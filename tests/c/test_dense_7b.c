/* Tests of the dense SoA n-D C API of Phase 7b (include/oti/dense/soa/base.h "N-D ARRAYS (7b)",
 * structures.h; PLAN-ndarray-contracts.md 7.2-7.5, 11.2-11.7): oarr_zeros_nd_to, oarr_from_real_nd_to,
 * oarr_from_oti_to, oarr_get_elem_to, oarr_view_index / _transpose / _reshape, oarr_reshape_copy_to,
 * oarr_reshape_root, oarr_assign_to (broadcast, growth, fit or BUSY, snapshots), oarr_index_get_to /
 * _set / _set_o / _set_r, oarr_grow_layout, oarr_is_shared, reservations, and the per-operand-stride
 * kernels (elementwise products of non-compact views with broadcasting, `res` a view of a shared root).
 *
 * Written from the contracts and the posted header, independently of the implementation. Oracle: a
 * reference model in plain C. An "image" holds the logical C-order element array with its NBLK = 6
 * direction blocks (nact 2, truncation order 2: blocks real, e1, e2, e1^2, e1e2, e2^2) as exact multiples
 * of 1/4; index keys, broadcasting, slicing (NumPy's PySlice_AdjustIndices) and the truncated polynomial
 * product are re-implemented here. Arrays are read and written through their block descriptors
 * (shape / strides in elements), so the checks do not depend on the dense kernels. */
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L   // contracts S23
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <oti/oti.h>
#include <oti/dense.h>
#include <oti/core/meta.h>
#include <oti/real/ndarray/buffer.h>
#include <oti/real/ndarray/create.h>
#include <oti/real/ndarray/views.h>

#define NACT   2                 ///< Active bases of every test array.
#define TRC    2                 ///< Truncation order of every test array.
#define NBLK   6                 ///< 1 + number of directions of orders 1..2 over 2 bases.
#define MAXD   5                 ///< Largest rank of the test arrays.
#define MAXEL  256               ///< Largest element count of an image.

static int n_failed = 0;
static dhelpl_t g_dhl;

/// Exponents (of e1, e2) of the six blocks, in the library's global direction order.
static const int MON[NBLK][2] = {{0, 0}, {1, 0}, {0, 1}, {2, 0}, {1, 1}, {0, 2}};


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


/// Reference image: logical element array, row-major, NBLK blocks.
typedef struct {
    int     ndim;
    int64_t shape[MAXD];
    int64_t size;
    double  v[MAXEL][NBLK];
} image_t;


