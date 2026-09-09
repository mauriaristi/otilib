# AGENTS.md

Guidance for AI agents working in this repository.

## Environment & Prerequisites

- **Conda Environment:** `pyoti` (`python=3.13`) defined in `environment.yml`.
- **Solver Gotcha:** Always use the `rattler` solver (`conda env create -f environment.yml --solver rattler` or `conda install --solver rattler`) on macOS arm64; the classic solver hangs/times out.
- **Key Dependency Pins:**
  - `numpy>=2.1,<3`: OTILib's own C-API usage is NumPy-2-compatible (enforced at build time via `NPY_NO_DEPRECATED_API` in `setup.py.in`). The lower bound is `2.1` rather than `2.0` because numpy 2.0.x publishes no Python 3.13 build at all. The optional `solver='umfpack'`/`solver='cholesky'` sparse-solver paths (`scikits.umfpack`, `sksparse`) depend on those upstream packages publishing NumPy-2-compatible builds; the default `solver='SuperLU'` path is unaffected either way.
  - `vtk<9.4`: `pyvista` compatibility (prevents `vtkCapsuleSource` import error with VTK 9.5+).
  - `cython>=3.0`: Cython 3.x is the standard compiler for building extension modules.
- **OpenMP (macOS):** Requires Homebrew `libomp` at `/opt/homebrew/opt/libomp` and `gfortran` (Homebrew GCC).

### Dependency Availability Check

Before bumping the `python=` / `numpy=` pins, confirm conda-forge publishes builds for every dependency on each target platform. Repeat for `osx-arm64`, `osx-64`, and `linux-64` via `CONDA_SUBDIR`; when cross-solving `linux-64` from macOS, also set `CONDA_OVERRIDE_GLIBC` (otherwise the missing `__glibc` virtual package makes the solve fail spuriously):

```bash
CONDA_SUBDIR=linux-64 CONDA_OVERRIDE_GLIBC=2.28 \
conda create -n __pintest --solver rattler --dry-run -c conda-forge -c anaconda \
  "python=3.13.*" "numpy>=2.1,<3" scipy "cython>=3.0" pandas make cmake pip pytest ipykernel \
  "conda-forge::vtk<9.4" conda-forge::gmsh conda-forge::python-gmsh conda-forge::pyvista \
  conda-forge::scikit-sparse conda-forge::scikit-umfpack -y
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
make gendata
conda develop .
```

### Critical Steps & Gotchas
1. **`make gendata` is required:** Compiles and runs `otigen` to generate lookup tables (`build/data/*.npy`). Importing `pyoti` fails without these files.
2. **`conda develop .` (from `build/`):** Links `build/pyoti` to the conda environment site-packages so `import pyoti` works repository-wide.
3. **Cython build (`oticython` target):** Automatically invoked during `make`. Generated shared objects (`*.so`) are placed into `build/pyoti/`.

## Architecture & Layout

- `src/c/`: C core implementations (scalar, array, dense, sparse, semisparse, static, fem).
- `src/fortran/`: Fortran implementations and wrappers (`core/`, `static/`, `sparse/`, `experimental/`).
- `src/python/pyoti/cython/`: Cython bindings (`core.pyx`, `dense.pyx`, `sparse.pyx`, `real.pyx`, `fem.pyx`, `static/*.pyx`).
- `src/python/pyoti/python/`: Pure Python modules and code generators (`whereotilib.py`, `fmod_writer.py`, `cmod_writer.py`).
- `src/datagen/`: `oti_gen_data.c` binary generator used for `make gendata`.
- `include/oti/`: C/C++ header files.
- `build/pyoti/`: Compiled Python package containing `.so` extensions and copied `.py` files.
- `build/data/`: Generated precomputed order tables (`.npy` files).

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
Run the Python test suite from the repository root to verify imports, precomputed data tables, and mathematical derivative accuracy:

```bash
# Run full Python test suite
pytest tests/python
# or via test runner:
python tests/run_tests.py

# Run specific verification tests
pytest tests/python/test_imports.py        # Installation, submodules & data tables
pytest tests/python/test_sparse_scalar.py  # Scalar math & derivative extraction
pytest tests/python/test_sparse_array.py   # Matrix/array operations & linalg
pytest tests/python/test_static.py         # Static dense modules (onummXnY)
pytest tests/python/test_dense.py          # Dynamic dense OTI numbers
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
./tests/fortran/test_f_static_scalar
./tests/fortran/test_f_sparse_scalar
./tests/cpp/test_cpp_vector
./tests/cpp/test_cpp_headers
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

- **Build phase** runs `ctest --output-on-failure` after `make gendata`, covering the C, Fortran and
  C++ suites in the build environment. The script starts with `set -ex`, so any failure aborts the
  build instead of producing a package.
- **Test phase** runs `pytest tests/python -v` against the *installed* package, plus the version
  consistency checks. `tests/python` and `VERSION` reach that phase through the recipe's
  `source_files:`; the build tree no longer exists there.

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

### 3. NumPy-Style Docstring Format
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

### 2. Function Implementation Delimiters (`.c` / `.cpp`)

Every function implementation in a source file must be visually framed using single-line horizontal dividers of **exactly 106 characters**:

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

### 5. Performance & Link-Time Optimization (LTO) Awareness
- **Elemental Mathematical Kernels:** Small helper routines (degree checks, monomial table lookups, coefficient index calculations) that are called inside inner loops must be declared static inline in internal header files rather than being isolated as non-inline functions in separate compilation units.
- **Separation of Concerns:** Keep files modular and grouped by algebraic domain (e.g., static/dense vs. dynamic/sparse vs. basis indexing). Do not collapse entire modules into single monster files purely for inlining purposes; rely on CMake INTERPROCEDURAL_OPTIMIZATION (IPO/LTO) to inline across translation units.
