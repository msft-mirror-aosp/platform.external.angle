// GENERATED FILE - DO NOT EDIT.
// Generated by gen_features.py using data from *_features.json.
//
// Copyright 2022 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// angle_features_autogen.cpp: List of ANGLE features to help enable/disable them in tests.

#include "angle_features_autogen.h"

#include "common/PackedEnums.h"

namespace angle
{
namespace
{
constexpr PackedEnumMap<Feature, const char *> kFeatureNames = {{
    {Feature::AddAndTrueToLoopCondition, "addAndTrueToLoopCondition"},
    {Feature::AddMockTextureNoRenderTarget, "addMockTextureNoRenderTarget"},
    {Feature::AdjustSrcDstRegionForBlitFramebuffer, "adjustSrcDstRegionForBlitFramebuffer"},
    {Feature::AllocateNonZeroMemory, "allocateNonZeroMemory"},
    {Feature::AllowAstcFormats, "allowAstcFormats"},
    {Feature::AllowBufferReadWrite, "allowBufferReadWrite"},
    {Feature::AllowClearForRobustResourceInit, "allowClearForRobustResourceInit"},
    {Feature::AllowCompressedFormats, "allowCompressedFormats"},
    {Feature::AllowES3OnFL100, "allowES3OnFL100"},
    {Feature::AllowETCFormats, "allowETCFormats"},
    {Feature::AllowGenerateMipmapWithCompute, "allowGenerateMipmapWithCompute"},
    {Feature::AllowGenMultipleMipsPerPass, "allowGenMultipleMipsPerPass"},
    {Feature::AllowHostImageCopyDespiteNonIdenticalLayout, "allowHostImageCopyDespiteNonIdenticalLayout"},
    {Feature::AllowInlineConstVertexData, "allowInlineConstVertexData"},
    {Feature::AllowMultisampledRenderToTextureEmulation, "allowMultisampledRenderToTextureEmulation"},
    {Feature::AllowMultisampleStoreAndResolve, "allowMultisampleStoreAndResolve"},
    {Feature::AllowRenderpassWithoutAttachment, "allowRenderpassWithoutAttachment"},
    {Feature::AllowRuntimeSamplerCompareMode, "allowRuntimeSamplerCompareMode"},
    {Feature::AllowSamplerCompareGradient, "allowSamplerCompareGradient"},
    {Feature::AllowSamplerCompareLod, "allowSamplerCompareLod"},
    {Feature::AllowSeparateDepthStencilBuffers, "allowSeparateDepthStencilBuffers"},
    {Feature::AllowTranslateUniformBlockToStructuredBuffer, "allowTranslateUniformBlockToStructuredBuffer"},
    {Feature::AlwaysCallUseProgramAfterLink, "alwaysCallUseProgramAfterLink"},
    {Feature::AlwaysPreferStagedTextureUploads, "alwaysPreferStagedTextureUploads"},
    {Feature::AlwaysUnbindFramebufferTexture2D, "alwaysUnbindFramebufferTexture2D"},
    {Feature::AlwaysUseManagedStorageModeForBuffers, "alwaysUseManagedStorageModeForBuffers"},
    {Feature::AlwaysUseSharedStorageModeForBuffers, "alwaysUseSharedStorageModeForBuffers"},
    {Feature::AlwaysUseStagedBufferUpdates, "alwaysUseStagedBufferUpdates"},
    {Feature::AppendAliasedMemoryDecorations, "appendAliasedMemoryDecorations"},
    {Feature::AsyncCommandBufferReset, "asyncCommandBufferReset"},
    {Feature::AsyncCommandQueue, "asyncCommandQueue"},
    {Feature::Avoid1BitAlphaTextureFormats, "avoid1BitAlphaTextureFormats"},
    {Feature::AvoidStencilTextureSwizzle, "avoidStencilTextureSwizzle"},
    {Feature::BindCompleteFramebufferForTimerQueries, "bindCompleteFramebufferForTimerQueries"},
    {Feature::BindTransformFeedbackBufferBeforeBindBufferRange, "bindTransformFeedbackBufferBeforeBindBufferRange"},
    {Feature::BorderColorSrgb, "borderColorSrgb"},
    {Feature::BottomLeftOriginPresentRegionRectangles, "bottomLeftOriginPresentRegionRectangles"},
    {Feature::BresenhamLineRasterization, "bresenhamLineRasterization"},
    {Feature::CacheCompiledShader, "cacheCompiledShader"},
    {Feature::CallClearTwice, "callClearTwice"},
    {Feature::ClampArrayAccess, "clampArrayAccess"},
    {Feature::ClampFragDepth, "clampFragDepth"},
    {Feature::ClampMscRate, "clampMscRate"},
    {Feature::ClampPointSize, "clampPointSize"},
    {Feature::ClearToZeroOrOneBroken, "clearToZeroOrOneBroken"},
    {Feature::ClipSrcRegionForBlitFramebuffer, "clipSrcRegionForBlitFramebuffer"},
    {Feature::CompileMetalShaders, "compileMetalShaders"},
    {Feature::CompressVertexData, "compressVertexData"},
    {Feature::CopyIOSurfaceToNonIOSurfaceForReadOptimization, "copyIOSurfaceToNonIOSurfaceForReadOptimization"},
    {Feature::CopyTextureToBufferForReadOptimization, "copyTextureToBufferForReadOptimization"},
    {Feature::DecodeEncodeSRGBForGenerateMipmap, "decodeEncodeSRGBForGenerateMipmap"},
    {Feature::DeferFlushUntilEndRenderPass, "deferFlushUntilEndRenderPass"},
    {Feature::DepthStencilBlitExtraCopy, "depthStencilBlitExtraCopy"},
    {Feature::DisableAnisotropicFiltering, "disableAnisotropicFiltering"},
    {Feature::DisableB5G6R5Support, "disableB5G6R5Support"},
    {Feature::DisableBaseInstanceVertex, "disableBaseInstanceVertex"},
    {Feature::DisableBlendFuncExtended, "disableBlendFuncExtended"},
    {Feature::DisableClipControl, "disableClipControl"},
    {Feature::DisableDrawBuffersIndexed, "disableDrawBuffersIndexed"},
    {Feature::DisableFlippingBlitWithCommand, "disableFlippingBlitWithCommand"},
    {Feature::DisableGPUSwitchingSupport, "disableGPUSwitchingSupport"},
    {Feature::DisableMetalOnAmdFirePro, "disableMetalOnAmdFirePro"},
    {Feature::DisableMetalOnNvidia, "disableMetalOnNvidia"},
    {Feature::DisableMultisampledRenderToTexture, "disableMultisampledRenderToTexture"},
    {Feature::DisableNativeParallelCompile, "disableNativeParallelCompile"},
    {Feature::DisableProgramBinary, "disableProgramBinary"},
    {Feature::DisableProgramCaching, "disableProgramCaching"},
    {Feature::DisableProgramCachingForTransformFeedback, "disableProgramCachingForTransformFeedback"},
    {Feature::DisableProgrammableBlending, "disableProgrammableBlending"},
    {Feature::DisableRasterizerOrderViews, "disableRasterizerOrderViews"},
    {Feature::DisableRasterOrderGroups, "disableRasterOrderGroups"},
    {Feature::DisableRenderSnorm, "disableRenderSnorm"},
    {Feature::DisableRWTextureTier2Support, "disableRWTextureTier2Support"},
    {Feature::DisableSemaphoreFd, "disableSemaphoreFd"},
    {Feature::DisableStagedInitializationOfPackedTextureFormats, "disableStagedInitializationOfPackedTextureFormats"},
    {Feature::DisableSyncControlSupport, "disableSyncControlSupport"},
    {Feature::DisableTextureClampToBorder, "disableTextureClampToBorder"},
    {Feature::DisableTextureMirrorClampToEdge, "disableTextureMirrorClampToEdge"},
    {Feature::DisableTimestampQueries, "disableTimestampQueries"},
    {Feature::DisallowMixedDepthStencilLoadOpNoneAndLoad, "disallowMixedDepthStencilLoadOpNoneAndLoad"},
    {Feature::DoesSRGBClearsOnLinearFramebufferAttachments, "doesSRGBClearsOnLinearFramebufferAttachments"},
    {Feature::DontInitializeUninitializedLocals, "dontInitializeUninitializedLocals"},
    {Feature::DontUseLoopsToInitializeVariables, "dontUseLoopsToInitializeVariables"},
    {Feature::DoubleDepthBiasConstantFactor, "doubleDepthBiasConstantFactor"},
    {Feature::DoWhileGLSLCausesGPUHang, "doWhileGLSLCausesGPUHang"},
    {Feature::DumpShaderSource, "dumpShaderSource"},
    {Feature::DumpTranslatedShaders, "dumpTranslatedShaders"},
    {Feature::EglColorspaceAttributePassthrough, "eglColorspaceAttributePassthrough"},
    {Feature::EmulateAbsIntFunction, "emulateAbsIntFunction"},
    {Feature::EmulateAdvancedBlendEquations, "emulateAdvancedBlendEquations"},
    {Feature::EmulateAlphaToCoverage, "emulateAlphaToCoverage"},
    {Feature::EmulateAtan2Float, "emulateAtan2Float"},
    {Feature::EmulateClipDistanceState, "emulateClipDistanceState"},
    {Feature::EmulateCopyTexImage2D, "emulateCopyTexImage2D"},
    {Feature::EmulateCopyTexImage2DFromRenderbuffers, "emulateCopyTexImage2DFromRenderbuffers"},
    {Feature::EmulateDithering, "emulateDithering"},
    {Feature::EmulatedPrerotation180, "emulatedPrerotation180"},
    {Feature::EmulatedPrerotation270, "emulatedPrerotation270"},
    {Feature::EmulatedPrerotation90, "emulatedPrerotation90"},
    {Feature::EmulateImmutableCompressedTexture3D, "emulateImmutableCompressedTexture3D"},
    {Feature::EmulateIsnanFloat, "emulateIsnanFloat"},
    {Feature::EmulateMaxVertexAttribStride, "emulateMaxVertexAttribStride"},
    {Feature::EmulatePackSkipRowsAndPackSkipPixels, "emulatePackSkipRowsAndPackSkipPixels"},
    {Feature::EmulatePixelLocalStorage, "emulatePixelLocalStorage"},
    {Feature::EmulatePrimitiveRestartFixedIndex, "emulatePrimitiveRestartFixedIndex"},
    {Feature::EmulateR32fImageAtomicExchange, "emulateR32fImageAtomicExchange"},
    {Feature::EmulateRGB10, "emulateRGB10"},
    {Feature::EmulateTinyStencilTextures, "emulateTinyStencilTextures"},
    {Feature::EmulateTransformFeedback, "emulateTransformFeedback"},
    {Feature::EnableAsyncPipelineCacheCompression, "enableAsyncPipelineCacheCompression"},
    {Feature::EnableCaptureLimits, "enableCaptureLimits"},
    {Feature::EnableInMemoryMtlLibraryCache, "enableInMemoryMtlLibraryCache"},
    {Feature::EnableMultisampledRenderToTexture, "enableMultisampledRenderToTexture"},
    {Feature::EnableParallelCompileAndLink, "enableParallelCompileAndLink"},
    {Feature::EnableParallelMtlLibraryCompilation, "enableParallelMtlLibraryCompilation"},
    {Feature::EnablePipelineCacheDataCompression, "enablePipelineCacheDataCompression"},
    {Feature::EnablePortabilityEnumeration, "enablePortabilityEnumeration"},
    {Feature::EnablePrecisionQualifiers, "enablePrecisionQualifiers"},
    {Feature::EnablePreRotateSurfaces, "enablePreRotateSurfaces"},
    {Feature::EnableProgramBinaryForCapture, "enableProgramBinaryForCapture"},
    {Feature::EnableShaderSubstitution, "enableShaderSubstitution"},
    {Feature::EnableTimestampQueries, "enableTimestampQueries"},
    {Feature::EnableTranslatedShaderSubstitution, "enableTranslatedShaderSubstitution"},
    {Feature::EnsureNonEmptyBufferIsBoundForDraw, "ensureNonEmptyBufferIsBoundForDraw"},
    {Feature::ExpandIntegerPowExpressions, "expandIntegerPowExpressions"},
    {Feature::ExplicitFragmentLocations, "explicitFragmentLocations"},
    {Feature::ExplicitlyCastMediumpFloatTo16Bit, "explicitlyCastMediumpFloatTo16Bit"},
    {Feature::ExplicitlyEnablePerSampleShading, "explicitlyEnablePerSampleShading"},
    {Feature::ExposeNonConformantExtensionsAndVersions, "exposeNonConformantExtensionsAndVersions"},
    {Feature::FinishDoesNotCauseQueriesToBeAvailable, "finishDoesNotCauseQueriesToBeAvailable"},
    {Feature::FlushAfterEndingTransformFeedback, "flushAfterEndingTransformFeedback"},
    {Feature::FlushAfterStreamVertexData, "flushAfterStreamVertexData"},
    {Feature::FlushBeforeDeleteTextureIfCopiedTo, "flushBeforeDeleteTextureIfCopiedTo"},
    {Feature::FlushOnFramebufferChange, "flushOnFramebufferChange"},
    {Feature::ForceAtomicValueResolution, "forceAtomicValueResolution"},
    {Feature::ForceBufferGPUStorage, "forceBufferGPUStorage"},
    {Feature::ForceContinuousRefreshOnSharedPresent, "forceContinuousRefreshOnSharedPresent"},
    {Feature::ForceD16TexFilter, "forceD16TexFilter"},
    {Feature::ForceD24S8AsUnsupported, "forceD24S8AsUnsupported"},
    {Feature::ForceDepthAttachmentInitOnClear, "forceDepthAttachmentInitOnClear"},
    {Feature::ForceDisableFullScreenExclusive, "forceDisableFullScreenExclusive"},
    {Feature::ForceFallbackFormat, "forceFallbackFormat"},
    {Feature::ForceFragmentShaderPrecisionHighpToMediump, "forceFragmentShaderPrecisionHighpToMediump"},
    {Feature::ForceGlErrorChecking, "forceGlErrorChecking"},
    {Feature::ForceInitShaderVariables, "forceInitShaderVariables"},
    {Feature::ForceMaxUniformBufferSize16KB, "forceMaxUniformBufferSize16KB"},
    {Feature::ForceNearestFiltering, "forceNearestFiltering"},
    {Feature::ForceNearestMipFiltering, "forceNearestMipFiltering"},
    {Feature::ForceNonCSBaseMipmapGeneration, "forceNonCSBaseMipmapGeneration"},
    {Feature::ForceRobustResourceInit, "forceRobustResourceInit"},
    {Feature::ForceSubmitImmutableTextureUpdates, "forceSubmitImmutableTextureUpdates"},
    {Feature::ForceTextureLodOffset1, "forceTextureLodOffset1"},
    {Feature::ForceTextureLodOffset2, "forceTextureLodOffset2"},
    {Feature::ForceTextureLodOffset3, "forceTextureLodOffset3"},
    {Feature::ForceTextureLodOffset4, "forceTextureLodOffset4"},
    {Feature::ForceWaitForSubmissionToCompleteForQueryResult, "forceWaitForSubmissionToCompleteForQueryResult"},
    {Feature::GenerateShareableShaders, "generateShareableShaders"},
    {Feature::GetDimensionsIgnoresBaseLevel, "getDimensionsIgnoresBaseLevel"},
    {Feature::HasBaseVertexInstancedDraw, "hasBaseVertexInstancedDraw"},
    {Feature::HasCheapRenderPass, "hasCheapRenderPass"},
    {Feature::HasDepthAutoResolve, "hasDepthAutoResolve"},
    {Feature::HasEffectivePipelineCacheSerialization, "hasEffectivePipelineCacheSerialization"},
    {Feature::HasEvents, "hasEvents"},
    {Feature::HasExplicitMemBarrier, "hasExplicitMemBarrier"},
    {Feature::HasNonUniformDispatch, "hasNonUniformDispatch"},
    {Feature::HasShaderStencilOutput, "hasShaderStencilOutput"},
    {Feature::HasStencilAutoResolve, "hasStencilAutoResolve"},
    {Feature::HasTextureSwizzle, "hasTextureSwizzle"},
    {Feature::InitFragmentOutputVariables, "initFragmentOutputVariables"},
    {Feature::InitializeCurrentVertexAttributes, "initializeCurrentVertexAttributes"},
    {Feature::IntelDisableFastMath, "intelDisableFastMath"},
    {Feature::IntelExplicitBoolCastWorkaround, "intelExplicitBoolCastWorkaround"},
    {Feature::KeepBufferShadowCopy, "keepBufferShadowCopy"},
    {Feature::LimitMax3dArrayTextureSizeTo1024, "limitMax3dArrayTextureSizeTo1024"},
    {Feature::LimitMaxColorTargetBitsForTesting, "limitMaxColorTargetBitsForTesting"},
    {Feature::LimitMaxDrawBuffersForTesting, "limitMaxDrawBuffersForTesting"},
    {Feature::LimitMaxMSAASamplesTo4, "limitMaxMSAASamplesTo4"},
    {Feature::LimitSampleCountTo2, "limitSampleCountTo2"},
    {Feature::LimitWebglMaxTextureSizeTo4096, "limitWebglMaxTextureSizeTo4096"},
    {Feature::LoadMetalShadersFromBlobCache, "loadMetalShadersFromBlobCache"},
    {Feature::LogMemoryReportCallbacks, "logMemoryReportCallbacks"},
    {Feature::LogMemoryReportStats, "logMemoryReportStats"},
    {Feature::LoseContextOnOutOfMemory, "loseContextOnOutOfMemory"},
    {Feature::MapUnspecifiedColorSpaceToPassThrough, "mapUnspecifiedColorSpaceToPassThrough"},
    {Feature::MergeProgramPipelineCachesToGlobalCache, "mergeProgramPipelineCachesToGlobalCache"},
    {Feature::MrtPerfWorkaround, "mrtPerfWorkaround"},
    {Feature::MultisampleColorFormatShaderReadWorkaround, "multisampleColorFormatShaderReadWorkaround"},
    {Feature::MutableMipmapTextureUpload, "mutableMipmapTextureUpload"},
    {Feature::OverrideSurfaceFormatRGB8ToRGBA8, "overrideSurfaceFormatRGB8ToRGBA8"},
    {Feature::PackLastRowSeparatelyForPaddingInclusion, "packLastRowSeparatelyForPaddingInclusion"},
    {Feature::PackOverlappingRowsSeparatelyPackBuffer, "packOverlappingRowsSeparatelyPackBuffer"},
    {Feature::PadBuffersToMaxVertexAttribStride, "padBuffersToMaxVertexAttribStride"},
    {Feature::PassHighpToPackUnormSnormBuiltins, "passHighpToPackUnormSnormBuiltins"},
    {Feature::PerFrameWindowSizeQuery, "perFrameWindowSizeQuery"},
    {Feature::PermanentlySwitchToFramebufferFetchMode, "permanentlySwitchToFramebufferFetchMode"},
    {Feature::PersistentlyMappedBuffers, "persistentlyMappedBuffers"},
    {Feature::PreAddTexelFetchOffsets, "preAddTexelFetchOffsets"},
    {Feature::PreemptivelyStartProvokingVertexCommandBuffer, "preemptivelyStartProvokingVertexCommandBuffer"},
    {Feature::PreferAggregateBarrierCalls, "preferAggregateBarrierCalls"},
    {Feature::PreferCpuForBuffersubdata, "preferCpuForBuffersubdata"},
    {Feature::PreferCPUForBufferSubData, "preferCPUForBufferSubData"},
    {Feature::PreferDeviceLocalMemoryHostVisible, "preferDeviceLocalMemoryHostVisible"},
    {Feature::PreferDrawClearOverVkCmdClearAttachments, "preferDrawClearOverVkCmdClearAttachments"},
    {Feature::PreferDriverUniformOverSpecConst, "preferDriverUniformOverSpecConst"},
    {Feature::PreferLinearFilterForYUV, "preferLinearFilterForYUV"},
    {Feature::PreferMonolithicPipelinesOverLibraries, "preferMonolithicPipelinesOverLibraries"},
    {Feature::PreferSkippingInvalidateForEmulatedFormats, "preferSkippingInvalidateForEmulatedFormats"},
    {Feature::PreferSubmitAtFBOBoundary, "preferSubmitAtFBOBoundary"},
    {Feature::PreferSubmitOnAnySamplesPassedQueryEnd, "preferSubmitOnAnySamplesPassedQueryEnd"},
    {Feature::PrintMetalShaders, "printMetalShaders"},
    {Feature::PromotePackedFormatsTo8BitPerChannel, "promotePackedFormatsTo8BitPerChannel"},
    {Feature::ProvokingVertex, "provokingVertex"},
    {Feature::QueryCounterBitsGeneratesErrors, "queryCounterBitsGeneratesErrors"},
    {Feature::ReadPixelsUsingImplementationColorReadFormatForNorm16, "readPixelsUsingImplementationColorReadFormatForNorm16"},
    {Feature::ReapplyUBOBindingsAfterUsingBinaryProgram, "reapplyUBOBindingsAfterUsingBinaryProgram"},
    {Feature::RegenerateStructNames, "regenerateStructNames"},
    {Feature::RemoveDynamicIndexingOfSwizzledVector, "removeDynamicIndexingOfSwizzledVector"},
    {Feature::RemoveInvariantAndCentroidForESSL3, "removeInvariantAndCentroidForESSL3"},
    {Feature::RequireGpuFamily2, "requireGpuFamily2"},
    {Feature::RequireMsl21, "requireMsl21"},
    {Feature::ResetTexImage2DBaseLevel, "resetTexImage2DBaseLevel"},
    {Feature::RetainSPIRVDebugInfo, "retainSPIRVDebugInfo"},
    {Feature::RewriteFloatUnaryMinusOperator, "rewriteFloatUnaryMinusOperator"},
    {Feature::RewriteRepeatedAssignToSwizzled, "rewriteRepeatedAssignToSwizzled"},
    {Feature::RewriteRowMajorMatrices, "rewriteRowMajorMatrices"},
    {Feature::RewriteUnaryMinusOperator, "rewriteUnaryMinusOperator"},
    {Feature::RGBA4IsNotSupportedForColorRendering, "RGBA4IsNotSupportedForColorRendering"},
    {Feature::RGBDXT1TexturesSampleZeroAlpha, "RGBDXT1TexturesSampleZeroAlpha"},
    {Feature::RoundOutputAfterDithering, "roundOutputAfterDithering"},
    {Feature::SanitizeAMDGPURendererString, "sanitizeAMDGPURendererString"},
    {Feature::ScalarizeVecAndMatConstructorArgs, "scalarizeVecAndMatConstructorArgs"},
    {Feature::SelectViewInGeometryShader, "selectViewInGeometryShader"},
    {Feature::SetDataFasterThanImageUpload, "setDataFasterThanImageUpload"},
    {Feature::SetPrimitiveRestartFixedIndexForDrawArrays, "setPrimitiveRestartFixedIndexForDrawArrays"},
    {Feature::SetZeroLevelBeforeGenerateMipmap, "setZeroLevelBeforeGenerateMipmap"},
    {Feature::ShiftInstancedArrayDataWithOffset, "shiftInstancedArrayDataWithOffset"},
    {Feature::SingleThreadedTextureDecompression, "singleThreadedTextureDecompression"},
    {Feature::SkipVSConstantRegisterZero, "skipVSConstantRegisterZero"},
    {Feature::SlowAsyncCommandQueueForTesting, "slowAsyncCommandQueueForTesting"},
    {Feature::SlowDownMonolithicPipelineCreationForTesting, "slowDownMonolithicPipelineCreationForTesting"},
    {Feature::SupportsAndroidHardwareBuffer, "supportsAndroidHardwareBuffer"},
    {Feature::SupportsAndroidNativeFenceSync, "supportsAndroidNativeFenceSync"},
    {Feature::SupportsBindMemory2, "supportsBindMemory2"},
    {Feature::SupportsBlendOperationAdvanced, "supportsBlendOperationAdvanced"},
    {Feature::SupportsColorWriteEnable, "supportsColorWriteEnable"},
    {Feature::SupportsComputeTranscodeEtcToBc, "supportsComputeTranscodeEtcToBc"},
    {Feature::SupportsCustomBorderColor, "supportsCustomBorderColor"},
    {Feature::SupportsDepthClampZeroOne, "supportsDepthClampZeroOne"},
    {Feature::SupportsDepthClipControl, "supportsDepthClipControl"},
    {Feature::SupportsDepthClipEnable, "supportsDepthClipEnable"},
    {Feature::SupportsDepthStencilResolve, "supportsDepthStencilResolve"},
    {Feature::SupportsExtendedDynamicState, "supportsExtendedDynamicState"},
    {Feature::SupportsExtendedDynamicState2, "supportsExtendedDynamicState2"},
    {Feature::SupportsExternalFenceCapabilities, "supportsExternalFenceCapabilities"},
    {Feature::SupportsExternalFenceFd, "supportsExternalFenceFd"},
    {Feature::SupportsExternalMemoryDmaBufAndModifiers, "supportsExternalMemoryDmaBufAndModifiers"},
    {Feature::SupportsExternalMemoryFd, "supportsExternalMemoryFd"},
    {Feature::SupportsExternalMemoryFuchsia, "supportsExternalMemoryFuchsia"},
    {Feature::SupportsExternalMemoryHost, "supportsExternalMemoryHost"},
    {Feature::SupportsExternalSemaphoreCapabilities, "supportsExternalSemaphoreCapabilities"},
    {Feature::SupportsExternalSemaphoreFd, "supportsExternalSemaphoreFd"},
    {Feature::SupportsExternalSemaphoreFuchsia, "supportsExternalSemaphoreFuchsia"},
    {Feature::SupportsFilteringPrecision, "supportsFilteringPrecision"},
    {Feature::SupportsFormatFeatureFlags2, "supportsFormatFeatureFlags2"},
    {Feature::SupportsFragmentShaderInterlockARB, "supportsFragmentShaderInterlockARB"},
    {Feature::SupportsFragmentShaderInterlockNV, "supportsFragmentShaderInterlockNV"},
    {Feature::SupportsFragmentShaderOrderingINTEL, "supportsFragmentShaderOrderingINTEL"},
    {Feature::SupportsFragmentShaderPixelInterlock, "supportsFragmentShaderPixelInterlock"},
    {Feature::SupportsFragmentShadingRate, "supportsFragmentShadingRate"},
    {Feature::SupportsFullScreenExclusive, "supportsFullScreenExclusive"},
    {Feature::SupportsGeometryStreamsCapability, "supportsGeometryStreamsCapability"},
    {Feature::SupportsGetMemoryRequirements2, "supportsGetMemoryRequirements2"},
    {Feature::SupportsGGPFrameToken, "supportsGGPFrameToken"},
    {Feature::SupportsGraphicsPipelineLibrary, "supportsGraphicsPipelineLibrary"},
    {Feature::SupportsHostImageCopy, "supportsHostImageCopy"},
    {Feature::SupportsHostQueryReset, "supportsHostQueryReset"},
    {Feature::SupportsImage2dViewOf3d, "supportsImage2dViewOf3d"},
    {Feature::SupportsImageCubeArray, "supportsImageCubeArray"},
    {Feature::SupportsImageFormatList, "supportsImageFormatList"},
    {Feature::SupportsImagelessFramebuffer, "supportsImagelessFramebuffer"},
    {Feature::SupportsIncrementalPresent, "supportsIncrementalPresent"},
    {Feature::SupportsIndexTypeUint8, "supportsIndexTypeUint8"},
    {Feature::SupportsLegacyDithering, "supportsLegacyDithering"},
    {Feature::SupportsLockSurfaceExtension, "supportsLockSurfaceExtension"},
    {Feature::SupportsLogicOpDynamicState, "supportsLogicOpDynamicState"},
    {Feature::SupportsMemoryBudget, "supportsMemoryBudget"},
    {Feature::SupportsMixedReadWriteDepthStencilLayouts, "supportsMixedReadWriteDepthStencilLayouts"},
    {Feature::SupportsMultiDrawIndirect, "supportsMultiDrawIndirect"},
    {Feature::SupportsMultisampledRenderToSingleSampled, "supportsMultisampledRenderToSingleSampled"},
    {Feature::SupportsMultisampledRenderToSingleSampledGOOGLEX, "supportsMultisampledRenderToSingleSampledGOOGLEX"},
    {Feature::SupportsMultiview, "supportsMultiview"},
    {Feature::SupportsNegativeViewport, "supportsNegativeViewport"},
    {Feature::SupportsPipelineCreationCacheControl, "supportsPipelineCreationCacheControl"},
    {Feature::SupportsPipelineCreationFeedback, "supportsPipelineCreationFeedback"},
    {Feature::SupportsPipelineProtectedAccess, "supportsPipelineProtectedAccess"},
    {Feature::SupportsPipelineRobustness, "supportsPipelineRobustness"},
    {Feature::SupportsPipelineStatisticsQuery, "supportsPipelineStatisticsQuery"},
    {Feature::SupportsPortabilityEnumeration, "supportsPortabilityEnumeration"},
    {Feature::SupportsPresentation, "supportsPresentation"},
    {Feature::SupportsPrimitivesGeneratedQuery, "supportsPrimitivesGeneratedQuery"},
    {Feature::SupportsPrimitiveTopologyListRestart, "supportsPrimitiveTopologyListRestart"},
    {Feature::SupportsProtectedMemory, "supportsProtectedMemory"},
    {Feature::SupportsRasterizationOrderAttachmentAccess, "supportsRasterizationOrderAttachmentAccess"},
    {Feature::SupportsRenderpass2, "supportsRenderpass2"},
    {Feature::SupportsRenderPassLoadStoreOpNone, "supportsRenderPassLoadStoreOpNone"},
    {Feature::SupportsRenderPassStoreOpNone, "supportsRenderPassStoreOpNone"},
    {Feature::SupportsSampler2dViewOf3d, "supportsSampler2dViewOf3d"},
    {Feature::SupportsSamplerMirrorClampToEdge, "supportsSamplerMirrorClampToEdge"},
    {Feature::SupportsShaderFloat16, "supportsShaderFloat16"},
    {Feature::SupportsShaderFramebufferFetch, "supportsShaderFramebufferFetch"},
    {Feature::SupportsShaderFramebufferFetchEXT, "supportsShaderFramebufferFetchEXT"},
    {Feature::SupportsShaderFramebufferFetchNonCoherent, "supportsShaderFramebufferFetchNonCoherent"},
    {Feature::SupportsShaderFramebufferFetchNonCoherentEXT, "supportsShaderFramebufferFetchNonCoherentEXT"},
    {Feature::SupportsShaderPixelLocalStorageEXT, "supportsShaderPixelLocalStorageEXT"},
    {Feature::SupportsShaderStencilExport, "supportsShaderStencilExport"},
    {Feature::SupportsSharedPresentableImageExtension, "supportsSharedPresentableImageExtension"},
    {Feature::SupportsSurfaceCapabilities2Extension, "supportsSurfaceCapabilities2Extension"},
    {Feature::SupportsSurfacelessQueryExtension, "supportsSurfacelessQueryExtension"},
    {Feature::SupportsSurfaceProtectedCapabilitiesExtension, "supportsSurfaceProtectedCapabilitiesExtension"},
    {Feature::SupportsSurfaceProtectedSwapchains, "supportsSurfaceProtectedSwapchains"},
    {Feature::SupportsSwapchainMaintenance1, "supportsSwapchainMaintenance1"},
    {Feature::SupportsTimelineSemaphore, "supportsTimelineSemaphore"},
    {Feature::SupportsTimestampSurfaceAttribute, "supportsTimestampSurfaceAttribute"},
    {Feature::SupportsTransformFeedbackExtension, "supportsTransformFeedbackExtension"},
    {Feature::SupportsVertexInputDynamicState, "supportsVertexInputDynamicState"},
    {Feature::SupportsYUVSamplerConversion, "supportsYUVSamplerConversion"},
    {Feature::SupportsYuvTarget, "supportsYuvTarget"},
    {Feature::SwapbuffersOnFlushOrFinishWithSingleBuffer, "swapbuffersOnFlushOrFinishWithSingleBuffer"},
    {Feature::SyncMonolithicPipelinesToBlobCache, "syncMonolithicPipelinesToBlobCache"},
    {Feature::SyncVertexArraysToDefault, "syncVertexArraysToDefault"},
    {Feature::UnbindFBOBeforeSwitchingContext, "unbindFBOBeforeSwitchingContext"},
    {Feature::UnfoldShortCircuits, "unfoldShortCircuits"},
    {Feature::UnpackLastRowSeparatelyForPaddingInclusion, "unpackLastRowSeparatelyForPaddingInclusion"},
    {Feature::UnpackOverlappingRowsSeparatelyUnpackBuffer, "unpackOverlappingRowsSeparatelyUnpackBuffer"},
    {Feature::UnsizedSRGBReadPixelsDoesntTransform, "unsizedSRGBReadPixelsDoesntTransform"},
    {Feature::UploadDataToIosurfacesWithStagingBuffers, "uploadDataToIosurfacesWithStagingBuffers"},
    {Feature::UploadTextureDataInChunks, "uploadTextureDataInChunks"},
    {Feature::UseCullModeDynamicState, "useCullModeDynamicState"},
    {Feature::UseDepthBiasEnableDynamicState, "useDepthBiasEnableDynamicState"},
    {Feature::UseDepthCompareOpDynamicState, "useDepthCompareOpDynamicState"},
    {Feature::UseDepthTestEnableDynamicState, "useDepthTestEnableDynamicState"},
    {Feature::UseDepthWriteEnableDynamicState, "useDepthWriteEnableDynamicState"},
    {Feature::UseFrontFaceDynamicState, "useFrontFaceDynamicState"},
    {Feature::UseInstancedPointSpriteEmulation, "useInstancedPointSpriteEmulation"},
    {Feature::UseMultipleDescriptorsForExternalFormats, "useMultipleDescriptorsForExternalFormats"},
    {Feature::UseNonZeroStencilWriteMaskStaticState, "useNonZeroStencilWriteMaskStaticState"},
    {Feature::UsePrimitiveRestartEnableDynamicState, "usePrimitiveRestartEnableDynamicState"},
    {Feature::UseRasterizerDiscardEnableDynamicState, "useRasterizerDiscardEnableDynamicState"},
    {Feature::UseResetCommandBufferBitForSecondaryPools, "useResetCommandBufferBitForSecondaryPools"},
    {Feature::UseShadowBuffersWhenAppropriate, "useShadowBuffersWhenAppropriate"},
    {Feature::UseStencilOpDynamicState, "useStencilOpDynamicState"},
    {Feature::UseStencilTestEnableDynamicState, "useStencilTestEnableDynamicState"},
    {Feature::UseSystemMemoryForConstantBuffers, "useSystemMemoryForConstantBuffers"},
    {Feature::UseUnusedBlocksWithStandardOrSharedLayout, "useUnusedBlocksWithStandardOrSharedLayout"},
    {Feature::UseVertexInputBindingStrideDynamicState, "useVertexInputBindingStrideDynamicState"},
    {Feature::UseVmaForImageSuballocation, "useVmaForImageSuballocation"},
    {Feature::VaryingsRequireMatchingPrecisionInSpirv, "varyingsRequireMatchingPrecisionInSpirv"},
    {Feature::VertexIDDoesNotIncludeBaseVertex, "vertexIDDoesNotIncludeBaseVertex"},
    {Feature::WaitIdleBeforeSwapchainRecreation, "waitIdleBeforeSwapchainRecreation"},
    {Feature::WarmUpPipelineCacheAtLink, "warmUpPipelineCacheAtLink"},
    {Feature::ZeroMaxLodWorkaround, "zeroMaxLodWorkaround"},
}};
}  // anonymous namespace

const char *GetFeatureName(Feature feature)
{
    return kFeatureNames[feature];
}

}  // namespace angle
