// Copyright 2015 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file contains the default suppressions for AddressSanitizer.
// It should only be used under very limited circumstances such as suppressing
// a report caused by an interceptor call in a system-installed library.

#if defined(ADDRESS_SANITIZER)

// Please make sure the code below declares a single string variable
// kASanDefaultSuppressions which contains ASan suppressions delimited by
// newlines. Entries should look, for example, like:
//
//   // http://crbug.com/178677
//   "interceptor_via_lib:libsqlite3.so\n"
char kASanDefaultSuppressions[] =
    // https://crbug.com/1471542 false positive odr violations from Rust code.
    "odr_violation:^core::\n"
    "odr_violation:^object::\n"
    "odr_violation:^std::io::\n"
    "odr_violation:^serde::\n"
    "odr_violation:^serde_json_lenient::\n"
    "odr_violation:^std::panicking::\n"
    "odr_violation:^std::thread::Builder::\n"
    "odr_violation:^read_fonts::tables::\n"
    "odr_violation:^std_detect::detect::cache::\n"
    "odr_violation:^alloc::sync::\n"
    "odr_violation:^log::\n"

    // End of suppressions.
    // PLEASE READ ABOVE BEFORE ADDING NEW SUPPRESSIONS.
    "";  // Please keep this semicolon.

#endif  // ADDRESS_SANITIZER
