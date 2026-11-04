



cdef np.ndarray darr_2_npy(darr_t* array )



cpdef eye(   uint64_t   size, uint64_t nip = *)
cpdef zeros( object shape_in, uint64_t nip = *)
cpdef ones(  object shape_in, uint64_t nip = *)
cpdef array( object      arr, uint64_t nip = *)

cpdef zero(               uint64_t nip = *)
cpdef one(                uint64_t nip = *)
cpdef number(coeff_t num, uint64_t nip = *)


# NumPy index keys over the 2-D C structs (7b, real/ndarray/key2d.pxi): shared by dmat, matso and the
# semi-sparse types.
cpdef tuple key2d(object key, int ndim, int64_t d0, int64_t d1, str modname = *)
cpdef int assign_plan(tuple vshape, tuple tshape) except -1
cpdef object gauss_key(object key, int64_t nrows, int64_t ncols)
cpdef tuple reshape_shape(object args, int64_t size, str modname = *)
