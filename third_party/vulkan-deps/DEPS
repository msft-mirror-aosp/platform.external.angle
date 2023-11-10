# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '091b9fd97959a2007f3ddc4ae903915c7b504715',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '4818f7e7ef7b7078a3a7a5a52c4a338e0dda22f4',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '88bc5e321c2839707df8b1ab534e243e00744177',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '9e7a1f2ddd65514f6edc8303bd909fa735054bcc',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': 'aff5071d4ee6215c60a91d8d983cad91bb25fb57',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '6342790c86356be9ab3a41d91a06e711fdbf35da',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '322e7b3f0850c4892b69b326959811c82344e18f',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': '5b3147a535e28a48ae760efacdf97b296d9e8c73',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': 'ca58d5500b830a50020e025528826501fae478ed',
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
