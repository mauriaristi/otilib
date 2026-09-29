# AGENTS.md

Guidance for AI agents working in this repository.

## Environment & Prerequisites

- **Conda Environment:** `pyoti` (`python=3.13`) defined in `environment.yml`.
- **Solver Gotcha:** Always use the `rattler` solver (`conda env create -f environment.yml --solver rattler` or `conda install --solver rattler`) on macOS arm64; the classic solver hangs/times out.
- **Key Dependency Pins:**
  - `numpy>=2.1,<3`: OTILib's own C-API usage is NumPy-2-compatible (enforced at build time via `NPY_NO_DEPRECATED_API` in `setup.py.in`). The lower bound is `2.1` rather than `2.0` because numpy 2.0.x publishes no Python 3.13 build at all. The optional `solver='umfpack'`/`solver='cholesky'` sparse-solver paths (`scikits.umfpack`, `sksparse`) depend on those upstream packages publishing NumPy-2-compatible builds; the default `solver='SuperLU'` path is unaffected either way.
  - `vtk<9.4`: `pyvista` compatibility (prevents `vtkCapsuleSource` import error with VTK 9.5+).
  - `cython>=3.0`: Cython 3.x is the standard compiler for building extension modules.
  - `scikit-sparse<0.5`: 0.5.0 returns a tuple from `cholesky(A)`, while `sparse/linalg.pxi` expects the
    callable `Factor` of 0.4.x, so `solve(csr, b, solver='cholesky')` fails with `TypeError: 'tuple'
    object is not callable` on 0.5. Supporting the 0.5 API is a later item.
- **OpenMP (macOS):** Requires Homebrew `libomp` at `/opt/homebrew/opt/libomp` and `gfortran` (Homebrew GCC).
- **LAPACK / BLAS (required):** The C core's dense linear algebra (`inv`, `det`, `solve`,
  `lu_factor`, `lu_solve`) links a LAPACK found by CMake's `find_package(LAPACK)` with 32-bit
  integers (LP64). Sources, by platform:
  - conda: `libblas`, `liblapack` (in `environment.yml`; conda-forge's stubs, switchable between
    OpenBLAS, MKL, Accelerate and netlib with `blas=*=<impl>`).
  - Linux system packages: `liblapack-dev` (or `libopenblas-dev`).
  - macOS: Accelerate, part of the OS (`-DOTI_BLA_VENDOR=Apple`).
- **CMake >= 3.22** (`BLA_SIZEOF_INTEGER`).
- **Platforms:** Linux and macOS. Native Windows is not supported: the Cython link line in
  `setup.py.in` assumes Unix archives and `-Wl,` linker flags. Use WSL.

### Dependency Availability Check

Before bumping the `python=` / `numpy=` pins, confirm conda-forge publishes builds for every dependency on each target platform. Repeat for `osx-arm64`, `osx-64`, and `linux-64` via `CONDA_SUBDIR`; when cross-solving `linux-64` from macOS, also set `CONDA_OVERRIDE_GLIBC` (otherwise the missing `__glibc` virtual package makes the solve fail spuriously):

```bash
CONDA_SUBDIR=linux-64 CONDA_OVERRIDE_GLIBC=2.28 \
conda create -n __pintest --solver rattler --dry-run -c conda-forge -c anaconda \
  "python=3.13.*" "numpy>=2.1,<3" scipy "cython>=3.0" pandas make cmake pip pytest ipykernel \
  "conda-forge::vtk<9.4" conda-forge::gmsh conda-forge::python-gmsh conda-forge::pyvista \
  "conda-forge::scikit-sparse<0.5" conda-forge::scikit-umfpack -y
```

## Versioning

The root `VERSION` file (`MAJOR.MINOR.PATCH`) is the **single source of truth** for every language
binding and for packaging. Never hardcode a version anywhere else.

CMake reads `VERSION` at configure time and generates, into the **build tree only**:

| Generated file | Template | Consumers |
|---|---|---|
| `build/include/oti/version.h` | `include/oti/version.h.in` | C, C++, Cython (`c_otilib/version.pxi`) |
| `build/generated/oti_version.f90` | `src/fortran/core/oti_version.f90.in` | Fortran (`USE oti_version`) |
| `build/pyoti/_version.py` | `src/python/pyoti/python/_version.py.in` | `pyoti.__version__` |

`conda/meta.yaml` reads `VERSION` directly through `load_file_regex`, and `setup.py.in` receives it
as `@OTI_VERSION@`.

Rules:

- To bump: `python tools/bump_version.py <major|minor|patch|X.Y.Z>`, then re-run `cmake`. Add the
  changes under the changelog section the script opens.
- Never edit a generated file; edit its `.in` template.
- The generated Fortran `oti_version` module declares **PARAMETERs only**. It is compiled into both
  `otistatic` and `otifsparse` (each emits its own `.mod` into its own module directory); adding a
  procedure there would produce duplicate symbols when both libraries are linked into one binary.
- `oti_version()` (C) and `pyoti.core.c_version()` report the version the *library* was built with,
  while `OTI_VERSION_STRING` and `pyoti.__version__` report the version of the sources the caller
  compiled against. The consistency tests (`test_c_version`, `test_f_version`,
  `tests/python/test_version.py`) exist to catch drift between them.

## Build Workflow

