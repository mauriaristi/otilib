# cython: boundscheck=False 
# cython: wraparound=False 
# cython: nonecheck=False 
# cython: language_level=3
# cython: profile=False
# cython: linetrace=False
# cython: binding=True
# cython: embedsignature=False
## distutils: define_macros=CYTHON_TRACE_NOGIL=1
## distutils: libraries = oti 
## distutils: extra_compile_args = -arch i386 -arch x86_64 
# filename: pyoti.pyx

include "core.pxi"
include "dense.pxi"
# include "sparse.pxi"