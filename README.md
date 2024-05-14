# OTIlib: 

An open source library for Order Truncated Imaginary (OTI) Numbers. An algebra for efficient arbitrary-order, multivariate differentiation.

# OVERVIEW #

**OTILIB** 

This is the repository of the Order Truncated Imaginary numbers (OTI numbers) implemented in different programming languages. OTI numbers is the extension of Dual numbers to compute high-order derivatives with respect to multiple variables. OTIs provide a concise extension of the Dual numbers ( $a + b \epsilon, \epsilon^2 = 0$ ) and are applicable to computing high order derivatives of computer functions at execution time.

OTI numbers are herein implemented in multiple programming languages. The core implementation is in C and supports various techniques to efficiently treat scalar and array operations such as matrix multiplication, vector dot product, etc.

Ongoing research is currently towards efficient implementation of a Fortran version to determine the best implementation version of OTIs. 

Currently three implementations are supported: 
* Dynamic-Dense, 
* Static-Dense and 
* Dynamic-Sparse 

All implementations so far are serial. It is expected in the near future to support parallel excecution using OpenMP, OpenMPI and OpenCL/CUDA/Metal (TBD).
***

## Current Programming languages: 
* **C** (C99) Core routines.
* **Python** (Version 3 or newer. This library requires [Cython](http://cython.org)
* **Fortran** (F95 or newer, only dense implementation so far)

The following programming languages will be implemented in a very near future:

* **Swift**
* **Julia**

Far-future implementation we are looking forward are:

* **C++** (C++11)
* **Matlab**
* **Java** / **Javascript**

## Installation instructions:

First you need [Anaconda 3](https://www.anaconda.com/distribution/) with Python 3. After cloning OTILIB, go to a terminal instance and go to the directory where you donwloaded this repository.
```
cd /PATH/TO/OTILIB-MASTER/
```

It is recomended to create a conda environment with the required dependencies. For this, it is easier to install the environment.yml file by runing:
```
conda env create -f environment.yml
```
**NOTE**: If you had a previous version of OTILIB, you may avoid this step. However, it is recommended that you update your current environment. For this, run the following command (see [this](https://stackoverflow.com/questions/42352841/how-to-update-an-existing-conda-environment-with-a-yml-file) for more details):

```
conda activate pyoti
conda env update --file environment.yml --prune
```

Note: Use ```env_basic.yml``` to use ```pyoti``` in its most basic form.

After runing the previous command, you should have installed/updated the  conda environment that will allow you to use the python version of the library. To activate this environment, run the following command:
```
conda activate pyoti
```

### Adding the local environment to the global jupyter notebook server.

You need to install ```ipykernel``` within your environment. To do so, activate your environment if not activated and run the following command.

```
conda install -c anaconda ipykernel
```

After this, and still within your environment, run the following to add pyoti to your ipython kernel options.

```
python -m ipykernel install --user --name=pyoti
```



### Compiling the library.

Finally, to build the library, run the following commands:

```
cd path/to/src/otilib
mkdir build
cd build
cmake ..
make
```
 
This will compile the library and link to the required dependencies.

**NOTE**: If this is your first time compiling the library, you should run the following command after the library is compiled:

```
make gendata
```

This will pre-compute the data required for standard operation of OTI library.

The current version of the library is in a developmental stage, and because of that you require to add the library to the conda path in order for the user to be able to import the library in your projects. For this, please run the following command or head to [this](https://stackoverflow.com/questions/49474575/how-to-install-my-own-python-module-package-via-conda-and-watch-its-changes) link in order to add the build directory to the path:

```
cd /PATH/TO/OTILIB-MASTER/build/
conda activate pyoti
conda develop .
```

In order to remove this folder to the path, run:

```
cd /PATH/TO/OTILIB-MASTER/build/
conda activate pyoti
conda develop -u .
```

## What is this repository for? 

* Quick summary
* Version: 1.0


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

For the full Finite Element Module support, the following libraries may be useful to find.

* PyVista
* GMSH (and Python-GMSH)
* vtk

  

***

## Contribution guidelines ###

* To be defined


## Who do I talk to? ###

* Direct comments to the library should be addressed to Mauricio Aristizabal to [this e-mail](mailto:mauriaristi@gmail.com) with the subject: "[OTILIB]:*concern*: your subject "

The word *concern* may be replaced by one of the following (choose accordingly):

* *bugc*: C code bugs
* *bugpy*: Python code bugs
* *bugswift*: Swift code bugs
* *doc*: Documentation bugs
* *example*: Trouble in one of the examples.
* *wrapper*: Questions related with wrappers to other languages.

***

## Other things 

* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)
