// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from egl.xml and egl_angle_ext.xml.
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// libEGL_autogen.cpp: Implements the exported EGL functions.

#include "anglebase/no_destructor.h"
#include "common/system_utils.h"

#include <memory>

#if defined(ANGLE_USE_EGL_LOADER)
#    include "libEGL/egl_loader_autogen.h"
#else
#    include "libGLESv2/entry_points_egl_autogen.h"
#    include "libGLESv2/entry_points_egl_ext_autogen.h"
#endif  // defined(ANGLE_USE_EGL_LOADER)

namespace
{
#if defined(ANGLE_USE_EGL_LOADER)
bool gLoaded          = false;
void *gEntryPointsLib = nullptr;

GenericProc KHRONOS_APIENTRY GlobalLoad(const char *symbol)
{
    return reinterpret_cast<GenericProc>(angle::GetLibrarySymbol(gEntryPointsLib, symbol));
}

void EnsureEGLLoaded()
{
    if (gLoaded)
    {
        return;
    }

    std::string errorOut;
    gEntryPointsLib = OpenSystemLibraryAndGetError(ANGLE_DISPATCH_LIBRARY,
                                                   angle::SearchType::ModuleDir, &errorOut);
    if (gEntryPointsLib)
    {
        LoadLibEGL_EGL(GlobalLoad);
        gLoaded = true;
    }
    else
    {
        fprintf(stderr, "Error loading EGL entry points: %s\n", errorOut.c_str());
    }
}
#else
void EnsureEGLLoaded() {}
#endif  // defined(ANGLE_USE_EGL_LOADER)
}  // anonymous namespace

