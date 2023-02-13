// GENERATED FILE - DO NOT EDIT.
// Generated by gen_features.py using data from vk_features.json.
//
// Copyright 2022 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// FeaturesVk_autogen.h: Optional features for the Vulkan renderer.

#ifndef ANGLE_PLATFORM_FEATURESVK_H_
#define ANGLE_PLATFORM_FEATURESVK_H_

#include "platform/Feature.h"

namespace angle
{

struct FeaturesVk : FeatureSetBase
{
    FeaturesVk();
    ~FeaturesVk();

    FeatureInfo bresenhamLineRasterization = {
        "bresenhamLineRasterization",
        FeatureCategory::VulkanFeatures,
        "Enable Bresenham line rasterization via VK_EXT_line_rasterization extension",
        &members,
    };

    FeatureInfo provokingVertex = {
        "provokingVertex",
        FeatureCategory::VulkanFeatures,
        "Enable provoking vertex mode via VK_EXT_provoking_vertex extension",
        &members,
    };

    FeatureInfo forceFallbackFormat = {
        "forceFallbackFormat",
        FeatureCategory::VulkanWorkarounds,
        "Force a fallback format for angle_end2end_tests",
        &members,
    };

    FeatureInfo clampPointSize = {
        "clampPointSize", FeatureCategory::VulkanWorkarounds,
        "The point size range reported from the API is inconsistent with the actual behavior",
        &members, "http://anglebug.com/2970"};

    FeatureInfo depthClamping = {
        "depthClamping", FeatureCategory::VulkanWorkarounds,
        "The depth value is not clamped to [0,1] for floating point depth buffers.", &members,
        "http://anglebug.com/3970"};

    FeatureInfo mutableMipmapTextureUpload = {
        "mutableMipmapTextureUpload", FeatureCategory::VulkanFeatures,
        "Enable uploading the previously defined mutable mipmap texture.", &members,
        "https://anglebug.com/7308"};

    FeatureInfo supportsMemoryBudget = {
        "supportsMemoryBudget",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_EXT_memory_budget extension.",
        &members,
    };

    FeatureInfo supportsRenderpass2 = {
        "supportsRenderpass2",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_KHR_create_renderpass2 extension",
        &members,
    };

    FeatureInfo supportsIncrementalPresent = {
        "supportsIncrementalPresent",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_KHR_incremental_present extension",
        &members,
    };

    FeatureInfo supportsAndroidHardwareBuffer = {
        "supportsAndroidHardwareBuffer",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_ANDROID_external_memory_android_hardware_buffer extension",
        &members,
    };

    FeatureInfo supportsGGPFrameToken = {
        "supportsGGPFrameToken",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_GGP_frame_token extension",
        &members,
    };

    FeatureInfo supportsExternalMemoryFd = {
        "supportsExternalMemoryFd",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_KHR_external_memory_fd extension",
        &members,
    };

    FeatureInfo supportsExternalMemoryFuchsia = {
        "supportsExternalMemoryFuchsia",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_FUCHSIA_external_memory extension",
        &members,
    };

    FeatureInfo supportsFilteringPrecision = {
        "supportsFilteringPrecision",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_GOOGLE_sampler_filtering_precision extension",
        &members,
    };

    FeatureInfo supportsExternalFenceCapabilities = {
        "supportsExternalFenceCapabilities",
        FeatureCategory::VulkanFeatures,
        "VkInstance supports the VK_KHR_external_fence_capabilities extension",
        &members,
    };

    FeatureInfo supportsExternalSemaphoreCapabilities = {
        "supportsExternalSemaphoreCapabilities",
        FeatureCategory::VulkanFeatures,
        "VkInstance supports the VK_KHR_external_semaphore_capabilities extension",
        &members,
    };

    FeatureInfo supportsExternalSemaphoreFd = {
        "supportsExternalSemaphoreFd",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_KHR_external_semaphore_fd extension",
        &members,
    };

    FeatureInfo supportsExternalSemaphoreFuchsia = {
        "supportsExternalSemaphoreFuchsia",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_FUCHSIA_external_semaphore extension",
        &members,
    };

    FeatureInfo supportsExternalFenceFd = {
        "supportsExternalFenceFd", FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_KHR_external_fence_fd extension", &members,
        "http://anglebug.com/2517"};

    FeatureInfo supportsAndroidNativeFenceSync = {
        "supportsAndroidNativeFenceSync", FeatureCategory::VulkanFeatures,
        "VkDevice supports the EGL_ANDROID_native_fence_sync extension", &members,
        "http://anglebug.com/2517"};

