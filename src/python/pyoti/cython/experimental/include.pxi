# Import c_types from otilib.
from pyoti.c_otilib cimport * 
from pyoti.experimental.c_pytorch_graph_interface cimport * 

from openmp cimport omp_get_thread_num, omp_get_num_threads, omp_get_num_procs
from cython.parallel cimport prange
from libc.stdlib cimport malloc, free

# # Import all c-capabilities from pyoti.
# import  pyoti.static.onumm1n1 as oti_m1n1
# cimport pyoti.static.onumm1n1 as oti_m1n1

# import  pyoti.static.onumm1n2 as oti_m1n2
# cimport pyoti.static.onumm1n2 as oti_m1n2

# import  pyoti.static.onumm1n3 as oti_m1n3
# cimport pyoti.static.onumm1n3 as oti_m1n3

# import  pyoti.static.onumm1n4 as oti_m1n4
# cimport pyoti.static.onumm1n4 as oti_m1n4

# import  pyoti.static.onumm2n1 as oti_m2n1
# cimport pyoti.static.onumm2n1 as oti_m2n1

# import  pyoti.static.onumm2n2 as oti_m2n2
# cimport pyoti.static.onumm2n2 as oti_m2n2

# import  pyoti.static.onumm2n3 as oti_m2n3
# cimport pyoti.static.onumm2n3 as oti_m2n3

# import  pyoti.static.onumm2n4 as oti_m2n4
# cimport pyoti.static.onumm2n4 as oti_m2n4

# import  pyoti.static.onumm3n1 as oti_m3n1
# cimport pyoti.static.onumm3n1 as oti_m3n1

# import  pyoti.static.onumm3n2 as oti_m3n2
# cimport pyoti.static.onumm3n2 as oti_m3n2

# import  pyoti.static.onumm3n3 as oti_m3n3
# cimport pyoti.static.onumm3n3 as oti_m3n3

# import  pyoti.static.onumm3n4 as oti_m3n4
# cimport pyoti.static.onumm3n4 as oti_m3n4

# Import all c-capabilities from numpy.
import  numpy as np
cimport numpy as np

import  pyoti.sparse as otispr
cimport pyoti.sparse as otispr 

from pyoti.core cimport  get_cython_dHelp, dHelp

cdef dHelp h = get_cython_dHelp()
cdef dhelpl_t dhl = h.dhl