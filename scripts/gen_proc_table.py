#!/usr/bin/python3
# Copyright 2017 The ANGLE Project Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#
# gen_proc_table.py:
#  Code generation for entry point loading tables.
#  NOTE: don't run this script directly. Run scripts/run_code_generation.py.

import sys
import registry_xml

out_file_name_gles = "../src/libGLESv2/proc_table_egl_autogen.cpp"
out_file_name_wgl = "../src/libGLESv2/proc_table_wgl_autogen.cpp"
out_file_name_glx = "../src/libGLESv2/proc_table_glx_autogen.cpp"
out_file_name_cl = "../src/libGLESv2/proc_table_cl_autogen.cpp"
out_file_name_cl_map = "../src/libOpenCL/libOpenCL_autogen.map"

strip_suffixes = ["ANGLE", "EXT", "KHR", "OES", "CHROMIUM", "OVR"]

template_cpp = """// GENERATED FILE - DO NOT EDIT.
// Generated by {script_name} using data from {data_source_name}.
//
// Copyright 2019 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// getProcAddress loader table:
//   Mapping from a string entry point name to function address.
//

{includes}
#define P(FUNC) reinterpret_cast<{cast}>(FUNC)
{desktop_only_macro_definition}

namespace {namespace}
{{
// clang-format off
const ProcEntry g_procTable[] = {{
{proc_data}
}};
// clang-format on
const size_t g_numProcs = {num_procs};
}}  // namespace {namespace}
"""

desktop_only_macro_definition = """
#if defined(ANGLE_ENABLE_GL_DESKTOP_FRONTEND)
#   define DESKTOP_ONLY(func, angleFunc) {func, P(angleFunc)},
#else
#   define DESKTOP_ONLY(func, angleFunc)
#endif
"""

# FOR OPENCL
template_map_cpp = """// GENERATED FILE - DO NOT EDIT.
// Generated by {script_name} using data from {data_source_name}.
//
// Copyright 2021 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// proc_table:
//   Mapping from a string entry point name to function address.
//

{includes}
#define P(FUNC) reinterpret_cast<{cast}>(FUNC)

namespace {namespace}
{{

const ProcTable &GetProcTable()
{{
    static angle::base::NoDestructor<ProcTable> sProcTable(
        {{{proc_data}}});
    return *sProcTable;
}}

}}  // namespace {namespace}
"""

# FOR OPENCL
template_map = """/* GENERATED FILE - DO NOT EDIT.
 * Generated by {script_name} using data from {data_source_name}.
 *
 * Copyright 2021 The ANGLE Project Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * symbol version map: Maps versions to entry point names for a shared library.
 */
{symbol_maps}
"""

includes_gles = """#include "libGLESv2/proc_table_egl.h"

#include "libGLESv2/entry_points_egl_autogen.h"
#include "libGLESv2/entry_points_egl_ext_autogen.h"
#include "libGLESv2/entry_points_gles_1_0_autogen.h"
#include "libGLESv2/entry_points_gles_2_0_autogen.h"
#include "libGLESv2/entry_points_gles_3_0_autogen.h"
#include "libGLESv2/entry_points_gles_3_1_autogen.h"
#include "libGLESv2/entry_points_gles_3_2_autogen.h"
#include "libGLESv2/entry_points_gles_ext_autogen.h"
#include "platform/PlatformMethods.h"

#if defined(ANGLE_ENABLE_GL_DESKTOP_FRONTEND)
#   include "libGLESv2/entry_points_gl_1_autogen.h"
#   include "libGLESv2/entry_points_gl_2_autogen.h"
#   include "libGLESv2/entry_points_gl_3_autogen.h"
#   include "libGLESv2/entry_points_gl_4_autogen.h"
#endif

#include <iterator>
"""

includes_wgl = """#include "libGLESv2/proc_table_wgl.h"

#include "libGLESv2/entry_points_egl_ext_autogen.h"
#include "libGLESv2/entry_points_gles_1_0_autogen.h"
#include "libGLESv2/entry_points_gles_2_0_autogen.h"
#include "libGLESv2/entry_points_gles_3_0_autogen.h"
#include "libGLESv2/entry_points_gles_3_1_autogen.h"
#include "libGLESv2/entry_points_gles_3_2_autogen.h"
#include "libGLESv2/entry_points_gles_ext_autogen.h"
#include "platform/PlatformMethods.h"
#include "libGLESv2/entry_points_gl_1_autogen.h"
#include "libGLESv2/entry_points_gl_2_autogen.h"
#include "libGLESv2/entry_points_gl_3_autogen.h"
#include "libGLESv2/entry_points_gl_4_autogen.h"
#include "libGLESv2/entry_points_wgl.h"

#include <iterator>
"""

