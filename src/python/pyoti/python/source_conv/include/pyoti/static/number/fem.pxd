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
      
  cdef public {fenum_pytype}   xi           # Xi natural coordinate. (integration points)
  cdef public {fenum_pytype}   eta          # Eta natural coordinate. (integration points)
  cdef public {fenum_pytype}   zeta         # Zeta natural coordinate. (integration points)

  cdef public {fenum_pytype}   w            # Integration weights
      
  cdef public {fearr_pytype}  N             # Real basis.
  cdef public {fearr_pytype}  Nxi           # dN/d xi    basis.
  cdef public {fearr_pytype}  Neta          # dN/d eta   basis.
  cdef public {fearr_pytype}  Nzeta         # dN/d zeta  basis.
      
  cdef public {fearr_pytype}  Nx            # dN/dx basis.
  cdef public {fearr_pytype}  Ny            # dN/dy basis.
  cdef public {fearr_pytype}  Nz            # dN/dz basis.
      
  cdef public {arr_pytype}    x             # Elemental xcoord basis.
  cdef public {arr_pytype}    y             # Elemental ycoord basis.
  cdef public {arr_pytype}    z             # Elemental zcoord basis.
      
  cdef public {fearr_pytype}    J           # Elemental Jacobian.
  cdef public {fenum_pytype}  detJ          # Determinant of Jacobian.
  cdef public {fenum_pytype}  dV            # integration weight dOmega.
  
  cdef public {fearr_pytype} Jinv           # Jacobian inverse.      

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