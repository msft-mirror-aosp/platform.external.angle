/*
 * Copyright (C) 2025 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.angle.cts;

import com.android.compatibility.common.util.PropertyUtil;
import com.android.tradefed.config.Option;
import com.android.tradefed.device.DeviceNotAvailableException;
import com.android.tradefed.device.ITestDevice;
import com.android.tradefed.log.LogUtil.CLog;
import com.android.tradefed.metrics.proto.MetricMeasurement.Metric;
import com.android.tradefed.result.FailureDescription;
import com.android.tradefed.result.FileInputStreamSource;
import com.android.tradefed.result.ITestInvocationListener;
import com.android.tradefed.result.LogDataType;
import com.android.tradefed.result.TestDescription;
import com.android.tradefed.result.error.TestErrorIdentifier;
import com.android.tradefed.result.skipped.SkipReason;
import com.android.tradefed.testtype.IDeviceTest;
import com.android.tradefed.testtype.IRemoteTest;
import com.android.tradefed.testtype.ITestCollector;
import com.android.tradefed.testtype.ITestFilterReceiver;
import com.android.tradefed.testtype.junit4.BaseHostJUnit4Test;
import com.android.tradefed.testtype.junit4.DeviceTestRunOptions;

import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONTokener;

import java.io.File;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.Duration;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Objects;
import java.util.Optional;
import java.util.Set;

public class AngleEnd2EndHostTest extends BaseHostJUnit4Test
        implements IDeviceTest, IRemoteTest, ITestCollector, ITestFilterReceiver {

    private static final String TAG = "AngleEnd2EndHostTest";

    private static final String OUTPUT_DIRECTORY = "/sdcard";
    private static final String STDOUT_FILE_NAME = "out.txt";
    private static final String RESULTS_FILE_NAME = "output.json";

    // Vendors are required to set ro.board.first_api_level property to 202604 to comply with the
    // requirement of launching new devices in Android 17. ANGLE end-to-end CTS is required on
    // new Android 17 devices and onward, even if ANGLE is not set as the system GL driver. This
    // test uses ro.vendor.api_level (equivalent to ro.board.first_api_level) to exclude devices
    // upgrading to Android 17 or later.
    private static final Integer MINIMUM_VENDOR_API_LEVEL = 202604;
    private static final String ANGLE_E2E_TEST_PKG_NAME = "com.android.angle.test";
    private static final String ANGLE_DRIVER_NAME = "angle";
    private static final String SETTINGS_GLOBAL_DRIVER_PKGS = "angle_gl_driver_selection_pkgs";
    private static final String SETTINGS_GLOBAL_DRIVER_VALUES = "angle_gl_driver_selection_values";

    ITestDevice mDevice;
    private long mStartTime;

    @Option(
            name = "gtest_filter",
            description =
                    "Gtest filter. ':' separator to include next. ':-' separator to exclude next."
                            + " '*' match any string. '?' match any single character. ''")
    private String mGtestFilter = "";

    @Option(name = "skip-api-level-check", description = "Skip API level check. Default is false.")
    private boolean mSkipApiLevelCheck = false;

    private HashSet<String> mIncludeFilters = new HashSet<>();
    private HashSet<String> mExcludeFilters = new HashSet<>();
    private String mAngleGlDriverSelectionPkgs = null;
    private String mAngleGlDriverSelectionValues = null;

    /** {@inheritDoc} */
    @Override
    public void setDevice(ITestDevice device) {
        mDevice = device;
    }

    /** {@inheritDoc} */
    @Override
    public void setCollectTestsOnly(boolean shouldCollectTest) {
        // TODO(b/432021211): Get the list of tests.
    }

    static String getGlobalSetting(ITestDevice device, String globalSetting) throws Exception {
        device.waitForDeviceAvailable();
        return device.getSetting("global", globalSetting);
    }

    static void setGlobalSetting(ITestDevice device, String globalSetting, String value)
            throws Exception {
        device.waitForDeviceAvailable();
        device.setSetting("global", globalSetting, value);
        device.executeShellCommand("am refresh-settings-cache");
    }

    private boolean selectAngleAsGlDriver() throws DeviceNotAvailableException {
        boolean result = false;
        try {
            mAngleGlDriverSelectionPkgs = getGlobalSetting(mDevice, SETTINGS_GLOBAL_DRIVER_PKGS);
            mAngleGlDriverSelectionValues =
                    getGlobalSetting(mDevice, SETTINGS_GLOBAL_DRIVER_VALUES);
            setGlobalSetting(mDevice, SETTINGS_GLOBAL_DRIVER_PKGS, ANGLE_E2E_TEST_PKG_NAME);
            setGlobalSetting(mDevice, SETTINGS_GLOBAL_DRIVER_VALUES, ANGLE_DRIVER_NAME);
            final String pkgs = getGlobalSetting(mDevice, SETTINGS_GLOBAL_DRIVER_PKGS);
            final String values = getGlobalSetting(mDevice, SETTINGS_GLOBAL_DRIVER_VALUES);
            result = pkgs.equals(ANGLE_E2E_TEST_PKG_NAME) && values.equals(ANGLE_DRIVER_NAME);
        } catch (Exception e) {
            CLog.e(
                    TAG,
                    "Exception occurred while selecting ANGLE for the test: "
                            + ANGLE_E2E_TEST_PKG_NAME);
            return false;
        }
        return result;
    }

    private void cleanUpAngleGLSettings() throws DeviceNotAvailableException {
        try {
            if (mAngleGlDriverSelectionPkgs != null) {
                if (!mAngleGlDriverSelectionPkgs.equals("null")) {
                    setGlobalSetting(
                            mDevice, SETTINGS_GLOBAL_DRIVER_PKGS, mAngleGlDriverSelectionPkgs);
                } else {
                    setGlobalSetting(mDevice, SETTINGS_GLOBAL_DRIVER_PKGS, "\"\"");
                }
            }
            if (mAngleGlDriverSelectionValues != null) {
                if (!mAngleGlDriverSelectionValues.equals("null")) {
                    setGlobalSetting(
                            mDevice, SETTINGS_GLOBAL_DRIVER_VALUES, mAngleGlDriverSelectionValues);
                } else {
                    setGlobalSetting(mDevice, SETTINGS_GLOBAL_DRIVER_VALUES, "\"\"");
                }
            }
        } catch (Exception e) {
            CLog.e(
                    TAG,
                    "Exception occurred while restoring ANGLE selection: "
                            + ANGLE_E2E_TEST_PKG_NAME);
        }
    }

    private boolean isVirtualDevice() throws DeviceNotAvailableException {
        return Objects.equals(mDevice.getProperty("ro.hardware.virtual_device"), "1");
    }

    private Path getDeviceFilePath(String filename) {
        Path outputPath = Paths.get(OUTPUT_DIRECTORY);
        return outputPath.resolve(filename);
    }

    private Optional<JSONObject> getTestResults() throws DeviceNotAvailableException {
        String testResultsPath = getDeviceFilePath(RESULTS_FILE_NAME).toString();

        String resultString = mDevice.pullFileContents(testResultsPath);
        if (resultString == null || resultString.isEmpty()) {
            CLog.e(TAG, "Error reading results file: '" + testResultsPath + "'");
            return Optional.empty();
        }

        try {
            return Optional.of(new JSONObject(new JSONTokener(resultString)));
        } catch (JSONException e) {
            CLog.e(TAG, "Failed to parse JSON: %s", e);
            CLog.e(TAG, "Results string: '" + resultString + "'");
            return Optional.empty();
        }
    }

    private void collectDeviceLogs(ITestInvocationListener listener) {
        // Separate try-catch blocks so we collect as many logs as are available, without them
        // affecting each other.
        try {
            final String stdoutPath = getDeviceFilePath(STDOUT_FILE_NAME).toString();
            final File stdoutFile = mDevice.pullFile(stdoutPath);
            if (stdoutFile != null) {
                try (FileInputStreamSource data = new FileInputStreamSource(stdoutFile)) {
                    listener.testLog("out", LogDataType.TEXT, data);
                }
            }
        } catch (DeviceNotAvailableException e) {
            CLog.e(TAG, "Failed to read log file: %s", e);
        }

        try {
            final String resultsPath = getDeviceFilePath(RESULTS_FILE_NAME).toString();
            final File resultsFile = mDevice.pullFile(resultsPath);
            if (resultsFile != null) {
                try (FileInputStreamSource data = new FileInputStreamSource(resultsFile)) {
                    listener.testLog("output", LogDataType.JSON, data);
                }
            }
        } catch (DeviceNotAvailableException e) {
            CLog.e(TAG, "Failed to read log file: %s", e);
        }
    }

    private void parseResults(ITestInvocationListener listener, JSONObject jsonOutput) {
        class TestResult {
            private final String mTestName;
            private final String mActual;
            private final String mExpected;

            TestResult(String testNameIn, String actualIn, String expectedIn) {
                mTestName = testNameIn;
                mActual = actualIn;
                mExpected = expectedIn;
            }

            public String toString() {
                return mTestName + " actual: " + mActual + " expected: " + mExpected;
            }
        }

        final HashMap<String, TestResult> testResults = new HashMap<>();

        // Build up a map of test name:result, so we can know we have good data before "starting"
        // the test run and recording results.
        try {
            JSONObject tests = jsonOutput.getJSONObject("tests");
            Iterator<String> keys = tests.keys();
            while (keys.hasNext()) {
                String testName = keys.next();
                JSONObject testResult = tests.getJSONObject(testName);
                String actual = testResult.getString("actual");
                String expected = testResult.getString("expected");
                testResults.put(testName, new TestResult(testName, actual, expected));
            }
        } catch (JSONException e) {
            // Mark the whole invocation as failed, since we haven't started recording the test
            // results yet.
            String errorMsg = String.format("Failed to parse test results JSON: %s", e);
            FailureDescription failure =
                    FailureDescription.create(errorMsg)
                            .setErrorIdentifier(TestErrorIdentifier.OUTPUT_PARSER_ERROR);
            listener.invocationFailed(failure);
            return;
        }

        // We have valid results, so "start" the test run.
        // TODO(b/432021211): Get the number of tests from the device before running the tests, so
        // we can validate everything ran as expected.
        listener.testRunStarted("CtsAngleEnd2EndTestCases", testResults.size());

        // Record the available test results.
        for (Map.Entry<String, TestResult> testResult : testResults.entrySet()) {
            TestResult result = testResult.getValue();
            final TestDescription testId =
                    new TestDescription(getClass().getCanonicalName(), result.mTestName);

            listener.testStarted(testId);

            // We don't want testSkipped() here, because "skipped" in tradefed implies it was
            // unexpected, which is not the case for the ANGLE end2end tests. We do actually
            // want to fully ignore any SKIP results.
            if (result.mActual.equals("SKIP")) {
                listener.testIgnored(testId);
            } else if (!result.mActual.equals("PASS") && result.mExpected.equals("PASS")) {
                listener.testFailed(testId, result.toString());
            }

            listener.testEnded(testId, new HashMap<String, Metric>());
        }

        // Mark the run as failed if it was interrupted.
        try {
            if (jsonOutput.getBoolean("interrupted")) {
                String errorLog = "ANGLE end2end tests were interrupted!";
                listener.testRunFailed(errorLog);
            }
        } catch (JSONException e) {
            String errorLog = String.format("Failed to parse test results JSON: %s", e);
            listener.testRunFailed(errorLog);
        }

        // The "start" must be balanced with an "end".
        listener.testRunEnded(
                System.currentTimeMillis() - mStartTime, new HashMap<String, Metric>());
    }

    private boolean isAngleDefaultDriver() throws DeviceNotAvailableException {
        String eglDriver = mDevice.executeShellCommand("getprop ro.hardware.egl").trim();
        return eglDriver.equals("angle");
    }

    /** {@inheritDoc} */
    @Override
    public void run(ITestInvocationListener listener) throws DeviceNotAvailableException {
        mStartTime = System.currentTimeMillis();

        if (isVirtualDevice()) {
            CLog.i("Skipping invocation: Running on a virtual device");
            listener.invocationSkipped(new SkipReason("Skip test on virtual devices", ""));
            return;
        }

        if (!isAngleDefaultDriver()) {
            if (mSkipApiLevelCheck
                    || PropertyUtil.getVsrApiLevel(mDevice) >= MINIMUM_VENDOR_API_LEVEL) {
                if (!selectAngleAsGlDriver()) {
                    final String errorMsg = "Failed to select ANGLE as the GL driver for the test";
                    CLog.i("Skipping invocation: " + errorMsg);
                    listener.invocationSkipped(new SkipReason(errorMsg, ""));
                    return;
                }
            } else {
                final String errorMsg =
                        "ANGLE is not the system driver, vendor API level is "
                                + PropertyUtil.getVsrApiLevel(mDevice);
                CLog.i("Skipping invocation: " + errorMsg);
                listener.invocationSkipped(new SkipReason(errorMsg, ""));
                return;
            }
        }

        // Delete stale test results from old runs.
        // Note we are only deleting the results file. Leave stdout for `AngleEnd2EndTestsHelper`.
        Path testResultsPath = getDeviceFilePath(RESULTS_FILE_NAME);
        mDevice.deleteFile(testResultsPath.toString());

        try {
            // We don't have feedback for individual test progress, so set all the timeouts to the
            // same overall end2end test suite limit.
            Duration timeout = Duration.ofMinutes(20);
            DeviceTestRunOptions opts = new DeviceTestRunOptions(ANGLE_E2E_TEST_PKG_NAME);
            opts.setTestClassName("com.android.angle.test.AngleEnd2EndTest");
            opts.setTestMethodName("testAngleEnd2End");
            opts.setTestTimeoutMs(timeout.toMillis());
            opts.setMaxTimeToOutputMs(timeout.toMillis());
            opts.setMaxInstrumentationTimeoutMs(timeout.toMillis());
            String gtestFilter = String.join("*:", mIncludeFilters);
            if (gtestFilter.isEmpty()) {
                gtestFilter = mGtestFilter;
            } else {
                gtestFilter += "*:" + mGtestFilter;
            }
            CLog.d(TAG, "gtest_filter: \"" + gtestFilter + "\"");
            if (!gtestFilter.isEmpty()) {
                // Skip sending an arg if it's an empty string to avoid causing the invocation
                // error.
                opts.addInstrumentationArg("gtest_filter", gtestFilter);
            }
            runDeviceTests(opts);
        } catch (DeviceNotAvailableException e) {
            // Only handle DeviceNotAvailableException and mark the whole invocation as failed,
            // since it means we can't get any device logs or results to parse for pass/fail/crash.
            String errorMsg = String.format("Device lost: %s", e);
            FailureDescription failure =
                    FailureDescription.create(errorMsg)
                            .setErrorIdentifier(TestErrorIdentifier.TEST_ABORTED);
            listener.invocationFailed(failure);
        } finally {
            // Always collect and parse the logs, regardless of pass/fail/crash. This should make it
            // easier to determine which test crashed, if one occurs.
            collectDeviceLogs(listener);

            Optional<JSONObject> testResults = getTestResults();
            if (testResults.isEmpty()) {
                String errorMsg = "Failed to get test results";
                // Mark the whole invocation as failed, since we haven't started recording the test
                // results yet.
                FailureDescription failure =
                        FailureDescription.create(errorMsg)
                                .setErrorIdentifier(TestErrorIdentifier.OUTPUT_PARSER_ERROR);
                listener.invocationFailed(failure);
            } else {
                parseResults(listener, testResults.get());
            }

            cleanUpAngleGLSettings();
        }
    }

    /** {@inheritDoc} */
    @Override
    public void addIncludeFilter(String filter) {
        mIncludeFilters.add(filter);
    }

    /** {@inheritDoc} */
    @Override
    public void addAllIncludeFilters(Set<String> filters) {
        mIncludeFilters.addAll(filters);
    }

    /** {@inheritDoc} */
    @Override
    public Set<String> getIncludeFilters() {
        return mIncludeFilters;
    }

    /** {@inheritDoc} */
    @Override
    public void clearIncludeFilters() {
        mIncludeFilters.clear();
    }

    /** {@inheritDoc} */
    @Override
    public void addExcludeFilter(String filter) {
        CLog.w(TAG, "Unexpected use of addExcludeFilter()");
        mExcludeFilters.add(filter);
    }

    /** {@inheritDoc} */
    @Override
    public void addAllExcludeFilters(Set<String> filters) {
        if (!filters.isEmpty()) {
            CLog.w(TAG, "Unexpected use of addAllExcludeFilters()");
        }
        mExcludeFilters.addAll(filters);
    }

    /** {@inheritDoc} */
    @Override
    public Set<String> getExcludeFilters() {
        CLog.w(TAG, "Unexpected use of getExcludeFilters()");
        return mExcludeFilters;
    }

    /** {@inheritDoc} */
    @Override
    public void clearExcludeFilters() {
        CLog.w(TAG, "Unexpected use of clearExcludeFilters()");
        mExcludeFilters.clear();
    }
}
