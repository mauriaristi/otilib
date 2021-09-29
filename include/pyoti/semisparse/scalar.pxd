
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::       CLASS  SCALAR     :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class sotinum:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef semiotin_t num
  cdef uint8_t FLAGS
  #---------------------------------------------------------------------------------------------------  
  
  @staticmethod
  cdef sotinum create(semiotin_t* num, uint8_t FLAGS = *)
  @staticmethod
  cdef sotinum init()

  # cpdef truncate(      self, object humdir)
  # cpdef extract_im(    self, object humdir)
  # cpdef extract_deriv( self, object humdir)
  # cpdef get_im(        self, object humdir)
  # cpdef get_deriv(     self, object humdir)
  # cpdef set(           self, object rhs   )


  cpdef get_deriv(     self, object humdir)
  cpdef get_im(        self, object humdir)
  cpdef extract_im(    self, object humdir)
  cpdef extract_deriv( self, object humdir)
  cpdef truncate(      self, object humdir)
  cpdef get_order_im(  self, ord_t order  )
  cpdef set(           self, object rhs   )
  cpdef set_im(    self,  object val, object humdir)
  cpdef set_deriv( self,  object val, object humdir)
  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS SCALAR :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


# cpdef sotinum sotinum_cos(sotinum val)
# cpdef sotinum sotinum_sin(sotinum val)
# cpdef sotinum sotinum_tan(sotinum val)
# cpdef sotinum sotinum_arctan(sotinum val)
# cpdef sotinum sotinum_arccos(sotinum val)
# cpdef sotinum sotinum_arcsin(sotinum val)
# cpdef sotinum sotinum_sinh(sotinum val)
# cpdef sotinum sotinum_arcsinh(sotinum val)
# cpdef sotinum sotinum_cosh(sotinum val)
# cpdef sotinum sotinum_arccosh(sotinum val)
# cpdef sotinum sotinum_tanh(sotinum val)
# cpdef sotinum sotinum_arctanh(sotinum val)
# cpdef sotinum sotinum_logb(sotinum val, double base)
# cpdef sotinum sotinum_log10(sotinum val)
# cpdef sotinum sotinum_log(sotinum val)
# cpdef sotinum sotinum_exp(sotinum val)
# cpdef sotinum sotinum_power(sotinum val, double exponent)
# cpdef sotinum sotinum_sqrt(sotinum val)
# cpdef sotinum semiotin_cbrt(sotinum val)