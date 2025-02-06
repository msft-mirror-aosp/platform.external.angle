//
// Copyright 2019 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// validationES32.cpp: Validation functions for OpenGL ES 3.2 entry point parameters

#include "libANGLE/validationES32_autogen.h"

#include "libANGLE/Context.h"
#include "libANGLE/ErrorStrings.h"
#include "libANGLE/Framebuffer.h"
#include "libANGLE/VertexArray.h"
#include "libANGLE/validationES.h"
#include "libANGLE/validationES2.h"
#include "libANGLE/validationES3.h"
#include "libANGLE/validationES31.h"
#include "libANGLE/validationES31_autogen.h"
#include "libANGLE/validationES3_autogen.h"

#include "common/utilities.h"

using namespace angle;

namespace gl
{
using namespace err;

namespace
{
// ANGLE_shader_pixel_local_storage: INVALID_OPERATION is generated by Enablei*(), Disablei*() if
// <cap> is not one of: BLEND, SCISSOR_TEST, SCISSOR_TEST_EXCLUSIVE_NV.
static bool IsIndexedCapBannedWithActivePLS(GLenum cap)
{
    switch (cap)
    {
        case GL_BLEND:
        case GL_SCISSOR_TEST:
        case GL_SCISSOR_TEST_EXCLUSIVE_NV:
            return false;
        default:
            return true;
    }
}
}  // anonymous namespace

bool ValidateBlendBarrier(const Context *context, angle::EntryPoint entryPoint)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    return true;
}

bool ValidateBlendEquationSeparatei(const PrivateState &state,
                                    ErrorSet *errors,
                                    angle::EntryPoint entryPoint,
                                    GLuint buf,
                                    GLenum modeRGB,
                                    GLenum modeAlpha)
{
    if (buf >= static_cast<GLuint>(state.getCaps().maxDrawBuffers))
    {
        errors->validationError(entryPoint, GL_INVALID_VALUE, kExceedsMaxDrawBuffers);
        return false;
    }

    if (!ValidateBlendEquationSeparate(state, errors, entryPoint, modeRGB, modeAlpha))
    {
        // error already generated
        return false;
    }

    return true;
}

bool ValidateBlendEquationi(const PrivateState &state,
                            ErrorSet *errors,
                            angle::EntryPoint entryPoint,
                            GLuint buf,
                            GLenum mode)
{
    if (buf >= static_cast<GLuint>(state.getCaps().maxDrawBuffers))
    {
        errors->validationError(entryPoint, GL_INVALID_VALUE, kExceedsMaxDrawBuffers);
        return false;
    }

    if (!ValidateBlendEquation(state, errors, entryPoint, mode))
    {
        // error already generated
        return false;
    }

    return true;
}

bool ValidateBlendFuncSeparatei(const PrivateState &state,
                                ErrorSet *errors,
                                angle::EntryPoint entryPoint,
                                GLuint buf,
                                GLenum srcRGB,
                                GLenum dstRGB,
                                GLenum srcAlpha,
                                GLenum dstAlpha)
{
    if (buf >= static_cast<GLuint>(state.getCaps().maxDrawBuffers))
    {
        errors->validationError(entryPoint, GL_INVALID_VALUE, kExceedsMaxDrawBuffers);
        return false;
    }

    if (!ValidateBlendFuncSeparate(state, errors, entryPoint, srcRGB, dstRGB, srcAlpha, dstAlpha))
    {
        // error already generated
        return false;
    }

    return true;
}

bool ValidateBlendFunci(const PrivateState &state,
                        ErrorSet *errors,
                        angle::EntryPoint entryPoint,
                        GLuint buf,
                        GLenum src,
                        GLenum dst)
{
    if (buf >= static_cast<GLuint>(state.getCaps().maxDrawBuffers))
    {
        errors->validationError(entryPoint, GL_INVALID_VALUE, kExceedsMaxDrawBuffers);
        return false;
    }

    if (!ValidateBlendFunc(state, errors, entryPoint, src, dst))
    {
        // error already generated
        return false;
    }

    return true;
}

