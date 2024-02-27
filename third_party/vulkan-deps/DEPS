# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '2518af09c8b39423e76db9efdf94a5a478f4e5fc',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': 'b8fcf307f1f347089e3c46eb4451d27f32ebc8d3',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '05cc486580771e4fa7ddc89f5c9ee1e97382689a',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': 'c3a9ffd74f8b27434d220f2e48a98ac6cd72d178',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '31aa7f634b052d87ede4664053e85f3f4d1d50d3',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '71a1694c80786c6ce5cb13e795456e66e2d93dd7',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '069bd14c0548556e130fc9e205adc918b7a01891',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': '1b8b60bf7f271a09eeda032d117d51a43ed506cd',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': 'd7b134da10fd39f6f36ce8eb579073de6d6646de',
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
