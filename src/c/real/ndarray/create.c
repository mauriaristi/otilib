// ndarray creators, copies and view-or-copy conversions (include/oti/real/ndarray/create.h, Phase 1):
// empty, zeros, ones, full, eye, arange, linspace, copy (C / F / A / K), ascontiguous, asfortran and
// reshape. Values follow NumPy 2. Included from src/c/real_ndarray.c after validate.c; uses
// buffer.c's ndb_alloc_array / ndb_view_retain and views.c's reshape helpers (declared below, defined
// later in the unity). File-static prefix: ndc_.

#include <math.h>
#include <string.h>

static int ndw_view_reshape(const ndarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
                            ndarr_t* out);
static int ndw_resolve_shape(int64_t size, int32_t ndim, const int64_t* in, int64_t* out);
static int32_t ndw_reshape_order(const ndarr_t* src, int32_t layout);


// *******************************************************************************************************
// Records a failure of a public creator (once, at the outermost level) and returns it.
static int ndc_fail(oti_ctx* ctx, int st, const char* where){

    oti_ctx_set_error(ctx, st, where, NULL);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The context check of a public creator (contracts 5.1): on rejection res is emptied and the status
// recorded. Runs before any allocation.
static int ndc_ctx(oti_ctx* ctx, ndarr_t* res, const char* where){

    int st = oti_ctx_check(ctx);

    if (st != OTI_OK){
        if (res != NULL){
            NDB_ASSERT_RECV(res);
            nd_init_empty(res);
        }
        oti_ctx_set_error(ctx, st, where, "invalid context");
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Copies the elements of src, visited with axis perm[0] outermost and perm[ndim-1] innermost, into
// contiguous memory dst of the same dtype. Elements are moved as bytes (memcpy), never through an
// integer lvalue, so NaN payloads and signed zeros are kept and no aliasing rule is involved. The
// outer index carries with -(shape - 1) * stride, so no offset leaves the accessed span.
static void ndc_gather(const ndarr_t* src, const int32_t* perm, void* dst){

    int64_t idx[OTI_ND_MAXDIM], n = nd_size(src), ni, si, off = 0, o, i, nouter, isz;
    const char* base = (const char*)src->data;
    char* d = (char*)dst;
    int32_t nd = src->ndim, k, j;

    if (n == 0){
        return;
    }
    isz = nd_itemsize(src->dtype);
    if (nd == 0){
        memcpy(dst, base, (size_t)isz);
        return;
    }
    for (k = 0; k < nd; k++){
        idx[k] = 0;
    }
    ni = src->shape[perm[nd - 1]];
    si = src->strides[perm[nd - 1]];
    nouter = n / ni;
    for (o = 0; o < nouter; o++){
        const char* s = base + off * isz;
        if (si == 1){
            memcpy(d, s, (size_t)(ni * isz));
        } else if (isz == 8){
            for (i = 0; i < ni; i++){
                memcpy(d + i * 8, s + i * si * 8, 8);
            }
        } else {
            for (i = 0; i < ni; i++){
                d[i] = s[i * si];
            }
        }
        d += ni * isz;
        if (o + 1 == nouter){
            break;
        }
        for (j = nd - 2; j >= 0; j--){
            k = perm[j];
            if (idx[k] + 1 < src->shape[k]){
                idx[k]++;
                off += src->strides[k];
                break;
            }
            off -= (src->shape[k] - 1) * src->strides[k];
            idx[k] = 0;
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// New array of shape (ndim, shape) in `order` (C or F) holding the elements of src read in that index
// order (the copy of nd_copy C / F and of a reshape). res may be src: it is written last.
static int ndc_copy_order(oti_ctx* ctx, const ndarr_t* src, int32_t ndim, const int64_t* shape,
                          int32_t order, ndarr_t* res){

    int32_t perm[OTI_ND_MAXDIM], k;
    ndarr_t t;
    int st;

    nd_init_empty(&t);
    st = ndb_alloc_array(ctx, src->dtype, ndim, shape, order, 0, &t);
    if (st != OTI_OK){
        nd_init_empty(res);
        return st;
    }
    for (k = 0; k < src->ndim; k++){
        perm[k] = (order == ND_LAYOUT_F) ? src->ndim - 1 - k : k;
    }
    ndc_gather(src, perm, t.data);
    *res = t;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The K order of src: axes of extent > 1 by decreasing |stride| (unsigned magnitudes, no signed
// negation), ties by axis index (stable insertion sort). Axes of extent <= 1 never step: they keep
// their own slot and the sorted axes fill the other slots in order. C, F and the dense SoA block
// layout (nb, r, c) / (r*c, 1, r) map to themselves.
static void ndc_k_perm(const ndarr_t* src, int32_t* perm){

    int32_t sorted[OTI_ND_MAXDIM], ns = 0, slot = 0, k, j, nd = src->ndim;
    uint64_t mag[OTI_ND_MAXDIM];

    for (k = 0; k < nd; k++){
        int64_t sk = src->strides[k];
        mag[k] = sk < 0 ? (uint64_t)0 - (uint64_t)sk : (uint64_t)sk;
    }
    for (k = 0; k < nd; k++){
        if (src->shape[k] <= 1){
            continue;
        }
        for (j = ns; j > 0 && mag[sorted[j - 1]] < mag[k]; j--){
            sorted[j] = sorted[j - 1];
        }
        sorted[j] = k;
        ns++;
    }
    for (k = 0; k < nd; k++){
        perm[k] = (src->shape[k] <= 1) ? k : sorted[slot++];
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// New compact array of src's shape and dtype in its K layout (C over the permuted shape, strides
// permuted back), through nd_alloc_strided's checks. perm receives the K order. No recording.
static int ndc_alloc_like(oti_ctx* ctx, const ndarr_t* src, int32_t alloc_flags, int32_t* perm,
                          ndarr_t* res){

    int64_t pshape[OTI_ND_MAXDIM], pstr[OTI_ND_MAXDIM], str[OTI_ND_MAXDIM];
    int32_t k, nd = src->ndim;
    int st;

    ndc_k_perm(src, perm);
    for (k = 0; k < nd; k++){
        pshape[k] = src->shape[perm[k]];
    }
    st = ndb_contig_strides(nd, pshape, ND_LAYOUT_C, pstr);
    if (st != OTI_OK){
        nd_init_empty(res);
        return st;
    }
    for (k = 0; k < nd; k++){
        str[perm[k]] = pstr[k];
    }

    return ndb_alloc_strided(ctx, src->dtype, nd, src->shape, str, alloc_flags, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_copy() without recording. ND_LAYOUT_A maps a layout that is neither C nor F (e.g. the SoA block
// layout) to C, as NumPy does; OTI code copies with ND_LAYOUT_K, which keeps it.
static int ndc_copy(oti_ctx* ctx, const ndarr_t* src, int32_t layout, ndarr_t* res){

    int32_t perm[OTI_ND_MAXDIM];
    ndarr_t t;
    int st;

    if (layout == ND_LAYOUT_C || layout == ND_LAYOUT_F || layout == ND_LAYOUT_A){
        int32_t order = ndw_reshape_order(src, layout);
        return ndc_copy_order(ctx, src, src->ndim, src->shape, order, res);
    }
    if (layout != ND_LAYOUT_K){
        nd_init_empty(res);
        return OTI_ERR_ARGUMENT;
    }
    // Built in a local descriptor: res may be src (a temporary).
    nd_init_empty(&t);
    st = ndc_alloc_like(ctx, src, 0, perm, &t);
    if (st != OTI_OK){
        nd_init_empty(res);
        return st;
    }
    ndc_gather(src, perm, t.data);
    *res = t;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fills a new contiguous OTI_F64 array with one value.
static void ndc_fill(ndarr_t* a, double value){

    int64_t n = nd_size(a), i;
    double* p = (double*)a->data;

    for (i = 0; i < n; i++){
        p[i] = value;
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// --------------------------------------------    CREATORS    -------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_empty(oti_ctx* ctx, int32_t ndim, const int64_t* shape, int32_t layout, ndarr_t* res){

    int st = ndc_ctx(ctx, res, "nd_empty");

    if (st != OTI_OK){
        return st;
    }
    st = ndb_alloc_array(ctx, OTI_F64, ndim, shape, layout, 0, res);

    return st == OTI_OK ? st : ndc_fail(ctx, st, "nd_empty");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_empty_like(oti_ctx* ctx, const ndarr_t* src, int32_t alloc_flags, ndarr_t* res){

    int32_t perm[OTI_ND_MAXDIM];
    ndarr_t t;
    int st;

    if (src == NULL || res == NULL){
        if (res != NULL){
            NDB_ASSERT_RECV(res);
            nd_init_empty(res);
        }
        return ndc_fail(ctx, OTI_ERR_ARGUMENT, "nd_empty_like");
    }
    NDB_ASSERT_RECV(res);
    NDB_ASSERT_INPUT(src);
    st = ndc_ctx(ctx, res, "nd_empty_like");
    if (st != OTI_OK){
        return st;
    }
    nd_init_empty(&t);
    st = ndc_alloc_like(ctx, src, alloc_flags, perm, &t);
    if (st != OTI_OK){
        nd_init_empty(res);
        return ndc_fail(ctx, st, "nd_empty_like");
    }
    *res = t;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_zeros(oti_ctx* ctx, int32_t ndim, const int64_t* shape, int32_t layout, ndarr_t* res){

    int st = ndc_ctx(ctx, res, "nd_zeros");

    if (st != OTI_OK){
        return st;
    }
    st = ndb_alloc_array(ctx, OTI_F64, ndim, shape, layout, ND_ALLOC_ZERO, res);

    return st == OTI_OK ? st : ndc_fail(ctx, st, "nd_zeros");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_ones(oti_ctx* ctx, int32_t ndim, const int64_t* shape, int32_t layout, ndarr_t* res){

    int st = ndc_ctx(ctx, res, "nd_ones");

    if (st != OTI_OK){
        return st;
    }
    st = ndb_alloc_array(ctx, OTI_F64, ndim, shape, layout, 0, res);

    if (st != OTI_OK){
        return ndc_fail(ctx, st, "nd_ones");
    }
    ndc_fill(res, 1.0);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_full(oti_ctx* ctx, int32_t ndim, const int64_t* shape, double value, int32_t layout,
            ndarr_t* res){

    int st = ndc_ctx(ctx, res, "nd_full");

    if (st != OTI_OK){
        return st;
    }
    st = ndb_alloc_array(ctx, OTI_F64, ndim, shape, layout, 0, res);

    if (st != OTI_OK){
        return ndc_fail(ctx, st, "nd_full");
    }
    ndc_fill(res, value);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_eye(oti_ctx* ctx, int64_t n, int64_t m, int64_t k, int32_t layout, ndarr_t* res){

    int64_t shape[2], i, i0, i1;
    double* p;
    int st;

    if (res == NULL){
        return ndc_fail(ctx, OTI_ERR_ARGUMENT, "nd_eye");
    }
    st = ndc_ctx(ctx, res, "nd_eye");
    if (st != OTI_OK){
        return st;
    }
    if (n < 0 || m < 0){
        NDB_ASSERT_RECV(res);
        nd_init_empty(res);
        return ndc_fail(ctx, OTI_ERR_SHAPE, "nd_eye");
    }
    shape[0] = n;
    shape[1] = m;
    st = ndb_alloc_array(ctx, OTI_F64, 2, shape, layout, ND_ALLOC_ZERO, res);
    if (st != OTI_OK){
        return ndc_fail(ctx, st, "nd_eye");
    }
    // Ones at (i, i + k) for max(0, -k) <= i < min(n, m - k), without overflowing on extreme k.
    if (k >= m || k <= -n){
        return OTI_OK;
    }
    i0 = (k < 0) ? -k : 0;
    i1 = (m - k < n) ? m - k : n;
    p = (double*)res->data;
    for (i = i0; i < i1; i++){
        p[i * res->strides[0] + (i + k) * res->strides[1]] = 1.0;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_arange(oti_ctx* ctx, double start, double stop, double step, ndarr_t* res){

    double q, delta, *p;
    int64_t n, i;
    int st;

    if (res == NULL){
        return ndc_fail(ctx, OTI_ERR_ARGUMENT, "nd_arange");
    }
    st = ndc_ctx(ctx, res, "nd_arange");
    if (st != OTI_OK){
        return st;
    }
    NDB_ASSERT_RECV(res);
    nd_init_empty(res);
    if (step == 0.0 || !isfinite(start) || !isfinite(stop) || !isfinite(step)){
        return ndc_fail(ctx, OTI_ERR_ARGUMENT, "nd_arange");
    }
    // NumPy: length = ceil((stop - start) / step), at least 0.
    q = ceil((stop - start) / step);
    if (isnan(q)){
        return ndc_fail(ctx, OTI_ERR_ARGUMENT, "nd_arange");
    }
    if (q >= 9223372036854775808.0){
        return ndc_fail(ctx, OTI_ERR_SIZE, "nd_arange");
    }
    n = (q > 0.0) ? (int64_t)q : 0;
    st = ndb_alloc_array(ctx, OTI_F64, 1, &n, ND_LAYOUT_C, 0, res);
    if (st != OTI_OK){
        return ndc_fail(ctx, st, "nd_arange");
    }
    // NumPy's fill: y[0] = start, y[1] = start + step, then start + i * (y[1] - y[0]).
    p = (double*)res->data;
    if (n > 0){
        p[0] = start;
    }
    if (n > 1){
        p[1] = start + step;
        delta = p[1] - p[0];
        for (i = 2; i < n; i++){
            p[i] = start + (double)i * delta;
        }
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_linspace(oti_ctx* ctx, double start, double stop, int64_t num, int32_t endpoint, ndarr_t* res){

    double delta, step, *p;
    int64_t div, i;
    int st;

    if (res == NULL){
        return ndc_fail(ctx, OTI_ERR_ARGUMENT, "nd_linspace");
    }
    st = ndc_ctx(ctx, res, "nd_linspace");
    if (st != OTI_OK){
        return st;
    }
    if (num < 0){
        NDB_ASSERT_RECV(res);
        nd_init_empty(res);
        return ndc_fail(ctx, OTI_ERR_ARGUMENT, "nd_linspace");
    }
    st = ndb_alloc_array(ctx, OTI_F64, 1, &num, ND_LAYOUT_C, 0, res);
    if (st != OTI_OK){
        return ndc_fail(ctx, st, "nd_linspace");
    }
    p = (double*)res->data;
    div = endpoint ? num - 1 : num;
    delta = stop - start;
    if (div > 0){
        step = delta / (double)div;
        if (step == 0.0){
            for (i = 0; i < num; i++){
                p[i] = ((double)i / (double)div) * delta + start;
            }
        } else {
            for (i = 0; i < num; i++){
                p[i] = (double)i * step + start;
            }
        }
    } else {
        for (i = 0; i < num; i++){
            p[i] = (double)i * delta + start;
        }
    }
    if (endpoint && num > 1){
        p[num - 1] = stop;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ------------------------------------    COPIES AND CONVERSIONS    -------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_copy(oti_ctx* ctx, const ndarr_t* src, int32_t layout, ndarr_t* res){

    int st;

    if (src == NULL || res == NULL){
        if (res != NULL){
            nd_init_empty(res);
        }
        return ndc_fail(ctx, OTI_ERR_ARGUMENT, "nd_copy");
    }
    NDB_ASSERT_RECV(res);
    NDB_ASSERT_INPUT(src);
    st = ndc_ctx(ctx, res, "nd_copy");
    if (st != OTI_OK){
        return st;
    }
    st = ndc_copy(ctx, src, layout, res);

    return st == OTI_OK ? st : ndc_fail(ctx, st, "nd_copy");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// ascontiguous / asfortran: a retained view when src already has the layout and a control block,
// else a copy in that layout.
static int ndc_as_layout(oti_ctx* ctx, const ndarr_t* src, int32_t layout, ndarr_t* res,
                         int32_t* copied, const char* where){

    ndarr_t t;
    int st;

    if (copied != NULL){
        *copied = 0;
    }
    if (src == NULL || res == NULL){
        if (res != NULL){
            nd_init_empty(res);
        }
        return ndc_fail(ctx, OTI_ERR_ARGUMENT, where);
    }
    NDB_ASSERT_RECV(res);
    NDB_ASSERT_INPUT(src);
    st = ndc_ctx(ctx, res, where);
    if (st != OTI_OK){
        return st;
    }
    t = *src;
    nd_update_flags(&t);
    if (src->buf != NULL && (t.flags & (layout == ND_LAYOUT_C ? ND_C_CONTIG : ND_F_CONTIG))){
        st = ndb_view_retain(src, res);
    } else {
        st = ndc_copy_order(ctx, src, src->ndim, src->shape, layout, res);
        if (st == OTI_OK && copied != NULL){
            *copied = 1;
        }
    }

    return st == OTI_OK ? st : ndc_fail(ctx, st, where);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_ascontiguous(oti_ctx* ctx, const ndarr_t* src, ndarr_t* res, int32_t* copied){

    return ndc_as_layout(ctx, src, ND_LAYOUT_C, res, copied, "nd_ascontiguous");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_asfortran(oti_ctx* ctx, const ndarr_t* src, ndarr_t* res, int32_t* copied){

    return ndc_as_layout(ctx, src, ND_LAYOUT_F, res, copied, "nd_asfortran");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_reshape(oti_ctx* ctx, const ndarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
               ndarr_t* res, int32_t* copied){

    int64_t ns[OTI_ND_MAXDIM];
    int32_t order;
    ndarr_t v;
    int st;

    if (copied != NULL){
        *copied = 0;
    }
    if (src == NULL || res == NULL){
        if (res != NULL){
            nd_init_empty(res);
        }
        return ndc_fail(ctx, OTI_ERR_ARGUMENT, "nd_reshape");
    }
    NDB_ASSERT_RECV(res);
    NDB_ASSERT_INPUT(src);
    st = ndc_ctx(ctx, res, "nd_reshape");
    if (st != OTI_OK){
        return st;
    }
    nd_init_empty(&v);
    st = ndw_view_reshape(src, ndim, shape, layout, &v);
    if (st == OTI_OK && src->buf != NULL){
        st = ndb_view_retain(&v, res);
    } else if (st == OTI_OK || st == OTI_ERR_LAYOUT){
        // No view (or nothing to pin it to): copy in the index order of the reshape.
        order = ndw_reshape_order(src, layout);
        st = ndw_resolve_shape(nd_size(src), ndim, shape, ns);
        if (st == OTI_OK){
            st = ndc_copy_order(ctx, src, ndim, ns, order, res);
        }
        if (st == OTI_OK && copied != NULL){
            *copied = 1;
        }
    }
    if (st != OTI_OK){
        nd_init_empty(res);
        return ndc_fail(ctx, st, "nd_reshape");
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------
