// Dense SoA arrays: memory, element and block access, conversions to and from arrso_t, truncation
// and compaction (include/oti/dense/soa/base.h). Template: src/c/semisparse/soa/base.c.
//
// A dense array over bases 1..nact is the semi-sparse layout of the active set [1..nact], so a
// smaller-nact array is a prefix of a larger one: order-p block i of the small layout is block i of
// order p in the large one. Unity-included from src/c/dense.c: static helpers carry the dnob_ prefix.
//
// Storage (Phase 7a, include/oti/dense/soa/structures.h): the blocks live in one nd_buffer_t
// (nd_alloc(), 64-byte aligned, OWNS | GROWABLE) described by the (nblocks, *S) descriptor `blocks`;
// the layout (nact, trc_order, act_order) lives in the array's oti_meta_t. Every owning array has a
// buffer (at least one real, also when S has a zero extent) and a meta. A layout change of an owning
// array is one transaction under the buffer's layout lock (contracts 7.2): oti_meta_layout_begin(),
// nd_grow_locked() when the allocation grows, the block moves, oti_meta_relayout(), then
// oti_meta_layout_end(); it fails with OTI_ERR_BUSY while another reference or an export is alive
// (never in 7a, where no view or export retains a dense buffer).


/// Largest number of element axes (S) of a 7a array: 2 for a matrix, 3 for a Gauss array.
#define DNOB_MAX_SDIM 3

