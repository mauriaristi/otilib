#!/usr/bin/env python3
"""
Bumps the OTIlib version held in the root VERSION file.

The root VERSION file is the single source of truth for the C header, the Fortran module, the Python
package and the conda recipe, so a release bump is exactly one file edit plus a changelog entry.
This script performs both, and optionally creates the annotated git tag.

Examples
--------
Bump the minor component and add a changelog section::

    python tools/bump_version.py minor

Set an explicit version and create the git tag::

    python tools/bump_version.py 2.0.0 --tag
"""

import argparse
import datetime
import os
import re
import subprocess
import sys


REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
VERSION_FILE = os.path.join(REPO_ROOT, "VERSION")
CHANGELOG_FILE = os.path.join(REPO_ROOT, "CHANGELOG.md")

VERSION_PATTERN = re.compile(r"^(\d+)\.(\d+)\.(\d+)$")

UNRELEASED_HEADING = "## [Unreleased]"


#*****************************************************************************************************
def read_version():
    """
    Reads the current version from the root VERSION file.

    Returns
    -------
    tuple of int
        The ``(major, minor, patch)`` components of the current version.

    Raises
    ------
    SystemExit
        If the VERSION file is missing or does not hold a MAJOR.MINOR.PATCH version.
    """

    if not os.path.isfile(VERSION_FILE):

        sys.exit("VERSION file not found at {}".format(VERSION_FILE))

    # end if

    with open(VERSION_FILE, "r") as handle:

        raw = handle.read().strip()

    # end with

    match = VERSION_PATTERN.match(raw)

    if match is None:

        sys.exit("VERSION file must hold a MAJOR.MINOR.PATCH version; got '{}'".format(raw))

    # end if

    return tuple(int(component) for component in match.groups())

# end function

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def resolve_target(current, spec):
    """
    Resolves the requested bump into an explicit version triplet.

    Parameters
    ----------
    current : tuple of int
        The ``(major, minor, patch)`` components of the current version.
    spec : str
        Either one of ``"major"``, ``"minor"``, ``"patch"``, or an explicit ``"X.Y.Z"`` version.

    Returns
    -------
    tuple of int
        The ``(major, minor, patch)`` components of the requested version.

    Raises
    ------
    SystemExit
        If the specification is neither a known component name nor a valid version string.
    """

    major, minor, patch = current

    if spec == "major":

        return (major + 1, 0, 0)

    # end if

    if spec == "minor":

        return (major, minor + 1, 0)

    # end if

    if spec == "patch":

        return (major, minor, patch + 1)

    # end if

    match = VERSION_PATTERN.match(spec)

    if match is None:

        sys.exit("Expected 'major', 'minor', 'patch' or an explicit X.Y.Z version; got '{}'"
                 .format(spec))

    # end if

    return tuple(int(component) for component in match.groups())

# end function

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def write_version(version):
    """
    Writes the given version to the root VERSION file.

    Parameters
    ----------
    version : tuple of int
        The ``(major, minor, patch)`` components to write.
    """

    with open(VERSION_FILE, "w") as handle:

        handle.write("{}.{}.{}\n".format(*version))

    # end with

# end function

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def update_changelog(version):
    """
    Inserts a dated section for the given version into CHANGELOG.md.

    Content already collected under an ``## [Unreleased]`` heading is moved into the new section, and
    a fresh empty ``## [Unreleased]`` heading is left in its place. The changelog is left untouched
    if it does not exist.

    Parameters
    ----------
    version : tuple of int
        The ``(major, minor, patch)`` components being released.
    """

    if not os.path.isfile(CHANGELOG_FILE):

        print("No CHANGELOG.md found; skipping changelog update.")
        return

    # end if

    with open(CHANGELOG_FILE, "r") as handle:

        content = handle.read()

    # end with

    today = datetime.date.today().isoformat()
    heading = "## [{}.{}.{}] - {}".format(version[0], version[1], version[2], today)

    if UNRELEASED_HEADING in content:

        replacement = "{}\n\n{}".format(UNRELEASED_HEADING, heading)
        content = content.replace(UNRELEASED_HEADING, replacement, 1)

    else:

        content = "{}\n\n{}\n".format(content.rstrip(), heading)

    # end if

    with open(CHANGELOG_FILE, "w") as handle:

        handle.write(content)

    # end with

# end function

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def create_tag(version):
    """
    Creates an annotated git tag for the given version.

    Parameters
    ----------
    version : tuple of int
        The ``(major, minor, patch)`` components being released.

    Raises
    ------
    SystemExit
        If the git command fails.
    """

    tag = "v{}.{}.{}".format(*version)

    try:

        subprocess.run(["git", "-C", REPO_ROOT, "tag", "-a", tag, "-m", "OTIlib {}".format(tag)],
                       check=True)

    except subprocess.CalledProcessError as error:

        sys.exit("Failed to create git tag {}: {}".format(tag, error))

    # end try

    print("Created git tag {} (not pushed).".format(tag))

# end function

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def main():
    """
    Parses the command line arguments and performs the requested version bump.

    Returns
    -------
    int
        Process exit status; zero on success.
    """

    parser = argparse.ArgumentParser(description="Bump the OTIlib version.")
    parser.add_argument("spec",
                        help="'major', 'minor', 'patch' or an explicit X.Y.Z version.")
    parser.add_argument("--tag", action="store_true",
                        help="Create an annotated git tag vX.Y.Z for the new version.")
    parser.add_argument("--dry-run", action="store_true",
                        help="Report the new version without writing any file.")

    args = parser.parse_args()

    current = read_version()
    target = resolve_target(current, args.spec)

    print("{}.{}.{} -> {}.{}.{}".format(*(current + target)))

    if args.dry_run:

        return 0

    # end if

    write_version(target)
    update_changelog(target)

    if args.tag:

        create_tag(target)

    # end if

    print("Re-run cmake so the generated version artifacts pick up the new value.")

    return 0

# end function

#-----------------------------------------------------------------------------------------------------


if __name__ == "__main__":

    sys.exit(main())

# end if
