
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTINUM    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class otinum:
  
  #---------------------------------------------------------------------------------------------------
  #-------------------------------------   ATTRIBUTES   ----------------------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef otinum_t num             # Stores the number in a c-level fashion.
  cdef uint8_t FLAGS

  #---------------------------------------------------------------------------------------------------


  @staticmethod
  cdef otinum create(otinum_t* num, uint8_t FLAGS = *)
  cpdef copy(self)
  cpdef coeff_t get_deriv( self, hum_dir)

  # @staticmethod
  # def otinum add(otinum lhs, otinum rhs, otinum out = *)
  
  # @staticmethod
  # def otinum add_to(otinum lhs, otinum rhs, otinum out)
  # @staticmethod
  # cdef double getitem(self, uint64_t index)
  # cdef otinum neg(self)
  # cpdef otinum selfNeg(self)
  # cpdef void changeOrder(self,uint8_t neworder)
  # cdef double c_getDerivByDirExp( self, uint16_t* p_dirA, uint8_t* p_expA)
  # cpdef assignAll(self, float64_t value)
  # cpdef one(self)
  # cpdef null(self)
  # cpdef scale(self,float64_t value)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTINUM :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::