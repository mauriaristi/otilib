// ndarray linear algebra, tier 1 (Phase 3; PLAN-ndarray-contracts.md 9.3-9.5, S20): LU, solve, inv,
// det, slogdet, Cholesky, triangular solves on OTI_F64 arrays, through include/oti/core/lapack.h.
// Included from src/c/real_ndarray.c after blas.c, whose batch runner, scratch and pack helpers it
// uses; file-static helpers carry the ndl_ prefix.
//
// Orientation (9.3): a C-contiguous matrix is memcpy'd and read as A^T in column major (trans = 1), an
// F-contiguous one is memcpy'd (trans = 0), anything else is packed into F order in one strided pass
// (trans = 0). Every matrix of a batch shares the 2-D strides, hence the orientation. Batches loop
// over the broadcast batch axes in C order (ndbl_batch_run(), oti_parallel_for_blas()); the first
// failing matrix in that order decides the status. Empty problems never reach the provider.

#include <math.h>
#include <string.h>

// Geometry of a stack of square matrices (..., n, n).
typedef struct {
    const double* p;
    int32_t  nb;                       // batch axes
    int64_t  bshape[OTI_ND_MAXDIM];
    int64_t  bstrides[OTI_ND_MAXDIM];
    int64_t  nbatch;
    int64_t  n;
    int64_t  s0, s1;                   // strides of the matrix axes
    int32_t  trans;                    // 1: every matrix is C-contiguous (read as A^T)
} ndl_sq_t;


