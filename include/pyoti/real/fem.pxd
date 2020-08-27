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
      
  cdef public dnumfe   xi           # Xi natural coordinate. (integration points)
  cdef public dnumfe   eta          # Eta natural coordinate. (integration points)
  cdef public dnumfe   zeta         # Zeta natural coordinate. (integration points)

  cdef public dnumfe   w            # Integration weights
      
  cdef public dmatfe  N             # Real basis.
  cdef public dmatfe  Nxi           # dN/d xi    basis.
  cdef public dmatfe  Neta          # dN/d eta   basis.
  cdef public dmatfe  Nzeta         # dN/d zeta  basis.
      
  cdef public dmatfe  Nx            # dN/dx basis.
  cdef public dmatfe  Ny            # dN/dy basis.
  cdef public dmatfe  Nz            # dN/dz basis.
      
  cdef public dmat    x             # Elemental xcoord basis.
  cdef public dmat    y             # Elemental ycoord basis.
  cdef public dmat    z             # Elemental zcoord basis.
      
  cdef public dmatfe    J           # Elemental Jacobian.
  cdef public dnumfe  detJ          # Determinant of Jacobian.
  cdef public dnumfe  dV            # integration weight dOmega.
  
  cdef public dmatfe Jinv           # Jacobian inverse.      

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