    FeatureInfo supportsImageCubeArray = {"supportsImageCubeArray", FeatureCategory::VulkanFeatures,
                                          "VkDevice supports the imageCubeArray feature properly",
                                          &members, "http://anglebug.com/3584"};

    FeatureInfo supportsPipelineStatisticsQuery = {
        "supportsPipelineStatisticsQuery", FeatureCategory::VulkanFeatures,
        "VkDevice supports the pipelineStatisticsQuery feature", &members,
        "http://anglebug.com/5430"};

    FeatureInfo supportsShaderStencilExport = {
        "supportsShaderStencilExport",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_EXT_shader_stencil_export extension",
        &members,
    };

    FeatureInfo supportsYUVSamplerConversion = {
        "supportsYUVSamplerConversion",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_KHR_sampler_ycbcr_conversion extension",
        &members,
    };

    FeatureInfo emulateTransformFeedback = {
        "emulateTransformFeedback", FeatureCategory::VulkanFeatures,
        "Emulate transform feedback as the VK_EXT_transform_feedback is not present.", &members,
        "http://anglebug.com/3205"};

    FeatureInfo supportsTransformFeedbackExtension = {
        "supportsTransformFeedbackExtension", FeatureCategory::VulkanFeatures,
        "Transform feedback uses the VK_EXT_transform_feedback extension.", &members,
        "http://anglebug.com/3206"};

    FeatureInfo supportsGeometryStreamsCapability = {
        "supportsGeometryStreamsCapability", FeatureCategory::VulkanFeatures,
        "Implementation supports the GeometryStreams SPIR-V capability.", &members,
        "http://anglebug.com/3206"};

    FeatureInfo supportsIndexTypeUint8 = {"supportsIndexTypeUint8", FeatureCategory::VulkanFeatures,
                                          "VkDevice supports the VK_EXT_index_type_uint8 extension",
                                          &members, "http://anglebug.com/4405"};

    FeatureInfo supportsCustomBorderColor = {
        "supportsCustomBorderColor", FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_EXT_custom_border_color extension", &members,
        "http://anglebug.com/3577"};

    FeatureInfo supportsMultiDrawIndirect = {
        "supportsMultiDrawIndirect", FeatureCategory::VulkanFeatures,
        "VkDevice supports the multiDrawIndirect extension", &members, "http://anglebug.com/6439"};

    FeatureInfo supportsDepthStencilResolve = {"supportsDepthStencilResolve",
                                               FeatureCategory::VulkanFeatures,
                                               "VkDevice supports the VK_KHR_depth_stencil_resolve "
                                               "extension with the independentResolveNone feature",
                                               &members, "http://anglebug.com/4836"};

    FeatureInfo supportsMultisampledRenderToSingleSampledGOOGLEX = {
        "supportsMultisampledRenderToSingleSampledGOOGLEX", FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_GOOGLEX_multisampled_render_to_single_sampled extension",
        &members, "http://anglebug.com/4836"};

    FeatureInfo supportsMultisampledRenderToSingleSampled = {
        "supportsMultisampledRenderToSingleSampled", FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_EXT_multisampled_render_to_single_sampled extension", &members,
        "http://anglebug.com/4836"};

    FeatureInfo supportsMultiview = {"supportsMultiview", FeatureCategory::VulkanFeatures,
                                     "VkDevice supports the VK_KHR_multiview extension", &members,
                                     "http://anglebug.com/6048"};

    FeatureInfo forceD16TexFilter = {
        "forceD16TexFilter", FeatureCategory::VulkanWorkarounds,
        "VK_FORMAT_D16_UNORM does not support VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT, "
        "which prevents OES_depth_texture from being supported.",
        &members, "http://anglebug.com/3452"};

    FeatureInfo disableFlippingBlitWithCommand = {
        "disableFlippingBlitWithCommand", FeatureCategory::VulkanWorkarounds,
        "vkCmdBlitImage with flipped coordinates blits incorrectly.", &members,
        "http://anglebug.com/3498"};

    FeatureInfo perFrameWindowSizeQuery = {
        "perFrameWindowSizeQuery", FeatureCategory::VulkanWorkarounds,
        "Vulkan swapchain is not returning VK_ERROR_OUT_OF_DATE when window resizing", &members,
        "http://anglebug.com/3623, http://anglebug.com/3624, http://anglebug.com/3625"};

    FeatureInfo padBuffersToMaxVertexAttribStride = {
        "padBuffersToMaxVertexAttribStride", FeatureCategory::VulkanWorkarounds,
        "Vulkan considers vertex attribute accesses to count up to the last multiple of the "
        "stride. This additional access supports AMD's robust buffer access implementation. "
        "AMDVLK in particular will return incorrect values when the vertex access extends into "
        "the range that would be the stride padding and the buffer is too small. "
        "This workaround limits GL_MAX_VERTEX_ATTRIB_STRIDE to a maximum value and "
        "pads up every buffer allocation size to be a multiple of the maximum stride.",
        &members, "http://anglebug.com/4428"};

