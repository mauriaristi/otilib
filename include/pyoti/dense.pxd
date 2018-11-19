
#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

cimport numpy as np
from c_otilib cimport *             # OTI lib in C.

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



#-----------------------------------------------------------------------------------------------------
#-------------------------------------     OTHER FUNCTIONS     ---------------------------------------
#-----------------------------------------------------------------------------------------------------
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
#-----------------------------------------------------------------------------------------------------























