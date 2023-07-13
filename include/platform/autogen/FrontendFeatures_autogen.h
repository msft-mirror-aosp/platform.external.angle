// GENERATED FILE - DO NOT EDIT.
// Generated by gen_features.py using data from frontend_features.json.
//
// Copyright 2022 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// FrontendFeatures_autogen.h: Features/workarounds for driver bugs and other behaviors seen
// on all platforms.

#ifndef ANGLE_PLATFORM_AUTOGEN_FRONTENDFEATURES_H_
#define ANGLE_PLATFORM_AUTOGEN_FRONTENDFEATURES_H_

#include "platform/Feature.h"

namespace angle
{

struct FrontendFeatures : FeatureSetBase
{
    FrontendFeatures();
    ~FrontendFeatures();

    FeatureInfo loseContextOnOutOfMemory = {
        "loseContextOnOutOfMemory",
        FeatureCategory::FrontendWorkarounds,
        "Some users rely on a lost context notification if a GL_OUT_OF_MEMORY error occurs",
        &members,
    };

    FeatureInfo disableProgramCachingForTransformFeedback = {
        "disableProgramCachingForTransformFeedback",
        FeatureCategory::FrontendWorkarounds,
        "On some GPUs, program binaries don't contain transform feedback varyings",
        &members,
    };

    FeatureInfo disableProgramBinary = {
        "disableProgramBinary",
        FeatureCategory::FrontendFeatures,
        "Disable support for GL_OES_get_program_binary",
        &members, "http://anglebug.com/5007"
    };

    FeatureInfo disableDrawBuffersIndexed = {
        "disableDrawBuffersIndexed",
        FeatureCategory::FrontendFeatures,
        "Disable support for OES_draw_buffers_indexed and EXT_draw_buffers_indexed",
        &members, "http://anglebug.com/7724"
    };

    FeatureInfo disableAnisotropicFiltering = {
        "disableAnisotropicFiltering",
        FeatureCategory::FrontendWorkarounds,
        "Disable support for anisotropic filtering",
        &members,
    };

    FeatureInfo allowCompressedFormats = {
        "allowCompressedFormats",
        FeatureCategory::FrontendWorkarounds,
        "Allow compressed formats",
        &members,
    };

    FeatureInfo singleThreadedTextureDecompression = {
        "singleThreadedTextureDecompression",
        FeatureCategory::FrontendWorkarounds,
        "Disables multi-threaded decompression of compressed texture formats",
        &members,
    };

    FeatureInfo forceDepthAttachmentInitOnClear = {
        "forceDepthAttachmentInitOnClear",
        FeatureCategory::FrontendWorkarounds,
        "Force depth attachment initialization on clear ops",
        &members, "https://anglebug.com/7246"
    };

    FeatureInfo enableCaptureLimits = {
        "enableCaptureLimits",
        FeatureCategory::FrontendFeatures,
        "Set the context limits like frame capturing was enabled",
        &members, "http://anglebug.com/5750"
    };

    FeatureInfo forceRobustResourceInit = {
        "forceRobustResourceInit",
        FeatureCategory::FrontendFeatures,
        "Force-enable robust resource init",
        &members, "http://anglebug.com/6041"
    };

    FeatureInfo forceInitShaderVariables = {
        "forceInitShaderVariables",
        FeatureCategory::FrontendFeatures,
        "Force-enable shader variable initialization",
        &members,
    };

    FeatureInfo enableProgramBinaryForCapture = {
        "enableProgramBinaryForCapture",
        FeatureCategory::FrontendFeatures,
        "Even if FrameCapture is enabled, enable GL_OES_get_program_binary",
        &members, "http://anglebug.com/5658"
    };

    FeatureInfo forceGlErrorChecking = {
        "forceGlErrorChecking",
        FeatureCategory::FrontendFeatures,
        "Force GL error checking (i.e. prevent applications from disabling error checking",
        &members, "https://issuetracker.google.com/220069903"
    };

    FeatureInfo emulatePixelLocalStorage = {
        "emulatePixelLocalStorage",
        FeatureCategory::FrontendFeatures,
        "Emulate ANGLE_shader_pixel_local_storage using shader images",
        &members, "http://anglebug.com/7279"
    };

    FeatureInfo cacheCompiledShader = {
        "cacheCompiledShader",
        FeatureCategory::FrontendFeatures,
        "Enable to cache compiled shaders",
        &members, "http://anglebug.com/7036"
    };

    FeatureInfo dumpShaderSource = {
        "dumpShaderSource",
        FeatureCategory::FrontendFeatures,
        "Write shader source to temp directory",
        &members, "http://anglebug.com/7760"
    };

    FeatureInfo enableShaderSubstitution = {
        "enableShaderSubstitution",
        FeatureCategory::FrontendWorkarounds,
        "Check the filesystem for shaders to use instead of those provided through glShaderSource",
        &members, "http://anglebug.com/7761"
    };

    FeatureInfo disableProgramCaching = {
        "disableProgramCaching",
        FeatureCategory::FrontendFeatures,
        "Disables saving programs to the cache",
        &members, "http://anglebug.com/1423136"
    };

};

inline FrontendFeatures::FrontendFeatures()  = default;
inline FrontendFeatures::~FrontendFeatures() = default;

}  // namespace angle

#endif  // ANGLE_PLATFORM_AUTOGEN_FRONTENDFEATURES_H_
