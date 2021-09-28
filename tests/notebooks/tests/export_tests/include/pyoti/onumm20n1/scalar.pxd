
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  SPR_OTINUM   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class onumm20n1_t:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef onumm20n1_t num
  cdef uint8_t FLAGS
  #---------------------------------------------------------------------------------------------------  
  
  @staticmethod
  cdef onumm20n1_t create(onumm20n1_t* num, uint8_t FLAGS = *)
  @staticmethod
  cdef onumm20n1_t init()

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
# :::::::::::::::::::::::::::::::::: END OF CLASS SPR_OTINUM :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
