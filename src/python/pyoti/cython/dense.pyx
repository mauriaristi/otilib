# cython: language_level=3
# cython: c_api_binop_methods=False
"""
Bind dense OTI scalars, SoA / AoS matrices, Gauss-point types and CSR matrices to Python.

Every number is dense over the global bases 1..nact and carries its own truncation order, with the
semi-sparse order rules (PLAN-dense-update.md). The names and call signatures mirror pyoti.sparse.
All C values returned here are owned by their Python wrappers.
"""

import numpy as np
cimport numpy as np
from libc.stdint cimport uint8_t, uint64_t
from pyoti.c_otilib cimport *
from pyoti.core cimport dHelp, get_cython_dHelp
from pyoti.core import expand_imdir as _expand_direction
from pyoti.sparse cimport sotinum, matso
from numbers import Real
from math import comb


cdef dHelp _helper = get_cython_dHelp()
cdef dhelpl_t _dhl = _helper.dhl


include "dense/utils.pxi"
include "dense/scalar/base.pxi"
include "dense/soa/base.pxi"
include "dense/aos/base.pxi"
include "dense/binary.pxi"
include "dense/linalg.pxi"
include "dense/creators.pxi"
include "dense/algebra.pxi"
include "dense/math.pxi"
include "dense/order.pxi"
include "dense/io.pxi"
include "dense/gauss/base.pxi"
include "dense/csr/base.pxi"
include "dense/fem/base.pxi"
