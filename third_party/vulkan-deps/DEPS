# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '1952e63d437beb0a3ba7df27f34ced0cef656824',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '37a58e4c95e80ac9baaff095f631ea0dce61217f',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': 'bdd1b2ab1f03e616047bbcf8971157dccd50c792',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '01ee1bf317611f52c8d3f2eb0fc451d266f826ee',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '217e93c664ec6704ec2d8c36fa116c1a4a1e2d40',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '4c20ea31565c5a469c66ad90918cb2e83f542032',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '2c0a644db855f40f100f9f39e5a8a8dfa2b0014d',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': '4cfc176e3242b4dbdfd3f6c5680c5d8f2cb7db45',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '0078555268f02bbbff329557c1fb0ab5bd087bde',
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
