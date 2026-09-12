Installation
============

There are two ways to get ``pyoti`` (the Python interface to OTIlib) on your system:

* **Install the conda package** (recommended for most users). A precompiled package is published on
  `anaconda.org <https://anaconda.org/mauriaristi/pyoti>`_ for Linux and macOS. No compilers or
  build steps are required.
* **Build from source** (recommended for development, or if you need a compiler configuration that
  the conda package does not provide). The source code is available at
  https://github.com/mauriaristi/otilib.

Both approaches use conda to manage the environment and its dependencies. Make sure you have a
conda distribution installed (see `Anaconda <https://www.anaconda.com/download>`_ or
`Miniconda <https://docs.conda.io/en/latest/miniconda.html>`_).

.. warning::

    This library has been tested under the following operating systems:

    - Unix platforms (Ubuntu, CentOS, Rocky Linux).
    - macOS (tested on Tahoe 26.*; see macOS specific instructions below when building from source).
    - Windows (only working under `WSL <https://learn.microsoft.com/en-us/windows/wsl/>`_).

    A pure Windows installation is currently not supported.


Installing with conda
---------------------

The easiest way to get ``pyoti`` installed is to create a separate conda environment that includes
the package and all of its requirements:

.. code-block:: bash

    conda create -n pyoti-env -c conda-forge mauriaristi::pyoti --solver rattler

This command:

* Creates a new environment named ``pyoti-env`` (you may choose any other name).
* Installs all dependencies from the ``conda-forge`` channel.
* Installs ``pyoti`` from the ``mauriaristi`` channel on anaconda.org (the ``mauriaristi::pyoti``
  package specification).
* Uses the ``rattler`` solver. This is required because the current default solver freezes while
  solving the environment (observed with conda 26.7.2).

The conda package ships the compiled library together with the precomputed data tables, so no
compilation or ``make gendata`` step is needed.

After the installation completes, activate the environment so that ``pyoti`` becomes importable:

.. code-block:: bash

    conda activate pyoti-env

You can verify the installation with:

.. code-block:: bash

    python -c "import pyoti; print(pyoti.__version__)"

To update to the latest published version at a later time, run the following from within the
environment:

.. code-block:: bash

    conda update -c conda-forge mauriaristi::pyoti --solver rattler

.. note::

    If you also want to use ``pyoti`` from Jupyter notebooks, see
    :ref:`jupyter-kernel` below. The steps are the same for both installation methods, replacing the
    environment name where appropriate.


Building from source
--------------------

Prerequisites
^^^^^^^^^^^^^

The recommended way to install the prerequisites is to use conda and the provided
``environment.yml`` file.

Minimum requirements are the following:

* Python 3 (Tested with python 3.13)
* Numpy >= 2.1, < 3
* Scipy
* scikit-umfpack (optional; only needed for the `solver='umfpack'` sparse solver, requires a NumPy 2-compatible upstream build)
* sksparse-cholmod (optional; only needed for the `solver='cholesky'` sparse solver, requires a NumPy 2-compatible upstream build)
* Cython>=3.0
* CMake>=3.20


Conda environment for building
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

After cloning OTILIB, go to a terminal instance and go to the directory where you downloaded this repository.

.. code-block:: bash

    cd /PATH/TO/OTILIB-MASTER/

It is recommended to create a conda environment with the required dependencies. For this, it is easier to install the environment.yml file by running:

.. code-block:: bash

    conda env create -f environment.yml --solver rattler

The ``--solver rattler`` flag is needed for the same reason as above: the default solver may hang
while solving this environment.

**NOTE**: If you had a previous version of OTILIB, you may avoid this step. However, it is recommended that you update your current environment. For this, run the following command (see `this <https://stackoverflow.com/questions/42352841/how-to-update-an-existing-conda-environment-with-a-yml-file>`_ for more details):

.. code-block:: bash

    conda activate pyoti
    conda env update --file environment.yml --prune --solver rattler


Note: Use ``env_basic.yml`` to use ``pyoti`` in its most basic form.

After running the previous command, you should have installed/updated the conda environment that will allow you to build and use the python version of the library. To activate this environment, run the following command:

.. code-block:: bash

    conda activate pyoti


MacOS additional instructions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

When you use MacOS, particularly Apple Silicon Macs, it is recommended to have the following steps:

Install libomp using brew:

.. code-block:: bash

    brew install libomp

In addition, install GNU gfortran from conda-forge:

.. code-block:: bash

    conda install -c conda-forge gfortran --solver rattler

This will add gfortran with support for the architecture of your processor, which is important.


Compiling the library
^^^^^^^^^^^^^^^^^^^^^

In order to build the library with your default compilers, run the following commands:

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

Additional CMake compilation options include disabling ``OpenMP`` compilation. For that, use a command line as follows:

.. code-block:: bash

    cmake -D USE_OPENMP=OFF ..



The library is currently in an active development stage. Therefore, you need to add the library to the conda path in order to import the library in your projects. For this, please run the following command. (Got instructions from `this link <https://stackoverflow.com/questions/49474575/how-to-install-my-own-python-module-package-via-conda-and-watch-its-changes>`_ to add the build directory to the path):

.. code-block:: bash

    cd /PATH/TO/OTILIB-MASTER/build/
    conda activate pyoti
    conda develop .

In order to remove this folder to the path, run:

.. code-block:: bash

    cd /PATH/TO/OTILIB-MASTER/build/
    conda activate pyoti
    conda develop -u .


.. _jupyter-kernel:

Adding the environment to the global jupyter notebook server
------------------------------------------------------------

You need to install ``ipykernel`` within your environment. To do so, activate your environment if not activated and run the following command (``ipykernel`` is already included when the environment was created from ``environment.yml``).

.. code-block:: bash

    conda install -c conda-forge ipykernel --solver rattler


After this, and still within your environment, run the following to add the environment to your ipython kernel options. Replace ``pyoti-env`` with ``pyoti`` if you built from source.

.. code-block:: bash

    python -m ipykernel install --user --name=pyoti-env

