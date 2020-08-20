

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  MATSOFE   ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class feoarrm20n1_t:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef feoarrm20n1_t arr
  cdef uint8_t FLAGS
  #---------------------------------------------------------------------------------------------------  
  
  @staticmethod
  cdef feoarrm20n1_t create(feoarrm20n1_t* num, uint8_t FLAGS = *)

  cpdef truncate(      self, object humdir)
  
  cpdef extract_im(    self, object humdir)
  cpdef extract_deriv( self, object humdir)

  cpdef get_im(        self, object humdir)
  cpdef get_deriv(     self, object humdir)

  cpdef get_order_im(  self, ord_t order  )
  
  cpdef get_ip(        self, int64_t ip   )
  cpdef get_item_ij(   self, int64_t i, int64_t j, feonumm20n1_t out=*)

  cpdef set(           self, object rhs   )

  cdef __setitem__r(self, object val, coeff_t value)
  # cdef __setitem__R(self, object val, dmat    value)
  cdef __setitem__o(self, object val, onumm20n1_t value)
  cdef __setitem__O(self, object val, oarrm20n1_t   value)
  cdef __setitem__f(self, object val, feonumm20n1_t  value)
  cdef __setitem__F(self, object val, feoarrm20n1_t value)
  # cpdef set_ip(        self, int64_t ip   )
  
  

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: END OF CLASS MATSOFE ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::