    FeatureInfo supportsExternalMemoryDmaBufAndModifiers = {
        "supportsExternalMemoryDmaBufAndModifiers", FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_EXT_external_memory_dma_buf and VK_EXT_image_drm_format_modifier "
        "extensions",
        &members, "http://anglebug.com/6248"};

    FeatureInfo supportsExternalMemoryHost = {
        "supportsExternalMemoryHost",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_EXT_external_memory_host extension",
        &members,
    };

    FeatureInfo allocateNonZeroMemory = {
        "allocateNonZeroMemory", FeatureCategory::VulkanFeatures,
        "Fill new allocations with non-zero values to flush out errors.", &members,
        "http://anglebug.com/4384"};

    FeatureInfo logMemoryReportCallbacks = {
        "logMemoryReportCallbacks",
        FeatureCategory::VulkanFeatures,
        "Log each callback from VK_EXT_device_memory_report",
        &members,
    };

    FeatureInfo logMemoryReportStats = {
        "logMemoryReportStats",
        FeatureCategory::VulkanFeatures,
        "Log stats from VK_EXT_device_memory_report each swap",
        &members,
    };

    FeatureInfo preferCPUForBufferSubData = {
        "preferCPUForBufferSubData", FeatureCategory::VulkanFeatures,
        "Prefer use CPU to do bufferSubData instead of staged update.", &members,
        "http://issuetracker.google.com/200067929"};

    FeatureInfo persistentlyMappedBuffers = {
        "persistentlyMappedBuffers", FeatureCategory::VulkanFeatures,
        "Persistently map buffer memory to reduce map/unmap IOCTL overhead.", &members,
        "http://anglebug.com/2162"};

    FeatureInfo enablePreRotateSurfaces = {"enablePreRotateSurfaces",
                                           FeatureCategory::VulkanFeatures,
                                           "Enable Android pre-rotation for landscape applications",
                                           &members, "http://anglebug.com/3502"};

    FeatureInfo enablePrecisionQualifiers = {
        "enablePrecisionQualifiers", FeatureCategory::VulkanFeatures,
        "Enable precision qualifiers in shaders", &members, "http://anglebug.com/3078"};

    FeatureInfo varyingsRequireMatchingPrecisionInSpirv = {
        "varyingsRequireMatchingPrecisionInSpirv", FeatureCategory::VulkanWorkarounds,
        "Add additional SPIRV instructions to make sure precision "
        "between shader stages match with each other",
        &members, "http://anglebug.com/7488"};

    FeatureInfo preferAggregateBarrierCalls = {
        "preferAggregateBarrierCalls", FeatureCategory::VulkanWorkarounds,
        "Single barrier call is preferred over multiple calls with "
        "fine grained pipeline stage dependency information",
        &members, "http://anglebug.com/4633"};

    FeatureInfo preferSkippingInvalidateForEmulatedFormats = {
        "preferSkippingInvalidateForEmulatedFormats", FeatureCategory::VulkanWorkarounds,
        "Skipping invalidate is preferred for emulated formats that have extra channels over "
        "re-clearing the image",
        &members, "http://anglebug.com/6860"};

    FeatureInfo asyncCommandQueue = {"asyncCommandQueue", FeatureCategory::VulkanFeatures,
                                     "Use CommandQueue worker thread to dispatch work to GPU.",
                                     &members, "http://anglebug.com/4324"};

    FeatureInfo slowAsyncCommandQueueForTesting = {
        "slowAsyncCommandQueueForTesting", FeatureCategory::VulkanWorkarounds,
        "Artificially slow down async command queue for threading testing", &members,
        "https://anglebug.com/6574"};

    FeatureInfo supportsShaderFloat16 = {
        "supportsShaderFloat16", FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_KHR_shader_float16_int8 extension "
        "and has the shaderFloat16 feature",
        &members, "http://anglebug.com/4551"};

    FeatureInfo allowGenerateMipmapWithCompute = {
        "allowGenerateMipmapWithCompute", FeatureCategory::VulkanFeatures,
        "Use the compute path to generate mipmaps on devices that meet the minimum requirements, "
        "and the performance is better.",
        &members, "http://anglebug.com/4551"};

    FeatureInfo supportsRenderPassStoreOpNone = {
        "supportsRenderPassStoreOpNone", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_QCOM_render_pass_store_ops extension.", &members,
        "http://anglebug.com/5055"};

