
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
  cdef uint8_t _lk            # Logical shape kind (7b): 0 -> (nrows, ncols), 1 -> (nrows,) stored as
                              # nrows x 1, 2 -> () stored as 1 x 1. The 2-D struct never changes.
  cdef ndarr_t nd             # The matrix (PLAN-ndarray.md Phase 6b): a retained (nrows, ncols) F64
                              # descriptor, possibly a strided view of another dmat's memory.
  cdef ndarr_t snap           # Non-empty only for a non-C-contiguous view: the contiguous copy that
                              # arr describes (refreshed by _sync, written back by _flush).

  #---------------------------------------------------------------------------------------------------


  @staticmethod
  cdef dmat create(darr_t* num, uint8_t FLAGS = *)
  @staticmethod
  cdef dmat create_view(ndarr_t* view, uint8_t lk = *)
  cdef int _logical(self, ndarr_t* out) except -1
  cdef object _view_rng(self, tuple r)
  cdef tuple _key(self, object val)
  cdef int _target(self, tuple r, ndarr_t* out) except -1
  cdef int _bind(self) except -1
  cdef int _sync(self) except -1
  cdef int _flush(self) except -1
  cdef int _check_out(self) except -1
  cdef int _slice(self, object ii, object jj, ndarr_t* out) except -1
  cdef object _view(self, object ii, object jj)
  cdef int _check_ij(self, object val0, object val1) except -1
  cpdef copy(self)
  cpdef set(self, object rhs)
  cpdef np.ndarray to_numpy(self)
  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTINUM :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# out= holders of 7b (rule S1b): out itself, or a zero-copy dmat of the result shape over out's memory
# when out has extra leading axes of extent 1 (real/array/base.pxi). Used by the sparse functions that
# take a dmat out=.
cdef dmat _dmat_out_shape(object out, tuple shape)
cdef dmat _dmat_out(object out, dmat like)
