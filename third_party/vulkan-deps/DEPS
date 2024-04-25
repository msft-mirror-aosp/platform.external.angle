# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': 'b5672e8e8d42b0278d1765ab3d24c97b0e746bd0',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': 'b8fcf307f1f347089e3c46eb4451d27f32ebc8d3',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '5e3ad389ee56fca27c9705d093ae5387ce404df4',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': 'dd4b663e13c07fea4fbb3f70c1c91c86731099f7',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': 'eaa319dade959cb61ed2229c8ea42e307cc8f8b3',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': 'fa3b7bdefadef01ee9af593245c47ca1a33212f4',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '9aec60c387fb0cd065d3ba921b56c3ef19ad958e',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': 'd0ffc68fe796ffd5752b7a2cba7c4f1d80ed7283',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '17c8bcb0e86fb2a64b53f2fab70deef326f9f73b',
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
