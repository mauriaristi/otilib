#!/usr/bin/env python
"""
PyOTI Test Runner.

Executes the Python test suite to verify the installation and core math functionality.

Usage:
    python tests/run_tests.py
    python tests/python/run_tests.py
    pytest tests/python
"""

import os
import sys
import pytest


def run_all_tests():
    """
    Discover and execute all pytest test cases in tests/python.

    Returns
    -------
    int
        Exit code returned by pytest (0 for success, non-zero for failure).
    """
    repo_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

    if repo_root not in sys.path:

        sys.path.insert(0, repo_root)

    # end if

    test_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), "python")
    return pytest.main(["-v", test_dir])

# end function


if __name__ == "__main__":

    sys.exit(run_all_tests())

# end if
