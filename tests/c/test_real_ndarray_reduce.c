/* Tests of the ndarray reductions (include/oti/real/ndarray/reduce.h, Phase 2): nd_reduce, nd_reduce_to,
 * nd_pairwise_sum, nd_tree_combine.
 *
 * Written from PLAN-ndarray-contracts.md (rows 3.4 reduction overlap, 5.4 determinism) and reduce.h,
 * independently of src/c/real/ndarray/reduce.c. Oracles: (1) the documented summation written in this
 * file
 * (the pairwise scheme of nd_pairwise_sum, the pairwise tree over blocks of OTI_EXEC_CHUNK_ELEMS, the
 * identity added last), compared BITWISE for 1-D inputs and single-axis reductions; (2) a generic
 * definition-by-coordinates reference with long double accumulation, compared exactly on small integers
 * (where every summation order gives the same value) and to 1e-12 for mean / var / std; (3) bit
 * identity of results at 1, 2, 3, 5, N threads and under the serial backend on adversarial data
 * (cancellation, mixed magnitudes, NaN, -0.0). Argmin / argmax follow NumPy: first occurrence in C order,
 * the first NaN wins. The reduction code of an array is tested in random layouts (C, F, slices with
 * negative and doubled steps). */
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
#include <oti/real/ndarray/reduce.h>

static int n_failed = 0;
static uint64_t g_rng_state;