    FeatureInfo supportsRenderPassLoadStoreOpNone = {
        "supportsRenderPassLoadStoreOpNone", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_load_store_op_none extension.", &members,
        "http://anglebug.com/5371"};

    FeatureInfo disallowMixedDepthStencilLoadOpNoneAndLoad = {
        "disallowMixedDepthStencilLoadOpNoneAndLoad", FeatureCategory::VulkanWorkarounds,
        "Disallow use of LOAD_OP_NONE for only one of the depth or stencil aspects of a "
        "depth/stencil attachment",
        &members, "http://anglebug.com/7370"};

    FeatureInfo supportsDepthClipControl = {
        "supportsDepthClipControl", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_depth_clip_control extension.", &members,
        "http://anglebug.com/5421"};

    FeatureInfo supportsPrimitiveTopologyListRestart = {
        "supportsPrimitiveTopologyListRestart", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_primitive_topology_list_restart extension.", &members,
        "http://anglebug.com/3832"};

    FeatureInfo supportsBlendOperationAdvanced = {
        "supportsBlendOperationAdvanced", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_blend_operation_advanced extension.", &members,
        "http://anglebug.com/3586"};

    FeatureInfo forceMaxUniformBufferSize16KB = {
        "forceMaxUniformBufferSize16KB", FeatureCategory::VulkanWorkarounds,
        "Force max uniform buffer size to 16K on some device due to bug", &members,
        "https://issuetracker.google.com/161903006"};

    FeatureInfo supportsImageFormatList = {
        "supportsImageFormatList", FeatureCategory::VulkanFeatures,
        "Enable VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT by default for ICDs "
        "that support VK_KHR_image_format_list",
        &members, "http://anglebug.com/5281"};

    FeatureInfo enableMultisampledRenderToTexture = {
        "enableMultisampledRenderToTexture", FeatureCategory::VulkanWorkarounds,
        "Expose EXT_multisampled_render_to_texture", &members, "http://anglebug.com/4937"};

    FeatureInfo deferFlushUntilEndRenderPass = {
        "deferFlushUntilEndRenderPass", FeatureCategory::VulkanWorkarounds,
        "Allow glFlush to be deferred until renderpass ends", &members,
        "https://issuetracker.google.com/issues/166475273"};

    FeatureInfo waitIdleBeforeSwapchainRecreation = {
        "waitIdleBeforeSwapchainRecreation", FeatureCategory::VulkanWorkarounds,
        "Before passing an oldSwapchain to VkSwapchainCreateInfoKHR, wait for queue to be idle. "
        "Works around a bug on platforms which destroy oldSwapchain in vkCreateSwapchainKHR.",
        &members, "http://anglebug.com/5061"};

    FeatureInfo forceTextureLodOffset1 = {
        "forceTextureLodOffset1",
        FeatureCategory::VulkanWorkarounds,
        "Increase the minimum texture level-of-detail by 1 when sampling.",
        &members,
    };

    FeatureInfo forceTextureLodOffset2 = {
        "forceTextureLodOffset2",
        FeatureCategory::VulkanWorkarounds,
        "Increase the minimum texture level-of-detail by 2 when sampling.",
        &members,
    };

    FeatureInfo forceTextureLodOffset3 = {
        "forceTextureLodOffset3",
        FeatureCategory::VulkanWorkarounds,
        "Increase the minimum texture level-of-detail by 3 when sampling.",
        &members,
    };

    FeatureInfo forceTextureLodOffset4 = {
        "forceTextureLodOffset4",
        FeatureCategory::VulkanWorkarounds,
        "Increase the minimum texture level-of-detail by 4 when sampling.",
        &members,
    };

    FeatureInfo forceNearestFiltering = {
        "forceNearestFiltering",
        FeatureCategory::VulkanWorkarounds,
        "Force nearest filtering when sampling.",
        &members,
    };

    FeatureInfo forceNearestMipFiltering = {
        "forceNearestMipFiltering",
        FeatureCategory::VulkanWorkarounds,
        "Force nearest mip filtering when sampling.",
        &members,
    };

    FeatureInfo compressVertexData = {
        "compressVertexData",
        FeatureCategory::VulkanWorkarounds,
        "Compress vertex data to smaller data types when "
        "possible. Using this feature makes ANGLE non-conformant.",
        &members,
    };

    FeatureInfo preferDrawClearOverVkCmdClearAttachments = {
        "preferDrawClearOverVkCmdClearAttachments", FeatureCategory::VulkanWorkarounds,
        "On some hardware, clear using a draw call instead of vkCmdClearAttachments in the middle "
        "of render pass due to bugs",
        &members, "https://issuetracker.google.com/166809097"};