extern "C" {

// EGL 1.0
EGLBoolean EGLAPIENTRY eglChooseConfig(EGLDisplay dpy,
                                       const EGLint *attrib_list,
                                       EGLConfig *configs,
                                       EGLint config_size,
                                       EGLint *num_config)
{
    EnsureEGLLoaded();
    return EGL_ChooseConfig(dpy, attrib_list, configs, config_size, num_config);
}

EGLBoolean EGLAPIENTRY eglCopyBuffers(EGLDisplay dpy,
                                      EGLSurface surface,
                                      EGLNativePixmapType target)
{
    EnsureEGLLoaded();
    return EGL_CopyBuffers(dpy, surface, target);
}

EGLContext EGLAPIENTRY eglCreateContext(EGLDisplay dpy,
                                        EGLConfig config,
                                        EGLContext share_context,
                                        const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreateContext(dpy, config, share_context, attrib_list);
}

EGLSurface EGLAPIENTRY eglCreatePbufferSurface(EGLDisplay dpy,
                                               EGLConfig config,
                                               const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreatePbufferSurface(dpy, config, attrib_list);
}

EGLSurface EGLAPIENTRY eglCreatePixmapSurface(EGLDisplay dpy,
                                              EGLConfig config,
                                              EGLNativePixmapType pixmap,
                                              const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreatePixmapSurface(dpy, config, pixmap, attrib_list);
}

EGLSurface EGLAPIENTRY eglCreateWindowSurface(EGLDisplay dpy,
                                              EGLConfig config,
                                              EGLNativeWindowType win,
                                              const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreateWindowSurface(dpy, config, win, attrib_list);
}

EGLBoolean EGLAPIENTRY eglDestroyContext(EGLDisplay dpy, EGLContext ctx)
{
    EnsureEGLLoaded();
    return EGL_DestroyContext(dpy, ctx);
}

EGLBoolean EGLAPIENTRY eglDestroySurface(EGLDisplay dpy, EGLSurface surface)
{
    EnsureEGLLoaded();
    return EGL_DestroySurface(dpy, surface);
}

EGLBoolean EGLAPIENTRY eglGetConfigAttrib(EGLDisplay dpy,
                                          EGLConfig config,
                                          EGLint attribute,
                                          EGLint *value)
{
    EnsureEGLLoaded();
    return EGL_GetConfigAttrib(dpy, config, attribute, value);
}

EGLBoolean EGLAPIENTRY eglGetConfigs(EGLDisplay dpy,
                                     EGLConfig *configs,
                                     EGLint config_size,
                                     EGLint *num_config)
{
    EnsureEGLLoaded();
    return EGL_GetConfigs(dpy, configs, config_size, num_config);
}

EGLDisplay EGLAPIENTRY eglGetCurrentDisplay()
{
    EnsureEGLLoaded();
    return EGL_GetCurrentDisplay();
}

EGLSurface EGLAPIENTRY eglGetCurrentSurface(EGLint readdraw)
{
    EnsureEGLLoaded();
    return EGL_GetCurrentSurface(readdraw);
}

EGLDisplay EGLAPIENTRY eglGetDisplay(EGLNativeDisplayType display_id)
{
    EnsureEGLLoaded();
    return EGL_GetDisplay(display_id);
}

EGLint EGLAPIENTRY eglGetError()
{
    EnsureEGLLoaded();
    return EGL_GetError();
}

__eglMustCastToProperFunctionPointerType EGLAPIENTRY eglGetProcAddress(const char *procname)
{
    EnsureEGLLoaded();
    return EGL_GetProcAddress(procname);
}

EGLBoolean EGLAPIENTRY eglInitialize(EGLDisplay dpy, EGLint *major, EGLint *minor)
{
    EnsureEGLLoaded();
    return EGL_Initialize(dpy, major, minor);
}

EGLBoolean EGLAPIENTRY eglMakeCurrent(EGLDisplay dpy,
                                      EGLSurface draw,
                                      EGLSurface read,
                                      EGLContext ctx)
{
    EnsureEGLLoaded();
    return EGL_MakeCurrent(dpy, draw, read, ctx);
}

EGLBoolean EGLAPIENTRY eglQueryContext(EGLDisplay dpy,
                                       EGLContext ctx,
                                       EGLint attribute,
                                       EGLint *value)
{
    EnsureEGLLoaded();
    return EGL_QueryContext(dpy, ctx, attribute, value);
}

const char *EGLAPIENTRY eglQueryString(EGLDisplay dpy, EGLint name)
{
    EnsureEGLLoaded();
    return EGL_QueryString(dpy, name);
}

EGLBoolean EGLAPIENTRY eglQuerySurface(EGLDisplay dpy,
                                       EGLSurface surface,
                                       EGLint attribute,
                                       EGLint *value)
{
    EnsureEGLLoaded();
    return EGL_QuerySurface(dpy, surface, attribute, value);
}

EGLBoolean EGLAPIENTRY eglSwapBuffers(EGLDisplay dpy, EGLSurface surface)
{
    EnsureEGLLoaded();
    return EGL_SwapBuffers(dpy, surface);
}

EGLBoolean EGLAPIENTRY eglTerminate(EGLDisplay dpy)
{
    EnsureEGLLoaded();
    return EGL_Terminate(dpy);
}

EGLBoolean EGLAPIENTRY eglWaitGL()
{
    EnsureEGLLoaded();
    return EGL_WaitGL();
}

EGLBoolean EGLAPIENTRY eglWaitNative(EGLint engine)
{
    EnsureEGLLoaded();
    return EGL_WaitNative(engine);
}

// EGL 1.1
EGLBoolean EGLAPIENTRY eglBindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    EnsureEGLLoaded();
    return EGL_BindTexImage(dpy, surface, buffer);
}

EGLBoolean EGLAPIENTRY eglReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    EnsureEGLLoaded();
    return EGL_ReleaseTexImage(dpy, surface, buffer);
}

EGLBoolean EGLAPIENTRY eglSurfaceAttrib(EGLDisplay dpy,
                                        EGLSurface surface,
                                        EGLint attribute,
                                        EGLint value)
{
    EnsureEGLLoaded();
    return EGL_SurfaceAttrib(dpy, surface, attribute, value);
}

EGLBoolean EGLAPIENTRY eglSwapInterval(EGLDisplay dpy, EGLint interval)
{
    EnsureEGLLoaded();
    return EGL_SwapInterval(dpy, interval);
}

// EGL 1.2
EGLBoolean EGLAPIENTRY eglBindAPI(EGLenum api)
{
    EnsureEGLLoaded();
    return EGL_BindAPI(api);
}

