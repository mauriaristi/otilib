
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
  @staticmethod
  cdef sotinum init()

  cpdef coeff_t get_deriv( self, object humdir)
  cpdef coeff_t get_im( self, object humdir)
  cpdef sotinum extract_im( self, object humdir)
  cpdef sotinum extract_deriv( self, object humdir)
  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: END OF CLASS SPR_OTINUM :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


cpdef sotinum sotinum_cos(sotinum val)
cpdef sotinum sotinum_sin(sotinum val)
cpdef sotinum sotinum_tan(sotinum val)
cpdef sotinum sotinum_arctan(sotinum val)
cpdef sotinum sotinum_arccos(sotinum val)
cpdef sotinum sotinum_arcsin(sotinum val)
cpdef sotinum sotinum_sinh(sotinum val)
cpdef sotinum sotinum_arcsinh(sotinum val)
cpdef sotinum sotinum_cosh(sotinum val)
cpdef sotinum sotinum_arccosh(sotinum val)
cpdef sotinum sotinum_tanh(sotinum val)
cpdef sotinum sotinum_arctanh(sotinum val)
cpdef sotinum sotinum_logb(sotinum val, double base)
cpdef sotinum sotinum_log10(sotinum val)
cpdef sotinum sotinum_log(sotinum val)
cpdef sotinum sotinum_exp(sotinum val)
cpdef sotinum sotinum_power(sotinum val, double exponent)
cpdef sotinum sotinum_sqrt(sotinum val)
cpdef sotinum sotinum_cbrt(sotinum val)