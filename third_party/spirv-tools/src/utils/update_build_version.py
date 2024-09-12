#!/usr/bin/env python3

# Copyright (c) 2016 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Updates an output file with version info unless the new content is the same
# as the existing content.
#
# Args: <changes-file> <output-file>
#
# The output file will contain a line of text consisting of two C source syntax
# string literals separated by a comma:
#  - The software version deduced from the given CHANGES file.
#  - A longer string with the project name, the software version number, and
#    git commit information for the CHANGES file's directory.  The commit
#    information is the content of the FORCED_BUILD_VERSION_DESCRIPTION
#    environement variable is it exists, else the output of "git describe" if
#    that succeeds, or "git rev-parse HEAD" if that succeeds, or otherwise a
#    message containing the phrase "unknown hash".
# The string contents are escaped as necessary.

import datetime
import errno
import os
import os.path
import re
import subprocess
import logging
import sys
import time

# Format of the output generated by this script. Example:
# "v2023.1", "SPIRV-Tools v2023.1 0fc5526f2b01a0cc89192c10cf8bef77f1007a62, 2023-01-18T14:51:49"
OUTPUT_FORMAT = '"{version_tag}", "SPIRV-Tools {version_tag} {description}"\n'

def mkdir_p(directory):
    """Make the directory, and all its ancestors as required.  Any of the
    directories are allowed to already exist."""

    if directory == "":
        # We're being asked to make the current directory.
        return

    try:
        os.makedirs(directory)
    except OSError as e:
        if e.errno == errno.EEXIST and os.path.isdir(directory):
            pass
        else:
            raise

def command_output(cmd, directory):
    """Runs a command in a directory and returns its standard output stream.

    Returns (False, None) if the command fails to launch or otherwise fails.
    """
    try:
      # Set shell=True on Windows so that Chromium's git.bat can be found when
      # 'git' is invoked.
      p = subprocess.Popen(cmd,
                           cwd=directory,
                           stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE,
                           shell=os.name == 'nt')
      (stdout, _) = p.communicate()
      if p.returncode != 0:
        return False, None
    except Exception as e:
        return False, None
    return p.returncode == 0, stdout

def deduce_software_version(changes_file):
    """Returns a tuple (success, software version number) parsed from the
    given CHANGES file.

    Success is set to True if the software version could be deduced.
    Software version is undefined if success if False.
    Function expects the CHANGES file to describes most recent versions first.
    """

    # Match the first well-formed version-and-date line
    # Allow trailing whitespace in the checked-out source code has
    # unexpected carriage returns on a linefeed-only system such as
    # Linux.
    pattern = re.compile(r'^(v\d+\.\d+(-dev)?) \d\d\d\d-\d\d-\d\d\s*$')
    with open(changes_file, mode='r') as f:
        for line in f.readlines():
            match = pattern.match(line)
            if match:
                return True, match.group(1)
    return False, None


def describe(repo_path):
    """Returns a string describing the current Git HEAD version as descriptively
    as possible.

    Runs 'git describe', or alternately 'git rev-parse HEAD', in directory.  If
    successful, returns the output; otherwise returns 'unknown hash, <date>'."""

    # if we're in a git repository, attempt to extract version info
    success, output = command_output(["git", "rev-parse", "--show-toplevel"], repo_path)
    if success:
        success, output = command_output(["git", "describe", "--tags", "--match=v*", "--long"], repo_path)
        if not success:
            success, output = command_output(["git", "rev-parse", "HEAD"], repo_path)

        if success:
            # decode() is needed here for Python3 compatibility. In Python2,
            # str and bytes are the same type, but not in Python3.
            # Popen.communicate() returns a bytes instance, which needs to be
            # decoded into text data first in Python3. And this decode() won't
            # hurt Python2.
            return output.rstrip().decode()

    # This is the fallback case where git gives us no information,
    # e.g. because the source tree might not be in a git tree or
    # git is not available on the system.
    # In this case, usually use a timestamp.  However, to ensure
    # reproducible builds, allow the builder to override the wall
    # clock time with environment variable SOURCE_DATE_EPOCH
    # containing a (presumably) fixed timestamp.
    timestamp = int(os.environ.get('SOURCE_DATE_EPOCH', time.time()))
    iso_date = datetime.datetime.fromtimestamp(timestamp, datetime.timezone.utc).isoformat()
    return "unknown hash, {}".format(iso_date)

def main():
    FORMAT = '%(asctime)s %(message)s'
    logging.basicConfig(format="[%(asctime)s][%(levelname)-8s] %(message)s", datefmt="%H:%M:%S")
    if len(sys.argv) != 3:
        logging.error("usage: {} <repo-path> <output-file>".format(sys.argv[0]))
        sys.exit(1)

    changes_file_path = os.path.realpath(sys.argv[1])
    output_file_path = sys.argv[2]

    success, version = deduce_software_version(changes_file_path)
    if not success:
      logging.error("Could not deduce latest release version from {}.".format(changes_file_path))
      sys.exit(1)

    repo_path = os.path.dirname(changes_file_path)
    description = os.getenv("FORCED_BUILD_VERSION_DESCRIPTION", describe(repo_path))
    content = OUTPUT_FORMAT.format(version_tag=version, description=description)

    # Escape file content.
    content.replace('"', '\\"')

    if os.path.isfile(output_file_path):
      with open(output_file_path, 'r') as f:
        if content == f.read():
          return

    mkdir_p(os.path.dirname(output_file_path))
    with open(output_file_path, 'w') as f:
        f.write(content)

if __name__ == '__main__':
    main()
