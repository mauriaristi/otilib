"""
Cython-visible dense scalar, SoA / AoS arrays, LU, Gauss-point and CSR types (PLAN-dense-update.md).

FLAGS bit 0 set means the wrapper owns its C buffers; clear means a non-owning view (the Gauss layer
views the SoA array embedded in a feoarr_t). The C structs carry no ownership flag, so every
__dealloc__ honours FLAGS, and a view is only ever an input: never pass one as `res` / `out=` of a C
`_to` function (it could be reallocated or freed under its owner).
"""

from pyoti.c_otilib cimport otinum_t, oarr_t, oarr_lu_t, arro_t, feoarr_t, lilo_t
from libc.stdint cimport uint8_t, uint64_t


cdef class otinum:
    cdef otinum_t num
    cdef uint8_t FLAGS
    @staticmethod
    cdef otinum wrap(otinum_t value)


cdef class omat:
    cdef oarr_t arr
    cdef uint8_t FLAGS
    cdef object __weakref__
    @staticmethod
    cdef omat wrap(oarr_t value)


cdef class arro:
    cdef arro_t arr
    cdef uint8_t FLAGS
    @staticmethod
    cdef arro wrap(arro_t value)


cdef class _LU:
    cdef oarr_lu_t factor


# Gauss-point types: a common base holding one feoarr_t (a scalar is the 1 x 1 case).
cdef class _dnfe:
    cdef feoarr_t fe


cdef class otife(_dnfe):
    pass


cdef class omatfe(_dnfe):
    pass


# OTI sparse matrices: one pattern, one nnz x 1 SoA value array; a triplet builder.
cdef class csr_matrix:
    cdef omat _val
    cdef object _indices
    cdef object _indptr
    cdef uint64_t _nrows
    cdef uint64_t _ncols


cdef class lil_matrix:
    cdef lilo_t lil
