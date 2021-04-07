#!/usr/bin/python
# Copyright 2019 The ANGLE Project Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#
# gen_mtl_format_table.py:
#  Code generation for Metal format map.
#  NOTE: don't run this script directly. Run scripts/run_code_generation.py.
#

import json
import math
import pprint
import re
import sys

sys.path.append('..')
import angle_format as angle_format_utils

template_autogen_inl = """// GENERATED FILE - DO NOT EDIT.
// Generated by {script_name} using data from {data_source_name}
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Metal Format table:
//   Conversion from ANGLE format to Metal format.

#import <Metal/Metal.h>
#include <TargetConditionals.h>

#include "image_util/copyimage.h"
#include "image_util/generatemip.h"
#include "image_util/loadimage.h"
#include "libANGLE/renderer/Format.h"
#include "libANGLE/renderer/metal/DisplayMtl.h"
#include "libANGLE/renderer/metal/mtl_format_utils.h"

using namespace angle;

namespace rx
{{
namespace mtl
{{

angle::FormatID Format::MetalToAngleFormatID(MTLPixelFormat formatMtl)
{{
    // Actual conversion
    switch (formatMtl)
    {{
{mtl_pixel_format_switch}
    }}
}}

void Format::init(const DisplayMtl *display, angle::FormatID intendedFormatId_)
{{
    this->intendedFormatId = intendedFormatId_;

    id<MTLDevice> metalDevice = display->getMetalDevice();

    // Actual conversion
    switch (this->intendedFormatId)
    {{
{angle_image_format_switch}
    }}
}}

void VertexFormat::init(angle::FormatID angleFormatId, bool tightlyPacked)
{{
    this->intendedFormatId = angleFormatId;

    // Actual conversion
    switch (this->intendedFormatId)
    {{
{angle_vertex_format_switch}
    }}
}}

void FormatTable::initNativeFormatCapsAutogen(const DisplayMtl *display)
{{
    const angle::FeaturesMtl &featuresMtl = display->getFeatures();
    // Skip auto resolve if either hasDepth/StencilAutoResolve or allowMultisampleStoreAndResolve
    // feature are disabled.
    bool supportDepthAutoResolve = featuresMtl.hasDepthAutoResolve.enabled &&
                                   featuresMtl.allowMultisampleStoreAndResolve.enabled;
    bool supportStencilAutoResolve = featuresMtl.hasStencilAutoResolve.enabled &&
                                     featuresMtl.allowMultisampleStoreAndResolve.enabled;
    bool supportDepthStencilAutoResolve = supportDepthAutoResolve && supportStencilAutoResolve;

    // Source: https://developer.apple.com/metal/Metal-Feature-Set-Tables.pdf
    {metal_format_caps}
}}

}}  // namespace mtl
}}  // namespace rx
"""

image_format_assign_template1 = """
            this->metalFormat = {mtl_format};
            this->actualFormatId = angle::FormatID::{actual_angle_format};
            this->initFunction = {init_function};
"""

image_format_assign_template2 = """
            if ({fallback_condition})
            {{
                this->metalFormat = {mtl_format};
                this->actualFormatId = angle::FormatID::{actual_angle_format};
                this->initFunction = {init_function};
            }}
            else
            {{
                this->metalFormat = {mtl_format_fallback};
                this->actualFormatId = angle::FormatID::{actual_angle_format_fallback};
                this->initFunction = {init_function_fallback};
            }}
"""

case_image_format_template1 = """        case angle::FormatID::{angle_format}:
            {image_format_assign}
            this->swizzled = false;
            break;

"""

case_image_format_template2 = """        case angle::FormatID::{angle_format}:
#if defined(__IPHONE_13_0) || defined(__MAC_10_15)
            if (display->getFeatures().hasTextureSwizzle.enabled)
            {{
                {image_format_assign_swizzled}
                this->swizzled = true;
                this->swizzle  = {mtl_swizzle};
            }}
            else
#endif  // #if defined(__IPHONE_13_0) || defined(__MAC_10_15)
            {{
                {image_format_assign_default}
                this->swizzled = false;
            }}
            break;

"""

case_image_mtl_to_angle_template = """        case {mtl_format}:
            return angle::FormatID::{angle_format};
"""

