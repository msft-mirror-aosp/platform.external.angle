//
// Copyright 2015 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#include "test_utils/ANGLETest.h"
#include "test_utils/gl_raii.h"

#include "util/random_utils.h"

#include <stdint.h>

using namespace angle;

class BufferDataTest : public ANGLETest
{
  protected:
    BufferDataTest()
    {
        setWindowWidth(16);
        setWindowHeight(16);
        setConfigRedBits(8);
        setConfigGreenBits(8);
        setConfigBlueBits(8);
        setConfigAlphaBits(8);
        setConfigDepthBits(24);

        mBuffer         = 0;
        mProgram        = 0;
        mAttribLocation = -1;
    }

    void testSetUp() override
    {
        constexpr char kVS[] = R"(attribute vec4 position;
attribute float in_attrib;
varying float v_attrib;
void main()
{
    v_attrib = in_attrib;
    gl_Position = position;
})";

        constexpr char kFS[] = R"(precision mediump float;
varying float v_attrib;
void main()
{
    gl_FragColor = vec4(v_attrib, 0, 0, 1);
})";

        glGenBuffers(1, &mBuffer);
        ASSERT_NE(mBuffer, 0U);

        mProgram = CompileProgram(kVS, kFS);
        ASSERT_NE(mProgram, 0U);

        mAttribLocation = glGetAttribLocation(mProgram, "in_attrib");
        ASSERT_NE(mAttribLocation, -1);

        glClearColor(0, 0, 0, 0);
        glClearDepthf(0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glDisable(GL_DEPTH_TEST);

        ASSERT_GL_NO_ERROR();
    }

    void testTearDown() override
    {
        glDeleteBuffers(1, &mBuffer);
        glDeleteProgram(mProgram);
    }

    GLuint mBuffer;
    GLuint mProgram;
    GLint mAttribLocation;
};

// If glBufferData was not called yet the capturing must not try to
// read the data. http://anglebug.com/6093
TEST_P(BufferDataTest, Uninitialized)
{
    // Trigger frame capture to try capturing the
    // generated but uninitialized buffer
    glBindBuffer(GL_ARRAY_BUFFER, mBuffer);
    swapBuffers();
}

TEST_P(BufferDataTest, ZeroNonNULLData)
{
    glBindBuffer(GL_ARRAY_BUFFER, mBuffer);
    EXPECT_GL_NO_ERROR();

    char *zeroData = new char[0];
    glBufferData(GL_ARRAY_BUFFER, 0, zeroData, GL_STATIC_DRAW);
    EXPECT_GL_NO_ERROR();

    glBufferSubData(GL_ARRAY_BUFFER, 0, 0, zeroData);
    EXPECT_GL_NO_ERROR();

    delete[] zeroData;
}

TEST_P(BufferDataTest, NULLResolvedData)
{
    glBindBuffer(GL_ARRAY_BUFFER, mBuffer);
    glBufferData(GL_ARRAY_BUFFER, 128, nullptr, GL_DYNAMIC_DRAW);

    glUseProgram(mProgram);
    glVertexAttribPointer(mAttribLocation, 1, GL_FLOAT, GL_FALSE, 4, nullptr);
    glEnableVertexAttribArray(mAttribLocation);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    drawQuad(mProgram, "position", 0.5f);
}

// Internally in D3D, we promote dynamic data to static after many draw loops. This code tests
// path.
TEST_P(BufferDataTest, RepeatedDrawWithDynamic)
{
    std::vector<GLfloat> data;
    for (int i = 0; i < 16; ++i)
    {
        data.push_back(static_cast<GLfloat>(i));
    }

    glUseProgram(mProgram);
    glBindBuffer(GL_ARRAY_BUFFER, mBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), data.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(mAttribLocation, 1, GL_FLOAT, GL_FALSE, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(mAttribLocation);

    for (int drawCount = 0; drawCount < 40; ++drawCount)
    {
        drawQuad(mProgram, "position", 0.5f);
    }

    EXPECT_GL_NO_ERROR();
}

// Tests for a bug where vertex attribute translation was not being invalidated when switching to
// DYNAMIC
TEST_P(BufferDataTest, RepeatedDrawDynamicBug)
{
    // http://anglebug.com/2843: Seems to be an Intel driver bug.
    ANGLE_SKIP_TEST_IF(IsVulkan() && IsIntel() && IsWindows());

    glUseProgram(mProgram);

    GLint positionLocation = glGetAttribLocation(mProgram, "position");
    ASSERT_NE(-1, positionLocation);

    auto quadVertices = GetQuadVertices();
    for (angle::Vector3 &vertex : quadVertices)
    {
        vertex.x() *= 1.0f;
        vertex.y() *= 1.0f;
        vertex.z() = 0.0f;
    }

    // Set up quad vertices with DYNAMIC data
    GLBuffer positionBuffer;
    glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * quadVertices.size() * 3, quadVertices.data(),
                 GL_DYNAMIC_DRAW);
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(positionLocation);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    EXPECT_GL_NO_ERROR();

    // Set up color data so red is drawn
    std::vector<GLfloat> data(6, 1.0f);

    // Set data to DYNAMIC
    glBindBuffer(GL_ARRAY_BUFFER, mBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), data.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(mAttribLocation, 1, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(mAttribLocation);
    EXPECT_GL_NO_ERROR();

    // Draw enough times to promote data to DIRECT mode
    for (int i = 0; i < 20; i++)
    {
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    // Verify red was drawn
    EXPECT_PIXEL_COLOR_EQ(0, 0, GLColor::red);

    // Set up color value so black is drawn
    std::fill(data.begin(), data.end(), 0.0f);

    // Update the data, changing back to DYNAMIC mode.
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), data.data(), GL_DYNAMIC_DRAW);

    // This draw should produce a black quad
    glDrawArrays(GL_TRIANGLES, 0, 6);
    EXPECT_PIXEL_COLOR_EQ(0, 0, GLColor::black);
    EXPECT_GL_NO_ERROR();
}

class IndexedBufferCopyTest : public ANGLETest
{
  protected:
    IndexedBufferCopyTest()
    {
        setWindowWidth(16);
        setWindowHeight(16);
        setConfigRedBits(8);
        setConfigGreenBits(8);
        setConfigBlueBits(8);
        setConfigAlphaBits(8);
        setConfigDepthBits(24);
    }

    void testSetUp() override
    {
        constexpr char kVS[] = R"(attribute vec3 in_attrib;
varying vec3 v_attrib;
void main()
{
    v_attrib = in_attrib;
    gl_Position = vec4(0.0, 0.0, 0.5, 1.0);
    gl_PointSize = 100.0;
})";

