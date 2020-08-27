# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::    CLASS  csr_matso   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class lil_matrix:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef object[:] data # Data array.
  cdef object[:] rows # Row list of lists.

  cdef public uint64_t     nrows    # Number of rows of every array.
  cdef public uint64_t     ncols    # Number of columns of every array.
  cdef public uint64_t     size     # Total number of elements in per array.

  cpdef get_deriv(     self, object hum_dir )
  cpdef get_im(        self, object hum_dir )
  cpdef extract_im(    self, object hum_dir )
  cpdef extract_deriv( self, object hum_dir )
  cpdef get_order_im(  self, ord_t order    )
  cpdef truncate(      self, object humdir  )
  
  #---------------------------------------------------------------------------------------------------  


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class spr_omat :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::    CLASS  csr_matso   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class csr_matrix:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef object[:]       data # Data array.
  cdef uint64_t[:]  indices # Indices array.
  cdef uint64_t[:]   indptr # Index pointer array.

  cdef public uint64_t nrows # Number of rows of the array.
  cdef public uint64_t ncols # Number of columns of every array.
  cdef public uint64_t size  # Total number of elements in per array.

  cpdef get_deriv(     self, object hum_dir )
  cpdef get_im(        self, object hum_dir )
  cpdef extract_im(    self, object hum_dir )
  cpdef extract_deriv( self, object hum_dir )
  cpdef get_order_im(  self, ord_t order    )
  cpdef truncate(      self, object humdir  )

  #---------------------------------------------------------------------------------------------------  


# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::::::::: End of class spr_omat :::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::