    FeatureInfo emulatedPrerotation90 = {"emulatedPrerotation90", FeatureCategory::VulkanFeatures,
                                         "Emulate 90-degree prerotation.", &members,
                                         "http://anglebug.com/4901"};

    FeatureInfo emulatedPrerotation180 = {"emulatedPrerotation180", FeatureCategory::VulkanFeatures,
                                          "Emulate 180-degree prerotation.", &members,
                                          "http://anglebug.com/4901"};

    FeatureInfo emulatedPrerotation270 = {"emulatedPrerotation270", FeatureCategory::VulkanFeatures,
                                          "Emulate 270-degree prerotation.", &members,
                                          "http://anglebug.com/4901"};

    FeatureInfo preferDriverUniformOverSpecConst = {
        "preferDriverUniformOverSpecConst", FeatureCategory::VulkanFeatures,
        "Prefer using driver uniforms instead of specialization constants.", &members,
        "http://anglebug.com/7406"};

    FeatureInfo exposeNonConformantExtensionsAndVersions = {
        "exposeNonConformantExtensionsAndVersions", FeatureCategory::VulkanWorkarounds,
        "Expose GLES versions and extensions that are not conformant.", &members,
        "http://anglebug.com/5375"};

    FeatureInfo emulateR32fImageAtomicExchange = {
        "emulateR32fImageAtomicExchange", FeatureCategory::VulkanWorkarounds,
        "Emulate r32f images with r32ui to support imageAtomicExchange.", &members,
        "http://anglebug.com/5535"};

    FeatureInfo supportsNegativeViewport = {
        "supportsNegativeViewport",
        FeatureCategory::VulkanFeatures,
        "The driver supports inverting the viewport with a negative height.",
        &members,
    };

    FeatureInfo forceFragmentShaderPrecisionHighpToMediump = {
        "forceFragmentShaderPrecisionHighpToMediump", FeatureCategory::VulkanWorkarounds,
        "Forces highp precision in fragment shader to mediump.", &members,
        "https://issuetracker.google.com/184850002"};

    FeatureInfo preferSubmitAtFBOBoundary = {
        "preferSubmitAtFBOBoundary", FeatureCategory::VulkanWorkarounds,
        "Submit commands to driver at each FBO boundary for performance improvements.", &members,
        "https://issuetracker.google.com/187425444"};

    FeatureInfo useMultipleDescriptorsForExternalFormats = {
        "useMultipleDescriptorsForExternalFormats", FeatureCategory::VulkanWorkarounds,
        "Return a default descriptor count for external formats.", &members,
        "http://anglebug.com/6141"};

    FeatureInfo supportsProtectedMemory = {
        "supportsProtectedMemory", FeatureCategory::VulkanFeatures,
        "VkDevice supports protected memory", &members, "http://anglebug.com/3965"};

    FeatureInfo supportsHostQueryReset = {"supportsHostQueryReset", FeatureCategory::VulkanFeatures,
                                          "VkDevice supports VK_EXT_host_query_reset extension",
                                          &members, "http://anglebug.com/6692"};

    FeatureInfo supportsPipelineCreationCacheControl = {
        "supportsPipelineCreationCacheControl", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_pipeline_creation_cache_control extension", &members,
        "http://anglebug.com/5881"};

    FeatureInfo supportsPipelineCreationFeedback = {
        "supportsPipelineCreationFeedback", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_pipeline_creation_feedback extension", &members,
        "http://anglebug.com/5881"};

    FeatureInfo supportsPrimitivesGeneratedQuery = {
        "supportsPrimitivesGeneratedQuery", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_primitives_generated_query extension", &members,
        "http://anglebug.com/5430"};

    FeatureInfo supportsSurfaceCapabilities2Extension = {
        "supportsSurfaceCapabilities2Extension",
        FeatureCategory::VulkanFeatures,
        "VkInstance supports the VK_KHR_get_surface_capabilities2 extension",
        &members,
    };

    FeatureInfo supportsSurfaceProtectedCapabilitiesExtension = {
        "supportsSurfaceProtectedCapabilitiesExtension",
        FeatureCategory::VulkanFeatures,
        "VkInstance supports the VK_KHR_surface_protected_capabilities extension",
        &members,
    };

    FeatureInfo supportsSurfacelessQueryExtension = {
        "supportsSurfacelessQueryExtension",
        FeatureCategory::VulkanFeatures,
        "VkInstance supports the VK_GOOGLE_surfaceless_query extension",
        &members,
    };

    FeatureInfo supportsSurfaceProtectedSwapchains = {
        "supportsSurfaceProtectedSwapchains",
        FeatureCategory::VulkanFeatures,
        "VkSurface supportsProtected for protected swapchains",
        &members,
    };

