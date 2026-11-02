/* Tests of the dense AoS array (arro_t, include/oti/dense/aos/aos.h, src/c/dense/aos/aos.c).
 * Oracles: arrso_t (sparse AoS, row-major like arro_t) and arrss_t (semi-sparse AoS). Random arrso_t
 * inputs whose elements have different active sets (k <= 4 bases from labels 1..6, so a dense element
 * has nact up to 6), different truncation orders (1..5) and some purely real elements are converted
 * to arro_t (dense) and arrss_t, run through each operation, and compared exhaustively (every
 * direction over the 6-label universe, every order 0..4) against the sparse result (1e-13) and the
 * semi-sparse result (1e-14).
 *
 * Also covered: memory and item functions with their statuses, conversions to and from arrso_t and the
 * SoA layout (elements with different nact and trc), the order and act_order rules, aliasing, shape
 * errors (DN_ERR_SIZE), linear algebra through SoA (mixed nact, singular real part), the rank-fallback
 * case (nact 11 at order 5, above Nbasis(5) = 10), and 1 vs N OpenMP threads. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <oti/oti.h>
#include <oti/semisparse.h>

#ifdef _OPENMP
#include <omp.h>
#endif

#define UNIV_N 6
#define MAXORD 5

#define TOL_SPARSE 1e-13
#define TOL_SEMI   1e-14

static const bases_t g_univ[UNIV_N] = {1, 2, 3, 4, 5, 6};

static int n_failed = 0;
static uint64_t n_checks = 0;


// *******************************************************************************************************
/* Structural / boolean check: prints on both outcomes, like the project's other C tests. */
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
/* Numeric check: silent on success (exhaustive granularity would flood the log), reported and
 * counted either way. Relative to max(1, |expected|); NaN must match NaN. */
