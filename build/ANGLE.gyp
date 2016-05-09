# Copyright (c) 2010 The ANGLE Project Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
    'targets':
    [
        {
            'target_name': 'All',
            'type': 'none',
            'dependencies':
            [
                '../src/angle.gyp:*',
                # For now, the tests and samples aren't needed and just add
                # dependencies that are hard to satisfy.
                # '../src/tests/tests.gyp:*',
            ],
            'conditions':
            [
                # Don't generate samples for WinRT
                ['angle_build_winrt==0',
                {
                    'dependencies':
                    [
                        # For now, the tests and samples aren't needed and just add
                        # dependencies that are hard to satisfy.
                        # '../samples/samples.gyp:*',
                    ],
                }],
            ],
        },
    ],
}
