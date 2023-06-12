# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': 'a6662c53ced629a9d94611276743cbcde896b6af',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '030d0be28c35bafebd20660c112852b1d8c8c6ca',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '8e2ad27488ed2f87c068c01a8f5e8979f7086405',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '93c13345e176f3f8bdb4b07e59c5e3365b3dbf44',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '605dc6d3e789630d24310435121cd0c7d51b6483',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': 'c97930ba3664fbd2c19d23584ac734a16a35cba8',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '2c83dd6cb2ef710bab843b69776997d6f2c12ba4',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': 'ee8fe8140a03c321b25a1df532b4d6cadda64071',
}

deps = {
  'glslang/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/glslang@{glslang_revision}',
  },

  'spirv-cross/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/SPIRV-Cross@{spirv_cross_revision}',
  },

  'spirv-headers/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/SPIRV-Headers@{spirv_headers_revision}',
  },

  'spirv-tools/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/SPIRV-Tools@{spirv_tools_revision}',
  },

  'vulkan-headers/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/Vulkan-Headers@{vulkan_headers_revision}',
  },

  'vulkan-loader/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/Vulkan-Loader@{vulkan_loader_revision}',
  },

  'vulkan-tools/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/Vulkan-Tools@{vulkan_tools_revision}',
  },

  'vulkan-validation-layers/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/Vulkan-ValidationLayers@{vulkan_validation_revision}',
  },
}
