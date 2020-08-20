

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  MATSOFE   ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class feoarrm3n2_t:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef feoarrm3n2_t arr
  cdef uint8_t FLAGS
  #---------------------------------------------------------------------------------------------------  
  
  @staticmethod
  cdef feoarrm3n2_t create(feoarrm3n2_t* num, uint8_t FLAGS = *)

  cpdef truncate(      self, object humdir)
  
  cpdef extract_im(    self, object humdir)
  cpdef extract_deriv( self, object humdir)

  cpdef get_im(        self, object humdir)
  cpdef get_deriv(     self, object humdir)

  cpdef get_order_im(  self, ord_t order  )
  
  cpdef get_ip(        self, int64_t ip   )
  cpdef get_item_ij(   self, int64_t i, int64_t j, feonumm3n2_t out=*)

  cpdef set(           self, object rhs   )

  cdef __setitem__r(self, object val, coeff_t value)
  # cdef __setitem__R(self, object val, dmat    value)
  cdef __setitem__o(self, object val, onumm3n2_t value)
  cdef __setitem__O(self, object val, oarrm3n2_t   value)
  cdef __setitem__f(self, object val, feonumm3n2_t  value)
  cdef __setitem__F(self, object val, feoarrm3n2_t value)
  # cpdef set_ip(        self, int64_t ip   )
  
  

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: END OF CLASS MATSOFE ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::