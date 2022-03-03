// GENERATED FILE - DO NOT EDIT.
// Generated by generate_entry_points.py using data from egl.xml and egl_angle_ext.xml.
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// egl_ext_stubs_autogen.h: Stubs for EXT extension entry points.

#ifndef LIBGLESV2_EGL_EXT_STUBS_AUTOGEN_H_
#define LIBGLESV2_EGL_EXT_STUBS_AUTOGEN_H_

#include <EGL/egl.h>
#include <EGL/eglext.h>

#include "common/PackedEGLEnums_autogen.h"

namespace gl
{
class Context;
}  // namespace gl

namespace egl
{
class AttributeMap;
class Device;
class Display;
class Image;
class Stream;
class Surface;
class Sync;
class Thread;
struct Config;

EGLint ClientWaitSyncKHR(Thread *thread,
                         egl::Display *dpyPacked,
                         Sync *syncPacked,
                         EGLint flags,
                         EGLTimeKHR timeout);
EGLImageKHR CreateImageKHR(Thread *thread,
                           egl::Display *dpyPacked,
                           gl::Context *ctxPacked,
                           EGLenum target,
                           EGLClientBuffer buffer,
                           const AttributeMap &attrib_listPacked);
EGLClientBuffer CreateNativeClientBufferANDROID(Thread *thread,
                                                const AttributeMap &attrib_listPacked);
EGLSurface CreatePlatformPixmapSurfaceEXT(Thread *thread,
                                          egl::Display *dpyPacked,
                                          Config *configPacked,
                                          void *native_pixmap,
                                          const AttributeMap &attrib_listPacked);
EGLSurface CreatePlatformWindowSurfaceEXT(Thread *thread,
                                          egl::Display *dpyPacked,
                                          Config *configPacked,
                                          void *native_window,
                                          const AttributeMap &attrib_listPacked);
EGLStreamKHR CreateStreamKHR(Thread *thread,
                             egl::Display *dpyPacked,
                             const AttributeMap &attrib_listPacked);
EGLSyncKHR CreateSyncKHR(Thread *thread,
                         egl::Display *dpyPacked,
                         EGLenum type,
                         const AttributeMap &attrib_listPacked);
EGLint DebugMessageControlKHR(Thread *thread,
                              EGLDEBUGPROCKHR callback,
                              const AttributeMap &attrib_listPacked);
EGLBoolean DestroyImageKHR(Thread *thread, egl::Display *dpyPacked, Image *imagePacked);
EGLBoolean DestroyStreamKHR(Thread *thread, egl::Display *dpyPacked, Stream *streamPacked);
EGLBoolean DestroySyncKHR(Thread *thread, egl::Display *dpyPacked, Sync *syncPacked);
EGLint DupNativeFenceFDANDROID(Thread *thread, egl::Display *dpyPacked, Sync *syncPacked);
EGLClientBuffer GetNativeClientBufferANDROID(Thread *thread, const struct AHardwareBuffer *buffer);
EGLDisplay GetPlatformDisplayEXT(Thread *thread,
                                 EGLenum platform,
                                 void *native_display,
                                 const AttributeMap &attrib_listPacked);
EGLBoolean GetSyncAttribKHR(Thread *thread,
                            egl::Display *dpyPacked,
                            Sync *syncPacked,
                            EGLint attribute,
                            EGLint *value);
EGLint LabelObjectKHR(Thread *thread,
                      egl::Display *displayPacked,
                      ObjectType objectTypePacked,
                      EGLObjectKHR object,
                      EGLLabelKHR label);
EGLBoolean LockSurfaceKHR(Thread *thread,
                          egl::Display *dpyPacked,
                          Surface *surfacePacked,
                          const AttributeMap &attrib_listPacked);
EGLBoolean PostSubBufferNV(Thread *thread,
                           egl::Display *dpyPacked,
                           Surface *surfacePacked,
                           EGLint x,
                           EGLint y,
                           EGLint width,
                           EGLint height);
EGLBoolean PresentationTimeANDROID(Thread *thread,
                                   egl::Display *dpyPacked,
                                   Surface *surfacePacked,
                                   EGLnsecsANDROID time);
EGLBoolean GetCompositorTimingSupportedANDROID(Thread *thread,
                                               egl::Display *dpyPacked,
                                               Surface *surfacePacked,
                                               CompositorTiming namePacked);
EGLBoolean GetCompositorTimingANDROID(Thread *thread,
                                      egl::Display *dpyPacked,
                                      Surface *surfacePacked,
                                      EGLint numTimestamps,
                                      const EGLint *names,
                                      EGLnsecsANDROID *values);
EGLBoolean GetNextFrameIdANDROID(Thread *thread,
                                 egl::Display *dpyPacked,
                                 Surface *surfacePacked,
                                 EGLuint64KHR *frameId);
EGLBoolean GetFrameTimestampSupportedANDROID(Thread *thread,
                                             egl::Display *dpyPacked,
                                             Surface *surfacePacked,
                                             Timestamp timestampPacked);
EGLBoolean GetFrameTimestampsANDROID(Thread *thread,
                                     egl::Display *dpyPacked,
                                     Surface *surfacePacked,
                                     EGLuint64KHR frameId,
                                     EGLint numTimestamps,
                                     const EGLint *timestamps,
                                     EGLnsecsANDROID *values);
EGLBoolean QueryDebugKHR(Thread *thread, EGLint attribute, EGLAttrib *value);
EGLBoolean QueryDeviceAttribEXT(Thread *thread,
                                Device *devicePacked,
                                EGLint attribute,
                                EGLAttrib *value);
const char *QueryDeviceStringEXT(Thread *thread, Device *devicePacked, EGLint name);
EGLBoolean QueryDisplayAttribEXT(Thread *thread,
                                 egl::Display *dpyPacked,
                                 EGLint attribute,
                                 EGLAttrib *value);
EGLBoolean QueryDmaBufFormatsEXT(Thread *thread,
                                 egl::Display *dpyPacked,
                                 EGLint max_formats,
                                 EGLint *formats,
                                 EGLint *num_formats);
EGLBoolean QueryDmaBufModifiersEXT(Thread *thread,
                                   egl::Display *dpyPacked,
                                   EGLint format,
                                   EGLint max_modifiers,
                                   EGLuint64KHR *modifiers,
                                   EGLBoolean *external_only,
                                   EGLint *num_modifiers);
EGLBoolean QueryStreamKHR(Thread *thread,
                          egl::Display *dpyPacked,
                          Stream *streamPacked,
                          EGLenum attribute,
                          EGLint *value);
EGLBoolean QueryStreamu64KHR(Thread *thread,
                             egl::Display *dpyPacked,
                             Stream *streamPacked,
                             EGLenum attribute,
                             EGLuint64KHR *value);
EGLBoolean QuerySurface64KHR(Thread *thread,
                             egl::Display *dpyPacked,
                             Surface *surfacePacked,
                             EGLint attribute,
                             EGLAttribKHR *value);
EGLBoolean QuerySurfacePointerANGLE(Thread *thread,
                                    egl::Display *dpyPacked,
                                    Surface *surfacePacked,
                                    EGLint attribute,
                                    void **value);
void SetBlobCacheFuncsANDROID(Thread *thread,
                              egl::Display *dpyPacked,
                              EGLSetBlobFuncANDROID set,
                              EGLGetBlobFuncANDROID get);
EGLBoolean SetDamageRegionKHR(Thread *thread,
                              egl::Display *dpyPacked,
                              Surface *surfacePacked,
                              EGLint *rects,
                              EGLint n_rects);
EGLBoolean SignalSyncKHR(Thread *thread, egl::Display *dpyPacked, Sync *syncPacked, EGLenum mode);
EGLBoolean StreamAttribKHR(Thread *thread,
                           egl::Display *dpyPacked,
                           Stream *streamPacked,
                           EGLenum attribute,
                           EGLint value);
EGLBoolean StreamConsumerAcquireKHR(Thread *thread, egl::Display *dpyPacked, Stream *streamPacked);
EGLBoolean StreamConsumerGLTextureExternalKHR(Thread *thread,
                                              egl::Display *dpyPacked,
                                              Stream *streamPacked);
EGLBoolean StreamConsumerGLTextureExternalAttribsNV(Thread *thread,
                                                    egl::Display *dpyPacked,
                                                    Stream *streamPacked,
                                                    const AttributeMap &attrib_listPacked);
EGLBoolean StreamConsumerReleaseKHR(Thread *thread, egl::Display *dpyPacked, Stream *streamPacked);
EGLBoolean SwapBuffersWithDamageKHR(Thread *thread,
                                    egl::Display *dpyPacked,
                                    Surface *surfacePacked,
                                    const EGLint *rects,
                                    EGLint n_rects);
EGLBoolean UnlockSurfaceKHR(Thread *thread, egl::Display *dpyPacked, Surface *surfacePacked);
EGLint WaitSyncKHR(Thread *thread, egl::Display *dpyPacked, Sync *syncPacked, EGLint flags);
EGLDeviceEXT CreateDeviceANGLE(Thread *thread,
                               EGLint device_type,
                               void *native_device,
                               const EGLAttrib *attrib_list);
EGLBoolean ReleaseDeviceANGLE(Thread *thread, Device *devicePacked);
EGLBoolean CreateStreamProducerD3DTextureANGLE(Thread *thread,
                                               egl::Display *dpyPacked,
                                               Stream *streamPacked,
                                               const AttributeMap &attrib_listPacked);
EGLBoolean StreamPostD3DTextureANGLE(Thread *thread,
                                     egl::Display *dpyPacked,
                                     Stream *streamPacked,
                                     void *texture,
                                     const AttributeMap &attrib_listPacked);
EGLBoolean GetMscRateANGLE(Thread *thread,
                           egl::Display *dpyPacked,
                           Surface *surfacePacked,
                           EGLint *numerator,
                           EGLint *denominator);
EGLBoolean GetSyncValuesCHROMIUM(Thread *thread,
                                 egl::Display *dpyPacked,
                                 Surface *surfacePacked,
                                 EGLuint64KHR *ust,
                                 EGLuint64KHR *msc,
                                 EGLuint64KHR *sbc);
EGLint ProgramCacheGetAttribANGLE(Thread *thread, egl::Display *dpyPacked, EGLenum attrib);
void ProgramCacheQueryANGLE(Thread *thread,
                            egl::Display *dpyPacked,
                            EGLint index,
                            void *key,
                            EGLint *keysize,
                            void *binary,
                            EGLint *binarysize);
void ProgramCachePopulateANGLE(Thread *thread,
                               egl::Display *dpyPacked,
                               const void *key,
                               EGLint keysize,
                               const void *binary,
                               EGLint binarysize);
EGLint ProgramCacheResizeANGLE(Thread *thread, egl::Display *dpyPacked, EGLint limit, EGLint mode);
const char *QueryStringiANGLE(Thread *thread, egl::Display *dpyPacked, EGLint name, EGLint index);
EGLBoolean SwapBuffersWithFrameTokenANGLE(Thread *thread,
                                          egl::Display *dpyPacked,
                                          Surface *surfacePacked,
                                          EGLFrameTokenANGLE frametoken);
EGLBoolean PrepareSwapBuffersANGLE(EGLDisplay dpy, EGLSurface surface);
void ReleaseHighPowerGPUANGLE(Thread *thread, egl::Display *dpyPacked, gl::Context *ctxPacked);
void ReacquireHighPowerGPUANGLE(Thread *thread, egl::Display *dpyPacked, gl::Context *ctxPacked);
void HandleGPUSwitchANGLE(Thread *thread, egl::Display *dpyPacked);
EGLBoolean QueryDisplayAttribANGLE(Thread *thread,
                                   egl::Display *dpyPacked,
                                   EGLint attribute,
                                   EGLAttrib *value);
EGLBoolean ExportVkImageANGLE(Thread *thread,
                              egl::Display *dpyPacked,
                              Image *imagePacked,
                              void *vk_image,
                              void *vk_image_create_info);
}  // namespace egl
#endif  // LIBGLESV2_EGL_EXT_STUBS_AUTOGEN_H_