case_vertex_format_template1 = """        case angle::FormatID::{angle_format}:
            this->metalFormat = {mtl_format};
            this->actualFormatId = angle::FormatID::{actual_angle_format};
            this->vertexLoadFunction = {vertex_copy_function};
            this->defaultAlpha = {default_alpha};
            this->actualSameGLType = {same_gl_type};
            break;

"""

case_vertex_format_template2 = """        case angle::FormatID::{angle_format}:
            if (tightlyPacked)
            {{
                this->metalFormat = {mtl_format_packed};
                this->actualFormatId = angle::FormatID::{actual_angle_format_packed};
                this->vertexLoadFunction = {vertex_copy_function_packed};
                this->defaultAlpha = {default_alpha_packed};
                this->actualSameGLType = {same_gl_type_packed};
            }}
            else
            {{
                this->metalFormat = {mtl_format};
                this->actualFormatId = angle::FormatID::{actual_angle_format};
                this->vertexLoadFunction = {vertex_copy_function};
                this->defaultAlpha = {default_alpha};
                this->actualSameGLType = {same_gl_type};
            }}
            break;

"""


# NOTE(hqle): This is a modified version of the get_vertex_copy_function() function in
# src/libANGLE/renderer/angle_format.py
# - Return value is a tuple {copy_function, default_alpha_value, have_same_gl_type}.
def get_vertex_copy_function_and_default_alpha(src_format, dst_format):
    if dst_format == "NONE":
        return "nullptr", 0, "false"

    num_channel = len(angle_format_utils.get_channel_tokens(src_format))
    if num_channel < 1 or num_channel > 4:
        return "nullptr", 0, "false"

    src_gl_type = angle_format_utils.get_format_gl_type(src_format)
    dst_gl_type = angle_format_utils.get_format_gl_type(dst_format)

    if src_gl_type == dst_gl_type:
        if src_format.startswith('R10G10B10A2'):
            return 'CopyNativeVertexData<GLuint, 1, 1, 0>', 0, "true"

        if src_gl_type == None:
            return 'nullptr', 0, "true"
        dst_num_channel = len(angle_format_utils.get_channel_tokens(dst_format))
        default_alpha = '1'

        if num_channel == dst_num_channel or dst_num_channel < 4:
            default_alpha = '0'
        elif 'A16_FLOAT' in dst_format:
            default_alpha = 'gl::Float16One'
        elif 'A32_FLOAT' in dst_format:
            default_alpha = 'gl::Float32One'
        elif 'NORM' in dst_format:
            default_alpha = 'std::numeric_limits<%s>::max()' % (src_gl_type)

        return 'CopyNativeVertexData<%s, %d, %d, %s>' % (src_gl_type, num_channel, dst_num_channel,
                                                         default_alpha), default_alpha, "true"

    if src_format.startswith('R10G10B10A2'):
        assert 'FLOAT' in dst_format, ('get_vertex_copy_function: can only convert to float,' +
                                       ' not to ' + dst_format)
        is_signed = 'true' if 'SINT' in src_format or 'SNORM' in src_format or 'SSCALED' in src_format else 'false'
        is_normal = 'true' if 'NORM' in src_format else 'false'
        return 'CopyXYZ10W2ToXYZW32FVertexData<%s, %s, true>' % (is_signed, is_normal), 0, "false"

    return angle_format_utils.get_vertex_copy_function(src_format, dst_format), 0, "false"


