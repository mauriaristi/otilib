
#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

cimport numpy as np
from c_otilib cimport *             # OTI lib in C.

#-----------------------------------------------------------------------------------------------------



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTINUM    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class dmat:
  
  #---------------------------------------------------------------------------------------------------
  #-------------------------------------   ATTRIBUTES   ----------------------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef darr_t  arr            # Stores the matrix in a c-level fashion.
  cdef uint8_t FLAGS

  #---------------------------------------------------------------------------------------------------


  @staticmethod
  cdef dmat create(darr_t* num, uint8_t FLAGS = *)
  cpdef copy(self)
  cpdef np.ndarray[double, ndim=2] to_numpy(self)
  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTINUM :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





cpdef dmat dot(dmat A, dmat B)
cpdef dmat invert(dmat A)
cpdef dmat transpose(dmat A)
cpdef coeff_t det(dmat A)
cpdef dmat eye(uint64_t size)
cpdef dmat zeros(uint64_t nrows,uint64_t ncols)
cpdef dmat ones(uint64_t nrows,uint64_t ncols)
cpdef dmat atanh(dmat A)
cpdef dmat asinh(dmat A)
cpdef dmat acosh(dmat A)
cpdef dmat tanh(dmat A)
cpdef dmat sqrt(dmat A)
cpdef dmat cosh(dmat A)
cpdef dmat sinh(dmat A)
cpdef dmat asin(dmat A)
cpdef dmat acos(dmat A)
cpdef dmat atan(dmat A)
cpdef dmat tan(dmat A)
cpdef dmat cos(dmat A)
cpdef dmat sin(dmat A)
cpdef dmat log10(dmat A)
cpdef dmat log(dmat A)
cpdef dmat exp(dmat A)
cpdef dmat logb(dmat A,coeff_t b)
cpdef dmat power(dmat A,coeff_t b)





cdef np.ndarray darr_2_npy(darr_t* array )