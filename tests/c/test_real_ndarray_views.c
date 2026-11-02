/* Tests of the ndarray views (include/oti/real/ndarray/views.h, Phase 1): nd_slice_normalize,
 * nd_normalize_axis, nd_broadcast_shapes, nd_view_index, nd_view_transpose, nd_view_swapaxes,
 * nd_view_squeeze, nd_view_expand_dims, nd_view_broadcast_to, nd_view_diagonal, nd_view_reshape, and the
 * ownership and read-only rules of views (contracts 1.4, 3.3, decision S1). Advanced indexing
 * (nd_index_get / nd_index_set) is Phase 5 and not tested here.
 *
 * Written from PLAN-ndarray-contracts.md (test matrix: view functions, 3.3 read-only), independently of
 * src/c/real/ndarray/views.c. Source arrays are filled so that element (i0, ..., ik) holds the C-order
 * linear index of its coordinates, whatever the memory layout: a view's element at a result coordinate
 * is then identified by value. The oracle is a reference evaluator written in this file (slice
 * normalization as Python's slice.indices, index tuples mapped axis by axis, reshape by enumerating
 * logical coordinates in the requested order), compared against random index tuples, plus
 * hand-derived tables for the helpers. Contiguity flags are compared with NumPy 2's rule implemented
 * here independently of nd_update_flags. */
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L   // contracts S23
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/core/exec.h>
#include <oti/real/ndarray/structures.h>
#include <oti/real/ndarray/buffer.h>
#include <oti/real/ndarray/create.h>
#include <oti/real/ndarray/views.h>

static int n_failed = 0;
static uint64_t g_rng_state;


