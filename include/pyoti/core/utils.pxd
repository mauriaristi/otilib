


cdef np.ndarray[double, ndim=3]  c_ptr_to_np_3darray_double(void * ptr, np.npy_intp sizex, \
                                                            np.npy_intp sizey, np.npy_intp sizez, \
                                                            uint8_t numpy_own = *)
cdef np.ndarray[double, ndim=2]  c_ptr_to_np_2darray_double(void * ptr, np.npy_intp sizex, \
                                                            np.npy_intp sizey, uint8_t numpy_own = *)
cdef np.ndarray[double, ndim=1]  c_ptr_to_np_1darray_double(void * ptr, np.npy_intp size, \
                                                            uint8_t numpy_own = *)
cdef np.ndarray[uint64_t, ndim=1]  c_ptr_to_np_1darray_uint64(void * ptr, np.npy_intp size, \
                                                            uint8_t numpy_own = *)

cdef np.ndarray[uint8_t, ndim=1]  c_ptr_to_np_1darray_uint8(void * ptr, np.npy_intp size, \
                                                            uint8_t numpy_own = *)
# cdef void c_getDirExpA(list dirArray, uint16_t** p_dirA, uint8_t** p_expA, uint8_t* order)

cdef void c_Py_print2DArrayUI8(uint8_t* array,uint64_t dim1, uint8_t dim2)
cdef void c_Py_printArrayUI8(uint8_t* array,uint8_t size)
cdef void c_Py_printArrayUI16(uint16_t* array,uint8_t size)
cdef void c_Py_printArrayUI64(uint64_t* array,uint64_t size)

cdef dHelp get_cython_dHelp()
cpdef list expand_imdir(hum_dir)
cpdef list imdir(hum_dir)


cdef copy_numpy2d_to_ptr_f64(np.ndarray[coeff_t, ndim=2] src, coeff_t* dst)

cpdef get_deriv_factor(hum_dir)

cdef void error_function( int64_t err_id ) nogil
#-----------------------------------------------------------------------------------------------------
