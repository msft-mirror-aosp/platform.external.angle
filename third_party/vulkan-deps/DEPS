# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '9001ec9aa56597ba6ddd5104bf53b44d7ae63527',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': 'b8fcf307f1f347089e3c46eb4451d27f32ebc8d3',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '4f7b471f1a66b6d06462cd4ba57628cc0cd087d7',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '2904985aee4de2fd67d697242a267f5ec31814ce',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '1e7b8a6d03d30c9254b5f533b561d62bba8c3199',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': 'c684aed192ce1bb202dedd775ea18f066c8c55cb',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '9fc3b7bfacb3fa5f4f18dd5aee77c07d53863a3a',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': 'd0670f9ff0da1a2f7596d4861f601dc4c8810aea',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '6bb4f917888277dc2e57fb5cc9a6bd64c81ee69f',
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
