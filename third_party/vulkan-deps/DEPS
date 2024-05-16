# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '541733a66b1cf4465559c78a8bd857606ac76123',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': 'b8fcf307f1f347089e3c46eb4451d27f32ebc8d3',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '49a1fceb9b1d087f3c25ad5ec077bb0e46231297',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '199038f10cbe56bf7cbfeb5472eb0a25af2f09f5',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '5677bafb820e476441e9e1f745371b72133407d3',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': 'a1a73779649c0bfdaba6b856f7c9c96be6fc75cb',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '137b3612d62f1c92da16537e5497a60fcf13b6dc',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': '777358fdad21132866be4a835327fbc28eabc1a4',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': 'dcc6123bf5b1b5746b52fc38aa8b8336cc4c1535',
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

  'vulkan-utility-libraries/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/Vulkan-Utility-Libraries@{vulkan_utility_libraries_revision}',
  },

  'vulkan-validation-layers/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/Vulkan-ValidationLayers@{vulkan_validation_revision}',
  },
}