// *******************************************************************************************************
static void image_init(image_t* im, int ndim, const int64_t* shape){

    int k;

    memset(im, 0, sizeof(*im));
    im->ndim = ndim;
    im->size = 1;
    for (k = 0; k < ndim; k++){
        im->shape[k] = shape[k];
        im->size *= shape[k];
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Exact deterministic value of block b of the element with row-major linear index lin.
static double value(int tag, int64_t lin, int b){

    return (double)(((lin * 7 + b * 5 + tag * 11) % 13) - 6) / 4.0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void image_fill(image_t* im, int tag){

    int64_t e;
    int b;

    for (e = 0; e < im->size; e++){
        for (b = 0; b < NBLK; b++){
            im->v[e][b] = value(tag, e, b);
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Row-major linear index of a multi-index in a shape.
static int64_t lin_of(int ndim, const int64_t* shape, const int64_t* m){

    int64_t l = 0;
    int k;

    for (k = 0; k < ndim; k++){
        l = l * shape[k] + m[k];
    }
    return l;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Multi-index of a row-major linear index.
static void multi_of(int ndim, const int64_t* shape, int64_t l, int64_t* m){

    int k;

    for (k = ndim - 1; k >= 0; k--){
        m[k] = (shape[k] > 0) ? l % shape[k] : 0;
        l = (shape[k] > 0) ? l / shape[k] : 0;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Pointer of block b at a multi-index, through the descriptor strides.
static coeff_t* at(const oarr_t* a, const int64_t* m, int b){

    int64_t off = (int64_t)b * a->blocks.strides[0];
    int k;

    for (k = 0; k < oarr_ndim(a); k++){
        off += m[k] * a->blocks.strides[1 + k];
    }
    return oarr_data(a) + off;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Writes an image into an array of the same shape through the descriptor (and raises act_order).
static void store(oarr_t* a, const image_t* im){

    int64_t e, m[MAXD];
    int b;

    for (e = 0; e < im->size; e++){
        multi_of(im->ndim, im->shape, e, m);
        for (b = 0; b < NBLK; b++){
            *at(a, m, b) = im->v[e][b];
        }
    }
    oarr_set_act_order(a, TRC);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// 1 when the array has the image's shape and every coefficient equals the image's (through strides).
static int same_as(const oarr_t* a, const image_t* im){

    int64_t e, m[MAXD];
    int k, b;

    if (oarr_ndim(a) != im->ndim){
        return 0;
    }
    for (k = 0; k < im->ndim; k++){
        if (oarr_shape(a, k) != im->shape[k]){
            return 0;
        }
    }
    for (e = 0; e < im->size; e++){
        multi_of(im->ndim, im->shape, e, m);
        for (b = 0; b < NBLK; b++){
            if (*at(a, m, b) != im->v[e][b]){
                return 0;
            }
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Reads an array into an image (through the descriptor).
static void load(const oarr_t* a, image_t* im){

    int64_t shape[MAXD], e, m[MAXD];
    int k, b;

    for (k = 0; k < oarr_ndim(a); k++){
        shape[k] = oarr_shape(a, k);
    }
    image_init(im, oarr_ndim(a), shape);
    for (e = 0; e < im->size; e++){
        multi_of(im->ndim, im->shape, e, m);
        for (b = 0; b < NBLK; b++){
            im->v[e][b] = *at(a, m, b);
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Creates a root of a shape and layout holding the image values of a tag (act_order TRC).
static int make_root(oarr_t* a, int ndim, const int64_t* shape, int layout, int tag, image_t* im){

    int st = oarr_zeros_nd_to(NACT, ndim, shape, layout, TRC, a);

    if (st != OTI_OK){
        return st;
    }
    image_init(im, ndim, shape);
    image_fill(im, tag);
    store(a, im);
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Reference elementwise product with NumPy broadcasting; returns 0 when the shapes do not broadcast.
static int image_mul(const image_t* x, const image_t* y, image_t* out){

    int nd = (x->ndim > y->ndim) ? x->ndim : y->ndim;
    int64_t shape[MAXD], m[MAXD], mx[MAXD], my[MAXD], e;
    int k, i, j;

    for (k = 0; k < nd; k++){
        int64_t sx = (k - (nd - x->ndim) >= 0) ? x->shape[k - (nd - x->ndim)] : 1;
        int64_t sy = (k - (nd - y->ndim) >= 0) ? y->shape[k - (nd - y->ndim)] : 1;
        if (sx != sy && sx != 1 && sy != 1){
            return 0;
        }
        shape[k] = (sx == 1) ? sy : sx;
    }
    image_init(out, nd, shape);
    for (e = 0; e < out->size; e++){
        multi_of(nd, shape, e, m);
        for (k = 0; k < x->ndim; k++){
            int64_t sk = x->shape[k];
            mx[k] = (sk == 1) ? 0 : m[k + nd - x->ndim];
        }
        for (k = 0; k < y->ndim; k++){
            int64_t sk = y->shape[k];
            my[k] = (sk == 1) ? 0 : m[k + nd - y->ndim];
        }
        {
            const double* a = x->v[lin_of(x->ndim, x->shape, mx)];
            const double* b = y->v[lin_of(y->ndim, y->shape, my)];
            for (i = 0; i < NBLK; i++){
                for (j = 0; j < NBLK; j++){
                    int ex = MON[i][0] + MON[j][0];
                    int ey = MON[i][1] + MON[j][1];
                    int t;
                    if (ex + ey > TRC){
                        continue;
                    }
                    for (t = 0; t < NBLK; t++){
                        if (MON[t][0] == ex && MON[t][1] == ey){
                            out->v[e][t] += a[i] * b[j];
                        }
                    }
                }
            }
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


/// One item of a basic key (the C struct of the library) and its reference expansion.
typedef struct {
    int     src_axis;   ///< Source axis of an output axis, -1 for a newaxis.
    int64_t start, step, len;
} outax_t;


// *******************************************************************************************************
/// NumPy slice normalization (PySlice_AdjustIndices).
static void slice_adjust(int64_t n, const nd_index_t* s, int64_t* start, int64_t* step, int64_t* len){

    int64_t st = (s->has & ND_HAS_STEP) ? s->step : 1;
    int64_t lo = (st < 0) ? -1 : 0;
    int64_t hi = (st < 0) ? n - 1 : n;
    int64_t a, b;

    a = (s->has & ND_HAS_START) ? s->start : ((st < 0) ? hi : lo);
    b = (s->has & ND_HAS_STOP) ? s->stop : ((st < 0) ? lo : hi);
    if (s->has & ND_HAS_START){
        if (a < 0){
            a += n;
            if (a < lo){
                a = lo;
            }
        } else if (a > hi){
            a = hi;
        }
    }
    if (s->has & ND_HAS_STOP){
        if (b < 0){
            b += n;
            if (b < lo){
                b = lo;
            }
        } else if (b > hi){
            b = hi;
        }
    }
    *start = a;
    *step = st;
    if (st < 0){
        *len = (b < a) ? (a - b - 1) / (-st) + 1 : 0;
    } else {
        *len = (a < b) ? (b - a - 1) / st + 1 : 0;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Reference of a basic key on an image. Returns 0 on an index error.
static int image_index(const image_t* x, int nidx, const nd_index_t* key, image_t* out){

    int fixed[MAXD], nfixed_axes = 0;
    int64_t fixv[MAXD];
    outax_t oa[2 * MAXD];
    int noa = 0, consumed = 0, ell = -1, i, k, ax = 0;
    int64_t shape[2 * MAXD], e, mo[2 * MAXD], ms[MAXD];

    for (i = 0; i < nidx; i++){
        if (key[i].kind == ND_IDX_INT || key[i].kind == ND_IDX_SLICE){
            consumed++;
        } else if (key[i].kind == ND_IDX_ELLIPSIS){
            ell = i;
        }
    }
    if (consumed > x->ndim){
        return 0;
    }
    for (k = 0; k < x->ndim; k++){
        fixed[k] = 0;
        fixv[k] = 0;
    }
    (void)nfixed_axes;
    for (i = 0; i < nidx; i++){
        if (key[i].kind == ND_IDX_ELLIPSIS){
            int fill = x->ndim - consumed;
            while (fill-- > 0){
                oa[noa].src_axis = ax;
                oa[noa].start = 0;
                oa[noa].step = 1;
                oa[noa].len = x->shape[ax];
                noa++;
                ax++;
            }
        } else if (key[i].kind == ND_IDX_NEWAXIS){
            oa[noa].src_axis = -1;
            oa[noa].start = 0;
            oa[noa].step = 1;
            oa[noa].len = 1;
            noa++;
        } else if (key[i].kind == ND_IDX_INT){
            int64_t v = key[i].start;
            if (v < 0){
                v += x->shape[ax];
            }
            if (v < 0 || v >= x->shape[ax]){
                return 0;
            }
            fixed[ax] = 1;
            fixv[ax] = v;
            ax++;
        } else {
            oa[noa].src_axis = ax;
            slice_adjust(x->shape[ax], &key[i], &oa[noa].start, &oa[noa].step, &oa[noa].len);
            noa++;
            ax++;
        }
    }
    (void)ell;
    while (ax < x->ndim){
        oa[noa].src_axis = ax;
        oa[noa].start = 0;
        oa[noa].step = 1;
        oa[noa].len = x->shape[ax];
        noa++;
        ax++;
    }
    for (k = 0; k < noa; k++){
        shape[k] = oa[k].len;
    }
    image_init(out, noa, shape);
    for (e = 0; e < out->size; e++){
        int b;
        multi_of(noa, shape, e, mo);
        for (k = 0; k < x->ndim; k++){
            ms[k] = fixed[k] ? fixv[k] : 0;
        }
        for (k = 0; k < noa; k++){
            if (oa[k].src_axis >= 0){
                ms[oa[k].src_axis] = oa[k].start + mo[k] * oa[k].step;
            }
        }
        for (b = 0; b < NBLK; b++){
            out->v[e][b] = x->v[lin_of(x->ndim, x->shape, ms)][b];
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static nd_index_t K_int(int64_t i){

    nd_index_t k;

    memset(&k, 0, sizeof(k));
    k.kind = ND_IDX_INT;
    k.start = i;
    return k;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static nd_index_t K_slice(int has, int64_t start, int64_t stop, int64_t step){

    nd_index_t k;

    memset(&k, 0, sizeof(k));
    k.kind = ND_IDX_SLICE;
    k.has = has;
    k.start = start;
    k.stop = stop;
    k.step = step;
    return k;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static nd_index_t K_kind(int kind){

    nd_index_t k;

    memset(&k, 0, sizeof(k));
    k.kind = kind;
    return k;

}
// -------------------------------------------------------------------------------------------------------


#define HS  ND_HAS_START
#define HE  ND_HAS_STOP
#define HT  ND_HAS_STEP


// *******************************************************************************************************
/// Layout check of a root created by oarr_zeros_nd_to: compact, F or C index order.
static int layout_ok(const oarr_t* a, int layout){

    int k, nd = oarr_ndim(a);
    int64_t size = 1, run = 1;

    for (k = 0; k < nd; k++){
        size *= oarr_shape(a, k);
    }
    if (size == 0){
        return 1;
    }
    if (a->blocks.strides[0] != size){
        return 0;
    }
    if (layout == ND_LAYOUT_F){
        for (k = 0; k < nd; k++){
            if (oarr_shape(a, k) > 1 && a->blocks.strides[1 + k] != run){
                return 0;
            }
            run *= oarr_shape(a, k);
        }
    } else {
        for (k = nd - 1; k >= 0; k--){
            if (oarr_shape(a, k) > 1 && a->blocks.strides[1 + k] != run){
                return 0;
            }
            run *= oarr_shape(a, k);
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_zeros_nd(void){

    static const int64_t s0[] = {0}, s1[] = {5}, s2[] = {3, 4}, s3[] = {2, 3, 4}, s4[] = {2, 1, 3, 2},
                         s5[] = {3, 0, 2}, s6[] = {2, 2, 2, 2, 2};
    const int64_t* shapes[] = {s0, s1, s2, s3, s4, s5, s6};
    const int nds[] = {0, 1, 2, 3, 4, 3, 5};
    int c, layout;
    int ok = 1;

    for (layout = 0; layout < 2; layout++){
        for (c = 0; c < 7; c++){
            oarr_t a = oarr_init();
            int k, st = oarr_zeros_nd_to(NACT, nds[c], (nds[c] > 0) ? shapes[c] : NULL, layout, TRC, &a);
            int64_t size = 1, m[MAXD];
            int b;

            ok = ok && st == OTI_OK && oarr_ndim(&a) == nds[c] && oarr_nact(&a) == NACT
                 && oarr_trc_order(&a) == TRC && oarr_act_order(&a) == 0 && oarr_capacity(&a) >= NACT
                 && a.blocks.shape[0] == NBLK && layout_ok(&a, layout) && oarr_owns(&a);
            for (k = 0; k < nds[c]; k++){
                ok = ok && oarr_shape(&a, k) == shapes[c][k];
                size *= shapes[c][k];
            }
            if (st == OTI_OK && size > 0){
                int64_t e;
                for (e = 0; e < size; e++){
                    multi_of(nds[c], shapes[c], e, m);
                    for (b = 0; b < NBLK; b++){
                        ok = ok && *at(&a, m, b) == 0.0;
                    }
                }
            }
            if (st != OTI_OK){
                fprintf(stderr, "zeros_nd case %d layout %d status %d\n", c, layout, st);
            }
            oarr_free(&a);
        }
    }
    check(ok, "zeros_nd: ranks 0-5, extents 0 / 1, both layouts: shape, nact, order, strides, zeros");

    {
        oarr_t a = oarr_init();
        int64_t neg[] = {3, -1};
        int64_t big[1] = {2};

        check(oarr_zeros_nd_to(NACT, 2, neg, ND_LAYOUT_F, TRC, &a) == DN_ERR_SIZE,
                "zeros_nd: negative extent");
        oarr_free(&a);
        check(oarr_zeros_nd_to(NACT, OTI_ND_MAXDIM, big, ND_LAYOUT_F, TRC, &a) == DN_ERR_SIZE,
              "zeros_nd: rank above the limit");
        oarr_free(&a);
        check(oarr_zeros_nd_to(NACT, 1, big, ND_LAYOUT_F, _MAXORDER_OTI + 1, &a) == DN_ERR_INDEX,
              "zeros_nd: truncation order above the maximum");
        oarr_free(&a);
        check(oarr_zeros_nd_to(NACT, 1, big, ND_LAYOUT_F, TRC, NULL) == DN_ERR_ARGUMENT,
                "zeros_nd: NULL res");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_elem_access(void){

    static const int64_t sh[] = {2, 3, 4};
    int layout;

    for (layout = 0; layout < 2; layout++){
        oarr_t a = oarr_init();
        image_t im;
        int64_t e, m[3];
        int ok = 1, b;
        otinum_t num = oti_init();

        check(make_root(&a, 3, sh, layout, 3 + layout, &im) == OTI_OK, "elem: make root");
        for (e = 0; e < im.size; e++){
            multi_of(3, sh, e, m);
            ok = ok && oarr_get_elem_to(&a, 3, m, &num) == DN_OK && num.nact == NACT
                 && num.trc_order == TRC && num.act_order == TRC && num.re == im.v[e][0];
            for (b = 1; b < NBLK && ok; b++){
                ok = ok && num.p_im[b - 1] == im.v[e][b];
            }
        }
        check(ok, layout ? "elem: every element via oarr_get_elem_to (C layout)"
                         : "elem: every element via oarr_get_elem_to (F layout)");
        {
            int64_t neg[3] = {-1, -2, -4};
            int64_t pos[3] = {1, 1, 0};
            int64_t over[3] = {2, 0, 0};
            int64_t two[2] = {0, 0};

            check(oarr_get_elem_to(&a, 3, neg, &num) == DN_OK && num.re == im.v[lin_of(3, sh, pos)][0],
                  "elem: negative indices count from the end");
            check(oarr_get_elem_to(&a, 3, over, &num) == DN_ERR_INDEX, "elem: index out of range");
            check(oarr_get_elem_to(&a, 2, two, &num) == DN_ERR_INDEX, "elem: fewer indices than axes");
        }
        oti_free(&num);
        oarr_free(&a);
    }

    {
        otinum_t s = oti_create_empty(NACT, TRC);
        oarr_t z = oarr_init();
        otinum_t back = oti_init();
        int64_t none[1] = {0};

        s.re = 2.5;
        s.p_im[0] = -1.0;
        s.p_im[4] = 0.75;
        s.act_order = TRC;
        check(oarr_from_oti_to(&s, &z) == OTI_OK && oarr_ndim(&z) == 0 && oarr_nact(&z) == NACT
              && oarr_trc_order(&z) == TRC, "from_oti: 0-D array of the scalar's layout");
        check(oarr_get_elem_to(&z, 0, none, &back) == DN_OK && back.re == 2.5 && back.p_im[0] == -1.0
              && back.p_im[4] == 0.75 && back.p_im[1] == 0.0, "from_oti: the element is the scalar");
        oti_free(&back);
        oti_free(&s);
        oarr_free(&z);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_from_real(void){

    ndarr_t d, t;
    oarr_t a = oarr_init();
    int64_t sh[2] = {3, 4};
    int64_t m[2], i, j;
    int ok = 1, layout;

    memset(&t, 0, sizeof(t));
    memset(&d, 0, sizeof(d));
    check(nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_C, 0, &d) == OTI_OK, "from_real: alloc");
    for (i = 0; i < 12; i++){
        ((double*)d.data)[i] = (double)(i + 1) / 2.0;
    }
    check(nd_view_transpose(&d, 0, NULL, &t) == OTI_OK, "from_real: transposed view of the source");

    for (layout = 0; layout < 2; layout++){
        check(oarr_from_real_nd_to(&t, TRC, layout, &a) == OTI_OK && oarr_ndim(&a) == 2
              && oarr_shape(&a, 0) == 4 && oarr_shape(&a, 1) == 3 && oarr_trc_order(&a) == TRC
              && oarr_nact(&a) == 0 && layout_ok(&a, layout),
                      "from_real: shape, order, no bases, layout");
        for (i = 0; i < 4; i++){
            for (j = 0; j < 3; j++){
                m[0] = i;
                m[1] = j;
                ok = ok && *at(&a, m, 0) == (double)(j * 4 + i + 1) / 2.0;
            }
        }
        oarr_free(&a);
    }
    check(ok, "from_real: values of a strided source, both layouts");
    nd_release(&d);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void expect_view(const oarr_t* root, const image_t* im, int nidx, const nd_index_t* key,
                        const char* name){

    oarr_t v = oarr_init();
    image_t ref, got;
    int refok = image_index(im, nidx, key, &ref);
    int st = oarr_view_index(root, nidx, key, &v);

    if (!refok){
        check(st == OTI_ERR_INDEX, name);
    } else {
        int ok = st == OTI_OK && same_as(&v, &ref) && v.meta == root->meta && oarr_is_shared(root)
                 && oarr_is_shared(&v) && oarr_nact(&v) == NACT && oarr_trc_order(&v) == TRC;
        if (ok){
            load(&v, &got);
        }
        check(ok, name);
    }
    oarr_free(&v);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_view_index(void){

    static const int64_t sh[] = {4, 3, 5};
    int layout;

    for (layout = 0; layout < 2; layout++){
        oarr_t a = oarr_init();
        image_t im;
        nd_index_t k[5];

        check(make_root(&a, 3, sh, layout, 5, &im) == OTI_OK, "view_index: root");

        k[0] = K_int(2);
        expect_view(&a, &im, 1, k, "view_index: a[2]");
        k[0] = K_int(-1);
        k[1] = K_int(1);
        expect_view(&a, &im, 2, k, "view_index: a[-1, 1]");
        k[0] = K_int(3);
        k[1] = K_int(2);
        k[2] = K_int(4);
        expect_view(&a, &im, 3, k, "view_index: full integer key gives a 0-D view");
        k[0] = K_slice(HS | HE, 1, 3, 1);
        expect_view(&a, &im, 1, k, "view_index: a[1:3]");
        k[0] = K_slice(HT, 0, 0, -1);
        k[1] = K_slice(HS | HT, 2, 0, -2);
        expect_view(&a, &im, 2, k, "view_index: a[::-1, 2::-2]");
        k[0] = K_kind(ND_IDX_ELLIPSIS);
        k[1] = K_int(-1);
        expect_view(&a, &im, 2, k, "view_index: a[..., -1]");
        k[0] = K_int(1);
        k[1] = K_kind(ND_IDX_NEWAXIS);
        k[2] = K_kind(ND_IDX_ELLIPSIS);
        k[3] = K_slice(HS | HE | HT, 0, 5, 2);
        expect_view(&a, &im, 4, k, "view_index: a[1, None, ..., 0:5:2]");
        k[0] = K_kind(ND_IDX_NEWAXIS);
        k[1] = K_kind(ND_IDX_ELLIPSIS);
        k[2] = K_kind(ND_IDX_NEWAXIS);
        expect_view(&a, &im, 3, k, "view_index: a[None, ..., None]");
        k[0] = K_slice(HS | HE, 3, 1, 1);
        expect_view(&a, &im, 1, k, "view_index: empty slice a[3:1]");
        k[0] = K_slice(HS | HE, -100, 100, 1);
        expect_view(&a, &im, 1, k, "view_index: out-of-range slice bounds clip");
        k[0] = K_int(4);
        expect_view(&a, &im, 1, k, "view_index: integer out of range -> OTI_ERR_INDEX");
        k[0] = K_int(0);
        k[1] = K_int(0);
        k[2] = K_int(0);
        k[3] = K_int(0);
        expect_view(&a, &im, 4, k, "view_index: too many indices -> OTI_ERR_INDEX");

        // writes through a view reach the root; the root's other elements are untouched
        {
            oarr_t v = oarr_init();
            nd_index_t key[2];
            image_t cur;
            int64_t m1[2] = {0, 0};
            int b;

            key[0] = K_int(1);
            key[1] = K_slice(HS | HE, 1, 3, 1);
            check(oarr_view_index(&a, 2, key, &v) == OTI_OK, "view write: view a[1, 1:3]");
            for (b = 0; b < NBLK; b++){
                *at(&v, m1, b) = 100.0 + b;
            }
            load(&a, &cur);
            check(cur.v[1 * 15 + 1 * 5 + 0][0] == 100.0 && cur.v[1 * 15 + 1 * 5][5] == 105.0
                  && cur.v[1 * 15 + 2 * 5][0] == im.v[1 * 15 + 2 * 5][0]
                  && cur.v[0 * 15 + 1 * 5][0] == im.v[0 * 15 + 1 * 5][0],
                  "view write: a write through the view reaches the root, only at its elements");
            check(oarr_is_shared(&a) == 1, "view: the root is shared while a view lives");
            oarr_free(&v);
            check(oarr_is_shared(&a) == 0, "view: the root is unshared after the view is freed");
        }
        oarr_free(&a);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Reference of a permutation of the axes.
static void image_transpose(const image_t* x, const int* axes, image_t* out){

    int64_t shape[MAXD], e, mo[MAXD], ms[MAXD];
    int k, b;

    for (k = 0; k < x->ndim; k++){
        shape[k] = x->shape[axes[k]];
    }
    image_init(out, x->ndim, shape);
    for (e = 0; e < out->size; e++){
        multi_of(out->ndim, out->shape, e, mo);
        for (k = 0; k < x->ndim; k++){
            ms[axes[k]] = mo[k];
        }
        for (b = 0; b < NBLK; b++){
            out->v[e][b] = x->v[lin_of(x->ndim, x->shape, ms)][b];
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Reference reshape in index order C (same linear order) or F (first axis fastest).
static int image_reshape(const image_t* x, int ndim, const int64_t* shape, int layout, image_t* out){

    int64_t e, ms[MAXD], mo[MAXD], size = 1, f;
    int k, b;

    for (k = 0; k < ndim; k++){
        size *= shape[k];
    }
    if (size != x->size){
        return 0;
    }
    image_init(out, ndim, shape);
    for (e = 0; e < out->size; e++){
        multi_of(ndim, shape, e, mo);
        if (layout == ND_LAYOUT_C){
            f = e;
        } else {
            int64_t run = 1;
            f = 0;
            for (k = 0; k < ndim; k++){
                f += mo[k] * run;
                run *= shape[k];
            }
        }
        if (layout == ND_LAYOUT_C){
            multi_of(x->ndim, x->shape, f, ms);
        } else {
            int64_t rem = f;
            for (k = 0; k < x->ndim; k++){
                ms[k] = rem % x->shape[k];
                rem /= x->shape[k];
            }
        }
        for (b = 0; b < NBLK; b++){
            out->v[e][b] = x->v[lin_of(x->ndim, x->shape, ms)][b];
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_transpose_reshape(void){

    static const int64_t sh[] = {2, 3, 4};
    int layout;

    for (layout = 0; layout < 2; layout++){
        oarr_t a = oarr_init();
        oarr_t v = oarr_init();
        image_t im, ref;
        int axes_rev[3] = {2, 1, 0};
        int axes_p[3] = {1, 2, 0};
        int axes_neg[3] = {-1, 0, 1};
        int axes_perm[3] = {2, 0, 1};
        int axes_rep[3] = {0, 0, 1};
        int axes_oob[3] = {0, 1, 3};
        int64_t shp[2] = {6, 4}, shm[2] = {-1, 4}, shbad[2] = {5, 5}, sh3[3] = {4, 3, 2};
        const char* tag = layout ? " (C layout)" : " (F layout)";
        char msg[160];

        check(make_root(&a, 3, sh, layout, 7, &im) == OTI_OK, "transpose: root");

        check(oarr_view_transpose(&a, 0, NULL, &v) == OTI_OK, "transpose: reversed axes status");
        image_transpose(&im, axes_rev, &ref);
        snprintf(msg, sizeof(msg), "transpose: .T is a view with reversed axes%s", tag);
        check(same_as(&v, &ref) && v.meta == a.meta && oarr_is_shared(&a), msg);
        oarr_free(&v);

        check(oarr_view_transpose(&a, 3, axes_p, &v) == OTI_OK, "transpose: axes (1, 2, 0) status");
        image_transpose(&im, axes_p, &ref);
        check(same_as(&v, &ref), "transpose: axes (1, 2, 0)");
        oarr_free(&v);

        check(oarr_view_transpose(&a, 3, axes_neg, &v) == OTI_OK, "transpose: negative axes status");
        image_transpose(&im, axes_perm, &ref);
        check(same_as(&v, &ref), "transpose: negative axes (-1, 0, 1) = (2, 0, 1)");
        oarr_free(&v);

        check(oarr_view_transpose(&a, 3, axes_rep, &v) == DN_ERR_ARGUMENT, "transpose: repeated axis");
        oarr_free(&v);
        check(oarr_view_transpose(&a, 3, axes_oob, &v) == DN_ERR_INDEX, "transpose: axis out of range");
        oarr_free(&v);
        check(oarr_view_transpose(&a, 2, axes_p, &v) == DN_ERR_ARGUMENT, "transpose: wrong axis count");
        oarr_free(&v);

        // reshape: a view when the strides allow it, else OTI_ERR_LAYOUT and the copy gives the values
        {
            int st_c = oarr_view_reshape(&a, 2, shp, ND_LAYOUT_C, &v);
            int st_f;

            image_reshape(&im, 2, shp, ND_LAYOUT_C, &ref);
            snprintf(msg, sizeof(msg), "reshape: C-order (6, 4) view status%s", tag);
            check(layout == ND_LAYOUT_C ? st_c == OTI_OK : st_c == OTI_ERR_LAYOUT, msg);
            if (st_c == OTI_OK){
                check(same_as(&v, &ref), "reshape: C-order view values");
            }
            oarr_free(&v);

            check(oarr_reshape_copy_to(&a, 2, shp, ND_LAYOUT_C, &v) == OTI_OK && same_as(&v, &ref)
                  && !oarr_is_shared(&v), "reshape_copy: C-order values, a new root");
            oarr_free(&v);

            st_f = oarr_view_reshape(&a, 2, shp, ND_LAYOUT_F, &v);
            image_reshape(&im, 2, shp, ND_LAYOUT_F, &ref);
            snprintf(msg, sizeof(msg), "reshape: F-order (6, 4) view status%s", tag);
            check(layout == ND_LAYOUT_F ? st_f == OTI_OK : st_f == OTI_ERR_LAYOUT, msg);
            if (st_f == OTI_OK){
                check(same_as(&v, &ref), "reshape: F-order view values");
            }
            oarr_free(&v);
            check(oarr_reshape_copy_to(&a, 2, shp, ND_LAYOUT_F, &v) == OTI_OK && same_as(&v, &ref),
                  "reshape_copy: F-order values");
            oarr_free(&v);
        }

        check(oarr_reshape_copy_to(&a, 2, shm, ND_LAYOUT_C, &v) == OTI_OK && oarr_shape(&v, 0) == 6
              && oarr_shape(&v, 1) == 4, "reshape: -1 is inferred");
        oarr_free(&v);
        check(oarr_view_reshape(&a, 2, shbad, ND_LAYOUT_C, &v) == DN_ERR_SIZE, "reshape: size mismatch");
        oarr_free(&v);
        (void)sh3;

        // reshape_root: an F relabel of a root compact in F order
        {
            coeff_t* before = oarr_data(&a);
            oarr_t keep = oarr_init();
            int st;

            check(oarr_view_index(&a, 0, NULL, &keep) == OTI_OK,
                    "reshape_root: a view of the whole root");
            st = oarr_reshape_root(&a, 2, shp);
            if (layout == ND_LAYOUT_F){
                image_reshape(&im, 2, shp, ND_LAYOUT_F, &ref);
                check(st == OTI_OK && oarr_data(&a) == before && same_as(&a, &ref)
                      && oarr_ndim(&keep) == 3,
                              "reshape_root: F relabel keeps the data; views keep their shape");
            } else {
                check(st == OTI_ERR_LAYOUT, "reshape_root: a root that is not compact in F order");
            }
            oarr_free(&keep);
        }
        oarr_free(&a);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// / Broadcast of an image to a shape (NumPy: trailing axes aligned, extent 1 stretched, leading 1s
// dropped).
static int image_bcast(const image_t* x, int ndim, const int64_t* shape, image_t* out){

    int64_t e, mo[MAXD], ms[MAXD];
    int k, b, lead = ndim - x->ndim;

    if (lead < 0){
        for (k = 0; k < -lead; k++){
            if (x->shape[k] != 1){
                return 0;
            }
        }
    }
    for (k = 0; k < x->ndim; k++){
        int dk = k + lead;
        if (dk >= 0 && x->shape[k] != 1 && x->shape[k] != shape[dk]){
            return 0;
        }
    }
    image_init(out, ndim, shape);
    for (e = 0; e < out->size; e++){
        multi_of(ndim, shape, e, mo);
        for (k = 0; k < x->ndim; k++){
            int dk = k + lead;
            ms[k] = (dk < 0 || x->shape[k] == 1) ? 0 : mo[dk];
        }
        for (b = 0; b < NBLK; b++){
            out->v[e][b] = x->v[lin_of(x->ndim, x->shape, ms)][b];
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_assign(void){

    static const int64_t dsh[] = {2, 3, 4};
    static const int64_t s_a[] = {4}, s_b[] = {3, 1}, s_c[] = {1, 2, 3, 4}, s_d[] = {1, 1}, s_e[] = {5},
                         s_f[] = {2, 3, 4};
    const int64_t* shapes[] = {s_a, s_b, s_c, s_d, s_e, s_f};
    const int nds[] = {1, 2, 4, 2, 1, 3};
    const char* names[] = {
        "assign: (4,) broadcast into (2, 3, 4)", "assign: (3, 1) broadcast into (2, 3, 4)",
        "assign: leading axis of extent 1 dropped ((1, 2, 3, 4) into (2, 3, 4))",
        "assign: (1, 1) broadcast into (2, 3, 4)", "assign: (5,) does not broadcast -> DN_ERR_SIZE",
        "assign: same shape"};
    int layout, c;

    for (layout = 0; layout < 2; layout++){
        for (c = 0; c < 6; c++){
            oarr_t dst = oarr_init();
            oarr_t src = oarr_init();
            image_t idst, isrc, expect;
            int st, ok;
            char msg[200];

            make_root(&dst, 3, dsh, layout, 1, &idst);
            make_root(&src, nds[c], shapes[c], 1 - layout, 2, &isrc);
            st = oarr_assign_to(&src, &dst);
            if (c == 4){
                snprintf(msg, sizeof(msg), "%s (dst layout %d)", names[c], layout);
                check(st == DN_ERR_SIZE && same_as(&dst, &idst), msg);
            } else {
                ok = image_bcast(&isrc, 3, dsh, &expect);
                snprintf(msg, sizeof(msg), "%s (dst layout %d)", names[c], layout);
                check(ok && st == DN_OK && same_as(&dst, &expect), msg);
            }
            oarr_free(&dst);
            oarr_free(&src);
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// A root over nact bases / order trc with every block filled from value() (tag), shape (2, 3).
static void make_big(oarr_t* a, bases_t nact, ord_t trc, int tag){

    static const int64_t sh[2] = {2, 3};
    int64_t e, m[2];
    uint64_t nblk, b;

    oarr_zeros_nd_to(nact, 2, sh, ND_LAYOUT_F, trc, a);
    nblk = (uint64_t)a->blocks.shape[0];
    for (e = 0; e < 6; e++){
        multi_of(2, sh, e, m);
        for (b = 0; b < nblk; b++){
            *at(a, m, (int)b) = value(tag, e, (int)(b % 13));
        }
    }
    oarr_set_act_order(a, trc);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Tuples of one order, for the direction ordering (nondecreasing base lists).
typedef struct {
    int c[8];
} tuple_t;

static int g_p;   ///< Order of the tuples being sorted (comparison helper).
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Global direction order inside one order: by the largest base first, then the next largest, and so on
/// (so a new base only appends directions: the index of a direction does not depend on nact).
static int tuple_cmp(const void* x, const void* y){

    const tuple_t* a = (const tuple_t*)x;
    const tuple_t* b = (const tuple_t*)y;
    int i;

    for (i = g_p - 1; i >= 0; i--){
        if (a->c[i] != b->c[i]){
            return (a->c[i] < b->c[i]) ? -1 : 1;
        }
    }
    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/// Block of the monomial e1^a * e2^b over k bases (order p = a + b): 1 + (directions of lower orders) +
/// the rank of the base list (1^a 2^b) among all nondecreasing lists of length p over 1..k in the global
/// direction order.
static int blk_of(int k, int a, int b){

    int p = a + b, order, off = 1, n = 0, i, rank = -1;
    static tuple_t list[2048];
    tuple_t cur;

    if (p == 0){
        return 0;
    }
    for (order = 1; order < p; order++){
        int cnt = 1, d;
        for (d = 1; d <= order; d++){
            cnt = cnt * (k + d - 1) / d;
        }
        off += cnt;
    }
    for (i = 0; i < p; i++){
        cur.c[i] = 1;
    }
    for (;;){
        list[n++] = cur;
        i = p - 1;
        while (i >= 0 && cur.c[i] == k){
            i--;
        }
        if (i < 0){
            break;
        }
        cur.c[i]++;
        {
            int j;
            for (j = i + 1; j < p; j++){
                cur.c[j] = cur.c[i];
            }
        }
    }
    g_p = p;
    qsort(list, (size_t)n, sizeof(tuple_t), tuple_cmp);
    for (i = 0; i < n; i++){
        int j, match = 1;
        for (j = 0; j < p; j++){
            if (list[i].c[j] != ((j < a) ? 1 : 2)){
                match = 0;
            }
        }
        if (match){
            rank = i;
        }
    }
    return (rank < 0) ? -1 : off + rank;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_block_order(void){

    int ok = 1, b;

    for (b = 0; b < NBLK; b++){
        ok = ok && blk_of(NACT, MON[b][0], MON[b][1]) == b;
    }
    check(ok, "block order: the test's monomial table agrees with the 2-base global direction order");
    check(blk_of(3, 1, 0) == 1 && blk_of(3, 0, 1) == 2 && blk_of(3, 2, 0) == 4 && blk_of(3, 1, 1) == 5
          && blk_of(3, 0, 2) == 6,
                  "block order: 3 bases, order 2 is (1,1) (1,2) (2,2) (1,3) (2,3) (3,3)");
    {
        int ok2 = 1, i;

        for (i = 0; i < 3; i++){
            ok2 = ok2 && oarr_block_index(3, 1, (ndir_t)i) == (uint64_t)(1 + i);
        }
        for (i = 0; i < 6; i++){
            ok2 = ok2 && oarr_block_index(3, 2, (ndir_t)i) == (uint64_t)(4 + i);
        }
        ok2 = ok2 && oarr_block_index(3, 0, 0) == 0;
        check(ok2,
                "block order: oarr_block_index() for 3 bases (order 1: blocks 1-3, order 2: blocks 4-9)");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_assign_growth_and_fit(void){

    oarr_t dst = oarr_init();
    oarr_t src = oarr_init();
    oarr_t view = oarr_init();
    image_t idst, before;
    int ok, b;

    // unshared root grows to the layout of src
    make_root(&dst, 2, (int64_t[]){2, 3}, ND_LAYOUT_F, 1, &idst);
    make_big(&src, 3, TRC, 4);
    check(oarr_assign_to(&src, &dst) == DN_OK && oarr_nact(&dst) == 3 && oarr_trc_order(&dst) == TRC,
          "assign growth: an unshared root grows to src's bases");
    {
        int64_t m[2];
        ok = 1;
        for (b = 0; b < 10; b++){
            multi_of(2, (int64_t[]){2, 3}, 4, m);
            ok = ok && *at(&dst, m, b) == *at(&src, m, b);
        }
        check(ok, "assign growth: every block of src is in dst");
    }
    oarr_free(&dst);

    // a shared root (live view) or a view must already hold src's layout, else BUSY and nothing changes
    make_root(&dst, 2, (int64_t[]){2, 3}, ND_LAYOUT_F, 1, &idst);
    check(oarr_view_index(&dst, 0, NULL, &view) == OTI_OK, "assign fit: view of dst");
    load(&dst, &before);
    check(oarr_assign_to(&src, &dst) == OTI_ERR_BUSY && same_as(&dst, &before) && oarr_nact(&dst) == NACT,
          "assign fit: shared root, src needs more bases -> OTI_ERR_BUSY, nothing changes");
    check(oarr_assign_to(&src, &view) == OTI_ERR_BUSY && same_as(&dst, &before),
          "assign fit: view dst, src needs more bases -> OTI_ERR_BUSY");
    oarr_free(&src);

    // a src with fewer bases and a lower order fits: its directions land, the others are zero
    {
        oarr_t small = oarr_init();
        int64_t m[2];
        int64_t sh[2] = {2, 3};

        oarr_zeros_nd_to(1, 2, sh, ND_LAYOUT_C, 1, &small);
        multi_of(2, sh, 4, m);
        *at(&small, m, 0) = 9.0;
        *at(&small, m, 1) = -3.0;
        oarr_set_act_order(&small, 1);
        check(oarr_assign_to(&small, &view) == DN_OK,
                "assign fit: src of 1 base, order 1 into a shared 2-base root");
        ok = *at(&dst, m, 0) == 9.0 && *at(&dst, m, blk_of(2, 1, 0)) == -3.0
             && *at(&dst, m, blk_of(2, 0, 1)) == 0.0 && *at(&dst, m, blk_of(2, 1, 1)) == 0.0
             && *at(&dst, m, blk_of(2, 2, 0)) == 0.0 && oarr_nact(&dst) == NACT
             && oarr_trc_order(&dst) == TRC && oarr_act_order(&dst) == TRC;
        check(ok, "assign fit: missing directions are zero, nact / order / act_order are kept");
        oarr_free(&small);
    }
    oarr_free(&view);
    oarr_free(&dst);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_assign_snapshot(void){

    static const int64_t sh6[1] = {6}, sh33[2] = {3, 3};
    oarr_t a = oarr_init();
    oarr_t lo = oarr_init();
    oarr_t hi = oarr_init();
    oarr_t t = oarr_init();
    image_t im, expect, r1, r2;
    nd_index_t k[1];
    int e;

    make_root(&a, 1, sh6, ND_LAYOUT_F, 3, &im);
    k[0] = K_slice(HS, 1, 0, 0);
    check(oarr_view_index(&a, 1, k, &hi) == OTI_OK, "snapshot: a[1:]");
    k[0] = K_slice(HE, 0, -1, 0);
    check(oarr_view_index(&a, 1, k, &lo) == OTI_OK, "snapshot: a[:-1]");
    check(oarr_assign_to(&lo, &hi) == DN_OK, "snapshot: a[1:] = a[:-1]");
    expect = im;
    for (e = 1; e < 6; e++){
        memcpy(expect.v[e], im.v[e - 1], sizeof(expect.v[e]));
    }
    check(same_as(&a, &expect),
            "snapshot: overlapping assignment equals a copy of the source first (S2)");
    oarr_free(&lo);
    oarr_free(&hi);
    oarr_free(&a);

    {
        int axes[2] = {1, 0};

        make_root(&a, 2, sh33, ND_LAYOUT_F, 4, &im);
        check(oarr_view_transpose(&a, 0, NULL, &t) == OTI_OK, "snapshot: a.T");
        check(oarr_assign_to(&t, &a) == DN_OK, "snapshot: a[...] = a.T");
        image_transpose(&im, axes, &expect);
        check(same_as(&a, &expect), "snapshot: a = a.T gives the transpose of the old values (S2)");
        (void)r1;
        (void)r2;
    }
    oarr_free(&t);
    oarr_free(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void make_i64(ndarr_t* d, int n, const int64_t* v){

    int64_t sh[1];
    int k;

    sh[0] = n;
    memset(d, 0, sizeof(*d));
    nd_alloc(NULL, OTI_I64, 1, sh, ND_LAYOUT_C, 0, d);
    for (k = 0; k < n; k++){
        ((int64_t*)d->data)[k] = v[k];
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void make_mask(ndarr_t* d, int n, const uint8_t* v){

    int64_t sh[1];
    int k;

    sh[0] = n;
    memset(d, 0, sizeof(*d));
    nd_alloc(NULL, OTI_U8, 1, sh, ND_LAYOUT_C, 0, d);
    for (k = 0; k < n; k++){
        ((uint8_t*)d->data)[k] = v[k];
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_index_get_advanced(void){

    static const int64_t sh[] = {4, 3, 5};
    oarr_t a = oarr_init();
    oarr_t r = oarr_init();
    image_t im, ref;
    ndarr_t ia, ib, ic, mk, mbad;
    nd_index_t k[3];
    const int64_t i1[3] = {3, 0, 3}, i2[2] = {2, 0}, i3[2] = {1, 7};
    const uint8_t m1[4] = {1, 0, 1, 1}, m2[3] = {1, 1, 0};
    int64_t e, mo[3];
    int ok, b, layout;

    for (layout = 0; layout < 2; layout++){
        make_root(&a, 3, sh, layout, 6, &im);
        make_i64(&ia, 3, i1);
        make_i64(&ib, 2, i2);
        make_i64(&ic, 2, i3);
        make_mask(&mk, 4, m1);
        make_mask(&mbad, 3, m2);

        // a[[3, 0, 3]]
        memset(k, 0, sizeof(k));
        k[0].kind = ND_IDX_ARRAY;
        k[0].arr = &ia;
        check(oarr_index_get_to(&a, 1, k, &r) == OTI_OK && oarr_ndim(&r) == 3 && oarr_shape(&r, 0) == 3
              && !oarr_is_shared(&r) && oarr_owns(&r),
                      "index_get: a[[3, 0, 3]] is a new root of shape (3, 3, 5)");
        ok = 1;
        for (e = 0; e < 3 * 15; e++){
            multi_of(3, (int64_t[]){3, 3, 5}, e, mo);
            for (b = 0; b < NBLK; b++){
                ok = ok && *at(&r, mo, b) == im.v[i1[mo[0]] * 15 + mo[1] * 5 + mo[2]][b];
            }
        }
        check(ok, "index_get: a[[3, 0, 3]] values (a repeated row twice)");
        {
            int64_t m0[3] = {0, 0, 0};
            *at(&r, m0, 0) = 12345.0;
            check(*at(&a, (int64_t[]){3, 0, 0}, 0) == im.v[45][0], "index_get: the result is a copy");
        }
        oarr_free(&r);

        // a[mask] with a boolean mask on axis 0
        k[0].arr = &mk;
        check(oarr_index_get_to(&a, 1, k, &r) == OTI_OK && oarr_shape(&r, 0) == 3 && oarr_shape(&r,
                1) == 3,
              "index_get: a[mask] has one row per true entry");
        ok = 1;
        for (e = 0; e < 3 * 15; e++){
            static const int rows[3] = {0, 2, 3};
            multi_of(3, (int64_t[]){3, 3, 5}, e, mo);
            for (b = 0; b < NBLK; b++){
                ok = ok && *at(&r, mo, b) == im.v[rows[mo[0]] * 15 + mo[1] * 5 + mo[2]][b];
            }
        }
        check(ok, "index_get: a[mask] values");
        oarr_free(&r);

        // a[:, [2, 0]]
        k[0] = K_slice(0, 0, 0, 0);
        k[1].kind = ND_IDX_ARRAY;
        k[1].arr = &ib;
        check(oarr_index_get_to(&a, 2, k, &r) == OTI_OK && oarr_ndim(&r) == 3 && oarr_shape(&r, 0) == 4
              && oarr_shape(&r, 1) == 2 && oarr_shape(&r, 2) == 5,
                      "index_get: a[:, [2, 0]] shape (4, 2, 5)");
        ok = 1;
        for (e = 0; e < 4 * 2 * 5; e++){
            multi_of(3, (int64_t[]){4, 2, 5}, e, mo);
            for (b = 0; b < NBLK; b++){
                ok = ok && *at(&r, mo, b) == im.v[mo[0] * 15 + i2[mo[1]] * 5 + mo[2]][b];
            }
        }
        check(ok, "index_get: a[:, [2, 0]] values");
        oarr_free(&r);

        // errors
        k[0] = K_kind(ND_IDX_ARRAY);
        k[0].arr = &ic;
        k[1] = K_kind(ND_IDX_ELLIPSIS);
        check(oarr_index_get_to(&a, 2, k, &r) == OTI_ERR_INDEX,
                "index_get: array index out of range -> OTI_ERR_INDEX");
        oarr_free(&r);
        k[0].arr = &mbad;
        {
            int st = oarr_index_get_to(&a, 1, k, &r);
            check(st == OTI_ERR_INDEX || st == OTI_ERR_SHAPE,
                    "index_get: mask of the wrong length is refused");
        }
        oarr_free(&r);

        nd_release(&ia);
        nd_release(&ib);
        nd_release(&ic);
        nd_release(&mk);
        nd_release(&mbad);
        oarr_free(&a);
    }
    (void)ref;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_index_set(void){

    static const int64_t sh[] = {4, 3, 5};
    oarr_t a = oarr_init();
    oarr_t src = oarr_init();
    image_t im, isrc, cur, expect;
    ndarr_t ia;
    nd_index_t k[3];
    const int64_t dup[3] = {1, 1, 2};
    int ok, b, layout;
    int64_t e, mo[3];

    for (layout = 0; layout < 2; layout++){
        // advanced: a[[1, 1, 2]] = src (3, 3, 5): the last write wins for the duplicate
        make_root(&a, 3, sh, layout, 8, &im);
        make_root(&src, 3, (int64_t[]){3, 3, 5}, 1 - layout, 9, &isrc);
        make_i64(&ia, 3, dup);
        memset(k, 0, sizeof(k));
        k[0].kind = ND_IDX_ARRAY;
        k[0].arr = &ia;
        check(oarr_index_set(&a, 1, k, &src) == DN_OK, "index_set: a[[1, 1, 2]] = src status");
        expect = im;
        for (e = 0; e < 15; e++){
            for (b = 0; b < NBLK; b++){
                expect.v[1 * 15 + e][b] = isrc.v[1 * 15 + e][b];   // last of the duplicates is src row 1
                expect.v[2 * 15 + e][b] = isrc.v[2 * 15 + e][b];
            }
        }
        check(same_as(&a, &expect),
                "index_set: advanced set, duplicates: the last write wins; others untouched");
        nd_release(&ia);
        oarr_free(&src);

        // basic with broadcast: a[1:3, ::2] = src (5,)
        make_root(&src, 1, (int64_t[]){5}, layout, 10, &isrc);
        k[0] = K_slice(HS | HE, 1, 3, 0);
        k[1] = K_slice(HT, 0, 0, 2);
        check(oarr_index_set(&a, 2, k, &src) == DN_OK, "index_set: a[1:3, ::2] = src (5,) status");
        for (e = 1; e < 3; e++){
            int64_t j;
            for (j = 0; j < 3; j += 2){
                int64_t t;
                for (t = 0; t < 5; t++){
                    for (b = 0; b < NBLK; b++){
                        expect.v[e * 15 + j * 5 + t][b] = isrc.v[t][b];
                    }
                }
            }
        }
        check(same_as(&a, &expect), "index_set: basic set broadcasts src over the region only");
        oarr_free(&src);

        // a key error leaves the array untouched
        make_root(&src, 1, (int64_t[]){5}, layout, 10, &isrc);
        load(&a, &cur);
        k[0] = K_int(4);
        check(oarr_index_set(&a, 1, k, &src) == OTI_ERR_INDEX && same_as(&a, &cur),
              "index_set: key out of range -> OTI_ERR_INDEX, nothing changes");
        oarr_free(&src);

        // a scalar into one element, in place
        {
            otinum_t num = oti_create_empty(NACT, TRC);
            coeff_t* before = oarr_data(&a);

            num.re = 3.5;
            num.p_im[2] = -0.5;
            num.p_im[4] = 2.0;
            num.act_order = TRC;
            k[0] = K_int(2);
            k[1] = K_int(-1);
            k[2] = K_int(0);
            check(oarr_index_set_o(&a, 3, k, &num) == DN_OK && oarr_data(&a) == before,
                  "index_set_o: a[2, -1, 0] = scalar, in place");
            load(&a, &cur);
            expect = cur;
            ok = cur.v[2 * 15 + 2 * 5][0] == 3.5 && cur.v[2 * 15 + 2 * 5][3] == -0.5
                 && cur.v[2 * 15 + 2 * 5][5] == 2.0 && cur.v[2 * 15 + 2 * 5][1] == 0.0;
            check(ok, "index_set_o: the element holds the scalar's coefficients (missing ones zero)");
            oti_free(&num);
        }

        // a real: every direction of the region becomes zero, the real part is the value
        k[0] = K_int(0);
        check(oarr_index_set_r(&a, 1, k, 7.0) == DN_OK, "index_set_r: a[0] = 7.0 status");
        load(&a, &cur);
        ok = 1;
        for (e = 0; e < 15; e++){
            ok = ok && cur.v[e][0] == 7.0;
            for (b = 1; b < NBLK; b++){
                ok = ok && cur.v[e][b] == 0.0;
            }
        }
        ok = ok && oarr_nact(&a) == NACT && cur.v[15][0] != 7.0;
        check(ok, "index_set_r: region set to the real, directions zero, no growth, rest untouched");
        (void)mo;
        oarr_free(&a);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_grow_layout(void){

    static const int64_t sh[] = {2, 3};
    oarr_t a = oarr_init();
    oarr_t v = oarr_init();
    ndarr_t ex;
    image_t im;
    int64_t m[2];
    int ok, b;
    coeff_t* p;

    make_root(&a, 2, sh, ND_LAYOUT_F, 3, &im);
    p = oarr_data(&a);
    check(oarr_grow_layout(&a, 2, 1) == DN_OK && oarr_data(&a) == p && oarr_nact(&a) == NACT,
          "grow_layout: a layout already held changes nothing");
    check(oarr_grow_layout(&a, 3, 3) == DN_OK && oarr_nact(&a) == 3 && oarr_trc_order(&a) == 3,
          "grow_layout: an unshared root grows (nact 3, order 3)");
    ok = 1;
    for (b = 0; b < NBLK; b++){
        int64_t e;
        for (e = 0; e < 6; e++){
            multi_of(2, sh, e, m);
            ok = ok && *at(&a, m, blk_of(3, MON[b][0], MON[b][1])) == im.v[e][b];
        }
    }
    check(ok, "grow_layout: every old coefficient is at its monomial's new block");
    ok = 1;
    for (b = 0; b < (int)a.blocks.shape[0]; b++){
        int found = 0, t;
        for (t = 0; t < NBLK; t++){
            found = found || blk_of(3, MON[t][0], MON[t][1]) == b;
        }
        if (!found){
            int64_t e;
            for (e = 0; e < 6; e++){
                multi_of(2, sh, e, m);
                ok = ok && *at(&a, m, b) == 0.0;
            }
        }
    }
    check(ok, "grow_layout: the new directions are zero");

    check(oarr_view_index(&a, 0, NULL, &v) == OTI_OK, "grow_layout: view");
    check(oarr_grow_layout(&a, 3, 3) == DN_OK, "grow_layout: a held layout is fine with live views");
    check(oarr_grow_layout(&a, 4, 3) == OTI_ERR_BUSY && oarr_nact(&a) == 3,
          "grow_layout: growth with a live view -> OTI_ERR_BUSY, unchanged");
    check(oarr_grow_layout(&v, 4, 3) == OTI_ERR_BUSY,
            "grow_layout: growth through a view -> OTI_ERR_BUSY");
    oarr_free(&v);
    check(oarr_grow_layout(&a, 4, 3) == DN_OK && oarr_nact(&a) == 4,
            "grow_layout: grows once the view is gone");

    check(nd_export(&a.blocks, 0, &ex) == OTI_OK && oarr_is_shared(&a),
            "grow_layout: export pins the layout");
    check(oarr_grow_layout(&a, 5, 3) == OTI_ERR_BUSY,
            "grow_layout: growth with an export -> OTI_ERR_BUSY");
    nd_release(&ex);
    check(oarr_grow_layout(&a, 5, 3) == DN_OK && oarr_nact(&a) == 5,
            "grow_layout: grows after the export ends");
    oarr_free(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_reservation(void){

    static const int64_t sh[] = {2, 3};
    oarr_t dst = oarr_init();
    oarr_t src = oarr_init();
    oarr_t v = oarr_init();
    image_t isrc;
    coeff_t* p;
    bases_t cap;
    int64_t m[2];
    int ok, b;

    oarr_zeros_nd_to(4, 2, sh, ND_LAYOUT_F, 3, &dst);
    p = oarr_data(&dst);
    cap = oarr_capacity(&dst);
    check(oarr_nact(&dst) == 4 && oarr_trc_order(&dst) == 3 && oarr_act_order(&dst) == 0 && cap >= 4,
          "reserve: zeros_nd_to(4 bases, order 3) holds the layout with act_order 0");

    make_root(&src, 2, sh, ND_LAYOUT_F, 5, &isrc);
    check(oarr_view_index(&dst, 0, NULL, &v) == OTI_OK, "reserve: a live view pins the reserved root");
    check(oarr_assign_to(&src, &dst) == DN_OK && oarr_data(&dst) == p && oarr_capacity(&dst) == cap
          && oarr_nact(&dst) == 4 && oarr_trc_order(&dst) == 3,
                  "reserve: values over fewer bases fit; no relayout");
    ok = 1;
    for (b = 0; b < NBLK; b++){
        int64_t e;
        for (e = 0; e < 6; e++){
            multi_of(2, sh, e, m);
            ok = ok && *at(&dst, m, blk_of(4, MON[b][0], MON[b][1])) == isrc.v[e][b];
        }
    }
    check(ok, "reserve: the values are at the 4-base block positions");
    check(oarr_act_order(&dst) == TRC, "reserve: act_order is raised to the value's order");
    oarr_free(&src);

    make_big(&src, 5, 2, 6);
    check(oarr_assign_to(&src, &dst) == OTI_ERR_BUSY && oarr_nact(&dst) == 4,
          "reserve: a value over more bases than reserved -> OTI_ERR_BUSY while shared");
    oarr_free(&v);
    check(oarr_assign_to(&src, &dst) == DN_OK && oarr_nact(&dst) == 5,
            "reserve: unshared, the same value grows it");
    oarr_free(&src);
    oarr_free(&dst);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_kernels_non_compact(void){

    static const int64_t sha[] = {4, 3, 5};
    oarr_t a = oarr_init();
    oarr_t b = oarr_init();
    oarr_t va = oarr_init();
    oarr_t vb = oarr_init();
    oarr_t r = oarr_init();
    image_t ia, ib, ra, rb, ref;
    nd_index_t ka[3], kb[3];

    make_root(&a, 3, sha, ND_LAYOUT_F, 11, &ia);
    make_root(&b, 3, sha, ND_LAYOUT_C, 12, &ib);

    // (2, 3, 3) strided / reversed view times a (3,) row of the other layout (broadcast)
    ka[0] = K_slice(HT, 0, 0, 2);
    ka[1] = K_slice(HT, 0, 0, -1);
    ka[2] = K_slice(HS | HE, 1, 4, 0);
    kb[0] = K_int(1);
    kb[1] = K_int(0);
    kb[2] = K_slice(HS | HE, 1, 4, 0);
    oarr_view_index(&a, 3, ka, &va);
    oarr_view_index(&b, 3, kb, &vb);
    image_index(&ia, 3, ka, &ra);
    image_index(&ib, 3, kb, &rb);
    check(oarr_mul_OO_to(&va, &vb, &r, g_dhl) == DN_OK && image_mul(&ra, &rb, &ref) && same_as(&r, &ref),
          "kernels: strided + reversed view * row of another layout, broadcast (2, 3, 3) * (3,)");
    oarr_free(&r);
    oarr_free(&va);
    oarr_free(&vb);

    // (3, 1) * (4,) -> (3, 4)
    ka[0] = K_int(0);
    ka[1] = K_slice(0, 0, 0, 0);
    ka[2] = K_slice(HS | HE, 0, 1, 0);
    kb[0] = K_int(1);
    kb[1] = K_int(0);
    kb[2] = K_slice(HS | HE, 0, 4, 0);
    oarr_view_index(&a, 3, ka, &va);
    oarr_view_index(&b, 3, kb, &vb);
    image_index(&ia, 3, ka, &ra);
    image_index(&ib, 3, kb, &rb);
    check(oarr_mul_OO_to(&va, &vb, &r, g_dhl) == DN_OK && image_mul(&ra, &rb, &ref) && same_as(&r, &ref)
          && oarr_ndim(&r) == 2 && oarr_shape(&r, 0) == 3 && oarr_shape(&r, 1) == 4,
          "kernels: (3, 1) view * (4,) view -> (3, 4)");
    oarr_free(&r);
    oarr_free(&va);
    oarr_free(&vb);

    // shapes that do not broadcast
    ka[0] = K_slice(HS | HE, 0, 2, 0);
    oarr_view_index(&a, 1, ka, &va);   // (2, 3, 5)
    kb[0] = K_slice(HS | HE, 0, 3, 0);
    oarr_view_index(&b, 1, kb, &vb);   // (3, 3, 5)
    check(oarr_mul_OO_to(&va, &vb, &r, g_dhl) == DN_ERR_SIZE,
            "kernels: (2, 3, 5) * (3, 3, 5) -> DN_ERR_SIZE");
    oarr_free(&r);
    oarr_free(&va);
    oarr_free(&vb);

    // a unary function of a transposed view
    {
        int axes[3] = {2, 0, 1};

        check(oarr_view_transpose(&a, 3, (int32_t[]){2, 0, 1}, &va) == OTI_OK,
                "kernels: transposed view");
        image_transpose(&ia, axes, &ra);
        check(oarr_neg_to(&va, &r, g_dhl) == DN_OK && oarr_ndim(&r) == 3,
                "kernels: neg of a transposed view status");
        {
            image_t neg = ra;
            int64_t e;
            int bb;
            for (e = 0; e < neg.size; e++){
                for (bb = 0; bb < NBLK; bb++){
                    neg.v[e][bb] = -ra.v[e][bb];
                }
            }
            check(same_as(&r, &neg), "kernels: neg of a transposed view, values and shape");
        }
        oarr_free(&r);
        oarr_free(&va);
    }
    oarr_free(&a);
    oarr_free(&b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_out_view(void){

    static const int64_t sh[] = {4, 3, 5};
    oarr_t a = oarr_init();
    oarr_t b = oarr_init();
    oarr_t root = oarr_init();
    oarr_t out = oarr_init();
    oarr_t va = oarr_init();
    oarr_t vb = oarr_init();
    image_t ia, ib, ir, ra, rb, ref, cur, expect;
    nd_index_t k[3], ko[3];
    int ok, e, bb;

    make_root(&a, 3, sh, ND_LAYOUT_F, 13, &ia);
    make_root(&b, 3, sh, ND_LAYOUT_C, 14, &ib);
    make_root(&root, 3, sh, ND_LAYOUT_F, 15, &ir);

    // out = view root[1:3, ::2, 0:3] of shape (2, 2, 3), operands a[0:2, 0:3:2, 1:4] and b[2:4, 1:3, 2:5]
    k[0] = K_slice(HS | HE, 0, 2, 0);
    k[1] = K_slice(HS | HE | HT, 0, 3, 2);
    k[2] = K_slice(HS | HE, 1, 4, 0);
    oarr_view_index(&a, 3, k, &va);
    image_index(&ia, 3, k, &ra);
    k[0] = K_slice(HS | HE, 2, 4, 0);
    k[1] = K_slice(HS | HE, 1, 3, 0);
    k[2] = K_slice(HS | HE, 2, 5, 0);
    oarr_view_index(&b, 3, k, &vb);
    image_index(&ib, 3, k, &rb);
    image_mul(&ra, &rb, &ref);
    ko[0] = K_slice(HS | HE, 1, 3, 0);
    ko[1] = K_slice(HT, 0, 0, 2);
    ko[2] = K_slice(HS | HE, 0, 3, 0);
    check(oarr_view_index(&root, 3, ko, &out) == OTI_OK && oarr_shape(&out, 0) == 2 && oarr_shape(&out,
            1) == 2
          && oarr_shape(&out, 2) == 3, "out view: root[1:3, ::2, 0:3] shape (2, 2, 3)");
    check(oarr_mul_OO_to(&va, &vb, &out, g_dhl) == DN_OK, "out view: product written into the view");
    expect = ir;
    for (e = 0; e < 2; e++){
        int j;
        for (j = 0; j < 2; j++){
            int t;
            for (t = 0; t < 3; t++){
                for (bb = 0; bb < NBLK; bb++){
                    expect.v[(1 + e) * 15 + (2 * j) * 5 + t][bb] = ref.v[e * 6 + j * 3 + t][bb];
                }
            }
        }
    }
    check(same_as(&root, &expect),
            "out view: the product reaches the root at the view's elements, nothing else");
    check(oarr_nact(&root) == NACT && oarr_trc_order(&root) == TRC,
            "out view: the root's layout is unchanged");

    // out = view of the left operand's own root (aliasing)
    oarr_free(&out);
    oarr_free(&va);
    oarr_free(&vb);
    {
        oarr_t whole = oarr_init();
        image_t sq;

        check(oarr_view_index(&a, 0, NULL, &whole) == OTI_OK, "out view: whole view of a");
        image_mul(&ia, &ib, &sq);
        check(oarr_mul_OO_to(&a, &b, &whole, g_dhl) == DN_OK && same_as(&a, &sq),
              "out view: a *= b through a view of a (res aliases an operand)");
        oarr_free(&whole);
    }

    // a result that does not fit the root's layout: BUSY, nothing changes
    {
        static const int64_t sh2[] = {2, 3};
        oarr_t small = oarr_init();
        oarr_t sv = oarr_init();
        oarr_t x = oarr_init();
        oarr_t y = oarr_init();
        image_t ix, iy;
        coeff_t snap[2 * 6];   // 1 base, order 1: 2 blocks of 6 elements

        oarr_zeros_nd_to(1, 2, sh2, ND_LAYOUT_F, 1, &small);
        make_root(&x, 2, sh2, ND_LAYOUT_F, 16, &ix);
        make_root(&y, 2, sh2, ND_LAYOUT_F, 17, &iy);
        check(oarr_view_index(&small, 0, NULL, &sv) == OTI_OK, "out view: shared small root");
        memcpy(snap, oarr_data(&small), sizeof(snap));
        ok = oarr_mul_OO_to(&x, &y, &sv, g_dhl) == OTI_ERR_BUSY
             && memcmp(snap, oarr_data(&small), sizeof(snap)) == 0
             && oarr_nact(&small) == 1 && oarr_trc_order(&small) == 1;
        check(ok,
                "out view: a product that does not fit the root -> BUSY, never clipped");
        oarr_free(&sv);
        oarr_free(&small);
        oarr_free(&x);
        oarr_free(&y);
    }

    oarr_free(&root);
    oarr_free(&a);
    oarr_free(&b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    setvbuf(stdout, NULL, _IONBF, 0);   // a debug assertion must not lose the progress lines
    dhelp_load(NULL, &g_dhl);

    test_block_order();
    test_zeros_nd();
    test_elem_access();
    test_from_real();
    test_view_index();
    test_transpose_reshape();
    test_assign();
    test_assign_growth_and_fit();
    test_assign_snapshot();
    test_index_get_advanced();
    test_index_set();
    test_grow_layout();
    test_reservation();
    test_kernels_non_compact();
    test_out_view();

    dhelp_free(&g_dhl);
    if (n_failed != 0){
        fprintf(stderr, "%d check(s) FAILED\n", n_failed);
        return 1;
    }
    printf("all checks passed\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
