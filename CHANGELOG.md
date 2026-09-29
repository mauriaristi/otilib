# Changelog

All notable changes to OTIlib are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project
adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

The version is held in the root `VERSION` file, which is the single source of truth for the C
header, the Fortran module, the Python package and the conda recipe. Use
`python tools/bump_version.py <major|minor|patch|X.Y.Z>` to bump it.

## [Unreleased]

### Added

- A semi-sparse OTI type (`PLAN-semisparse.md`), alongside the sparse types (`sotinum_t` /
  `arrso_t`), with conversions both ways: a dense representation over a sorted list of active
  bases, aimed at FEM/CFD-style workloads with a handful to ~100 parameters at moderate truncation
  order.
  - C: scalar `ssotinum_t`, structure-of-arrays `oarrss_t` and array-of-structures `arrss_t`
    (`ssoti_` / `oarrss_` / `arrss_` prefixes), in `src/c/semisparse/` and
    `include/oti/semisparse/`. Shared index helpers (`sshelp_*`: local/global direction numbering,
    unions, the table-vs-rank product index, per-thread workspaces) in
    `include/oti/core/semisparse.h` / `src/c/core/semisparse_helper.c`.
  - A lazily built, process-wide local product-table cache for `sshelp_get_pair()`, covering
    `(k, p, q)` combinations beyond the global multiplication table's reach (previously a per-call
    rank fallback on every multiplication): budgeted at 256 MiB by default
    (`SSHELP_CACHE_DEFAULT_MB`, overridable with `OTI_SS_TABLE_CACHE_MB`), thread-safe like
    `dhelp_get_multtabl()`. Measured about 18x faster at k=11, order 5 (1.3x -> 23x versus the
    sparse type; the global table already gave about 15x at k=10).
  - Python: `pyoti.semisparse` (scalar, AoS and SoA classes, conversions to/from `pyoti.sparse`,
    direction blocks of a SoA array as NumPy views). `pyoti.semisparse.e(hum_dir, nbases=0,
    order=0, nip=0)` creates the imaginary unit along a direction, like `pyoti.sparse.e` (C:
    `ssoti_e()`), and directions are parsed exactly as in `pyoti.sparse` (a tuple is a list of
    bases). `pyoti.semisparse.rawdir(index, order)` passes a raw global direction to any of them.
  - `tools/bench_semisparse.py`: scalar, AoS and SoA timings and memory against `pyoti.sparse` /
    `pyoti.dense`, across a `k`/order/fill/set-relation grid, each case in a fresh process
    (`--quick`, `--json`, `--compare`).
  - `tools/bench/`: C-level benchmarks of the semi-sparse types against `sotinum_t` / `arrso_t`,
    built with `-DOTI_BUILD_BENCH=ON`.
  - Tests: `tests/c/test_semisparse_{core,scalar,soa,aos,review}.c` (auto-registered by
    `tests/c/CMakeLists.txt`) and `tests/python/test_semisparse_{scalar,soa,aos}.py`.
- C interface to BLAS (`include/oti/core/lapack.h`, library `otilapack`): `oti_dgemm`, in the same
  style as the existing `oti_dgetrf` / `oti_dgetrs` / `oti_dtrsm` / `oti_dtrmm` wrappers, used by
  the semi-sparse SoA matrix product.
