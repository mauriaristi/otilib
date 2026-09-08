"""
Tests that the library version is consistent across every layer of the build.

The root VERSION file is the single source of truth. CMake generates the C header, the Fortran
module and the Python ``_version`` module from it, and the conda recipe reads it directly. These
tests fail if any of those copies drifts apart from the file.
"""

import os
import re

import pytest

import pyoti
import pyoti.core


#*****************************************************************************************************
def _repository_version_file():
    """
    Locates the root VERSION file of the repository checkout, if the tests run from a checkout.

    Returns
    -------
    str or None
        Absolute path to the VERSION file, or None when the tests run against an installed package
        that is detached from the source tree (e.g. a conda package under site-packages).
    """

    here = os.path.dirname(os.path.abspath(__file__))
    candidate = os.path.join(here, os.pardir, os.pardir, "VERSION")

    if os.path.isfile(candidate):

        return os.path.abspath(candidate)

    # end if

    return None

# end function

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def test_version_attributes_exist():
    """
    Checks that the package exposes the documented version attributes.
    """

    assert isinstance(pyoti.__version__, str)
    assert isinstance(pyoti.__version_info__, tuple)
    assert len(pyoti.__version_info__) == 3
    assert all(isinstance(component, int) for component in pyoti.__version_info__)

# end function

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def test_version_is_semantic():
    """
    Checks that the version string is a plain MAJOR.MINOR.PATCH triplet.
    """

    assert re.fullmatch(r"\d+\.\d+\.\d+", pyoti.__version__) is not None

# end function

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def test_version_string_matches_version_info():
    """
    Checks that the version string and the version tuple describe the same version.
    """

    expected = ".".join(str(component) for component in pyoti.__version_info__)

    assert pyoti.__version__ == expected

# end function

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def test_version_number_packing():
    """
    Checks that the packed integer version agrees with the version components.
    """

    major, minor, patch = pyoti.__version_info__

    assert pyoti.version_number() == major * 10000 + minor * 100 + patch

# end function

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def test_c_library_version_matches_python_version():
    """
    Checks that the compiled C library and the Python package report the same version.

    A mismatch means the extension modules were linked against a liboti built from a different
    version of the sources than the Python files shipped alongside them.
    """

    assert pyoti.core.c_version() == pyoti.__version__
    assert pyoti.core.c_version_info() == pyoti.__version_info__
    assert pyoti.core.c_version_number() == pyoti.version_number()

# end function

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def test_version_matches_repository_version_file():
    """
    Checks that the reported version matches the root VERSION file when running from a checkout.
    """

    version_file = _repository_version_file()

    if version_file is None:

        pytest.skip("Not running from a repository checkout; no VERSION file to compare against.")

    # end if

    with open(version_file, "r") as handle:

        expected = handle.read().strip()

    # end with

    assert pyoti.__version__ == expected

# end function

#-----------------------------------------------------------------------------------------------------
