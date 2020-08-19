

# Array specific functions.

cdef (uint64_t,uint64_t) process_shape(  object shape_in    )
cdef uint64_t            binSearch_list( list a, uint64_t x )



cpdef eye(   uint64_t   size, uint64_t nip = *)
cpdef zeros( object shape_in, uint64_t nip = *)
cpdef ones(  object shape_in, uint64_t nip = *)
cpdef array( object      arr, uint64_t nip = *)

cpdef e( object hum_dir , uint64_t nip = *)
cpdef zero(               uint64_t nip = *)
cpdef one(                uint64_t nip = *)
cpdef number(coeff_t num, uint64_t nip = *)




cpdef truncate( object humdir, object val, object out = *)



cpdef get_im(     object humdir, object val, object out = *)
cpdef extract_im( object humdir, object val, object out = *)

cpdef get_deriv(     object humdir, object val, object out = *)
cpdef extract_deriv( object humdir, object val, object out = *)


