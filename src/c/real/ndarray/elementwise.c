// ndarray elementwise arithmetic, assignment and fill (include/oti/real/ndarray/elementwise.h, Phase 1;
// PLAN-ndarray-contracts.md 3.4 and 5.4). Unity-included from src/c/real_ndarray.c after buffer.c
// (ndb_alloc_strided, ndb_contig_strides, oti_ckd_mul_i64) and iter.c (ndi_broadcast_shape,
// ndi_driver, ndi_k_sort); static helpers carry the nde_ prefix. functions.c, included next, reuses
// the driver (nde_apply_to, nde_apply_new) and the NDE_UNARY_KERNEL macro.
//
// Structure of every operation:
//   - a kernel: an nd_inner_fn over one run (n elements, one byte stride per operand) with a
//     contiguous body the compiler can vectorize, stride-0 (broadcast) bodies for binary operations
//     and a strided fallback. Each element depends only on its own operands, and the build has no
//     FMA contraction (-ffp-contract=off) and no vector math library, so the vector body, the scalar
//     tail and any traversal order give bit-identical values;
//   - the trivial path (NumPy's PyArray_TRIVIALLY_ITERABLE, critic W1 finding 5): when the output
//     is dense (C, F or any compact layout with positive strides, e.g. the SoA block layout) and
//     every input has its shape and strides or is a single element, the kernel runs over `size`
//     elements in memory order with no iterator (nde_try_flat);
//   - otherwise the driver: nd_iter_init() over (out, inputs) in ND_ITER_ORDER_K, then the
//     iteration space cut into fixed logical chunks of OTI_EXEC_CHUNK_ELEMS linear indices, each
//     walked by nd_iter_run() (nde_run);
//   - both run the same fixed chunks through nde_for(): oti_parallel_for() when oti_exec_plan()
//     gives >= 2 workers for the kernel family's cost per element (contracts S27; NDE_NS_*),
//     oti_serial_for() otherwise. A chunk writes only its own elements and records no error, so
//     values are bit-identical at every thread count;
//   - aliasing (contracts 3.4): an input that is exactly `out` (ND_SHARE_EXACT) is computed in place;
//     any other possible overlap (ND_SHARE_MAYBE) computes into a temporary charged to the temp
//     budget, then copies it into `out`. Assignment copies a possibly overlapping source first
//     (snapshot semantics); an exact alias is a no-op.
// Comparisons and mask operators (ND_OP_EQ ... ND_OP_XOR, ND_FN_NOT) have their kernels in mask.c
// (forward-declared below); this file dispatches them like the arithmetic operations.

#include <math.h>
#include <string.h>

#include "oti/real/ndarray.h"

// Kernel argument: the positions of the operands in the iterator and an optional scalar.
typedef struct {
    int32_t io;        // output
    int32_t i0;        // first input (left operand)
    int32_t i1;        // second input (right operand); unused by unary kernels
    int32_t reserved;
    double  s;         // fill value
} nde_karg_t;

// One elementwise job: a prepared iterator, its kernel and the kernel argument.
typedef struct {
    const nd_iter_t* it;
    nd_inner_fn      fn;
    void*            arg;
} nde_job_t;

// One trivially iterable job: per operand its element 0 and its step (the itemsize, or 0 for a
// single-element operand), walked linearly over `size` elements.
typedef struct {
    nd_inner_fn fn;
    void*       arg;
    int32_t     nop;
    int32_t     reserved;
    int64_t     size;
    char*       data[ND_ITER_MAXOPS];
    int64_t     step[ND_ITER_MAXOPS];
} nde_flat_t;

// A binary operation: kernel, operand and result dtypes, cost per element for oti_exec_plan().
typedef struct {
    nd_inner_fn fn;
    int32_t     in_dtype;
    int32_t     out_dtype;
    double      ns;
} nde_opinfo_t;

// Cost per element (ns, one core) of the kernel families, for oti_exec_plan() (contracts S27).
// Measured serially on 2^20 contiguous doubles (Apple M-series, build-orch/w2-scratch/nd-kern/
// bench_ns.c): add / mul / copy / fill / compare / neg / floor / sign 0.1-0.2; div, sqrt, reciprocal
// 0.13-0.25 and maximum / minimum 0.8 (the NaN and signed-zero branches); libm functions 1.5-2.9;
// pow 4.9. Strided or broadcast operands cost more per element; the constants are the contiguous
// floor, which errs towards serial for small loops.
#define NDE_NS_ARITH   0.15
#define NDE_NS_DIV     0.3
#define NDE_NS_LIBM    2.0
#define NDE_NS_POW     5.0

// mask.c (included after this file and functions.c): comparison and logical operations.
static int ndm_binary_info(int32_t op, nde_opinfo_t* info);


