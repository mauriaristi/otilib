// Advanced indexing (nd_index_get / nd_index_set; include/oti/real/ndarray/views.h; Phase 5): integer
// arrays, OTI_U8 masks and their mix with integers, slices, newaxis and one ellipsis, by NumPy's rules
// (PLAN-ndarray-contracts.md 3.4). Included last from src/c/real_ndarray.c; uses views.c's ndw_index
// for the basic part and iter.c / elementwise.c (nd_iter_init, nde_run, nde_broadcast_view,
// nde_alloc_k, nde_copy_into) for the loops. File-static prefix: ndx_.
//
// How an index is applied (both functions):
//   1. Parse: every item is classified; the ellipsis is expanded; a mask must match the extents of the
//      axes it covers (a mask extent of 0 matches any, as in NumPy). A 0-D I64 array is an integer
//      (NumPy). Integers count as advanced items for the axis placement rule (NumPy), but they are
//      applied in the basic part (they only drop their axis and move the data pointer), so they are
//      checked even when nothing else is indexed.
//   2. The basic part V: ndw_index() on the index with every advanced item replaced by integers 0 (an
//      I64 array by one, a k-D mask by k, a 0-D mask by nothing). V's axes are the result axes of the
//      slices, newaxis items and the ellipsis, in order.
//   3. The advanced part B: the broadcast of the components (I64 arrays with their shapes, each k-D mask
//      as one (nnz,) list, all 0-D masks as one (1,) or (0,) list). Its byte offsets from V's data, one
//      int64 per element of B in C order, are computed once (index values checked there) into a
//      temporary charged to the temp budget. NumPy checks no index value when B is empty.
//   4. The result shape R is V's shape with B inserted at the placement position (where the first
//      advanced item was when the advanced items are adjacent, else in front). Element r of R reads
//      or writes V(r's V part) + offset(r's B part). Gather and scatter are three-operand iterations
//      over R: the result (or the values), V with stride 0 on the B axes, and the offsets with stride 0
//      on the V axes.
// The scatter walks R in C order, serially, unless the offsets are provably distinct (at most one
// element of B, or a mask component that is not stretched): the last write in index order wins.


// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

// Component kinds of the advanced part.
#define NDX_C_INDEX 0   // OTI_I64 index array on one axis
#define NDX_C_MASK  1   // OTI_U8 mask of rank >= 1 on mask->ndim axes, as its (nnz,) offset list

// Items of the basic index: every consuming item, the newaxis items and one ellipsis.
#define NDX_MAXITEMS (2 * OTI_ND_MAXDIM + 1)

// Cost per element of the gather / scatter (oti_exec_plan): an estimate for random reads or writes,
// twice the elementwise copy. Not measured (benchmarks need the maintainer's approval).
#define NDX_NS_MOVE 0.3

// One component of the advanced part.
typedef struct {
    const ndarr_t* arr;     // index array or mask
    int32_t        kind;    // NDX_C_*
    int32_t        axis;    // first source axis covered
    int64_t        extent;  // NDX_C_INDEX: extent of the axis
    int64_t        sb;      // NDX_C_INDEX: byte stride of the axis (0 when the extent is <= 1)
    int64_t        nnz;     // NDX_C_MASK: true elements
    int64_t        moff;    // NDX_C_MASK: first entry of its offsets in the mask block
} ndx_comp_t;

// A parsed index applied to a source (or destination) descriptor.
typedef struct {
    ndarr_t     v;                          // basic part (temporary over the source)
    int64_t     bshape[OTI_ND_MAXDIM];      // B
    int64_t     rshape[OTI_ND_MAXDIM];      // R
    ndx_comp_t  comp[OTI_ND_MAXDIM];        // components (each consumes >= 1 axis)
    int64_t     nb;                         // elements of B
    int64_t     nr;                         // elements of R
    int64_t     nmask;                      // offsets of every mask together
    int64_t*    off;                        // nb offsets of B (bytes from v.data), then the masks'
    int32_t     ncomp;                      // components
    int32_t     bnd;                        // rank of B
    int32_t     rnd;                        // rank of R
    int32_t     pos;                        // first axis of B in R
    int32_t     distinct;                   // 1 when the nb offsets are provably distinct
    int32_t     reserved;
} ndx_plan_t;

