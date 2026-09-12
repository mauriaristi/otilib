# OTIlib and pyoti 

<p align="center">
An open source library for Order Truncated Imaginary (OTI) Numbers. 
An algebra for efficient arbitrary-order, multivariate differentiation.
</p>

Useful links:

* [Changelog](CHANGELOG.md)
* [Documentation](https://mauriaristi.github.io/otilib/) (work in progress)
* Theory, references, lecture notes and other information on Hypercomplex-based Automatic Differentiation [HYPAD](https://ceid.utsa.edu/HYPAD/).


# OVERVIEW #

**OTILIB** 

This is the repository of the Order Truncated Imaginary numbers (OTI numbers) implemented in different programming languages. OTI numbers, initially developed in [the Ph.D. thesis "Order Truncated Imaginary Algebra for Computation of Multivariable High-Order Derivatives in Finite Element Analysis"](https://www.proquest.com/docview/2749270507/). OTI numbers are an extension of Dual numbers, which can be used to compute high-order derivatives with respect to multiple variables. In contrast to the Dual numbers ( $a + b \epsilon, \epsilon^2 = 0$ ), OTI numbers set a truncation condition other than $\epsilon^2 = 0$, and considers multiple imaginary basis. For instance $\epsilon_1^5,\epsilon_1^2\epsilon_2,\ldots,\epsilon_m$ can be non-truncated imaginary directions.

This library provides multiple implementations of OTI numbers. A core implementation is provided in C that supports various techniques to efficiently treat scalar and array operations such as matrix multiplication, vector dot product, vector array operations, etc.

Ongoing research and updates are currently focused to improve efficiency of the Python and Fortran implementation of OTIs. 

Currently three implementations are supported: 
* Dynamic-Dense (outdated), 
* Static-Dense (modern, fastest) and 
* Dynamic-Sparse  (Slower, but the most versatile and robust)

Most operations implemented so far are serial, and some support OpenMP parallelization. It is expected in the near future to fully support parallel excecution using OpenMP, MPI and GPU parallelization (OpenCL/CUDA/Metal, to be defined).



## Current Programming languages: 
* **C** (C99) for core routines.
* **Python** (Version 3.10 or newer. This library requires [Cython](http://cython.org) >= 3.0)
* **Fortran** (F95 or newer, static dense implementation)

## Quick Installation instructions:

### Conda
The easiest way to get ```otilib``` installed in your system is using conda. Make sure you have a conda installed (see [Anaconda](https://www.anaconda.com/download).)

``` bash
conda install -c mauriaristi pyoti
```

### Compilation

This library has been tested on:

- **Unix** platforms (Ubuntu, CentOS, Rocky Linux).
- **macOS** (Tested on Tahoe 26.*)
- **Windows** (Works only under Windows Subsystem for Linux - [WSL](https://learn.microsoft.com/en-us/windows/wsl/) ) 


1. Create the conda environment with dependencies from the ```environment.yml``` file:
``` bash
conda env create -f environment.yml
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

3. Generate the precomputed data using the following command:

``` bash
make gendata
```

4. Add the current folder to the conda path using :

``` bash

conda activate pyoti
conda develop .
```

For more detailed instructions, see [installation](https://mauriaristi.github.io/otilib/installation)


### Requirements

#### **C** version

The current version depends on ```stdlib.h``` and ```math.h```

#### Python version 3:

Requirements:

* Numpy >= 2.1, < 3
* Scipy
* Cython>=3.0 (For compilation only)
* CMake (For compilation only)

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