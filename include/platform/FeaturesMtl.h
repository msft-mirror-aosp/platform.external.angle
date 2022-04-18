// GENERATED FILE - DO NOT EDIT.
// Generated by gen_features.py using data from mtl_features.json.
//
// Copyright 2022 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// FeaturesMtl.h: Optional features for the Metal renderer.

#ifndef ANGLE_PLATFORM_FEATURESMTL_H_
#define ANGLE_PLATFORM_FEATURESMTL_H_

#include "platform/Feature.h"

namespace angle
{

struct FeaturesMtl : FeatureSetBase
{
    FeaturesMtl();
    ~FeaturesMtl();

    FeatureInfo hasBaseVertexInstancedDraw = {
        "has_base_vertex_instanced_draw",
        FeatureCategory::MetalFeatures,
        "The renderer supports base vertex instanced draw",
        &members,
    };

    FeatureInfo hasExplicitMemBarrier = {
        "has_explicit_mem_barrier_mtl",
        FeatureCategory::MetalFeatures,
        "The renderer supports explicit memory barrier",
        &members,
    };

    FeatureInfo hasCheapRenderPass = {
        "has_cheap_render_pass_mtl",
        FeatureCategory::MetalFeatures,
        "The renderer can cheaply break a render pass.",
        &members,
    };

    FeatureInfo hasNonUniformDispatch = {
        "has_non_uniform_dispatch",
        FeatureCategory::MetalFeatures,
        "The renderer supports non uniform compute shader dispatch's group size",
        &members,
    };

    FeatureInfo hasStencilOutput = {
        "has_shader_stencil_output",
        FeatureCategory::MetalFeatures,
        "The renderer supports stencil output from fragment shader",
        &members,
    };

    FeatureInfo hasTextureSwizzle = {
        "has_texture_swizzle",
        FeatureCategory::MetalFeatures,
        "The renderer supports texture swizzle",
        &members,
    };

    FeatureInfo hasDepthAutoResolve = {
        "has_msaa_depth_auto_resolve",
        FeatureCategory::MetalFeatures,
        "The renderer supports MSAA depth auto resolve at the end of render pass",
        &members,
    };

    FeatureInfo hasStencilAutoResolve = {
        "has_msaa_stencil_auto_resolve",
        FeatureCategory::MetalFeatures,
        "The renderer supports MSAA stencil auto resolve at the end of render pass",
        &members,
    };

    FeatureInfo hasEvents = {
        "has_mtl_events",
        FeatureCategory::MetalFeatures,
        "The renderer supports MTL(Shared)Event",
        &members,
    };

    FeatureInfo allowInlineConstVertexData = {
        "allow_inline_const_vertex_data",
        FeatureCategory::MetalFeatures,
        "The renderer supports using inline constant data for small client vertex data",
        &members,
    };

    FeatureInfo allowSeparatedDepthStencilBuffers = {
        "allow_separate_depth_stencil_buffers",
        FeatureCategory::MetalFeatures,
        "Some Apple platforms such as iOS allows separate depth and stencil buffers, "
        "whereas others such as macOS don't",
        &members,
    };

    FeatureInfo allowRuntimeSamplerCompareMode = {
        "allow_runtime_sampler_compare_mode",
        FeatureCategory::MetalFeatures,
        "The renderer supports changing sampler's compare mode outside shaders",
        &members,
    };

    FeatureInfo allowSamplerCompareGradient = {
        "allow_sampler_compare_gradient",
        FeatureCategory::MetalFeatures,
        "The renderer supports sample_compare with gradients",
        &members,
    };

    FeatureInfo allowSamplerCompareLod = {
        "allow_sampler_compare_lod",
        FeatureCategory::MetalFeatures,
        "The renderer supports sample_compare with lod",
        &members,
    };

    FeatureInfo allowBufferReadWrite = {
        "allow_buffer_read_write",
        FeatureCategory::MetalFeatures,
        "The renderer supports buffer read and write in the same shader",
        &members,
    };

    FeatureInfo allowMultisampleStoreAndResolve = {
        "allow_msaa_store_and_resolve",
        FeatureCategory::MetalFeatures,
        "The renderer supports MSAA store and resolve in the same pass",
        &members,
    };

    FeatureInfo allowGenMultipleMipsPerPass = {
        "gen_multiple_mips_per_pass",
        FeatureCategory::MetalFeatures,
        "The renderer supports generating multiple mipmaps per pass",
        &members,
    };

    FeatureInfo forceD24S8AsUnsupported = {
        "force_d24s8_as_unsupported",
        FeatureCategory::MetalFeatures,
        "Force Depth24Stencil8 format as unsupported.",
        &members,
    };

    FeatureInfo forceBufferGPUStorage = {
        "force_buffer_gpu_storage",
        FeatureCategory::MetalFeatures,
        "On systems that support both buffer' memory allocation on GPU and shared memory (such as "
        "macOS), force using GPU memory allocation for buffers everytime or not.",
        &members,
    };

    FeatureInfo directMetalGeneration = {"directMetalGeneration", FeatureCategory::MetalFeatures,
                                         "Direct translation to Metal.", &members,
                                         "http://anglebug.com/5505"};

    FeatureInfo forceNonCSBaseMipmapGeneration = {
        "force_non_cs_mipmap_gen",
        FeatureCategory::MetalFeatures,
        "Turn this feature on to disallow Compute Shader based mipmap generation. Compute Shader "
        "based mipmap generation might cause GPU hang on some older iOS devices.",
        &members,
    };

    FeatureInfo emulateTransformFeedback = {
        "emulateTransformFeedback",
        FeatureCategory::MetalFeatures,
        "Turn this on to allow transform feedback in Metal using a 2-pass VS for GLES3.",
        &members,
    };

    FeatureInfo rewriteRowMajorMatrices = {
        "rewrite_row_major_matrices",
        FeatureCategory::MetalFeatures,
        "Rewrite row major matrices in shaders as column major.",
        &members,
    };

    FeatureInfo intelExplicitBoolCastWorkaround = {
        "intel_explicit_bool_cast_workaround",
        FeatureCategory::MetalWorkarounds,
        "Insert explicit casts for float/double/unsigned/signed int on macOS 10.15 with Intel "
        "driver",
        &members,
    };

    FeatureInfo intelDisableFastMath = {
        "intel_disable_fast_math",
        FeatureCategory::MetalWorkarounds,
        "Disable fast math in atan and invariance cases when running below macOS 12.0",
        &members,
    };

    FeatureInfo multisampleColorFormatShaderReadWorkaround = {
        "multisample_color_format_shader_read_workaround", FeatureCategory::MetalWorkarounds,
        "Add shaderRead usage to some multisampled texture formats", &members,
        "http://anglebug.com/7049"};
};

inline FeaturesMtl::FeaturesMtl()  = default;
inline FeaturesMtl::~FeaturesMtl() = default;

}  // namespace angle

#endif  // ANGLE_PLATFORM_FEATURESMTL_H_
