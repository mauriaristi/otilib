
#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

import  numpy as np                 # General numerical library
cimport numpy as np                 # C-level functions of numpy
cimport cython                      #
import warnings
import operator as _op

from operator import index as operator_index
from pyoti.core import   number_types
from pyoti.core cimport  c_ptr_to_np_2darray_double
from pyoti.c_otilib cimport *       # OTI lib in C.

#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------
