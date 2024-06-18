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
      
  cdef public feonumm2n4   xi           # Xi natural coordinate. (integration points)
  cdef public feonumm2n4   eta          # Eta natural coordinate. (integration points)
  cdef public feonumm2n4   zeta         # Zeta natural coordinate. (integration points)

  cdef public feonumm2n4   w            # Integration weights
      
  cdef public feomatm2n4  N             # Real basis.
  cdef public feomatm2n4  Nxi           # dN/d xi    basis.
  cdef public feomatm2n4  Neta          # dN/d eta   basis.
  cdef public feomatm2n4  Nzeta         # dN/d zeta  basis.
      
  cdef public feomatm2n4  Nx            # dN/dx basis.
  cdef public feomatm2n4  Ny            # dN/dy basis.
  cdef public feomatm2n4  Nz            # dN/dz basis.
      
  cdef public omatm2n4    x             # Elemental xcoord basis.
  cdef public omatm2n4    y             # Elemental ycoord basis.
  cdef public omatm2n4    z             # Elemental zcoord basis.
      
  cdef public feomatm2n4    J           # Elemental Jacobian.
  cdef public feonumm2n4  detJ          # Determinant of Jacobian.
  cdef public feonumm2n4  dV            # integration weight dOmega.
  
  cdef public feomatm2n4 Jinv           # Jacobian inverse.      

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