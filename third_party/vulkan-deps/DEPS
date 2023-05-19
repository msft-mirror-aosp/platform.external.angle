# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': 'd1517d64cfca91f573af1bf7341dc3a5113349c0',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '28b11e010a4dbf444804e4bcfc5a57046c69287e',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': 'bdbfd019be6952fd8fa9bd5606a8798a7530c853',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': 'e7c6084fd1d6d6f5ac393e842728d8be309688ca',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '9e61870ecbd32514113b467e0a0c46f60ed222c7',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '35b005a5792f6e4c2931d62a37324923f1a71c79',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': 'fec27a3f6e3bae96a8f3e784d6d643afb41989d6',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '84788d43ee6d2c8503713e50a5081e68567a143a',
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

  'vulkan-validation-layers/src': {
    'url': '{chromium_git}/external/github.com/KhronosGroup/Vulkan-ValidationLayers@{vulkan_validation_revision}',
  },
}