- Semi-sparse / sparse feature leveling (`PLAN-semisparse-sparse-leveling.md`): `import
  pyoti.semisparse as oti` runs sparse scripts unchanged, including the FEM code.
  - API parity: the sparse creators (`e`, `zero`, `one`, `number`, `zeros`, `ones`, `eye`, `array`,
    all with `nip=`), scalar and array methods (`get_deriv`, `get_im`, `set_im`, `extract_*`,
    `copy`, `real`, `nrows`/`ncols`/`size`, `dot`, `inv`, `transpose`, ...), matso-style indexing and
    slice assignment, in-place operators, and `sum`/`sub`/`mul`/`div`/`neg`/`abs`/`norm`/
    `transpose`/`dot`/`inv`/`det` with `out=`; `set_printoptions`, `short_repr`, `long_repr`.
  - Order and derivative plumbing in C (`src/c/semisparse/{scalar,soa}/utils.c`): `get_order_im`,
    `get_order_im_array`, `set_order_im_from_array`, `get_all_ims`/`get_all_derivs`, `extract_im`/
    `extract_deriv`, `trunc_dot`, `trunc_sub`, `dot_product`, `rom_eval*`, `interp1d`,
    `moving_average`, `inv_block`.
  - `pyoti.semisparse.save` / `read`: a versioned, validated binary format for `ssotinum`, `arrss`
    and `oarrss` (C `ssoti_/arrss_/oarrss_save/read`, `ssio_peek`, `ssio_strerror`).
  - Gauss-point types `ssotife` (scalar) and `oarrssfe` (matrix) at `nip` integration points (C
    `feoarrss_t`), SoA batched over the points: arithmetic with broadcasting, elementary functions,
    per-point `dot`/`inv`/`det`/`transpose`, `set_ijk`, `get_ip`, `gauss_integrate`, conversions to
    and from `sotife`/`matsofe`.
  - A semi-sparse `elm_help`, so `pyoti.fem.set_global_algebra(pyoti.semisparse)` works; its
    Jacobian computation is batched over the integration points.
  - OTI sparse matrices `lil_matrix` / `csr_matrix` with the `pyoti.sparse` API (item get/set,
    `tocsr`, conversions to and from `pyoti.sparse` and SciPy, arithmetic, derivative extractors,
    `K @ x`), `real` exposed as a SciPy CSR matrix without a copy (C `lilss_*` / `csrss_*`), and
    `solve(K, b, solver='SuperLU' | 'spilu' | 'cholesky' | 'umfpack', solver_args={})`: the real
    part is factored once and each order's right-hand side is built in C; the dense `solve` takes the
    same `out`/`solver`/`solver_args` arguments.
  - `examples/python/fem_twc.py`: the thick-walled-cylinder model as `run(algebra, ndivs, order,
    perturb_geometry=False)`, the drop-in acceptance test; `tools/bench_fem_twc.py` benchmarks it
    for both algebras (stage timings, peak RSS and heap, correctness per case).
  - `examples/notebooks/semisparse_tutorial_01.ipynb`.
  - Tests: `tests/python/test_semisparse_{api,order,io,gauss,csr}.py`,
    `tests/python/test_sparse_{io,gauss,csr}.py` (sparse oracle checks), `tests/python/
    test_fem_{elements,twc}.py`, `tests/c/test_semisparse_{utils,io,gauss,csr}.c`.