EGLSurface EGLAPIENTRY eglCreatePbufferFromClientBuffer(EGLDisplay dpy,
                                                        EGLenum buftype,
                                                        EGLClientBuffer buffer,
                                                        EGLConfig config,
                                                        const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreatePbufferFromClientBuffer(dpy, buftype, buffer, config, attrib_list);
}

EGLenum EGLAPIENTRY eglQueryAPI()
{
    EnsureEGLLoaded();
    return EGL_QueryAPI();
}

EGLBoolean EGLAPIENTRY eglReleaseThread()
{
    EnsureEGLLoaded();
    return EGL_ReleaseThread();
}

EGLBoolean EGLAPIENTRY eglWaitClient()
{
    EnsureEGLLoaded();
    return EGL_WaitClient();
}

// EGL 1.4
EGLContext EGLAPIENTRY eglGetCurrentContext()
{
    EnsureEGLLoaded();
    return EGL_GetCurrentContext();
}

// EGL 1.5
EGLint EGLAPIENTRY eglClientWaitSync(EGLDisplay dpy, EGLSync sync, EGLint flags, EGLTime timeout)
{
    EnsureEGLLoaded();
    return EGL_ClientWaitSync(dpy, sync, flags, timeout);
}

EGLImage EGLAPIENTRY eglCreateImage(EGLDisplay dpy,
                                    EGLContext ctx,
                                    EGLenum target,
                                    EGLClientBuffer buffer,
                                    const EGLAttrib *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreateImage(dpy, ctx, target, buffer, attrib_list);
}

EGLSurface EGLAPIENTRY eglCreatePlatformPixmapSurface(EGLDisplay dpy,
                                                      EGLConfig config,
                                                      void *native_pixmap,
                                                      const EGLAttrib *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreatePlatformPixmapSurface(dpy, config, native_pixmap, attrib_list);
}

EGLSurface EGLAPIENTRY eglCreatePlatformWindowSurface(EGLDisplay dpy,
                                                      EGLConfig config,
                                                      void *native_window,
                                                      const EGLAttrib *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreatePlatformWindowSurface(dpy, config, native_window, attrib_list);
}

EGLSync EGLAPIENTRY eglCreateSync(EGLDisplay dpy, EGLenum type, const EGLAttrib *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreateSync(dpy, type, attrib_list);
}

EGLBoolean EGLAPIENTRY eglDestroyImage(EGLDisplay dpy, EGLImage image)
{
    EnsureEGLLoaded();
    return EGL_DestroyImage(dpy, image);
}

EGLBoolean EGLAPIENTRY eglDestroySync(EGLDisplay dpy, EGLSync sync)
{
    EnsureEGLLoaded();
    return EGL_DestroySync(dpy, sync);
}

EGLDisplay EGLAPIENTRY eglGetPlatformDisplay(EGLenum platform,
                                             void *native_display,
                                             const EGLAttrib *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_GetPlatformDisplay(platform, native_display, attrib_list);
}

EGLBoolean EGLAPIENTRY eglGetSyncAttrib(EGLDisplay dpy,
                                        EGLSync sync,
                                        EGLint attribute,
                                        EGLAttrib *value)
{
    EnsureEGLLoaded();
    return EGL_GetSyncAttrib(dpy, sync, attribute, value);
}

EGLBoolean EGLAPIENTRY eglWaitSync(EGLDisplay dpy, EGLSync sync, EGLint flags)
{
    EnsureEGLLoaded();
    return EGL_WaitSync(dpy, sync, flags);
}

// EGL_ANDROID_blob_cache
void EGLAPIENTRY eglSetBlobCacheFuncsANDROID(EGLDisplay dpy,
                                             EGLSetBlobFuncANDROID set,
                                             EGLGetBlobFuncANDROID get)
{
    EnsureEGLLoaded();
    return EGL_SetBlobCacheFuncsANDROID(dpy, set, get);
}

// EGL_ANDROID_create_native_client_buffer
EGLClientBuffer EGLAPIENTRY eglCreateNativeClientBufferANDROID(const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreateNativeClientBufferANDROID(attrib_list);
}

