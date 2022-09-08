# Copyright 2020 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
"""Utility methods for Skia Gold functionality unittests."""

import argparse
import collections
import typing
from typing import Optional

_SkiaGoldArgs = collections.namedtuple('_SkiaGoldArgs', [
    'local_pixel_tests',
    'no_luci_auth',
    'code_review_system',
    'continuous_integration_system',
    'git_revision',
    'gerrit_issue',
    'gerrit_patchset',
    'buildbucket_id',
    'bypass_skia_gold_functionality',
    'skia_gold_local_png_write_directory',
])


def createSkiaGoldArgs(local_pixel_tests: Optional[bool] = None,
                       no_luci_auth: Optional[bool] = None,
                       code_review_system: Optional[str] = None,
                       continuous_integration_system: Optional[str] = None,
                       git_revision: Optional[str] = None,
                       gerrit_issue: Optional[int] = None,
                       gerrit_patchset: Optional[int] = None,
                       buildbucket_id: Optional[int] = None,
                       bypass_skia_gold_functionality: Optional[bool] = None,
                       skia_gold_local_png_write_directory: Optional[str] = None
                       ) -> argparse.Namespace:
  return typing.cast(
      argparse.Namespace,
      _SkiaGoldArgs(local_pixel_tests, no_luci_auth, code_review_system,
                    continuous_integration_system, git_revision, gerrit_issue,
                    gerrit_patchset, buildbucket_id,
                    bypass_skia_gold_functionality,
                    skia_gold_local_png_write_directory))