- `lil_matrix.add_block(rows, cols, block)` in `pyoti.sparse` and `pyoti.semisparse`: adds a dense
  block in place, `K[rows[a], cols[b]] += block[a, b]`, the scatter of an element matrix in one
  call (C `lilss_add_block` for semi-sparse: new entries are written straight from the block and
  stored ones over the block's active set are updated in place).

### Changed

- Semi-sparse SoA elementwise operations, functions, `matmul`, `transpose`, `add_bases` and
  `compact` no longer keep a result-sized buffer in the per-thread workspace after a call: they
  write into the destination directly (call-local scratch when it aliases an operand). After one
  `mul` of a 1000x1000 array (k = 5, order 3) the process held 439 MiB before and 11.5 MiB (the
  tables) after.
- Pinned `scikit-sparse<0.5`: 0.5 returns a tuple from `cholesky()`, which broke
  `solve(csr, b, solver='cholesky')`.
- `pyoti.fem`: mesh coordinates are built with the global algebra (`alg.array`) and
  `set_global_algebra` reports why an algebra fails its probe.
- `pyoti.semisparse.zeros` takes `nbases` as its second positional argument, as in `pyoti.sparse`
  (`bases=` stays as a keyword).
- `examples/python/fem_twc.py` allocates each element type once (it allocated for every element),
  builds the constitutive matrix once (it was built at every integration point) and scatters each
  element matrix with one `add_block` call (it made 64 Python get/add/set calls), for both
  algebras. The solution is bitwise unchanged.
- Semi-sparse kernels no longer compute a binomial coefficient per direction pair:
  `sshelp_comb()` uses 64-bit arithmetic for sets of at most 62 (it always went through a
  software 128-bit division), and the SoA elementwise, matrix, Gauss-point, CSR and truncated
  products and the element accessors (`oarrss_get_item_to`, `oarrss_set_item*`) compute each
  order's block offset once. On the TWC model (80 x 80 mesh, order 4, six bases) the element
  products take 0.56 s instead of 0.79 s, and with the example changes above the K assembly is
  11.0x faster than with `pyoti.sparse` (4.3x before).

### Removed

- The old, non-functional `src/c/semisparse/` (only `scalar/base.c` was compiled, and it referenced
  fields its own struct didn't have) and the matching `include/oti/semisparse/`,
  `include/pyoti/semisparse/`, replaced in place by the semi-sparse type above.

### Fixed

- `pyoti.sparse.read` wrote one byte past its filename buffer and misbehaved on an empty filename;
  `save`/`read` now accept non-ASCII and path-like names and raise Python exceptions for a missing
  or invalid file instead of exiting the interpreter.
- Quad9 elements: the centre shape function had a spurious factor of 0.5, so the shape functions
  summed to 0.5 at the centre.
- `oarrss_feval_to` divided by zero on an empty array with active bases.

## [1.2.1] - 2026-09-27

### Added

- Lazy, in-memory direction-helper tables: `ndirs` and `fulldir` are built at `dhelp_load` (import
  time), and each order's `multtabl` is built the first time a multiplication needs it and cached
  for the rest of the process (an OpenMP critical section makes the first build thread-safe).
  `dhelp_default_nbasis(order)` encodes the per-order basis schedule, and the Cython layer exposes
  `dHelp.get_nbasis` / `dHelp.is_multtabl_loaded` for tests.
- `tools/bench_dhelp.py`: import time, RSS after import, and `mult_dir` / multiplication timings at
  several orders (`--json`).
- `tests/c/test_dhelp.c`: checks table values against `dhelp_precompute_multiply`, including an
  OpenMP parallel first touch.

### Changed

- Import time drops from about 1.3 s to about 0.16 s, and RSS after import from about 663 MiB to
  about 262 MiB (`tools/bench_dhelp.py`). The tables built at import are about 49 MB; most of the
  rest is the per-order temporaries of `dhelp_load_tmps`. The first multiplication at a given order
  now pays a one-time table build instead of that memory being paid at import for every order (for
  example, about 340 MB and about 0.14 s for order 4).

### Removed

- `make gendata` / the `otigen` CMake target, `src/datagen/`, and the ~857 MB of precomputed
  `build/data/*.npy` tables they generated.
- The `.npy` loaders in `src/c/core/load.c` and `pyoti`'s `precompute.py`.

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
  the shape/integration-point checks.
- `matso` supports the `@` operator (`__matmul__` / `__rmatmul__`, delegating to `dot`).
- `pyoti.sparse.lu_factor(A, out=None)` and `lu_solve((lu, piv), b, out=None)`: LU factorization
  with partial pivoting of a dense `matso`, `A = P L U`, with the same conventions as
  `scipy.linalg.lu_factor` / `lu_solve` (packed factors, 0-based `int32` pivots). Pivoting is
  decided by the real part (LAPACK `dgetrf`); every imaginary order of L and U follows by real
  triangular solves (HYPAD LU, Pan, Yu and Stewart 1997, Algorithm 3.1), so no OTI division is
  performed. `lu_solve` reuses the factors for any number of right-hand sides.
- C API (`include/oti/sparse/array/algebra_lu.h`): `arrso_solve[_to]` (block solver: one real
  factorization, every order by batched real solves), `arrso_lu_factor[_to]`,
  `arrso_lu_solve[_to]`, the packing helpers (`arrso_get_real_colmajor`,
  `arrso_get_order_colmajor`, `arrso_set_order_colmajor`, `arrso_permute_rows_to`,
  `arrso_tril_to` / `arrso_triu_to`, `arrso_set_nan`, `arrso_get_nbases`) and the status codes
  `OTI_LINALG_ERR_SIZE` / `_MEMORY` / `_PIVOT`. The `_to` variants accept an output that aliases an
  input.
- C interface to LAPACK (`include/oti/core/lapack.h`, library `otilapack`): Fortran `bind(C)`
  wrappers `oti_dgetrf`, `oti_dgetrs`, `oti_dtrsm`, `oti_dtrmm` and `oti_lapack_fits()`.
- Tests: `tests/c/test_lapack.c` (wrappers), `tests/c/test_sparse_linalg.c` (det / inv / solve /
  LU of OTI arrays up to n = 7, pivoting, aliasing, singular real part), and in
  `tests/python/test_sparse_array_ops.py` an OTI-valued 4x4 `det` against sympy (all derivatives up
  to 4th order, two bases), `K inv(K) = I` in every direction for n = 3..8, `lu_factor` /
  `lu_solve` against SciPy and `solve`, FE arrays, singular real parts and the error paths.
- `tools/bench_linalg.py`: timings and correctness checks of `det`, `inv`, `inv_block` and `solve`
  (`--json`).

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
- **The build requires LAPACK / BLAS**, found by CMake's `find_package(LAPACK)` (32-bit integers,
  LP64). `OTI_BLA_VENDOR` (passed to `BLA_VENDOR`, e.g. `Apple`, `OpenBLAS`, `Generic`) selects the
  implementation; empty means CMake's default search order. `environment.yml` and the conda recipe
  add `libblas` / `liblapack`; the recipe builds with `-DOTI_BLA_VENDOR=Generic` so the package
  links conda-forge's switchable stubs.
- CMake >= 3.22 is required (`BLA_SIZEOF_INTEGER`).
- `solve` with a dense `matso` coefficient matrix runs in C (`arrso_solve_to`) instead of Python
  and SciPy; `solver` / `solver_args` only apply to a `csr_matrix`. `solve_dense` was removed.
- `inv` and `det` of arrays larger than 3x3 use the LU path; the closed forms remain for n <= 3
  (`_OTI_LINALG_CLOSED_FORM_MAX`).
- `arrso_invert_to`, `arrso_det_to`, `fearrso_invert_to` and `fearrso_det_to` return an `int`
  status instead of `void` (0 on success, > 0 singular real part, < 0 `OTI_LINALG_ERR_*`; the FE
  variants return the first nonzero status over the integration points). The allocating variants
  keep their signatures and fill the result with NaN on failure.
- `inv`, `solve`, `lu_factor` and `lu_solve` raise `numpy.linalg.LinAlgError` when the real part is
  singular, for every size (the closed forms now detect it too). `det` of a matrix larger than 3x3
  with a singular real part raises `LinAlgError` naming the limitation below.

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
- `inv` of an n x n `matso` with n >= 4 returned zeros (`arrso_invert_to`).
- `det` of an n x n `matso` with n >= 4 used a generalized Sarrus rule and was wrong
  (`arrso_det_to`).

### Known issues

- `det` of an array larger than 3x3 whose real part is singular (e.g. `diag(e1, 1, 1, 1)`) raises
  `LinAlgError` instead of returning the determinant, whose derivatives can be nonzero
  (`bug-report.md`; strict xfail `test_det_singular_real_part_4x4`).

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
