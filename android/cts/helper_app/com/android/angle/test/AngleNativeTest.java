/*
 * Copyright (C) 2025 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.angle.test;

import static android.view.WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE;

import android.app.NativeActivity;
import android.os.Bundle;
import android.util.Log;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public final class AngleNativeTest extends NativeActivity {
    private static final String TAG = "AngleNativeTest";
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

        return commandLineFlags;
    }

    /** Run the ANGLE end2end tests. */
    public void runEnd2EndTests() {
        Path stdoutFilePath = Paths.get(OUTPUT_DIRECTORY).resolve(STDOUT_FILENAME);

        try {
            Files.deleteIfExists(stdoutFilePath);
        } catch (IOException e) {
            Log.e(TAG, "Failed to delete stdout file '" + stdoutFilePath + "': ", e);
            // Exit the test, since the log file is inaccessible.
            throw new AssertionError("Failed to delete stdout file '" + stdoutFilePath + "'", e);
        }

        nativeRunTests(getCommandLineFlags(), "", stdoutFilePath.toString());
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // Disable input events to prevent keyDispatchingTimedOut exception from
        // ever happening when an ANR state is being detected by InputDispatcher
        // thread through sending any input to the process in testing.
        getWindow().addFlags(FLAG_NOT_FOCUSABLE);
    }

    private native void nativeRunTests(
            String commandLineFlags, String commandLineFilePath, String stdoutFileNamePath);
}
