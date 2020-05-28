
#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

from pyoti.core import   number_types, dHelp
from pyoti.core cimport  c_ptr_to_np_1darray_double, ZERO, ONE
from pyoti.core cimport  c_ptr_to_np_2darray_double
from pyoti.core cimport  get_cython_dHelp, dHelp, imdir

from pyoti.real import  dmat
from pyoti.real cimport dmat

from pyoti.dense import  omat, otinum, e
from pyoti.dense cimport omat, otinum

from pyoti.sparse  import sotinum, matso, get_deriv, e as se
from pyoti.sparse  import sotife, matsofe
from pyoti.sparse cimport sotinum, matso, sotife, matsofe

import  numpy as np
cimport numpy as np

#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------



cdef dHelp h = get_cython_dHelp()
cdef dhelpl_t dhl = h.dhl