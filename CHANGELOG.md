# Changelog

All notable changes to OTIlib are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project
adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

The version is held in the root `VERSION` file, which is the single source of truth for the C
header, the Fortran module, the Python package and the conda recipe. Use
`python tools/bump_version.py <major|minor|patch|X.Y.Z>` to bump it.

## [Unreleased]

Development toward 2.0.0 (`PLAN-ndarray.md`). 2.0.0 breaks the Python API: see Breaking, and
[Migrating to OTIlib 2.0](doc/source/migrating_to_2_0.rst).

### Breaking

Details, before/after recipes and a checklist: [Migrating to OTIlib 2.0](doc/source/migrating_to_2_0.rst).

1. **NumPy indexing** in `pyoti.dense`, `pyoti.semisparse`, `pyoti.sparse` and `pyoti.real.dmat`:
   an integer index drops its axis (`A[i]` is 1-D, `A[:, j]` is 1-D), negative indices work
   everywhere, `None` / `...` are supported, and `len()` / iteration run over the first axis. All
   integers give an OTI scalar. The Gauss types keep the matrix indexing rule.
2. **Creators return NumPy shapes**: `zeros(n)` and `array(1-D)` give `(n,)`, and `array(scalar)`
   gives a 0-D array. Write `zeros((n, 1))` for a column.
3. **Assignment broadcasts as NumPy does**: an `(n, 1)` column no longer fits an `(n,)` target.
4. **Views**: in `pyoti.dense` (`omat`) basic slices, `.T` and `reshape` are views and writes reach
   the parent. Whether a slice result shares memory is algebra-dependent; do not rely on either.
5. **Read-only exports**: `.real` (all algebras), `get_block` and `csr_matrix.real` (all three
   algebras) are read-only. Use `.copy()`, `get_block(d, writeable=True)` or
   `csr_matrix.get_real(writeable=True)`. Unchanged: static arrays (provisional), sparse Gauss
   `.real` (a `dmatfe` object) and `dmat.to_numpy()`.
6. **Growth with live views or exports raises `BufferError`** (dense, and now semi-sparse). Size
   arrays up front with `reserve`, `nbases=` / `bases=` / `order=`.
7. **`nbases=` reserves the layout** of dense arrays (`active_bases` reports `1..nbases`; `nbases=0`,
   the default, reserves nothing; a hint too large for the memory budget raises `MemoryError`) and of
   `elm_help` helper fields. Scalar creators are unchanged.
8. **1-D products follow NumPy**: `dot(x, y)` of 1-D arrays is a scalar, and `A @ x` is 1-D.
9. **Saved files are version 2**: 1.x cannot read them; 2.0 reads 1.x files.
10. **`nrows` / `ncols` are deprecated**; use `shape`.
11. **Static array classes are provisional** and will follow `pyoti.dense` in a later 2.x.

New, not breaking: `layout=` (`'C'` / `'F'`; default `'F'` for SoA arrays) in the creators, and
`reserve()`.

### Added

- n-dimensional double arrays in the real module, C only so far (`include/oti/real/ndarray.h`,
  `src/c/real_ndarray.c`, `src/c/real/ndarray/`):
  - `ndarr_t` descriptors (rank 0 to 32, strides in elements, possibly negative or zero) over a
    reference-counted `nd_buffer_t` with an atomic state word, exports and a layout lock for growth;
  - a descriptor validator, checked size arithmetic, the PEP 3118 / DLPack format table, `nd_import`
    (zero-copy or converting), overlap queries and the `oti_view` mapping;
  - creators (`empty`, `empty_like`, `zeros`, `ones`, `full`, `eye`, `arange`, `linspace`), strided
    allocation (`nd_alloc_strided`, e.g. the dense SoA block layout), a checked relayout after growth
    (`nd_set_layout`), `copy`, `reshape`, `ascontiguous`, `asfortran`, and basic views (integer,
    slice, newaxis, ellipsis, transpose, swapaxes, squeeze, expand_dims, read-only broadcast_to and
    diagonal);
  - a multi-operand strided iterator; elementwise `+ - * /`, `pow`, `maximum`, `minimum` with
    broadcasting, scalar operands and `out=` (NumPy aliasing semantics), results in the memory
    layout of the inputs; 30 unary math functions; `assign` and `fill`;
  - every buffer the library allocates can grow while it is not shared.
