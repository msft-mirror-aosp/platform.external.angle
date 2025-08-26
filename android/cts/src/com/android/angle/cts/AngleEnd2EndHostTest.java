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

    ITestDevice mDevice;
    private long mStartTime;

    @Option(
            name = "gtest_filter",
            description =
                    "Gtest filter. ':' separator to include next. ':-' separator to exclude next."
                            + " '*' match any string. '?' match any single character. ''")
    private String mGtestFilter = "";

    private HashSet<String> mIncludeFilters = new HashSet<>();
    private HashSet<String> mExcludeFilters = new HashSet<>();

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
            CLog.e(TAG, "Failed to parse JSON: ", e);
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
            CLog.e(TAG, "Failed to read log file: ", e);
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
            CLog.e(TAG, "Failed to read log file: ", e);
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
            listener.invocationSkipped(new SkipReason("Skip test on virtual devices", ""));
            return;
        }

        // TODO(b/431804941): Enable and test ANGLE on all new devices.
        if (!isAngleDefaultDriver()) {
            listener.invocationSkipped(new SkipReason("ANGLE is not the system driver", ""));
            return;
        }

        // Delete stale test results from old runs.
        // Note we are only deleting the results file. Leave stdout for `AngleEnd2EndTestsHelper`.
        Path testResultsPath = getDeviceFilePath(RESULTS_FILE_NAME);
        mDevice.deleteFile(testResultsPath.toString());

        try {
            // We don't have feedback for individual test progress, so set all the timeouts to the
            // same overall end2end test suite limit.
            Duration timeout = Duration.ofMinutes(20);
            DeviceTestRunOptions opts = new DeviceTestRunOptions("com.android.angle.test");
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
