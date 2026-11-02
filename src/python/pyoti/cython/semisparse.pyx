# cython: language_level=3
# cython: c_api_binop_methods=False
"""
Bind semi-sparse scalars and array-of-structures / structure-of-arrays matrices to Python.

All C values returned here are owned by their Python wrappers.
"""

import numpy as np
cimport numpy as np
from libc.stdint cimport uint64_t
from pyoti.c_otilib cimport *
from pyoti.core cimport dHelp, get_cython_dHelp
from pyoti.core import expand_imdir as _expand_direction
from pyoti.sparse cimport sotinum, matso
from numbers import Real
from math import comb
from time import perf_counter as _perf_counter


cdef dHelp _helper = get_cython_dHelp()
cdef dhelpl_t _dhl = _helper.dhl


include "semisparse/utils.pxi"
include "semisparse/scalar/base.pxi"
include "semisparse/soa/base.pxi"
include "semisparse/aos/base.pxi"
include "semisparse/binary.pxi"
include "semisparse/linalg.pxi"
include "semisparse/creators.pxi"
include "semisparse/algebra.pxi"
include "semisparse/math.pxi"
include "semisparse/order.pxi"
include "semisparse/io.pxi"
include "semisparse/gauss/base.pxi"
include "semisparse/csr/base.pxi"
include "semisparse/fem/base.pxi"
include "semisparse/profile.pxi"