// Kernel argument of the offset computation.
typedef struct {
    int64_t n;      // extent of the axis (NDX_C_INDEX)
    int64_t sb;     // byte stride of the axis (NDX_C_INDEX)
    int32_t first;  // 1: store, 0: add
    int32_t raw;    // 1: the input already holds byte offsets (masks)
} ndx_okarg_t;

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------------    KERNELS    -------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Offsets: p[0] = the B offsets (output), p[1] = an I64 index array or a mask's offset list broadcast to
// B. Index values are normalized (negative counts from the end) and checked against the extent.
static int ndx_k_offsets(void* arg, int64_t n, char* const* p, const int64_t* bs){

    const ndx_okarg_t* a = (const ndx_okarg_t*)arg;
    char* po = p[0];
    const char* pi = p[1];
    int64_t i, v;

    for (i = 0; i < n; i++){

        int64_t* o = (int64_t*)(po + i * bs[0]);

        v = *(const int64_t*)(pi + i * bs[1]);

        if (!a->raw){
            if (v < 0){
                v += a->n;      // v >= INT64_MIN and n >= 0: no overflow
            }
            if (v < 0 || v >= a->n){
                return OTI_ERR_INDEX;
            }
            v *= a->sb;         // the byte offset of an element of the source: bounded
        }

        *o = a->first ? v : *o + v;

    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Gather of 8-byte elements: p[0] = result, p[1] = V (stride 0 on the B axes), p[2] = B offsets.
// Bit-exact (NaN payloads kept).
static int ndx_k_gather8(void* arg, int64_t n, char* const* p, const int64_t* bs){

    char* po = p[0];
    const char* ps = p[1];
    const char* pf = p[2];
    int64_t i;

    (void)arg;

    if (bs[0] == 8 && bs[1] == 0 && bs[2] == 8){

        const int64_t* f = (const int64_t*)pf;

        for (i = 0; i < n; i++){
            memcpy(po + i * 8, ps + f[i], 8);
        }

        return OTI_OK;

    }

    for (i = 0; i < n; i++){
        memcpy(po + i * bs[0], ps + i * bs[1] + *(const int64_t*)(pf + i * bs[2]), 8);
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Gather of 1-byte elements (OTI_U8), as ndx_k_gather8.
static int ndx_k_gather1(void* arg, int64_t n, char* const* p, const int64_t* bs){

    char* po = p[0];
    const char* ps = p[1];
    const char* pf = p[2];
    int64_t i;

    (void)arg;

    for (i = 0; i < n; i++){
        po[i * bs[0]] = ps[i * bs[1] + *(const int64_t*)(pf + i * bs[2])];
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Scatter kernels: p[0] = values broadcast to R, p[1] = V of the destination (stride 0 on the B axes;
// written through), p[2] = B offsets. One per accepted (destination, values) dtype pair (nd_assign's).
#define NDX_SCATTER(NAME, TD, TS, CONV)                                                                 \
static int NAME(void* arg, int64_t n, char* const* p, const int64_t* bs){                           \
                                                                                                        \
    int64_t i;                                                                                          \
                                                                                                        \
    (void)arg;                                                                                          \
                                                                                                        \
    for (i = 0; i < n; i++){                                                                            \
        TS s;                                                                                           \
        TD d;                                                                                           \
        memcpy(&s, p[0] + i * bs[0], sizeof(TS));                                                       \
        d = CONV(s);                                                                                    \
        memcpy(p[1] + i * bs[1] + *(const int64_t*)(p[2] + i * bs[2]), &d, sizeof(TD));                 \
    }                                                                                                   \
                                                                                                        \
    return OTI_OK;                                                                                      \
                                                                                                        \
}

#define NDX_SAME(s)    (s)
#define NDX_BOOL(s)    ((s) != 0 ? 1.0 : 0.0)
#define NDX_TO_F64(s)  ((double)(s))

NDX_SCATTER(ndx_k_scatter_f64, double,   double,   NDX_SAME)
NDX_SCATTER(ndx_k_scatter_i64, int64_t,  int64_t,  NDX_SAME)
NDX_SCATTER(ndx_k_scatter_u8,  uint8_t,  uint8_t,  NDX_SAME)
NDX_SCATTER(ndx_k_scatter_b2f, double,   uint8_t,  NDX_BOOL)
NDX_SCATTER(ndx_k_scatter_i2f, double,   int64_t,  NDX_TO_F64)
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Scatter kernel of a (destination, values) dtype pair, or NULL (OTI_ERR_DTYPE): the same dtype, or
// OTI_U8 / OTI_I64 into OTI_F64 (as nd_assign).
static nd_inner_fn ndx_scatter_kernel(int32_t dst_dtype, int32_t val_dtype){

    if (dst_dtype == val_dtype){
        return (dst_dtype == OTI_F64) ? ndx_k_scatter_f64 :
               (dst_dtype == OTI_I64) ? ndx_k_scatter_i64 :
               (dst_dtype == OTI_U8)  ? ndx_k_scatter_u8  : NULL;
    }

    if (dst_dtype == OTI_F64 && val_dtype == OTI_U8){
        return ndx_k_scatter_b2f;
    }

    if (dst_dtype == OTI_F64 && val_dtype == OTI_I64){
        return ndx_k_scatter_i2f;
    }

    return NULL;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------------    PARSING    -------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Byte stride of a source axis as the offsets use it: 0 for an extent <= 1 (only index 0 is valid, and
// such a stride is not bounded by validation), else stride * itemsize (bounded: a well-formed
// descriptor reaches element (extent - 1) * stride).
static inline int64_t ndx_axis_bytes(const ndarr_t* a, int32_t ax){

    return (a->shape[ax] > 1) ? a->strides[ax] * nd_itemsize(a->dtype) : 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Element count of a shape: 0 when an extent is 0, else the checked product (OTI_ERR_SIZE).
static int ndx_count(int32_t ndim, const int64_t* shape, int64_t* n){

    int32_t k;

    *n = 1;

    for (k = 0; k < ndim; k++){
        if (shape[k] == 0){
            *n = 0;
            return OTI_OK;
        }
    }

    for (k = 0; k < ndim; k++){
        if (oti_ckd_mul_i64(*n, shape[k], n)){
            return OTI_ERR_SIZE;
        }
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Broadcasts one component shape into B (bnd / bshape): NumPy's rule, right-aligned, extent 1
// stretches. A mismatch is OTI_ERR_SHAPE (status.h: a broadcast failure; NumPy raises IndexError).
static int ndx_broadcast(ndx_plan_t* pl, int32_t nd, const int64_t* shape){

    int32_t k, off;

    if (nd > pl->bnd){
        off = nd - pl->bnd;
        for (k = pl->bnd - 1; k >= 0; k--){
            pl->bshape[k + off] = pl->bshape[k];
        }
        for (k = 0; k < off; k++){
            pl->bshape[k] = 1;
        }
        pl->bnd = nd;
    }

    off = pl->bnd - nd;

    for (k = 0; k < nd; k++){

        int64_t e = shape[k];
        int64_t* b = &pl->bshape[off + k];

        if (e == 1 || e == *b){
            continue;
        }
        if (*b != 1){
            return OTI_ERR_SHAPE;
        }
        *b = e;

    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Walks a mask (rank >= 1, non-empty) in C order; counts its true (nonzero) elements and, when off is
// not NULL, stores the byte offset of each in the source: sum of coordinate * sb[axis]. The offsets
// are maintained incrementally and never leave the valid range of either array.
static int64_t ndx_mask_walk(const ndarr_t* m, const int64_t* sb, int64_t* off){

    int64_t idx[OTI_ND_MAXDIM];
    int64_t mo = 0, so = 0, count = 0, i;
    int32_t k = m->ndim, j;
    int64_t n_in = m->shape[k - 1];
    int64_t ms_in = m->strides[k - 1];
    int64_t sb_in = sb[k - 1];
    const uint8_t* base = (const uint8_t*)m->data;

    for (j = 0; j < k; j++){
        idx[j] = 0;
    }

    for (;;){

        const uint8_t* row = base + mo;

        for (i = 0; i < n_in; i++){
            if (row[i * ms_in] != 0){
                if (off != NULL){
                    off[count] = so + i * sb_in;
                }
                count++;
            }
        }

        // Next row: the odometer over axes 0 .. k-2.
        for (j = k - 2; j >= 0; j--){
            if (idx[j] + 1 < m->shape[j]){
                idx[j]++;
                mo += m->strides[j];
                so += sb[j];
                break;
            }
            mo -= (m->shape[j] - 1) * m->strides[j];
            so -= (m->shape[j] - 1) * sb[j];
            idx[j] = 0;
        }

        if (j < 0){
            break;
        }

    }

    return count;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Parses an index against a (well-formed) source and fills the plan up to the result shape: V, the
// components, B, R, the placement and the distinctness flag. Allocates nothing; pl->off is NULL.
// Without an array item the result is basic indexing (B of rank 0, one element), copied.
// Statuses: ARGUMENT (an unknown kind, a NULL array, a zero step); DTYPE (an index array that is
// neither OTI_I64 nor OTI_U8); INDEX (two ellipses, too many indices, a mask shape mismatch, an
// integer out of range); SHAPE (index arrays that do not broadcast, rank above OTI_ND_MAXDIM); SIZE
// (an element count above INT64_MAX).
static int ndx_parse(const ndarr_t* src, int32_t nidx, const nd_index_t* idx, ndx_plan_t* pl){

    nd_index_t bl[NDX_MAXITEMS];
    ndarr_t sub;
    int64_t sb[OTI_ND_MAXDIM], one = 1, zero_d = 1;
    int32_t nconsumed = 0, nell = 0, nnew = 0, nint = 0, nfax = 0, nbool0 = 0;
    int32_t i, j, k, nbl = 0, ax = 0, rdim = 0, state = -1, vnd;
    int st;

    pl->off = NULL;
    pl->ncomp = 0;
    pl->bnd = 0;
    pl->pos = 0;
    pl->nmask = 0;
    pl->distinct = 0;
    pl->reserved = 0;

    // 1. Classify the items.
    for (i = 0; i < nidx; i++){

        const nd_index_t* it = &idx[i];

        switch (it->kind){
        case ND_IDX_INT:
            nint++;
            nconsumed++;
            break;
        case ND_IDX_SLICE:
            nconsumed++;
            break;
        case ND_IDX_NEWAXIS:
            nnew++;
            break;
        case ND_IDX_ELLIPSIS:
            nell++;
            break;
        case ND_IDX_ARRAY:
            if (it->arr == NULL){
                return OTI_ERR_ARGUMENT;
            }
            NDB_ASSERT_INPUT(it->arr);
            if (it->arr->dtype == OTI_I64 && it->arr->ndim == 0){
                nint++;         // an integer (NumPy), checked even when B is empty
                nconsumed++;
            } else if (it->arr->dtype == OTI_I64){
                nconsumed++;
                nfax++;
            } else if (it->arr->dtype == OTI_U8){
                nconsumed += it->arr->ndim;
                nfax += it->arr->ndim;
                nbool0 += (it->arr->ndim == 0);
            } else {
                return OTI_ERR_DTYPE;
            }
            break;
        default:
            return OTI_ERR_ARGUMENT;
        }

    }

    if (nell > 1 || nconsumed > src->ndim){
        return OTI_ERR_INDEX;
    }
    // V's rank; R's is larger by B's rank, so this bounds both the basic list and the result.
    vnd = src->ndim - nint - nfax + nnew;
    if (vnd > OTI_ND_MAXDIM){
        return OTI_ERR_SHAPE;
    }

    // 2. Axes, components, the basic list and the placement (NumPy's mapiter_fill_info: integers and
    //    arrays are advanced; a slice, newaxis or ellipsis, even an empty one, between two of them
    //    sends B to the front).
    ndw_store(&sub, src);
    for (i = 0; i < nidx; i++){

        const nd_index_t* it = &idx[i];
        int32_t adv = (it->kind == ND_IDX_INT || it->kind == ND_IDX_ARRAY);

        if (adv){
            if (state == -1){
                pl->pos = rdim;
                state = 0;
            } else if (state == 1){
                pl->pos = 0;
                state = 2;
            }
        } else if (state == 0){
            state = 1;
        }

        if (it->kind == ND_IDX_INT || it->kind == ND_IDX_SLICE){
            bl[nbl++] = *it;
            rdim += (it->kind == ND_IDX_SLICE);
            ax++;
        } else if (it->kind == ND_IDX_NEWAXIS){
            bl[nbl++] = *it;
            rdim++;
        } else if (it->kind == ND_IDX_ELLIPSIS){
            bl[nbl++] = *it;
            rdim += src->ndim - nconsumed;
            ax += src->ndim - nconsumed;
        } else {

            const ndarr_t* a = it->arr;
            int32_t nax = (a->dtype == OTI_I64) ? 1 : a->ndim;

            if (a->dtype == OTI_U8 && a->ndim == 0){
                zero_d = zero_d && (*(const uint8_t*)a->data != 0);
                continue;
            }
            if (a->dtype == OTI_I64 && a->ndim == 0){
                bl[nbl] = *it;
                bl[nbl].kind = ND_IDX_INT;
                bl[nbl].start = *(const int64_t*)a->data;
                bl[nbl].arr = NULL;
                nbl++;
                ax++;
                continue;
            }

            for (k = 0; k < nax; k++){
                // NumPy checks a mask axis only when its extent is not 0 (an empty mask axis matches).
                if (a->dtype == OTI_U8 && a->shape[k] != 0 && a->shape[k] != src->shape[ax + k]){
                    return OTI_ERR_INDEX;
                }
                if (sub.shape[ax + k] == 0){
                    sub.shape[ax + k] = 1;    // only V's shape is used then (B is empty or fails)
                }
                bl[nbl].kind = ND_IDX_INT;
                bl[nbl].has = 0;
                bl[nbl].start = 0;
                bl[nbl].stop = 0;
                bl[nbl].step = 0;
                bl[nbl].arr = NULL;
                nbl++;
            }

            pl->comp[pl->ncomp].arr = a;
            pl->comp[pl->ncomp].kind = (a->dtype == OTI_I64) ? NDX_C_INDEX : NDX_C_MASK;
            pl->comp[pl->ncomp].axis = ax;
            pl->comp[pl->ncomp].extent = src->shape[ax];
            pl->comp[pl->ncomp].sb = ndx_axis_bytes(src, ax);
            pl->comp[pl->ncomp].nnz = 0;
            pl->comp[pl->ncomp].moff = 0;
            pl->ncomp++;
            ax += nax;

        }

    }

    // 3. V: integers checked here (NumPy checks them even when B is empty).
    ndw_store(&pl->v, &sub);
    pl->v.flags &= ~(ND_RETAINED | ND_EXPORTED);
    st = ndw_index(&sub, nbl, bl, &pl->v);
    if (st != OTI_OK){
        return st;
    }
    nd_update_flags(&pl->v);

    // 4. B: the components' shapes, the masks as (nnz,) lists, the 0-D masks as one (1,) or (0,).
    for (i = 0; i < pl->ncomp; i++){

        ndx_comp_t* c = &pl->comp[i];

        if (c->kind == NDX_C_INDEX){
            st = ndx_broadcast(pl, c->arr->ndim, c->arr->shape);
        } else {
            for (k = 0; k < c->arr->ndim; k++){
                sb[k] = ndx_axis_bytes(src, c->axis + k);
            }
            c->nnz = (nd_size(c->arr) == 0) ? 0 : ndx_mask_walk(c->arr, sb, NULL);
            c->moff = pl->nmask;
            if (oti_ckd_add_i64(pl->nmask, c->nnz, &pl->nmask)){
                return OTI_ERR_SIZE;
            }
            st = ndx_broadcast(pl, 1, &c->nnz);
        }

        if (st != OTI_OK){
            return st;
        }

    }
    if (nbool0 > 0){
        one = zero_d ? 1 : 0;
        st = ndx_broadcast(pl, 1, &one);
        if (st != OTI_OK){
            return st;
        }
    }

    // 5. R = V[:pos] + B + V[pos:].
    if (vnd + pl->bnd > OTI_ND_MAXDIM){
        return OTI_ERR_SHAPE;
    }
    pl->rnd = vnd + pl->bnd;
    for (k = 0, j = 0; k < pl->rnd; k++){
        if (k >= pl->pos && k < pl->pos + pl->bnd){
            pl->rshape[k] = pl->bshape[k - pl->pos];
        } else {
            pl->rshape[k] = pl->v.shape[j++];
        }
    }
    st = ndx_count(pl->bnd, pl->bshape, &pl->nb);
    if (st == OTI_OK){
        st = ndx_count(pl->rnd, pl->rshape, &pl->nr);
    }
    if (st != OTI_OK){
        return st;
    }

    // 6. Distinct offsets (a parallel scatter): at most one element of B, or a mask list that is B
    //    itself (not stretched): its entries are distinct, and the components cover disjoint axes of a
    //    destination without internal overlap.
    pl->distinct = (pl->nb <= 1);
    for (i = 0; i < pl->ncomp && !pl->distinct; i++){
        if (pl->comp[i].kind == NDX_C_MASK && pl->bnd == 1 && pl->comp[i].nnz == pl->nb){
            pl->distinct = 1;
        }
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Allocates the offset block (nb B offsets, then every mask's list; extra_bytes more are charged to
// the same temp budget check for the caller's own temporary) and computes the offsets. Index values
// are checked only when B is not empty (NumPy). On failure pl->off is NULL.
static int ndx_offsets(oti_ctx* ctx, const ndarr_t* src, ndx_plan_t* pl, int64_t extra_bytes){

    const ndarr_t* ops[2];
    int32_t flags[2] = {ND_ITER_OUT, ND_ITER_IN};
    int64_t sb[OTI_ND_MAXDIM], total, bytes;
    ndx_okarg_t ka;
    ndarr_t od, md, ml;
    nd_iter_t it;
    int32_t i, k, first = 1;
    int st;

    if (oti_ckd_add_i64(pl->nb, pl->nmask, &total) || oti_ckd_mul_i64(total, 8, &bytes)
        || oti_ckd_add_i64(bytes, extra_bytes, &total)){
        return OTI_ERR_SIZE;
    }
    st = oti_ctx_check_temp(ctx, total);
    if (st != OTI_OK || bytes == 0){
        return st;
    }
    pl->off = (int64_t*)ndb_aligned_alloc((size_t)bytes);
    if (pl->off == NULL){
        return OTI_ERR_MEMORY;
    }
    if (pl->nb == 0){
        return OTI_OK;    // nothing indexes: no value is read or checked
    }

    // The masks' lists.
    for (i = 0; i < pl->ncomp; i++){
        const ndx_comp_t* c = &pl->comp[i];
        if (c->kind == NDX_C_MASK && c->nnz > 0){
            for (k = 0; k < c->arr->ndim; k++){
                sb[k] = ndx_axis_bytes(src, c->axis + k);
            }
            (void)ndx_mask_walk(c->arr, sb, pl->off + pl->nb + c->moff);
        }
    }

    // B's offsets: the sum of the components' contributions (0-D masks and integers add nothing).
    memset(&od, 0, sizeof(od));
    od.data = pl->off;
    od.dtype = OTI_I64;
    od.ndim = pl->bnd;
    od.flags = ND_WRITEABLE;
    for (k = 0; k < pl->bnd; k++){
        od.shape[k] = pl->bshape[k];
    }
    st = ndb_contig_strides(pl->bnd, pl->bshape, ND_LAYOUT_C, od.strides);
    if (st != OTI_OK){
        return st;
    }
    nd_update_flags(&od);
    ops[0] = &od;

    for (i = 0; i < pl->ncomp; i++){

        const ndx_comp_t* c = &pl->comp[i];

        ka.first = first;
        if (c->kind == NDX_C_INDEX){
            ka.n = c->extent;
            ka.sb = c->sb;
            ka.raw = 0;
            st = nde_broadcast_view(c->arr, &od, &md);    // the iterator wants B's exact shape
            if (st != OTI_OK){
                return st;
            }
            nd_update_flags(&md);
            ops[1] = &md;
        } else {
            memset(&ml, 0, sizeof(ml));
            ml.data = pl->off + pl->nb + c->moff;
            ml.dtype = OTI_I64;
            ml.ndim = 1;
            ml.shape[0] = c->nnz;
            ml.strides[0] = 1;
            st = nde_broadcast_view(&ml, &od, &md);
            if (st != OTI_OK){
                return st;
            }
            nd_update_flags(&md);
            ka.n = 0;
            ka.sb = 0;
            ka.raw = 1;
            ops[1] = &md;
        }

        st = nd_iter_init(&it, 2, ops, flags, ND_ITER_ORDER_C);
        if (st == OTI_OK){
            st = nde_run(ctx, &it, ndx_k_offsets, &ka, NDE_NS_ARITH);
        }
        if (st != OTI_OK){
            return st;
        }
        first = 0;

    }

    if (first){
        memset(pl->off, 0, (size_t)pl->nb * 8);
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The two R-shaped iteration operands of the plan: base = V with stride 0 on the B axes (read-only
// temporary), offs = the B offsets with stride 0 on the V axes.
static void ndx_operands(const ndx_plan_t* pl, ndarr_t* base, ndarr_t* offs){

    int64_t bstr[OTI_ND_MAXDIM];
    int32_t k, j = 0;

    memset(base, 0, sizeof(*base));
    memset(offs, 0, sizeof(*offs));
    base->data = pl->v.data;
    base->dtype = pl->v.dtype;
    base->ndim = pl->rnd;
    offs->data = pl->off;
    offs->dtype = OTI_I64;
    offs->ndim = pl->rnd;
    (void)ndb_contig_strides(pl->bnd, pl->bshape, ND_LAYOUT_C, bstr);   // nb fits int64 (parse)

    for (k = 0; k < pl->rnd; k++){
        base->shape[k] = pl->rshape[k];
        offs->shape[k] = pl->rshape[k];
        if (k >= pl->pos && k < pl->pos + pl->bnd){
            base->strides[k] = 0;
            offs->strides[k] = bstr[k - pl->pos];
        } else {
            base->strides[k] = pl->v.strides[j++];
            offs->strides[k] = 0;
        }
    }

    nd_update_flags(base);
    nd_update_flags(offs);
    base->flags &= ~ND_WRITEABLE;
    offs->flags &= ~ND_WRITEABLE;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------------    GATHER    --------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_index_get() without last-error recording.
static int ndx_get(oti_ctx* ctx, const ndarr_t* src, int32_t nidx, const nd_index_t* idx,
                   ndarr_t* res){

    const ndarr_t* ops[3];
    int32_t flags[3] = {ND_ITER_OUT, ND_ITER_IN, ND_ITER_IN};
    ndx_plan_t pl;
    ndarr_t base, offs;
    nd_iter_t it;
    int st;

    if (res == NULL){
        return OTI_ERR_ARGUMENT;
    }
    NDB_ASSERT_RECV(res);
    nd_init_empty(res);
    st = oti_ctx_check(ctx);
    if (st != OTI_OK){
        return st;
    }
    if (src == NULL || nidx < 0 || (nidx > 0 && idx == NULL)){
        return OTI_ERR_ARGUMENT;
    }
    NDB_ASSERT_INPUT(src);

    st = ndx_parse(src, nidx, idx, &pl);
    if (st == OTI_OK){
        st = ndx_offsets(ctx, src, &pl, 0);
    }
    if (st == OTI_OK){
        st = nd_alloc(ctx, src->dtype, pl.rnd, pl.rshape, ND_LAYOUT_C, 0, res);
    }
    if (st == OTI_OK && pl.nr > 0){
        ndx_operands(&pl, &base, &offs);
        ops[0] = res;
        ops[1] = &base;
        ops[2] = &offs;
        st = nd_iter_init(&it, 3, ops, flags, ND_ITER_ORDER_C);
        if (st == OTI_OK){
            st = nde_run(ctx, &it, (src->dtype == OTI_U8) ? ndx_k_gather1 : ndx_k_gather8, NULL,
                         NDX_NS_MOVE);
        }
    }

    free(pl.off);
    if (st != OTI_OK){
        nd_release(res);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_index_get(oti_ctx* ctx, const ndarr_t* src, int32_t nidx, const nd_index_t* idx, ndarr_t* res){

    int st = ndx_get(ctx, src, nidx, idx, res);

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_index_get", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------------    SCATTER    -------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_index_set() without last-error recording.
static int ndx_set(oti_ctx* ctx, ndarr_t* dst, int32_t nidx, const nd_index_t* idx,
                   const ndarr_t* values){

    const ndarr_t* ops[3];
    int32_t flags[3] = {ND_ITER_IN, ND_ITER_IN, ND_ITER_IN};
    int64_t snap = 0;
    ndx_plan_t pl;
    ndarr_t base, offs, vv, tmp;
    nd_inner_fn fn;
    nd_iter_t it;
    int st;

    st = oti_ctx_check(ctx);
    if (st != OTI_OK){
        return st;
    }
    if (dst == NULL || values == NULL || nidx < 0 || (nidx > 0 && idx == NULL)){
        return OTI_ERR_ARGUMENT;
    }
    NDB_ASSERT_INPUT(dst);
    NDB_ASSERT_INPUT(values);
    if (!(dst->flags & ND_WRITEABLE)){
        return OTI_ERR_READONLY;
    }
    if (nd_size(dst) > 0 && nd_internal_overlap(dst)){
        return OTI_ERR_LAYOUT;
    }
    fn = ndx_scatter_kernel(dst->dtype, values->dtype);
    if (fn == NULL){
        return OTI_ERR_DTYPE;
    }

    pl.off = NULL;
    st = ndx_parse(dst, nidx, idx, &pl);
    if (st != OTI_OK){
        return st;
    }
    ndx_operands(&pl, &base, &offs);    // offs.data is set again once the offsets exist
    st = nde_broadcast_view(values, &base, &vv);
    if (st != OTI_OK){
        return st;
    }
    nd_update_flags(&vv);

    // Snapshot semantics: values that may share memory with dst are copied first (charged together
    // with the offsets).
    if (nd_may_share_memory(values, dst) != ND_SHARE_NONE
        && oti_ckd_mul_i64(nd_size(values), nd_itemsize(values->dtype), &snap)){
        return OTI_ERR_SIZE;
    }
    st = ndx_offsets(ctx, dst, &pl, snap);
    nd_init_empty(&tmp);
    if (st == OTI_OK && snap > 0 && pl.nr > 0){
        st = nde_alloc_k(ctx, values->dtype, 1, &values, values->ndim, values->shape, 0, &tmp);
        if (st == OTI_OK){
            st = nde_copy_into(ctx, values, &tmp);
        }
        if (st == OTI_OK){
            st = nde_broadcast_view(&tmp, &base, &vv);
            nd_update_flags(&vv);
        }
    }

    if (st == OTI_OK && pl.nr > 0){
        offs.data = pl.off;
        ops[0] = &vv;
        ops[1] = &base;
        ops[2] = &offs;
        st = nd_iter_init(&it, 3, ops, flags, ND_ITER_ORDER_C);
        if (st == OTI_OK){
            if (pl.distinct){
                st = nde_run(ctx, &it, fn, NULL, NDX_NS_MOVE);
            } else {
                st = nd_iter_run(&it, 0, it.size, fn, NULL);    // C order: the last write wins
            }
        }
    }

    nd_release(&tmp);
    free(pl.off);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_index_set(oti_ctx* ctx, ndarr_t* dst, int32_t nidx, const nd_index_t* idx,
                 const ndarr_t* values){

    int st = ndx_set(ctx, dst, nidx, idx, values);

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_index_set", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------
