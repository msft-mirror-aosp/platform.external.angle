//
// Copyright 2024 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#include "libANGLE/renderer/wgpu/wgpu_utils.h"

#include "libANGLE/renderer/renderer_utils.h"
#include "libANGLE/renderer/wgpu/ContextWgpu.h"
#include "libANGLE/renderer/wgpu/DisplayWgpu.h"

namespace rx
{

namespace webgpu
{
DisplayWgpu *GetDisplay(const gl::Context *context)
{
    ContextWgpu *contextWgpu = GetImpl(context);
    return contextWgpu->getDisplay();
}

wgpu::Device GetDevice(const gl::Context *context)
{
    DisplayWgpu *display = GetDisplay(context);
    return display->getDevice();
}

wgpu::Instance GetInstance(const gl::Context *context)
{
    DisplayWgpu *display = GetDisplay(context);
    return display->getInstance();
}

wgpu::RenderPassColorAttachment CreateNewClearColorAttachment(wgpu::Color clearValue,
                                                              uint32_t depthSlice,
                                                              wgpu::TextureView textureView)
{
    wgpu::RenderPassColorAttachment colorAttachment;
    colorAttachment.view       = textureView;
    colorAttachment.depthSlice = depthSlice;
    colorAttachment.loadOp     = wgpu::LoadOp::Clear;
    colorAttachment.storeOp    = wgpu::StoreOp::Store;
    colorAttachment.clearValue = clearValue;

    return colorAttachment;
}

bool IsWgpuError(wgpu::WaitStatus waitStatus)
{
    return waitStatus != wgpu::WaitStatus::Success;
}

bool IsWgpuError(WGPUBufferMapAsyncStatus mapBufferStatus)
{
    return mapBufferStatus != WGPUBufferMapAsyncStatus_Success;
}

ClearValuesArray::ClearValuesArray() : mValues{}, mEnabled{} {}
ClearValuesArray::~ClearValuesArray() = default;

ClearValuesArray::ClearValuesArray(const ClearValuesArray &other)          = default;
ClearValuesArray &ClearValuesArray::operator=(const ClearValuesArray &rhs) = default;

void ClearValuesArray::store(uint32_t index, ClearValues clearValues)
{
    mValues[index] = clearValues;
    mEnabled.set(index);
}

gl::DrawBufferMask ClearValuesArray::getColorMask() const
{
    return gl::DrawBufferMask(mEnabled.bits() & kUnpackedColorBuffersMask);
}

void EnsureCapsInitialized(const wgpu::Device &device, gl::Caps *nativeCaps)
{
    wgpu::SupportedLimits limitsWgpu = {};
    device.GetLimits(&limitsWgpu);

    nativeCaps->maxElementIndex       = std::numeric_limits<GLuint>::max() - 1;
    nativeCaps->max3DTextureSize      = rx::LimitToInt(limitsWgpu.limits.maxTextureDimension3D);
    nativeCaps->max2DTextureSize      = rx::LimitToInt(limitsWgpu.limits.maxTextureDimension2D);
    nativeCaps->maxArrayTextureLayers = rx::LimitToInt(limitsWgpu.limits.maxTextureArrayLayers);
    nativeCaps->maxCubeMapTextureSize = rx::LimitToInt(limitsWgpu.limits.maxTextureDimension2D);
    nativeCaps->maxRenderbufferSize   = rx::LimitToInt(limitsWgpu.limits.maxTextureDimension2D);

    nativeCaps->maxDrawBuffers       = rx::LimitToInt(limitsWgpu.limits.maxColorAttachments);
    nativeCaps->maxFramebufferWidth  = rx::LimitToInt(limitsWgpu.limits.maxTextureDimension2D);
    nativeCaps->maxFramebufferHeight = rx::LimitToInt(limitsWgpu.limits.maxTextureDimension2D);
    nativeCaps->maxColorAttachments  = rx::LimitToInt(limitsWgpu.limits.maxColorAttachments);

    nativeCaps->maxVertexAttribStride =
        rx::LimitToInt(limitsWgpu.limits.maxVertexBufferArrayStride);

    nativeCaps->maxVertexAttributes = rx::LimitToInt(limitsWgpu.limits.maxVertexAttributes);

    nativeCaps->maxTextureBufferSize = rx::LimitToInt(limitsWgpu.limits.maxBufferSize);
}

bool IsStripPrimitiveTopology(wgpu::PrimitiveTopology topology)
{
    switch (topology)
    {
        case wgpu::PrimitiveTopology::LineStrip:
        case wgpu::PrimitiveTopology::TriangleStrip:
            return true;

        default:
            return false;
    }
}

}  // namespace webgpu

namespace wgpu_gl
{
gl::LevelIndex getLevelIndex(webgpu::LevelIndex levelWgpu, gl::LevelIndex baseLevel)
{
    return gl::LevelIndex(levelWgpu.get() + baseLevel.get());
}

gl::Extents getExtents(wgpu::Extent3D wgpuExtent)
{
    gl::Extents glExtent;
    glExtent.width  = wgpuExtent.width;
    glExtent.height = wgpuExtent.height;
    glExtent.depth  = wgpuExtent.depthOrArrayLayers;
    return glExtent;
}
}  // namespace wgpu_gl

namespace gl_wgpu
{
webgpu::LevelIndex getLevelIndex(gl::LevelIndex levelGl, gl::LevelIndex baseLevel)
{
    ASSERT(baseLevel <= levelGl);
    return webgpu::LevelIndex(levelGl.get() - baseLevel.get());
}

wgpu::Extent3D getExtent3D(const gl::Extents &glExtent)
{
    wgpu::Extent3D wgpuExtent;
    wgpuExtent.width              = glExtent.width;
    wgpuExtent.height             = glExtent.height;
    wgpuExtent.depthOrArrayLayers = glExtent.depth;
    return wgpuExtent;
}

wgpu::PrimitiveTopology GetPrimitiveTopology(gl::PrimitiveMode mode)
{
    switch (mode)
    {
        case gl::PrimitiveMode::Points:
            return wgpu::PrimitiveTopology::PointList;
        case gl::PrimitiveMode::Lines:
            return wgpu::PrimitiveTopology::LineList;
        case gl::PrimitiveMode::LineLoop:
            UNIMPLEMENTED();
            return wgpu::PrimitiveTopology::LineList;  // Emulated
        case gl::PrimitiveMode::LineStrip:
            return wgpu::PrimitiveTopology::LineStrip;
        case gl::PrimitiveMode::Triangles:
            return wgpu::PrimitiveTopology::TriangleList;
        case gl::PrimitiveMode::TriangleStrip:
            return wgpu::PrimitiveTopology::TriangleStrip;
        case gl::PrimitiveMode::TriangleFan:
            UNIMPLEMENTED();
            return wgpu::PrimitiveTopology::TriangleList;  // Emulated
        default:
            UNREACHABLE();
            return wgpu::PrimitiveTopology::Undefined;
    }
}

wgpu::IndexFormat GetIndexFormat(gl::DrawElementsType drawElementsType)
{
    switch (drawElementsType)
    {
        case gl::DrawElementsType::UnsignedByte:
            UNIMPLEMENTED();
            return wgpu::IndexFormat::Uint16;  // Emulated
        case gl::DrawElementsType::UnsignedShort:
            return wgpu::IndexFormat::Uint16;
        case gl::DrawElementsType::UnsignedInt:
            return wgpu::IndexFormat::Uint32;

        default:
            UNREACHABLE();
            return wgpu::IndexFormat::Undefined;
    }
}

wgpu::FrontFace GetFrontFace(GLenum frontFace)
{
    switch (frontFace)
    {
        case GL_CW:
            return wgpu::FrontFace::CW;
        case GL_CCW:
            return wgpu::FrontFace::CCW;

        default:
            UNREACHABLE();
            return wgpu::FrontFace::Undefined;
    }
}

wgpu::CullMode GetCullMode(gl::CullFaceMode mode, bool cullFaceEnabled)
{
    if (!cullFaceEnabled)
    {
        return wgpu::CullMode::None;
    }

    switch (mode)
    {
        case gl::CullFaceMode::Front:
            return wgpu::CullMode::Front;
        case gl::CullFaceMode::Back:
            return wgpu::CullMode::Back;
        case gl::CullFaceMode::FrontAndBack:
            UNIMPLEMENTED();
            return wgpu::CullMode::None;  // Emulated
        default:
            UNREACHABLE();
            return wgpu::CullMode::None;
    }
}

wgpu::TextureDimension getWgpuTextureDimension(gl::TextureType glTextureType)
{
    wgpu::TextureDimension dimension = {};
    switch (glTextureType)
    {
        case gl::TextureType::_2D:
        case gl::TextureType::_2DMultisample:
        case gl::TextureType::Rectangle:
        case gl::TextureType::External:
        case gl::TextureType::Buffer:
            dimension = wgpu::TextureDimension::e2D;
            break;
        case gl::TextureType::_2DArray:
        case gl::TextureType::_2DMultisampleArray:
        case gl::TextureType::_3D:
        case gl::TextureType::CubeMap:
        case gl::TextureType::CubeMapArray:
        case gl::TextureType::VideoImage:
            dimension = wgpu::TextureDimension::e3D;
            break;
        default:
            break;
    }
    return dimension;
}
}  // namespace gl_wgpu
}  // namespace rx
