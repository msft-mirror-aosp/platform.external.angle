// GENERATED FILE - DO NOT EDIT.
// Generated by gen_features.py using data from *_features.json.
//
// Copyright 2022 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// angle_features_autogen.h: List of ANGLE features to help enable/disable them in tests.

#ifndef ANGLE_SRC_TESTS_TEST_UTIL_AUTOGEN_ANGLE_FEATURES_AUTOGEN_H_
#define ANGLE_SRC_TESTS_TEST_UTIL_AUTOGEN_ANGLE_FEATURES_AUTOGEN_H_

#include "../util_export.h"

namespace angle
{
enum class Feature
{
    AddAndTrueToLoopCondition,
    AddMockTextureNoRenderTarget,
    AdjustClearColorPrecision,
    AdjustSrcDstRegionForBlitFramebuffer,
    AllocateNonZeroMemory,
    AllowAstcFormats,
    AllowBufferReadWrite,
    AllowClearForRobustResourceInit,
    AllowCompressedFormats,
    AllowES3OnFL100,
    AllowETCFormats,
    AllowGenerateMipmapWithCompute,
    AllowGenMultipleMipsPerPass,
    AllowHostImageCopyDespiteNonIdenticalLayout,
    AllowInlineConstVertexData,
    AllowMultisampledRenderToTextureEmulation,
    AllowMultisampleStoreAndResolve,
    AllowRenderpassWithoutAttachment,
    AllowRuntimeSamplerCompareMode,
    AllowSamplerCompareGradient,
    AllowSeparateDepthStencilBuffers,
    AllowTranslateUniformBlockToStructuredBuffer,
    AlwaysCallUseProgramAfterLink,
    AlwaysEnableEmulatedMultidrawExtensions,
    AlwaysPreferStagedTextureUploads,
    AlwaysRunLinkSubJobsThreaded,
    AlwaysUnbindFramebufferTexture2D,
    AlwaysUseManagedStorageModeForBuffers,
    AlwaysUseSharedStorageModeForBuffers,
    AlwaysUseStagedBufferUpdates,
    AppendAliasedMemoryDecorations,
    AsyncCommandBufferResetAndGarbageCleanup,
    AsyncCommandQueue,
    Avoid1BitAlphaTextureFormats,
    AvoidBindFragDataLocation,
    AvoidOpSelectWithMismatchingRelaxedPrecision,
    AvoidStencilTextureSwizzle,
    BgraTexImageFormatsBroken,
    BindCompleteFramebufferForTimerQueries,
    BindTransformFeedbackBufferBeforeBindBufferRange,
    BorderColorSrgb,
    BottomLeftOriginPresentRegionRectangles,
    BresenhamLineRasterization,
    CacheCompiledShader,
    CallClearTwice,
    ClampArrayAccess,
    ClampFragDepth,
    ClampMscRate,
    ClampPointSize,
    ClDumpVkSpirv,
    ClearsWithGapsNeedFlush,
    ClearToZeroOrOneBroken,
    ClipSrcRegionForBlitFramebuffer,
    CompileJobIsThreadSafe,
    CompileMetalShaders,
    CompressVertexData,
    CopyIOSurfaceToNonIOSurfaceForReadOptimization,
    CopyTextureToBufferForReadOptimization,
    CorruptProgramBinaryForTesting,
    DecodeEncodeSRGBForGenerateMipmap,
    DepthStencilBlitExtraCopy,
    DescriptorSetCache,
    DisableAnisotropicFiltering,
    DisableB5G6R5Support,
    DisableBaseInstanceVertex,
    DisableBlendEquationAdvanced,
    DisableBlendFuncExtended,
    DisableClipControl,
    DisableDepthStencilResolveThroughAttachment,
    DisableDrawBuffersIndexed,
    DisableFlippingBlitWithCommand,
    DisableGPUSwitchingSupport,
    DisableMetalOnNvidia,
    DisableMultisampledRenderToTexture,
    DisableNativeParallelCompile,
    DisablePipelineCacheLoadForTesting,
    DisableProgramBinary,
    DisableProgramCaching,
    DisableProgramCachingForTransformFeedback,
    DisableProgrammableBlending,
    DisableRasterizerOrderViews,
    DisableRasterOrderGroups,
    DisableRenderSnorm,
    DisableRWTextureTier2Support,
    DisableSemaphoreFd,
    DisableSeparateShaderObjects,
    DisableStagedInitializationOfPackedTextureFormats,
    DisableSyncControlSupport,
    DisableTextureClampToBorder,
    DisableTextureMirrorClampToEdge,
    DisableTiledRendering,
    DisableTimestampQueries,
    DisallowMixedDepthStencilLoadOpNoneAndLoad,
    DoesSRGBClearsOnLinearFramebufferAttachments,
    DontInitializeUninitializedLocals,
    DontUseLoopsToInitializeVariables,
    DoubleDepthBiasConstantFactor,
    DoWhileGLSLCausesGPUHang,
    DumpShaderSource,
    DumpTranslatedShaders,
    EglColorspaceAttributePassthrough,
    EmulateAbsIntFunction,
    EmulateAdvancedBlendEquations,
    EmulateAlphaToCoverage,
    EmulateAtan2Float,
    EmulateClipDistanceState,
    EmulateClipOrigin,
    EmulateCopyTexImage2D,
    EmulateCopyTexImage2DFromRenderbuffers,
    EmulateDithering,
    EmulateDontCareLoadWithRandomClear,
    EmulatedPrerotation180,
    EmulatedPrerotation270,
    EmulatedPrerotation90,
    EmulateImmutableCompressedTexture3D,
    EmulateIsnanFloat,
    EmulateMaxVertexAttribStride,
    EmulatePackSkipRowsAndPackSkipPixels,
    EmulatePixelLocalStorage,
    EmulatePrimitiveRestartFixedIndex,
    EmulateR32fImageAtomicExchange,
    EmulateRGB10,
    EmulateTinyStencilTextures,
    EmulateTransformFeedback,
    EnableAdditionalBlendFactorsForDithering,
    EnableAsyncPipelineCacheCompression,
    EnableCaptureLimits,
    EnableInMemoryMtlLibraryCache,
    EnableMergeClientAttribBuffer,
    EnableMultisampledRenderToTexture,
    EnableMultisampledRenderToTextureOnNonTilers,
    EnableParallelCompileAndLink,
    EnableParallelMtlLibraryCompilation,
    EnablePipelineCacheDataCompression,
    EnablePortabilityEnumeration,
    EnablePrecisionQualifiers,
    EnablePreRotateSurfaces,
    EnableProgramBinaryForCapture,
    EnableShaderSubstitution,
    EnableTimestampQueries,
    EnableTranslatedShaderSubstitution,
    EnsureNonEmptyBufferIsBoundForDraw,
    ExpandIntegerPowExpressions,
    ExplicitFragmentLocations,
    ExplicitlyCastMediumpFloatTo16Bit,
    ExplicitlyEnablePerSampleShading,
    ExposeNonConformantExtensionsAndVersions,
    FinishDoesNotCauseQueriesToBeAvailable,
    FlushAfterEndingTransformFeedback,
    FlushAfterStreamVertexData,
    FlushBeforeDeleteTextureIfCopiedTo,
    FlushOnFramebufferChange,
    ForceAtomicValueResolution,
    ForceBufferGPUStorage,
    ForceContinuousRefreshOnSharedPresent,
    ForceD16TexFilter,
    ForceD24S8AsUnsupported,
    ForceDepthAttachmentInitOnClear,
    ForceDisableFullScreenExclusive,
    ForceFallbackFormat,
    ForceFlushAfterDrawcallUsingShadowmap,
    ForceFragmentShaderPrecisionHighpToMediump,
    ForceGlErrorChecking,
    ForceInitShaderVariables,
    ForceMaxUniformBufferSize16KB,
    ForceMinimumMaxVertexAttributes,
    ForceNearestFiltering,
    ForceNearestMipFiltering,
    ForceNonCSBaseMipmapGeneration,
    ForceRobustResourceInit,
    ForceSampleUsageForAhbBackedImages,
    ForceSubmitImmutableTextureUpdates,
    ForceTextureLodOffset1,
    ForceTextureLodOffset2,
    ForceTextureLodOffset3,
    ForceTextureLodOffset4,
    ForceWaitForSubmissionToCompleteForQueryResult,
    GenerateFragmentShadingRateAttchementWithCpu,
    GenerateShareableShaders,
    GetDimensionsIgnoresBaseLevel,
    HasBaseVertexInstancedDraw,
    HasBlobCacheThatEvictsOldItemsFirst,
    HasCheapRenderPass,
    HasDepthAutoResolve,
    HasEffectivePipelineCacheSerialization,
    HasEvents,
    HasExplicitMemBarrier,
    HasNonUniformDispatch,
    HasShaderStencilOutput,
    HasStencilAutoResolve,
    HasTextureSwizzle,
    InitFragmentOutputVariables,
    InitializeCurrentVertexAttributes,
    InjectAsmStatementIntoLoopBodies,
    IntelDisableFastMath,
    IntelExplicitBoolCastWorkaround,
    KeepBufferShadowCopy,
    LimitMax3dArrayTextureSizeTo1024,
    LimitMaxColorTargetBitsForTesting,
    LimitMaxDrawBuffersForTesting,
    LimitMaxMSAASamplesTo4,
    LimitMaxStorageBufferSize,
    LimitSampleCountTo2,
    LimitWebglMaxTextureSizeTo4096,
    LimitWebglMaxTextureSizeTo8192,
    LinkJobIsThreadSafe,
    LoadMetalShadersFromBlobCache,
    LogMemoryReportCallbacks,
    LogMemoryReportStats,
    LoseContextOnOutOfMemory,
    MapUnspecifiedColorSpaceToPassThrough,
    MergeProgramPipelineCachesToGlobalCache,
    MrtPerfWorkaround,
    MultisampleColorFormatShaderReadWorkaround,
    MutableMipmapTextureUpload,
    OverrideSurfaceFormatRGB8ToRGBA8,
    PackLastRowSeparatelyForPaddingInclusion,
    PackOverlappingRowsSeparatelyPackBuffer,
    PadBuffersToMaxVertexAttribStride,
    PassHighpToPackUnormSnormBuiltins,
    PerFrameWindowSizeQuery,
    PermanentlySwitchToFramebufferFetchMode,
    PersistentlyMappedBuffers,
    PreAddTexelFetchOffsets,
    PreemptivelyStartProvokingVertexCommandBuffer,
    PreferAggregateBarrierCalls,
    PreferCachedNoncoherentForDynamicStreamBufferUsage,
    PreferCpuForBuffersubdata,
    PreferCPUForBufferSubData,
    PreferDeviceLocalMemoryHostVisible,
    PreferDoubleBufferSwapchainOnFifoMode,
    PreferDrawClearOverVkCmdClearAttachments,
    PreferDriverUniformOverSpecConst,
    PreferDynamicRendering,
    PreferHostCachedForNonStaticBufferUsage,
    PreferLinearFilterForYUV,
    PreferMonolithicPipelinesOverLibraries,
    PreferMSRTSSFlagByDefault,
    PreferSkippingInvalidateForEmulatedFormats,
    PreferSubmitAtFBOBoundary,
    PreferSubmitOnAnySamplesPassedQueryEnd,
    PreTransformTextureCubeGradDerivatives,
    PrintMetalShaders,
    PromotePackedFormatsTo8BitPerChannel,
    ProvokingVertex,
    QueryCounterBitsGeneratesErrors,
    ReadPixelsUsingImplementationColorReadFormatForNorm16,
    ReapplyUBOBindingsAfterUsingBinaryProgram,
    RegenerateStructNames,
    RejectWebglShadersWithUndefinedBehavior,
    RemoveDynamicIndexingOfSwizzledVector,
    RemoveInvariantAndCentroidForESSL3,
    RequireGpuFamily2,
    RescopeGlobalVariables,
    ResetTexImage2DBaseLevel,
    ResyncDepthRangeOnClipControl,
    RetainSPIRVDebugInfo,
    RewriteFloatUnaryMinusOperator,
    RewriteRepeatedAssignToSwizzled,
    RewriteRowMajorMatrices,
    RewriteUnaryMinusOperator,
    RGBA4IsNotSupportedForColorRendering,
    RGBDXT1TexturesSampleZeroAlpha,
    RoundOutputAfterDithering,
    SanitizeAMDGPURendererString,
    ScalarizeVecAndMatConstructorArgs,
    SelectViewInGeometryShader,
    SetDataFasterThanImageUpload,
    SetPrimitiveRestartFixedIndexForDrawArrays,
    SetZeroLevelBeforeGenerateMipmap,
    ShiftInstancedArrayDataWithOffset,
    SingleThreadedTextureDecompression,
    SkipVSConstantRegisterZero,
    SlowAsyncCommandQueueForTesting,
    SlowDownMonolithicPipelineCreationForTesting,
    SrgbBlendingBroken,
    Supports16BitInputOutput,
    Supports16BitPushConstant,
    Supports16BitStorageBuffer,
    Supports16BitUniformAndStorageBuffer,
    Supports8BitPushConstant,
    Supports8BitStorageBuffer,
    Supports8BitUniformAndStorageBuffer,
    SupportsAndroidHardwareBuffer,
    SupportsAndroidNativeFenceSync,
    SupportsBindMemory2,
    SupportsBlendOperationAdvanced,
    SupportsBlendOperationAdvancedCoherent,
    SupportsColorWriteEnable,
    SupportsComputeTranscodeEtcToBc,
    SupportsCustomBorderColor,
    SupportsDenormFtzFp16,
    SupportsDenormFtzFp32,
    SupportsDenormFtzFp64,
    SupportsDenormPreserveFp16,
    SupportsDenormPreserveFp32,
    SupportsDenormPreserveFp64,
    SupportsDepthClampZeroOne,
    SupportsDepthClipControl,
    SupportsDepthStencilIndependentResolveNone,
    SupportsDepthStencilResolve,
    SupportsDynamicRendering,
    SupportsDynamicRenderingLocalRead,
    SupportsExtendedDynamicState,
    SupportsExtendedDynamicState2,
    SupportsExternalFenceCapabilities,
    SupportsExternalFenceFd,
    SupportsExternalFormatResolve,
    SupportsExternalMemoryDmaBufAndModifiers,
    SupportsExternalMemoryFd,
    SupportsExternalMemoryFuchsia,
    SupportsExternalMemoryHost,
    SupportsExternalSemaphoreCapabilities,
    SupportsExternalSemaphoreFd,
    SupportsExternalSemaphoreFuchsia,
    SupportsFormatFeatureFlags2,
    SupportsFoveatedRendering,
    SupportsFragmentShaderInterlockARB,
    SupportsFragmentShaderInterlockNV,
    SupportsFragmentShaderOrderingINTEL,
    SupportsFragmentShaderPixelInterlock,
    SupportsFragmentShadingRate,
    SupportsFullScreenExclusive,
    SupportsGeometryStreamsCapability,
    SupportsGetMemoryRequirements2,
    SupportsGGPFrameToken,
    SupportsGraphicsPipelineLibrary,
    SupportsHostImageCopy,
    SupportsHostQueryReset,
    SupportsImage2dViewOf3d,
    SupportsImageCubeArray,
    SupportsImageFormatList,
    SupportsImagelessFramebuffer,
    SupportsIncrementalPresent,
    SupportsIndexTypeUint8,
    SupportsLegacyDithering,
    SupportsLockSurfaceExtension,
    SupportsLogicOpDynamicState,
    SupportsMaintenance5,
    SupportsMemoryBudget,
    SupportsMixedReadWriteDepthStencilLayouts,
    SupportsMultiDrawIndirect,
    SupportsMultisampledRenderToSingleSampled,
    SupportsMultiview,
    SupportsNonConstantLoopIndexing,
    SupportsPipelineCreationFeedback,
    SupportsPipelineProtectedAccess,
    SupportsPipelineRobustness,
    SupportsPipelineStatisticsQuery,
    SupportsPortabilityEnumeration,
    SupportsPresentation,
    SupportsPrimitivesGeneratedQuery,
    SupportsPrimitiveTopologyListRestart,
    SupportsProtectedMemory,
    SupportsRasterizationOrderAttachmentAccess,
    SupportsRenderpass2,
    SupportsRenderPassLoadStoreOpNone,
    SupportsRenderPassStoreOpNone,
    SupportsRoundingModeRteFp16,
    SupportsRoundingModeRteFp32,
    SupportsRoundingModeRteFp64,
    SupportsRoundingModeRtzFp16,
    SupportsRoundingModeRtzFp32,
    SupportsRoundingModeRtzFp64,
    SupportsSampler2dViewOf3d,
    SupportsSamplerMirrorClampToEdge,
    SupportsShaderFloat16,
    SupportsShaderFloat64,
    SupportsShaderFramebufferFetch,
    SupportsShaderFramebufferFetchDepthStencil,
    SupportsShaderFramebufferFetchEXT,
    SupportsShaderFramebufferFetchNonCoherent,
    SupportsShaderFramebufferFetchNonCoherentEXT,
    SupportsShaderInt8,
    SupportsShaderNonSemanticInfo,
    SupportsShaderStencilExport,
    SupportsSharedPresentableImageExtension,
    SupportsSignedZeroInfNanPreserveFp16,
    SupportsSignedZeroInfNanPreserveFp32,
    SupportsSignedZeroInfNanPreserveFp64,
    SupportsSPIRV14,
    SupportsSurfaceCapabilities2Extension,
    SupportsSurfacelessQueryExtension,
    SupportsSurfaceMaintenance1,
    SupportsSurfaceProtectedCapabilitiesExtension,
    SupportsSurfaceProtectedSwapchains,
    SupportsSwapchainMaintenance1,
    SupportsSynchronization2,
    SupportsTimelineSemaphore,
    SupportsTimestampSurfaceAttribute,
    SupportsTransformFeedbackExtension,
    SupportsVertexInputDynamicState,
    SupportsYUVSamplerConversion,
    SupportsYuvTarget,
    SwapbuffersOnFlushOrFinishWithSingleBuffer,
    SyncAllVertexArraysToDefault,
    SyncDefaultVertexArraysToDefault,
    SyncMonolithicPipelinesToBlobCache,
    UnbindFBOBeforeSwitchingContext,
    UncurrentEglSurfaceUponSurfaceDestroy,
    UnfoldShortCircuits,
    UnpackLastRowSeparatelyForPaddingInclusion,
    UnpackOverlappingRowsSeparatelyUnpackBuffer,
    UnsizedSRGBReadPixelsDoesntTransform,
    UploadDataToIosurfacesWithStagingBuffers,
    UploadTextureDataInChunks,
    UseCullModeDynamicState,
    UseDepthBiasEnableDynamicState,
    UseDepthCompareOpDynamicState,
    UseDepthTestEnableDynamicState,
    UseDepthWriteEnableDynamicState,
    UseDualPipelineBlobCacheSlots,
    UseEmptyBlobsToEraseOldPipelineCacheFromBlobCache,
    UseFrontFaceDynamicState,
    UseIntermediateTextureForGenerateMipmap,
    UseMultipleDescriptorsForExternalFormats,
    UseNonZeroStencilWriteMaskStaticState,
    UsePrimitiveRestartEnableDynamicState,
    UseRasterizerDiscardEnableDynamicState,
    UseResetCommandBufferBitForSecondaryPools,
    UseShadowBuffersWhenAppropriate,
    UseStencilOpDynamicState,
    UseStencilTestEnableDynamicState,
    UseSystemMemoryForConstantBuffers,
    UseUnusedBlocksWithStandardOrSharedLayout,
    UseVertexInputBindingStrideDynamicState,
    UseVkEventForImageBarrier,
    UseVmaForImageSuballocation,
    VaryingsRequireMatchingPrecisionInSpirv,
    VerifyPipelineCacheInBlobCache,
    VertexIDDoesNotIncludeBaseVertex,
    WaitIdleBeforeSwapchainRecreation,
    WarmUpPipelineCacheAtLink,
    WrapSwitchInIfTrue,
    WriteHelperSampleMask,
    ZeroMaxLodWorkaround,

    InvalidEnum,
    EnumCount = InvalidEnum,
};

ANGLE_UTIL_EXPORT extern const char *GetFeatureName(Feature feature);

}  // namespace angle

#endif  // ANGLE_SRC_TESTS_TEST_UTIL_AUTOGEN_ANGLE_FEATURES_AUTOGEN_H_
