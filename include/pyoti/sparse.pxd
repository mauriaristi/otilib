
from c_otilib cimport *


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  SPR_OTINUM   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class sotinum:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef sotinum_t num
  cdef uint8_t FLAGS
  #---------------------------------------------------------------------------------------------------  
  
  @staticmethod
  cdef sotinum create(sotinum_t* num, uint8_t FLAGS = *)
  cpdef coeff_t get_deriv( self, list item)
 
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: End of class spr_otinum :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



#*****************************************************************************************************
cpdef sotinum cos(sotinum val)
cpdef sotinum sin(sotinum val)
cpdef sotinum tan(sotinum val)
cpdef sotinum atan(sotinum val)
# cpdef sotinum atan2(sotinum valx, sotinum valy)
cpdef sotinum acos(sotinum val)
cpdef sotinum asin(sotinum val)
cpdef sotinum sinh(sotinum val)
cpdef sotinum asinh(sotinum val)
cpdef sotinum cosh(sotinum val)
cpdef sotinum acosh(sotinum val)
cpdef sotinum tanh(sotinum val)
cpdef sotinum atanh(sotinum val)
cpdef sotinum logb(sotinum val, double base)
cpdef sotinum log10(sotinum val)
cpdef sotinum log(sotinum val)
cpdef sotinum exp(sotinum val)
cpdef sotinum power(sotinum val, double exponent)
cpdef sotinum sqrt(sotinum val)
#*****************************************************************************************************






