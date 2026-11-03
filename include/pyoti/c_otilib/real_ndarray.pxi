# Real ndarray C declarations: ndarr_t, buffers, creators, views, elementwise, reductions,
# BLAS and linear algebra, statuses and the execution context.
# GENERATED from include/oti/real/ndarray/*.h and include/oti/core/{status,exec}.h
# (PLAN-ndarray.md, Phase 4) by tools/gen_dense_pxi.py; re-run it when one changes.
# Do not edit by hand.
cdef extern from "oti/real/ndarray.h" nogil:

    # core/status.h
    cdef enum:
        OTI_OK
        OTI_ERR_SIZE
        OTI_ERR_MEMORY
        OTI_ERR_PIVOT
        OTI_ERR_INDEX
        OTI_ERR_ARGUMENT
        OTI_ERR_SHAPE
        OTI_ERR_BUSY
        OTI_ERR_DTYPE
        OTI_ERR_LAYOUT
        OTI_ERR_CONVERGE
        OTI_ERR_NOTPD
        OTI_ERR_BACKEND
        OTI_ERR_READONLY
        OTI_DEVICE_CPU

    int oti_status_is_singular(int status)
    const char* oti_status_string(int status)

    # core/exec.h
    cdef enum:
        OTI_BACKEND_DEFAULT
        OTI_BACKEND_SERIAL
        OTI_BACKEND_OPENMP
        OTI_BACKEND_PTHREADS
        OTI_BLAS_INHERIT
        OTI_BLAS_SERIAL_IN_REGIONS
        OTI_EXEC_CHUNK_ELEMS
        OTI_EXEC_MIN_PARALLEL_DEFAULT

    ctypedef struct oti_exec_t:
        int32_t struct_size
        int32_t backend
        int32_t nthreads
        int32_t blas_policy
        int64_t min_parallel_elems
        int64_t reserved[4]

    ctypedef struct oti_ctx_s:
        int32_t struct_size
        int32_t device_type
        int32_t device_id
        int32_t flags
        oti_exec_t exec
        int64_t max_alloc_bytes
        int64_t max_temp_bytes
        void* stream
        int32_t last_status
        int32_t reserved0
        const char* last_where
        const char* last_msg
        int64_t reserved[8]
    ctypedef oti_ctx_s oti_ctx

    ctypedef int (*oti_chunk_fn)(void* arg, int64_t chunk, int32_t worker)

    void oti_exec_init(oti_exec_t* exec_)
    int oti_ctx_init(oti_ctx* ctx)
    const oti_ctx* oti_ctx_default()
    int oti_ctx_check(const oti_ctx* ctx)
    void oti_ctx_set_error(oti_ctx* ctx, int status, const char* where, const char* msg)
    int oti_ctx_last_error(const oti_ctx* ctx, const char* * where, const char* * msg)
    void oti_ctx_clear_error(oti_ctx* ctx)
    int oti_ctx_check_alloc(const oti_ctx* ctx, int64_t nbytes)
    int oti_ctx_check_temp(const oti_ctx* ctx, int64_t nbytes)
    int oti_exec_backend_available(int32_t backend)
    int oti_exec_in_parallel()
    int32_t oti_exec_max_workers(const oti_ctx* ctx)
    int oti_exec_parallel_ok(const oti_ctx* ctx, int64_t work_items, int64_t min_items)
    int32_t oti_exec_plan(const oti_ctx* ctx, int64_t n_items, int64_t chunk_items, double ns_per_item)
    int64_t oti_exec_nchunks(int64_t n_items, int64_t chunk_items)
    int oti_serial_for(int64_t n_chunks, oti_chunk_fn fn, void* arg)
    int oti_parallel_for(oti_ctx* ctx, int64_t n_chunks, oti_chunk_fn fn, void* arg)
    int oti_parallel_for_blas(oti_ctx* ctx, int64_t n_chunks, oti_chunk_fn fn, void* arg)

    # real/ndarray/structures.h
    cdef enum:
        OTI_ND_MAXDIM
        OTI_F64
        OTI_U8
        OTI_I64
        ND_C_CONTIG
        ND_F_CONTIG
        ND_WRITEABLE
        ND_RETAINED
        ND_EXPORTED
        ND_LAYOUT_C
        ND_LAYOUT_F
        ND_LAYOUT_A
        ND_LAYOUT_K
        OTI_KIND_REAL
        OTI_KIND_DENSE_SOA
        OTI_KIND_SEMISPARSE_SOA
        OTI_KIND_DIAGONAL_SOA
        OTI_DL_INT
        OTI_DL_UINT
        OTI_DL_FLOAT
        OTI_DL_BFLOAT
        OTI_DL_COMPLEX
        OTI_DL_BOOL
        OTI_VIEW_READONLY

    ctypedef struct nd_buffer_s:
        pass
    ctypedef nd_buffer_s nd_buffer_t

    ctypedef struct ndarr_t:
        void* data
        int64_t shape[OTI_ND_MAXDIM]
        int64_t strides[OTI_ND_MAXDIM]
        int32_t ndim
        int32_t dtype
        int32_t flags
        int32_t reserved
        nd_buffer_t* buf

    ctypedef struct oti_dldevice_t:
        int32_t device_type
        int32_t device_id

    ctypedef struct oti_dldtype_t:
        uint8_t code
        uint8_t bits
        uint16_t lanes

    ctypedef struct oti_dltensor_t:
        void* data
        oti_dldevice_t device
        int32_t ndim
        oti_dldtype_t dtype
        int64_t* shape
        int64_t* strides
        uint64_t byte_offset

    ctypedef struct oti_view:
        int32_t struct_size
        int32_t kind
        oti_dltensor_t dl
        int32_t flags
        int32_t trc_order
        int32_t act_order
        int32_t reserved0
        int64_t nbases
        const int64_t* bases
        int64_t reserved[6]

    int64_t nd_itemsize(int32_t dtype)
    int64_t nd_size(const ndarr_t* a)
    double* nd_f64(const ndarr_t* a)
    uint8_t* nd_u8(const ndarr_t* a)
    int64_t* nd_i64(const ndarr_t* a)

    # real/ndarray/buffer.h
    cdef enum:
        ND_STATE_EXPORTS_SHIFT
        ND_ALLOC_ZERO
        ND_ALLOC_GROWABLE
        ND_V_SPAN
        ND_V_OUTPUT
        ND_SHARE_NONE
        ND_SHARE_MAYBE
        ND_SHARE_EXACT
        ND_SRC_BOOL
        ND_SRC_INT
        ND_SRC_UINT
        ND_SRC_FLOAT
        ND_SRC_COMPLEX
        ND_SRC_OTHER
        ND_IMPORT_WRITEABLE
        ND_IMPORT_COPY

    uint64_t ND_STATE_REFS_MASK
    uint64_t ND_STATE_EXPORTS_MASK
    uint64_t ND_STATE_OWNS
    uint64_t ND_STATE_GROWABLE
    uint64_t ND_STATE_WRITEABLE
    uint64_t ND_STATE_GROWING

    ctypedef struct nd_srctype_t:
        int32_t kind
        int32_t itemsize
        int32_t swapped
        int32_t reserved

    ctypedef struct nd_import_t:
        void* data
        int32_t ndim
        int32_t readonly
        const int64_t* shape
        const int64_t* byte_strides
        nd_srctype_t src
        int32_t device_type
        int32_t reserved

    ctypedef void (*nd_release_fn)(void* release_ctx)

    void nd_init_empty(ndarr_t* a)
    int nd_alloc(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape, int32_t layout,
                 int32_t alloc_flags, ndarr_t* res)
    int nd_alloc_strided(oti_ctx* ctx, int32_t dtype, int32_t ndim, const int64_t* shape,
                         const int64_t* strides, int32_t alloc_flags, ndarr_t* res)
    int nd_wrap(oti_ctx* ctx, const ndarr_t* desc, const void* span_lo, int64_t span_nbytes,
                nd_release_fn release, void* release_ctx, ndarr_t* res)
    int nd_wrap_trusted(void* data, int32_t dtype, int32_t ndim, const int64_t* shape,
                        const int64_t* strides, int32_t writeable, ndarr_t* out)
    int nd_view_retain(const ndarr_t* src, ndarr_t* res)
    int nd_clone(const ndarr_t* src, ndarr_t* res)
    void nd_move(ndarr_t* src, ndarr_t* dst)
    int nd_export(const ndarr_t* src, int32_t writeable, ndarr_t* res)
    void nd_release(ndarr_t* a)
    int nd_grow(oti_ctx* ctx, ndarr_t* root, int64_t nbytes, int64_t keep_bytes)
    int nd_grow_locked(oti_ctx* ctx, ndarr_t* root, int64_t nbytes, int64_t keep_bytes)
    int nd_set_layout(ndarr_t* root, int32_t ndim, const int64_t* shape, const int64_t* strides)
    uint64_t nd_buffer_state(const nd_buffer_t* buf)
    int64_t nd_buffer_refs(const nd_buffer_t* buf)
    int64_t nd_buffer_exports(const nd_buffer_t* buf)
    const void* nd_buffer_base(const nd_buffer_t* buf)
    int64_t nd_buffer_nbytes(const nd_buffer_t* buf)
    int nd_buffer_lock_layout(nd_buffer_t* buf)
    void nd_buffer_unlock_layout(nd_buffer_t* buf)
    int nd_validate(const ndarr_t* a, const void* span_lo, const void* span_hi, int32_t vflags)
    void nd_update_flags(ndarr_t* a)
    int nd_extent(const ndarr_t* a, int64_t* lo, int64_t* hi)
    int nd_internal_overlap(const ndarr_t* a)
    int nd_may_share_memory(const ndarr_t* a, const ndarr_t* b)
    int nd_pep3118_classify(const char* format, int64_t itemsize, nd_srctype_t* st)
    int nd_dlpack_classify(int32_t code, int32_t bits, int32_t lanes, nd_srctype_t* st)
    int nd_import(oti_ctx* ctx, const nd_import_t* src, int32_t want, int32_t iflags,
                  nd_release_fn release, void* release_ctx, ndarr_t* res)
    int nd_to_view(const ndarr_t* a, oti_view* v)
    int nd_from_view(const oti_view* v, int32_t vflags, ndarr_t* out)
    void nd_test_fail_alloc(int64_t countdown)

    # real/ndarray/create.h
    int nd_empty(oti_ctx* ctx, int32_t ndim, const int64_t* shape, int32_t layout, ndarr_t* res)
    int nd_empty_like(oti_ctx* ctx, const ndarr_t* src, int32_t alloc_flags, ndarr_t* res)
    int nd_zeros(oti_ctx* ctx, int32_t ndim, const int64_t* shape, int32_t layout, ndarr_t* res)
    int nd_ones(oti_ctx* ctx, int32_t ndim, const int64_t* shape, int32_t layout, ndarr_t* res)
    int nd_full(oti_ctx* ctx, int32_t ndim, const int64_t* shape, double value, int32_t layout,
                ndarr_t* res)
    int nd_eye(oti_ctx* ctx, int64_t n, int64_t m, int64_t k, int32_t layout, ndarr_t* res)
    int nd_arange(oti_ctx* ctx, double start, double stop, double step, ndarr_t* res)
    int nd_linspace(oti_ctx* ctx, double start, double stop, int64_t num, int32_t endpoint,
                    ndarr_t* res)
    int nd_copy(oti_ctx* ctx, const ndarr_t* src, int32_t layout, ndarr_t* res)
    int nd_ascontiguous(oti_ctx* ctx, const ndarr_t* src, ndarr_t* res, int32_t* copied)
    int nd_asfortran(oti_ctx* ctx, const ndarr_t* src, ndarr_t* res, int32_t* copied)
    int nd_reshape(oti_ctx* ctx, const ndarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
                   ndarr_t* res, int32_t* copied)

    # real/ndarray/views.h
    cdef enum:
        ND_IDX_INT
        ND_IDX_SLICE
        ND_IDX_NEWAXIS
        ND_IDX_ELLIPSIS
        ND_IDX_ARRAY
        ND_HAS_START
        ND_HAS_STOP
        ND_HAS_STEP

    ctypedef struct nd_index_t:
        int32_t kind
        int32_t has
        int64_t start
        int64_t stop
        int64_t step
        const ndarr_t* arr

    int nd_slice_normalize(int64_t n, const nd_index_t* s, int64_t* start, int64_t* step, int64_t* len)
    int nd_normalize_axis(int32_t axis, int32_t ndim, int32_t* res)
    int nd_broadcast_shapes(int32_t nops, const ndarr_t* const* ops, int32_t* ndim, int64_t* shape)
    int nd_view_index(const ndarr_t* src, int32_t nidx, const nd_index_t* idx, ndarr_t* out)
    int nd_view_transpose(const ndarr_t* src, int32_t naxes, const int32_t* axes, ndarr_t* out)
    int nd_view_swapaxes(const ndarr_t* src, int32_t axis1, int32_t axis2, ndarr_t* out)
    int nd_view_squeeze(const ndarr_t* src, int32_t naxes, const int32_t* axes, ndarr_t* out)
    int nd_view_expand_dims(const ndarr_t* src, int32_t naxes, const int32_t* axes, ndarr_t* out)
    int nd_view_broadcast_to(const ndarr_t* src, int32_t ndim, const int64_t* shape, ndarr_t* out)
    int nd_view_diagonal(const ndarr_t* src, int64_t offset, int32_t axis1, int32_t axis2, ndarr_t* out)
    int nd_view_reshape(const ndarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
                        ndarr_t* out)
    int nd_index_get(oti_ctx* ctx, const ndarr_t* src, int32_t nidx, const nd_index_t* idx,
                     ndarr_t* res)
    int nd_index_set(oti_ctx* ctx, ndarr_t* dst, int32_t nidx, const nd_index_t* idx,
                     const ndarr_t* values)

    # real/ndarray/iter.h
    cdef enum:
        ND_ITER_MAXOPS
        ND_ITER_IN
        ND_ITER_OUT
        ND_ITER_REDUCE_OUT
        ND_ITER_ORDER_C
        ND_ITER_ORDER_K

    ctypedef struct nd_iter_t:
        int32_t nop
        int32_t ndim
        int64_t size
        int64_t shape[OTI_ND_MAXDIM]
        int64_t bstrides[OTI_ND_MAXDIM][ND_ITER_MAXOPS]
        char* data[ND_ITER_MAXOPS]
        int32_t itemsize[ND_ITER_MAXOPS]
        int32_t perm[OTI_ND_MAXDIM]

    ctypedef int (*nd_inner_fn)(void* arg, int64_t n, char* const* ptrs, const int64_t* bstrides)

    int nd_iter_init(nd_iter_t* it, int32_t nop, const ndarr_t* const* ops, const int32_t* op_flags,
                     int32_t order)
    int nd_iter_run(const nd_iter_t* it, int64_t start, int64_t count, nd_inner_fn fn, void* arg)

    # real/ndarray/elementwise.h
    cdef enum:
        ND_OP_ADD
        ND_OP_SUB
        ND_OP_MUL
        ND_OP_DIV
        ND_OP_POW
        ND_OP_MAXIMUM
        ND_OP_MINIMUM
        ND_OP_EQ
        ND_OP_NE
        ND_OP_LT
        ND_OP_LE
        ND_OP_GT
        ND_OP_GE
        ND_OP_AND
        ND_OP_OR
        ND_OP_XOR
        ND_FN_NEG
        ND_FN_ABS
        ND_FN_SQRT
        ND_FN_CBRT
        ND_FN_EXP
        ND_FN_EXP2
        ND_FN_EXPM1
        ND_FN_LOG
        ND_FN_LOG2
        ND_FN_LOG10
        ND_FN_LOG1P
        ND_FN_SIN
        ND_FN_COS
        ND_FN_TAN
        ND_FN_ASIN
        ND_FN_ACOS
        ND_FN_ATAN
        ND_FN_SINH
        ND_FN_COSH
        ND_FN_TANH
        ND_FN_ASINH
        ND_FN_ACOSH
        ND_FN_ATANH
        ND_FN_FLOOR
        ND_FN_CEIL
        ND_FN_TRUNC
        ND_FN_RINT
        ND_FN_SQUARE
        ND_FN_RECIPROCAL
        ND_FN_SIGN
        ND_FN_NOT

    int nd_binary_to(oti_ctx* ctx, int32_t op, const ndarr_t* a, const ndarr_t* b, ndarr_t* out)
    int nd_binary(oti_ctx* ctx, int32_t op, const ndarr_t* a, const ndarr_t* b, ndarr_t* res)
    int nd_binary_scalar_to(oti_ctx* ctx, int32_t op, const ndarr_t* a, double s, int32_t scalar_left,
                            ndarr_t* out)
    int nd_binary_scalar(oti_ctx* ctx, int32_t op, const ndarr_t* a, double s, int32_t scalar_left,
                         ndarr_t* res)
    int nd_unary_to(oti_ctx* ctx, int32_t fn, const ndarr_t* a, ndarr_t* out)
    int nd_unary(oti_ctx* ctx, int32_t fn, const ndarr_t* a, ndarr_t* res)
    int nd_assign(oti_ctx* ctx, const ndarr_t* src, ndarr_t* dst)
    int nd_fill(oti_ctx* ctx, ndarr_t* dst, double value)

    # real/ndarray/reduce.h
    cdef enum:
        ND_RED_SUM
        ND_RED_PROD
        ND_RED_MIN
        ND_RED_MAX
        ND_RED_MEAN
        ND_RED_VAR
        ND_RED_STD
        ND_RED_ARGMIN
        ND_RED_ARGMAX
        ND_RED_ANY
        ND_RED_ALL

    int nd_reduce(oti_ctx* ctx, int32_t op, const ndarr_t* a, int32_t naxes, const int32_t* axes,
                  int32_t keepdims, int64_t ddof, ndarr_t* res)
    int nd_reduce_to(oti_ctx* ctx, int32_t op, const ndarr_t* a, int32_t naxes, const int32_t* axes,
                     int32_t keepdims, int64_t ddof, ndarr_t* out)
    double nd_pairwise_sum(const double* x, int64_t n, int64_t stride)
    double nd_tree_combine(const double* partials, int64_t n, int32_t op)

    # real/ndarray/blas.h
    int nd_matmul(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* res)
    int nd_matmul_to(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out)
    int nd_dot(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* res)
    int nd_dot_to(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out)
    int nd_gemm(oti_ctx* ctx, int32_t transa, int32_t transb, double alpha, const ndarr_t* a,
                const ndarr_t* b, double beta, ndarr_t* c)
    int nd_gemv(oti_ctx* ctx, int32_t trans, double alpha, const ndarr_t* a, const ndarr_t* x,
                double beta, ndarr_t* y)
    int nd_ger(oti_ctx* ctx, double alpha, const ndarr_t* x, const ndarr_t* y, ndarr_t* a)
    int nd_vdot(oti_ctx* ctx, const ndarr_t* x, const ndarr_t* y, double* res)
    int nd_axpy(oti_ctx* ctx, double alpha, const ndarr_t* x, ndarr_t* y)
    int nd_scal(oti_ctx* ctx, double alpha, ndarr_t* x)
    int nd_nrm2(oti_ctx* ctx, const ndarr_t* x, double* res)
    int nd_asum(oti_ctx* ctx, const ndarr_t* x, double* res)
    int nd_iamax(oti_ctx* ctx, const ndarr_t* x, int64_t* res)

    # real/ndarray/linalg.h
    ctypedef struct nd_lu_t:
        ndarr_t lu
        int* ipiv
        int64_t n
        int32_t trans
        int32_t info
        int64_t nbatch
        int* infos

    void nd_lu_init(nd_lu_t* lu)
    int nd_lu_factor(oti_ctx* ctx, ndarr_t* a, int32_t overwrite, nd_lu_t* lu)
    int nd_lu_solve(oti_ctx* ctx, const nd_lu_t* lu, const ndarr_t* b, ndarr_t* res)
    int nd_lu_solve_to(oti_ctx* ctx, const nd_lu_t* lu, const ndarr_t* b, ndarr_t* out)
    void nd_lu_free(nd_lu_t* lu)
    int nd_solve(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* res)
    int nd_solve_to(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out)
    int nd_inv(oti_ctx* ctx, const ndarr_t* a, ndarr_t* res)
    int nd_det(oti_ctx* ctx, const ndarr_t* a, ndarr_t* res)
    int nd_slogdet(oti_ctx* ctx, const ndarr_t* a, ndarr_t* sign, ndarr_t* logabs)
    int nd_cholesky(oti_ctx* ctx, const ndarr_t* a, int32_t lower, ndarr_t* res)
    int nd_cho_solve(oti_ctx* ctx, const ndarr_t* c, int32_t lower, const ndarr_t* b, ndarr_t* res)
    int nd_cho_solve_to(oti_ctx* ctx, const ndarr_t* c, int32_t lower, const ndarr_t* b, ndarr_t* out)
    int nd_solve_triangular(oti_ctx* ctx, const ndarr_t* t, const ndarr_t* b, int32_t lower,
                            int32_t trans, int32_t unit_diagonal, ndarr_t* res)
    int nd_solve_triangular_to(oti_ctx* ctx, const ndarr_t* t, const ndarr_t* b, int32_t lower,
                               int32_t trans, int32_t unit_diagonal, ndarr_t* out)

    # real/ndarray/compat_darr.h
    cdef enum:
        ND_DARR_BORROW
        ND_DARR_RETAIN
        ND_DARR_TAKE

    int nd_from_darr(oti_ctx* ctx, darr_t* src, int32_t mode, ndarr_t* out)
    int nd_as_darr(const ndarr_t* a, int32_t writeable, darr_t* out)
