//
// Copyright 2022 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// entry_point_utils:
//   These helpers are used in GL/GLES entry point routines.

#include "libANGLE/entry_points_utils.h"

#include "libANGLE/ErrorStrings.h"

namespace gl
{
bool GeneratePixelLocalStorageActiveError(const Context *context, angle::EntryPoint entryPoint)
{
    ASSERT(context->getState().getPixelLocalStorageActivePlanes() != 0);
    context->getMutableErrorSetForValidation()->validationError(entryPoint, GL_INVALID_OPERATION,
                                                                err::kPLSActive);
    return false;
}
}  // namespace gl
