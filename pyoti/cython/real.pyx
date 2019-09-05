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
# filename: real.pyx




import  numpy as np                 # General numerical library
cimport numpy as np                 # C-level functions of numpy
cimport cython                      #

from pyoti.core import   number_types
from pyoti.core cimport  c_ptr_to_np_2darray_double
from c_otilib cimport *             # OTI lib in C.









include "real/array.pxi"

include "real/math.pxi"

include "real/utils.pxi"