- Execution layer (`include/oti/core/exec.h`, `src/c/core/exec.c`): `oti_ctx` contexts with byte
  budgets and per-thread / per-context last errors, `oti_status_string`, and `oti_serial_for` /
  `oti_parallel_for` with fixed chunking and the lowest-failing-chunk error rule (serial and
  OpenMP backends).
- Library-wide status codes, `include/oti/core/status.h`.
- Reductions (`sum`, `prod`, `min`, `max`, `argmin`, `argmax`, `mean`, `var`, `std`, `any`, `all`)
  with `axis` / `keepdims` / `out=`, bit-identical at every thread count; comparisons into `uint8`
  masks and mask operators; parallel elementwise and reduction kernels chosen by a cost model
  (`oti_exec_plan`), and a fast path for operands of one layout.
- BLAS / LAPACK through C wrappers (`include/oti/core/lapack.h`, `src/c/core/lapack.c`) with a
  provider table and a run-time probe (Accelerate `$NEWLAPACK`, OpenBLAS, MKL, BLIS): `matmul`,
  `dot`, `gemm`, `gemv`, `ger`, level 1; LU (also on stacks), `solve` / `lu_solve` / `cho_solve` /
  `solve_triangular` with in-place `_to` forms, `inv`, `det` (from `slogdet`), `slogdet`,
  Cholesky.
- `darr_t` adapters (`include/oti/real/ndarray/compat_darr.h`).
- Python: the private `pyoti.real._ndtest` handle and the `cdef` API `nd_from_object` /
  `nd_to_numpy` (buffer protocol and DLPack in, NumPy views out); no public class yet.
- Fortran: the `oti_real_ndarray` module and its C descriptor shim (`src/fortran/ndarray/`,
  generated by `tools/gen_fortran_ndarray.py`), tested on gfortran 16.2 and flang 23.1.
- A batched BLAS benchmark, `tools/bench/bench_blas_batch.c`, built only with `-DOTI_BUILD_BENCH=ON`.
- Advanced indexing of ndarrays: `nd_index_get` (gather into a new C-contiguous array) and
  `nd_index_set` (scatter; last write wins for duplicate indices, overlapping values are copied
  first), with NumPy's rules for integer arrays, boolean masks and the axis placement of mixed
  indices.
- `pyoti.real.dmat` supports the buffer protocol and DLPack (`np.asarray(D)`, `memoryview(D)`,
  `np.from_dlpack(D)`), through generic producers in `real/ndarray/base.pxi`.
- `oti_meta_t` (`include/oti/core/meta.h`, `src/c/core/meta.c`): reference-counted layout metadata
  shared by an OTI array and its views.
- Static modules: compile-time layout checks of `onummXnY_t` and the Gauss value types for all 17
  combinations; a generator of fixed-order block kernels
  (`src/python/pyoti/python/block_kernel_writer.py`) with an opt-in harness
  (`-DOTI_BUILD_STATIC_BLOCK=ON`).
- C tests: `test_real_ndarray_{core,views,iter,ufunc,reduce,blas,linalg,index}`, `test_exec`,
  `test_oti_meta`, `test_dense_7b_ready`; Python tests for `dmat`, advanced indexing, and the 2.0.0
  compatibility suite (`test_compat_2_0_*`, expected failures until Phase 7b).
- Per-call dense benchmarks `tools/bench/bench_7a.c` (with `-DOTI_BUILD_BENCH=ON`) and
  `tools/bench/bench_7a_py.py`.
- `nd_alloc_extra` (caller storage in the control block, living as long as the buffer),
  `ND_ALLOC_SCRATCH` (call-local arrays from a per-thread arena, never exported), `nd_buffer_extra`,
  `nd_buffer_extra_bytes`, `nd_scratch_release`.
- n-D dense arrays (up to 31 element dimensions), `layout=`, `reserve()` in `pyoti.dense` and
  `pyoti.semisparse` (`reserve(bases=, order=)`), `elm_help.allocate(..., bases=)` for semi-sparse.
- `reshape` for `matso` and `dmat` (within two dimensions), `dmat.T`, `pyoti.sparse.matmul`, `abs()` of
  `matso` and `dmat`.
- C tests `test_dense_7b`, `test_real_ndarray_alloc`, `test_core_slice`, `test_real_darr_abs`; Python
  tests for version-1 and version-2 files (`tests/python/data/v1/` fixtures written by the 1.x writers)
  and `test_compat_2_0_fix2.py`.

### Changed

- The build defines `OTI_PARALLEL_OPENMP` or `OTI_PARALLEL_SERIAL`, and refuses fast-math or
  vector-math-library compiler flags (results must not change between builds).
