
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::     CLASS  elBase    ::::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# cdef class elBase:
  
#   #---------------------------------------------------------------------------------------------------
#   #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
#   #---------------------------------------------------------------------------------------------------

#   cdef uint8_t FLAG           # Defines if the elemen is defined in python or c.
#   cdef public uint8_t elorder # Element type order.
#   cdef elem_t elem            # C-level memory structure of element class.
#   cdef public list boundEls   # List of boundary element types.
#   cdef object pyFunct

#   #---------------------------------------------------------------------------------------------------

  
#   @staticmethod
#   # cdef elBase createNewElement(uint64_t nbasis, int64_t geomBase, int64_t  kind,   uint8_t  ndim, \
#   #             int64_t (*basis_f)(int64_t,int64_t,darr_t*,void*,darr_t*) nogil, list boundEls )
#   cdef elBase createNewElement(uint64_t nbasis, uint8_t order, int64_t geomBase, int64_t  kind,   \
#     uint8_t  ndim, object basis, list boundEls )
  
#   cdef is_allocated(self)
#   cdef is_initialized(self)

#   cpdef allocate(self, uint64_t intorder)
#   cpdef end(self)

#   # cpdef initElement(self, uint64_t order, uint8_t otiorder, uint8_t nDimAnalysis)
#   # cpdef uninitElement(self)
#   # cdef sndarray Ke(self,sndarray coords, np.ndarray connect, other)
#   # cdef sndarray fe(self,sndarray coords, np.ndarray connect, other)


# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::::::::: END OF CLASS elBase :::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::






# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  elBaseso    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elbaseso:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef uint8_t FLAG           # Defines if the elemen is defined in python or c.
  cdef public uint8_t elorder # Element type order.
  cdef elemso_t     elem      # C-level memory structure of element class.
  cdef elemso_spt_t elem_spt  # C-level memory structure of spatial element components.
  cdef public list boundEls   # List of boundary element types.
  cdef public object basis    # Function that calculates the basis functions of the element.
  cdef public object N        # List of evaluated basis.

  #---------------------------------------------------------------------------------------------------
  
  cdef is_allocated(self)
  cdef is_initialized(self)

  cpdef allocate(self, uint64_t intorder, bases_t nbases = * , ord_t order = * )
  cpdef end(self)

  # cpdef initElement(self, uint64_t order, uint8_t otiorder, uint8_t nDimAnalysis)
  # cpdef uninitElement(self)
  # cdef sndarray Ke(self,sndarray coords, np.ndarray connect, other)
  # cdef sndarray fe(self,sndarray coords, np.ndarray connect, other)


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elBaseso :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

