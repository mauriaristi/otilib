.. pyoti documentation master file, created by
   sphinx-quickstart on Mon Jun 17 11:32:49 2024.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to OTIlib and pyoti documentation!
==============================================

The OTIlib and pyoti library is a C and Python library to support the Order Truncated Imaginary (OTI) algebra. OTI numbers were developed in the Ph.D. thesis "Order Truncated Imaginary Algebra for Computation of Multivariable High-Order Derivatives in Finite Element Analysis" (`link <https://www.proquest.com/docview/2749270507/>`_). OTI numbers are an extension of Dual numbers. Dual numbers are a hypercomplex algebra that allows computing a single first order derivative per evaluation. OITs, is also a hypercomplex algebra, but in contrast to dual numbers, it can be used to compute efficient high-order derivatives with respect to multiple variables. In contrast to the Dual numbers ( :math:`a + b \epsilon, \epsilon^2 = 0` ), OTI numbers set a truncation condition other than :math:`\epsilon^2 = 0`, and considers multiple imaginary basis. For instance :math:`\epsilon_1^5, \epsilon_1^2\epsilon_2, \ldots, \epsilon_m` can be non-truncated imaginary directions.



More information on HYPAD
=========================

* Theory, references, lecture notes and other information on Hypercomplex-based Automatic Differentiation `HYPAD <https://ceid.utsa.edu/HYPAD/>`_.

.. warning::
   This website is under construction. Documentation placed here may be incomplete.

   Development is constantly being done to improve documentation.


Quick example:
--------------

.. literalinclude:: ../../examples/python/quick_example.py
   :language: python

---------------------------------------------

Contents
========

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   installation
   tutorials
   examples
   aboutus



---------------------------------------------

Module documentation
====================

.. toctree::
   :maxdepth: 1
   :caption: Module documentation:

   pyoti


Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`



