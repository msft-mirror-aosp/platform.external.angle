// GENERATED FILE - DO NOT EDIT.
// Generated by gen_features.py using data from gl_features.json.
//
// Copyright 2022 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// FeaturesGL_autogen.h: angle::Features and workarounds for GL driver bugs and other issues.

#ifndef ANGLE_PLATFORM_AUTOGEN_FEATURESGL_H_
#define ANGLE_PLATFORM_AUTOGEN_FEATURESGL_H_

#include "platform/Feature.h"

namespace angle
{

struct FeaturesGL : FeatureSetBase
{
    FeaturesGL();
    ~FeaturesGL();

    FeatureInfo avoid1BitAlphaTextureFormats = {
        "avoid1BitAlphaTextureFormats",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo RGBA4IsNotSupportedForColorRendering = {
        "RGBA4IsNotSupportedForColorRendering",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo allowETCFormats = {
        "allowETCFormats",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo allowAstcFormats = {
        "allowAstcFormats",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo clearsWithGapsNeedFlush = {
        "clearsWithGapsNeedFlush",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo doesSRGBClearsOnLinearFramebufferAttachments = {
        "doesSRGBClearsOnLinearFramebufferAttachments",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo doWhileGLSLCausesGPUHang = {
        "doWhileGLSLCausesGPUHang",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo vertexIDDoesNotIncludeBaseVertex = {
        "vertexIDDoesNotIncludeBaseVertex",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo finishDoesNotCauseQueriesToBeAvailable = {
        "finishDoesNotCauseQueriesToBeAvailable",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo alwaysCallUseProgramAfterLink = {
        "alwaysCallUseProgramAfterLink",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo unpackOverlappingRowsSeparatelyUnpackBuffer = {
        "unpackOverlappingRowsSeparatelyUnpackBuffer",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo packOverlappingRowsSeparatelyPackBuffer = {
        "packOverlappingRowsSeparatelyPackBuffer",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo initializeCurrentVertexAttributes = {
        "initializeCurrentVertexAttributes",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulateAbsIntFunction = {
        "emulateAbsIntFunction",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo addAndTrueToLoopCondition = {
        "addAndTrueToLoopCondition",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo unpackLastRowSeparatelyForPaddingInclusion = {
        "unpackLastRowSeparatelyForPaddingInclusion",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo packLastRowSeparatelyForPaddingInclusion = {
        "packLastRowSeparatelyForPaddingInclusion",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulateIsnanFloat = {
        "emulateIsnanFloat",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo useUnusedBlocksWithStandardOrSharedLayout = {
        "useUnusedBlocksWithStandardOrSharedLayout",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo removeInvariantAndCentroidForESSL3 = {
        "removeInvariantAndCentroidForESSL3",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo rewriteFloatUnaryMinusOperator = {
        "rewriteFloatUnaryMinusOperator",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulateAtan2Float = {
        "emulateAtan2Float",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo reapplyUBOBindingsAfterUsingBinaryProgram = {
        "reapplyUBOBindingsAfterUsingBinaryProgram",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulateMaxVertexAttribStride = {
        "emulateMaxVertexAttribStride",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo dontInitializeUninitializedLocals = {
        "dontInitializeUninitializedLocals",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo clampPointSize = {
        "clampPointSize",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo dontUseLoopsToInitializeVariables = {
        "dontUseLoopsToInitializeVariables",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo clampFragDepth = {
        "clampFragDepth",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo rewriteRepeatedAssignToSwizzled = {
        "rewriteRepeatedAssignToSwizzled",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo preTransformTextureCubeGradDerivatives = {
        "preTransformTextureCubeGradDerivatives",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableBlendFuncExtended = {
        "disableBlendFuncExtended",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo unsizedSRGBReadPixelsDoesntTransform = {
        "unsizedSRGBReadPixelsDoesntTransform",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo queryCounterBitsGeneratesErrors = {
        "queryCounterBitsGeneratesErrors",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo limitWebglMaxTextureSizeTo4096 = {
        "limitWebglMaxTextureSizeTo4096",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo limitWebglMaxTextureSizeTo8192 = {
        "limitWebglMaxTextureSizeTo8192",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo limitMaxMSAASamplesTo4 = {
        "limitMaxMSAASamplesTo4",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo allowClearForRobustResourceInit = {
        "allowClearForRobustResourceInit",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo clampArrayAccess = {
        "clampArrayAccess",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo resetTexImage2DBaseLevel = {
        "resetTexImage2DBaseLevel",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo clearToZeroOrOneBroken = {
        "clearToZeroOrOneBroken",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo limitMax3dArrayTextureSizeTo1024 = {
        "limitMax3dArrayTextureSizeTo1024",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo adjustSrcDstRegionForBlitFramebuffer = {
        "adjustSrcDstRegionForBlitFramebuffer",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo clipSrcRegionForBlitFramebuffer = {
        "clipSrcRegionForBlitFramebuffer",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo RGBDXT1TexturesSampleZeroAlpha = {
        "RGBDXT1TexturesSampleZeroAlpha",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo unfoldShortCircuits = {
        "unfoldShortCircuits",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulatePrimitiveRestartFixedIndex = {
        "emulatePrimitiveRestartFixedIndex",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo setPrimitiveRestartFixedIndexForDrawArrays = {
        "setPrimitiveRestartFixedIndexForDrawArrays",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo removeDynamicIndexingOfSwizzledVector = {
        "removeDynamicIndexingOfSwizzledVector",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo preAddTexelFetchOffsets = {
        "preAddTexelFetchOffsets",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo regenerateStructNames = {
        "regenerateStructNames",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo readPixelsUsingImplementationColorReadFormatForNorm16 = {
        "readPixelsUsingImplementationColorReadFormatForNorm16",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo flushBeforeDeleteTextureIfCopiedTo = {
        "flushBeforeDeleteTextureIfCopiedTo",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo rewriteRowMajorMatrices = {
        "rewriteRowMajorMatrices",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableDrawBuffersIndexed = {
        "disableDrawBuffersIndexed",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableSemaphoreFd = {
        "disableSemaphoreFd",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableTimestampQueries = {
        "disableTimestampQueries",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo decodeEncodeSRGBForGenerateMipmap = {
        "decodeEncodeSRGBForGenerateMipmap",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulateCopyTexImage2D = {
        "emulateCopyTexImage2D",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulateCopyTexImage2DFromRenderbuffers = {
        "emulateCopyTexImage2DFromRenderbuffers",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableGPUSwitchingSupport = {
        "disableGPUSwitchingSupport",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableNativeParallelCompile = {
        "disableNativeParallelCompile",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulatePackSkipRowsAndPackSkipPixels = {
        "emulatePackSkipRowsAndPackSkipPixels",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo clampMscRate = {
        "clampMscRate",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo bindTransformFeedbackBufferBeforeBindBufferRange = {
        "bindTransformFeedbackBufferBeforeBindBufferRange",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableSyncControlSupport = {
        "disableSyncControlSupport",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo keepBufferShadowCopy = {
        "keepBufferShadowCopy",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo setZeroLevelBeforeGenerateMipmap = {
        "setZeroLevelBeforeGenerateMipmap",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo promotePackedFormatsTo8BitPerChannel = {
        "promotePackedFormatsTo8BitPerChannel",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo initFragmentOutputVariables = {
        "initFragmentOutputVariables",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo shiftInstancedArrayDataWithOffset = {
        "shiftInstancedArrayDataWithOffset",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo syncAllVertexArraysToDefault = {
        "syncAllVertexArraysToDefault",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo syncDefaultVertexArraysToDefault = {
        "syncDefaultVertexArraysToDefault",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo sanitizeAMDGPURendererString = {
        "sanitizeAMDGPURendererString",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo unbindFBOBeforeSwitchingContext = {
        "unbindFBOBeforeSwitchingContext",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo flushOnFramebufferChange = {
        "flushOnFramebufferChange",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableMultisampledRenderToTexture = {
        "disableMultisampledRenderToTexture",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo uploadTextureDataInChunks = {
        "uploadTextureDataInChunks",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulateImmutableCompressedTexture3D = {
        "emulateImmutableCompressedTexture3D",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulateRGB10 = {
        "emulateRGB10",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo alwaysUnbindFramebufferTexture2D = {
        "alwaysUnbindFramebufferTexture2D",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableTextureClampToBorder = {
        "disableTextureClampToBorder",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo passHighpToPackUnormSnormBuiltins = {
        "passHighpToPackUnormSnormBuiltins",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulateClipDistanceState = {
        "emulateClipDistanceState",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo emulateClipOrigin = {
        "emulateClipOrigin",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo bindCompleteFramebufferForTimerQueries = {
        "bindCompleteFramebufferForTimerQueries",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableBaseInstanceVertex = {
        "disableBaseInstanceVertex",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo supportsFragmentShaderInterlockNV = {
        "supportsFragmentShaderInterlockNV",
        FeatureCategory::OpenGLFeatures,
        &members,
    };

    FeatureInfo supportsFragmentShaderOrderingINTEL = {
        "supportsFragmentShaderOrderingINTEL",
        FeatureCategory::OpenGLFeatures,
        &members,
    };

    FeatureInfo supportsFragmentShaderInterlockARB = {
        "supportsFragmentShaderInterlockARB",
        FeatureCategory::OpenGLFeatures,
        &members,
    };

    FeatureInfo supportsShaderFramebufferFetchEXT = {
        "supportsShaderFramebufferFetchEXT",
        FeatureCategory::OpenGLFeatures,
        &members,
    };

    FeatureInfo supportsShaderFramebufferFetchNonCoherentEXT = {
        "supportsShaderFramebufferFetchNonCoherentEXT",
        FeatureCategory::OpenGLFeatures,
        &members,
    };

    FeatureInfo disableClipControl = {
        "disableClipControl",
        FeatureCategory::OpenGLFeatures,
        &members,
    };

    FeatureInfo scalarizeVecAndMatConstructorArgs = {
        "scalarizeVecAndMatConstructorArgs",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo ensureNonEmptyBufferIsBoundForDraw = {
        "ensureNonEmptyBufferIsBoundForDraw",
        FeatureCategory::OpenGLFeatures,
        &members,
    };

    FeatureInfo explicitFragmentLocations = {
        "explicitFragmentLocations",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableRenderSnorm = {
        "disableRenderSnorm",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableTextureMirrorClampToEdge = {
        "disableTextureMirrorClampToEdge",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo resyncDepthRangeOnClipControl = {
        "resyncDepthRangeOnClipControl",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo corruptProgramBinaryForTesting = {
        "corruptProgramBinaryForTesting",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo useIntermediateTextureForGenerateMipmap = {
        "useIntermediateTextureForGenerateMipmap",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo avoidBindFragDataLocation = {
        "avoidBindFragDataLocation",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo srgbBlendingBroken = {
        "srgbBlendingBroken",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo bgraTexImageFormatsBroken = {
        "bgraTexImageFormatsBroken",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableTiledRendering = {
        "disableTiledRendering",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

    FeatureInfo disableBlendEquationAdvanced = {
        "disableBlendEquationAdvanced",
        FeatureCategory::OpenGLWorkarounds,
        &members,
    };

};

inline FeaturesGL::FeaturesGL()  = default;
inline FeaturesGL::~FeaturesGL() = default;

}  // namespace angle

#endif  // ANGLE_PLATFORM_AUTOGEN_FEATURESGL_H_
