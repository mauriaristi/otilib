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
      
  cdef public feonumm4n5   xi           # Xi natural coordinate. (integration points)
  cdef public feonumm4n5   eta          # Eta natural coordinate. (integration points)
  cdef public feonumm4n5   zeta         # Zeta natural coordinate. (integration points)

  cdef public feonumm4n5   w            # Integration weights
      
  cdef public feomatm4n5  N             # Real basis.
  cdef public feomatm4n5  Nxi           # dN/d xi    basis.
  cdef public feomatm4n5  Neta          # dN/d eta   basis.
  cdef public feomatm4n5  Nzeta         # dN/d zeta  basis.
      
  cdef public feomatm4n5  Nx            # dN/dx basis.
  cdef public feomatm4n5  Ny            # dN/dy basis.
  cdef public feomatm4n5  Nz            # dN/dz basis.
      
  cdef public omatm4n5    x             # Elemental xcoord basis.
  cdef public omatm4n5    y             # Elemental ycoord basis.
  cdef public omatm4n5    z             # Elemental zcoord basis.
      
  cdef public feomatm4n5    J           # Elemental Jacobian.
  cdef public feonumm4n5  detJ          # Determinant of Jacobian.
  cdef public feonumm4n5  dV            # integration weight dOmega.
  
  cdef public feomatm4n5 Jinv           # Jacobian inverse.      

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