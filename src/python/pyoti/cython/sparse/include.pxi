
#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

import numpy as np                  # General numerical library
import warnings
import operator as _op
cimport numpy as np                 # C-level functions of numpy
from pyoti.c_otilib cimport *       # OTI lib in C.
cimport cython                      #



import scipy.sparse as sci_spr


from libc.stdlib cimport malloc,free      # import memory managment functions.
from libc.stdlib cimport realloc          #    "              "
from libc.string cimport memset, memcpy


from pyoti.core import   number_types, dHelp, imdir, print_capabilities
from pyoti.core cimport  ZERO, ONE, get_cython_dHelp, dHelp, imdir, is_integer
from pyoti.core cimport  c_ptr_to_np_1darray_double, c_ptr_to_np_1darray_uint64 
from pyoti.core cimport  c_ptr_to_np_1darray_uint8, error_function


import  pyoti.real as r
cimport pyoti.real as r

from pyoti.real import  dmat
from pyoti.real cimport dmat
from pyoti.real cimport key2d, assign_plan, gauss_key, reshape_shape
from pyoti.real cimport _dmat_out, _dmat_out_shape


# The logical shape kind of a dmat result: the result takes the kind of the operand it follows.
cdef inline object _dmat_like(dmat d, dmat like):
  d._lk = like._lk
  return d

#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------



cdef dHelp h = get_cython_dHelp()
cdef dhelpl_t dhl = h.dhl

# set_python_error_function(error_function)