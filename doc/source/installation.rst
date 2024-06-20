Installation
============

Currently, the only way to install pyoti is to build it from source. The source code can be downloaded from https://github.com/mauriaristi/otilib. Make sure that all prerequisites are installed before continuing with the setup of pyoti.


Prerequisites
-------------

The recommended way to install the prerequisites is to use conda and the provided environment.yml file.

Minimum requirements are the following:

* Python 3 (Tested with python 3.9)
* Numpy
* Scipy
* scikit-umfpack
* sksparse-cholmod
* Cython 0.29 (Development plans are in place to support cython 3)
* CMake>=3.20 

.. warning::
    
    This library has been tested under the following operating systems:

    - Unix platforms.
    - macos
    - Windows (only working under WSL)

    A pure windows installation is currently not supported.
    

Conda environment installation instructions:
--------------------------------------------

First you need `Anaconda <https://www.anaconda.com/download>`_ with Python 3. After cloning OTILIB, go to a terminal instance and go to the directory where you donwloaded this repository.

.. code-block:: bash

    cd /PATH/TO/OTILIB-MASTER/

It is recomended to create a conda environment with the required dependencies. For this, it is easier to install the environment.yml file by runing:

.. code-block:: bash
    
    conda env create -f environment.yml


**NOTE**: If you had a previous version of OTILIB, you may avoid this step. However, it is recommended that you update your current environment. For this, run the following command (see `this <https://stackoverflow.com/questions/42352841/how-to-update-an-existing-conda-environment-with-a-yml-file>`_ for more details):

.. code-block:: bash

    conda activate pyoti
    conda env update --file environment.yml --prune


Note: Use ``env_basic.yml`` to use ``pyoti`` in its most basic form.

After runing the previous command, you should have installed/updated the  conda environment that will allow you to use the python version of the library. To activate this environment, run the following command:

.. code-block:: bash

    conda activate pyoti

Adding the local environment to the global jupyter notebook server
------------------------------------------------------------------

You need to install ``ipykernel`` within your environment. To do so, activate your environment if not activated and run the following command.

.. code-block:: bash

    conda install -c anaconda ipykernel


After this, and still within your environment, run the following to add pyoti to your ipython kernel options.

.. code-block:: bash

    python -m ipykernel install --user --name=pyoti



Compiling the library
---------------------

Finally, to build the library with your default compilers, run the following commands:

.. code-block:: bash

    cd path/to/src/otilib
    mkdir build
    cd build
    cmake ..
    make

This will compile the library and link to the required dependencies.

If you want to compile with a different compiler, e.g. the Intel OneApi compilers, you can define the ``CC`` and ``FC`` flags as follow

.. code-block:: bash

    cd path/to/src/otilib
    mkdir build
    cd build
    CC=icx FC=icx cmake ..
    make


.. note::
    
    If you had previously compiled the library and want to change the compiler, you **need** to remove the contents of the build/ directory. Use ``rm -rf -v !(data)`` to keep the data folder (if any).

.. note::

    If this is your first time compiling the library, you should run the following command after the library is compiled:

.. code-block:: bash

    make gendata


This will pre-compute the data required for standard operation of OTI library.

The library is currently in a developmental stage. Because of that, you need to add the library to the conda path in order to import the library in your projects. For this, please run the following command. (Got instructions from `this link <https://stackoverflow.com/questions/49474575/how-to-install-my-own-python-module-package-via-conda-and-watch-its-changes>`_ to add the build directory to the path):

.. code-block:: bash

    cd /PATH/TO/OTILIB-MASTER/build/
    conda activate pyoti
    conda develop .

In order to remove this folder to the path, run:

.. code-block:: bash

    cd /PATH/TO/OTILIB-MASTER/build/
    conda activate pyoti
    conda develop -u .

 