- With Accelerate the minimum macOS deployment target is 13.3 (`$NEWLAPACK`).
- `fem` C code no longer uses the legacy `enum oti_errors`, `printf` or `exit()`.
- `pyoti.real.dmat` sits on `ndarr_t`: slices are views of the parent (writes go through in both
  directions; its indexing shapes become NumPy's, see Breaking); `to_numpy()` arrays keep the
  memory alive; a shape mismatch in `D[i:j, k:l] = E` raises `ValueError` instead of terminating the
  process; a strided view as `out=` raises `ValueError`; `numpy.ndarray op dmat` raises `TypeError`.
- Dense arrays (`oarr_t`, `feoarr_t`, `arro_t`) sit on `ndarr_t` and `oti_meta_t`, with no change in
  results, saved files or the Python API; their parallel loops run on `oti_parallel_for` with
  thresholds from the cost model, and results no longer depend on the thread count. `DN_ERR_*` are
  aliases of `OTI_ERR_*`.
- `src/c/real_ndarray.c` and `src/c/core/exec.c` are compiled with `-ffp-contract=off` and
  `-fno-wrapv`.
- ndarray arrays with at most 4096 data bytes take one allocation (control block and 64-byte-aligned
  data); a dense array's `oti_meta_t` lives in its buffer.
- `A.set(rhs)` is `A[...] = rhs` in every algebra (NumPy broadcasting; sparse was strict).
- `out=` returns the `out` it was given (1.x returned `None`), also when `out` has extra leading axes
  of extent 1.
- `bool()` of an empty array is `False` (arrays have a length); `numpy.ndarray * matso` raises
  `TypeError` (was `ValueError`); `x[i].real` of a 1-D array is a float.
- Version-2 `'OTD'`, `'OTS'` and `'OTI'` files share one header rule (contracts 11.12). `'OTI'` files
  are read from Python by a validating Cython decoder (the C reader is no longer called): a corrupt
  file raises `ValueError` instead of terminating the process.
- `VERSION` is 2.0.0 on the development branch (the release is tagged after Phase 8).

### Removed

- `src/c/real/array/blas_level1.c`, which nothing used.
- The Fortran LAPACK wrappers `src/fortran/core/oti_lapack.f90` and the `otilapack` library: the
  five wrappers (`oti_dgetrf`, `oti_dgetrs`, `oti_dtrsm`, `oti_dtrmm`, `oti_dgemm`) keep their names
  and signatures, now in C.
- The unused OpenMP helpers `setup_global_omp_dist` / `setup_omp_parallel_elementwise`: no library
  code changes the process-wide OpenMP thread count.

### Fixed

- `pyoti.real.solve` returned the unsolved right-hand side for a dense `K` and more than one
  right-hand-side column.
- Empty extended slices (`A[:-6:2]` of a 5-row array) of the 2-D slicers returned one row
  (`slice_size()`, `get_slice_size()` of the real and complex arrays).
- A `pyoti.real.dmat` view that outlived its parent read freed memory.
- `pyoti.real.inv` / `det` / `solve` of a non-square `dmat` terminated the interpreter; they raise
  `LinAlgError`.
- `darr_abs` (`abs()` of real arrays in C) truncated to integers: `-1.5` became 1.
- `erf` of a `dmat` computed `cos`.
## [1.3.1] - 2026-11-02

Fixes the 1.3.0 conda deployment, which failed on every platform and published no package.

### Fixed

- Linux Release builds failed to compile `src/c/dense/io/io.c` and `src/c/semisparse/io/io.c`:
  under `-std=c99` glibc hides the POSIX `fseeko` / `ftello`, and GCC 14+ rejects the resulting
  implicit declarations (older GCC only warned, and then treated the `off_t` result of `ftello` as
  `int`, misreporting files over 2 GiB). `src/c/dense.c` and `src/c/semisparse.c` now define
  `_POSIX_C_SOURCE 200809L` before any system header (not on Apple).
- `soti_init()` left the real part of a `sotinum_t` uninitialized, so `soti_createEmpty()` returned
  a number with an indeterminate real coefficient. The sparse reference in the C `moving_average`
  tests (`c_dense_utils_test`, `c_semisparse_utils_test`) accumulated into such a number and failed
  at `-O3` on macOS. It is now initialized to `0.0`.
- The conda recipe's test phase could not import `examples.python.fem_twc`, used by
  `tests/python/test_fem_twc.py`: the example is now in `test.source_files`, and the test puts the
  repository root on `sys.path` itself instead of relying on `tests/python/run_tests.py`.

## [1.3.0] - 2026-11-02

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
- The dense OTI type rewritten (`PLAN-dense-update.md`): every number is dense over the global
  bases 1..nact and carries its own truncation order, with the semi-sparse order rules (result
  truncation order and nact are the operands' maxima; lower operands are zero-extended). It reaches
  the capabilities of `pyoti.semisparse`, and `pyoti.fem.set_global_algebra(pyoti.dense)` runs the
  FEM element tests and the TWC model.
  - C (`src/c/dense/`, `include/oti/dense/`): scalar `otinum_t` (`oti_*`), structure-of-arrays
    `oarr_t` (`oarr_*`, one buffer, column-major blocks), array-of-structures `arro_t` (`arro_*`),
    linear algebra (`oarr_lu_factor/lu_solve/solve_to/inv_to/det_to` through the `oti_d*` LAPACK
    wrappers, at every n), order plumbing and truncated products, save/read (magic
    `0x93 'O' 'T' 'D'`, `dnio_peek`), Gauss-point types `feoarr_t` / `feotinum_t` (`fearr_*`), and
    OTI sparse matrices `lilo_t` / `csro_t` with the block-solve right-hand sides. Operands with a
    smaller nact are read in place at their own offsets (the colex prefix property), so products
    of mixed-nact operands do no expansion. Every function that can allocate returns a status
    (`DN_OK` / `DN_ERR_*`, `CSRO_*`, `DNIO_*`); nothing calls `exit()`, and the global truncation
    order is never read.
  - Python: `pyoti.dense` mirrors the `pyoti.sparse` names and call signatures (`otinum`, `omat`,
    `arro`, `otife`, `omatfe`, `lil_matrix`, `csr_matrix`, the creators with `nip=`, module
    functions with `out=`, `solve` with the four sparse solvers, `save` / `read`, `elm_help`).
  - Tests: `tests/c/test_dense_{scalar,soa,linalg,aos,utils,io,gauss,csr}.c` against the
    `sotinum_t` / `arrso_t` oracle and semi-sparse, `tests/python/test_dense_*.py` against
    `pyoti.sparse`, the dense parameter of `tests/python/test_fem_elements.py`, and the dense twin in
    `tests/python/test_fem_twc.py`.
  - `examples/python/fem_twc.py --algebra dense`; `tools/bench_fem_twc.py` and
    `tools/bench_semisparse.py` cover the three algebras.
  - Performance (`reports/2026-09-30-dense-update/`): against sparse in its valid range, scalars
    about 5-6x faster, SoA arrays 12-100x, the TWC model 4.3-9.7x at 80x80; against semi-sparse a tie
    when operands share the labels 1..k, faster on products and sums over different label sets, and
    slower with more memory when values use only a few high labels.
  - Oversized requests fail with `MemoryError` / `DN_ERR_MEMORY` instead of an overcommitted
    allocation: a single coefficient buffer may not exceed `OTI_DENSE_MAX_MB` megabytes (default:
    the physical memory).

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

- **Breaking:** the old `pyoti.dense` API is replaced by the rewrite above. Products no longer grow
  in order up to a global cap (`2 x 2 -> 4` before, now the operands' maximum), `det` / `inv` no
  longer need `set_trunc_order`, and `omat` follows the `matso` API. `import pyoti` still re-exports
  `pyoti.dense`, now with the new API; `pyoti.set_trunc_order` / `pyoti.get_trunc_order` are no
  longer available at the top level (they stay in `pyoti.core`). Earlier dense benchmark baselines
  are not comparable.

### Removed

- The old dense implementation: `src/c/dense/` and `include/oti/dense/` (replaced in place),
  `dhelp_dense_mult` (`include/oti/core/dense.h`, `src/c/core/dense_helper.c`), the old Cython
  `pyoti.dense` (`spr_omat`, `oti_n2m2`, `otibase`), the dormant FEM `feoarr_t` / `feotinum_t`
  sources (never compiled) with `fem/feoarr.pxi`, and `tests/python/test_dense.py`.
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
- Dense (by the rewrite): `det` / `invert` segfaulted unless `set_trunc_order(arr.order)` was
  called first, `invert` returned zeros and `det` was wrong for n >= 4, `nbases > Nbasis(order)`
  called `exit()`, `otinum(3.0, 2, 0)` segfaulted, and the temporary pool was global and not
  thread-safe.

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
