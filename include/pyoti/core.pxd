
#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

cimport numpy as np
from c_otilib cimport *             # OTI lib in C.

#-----------------------------------------------------------------------------------------------------


#-----------------------------------------------------------------------------------------------------
#-------------------------------------   INITIALIZATION ONLY   ---------------------------------------
#-----------------------------------------------------------------------------------------------------

cdef dHelp h
cdef directionHelper* p_dH 
cdef uint64_t ZERO 
cdef uint64_t  ONE 

#-----------------------------------------------------------------------------------------------------



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::      CLASS HELPER      :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class dHelp:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public np.ndarray __mmax  # Variable to hold the maximum number 
                                    # of base directions to load.
  cdef directionHelper* p_dH        # pointer to all helpers.
  cdef public uint8_t merror        # value to hold multiplication errors
  cdef public uint8_t nhelps        # number of helpers.
  cdef uint8_t nn                   # number of user arrays.

  #---------------------------------------------------------------------------------------------------  

  #---------------------------------------------------------------------------------------------------
  #------------------------------   DEFINITION OF C-LEVEL FUNCTIONS   --------------------------------
  #---------------------------------------------------------------------------------------------------
  cdef  uint64_t  c_findIndx(self, uint16_t* dirA,  uint8_t* expA, uint8_t order)
  cpdef uint64_t  multIndx(self, uint64_t indx1, uint64_t indx2, uint8_t order)
  cpdef uint64_t  multIndxFast(self, uint64_t indx1, uint64_t indx2, uint8_t order)
  cdef  uint8_t*  c_getExpA(self, uint64_t indx, uint8_t order)
  cdef  uint8_t*  c_getUExpA(self, uint8_t order, uint8_t n = *)
  cdef  uint16_t* c_getUDirA(self, uint8_t order, uint8_t n = *)
  cdef  uint16_t* c_getDirA(self, uint64_t indx, uint8_t order)
  cpdef uint64_t  findMaxDir(self, uint64_t index, uint8_t order)
  cpdef uint64_t  getNels(self, uint64_t m, uint8_t order)
  cpdef uint64_t  getNParts(self, uint8_t order) 
  cpdef uint16_t  getSet(self, uint8_t order,uint64_t i,uint64_t j)

  #---------------------------------------------------------------------------------------------------
  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::   END OF CLASS HELPER   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


#-----------------------------------------------------------------------------------------------------
#-------------------------------------     OTHER FUNCTIONS     ---------------------------------------
#-----------------------------------------------------------------------------------------------------



cdef np.ndarray[double, ndim=3]  c_ptr_to_np_3darray_double(void * ptr, np.npy_intp sizex, \
                                                            np.npy_intp sizey, np.npy_intp sizez, \
                                                            uint8_t numpy_own = *)
cdef np.ndarray[double, ndim=2]  c_ptr_to_np_2darray_double(void * ptr, np.npy_intp sizex, \
                                                            np.npy_intp sizey, uint8_t numpy_own = *)
cdef np.ndarray[double, ndim=1]  c_ptr_to_np_1darray_double(void * ptr, np.npy_intp size, \
                                                            uint8_t numpy_own = *)
cdef np.ndarray[uint64_t, ndim=1]  c_ptr_to_np_1darray_uint64(void * ptr, np.npy_intp size, \
                                                            uint8_t numpy_own = *)
cdef void c_getDirExpA(list dirArray, uint16_t** p_dirA, uint8_t** p_expA, uint8_t* order)

cdef void c_Py_print2DArrayUI8(uint8_t* array,uint64_t dim1, uint8_t dim2)
cdef void c_Py_printArrayUI8(uint8_t* array,uint8_t size)
cdef void c_Py_printArrayUI16(uint16_t* array,uint8_t size)
cdef void c_Py_printArrayUI64(uint64_t* array,uint64_t size)
cdef dHelp get_cython_dHelp()
#-----------------------------------------------------------------------------------------------------