// EGL_ANDROID_get_frame_timestamps
EGLBoolean EGLAPIENTRY eglGetCompositorTimingSupportedANDROID(EGLDisplay dpy,
                                                              EGLSurface surface,
                                                              EGLint name)
{
    EnsureEGLLoaded();
    return EGL_GetCompositorTimingSupportedANDROID(dpy, surface, name);
}

EGLBoolean EGLAPIENTRY eglGetCompositorTimingANDROID(EGLDisplay dpy,
                                                     EGLSurface surface,
                                                     EGLint numTimestamps,
                                                     const EGLint *names,
                                                     EGLnsecsANDROID *values)
{
    EnsureEGLLoaded();
    return EGL_GetCompositorTimingANDROID(dpy, surface, numTimestamps, names, values);
}

EGLBoolean EGLAPIENTRY eglGetNextFrameIdANDROID(EGLDisplay dpy,
                                                EGLSurface surface,
                                                EGLuint64KHR *frameId)
{
    EnsureEGLLoaded();
    return EGL_GetNextFrameIdANDROID(dpy, surface, frameId);
}

EGLBoolean EGLAPIENTRY eglGetFrameTimestampSupportedANDROID(EGLDisplay dpy,
                                                            EGLSurface surface,
                                                            EGLint timestamp)
{
    EnsureEGLLoaded();
    return EGL_GetFrameTimestampSupportedANDROID(dpy, surface, timestamp);
}

EGLBoolean EGLAPIENTRY eglGetFrameTimestampsANDROID(EGLDisplay dpy,
                                                    EGLSurface surface,
                                                    EGLuint64KHR frameId,
                                                    EGLint numTimestamps,
                                                    const EGLint *timestamps,
                                                    EGLnsecsANDROID *values)
{
    EnsureEGLLoaded();
    return EGL_GetFrameTimestampsANDROID(dpy, surface, frameId, numTimestamps, timestamps, values);
}

// EGL_ANDROID_get_native_client_buffer
EGLClientBuffer EGLAPIENTRY eglGetNativeClientBufferANDROID(const struct AHardwareBuffer *buffer)
{
    EnsureEGLLoaded();
    return EGL_GetNativeClientBufferANDROID(buffer);
}

// EGL_ANDROID_native_fence_sync
EGLint EGLAPIENTRY eglDupNativeFenceFDANDROID(EGLDisplay dpy, EGLSyncKHR sync)
{
    EnsureEGLLoaded();
    return EGL_DupNativeFenceFDANDROID(dpy, sync);
}

// EGL_ANDROID_presentation_time
EGLBoolean EGLAPIENTRY eglPresentationTimeANDROID(EGLDisplay dpy,
                                                  EGLSurface surface,
                                                  EGLnsecsANDROID time)
{
    EnsureEGLLoaded();
    return EGL_PresentationTimeANDROID(dpy, surface, time);
}

// EGL_ANGLE_device_creation
EGLDeviceEXT EGLAPIENTRY eglCreateDeviceANGLE(EGLint device_type,
                                              void *native_device,
                                              const EGLAttrib *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreateDeviceANGLE(device_type, native_device, attrib_list);
}

EGLBoolean EGLAPIENTRY eglReleaseDeviceANGLE(EGLDeviceEXT device)
{
    EnsureEGLLoaded();
    return EGL_ReleaseDeviceANGLE(device);
}

// EGL_ANGLE_external_context_and_surface
void EGLAPIENTRY eglAcquireExternalContextANGLE(EGLDisplay dpy)
{
    EnsureEGLLoaded();
    return EGL_AcquireExternalContextANGLE(dpy);
}

void EGLAPIENTRY eglReleaseExternalContextANGLE(EGLDisplay dpy)
{
    EnsureEGLLoaded();
    return EGL_ReleaseExternalContextANGLE(dpy);
}

// EGL_ANGLE_feature_control
const char *EGLAPIENTRY eglQueryStringiANGLE(EGLDisplay dpy, EGLint name, EGLint index)
{
    EnsureEGLLoaded();
    return EGL_QueryStringiANGLE(dpy, name, index);
}

