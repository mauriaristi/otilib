// ndarray validation, contiguity flags, overlap tests, the PEP 3118 / DLPack format table, nd_import and
// the oti_view mapping (include/oti/real/ndarray/buffer.h, second half; PLAN-ndarray-contracts.md
// sections 2, 3.1, 3.2 and 6). Included from src/c/real_ndarray.c after buffer.c, whose helpers
// (oti_ckd_*, ndb_alloc_array, ndb_wrap, ndb_wrap_trusted) it uses. File-static prefix: ndv_.

#include <string.h>

// create.c (later in the unity): the K order and the K-layout allocator (S24), used by nd_import's
// converted copy (contracts 2.4 step 4).
static int ndc_alloc_like(oti_ctx* ctx, const ndarr_t* src, int32_t alloc_flags, int32_t* perm,
                          ndarr_t* res);


// *******************************************************************************************************
// 1 on a little-endian host.
static inline int ndv_host_le(void){

#if defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    return 0;
#else
    return 1;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Element offsets of the lowest and highest accessed elements, unchecked (well-formed, non-empty).
static inline void ndv_extent_raw(const ndarr_t* a, int64_t* lo, int64_t* hi){

    int64_t l = 0, h = 0;
    int32_t k;

    for (k = 0; k < a->ndim; k++){
        int64_t d = (a->shape[k] - 1) * a->strides[k];
        if (d < 0){
            l += d;
        } else {
            h += d;
        }
    }
    *lo = l;
    *hi = h;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 if some extent is 0.
static inline int ndv_is_empty(const ndarr_t* a){

    int32_t k;

    for (k = 0; k < a->ndim; k++){
        if (a->shape[k] == 0){
            return 1;
        }
    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_validate(const ndarr_t* a, const void* span_lo, const void* span_hi, int32_t vflags){

    int64_t isz, count = 1, lo = 0, hi = 0, lo_b, hi_b, t;
    int32_t k;
    int empty = 0;

    if (a == NULL){
        return OTI_ERR_ARGUMENT;
    }

    // 1. Rank and extents.
    if (a->ndim < 0 || a->ndim > OTI_ND_MAXDIM){
        return OTI_ERR_SHAPE;
    }
    for (k = 0; k < a->ndim; k++){
        if (a->shape[k] < 0){
            return OTI_ERR_SHAPE;
        }
        if (a->shape[k] == 0){
            empty = 1;
        }
    }

    // 2. dtype.
    isz = nd_itemsize(a->dtype);
    if (isz == 0){
        return OTI_ERR_DTYPE;
    }

    // 3. Flag bits.
    if ((a->flags & ~0x1F) != 0 || a->reserved != 0 ||
        ((a->flags & ND_EXPORTED) && !(a->flags & ND_RETAINED))){
        return OTI_ERR_ARGUMENT;
    }

    // 4. Checked arithmetic. The product of the NON-ZERO extents, and that product in bytes, must fit
    //    int64 also for an empty array (nd_size()'s precondition, NumPy's "array is too big" rule).
    //    Only a non-empty array accesses memory, so only it has extent offsets.
    for (k = 0; k < a->ndim; k++){
        if (a->shape[k] > 0 && oti_ckd_mul_i64(count, a->shape[k], &count)){
            return OTI_ERR_SIZE;
        }
    }
    if (oti_ckd_mul_i64(count, isz, &t)){
        return OTI_ERR_SIZE;
    }
    if (!empty){
        for (k = 0; k < a->ndim; k++){
            int64_t d;
            if (oti_ckd_mul_i64(a->shape[k] - 1, a->strides[k], &d)){
                return OTI_ERR_SIZE;
            }
            if (d < 0){
                if (oti_ckd_add_i64(lo, d, &lo)){
                    return OTI_ERR_SIZE;
                }
            } else if (oti_ckd_add_i64(hi, d, &hi)){
                return OTI_ERR_SIZE;
            }
        }
        if (oti_ckd_mul_i64(lo, isz, &lo_b) ||
            oti_ckd_add_i64(hi, 1, &hi_b) || oti_ckd_mul_i64(hi_b, isz, &hi_b)){
            return OTI_ERR_SIZE;
        }

        // 5. Data pointer, alignment and span.
        if (a->data == NULL){
            return OTI_ERR_ARGUMENT;
        }
        if ((uintptr_t)a->data % (uintptr_t)isz != 0){
            return OTI_ERR_LAYOUT;
        }
        if (vflags & ND_V_SPAN){
            uintptr_t d = (uintptr_t)a->data, first, last;
            uint64_t neg = (uint64_t)(-(lo_b + 1)) + 1u;   // -lo_b without overflow at INT64_MIN
            if (lo_b < 0 && neg > (uint64_t)d){
                return OTI_ERR_LAYOUT;
            }
            first = d - (uintptr_t)(lo_b < 0 ? neg : 0u);
            if ((uint64_t)hi_b > (uint64_t)(UINTPTR_MAX - d)){
                return OTI_ERR_LAYOUT;
            }
            last = d + (uintptr_t)hi_b;
            if (span_lo == NULL || span_hi == NULL || (uintptr_t)span_hi < (uintptr_t)span_lo ||
                first < (uintptr_t)span_lo || last > (uintptr_t)span_hi){
                return OTI_ERR_LAYOUT;
            }
        }
    }

    // 6. Output.
    if (vflags & ND_V_OUTPUT){
        if (!(a->flags & ND_WRITEABLE)){
            return OTI_ERR_READONLY;
        }
        if (!empty && nd_internal_overlap(a)){
            return OTI_ERR_LAYOUT;
        }
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void nd_update_flags(ndarr_t* a){

    int64_t expect;
    int32_t k, c = 1, f = 1;

    if (a == NULL){
        return;
    }
    a->flags &= ~(ND_C_CONTIG | ND_F_CONTIG);
    if (!ndv_is_empty(a)){
        expect = 1;
        for (k = a->ndim - 1; k >= 0; k--){
            if (a->shape[k] != 1){
                if (a->strides[k] != expect){
                    c = 0;
                    break;
                }
                expect *= a->shape[k];
            }
        }
        expect = 1;
        for (k = 0; k < a->ndim; k++){
            if (a->shape[k] != 1){
                if (a->strides[k] != expect){
                    f = 0;
                    break;
                }
                expect *= a->shape[k];
            }
        }
    }
    a->flags |= (c ? ND_C_CONTIG : 0) | (f ? ND_F_CONTIG : 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_extent(const ndarr_t* a, int64_t* lo, int64_t* hi){

    int64_t l, h;

    if (a == NULL || ndv_is_empty(a)){
        return a == NULL ? OTI_ERR_ARGUMENT : OTI_ERR_SHAPE;
    }
    ndv_extent_raw(a, &l, &h);
    if (lo != NULL){
        *lo = l;
    }
    if (hi != NULL){
        *hi = h;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_internal_overlap(const ndarr_t* a){

    int64_t ext[OTI_ND_MAXDIM], str[OTI_ND_MAXDIM], span = 0;
    int32_t k, j, n = 0;

    if (a == NULL || ndv_is_empty(a)){
        return 0;
    }
    for (k = 0; k < a->ndim; k++){
        if (a->shape[k] > 1){
            int64_t s = a->strides[k] < 0 ? -a->strides[k] : a->strides[k];
            if (s == 0){
                return 1;
            }
            // Insertion sort by |stride| ascending.
            for (j = n; j > 0 && str[j - 1] > s; j--){
                str[j] = str[j - 1];
                ext[j] = ext[j - 1];
            }
            str[j] = s;
            ext[j] = a->shape[k];
            n++;
        }
    }
    for (k = 0; k < n; k++){
        if (str[k] <= span){
            return 1;
        }
        span += (ext[k] - 1) * str[k];
    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_may_share_memory(const ndarr_t* a, const ndarr_t* b){

    int64_t alo, ahi, blo, bhi;
    uintptr_t a0, a1, b0, b1;
    int32_t k;

    if (a == NULL || b == NULL || ndv_is_empty(a) || ndv_is_empty(b)){
        return ND_SHARE_NONE;
    }
    ndv_extent_raw(a, &alo, &ahi);
    ndv_extent_raw(b, &blo, &bhi);
    a0 = (uintptr_t)a->data + (uintptr_t)(alo * nd_itemsize(a->dtype));
    a1 = (uintptr_t)a->data + (uintptr_t)((ahi + 1) * nd_itemsize(a->dtype));
    b0 = (uintptr_t)b->data + (uintptr_t)(blo * nd_itemsize(b->dtype));
    b1 = (uintptr_t)b->data + (uintptr_t)((bhi + 1) * nd_itemsize(b->dtype));
    if (a1 <= b0 || b1 <= a0){
        return ND_SHARE_NONE;
    }
    if (a->data != b->data || a->dtype != b->dtype || a->ndim != b->ndim){
        return ND_SHARE_MAYBE;
    }
    for (k = 0; k < a->ndim; k++){
        if (a->shape[k] != b->shape[k] || (a->shape[k] > 1 && a->strides[k] != b->strides[k])){
            return ND_SHARE_MAYBE;
        }
    }

    return ND_SHARE_EXACT;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -----------------------------------------    FORMAT TABLE    ------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fills an nd_srctype_t; checks the itemsize against the kind (bool 1; integers 1, 2, 4, 8; floats
// 4, 8). COMPLEX and OTHER take any itemsize.
static int ndv_srctype(int32_t kind, int64_t itemsize, int32_t swapped, nd_srctype_t* st){

    int ok;

    switch (kind){
    case ND_SRC_BOOL:
        ok = (itemsize == 1);
        break;
    case ND_SRC_INT:
    case ND_SRC_UINT:
        ok = (itemsize == 1 || itemsize == 2 || itemsize == 4 || itemsize == 8);
        break;
    case ND_SRC_FLOAT:
        ok = (itemsize == 4 || itemsize == 8);
        break;
    default:
        ok = (itemsize >= 0 && itemsize <= INT32_MAX);
        break;
    }
    if (!ok){
        return OTI_ERR_DTYPE;
    }
    st->kind = kind;
    st->itemsize = (int32_t)itemsize;
    st->swapped = swapped;
    st->reserved = 0;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_pep3118_classify(const char* format, int64_t itemsize, nd_srctype_t* st){

    const char* p = (format == NULL) ? "B" : format;
    int32_t swapped = 0, kind;
    char c;

    if (st == NULL){
        return OTI_ERR_ARGUMENT;
    }
    memset(st, 0, sizeof(*st));
    if (*p == '@' || *p == '=' || *p == '<' || *p == '>' || *p == '!'){
        int big = (*p == '>' || *p == '!');
        if (*p == '<' || big){
            swapped = (big == ndv_host_le());
        }
        p++;
    }
    c = *p++;
    switch (c){
    case '?':
        kind = ND_SRC_BOOL;
        break;
    case 'b': case 'h': case 'i': case 'l': case 'q': case 'n':
        kind = ND_SRC_INT;
        break;
    case 'B': case 'H': case 'I': case 'L': case 'Q': case 'N':
        kind = ND_SRC_UINT;
        break;
    case 'f': case 'd':
        kind = ND_SRC_FLOAT;
        break;
    case 'Z':
        c = *p++;
        if (c != 'f' && c != 'd' && c != 'g'){
            return OTI_ERR_DTYPE;
        }
        kind = ND_SRC_COMPLEX;
        break;
    case '\0':
        return OTI_ERR_DTYPE;
    default:
        // Repeat counts, structs and field names are not single types.
        if ((c >= '0' && c <= '9') || c == 'T' || c == '(' || c == ':' || c == '{' || c == '}' ||
            c == ' '){
            return OTI_ERR_DTYPE;
        }
        kind = ND_SRC_OTHER;
        break;
    }
    if (*p != '\0'){
        return OTI_ERR_DTYPE;
    }
    // 'f' and 'd' name their width in every PEP 3118 mode (native and standard): 4 and 8 bytes.
    if (kind == ND_SRC_FLOAT && itemsize != (c == 'f' ? 4 : 8)){
        return OTI_ERR_DTYPE;
    }

    return ndv_srctype(kind, itemsize, swapped, st);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_dlpack_classify(int32_t code, int32_t bits, int32_t lanes, nd_srctype_t* st){

    int32_t kind, isz;

    if (st == NULL){
        return OTI_ERR_ARGUMENT;
    }
    memset(st, 0, sizeof(*st));
    if (lanes != 1 || bits <= 0 || bits % 8 != 0){
        return OTI_ERR_DTYPE;
    }
    isz = bits / 8;
    switch (code){
    case OTI_DL_INT:
        kind = (isz == 1 || isz == 2 || isz == 4 || isz == 8) ? ND_SRC_INT : ND_SRC_OTHER;
        break;
    case OTI_DL_UINT:
        kind = (isz == 1 || isz == 2 || isz == 4 || isz == 8) ? ND_SRC_UINT : ND_SRC_OTHER;
        break;
    case OTI_DL_FLOAT:
        kind = (isz == 4 || isz == 8) ? ND_SRC_FLOAT : ND_SRC_OTHER;
        break;
    case OTI_DL_BOOL:
        kind = (isz == 1) ? ND_SRC_BOOL : ND_SRC_OTHER;
        break;
    case OTI_DL_COMPLEX:
        kind = ND_SRC_COMPLEX;
        break;
    default:
        return OTI_ERR_DTYPE;
    }

    return ndv_srctype(kind, isz, 0, st);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------------    IMPORT    ----------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Target dtype of an import (table 2.2), or a negative status; *exact = 1 for a zero-copy element type.
static int ndv_import_target(const nd_srctype_t* s, int32_t want, int32_t* exact){

    int32_t k = s->kind;
    int valid = (k == ND_SRC_BOOL && s->itemsize == 1) ||
                ((k == ND_SRC_INT || k == ND_SRC_UINT) &&
                 (s->itemsize == 1 || s->itemsize == 2 || s->itemsize == 4 || s->itemsize == 8)) ||
                (k == ND_SRC_FLOAT && (s->itemsize == 4 || s->itemsize == 8));
    int32_t t;

    *exact = 0;
    if (!valid){
        return OTI_ERR_DTYPE;
    }
    if (want == 0){
        t = (k == ND_SRC_BOOL) ? OTI_U8 : (k == ND_SRC_FLOAT) ? OTI_F64 : OTI_I64;
    } else {
        t = want;
    }
    if (t == OTI_U8 && k != ND_SRC_BOOL){
        return OTI_ERR_DTYPE;
    }
    if (t == OTI_I64 && k != ND_SRC_INT && k != ND_SRC_UINT){
        return OTI_ERR_DTYPE;
    }
    if (t == OTI_U8){
        *exact = 1;
    } else if (t == OTI_F64){
        *exact = (k == ND_SRC_FLOAT && s->itemsize == 8 && !s->swapped);
    } else {
        *exact = (k == ND_SRC_INT && s->itemsize == 8 && !s->swapped);
    }

    return t;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reads one foreign element (any alignment) into the widest type of its kind, swapping the bytes when
// needed. Floats go to *f, signed integers to *i, unsigned integers and bools to *u.
static inline void ndv_load(const unsigned char* p, const nd_srctype_t* s, double* f, int64_t* i,
                            uint64_t* u){

    unsigned char b[8];
    int32_t n = s->itemsize, k;

    if (s->swapped && n > 1){
        for (k = 0; k < n; k++){
            b[k] = p[n - 1 - k];
        }
    } else {
        memcpy(b, p, (size_t)n);
    }
    switch (s->kind){
    case ND_SRC_FLOAT:
        if (n == 4){
            float v;
            memcpy(&v, b, 4);
            *f = (double)v;
        } else {
            memcpy(f, b, 8);
        }
        break;
    case ND_SRC_INT:
        if (n == 1){ int8_t v; memcpy(&v, b, 1); *i = v; }
        else if (n == 2){ int16_t v; memcpy(&v, b, 2); *i = v; }
        else if (n == 4){ int32_t v; memcpy(&v, b, 4); *i = v; }
        else { memcpy(i, b, 8); }
        break;
    default:
        if (n == 1){ uint8_t v; memcpy(&v, b, 1); *u = v; }
        else if (n == 2){ uint16_t v; memcpy(&v, b, 2); *u = v; }
        else if (n == 4){ uint32_t v; memcpy(&v, b, 4); *u = v; }
        else { memcpy(u, b, 8); }
        break;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Converts the foreign elements into dst, the compact K-layout library array of the source (contracts
// 2.4 step 4, S24): the source is walked with axis perm[0] outermost and perm[ndim-1] innermost, which
// is dst's memory order, so dst is written sequentially and the source is read in its own memory order.
// Foreign addresses are computed on uintptr_t (contracts 2.3): the index carries with
// -(shape - 1) * stride, which nd_import() bounded with checked arithmetic (and the whole address
// interval was checked), and the walk stops at the last element, so no address outside the accessed
// span is ever formed.
static int ndv_convert(const nd_import_t* src, const int64_t* bstr, const int32_t* perm, ndarr_t* dst){

    int64_t idx[OTI_ND_MAXDIM], n = nd_size(dst), e;
    uintptr_t addr = (uintptr_t)src->data;
    int32_t nd = src->ndim, k, j;

    if (n == 0){
        return OTI_OK;
    }
    for (k = 0; k < nd; k++){
        idx[k] = 0;
    }
    for (e = 0; e < n; e++){
        double f = 0.0;
        int64_t i = 0;
        uint64_t u = 0;
        ndv_load((const unsigned char*)addr, &src->src, &f, &i, &u);
        if (dst->dtype == OTI_F64){
            double v = (src->src.kind == ND_SRC_FLOAT) ? f :
                       (src->src.kind == ND_SRC_INT) ? (double)i :
                       (src->src.kind == ND_SRC_BOOL) ? (u != 0 ? 1.0 : 0.0) : (double)u;
            ((double*)dst->data)[e] = v;
        } else if (dst->dtype == OTI_I64){
            if (src->src.kind == ND_SRC_UINT){
                if (u > (uint64_t)INT64_MAX){
                    return OTI_ERR_INDEX;
                }
                i = (int64_t)u;
            }
            ((int64_t*)dst->data)[e] = i;
        } else {
            ((uint8_t*)dst->data)[e] = (uint8_t)u;
        }
        if (e + 1 == n){
            break;
        }
        // Next index in perm order (modular uintptr_t arithmetic; every intermediate is in the span).
        for (j = nd - 1; j >= 0; j--){
            k = perm[j];
            if (idx[k] + 1 < src->shape[k]){
                idx[k]++;
                addr += (uintptr_t)bstr[k];
                break;
            }
            addr -= (uintptr_t)((src->shape[k] - 1) * bstr[k]);
            idx[k] = 0;
        }
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_import() without last-error recording.
static int ndv_import(oti_ctx* ctx, const nd_import_t* src, int32_t want, int32_t iflags,
                      nd_release_fn release, void* release_ctx, ndarr_t* res){

    int64_t bstr[OTI_ND_MAXDIM], isz, count = 1, lo = 0, hi = 0, t;
    int32_t k, target, exact = 0, aligned, empty = 0;
    ndarr_t desc;
    int st;

    if (res == NULL){
        st = OTI_ERR_ARGUMENT;
        goto fail;
    }
    NDB_ASSERT_RECV(res);
    nd_init_empty(res);
    if (src == NULL || (iflags & ~(ND_IMPORT_WRITEABLE | ND_IMPORT_COPY)) != 0 ||
        (iflags & ND_IMPORT_WRITEABLE && iflags & ND_IMPORT_COPY) ||
        (want != 0 && want != OTI_F64 && want != OTI_I64 && want != OTI_U8)){
        st = OTI_ERR_ARGUMENT;
        goto fail;
    }

    // 1. Device, rank, extents, byte extents (checked).
    if (src->device_type != OTI_DEVICE_CPU){
        st = OTI_ERR_ARGUMENT;
        goto fail;
    }
    if (src->ndim < 0 || src->ndim > OTI_ND_MAXDIM){
        st = OTI_ERR_SHAPE;
        goto fail;
    }
    if (src->ndim > 0 && src->shape == NULL){
        st = OTI_ERR_ARGUMENT;
        goto fail;
    }
    for (k = 0; k < src->ndim; k++){
        if (src->shape[k] < 0){
            st = OTI_ERR_SHAPE;
            goto fail;
        }
        if (src->shape[k] == 0){
            empty = 1;
        }
    }

    // 2. Target dtype.
    target = ndv_import_target(&src->src, want, &exact);
    if (target < 0){
        st = target;
        goto fail;
    }
    isz = src->src.itemsize;
    if (src->byte_strides != NULL){
        for (k = 0; k < src->ndim; k++){
            bstr[k] = src->byte_strides[k];
        }
    } else {
        int64_t s = isz;
        for (k = src->ndim - 1; k >= 0; k--){
            bstr[k] = s;
            if (src->shape[k] > 0 && oti_ckd_mul_i64(s, src->shape[k], &s)){
                st = OTI_ERR_SIZE;
                goto fail;
            }
        }
    }
    if (!empty){
        for (k = 0; k < src->ndim; k++){
            int64_t d;
            if (oti_ckd_mul_i64(count, src->shape[k], &count) ||
                oti_ckd_mul_i64(src->shape[k] - 1, bstr[k], &d) ||
                (d < 0 ? oti_ckd_add_i64(lo, d, &lo) : oti_ckd_add_i64(hi, d, &hi))){
                st = OTI_ERR_SIZE;
                goto fail;
            }
        }
        if (oti_ckd_mul_i64(count, 8, &t) || oti_ckd_add_i64(hi, isz, &t)){
            st = OTI_ERR_SIZE;
            goto fail;
        }
        if (src->data == NULL){
            st = OTI_ERR_ARGUMENT;
            goto fail;
        }
        // The whole foreign address interval [data + lo, data + hi + itemsize) must be representable
        // (contracts 2.3), so that ndv_convert()'s modular carries never wrap. Checked before any
        // allocation or load.
        {
            uintptr_t d = (uintptr_t)src->data;
            uint64_t below = (uint64_t)0 - (uint64_t)lo;      // -lo, lo <= 0
            if (below > (uint64_t)d || (uint64_t)(hi + isz) > (uint64_t)(UINTPTR_MAX - d)){
                st = OTI_ERR_LAYOUT;
                goto fail;
            }
        }
    }

    // 3. Zero-copy test: exact type, aligned data, strides multiples of the itemsize (axes of extent
    //    <= 1 and empty arrays never step, so their strides do not matter).
    aligned = empty || (uintptr_t)src->data % (uintptr_t)isz == 0;
    for (k = 0; k < src->ndim && aligned && !empty; k++){
        if (src->shape[k] > 1 && bstr[k] % isz != 0){
            aligned = 0;
        }
    }
    if (iflags & ND_IMPORT_WRITEABLE){
        if (!exact){
            st = OTI_ERR_DTYPE;
            goto fail;
        }
        if (src->readonly){
            st = OTI_ERR_READONLY;
            goto fail;
        }
        if (!aligned){
            st = OTI_ERR_LAYOUT;
            goto fail;
        }
    }
    if (exact && aligned && !(iflags & ND_IMPORT_COPY)){
        memset(&desc, 0, sizeof(desc));
        desc.data = empty ? NULL : src->data;
        desc.ndim = src->ndim;
        desc.dtype = target;
        for (k = 0; k < src->ndim; k++){
            desc.shape[k] = src->shape[k];
            desc.strides[k] = (bstr[k] % isz == 0) ? bstr[k] / isz : 0;
        }
        desc.flags = src->readonly ? 0 : ND_WRITEABLE;
        return ndb_wrap(&desc, NULL, -1, release, release_ctx, res);
    }

    // 4. Converted copy into a new library array in the K layout of the source (S24: C for a C
    //    source, F for an F source, the SoA block layout kept), ordered by the source's byte strides
    //    with the rule of nd_copy(ND_LAYOUT_K). Only shape, strides, ndim and dtype of the
    //    descriptor below are read.
    {
        int32_t perm[OTI_ND_MAXDIM];
        ndarr_t kd;
        kd.ndim = src->ndim;
        kd.dtype = target;
        for (k = 0; k < src->ndim; k++){
            kd.shape[k] = src->shape[k];
            kd.strides[k] = bstr[k];
        }
        st = ndc_alloc_like(ctx, &kd, 0, perm, res);
        if (st == OTI_OK){
            st = ndv_convert(src, bstr, perm, res);
            if (st != OTI_OK){
                nd_release(res);
            }
        }
    }

    // The conversion path, successful or not, and every failure end the foreign export here.
fail:
    if (release != NULL){
        release(release_ctx);
    }
    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_import(oti_ctx* ctx, const nd_import_t* src, int32_t want, int32_t iflags,
              nd_release_fn release, void* release_ctx, ndarr_t* res){

    int st = oti_ctx_check(ctx);

    if (st != OTI_OK){
        // The callback was handed over on entry: it runs exactly once, here.
        if (res != NULL){
            NDB_ASSERT_RECV(res);
            nd_init_empty(res);
        }
        if (release != NULL){
            release(release_ctx);
        }
    } else {
        st = ndv_import(ctx, src, want, iflags, release, release_ctx, res);
    }
    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_import", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------    VIEW MAPPING    -------------------------------------------
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_to_view(const ndarr_t* a, oti_view* v){

    oti_view w;
    size_t n;

    if (a == NULL || v == NULL || v->struct_size < (int32_t)offsetof(oti_view, reserved)){
        oti_ctx_set_error(NULL, OTI_ERR_ARGUMENT, "nd_to_view", NULL);
        return OTI_ERR_ARGUMENT;
    }
    NDB_ASSERT_INPUT(a);
    memset(&w, 0, sizeof(w));
    w.struct_size = v->struct_size;
    w.kind = OTI_KIND_REAL;
    w.dl.data = a->data;
    w.dl.device.device_type = OTI_DEVICE_CPU;
    w.dl.device.device_id = 0;
    w.dl.ndim = a->ndim;
    if (a->dtype == OTI_F64){
        w.dl.dtype.code = OTI_DL_FLOAT;
        w.dl.dtype.bits = 64;
    } else if (a->dtype == OTI_U8){
        w.dl.dtype.code = OTI_DL_BOOL;
        w.dl.dtype.bits = 8;
    } else {
        w.dl.dtype.code = OTI_DL_INT;
        w.dl.dtype.bits = 64;
    }
    w.dl.dtype.lanes = 1;
    w.dl.shape = (int64_t*)a->shape;
    w.dl.strides = (int64_t*)a->strides;
    w.dl.byte_offset = 0;
    w.flags = (a->flags & ND_WRITEABLE) ? 0 : OTI_VIEW_READONLY;
    n = (size_t)v->struct_size < sizeof(w) ? (size_t)v->struct_size : sizeof(w);
    memcpy(v, &w, n);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_from_view() without last-error recording.
static int ndv_from_view(const oti_view* v, int32_t vflags, ndarr_t* out){

    const oti_dldtype_t* t;
    uintptr_t d;
    int32_t dtype;
    int st;

    if (out == NULL){
        return OTI_ERR_ARGUMENT;
    }
    NDB_ASSERT_RECV(out);
    nd_init_empty(out);
    if (v == NULL || v->struct_size < (int32_t)offsetof(oti_view, reserved) ||
        (vflags & ~ND_V_OUTPUT) != 0 || v->kind != OTI_KIND_REAL ||
        v->dl.device.device_type != OTI_DEVICE_CPU || v->dl.device.device_id != 0){
        return OTI_ERR_ARGUMENT;
    }
    if (v->dl.ndim < 0 || v->dl.ndim > OTI_ND_MAXDIM){
        return OTI_ERR_SHAPE;
    }
    t = &v->dl.dtype;
    if (t->lanes == 1 && t->code == OTI_DL_FLOAT && t->bits == 64){
        dtype = OTI_F64;
    } else if (t->lanes == 1 && t->code == OTI_DL_BOOL && t->bits == 8){
        dtype = OTI_U8;
    } else if (t->lanes == 1 && t->code == OTI_DL_INT && t->bits == 64){
        dtype = OTI_I64;
    } else {
        return OTI_ERR_DTYPE;
    }
    d = (uintptr_t)v->dl.data;
    if (v->dl.byte_offset > (uint64_t)(UINTPTR_MAX - d)){
        return OTI_ERR_LAYOUT;
    }
    d += (uintptr_t)v->dl.byte_offset;
    st = ndb_wrap_trusted((void*)d, dtype, v->dl.ndim, v->dl.shape, v->dl.strides,
                          !(v->flags & OTI_VIEW_READONLY), out);
    if (st == OTI_OK && (vflags & ND_V_OUTPUT)){
        st = nd_validate(out, NULL, NULL, ND_V_OUTPUT);
        if (st != OTI_OK){
            nd_init_empty(out);
        }
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_from_view(const oti_view* v, int32_t vflags, ndarr_t* out){

    int st = ndv_from_view(v, vflags, out);

    if (st != OTI_OK){
        oti_ctx_set_error(NULL, st, "nd_from_view", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------
