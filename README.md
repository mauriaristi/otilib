# OTIlib and pyoti 

<p align="center">
An open source library for Order Truncated Imaginary (OTI) Numbers. 
An algebra for efficient arbitrary-order, multivariate differentiation.
</p>

Useful links:

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
***

## Current Programming languages: 
* **C** (C99) for core routines.
* **Python** (Version 3 or newer. This library requires [Cython](http://cython.org)
* **Fortran** (F95 or newer, static dense implementation)

## Quick Installation instructions:

For more detailed instructions, see [installation](https://mauriaristi.github.io/otilib/installation)

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

### Requirements

#### **C** version

The current version depends on ```stdlib.h``` and ```math.h```

#### Python version 3:

Requirements:

* Numpy
* Scipy
* Cython (For compilation only)
* CMake (For compilation only)

For the full Finite Element support, the following libraries are required.

* PyVista
* GMSH (and Python-GMSH)
* scikit-umfpack
* scikit-sparse
* vtk

  
***

## Contribution guidelines ###

* To be defined


## Bugs and problems with the library? New features required? ###

* Report an issue using the Github interface, and this will be addressed in an orderly fashion. 