    FeatureInfo overrideSurfaceFormatRGB8ToRGBA8 = {
        "overrideSurfaceFormatRGB8ToRGBA8", FeatureCategory::VulkanWorkarounds,
        "Override surface format GL_RGB8 to GL_RGBA8", &members, "http://anglebug.com/6651"};

    FeatureInfo supportsSharedPresentableImageExtension = {
        "supportsSharedPresentableImageExtension",
        FeatureCategory::VulkanFeatures,
        "VkSurface supports the VK_KHR_shared_presentable_images extension",
        &members,
    };

    FeatureInfo supportsShaderFramebufferFetch = {
        "supportsShaderFramebufferFetch",
        FeatureCategory::VulkanFeatures,
        "Whether the Vulkan backend supports coherent framebuffer fetch",
        &members,
    };

    FeatureInfo supportsShaderFramebufferFetchNonCoherent = {
        "supportsShaderFramebufferFetchNonCoherent",
        FeatureCategory::VulkanFeatures,
        "Whether the Vulkan backend supports non-coherent framebuffer fetch",
        &members,
    };

    FeatureInfo permanentlySwitchToFramebufferFetchMode = {
        "permanentlySwitchToFramebufferFetchMode",
        FeatureCategory::VulkanFeatures,
        "Whether the context should permanently switch to framebuffer fetch mode on first "
        "encounter",
        &members,
    };

    FeatureInfo supportsLockSurfaceExtension = {
        "supportsLockSurfaceExtension",
        FeatureCategory::VulkanFeatures,
        "Surface supports the EGL_KHR_lock_surface3 extension",
        &members,
    };

    FeatureInfo swapbuffersOnFlushOrFinishWithSingleBuffer = {
        "swapbuffersOnFlushOrFinishWithSingleBuffer", FeatureCategory::VulkanFeatures,
        "Bypass deferredFlush with calling swapbuffers on flush or finish when in Shared "
        "Present mode",
        &members, "http://anglebug.com/6878"};

    FeatureInfo emulateDithering = {"emulateDithering", FeatureCategory::VulkanFeatures,
                                    "Emulate OpenGL dithering", &members,
                                    "http://anglebug.com/6755"};

    FeatureInfo roundOutputAfterDithering = {
        "roundOutputAfterDithering", FeatureCategory::VulkanWorkarounds,
        "Round output after dithering to workaround a driver bug that rounds the output up",
        &members, "http://anglebug.com/6953"};

    FeatureInfo emulateAdvancedBlendEquations = {
        "emulateAdvancedBlendEquations", FeatureCategory::VulkanFeatures,
        "Emulate GL_KHR_blend_equation_advanced", &members, "http://anglebug.com/3586"};

    FeatureInfo precisionSafeDivision = {
        "precisionSafeDivision",
        FeatureCategory::VulkanWorkarounds,
        "Special case handling for platforms that do not generate 1.0f even when the dividend and "
        "divisor have the same value",
        &members,
    };

    FeatureInfo bottomLeftOriginPresentRegionRectangles = {
        "bottomLeftOriginPresentRegionRectangles",
        FeatureCategory::VulkanWorkarounds,
        "On some platforms present region rectangles are expected to have a bottom-left origin, "
        "instead of top-left origin as from spec",
        &members,
    };

    FeatureInfo forceSubmitImmutableTextureUpdates = {
        "forceSubmitImmutableTextureUpdates", FeatureCategory::VulkanAppWorkarounds,
        "Force submit updates to immutable textures", &members, "http://anglebug.com/6929"};

    FeatureInfo retainSPIRVDebugInfo = {"retainSPIRVDebugInfo", FeatureCategory::VulkanFeatures,
                                        "Retain debug info in SPIR-V blob.", &members,
                                        "http://anglebug.com/5901"};

    FeatureInfo warmUpPipelineCacheAtLink = {
        "warmUpPipelineCacheAtLink", FeatureCategory::VulkanFeatures,
        "Warm up the Vulkan pipeline cache at link time", &members, "http://anglebug.com/5881"};

    FeatureInfo preferDeviceLocalMemoryHostVisible = {
        "preferDeviceLocalMemoryHostVisible", FeatureCategory::VulkanFeatures,
        "Prefer adding HOST_VISIBLE flag for DEVICE_LOCAL memory when picking memory types",
        &members, "http://anglebug.com/7047"};

    FeatureInfo forceStaticVertexStrideState = {
        "forceStaticVertexStrideState", FeatureCategory::VulkanWorkarounds,
        "Force static state for VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT due to "
        "driver bugs",
        &members, "https://bugs.fuchsia.dev/p/fuchsia/issues/detail?id=107106"};

