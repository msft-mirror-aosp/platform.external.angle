#!/usr/bin/env python3
# Copyright 2023 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
"""
Updates .filelist files using data from corresponding .globlist files (or
checks whether they are up to date).

bundle_data targets require an explicit source list, but maintaining these large
lists can be cumbersome. This script aims to simplify the process of updating
these lists by either expanding globs to update file lists or check that an
existing file list matches such an expansion (i.e., checking during presubmit).

The .globlist file contains a list of globs that will be expanded to either
compare or replace a corresponding .filelist. It is possible to exclude items
from the file list with globs as well. These lines are prefixed with '-' and are
processed in order, so be sure that exclusions succeed inclusions in the list of
globs. Comments and empty lines are permitted in .globfiles; comments are
prefixed with '#'.

By convention, the base name of the .globlist and .filelist files matches the
label of their corresponding bundle_data from the .gn file. In order to ensure
that these filelists don't get stale, there should also be a PRESUBMIT.py
which uses this script to check that list is up to date.

By default, the script will update the file list to match the expanded globs.
"""

import argparse
import datetime
import difflib
import glob
import os.path
import re
import subprocess
import sys

# Character to set colors in terminal. Taken, along with the printing routine
# below, from update_deps.py.
TERMINAL_ERROR_COLOR = '\033[91m'
TERMINAL_RESET_COLOR = '\033[0m'

_HEADER = """# Copyright %d The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
# NOTE: this file is generated by build/ios/update_bundle_filelist.py
#       If it requires updating, you should get a presubmit error with
#       instructions on how to regenerate. Otherwise, do not edit.
""" % (datetime.datetime.now().year)

_HEADER_PATTERN = re.compile(r"""# Copyright [0-9]+ The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
# NOTE: this file is generated by build/ios/update_bundle_filelist.py
#       If it requires updating, you should get a presubmit error with
#       instructions on how to regenerate. Otherwise, do not edit.
""")

_HEADER_HEIGHT = 6

_START_IGNORE_EXPANSIONS_OUTSIDE_GLOBLIST_DIR = '# push(ignore-relative)'
_STOP_IGNORE_EXPANSIONS_OUTSIDE_GLOBLIST_DIR = '# pop(ignore-relative)'


def parse_filelist(filelist_name):
  try:
    with open(filelist_name) as filelist:
      unfiltered = [l for l in filelist]
      header = ''.join(unfiltered[:_HEADER_HEIGHT])
      files = sorted(l.strip() for l in unfiltered[_HEADER_HEIGHT:])
      return (files, header)
  except Exception as e:
    print_error(f'Could not read file list: {filelist_name}', f'{type(e)}: {e}')
    return []


def get_git_command_name():
  if sys.platform.startswith('win'):
    return 'git.bat'
  return 'git'


def get_tracked_files(directory, globroot, repository_root_relative, verbose):
  try:
    if os.getcwd().startswith('/google/cog/cloud'):
      files = []
      for root, _, filenames in os.walk(directory):
        files.extend([os.path.join(root, f) for f in filenames])
      return set(files)
    cmd = [get_git_command_name(), 'ls-files', '--error-unmatch', directory]
    with subprocess.Popen(cmd,
                          stdout=subprocess.PIPE,
                          stderr=subprocess.PIPE,
                          cwd=globroot) as p:
      output = p.communicate()
      if p.returncode != 0:
        if verbose:
          print_error(
              f'Could not gather a list of tracked files in {directory}',
              f'{output[1]}')
        return set()

      files = [f.decode('utf-8') for f in output[0].splitlines()]

      # Need paths to be relative to directory in order to match expansions.
      # This should happen naturally due to cwd above, but we need to take
      # special care if relative to the repository root.
      if repository_root_relative:
        files = ['//' + f for f in files]

      # Handle Windows backslashes
      files = [f.replace('\\', '/') for f in files]

      return set(files)

  except Exception as e:
    if verbose:
      print_error(f'Could not gather a list of tracked files in {directory}',
                  f'{type(e)}: {e}')
    return set()


def combine_potentially_repository_root_relative_paths(a, b):
  if b.startswith('//'):
    # If b is relative to the repository root, os.path will consider it absolute
    # and os.path.join will fail. In this case, we can simply concatenate the
    # paths.
    return (a + b, True)
  else:
    return (os.path.join(a, b), False)


