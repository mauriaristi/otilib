

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  MATSO   ::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class omatm3n2: 
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef oarrm3n2_t arr
  cdef uint8_t FLAGS
  #---------------------------------------------------------------------------------------------------  

  @staticmethod
  cdef omatm3n2 create(oarrm3n2_t* num, uint8_t FLAGS = *)
  
  cpdef truncate(      self, object humdir)
  cpdef extract_im(    self, object humdir)
  cpdef extract_deriv( self, object humdir)
  cpdef get_im(        self, object humdir)
  cpdef get_deriv(     self, object humdir)
  cpdef set(           self, object rhs   )
  cpdef get_order_im(  self, ord_t order  )

  cdef __setitem__r(self, object val, coeff_t value)
  cdef __setitem__R(self, object val, dmat    value)
  cdef __setitem__o(self, object val, onumm3n2 value)
  cdef __setitem__O(self, object val, omatm3n2   value)
    
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: END OF CLASS MATSO ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

