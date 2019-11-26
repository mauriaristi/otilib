
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
  cpdef coeff_t get_deriv( self, object humdir)
  cpdef sin(self)
  cpdef cos(self)
  cpdef tan(self)
  cpdef arctan(self)
  cpdef arccos(self)
  cpdef arcsin(self)
  cpdef sinh(self)
  cpdef arcsinh(self)
  cpdef cosh(self)
  cpdef arccosh(self)
  cpdef tanh(self)
  cpdef arctanh(self)
  cpdef log10(self)
  cpdef log(self)
  cpdef exp(self)
  cpdef sqrt(self)
  cpdef cbrt(self)
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: End of class spr_otinum :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



# #*****************************************************************************************************
cpdef sotinum cos(sotinum val)
cpdef sotinum sin(sotinum val)
cpdef sotinum tan(sotinum val)
cpdef sotinum arctan(sotinum val)
# cpdef sotinum atan2(sotinum valx, sotinum valy)
cpdef sotinum arccos(sotinum val)
cpdef sotinum arcsin(sotinum val)
cpdef sotinum sinh(sotinum val)
cpdef sotinum arcsinh(sotinum val)
cpdef sotinum cosh(sotinum val)
cpdef sotinum arccosh(sotinum val)
cpdef sotinum tanh(sotinum val)
cpdef sotinum arctanh(sotinum val)
cpdef sotinum logb(sotinum val, double base)
cpdef sotinum log10(sotinum val)
cpdef sotinum log(sotinum val)
cpdef sotinum exp(sotinum val)
cpdef sotinum power(sotinum val, double exponent)
cpdef sotinum sqrt(sotinum val)
cpdef sotinum cbrt(sotinum val)
# #*****************************************************************************************************






