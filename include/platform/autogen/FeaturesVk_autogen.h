// GENERATED FILE - DO NOT EDIT.
// Generated by gen_features.py using data from vk_features.json.
//
// Copyright 2022 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// FeaturesVk_autogen.h: Optional features for the Vulkan renderer.

#ifndef ANGLE_PLATFORM_AUTOGEN_FEATURESVK_H_
#define ANGLE_PLATFORM_AUTOGEN_FEATURESVK_H_

#include "platform/Feature.h"

namespace angle
{

struct FeaturesVk : FeatureSetBase
{
    FeaturesVk();
    ~FeaturesVk();

    FeatureInfo appendAliasedMemoryDecorations = {
        "appendAliasedMemoryDecorations",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo bresenhamLineRasterization = {
        "bresenhamLineRasterization",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo provokingVertex = {
        "provokingVertex",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo forceFallbackFormat = {
        "forceFallbackFormat",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo clampPointSize = {
        "clampPointSize",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsDepthClampZeroOne = {
        "supportsDepthClampZeroOne",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo clampFragDepth = {
        "clampFragDepth",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo mutableMipmapTextureUpload = {
        "mutableMipmapTextureUpload",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo useVmaForImageSuballocation = {
        "useVmaForImageSuballocation",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsMemoryBudget = {
        "supportsMemoryBudget",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsRenderpass2 = {
        "supportsRenderpass2",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsIncrementalPresent = {
        "supportsIncrementalPresent",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsAndroidHardwareBuffer = {
        "supportsAndroidHardwareBuffer",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsGGPFrameToken = {
        "supportsGGPFrameToken",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsExternalMemoryFd = {
        "supportsExternalMemoryFd",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsExternalMemoryFuchsia = {
        "supportsExternalMemoryFuchsia",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsExternalFenceCapabilities = {
        "supportsExternalFenceCapabilities",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsExternalSemaphoreCapabilities = {
        "supportsExternalSemaphoreCapabilities",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsExternalSemaphoreFd = {
        "supportsExternalSemaphoreFd",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsExternalSemaphoreFuchsia = {
        "supportsExternalSemaphoreFuchsia",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsExternalFenceFd = {
        "supportsExternalFenceFd",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsAndroidNativeFenceSync = {
        "supportsAndroidNativeFenceSync",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsImageCubeArray = {
        "supportsImageCubeArray",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsPipelineStatisticsQuery = {
        "supportsPipelineStatisticsQuery",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsShaderStencilExport = {
        "supportsShaderStencilExport",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsYUVSamplerConversion = {
        "supportsYUVSamplerConversion",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo emulateTransformFeedback = {
        "emulateTransformFeedback",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsTransformFeedbackExtension = {
        "supportsTransformFeedbackExtension",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsGeometryStreamsCapability = {
        "supportsGeometryStreamsCapability",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsIndexTypeUint8 = {
        "supportsIndexTypeUint8",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsCustomBorderColor = {
        "supportsCustomBorderColor",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsMultiDrawIndirect = {
        "supportsMultiDrawIndirect",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsDepthStencilResolve = {
        "supportsDepthStencilResolve",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsDepthStencilIndependentResolveNone = {
        "supportsDepthStencilIndependentResolveNone",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsMultisampledRenderToSingleSampled = {
        "supportsMultisampledRenderToSingleSampled",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo preferMSRTSSFlagByDefault = {
        "preferMSRTSSFlagByDefault",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsMultiview = {
        "supportsMultiview",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo forceD16TexFilter = {
        "forceD16TexFilter",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo disableFlippingBlitWithCommand = {
        "disableFlippingBlitWithCommand",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo perFrameWindowSizeQuery = {
        "perFrameWindowSizeQuery",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo padBuffersToMaxVertexAttribStride = {
        "padBuffersToMaxVertexAttribStride",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsExternalMemoryDmaBufAndModifiers = {
        "supportsExternalMemoryDmaBufAndModifiers",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsExternalMemoryHost = {
        "supportsExternalMemoryHost",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo allocateNonZeroMemory = {
        "allocateNonZeroMemory",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo logMemoryReportCallbacks = {
        "logMemoryReportCallbacks",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo logMemoryReportStats = {
        "logMemoryReportStats",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo preferCPUForBufferSubData = {
        "preferCPUForBufferSubData",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo persistentlyMappedBuffers = {
        "persistentlyMappedBuffers",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo enablePreRotateSurfaces = {
        "enablePreRotateSurfaces",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo enablePrecisionQualifiers = {
        "enablePrecisionQualifiers",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo varyingsRequireMatchingPrecisionInSpirv = {
        "varyingsRequireMatchingPrecisionInSpirv",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo preferAggregateBarrierCalls = {
        "preferAggregateBarrierCalls",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo preferSkippingInvalidateForEmulatedFormats = {
        "preferSkippingInvalidateForEmulatedFormats",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo asyncCommandQueue = {
        "asyncCommandQueue",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo slowAsyncCommandQueueForTesting = {
        "slowAsyncCommandQueueForTesting",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsShaderFloat16 = {
        "supportsShaderFloat16",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsShaderInt8 = {
        "supportsShaderInt8",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsShaderFloat64 = {
        "supportsShaderFloat64",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo allowGenerateMipmapWithCompute = {
        "allowGenerateMipmapWithCompute",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsRenderPassStoreOpNone = {
        "supportsRenderPassStoreOpNone",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsRenderPassLoadStoreOpNone = {
        "supportsRenderPassLoadStoreOpNone",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo disallowMixedDepthStencilLoadOpNoneAndLoad = {
        "disallowMixedDepthStencilLoadOpNoneAndLoad",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsDepthClipControl = {
        "supportsDepthClipControl",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsPrimitiveTopologyListRestart = {
        "supportsPrimitiveTopologyListRestart",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsBlendOperationAdvanced = {
        "supportsBlendOperationAdvanced",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsBlendOperationAdvancedCoherent = {
        "supportsBlendOperationAdvancedCoherent",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo forceMaxUniformBufferSize16KB = {
        "forceMaxUniformBufferSize16KB",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsImageFormatList = {
        "supportsImageFormatList",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo allowMultisampledRenderToTextureEmulation = {
        "allowMultisampledRenderToTextureEmulation",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo enableMultisampledRenderToTexture = {
        "enableMultisampledRenderToTexture",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo waitIdleBeforeSwapchainRecreation = {
        "waitIdleBeforeSwapchainRecreation",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo forceTextureLodOffset1 = {
        "forceTextureLodOffset1",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo forceTextureLodOffset2 = {
        "forceTextureLodOffset2",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo forceTextureLodOffset3 = {
        "forceTextureLodOffset3",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo forceTextureLodOffset4 = {
        "forceTextureLodOffset4",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo forceNearestFiltering = {
        "forceNearestFiltering",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo forceNearestMipFiltering = {
        "forceNearestMipFiltering",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo compressVertexData = {
        "compressVertexData",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo preferDrawClearOverVkCmdClearAttachments = {
        "preferDrawClearOverVkCmdClearAttachments",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo emulatedPrerotation90 = {
        "emulatedPrerotation90",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo emulatedPrerotation180 = {
        "emulatedPrerotation180",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo emulatedPrerotation270 = {
        "emulatedPrerotation270",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo preferDriverUniformOverSpecConst = {
        "preferDriverUniformOverSpecConst",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo exposeNonConformantExtensionsAndVersions = {
        "exposeNonConformantExtensionsAndVersions",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo exposeES32ForTesting = {
        "exposeES32ForTesting",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo emulateR32fImageAtomicExchange = {
        "emulateR32fImageAtomicExchange",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo forceFragmentShaderPrecisionHighpToMediump = {
        "forceFragmentShaderPrecisionHighpToMediump",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo preferSubmitAtFBOBoundary = {
        "preferSubmitAtFBOBoundary",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo useMultipleDescriptorsForExternalFormats = {
        "useMultipleDescriptorsForExternalFormats",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsProtectedMemory = {
        "supportsProtectedMemory",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsHostQueryReset = {
        "supportsHostQueryReset",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsPipelineCreationFeedback = {
        "supportsPipelineCreationFeedback",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsPrimitivesGeneratedQuery = {
        "supportsPrimitivesGeneratedQuery",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSurfaceCapabilities2Extension = {
        "supportsSurfaceCapabilities2Extension",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSurfaceProtectedCapabilitiesExtension = {
        "supportsSurfaceProtectedCapabilitiesExtension",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSurfacelessQueryExtension = {
        "supportsSurfacelessQueryExtension",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSurfaceProtectedSwapchains = {
        "supportsSurfaceProtectedSwapchains",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo overrideSurfaceFormatRGB8ToRGBA8 = {
        "overrideSurfaceFormatRGB8ToRGBA8",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsSharedPresentableImageExtension = {
        "supportsSharedPresentableImageExtension",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsShaderFramebufferFetch = {
        "supportsShaderFramebufferFetch",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsShaderFramebufferFetchNonCoherent = {
        "supportsShaderFramebufferFetchNonCoherent",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsShaderFramebufferFetchDepthStencil = {
        "supportsShaderFramebufferFetchDepthStencil",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo permanentlySwitchToFramebufferFetchMode = {
        "permanentlySwitchToFramebufferFetchMode",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsLockSurfaceExtension = {
        "supportsLockSurfaceExtension",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo swapbuffersOnFlushOrFinishWithSingleBuffer = {
        "swapbuffersOnFlushOrFinishWithSingleBuffer",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo emulateDithering = {
        "emulateDithering",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo roundOutputAfterDithering = {
        "roundOutputAfterDithering",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo adjustClearColorPrecision = {
        "adjustClearColorPrecision",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo emulateAdvancedBlendEquations = {
        "emulateAdvancedBlendEquations",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo doubleDepthBiasConstantFactor = {
        "doubleDepthBiasConstantFactor",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo bottomLeftOriginPresentRegionRectangles = {
        "bottomLeftOriginPresentRegionRectangles",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo forceSubmitImmutableTextureUpdates = {
        "forceSubmitImmutableTextureUpdates",
        FeatureCategory::VulkanAppWorkarounds,
        &members,
    };

    FeatureInfo supportsSPIRV14 = {
        "supportsSPIRV14",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo retainSPIRVDebugInfo = {
        "retainSPIRVDebugInfo",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo warmUpPipelineCacheAtLink = {
        "warmUpPipelineCacheAtLink",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo preferDeviceLocalMemoryHostVisible = {
        "preferDeviceLocalMemoryHostVisible",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsExtendedDynamicState = {
        "supportsExtendedDynamicState",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo useVertexInputBindingStrideDynamicState = {
        "useVertexInputBindingStrideDynamicState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo useCullModeDynamicState = {
        "useCullModeDynamicState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo useFrontFaceDynamicState = {
        "useFrontFaceDynamicState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo useDepthTestEnableDynamicState = {
        "useDepthTestEnableDynamicState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo useDepthWriteEnableDynamicState = {
        "useDepthWriteEnableDynamicState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo useDepthCompareOpDynamicState = {
        "useDepthCompareOpDynamicState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo useStencilTestEnableDynamicState = {
        "useStencilTestEnableDynamicState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo useStencilOpDynamicState = {
        "useStencilOpDynamicState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsExtendedDynamicState2 = {
        "supportsExtendedDynamicState2",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo usePrimitiveRestartEnableDynamicState = {
        "usePrimitiveRestartEnableDynamicState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo useRasterizerDiscardEnableDynamicState = {
        "useRasterizerDiscardEnableDynamicState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo useDepthBiasEnableDynamicState = {
        "useDepthBiasEnableDynamicState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsLogicOpDynamicState = {
        "supportsLogicOpDynamicState",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsFragmentShadingRate = {
        "supportsFragmentShadingRate",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsFoveatedRendering = {
        "supportsFoveatedRendering",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo generateFragmentShadingRateAttchementWithCpu = {
        "generateFragmentShadingRateAttchementWithCpu",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsFragmentShaderPixelInterlock = {
        "supportsFragmentShaderPixelInterlock",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo explicitlyEnablePerSampleShading = {
        "explicitlyEnablePerSampleShading",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo explicitlyCastMediumpFloatTo16Bit = {
        "explicitlyCastMediumpFloatTo16Bit",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo forceContinuousRefreshOnSharedPresent = {
        "forceContinuousRefreshOnSharedPresent",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsImage2dViewOf3d = {
        "supportsImage2dViewOf3d",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSampler2dViewOf3d = {
        "supportsSampler2dViewOf3d",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsImagelessFramebuffer = {
        "supportsImagelessFramebuffer",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo preferLinearFilterForYUV = {
        "preferLinearFilterForYUV",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsYuvTarget = {
        "supportsYuvTarget",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo useNonZeroStencilWriteMaskStaticState = {
        "useNonZeroStencilWriteMaskStaticState",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo mapUnspecifiedColorSpaceToPassThrough = {
        "mapUnspecifiedColorSpaceToPassThrough",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsTimestampSurfaceAttribute = {
        "supportsTimestampSurfaceAttribute",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsRasterizationOrderAttachmentAccess = {
        "supportsRasterizationOrderAttachmentAccess",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo eglColorspaceAttributePassthrough = {
        "eglColorspaceAttributePassthrough",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsPipelineRobustness = {
        "supportsPipelineRobustness",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsVertexInputDynamicState = {
        "supportsVertexInputDynamicState",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsColorWriteEnable = {
        "supportsColorWriteEnable",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsPresentation = {
        "supportsPresentation",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsComputeTranscodeEtcToBc = {
        "supportsComputeTranscodeEtcToBc",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsGraphicsPipelineLibrary = {
        "supportsGraphicsPipelineLibrary",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo preferMonolithicPipelinesOverLibraries = {
        "preferMonolithicPipelinesOverLibraries",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo slowDownMonolithicPipelineCreationForTesting = {
        "slowDownMonolithicPipelineCreationForTesting",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo disablePipelineCacheLoadForTesting = {
        "disablePipelineCacheLoadForTesting",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo syncMonolithicPipelinesToBlobCache = {
        "syncMonolithicPipelinesToBlobCache",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo mergeProgramPipelineCachesToGlobalCache = {
        "mergeProgramPipelineCachesToGlobalCache",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo hasEffectivePipelineCacheSerialization = {
        "hasEffectivePipelineCacheSerialization",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo enableAsyncPipelineCacheCompression = {
        "enableAsyncPipelineCacheCompression",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsPipelineProtectedAccess = {
        "supportsPipelineProtectedAccess",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsMixedReadWriteDepthStencilLayouts = {
        "supportsMixedReadWriteDepthStencilLayouts",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsMaintenance5 = {
        "supportsMaintenance5",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSurfaceMaintenance1 = {
        "supportsSurfaceMaintenance1",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSwapchainMaintenance1 = {
        "supportsSwapchainMaintenance1",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsGetMemoryRequirements2 = {
        "supportsGetMemoryRequirements2",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsBindMemory2 = {
        "supportsBindMemory2",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSamplerMirrorClampToEdge = {
        "supportsSamplerMirrorClampToEdge",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo preferSubmitOnAnySamplesPassedQueryEnd = {
        "preferSubmitOnAnySamplesPassedQueryEnd",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo forceWaitForSubmissionToCompleteForQueryResult = {
        "forceWaitForSubmissionToCompleteForQueryResult",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo asyncCommandBufferResetAndGarbageCleanup = {
        "asyncCommandBufferResetAndGarbageCleanup",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo useResetCommandBufferBitForSecondaryPools = {
        "useResetCommandBufferBitForSecondaryPools",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo enablePipelineCacheDataCompression = {
        "enablePipelineCacheDataCompression",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsLegacyDithering = {
        "supportsLegacyDithering",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo limitSampleCountTo2 = {
        "limitSampleCountTo2",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsFullScreenExclusive = {
        "supportsFullScreenExclusive",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo forceDisableFullScreenExclusive = {
        "forceDisableFullScreenExclusive",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsPortabilityEnumeration = {
        "supportsPortabilityEnumeration",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo enablePortabilityEnumeration = {
        "enablePortabilityEnumeration",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo supportsTimelineSemaphore = {
        "supportsTimelineSemaphore",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsFormatFeatureFlags2 = {
        "supportsFormatFeatureFlags2",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsHostImageCopy = {
        "supportsHostImageCopy",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo allowHostImageCopyDespiteNonIdenticalLayout = {
        "allowHostImageCopyDespiteNonIdenticalLayout",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo enableParallelCompileAndLink = {
        "enableParallelCompileAndLink",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo preferHostCachedForNonStaticBufferUsage = {
        "preferHostCachedForNonStaticBufferUsage",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsExternalFormatResolve = {
        "supportsExternalFormatResolve",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo disableSeparateShaderObjects = {
        "disableSeparateShaderObjects",
        FeatureCategory::VulkanAppWorkarounds,
        &members,
    };

    FeatureInfo forceSampleUsageForAhbBackedImages = {
        "forceSampleUsageForAhbBackedImages",
        FeatureCategory::VulkanAppWorkarounds,
        &members,
    };

    FeatureInfo avoidOpSelectWithMismatchingRelaxedPrecision = {
        "avoidOpSelectWithMismatchingRelaxedPrecision",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo wrapSwitchInIfTrue = {
        "wrapSwitchInIfTrue",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo disableDepthStencilResolveThroughAttachment = {
        "disableDepthStencilResolveThroughAttachment",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo limitMaxStorageBufferSize = {
        "limitMaxStorageBufferSize",
        FeatureCategory::VulkanWorkarounds,
        &members,
    };

    FeatureInfo clDumpVkSpirv = {
        "clDumpVkSpirv",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo enableAdditionalBlendFactorsForDithering = {
        "enableAdditionalBlendFactorsForDithering",
        FeatureCategory::VulkanAppWorkarounds,
        &members,
    };

    FeatureInfo enableMergeClientAttribBuffer = {
        "enableMergeClientAttribBuffer",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsShaderNonSemanticInfo = {
        "supportsShaderNonSemanticInfo",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supports8BitStorageBuffer = {
        "supports8BitStorageBuffer",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supports8BitUniformAndStorageBuffer = {
        "supports8BitUniformAndStorageBuffer",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supports8BitPushConstant = {
        "supports8BitPushConstant",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supports16BitStorageBuffer = {
        "supports16BitStorageBuffer",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supports16BitUniformAndStorageBuffer = {
        "supports16BitUniformAndStorageBuffer",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supports16BitPushConstant = {
        "supports16BitPushConstant",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supports16BitInputOutput = {
        "supports16BitInputOutput",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo useVkEventForImageBarrier = {
        "useVkEventForImageBarrier",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSynchronization2 = {
        "supportsSynchronization2",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsDynamicRendering = {
        "supportsDynamicRendering",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsDynamicRenderingLocalRead = {
        "supportsDynamicRenderingLocalRead",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo preferDynamicRendering = {
        "preferDynamicRendering",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo preferCachedNoncoherentForDynamicStreamBufferUsage = {
        "preferCachedNoncoherentForDynamicStreamBufferUsage",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsRoundingModeRteFp16 = {
        "supportsRoundingModeRteFp16",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsRoundingModeRteFp32 = {
        "supportsRoundingModeRteFp32",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsRoundingModeRteFp64 = {
        "supportsRoundingModeRteFp64",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsRoundingModeRtzFp16 = {
        "supportsRoundingModeRtzFp16",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsRoundingModeRtzFp32 = {
        "supportsRoundingModeRtzFp32",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsRoundingModeRtzFp64 = {
        "supportsRoundingModeRtzFp64",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsDenormPreserveFp16 = {
        "supportsDenormPreserveFp16",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsDenormPreserveFp32 = {
        "supportsDenormPreserveFp32",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsDenormPreserveFp64 = {
        "supportsDenormPreserveFp64",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsDenormFtzFp16 = {
        "supportsDenormFtzFp16",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsDenormFtzFp32 = {
        "supportsDenormFtzFp32",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsDenormFtzFp64 = {
        "supportsDenormFtzFp64",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSignedZeroInfNanPreserveFp16 = {
        "supportsSignedZeroInfNanPreserveFp16",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSignedZeroInfNanPreserveFp32 = {
        "supportsSignedZeroInfNanPreserveFp32",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsSignedZeroInfNanPreserveFp64 = {
        "supportsSignedZeroInfNanPreserveFp64",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo preferDoubleBufferSwapchainOnFifoMode = {
        "preferDoubleBufferSwapchainOnFifoMode",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo useDualPipelineBlobCacheSlots = {
        "useDualPipelineBlobCacheSlots",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo useEmptyBlobsToEraseOldPipelineCacheFromBlobCache = {
        "useEmptyBlobsToEraseOldPipelineCacheFromBlobCache",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo hasBlobCacheThatEvictsOldItemsFirst = {
        "hasBlobCacheThatEvictsOldItemsFirst",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo verifyPipelineCacheInBlobCache = {
        "verifyPipelineCacheInBlobCache",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo descriptorSetCache = {
        "descriptorSetCache",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsImageCompressionControl = {
        "supportsImageCompressionControl",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsAstcSliced3d = {
        "supportsAstcSliced3d",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsTextureCompressionAstcHdr = {
        "supportsTextureCompressionAstcHdr",
        FeatureCategory::VulkanFeatures,
        &members,
    };

    FeatureInfo supportsImageCompressionControlSwapchain = {
        "supportsImageCompressionControlSwapchain",
        FeatureCategory::VulkanFeatures,
        &members,
    };

};

inline FeaturesVk::FeaturesVk()  = default;
inline FeaturesVk::~FeaturesVk() = default;

}  // namespace angle

#endif  // ANGLE_PLATFORM_AUTOGEN_FEATURESVK_H_
