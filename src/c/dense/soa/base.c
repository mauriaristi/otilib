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
// oti_meta_layout_end(); it fails with OTI_ERR_BUSY while another reference (an OTI view) or an export
// is alive.
//
// Phase 7b: S has any rank 0 .. DNOB_MAX_SDIM; roots are compact in F (default) or C order; retained
// views (OARR_VIEW) share the buffer and the meta. The internal functions work on canonical operands
// (dnob_canon()); the public entry points normalize theirs with DNOB_IN*() (dnob_call_begin()).


/// Largest number of element axes (S): the block axis takes one of the OTI_ND_MAXDIM axes.
#define DNOB_MAX_SDIM (OTI_ND_MAXDIM - 1)

// *******************************************************************************************************
// Element shape S of an array: sdim extents and the order of the axes inside a block.
typedef struct {
    int32_t        sdim; ///< Number of element axes, 0 .. DNOB_MAX_SDIM.
    int32_t      layout; ///< ND_LAYOUT_F (canonical) or ND_LAYOUT_C, for dnob_set_layout().
    uint64_t ext[DNOB_MAX_SDIM]; ///< Extents.
} dnob_shape_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The matrix shape (nrows, ncols).
static inline dnob_shape_t dnob_shape2(uint64_t nrows, uint64_t ncols){

    dnob_shape_t s;

    s.sdim   = 2;
    s.layout = ND_LAYOUT_F;
    s.ext[0] = nrows;
    s.ext[1] = ncols;

    return s;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether the element axes of an array are compact in the given order (ND_LAYOUT_F or _C),
// ignoring axes of extent 1 (NumPy's contiguity rule). An array without elements is compact.
static int dnob_elems_compact(const oarr_t* a, int32_t layout){

    int64_t st = 1;
    int32_t e, d, sdim = a->blocks.ndim - 1;

    for (e = 0; e < sdim; e++){

        d = (layout == ND_LAYOUT_C) ? sdim - e : 1 + e;

        if (a->blocks.shape[d] == 0){
            return 1;
        }

        if (a->blocks.shape[d] != 1){

            if (a->blocks.strides[d] != st){
                return 0;
            }

            st *= a->blocks.shape[d];

        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether an array is canonical, the form every internal function reads: element axes compact
// in F order and block stride equal to the element count (one block, or no element, needs no block
// stride; an array without data is canonical). Element e of block b is then at data + b * size + e.
// The full test, from the descriptor; dnob_canon() reads OARR_CANON first.
static int dnob_canon_full(const oarr_t* a){

    int64_t m = 1;
    int32_t d;

    // No data, nothing to pack (oarr_init(), or a shell whose sizes the function rejects first).
    if (a->blocks.data == NULL){
        return 1;
    }

    for (d = 1; d < a->blocks.ndim; d++){
        m *= a->blocks.shape[d];
    }

    if (m == 0 || a->blocks.shape[0] <= 1){
        return dnob_elems_compact(a, ND_LAYOUT_F);
    }

    return dnob_elems_compact(a, ND_LAYOUT_F) && a->blocks.strides[0] == m;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// dnob_canon_full() with the OARR_CANON fast path (structures.h): a root laid out canonically by
// dnob_set_layout() answers with one load. Debug builds check the bit against the descriptor.
static inline int dnob_canon(const oarr_t* a){

    if (a->flags & OARR_CANON){

#ifdef OTI_ND_DEBUG
        assert(oarr_owns(a) && dnob_canon_full(a));
#endif

        return 1;

    }

    return dnob_canon_full(a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The element shape of an array (from its blocks descriptor): F order, or C for a C-compact root.
static inline dnob_shape_t dnob_shape_of(const oarr_t* a){

    dnob_shape_t s;
    int32_t d;

    s.sdim   = a->blocks.ndim - 1;
    s.layout = ND_LAYOUT_F;

    for (d = 0; d < s.sdim; d++){
        s.ext[d] = (uint64_t)a->blocks.shape[1 + d];
    }

    if (dnob_elems_compact(a, ND_LAYOUT_C) && !dnob_elems_compact(a, ND_LAYOUT_F)){
        s.layout = ND_LAYOUT_C;
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
// Writes the compact layout (nblocks, *S), S->layout order inside a block, over the array's current
// data. The caller has checked the sizes (dnob_nreals()) and the buffer holds nblocks * prod(S) reals.
static void dnob_set_layout(oarr_t* a, uint64_t nblocks, const dnob_shape_t* S){

    ndarr_t* b = &a->blocks;
    int64_t st = 1;
    int32_t d, e;

    b->ndim     = 1 + S->sdim;
    b->shape[0] = (int64_t)nblocks;

    for (e = 0; e < S->sdim; e++){

        d = (S->layout == ND_LAYOUT_C) ? S->sdim - 1 - e : e;
        b->shape[1 + d]   = (int64_t)S->ext[d];
        b->strides[1 + d] = st;
        st *= (int64_t)S->ext[d];

    }

    b->strides[0] = st;
    nd_update_flags(b);

    // OARR_CANON: set for a root laid out canonically (F order, or a C order that is also F compact:
    // at most one axis of extent > 1), cleared otherwise; the block stride is the element count here.
    a->flags &= ~OARR_CANON;

    if (oarr_owns(a) && (S->layout != ND_LAYOUT_C || dnob_elems_compact(a, ND_LAYOUT_F))){
        a->flags |= OARR_CANON;
    }

#ifdef OTI_ND_DEBUG
    if (b->buf != NULL){

        const char* lo = (const char*)nd_buffer_base(b->buf);

        assert(nd_validate(b, lo, lo + nd_buffer_nbytes(b->buf), ND_V_SPAN) == OTI_OK);

    }
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A Gauss array (OARR_GAUSS, S = (nip, nrows, ncols)) keeps its element shape through any result,
// reserve or move that gives it the same matricized shape nip x (nrows * ncols): replaces a matrix
// shape S by the array's own in that case. The label is metadata only (the memory layout is the same).
// The kind is explicit (critic W3 finding 3): an n-D omat of the same rank is never relabelled.
static inline void dnob_keep_shape(const oarr_t* res, dnob_shape_t* S){

    if (S->sdim == 2 && oarr_owns(res) && (res->flags & OARR_GAUSS) && res->blocks.ndim == 4
        && S->ext[0] == oarr_nrows(res) && S->ext[1] == oarr_ncols(res)){
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

    return (size_t)dnob_nblocks(arr->cap, oarr_trc_order(arr)) * oarr_size(arr);

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
// Tells whether an array is a view: a retained one (OARR_VIEW) or a temporary (oarr_view_matrix(),
// which holds a buffer or meta it does not own). An oarr_init() array (nothing at all) is not a view.
static inline int dnob_is_view(const oarr_t* a){

    return (a->flags & OARR_VIEW)
           || (!(a->blocks.flags & ND_RETAINED)
               && (a->meta != NULL || a->blocks.buf != NULL || a->blocks.data != NULL));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether nobody else holds the buffer and the meta of a root: one reference on each. The buffer's
// count includes its exports (each export holds a reference, buffer.h), so it also says "no export";
// the meta's count is read inline (the acquire load of oti_meta_shared(), meta.c), one call less.
static inline int dnob_sole(const oarr_t* res){

    return nd_buffer_refs(res->blocks.buf) == 1
           && __atomic_load_n(&res->meta->refs, __ATOMIC_ACQUIRE) == 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether the buffer and meta of `res` may be replaced by a call-local result (an aliased `_to`):
// not for a view, nor while another reference, an export or an OTI view shares them (contracts 7.2,
// 7.3: such a `res` receives its result through oarr_assign_to(), see dnob_call_begin()).
static inline int dnob_can_replace(const oarr_t* res){

    if (dnob_is_view(res)){
        return 0;
    }

    return !oarr_owns(res) || dnob_sole(res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Gives `res` a new buffer of max(n, 1) reals (contents unspecified) and a new dense meta over (nact,
// trc), without releasing what it held: for an array that owns nothing (oarr_init() or a view, whose
// buffer and meta are borrowed). Sets cap = nact; blocks keeps its old layout until the caller sets
// one. On a failure `res` is unchanged.
static int dnob_new_owned_f(oarr_t* res, size_t n, bases_t nact, ord_t trc, int32_t alloc_flags){

    int64_t len = (n > 0) ? (int64_t)n : 1;
    void* zone = NULL;
    oti_meta_t* m;
    ndarr_t b;
    int status;

    // One allocation for a small array (control block, the meta in its extra zone, and the data up to
    // 4 KiB: nd_alloc_extra()); the meta lives as long as the buffer (oti_meta_init()).
    nd_init_empty(&b);
    status = nd_alloc_extra(NULL, OTI_F64, 1, &len, NULL, ND_LAYOUT_C, alloc_flags,
                            (int64_t)sizeof(oti_meta_t), &zone, &b);

    if (status != OTI_OK){
        return DN_ERR_MEMORY;
    }

    m = (oti_meta_t*)zone;

    if (oti_meta_init(m, OTI_META_DENSE, trc, nact, NULL, 0) != OTI_OK){

        nd_release(&b);
        return DN_ERR_MEMORY;

    }

    res->blocks.data  = b.data;
    res->blocks.dtype = OTI_F64;
    res->blocks.buf   = b.buf;
    res->blocks.flags = ND_WRITEABLE | ND_RETAINED;
    res->meta         = m;
    res->cap          = nact;
    res->flags       &= OARR_GAUSS;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// dnob_new_owned_f() on the heap.
static int dnob_new_owned(oarr_t* res, size_t n, bases_t nact, ord_t trc){

    return dnob_new_owned_f(res, n, nact, trc, 0);

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
    // gives cap = max(cap, nact) = cap. A view of that layout is written in place.
    if ((view || oarr_owns(res)) && oarr_nact(res) == nact && oarr_trc_order(res) == trc
        && dnob_shape_is(res, &Sr) && (Sr.layout == ND_LAYOUT_C ? dnob_elems_compact(res, ND_LAYOUT_C)
                                       && (int64_t)dnob_used(res) == res->blocks.strides[0]
                                       * res->blocks.shape[0] : dnob_canon(res))){

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
                cap = (res->cap > nact) ? res->cap : nact;
            } else {
                cap = nact;
            }

            status = dnob_relayout(res, 0, 0, nact, trc);

        }

    }

    if (status != DN_OK){
        return status;
    }

    res->cap = cap;
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
// keeping its element shape: a layout transaction without growth. cap is unchanged.
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
    int gauss;

    if (src == res){
        return;
    }

    // Callers check dnob_can_replace() before computing a call-local result (OTI_ERR_BUSY otherwise).
#ifdef OTI_ND_DEBUG
    assert(dnob_can_replace(res));
#endif

    S = dnob_shape_of(src);
    dnob_keep_shape(res, &S);
    gauss = (res->flags & OARR_GAUSS) && S.sdim == 3;

    oarr_free(res);
    *res = *src;
    *src = oarr_init();

    if (res->blocks.ndim != 1 + S.sdim){
        dnob_set_layout(res, (uint64_t)res->blocks.shape[0], &S);
    }

    res->flags = (res->flags & ~OARR_GAUSS) | (gauss ? OARR_GAUSS : 0);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ----------------------------------     CANONICAL OPERANDS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------
// The internal functions read canonical operands (dnob_canon(): S compact in F order, block stride ==
// element count) and write their result into a `res` they may relayout. A public entry point starts with
// DNOB_IN1 / DNOB_IN2 / DNOB_IN2B / DNOB_IN3: when an input is not canonical (a view, a C-order root, or
// for DNOB_IN2B an operand of another shape that broadcasts) it is packed into a call-local canonical
// copy, and a `res` that is a view or a shared root receives the result through oarr_assign_to()
// (contracts 7.3: it fits the shared layout or the call fails with OTI_ERR_BUSY; nothing is clipped).
// The entry point then calls itself once more on those operands, which are canonical and direct.

/// Largest number of array operands of one public entry point.
#define DNOB_MAX_IN 3

// *******************************************************************************************************
// Operands of a public entry point (DNOB_IN*()).
typedef struct {
    const oarr_t*  in[DNOB_MAX_IN]; ///< Canonical inputs: the caller's arrays or packed copies.
    oarr_t        tmp[DNOB_MAX_IN]; ///< Packed copies (oarr_init() when unused).
    oarr_t*                    res; ///< Where the result is written: the caller's res, or &out.
    oarr_t                     out; ///< Call-local result of a view or shared `res`.
    int                   redirect; ///< Nonzero when `out` is stored into res by oarr_assign_to().
} dnob_call_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether `res` takes a result directly: NULL (no array result), an empty array, or a root whose
// buffer and meta nobody else holds. A view or a shared root receives it through oarr_assign_to().
static inline int dnob_res_direct(const oarr_t* res){

    if (res == NULL){
        return 1;
    }

    // A canonical root (OARR_CANON) is a root: only its sharing is left to read.
    if (res->flags & OARR_CANON){

#ifdef OTI_ND_DEBUG
        assert(oarr_owns(res) && !dnob_is_view(res));
#endif

        return dnob_sole(res);

    }

    return !dnob_is_view(res) && (!oarr_owns(res) || dnob_can_replace(res));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether an input needs no packing (NULL is left to the function's own checks).
static inline int dnob_in_ok(const oarr_t* x){

    return x == NULL || dnob_canon(x);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether two arrays have the same element shape S.
static int dnob_same_shape(const oarr_t* a, const oarr_t* b){

    int32_t d;

    if (a->blocks.ndim != b->blocks.ndim){
        return 0;
    }

    for (d = 1; d < a->blocks.ndim; d++){

        if (a->blocks.shape[d] != b->blocks.shape[d]){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The broadcast (NumPy rules) of the element shapes of n arrays (NULL entries skipped) into *S, F order;
// DN_ERR_SIZE when they do not broadcast.
static int dnob_bcast_shape(int32_t n, const oarr_t* const* x, dnob_shape_t* S){

    int32_t i, d, e, sdim = 0;

    for (i = 0; i < n; i++){

        if (x[i] != NULL && oarr_ndim(x[i]) > sdim){
            sdim = oarr_ndim(x[i]);
        }

    }

    S->sdim   = sdim;
    S->layout = ND_LAYOUT_F;

    for (d = 0; d < sdim; d++){
        S->ext[d] = 1;
    }

    for (i = 0; i < n; i++){

        if (x[i] == NULL){
            continue;
        }

        for (e = 0; e < oarr_ndim(x[i]); e++){

            uint64_t ext = (uint64_t)oarr_shape(x[i], e);

            d = sdim - oarr_ndim(x[i]) + e;

            if (ext == S->ext[d] || ext == 1){
                continue;
            }

            if (S->ext[d] != 1){
                return DN_ERR_SIZE;
            }

            S->ext[d] = ext;

        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Temporary read-only descriptor of the blocks [b0, b0 + nb) of `a` with its element axes broadcast to
// S (NumPy alignment: trailing axes matched; leading axes of `a` beyond S must have extent 1 and are
// dropped, the value rule S1; a stretched axis gets stride 0). DN_ERR_SIZE when `a` does not
// broadcast to S.
static int dnob_bcast_blocks(const oarr_t* a, uint64_t b0, uint64_t nb, const dnob_shape_t* S,
                             ndarr_t* out){

    int32_t sa = oarr_ndim(a), skip = (sa > S->sdim) ? sa - S->sdim : 0, d, e;

    nd_init_empty(out);

    for (e = 0; e < skip; e++){

        if (oarr_shape(a, e) != 1){
            return DN_ERR_SIZE;
        }

    }

    out->dtype      = OTI_F64;
    out->buf        = a->blocks.buf;
    out->ndim       = 1 + S->sdim;
    out->shape[0]   = (int64_t)nb;
    out->strides[0] = a->blocks.strides[0];
    out->data       = (a->blocks.data == NULL) ? NULL
                      : (void*)((coeff_t*)a->blocks.data + (int64_t)b0 * a->blocks.strides[0]);

    for (d = 0; d < S->sdim; d++){

        e = d - (S->sdim - sa);
        out->shape[1 + d] = (int64_t)S->ext[d];

        if (e < 0){
            out->strides[1 + d] = 0;
        } else if (oarr_shape(a, e) == (int64_t)S->ext[d]){
            out->strides[1 + d] = a->blocks.strides[1 + e];
        } else if (oarr_shape(a, e) == 1){
            out->strides[1 + d] = 0;
        } else {
            return DN_ERR_SIZE;
        }

    }

    out->flags = 0;
    nd_update_flags(out);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Temporary writable descriptor of the blocks [b0, b0 + nb) of `a`, its own element axes.
static void dnob_block_range(const oarr_t* a, uint64_t b0, uint64_t nb, ndarr_t* out){

    *out          = a->blocks;
    out->flags   &= ~(ND_RETAINED | ND_EXPORTED);
    out->shape[0] = (int64_t)nb;

    if (out->data != NULL){
        out->data = (void*)((coeff_t*)out->data + (int64_t)b0 * a->blocks.strides[0]);
    }

    nd_update_flags(out);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Packs `a` into `res` (empty on entry): a new compact root of element shape S (a's shape, or one it
// broadcasts to) in the order S->layout, over a's layout (nact, trc, act). On a failure `res` is empty.
static int dnob_pack(const oarr_t* a, const dnob_shape_t* S, oarr_t* res){

    ndarr_t src;
    int status = dnob_result_shape_s(res, oarr_nact(a), S, oarr_trc_order(a), NULL);

    if (status != DN_OK){

        oarr_free(res);
        return status;

    }

    oarr_set_act_order(res, (oarr_act_order(a) < oarr_trc_order(a)) ? oarr_act_order(a)
                                                                     : oarr_trc_order(a));

    if (oarr_size(res) == 0){
        return DN_OK;
    }

    status = dnob_bcast_blocks(a, 0, (uint64_t)res->blocks.shape[0], S, &src);

    if (status == DN_OK){
        status = nd_assign(NULL, &src, &res->blocks);
    }

    if (status != DN_OK){

        oarr_free(res);
        return (status == OTI_ERR_MEMORY) ? DN_ERR_MEMORY : status;

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Releases the call-local arrays of an entry point.
static void dnob_call_free(dnob_call_t* c){

    int32_t i;

    for (i = 0; i < DNOB_MAX_IN; i++){
        oarr_free(&c->tmp[i]);
    }

    oarr_free(&c->out);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Prepares the operands of an entry point: packs every input that is not canonical (with bcast, every
// input whose shape is not the broadcast shape) and redirects a `res` that is not direct to a call-local
// result. On a failure nothing is held.
static int dnob_call_begin(dnob_call_t* c, int32_t n, const oarr_t* const* x, oarr_t* res, int bcast){

    dnob_shape_t S, Si;
    int32_t i;
    int status;

    c->res      = res;
    c->redirect = 0;
    c->out      = oarr_init();

    for (i = 0; i < DNOB_MAX_IN; i++){

        c->in[i]  = (i < n) ? x[i] : NULL;
        c->tmp[i] = oarr_init();

    }

    if (bcast && dnob_bcast_shape(n, x, &S) != DN_OK){
        return DN_ERR_SIZE;
    }

    for (i = 0; i < n; i++){

        if (x[i] == NULL || (dnob_canon(x[i]) && (!bcast || dnob_shape_is(x[i], &S)))){
            continue;
        }

        Si        = bcast ? S : dnob_shape_of(x[i]);
        Si.layout = ND_LAYOUT_F;
        status    = dnob_pack(x[i], &Si, &c->tmp[i]);

        if (status != DN_OK){

            dnob_call_free(c);
            return status;

        }

        c->in[i] = &c->tmp[i];

    }

    if (!dnob_res_direct(res)){

        c->redirect = 1;
        c->res      = &c->out;

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Finishes an entry point: stores a redirected result into `res` (exact shape, contracts 3.4; the
// layout must fit, 7.3) and releases the call-local arrays. Returns the final status.
static int dnob_call_end(dnob_call_t* c, int status, oarr_t* res){

    if (status == DN_OK && c->redirect){
        status = dnob_same_shape(&c->out, res) ? oarr_assign_to(&c->out, res) : DN_ERR_SIZE;
    }

    dnob_call_free(c);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Entry of a public function with array input X and array result RES (NULL for none): unless X is
// canonical and RES direct, return the value of CALL, the same function called with c_.in[0] and c_.res
// in place of X and RES (see the section comment).
#define DNOB_IN1(X, RES, CALL) do {                                                                  \
        if (!dnob_in_ok(X) || !dnob_res_direct(RES)){                                              \
            const oarr_t* x_[1];                                                                    \
            dnob_call_t c_;                                                                         \
            int s_;                                                                                 \
            x_[0] = (X);                                                                            \
            s_    = dnob_call_begin(&c_, 1, x_, (RES), 0);                                          \
            return (s_ == DN_OK) ? dnob_call_end(&c_, (CALL), (RES)) : s_;                          \
        }                                                                                           \
    } while (0)

// The same with two array inputs (c_.in[0], c_.in[1]); shapes are left to the function.
#define DNOB_IN2(X1, X2, RES, CALL) do {                                                             \
        if (!dnob_in_ok(X1) || !dnob_in_ok(X2) || !dnob_res_direct(RES)){                          \
            const oarr_t* x_[2];                                                                    \
            dnob_call_t c_;                                                                         \
            int s_;                                                                                 \
            x_[0] = (X1);                                                                           \
            x_[1] = (X2);                                                                           \
            s_    = dnob_call_begin(&c_, 2, x_, (RES), 0);                                          \
            return (s_ == DN_OK) ? dnob_call_end(&c_, (CALL), (RES)) : s_;                          \
        }                                                                                           \
    } while (0)

// Two elementwise operands: also broadcast them to their common shape (NumPy rules).
#define DNOB_IN2B(X1, X2, RES, CALL) do {                                                            \
        if (!dnob_in_ok(X1) || !dnob_in_ok(X2) || !dnob_res_direct(RES)                            \
            || ((X1) != NULL && (X2) != NULL && !dnob_same_shape((X1), (X2)))){                     \
            const oarr_t* x_[2];                                                                    \
            dnob_call_t c_;                                                                         \
            int s_;                                                                                 \
            x_[0] = (X1);                                                                           \
            x_[1] = (X2);                                                                           \
            s_    = dnob_call_begin(&c_, 2, x_, (RES), 1);                                          \
            return (s_ == DN_OK) ? dnob_call_end(&c_, (CALL), (RES)) : s_;                          \
        }                                                                                           \
    } while (0)

// Three array inputs (c_.in[0 .. 2]); shapes are left to the function.
#define DNOB_IN3(X1, X2, X3, RES, CALL) do {                                                         \
        if (!dnob_in_ok(X1) || !dnob_in_ok(X2) || !dnob_in_ok(X3) || !dnob_res_direct(RES)){       \
            const oarr_t* x_[3];                                                                    \
            dnob_call_t c_;                                                                         \
            int s_;                                                                                 \
            x_[0] = (X1);                                                                           \
            x_[1] = (X2);                                                                           \
            x_[2] = (X3);                                                                           \
            s_    = dnob_call_begin(&c_, 3, x_, (RES), 0);                                          \
            return (s_ == DN_OK) ? dnob_call_end(&c_, (CALL), (RES)) : s_;                          \
        }                                                                                           \
    } while (0)
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Prepares an in-place function (one that reads and rewrites `arr`) on a view or a shared root: `arr`
// is packed into the call-local root `out`, the function runs on it (it may grow it), and
// dnob_call_end() stores it back into `arr` (it must fit, contracts 7.3).
static int dnob_call_inplace(dnob_call_t* c, oarr_t* arr){

    dnob_shape_t S = dnob_shape_of(arr);
    int32_t i;

    for (i = 0; i < DNOB_MAX_IN; i++){

        c->in[i]  = NULL;
        c->tmp[i] = oarr_init();

    }

    c->out      = oarr_init();
    c->res      = &c->out;
    c->redirect = 1;
    S.layout    = ND_LAYOUT_F;

    return dnob_pack(arr, &S, &c->out);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Entry of an in-place function on ARR: unless ARR is canonical and direct, return the value of CALL run
// on c_.res, a canonical copy of ARR that is stored back afterwards.
#define DNOB_INPLACE(ARR, CALL) do {                                                                 \
        if (!dnob_canon(ARR) || !dnob_res_direct(ARR)){                                            \
            dnob_call_t c_;                                                                         \
            int s_ = dnob_call_inplace(&c_, (ARR));                                                 \
            return (s_ == DN_OK) ? dnob_call_end(&c_, (CALL), (ARR)) : s_;                          \
        }                                                                                           \
    } while (0)
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Element e (flat F order) of a canonical array as a full index.
static void dnob_unflat(const oarr_t* a, uint64_t e, int64_t* index){

    int32_t d;

    for (d = 0; d < oarr_ndim(a); d++){

        index[d] = (int64_t)(e % (uint64_t)oarr_shape(a, d));
        e       /= (uint64_t)oarr_shape(a, d);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Stores a new root `local` into `res`: moved when `res` is direct, else assigned (exact shape, the
// layout must fit). `local` is empty afterwards.
static int dnob_store(oarr_t* local, oarr_t* res){

    int status;

    if (dnob_res_direct(res)){

        dnob_move(local, res);
        return DN_OK;

    }

    status = dnob_same_shape(local, res) ? oarr_assign_to(local, res) : DN_ERR_SIZE;
    oarr_free(local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
oarr_t oarr_init(void){

    oarr_t arr;

    dnob_empty_blocks(&arr.blocks, 2);
    arr.meta  = NULL;
    arr.cap   = 0;
    arr.flags = 0;

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_zeros_to(bases_t nact, uint64_t nrows, uint64_t ncols, ord_t trc_order, oarr_t* res){

    size_t n;
    int status;

    DNOB_IN1(NULL, res, oarr_zeros_to(nact, nrows, ncols, trc_order, c_.res));

    status = dnob_result_shape(res, nact, nrows, ncols, trc_order, &n);

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

    int status;

    DNOB_IN1(NULL, res, oarr_from_real_to(data, nrows, ncols, trc_order, c_.res));

    status = oarr_zeros_to(0, nrows, ncols, trc_order, res);

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
    int status;

    DNOB_IN1(NULL, res, oarr_eye_to(n, trc_order, c_.res));

    status = oarr_zeros_to(0, n, n, trc_order, res);

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
    // otherwise allocate exactly that layout; cap becomes new_cap either way. The same size keeps
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

    arr->cap = new_cap;
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

    int32_t sdim = (arr->flags & OARR_GAUSS) ? 3 : 2;

    // A root or a retained view releases its references; a temporary view only resets (its buffer and
    // meta are borrowed). A Gauss array stays 4-D (and Gauss); anything else becomes 0 x 0.
    // The meta first: an embedded meta lives in the buffer's extra zone (dnob_new_owned_f()).
    if (arr->blocks.flags & ND_RETAINED){

        oti_meta_release(&arr->meta);
        nd_release(&arr->blocks);

    }

    dnob_empty_blocks(&arr->blocks, sdim);
    arr->meta  = NULL;
    arr->cap   = 0;
    arr->flags = arr->flags & OARR_GAUSS;

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

    DNOB_IN1(arr, res, oarr_copy_to(c_.in[0], c_.res));

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
    ord_t trc, p, top;
    uint64_t m;
    dnob_shape_t S;
    size_t need, have;
    coeff_t* d;
    int status, expand = 0;

    // The common case (the bases are there already) returns before any shape work.
    if (nact <= kold){
        return DN_OK;
    }

    trc = oarr_trc_order(arr);
    m = oarr_size(arr);
    S = dnob_shape_of(arr);
    top = (oarr_act_order(arr) < trc) ? oarr_act_order(arr) : trc;

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

        arr->cap = (arr->cap > nact) ? arr->cap : nact;
        dnob_set_layout(arr, dnob_nblocks(nact, trc), &S);

        return DN_OK;

    }

    // One transaction: grow when the capacity is exceeded (keeping the old layout as a prefix), then
    // move the blocks in place.
    status = oti_meta_layout_begin(arr->meta, arr->blocks.buf);

    if (status != OTI_OK){
        return status;
    }

    if (nact > arr->cap || need > have){

        status = nd_grow_locked(NULL, &arr->blocks, (int64_t)(need * sizeof(coeff_t)),
                                (int64_t)(dnob_used(arr) * sizeof(coeff_t)));

        if (status != OTI_OK){

            oti_meta_layout_end(arr->meta, arr->blocks.buf);
            return (status == OTI_ERR_BUSY) ? status : DN_ERR_MEMORY;

        }

        arr->cap = nact;
        expand   = 1;

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
int oarr_view_matrix(const oarr_t* arr, uint64_t nrows, uint64_t ncols, oarr_t* view){

    uint64_t size;
    dnob_shape_t S = dnob_shape2(nrows, ncols);

    if (arr == NULL || view == NULL || (view == arr && oarr_owns(arr))){
        return DN_ERR_ARGUMENT;
    }

    if (dnob_shape_size_s(&S, &size) != DN_OK || size != oarr_size(arr) || !dnob_canon(arr)
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
    view->cap             = 0;
    view->flags           = 0;

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

    return oarr_data(arr) + (int64_t)oarr_block_index(oarr_nact(arr), order, idx) * oarr_bstride(arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The element (i, j) of the matricized shape nrows x ncols as a full index of the array: (i, j) for a
// matrix, (i) for a vector (j == 0), () for a 0-D array (i == j == 0), and for a Gauss array the
// element i + j * nip of its F-order (nip, nrows, ncols). DN_ERR_SIZE for any other rank, DN_ERR_INDEX
// out of range.
static int dnob_index2(const oarr_t* arr, uint64_t i, uint64_t j, int64_t* index, int32_t* n){

    if (i >= oarr_nrows(arr) || j >= oarr_ncols(arr)){
        return (oarr_ndim(arr) <= 2 || (arr->flags & OARR_GAUSS)) ? DN_ERR_INDEX : DN_ERR_SIZE;
    }

    if (arr->flags & OARR_GAUSS){

        *n = oarr_ndim(arr);
        dnob_unflat(arr, i + j * oarr_nrows(arr), index);

        return DN_OK;

    }

    if (oarr_ndim(arr) > 2){
        return DN_ERR_SIZE;
    }

    *n       = oarr_ndim(arr);
    index[0] = (int64_t)i;
    index[1] = (int64_t)j;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// dnob_index2() as the integer key of oarr_index_set_o().
static int dnob_key2(const oarr_t* arr, uint64_t i, uint64_t j, nd_index_t* key, int32_t* n){

    int64_t index[OTI_ND_MAXDIM];
    int32_t d;
    int status = dnob_index2(arr, i, j, index, n);

    for (d = 0; d < *n && status == DN_OK; d++){

        key[d].kind  = ND_IDX_INT;
        key[d].has   = 0;
        key[d].start = index[d];
        key[d].stop  = 0;
        key[d].step  = 0;
        key[d].arr   = NULL;

    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_get_item_to(uint64_t i, uint64_t j, const oarr_t* arr, otinum_t* res){

    int64_t index[OTI_ND_MAXDIM];
    int32_t n;
    int status = dnob_index2(arr, i, j, index, &n);

    return (status != DN_OK) ? status : oarr_get_elem_to(arr, n, index, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_set_item(const otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr){

    nd_index_t key[OTI_ND_MAXDIM];
    int32_t n;
    int status = dnob_key2(arr, i, j, key, &n);

    // Assignment rule: a root raises nact and the truncation order so that no coefficient of num is
    // lost (a view or a shared root must already hold them: OTI_ERR_BUSY).
    return (status != DN_OK) ? status : oarr_index_set_o(arr, n, key, num);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_set_item_r(coeff_t val, uint64_t i, uint64_t j, oarr_t* arr){

    nd_index_t key[OTI_ND_MAXDIM];
    int32_t n;
    int status = dnob_key2(arr, i, j, key, &n);

    return (status != DN_OK) ? status : oarr_index_set_r(arr, n, key, val);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
double oarr_density(const oarr_t* arr){

    size_t nslots, n, nnz = 0;

    if (!dnob_canon(arr)){

        oarr_t t = oarr_init();
        dnob_shape_t S = dnob_shape_of(arr);
        double d = 0.0;

        S.layout = ND_LAYOUT_F;

        if (dnob_pack(arr, &S, &t) == DN_OK){
            d = oarr_density(&t);
        }

        oarr_free(&t);

        return d;

    }

    nslots = dnob_used(arr) - oarr_size(arr);

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

    DNOB_IN1(NULL, res, oarr_from_arrso_to(arr, c_.res, dhl));

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

    if (!dnob_canon(arr)){

        oarr_t t = oarr_init();
        dnob_shape_t S = dnob_shape_of(arr);
        arrso_t r;

        S.layout = ND_LAYOUT_F;

        if (dnob_pack(arr, &S, &t) != DN_OK){
            return arrso_init();
        }

        r = oarr_to_arrso(&t, dhl);
        oarr_free(&t);

        return r;

    }


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
    int status;

    DNOB_IN1(arr, res, oarr_truncate_im_to(idx, order, c_.in[0], c_.res));

    status = oarr_copy_to(arr, res);

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
    int status;

    DNOB_IN1(arr, res, oarr_truncate_order_to(order, c_.in[0], c_.res));

    status = oarr_copy_to(arr, res);

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
    int status;

    DNOB_IN1(arr, res, oarr_get_order_im_to(order, c_.in[0], c_.res));

    status = oarr_copy_to(arr, res);

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

    DNOB_IN1(arr, res, oarr_compact_to(c_.in[0], c_.res));

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

        // The capacity (cap) is kept: the array is compacted without shrinking.
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


// -------------------------------------------------------------------------------------------------------
// ------------------------------------     N-D ARRAYS (7b)     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

/// Largest number of items of an index key (newaxis items included).
#define DNOB_MAX_KEY 64

// *******************************************************************************************************
int oarr_zeros_nd_to(bases_t nact, int32_t ndim, const int64_t* shape, int32_t layout, ord_t trc_order,
                     oarr_t* res){

    dnob_shape_t S;
    size_t n;
    int32_t d;
    int status;

    if (res == NULL || ndim < 0 || (ndim > 0 && shape == NULL)
        || (layout != ND_LAYOUT_F && layout != ND_LAYOUT_C)){
        return DN_ERR_ARGUMENT;
    }

    if (ndim > DNOB_MAX_SDIM){
        return DN_ERR_SIZE;
    }

    S.sdim   = ndim;
    S.layout = layout;

    for (d = 0; d < ndim; d++){

        if (shape[d] < 0){
            return DN_ERR_SIZE;
        }

        S.ext[d] = (uint64_t)shape[d];

    }

    status = dnob_result_shape_s(res, nact, &S, trc_order, &n);

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
int oarr_from_real_nd_to(const ndarr_t* data, ord_t trc_order, int32_t layout, oarr_t* res){

    ndarr_t real;
    int status;

    if (data == NULL || data->dtype != OTI_F64){
        return (data == NULL) ? DN_ERR_ARGUMENT : OTI_ERR_DTYPE;
    }

    status = oarr_zeros_nd_to(0, data->ndim, data->shape, layout, trc_order, res);

    if (status != DN_OK || oarr_size(res) == 0){
        return status;
    }

    // Block 0 as an element-shaped descriptor (the block axis of extent 1 broadcasts away).
    dnob_block_range(res, 0, 1, &real);
    status = nd_assign(NULL, data, &real);

    return (status == OTI_OK) ? DN_OK : status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Offset (in reals, from element 0 of a block) of the element `index` of `a`: n == ndim indices,
// negative ones counting from the end. DN_ERR_INDEX when one is out of range or n != ndim.
static int dnob_elem_offset(const oarr_t* a, int32_t n, const int64_t* index, int64_t* off){

    int64_t o = 0, i;
    int32_t d;

    if (n != oarr_ndim(a) || (n > 0 && index == NULL)){
        return DN_ERR_INDEX;
    }

    for (d = 0; d < n; d++){

        i = index[d];

        if (i < 0){
            i += oarr_shape(a, d);
        }

        if (i < 0 || i >= oarr_shape(a, d)){
            return DN_ERR_INDEX;
        }

        o += i * a->blocks.strides[1 + d];

    }

    *off = o;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_get_elem_to(const oarr_t* arr, int32_t n, const int64_t* index, otinum_t* res){

    int64_t off, bs;
    ndir_t b, nimag;
    const coeff_t* d;
    int status;

    if (arr == NULL || res == NULL || arr->meta == NULL){
        return DN_ERR_ARGUMENT;
    }

    status = dnob_elem_offset(arr, n, index, &off);

    if (status != DN_OK){
        return status;
    }

    status = oti_reserve(res, oarr_nact(arr), oarr_trc_order(arr));

    if (status != DN_OK){
        return status;
    }

    // The scalar and block layouts match: coefficient b of the scalar is block 1 + b.
    d     = oarr_data(arr) + off;
    bs    = oarr_bstride(arr);
    nimag = sshelp_ndir_total(oarr_nact(arr), oarr_trc_order(arr));

    res->re = d[0];

    for (b = 0; b < nimag; b++){
        res->p_im[b] = d[(int64_t)(1 + b) * bs];
    }

    res->nact      = oarr_nact(arr);
    res->trc_order = oarr_trc_order(arr);
    res->act_order = oarr_act_order(arr);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Raises act_order of the meta of `a` to min(act, trc) (never lowers it: `a` may be a region).
static void dnob_raise_act(oarr_t* a, ord_t act){

    ord_t top = (act < oarr_trc_order(a)) ? act : oarr_trc_order(a);

    if ((int32_t)top > a->meta->act_order){
        a->meta->act_order = (int32_t)top;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes num into the element at offset `off` of `dst`, whose layout holds num's (the caller grew it):
// the directions num lacks are zeroed, act_order is raised.
static void dnob_put_elem(oarr_t* dst, int64_t off, const otinum_t* num){

    bases_t kd = oarr_nact(dst);
    uint64_t b, nb = dnob_nblocks(kd, oarr_trc_order(dst));
    int64_t bs = oarr_bstride(dst);
    coeff_t* d = oarr_data(dst) + off;
    ord_t p, top = (num->act_order < num->trc_order) ? num->act_order : num->trc_order;

    for (b = 1; b < nb; b++){
        d[(int64_t)b * bs] = 0.0;
    }

    d[0] = num->re;

    for (p = 1; p <= top && num->nact > 0; p++){

        ndir_t np = sshelp_ndir_order(num->nact, p), i;
        const coeff_t* src = num->p_im + sshelp_order_offset(num->nact, p);
        int64_t base = (int64_t)oarr_block_index(kd, p, 0);

        for (i = 0; i < np; i++){
            d[(base + (int64_t)i) * bs] = src[i];
        }

    }

    dnob_raise_act(dst, top);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_grow_layout(oarr_t* arr, bases_t nact, ord_t trc_order){

    bases_t k;
    ord_t t0;
    dnob_shape_t S;
    int status;

    if (arr == NULL){
        return DN_ERR_ARGUMENT;
    }

    k  = oarr_nact(arr);
    t0 = oarr_trc_order(arr);

    if (nact <= k && trc_order <= t0){
        return DN_OK;
    }

    if (trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    // Growth through a view always fails (contracts 7.2).
    if (dnob_is_view(arr)){
        return OTI_ERR_BUSY;
    }

    S = dnob_shape_of(arr);

    if (!oarr_owns(arr)){

        size_t n;

        status = dnob_result_shape_s(arr, (nact > k) ? nact : k, &S, (trc_order > t0) ? trc_order : t0,
                                     &n);

        if (status == DN_OK && n > 0){
            memset(oarr_data(arr), 0, n * sizeof(coeff_t));
        }

        if (status == DN_OK){
            oarr_set_act_order(arr, 0);
        }

        return status;

    }

    if (trc_order > t0){

        uint64_t m = oarr_size(arr);
        size_t need, have = dnob_capacity(arr), old = dnob_used(arr);

        if (dnob_nreals(k, trc_order, m, &need) != DN_OK
            || dnob_layout_ok(dnob_nblocks(k, trc_order), &S) != DN_OK){
            return DN_ERR_MEMORY;
        }

        // Blocks of the orders up to t0 keep their indices; the new orders follow them, zero.
        status = dnob_relayout(arr, (need > have) ? need : 0, old, k, trc_order);

        if (status != DN_OK){
            return status;
        }

        arr->cap = k;
        dnob_set_layout(arr, dnob_nblocks(k, trc_order), &S);

        if (need > old){
            memset(oarr_data(arr) + old, 0, (need - old) * sizeof(coeff_t));
        }

    }

    return oarr_add_bases(nact, arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Growth rule of an assignment of a value over (k, trc) into `dst` (contracts 11.6 G1): a root grows
// (unless shared: OTI_ERR_BUSY); a view must already hold the layout (else OTI_ERR_BUSY).
static int dnob_assign_grow(oarr_t* dst, bases_t k, ord_t trc){

    if (k <= oarr_nact(dst) && trc <= oarr_trc_order(dst)){
        return DN_OK;
    }

    if (dnob_is_view(dst)){
        return OTI_ERR_BUSY;
    }

    return oarr_grow_layout(dst, (k > oarr_nact(dst)) ? k : oarr_nact(dst),
                            (trc > oarr_trc_order(dst)) ? trc : oarr_trc_order(dst));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_assign_to(const oarr_t* src, oarr_t* dst){

    bases_t ks, kd;
    ord_t ts, td, as, p;
    oarr_t snap = oarr_init();
    dnob_shape_t S;
    ndarr_t sd, dd;
    int status;

    if (src == NULL || dst == NULL || dst->meta == NULL){
        return DN_ERR_ARGUMENT;
    }

    if (!(dst->blocks.flags & ND_WRITEABLE)){
        return OTI_ERR_READONLY;
    }

    ks = oarr_nact(src);
    ts = oarr_trc_order(src);
    S  = dnob_shape_of(dst);

    // The value must broadcast to the destination (rule S1), checked before anything changes.
    status = dnob_bcast_blocks(src, 0, 1, &S, &sd);

    if (status != DN_OK){
        return status;
    }

    status = dnob_assign_grow(dst, ks, ts);

    if (status != DN_OK){
        return status;
    }

    if (oarr_size(dst) == 0){
        return DN_OK;
    }

    // Snapshot (rule S2): a value that may share memory with the destination is copied first.
    if (src->blocks.buf != NULL && src->blocks.buf == dst->blocks.buf
        && nd_may_share_memory(&src->blocks, &dst->blocks)){

        dnob_shape_t Ss = dnob_shape_of(src);

        Ss.layout = ND_LAYOUT_F;
        status    = dnob_pack(src, &Ss, &snap);

        if (status != DN_OK){
            return status;
        }

        src = &snap;

    }

    kd = oarr_nact(dst);
    td = oarr_trc_order(dst);
    as = (oarr_act_order(src) < ts) ? oarr_act_order(src) : ts;

    // Per order: the value's blocks (a prefix of the destination's, order by order), then zeros for the
    // directions the value lacks; orders above the value's act_order are zero in it.
    for (p = 0; p <= td && status == DN_OK; p++){

        uint64_t Nd = (p == 0) ? 1 : sshelp_ndir_order(kd, p);
        uint64_t Ns = (p == 0) ? 1 : (p > as || ks == 0) ? 0 : sshelp_ndir_order(ks, p);
        uint64_t bd = oarr_block_index(kd, p, 0);

        if (Ns > 0){

            status = dnob_bcast_blocks(src, oarr_block_index(ks, p, 0), Ns, &S, &sd);

            if (status == DN_OK){

                dnob_block_range(dst, bd, Ns, &dd);
                status = nd_assign(NULL, &sd, &dd);

            }

        }

        if (status == DN_OK && Nd > Ns){

            dnob_block_range(dst, bd + Ns, Nd - Ns, &dd);
            status = nd_fill(NULL, &dd, 0.0);

        }

    }

    oarr_free(&snap);

    if (status != DN_OK){
        return (status == OTI_ERR_MEMORY) ? DN_ERR_MEMORY : status;
    }

    dnob_raise_act(dst, as);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Makes `res` a retained view (OARR_VIEW) of `src` over the temporary block descriptor `v` (derived from
// src->blocks): one more reference on the buffer and on the meta. What `res` held is released.
static int dnob_view_finish(const oarr_t* src, const ndarr_t* v, oarr_t* res){

    oarr_t r = oarr_init();
    int status = nd_view_retain(v, &r.blocks);

    if (status != OTI_OK){
        return status;
    }

    r.meta  = oti_meta_retain(src->meta);
    r.cap   = 0;
    r.flags = OARR_VIEW;

    oarr_free(res);
    *res = r;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The items of a key on the block array with the block axis first: a full slice, then the key.
// OTI_ERR_INDEX for too many items; DN_ERR_ARGUMENT for an array item unless allowed.
static int dnob_key_first(int32_t nidx, const nd_index_t* idx, int allow_array, nd_index_t* items,
                          int32_t* n){

    int32_t i;

    if (nidx < 0 || (nidx > 0 && idx == NULL)){
        return DN_ERR_ARGUMENT;
    }

    if (nidx > DNOB_MAX_KEY){
        return DN_ERR_INDEX;
    }

    items[0].kind  = ND_IDX_SLICE;
    items[0].has   = 0;
    items[0].start = 0;
    items[0].stop  = 0;
    items[0].step  = 0;
    items[0].arr   = NULL;

    for (i = 0; i < nidx; i++){

        if (idx[i].kind == ND_IDX_ARRAY && !allow_array){
            return DN_ERR_ARGUMENT;
        }

        items[1 + i] = idx[i];

    }

    *n = nidx + 1;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The items of a key on the block array with the block axis LAST ((*S, nblocks), dnob_blocks_last()):
// the key, an ellipsis unless the key has one, then a full slice of the block axis. With the block axis
// last, NumPy's placement of the advanced result axes (first when they are not adjacent) never moves
// it.
static int dnob_key_last(int32_t nidx, const nd_index_t* idx, nd_index_t* items, int32_t* n){

    int32_t i, k = 0, ellipsis = 0;

    if (nidx < 0 || (nidx > 0 && idx == NULL)){
        return DN_ERR_ARGUMENT;
    }

    if (nidx > DNOB_MAX_KEY){
        return DN_ERR_INDEX;
    }

    for (i = 0; i < nidx; i++){

        ellipsis |= (idx[i].kind == ND_IDX_ELLIPSIS);
        items[k++] = idx[i];

    }

    if (!ellipsis){

        items[k].kind  = ND_IDX_ELLIPSIS;
        items[k].has   = 0;
        items[k].start = 0;
        items[k].stop  = 0;
        items[k].step  = 0;
        items[k].arr   = NULL;
        k++;

    }

    items[k].kind  = ND_IDX_SLICE;
    items[k].has   = 0;
    items[k].start = 0;
    items[k].stop  = 0;
    items[k].step  = 0;
    items[k].arr   = NULL;

    *n = k + 1;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Temporary descriptor of all blocks of `a` with the block axis moved last: (*S, nblocks).
static int dnob_blocks_last(const oarr_t* a, ndarr_t* out){

    int32_t perm[OTI_ND_MAXDIM], d, sdim = oarr_ndim(a);

    for (d = 0; d < sdim; d++){
        perm[d] = 1 + d;
    }

    perm[sdim] = 0;
    nd_init_empty(out);

    return nd_view_transpose(&a->blocks, sdim + 1, perm, out);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_view_index(const oarr_t* src, int32_t nidx, const nd_index_t* idx, oarr_t* res){

    nd_index_t items[DNOB_MAX_KEY + 1];
    ndarr_t v;
    int32_t n;
    int status;

    if (src == NULL || res == NULL || src->meta == NULL){
        return DN_ERR_ARGUMENT;
    }

    status = dnob_key_first(nidx, idx, 0, items, &n);

    if (status != DN_OK){
        return status;
    }

    nd_init_empty(&v);
    status = nd_view_index(&src->blocks, n, items, &v);

    return (status != OTI_OK) ? status : dnob_view_finish(src, &v, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_view_transpose(const oarr_t* src, int32_t naxes, const int32_t* axes, oarr_t* res){

    int32_t perm[OTI_ND_MAXDIM], d, a, sdim;
    ndarr_t v;
    int status;

    if (src == NULL || res == NULL || src->meta == NULL){
        return DN_ERR_ARGUMENT;
    }

    sdim    = oarr_ndim(src);
    perm[0] = 0;

    if (axes == NULL){

        if (naxes != 0){
            return DN_ERR_ARGUMENT;
        }

        for (d = 0; d < sdim; d++){
            perm[1 + d] = sdim - d;
        }

    } else {

        if (naxes != sdim){
            return DN_ERR_ARGUMENT;
        }

        for (d = 0; d < sdim; d++){

            a = (axes[d] < 0) ? axes[d] + sdim : axes[d];

            if (a < 0 || a >= sdim){
                return DN_ERR_INDEX;
            }

            perm[1 + d] = 1 + a;

        }

    }

    nd_init_empty(&v);
    status = nd_view_transpose(&src->blocks, sdim + 1, perm, &v);

    return (status != OTI_OK) ? status : dnob_view_finish(src, &v, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The block-array shape (nblocks, *shape) of a reshape into *full, with one -1 resolved against the
// element count of `src`. DN_ERR_SIZE for a bad rank or size, DN_ERR_ARGUMENT for two -1.
static int dnob_reshape_shape(const oarr_t* src, int32_t ndim, const int64_t* shape, int64_t* full){

    int64_t known = 1, size = (int64_t)oarr_size(src);
    int32_t d, free_axis = -1;

    if (ndim < 0 || ndim > DNOB_MAX_SDIM || (ndim > 0 && shape == NULL)){
        return DN_ERR_SIZE;
    }

    full[0] = src->blocks.shape[0];

    for (d = 0; d < ndim; d++){

        if (shape[d] == -1){

            if (free_axis >= 0){
                return DN_ERR_ARGUMENT;
            }

            free_axis = d;

        } else if (shape[d] < 0){
            return DN_ERR_SIZE;
        } else {
            known *= shape[d];
        }

        full[1 + d] = shape[d];

    }

    if (free_axis >= 0){

        if (known == 0 || size % known != 0){
            return DN_ERR_SIZE;
        }

        full[1 + free_axis] = size / known;
        known = size;

    }

    return (known == size) ? DN_OK : DN_ERR_SIZE;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_view_reshape(const oarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
                      oarr_t* res){

    int64_t full[OTI_ND_MAXDIM];
    ndarr_t v;
    int status;

    if (src == NULL || res == NULL || src->meta == NULL
        || (layout != ND_LAYOUT_C && layout != ND_LAYOUT_F)){
        return DN_ERR_ARGUMENT;
    }

    status = dnob_reshape_shape(src, ndim, shape, full);

    if (status != DN_OK){
        return status;
    }

    nd_init_empty(&v);
    status = nd_view_reshape(&src->blocks, ndim + 1, full, layout, &v);

    return (status != OTI_OK) ? status : dnob_view_finish(src, &v, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_reshape_copy_to(const oarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
                         oarr_t* res){

    int64_t full[OTI_ND_MAXDIM];
    dnob_shape_t S, S2;
    oarr_t r = oarr_init();
    int32_t d;
    int status;

    if (src == NULL || res == NULL || src->meta == NULL
        || (layout != ND_LAYOUT_C && layout != ND_LAYOUT_F)){
        return DN_ERR_ARGUMENT;
    }

    status = dnob_reshape_shape(src, ndim, shape, full);

    if (status != DN_OK){
        return status;
    }

    // Compact in the index order, then relabelled: the flat order of both shapes is the same.
    S        = dnob_shape_of(src);
    S.layout = layout;
    status   = dnob_pack(src, &S, &r);

    if (status != DN_OK){
        return status;
    }

    S2.sdim   = ndim;
    S2.layout = layout;

    for (d = 0; d < ndim; d++){
        S2.ext[d] = (uint64_t)full[1 + d];
    }

    dnob_set_layout(&r, (uint64_t)r.blocks.shape[0], &S2);

    return dnob_store(&r, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_index_get_to(const oarr_t* src, int32_t nidx, const nd_index_t* idx, oarr_t* res){

    nd_index_t items[DNOB_MAX_KEY + 2];
    int32_t perm[OTI_ND_MAXDIM], n, d, sdim;
    ndarr_t last, got;
    oarr_t wrap = oarr_init(), r = oarr_init();
    dnob_shape_t S;
    int status;

    if (src == NULL || res == NULL || src->meta == NULL){
        return DN_ERR_ARGUMENT;
    }

    status = dnob_key_last(nidx, idx, items, &n);

    if (status == DN_OK){
        status = dnob_blocks_last(src, &last);
    }

    if (status != DN_OK){
        return status;
    }

    nd_init_empty(&got);
    status = nd_index_get(NULL, &last, n, items, &got);

    if (status != OTI_OK){
        return status;
    }

    // got is (*Sr, nblocks), C order: move the block axis back first and pack it canonically.
    sdim = got.ndim - 1;
    perm[0] = sdim;

    for (d = 0; d < sdim; d++){
        perm[1 + d] = d;
    }

    status = nd_view_transpose(&got, sdim + 1, perm, &wrap.blocks);

    if (status == OTI_OK){

        wrap.meta = src->meta;
        S         = dnob_shape_of(&wrap);
        S.layout  = ND_LAYOUT_F;
        status    = dnob_pack(&wrap, &S, &r);

    }

    nd_release(&got);

    if (status != DN_OK){
        return status;
    }

    return dnob_store(&r, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether a key has an advanced (array) item.
static int dnob_key_advanced(int32_t nidx, const nd_index_t* idx){

    int32_t i;

    for (i = 0; i < nidx; i++){

        if (idx[i].kind == ND_IDX_ARRAY){
            return 1;
        }

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_index_set(oarr_t* dst, int32_t nidx, const nd_index_t* idx, const oarr_t* src){

    nd_index_t items[DNOB_MAX_KEY + 2];
    oarr_t T, V = oarr_init();
    dnob_shape_t S;
    ndarr_t D, Vl;
    int32_t n, e, lead;
    ord_t as;
    int status;

    if (dst == NULL || src == NULL || dst->meta == NULL || (nidx > 0 && idx == NULL)){
        return DN_ERR_ARGUMENT;
    }

    if (!dnob_key_advanced(nidx, idx)){

        status = dnob_key_first(nidx, idx, 0, items, &n);

        // Check the key before growing: an invalid key changes nothing.
        if (status == DN_OK){

            nd_init_empty(&T.blocks);
            status = nd_view_index(&dst->blocks, n, items, &T.blocks);

        }

        if (status == DN_OK){
            status = dnob_assign_grow(dst, oarr_nact(src), oarr_trc_order(src));
        }

        if (status != DN_OK){
            return status;
        }

        // The region as a temporary view of dst (rebuilt: a growth moved the buffer).
        nd_init_empty(&T.blocks);
        status = nd_view_index(&dst->blocks, n, items, &T.blocks);

        if (status != OTI_OK){
            return status;
        }

        T.meta  = dst->meta;
        T.cap   = 0;
        T.flags = 0;

        return oarr_assign_to(src, &T);

    }

    // Advanced key: the value expanded to dst's layout (its leading extent-1 axes dropped), then one
    // scatter of every block with the block axis last (nd_index_set(), snapshot semantics).
    status = dnob_key_last(nidx, idx, items, &n);

    if (status == DN_OK){
        status = dnob_assign_grow(dst, oarr_nact(src), oarr_trc_order(src));
    }

    if (status != DN_OK){
        return status;
    }

    S        = dnob_shape_of(src);
    S.layout = ND_LAYOUT_F;

    for (lead = 0; lead < S.sdim && S.ext[lead] == 1; lead++){
    }

    for (e = lead; e < S.sdim; e++){
        S.ext[e - lead] = S.ext[e];
    }

    S.sdim -= lead;
    status  = dnob_result_shape_s(&V, oarr_nact(dst), &S, oarr_trc_order(dst), NULL);

    if (status == DN_OK){

        oarr_set_act_order(&V, 0);
        status = oarr_assign_to(src, &V);

    }

    if (status == DN_OK){
        status = dnob_blocks_last(dst, &D);
    }

    if (status == DN_OK){
        status = dnob_blocks_last(&V, &Vl);
    }

    if (status == DN_OK){
        status = nd_index_set(NULL, &D, n, items, &Vl);
    }

    as = oarr_act_order(&V);
    oarr_free(&V);

    if (status != DN_OK){
        return (status == OTI_ERR_MEMORY) ? DN_ERR_MEMORY : status;
    }

    dnob_raise_act(dst, as);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether a key names one element of `a` (one integer per axis, nothing else) and computes its
// offset; DN_ERR_INDEX for an integer out of range.
static int dnob_key_elem(const oarr_t* a, int32_t nidx, const nd_index_t* idx, int64_t* off,
                         int* is_elem){

    int64_t index[OTI_ND_MAXDIM];
    int32_t i;

    *is_elem = 0;

    if (nidx != oarr_ndim(a)){
        return DN_OK;
    }

    for (i = 0; i < nidx; i++){

        if (idx[i].kind != ND_IDX_INT){
            return DN_OK;
        }

        index[i] = idx[i].start;

    }

    *is_elem = 1;

    return dnob_elem_offset(a, nidx, index, off);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_from_oti_to(const otinum_t* num, oarr_t* res){

    int status;

    if (num == NULL || res == NULL){
        return DN_ERR_ARGUMENT;
    }

    status = oarr_zeros_nd_to(num->nact, 0, NULL, ND_LAYOUT_F, num->trc_order, res);

    if (status == DN_OK){
        dnob_put_elem(res, 0, num);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_index_set_o(oarr_t* dst, int32_t nidx, const nd_index_t* idx, const otinum_t* num){

    oarr_t t = oarr_init();
    int64_t off;
    int is_elem, status;

    if (dst == NULL || num == NULL || dst->meta == NULL || (nidx > 0 && idx == NULL)){
        return DN_ERR_ARGUMENT;
    }

    // One element: written in place (the common assembly case).
    status = dnob_key_elem(dst, nidx, idx, &off, &is_elem);

    if (status != DN_OK){
        return status;
    }

    if (is_elem){

        status = dnob_assign_grow(dst, num->nact, num->trc_order);

        if (status == DN_OK){

            // A growth moved the buffer, not the offsets.
            dnob_put_elem(dst, off, num);

        }

        return status;

    }

    status = oarr_from_oti_to(num, &t);

    if (status == DN_OK){
        status = oarr_index_set(dst, nidx, idx, &t);
    }

    oarr_free(&t);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_index_set_r(oarr_t* dst, int32_t nidx, const nd_index_t* idx, coeff_t val){

    otinum_t num;
    int status;

    num           = oti_init();
    num.re        = val;
    status        = oarr_index_set_o(dst, nidx, idx, &num);
    oti_free(&num);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_is_shared(const oarr_t* arr){

    return arr != NULL && !dnob_res_direct(arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarr_raise_act(oarr_t* arr, ord_t act){

    if (arr != NULL && arr->meta != NULL){
        dnob_raise_act(arr, act);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_reshape_root(oarr_t* arr, int32_t ndim, const int64_t* shape){

    int64_t full[OTI_ND_MAXDIM];
    dnob_shape_t S;
    int32_t d;
    int status;

    if (arr == NULL || !oarr_owns(arr)){
        return DN_ERR_ARGUMENT;
    }

    // A compact F root keeps its flat F order under an F-order reshape: a relabel, no data moves.
    if (!dnob_canon(arr)){
        return OTI_ERR_LAYOUT;
    }

    status = dnob_reshape_shape(arr, ndim, shape, full);

    if (status != DN_OK){
        return status;
    }

    S.sdim   = ndim;
    S.layout = ND_LAYOUT_F;

    for (d = 0; d < ndim; d++){
        S.ext[d] = (uint64_t)full[1 + d];
    }

    dnob_set_layout(arr, (uint64_t)arr->blocks.shape[0], &S);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------