        constexpr char kFS[] = R"(precision mediump float;
varying vec3 v_attrib;
void main()
{
    gl_FragColor = vec4(v_attrib, 1);
})";

        glGenBuffers(2, mBuffers);
        ASSERT_NE(mBuffers[0], 0U);
        ASSERT_NE(mBuffers[1], 0U);

        glGenBuffers(1, &mElementBuffer);
        ASSERT_NE(mElementBuffer, 0U);

        mProgram = CompileProgram(kVS, kFS);
        ASSERT_NE(mProgram, 0U);

        mAttribLocation = glGetAttribLocation(mProgram, "in_attrib");
        ASSERT_NE(mAttribLocation, -1);

        glClearColor(0, 0, 0, 0);
        glDisable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT);

        ASSERT_GL_NO_ERROR();
    }

    void testTearDown() override
    {
        glDeleteBuffers(2, mBuffers);
        glDeleteBuffers(1, &mElementBuffer);
        glDeleteProgram(mProgram);
    }

    GLuint mBuffers[2];
    GLuint mElementBuffer;
    GLuint mProgram;
    GLint mAttribLocation;
};

// The following test covers an ANGLE bug where our index ranges
// weren't updated from CopyBufferSubData calls
// https://code.google.com/p/angleproject/issues/detail?id=709
TEST_P(IndexedBufferCopyTest, IndexRangeBug)
{
    // http://anglebug.com/4092
    ANGLE_SKIP_TEST_IF(isSwiftshader());
    // TODO(geofflang): Figure out why this fails on AMD OpenGL (http://anglebug.com/1291)
    ANGLE_SKIP_TEST_IF(IsAMD() && IsOpenGL());

    unsigned char vertexData[] = {255, 0, 0, 0, 0, 0};
    unsigned int indexData[]   = {0, 1};

    glBindBuffer(GL_ARRAY_BUFFER, mBuffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(char) * 6, vertexData, GL_STATIC_DRAW);

    glUseProgram(mProgram);
    glVertexAttribPointer(mAttribLocation, 3, GL_UNSIGNED_BYTE, GL_TRUE, 3, nullptr);
    glEnableVertexAttribArray(mAttribLocation);

    ASSERT_GL_NO_ERROR();

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * 1, indexData, GL_STATIC_DRAW);

    glUseProgram(mProgram);

    ASSERT_GL_NO_ERROR();

    glDrawElements(GL_POINTS, 1, GL_UNSIGNED_INT, nullptr);

    EXPECT_GL_NO_ERROR();
    EXPECT_PIXEL_EQ(0, 0, 255, 0, 0, 255);

    glBindBuffer(GL_COPY_READ_BUFFER, mBuffers[1]);
    glBufferData(GL_COPY_READ_BUFFER, 4, &indexData[1], GL_STATIC_DRAW);

    glBindBuffer(GL_COPY_WRITE_BUFFER, mElementBuffer);

    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, sizeof(int));

    ASSERT_GL_NO_ERROR();

    glClear(GL_COLOR_BUFFER_BIT);
    EXPECT_PIXEL_EQ(0, 0, 0, 0, 0, 0);

    unsigned char newData[] = {0, 255, 0};
    glBufferSubData(GL_ARRAY_BUFFER, 3, 3, newData);

    glDrawElements(GL_POINTS, 1, GL_UNSIGNED_INT, nullptr);

    EXPECT_GL_NO_ERROR();
    EXPECT_PIXEL_COLOR_EQ(0, 0, GLColor::green);
}

class BufferDataTestES3 : public BufferDataTest
{};

// The following test covers an ANGLE bug where the buffer storage
// is not resized by Buffer11::getLatestBufferStorage when needed.
// https://code.google.com/p/angleproject/issues/detail?id=897
TEST_P(BufferDataTestES3, BufferResizing)
{
    glBindBuffer(GL_ARRAY_BUFFER, mBuffer);
    ASSERT_GL_NO_ERROR();

    // Allocate a buffer with one byte
    uint8_t singleByte[] = {0xaa};
    glBufferData(GL_ARRAY_BUFFER, 1, singleByte, GL_STATIC_DRAW);

    // Resize the buffer
    // To trigger the bug, the buffer need to be big enough because some hardware copy buffers
    // by chunks of pages instead of the minimum number of bytes needed.
    const size_t numBytes = 4096 * 4;
    glBufferData(GL_ARRAY_BUFFER, numBytes, nullptr, GL_STATIC_DRAW);

    // Copy the original data to the buffer
    uint8_t srcBytes[numBytes];
    for (size_t i = 0; i < numBytes; ++i)
    {
        srcBytes[i] = static_cast<uint8_t>(i);
    }

    void *dest = glMapBufferRange(GL_ARRAY_BUFFER, 0, numBytes,
                                  GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);

    ASSERT_GL_NO_ERROR();

    memcpy(dest, srcBytes, numBytes);
    glUnmapBuffer(GL_ARRAY_BUFFER);

    EXPECT_GL_NO_ERROR();

    // Create a new buffer and copy the data to it
    GLuint readBuffer;
    glGenBuffers(1, &readBuffer);
    glBindBuffer(GL_COPY_WRITE_BUFFER, readBuffer);
    uint8_t zeros[numBytes];
    for (size_t i = 0; i < numBytes; ++i)
    {
        zeros[i] = 0;
    }
    glBufferData(GL_COPY_WRITE_BUFFER, numBytes, zeros, GL_STATIC_DRAW);
    glCopyBufferSubData(GL_ARRAY_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, numBytes);

    ASSERT_GL_NO_ERROR();

    // Read back the data and compare it to the original
    uint8_t *data = reinterpret_cast<uint8_t *>(
        glMapBufferRange(GL_COPY_WRITE_BUFFER, 0, numBytes, GL_MAP_READ_BIT));

    ASSERT_GL_NO_ERROR();

    for (size_t i = 0; i < numBytes; ++i)
    {
        EXPECT_EQ(srcBytes[i], data[i]);
    }
    glUnmapBuffer(GL_COPY_WRITE_BUFFER);

    glDeleteBuffers(1, &readBuffer);

    EXPECT_GL_NO_ERROR();
}

// Test to verify mapping a buffer after copying to it contains flushed/updated data
TEST_P(BufferDataTestES3, CopyBufferSubDataMapReadTest)
{
    const char simpleVertex[]   = R"(attribute vec2 position;
attribute vec4 color;
varying vec4 vColor;
void main()
{
    gl_Position = vec4(position, 0, 1);
    vColor = color;
}
)";
    const char simpleFragment[] = R"(precision mediump float;