# Generate format conversion switch case (generic case)
def gen_image_map_switch_case(angle_format, actual_angle_format_info, angle_to_mtl_map,
                              assign_gen_func):
    if isinstance(actual_angle_format_info, dict):
        default_actual_angle_format = actual_angle_format_info['default']
        # Check if the format can be override with swizzle feature
        if 'swizzle' in actual_angle_format_info:
            swizzle_info = actual_angle_format_info['swizzle']
            swizzle_channels = swizzle_info[0]
            swizzled_actual_angle_format = swizzle_info[1]
            swizzle_map = {
                'R': 'GL_RED',
                'G': 'GL_GREEN',
                'B': 'GL_BLUE',
                'A': 'GL_ALPHA',
                '1': 'GL_ONE',
                '0': 'GL_ZERO',
            }

            mtl_swizzle_make = '{{{r}, {g}, {b}, {a}}}'.format(
                r=swizzle_map[swizzle_channels[0:1]],
                g=swizzle_map[swizzle_channels[1:2]],
                b=swizzle_map[swizzle_channels[2:3]],
                a=swizzle_map[swizzle_channels[3:]])
            return case_image_format_template2.format(
                angle_format=angle_format,
                image_format_assign_default=assign_gen_func(default_actual_angle_format,
                                                            angle_to_mtl_map),
                image_format_assign_swizzled=assign_gen_func(swizzled_actual_angle_format,
                                                             angle_to_mtl_map),
                mtl_swizzle=mtl_swizzle_make)
        else:
            # Only default case
            return gen_image_map_switch_case(angle_format, default_actual_angle_format,
                                             angle_to_mtl_map, assign_gen_func)
    else:
        # Default case
        return case_image_format_template1.format(
            angle_format=angle_format,
            image_format_assign=assign_gen_func(actual_angle_format_info, angle_to_mtl_map))


# Generate format conversion switch case (simple case)
def gen_image_map_switch_simple_case(angle_format, actual_angle_format_info, angle_to_gl,
                                     angle_to_mtl_map):

    def gen_format_assign_code(actual_angle_format, angle_to_mtl_map):
        return image_format_assign_template1.format(
            actual_angle_format=actual_angle_format,
            mtl_format=angle_to_mtl_map[actual_angle_format],
            init_function=angle_format_utils.get_internal_format_initializer(
                angle_to_gl[angle_format], actual_angle_format))

    return gen_image_map_switch_case(angle_format, actual_angle_format_info, angle_to_mtl_map,
                                     gen_format_assign_code)


# Generate format conversion switch case (Mac case)
def gen_image_map_switch_mac_case(angle_format, actual_angle_format_info, angle_to_gl,
                                  angle_to_mtl_map, mac_fallbacks):
    gl_format = angle_to_gl[angle_format]

    def gen_format_assign_code(actual_angle_format, angle_to_mtl_map):
        if actual_angle_format in mac_fallbacks:
            # This format requires fallback when depth24Stencil8PixelFormatSupported flag is false.
            # Fallback format:
            actual_angle_format_fallback = mac_fallbacks[actual_angle_format]
            fallback_condition = "metalDevice.depth24Stencil8PixelFormatSupported && \
                                 !display->getFeatures().forceD24S8AsUnsupported.enabled"
            # return if else block:
            return image_format_assign_template2.format(
                actual_angle_format=actual_angle_format,
                mtl_format=angle_to_mtl_map[actual_angle_format],
                init_function=angle_format_utils.get_internal_format_initializer(
                    gl_format, actual_angle_format),
                actual_angle_format_fallback=actual_angle_format_fallback,
                mtl_format_fallback=angle_to_mtl_map[actual_angle_format_fallback],
                init_function_fallback=angle_format_utils.get_internal_format_initializer(
                    gl_format, actual_angle_format_fallback),
                fallback_condition=fallback_condition)
        else:
            # return ordinary block:
            return image_format_assign_template1.format(
                actual_angle_format=actual_angle_format,
                mtl_format=angle_to_mtl_map[actual_angle_format],
                init_function=angle_format_utils.get_internal_format_initializer(
                    gl_format, actual_angle_format))

    return gen_image_map_switch_case(angle_format, actual_angle_format_info, angle_to_mtl_map,
                                     gen_format_assign_code)


# Generate format conversion switch case (non-desktop ES 3.0 case)
def gen_image_map_switch_es3_case(angle_format, actual_angle_format_info, angle_to_gl,
                                  angle_to_mtl_map, mac_fallbacks):
    gl_format = angle_to_gl[angle_format]

    def gen_format_assign_code(actual_angle_format, angle_to_mtl_map):
        actual_angle_format_fallback = mac_fallbacks[actual_angle_format]
        return image_format_assign_template2.format(
            actual_angle_format=actual_angle_format,
            mtl_format=angle_to_mtl_map[actual_angle_format],
            init_function=angle_format_utils.get_internal_format_initializer(
                gl_format, actual_angle_format),
            actual_angle_format_fallback=actual_angle_format_fallback,
            mtl_format_fallback=angle_to_mtl_map[actual_angle_format_fallback],
            init_function_fallback=angle_format_utils.get_internal_format_initializer(
                gl_format, actual_angle_format_fallback),
            fallback_condition="display->supportsAppleGPUFamily(1)")

    return gen_image_map_switch_case(angle_format, actual_angle_format_info, angle_to_mtl_map,
                                     gen_format_assign_code)


