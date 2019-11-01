
#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

import numpy as np                  # General numerical library
cimport numpy as np                 # C-level functions of numpy
from c_otilib cimport *             # OTI lib in C.
cimport cython                      #

from pyoti.core import   number_types, dHelp, imdir
from pyoti.core cimport  ZERO, ONE, get_cython_dHelp, dHelp, imdir
from pyoti.core cimport  c_ptr_to_np_1darray_double

#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------



cdef dHelp h = get_cython_dHelp()
cdef dhelpl_t dhl = h.dhl