Always activate the `pyoti` environment before running `cmake` or `make` so Python/Cython/NumPy headers are found:

```bash
conda activate pyoti
mkdir -p build && cd build
cmake ..
make
conda develop .
```

### Critical Steps & Gotchas
1. **Direction-helper tables are lazy, in-memory:** `ndirs` and `fulldir` are computed at
   `dhelp_load` (import time); each order's `multtabl` is built the first time a multiplication
   needs it and cached for the rest of the process. The first build of an order's table is
   thread-safe (an OpenMP critical section), since sparse array multiplications may call it from
   inside `omp parallel`.
2. **`conda develop .` (from `build/`):** Links `build/pyoti` to the conda environment site-packages so `import pyoti` works repository-wide.
3. **Cython build (`oticython` target):** Automatically invoked during `make`. Generated shared objects (`*.so`) are placed into `build/pyoti/`.
4. **Choosing the LAPACK:** `cmake -DOTI_BLA_VENDOR=<vendor> ..` passes `<vendor>` to FindLAPACK
   as `BLA_VENDOR` (`Apple`, `OpenBLAS`, `Generic`, `Intel10_64lp`, ...). Empty (the default)
   uses CMake's search order, which picks the conda OpenBLAS inside the `pyoti` env. The configure
   log prints `LAPACK libraries:` and the Cython link arguments; check them after switching.
   - `Generic` on macOS finds the SDK's `libblas.tbd` (Accelerate) unless
     `-DCMAKE_PREFIX_PATH="$CONDA_PREFIX"` is also given; the conda recipe passes `$PREFIX`.
   - Check the linked library with `otool -L build/pyoti/sparse*.so` (macOS) or `ldd` (Linux).
   - Changing the vendor in an existing `build/` needs a fresh configure (FindLAPACK caches its
     result).
5. **Fortran compiler on macOS:** a fresh configure with CMake 4 picks Homebrew `flang` over
   `gfortran` when both are installed, and FindBLAS's Accelerate check fails under `flang`. Pass
   the compiler explicitly on a new build directory:
   `cmake -DCMAKE_Fortran_COMPILER=gfortran ..`. An existing `build/` keeps the compiler in its
   cache.

## Architecture & Layout

- `src/c/`: C core implementations (scalar, array, dense, sparse, semisparse, static, fem).
- `src/fortran/`: Fortran implementations and wrappers (`core/`, `static/`, `sparse/`, `experimental/`).
- `src/python/pyoti/cython/`: Cython bindings (`core.pyx`, `dense.pyx`, `sparse.pyx`, `real.pyx`, `fem.pyx`, `semisparse.pyx`, `static/*.pyx`).
- `src/python/pyoti/python/`: Pure Python modules and code generators (`whereotilib.py`, `fmod_writer.py`, `cmod_writer.py`).
- `include/oti/`: C/C++ header files.
- `build/pyoti/`: Compiled Python package containing `.so` extensions and copied `.py` files.
- **Semi-sparse (`PLAN-semisparse.md`)**: a dense-over-active-bases type, alongside the sparse
  types (`sotinum_t` / `arrso_t`), with conversions both ways.
  - `src/c/semisparse/scalar/`, `src/c/semisparse/soa/`, `src/c/semisparse/array/`: scalar
    (`ssotinum_t`), structure-of-arrays (`oarrss_t`) and array-of-structures (`arrss_t`)
    implementations, unity-included from `src/c/semisparse.c`.
  - `include/oti/semisparse/{scalar,soa,array}/`: their public C headers, aggregated by
    `include/oti/semisparse.h`.
  - `include/oti/core/semisparse.h`: index helpers shared by all three (`sshelp_*`: local/global
    direction numbering, unions, the table-vs-rank product index, the local product-table cache,
    per-thread workspaces), implemented in `src/c/core/semisparse_helper.c`.
  - `src/python/pyoti/cython/semisparse.pyx`: the `pyoti.semisparse` module (scalar, AoS and SoA
    classes, conversions to/from `pyoti.sparse`, direction blocks as NumPy views). Like
    `sparse.pyx`, it is only headers and `include` lines; the code is in
    `src/python/pyoti/cython/semisparse/*.pxi` (`scalar/`, `soa/`, `aos/` hold the class bodies).
  - **Feature parity with `pyoti.sparse` (`PLAN-semisparse-sparse-leveling.md`)**, each area with
    its C source, header, Cython declarations (`include/pyoti/c_otilib/semisparse_<area>.pxi`) and
    module code:
    - order/derivative plumbing, `trunc_dot`/`trunc_sub`/`dot_product`, `rom_eval*`, `interp1d`,
      `moving_average`, `inv_block`: `src/c/semisparse/{scalar,soa}/utils.c`, `semisparse/order.pxi`;
    - save/read: `src/c/semisparse/io/`, `include/oti/semisparse/io/io.h` (the file format is
      documented there), `semisparse/io.pxi`;
    - Gauss-point types `ssotife`/`oarrssfe` (C `feoarrss_t`): `src/c/semisparse/gauss/`,
      `include/oti/semisparse/gauss/gauss.h`, `semisparse/gauss/base.pxi`;
    - FEM element helper `elm_help`: `semisparse/fem/base.pxi`;
    - OTI sparse matrices: `src/c/semisparse/csr/`, `include/oti/semisparse/csr/csr.h` (the
      `lilss_t` hash-table triplet builder behind `lil_matrix`, the `csrss_t` CSR view with values as
      one nnz x 1 `oarrss_t` and int64 `indices`/`indptr`, `csrss_matmul_to`, the block-solve
      right-hand sides `csrss_solve_init`/`csrss_solve_rhs`); Python `csr_matrix`, `lil_matrix` and
      `_csr_solve` in `semisparse/csr/base.pxi`.
  - `examples/python/fem_twc.py`: the thick-walled-cylinder FEM model, `run(algebra, ndivs, order,
    perturb_geometry=False)`; it never branches on the algebra and is the drop-in acceptance test
    of `pyoti.semisparse` against `pyoti.sparse`.