varying vec4 vColor;
void main()
{
    gl_FragColor = vColor;
}
)";

    const uint32_t numComponents = 3;
    const uint32_t width         = 4;
    const uint32_t height        = 4;
    const size_t numElements     = width * height * numComponents;
    std::vector<uint8_t> srcData(numElements);
    std::vector<uint8_t> dstData(numElements);

    for (uint8_t i = 0; i < srcData.size(); i++)
    {
        srcData[i] = 128;
    }
    for (uint8_t i = 0; i < dstData.size(); i++)
    {
        dstData[i] = 0;
    }

    GLBuffer srcBuffer;
    GLBuffer dstBuffer;

    glBindBuffer(GL_ARRAY_BUFFER, srcBuffer);
    glBufferData(GL_ARRAY_BUFFER, srcData.size(), srcData.data(), GL_STATIC_DRAW);
    ASSERT_GL_NO_ERROR();

    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, dstBuffer);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, dstData.size(), dstData.data(), GL_STATIC_READ);
    ASSERT_GL_NO_ERROR();

    ANGLE_GL_PROGRAM(program, simpleVertex, simpleFragment);
    glUseProgram(program);

    GLint colorLoc = glGetAttribLocation(program, "color");
    ASSERT_NE(-1, colorLoc);

    glBindBuffer(GL_ARRAY_BUFFER, srcBuffer);
    glVertexAttribPointer(colorLoc, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, nullptr);
    glEnableVertexAttribArray(colorLoc);

    drawQuad(program, "position", 0.5f, 1.0f, true);
    ASSERT_GL_NO_ERROR();

    glCopyBufferSubData(GL_ARRAY_BUFFER, GL_PIXEL_UNPACK_BUFFER, 0, 0, numElements);

    // With GL_MAP_READ_BIT, we expect the data to be flushed and updated to match srcData
    uint8_t *data = reinterpret_cast<uint8_t *>(
        glMapBufferRange(GL_PIXEL_UNPACK_BUFFER, 0, numElements, GL_MAP_READ_BIT));
    EXPECT_GL_NO_ERROR();
    for (size_t i = 0; i < numElements; ++i)
    {
        EXPECT_EQ(srcData[i], data[i]);
    }
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
    EXPECT_GL_NO_ERROR();
}

// Test to verify mapping a buffer after copying to it contains expected data
// with GL_MAP_UNSYNCHRONIZED_BIT
TEST_P(BufferDataTestES3, MapBufferUnsynchronizedReadTest)
{
    const char simpleVertex[]   = R"(attribute vec2 position;
attribute vec4 color;
varying vec4 vColor;
void main()
{
    gl_Position = vec4(position, 0, 1);
    vColor = color;
}
)";
    const char simpleFragment[] = R"(precision mediump float;
varying vec4 vColor;
void main()
{
    gl_FragColor = vColor;
}
)";

    const uint32_t numComponents = 3;
    const uint32_t width         = 4;
    const uint32_t height        = 4;
    const size_t numElements     = width * height * numComponents;
    std::vector<uint8_t> srcData(numElements);
    std::vector<uint8_t> dstData(numElements);

    for (uint8_t i = 0; i < srcData.size(); i++)
    {
        srcData[i] = 128;
    }
    for (uint8_t i = 0; i < dstData.size(); i++)
    {
        dstData[i] = 0;
    }

    GLBuffer srcBuffer;
    GLBuffer dstBuffer;

    glBindBuffer(GL_ARRAY_BUFFER, srcBuffer);
    glBufferData(GL_ARRAY_BUFFER, srcData.size(), srcData.data(), GL_STATIC_DRAW);
    ASSERT_GL_NO_ERROR();

    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, dstBuffer);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, dstData.size(), dstData.data(), GL_STATIC_READ);
    ASSERT_GL_NO_ERROR();

    ANGLE_GL_PROGRAM(program, simpleVertex, simpleFragment);
    glUseProgram(program);

    GLint colorLoc = glGetAttribLocation(program, "color");
    ASSERT_NE(-1, colorLoc);

    glBindBuffer(GL_ARRAY_BUFFER, srcBuffer);
    glVertexAttribPointer(colorLoc, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, nullptr);
    glEnableVertexAttribArray(colorLoc);

    drawQuad(program, "position", 0.5f, 1.0f, true);
    ASSERT_GL_NO_ERROR();

    glCopyBufferSubData(GL_ARRAY_BUFFER, GL_PIXEL_UNPACK_BUFFER, 0, 0, numElements);

    // Synchronize.
    glFinish();

    // Map with GL_MAP_UNSYNCHRONIZED_BIT and overwrite buffers data with srcData
    uint8_t *data = reinterpret_cast<uint8_t *>(glMapBufferRange(
        GL_PIXEL_UNPACK_BUFFER, 0, numElements, GL_MAP_WRITE_BIT | GL_MAP_UNSYNCHRONIZED_BIT));
    EXPECT_GL_NO_ERROR();
    memcpy(data, srcData.data(), srcData.size());
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
    EXPECT_GL_NO_ERROR();

    // Map without GL_MAP_UNSYNCHRONIZED_BIT and read data. We expect it to be srcData
    data = reinterpret_cast<uint8_t *>(
        glMapBufferRange(GL_PIXEL_UNPACK_BUFFER, 0, numElements, GL_MAP_READ_BIT));
    EXPECT_GL_NO_ERROR();
    for (size_t i = 0; i < numElements; ++i)
    {
        EXPECT_EQ(srcData[i], data[i]);
    }
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
    EXPECT_GL_NO_ERROR();
}

// Verify the functionality of glMapBufferRange()'s GL_MAP_UNSYNCHRONIZED_BIT
// NOTE: On Vulkan, if we ever use memory that's not `VK_MEMORY_PROPERTY_HOST_COHERENT_BIT`, then
// this could incorrectly pass.
TEST_P(BufferDataTestES3, MapBufferRangeUnsynchronizedBit)
{
    // We can currently only control the behavior of the Vulkan backend's synchronizing operation's
    ANGLE_SKIP_TEST_IF(!IsVulkan());

    const size_t numElements = 10;
    std::vector<uint8_t> srcData(numElements);
    std::vector<uint8_t> dstData(numElements);

    for (uint8_t i = 0; i < srcData.size(); i++)
    {
        srcData[i] = i;
    }
    for (uint8_t i = 0; i < dstData.size(); i++)
    {
        dstData[i] = static_cast<uint8_t>(i + dstData.size());
    }

    GLBuffer srcBuffer;
    GLBuffer dstBuffer;

    glBindBuffer(GL_COPY_READ_BUFFER, srcBuffer);
    ASSERT_GL_NO_ERROR();
    glBindBuffer(GL_COPY_WRITE_BUFFER, dstBuffer);
    ASSERT_GL_NO_ERROR();

    glBufferData(GL_COPY_READ_BUFFER, srcData.size(), srcData.data(), GL_STATIC_DRAW);
    ASSERT_GL_NO_ERROR();
    glBufferData(GL_COPY_WRITE_BUFFER, dstData.size(), dstData.data(), GL_STATIC_READ);
    ASSERT_GL_NO_ERROR();

    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, numElements);

    // With GL_MAP_UNSYNCHRONIZED_BIT, we expect the data to be stale and match dstData
    // NOTE: We are specifying GL_MAP_WRITE_BIT so we can use GL_MAP_UNSYNCHRONIZED_BIT. This is
    // venturing into undefined behavior, since we are actually planning on reading from this
    // pointer.
    auto *data = reinterpret_cast<uint8_t *>(glMapBufferRange(
        GL_COPY_WRITE_BUFFER, 0, numElements, GL_MAP_WRITE_BIT | GL_MAP_UNSYNCHRONIZED_BIT));
    EXPECT_GL_NO_ERROR();
    for (size_t i = 0; i < numElements; ++i)
    {
        // Allow for the possibility that data matches either "dstData" or "srcData"
        if (dstData[i] != data[i])
        {
            EXPECT_EQ(srcData[i], data[i]);
        }
    }
    glUnmapBuffer(GL_COPY_WRITE_BUFFER);
    EXPECT_GL_NO_ERROR();

    // Without GL_MAP_UNSYNCHRONIZED_BIT, we expect the data to be copied and match srcData
    data = reinterpret_cast<uint8_t *>(
        glMapBufferRange(GL_COPY_WRITE_BUFFER, 0, numElements, GL_MAP_READ_BIT));
    EXPECT_GL_NO_ERROR();
    for (size_t i = 0; i < numElements; ++i)
    {
        EXPECT_EQ(srcData[i], data[i]);
    }
    glUnmapBuffer(GL_COPY_WRITE_BUFFER);
    EXPECT_GL_NO_ERROR();
}

