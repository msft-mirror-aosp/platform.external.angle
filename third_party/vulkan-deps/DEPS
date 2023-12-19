# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': 'a7785ea1ff5b10bfc2d8ca77fdad5929562897b7',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': 'f349c91274b91c1a7c173f2df70ec53080076191',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '1c6bb2743599e6eb6f37b2969acc0aef812e32e3',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': 'e03c8f5c8ed77f0b1a2408d55bb8f00a7ee9793c',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '41263fc5aa994b8eafaca946583bfcceca8ca419',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '979242bdd724e0018c20bb75837a393a08408e77',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '8f6c0e51dcfb0a08f14d28ace577445a87c391c4',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': 'b89f4b8415ef6afe08a8dbb98c8487ebd59c3387',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': 'eebe1dfcefd3473f80a981d4ec88adc3bb07d27d',
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
