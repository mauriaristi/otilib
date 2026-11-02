// ndarray BLAS dispatch (Phase 3; PLAN-ndarray-contracts.md 9.1, 9.2, S14, S15): products and
// level-1/2 helpers on OTI_F64 arrays, through the C wrappers of include/oti/core/lapack.h only.
// Included from src/c/real_ndarray.c; file-static helpers carry the ndbl_ prefix. linalg.c (included
// next) reuses the batch runner and the per-worker scratch defined here.
//
// Dispatch rules (contracts 9.1): a 2-D operand (n0, n1) with strides (s0, s1) is passed directly as
// 'N' or 'T' when its strides allow it (singleton extents normalized), else packed into an F-order
// temporary. The output C is used directly ('N'), computed as C^T = B^T A^T ('T'), or through an F
// temporary. Every narrowed value passes oti_lapack_fits_i64() and oti_lapack_int_limit(); empty
// problems never reach the provider. Every matrix of a batch shares the 2-D strides, so the decision
// ("plan") is made once and applied per matrix.

#include <math.h>
#include <string.h>

#include "oti/core/lapack.h"

// NDBL_COST: estimated serial cost of one provider call, ns = fixed + rate * multiply-adds (S28). The
// one table of these constants; they decide the team size of batch loops only, never the results.
// Measured on the development machine (Apple M-series, 10P + 4E cores, conda OpenBLAS 0.3.34, one
// thread) in reports/2026-11-02-ndarray-w2/review-critic.md, tables C2 (raw calls) and D (per call
// at FEM sizes); tools/bench/bench_blas_batch.c measures the same quantities on other machines.
//   dgemm  m x n x k: 80 ns + 0.047 ns per m*n*k       (C2: 8 -> 101 ns, 32 -> 1 407, 100 -> 48 865)
//   dgetrf n:        400 ns + 0.10 ns per n^3 (n <= 32), 0.03 above   (C2 memcpy + dgetrf: 8 -> 427,
//                    32 -> 4 508, 100 -> 32 416)
//   dgetrs n, k:     250 ns + 0.06 ns per n*n*k        (C1 / D: solve minus factor)
//   dgetri n:        300 ns + 0.067 ns per n^3         (D: inv minus lu, 8 -> 328, 100 -> 67 355)
//   dpotrf n:        200 ns + 0.05 ns per n^3          (not measured: half of dgetrf, an estimate)
//   det / slogdet:   dgetrf + 60 ns (log / exp, D)
#define NDBL_GEMM_NS              80.0
#define NDBL_GEMM_NS_FMA           0.047
#define NDBL_GETRF_NS            400.0
#define NDBL_GETRF_NS_FMA_SMALL    0.10
#define NDBL_GETRF_NS_FMA          0.03
#define NDBL_GETRS_NS            250.0
#define NDBL_GETRS_NS_FMA          0.06
#define NDBL_GETRI_NS            300.0
#define NDBL_GETRI_NS_FMA          0.067
#define NDBL_POTRF_NS            200.0
#define NDBL_POTRF_NS_FMA          0.05
#define NDBL_DET_NS               60.0

// Floors of a parallel batch loop (S28): an item of at least 1 us and chunks of at least 50 us of
// estimated serial work; below them OpenBLAS's small-call path gains nothing and loses up to 2.5x
// (critic table C2).
#define NDBL_MIN_ITEM_NS        1000.0
#define NDBL_MIN_CHUNK_NS      50000.0

// A 2-D strided operand: element (i, j) at p[i * s0 + j * s1].
typedef struct {
    double*  p;
    int64_t  n0, n1;
    int64_t  s0, s1;
} ndbl_m2_t;

// A strided vector: element i at p[i * s].
typedef struct {
    double*  p;
    int64_t  n;
    int64_t  s;
} ndbl_v_t;

// Plan of one 2-D product C (m, n) = alpha A (m, k) B (k, n) + beta C, made from shapes and strides.
typedef struct {
    int32_t   kind;     // 0: nothing to do; 1: k == 0 (C = beta C or 0); 2: one dgemm
    int32_t   swap;     // 1: computed as C^T = B^T A^T (A' = B^T, B' = A^T, C' = C^T)
    int32_t   pack_a;   // 1: A' is packed into scratch + off_a (F, ld = max(1, m))
    int32_t   pack_b;   // 1: B' is packed into scratch + off_b (F, ld = max(1, k))
    int32_t   tmp_c;    // 1: C' goes through an F temporary at scratch + off_c
    char      ta, tb;   // 'N' / 'T' of A' and B' as stored
    int64_t   m, n, k;  // of the product actually called (after the swap)
    int64_t   lda, ldb, ldc;
    ndbl_m2_t a, b, c;  // A', B', C' shapes and strides (p unused)
    int64_t   off_a, off_b, off_c;
    int64_t   scratch;  // doubles of scratch per product
} ndbl_plan_t;

// Per-worker scratch of a batch loop: one lazily allocated block per worker slot.
typedef struct {
    void**   slot;
    int32_t  nslots;
    int64_t  nbytes;    // bytes of each block
} ndbl_scratch_t;

// Item function of a batch loop: one matrix (or problem) of index `item`.
typedef int (*ndbl_item_fn)(void* arg, int64_t item, int32_t worker);

// Chunk argument of the batch loop (groups of consecutive items).
typedef struct {
    ndbl_item_fn fn;
    void*        arg;
    int64_t      nitems;
    int64_t      per_chunk;
} ndbl_batch_t;