bool ValidateColorMaski(const PrivateState &state,
                        ErrorSet *errors,
                        angle::EntryPoint entryPoint,
                        GLuint buf,
                        GLboolean r,
                        GLboolean g,
                        GLboolean b,
                        GLboolean a)
{
    if (buf >= static_cast<GLuint>(state.getCaps().maxDrawBuffers))
    {
        errors->validationError(entryPoint, GL_INVALID_VALUE, kIndexExceedsMaxDrawBuffer);
        return false;
    }

    return true;
}

bool ValidateCopyImageSubData(const Context *context,
                              angle::EntryPoint entryPoint,
                              GLuint srcName,
                              GLenum srcTarget,
                              GLint srcLevel,
                              GLint srcX,
                              GLint srcY,
                              GLint srcZ,
                              GLuint dstName,
                              GLenum dstTarget,
                              GLint dstLevel,
                              GLint dstX,
                              GLint dstY,
                              GLint dstZ,
                              GLsizei srcWidth,
                              GLsizei srcHeight,
                              GLsizei srcDepth)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    return ValidateCopyImageSubDataBase(context, entryPoint, srcName, srcTarget, srcLevel, srcX,
                                        srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ,
                                        srcWidth, srcHeight, srcDepth);
}

bool ValidateDebugMessageCallback(const Context *context,
                                  angle::EntryPoint entryPoint,
                                  GLDEBUGPROC callback,
                                  const void *userParam)
{
    return true;
}

bool ValidateDebugMessageControl(const Context *context,
                                 angle::EntryPoint entryPoint,
                                 GLenum source,
                                 GLenum type,
                                 GLenum severity,
                                 GLsizei count,
                                 const GLuint *ids,
                                 GLboolean enabled)
{
    return true;
}

bool ValidateDebugMessageInsert(const Context *context,
                                angle::EntryPoint entryPoint,
                                GLenum source,
                                GLenum type,
                                GLuint id,
                                GLenum severity,
                                GLsizei length,
                                const GLchar *buf)
{
    return true;
}

bool ValidateDisablei(const PrivateState &state,
                      ErrorSet *errors,
                      angle::EntryPoint entryPoint,
                      GLenum target,
                      GLuint index)
{
    int numPLSPlanes = state.getPixelLocalStorageActivePlanes();
    if (numPLSPlanes != 0)
    {
        if (IsIndexedCapBannedWithActivePLS(target))
        {
            errors->validationErrorF(entryPoint, GL_INVALID_OPERATION, kPLSCapNotAllowed, target);
            return false;
        }
    }

    switch (target)
    {
        case GL_BLEND:
            if (index >= static_cast<GLuint>(state.getCaps().maxDrawBuffers))
            {
                errors->validationError(entryPoint, GL_INVALID_VALUE, kIndexExceedsMaxDrawBuffer);
                return false;
            }
            break;
        default:
            errors->validationErrorF(entryPoint, GL_INVALID_ENUM, kEnumNotSupported, target);
            return false;
    }
    return true;
}

bool ValidateDrawElementsBaseVertex(const Context *context,
                                    angle::EntryPoint entryPoint,
                                    PrimitiveMode mode,
                                    GLsizei count,
                                    DrawElementsType type,
                                    const void *indices,
                                    GLint basevertex)
{
    return ValidateDrawElementsCommon(context, entryPoint, mode, count, type, indices, 1);
}

bool ValidateDrawElementsInstancedBaseVertex(const Context *context,
                                             angle::EntryPoint entryPoint,
                                             PrimitiveMode mode,
                                             GLsizei count,
                                             DrawElementsType type,
                                             const void *indices,
                                             GLsizei instancecount,
                                             GLint basevertex)
{
    return ValidateDrawElementsInstancedBase(context, entryPoint, mode, count, type, indices,
                                             instancecount, 0);
}

bool ValidateDrawRangeElementsBaseVertex(const Context *context,
                                         angle::EntryPoint entryPoint,
                                         PrimitiveMode mode,
                                         GLuint start,
                                         GLuint end,
                                         GLsizei count,
                                         DrawElementsType type,
                                         const void *indices,
                                         GLint basevertex)
{
    if (end < start)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_VALUE, kInvalidElementRange);
        return false;
    }

    if (!ValidateDrawElementsCommon(context, entryPoint, mode, count, type, indices, 1))
    {
        return false;
    }

    // Skip range checks for no-op calls.
    if (count <= 0)
    {
        return true;
    }

    return true;
}

