// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from gl.xml and gl_angle_ext.xml.
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// validationES3_autogen.h:
//   Validation functions for the OpenGL ES 3.0 entry points.

#ifndef LIBANGLE_VALIDATION_ES3_AUTOGEN_H_
#define LIBANGLE_VALIDATION_ES3_AUTOGEN_H_

#include "common/PackedEnums.h"

namespace gl
{
class Context;

bool ValidateBeginQuery(const Context *context, QueryType targetPacked, QueryID idPacked);
bool ValidateBeginTransformFeedback(const Context *context, PrimitiveMode primitiveModePacked);
bool ValidateBindBufferBase(const Context *context,
                            BufferBinding targetPacked,
                            GLuint index,
                            BufferID bufferPacked);
bool ValidateBindBufferRange(const Context *context,
                             BufferBinding targetPacked,
                             GLuint index,
                             BufferID bufferPacked,
                             GLintptr offset,
                             GLsizeiptr size);
bool ValidateBindSampler(const Context *context, GLuint unit, SamplerID samplerPacked);
bool ValidateBindTransformFeedback(const Context *context,
                                   GLenum target,
                                   TransformFeedbackID idPacked);
bool ValidateBindVertexArray(const Context *context, VertexArrayID arrayPacked);
bool ValidateBlitFramebuffer(const Context *context,
                             GLint srcX0,
                             GLint srcY0,
                             GLint srcX1,
                             GLint srcY1,
                             GLint dstX0,
                             GLint dstY0,
                             GLint dstX1,
                             GLint dstY1,
                             GLbitfield mask,
                             GLenum filter);
bool ValidateClearBufferfi(const Context *context,
                           GLenum buffer,
                           GLint drawbuffer,
                           GLfloat depth,
                           GLint stencil);
bool ValidateClearBufferfv(const Context *context,
                           GLenum buffer,
                           GLint drawbuffer,
                           const GLfloat *value);
bool ValidateClearBufferiv(const Context *context,
                           GLenum buffer,
                           GLint drawbuffer,
                           const GLint *value);
bool ValidateClearBufferuiv(const Context *context,
                            GLenum buffer,
                            GLint drawbuffer,
                            const GLuint *value);
bool ValidateClientWaitSync(const Context *context,
                            GLsync sync,
                            GLbitfield flags,
                            GLuint64 timeout);
bool ValidateCompressedTexImage3D(const Context *context,
                                  TextureTarget targetPacked,
                                  GLint level,
                                  GLenum internalformat,
                                  GLsizei width,
                                  GLsizei height,
                                  GLsizei depth,
                                  GLint border,
                                  GLsizei imageSize,
                                  const void *data);
bool ValidateCompressedTexSubImage3D(const Context *context,
                                     TextureTarget targetPacked,
                                     GLint level,
                                     GLint xoffset,
                                     GLint yoffset,
                                     GLint zoffset,
                                     GLsizei width,
                                     GLsizei height,
                                     GLsizei depth,
                                     GLenum format,
                                     GLsizei imageSize,
                                     const void *data);
bool ValidateCopyBufferSubData(const Context *context,
                               BufferBinding readTargetPacked,
                               BufferBinding writeTargetPacked,
                               GLintptr readOffset,
                               GLintptr writeOffset,
                               GLsizeiptr size);
bool ValidateCopyTexSubImage3D(const Context *context,
                               TextureTarget targetPacked,
                               GLint level,
                               GLint xoffset,
                               GLint yoffset,
                               GLint zoffset,
                               GLint x,
                               GLint y,
                               GLsizei width,
                               GLsizei height);
bool ValidateDeleteQueries(const Context *context, GLsizei n, const QueryID *idsPacked);
bool ValidateDeleteSamplers(const Context *context, GLsizei count, const SamplerID *samplersPacked);
bool ValidateDeleteSync(const Context *context, GLsync sync);
bool ValidateDeleteTransformFeedbacks(const Context *context,
                                      GLsizei n,
                                      const TransformFeedbackID *idsPacked);
bool ValidateDeleteVertexArrays(const Context *context,
                                GLsizei n,
                                const VertexArrayID *arraysPacked);
bool ValidateDrawArraysInstanced(const Context *context,
                                 PrimitiveMode modePacked,
                                 GLint first,
                                 GLsizei count,
                                 GLsizei instancecount);
bool ValidateDrawBuffers(const Context *context, GLsizei n, const GLenum *bufs);
bool ValidateDrawElementsInstanced(const Context *context,
                                   PrimitiveMode modePacked,
                                   GLsizei count,
                                   DrawElementsType typePacked,
                                   const void *indices,
                                   GLsizei instancecount);
bool ValidateDrawRangeElements(const Context *context,
                               PrimitiveMode modePacked,
                               GLuint start,
                               GLuint end,
                               GLsizei count,
                               DrawElementsType typePacked,
                               const void *indices);
bool ValidateEndQuery(const Context *context, QueryType targetPacked);
bool ValidateEndTransformFeedback(const Context *context);
bool ValidateFenceSync(const Context *context, GLenum condition, GLbitfield flags);
bool ValidateFlushMappedBufferRange(const Context *context,
                                    BufferBinding targetPacked,
                                    GLintptr offset,
                                    GLsizeiptr length);
bool ValidateFramebufferTextureLayer(const Context *context,
                                     GLenum target,
                                     GLenum attachment,
                                     TextureID texturePacked,
                                     GLint level,
                                     GLint layer);
bool ValidateGenQueries(const Context *context, GLsizei n, const QueryID *idsPacked);
bool ValidateGenSamplers(const Context *context, GLsizei count, const SamplerID *samplersPacked);
bool ValidateGenTransformFeedbacks(const Context *context,
                                   GLsizei n,
                                   const TransformFeedbackID *idsPacked);
bool ValidateGenVertexArrays(const Context *context, GLsizei n, const VertexArrayID *arraysPacked);
bool ValidateGetActiveUniformBlockName(const Context *context,
                                       ShaderProgramID programPacked,
                                       UniformBlockIndex uniformBlockIndexPacked,
                                       GLsizei bufSize,
                                       const GLsizei *length,
                                       const GLchar *uniformBlockName);
bool ValidateGetActiveUniformBlockiv(const Context *context,
                                     ShaderProgramID programPacked,
                                     UniformBlockIndex uniformBlockIndexPacked,
                                     GLenum pname,
                                     const GLint *params);
bool ValidateGetActiveUniformsiv(const Context *context,
                                 ShaderProgramID programPacked,
                                 GLsizei uniformCount,
                                 const GLuint *uniformIndices,
                                 GLenum pname,
                                 const GLint *params);
bool ValidateGetBufferParameteri64v(const Context *context,
                                    BufferBinding targetPacked,
                                    GLenum pname,
                                    const GLint64 *params);
bool ValidateGetBufferPointerv(const Context *context,
                               BufferBinding targetPacked,
                               GLenum pname,
                               void *const *params);
bool ValidateGetFragDataLocation(const Context *context,
                                 ShaderProgramID programPacked,
                                 const GLchar *name);
bool ValidateGetInteger64i_v(const Context *context,
                             GLenum target,
                             GLuint index,
                             const GLint64 *data);
bool ValidateGetInteger64v(const Context *context, GLenum pname, const GLint64 *data);
bool ValidateGetIntegeri_v(const Context *context, GLenum target, GLuint index, const GLint *data);
bool ValidateGetInternalformativ(const Context *context,
                                 GLenum target,
                                 GLenum internalformat,
                                 GLenum pname,
                                 GLsizei bufSize,
                                 const GLint *params);
bool ValidateGetProgramBinary(const Context *context,
                              ShaderProgramID programPacked,
                              GLsizei bufSize,
                              const GLsizei *length,
                              const GLenum *binaryFormat,
                              const void *binary);
bool ValidateGetQueryObjectuiv(const Context *context,
                               QueryID idPacked,
                               GLenum pname,
                               const GLuint *params);
bool ValidateGetQueryiv(const Context *context,
                        QueryType targetPacked,
                        GLenum pname,
                        const GLint *params);
bool ValidateGetSamplerParameterfv(const Context *context,
                                   SamplerID samplerPacked,
                                   GLenum pname,
                                   const GLfloat *params);
bool ValidateGetSamplerParameteriv(const Context *context,
                                   SamplerID samplerPacked,
                                   GLenum pname,
                                   const GLint *params);
bool ValidateGetStringi(const Context *context, GLenum name, GLuint index);
bool ValidateGetSynciv(const Context *context,
                       GLsync sync,
                       GLenum pname,
                       GLsizei bufSize,
                       const GLsizei *length,
                       const GLint *values);
bool ValidateGetTransformFeedbackVarying(const Context *context,
                                         ShaderProgramID programPacked,
                                         GLuint index,
                                         GLsizei bufSize,
                                         const GLsizei *length,
                                         const GLsizei *size,
                                         const GLenum *type,
                                         const GLchar *name);
bool ValidateGetUniformBlockIndex(const Context *context,
                                  ShaderProgramID programPacked,
                                  const GLchar *uniformBlockName);
bool ValidateGetUniformIndices(const Context *context,
                               ShaderProgramID programPacked,
                               GLsizei uniformCount,
                               const GLchar *const *uniformNames,
                               const GLuint *uniformIndices);
bool ValidateGetUniformuiv(const Context *context,
                           ShaderProgramID programPacked,
                           UniformLocation locationPacked,
                           const GLuint *params);
bool ValidateGetVertexAttribIiv(const Context *context,
                                GLuint index,
                                GLenum pname,
                                const GLint *params);
bool ValidateGetVertexAttribIuiv(const Context *context,
                                 GLuint index,
                                 GLenum pname,
                                 const GLuint *params);
bool ValidateInvalidateFramebuffer(const Context *context,
                                   GLenum target,
                                   GLsizei numAttachments,
                                   const GLenum *attachments);
bool ValidateInvalidateSubFramebuffer(const Context *context,
                                      GLenum target,
                                      GLsizei numAttachments,
                                      const GLenum *attachments,
                                      GLint x,
                                      GLint y,
                                      GLsizei width,
                                      GLsizei height);
bool ValidateIsQuery(const Context *context, QueryID idPacked);
bool ValidateIsSampler(const Context *context, SamplerID samplerPacked);
bool ValidateIsSync(const Context *context, GLsync sync);
bool ValidateIsTransformFeedback(const Context *context, TransformFeedbackID idPacked);
bool ValidateIsVertexArray(const Context *context, VertexArrayID arrayPacked);
bool ValidateMapBufferRange(const Context *context,
                            BufferBinding targetPacked,
                            GLintptr offset,
                            GLsizeiptr length,
                            GLbitfield access);
bool ValidatePauseTransformFeedback(const Context *context);
bool ValidateProgramBinary(const Context *context,
                           ShaderProgramID programPacked,
                           GLenum binaryFormat,
                           const void *binary,
                           GLsizei length);
bool ValidateProgramParameteri(const Context *context,
                               ShaderProgramID programPacked,
                               GLenum pname,
                               GLint value);
bool ValidateReadBuffer(const Context *context, GLenum src);
bool ValidateRenderbufferStorageMultisample(const Context *context,
                                            GLenum target,
                                            GLsizei samples,
                                            GLenum internalformat,
                                            GLsizei width,
                                            GLsizei height);
bool ValidateResumeTransformFeedback(const Context *context);
bool ValidateSamplerParameterf(const Context *context,
                               SamplerID samplerPacked,
                               GLenum pname,
                               GLfloat param);
bool ValidateSamplerParameterfv(const Context *context,
                                SamplerID samplerPacked,
                                GLenum pname,
                                const GLfloat *param);
bool ValidateSamplerParameteri(const Context *context,
                               SamplerID samplerPacked,
                               GLenum pname,
                               GLint param);
bool ValidateSamplerParameteriv(const Context *context,
                                SamplerID samplerPacked,
                                GLenum pname,
                                const GLint *param);
bool ValidateTexImage3D(const Context *context,
                        TextureTarget targetPacked,
                        GLint level,
                        GLint internalformat,
                        GLsizei width,
                        GLsizei height,
                        GLsizei depth,
                        GLint border,
                        GLenum format,
                        GLenum type,
                        const void *pixels);
bool ValidateTexStorage2D(const Context *context,
                          TextureType targetPacked,
                          GLsizei levels,
                          GLenum internalformat,
                          GLsizei width,
                          GLsizei height);
bool ValidateTexStorage3D(const Context *context,
                          TextureType targetPacked,
                          GLsizei levels,
                          GLenum internalformat,
                          GLsizei width,
                          GLsizei height,
                          GLsizei depth);
bool ValidateTexSubImage3D(const Context *context,
                           TextureTarget targetPacked,
                           GLint level,
                           GLint xoffset,
                           GLint yoffset,
                           GLint zoffset,
                           GLsizei width,
                           GLsizei height,
                           GLsizei depth,
                           GLenum format,
                           GLenum type,
                           const void *pixels);
bool ValidateTransformFeedbackVaryings(const Context *context,
                                       ShaderProgramID programPacked,
                                       GLsizei count,
                                       const GLchar *const *varyings,
                                       GLenum bufferMode);
bool ValidateUniform1ui(const Context *context, UniformLocation locationPacked, GLuint v0);
bool ValidateUniform1uiv(const Context *context,
                         UniformLocation locationPacked,
                         GLsizei count,
                         const GLuint *value);
bool ValidateUniform2ui(const Context *context,
                        UniformLocation locationPacked,
                        GLuint v0,
                        GLuint v1);
bool ValidateUniform2uiv(const Context *context,
                         UniformLocation locationPacked,
                         GLsizei count,
                         const GLuint *value);
bool ValidateUniform3ui(const Context *context,
                        UniformLocation locationPacked,
                        GLuint v0,
                        GLuint v1,
                        GLuint v2);
bool ValidateUniform3uiv(const Context *context,
                         UniformLocation locationPacked,
                         GLsizei count,
                         const GLuint *value);
bool ValidateUniform4ui(const Context *context,
                        UniformLocation locationPacked,
                        GLuint v0,
                        GLuint v1,
                        GLuint v2,
                        GLuint v3);
bool ValidateUniform4uiv(const Context *context,
                         UniformLocation locationPacked,
                         GLsizei count,
                         const GLuint *value);
bool ValidateUniformBlockBinding(const Context *context,
                                 ShaderProgramID programPacked,
                                 UniformBlockIndex uniformBlockIndexPacked,
                                 GLuint uniformBlockBinding);
bool ValidateUniformMatrix2x3fv(const Context *context,
                                UniformLocation locationPacked,
                                GLsizei count,
                                GLboolean transpose,
                                const GLfloat *value);
bool ValidateUniformMatrix2x4fv(const Context *context,
                                UniformLocation locationPacked,
                                GLsizei count,
                                GLboolean transpose,
                                const GLfloat *value);
bool ValidateUniformMatrix3x2fv(const Context *context,
                                UniformLocation locationPacked,
                                GLsizei count,
                                GLboolean transpose,
                                const GLfloat *value);
bool ValidateUniformMatrix3x4fv(const Context *context,
                                UniformLocation locationPacked,
                                GLsizei count,
                                GLboolean transpose,
                                const GLfloat *value);
bool ValidateUniformMatrix4x2fv(const Context *context,
                                UniformLocation locationPacked,
                                GLsizei count,
                                GLboolean transpose,
                                const GLfloat *value);
bool ValidateUniformMatrix4x3fv(const Context *context,
                                UniformLocation locationPacked,
                                GLsizei count,
                                GLboolean transpose,
                                const GLfloat *value);
bool ValidateUnmapBuffer(const Context *context, BufferBinding targetPacked);
bool ValidateVertexAttribDivisor(const Context *context, GLuint index, GLuint divisor);
bool ValidateVertexAttribI4i(const Context *context,
                             GLuint index,
                             GLint x,
                             GLint y,
                             GLint z,
                             GLint w);
bool ValidateVertexAttribI4iv(const Context *context, GLuint index, const GLint *v);
bool ValidateVertexAttribI4ui(const Context *context,
                              GLuint index,
                              GLuint x,
                              GLuint y,
                              GLuint z,
                              GLuint w);
bool ValidateVertexAttribI4uiv(const Context *context, GLuint index, const GLuint *v);
bool ValidateVertexAttribIPointer(const Context *context,
                                  GLuint index,
                                  GLint size,
                                  VertexAttribType typePacked,
                                  GLsizei stride,
                                  const void *pointer);
bool ValidateWaitSync(const Context *context, GLsync sync, GLbitfield flags, GLuint64 timeout);
}  // namespace gl

#endif  // LIBANGLE_VALIDATION_ES3_AUTOGEN_H_
