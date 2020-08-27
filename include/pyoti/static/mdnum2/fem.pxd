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
      
  cdef public mdnumfe2   xi           # Xi natural coordinate. (integration points)
  cdef public mdnumfe2   eta          # Eta natural coordinate. (integration points)
  cdef public mdnumfe2   zeta         # Zeta natural coordinate. (integration points)

  cdef public mdnumfe2   w            # Integration weights
      
  cdef public mdmatfe2  N             # Real basis.
  cdef public mdmatfe2  Nxi           # dN/d xi    basis.
  cdef public mdmatfe2  Neta          # dN/d eta   basis.
  cdef public mdmatfe2  Nzeta         # dN/d zeta  basis.
      
  cdef public mdmatfe2  Nx            # dN/dx basis.
  cdef public mdmatfe2  Ny            # dN/dy basis.
  cdef public mdmatfe2  Nz            # dN/dz basis.
      
  cdef public mdmat2    x             # Elemental xcoord basis.
  cdef public mdmat2    y             # Elemental ycoord basis.
  cdef public mdmat2    z             # Elemental zcoord basis.
      
  cdef public mdmatfe2    J           # Elemental Jacobian.
  cdef public mdnumfe2  detJ          # Determinant of Jacobian.
  cdef public mdnumfe2  dV            # integration weight dOmega.
  
  cdef public mdmatfe2 Jinv           # Jacobian inverse.      

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