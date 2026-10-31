# OTIlib #

<p align="center">
An open source library for Order Truncated Imaginary (OTI) Numbers. 
An algebra for efficient high-order differentiation with respect to multiple variables.
</p>

Useful links:

* [Changelog](CHANGELOG.md)
* [Documentation](https://mauriaristi.github.io/otilib/) (work in progress)
* Additional theory, references, lecture notes, and other information on Hypercomplex-based Automatic Differentiation [HYPAD](https://ceid.utsa.edu/HYPAD/).


# OVERVIEW #

**OTILIB** is a library that implements the Order Truncated Imaginary numbers (OTI numbers), a hypercomplex algebra that computes exact high-order derivatives with respect to many variables at once. An OTI number stores a real value and coefficients that carry derivative information up to a chosen order.  Arithmetic and supported
mathematical functions propagate these coefficients through your calculation.  

You write your program once, with OTI numbers in place of real numbers, and the library returns the value
of the result together with coefficients that contains its derivatives up to the order you choose. This allows you to extract first derivatives, higher derivatives, and mixed derivatives of a computed result.

OTI numbers extend the Dual numbers. A Dual number $a + b \epsilon, \epsilon^2 = 0$  with $\epsilon^2 = 0$ carries only first derivatives of one variable. An OTI number carries one imaginary unit
$\epsilon_1, \ldots, \epsilon_m$ per variable and truncates products only above a chosen order, so
terms such as $\epsilon_1^5$ or $\epsilon_1^2\epsilon_2$ survive and hold the corresponding
high-order and mixed derivatives.

The project began in 2016, when OTI numbers were initially developed in the PhD thesis titled 
["Order Truncated Imaginary Algebra for Computation of Multivariable High-Order Derivatives in Finite Element Analysis"](https://www.proquest.com/docview/2749270507/) from Universidad EAFIT, in Medellin, Colombia.


### Languages and execution

The library implements the OTI algebra in a **C core** and exposes it to **Python** using Cython as `pyoti`, with NumPy and SciPy integration; and partially, to **Fortran** which provides generated fixed-size OTI types and a limited first-order sparse type.   Current Fortran tests check representative scalar arithmetic, an elementary function, and version information. Fortran also supplies the BLAS/LAPACK wrappers used by the C core; but it does not yet expose the full dynamic C API to Fortran applications. 

For every implementation it provides:

* **Scalars**: arithmetic (`+ - * /`, powers) between OTI numbers and real numbers.
* **Elementary functions**: `sin`, `cos`, `tan`, `asin`, `acos`, `atan`, `sinh`, `cosh`, `tanh`,
  `asinh`, `acosh`, `atanh`, `exp`, `log`, `log10`, `logb`, `sqrt`, `cbrt`, `pow`, `erf`, `abs`.
* **Arrays and matrices** of OTI numbers: elementwise operations and functions, matrix product,
  dot product, transpose, norm, indexing and slicing.
* **Dense linear algebra** on OTI matrices: `solve`, `inv`, `det`, `lu_factor`, `lu_solve`. These
  routines factor the real part once with LAPACK and reuse that factorization for every derivative.
* **Derivative access**: read and write individual imaginary coefficients and derivatives
  (`get_im`, `get_deriv`, `set_im`, `extract_im`, `extract_deriv`, `get_all_derivs`, ...), and change
  the truncation order of a number.
* **Utilities**: Taylor series evaluation (`rom_eval`), `interp1d`, `moving_average`,
  truncated products and subtractions.
* **Save and read** of OTI numbers and arrays in binary files.
* **Finite elements**: Gauss-point OTI types, OTI sparse matrices (`lil_matrix`, `csr_matrix`) with
  a sparse solver (SciPy SuperLU by default; UMFPACK and CHOLMOD optionally), and the `pyoti.fem`
  module (meshes through GMSH, 1D/2D/3D Lagrange elements, numerical integration, assembly). This
  lets you compute derivatives of a finite element solution with respect to material, load or
  geometry parameters.

Selected CPU operations use **OpenMP**. Matrix multiplication and linear algebra also use
**BLAS/LAPACK**, whose threading depends on the linked library. Avoid assigning all CPU cores
to both OpenMP and BLAS at the same time.

The current release does not provide Julia, MATLAB, or Rust bindings, MPI execution, or CUDA,
HIP, or Metal backends.



### Available implementations


OTIlib provides four implementations. They differ in how they store the
imaginary coefficients, so each one suits a different kind of problem.

| Implementation | Python module | Storage | Best suited for |
|---|---|---|---|
| **Dense** (default) | `pyoti.dense` (also `import pyoti`) | Stores every coefficient over the bases $1 \ldots n$; each number carries its own truncation order (up to 150). | General use with a moderate number of variables. |
| **Semi-sparse** | `pyoti.semisparse` | Stores every coefficient, but only over the bases the number actually uses (base labels up to 65535). | Problems with a handful to about 100 parameters at moderate order, for example FEM and CFD models. |
| **Sparse** | `pyoti.sparse` | Stores only the nonzero imaginary directions. | Many variables where each result depends on only a few of them. |
| **Static** | `pyoti.static.onumm<M>n<N>` | Fixed number of bases `M` and fixed order `N`, generated at compile time. | Small, fixed problems where speed matters most. |


The dense, semi-sparse and sparse implementations share the same Python API. A script written for
`pyoti.sparse` runs unchanged with `pyoti.semisparse` or `pyoti.dense`. Each of these three
implementations provides scalars, arrays in two memory layouts (array-of-structures and
structure-of-arrays), Gauss-point types, OTI sparse matrices, and save/read, and converts to and
from the sparse types.

The static implementation provides by default the following combinations of bases (`m`) and order (`n`):

* 1 basis: orders 1, 2, 3, 4, 10, 20 and 30 (`onumm1n1` ... `onumm1n30`).
* 2 bases: orders 1 to 4 (`onumm2n1` ... `onumm2n4`).
* 3 bases: orders 1 to 4 (`onumm3n1` ... `onumm3n4`).
* 10 bases: orders 1 and 2 (`onumm10n1`, `onumm10n2`).

Other combinations can be generated using the `pyoti.core.cmod_writer(...)` and `pyoti.core.fmod_writer(...)` utils provided with the library.

## Quick Installation instructions:

### Conda
The easiest way to get ```otilib``` installed in your system is using conda on a separate environment that includes all requirements. Make sure you have a conda installed (see [Anaconda](https://www.anaconda.com/download).)

``` bash
conda create -n pyoti-env -c conda-forge mauriaristi::pyoti --solver rattler
```
- Installs dependencies from conda-forge
- Installs the library from conda.
- Utilizes the ```rattler``` solver as the current defaul solver freezes during environment solve (using conda 26.7.2).

After installation, you can activate your conda environment so that otilib is accessible. You can use it via Python using ```pyoti```.

``` bash
conda activate pyoti-env
```

### Example

A first example in Python:

```python
import pyoti.semisparse as oti

x = 0.5 + oti.e(1, order=3)      # x = 0.5, perturbed along variable 1, up to order 3
y = 2.0 + oti.e(2, order=3)      # y = 2.0, perturbed along variable 2
f = oti.sin(x * y)

print(f"f(0.5.2.0) : {f.real}")                 # sin(1.0)
print(f"d^2f/ dx dy: {f.get_deriv([1, 2])}")    # d^2 f / dx dy
print(f"d^3f/ dx^3 : {f.get_deriv([1, 1, 1])}") # d^3 f / dx^3
```


## Compilation

The recommended approach to compile this library is to use a conda environment setup with the ```environment.yml``` file.


1. Create the conda environment with dependencies from the ```environment.yml``` file:
``` bash
conda env create -f environment.yml --solver rattler
conda activate pyoti
```

2. Create a ```build``` directory within the library's master folder, and configure the compilation usign CMake:

``` bash
cd path/to/src/otilib
mkdir build
cd build
cmake ..
make
```

3. Add the current folder to the conda path using :

``` bash

conda activate pyoti
conda develop .
```

For more detailed instructions, see [installation](https://mauriaristi.github.io/otilib/installation)

This library has been tested on:

- **Unix** platforms (Ubuntu, CentOS, Rocky Linux).
- **macOS** (Tested on Tahoe 26.*)
- **Windows** (Works only under Windows Subsystem for Linux - [WSL](https://learn.microsoft.com/en-us/windows/wsl/) ). Native Windows builds are not supported.



### Requirements

#### **C** version

The current version depends on ```stdlib.h```, ```math.h``` and a LAPACK / BLAS library (LP64,
32-bit integers), found at build time by CMake (>= 3.22):

* conda: `libblas` and `liblapack` (already in `environment.yml`).
* Linux: `liblapack-dev` or `libopenblas-dev` from the system package manager.
* macOS: Accelerate, part of the OS (`cmake -DOTI_BLA_VENDOR=Apple ..`).

`OTI_BLA_VENDOR` accepts CMake's `BLA_VENDOR` values (`Apple`, `OpenBLAS`, `Generic`,
`Intel10_64lp`, ...); left empty, CMake searches in its default order. A Fortran compiler is
required as well: the C code calls LAPACK through Fortran wrappers.

#### Python version 3:

Requirements:

* Numpy >= 2.1, < 3
* Scipy
* Cython>=3.0 (For compilation only)
* CMake >= 3.22 (For compilation only)
* LAPACK / BLAS (For compilation; see the C requirements above)

For the full Finite Element support, the following libraries are required.

* PyVista
* GMSH (and Python-GMSH)
* scikit-umfpack (optional accelerator for `solver='umfpack'`; requires a NumPy 2-compatible build from upstream)
* scikit-sparse (optional accelerator for `solver='cholesky'`; requires a NumPy 2-compatible build from upstream)
* vtk

  
***

## Versioning

OTIlib follows [Semantic Versioning](https://semver.org/spec/v2.0.0.html). The version lives in the
root [`VERSION`](VERSION) file, which is the single source of truth: CMake generates the C header,
the Fortran module and the Python version module from it at configure time, and the conda recipe
reads it directly. Notable changes are recorded in the [changelog](CHANGELOG.md).

Querying the version from each implementation:

```c
#include <oti/oti.h>

printf("%s\n", oti_version());        /* version of the linked library */
printf("%s\n", OTI_VERSION_STRING);   /* version of the headers compiled against */

#if OTI_VERSION_NUMBER >= OTI_VERSION_ENCODE(1, 1, 0)
    /* feature available since 1.1.0 */
#endif
```

```fortran
USE oti_version

WRITE(*,*) OTI_VERSION_STRING     ! "1.1.0"
WRITE(*,*) OTI_VERSION_NUMBER     ! 10100
```

```python
import pyoti

pyoti.__version__          # '1.1.0'
pyoti.__version_info__     # (1, 1, 0)
pyoti.core.c_version()     # version of the linked C library
```

To release a new version, bump the `VERSION` file and re-run `cmake`:

```bash
python tools/bump_version.py minor    # or: major / patch / an explicit X.Y.Z
```

## Contribution guidelines ###

* To be defined


## Bugs and problems with the library? New features required? ###

* Report an issue using the Github interface, and this will be addressed in an orderly fashion. 


<!-- 
### Citations ###

```bibtex
@software{pyoti,
 title = {OTIlib: An open source library for Order Truncated Imaginary (OTI) Numbers},
 version = {1.1.0},
 author = {Aristizabal, Mauricio},
 year = 2024,
 keywords = {Python, Hypercomplex Algebras, Complex Step, Hyperdual numbers,},
 url = {https://github.com/mauriaristi/otilib}
}
```
 -->