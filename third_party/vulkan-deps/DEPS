# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '8a3ea594c76c154493ade0948f1ea64a2f9d2e75',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': 'b8fcf307f1f347089e3c46eb4451d27f32ebc8d3',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '4f7b471f1a66b6d06462cd4ba57628cc0cd087d7',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '58ab8baf72d5abeff0b56e075fde714b16507b75',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': 'cfebfc96b2b0bce93da7d12f2c14cc01793ae25c',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '44260a22118fb4a12cf6f557acfefd4aa1cf74f0',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': 'c5da01ee0af9766c2992d6757e8f31ef50117b09',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': 'cdd0e00cff5bb2ac15850995e25c1956c37a58ec',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '3492699f4948b0b47a94e21a7bc1c2477b713631',
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
