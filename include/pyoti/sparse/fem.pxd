# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  elm_help    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elm_help:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public object   special      # Marker to determine special behavior of the system.
  
  cdef public bases_t  otinbases    # OTI number of bases.
  cdef public ord_t    otiorder     # OTI order.

  cdef public uint8_t  ndim         # Number of dimensions of the element.
  cdef public uint8_t  nbasis       # Element type order.
  cdef public uint64_t ndim_an      # Number of dimensions of the analysis.
  cdef public uint64_t nip          # Number of integration points
      
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
  cdef public matso    y            # Elemental ycoord basis.
  cdef public matso    z            # Elemental zcoord basis.
      
  cdef public matsofe    J          # Elemental Jacobian.
  cdef public sotife  detJ          # Determinant of Jacobian.
  cdef public sotife  dV            # integration weight dOmega.
  
  cdef public matsofe Jinv          # Jacobian inverse.      

  cdef public uint8_t compute_Jinv  # Flag to compute Jacobian

  
  #---------------------------------------------------------------------------------------------------
  
  cpdef is_allocated( self )
  cpdef allocate(self, uint8_t ndim, uint64_t nbasis, uint64_t nip, bases_t nbases = * , ord_t order = * )
  cpdef allocate_spatial( self, uint64_t ndim_an, uint8_t compute_Jinv = * )
  cpdef reset( self )
  cpdef end( self )
  cpdef integrate( self, object val, object out = * )
  cpdef get_local(self, matso arr, np.ndarray elem_indices, matso out = *)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elm_help :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::