"""
Cython-visible semi-sparse scalar, AoS/SoA arrays, and opaque LU types.
"""

from pyoti.c_otilib cimport ssotinum_t, arrss_t, oarrss_t, oarrss_lu_t


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
