# Changelog

All notable changes to OTIlib are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project
adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

The version is held in the root `VERSION` file, which is the single source of truth for the C
header, the Fortran module, the Python package and the conda recipe. Use
`python tools/bump_version.py <major|minor|patch|X.Y.Z>` to bump it.

## [Unreleased]

### Added

- `tests/python/test_sparse_scalar_functions.py`: checks every supported `pyoti.sparse` scalar
  function and operator (trigonometric, hyperbolic and their inverses, `exp`, `log`, `log10`,
  `logb`, `sqrt`, `cbrt`, `pow` with integer, real and OTI exponents, `erf`, `neg`, `abs`, and all
  real/OTI arithmetic operators) up to 6th order derivatives against exact `sympy` references, for
  both univariate derivatives and all mixed derivatives of f(x*y). Also covers the `out=` path of
  every function that accepts it, including clearing stale coefficients in the destination.
- `tests/python/test_sparse_scalar_utils.py`: unit tests for `sotinum.rom_eval` (Taylor polynomial
  and truncation error, polynomial exactness, bivariate case, basis order, omitted bases, array
  deltas, length mismatch), `truncate` (method and module function, with and without `out=`) and
  `truncate_order` (every cutoff from 0 to beyond the truncation order).
- `sympy` as a test-only dependency in `environment.yml` and the conda recipe's `test.requires`.

### Changed

- Documented the `truncate_order` semantics: the real part is the term of order zero, so
  `truncate_order(0)` returns zero (with truncation order 0), and `truncate_order(k)` keeps orders
  `0 .. k-1`. Updated the Cython docstrings of `sotinum`, `matso`, `sotife` and `matsofe`, and added
  Doxygen blocks for `soti_`, `arrso_`, `fesoti_` and `fearrso_truncate_order[_to]` in
  `include/oti/sparse/`, including memory ownership and the reallocation requirements of the `_to`
  variants.
- Python tests brought in line with the `AGENTS.md` style rules: `test_sparse_scalar.py` rewritten
  (arithmetic split into OTI-OTI and real-OTI tests, incorrect comments corrected, `oti / real`
  case added; its function tests moved to the new 6th-order suite), C-style dividers removed from
  `test_version.py`, and minor docstring and formatting fixes in `test_imports.py` and
  `run_tests.py`.

### Fixed

- The 4th derivative of `acosh` was wrong for every OTI type (sparse, dense and static):
  `der_r_acosh` in `src/c/real/function_derivatives.c` used `pow(x0, .2)` instead of
  `pow(x0, 2.)`. For example, at x = 1.7 it returned 0.0605 instead of -4.8245.
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
