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
//   - the driver: nd_iter_init() over (out, inputs) in ND_ITER_ORDER_K, then the iteration space cut
//     into fixed logical chunks of OTI_EXEC_CHUNK_ELEMS linear indices, each walked by nd_iter_run()
//     (nde_run). Phase 1 runs the chunks with oti_serial_for(); Phase 2 hands the same chunks to
//     oti_parallel_for() (nde_chunk is already a valid chunk function: it writes only its own range
//     and records no error);
//   - aliasing (contracts 3.4): an input that is exactly `out` (ND_SHARE_EXACT) is computed in place;
//     any other possible overlap (ND_SHARE_MAYBE) computes into a temporary charged to the temp
//     budget, then copies it into `out`. Assignment copies a possibly overlapping source first
//     (snapshot semantics); an exact alias is a no-op.
// Comparisons and mask operators (ND_OP_EQ ... ND_OP_XOR, ND_FN_NOT) are Phase 2 (mask.c): until then
// they are OTI_ERR_ARGUMENT, the status documented for an unknown operation.

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
// Runs a prepared iterator in fixed logical chunks. Phase 1 is serial; Phase 2 switches to
// oti_parallel_for() when oti_exec_parallel_ok(ctx, it->size, 0) holds, with the same chunks.
static int nde_run(oti_ctx* ctx, const nd_iter_t* it, nd_inner_fn fn, void* arg){

    nde_job_t job;

    (void)ctx;
    job.it  = it;
    job.fn  = fn;
    job.arg = arg;

    return oti_serial_for(oti_exec_nchunks(it->size, OTI_EXEC_CHUNK_ELEMS), nde_chunk, &job);

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
// A rank-0 temporary descriptor over a caller variable (a scalar operand); valid while *s lives.
static void nde_scalar_desc(const double* s, ndarr_t* d){

    memset(d, 0, sizeof(*d));
    d->data  = (void*)s;
    d->ndim  = 0;
    d->dtype = OTI_F64;
    d->flags = ND_C_CONTIG | ND_F_CONTIG;

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
    nd_iter_t it;
    int status;

    ops[0] = dst;
    ops[1] = src;
    status = nd_iter_init(&it, 2, ops, flags, ND_ITER_ORDER_K);

    if (status != OTI_OK){
        return status;
    }

    return nde_run(ctx, &it, nde_copy_kernel(dst->dtype), &k);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// out = fn(in0[, in1]) with the aliasing rules of 3.4: in place for exact aliases, through a temporary
// for any other possible overlap. nin is 1 or 2. Statuses only (the public caller records errors).
static int nde_apply_to(oti_ctx* ctx, nd_inner_fn fn, int32_t nin, const ndarr_t* in0,
                        const ndarr_t* in1, ndarr_t* out){

    const ndarr_t* ops[3];
    int32_t flags[3] = {ND_ITER_OUT, ND_ITER_IN, ND_ITER_IN};
    nde_karg_t k = {0, 1, 2, 0, 0.0};
    nd_iter_t it;
    const ndarr_t* like = out;
    ndarr_t tmp;
    int status, need_tmp;

    if (nin == 1){
        k.i1 = 1;
    }

    ops[0] = out;
    ops[1] = in0;
    ops[2] = in1;
    status = nd_iter_init(&it, 1 + nin, ops, flags, ND_ITER_ORDER_K);

    if (status != OTI_OK){
        return status;
    }

    need_tmp = (nd_may_share_memory(out, in0) == ND_SHARE_MAYBE)
               || (nin == 2 && nd_may_share_memory(out, in1) == ND_SHARE_MAYBE);

    if (!need_tmp){
        return nde_run(ctx, &it, fn, &k);
    }

    // Partial overlap: compute into a fresh array in out's K layout, then copy it into out.
    nd_init_empty(&tmp);
    status = nde_alloc_k(ctx, OTI_F64, 1, &like, out->ndim, out->shape, 1, &tmp);

    if (status != OTI_OK){
        return status;
    }

    ops[0] = &tmp;
    status = nd_iter_init(&it, 1 + nin, ops, flags, ND_ITER_ORDER_K);

    if (status == OTI_OK){
        status = nde_run(ctx, &it, fn, &k);
    }

    if (status == OTI_OK){
        status = nde_copy_into(ctx, &tmp, out);
    }

    nd_release(&tmp);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res = fn(ins[0][, ins[1]]) in a new OTI_F64 array of the broadcast shape in the K layout of the
// inputs (contracts S24, nde_alloc_k); the result is the iterator's last operand, so the driving
// input of the allocation also drives the walk. `swap` makes the kernel read ins[1] as its left
// operand (scalar-left variants, where ins[0] is the array). res is empty on failure.
static int nde_apply_new(oti_ctx* ctx, nd_inner_fn fn, int32_t nin, const ndarr_t* const* ins,
                         int32_t swap, ndarr_t* res){

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

    status = nde_alloc_k(ctx, OTI_F64, nin, ins, ndim, shape, 0, res);

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

    status = nd_iter_init(&it, nin + 1, ops, flags, ND_ITER_ORDER_K);

    if (status == OTI_OK){
        status = nde_run(ctx, &it, fn, &k);
    }

    if (status != OTI_OK){
        nd_release(res);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Kernel of a binary arithmetic operation, or NULL (unknown, or a Phase 2 comparison / mask operator).
static nd_inner_fn nde_binary_kernel(int32_t op){

    switch (op){
    case ND_OP_ADD:
        return nde_k_add;
    case ND_OP_SUB:
        return nde_k_sub;
    case ND_OP_MUL:
        return nde_k_mul;
    case ND_OP_DIV:
        return nde_k_div;
    case ND_OP_POW:
        return nde_k_pow;
    case ND_OP_MAXIMUM:
        return nde_k_maximum;
    case ND_OP_MINIMUM:
        return nde_k_minimum;
    default:
        return NULL;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Unary kernel of a scalar exponent with a NumPy fast path (elementwise.h), or NULL.
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
// Argument checks shared by the binary entry points: operands present, operation known, OTI_F64.
static int nde_binary_check(int32_t op, const ndarr_t* a, const ndarr_t* b, const ndarr_t* out){

    if (a == NULL || b == NULL || out == NULL || nde_binary_kernel(op) == NULL){
        return OTI_ERR_ARGUMENT;
    }

    nde_debug_input(a);
    nde_debug_input(b);
    nde_debug_input(out);

    if (a->dtype != OTI_F64 || b->dtype != OTI_F64 || out->dtype != OTI_F64){
        return OTI_ERR_DTYPE;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_binary_to(oti_ctx* ctx, int32_t op, const ndarr_t* a, const ndarr_t* b, ndarr_t* out){

    int status = oti_ctx_check(ctx);

    if (status == OTI_OK){
        status = nde_binary_check(op, a, b, out);
    }

    if (status == OTI_OK){
        status = nde_apply_to(ctx, nde_binary_kernel(op), 2, a, b, out);
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
    int status;

    if (res == NULL){
        status = OTI_ERR_ARGUMENT;
    } else {

        // out stands in for res in the dtype check; res is overwritten anyway.
        nde_debug_res(res);
        status = oti_ctx_check(ctx);

        if (status == OTI_OK){
            status = (a == NULL) ? OTI_ERR_ARGUMENT : nde_binary_check(op, a, b, a);
        }

        if (status == OTI_OK){
            ins[0] = a;
            ins[1] = b;
            status = nde_apply_new(ctx, nde_binary_kernel(op), 2, ins, 0, res);
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
// Checks of the scalar variants (out may be NULL for the allocating one).
static int nde_scalar_check(int32_t op, const ndarr_t* a, int32_t scalar_left, const ndarr_t* out){

    if (a == NULL || nde_binary_kernel(op) == NULL || (scalar_left != 0 && scalar_left != 1)){
        return OTI_ERR_ARGUMENT;
    }

    nde_debug_input(a);
    nde_debug_input(out);

    if (a->dtype != OTI_F64 || (out != NULL && out->dtype != OTI_F64)){
        return OTI_ERR_DTYPE;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_binary_scalar_to(oti_ctx* ctx, int32_t op, const ndarr_t* a, double s, int32_t scalar_left,
                        ndarr_t* out){

    nd_inner_fn fast = NULL;
    ndarr_t sd;
    int status = oti_ctx_check(ctx);

    if (status == OTI_OK){
        status = (out == NULL) ? OTI_ERR_ARGUMENT : nde_scalar_check(op, a, scalar_left, out);
    }

    if (status == OTI_OK){

        if (op == ND_OP_POW && !scalar_left){
            fast = nde_pow_fast_kernel(s);
        }

        if (fast != NULL){
            status = nde_apply_to(ctx, fast, 1, a, NULL, out);
        } else {
            nde_scalar_desc(&s, &sd);
            status = scalar_left ? nde_apply_to(ctx, nde_binary_kernel(op), 2, &sd, a, out)
                                 : nde_apply_to(ctx, nde_binary_kernel(op), 2, a, &sd, out);
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
    ndarr_t sd;
    int status;

    if (res == NULL){
        status = OTI_ERR_ARGUMENT;
    } else {

        nde_debug_res(res);
        status = oti_ctx_check(ctx);

        if (status == OTI_OK){
            status = nde_scalar_check(op, a, scalar_left, NULL);
        }

        if (status == OTI_OK){

            if (op == ND_OP_POW && !scalar_left){
                fast = nde_pow_fast_kernel(s);
            }

            ins[0] = a;

            if (fast != NULL){
                status = nde_apply_new(ctx, fast, 1, ins, 0, res);
            } else {
                nde_scalar_desc(&s, &sd);
                ins[1] = &sd;
                status = nde_apply_new(ctx, nde_binary_kernel(op), 2, ins, scalar_left, res);
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

    status = nde_broadcast_view(src, dst, &view);

    if (status != OTI_OK){
        return status;
    }

    ops[0] = dst;
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
        return nde_run(ctx, &it, fn, &k);
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
        status = nde_run(ctx, &it, fn, &k);
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
        status = nd_iter_init(&it, 1, ops, flags, ND_ITER_ORDER_K);

        if (status == OTI_OK){
            status = nde_run(ctx, &it, nde_k_fill, &k);
        }

    }

    if (status != OTI_OK){
        oti_ctx_set_error(ctx, status, "nd_fill", NULL);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------
