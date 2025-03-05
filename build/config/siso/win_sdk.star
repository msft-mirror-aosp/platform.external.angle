# -*- bazel-starlark -*-
# Copyright 2024 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
"""Siso configuration fow win sdk."""

load("@builtin//encoding.star", "json")
load("@builtin//lib/gn.star", "gn")
load("@builtin//path.star", "path")
load("@builtin//runtime.star", "runtime")
load("@builtin//struct.star", "module")
load("./gn_logs.star", "gn_logs")

def __win_toolchain_dir(ctx):
    # build/win_toolchain.json may not exist when
    # $env:DEPOT_TOOLS_WIN_TOOLCHAIN=0 or so.
    if not ctx.fs.exists("build/win_toolchain.json"):
        return None
    data = json.decode(str(ctx.fs.read("build/win_toolchain.json")))
    if "path" in data:
        return ctx.fs.canonpath(data["path"])
    return None

def __win_sdk_version(ctx):
    return gn_logs.read(ctx).get("windows_sdk_version")

def __target_cpu(ctx):
    if "args.gn" in ctx.metadata:
        gn_args = gn.args(ctx)
        target = gn_args.get("target_cpu", "").strip('"')
        if target:
            return target
    return "x64"

def __enabled(ctx):
    if "args.gn" in ctx.metadata:
        gn_args = gn.args(ctx)
        if gn_args.get("target_os") == '"win"':
            return True
    return runtime.os == "windows"

def __filegroups(ctx):
    win_toolchain_dir = __win_toolchain_dir(ctx)
    sdk_version = __win_sdk_version(ctx)
    target_cpu = __target_cpu(ctx)
    fg = {}
    if win_toolchain_dir and sdk_version:
        fg.update({
            # for precomputed subtrees.
            # Case insensitive files are listed by filegroups.
            # But, case sensitive files are added individually in
            # __step_config() below.
            win_toolchain_dir + ":headers-ci": {
                "type": "glob",
                "includes": [
                    "*.h",
                    "*.inl",
                    "*.H",
                    "*.Hxx",
                    "*.hxx",
                    "*.hpp",
                    "VC/Tools/MSVC/*/include/*",
                    "VC/Tools/MSVC/*/include/*/*",
                ],
            },
            win_toolchain_dir + ":libs-ci": {
                "type": "glob",
                "includes": [
                    "DIA SDK/lib/*.lib",
                    "DIA SDK/lib/*/*.lib",
                    path.join("VC/Tools/MSVC/*/lib", target_cpu, "*.lib"),
                    path.join("VC/Tools/MSVC/*/lib", target_cpu, "*.pdb"),
                    path.join("VC/Tools/MSVC/*/*/lib", target_cpu, "*.lib"),
                    path.join("VC/Tools/MSVC/*/*/lib", target_cpu, "*.pdb"),
                    path.join("VC/Tools/MSVC/*/lib", target_cpu, "*/*.lib"),
                    path.join("Windows Kits/10/Lib", sdk_version, "ucrt", target_cpu, "*.lib"),
                    path.join("Windows Kits/10/Lib", sdk_version, "um", target_cpu, "*.lib"),
                    path.join("Windows Kits/10/Lib", target_cpu, "*.lib"),
                ],
            },
        })
    return fg

