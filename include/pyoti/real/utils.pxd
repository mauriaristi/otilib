



cdef np.ndarray darr_2_npy(darr_t* array )


# Linear algebra operations.

cpdef dmat dot(dmat A, dmat B)
cpdef dmat invert(dmat A)
cpdef dmat transpose(dmat A)
cpdef coeff_t det(dmat A)




cpdef dmat eye(uint64_t size)
cpdef dmat zeros(uint64_t nrows,uint64_t ncols)
cpdef dmat ones(uint64_t nrows,uint64_t ncols)