includes_glx = """#include "libGLESv2/proc_table_glx.h"

#include "libGLESv2/entry_points_egl_ext_autogen.h"
#include "libGLESv2/entry_points_gles_1_0_autogen.h"
#include "libGLESv2/entry_points_gles_2_0_autogen.h"
#include "libGLESv2/entry_points_gles_3_0_autogen.h"
#include "libGLESv2/entry_points_gles_3_1_autogen.h"
#include "libGLESv2/entry_points_gles_3_2_autogen.h"
#include "libGLESv2/entry_points_gles_ext_autogen.h"
#include "platform/PlatformMethods.h"
#include "libGLESv2/entry_points_gl_1_autogen.h"
#include "libGLESv2/entry_points_gl_2_autogen.h"
#include "libGLESv2/entry_points_gl_3_autogen.h"
#include "libGLESv2/entry_points_gl_4_autogen.h"
#include "libGLESv2/entry_points_glx.h"

#include <iterator>
"""

includes_cl = """#include "libGLESv2/proc_table_cl.h"

#include "libGLESv2/entry_points_cl_autogen.h"

#include "anglebase/no_destructor.h"

// Using fully qualified entry point identifiers to make sure that missing entry points would not
// pick up the global declarations of OpenCL
"""

sys.path.append('../src/libANGLE/renderer')
import angle_format


def _get_annotations(versions):
    return ["%d_%d" % version for version in versions]