bool ValidateEnablei(const PrivateState &state,
                     ErrorSet *errors,
                     angle::EntryPoint entryPoint,
                     GLenum target,
                     GLuint index)
{
    int numPLSPlanes = state.getPixelLocalStorageActivePlanes();
    if (numPLSPlanes != 0)
    {
        if (IsIndexedCapBannedWithActivePLS(target))
        {
            errors->validationErrorF(entryPoint, GL_INVALID_OPERATION, kPLSCapNotAllowed, target);
            return false;
        }
    }

    switch (target)
    {
        case GL_BLEND:
            if (index >= static_cast<GLuint>(state.getCaps().maxDrawBuffers))
            {
                errors->validationError(entryPoint, GL_INVALID_VALUE, kIndexExceedsMaxDrawBuffer);
                return false;
            }
            break;
        default:
            errors->validationErrorF(entryPoint, GL_INVALID_ENUM, kEnumNotSupported, target);
            return false;
    }
    return true;
}

bool ValidateFramebufferTexture(const Context *context,
                                angle::EntryPoint entryPoint,
                                GLenum target,
                                GLenum attachment,
                                TextureID texture,
                                GLint level)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    return ValidateFramebufferTextureCommon(context, entryPoint, target, attachment, texture,
                                            level);
}

bool ValidateGetDebugMessageLog(const Context *context,
                                angle::EntryPoint entryPoint,
                                GLuint count,
                                GLsizei bufSize,
                                const GLenum *sources,
                                const GLenum *types,
                                const GLuint *ids,
                                const GLenum *severities,
                                const GLsizei *lengths,
                                const GLchar *messageLog)
{
    return true;
}

bool ValidateGetGraphicsResetStatus(const Context *context, angle::EntryPoint entryPoint)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    return true;
}

bool ValidateGetObjectLabel(const Context *context,
                            angle::EntryPoint entryPoint,
                            GLenum identifier,
                            GLuint name,
                            GLsizei bufSize,
                            const GLsizei *length,
                            const GLchar *label)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    if (!ValidateGetObjectLabelBase(context, entryPoint, identifier, name, bufSize, length, label))
    {
        return false;
    }

    return true;
}

bool ValidateGetObjectPtrLabel(const Context *context,
                               angle::EntryPoint entryPoint,
                               const void *ptr,
                               GLsizei bufSize,
                               const GLsizei *length,
                               const GLchar *label)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    if (!ValidateGetObjectPtrLabelBase(context, entryPoint, ptr, bufSize, length, label))
    {
        return false;
    }

    return true;
}

bool ValidateGetPointerv(const Context *context,
                         angle::EntryPoint entryPoint,
                         GLenum pname,
                         void *const *params)
{
    switch (pname)
    {
        case GL_VERTEX_ARRAY_POINTER:
        case GL_NORMAL_ARRAY_POINTER:
        case GL_COLOR_ARRAY_POINTER:
        case GL_TEXTURE_COORD_ARRAY_POINTER:
        case GL_POINT_SIZE_ARRAY_POINTER_OES:
            if (context->getClientMajorVersion() != 1)
            {
                ANGLE_VALIDATION_ERROR(GL_INVALID_ENUM, kInvalidPointerQuery);
                return false;
            }
            break;

        case GL_DEBUG_CALLBACK_FUNCTION:
        case GL_DEBUG_CALLBACK_USER_PARAM:
            if (!context->getExtensions().debugKHR)
            {
                ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kExtensionNotEnabled);
                return false;
            }
            break;

        case GL_BLOB_CACHE_GET_FUNCTION_ANGLE:
        case GL_BLOB_CACHE_SET_FUNCTION_ANGLE:
        case GL_BLOB_CACHE_USER_PARAM_ANGLE:
            if (!context->getExtensions().blobCacheANGLE)
            {
                ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kExtensionNotEnabled);
                return false;
            }
            break;

        default:
            ANGLE_VALIDATION_ERROR(GL_INVALID_ENUM, kInvalidPointerQuery);
            return false;
    }

    return true;
}