def __step_config(ctx, step_config):
    win_toolchain_dir = __win_toolchain_dir(ctx)
    if not win_toolchain_dir:
        return
    target_cpu = __target_cpu(ctx)
    win_toolchain_headers = [
        win_toolchain_dir + ":headers-ci",
    ]
    win_toolchain_libs = [
        win_toolchain_dir + ":libs-ci",
    ]
    sdk_version = __win_sdk_version(ctx)
    if sdk_version:
        win_toolchain_headers.extend([
            # third_party/abseil-cpp includes "dbghelp.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/dbghelp.h"),
            # third_party/abseil-cpp includes "aclapi.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/aclapi.h"),
            # base/debug includes "psapi.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/psapi.h"),
            # base/process includes "tlhelp32.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/tlhelp32.h"),
            # base/process includes "userenv.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/userenv.h"),
            # base includes "shlobj.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/shlobj.h"),
            # base/win includes "lm.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/lm.h"),
            # base/win includes "mdmregistration.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/mdmregistration.h"),
            # base/win includes "shellscalingapi.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/shellscalingapi.h"),
            # base/win includes "uiviewsettingsinterop.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/uiviewsettingsinterop.h"),
            # native_client/src/shared/platform/win includes "WinError.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "shared/WinError.h"),
            # third_party/webrtc/rtc_base/win includes "windows.graphics.directX.direct3d11.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "cppwinrt/winrt/windows.graphics.directX.direct3d11.h"),
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "winrt/windows.graphics.directX.direct3d11.h"),
            # third_party/webrtc/rtc_base/win includes "windows.graphics.directX.direct3d11.interop.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/windows.graphics.directX.direct3d11.interop.h"),
            # third_party/crashpad/crashpad/handler/win includes "werapi.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/werapi.h"),
            # chrome/install_static/ includes "wtsapi32.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/wtsapi32.h"),
            # third_party/dawn/include/dawn/native includes "DXGI1_4.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "shared/DXGI1_4.h"),
            # v8/src/diagnostics includes "versionhelpers.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/versionhelpers.h"),
            # ui/gfx/ includes "DXGIType.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "shared/DXGIType.h"),
            # third_party/unrar includes "PowrProf.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/PowrProf.h"),
            # device/base/ includes "dbt.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/dbt.h"),
            # third_party/skia/ includes "ObjBase.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/ObjBase.h"),
            # third_party/webrtc/rtc_base includes "ws2spi.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/ws2spi.h"),
            # third_party/skia/ includes "T2EmbApi.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/T2EmbApi.h"),
            # device/vr/windows/ includes "D3D11_1.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/D3D11_1.h"),
            # rlz/win/ includes "Sddl.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "shared/Sddl.h"),
            # chrome/common/safe_browsing/ includes "softpub.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/softpub.h"),
            # services/device/generic_sensor/ includes "Sensors.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/Sensors.h"),
            # third_party/webrtc/modules/desktop_capture/win includes "windows.graphics.capture.interop.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/windows.graphics.capture.interop.h"),
            # third_party/skia/ includes "FontSub.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/FontSub.h"),
            # chrome/updater/ includes "regstr.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/regstr.h"),
            # services/device/compute_pressure includes "pdh.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/pdh.h"),
            # chrome/installer/ includes "mshtmhst.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/mshtmhst.h"),
            # net/ssl/ includes "NCrypt.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/NCrypt.h"),
            # device/fido/win/ includes "Combaseapi.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/Combaseapi.h"),
            # components/device_signals/core/system_signals/win includes "wscapi.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/wscapi.h"),
            # net/proxy_resolution/win/ includes "dhcpcsdk.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/dhcpcsdk.h"),
            # third_party/dawn/third_party/glfw includes "xinput.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/xinput.h"),
            # v8/tools/v8windbg includes "pathcch.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/pathcch.h"),
            # remoting/host includes "rpcproxy.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/rpcproxy.h"),
            # sandbox/win includes "Aclapi.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/Aclapi.h"),
            # ui/accessibility/platform includes "uiautomation.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/uiautomation.h"),
            # chrome/credential_provider/gaiacp includes "ntsecapi.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/ntsecapi.h"),
            # net/dns includes "Winsock2.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/Winsock2.h"),
            # media/cdm/win includes "mferror.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/mferror.h"),
            # chrome/credentialProvider/gaiacp includes "Winternl.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/Winternl.h"),
            # media/audio/win includes "audioclient.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/audioclient.h"),
            # media/audio/win includes "MMDeviceAPI.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/MMDeviceAPI.h"),
            # net/proxy_resolution/win includes "dhcpv6csdk.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/dhcpv6csdk.h"),
            # components/system_media_controls/win includes "systemmediatransportcontrolsinterop.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/systemmediatransportcontrolsinterop.h"),
            # ui/native_theme includes "Windows.Media.ClosedCaptioning.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "cppwinrt/winrt/Windows.Media.ClosedCaptioning.h"),
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "winrt/Windows.Media.ClosedCaptioning.h"),
            # media/audio/win includes "Functiondiscoverykeys_devpkey.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/Functiondiscoverykeys_devpkey.h"),
            # device/fido includes "Winuser.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/Winuser.h"),
            # chrome/updater/win includes "msxml2.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/msxml2.h"),
            # remoting/host includes "ime.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/ime.h"),
            # remoting/host/win includes "D3DCommon.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/D3DCommon.h"),
            # ui/views/controls/menu includes "Vssym32.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/Vssym32.h"),
            # third_party/wtl includes "richedit.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/richedit.h"),
            # chrome/updater/net includes "Urlmon.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/Urlmon.h"),
            # device/gamepad includes "XInput.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/XInput.h"),
            # chrome/credential_provider/gaiacp includes "Shlobj.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/Shlobj.h"),
            # content/renderer includes "mlang.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/mlang.h"),
            # components/storage_monitor includes "portabledevice.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/portabledevice.h"),
            # third_party/wtl includes "richole.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/richole.h"),
            # chrome/utility/importer includes "intshcut.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/intshcut.h"),
            # chrome/browser/net includes "Ws2spi.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/Ws2spi.h"),
            # chrome/browser/enterprise/platform_auth includes "proofofpossessioncookieinfo.h)"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/proofofpossessioncookieinfo.h"),
            # chrome/utility/importer includes "urlhist.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/urlhist.h"),
            # chrome/updater/win/installer includes "msiquery.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/msiquery.h"),
            # third_party/win_virtual_display/controller includes "Devpropdef.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "shared/Devpropdef.h"),
            # third_party/dawn/third_party/dxc/include/dxc/Support/WinIncludes.h "ObjIdl.h"
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/ObjIdl.h"),
            # third_party/dawn/third_party/dxc/lib/Support includes "D3Dcommon.h"
            # https://github.com/microsoft/DirectXShaderCompiler/pull/6380
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version, "um/D3Dcommon.h"),
        ])
        win_toolchain_libs.extend([
            # Having the empty "Windows Kits/10/Include/{sdk_version}" directory is necessary
            # for lld-link to search libs under "Windows Kits/10/Lib/{sdk_version}/um".
            path.join(win_toolchain_dir, "Windows Kits/10/Include", sdk_version),
            # The following libs are necessary to resolve case mismatches on
            # Linux remote workers.
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "Bthprops.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "Cfgmgr32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "Crypt32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "DXGI.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "DbgEng.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "DbgModel.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "Ole32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "Pathcch.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "Propsys.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "Rtworkq.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "RuntimeObject.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "Setupapi.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "Wintrust.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "advapi32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "comctl32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "comdlg32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "credui.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "crypt32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "dbghelp.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "dhcpcsvc.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "dnsapi.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "gdi32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "imagehlp.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "imm32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "kernel32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "mf.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "mfplat.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "msi.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "msimg32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "msxml2.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "netapi32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "ntdsapi.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "ole32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "oleacc.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "oleaut32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "onecore.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "opengl32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "pdh.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "portabledeviceguids.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "rpcns4.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "rpcrt4.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "sapi.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "secur32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "setupapi.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "shlwapi.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "uiautomationcore.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "urlmon.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "user32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "userenv.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "usp10.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "uuid.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "uxtheme.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "version.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "wininet.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "winmm.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "winspool.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "wintrust.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "ws2_32.lib"),
            path.join(win_toolchain_dir, "Windows Kits/10/Lib", sdk_version, "um", target_cpu, "wtsapi32.lib"),
        ])
        step_config["input_deps"].update({
            win_toolchain_dir + ":headers": win_toolchain_headers,
            win_toolchain_dir + ":libs": win_toolchain_libs,
        })
    else:
        # sdk_version may be unknown when first build after `gn clean` (no gn_logs.txt yet)
        print("sdk_version is unknown")

win_sdk = module(
    "win_sdk",
    enabled = __enabled,
    toolchain_dir = __win_toolchain_dir,
    step_config = __step_config,
    filegroups = __filegroups,
)
