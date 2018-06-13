
#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

cimport numpy as np
from c_otilib cimport *             # OTI lib in C.
from c_otifem cimport *             # OTIFEM lib in C.

#-----------------------------------------------------------------------------------------------------





# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  ndarray   ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class ndarray:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  cdef public uint8_t order          # Stores the maximum order of the vector.
  # cdef public float64_t[:,::1] data   # Array of coefficients of the OTI vector.
  cdef public np.ndarray data
  cdef double* p_data                   # pointer to the data. This will manipulate the data
  cdef public uint16_t m                # Number of basis of the OTI numbers inside.
  cdef public uint64_t size             # Number of oti numbers inside.
  cdef public uint64_t Ndir             # Number of OTI directions in the OTIVEC
  cdef public tuple shape              
  cdef public tuple imshape             # Imaginary shape (taking into account the number of directions)
  #---------------------------------------------------------------------------------------------------  


  cpdef np.ndarray c_getByIndx(self, uint64_t indx)
  cpdef void c_setByIndx(self, uint64_t indx, np.ndarray value)


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class ndarray ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




#-----------------------------------------------------------------------------------------------------
#-------------------------------------   INITIALIZATION ONLY   ---------------------------------------
#-----------------------------------------------------------------------------------------------------

cdef dHelp h
cdef directionHelper* p_dH
cdef uint64_t ZERO 
cdef uint64_t  ONE 

#-----------------------------------------------------------------------------------------------------


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTINUM    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class otinum:
  
  #---------------------------------------------------------------------------------------------------
  #-------------------------------------   ATTRIBUTES   ----------------------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef otinum_t num             # Stores the number in a c-level fashion.
  cdef uint8_t FLAGS

  #---------------------------------------------------------------------------------------------------


  @staticmethod
  cdef otinum create(otinum_t* num, uint8_t FLAGS = *)
  @staticmethod
  cdef double getitem(self, uint64_t index)
  cdef otinum neg(self)
  cpdef otinum selfNeg(self)
  cpdef copy(self)
  cpdef void changeOrder(self,uint8_t neworder)
  cdef double c_getDerivByDirExp( self, uint16_t* p_dirA, uint8_t* p_expA)
  cpdef assignAll(self, float64_t value)
  cpdef one(self)
  cpdef null(self)
  cpdef scale(self,float64_t value)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTINUM :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  otimat   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class otimat:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  cdef public uint8_t order             # Stores the maximum order of the vector.
  cdef public object[:] elements        # Array of matrices for each oti dir.
  cdef public uint16_t m                # Number of basis of the OTI numbers inside.
  cdef public uint64_t[:] shape         # Number of oti numbers inside.
  cdef public uint64_t Ndir             # Number of OTI directions in the otimat
  cdef public uint8_t spr_type          # Number that indicates the type of sparse matrix. 
                                        # 0: csr, 1: coo, 2: lil
  #---------------------------------------------------------------------------------------------------  

  cdef void c_setSumFromSotinum(self, list index, sotinum_t* value)
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class otimat :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::      CLASS HELPER      :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class dHelp:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public uint16_t[::1] __mmax  # Variable to hold the maximum number 
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

cpdef ndarray zeros(shape = * , uint8_t maxorder = * , uint16_t m = *)



cpdef  otinum cos(otinum val)
cpdef  otinum sin(otinum val)
cpdef  otinum tan(otinum val)
cpdef  otinum atan(otinum val)
cpdef  otinum atan2(otinum valx, otinum valy)
cpdef  otinum acos(otinum val)
cpdef  otinum asin(otinum val)
cpdef  otinum sinh(otinum val)
cpdef  otinum asinh(otinum val)
cpdef  otinum cosh(otinum val)
cpdef  otinum acosh(otinum val)
cpdef  otinum tanh(otinum val)
cpdef  otinum atanh(otinum val)
cpdef  otinum logb(otinum val, int base)
cpdef  otinum log10(otinum val)
cpdef  otinum log(otinum val)
cpdef  otinum exp(otinum val)
cpdef  otinum power(otinum val, double exponent)
cpdef  otinum sqrt(otinum val)



# cpdef ndarray solveLU(otimat A, ndarray b, solver = *)
# cpdef ndarray solve(otimat A, ndarray b, solver = *)

#-----------------------------------------------------------------------------------------------------