bool ValidateGetSamplerParameterIiv(const Context *context,
                                    angle::EntryPoint entryPoint,
                                    SamplerID sampler,
                                    GLenum pname,
                                    const GLint *params)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }
    return ValidateGetSamplerParameterBase(context, entryPoint, sampler, pname, nullptr);
}

bool ValidateGetSamplerParameterIuiv(const Context *context,
                                     angle::EntryPoint entryPoint,
                                     SamplerID sampler,
                                     GLenum pname,
                                     const GLuint *params)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }
    return ValidateGetSamplerParameterBase(context, entryPoint, sampler, pname, nullptr);
}

bool ValidateGetTexParameterIiv(const Context *context,
                                angle::EntryPoint entryPoint,
                                TextureType targetPacked,
                                GLenum pname,
                                const GLint *params)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }
    return ValidateGetTexParameterBase(context, entryPoint, targetPacked, pname, nullptr);
}

bool ValidateGetTexParameterIuiv(const Context *context,
                                 angle::EntryPoint entryPoint,
                                 TextureType targetPacked,
                                 GLenum pname,
                                 const GLuint *params)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }
    return ValidateGetTexParameterBase(context, entryPoint, targetPacked, pname, nullptr);
}

bool ValidateGetnUniformfv(const Context *context,
                           angle::EntryPoint entryPoint,
                           ShaderProgramID program,
                           UniformLocation location,
                           GLsizei bufSize,
                           const GLfloat *params)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    return ValidateSizedGetUniform(context, entryPoint, program, location, bufSize, nullptr);
}

bool ValidateGetnUniformiv(const Context *context,
                           angle::EntryPoint entryPoint,
                           ShaderProgramID program,
                           UniformLocation location,
                           GLsizei bufSize,
                           const GLint *params)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    return ValidateSizedGetUniform(context, entryPoint, program, location, bufSize, nullptr);
}

bool ValidateGetnUniformuiv(const Context *context,
                            angle::EntryPoint entryPoint,
                            ShaderProgramID program,
                            UniformLocation location,
                            GLsizei bufSize,
                            const GLuint *params)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    return ValidateSizedGetUniform(context, entryPoint, program, location, bufSize, nullptr);
}

bool ValidateIsEnabledi(const PrivateState &state,
                        ErrorSet *errors,
                        angle::EntryPoint entryPoint,
                        GLenum target,
                        GLuint index)
{
    switch (target)
    {
        case GL_BLEND:
            if (index >= static_cast<GLuint>(state.getCaps().maxDrawBuffers))
            {
                errors->validationError(entryPoint, GL_INVALID_VALUE, kIndexExceedsMaxDrawBuffer);
                return false;
            }
            break;
        default:
            errors->validationErrorF(entryPoint, GL_INVALID_ENUM, kEnumNotSupported, target);
            return false;
    }
    return true;
}

bool ValidateMinSampleShading(const PrivateState &state,
                              ErrorSet *errors,
                              angle::EntryPoint entryPoint,
                              GLfloat value)
{
    return true;
}

bool ValidateObjectLabel(const Context *context,
                         angle::EntryPoint entryPoint,
                         GLenum identifier,
                         GLuint name,
                         GLsizei length,
                         const GLchar *label)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    if (!ValidateObjectLabelBase(context, entryPoint, identifier, name, length, label))
    {
        return false;
    }

    return true;
}

bool ValidateObjectPtrLabel(const Context *context,
                            angle::EntryPoint entryPoint,
                            const void *ptr,
                            GLsizei length,
                            const GLchar *label)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    if (!ValidateObjectPtrLabelBase(context, entryPoint, ptr, length, label))
    {
        return false;
    }

    return true;
}

