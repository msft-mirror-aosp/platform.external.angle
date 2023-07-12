//
// Copyright 2023 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// context_local_call_gles.cpp:
//   Helpers that set/get state that is entirely locally accessed by the context.

#include "libANGLE/context_local_call_gles_autogen.h"

#include "libANGLE/queryconversions.h"

namespace gl
{
void ContextLocalClearColor(Context *context,
                            GLfloat red,
                            GLfloat green,
                            GLfloat blue,
                            GLfloat alpha)
{
    context->getMutableLocalState()->setColorClearValue(red, green, blue, alpha);
}

void ContextLocalClearDepthf(Context *context, GLfloat depth)
{
    context->getMutableLocalState()->setDepthClearValue(clamp01(depth));
}

void ContextLocalClearStencil(Context *context, GLint stencil)
{
    context->getMutableLocalState()->setStencilClearValue(stencil);
}

void ContextLocalClearColorx(Context *context,
                             GLfixed red,
                             GLfixed green,
                             GLfixed blue,
                             GLfixed alpha)
{
    context->getMutableLocalState()->setColorClearValue(
        ConvertFixedToFloat(red), ConvertFixedToFloat(green), ConvertFixedToFloat(blue),
        ConvertFixedToFloat(alpha));
}

void ContextLocalClearDepthx(Context *context, GLfixed depth)
{
    context->getMutableLocalState()->setDepthClearValue(clamp01(ConvertFixedToFloat(depth)));
}

void ContextLocalColorMask(Context *context,
                           GLboolean red,
                           GLboolean green,
                           GLboolean blue,
                           GLboolean alpha)
{
    context->getMutableLocalState()->setColorMask(ConvertToBool(red), ConvertToBool(green),
                                                  ConvertToBool(blue), ConvertToBool(alpha));
    context->onContextLocalColorMaskChange();
}

void ContextLocalColorMaski(Context *context,
                            GLuint index,
                            GLboolean r,
                            GLboolean g,
                            GLboolean b,
                            GLboolean a)
{
    context->getMutableLocalState()->setColorMaskIndexed(ConvertToBool(r), ConvertToBool(g),
                                                         ConvertToBool(b), ConvertToBool(a), index);
    context->onContextLocalColorMaskChange();
}

void ContextLocalDepthMask(Context *context, GLboolean flag)
{
    context->getMutableLocalState()->setDepthMask(ConvertToBool(flag));
}

void ContextLocalDisable(Context *context, GLenum cap)
{
    context->getMutableLocalState()->setEnableFeature(cap, false);
    context->onContextLocalCapChange();
}

void ContextLocalDisablei(Context *context, GLenum target, GLuint index)
{
    context->getMutableLocalState()->setEnableFeatureIndexed(target, false, index);
    context->onContextLocalCapChange();
}

void ContextLocalEnable(Context *context, GLenum cap)
{
    context->getMutableLocalState()->setEnableFeature(cap, true);
    context->onContextLocalCapChange();
}

void ContextLocalEnablei(Context *context, GLenum target, GLuint index)
{
    context->getMutableLocalState()->setEnableFeatureIndexed(target, true, index);
    context->onContextLocalCapChange();
}

void ContextLocalActiveTexture(Context *context, GLenum texture)
{
    context->getMutableLocalState()->setActiveSampler(texture - GL_TEXTURE0);
}

void ContextLocalCullFace(Context *context, CullFaceMode mode)
{
    context->getMutableLocalState()->setCullMode(mode);
}

void ContextLocalDepthFunc(Context *context, GLenum func)
{
    context->getMutableLocalState()->setDepthFunc(func);
}

void ContextLocalDepthRangef(Context *context, GLfloat zNear, GLfloat zFar)
{
    context->getMutableLocalState()->setDepthRange(clamp01(zNear), clamp01(zFar));
}

void ContextLocalDepthRangex(Context *context, GLfixed zNear, GLfixed zFar)
{
    context->getMutableLocalState()->setDepthRange(clamp01(ConvertFixedToFloat(zNear)),
                                                   clamp01(ConvertFixedToFloat(zFar)));
}

void ContextLocalFrontFace(Context *context, GLenum mode)
{
    context->getMutableLocalState()->setFrontFace(mode);
}

void ContextLocalLineWidth(Context *context, GLfloat width)
{
    context->getMutableLocalState()->setLineWidth(width);
}

void ContextLocalLineWidthx(Context *context, GLfixed width)
{
    context->getMutableLocalState()->setLineWidth(ConvertFixedToFloat(width));
}

void ContextLocalPolygonOffset(Context *context, GLfloat factor, GLfloat units)
{
    context->getMutableLocalState()->setPolygonOffsetParams(factor, units, 0.0f);
}

void ContextLocalPolygonOffsetClamp(Context *context, GLfloat factor, GLfloat units, GLfloat clamp)
{
    context->getMutableLocalState()->setPolygonOffsetParams(factor, units, clamp);
}

void ContextLocalPolygonOffsetx(Context *context, GLfixed factor, GLfixed units)
{
    context->getMutableLocalState()->setPolygonOffsetParams(ConvertFixedToFloat(factor),
                                                            ConvertFixedToFloat(units), 0.0f);
}

void ContextLocalSampleCoverage(Context *context, GLfloat value, GLboolean invert)
{
    context->getMutableLocalState()->setSampleCoverageParams(clamp01(value), ConvertToBool(invert));
}

void ContextLocalSampleCoveragex(Context *context, GLclampx value, GLboolean invert)
{
    const GLclampf valuef = ConvertFixedToFloat(value);
    context->getMutableLocalState()->setSampleCoverageParams(clamp01(valuef),
                                                             ConvertToBool(invert));
}

void ContextLocalScissor(Context *context, GLint x, GLint y, GLsizei width, GLsizei height)
{
    context->getMutableLocalState()->setScissorParams(x, y, width, height);
}

void ContextLocalVertexAttrib1f(Context *context, GLuint index, GLfloat x)
{
    GLfloat vals[4] = {x, 0, 0, 1};
    context->getMutableLocalState()->setVertexAttribf(index, vals);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalVertexAttrib1fv(Context *context, GLuint index, const GLfloat *values)
{
    GLfloat vals[4] = {values[0], 0, 0, 1};
    context->getMutableLocalState()->setVertexAttribf(index, vals);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalVertexAttrib2f(Context *context, GLuint index, GLfloat x, GLfloat y)
{
    GLfloat vals[4] = {x, y, 0, 1};
    context->getMutableLocalState()->setVertexAttribf(index, vals);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalVertexAttrib2fv(Context *context, GLuint index, const GLfloat *values)
{
    GLfloat vals[4] = {values[0], values[1], 0, 1};
    context->getMutableLocalState()->setVertexAttribf(index, vals);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalVertexAttrib3f(Context *context, GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
    GLfloat vals[4] = {x, y, z, 1};
    context->getMutableLocalState()->setVertexAttribf(index, vals);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalVertexAttrib3fv(Context *context, GLuint index, const GLfloat *values)
{
    GLfloat vals[4] = {values[0], values[1], values[2], 1};
    context->getMutableLocalState()->setVertexAttribf(index, vals);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalVertexAttrib4f(Context *context,
                                GLuint index,
                                GLfloat x,
                                GLfloat y,
                                GLfloat z,
                                GLfloat w)
{
    GLfloat vals[4] = {x, y, z, w};
    context->getMutableLocalState()->setVertexAttribf(index, vals);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalVertexAttrib4fv(Context *context, GLuint index, const GLfloat *values)
{
    context->getMutableLocalState()->setVertexAttribf(index, values);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalVertexAttribI4i(Context *context, GLuint index, GLint x, GLint y, GLint z, GLint w)
{
    GLint vals[4] = {x, y, z, w};
    context->getMutableLocalState()->setVertexAttribi(index, vals);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalVertexAttribI4iv(Context *context, GLuint index, const GLint *values)
{
    context->getMutableLocalState()->setVertexAttribi(index, values);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalVertexAttribI4ui(Context *context,
                                  GLuint index,
                                  GLuint x,
                                  GLuint y,
                                  GLuint z,
                                  GLuint w)
{
    GLuint vals[4] = {x, y, z, w};
    context->getMutableLocalState()->setVertexAttribu(index, vals);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalVertexAttribI4uiv(Context *context, GLuint index, const GLuint *values)
{
    context->getMutableLocalState()->setVertexAttribu(index, values);
    context->onContextLocalDefaultVertexAttributeChange();
}

void ContextLocalViewport(Context *context, GLint x, GLint y, GLsizei width, GLsizei height)
{
    context->getMutableLocalState()->setViewportParams(x, y, width, height);
}

void ContextLocalSampleMaski(Context *context, GLuint maskNumber, GLbitfield mask)
{
    context->getMutableLocalState()->setSampleMaskParams(maskNumber, mask);
}

void ContextLocalMinSampleShading(Context *context, GLfloat value)
{
    context->getMutableLocalState()->setMinSampleShading(value);
}

void ContextLocalPrimitiveBoundingBox(Context *context,
                                      GLfloat minX,
                                      GLfloat minY,
                                      GLfloat minZ,
                                      GLfloat minW,
                                      GLfloat maxX,
                                      GLfloat maxY,
                                      GLfloat maxZ,
                                      GLfloat maxW)
{
    context->getMutableLocalState()->setBoundingBox(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}

void ContextLocalLogicOp(Context *context, LogicalOperation opcode)
{
    context->getMutableGLES1State()->setLogicOp(opcode);
}

void ContextLocalLogicOpANGLE(Context *context, LogicalOperation opcode)
{
    context->getMutableLocalState()->setLogicOp(opcode);
}

void ContextLocalPolygonMode(Context *context, GLenum face, PolygonMode mode)
{
    ASSERT(face == GL_FRONT_AND_BACK);
    context->getMutableLocalState()->setPolygonMode(mode);
}

void ContextLocalPolygonModeNV(Context *context, GLenum face, PolygonMode mode)
{
    ContextLocalPolygonMode(context, face, mode);
}

void ContextLocalProvokingVertex(Context *context, ProvokingVertexConvention provokeMode)
{
    context->getMutableLocalState()->setProvokingVertex(provokeMode);
}

void ContextLocalCoverageModulation(Context *context, GLenum components)
{
    context->getMutableLocalState()->setCoverageModulation(components);
}

void ContextLocalClipControl(Context *context, ClipOrigin origin, ClipDepthMode depth)
{
    context->getMutableLocalState()->setClipControl(origin, depth);
}

void ContextLocalShadingRate(Context *context, GLenum rate)
{
    context->getMutableLocalState()->setShadingRate(rate);
}
}  // namespace gl
