# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '277d09e679f0f4d9469c463c00cb11c6a040e65f',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '79401259fd80b3be1274184646bb6d03315b8db8',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': 'e867c06631767a2d96424cbec530f9ee5e78180f',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '74005dfa67c48ac9c20dd7fce848166f40d02473',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': 'bbe0f575ebd6098369f0ac6c6a43532732ed0ba6',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '6b36b69a7e614191997e8113ced26cf5d84adb40',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': 'd6a6498781cbdd63c0c018f5ffab39e16e920035',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': 'ca0ad5798733d94a80a322c98dab9ca9a0cd0fb2',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': 'bb7b6f1526d4cb7c35253caa6d705755233e69e9',
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
