# Copyright 2020 The Chromium Authors
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
"""Class for interacting with the Skia Gold image diffing service."""

import logging
import os
import platform
import shutil
import sys
import tempfile
import time
from typing import Any, Dict, List, Optional, Tuple

from skia_gold_common import skia_gold_properties

CHROMIUM_SRC = os.path.realpath(
    os.path.join(os.path.dirname(__file__), '..', '..'))

GOLDCTL_BINARY = os.path.join(CHROMIUM_SRC, 'tools', 'skia_goldctl')
if sys.platform == 'win32':
  GOLDCTL_BINARY = os.path.join(GOLDCTL_BINARY, 'win', 'goldctl') + '.exe'
elif sys.platform == 'darwin':
  machine = platform.machine().lower()
  if any(machine.startswith(m) for m in ('arm64', 'aarch64')):
    GOLDCTL_BINARY = os.path.join(GOLDCTL_BINARY, 'mac_arm64', 'goldctl')
  else:
    GOLDCTL_BINARY = os.path.join(GOLDCTL_BINARY, 'mac_amd64', 'goldctl')
else:
  GOLDCTL_BINARY = os.path.join(GOLDCTL_BINARY, 'linux', 'goldctl')


StepRetVal = Tuple[int, Optional[str]]


class SkiaGoldSession():
  class StatusCodes():
    """Status codes for RunComparison."""
    SUCCESS = 0
    AUTH_FAILURE = 1
    INIT_FAILURE = 2
    COMPARISON_FAILURE_REMOTE = 3
    COMPARISON_FAILURE_LOCAL = 4
    LOCAL_DIFF_FAILURE = 5
    NO_OUTPUT_MANAGER = 6

  class ComparisonResults():
    """Struct-like object for storing results of an image comparison."""

    def __init__(self):
      self.public_triage_link: Optional[str] = None
      self.internal_triage_link: Optional[str] = None
      self.triage_link_omission_reason: Optional[str] = None
      self.local_diff_given_image: Optional[str] = None
      self.local_diff_closest_image: Optional[str] = None
      self.local_diff_diff_image: Optional[str] = None

  def __init__(self,
               working_dir: str,
               gold_properties: skia_gold_properties.SkiaGoldProperties,
               keys_file: str,
               corpus: str,
               instance: str,
               bucket: Optional[str] = None):
    """Abstract class to handle all aspects of image comparison via Skia Gold.

    A single SkiaGoldSession is valid for a single instance/corpus/keys_file
    combination.

    Args:
      working_dir: The directory to store config files, etc.
      gold_properties: A skia_gold_properties.SkiaGoldProperties instance for
          the current test run.
      keys_file: A path to a JSON file containing various comparison config data
          such as corpus and debug information like the hardware/software
          configuration the images will be produced on.
      corpus: The corpus that images that will be compared belong to.
      instance: The name of the Skia Gold instance to interact with.
      bucket: Overrides the formulaic Google Storage bucket name generated by
          goldctl
    """
    self._working_dir = working_dir
    self._gold_properties = gold_properties
    self._corpus = corpus
    self._instance = instance
    self._bucket = bucket
    self._local_png_directory = (self._gold_properties.local_png_directory
                                 or tempfile.mkdtemp())
    with tempfile.NamedTemporaryFile(suffix='.txt',
                                     dir=working_dir,
                                     delete=False) as triage_link_file:
      self._triage_link_file = triage_link_file.name
    # A map of image name (string) to ComparisonResults for that image.
    self._comparison_results = {}
    self._authenticated = False
    self._initialized = False

    # Copy the given keys file to the working directory in case it ends up
    # getting deleted before we try to use it.
    self._keys_file = os.path.join(working_dir, 'gold_keys.json')
    shutil.copy(keys_file, self._keys_file)

  def RunComparison(self,
                    name: str,
                    png_file: str,
                    output_manager: Any,
                    inexact_matching_args: Optional[List[str]] = None,
                    use_luci: bool = True,
                    service_account: Optional[str] = None,
                    optional_keys: Optional[Dict[str, str]] = None,
                    force_dryrun: bool = False) -> StepRetVal:
    """Helper method to run all steps to compare a produced image.

    Handles authentication, itnitialization, comparison, and, if necessary,
    local diffing.

    Args:
      name: The name of the image being compared.
      png_file: A path to a PNG file containing the image to be compared.
      output_manager: An output manager to use to store diff links. The
          argument's type depends on what type a subclasses' _StoreDiffLinks
          implementation expects. Can be None even if _StoreDiffLinks expects
          a valid input, but will fail if it ever actually needs to be used.
      inexact_matching_args: A list of strings containing extra command line
          arguments to pass to Gold for inexact matching. Can be omitted to use
          exact matching.
      use_luci: If true, authentication will use the service account provided by
          the LUCI context. If false, will attempt to use whatever is set up in
          gsutil, which is only supported for local runs.
      service_account: If set, uses the provided service account instead of
          LUCI_CONTEXT or whatever is set in gsutil.
      optional_keys: A dict containing optional key/value pairs to pass to Gold
          for this comparison. Optional keys are keys unrelated to the
          configuration the image was produced on, e.g. a comment or whether
          Gold should treat the image as ignored.
      force_dryrun: A boolean denoting whether dryrun should be forced on
          regardless of whether this is a local comparison or not.

    Returns:
      A tuple (status, error). |status| is a value from
      SkiaGoldSession.StatusCodes signifying the result of the comparison.
      |error| is an error message describing the status if not successful.
    """
    auth_rc, auth_stdout = self.Authenticate(use_luci=use_luci,
                                             service_account=service_account)
    if auth_rc:
      return self.StatusCodes.AUTH_FAILURE, auth_stdout

    init_rc, init_stdout = self.Initialize()
    if init_rc:
      return self.StatusCodes.INIT_FAILURE, init_stdout

    compare_rc, compare_stdout = self.Compare(
        name=name,
        png_file=png_file,
        inexact_matching_args=inexact_matching_args,
        optional_keys=optional_keys,
        force_dryrun=force_dryrun)
    if not compare_rc:
      return self.StatusCodes.SUCCESS, None

    logging.error('Gold comparison failed: %s', compare_stdout)
    if not self._gold_properties.local_pixel_tests:
      return self.StatusCodes.COMPARISON_FAILURE_REMOTE, compare_stdout

    if not output_manager:
      return (self.StatusCodes.NO_OUTPUT_MANAGER,
              'No output manager for local diff images')

    diff_rc, diff_stdout = self.Diff(name=name,
                                     png_file=png_file,
                                     output_manager=output_manager)
    if diff_rc:
      return self.StatusCodes.LOCAL_DIFF_FAILURE, diff_stdout
    return self.StatusCodes.COMPARISON_FAILURE_LOCAL, compare_stdout

  def Authenticate(self,
                   use_luci: bool = True,
                   service_account: Optional[str] = None) -> StepRetVal:
    """Authenticates with Skia Gold for this session.

    Args:
      use_luci: If true, authentication will use the service account provided
          by the LUCI context. If false, will attempt to use whatever is set up
          in gsutil, which is only supported for local runs.
      service_account: If set, uses the provided service account instead of
          LUCI_CONTEXT or whatever is set in gsutil.

    Returns:
      A tuple (return_code, output). |return_code| is the return code of the
      authentication process. |output| is the stdout + stderr of the
      authentication process.
    """
    if self._authenticated:
      return 0, None
    if self._gold_properties.bypass_skia_gold_functionality:
      logging.warning('Not actually authenticating with Gold due to '
                      '--bypass-skia-gold-functionality being present.')
      return 0, None
    assert not (use_luci and service_account)

    auth_cmd = [GOLDCTL_BINARY, 'auth', '--work-dir', self._working_dir]
    if use_luci:
      auth_cmd.append('--luci')
    elif service_account:
      auth_cmd.extend(['--service-account', service_account])
    elif not self._gold_properties.local_pixel_tests:
      raise RuntimeError(
          'Cannot authenticate to Skia Gold with use_luci=False without a '
          'service account unless running local pixel tests')

    rc, stdout = self._RunCmdForRcAndOutput(auth_cmd)
    if rc == 0:
      self._authenticated = True
    return rc, stdout

  def Initialize(self) -> StepRetVal:
    """Initializes the working directory if necessary.

    This can technically be skipped if the same information is passed to the
    command used for image comparison, but that is less efficient under the
    hood. Doing it that way effectively requires an initialization for every
    comparison (~250 ms) instead of once at the beginning.

    Returns:
      A tuple (return_code, output). |return_code| is the return code of the
      initialization process. |output| is the stdout + stderr of the
      initialization process.
    """
    if self._initialized:
      return 0, None
    if self._gold_properties.bypass_skia_gold_functionality:
      logging.warning('Not actually initializing Gold due to '
                      '--bypass-skia-gold-functionality being present.')
      return 0, None

    init_cmd = [
        GOLDCTL_BINARY,
        'imgtest',
        'init',
        '--passfail',
        '--instance',
        self._instance,
        '--corpus',
        self._corpus,
        '--keys-file',
        self._keys_file,
        '--work-dir',
        self._working_dir,
        '--failure-file',
        self._triage_link_file,
        '--commit',
        self._gold_properties.git_revision,
    ]
    if self._bucket:
      init_cmd.extend(['--bucket', self._bucket])
    if self._gold_properties.IsTryjobRun():
      init_cmd.extend([
          '--issue',
          str(self._gold_properties.issue),
          '--patchset',
          str(self._gold_properties.patchset),
          '--jobid',
          str(self._gold_properties.job_id),
          '--crs',
          str(self._gold_properties.code_review_system),
          '--cis',
          str(self._gold_properties.continuous_integration_system),
      ])

    rc, stdout = self._RunCmdForRcAndOutput(init_cmd)
    if rc == 0:
      self._initialized = True
    return rc, stdout

  def Compare(self,
              name: str,
              png_file: str,
              inexact_matching_args: Optional[List[str]] = None,
              optional_keys: Optional[Dict[str, str]] = None,
              force_dryrun: bool = False) -> StepRetVal:
    """Compares the given image to images known to Gold.

    Triage links can later be retrieved using GetTriageLinks().

    Args:
      name: The name of the image being compared.
      png_file: A path to a PNG file containing the image to be compared.
      inexact_matching_args: A list of strings containing extra command line
          arguments to pass to Gold for inexact matching. Can be omitted to use
          exact matching.
      optional_keys: A dict containing optional key/value pairs to pass to Gold
          for this comparison. Optional keys are keys unrelated to the
          configuration the image was produced on, e.g. a comment or whether
          Gold should treat the image as ignored.
      force_dryrun: A boolean denoting whether dryrun should be forced on
          regardless of whether this is a local comparison or not.

    Returns:
      A tuple (return_code, output). |return_code| is the return code of the
      comparison process. |output| is the stdout + stderr of the comparison
      process.
    """
    if self._gold_properties.bypass_skia_gold_functionality:
      logging.warning('Not actually comparing with Gold due to '
                      '--bypass-skia-gold-functionality being present.')
      return 0, None

    compare_cmd = [
        GOLDCTL_BINARY,
        'imgtest',
        'add',
        '--test-name',
        name,
        '--png-file',
        png_file,
        '--work-dir',
        self._working_dir,
    ]
    if self._gold_properties.local_pixel_tests or force_dryrun:
      compare_cmd.append('--dryrun')
    if inexact_matching_args:
      logging.info('Using inexact matching arguments for image %s: %s', name,
                   inexact_matching_args)
      compare_cmd.extend(inexact_matching_args)

    optional_keys = optional_keys or {}
    for k, v in optional_keys.items():
      compare_cmd.extend([
          '--add-test-optional-key',
          '%s:%s' % (k, v),
      ])

    self._ClearTriageLinkFile()
    rc, stdout = self._RunCmdForRcAndOutput(compare_cmd)

    self._comparison_results[name] = self.ComparisonResults()
    if rc == 0:
      self._comparison_results[name].triage_link_omission_reason = (
          'Comparison succeeded, no triage link')
    elif self._gold_properties.IsTryjobRun():
      cl_triage_link = ('https://{instance}-gold.skia.org/cl/{crs}/{issue}')
      cl_triage_link = cl_triage_link.format(
          instance=self._instance,
          crs=self._gold_properties.code_review_system,
          issue=self._gold_properties.issue)
      self._comparison_results[name].internal_triage_link = cl_triage_link
      self._comparison_results[name].public_triage_link =\
          self._GeneratePublicTriageLink(cl_triage_link)
    else:
      try:
        with open(self._triage_link_file) as tlf:
          triage_link = tlf.read().strip()
        if not triage_link:
          self._comparison_results[name].triage_link_omission_reason = (
              'Gold did not provide a triage link. This is likely a bug on '
              "Gold's end.")
          self._comparison_results[name].internal_triage_link = None
          self._comparison_results[name].public_triage_link = None
        else:
          self._comparison_results[name].internal_triage_link = triage_link
          self._comparison_results[name].public_triage_link =\
              self._GeneratePublicTriageLink(triage_link)
      except IOError:
        self._comparison_results[name].triage_link_omission_reason = (
            'Failed to read triage link from file')
    return rc, stdout

  def Diff(self, name: str, png_file: str, output_manager: Any) -> StepRetVal:
    """Performs a local image diff against the closest known positive in Gold.

    This is used for running tests on a workstation, where uploading data to
    Gold for ingestion is not allowed, and thus the web UI is not available.

    Image links can later be retrieved using Get*ImageLink().

    Args:
      name: The name of the image being compared.
      png_file: The path to a PNG file containing the image to be diffed.
      output_manager: An output manager to use to store diff links. The
          argument's type depends on what type a subclasses' _StoreDiffLinks
          implementation expects.

    Returns:
      A tuple (return_code, output). |return_code| is the return code of the
      diff process. |output| is the stdout + stderr of the diff process.
    """
    # Instead of returning that everything is okay and putting in dummy links,
    # just fail since this should only be called when running locally and
    # --bypass-skia-gold-functionality is only meant for use on the bots.
    if self._gold_properties.bypass_skia_gold_functionality:
      raise RuntimeError(
          '--bypass-skia-gold-functionality is not supported when running '
          'tests locally.')

    output_dir = self._CreateDiffOutputDir(name)
    # TODO(skbug.com/10611): Remove this temporary work dir and instead just use
    # self._working_dir once `goldctl diff` stops clobbering the auth files in
    # the provided work directory.
    temp_work_dir = tempfile.mkdtemp()
    # shutil.copytree() fails if the destination already exists, so use a
    # subdirectory of the temporary directory.
    temp_work_dir = os.path.join(temp_work_dir, 'diff_work_dir')
    try:
      shutil.copytree(self._working_dir, temp_work_dir)
      diff_cmd = [
          GOLDCTL_BINARY,
          'diff',
          '--corpus',
          self._corpus,
          '--instance',
          self._GetDiffGoldInstance(),
          '--input',
          png_file,
          '--test',
          name,
          '--work-dir',
          temp_work_dir,
          '--out-dir',
          output_dir,
      ]
      rc, stdout = self._RunCmdForRcAndOutput(diff_cmd)
      self._StoreDiffLinks(name, output_manager, output_dir)
      return rc, stdout
    finally:
      shutil.rmtree(os.path.realpath(os.path.join(temp_work_dir, '..')))

  def GetTriageLinks(self, name: str) -> Tuple[str, str]:
    """Gets the triage links for the given image.

    Args:
      name: The name of the image to retrieve the triage link for.

    Returns:
      A tuple (public, internal). |public| is a string containing the triage
      link for the public Gold instance if it is available, or None if it is not
      available for some reason. |internal| is the same as |public|, but
      containing a link to the internal Gold instance. The reason for links not
      being available can be retrieved using GetTriageLinkOmissionReason.
    """
    comparison_results = self._comparison_results.get(name,
                                                      self.ComparisonResults())
    return (comparison_results.public_triage_link,
            comparison_results.internal_triage_link)

  def GetTriageLinkOmissionReason(self, name: str) -> str:
    """Gets the reason why a triage link is not available for an image.

    Args:
      name: The name of the image whose triage link does not exist.

    Returns:
      A string containing the reason why a triage link is not available.
    """
    if name not in self._comparison_results:
      return 'No image comparison performed for %s' % name
    results = self._comparison_results[name]
    # This method should not be called if there is a valid triage link.
    assert results.public_triage_link is None
    assert results.internal_triage_link is None
    if results.triage_link_omission_reason:
      return results.triage_link_omission_reason
    if results.local_diff_given_image:
      return 'Gold only used to do a local image diff'
    raise RuntimeError(
        'Somehow have a ComparisonResults instance for %s that should not '
        'exist' % name)

  def GetGivenImageLink(self, name: str) -> str:
    """Gets the link to the given image used for local diffing.

    Args:
      name: The name of the image that was diffed.

    Returns:
      A string containing the link to where the image is saved, or None if it
      does not exist.
    """
    assert name in self._comparison_results
    return self._comparison_results[name].local_diff_given_image

  def GetClosestImageLink(self, name: str) -> str:
    """Gets the link to the closest known image used for local diffing.

    Args:
      name: The name of the image that was diffed.

    Returns:
      A string containing the link to where the image is saved, or None if it
      does not exist.
    """
    assert name in self._comparison_results
    return self._comparison_results[name].local_diff_closest_image

  def GetDiffImageLink(self, name: str) -> str:
    """Gets the link to the diff between the given and closest images.

    Args:
      name: The name of the image that was diffed.

    Returns:
      A string containing the link to where the image is saved, or None if it
      does not exist.
    """
    assert name in self._comparison_results
    return self._comparison_results[name].local_diff_diff_image

  def _GeneratePublicTriageLink(self, internal_link: str) -> str:
    """Generates a public triage link given an internal one.

    Args:
      internal_link: A string containing a triage link pointing to an internal
          Gold instance.

    Returns:
      A string containing a triage link pointing to the public mirror of the
      link pointed to by |internal_link|.
    """
    return internal_link.replace('%s-gold' % self._instance,
                                 '%s-public-gold' % self._instance)

  def _ClearTriageLinkFile(self) -> None:
    """Clears the contents of the triage link file.

    This should be done before every comparison since goldctl appends to the
    file instead of overwriting its contents, which results in multiple triage
    links getting concatenated together if there are multiple failures.
    """
    open(self._triage_link_file, 'w').close()

  def _CreateDiffOutputDir(self, _name: str) -> str:
    # We don't use self._local_png_directory here since we want it to be
    # automatically cleaned up with the working directory. Any subclasses that
    # want to keep it around can override this method.
    return tempfile.mkdtemp(dir=self._working_dir)

  def _GetDiffGoldInstance(self) -> str:
    """Gets the Skia Gold instance to use for the Diff step.

    This can differ based on how a particular instance is set up, mainly
    depending on whether it is set up for internal results or not.
    """
    # TODO(skbug.com/10610): Decide whether to use the public or
    # non-public instance once authentication is fixed for the non-public
    # instance.
    return str(self._instance) + '-public'

  def _StoreDiffLinks(self, image_name: str, output_manager: Any,
                      output_dir: str) -> None:
    """Stores the local diff files as links.

    The ComparisonResults entry for |image_name| should have its *_image fields
    filled after this unless corresponding images were not found on disk.

    Args:
      image_name: A string containing the name of the image that was diffed.
      output_manager: An output manager used used to surface links to users,
          if necessary. The expected argument type depends on each subclasses'
          implementation of this method.
      output_dir: A string containing the path to the directory where diff
          output image files where saved.
    """
    raise NotImplementedError()

  @staticmethod
  def _RunCmdForRcAndOutput(cmd: List[str]) -> Tuple[int, str]:
    """Runs |cmd| and returns its returncode and output.

    Args:
      cmd: A list containing the command line to run.

    Returns:
      A tuple (rc, output), where, |rc| is the returncode of the command and
      |output| is the stdout + stderr of the command.
    """
    raise NotImplementedError()