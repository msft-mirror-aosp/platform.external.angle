# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '5ff0c048b7242e173357bf28024cdee79edbcea8',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '37fee00a71b5a47247c1cf20256a3f794537c6c0',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': 'e867c06631767a2d96424cbec530f9ee5e78180f',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '4fab7435bf2e1be1abb6d308bdd6298ac95de88d',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '6f0d6550e61f204a42f8c1bcea82b61802e27d66',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': 'dedcfae3782e4db579b7e4e3ef9668de471bc635',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': 'e483d0dfc7b33483cefd80632d141fe0bacdfb9a',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': '2169a0849e3df4e2133b728dec67d3b16bd30263',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '8dee6832716cb8c6ba12165996abd7bec2c8aff6',
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
