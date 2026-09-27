# Changelog

All notable changes to OTIlib are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project
adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

The version is held in the root `VERSION` file, which is the single source of truth for the C
header, the Fortran module, the Python package and the conda recipe. Use
`python tools/bump_version.py <major|minor|patch|X.Y.Z>` to bump it.

## [Unreleased]

## [1.2.0] - 2026-09-27

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
- `tests/python/test_sparse_array_ops.py`: checks the dense `matso` array operations of
  `pyoti.sparse` (elementwise arithmetic between arrays and reals, OTI scalars and real `dmat`
  arrays; powers; math functions; `dot`, `dot_product`, `transpose`, `det`, `norm`, `inv`,
  `inv_block`, `solve`; truncation and extraction utilities, `rom_eval`, `interp1d`,
  `moving_average`) up to 4th order derivatives in two bases against `sympy`, including the `out=`
  paths of these functions and the new shape validation. FE (`matsofe`) arrays are only covered by
  the shape/integration-point checks. `inv` / `det` of arrays larger than 3x3 (still wrong) are
  strict xfails.
- `matso` supports the `@` operator (`__matmul__` / `__rmatmul__`, delegating to `dot`).

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

- `pyoti.sparse` array operations validate their operands and raise `ValueError` for mismatched
  shapes, non-square arrays, wrongly shaped `out=` holders, slice assignments of the wrong shape and
  FE (`matsofe` / `sotife`) operands with different numbers of integration points, instead of
  reaching the C core's dimension checks, which print a message and terminate the interpreter with
  `exit()` (`sparse/array/checks.pxi`). Covered entry points: the `matso` and `matsofe` arithmetic
  operators, `matso` `**`, `set` and slice assignment, `sum` / `sub` / `mul` / `div` /
  `trunc_sub`, `dot` / `trunc_dot` / `dot_product`, `det`, `inv`, `inv_block`, `transpose`,
  `solve`, `interp1d`, `gauss_integrate`, and the `out=` paths of the math and truncation /
  extraction functions. The C API keeps its behaviour.
- Functions called with `out=` whose result is a float raise `TypeError` instead of silently
  ignoring `out`: `det` / `norm` of a real `dmat`, math and truncation functions of a real number
  and `sum` / `sub` / `mul` / `div` of two reals.

### Fixed

- `soti_gem_ro_to` (and the semisparse `ssoti_gem_ro_to`) sized its temporary by the operand's
  actual order instead of its truncation order, so `soti_copy_to` terminated the process
  ("Cant change memory") whenever an operand's actual order was below its truncation order. This
  crashed `dot(dmat, matso)` and `dot_product` with a `dmat` operand for arrays of order >= 2.
- `dot(matso, dmat)` (and `dot(matsofe, dmat)`) raised `TypeError`: the dispatch tested the type
  of the left operand instead of the right one. Fixed in `pyoti.sparse`, in the static module
  template (`source_conv`, `source`) and in the 17 generated `onummXnY` modules.
- `solve` of a dense OTI system with a multi-column right-hand side returned the right-hand side's
  real part unchanged: the real solve discarded `scipy.linalg.lu_solve`'s result and relied on
  `overwrite_b`, which only works for Fortran-contiguous arrays.
- `pow(val, e, out=o)` with a `matso` exponent wrote `o` and then raised `UnboundLocalError`.
- `inv_block(arr, out=o)` left `o` with only the real part of the inverse, and
  `interp1d(x, xvals, yvals, out=o)` for a scalar `x` never wrote `o`: both rebound the local name
  that referenced `out`.
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
