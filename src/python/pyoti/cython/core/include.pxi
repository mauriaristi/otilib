

#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

import numpy as np                        # General numerical library
cimport numpy as np                       # C-level functions of numpy 
from libc.stdlib cimport malloc,free      # import memory managment functions.
from libc.stdlib cimport realloc          #    "              "
from libc.string cimport memcpy           # fast memory block copy.
from libc.string cimport memset           # fast memory instantiation.
from warnings import warn                 # Warnings
# from math import factorial                # Compute factorials
import scipy.sparse as spr                # Manipulator of sparse matrices
from scipy.special import comb            # Classic combinatorials
# from partitionsets import partition       # Compute partitions of sets
import pyoti.whereotilib as whereotilib   # A pure python script to get 
                                          #the current path of this folder.

from c_otilib cimport *                   # OTI lib in C.

cimport cython                            #
from cpython cimport PyObject             # 
from cpython cimport Py_INCREF            #

#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

cdef extern from "numpy/arrayobject.h":
      void PyArray_ENABLEFLAGS(np.ndarray arr, int flags)

np.import_array()