// Verify OES_mapbuffer is present if EXT_map_buffer_range is.
TEST_P(BufferDataTest, ExtensionDependency)
{
    if (IsGLExtensionEnabled("GL_EXT_map_buffer_range"))
    {
        ASSERT_TRUE(IsGLExtensionEnabled("GL_OES_mapbuffer"));
    }
}

// Test mapping with the OES extension.
TEST_P(BufferDataTest, MapBufferOES)
{
    if (!IsGLExtensionEnabled("GL_EXT_map_buffer_range"))
    {
        // Needed for test validation.
        return;
    }

    std::vector<uint8_t> data(1024);
    FillVectorWithRandomUBytes(&data);

    GLBuffer buffer;
    glBindBuffer(GL_ARRAY_BUFFER, buffer.get());
    glBufferData(GL_ARRAY_BUFFER, data.size(), nullptr, GL_STATIC_DRAW);

    // Validate that other map flags don't work.
    void *badMapPtr = glMapBufferOES(GL_ARRAY_BUFFER, GL_MAP_READ_BIT);
    EXPECT_EQ(nullptr, badMapPtr);
    EXPECT_GL_ERROR(GL_INVALID_ENUM);

    // Map and write.
    void *mapPtr = glMapBufferOES(GL_ARRAY_BUFFER, GL_WRITE_ONLY_OES);
    ASSERT_NE(nullptr, mapPtr);
    ASSERT_GL_NO_ERROR();
    memcpy(mapPtr, data.data(), data.size());
    glUnmapBufferOES(GL_ARRAY_BUFFER);

    // Validate data with EXT_map_buffer_range
    void *readMapPtr = glMapBufferRangeEXT(GL_ARRAY_BUFFER, 0, data.size(), GL_MAP_READ_BIT_EXT);
    ASSERT_NE(nullptr, readMapPtr);
    ASSERT_GL_NO_ERROR();
    std::vector<uint8_t> actualData(data.size());
    memcpy(actualData.data(), readMapPtr, data.size());
    glUnmapBufferOES(GL_ARRAY_BUFFER);

    EXPECT_EQ(data, actualData);
}

// Test to verify mapping a dynamic buffer with GL_MAP_UNSYNCHRONIZED_BIT to modify a portion
// won't affect draw calls using other portions.
TEST_P(BufferDataTest, MapDynamicBufferUnsynchronizedEXTTest)
{
    ANGLE_SKIP_TEST_IF(!IsGLExtensionEnabled("GL_EXT_map_buffer_range"));

    const char simpleVertex[]   = R"(attribute vec2 position;
attribute vec4 color;
varying vec4 vColor;
void main()
{
    gl_Position = vec4(position, 0, 1);
    vColor = color;
}
)";
    const char simpleFragment[] = R"(precision mediump float;
varying vec4 vColor;
void main()
{
    gl_FragColor = vColor;
}
)";

    constexpr int kNumVertices = 6;

    std::vector<GLubyte> color(8 * kNumVertices);
    for (int i = 0; i < kNumVertices; ++i)
    {
        color[4 * i]     = 255;
        color[4 * i + 3] = 255;
    }
    GLBuffer buffer;
    glBindBuffer(GL_ARRAY_BUFFER, buffer.get());
    glBufferData(GL_ARRAY_BUFFER, color.size(), color.data(), GL_DYNAMIC_DRAW);

    ANGLE_GL_PROGRAM(program, simpleVertex, simpleFragment);
    glUseProgram(program);

    GLint colorLoc = glGetAttribLocation(program, "color");
    ASSERT_NE(-1, colorLoc);

    glVertexAttribPointer(colorLoc, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0, nullptr);
    glEnableVertexAttribArray(colorLoc);

    glViewport(0, 0, 2, 2);
    drawQuad(program, "position", 0.5f, 1.0f, true);
    ASSERT_GL_NO_ERROR();

    // Map with GL_MAP_UNSYNCHRONIZED_BIT and overwrite buffers data at offset 24
    uint8_t *data = reinterpret_cast<uint8_t *>(
        glMapBufferRangeEXT(GL_ARRAY_BUFFER, 4 * kNumVertices, 4 * kNumVertices,
                            GL_MAP_WRITE_BIT | GL_MAP_UNSYNCHRONIZED_BIT));
    EXPECT_GL_NO_ERROR();
    for (int i = 0; i < kNumVertices; ++i)
    {
        data[4 * i]     = 0;
        data[4 * i + 1] = 255;
        data[4 * i + 2] = 0;
        data[4 * i + 3] = 255;
    }
    glUnmapBufferOES(GL_ARRAY_BUFFER);
    EXPECT_GL_NO_ERROR();

    // Re-draw using offset = 0 but to different viewport
    glViewport(0, 2, 2, 2);
    drawQuad(program, "position", 0.5f, 1.0f, true);
    ASSERT_GL_NO_ERROR();

    // Change vertex attribute to use buffer starting from offset 24
    glVertexAttribPointer(colorLoc, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0,
                          reinterpret_cast<void *>(4 * kNumVertices));

    glViewport(2, 2, 2, 2);
    drawQuad(program, "position", 0.5f, 1.0f, true);
    ASSERT_GL_NO_ERROR();

    EXPECT_PIXEL_COLOR_EQ(1, 1, GLColor::red);
    EXPECT_PIXEL_COLOR_EQ(1, 3, GLColor::red);
    EXPECT_PIXEL_COLOR_EQ(3, 3, GLColor::green);
}

