// Copyright 2025 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// AngleNativeTest:
//   Helper to run Angle tests inside NativeActivity.

package com.android.angle.test;

import android.app.NativeActivity;
import android.os.Handler;
import android.util.Log;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public final class AngleNativeTest extends NativeActivity {
    private static final String TAG = "NativeTest";
    // On the device, maps to: /data/media/[0|10]
    // See: https://source.android.com/docs/devices/admin/multi-user-testing
    private static final String OUTPUT_DIRECTORY = "/sdcard";
    private static final String STDOUT_FILENAME = "out.txt";

    static {
        System.loadLibrary("angle_util");
        System.loadLibrary("angle_end2end_tests__library");
    }

    String getCommandLineFlags() {
        String commandLineFlags = "";
        // Generate an output.json file. On the device, translates to: /data/media/[0|10]
        commandLineFlags += "--results-directory=" + OUTPUT_DIRECTORY;

        // TODO(b/279980674): Remove filter and Enable all tests, filtered by the expectations file.
        // We want to run at least one test to exercise things, and this one is small and passing.
        commandLineFlags += " --gtest_filter=ClearTest.DefaultFramebuffer/* ";

        return commandLineFlags;
    }

    @Override
    public void onStart() {
        super.onStart();

        Path stdoutFilePath = Paths.get(OUTPUT_DIRECTORY).resolve(STDOUT_FILENAME);

        try {
            Files.deleteIfExists(stdoutFilePath);
        } catch (IOException e) {
            Log.e(TAG, "Failed to delete stdout file '" + stdoutFilePath + "': ", e);
            // Exit the test, since the log file is inaccessible.
            throw new AssertionError("Failed to delete stdout file '" + stdoutFilePath + "'", e);
        }

        final Runnable runTestsTask =
                new Runnable() {
                    @Override
                    public void run() {
                        nativeRunTests(getCommandLineFlags(), "", stdoutFilePath.toString());
                        finish();
                    }
                };
        final Handler handler = new Handler();
        final Runnable startTestThreadTask = new Runnable() {
            @Override
            public void run() {
                new Thread(runTestsTask).start();
            }
        };
        handler.post(startTestThreadTask);
    }

    private native void nativeRunTests(
            String commandLineFlags, String commandLineFilePath, String stdoutFileNamePath);
}
