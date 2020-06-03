
#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------
from pyoti.c_otilib cimport *  

from pyoti.core import   number_types, dHelp
from pyoti.core cimport  c_ptr_to_np_1darray_double, ZERO, ONE
from pyoti.core cimport  c_ptr_to_np_2darray_double
from pyoti.core cimport  get_cython_dHelp, dHelp, imdir

from pyoti.real import  dmat
from pyoti.real cimport dmat

from pyoti.dense import  omat, otinum, e as eps
from pyoti.dense cimport omat, otinum

from pyoti.sparse  import e
from pyoti.sparse  import sotinum, matso, sotife, matsofe, get_deriv
from pyoti.sparse  import zeros, array, ones, eye, truncate
from pyoti.sparse  import det, norm, inv, dot, transpose
from pyoti.sparse  import gauss_integrate

# from pyoti.sparse cimport e
from pyoti.sparse cimport sotinum, matso, sotife, matsofe, get_deriv
from pyoti.sparse cimport zeros, array, ones, eye, truncate
from pyoti.sparse cimport det, norm, inv, dot, transpose
from pyoti.sparse cimport gauss_integrate

import  numpy as np
cimport numpy as np

#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------



cdef dHelp h = get_cython_dHelp()
cdef dhelpl_t dhl = h.dhl