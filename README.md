# OTIlib and pyoti 

<p align="center">
An open source library for Order Truncated Imaginary (OTI) Numbers. An algebra for efficient arbitrary-order, multivariate differentiation.
</p>

Useful links:

* [Documentation](https://mauriaristi.github.io/otilib/) (work in progress)
* Theory, references, lecture notes and other information on Hypercomplex-based Automatic Differentiation [HYPAD](https://ceid.utsa.edu/HYPAD/).


# OVERVIEW #

**OTILIB** 

This is the repository of the Order Truncated Imaginary numbers (OTI numbers) implemented in different programming languages. OTI numbers, initially developed in [the Ph.D. thesis "Order Truncated Imaginary Algebra for Computation of Multivariable High-Order Derivatives in Finite Element Analysis"](https://www.proquest.com/docview/2749270507/). OTI numbers are an extension of Dual numbers, which can be used to compute high-order derivatives with respect to multiple variables. In contrast to the Dual numbers ( $a + b \epsilon, \epsilon^2 = 0$ ), OTI numbers set a truncation condition other than $\epsilon^2 = 0$, and considers multiple imaginary basis. For instance $\epsilon_1^5,\epsilon_1^2\epsilon_2,\ldots,\epsilon_m$ can be non-truncated imaginary directions.

This library provides multiple implementations of OTI numbers. A core implementation is provided in C that supports various techniques to efficiently treat scalar and array operations such as matrix multiplication, vector dot product, vector array operations, etc.

Ongoing research and updates is currently focused towards the efficient implementation of a Fortran version of OTIs. 

Currently three implementations are supported: 
* Dynamic-Dense (outdated), 
* Static-Dense (modern, fastest) and 
* Dynamic-Sparse  (Slower, but the most versatile and robust)

Most operations implemented so far are serial, and some support OpenMP parallelization. It is expected in the near future to fully support parallel excecution using OpenMP, MPI and GPU parallelization (OpenCL/CUDA/Metal, to be defined).
***

## Current Programming languages: 
* **C** (C99) Core routines.
* **Python** (Version 3 or newer. This library requires [Cython](http://cython.org)
* **Fortran** (F95 or newer, static dense implementation)

The following programming languages will be added in due time:

* **Matlab**
* **C++** (C++11)
* **Julia**
* **Swift**
* **Java** / **Javascript**

## Installation instructions:

First you need [Anaconda 3](https://www.anaconda.com/distribution/) with Python 3. After cloning OTILIB, go to a terminal instance and go to the directory where you donwloaded this repository.
``` bash
cd /PATH/TO/OTILIB-MASTER/
```

It is recomended to create a conda environment with the required dependencies. For this, it is easier to install the environment.yml file by runing:
``` bash
conda env create -f environment.yml
```
**NOTE**: If you had a previous version of OTILIB, you may avoid this step. However, it is recommended that you update your current environment. For this, run the following command (see [this](https://stackoverflow.com/questions/42352841/how-to-update-an-existing-conda-environment-with-a-yml-file) for more details):

``` bash
conda activate pyoti
conda env update --file environment.yml --prune
```

Note: Use ```env_basic.yml``` to use ```pyoti``` in its most basic form.

After runing the previous command, you should have installed/updated the  conda environment that will allow you to use the python version of the library. To activate this environment, run the following command:
``` bash
conda activate pyoti
```

### Adding the local environment to the global jupyter notebook server.

You need to install ```ipykernel``` within your environment. To do so, activate your environment if not activated and run the following command.

``` bash
conda install -c anaconda ipykernel
```

After this, and still within your environment, run the following to add pyoti to your ipython kernel options.

``` bash
python -m ipykernel install --user --name=pyoti
```



### Compiling the library.

Finally, to build the library, run the following commands:

``` bash
cd path/to/src/otilib
mkdir build
cd build
cmake ..
make
```
 
This will compile the library and link to the required dependencies.

**NOTE**: If this is your first time compiling the library, you should run the following command after the library is compiled:

``` bash
make gendata
```

This will pre-compute the data required for standard operation of OTI library.

The current version of the library is in a developmental stage, and because of that you require to add the library to the conda path in order for the user to be able to import the library in your projects. For this, please run the following command or head to [this](https://stackoverflow.com/questions/49474575/how-to-install-my-own-python-module-package-via-conda-and-watch-its-changes) link in order to add the build directory to the path:

``` bash
cd /PATH/TO/OTILIB-MASTER/build/
conda activate pyoti
conda develop .
```

In order to remove this folder to the path, run:

``` bash
cd /PATH/TO/OTILIB-MASTER/build/
conda activate pyoti
conda develop -u .
```

## What is this repository for? 

* Quick summary
* Version: 0.1


### Requirements

#### **C** version

The current version depends on ```stdlib.h``` and ```math.h```

#### Python version 3:

Requirements:

* Numpy
* Scipy
* scikit-umfpack
* scikit-sparse
* Cython (For compilation only)

For the full Finite Element support, the following libraries are required.

* PyVista
* GMSH (and Python-GMSH)
* vtk

  
***

## Contribution guidelines ###

* To be defined


## Bugs and problems with the library? New features required? ###

* Report an issue using the Github interface, and this will be addressed in an orderly fashion. 
