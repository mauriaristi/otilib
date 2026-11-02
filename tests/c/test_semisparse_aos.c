/* Tests of the semi-sparse AoS array (arrss_t, include/oti/semisparse/array/array.h,
 * src/c/semisparse/array/array.c). Oracle = arrso_t (sparse AoS array, row-major like arrss_t).
 * Random arrso_t inputs whose elements have different active sets (k <= 4 bases from labels
 * 1..6, order <= 4, some purely real elements) are converted to arrss_t, run through the
 * semi-sparse op, converted back, and compared exhaustively (every direction over the 6-label
 * universe, every order 0..4) against the sparse op's result on the same inputs. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <oti/oti.h>

#ifdef _OPENMP
#include <omp.h>
#endif

#define UNIV_N 6
#define MAXORD 4

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
/* Numeric check: silent on success (used at exhaustive, per-direction granularity -- printing
 * every one of those would flood the log), reported and counted either way. */
static void check_close(const char* label, double got, double expected){

    n_checks++;

    if (!isfinite(expected)){
        return;
    }

    if (!isfinite(got) || fabs(got - expected) > 1e-8 * (1.0 + fabs(expected))){
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


// *******************************************************************************************************
/* Fills an already-created element (trc_order >= MAXORD) with a random real part and, unless
 * force_real is set, a random set of k <= 4 bases (from the 6-label universe) and a couple of
 * random directions per order over those bases. */
static void build_random_element(sotinum_t* elem, dhelpl_t dhl, double (*re_gen)(void),
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

    }

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

    }

    for (p = 1; p <= MAXORD; p++){

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

            }

            idx = (imdir_t)sshelp_global_rank(tuple, p);
            soti_set_item(rand_coef(), idx, p, elem, dhl);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* real_pct: chance (0..100) that a given element is forced real-only (k = 0). */
static arrso_t build_random_arrso(uint64_t nrows, uint64_t ncols, dhelpl_t dhl,
                                  double (*re_gen)(void), int real_pct){

    arrso_t arr = arrso_zeros_bases(nrows, ncols, 0, MAXORD, dhl);
    uint64_t e;

    for (e = 0; e < arr.size; e++){

        int force_real = (int)((rand() % 100) < real_pct);

        build_random_element(&arr.p_data[e], dhl, re_gen, force_real);

    }

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Every direction over the 6-label universe, order 0..MAXORD: N_p(6) directions per order,
 * global indices 0 .. N_p(6) - 1 (colex prefix property, PLAN-semisparse.md Section 2). */
static void compare_soti_exhaustive(const char* tag, sotinum_t* a, sotinum_t* b, dhelpl_t dhl){

    ord_t p;
    ndir_t n, i;
    char label[224];

    snprintf(label, sizeof(label), "%s re", tag);
    check_close(label, a->re, b->re);

    for (p = 1; p <= MAXORD; p++){

        n = sshelp_ndir_order(UNIV_N, p);

        for (i = 0; i < n; i++){

            snprintf(label, sizeof(label), "%s ord=%u idx=" _PNDIRT, tag, (unsigned)p, i);
            check_close(label, soti_get_item((imdir_t)i, p, a, dhl), soti_get_item((imdir_t)i, p, b, dhl));

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void compare_arrso_exhaustive(const char* tag, arrso_t* a, arrso_t* b, dhelpl_t dhl){

    uint64_t e;
    char label[256];
    uint64_t before = n_failed;

    if (a->nrows != b->nrows || a->ncols != b->ncols){

        fprintf(stderr, "FAILED %s: shape mismatch (%llux%llu vs %llux%llu)\n", tag,
            (unsigned long long)a->nrows, (unsigned long long)a->ncols,
            (unsigned long long)b->nrows, (unsigned long long)b->ncols);
        n_failed++;
        return;

    }

    for (e = 0; e < a->size; e++){

        snprintf(label, sizeof(label), "%s elem " "%llu", tag, (unsigned long long)e);
        compare_soti_exhaustive(label, &a->p_data[e], &b->p_data[e], dhl);

    }

    if (n_failed == before){
        printf("passed: %s (%llu elements, exhaustive over %d-label universe up to order %d)\n",
            tag, (unsigned long long)a->size, UNIV_N, MAXORD);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* arrso -> arrss -> arrso must reproduce the original values exactly, for every shape used below. */
static void test_roundtrip(dhelpl_t dhl){

    static const uint64_t shapes[4][2] = {{1, 1}, {3, 3}, {2, 4}, {4, 3}};
    size_t s;

    for (s = 0; s < 4; s++){

        arrso_t src = build_random_arrso(shapes[s][0], shapes[s][1], dhl, rand_re_general, 20);
        arrss_t mid = arrss_from_arrso(&src, dhl);
        arrso_t back = arrss_to_arrso(&mid, dhl);
        char tag[64];

        snprintf(tag, sizeof(tag), "roundtrip %llux%llu",
            (unsigned long long)shapes[s][0], (unsigned long long)shapes[s][1]);
        compare_arrso_exhaustive(tag, &src, &back, dhl);

        check((int)(mid.nrows == shapes[s][0] && mid.ncols == shapes[s][1]),
            "arrss_from_arrso keeps shape");

        arrso_free(&src);
        arrss_free(&mid);
        arrso_free(&back);

    }

}
// -------------------------------------------------------------------------------------------------------


typedef void (*arrso_oo_fn)(arrso_t*, arrso_t*, arrso_t*, dhelpl_t);
typedef void (*arrss_oo_fn)(const arrss_t*, const arrss_t*, arrss_t*, dhelpl_t);
typedef void (*arrso_oscalar_fn)(sotinum_t*, arrso_t*, arrso_t*, dhelpl_t);
typedef void (*arrss_oscalar_fn)(const ssotinum_t*, const arrss_t*, arrss_t*, dhelpl_t);
typedef void (*arrso_rO_fn)(coeff_t, arrso_t*, arrso_t*, dhelpl_t);
typedef void (*arrss_rO_fn)(coeff_t, const arrss_t*, arrss_t*, dhelpl_t);
typedef void (*arrso_Oscalar_fn)(arrso_t*, sotinum_t*, arrso_t*, dhelpl_t);
typedef void (*arrss_Oscalar_fn)(const arrss_t*, const ssotinum_t*, arrss_t*, dhelpl_t);
typedef void (*arrso_Or_fn)(arrso_t*, coeff_t, arrso_t*, dhelpl_t);
typedef void (*arrss_Or_fn)(const arrss_t*, coeff_t, arrss_t*, dhelpl_t);
typedef void (*arrso_unary_fn)(arrso_t*, arrso_t*, dhelpl_t);
typedef void (*arrss_unary_fn)(const arrss_t*, arrss_t*, dhelpl_t);


// *******************************************************************************************************
/* OO, oO, rO, Oo, Or elementwise ops (+ - x /) and negation, for one shape. arr1/arr2 have
 * different active sets and some purely real elements; num/val are the scalar/real operands. */
static void test_elementwise_shape(uint64_t nrows, uint64_t ncols, dhelpl_t dhl){

    static const struct { const char* name; arrso_oo_fn f_so; arrss_oo_fn f_ss; } oo_ops[] = {
        {"sum_OO", arrso_sum_OO_to, arrss_sum_OO_to},
        {"sub_OO", arrso_sub_OO_to, arrss_sub_OO_to},
        {"mul_OO", arrso_mul_OO_to, arrss_mul_OO_to},
        {"div_OO", arrso_div_OO_to, arrss_div_OO_to},
    };
    static const struct { const char* name; arrso_oscalar_fn f_so; arrss_oscalar_fn f_ss; }
        oscalar_ops[] = {
        {"sum_oO", arrso_sum_oO_to, arrss_sum_oO_to},
        {"sub_oO", arrso_sub_oO_to, arrss_sub_oO_to},
        {"mul_oO", arrso_mul_oO_to, arrss_mul_oO_to},
        {"div_oO", arrso_div_oO_to, arrss_div_oO_to},
    };
    static const struct { const char* name; arrso_rO_fn f_so; arrss_rO_fn f_ss; } rO_ops[] = {
        {"sum_rO", arrso_sum_rO_to, arrss_sum_rO_to},
        {"sub_rO", arrso_sub_rO_to, arrss_sub_rO_to},
        {"mul_rO", arrso_mul_rO_to, arrss_mul_rO_to},
        {"div_rO", arrso_div_rO_to, arrss_div_rO_to},
    };
    static const struct { const char* name; arrso_Oscalar_fn f_so; arrss_Oscalar_fn f_ss; }
        Oscalar_ops[] = {
        {"sub_Oo", arrso_sub_Oo_to, arrss_sub_Oo_to},
        {"div_Oo", arrso_div_Oo_to, arrss_div_Oo_to},
    };
    static const struct { const char* name; arrso_Or_fn f_so; arrss_Or_fn f_ss; } Or_ops[] = {
        {"sub_Or", arrso_sub_Or_to, arrss_sub_Or_to},
        {"div_Or", arrso_div_Or_to, arrss_div_Or_to},
    };

    arrso_t a1 = build_random_arrso(nrows, ncols, dhl, rand_re_general, 20);
    arrso_t a2 = build_random_arrso(nrows, ncols, dhl, rand_re_general, 20);
    sotinum_t num = soti_createEmpty(MAXORD, dhl);
    ssotinum_t snum;
    coeff_t val = rand_coef();
    arrss_t s1, s2;
    size_t i;
    char tag[96];

    build_random_element(&num, dhl, rand_re_general, 0);
    snum = ssoti_from_soti(&num, dhl);
    s1 = arrss_from_arrso(&a1, dhl);
    s2 = arrss_from_arrso(&a2, dhl);

    for (i = 0; i < sizeof(oo_ops) / sizeof(oo_ops[0]); i++){

        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got = arrso_init();

        oo_ops[i].f_so(&a1, &a2, &exp, dhl);
        oo_ops[i].f_ss((const arrss_t*)&s1, (const arrss_t*)&s2, &got_ss, dhl);
        got = arrss_to_arrso(&got_ss, dhl);

        snprintf(tag, sizeof(tag), "%s %llux%llu", oo_ops[i].name,
            (unsigned long long)nrows, (unsigned long long)ncols);
        compare_arrso_exhaustive(tag, &exp, &got, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arrso_free(&got);

    }

    for (i = 0; i < sizeof(oscalar_ops) / sizeof(oscalar_ops[0]); i++){

        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got = arrso_init();

        oscalar_ops[i].f_so(&num, &a1, &exp, dhl);
        oscalar_ops[i].f_ss((const ssotinum_t*)&snum, (const arrss_t*)&s1, &got_ss, dhl);
        got = arrss_to_arrso(&got_ss, dhl);

        snprintf(tag, sizeof(tag), "%s %llux%llu", oscalar_ops[i].name,
            (unsigned long long)nrows, (unsigned long long)ncols);
        compare_arrso_exhaustive(tag, &exp, &got, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arrso_free(&got);

    }

    for (i = 0; i < sizeof(rO_ops) / sizeof(rO_ops[0]); i++){

        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got = arrso_init();

        rO_ops[i].f_so(val, &a1, &exp, dhl);
        rO_ops[i].f_ss(val, (const arrss_t*)&s1, &got_ss, dhl);
        got = arrss_to_arrso(&got_ss, dhl);

        snprintf(tag, sizeof(tag), "%s %llux%llu", rO_ops[i].name,
            (unsigned long long)nrows, (unsigned long long)ncols);
        compare_arrso_exhaustive(tag, &exp, &got, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arrso_free(&got);

    }

    for (i = 0; i < sizeof(Oscalar_ops) / sizeof(Oscalar_ops[0]); i++){

        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got = arrso_init();

        Oscalar_ops[i].f_so(&a1, &num, &exp, dhl);
        Oscalar_ops[i].f_ss((const arrss_t*)&s1, (const ssotinum_t*)&snum, &got_ss, dhl);
        got = arrss_to_arrso(&got_ss, dhl);

        snprintf(tag, sizeof(tag), "%s %llux%llu", Oscalar_ops[i].name,
            (unsigned long long)nrows, (unsigned long long)ncols);
        compare_arrso_exhaustive(tag, &exp, &got, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arrso_free(&got);

    }

    for (i = 0; i < sizeof(Or_ops) / sizeof(Or_ops[0]); i++){

        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got = arrso_init();

        Or_ops[i].f_so(&a1, val, &exp, dhl);
        Or_ops[i].f_ss((const arrss_t*)&s1, val, &got_ss, dhl);
        got = arrss_to_arrso(&got_ss, dhl);

        snprintf(tag, sizeof(tag), "%s %llux%llu", Or_ops[i].name,
            (unsigned long long)nrows, (unsigned long long)ncols);
        compare_arrso_exhaustive(tag, &exp, &got, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arrso_free(&got);

    }

    {
        arrso_t exp = arrso_zeros_bases(nrows, ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got = arrso_init();

        arrso_neg_to(&a1, &exp, dhl);
        arrss_neg_to((const arrss_t*)&s1, &got_ss, dhl);
        got = arrss_to_arrso(&got_ss, dhl);

        snprintf(tag, sizeof(tag), "neg %llux%llu", (unsigned long long)nrows,
            (unsigned long long)ncols);
        compare_arrso_exhaustive(tag, &exp, &got, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arrso_free(&got);

    }

    arrso_free(&a1);
    arrso_free(&a2);
    soti_free(&num);
    ssoti_free(&snum);
    arrss_free(&s1);
    arrss_free(&s2);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_elementwise(dhelpl_t dhl){

    test_elementwise_shape(1, 1, dhl);
    test_elementwise_shape(3, 3, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_functions(dhelpl_t dhl){

    static const struct { const char* name; double (*re_gen)(void); arrso_unary_fn f_so;
        arrss_unary_fn f_ss; } ops[] = {
        {"neg",   rand_re_general,  arrso_neg_to,   arrss_neg_to},
        {"exp",   rand_re_general,  arrso_exp_to,   arrss_exp_to},
        {"log",   rand_re_positive, arrso_log_to,   arrss_log_to},
        {"log10", rand_re_positive, arrso_log10_to, arrss_log10_to},
        {"sqrt",  rand_re_positive, arrso_sqrt_to,  arrss_sqrt_to},
        {"cbrt",  rand_re_general,  arrso_cbrt_to,  arrss_cbrt_to},
        {"sin",   rand_re_general,  arrso_sin_to,   arrss_sin_to},
        {"cos",   rand_re_general,  arrso_cos_to,   arrss_cos_to},
        {"tan",   rand_re_general,  arrso_tan_to,   arrss_tan_to},
        {"asin",  rand_re_bounded,  arrso_asin_to,  arrss_asin_to},
        {"acos",  rand_re_bounded,  arrso_acos_to,  arrss_acos_to},
        {"atan",  rand_re_general,  arrso_atan_to,  arrss_atan_to},
        {"sinh",  rand_re_general,  arrso_sinh_to,  arrss_sinh_to},
        {"cosh",  rand_re_general,  arrso_cosh_to,  arrss_cosh_to},
        {"tanh",  rand_re_general,  arrso_tanh_to,  arrss_tanh_to},
        {"asinh", rand_re_general,  arrso_asinh_to, arrss_asinh_to},
        {"acosh", rand_re_ge1,      arrso_acosh_to, arrss_acosh_to},
        {"atanh", rand_re_bounded,  arrso_atanh_to, arrss_atanh_to},
        {"erf",   rand_re_general,  arrso_erf_to,   arrss_erf_to},
    };
    size_t i;

    for (i = 0; i < sizeof(ops) / sizeof(ops[0]); i++){

        arrso_t a1 = build_random_arrso(3, 3, dhl, ops[i].re_gen, 20);
        arrss_t s1 = arrss_from_arrso(&a1, dhl);
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got;
        char tag[64];

        ops[i].f_so(&a1, &exp, dhl);
        ops[i].f_ss((const arrss_t*)&s1, &got_ss, dhl);
        got = arrss_to_arrso(&got_ss, dhl);

        snprintf(tag, sizeof(tag), "%s 3x3", ops[i].name);
        compare_arrso_exhaustive(tag, &exp, &got, dhl);

        arrso_free(&a1);
        arrss_free(&s1);
        arrso_free(&exp);
        arrss_free(&got_ss);
        arrso_free(&got);

    }

    {
        static const double exponents[] = {2.0, 0.5, -1.0, 3.0};
        size_t e;

        for (e = 0; e < sizeof(exponents) / sizeof(exponents[0]); e++){

            arrso_t a1 = build_random_arrso(3, 3, dhl, rand_re_positive, 20);
            arrss_t s1 = arrss_from_arrso(&a1, dhl);
            arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
            arrss_t got_ss = arrss_init();
            arrso_t got;
            char tag[64];

            arrso_pow_to(&a1, exponents[e], &exp, dhl);
            arrss_pow_to((const arrss_t*)&s1, exponents[e], &got_ss, dhl);
            got = arrss_to_arrso(&got_ss, dhl);

            snprintf(tag, sizeof(tag), "pow(^%.1f) 3x3", exponents[e]);
            compare_arrso_exhaustive(tag, &exp, &got, dhl);

            arrso_free(&a1);
            arrss_free(&s1);
            arrso_free(&exp);
            arrss_free(&got_ss);
            arrso_free(&got);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_truncation_compact(dhelpl_t dhl){

    arrso_t a1 = build_random_arrso(3, 3, dhl, rand_re_general, 20);
    arrss_t s1 = arrss_from_arrso(&a1, dhl);
    bases_t g3[1] = {3};
    imdir_t idx_b3 = (imdir_t)sshelp_global_rank(g3, 1);

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got;

        arrso_truncate_im_to(idx_b3, 1, &a1, &exp, dhl);
        arrss_truncate_im_to(idx_b3, 1, (const arrss_t*)&s1, &got_ss, dhl);
        got = arrss_to_arrso(&got_ss, dhl);

        compare_arrso_exhaustive("truncate_im(base3,ord1) 3x3", &exp, &got, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arrso_free(&got);

    }

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got;
        uint64_t e, nbases_before = 0, nbases_after = 0;

        arrso_truncate_order_to(2, &a1, &exp, dhl);
        arrss_truncate_order_to(2, (const arrss_t*)&s1, &got_ss, dhl);

        for (e = 0; e < got_ss.size; e++){
            nbases_before += got_ss.p_data[e].nbases;
        }

        arrss_compact_to((const arrss_t*)&got_ss, &got_ss, dhl);

        for (e = 0; e < got_ss.size; e++){
            nbases_after += got_ss.p_data[e].nbases;
        }

        got = arrss_to_arrso(&got_ss, dhl);

        compare_arrso_exhaustive("truncate_order(2)+compact 3x3", &exp, &got, dhl);
        check(nbases_after <= nbases_before, "compact never grows the total active-base count");

        arrso_free(&exp);
        arrss_free(&got_ss);
        arrso_free(&got);

    }

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got;

        arrso_get_order_im_to(2, &a1, &exp, dhl);
        arrss_get_order_im_to(2, (const arrss_t*)&s1, &got_ss, dhl);
        got = arrss_to_arrso(&got_ss, dhl);

        compare_arrso_exhaustive("get_order_im(2) 3x3", &exp, &got, dhl);

        arrso_free(&exp);
        arrss_free(&got_ss);
        arrso_free(&got);

    }

    arrso_free(&a1);
    arrss_free(&s1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_matmul(dhelpl_t dhl){

    arrso_t a1 = build_random_arrso(2, 4, dhl, rand_re_general, 20);
    arrso_t a2 = build_random_arrso(4, 3, dhl, rand_re_general, 20);
    arrss_t s1 = arrss_from_arrso(&a1, dhl);
    arrss_t s2 = arrss_from_arrso(&a2, dhl);
    arrso_t exp = arrso_zeros_bases(2, 3, 0, 0, dhl);
    arrss_t got_ss = arrss_init();
    arrso_t got;

    arrso_matmul_OO_to(&a1, &a2, &exp, dhl);
    arrss_matmul_OO_to((const arrss_t*)&s1, (const arrss_t*)&s2, &got_ss, dhl);
    got = arrss_to_arrso(&got_ss, dhl);

    compare_arrso_exhaustive("matmul 2x4 . 4x3", &exp, &got, dhl);
    check((int)(got_ss.nrows == 2 && got_ss.ncols == 3), "matmul_OO result shape 2x3");

    arrso_free(&a1);
    arrso_free(&a2);
    arrss_free(&s1);
    arrss_free(&s2);
    arrso_free(&exp);
    arrss_free(&got_ss);
    arrso_free(&got);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_transpose(dhelpl_t dhl){

    static const uint64_t shapes[2][2] = {{3, 3}, {2, 4}};
    size_t s;

    for (s = 0; s < 2; s++){

        arrso_t a1 = build_random_arrso(shapes[s][0], shapes[s][1], dhl, rand_re_general, 20);
        arrss_t s1 = arrss_from_arrso(&a1, dhl);
        arrso_t exp = arrso_zeros_bases(shapes[s][1], shapes[s][0], 0, 0, dhl);
        arrso_t got;
        char tag[64];

        arrso_transpose_to(&a1, &exp, dhl);
        arrss_transpose_to((const arrss_t*)&s1, &s1); /* aliased: transposes s1 in place */
        got = arrss_to_arrso(&s1, dhl);

        snprintf(tag, sizeof(tag), "transpose %llux%llu (aliased)",
            (unsigned long long)shapes[s][0], (unsigned long long)shapes[s][1]);
        compare_arrso_exhaustive(tag, &exp, &got, dhl);
        check((int)(s1.nrows == shapes[s][1] && s1.ncols == shapes[s][0]),
            "arrss_transpose_to swaps shape in place");

        arrso_free(&a1);
        arrss_free(&s1);
        arrso_free(&exp);
        arrso_free(&got);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* res aliasing an input operand, for a representative sample of ops (elementwise, truncation,
 * compact; transpose's own aliasing is covered in test_transpose). */
static void test_aliasing(dhelpl_t dhl){

    arrso_t a1 = build_random_arrso(3, 3, dhl, rand_re_general, 20);
    arrso_t a2 = build_random_arrso(3, 3, dhl, rand_re_general, 20);
    arrss_t s1 = arrss_from_arrso(&a1, dhl);
    arrss_t s2 = arrss_from_arrso(&a2, dhl);

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrso_t got;

        arrso_sum_OO_to(&a1, &a2, &exp, dhl);
        arrss_sum_OO_to((const arrss_t*)&s1, (const arrss_t*)&s2, &s1, dhl); /* res == arr1 */
        got = arrss_to_arrso(&s1, dhl);

        compare_arrso_exhaustive("aliased sum_OO_to(res=arr1)", &exp, &got, dhl);

        arrso_free(&exp);
        arrso_free(&got);
        arrss_free(&s1);
        s1 = arrss_from_arrso(&a1, dhl);

    }

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrso_t got;

        arrso_mul_OO_to(&a1, &a2, &exp, dhl);
        arrss_mul_OO_to((const arrss_t*)&s1, (const arrss_t*)&s2, &s2, dhl); /* res == arr2 */
        got = arrss_to_arrso(&s2, dhl);

        compare_arrso_exhaustive("aliased mul_OO_to(res=arr2)", &exp, &got, dhl);

        arrso_free(&exp);
        arrso_free(&got);
        arrss_free(&s2);
        s2 = arrss_from_arrso(&a2, dhl);

    }

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrso_t got;

        arrso_neg_to(&a1, &exp, dhl);
        arrss_neg_to((const arrss_t*)&s1, &s1, dhl); /* res == arr1 */
        got = arrss_to_arrso(&s1, dhl);

        compare_arrso_exhaustive("aliased neg_to(res=arr1)", &exp, &got, dhl);

        arrso_free(&exp);
        arrso_free(&got);
        arrss_free(&s1);
        s1 = arrss_from_arrso(&a1, dhl);

    }

    {
        arrso_t exp = arrso_zeros_bases(3, 3, 0, 0, dhl);
        arrso_t got;

        arrso_truncate_order_to(2, &a1, &exp, dhl);
        arrss_truncate_order_to(2, (const arrss_t*)&s1, &s1, dhl); /* res == arr1 */
        arrss_compact_to((const arrss_t*)&s1, &s1, dhl);           /* res == arr1 again */
        got = arrss_to_arrso(&s1, dhl);

        compare_arrso_exhaustive("aliased truncate_order+compact(res=arr1)", &exp, &got, dhl);

        arrso_free(&exp);
        arrso_free(&got);

    }

    arrso_free(&a1);
    arrso_free(&a2);
    arrss_free(&s1);
    arrss_free(&s2);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* arrss -> oarrss -> arrss round trip: values must be preserved even though every element's
 * active set becomes the union of the original per-element sets. */
static void test_soa_roundtrip(dhelpl_t dhl){

    arrso_t a1 = build_random_arrso(3, 3, dhl, rand_re_general, 20);
    arrss_t s1 = arrss_from_arrso(&a1, dhl);
    oarrss_t soa = oarrss_init();
    arrss_t back = arrss_init();
    arrso_t exp = arrss_to_arrso(&s1, dhl);
    arrso_t got;

    arrss_to_oarrss((const arrss_t*)&s1, &soa);
    arrss_from_oarrss(&soa, &back);
    got = arrss_to_arrso(&back, dhl);

    compare_arrso_exhaustive("arrss<->oarrss roundtrip 3x3", &exp, &got, dhl);
    check((int)(back.nrows == 3 && back.ncols == 3), "arrss_from_oarrss keeps shape");

    arrso_free(&a1);
    arrss_free(&s1);
    oarrss_free(&soa);
    arrss_free(&back);
    arrso_free(&exp);
    arrso_free(&got);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* solve / inv / det through the SoA layer (src/c/semisparse/soa/linalg.c), vs arrso_solve /
 * arrso_invert / arrso_det. K's diagonal is boosted to keep the real part invertible. */
static void test_linalg(dhelpl_t dhl){

    arrso_t K = build_random_arrso(3, 3, dhl, rand_re_general, 0);
    arrso_t b = build_random_arrso(3, 2, dhl, rand_re_general, 0);
    arrss_t sK, sb;
    int i;

    for (i = 0; i < 3; i++){
        K.p_data[i * 3 + i].re += (K.p_data[i * 3 + i].re >= 0.0) ? 6.0 : -6.0;
    }

    sK = arrss_from_arrso(&K, dhl);
    sb = arrss_from_arrso(&b, dhl);

    {
        arrso_t exp = arrso_zeros_bases(K.nrows, b.ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got;
        int st_exp, st_got;

        st_exp = arrso_solve_to(&K, &b, &exp, dhl);
        st_got = arrss_solve_to((const arrss_t*)&sK, (const arrss_t*)&sb, &got_ss, dhl);

        check(st_exp == 0, "arrso_solve_to status 0 (K diagonally dominant)");
        check(st_got == st_exp, "arrss_solve_to status matches arrso_solve_to");

        if (st_exp == 0 && st_got == 0){

            got = arrss_to_arrso(&got_ss, dhl);
            compare_arrso_exhaustive("solve K x = b, 3x3 / 3x2", &exp, &got, dhl);
            arrso_free(&got);

        }

        arrso_free(&exp);
        arrss_free(&got_ss);

    }

    {
        arrso_t exp = arrso_zeros_bases(K.nrows, K.ncols, 0, 0, dhl);
        arrss_t got_ss = arrss_init();
        arrso_t got;
        int st_exp, st_got;

        st_exp = arrso_invert_to(&K, &exp, dhl);
        st_got = arrss_inv_to((const arrss_t*)&sK, &got_ss, dhl);

        check(st_exp == 0, "arrso_invert_to status 0");
        check(st_got == st_exp, "arrss_inv_to status matches arrso_invert_to");

        if (st_exp == 0 && st_got == 0){

            got = arrss_to_arrso(&got_ss, dhl);
            compare_arrso_exhaustive("inv(K) 3x3", &exp, &got, dhl);
            arrso_free(&got);

        }

        arrso_free(&exp);
        arrss_free(&got_ss);

    }

    {
        sotinum_t exp = soti_init();
        ssotinum_t got_ss = ssoti_init();
        sotinum_t got;
        int st_exp, st_got;

        st_exp = arrso_det_to(&K, &exp, dhl);
        st_got = arrss_det_to((const arrss_t*)&sK, &got_ss, dhl);

        check(st_exp == 0, "arrso_det_to status 0");
        check(st_got == st_exp, "arrss_det_to status matches arrso_det_to");

        if (st_exp == 0 && st_got == 0){

            got = ssoti_to_soti(&got_ss, dhl);
            compare_soti_exhaustive("det(K)", &exp, &got, dhl);
            soti_free(&got);

        }

        soti_free(&exp);
        ssoti_free(&got_ss);

    }

    arrso_free(&K);
    arrso_free(&b);
    arrss_free(&sK);
    arrss_free(&sb);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* 1 vs N OpenMP threads must give identical results (no shared accumulation across threads: each
 * output element/product is computed independently), for a 20x20 elementwise mul and matmul. */
static void test_threads(dhelpl_t dhl){

#ifdef _OPENMP
    arrso_t a1 = build_random_arrso(20, 20, dhl, rand_re_general, 10);
    arrso_t a2 = build_random_arrso(20, 20, dhl, rand_re_general, 10);
    arrss_t s1 = arrss_from_arrso(&a1, dhl);
    arrss_t s2 = arrss_from_arrso(&a2, dhl);
    int max_threads = omp_get_max_threads();
    arrss_t mul1 = arrss_init(), mulN = arrss_init();
    arrss_t mm1 = arrss_init(), mmN = arrss_init();
    arrso_t mul1_o, mulN_o, mm1_o, mmN_o;

    omp_set_num_threads(1);
    arrss_mul_OO_to((const arrss_t*)&s1, (const arrss_t*)&s2, &mul1, dhl);
    arrss_matmul_OO_to((const arrss_t*)&s1, (const arrss_t*)&s2, &mm1, dhl);

    omp_set_num_threads(max_threads > 1 ? max_threads : 4);
    arrss_mul_OO_to((const arrss_t*)&s1, (const arrss_t*)&s2, &mulN, dhl);
    arrss_matmul_OO_to((const arrss_t*)&s1, (const arrss_t*)&s2, &mmN, dhl);

    omp_set_num_threads(max_threads);

    mul1_o = arrss_to_arrso(&mul1, dhl);
    mulN_o = arrss_to_arrso(&mulN, dhl);
    mm1_o  = arrss_to_arrso(&mm1, dhl);
    mmN_o  = arrss_to_arrso(&mmN, dhl);

    compare_arrso_exhaustive("mul_OO 20x20, 1 vs N threads", &mul1_o, &mulN_o, dhl);
    compare_arrso_exhaustive("matmul_OO 20x20, 1 vs N threads", &mm1_o, &mmN_o, dhl);

    arrso_free(&a1);
    arrso_free(&a2);
    arrss_free(&s1);
    arrss_free(&s2);
    arrss_free(&mul1);
    arrss_free(&mulN);
    arrss_free(&mm1);
    arrss_free(&mmN);
    arrso_free(&mul1_o);
    arrso_free(&mulN_o);
    arrso_free(&mm1_o);
    arrso_free(&mmN_o);
#else
    (void)dhl;
    printf("skipped: 1 vs N threads (not built with OpenMP)\n");
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    srand(20260928u);
    dhelp_load(NULL, &dhl);

    test_roundtrip(dhl);
    test_elementwise(dhl);
    test_functions(dhl);
    test_truncation_compact(dhl);
    test_matmul(dhl);
    test_transpose(dhl);
    test_aliasing(dhl);
    test_soa_roundtrip(dhl);
    test_linalg(dhl);
    test_threads(dhl);

    printf("\n%llu numeric checks, %d failure(s).\n", (unsigned long long)n_checks, n_failed);

    if (n_failed != 0){
        return 1;
    }

    printf("All semi-sparse AoS array checks passed.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
