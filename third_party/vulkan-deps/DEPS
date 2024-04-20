# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '68df2230566b02c6495ffd8c200db523392fa797',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': 'b8fcf307f1f347089e3c46eb4451d27f32ebc8d3',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '4f7b471f1a66b6d06462cd4ba57628cc0cd087d7',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': 'dadb3012d51702cccae71967f9f2acaec8f393d5',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': 'eaa319dade959cb61ed2229c8ea42e307cc8f8b3',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': 'c684aed192ce1bb202dedd775ea18f066c8c55cb',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': 'bfdd09240f60ae643a91518cba44526c94fbc635',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': 'd0670f9ff0da1a2f7596d4861f601dc4c8810aea',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': 'd1316e54231099f7febfcee90ace3ad6a8a551b5',
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