## Semi-sparse gotchas
- **Block offsets in kernels.** `oarrss_block_index(k, p, i)` and `sshelp_order_offset(k, p)` compute
  a binomial coefficient on every call. Compute the order's first block once per order and add the
  local index (`bp + i`), never call them per direction or per direction pair: per-pair calls were
  about 30% of the TWC element product before this was fixed.

- **Local vs. global direction numbering.** Scalar/array functions that take a direction (e.g.
  `ssoti_get_item`, `ssoti_truncate_im`) take it as a **global** `(idx, order)` pair, same numbering
  as `sotinum_t`. Internally, a number's own directions are numbered **locally** over its sorted
  active bases (`include/oti/core/semisparse.h`): local base `u` is global base `p_bases[u]`, and
  order-p directions using only local bases `0..k-1` are exactly local indices `0 .. N_p(k)-1` (the
  colex prefix property). Converting between the two goes through `sshelp_local_to_global` /
  `sshelp_global_to_local` / `sshelp_global_unrank`, never through `dhelp_get_imdir` (its tables
  don't cover the full label range semi-sparse allows, up to 65535).
- **Python directions parse like `pyoti.sparse`**: in `pyoti.semisparse` a list or tuple is always
  a list of bases (`(4, 2)` is `e([2, 4])`). A raw global `(index, order)` pair must be wrapped in
  `pyoti.semisparse.rawdir(index, order)`, which every direction argument accepts.
- **Result truncation order is the MAX of the operands'**, as `sotinum_t` does; an operand with a
  lower truncation order is expanded (zero-extended) to match before the kernel runs, rather than
  being used in place.
- **Bases are never dropped automatically.** Cancelling a coefficient (e.g. `x - x`) leaves its
  bases in the active set with zero coefficients; call `ssoti_compact` / `arrss_compact_to` (or the
  Python equivalent) to shrink the set and, for arrays, `arrss_to_oarrss` / `arrss_from_oarrss` when
  moving through the SoA layout, which always uses the union of the input sets.
- **Storage order differs between array layouts.** SoA (`oarrss_t`) blocks are column-major
  (`element (r, c)` at `r + c*nrows`), so a NumPy view of one is Fortran-ordered; AoS (`arrss_t`),
  like `arrso_t`, is row-major (`element (i, j)` at `p_data[j + i*ncols]`).
- **The local product-table cache** (`sshelp_get_pair`, `src/c/core/semisparse_helper.c`) lazily
  builds and caches, per process, a table for any `(k, p, q)` beyond the global multiplication
  table's reach (`k > Nbasis(p+q)`), instead of the plain per-call rank fallback. Budgeted at 256
  MiB total (`SSHELP_CACHE_DEFAULT_MB`), overridable with the `OTI_SS_TABLE_CACHE_MB` environment
  variable (MiB, read once, on the first table build); past the budget it silently keeps using the
  rank fallback (always correct, just slower). Freed by `dhelp_free()`.
- **`det`/`inv` need a nonsingular real part**: unlike the sparse types' closed forms for n <= 3
  (`_OTI_LINALG_CLOSED_FORM_MAX`), the semi-sparse SoA linear algebra (`src/c/semisparse/soa/linalg.c`)
  always goes through the real LU factorization first, with no closed-form fallback at any size, so
  a singular real part fails at every n, not just above the closed-form cutoff.
- **OpenMP vs. threaded BLAS: don't nest them.** Elementwise operations (scalar kernels run over
  array elements) parallelize with OpenMP; SoA `matmul` and `solve`/`inv`/`det` (one `dgemm` /
  `dgetrf` per order) rely on BLAS's own threading instead. Running both nested oversubscribes the
  machine. Set `OMP_NUM_THREADS` for the OpenMP side and `OPENBLAS_NUM_THREADS` /
  `VECLIB_MAXIMUM_THREADS` (OpenBLAS / Accelerate, matching the linked LAPACK vendor -- see
  "Choosing the LAPACK" above) for the BLAS side; don't set both to the machine's full core count
  at once.
- **No coefficient-sized buffer outlives a SoA call.** SoA elementwise operations, functions,
  `matmul`, `transpose`, `add_bases` and `compact` write straight into `res`; when `res` aliases an
  operand the result is built in a call-local buffer and copied. Only the small index buffers (union
  of bases, position maps) stay in the per-thread workspace, so after a call the process holds only
  the lazy tables. New SoA code should follow the same rule (`malloc`/`free` inside the call).