// Verify that we can map and write the buffer between draws and the second draw sees the new buffer
// data, using drawQuad().
TEST_P(BufferDataTest, MapWriteArrayBufferDataDrawQuad)
{
    ANGLE_SKIP_TEST_IF(!IsGLExtensionEnabled("GL_EXT_map_buffer_range"));

    std::vector<GLfloat> data(6, 0.0f);

    glUseProgram(mProgram);
    glBindBuffer(GL_ARRAY_BUFFER, mBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), nullptr, GL_STATIC_DRAW);
    glVertexAttribPointer(mAttribLocation, 1, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(mAttribLocation);

    // Don't read back to verify black, so we don't break the render pass.
    drawQuad(mProgram, "position", 0.5f);
    EXPECT_GL_NO_ERROR();

    // Map and write.
    std::vector<GLfloat> data2(6, 1.0f);
    void *mapPtr = glMapBufferOES(GL_ARRAY_BUFFER, GL_WRITE_ONLY_OES);
    ASSERT_NE(nullptr, mapPtr);
    ASSERT_GL_NO_ERROR();
    memcpy(mapPtr, data2.data(), sizeof(GLfloat) * data2.size());
    glUnmapBufferOES(GL_ARRAY_BUFFER);

    drawQuad(mProgram, "position", 0.5f);
    EXPECT_PIXEL_COLOR_EQ(8, 8, GLColor::red);
    EXPECT_GL_NO_ERROR();
}

// Verify that we can map and write the buffer between draws and the second draw sees the new buffer
// data, calling glDrawArrays() directly.
TEST_P(BufferDataTest, MapWriteArrayBufferDataDrawArrays)
{
    ANGLE_SKIP_TEST_IF(!IsGLExtensionEnabled("GL_EXT_map_buffer_range"));

    std::vector<GLfloat> data(6, 0.0f);

    glUseProgram(mProgram);

    GLint positionLocation = glGetAttribLocation(mProgram, "position");
    ASSERT_NE(-1, positionLocation);

    // Set up position attribute, don't use drawQuad.
    auto quadVertices = GetQuadVertices();

    GLBuffer positionBuffer;
    glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * quadVertices.size() * 3, quadVertices.data(),
                 GL_DYNAMIC_DRAW);
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(positionLocation);
    EXPECT_GL_NO_ERROR();

    glBindBuffer(GL_ARRAY_BUFFER, mBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), nullptr, GL_STATIC_DRAW);
    glVertexAttribPointer(mAttribLocation, 1, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(mAttribLocation);
    EXPECT_GL_NO_ERROR();

    // Don't read back to verify black, so we don't break the render pass.
    glDrawArrays(GL_TRIANGLES, 0, 6);
    EXPECT_GL_NO_ERROR();

    // Map and write.
    std::vector<GLfloat> data2(6, 1.0f);
    void *mapPtr = glMapBufferOES(GL_ARRAY_BUFFER, GL_WRITE_ONLY_OES);
    ASSERT_NE(nullptr, mapPtr);
    ASSERT_GL_NO_ERROR();
    memcpy(mapPtr, data2.data(), sizeof(GLfloat) * data2.size());
    glUnmapBufferOES(GL_ARRAY_BUFFER);

    glDrawArrays(GL_TRIANGLES, 0, 6);
    EXPECT_PIXEL_COLOR_EQ(8, 8, GLColor::red);
    EXPECT_GL_NO_ERROR();
}

// Tests a null crash bug caused by copying from null back-end buffer pointer
// when calling bufferData again after drawing without calling bufferData in D3D11.
TEST_P(BufferDataTestES3, DrawWithNotCallingBufferData)
{
    ANGLE_GL_PROGRAM(drawRed, essl3_shaders::vs::Simple(), essl3_shaders::fs::Red());
    glUseProgram(drawRed);

    GLint mem = 0;
    GLBuffer buffer;
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindBuffer(GL_COPY_WRITE_BUFFER, buffer);
    glBufferData(GL_COPY_WRITE_BUFFER, 1, &mem, GL_STREAM_DRAW);
    ASSERT_GL_NO_ERROR();
}

// Tests a bug where copying buffer data immediately after creation hit a nullptr in D3D11.
TEST_P(BufferDataTestES3, NoBufferInitDataCopyBug)
{
    constexpr GLsizei size = 64;

    GLBuffer sourceBuffer;
    glBindBuffer(GL_COPY_READ_BUFFER, sourceBuffer);
    glBufferData(GL_COPY_READ_BUFFER, size, nullptr, GL_STATIC_DRAW);

    GLBuffer destBuffer;
    glBindBuffer(GL_ARRAY_BUFFER, destBuffer);
    glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_STATIC_DRAW);

    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_ARRAY_BUFFER, 0, 0, size);
    ASSERT_GL_NO_ERROR();
}

// Ensures that calling glBufferData on a mapped buffer results in an unmapped buffer
TEST_P(BufferDataTestES3, BufferDataUnmap)
{
    // Per the OpenGL ES 3.0 spec, buffers are implicity unmapped when a call to
    // BufferData happens on a mapped buffer:
    //
    //    If any portion of the buffer object is mapped in the current context or
    //    any context current to another thread, it is as though UnmapBuffer
    //    (see section 2.10.3) is executed in each such context prior to deleting
    //    the existing data store.
    //

    std::vector<uint8_t> data1(16);
    std::vector<uint8_t> data2(16);

    GLBuffer dataBuffer;
    glBindBuffer(GL_ARRAY_BUFFER, dataBuffer);
    glBufferData(GL_ARRAY_BUFFER, data1.size(), data1.data(), GL_STATIC_DRAW);

    // Map the buffer once
    glMapBufferRange(GL_ARRAY_BUFFER, 0, data1.size(),
                     GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT | GL_MAP_FLUSH_EXPLICIT_BIT |
                         GL_MAP_UNSYNCHRONIZED_BIT);

    // Then repopulate the buffer. This should cause the buffer to become unmapped.
    glBufferData(GL_ARRAY_BUFFER, data2.size(), data2.data(), GL_STATIC_DRAW);
    ASSERT_GL_NO_ERROR();

    // Try to unmap the buffer, this should fail
    bool result = glUnmapBuffer(GL_ARRAY_BUFFER);
    ASSERT_EQ(result, false);
    EXPECT_GL_ERROR(GL_INVALID_OPERATION);

    // Try to map the buffer again, which should succeed
    glMapBufferRange(GL_ARRAY_BUFFER, 0, data2.size(),
                     GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT | GL_MAP_FLUSH_EXPLICIT_BIT |
                         GL_MAP_UNSYNCHRONIZED_BIT);
    ASSERT_GL_NO_ERROR();
}