// *******************************************************************************************************
static void check(int cond, const char* name){

    if (!cond){
        fprintf(stderr, "FAILED: %s\n", name);
        n_failed++;
    } else {
        printf("passed: %s\n", name);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void rng_seed(uint64_t seed){

    g_rng_state = (seed != 0) ? seed : 0x9E3779B97F4A7C15ULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static uint64_t rng_next(void){

    uint64_t x = g_rng_state;

    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    g_rng_state = x;

    return x;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int64_t rng_int(int64_t n){

    return (int64_t)(rng_next() % (uint64_t)n);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Allocates an F64 array of the given shape and layout holding the C-order linear index of each
// coordinate.
static void make_iota(int32_t ndim, const int64_t* shape, int32_t layout, ndarr_t* a){

    int st = nd_alloc(NULL, OTI_F64, ndim, shape, layout, 0, a);
    int64_t n = 1, lin;
    int32_t k;

    if (st != OTI_OK){
        fprintf(stderr, "make_iota: nd_alloc failed (%d)\n", st);
        exit(2);
    }
    for (k = 0; k < ndim; k++){
        n *= shape[k];
    }
    for (lin = 0; lin < n; lin++){
        int64_t rem = lin, off = 0;
        for (k = ndim - 1; k >= 0; k--){
            off += (rem % shape[k]) * a->strides[k];
            rem /= shape[k];
        }
        ((double*)a->data)[off] = (double)lin;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void make_desc(ndarr_t* a, void* data, int32_t dtype, int32_t ndim, const int64_t* shape,
                      const int64_t* strides, int32_t flags){

    int32_t k;

    memset(a, 0, sizeof(*a));
    a->data = data;
    a->dtype = dtype;
    a->ndim = ndim;
    a->flags = flags;
    for (k = 0; k < ndim; k++){
        a->shape[k] = shape[k];
        a->strides[k] = strides[k];
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int64_t shape_size(int32_t nd, const int64_t* shape){

    int64_t n = 1;
    int32_t k;

    for (k = 0; k < nd; k++){
        n *= shape[k];
    }
    return n;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// NumPy 2's contiguity rule, independent of nd_update_flags: axes of extent 1 are ignored, an array
// with at most one element is both. Returns the C bit and the F bit.
static int ref_flags(const ndarr_t* a){

    int64_t expect;
    int32_t k;
    int c = 1, f = 1;

    if (shape_size(a->ndim, a->shape) <= 1){
        return ND_C_CONTIG | ND_F_CONTIG;
    }
    expect = 1;
    for (k = a->ndim - 1; k >= 0; k--){
        if (a->shape[k] != 1){
            if (a->strides[k] != expect){
                c = 0;
            }
            expect *= a->shape[k];
        }
    }
    expect = 1;
    for (k = 0; k < a->ndim; k++){
        if (a->shape[k] != 1){
            if (a->strides[k] != expect){
                f = 0;
            }
            expect *= a->shape[k];
        }
    }
    return (c ? ND_C_CONTIG : 0) | (f ? ND_F_CONTIG : 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int flags_match(const ndarr_t* a){

    return (a->flags & (ND_C_CONTIG | ND_F_CONTIG)) == ref_flags(a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A temporary derived from a retained or temporary source: ND_RETAINED and ND_EXPORTED clear, same buf.
static int is_borrowing_temp(const ndarr_t* v, const ndarr_t* src){

    return !(v->flags & (ND_RETAINED | ND_EXPORTED)) && v->buf == src->buf && v->dtype == src->dtype;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Odometer over a shape: advances idx, returns 0 when done.
static int next_coord(int32_t nd, const int64_t* shape, int64_t* idx){

    int32_t k;

    for (k = nd - 1; k >= 0; k--){
        if (++idx[k] < shape[k]){
            return 1;
        }
        idx[k] = 0;
    }
    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double* at(const ndarr_t* a, const int64_t* idx){

    int64_t off = 0;
    int32_t k;

    for (k = 0; k < a->ndim; k++){
        off += idx[k] * a->strides[k];
    }
    return (double*)a->data + off;

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Helpers: slice normalization, axes, broadcast shapes
// =======================================================================================================

// *******************************************************************************************************
static nd_index_t mk_slice(int has, int64_t start, int64_t stop, int64_t step){

    nd_index_t s;

    memset(&s, 0, sizeof(s));
    s.kind = ND_IDX_SLICE;
    s.has = has;
    s.start = start;
    s.stop = stop;
    s.step = step;
    return s;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static nd_index_t mk_int(int64_t i){

    nd_index_t s;

    memset(&s, 0, sizeof(s));
    s.kind = ND_IDX_INT;
    s.start = i;
    return s;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static nd_index_t mk_kind(int kind){

    nd_index_t s;

    memset(&s, 0, sizeof(s));
    s.kind = kind;
    return s;

}
// -------------------------------------------------------------------------------------------------------


#define HS 0x1
#define HP 0x2
#define HT 0x4

// *******************************************************************************************************
// Python's slice.indices(n) by definition (PySlice_AdjustIndices), written here for the oracle.
static void ref_slice(int64_t n, int has, int64_t start, int64_t stop, int64_t step, int64_t* o_start,
                      int64_t* o_step, int64_t* o_len){

    int64_t lo, hi, s, e;

    if (!(has & HT)){
        step = 1;
    }
    if (step > 0){
        lo = 0;
        hi = n;
    } else {
        lo = -1;
        hi = n - 1;
    }
    if (!(has & HS)){
        s = (step < 0) ? hi : lo;
    } else {
        s = start;
        if (s < 0){
            s += n;
            if (s < lo){
                s = lo;
            }
        } else if (s > hi){
            s = hi;
        }
    }
    if (!(has & HP)){
        e = (step < 0) ? lo : hi;
    } else {
        e = stop;
        if (e < 0){
            e += n;
            if (e < lo){
                e = lo;
            }
        } else if (e > hi){
            e = hi;
        }
    }
    *o_start = s;
    *o_step = step;
    if (step < 0){
        *o_len = (e < s) ? (s - e - 1) / (-step) + 1 : 0;
    } else {
        *o_len = (s < e) ? (e - s - 1) / step + 1 : 0;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_slice_normalize(void){

    static const struct {
        int64_t n;
        int has;
        int64_t start, stop, step;
        int64_t e_start, e_step, e_len;
        const char* name;
    } T[] = {
        {10, 0, 0, 0, 0,                0, 1, 10, "[:]"},
        {10, HS | HP, 2, 5, 0,          2, 1, 3, "[2:5]"},
        {10, HS, -3, 0, 0,              7, 1, 3, "[-3:]"},
        {10, HP, 0, -3, 0,              0, 1, 7, "[:-3]"},
        {10, HT, 0, 0, 2,               0, 2, 5, "[::2]"},
        {10, HS | HT, 1, 0, 3,          1, 3, 3, "[1::3]"},
        {10, HT, 0, 0, -1,              9, -1, 10, "[::-1]"},
        {10, HS | HP | HT, 5, 2, -1,    5, -1, 3, "[5:2:-1]"},
        {10, HS | HP | HT, -1, -4, -1,  9, -1, 3, "[-1:-4:-1]"},
        {10, HS, 20, 0, 0,              10, 1, 0, "[20:]"},
        {10, HS, -20, 0, 0,             0, 1, 10, "[-20:]"},
        {10, HP, 0, 20, 0,              0, 1, 10, "[:20]"},
        {10, HS | HP, 2, 2, 0,          2, 1, 0, "[2:2]"},
        {10, HS | HP, 8, 2, 0,          8, 1, 0, "[8:2]"},
        {10, HS | HP | HT, 2, 8, -1,    2, -1, 0, "[2:8:-1]"},
        {10, HT, 0, 0, -3,              9, -3, 4, "[::-3]"},
        {10, HS | HT, 100, 0, -1,       9, -1, 10, "[100::-1]"},
        {10, HS | HT, -100, 0, -1,      -1, -1, 0, "[-100::-1]"},
        {10, HT, 0, 0, 100,             0, 100, 1, "[::100]"},
        {10, HS | HP | HT, 1, 9, 4,     1, 4, 2, "[1:9:4]"},
        {1, HT, 0, 0, -1,               0, -1, 1, "n=1 [::-1]"},
        {0, 0, 0, 0, 0,                 0, 1, 0, "n=0 [:]"},
        {0, HS | HP, 3, 9, 0,           0, 1, 0, "n=0 [3:9]"},
        {0, HT, 0, 0, -1,               -1, -1, 0, "n=0 [::-1]"}
    };
    int i, ok = 1;

    for (i = 0; i < (int)(sizeof(T) / sizeof(T[0])); i++){
        nd_index_t s = mk_slice(T[i].has, T[i].start, T[i].stop, T[i].step);
        int64_t st = -999, sp = -999, ln = -999;
        int r = nd_slice_normalize(T[i].n, &s, &st, &sp, &ln);
        int64_t r_st, r_sp, r_ln;

        ref_slice(T[i].n, T[i].has, T[i].start, T[i].stop, T[i].step, &r_st, &r_sp, &r_ln);
        if (r_ln != T[i].e_len || r_sp != T[i].e_step){
            fprintf(stderr, "  oracle disagrees with the table at %s\n", T[i].name);
            ok = 0;
        }
        if (r != OTI_OK || sp != T[i].e_step || ln != T[i].e_len || (ln > 0 && st != T[i].e_start)){
            fprintf(stderr,
                    "  slice %s n=%lld: status %d start %lld step %lld len %lld; want %lld %lld %lld\n",
                    T[i].name, (long long)T[i].n, r, (long long)st, (long long)sp, (long long)ln,
                    (long long)T[i].e_start, (long long)T[i].e_step, (long long)T[i].e_len);
            ok = 0;
        }
    }
    check(ok, "nd_slice_normalize: 24 hand-derived slices (Python slice.indices)");

    {
        nd_index_t s = mk_slice(HT, 0, 0, 0);
        int64_t st, sp, ln;
        check(nd_slice_normalize(10, &s, &st, &sp, &ln) == OTI_ERR_ARGUMENT,
                "nd_slice_normalize: step 0 -> ARGUMENT");
    }

    // randomized against the reference
    {
        int it, okr = 1;
        rng_seed(99);
        for (it = 0; it < 20000; it++){
            int64_t n = rng_int(12);
            int has = (int)rng_int(8);
            int64_t start = rng_int(40) - 20, stop = rng_int(40) - 20, step = rng_int(11) - 5;
            nd_index_t s;
            int64_t st = 0, sp = 0, ln = 0, r_st, r_sp, r_ln;
            int r;
            if ((has & HT) && step == 0){
                step = 1;
            }
            s = mk_slice(has, start, stop, step);
            r = nd_slice_normalize(n, &s, &st, &sp, &ln);
            ref_slice(n, has, start, stop, step, &r_st, &r_sp, &r_ln);
            if (r != OTI_OK || sp != r_sp || ln != r_ln || (ln > 0 && st != r_st)){
                okr = 0;
            }
        }
        check(okr, "nd_slice_normalize: 20000 random slices agree with the reference");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_normalize_axis(void){

    int32_t r = -99;

    check(nd_normalize_axis(0, 3, &r) == OTI_OK && r == 0, "normalize_axis(0, 3) = 0");
    check(nd_normalize_axis(2, 3, &r) == OTI_OK && r == 2, "normalize_axis(2, 3) = 2");
    check(nd_normalize_axis(-1, 3, &r) == OTI_OK && r == 2, "normalize_axis(-1, 3) = 2");
    check(nd_normalize_axis(-3, 3, &r) == OTI_OK && r == 0, "normalize_axis(-3, 3) = 0");
    check(nd_normalize_axis(3, 3, &r) == OTI_ERR_INDEX, "normalize_axis(3, 3) -> INDEX");
    check(nd_normalize_axis(-4, 3, &r) == OTI_ERR_INDEX, "normalize_axis(-4, 3) -> INDEX");
    check(nd_normalize_axis(0, 0, &r) == OTI_ERR_INDEX, "normalize_axis on rank 0 -> INDEX");


}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Re-derived from NumPy: shapes (5) and (4,1) broadcast to (4,5); (3,4,1) and (5) to (3,4,5);
// (5) and (4) fail; a zero extent against 1 gives 0, against 5 fails; rank 0 broadcasts with anything.
static int bshape(int na, const int64_t* sa, int nb, const int64_t* sb, int32_t* nd, int64_t* shape){

    double mem[1] = {0};
    int64_t stz[OTI_ND_MAXDIM] = {0};
    ndarr_t a = {0}, b = {0};
    const ndarr_t* ops[2];

    make_desc(&a, mem, OTI_F64, na, sa, stz, 0);
    make_desc(&b, mem, OTI_F64, nb, sb, stz, 0);
    ops[0] = &a;
    ops[1] = &b;
    return nd_broadcast_shapes(2, ops, nd, shape);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_broadcast_shapes_table(void){

    int32_t nd;
    int64_t shape[OTI_ND_MAXDIM];
    int64_t a5[1] = {5}, a41[2] = {4, 1}, a341[3] = {3, 4, 1}, a4[1] = {4}, a03[2] = {0, 3}, a13[2] = {1,
            3};
    int64_t a1[1] = {1}, a0[1] = {0}, a05[1] = {5};

    check(bshape(1, a5, 2, a41, &nd, shape) == OTI_OK && nd == 2 && shape[0] == 4 && shape[1] == 5,
          "broadcast_shapes: (5) with (4,1) -> (4,5)");
    check(bshape(3, a341, 1, a5, &nd, shape) == OTI_OK && nd == 3 && shape[0] == 3 && shape[1] == 4 &&
          shape[2] == 5, "broadcast_shapes: (3,4,1) with (5) -> (3,4,5)");
    check(bshape(1, a5, 1, a4, &nd, shape) == OTI_ERR_SHAPE, "broadcast_shapes: (5) with (4) -> SHAPE");
    check(bshape(2, a03, 2, a13, &nd, shape) == OTI_OK && nd == 2 && shape[0] == 0 && shape[1] == 3,
          "broadcast_shapes: (0,3) with (1,3) -> (0,3)");
    check(bshape(1, a0, 1, a1, &nd, shape) == OTI_OK && nd == 1 && shape[0] == 0,
            "broadcast_shapes: (0) with (1) -> (0)");
    check(bshape(1, a0, 1, a05, &nd, shape) == OTI_ERR_SHAPE, "broadcast_shapes: (0) with (5) -> SHAPE");
    check(bshape(0, NULL, 1, a5, &nd, shape) == OTI_OK && nd == 1 && shape[0] == 5,
          "broadcast_shapes: rank 0 with (5) -> (5)");
    check(bshape(0, NULL, 0, NULL, &nd, shape) == OTI_OK && nd == 0,
            "broadcast_shapes: rank 0 with rank 0");

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// nd_view_index against the reference evaluator
// =======================================================================================================

typedef struct {
    int32_t src_axis;    // -1 for a new axis
    int64_t start, step, len;
} rax_t;


// *******************************************************************************************************
// Reference evaluator of a basic index tuple over a source of shape dims[]. Result axes in order;
// fixed[k] is the coordinate of an integer-indexed source axis. Returns 0 on success, or the expected
// status (INDEX / ARGUMENT).
static int ref_index(int32_t nd, const int64_t* dims, int32_t nidx, const nd_index_t* idx, int32_t* rnd,
                     rax_t* ax, int64_t* fixed, int32_t* is_fixed){

    int32_t i, used = 0, ell = -1, src = 0, r = 0;
    int32_t k;

    for (i = 0; i < nidx; i++){
        if (idx[i].kind == ND_IDX_ARRAY){
            return OTI_ERR_ARGUMENT;
        }
        if (idx[i].kind == ND_IDX_ELLIPSIS){
            if (ell >= 0){
                return OTI_ERR_INDEX;
            }
            ell = i;
        } else if (idx[i].kind != ND_IDX_NEWAXIS){
            used++;
        }
    }
    if (used > nd){
        return OTI_ERR_INDEX;
    }
    for (k = 0; k < nd; k++){
        is_fixed[k] = 0;
        fixed[k] = 0;
    }
    for (i = 0; i < nidx; i++){
        if (idx[i].kind == ND_IDX_ELLIPSIS){
            int32_t fill = nd - used;
            while (fill-- > 0){
                ax[r].src_axis = src; ax[r].start = 0; ax[r].step = 1; ax[r].len = dims[src];
                r++; src++;
            }
        } else if (idx[i].kind == ND_IDX_NEWAXIS){
            ax[r].src_axis = -1; ax[r].start = 0; ax[r].step = 1; ax[r].len = 1;
            r++;
        } else if (idx[i].kind == ND_IDX_INT){
            int64_t v = idx[i].start;
            if (v < -dims[src] || v >= dims[src]){
                return OTI_ERR_INDEX;
            }
            if (v < 0){
                v += dims[src];
            }
            fixed[src] = v;
            is_fixed[src] = 1;
            src++;
        } else {
            int64_t s, st, ln;
            ref_slice(dims[src], idx[i].has, idx[i].start, idx[i].stop, idx[i].step, &s, &st, &ln);
            ax[r].src_axis = src; ax[r].start = s; ax[r].step = st; ax[r].len = ln;
            r++; src++;
        }
    }
    if (ell < 0){
        while (src < nd){
            ax[r].src_axis = src; ax[r].start = 0; ax[r].step = 1; ax[r].len = dims[src];
            r++; src++;
        }
    }
    *rnd = r;
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks the values of a view against the reference mapping: for every result coordinate the element
// holds the C-order linear index of the mapped source coordinates.
static int check_index_view(const ndarr_t* v, int32_t nd, const int64_t* dims, int32_t rnd,
        const rax_t* ax,
                            const int64_t* fixed, const int32_t* is_fixed){

    int64_t lstride[OTI_ND_MAXDIM];
    int64_t idx[OTI_ND_MAXDIM];
    int32_t k;
    int64_t total;

    if (v->ndim != rnd){
        return 0;
    }
    for (k = 0; k < rnd; k++){
        if (v->shape[k] != ax[k].len){
            return 0;
        }
    }
    lstride[nd - 1 >= 0 ? nd - 1 : 0] = 1;
    for (k = nd - 2; k >= 0; k--){
        lstride[k] = lstride[k + 1] * dims[k + 1];
    }
    total = shape_size(rnd, v->shape);
    if (total == 0){
        return 1;
    }
    memset(idx, 0, sizeof(idx));
    do {
        int64_t expect = 0;
        int32_t j;
        for (j = 0; j < nd; j++){
            if (is_fixed[j]){
                expect += fixed[j] * lstride[j];
            }
        }
        for (j = 0; j < rnd; j++){
            if (ax[j].src_axis >= 0){
                expect += (ax[j].start + idx[j] * ax[j].step) * lstride[ax[j].src_axis];
            }
        }
        if (*at(v, idx) != (double)expect){
            return 0;
        }
    } while (next_coord(rnd, v->shape, idx));
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_view_index_hand(void){

    ndarr_t a = {0}, v = {0};
    int64_t shape[3] = {3, 4, 5};
    nd_index_t idx[4];

    make_iota(3, shape, ND_LAYOUT_C, &a);

    // a[1] -> (4, 5), strides (5, 1), offset 20
    idx[0] = mk_int(1);
    check(nd_view_index(&a, 1, idx, &v) == OTI_OK, "a[1]: OK");
    check(v.ndim == 2 && v.shape[0] == 4 && v.shape[1] == 5 && v.strides[0] == 5 && v.strides[1] == 1 &&
          v.data == (double*)a.data + 20, "a[1]: shape (4,5), strides (5,1), offset 20");
    check(is_borrowing_temp(&v, &a) && (v.flags & ND_WRITEABLE) && (v.flags & ND_C_CONTIG),
          "a[1]: temporary borrowing the buffer, writeable, C contiguous");
    check(nd_buffer_refs(a.buf) == 1, "a[1]: no reference taken");

    // a[:, 2]  -> (3, 5), strides (20, 1), offset 10
    idx[0] = mk_slice(0, 0, 0, 0);
    idx[1] = mk_int(2);
    check(nd_view_index(&a, 2, idx, &v) == OTI_OK && v.ndim == 2 && v.shape[0] == 3 && v.shape[1] == 5 &&
          v.strides[0] == 20 && v.strides[1] == 1 && v.data == (double*)a.data + 10 &&
                  !(v.flags & ND_C_CONTIG),
          "a[:, 2]: shape (3,5), strides (20,1), offset 10, not contiguous");

    // a[..., 0] -> (3, 4), strides (20, 5)
    idx[0] = mk_kind(ND_IDX_ELLIPSIS);
    idx[1] = mk_int(0);
    check(nd_view_index(&a, 2, idx, &v) == OTI_OK && v.ndim == 2 && v.strides[0] == 20 &&
            v.strides[1] == 5 &&
          v.shape[0] == 3 && v.shape[1] == 4 && v.data == a.data, "a[..., 0]: (3,4) strides (20,5)");

    // a[None] -> (1, 3, 4, 5)
    idx[0] = mk_kind(ND_IDX_NEWAXIS);
    check(nd_view_index(&a, 1, idx, &v) == OTI_OK && v.ndim == 4 && v.shape[0] == 1 && v.shape[1] == 3 &&
          v.shape[3] == 5 && (v.flags & ND_C_CONTIG), "a[None]: (1,3,4,5)");

    // a[::-1, 1:3, ::2] -> (3, 2, 3), strides (-20, 5, 2), offset 2*20 + 5
    idx[0] = mk_slice(HT, 0, 0, -1);
    idx[1] = mk_slice(HS | HP, 1, 3, 0);
    idx[2] = mk_slice(HT, 0, 0, 2);
    check(nd_view_index(&a, 3, idx, &v) == OTI_OK && v.shape[0] == 3 && v.shape[1] == 2 &&
            v.shape[2] == 3 &&
          v.strides[0] == -20 && v.strides[1] == 5 && v.strides[2] == 2 && v.data == (double*)a.data + 45,
          "a[::-1, 1:3, ::2]: shape (3,2,3), strides (-20,5,2), offset 45");

    // a with no items is the whole array (a new temporary)
    check(nd_view_index(&a, 0, NULL, &v) == OTI_OK && v.ndim == 3 && v.data == a.data &&
            is_borrowing_temp(&v, &a),
          "a[()]: the whole array as a temporary");

    // all integers -> rank 0
    idx[0] = mk_int(2);
    idx[1] = mk_int(-1);
    idx[2] = mk_int(3);
    check(nd_view_index(&a, 3, idx, &v) == OTI_OK && v.ndim == 0 &&
            *(double*)v.data == (double)(2 * 20 + 3 * 5 + 3),
          "a[2, -1, 3]: rank 0 holding the element");
    check((v.flags & ND_C_CONTIG) && (v.flags & ND_F_CONTIG), "rank-0 view: C and F contiguous");

    // errors
    idx[0] = mk_int(3);
    check(nd_view_index(&a, 1, idx, &v) == OTI_ERR_INDEX, "a[3] on extent 3 -> INDEX");
    idx[0] = mk_int(-4);
    check(nd_view_index(&a, 1, idx, &v) == OTI_ERR_INDEX, "a[-4] on extent 3 -> INDEX");
    idx[0] = mk_int(0); idx[1] = mk_int(0); idx[2] = mk_int(0); idx[3] = mk_int(0);
    check(nd_view_index(&a, 4, idx, &v) == OTI_ERR_INDEX, "four integers on a 3-D array -> INDEX");
    idx[0] = mk_kind(ND_IDX_ELLIPSIS); idx[1] = mk_kind(ND_IDX_ELLIPSIS);
    check(nd_view_index(&a, 2, idx, &v) == OTI_ERR_INDEX, "two ellipses -> INDEX");
    idx[0] = mk_slice(HT, 0, 0, 0);
    check(nd_view_index(&a, 1, idx, &v) == OTI_ERR_ARGUMENT, "slice with step 0 -> ARGUMENT");
    idx[0] = mk_kind(ND_IDX_ARRAY);
    check(nd_view_index(&a, 1, idx, &v) == OTI_ERR_ARGUMENT, "ND_IDX_ARRAY in a basic index -> ARGUMENT");
    {
        // a[None, None, ...]: rank grows beyond 32 -> SHAPE
        ndarr_t big = {0};
        int64_t sh32[32];
        nd_index_t items[2];
        int i;
        for (i = 0; i < 32; i++){
            sh32[i] = 1;
        }
        make_iota(32, sh32, ND_LAYOUT_C, &big);
        items[0] = mk_kind(ND_IDX_NEWAXIS);
        check(nd_view_index(&big, 1, items, &v) == OTI_ERR_SHAPE, "newaxis on a rank-32 array -> SHAPE");
        items[0] = mk_int(0);
        check(nd_view_index(&big, 1, items, &v) == OTI_OK && v.ndim == 31,
                "an integer on a rank-32 array -> rank 31");
        nd_release(&big);
    }

    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_view_index_random(void){

    int iter, ok = 1, ok_flags = 1, ok_own = 1, nfail = 0;
    int ok_err = 1;

    rng_seed(31337);

    for (iter = 0; iter < 6000; iter++){

        int32_t nd = 1 + (int32_t)rng_int(4);
        int64_t dims[4];
        int32_t layout = (rng_int(2) == 0) ? ND_LAYOUT_C : ND_LAYOUT_F;
        ndarr_t a = {0}, v = {0};
        nd_index_t idx[8];
        int32_t nidx = (int32_t)rng_int(7), i, k;
        int has_ell = 0;
        int32_t rnd = 0;
        rax_t ax[OTI_ND_MAXDIM];
        int64_t fixed[4];
        int32_t is_fixed[4];
        int expect;
        int st;

        for (k = 0; k < nd; k++){
            dims[k] = (rng_int(12) == 0) ? 0 : 1 + rng_int(5);
        }
        for (i = 0; i < nidx; i++){
            int t = (int)rng_int(10);
            if (t < 3){
                // integer, mostly in range, sometimes out of range
                int64_t n = (k = (int32_t)rng_int(nd), dims[k]);
                idx[i] = mk_int(rng_int(n + 4) - (n + 2));
            } else if (t < 7){
                int has = (int)rng_int(8);
                int64_t step = rng_int(7) - 3;
                if ((has & HT) && step == 0){
                    step = -1;
                }
                idx[i] = mk_slice(has, rng_int(14) - 7, rng_int(14) - 7, step);
            } else if (t < 9){
                idx[i] = mk_kind(ND_IDX_NEWAXIS);
            } else {
                if (has_ell){
                    idx[i] = mk_kind(ND_IDX_NEWAXIS);
                } else {
                    idx[i] = mk_kind(ND_IDX_ELLIPSIS);
                    has_ell = 1;
                }
            }
        }

        make_iota(nd, dims, layout, &a);
        expect = ref_index(nd, dims, nidx, idx, &rnd, ax, fixed, is_fixed);
        // an integer index is checked against the extent of the axis it lands on: ref_index does that;
        // the draw above picked a random axis, so some tuples are out of range, which is the point.
        st = nd_view_index(&a, nidx, idx, &v);

        if (expect != OTI_OK){
            if (st != expect){
                fprintf(stderr, "  iter %d: expected status %d, got %d\n", iter, expect, st);
                ok_err = 0;
                nfail++;
            }
        } else {
            if (st != OTI_OK){
                fprintf(stderr, "  iter %d: expected OK, got %d\n", iter, st);
                ok = 0;
                nfail++;
            } else {
                if (!check_index_view(&v, nd, dims, rnd, ax, fixed, is_fixed)){
                    ok = 0;
                    nfail++;
                    if (nfail < 5){
                        fprintf(stderr, "  iter %d: view values or shape differ (nd %d, nidx %d)\n", iter,
                                nd, nidx);
                    }
                }
                if (!flags_match(&v)){
                    ok_flags = 0;
                }
                if (!is_borrowing_temp(&v, &a) || !(v.flags & ND_WRITEABLE) ||
                        nd_buffer_refs(a.buf) != 1){
                    ok_own = 0;
                }
            }
        }
        nd_release(&a);

    }

    check(ok, "nd_view_index: 6000 random index tuples agree with the reference (shape and values)");
    check(ok_err,
            "nd_view_index: out-of-range ints, too many indices, two ellipses: expected status");
    check(ok_flags, "nd_view_index: contiguity flags equal NumPy 2's rule for every random view");
    check(ok_own,
            "nd_view_index: results are writeable temporaries borrowing the buffer, refs unchanged");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Ownership of views (decision S1): temporaries; retaining a view keeps the buffer; building in place
// over a temporary source works ([cH2]); trusted spans stay trusted.
static void test_view_ownership(void){

    ndarr_t a = {0}, v = {0}, r = {0}, t = {0};
    int64_t shape[2] = {4, 5};
    nd_index_t idx[2];
    uint64_t s0;

    make_iota(2, shape, ND_LAYOUT_C, &a);
    s0 = nd_buffer_state(a.buf);
    idx[0] = mk_slice(HS | HP, 1, 3, 0);
    idx[1] = mk_int(2);
    nd_init_empty(&v);
    check(nd_view_index(&a, 2, idx, &v) == OTI_OK && nd_buffer_state(a.buf) == s0,
          "view_index leaves the state word untouched");

    // retain a view, release the parent, read through the retained view
    check(nd_view_retain(&v, &r) == OTI_OK && (r.flags & ND_RETAINED) && nd_buffer_refs(a.buf) == 2,
          "nd_view_retain of a view: retained, refs 2");
    check(r.shape[0] == 2 && r.data == v.data && r.strides[0] == 5,
            "retained view: same shape, strides, data");
    nd_release(&a);
    check(r.buf != NULL && nd_buffer_refs(r.buf) == 1,
            "parent released first: the view keeps the buffer alive");
    check(((double*)r.data)[0] == 1 * 5 + 2 && ((double*)r.data)[5] == 2 * 5 + 2,
          "the retained view still reads the right elements");
    nd_release(&r);

    // in place over a temporary source
    make_iota(2, shape, ND_LAYOUT_C, &a);
    t = a;
    t.flags &= ~ND_RETAINED;
    idx[0] = mk_int(1);
    check(nd_view_index(&t, 1, idx, &t) == OTI_OK && t.ndim == 1 && t.shape[0] == 5 &&
          t.data == (double*)a.data + 5, "view_index in place over a temporary (out == src)");
    check(nd_view_transpose(&t, 0, NULL, &t) == OTI_OK && t.ndim == 1,
            "transpose in place over a temporary");
    check(nd_buffer_refs(a.buf) == 1, "in-place views take no reference");

    // views of a trusted span keep buf NULL
    {
        static double mem[20];
        ndarr_t tr = {0}, w = {0};
        int64_t sh[2] = {4, 5};
        nd_wrap_trusted(mem, OTI_F64, 2, sh, NULL, 1, &tr);
        idx[0] = mk_int(2);
        check(nd_view_index(&tr, 1, idx, &w) == OTI_OK && w.buf == NULL && !(w.flags & ND_RETAINED) &&
              w.data == mem + 10, "view of a trusted temporary keeps buf NULL");
        check(nd_view_retain(&w, &r) == OTI_ERR_ARGUMENT,
                "retaining a view of a trusted span -> ARGUMENT");
    }
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// transpose, swapaxes, squeeze, expand_dims
// =======================================================================================================

// *******************************************************************************************************
static void test_transpose_swapaxes(void){

    ndarr_t a = {0}, v = {0};
    int64_t shape[3] = {2, 3, 4};
    int32_t perm[3];
    int64_t idx[3], j[3];
    int ok;

    make_iota(3, shape, ND_LAYOUT_C, &a);

    check(nd_view_transpose(&a, 0, NULL, &v) == OTI_OK && v.ndim == 3 && v.shape[0] == 4 &&
            v.shape[1] == 3 &&
          v.shape[2] == 2 && v.strides[0] == 1 && v.strides[1] == 4 && v.strides[2] == 12 &&
                  v.data == a.data,
          "transpose(naxes 0, axes NULL): reversed axes");
    check((v.flags & ND_F_CONTIG) && !(v.flags & ND_C_CONTIG) && is_borrowing_temp(&v, &a) &&
          (v.flags & ND_WRITEABLE), "transpose of a C array: F contiguous, writeable temporary");

    perm[0] = 1; perm[1] = 2; perm[2] = 0;
    check(nd_view_transpose(&a, 3, perm, &v) == OTI_OK && v.shape[0] == 3 && v.shape[1] == 4 &&
            v.shape[2] == 2 &&
          v.strides[0] == 4 && v.strides[1] == 1 && v.strides[2] == 12, "transpose (1,2,0)");
    ok = 1;
    memset(idx, 0, sizeof(idx));
    do {
        // v[i0,i1,i2] = a[i2, i0, i1]
        j[0] = idx[2]; j[1] = idx[0]; j[2] = idx[1];
        ok = ok && (*at(&v, idx) == (double)(j[0] * 12 + j[1] * 4 + j[2]));
    } while (next_coord(3, v.shape, idx));
    check(ok, "transpose (1,2,0): values");

    perm[0] = -2; perm[1] = -1; perm[2] = 0;
    check(nd_view_transpose(&a, 3, perm, &v) == OTI_OK && v.shape[0] == 3 && v.shape[1] == 4 &&
            v.shape[2] == 2,
          "transpose with negative axes");
    perm[0] = 0; perm[1] = 1; perm[2] = 2;
    check(nd_view_transpose(&a, 3, perm, &v) == OTI_OK && (v.flags & ND_C_CONTIG) && v.strides[0] == 12,
          "transpose identity");
    perm[0] = 0; perm[1] = 0; perm[2] = 1;
    check(nd_view_transpose(&a, 3, perm, &v) == OTI_ERR_ARGUMENT,
            "transpose with a repeated axis -> ARGUMENT");
    perm[0] = 0; perm[1] = 1; perm[2] = 3;
    check(nd_view_transpose(&a, 3, perm, &v) == OTI_ERR_INDEX,
            "transpose with an axis out of range -> INDEX");
    perm[0] = 0; perm[1] = 1; perm[2] = -4;
    check(nd_view_transpose(&a, 3, perm, &v) == OTI_ERR_INDEX, "transpose with axis -4 -> INDEX");
    perm[0] = 0; perm[1] = 1;
    check(nd_view_transpose(&a, 2, perm, &v) == OTI_ERR_ARGUMENT,
            "transpose with the wrong number of axes -> ARGUMENT");

    // swapaxes
    check(nd_view_swapaxes(&a, 0, 2, &v) == OTI_OK && v.shape[0] == 4 && v.shape[1] == 3 &&
            v.shape[2] == 2 &&
          v.strides[0] == 1 && v.strides[1] == 4 && v.strides[2] == 12, "swapaxes(0, 2)");
    check(nd_view_swapaxes(&a, -1, 1, &v) == OTI_OK && v.shape[1] == 4 && v.shape[2] == 3 &&
            v.strides[1] == 1 &&
          v.strides[2] == 4, "swapaxes(-1, 1)");
    check(nd_view_swapaxes(&a, 1, 1, &v) == OTI_OK && v.shape[1] == 3 && (v.flags & ND_C_CONTIG),
          "swapaxes of an axis with itself is the identity");
    check(nd_view_swapaxes(&a, 0, 3, &v) == OTI_ERR_INDEX, "swapaxes: axis out of range -> INDEX");
    check(nd_view_swapaxes(&a, -4, 0, &v) == OTI_ERR_INDEX, "swapaxes: axis -4 -> INDEX");

    // rank 0 and rank 1 transposes
    {
        ndarr_t s = {0}, r0 = {0};
        int64_t one[1] = {5};
        make_iota(1, one, ND_LAYOUT_C, &s);
        check(nd_view_transpose(&s, 0, NULL, &r0) == OTI_OK && r0.ndim == 1 && r0.shape[0] == 5,
              "transpose of a 1-D array");
        nd_release(&s);
        make_iota(0, NULL, ND_LAYOUT_C, &s);
        check(nd_view_transpose(&s, 0, NULL, &r0) == OTI_OK && r0.ndim == 0,
                "transpose of a rank-0 array");
        nd_release(&s);
    }
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_squeeze_expand(void){

    ndarr_t a = {0}, v = {0};
    int64_t shape[4] = {1, 3, 1, 4};
    int32_t axes[3];
    int64_t shape2[2] = {3, 4};

    make_iota(4, shape, ND_LAYOUT_C, &a);

    check(nd_view_squeeze(&a, 0, NULL, &v) == OTI_OK && v.ndim == 2 && v.shape[0] == 3 &&
            v.shape[1] == 4 &&
          v.strides[0] == 4 && v.strides[1] == 1 && v.data == a.data, "squeeze all: (1,3,1,4) -> (3,4)");
    axes[0] = 0;
    check(nd_view_squeeze(&a, 1, axes, &v) == OTI_OK && v.ndim == 3 && v.shape[0] == 3 &&
            v.shape[1] == 1 &&
          v.shape[2] == 4, "squeeze axis 0: (3,1,4)");
    axes[0] = -2;
    check(nd_view_squeeze(&a, 1, axes, &v) == OTI_OK && v.ndim == 3 && v.shape[0] == 1 &&
            v.shape[1] == 3 &&
          v.shape[2] == 4, "squeeze axis -2: (1,3,4)");
    axes[0] = 0; axes[1] = 2;
    check(nd_view_squeeze(&a, 2, axes, &v) == OTI_OK && v.ndim == 2, "squeeze axes (0, 2)");
    axes[0] = 1;
    check(nd_view_squeeze(&a, 1, axes, &v) == OTI_ERR_SHAPE, "squeeze an axis of extent 3 -> SHAPE");
    axes[0] = 0; axes[1] = 0;
    check(nd_view_squeeze(&a, 2, axes, &v) == OTI_ERR_ARGUMENT, "squeeze a repeated axis -> ARGUMENT");
    axes[0] = 0; axes[1] = -4;
    check(nd_view_squeeze(&a, 2, axes, &v) == OTI_ERR_ARGUMENT,
            "squeeze axes 0 and -4 (the same axis) -> ARGUMENT");
    axes[0] = 4;
    check(nd_view_squeeze(&a, 1, axes, &v) == OTI_ERR_INDEX, "squeeze axis 4 -> INDEX");
    nd_release(&a);

    {
        ndarr_t s = {0};
        int64_t one[2] = {1, 1};
        make_iota(2, one, ND_LAYOUT_C, &s);
        check(nd_view_squeeze(&s, 0, NULL, &v) == OTI_OK && v.ndim == 0, "squeeze (1,1) -> rank 0");
        nd_release(&s);
    }

    // expand_dims
    make_iota(2, shape2, ND_LAYOUT_C, &a);
    axes[0] = 0;
    check(nd_view_expand_dims(&a, 1, axes, &v) == OTI_OK && v.ndim == 3 && v.shape[0] == 1 &&
            v.shape[1] == 3 &&
          v.shape[2] == 4 && v.strides[1] == 4 && v.strides[2] == 1, "expand_dims(0): (1,3,4)");
    axes[0] = 1;
    check(nd_view_expand_dims(&a, 1, axes, &v) == OTI_OK && v.shape[0] == 3 && v.shape[1] == 1 &&
            v.shape[2] == 4,
          "expand_dims(1): (3,1,4)");
    axes[0] = -1;
    check(nd_view_expand_dims(&a, 1, axes, &v) == OTI_OK && v.shape[0] == 3 && v.shape[1] == 4 &&
            v.shape[2] == 1,
          "expand_dims(-1): (3,4,1)");
    axes[0] = 0; axes[1] = 3;
    check(nd_view_expand_dims(&a, 2, axes, &v) == OTI_OK && v.ndim == 4 && v.shape[0] == 1 &&
            v.shape[1] == 3 &&
          v.shape[2] == 4 && v.shape[3] == 1, "expand_dims((0, 3)): (1,3,4,1)");
    axes[0] = 1; axes[1] = 3;
    check(nd_view_expand_dims(&a, 2, axes, &v) == OTI_OK && v.shape[0] == 3 && v.shape[1] == 1 &&
            v.shape[2] == 4 &&
          v.shape[3] == 1, "expand_dims((1, 3)): (3,1,4,1)");
    axes[0] = 3;
    check(nd_view_expand_dims(&a, 1, axes, &v) == OTI_ERR_INDEX,
            "expand_dims(3) on rank 2 (result rank 3) -> INDEX");
    axes[0] = -4;
    check(nd_view_expand_dims(&a, 1, axes, &v) == OTI_ERR_INDEX, "expand_dims(-4) -> INDEX");
    axes[0] = 1; axes[1] = 1;
    check(nd_view_expand_dims(&a, 2, axes, &v) == OTI_ERR_ARGUMENT,
            "expand_dims with a repeated position -> ARGUMENT");
    nd_release(&a);
    {
        ndarr_t big = {0};
        int64_t sh32[32];
        int i;
        for (i = 0; i < 32; i++){
            sh32[i] = 1;
        }
        make_iota(32, sh32, ND_LAYOUT_C, &big);
        axes[0] = 0;
        check(nd_view_expand_dims(&big, 1, axes, &v) == OTI_ERR_SHAPE,
                "expand_dims past rank 32 -> SHAPE");
        nd_release(&big);
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// broadcast_to, diagonal
// =======================================================================================================

// *******************************************************************************************************
static void test_broadcast_to(void){

    ndarr_t a = {0}, v = {0};
    int64_t shape[2] = {3, 1};
    int64_t target[3] = {2, 3, 4};
    int64_t idx[3];
    int ok;

    make_iota(2, shape, ND_LAYOUT_C, &a);
    check(nd_view_broadcast_to(&a, 3, target, &v) == OTI_OK, "broadcast_to (3,1) -> (2,3,4)");
    check(v.ndim == 3 && v.shape[0] == 2 && v.shape[1] == 3 && v.shape[2] == 4,
            "broadcast_to: target shape");
    check(v.strides[0] == 0 && v.strides[1] == 1 && v.strides[2] == 0,
            "broadcast_to: stride 0 on stretched / new axes");
    check(!(v.flags & ND_WRITEABLE) && (a.flags & ND_WRITEABLE),
            "broadcast_to: read-only even of a writeable source");
    check(is_borrowing_temp(&v, &a) && flags_match(&v),
            "broadcast_to: borrowing temporary, flags per NumPy");
    ok = 1;
    memset(idx, 0, sizeof(idx));
    do {
        ok = ok && (*at(&v, idx) == (double)idx[1]);
    } while (next_coord(3, v.shape, idx));
    check(ok, "broadcast_to: element (i, j, k) = a[j, 0]");

    check(nd_view_broadcast_to(&a, 2, shape, &v) == OTI_OK && (v.flags & ND_C_CONTIG) &&
            !(v.flags & ND_WRITEABLE),
          "broadcast_to the same shape: read-only view");
    {
        int64_t bad[2] = {4, 1};
        check(nd_view_broadcast_to(&a, 2, bad, &v) == OTI_ERR_SHAPE,
                "broadcast_to (3,1) -> (4,1) -> SHAPE");
    }
    {
        int64_t bad[1] = {3};
        check(nd_view_broadcast_to(&a, 1, bad, &v) == OTI_ERR_SHAPE,
                "broadcast_to a lower rank than the source -> SHAPE");
    }
    {
        int64_t zero[2] = {0, 5};
        check(nd_view_broadcast_to(&a, 2, zero, &v) == OTI_ERR_SHAPE,
                "broadcast_to (3,1) -> (0,5) -> SHAPE");
    }
    nd_release(&a);

    // a one-element rank-0 source broadcasts to anything
    make_iota(0, NULL, ND_LAYOUT_C, &a);
    ((double*)a.data)[0] = 7.0;
    check(nd_view_broadcast_to(&a, 2, shape, &v) == OTI_OK && v.strides[0] == 0 && v.strides[1] == 0 &&
          *at(&v, (int64_t[]){2, 0}) == 7.0, "broadcast_to from rank 0");
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_diagonal(void){

    ndarr_t a = {0}, v = {0};
    int64_t shape[2] = {4, 5};
    int64_t shape3[3] = {3, 4, 5};
    int64_t off, i;
    int ok;

    make_iota(2, shape, ND_LAYOUT_C, &a);
    for (off = -5; off <= 6; off++){
        // expected length of numpy.diagonal(a, off) for a (4,5) matrix
        int64_t len;
        if (off >= 0){
            len = 5 - off < 4 ? 5 - off : 4;
        } else {
            len = 4 + off < 5 ? 4 + off : 5;
        }
        if (len < 0){
            len = 0;
        }
        ok = (nd_view_diagonal(&a, off, 0, 1, &v) == OTI_OK) && v.ndim == 1 && v.shape[0] == len &&
             !(v.flags & ND_WRITEABLE) && is_borrowing_temp(&v, &a);
        for (i = 0; ok && i < len; i++){
            int64_t r = off >= 0 ? i : i - off;
            int64_t c = off >= 0 ? i + off : i;
            ok = ok && (*at(&v, &i) == (double)(r * 5 + c));
        }
        if (!ok){
            fprintf(stderr, "  diagonal offset %lld failed (len expected %lld, got %lld)\n",
                    (long long)off,
                    (long long)len, (long long)v.shape[0]);
        }
        {
            char msg[80];
            snprintf(msg, sizeof(msg), "diagonal of a (4,5) matrix, offset %lld", (long long)off);
            check(ok, msg);
        }
    }

    // axes of a 3-D array: diagonal over (0, 2) becomes the last axis; the remaining axis comes first
    nd_release(&a);
    make_iota(3, shape3, ND_LAYOUT_C, &a);
    ok = (nd_view_diagonal(&a, 0, 0, 2, &v) == OTI_OK) && v.ndim == 2 && v.shape[0] == 4 &&
            v.shape[1] == 3;
    for (i = 0; ok && i < 4; i++){
        int64_t j;
        for (j = 0; j < 3; j++){
            int64_t ix[2];
            ix[0] = i; ix[1] = j;
            ok = ok && (*at(&v, ix) == (double)(j * 20 + i * 5 + j));
        }
    }
    check(ok, "diagonal(axis1 0, axis2 2) of a (3,4,5) array: shape (4,3), the diagonal last");
    ok = (nd_view_diagonal(&a, 1, 1, 2, &v) == OTI_OK) && v.ndim == 2 && v.shape[0] == 3 &&
            v.shape[1] == 4;
    for (i = 0; ok && i < 3; i++){
        int64_t j;
        for (j = 0; j < 4; j++){
            int64_t ix[2];
            ix[0] = i; ix[1] = j;
            ok = ok && (*at(&v, ix) == (double)(i * 20 + j * 5 + (j + 1)));
        }
    }
    check(ok, "diagonal(offset 1, axes 1, 2) of (3,4,5): shape (3,4)");
    ok = (nd_view_diagonal(&a, 0, -1, -2, &v) == OTI_OK) && v.ndim == 2 && v.shape[0] == 3 &&
            v.shape[1] == 4;
    check(ok, "diagonal with negative axes (-1, -2): length min(5,4) = 4");
    check(nd_view_diagonal(&a, 0, 1, 1, &v) == OTI_ERR_ARGUMENT,
            "diagonal: the same axis twice -> ARGUMENT");
    check(nd_view_diagonal(&a, 0, 0, -3, &v) == OTI_ERR_ARGUMENT,
            "diagonal: the same axis as 0 and -3 -> ARGUMENT");
    check(nd_view_diagonal(&a, 0, 0, 3, &v) == OTI_ERR_INDEX, "diagonal: axis out of range -> INDEX");
    nd_release(&a);
    {
        ndarr_t s = {0};
        int64_t one[1] = {5};
        make_iota(1, one, ND_LAYOUT_C, &s);
        check(nd_view_diagonal(&s, 0, 0, 1, &v) == OTI_ERR_SHAPE, "diagonal of a 1-D array -> SHAPE");
        nd_release(&s);
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// reshape
// =======================================================================================================

// *******************************************************************************************************
// Reference: the element at logical position k (in index order `layout`: C or F) of an array.
static double ref_elem_at(const ndarr_t* a, int64_t k, int layout){

    int64_t idx[OTI_ND_MAXDIM];
    int32_t j;
    int64_t rem = k;

    if (layout == ND_LAYOUT_C){
        for (j = a->ndim - 1; j >= 0; j--){
            idx[j] = rem % a->shape[j];
            rem /= a->shape[j];
        }
    } else {
        for (j = 0; j < a->ndim; j++){
            idx[j] = rem % a->shape[j];
            rem /= a->shape[j];
        }
    }
    return *at(a, idx);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int reshape_values_ok(const ndarr_t* src, const ndarr_t* out, int layout){

    int64_t n = shape_size(src->ndim, src->shape), k;

    if (shape_size(out->ndim, out->shape) != n){
        return 0;
    }
    for (k = 0; k < n; k++){
        if (ref_elem_at(src, k, layout) != ref_elem_at(out, k, layout)){
            return 0;
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_view_reshape(void){

    ndarr_t a = {0}, f = {0}, v = {0}, t = {0};
    int64_t shape[2] = {3, 4};
    int64_t tgt[3];

    make_iota(2, shape, ND_LAYOUT_C, &a);

    tgt[0] = 12;
    check(nd_view_reshape(&a, 1, tgt, ND_LAYOUT_C, &v) == OTI_OK && v.ndim == 1 && v.shape[0] == 12 &&
          v.strides[0] == 1 && v.data == a.data && reshape_values_ok(&a, &v, ND_LAYOUT_C),
          "reshape C (3,4) -> (12): view");
    check(is_borrowing_temp(&v, &a) && (v.flags & ND_WRITEABLE) && nd_buffer_refs(a.buf) == 1,
          "reshape view: writeable temporary, no reference taken");
    tgt[0] = 2; tgt[1] = 6;
    check(nd_view_reshape(&a, 2, tgt, ND_LAYOUT_C, &v) == OTI_OK && v.strides[0] == 6 &&
            v.strides[1] == 1 &&
          reshape_values_ok(&a, &v, ND_LAYOUT_C), "reshape C (3,4) -> (2,6)");
    tgt[0] = 3; tgt[1] = 2; tgt[2] = 2;
    check(nd_view_reshape(&a, 3, tgt, ND_LAYOUT_C, &v) == OTI_OK && v.strides[0] == 4 &&
            v.strides[1] == 2 &&
          v.strides[2] == 1 && reshape_values_ok(&a, &v, ND_LAYOUT_C), "reshape C (3,4) -> (3,2,2)");
    tgt[0] = -1; tgt[1] = 6;
    check(nd_view_reshape(&a, 2, tgt, ND_LAYOUT_C, &v) == OTI_OK && v.shape[0] == 2 && v.shape[1] == 6,
          "reshape: -1 inferred (2,6)");
    tgt[0] = 4; tgt[1] = -1;
    check(nd_view_reshape(&a, 2, tgt, ND_LAYOUT_C, &v) == OTI_OK && v.shape[0] == 4 && v.shape[1] == 3,
          "reshape: -1 inferred (4,3)");
    tgt[0] = 1; tgt[1] = 12; tgt[2] = 1;
    check(nd_view_reshape(&a, 3, tgt, ND_LAYOUT_C, &v) == OTI_OK && v.ndim == 3 && v.shape[0] == 1 &&
          reshape_values_ok(&a, &v, ND_LAYOUT_C), "reshape adding axes of extent 1");

    // F order index: a C array reshaped in F index order needs a copy
    tgt[0] = 12;
    check(nd_view_reshape(&a, 1, tgt, ND_LAYOUT_F, &v) == OTI_ERR_LAYOUT,
          "reshape C (3,4) -> (12) in F order: no view -> LAYOUT");
    check(nd_view_reshape(&a, 1, tgt, ND_LAYOUT_A, &v) == OTI_OK && reshape_values_ok(&a, &v,
            ND_LAYOUT_C),
          "reshape order A of a C array behaves as C");

    // an F array
    make_iota(2, shape, ND_LAYOUT_F, &f);
    tgt[0] = 12;
    check(nd_view_reshape(&f, 1, tgt, ND_LAYOUT_F, &v) == OTI_OK && v.strides[0] == 1 &&
          reshape_values_ok(&f, &v, ND_LAYOUT_F), "reshape F (3,4) -> (12) in F order: view");
    check(nd_view_reshape(&f, 1, tgt, ND_LAYOUT_C, &v) == OTI_ERR_LAYOUT,
            "reshape F -> (12) in C order: no view -> LAYOUT");
    check(nd_view_reshape(&f, 1, tgt, ND_LAYOUT_A, &v) == OTI_OK && reshape_values_ok(&f, &v,
            ND_LAYOUT_F),
          "reshape order A of an F array behaves as F");
    nd_release(&f);

    // a transposed C array is F contiguous: (4,3) transposed -> reshape (12) in F order is a view
    nd_view_transpose(&a, 0, NULL, &t);
    tgt[0] = 12;
    check(nd_view_reshape(&t, 1, tgt, ND_LAYOUT_F, &v) == OTI_OK && reshape_values_ok(&t, &v,
            ND_LAYOUT_F),
          "reshape of a transposed C array in F order: view");
    check(nd_view_reshape(&t, 1, tgt, ND_LAYOUT_C, &v) == OTI_ERR_LAYOUT, "... and in C order: LAYOUT");

    // slices that cannot merge: a[:, ::2] (3,2) strides (4,2) -> (6)
    {
        nd_index_t idx[2];
        idx[0] = mk_slice(0, 0, 0, 0);
        idx[1] = mk_slice(HT, 0, 0, 3);
        nd_view_index(&a, 2, idx, &t);
        tgt[0] = 6;
        check(nd_view_reshape(&t, 1, tgt, ND_LAYOUT_C, &v) == OTI_ERR_LAYOUT,
              "reshape a[:, ::3] (strides (4,3)) -> (6): no view -> LAYOUT");
        idx[1] = mk_slice(HT, 0, 0, 2);
        nd_view_index(&a, 2, idx, &t);
        check(nd_view_reshape(&t, 1, tgt, ND_LAYOUT_C, &v) == OTI_OK && v.strides[0] == 2 &&
              reshape_values_ok(&t, &v, ND_LAYOUT_C),
              "reshape a[:, ::2] (strides (4,2), 4 == 2 * 2) -> (6): a view with stride 2");
        idx[1] = mk_slice(HT, 0, 0, 3);
        nd_view_index(&a, 2, idx, &t);
        tgt[0] = 3; tgt[1] = 1; tgt[2] = 2;
        check(nd_view_reshape(&t, 3, tgt, ND_LAYOUT_C, &v) == OTI_OK && reshape_values_ok(&t, &v,
                ND_LAYOUT_C),
              "reshape a[:, ::3] -> (3,1,2): a view (only extent-1 axes added)");
        // a[::2] (2,4) strides (8,1) -> (2,2,2)
        idx[0] = mk_slice(HT, 0, 0, 2);
        nd_view_index(&a, 1, idx, &t);
        tgt[0] = 2; tgt[1] = 2; tgt[2] = 2;
        check(nd_view_reshape(&t, 3, tgt, ND_LAYOUT_C, &v) == OTI_OK && reshape_values_ok(&t, &v,
                ND_LAYOUT_C),
              "reshape a[::2] -> (2,2,2): splitting the contiguous axis is a view");
        tgt[0] = 8;
        check(nd_view_reshape(&t, 1, tgt, ND_LAYOUT_C, &v) == OTI_ERR_LAYOUT,
                "reshape a[::2] -> (8): LAYOUT");
    }

    // reversed 1-D array: negative strides reshape to (2,6)
    {
        ndarr_t r1 = {0};
        int64_t sh[1] = {12};
        nd_index_t idx[1];
        make_iota(1, sh, ND_LAYOUT_C, &r1);
        idx[0] = mk_slice(HT, 0, 0, -1);
        nd_view_index(&r1, 1, idx, &t);
        tgt[0] = 3; tgt[1] = 4;
        check(nd_view_reshape(&t, 2, tgt, ND_LAYOUT_C, &v) == OTI_OK && v.strides[0] == -4 &&
                v.strides[1] == -1 &&
              reshape_values_ok(&t, &v, ND_LAYOUT_C),
                      "reshape of a reversed 1-D array -> (3,4): negative strides kept");
        nd_release(&r1);
    }

    // size 0 and rank 0
    {
        ndarr_t z = {0}, s = {0};
        int64_t zs[2] = {0, 3};
        int64_t sh1[1] = {1};
        make_iota(2, zs, ND_LAYOUT_C, &z);
        tgt[0] = 3; tgt[1] = 0;
        check(nd_view_reshape(&z, 2, tgt, ND_LAYOUT_C, &v) == OTI_OK && v.shape[0] == 3 &&
                v.shape[1] == 0,
              "reshape (0,3) -> (3,0)");
        tgt[0] = -1; tgt[1] = 0;
        check(nd_view_reshape(&z, 2, tgt, ND_LAYOUT_C, &v) == OTI_ERR_SHAPE,
              "reshape: -1 with a zero-size remainder -> SHAPE");
        nd_release(&z);
        make_iota(1, sh1, ND_LAYOUT_C, &s);
        check(nd_view_reshape(&s, 0, NULL, ND_LAYOUT_C, &v) == OTI_OK && v.ndim == 0,
                "reshape (1) -> rank 0");
        nd_release(&s);
    }

    // errors
    tgt[0] = 5;
    check(nd_view_reshape(&a, 1, tgt, ND_LAYOUT_C, &v) == OTI_ERR_SHAPE,
            "reshape to a different size -> SHAPE");
    tgt[0] = -1; tgt[1] = -1;
    check(nd_view_reshape(&a, 2, tgt, ND_LAYOUT_C, &v) == OTI_ERR_SHAPE, "reshape with two -1 -> SHAPE");
    tgt[0] = -1; tgt[1] = 5;
    check(nd_view_reshape(&a, 2, tgt, ND_LAYOUT_C, &v) == OTI_ERR_SHAPE,
            "reshape: -1 that does not divide -> SHAPE");
    tgt[0] = 12;
    check(nd_view_reshape(&a, 1, tgt, ND_LAYOUT_K, &v) == OTI_ERR_ARGUMENT,
            "reshape with layout K -> ARGUMENT");
    check(nd_view_reshape(&a, 1, tgt, 9, &v) == OTI_ERR_ARGUMENT,
            "reshape with an unknown layout -> ARGUMENT");
    tgt[0] = -2;
    check(nd_view_reshape(&a, 1, tgt, ND_LAYOUT_C, &v) == OTI_ERR_SHAPE,
            "reshape with an extent -2 -> SHAPE");

    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 3.3 read-only propagation
// =======================================================================================================

// *******************************************************************************************************
static void test_readonly_propagation(void){

    static double mem[24];
    ndarr_t d = {0}, ro = {0}, rw = {0}, v = {0};
    int64_t shape[2] = {4, 6};
    int64_t strides[2] = {6, 1};
    nd_index_t idx[2];
    int32_t axes[2];

    make_desc(&d, mem, OTI_F64, 2, shape, strides, 0);
    nd_wrap(NULL, &d, mem, sizeof(mem), NULL, NULL, &ro);
    make_desc(&d, mem, OTI_F64, 2, shape, strides, ND_WRITEABLE);
    nd_wrap(NULL, &d, mem, sizeof(mem), NULL, NULL, &rw);

    idx[0] = mk_slice(HS, 1, 0, 0);
    idx[1] = mk_int(2);
    check(nd_view_index(&ro, 2, idx, &v) == OTI_OK && !(v.flags & ND_WRITEABLE),
            "view_index keeps read-only");
    check(nd_view_index(&rw, 2, idx, &v) == OTI_OK && (v.flags & ND_WRITEABLE),
            "view_index keeps writeable");
    check(nd_view_transpose(&ro, 0, NULL, &v) == OTI_OK && !(v.flags & ND_WRITEABLE),
            "transpose keeps read-only");
    check(nd_view_transpose(&rw, 0, NULL, &v) == OTI_OK && (v.flags & ND_WRITEABLE),
            "transpose keeps writeable");
    check(nd_view_swapaxes(&rw, 0, 1, &v) == OTI_OK && (v.flags & ND_WRITEABLE),
            "swapaxes keeps writeable");
    check(nd_view_swapaxes(&ro, 0, 1, &v) == OTI_OK && !(v.flags & ND_WRITEABLE),
            "swapaxes keeps read-only");
    {
        int64_t one[3] = {4, 1, 6};
        int64_t onest[3] = {6, 6, 1};
        ndarr_t o = {0}, w = {0};
        make_desc(&o, mem, OTI_F64, 3, one, onest, ND_WRITEABLE);
        axes[0] = 1;
        check(nd_view_squeeze(&o, 1, axes, &w) == OTI_OK && (w.flags & ND_WRITEABLE),
                "squeeze keeps writeable");
        make_desc(&o, mem, OTI_F64, 3, one, onest, 0);
        check(nd_view_squeeze(&o, 1, axes, &w) == OTI_OK && !(w.flags & ND_WRITEABLE),
                "squeeze keeps read-only");
    }
    axes[0] = 0;
    check(nd_view_expand_dims(&rw, 1, axes, &v) == OTI_OK && (v.flags & ND_WRITEABLE),
            "expand_dims keeps writeable");
    check(nd_view_expand_dims(&ro, 1, axes, &v) == OTI_OK && !(v.flags & ND_WRITEABLE),
            "expand_dims keeps read-only");
    {
        int64_t tgt[1] = {24};
        check(nd_view_reshape(&rw, 1, tgt, ND_LAYOUT_C, &v) == OTI_OK && (v.flags & ND_WRITEABLE),
              "reshape view keeps writeable");
        check(nd_view_reshape(&ro, 1, tgt, ND_LAYOUT_C, &v) == OTI_OK && !(v.flags & ND_WRITEABLE),
              "reshape view keeps read-only");
    }
    check(nd_view_diagonal(&rw, 0, 0, 1, &v) == OTI_OK && !(v.flags & ND_WRITEABLE),
          "diagonal of a writeable array is read-only (as NumPy)");
    {
        int64_t tgt[3] = {2, 4, 6};
        check(nd_view_broadcast_to(&rw, 3, tgt, &v) == OTI_OK && !(v.flags & ND_WRITEABLE),
              "broadcast_to of a writeable array is read-only");
    }
    // The buffer state of a read-only wrap never allows a writeable descriptor.
    check(!(nd_buffer_state(ro.buf) & ND_STATE_WRITEABLE) &&
            (nd_buffer_state(rw.buf) & ND_STATE_WRITEABLE),
          "wrap: buffer WRITEABLE bit follows the descriptor");

    // A view that nd_internal_overlap flags is not writeable: a hand-built writeable descriptor with a
    // zero stride, then sliced and transposed.
    {
        int64_t sh[2] = {3, 4};
        int64_t st[2] = {0, 1};
        ndarr_t z = {0}, rz = {0};
        make_desc(&z, mem, OTI_F64, 2, sh, st, ND_WRITEABLE);
        nd_wrap(NULL, &z, NULL, -1, NULL, NULL, &rz);
        idx[0] = mk_slice(HS | HP, 0, 2, 0);
        check(nd_view_index(&rz, 1, idx, &v) == OTI_OK && !(v.flags & ND_WRITEABLE),
              "a view whose layout has internal overlap is not writeable (slice of a stride-0 array)");
        check(nd_view_transpose(&rz, 0, NULL, &v) == OTI_OK && !(v.flags & ND_WRITEABLE),
              "a transposed view with internal overlap is not writeable");
        nd_release(&rz);
    }

    nd_release(&ro);
    nd_release(&rw);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Views of views, chained, against the reference: transpose(a)[::2, 1:] and a[1:, ::-1].T.
static void test_view_chain(void){

    ndarr_t a = {0}, v = {0}, w = {0}, x = {0};
    int64_t shape[3] = {3, 4, 5};
    nd_index_t idx[3];
    int ok;
    int64_t k, idx3[3], j[3];

    make_iota(3, shape, ND_LAYOUT_F, &a);
    idx[0] = mk_slice(HS, 1, 0, 0);
    idx[1] = mk_slice(HT, 0, 0, -1);
    idx[2] = mk_slice(HS | HP | HT, 4, 0, -2);
    nd_view_index(&a, 3, idx, &v);
    nd_view_transpose(&v, 0, NULL, &w);
    idx[0] = mk_slice(HS, 1, 0, 0);
    idx[1] = mk_kind(ND_IDX_NEWAXIS);
    nd_view_index(&w, 2, idx, &x);
    // v = a[1:, ::-1, 4:0:-2] shape (2,4,2); w = v.T shape (2,4,2) reversed axes; x = w[1:, None]
    ok = (x.ndim == 4 && x.shape[0] == 1 && x.shape[1] == 1 && x.shape[2] == 4 && x.shape[3] == 2);
    memset(idx3, 0, sizeof(idx3));
    for (k = 0; ok && k < 8; k++){
        // x[0, 0, p, q] = w[1, p, q] = v[q, p, 1] = a[1 + q, 3 - p, 4 - 2*1]
        int64_t p = k / 2, q = k % 2;
        j[0] = 1 + q;
        j[1] = 3 - p;
        j[2] = 4 - 2 * 1;
        {
            int64_t ix[4];
            ix[0] = 0; ix[1] = 0; ix[2] = p; ix[3] = q;
            ok = ok && (*at(&x, ix) == (double)(j[0] * 20 + j[1] * 5 + j[2]));
        }
    }
    check(ok, "chained views (slice, reverse, transpose, newaxis) read the right elements");
    check(flags_match(&x) && is_borrowing_temp(&x, &a) && nd_buffer_refs(a.buf) == 1,
            "chained views: flags and ownership");
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 1 regressions (checker findings 1, 7, 8).
static int empty_state(const ndarr_t* a){

    return a->data == NULL && a->buf == NULL && a->ndim == 1 && a->shape[0] == 0 && a->dtype == OTI_F64 &&
           a->flags == (ND_C_CONTIG | ND_F_CONTIG | ND_WRITEABLE);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_fix1_views(void){

    ndarr_t s = {0}, a = {0}, t = {0}, out = {0};
    int64_t tgt2[2] = {INT64_C(1) << 32, INT64_C(1) << 32};
    int64_t tgt1[1] = {INT64_MAX};
    int64_t sh[2] = {3, 4};
    int64_t bad[1] = {5};
    int64_t flat[1] = {12};
    int st;

    // 1: broadcast element / byte count overflow
    make_iota(0, NULL, ND_LAYOUT_C, &s);
    memset(&out, 0x5A, sizeof(out));
    out.flags = 0; out.buf = NULL;
    check(nd_view_broadcast_to(&s, 2, tgt2, &out) == OTI_ERR_SIZE && empty_state(&out),
          "fix1.1: scalar broadcast to (2^32, 2^32) -> SIZE, out empty");
    memset(&out, 0x5A, sizeof(out));
    out.flags = 0; out.buf = NULL;
    check(nd_view_broadcast_to(&s, 1, tgt1, &out) == OTI_ERR_SIZE && empty_state(&out),
          "fix1.1: scalar broadcast to (INT64_MAX,) F64 (byte count overflows) -> SIZE, out empty");
    nd_release(&s);

    // 7: on failure out is empty, also when out == src
    make_iota(2, sh, ND_LAYOUT_C, &a);
    t = a;
    t.flags &= ~ND_RETAINED;
    check(nd_view_swapaxes(&t, 0, 99, &t) == OTI_ERR_INDEX && empty_state(&t),
          "fix1.7: swapaxes(&t, 0, 99, &t) -> INDEX and t empty");
    t = a;
    t.flags &= ~ND_RETAINED;
    st = nd_view_reshape(&t, 1, bad, ND_LAYOUT_C, &t);
    check(st == OTI_ERR_SHAPE && empty_state(&t), "fix1.7: a failed in-place reshape leaves t empty");
    t = a;
    t.flags &= ~ND_RETAINED;
    check(nd_view_transpose(&t, 3, (int32_t[]){0, 1, 2}, &t) != OTI_OK && empty_state(&t),
          "fix1.7: a failed in-place transpose leaves t empty");
    nd_release(&a);

    // 8: nd_view_reshape needing a copy records LAYOUT
    make_iota(2, sh, ND_LAYOUT_F, &a);
    oti_ctx_clear_error(NULL);
    st = nd_view_reshape(&a, 1, flat, ND_LAYOUT_C, &t);
    check(st == OTI_ERR_LAYOUT && oti_ctx_last_error(NULL, NULL, NULL) == OTI_ERR_LAYOUT,
          "fix1.8: nd_view_reshape needing a copy -> LAYOUT recorded as the last error");
    oti_ctx_clear_error(NULL);
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 2 (V1): a reshape target whose byte count overflows is SIZE, out empty, recorded.
static void test_fix2_views(void){

    ndarr_t e = {0}, o = {0}, r = {0};
    int64_t z[1] = {0};
    int64_t tgt[2] = {0, INT64_C(1) << 60};
    int st;

    nd_alloc(NULL, OTI_F64, 1, z, ND_LAYOUT_F, 0, &e);
    oti_ctx_clear_error(NULL);
    st = nd_view_reshape(&e, 2, tgt, ND_LAYOUT_C, &o);
    check(st == OTI_ERR_SIZE && empty_state(&o),
            "fix2.V1: nd_view_reshape to (0, 2^60) -> SIZE, out empty");
    check(oti_ctx_last_error(NULL, NULL, NULL) == OTI_ERR_SIZE, "fix2.V1: recorded as the last error");
    oti_ctx_clear_error(NULL);
    st = nd_reshape(NULL, &e, 2, tgt, ND_LAYOUT_C, &r, NULL);
    check(st == OTI_ERR_SIZE && empty_state(&r), "fix2.V1: nd_reshape to (0, 2^60) -> SIZE, res empty");
    check(oti_ctx_last_error(NULL, NULL, NULL) == OTI_ERR_SIZE, "fix2.V1: nd_reshape records SIZE");
    oti_ctx_clear_error(NULL);
    nd_release(&e);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 3 (S24): the dense SoA block layout (6, 8, 5) with strides (40, 1, 8).
static void test_fix3_views(void){

    ndarr_t a = {0}, blk = {0}, tr = {0}, m = {0};
    int64_t sh[3] = {6, 8, 5};
    int64_t st[3] = {40, 1, 8};
    int64_t msh[2] = {8, 30};
    int32_t perm[3] = {1, 2, 0};
    nd_index_t idx[1];
    oti_view v;
    int64_t b, i, j;
    int ok = 1;

    check(nd_alloc_strided(NULL, OTI_F64, 3, sh, st, 0, &a) == OTI_OK, "fix3: SoA array");
    for (b = 0; b < 6; b++){
        for (i = 0; i < 8; i++){
            for (j = 0; j < 5; j++){
                ((double*)a.data)[b * 40 + i + j * 8] = (double)(b * 1000 + i * 10 + j);
            }
        }
    }

    // nd_to_view
    v.struct_size = (int32_t)sizeof(oti_view);
    check(nd_to_view(&a, &v) == OTI_OK && v.dl.ndim == 3 && v.dl.shape[0] == 6 && v.dl.shape[1] == 8 &&
          v.dl.shape[2] == 5 && v.dl.strides[0] == 40 && v.dl.strides[1] == 1 && v.dl.strides[2] == 8 &&
          v.dl.data == a.data && v.flags == 0,
                  "fix3: nd_to_view of the SoA array: shape (6,8,5), strides (40,1,8)");

    // block views: a[b] is an F-ordered (8, 5) matrix
    idx[0].kind = ND_IDX_INT; idx[0].has = 0; idx[0].start = 2;
    idx[0].stop = 0; idx[0].step = 0; idx[0].arr = NULL;
    check(nd_view_index(&a, 1, idx, &blk) == OTI_OK && blk.ndim == 2 && blk.shape[0] == 8 &&
            blk.shape[1] == 5 &&
          blk.strides[0] == 1 && blk.strides[1] == 8 && (blk.flags & ND_F_CONTIG) &&
                  !(blk.flags & ND_C_CONTIG),
          "fix3: block view a[2]: (8,5) with strides (1,8), F contiguous");

    // the blocks as one (n, m*N) matrix: transpose (1,2,0) then reshape in F order is a view
    check(nd_view_transpose(&a, 3, perm, &tr) == OTI_OK && tr.shape[0] == 8 && tr.shape[1] == 5 &&
          tr.shape[2] == 6 && tr.strides[0] == 1 && tr.strides[1] == 8 && tr.strides[2] == 40,
          "fix3: transpose (1,2,0) of the blocks: shape (8,5,6), strides (1,8,40)");
    check(nd_view_reshape(&tr, 2, msh, ND_LAYOUT_F, &m) == OTI_OK && m.shape[0] == 8 &&
            m.shape[1] == 30 &&
          m.strides[0] == 1 && m.strides[1] == 8 && (m.flags & ND_F_CONTIG) && m.data == a.data,
          "fix3: transposed blocks reshape (F order) into one (8,30) view with strides (1,8)");
    for (j = 0; j < 30; j++){
        for (i = 0; i < 8; i++){
            // F-order column j of (m, N) splits as j = col + 5 * block
            int64_t col = j % 5, blkno = j / 5;
            ok = ok && ((double*)m.data)[i + j * 8] == (double)(blkno * 1000 + i * 10 + col);
        }
    }
    check(ok, "fix3: the (8,30) matrix view holds the blocks side by side");
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 4: views of an empty array with a huge stride: empty results, no overflow, data unchanged.
static void test_fix4_views(void){

    ndarr_t a = {0}, o = {0}, t = {0};
    int64_t sh[2] = {0, 3};
    int64_t st[2] = {0, INT64_MAX};
    nd_index_t idx[2];
    int variant, made;

    made = (nd_alloc_strided(NULL, OTI_F64, 2, sh, st, 0, &a) == OTI_OK);
    if (!made){
        // nd_alloc_strided rejected those strides: build the empty array as a trusted span
        static double mem[1];
        check(nd_wrap_trusted(mem, OTI_F64, 2, sh, st, 1, &a) == OTI_OK,
              "fix4: trusted empty (0,3) with huge strides");
    }
    for (variant = 0; variant < 3; variant++){
        int aliased;
        for (aliased = 0; aliased < 2; aliased++){
            int stt;
            char msg[96];
            t = a;
            t.flags &= ~ND_RETAINED;
            nd_init_empty(&o);
            idx[0] = mk_slice(0, 0, 0, 0);
            if (variant == 0){
                idx[1] = mk_int(2);
            } else {
                idx[1] = mk_slice(HS, 2, 0, 0);
            }
            if (variant < 2){
                stt = nd_view_index(&t, 2, idx, aliased ? &t : &o);
            } else {
                stt = nd_view_diagonal(&t, 2, 0, 1, aliased ? &t : &o);
            }
            snprintf(msg, sizeof(msg), "fix4: %s%s succeeds with an empty result",
                     variant == 0 ? "a[:, 2]" : variant == 1 ? "a[:, 2:]" : "diagonal(2, 0, 1)",
                     aliased ? " (aliased destination)" : "");
            check(stt == OTI_OK && nd_size(aliased ? &t : &o) == 0 &&
                  (aliased ? t.data : o.data) == a.data, msg);
        }
    }
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    test_slice_normalize();
    test_normalize_axis();
    test_broadcast_shapes_table();
    test_view_index_hand();
    test_view_index_random();
    test_view_ownership();
    test_transpose_swapaxes();
    test_squeeze_expand();
    test_broadcast_to();
    test_diagonal();
    test_view_reshape();
    test_readonly_propagation();
    test_view_chain();

    test_fix1_views();

    test_fix2_views();

    test_fix3_views();

    test_fix4_views();

    if (n_failed > 0){
        fprintf(stderr, "\n%d check(s) FAILED\n", n_failed);
        return 1;
    }
    printf("\nAll checks passed.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