- **API parity with `pyoti.sparse`.** `pyoti.semisparse` mirrors the sparse names and call
  signatures (creators, `array`, `zeros(shape, nbases, order, nip, bases=)`, `sum`/`sub`/`mul`/
  `div`/`neg`/`abs`/`norm`/`transpose`/`dot`/`inv`/`det` with `out=`, the Phase 2 functions,
  `save`/`read`). `nbases=` is accepted everywhere and has no effect (a capacity hint in sparse).
  In-place operators rebind (`a += b` is `a = a + b`), as in sparse.
- **Assignment raises the truncation order.** `A[i, j] = x` and slice assignment on SoA/AoS arrays
  (and Gauss types) raise the array's truncation order to the value's, zero-extending the entries
  already there, and grow the active set; `f = zeros((n, 1)); f[i, 0] = f[i, 0] + x` keeps every
  derivative of `x`. Matrix indexing follows `matso`: `A[i]` is a row block, `A[i, j]` an
  `ssotinum` copy; negative indices count from the end (sparse does not support them).
- **`sum`, `abs` and `pow` are module functions** of `pyoti.semisparse` and shadow the builtins inside
  every `.pxi` of `semisparse.pyx`; use `_builtins.sum` / `_builtins.abs` there (`import builtins as
  _builtins` is in `semisparse/utils.pxi`). Cython also rejects generator expressions other than
  inlined `all`/`any`/`sum` inside `cdef` functions; use list comprehensions.
- **Gauss-point layout.** A `feoarrss_t` (Python `ssotife` scalar, `oarrssfe` matrix) embeds one
  `oarrss_t` of shape `nip x (nrows * ncols)`: entry (i, j) at point ip is element
  (ip, i + j*nrows), points fastest, one active set for all points. Elementwise operations and
  functions are the SoA kernels on it; a Gauss x plain matrix product, `dot_product` with a plain
  array and `gauss_integrate` are single SoA matrix products on reinterpreted shapes. Gauss scalars
  broadcast over Gauss arrays point by point; plain OTI values are the same at every point. `.real`,
  `get_im`, `get_deriv` return NumPy of shape `(nip,)` / `(nip, nrows, ncols)` (sparse returns real
  Gauss types). Gauss `det`/`inv` use closed forms for n <= 3 (a singular real part gives inf/nan,
  no status) and LU per point above (status on a singular real part).
- **`dot_product` pairs entries row-major**, as sparse does (the kernels pair column-major, which is
  the same for equal shapes and vectors; otherwise the transposes are paired).
- **FEM with semi-sparse.** `pyoti.fem.set_global_algebra(pyoti.semisparse)` builds mesh
  coordinates with `pyoti.semisparse.array` (SoA columns) and elements hold a semi-sparse
  `elm_help`. `elbase.allocate` still evaluates shape functions with sparse numbers and fills the
  helper only through `set_ijk(real, 0, i, ip)`. `set_global_algebra` reports the underlying error
  when an algebra fails its probe.
- **Save/read formats differ.** `pyoti.semisparse.save`/`read` files start `93 'O' 'T' 'S'` (a
  versioned, validated format, host byte order); `pyoti.sparse` files start `93 'O' 'T' 'I'`. The two
  are not interchangeable.
