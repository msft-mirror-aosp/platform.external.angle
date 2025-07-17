// Copyright 2025 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// AngleNativeTest:
//   Helper to run Angle tests inside NativeActivity.

package com.android.angle.test;

import android.app.NativeActivity;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;

import java.nio.file.Paths;

public final class AngleNativeTest extends NativeActivity {
    private static final String TAG = "NativeTest";
    private static final String OUTPUT_DIR = "/sdcard/Download";
    private static final String STDOUT_FILENAME = "out.txt";

    @Override
    public void onCreate(Bundle bundle) {
        final String angleUtilLibraryName = "angle_util";
        final String end2endTestsLibraryName = "angle_end2end_tests__library";

        try {
            // Implements ANativeActivity_onCreate etc.
            System.loadLibrary(angleUtilLibraryName);
        } catch (Throwable e) {
            Log.e(TAG, "Error loading: " + angleUtilLibraryName, e);
            throw e;
        }

        try {
            // Contains all the end2end tests.
            System.loadLibrary(end2endTestsLibraryName);
        } catch (Throwable e) {
            Log.e(TAG, "Error loading: " + end2endTestsLibraryName, e);
            throw e;
        }

        super.onCreate(bundle);
    }

    String getStdoutFilePath() {
        return Paths.get(OUTPUT_DIR, STDOUT_FILENAME).toString();
    }

    String getCommandLineFlags() {
        String commandLineFlags = "";
        // Generate an output.json file. Translates to
        // /data/media/<userID>/Download on the device.
        commandLineFlags += "--results-directory=" + OUTPUT_DIR;
        // TODO(b/279980674): Remove filter and Enable all tests, filtered by the expectations file.
        // We want to run at least one test to exercise things, and this one is small and passing.
        commandLineFlags += " --gtest_filter=MemorySizeTest.BasicUsageTexture/* ";

        return commandLineFlags;
    }

    @Override
    public void onStart() {
        super.onStart();
        final Runnable runTestsTask = new Runnable() {
            @Override
            public void run() {
                nativeRunTests(getCommandLineFlags(), "", getStdoutFilePath());
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
