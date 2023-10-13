# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': '48f9ed8b08be974f4e463ef38136c8f23513b2cf',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '724433d72925f54682ae637c8bc4f4b7e83c4409',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': '4183b260f4cccae52a89efdfcdd43c4897989f42',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': '661f429b11e4392139a6c0630ceb3e3182cdb0f4',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '07ff4233bc69e573ae0a6b4b48ad16451ac4e37f',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': '5402dd26632797d3cdaedb97cef04849d5ec980d',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '730552e6702cd73764b28f48271a967fba95162e',

  # Current revision of Khronos Vulkan-Utility-Libraries.
  'vulkan_utility_libraries_revision': 'ca0ad5798733d94a80a322c98dab9ca9a0cd0fb2',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': '38891e233bf914cd82bc0a8b4c91b7b94e3cd86b',
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
