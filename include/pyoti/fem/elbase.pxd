
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  ELBASE      ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elbase:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef        uint8_t  FLAGS        # Defines if the elemen is defined in python or c.
  cdef        elemd_t  elem         # C-level memory structure of element class.

  cdef public uint8_t  elorder      # Element type order.
  cdef public np.ndarray  elem_indices # Element global indices.
  cdef public list     boundEls     # List of boundary element types.
  cdef public list     faceIndx     # Face inidices of the element. Only for the next dimension down.
  cdef public object   basis        # Function that calculates the basis functions of the element.
  cdef public object   elh          # Element helper object. It must come defined in the algebra.

  
  #---------------------------------------------------------------------------------------------------
  
  cpdef is_allocated(   self )
  cpdef is_initialized( self )
  cpdef end( self )
  cpdef allocate_spatial( self, uint64_t ndim_an, uint8_t compute_Jinv = * )
  cpdef get_boundary_elem(self, uint64_t dim, uint64_t idx )
  cpdef reset( self )
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS ELBASE   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::






# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::     CLASS  elBaseso    ::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# cdef class elbaseso:
  
#   #---------------------------------------------------------------------------------------------------
#   #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
#   #---------------------------------------------------------------------------------------------------

#   cdef        uint8_t  FLAGS        # Defines if the elemen is defined in python or c.
#   cdef        elemso_t elem         # C-level memory structure of element class.

#   cdef public uint8_t  elorder      # Element type order.
#   cdef public ord_t    otiorder     # OTI order
#   cdef public bases_t  otinbases    # OTI order
#   cdef public uint64_t ndim_an      # Number of dimensions of the analysis
#   cdef public list     boundEls     # List of boundary element types.
#   cdef public object   basis        # Function that calculates the basis functions of the element.
      
#   cdef public sotife   xi           # Xi natural coordinate. (integration points)
#   cdef public sotife   eta          # Eta natural coordinate. (integration points)
#   cdef public sotife   zeta         # Zeta natural coordinate. (integration points)

#   cdef public sotife   w            # Integration weights
      
#   cdef public matsofe  N            # Real basis.
#   cdef public matsofe  Nxi          # dN/d xi    basis.
#   cdef public matsofe  Neta         # dN/d eta   basis.
#   cdef public matsofe  Nzeta        # dN/d zeta  basis.
      
#   cdef public matsofe  Nx           # dN/dx basis.
#   cdef public matsofe  Ny           # dN/dy basis.
#   cdef public matsofe  Nz           # dN/dz basis.
      
#   cdef public matso    x            # Elemental xcoord basis.
#   cdef public matso    y            # Elemental xcoord basis.
#   cdef public matso    z            # Elemental xcoord basis.
      
#   cdef public matsofe    J          # Elemental Jacobian.
#   cdef public sotife  detJ          # Determinant of Jacobian.
#   cdef public sotife  w_dJ          # integration weight dOmega.
  
#   cdef public matsofe    Jinv       # Jacobian inverse.
      

#   cdef public uint8_t compute_Jinv

  
#   #---------------------------------------------------------------------------------------------------
  
#   cpdef is_allocated(   self )
#   cpdef is_initialized( self )

#   cpdef allocate( self, uint64_t intorder, bases_t nbases = * , ord_t order = * )
#   cpdef end( self )

#   cpdef allocate_spatial( self, uint64_t ndim_an, uint8_t compute_Jinv = * )
#   cpdef reset( self )
#   # cpdef uninitElement(self)
#   # cdef sndarray Ke(self,sndarray coords, np.ndarray connect, other)
#   # cdef sndarray fe(self,sndarray coords, np.ndarray connect, other)


# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::::::::: END OF CLASS elBaseso :::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::     CLASS  elBased     ::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# cdef class elbased:
  
#   #---------------------------------------------------------------------------------------------------
#   #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
#   #---------------------------------------------------------------------------------------------------

#   cdef        uint8_t  FLAGS        # Defines if the elemen is defined in python or c.
#   cdef        elemd_t  elem         # C-level memory structure of element class.

#   cdef public uint8_t  elorder      # Element type order.
#   cdef public uint64_t ndim_an      # Number of dimensions of the analysis
#   cdef public list     boundEls     # List of boundary element types.
#   cdef public object   basis        # Function that calculates the basis functions of the element.
      
#   cdef public r.dnumfe   xi         # Xi natural coordinate. (integration points)
#   cdef public r.dnumfe   eta        # Eta natural coordinate. (integration points)
#   cdef public r.dnumfe   zeta       # Zeta natural coordinate. (integration points)

#   cdef public r.dnumfe   w          # Integration weights
      
#   cdef public r.dmatfe   N          # Real basis.
#   cdef public r.dmatfe   Nxi        # dN/d xi    basis.
#   cdef public r.dmatfe   Neta       # dN/d eta   basis.
#   cdef public r.dmatfe   Nzeta      # dN/d zeta  basis.
      
#   cdef public r.dmatfe   Nx         # dN/dx basis.
#   cdef public r.dmatfe   Ny         # dN/dy basis.
#   cdef public r.dmatfe   Nz         # dN/dz basis.
      
#   cdef public r.dmat     x          # Elemental xcoord basis.
#   cdef public r.dmat     y          # Elemental xcoord basis.
#   cdef public r.dmat     z          # Elemental xcoord basis.
      
#   cdef public r.dmatfe     J        # Elemental Jacobian.
#   cdef public r.dnumfe  detJ        # Determinant of Jacobian.
#   cdef public r.dnumfe  w_dJ        # integration weight dOmega.
  
#   cdef public r.dmatfe     Jinv     # Jacobian inverse.
      

#   cdef public uint8_t compute_Jinv

  
#   #---------------------------------------------------------------------------------------------------
  
#   cpdef is_allocated(   self )
#   cpdef is_initialized( self )

#   cpdef allocate( self, uint64_t intorder )
#   cpdef end( self )

#   cpdef allocate_spatial( self, uint64_t ndim_an, uint8_t compute_Jinv = * )
#   cpdef reset( self )
#   # cpdef uninitElement(self)
#   # cdef sndarray Ke(self,sndarray coords, np.ndarray connect, other)
#   # cdef sndarray fe(self,sndarray coords, np.ndarray connect, other)


# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::::::::: END OF CLASS elBased  :::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