    FeatureInfo supportsExtendedDynamicState = {
        "supportsExtendedDynamicState", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_extended_dynamic_state extension", &members,
        "http://anglebug.com/5906"};

    FeatureInfo supportsExtendedDynamicState2 = {
        "supportsExtendedDynamicState2", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_extended_dynamic_state2 extension", &members,
        "http://anglebug.com/5906"};

    FeatureInfo supportsLogicOpDynamicState = {
        "supportsLogicOpDynamicState", FeatureCategory::VulkanFeatures,
        "VkDevice supports the logicOp feature of VK_EXT_extended_dynamic_state2 extension",
        &members, "http://anglebug.com/3862"};

    FeatureInfo supportsFragmentShadingRate = {
        "supportsFragmentShadingRate", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_KHR_fragment_shading_rate extension", &members,
        "http://anglebug.com/7172"};

    FeatureInfo supportsFragmentShaderPixelInterlock = {
        "supportsFragmentShaderPixelInterlock",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_EXT_fragment_shader_interlock extension "
        "and has the fragmentShaderPixelInterlock feature",
        &members,
    };

    FeatureInfo explicitlyEnablePerSampleShading = {
        "explicitlyEnablePerSampleShading", FeatureCategory::VulkanWorkarounds,
        "Explicitly enable per-sample shading if the fragment shader contains the "
        "sample qualifier",
        &members, "http://anglebug.com/6876"};

    FeatureInfo forceContinuousRefreshOnSharedPresent = {
        "forceContinuousRefreshOnSharedPresent", FeatureCategory::VulkanFeatures,
        "Force to create vulkan swapchain with continuous refresh on shared present", &members,
        "https://issuetracker.google.com/229267970"};

