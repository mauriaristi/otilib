/* Tests of the OTI layout metadata (include/oti/core/meta.h, src/c/core/meta.c, Phase 7a):
   oti_meta_create /
 * retain / release / shared, the layout transaction (oti_meta_layout_begin / relayout / layout_end
 * together
 * with nd_grow_locked), the act functions and oti_meta_fits.
 *
 * Written from PLAN-ndarray-contracts.md sections 7.1-7.3 and the header, independently of meta.c.
 * Oracles:
 * the documented field values (what each call must leave in the struct), the state word of the root's
 * buffer
 * (nd_buffer_state: the GROWING bit says whether the layout lock is held; refs and exports through
 * nd_buffer_refs / nd_buffer_exports), subset and order rules of 7.3 stated by hand, and thread counters
 * for the
 * refcount. Allocation failures use nd_test_fail_alloc(); leaks are checked by the lead (leaks / ASan).
 * */
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L   // pthreads under -std=c99 on Linux (contracts S23)
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <oti/comm.h>
#include <oti/core/exec.h>
#include <oti/core/meta.h>
#include <oti/real/ndarray/structures.h>
#include <oti/real/ndarray/buffer.h>
#include <oti/real/ndarray/create.h>

static int n_failed = 0;


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
static int growing(const ndarr_t* a){

    return (nd_buffer_state(a->buf) & ND_STATE_GROWING) != 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int i64_matches(const oti_meta_t* m, const bases_t* b, int32_t n){

    int32_t i;

    if (m->bases_i64 == NULL){
        return 0;
    }
    for (i = 0; i < n; i++){
        if (m->bases_i64[i] != (int64_t)b[i]){
            return 0;
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 7.1 Creation, fields
// =======================================================================================================

// *******************************************************************************************************
static void test_create_fields(void){

    oti_meta_t* m = NULL;
    bases_t lab[3] = {2, 5, 9};

    check(oti_meta_create(OTI_META_DENSE, 3, 4, NULL, 0, &m) == OTI_OK && m != NULL, "create dense: OK");
    check(m->refs == 1 && m->kind == OTI_META_DENSE && m->trc_order == 3 && m->nbases == 4 &&
            m->act_order == 0,
          "dense: refs 1, kind DENSE, trc 3, nbases 4, act 0");
    check(m->bases == NULL && m->bases_i64 == NULL && m->cap_bases == 0 && m->reserved == 0,
          "dense: bases and bases_i64 NULL, cap_bases 0, reserved 0");
    check(!oti_meta_shared(m), "a fresh meta is not shared");
    oti_meta_release(&m);
    check(m == NULL, "release sets the caller's pointer to NULL");

    check(oti_meta_create(OTI_META_BASES, 2, 3, lab, 8, &m) == OTI_OK && m != NULL, "create bases: OK");
    check(m->kind == OTI_META_BASES && m->trc_order == 2 && m->nbases == 3 && m->cap_bases == 8 &&
            m->refs == 1 &&
          m->act_order == 0, "bases: kind BASES, trc 2, nbases 3, cap_bases 8, refs 1, act 0");
    check(m->bases != NULL && m->bases != lab && m->bases[0] == 2 && m->bases[1] == 5 && m->bases[2] == 9,
          "bases: the labels are copied (own storage)");
    check(m->bases_i64 != NULL && i64_matches(m, lab, 3),
          "bases: bases_i64 is built eagerly at creation and holds {2, 5, 9} ([cL10])");
    check(m->bases_i64 != (int64_t*)m->bases, "bases_i64 is a separate int64 array");
    lab[0] = 77;
    check(m->bases[0] == 2, "changing the caller's label array afterwards does not change the meta");
    oti_meta_release(&m);

    // capacity larger than nbases, zero labels, maximum order
    check(oti_meta_create(OTI_META_BASES, 0, 0, NULL, 4, &m) == OTI_OK && m->nbases == 0 &&
            m->cap_bases >= 0,
          "bases with zero labels and no label array: OK");
    oti_meta_release(&m);
    check(oti_meta_create(OTI_META_DENSE, _MAXORDER_OTI, 0, NULL, 0, &m) == OTI_OK &&
            m->trc_order == _MAXORDER_OTI,
          "trc_order _MAXORDER_OTI (150) is accepted");
    oti_meta_release(&m);
    check(oti_meta_create(OTI_META_DENSE, 0, 0, NULL, 0, &m) == OTI_OK && m->trc_order == 0,
            "trc_order 0, nbases 0");
    oti_meta_release(&m);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_create_errors(void){

    oti_meta_t* m = (oti_meta_t*)0x1;
    bases_t unsorted[2] = {5, 2}, dup[2] = {3, 3}, ok2[2] = {1, 4};

    check(oti_meta_create(7, 2, 3, NULL, 0, &m) == OTI_ERR_ARGUMENT && m == NULL,
            "unknown kind -> ARGUMENT, *res NULL");
    m = (oti_meta_t*)0x1;
    check(oti_meta_create(OTI_META_BASES, 2, 2, unsorted, 4, &m) == OTI_ERR_ARGUMENT && m == NULL,
          "unsorted labels -> ARGUMENT, *res NULL");
    m = (oti_meta_t*)0x1;
    check(oti_meta_create(OTI_META_BASES, 2, 2, dup, 4, &m) == OTI_ERR_ARGUMENT && m == NULL,
          "duplicate labels -> ARGUMENT");
    m = (oti_meta_t*)0x1;
    check(oti_meta_create(OTI_META_BASES, 2, 2, NULL, 4, &m) == OTI_ERR_ARGUMENT && m == NULL,
          "bases kind with nbases > 0 and NULL labels -> ARGUMENT");
    m = (oti_meta_t*)0x1;
    check(oti_meta_create(OTI_META_BASES, 2, 2, ok2, 1, &m) == OTI_ERR_ARGUMENT && m == NULL,
          "cap_bases below nbases -> ARGUMENT");
    m = (oti_meta_t*)0x1;
    check(oti_meta_create(OTI_META_DENSE, _MAXORDER_OTI + 1, 3, NULL, 0, &m) == OTI_ERR_INDEX &&
            m == NULL,
          "trc_order above the maximum -> INDEX, *res NULL");
    m = (oti_meta_t*)0x1;
    check(oti_meta_create(OTI_META_DENSE, -1, 3, NULL, 0, &m) != OTI_OK && m == NULL,
          "a negative order is rejected, *res NULL");
    check(oti_meta_create(OTI_META_DENSE, 2, 3, NULL, 0, NULL) == OTI_ERR_ARGUMENT,
            "NULL res -> ARGUMENT");
    m = (oti_meta_t*)0x1;
    check(oti_meta_create(OTI_META_DENSE, 2, 3, ok2, 0, &m) == OTI_ERR_ARGUMENT && m == NULL,
          "labels given for a dense meta -> ARGUMENT");
    m = (oti_meta_t*)0x1;
    check(oti_meta_create(OTI_META_DENSE, 2, 65536, NULL, 0, &m) == OTI_ERR_ARGUMENT && m == NULL,
          "nbases above 65535 (bases_t) -> ARGUMENT");
    m = (oti_meta_t*)0x1;
    check(oti_meta_create(OTI_META_BASES, 2, 2, ok2, 65536, &m) == OTI_ERR_ARGUMENT && m == NULL,
          "cap_bases above 65535 -> ARGUMENT");
    {
        oti_meta_t* d = NULL;
        check(oti_meta_create(OTI_META_DENSE, 2, 3, NULL, 99, &d) == OTI_OK && d->cap_bases == 0,
              "a dense meta ignores cap_bases and keeps cap_bases 0");
        oti_meta_release(&d);
    }

    // allocation failure at every allocation of a bases-kind creation, then success
    {
        int k, saw = 0, finished = 0, ok = 1;
        for (k = 1; k < 12 && !finished; k++){
            int st;
            m = (oti_meta_t*)0x1;
            oti_meta_test_fail_alloc(k);
            st = oti_meta_create(OTI_META_BASES, 3, 2, ok2, 6, &m);
            oti_meta_test_fail_alloc(0);
            if (st == OTI_OK){
                finished = 1;
                oti_meta_release(&m);
            } else {
                saw++;
                ok = ok && st == OTI_ERR_MEMORY && m == NULL;
            }
        }
        check(finished, "creation succeeds once the injected failure is past the last allocation");
        check(saw >= 1 && ok,
                "creation: an allocation failure -> MEMORY, *res NULL (no partial block remains)");
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Refcounting
// =======================================================================================================

typedef struct {
    oti_meta_t* m;
    int         rounds;
} rc_t;

// *******************************************************************************************************
static void* rc_thread(void* p){

    rc_t* r = (rc_t*)p;
    int i;

    for (i = 0; i < r->rounds; i++){
        oti_meta_t* mine = oti_meta_retain(r->m);
        oti_meta_release(&mine);
    }
    return NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_refcount(void){

    oti_meta_t* m = NULL;
    oti_meta_t* a;
    oti_meta_t* b;
    oti_meta_t* none = NULL;

    oti_meta_create(OTI_META_DENSE, 2, 2, NULL, 0, &m);
    a = oti_meta_retain(m);
    check(a == m && m->refs == 2 && oti_meta_shared(m), "retain returns the same block, refs 2, shared");
    b = oti_meta_retain(m);
    check(m->refs == 3, "second retain: refs 3");
    oti_meta_release(&b);
    check(b == NULL && m->refs == 2 && oti_meta_shared(m), "release: refs 2, caller's pointer NULL");
    oti_meta_release(&a);
    check(m->refs == 1 && !oti_meta_shared(m), "back to refs 1, not shared");
    oti_meta_release(&none);
    oti_meta_release(NULL);
    check(1, "release of a NULL pointer and of NULL itself are no-ops");
    oti_meta_release(&m);
    check(m == NULL, "the last release frees the block and clears the pointer");

    // concurrent retain / release from four threads: the count returns to 1
    {
        pthread_t th[4];
        rc_t rs[4];
        int t;
        oti_meta_create(OTI_META_BASES, 2, 3, (const bases_t[]){1, 2, 3}, 4, &m);
        for (t = 0; t < 4; t++){
            rs[t].m = m;
            rs[t].rounds = 50000;
            pthread_create(&th[t], NULL, rc_thread, &rs[t]);
        }
        for (t = 0; t < 4; t++){
            pthread_join(th[t], NULL);
        }
        check(m->refs == 1, "4 threads x 50000 retain / release: refs back to exactly 1");
        oti_meta_release(&m);
    }

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 7.2 Layout transactions
// =======================================================================================================

// *******************************************************************************************************
static void make_root(ndarr_t* a){

    int64_t sh[1] = {64};

    nd_init_empty(a);
    if (nd_alloc(NULL, OTI_F64, 1, sh, ND_LAYOUT_C, ND_ALLOC_ZERO, a) != OTI_OK){
        fprintf(stderr, "make_root failed\n");
        exit(2);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_layout_begin_busy(void){

    oti_meta_t* m = NULL;
    ndarr_t root, v, e;
    oti_meta_t* extra;

    oti_meta_create(OTI_META_DENSE, 3, 4, NULL, 0, &m);
    make_root(&root);

    // success: the lock is held until layout_end
    check(oti_meta_layout_begin(m, root.buf) == OTI_OK && growing(&root),
            "layout_begin on an unshared meta and a sole-owner buffer: OK, lock held");
    check(oti_meta_layout_begin(m, root.buf) == OTI_ERR_BUSY,
            "a second layout_begin while the lock is held -> BUSY");
    oti_meta_layout_end(m, root.buf);
    check(!growing(&root), "layout_end releases the buffer's layout lock");

    // an OTI view shares the meta (refs 2): BUSY, and the buffer lock is NOT taken
    extra = oti_meta_retain(m);
    check(oti_meta_layout_begin(m, root.buf) == OTI_ERR_BUSY && !growing(&root),
          "layout_begin with refs 2 (an OTI view) -> BUSY, the buffer lock is not taken");
    oti_meta_release(&extra);
    check(oti_meta_layout_begin(m, root.buf) == OTI_OK, "after the view is gone it succeeds");
    oti_meta_layout_end(m, root.buf);

    // another reference to the buffer (a retained view)
    nd_init_empty(&v);
    nd_view_retain(&root, &v);
    check(oti_meta_layout_begin(m, root.buf) == OTI_ERR_BUSY && !growing(&root),
          "layout_begin with a second buffer reference -> BUSY, no lock");
    nd_release(&v);
    // an export (a NumPy base object)
    nd_init_empty(&e);
    nd_export(&root, 0, &e);
    check(oti_meta_layout_begin(m, root.buf) == OTI_ERR_BUSY && !growing(&root),
          "layout_begin with a live export -> BUSY");
    nd_release(&e);
    check(oti_meta_layout_begin(m, root.buf) == OTI_OK && growing(&root),
            "after the export ends it succeeds");
    // while the transaction is open, retain and export of the buffer fail with BUSY
    nd_init_empty(&v);
    check(nd_view_retain(&root, &v) == OTI_ERR_BUSY,
            "inside the transaction a retain of the buffer -> BUSY");
    check(nd_export(&root, 0, &v) == OTI_ERR_BUSY, "inside the transaction an export -> BUSY");
    oti_meta_layout_end(m, root.buf);
    check(oti_meta_layout_begin(NULL, root.buf) == OTI_ERR_ARGUMENT && !growing(&root),
          "layout_begin(NULL meta) -> ARGUMENT, nothing held");
    check(oti_meta_layout_begin(m, NULL) == OTI_ERR_ARGUMENT, "layout_begin(NULL buffer) -> ARGUMENT");
    nd_release(&root);
    oti_meta_release(&m);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// One relayout transaction (contracts 7.2, [k4]): begin, nd_grow_locked, move blocks, relayout, end.
static void test_transaction_with_growth(void){

    oti_meta_t* m = NULL;
    ndarr_t root;
    int64_t i;
    double* before;
    int ok = 1;

    oti_meta_create(OTI_META_DENSE, 2, 3, NULL, 0, &m);
    make_root(&root);
    for (i = 0; i < 8; i++){
        ((double*)root.data)[i] = 10.0 + (double)i;
    }
    before = (double*)root.data;
    check(oti_meta_layout_begin(m, root.buf) == OTI_OK, "transaction: begin");
    check(nd_grow(NULL, &root, 4096, 64) == OTI_ERR_BUSY,
            "inside the transaction nd_grow (which locks itself) -> BUSY");
    check(nd_grow_locked(NULL, &root, 4096, 64) == OTI_OK,
            "inside the transaction nd_grow_locked succeeds");
    check(growing(&root), "the lock is still held after nd_grow_locked");
    for (i = 0; i < 8; i++){
        ok = ok && ((double*)root.data)[i] == 10.0 + (double)i;
    }
    check(ok, "the grown buffer keeps the first keep_bytes bytes");
    (void)before;
    check(oti_meta_relayout(m, 4, 7, NULL) == OTI_OK && m->trc_order == 4 && m->nbases == 7 &&
            m->bases == NULL,
          "relayout (dense): trc 4, nbases 7");
    oti_meta_layout_end(m, root.buf);
    check(!growing(&root) && nd_buffer_nbytes(root.buf) >= 4096,
            "end: the lock is released; the buffer is bigger");
    nd_release(&root);
    oti_meta_release(&m);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_relayout(void){

    oti_meta_t* m = NULL;
    ndarr_t root;
    bases_t lab[3] = {2, 5, 9};
    bases_t more[6] = {1, 2, 5, 9, 10, 40};
    bases_t unsorted[2] = {7, 3};
    bases_t shrink[2] = {5, 40};

    // dense: act clipped to the new trc
    oti_meta_create(OTI_META_DENSE, 4, 3, NULL, 0, &m);
    oti_meta_raise_act(m, 4);
    make_root(&root);
    oti_meta_layout_begin(m, root.buf);
    check(oti_meta_relayout(m, 2, 5, NULL) == OTI_OK && m->trc_order == 2 && m->nbases == 5 &&
            m->act_order == 2,
          "relayout to trc 2: act_order 4 is clipped to 2");
    check(oti_meta_relayout(m, 6, 1, NULL) == OTI_OK && m->trc_order == 6 && m->nbases == 1 &&
            m->act_order == 2,
          "relayout to a higher trc leaves act_order alone");
    check(oti_meta_relayout(m, _MAXORDER_OTI + 1, 1, NULL) == OTI_ERR_INDEX && m->trc_order == 6 &&
            m->nbases == 1,
          "relayout above the maximum order -> INDEX, fields unchanged");
    oti_meta_layout_end(m, root.buf);
    oti_meta_release(&m);

    // bases kind: labels replaced, capacity grown, bases_i64 rebuilt
    oti_meta_create(OTI_META_BASES, 3, 3, lab, 3, &m);
    check(m->cap_bases >= 3, "initial capacity covers the labels");
    oti_meta_layout_begin(m, root.buf);
    check(oti_meta_relayout(m, 3, 6, more) == OTI_OK && m->nbases == 6 && m->cap_bases >= 6,
          "relayout to 6 labels grows the capacity");
    {
        int ok = 1, i;
        for (i = 0; i < 6; i++){
            ok = ok && m->bases[i] == more[i] && m->bases_i64[i] == (int64_t)more[i];
        }
        check(ok, "bases and bases_i64 hold {1, 2, 5, 9, 10, 40} (bases_i64 rebuilt eagerly)");
    }
    check(m->bases != more, "the new labels are copied");
    check(oti_meta_relayout(m, 3, 2, shrink) == OTI_OK && m->nbases == 2 && m->bases[0] == 5 &&
            m->bases[1] == 40 &&
          m->bases_i64[0] == 5 && m->bases_i64[1] == 40, "relayout to 2 labels: {5, 40} in both arrays");
    check(m->cap_bases >= m->nbases, "the capacity never drops below nbases");
    check(oti_meta_relayout(m, 3, 2, unsorted) == OTI_ERR_ARGUMENT && m->nbases == 2 &&
            m->bases[0] == 5 &&
          m->bases[1] == 40 && m->bases_i64[0] == 5,
                  "unsorted labels -> ARGUMENT, the layout is unchanged");
    check(oti_meta_relayout(m, 3, 2, NULL) == OTI_ERR_ARGUMENT && m->bases[0] == 5,
            "NULL labels for a bases meta -> ARGUMENT");
    // the new labels may point into the meta's own array
    check(oti_meta_relayout(m, 3, 1, m->bases + 1) == OTI_OK && m->nbases == 1 && m->bases[0] == 40 &&
          m->bases_i64[0] == 40, "relayout with labels pointing into the meta's own array");
    check(oti_meta_relayout(m, 3, 2, shrink) == OTI_OK && m->nbases == 2, "back to {5, 40}");
    // a relayout past the current capacity makes the capacity equal to nbases
    {
        bases_t seven[7] = {1, 2, 3, 4, 5, 6, 7};
        oti_meta_t* c = NULL;
        ndarr_t r2;
        make_root(&r2);
        oti_meta_create(OTI_META_BASES, 1, 1, seven, 1, &c);
        oti_meta_layout_begin(c, r2.buf);
        check(oti_meta_relayout(c, 1, 7, seven) == OTI_OK && c->cap_bases == 7 && c->nbases == 7,
              "relayout past the capacity: cap_bases becomes nbases (7)");
        oti_meta_layout_end(c, r2.buf);
        nd_release(&r2);
        oti_meta_release(&c);
    }
    // allocation failure while growing the labels: MEMORY, unchanged
    {
        int k, saw = 0, finished = 0, ok = 1;
        bases_t big[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (k = 1; k < 10 && !finished; k++){
            int st;
            oti_meta_test_fail_alloc(k);
            st = oti_meta_relayout(m, 3, 9, big);
            oti_meta_test_fail_alloc(0);
            if (st == OTI_OK){
                finished = 1;
                ok = ok && m->nbases == 9 && m->bases[8] == 9 && m->bases_i64[8] == 9;
            } else {
                saw++;
                ok = ok && st == OTI_ERR_MEMORY && m->nbases == 2 && m->bases[0] == 5 &&
                        m->bases[1] == 40 &&
                     m->bases_i64[1] == 40;
            }
        }
        check(finished && ok,
                "relayout growing the labels: MEMORY leaves every field unchanged, then success");
        (void)saw;
    }
    oti_meta_layout_end(m, root.buf);
    nd_release(&root);
    oti_meta_release(&m);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// 7.3 / 7.4 act and fit
// =======================================================================================================

// *******************************************************************************************************
static void test_act(void){

    oti_meta_t* m = NULL;

    oti_meta_create(OTI_META_DENSE, 3, 2, NULL, 0, &m);
    oti_meta_raise_act(m, 2);
    check(m->act_order == 2, "raise_act(2): act 2");
    oti_meta_raise_act(m, 1);
    check(m->act_order == 2, "raise_act never lowers");
    oti_meta_raise_act(m, 9);
    check(m->act_order == 3, "raise_act(9) with trc 3: clipped to 3");
    oti_meta_raise_act(m, -4);
    check(m->act_order == 3, "raise_act of a negative value changes nothing");
    oti_meta_set_act(m, 1);
    check(m->act_order == 1, "set_act(1) on an unshared meta sets the exact value (may lower it)");
    oti_meta_set_act(m, 0);
    check(m->act_order == 0, "set_act(0)");
    oti_meta_set_act(m, 99);
    check(m->act_order == 3, "set_act above trc is clipped to trc");
    oti_meta_set_act(m, -2);
    check(m->act_order == 0, "set_act below 0 is clipped to 0");
    oti_meta_set_act(m, 3);
    check(m->act_order == 3, "set_act(3) == trc");
    {
        // a shared meta: raise_act through a view still works and never lowers
        oti_meta_t* view = oti_meta_retain(m);
        oti_meta_raise_act(view, 2);
        check(m->act_order == 3 && oti_meta_shared(m),
                "raise_act through a shared meta never lowers act");
        oti_meta_release(&view);
    }
    oti_meta_release(&m);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_fits(void){

    oti_meta_t* d = NULL;
    oti_meta_t* s = NULL;
    bases_t sub[2] = {2, 9}, notsub[2] = {2, 7}, sup[4] = {2, 5, 9, 11}, same[3] = {2, 5, 9},
            one[1] = {5};

    oti_meta_create(OTI_META_DENSE, 3, 4, NULL, 0, &d);
    check(oti_meta_fits(d, 3, 4, NULL) == 1, "dense (trc 3, nbases 4) fits a value of (3, 4)");
    check(oti_meta_fits(d, 2, 2, NULL) == 1, "dense fits a smaller value (2, 2)");
    check(oti_meta_fits(d, 0, 0, NULL) == 1, "dense fits (0, 0)");
    check(oti_meta_fits(d, 4, 4, NULL) == 0, "dense does not fit a higher truncation order (4, 4)");
    check(oti_meta_fits(d, 3, 5, NULL) == 0, "dense does not fit nact 5 > 4");
    check(oti_meta_fits(d, 3, 0, NULL) == 1 && oti_meta_fits(d, 1, 4, NULL) == 1,
            "dense: (3, 0) and (1, 4) fit");
    oti_meta_release(&d);

    oti_meta_create(OTI_META_BASES, 3, 3, same, 8, &s);
    check(oti_meta_fits(s, 3, 3, same) == 1, "bases {2,5,9}: the same labels fit");
    check(oti_meta_fits(s, 2, 2, sub) == 1, "bases: the subset {2, 9} fits");
    check(oti_meta_fits(s, 3, 1, one) == 1, "bases: {5} fits");
    check(oti_meta_fits(s, 3, 0, NULL) == 1, "bases: no labels fit (a real value)");
    check(oti_meta_fits(s, 3, 2, notsub) == 0, "bases: {2, 7} is not a subset");
    check(oti_meta_fits(s, 3, 4, sup) == 0, "bases: the superset {2,5,9,11} does not fit");
    check(oti_meta_fits(s, 4, 3, same) == 0, "bases: a higher truncation order does not fit");
    check(oti_meta_fits(s, 0, 3, same) == 1, "bases: a lower order with the same labels fits");
    // mixed kinds: a dense value has the labels 1..nbases, and so does a dense meta
    {
        bases_t l123[3] = {1, 2, 3};
        bases_t l12[2] = {1, 2}, l15[2] = {1, 5};
        oti_meta_t* b123 = NULL;
        oti_meta_t* d3 = NULL;
        oti_meta_create(OTI_META_BASES, 3, 3, l123, 3, &b123);
        oti_meta_create(OTI_META_DENSE, 3, 3, NULL, 0, &d3);
        check(oti_meta_fits(b123, 3, 3, NULL) == 1, "bases {1,2,3} fits a dense value with nbases 3");
        check(oti_meta_fits(b123, 3, 4, NULL) == 0,
                "bases {1,2,3} does not fit a dense value with nbases 4");
        check(oti_meta_fits(s, 3, 1, NULL) == 0,
                "bases {2,5,9} does not fit a dense value with nbases 1");
        check(oti_meta_fits(d3, 3, 2, l12) == 1, "dense nbases 3 fits the labels {1, 2}");
        check(oti_meta_fits(d3, 3, 2, l15) == 0, "dense nbases 3 does not fit the labels {1, 5}");
        check(oti_meta_fits(d3, -1, 2, NULL) == 0 && oti_meta_fits(d3, 2, -1, NULL) == 0,
              "negative trc or nbases never fit");
        oti_meta_release(&b123);
        oti_meta_release(&d3);
    }
    oti_meta_release(&s);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    test_create_fields();
    test_create_errors();
    test_refcount();
    test_layout_begin_busy();
    test_transaction_with_growth();
    test_relayout();
    test_act();
    test_fits();

    if (n_failed > 0){
        fprintf(stderr, "\n%d check(s) FAILED\n", n_failed);
        return 1;
    }
    printf("\nAll checks passed.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
