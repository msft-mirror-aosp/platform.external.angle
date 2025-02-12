//
// Copyright 2024 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// VertexArrayWgpu.cpp:
//    Implements the class methods for VertexArrayWgpu.
//

#include "libANGLE/renderer/wgpu/VertexArrayWgpu.h"

#include "common/debug.h"
#include "libANGLE/renderer/wgpu/ContextWgpu.h"

namespace rx
{

namespace
{
bool AttributeNeedsStreaming(ContextWgpu *context,
                             const gl::VertexAttribute &attrib,
                             const gl::VertexBinding &binding)
{
    const size_t stride = ComputeVertexAttributeStride(attrib, binding);
    if (stride % 4 != 0)
    {
        return true;
    }

    const size_t typeSize = gl::ComputeVertexAttributeTypeSize(attrib);
    if (stride % typeSize != 0)
    {
        return true;
    }

    const webgpu::Format &vertexFormat = context->getFormat(attrib.format->glInternalFormat);
    if (vertexFormat.vertexLoadRequiresConversion())
    {
        return true;
    }

    gl::Buffer *bufferGl = binding.getBuffer().get();
    if (!bufferGl || bufferGl->getSize() == 0)
    {
        return true;
    }

    return false;
}

template <typename SourceType, typename DestType>
void CopyIndexData(const uint8_t *sourceData, size_t count, uint8_t *destData)
{
    if constexpr (std::is_same<SourceType, DestType>::value)
    {
        memcpy(destData, sourceData, sizeof(SourceType) * count);
    }
    else
    {
        for (size_t i = 0; i < count; i++)
        {
            DestType *dst         = reinterpret_cast<DestType *>(destData) + i;
            const SourceType *src = reinterpret_cast<const SourceType *>(sourceData) + i;
            *dst                  = static_cast<DestType>(*src);
        }
    }
}
using CopyIndexFunction = void (*)(const uint8_t *sourceData, size_t count, uint8_t *destData);

CopyIndexFunction GetCopyIndexFunction(gl::DrawElementsType sourceType,
                                       gl::DrawElementsType destType)
{
    static_assert(static_cast<size_t>(gl::DrawElementsType::UnsignedByte) == 0);
    static_assert(static_cast<size_t>(gl::DrawElementsType::UnsignedShort) == 1);
    static_assert(static_cast<size_t>(gl::DrawElementsType::UnsignedInt) == 2);
    ASSERT(static_cast<size_t>(sourceType) <= 2);
    ASSERT(static_cast<size_t>(destType) <= 2);
    ASSERT(static_cast<size_t>(destType) >=
           static_cast<size_t>(sourceType));  // Can't copy to a smaller type

    constexpr CopyIndexFunction copyFunctions[3][3] = {
        {
            CopyIndexData<GLubyte, GLubyte>,
            CopyIndexData<GLubyte, GLushort>,
            CopyIndexData<GLubyte, GLuint>,
        },
        {
            nullptr,
            CopyIndexData<GLushort, GLushort>,
            CopyIndexData<GLushort, GLuint>,
        },
        {
            nullptr,
            nullptr,
            CopyIndexData<GLuint, GLuint>,
        },
    };

    CopyIndexFunction copyFunction =
        copyFunctions[static_cast<size_t>(sourceType)][static_cast<size_t>(destType)];
    ASSERT(copyFunction != nullptr);
    return copyFunction;
}

}  // namespace

VertexArrayWgpu::VertexArrayWgpu(const gl::VertexArrayState &data) : VertexArrayImpl(data)
{
    // Pre-initialize mCurrentIndexBuffer to a streaming buffer because no index buffer dirty bit is
    // triggered if our first draw call has no buffer bound.
    mCurrentIndexBuffer = &mStreamingIndexBuffer;
}

angle::Result VertexArrayWgpu::syncState(const gl::Context *context,
                                         const gl::VertexArray::DirtyBits &dirtyBits,
                                         gl::VertexArray::DirtyAttribBitsArray *attribBits,
                                         gl::VertexArray::DirtyBindingBitsArray *bindingBits)
{
    ASSERT(dirtyBits.any());

    ContextWgpu *contextWgpu = GetImplAs<ContextWgpu>(context);

    const std::vector<gl::VertexAttribute> &attribs = mState.getVertexAttributes();
    const std::vector<gl::VertexBinding> &bindings  = mState.getVertexBindings();

    gl::AttributesMask syncedAttributes;

    for (auto iter = dirtyBits.begin(), endIter = dirtyBits.end(); iter != endIter; ++iter)
    {
        size_t dirtyBit = *iter;
        switch (dirtyBit)
        {
            case gl::VertexArray::DIRTY_BIT_LOST_OBSERVATION:
                break;

            case gl::VertexArray::DIRTY_BIT_ELEMENT_ARRAY_BUFFER:
            case gl::VertexArray::DIRTY_BIT_ELEMENT_ARRAY_BUFFER_DATA:
                ANGLE_TRY(syncDirtyElementArrayBuffer(contextWgpu));
                contextWgpu->invalidateIndexBuffer();
                break;

#define ANGLE_VERTEX_DIRTY_ATTRIB_FUNC(INDEX)                                     \
    case gl::VertexArray::DIRTY_BIT_ATTRIB_0 + INDEX:                             \
        ANGLE_TRY(syncDirtyAttrib(contextWgpu, attribs[INDEX],                    \
                                  bindings[attribs[INDEX].bindingIndex], INDEX)); \
        (*attribBits)[INDEX].reset();                                             \
        syncedAttributes.set(INDEX);                                              \
        break;

                ANGLE_VERTEX_INDEX_CASES(ANGLE_VERTEX_DIRTY_ATTRIB_FUNC)

#define ANGLE_VERTEX_DIRTY_BINDING_FUNC(INDEX)                                    \
    case gl::VertexArray::DIRTY_BIT_BINDING_0 + INDEX:                            \
        ANGLE_TRY(syncDirtyAttrib(contextWgpu, attribs[INDEX],                    \
                                  bindings[attribs[INDEX].bindingIndex], INDEX)); \
        (*bindingBits)[INDEX].reset();                                            \
        syncedAttributes.set(INDEX);                                              \
        break;

                ANGLE_VERTEX_INDEX_CASES(ANGLE_VERTEX_DIRTY_BINDING_FUNC)

#define ANGLE_VERTEX_DIRTY_BUFFER_DATA_FUNC(INDEX)                                \
    case gl::VertexArray::DIRTY_BIT_BUFFER_DATA_0 + INDEX:                        \
        ANGLE_TRY(syncDirtyAttrib(contextWgpu, attribs[INDEX],                    \
                                  bindings[attribs[INDEX].bindingIndex], INDEX)); \
        syncedAttributes.set(INDEX);                                              \
        break;

                ANGLE_VERTEX_INDEX_CASES(ANGLE_VERTEX_DIRTY_BUFFER_DATA_FUNC)
            default:
                break;
        }
    }

    for (size_t syncedAttribIndex : syncedAttributes)
    {
        contextWgpu->setVertexAttribute(syncedAttribIndex, mCurrentAttribs[syncedAttribIndex]);
        contextWgpu->invalidateVertexBuffer(syncedAttribIndex);
    }
    return angle::Result::Continue;
}

angle::Result VertexArrayWgpu::syncClientArrays(
    const gl::Context *context,
    const gl::AttributesMask &activeAttributesMask,
    gl::PrimitiveMode mode,
    GLint first,
    GLsizei count,
    GLsizei instanceCount,
    gl::DrawElementsType sourceDrawElementsTypeOrInvalid,
    const void *indices,
    GLint baseVertex,
    bool primitiveRestartEnabled,
    const void **adjustedIndicesPtr,
    uint32_t *indexCountOut)
{
    *adjustedIndicesPtr = indices;

    gl::AttributesMask clientAttributesToSync =
        (mState.getClientMemoryAttribsMask() | mForcedStreamingAttributes) &
        mState.getEnabledAttributesMask() & activeAttributesMask;

    gl::DrawElementsType destDrawElementsTypeOrInvalid = sourceDrawElementsTypeOrInvalid;

    IndexDataNeedsStreaming indexDataNeedsStreaming = IndexDataNeedsStreaming::No;
    if (sourceDrawElementsTypeOrInvalid == gl::DrawElementsType::UnsignedByte)
    {
        // Promote 8-bit indices to 16-bit indices
        indexDataNeedsStreaming       = IndexDataNeedsStreaming::Yes;
        destDrawElementsTypeOrInvalid = gl::DrawElementsType::UnsignedShort;
    }
    else if (mode == gl::PrimitiveMode::LineLoop)
    {
        // Index data will always need streaming for line loop mode regardless of what type of draw
        // call it is.
        indexDataNeedsStreaming = IndexDataNeedsStreaming::Yes;
    }
    else if (sourceDrawElementsTypeOrInvalid != gl::DrawElementsType::InvalidEnum &&
             !mState.getElementArrayBuffer())
    {
        // Index data needs to be uploaded to the GPU
        indexDataNeedsStreaming = IndexDataNeedsStreaming::Yes;
    }

    if (!clientAttributesToSync.any() && indexDataNeedsStreaming == IndexDataNeedsStreaming::No)
    {
        return angle::Result::Continue;
    }

    GLsizei adjustedCount = count;
    if (mode == gl::PrimitiveMode::LineLoop)
    {
        adjustedCount++;
    }

    if (indexCountOut)
    {
        *indexCountOut = adjustedCount;
    }

    ContextWgpu *contextWgpu = webgpu::GetImpl(context);
    wgpu::Device device      = webgpu::GetDevice(context);

    // If any attributes need to be streamed, we need to know the index range.
    std::optional<gl::IndexRange> indexRange;
    if (clientAttributesToSync.any())
    {
        GLint startVertex  = 0;
        size_t vertexCount = 0;
        ANGLE_TRY(GetVertexRangeInfo(context, first, count, sourceDrawElementsTypeOrInvalid,
                                     indices, baseVertex, &startVertex, &vertexCount));
        indexRange = gl::IndexRange(startVertex, startVertex + vertexCount - 1, 0);
    }

    // Pre-compute the total size of all streamed vertex and index data so a single staging buffer
    // can be used
    size_t stagingBufferSize = 0;

    std::optional<size_t> destIndexDataSize;
    std::optional<size_t> destIndexUnitSize;
    gl::Buffer *elementArrayBuffer = mState.getElementArrayBuffer();
    if (indexDataNeedsStreaming == IndexDataNeedsStreaming::Yes)
    {
        destIndexUnitSize =
            static_cast<size_t>(gl::GetDrawElementsTypeSize(destDrawElementsTypeOrInvalid));
        destIndexDataSize = destIndexUnitSize.value() * adjustedCount;

        // Allocating staging buffer space for indices is only needed when there is no source index
        // buffer or index data conversion is needed
        if (!elementArrayBuffer || sourceDrawElementsTypeOrInvalid != destDrawElementsTypeOrInvalid)
        {
            stagingBufferSize +=
                rx::roundUpPow2(destIndexDataSize.value(), webgpu::kBufferCopyToBufferAlignment);
        }
    }

    const std::vector<gl::VertexAttribute> &attribs = mState.getVertexAttributes();
    const std::vector<gl::VertexBinding> &bindings  = mState.getVertexBindings();

    if (clientAttributesToSync.any())
    {
        for (size_t attribIndex : clientAttributesToSync)
        {
            const gl::VertexAttribute &attrib = attribs[attribIndex];
            const gl::VertexBinding &binding  = bindings[attrib.bindingIndex];

            size_t elementCount = gl::ComputeVertexBindingElementCount(
                binding.getDivisor(), indexRange->vertexCount(), instanceCount);

            const webgpu::Format &vertexFormat =
                contextWgpu->getFormat(attrib.format->glInternalFormat);
            size_t destTypeSize = vertexFormat.getActualBufferFormat().pixelBytes;
            ASSERT(destTypeSize > 0);

            size_t attribSize = destTypeSize * elementCount;
            stagingBufferSize += rx::roundUpPow2(attribSize, webgpu::kBufferCopyToBufferAlignment);
        }
    }

    webgpu::BufferHelper stagingBuffer;
    uint8_t *stagingData              = nullptr;
    size_t currentStagingDataPosition = 0;
    if (stagingBufferSize > 0)
    {
        ASSERT(stagingBufferSize > 0);
        ASSERT(stagingBufferSize % webgpu::kBufferSizeAlignment == 0);
        ANGLE_TRY(stagingBuffer.initBuffer(device, stagingBufferSize,
                                           wgpu::BufferUsage::CopySrc | wgpu::BufferUsage::MapWrite,
                                           webgpu::MapAtCreation::Yes));
        stagingData = stagingBuffer.getMapWritePointer(0, stagingBufferSize);
    }

    struct BufferCopy
    {
        uint64_t sourceOffset;
        webgpu::BufferHelper *src;
        webgpu::BufferHelper *dest;
        uint64_t destOffset;
        uint64_t size;
    };
    std::vector<BufferCopy> stagingUploads;

    if (indexDataNeedsStreaming == IndexDataNeedsStreaming::Yes)
    {
        // Indices are streamed to the start of the buffer. Tell the draw call command to use 0 for
        // firstIndex.
        *adjustedIndicesPtr = 0;
        ASSERT(destIndexDataSize.has_value());
        ASSERT(destIndexUnitSize.has_value());

        size_t destIndexBufferSize =
            rx::roundUpPow2(destIndexDataSize.value(), webgpu::kBufferCopyToBufferAlignment);
        ANGLE_TRY(ensureBufferCreated(context, mStreamingIndexBuffer, destIndexBufferSize, 0,
                                      wgpu::BufferUsage::CopyDst | wgpu::BufferUsage::Index,
                                      BufferType::IndexBuffer));
        if (sourceDrawElementsTypeOrInvalid == destDrawElementsTypeOrInvalid && elementArrayBuffer)
        {
            // Use the element array buffer as the source for the new streaming index buffer. This
            // condition is only hit when an indexed draw call has an element array buffer and is
            // trying to draw line loops.

            // When using an element array buffer, 'indices' is an offset to the first element.
            size_t sourceOffset                = reinterpret_cast<size_t>(indices);
            BufferWgpu *elementArrayBufferWgpu = GetImplAs<BufferWgpu>(elementArrayBuffer);
            webgpu::BufferHelper *sourceBuffer = &elementArrayBufferWgpu->getBuffer();

            size_t copySize = rx::roundUpPow2(destIndexUnitSize.value() * count,
                                              webgpu::kBufferCopyToBufferAlignment);
            stagingUploads.push_back(
                {sourceOffset, sourceBuffer, &mStreamingIndexBuffer, 0, copySize});

            if (mode == gl::PrimitiveMode::LineLoop)
            {
                // Emulate line loops with an additional copy of the first index at the end of the
                // buffer
                size_t lastOffset = copySize;
                stagingUploads.push_back({sourceOffset, sourceBuffer, &mStreamingIndexBuffer,
                                          lastOffset,
                                          rx::roundUpPow2(destIndexUnitSize.value(),
                                                          webgpu::kBufferCopyToBufferAlignment)});
            }
        }
        else
        {
            const uint8_t *srcIndexData = static_cast<const uint8_t *>(indices);

            webgpu::BufferReadback readbackBuffer;
            if (mState.getElementArrayBuffer())
            {
                webgpu::BufferHelper &srcBuffer =
                    webgpu::GetImpl(mState.getElementArrayBuffer())->getBuffer();

                const GLuint srcIndexTypeSize =
                    gl::GetDrawElementsTypeSize(sourceDrawElementsTypeOrInvalid);
                const size_t srcIndexOffset = reinterpret_cast<uintptr_t>(indices);

                ANGLE_TRY(srcBuffer.readDataImmediate(
                    contextWgpu, srcIndexOffset, count * srcIndexTypeSize,
                    webgpu::RenderPassClosureReason::IndexRangeReadback, &readbackBuffer));
                srcIndexData = readbackBuffer.data;
            }

            CopyIndexFunction indexCopyFunction = GetCopyIndexFunction(
                sourceDrawElementsTypeOrInvalid, destDrawElementsTypeOrInvalid);
            ASSERT(stagingData != nullptr);
            indexCopyFunction(srcIndexData, count, stagingData + currentStagingDataPosition);

            if (mode == gl::PrimitiveMode::LineLoop)
            {
                indexCopyFunction(
                    srcIndexData, count,
                    stagingData + currentStagingDataPosition + (destIndexUnitSize.value() * count));
            }

            size_t copySize = destIndexBufferSize;
            stagingUploads.push_back(
                {currentStagingDataPosition, &stagingBuffer, &mStreamingIndexBuffer, 0, copySize});
            currentStagingDataPosition += copySize;
        }
        // TODO(anglebug.com/383356846): add support for primitive restarts and line loop draw
        // arrays.
    }

    for (size_t attribIndex : clientAttributesToSync)
    {
        const gl::VertexAttribute &attrib = attribs[attribIndex];
        const gl::VertexBinding &binding  = bindings[attrib.bindingIndex];

        size_t streamedVertexCount = gl::ComputeVertexBindingElementCount(
            binding.getDivisor(), indexRange->vertexCount(), instanceCount);

        const size_t sourceStride = ComputeVertexAttributeStride(attrib, binding);
        const size_t sourceTypeSize = gl::ComputeVertexAttributeTypeSize(attrib);

        // Vertices do not apply the 'start' offset when the divisor is non-zero even when doing
        // a non-instanced draw call
        const size_t firstIndex = (binding.getDivisor() == 0) ? indexRange->start : 0;

        // Attributes using client memory ignore the VERTEX_ATTRIB_BINDING state.
        // https://www.opengl.org/registry/specs/ARB/vertex_attrib_binding.txt
        const uint8_t *inputPointer = static_cast<const uint8_t *>(attrib.pointer);

        webgpu::BufferReadback readbackBuffer;
        if (binding.getBuffer().get())
        {
            webgpu::BufferHelper &srcBuffer =
                webgpu::GetImpl(binding.getBuffer().get())->getBuffer();

            size_t sourceVertexDataSize =
                sourceStride * (firstIndex + streamedVertexCount - 1) + sourceTypeSize;

            ANGLE_TRY(srcBuffer.readDataImmediate(
                contextWgpu, 0, reinterpret_cast<uintptr_t>(attrib.pointer) + sourceVertexDataSize,
                webgpu::RenderPassClosureReason::IndexRangeReadback, &readbackBuffer));
            inputPointer = readbackBuffer.data + reinterpret_cast<uintptr_t>(attrib.pointer);
        }

        const webgpu::Format &vertexFormat =
            contextWgpu->getFormat(attrib.format->glInternalFormat);
        size_t destTypeSize = vertexFormat.getActualBufferFormat().pixelBytes;

        VertexCopyFunction copyFunction = vertexFormat.getVertexLoadFunction();
        ASSERT(copyFunction != nullptr);
        ASSERT(stagingData != nullptr);
        copyFunction(inputPointer + (sourceStride * firstIndex), sourceStride, streamedVertexCount,
                     stagingData + currentStagingDataPosition);

        size_t copySize = rx::roundUpPow2(streamedVertexCount * destTypeSize,
                                          webgpu::kBufferCopyToBufferAlignment);
        // Pad the streaming buffer with empty data at the beginning to put the vertex data at the
        // same index location. The stride is tightly packed.
        size_t destCopyOffset = firstIndex * destTypeSize;

        ANGLE_TRY(ensureBufferCreated(
            context, mStreamingArrayBuffers[attribIndex], destCopyOffset + copySize, attribIndex,
            wgpu::BufferUsage::CopyDst | wgpu::BufferUsage::Vertex, BufferType::ArrayBuffer));

        stagingUploads.push_back({currentStagingDataPosition, &stagingBuffer,
                                  &mStreamingArrayBuffers[attribIndex], destCopyOffset, copySize});

        currentStagingDataPosition += copySize;
    }

    if (stagingBuffer.valid())
    {
        ANGLE_TRY(stagingBuffer.unmap());
    }
    ANGLE_TRY(contextWgpu->flush(webgpu::RenderPassClosureReason::VertexArrayStreaming));

    contextWgpu->ensureCommandEncoderCreated();
    wgpu::CommandEncoder &commandEncoder = contextWgpu->getCurrentCommandEncoder();

    for (const BufferCopy &copy : stagingUploads)
    {
        commandEncoder.CopyBufferToBuffer(copy.src->getBuffer(), copy.sourceOffset,
                                          copy.dest->getBuffer(), copy.destOffset, copy.size);
    }

    return angle::Result::Continue;
}

angle::Result VertexArrayWgpu::syncDirtyAttrib(ContextWgpu *contextWgpu,
                                               const gl::VertexAttribute &attrib,
                                               const gl::VertexBinding &binding,
                                               size_t attribIndex)
{
    mForcedStreamingAttributes[attribIndex] = AttributeNeedsStreaming(contextWgpu, attrib, binding);

    if (attrib.enabled)
    {
        SetBitField(mCurrentAttribs[attribIndex].enabled, true);
        const webgpu::Format &webgpuFormat =
            contextWgpu->getFormat(attrib.format->glInternalFormat);
        SetBitField(mCurrentAttribs[attribIndex].format, webgpuFormat.getActualWgpuVertexFormat());
        SetBitField(mCurrentAttribs[attribIndex].shaderLocation, attribIndex);

        if (!mForcedStreamingAttributes[attribIndex])
        {
            // Data is sourced directly from the array buffer.
            SetBitField(mCurrentAttribs[attribIndex].offset, 0);
            SetBitField(mCurrentAttribs[attribIndex].stride, binding.getStride());

            gl::Buffer *bufferGl = binding.getBuffer().get();
            ASSERT(bufferGl);
            BufferWgpu *bufferWgpu            = webgpu::GetImpl(bufferGl);
            mCurrentArrayBuffers[attribIndex].buffer = &(bufferWgpu->getBuffer());
            mCurrentArrayBuffers[attribIndex].offset = reinterpret_cast<uintptr_t>(attrib.pointer);
        }
        else
        {
            SetBitField(mCurrentAttribs[attribIndex].offset, 0);
            SetBitField(mCurrentAttribs[attribIndex].stride,
                        webgpuFormat.getActualBufferFormat().pixelBytes);
            mCurrentArrayBuffers[attribIndex].buffer = &mStreamingArrayBuffers[attribIndex];
            mCurrentArrayBuffers[attribIndex].offset = 0;
        }
    }
    else
    {
        memset(&mCurrentAttribs[attribIndex], 0, sizeof(webgpu::PackedVertexAttribute));
        mCurrentArrayBuffers[attribIndex].buffer = nullptr;
        mCurrentArrayBuffers[attribIndex].offset = 0;
    }

    return angle::Result::Continue;
}

angle::Result VertexArrayWgpu::syncDirtyElementArrayBuffer(ContextWgpu *contextWgpu)
{
    gl::Buffer *bufferGl = mState.getElementArrayBuffer();
    if (bufferGl)
    {
        BufferWgpu *buffer  = webgpu::GetImpl(bufferGl);
        mCurrentIndexBuffer = &buffer->getBuffer();
    }
    else
    {
        mCurrentIndexBuffer = &mStreamingIndexBuffer;
    }

    return angle::Result::Continue;
}

angle::Result VertexArrayWgpu::ensureBufferCreated(const gl::Context *context,
                                                   webgpu::BufferHelper &buffer,
                                                   size_t size,
                                                   size_t attribIndex,
                                                   wgpu::BufferUsage usage,
                                                   BufferType bufferType)
{
    ContextWgpu *contextWgpu = webgpu::GetImpl(context);
    if (!buffer.valid() || buffer.requestedSize() < size || buffer.getBuffer().GetUsage() != usage)
    {
        wgpu::Device device = webgpu::GetDevice(context);
        ANGLE_TRY(buffer.initBuffer(device, size, usage, webgpu::MapAtCreation::No));

        if (bufferType == BufferType::IndexBuffer)
        {
            contextWgpu->invalidateIndexBuffer();
        }
        else
        {
            ASSERT(bufferType == BufferType::ArrayBuffer);
            contextWgpu->invalidateVertexBuffer(attribIndex);
        }
    }

    if (bufferType == BufferType::IndexBuffer)
    {
        mCurrentIndexBuffer = &buffer;
    }
    return angle::Result::Continue;
}

}  // namespace rx