// Ensures that mapping buffer with GL_MAP_INVALIDATE_BUFFER_BIT followed by glBufferSubData calls
// works.  Regression test for the Vulkan backend where that flag caused use after free.
TEST_P(BufferDataTestES3, MapInvalidateThenBufferSubData)
{
    // http://anglebug.com/5984
    ANGLE_SKIP_TEST_IF(IsWindows() && IsOpenGL() && IsIntel());

    // http://anglebug.com/5985
    ANGLE_SKIP_TEST_IF(IsNexus5X() && IsOpenGLES());

    const std::array<GLColor, 4> kInitialData = {GLColor::red, GLColor::red, GLColor::red,
                                                 GLColor::red};
    const std::array<GLColor, 4> kUpdateData1 = {GLColor::white, GLColor::white, GLColor::white,
                                                 GLColor::white};
    const std::array<GLColor, 4> kUpdateData2 = {GLColor::blue, GLColor::blue, GLColor::blue,
                                                 GLColor::blue};

    GLBuffer buffer;
    glBindBuffer(GL_UNIFORM_BUFFER, buffer);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(kInitialData), kInitialData.data(), GL_DYNAMIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, 0, buffer);
    EXPECT_GL_NO_ERROR();

    // Draw
    constexpr char kVerifyUBO[] = R"(#version 300 es
precision mediump float;
uniform block {
    uvec4 data;
} ubo;
uniform uint expect;
uniform vec4 successOutput;
out vec4 colorOut;
void main()
{
    if (all(equal(ubo.data, uvec4(expect))))
        colorOut = successOutput;
    else
        colorOut = vec4(1.0, 0, 0, 1.0);
})";

    ANGLE_GL_PROGRAM(verifyUbo, essl3_shaders::vs::Simple(), kVerifyUBO);
    glUseProgram(verifyUbo);

    GLint expectLoc = glGetUniformLocation(verifyUbo, "expect");
    EXPECT_NE(-1, expectLoc);
    GLint successLoc = glGetUniformLocation(verifyUbo, "successOutput");
    EXPECT_NE(-1, successLoc);

    glUniform1ui(expectLoc, kInitialData[0].asUint());
    glUniform4f(successLoc, 0, 1, 0, 1);

    drawQuad(verifyUbo, essl3_shaders::PositionAttrib(), 0.5);
    EXPECT_GL_NO_ERROR();

    // Dont't verify the buffer.  This is testing GL_MAP_INVALIDATE_BUFFER_BIT while the buffer is
    // in use by the GPU.

    // Map the buffer and update it.
    void *mappedBuffer = glMapBufferRange(GL_UNIFORM_BUFFER, 0, sizeof(kInitialData),
                                          GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);

    memcpy(mappedBuffer, kUpdateData1.data(), sizeof(kInitialData));

    glUnmapBuffer(GL_UNIFORM_BUFFER);
    EXPECT_GL_NO_ERROR();

    // Verify that the buffer has the updated value.
    glUniform1ui(expectLoc, kUpdateData1[0].asUint());
    glUniform4f(successLoc, 0, 0, 1, 1);

    drawQuad(verifyUbo, essl3_shaders::PositionAttrib(), 0.5);
    EXPECT_GL_NO_ERROR();

    EXPECT_PIXEL_COLOR_EQ(0, 0, GLColor::blue);

    // Update the buffer with glBufferSubData
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(kUpdateData2), kUpdateData2.data());
    EXPECT_GL_NO_ERROR();

    // Verify that the buffer has the updated value.
    glUniform1ui(expectLoc, kUpdateData2[0].asUint());
    glUniform4f(successLoc, 0, 1, 1, 1);

    drawQuad(verifyUbo, essl3_shaders::PositionAttrib(), 0.5);
    EXPECT_GL_NO_ERROR();

    EXPECT_PIXEL_COLOR_EQ(0, 0, GLColor::cyan);
}

class BufferStorageTestES3 : public BufferDataTest
{};

// Tests that proper error value is returned when bad size is passed in
TEST_P(BufferStorageTestES3, BufferStorageInvalidSize)
{
    ANGLE_SKIP_TEST_IF(!IsGLExtensionEnabled("GL_EXT_buffer_storage"));

    std::vector<GLfloat> data(6, 1.0f);

    GLBuffer buffer;
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferStorageEXT(GL_ARRAY_BUFFER, 0, data.data(), 0);
    EXPECT_GL_ERROR(GL_INVALID_VALUE);
}

// Tests that buffer storage can be allocated with the GL_MAP_PERSISTENT_BIT_EXT and
// GL_MAP_COHERENT_BIT_EXT flags
TEST_P(BufferStorageTestES3, BufferStorageFlagsPersistentCoherentWrite)
{
    ANGLE_SKIP_TEST_IF(!IsGLExtensionEnabled("GL_EXT_buffer_storage"));

    std::vector<GLfloat> data(6, 1.0f);

    GLBuffer buffer;
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferStorageEXT(GL_ARRAY_BUFFER, data.size(), data.data(),
                       GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT_EXT | GL_MAP_COHERENT_BIT_EXT);
    ASSERT_GL_NO_ERROR();
}

// Verify that glBufferStorage makes a buffer immutable
TEST_P(BufferStorageTestES3, StorageBufferBufferData)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 ||
                       !IsGLExtensionEnabled("GL_EXT_buffer_storage"));

    std::vector<GLfloat> data(6, 1.0f);

    GLBuffer buffer;
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferStorageEXT(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), data.data(), 0);
    ASSERT_GL_NO_ERROR();

    // Verify that calling glBufferStorageEXT again produces an error.
    glBufferStorageEXT(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), data.data(), 0);
    EXPECT_GL_ERROR(GL_INVALID_OPERATION);

    // Verify that calling glBufferData after calling glBufferStorageEXT produces an error.
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), data.data(), GL_STATIC_DRAW);
    EXPECT_GL_ERROR(GL_INVALID_OPERATION);
}

// Verify that glBufferStorageEXT can be called after glBufferData
TEST_P(BufferStorageTestES3, BufferDataStorageBuffer)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 ||
                       !IsGLExtensionEnabled("GL_EXT_buffer_storage"));

    std::vector<GLfloat> data(6, 1.0f);

    GLBuffer buffer;
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), data.data(), GL_STATIC_DRAW);
    ASSERT_GL_NO_ERROR();

    // Verify that calling glBufferStorageEXT again produces an error.
    glBufferStorageEXT(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), data.data(), 0);
    ASSERT_GL_NO_ERROR();
}

// Verify that we can perform subdata updates to a buffer marked with GL_DYNAMIC_STORAGE_BIT_EXT
// usage flag
TEST_P(BufferStorageTestES3, StorageBufferSubData)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 ||
                       !IsGLExtensionEnabled("GL_EXT_buffer_storage"));

    std::vector<GLfloat> data(6, 0.0f);

    glUseProgram(mProgram);
    glBindBuffer(GL_ARRAY_BUFFER, mBuffer);
    glBufferStorageEXT(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), nullptr,
                       GL_DYNAMIC_STORAGE_BIT_EXT);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * data.size(), data.data());
    glVertexAttribPointer(mAttribLocation, 1, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(mAttribLocation);

    drawQuad(mProgram, "position", 0.5f);
    EXPECT_PIXEL_COLOR_EQ(8, 8, GLColor::black);
    EXPECT_GL_NO_ERROR();

    std::vector<GLfloat> data2(6, 1.0f);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * data2.size(), data2.data());

    drawQuad(mProgram, "position", 0.5f);
    EXPECT_PIXEL_COLOR_EQ(8, 8, GLColor::red);
    EXPECT_GL_NO_ERROR();
}

