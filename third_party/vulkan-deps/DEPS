# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': 'fd403737d25ca5f167845b5a6d0e9adb0a2bb5ff',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '42aac916ab5db0cbaf55c2d41f4d063f4ce3955a',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': 'cca08c63cefa129d082abca0302adcb81610b465',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '2a238ed24dffd84fe3ed2e60d7aa5c28e2acf45a',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '7d92fe7b687eb92dafb5d344d1f4c817780cd3ce',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': 'a4ff6a54e4f06638fa8fb367913818bf9d189bdb',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '9ef6c05af3ed1a30b6345a19deb1ddfc409e52bd',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': '228f7487ddef12e55ee2c608dbf345eb042870b5',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '7adefb0aeb9034bb791437afb7ad447e0cbe5931',
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
