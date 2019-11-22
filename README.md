# OVERVIEW #

**OTILIB** 

This is the repository for the implementation of Order Truncated Imaginary numbers (OTI numbers) in different programming languages. OTI algebra is the extension from the imaginary numbers perspective to the Truncated Taylor Polynomials. They provide a concise extension of the Dual numbers ( a + b eps, eps^2 = 0 ) and are applicable to computing high order derivatives computer programmed functions.

***

## Current Programming languages: 
* **C** (C99)
* **Python** (Version 3 or newer. We are currently using [Cython](http://cython.org)

The following programming languages are to be implemented in a very near future:

* **Fortran** (F95 or newer)
* **C++** (C++11)

Far-future implementation we are looking forward are:

* **Matlab**
* **Java** / **Javascript**
* **Julia**

The wonderful world of OTIs

## What is this repository for? 

* Quick summary
* Version: 1.0


***

## Quick set up.

* Summary of set up

First you need anaconda 3. Then you should install the environment.yml file by runing:

```
conda env create -f environment.yml
```

Then, after created the environment you should activate the environment,

```
conda activate pyoti
```

Finally, run:
```
cd path/to/src/otilib
mkdir build
cd build
cmake ..
make
```

* Configuration
* Dependencies
* Database configuration
* How to run tests
* Deployment instructions

### Requirements

#### **C** version

The current version only depends on ```stdlib.h``` and ```math.h```

#### Python version 3:

Requirements:
- Numpy
- Scipy
- partitionsets

***

## Contribution guidelines ###

* To be defined


## Who do I talk to? ###

* Direct comments to the library should be addressed to Mauricio Aristizabal to [this e-mail](mailto:mauriaristi@gmail.com) with the subject: "[OTILIB]:*concern*: your subject "

The word *concern* may be replaced by one of the following (choose accordingly):
* *CodeTroubleC*: C code bugs
* *CodeTroublePy*: Python code bugs
* *DocTrouble*: Documentation bugs
* *ExampleTrouble*: Trouble in one of the examples.
* *NewWrapper*: Questions related with new wrappers to other languages.

***

## Other things 

* [Learn Markdown](https://bitbucket.org/tutorials/markdowndemo)