EGLBoolean EGLAPIENTRY eglQueryDisplayAttribANGLE(EGLDisplay dpy,
                                                  EGLint attribute,
                                                  EGLAttrib *value)
{
    EnsureEGLLoaded();
    return EGL_QueryDisplayAttribANGLE(dpy, attribute, value);
}

// EGL_ANGLE_metal_shared_event_sync
void *EGLAPIENTRY eglCopyMetalSharedEventANGLE(EGLDisplay dpy, EGLSyncKHR sync)
{
    EnsureEGLLoaded();
    return EGL_CopyMetalSharedEventANGLE(dpy, sync);
}

// EGL_ANGLE_power_preference
void EGLAPIENTRY eglReleaseHighPowerGPUANGLE(EGLDisplay dpy, EGLContext ctx)
{
    EnsureEGLLoaded();
    return EGL_ReleaseHighPowerGPUANGLE(dpy, ctx);
}

void EGLAPIENTRY eglReacquireHighPowerGPUANGLE(EGLDisplay dpy, EGLContext ctx)
{
    EnsureEGLLoaded();
    return EGL_ReacquireHighPowerGPUANGLE(dpy, ctx);
}

void EGLAPIENTRY eglHandleGPUSwitchANGLE(EGLDisplay dpy)
{
    EnsureEGLLoaded();
    return EGL_HandleGPUSwitchANGLE(dpy);
}

void EGLAPIENTRY eglForceGPUSwitchANGLE(EGLDisplay dpy, EGLint gpuIDHigh, EGLint gpuIDLow)
{
    EnsureEGLLoaded();
    return EGL_ForceGPUSwitchANGLE(dpy, gpuIDHigh, gpuIDLow);
}

// EGL_ANGLE_prepare_swap_buffers
EGLBoolean EGLAPIENTRY eglPrepareSwapBuffersANGLE(EGLDisplay dpy, EGLSurface surface)
{
    EnsureEGLLoaded();
    return EGL_PrepareSwapBuffersANGLE(dpy, surface);
}

// EGL_ANGLE_program_cache_control
EGLint EGLAPIENTRY eglProgramCacheGetAttribANGLE(EGLDisplay dpy, EGLenum attrib)
{
    EnsureEGLLoaded();
    return EGL_ProgramCacheGetAttribANGLE(dpy, attrib);
}

void EGLAPIENTRY eglProgramCacheQueryANGLE(EGLDisplay dpy,
                                           EGLint index,
                                           void *key,
                                           EGLint *keysize,
                                           void *binary,
                                           EGLint *binarysize)
{
    EnsureEGLLoaded();
    return EGL_ProgramCacheQueryANGLE(dpy, index, key, keysize, binary, binarysize);
}

void EGLAPIENTRY eglProgramCachePopulateANGLE(EGLDisplay dpy,
                                              const void *key,
                                              EGLint keysize,
                                              const void *binary,
                                              EGLint binarysize)
{
    EnsureEGLLoaded();
    return EGL_ProgramCachePopulateANGLE(dpy, key, keysize, binary, binarysize);
}

EGLint EGLAPIENTRY eglProgramCacheResizeANGLE(EGLDisplay dpy, EGLint limit, EGLint mode)
{
    EnsureEGLLoaded();
    return EGL_ProgramCacheResizeANGLE(dpy, limit, mode);
}

// EGL_ANGLE_query_surface_pointer
EGLBoolean EGLAPIENTRY eglQuerySurfacePointerANGLE(EGLDisplay dpy,
                                                   EGLSurface surface,
                                                   EGLint attribute,
                                                   void **value)
{
    EnsureEGLLoaded();
    return EGL_QuerySurfacePointerANGLE(dpy, surface, attribute, value);
}

// EGL_ANGLE_stream_producer_d3d_texture
EGLBoolean EGLAPIENTRY eglCreateStreamProducerD3DTextureANGLE(EGLDisplay dpy,
                                                              EGLStreamKHR stream,
                                                              const EGLAttrib *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreateStreamProducerD3DTextureANGLE(dpy, stream, attrib_list);
}

