// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from gl.xml.
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// entry_points_gl_3_autogen.h:
//   Defines the Desktop GL 3.x entry points.

#ifndef LIBGLESV2_ENTRY_POINTS_GL_3_AUTOGEN_H_
#define LIBGLESV2_ENTRY_POINTS_GL_3_AUTOGEN_H_

#include <export.h>
#include "angle_gl.h"

extern "C" {

// GL 3.0
ANGLE_EXPORT void GL_APIENTRY GL_BeginConditionalRender(GLuint id, GLenum mode);
ANGLE_EXPORT void GL_APIENTRY GL_BindFragDataLocation(GLuint program,
                                                      GLuint color,
                                                      const GLchar *name);
ANGLE_EXPORT void GL_APIENTRY GL_ClampColor(GLenum target, GLenum clamp);
ANGLE_EXPORT void GL_APIENTRY GL_EndConditionalRender();
ANGLE_EXPORT void GL_APIENTRY GL_FramebufferTexture1D(GLenum target,
                                                      GLenum attachment,
                                                      GLenum textarget,
                                                      GLuint texture,
                                                      GLint level);
ANGLE_EXPORT void GL_APIENTRY GL_FramebufferTexture3D(GLenum target,
                                                      GLenum attachment,
                                                      GLenum textarget,
                                                      GLuint texture,
                                                      GLint level,
                                                      GLint zoffset);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI1i(GLuint index, GLint x);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI1iv(GLuint index, const GLint *v);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI1ui(GLuint index, GLuint x);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI1uiv(GLuint index, const GLuint *v);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI2i(GLuint index, GLint x, GLint y);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI2iv(GLuint index, const GLint *v);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI2ui(GLuint index, GLuint x, GLuint y);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI2uiv(GLuint index, const GLuint *v);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI3iv(GLuint index, const GLint *v);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI3uiv(GLuint index, const GLuint *v);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI4bv(GLuint index, const GLbyte *v);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI4sv(GLuint index, const GLshort *v);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI4ubv(GLuint index, const GLubyte *v);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribI4usv(GLuint index, const GLushort *v);

// GL 3.1
ANGLE_EXPORT void GL_APIENTRY GL_GetActiveUniformName(GLuint program,
                                                      GLuint uniformIndex,
                                                      GLsizei bufSize,
                                                      GLsizei *length,
                                                      GLchar *uniformName);
ANGLE_EXPORT void GL_APIENTRY GL_PrimitiveRestartIndex(GLuint index);

// GL 3.2
ANGLE_EXPORT void GL_APIENTRY GL_MultiDrawElementsBaseVertex(GLenum mode,
                                                             const GLsizei *count,
                                                             GLenum type,
                                                             const void *const *indices,
                                                             GLsizei drawcount,
                                                             const GLint *basevertex);
ANGLE_EXPORT void GL_APIENTRY GL_ProvokingVertex(GLenum mode);
ANGLE_EXPORT void GL_APIENTRY GL_TexImage2DMultisample(GLenum target,
                                                       GLsizei samples,
                                                       GLenum internalformat,
                                                       GLsizei width,
                                                       GLsizei height,
                                                       GLboolean fixedsamplelocations);
ANGLE_EXPORT void GL_APIENTRY GL_TexImage3DMultisample(GLenum target,
                                                       GLsizei samples,
                                                       GLenum internalformat,
                                                       GLsizei width,
                                                       GLsizei height,
                                                       GLsizei depth,
                                                       GLboolean fixedsamplelocations);

// GL 3.3
ANGLE_EXPORT void GL_APIENTRY GL_BindFragDataLocationIndexed(GLuint program,
                                                             GLuint colorNumber,
                                                             GLuint index,
                                                             const GLchar *name);
ANGLE_EXPORT void GL_APIENTRY GL_ColorP3ui(GLenum type, GLuint color);
ANGLE_EXPORT void GL_APIENTRY GL_ColorP3uiv(GLenum type, const GLuint *color);
ANGLE_EXPORT void GL_APIENTRY GL_ColorP4ui(GLenum type, GLuint color);
ANGLE_EXPORT void GL_APIENTRY GL_ColorP4uiv(GLenum type, const GLuint *color);
ANGLE_EXPORT GLint GL_APIENTRY GL_GetFragDataIndex(GLuint program, const GLchar *name);
ANGLE_EXPORT void GL_APIENTRY GL_GetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params);
ANGLE_EXPORT void GL_APIENTRY GL_GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params);
ANGLE_EXPORT void GL_APIENTRY GL_MultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY GL_MultiTexCoordP1uiv(GLenum texture,
                                                    GLenum type,
                                                    const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY GL_MultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY GL_MultiTexCoordP2uiv(GLenum texture,
                                                    GLenum type,
                                                    const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY GL_MultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY GL_MultiTexCoordP3uiv(GLenum texture,
                                                    GLenum type,
                                                    const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY GL_MultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY GL_MultiTexCoordP4uiv(GLenum texture,
                                                    GLenum type,
                                                    const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY GL_NormalP3ui(GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY GL_NormalP3uiv(GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY GL_QueryCounter(GLuint id, GLenum target);
ANGLE_EXPORT void GL_APIENTRY GL_SecondaryColorP3ui(GLenum type, GLuint color);
ANGLE_EXPORT void GL_APIENTRY GL_SecondaryColorP3uiv(GLenum type, const GLuint *color);
ANGLE_EXPORT void GL_APIENTRY GL_TexCoordP1ui(GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY GL_TexCoordP1uiv(GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY GL_TexCoordP2ui(GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY GL_TexCoordP2uiv(GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY GL_TexCoordP3ui(GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY GL_TexCoordP3uiv(GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY GL_TexCoordP4ui(GLenum type, GLuint coords);
ANGLE_EXPORT void GL_APIENTRY GL_TexCoordP4uiv(GLenum type, const GLuint *coords);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribP1ui(GLuint index,
                                                  GLenum type,
                                                  GLboolean normalized,
                                                  GLuint value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribP1uiv(GLuint index,
                                                   GLenum type,
                                                   GLboolean normalized,
                                                   const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribP2ui(GLuint index,
                                                  GLenum type,
                                                  GLboolean normalized,
                                                  GLuint value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribP2uiv(GLuint index,
                                                   GLenum type,
                                                   GLboolean normalized,
                                                   const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribP3ui(GLuint index,
                                                  GLenum type,
                                                  GLboolean normalized,
                                                  GLuint value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribP3uiv(GLuint index,
                                                   GLenum type,
                                                   GLboolean normalized,
                                                   const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribP4ui(GLuint index,
                                                  GLenum type,
                                                  GLboolean normalized,
                                                  GLuint value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexAttribP4uiv(GLuint index,
                                                   GLenum type,
                                                   GLboolean normalized,
                                                   const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexP2ui(GLenum type, GLuint value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexP2uiv(GLenum type, const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexP3ui(GLenum type, GLuint value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexP3uiv(GLenum type, const GLuint *value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexP4ui(GLenum type, GLuint value);
ANGLE_EXPORT void GL_APIENTRY GL_VertexP4uiv(GLenum type, const GLuint *value);
}  // extern "C"

#endif  // LIBGLESV2_ENTRY_POINTS_GL_3_AUTOGEN_H_
