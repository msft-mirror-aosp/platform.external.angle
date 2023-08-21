# This file is used to manage Vulkan dependencies for several repos. It is
# used by gclient to determine what version of each dependency to check out, and
# where.

# Avoids the need for a custom root variable.
use_relative_paths = True
git_dependencies = 'SYNC'

vars = {
  'chromium_git': 'https://chromium.googlesource.com',

  # Current revision of glslang, the Khronos SPIRV compiler.
  'glslang_revision': 'c5117b328afc86e16edff6ed6afe0fe7872a7cf3',

  # Current revision of spirv-cross, the Khronos SPIRV cross compiler.
  'spirv_cross_revision': '633dc301350952a9a895c8db42eed371ea969a64',

  # Current revision fo the SPIRV-Headers Vulkan support library.
  'spirv_headers_revision': 'b8b9eb8640c8c0107ba580fbcb10f969022ca32c',

  # Current revision of SPIRV-Tools for Vulkan.
  'spirv_tools_revision': 'bfc94f63a7adbcf8ae166f5f108ac9f69079efc0',

  # Current revision of Khronos Vulkan-Headers.
  'vulkan_headers_revision': '85c2334e92e215cce34e8e0ed8b2dce4700f4a50',

  # Current revision of Khronos Vulkan-Loader.
  'vulkan_loader_revision': 'dd8332d253cfaf3a9be306af4194e4dffc2e3b3c',

  # Current revision of Khronos Vulkan-Tools.
  'vulkan_tools_revision': '300d9bf6b3cf7b237ee5e2c1d0ae10b9236f82d3',

  # Current revision of Khronos Vulkan-ValidationLayers.
  'vulkan_validation_revision': 'd1ff40512a3ac70d6d075a3292028a7961d917ce',
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
