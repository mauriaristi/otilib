

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  MATSOFE   ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class mdmatfe4:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef femdarr4_t arr
  cdef uint8_t FLAGS
  #---------------------------------------------------------------------------------------------------  
  
  @staticmethod
  cdef mdmatfe4 create(femdarr4_t* num, uint8_t FLAGS = *)

  cpdef truncate(      self, object humdir)
  
  cpdef extract_im(    self, object humdir)
  cpdef extract_deriv( self, object humdir)

  cpdef get_im(        self, object humdir)
  cpdef get_deriv(     self, object humdir)

  cpdef get_order_im(  self, ord_t order  )
  
  cpdef get_ip(        self, int64_t ip   )
  cpdef get_item_ij(   self, int64_t i, int64_t j, mdnumfe4 out=*)

  cpdef set(           self, object rhs   )

  cdef __setitem__r(self, object val, coeff_t value)
  # cdef __setitem__R(self, object val, dmat    value)
  cdef __setitem__o(self, object val, mdnum4 value)
  cdef __setitem__O(self, object val, mdmat4   value)
  cdef __setitem__f(self, object val, mdnumfe4  value)
  cdef __setitem__F(self, object val, mdmatfe4 value)
  # cpdef set_ip(        self, int64_t ip   )
  
  

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: END OF CLASS MATSOFE ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::