EGLBoolean EGLAPIENTRY eglStreamPostD3DTextureANGLE(EGLDisplay dpy,
                                                    EGLStreamKHR stream,
                                                    void *texture,
                                                    const EGLAttrib *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_StreamPostD3DTextureANGLE(dpy, stream, texture, attrib_list);
}

// EGL_ANGLE_swap_with_frame_token
EGLBoolean EGLAPIENTRY eglSwapBuffersWithFrameTokenANGLE(EGLDisplay dpy,
                                                         EGLSurface surface,
                                                         EGLFrameTokenANGLE frametoken)
{
    EnsureEGLLoaded();
    return EGL_SwapBuffersWithFrameTokenANGLE(dpy, surface, frametoken);
}

// EGL_ANGLE_sync_control_rate
EGLBoolean EGLAPIENTRY eglGetMscRateANGLE(EGLDisplay dpy,
                                          EGLSurface surface,
                                          EGLint *numerator,
                                          EGLint *denominator)
{
    EnsureEGLLoaded();
    return EGL_GetMscRateANGLE(dpy, surface, numerator, denominator);
}

// EGL_ANGLE_vulkan_image
EGLBoolean EGLAPIENTRY eglExportVkImageANGLE(EGLDisplay dpy,
                                             EGLImage image,
                                             void *vk_image,
                                             void *vk_image_create_info)
{
    EnsureEGLLoaded();
    return EGL_ExportVkImageANGLE(dpy, image, vk_image, vk_image_create_info);
}

// EGL_ANGLE_wait_until_work_scheduled
void EGLAPIENTRY eglWaitUntilWorkScheduledANGLE(EGLDisplay dpy)
{
    EnsureEGLLoaded();
    return EGL_WaitUntilWorkScheduledANGLE(dpy);
}

// EGL_CHROMIUM_sync_control
EGLBoolean EGLAPIENTRY eglGetSyncValuesCHROMIUM(EGLDisplay dpy,
                                                EGLSurface surface,
                                                EGLuint64KHR *ust,
                                                EGLuint64KHR *msc,
                                                EGLuint64KHR *sbc)
{
    EnsureEGLLoaded();
    return EGL_GetSyncValuesCHROMIUM(dpy, surface, ust, msc, sbc);
}

// EGL_EXT_device_query
EGLBoolean EGLAPIENTRY eglQueryDeviceAttribEXT(EGLDeviceEXT device,
                                               EGLint attribute,
                                               EGLAttrib *value)
{
    EnsureEGLLoaded();
    return EGL_QueryDeviceAttribEXT(device, attribute, value);
}

const char *EGLAPIENTRY eglQueryDeviceStringEXT(EGLDeviceEXT device, EGLint name)
{
    EnsureEGLLoaded();
    return EGL_QueryDeviceStringEXT(device, name);
}

EGLBoolean EGLAPIENTRY eglQueryDisplayAttribEXT(EGLDisplay dpy, EGLint attribute, EGLAttrib *value)
{
    EnsureEGLLoaded();
    return EGL_QueryDisplayAttribEXT(dpy, attribute, value);
}

// EGL_EXT_image_dma_buf_import_modifiers
EGLBoolean EGLAPIENTRY eglQueryDmaBufFormatsEXT(EGLDisplay dpy,
                                                EGLint max_formats,
                                                EGLint *formats,
                                                EGLint *num_formats)
{
    EnsureEGLLoaded();
    return EGL_QueryDmaBufFormatsEXT(dpy, max_formats, formats, num_formats);
}

EGLBoolean EGLAPIENTRY eglQueryDmaBufModifiersEXT(EGLDisplay dpy,
                                                  EGLint format,
                                                  EGLint max_modifiers,
                                                  EGLuint64KHR *modifiers,
                                                  EGLBoolean *external_only,
                                                  EGLint *num_modifiers)
{
    EnsureEGLLoaded();
    return EGL_QueryDmaBufModifiersEXT(dpy, format, max_modifiers, modifiers, external_only,
                                       num_modifiers);
}

// EGL_EXT_platform_base
EGLSurface EGLAPIENTRY eglCreatePlatformPixmapSurfaceEXT(EGLDisplay dpy,
                                                         EGLConfig config,
                                                         void *native_pixmap,
                                                         const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreatePlatformPixmapSurfaceEXT(dpy, config, native_pixmap, attrib_list);
}