    FeatureInfo supportsImage2dViewOf3d = {
        "supportsImage2dViewOf3d", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_image_2d_view_of_3d", &members, "https://anglebug.com/7320"};

    FeatureInfo supportsImagelessFramebuffer = {
        "supportsImagelessFramebuffer", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_KHR_imageless_framebuffer extension", &members,
        "http://anglebug.com/7553"};

    FeatureInfo preferLinearFilterForYUV = {
        "preferLinearFilterForYUV", FeatureCategory::VulkanFeatures,
        "Prefer to use VK_FILTER_LINEAR for VkSamplerYcbcrConversion", &members,
        "https://anglebug.com/7382"};

    FeatureInfo supportsYuvTarget = {
        "supportsYuvTarget",
        FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_ANDROID_render_to_external_format and VK_EXT_ycbcr_attachment",
        &members,
    };

    FeatureInfo useNonZeroStencilWriteMaskStaticState = {
        "useNonZeroStencilWriteMaskStaticState", FeatureCategory::VulkanWorkarounds,
        "Work around a driver bug where 0 in stencil write mask static state would make the "
        "corresponding dynamic state malfunction in the presence of discard or alpha to coverage",
        &members, "http://anglebug.com/7556"};

    FeatureInfo mapUnspecifiedColorSpaceToPassThrough = {
        "mapUnspecifiedColorSpaceToPassThrough",
        FeatureCategory::VulkanFeatures,
        "Use VK_COLOR_SPACE_PASS_THROUGH_EXT for EGL_NONE or unspecifed color "
        "spaces",
        &members,
    };

    FeatureInfo supportsTimestampSurfaceAttribute = {
        "supportsTimestampSurfaceAttribute", FeatureCategory::VulkanFeatures,
        "Platform supports setting frame timestamp surface attribute", &members,
        "https://anglebug.com/7489"};

    FeatureInfo supportsRasterizationOrderAttachmentAccess = {
        "supportsRasterizationOrderAttachmentAccess", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_rasterization_order_attachment_access extension", &members,
        "https://anglebug.com/7604"};

    FeatureInfo eglColorspaceAttributePassthrough = {
        "eglColorspaceAttributePassthrough", FeatureCategory::VulkanFeatures,
        "Support passthrough of EGL colorspace attribute values", &members,
        "https://anglebug.com/7319"};

    FeatureInfo supportsPipelineRobustness = {
        "supportsPipelineRobustness", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_pipeline_robustness extension", &members,
        "https://anglebug.com/5845"};

    FeatureInfo supportsVertexInputDynamicState = {
        "supportsVertexInputDynamicState", FeatureCategory::VulkanFeatures,
        "VkDevice supports VK_EXT_vertex_input_dynamic_state extension", &members,
        "https://anglebug.com/7162"};

    FeatureInfo supportsColorWriteEnable = {"supportsColorWriteEnable",
                                            FeatureCategory::VulkanFeatures,
                                            "VkDevice supports VK_EXT_color_write_enable extension",
                                            &members, "https://anglebug.com/7161"};

    FeatureInfo supportsPresentation = {
        "supportsPresentation",
        FeatureCategory::VulkanFeatures,
        "VkDisplay supports presentation through a present family queue",
        &members,
    };

    FeatureInfo supportsComputeTranscodeEtcToBc = {
        "supportsComputeTranscodeEtcToBc",
        FeatureCategory::VulkanFeatures,
        "supports compute shader transcode etc format to bc format",
        &members,
    };

    FeatureInfo supportsGraphicsPipelineLibrary = {
        "supportsGraphicsPipelineLibrary", FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_EXT_graphics_pipeline_library extension", &members,
        "https://anglebug.com/7369"};

    FeatureInfo preferMonolithicPipelinesOverLibraries = {
        "preferMonolithicPipelinesOverLibraries", FeatureCategory::VulkanWorkarounds,
        "Whether monolithic pipelines perform significantly better than libraries", &members,
        "https://anglebug.com/7369"};

    FeatureInfo slowDownMonolithicPipelineCreationForTesting = {
        "slowDownMonolithicPipelineCreationForTesting", FeatureCategory::VulkanWorkarounds,
        "Artificially slow down async monolithic pipeline creation for threading testing", &members,
        "https://anglebug.com/7369"};

    FeatureInfo syncMonolithicPipelinesToBlobCache = {
        "syncMonolithicPipelinesToBlobCache", FeatureCategory::VulkanWorkarounds,
        "Whether it's beneficial to store monolithic pipelines in the blob cache when "
        "VK_EXT_graphics_pipeline_library is in use.  Otherwise the libraries are stored "
        "only, and monolithic pipelines are recreated on every run",
        &members, "https://anglebug.com/7369"};

    FeatureInfo mergeProgramPipelineCachesToGlobalCache = {
        "mergeProgramPipelineCachesToGlobalCache", FeatureCategory::VulkanWorkarounds,
        "Whether it's beneficial to merge the pipeline cache for the shaders subset of the "
        "pipeline into the monolithic pipeline cache.  Only useful on platforms where "
        "monolithic pipelines can reuse blobs from partial pipelines",
        &members, "https://anglebug.com/7369"};

    FeatureInfo hasEffectivePipelineCacheSerialization = {
        "hasEffectivePipelineCacheSerialization", FeatureCategory::VulkanFeatures,
        "Whether the implementation serializes the Vulkan pipeline cache effectively. "
        "On some implementations, pipeline cache serialization returns no data, so there "
        "is no benefit to serializing it",
        &members, "https://anglebug.com/7369"};

    FeatureInfo enableAsyncPipelineCacheCompression = {
        "enableAsyncPipelineCacheCompression", FeatureCategory::VulkanWorkarounds,
        "Enable compressing pipeline cache in a thread.", &members, "http://anglebug.com/4722"};

    FeatureInfo supportsPipelineProtectedAccess = {
        "supportsPipelineProtectedAccess", FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_EXT_pipeline_protected_access extension", &members,
        "https://anglebug.com/7714"};

    FeatureInfo supportsMixedReadWriteDepthStencilLayouts = {
        "supportsMixedReadWriteDepthStencilLayouts", FeatureCategory::VulkanFeatures,
        "VkDevice supports the mixed read and write depth/stencil layouts introduced by "
        "VK_KHR_maintenance2",
        &members, "https://anglebug.com/7899"};

    FeatureInfo supportsSwapchainMaintenance1 = {
        "supportsSwapchainMaintenance1", FeatureCategory::VulkanFeatures,
        "VkDevice supports the VK_EXT_surface_maintenance1 and VK_EXT_swapchain_maintenance1 "
        "extensions",
        &members, "https://anglebug.com/7847"};

    FeatureInfo preferSubmitOnAnySamplesPassedQueryEnd = {
        "preferSubmitOnAnySamplesPassedQueryEnd", FeatureCategory::VulkanWorkarounds,
        "Submit commands to driver when last GL_ANY_SAMPLES_PASSED query is made for performance "
        "improvements.",
        &members, "https://issuetracker.google.com/250706693"};

    FeatureInfo forceWaitForSubmissionToCompleteForQueryResult = {
        "forceWaitForSubmissionToCompleteForQueryResult", FeatureCategory::VulkanWorkarounds,
        "Force wait for submission to complete before calling getQueryResult(wait).", &members,
        "https://issuetracker.google.com/253522366"};
};

inline FeaturesVk::FeaturesVk()  = default;
inline FeaturesVk::~FeaturesVk() = default;

}  // namespace angle

#endif  // ANGLE_PLATFORM_FEATURESVK_H_
