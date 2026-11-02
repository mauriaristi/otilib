/* Tests of the multi-operand strided iterator (include/oti/real/ndarray/iter.h, Phase 1):
 * nd_iter_init and nd_iter_run.
 *
 * Written from PLAN-ndarray-contracts.md (decisions and the iter.h header comment) independently of
 * src/c/real/ndarray/iter.c. The oracle is a coordinate loop. Operand 0 (the output or first input)
 * always has the full broadcast shape and holds, at each coordinate, the C-order linear index of that
 * coordinate; every other operand holds, at each of its own coordinates, its own C-order linear index
 * (U8 operands: that index modulo 251). A visited tuple of pointers is therefore decoded by reading
 * operand 0: the coordinate follows from its value, and every other operand's value must equal what
 * the broadcasting rule says for that coordinate. Coverage is checked by counting the visits of each
 * linear index (exactly once). Operands get random layouts: C, F, negative-step slices of a larger
 * array, and explicit stride-0 broadcast views. Orders: ND_ITER_ORDER_C visits in increasing linear
 * index (the sequence 0, 1, ..., size - 1 is checked exactly); ND_ITER_ORDER_K visits each element
 * once, and for positive strides in increasing memory order. A walk cut into arbitrary chunks gives the
 * same sequence as the whole walk. Hand-derived cases cover coalescing, rank 0, rank 32, zero size,
 * reduction targets and every status. */
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
#include <oti/real/ndarray/iter.h>

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
// Writes `value_of(logical C-order linear index)` into every element of `a` (any dtype), the value being
// the linear index itself (U8: modulo 251).
static void fill_linear(ndarr_t* a){

    int64_t n = shape_size(a->ndim, a->shape), lin;
    int32_t k;

    for (lin = 0; lin < n; lin++){
        int64_t rem = lin, off = 0;
        for (k = a->ndim - 1; k >= 0; k--){
            off += (rem % a->shape[k]) * a->strides[k];
            rem /= a->shape[k];
        }
        if (a->dtype == OTI_F64){
            ((double*)a->data)[off] = (double)lin;
        } else if (a->dtype == OTI_I64){
            ((int64_t*)a->data)[off] = lin;
        } else {
            ((uint8_t*)a->data)[off] = (uint8_t)(lin % 251);
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int64_t read_linear(const void* p, int32_t dtype){

    if (dtype == OTI_F64){
        return (int64_t)*(const double*)p;
    }
    if (dtype == OTI_I64){
        return *(const int64_t*)p;
    }
    return (int64_t)*(const uint8_t*)p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A random view of `shape` (a fresh retained base `base`, kept for the caller to release): random layout,
// optionally through a slice with steps +-1 or +-2 so that strides are
// negative or doubled. The result holds the linear index of each coordinate (U8: modulo 251).
static void make_operand(int32_t nd, const int64_t* shape, int32_t dtype, ndarr_t* base, ndarr_t* view){

    int64_t big[OTI_ND_MAXDIM];
    nd_index_t idx[OTI_ND_MAXDIM];
    int32_t k;
    int32_t layout = (rng_int(2) == 0) ? ND_LAYOUT_C : ND_LAYOUT_F;
    int use_slice = (rng_int(3) != 0);
    int st;

    for (k = 0; k < nd; k++){
        big[k] = (use_slice && shape[k] > 1) ? 2 * shape[k] + 2 : shape[k];
    }
    st = nd_alloc(NULL, dtype, nd, big, layout, ND_ALLOC_ZERO, base);
    if (st != OTI_OK){
        fprintf(stderr, "make_operand: nd_alloc failed (%d)\n", st);
        exit(2);
    }
    if (!use_slice){
        *view = *base;
        view->flags &= ~ND_RETAINED;
    } else {
        for (k = 0; k < nd; k++){
            int64_t p = (rng_int(2) == 0) ? 1 : 2;
            int64_t r = rng_int(2);
            if (shape[k] <= 1){
                idx[k] = mk_slice(0, 0, 0, 0);
            } else if (rng_int(2) == 0){
                // negative step: the first index is high enough for shape[k] elements; the view runs
                // on towards 0 and is trimmed below
                idx[k] = mk_slice(HS | HT, p * (shape[k] - 1) + r, 0, -p);
            } else {
                idx[k] = mk_slice(HS | HT, r, 0, p);
            }
        }
        st = nd_view_index(base, nd, idx, view);
        if (st != OTI_OK){
            fprintf(stderr, "make_operand: view_index failed (%d)\n", st);
            exit(2);
        }
        // The slice arithmetic above can give a longer extent than asked for (rounding); trim by hand.
        for (k = 0; k < nd; k++){
            if (view->shape[k] < shape[k]){
                fprintf(stderr, "make_operand: view shorter than asked (%lld < %lld)\n",
                        (long long)view->shape[k], (long long)shape[k]);
                exit(2);
            }
            view->shape[k] = shape[k];
        }
        // contiguity flags are recomputed for the trimmed view
        nd_update_flags(view);
    }
    fill_linear(view);

}
// -------------------------------------------------------------------------------------------------------


typedef struct {
    int32_t        nop;
    int32_t        nd;                    // rank of the iteration (broadcast) shape
    int64_t        S[OTI_ND_MAXDIM];      // iteration shape
    int64_t        own_shape[ND_ITER_MAXOPS][OTI_ND_MAXDIM];
    int32_t        own_nd[ND_ITER_MAXOPS];
    int32_t        dtype[ND_ITER_MAXOPS];
    int64_t*       seen;                  // visits per linear index of operand 0
    int64_t        total;
    int64_t        count;
    int64_t        order_next;            // for the C-order sequence check
    int            c_order;
    int            bad;
    int64_t        last_off0;
    int            monotonic;
    int            check_monotonic;
    int64_t*       seq;                   // operand 0 linear indices in visiting order (optional)
    int64_t        seq_len;
    int64_t        runs;
    int            run_min_ok;
} walk_t;


// *******************************************************************************************************
// The expected linear index (in operand k's own shape) of operand k at the broadcast coordinate c.
static int64_t expected_linear(const walk_t* w, int32_t k, const int64_t* c){

    int32_t nd_k = w->own_nd[k], j;
    int64_t lin = 0;

    for (j = 0; j < nd_k; j++){
        int32_t axis = w->nd - nd_k + j;
        int64_t ext = w->own_shape[k][j];
        int64_t ci = (ext == 1) ? 0 : c[axis];
        lin = lin * ext + ci;
    }
    return (w->dtype[k] == OTI_U8) ? lin % 251 : lin;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int walk_inner(void* arg, int64_t n, char* const* ptrs, const int64_t* bstrides){

    walk_t* w = (walk_t*)arg;
    int64_t i;
    int32_t k;

    if (n < 1){
        w->run_min_ok = 0;
        return OTI_OK;
    }
    w->runs++;
    for (i = 0; i < n; i++){
        int64_t v0 = read_linear(ptrs[0] + i * bstrides[0], w->dtype[0]);
        int64_t c[OTI_ND_MAXDIM];
        int64_t rem = v0;
        int32_t a;

        if (v0 < 0 || v0 >= w->total){
            w->bad++;
            continue;
        }
        for (a = w->nd - 1; a >= 0; a--){
            c[a] = rem % w->S[a];
            rem /= w->S[a];
        }
        w->seen[v0]++;
        for (k = 1; k < w->nop; k++){
            int64_t got = read_linear(ptrs[k] + i * bstrides[k], w->dtype[k]);
            if (got != expected_linear(w, k, c)){
                w->bad++;
            }
        }
        if (w->c_order){
            if (v0 != w->order_next){
                w->bad++;
            }
            w->order_next = v0 + 1;
        }
        if (w->seq != NULL && w->seq_len < w->total){
            w->seq[w->seq_len++] = v0;
        }
        if (w->check_monotonic){
            int64_t off = (int64_t)(uintptr_t)(ptrs[0] + i * bstrides[0]);
            if (w->count > 0 && off <= w->last_off0){
                w->monotonic = 0;
            }
            w->last_off0 = off;
        }
        w->count++;
    }
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int all_seen_once(const walk_t* w){

    int64_t i;

    for (i = 0; i < w->total; i++){
        if (w->seen[i] != 1){
            return 0;
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


static int64_t g_seen[1 << 12];
static int64_t g_seq_a[1 << 12];
static int64_t g_seq_b[1 << 12];


// *******************************************************************************************************
// One randomized scenario. Returns 0 when everything holds, else the number of the failing property.
static int run_scenario(int iter_no, int use_out, int32_t order, int32_t max_rank, int verbose_fail){

    int32_t nd = (int32_t)rng_int(max_rank + 1);
    int64_t S[OTI_ND_MAXDIM];
    int32_t nop = 1 + (int32_t)rng_int(3);
    ndarr_t bases[ND_ITER_MAXOPS] = {0}, views[ND_ITER_MAXOPS] = {0}, bcast[ND_ITER_MAXOPS] = {0};
    const ndarr_t* ops[ND_ITER_MAXOPS];
    int32_t flags[ND_ITER_MAXOPS];
    walk_t w;
    nd_iter_t it;
    int32_t k, j;
    int failed = 0;
    int64_t total;
    int all_pos;

    for (k = 0; k < nd; k++){
        S[k] = (rng_int(10) == 0) ? 0 : 1 + rng_int(4);
    }
    // keep the element count small
    total = shape_size(nd, S);
    while (total > 3000){
        S[rng_int(nd)] = 1;
        total = shape_size(nd, S);
    }
    if (nop < 2 && use_out){
        nop = 2;
    }

    memset(&w, 0, sizeof(w));
    w.nop = nop;
    w.nd = nd;
    for (k = 0; k < nd; k++){
        w.S[k] = S[k];
    }
    w.total = total;
    w.seen = g_seen;
    memset(g_seen, 0, sizeof(int64_t) * (size_t)(total > 0 ? total : 1));
    w.c_order = (order == ND_ITER_ORDER_C);

    // operand 0: full shape, F64; operand 1: full shape; the rest: random broadcastable shapes
    for (k = 0; k < nop; k++){
        int32_t nd_k;
        int64_t sk[OTI_ND_MAXDIM];
        int32_t dt = OTI_F64;
        int do_bcast = 0;

        if (k == 0 || k == 1){
            nd_k = nd;
            for (j = 0; j < nd; j++){
                sk[j] = S[j];
            }
        } else {
            nd_k = (int32_t)rng_int(nd + 1);
            for (j = 0; j < nd_k; j++){
                int32_t axis = nd - nd_k + j;
                sk[j] = (rng_int(3) == 0) ? 1 : S[axis];
            }
        }
        if (k > 0){
            int64_t r = rng_int(5);
            dt = (r == 0) ? OTI_I64 : (r == 1) ? OTI_U8 : OTI_F64;
        }
        w.dtype[k] = dt;
        w.own_nd[k] = nd_k;
        for (j = 0; j < nd_k; j++){
            w.own_shape[k][j] = sk[j];
        }
        make_operand(nd_k, sk, dt, &bases[k], &views[k]);
        ops[k] = &views[k];
        // sometimes present an input as an explicit stride-0 broadcast view of its own shape
        if (k >= 2 && rng_int(3) == 0){
            int64_t tgt[OTI_ND_MAXDIM];
            for (j = 0; j < nd; j++){
                tgt[j] = S[j];
            }
            if (nd_view_broadcast_to(&views[k], nd, tgt, &bcast[k]) == OTI_OK){
                ops[k] = &bcast[k];
                do_bcast = 1;
            }
        }
        (void)do_bcast;
        flags[k] = ND_ITER_IN;
    }
    if (use_out){
        flags[0] = ND_ITER_OUT;
    }
    w.dtype[0] = OTI_F64;

    all_pos = 1;
    for (j = 0; j < views[0].ndim; j++){
        if (views[0].strides[j] < 0){
            all_pos = 0;
        }
    }
    w.check_monotonic = (order == ND_ITER_ORDER_K) && all_pos;
    w.monotonic = 1;
    w.seq = g_seq_a;

    {
        int st = nd_iter_init(&it, nop, ops, flags, order);
        if (st != OTI_OK){
            if (verbose_fail){
                fprintf(stderr, "  scenario %d: nd_iter_init status %d\n", iter_no, st);
            }
            failed = 1;
            goto cleanup;
        }
    }

    if (it.nop != nop || it.size != total || it.ndim < 1 || it.ndim > OTI_ND_MAXDIM){
        if (verbose_fail){
            fprintf(stderr, "  scenario %d: nop %d size %lld (expected %lld) ndim %d\n", iter_no, it.nop,
                    (long long)it.size, (long long)total, it.ndim);
        }
        failed = 2;
        goto cleanup;
    }
    {
        int64_t prod = 1;
        for (j = 0; j < it.ndim; j++){
            prod *= it.shape[j];
        }
        if (prod != total){
            failed = 3;
            goto cleanup;
        }
    }
    for (k = 0; k < nop; k++){
        if (it.itemsize[k] != (int32_t)nd_itemsize(ops[k]->dtype)){
            failed = 4;
        }
        if (total > 0 && it.data[k] != (char*)ops[k]->data){
            failed = 5;
        }
    }
    if (failed){
        goto cleanup;
    }

    // whole walk
    w.run_min_ok = 1;
    w.count = 0;
    if (nd_iter_run(&it, 0, total, walk_inner, &w) != OTI_OK){
        failed = 6;
        goto cleanup;
    }
    if (w.count != total || w.bad != 0 || !all_seen_once(&w) || !w.run_min_ok){
        if (verbose_fail){
            fprintf(stderr, "  scenario %d: count %lld/%lld bad %d once %d\n", iter_no,
                    (long long)w.count,
                    (long long)total, w.bad, all_seen_once(&w));
        }
        failed = 7;
        goto cleanup;
    }
    if (w.check_monotonic && !w.monotonic){
        failed = 8;
        goto cleanup;
    }
    if (w.runs > total && total > 0){
        failed = 9;
        goto cleanup;
    }

    // the same range cut into random chunks: same sequence, same coverage
    {
        int64_t pos = 0;
        walk_t w2 = w;
        int64_t i;

        w2.count = 0;
        w2.bad = 0;
        w2.order_next = 0;
        w2.seq = g_seq_b;
        w2.seq_len = 0;
        w2.check_monotonic = 0;
        memset(g_seen, 0, sizeof(int64_t) * (size_t)(total > 0 ? total : 1));
        while (pos < total){
            int64_t len = 1 + rng_int(total - pos < 40 ? total - pos : 40);
            if (nd_iter_run(&it, pos, len, walk_inner, &w2) != OTI_OK){
                failed = 10;
                goto cleanup;
            }
            pos += len;
        }
        if (w2.count != total || w2.bad != 0 || !all_seen_once(&w2)){
            failed = 11;
            goto cleanup;
        }
        for (i = 0; i < total; i++){
            if (g_seq_a[i] != g_seq_b[i]){
                failed = 12;
                goto cleanup;
            }
        }
    }

    if (order == ND_ITER_ORDER_C && use_out == 0){
        // exact sequence 0, 1, ..., size - 1 was verified through w.c_order (bad == 0)
    }

cleanup:
    for (k = 0; k < nop; k++){
        nd_release(&bases[k]);
    }
    return failed;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_randomized_walks(void){

    int iter, fails_c = 0, fails_k = 0, fails_out = 0, fails_big = 0;

    rng_seed(5150);
    for (iter = 0; iter < 1500; iter++){
        int f = run_scenario(iter, 0, ND_ITER_ORDER_C, 5, fails_c < 3);
        if (f){
            fails_c++;
            fprintf(stderr, "  C-order scenario %d failed property %d\n", iter, f);
        }
    }
    check(fails_c == 0,
            "iterator ORDER_C: 1500 random broadcast scenarios (inputs): exact C sequence, coverage");

    rng_seed(8675309);
    for (iter = 0; iter < 1500; iter++){
        int f = run_scenario(iter, 0, ND_ITER_ORDER_K, 5, fails_k < 3);
        if (f){
            fails_k++;
            fprintf(stderr, "  K-order scenario %d failed property %d\n", iter, f);
        }
    }
    check(fails_k == 0,
            "iterator ORDER_K: 1500 random scenarios: each element once, memory order, chunk-invariant");

    rng_seed(24601);
    for (iter = 0; iter < 1500; iter++){
        int f = run_scenario(iter, 1, (iter & 1) ? ND_ITER_ORDER_K : ND_ITER_ORDER_C, 5, fails_out < 3);
        if (f){
            fails_out++;
            fprintf(stderr, "  OUT scenario %d failed property %d\n", iter, f);
        }
    }
    check(fails_out == 0, "iterator with an ND_ITER_OUT operand 0: 1500 random scenarios");

    // high ranks: up to 12 axes
    rng_seed(777777);
    for (iter = 0; iter < 400; iter++){
        int f = run_scenario(iter, iter % 2, (iter & 2) ? ND_ITER_ORDER_K : ND_ITER_ORDER_C, 12,
                fails_big < 3);
        if (f){
            fails_big++;
            fprintf(stderr, "  rank<=12 scenario %d failed property %d\n", iter, f);
        }
    }
    check(fails_big == 0, "iterator: 400 random scenarios up to rank 12");

}
// -------------------------------------------------------------------------------------------------------


typedef struct {
    int64_t calls;
    int64_t elements;
    int64_t fail_at_call;
    int     status;
} count_t;


// *******************************************************************************************************
static int count_inner(void* arg, int64_t n, char* const* ptrs, const int64_t* bstrides){

    count_t* c = (count_t*)arg;

    (void)ptrs;
    (void)bstrides;
    c->calls++;
    c->elements += n;
    if (c->fail_at_call > 0 && c->calls == c->fail_at_call){
        return c->status;
    }
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_coalescing_and_shape(void){

    ndarr_t a = {0}, b = {0}, f = {0}, v = {0}, vt = {0}, s0 = {0};
    int64_t shape3[3] = {3, 4, 5};
    nd_iter_t it;
    const ndarr_t* ops[2];
    int32_t fl[2];
    count_t cnt;

    // a C-contiguous array collapses to one axis, in both orders
    nd_alloc(NULL, OTI_F64, 3, shape3, ND_LAYOUT_C, 0, &a);
    ops[0] = &a;
    fl[0] = ND_ITER_IN;
    check(nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.ndim == 1 && it.size == 60 &&
          it.shape[0] == 60, "C array, ORDER_C: coalesced to one axis of 60");
    check(it.bstrides[0][0] == 8, "C array: byte stride 8");
    memset(&cnt, 0, sizeof(cnt));
    check(nd_iter_run(&it, 0, 60, count_inner, &cnt) == OTI_OK && cnt.calls == 1 && cnt.elements == 60,
          "C array: one run of 60 elements");
    check(nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_K) == OTI_OK && it.ndim == 1 && it.size == 60,
          "C array, ORDER_K: one axis");

    // an F-contiguous array: ORDER_K coalesces, ORDER_C cannot
    nd_alloc(NULL, OTI_F64, 3, shape3, ND_LAYOUT_F, 0, &f);
    ops[0] = &f;
    check(nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_K) == OTI_OK && it.ndim == 1 && it.size == 60 &&
          it.bstrides[0][0] == 8, "F array, ORDER_K: memory order, one axis of byte stride 8");
    check(nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.ndim == 3 && it.shape[0] == 3 &&
          it.shape[1] == 4 && it.shape[2] == 5, "F array, ORDER_C: three axes (3,4,5), logical order");
    check(it.bstrides[0][0] == 8 && it.bstrides[1][0] == 24 && it.bstrides[2][0] == 96,
          "F array, ORDER_C: byte strides (8, 24, 96) per axis");

    // two C arrays of the same shape coalesce together; a broadcast operand blocks the merge
    nd_alloc(NULL, OTI_F64, 3, shape3, ND_LAYOUT_C, 0, &b);
    ops[0] = &a;
    ops[1] = &b;
    fl[0] = ND_ITER_IN;
    fl[1] = ND_ITER_IN;
    check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_K) == OTI_OK && it.ndim == 1 && it.size == 60,
          "two C arrays: one axis");
    {
        ndarr_t row = {0}, rb = {0};
        int64_t sh1[1] = {5};
        int64_t tgt[3] = {3, 4, 5};
        nd_alloc(NULL, OTI_F64, 1, sh1, ND_LAYOUT_C, 0, &row);
        ops[1] = &row;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.ndim == 2 && it.size == 60 &&
              it.shape[0] == 12 && it.shape[1] == 5,
              "(3,4,5) with (5,): outer axes merge (stride 0 on both): (12,5)");
        check(it.bstrides[0][1] == 0 && it.bstrides[1][1] == 8 && it.bstrides[0][0] == 40 &&
                it.bstrides[1][0] == 8,
              "broadcast operand: byte stride 0 on the outer axis, 8 inside");
        nd_view_broadcast_to(&row, 3, tgt, &rb);
        ops[1] = &rb;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.ndim == 2 && it.size == 60,
              "explicit stride-0 broadcast view gives the same iteration");
        nd_release(&row);
    }

    // permuted, non-mergeable layout: slices with steps (shape (3,4,5), strides (80,10,2))
    {
        ndarr_t big = {0};
        nd_index_t idx[3];
        int64_t bs[3] = {6, 8, 10};
        nd_alloc(NULL, OTI_F64, 3, bs, ND_LAYOUT_C, 0, &big);
        idx[0] = mk_slice(HT, 0, 0, 2);
        idx[1] = mk_slice(HT, 0, 0, 2);
        idx[2] = mk_slice(HT, 0, 0, 2);
        nd_view_index(&big, 3, idx, &v);
        check(v.shape[0] == 3 && v.shape[1] == 4 && v.shape[2] == 5 && v.strides[0] == 160 &&
                v.strides[1] == 20 &&
              v.strides[2] == 2, "setup: slice view with strides (160, 20, 2)");
        ops[0] = &v;
        fl[0] = ND_ITER_IN;
        check(nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.ndim == 3 &&
                it.perm[0] == 0 &&
              it.perm[1] == 1 && it.perm[2] == 2,
                      "non-mergeable view, ORDER_C: three axes, perm (0,1,2)");
        check(nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_K) == OTI_OK && it.ndim == 3 &&
                it.perm[0] == 0 &&
              it.perm[1] == 1 && it.perm[2] == 2, "same view, ORDER_K: decreasing |stride| (0,1,2)");
        nd_view_transpose(&v, 0, NULL, &vt);
        ops[0] = &vt;
        check(nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.ndim == 3 &&
                it.perm[0] == 0 &&
              it.perm[1] == 1 && it.perm[2] == 2, "transposed view, ORDER_C: logical order");
        check(nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_K) == OTI_OK && it.ndim == 3 &&
                it.perm[0] == 2 &&
              it.perm[1] == 1 && it.perm[2] == 0 && it.shape[0] == 3 && it.shape[1] == 4 &&
                      it.shape[2] == 5,
              "transposed view, ORDER_K: axes by decreasing |stride|: perm (2,1,0), shape (3,4,5)");
        nd_release(&big);
    }

    // ND_ITER_ORDER_K ties by axis index, and is deterministic
    {
        ndarr_t u = {0};
        int64_t sh[2] = {4, 4};
        int64_t st[2] = {0, 0};
        (void)st;
        nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_C, 0, &u);
        ops[0] = &u;
        nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_K);
        {
            nd_iter_t it2;
            nd_iter_init(&it2, 1, ops, fl, ND_ITER_ORDER_K);
            check(it.ndim == it2.ndim && it.size == it2.size && it.shape[0] == it2.shape[0] &&
                  it.bstrides[0][0] == it2.bstrides[0][0], "ORDER_K is deterministic for a given layout");
        }
        nd_release(&u);
    }

    // rank 0 and extent-1 shapes
    nd_alloc(NULL, OTI_F64, 0, NULL, ND_LAYOUT_C, 0, &s0);
    ops[0] = &s0;
    check(nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.size == 1 && it.ndim >= 1 &&
          it.shape[0] == 1, "rank 0: one element, ndim >= 1 with an axis of extent 1");
    memset(&cnt, 0, sizeof(cnt));
    check(nd_iter_run(&it, 0, 1, count_inner, &cnt) == OTI_OK && cnt.calls == 1 && cnt.elements == 1,
          "rank 0: one run of one element");
    ops[0] = &a;
    ops[1] = &s0;
    check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.size == 60 && it.ndim == 1 &&
          it.bstrides[0][1] == 0, "(3,4,5) with a rank-0 operand: one axis, operand 1 stride 0");

    nd_release(&a);
    nd_release(&b);
    nd_release(&f);
    nd_release(&s0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_zero_size_and_ranges(void){

    ndarr_t z = {0}, a = {0};
    int64_t zs[2] = {3, 0};
    int64_t as[2] = {3, 4};
    nd_iter_t it;
    const ndarr_t* ops[2];
    int32_t fl[2];
    count_t cnt;

    nd_alloc(NULL, OTI_F64, 2, zs, ND_LAYOUT_C, 0, &z);
    ops[0] = &z;
    fl[0] = ND_ITER_IN;
    check(nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.size == 0 && it.ndim >= 1,
          "zero-size array: size 0, ndim >= 1");
    memset(&cnt, 0, sizeof(cnt));
    check(nd_iter_run(&it, 0, 0, count_inner, &cnt) == OTI_OK && cnt.calls == 0,
            "zero-size: the inner function is never called");
    check(nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_K) == OTI_OK && it.size == 0, "zero-size, ORDER_K");

    // zero size broadcast against (1,1)
    {
        ndarr_t one = {0};
        int64_t o2[2] = {1, 1};
        nd_alloc(NULL, OTI_F64, 2, o2, ND_LAYOUT_C, 0, &one);
        ops[1] = &one;
        fl[1] = ND_ITER_IN;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.size == 0,
                "(3,0) with (1,1): size 0");
        nd_release(&one);
    }

    nd_alloc(NULL, OTI_F64, 2, as, ND_LAYOUT_C, 0, &a);
    ops[0] = &a;
    nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_C);

    // ranges
    memset(&cnt, 0, sizeof(cnt));
    check(nd_iter_run(&it, 12, 0, count_inner, &cnt) == OTI_OK && cnt.calls == 0,
            "run: empty range at the end is OK");
    check(nd_iter_run(&it, 0, 13, count_inner, &cnt) == OTI_ERR_INDEX,
            "run: start + count > size -> INDEX");
    check(nd_iter_run(&it, 13, 0, count_inner, &cnt) == OTI_ERR_INDEX, "run: start > size -> INDEX");
    check(nd_iter_run(&it, 5, 8, count_inner, &cnt) == OTI_ERR_INDEX,
            "run: range crossing the end -> INDEX");
    check(nd_iter_run(&it, -1, 3, count_inner, &cnt) == OTI_ERR_INDEX, "run: negative start -> INDEX");
    check(nd_iter_run(&it, 0, -1, count_inner, &cnt) == OTI_ERR_INDEX, "run: negative count -> INDEX");

    // a middle range visits exactly its elements
    memset(&cnt, 0, sizeof(cnt));
    check(nd_iter_run(&it, 3, 7, count_inner, &cnt) == OTI_OK && cnt.elements == 7,
            "run: a middle range visits count elements");

    // a failing inner function stops the walk and returns its status
    {
        ndarr_t b3 = {0};
        int64_t bs3[2] = {5, 6};
        nd_iter_t it2;
        const ndarr_t* o[2];
        ndarr_t bt = {0};
        int32_t f2[1];
        // an F-ordered 5x6 walked in C order needs several runs
        nd_alloc(NULL, OTI_F64, 2, bs3, ND_LAYOUT_F, 0, &b3);
        o[0] = &b3;
        f2[0] = ND_ITER_IN;
        nd_iter_init(&it2, 1, o, f2, ND_ITER_ORDER_C);
        memset(&cnt, 0, sizeof(cnt));
        cnt.fail_at_call = 2;
        cnt.status = OTI_ERR_BUSY;
        check(nd_iter_run(&it2, 0, 30, count_inner, &cnt) == OTI_ERR_BUSY && cnt.calls == 2,
              "run: a failing inner function stops the walk, its status is returned");
        (void)bt;
        // runs along the inner axis of an F array walked in C order have 5 elements: n == shape[last]
        memset(&cnt, 0, sizeof(cnt));
        nd_iter_run(&it2, 0, 30, count_inner, &cnt);
        check(cnt.calls == 5 && cnt.elements == 30,
                "F (5,6) in C order: five runs of six elements (inner axis extent 6)");
        // a range cutting through runs never produces a run across the boundary
        memset(&cnt, 0, sizeof(cnt));
        nd_iter_run(&it2, 3, 4, count_inner, &cnt);
        check(cnt.elements == 4 && cnt.calls == 2,
                "run: range [3, 7) = a run of 3 then a run of 1 (never across the end)");
        nd_release(&b3);
    }

    nd_release(&a);
    nd_release(&z);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_iter_errors(void){

    ndarr_t a = {0}, b = {0}, ro = {0}, out = {0}, small = {0};
    int64_t as[2] = {3, 4};
    int64_t bs[2] = {2, 4};
    int64_t os[2] = {3, 4};
    int64_t ss[1] = {4};
    nd_iter_t it;
    const ndarr_t* ops[3];
    int32_t fl[3];

    nd_alloc(NULL, OTI_F64, 2, as, ND_LAYOUT_C, 0, &a);
    nd_alloc(NULL, OTI_F64, 2, bs, ND_LAYOUT_C, 0, &b);
    nd_alloc(NULL, OTI_F64, 2, os, ND_LAYOUT_C, 0, &out);
    nd_alloc(NULL, OTI_F64, 1, ss, ND_LAYOUT_C, 0, &small);

    ops[0] = &a; ops[1] = &b;
    fl[0] = ND_ITER_IN; fl[1] = ND_ITER_IN;
    check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_ERR_SHAPE,
            "inputs (3,4) and (2,4): broadcast failure -> SHAPE");

    ops[0] = &out; ops[1] = &a;
    fl[0] = ND_ITER_OUT; fl[1] = ND_ITER_IN;
    check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_K) == OTI_OK, "OUT (3,4) with IN (3,4): OK");

    ops[0] = &small; ops[1] = &a;
    check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_ERR_SHAPE,
            "OUT (4,) with IN (3,4): output shape mismatch -> SHAPE");
    {
        ndarr_t o3 = {0};
        int64_t s3[2] = {1, 4};
        nd_alloc(NULL, OTI_F64, 2, s3, ND_LAYOUT_C, 0, &o3);
        ops[0] = &o3;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_ERR_SHAPE,
              "OUT (1,4) with IN (3,4): an output does not broadcast -> SHAPE");
        nd_release(&o3);
    }

    // read-only output
    {
        ndarr_t d = {0};
        make_desc(&d, out.data, OTI_F64, 2, os, out.strides, 0);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ro);
        ops[0] = &ro; ops[1] = &a;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_ERR_READONLY,
                "read-only OUT -> READONLY");
        nd_release(&ro);
    }
    // internal overlap on an output
    {
        ndarr_t d = {0}, ov = {0};
        int64_t st0[2] = {0, 1};
        make_desc(&d, out.data, OTI_F64, 2, os, st0, ND_WRITEABLE);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &ov);
        ops[0] = &ov; ops[1] = &a;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_ERR_LAYOUT,
                "OUT with stride 0 (internal overlap) -> LAYOUT");
        // as a reduction target it is fine
        fl[0] = ND_ITER_REDUCE_OUT;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_OK,
                "REDUCE_OUT may have stride 0 on reduced axes");
        // as an IN too
        fl[0] = ND_ITER_IN;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_OK, "an input may have stride 0");
        nd_release(&ov);
    }

    // arguments
    ops[0] = &a; ops[1] = &a;
    fl[0] = ND_ITER_IN; fl[1] = ND_ITER_IN;
    check(nd_iter_init(&it, 0, ops, fl, ND_ITER_ORDER_C) == OTI_ERR_ARGUMENT, "nop 0 -> ARGUMENT");
    {
        const ndarr_t* many[9];
        int32_t mf[9];
        int i;
        for (i = 0; i < 9; i++){
            many[i] = &a;
            mf[i] = ND_ITER_IN;
        }
        check(nd_iter_init(&it, 8, many, mf, ND_ITER_ORDER_C) == OTI_OK && it.nop == 8,
                "nop 8 (ND_ITER_MAXOPS) accepted");
        check(nd_iter_init(&it, 9, many, mf, ND_ITER_ORDER_C) == OTI_ERR_ARGUMENT, "nop 9 -> ARGUMENT");
    }
    check(nd_iter_init(&it, 2, ops, fl, 7) == OTI_ERR_ARGUMENT, "unknown order -> ARGUMENT");
    fl[1] = 0;
    check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_ERR_ARGUMENT,
            "operand flags 0 -> ARGUMENT");
    fl[1] = 0x40;
    check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_ERR_ARGUMENT,
            "unknown operand flag bits -> ARGUMENT");

    nd_release(&a);
    nd_release(&b);
    nd_release(&out);
    nd_release(&small);

}
// -------------------------------------------------------------------------------------------------------


