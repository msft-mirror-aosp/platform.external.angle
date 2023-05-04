# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': 'dfc97740ff91008cf038f13fc1ae9eb2aaa007fb',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '4faeb81f3fb489248a6b633ed2662271777756e3',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '7f1d2f4158704337aff1f739c8e494afc5716e7e',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': 'a525dccbe8058c42079a67a49e7aa9973d67de27',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '870a531486f77dfaf124395de80ed38867400d31',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '71254bedeef4b9e94f7a51ec0fe6e4134dbfcfec',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': 'b647be6419696dac2f5e009d7e27913d987f037b',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '631fde41b2f4bd80f452b76578d5f02dbf82b06c',
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