// Test interaction between GL_OES_mapbuffer and GL_EXT_buffer_storage extensions.
TEST_P(BufferStorageTestES3, StorageBufferMapBufferOES)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 ||
                       !IsGLExtensionEnabled("GL_EXT_buffer_storage") ||
                       !IsGLExtensionEnabled("GL_EXT_map_buffer_range"));

    std::vector<uint8_t> data(1024);
    FillVectorWithRandomUBytes(&data);

    GLBuffer buffer;
    glBindBuffer(GL_ARRAY_BUFFER, buffer.get());
    glBufferStorageEXT(GL_ARRAY_BUFFER, data.size(), nullptr, GL_MAP_READ_BIT | GL_MAP_WRITE_BIT);

    // Validate that other map flags don't work.
    void *badMapPtr = glMapBufferOES(GL_ARRAY_BUFFER, GL_MAP_READ_BIT);
    EXPECT_EQ(nullptr, badMapPtr);
    EXPECT_GL_ERROR(GL_INVALID_ENUM);

    // Map and write.
    void *mapPtr = glMapBufferOES(GL_ARRAY_BUFFER, GL_WRITE_ONLY_OES);
    ASSERT_NE(nullptr, mapPtr);
    ASSERT_GL_NO_ERROR();
    memcpy(mapPtr, data.data(), data.size());
    glUnmapBufferOES(GL_ARRAY_BUFFER);

    // Validate data with EXT_map_buffer_range
    void *readMapPtr = glMapBufferRangeEXT(GL_ARRAY_BUFFER, 0, data.size(), GL_MAP_READ_BIT_EXT);
    ASSERT_NE(nullptr, readMapPtr);
    ASSERT_GL_NO_ERROR();
    std::vector<uint8_t> actualData(data.size());
    memcpy(actualData.data(), readMapPtr, data.size());
    glUnmapBufferOES(GL_ARRAY_BUFFER);

    EXPECT_EQ(data, actualData);
}

// Verify persistently mapped buffers can use glCopyBufferSubData
// Tests a pattern used by Fortnite's GLES backend
TEST_P(BufferStorageTestES3, StorageCopyBufferSubDataMapped)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 ||
                       !IsGLExtensionEnabled("GL_EXT_buffer_storage") ||
                       !IsGLExtensionEnabled("GL_EXT_map_buffer_range"));

    const std::array<GLColor, 4> kInitialData = {GLColor::red, GLColor::green, GLColor::blue,
                                                 GLColor::yellow};

    // Set up the read buffer
    GLBuffer readBuffer;
    glBindBuffer(GL_ARRAY_BUFFER, readBuffer.get());
    glBufferData(GL_ARRAY_BUFFER, sizeof(kInitialData), kInitialData.data(), GL_DYNAMIC_DRAW);

    // Set up the write buffer to be persistently mapped
    GLBuffer writeBuffer;
    glBindBuffer(GL_COPY_WRITE_BUFFER, writeBuffer.get());
    glBufferStorageEXT(GL_COPY_WRITE_BUFFER, 16, nullptr,
                       GL_MAP_READ_BIT | GL_MAP_PERSISTENT_BIT_EXT | GL_MAP_COHERENT_BIT_EXT);
    void *readMapPtr =
        glMapBufferRange(GL_COPY_WRITE_BUFFER, 0, 16,
                         GL_MAP_READ_BIT | GL_MAP_PERSISTENT_BIT_EXT | GL_MAP_COHERENT_BIT_EXT);
    ASSERT_NE(nullptr, readMapPtr);
    ASSERT_GL_NO_ERROR();

    // Verify we can copy into the write buffer
    glBindBuffer(GL_COPY_READ_BUFFER, readBuffer.get());
    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, 16);
    ASSERT_GL_NO_ERROR();

    // Flush the buffer.
    glFinish();

    // Check the contents
    std::array<GLColor, 4> resultingData;
    memcpy(resultingData.data(), readMapPtr, resultingData.size() * sizeof(GLColor));
    glUnmapBuffer(GL_COPY_WRITE_BUFFER);
    EXPECT_EQ(kInitialData, resultingData);
    ASSERT_GL_NO_ERROR();
}

// Verify persistently mapped element array buffers can use glDrawElements
TEST_P(BufferStorageTestES3, DrawElementsElementArrayBufferMapped)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 ||
                       !IsGLExtensionEnabled("GL_EXT_buffer_storage") ||
                       !IsGLExtensionEnabled("GL_EXT_map_buffer_range"));

    GLfloat kVertexBuffer[] = {-1.0f, -1.0f, 1.0f,  // (x, y, R)
                               -1.0f, 1.0f,  1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    // Set up array buffer
    GLBuffer readBuffer;
    glBindBuffer(GL_ARRAY_BUFFER, readBuffer.get());
    glBufferData(GL_ARRAY_BUFFER, sizeof(kVertexBuffer), kVertexBuffer, GL_DYNAMIC_DRAW);
    GLint vLoc = glGetAttribLocation(mProgram, "position");
    GLint cLoc = mAttribLocation;
    glVertexAttribPointer(vLoc, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
    glEnableVertexAttribArray(vLoc);
    glVertexAttribPointer(cLoc, 1, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (const GLvoid *)8);
    glEnableVertexAttribArray(cLoc);

    // Set up the element array buffer to be persistently mapped
    GLshort kElementArrayBuffer[] = {0, 0, 0, 0, 0, 0};

    GLBuffer indexBuffer;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer.get());
    glBufferStorageEXT(GL_ELEMENT_ARRAY_BUFFER, sizeof(kElementArrayBuffer), kElementArrayBuffer,
                       GL_DYNAMIC_STORAGE_BIT_EXT | GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT_EXT |
                           GL_MAP_COHERENT_BIT_EXT);

    glUseProgram(mProgram);

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_SHORT, 0);
    ASSERT_GL_NO_ERROR();
    EXPECT_PIXEL_COLOR_EQ(0, 0, GLColor::transparentBlack);

    GLshort *mappedPtr = (GLshort *)glMapBufferRange(
        GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(kElementArrayBuffer),
        GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT_EXT | GL_MAP_COHERENT_BIT_EXT);
    ASSERT_NE(nullptr, mappedPtr);
    ASSERT_GL_NO_ERROR();

    mappedPtr[0] = 0;
    mappedPtr[1] = 1;
    mappedPtr[2] = 2;
    mappedPtr[3] = 2;
    mappedPtr[4] = 1;
    mappedPtr[5] = 3;
    glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_SHORT, 0);

    ASSERT_GL_NO_ERROR();

    EXPECT_PIXEL_COLOR_EQ(0, 0, GLColor::red);
}

