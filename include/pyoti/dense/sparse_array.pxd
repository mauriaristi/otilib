# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  spr_omat   :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class spr_omat:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public object          re    # Real Coefficient.
  cdef public np.ndarray    p_im    # Array of imaginary coefficients.
  cdef public np.ndarray  p_ndpo    # Number of imaginary directions per orde
  cdef public ndir_t        ndir    # Number of imaginary directions.
  cdef public bases_t     nbases    # Number of bases.
  cdef public ord_t        order    # Truncation order.
  cdef public uint64_t     nrows    # Number of rows of every array.
  cdef public uint64_t     ncols    # Number of columns of every array.
  cdef public uint64_t     size     # Total number of elements in per array.
  cdef public uint8_t      spr_type # Number that indicates the type of sparse 
                                                          # matrix. 
                                                          # 0: csr, 1: coo, 2: lil
  #---------------------------------------------------------------------------------------------------  

  cpdef object get_base_sprmat_creator(self)
  cdef set_and_sum_from_otinum_t(self, tuple index, otinum_t* num)
  cpdef set_from_otinum(self, index, otinum value)
  cpdef recompute_ndir(self)
  cpdef change_order(self, ord_t new_order)
  cpdef change_nbases(self,bases_t new_nbases)
  cpdef get_imdir(self, imdir_t idx , ord_t order)

  # cdef void c_setSumFromSotinum(self, list index, sotinum_t* value)
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class spr_omat :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::