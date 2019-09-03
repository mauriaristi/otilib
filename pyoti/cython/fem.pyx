# cython: boundscheck=False 
# cython: wraparound=False 
# cython: nonecheck=False 
# cython: language_level=3
# cython: profile=False
# cython: linetrace=False
# cython: binding=True
# cython: embedsignature=False
## distutils: define_macros=CYTHON_TRACE_NOGIL=1
## distutils: libraries = oti 
## distutils: extra_compile_args = -arch i386 -arch x86_64
# filename: fem.pyx




from pyoti.core import   number_types, dHelp
from pyoti.core cimport  c_ptr_to_np_1darray_double, ZERO, ONE
from pyoti.core cimport  c_ptr_to_np_2darray_double
from pyoti.core cimport  get_cython_dHelp, dHelp, imdir

from pyoti.real import  dmat
from pyoti.real cimport dmat


from pyoti.dense import  omat, otinum, e
from pyoti.dense cimport omat, otinum


cdef dHelp h = get_cython_dHelp()
cdef dhelpl_t dhl = h.dhl



import  numpy as np
cimport numpy as np












include "fem/core.pxi"
include "fem/elbase.pxi"
include "fem/mesh.pxi"
include "fem/fespace.pxi"
include "fem/fefunction.pxi"
# include "fem/feproblem.pxi"








# include "fem/.pxi"