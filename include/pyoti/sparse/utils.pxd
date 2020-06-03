





# Array specific functions.

cdef (uint64_t,uint64_t) process_shape(object shape_in)

cpdef eye(   uint64_t   size, bases_t nbases = *, ord_t order = *, uint64_t nip = *)
cpdef zeros( object shape_in, bases_t nbases = *, ord_t order = *, uint64_t nip = *)
cpdef ones(  object shape_in, bases_t nbases = *, ord_t order = *, uint64_t nip = *)

cpdef array( object arr, bases_t nbases = *, ord_t order = *, uint64_t nip = *)
cpdef truncate( object humdir, object val, object out = *)

cpdef get_im(     object humdir, object val, object out = *)
cpdef extract_im( object humdir, object val, object out = *)

cpdef get_deriv(     object humdir, object val, object out = *)
cpdef extract_deriv( object humdir, object val, object out = *)
