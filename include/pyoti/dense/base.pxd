

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  BASE CLASS    ::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class otibase:
  
  #---------------------------------------------------------------------------------------------------
  #-------------------------------------   ATTRIBUTES   ----------------------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef public object           re           # Real element
  cdef public np.ndarray     p_im           # Imaginary directions. Every element in this list is a
  cdef public np.ndarray   p_ndpo           # Number of imaginary directions per order.
  cdef public ndir_t         ndir           # Number of imaginary directions.
  cdef public bases_t      nbases           # Number of bases.
  cdef public ord_t         order           # Truncation order. 

  cdef public type dtype
  cdef dict __dict__

  #---------------------------------------------------------------------------------------------------

  # @staticmethod
  # cdef omat create(oarr_t* arr, uint8_t FLAGS = *)
  # cpdef copy(self)
  # cpdef get_im(self, hum_dir, copy = *)
  # cpdef get_imdir(self, imdir_t idx , ord_t order, copy = *)
  # cpdef set_imdir(self,np.ndarray[coeff_t, ndim=2] arr, imdir_t idx , ord_t order)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS BASE CLASS :::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


