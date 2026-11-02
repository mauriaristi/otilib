// ndarray basic views (include/oti/real/ndarray/views.h, Phase 1 part; PLAN-ndarray-contracts.md S1,
// 3.3): slice normalization, axis normalization, broadcast shapes, basic indexing, transpose,
// swapaxes, squeeze, expand_dims, broadcast_to, diagonal and the no-copy reshape. Every view is a
// temporary that borrows the source's reference (same buf, ND_RETAINED and ND_EXPORTED cleared); it
// keeps ND_WRITEABLE except broadcast_to, diagonal and layouts nd_internal_overlap() flags. Advanced
// indexing (nd_index_get / nd_index_set) is Phase 5 (index.c). Included from src/c/real_ndarray.c
// after create.c, which uses ndw_resolve_shape() and ndw_view_reshape(). File-static prefix: ndw_.
//
// `out` may be `src` when src is a temporary: every function builds the view in a local descriptor
// and writes `out` last. On failure `out` is left empty, also when it is `src` (contracts 1.4): it is
// cleared only after every check that reads src.


// *******************************************************************************************************
// Copies the descriptor fields and the first ndim shape / stride entries (critic finding 5: never the
// whole 544-byte descriptor).
static inline void ndw_store(ndarr_t* dst, const ndarr_t* src){

    int32_t k;

    dst->data = src->data;
    dst->ndim = src->ndim;
    dst->dtype = src->dtype;
    dst->flags = src->flags;
    dst->reserved = src->reserved;
    dst->buf = src->buf;
    for (k = 0; k < src->ndim; k++){
        dst->shape[k] = src->shape[k];
        dst->strides[k] = src->strides[k];
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Starts a view that holds no reference. It is built directly in out when out is not src, else in
// the caller's local tmp (out == src is allowed for a temporary src). Returns the descriptor to fill.
static inline ndarr_t* ndw_begin(const ndarr_t* src, ndarr_t* out, ndarr_t* tmp){

    ndarr_t* v = (out == src) ? tmp : out;

    ndw_store(v, src);
    v->flags &= ~(ND_RETAINED | ND_EXPORTED);

    return v;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Ends a view: contiguity recomputed, ND_WRITEABLE cleared when asked or when the layout may map two
// indices to one address (contracts 3.3), then stored in out if it was built elsewhere.
static inline void ndw_finish(ndarr_t* v, int32_t readonly, ndarr_t* out){

    nd_update_flags(v);
    if (readonly || ((v->flags & ND_WRITEABLE) && nd_internal_overlap(v))){
        v->flags &= ~ND_WRITEABLE;
    }
    if (v != out){
        ndw_store(out, v);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Failure exit of a view function, after every check that reads src: empties out (also when it is
// src, contracts 1.4) and records the status (NULL context).
static int ndw_fail(const ndarr_t* src, ndarr_t* out, int st, const char* where){

    (void)src;
    if (out != NULL){
        nd_init_empty(out);
    }
    oti_ctx_set_error(NULL, st, where, NULL);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The data pointer of a view: data moved by `off` elements for a non-empty result, data unchanged for
// an empty one (whose offsets need not be meaningful). Callers have checked off; the conversion to
// bytes is checked too, and *st is set to OTI_ERR_SIZE if it overflows (a malformed source).
static inline void* ndw_offset(void* data, int64_t off, int32_t dtype, int32_t empty, int* st){

    int64_t b;

    if (empty || data == NULL){
        return data;
    }
    if (oti_ckd_mul_i64(off, nd_itemsize(dtype), &b)){
        *st = OTI_ERR_SIZE;
        return data;
    }

    return (void*)((char*)data + b);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// --------------------------------------------    HELPERS    --------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_slice_normalize(int64_t n, const nd_index_t* s, int64_t* start, int64_t* step, int64_t* len){

    int64_t st, b, e;

    if (s == NULL || start == NULL || step == NULL || len == NULL || n < 0){
        return OTI_ERR_ARGUMENT;
    }
    st = (s->has & ND_HAS_STEP) ? s->step : 1;
    if (st == 0){
        return OTI_ERR_ARGUMENT;
    }
    if (st < -INT64_MAX){
        st = -INT64_MAX;    // as PySlice_Unpack, so that -step is representable
    }
    if (s->has & ND_HAS_START){
        b = s->start;
        if (b < 0){
            b += n;
            if (b < 0){
                b = (st < 0) ? -1 : 0;
            }
        } else if (b >= n){
            b = (st < 0) ? n - 1 : n;
        }
    } else {
        b = (st < 0) ? n - 1 : 0;
    }
    if (s->has & ND_HAS_STOP){
        e = s->stop;
        if (e < 0){
            e += n;
            if (e < 0){
                e = (st < 0) ? -1 : 0;
            }
        } else if (e >= n){
            e = (st < 0) ? n - 1 : n;
        }
    } else {
        e = (st < 0) ? -1 : n;
    }
    if (st > 0){
        *len = (e > b) ? (e - b - 1) / st + 1 : 0;
    } else {
        *len = (b > e) ? (b - e - 1) / (-st) + 1 : 0;
    }
    *start = b;
    *step = st;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_normalize_axis(int32_t axis, int32_t ndim, int32_t* res){

    if (res == NULL){
        return OTI_ERR_ARGUMENT;
    }
    if (ndim < 0 || axis < -ndim || axis >= ndim){
        return OTI_ERR_INDEX;
    }
    *res = (axis < 0) ? axis + ndim : axis;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_broadcast_shapes(int32_t nops, const ndarr_t* const* ops, int32_t* ndim, int64_t* shape){

    int64_t r[OTI_ND_MAXDIM];
    int32_t i, k, nd = 0;

    if (nops < 1 || ops == NULL || ndim == NULL || shape == NULL){
        return OTI_ERR_ARGUMENT;
    }
    for (i = 0; i < nops; i++){
        if (ops[i] == NULL){
            return OTI_ERR_ARGUMENT;
        }
        if (ops[i]->ndim < 0 || ops[i]->ndim > OTI_ND_MAXDIM){
            return OTI_ERR_SHAPE;
        }
        if (ops[i]->ndim > nd){
            nd = ops[i]->ndim;
        }
    }
    for (k = 0; k < nd; k++){
        r[k] = 1;
    }
    for (i = 0; i < nops; i++){
        const ndarr_t* a = ops[i];
        int32_t off = nd - a->ndim;
        for (k = 0; k < a->ndim; k++){
            int64_t e = a->shape[k];
            if (e == 1){
                continue;
            }
            if (r[off + k] == 1){
                r[off + k] = e;
            } else if (r[off + k] != e){
                return OTI_ERR_SHAPE;
            }
        }
    }
    *ndim = nd;
    for (k = 0; k < nd; k++){
        shape[k] = r[k];
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -----------------------------------------    BASIC VIEWS    -------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_view_index() into v (already begun from src); returns a status, records nothing.
static int ndw_index(const ndarr_t* src, int32_t nidx, const nd_index_t* idx, ndarr_t* v){

    int32_t i, k, nconsumed = 0, nell = 0, nint = 0, nnew = 0, ax = 0, r = 0, rank, empty = 0;
    int64_t off = 0, t;
    int ovf = 0, st = OTI_OK;

    for (i = 0; i < nidx; i++){
        switch (idx[i].kind){
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
        default:
            return OTI_ERR_ARGUMENT;
        }
    }
    if (nell > 1 || nconsumed > src->ndim){
        return OTI_ERR_INDEX;
    }
    rank = src->ndim - nint + nnew;
    if (rank > OTI_ND_MAXDIM){
        return OTI_ERR_SHAPE;
    }

    for (i = 0; i < nidx; i++){
        const nd_index_t* it = &idx[i];
        if (it->kind == ND_IDX_INT){
            int64_t n = src->shape[ax], j = it->start;
            if (j < -n || j >= n){
                return OTI_ERR_INDEX;
            }
            if (j < 0){
                j += n;
            }
            // Checked: an empty source may carry strides that no accessed offset bounds.
            if (oti_ckd_mul_i64(j, src->strides[ax], &t) || oti_ckd_add_i64(off, t, &off)){
                ovf = 1;
            }
            ax++;
        } else if (it->kind == ND_IDX_SLICE){
            int64_t start, step, len, s;
            if (nd_slice_normalize(src->shape[ax], it, &start, &step, &len) != OTI_OK){
                return OTI_ERR_ARGUMENT;
            }
            if (len <= 0){
                len = 0;
                s = src->strides[ax];
            } else {
                if (oti_ckd_mul_i64(start, src->strides[ax], &t) || oti_ckd_add_i64(off, t, &off)){
                    ovf = 1;
                }
                if (oti_ckd_mul_i64(step, src->strides[ax], &s)){
                    s = src->strides[ax];    // len == 1 or an empty result: the stride is unused
                }
            }
            v->shape[r] = len;
            v->strides[r] = s;
            ax++;
            r++;
        } else if (it->kind == ND_IDX_NEWAXIS){
            v->shape[r] = 1;
            v->strides[r] = 0;
            r++;
        } else {
            for (k = 0; k < src->ndim - nconsumed; k++){
                v->shape[r] = src->shape[ax];
                v->strides[r] = src->strides[ax];
                ax++;
                r++;
            }
        }
    }
    while (ax < src->ndim){
        v->shape[r] = src->shape[ax];
        v->strides[r] = src->strides[ax];
        ax++;
        r++;
    }
    v->ndim = r;
    // Emptiness decides before any offset is used: an empty result keeps src's data pointer.
    for (k = 0; k < r; k++){
        if (v->shape[k] == 0){
            empty = 1;
        }
    }
    if (!empty && ovf){
        return OTI_ERR_SIZE;    // not reachable for a well-formed non-empty source
    }
    v->data = ndw_offset(src->data, off, src->dtype, empty, &st);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_view_index(const ndarr_t* src, int32_t nidx, const nd_index_t* idx, ndarr_t* out){

    ndarr_t tmp, *v;
    int st;

    if (src == NULL || out == NULL || nidx < 0 || (nidx > 0 && idx == NULL)){
        return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_index");
    }
    NDB_ASSERT_RECV(out);
    NDB_ASSERT_INPUT(src);
    v = ndw_begin(src, out, &tmp);
    st = ndw_index(src, nidx, idx, v);
    if (st != OTI_OK){
        return ndw_fail(src, out, st, "nd_view_index");
    }
    ndw_finish(v, 0, out);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_view_transpose(const ndarr_t* src, int32_t naxes, const int32_t* axes, ndarr_t* out){

    int32_t perm[OTI_ND_MAXDIM], seen[OTI_ND_MAXDIM], k, nd;
    ndarr_t tmp, *v;

    if (src == NULL || out == NULL){
        return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_transpose");
    }
    NDB_ASSERT_RECV(out);
    NDB_ASSERT_INPUT(src);
    nd = src->ndim;
    if (axes == NULL){
        if (naxes != 0 && naxes != nd){
            return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_transpose");
        }
        for (k = 0; k < nd; k++){
            perm[k] = nd - 1 - k;
        }
    } else {
        if (naxes != nd){
            return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_transpose");
        }
        for (k = 0; k < nd; k++){
            seen[k] = 0;
        }
        for (k = 0; k < nd; k++){
            if (nd_normalize_axis(axes[k], nd, &perm[k]) != OTI_OK){
                return ndw_fail(src, out, OTI_ERR_INDEX, "nd_view_transpose");
            }
        }
        for (k = 0; k < nd; k++){
            if (seen[perm[k]]++){
                return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_transpose");
            }
        }
    }
    v = ndw_begin(src, out, &tmp);
    for (k = 0; k < nd; k++){
        v->shape[k] = src->shape[perm[k]];
        v->strides[k] = src->strides[perm[k]];
    }
    ndw_finish(v, 0, out);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_view_swapaxes(const ndarr_t* src, int32_t axis1, int32_t axis2, ndarr_t* out){

    int32_t a1, a2;
    ndarr_t tmp, *v;

    if (src == NULL || out == NULL){
        return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_swapaxes");
    }
    NDB_ASSERT_RECV(out);
    NDB_ASSERT_INPUT(src);
    if (nd_normalize_axis(axis1, src->ndim, &a1) != OTI_OK ||
        nd_normalize_axis(axis2, src->ndim, &a2) != OTI_OK){
        return ndw_fail(src, out, OTI_ERR_INDEX, "nd_view_swapaxes");
    }
    v = ndw_begin(src, out, &tmp);
    v->shape[a1] = src->shape[a2];
    v->strides[a1] = src->strides[a2];
    v->shape[a2] = src->shape[a1];
    v->strides[a2] = src->strides[a1];
    ndw_finish(v, 0, out);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_view_squeeze(const ndarr_t* src, int32_t naxes, const int32_t* axes, ndarr_t* out){

    int32_t drop[OTI_ND_MAXDIM], k, a, r = 0;
    ndarr_t tmp, *v;

    if (src == NULL || out == NULL || naxes < 0 || (naxes > 0 && axes == NULL)){
        return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_squeeze");
    }
    NDB_ASSERT_RECV(out);
    NDB_ASSERT_INPUT(src);
    for (k = 0; k < src->ndim; k++){
        drop[k] = (axes == NULL && src->shape[k] == 1);
    }
    if (axes != NULL){
        for (k = 0; k < naxes; k++){
            if (nd_normalize_axis(axes[k], src->ndim, &a) != OTI_OK){
                return ndw_fail(src, out, OTI_ERR_INDEX, "nd_view_squeeze");
            }
            if (drop[a]){
                return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_squeeze");
            }
            drop[a] = 1;
        }
        for (k = 0; k < src->ndim; k++){
            if (drop[k] && src->shape[k] != 1){
                return ndw_fail(src, out, OTI_ERR_SHAPE, "nd_view_squeeze");
            }
        }
    }
    v = ndw_begin(src, out, &tmp);
    for (k = 0; k < src->ndim; k++){
        if (!drop[k]){
            v->shape[r] = src->shape[k];
            v->strides[r] = src->strides[k];
            r++;
        }
    }
    v->ndim = r;
    ndw_finish(v, 0, out);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_view_expand_dims(const ndarr_t* src, int32_t naxes, const int32_t* axes, ndarr_t* out){

    int32_t isnew[OTI_ND_MAXDIM], k, a, nd, s = 0;
    ndarr_t tmp, *v;

    if (src == NULL || out == NULL || naxes < 0 || (naxes > 0 && axes == NULL)){
        return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_expand_dims");
    }
    NDB_ASSERT_RECV(out);
    NDB_ASSERT_INPUT(src);
    if (naxes > OTI_ND_MAXDIM - src->ndim){
        return ndw_fail(src, out, OTI_ERR_SHAPE, "nd_view_expand_dims");
    }
    nd = src->ndim + naxes;
    for (k = 0; k < nd; k++){
        isnew[k] = 0;
    }
    for (k = 0; k < naxes; k++){
        if (nd_normalize_axis(axes[k], nd, &a) != OTI_OK){
            return ndw_fail(src, out, OTI_ERR_INDEX, "nd_view_expand_dims");
        }
        if (isnew[a]){
            return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_expand_dims");
        }
        isnew[a] = 1;
    }
    v = ndw_begin(src, out, &tmp);
    for (k = 0; k < nd; k++){
        if (!isnew[k]){
            v->shape[k] = src->shape[s];
            v->strides[k] = src->strides[s];
            s++;
        }
    }
    // A new axis gets the stride a contiguous array would have there (it is never stepped).
    for (k = nd - 1; k >= 0; k--){
        if (isnew[k]){
            if (k == nd - 1){
                v->strides[k] = 1;
            } else {
                int64_t e = v->shape[k + 1] > 0 ? v->shape[k + 1] : 1, t;
                v->strides[k] = oti_ckd_mul_i64(v->strides[k + 1], e, &t) ? v->strides[k + 1] : t;
            }
            v->shape[k] = 1;
        }
    }
    v->ndim = nd;
    ndw_finish(v, 0, out);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_view_broadcast_to(const ndarr_t* src, int32_t ndim, const int64_t* shape, ndarr_t* out){

    int32_t k, off;
    ndarr_t tmp, *v;

    if (src == NULL || out == NULL || (ndim > 0 && shape == NULL)){
        return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_broadcast_to");
    }
    NDB_ASSERT_RECV(out);
    NDB_ASSERT_INPUT(src);
    if (ndim < src->ndim || ndim > OTI_ND_MAXDIM){
        return ndw_fail(src, out, OTI_ERR_SHAPE, "nd_view_broadcast_to");
    }
    off = ndim - src->ndim;
    for (k = 0; k < ndim; k++){
        if (shape[k] < 0){
            return ndw_fail(src, out, OTI_ERR_SHAPE, "nd_view_broadcast_to");
        }
    }
    // The result's element count (product of the non-zero extents) and byte count must fit int64.
    {
        int64_t count = 1, bytes;
        for (k = 0; k < ndim; k++){
            if (shape[k] > 0 && oti_ckd_mul_i64(count, shape[k], &count)){
                return ndw_fail(src, out, OTI_ERR_SIZE, "nd_view_broadcast_to");
            }
        }
        if (oti_ckd_mul_i64(count, nd_itemsize(src->dtype), &bytes)){
            return ndw_fail(src, out, OTI_ERR_SIZE, "nd_view_broadcast_to");
        }
    }
    v = ndw_begin(src, out, &tmp);
    for (k = 0; k < ndim; k++){
        if (k < off){
            v->strides[k] = 0;
        } else {
            int64_t e = src->shape[k - off];
            if (e == shape[k]){
                v->strides[k] = src->strides[k - off];
            } else if (e == 1){
                v->strides[k] = 0;
            } else {
                return ndw_fail(src, out, OTI_ERR_SHAPE, "nd_view_broadcast_to");
            }
        }
    }
    for (k = 0; k < ndim; k++){
        v->shape[k] = shape[k];
    }
    v->ndim = ndim;
    ndw_finish(v, 1, out);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_view_diagonal(const ndarr_t* src, int64_t offset, int32_t axis1, int32_t axis2, ndarr_t* out){

    int64_t n1, n2, s1, s2, len, ds, off = 0;
    int32_t a1, a2, k, r = 0, empty;
    ndarr_t tmp, *v;
    int st = OTI_OK;

    if (src == NULL || out == NULL){
        return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_diagonal");
    }
    NDB_ASSERT_RECV(out);
    NDB_ASSERT_INPUT(src);
    if (src->ndim < 2){
        return ndw_fail(src, out, OTI_ERR_SHAPE, "nd_view_diagonal");
    }
    if (nd_normalize_axis(axis1, src->ndim, &a1) != OTI_OK ||
        nd_normalize_axis(axis2, src->ndim, &a2) != OTI_OK){
        return ndw_fail(src, out, OTI_ERR_INDEX, "nd_view_diagonal");
    }
    if (a1 == a2){
        return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_diagonal");
    }
    n1 = src->shape[a1];
    n2 = src->shape[a2];
    s1 = src->strides[a1];
    s2 = src->strides[a2];
    // NumPy's PyArray_Diagonal: an offset outside the matrix gives length 0 and no data offset. The
    // length comes first; the offset is computed only for a non-empty result (an empty source may
    // carry strides that no accessed offset bounds), and checked.
    if (offset >= 0){
        len = (offset >= n2) ? 0 : ((n2 - offset < n1) ? n2 - offset : n1);
    } else {
        len = (offset == INT64_MIN || -offset >= n1) ? 0 : ((n1 + offset < n2) ? n1 + offset : n2);
    }
    if (len < 0){
        len = 0;
    }
    empty = (len == 0);
    for (k = 0; k < src->ndim; k++){
        if (k != a1 && k != a2 && src->shape[k] == 0){
            empty = 1;
        }
    }
    if (!empty){
        int ovf = (offset >= 0) ? oti_ckd_mul_i64(offset, s2, &off) :
                                  oti_ckd_mul_i64(-offset, s1, &off);
        if (ovf){
            // Not reachable for a well-formed source.
            return ndw_fail(src, out, OTI_ERR_SIZE, "nd_view_diagonal");
        }
    }
    if (oti_ckd_add_i64(s1, s2, &ds)){
        ds = s1;    // len <= 1 or an empty result: the stride is unused
    }
    v = ndw_begin(src, out, &tmp);
    for (k = 0; k < src->ndim; k++){
        if (k != a1 && k != a2){
            v->shape[r] = src->shape[k];
            v->strides[r] = src->strides[k];
            r++;
        }
    }
    v->shape[r] = len;
    v->strides[r] = ds;
    v->ndim = r + 1;
    v->data = ndw_offset(src->data, off, src->dtype, empty, &st);
    if (st != OTI_OK){
        return ndw_fail(src, out, st, "nd_view_diagonal");
    }
    ndw_finish(v, 1, out);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------------    RESHAPE    ---------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Resolves a requested shape (one -1 allowed) against an element count. OTI_ERR_SHAPE when the
// counts differ, for several -1, other negative extents, or a -1 next to a zero-size remainder.
static int ndw_resolve_shape(int64_t size, int32_t ndim, const int64_t* in, int64_t* out){

    int64_t known = 1;
    int32_t k, unknown = -1, overflow = 0;

    if (ndim < 0 || ndim > OTI_ND_MAXDIM){
        return OTI_ERR_SHAPE;
    }
    if (ndim > 0 && in == NULL){
        return OTI_ERR_ARGUMENT;
    }
    for (k = 0; k < ndim; k++){
        if (in[k] == -1){
            if (unknown >= 0){
                return OTI_ERR_SHAPE;
            }
            unknown = k;
        } else if (in[k] < 0){
            return OTI_ERR_SHAPE;
        }
    }
    for (k = 0; k < ndim; k++){
        out[k] = in[k];
        if (k != unknown && !overflow && oti_ckd_mul_i64(known, in[k], &known)){
            overflow = 1;
        }
    }
    if (overflow){
        return OTI_ERR_SHAPE;
    }
    // The product of the non-zero extents must fit int64 also for an empty result (nd_size()).
    {
        int64_t nz = 1;
        for (k = 0; k < ndim; k++){
            if (k != unknown && in[k] > 0 && oti_ckd_mul_i64(nz, in[k], &nz)){
                return OTI_ERR_SIZE;
            }
        }
    }
    if (unknown >= 0){
        if (known == 0 || size % known != 0){
            return OTI_ERR_SHAPE;
        }
        out[unknown] = size / known;
    } else if (known != size){
        return OTI_ERR_SHAPE;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// NumPy's _attempt_nocopy_reshape: strides for newdims over the memory of a (size > 1), or 0 when
// the old axes cannot be merged or split without a copy.
static int ndw_nocopy_strides(const ndarr_t* a, int32_t newnd, const int64_t* newdims, int32_t fo,
                              int64_t* newstrides){

    int64_t olddims[OTI_ND_MAXDIM], oldstrides[OTI_ND_MAXDIM], last;
    int32_t oldnd = 0, oi, oj, ok, ni, nj, nk;

    for (oi = 0; oi < a->ndim; oi++){
        if (a->shape[oi] != 1){
            olddims[oldnd] = a->shape[oi];
            oldstrides[oldnd] = a->strides[oi];
            oldnd++;
        }
    }
    oi = 0;
    oj = 1;
    ni = 0;
    nj = 1;
    while (ni < newnd && oi < oldnd){
        int64_t np = newdims[ni], op = olddims[oi];
        while (np != op){
            if (np < op){
                np *= newdims[nj++];
            } else {
                op *= olddims[oj++];
            }
        }
        for (ok = oi; ok < oj - 1; ok++){
            if (fo){
                if (oldstrides[ok + 1] != olddims[ok] * oldstrides[ok]){
                    return 0;
                }
            } else if (oldstrides[ok] != olddims[ok + 1] * oldstrides[ok + 1]){
                return 0;
            }
        }
        if (fo){
            newstrides[ni] = oldstrides[oi];
            for (nk = ni + 1; nk < nj; nk++){
                newstrides[nk] = newstrides[nk - 1] * newdims[nk - 1];
            }
        } else {
            newstrides[nj - 1] = oldstrides[oj - 1];
            for (nk = nj - 1; nk > ni; nk--){
                newstrides[nk - 1] = newstrides[nk] * newdims[nk];
            }
        }
        ni = nj++;
        oi = oj++;
    }
    // Trailing extents of 1.
    if (ni >= 1){
        last = newstrides[ni - 1];
        if (fo){
            last *= newdims[ni - 1];
        }
    } else {
        last = 1;
    }
    for (nk = ni; nk < newnd; nk++){
        newstrides[nk] = last;
    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The index order of a reshape: ND_LAYOUT_C or _F (A resolved against src), or -1 for an invalid one.
static int32_t ndw_reshape_order(const ndarr_t* src, int32_t layout){

    ndarr_t t;

    if (layout == ND_LAYOUT_C || layout == ND_LAYOUT_F){
        return layout;
    }
    if (layout != ND_LAYOUT_A){
        return -1;
    }
    t = *src;
    nd_update_flags(&t);

    return ((t.flags & ND_F_CONTIG) && !(t.flags & ND_C_CONTIG)) ? ND_LAYOUT_F : ND_LAYOUT_C;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_view_reshape() without recording: OTI_ERR_LAYOUT when only a copy can express the reshape.
static int ndw_view_reshape(const ndarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
                            ndarr_t* out){

    int64_t ns[OTI_ND_MAXDIM], nstr[OTI_ND_MAXDIM];
    int32_t order, k, contig;
    ndarr_t tmp, t, *v;
    int st;

    order = ndw_reshape_order(src, layout);
    if (order < 0){
        return OTI_ERR_ARGUMENT;
    }
    st = ndw_resolve_shape(nd_size(src), ndim, shape, ns);
    if (st != OTI_OK){
        return st;
    }
    // The target's non-zero extent product in bytes must fit int64 (nd_validate() step 4), also for
    // an empty target such as (0, 2^60) of F64.
    {
        int64_t nz = 1, bytes;
        for (k = 0; k < ndim; k++){
            if (ns[k] > 0 && oti_ckd_mul_i64(nz, ns[k], &nz)){
                return OTI_ERR_SIZE;
            }
        }
        if (oti_ckd_mul_i64(nz, nd_itemsize(src->dtype), &bytes)){
            return OTI_ERR_SIZE;
        }
    }
    t = *src;
    nd_update_flags(&t);
    contig = (order == ND_LAYOUT_C) ? (t.flags & ND_C_CONTIG) : (t.flags & ND_F_CONTIG);
    if (contig){
        st = ndb_contig_strides(ndim, ns, order, nstr);
        if (st != OTI_OK){
            return st;
        }
    } else if (!ndw_nocopy_strides(src, ndim, ns, order == ND_LAYOUT_F, nstr)){
        return OTI_ERR_LAYOUT;
    }
    v = ndw_begin(src, out, &tmp);
    for (k = 0; k < ndim; k++){
        v->shape[k] = ns[k];
        v->strides[k] = nstr[k];
    }
    v->ndim = ndim;
    ndw_finish(v, 0, out);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_view_reshape(const ndarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
                    ndarr_t* out){

    int st;

    if (src == NULL || out == NULL){
        return ndw_fail(src, out, OTI_ERR_ARGUMENT, "nd_view_reshape");
    }
    NDB_ASSERT_RECV(out);
    NDB_ASSERT_INPUT(src);
    st = ndw_view_reshape(src, ndim, shape, layout, out);
    if (st != OTI_OK){
        // OTI_ERR_LAYOUT (only a copy can express the reshape) is recorded like every other failure;
        // nd_reshape() uses the non-recording ndw_view_reshape() and copies instead.
        return ndw_fail(src, out, st, "nd_view_reshape");
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------
