
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  elBase    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elBase:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef uint8_t FLAG # Defines if the elemen is defined in python or c.
  cdef public uint8_t elorder # Element type order
  cdef elem_t elem  # Properties of the element.
  cdef public list boundEls
  cdef object pyFunct

  #---------------------------------------------------------------------------------------------------

  
  @staticmethod
  cdef elBase createNewElement(uint64_t nbasis, int64_t geomBase, int64_t  kind,   uint8_t  ndim, \
              int64_t (*basis_f)(int64_t,int64_t,darr_t*,void*,darr_t*) nogil, list boundEls )

  cpdef allocate(self, uint64_t intorder)
  cpdef end(self)

  # cpdef initElement(self, uint64_t order, uint8_t otiorder, uint8_t nDimAnalysis)
  # cpdef uninitElement(self)
  # cdef sndarray Ke(self,sndarray coords, np.ndarray connect, other)
  # cdef sndarray fe(self,sndarray coords, np.ndarray connect, other)


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elBase :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