def main():

    # auto_script parameters.
    if len(sys.argv) > 1:
        inputs = [source for source in registry_xml.xml_inputs]
        outputs = [
            out_file_name_gles, out_file_name_wgl, out_file_name_glx, out_file_name_cl,
            out_file_name_cl_map
        ]
        if sys.argv[1] == 'inputs':
            print(','.join(inputs))
        elif sys.argv[1] == 'outputs':
            print(','.join(outputs))
        else:
            print('Invalid script parameters')
            return 1
        return 0

    glesxml = registry_xml.RegistryXML('gl.xml', 'gl_angle_ext.xml')

    for annotation in _get_annotations(registry_xml.GLES_VERSIONS):
        name_prefix = "GL_ES_VERSION_"
        if annotation[0] == '1':
            name_prefix = "GL_VERSION_ES_CM_"
        feature_name = "{}{}".format(name_prefix, annotation)
        glesxml.AddCommands(feature_name, annotation)

    glesxml.AddExtensionCommands(registry_xml.supported_extensions, ['gles2', 'gles1'])

    # Also don't add GLES extension commands to libGL proc table
    extension_commands = []
    for extension_name, ext_cmd_names in sorted(glesxml.ext_data.items()):
        extension_commands.extend(glesxml.ext_data[extension_name])
    for name in extension_commands:
        name_no_suffix = name
        for suffix in strip_suffixes:
            if name_no_suffix.endswith(suffix):
                name_no_suffix = name_no_suffix[0:-len(suffix)]

    gles_data = glesxml.all_cmd_names.get_all_commands()
    eglxml = registry_xml.RegistryXML('egl.xml', 'egl_angle_ext.xml')

    for annotation in _get_annotations(registry_xml.EGL_VERSIONS):
        name_prefix = "EGL_VERSION_"
        feature_name = "{}{}".format(name_prefix, annotation)
        eglxml.AddCommands(feature_name, annotation)

    eglxml.AddExtensionCommands(registry_xml.supported_egl_extensions, ['gles2', 'gles1'])

    gles_data.extend(eglxml.all_cmd_names.get_all_commands())

    gles_data.append("ANGLEGetDisplayPlatform")
    gles_data.append("ANGLEResetDisplayPlatform")
    gles_data = set(gles_data)

    glxml = registry_xml.RegistryXML('gl.xml')
    for annotation in _get_annotations(registry_xml.DESKTOP_GL_VERSIONS):
        name_prefix = "GL_VERSION_"
        feature_name = "{}{}".format(name_prefix, annotation)
        glxml.AddCommands(feature_name, annotation)

    gl_data = set([cmd for cmd in glxml.all_cmd_names.get_all_commands()])

    all_gl_data = list(set(gles_data).union(gl_data))
    all_functions = {}
    for function in all_gl_data:
        if function.startswith("gl"):
            all_functions[function] = "GL_" + function[2:]
        elif function.startswith("egl"):
            all_functions[function] = "EGL_" + function[3:]
        else:
            all_functions[function] = function

    proc_data = []
    gl_only_data = gl_data.difference(gles_data)
    for func, angle_func in sorted(all_functions.items()):
        if func in gl_only_data:
            proc_data.append('    DESKTOP_ONLY("%s", %s)' % (func, angle_func))
        else:
            proc_data.append('    {"%s", P(%s)},' % (func, angle_func))

    with open(out_file_name_gles, 'w') as out_file:
        output_cpp = template_cpp.format(
            script_name=sys.argv[0],
            data_source_name="gl.xml, gl_angle_ext.xml, egl.xml, egl_angle_ext.xml",
            includes=includes_gles,
            cast="__eglMustCastToProperFunctionPointerType",
            namespace="egl",
            proc_data="\n".join(proc_data),
            num_procs="std::size(g_procTable)",
            desktop_only_macro_definition=desktop_only_macro_definition)
        out_file.write(output_cpp)
        out_file.close()

    def WriteWindowingProcTable(api_name, out_file_name, includes, cast):
        xml_file_name = '{}.xml'.format(api_name)
        xml = registry_xml.RegistryXML(xml_file_name)
        annotations = _get_annotations(
            getattr(registry_xml, '{}_VERSIONS'.format(api_name.upper())))
        for annotation in annotations:
            name_prefix = "{}_VERSION_".format(api_name.upper())
            feature_name = "{}{}".format(name_prefix, annotation)
            xml.AddCommands(feature_name, annotation)

        commands = [
            # Some WGL EP's need to have "wgl" appended to their names
            cmd if api_name != 'wgl' or cmd.startswith(api_name) else api_name + cmd
            for cmd in xml.all_cmd_names.get_all_commands()
        ]

        # Start with all of the GLES + Desktop entry points, filtering out the EGL ones
        proc_data = [
            '    {"%s", P(%s)},' % (func, angle_func)
            for func, angle_func in sorted(all_functions.items())
            if not func.startswith('egl')
        ]
        proc_data.extend(['    {"%s", P(%s)},' % (cmd, cmd) for cmd in sorted(commands)])

        with open(out_file_name, 'w') as out_file:
            output_cpp = template_cpp.format(
                script_name=sys.argv[0],
                data_source_name="gl.xml, gl_angle_ext.xml, {}".format(xml_file_name),
                includes=includes,
                cast=cast,
                namespace=api_name,
                proc_data="\n".join(proc_data),
                num_procs="std::size(g_procTable)",
                desktop_only_macro_definition='')
            out_file.write(output_cpp)
            out_file.close()

    WriteWindowingProcTable('wgl', out_file_name_wgl, includes_wgl, "PROC")
    WriteWindowingProcTable('glx', out_file_name_glx, includes_glx, "__GLXextFuncPtr")

    # libCL proc table
    clxml = registry_xml.RegistryXML('cl.xml')
    symbol_maps = []
    symbol_map_dependency = ""

    for major_version, minor_version in registry_xml.CL_VERSIONS:
        name_prefix = "CL_VERSION_"
        annotation = "%d_%d" % (major_version, minor_version)
        feature_name = "%s%s" % (name_prefix, annotation)
        clxml.AddCommands(feature_name, annotation)
        symbol_version = "OPENCL_%d.%d" % (major_version, minor_version)
        symbol_maps += ["\n%s {\n    global:" % symbol_version]
        symbol_maps += ['        %s;' % cmd for cmd in clxml.commands[annotation]]
        if not symbol_map_dependency:
            symbol_maps += ["    local:\n        *;\n};"]
        else:
            symbol_maps += ["} %s;" % symbol_map_dependency]
        symbol_map_dependency = symbol_version

    clxml.AddExtensionCommands(registry_xml.supported_cl_extensions, ['cl'])
    cl_commands = clxml.all_cmd_names.get_all_commands()
    proc_data = ['{"%s", P(::cl::%s)}' % (cmd, cmd) for cmd in cl_commands]

    with open(out_file_name_cl, 'w') as out_file:
        output_cpp = template_map_cpp.format(
            script_name=sys.argv[0],
            data_source_name="cl.xml",
            includes=includes_cl,
            cast="void *",
            namespace="cl",
            proc_data=",\n         ".join(proc_data))
        out_file.write(output_cpp)
        out_file.close()

    with open(out_file_name_cl_map, 'w') as out_file:
        output_map = template_map.format(
            script_name=sys.argv[0], data_source_name="cl.xml", symbol_maps="\n".join(symbol_maps))
        out_file.write(output_map)
        out_file.close()

    return 0


if __name__ == '__main__':
    sys.exit(main())