// *******************************************************************************************************
// Debug builds assert that every input is well formed and every `res` empty or a temporary.
static inline void ndbl_debug_input(const ndarr_t* a){

#ifdef OTI_ND_DEBUG
    assert(a == NULL || nd_validate(a, NULL, NULL, 0) == OTI_OK);
#else
    (void)a;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static inline void ndbl_debug_res(const ndarr_t* res){

#ifdef OTI_ND_DEBUG
    assert(res == NULL || !(res->flags & ND_RETAINED));
#else
    (void)res;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 when v may be narrowed to a LAPACK int: oti_lapack_fits_i64() and |v| <= oti_lapack_int_limit().
static inline int ndbl_fits(int64_t v){

    return oti_lapack_fits_i64(v) && (v < 0 ? -v : v) <= oti_lapack_int_limit();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static inline int64_t ndbl_max1(int64_t v){

    return v > 1 ? v : 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The 2-D operand of axes (ax0, ax1) of a (a->data at element (0, ..., 0)).
static inline ndbl_m2_t ndbl_m2_of(const ndarr_t* a, int32_t ax0, int32_t ax1){

    ndbl_m2_t x;

    x.p  = (double*)a->data;
    x.n0 = a->shape[ax0];
    x.s0 = a->strides[ax0];
    x.n1 = a->shape[ax1];
    x.s1 = a->strides[ax1];

    return x;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static inline ndbl_m2_t ndbl_m2_t_of(ndbl_m2_t x){

    ndbl_m2_t t;

    t.p  = x.p;
    t.n0 = x.n1;
    t.n1 = x.n0;
    t.s0 = x.s1;
    t.s1 = x.s0;

    return t;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// usable_N (contracts 9.1): the stored column-major matrix is x itself, with leading dimension *ld.
static inline int ndbl_usable_n(const ndbl_m2_t* x, int64_t* ld){

    if ((x->n0 <= 1 || x->s0 == 1) && (x->n1 <= 1 || x->s1 >= ndbl_max1(x->n0))){
        *ld = x->n1 <= 1 ? ndbl_max1(x->n0) : x->s1;
        return 1;
    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// usable_T (contracts 9.1): the stored column-major matrix is x^T, with leading dimension *ld.
static inline int ndbl_usable_t(const ndbl_m2_t* x, int64_t* ld){

    if ((x->n1 <= 1 || x->s1 == 1) && (x->n0 <= 1 || x->s0 >= ndbl_max1(x->n1))){
        *ld = x->n0 <= 1 ? ndbl_max1(x->n1) : x->s0;
        return 1;
    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Copies x into an F-order buffer with leading dimension ld.
static void ndbl_pack2(const ndbl_m2_t* x, double* dst, int64_t ld){

    int64_t i, j;

    for (j = 0; j < x->n1; j++){

        const double* src = x->p + j * x->s1;
        double*       d   = dst + j * ld;

        for (i = 0; i < x->n0; i++){
            d[i] = src[i * x->s0];
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Copies an F-order buffer with leading dimension ld into x.
static void ndbl_unpack2(const double* src, int64_t ld, const ndbl_m2_t* x){

    int64_t i, j;

    for (j = 0; j < x->n1; j++){

        const double* s = src + j * ld;
        double*       d = x->p + j * x->s1;

        for (i = 0; i < x->n0; i++){
            d[i * x->s0] = s[i];
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// x = beta * x, or 0.0 when beta == 0 (never propagates a NaN of x).
static void ndbl_scale2(const ndbl_m2_t* x, double beta){

    int64_t i, j;

    for (j = 0; j < x->n1; j++){

        double* d = x->p + j * x->s1;

        for (i = 0; i < x->n0; i++){
            d[i * x->s0] = beta == 0.0 ? 0.0 : beta * d[i * x->s0];
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Makes the plan of C = alpha A B + beta C from the shapes and strides of a (m, k), b (k, n) and
// c (m, n). OTI_ERR_SIZE when a narrowed value or the scratch count does not fit.
static int ndbl_plan_gemm(ndbl_m2_t a, ndbl_m2_t b, ndbl_m2_t c, ndbl_plan_t* pl){

    int64_t ld, t;

    memset(pl, 0, sizeof(*pl));

    if (c.n0 == 0 || c.n1 == 0){
        return OTI_OK;                                 // kind 0
    }
    if (a.n1 == 0){
        pl->kind = 1;
        pl->c    = c;
        return OTI_OK;
    }

    pl->kind = 2;

    // Output: direct, transposed problem, or an F temporary.
    if (!ndbl_usable_n(&c, &ld) && ndbl_usable_t(&c, &ld)){
        ndbl_m2_t a2 = ndbl_m2_t_of(b);
        ndbl_m2_t b2 = ndbl_m2_t_of(a);
        a = a2;
        b = b2;
        c = ndbl_m2_t_of(c);
        pl->swap = 1;
    }

    pl->m = c.n0;
    pl->n = c.n1;
    pl->k = a.n1;
    pl->a = a;
    pl->b = b;
    pl->c = c;

    if (ndbl_usable_n(&c, &ld)){
        pl->ldc = ld;
    } else {
        pl->tmp_c = 1;
        pl->ldc   = ndbl_max1(pl->m);
    }

    if (ndbl_usable_n(&a, &ld)){
        pl->ta  = 'N';
        pl->lda = ld;
    } else if (ndbl_usable_t(&a, &ld)){
        pl->ta  = 'T';
        pl->lda = ld;
    } else {
        pl->ta     = 'N';
        pl->pack_a = 1;
        pl->lda    = ndbl_max1(pl->m);
    }

    if (ndbl_usable_n(&b, &ld)){
        pl->tb  = 'N';
        pl->ldb = ld;
    } else if (ndbl_usable_t(&b, &ld)){
        pl->tb  = 'T';
        pl->ldb = ld;
    } else {
        pl->tb     = 'N';
        pl->pack_b = 1;
        pl->ldb    = ndbl_max1(pl->k);
    }

    if (!ndbl_fits(pl->m) || !ndbl_fits(pl->n) || !ndbl_fits(pl->k) || !ndbl_fits(pl->lda)
        || !ndbl_fits(pl->ldb) || !ndbl_fits(pl->ldc)){
        return OTI_ERR_SIZE;
    }

    // Scratch layout: [A' pack][B' pack][C' temporary], each m*k, k*n, m*n doubles when used.
    pl->scratch = 0;

    if (pl->pack_a){
        pl->off_a = pl->scratch;
        if (oti_ckd_mul_i64(pl->m, pl->k, &t) || oti_ckd_add_i64(pl->scratch, t, &pl->scratch)){
            return OTI_ERR_SIZE;
        }
    }
    if (pl->pack_b){
        pl->off_b = pl->scratch;
        if (oti_ckd_mul_i64(pl->k, pl->n, &t) || oti_ckd_add_i64(pl->scratch, t, &pl->scratch)){
            return OTI_ERR_SIZE;
        }
    }
    if (pl->tmp_c){
        pl->off_c = pl->scratch;
        if (oti_ckd_mul_i64(pl->m, pl->n, &t) || oti_ckd_add_i64(pl->scratch, t, &pl->scratch)){
            return OTI_ERR_SIZE;
        }
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs a plan on one product: pa, pb, pc are element (0, 0) of the ORIGINAL a, b, c; scratch holds
// pl->scratch doubles (may be NULL when 0).
static void ndbl_exec_gemm(const ndbl_plan_t* pl, double alpha, const double* pa, const double* pb,
                           double beta, double* pc, double* scratch){

    ndbl_m2_t x;
    const double* qa = pl->swap ? pb : pa;
    const double* qb = pl->swap ? pa : pb;
    double*       qc = pc;

    if (pl->kind == 0){
        return;
    }

    if (pl->kind == 1){
        x   = pl->c;
        x.p = pc;
        ndbl_scale2(&x, beta);
        return;
    }

    if (pl->pack_a){
        x   = pl->a;
        x.p = (double*)qa;
        ndbl_pack2(&x, scratch + pl->off_a, pl->lda);
        qa  = scratch + pl->off_a;
    }
    if (pl->pack_b){
        x   = pl->b;
        x.p = (double*)qb;
        ndbl_pack2(&x, scratch + pl->off_b, pl->ldb);
        qb  = scratch + pl->off_b;
    }
    if (pl->tmp_c){
        qc = scratch + pl->off_c;
        if (beta != 0.0){
            x   = pl->c;
            x.p = pc;
            ndbl_pack2(&x, qc, pl->ldc);
        }
    }

    oti_dgemm(pl->ta, pl->tb, (int)pl->m, (int)pl->n, (int)pl->k, alpha, qa, (int)pl->lda, qb,
              (int)pl->ldb, beta, qc, (int)pl->ldc);

    if (pl->tmp_c){
        x   = pl->c;
        x.p = pc;
        ndbl_unpack2(qc, pl->ldc, &x);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes of n doubles plus extra bytes, checked; OTI_ERR_SIZE on overflow.
static int ndbl_bytes(int64_t ndoubles, int64_t extra, int64_t* nbytes){

    int64_t b;

    if (ndoubles < 0 || extra < 0 || oti_ckd_mul_i64(ndoubles, 8, &b)
        || oti_ckd_add_i64(b, extra, nbytes) || (uint64_t)*nbytes > (uint64_t)SIZE_MAX){
        return OTI_ERR_SIZE;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Prepares nslots lazily allocated blocks of nbytes each. Unless held < 0 (the caller has already
// checked the operation's total), held + nslots * nbytes is checked against the context's temp
// budget first: held is what the operation already holds (an overlap temporary, factors). Nothing is
// allocated for nbytes == 0 but the slot table.
static int ndbl_scratch_init(oti_ctx* ctx, ndbl_scratch_t* s, int32_t nslots, int64_t nbytes,
                             int64_t held){

    int64_t total;
    int st = OTI_OK;

    s->slot   = NULL;
    s->nslots = 0;
    s->nbytes = nbytes;

    if (nslots < 1){
        nslots = 1;
    }
    if (oti_ckd_mul_i64(nbytes, nslots, &total)){
        return OTI_ERR_SIZE;
    }
    if (held >= 0){
        if (oti_ckd_add_i64(total, held, &total)){
            return OTI_ERR_SIZE;
        }
        st = oti_ctx_check_temp(ctx, total);
    }
    if (st != OTI_OK || nbytes == 0){
        return st;
    }

    s->slot = (void**)ndb_malloc((size_t)nslots * sizeof(void*));

    if (s->slot == NULL){
        return OTI_ERR_MEMORY;
    }

    memset(s->slot, 0, (size_t)nslots * sizeof(void*));
    s->nslots = nslots;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The block of a worker slot, allocated on first use (each slot is used by one worker only). NULL on
// allocation failure; a block of 0 bytes is a valid non-NULL pointer.
static void* ndbl_scratch_get(ndbl_scratch_t* s, int32_t worker){

    if (worker < 0 || worker >= s->nslots){
        return NULL;
    }
    if (s->slot[worker] == NULL){
        s->slot[worker] = ndb_aligned_alloc((size_t)s->nbytes);
    }

    return s->slot[worker];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void ndbl_scratch_free(ndbl_scratch_t* s){

    int32_t w;

    if (s->slot != NULL){
        for (w = 0; w < s->nslots; w++){
            free(s->slot[w]);
        }
        free(s->slot);
    }

    s->slot   = NULL;
    s->nslots = 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs one planned product, allocating its scratch only when needed; held + the scratch is checked
// against the temp budget once, before allocating.
static int ndbl_gemm_once(oti_ctx* ctx, const ndbl_plan_t* pl, double alpha, const double* pa,
                          const double* pb, double beta, double* pc, int64_t held){

    double* s = NULL;
    int64_t nbytes = 0, total;
    int st = ndbl_bytes(pl->scratch, 0, &nbytes);

    if (st == OTI_OK && oti_ckd_add_i64(nbytes, held, &total)){
        st = OTI_ERR_SIZE;
    }
    if (st == OTI_OK){
        st = oti_ctx_check_temp(ctx, total);
    }
    if (st == OTI_OK && nbytes > 0){
        s  = (double*)ndb_aligned_alloc((size_t)nbytes);
        st = s == NULL ? OTI_ERR_MEMORY : OTI_OK;
    }
    if (st == OTI_OK){
        ndbl_exec_gemm(pl, alpha, pa, pb, beta, pc, s);
    }

    free(s);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Team size of a batch loop of nitems items of ns_per_item each, and the items per chunk (S28). Serial
// (0) below NDBL_MIN_ITEM_NS per item; chunks hold at least NDBL_MIN_CHUNK_NS of work (independent of
// the team size); the team is the cost model's (oti_exec_plan) bounded by the provider's measured
// contention: w <= ns_per_item / oti_blas_contention_ns(), so that the per-call contention stays below
// the useful work of a call.
static int32_t ndbl_batch_workers(const oti_ctx* ctx, int64_t nitems, double ns_per_item,
                                  int64_t* per_chunk){

    double  c = ns_per_item > 1.0 ? NDBL_MIN_CHUNK_NS / ns_per_item : NDBL_MIN_CHUNK_NS;
    double  cont;
    int32_t w;

    *per_chunk = c <= 1.0 ? 1 : (int64_t)ceil(c);

    if (nitems < 2 || !(ns_per_item >= NDBL_MIN_ITEM_NS)){
        return 0;
    }

    w = oti_exec_plan(ctx, nitems, *per_chunk, ns_per_item);

    if (w < 2){
        return 0;
    }

    cont = oti_blas_contention_ns();   // measured once per provider, only when a team is planned

    if (cont > 0.0 && (double)w * cont > ns_per_item){
        w = (int32_t)(ns_per_item / cont);
    }

    return w >= 2 ? w : 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Chunk of a batch loop: items in increasing order; the first failing item's status is returned.
static int ndbl_batch_chunk(void* arg, int64_t chunk, int32_t worker){

    const ndbl_batch_t* b = (const ndbl_batch_t*)arg;
    int64_t lo = chunk * b->per_chunk;
    int64_t hi = lo + b->per_chunk < b->nitems ? lo + b->per_chunk : b->nitems;
    int64_t i;
    int st;

    for (i = lo; i < hi; i++){
        st = b->fn(b->arg, i, worker);
        if (st != OTI_OK){
            return st;
        }
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs fn over items 0 .. nitems-1: serially when workers < 2, else through oti_parallel_for_blas()
// with `workers` threads (which itself stays serial without the BLAS capabilities, contracts 5.5).
// The status is the first failing item's, in item order.
static int ndbl_batch_run(oti_ctx* ctx, int32_t workers, int64_t nitems, int64_t per_chunk,
                          ndbl_item_fn fn, void* arg){

    ndbl_batch_t b;
    int64_t i;
    int st;

    if (workers < 2){
        for (i = 0; i < nitems; i++){
            st = fn(arg, i, 0);
            if (st != OTI_OK){
                return st;
            }
        }
        return OTI_OK;
    }

    {
        oti_ctx run = *(ctx != NULL ? ctx : oti_ctx_default());

        run.exec.nthreads = workers;
        b.fn        = fn;
        b.arg       = arg;
        b.nitems    = nitems;
        b.per_chunk = per_chunk;

        return oti_parallel_for_blas(&run, oti_exec_nchunks(nitems, per_chunk), ndbl_batch_chunk, &b);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks of a read-only OTI_F64 input.
static inline int ndbl_check_in(const ndarr_t* a){

    if (a == NULL){
        return OTI_ERR_ARGUMENT;
    }

    ndbl_debug_input(a);

    return a->dtype == OTI_F64 ? OTI_OK : OTI_ERR_DTYPE;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks of a written OTI_F64 output: dtype, writeability (READONLY), internal overlap (LAYOUT).
static inline int ndbl_check_out(const ndarr_t* o){

    int st = ndbl_check_in(o);

    if (st != OTI_OK){
        return st;
    }

    return nd_validate(o, NULL, NULL, ND_V_OUTPUT);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 when out may share memory with a or b.
static inline int ndbl_shares(const ndarr_t* out, const ndarr_t* a, const ndarr_t* b){

    return nd_may_share_memory(out, a) != ND_SHARE_NONE
           || (b != NULL && nd_may_share_memory(out, b) != ND_SHARE_NONE);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 when the axes (extents, strides) merge into one strided axis (NumPy's reshape rule), giving its
// extent and stride; axes of extent 1 are ignored.
static int ndbl_merge_axes(int32_t nd, const int64_t* shape, const int64_t* strides, int64_t* n,
                           int64_t* s){

    int64_t total = 1;
    int64_t last_n = 1, last_s = 0;
    int32_t i, seen = 0;

    for (i = 0; i < nd; i++){

        if (shape[i] == 1){
            continue;
        }
        if (seen && last_s != shape[i] * strides[i]){
            return 0;
        }

        total *= shape[i];
        last_n = shape[i];
        last_s = strides[i];
        seen   = 1;

    }

    (void)last_n;
    *n = total;
    *s = seen ? last_s : 0;

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// numpy.matmul geometry: the result's rank and extents, the operands' 2-D views (after the 1-D
// promotions) and the broadcast batch strides.
typedef struct {
    int32_t   nb;                          // batch axes of the result
    int64_t   bshape[OTI_ND_MAXDIM];
    int64_t   sa[OTI_ND_MAXDIM];           // batch strides of a, b, out (0 when broadcast)
    int64_t   sb[OTI_ND_MAXDIM];
    int64_t   so[OTI_ND_MAXDIM];
    int64_t   nbatch;
    int32_t   b_batched;                   // 1 when some batch axis of b has extent > 1
    ndbl_m2_t a2, b2, o2;                  // 2-D views (after the 1-D promotions)
    int32_t   ndim;                        // result rank
    int64_t   shape[OTI_ND_MAXDIM];        // result extents
} ndbl_mm_t;


// *******************************************************************************************************
// numpy.matmul shapes: rank-0 operands, k mismatches and non-broadcastable batches are SHAPE.
static int ndbl_mm_shape(const ndarr_t* a, const ndarr_t* b, ndbl_mm_t* mm){

    int32_t an = a->ndim, bn = b->ndim, i, nb, nba, nbb;
    int64_t m, k, kb, n;

    if (an < 1 || bn < 1){
        return OTI_ERR_SHAPE;
    }

    m  = an == 1 ? 1 : a->shape[an - 2];
    k  = a->shape[an - 1];
    kb = bn == 1 ? b->shape[0] : b->shape[bn - 2];
    n  = bn == 1 ? 1 : b->shape[bn - 1];

    if (k != kb){
        return OTI_ERR_SHAPE;
    }

    nba = an > 2 ? an - 2 : 0;
    nbb = bn > 2 ? bn - 2 : 0;
    nb  = nba > nbb ? nba : nbb;
    mm->nb        = nb;
    mm->nbatch    = 1;
    mm->b_batched = 0;

    for (i = 0; i < nb; i++){

        int32_t ia = i - (nb - nba), ib = i - (nb - nbb);
        int64_t ea = ia >= 0 ? a->shape[ia] : 1, eb = ib >= 0 ? b->shape[ib] : 1;

        if (ea != eb && ea != 1 && eb != 1){
            return OTI_ERR_SHAPE;
        }

        mm->bshape[i] = ea == 1 ? eb : ea;
        mm->sa[i]     = (ia >= 0 && ea != 1) ? a->strides[ia] : 0;
        mm->sb[i]     = (ib >= 0 && eb != 1) ? b->strides[ib] : 0;

        if (eb > 1){
            mm->b_batched = 1;
        }

        // Batch sizes: the result is allocated with checked arithmetic later; 0 short-circuits.
        if (mm->bshape[i] == 0 || mm->nbatch == 0){
            mm->nbatch = 0;
        } else if (oti_ckd_mul_i64(mm->nbatch, mm->bshape[i], &mm->nbatch)){
            return OTI_ERR_SIZE;
        }

    }

    mm->a2.p  = (double*)a->data;
    mm->a2.n0 = m;
    mm->a2.s0 = an == 1 ? 0 : a->strides[an - 2];
    mm->a2.n1 = k;
    mm->a2.s1 = a->strides[an - 1];
    mm->b2.p  = (double*)b->data;
    mm->b2.n0 = k;
    mm->b2.s0 = bn == 1 ? b->strides[0] : b->strides[bn - 2];
    mm->b2.n1 = n;
    mm->b2.s1 = bn == 1 ? 0 : b->strides[bn - 1];

    mm->ndim = nb;

    for (i = 0; i < nb; i++){
        mm->shape[i] = mm->bshape[i];
    }
    if (an > 1){
        mm->shape[mm->ndim++] = m;
    }
    if (bn > 1){
        mm->shape[mm->ndim++] = n;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The output's 2-D view and batch strides (out has exactly the result shape).
static void ndbl_mm_out(const ndarr_t* a, const ndarr_t* b, const ndarr_t* out, ndbl_mm_t* mm){

    int32_t i, ax = mm->nb;

    for (i = 0; i < mm->nb; i++){
        mm->so[i] = out->strides[i];
    }

    mm->o2.p  = (double*)out->data;
    mm->o2.n0 = mm->a2.n0;
    mm->o2.s0 = a->ndim > 1 ? out->strides[ax++] : 0;
    mm->o2.n1 = mm->b2.n1;
    mm->o2.s1 = b->ndim > 1 ? out->strides[ax] : 0;

}
// -------------------------------------------------------------------------------------------------------


// Argument of the batched matmul items.
typedef struct {
    const ndbl_mm_t*   mm;
    const ndbl_plan_t* pl;
    ndbl_scratch_t*    scr;
} ndbl_mm_arg_t;


// *******************************************************************************************************
// One matrix of a batched matmul: batch index `item` in C order of the result's batch axes.
static int ndbl_mm_item(void* arg, int64_t item, int32_t worker){

    const ndbl_mm_arg_t* g  = (const ndbl_mm_arg_t*)arg;
    const ndbl_mm_t*     mm = g->mm;
    int64_t oa = 0, ob = 0, oo = 0, r = item;
    int32_t i;
    double* scratch = NULL;

    for (i = mm->nb - 1; i >= 0; i--){

        int64_t ix = r % mm->bshape[i];

        r  /= mm->bshape[i];
        oa += ix * mm->sa[i];
        ob += ix * mm->sb[i];
        oo += ix * mm->so[i];

    }

    if (g->pl->scratch > 0){
        scratch = (double*)ndbl_scratch_get(g->scr, worker);
        if (scratch == NULL){
            return OTI_ERR_MEMORY;
        }
    }

    ndbl_exec_gemm(g->pl, 1.0, mm->a2.p + oa, mm->b2.p + ob, 0.0, mm->o2.p + oo, scratch);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// numpy.matmul into out (exactly the result shape, writeable, not overlapping a or b); held: the
// bytes of temporaries the caller already holds (the overlap temporary), counted in the budget.
static int ndbl_matmul_core(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out,
                            ndbl_mm_t* mm, int64_t held){

    ndbl_plan_t    pl;
    ndbl_scratch_t scr;
    ndbl_mm_arg_t  g;
    int64_t nbytes, per_chunk = 1, mrows, srow_a, srow_o;
    int32_t workers = 0;
    double  ns;
    int st;

    ndbl_mm_out(a, b, out, mm);

    if (mm->nbatch == 0){
        return OTI_OK;
    }

    // One GEMM (batch * m, k) @ (k, n) when b is not batched and the batch and row axes of a and out
    // merge into one strided axis each (contracts 9.1, allowed optimisation).
    if (mm->nbatch > 1 && !mm->b_batched){

        int64_t sh[OTI_ND_MAXDIM + 1], sa[OTI_ND_MAXDIM + 1], so[OTI_ND_MAXDIM + 1];
        int64_t n_a, n_o;
        int32_t i;

        for (i = 0; i < mm->nb; i++){
            sh[i] = mm->bshape[i];
            sa[i] = mm->sa[i];
            so[i] = mm->so[i];
        }

        sh[mm->nb] = mm->a2.n0;
        sa[mm->nb] = mm->a2.s0;
        so[mm->nb] = mm->o2.s0;

        if (ndbl_merge_axes(mm->nb + 1, sh, sa, &n_a, &srow_a)
            && ndbl_merge_axes(mm->nb + 1, sh, so, &n_o, &srow_o) && n_a == n_o){

            ndbl_m2_t a2 = mm->a2, o2 = mm->o2;

            mrows = n_a;
            a2.n0 = mrows;
            a2.s0 = srow_a;
            o2.n0 = mrows;
            o2.s0 = srow_o;

            if (ndbl_plan_gemm(a2, mm->b2, o2, &pl) == OTI_OK){
                return ndbl_gemm_once(ctx, &pl, 1.0, a2.p, mm->b2.p, 0.0, o2.p, held);
            }
            // A merged extent that does not fit LAPACK ints falls back to the per-matrix loop.

        }

    }

    st = ndbl_plan_gemm(mm->a2, mm->b2, mm->o2, &pl);

    if (st != OTI_OK){
        return st;
    }

    ns = NDBL_GEMM_NS + NDBL_GEMM_NS_FMA * (double)mm->a2.n0 * (double)mm->a2.n1 * (double)mm->b2.n1;
    workers = pl.kind == 2 ? ndbl_batch_workers(ctx, mm->nbatch, ns, &per_chunk) : 0;

    if (workers < 2){
        per_chunk = 1;
    }

    st = ndbl_bytes(pl.scratch, 0, &nbytes);

    if (st == OTI_OK){
        st = ndbl_scratch_init(ctx, &scr, workers, nbytes, held);
    }
    if (st != OTI_OK){
        return st;
    }

    g.mm  = mm;
    g.pl  = &pl;
    g.scr = &scr;

    st = ndbl_batch_run(ctx, workers, mm->nbatch, per_chunk, ndbl_mm_item, &g);

    ndbl_scratch_free(&scr);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_matmul(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* res){

    ndbl_mm_t mm;
    int st;

    ndbl_debug_res(res);

    if (res == NULL){
        st = OTI_ERR_ARGUMENT;
    } else {

        nd_init_empty(res);
        st = oti_ctx_check(ctx);

        if (st == OTI_OK){
            st = ndbl_check_in(a);
        }
        if (st == OTI_OK){
            st = ndbl_check_in(b);
        }
        if (st == OTI_OK){
            st = ndbl_mm_shape(a, b, &mm);
        }
        if (st == OTI_OK){
            st = nd_alloc(ctx, OTI_F64, mm.ndim, mm.shape, ND_LAYOUT_C, 0, res);
        }
        if (st == OTI_OK){
            st = ndbl_matmul_core(ctx, a, b, res, &mm, 0);
            if (st != OTI_OK){
                nd_release(res);
            }
        }

    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_matmul", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 when out has exactly the given shape.
static int ndbl_same_shape(const ndarr_t* out, int32_t ndim, const int64_t* shape){

    int32_t i;

    if (out->ndim != ndim){
        return 0;
    }
    for (i = 0; i < ndim; i++){
        if (out->shape[i] != shape[i]){
            return 0;
        }
    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The overlap temporary of nd_matmul_to() / nd_dot_to() (S14): a new C array of the result shape. Its
// bytes (*nbytes) are checked against the temp budget here and carried into the inner operation's
// budget (held), so that the temporary plus the packs are checked together (checker W2 finding 2).
static int ndbl_overlap_tmp(oti_ctx* ctx, int32_t ndim, const int64_t* shape, ndarr_t* tmp,
                            int64_t* nbytes){

    int64_t n = 1;
    int32_t i;
    int st;

    nd_init_empty(tmp);
    *nbytes = 0;

    for (i = 0; i < ndim; i++){
        if (oti_ckd_mul_i64(n, shape[i], &n)){
            return OTI_ERR_SIZE;
        }
    }

    st = ndbl_bytes(n, 0, nbytes);

    if (st == OTI_OK){
        st = oti_ctx_check_temp(ctx, *nbytes);
    }
    if (st == OTI_OK){
        st = nd_alloc(ctx, OTI_F64, ndim, shape, ND_LAYOUT_C, 0, tmp);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_matmul_to(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out){

    ndbl_mm_t mm;
    ndarr_t tmp;
    int64_t held = 0;
    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndbl_check_in(a);
    }
    if (st == OTI_OK){
        st = ndbl_check_in(b);
    }
    if (st == OTI_OK){
        st = ndbl_check_out(out);
    }
    if (st == OTI_OK){
        st = ndbl_mm_shape(a, b, &mm);
    }
    if (st == OTI_OK && !ndbl_same_shape(out, mm.ndim, mm.shape)){
        st = OTI_ERR_SHAPE;
    }

    if (st == OTI_OK){

        if (ndbl_shares(out, a, b)){

            // numpy.matmul(a, b, out=a): compute into a temporary, then copy (S14).
            st = ndbl_overlap_tmp(ctx, mm.ndim, mm.shape, &tmp, &held);

            if (st == OTI_OK){
                st = ndbl_matmul_core(ctx, a, b, &tmp, &mm, held);
            }
            if (st == OTI_OK){
                st = nd_assign(ctx, &tmp, out);
            }

            nd_release(&tmp);

        } else {
            st = ndbl_matmul_core(ctx, a, b, out, &mm, 0);
        }

    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_matmul_to", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A vector's pointer and increment for ddot / daxpy / dcopy / dswap (any sign): the lowest address and
// the negative increment for s < 0; inc 1 for n == 1. Returns 0 when the vector must be packed
// (zero stride with n > 1); OTI_ERR_SIZE through *st when the increment does not fit.
static int ndbl_vec_any(const ndbl_v_t* v, double** p, int* inc, int* st){

    *st = OTI_OK;

    if (v->n <= 1){
        *p   = v->p;
        *inc = 1;
        return 1;
    }
    if (v->s == 0){
        return 0;
    }
    if (!ndbl_fits(v->s)){
        *st = OTI_ERR_SIZE;
        return 1;
    }

    *p   = v->s > 0 ? v->p : v->p + (v->n - 1) * v->s;
    *inc = (int)v->s;

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A vector's pointer and increment for routines that need inc > 0. Returns 0 when it must be packed.
static int ndbl_vec_pos(const ndbl_v_t* v, double** p, int* inc, int* st){

    *st = OTI_OK;

    if (v->n <= 1){
        *p   = v->p;
        *inc = 1;
        return 1;
    }
    if (v->s <= 0){
        return 0;
    }
    if (!ndbl_fits(v->s)){
        *st = OTI_ERR_SIZE;
        return 1;
    }

    *p   = v->p;
    *inc = (int)v->s;

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static inline ndbl_v_t ndbl_v_of(const ndarr_t* a){

    ndbl_v_t v;

    v.p = (double*)a->data;
    v.n = a->shape[0];
    v.s = a->strides[0];

    return v;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Packs a vector into a contiguous temporary, after the caller checked the operation's planned total
// against the temp budget. *tmp must be freed.
static int ndbl_vec_pack_raw(const ndbl_v_t* v, double** tmp){

    int64_t nbytes, i;
    int st = ndbl_bytes(v->n, 0, &nbytes);

    *tmp = NULL;

    if (st != OTI_OK){
        return st;
    }

    *tmp = (double*)ndb_aligned_alloc((size_t)nbytes);

    if (*tmp == NULL){
        return OTI_ERR_MEMORY;
    }

    for (i = 0; i < v->n; i++){
        (*tmp)[i] = v->p[i * v->s];
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Packs a vector that is the operation's only temporary (held + its bytes checked first).
static int ndbl_vec_pack(oti_ctx* ctx, const ndbl_v_t* v, double** tmp){

    int64_t nbytes;
    int st = ndbl_bytes(v->n, 0, &nbytes);

    *tmp = NULL;

    if (st == OTI_OK){
        st = oti_ctx_check_temp(ctx, nbytes);
    }

    return st == OTI_OK ? ndbl_vec_pack_raw(v, tmp) : st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Adds the bytes of n doubles to *total when `need`; OTI_ERR_SIZE on overflow.
static inline int ndbl_add_doubles(int need, int64_t n, int64_t* total){

    int64_t b;

    if (!need){
        return OTI_OK;
    }

    return (ndbl_bytes(n, 0, &b) != OTI_OK || oti_ckd_add_i64(*total, b, total)) ? OTI_ERR_SIZE
                                                                                : OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// x . y on two vectors of the same length (ddot, with the any-sign rule). Both packs are planned and
// checked together with held before either is allocated (checker W2 finding 2).
static int ndbl_dot_run(oti_ctx* ctx, const ndbl_v_t* x, const ndbl_v_t* y, double* res,
                        int64_t held){

    double *px = NULL, *py = NULL, *tx = NULL, *ty = NULL;
    int ix = 1, iy = 1, st = OTI_OK, st2 = OTI_OK, pack_x, pack_y;
    int64_t total = held;

    *res = 0.0;

    if (x->n == 0){
        return OTI_OK;
    }
    if (!ndbl_fits(x->n)){
        return OTI_ERR_SIZE;
    }

    pack_x = !ndbl_vec_any(x, &px, &ix, &st);
    pack_y = !ndbl_vec_any(y, &py, &iy, &st2);

    if (st == OTI_OK){
        st = st2;
    }
    if (st == OTI_OK){
        st = ndbl_add_doubles(pack_x, x->n, &total);
    }
    if (st == OTI_OK){
        st = ndbl_add_doubles(pack_y, y->n, &total);
    }
    if (st == OTI_OK && (pack_x || pack_y || held > 0)){
        st = oti_ctx_check_temp(ctx, total);
    }
    if (st == OTI_OK && pack_x){
        st = ndbl_vec_pack_raw(x, &tx);
        px = tx;
        ix = 1;
    }
    if (st == OTI_OK && pack_y){
        st = ndbl_vec_pack_raw(y, &ty);
        py = ty;
        iy = 1;
    }
    if (st == OTI_OK){
        *res = oti_ddot((int)x->n, px, ix, py, iy);
    }

    free(tx);
    free(ty);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// y (m) = alpha A (m, n) x (n) + beta y, A by the GEMM rules, vectors with inc > 0. The A pack and the
// x and y packs are planned first and checked together with held once (checker W2 finding 2).
static int ndbl_gemv_run(oti_ctx* ctx, double alpha, ndbl_m2_t a, const ndbl_v_t* x, double beta,
                         const ndbl_v_t* y, int64_t held){

    double *px = NULL, *py = NULL, *ta = NULL, *tx = NULL, *ty = NULL;
    const double* pa = a.p;
    int64_t ld = 1, nbytes, i, m = a.n0, n = a.n1, rows, cols, total = held;
    int ix = 1, iy = 1, st = OTI_OK, st2 = OTI_OK, pack_a = 0, pack_x, pack_y;
    char tr;

    if (m == 0){
        return OTI_OK;
    }
    if (n == 0){
        for (i = 0; i < m; i++){
            y->p[i * y->s] = beta == 0.0 ? 0.0 : beta * y->p[i * y->s];
        }
        return OTI_OK;
    }

    // dgemv(tr, rows, cols, A stored rows x cols): 'N' stores A, 'T' stores A^T.
    if (ndbl_usable_n(&a, &ld)){
        tr = 'N'; rows = m; cols = n;
    } else if (ndbl_usable_t(&a, &ld)){
        tr = 'T'; rows = n; cols = m;
    } else {
        tr = 'N'; rows = m; cols = n; ld = ndbl_max1(m); pack_a = 1;
    }

    pack_x = !ndbl_vec_pos(x, &px, &ix, &st);
    pack_y = !ndbl_vec_pos(y, &py, &iy, &st2);

    if (st == OTI_OK){
        st = st2;
    }
    if (st == OTI_OK && (!ndbl_fits(m) || !ndbl_fits(n) || !ndbl_fits(ld))){
        st = OTI_ERR_SIZE;
    }
    if (st == OTI_OK){
        st = ndbl_add_doubles(pack_a, m * n, &total);   // m * n fits: A has those elements
    }
    if (st == OTI_OK){
        st = ndbl_add_doubles(pack_x, n, &total);
    }
    if (st == OTI_OK){
        st = ndbl_add_doubles(pack_y, m, &total);
    }
    if (st == OTI_OK && (pack_a || pack_x || pack_y || held > 0)){
        st = oti_ctx_check_temp(ctx, total);
    }

    if (st == OTI_OK && pack_a){
        st = ndbl_bytes(m * n, 0, &nbytes);
        if (st == OTI_OK){
            ta = (double*)ndb_aligned_alloc((size_t)nbytes);
            st = ta == NULL ? OTI_ERR_MEMORY : OTI_OK;
        }
        if (st == OTI_OK){
            ndbl_pack2(&a, ta, ld);
            pa = ta;
        }
    }
    if (st == OTI_OK && pack_x){
        st = ndbl_vec_pack_raw(x, &tx);
        px = tx;
        ix = 1;
    }
    if (st == OTI_OK && pack_y){
        st = ndbl_vec_pack_raw(y, &ty);   // copied in: beta may be non-zero
        py = ty;
        iy = 1;
    }

    if (st == OTI_OK){

        oti_dgemv(tr, (int)rows, (int)cols, alpha, pa, (int)ld, px, ix, beta, py, iy);

        if (ty != NULL){
            for (i = 0; i < m; i++){
                y->p[i * y->s] = ty[i];
            }
        }

    }

    free(ta);
    free(tx);
    free(ty);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// numpy.dot for ndim <= 2 into out (exactly the result shape, not overlapping a or b).
static int ndbl_dot_core(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out,
                         int64_t held){

    ndbl_v_t x, y, o;
    ndbl_plan_t pl;
    double r;
    int st;

    if (a->ndim == 1 && b->ndim == 1){
        x  = ndbl_v_of(a);
        y  = ndbl_v_of(b);
        st = ndbl_dot_run(ctx, &x, &y, &r, held);
        if (st == OTI_OK){
            *(double*)out->data = r;
        }
        return st;
    }

    if (a->ndim == 2 && b->ndim == 1){
        x = ndbl_v_of(b);
        o = ndbl_v_of(out);
        return ndbl_gemv_run(ctx, 1.0, ndbl_m2_of(a, 0, 1), &x, 0.0, &o, held);
    }

    if (a->ndim == 1 && b->ndim == 2){
        x = ndbl_v_of(a);
        o = ndbl_v_of(out);
        return ndbl_gemv_run(ctx, 1.0, ndbl_m2_of(b, 1, 0), &x, 0.0, &o, held);
    }

    st = ndbl_plan_gemm(ndbl_m2_of(a, 0, 1), ndbl_m2_of(b, 0, 1), ndbl_m2_of(out, 0, 1), &pl);

    if (st == OTI_OK){
        st = ndbl_gemm_once(ctx, &pl, 1.0, (const double*)a->data, (const double*)b->data, 0.0,
                            (double*)out->data, held);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// numpy.dot result shape for ndim <= 2 (0-D operands are handled by the caller as a product).
static int ndbl_dot_shape(const ndarr_t* a, const ndarr_t* b, int32_t* ndim, int64_t* shape){

    int64_t ka = a->shape[a->ndim - 1];
    int64_t kb = b->shape[0];

    if (a->ndim > 2 || b->ndim > 2){
        return OTI_ERR_SHAPE;
    }
    if (ka != kb){
        return OTI_ERR_SHAPE;
    }

    *ndim = 0;

    if (a->ndim == 2){
        shape[(*ndim)++] = a->shape[0];
    }
    if (b->ndim == 2){
        shape[(*ndim)++] = b->shape[1];
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_dot(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* res){

    int64_t shape[2];
    int32_t ndim = 0;
    int st;

    ndbl_debug_res(res);

    if (res == NULL){
        st = OTI_ERR_ARGUMENT;
    } else {

        nd_init_empty(res);
        st = oti_ctx_check(ctx);

        if (st == OTI_OK){
            st = ndbl_check_in(a);
        }
        if (st == OTI_OK){
            st = ndbl_check_in(b);
        }
        if (st == OTI_OK && (a->ndim > 2 || b->ndim > 2)){
            st = OTI_ERR_SHAPE;
        }

        if (st == OTI_OK && (a->ndim == 0 || b->ndim == 0)){
            // numpy.dot with a scalar is multiplication.
            st = nd_binary(ctx, ND_OP_MUL, a, b, res);
        } else if (st == OTI_OK){

            st = ndbl_dot_shape(a, b, &ndim, shape);

            if (st == OTI_OK){
                st = nd_alloc(ctx, OTI_F64, ndim, shape, ND_LAYOUT_C, 0, res);
            }
            if (st == OTI_OK){
                st = ndbl_dot_core(ctx, a, b, res, 0);
                if (st != OTI_OK){
                    nd_release(res);
                }
            }

        }

    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_dot", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_dot_to(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out){

    int64_t shape[2], held = 0;
    int32_t ndim = 0;
    ndarr_t tmp;
    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndbl_check_in(a);
    }
    if (st == OTI_OK){
        st = ndbl_check_in(b);
    }
    if (st == OTI_OK){
        st = ndbl_check_out(out);
    }
    if (st == OTI_OK && (a->ndim > 2 || b->ndim > 2)){
        st = OTI_ERR_SHAPE;
    }

    if (st == OTI_OK && (a->ndim == 0 || b->ndim == 0)){
        st = nd_binary_to(ctx, ND_OP_MUL, a, b, out);
    } else if (st == OTI_OK){

        st = ndbl_dot_shape(a, b, &ndim, shape);

        if (st == OTI_OK && !ndbl_same_shape(out, ndim, shape)){
            st = OTI_ERR_SHAPE;
        }

        if (st == OTI_OK && ndbl_shares(out, a, b)){

            st = ndbl_overlap_tmp(ctx, ndim, shape, &tmp, &held);

            if (st == OTI_OK){
                st = ndbl_dot_core(ctx, a, b, &tmp, held);
            }
            if (st == OTI_OK){
                st = nd_assign(ctx, &tmp, out);
            }

            nd_release(&tmp);

        } else if (st == OTI_OK){
            st = ndbl_dot_core(ctx, a, b, out, 0);
        }

    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_dot_to", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_gemm(oti_ctx* ctx, int32_t transa, int32_t transb, double alpha, const ndarr_t* a,
            const ndarr_t* b, double beta, ndarr_t* c){

    ndbl_m2_t   ma, mb, mc;
    ndbl_plan_t pl;
    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndbl_check_in(a);
    }
    if (st == OTI_OK){
        st = ndbl_check_in(b);
    }
    if (st == OTI_OK){
        st = ndbl_check_out(c);
    }
    if (st == OTI_OK && ((transa != 0 && transa != 1) || (transb != 0 && transb != 1))){
        st = OTI_ERR_ARGUMENT;
    }
    if (st == OTI_OK && (a->ndim != 2 || b->ndim != 2 || c->ndim != 2)){
        st = OTI_ERR_SHAPE;
    }

    if (st == OTI_OK){

        ma = transa ? ndbl_m2_of(a, 1, 0) : ndbl_m2_of(a, 0, 1);
        mb = transb ? ndbl_m2_of(b, 1, 0) : ndbl_m2_of(b, 0, 1);
        mc = ndbl_m2_of(c, 0, 1);

        if (ma.n1 != mb.n0 || mc.n0 != ma.n0 || mc.n1 != mb.n1){
            st = OTI_ERR_SHAPE;
        } else if (ndbl_shares(c, a, b)){
            st = OTI_ERR_LAYOUT;
        }

    }

    if (st == OTI_OK){
        st = ndbl_plan_gemm(ma, mb, mc, &pl);
    }
    if (st == OTI_OK){
        st = ndbl_gemm_once(ctx, &pl, alpha, ma.p, mb.p, beta, mc.p, 0);
    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_gemm", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_gemv(oti_ctx* ctx, int32_t trans, double alpha, const ndarr_t* a, const ndarr_t* x,
            double beta, ndarr_t* y){

    ndbl_m2_t ma;
    ndbl_v_t  vx, vy;
    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndbl_check_in(a);
    }
    if (st == OTI_OK){
        st = ndbl_check_in(x);
    }
    if (st == OTI_OK){
        st = ndbl_check_out(y);
    }
    if (st == OTI_OK && trans != 0 && trans != 1){
        st = OTI_ERR_ARGUMENT;
    }
    if (st == OTI_OK && (a->ndim != 2 || x->ndim != 1 || y->ndim != 1)){
        st = OTI_ERR_SHAPE;
    }

    if (st == OTI_OK){

        ma = trans ? ndbl_m2_of(a, 1, 0) : ndbl_m2_of(a, 0, 1);
        vx = ndbl_v_of(x);
        vy = ndbl_v_of(y);

        if (ma.n1 != vx.n || ma.n0 != vy.n){
            st = OTI_ERR_SHAPE;
        } else if (ndbl_shares(y, a, x)){
            st = OTI_ERR_LAYOUT;
        } else {
            st = ndbl_gemv_run(ctx, alpha, ma, &vx, beta, &vy, 0);
        }

    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_gemv", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_ger(oti_ctx* ctx, double alpha, const ndarr_t* x, const ndarr_t* y, ndarr_t* a){

    ndbl_m2_t ma;
    ndbl_v_t  vx, vy;
    double *px = NULL, *py = NULL, *tx = NULL, *ty = NULL, *ta = NULL;
    int64_t ld, nbytes, total = 0;
    int ix = 1, iy = 1, mode = 0, pack_x, pack_y, st2 = OTI_OK;
    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndbl_check_in(x);
    }
    if (st == OTI_OK){
        st = ndbl_check_in(y);
    }
    if (st == OTI_OK){
        st = ndbl_check_out(a);
    }
    if (st == OTI_OK && (a->ndim != 2 || x->ndim != 1 || y->ndim != 1)){
        st = OTI_ERR_SHAPE;
    }
    if (st == OTI_OK && (x->shape[0] != a->shape[0] || y->shape[0] != a->shape[1])){
        st = OTI_ERR_SHAPE;
    }
    if (st == OTI_OK && ndbl_shares(a, x, y)){
        st = OTI_ERR_LAYOUT;
    }

    if (st == OTI_OK && nd_size(a) > 0){

        ma = ndbl_m2_of(a, 0, 1);
        vx = ndbl_v_of(x);
        vy = ndbl_v_of(y);

        // mode 0: A stored ('N'); 1: A^T stored, A^T += alpha y x^T; 2: an F temporary.
        if (ndbl_usable_n(&ma, &ld)){
            mode = 0;
        } else if (ndbl_usable_t(&ma, &ld)){
            mode = 1;
        } else {
            mode = 2;
            ld   = ndbl_max1(ma.n0);
        }

        // The A temporary and the vector packs are planned, then checked together once.
        pack_x = !ndbl_vec_pos(&vx, &px, &ix, &st);
        pack_y = !ndbl_vec_pos(&vy, &py, &iy, &st2);

        if (st == OTI_OK){
            st = st2;
        }
        if (st == OTI_OK && (!ndbl_fits(ma.n0) || !ndbl_fits(ma.n1) || !ndbl_fits(ld))){
            st = OTI_ERR_SIZE;
        }
        if (st == OTI_OK){
            st = ndbl_add_doubles(mode == 2, ma.n0 * ma.n1, &total);   // A has those elements
        }
        if (st == OTI_OK){
            st = ndbl_add_doubles(pack_x, vx.n, &total);
        }
        if (st == OTI_OK){
            st = ndbl_add_doubles(pack_y, vy.n, &total);
        }
        if (st == OTI_OK && total > 0){
            st = oti_ctx_check_temp(ctx, total);
        }
        if (st == OTI_OK && mode == 2){
            st = ndbl_bytes(ma.n0 * ma.n1, 0, &nbytes);
            if (st == OTI_OK){
                ta = (double*)ndb_aligned_alloc((size_t)nbytes);
                st = ta == NULL ? OTI_ERR_MEMORY : OTI_OK;
            }
            if (st == OTI_OK){
                ndbl_pack2(&ma, ta, ld);
            }
        }
        if (st == OTI_OK && pack_x){
            st = ndbl_vec_pack_raw(&vx, &tx);
            px = tx;
            ix = 1;
        }
        if (st == OTI_OK && pack_y){
            st = ndbl_vec_pack_raw(&vy, &ty);
            py = ty;
            iy = 1;
        }

        if (st == OTI_OK){
            if (mode == 1){
                oti_dger((int)ma.n1, (int)ma.n0, alpha, py, iy, px, ix, ma.p, (int)ld);
            } else {
                oti_dger((int)ma.n0, (int)ma.n1, alpha, px, ix, py, iy, mode == 2 ? ta : ma.p,
                         (int)ld);
                if (mode == 2){
                    ndbl_unpack2(ta, ld, &ma);
                }
            }
        }

        free(ta);
        free(tx);
        free(ty);

    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_ger", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Common checks of the level-1 functions: 1-D OTI_F64 inputs (and output), equal lengths.
static int ndbl_check_l1(const ndarr_t* x, const ndarr_t* y, int y_out){

    int st = ndbl_check_in(x);

    if (st == OTI_OK && y != NULL){
        st = y_out ? ndbl_check_out(y) : ndbl_check_in(y);
    }
    if (st == OTI_OK && (x->ndim != 1 || (y != NULL && y->ndim != 1))){
        st = OTI_ERR_SHAPE;
    }
    if (st == OTI_OK && y != NULL && x->shape[0] != y->shape[0]){
        st = OTI_ERR_SHAPE;
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_vdot(oti_ctx* ctx, const ndarr_t* x, const ndarr_t* y, double* res){

    ndbl_v_t vx, vy;
    int st = oti_ctx_check(ctx);

    if (st == OTI_OK && res == NULL){
        st = OTI_ERR_ARGUMENT;
    }
    if (st == OTI_OK){
        st = ndbl_check_l1(x, y, 0);
    }
    if (st == OTI_OK){
        vx = ndbl_v_of(x);
        vy = ndbl_v_of(y);
        st = ndbl_dot_run(ctx, &vx, &vy, res, 0);
    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_vdot", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_axpy(oti_ctx* ctx, double alpha, const ndarr_t* x, ndarr_t* y){

    ndbl_v_t vx, vy;
    double *px = NULL, *py = NULL, *tx = NULL;
    int ix = 1, iy = 1;
    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndbl_check_l1(x, y, 1);
    }
    if (st == OTI_OK && ndbl_shares(y, x, NULL)){
        st = OTI_ERR_LAYOUT;
    }

    if (st == OTI_OK && x->shape[0] > 0){

        vx = ndbl_v_of(x);
        vy = ndbl_v_of(y);

        if (!ndbl_fits(vx.n)){
            st = OTI_ERR_SIZE;
        }
        if (st == OTI_OK && !ndbl_vec_any(&vx, &px, &ix, &st)){
            st = ndbl_vec_pack(ctx, &vx, &tx);
            px = tx;
            ix = 1;
        }
        // y has no zero stride with n > 1 (internal overlap was rejected above).
        if (st == OTI_OK){
            (void)ndbl_vec_any(&vy, &py, &iy, &st);
        }
        if (st == OTI_OK){
            oti_daxpy((int)vx.n, alpha, px, ix, py, iy);
        }

        free(tx);

    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_axpy", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_scal(oti_ctx* ctx, double alpha, ndarr_t* x){

    ndbl_v_t v;
    double* p;
    int inc;
    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndbl_check_in(x);
    }
    if (st == OTI_OK && x->ndim != 1){
        st = OTI_ERR_SHAPE;
    }
    if (st == OTI_OK){
        st = ndbl_check_out(x);
    }

    if (st == OTI_OK && x->shape[0] > 0){

        v = ndbl_v_of(x);

        // Scaling is elementwise, so a negative stride is the same set of elements from the lowest
        // address with a positive increment (no pack needed, contracts 9.2).
        if (v.n == 1){
            p   = v.p;
            inc = 1;
        } else {
            p   = v.s > 0 ? v.p : v.p + (v.n - 1) * v.s;
            inc = 1;
            if (!ndbl_fits(v.s)){
                st = OTI_ERR_SIZE;
            } else {
                inc = (int)(v.s > 0 ? v.s : -v.s);
            }
        }

        if (st == OTI_OK && !ndbl_fits(v.n)){
            st = OTI_ERR_SIZE;
        }
        if (st == OTI_OK){
            oti_dscal((int)v.n, alpha, p, inc);
        }

    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_scal", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Shared body of nd_nrm2 / nd_asum / nd_iamax: a positive-increment vector (packed otherwise).
// which: 0 dnrm2, 1 dasum, 2 idamax (1-based in *ires).
static int ndbl_l1_reduce(oti_ctx* ctx, const ndarr_t* x, int which, double* dres, int* ires){

    ndbl_v_t v;
    double *p = NULL, *t = NULL;
    int inc = 1;
    int st = ndbl_check_in(x);

    if (st == OTI_OK && x->ndim != 1){
        st = OTI_ERR_SHAPE;
    }
    if (st != OTI_OK || x->shape[0] == 0){
        return st;
    }

    v = ndbl_v_of(x);

    if (!ndbl_fits(v.n)){
        return OTI_ERR_SIZE;
    }
    if (!ndbl_vec_pos(&v, &p, &inc, &st)){
        st  = ndbl_vec_pack(ctx, &v, &t);
        p   = t;
        inc = 1;
    }

    if (st == OTI_OK){
        if (which == 0){
            *dres = oti_dnrm2((int)v.n, p, inc);
        } else if (which == 1){
            *dres = oti_dasum((int)v.n, p, inc);
        } else {
            *ires = oti_idamax((int)v.n, p, inc);
        }
    }

    free(t);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_nrm2(oti_ctx* ctx, const ndarr_t* x, double* res){

    int st = oti_ctx_check(ctx);

    if (st == OTI_OK && res == NULL){
        st = OTI_ERR_ARGUMENT;
    }
    if (st == OTI_OK){
        *res = 0.0;
        st   = ndbl_l1_reduce(ctx, x, 0, res, NULL);
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_nrm2", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_asum(oti_ctx* ctx, const ndarr_t* x, double* res){

    int st = oti_ctx_check(ctx);

    if (st == OTI_OK && res == NULL){
        st = OTI_ERR_ARGUMENT;
    }
    if (st == OTI_OK){
        *res = 0.0;
        st   = ndbl_l1_reduce(ctx, x, 1, res, NULL);
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_asum", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_iamax(oti_ctx* ctx, const ndarr_t* x, int64_t* res){

    int idx = 0;
    int st = oti_ctx_check(ctx);

    if (st == OTI_OK && res == NULL){
        st = OTI_ERR_ARGUMENT;
    }
    if (st == OTI_OK){
        st = ndbl_l1_reduce(ctx, x, 2, NULL, &idx);
        *res = (int64_t)idx - 1;           // 0-based; -1 for an empty vector
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_iamax", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------