// Verify persistently mapped buffers can use glBufferSubData
TEST_P(BufferStorageTestES3, StorageBufferSubDataMapped)
{
    ANGLE_SKIP_TEST_IF(getClientMajorVersion() < 3 ||
                       !IsGLExtensionEnabled("GL_EXT_buffer_storage") ||
                       !IsGLExtensionEnabled("GL_EXT_map_buffer_range"));

    const std::array<GLColor, 4> kUpdateData1 = {GLColor::red, GLColor::green, GLColor::blue,
                                                 GLColor::yellow};

    // Set up the buffer to be persistently mapped and dynamic
    GLBuffer buffer;
    glBindBuffer(GL_ARRAY_BUFFER, buffer.get());
    glBufferStorageEXT(GL_ARRAY_BUFFER, 16, nullptr,
                       GL_MAP_READ_BIT | GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT_EXT |
                           GL_MAP_COHERENT_BIT_EXT | GL_DYNAMIC_STORAGE_BIT_EXT);
    void *readMapPtr = glMapBufferRange(
        GL_ARRAY_BUFFER, 0, 16,
        GL_MAP_READ_BIT | GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT_EXT | GL_MAP_COHERENT_BIT_EXT);
    ASSERT_NE(nullptr, readMapPtr);
    ASSERT_GL_NO_ERROR();

    // Verify we can push new data into the buffer
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLColor) * kUpdateData1.size(), kUpdateData1.data());
    ASSERT_GL_NO_ERROR();

    // Flush the buffer.
    glFinish();

    // Check the contents
    std::array<GLColor, 4> persistentData1;
    memcpy(persistentData1.data(), readMapPtr, persistentData1.size() * sizeof(GLColor));
    EXPECT_EQ(kUpdateData1, persistentData1);
    glUnmapBuffer(GL_ARRAY_BUFFER);
    ASSERT_GL_NO_ERROR();
}

ANGLE_INSTANTIATE_TEST_ES2(BufferDataTest);

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(BufferDataTestES3);
ANGLE_INSTANTIATE_TEST_ES3_AND(BufferDataTestES3, WithDirectSPIRVGeneration(ES3_VULKAN()));

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(BufferStorageTestES3);
ANGLE_INSTANTIATE_TEST_ES3(BufferStorageTestES3);

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(IndexedBufferCopyTest);
ANGLE_INSTANTIATE_TEST_ES3(IndexedBufferCopyTest);

#ifdef _WIN64

// Test a bug where an integer overflow bug could trigger a crash in D3D.
// The test uses 8 buffers with a size just under 0x2000000 to overflow max uint
// (with the internal D3D rounding to 16-byte values) and trigger the bug.
// Only handle this bug on 64-bit Windows for now. Harder to repro on 32-bit.
class BufferDataOverflowTest : public ANGLETest
{
  protected:
    BufferDataOverflowTest() {}
};

// See description above.
TEST_P(BufferDataOverflowTest, VertexBufferIntegerOverflow)
{
    // These values are special, to trigger the rounding bug.
    unsigned int numItems       = 0x7FFFFFE;
    constexpr GLsizei bufferCnt = 8;

    std::vector<GLBuffer> buffers(bufferCnt);

    std::stringstream vertexShaderStr;

    for (GLsizei bufferIndex = 0; bufferIndex < bufferCnt; ++bufferIndex)
    {
        vertexShaderStr << "attribute float attrib" << bufferIndex << ";\n";
    }

    vertexShaderStr << "attribute vec2 position;\n"
                       "varying float v_attrib;\n"
                       "void main() {\n"
                       "  gl_Position = vec4(position, 0, 1);\n"
                       "  v_attrib = 0.0;\n";

    for (GLsizei bufferIndex = 0; bufferIndex < bufferCnt; ++bufferIndex)
    {
        vertexShaderStr << "v_attrib += attrib" << bufferIndex << ";\n";
    }

    vertexShaderStr << "}";

    constexpr char kFS[] =
        "varying highp float v_attrib;\n"
        "void main() {\n"
        "  gl_FragColor = vec4(v_attrib, 0, 0, 1);\n"
        "}";

    ANGLE_GL_PROGRAM(program, vertexShaderStr.str().c_str(), kFS);
    glUseProgram(program.get());

    std::vector<GLfloat> data(numItems, 1.0f);

    for (GLsizei bufferIndex = 0; bufferIndex < bufferCnt; ++bufferIndex)
    {
        glBindBuffer(GL_ARRAY_BUFFER, buffers[bufferIndex].get());
        glBufferData(GL_ARRAY_BUFFER, numItems * sizeof(float), &data[0], GL_DYNAMIC_DRAW);

        std::stringstream attribNameStr;
        attribNameStr << "attrib" << bufferIndex;

        GLint attribLocation = glGetAttribLocation(program.get(), attribNameStr.str().c_str());
        ASSERT_NE(-1, attribLocation);

        glVertexAttribPointer(attribLocation, 1, GL_FLOAT, GL_FALSE, 4, nullptr);
        glEnableVertexAttribArray(attribLocation);
    }

    GLint positionLocation = glGetAttribLocation(program.get(), "position");
    ASSERT_NE(-1, positionLocation);
    glDisableVertexAttribArray(positionLocation);
    glVertexAttrib2f(positionLocation, 1.0f, 1.0f);

    EXPECT_GL_NO_ERROR();
    glDrawArrays(GL_TRIANGLES, 0, numItems);
    EXPECT_GL_ERROR(GL_OUT_OF_MEMORY);

    // Test that a small draw still works.
    for (GLsizei bufferIndex = 0; bufferIndex < bufferCnt; ++bufferIndex)
    {
        std::stringstream attribNameStr;
        attribNameStr << "attrib" << bufferIndex;
        GLint attribLocation = glGetAttribLocation(program.get(), attribNameStr.str().c_str());
        ASSERT_NE(-1, attribLocation);
        glDisableVertexAttribArray(attribLocation);
    }

    glDrawArrays(GL_TRIANGLES, 0, 3);
    EXPECT_GL_ERROR(GL_NO_ERROR);
}

// Tests a security bug in our CopyBufferSubData validation (integer overflow).
TEST_P(BufferDataOverflowTest, CopySubDataValidation)
{
    GLBuffer readBuffer, writeBuffer;

    glBindBuffer(GL_COPY_READ_BUFFER, readBuffer.get());
    glBindBuffer(GL_COPY_WRITE_BUFFER, writeBuffer.get());

    constexpr int bufSize = 100;

    glBufferData(GL_COPY_READ_BUFFER, bufSize, nullptr, GL_STATIC_DRAW);
    glBufferData(GL_COPY_WRITE_BUFFER, bufSize, nullptr, GL_STATIC_DRAW);

    GLintptr big = std::numeric_limits<GLintptr>::max() - bufSize + 90;

    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, big, 0, 50);
    EXPECT_GL_ERROR(GL_INVALID_VALUE);

    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, big, 50);
    EXPECT_GL_ERROR(GL_INVALID_VALUE);
}

ANGLE_INSTANTIATE_TEST_ES3(BufferDataOverflowTest);

#endif  // _WIN64