// *******************************************************************************************************
// Element shape S of an array: sdim extents, F order inside a block.
typedef struct {
    int32_t      sdim; ///< Number of element axes, 2 or 3.
    uint64_t ext[DNOB_MAX_SDIM]; ///< Extents.
} dnob_shape_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The matrix shape (nrows, ncols).
static inline dnob_shape_t dnob_shape2(uint64_t nrows, uint64_t ncols){

    dnob_shape_t s;

    s.sdim   = 2;
    s.ext[0] = nrows;
    s.ext[1] = ncols;
    s.ext[2] = 1;

    return s;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The element shape of an array (from its blocks descriptor).
static inline dnob_shape_t dnob_shape_of(const oarr_t* a){

    dnob_shape_t s;
    int32_t d;

    s.sdim   = a->blocks.ndim - 1;
    s.ext[2] = 1;

    for (d = 0; d < s.sdim; d++){
        s.ext[d] = (uint64_t)a->blocks.shape[1 + d];
    }

    return s;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether the element shape of an array is S.
static inline int dnob_shape_is(const oarr_t* a, const dnob_shape_t* S){

    int32_t d;

    if (a->blocks.ndim != 1 + S->sdim){
        return 0;
    }

    for (d = 0; d < S->sdim; d++){

        if ((uint64_t)a->blocks.shape[1 + d] != S->ext[d]){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Empty compact descriptor of sdim element axes: shape (1, 0, ...), no buffer (oarr_init()).
static void dnob_empty_blocks(ndarr_t* b, int32_t sdim){

    int32_t d;

    b->data       = NULL;
    b->ndim       = 1 + sdim;
    b->dtype      = OTI_F64;
    b->flags      = ND_C_CONTIG | ND_F_CONTIG | ND_WRITEABLE;
    b->reserved   = 0;
    b->buf        = NULL;
    b->shape[0]   = 1;
    b->strides[0] = 0;

    for (d = 1; d <= sdim; d++){
        b->shape[d]   = 0;
        b->strides[d] = (d == 1) ? 1 : 0;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes the compact layout (nblocks, *S), F order inside a block, over the array's current data. The
// caller has checked the sizes (dnob_nreals()) and the buffer holds nblocks * prod(S) reals.
static void dnob_set_layout(oarr_t* a, uint64_t nblocks, const dnob_shape_t* S){

    ndarr_t* b = &a->blocks;
    int64_t st = 1;
    int32_t d;

    b->ndim     = 1 + S->sdim;
    b->shape[0] = (int64_t)nblocks;

    for (d = 0; d < S->sdim; d++){
        b->shape[1 + d]   = (int64_t)S->ext[d];
        b->strides[1 + d] = st;
        st *= (int64_t)S->ext[d];
    }

    b->strides[0] = st;
    nd_update_flags(b);

#ifdef OTI_ND_DEBUG
    if (b->buf != NULL){

        const char* lo = (const char*)nd_buffer_base(b->buf);

        assert(nd_validate(b, lo, lo + nd_buffer_nbytes(b->buf), ND_V_SPAN) == OTI_OK);

    }
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A Gauss array (S = (nip, nrows, ncols)) keeps its element shape through any result, reserve or move
// that gives it the same matricized shape nip x (nrows * ncols): replaces a matrix shape S by the
// array's own in that case. The label is metadata only (the memory layout is the same).
static inline void dnob_keep_shape(const oarr_t* res, dnob_shape_t* S){

    if (S->sdim == 2 && oarr_owns(res) && res->blocks.ndim == 4 && S->ext[0] == oarr_nrows(res)
        && S->ext[1] == oarr_ncols(res)){
        *S = dnob_shape_of(res);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nrows * ncols into *p_size; DN_ERR_MEMORY when the product overflows uint64_t.
static int dnob_shape_size(uint64_t nrows, uint64_t ncols, uint64_t* p_size){

    if (ncols != 0 && nrows > UINT64_MAX / ncols){
        return DN_ERR_MEMORY;
    }

    *p_size = nrows * ncols;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// prod(S) into *p_size, checking that the shape is representable in a descriptor: DN_ERR_MEMORY when an
// extent or the product of the nonzero extents exceeds INT64_MAX (nothing is modified).
static int dnob_shape_size_s(const dnob_shape_t* S, uint64_t* p_size){

    uint64_t nz = 1;
    int32_t d;
    int empty = 0;

    // Every extent fits int64_t and the product of the nonzero extents, in bytes, too (the
    // descriptor's type; nd_validate()'s and NumPy's "array is too big" rule): then every compact
    // stride, a prefix product, fits, also for an empty shape such as (0, 2^62).
    for (d = 0; d < S->sdim; d++){

        if (S->ext[d] > (uint64_t)INT64_MAX){
            return DN_ERR_MEMORY;
        }

        if (S->ext[d] == 0){
            empty = 1;
        } else if (dnob_shape_size(nz, S->ext[d], &nz) != DN_OK
                   || nz > (uint64_t)INT64_MAX / sizeof(coeff_t)){
            return DN_ERR_MEMORY;
        }

    }

    *p_size = empty ? 0 : nz;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// DN_OK when the descriptor (nblocks, *S) is representable (nd_validate()'s rule): the product of its
// nonzero extents, the block axis included, in bytes within INT64_MAX, also when S is empty (where
// dnob_nreals() checks nothing); else DN_ERR_MEMORY. S itself passed dnob_shape_size_s().
static int dnob_layout_ok(uint64_t nblocks, const dnob_shape_t* S){

    uint64_t nz = nblocks;
    int32_t d;

    if (nblocks == 0 || nblocks > (uint64_t)INT64_MAX / sizeof(coeff_t)){
        return DN_ERR_MEMORY;
    }

    for (d = 0; d < S->sdim; d++){

        if (S->ext[d] != 0 && (dnob_shape_size(nz, S->ext[d], &nz) != DN_OK
                               || nz > (uint64_t)INT64_MAX / sizeof(coeff_t))){
            return DN_ERR_MEMORY;
        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reals of a (1 + nimag(k, trc)) * size buffer into *p_n; DN_ERR_MEMORY when the count or its byte
// size overflows, or the buffer exceeds the dense byte budget (dnsm_budget()).
static int dnob_nreals(bases_t k, ord_t trc, uint64_t size, size_t* p_n){

    ndir_t nimag;
    uint64_t nblocks;

    if (sshelp_ndir_total_checked(k, trc, &nimag) != SSHELP_OK){
        return DN_ERR_MEMORY;
    }

    nblocks = 1 + (uint64_t)nimag;

    // The block count is an extent of the descriptor (int64_t), also when the size is 0.
    if (nimag >= (ndir_t)INT64_MAX || (size != 0 && nblocks > UINT64_MAX / size)){
        return DN_ERR_MEMORY;
    }

    if (nblocks * size > SIZE_MAX / sizeof(coeff_t) || dnsm_budget(nblocks * size) != DN_OK){
        return DN_ERR_MEMORY;
    }

    *p_n = (size_t)(nblocks * size);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Number of direction blocks (the real one included) of the layout (k, trc).
static inline uint64_t dnob_nblocks(bases_t k, ord_t trc){

    return 1 + (uint64_t)sshelp_ndir_total(k, trc);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reals the layout of an array uses (1 + nimag(nact, trc)) * size. Only for valid arrays, whose count
// was checked when the buffer was allocated.
static inline size_t dnob_used(const oarr_t* arr){

    return (size_t)dnob_nblocks(oarr_nact(arr), oarr_trc_order(arr)) * oarr_size(arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reals the buffer of an array holds at least, from its capacity (0 without an owned buffer).
static inline size_t dnob_capacity(const oarr_t* arr){

    if (!oarr_owns(arr)){
        return 0;
    }

    return (size_t)dnob_nblocks(arr->nbases, oarr_trc_order(arr)) * oarr_size(arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether an array is a matrix: blocks (nblocks, nrows, ncols). The matrix functions (products,
// transpose, linear algebra, CSR) reject any other rank with DN_ERR_SIZE; a Gauss array passes them a
// matrix view (oarr_view_matrix()).
static inline int dnob_is_matrix(const oarr_t* a){

    return a->blocks.ndim == 3;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether an array is a view (oarr_view_matrix()): it holds a buffer or meta it does not own. An
// oarr_init() array (nothing at all) is not a view.
static inline int dnob_is_view(const oarr_t* a){

    return !oarr_owns(a) && (a->meta != NULL || a->blocks.buf != NULL || a->blocks.data != NULL);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether the buffer and meta of `res` may be replaced by a call-local result (an aliased `_to`):
// not for a view, nor while another reference, an export or an OTI view shares them (contracts 7.2,
// 7.3: OTI_ERR_BUSY; never the case in 7a).
static inline int dnob_can_replace(const oarr_t* res){

    if (dnob_is_view(res)){
        return 0;
    }

    return !oarr_owns(res) || (nd_buffer_refs(res->blocks.buf) == 1
                               && nd_buffer_exports(res->blocks.buf) == 0 && !oti_meta_shared(res->meta));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Gives `res` a new buffer of max(n, 1) reals (contents unspecified) and a new dense meta over (nact,
// trc), without releasing what it held: for an array that owns nothing (oarr_init() or a view, whose
// buffer and meta are borrowed). Sets nbases = nact; blocks keeps its old layout until the caller sets
// one. On a failure `res` is unchanged.
static int dnob_new_owned(oarr_t* res, size_t n, bases_t nact, ord_t trc){

    int64_t len = (n > 0) ? (int64_t)n : 1;
    oti_meta_t* m = NULL;
    ndarr_t b;
    int status;

    nd_init_empty(&b);
    status = nd_alloc(NULL, OTI_F64, 1, &len, ND_LAYOUT_C, 0, &b);

    if (status != OTI_OK){
        return DN_ERR_MEMORY;
    }

    if (oti_meta_create(OTI_META_DENSE, trc, nact, NULL, 0, &m) != OTI_OK){

        nd_release(&b);
        return DN_ERR_MEMORY;

    }

    res->blocks.data  = b.data;
    res->blocks.dtype = OTI_F64;
    res->blocks.buf   = b.buf;
    res->blocks.flags = ND_WRITEABLE | ND_RETAINED;
    res->meta         = m;
    res->nbases       = nact;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Layout transaction of an owning array (contracts 7.2): the meta becomes (nact, trc) (act_order is
// clipped to trc) and, with grow > 0, the buffer is reallocated to exactly `grow` reals keeping its
// first `keep` reals. blocks keeps its old layout until the caller sets one. Returns DN_OK,
// OTI_ERR_BUSY (another reference or an export of the buffer, or OTI views of the meta) or
// DN_ERR_MEMORY; on a failure the array is unchanged.
static int dnob_relayout(oarr_t* arr, size_t grow, size_t keep, bases_t nact, ord_t trc){

    int status = oti_meta_layout_begin(arr->meta, arr->blocks.buf);

    if (status != OTI_OK){
        return status;
    }

    if (grow > 0){

        status = nd_grow_locked(NULL, &arr->blocks, (int64_t)(grow * sizeof(coeff_t)),
                                (int64_t)(keep * sizeof(coeff_t)));

    }

    if (status == OTI_OK){
        status = oti_meta_relayout(arr->meta, trc, nact, NULL);
    }

    oti_meta_layout_end(arr->meta, arr->blocks.buf);

    if (status == OTI_ERR_BUSY){
        return status;
    }

    return (status == OTI_OK) ? DN_OK : DN_ERR_MEMORY;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Shapes `res` as an array of element shape S over bases 1..nact at truncation order trc, with a
// buffer of at least that layout. The contents are unspecified (the caller writes every value) and
// act_order is left to the caller (clipped to trc). The buffer is kept when it is large enough;
// otherwise a new one replaces it. On a failure `res` is unchanged. Returns DN_OK, DN_ERR_INDEX (trc
// above _MAXORDER_OTI), DN_ERR_MEMORY or OTI_ERR_BUSY; *p_n gets the reals of the layout.
static int dnob_result_shape_s(oarr_t* res, bases_t nact, const dnob_shape_t* S, ord_t trc,
                               size_t* p_n){

    uint64_t size;
    size_t need, have;
    bases_t cap;
    dnob_shape_t Sr = *S;
    int status, view = dnob_is_view(res);

    if (trc > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    dnob_keep_shape(res, &Sr);

    // Same layout (the steady state of a `_to` loop), tested first: nothing moves, the layout already
    // passed the size checks and the budget, and the 1.x capacity rule (same size, trc <= old trc)
    // gives nbases = max(nbases, nact) = nbases. A view of that layout is written in place.
    if ((view || oarr_owns(res)) && oarr_nact(res) == nact && oarr_trc_order(res) == trc
        && dnob_shape_is(res, &Sr)){

        if (p_n != NULL){
            *p_n = dnob_used(res);
        }

        return DN_OK;

    }

    // Any other layout would relayout the viewed array (contracts 7.3): never redirect a view.
    if (view){
        return OTI_ERR_BUSY;
    }

    if (dnob_shape_size_s(S, &size) != DN_OK || dnob_nreals(nact, trc, size, &need) != DN_OK
        || dnob_layout_ok(dnob_nblocks(nact, trc), S) != DN_OK){
        return DN_ERR_MEMORY;
    }

    if (!oarr_owns(res)){

        status = dnob_new_owned(res, need, nact, trc);
        cap    = nact;

    } else {

        have = dnob_capacity(res);

        if (need > have){

            cap    = nact;
            status = dnob_relayout(res, need, 0, nact, trc);

        } else {

            // The capacity in bases stays valid at a lower truncation order and the same size; for
            // another shape it is only known to cover nact.
            if (size == oarr_size(res) && trc <= oarr_trc_order(res)){
                cap = (res->nbases > nact) ? res->nbases : nact;
            } else {
                cap = nact;
            }

            status = dnob_relayout(res, 0, 0, nact, trc);

        }

    }

    if (status != DN_OK){
        return status;
    }

    res->nbases = cap;
    dnob_set_layout(res, dnob_nblocks(nact, trc), &Sr);

    if (p_n != NULL){
        *p_n = need;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// dnob_result_shape_s() for the matrix shape (nrows, ncols).
static int dnob_result_shape(oarr_t* res, bases_t nact, uint64_t nrows, uint64_t ncols, ord_t trc,
                             size_t* p_n){

    dnob_shape_t S = dnob_shape2(nrows, ncols);

    return dnob_result_shape_s(res, nact, &S, trc, p_n);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Sets the layout (nact, trc) of an owning array whose buffer already holds it (after oarr_reserve()),
// keeping its element shape: a layout transaction without growth. nbases is unchanged.
static int dnob_set_nact_trc(oarr_t* arr, bases_t nact, ord_t trc){

    dnob_shape_t S = dnob_shape_of(arr);
    int status;

    if (oarr_nact(arr) == nact && oarr_trc_order(arr) == trc){
        return DN_OK;
    }

    if (dnob_is_view(arr)){
        return OTI_ERR_BUSY;
    }

    if (dnob_layout_ok(dnob_nblocks(nact, trc), &S) != DN_OK){
        return DN_ERR_MEMORY;
    }

    status = dnob_relayout(arr, 0, 0, nact, trc);

    if (status != DN_OK){
        return status;
    }

    dnob_set_layout(arr, dnob_nblocks(nact, trc), &S);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Moves an owning array into `res` (whose previous contents are released): the struct is moved and
// `src` reset, so no descriptor is held twice.
static void dnob_move(oarr_t* src, oarr_t* res){

    dnob_shape_t S;

    if (src == res){
        return;
    }

    // Callers check dnob_can_replace() before computing a call-local result (OTI_ERR_BUSY otherwise).
#ifdef OTI_ND_DEBUG
    assert(dnob_can_replace(res));
#endif

    S = dnob_shape_of(src);
    dnob_keep_shape(res, &S);

    oarr_free(res);
    *res = *src;
    *src = oarr_init();

    if (res->blocks.ndim != 1 + S.sdim){
        dnob_set_layout(res, (uint64_t)res->blocks.shape[0], &S);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
oarr_t oarr_init(void){

    oarr_t arr;

    dnob_empty_blocks(&arr.blocks, 2);
    arr.meta   = NULL;
    arr.nbases = 0;

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_zeros_to(bases_t nact, uint64_t nrows, uint64_t ncols, ord_t trc_order, oarr_t* res){

    size_t n;
    int status = dnob_result_shape(res, nact, nrows, ncols, trc_order, &n);

    if (status != DN_OK){
        return status;
    }

    if (n > 0){
        memset(oarr_data(res), 0, n * sizeof(coeff_t));
    }

    oarr_set_act_order(res, 0);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_from_real_to(const coeff_t* data, uint64_t nrows, uint64_t ncols, ord_t trc_order,
                      oarr_t* res){

    int status = oarr_zeros_to(0, nrows, ncols, trc_order, res);

    if (status != DN_OK){
        return status;
    }

    if (data != NULL && oarr_size(res) > 0){
        memcpy(oarr_data(res), data, (size_t)oarr_size(res) * sizeof(coeff_t));
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_eye_to(uint64_t n, ord_t trc_order, oarr_t* res){

    uint64_t i;
    coeff_t* d;
    int status = oarr_zeros_to(0, n, n, trc_order, res);

    if (status != DN_OK){
        return status;
    }

    d = oarr_data(res);

    for (i = 0; i < n; i++){
        d[i + i * n] = 1.0;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_reserve(oarr_t* arr, bases_t cap, uint64_t nrows, uint64_t ncols, ord_t trc_order){

    uint64_t size;
    bases_t nact = oarr_nact(arr);
    ord_t trc_old = oarr_trc_order(arr);
    ord_t trc = (trc_order > trc_old) ? trc_order : trc_old;
    bases_t new_cap = (cap > nact) ? cap : nact;
    size_t need, have = dnob_capacity(arr), n_old = 0;
    dnob_shape_t S = dnob_shape2(nrows, ncols);
    int same, status;

    dnob_keep_shape(arr, &S);

    if (trc > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    // A view is never regrown: only a request its layout already satisfies succeeds (no change).
    if (dnob_is_view(arr)){

        return (dnob_shape_is(arr, &S) && trc == trc_old && cap <= nact) ? DN_OK : OTI_ERR_BUSY;

    }

    if (dnob_shape_size_s(&S, &size) != DN_OK || dnob_nreals(new_cap, trc, size, &need) != DN_OK
        || dnob_layout_ok(dnob_nblocks(nact, trc), &S) != DN_OK){
        return DN_ERR_MEMORY;
    }

    same = (size == oarr_size(arr));

    // Capacity rule: keep the buffer when the required layout (new_cap, trc, size) fits it,
    // otherwise allocate exactly that layout; nbases becomes new_cap either way. The same size keeps
    // the values (the layout over nact is unchanged); another size leaves them undefined.
    if (!oarr_owns(arr)){

        status = dnob_new_owned(arr, need, nact, trc);

    } else {

        n_old  = dnob_used(arr);
        status = dnob_relayout(arr, (need > have) ? need : 0, same ? n_old : 0, nact, trc);

    }

    if (status != DN_OK){
        return status;
    }

    arr->nbases = new_cap;
    dnob_set_layout(arr, dnob_nblocks(nact, trc), &S);

    // Same size and a higher order: the new orders are appended after the old ones, zero.
    if (same && size > 0){

        size_t n_new = dnob_used(arr);

        if (n_new > n_old){
            memset(oarr_data(arr) + n_old, 0, (n_new - n_old) * sizeof(coeff_t));
        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarr_free(oarr_t* arr){

    int32_t sdim = (arr->blocks.ndim >= 3 && arr->blocks.ndim <= 1 + DNOB_MAX_SDIM)
                   ? arr->blocks.ndim - 1 : 2;

    if (oarr_owns(arr)){

        nd_release(&arr->blocks);
        oti_meta_release(&arr->meta);

    }

    // A view only resets: its buffer and meta are borrowed. The element rank is kept (a Gauss array
    // stays 4-D).
    dnob_empty_blocks(&arr->blocks, sdim);
    arr->meta   = NULL;
    arr->nbases = 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_copy_to(const oarr_t* arr, oarr_t* res){

    size_t n;
    dnob_shape_t S;
    int status;

    if (arr == res){
        return DN_OK;
    }

    S      = dnob_shape_of(arr);
    status = dnob_result_shape_s(res, oarr_nact(arr), &S, oarr_trc_order(arr), &n);

    if (status != DN_OK){
        return status;
    }

    if (n > 0){
        memcpy(oarr_data(res), oarr_data(arr), n * sizeof(coeff_t));
    }

    oarr_set_act_order(res, oarr_act_order(arr));

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarr_kernel_expand(const oarr_t* arr, bases_t ku, ord_t trc, coeff_t* dst){

    bases_t k = oarr_nact(arr);
    ord_t p, top = (oarr_act_order(arr) < trc) ? oarr_act_order(arr) : trc;
    uint64_t m = oarr_size(arr);
    const coeff_t* src = oarr_data(arr);
    ndir_t Ns, Nd;
    coeff_t* D;

    if (m == 0){
        return;
    }

    memcpy(dst, src, (size_t)m * sizeof(coeff_t));

    for (p = 1; p <= trc; p++){

        Nd = sshelp_ndir_order(ku, p);
        D  = dst + oarr_block_index(ku, p, 0) * m;
        Ns = (p > top || k == 0) ? 0 : sshelp_ndir_order(k, p);

        // Prefix property: the order-p blocks of the smaller layout are the first Ns of the larger.
        if (Ns > 0){
            memcpy(D, src + oarr_block_index(k, p, 0) * m, (size_t)Ns * m * sizeof(coeff_t));
        }

        memset(D + (size_t)Ns * m, 0, (size_t)(Nd - Ns) * m * sizeof(coeff_t));

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_add_bases(bases_t nact, oarr_t* arr){

    bases_t kold = oarr_nact(arr);
    ord_t trc = oarr_trc_order(arr);
    uint64_t m = oarr_size(arr);
    dnob_shape_t S = dnob_shape_of(arr);
    size_t need, have;
    coeff_t* d;
    ord_t p, top = (oarr_act_order(arr) < trc) ? oarr_act_order(arr) : trc;
    int status, expand = 0;

    if (nact <= kold){
        return DN_OK;
    }

    // A view is never relaid out (contracts 7.2, 7.3).
    if (dnob_is_view(arr)){
        return OTI_ERR_BUSY;
    }

    if (dnob_nreals(nact, trc, m, &need) != DN_OK || dnob_layout_ok(dnob_nblocks(nact, trc),
                                                                    &S) != DN_OK){
        return DN_ERR_MEMORY;
    }

    if (!oarr_owns(arr)){

        // Nothing to keep: an empty array (or a view, which is never a result) gets its own layout.
        status = dnob_new_owned(arr, need, nact, trc);

        if (status != DN_OK){
            return status;
        }

        if (need > 0){
            memset(oarr_data(arr), 0, need * sizeof(coeff_t));
        }

        oarr_set_act_order(arr, 0);
        dnob_set_layout(arr, dnob_nblocks(nact, trc), &S);

        return DN_OK;

    }

    have = dnob_capacity(arr);

    if (need == 0){

        status = dnob_relayout(arr, 0, 0, nact, trc);

        if (status != DN_OK){
            return status;
        }

        arr->nbases = (arr->nbases > nact) ? arr->nbases : nact;
        dnob_set_layout(arr, dnob_nblocks(nact, trc), &S);

        return DN_OK;

    }

    // One transaction: grow when the capacity is exceeded (keeping the old layout as a prefix), then
    // move the blocks in place.
    status = oti_meta_layout_begin(arr->meta, arr->blocks.buf);

    if (status != OTI_OK){
        return status;
    }

    if (nact > arr->nbases || need > have){

        status = nd_grow_locked(NULL, &arr->blocks, (int64_t)(need * sizeof(coeff_t)),
                                (int64_t)(dnob_used(arr) * sizeof(coeff_t)));

        if (status != OTI_OK){

            oti_meta_layout_end(arr->meta, arr->blocks.buf);
            return (status == OTI_ERR_BUSY) ? status : DN_ERR_MEMORY;

        }

        arr->nbases = nact;
        expand      = 1;

    }

    d = oarr_data(arr);

    // Highest order first: every order block moves up (its offset grows with k), so the source of a
    // lower order is never overwritten before it moves. After a growth the result is that of
    // oarr_kernel_expand(): orders above act_order are written as zeros, not moved.
    for (p = trc; p >= 1; p--){

        ndir_t off_old = sshelp_order_offset(kold, p), n_old = sshelp_ndir_order(kold, p);
        ndir_t off_new = sshelp_order_offset(nact, p), n_new = sshelp_ndir_order(nact, p);

        if (expand && p > top){
            n_old = 0;
        }

        if (n_old > 0){
            memmove(d + (1 + off_new) * m, d + (1 + off_old) * m, (size_t)n_old * m * sizeof(coeff_t));
        }

        memset(d + (1 + off_new + n_old) * m, 0, (size_t)(n_new - n_old) * m * sizeof(coeff_t));

    }

    status = oti_meta_relayout(arr->meta, trc, nact, NULL);
    oti_meta_layout_end(arr->meta, arr->blocks.buf);

    if (status != OTI_OK){
        return DN_ERR_MEMORY;
    }

    dnob_set_layout(arr, dnob_nblocks(nact, trc), &S);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Relabels a compact array as an nrows x ncols matrix of the same size (nrows * ncols == its size).
static void dnob_reshape2(oarr_t* arr, uint64_t nrows, uint64_t ncols){

    dnob_shape_t S = dnob_shape2(nrows, ncols);

    dnob_set_layout(arr, (uint64_t)arr->blocks.shape[0], &S);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether the blocks of an array have the compact layout dnob_set_layout() writes.
static int dnob_is_compact(const oarr_t* a){

    int64_t st = 1;
    int32_t d;

    for (d = 1; d < a->blocks.ndim; d++){

        if (a->blocks.strides[d] != st){
            return 0;
        }

        st *= a->blocks.shape[d];

    }

    return a->blocks.strides[0] == st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_view_matrix(const oarr_t* arr, uint64_t nrows, uint64_t ncols, oarr_t* view){

    uint64_t size;
    dnob_shape_t S = dnob_shape2(nrows, ncols);

    if (arr == NULL || view == NULL || (view == arr && oarr_owns(arr))){
        return DN_ERR_ARGUMENT;
    }

    if (dnob_shape_size_s(&S, &size) != DN_OK || size != oarr_size(arr) || !dnob_is_compact(arr)
        || dnob_layout_ok((uint64_t)arr->blocks.shape[0], &S) != DN_OK){
        return DN_ERR_SIZE;
    }

    // A temporary over the same data: no reference is taken on the buffer or the meta.
    view->blocks.data     = arr->blocks.data;
    view->blocks.dtype    = OTI_F64;
    view->blocks.reserved = 0;
    view->blocks.buf      = arr->blocks.buf;
    view->blocks.flags    = arr->blocks.flags & ND_WRITEABLE;
    view->meta            = arr->meta;
    view->nbases          = 0;

    dnob_set_layout(view, (uint64_t)arr->blocks.shape[0], &S);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
coeff_t* oarr_get_block(imdir_t idx, ord_t order, const oarr_t* arr){

    if (order == 0){
        return oarr_data(arr);
    }

    if (order > oarr_trc_order(arr) || idx >= sshelp_ndir_order(oarr_nact(arr), order)){
        return NULL;
    }

    return oarr_data(arr) + oarr_block_index(oarr_nact(arr), order, idx) * oarr_size(arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_get_item_to(uint64_t i, uint64_t j, const oarr_t* arr, otinum_t* res){

    uint64_t e, m = oarr_size(arr);
    ndir_t n, nimag;
    int status;

    if (i >= oarr_nrows(arr) || j >= oarr_ncols(arr)){
        return DN_ERR_INDEX;
    }

    e     = i + j * oarr_nrows(arr);
    nimag = sshelp_ndir_total(oarr_nact(arr), oarr_trc_order(arr));

    status = oti_reserve(res, oarr_nact(arr), oarr_trc_order(arr));

    if (status != DN_OK){
        return status;
    }

    // The scalar and block layouts match: coefficient n of the scalar is block 1 + n.
    res->re = oarr_data(arr)[e];

    for (n = 0; n < nimag; n++){
        res->p_im[n] = oarr_data(arr)[(1 + n) * m + e];
    }

    res->nact      = oarr_nact(arr);
    res->trc_order = oarr_trc_order(arr);
    res->act_order = oarr_act_order(arr);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Zeroes every coefficient of element e (the real part included).
static void dnob_clear_elem(uint64_t e, oarr_t* arr){

    size_t b, nblocks = 1 + sshelp_ndir_total(oarr_nact(arr), oarr_trc_order(arr));

    for (b = 0; b < nblocks; b++){
        oarr_data(arr)[b * oarr_size(arr) + e] = 0.0;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_set_item(const otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr){

    uint64_t e, m;
    ord_t p, top;
    int status;

    if (i >= oarr_nrows(arr) || j >= oarr_ncols(arr)){
        return DN_ERR_INDEX;
    }

    // Assignment rule: raise nact and the truncation order so that no coefficient of num is lost.
    status = oarr_add_bases(num->nact, arr);

    if (status == DN_OK && num->trc_order > oarr_trc_order(arr)){
        status = oarr_reserve(arr, oarr_nact(arr), oarr_nrows(arr), oarr_ncols(arr), num->trc_order);
    }

    if (status != DN_OK){
        return status;
    }

    m = oarr_size(arr);
    e = i + j * oarr_nrows(arr);

    dnob_clear_elem(e, arr);
    oarr_data(arr)[e] = num->re;

    top = (num->act_order < num->trc_order) ? num->act_order : num->trc_order;

    for (p = 1; p <= top && num->nact > 0; p++){

        ndir_t np = sshelp_ndir_order(num->nact, p), idx;
        const coeff_t* src = num->p_im + sshelp_order_offset(num->nact, p);
        coeff_t* dst = oarr_data(arr) + oarr_block_index(oarr_nact(arr), p, 0) * m + e;

        for (idx = 0; idx < np; idx++){
            dst[idx * m] = src[idx];
        }

    }

    if (top > oarr_act_order(arr)){
        oarr_set_act_order(arr, top);
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_set_item_r(coeff_t val, uint64_t i, uint64_t j, oarr_t* arr){

    uint64_t e;

    if (i >= oarr_nrows(arr) || j >= oarr_ncols(arr)){
        return DN_ERR_INDEX;
    }

    e = i + j * oarr_nrows(arr);

    dnob_clear_elem(e, arr);
    oarr_data(arr)[e] = val;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
double oarr_density(const oarr_t* arr){

    size_t nslots = dnob_used(arr) - oarr_size(arr), n, nnz = 0;

    if (nslots == 0){
        return 0.0;
    }

    for (n = 0; n < nslots; n++){

        if (oarr_data(arr)[oarr_size(arr) + n] != 0.0){
            nnz++;
        }

    }

    return (double)nnz / (double)nslots;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
size_t oarr_memory_size(const oarr_t* arr){

    return sizeof(oarr_t) + dnob_capacity(arr) * sizeof(coeff_t);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     CONVERSION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarr_from_arrso_to(const arrso_t* arr, oarr_t* res, dhelpl_t dhl){

    uint64_t i, j, m;
    bases_t nact = 0;
    ord_t trc = 0, act = 0, ordi;
    bases_t g[256];
    int status;

    (void)dhl;

    // First pass: the layout (largest base of a stored direction, largest truncation order).
    for (i = 0; i < arr->size; i++){

        const sotinum_t* el = &arr->p_data[i];

        if (el->trc_order > trc){
            trc = el->trc_order;
        }

        for (ordi = 0; ordi < el->trc_order; ordi++){

            ndir_t n;

            if (el->p_nnz[ordi] > 0 && ordi + 1 > act){
                act = (ord_t)(ordi + 1);
            }

            for (n = 0; n < el->p_nnz[ordi]; n++){

                if (sshelp_global_unrank(el->p_idx[ordi][n], (ord_t)(ordi + 1), g) != SSHELP_OK){
                    return DN_ERR_INDEX;
                }

                if (g[ordi] > nact){
                    nact = g[ordi];
                }

            }

        }

    }

    status = oarr_zeros_to(nact, arr->nrows, arr->ncols, trc, res);

    if (status != DN_OK){
        return status;
    }

    m = oarr_size(res);

    // arrso_t is row-major, (i, j) at p_data[j + i*ncols]; oarr_t blocks are column-major.
    for (i = 0; i < arr->nrows; i++){

        for (j = 0; j < arr->ncols; j++){

            const sotinum_t* el = &arr->p_data[j + i * arr->ncols];
            uint64_t e = i + j * arr->nrows;

            oarr_data(res)[e] = el->re;

            for (ordi = 0; ordi < el->trc_order; ordi++){

                coeff_t* blk = oarr_data(res) + oarr_block_index(nact, (ord_t)(ordi + 1), 0) * m + e;
                ndir_t n;

                for (n = 0; n < el->p_nnz[ordi]; n++){
                    blk[(size_t)el->p_idx[ordi][n] * m] += el->p_im[ordi][n];
                }

            }

        }

    }

    oarr_set_act_order(res, act);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
arrso_t oarr_to_arrso(const oarr_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_zeros_bases(oarr_nrows(arr), oarr_ncols(arr), 0, 0, dhl);
    bases_t k = oarr_nact(arr);
    ord_t trc = oarr_trc_order(arr);
    uint64_t i, j, m = oarr_size(arr);

    for (i = 0; i < oarr_nrows(arr); i++){

        for (j = 0; j < oarr_ncols(arr); j++){

            uint64_t e = i + j * oarr_nrows(arr);
            ndir_t p_nnz[_MAXORDER_OTI];
            ord_t ordi, act = 0;
            sotinum_t tmp;

            for (ordi = 0; ordi < trc; ordi++){

                const coeff_t* blk = oarr_data(arr) + oarr_block_index(k, (ord_t)(ordi + 1), 0) * m + e;
                ndir_t n, np = sshelp_ndir_order(k, (ord_t)(ordi + 1));

                p_nnz[ordi] = 0;

                for (n = 0; n < np; n++){

                    if (blk[n * m] != 0.0){
                        p_nnz[ordi]++;
                    }

                }

                if (p_nnz[ordi] > 0){
                    act = (ord_t)(ordi + 1);
                }

            }

            tmp = soti_createEmpty_predef(p_nnz, trc, dhl);
            tmp.re        = oarr_data(arr)[e];
            tmp.act_order = act;

            // Local and global numbering coincide, so each order comes out sorted by global index.
            for (ordi = 0; ordi < trc; ordi++){

                const coeff_t* blk = oarr_data(arr) + oarr_block_index(k, (ord_t)(ordi + 1), 0) * m + e;
                ndir_t n, np = sshelp_ndir_order(k, (ord_t)(ordi + 1)), pos = 0;

                for (n = 0; n < np && pos < p_nnz[ordi]; n++){

                    if (blk[n * m] != 0.0){

                        tmp.p_im[ordi][pos]  = blk[n * m];
                        tmp.p_idx[ordi][pos] = (imdir_t)n;
                        pos++;

                    }

                }

                tmp.p_nnz[ordi] = pos;

            }

            arrso_set_item_ij_o(&tmp, i, j, &res, dhl);
            soti_free(&tmp);

        }

    }

    return res;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Tells whether the sorted multiset `small` (length p) is contained in the sorted multiset `big`
// (length q).
static int dnob_submultiset(const bases_t* small, ord_t p, const bases_t* big, ord_t q){

    ord_t si = 0, bi = 0;

    while (si < p && bi < q){

        if (small[si] == big[bi]){

            si++;
            bi++;

        } else if (big[bi] < small[si]){

            bi++;

        } else {

            return 0;

        }

    }

    return si == p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_truncate_im_to(imdir_t idx, ord_t order, const oarr_t* arr, oarr_t* res){

    bases_t g[256], u[256];
    ord_t q, i;
    int status = oarr_copy_to(arr, res);

    if (status != DN_OK){
        return status;
    }

    if (order == 0 || order > oarr_trc_order(res) || idx >= sshelp_ndir_order(oarr_nact(res), order)){
        return DN_OK;
    }

    // Local bases of the direction (global base b is local base b - 1).
    sshelp_unrank(idx, order, g);

    // Every direction of order q >= order that contains it, visited in local index order.
    for (q = order; q <= oarr_trc_order(res); q++){

        ndir_t Nq = sshelp_ndir_order(oarr_nact(res), q), jj;
        coeff_t* b0 = oarr_data(res) + oarr_block_index(oarr_nact(res), q, 0) * oarr_size(res);

        for (i = 0; i < q; i++){
            u[i] = 0;
        }

        for (jj = 0; jj < Nq; jj++){

            if (dnob_submultiset(g, order, u, q)){
                memset(b0 + jj * oarr_size(res), 0, (size_t)oarr_size(res) * sizeof(coeff_t));
            }

            sshelp_next_dir(u, q, oarr_nact(res));

        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_truncate_order_to(ord_t order, const oarr_t* arr, oarr_t* res){

    size_t off, n;
    int status = oarr_copy_to(arr, res);

    if (status != DN_OK){
        return status;
    }

    // Order 0 removes everything, the real part included; nact and trc are kept.
    if (order == 0){

        n = dnob_used(res);

        if (n > 0){
            memset(oarr_data(res), 0, n * sizeof(coeff_t));
        }

        oarr_set_act_order(res, 0);

        return DN_OK;

    }

    if (order > oarr_trc_order(res)){
        return DN_OK;
    }

    off = (size_t)oarr_block_index(oarr_nact(res), order, 0) * oarr_size(res);
    n   = dnob_used(res);

    if (n > off){
        memset(oarr_data(res) + off, 0, (n - off) * sizeof(coeff_t));
    }

    if (oarr_act_order(res) > order - 1){
        oarr_set_act_order(res, (ord_t)(order - 1));
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_get_order_im_to(ord_t order, const oarr_t* arr, oarr_t* res){

    size_t n, lo, hi;
    int status = oarr_copy_to(arr, res);

    if (status != DN_OK){
        return status;
    }

    n = dnob_used(res);

    if (n == 0){
        return DN_OK;
    }

    // Blocks [lo, hi) are the kept order; everything else is zeroed.
    if (order > oarr_trc_order(res)){

        lo = hi = 0;

    } else {

        lo = (size_t)oarr_block_index(oarr_nact(res), order, 0) * oarr_size(res);
        hi = lo + (size_t)sshelp_ndir_order(oarr_nact(res), order) * oarr_size(res);

    }

    memset(oarr_data(res), 0, lo * sizeof(coeff_t));
    memset(oarr_data(res) + hi, 0, (n - hi) * sizeof(coeff_t));

    oarr_set_act_order(res, (order <= oarr_trc_order(res)) ? order : oarr_trc_order(res));

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether n reals starting at x are all zero.
static int dnob_all_zero(const coeff_t* x, size_t n){

    size_t e;

    for (e = 0; e < n; e++){

        if (x[e] != 0.0){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_compact_to(const oarr_t* arr, oarr_t* res){

    bases_t k = oarr_nact(arr), knew = 0;
    uint64_t m = oarr_size(arr);
    ord_t p, act = 0, trc = oarr_trc_order(arr);
    dnob_shape_t S = dnob_shape_of(arr);
    size_t n;
    int status;

    // Smallest nact that keeps every nonzero block: by the prefix property, the order-p directions
    // over bases 1..k' are the first N_p(k') of the order, so it is the smallest k' above the last
    // nonzero block of each order.
    for (p = 1; p <= oarr_trc_order(arr) && k > 0 && m > 0; p++){

        const coeff_t* b0 = oarr_data(arr) + oarr_block_index(k, p, 0) * m;
        ndir_t np = sshelp_ndir_order(k, p), last = np;

        while (last > 0 && dnob_all_zero(b0 + (last - 1) * m, (size_t)m)){
            last--;
        }

        if (last == 0){
            continue;
        }

        act = p;

        while (sshelp_ndir_order(knew, p) < last){
            knew++;
        }

    }

    if (res != arr){

        status = dnob_result_shape_s(res, knew, &S, trc, &n);

        if (status != DN_OK){
            return status;
        }

    } else if (!oarr_owns(res)){

        // oarr_init() has nothing to compact; a view can only keep its layout (contracts 7.3).
        if (dnob_is_view(res) && knew != k){
            return OTI_ERR_BUSY;
        }

        if (dnob_is_view(res)){
            oarr_set_act_order(res, act);
        }

        return DN_OK;

    } else {

        // In place: one layout transaction around the block moves (contracts 7.2).
        status = oti_meta_layout_begin(res->meta, res->blocks.buf);

        if (status != OTI_OK){
            return status;
        }

    }

    // The new layout is a prefix: moving order blocks down in increasing order never overwrites a
    // block not yet moved (offsets only shrink with k).
    if (m > 0){

        if (res != arr){
            memcpy(oarr_data(res), oarr_data(arr), (size_t)m * sizeof(coeff_t));
        }

        for (p = 1; p <= trc && knew > 0; p++){

            memmove(oarr_data(res) + oarr_block_index(knew, p, 0) * m,
                    oarr_data(arr) + oarr_block_index(k, p, 0) * m,
                    (size_t)sshelp_ndir_order(knew, p) * m * sizeof(coeff_t));

        }

    }

    if (res == arr){

        // The capacity (nbases) is kept: the array is compacted without shrinking.
        status = oti_meta_relayout(res->meta, trc, knew, NULL);
        oti_meta_layout_end(res->meta, res->blocks.buf);

        if (status != OTI_OK){
            return DN_ERR_MEMORY;
        }

        dnob_set_layout(res, dnob_nblocks(knew, trc), &S);

    }

    oarr_set_act_order(res, act);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------
