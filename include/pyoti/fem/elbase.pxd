
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

  cdef        uint8_t  FLAGS        # Defines if the elemen is defined in python or c.
  cdef        elemso_t elem         # C-level memory structure of element class.

  cdef public uint8_t  elorder      # Element type order.
  cdef public ord_t    otiorder     # OTI order
  cdef public bases_t  otinbases    # OTI order
  cdef public uint64_t ndim_an      # Number of dimensions of the analysis
  cdef public list     boundEls     # List of boundary element types.
  cdef public object   basis        # Function that calculates the basis functions of the element.
      
  cdef public sotife   xi           # Xi natural coordinate. (integration points)
  cdef public sotife   eta          # Eta natural coordinate. (integration points)
  cdef public sotife   zeta         # Zeta natural coordinate. (integration points)

  cdef public sotife   w            # Integration weights
      
  cdef public matsofe  N            # Real basis.
  cdef public matsofe  Nxi          # dN/d xi    basis.
  cdef public matsofe  Neta         # dN/d eta   basis.
  cdef public matsofe  Nzeta        # dN/d zeta  basis.
      
  cdef public matsofe  Nx           # dN/dx basis.
  cdef public matsofe  Ny           # dN/dy basis.
  cdef public matsofe  Nz           # dN/dz basis.
      
  cdef public matso    x            # Elemental xcoord basis.
  cdef public matso    y            # Elemental xcoord basis.
  cdef public matso    z            # Elemental xcoord basis.
      
  cdef public matsofe    J          # Elemental Jacobian.
  cdef public sotife  detJ          # Determinant of Jacobian.
  cdef public matsofe    Jinv       # Jacobian inverse.
      
  cdef public sotife  w_dJ          # integration weight dOmega.

  cdef public uint8_t compute_Jinv

  
  #---------------------------------------------------------------------------------------------------
  
  cpdef is_allocated(   self )
  cpdef is_initialized( self )

  cpdef allocate( self, uint64_t intorder, bases_t nbases = * , ord_t order = * )
  cpdef end( self )

  cpdef allocate_spatial( self, uint64_t ndim_an, uint8_t compute_Jinv = * )
  cpdef reset( self )
  # cpdef uninitElement(self)
  # cdef sndarray Ke(self,sndarray coords, np.ndarray connect, other)
  # cdef sndarray fe(self,sndarray coords, np.ndarray connect, other)


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elBaseso :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