// *******************************************************************************************************
// Debug builds assert that every input descriptor is well formed (contracts 1.1; the same policy as
// nd-core, critic W1 finding 14); release builds trust them. NULL is left to the argument checks.
static inline void nde_debug_input(const ndarr_t* a){

#ifdef OTI_ND_DEBUG
    assert(a == NULL || nd_validate(a, NULL, NULL, 0) == OTI_OK);
#else
    (void)a;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Debug builds assert that a `res` argument is empty or a temporary on entry (contracts 1.4, [cL7]).
static inline void nde_debug_res(const ndarr_t* res){

#ifdef OTI_ND_DEBUG
    assert(res == NULL || !(res->flags & ND_RETAINED));
#else
    (void)res;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs n_chunks fixed chunks of fn: in parallel when oti_exec_plan() gives >= 2 workers for n_items
// items of ns nanoseconds each (with exactly that many workers, through a copy of the context),
// serially otherwise. The chunks, hence the values, do not depend on the choice.
static int nde_for(oti_ctx* ctx, int64_t n_items, int64_t chunk_items, double ns, int64_t n_chunks,
                   oti_chunk_fn fn, void* arg){

    if (n_chunks >= 2){

        int32_t w = oti_exec_plan(ctx, n_items, chunk_items, ns);

        if (w >= 2){

            oti_ctx run = *(ctx != NULL ? ctx : oti_ctx_default());

            run.exec.nthreads = w;

            return oti_parallel_for(&run, n_chunks, fn, arg);

        }

    }

    return oti_serial_for(n_chunks, fn, arg);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Chunk function: walks the linear range of chunk c (an oti_chunk_fn; safe to run concurrently on
// distinct chunks, since the kernels write only the elements of their run).
static int nde_chunk(void* arg, int64_t c, int32_t worker){

    const nde_job_t* job = (const nde_job_t*)arg;
    int64_t start = c * OTI_EXEC_CHUNK_ELEMS;
    int64_t n = job->it->size - start;

    (void)worker;

    if (n > OTI_EXEC_CHUNK_ELEMS){
        n = OTI_EXEC_CHUNK_ELEMS;
    }

    return nd_iter_run(job->it, start, n, job->fn, job->arg);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs a prepared iterator in fixed logical chunks of OTI_EXEC_CHUNK_ELEMS elements (nde_for).
static int nde_run(oti_ctx* ctx, const nd_iter_t* it, nd_inner_fn fn, void* arg, double ns){

    nde_job_t job;

    job.it  = it;
    job.fn  = fn;
    job.arg = arg;

    return nde_for(ctx, it->size, OTI_EXEC_CHUNK_ELEMS, ns,
                   oti_exec_nchunks(it->size, OTI_EXEC_CHUNK_ELEMS), nde_chunk, &job);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Chunk function of the trivial path: elements [c*CH, min((c+1)*CH, size)) as one run.
static int nde_flat_chunk(void* arg, int64_t c, int32_t worker){

    const nde_flat_t* f = (const nde_flat_t*)arg;
    char* p[ND_ITER_MAXOPS];
    int64_t start = c * OTI_EXEC_CHUNK_ELEMS;
    int64_t n = f->size - start;
    int32_t i;

    (void)worker;

    if (n > OTI_EXEC_CHUNK_ELEMS){
        n = OTI_EXEC_CHUNK_ELEMS;
    }

    for (i = 0; i < f->nop; i++){
        p[i] = f->data[i] + start * f->step[i];
    }

    return f->fn(f->arg, n, p, f->step);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Nonzero when a (size >= 1 elements) occupies exactly `size` consecutive elements upward from data:
// C or F contiguous, or a compact layout with positive strides on its axes of extent > 1 (the SoA
// block layout); such a layout can be walked linearly in memory order.
static int nde_dense_up(const ndarr_t* a, int64_t size){

    int64_t last = 0;
    int32_t k;

    if (a->flags & (ND_C_CONTIG | ND_F_CONTIG)){
        return 1;
    }

    for (k = 0; k < a->ndim; k++){

        if (a->shape[k] <= 1){
            continue;
        }

        if (a->strides[k] <= 0){
            return 0;
        }

        last += (a->shape[k] - 1) * a->strides[k];      // bounded by the validated span.

    }

    return last == size - 1 && !nd_internal_overlap(a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Nonzero when a has o's shape and o's strides on every axis of extent > 1.
static int nde_same_layout(const ndarr_t* a, const ndarr_t* o){

    int32_t k;

    if (a->ndim != o->ndim){
        return 0;
    }

    for (k = 0; k < o->ndim; k++){
        if (a->shape[k] != o->shape[k] || (o->shape[k] > 1 && a->strides[k] != o->strides[k])){
            return 0;
        }
    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The trivial path (NumPy's PyArray_TRIVIALLY_ITERABLE): ops[io] is the output. Taken when the
// output is writeable, non-empty and dense (nde_dense_up), and every input has the output's layout
// (nde_same_layout) or is a single element broadcast with step 0; an input may be the output itself
// (same data and dtype: in place), any other byte-range overlap leaves the case to the general path
// (and its temporary). Returns 1 with *status set when it ran, 0 when the general path must run
// (which also produces every error status).
static int nde_try_flat(oti_ctx* ctx, nd_inner_fn fn, void* arg, double ns, int32_t nop,
                        const ndarr_t* const* ops, int32_t io, int* status){

    const ndarr_t* o = ops[io];
    nde_flat_t f;
    uintptr_t olo, ohi;
    int64_t size;
    int32_t i;

    if (!(o->flags & ND_WRITEABLE)){
        return 0;
    }

    size = nd_size(o);

    if (size == 0 || !nde_dense_up(o, size)){
        return 0;
    }

    olo = (uintptr_t)o->data;
    ohi = olo + (uintptr_t)size * (uintptr_t)nd_itemsize(o->dtype);

    for (i = 0; i < nop; i++){

        const ndarr_t* a = ops[i];
        int64_t isz = nd_itemsize(a->dtype);
        uintptr_t lo = (uintptr_t)a->data, hi;

        f.data[i] = (char*)a->data;

        if (i == io){
            f.step[i] = isz;
            continue;
        }

        if (nde_same_layout(a, o)){

            f.step[i] = isz;

            if (a->data == o->data && a->dtype == o->dtype){
                continue;                               // exact alias: in place.
            }

            hi = lo + (uintptr_t)size * (uintptr_t)isz;

        } else if (a->ndim <= o->ndim && nd_size(a) == 1){

            f.step[i] = 0;
            hi = lo + (uintptr_t)isz;

        } else {
            return 0;
        }

        if (lo < ohi && olo < hi){
            return 0;
        }

    }

    f.fn   = fn;
    f.arg  = arg;
    f.nop  = nop;
    f.size = size;

    *status = nde_for(ctx, size, OTI_EXEC_CHUNK_ELEMS, ns,
                      oti_exec_nchunks(size, OTI_EXEC_CHUNK_ELEMS), nde_flat_chunk, &f);

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Allocates a compact array of shape (ndim, shape) in the K layout of the inputs ins[0 .. nin)
// (contracts S24): the axes of extent > 1 in the iterator's K order over the inputs (ndi_driver,
// ndi_k_sort), outermost first; axes of extent <= 1 keep their own slot and the sorted axes fill the
// other slots (nd-core's nd_empty_like rule, so C and F give NumPy's strides); C strides over that
// permuted shape, permuted back, through nd-core's ndb_alloc_strided(). A temporary (temp != 0) is
// first checked against the context's temp budget. Non-recording; res is empty on failure.
static int nde_alloc_k(oti_ctx* ctx, int32_t dtype, int32_t nin, const ndarr_t* const* ins,
                       int32_t ndim, const int64_t* shape, int32_t temp, ndarr_t* res){

    int64_t pshape[OTI_ND_MAXDIM], pstr[OTI_ND_MAXDIM], str[OTI_ND_MAXDIM];
    int32_t axes[OTI_ND_MAXDIM], perm[OTI_ND_MAXDIM];
    int64_t nbytes = nd_itemsize(dtype);
    int32_t nkept = 0, slot = 0, k;
    int status;

    if (temp){

        for (k = 0; k < ndim; k++){
            if (shape[k] > 0 && oti_ckd_mul_i64(nbytes, shape[k], &nbytes)){
                nd_init_empty(res);
                return OTI_ERR_SIZE;
            }
        }

        status = oti_ctx_check_temp(ctx, nbytes);

        if (status != OTI_OK){
            nd_init_empty(res);
            return status;
        }

    }

    for (k = 0; k < ndim; k++){
        if (shape[k] > 1){
            axes[nkept++] = k;
        }
    }

    ndi_k_sort(ins[ndi_driver(nin, ins, ndim, axes, nkept)], ndim, axes, nkept);

    for (k = 0; k < ndim; k++){
        perm[k]   = (shape[k] <= 1) ? k : axes[slot++];
        pshape[k] = shape[perm[k]];
    }

    status = ndb_contig_strides(ndim, pshape, ND_LAYOUT_C, pstr);

    if (status != OTI_OK){
        nd_init_empty(res);
        return status;
    }

    for (k = 0; k < ndim; k++){
        str[perm[k]] = pstr[k];
    }

    return ndb_alloc_strided(ctx, dtype, ndim, shape, str, 0, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A rank-0 temporary descriptor over a caller variable (a scalar operand of the given dtype); valid
// while *s lives.
static void nde_scalar_desc(const void* s, int32_t dtype, ndarr_t* d){

    d->data  = (void*)s;
    d->buf   = NULL;
    d->ndim  = 0;
    d->dtype = dtype;
    d->flags    = ND_C_CONTIG | ND_F_CONTIG;
    d->reserved = 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Elementwise kernels. Variables inside EXPR: a_ and b_ (binary), x_ (unary); k (nde_karg_t*).
// Binary kernels have bodies for all-contiguous runs and for a broadcast (stride 0) operand; the
// hoisted broadcast value never aliases the output (that overlap goes through a temporary).
#define NDE_BINARY_KERNEL(NAME, EXPR)                                                                \
static int NAME(void* arg, int64_t n, char* const* p, const int64_t* bs){                           \
    const nde_karg_t* k = (const nde_karg_t*)arg;                                                    \
    char* po = p[k->io];                                                                             \
    const char* pa = p[k->i0];                                                                       \
    const char* pb = p[k->i1];                                                                       \
    int64_t so = bs[k->io], sa = bs[k->i0], sb = bs[k->i1], i;                                       \
    if (so == 8 && sa == 8 && sb == 8){                                                              \
        double* o = (double*)po;                                                                     \
        const double* x = (const double*)pa;                                                         \
        const double* y = (const double*)pb;                                                         \
        for (i = 0; i < n; i++){ double a_ = x[i], b_ = y[i]; o[i] = (EXPR); }                       \
    } else if (so == 8 && sa == 8 && sb == 0){                                                       \
        double* o = (double*)po;                                                                     \
        const double* x = (const double*)pa;                                                         \
        const double b_ = *(const double*)pb;                                                        \
        for (i = 0; i < n; i++){ double a_ = x[i]; o[i] = (EXPR); }                                  \
    } else if (so == 8 && sa == 0 && sb == 8){                                                       \
        double* o = (double*)po;                                                                     \
        const double a_ = *(const double*)pa;                                                        \
        const double* y = (const double*)pb;                                                         \
        for (i = 0; i < n; i++){ double b_ = y[i]; o[i] = (EXPR); }                                  \
    } else {                                                                                         \
        for (i = 0; i < n; i++){                                                                     \
            double a_ = *(const double*)(pa + i * sa), b_ = *(const double*)(pb + i * sb);           \
            *(double*)(po + i * so) = (EXPR);                                                        \
        }                                                                                            \
    }                                                                                                \
    (void)k;                                                                                         \
    return OTI_OK;                                                                                   \
}

#define NDE_UNARY_KERNEL(NAME, EXPR)                                                                 \
static int NAME(void* arg, int64_t n, char* const* p, const int64_t* bs){                           \
    const nde_karg_t* k = (const nde_karg_t*)arg;                                                    \
    char* po = p[k->io];                                                                             \
    const char* pa = p[k->i0];                                                                       \
    int64_t so = bs[k->io], sa = bs[k->i0], i;                                                       \
    if (so == 8 && sa == 8){                                                                         \
        double* o = (double*)po;                                                                     \
        const double* x = (const double*)pa;                                                         \
        for (i = 0; i < n; i++){ double x_ = x[i]; o[i] = (EXPR); }                                  \
    } else {                                                                                         \
        for (i = 0; i < n; i++){                                                                     \
            double x_ = *(const double*)(pa + i * sa);                                               \
            *(double*)(po + i * so) = (EXPR);                                                        \
        }                                                                                            \
    }                                                                                                \
    (void)k;                                                                                         \
    return OTI_OK;                                                                                   \
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// numpy.maximum: NaN propagates (the first NaN operand), and +0.0 is larger than -0.0 (the IEEE
// 754-2019 maximum; NumPy 2.5.3 gives maximum(-0.0, 0.0) == maximum(0.0, -0.0) == +0.0).
static inline double nde_maximum(double a, double b){

    if (a != a){
        return a;
    }

    if (b != b){
        return b;
    }

    if (a == b){
        return signbit(a) ? b : a;
    }

    return (a > b) ? a : b;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// numpy.minimum: NaN propagates, and -0.0 is smaller than +0.0.
static inline double nde_minimum(double a, double b){

    if (a != a){
        return a;
    }

    if (b != b){
        return b;
    }

    if (a == b){
        return signbit(a) ? a : b;
    }

    return (a < b) ? a : b;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Binary arithmetic kernels (ND_OP_ADD ... ND_OP_MINIMUM).
NDE_BINARY_KERNEL(nde_k_add, a_ + b_)
NDE_BINARY_KERNEL(nde_k_sub, a_ - b_)
NDE_BINARY_KERNEL(nde_k_mul, a_ * b_)
NDE_BINARY_KERNEL(nde_k_div, a_ / b_)
NDE_BINARY_KERNEL(nde_k_pow, pow(a_, b_))
NDE_BINARY_KERNEL(nde_k_maximum, nde_maximum(a_, b_))
NDE_BINARY_KERNEL(nde_k_minimum, nde_minimum(a_, b_))
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Unary kernels of this file: neg and abs, and the scalar-exponent fast paths of POW (NumPy's:
// 2 -> x*x, 0.5 -> sqrt, -1 -> 1/x, 1 -> x, 0 -> 1). functions.c adds the libm functions.
NDE_UNARY_KERNEL(nde_u_neg, -x_)
NDE_UNARY_KERNEL(nde_u_abs, fabs(x_))
NDE_UNARY_KERNEL(nde_u_square, x_ * x_)
NDE_UNARY_KERNEL(nde_u_sqrt, sqrt(x_))
NDE_UNARY_KERNEL(nde_u_reciprocal, 1.0 / x_)
NDE_UNARY_KERNEL(nde_u_identity, x_)
NDE_UNARY_KERNEL(nde_u_one, ((void)x_, 1.0))
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Copy kernel for 8-byte elements (OTI_F64, OTI_I64): bit-exact (NaN payloads kept). Source and
// destination never overlap (callers go through a temporary otherwise).
static int nde_k_copy8(void* arg, int64_t n, char* const* p, const int64_t* bs){

    const nde_karg_t* k = (const nde_karg_t*)arg;
    char* po = p[k->io];
    const char* pa = p[k->i0];
    int64_t so = bs[k->io], sa = bs[k->i0], i;

    if (so == 8 && sa == 8){
        memcpy(po, pa, (size_t)n * 8);
        return OTI_OK;
    }

    for (i = 0; i < n; i++){
        memcpy(po + i * so, pa + i * sa, 8);
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Copy kernel for 1-byte elements (OTI_U8 masks), values kept as they are.
static int nde_k_copy1(void* arg, int64_t n, char* const* p, const int64_t* bs){

    const nde_karg_t* k = (const nde_karg_t*)arg;
    char* po = p[k->io];
    const char* pa = p[k->i0];
    int64_t so = bs[k->io], sa = bs[k->i0], i;

    if (so == 1 && sa == 1){
        memcpy(po, pa, (size_t)n);
        return OTI_OK;
    }

    for (i = 0; i < n; i++){
        po[i * so] = pa[i * sa];
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// OTI_U8 mask into OTI_F64: true (nonzero) is 1.0, false 0.0 (NumPy bool -> float64).
static int nde_k_u8_to_f64(void* arg, int64_t n, char* const* p, const int64_t* bs){

    const nde_karg_t* k = (const nde_karg_t*)arg;
    char* po = p[k->io];
    const uint8_t* pa = (const uint8_t*)p[k->i0];
    int64_t so = bs[k->io], sa = bs[k->i0], i;

    for (i = 0; i < n; i++){
        *(double*)(po + i * so) = (pa[i * sa] != 0) ? 1.0 : 0.0;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// OTI_I64 into OTI_F64 (C conversion, round to nearest for |v| > 2^53, as NumPy's int64 -> float64).
static int nde_k_i64_to_f64(void* arg, int64_t n, char* const* p, const int64_t* bs){

    const nde_karg_t* k = (const nde_karg_t*)arg;
    char* po = p[k->io];
    const char* pa = p[k->i0];
    int64_t so = bs[k->io], sa = bs[k->i0], i;

    for (i = 0; i < n; i++){
        *(double*)(po + i * so) = (double)*(const int64_t*)(pa + i * sa);
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fill kernel: every element of the run gets k->s.
static int nde_k_fill(void* arg, int64_t n, char* const* p, const int64_t* bs){

    const nde_karg_t* k = (const nde_karg_t*)arg;
    char* po = p[k->io];
    int64_t so = bs[k->io], i;
    double v = k->s;

    if (so == 8){

        double* o = (double*)po;

        for (i = 0; i < n; i++){
            o[i] = v;
        }

        return OTI_OK;

    }

    for (i = 0; i < n; i++){
        *(double*)(po + i * so) = v;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Copy kernel of a dtype (same dtype on both sides).
static inline nd_inner_fn nde_copy_kernel(int32_t dtype){

    return (dtype == OTI_U8) ? nde_k_copy1 : nde_k_copy8;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Copies src into dst (same shape and dtype, no overlap, dst writeable).
static int nde_copy_into(oti_ctx* ctx, const ndarr_t* src, ndarr_t* dst){

    const ndarr_t* ops[2];
    int32_t flags[2] = {ND_ITER_OUT, ND_ITER_IN};
    nde_karg_t k = {0, 1, 1, 0, 0.0};
    nd_inner_fn fn = nde_copy_kernel(dst->dtype);
    nd_iter_t it;
    int status;

    ops[0] = dst;
    ops[1] = src;

    if (nde_try_flat(ctx, fn, &k, NDE_NS_ARITH, 2, ops, 0, &status)){
        return status;
    }

    status = nd_iter_init(&it, 2, ops, flags, ND_ITER_ORDER_K);

    if (status != OTI_OK){
        return status;
    }

    return nde_run(ctx, &it, fn, &k, NDE_NS_ARITH);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// out = fn(in0[, in1]) with the aliasing rules of 3.4: in place for exact aliases, through a temporary
// (out's dtype, its K layout) for any other possible overlap. nin is 1 or 2; ns is the kernel
// family's cost per element. Statuses only (the public caller records errors).
static int nde_apply_to(oti_ctx* ctx, nd_inner_fn fn, double ns, int32_t nin, const ndarr_t* in0,
                        const ndarr_t* in1, ndarr_t* out){

    const ndarr_t* ops[3];
    int32_t flags[3] = {ND_ITER_OUT, ND_ITER_IN, ND_ITER_IN};
    nde_karg_t k = {0, 1, 2, 0, 0.0};
    const ndarr_t* like = out;
    nd_iter_t it;
    ndarr_t tmp;
    int status, need_tmp;

    if (nin == 1){
        k.i1 = 1;
    }

    ops[0] = out;
    ops[1] = in0;
    ops[2] = in1;

    if (nde_try_flat(ctx, fn, &k, ns, 1 + nin, ops, 0, &status)){
        return status;
    }

    status = nd_iter_init(&it, 1 + nin, ops, flags, ND_ITER_ORDER_K);

    if (status != OTI_OK){
        return status;
    }

    need_tmp = (nd_may_share_memory(out, in0) == ND_SHARE_MAYBE)
               || (nin == 2 && nd_may_share_memory(out, in1) == ND_SHARE_MAYBE);

    if (!need_tmp){
        return nde_run(ctx, &it, fn, &k, ns);
    }

    // Partial overlap: compute into a fresh array in out's K layout, then copy it into out.
    nd_init_empty(&tmp);
    status = nde_alloc_k(ctx, out->dtype, 1, &like, out->ndim, out->shape, 1, &tmp);

    if (status != OTI_OK){
        return status;
    }

    ops[0] = &tmp;

    if (!nde_try_flat(ctx, fn, &k, ns, 1 + nin, ops, 0, &status)){

        status = nd_iter_init(&it, 1 + nin, ops, flags, ND_ITER_ORDER_K);

        if (status == OTI_OK){
            status = nde_run(ctx, &it, fn, &k, ns);
        }

    }

    if (status == OTI_OK){
        status = nde_copy_into(ctx, &tmp, out);
    }

    nd_release(&tmp);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res = fn(ins[0][, ins[1]]) in a new array of dtype odt and the broadcast shape, in the K layout of
// the inputs (contracts S24, nde_alloc_k); the result is the iterator's last operand, so the driving
// input of the allocation also drives the walk. `swap` makes the kernel read ins[1] as its left
// operand (scalar-left variants, where ins[0] is the array). res is empty on failure.
static int nde_apply_new(oti_ctx* ctx, nd_inner_fn fn, double ns, int32_t odt, int32_t nin,
                         const ndarr_t* const* ins, int32_t swap, ndarr_t* res){

    const ndarr_t* ops[3];
    int32_t flags[3] = {ND_ITER_IN, ND_ITER_IN, ND_ITER_OUT};
    int64_t shape[OTI_ND_MAXDIM];
    nde_karg_t k = {0, 0, 1, 0, 0.0};
    nd_iter_t it;
    int32_t ndim, i;
    int status;

    nde_debug_res(res);

    status = ndi_broadcast_shape(nin, ins, NULL, 0, &ndim, shape);

    if (status != OTI_OK){
        nd_init_empty(res);
        return status;
    }

    status = nde_alloc_k(ctx, odt, nin, ins, ndim, shape, 0, res);

    if (status != OTI_OK){
        return status;
    }

    for (i = 0; i < nin; i++){
        ops[i] = ins[i];
    }

    ops[nin]   = res;
    flags[nin] = ND_ITER_OUT;
    k.io       = nin;
    k.i0       = swap ? 1 : 0;
    k.i1       = (nin == 1) ? 0 : (swap ? 0 : 1);

    if (!nde_try_flat(ctx, fn, &k, ns, nin + 1, ops, nin, &status)){

        status = nd_iter_init(&it, nin + 1, ops, flags, ND_ITER_ORDER_K);

        if (status == OTI_OK){
            status = nde_run(ctx, &it, fn, &k, ns);
        }

    }

    if (status != OTI_OK){
        nd_release(res);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The kernel, dtypes and cost of a binary operation: arithmetic here (OTI_F64 -> OTI_F64),
// comparisons and logical operations in mask.c. Returns 0 for an unknown operation.
static int nde_binary_info(int32_t op, nde_opinfo_t* info){

    info->in_dtype  = OTI_F64;
    info->out_dtype = OTI_F64;
    info->ns        = NDE_NS_ARITH;

    switch (op){
    case ND_OP_ADD:
        info->fn = nde_k_add;
        return 1;
    case ND_OP_SUB:
        info->fn = nde_k_sub;
        return 1;
    case ND_OP_MUL:
        info->fn = nde_k_mul;
        return 1;
    case ND_OP_DIV:
        info->fn = nde_k_div;
        info->ns = NDE_NS_DIV;
        return 1;
    case ND_OP_POW:
        info->fn = nde_k_pow;
        info->ns = NDE_NS_POW;
        return 1;
    case ND_OP_MAXIMUM:
        info->fn = nde_k_maximum;
        info->ns = NDE_NS_DIV;
        return 1;
    case ND_OP_MINIMUM:
        info->fn = nde_k_minimum;
        info->ns = NDE_NS_DIV;
        return 1;
    default:
        return ndm_binary_info(op, info);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Unary kernel of a scalar exponent with a NumPy fast path (elementwise.h), or NULL. All run at
// the cost of arithmetic except sqrt (NDE_NS_DIV, set by the caller).
static nd_inner_fn nde_pow_fast_kernel(double s){

    if (s == 2.0){
        return nde_u_square;
    }

    if (s == 0.5){
        return nde_u_sqrt;
    }

    if (s == -1.0){
        return nde_u_reciprocal;
    }

    if (s == 1.0){
        return nde_u_identity;
    }

    if (s == 0.0){
        return nde_u_one;
    }

    return NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Argument checks shared by the binary entry points: operands present, operation known, operand
// dtypes as the operation takes them (out is NULL for the allocating variants).
static int nde_binary_check(int32_t op, const ndarr_t* a, const ndarr_t* b, const ndarr_t* out,
                            nde_opinfo_t* info){

    if (a == NULL || b == NULL || !nde_binary_info(op, info)){
        return OTI_ERR_ARGUMENT;
    }

    nde_debug_input(a);
    nde_debug_input(b);
    nde_debug_input(out);

    if (a->dtype != info->in_dtype || b->dtype != info->in_dtype
        || (out != NULL && out->dtype != info->out_dtype)){
        return OTI_ERR_DTYPE;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_binary_to(oti_ctx* ctx, int32_t op, const ndarr_t* a, const ndarr_t* b, ndarr_t* out){

    nde_opinfo_t info;
    int status = oti_ctx_check(ctx);

    if (status == OTI_OK){
        status = (out == NULL) ? OTI_ERR_ARGUMENT : nde_binary_check(op, a, b, out, &info);
    }

    if (status == OTI_OK){
        status = nde_apply_to(ctx, info.fn, info.ns, 2, a, b, out);
    }

    if (status != OTI_OK){
        oti_ctx_set_error(ctx, status, "nd_binary_to", NULL);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_binary(oti_ctx* ctx, int32_t op, const ndarr_t* a, const ndarr_t* b, ndarr_t* res){

    const ndarr_t* ins[2];
    nde_opinfo_t info;
    int status;

    if (res == NULL){
        status = OTI_ERR_ARGUMENT;
    } else {

        nde_debug_res(res);
        status = oti_ctx_check(ctx);

        if (status == OTI_OK){
            status = nde_binary_check(op, a, b, NULL, &info);
        }

        if (status == OTI_OK){
            ins[0] = a;
            ins[1] = b;
            status = nde_apply_new(ctx, info.fn, info.ns, info.out_dtype, 2, ins, 0, res);
        } else {
            nd_init_empty(res);
        }

    }

    if (status != OTI_OK){
        oti_ctx_set_error(ctx, status, "nd_binary", NULL);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks of the scalar variants (out is NULL for the allocating one).
static int nde_scalar_check(int32_t op, const ndarr_t* a, int32_t scalar_left, const ndarr_t* out,
                            nde_opinfo_t* info){

    if (a == NULL || !nde_binary_info(op, info) || (scalar_left != 0 && scalar_left != 1)){
        return OTI_ERR_ARGUMENT;
    }

    nde_debug_input(a);
    nde_debug_input(out);

    if (a->dtype != info->in_dtype || (out != NULL && out->dtype != info->out_dtype)){
        return OTI_ERR_DTYPE;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The scalar operand of a scalar variant as a rank-0 descriptor of the operation's input dtype: the
// double itself, or for the logical operations its truth value (NaN is true, as bool(nan)). *u8 is
// the storage of the latter.
static void nde_scalar_operand(const nde_opinfo_t* info, const double* s, uint8_t* u8, ndarr_t* sd){

    if (info->in_dtype == OTI_U8){
        *u8 = (uint8_t)(*s != 0.0);
        nde_scalar_desc(u8, OTI_U8, sd);
    } else {
        nde_scalar_desc(s, OTI_F64, sd);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_binary_scalar_to(oti_ctx* ctx, int32_t op, const ndarr_t* a, double s, int32_t scalar_left,
                        ndarr_t* out){

    nd_inner_fn fast = NULL;
    nde_opinfo_t info;
    ndarr_t sd;
    uint8_t u8;
    int status = oti_ctx_check(ctx);

    if (status == OTI_OK){
        status = (out == NULL) ? OTI_ERR_ARGUMENT : nde_scalar_check(op, a, scalar_left, out, &info);
    }

    if (status == OTI_OK){

        if (op == ND_OP_POW && !scalar_left){
            fast = nde_pow_fast_kernel(s);
        }

        if (fast != NULL){
            status = nde_apply_to(ctx, fast, (s == 0.5) ? NDE_NS_DIV : NDE_NS_ARITH, 1, a, NULL, out);
        } else {
            nde_scalar_operand(&info, &s, &u8, &sd);
            status = scalar_left ? nde_apply_to(ctx, info.fn, info.ns, 2, &sd, a, out)
                                 : nde_apply_to(ctx, info.fn, info.ns, 2, a, &sd, out);
        }

    }

    if (status != OTI_OK){
        oti_ctx_set_error(ctx, status, "nd_binary_scalar_to", NULL);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_binary_scalar(oti_ctx* ctx, int32_t op, const ndarr_t* a, double s, int32_t scalar_left,
                     ndarr_t* res){

    nd_inner_fn fast = NULL;
    const ndarr_t* ins[2];
    nde_opinfo_t info;
    ndarr_t sd;
    uint8_t u8;
    int status;

    if (res == NULL){
        status = OTI_ERR_ARGUMENT;
    } else {

        nde_debug_res(res);
        status = oti_ctx_check(ctx);

        if (status == OTI_OK){
            status = nde_scalar_check(op, a, scalar_left, NULL, &info);
        }

        if (status == OTI_OK){

            if (op == ND_OP_POW && !scalar_left){
                fast = nde_pow_fast_kernel(s);
            }

            ins[0] = a;

            if (fast != NULL){
                status = nde_apply_new(ctx, fast, (s == 0.5) ? NDE_NS_DIV : NDE_NS_ARITH, OTI_F64, 1,
                                       ins, 0, res);
            } else {
                nde_scalar_operand(&info, &s, &u8, &sd);
                ins[1] = &sd;
                status = nde_apply_new(ctx, info.fn, info.ns, info.out_dtype, 2, ins, scalar_left,
                                       res);
            }

        } else {
            nd_init_empty(res);
        }

    }

    if (status != OTI_OK){
        oti_ctx_set_error(ctx, status, "nd_binary_scalar", NULL);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Kernel converting src's dtype into dst's for nd_assign(), or NULL (OTI_ERR_DTYPE): the same dtype,
// or OTI_U8 / OTI_I64 into OTI_F64.
static nd_inner_fn nde_assign_kernel(int32_t dst_dtype, int32_t src_dtype){

    if (dst_dtype == src_dtype){
        return nde_copy_kernel(dst_dtype);
    }

    if (dst_dtype == OTI_F64 && src_dtype == OTI_U8){
        return nde_k_u8_to_f64;
    }

    if (dst_dtype == OTI_F64 && src_dtype == OTI_I64){
        return nde_k_i64_to_f64;
    }

    return NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A temporary view of src broadcast to dst's shape, NumPy's assignment rule: leading axes of extent 1
// beyond dst's rank are dropped, an extent of 1 stretches (stride 0), anything else is OTI_ERR_SHAPE.
static int nde_broadcast_view(const ndarr_t* src, const ndarr_t* dst, ndarr_t* v){

    int32_t lead = src->ndim - dst->ndim;
    int32_t k;

    for (k = 0; k < lead; k++){
        if (src->shape[k] != 1){
            return OTI_ERR_SHAPE;
        }
    }

    memset(v, 0, sizeof(*v));
    v->data  = src->data;
    v->dtype = src->dtype;
    v->ndim  = dst->ndim;

    for (k = 0; k < dst->ndim; k++){

        int32_t d = k + lead;

        v->shape[k] = dst->shape[k];

        if (d < 0 || src->shape[d] == 1){
            v->strides[k] = 0;
        } else if (src->shape[d] == dst->shape[k]){
            v->strides[k] = src->strides[d];
        } else {
            return OTI_ERR_SHAPE;
        }

    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// dst[...] = src with dst's checks done by the iterator (shape, writeability, overlap).
static int nde_assign(oti_ctx* ctx, const ndarr_t* src, ndarr_t* dst){

    const ndarr_t* ops[2];
    int32_t flags[2] = {ND_ITER_OUT, ND_ITER_IN};
    nde_karg_t k = {0, 1, 1, 0, 0.0};
    nd_inner_fn fn = nde_assign_kernel(dst->dtype, src->dtype);
    nd_iter_t it;
    ndarr_t view, tmp;
    int status, share;

    if (fn == NULL){
        return OTI_ERR_DTYPE;
    }

    // Trivial path: same layout or a single element, no overlap except dst being src itself.
    ops[0] = dst;
    ops[1] = src;

    if (nde_try_flat(ctx, fn, &k, NDE_NS_ARITH, 2, ops, 0, &status)){
        return status;
    }

    status = nde_broadcast_view(src, dst, &view);

    if (status != OTI_OK){
        return status;
    }

    ops[1] = &view;
    status = nd_iter_init(&it, 2, ops, flags, ND_ITER_ORDER_K);

    if (status != OTI_OK){
        return status;
    }

    share = nd_may_share_memory(dst, src);

    if (share == ND_SHARE_EXACT){
        return OTI_OK;      // dst is src: nothing changes.
    }

    if (share == ND_SHARE_NONE){
        return nde_run(ctx, &it, fn, &k, NDE_NS_ARITH);
    }

    // Snapshot semantics: copy src first, then assign from the copy.
    nd_init_empty(&tmp);
    status = nde_alloc_k(ctx, src->dtype, 1, &src, src->ndim, src->shape, 1, &tmp);

    if (status != OTI_OK){
        return status;
    }

    status = nde_copy_into(ctx, src, &tmp);

    if (status == OTI_OK){
        status = nde_broadcast_view(&tmp, dst, &view);
    }

    if (status == OTI_OK){
        status = nd_iter_init(&it, 2, ops, flags, ND_ITER_ORDER_K);
    }

    if (status == OTI_OK){
        status = nde_run(ctx, &it, fn, &k, NDE_NS_ARITH);
    }

    nd_release(&tmp);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_assign(oti_ctx* ctx, const ndarr_t* src, ndarr_t* dst){

    int status = oti_ctx_check(ctx);

    if (status == OTI_OK && (src == NULL || dst == NULL)){
        status = OTI_ERR_ARGUMENT;
    }

    if (status == OTI_OK){
        nde_debug_input(src);
        nde_debug_input(dst);
        status = nde_assign(ctx, src, dst);
    }

    if (status != OTI_OK){
        oti_ctx_set_error(ctx, status, "nd_assign", NULL);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Argument checks of nd_fill(): destination present and OTI_F64.
static int nde_fill_check(const ndarr_t* dst){

    if (dst == NULL){
        return OTI_ERR_ARGUMENT;
    }

    nde_debug_input(dst);

    return (dst->dtype != OTI_F64) ? OTI_ERR_DTYPE : OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_fill(oti_ctx* ctx, ndarr_t* dst, double value){

    const ndarr_t* ops[1];
    int32_t flags[1] = {ND_ITER_OUT};
    nde_karg_t k = {0, 0, 0, 0, 0.0};
    nd_iter_t it;
    int status = oti_ctx_check(ctx);

    if (status == OTI_OK){
        status = nde_fill_check(dst);
    }

    if (status == OTI_OK){

        ops[0] = dst;
        k.s    = value;

        if (!nde_try_flat(ctx, nde_k_fill, &k, NDE_NS_ARITH, 1, ops, 0, &status)){

            status = nd_iter_init(&it, 1, ops, flags, ND_ITER_ORDER_K);

            if (status == OTI_OK){
                status = nde_run(ctx, &it, nde_k_fill, &k, NDE_NS_ARITH);
            }

        }

    }

    if (status != OTI_OK){
        oti_ctx_set_error(ctx, status, "nd_fill", NULL);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------
