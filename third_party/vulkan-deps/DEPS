# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '9a35abff55440655dda5326c1d07ae23450ae64f',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': 'f349c91274b91c1a7c173f2df70ec53080076191',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '1c6bb2743599e6eb6f37b2969acc0aef812e32e3',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '6b4f0c9d0b7d02db5ed0b03433ae62c03bbff722',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '19a863ccce773ff393b186329478b1eb1a519fd3',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '0133778cb1c4493a9d580700b8a6e0fe493c601c',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '1ee9eea9f1f58fe0677703eb121ae445e6513b9a',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': '4a89051018cef521243b0bc5c7d13ca362e328d7',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '3d6bdd9dc7214c38d1965e0bf1a7c1e0c2089044',
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