EGLSurface EGLAPIENTRY eglCreatePlatformWindowSurfaceEXT(EGLDisplay dpy,
                                                         EGLConfig config,
                                                         void *native_window,
                                                         const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreatePlatformWindowSurfaceEXT(dpy, config, native_window, attrib_list);
}

EGLDisplay EGLAPIENTRY eglGetPlatformDisplayEXT(EGLenum platform,
                                                void *native_display,
                                                const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_GetPlatformDisplayEXT(platform, native_display, attrib_list);
}

// EGL_KHR_debug
EGLint EGLAPIENTRY eglDebugMessageControlKHR(EGLDEBUGPROCKHR callback, const EGLAttrib *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_DebugMessageControlKHR(callback, attrib_list);
}

EGLint EGLAPIENTRY eglLabelObjectKHR(EGLDisplay display,
                                     EGLenum objectType,
                                     EGLObjectKHR object,
                                     EGLLabelKHR label)
{
    EnsureEGLLoaded();
    return EGL_LabelObjectKHR(display, objectType, object, label);
}

EGLBoolean EGLAPIENTRY eglQueryDebugKHR(EGLint attribute, EGLAttrib *value)
{
    EnsureEGLLoaded();
    return EGL_QueryDebugKHR(attribute, value);
}

// EGL_KHR_fence_sync
EGLint EGLAPIENTRY eglClientWaitSyncKHR(EGLDisplay dpy,
                                        EGLSyncKHR sync,
                                        EGLint flags,
                                        EGLTimeKHR timeout)
{
    EnsureEGLLoaded();
    return EGL_ClientWaitSyncKHR(dpy, sync, flags, timeout);
}

EGLSyncKHR EGLAPIENTRY eglCreateSyncKHR(EGLDisplay dpy, EGLenum type, const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreateSyncKHR(dpy, type, attrib_list);
}

EGLBoolean EGLAPIENTRY eglDestroySyncKHR(EGLDisplay dpy, EGLSyncKHR sync)
{
    EnsureEGLLoaded();
    return EGL_DestroySyncKHR(dpy, sync);
}

EGLBoolean EGLAPIENTRY eglGetSyncAttribKHR(EGLDisplay dpy,
                                           EGLSyncKHR sync,
                                           EGLint attribute,
                                           EGLint *value)
{
    EnsureEGLLoaded();
    return EGL_GetSyncAttribKHR(dpy, sync, attribute, value);
}

// EGL_KHR_image
EGLImageKHR EGLAPIENTRY eglCreateImageKHR(EGLDisplay dpy,
                                          EGLContext ctx,
                                          EGLenum target,
                                          EGLClientBuffer buffer,
                                          const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreateImageKHR(dpy, ctx, target, buffer, attrib_list);
}

EGLBoolean EGLAPIENTRY eglDestroyImageKHR(EGLDisplay dpy, EGLImageKHR image)
{
    EnsureEGLLoaded();
    return EGL_DestroyImageKHR(dpy, image);
}

// EGL_KHR_lock_surface3
EGLBoolean EGLAPIENTRY eglLockSurfaceKHR(EGLDisplay dpy,
                                         EGLSurface surface,
                                         const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_LockSurfaceKHR(dpy, surface, attrib_list);
}

EGLBoolean EGLAPIENTRY eglQuerySurface64KHR(EGLDisplay dpy,
                                            EGLSurface surface,
                                            EGLint attribute,
                                            EGLAttribKHR *value)
{
    EnsureEGLLoaded();
    return EGL_QuerySurface64KHR(dpy, surface, attribute, value);
}

EGLBoolean EGLAPIENTRY eglUnlockSurfaceKHR(EGLDisplay dpy, EGLSurface surface)
{
    EnsureEGLLoaded();
    return EGL_UnlockSurfaceKHR(dpy, surface);
}