def gen_image_map_switch_string(image_table, angle_to_gl):
    angle_override = image_table["override"]
    mac_override_es3 = image_table["override_mac_es3"]
    mac_override_bc1 = image_table["override_mac_bc1"]
    ios_override = image_table["override_ios"]
    mac_fallbacks = image_table["d24s8_fallbacks_mac"]
    angle_to_mtl = image_table["map"]
    mac_specific_map = image_table["map_mac"]
    ios_specific_map = image_table["map_ios"]

    # mac_specific_map + angle_to_mtl:
    mac_angle_to_mtl = mac_specific_map.copy()
    mac_angle_to_mtl.update(angle_to_mtl)
    # ios_specific_map + angle_to_mtl
    ios_angle_to_mtl = ios_specific_map.copy()
    ios_angle_to_mtl.update(angle_to_mtl)

    switch_data = ''

    def gen_image_map_switch_common_case(angle_format, actual_angle_format):
        return gen_image_map_switch_simple_case(angle_format, actual_angle_format, angle_to_gl,
                                                angle_to_mtl)

    # Common case: universally-supported formats + universal overrides
    for angle_format in sorted(angle_to_mtl.keys()):
        switch_data += gen_image_map_switch_common_case(angle_format, angle_format)
    for angle_format in sorted(angle_override.keys()):
        switch_data += gen_image_map_switch_common_case(angle_format, angle_override[angle_format])

    # Mac GPU case: macOS + Catalyst targets
    switch_data += "#if TARGET_OS_OSX || TARGET_OS_MACCATALYST\n"
    for angle_format in sorted(mac_specific_map.keys()):
        switch_data += gen_image_map_switch_mac_case(angle_format, angle_format, angle_to_gl,
                                                     mac_angle_to_mtl, mac_fallbacks)
    for angle_format in sorted(mac_override_bc1.keys()):
        switch_data += gen_image_map_switch_mac_case(angle_format, mac_override_bc1[angle_format],
                                                     angle_to_gl, mac_angle_to_mtl, mac_fallbacks)
    switch_data += "#endif\n"

    # Override missing ES 3.0 formats for older macOS SDK or Catalyst
    switch_data += "#if (TARGET_OS_OSX && (__MAC_OS_X_VERSION_MAX_ALLOWED < 101600)) || \\\n"
    switch_data += "TARGET_OS_MACCATALYST\n"
    for angle_format in sorted(mac_override_es3.keys()):
        switch_data += gen_image_map_switch_mac_case(angle_format, mac_override_es3[angle_format],
                                                     angle_to_gl, mac_angle_to_mtl, mac_fallbacks)
    switch_data += "#endif\n"

    # iOS specific
    switch_data += "#if TARGET_OS_IOS || TARGET_OS_TV\n"
    for angle_format in sorted(ios_specific_map.keys()):
        switch_data += gen_image_map_switch_simple_case(angle_format, angle_format, angle_to_gl,
                                                        ios_specific_map)
    for angle_format in sorted(ios_override.keys()):
        switch_data += gen_image_map_switch_simple_case(angle_format, ios_override[angle_format],
                                                        angle_to_gl, ios_angle_to_mtl)
    switch_data += "#endif\n"

    # Try to support all iOS formats on newer macOS with Apple GPU.
    switch_data += "#if (TARGET_OS_OSX && (__MAC_OS_X_VERSION_MAX_ALLOWED >= 101600))\n"
    for angle_format in sorted(ios_specific_map.keys()):
        if (angle_format in mac_override_es3.keys()):
            # ETC/EAC or packed 16-bit
            switch_data += gen_image_map_switch_es3_case(angle_format, angle_format, angle_to_gl,
                                                         ios_angle_to_mtl, mac_override_es3)
        else:
            # ASTC or PVRTC1
            switch_data += gen_image_map_switch_simple_case(angle_format, angle_format,
                                                            angle_to_gl, ios_specific_map)
    switch_data += "#endif\n"

    switch_data += "        default:\n"
    switch_data += "            this->metalFormat = MTLPixelFormatInvalid;\n"
    switch_data += "            this->actualFormatId = angle::FormatID::NONE;"
    return switch_data