bool ValidatePatchParameteri(const PrivateState &state,
                             ErrorSet *errors,
                             angle::EntryPoint entryPoint,
                             GLenum pname,
                             GLint value)
{
    if (state.getClientVersion() < ES_3_2)
    {
        errors->validationError(entryPoint, GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    return ValidatePatchParameteriBase(state, errors, entryPoint, pname, value);
}

bool ValidatePopDebugGroup(const Context *context, angle::EntryPoint entryPoint)
{
    return ValidatePopDebugGroupBase(context, entryPoint);
}

bool ValidatePrimitiveBoundingBox(const PrivateState &state,
                                  ErrorSet *errors,
                                  angle::EntryPoint entryPoint,
                                  GLfloat minX,
                                  GLfloat minY,
                                  GLfloat minZ,
                                  GLfloat minW,
                                  GLfloat maxX,
                                  GLfloat maxY,
                                  GLfloat maxZ,
                                  GLfloat maxW)
{
    return true;
}

bool ValidatePushDebugGroup(const Context *context,
                            angle::EntryPoint entryPoint,
                            GLenum source,
                            GLuint id,
                            GLsizei length,
                            const GLchar *message)
{
    return ValidatePushDebugGroupBase(context, entryPoint, source, id, length, message);
}

bool ValidateReadnPixels(const Context *context,
                         angle::EntryPoint entryPoint,
                         GLint x,
                         GLint y,
                         GLsizei width,
                         GLsizei height,
                         GLenum format,
                         GLenum type,
                         GLsizei bufSize,
                         const void *data)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    if (bufSize < 0)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_VALUE, kNegativeBufSize);
        return false;
    }

    return ValidateReadPixelsBase(context, entryPoint, x, y, width, height, format, type, bufSize,
                                  nullptr, nullptr, nullptr, data);
}

bool ValidateSamplerParameterIiv(const Context *context,
                                 angle::EntryPoint entryPoint,
                                 SamplerID sampler,
                                 GLenum pname,
                                 const GLint *param)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }
    return ValidateSamplerParameterBase(context, entryPoint, sampler, pname, -1, true, param);
}

bool ValidateSamplerParameterIuiv(const Context *context,
                                  angle::EntryPoint entryPoint,
                                  SamplerID sampler,
                                  GLenum pname,
                                  const GLuint *param)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }
    return ValidateSamplerParameterBase(context, entryPoint, sampler, pname, -1, true, param);
}

bool ValidateTexBuffer(const Context *context,
                       angle::EntryPoint entryPoint,
                       TextureType target,
                       GLenum internalformat,
                       BufferID buffer)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    return ValidateTexBufferBase(context, entryPoint, target, internalformat, buffer);
}

bool ValidateTexBufferRange(const Context *context,
                            angle::EntryPoint entryPoint,
                            TextureType target,
                            GLenum internalformat,
                            BufferID buffer,
                            GLintptr offset,
                            GLsizeiptr size)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }

    return ValidateTexBufferRangeBase(context, entryPoint, target, internalformat, buffer, offset,
                                      size);
}

bool ValidateTexParameterIiv(const Context *context,
                             angle::EntryPoint entryPoint,
                             TextureType targetPacked,
                             GLenum pname,
                             const GLint *params)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }
    return ValidateTexParameterBase(context, entryPoint, targetPacked, pname, -1, true, params);
}

bool ValidateTexParameterIuiv(const Context *context,
                              angle::EntryPoint entryPoint,
                              TextureType targetPacked,
                              GLenum pname,
                              const GLuint *params)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }
    return ValidateTexParameterBase(context, entryPoint, targetPacked, pname, -1, true, params);
}

bool ValidateTexStorage3DMultisample(const Context *context,
                                     angle::EntryPoint entryPoint,
                                     TextureType targetPacked,
                                     GLsizei samples,
                                     GLenum internalformat,
                                     GLsizei width,
                                     GLsizei height,
                                     GLsizei depth,
                                     GLboolean fixedsamplelocations)
{
    if (context->getClientVersion() < ES_3_2)
    {
        ANGLE_VALIDATION_ERROR(GL_INVALID_OPERATION, kES32Required);
        return false;
    }
    return ValidateTexStorage3DMultisampleBase(context, entryPoint, targetPacked, samples,
                                               internalformat, width, height, depth);
}

}  // namespace gl
