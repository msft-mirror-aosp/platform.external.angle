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
    {Feature::AdjustClearColorPrecision, "adjustClearColorPrecision"},
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
    {Feature::AllowSeparateDepthStencilBuffers, "allowSeparateDepthStencilBuffers"},
    {Feature::AllowTranslateUniformBlockToStructuredBuffer, "allowTranslateUniformBlockToStructuredBuffer"},
    {Feature::AlwaysCallUseProgramAfterLink, "alwaysCallUseProgramAfterLink"},
    {Feature::AlwaysEnableEmulatedMultidrawExtensions, "alwaysEnableEmulatedMultidrawExtensions"},
    {Feature::AlwaysPreferStagedTextureUploads, "alwaysPreferStagedTextureUploads"},
    {Feature::AlwaysRunLinkSubJobsThreaded, "alwaysRunLinkSubJobsThreaded"},
    {Feature::AlwaysUnbindFramebufferTexture2D, "alwaysUnbindFramebufferTexture2D"},
    {Feature::AlwaysUseManagedStorageModeForBuffers, "alwaysUseManagedStorageModeForBuffers"},
    {Feature::AlwaysUseSharedStorageModeForBuffers, "alwaysUseSharedStorageModeForBuffers"},
    {Feature::AlwaysUseStagedBufferUpdates, "alwaysUseStagedBufferUpdates"},
    {Feature::AppendAliasedMemoryDecorations, "appendAliasedMemoryDecorations"},
    {Feature::AsyncCommandBufferResetAndGarbageCleanup, "asyncCommandBufferResetAndGarbageCleanup"},
    {Feature::Avoid1BitAlphaTextureFormats, "avoid1BitAlphaTextureFormats"},
    {Feature::AvoidBindFragDataLocation, "avoidBindFragDataLocation"},
    {Feature::AvoidOpSelectWithMismatchingRelaxedPrecision, "avoidOpSelectWithMismatchingRelaxedPrecision"},
    {Feature::AvoidStencilTextureSwizzle, "avoidStencilTextureSwizzle"},
    {Feature::BgraTexImageFormatsBroken, "bgraTexImageFormatsBroken"},
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
    {Feature::ClDumpVkSpirv, "clDumpVkSpirv"},
    {Feature::ClearsWithGapsNeedFlush, "clearsWithGapsNeedFlush"},
    {Feature::ClearToZeroOrOneBroken, "clearToZeroOrOneBroken"},
    {Feature::ClipSrcRegionForBlitFramebuffer, "clipSrcRegionForBlitFramebuffer"},
    {Feature::CompileJobIsThreadSafe, "compileJobIsThreadSafe"},
    {Feature::CompileMetalShaders, "compileMetalShaders"},
    {Feature::CompressVertexData, "compressVertexData"},
    {Feature::CopyIOSurfaceToNonIOSurfaceForReadOptimization, "copyIOSurfaceToNonIOSurfaceForReadOptimization"},
    {Feature::CopyTextureToBufferForReadOptimization, "copyTextureToBufferForReadOptimization"},
    {Feature::CorruptProgramBinaryForTesting, "corruptProgramBinaryForTesting"},
    {Feature::DecodeEncodeSRGBForGenerateMipmap, "decodeEncodeSRGBForGenerateMipmap"},
    {Feature::DepthStencilBlitExtraCopy, "depthStencilBlitExtraCopy"},
    {Feature::DescriptorSetCache, "descriptorSetCache"},
    {Feature::DisableAnisotropicFiltering, "disableAnisotropicFiltering"},
    {Feature::DisableB5G6R5Support, "disableB5G6R5Support"},
    {Feature::DisableBaseInstanceVertex, "disableBaseInstanceVertex"},
    {Feature::DisableBlendEquationAdvanced, "disableBlendEquationAdvanced"},
    {Feature::DisableBlendFuncExtended, "disableBlendFuncExtended"},
    {Feature::DisableClipControl, "disableClipControl"},
    {Feature::DisableDepthStencilResolveThroughAttachment, "disableDepthStencilResolveThroughAttachment"},
    {Feature::DisableDrawBuffersIndexed, "disableDrawBuffersIndexed"},
    {Feature::DisableFlippingBlitWithCommand, "disableFlippingBlitWithCommand"},
    {Feature::DisableGPUSwitchingSupport, "disableGPUSwitchingSupport"},
    {Feature::DisableMetalOnNvidia, "disableMetalOnNvidia"},
    {Feature::DisableMultisampledRenderToTexture, "disableMultisampledRenderToTexture"},
    {Feature::DisableNativeParallelCompile, "disableNativeParallelCompile"},
    {Feature::DisablePipelineCacheLoadForTesting, "disablePipelineCacheLoadForTesting"},
    {Feature::DisableProgramBinary, "disableProgramBinary"},
    {Feature::DisableProgramCaching, "disableProgramCaching"},
    {Feature::DisableProgramCachingForTransformFeedback, "disableProgramCachingForTransformFeedback"},
    {Feature::DisableProgrammableBlending, "disableProgrammableBlending"},
    {Feature::DisableRasterizerOrderViews, "disableRasterizerOrderViews"},
    {Feature::DisableRasterOrderGroups, "disableRasterOrderGroups"},
    {Feature::DisableRenderSnorm, "disableRenderSnorm"},
    {Feature::DisableRWTextureTier2Support, "disableRWTextureTier2Support"},
    {Feature::DisableSemaphoreFd, "disableSemaphoreFd"},
    {Feature::DisableSeparateShaderObjects, "disableSeparateShaderObjects"},
    {Feature::DisableStagedInitializationOfPackedTextureFormats, "disableStagedInitializationOfPackedTextureFormats"},
    {Feature::DisableSyncControlSupport, "disableSyncControlSupport"},
    {Feature::DisableTextureClampToBorder, "disableTextureClampToBorder"},
    {Feature::DisableTextureMirrorClampToEdge, "disableTextureMirrorClampToEdge"},
    {Feature::DisableTiledRendering, "disableTiledRendering"},
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
    {Feature::EmulateClipOrigin, "emulateClipOrigin"},
    {Feature::EmulateCopyTexImage2D, "emulateCopyTexImage2D"},
    {Feature::EmulateCopyTexImage2DFromRenderbuffers, "emulateCopyTexImage2DFromRenderbuffers"},
    {Feature::EmulateDithering, "emulateDithering"},
    {Feature::EmulateDontCareLoadWithRandomClear, "emulateDontCareLoadWithRandomClear"},
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
    {Feature::EnableAdditionalBlendFactorsForDithering, "enableAdditionalBlendFactorsForDithering"},
    {Feature::EnableAsyncPipelineCacheCompression, "enableAsyncPipelineCacheCompression"},
    {Feature::EnableCaptureLimits, "enableCaptureLimits"},
    {Feature::EnableInMemoryMtlLibraryCache, "enableInMemoryMtlLibraryCache"},
    {Feature::EnableMergeClientAttribBuffer, "enableMergeClientAttribBuffer"},
    {Feature::EnableMultisampledRenderToTexture, "enableMultisampledRenderToTexture"},
    {Feature::EnableMultisampledRenderToTextureOnNonTilers, "enableMultisampledRenderToTextureOnNonTilers"},
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
    {Feature::ExposeES32ForTesting, "exposeES32ForTesting"},
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
    {Feature::ForceFlushAfterDrawcallUsingShadowmap, "forceFlushAfterDrawcallUsingShadowmap"},
    {Feature::ForceFragmentShaderPrecisionHighpToMediump, "forceFragmentShaderPrecisionHighpToMediump"},
    {Feature::ForceGlErrorChecking, "forceGlErrorChecking"},
    {Feature::ForceInitShaderVariables, "forceInitShaderVariables"},
    {Feature::ForceMaxUniformBufferSize16KB, "forceMaxUniformBufferSize16KB"},
    {Feature::ForceMinimumMaxVertexAttributes, "forceMinimumMaxVertexAttributes"},
    {Feature::ForceNearestFiltering, "forceNearestFiltering"},
    {Feature::ForceNearestMipFiltering, "forceNearestMipFiltering"},
    {Feature::ForceNonCSBaseMipmapGeneration, "forceNonCSBaseMipmapGeneration"},
    {Feature::ForceRobustResourceInit, "forceRobustResourceInit"},
    {Feature::ForceSampleUsageForAhbBackedImages, "forceSampleUsageForAhbBackedImages"},
    {Feature::ForceSubmitImmutableTextureUpdates, "forceSubmitImmutableTextureUpdates"},
    {Feature::ForceTextureLodOffset1, "forceTextureLodOffset1"},
    {Feature::ForceTextureLodOffset2, "forceTextureLodOffset2"},
    {Feature::ForceTextureLodOffset3, "forceTextureLodOffset3"},
    {Feature::ForceTextureLodOffset4, "forceTextureLodOffset4"},
    {Feature::ForceWaitForSubmissionToCompleteForQueryResult, "forceWaitForSubmissionToCompleteForQueryResult"},
    {Feature::GenerateFragmentShadingRateAttchementWithCpu, "generateFragmentShadingRateAttchementWithCpu"},
    {Feature::GenerateShareableShaders, "generateShareableShaders"},
    {Feature::GetDimensionsIgnoresBaseLevel, "getDimensionsIgnoresBaseLevel"},
    {Feature::HasBaseVertexInstancedDraw, "hasBaseVertexInstancedDraw"},
    {Feature::HasBlobCacheThatEvictsOldItemsFirst, "hasBlobCacheThatEvictsOldItemsFirst"},
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
    {Feature::InjectAsmStatementIntoLoopBodies, "injectAsmStatementIntoLoopBodies"},
    {Feature::IntelDisableFastMath, "intelDisableFastMath"},
    {Feature::IntelExplicitBoolCastWorkaround, "intelExplicitBoolCastWorkaround"},
    {Feature::KeepBufferShadowCopy, "keepBufferShadowCopy"},
    {Feature::LimitMax3dArrayTextureSizeTo1024, "limitMax3dArrayTextureSizeTo1024"},
    {Feature::LimitMaxColorTargetBitsForTesting, "limitMaxColorTargetBitsForTesting"},
    {Feature::LimitMaxDrawBuffersForTesting, "limitMaxDrawBuffersForTesting"},
    {Feature::LimitMaxMSAASamplesTo4, "limitMaxMSAASamplesTo4"},
    {Feature::LimitMaxStorageBufferSize, "limitMaxStorageBufferSize"},
    {Feature::LimitSampleCountTo2, "limitSampleCountTo2"},
    {Feature::LimitWebglMaxTextureSizeTo4096, "limitWebglMaxTextureSizeTo4096"},
    {Feature::LimitWebglMaxTextureSizeTo8192, "limitWebglMaxTextureSizeTo8192"},
    {Feature::LinkJobIsThreadSafe, "linkJobIsThreadSafe"},
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
    {Feature::PreferCachedNoncoherentForDynamicStreamBufferUsage, "preferCachedNoncoherentForDynamicStreamBufferUsage"},
    {Feature::PreferCpuForBuffersubdata, "preferCpuForBuffersubdata"},
    {Feature::PreferCPUForBufferSubData, "preferCPUForBufferSubData"},
    {Feature::PreferDeviceLocalMemoryHostVisible, "preferDeviceLocalMemoryHostVisible"},
    {Feature::PreferDoubleBufferSwapchainOnFifoMode, "preferDoubleBufferSwapchainOnFifoMode"},
    {Feature::PreferDrawClearOverVkCmdClearAttachments, "preferDrawClearOverVkCmdClearAttachments"},
    {Feature::PreferDriverUniformOverSpecConst, "preferDriverUniformOverSpecConst"},
    {Feature::PreferDynamicRendering, "preferDynamicRendering"},
    {Feature::PreferHostCachedForNonStaticBufferUsage, "preferHostCachedForNonStaticBufferUsage"},
    {Feature::PreferLinearFilterForYUV, "preferLinearFilterForYUV"},
    {Feature::PreferMonolithicPipelinesOverLibraries, "preferMonolithicPipelinesOverLibraries"},
    {Feature::PreferMSRTSSFlagByDefault, "preferMSRTSSFlagByDefault"},
    {Feature::PreferSkippingInvalidateForEmulatedFormats, "preferSkippingInvalidateForEmulatedFormats"},
    {Feature::PreferSubmitAtFBOBoundary, "preferSubmitAtFBOBoundary"},
    {Feature::PreferSubmitOnAnySamplesPassedQueryEnd, "preferSubmitOnAnySamplesPassedQueryEnd"},
    {Feature::PreTransformTextureCubeGradDerivatives, "preTransformTextureCubeGradDerivatives"},
    {Feature::PrintMetalShaders, "printMetalShaders"},
    {Feature::PromotePackedFormatsTo8BitPerChannel, "promotePackedFormatsTo8BitPerChannel"},
    {Feature::ProvokingVertex, "provokingVertex"},
    {Feature::QueryCounterBitsGeneratesErrors, "queryCounterBitsGeneratesErrors"},
    {Feature::ReadPixelsUsingImplementationColorReadFormatForNorm16, "readPixelsUsingImplementationColorReadFormatForNorm16"},
    {Feature::ReapplyUBOBindingsAfterUsingBinaryProgram, "reapplyUBOBindingsAfterUsingBinaryProgram"},
    {Feature::RegenerateStructNames, "regenerateStructNames"},
    {Feature::RejectWebglShadersWithUndefinedBehavior, "rejectWebglShadersWithUndefinedBehavior"},
    {Feature::RemoveDynamicIndexingOfSwizzledVector, "removeDynamicIndexingOfSwizzledVector"},
    {Feature::RemoveInvariantAndCentroidForESSL3, "removeInvariantAndCentroidForESSL3"},
    {Feature::RequireGpuFamily2, "requireGpuFamily2"},
    {Feature::RescopeGlobalVariables, "rescopeGlobalVariables"},
    {Feature::ResetTexImage2DBaseLevel, "resetTexImage2DBaseLevel"},
    {Feature::ResyncDepthRangeOnClipControl, "resyncDepthRangeOnClipControl"},
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
    {Feature::SlowDownMonolithicPipelineCreationForTesting, "slowDownMonolithicPipelineCreationForTesting"},
    {Feature::SrgbBlendingBroken, "srgbBlendingBroken"},
    {Feature::Supports16BitInputOutput, "supports16BitInputOutput"},
    {Feature::Supports16BitPushConstant, "supports16BitPushConstant"},
    {Feature::Supports16BitStorageBuffer, "supports16BitStorageBuffer"},
    {Feature::Supports16BitUniformAndStorageBuffer, "supports16BitUniformAndStorageBuffer"},
    {Feature::Supports8BitPushConstant, "supports8BitPushConstant"},
    {Feature::Supports8BitStorageBuffer, "supports8BitStorageBuffer"},
    {Feature::Supports8BitUniformAndStorageBuffer, "supports8BitUniformAndStorageBuffer"},
    {Feature::SupportsAndroidHardwareBuffer, "supportsAndroidHardwareBuffer"},
    {Feature::SupportsAndroidNativeFenceSync, "supportsAndroidNativeFenceSync"},
    {Feature::SupportsAngleRgbxInternalFormat, "supportsAngleRgbxInternalFormat"},
    {Feature::SupportsAppleClipDistance, "supportsAppleClipDistance"},
    {Feature::SupportsAstcSliced3d, "supportsAstcSliced3d"},
    {Feature::SupportsBindMemory2, "supportsBindMemory2"},
    {Feature::SupportsBlendOperationAdvanced, "supportsBlendOperationAdvanced"},
    {Feature::SupportsBlendOperationAdvancedCoherent, "supportsBlendOperationAdvancedCoherent"},
    {Feature::SupportsColorWriteEnable, "supportsColorWriteEnable"},
    {Feature::SupportsComputeTranscodeEtcToBc, "supportsComputeTranscodeEtcToBc"},
    {Feature::SupportsCustomBorderColor, "supportsCustomBorderColor"},
    {Feature::SupportsDenormFtzFp16, "supportsDenormFtzFp16"},
    {Feature::SupportsDenormFtzFp32, "supportsDenormFtzFp32"},
    {Feature::SupportsDenormFtzFp64, "supportsDenormFtzFp64"},
    {Feature::SupportsDenormPreserveFp16, "supportsDenormPreserveFp16"},
    {Feature::SupportsDenormPreserveFp32, "supportsDenormPreserveFp32"},
    {Feature::SupportsDenormPreserveFp64, "supportsDenormPreserveFp64"},
    {Feature::SupportsDepthClampZeroOne, "supportsDepthClampZeroOne"},
    {Feature::SupportsDepthClipControl, "supportsDepthClipControl"},
    {Feature::SupportsDepthStencilIndependentResolveNone, "supportsDepthStencilIndependentResolveNone"},
    {Feature::SupportsDepthStencilResolve, "supportsDepthStencilResolve"},
    {Feature::SupportsDynamicRendering, "supportsDynamicRendering"},
    {Feature::SupportsDynamicRenderingLocalRead, "supportsDynamicRenderingLocalRead"},
    {Feature::SupportsExtendedDynamicState, "supportsExtendedDynamicState"},
    {Feature::SupportsExtendedDynamicState2, "supportsExtendedDynamicState2"},
    {Feature::SupportsExternalFenceCapabilities, "supportsExternalFenceCapabilities"},
    {Feature::SupportsExternalFenceFd, "supportsExternalFenceFd"},
    {Feature::SupportsExternalFormatResolve, "supportsExternalFormatResolve"},
    {Feature::SupportsExternalMemoryDmaBufAndModifiers, "supportsExternalMemoryDmaBufAndModifiers"},
    {Feature::SupportsExternalMemoryFd, "supportsExternalMemoryFd"},
    {Feature::SupportsExternalMemoryFuchsia, "supportsExternalMemoryFuchsia"},
    {Feature::SupportsExternalMemoryHost, "supportsExternalMemoryHost"},
    {Feature::SupportsExternalSemaphoreCapabilities, "supportsExternalSemaphoreCapabilities"},
    {Feature::SupportsExternalSemaphoreFd, "supportsExternalSemaphoreFd"},
    {Feature::SupportsExternalSemaphoreFuchsia, "supportsExternalSemaphoreFuchsia"},
    {Feature::SupportsFormatFeatureFlags2, "supportsFormatFeatureFlags2"},
    {Feature::SupportsFoveatedRendering, "supportsFoveatedRendering"},
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
    {Feature::SupportsImageCompressionControl, "supportsImageCompressionControl"},
    {Feature::SupportsImageCompressionControlSwapchain, "supportsImageCompressionControlSwapchain"},
    {Feature::SupportsImageCubeArray, "supportsImageCubeArray"},
    {Feature::SupportsImageFormatList, "supportsImageFormatList"},
    {Feature::SupportsImagelessFramebuffer, "supportsImagelessFramebuffer"},
    {Feature::SupportsIncrementalPresent, "supportsIncrementalPresent"},
    {Feature::SupportsIndexTypeUint8, "supportsIndexTypeUint8"},
    {Feature::SupportsLegacyDithering, "supportsLegacyDithering"},
    {Feature::SupportsLockSurfaceExtension, "supportsLockSurfaceExtension"},
    {Feature::SupportsLogicOpDynamicState, "supportsLogicOpDynamicState"},
    {Feature::SupportsMaintenance5, "supportsMaintenance5"},
    {Feature::SupportsMemoryBudget, "supportsMemoryBudget"},
    {Feature::SupportsMixedReadWriteDepthStencilLayouts, "supportsMixedReadWriteDepthStencilLayouts"},
    {Feature::SupportsMultiDrawIndirect, "supportsMultiDrawIndirect"},
    {Feature::SupportsMultisampledRenderToSingleSampled, "supportsMultisampledRenderToSingleSampled"},
    {Feature::SupportsMultiview, "supportsMultiview"},
    {Feature::SupportsNonConstantLoopIndexing, "supportsNonConstantLoopIndexing"},
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
    {Feature::SupportsRoundingModeRteFp16, "supportsRoundingModeRteFp16"},
    {Feature::SupportsRoundingModeRteFp32, "supportsRoundingModeRteFp32"},
    {Feature::SupportsRoundingModeRteFp64, "supportsRoundingModeRteFp64"},
    {Feature::SupportsRoundingModeRtzFp16, "supportsRoundingModeRtzFp16"},
    {Feature::SupportsRoundingModeRtzFp32, "supportsRoundingModeRtzFp32"},
    {Feature::SupportsRoundingModeRtzFp64, "supportsRoundingModeRtzFp64"},
    {Feature::SupportsSampler2dViewOf3d, "supportsSampler2dViewOf3d"},
    {Feature::SupportsSamplerMirrorClampToEdge, "supportsSamplerMirrorClampToEdge"},
    {Feature::SupportsShaderFloat16, "supportsShaderFloat16"},
    {Feature::SupportsShaderFloat64, "supportsShaderFloat64"},
    {Feature::SupportsShaderFramebufferFetch, "supportsShaderFramebufferFetch"},
    {Feature::SupportsShaderFramebufferFetchDepthStencil, "supportsShaderFramebufferFetchDepthStencil"},
    {Feature::SupportsShaderFramebufferFetchEXT, "supportsShaderFramebufferFetchEXT"},
    {Feature::SupportsShaderFramebufferFetchNonCoherent, "supportsShaderFramebufferFetchNonCoherent"},
    {Feature::SupportsShaderFramebufferFetchNonCoherentEXT, "supportsShaderFramebufferFetchNonCoherentEXT"},
    {Feature::SupportsShaderInt8, "supportsShaderInt8"},
    {Feature::SupportsShaderNonSemanticInfo, "supportsShaderNonSemanticInfo"},
    {Feature::SupportsShaderStencilExport, "supportsShaderStencilExport"},
    {Feature::SupportsSharedPresentableImageExtension, "supportsSharedPresentableImageExtension"},
    {Feature::SupportsSignedZeroInfNanPreserveFp16, "supportsSignedZeroInfNanPreserveFp16"},
    {Feature::SupportsSignedZeroInfNanPreserveFp32, "supportsSignedZeroInfNanPreserveFp32"},
    {Feature::SupportsSignedZeroInfNanPreserveFp64, "supportsSignedZeroInfNanPreserveFp64"},
    {Feature::SupportsSPIRV14, "supportsSPIRV14"},
    {Feature::SupportsSurfaceCapabilities2Extension, "supportsSurfaceCapabilities2Extension"},
    {Feature::SupportsSurfacelessQueryExtension, "supportsSurfacelessQueryExtension"},
    {Feature::SupportsSurfaceMaintenance1, "supportsSurfaceMaintenance1"},
    {Feature::SupportsSurfaceProtectedCapabilitiesExtension, "supportsSurfaceProtectedCapabilitiesExtension"},
    {Feature::SupportsSurfaceProtectedSwapchains, "supportsSurfaceProtectedSwapchains"},
    {Feature::SupportsSwapchainMaintenance1, "supportsSwapchainMaintenance1"},
    {Feature::SupportsSynchronization2, "supportsSynchronization2"},
    {Feature::SupportsTextureCompressionAstcHdr, "supportsTextureCompressionAstcHdr"},
    {Feature::SupportsTimelineSemaphore, "supportsTimelineSemaphore"},
    {Feature::SupportsTimestampSurfaceAttribute, "supportsTimestampSurfaceAttribute"},
    {Feature::SupportsTransformFeedbackExtension, "supportsTransformFeedbackExtension"},
    {Feature::SupportsUniformBufferStandardLayout, "supportsUniformBufferStandardLayout"},
    {Feature::SupportsVertexInputDynamicState, "supportsVertexInputDynamicState"},
    {Feature::SupportsYUVSamplerConversion, "supportsYUVSamplerConversion"},
    {Feature::SupportsYuvTarget, "supportsYuvTarget"},
    {Feature::SwapbuffersOnFlushOrFinishWithSingleBuffer, "swapbuffersOnFlushOrFinishWithSingleBuffer"},
    {Feature::SyncAllVertexArraysToDefault, "syncAllVertexArraysToDefault"},
    {Feature::SyncDefaultVertexArraysToDefault, "syncDefaultVertexArraysToDefault"},
    {Feature::SyncMonolithicPipelinesToBlobCache, "syncMonolithicPipelinesToBlobCache"},
    {Feature::UnbindFBOBeforeSwitchingContext, "unbindFBOBeforeSwitchingContext"},
    {Feature::UncurrentEglSurfaceUponSurfaceDestroy, "uncurrentEglSurfaceUponSurfaceDestroy"},
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
    {Feature::UseDualPipelineBlobCacheSlots, "useDualPipelineBlobCacheSlots"},
    {Feature::UseEmptyBlobsToEraseOldPipelineCacheFromBlobCache, "useEmptyBlobsToEraseOldPipelineCacheFromBlobCache"},
    {Feature::UseFrontFaceDynamicState, "useFrontFaceDynamicState"},
    {Feature::UseIntermediateTextureForGenerateMipmap, "useIntermediateTextureForGenerateMipmap"},
    {Feature::UseMultipleDescriptorsForExternalFormats, "useMultipleDescriptorsForExternalFormats"},
    {Feature::UseNonZeroStencilWriteMaskStaticState, "useNonZeroStencilWriteMaskStaticState"},
    {Feature::UsePrimitiveRestartEnableDynamicState, "usePrimitiveRestartEnableDynamicState"},
    {Feature::UseRasterizerDiscardEnableDynamicState, "useRasterizerDiscardEnableDynamicState"},
    {Feature::UseResetCommandBufferBitForSecondaryPools, "useResetCommandBufferBitForSecondaryPools"},
    {Feature::UseShadowBuffersWhenAppropriate, "useShadowBuffersWhenAppropriate"},
    {Feature::UsesNativeBuiltinClKernel, "usesNativeBuiltinClKernel"},
    {Feature::UseStencilOpDynamicState, "useStencilOpDynamicState"},
    {Feature::UseStencilTestEnableDynamicState, "useStencilTestEnableDynamicState"},
    {Feature::UseSystemMemoryForConstantBuffers, "useSystemMemoryForConstantBuffers"},
    {Feature::UseUnusedBlocksWithStandardOrSharedLayout, "useUnusedBlocksWithStandardOrSharedLayout"},
    {Feature::UseVertexInputBindingStrideDynamicState, "useVertexInputBindingStrideDynamicState"},
    {Feature::UseVkEventForBufferBarrier, "useVkEventForBufferBarrier"},
    {Feature::UseVkEventForImageBarrier, "useVkEventForImageBarrier"},
    {Feature::UseVmaForImageSuballocation, "useVmaForImageSuballocation"},
    {Feature::VaryingsRequireMatchingPrecisionInSpirv, "varyingsRequireMatchingPrecisionInSpirv"},
    {Feature::VerifyPipelineCacheInBlobCache, "verifyPipelineCacheInBlobCache"},
    {Feature::VertexIDDoesNotIncludeBaseVertex, "vertexIDDoesNotIncludeBaseVertex"},
    {Feature::WaitIdleBeforeSwapchainRecreation, "waitIdleBeforeSwapchainRecreation"},
    {Feature::WarmUpPipelineCacheAtLink, "warmUpPipelineCacheAtLink"},
    {Feature::WrapSwitchInIfTrue, "wrapSwitchInIfTrue"},
    {Feature::WriteHelperSampleMask, "writeHelperSampleMask"},
    {Feature::ZeroMaxLodWorkaround, "zeroMaxLodWorkaround"},
}};
}  // anonymous namespace

const char *GetFeatureName(Feature feature)
{
    return kFeatureNames[feature];
}

}  // namespace angle