def gen_image_mtl_to_angle_switch_string(image_table):
    angle_to_mtl = image_table["map"]
    mac_specific_map = image_table["map_mac"]
    ios_specific_map = image_table["map_ios"]

    switch_data = ''

    # Common case
    for angle_format in sorted(angle_to_mtl.keys()):
        switch_data += case_image_mtl_to_angle_template.format(
            mtl_format=angle_to_mtl[angle_format], angle_format=angle_format)

    # Mac specific
    switch_data += "#if TARGET_OS_OSX || TARGET_OS_MACCATALYST\n"
    for angle_format in sorted(mac_specific_map.keys()):
        switch_data += case_image_mtl_to_angle_template.format(
            mtl_format=mac_specific_map[angle_format], angle_format=angle_format)
    switch_data += "#endif  // TARGET_OS_OSX || TARGET_OS_MACCATALYST\n"

    # iOS + macOS 11.0+ specific
    switch_data += "#if TARGET_OS_IOS || TARGET_OS_TV || (TARGET_OS_OSX && (__MAC_OS_X_VERSION_MAX_ALLOWED >= 101600))\n"
    for angle_format in sorted(ios_specific_map.keys()):
        # ETC1_R8G8B8_UNORM_BLOCK is a duplicated of ETC2_R8G8B8_UNORM_BLOCK
        if angle_format == 'ETC1_R8G8B8_UNORM_BLOCK':
            continue
        switch_data += case_image_mtl_to_angle_template.format(
            mtl_format=ios_specific_map[angle_format], angle_format=angle_format)
    switch_data += "#endif  // TARGET_OS_IOS || TARGET_OS_TV || mac 11.0+\n"

    switch_data += "        default:\n"
    switch_data += "            return angle::FormatID::NONE;\n"
    return switch_data


def gen_vertex_map_switch_case(angle_fmt, actual_angle_fmt, angle_to_mtl_map, override_packed_map):
    mtl_format = angle_to_mtl_map[actual_angle_fmt]
    copy_function, default_alpha, same_gl_type = get_vertex_copy_function_and_default_alpha(
        angle_fmt, actual_angle_fmt)

    if actual_angle_fmt in override_packed_map:
        # This format has an override when used in tightly packed buffer,
        # Return if else block
        angle_fmt_packed = override_packed_map[actual_angle_fmt]
        mtl_format_packed = angle_to_mtl_map[angle_fmt_packed]
        copy_function_packed, default_alpha_packed, same_gl_type_packed = get_vertex_copy_function_and_default_alpha(
            angle_fmt, angle_fmt_packed)

        return case_vertex_format_template2.format(
            angle_format=angle_fmt,
            mtl_format_packed=mtl_format_packed,
            actual_angle_format_packed=angle_fmt_packed,
            vertex_copy_function_packed=copy_function_packed,
            default_alpha_packed=default_alpha_packed,
            same_gl_type_packed=same_gl_type_packed,
            mtl_format=mtl_format,
            actual_angle_format=actual_angle_fmt,
            vertex_copy_function=copy_function,
            default_alpha=default_alpha,
            same_gl_type=same_gl_type)
    else:
        # This format has no packed buffer's override, return ordinary block.
        return case_vertex_format_template1.format(
            angle_format=angle_fmt,
            mtl_format=mtl_format,
            actual_angle_format=actual_angle_fmt,
            vertex_copy_function=copy_function,
            default_alpha=default_alpha,
            same_gl_type=same_gl_type)


