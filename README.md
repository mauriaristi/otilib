# OVERVIEW #

**OTILIB** 

This is the repository for the implementation of Order Truncated Imaginary numbers (OTI numbers) in different programming languages. OTI algebra is the extension of Dual numbers such that they can compute higher order derivatives of multiple variables. They provide a concise extension of the Dual numbers ( a + b eps, eps^2 = 0 ) and are applicable to computing high order derivatives of computer functions at execution time.

***

## Current Programming languages: 
* **C** (C99) Core routines.
* **Python** (Version 3 or newer. This library requires [Cython](http://cython.org)

The following programming languages will be implemented in a very near future:

* **Fortran** (F95 or newer, only dense implementation so far)
* **Swift**
* **Julia**

Far-future implementation we are looking forward are:

* **C++** (C++11)
* **Matlab**
* **Java** / **Javascript**

## Installation instructions:

First you need [Anaconda 3](https://www.anaconda.com/distribution/) with Python 3. After installing and cloning OTILIB, go to the Terminal and go to the directory where you donwloaded this repository.
```
cd /PATH/TO/OTILIB-MASTER/
```

It is recomended to create an environment with the required dependencies. For this, it is easier to install the environment.yml file by runing:
```
conda env create -f environment.yml
```
NOTE: If you had a previous version of OTILIB, 

After runing the previous command, you should have installed a conda environment that will allow you to use the python library. To activate this environment, run the following command:
```
conda activate pyoti
```

Finally, to install the library, run:
```
cd path/to/src/otilib
mkdir build
cd build
cmake ..
make
```
 
This will compile the library and link to the required dependencies.

NOTE: If this is your first time compiling the library, you should run the following command after the library is compiled:

```
make gendata
```

This will pre-compute the data required for standard operation of OTI library.



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
