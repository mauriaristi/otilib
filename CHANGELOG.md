# Changelog

All notable changes to OTIlib are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project
adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

The version is held in the root `VERSION` file, which is the single source of truth for the C
header, the Fortran module, the Python package and the conda recipe. Use
`python tools/bump_version.py <major|minor|patch|X.Y.Z>` to bump it.

## [Unreleased]

### Fixed

- Conda CI upload step failed with exit code 127 (`anaconda: command not found`): setup-miniconda
  activates a `test` environment rather than base, so the `anaconda` client installed into base was
  not on PATH. The workflow now calls it through `$(conda info --base)/bin/anaconda`.
- Conda CI build failed on every platform since the repository restructuring:
  - `src/c/fem/integration_points/real/base.c`: the prism integration-point block passed a
    `sotinum_t` where `fednum_get_item_k_to()` expects a `coeff_t*`. GCC 16 and clang 23 (the
    conda-forge compilers the recipe now uses) treat this as an error; the system compilers used by
    the previous recipe only warned.
  - `conda/meta.yaml`: `setuptools` added to the host requirements (conda-forge's Python 3.13 / pip
    no longer pull it in), and `{{ compiler('cxx') }}` added to the build requirements so the C++
    tests no longer fall back to the runner's system compiler. `environment.yml` gained
    `setuptools` to match. Both lines were later lost while editing the recipe's `about` section,
    which reintroduced `ModuleNotFoundError: No module named 'setuptools'` in the `oticython`
    step; they are restored, now with comments explaining why they are required.
  - Workflow: the Intel macOS job moved from the retired `macos-13` runner to `macos-15-intel`, and
    `setup-miniconda` no longer adds the `defaults` channel implicitly.
- `-Wstrict-prototypes` is now applied to C sources only instead of every Fortran file, and the
  `oticython` custom commands declare `POST_BUILD` explicitly (CMake policy CMP0175).

## [1.1.0] - 2026-09-07

### Added

- Unified versioning across all bindings, driven by the new root `VERSION` file:
  - **C**: generated `oti/version.h` with `OTI_VERSION_MAJOR/MINOR/PATCH`, `OTI_VERSION_STRING`,
    `OTI_VERSION_NUMBER` and `OTI_VERSION_ENCODE()`, plus the runtime accessors `oti_version()`,
    `oti_version_numbers()` and `oti_version_number()`.
  - **Fortran**: generated `oti_version` module exposing `OTI_VERSION_STRING`, `OTI_VERSION_MAJOR/MINOR/PATCH`
    and `OTI_VERSION_NUMBER`.
  - **Python**: `pyoti.__version__`, `pyoti.__version_info__` and `pyoti.version_number()`, plus
    `pyoti.core.c_version()`, `c_version_info()` and `c_version_number()` reporting the version of the
    linked C library so header/library mismatches are detectable at run time.
- `tools/bump_version.py` to bump the version and open a changelog section in one command.
- Version consistency tests for C (`test_c_version`), Fortran (`test_f_version`) and Python
  (`tests/python/test_version.py`), plus a `version-check` CI job and conda recipe test commands.
- The conda recipe now verifies the compilation it produces: the native suite runs via `ctest`
  during the build phase, and the full Python suite runs against the installed package during the
  test phase, so a broken build cannot produce an uploadable package.

### Changed

- The conda recipe reads its version from the root `VERSION` file instead of hardcoding it. This
  supersedes the previously hardcoded `1.0.0`, which had drifted from the CMake project version
  (`0.1`) and the `setup.py` version (`0.1`).
- `CMakeLists.txt` derives `project(oti VERSION ...)` from the `VERSION` file.

### Removed

- The unused `OTI_LIBRARY_VERSION_MAJOR` / `OTI_LIBRARY_VERSION_MINOR` CMake variables.

## [1.0.0]

Baseline release, as published to the `mauriaristi` Anaconda channel. Includes the modernization
work carried out before versioning was unified:

- Python 3.13+ support.
- NumPy 2.0+ support (`NPY_NO_DEPRECATED_API` enforced at build time).
- Cython 3 as the extension compiler.