def parse_and_expand_globlist(globlist_name, glob_root):
  # The following expects glob_root not to end in a trailing slash.
  if glob_root.endswith('/'):
    glob_root = glob_root[:-1]

  check_expansions_outside_globlist_dir = True
  globlist_dir = os.path.dirname(globlist_name)

  with open(globlist_name) as globlist:
    # Paths in |files| and |to_check| must use unix separators. Using a set
    # ensures no unwanted duplicates. The files in |to_check| must be in the
    # globroot or a subdirectory.
    files = set()
    to_check = set()
    for g in globlist:
      g = g.strip()

      # Ignore blank lines
      if not g:
        continue

      # Toggle error checking.
      if g == _START_IGNORE_EXPANSIONS_OUTSIDE_GLOBLIST_DIR:
        check_expansions_outside_globlist_dir = False
      elif g == _STOP_IGNORE_EXPANSIONS_OUTSIDE_GLOBLIST_DIR:
        check_expansions_outside_globlist_dir = True

      # Ignore comments.
      if not g or g.startswith('#'):
        continue

      # Exclusions are prefixed with '-'.
      is_exclusion = g.startswith('-')
      if is_exclusion:
        g = g[1:]

      (combined,
       root_relative) = combine_potentially_repository_root_relative_paths(
           glob_root, g)

      prefix_size = len(glob_root)
      if not root_relative:
        # We need to account for the separator.
        prefix_size += 1

      expansion = glob.glob(combined, recursive=True)

      # Filter out directories.
      expansion = [f for f in expansion if os.path.isfile(f)]

      if check_expansions_outside_globlist_dir:
        for f in expansion:
          relative = os.path.relpath(f, globlist_dir)
          if relative.startswith('..'):
            raise Exception(f'Globlist expansion outside globlist dir: {f}')

      # Make relative to |glob_root|.
      expansion = [f[prefix_size:] for f in expansion]

      # Handle Windows backslashes
      expansion = [f.replace('\\', '/') for f in expansion]

      # Since paths in |expansion| only use unix separators, it is safe to
      # compare for both the purpose of exclusion and addition.
      if is_exclusion:
        files = files.difference(expansion)
      else:
        files = files.union(expansion)

    # Return a sorted list.
    return sorted(files)


def compare_lists(a, b):
  differ = difflib.Differ()
  full_diff = differ.compare(a, b)
  lines = [d for d in full_diff if not d.startswith('  ')]
  additions = [l[2:] for l in lines if l.startswith('+ ')]
  removals = [l[2:] for l in lines if l.startswith('- ')]
  return (additions, removals)


def write_filelist(filelist_name, files, header):
  try:
    with open(filelist_name, 'w', encoding='utf-8', newline='') as filelist:
      if not _HEADER_PATTERN.search(header):
        header = _HEADER
      filelist.write(header)
      for file in files:
        filelist.write(f'{file}\n')
  except Exception as e:
    print_error(f'Could not write file list: {filelist_name}',
                f'{type(e)}: {e}')
    return []


def process_filelist(filelist, globlist, globroot, check=False, verbose=False):
  files_from_globlist = []
  try:
    files_from_globlist = parse_and_expand_globlist(globlist, globroot)
  except Exception as e:
    if verbose:
      print_error(f'Could not read glob list: {globlist}', f'{type(e)}: {e}')
    return 1

  (files, header) = parse_filelist(filelist)

  (additions, removals) = compare_lists(files, files_from_globlist)
  to_ignore = set()

  # Ignore additions of untracked files.
  if additions:
    directories = set([os.path.dirname(f) for f in additions])
    tracked_files = set()
    for d in directories:
      (combined,
       root_relative) = combine_potentially_repository_root_relative_paths(
           globroot, d)
      relative = os.path.relpath(combined, globroot)
      tracked_files = tracked_files.union(
          get_tracked_files(relative, globroot, root_relative, verbose))
    to_ignore = set(additions).difference(tracked_files)
    additions = [f for f in additions if f in tracked_files]

  files_from_globlist = [f for f in files_from_globlist if f not in to_ignore]

  if check:
    if not _HEADER_PATTERN.search(header):
      if verbose:
        print_error(f'Unexpected header for {filelist}', f'{header}')
      return 1
    if not additions and not removals:
      return 0
    if verbose:
      pretty_additions = ['+ ' + f for f in additions]
      pretty_removals = ['- ' + f for f in removals]
      pretty_diff = '\n'.join(pretty_additions + pretty_removals)
      print_error('File list does not match glob expansion', f'{pretty_diff}')
    return 1
  else:
    write_filelist(filelist, files_from_globlist, header)
    return 0


def main(args):
  parser = argparse.ArgumentParser(
      description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
  parser.add_argument('filelist', help='Contains one file per line')
  parser.add_argument('globlist',
                      help='Contains globs that, when expanded, '
                      'should match the filelist. Use '
                      '--help for details on syntax')
  parser.add_argument('globroot',
                      help='Directory from which globs are relative')
  parser.add_argument('-c',
                      '--check',
                      action='store_true',
                      help='Prevents modifying the file list')
  parser.add_argument('-v',
                      '--verbose',
                      action='store_true',
                      help='Use this to print details on differences')
  args = parser.parse_args()
  return process_filelist(args.filelist,
                          args.globlist,
                          args.globroot,
                          check=args.check,
                          verbose=args.verbose)


def print_error(error_message, error_info):
  """ Print the `error_message` with additional `error_info` """
  color_start, color_end = adapted_color_for_output(TERMINAL_ERROR_COLOR,
                                                    TERMINAL_RESET_COLOR)

  error_message = color_start + 'ERROR: ' + error_message + color_end
  if len(error_info) > 0:
    error_message = error_message + '\n' + error_info
  print(error_message, file=sys.stderr)


def adapted_color_for_output(color_start, color_end):
  """ Returns a the `color_start`, `color_end` tuple if the output is a
    terminal, or empty strings otherwise """
  if not sys.stdout.isatty():
    return '', ''
  return color_start, color_end


if __name__ == '__main__':
  sys.exit(main(sys.argv[1:]))
