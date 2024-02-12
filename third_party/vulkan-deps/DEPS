# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '30661abd9c3e97144f79cb30f2fb5a0da2c7b93c',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': 'b8fcf307f1f347089e3c46eb4451d27f32ebc8d3',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': 'e77d03080b90c5d361663a67834c57bb1fddaec2',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': 'a8959dc653d71609ac5bbfd151ddd6da2b62e79b',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '5ac36269f50381bdd92a5e1973d8eb041771e59e',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': 'e0d594e05b194597bacda68e9a9279d12905f89b',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': 'f24bab1ea1c521cd77991260cad1b11384eec5f0',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': '86de0a0a9dc09520644bfb6b2f49e919134fe86d',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '9d00ae6c668895d3af97ad57e4f1771797cf3a16',
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
