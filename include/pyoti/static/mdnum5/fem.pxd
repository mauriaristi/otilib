# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  elm_help    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elm_help:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public object   special      # Marker to determine special behavior of the system.

  cdef public uint8_t  ndim         # Number of dimensions of the element.
  cdef public uint8_t  nbasis       # Element type order.
  cdef public uint64_t ndim_an      # Number of dimensions of the analysis.
  cdef public uint64_t nip          # Number of integration points
      
  cdef public mdnumfe5   xi           # Xi natural coordinate. (integration points)
  cdef public mdnumfe5   eta          # Eta natural coordinate. (integration points)
  cdef public mdnumfe5   zeta         # Zeta natural coordinate. (integration points)

  cdef public mdnumfe5   w            # Integration weights
      
  cdef public mdmatfe5  N             # Real basis.
  cdef public mdmatfe5  Nxi           # dN/d xi    basis.
  cdef public mdmatfe5  Neta          # dN/d eta   basis.
  cdef public mdmatfe5  Nzeta         # dN/d zeta  basis.
      
  cdef public mdmatfe5  Nx            # dN/dx basis.
  cdef public mdmatfe5  Ny            # dN/dy basis.
  cdef public mdmatfe5  Nz            # dN/dz basis.
      
  cdef public mdmat5    x             # Elemental xcoord basis.
  cdef public mdmat5    y             # Elemental ycoord basis.
  cdef public mdmat5    z             # Elemental zcoord basis.
      
  cdef public mdmatfe5    J           # Elemental Jacobian.
  cdef public mdnumfe5  detJ          # Determinant of Jacobian.
  cdef public mdnumfe5  dV            # integration weight dOmega.
  
  cdef public mdmatfe5 Jinv           # Jacobian inverse.      

  cdef public uint8_t compute_Jinv  # Flag to compute Jacobian

  
  #---------------------------------------------------------------------------------------------------
  
  cpdef is_allocated( self )
  cpdef allocate(self, uint8_t ndim, uint64_t nbasis, uint64_t nip )
  cpdef allocate_spatial( self, uint64_t ndim_an, uint8_t compute_Jinv = * )
  cpdef reset( self )
  cpdef end( self )

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elm_help :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::