// EGL_KHR_partial_update
EGLBoolean EGLAPIENTRY eglSetDamageRegionKHR(EGLDisplay dpy,
                                             EGLSurface surface,
                                             EGLint *rects,
                                             EGLint n_rects)
{
    EnsureEGLLoaded();
    return EGL_SetDamageRegionKHR(dpy, surface, rects, n_rects);
}

// EGL_KHR_reusable_sync
EGLBoolean EGLAPIENTRY eglSignalSyncKHR(EGLDisplay dpy, EGLSyncKHR sync, EGLenum mode)
{
    EnsureEGLLoaded();
    return EGL_SignalSyncKHR(dpy, sync, mode);
}

// EGL_KHR_stream
EGLStreamKHR EGLAPIENTRY eglCreateStreamKHR(EGLDisplay dpy, const EGLint *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_CreateStreamKHR(dpy, attrib_list);
}

EGLBoolean EGLAPIENTRY eglDestroyStreamKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    EnsureEGLLoaded();
    return EGL_DestroyStreamKHR(dpy, stream);
}

EGLBoolean EGLAPIENTRY eglQueryStreamKHR(EGLDisplay dpy,
                                         EGLStreamKHR stream,
                                         EGLenum attribute,
                                         EGLint *value)
{
    EnsureEGLLoaded();
    return EGL_QueryStreamKHR(dpy, stream, attribute, value);
}

EGLBoolean EGLAPIENTRY eglQueryStreamu64KHR(EGLDisplay dpy,
                                            EGLStreamKHR stream,
                                            EGLenum attribute,
                                            EGLuint64KHR *value)
{
    EnsureEGLLoaded();
    return EGL_QueryStreamu64KHR(dpy, stream, attribute, value);
}

EGLBoolean EGLAPIENTRY eglStreamAttribKHR(EGLDisplay dpy,
                                          EGLStreamKHR stream,
                                          EGLenum attribute,
                                          EGLint value)
{
    EnsureEGLLoaded();
    return EGL_StreamAttribKHR(dpy, stream, attribute, value);
}

// EGL_KHR_stream_consumer_gltexture
EGLBoolean EGLAPIENTRY eglStreamConsumerAcquireKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    EnsureEGLLoaded();
    return EGL_StreamConsumerAcquireKHR(dpy, stream);
}

EGLBoolean EGLAPIENTRY eglStreamConsumerGLTextureExternalKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    EnsureEGLLoaded();
    return EGL_StreamConsumerGLTextureExternalKHR(dpy, stream);
}

EGLBoolean EGLAPIENTRY eglStreamConsumerReleaseKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    EnsureEGLLoaded();
    return EGL_StreamConsumerReleaseKHR(dpy, stream);
}

// EGL_KHR_swap_buffers_with_damage
EGLBoolean EGLAPIENTRY eglSwapBuffersWithDamageKHR(EGLDisplay dpy,
                                                   EGLSurface surface,
                                                   const EGLint *rects,
                                                   EGLint n_rects)
{
    EnsureEGLLoaded();
    return EGL_SwapBuffersWithDamageKHR(dpy, surface, rects, n_rects);
}

// EGL_KHR_wait_sync
EGLint EGLAPIENTRY eglWaitSyncKHR(EGLDisplay dpy, EGLSyncKHR sync, EGLint flags)
{
    EnsureEGLLoaded();
    return EGL_WaitSyncKHR(dpy, sync, flags);
}

// EGL_NV_post_sub_buffer
EGLBoolean EGLAPIENTRY eglPostSubBufferNV(EGLDisplay dpy,
                                          EGLSurface surface,
                                          EGLint x,
                                          EGLint y,
                                          EGLint width,
                                          EGLint height)
{
    EnsureEGLLoaded();
    return EGL_PostSubBufferNV(dpy, surface, x, y, width, height);
}

// EGL_NV_stream_consumer_gltexture_yuv
EGLBoolean EGLAPIENTRY eglStreamConsumerGLTextureExternalAttribsNV(EGLDisplay dpy,
                                                                   EGLStreamKHR stream,
                                                                   const EGLAttrib *attrib_list)
{
    EnsureEGLLoaded();
    return EGL_StreamConsumerGLTextureExternalAttribsNV(dpy, stream, attrib_list);
}

}  // extern "C"