// *******************************************************************************************************
// 1 when the n x n matrix with strides (s0, s1) is C-contiguous (and not trivially both: n <= 1 is
// taken as F, trans = 0).
static inline int32_t ndl_orient(int64_t n, int64_t s0, int64_t s1){

    return (n > 1 && s1 == 1 && s0 == n) ? 1 : 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The geometry of a (..., n, n) OTI_F64 input; SHAPE when it is not a stack of square matrices.
static int ndl_square(const ndarr_t* a, ndl_sq_t* g){

    int32_t i;
    int st = ndbl_check_in(a);

    if (st != OTI_OK){
        return st;
    }
    if (a->ndim < 2 || a->shape[a->ndim - 1] != a->shape[a->ndim - 2]){
        return OTI_ERR_SHAPE;
    }

    g->p      = (const double*)a->data;
    g->nb     = a->ndim - 2;
    g->n      = a->shape[a->ndim - 1];
    g->s0     = a->strides[a->ndim - 2];
    g->s1     = a->strides[a->ndim - 1];
    g->nbatch = 1;

    // a is well formed: the product of its extents fits (0 as soon as one extent is 0).
    for (i = 0; i < g->nb; i++){
        g->bshape[i]   = a->shape[i];
        g->bstrides[i] = a->strides[i];
        g->nbatch      = a->shape[i] == 0 ? 0 : g->nbatch * a->shape[i];
    }

    if (!ndbl_fits(g->n)){
        return OTI_ERR_SIZE;
    }

    g->trans = ndl_orient(g->n, g->s0, g->s1);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Element offset of batch item `item` (C order over nb axes of extents bshape) for the given strides.
static inline int64_t ndl_offset(int32_t nb, const int64_t* bshape, const int64_t* strides,
                                 int64_t item){

    int64_t off = 0;
    int32_t i;

    for (i = nb - 1; i >= 0; i--){
        off  += (item % bshape[i]) * strides[i];
        item /= bshape[i];
    }

    return off;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Copies the n x n matrix src (strides s0, s1) into the F buffer dst (ld n): memcpy for a contiguous
// matrix (C-contiguous gives A^T, which is what trans = 1 means), else one strided pass.
static void ndl_load(const double* src, int64_t n, int64_t s0, int64_t s1, int32_t trans,
                     double* dst){

    int64_t i, j;

    if (n == 1){
        dst[0] = src[0];
    } else if (trans || (s0 == 1 && s1 == n)){
        memcpy(dst, src, (size_t)(n * n) * sizeof(double));
    } else {
        for (j = 0; j < n; j++){
            for (i = 0; i < n; i++){
                dst[i + j * n] = src[i * s0 + j * s1];
            }
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Strides of a new (batch..., n0, n1) array made of compact per-matrix blocks (C order over the batch),
// each F (strides (1, n0)) or C (strides (n1, 1)).
static void ndl_block_strides(int32_t nb, const int64_t* bshape, int64_t n0, int64_t n1,
                              int32_t c_block, int64_t* strides){

    int64_t acc = n0 * n1;   // the result size was checked by the caller (nd_size fits)
    int32_t i;

    strides[nb]     = c_block ? n1 : 1;
    strides[nb + 1] = c_block ? 1 : n0;

    for (i = nb - 1; i >= 0; i--){
        strides[i] = acc;
        acc *= bshape[i] > 0 ? bshape[i] : 1;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Allocates res of the given shape: C-contiguous when it is empty, else compact per-matrix blocks
// (the last two axes) in F (c_block = 0) or C order.
static int ndl_alloc_blocks(oti_ctx* ctx, int32_t ndim, const int64_t* shape, int32_t c_block,
                            ndarr_t* res){

    int64_t strides[OTI_ND_MAXDIM];
    int64_t size = 1;
    int32_t i;

    for (i = 0; i < ndim; i++){
        if (shape[i] == 0){
            size = 0;
        } else if (size != 0 && oti_ckd_mul_i64(size, shape[i], &size)){
            return OTI_ERR_SIZE;
        }
    }

    if (size == 0 || ndim < 2){
        return nd_alloc(ctx, OTI_F64, ndim, shape, ND_LAYOUT_C, 0, res);
    }

    ndl_block_strides(ndim - 2, shape, shape[ndim - 2], shape[ndim - 1], c_block, strides);

    return nd_alloc_strided(ctx, OTI_F64, ndim, shape, strides, 0, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Estimated serial costs of the LAPACK items (S28; the NDBL_COST table of blas.c, rates per n^3).
static inline double ndl_ns_getrf(int64_t n){

    double n3 = (double)n * (double)n * (double)n;

    return NDBL_GETRF_NS + (n <= 32 ? NDBL_GETRF_NS_FMA_SMALL : NDBL_GETRF_NS_FMA) * n3;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static inline double ndl_ns_getrs(int64_t n, int64_t k){

    return NDBL_GETRS_NS + NDBL_GETRS_NS_FMA * 2.0 * (double)n * (double)n * (double)k;

}
// -------------------------------------------------------------------------------------------------------


// Geometry of the right-hand sides of a solve against a factor batch of fnb axes (NumPy 2 rules: a
// 1-D b is one vector (n,), otherwise (..., n, k) broadcasting against the factor batch).
typedef struct {
    int32_t  vec;                      // b is one vector (n,)
    int64_t  n, k;
    int32_t  nb;                       // batch axes of the result
    int64_t  oshape[OTI_ND_MAXDIM];    // their extents
    int64_t  nout;                     // number of result matrices (checked product)
    int64_t  sb[OTI_ND_MAXDIM];        // b element strides per result batch axis (0: broadcast)
    int64_t  sf[OTI_ND_MAXDIM];        // factor-index strides per result batch axis (0: broadcast)
    int64_t  bs0, bs1;                 // b matrix strides (bs1 = 0 for a vector)
    int32_t  ndim;                     // result rank and extents
    int64_t  shape[OTI_ND_MAXDIM];
} ndl_rhs_t;


// *******************************************************************************************************
// The result geometry of b against fnb factor batch axes of extents fshape and order n. The broadcast
// count uses checked arithmetic (checker W2 finding 3): OTI_ERR_SIZE before anything is allocated.
static int ndl_rhs_geom(int32_t fnb, const int64_t* fshape, int64_t n, const ndarr_t* b,
                        ndl_rhs_t* r){

    int64_t fstr[OTI_ND_MAXDIM], acc = 1;
    int32_t i, bnb;
    int st = ndbl_check_in(b);

    if (st != OTI_OK){
        return st;
    }

    r->vec = b->ndim == 1;

    if (b->ndim == 0 || b->shape[r->vec ? 0 : b->ndim - 2] != n){
        return OTI_ERR_SHAPE;
    }

    bnb    = r->vec ? 0 : b->ndim - 2;
    r->n   = n;
    r->k   = r->vec ? 1 : b->shape[b->ndim - 1];
    r->bs0 = b->strides[r->vec ? 0 : b->ndim - 2];
    r->bs1 = r->vec ? 0 : b->strides[b->ndim - 1];
    r->nb  = fnb > bnb ? fnb : bnb;

    if (!ndbl_fits(r->k)){
        return OTI_ERR_SIZE;
    }

    // Factor indices: C order over the factor batch (its product fits: the factors exist).
    for (i = fnb - 1; i >= 0; i--){
        fstr[i] = acc;
        acc    *= fshape[i] > 0 ? fshape[i] : 1;
    }

    r->nout = 1;

    for (i = 0; i < r->nb; i++){

        int32_t ia = i - (r->nb - fnb), ib = i - (r->nb - bnb);
        int64_t ea = ia >= 0 ? fshape[ia] : 1, eb = ib >= 0 ? b->shape[ib] : 1;

        if (ea != eb && ea != 1 && eb != 1){
            return OTI_ERR_SHAPE;
        }

        r->oshape[i] = ea == 1 ? eb : ea;
        r->sf[i]     = (ia >= 0 && ea != 1) ? fstr[ia] : 0;
        r->sb[i]     = (ib >= 0 && eb != 1) ? b->strides[ib] : 0;

        if (r->oshape[i] == 0 || r->nout == 0){
            r->nout = 0;
        } else if (oti_ckd_mul_i64(r->nout, r->oshape[i], &r->nout)){
            return OTI_ERR_SIZE;
        }

    }

    r->ndim = r->nb;

    for (i = 0; i < r->nb; i++){
        r->shape[i] = r->oshape[i];
    }

    r->shape[r->ndim++] = n;

    if (!r->vec){
        r->shape[r->ndim++] = r->k;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The new result of a solve: C-contiguous for a vector result, else compact per-matrix F blocks.
static int ndl_rhs_alloc(oti_ctx* ctx, const ndl_rhs_t* r, ndarr_t* res){

    return r->vec ? nd_alloc(ctx, OTI_F64, r->ndim, r->shape, ND_LAYOUT_C, 0, res)
                  : ndl_alloc_blocks(ctx, r->ndim, r->shape, 0, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks of a written solve output: exactly the result shape, writeable, no internal overlap.
static int ndl_rhs_check_out(const ndl_rhs_t* r, const ndarr_t* out){

    int st = ndbl_check_out(out);

    if (st == OTI_OK && !ndbl_same_shape(out, r->ndim, r->shape)){
        st = OTI_ERR_SHAPE;
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// Solves in place in x (n x k, F with leading dimension ld) with the factors of index fidx.
typedef int (*ndl_solve_fn)(const void* farg, int64_t fidx, double* x, int64_t ld, int64_t k);

// Argument of the per-matrix items of ndl_solve_into().
typedef struct {
    const ndl_rhs_t* r;
    const double*    pb;                    // b (or its snapshot)
    double*          po;                    // out
    int64_t          so[OTI_ND_MAXDIM];     // out element strides per result batch axis
    int64_t          bsb[OTI_ND_MAXDIM];    // b element strides per result batch axis
    int64_t          bs0, bs1;              // b matrix strides
    int64_t          os0, os1;              // out matrix strides
    int32_t          inplace;               // out matrices 'N'-usable: solve in them
    int32_t          same;                  // b is out (exact): nothing to copy first
    int64_t          ld;                    // leading dimension of out's matrices when inplace
    ndbl_scratch_t*  scr;
    ndl_solve_fn     fn;
    const void*      farg;
} ndl_into_t;


// *******************************************************************************************************
// One result matrix: b's block into x (out's block, or per-worker scratch), solve, copy out.
static int ndl_into_item(void* arg, int64_t item, int32_t worker){

    const ndl_into_t* s = (const ndl_into_t*)arg;
    const ndl_rhs_t*  r = s->r;
    int64_t ob = ndl_offset(r->nb, r->oshape, s->bsb, item);
    int64_t oo = ndl_offset(r->nb, r->oshape, s->so, item);
    int64_t fi = ndl_offset(r->nb, r->oshape, r->sf, item);
    int64_t ld = s->inplace ? s->ld : r->n;
    double* x  = s->inplace ? s->po + oo : (double*)ndbl_scratch_get(s->scr, worker);
    ndbl_m2_t m;
    int st;

    if (x == NULL){
        return OTI_ERR_MEMORY;
    }

    if (!(s->inplace && s->same)){
        m.p  = (double*)s->pb + ob;
        m.n0 = r->n;
        m.s0 = s->bs0;
        m.n1 = r->k;
        m.s1 = s->bs1;
        ndbl_pack2(&m, x, ld);
    }

    st = s->fn(s->farg, fi, x, ld, r->k);

    if (st == OTI_OK && !s->inplace){
        m.p  = s->po + oo;
        m.n0 = r->n;
        m.s0 = s->os0;
        m.n1 = r->k;
        m.s1 = s->os1;
        ndbl_unpack2(x, r->n, &m);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Solves every result matrix into out (exactly the result shape, checked by the caller): in place
// when out's matrices are 'N'-usable, else through per-worker F scratch; a b partially overlapping out
// is first copied into a snapshot. `held` bytes of temporaries are already live (the factors); held
// plus everything allocated here is checked against the temp budget once, before allocating.
static int ndl_solve_into(oti_ctx* ctx, const ndl_rhs_t* r, const ndarr_t* b, ndarr_t* out,
                          ndl_solve_fn fn, const void* farg, int64_t held){

    ndl_into_t s;
    ndbl_scratch_t scr;
    ndarr_t snap;
    int64_t slot = 0, snap_bytes = 0, total, per_chunk = 1, ld = 0, nslots;
    int32_t workers, i, share;
    double* snap_mem = NULL;
    ndbl_m2_t om;
    int st;

    if (r->nout == 0 || r->n == 0 || r->k == 0){
        return OTI_OK;                                // empty: no provider call ([k5])
    }

    memset(&s, 0, sizeof(s));
    s.r   = r;
    s.po  = (double*)out->data;
    s.pb  = (const double*)b->data;
    s.bs0 = r->bs0;
    s.bs1 = r->bs1;
    s.fn  = fn;
    s.farg = farg;
    s.os0 = out->strides[r->vec ? out->ndim - 1 : out->ndim - 2];
    s.os1 = r->vec ? 0 : out->strides[out->ndim - 1];

    for (i = 0; i < r->nb; i++){
        s.so[i]  = out->strides[i];
        s.bsb[i] = r->sb[i];
    }

    om.p  = s.po;
    om.n0 = r->n;
    om.s0 = s.os0;
    om.n1 = r->k;
    om.s1 = s.os1;
    s.inplace = ndbl_usable_n(&om, &ld) && ndbl_fits(ld);
    s.ld      = ld;
    share     = nd_may_share_memory(out, b);
    s.same    = share == ND_SHARE_EXACT;

    workers = ndbl_batch_workers(ctx, r->nout, ndl_ns_getrs(r->n, r->k), &per_chunk);
    nslots  = workers > 1 ? workers : 1;

    st = ndbl_bytes(s.inplace ? 0 : r->n * r->k, 0, &slot);   // n * k fits: out has those elements

    if (st == OTI_OK && share == ND_SHARE_MAYBE){
        st = ndbl_bytes(nd_size(b), 0, &snap_bytes);
    }
    if (st == OTI_OK && (oti_ckd_mul_i64(slot, nslots, &total)
                         || oti_ckd_add_i64(total, snap_bytes, &total)
                         || oti_ckd_add_i64(total, held, &total))){
        st = OTI_ERR_SIZE;
    }
    if (st == OTI_OK){
        st = oti_ctx_check_temp(ctx, total);
    }
    if (st != OTI_OK){
        return st;
    }

    // A partial overlap of out with b: solve from a C snapshot of b.
    if (share == ND_SHARE_MAYBE){

        snap_mem = (double*)ndb_aligned_alloc((size_t)snap_bytes);

        if (snap_mem == NULL){
            return OTI_ERR_MEMORY;
        }

        nd_init_empty(&snap);
        st = nd_wrap_trusted(snap_mem, OTI_F64, b->ndim, b->shape, NULL, 1, &snap);

        if (st == OTI_OK){
            st = nd_assign(ctx, b, &snap);
        }
        if (st != OTI_OK){
            free(snap_mem);
            return st;
        }

        s.pb  = snap_mem;
        s.bs0 = snap.strides[r->vec ? snap.ndim - 1 : snap.ndim - 2];
        s.bs1 = r->vec ? 0 : snap.strides[snap.ndim - 1];

        // Same broadcast pattern as b's (an axis of extent 1 or missing in b has stride 0).
        for (i = 0; i < r->nb; i++){
            int32_t ib = i - (r->nb - (r->vec ? 0 : b->ndim - 2));
            s.bsb[i] = (ib >= 0 && b->shape[ib] != 1) ? snap.strides[ib] : 0;
        }

    }

    st = ndbl_scratch_init(ctx, &scr, workers, slot, -1);    // budget already checked above

    if (st == OTI_OK){
        s.scr = &scr;
        st = ndbl_batch_run(ctx, workers, r->nout, per_chunk, ndl_into_item, &s);
        ndbl_scratch_free(&scr);
    }

    free(snap_mem);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void nd_lu_init(nd_lu_t* lu){

    if (lu == NULL){
        return;
    }

    nd_init_empty(&lu->lu);
    lu->ipiv   = NULL;
    lu->n      = 0;
    lu->trans  = 0;
    lu->info   = 0;
    lu->nbatch = 0;
    lu->infos  = NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void nd_lu_free(nd_lu_t* lu){

    if (lu == NULL){
        return;
    }

    nd_release(&lu->lu);
    free(lu->ipiv);
    free(lu->infos);
    nd_lu_init(lu);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The in-place factor view of nd_lu_factor(overwrite = 1): the input itself, with its last two axes
// swapped when the matrices are C-contiguous (read as A^T, trans = 1), so every matrix is F; retained
// when the input has a control block, else a temporary.
static int ndl_lu_inplace(const ndarr_t* a, int32_t trans, ndarr_t* view){

    int32_t perm[OTI_ND_MAXDIM], i, nd = a->ndim;
    ndarr_t tv;
    int st;

    for (i = 0; i < nd; i++){
        perm[i] = i;
    }
    if (trans){
        perm[nd - 2] = nd - 1;
        perm[nd - 1] = nd - 2;
    }

    nd_init_empty(&tv);
    st = nd_view_transpose(a, nd, perm, &tv);

    if (st != OTI_OK){
        return st;
    }
    if (a->buf != NULL){
        return nd_view_retain(&tv, view);             // OTI_ERR_BUSY while the buffer grows ([cL2])
    }

    nd_move(&tv, view);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// Argument of the factor items of nd_lu_factor().
typedef struct {
    const ndl_sq_t* g;
    nd_lu_t*        lu;
    int32_t         load;      // 1: copy the matrix into its block first (not in place)
} ndl_factor_t;


// *******************************************************************************************************
// One matrix of nd_lu_factor(): (load and) dgetrf in its block; its info is recorded, never failed.
static int ndl_factor_item(void* arg, int64_t item, int32_t worker){

    const ndl_factor_t* s  = (const ndl_factor_t*)arg;
    const ndl_sq_t*     g  = s->g;
    nd_lu_t*            lu = s->lu;
    double* f = (double*)lu->lu.data + ndl_offset(g->nb, g->bshape, lu->lu.strides, item);
    int info = 0;

    (void)worker;

    if (s->load){
        ndl_load(g->p + ndl_offset(g->nb, g->bshape, g->bstrides, item), g->n, g->s0, g->s1,
                 g->trans, f);
    }

    oti_dgetrf((int)g->n, (int)g->n, f, (int)ndbl_max1(g->n), lu->ipiv + item * g->n, &info);
    lu->infos[item] = info;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Temporary bytes of nd_lu_factor(): ipiv and infos exactly as allocated (at least one element
// each, also for empty stacks), plus the F factor blocks unless the input is factored in place
// (checker W2 finding 8: both branches are charged).
static int ndl_factor_bytes(const ndl_sq_t* g, int64_t npiv, int32_t blocks, int64_t* nbytes){

    int64_t nn = 0, ints;

    if (oti_ckd_add_i64(ndbl_max1(npiv), ndbl_max1(g->nbatch), &ints)
        || oti_ckd_mul_i64(ints, (int64_t)sizeof(int), &ints)
        || (blocks && (oti_ckd_mul_i64(g->n, g->n, &nn) || oti_ckd_mul_i64(nn, g->nbatch, &nn)))){
        return OTI_ERR_SIZE;
    }

    return ndbl_bytes(nn, ints, nbytes);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_lu_factor() without the entry checks and the error record; *held receives the bytes of
// temporaries it charged (in place: ipiv and infos only). Everything is checked before allocating,
// retaining or factoring; on failure the caller frees lu.
static int ndl_lu_factor_core(oti_ctx* ctx, ndarr_t* a, int32_t overwrite, nd_lu_t* lu,
                              int64_t* held){

    ndl_sq_t g;
    ndl_factor_t f;
    int64_t nbytes = 0, npiv, i, per_chunk = 1;
    int32_t workers, inplace = 0;
    int st = ndl_square(a, &g);

    *held = 0;

    if (st != OTI_OK){
        return st;
    }

    // In place: writeable, every matrix C- or F-contiguous, and no two matrices sharing memory.
    if (overwrite && (a->flags & ND_WRITEABLE)
        && (g.n <= 1 || (g.s0 == 1 && g.s1 == g.n) || (g.s1 == 1 && g.s0 == g.n))
        && (g.nb == 0 || nd_internal_overlap(a) == 0)){
        inplace = 1;
    }

    lu->trans  = g.trans;
    lu->n      = g.n;
    lu->nbatch = g.nbatch;

    if (oti_ckd_mul_i64(g.nbatch, g.n, &npiv)){
        return OTI_ERR_SIZE;
    }

    st = ndl_factor_bytes(&g, npiv, !inplace, &nbytes);

    if (st == OTI_OK){
        st = oti_ctx_check_temp(ctx, nbytes);
    }
    if (st != OTI_OK){
        return st;
    }

    *held = nbytes;
    st    = inplace ? ndl_lu_inplace(a, g.trans, &lu->lu)
                    : ndl_alloc_blocks(ctx, a->ndim, a->shape, 0, &lu->lu);

    if (st == OTI_OK){
        lu->ipiv  = (int*)ndb_malloc((size_t)ndbl_max1(npiv) * sizeof(int));
        lu->infos = (int*)ndb_malloc((size_t)ndbl_max1(g.nbatch) * sizeof(int));
        st = (lu->ipiv == NULL || lu->infos == NULL) ? OTI_ERR_MEMORY : OTI_OK;
    }

    if (st != OTI_OK){
        return st;
    }

    for (i = 0; i < g.nbatch; i++){
        lu->infos[i] = 0;
    }

    if (g.n > 0 && g.nbatch > 0){
        f.g     = &g;
        f.lu    = lu;
        f.load  = !inplace;
        workers = ndbl_batch_workers(ctx, g.nbatch, ndl_ns_getrf(g.n), &per_chunk);
        st      = ndbl_batch_run(ctx, workers, g.nbatch, per_chunk, ndl_factor_item, &f);
    }

    for (i = 0; st == OTI_OK && i < g.nbatch; i++){
        if (lu->infos[i] > 0){
            lu->info = lu->infos[i];
            break;
        }
    }

    return st != OTI_OK ? st : (lu->info > 0 ? lu->info : OTI_OK);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_lu_factor(oti_ctx* ctx, ndarr_t* a, int32_t overwrite, nd_lu_t* lu){

    int64_t held;
    int st = oti_ctx_check(ctx);

    nd_lu_init(lu);

    if (lu == NULL || (overwrite != 0 && overwrite != 1)){
        st = OTI_ERR_ARGUMENT;
    }
    if (st == OTI_OK){
        st = ndl_lu_factor_core(ctx, a, overwrite, lu, &held);
        if (st < 0){
            nd_lu_free(lu);
        }
    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_lu_factor", st > 0 ? "exactly singular matrix" : NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// dgetrs on the factors of index fidx (farg: the nd_lu_t).
static int ndl_lu_fn(const void* farg, int64_t fidx, double* x, int64_t ld, int64_t k){

    const nd_lu_t* lu = (const nd_lu_t*)farg;
    int32_t nb = lu->lu.ndim - 2;
    const double* f = (const double*)lu->lu.data + ndl_offset(nb, lu->lu.shape, lu->lu.strides, fidx);
    int info = 0;

    oti_dgetrs(lu->trans ? 'T' : 'N', (int)lu->n, (int)k, f, (int)ndbl_max1(lu->n),
               lu->ipiv + fidx * lu->n, x, (int)ld, &info);

    return info == 0 ? OTI_OK : OTI_ERR_ARGUMENT;   // not reachable with legal arguments

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks of a factorization handed to a solve.
static int ndl_lu_check(const nd_lu_t* lu){

    if (lu == NULL || lu->lu.ndim < 2 || (lu->n > 0 && lu->nbatch > 0 && lu->ipiv == NULL)){
        return OTI_ERR_ARGUMENT;
    }

    return lu->info > 0 ? lu->info : OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_lu_solve(oti_ctx* ctx, const nd_lu_t* lu, const ndarr_t* b, ndarr_t* res){

    ndl_rhs_t r;
    int st = oti_ctx_check(ctx);

    ndbl_debug_res(res);

    if (res == NULL){
        st = OTI_ERR_ARGUMENT;
    } else {
        nd_init_empty(res);
    }
    if (st == OTI_OK){
        st = ndl_lu_check(lu);
    }
    if (st == OTI_OK){
        st = ndl_rhs_geom(lu->lu.ndim - 2, lu->lu.shape, lu->n, b, &r);
    }
    if (st == OTI_OK){
        st = ndl_rhs_alloc(ctx, &r, res);
    }
    if (st == OTI_OK){
        st = ndl_solve_into(ctx, &r, b, res, ndl_lu_fn, lu, 0);
    }

    if (st != OTI_OK){
        if (res != NULL){
            nd_release(res);
        }
        oti_ctx_set_error(ctx, st, "nd_lu_solve", st > 0 ? "exactly singular matrix" : NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_lu_solve_to(oti_ctx* ctx, const nd_lu_t* lu, const ndarr_t* b, ndarr_t* out){

    ndl_rhs_t r;
    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndl_lu_check(lu);
    }
    if (st == OTI_OK){
        st = ndl_rhs_geom(lu->lu.ndim - 2, lu->lu.shape, lu->n, b, &r);
    }
    if (st == OTI_OK){
        st = ndl_rhs_check_out(&r, out);
    }
    if (st == OTI_OK && nd_may_share_memory(out, &lu->lu) != ND_SHARE_NONE){
        st = OTI_ERR_LAYOUT;
    }
    if (st == OTI_OK){
        st = ndl_solve_into(ctx, &r, b, out, ndl_lu_fn, lu, 0);
    }

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_lu_solve_to", st > 0 ? "exactly singular matrix" : NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Shared body of nd_solve() / nd_solve_to(): res_new = 1 allocates *out first. The factors of a are a
// private copy, so out may overlap a; nothing is factored when the result is empty ([k5]).
static int ndl_solve_common(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out,
                            int32_t res_new){

    ndl_sq_t  g;
    ndl_rhs_t r;
    nd_lu_t   lu;
    int64_t   held = 0;
    int st = ndl_square(a, &g);

    if (st == OTI_OK){
        st = ndl_rhs_geom(g.nb, g.bshape, g.n, b, &r);
    }
    if (st == OTI_OK){
        st = res_new ? ndl_rhs_alloc(ctx, &r, out) : ndl_rhs_check_out(&r, out);
    }
    if (st != OTI_OK || r.nout == 0 || r.n == 0 || r.k == 0){
        return st;
    }

    nd_lu_init(&lu);
    st = ndl_lu_factor_core(ctx, (ndarr_t*)a, 0, &lu, &held);   // overwrite = 0: a is not written

    // The first exactly singular matrix in C order of a's batch is also the first in C order of the
    // result's batch (each factor index first appears with its broadcast coordinates at 0).
    if (st == OTI_OK){
        st = ndl_solve_into(ctx, &r, b, out, ndl_lu_fn, &lu, held);
    }

    nd_lu_free(&lu);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_solve(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* res){

    int st = oti_ctx_check(ctx);

    ndbl_debug_res(res);

    if (res == NULL){
        st = OTI_ERR_ARGUMENT;
    } else {
        nd_init_empty(res);
    }
    if (st == OTI_OK){
        st = ndl_solve_common(ctx, a, b, res, 1);
    }

    if (st != OTI_OK){
        if (res != NULL){
            nd_release(res);
        }
        oti_ctx_set_error(ctx, st, "nd_solve", st > 0 ? "exactly singular matrix" : NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_solve_to(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out){

    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndl_solve_common(ctx, a, b, out, 0);
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_solve_to", st > 0 ? "exactly singular matrix" : NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// Argument of the per-matrix items of nd_inv(), nd_det() / nd_slogdet() and nd_cholesky().
typedef struct {
    const ndl_sq_t*  g;
    ndbl_scratch_t*  scr;
    double*          pr;        // result data (inv, cholesky: blocks of n*n; det: one per matrix)
    double*          psign;     // slogdet sign, or NULL
    double*          plog;      // slogdet logabs, or NULL
    int              lwork;     // inv
    int32_t          lower;     // cholesky
} ndl_item_arg_t;


// *******************************************************************************************************
// One matrix of nd_inv(): loaded into its result block, dgetrf, dgetri (per-worker ipiv and work).
static int ndl_inv_item(void* arg, int64_t item, int32_t worker){

    const ndl_item_arg_t* s = (const ndl_item_arg_t*)arg;
    const ndl_sq_t* g = s->g;
    double* f = s->pr + item * g->n * g->n;
    double* work = (double*)ndbl_scratch_get(s->scr, worker);
    int* ipiv;
    int info = 0;

    if (work == NULL){
        return OTI_ERR_MEMORY;
    }

    ipiv = (int*)(work + s->lwork);
    ndl_load(g->p + ndl_offset(g->nb, g->bshape, g->bstrides, item), g->n, g->s0, g->s1, g->trans, f);
    oti_dgetrf((int)g->n, (int)g->n, f, (int)g->n, ipiv, &info);

    if (info > 0){
        return info;
    }

    // trans = 1: the block holds (A^T)^-1 = (A^-1)^T in column major, i.e. A^-1 in C order.
    oti_dgetri((int)g->n, f, (int)g->n, ipiv, work, s->lwork, &info);

    return info;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_inv(oti_ctx* ctx, const ndarr_t* a, ndarr_t* res){

    ndl_sq_t g;
    ndl_item_arg_t s;
    ndbl_scratch_t scr;
    int64_t nbytes, per_chunk = 1;
    int32_t workers;
    double  q = 0.0, ns;
    int info = 0, ipiv_dummy = 0;
    int st = oti_ctx_check(ctx);

    ndbl_debug_res(res);

    if (res == NULL){
        st = OTI_ERR_ARGUMENT;
    } else {
        nd_init_empty(res);
    }
    if (st == OTI_OK){
        st = ndl_square(a, &g);
    }
    if (st == OTI_OK){
        // Result blocks in the orientation of the factors: C for C-contiguous matrices, else F.
        st = ndl_alloc_blocks(ctx, a->ndim, a->shape, g.trans, res);
    }

    if (st == OTI_OK && nd_size(res) > 0){

        memset(&s, 0, sizeof(s));
        s.g  = &g;
        s.pr = (double*)res->data;

        // Workspace query (lwork = -1 touches neither a nor ipiv).
        oti_dgetri((int)g.n, s.pr, (int)g.n, &ipiv_dummy, &q, -1, &info);
        st = info == 0 ? oti_lapack_lwork(q, g.n, &s.lwork) : OTI_ERR_ARGUMENT;

        if (st == OTI_OK){
            ns      = ndl_ns_getrf(g.n) + NDBL_GETRI_NS
                      + NDBL_GETRI_NS_FMA * (double)g.n * (double)g.n * (double)g.n;
            workers = ndbl_batch_workers(ctx, g.nbatch, ns, &per_chunk);
            st      = ndbl_bytes(s.lwork, g.n * (int64_t)sizeof(int), &nbytes);

            if (st == OTI_OK){
                st = ndbl_scratch_init(ctx, &scr, workers, nbytes, 0);
            }
            if (st == OTI_OK){
                s.scr = &scr;
                st = ndbl_batch_run(ctx, workers, g.nbatch, per_chunk, ndl_inv_item, &s);
                ndbl_scratch_free(&scr);
            }
        }

    }

    if (st != OTI_OK){
        if (res != NULL){
            nd_release(res);
        }
        oti_ctx_set_error(ctx, st, "nd_inv", st > 0 ? "exactly singular matrix" : NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// One matrix of nd_det() / nd_slogdet(): factored in per-worker scratch; sign = p * prod sign(u_ii),
// logabs = sum log|u_ii| in index order, det = sign * exp(logabs) (S20). An exactly zero pivot gives
// (0, -inf) and det 0 without touching the later entries.
static int ndl_det_item(void* arg, int64_t item, int32_t worker){

    const ndl_item_arg_t* s = (const ndl_item_arg_t*)arg;
    const ndl_sq_t* g = s->g;
    double* f = (double*)ndbl_scratch_get(s->scr, worker);
    double  sign = 1.0, logabs = 0.0;
    int*    ipiv;
    int64_t i;
    int     info = 0, neg = 0;

    if (f == NULL){
        return OTI_ERR_MEMORY;
    }

    ipiv = (int*)(f + g->n * g->n);
    ndl_load(g->p + ndl_offset(g->nb, g->bshape, g->bstrides, item), g->n, g->s0, g->s1, g->trans, f);
    oti_dgetrf((int)g->n, (int)g->n, f, (int)g->n, ipiv, &info);

    if (info > 0){
        sign   = 0.0;
        logabs = -INFINITY;
    } else {
        for (i = 0; i < g->n; i++){
            double u = f[i + i * g->n];
            if (ipiv[i] != (int)(i + 1)){
                neg ^= 1;
            }
            if (u < 0.0){
                neg ^= 1;
            }
            logabs += log(fabs(u));
        }
        sign = neg ? -1.0 : 1.0;
    }

    if (s->psign != NULL){
        s->psign[item] = sign;
        s->plog[item]  = logabs;
    } else {
        s->pr[item] = info > 0 ? 0.0 : sign * exp(logabs);
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Shared body of nd_det() (det != NULL) and nd_slogdet().
static int ndl_det_common(oti_ctx* ctx, const ndarr_t* a, ndarr_t* det, ndarr_t* sign,
                          ndarr_t* logabs){

    ndl_sq_t g;
    ndl_item_arg_t s;
    ndbl_scratch_t scr;
    int64_t nbytes, per_chunk = 1, i;
    int32_t workers;
    double  ns;
    int st = ndl_square(a, &g);

    if (st != OTI_OK){
        return st;
    }

    if (det != NULL){
        st = nd_alloc(ctx, OTI_F64, g.nb, g.bshape, ND_LAYOUT_C, 0, det);
    } else {
        st = nd_alloc(ctx, OTI_F64, g.nb, g.bshape, ND_LAYOUT_C, 0, sign);
        if (st == OTI_OK){
            st = nd_alloc(ctx, OTI_F64, g.nb, g.bshape, ND_LAYOUT_C, 0, logabs);
        }
    }
    if (st != OTI_OK || g.nbatch == 0){
        return st;
    }

    memset(&s, 0, sizeof(s));
    s.g = &g;

    if (det != NULL){
        s.pr = (double*)det->data;
    } else {
        s.psign = (double*)sign->data;
        s.plog  = (double*)logabs->data;
    }

    // 0 x 0: det 1, slogdet (1, 0), no provider call.
    if (g.n == 0){
        for (i = 0; i < g.nbatch; i++){
            if (det != NULL){
                s.pr[i] = 1.0;
            } else {
                s.psign[i] = 1.0;
                s.plog[i]  = 0.0;
            }
        }
        return OTI_OK;
    }

    ns      = ndl_ns_getrf(g.n) + NDBL_DET_NS;
    workers = ndbl_batch_workers(ctx, g.nbatch, ns, &per_chunk);
    st      = ndbl_bytes(g.n * g.n, g.n * (int64_t)sizeof(int), &nbytes);

    if (st == OTI_OK){
        st = ndbl_scratch_init(ctx, &scr, workers, nbytes, 0);
    }
    if (st == OTI_OK){
        s.scr = &scr;
        st = ndbl_batch_run(ctx, workers, g.nbatch, per_chunk, ndl_det_item, &s);
        ndbl_scratch_free(&scr);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_det(oti_ctx* ctx, const ndarr_t* a, ndarr_t* res){

    int st = oti_ctx_check(ctx);

    ndbl_debug_res(res);

    if (res == NULL){
        st = OTI_ERR_ARGUMENT;
    } else {
        nd_init_empty(res);
    }
    if (st == OTI_OK){
        st = ndl_det_common(ctx, a, res, NULL, NULL);
    }

    if (st != OTI_OK){
        if (res != NULL){
            nd_release(res);
        }
        oti_ctx_set_error(ctx, st, "nd_det", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_slogdet(oti_ctx* ctx, const ndarr_t* a, ndarr_t* sign, ndarr_t* logabs){

    int st = oti_ctx_check(ctx);

    ndbl_debug_res(sign);
    ndbl_debug_res(logabs);

    if (sign == NULL || logabs == NULL || sign == logabs){
        st = OTI_ERR_ARGUMENT;
    } else {
        nd_init_empty(sign);
        nd_init_empty(logabs);
    }
    if (st == OTI_OK){
        st = ndl_det_common(ctx, a, NULL, sign, logabs);
    }

    if (st != OTI_OK){
        if (sign != NULL && sign != logabs){
            nd_release(sign);
            nd_release(logabs);
        }
        oti_ctx_set_error(ctx, st, "nd_slogdet", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// One matrix of nd_cholesky(): the block M (F order) is A, or A^T for a C-contiguous A (trans = 1).
// The chosen triangle of A is the same triangle of M (trans = 0) or the other one (trans = 1), so
// dpotrf gets uplo = (lower XOR trans) ? 'L' : 'U'; the other triangle of M is then zeroed. Read in
// the result's orientation, the block is L (lower) or U.
static int ndl_chol_item(void* arg, int64_t item, int32_t worker){

    const ndl_item_arg_t* s = (const ndl_item_arg_t*)arg;
    const ndl_sq_t* g = s->g;
    double* f = s->pr + item * g->n * g->n;
    const double* src = g->p + ndl_offset(g->nb, g->bshape, g->bstrides, item);
    int64_t i, j, n = g->n;
    int     m_lower = (s->lower ^ g->trans) != 0;
    int     info = 0;

    (void)worker;

    // Copy only the triangle dpotrf reads (in M's terms), zero the other one.
    for (j = 0; j < n; j++){
        for (i = 0; i < n; i++){
            int keep = m_lower ? (i >= j) : (i <= j);
            // M(i, j) = A(i, j) for trans = 0, A(j, i) for trans = 1.
            f[i + j * n] = !keep ? 0.0
                         : g->trans ? src[j * g->s0 + i * g->s1] : src[i * g->s0 + j * g->s1];
        }
    }

    oti_dpotrf(m_lower ? 'L' : 'U', (int)n, f, (int)n, &info);

    return info > 0 ? OTI_ERR_NOTPD : (info == 0 ? OTI_OK : OTI_ERR_ARGUMENT);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_cholesky(oti_ctx* ctx, const ndarr_t* a, int32_t lower, ndarr_t* res){

    ndl_sq_t g;
    ndl_item_arg_t s;
    int64_t per_chunk = 1;
    int32_t workers;
    double  ns;
    int st = oti_ctx_check(ctx);

    ndbl_debug_res(res);

    if (res == NULL || (lower != 0 && lower != 1)){
        st = OTI_ERR_ARGUMENT;
    }
    if (res != NULL){
        nd_init_empty(res);
    }
    if (st == OTI_OK){
        st = ndl_square(a, &g);
    }
    if (st == OTI_OK){
        st = ndl_alloc_blocks(ctx, a->ndim, a->shape, g.trans, res);
    }

    if (st == OTI_OK && nd_size(res) > 0){
        memset(&s, 0, sizeof(s));
        s.g     = &g;
        s.pr    = (double*)res->data;
        s.lower = lower;
        ns      = NDBL_POTRF_NS + NDBL_POTRF_NS_FMA * (double)g.n * (double)g.n * (double)g.n;
        workers = ndbl_batch_workers(ctx, g.nbatch, ns, &per_chunk);
        st      = ndbl_batch_run(ctx, workers, g.nbatch, per_chunk, ndl_chol_item, &s);
    }

    if (st != OTI_OK){
        if (res != NULL){
            nd_release(res);
        }
        oti_ctx_set_error(ctx, st, "nd_cholesky", st == OTI_ERR_NOTPD ? "not positive definite"
                                                                      : NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// A 2-D factor of dpotrs / dtrtrs, as the solve reads it.
typedef struct {
    const double* p;
    int64_t       n;
    char          uplo, trans, diag;
} ndl_tri_t;


// *******************************************************************************************************
// The factor t (n x n) read in place when F-contiguous (*flip = 0) or C-contiguous (*flip = 1: the
// stored matrix is the transpose) and not overlapping out; else packed into *tmp (F), charged to the
// temp budget (its bytes in *held).
static int ndl_tri_operand(oti_ctx* ctx, const ndarr_t* t, int64_t n, const ndarr_t* out,
                           const double** p, int* flip, double** tmp, int64_t* held){

    int64_t s0 = t->strides[0], s1 = t->strides[1], nbytes;
    ndbl_m2_t x;
    int st;

    *tmp  = NULL;
    *flip = 0;
    *held = 0;
    *p    = (const double*)t->data;

    if (nd_may_share_memory(out, t) == ND_SHARE_NONE){
        if (n <= 1 || (s0 == 1 && s1 == n)){
            return OTI_OK;
        }
        if (s1 == 1 && s0 == n){
            *flip = 1;
            return OTI_OK;
        }
    }

    st = ndbl_bytes(n * n, 0, &nbytes);   // n * n fits: t has those elements

    if (st == OTI_OK){
        st = oti_ctx_check_temp(ctx, nbytes);
    }
    if (st == OTI_OK){
        *tmp = (double*)ndb_aligned_alloc((size_t)nbytes);
        st   = *tmp == NULL ? OTI_ERR_MEMORY : OTI_OK;
    }
    if (st == OTI_OK){
        x.p  = (double*)t->data;
        x.n0 = n;
        x.n1 = n;
        x.s0 = s0;
        x.s1 = s1;
        ndbl_pack2(&x, *tmp, ndbl_max1(n));
        *p    = *tmp;
        *held = nbytes;
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks of a 2-D square OTI_F64 factor; *n its order.
static int ndl_check_factor(const ndarr_t* c, int64_t* n){

    int st = ndbl_check_in(c);

    if (st != OTI_OK){
        return st;
    }
    if (c->ndim != 2 || c->shape[0] != c->shape[1]){
        return OTI_ERR_SHAPE;
    }

    *n = c->shape[0];

    return ndbl_fits(*n) ? OTI_OK : OTI_ERR_SIZE;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int ndl_cho_fn(const void* farg, int64_t fidx, double* x, int64_t ld, int64_t k){

    const ndl_tri_t* t = (const ndl_tri_t*)farg;
    int info = 0;

    (void)fidx;
    oti_dpotrs(t->uplo, (int)t->n, (int)k, t->p, (int)ndbl_max1(t->n), x, (int)ld, &info);

    return info == 0 ? OTI_OK : OTI_ERR_ARGUMENT;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int ndl_trs_fn(const void* farg, int64_t fidx, double* x, int64_t ld, int64_t k){

    const ndl_tri_t* t = (const ndl_tri_t*)farg;
    int info = 0;

    (void)fidx;
    oti_dtrtrs(t->uplo, t->trans, t->diag, (int)t->n, (int)k, t->p, (int)ndbl_max1(t->n), x,
               (int)ld, &info);

    return info > 0 ? info : (info == 0 ? OTI_OK : OTI_ERR_ARGUMENT);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Shared body of the Cholesky and triangular solves. kind 0: dpotrs (lower); 1: dtrtrs. res_new = 1
// allocates *out first. A C-contiguous factor is used as its transpose, with uplo (and, for dtrtrs,
// trans) flipped: a C-contiguous L is U = L^T in column major, and T x = b is M^T x = b for M = T^T.
static int ndl_tri_common(oti_ctx* ctx, int32_t kind, const ndarr_t* t, const ndarr_t* b,
                          int32_t lower, int32_t trans, int32_t unit, ndarr_t* out,
                          int32_t res_new){

    ndl_rhs_t r;
    ndl_tri_t f;
    double* tmp = NULL;
    int64_t n = 0, held = 0;
    int flip = 0;
    int st = ndl_check_factor(t, &n);

    if (st == OTI_OK){
        st = ndl_rhs_geom(0, NULL, n, b, &r);
    }
    if (st == OTI_OK){
        st = res_new ? ndl_rhs_alloc(ctx, &r, out) : ndl_rhs_check_out(&r, out);
    }
    if (st != OTI_OK || r.nout == 0 || r.n == 0 || r.k == 0){
        return st;
    }

    st = ndl_tri_operand(ctx, t, n, out, &f.p, &flip, &tmp, &held);

    if (st == OTI_OK){
        f.n     = n;
        f.uplo  = (lower ^ flip) ? 'L' : 'U';
        f.trans = (trans ^ flip) ? 'T' : 'N';
        f.diag  = unit ? 'U' : 'N';
        st = ndl_solve_into(ctx, &r, b, out, kind == 0 ? ndl_cho_fn : ndl_trs_fn, &f, held);
    }

    free(tmp);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_cho_solve(oti_ctx* ctx, const ndarr_t* c, int32_t lower, const ndarr_t* b, ndarr_t* res){

    int st = oti_ctx_check(ctx);

    ndbl_debug_res(res);

    if (res == NULL || (lower != 0 && lower != 1)){
        st = OTI_ERR_ARGUMENT;
    }
    if (res != NULL){
        nd_init_empty(res);
    }
    if (st == OTI_OK){
        st = ndl_tri_common(ctx, 0, c, b, lower, 0, 0, res, 1);
    }

    if (st != OTI_OK){
        if (res != NULL){
            nd_release(res);
        }
        oti_ctx_set_error(ctx, st, "nd_cho_solve", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_cho_solve_to(oti_ctx* ctx, const ndarr_t* c, int32_t lower, const ndarr_t* b, ndarr_t* out){

    int st = oti_ctx_check(ctx);

    if (st == OTI_OK && lower != 0 && lower != 1){
        st = OTI_ERR_ARGUMENT;
    }
    if (st == OTI_OK){
        st = ndl_tri_common(ctx, 0, c, b, lower, 0, 0, out, 0);
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_cho_solve_to", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Flag checks of the triangular solves.
static inline int ndl_tri_flags(int32_t lower, int32_t trans, int32_t unit){

    return ((lower != 0 && lower != 1) || (trans != 0 && trans != 1) || (unit != 0 && unit != 1))
           ? OTI_ERR_ARGUMENT : OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_solve_triangular(oti_ctx* ctx, const ndarr_t* t, const ndarr_t* b, int32_t lower,
                        int32_t trans, int32_t unit_diagonal, ndarr_t* res){

    int st = oti_ctx_check(ctx);

    ndbl_debug_res(res);

    if (res == NULL){
        st = OTI_ERR_ARGUMENT;
    } else {
        nd_init_empty(res);
    }
    if (st == OTI_OK){
        st = ndl_tri_flags(lower, trans, unit_diagonal);
    }
    if (st == OTI_OK){
        st = ndl_tri_common(ctx, 1, t, b, lower, trans, unit_diagonal, res, 1);
    }

    if (st != OTI_OK){
        if (res != NULL){
            nd_release(res);
        }
        oti_ctx_set_error(ctx, st, "nd_solve_triangular", st > 0 ? "singular triangular matrix"
                                                                 : NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_solve_triangular_to(oti_ctx* ctx, const ndarr_t* t, const ndarr_t* b, int32_t lower,
                           int32_t trans, int32_t unit_diagonal, ndarr_t* out){

    int st = oti_ctx_check(ctx);

    if (st == OTI_OK){
        st = ndl_tri_flags(lower, trans, unit_diagonal);
    }
    if (st == OTI_OK){
        st = ndl_tri_common(ctx, 1, t, b, lower, trans, unit_diagonal, out, 0);
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_solve_triangular_to", st > 0 ? "singular triangular matrix"
                                                                    : NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------