def gen_vertex_map_switch_string(vertex_table):
    angle_to_mtl = vertex_table["map"]
    angle_override = vertex_table["override"]
    override_packed = vertex_table["override_tightly_packed"]

    switch_data = ''
    for angle_fmt in sorted(angle_to_mtl.keys()):
        switch_data += gen_vertex_map_switch_case(angle_fmt, angle_fmt, angle_to_mtl,
                                                  override_packed)

    for angle_fmt in sorted(angle_override.keys()):
        switch_data += gen_vertex_map_switch_case(angle_fmt, angle_override[angle_fmt],
                                                  angle_to_mtl, override_packed)

    switch_data += "        default:\n"
    switch_data += "            this->metalFormat = MTLVertexFormatInvalid;\n"
    switch_data += "            this->actualFormatId = angle::FormatID::NONE;\n"
    switch_data += "            this->vertexLoadFunction = nullptr;"
    switch_data += "            this->defaultAlpha = 0;"
    switch_data += "            this->actualSameGLType = false;"
    return switch_data


def gen_mtl_format_caps_init_string(map_image):
    caps = map_image['caps']
    mac_caps = map_image['caps_mac']
    ios_caps = map_image['caps_ios']
    caps_init_str = ''

    def cap_to_param(caps, key):
        return '/** ' + key + '*/ ' + caps.get(key, 'false')

    def caps_to_cpp(caps_table):
        init_str = ''
        for mtl_format in sorted(caps_table.keys()):
            caps = caps_table[mtl_format]
            filterable = cap_to_param(caps, 'filterable')
            writable = cap_to_param(caps, 'writable')
            colorRenderable = cap_to_param(caps, 'colorRenderable')
            depthRenderable = cap_to_param(caps, 'depthRenderable')
            blendable = cap_to_param(caps, 'blendable')
            multisample = cap_to_param(caps, 'multisample')
            resolve = cap_to_param(caps, 'resolve')

            init_str += "    setFormatCaps({0}, {1}, {2}, {3}, {4}, {5}, {6}, {7});\n\n".format(
                mtl_format, filterable, writable, blendable, multisample, resolve, colorRenderable,
                depthRenderable)

        return init_str

    caps_init_str += caps_to_cpp(caps)

    caps_init_str += "#if TARGET_OS_OSX || TARGET_OS_MACCATALYST\n"
    caps_init_str += caps_to_cpp(mac_caps)
    caps_init_str += "#endif  // TARGET_OS_OSX || TARGET_OS_MACCATALYST\n"

    caps_init_str += "#if (TARGET_OS_IOS && !TARGET_OS_MACCATALYST) || TARGET_OS_TV || \\\n"
    caps_init_str += "    (TARGET_OS_OSX && (__MAC_OS_X_VERSION_MAX_ALLOWED >= 101600))\n"

    caps_init_str += caps_to_cpp(ios_caps)

    caps_init_str += "#endif\n"

    return caps_init_str


def main():
    data_source_name = 'mtl_format_map.json'
    # auto_script parameters.
    if len(sys.argv) > 1:
        inputs = ['../angle_format.py', '../angle_format_map.json', data_source_name]
        outputs = ['mtl_format_table_autogen.mm']

        if sys.argv[1] == 'inputs':
            print(','.join(inputs))
        elif sys.argv[1] == 'outputs':
            print(','.join(outputs))
        else:
            print('Invalid script parameters')
            return 1
        return 0

    angle_to_gl = angle_format_utils.load_inverse_table('../angle_format_map.json')

    map_json = angle_format_utils.load_json(data_source_name)
    map_image = map_json["image"]
    map_vertex = map_json["vertex"]

    image_switch_data = gen_image_map_switch_string(map_image, angle_to_gl)
    image_mtl_to_angle_switch_data = gen_image_mtl_to_angle_switch_string(map_image)

    vertex_switch_data = gen_vertex_map_switch_string(map_vertex)

    caps_init_str = gen_mtl_format_caps_init_string(map_image)

    output_cpp = template_autogen_inl.format(
        script_name=sys.argv[0],
        data_source_name=data_source_name,
        angle_image_format_switch=image_switch_data,
        mtl_pixel_format_switch=image_mtl_to_angle_switch_data,
        angle_vertex_format_switch=vertex_switch_data,
        metal_format_caps=caps_init_str)
    with open('mtl_format_table_autogen.mm', 'wt') as out_file:
        out_file.write(output_cpp)
        out_file.close()


if __name__ == '__main__':
    sys.exit(main())