- **OTI sparse matrices.** `lil_matrix.tocsr()` empties the builder, as in `pyoti.sparse`
  (`preserve_in=True` keeps it). Setting an element overwrites it; accumulate with
  `K[i, j] = K[i, j] + v` or the faster `K.add(i, j, v)`, and scatter an element matrix with
  `K.add_block(rows, cols, Ke)` (both algebras; one call instead of 64 Python calls for a quad4).
  `csr_matrix.real` is a SciPy CSR matrix sharing memory with the OTI matrix's real part (writing
  its `data` changes the OTI matrix); `indices`/`indptr` are read-only int64 arrays shared by
  copies. `solve(csr, b, solver=...)`
  factors the real part once (SciPy SuperLU/spilu, scikit-sparse cholmod, scikit-umfpack) and solves
  all directions of one order as a single multi-column right-hand side built in C; the solution is
  dense over the union of K's and b's bases. `csr @ x` never expands or copies either operand
  (directions are remapped into the union's product tables).
- **Phase 2 global layouts** (`get_all_ims`, `get_order_im_array`) are indexed by global direction
  index and skip directions with bases beyond the layout instead of writing out of range.
  `soa/utils.c` and `gauss/gauss.c` rely on the unity-build order (they reuse `oarrss_pairsrc_*`
  and other statics of `soa/kernels.c` / `soa/base.c`).

## Verification & Testing

### 1. Verify Environment Installation
Verify that third-party dependencies are properly installed and compatible:

```bash
python -c "
import numpy, scipy, cython, pandas, pyvista, gmsh, vtk, pytest
print('Core environment verification passed!')
try:
    import scikits.umfpack, sksparse
    print('Optional umfpack/cholesky solver deps available.')
except ImportError as e:
    print('Optional umfpack/cholesky solver deps unavailable (', e, '); default solver=\'SuperLU\' is unaffected.')
"
```

Note: as of the Python 3.13 migration, `scikits.umfpack`/`sksparse` conda-forge builds were re-verified as available for `python=3.13` across linux-64, osx-64, and osx-arm64 (unlike the earlier NumPy 2.0/Python 3.9 migration, where the osx-arm64 build was initially missing). If this regresses in the future, re-run the "Dependency Availability Check" above before assuming the optional `solver='umfpack'`/`solver='cholesky'` paths are broken — the default `solver='SuperLU'` path never depends on these.

### 2. Verify PyOTI Package Installation & Test Suite
Run the Python test suite from the repository root to verify imports, the direction-helper tables, and mathematical derivative accuracy:

Reference derivatives in the scalar-function tests are computed with `sympy`, a test-only dependency
(listed in `environment.yml` and the conda recipe's `test.requires`).

```bash
# Run full Python test suite
pytest tests/python
# or via test runner:
python tests/run_tests.py

# Run specific verification tests
pytest tests/python/test_imports.py        # Installation, submodules & direction-helper tables
pytest tests/python/test_sparse_scalar.py  # Scalar creation & basic arithmetic
pytest tests/python/test_sparse_scalar_functions.py  # All scalar functions/operators, up to 6th order
pytest tests/python/test_sparse_scalar_utils.py      # rom_eval, truncate, truncate_order
pytest tests/python/test_sparse_array.py   # Matrix/array operations & linalg
pytest tests/python/test_sparse_array_ops.py  # Dense matso ops & linalg vs sympy, up to 4th order
pytest tests/python/test_static.py         # Static dense modules (onummXnY)
pytest tests/python/test_dense.py          # Dynamic dense OTI numbers
pytest tests/python/test_semisparse_scalar.py  # pyoti.semisparse scalar vs the sparse oracle
pytest tests/python/test_semisparse_soa.py     # SoA arrays (oarrss) vs the sparse oracle
pytest tests/python/test_semisparse_aos.py     # AoS arrays (arrss) vs the sparse oracle
pytest tests/python/test_semisparse_api.py     # API parity (creators, methods, indexing, out=) vs sparse
pytest tests/python/test_semisparse_order.py   # get_order_im*, extract_*, trunc_dot/sub, dot_product,
                                               #   rom_eval*, interp1d, moving_average, inv_block
pytest tests/python/test_semisparse_io.py      # save/read round trips, sparse cross-check, bad files
pytest tests/python/test_semisparse_gauss.py   # Gauss-point types (ssotife, oarrssfe) vs sotife/matsofe
pytest tests/python/test_semisparse_csr.py     # lil/csr vs sparse, matmul, solve (all four solvers)
pytest tests/python/test_sparse_io.py          # matso save/read, file names, bad files
pytest tests/python/test_sparse_gauss.py       # sparse Gauss types and elm_help (oracle checks)
pytest tests/python/test_sparse_csr.py         # sparse lil/csr and the four solvers (oracle checks)
pytest tests/python/test_fem_elements.py       # every pyoti.fem element, both algebras
pytest tests/python/test_fem_twc.py            # TWC model: Lame check, refinement, semi vs sparse
```

### 3. Verify Native Multi-Language Tests (CTest)
Run native multi-language tests (C, Fortran, C++) with CTest or individual binaries from `build/`:

```bash
cd build
# Run all native tests via CTest
ctest --output-on-failure

# Or run individual test executables:
./tests/c/test_c_scalar
./tests/c/test_c_array
./tests/c/test_c_lapack          # LAPACK wrappers
./tests/c/test_c_sparse_linalg   # det / inv / solve / LU of OTI arrays
./tests/c/test_c_dhelp           # direction-helper tables: lazy multtabl build vs dhelp_precompute_multiply
./tests/c/test_c_semisparse_core   # index helpers: union/positions, remap vs rank, local<->global
                                    #   round trips, table sub-block vs rank, the product-table cache
./tests/c/test_c_semisparse_scalar # ssotinum_t vs the sotinum_t oracle
./tests/c/test_c_semisparse_soa    # oarrss_t (SoA) vs the arrso_t oracle
./tests/c/test_c_semisparse_aos    # arrss_t (AoS) vs the arrso_t oracle
./tests/c/test_c_semisparse_review # edge cases found in review (e.g. 0x0 SoA matrices)
./tests/c/test_c_semisparse_utils  # Phase 2 kernels vs the sotinum_t/arrso_t oracle
./tests/c/test_c_semisparse_io     # save/read format
./tests/c/test_c_semisparse_gauss  # Gauss-point types (feoarrss_t) vs per-point oarrss_t / arrso_t
./tests/c/test_c_semisparse_csr    # triplet builder, CSR spmm and solve RHS vs dense SoA
./tests/fortran/test_f_static_scalar
./tests/fortran/test_f_sparse_scalar
./tests/cpp/test_cpp_vector
./tests/cpp/test_cpp_headers
```

`tests/c/CMakeLists.txt` registers `test_c_semisparse_<name>` / `c_semisparse_<name>_test`
automatically, for every `tests/c/test_semisparse_<name>.c` that exists (a `foreach` over
`core scalar soa aos review utils io gauss csr`), so adding one of those files needs no
`CMakeLists.txt` edit; a new `<name>` needs one word added to that list.

Benchmark the direction-helper tables (import time, RSS, `mult_dir`/multiplication timings at
several orders) with:

```bash
python tools/bench_dhelp.py
```

Benchmark the semi-sparse types (scalar, AoS and SoA arrays: elementwise ops, `matmul`,
`solve`/`inv`/`det`; k in `{2, 5, 10, 20, 50, 100}` x order in `{1, 2, 3, 4, 6, 8, 10}`) against the
`pyoti.sparse` and dense `pyoti.dense` baselines, each case in its own fresh process, with:

```bash
python tools/bench_semisparse.py --quick                                  # small validation grid
python tools/bench_semisparse.py --json build/bench_semisparse_baseline.json  # full grid, saved
python tools/bench_semisparse.py --quick --compare build/bench_semisparse_baseline.json  # speedup
```

The C-level benchmarks (`tools/bench/`, no Python overhead; identical inputs on both sides and a
result check per case) are built only on request, with `-DOTI_BUILD_BENCH=ON`:

```bash
cmake -DOTI_BUILD_BENCH=ON .. && make bench_semisparse_scalar bench_semisparse_arrays
./tools/bench/bench_semisparse_scalar [--quick] > scalar.csv   # ssotinum_t vs sotinum_t
./tools/bench/bench_semisparse_arrays [--quick] > arrays.csv   # arrss_t / oarrss_t vs arrso_t
```

### 4. Verify Native C & Fortran Examples
Run native example executables from the `build/` directory:

```bash
cd build
./examples/basic_scalar_c
./examples/basic_array_c
./examples/basic_scalar_f
./examples/ex1_oti_core
./examples/ex2_sparse_n1
./examples/ex3_static_m1n2
```

### 5. Verify Python Examples
Run example scripts from the repository root:

```bash
python examples/python/quick_example.py
python examples/python/basic_scalar.py
python examples/python/basic_array.py
python examples/python/basic_highorder.py
python examples/python/basic_linalg.py
```





### 6. Verify the Conda Package Build

The recipe verifies its own compilation, so a full package build is the closest local equivalent of
what CI does:

```bash
CONDA_SOLVER=libmamba conda build conda --override-channels -c conda-forge --output-folder dist
```

Use `--override-channels`: a `.condarc` that lists only the `defaults` channels (with the classic
solver) makes the plain `-c conda-forge` form fail with an opaque "Unsatisfiable dependencies for
platform ...: {'__unix', '__osx', ...}" message. CI is conda-forge only, so this mirrors it.
Prefer running from a clean export (`git archive HEAD | tar -x -C <dir>`) so a local `build/` tree
is not copied into the recipe's work directory.

- **Build phase** runs `ctest --output-on-failure` after `make`, covering the C, Fortran and
  C++ suites in the build environment. The script starts with `set -ex`, so any failure aborts the
  build instead of producing a package.
- **Test phase** runs `pytest tests/python -v` against the *installed* package, plus the version
  consistency checks. `tests/python` and `VERSION` reach that phase through the recipe's
  `source_files:`; the build tree no longer exists there.

## Generating the Documentation

Step-by-step instructions live in `doc/README.md`; this section adds the gotchas found in
practice that aren't spelled out there.

- **Folder layout:** `doc/Makefile` hardcodes `BUILDDIR = ../../otilib-gh-pages/` (relative to
  `doc/`), i.e. a sibling of this repo's own checkout, not a subfolder inside it. Before building,
  clone the `gh-pages` branch there:
  ```bash
  cd .. && git clone -b gh-pages https://github.com/mauriaristi/otilib otilib-gh-pages
  ```
- **Compiled library required first:** `doc/source/pyoti.rst` uses autodoc, which imports the
  real `pyoti` package. `build/` must already be compiled and linked (`conda develop .` from
  `build/`, see Build Workflow above) before running `make html`, or the module page fails to
  generate.
- **`pandoc` is not in `doc/requirements.txt`:** nbsphinx needs it too. A `pandoc` on `PATH`
  outside the `pyoti` env (e.g. in `base`) is not picked up by `conda run -n pyoti`; install it
  into the env explicitly:
  ```bash
  conda install -n pyoti -c conda-forge pandoc --solver rattler
  ```
- **Tutorial notebooks are not tracked under `doc/source/notebooks/`:** copy them in before
  building:
  ```bash
  cp examples/notebooks/*.ipynb doc/source/notebooks/
  ```
- **`doxygen` is not in `environment.yml` or `doc/requirements.txt`:** it's a system tool invoked
  as a subprocess by the `breathe`/`exhale` Sphinx extensions, not a Python package. Install it
  into the `pyoti` env explicitly:
  ```bash
  conda install -n pyoti -c conda-forge doxygen --solver rattler
  ```
- **C API pages are generated automatically during `make html`, not as a separate step:**
  `doc/source/Doxyfile` (`exhaleUseDoxyfile = True`) is invoked by Exhale directly from the Sphinx
  build; it walks `include/oti/` (excluding `include/oti/static/` — see the note in
  `doc/source/capi.rst`) and Breathe/Exhale turn the resulting Doxygen XML into a full page tree
  with zero hand-maintained per-file RST. Output lands in `doc/source/doxyoutput/` (raw Doxygen
  XML) and `doc/source/capi_generated/` (Exhale's generated RST), both gitignored and regenerated
  fresh on every build. Exhale does not purge `capi_generated/` before regenerating, so a renamed
  or removed header can leave a stale page behind; if the C API section looks out of date after
  such a change, `rm -rf doc/source/doxyoutput doc/source/capi_generated` before rebuilding.
- **Build:**
  ```bash
  cd doc && conda run -n pyoti make html
  ```
  Output lands in `../../otilib-gh-pages/html/` (the sibling clone), not a local `_build/`.
- **Publishing the built site (`doc/README.md` step 4):** move `html/*` into the
  `otilib-gh-pages` clone's root, replacing the old rendered pages, keeping only `.git`,
  `Makefile` and `README.md` from the previous state — then restore `.nojekyll` (an empty file
  GitHub Pages needs so `_static/`, `_sources/` and `_modules/` aren't swallowed by Jekyll; it
  does not survive a naive "keep only html/Makefile/README.md" cleanup because it lived at the
  clone's root, not inside `html/`):
  ```bash
  cd ../../otilib-gh-pages
  find . -maxdepth 1 ! -name . ! -name html ! -name Makefile ! -name README.md ! -name .git -exec rm -rf {} +
  cp -a html/. . && rm -rf html
  touch .nojekyll
  ```
  Do this as a single `cp -a` / `rm -rf`, not an incremental per-file `mv` loop: if any item at
  the destination already exists (e.g. a stale same-named directory left over from a previous
  build), `mv` silently fails on just that item and leaves old and new content mixed with no
  obvious error.
- Review the generated site locally (open `otilib-gh-pages/index.html` in a browser) before
  committing and pushing the `gh-pages` branch.






## Python and cython coding Standards & Style Guide

Whenever writing, generating, or modifying Python code, strictly adhere to the following formatting and 
documentation rules:

### 1. Indentation & Line Limits
- **Indentation:** Exactly 4 spaces per indentation level. Never use tabs.
- **Line Length:** Maximum 106 characters per line. Every line must strictly fit within 106 characters. If an expression, call, comment, or docstring exceeds 106 characters, split it cleanly across multiple lines.


### 2. Explicit Block Closing Comments
- Always include a newline before starting a major coding block (`for`, `while`, `if`, `try`, `with`), and a new line after the major block starts. 
- Close every major block (`def`, `class`, `for`, `while`, `if`, `try`, `with`) with an explicit comment matching the exact indentation level of the opening statement.
- The comment format is `# end <keyword>`:
  - Functions / Methods: `# end function`
  - Classes: `# end class`
  - Loops: `# end for`, `# end while`
  - Conditionals: `# end if`
  - Context & Exceptions: `# end with`, `# end try`
- Add a new line before and after the `# end <keyword>` comment.

### 3. Function/method/class implementation Delimiters

Every function, method or class implementation in a source file must be visually framed using single-line horizontal dividers starting at the declaration indentation level and ending **exactly at the 106 character marks**:

- **Top Divider (Opening):** Use an asterisk line preceded by `# ` (Fill with characters until you reach the 106 character mark).
  - The top divider must be placed in the line before the declaration except there is any decorator of a function.
- **Bottom Divider (Closing):** Use a hyphen line preceded by `# ` (Fill with characters until you reach the 106 character mark).
  - The bottom divider must be placed in the line after the `# end <keyword>` comment. Add a new line after this delimeter.


### 4. NumPy-Style Docstring Format
Every module, class, function, and method must include a NumPy-style docstring:
- **docstring structure:** Always format all docstrings (including single-line docstrings) with the opening and closing triple quotes on their own separate lines. Never place triple quotes on the same line as the docstring text.
- **One-line summary:** First line directly summarizes the action or behavior.
- **Extended summary (optional):** Additional context or formula details after a blank line.
- **Parameters section:** Header `Parameters` underlined with dashes (`----------`).
  - Format: `<param_name> : <type>` followed by indented explanation.
  - For class methods, **omit `self`** from the `Parameters` list.
- **Returns section:** Header `Returns` underlined with dashes (`-------`).
  - Format: `<return_type>` or `<name> : <type>` followed by description. Omit section if the function returns `None`.
- **Examples section:** Header `Examples` underlined with dashes (`--------`), containing doctests or usage code.




## Code Style & Architecture Guidelines for C/C++

This repository enforces a specific code organization, documentation, and formatting style. When generating, editing, or refactoring C or C++ code in this project, you must adhere strictly to the rules below.

### 1. Line Width & Formatting Boundary

- **Maximum Line Length:** Strictly **106 columns**.
- No line of code, comment, or divider may exceed 106 characters.
- Pointers adhere to C style with the asterisk bound to the identifier (`type *var` or `type* var` consistently matching the enclosing file).
- Constness must be explicitly specified for read-only pointer arguments (`const sotinum_t *num`).

### 2. Function/method/class Implementation Delimiters (`.c` / `.cpp`)

Every function, method or class implementation in a source file must be visually framed using single-line horizontal dividers of **exactly 106 characters**:

- **Top Divider (Opening):** Use an asterisk line preceded by `// ` (total length: 106 characters).
- **Bottom Divider (Closing):** Use a hyphen line preceded by `// ` (total length: 106 characters).
- Follow with **two blank lines** before the next function.

#### Reference Template:
```c
// ******************************************************************************************************
sotinum_t soti_sum_oo(const sotinum_t *num1, const sotinum_t *num2, dhelpl_t dhl) {
    sotinum_t res, tmp;

    tmp = soti_base_sum(num1, num2, dhl);
    res = soti_copy(&tmp, dhl);

    return res;
}
// ------------------------------------------------------------------------------------------------------
```
(Note: //  followed by 103 characters of * or - equals exactly 106 characters).

### 3. Header Documentation & Function Declarations (.h / .hpp)
All public functions must be documented in the header file using standard Doxygen syntax while respecting the project's visual divider conventions.

#### Rules for Headers:
 No Shared Doc Blocks: Never write a single Doxygen comment block intending to describe multiple subsequent function declarations. Each distinct function must have its own Doxygen block.

- **Variant Grouping:** For overloaded variants (e.g., OTI-OTI, Real-OTI, In-place _to variants), cluster them using Doxygen @name member groups (`/** @name ... @{ */ and /** @} */`).
- **Closing Divider:** Place a 106-character hyphen divider (`// -----`...) after a function or logical group of related declarations.
- **Parameter Directionality:** Every pointer parameter must explicitly state directionality: `@param[in]`, `@param[out]`, or `@param[in,out]`.
- **Memory Ownership Contracts:** If a function allocates memory on the heap (e.g., via copy, alloc, init), the `@return` tag must explicitly state allocation behavior and the corresponding deallocator function (e.g., `soti_free()`).

#### Reference Template:
```c
/**
 * @name Sparse OTI Addition Variants
 * Functions for summing OTI numbers with other OTI numbers or scalar real coefficients.
 * @{
 */

/**
 * @brief Adds two sparse OTI numbers (allocating variant).
 *
 * Computes the sum of @p num1 and @p num2. Allocates a new internal coefficient
 * buffer that must be released by the caller.
 *
 * @param[in] num1 Pointer to the first OTI operand. Must not be NULL.
 * @param[in] num2 Pointer to the second OTI operand. Must not be NULL.
 * @param[in] dhl  Direction helper list object defining dimensions and truncation.
 *
 * @return Newly allocated sotinum_t structure. Caller owns memory and must free
 *         via soti_free().
 *
 * @see soti_sum_oo_to() for the non-allocating variant.
 */
sotinum_t soti_sum_oo(const sotinum_t *num1, const sotinum_t *num2, dhelpl_t dhl);

/**
 * @brief Adds two sparse OTI numbers in-place into an existing destination buffer.
 *
 * Performs addition without heap allocations by writing directly into @p res.
 *
 * @param[in]  num1 Pointer to the first OTI operand.
 * @param[in]  num2 Pointer to the second OTI operand.
 * @param[out] res  Pre-allocated destination structure where result is stored.
 * @param[in]  dhl  Direction helper list object.
 *
 * @note @p res may safely alias @p num1 or @p num2.
 */
void soti_sum_oo_to(const sotinum_t *num1, const sotinum_t *num2, sotinum_t *res, dhelpl_t dhl);

/** @} */
// ------------------------------------------------------------------------------------------------------
```

### 4. Alignment & Columnar Formatting
Align arguments in multiline function declarations when defining groups of variant APIs to maintain clean visual scan paths.

Keep inline comments succinct and place them directly above the relevant operations or on the same line if within the 106-column budget.

### 5. Calling LAPACK / BLAS

- **Never call LAPACK or BLAS symbols (`dgetrf_`, `DGETRF`, `cblas_*`, ...) from C directly**, and
  never include vendor headers (`<Accelerate/Accelerate.h>`, `lapacke.h`). Use the `oti_d*`
  wrappers declared in `include/oti/core/lapack.h`. They are Fortran `bind(C)` subroutines
  (`src/fortran/core/oti_lapack.f90`, library `otilapack`), so the Fortran compiler resolves symbol
  mangling and the hidden string-length arguments on every platform and vendor.
- A new routine means a new wrapper in `oti_lapack.f90` (`integer(c_int)` arguments, flags as
  `character(kind=c_char), value` copied into a default-kind `character(len=1)` local), its
  prototype and Doxygen block in `lapack.h`, and a case in `tests/c/test_lapack.c`.
- Size checks, two kinds:
  - Every value passed to a wrapper as an `int` (dimension, leading dimension, right-hand-side
    count such as `ncols * N_ord`) goes through `oti_lapack_fits()` before it is narrowed.
  - Byte counts of work buffers are checked for `size_t` overflow before `malloc`
    (`lu_buffer_bytes()` in `src/c/sparse/array/algebra_lu.c`); `oti_lapack_fits()` does not
    cover them.
- Linear algebra functions return a status: `info > 0` from `dgetrf` (singular real part) or an
  `OTI_LINALG_ERR_*` code (< 0, `include/oti/sparse/array/algebra_lu.h`). The Python layer maps it
  to an exception (`_raise_linalg_status` in `sparse/linalg.pxi`); never `exit()` on it.

### 6. Performance & Link-Time Optimization (LTO) Awareness
- **Elemental Mathematical Kernels:** Small helper routines (degree checks, monomial table lookups, coefficient index calculations) that are called inside inner loops must be declared static inline in internal header files rather than being isolated as non-inline functions in separate compilation units.
- **Separation of Concerns:** Keep files modular and grouped by algebraic domain (e.g., static/dense vs. dynamic/sparse vs. basis indexing). Do not collapse entire modules into single monster files purely for inlining purposes; rely on CMake INTERPROCEDURAL_OPTIMIZATION (IPO/LTO) to inline across translation units.
