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
      
  cdef public feonumm1n30   xi           # Xi natural coordinate. (integration points)
  cdef public feonumm1n30   eta          # Eta natural coordinate. (integration points)
  cdef public feonumm1n30   zeta         # Zeta natural coordinate. (integration points)

  cdef public feonumm1n30   w            # Integration weights
      
  cdef public feomatm1n30  N             # Real basis.
  cdef public feomatm1n30  Nxi           # dN/d xi    basis.
  cdef public feomatm1n30  Neta          # dN/d eta   basis.
  cdef public feomatm1n30  Nzeta         # dN/d zeta  basis.
      
  cdef public feomatm1n30  Nx            # dN/dx basis.
  cdef public feomatm1n30  Ny            # dN/dy basis.
  cdef public feomatm1n30  Nz            # dN/dz basis.
      
  cdef public omatm1n30    x             # Elemental xcoord basis.
  cdef public omatm1n30    y             # Elemental ycoord basis.
  cdef public omatm1n30    z             # Elemental zcoord basis.
      
  cdef public feomatm1n30    J           # Elemental Jacobian.
  cdef public feonumm1n30  detJ          # Determinant of Jacobian.
  cdef public feonumm1n30  dV            # integration weight dOmega.
  
  cdef public feomatm1n30 Jinv           # Jacobian inverse.      

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