#define HS 0x1
#define HP 0x2
#define HT 0x4


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
static double rng_uniform(void){

    return (double)(rng_next() >> 11) / (double)(1ULL << 53);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int same_bits(double a, double b){

    if (isnan(a) && isnan(b)){
        return 1;
    }
    return memcmp(&a, &b, sizeof(double)) == 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int same_num(double a, double b){

    if (isnan(a) && isnan(b)){
        return 1;
    }
    return a == b;

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
// Pointer to the element of logical C-order position `lin` of any-dtype array.
static void* elem_ptr(const ndarr_t* a, int64_t lin){

    int64_t off = 0, rem = lin;
    int32_t k;

    for (k = a->ndim - 1; k >= 0; k--){
        off += (rem % a->shape[k]) * a->strides[k];
        rem /= a->shape[k];
    }
    return (char*)a->data + off * nd_itemsize(a->dtype);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double get_f(const ndarr_t* a, int64_t lin){

    return *(double*)elem_ptr(a, lin);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void set_f(ndarr_t* a, int64_t lin, double v){

    *(double*)elem_ptr(a, lin) = v;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Per-axis recipe for a test view: plain, reversed (step -1) or doubled (step 2 over a double-size base).
// `kind` picks one of: 0 C base, 1 F base, 2 random slices over a bigger base.
static void make_view(int32_t nd, const int64_t* shape, int kind, int32_t dtype, ndarr_t* base,
        ndarr_t* view){

    int64_t big[OTI_ND_MAXDIM];
    nd_index_t idx[OTI_ND_MAXDIM];
    int32_t k;
    int st;

    for (k = 0; k < nd; k++){
        int64_t pick = (kind == 2 && shape[k] > 0) ? rng_int(3) : 0;
        big[k] = (pick == 2) ? 2 * shape[k] : shape[k];
        if (pick == 0){
            idx[k] = mk_slice(0, 0, 0, 0);
        } else if (pick == 1){
            idx[k] = mk_slice(HS | HT, shape[k] - 1, 0, -1);
        } else {
            idx[k] = mk_slice(HS | HT, 0, 0, 2);
        }
    }
    st = nd_alloc(NULL, dtype, nd, big, kind == 1 ? ND_LAYOUT_F : ND_LAYOUT_C, ND_ALLOC_ZERO, base);
    if (st != OTI_OK){
        fprintf(stderr, "make_view: nd_alloc failed (%d)\n", st);
        exit(2);
    }
    st = nd_view_index(base, nd, idx, view);
    if (st != OTI_OK){
        fprintf(stderr, "make_view: view_index failed (%d)\n", st);
        exit(2);
    }
    // a doubled axis of an odd extent has one more element than asked: trim
    for (k = 0; k < nd; k++){
        view->shape[k] = shape[k];
    }
    nd_update_flags(view);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A plain C or F array holding `vals` (logical C order).
static void make_from(int32_t nd, const int64_t* shape, int32_t layout, const double* vals, ndarr_t* a){

    int64_t n = shape_size(nd, shape), i;

    if (nd_alloc(NULL, OTI_F64, nd, shape, layout, ND_ALLOC_ZERO, a) != OTI_OK){
        fprintf(stderr, "make_from: nd_alloc failed\n");
        exit(2);
    }
    for (i = 0; i < n; i++){
        set_f(a, i, vals[i]);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int arr_equals(const ndarr_t* a, const double* expect, int64_t n, int bitwise){

    int64_t i;

    if (shape_size(a->ndim, a->shape) != n){
        return 0;
    }
    for (i = 0; i < n; i++){
        double g = get_f(a, i);
        if (bitwise ? !same_bits(g, expect[i]) : !same_num(g, expect[i])){
            return 0;
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Adversarial data: cancellation, mixed magnitudes, NaN, -0.0, infinities.
static void fill_adversarial(ndarr_t* a, uint64_t seed){

    int64_t n = shape_size(a->ndim, a->shape), i;
    uint64_t save = g_rng_state;

    rng_seed(seed);
    for (i = 0; i < n; i++){
        double v;
        switch (rng_int(10)){
            case 0: v = 1e16; break;
            case 1: v = -1e16; break;
            case 2: v = 1.0; break;
            case 3: v = -0.0; break;
            case 4: v = NAN; break;
            case 5: v = (rng_uniform() - 0.5) * 1e-300; break;
            case 6: v = (rng_uniform() - 0.5) * 1e300; break;
            default: v = (rng_uniform() - 0.5) * 100.0; break;
        }
        set_f(a, i, v);
    }
    g_rng_state = save;

}
// -------------------------------------------------------------------------------------------------------



// =======================================================================================================
// References written from the documented algorithms
// =======================================================================================================

// *******************************************************************************************************
// reduce.h: nd_pairwise_sum. n < 8: sequential from +0.0; 8 <= n <= 128: eight accumulators combined
// ((r0 + r1) + (r2 + r3)) + ((r4 + r5) + (r6 + r7)) then the remainder; n > 128: split at n / 2 rounded
// down to a multiple of 8.
static double ref_pairwise(const double* x, int64_t n, int64_t stride){

    int64_t i;

    if (n < 8){
        double res = 0.0;
        for (i = 0; i < n; i++){
            res += x[i * stride];
        }
        return res;
    }
    if (n <= 128){
        double r[8], res;
        int j;
        for (j = 0; j < 8; j++){
            r[j] = x[j * stride];
        }
        for (i = 8; i < n - (n % 8); i += 8){
            for (j = 0; j < 8; j++){
                r[j] += x[(i + j) * stride];
            }
        }
        res = ((r[0] + r[1]) + (r[2] + r[3])) + ((r[4] + r[5]) + (r[6] + r[7]));
        for (; i < n; i++){
            res += x[i * stride];
        }
        return res;
    }
    {
        int64_t n2 = n / 2;
        n2 -= n2 % 8;
        return ref_pairwise(x, n2, stride) + ref_pairwise(x + n2 * stride, n - n2, stride);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// reduce.h: nd_tree_combine, halves split at n / 2.
static double ref_tree(const double* p, int64_t n, int32_t op){

    int64_t h;
    double l, r;

    if (n == 1){
        return p[0];
    }
    h = n / 2;
    l = ref_tree(p, h, op);
    r = ref_tree(p + h, n - h, op);
    return op == ND_RED_PROD ? l * r : l + r;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The documented SUM of n elements taken in order with a stride: blocks of OTI_EXEC_CHUNK_ELEMS reduced
// by
// the pairwise scheme, a pairwise tree over the blocks, then the identity (+0.0) added.
static double ref_sum_blocks(const double* x, int64_t n, int64_t stride){

    static double part[1 << 14];
    int64_t nb = (n + OTI_EXEC_CHUNK_ELEMS - 1) / OTI_EXEC_CHUNK_ELEMS, b;
    double t;

    if (n == 0){
        return 0.0;
    }
    for (b = 0; b < nb; b++){
        int64_t start = b * OTI_EXEC_CHUNK_ELEMS;
        int64_t len = n - start < OTI_EXEC_CHUNK_ELEMS ? n - start : OTI_EXEC_CHUNK_ELEMS;
        part[b] = ref_pairwise(x + start * stride, len, stride);
    }
    t = ref_tree(part, nb, ND_RED_SUM);
    return 0.0 + t;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int close_to(double a, double b, double rtol, double atol){

    if (isnan(a) && isnan(b)){
        return 1;
    }
    if (isinf(a) || isinf(b)){
        return a == b;
    }
    return fabs(a - b) <= atol + rtol * fabs(b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Value of element `lin` (logical C order) of any dtype as a double.
static double get_num(const ndarr_t* a, int64_t lin){

    void* p = elem_ptr(a, lin);

    if (a->dtype == OTI_F64){
        return *(double*)p;
    }
    if (a->dtype == OTI_I64){
        return (double)*(int64_t*)p;
    }
    return (double)*(uint8_t*)p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void set_u8(ndarr_t* a, int64_t lin, int v){

    *(uint8_t*)elem_ptr(a, lin) = (uint8_t)v;

}
// -------------------------------------------------------------------------------------------------------


static double g_vals[1 << 15];
static double g_expect[1 << 15];

// *******************************************************************************************************
// Generic reference reduction by definition: for every output element (kept axes in C order) the reduced
// coordinates are visited in C order. Returns 0, or OTI_ERR_SHAPE for an empty min / max / arg*; fills
// g_expect with the result values (long double accumulation, exact for small integers) and the result
// shape (kept axes, extent 1 for reduced axes when keepdims).
static int ref_reduce(int32_t op, const ndarr_t* a, const int* is_red, int64_t ddof, int32_t keepdims,
                      int32_t* rnd, int64_t* rshape){

    int32_t nd = a->ndim, k;
    int64_t nk = 1, nr = 1, lstride[OTI_ND_MAXDIM], ok, r;
    int32_t kept[OTI_ND_MAXDIM], red[OTI_ND_MAXDIM], nkept = 0, nred = 0;

    lstride[nd > 0 ? nd - 1 : 0] = 1;
    for (k = nd - 2; k >= 0; k--){
        lstride[k] = lstride[k + 1] * a->shape[k + 1];
    }
    *rnd = 0;
    for (k = 0; k < nd; k++){
        if (is_red[k]){
            red[nred++] = k;
            nr *= a->shape[k];
            if (keepdims){
                rshape[(*rnd)++] = 1;
            }
        } else {
            kept[nkept++] = k;
            nk *= a->shape[k];
            rshape[(*rnd)++] = a->shape[k];
        }
    }
    if (nr == 0 && nk > 0 && (op == ND_RED_MIN || op == ND_RED_MAX || op == ND_RED_ARGMIN ||
                              op == ND_RED_ARGMAX)){
        return OTI_ERR_SHAPE;
    }
    for (ok = 0; ok < nk; ok++){
        int64_t base = 0, rem = ok;
        long double s = 0.0L, p = 1.0L;
        double mn = 0, mx = 0, mean;
        int have = 0, anynan = 0;
        int64_t imin = 0, imax = 0, inan = -1;
        for (k = nkept - 1; k >= 0; k--){
            base += (rem % a->shape[kept[k]]) * lstride[kept[k]];
            rem /= a->shape[kept[k]];
        }
        for (r = 0; r < nr; r++){
            int64_t rr = r, lin = base;
            double v;
            for (k = nred - 1; k >= 0; k--){
                lin += (rr % a->shape[red[k]]) * lstride[red[k]];
                rr /= a->shape[red[k]];
            }
            v = get_num(a, lin);
            g_vals[r] = v;
            s += v;
            p *= v;
            if (isnan(v)){
                anynan = 1;
                if (inan < 0){
                    inan = r;
                }
            }
            if (!have){
                mn = mx = v;
                imin = imax = r;
                have = 1;
            } else {
                if (v < mn){ mn = v; imin = r; }
                if (v > mx){ mx = v; imax = r; }
            }
        }
        switch (op){
            case ND_RED_SUM:  g_expect[ok] = (double)s; break;
            case ND_RED_PROD: g_expect[ok] = (double)p; break;
            case ND_RED_MIN:  g_expect[ok] = anynan ? NAN : mn; break;
            case ND_RED_MAX:  g_expect[ok] = anynan ? NAN : mx; break;
            case ND_RED_ARGMIN: g_expect[ok] = (double)(inan >= 0 ? inan : imin); break;
            case ND_RED_ARGMAX: g_expect[ok] = (double)(inan >= 0 ? inan : imax); break;
            case ND_RED_ANY:
                g_expect[ok] = 0;
                for (r = 0; r < nr; r++){ if (g_vals[r] != 0.0 || isnan(g_vals[r])) g_expect[ok] = 1; }
                break;
            case ND_RED_ALL:
                g_expect[ok] = 1;
                for (r = 0; r < nr; r++){ if (g_vals[r] == 0.0) g_expect[ok] = 0; }
                break;
            default: {
                long double ss = 0.0L;
                int64_t denom;
                mean = nr > 0 ? (double)(s / (long double)nr) : NAN;
                if (op == ND_RED_MEAN){
                    g_expect[ok] = mean;
                    break;
                }
                for (r = 0; r < nr; r++){
                    long double d = (long double)g_vals[r] - (long double)mean;
                    ss += d * d;
                }
                denom = nr - ddof;
                if (denom < 0){
                    denom = 0;
                }
                if (nr == 0 || isnan((double)ss)){
                    g_expect[ok] = NAN;
                } else if (denom == 0){
                    g_expect[ok] = (ss == 0.0L) ? NAN : INFINITY;
                } else {
                    g_expect[ok] = (double)(ss / (long double)denom);
                }
                if (op == ND_RED_STD){
                    g_expect[ok] = sqrt(g_expect[ok]);
                }
            }
        }
    }
    return 0;

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// nd_pairwise_sum, nd_tree_combine
// =======================================================================================================

// *******************************************************************************************************
static void test_pairwise_sum(void){

    static double buf[20000];
    int64_t sizes[] = {0, 1, 2, 7, 8, 9, 15, 16, 17, 127, 128, 129, 130, 135, 136, 255, 256, 257, 1000,
            4096,
                       4097, 10000};
    int64_t strides[] = {1, 2, 3, -1, -2};
    int si, ti, kind, ok = 1;

    for (kind = 0; kind < 3; kind++){
        int64_t i;
        rng_seed(900 + (uint64_t)kind);
        for (i = 0; i < 20000; i++){
            if (kind == 0){
                buf[i] = (rng_uniform() - 0.5) * 100.0;
            } else if (kind == 1){
                buf[i] = (rng_int(4) == 0) ? 1e16 : (rng_int(3) == 0) ? -1e16 : 1.0;      // cancellation
            } else {
                buf[i] = (i % 3 == 0) ? -0.0 : (rng_uniform() - 0.5) * 1e-300 + (i % 5 ? 1e300 : -1e300);
            }
        }
        for (si = 0; si < (int)(sizeof(sizes) / sizeof(sizes[0])); si++){
            for (ti = 0; ti < 5; ti++){
                int64_t n = sizes[si], s = strides[ti];
                const double* first;
                double got, expect;
                int64_t span = (n > 0 ? (n - 1) * (s < 0 ? -s : s) : 0) + 1;
                if (span > 20000){
                    continue;
                }
                first = (s > 0) ? buf : buf + (n > 0 ? (n - 1) * (-s) : 0);
                got = nd_pairwise_sum(first, n, s);
                expect = ref_pairwise(first, n, s);
                if (!same_bits(got, expect)){
                    ok = 0;
                    fprintf(stderr, "  pairwise n=%lld stride %lld kind %d: %.17g vs %.17g\n",
                            (long long)n,
                            (long long)s, kind, got, expect);
                }
            }
        }
    }
    check(ok,
            "nd_pairwise_sum is bitwise the documented algorithm (22 sizes x 5 strides x 3 data kinds)");
    check(nd_pairwise_sum(buf, 0, 1) == 0.0 && !signbit(nd_pairwise_sum(buf, 0, 1)),
            "nd_pairwise_sum(n = 0) is +0.0");
    {
        double nz[7] = {-0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0};
        check(!signbit(nd_pairwise_sum(nz, 7, 1)),
                "nd_pairwise_sum of 7 negative zeros is +0.0 (starts from +0.0)");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_tree_combine(void){

    double p[64];
    int n, ok = 1, i;

    rng_seed(77);
    for (i = 0; i < 64; i++){
        p[i] = (rng_uniform() - 0.5) * 10.0 + ((i % 5) ? 1e10 : -1e10);
    }
    for (n = 1; n <= 64; n++){
        ok = ok && same_bits(nd_tree_combine(p, n, ND_RED_SUM), ref_tree(p, n, ND_RED_SUM));
        ok = ok && same_bits(nd_tree_combine(p, n, ND_RED_PROD), ref_tree(p, n, ND_RED_PROD));
    }
    check(ok, "nd_tree_combine: bitwise the documented pairwise tree for 1..64 blocks, SUM and PROD");
    check(nd_tree_combine(p, 1, ND_RED_SUM) == p[0] && nd_tree_combine(p, 2, ND_RED_SUM) == p[0] + p[1],
          "nd_tree_combine: one block is itself, two blocks are their sum");

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// nd_reduce: 1-D and single-axis bitwise against the documented tree
// =======================================================================================================

// *******************************************************************************************************
static void test_sum_1d_blocks(void){

    static double data[70001];
    int64_t sizes[] = {0, 1, 2, 7, 8, 9, 100, 128, 129, 1000, 4095, 4096, 4097, 8191, 8192, 8193, 20000,
            70001};
    int si, kind, ok = 1, ok_mean = 1;

    for (kind = 0; kind < 2; kind++){
        int64_t i;
        rng_seed(31 + (uint64_t)kind);
        for (i = 0; i < 70001; i++){
            data[i] = kind == 0 ? (rng_uniform() - 0.5) * 20.0 :
                      ((i % 7 == 0) ? 1e16 : (i % 7 == 3) ? -1e16 : 0.1);
        }
        for (si = 0; si < (int)(sizeof(sizes) / sizeof(sizes[0])); si++){
            int64_t n = sizes[si];
            ndarr_t a = {0}, res = {0};
            int64_t sh[1];
            double expect;
            sh[0] = n;
            make_desc(&a, data, OTI_F64, 1, sh, (int64_t[]){1}, 0);
            nd_update_flags(&a);
            if (nd_reduce(NULL, ND_RED_SUM, &a, -1, NULL, 0, 0, &res) != OTI_OK || res.ndim != 0){
                ok = 0;
                continue;
            }
            expect = ref_sum_blocks(data, n, 1);
            if (!same_bits(get_f(&res, 0), expect)){
                ok = 0;
                fprintf(stderr, "  sum n=%lld kind %d: %.17g vs documented %.17g\n", (long long)n, kind,
                        get_f(&res, 0), expect);
            }
            nd_release(&res);
            if (nd_reduce(NULL, ND_RED_MEAN, &a, -1, NULL, 0, 0, &res) != OTI_OK){
                ok_mean = 0;
                continue;
            }
            if (n > 0){
                ok_mean = ok_mean && same_bits(get_f(&res, 0), expect / (double)n);
            } else {
                ok_mean = ok_mean && isnan(get_f(&res, 0));
            }
            nd_release(&res);
        }
    }
    check(ok,
            "nd_reduce(SUM) of a contiguous 1-D input is bitwise the documented block tree (n <= 70001)");
    check(ok_mean, "nd_reduce(MEAN) of a 1-D input is the documented sum / N (empty: NaN)");

    // up to one block: nd_pairwise_sum plus the identity
    {
        int64_t n;
        int okb = 1;
        for (n = 1; n <= 4096; n += (n < 300 ? 1 : 211)){
            ndarr_t a = {0}, res = {0};
            int64_t sh[1];
            sh[0] = n;
            make_desc(&a, data, OTI_F64, 1, sh, (int64_t[]){1}, 0);
            nd_update_flags(&a);
            nd_reduce(NULL, ND_RED_SUM, &a, -1, NULL, 0, 0, &res);
            okb = okb && same_bits(get_f(&res, 0), 0.0 + nd_pairwise_sum(data, n, 1));
            nd_release(&res);
        }
        check(okb, "nd_reduce(SUM) up to 4096 elements equals 0.0 + nd_pairwise_sum bitwise (as np.sum)");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_negative_zero_and_specials(void){

    static double nz[5000];
    int64_t sizes[] = {1, 2, 7, 8, 9, 100, 129, 4096, 5000};
    int i, ok = 1;
    ndarr_t a = {0}, res = {0};

    for (i = 0; i < 5000; i++){
        nz[i] = -0.0;
    }
    for (i = 0; i < (int)(sizeof(sizes) / sizeof(sizes[0])); i++){
        int64_t sh[1];
        sh[0] = sizes[i];
        make_desc(&a, nz, OTI_F64, 1, sh, (int64_t[]){1}, 0);
        nd_update_flags(&a);
        nd_reduce(NULL, ND_RED_SUM, &a, -1, NULL, 0, 0, &res);
        ok = ok && same_bits(get_f(&res, 0), 0.0);
        nd_release(&res);
    }
    check(ok, "the sum of negative zeros is +0.0 for every length (as np.sum([-0.0]))");
    {
        double v[4] = {1.0, NAN, 2.0, 3.0};
        int64_t sh[1] = {4};
        make_desc(&a, v, OTI_F64, 1, sh, (int64_t[]){1}, 0);
        nd_update_flags(&a);
        nd_reduce(NULL, ND_RED_SUM, &a, -1, NULL, 0, 0, &res);
        check(isnan(get_f(&res, 0)), "sum with a NaN is NaN");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_MAX, &a, -1, NULL, 0, 0, &res);
        check(isnan(get_f(&res, 0)), "max with a NaN is NaN");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_MIN, &a, -1, NULL, 0, 0, &res);
        check(isnan(get_f(&res, 0)), "min with a NaN is NaN");
        nd_release(&res);
    }
    {
        double v[3] = {INFINITY, 1.0, -INFINITY};
        int64_t sh[1] = {3};
        make_desc(&a, v, OTI_F64, 1, sh, (int64_t[]){1}, 0);
        nd_update_flags(&a);
        nd_reduce(NULL, ND_RED_SUM, &a, -1, NULL, 0, 0, &res);
        check(isnan(get_f(&res, 0)), "inf + (-inf) sums to NaN, status OK");
        nd_release(&res);
    }
    {
        double v[3] = {2.0, 3.0, 4.0};
        int64_t sh[1] = {3};
        make_desc(&a, v, OTI_F64, 1, sh, (int64_t[]){1}, 0);
        nd_update_flags(&a);
        nd_reduce(NULL, ND_RED_PROD, &a, -1, NULL, 0, 0, &res);
        check(get_f(&res, 0) == 24.0 && res.ndim == 0, "prod of (2,3,4) is 24, rank 0");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_VAR, &a, -1, NULL, 0, 0, &res);
        check(close_to(get_f(&res, 0), 2.0 / 3.0, 1e-15, 0), "var(2,3,4) = 2/3");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_VAR, &a, -1, NULL, 0, 1, &res);
        check(close_to(get_f(&res, 0), 1.0, 1e-15, 0), "var(2,3,4, ddof=1) = 1");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_STD, &a, -1, NULL, 0, 1, &res);
        check(close_to(get_f(&res, 0), 1.0, 1e-15, 0), "std(2,3,4, ddof=1) = 1");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_VAR, &a, -1, NULL, 0, 3, &res);
        check(isnan(get_f(&res, 0)) || isinf(get_f(&res, 0)),
                "var with ddof = N: IEEE inf / NaN (0 denominator)");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_VAR, &a, -1, NULL, 0, 5, &res);
        check(isnan(get_f(&res, 0)) || isinf(get_f(&res, 0)),
                "var with ddof > N: max(N - ddof, 0) = 0 denominator");
        nd_release(&res);
    }
    {
        double v[1] = {5.0};
        int64_t sh[1] = {1};
        make_desc(&a, v, OTI_F64, 1, sh, (int64_t[]){1}, 0);
        nd_update_flags(&a);
        nd_reduce(NULL, ND_RED_VAR, &a, -1, NULL, 0, 0, &res);
        check(get_f(&res, 0) == 0.0, "var of one element, ddof 0, is 0");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_VAR, &a, -1, NULL, 0, 1, &res);
        check(isnan(get_f(&res, 0)), "var of one element, ddof 1, is NaN (0 / 0)");
        nd_release(&res);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A single reduced axis of a 2-D array with random layout: the elements of each output are taken along
// the
// axis in order and reduced as documented, bitwise.
static void test_sum_single_axis_bitwise(void){

    int iter, ok = 1, ok_mean = 1;

    rng_seed(4242);
    for (iter = 0; iter < 80; iter++){
        int64_t sh[2];
        ndarr_t base = {0}, a = {0}, res = {0};
        int32_t axis = (int32_t)rng_int(2);
        int64_t other, o;
        sh[axis] = (iter % 4 == 0) ? 4096 + rng_int(6000) : 1 + rng_int(300);
        other = 1 + rng_int(4);
        sh[1 - axis] = other;
        make_view(2, sh, (int)rng_int(3), OTI_F64, &base, &a);
        fill_adversarial(&a, 5000 + (uint64_t)iter);
        if (nd_reduce(NULL, ND_RED_SUM, &a, 1, &axis, 0, 0, &res) != OTI_OK){
            ok = 0;
            nd_release(&base);
            continue;
        }
        for (o = 0; o < other; o++){
            double line[12000];
            int64_t i;
            for (i = 0; i < sh[axis]; i++){
                int64_t lin = axis == 0 ? i * other + o : o * sh[1] + i;
                line[i] = get_f(&a, lin);
            }
            if (!same_bits(get_f(&res, o), ref_sum_blocks(line, sh[axis], 1))){
                ok = 0;
                fprintf(stderr, "  iter %d axis %d len %lld output %lld differs\n", iter, axis,
                        (long long)sh[axis], (long long)o);
            }
        }
        nd_release(&res);
        nd_reduce(NULL, ND_RED_MEAN, &a, 1, &axis, 0, 0, &res);
        for (o = 0; o < other; o++){
            double line[12000];
            int64_t i;
            for (i = 0; i < sh[axis]; i++){
                int64_t lin = axis == 0 ? i * other + o : o * sh[1] + i;
                line[i] = get_f(&a, lin);
            }
            ok_mean = ok_mean && same_bits(get_f(&res, o), ref_sum_blocks(line, sh[axis],
                    1) / (double)sh[axis]);
        }
        nd_release(&res);
        nd_release(&base);
    }
    check(ok,
            "nd_reduce(SUM) over one axis: 80 random shapes / layouts, bitwise the documented tree");
    check(ok_mean, "nd_reduce(MEAN) over one axis: bitwise sum / N");

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// nd_reduce: every op against the reference, random shapes / axes / layouts
// =======================================================================================================

static const int32_t k_red_ops[11] = {ND_RED_SUM, ND_RED_PROD, ND_RED_MIN, ND_RED_MAX, ND_RED_MEAN,
                                      ND_RED_VAR, ND_RED_STD, ND_RED_ARGMIN, ND_RED_ARGMAX, ND_RED_ANY,
                                      ND_RED_ALL};

// *******************************************************************************************************
static void fill_small(ndarr_t* a, int32_t op, int u8){

    int64_t n = shape_size(a->ndim, a->shape), i;

    for (i = 0; i < n; i++){
        if (u8){
            set_u8(a, i, rng_int(3) == 0 ? 0 : 1);
        } else if (op == ND_RED_PROD){
            static const double pv[6] = {1.0, -1.0, 2.0, 0.5, -2.0, 1.0};
            set_f(a, i, pv[rng_int(6)]);
        } else if (op == ND_RED_MIN || op == ND_RED_MAX || op == ND_RED_ARGMIN || op == ND_RED_ARGMAX){
            set_f(a, i, rng_int(10) == 0 ? NAN : (double)(rng_int(5) - 2));       // ties and NaN
        } else if (op == ND_RED_ANY || op == ND_RED_ALL){
            set_f(a, i, rng_int(3) == 0 ? 0.0 : (rng_int(8) == 0 ? NAN : 1.5));
        } else {
            set_f(a, i, (double)(rng_int(9) - 4));
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_reduce_random_all_ops(void){

    int iter, fails = 0;
    int failed_op[11] = {0};

    rng_seed(8128);
    for (iter = 0; iter < 2500; iter++){

        int32_t op = k_red_ops[iter % 11];
        int32_t nd = 1 + (int32_t)rng_int(4);
        int64_t sh[4];
        int32_t k;
        ndarr_t base = {0}, a = {0}, res = {0};
        int u8 = ((op == ND_RED_ANY || op == ND_RED_ALL) && rng_int(2) == 0);
        int is_red[4] = {0, 0, 0, 0};
        int32_t axes[4], naxes = 0;
        int32_t keep = (int32_t)rng_int(2);
        int64_t ddof = (op == ND_RED_VAR || op == ND_RED_STD) ? rng_int(3) : 0;
        int32_t rnd;
        int64_t rshape[OTI_ND_MAXDIM];
        int expect_status, st;
        int use_all = 0;
        int64_t total, nres;

        for (k = 0; k < nd; k++){
            sh[k] = (rng_int(10) == 0) ? 0 : 1 + rng_int(5);
        }
        if (op == ND_RED_ARGMIN || op == ND_RED_ARGMAX){
            if (rng_int(3) == 0){
                use_all = 1;                    // naxes -1: flattened C order
                for (k = 0; k < nd; k++){
                    is_red[k] = 1;
                }
            } else {
                int32_t ax = (int32_t)rng_int(nd);
                is_red[ax] = 1;
                axes[naxes++] = (rng_int(2) ? ax : ax - nd);
            }
            keep = use_all ? 0 : keep;
        } else if (rng_int(4) == 0){
            use_all = 1;
            for (k = 0; k < nd; k++){
                is_red[k] = 1;
            }
        } else {
            for (k = 0; k < nd; k++){
                if (rng_int(2)){
                    is_red[k] = 1;
                    axes[naxes++] = (rng_int(2) ? k : k - nd);
                }
            }
            if (naxes == 0){
                is_red[0] = 1;
                axes[naxes++] = 0;
            }
        }
        make_view(nd, sh, (int)rng_int(3), u8 ? OTI_U8 : OTI_F64, &base, &a);
        fill_small(&a, op, u8);
        if (use_all && (op == ND_RED_ARGMIN || op == ND_RED_ARGMAX)){
            keep = 0;
        }
        expect_status = ref_reduce(op, &a, is_red, ddof, (use_all && (op == ND_RED_ARGMIN ||
                op == ND_RED_ARGMAX)) ? 0 : keep,
                                   &rnd, rshape);
        // skip the ambiguous case of an empty reduced extent with an empty output for min / max / arg
        {
            int64_t nr_ = 1, nk_ = 1;
            for (k = 0; k < nd; k++){
                if (is_red[k]){ nr_ *= sh[k]; } else { nk_ *= sh[k]; }
            }
            if (nr_ == 0 && nk_ == 0 && (op == ND_RED_MIN || op == ND_RED_MAX || op == ND_RED_ARGMIN ||
                    op == ND_RED_ARGMAX)){
                nd_release(&base);
                continue;
            }
        }
        st = nd_reduce(NULL, op, &a, use_all ? -1 : naxes, use_all ? NULL : axes, keep, ddof, &res);
        total = shape_size(rnd, rshape);
        nres = total;
        if (expect_status != 0){
            if (st != expect_status){
                fails++;
                failed_op[iter % 11]++;
                if (fails < 6){
                    fprintf(stderr, "  iter %d op %d: expected status %d, got %d\n", iter, op,
                            expect_status, st);
                }
            }
        } else if (st != OTI_OK){
            fails++;
            failed_op[iter % 11]++;
            if (fails < 6){
                fprintf(stderr, "  iter %d op %d nd %d: status %d\n", iter, op, nd, st);
            }
        } else {
            int okv = (res.ndim == rnd);
            int64_t i;
            int32_t want_dtype = (op == ND_RED_ARGMIN || op == ND_RED_ARGMAX) ? OTI_I64 :
                                 (op == ND_RED_ANY || op == ND_RED_ALL) ? OTI_U8 : OTI_F64;
            okv = okv && res.dtype == want_dtype;
            for (k = 0; okv && k < rnd; k++){
                okv = okv && res.shape[k] == rshape[k];
            }
            for (i = 0; okv && i < nres; i++){
                double got = get_num(&res, i);
                int good;
                if (op == ND_RED_SUM || op == ND_RED_PROD || op == ND_RED_MIN || op == ND_RED_MAX ||
                    op == ND_RED_ARGMIN || op == ND_RED_ARGMAX || op == ND_RED_ANY || op == ND_RED_ALL){
                    good = same_num(got, g_expect[i]);
                } else {
                    good = close_to(got, g_expect[i], 1e-12, 1e-12);
                }
                if (!good){
                    okv = 0;
                    if (fails < 6){
                        fprintf(stderr, "  iter %d op %d: element %lld got %.17g expected %.17g\n", iter,
                                op,
                                (long long)i, got, g_expect[i]);
                    }
                }
            }
            if (!okv){
                fails++;
                failed_op[iter % 11]++;
            }
        }
        if (res.buf != NULL){
            nd_release(&res);
        }
        nd_release(&base);
    }
    check(fails == 0,
            "nd_reduce: 2500 random shapes / axes / keepdims / layouts, every op, vs the reference");
    if (fails){
        int o;
        for (o = 0; o < 11; o++){
            if (failed_op[o]){
                fprintf(stderr, "  op %d failed %d times\n", k_red_ops[o], failed_op[o]);
            }
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_reduce_hand(void){

    double v[6] = {3, 1, 2, 9, 5, 4};      // (2,3): [[3,1,2],[9,5,4]]
    int64_t sh[2] = {2, 3};
    ndarr_t a = {0}, res = {0};
    int32_t ax0 = 0, ax1 = 1, axm1 = -1;
    int32_t both[2] = {0, 1};

    make_from(2, sh, ND_LAYOUT_C, v, &a);
    nd_reduce(NULL, ND_RED_SUM, &a, 1, &ax0, 0, 0, &res);
    check(res.ndim == 1 && res.shape[0] == 3 && get_f(&res, 0) == 12 && get_f(&res, 1) == 6 && get_f(&res,
            2) == 6,
          "sum axis 0 of [[3,1,2],[9,5,4]] = [12,6,6]");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_SUM, &a, 1, &ax1, 0, 0, &res);
    check(res.ndim == 1 && res.shape[0] == 2 && get_f(&res, 0) == 6 && get_f(&res, 1) == 18,
            "sum axis 1 = [6,18]");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_SUM, &a, 1, &axm1, 1, 0, &res);
    check(res.ndim == 2 && res.shape[0] == 2 && res.shape[1] == 1 && get_f(&res, 1) == 18,
          "sum axis -1 keepdims: shape (2,1)");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_SUM, &a, 2, both, 1, 0, &res);
    check(res.ndim == 2 && res.shape[0] == 1 && res.shape[1] == 1 && get_f(&res, 0) == 24,
            "sum both axes keepdims: (1,1)");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_SUM, &a, -1, NULL, 0, 0, &res);
    check(res.ndim == 0 && get_f(&res, 0) == 24, "sum of everything: rank 0, 24");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_SUM, &a, -1, NULL, 1, 0, &res);
    check(res.ndim == 2 && res.shape[0] == 1 && res.shape[1] == 1, "sum of everything keepdims: (1,1)");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_MIN, &a, 1, &ax1, 0, 0, &res);
    check(get_f(&res, 0) == 1 && get_f(&res, 1) == 4, "min axis 1 = [1,4]");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_MAX, &a, 1, &ax0, 0, 0, &res);
    check(get_f(&res, 0) == 9 && get_f(&res, 1) == 5 && get_f(&res, 2) == 4, "max axis 0 = [9,5,4]");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_ARGMIN, &a, 1, &ax1, 0, 0, &res);
    check(res.dtype == OTI_I64 && ((int64_t*)res.data)[0] == 1 && ((int64_t*)res.data)[1] == 2,
            "argmin axis 1 = [1,2], I64");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_ARGMAX, &a, -1, NULL, 0, 0, &res);
    check(res.ndim == 0 && *(int64_t*)res.data == 3, "argmax of everything (flattened C order) = 3");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_MEAN, &a, 1, &ax0, 0, 0, &res);
    check(get_f(&res, 0) == 6 && get_f(&res, 1) == 3 && get_f(&res, 2) == 3, "mean axis 0 = [6,3,3]");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_ANY, &a, -1, NULL, 0, 0, &res);
    check(res.dtype == OTI_U8 && *(uint8_t*)res.data == 1, "any of nonzero values is 1, U8");
    nd_release(&res);
    nd_reduce(NULL, ND_RED_ALL, &a, 1, &ax1, 0, 0, &res);
    check(res.dtype == OTI_U8 && ((uint8_t*)res.data)[0] == 1 && ((uint8_t*)res.data)[1] == 1,
            "all axis 1");
    nd_release(&res);

    // naxes 0 reduces nothing
    nd_reduce(NULL, ND_RED_SUM, &a, 0, NULL, 0, 0, &res);
    check(res.ndim == 2 && res.shape[0] == 2 && res.shape[1] == 3 && get_f(&res, 4) == 5,
          "sum with naxes 0 reduces nothing (same shape and values)");
    nd_release(&res);

    // argmax: first occurrence in C order on an F-ordered input with ties; first NaN wins
    {
        double t[6] = {7, 7, 1, 7, 2, 7};     // (2,3) logical [[7,7,1],[7,2,7]]
        ndarr_t f = {0};
        make_from(2, sh, ND_LAYOUT_F, t, &f);
        nd_reduce(NULL, ND_RED_ARGMAX, &f, -1, NULL, 0, 0, &res);
        check(*(int64_t*)res.data == 0,
                "argmax of an F-ordered array with ties: the first in C order (0)");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_ARGMAX, &f, 1, &ax1, 0, 0, &res);
        check(((int64_t*)res.data)[0] == 0 && ((int64_t*)res.data)[1] == 0,
                "argmax axis 1 of the same: [0, 0]");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_ARGMIN, &f, 1, &ax0, 0, 0, &res);
        check(((int64_t*)res.data)[0] == 0 || ((int64_t*)res.data)[0] == 1, "argmin axis 0 runs");
        nd_release(&res);
        set_f(&f, 4, NAN);
        set_f(&f, 5, NAN);
        nd_reduce(NULL, ND_RED_ARGMAX, &f, -1, NULL, 0, 0, &res);
        check(*(int64_t*)res.data == 4, "argmax with NaNs: the first NaN in C order (index 4)");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_ARGMIN, &f, -1, NULL, 0, 0, &res);
        check(*(int64_t*)res.data == 4, "argmin with NaNs: the first NaN in C order");
        nd_release(&res);
        nd_release(&f);
    }

    // empty inputs
    {
        int64_t z[1] = {0}, z2[2] = {0, 3}, e3[2] = {3, 0};
        ndarr_t e = {0};
        nd_alloc(NULL, OTI_F64, 1, z, ND_LAYOUT_C, 0, &e);
        nd_reduce(NULL, ND_RED_SUM, &e, -1, NULL, 0, 0, &res);
        check(get_f(&res, 0) == 0.0 && !signbit(get_f(&res, 0)), "sum of an empty array is +0.0");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_PROD, &e, -1, NULL, 0, 0, &res);
        check(get_f(&res, 0) == 1.0, "prod of an empty array is 1");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_MEAN, &e, -1, NULL, 0, 0, &res);
        check(isnan(get_f(&res, 0)), "mean of an empty array is NaN");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_ANY, &e, -1, NULL, 0, 0, &res);
        check(*(uint8_t*)res.data == 0, "any of an empty array is 0");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_ALL, &e, -1, NULL, 0, 0, &res);
        check(*(uint8_t*)res.data == 1, "all of an empty array is 1");
        nd_release(&res);
        check(nd_reduce(NULL, ND_RED_MIN, &e, -1, NULL, 0, 0, &res) == OTI_ERR_SHAPE && res.buf == NULL,
                "min of an empty array -> SHAPE");
        check(nd_reduce(NULL, ND_RED_MAX, &e, -1, NULL, 0, 0, &res) == OTI_ERR_SHAPE,
                "max of an empty array -> SHAPE");
        check(nd_reduce(NULL, ND_RED_ARGMIN, &e, -1, NULL, 0, 0, &res) == OTI_ERR_SHAPE,
                "argmin of an empty array -> SHAPE");
        check(nd_reduce(NULL, ND_RED_ARGMAX, &e, -1, NULL, 0, 0, &res) == OTI_ERR_SHAPE,
                "argmax of an empty array -> SHAPE");
        nd_release(&e);
        nd_alloc(NULL, OTI_F64, 2, z2, ND_LAYOUT_C, 0, &e);
        nd_reduce(NULL, ND_RED_SUM, &e, 1, &ax0, 0, 0, &res);
        check(res.ndim == 1 && res.shape[0] == 3 && get_f(&res, 0) == 0.0 && get_f(&res, 2) == 0.0,
              "sum over the empty axis 0 of (0,3): zeros (3,)");
        nd_release(&res);
        nd_reduce(NULL, ND_RED_SUM, &e, 1, &ax1, 0, 0, &res);
        check(res.ndim == 1 && res.shape[0] == 0, "sum over axis 1 of (0,3): an empty (0,)");
        nd_release(&res);
        check(nd_reduce(NULL, ND_RED_MAX, &e, 1, &ax0, 0, 0, &res) == OTI_ERR_SHAPE,
                "max over the empty axis 0 of (0,3) -> SHAPE");
        nd_release(&e);
        nd_alloc(NULL, OTI_F64, 2, e3, ND_LAYOUT_C, 0, &e);
        nd_reduce(NULL, ND_RED_SUM, &e, 1, &ax1, 0, 0, &res);
        check(res.shape[0] == 3 && get_f(&res, 1) == 0.0,
                "sum over the empty axis 1 of (3,0): zeros (3,)");
        nd_release(&res);
        nd_release(&e);
    }
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_reduce_errors(void){

    ndarr_t a = {0}, u = {0}, res = {0};
    int64_t sh[2] = {3, 4};
    int32_t ax[2];
    double v[12] = {0};

    make_from(2, sh, ND_LAYOUT_C, v, &a);
    nd_alloc(NULL, OTI_U8, 2, sh, ND_LAYOUT_C, ND_ALLOC_ZERO, &u);
    ax[0] = 0;
    check(nd_reduce(NULL, 99, &a, 1, ax, 0, 0, &res) == OTI_ERR_ARGUMENT && res.buf == NULL,
            "unknown op -> ARGUMENT, res empty");
    check(nd_reduce(NULL, 0, &a, 1, ax, 0, 0, &res) == OTI_ERR_ARGUMENT, "op 0 -> ARGUMENT");
    ax[0] = 0; ax[1] = 0;
    check(nd_reduce(NULL, ND_RED_SUM, &a, 2, ax, 0, 0, &res) == OTI_ERR_ARGUMENT,
            "a repeated axis -> ARGUMENT");
    ax[0] = 0; ax[1] = -2;
    check(nd_reduce(NULL, ND_RED_SUM, &a, 2, ax, 0, 0, &res) == OTI_ERR_ARGUMENT,
            "axes 0 and -2 (the same axis) -> ARGUMENT");
    ax[0] = 0; ax[1] = 1;
    check(nd_reduce(NULL, ND_RED_ARGMAX, &a, 2, ax, 0, 0, &res) == OTI_ERR_ARGUMENT,
            "argmax over two axes -> ARGUMENT");
    check(nd_reduce(NULL, ND_RED_ARGMIN, &a, 2, ax, 0, 0, &res) == OTI_ERR_ARGUMENT,
            "argmin over two axes -> ARGUMENT");
    ax[0] = 2;
    check(nd_reduce(NULL, ND_RED_SUM, &a, 1, ax, 0, 0, &res) == OTI_ERR_INDEX,
            "axis 2 of a 2-D array -> INDEX");
    ax[0] = -3;
    check(nd_reduce(NULL, ND_RED_SUM, &a, 1, ax, 0, 0, &res) == OTI_ERR_INDEX,
            "axis -3 of a 2-D array -> INDEX");
    ax[0] = 0;
    check(nd_reduce(NULL, ND_RED_SUM, &u, 1, ax, 0, 0, &res) == OTI_ERR_DTYPE,
            "sum of a U8 array -> DTYPE");
    check(nd_reduce(NULL, ND_RED_MAX, &u, 1, ax, 0, 0, &res) == OTI_ERR_DTYPE,
            "max of a U8 array -> DTYPE");
    check(nd_reduce(NULL, ND_RED_ANY, &u, 1, ax, 0, 0, &res) == OTI_OK, "any of a U8 array is allowed");
    nd_release(&res);
    {
        oti_ctx ctx;
        oti_ctx_init(&ctx);
        ctx.device_type = 2;
        check(nd_reduce(&ctx, ND_RED_SUM, &a, -1, NULL, 0, 0, &res) == oti_ctx_check(&ctx) &&
              oti_ctx_last_error(&ctx, NULL, NULL) == oti_ctx_check(&ctx),
                      "a bad context is rejected and recorded");
        oti_ctx_init(&ctx);
        ax[0] = 5;
        check(nd_reduce(&ctx, ND_RED_SUM, &a, 1, ax, 0, 0, &res) == OTI_ERR_INDEX &&
              oti_ctx_last_error(&ctx, NULL, NULL) == OTI_ERR_INDEX,
                      "a failing nd_reduce records its status");
    }
    nd_release(&a);
    nd_release(&u);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// nd_reduce_to and overlap (3.4)
// =======================================================================================================

// *******************************************************************************************************
static void test_reduce_to(void){

    double v[12];
    int64_t sh[2] = {3, 4}, s4[1] = {4}, s3[1] = {3}, s14[2] = {1, 4};
    ndarr_t a = {0}, out = {0}, ro = {0}, ov = {0};
    int32_t ax0 = 0;
    int i;
    oti_ctx tiny;
    double e[4];

    for (i = 0; i < 12; i++){
        v[i] = 1.0 + (double)i;
    }
    for (i = 0; i < 4; i++){
        e[i] = v[i] + v[4 + i] + v[8 + i];
    }
    make_from(2, sh, ND_LAYOUT_C, v, &a);

    nd_alloc(NULL, OTI_F64, 1, s4, ND_LAYOUT_C, 0, &out);
    check(nd_reduce_to(NULL, ND_RED_SUM, &a, 1, &ax0, 0, 0, &out) == OTI_OK && arr_equals(&out, e, 4, 1),
          "nd_reduce_to into (4,)");
    nd_release(&out);
    nd_alloc(NULL, OTI_F64, 2, s14, ND_LAYOUT_C, 0, &out);
    check(nd_reduce_to(NULL, ND_RED_SUM, &a, 1, &ax0, 1, 0, &out) == OTI_OK && arr_equals(&out, e, 4, 1),
          "nd_reduce_to keepdims into (1,4)");
    check(nd_reduce_to(NULL, ND_RED_SUM, &a, 1, &ax0, 0, 0, &out) == OTI_ERR_SHAPE,
            "keepdims mismatch: out (1,4) for the (4,) result -> SHAPE");
    nd_release(&out);
    nd_alloc(NULL, OTI_F64, 1, s3, ND_LAYOUT_C, 0, &out);
    check(nd_reduce_to(NULL, ND_RED_SUM, &a, 1, &ax0, 0, 0, &out) == OTI_ERR_SHAPE,
            "out (3,) for the (4,) result -> SHAPE");
    nd_release(&out);
    nd_alloc(NULL, OTI_I64, 1, s4, ND_LAYOUT_C, 0, &out);
    check(nd_reduce_to(NULL, ND_RED_SUM, &a, 1, &ax0, 0, 0, &out) == OTI_ERR_DTYPE,
            "sum into an I64 out -> DTYPE");
    check(nd_reduce_to(NULL, ND_RED_ARGMAX, &a, 1, &ax0, 0, 0, &out) == OTI_OK &&
            ((int64_t*)out.data)[0] == 2,
          "argmax into an I64 out");
    nd_release(&out);
    nd_alloc(NULL, OTI_F64, 1, s4, ND_LAYOUT_C, 0, &out);
    check(nd_reduce_to(NULL, ND_RED_ARGMAX, &a, 1, &ax0, 0, 0, &out) == OTI_ERR_DTYPE,
            "argmax into an F64 out -> DTYPE");
    {
        ndarr_t d = {0};
        make_desc(&d, out.data, OTI_F64, 1, s4, (int64_t[]){1}, 0);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ro);
        check(nd_reduce_to(NULL, ND_RED_SUM, &a, 1, &ax0, 0, 0, &ro) == OTI_ERR_READONLY,
                "read-only out -> READONLY");
        nd_release(&ro);
        make_desc(&d, out.data, OTI_F64, 1, s4, (int64_t[]){0}, ND_WRITEABLE);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ov);
        check(nd_reduce_to(NULL, ND_RED_SUM, &a, 1, &ax0, 0, 0, &ov) == OTI_ERR_LAYOUT,
                "out with stride 0 -> LAYOUT");
        nd_release(&ov);
    }
    nd_release(&out);

    // overlap: np.sum(c, axis=0, out=c[0]) is computed through a temporary
    {
        ndarr_t c = {0}, row = {0};
        nd_index_t ix[1];
        double vv[12];
        oti_ctx ctx;
        memcpy(vv, v, sizeof(vv));
        make_from(2, sh, ND_LAYOUT_C, vv, &c);
        ix[0].kind = ND_IDX_INT; ix[0].has = 0; ix[0].start = 0;
        ix[0].stop = 0; ix[0].step = 0; ix[0].arr = NULL;
        nd_view_index(&c, 1, ix, &row);
        oti_ctx_init(&ctx);
        check(nd_reduce_to(&ctx, ND_RED_SUM, &c, 1, &ax0, 0, 0, &row) == OTI_OK,
                "sum(c, axis=0, out=c[0]): OK");
        check(arr_equals(&row, e, 4, 1),
                "out=c[0]: the column sums of the ORIGINAL c (computed through a temporary)");
        check(get_f(&c, 4) == v[4] && get_f(&c, 11) == v[11], "out=c[0]: the other rows are unchanged");
        nd_release(&c);

        // a shifted overlapping out and the temp budget: a temporary is charged
        make_from(2, sh, ND_LAYOUT_C, vv, &c);
        ix[0].start = 1;
        nd_view_index(&c, 1, ix, &row);
        oti_ctx_init(&tiny);
        tiny.max_temp_bytes = 1;
        check(nd_reduce_to(&tiny, ND_RED_SUM, &c, 1, &ax0, 0, 0, &row) == OTI_ERR_MEMORY,
              "overlapping out with a 1-byte temporary budget -> MEMORY");
        nd_test_fail_alloc(1);
        {
            int st = nd_reduce_to(&ctx, ND_RED_SUM, &c, 1, &ax0, 0, 0, &row);
            nd_test_fail_alloc(0);
            check(st == OTI_ERR_MEMORY, "overlapping out with an injected allocation failure -> MEMORY");
        }
        check(nd_reduce_to(&ctx, ND_RED_SUM, &c, 1, &ax0, 0, 0, &row) == OTI_OK && arr_equals(&row, e, 4,
                1),
              "overlapping out (row 1): original column sums");
        nd_release(&c);
    }

    // guard region: only the out view is written
    {
        static double buf[40];
        ndarr_t o = {0};
        uint64_t bits = UINT64_C(0x7FF8DEADBEEF0001);
        int ok = 1;
        for (i = 0; i < 40; i++){
            memcpy(&buf[i], &bits, 8);
        }
        make_desc(&o, buf + 30, OTI_F64, 1, s4, (int64_t[]){-3}, ND_WRITEABLE);
        nd_update_flags(&o);
        check(nd_reduce_to(NULL, ND_RED_SUM, &a, 1, &ax0, 0, 0, &o) == OTI_OK,
                "reduce_to into a strided, reversed out");
        for (i = 0; i < 40; i++){
            int touched = (i == 30 || i == 27 || i == 24 || i == 21);
            if (!touched && memcmp(&buf[i], &bits, 8) != 0){
                ok = 0;
            }
        }
        check(ok && arr_equals(&o, e, 4, 1),
                "reduce_to writes exactly the out view (canaries untouched)");
    }
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Determinism: bit-identical at 1, 2, N threads and the serial backend
// =======================================================================================================

// *******************************************************************************************************
static int reduce_bits_equal(const ndarr_t* a, const ndarr_t* b){

    int64_t n = shape_size(a->ndim, a->shape), i;

    if (a->ndim != b->ndim || a->dtype != b->dtype){
        return 0;
    }
    for (i = 0; i < n; i++){
        if (a->dtype == OTI_F64){
            double x = get_f(a, i), y = get_f(b, i);
            if (memcmp(&x, &y, 8) != 0){
                return 0;
            }
        } else if (get_num(a, i) != get_num(b, i)){
            return 0;
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_reduce_determinism(void){

    static const struct { int64_t s0,
            s1; int layout; int sliced; int axis; const char* name; } cases[] = {
        {70001, 0, 0, 0, -1, "(70001,) all"},
        {300, 500, 0, 0, 0, "(300,500) C axis 0"},
        {300, 500, 0, 0, 1, "(300,500) C axis 1"},
        {300, 500, 0, 0, -1, "(300,500) C all"},
        {300, 500, 1, 0, 0, "(300,500) F axis 0"},
        {300, 500, 1, 0, 1, "(300,500) F axis 1"},
        {400, 300, 0, 1, 0, "(400,300) strided / reversed view axis 0"},
        {4, 100000, 0, 0, 1, "(4,100000) axis 1: few outputs, many blocks"},
        {100000, 4, 0, 0, 0, "(100000,4) axis 0"},
        {50, 9000, 1, 0, 1, "(50,9000) F axis 1"}
    };
    static const int32_t ops[7] = {ND_RED_SUM, ND_RED_PROD, ND_RED_MEAN, ND_RED_VAR, ND_RED_STD,
            ND_RED_MIN,
                                   ND_RED_MAX};
    static const int32_t threads[5] = {1, 2, 3, 5, 0};
    int c, o, t, bad = 0;

    for (c = 0; c < (int)(sizeof(cases) / sizeof(cases[0])); c++){
        ndarr_t base = {0}, a = {0};
        int64_t sh[2];
        int nd = cases[c].s1 == 0 ? 1 : 2;
        int32_t axis = cases[c].axis;
        sh[0] = cases[c].s0;
        sh[1] = cases[c].s1;
        if (cases[c].sliced){
            nd_index_t ix[2];
            int64_t bsh[2];
            bsh[0] = 2 * sh[0];
            bsh[1] = sh[1];
            nd_alloc(NULL, OTI_F64, 2, bsh, ND_LAYOUT_C, 0, &base);
            ix[0] = mk_slice(HT, 0, 0, 2);
            ix[1] = mk_slice(HT, 0, 0, -1);
            nd_view_index(&base, 2, ix, &a);
        } else {
            make_view(nd, sh, cases[c].layout ? 1 : 0, OTI_F64, &base, &a);
        }
        fill_adversarial(&a, 777 + (uint64_t)c);
        for (o = 0; o < 7; o++){
            ndarr_t ref = {0}, got = {0};
            oti_ctx serial, par;
            int32_t axes[1];
            axes[0] = axis;
            oti_ctx_init(&serial);
            serial.exec.backend = OTI_BACKEND_SERIAL;
            if (nd_reduce(&serial, ops[o], &a, axis < 0 ? -1 : 1, axis < 0 ? NULL : axes, 0, 0,
                    &ref) != OTI_OK){
                bad++;
                continue;
            }
            for (t = 0; t < 5; t++){
                oti_ctx_init(&par);
                par.exec.nthreads = threads[t];
                par.exec.min_parallel_elems = 1;
                if (nd_reduce(&par, ops[o], &a, axis < 0 ? -1 : 1, axis < 0 ? NULL : axes, 0, 0,
                        &got) != OTI_OK ||
                    !reduce_bits_equal(&ref, &got)){
                    bad++;
                    fprintf(stderr, "  determinism: %s op %d nthreads %d differs from serial\n",
                            cases[c].name,
                            ops[o], threads[t]);
                }
                if (got.buf != NULL){
                    nd_release(&got);
                }
            }
            // the default context (default threshold, inherited threads) too
            if (nd_reduce(NULL, ops[o], &a, axis < 0 ? -1 : 1, axis < 0 ? NULL : axes, 0, 0,
                    &got) != OTI_OK ||
                !reduce_bits_equal(&ref, &got)){
                bad++;
                fprintf(stderr, "  determinism: %s op %d default context differs\n", cases[c].name,
                        ops[o]);
            }
            if (got.buf != NULL){
                nd_release(&got);
            }
            nd_release(&ref);
        }
        nd_release(&base);
    }
    check(bad == 0,
            "reductions SUM PROD MEAN VAR STD MIN MAX: bit-identical at 1, 2, 3, 5, N threads, serial");

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// S24: K-layout results on the SoA block layout
// =======================================================================================================

// *******************************************************************************************************
static void test_reduce_soa(void){

    ndarr_t a = {0}, res = {0};
    int64_t sh[3] = {6, 8, 5};
    int64_t st[3] = {40, 1, 8};
    int32_t ax;
    int64_t i;
    int ok;

    nd_alloc_strided(NULL, OTI_F64, 3, sh, st, 0, &a);
    for (i = 0; i < 240; i++){
        set_f(&a, i, (double)(i % 11) - 5.0);
    }

    // sum over the block axis: an (8,5) result in the layout of the input's remaining axes (F-ordered)
    ax = 0;
    nd_reduce(NULL, ND_RED_SUM, &a, 1, &ax, 0, 0, &res);
    ok = res.ndim == 2 && res.shape[0] == 8 && res.shape[1] == 5;
    for (i = 0; ok && i < 40; i++){
        double s = 0;
        int64_t b;
        for (b = 0; b < 6; b++){
            s += get_f(&a, b * 40 + i);
        }
        ok = ok && get_f(&res, i) == s;
    }
    check(ok, "SoA (6,8,5): sum over the block axis: values");
    check(res.strides[0] == 1 && res.strides[1] == 8 && (res.flags & ND_F_CONTIG),
          "SoA: the (8,5) result keeps the in-block F order (K layout, strides (1,8))");
    nd_release(&res);

    // keepdims over the block axis
    nd_reduce(NULL, ND_RED_SUM, &a, 1, &ax, 1, 0, &res);
    check(res.ndim == 3 && res.shape[0] == 1 && res.shape[1] == 8 && res.shape[2] == 5 &&
            res.strides[1] == 1 &&
          res.strides[2] == 8, "SoA keepdims: (1,8,5) with strides (., 1, 8)");
    nd_release(&res);

    // sum over the column axis: (6,8) with the block stride 8 and the row stride 1 (C-like in blocks)
    ax = 2;
    nd_reduce(NULL, ND_RED_MAX, &a, 1, &ax, 0, 0, &res);
    ok = res.ndim == 2 && res.shape[0] == 6 && res.shape[1] == 8;
    for (i = 0; ok && i < 48; i++){
        double mx = -1e300;
        int64_t j;
        for (j = 0; j < 5; j++){
            double x = get_f(&a, i * 5 + j);
            mx = x > mx ? x : mx;
        }
        ok = ok && get_f(&res, i) == mx;
    }
    check(ok, "SoA: max over the column axis: values");
    check(res.strides[1] == 1 && res.strides[0] == 8,
            "SoA: the (6,8) result is compact with the row axis innermost (8, 1)");
    nd_release(&res);

    // full reduction
    {
        double s = 0;
        for (i = 0; i < 240; i++){
            s += get_f(&a, i);
        }
        nd_reduce(NULL, ND_RED_SUM, &a, -1, NULL, 0, 0, &res);
        check(res.ndim == 0 && get_f(&res, 0) == s, "SoA: full sum");
        nd_release(&res);
    }
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// W2 fix 1, checker 1 and 6: reduction workspaces are charged to the temp budget; empty reductions do no
// input-stride arithmetic.
static void test_fix1_reduce(void){

    enum { NB = 257 };
    int64_t n = (int64_t)NB * OTI_EXEC_CHUNK_ELEMS;
    int64_t sh[1];
    ndarr_t a = {0}, res = {0}, out = {0};
    oti_ctx tiny, mid, big;
    int64_t i;
    nd_index_t ix[1];

    sh[0] = n;
    nd_alloc(NULL, OTI_F64, 1, sh, ND_LAYOUT_C, 0, &a);
    for (i = 0; i < n; i++){
        ((double*)a.data)[i] = 1.0;
    }
    oti_ctx_init(&tiny);
    tiny.max_temp_bytes = 1024;
    check(nd_reduce(&tiny, ND_RED_SUM, &a, -1, NULL, 0, 0, &res) == OTI_ERR_MEMORY && res.buf == NULL,
          "fix1.1: SUM of 257 blocks needs 2056 bytes of partials: a 1024-byte temp budget -> MEMORY");
    check(nd_reduce(&tiny, ND_RED_ARGMIN, &a, -1, NULL, 0, 0, &res) == OTI_ERR_MEMORY && res.buf == NULL,
          "fix1.1: ARGMIN over 257 blocks (values and indices) -> MEMORY under the same budget");
    oti_ctx_init(&big);
    check(nd_reduce(&big, ND_RED_SUM, &a, -1, NULL, 0, 0, &res) == OTI_OK && get_f(&res, 0) == (double)n,
          "fix1.1: the same sum under the default budget is correct");
    nd_release(&res);
    // _to with an overlapping out: the overlap temporary is part of the same total (partials 2056 + 8)
    oti_ctx_init(&mid);
    mid.max_temp_bytes = 2060;
    ix[0].kind = ND_IDX_INT; ix[0].has = 0; ix[0].start = 0;
    ix[0].stop = 0; ix[0].step = 0; ix[0].arr = NULL;
    nd_view_index(&a, 1, ix, &out);                         // rank 0, overlaps the input
    check(nd_reduce_to(&mid, ND_RED_SUM, &a, -1, NULL, 0, 0, &out) == OTI_ERR_MEMORY,
          "fix1.1: partials (2056) plus the overlap temporary (8) exceed a 2060-byte budget -> MEMORY");
    set_f(&a, 0, 1.0);                                      // the failing call may have written it
    mid.max_temp_bytes = 1 << 20;
    check(nd_reduce_to(&mid, ND_RED_SUM, &a, -1, NULL, 0, 0, &out) == OTI_OK && get_f(&a, 0) == (double)n,
          "fix1.1: with a generous budget the overlapping reduction is correct");
    nd_release(&a);

    // checker 6: an empty (0,2) array with element strides (0, INT64_MAX): identities, no stride
    // arithmetic
    {
        int64_t esh[2] = {0, 2};
        int64_t est[2] = {0, INT64_MAX};
        ndarr_t e = {0};
        int32_t ax0 = 0, ax1 = 1;
        int st = nd_wrap_trusted(NULL, OTI_F64, 2, esh, est, 0, &e);
        check(st == OTI_OK,
                "fix1.6: a trusted empty (0,2) descriptor with strides (0, INT64_MAX) is valid");
        if (st == OTI_OK){
            check(nd_reduce(NULL, ND_RED_SUM, &e, 1, &ax0, 0, 0, &res) == OTI_OK && res.ndim == 1 &&
                  res.shape[0] == 2 && get_f(&res, 0) == 0.0 && get_f(&res, 1) == 0.0,
                  "fix1.6: SUM over the empty axis 0: zeros (2,), no overflow");
            nd_release(&res);
            check(nd_reduce(NULL, ND_RED_PROD, &e, 1, &ax0, 0, 0, &res) == OTI_OK && get_f(&res,
                    1) == 1.0,
                  "fix1.6: PROD over the empty axis 0: ones");
            nd_release(&res);
            check(nd_reduce(NULL, ND_RED_MEAN, &e, 1, &ax0, 1, 0, &res) == OTI_OK && isnan(get_f(&res,
                    0)) &&
                  res.ndim == 2 && res.shape[0] == 1,
                          "fix1.6: MEAN over the empty axis 0, keepdims: NaN (1,2)");
            nd_release(&res);
            check(nd_reduce(NULL, ND_RED_SUM, &e, 1, &ax1, 0, 0, &res) == OTI_OK && res.ndim == 1 &&
                  res.shape[0] == 0, "fix1.6: SUM over axis 1: an empty (0,)");
            nd_release(&res);
            check(nd_reduce(NULL, ND_RED_MAX, &e, 1, &ax0, 0, 0, &res) == OTI_ERR_SHAPE,
                  "fix1.6: MAX over the empty axis 0 -> SHAPE");
            check(nd_reduce(NULL, ND_RED_SUM, &e, -1, NULL, 0, 0, &res) == OTI_OK && get_f(&res,
                    0) == 0.0,
                  "fix1.6: SUM of everything: 0.0");
            nd_release(&res);
        }
        // an unused reduced axis with an arbitrary stride when another extent is zero
        {
            int64_t fsh[2] = {0, 3};
            int64_t fst[2] = {3, INT64_MAX};
            ndarr_t f = {0};
            st = nd_wrap_trusted(NULL, OTI_F64, 2, fsh, fst, 0, &f);
            if (st == OTI_OK){
                check(nd_reduce(NULL, ND_RED_SUM, &f, 1, &ax1, 0, 0, &res) == OTI_OK && res.shape[0] == 0,
                      "fix1.6: (0,3) with strides (3, INT64_MAX), SUM over axis 1: an empty (0,)");
                nd_release(&res);
            }
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    test_pairwise_sum();
    test_tree_combine();
    test_sum_1d_blocks();
    test_negative_zero_and_specials();
    test_sum_single_axis_bitwise();
    test_reduce_hand();
    test_reduce_errors();
    test_reduce_random_all_ops();
    test_reduce_to();
    test_reduce_determinism();
    test_reduce_soa();

    test_fix1_reduce();

    if (n_failed > 0){
        fprintf(stderr, "\n%d check(s) FAILED\n", n_failed);
        return 1;
    }
    printf("\nAll checks passed.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
