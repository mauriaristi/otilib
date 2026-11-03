
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTINUM    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class dmat:
  
  #---------------------------------------------------------------------------------------------------
  #-------------------------------------   ATTRIBUTES   ----------------------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef darr_t  arr            # darr_t window of the matrix for the C code that still takes a darr_t
                              # (sparse, static, fem): it is always valid; see _bind.
  cdef uint8_t FLAGS          # 1 if the memory was handed over with the darr_t (kept for callers).
  cdef ndarr_t nd             # The matrix (PLAN-ndarray.md Phase 6b): a retained (nrows, ncols) F64
                              # descriptor, possibly a strided view of another dmat's memory.
  cdef ndarr_t snap           # Non-empty only for a non-C-contiguous view: the contiguous copy that
                              # arr describes (refreshed by _sync, written back by _flush).

  #---------------------------------------------------------------------------------------------------


  @staticmethod
  cdef dmat create(darr_t* num, uint8_t FLAGS = *)
  @staticmethod
  cdef dmat create_view(ndarr_t* view)
  cdef int _bind(self) except -1
  cdef int _sync(self) except -1
  cdef int _flush(self) except -1
  cdef int _check_out(self) except -1
  cdef int _slice(self, object ii, object jj, ndarr_t* out) except -1
  cdef object _view(self, object ii, object jj)
  cdef int _check_ij(self, object val0, object val1) except -1
  cpdef copy(self)
  cdef __setitem__r(self, object val, coeff_t value)
  cdef __setitem__R(self, object val, dmat    value)
  cpdef set(self, coeff_t val)
  cpdef np.ndarray[double, ndim=2] to_numpy(self)
  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTINUM :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
