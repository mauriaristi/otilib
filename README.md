# OTIlib 

<p align="center">
An open source library for Order Truncated Imaginary (OTI) Numbers. 
An algebra for efficient arbitrary-order, multivariate differentiation.
</p>


Useful links:

* [Changelog](CHANGELOG.md)
* [Documentation](https://mauriaristi.github.io/otilib/) (work in progress)
* Additional theory, references, lecture notes, and other information on Hypercomplex-based Automatic Differentiation [HYPAD](https://ceid.utsa.edu/HYPAD/).


# OVERVIEW #

**OTILIB** 

This is the repository of the Order Truncated Imaginary numbers (OTI numbers), a hypercomplex algebra that allows the calculation of high-order, multivariable derivatives in computer programs. The core implementation is developed in C++ (following the majority of the C++20 standard), and provides an interface with C to languages like Fortran, Python, Julia, and Matlab. OTI numbers were initially developed in the PhD thesis titled ["Order Truncated Imaginary Algebra for Computation of Multivariable High-Order Derivatives in Finite Element Analysis"](https://www.proquest.com/docview/2749270507/). This project started with this PhD project, and has been developed since 2016.

OTI numbers extend the Dual numbers and can be used to compute high-order derivatives with respect to multiple variables. In contrast to the Dual numbers ( $a + b \epsilon, \epsilon^2 = 0$ ), OTI numbers set a truncation condition other than $\epsilon^2 = 0$, and considers multiple imaginary basis. For instance $\epsilon_1^5,\epsilon_1^2\epsilon_2,\ldots,\epsilon_m$ can be non-truncated imaginary directions.

This library provides multiple implementations of OTI numbers, supporting different usage cases. Each implementation supports techniques to efficiently treat scalar and tensor operations such as elementwise operations, matrix multiplication, vector dot product, vector array operations, etc in an efficient manner.

Currently three implementations are supported: 
* Sparse implementation (default)
* Dynamic dense implementation (partial support)
* Static-Dense 

Parallelization is supported for shared-memory (OpenMP), distributed memory (MPI), and GPU support is provided via CUDA and Metal backends.

## Current Programming languages: 

* **C++** (C++20) for core routines.
* **C**: Exposed from the C++ implementation via extern C declarations.
* **Python** (Version 3.13 or newer. This library requires [Cython](http://cython.org) >= 3.0)
* **Fortran** (F2018  standard or newer) Exposes all core features.
* **MATLAB** .
* **Julia** .

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

## Compilation

In order to compile this library, the recommended approach is to use a conda environment setup with the ```environment.yml``` file.


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