static void check_close(const char* label, double got, double expected, double tol){

    n_checks++;

    if (isnan(expected) && isnan(got)){
        return;
    }

    if (!(fabs(got - expected) <= tol * fmax(1.0, fabs(expected)))){
        fprintf(stderr, "FAILED %s: got %.17g, expected %.17g\n", label, got, expected);
        n_failed++;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double frand(double lo, double hi){

    return lo + (hi - lo) * ((double)rand() / ((double)RAND_MAX + 1.0));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double rand_coef(void){

    double v;

    do {
        v = frand(-3.0, 3.0);
    } while (fabs(v) < 0.05);

    return v;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double rand_re_general(void){ return rand_coef(); }
static double rand_re_positive(void){ return frand(0.4, 3.0); }
static double rand_re_ge1(void){ return frand(1.2, 3.0); }
static double rand_re_bounded(void){ return frand(-0.8, 0.8); }
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     BUILDING OPERANDS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Fills an already-created element (trc_order = trc) with a random real part and, unless force_real is
 * set, a random set of k <= 4 bases (from the 6-label universe) and a couple of random directions per
 * order (up to the element's truncation order) over those bases. */
static void build_random_element(sotinum_t* elem, ord_t trc, dhelpl_t dhl, double (*re_gen)(void),
                                 int force_real){

    bases_t labels[UNIV_N], chosen[4], tuple[MAXORD];
    int k, i, j, n_dirs, d;
    ord_t p;
    imdir_t idx;

    elem->re = re_gen();

    if (force_real){
        return;
    }

    memcpy(labels, g_univ, sizeof(labels));

    for (i = UNIV_N - 1; i > 0; i--){

        j = rand() % (i + 1);

        if (i != j){

            bases_t tmp = labels[i];
            labels[i] = labels[j];
            labels[j] = tmp;

        }

    } // end for

    k = rand() % 5;

    if (k == 0){
        return;
    }

    for (i = 0; i < k; i++){
        chosen[i] = labels[i];
    }

    for (i = 1; i < k; i++){

        bases_t key = chosen[i];

        j = i - 1;

        while (j >= 0 && chosen[j] > key){
            chosen[j + 1] = chosen[j];
            j--;
        }

        chosen[j + 1] = key;

    } // end for

    for (p = 1; p <= trc; p++){

        n_dirs = rand() % 3;

        for (d = 0; d < n_dirs; d++){

            for (i = 0; i < p; i++){
                tuple[i] = chosen[rand() % k];
            }

            for (i = 1; i < p; i++){

                bases_t key = tuple[i];

                j = i - 1;

                while (j >= 0 && tuple[j] > key){
                    tuple[j + 1] = tuple[j];
                    j--;
                }

                tuple[j + 1] = key;

            } // end for

            idx = (imdir_t)sshelp_global_rank(tuple, p);
            soti_set_item(rand_coef(), idx, p, elem, dhl);

        } // end for

    } // end for

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* real_pct: chance (0..100) that a given element is forced real-only (k = 0). mixed_trc: element
 * truncation orders are drawn from 1..MAXORD (else all MAXORD). */
static arrso_t build_random_arrso(uint64_t nrows, uint64_t ncols, dhelpl_t dhl,
                                  double (*re_gen)(void), int real_pct, int mixed_trc){

    arrso_t arr = arrso_zeros_bases(nrows, ncols, 0, MAXORD, dhl);
    uint64_t e;

    for (e = 0; e < arr.size; e++){

        int force_real = (int)((rand() % 100) < real_pct);
        ord_t trc = mixed_trc ? (ord_t)(1 + rand() % MAXORD) : MAXORD;
        sotinum_t tmp = soti_createEmpty(trc, dhl);

        build_random_element(&tmp, trc, dhl, re_gen, force_real);

        // Move the element in: a copy into the array's own element would keep its trc (MAXORD).
        soti_free(&arr.p_data[e]);
        arr.p_data[e] = tmp;

    }

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     COMPARISON HARNESS     --------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Coefficient of the global direction (idx, p) of a dense number; zero when structurally absent. */
static coeff_t num_coef(const otinum_t* t, imdir_t idx, ord_t p){

    if (p == 0){
        return t->re;
    }

    if (p > t->trc_order || idx >= sshelp_ndir_order(t->nact, p)){
        return 0.0;
    }

    return t->p_im[sshelp_order_offset(t->nact, p) + idx];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Every direction over the 6-label universe, order 0..MAXORD: N_p(6) directions per order, global
 * indices 0 .. N_p(6) - 1 (colex prefix property). Dense against sparse. */
static void compare_num_vs_soti(const char* tag, const otinum_t* a, sotinum_t* b, double tol,
                                dhelpl_t dhl){

    ord_t p;
    ndir_t n, i;
    char label[224];

    snprintf(label, sizeof(label), "%s re", tag);
    check_close(label, a->re, b->re, tol);

    for (p = 1; p <= MAXORD; p++){

        n = sshelp_ndir_order(UNIV_N, p);

        for (i = 0; i < n; i++){

            snprintf(label, sizeof(label), "%s ord=%u idx=" _PNDIRT, tag, (unsigned)p, i);
            check_close(label, num_coef(a, (imdir_t)i, p), soti_get_item((imdir_t)i, p, b, dhl), tol);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense against semi-sparse, same universe. */
static void compare_num_vs_ssoti(const char* tag, const otinum_t* a, const ssotinum_t* b, double tol){

    ord_t p;
    ndir_t n, i;
    char label[224];

    snprintf(label, sizeof(label), "%s re (semi-sparse)", tag);
    check_close(label, a->re, b->re, tol);

    for (p = 1; p <= MAXORD; p++){

        n = sshelp_ndir_order(UNIV_N, p);

        for (i = 0; i < n; i++){

            snprintf(label, sizeof(label), "%s ord=%u idx=" _PNDIRT " (semi-sparse)", tag, (unsigned)p,
                     i);
            check_close(label, num_coef(a, (imdir_t)i, p), ssoti_get_item((imdir_t)i, p, b), tol);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense array against a sparse array (and optionally a semi-sparse one), every element. */
static void compare_arro(const char* tag, const arro_t* a, arrso_t* o, const arrss_t* s,
                         dhelpl_t dhl){

    uint64_t e;
    char label[256];
    int before = n_failed;

    if (a->nrows != o->nrows || a->ncols != o->ncols){

        fprintf(stderr, "FAILED %s: shape mismatch (%llux%llu vs %llux%llu)\n", tag,
                (unsigned long long)a->nrows, (unsigned long long)a->ncols,
                (unsigned long long)o->nrows, (unsigned long long)o->ncols);
        n_failed++;
        return;

    }

    for (e = 0; e < a->size; e++){

        snprintf(label, sizeof(label), "%s elem %llu", tag, (unsigned long long)e);
        compare_num_vs_soti(label, &a->p_data[e], &o->p_data[e], TOL_SPARSE, dhl);

        if (s != NULL){
            compare_num_vs_ssoti(label, &a->p_data[e], &s->p_data[e], TOL_SEMI);
        }

    }

    if (n_failed == before){
        printf("passed: %s (%llu elements, exhaustive over %d-label universe up to order %d)\n", tag,
               (unsigned long long)a->size, UNIV_N, MAXORD);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense array against a dense array (same shape): values within tol, nact and trc per element. */
static void compare_arro_dense(const char* tag, const arro_t* a, const arro_t* b, double tol,
                               int same_layout){

    uint64_t e;
    ord_t p;
    ndir_t n, i;
    char label[256];
    int before = n_failed;

    if (a->nrows != b->nrows || a->ncols != b->ncols){

        fprintf(stderr, "FAILED %s: shape mismatch\n", tag);
        n_failed++;
        return;

    }

    for (e = 0; e < a->size; e++){

        const otinum_t *x = &a->p_data[e], *y = &b->p_data[e];
        bases_t kmax = (x->nact > y->nact) ? x->nact : y->nact;
        ord_t trc = (x->trc_order > y->trc_order) ? x->trc_order : y->trc_order;

        if (same_layout && (x->nact != y->nact || x->trc_order != y->trc_order)){

            fprintf(stderr, "FAILED %s elem %llu: layout (%u, %u) vs (%u, %u)\n", tag,
                    (unsigned long long)e, (unsigned)x->nact, (unsigned)x->trc_order,
                    (unsigned)y->nact, (unsigned)y->trc_order);
            n_failed++;
            continue;

        }

        snprintf(label, sizeof(label), "%s elem %llu re", tag, (unsigned long long)e);
        check_close(label, x->re, y->re, tol);

        for (p = 1; p <= trc; p++){

            n = sshelp_ndir_order(kmax, p);

            for (i = 0; i < n; i++){

                snprintf(label, sizeof(label), "%s elem %llu ord=%u idx=" _PNDIRT, tag,
                         (unsigned long long)e, (unsigned)p, i);
                check_close(label, num_coef(x, (imdir_t)i, p), num_coef(y, (imdir_t)i, p), tol);

            }

        }

    }

    if (n_failed == before){
        printf("passed: %s (%llu elements)\n", tag, (unsigned long long)a->size);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Dense array against the sparse array it was converted from (every element, exhaustively). */
typedef struct {
    arrso_t so;      ///< Sparse oracle.
    arrss_t ss;      ///< Semi-sparse copy.
    arro_t  dn;      ///< Dense copy.
} operand_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static operand_t make_operand(uint64_t nrows, uint64_t ncols, dhelpl_t dhl, double (*re_gen)(void),
                              int real_pct, int mixed_trc){

    operand_t op;

    op.so = build_random_arrso(nrows, ncols, dhl, re_gen, real_pct, mixed_trc);
    op.ss = arrss_from_arrso(&op.so, dhl);
    op.dn = arro_init();

    check(arro_from_arrso_to(&op.so, &op.dn, dhl) == DN_OK, "arro_from_arrso_to status");

    return op;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void free_operand(operand_t* op){

    arrso_free(&op->so);
    arrss_free(&op->ss);
    arro_free(&op->dn);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Highest order with a nonzero coefficient in a dense number (0 for a real one). */
static ord_t highest_nonzero_order(const otinum_t* t){

    ord_t p, top = 0;
    ndir_t i, n;

    for (p = 1; p <= t->trc_order; p++){

        n = sshelp_ndir_order(t->nact, p);

        for (i = 0; i < n; i++){

            if (t->p_im[sshelp_order_offset(t->nact, p) + i] != 0.0){
                top = p;
            }

        }

    }

    return top;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Order rules of an elementwise operation on two arrays: every result element has nact and trc equal to
 * the maxima over the operands, and an act_order that covers its nonzero coefficients and does not
 * exceed trc. kind: 's' sum / sub (act = max of the operands'), 'm' product (min(act_a + act_b, trc)),
 * anything else only the coverage bound. */
static void check_order_rules(const char* tag, char kind, const arro_t* a, const arro_t* b,
                              const arro_t* res){

    uint64_t e;
    int bad = 0;

    for (e = 0; e < res->size; e++){

        const otinum_t *x = &a->p_data[e], *y = &b->p_data[e], *r = &res->p_data[e];
        ord_t trc = (x->trc_order > y->trc_order) ? x->trc_order : y->trc_order;
        bases_t k = (x->nact > y->nact) ? x->nact : y->nact;

        bad += (r->trc_order != trc || r->nact != k);
        bad += (r->act_order > r->trc_order || r->act_order < highest_nonzero_order(r));

        if (kind == 's'){
            bad += (r->act_order != ((x->act_order > y->act_order) ? x->act_order : y->act_order));
        } else if (kind == 'm'){
            bad += (r->act_order != (((unsigned)x->act_order + y->act_order < trc)
                                     ? (ord_t)(x->act_order + y->act_order) : trc));
        }

    }

    {
        char name[160];

        snprintf(name, sizeof(name), "%s: nact / trc / act_order rules", tag);
        check(bad == 0, name);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     MEMORY AND ITEMS     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_memory(dhelpl_t dhl){

    arro_t z = arro_init(), c = arro_init();
    otinum_t num = oti_create_empty(3, 4);
    uint64_t e;
    int status, ok;

    (void)dhl;

    check(z.p_data == NULL && z.nrows == 0 && z.ncols == 0 && z.size == 0, "arro_init is empty");
    arro_free(&z);
    check(z.p_data == NULL, "arro_free of an empty array is a no-op");

    status = arro_zeros_to(2, 3, 3, &z);
    ok = (status == DN_OK && z.nrows == 2 && z.ncols == 3 && z.size == 6);

    for (e = 0; e < z.size; e++){
        ok = ok && z.p_data[e].re == 0.0 && z.p_data[e].nact == 0 && z.p_data[e].trc_order == 3;
    }

    check(ok, "arro_zeros_to: real zeros with the requested trc");

    // Items.
    oti_set_item(2.5, 4, 2, &num);
    num.re = 1.5;
    check(arro_set_item(&num, 1, 2, &z) == DN_OK, "arro_set_item status");
    num.re = -9.0;
    check(z.p_data[2 + 1 * 3].re == 1.5 && z.p_data[2 + 1 * 3].nact == num.nact &&
          z.p_data[2 + 1 * 3].p_im != num.p_im, "arro_set_item stores an independent copy");
    check(arro_set_item(&num, 2, 0, &z) == DN_ERR_INDEX && arro_set_item(&num, 0, 3, &z) == DN_ERR_INDEX,
          "arro_set_item out of range: DN_ERR_INDEX");
    check(arro_set_item_r(7.0, 1, 2, &z) == DN_OK && z.p_data[5].re == 7.0 && z.p_data[5].nact == 0 &&
          z.p_data[5].trc_order == 4, "arro_set_item_r: real value, element's trc kept as it was");
    check(arro_set_item_r(1.0, 2, 0, &z) == DN_ERR_INDEX, "arro_set_item_r out of range: DN_ERR_INDEX");
    check(arro_get_item_ptr(1, 2, &z) == &z.p_data[5] && arro_get_item_ptr(2, 0, &z) == NULL &&
          arro_get_item_ptr(0, 3, &z) == NULL, "arro_get_item_ptr: pointer or NULL out of range");

    // Zeros into an array that has content: every element reset.
    check(arro_zeros_to(3, 3, 2, &z) == DN_OK, "arro_zeros_to over an existing array");
    ok = (z.size == 9);

    for (e = 0; e < z.size; e++){
        ok = ok && z.p_data[e].re == 0.0 && z.p_data[e].nact == 0 && z.p_data[e].trc_order == 2;
    }

    check(ok, "arro_zeros_to resets every element");

    // Resize keeps the first elements, new ones are real zeros with the given trc.
    for (e = 0; e < z.size; e++){
        z.p_data[e].re = (double)(e + 1);
    }

    check(arro_resize(3, 4, 4, &z) == DN_OK && z.size == 12, "arro_resize grows");
    ok = 1;

    for (e = 0; e < 9; e++){
        ok = ok && z.p_data[e].re == (double)(e + 1);
    }

    for (e = 9; e < 12; e++){
        ok = ok && z.p_data[e].re == 0.0 && z.p_data[e].trc_order == 4 && z.p_data[e].nact == 0;
    }

    check(ok, "arro_resize keeps the old elements and adds real zeros");
    check(arro_resize(1, 2, 0, &z) == DN_OK && z.size == 2 && z.p_data[0].re == 1.0 &&
          z.p_data[1].re == 2.0 && z.nrows == 1 && z.ncols == 2, "arro_resize shrinks");

    // Copy.
    check(arro_copy_to(&z, &z) == DN_OK, "arro_copy_to onto itself is a no-op");
    z.p_data[1] = oti_copy(&num);
    check(arro_copy_to(&z, &c) == DN_OK, "arro_copy_to status");
    compare_arro_dense("arro_copy_to", &z, &c, 0.0, 1);
    check(c.p_data[1].p_im != z.p_data[1].p_im, "arro_copy_to is deep");

    // Failures leave a valid array.
    check(arro_resize(1ULL << 40, 1ULL << 40, 0, &z) == DN_ERR_MEMORY && z.size == 2,
          "arro_resize: shape overflow gives DN_ERR_MEMORY, array unchanged");
    check(arro_resize(1ULL << 60, 4, 0, &z) == DN_ERR_MEMORY && z.size == 2,
          "arro_resize: byte-count overflow gives DN_ERR_MEMORY, array unchanged");
    check(arro_resize(3, 3, 151, &z) == DN_ERR_INDEX && z.size == 2,
          "arro_resize: new elements above the maximum order give DN_ERR_INDEX");
    check(arro_zeros_to(2, 2, 151, &c) == DN_ERR_INDEX, "arro_zeros_to: trc 151 gives DN_ERR_INDEX");
    check(arro_zeros_to(2, 2, 150, &c) == DN_OK && c.p_data[0].trc_order == 150,
          "arro_zeros_to: trc 150 works");

    arro_free(&z);
    arro_free(&c);
    oti_free(&num);
    arro_free(&c);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     CONVERSIONS     ---------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
/* Sparse array against sparse array (every direction of the universe, to 1e-15). */
static void compare_arrso_arrso(const char* tag, arrso_t* a, arrso_t* b, dhelpl_t dhl){

    uint64_t e;
    ord_t p;
    ndir_t i, n;
    int before = n_failed;
    char label[224];

    for (e = 0; e < a->size; e++){

        snprintf(label, sizeof(label), "%s elem %llu re", tag, (unsigned long long)e);
        check_close(label, a->p_data[e].re, b->p_data[e].re, 1e-15);

        for (p = 1; p <= MAXORD; p++){

            n = sshelp_ndir_order(UNIV_N, p);

            for (i = 0; i < n; i++){

                snprintf(label, sizeof(label), "%s elem %llu ord=%u idx=" _PNDIRT, tag,
                         (unsigned long long)e, (unsigned)p, i);
                check_close(label, soti_get_item((imdir_t)i, p, &a->p_data[e], dhl),
                            soti_get_item((imdir_t)i, p, &b->p_data[e], dhl), 1e-15);

            }

        }

    }

    if (n_failed == before){
        printf("passed: %s\n", tag);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Coefficient (idx, p) of element (i, j) of a dense SoA array, zero when structurally absent. */
static coeff_t oarr_coef(const oarr_t* A, uint64_t i, uint64_t j, imdir_t idx, ord_t p){

    if (p == 0){
        return A->p_data[i + j * A->nrows];
    }

    if (p > A->trc_order || idx >= sshelp_ndir_order(A->nact, p)){
        return 0.0;
    }

    return A->p_data[(1 + sshelp_order_offset(A->nact, p) + idx) * A->size + i + j * A->nrows];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Coefficient (idx, p) of element (i, j) of a semi-sparse SoA array (global direction). */
static coeff_t oarrss_coef(const oarrss_t* S, uint64_t i, uint64_t j, imdir_t idx, ord_t p){

    ndir_t l;

    if (p == 0){
        return S->p_data[i + j * S->nrows];
    }

    if (p > S->trc_order || sshelp_global_to_local(idx, p, S->p_bases, S->nbases, &l) != 1){
        return 0.0;
    }

    return S->p_data[(1 + sshelp_order_offset(S->nbases, p) + l) * S->size + i + j * S->nrows];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* AoS <-> sparse and AoS <-> SoA conversions, on arrays whose elements have different nact and trc. */
static void test_conversions(dhelpl_t dhl){

    static const uint64_t shapes[4][2] = {{1, 1}, {3, 3}, {2, 4}, {4, 3}};
    size_t s;

    for (s = 0; s < 4; s++){

        operand_t op = make_operand(shapes[s][0], shapes[s][1], dhl, rand_re_general, 20, 1);
        arrso_t back = arro_to_arrso(&op.dn, dhl);
        oarr_t S = oarr_init();
        oarrss_t Sss = oarrss_init();
        arro_t from = arro_init();
        uint64_t e, i, j;
        bases_t kmax = 0;
        ord_t trc = 0, p;
        ndir_t idx, n;
        int ok = 1, bad_nact = 0;
        char tag[96];

        snprintf(tag, sizeof(tag), "arrso -> arro -> arrso round trip %llux%llu",
                 (unsigned long long)shapes[s][0], (unsigned long long)shapes[s][1]);
        compare_arro(tag, &op.dn, &op.so, &op.ss, dhl);
        compare_arrso_arrso(tag, &op.so, &back, dhl);
        check(back.nrows == op.so.nrows && back.ncols == op.so.ncols, "arro_to_arrso keeps the shape");

        // Every element has its own nact (the largest base it uses) and its own trc.
        for (e = 0; e < op.dn.size; e++){

            const sotinum_t* x = &op.so.p_data[e];
            bases_t k = 0;

            for (p = 1; p <= x->act_order; p++){

                for (idx = 0; idx < sshelp_ndir_order(UNIV_N, p); idx++){

                    if (soti_get_item((imdir_t)idx, p, (sotinum_t*)x, dhl) != 0.0){

                        bases_t g[8];

                        sshelp_global_unrank((imdir_t)idx, p, g);
                        k = (g[p - 1] > k) ? g[p - 1] : k;

                    }

                }

            }

            bad_nact += (op.dn.p_data[e].nact != k || op.dn.p_data[e].trc_order != x->trc_order);
            kmax = (op.dn.p_data[e].nact > kmax) ? op.dn.p_data[e].nact : kmax;
            trc  = (op.dn.p_data[e].trc_order > trc) ? op.dn.p_data[e].trc_order : trc;

        }

        check(bad_nact == 0, "arro_from_arrso_to: element nact = its largest base, its own trc");

        // AoS -> SoA: nact and trc are the maxima; every element zero-extended.
        check(arro_to_oarr(&op.dn, &S) == DN_OK, "arro_to_oarr status");
        check(S.nact == kmax && S.trc_order == trc && S.nrows == shapes[s][0] &&
              S.ncols == shapes[s][1], "arro_to_oarr: nact and trc are the element maxima");

        for (i = 0; i < S.nrows; i++){

            for (j = 0; j < S.ncols; j++){

                const otinum_t* x = &op.dn.p_data[j + i * S.ncols];

                ok = ok && S.p_data[i + j * S.nrows] == x->re;

                for (p = 1; p <= trc; p++){

                    n = sshelp_ndir_order(UNIV_N, p);

                    for (idx = 0; idx < n; idx++){
                        ok = ok && oarr_coef(&S, i, j, (imdir_t)idx, p) == num_coef(x, (imdir_t)idx, p);
                    }

                }

            }

        }

        check(ok, "arro_to_oarr: every coefficient of every element");

        // Against the semi-sparse conversion (its sets are unions of the element sets).
        arrss_to_oarrss(&op.ss, &Sss);
        ok = 1;

        for (i = 0; i < S.nrows; i++){

            for (j = 0; j < S.ncols; j++){

                for (p = 1; p <= trc; p++){

                    n = sshelp_ndir_order(UNIV_N, p);

                    for (idx = 0; idx < n; idx++){
                        ok = ok && oarr_coef(&S, i, j, (imdir_t)idx, p) ==
                                   oarrss_coef(&Sss, i, j, (imdir_t)idx, p);
                    }

                }

            }

        }

        check(ok, "arro_to_oarr agrees with arrss_to_oarrss");

        // SoA -> AoS: every element gets the SoA nact and orders.
        check(arro_from_oarr(&S, &from) == DN_OK, "arro_from_oarr status");
        ok = (from.nrows == S.nrows && from.ncols == S.ncols);

        for (e = 0; e < from.size; e++){

            ok = ok && from.p_data[e].nact == S.nact && from.p_data[e].trc_order == S.trc_order &&
                 from.p_data[e].act_order == S.act_order;

        }

        check(ok, "arro_from_oarr: every element has the SoA nact, trc and act_order");
        compare_arro_dense("arro -> oarr -> arro round trip", &op.dn, &from, 0.0, 0);

        arrso_free(&back);
        oarr_free(&S);
        oarrss_free(&Sss);
        arro_free(&from);
        free_operand(&op);

    } // end for

    // Empty and all-real arrays.
    {
        arro_t e0 = arro_init(), r = arro_init(), back = arro_init();
        oarr_t S = oarr_init();

        check(arro_to_oarr(&e0, &S) == DN_OK && S.size == 0 && S.nact == 0,
              "arro_to_oarr of an empty array");
        check(arro_from_oarr(&S, &back) == DN_OK && back.size == 0, "arro_from_oarr of an empty array");

        arro_zeros_to(2, 2, 3, &r);
        r.p_data[1].re = 4.0;
        check(arro_to_oarr(&r, &S) == DN_OK && S.nact == 0 && S.trc_order == 3 && S.act_order == 0 &&
              S.p_data[2] == 4.0, "arro_to_oarr of real elements: nact 0, act_order 0");
        check(arro_from_oarr(&S, &back) == DN_OK && back.p_data[1].re == 4.0 && back.p_data[0].nact == 0,
              "arro_from_oarr of a real array");

        arro_free(&r);
        arro_free(&back);
        oarr_free(&S);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     ELEMENTWISE     ---------------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef void (*arrso_oo_fn)(arrso_t*, arrso_t*, arrso_t*, dhelpl_t);
typedef void (*arrss_oo_fn)(const arrss_t*, const arrss_t*, arrss_t*, dhelpl_t);
typedef int (*arro_oo_fn)(const arro_t*, const arro_t*, arro_t*, dhelpl_t);
typedef void (*arrso_oscalar_fn)(sotinum_t*, arrso_t*, arrso_t*, dhelpl_t);
typedef void (*arrss_oscalar_fn)(const ssotinum_t*, const arrss_t*, arrss_t*, dhelpl_t);
typedef int (*arro_oscalar_fn)(const otinum_t*, const arro_t*, arro_t*, dhelpl_t);
typedef void (*arrso_rO_fn)(coeff_t, arrso_t*, arrso_t*, dhelpl_t);
typedef void (*arrss_rO_fn)(coeff_t, const arrss_t*, arrss_t*, dhelpl_t);
typedef int (*arro_rO_fn)(coeff_t, const arro_t*, arro_t*, dhelpl_t);
typedef void (*arrso_Oscalar_fn)(arrso_t*, sotinum_t*, arrso_t*, dhelpl_t);
typedef void (*arrss_Oscalar_fn)(const arrss_t*, const ssotinum_t*, arrss_t*, dhelpl_t);
typedef int (*arro_Oscalar_fn)(const arro_t*, const otinum_t*, arro_t*, dhelpl_t);
typedef void (*arrso_Or_fn)(arrso_t*, coeff_t, arrso_t*, dhelpl_t);
typedef void (*arrss_Or_fn)(const arrss_t*, coeff_t, arrss_t*, dhelpl_t);
typedef int (*arro_Or_fn)(const arro_t*, coeff_t, arro_t*, dhelpl_t);
typedef void (*arrso_unary_fn)(arrso_t*, arrso_t*, dhelpl_t);
typedef void (*arrss_unary_fn)(const arrss_t*, arrss_t*, dhelpl_t);
typedef int (*arro_unary_fn)(const arro_t*, arro_t*, dhelpl_t);


// *******************************************************************************************************
/* OO, oO, rO, Oo, Or elementwise ops (+ - x /) and negation, for one shape. The operands have different
 * active sets and truncation orders per element and some purely real elements; num / val are the
 * scalar / real operands. Each result is compared with the sparse and the semi-sparse result. */
static void test_elementwise_shape(uint64_t nrows, uint64_t ncols, dhelpl_t dhl){

    static const struct { const char* name; char kind; arrso_oo_fn f_so; arrss_oo_fn f_ss;
        arro_oo_fn f_dn; } oo_ops[] = {
        {"sum_OO", 's', arrso_sum_OO_to, arrss_sum_OO_to, arro_sum_OO_to},
        {"sub_OO", 's', arrso_sub_OO_to, arrss_sub_OO_to, arro_sub_OO_to},
        {"mul_OO", 'm', arrso_mul_OO_to, arrss_mul_OO_to, arro_mul_OO_to},
        {"div_OO", 'd', arrso_div_OO_to, arrss_div_OO_to, arro_div_OO_to},
    };
    static const struct { const char* name; arrso_oscalar_fn f_so; arrss_oscalar_fn f_ss;
        arro_oscalar_fn f_dn; } oscalar_ops[] = {
        {"sum_oO", arrso_sum_oO_to, arrss_sum_oO_to, arro_sum_oO_to},
        {"sub_oO", arrso_sub_oO_to, arrss_sub_oO_to, arro_sub_oO_to},
        {"mul_oO", arrso_mul_oO_to, arrss_mul_oO_to, arro_mul_oO_to},
        {"div_oO", arrso_div_oO_to, arrss_div_oO_to, arro_div_oO_to},
    };
    static const struct { const char* name; arrso_rO_fn f_so; arrss_rO_fn f_ss; arro_rO_fn f_dn; }
        rO_ops[] = {
        {"sum_rO", arrso_sum_rO_to, arrss_sum_rO_to, arro_sum_rO_to},
        {"sub_rO", arrso_sub_rO_to, arrss_sub_rO_to, arro_sub_rO_to},
        {"mul_rO", arrso_mul_rO_to, arrss_mul_rO_to, arro_mul_rO_to},
        {"div_rO", arrso_div_rO_to, arrss_div_rO_to, arro_div_rO_to},
    };
    static const struct { const char* name; arrso_Oscalar_fn f_so; arrss_Oscalar_fn f_ss;
        arro_Oscalar_fn f_dn; } Oscalar_ops[] = {
        {"sub_Oo", arrso_sub_Oo_to, arrss_sub_Oo_to, arro_sub_Oo_to},
        {"div_Oo", arrso_div_Oo_to, arrss_div_Oo_to, arro_div_Oo_to},
    };
    static const struct { const char* name; arrso_Or_fn f_so; arrss_Or_fn f_ss; arro_Or_fn f_dn; }
        Or_ops[] = {
        {"sub_Or", arrso_sub_Or_to, arrss_sub_Or_to, arro_sub_Or_to},
        {"div_Or", arrso_div_Or_to, arrss_div_Or_to, arro_div_Or_to},
    };

    operand_t a1 = make_operand(nrows, ncols, dhl, rand_re_general, 20, 1);
    operand_t a2 = make_operand(nrows, ncols, dhl, rand_re_general, 20, 1);
    sotinum_t num = soti_createEmpty(MAXORD, dhl);
    ssotinum_t snum;
    otinum_t dnum = oti_init();
    coeff_t val = rand_coef();
    size_t i;
    char tag[96];

    build_random_element(&num, MAXORD, dhl, rand_re_general, 0);
    snum = ssoti_from_soti(&num, dhl);
    check(oti_from_soti_to(&num, &dnum, dhl) == DN_OK, "oti_from_soti_to status");

    for (i = 0; i < sizeof(oo_ops) / sizeof(oo_ops[0]); i++){

        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init();

        oo_ops[i].f_so(&a1.so, &a2.so, &exp, dhl);
        oo_ops[i].f_ss(&a1.ss, &a2.ss, &got_ss, dhl);
        check(oo_ops[i].f_dn(&a1.dn, &a2.dn, &got, dhl) == DN_OK, "elementwise OO status");

        snprintf(tag, sizeof(tag), "%s %llux%llu", oo_ops[i].name, (unsigned long long)nrows,
                 (unsigned long long)ncols);
        compare_arro(tag, &got, &exp, &got_ss, dhl);
        check_order_rules(tag, oo_ops[i].kind, &a1.dn, &a2.dn, &got);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);

    }

    for (i = 0; i < sizeof(oscalar_ops) / sizeof(oscalar_ops[0]); i++){

        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init();

        oscalar_ops[i].f_so(&num, &a1.so, &exp, dhl);
        oscalar_ops[i].f_ss(&snum, &a1.ss, &got_ss, dhl);
        check(oscalar_ops[i].f_dn(&dnum, &a1.dn, &got, dhl) == DN_OK, "elementwise oO status");

        snprintf(tag, sizeof(tag), "%s %llux%llu", oscalar_ops[i].name, (unsigned long long)nrows,
                 (unsigned long long)ncols);
        compare_arro(tag, &got, &exp, &got_ss, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);

    }

    for (i = 0; i < sizeof(rO_ops) / sizeof(rO_ops[0]); i++){

        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init();

        rO_ops[i].f_so(val, &a1.so, &exp, dhl);
        rO_ops[i].f_ss(val, &a1.ss, &got_ss, dhl);
        check(rO_ops[i].f_dn(val, &a1.dn, &got, dhl) == DN_OK, "elementwise rO status");

        snprintf(tag, sizeof(tag), "%s %llux%llu", rO_ops[i].name, (unsigned long long)nrows,
                 (unsigned long long)ncols);
        compare_arro(tag, &got, &exp, &got_ss, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);

    }

    for (i = 0; i < sizeof(Oscalar_ops) / sizeof(Oscalar_ops[0]); i++){

        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init();

        Oscalar_ops[i].f_so(&a1.so, &num, &exp, dhl);
        Oscalar_ops[i].f_ss(&a1.ss, &snum, &got_ss, dhl);
        check(Oscalar_ops[i].f_dn(&a1.dn, &dnum, &got, dhl) == DN_OK, "elementwise Oo status");

        snprintf(tag, sizeof(tag), "%s %llux%llu", Oscalar_ops[i].name, (unsigned long long)nrows,
                 (unsigned long long)ncols);
        compare_arro(tag, &got, &exp, &got_ss, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);

    }

    for (i = 0; i < sizeof(Or_ops) / sizeof(Or_ops[0]); i++){

        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init();

        Or_ops[i].f_so(&a1.so, val, &exp, dhl);
        Or_ops[i].f_ss(&a1.ss, val, &got_ss, dhl);
        check(Or_ops[i].f_dn(&a1.dn, val, &got, dhl) == DN_OK, "elementwise Or status");

        snprintf(tag, sizeof(tag), "%s %llux%llu", Or_ops[i].name, (unsigned long long)nrows,
                 (unsigned long long)ncols);
        compare_arro(tag, &got, &exp, &got_ss, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);

    }

    {
        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init();

        arrso_neg_to(&a1.so, &exp, dhl);
        arrss_neg_to(&a1.ss, &got_ss, dhl);
        check(arro_neg_to(&a1.dn, &got, dhl) == DN_OK, "neg status");

        snprintf(tag, sizeof(tag), "neg %llux%llu", (unsigned long long)nrows,
                 (unsigned long long)ncols);
        compare_arro(tag, &got, &exp, &got_ss, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);

    }

    free_operand(&a1);
    free_operand(&a2);
    soti_free(&num);
    ssoti_free(&snum);
    oti_free(&dnum);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_elementwise(dhelpl_t dhl){

    test_elementwise_shape(1, 1, dhl);
    test_elementwise_shape(3, 3, dhl);
    test_elementwise_shape(2, 4, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_functions(dhelpl_t dhl){

    static const struct { const char* name; double (*re_gen)(void); arrso_unary_fn f_so;
        arrss_unary_fn f_ss; arro_unary_fn f_dn; } ops[] = {
        {"exp",   rand_re_general,  arrso_exp_to,   arrss_exp_to,   arro_exp_to},
        {"log",   rand_re_positive, arrso_log_to,   arrss_log_to,   arro_log_to},
        {"log10", rand_re_positive, arrso_log10_to, arrss_log10_to, arro_log10_to},
        {"sqrt",  rand_re_positive, arrso_sqrt_to,  arrss_sqrt_to,  arro_sqrt_to},
        {"cbrt",  rand_re_positive, arrso_cbrt_to,  arrss_cbrt_to,  arro_cbrt_to},
        {"sin",   rand_re_general,  arrso_sin_to,   arrss_sin_to,   arro_sin_to},
        {"cos",   rand_re_general,  arrso_cos_to,   arrss_cos_to,   arro_cos_to},
        {"tan",   rand_re_general,  arrso_tan_to,   arrss_tan_to,   arro_tan_to},
        {"asin",  rand_re_bounded,  arrso_asin_to,  arrss_asin_to,  arro_asin_to},
        {"acos",  rand_re_bounded,  arrso_acos_to,  arrss_acos_to,  arro_acos_to},
        {"atan",  rand_re_general,  arrso_atan_to,  arrss_atan_to,  arro_atan_to},
        {"sinh",  rand_re_general,  arrso_sinh_to,  arrss_sinh_to,  arro_sinh_to},
        {"cosh",  rand_re_general,  arrso_cosh_to,  arrss_cosh_to,  arro_cosh_to},
        {"tanh",  rand_re_general,  arrso_tanh_to,  arrss_tanh_to,  arro_tanh_to},
        {"asinh", rand_re_general,  arrso_asinh_to, arrss_asinh_to, arro_asinh_to},
        {"acosh", rand_re_ge1,      arrso_acosh_to, arrss_acosh_to, arro_acosh_to},
        {"atanh", rand_re_bounded,  arrso_atanh_to, arrss_atanh_to, arro_atanh_to},
        {"erf",   rand_re_general,  arrso_erf_to,   arrss_erf_to,   arro_erf_to},
    };
    size_t i;

    for (i = 0; i < sizeof(ops) / sizeof(ops[0]); i++){

        operand_t a1 = make_operand(3, 3, dhl, ops[i].re_gen, 20, 1);
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init();
        char tag[64];

        ops[i].f_so(&a1.so, &exp, dhl);
        ops[i].f_ss(&a1.ss, &got_ss, dhl);
        check(ops[i].f_dn(&a1.dn, &got, dhl) == DN_OK, "function status");

        snprintf(tag, sizeof(tag), "%s 3x3", ops[i].name);
        compare_arro(tag, &got, &exp, &got_ss, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);
        free_operand(&a1);

    }

    {
        static const double exponents[] = {2.0, 0.5, -1.0, 3.0};
        size_t e;

        for (e = 0; e < sizeof(exponents) / sizeof(exponents[0]); e++){

            operand_t a1 = make_operand(3, 3, dhl, rand_re_positive, 20, 1);
            arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
            arrss_t got_ss = arrss_init();
            arro_t got = arro_init();
            char tag[64];

            arrso_pow_to(&a1.so, exponents[e], &exp, dhl);
            arrss_pow_to(&a1.ss, exponents[e], &got_ss, dhl);
            check(arro_pow_to(&a1.dn, exponents[e], &got, dhl) == DN_OK, "pow status");

            snprintf(tag, sizeof(tag), "pow(^%.1f) 3x3", exponents[e]);
            compare_arro(tag, &got, &exp, &got_ss, dhl);

            arrso_free(&exp);
            arrss_free(&got_ss);
            arro_free(&got);
            free_operand(&a1);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_truncation_compact(dhelpl_t dhl){

    operand_t a1 = make_operand(3, 3, dhl, rand_re_general, 20, 1);
    bases_t g3[1] = {3};
    imdir_t idx_b3 = (imdir_t)sshelp_global_rank(g3, 1);

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init();

        arrso_truncate_im_to(idx_b3, 1, &a1.so, &exp, dhl);
        arrss_truncate_im_to(idx_b3, 1, &a1.ss, &got_ss, dhl);
        check(arro_truncate_im_to(idx_b3, 1, &a1.dn, &got, dhl) == DN_OK, "truncate_im status");

        compare_arro("truncate_im(base3,ord1) 3x3", &got, &exp, &got_ss, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);
    }

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init(), cmp = arro_init();
        uint64_t e, nact_before = 0, nact_after = 0;
        int trc_kept = 1;

        arrso_truncate_order_to(2, &a1.so, &exp, dhl);
        arrss_truncate_order_to(2, &a1.ss, &got_ss, dhl);
        check(arro_truncate_order_to(2, &a1.dn, &got, dhl) == DN_OK, "truncate_order status");

        for (e = 0; e < got.size; e++){

            nact_before += got.p_data[e].nact;
            trc_kept = trc_kept && got.p_data[e].trc_order == a1.dn.p_data[e].trc_order;

        }

        check(trc_kept, "truncate_order keeps every element's trc");
        check(arro_compact_to(&got, &cmp, dhl) == DN_OK, "compact status");

        for (e = 0; e < cmp.size; e++){
            nact_after += cmp.p_data[e].nact;
        }

        compare_arro("truncate_order(2)+compact 3x3", &cmp, &exp, &got_ss, dhl);
        check(nact_after <= nact_before, "compact never grows the total nact");

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);
        arro_free(&cmp);
    }

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init();

        arrso_get_order_im_to(2, &a1.so, &exp, dhl);
        arrss_get_order_im_to(2, &a1.ss, &got_ss, dhl);
        check(arro_get_order_im_to(2, &a1.dn, &got, dhl) == DN_OK, "get_order_im status");

        compare_arro("get_order_im(2) 3x3", &got, &exp, &got_ss, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);
    }

    // compact trims only trailing all-zero bases.
    {
        arro_t z = arro_init(), c = arro_init();
        otinum_t n1 = oti_create_empty(5, 3);

        oti_set_item(2.0, 1, 1, &n1);     // base 2 only, over nact 5.
        arro_zeros_to(1, 2, 3, &z);
        arro_set_item(&n1, 0, 0, &z);
        oti_set_r(1.0, &n1);
        arro_set_item(&n1, 0, 1, &z);
        check(arro_compact_to(&z, &c, dhl) == DN_OK && c.p_data[0].nact == 2 && c.p_data[1].nact == 0,
              "compact trims trailing zero bases only (nact 5 -> 2, real -> 0)");
        check(c.p_data[0].trc_order == 3 && num_coef(&c.p_data[0], 1, 1) == 2.0,
              "compact keeps trc and values");

        arro_free(&z);
        arro_free(&c);
        oti_free(&n1);
    }

    free_operand(&a1);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// -------------------------------------     MATRIX OPERATIONS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
static void test_matmul(dhelpl_t dhl){

    operand_t a1 = make_operand(2, 4, dhl, rand_re_general, 20, 1);
    operand_t a2 = make_operand(4, 3, dhl, rand_re_general, 20, 1);
    arrso_t exp = arrso_zeros_bases(2, 3, 0, 0, dhl);
    arrss_t got_ss = arrss_init();
    arro_t got = arro_init();

    arrso_matmul_OO_to(&a1.so, &a2.so, &exp, dhl);
    arrss_matmul_OO_to(&a1.ss, &a2.ss, &got_ss, dhl);
    check(arro_matmul_OO_to(&a1.dn, &a2.dn, &got, dhl) == DN_OK, "matmul status");

    compare_arro("matmul 2x4 . 4x3", &got, &exp, &got_ss, dhl);
    check(got.nrows == 2 && got.ncols == 3, "matmul_OO result shape 2x3");

    // Shape mismatch.
    check(arro_matmul_OO_to(&a2.dn, &a2.dn, &got, dhl) == DN_ERR_SIZE, "matmul rejects unaligned shapes");
    check(got.nrows == 2 && got.ncols == 3, "a failed matmul leaves res untouched");

    // Regression (review M2): elements of different trc, and the inner order must not matter.
    // x1 = y1 = 1 + e1 at trc 1 and x3 = 1 at trc 3: the trc-1 product x1 * y1 has no e1^2.
    {
        sotinum_t x1 = soti_createEmpty(1, dhl), x3 = soti_createEmpty(3, dhl);
        sotinum_t y1 = soti_createEmpty(1, dhl), y1b = soti_createEmpty(1, dhl);
        arrso_t row = arrso_zeros_bases(1, 2, 0, 3, dhl), col = arrso_zeros_bases(2, 1, 0, 3, dhl);
        arrso_t rexp = arrso_zeros_bases(1, 1, 0, 0, dhl);
        arro_t drow = arro_init(), dcol = arro_init(), dgot = arro_init();
        int order;

        x1.re = 1.0;
        soti_set_item(1.0, 0, 1, &x1, dhl);
        x3.re = 1.0;
        y1.re = 1.0;
        soti_set_item(1.0, 0, 1, &y1, dhl);
        y1b.re = 1.0;
        soti_set_item(1.0, 0, 1, &y1b, dhl);

        for (order = 0; order < 2; order++){

            soti_free(&row.p_data[0]);
            soti_free(&row.p_data[1]);
            row.p_data[order]     = soti_copy(&x3, dhl);
            row.p_data[1 - order] = soti_copy(&x1, dhl);
            soti_free(&col.p_data[0]);
            soti_free(&col.p_data[1]);
            col.p_data[0] = soti_copy(&y1, dhl);
            col.p_data[1] = soti_copy(&y1b, dhl);

            arro_free(&drow);
            arro_free(&dcol);
            arro_from_arrso_to(&row, &drow, dhl);
            arro_from_arrso_to(&col, &dcol, dhl);
            arrso_matmul_OO_to(&row, &col, &rexp, dhl);
            check(arro_matmul_OO_to(&drow, &dcol, &dgot, dhl) == DN_OK, "matmul mixed trc status");
            compare_arro(order == 0 ? "matmul mixed trc [x3 x1] . [y1; y1]"
                                    : "matmul mixed trc [x1 x3] . [y1; y1]", &dgot, &rexp, NULL, dhl);
            check(dgot.p_data[0].trc_order == 3 && num_coef(&dgot.p_data[0], 0, 2) == 0.0
                  && num_coef(&dgot.p_data[0], 0, 1) == 3.0, "matmul mixed trc: no e1^2, 2 + 3 e1");

        }

        arro_free(&drow);
        arro_free(&dcol);
        arro_free(&dgot);
        arrso_free(&row);
        arrso_free(&col);
        arrso_free(&rexp);
        soti_free(&x1);
        soti_free(&x3);
        soti_free(&y1);
        soti_free(&y1b);
    }

    // Empty inner dimension: zeros.
    {
        arro_t e1 = arro_init(), e2 = arro_init(), r = arro_init();

        arro_zeros_to(2, 0, 0, &e1);
        arro_zeros_to(0, 3, 0, &e2);
        check(arro_matmul_OO_to(&e1, &e2, &r, dhl) == DN_OK && r.nrows == 2 && r.ncols == 3 &&
              r.p_data[5].re == 0.0, "matmul with an empty inner dimension gives zeros");
        arro_free(&e1);
        arro_free(&e2);
        arro_free(&r);
    }

    arrso_free(&exp);
    arrss_free(&got_ss);
    arro_free(&got);
    free_operand(&a1);
    free_operand(&a2);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Review M1: arro_to_oarr into a result that held many bases must follow the capacity rule (no
 * allocation over the old layout). Review m2: the scalar operand may be an element of res or arr1. */
static void test_review_fixes(dhelpl_t dhl){

    // M1: a 1 x 10 array over 200 bases at trc 1, reused for 10 elements of nact 1 at trc 4.
    {
        arro_t src = arro_init();
        oarr_t res = oarr_init();
        otinum_t unit = oti_init();
        uint64_t e;

        check(arro_zeros_to(1, 10, 4, &src) == DN_OK, "M1: source array");
        check(oti_e_to(0, 1, 4, &unit) == DN_OK, "M1: unit");

        for (e = 0; e < 10; e++){
            check(arro_set_item(&unit, 0, e, &src) == DN_OK, "M1: set item");
        }

        check(oarr_zeros_to(200, 1, 10, 1, &res) == DN_OK, "M1: previous result over 200 bases");
        check(arro_to_oarr(&src, &res) == DN_OK, "M1: arro_to_oarr status");
        check(res.nact == 1 && res.trc_order == 4 && res.nbases == 1, "M1: capacity is nact, not 200");
        check(res.nrows == 1 && res.ncols == 10 && res.p_data[0] == 0.0, "M1: shape and real part");

        oarr_free(&res);
        oti_free(&unit);
        arro_free(&src);
    }

    // m2: num is an element of the array that is also the result (all 100 elements 2 + e1).
    {
        arro_t a = arro_init(), b = arro_init(), c = arro_init();
        otinum_t x = oti_init();
        uint64_t e;
        int ok = 1;

        check(arro_zeros_to(1, 100, 2, &a) == DN_OK, "m2: array");
        check(oti_e_to(0, 1, 2, &x) == DN_OK, "m2: unit");
        x.re = 2.0;

        for (e = 0; e < 100; e++){
            arro_set_item(&x, 0, e, &a);
        }

        check(arro_copy_to(&a, &b) == DN_OK, "m2: copy");

        // res == arr1 and num inside it: every element becomes (2 + e1)^2.
        check(arro_mul_oO_to(arro_get_item_ptr(0, 0, &a), &a, &a, dhl) == DN_OK, "m2: mul status");

        for (e = 0; e < 100; e++){
            ok = ok && a.p_data[e].re == 4.0 && num_coef(&a.p_data[e], 0, 1) == 4.0
                    && num_coef(&a.p_data[e], 0, 2) == 1.0;
        }

        check(ok, "m2: arro_mul_oO_to with num inside res == arr1");

        // res != arr1, num inside res, and res is resized (3 -> 100 elements): num would dangle.
        check(arro_zeros_to(1, 3, 2, &c) == DN_OK, "m2: small result");
        arro_set_item(&x, 0, 0, &c);
        check(arro_sum_oO_to(arro_get_item_ptr(0, 0, &c), &b, &c, dhl) == DN_OK, "m2: sum status");
        ok = c.size == 100;

        for (e = 0; e < c.size && ok; e++){
            ok = c.p_data[e].re == 4.0 && num_coef(&c.p_data[e], 0, 1) == 2.0;
        }

        check(ok, "m2: arro_sum_oO_to with num inside a resized res");

        // Oo variants with num inside arr1 (res == arr1): 2 + e1 minus the first element is zero.
        arro_copy_to(&b, &a);
        check(arro_sub_Oo_to(&a, arro_get_item_ptr(0, 0, &a), &a, dhl) == DN_OK, "m2: sub status");
        ok = 1;

        for (e = 0; e < 100; e++){
            ok = ok && a.p_data[e].re == 0.0 && num_coef(&a.p_data[e], 0, 1) == 0.0;
        }

        check(ok, "m2: arro_sub_Oo_to with num inside res == arr1");

        oti_free(&x);
        arro_free(&a);
        arro_free(&b);
        arro_free(&c);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_transpose(dhelpl_t dhl){

    static const uint64_t shapes[2][2] = {{3, 3}, {2, 4}};
    size_t s;

    for (s = 0; s < 2; s++){

        operand_t a1 = make_operand(shapes[s][0], shapes[s][1], dhl, rand_re_general, 20, 1);
        arrso_t exp = arrso_zeros_bases(shapes[s][1], shapes[s][0], 0, 0, dhl);
        arro_t got = arro_init();
        arrss_t tss = arrss_init();
        char tag[64];

        arrso_transpose_to(&a1.so, &exp, dhl);
        arrss_transpose_to(&a1.ss, &tss);
        check(arro_transpose_to(&a1.dn, &got) == DN_OK, "transpose status");

        snprintf(tag, sizeof(tag), "transpose %llux%llu", (unsigned long long)shapes[s][0],
                 (unsigned long long)shapes[s][1]);
        compare_arro(tag, &got, &exp, &tss, dhl);

        // Aliased: transposes in place.
        check(arro_transpose_to(&a1.dn, &a1.dn) == DN_OK, "transpose aliased status");
        snprintf(tag, sizeof(tag), "transpose %llux%llu (aliased)", (unsigned long long)shapes[s][0],
                 (unsigned long long)shapes[s][1]);
        compare_arro(tag, &a1.dn, &exp, NULL, dhl);
        check(a1.dn.nrows == shapes[s][1] && a1.dn.ncols == shapes[s][0],
              "transpose swaps the shape in place");

        arrso_free(&exp);
        arro_free(&got);
        arrss_free(&tss);
        free_operand(&a1);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* res aliasing an input operand, for a representative sample of ops. */
static void test_aliasing(dhelpl_t dhl){

    operand_t a1 = make_operand(3, 3, dhl, rand_re_general, 20, 1);
    operand_t a2 = make_operand(3, 3, dhl, rand_re_general, 20, 1);
    otinum_t dnum = oti_init();
    sotinum_t num = soti_createEmpty(MAXORD, dhl);
    arro_t w = arro_init();

    build_random_element(&num, MAXORD, dhl, rand_re_general, 0);
    oti_from_soti_to(&num, &dnum, dhl);

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);

        arrso_sum_OO_to(&a1.so, &a2.so, &exp, dhl);
        arro_copy_to(&a1.dn, &w);
        check(arro_sum_OO_to(&w, &a2.dn, &w, dhl) == DN_OK, "aliased sum status");
        compare_arro("aliased sum_OO_to(res=arr1)", &w, &exp, NULL, dhl);
        arrso_free(&exp);
    }

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);

        arrso_mul_OO_to(&a1.so, &a2.so, &exp, dhl);
        arro_copy_to(&a2.dn, &w);
        check(arro_mul_OO_to(&a1.dn, &w, &w, dhl) == DN_OK, "aliased mul status");
        compare_arro("aliased mul_OO_to(res=arr2)", &w, &exp, NULL, dhl);
        arrso_free(&exp);
    }

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);

        arrso_div_oO_to(&num, &a1.so, &exp, dhl);
        arro_copy_to(&a1.dn, &w);
        check(arro_div_oO_to(&dnum, &w, &w, dhl) == DN_OK, "aliased scalar div status");
        compare_arro("aliased div_oO_to(res=arr1)", &w, &exp, NULL, dhl);
        arrso_free(&exp);
    }

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);

        arrso_exp_to(&a1.so, &exp, dhl);
        arro_copy_to(&a1.dn, &w);
        check(arro_exp_to(&w, &w, dhl) == DN_OK, "aliased exp status");
        compare_arro("aliased exp_to(res=arr1)", &w, &exp, NULL, dhl);
        arrso_free(&exp);
    }

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arro_t sq = arro_init(), sqcopy = arro_init();
        arrso_t exp2 = arrso_zeros_bases(3, 3, 0, 0, dhl);

        arrso_truncate_order_to(2, &a1.so, &exp, dhl);
        arro_copy_to(&a1.dn, &w);
        arro_truncate_order_to(2, &w, &w, dhl);
        arro_compact_to(&w, &w, dhl);
        compare_arro("aliased truncate_order+compact(res=arr1)", &w, &exp, NULL, dhl);

        // matmul with res aliasing an operand.
        arrso_matmul_OO_to(&a1.so, &a2.so, &exp2, dhl);
        arro_copy_to(&a1.dn, &sq);
        arro_copy_to(&a2.dn, &sqcopy);
        check(arro_matmul_OO_to(&sq, &sqcopy, &sq, dhl) == DN_OK, "aliased matmul status");
        compare_arro("aliased matmul_OO_to(res=arr1)", &sq, &exp2, NULL, dhl);

        arro_copy_to(&a1.dn, &sq);
        arro_matmul_OO_to(&sq, &sqcopy, &sqcopy, dhl);
        compare_arro("aliased matmul_OO_to(res=arr2)", &sqcopy, &exp2, NULL, dhl);

        arrso_free(&exp);
        arrso_free(&exp2);
        arro_free(&sq);
        arro_free(&sqcopy);
    }

    arro_free(&w);
    oti_free(&dnum);
    soti_free(&num);
    free_operand(&a1);
    free_operand(&a2);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Shape mismatches give DN_ERR_SIZE and leave the result as it was. */
static void test_shape_errors(dhelpl_t dhl){

    operand_t a = make_operand(3, 3, dhl, rand_re_general, 20, 1);
    operand_t b = make_operand(2, 4, dhl, rand_re_general, 20, 1);
    arro_t res = arro_init();
    arro_t K = arro_init();
    int st;

    arro_zeros_to(1, 1, 2, &res);
    res.p_data[0].re = 5.0;

    check(arro_sum_OO_to(&a.dn, &b.dn, &res, dhl) == DN_ERR_SIZE, "sum_OO shape mismatch: DN_ERR_SIZE");
    check(arro_sub_OO_to(&a.dn, &b.dn, &res, dhl) == DN_ERR_SIZE, "sub_OO shape mismatch: DN_ERR_SIZE");
    check(arro_mul_OO_to(&a.dn, &b.dn, &res, dhl) == DN_ERR_SIZE, "mul_OO shape mismatch: DN_ERR_SIZE");
    check(arro_div_OO_to(&a.dn, &b.dn, &res, dhl) == DN_ERR_SIZE, "div_OO shape mismatch: DN_ERR_SIZE");
    check(res.size == 1 && res.p_data[0].re == 5.0, "a failed elementwise call leaves res untouched");

    // Non-square K and mismatched b for the linear algebra.
    st = arro_solve_to(&b.dn, &a.dn, &res, dhl);
    check(st == DN_ERR_SIZE, "solve with a non-square K: DN_ERR_SIZE");
    check(arro_inv_to(&b.dn, &res, dhl) == DN_ERR_SIZE, "inv of a non-square matrix: DN_ERR_SIZE");
    {
        otinum_t d = oti_init();

        check(arro_det_to(&b.dn, &d, dhl) == DN_ERR_SIZE, "det of a non-square matrix: DN_ERR_SIZE");
        oti_free(&d);
    }
    check(arro_solve_to(&a.dn, &b.dn, &res, dhl) == DN_ERR_SIZE,
          "solve with mismatched rows: DN_ERR_SIZE");

    arro_free(&res);
    arro_free(&K);
    free_operand(&a);
    free_operand(&b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* solve / inv / det through the SoA layer, vs arrso_solve / arrso_invert / arrso_det and the semi-sparse
 * ones. K's diagonal is boosted to keep the real part invertible; the elements of K and b have
 * different nact and trc. */
static void test_linalg(dhelpl_t dhl){

    arrso_t K = build_random_arrso(3, 3, dhl, rand_re_general, 0, 1);
    arrso_t b = build_random_arrso(3, 2, dhl, rand_re_general, 0, 1);
    arrss_t sK, sb;
    arro_t dK = arro_init(), db = arro_init();
    int i;

    for (i = 0; i < 3; i++){
        K.p_data[i * 3 + i].re += (K.p_data[i * 3 + i].re >= 0.0) ? 6.0 : -6.0;
    }

    sK = arrss_from_arrso(&K, dhl);
    sb = arrss_from_arrso(&b, dhl);
    arro_from_arrso_to(&K, &dK, dhl);
    arro_from_arrso_to(&b, &db, dhl);

    {
        arrso_t exp = arrso_zeros_bases(K.nrows, b.ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init(), alias = arro_init();
        int st_exp, st_ss, st;

        st_exp = arrso_solve_to(&K, &b, &exp, dhl);
        st_ss  = arrss_solve_to(&sK, &sb, &got_ss, dhl);
        st     = arro_solve_to(&dK, &db, &got, dhl);

        check(st_exp == 0 && st_ss == 0 && st == DN_OK, "solve statuses (K diagonally dominant)");
        compare_arro("solve K x = b, 3x3 / 3x2", &got, &exp, &got_ss, dhl);

        arro_copy_to(&db, &alias);
        st = arro_solve_to(&dK, &alias, &alias, dhl);
        check(st == DN_OK, "solve with x aliasing b: status");
        compare_arro("solve aliased x = b", &alias, &exp, &got_ss, dhl);

        arro_copy_to(&dK, &alias);
        st = arro_solve_to(&alias, &db, &alias, dhl);
        check(st == DN_OK, "solve with x aliasing K: status");
        compare_arro("solve aliased x = K", &alias, &exp, &got_ss, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);
        arro_free(&alias);
    }

    {
        arrso_t exp = arrso_zeros_bases(K.nrows, K.ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arro_t got = arro_init();
        int st_exp, st_ss, st;

        st_exp = arrso_invert_to(&K, &exp, dhl);
        st_ss  = arrss_inv_to(&sK, &got_ss, dhl);
        st     = arro_inv_to(&dK, &got, dhl);

        check(st_exp == 0 && st_ss == 0 && st == DN_OK, "inv statuses");
        compare_arro("inv(K) 3x3", &got, &exp, &got_ss, dhl);

        arro_copy_to(&dK, &got);
        check(arro_inv_to(&got, &got, dhl) == DN_OK, "inv aliased status");
        compare_arro("inv(K) aliased", &got, &exp, &got_ss, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arro_free(&got);
    }

    {
        sotinum_t exp = soti_init();
        ssotinum_t got_ss = ssoti_init();
        otinum_t got = oti_init();
        int st_exp, st_ss, st;

        st_exp = arrso_det_to(&K, &exp, dhl);
        st_ss  = arrss_det_to(&sK, &got_ss, dhl);
        st     = arro_det_to(&dK, &got, dhl);

        check(st_exp == 0 && st_ss == 0 && st == DN_OK, "det statuses");
        compare_num_vs_soti("det(K)", &got, &exp, TOL_SPARSE, dhl);
        compare_num_vs_ssoti("det(K)", &got, &got_ss, TOL_SEMI);

        soti_free(&exp);
        ssoti_free(&got_ss);
        oti_free(&got);
    }

    // Singular real part: status > 0 (equal to semi-sparse's), the result untouched and freeable.
    {
        arro_t Ks = arro_init(), x = arro_init(), inv = arro_init();
        otinum_t d = oti_create_empty(2, 2);
        arrss_t sKs, sx = arrss_init();
        uint64_t j;
        int st, st_ss;

        arro_copy_to(&dK, &Ks);

        for (j = 0; j < 3; j++){
            Ks.p_data[1 * 3 + j].re = 0.0;              // row 1 real part = 0.
        }

        {
            arrso_t Kso = arro_to_arrso(&Ks, dhl);

            sKs = arrss_from_arrso(&Kso, dhl);
            arrso_free(&Kso);
        }

        st    = arro_solve_to(&Ks, &db, &x, dhl);
        st_ss = arrss_solve_to(&sKs, &sb, &sx, dhl);
        check(st > 0 && st == st_ss && x.size == 0,
              "singular solve: status > 0 equal to semi-sparse's, x untouched");
        check(arro_inv_to(&Ks, &inv, dhl) > 0, "singular inv: status > 0");
        check(arro_det_to(&Ks, &d, dhl) > 0 && d.nact == 2 && d.trc_order == 2,
              "singular det: status > 0, result untouched");

        arro_free(&Ks);
        arro_free(&x);
        arro_free(&inv);
        oti_free(&d);
        arrss_free(&sKs);
        arrss_free(&sx);
    }

    arrso_free(&K);
    arrso_free(&b);
    arrss_free(&sK);
    arrss_free(&sb);
    arro_free(&dK);
    arro_free(&db);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* The rank-fallback case: elements with nact 11 at order 5 (above Nbasis(5) = 10), and a smaller-nact
 * element beside them. The AoS elementwise product and matmul against the SoA kernels (an
 * independent code path over the same layout). */
static void test_fallback_k11(dhelpl_t dhl){

    arro_t A = arro_init(), B = arro_init(), P = arro_init(), M = arro_init();
    oarr_t sA = oarr_init(), sB = oarr_init(), sP = oarr_init(), tP = oarr_init(), sM = oarr_init();
    oarr_t tM = oarr_init();
    uint64_t e;
    int status;
    static const bases_t ks[8] = {11, 11, 4, 11, 11, 7, 11, 11};

    arro_zeros_to(2, 2, 5, &A);
    arro_zeros_to(2, 2, 5, &B);

    for (e = 0; e < 4; e++){

        otinum_t x = oti_create_empty(ks[e], 5), y = oti_create_empty(ks[e + 4], 5);
        ndir_t d, n;

        n = sshelp_ndir_total(ks[e], 5);

        for (d = 0; d < n; d++){
            x.p_im[d] = (rand() % 5 == 0) ? frand(-0.5, 0.5) : 0.0;
        }

        n = sshelp_ndir_total(ks[e + 4], 5);

        for (d = 0; d < n; d++){
            y.p_im[d] = (rand() % 5 == 0) ? frand(-0.5, 0.5) : 0.0;
        }

        x.re         = frand(0.5, 1.5);
        y.re         = frand(0.5, 1.5);
        x.act_order  = 5;
        y.act_order  = 5;
        arro_set_item(&x, e / 2, e % 2, &A);
        arro_set_item(&y, e / 2, e % 2, &B);
        oti_free(&x);
        oti_free(&y);

    }

    // Elementwise product vs the SoA kernel.
    status = arro_mul_OO_to(&A, &B, &P, dhl);
    check(status == DN_OK, "k = 11 order 5: arro_mul_OO_to status");
    arro_to_oarr(&A, &sA);
    arro_to_oarr(&B, &sB);
    check(oarr_mul_OO_to(&sA, &sB, &sP, dhl) == DN_OK, "k = 11: SoA product status");
    arro_to_oarr(&P, &tP);
    check(tP.nact == 11 && sP.nact == 11 && tP.trc_order == 5, "k = 11 product: nact 11, trc 5");

    {
        uint64_t n = (1 + sshelp_ndir_total(11, 5)) * sP.size, bad = 0;

        for (e = 0; e < n; e++){

            bad += !(fabs(tP.p_data[e] - sP.p_data[e]) <= 1e-13 * fmax(1.0, fabs(sP.p_data[e])));

        }

        check(bad == 0, "k = 11 order 5: arro_mul_OO_to equals the SoA product");
    }

    // Matrix product (2x2 . 2x2) vs the SoA matmul.
    check(arro_matmul_OO_to(&A, &B, &M, dhl) == DN_OK, "k = 11 order 5: arro_matmul_OO_to status");
    check(oarr_matmul_OO_to(&sA, &sB, &sM, dhl) == DN_OK, "k = 11: SoA matmul status");
    arro_to_oarr(&M, &tM);

    {
        uint64_t n = (1 + sshelp_ndir_total(11, 5)) * sM.size, bad = 0;

        check(tM.nact == 11 && tM.trc_order == 5, "k = 11 matmul: nact 11, trc 5");

        for (e = 0; e < n; e++){

            bad += !(fabs(tM.p_data[e] - sM.p_data[e]) <= 1e-13 * fmax(1.0, fabs(sM.p_data[e])));

        }

        check(bad == 0, "k = 11 order 5: arro_matmul_OO_to equals the SoA matmul");
    }

    arro_free(&A);
    arro_free(&B);
    arro_free(&P);
    arro_free(&M);
    oarr_free(&sA);
    oarr_free(&sB);
    oarr_free(&sP);
    oarr_free(&tP);
    oarr_free(&sM);
    oarr_free(&tM);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* 1 vs N OpenMP threads must give identical results (each output element is computed independently),
 * for a 20 x 20 elementwise mul and matmul. */
static void test_threads(dhelpl_t dhl){

#ifdef _OPENMP
    operand_t a1 = make_operand(20, 20, dhl, rand_re_general, 10, 1);
    operand_t a2 = make_operand(20, 20, dhl, rand_re_general, 10, 1);
    int max_threads = omp_get_max_threads();
    arro_t mul1 = arro_init(), mulN = arro_init(), mm1 = arro_init(), mmN = arro_init();

    omp_set_num_threads(1);
    arro_mul_OO_to(&a1.dn, &a2.dn, &mul1, dhl);
    arro_matmul_OO_to(&a1.dn, &a2.dn, &mm1, dhl);

    omp_set_num_threads(max_threads > 1 ? max_threads : 4);
    arro_mul_OO_to(&a1.dn, &a2.dn, &mulN, dhl);
    arro_matmul_OO_to(&a1.dn, &a2.dn, &mmN, dhl);

    // Every worker thread keeps a per-thread workspace (oti_ws()): release them before leak checking.
    #pragma omp parallel
    {
        oti_ws_release();
    }

    omp_set_num_threads(max_threads);

    compare_arro_dense("mul_OO 20x20, 1 vs N threads", &mul1, &mulN, 0.0, 1);
    compare_arro_dense("matmul_OO 20x20, 1 vs N threads", &mm1, &mmN, 0.0, 1);

    arro_free(&mul1);
    arro_free(&mulN);
    arro_free(&mm1);
    arro_free(&mmN);
    free_operand(&a1);
    free_operand(&a2);
#else
    (void)dhl;
    printf("skipped: 1 vs N threads (not built with OpenMP)\n");
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    srand(20260929u);
    dhelp_load(NULL, &dhl);

    test_memory(dhl);
    test_conversions(dhl);
    test_elementwise(dhl);
    test_functions(dhl);
    test_truncation_compact(dhl);
    test_matmul(dhl);
    test_transpose(dhl);
    test_review_fixes(dhl);
    test_aliasing(dhl);
    test_shape_errors(dhl);
    test_linalg(dhl);
    test_fallback_k11(dhl);
    test_threads(dhl);

    oti_ws_release();
    ssoti_ws_release();
    dhelp_free(&dhl);

    printf("\n%llu numeric checks, %d failure(s).\n", (unsigned long long)n_checks, n_failed);

    if (n_failed != 0){
        return 1;
    }

    printf("All dense AoS array checks passed.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