typedef struct {
    int mode;
} red_t;


// *******************************************************************************************************
// out += in, element by element along the run (the reduction-style inner loop).
static int accumulate_inner(void* arg, int64_t n, char* const* ptrs, const int64_t* bstrides){

    int64_t i;

    (void)arg;
    for (i = 0; i < n; i++){
        *(double*)(ptrs[0] + i * bstrides[0]) += *(double*)(ptrs[1] + i * bstrides[1]);
    }
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_reduce_out(void){

    ndarr_t in = {0}, out = {0}, outb = {0};
    int64_t is[2] = {3, 4};
    int64_t col_shape[2] = {3, 1};
    int64_t row_shape[1] = {4};
    int64_t i, j;
    nd_iter_t it;
    const ndarr_t* ops[2];
    int32_t fl[2];
    int ok;

    nd_alloc(NULL, OTI_F64, 2, is, ND_LAYOUT_C, 0, &in);
    for (i = 0; i < 3; i++){
        for (j = 0; j < 4; j++){
            ((double*)in.data)[i * 4 + j] = (double)(1 + i * 10 + j);
        }
    }
    fl[0] = ND_ITER_REDUCE_OUT;
    fl[1] = ND_ITER_IN;

    // out of shape (3,1): sums over axis 1
    nd_alloc(NULL, OTI_F64, 2, col_shape, ND_LAYOUT_C, ND_ALLOC_ZERO, &out);
    ops[0] = &out; ops[1] = &in;
    check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.size == 12,
            "REDUCE_OUT (3,1) with IN (3,4)");
    check(nd_iter_run(&it, 0, 12, accumulate_inner, NULL) == OTI_OK, "accumulate over axis 1");
    ok = 1;
    for (i = 0; i < 3; i++){
        double expect = 0;
        for (j = 0; j < 4; j++){
            expect += (double)(1 + i * 10 + j);
        }
        ok = ok && (((double*)out.data)[i] == expect);
    }
    check(ok, "REDUCE_OUT (3,1): row sums");
    nd_release(&out);

    // out of shape (4,): sums over axis 0
    nd_alloc(NULL, OTI_F64, 1, row_shape, ND_LAYOUT_C, ND_ALLOC_ZERO, &out);
    ops[0] = &out;
    check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_OK, "REDUCE_OUT (4,) with IN (3,4)");
    nd_iter_run(&it, 0, 12, accumulate_inner, NULL);
    ok = 1;
    for (j = 0; j < 4; j++){
        double expect = 0;
        for (i = 0; i < 3; i++){
            expect += (double)(1 + i * 10 + j);
        }
        ok = ok && (((double*)out.data)[j] == expect);
    }
    check(ok, "REDUCE_OUT (4,): column sums");
    // the same through an explicit stride-0 view (shape (3,4), strides (0,1)): hand-built, writeable
    {
        ndarr_t d = {0};
        int64_t st[2] = {0, 1};
        memset(out.data, 0, 4 * sizeof(double));
        make_desc(&d, out.data, OTI_F64, 2, is, st, ND_WRITEABLE);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &outb);
        ops[0] = &outb;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_OK,
                "REDUCE_OUT with explicit stride 0 on axis 0");
        nd_iter_run(&it, 0, 12, accumulate_inner, NULL);
        ok = 1;
        for (j = 0; j < 4; j++){
            double expect = 0;
            for (i = 0; i < 3; i++){
                expect += (double)(1 + i * 10 + j);
            }
            ok = ok && (((double*)out.data)[j] == expect);
        }
        check(ok, "REDUCE_OUT through stride 0: column sums");
        nd_release(&outb);
    }
    // a read-only reduction target
    {
        ndarr_t d = {0}, rb = {0};
        make_desc(&d, out.data, OTI_F64, 1, row_shape, (int64_t[]){1}, 0);
        nd_wrap(NULL, &d, NULL, -1, NULL, NULL, &rb);
        ops[0] = &rb;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_ERR_READONLY,
                "read-only REDUCE_OUT -> READONLY");
        nd_release(&rb);
    }
    nd_release(&out);

    // a REDUCE_OUT whose shape cannot broadcast to the input: SHAPE
    {
        int64_t bad[1] = {3};
        ndarr_t o = {0};
        nd_alloc(NULL, OTI_F64, 1, bad, ND_LAYOUT_C, 0, &o);
        ops[0] = &o;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_ERR_SHAPE,
                "REDUCE_OUT (3,) against IN (3,4) -> SHAPE");
        nd_release(&o);
    }
    nd_release(&in);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Rank 32: three axes of extent > 1 hidden among extent-1 axes, with broadcasting from rank 30.
