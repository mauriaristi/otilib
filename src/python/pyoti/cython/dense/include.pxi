#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

import numpy as np                  # General numerical library
cimport numpy as np                 # C-level functions of numpy
from c_otilib cimport *             # OTI lib in C.
cimport cython                      #

from libc.stdlib cimport free      # import memory managment functions.

from pyoti.core import   number_types, dHelp, imdir # To make them available on import.
from pyoti.core import   dhelp_get_matrix_form, print_capabilities
from pyoti.core import   get_latex_dir, set_trunc_order, get_trunc_order

from pyoti.core cimport  c_ptr_to_np_1darray_double, ZERO, ONE
from pyoti.core cimport  c_ptr_to_np_2darray_double
from pyoti.core cimport  c_ptr_to_np_1darray_uint64
from pyoti.core cimport  c_ptr_to_np_1darray_uint8
from pyoti.core cimport  get_cython_dHelp, dHelp, imdir
from pyoti.core cimport  copy_numpy2d_to_ptr_f64


from pyoti.real import  dmat
from pyoti.real cimport dmat


#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------



cdef dHelp      h = get_cython_dHelp()
cdef dhelpl_t dhl = h.dhl