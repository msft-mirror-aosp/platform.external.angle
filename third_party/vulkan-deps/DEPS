# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': 'f6f9840eabd8c5b31e218c8c61b4716e5981f713',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '03b485dc47c6e84a15936601e8b121d84d8ddadf',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '1c9115b562bab79ee2160fbd845f41b815b9f21f',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': 'e5fcb7facf1c891cb30630ea8784da5493d78c22',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': 'ea45703effcb01df0856628286f8a890dd313ecd',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '90b990e43ba591d7a67ceda16f4600a3dd7e3507',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '5a5e17fbcc09d189f8b730d042af4a2c79920cc7',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': 'b6f52799ec558808c7cad9522cf3b4fe75ee97d5',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '6f55c100c6b2169543958d1a135bc38b67a81ed5',
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
