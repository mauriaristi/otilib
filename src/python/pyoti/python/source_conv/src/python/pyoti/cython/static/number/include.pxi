
#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

import numpy as np                  # General numerical library
cimport numpy as np                 # C-level functions of numpy
from pyoti.c_otilib cimport *       # OTI lib in C.
cimport cython                      #

from cython.parallel import prange

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

#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

cdef dHelp h = get_cython_dHelp()
cdef dhelpl_t dhl = h.dhl

# set_python_error_function(error_function)