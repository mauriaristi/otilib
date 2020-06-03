

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  MATSO   ::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class matso: 
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef arrso_t arr
  cdef uint8_t FLAGS
  #---------------------------------------------------------------------------------------------------  

  @staticmethod
  cdef matso create(arrso_t* num, uint8_t FLAGS = *)
  
  cpdef truncate(      self, object humdir)
  cpdef extract_im(    self, object humdir)
  cpdef extract_deriv( self, object humdir)
  cpdef get_im(        self, object humdir)
  cpdef get_deriv(     self, object humdir)
  cpdef set(           self, object rhs   )
  cpdef get_order_im(     self, ord_t order  )
  
  # @staticmethod
  # cpdef matso inv( matso arr, matso out = *)

  # @staticmethod
  # cpdef sotinum det( matso arr, sotinum out = *)
  
  # @staticmethod
  # cpdef sotinum norm(matso arr, sotinum out = *)

  # # Math functions
  # @staticmethod
  # cpdef matso sin(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso cos(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso tan(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso arcsin(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso arccos(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso arctan(matso arr, matso out = *)




  # @staticmethod
  # cpdef matso sinh(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso cosh(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso tanh(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso arcsinh(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso arccosh(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso arctanh(matso arr, matso out = *)



  # @staticmethod
  # cpdef matso log(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso logb(matso arr, coeff_t base,  matso out = *)

  # @staticmethod
  # cpdef matso log10(matso arr, matso out = *)

  # @staticmethod
  # cpdef matso power(matso arr, coeff_t exp, matso out = *)

  # @staticmethod
  # cpdef matso exp(matso arr, matso out = *)

  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: END OF CLASS MATSO ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