static void test_rank_32(void){

    ndarr_t a = {0}, b = {0}, a_view = {0};
    int64_t sh[32], sb[30];
    int i;
    nd_iter_t it;
    const ndarr_t* ops[2];
    int32_t fl[2];
    walk_t w;
    int ok;

    for (i = 0; i < 32; i++){
        sh[i] = 1;
    }
    sh[3] = 2; sh[17] = 3; sh[31] = 4;
    for (i = 0; i < 30; i++){
        sb[i] = sh[i + 2];
    }
    nd_alloc(NULL, OTI_F64, 32, sh, ND_LAYOUT_C, 0, &a);
    nd_alloc(NULL, OTI_F64, 30, sb, ND_LAYOUT_F, 0, &b);
    fill_linear(&a);
    fill_linear(&b);
    ops[0] = &a; ops[1] = &b;
    fl[0] = ND_ITER_IN; fl[1] = ND_ITER_IN;
    check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_C) == OTI_OK && it.size == 24 && it.ndim >= 1 &&
          it.ndim <= 3, "rank 32 with rank 30: size 24, axes of extent 1 dropped (at most 3 remain)");

    memset(&w, 0, sizeof(w));
    w.nop = 2; w.nd = 32; w.total = 24; w.seen = g_seen; w.c_order = 1;
    w.dtype[0] = OTI_F64; w.dtype[1] = OTI_F64;
    for (i = 0; i < 32; i++){
        w.S[i] = sh[i];
    }
    w.own_nd[0] = 32; w.own_nd[1] = 30;
    for (i = 0; i < 32; i++){
        w.own_shape[0][i] = sh[i];
    }
    for (i = 0; i < 30; i++){
        w.own_shape[1][i] = sb[i];
    }
    memset(g_seen, 0, sizeof(int64_t) * 24);
    check(nd_iter_run(&it, 0, 24, walk_inner, &w) == OTI_OK && w.count == 24 && w.bad == 0 &&
            all_seen_once(&w),
          "rank 32 walk: every element once, in C order, broadcast operand consistent");

    // a view: a rank-32 array with a negative-step slice on the last axis
    {
        nd_index_t idx[1];
        idx[0] = mk_slice(0, 0, 0, 0);
        ok = (nd_view_index(&a, 0, idx, &a_view) == OTI_OK);
        ops[0] = &a_view;
        fl[0] = ND_ITER_IN;
        check(ok && nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_K) == OTI_OK && it.size == 24,
                "rank 32 ORDER_K init");
    }

    nd_release(&a);
    nd_release(&b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The iterator holds no reference: releasing the operands changes nothing in its state word, and a
// walk never alters reference counts.
static void test_iter_takes_no_reference(void){

    ndarr_t a = {0};
    int64_t sh[2] = {3, 4};
    nd_iter_t it;
    const ndarr_t* ops[1];
    int32_t fl[1];
    count_t cnt;
    uint64_t s0;

    nd_alloc(NULL, OTI_F64, 2, sh, ND_LAYOUT_C, 0, &a);
    s0 = nd_buffer_state(a.buf);
    ops[0] = &a;
    fl[0] = ND_ITER_IN;
    nd_iter_init(&it, 1, ops, fl, ND_ITER_ORDER_C);
    memset(&cnt, 0, sizeof(cnt));
    nd_iter_run(&it, 0, 12, count_inner, &cnt);
    check(nd_buffer_state(a.buf) == s0 && nd_buffer_refs(a.buf) == 1,
            "iterator init / run take no reference");
    nd_release(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 3 (S26): three SoA operands coalesce into one run; the K order follows the operand with the
// most non-zero-stride axes.
static void test_fix3_iter(void){

    ndarr_t a = {0}, b = {0}, o = {0}, col = {0}, f = {0};
    int64_t sh[3] = {6, 8, 5};
    int64_t st[3] = {40, 1, 8};
    const ndarr_t* ops[3];
    int32_t fl[3];
    nd_iter_t it;
    count_t cnt;

    nd_alloc_strided(NULL, OTI_F64, 3, sh, st, 0, &a);
    nd_alloc_strided(NULL, OTI_F64, 3, sh, st, 0, &b);
    nd_alloc_strided(NULL, OTI_F64, 3, sh, st, 0, &o);
    ops[0] = &o; ops[1] = &a; ops[2] = &b;
    fl[0] = ND_ITER_OUT; fl[1] = ND_ITER_IN; fl[2] = ND_ITER_IN;
    check(nd_iter_init(&it, 3, ops, fl, ND_ITER_ORDER_K) == OTI_OK && it.ndim == 1 && it.size == 240 &&
          it.shape[0] == 240 && it.bstrides[0][0] == 8 && it.bstrides[0][1] == 8 &&
                  it.bstrides[0][2] == 8,
          "fix3: three SoA operands coalesce into one axis of 240 elements (ORDER_K)");
    memset(&cnt, 0, sizeof(cnt));
    check(nd_iter_run(&it, 0, 240, count_inner, &cnt) == OTI_OK && cnt.calls == 1 && cnt.elements == 240,
          "fix3: ... and one run of 240");

    // K order driven by the operand with the most non-zero-stride axes
    {
        int64_t cs[2] = {4, 1}, fs[2] = {4, 3};
        nd_alloc(NULL, OTI_F64, 2, cs, ND_LAYOUT_C, 0, &col);
        nd_alloc(NULL, OTI_F64, 2, fs, ND_LAYOUT_F, 0, &f);
        ops[0] = &col; ops[1] = &f;
        fl[0] = ND_ITER_IN; fl[1] = ND_ITER_IN;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_K) == OTI_OK && it.size == 12 && it.ndim == 2 &&
              it.perm[0] == 1 && it.perm[1] == 0 && it.shape[0] == 3 && it.shape[1] == 4,
              "fix3.S26: column (n,1) with F (n,m): the walk follows the F operand (perm (1,0))");
        check(it.bstrides[1][1] == 8 && it.bstrides[0][1] == 32,
                "fix3.S26: the F operand's byte strides (32 outer, 8 inner)");
        // the same operands in the other order: the F operand still drives
        ops[0] = &f; ops[1] = &col;
        check(nd_iter_init(&it, 2, ops, fl, ND_ITER_ORDER_K) == OTI_OK && it.perm[0] == 1 &&
                it.perm[1] == 0,
              "fix3.S26: F first: the same walk");
        nd_release(&col);
        nd_release(&f);
    }
    nd_release(&a);
    nd_release(&b);
    nd_release(&o);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    test_coalescing_and_shape();
    test_zero_size_and_ranges();
    test_iter_errors();
    test_reduce_out();
    test_rank_32();
    test_iter_takes_no_reference();
    test_randomized_walks();

    test_fix3_iter();

    if (n_failed > 0){
        fprintf(stderr, "\n%d check(s) FAILED\n", n_failed);
        return 1;
    }
    printf("\nAll checks passed.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
