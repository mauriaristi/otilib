"""
Cython-visible semi-sparse scalar, AoS/SoA arrays, and opaque LU types.
"""

from pyoti.c_otilib cimport ssotinum_t, arrss_t, oarrss_t, oarrss_lu_t, feoarrss_t, lilss_t
from libc.stdint cimport uint64_t


cdef class ssotinum:
    cdef ssotinum_t num
    @staticmethod
    cdef ssotinum wrap(ssotinum_t value)


cdef class oarrss:
    cdef oarrss_t arr
    cdef object __weakref__
    @staticmethod
    cdef oarrss wrap(oarrss_t value)


cdef class arrss:
    cdef arrss_t arr
    @staticmethod
    cdef arrss wrap(arrss_t value)


cdef class _LU:
    cdef oarrss_lu_t factor


# Gauss-point types (Phase 4): a common base holding one feoarrss_t.
cdef class _ssfe:
    cdef feoarrss_t fe


cdef class ssotife(_ssfe):
    pass


cdef class oarrssfe(_ssfe):
    pass


# OTI sparse matrices (Phase 6): one pattern, one nnz x 1 SoA value array; a triplet builder.
cdef class csr_matrix:
    cdef oarrss _val
    cdef object _indices
    cdef object _indptr
    cdef uint64_t _nrows
    cdef uint64_t _ncols


cdef class lil_matrix:
    cdef lilss_t lil
