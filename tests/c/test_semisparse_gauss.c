/* Semi-sparse Gauss arrays: test feoarrss_t against per-point oarrss_t operations and arrso_t. */
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <oti/oti.h>
#include <oti/semisparse.h>

#define MAX_ORDER 4
#define GLOBAL_BASES 5
#define N_SCENARIOS 3

static int n_failed = 0;
static uint64_t rng_state = 0xD37A20260928ULL;

static const bases_t SET_A[2] = {1, 2};
static const bases_t SET_B[4] = {1, 2, 3, 4};
static const bases_t SET_C[2] = {1, 3};
static const bases_t SET_D[2] = {2, 4};
static const uint64_t NIPS[3] = {1, 3, 8};

typedef struct {
    const bases_t* bases_a;
    bases_t k_a;
    const bases_t* bases_b;
    bases_t k_b;
    const char* label;
} scenario_t;

static const scenario_t SCENARIOS[N_SCENARIOS] = {
    {SET_A, 2, SET_A, 2, "same"},
    {SET_A, 2, SET_B, 4, "leading"},
    {SET_C, 2, SET_D, 2, "interleaved"},
};


// *******************************************************************************************************
static void check(int condition, const char* label){

    if (!condition){
        fprintf(stderr, "FAILED: %s\n", label);
        n_failed++;
    } else {
        printf("passed: %s\n", label);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int approx_equal(coeff_t a, coeff_t b, double tol){

    double scale = fmax(1.0, fmax(fabs(a), fabs(b)));

    return fabs(a - b) <= tol * scale;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static uint64_t rng_next(void){

    uint64_t value = rng_state;

    value ^= value << 13;
    value ^= value >> 7;
    value ^= value << 17;
    rng_state = value;

    return value;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double rng_uniform(void){

    return (double)(rng_next() >> 11) / (double)(1ULL << 53);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double rng_range(double low, double high){

    return low + (high - low) * rng_uniform();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static sotinum_t build_soti_elem(const bases_t* bases, bases_t k, ord_t order, coeff_t real,
                                 dhelpl_t dhl){

    sotinum_t value = soti_createEmpty(order, dhl);
    bases_t i;
    ord_t p;

    soti_set_item(real, 0, 0, &value, dhl);

    for (i = 0; i < k; i++){

        soti_set_item(rng_range(-0.12, 0.12), (imdir_t)(bases[i] - 1), 1, &value, dhl);

    }

    for (p = 2; p <= order; p++){

        bases_t local[MAX_ORDER] = {0, 0, 0, 0};
        ndir_t count = sshelp_ndir_order(k, p), d;

        for (d = 0; d < count; d++){

            bases_t global[MAX_ORDER];
            ord_t q;
            imdir_t index;

            for (q = 0; q < p; q++){
                global[q] = bases[local[q]];
            }

            index = sshelp_global_rank(global, p);
            soti_set_item(rng_range(-0.04, 0.04), index, p, &value, dhl);
            sshelp_next_dir(local, p, k);

        }

    }

    return value;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static arrso_t build_arrso_operand(uint64_t nrows, uint64_t ncols, const bases_t* bases, bases_t k,
                                   ord_t order, double real_shift, dhelpl_t dhl){

    arrso_t array = arrso_zeros_bases(nrows, ncols, 0, order, dhl);
    uint64_t e;

    for (e = 0; e < array.size; e++){

        sotinum_t value = build_soti_elem(bases, k, order,
            real_shift + rng_range(0.7, 1.3), dhl);

        soti_copy_to(&value, &array.p_data[e], dhl);
        soti_free(&value);

    }

    return array;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static feoarrss_t build_fe_operand(uint64_t nrows, uint64_t ncols, const bases_t* bases, bases_t k,
                                   ord_t order, uint64_t nip, double real_shift, dhelpl_t dhl){

    feoarrss_t fe = feoarrss_zeros(bases, k, nrows, ncols, nip, order);
    uint64_t ip;

    for (ip = 0; ip < nip; ip++){

        arrso_t oracle = build_arrso_operand(nrows, ncols, bases, k, order,
            real_shift + (coeff_t)ip * 0.09, dhl);
        oarrss_t point = oarrss_from_arrso(&oracle, dhl);

        feoarrss_set_ip(&point, ip, &fe);
        oarrss_free(&point);
        arrso_free(&oracle);

    }

    return fe;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void compare_oarrss_vs_arrso(const oarrss_t* got, arrso_t* expected, dhelpl_t dhl,
                                    double tol, const char* label){

    uint64_t i, j, checked = 0, mismatches = 0;
    char message[256];

    check(got->nrows == expected->nrows && got->ncols == expected->ncols, label);

    for (i = 0; i < got->nrows; i++){

        for (j = 0; j < got->ncols; j++){

            ssotinum_t item = oarrss_get_item(i, j, got);
            sotinum_t* oracle = &expected->p_data[j + i * expected->ncols];
            ord_t p;

            checked++;

            if (!approx_equal(item.re, oracle->re, tol)){
                mismatches++;
            }

            for (p = 1; p <= MAX_ORDER; p++){

                ndir_t d, ndir = sshelp_ndir_order(GLOBAL_BASES, p);

                for (d = 0; d < ndir; d++){

                    coeff_t a = ssoti_get_item((imdir_t)d, p, &item);
                    coeff_t b = soti_get_item((imdir_t)d, p, oracle, dhl);
                    checked++;

                    if (!approx_equal(a, b, tol)){

                        if (mismatches < 4){
                            fprintf(stderr,
                                "  mismatch %s (%llu,%llu) order=%u dir=%llu: %.17g != %.17g\n",
                                label, (unsigned long long)i, (unsigned long long)j,
                                (unsigned)p, (unsigned long long)d, a, b);
                        }

                        mismatches++;

                    }

                }

            }

            ssoti_free(&item);

        }

    }

    snprintf(message, sizeof(message), "%s: %llu/%llu coefficients agree", label,
        (unsigned long long)(checked - mismatches), (unsigned long long)checked);
    check(mismatches == 0, message);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void compare_fe_point(const feoarrss_t* fe, uint64_t ip, arrso_t* expected, dhelpl_t dhl,
                             double tol, const char* label){

    oarrss_t point = oarrss_init();

    feoarrss_get_ip_to(ip, fe, &point);
    compare_oarrss_vs_arrso(&point, expected, dhl, tol, label);
    oarrss_free(&point);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void compare_ssoti_vs_soti(const ssotinum_t* got, sotinum_t* expected, dhelpl_t dhl,
                                  double tol, const char* label){

    ord_t p;
    uint64_t checked = 1, mismatches = 0;
    char message[256];

    if (!approx_equal(got->re, expected->re, tol)){

        fprintf(stderr, "  mismatch %s real: %.17g != %.17g\n", label, got->re, expected->re);
        mismatches++;

    }

    for (p = 1; p <= MAX_ORDER; p++){

        ndir_t d, ndir = sshelp_ndir_order(GLOBAL_BASES, p);

        for (d = 0; d < ndir; d++){

            coeff_t a = ssoti_get_item((imdir_t)d, p, got);
            coeff_t b = soti_get_item((imdir_t)d, p, expected, dhl);
            checked++;

            if (!approx_equal(a, b, tol)){

                if (mismatches < 5){
                    fprintf(stderr,
                        "  mismatch %s order=%u dir=%llu: %.17g != %.17g\n",
                        label, (unsigned)p, (unsigned long long)d, a, b);
                }

                mismatches++;

            }

        }

    }

    snprintf(message, sizeof(message), "%s: %llu/%llu scalar coefficients agree", label,
        (unsigned long long)(checked - mismatches), (unsigned long long)checked);
    check(mismatches == 0, message);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static feoarrss_t clone_fe(const feoarrss_t* source){

    feoarrss_t result = feoarrss_init();

    feoarrss_copy_to(source, &result);

    return result;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_memory_copy_grow(dhelpl_t dhl){

    static const bases_t add[1] = {5};
    size_t ni;
    ord_t order;

    for (order = 1; order <= MAX_ORDER; order++){

        for (ni = 0; ni < 3; ni++){

            feoarrss_t empty = feoarrss_init();
            feoarrss_t fe = build_fe_operand(2, 3, SET_A, 2, order, NIPS[ni], 0.0, dhl);
            feoarrss_t copy = feoarrss_init();
            feoarrss_t grown = feoarrss_init();
            uint64_t ip;
            char label[128];

            feoarrss_copy_to(&fe, &copy);
            check(fe.nrows == 2 && fe.ncols == 3 && fe.nip == NIPS[ni],
                "zeros/copy: Gauss shape and points");
            check(fe.arr.nrows == NIPS[ni] && fe.arr.ncols == 6,
                "zeros: embedded array shape");
            check(copy.arr.nbases == fe.arr.nbases && copy.arr.trc_order == order,
                "copy: active set and truncation order");

            for (ip = 0; ip < fe.nip; ip++){

                oarrss_t point = oarrss_init();
                arrso_t expected;

                feoarrss_get_ip_to(ip, &fe, &point);
                expected = oarrss_to_arrso(&point, dhl);
                snprintf(label, sizeof(label), "copy/get_ip order=%u nip=%llu ip=%llu",
                    (unsigned)order, (unsigned long long)fe.nip, (unsigned long long)ip);
                compare_fe_point(&copy, ip, &expected, dhl, 1e-13, label);
                oarrss_free(&point);
                arrso_free(&expected);

            }

            feoarrss_copy_to(&fe, &grown);
            feoarrss_grow(add, 1, MAX_ORDER, &grown);
            check(grown.arr.nbases == 3 && grown.arr.p_bases[2] == 5,
                "grow: sorted active-base union");
            check(grown.arr.trc_order == MAX_ORDER, "grow: order raises and zero extends");

            for (ip = 0; ip < fe.nip; ip++){

                oarrss_t point = oarrss_init();
                arrso_t expected;

                feoarrss_get_ip_to(ip, &fe, &point);
                expected = oarrss_to_arrso(&point, dhl);
                snprintf(label, sizeof(label), "grow preserves point %llu",
                    (unsigned long long)ip);
                compare_fe_point(&grown, ip, &expected, dhl, 1e-13, label);
                oarrss_free(&point);
                arrso_free(&expected);

            }

            feoarrss_free(&empty);
            feoarrss_free(&fe);
            feoarrss_free(&copy);
            feoarrss_free(&grown);

            check(empty.nip == 0 && empty.nrows == 0 && empty.ncols == 0,
                "free resets Gauss structure");

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_set_shape_from_oarrss_and_bcast(dhelpl_t dhl){

    uint64_t ip;
    arrso_t source = build_arrso_operand(2, 3, SET_C, 2, 3, 0.0, dhl);
    oarrss_t plain = oarrss_from_arrso(&source, dhl);
    feoarrss_t repeated = feoarrss_init();
    feoarrss_t scalar_fe = feoarrss_init();
    feoarrss_t broadcast = feoarrss_init();
    arrso_t scalar_source = build_arrso_operand(1, 1, SET_D, 2, 3, 0.4, dhl);
    oarrss_t scalar_plain = oarrss_from_arrso(&scalar_source, dhl);
    arrso_t scalar_value = oarrss_to_arrso(&scalar_plain, dhl);
    arrso_t broadcast_oracle = arrso_zeros_bases(2, 3, 0, 3, dhl);
    uint64_t e;

    feoarrss_from_oarrss_to(&plain, 3, &repeated);
    check(repeated.nrows == 2 && repeated.ncols == 3 && repeated.nip == 3,
        "from_oarrss_to sets metadata");

    for (ip = 0; ip < repeated.nip; ip++){

        char label[96];

        snprintf(label, sizeof(label), "from_oarrss point %llu", (unsigned long long)ip);
        compare_fe_point(&repeated, ip, &source, dhl, 1e-13, label);

    }

    feoarrss_from_oarrss_to(&scalar_plain, 3, &scalar_fe);
    feoarrss_bcast_to(&scalar_fe, 2, 3, &broadcast);
    feoarrss_set_shape(2, 3, 3, &broadcast);
    check(broadcast.nrows == 2 && broadcast.ncols == 3 && broadcast.nip == 3,
        "set_shape: labels embedded broadcast array");

    for (e = 0; e < broadcast_oracle.size; e++){
        soti_copy_to(&scalar_value.p_data[0], &broadcast_oracle.p_data[e], dhl);
    }

    for (ip = 0; ip < broadcast.nip; ip++){

        char label[96];

        snprintf(label, sizeof(label), "bcast scalar point %llu", (unsigned long long)ip);
        compare_fe_point(&broadcast, ip, &broadcast_oracle, dhl, 1e-13, label);

    }

    feoarrss_free(&repeated);
    feoarrss_free(&scalar_fe);
    feoarrss_free(&broadcast);
    oarrss_free(&plain);
    oarrss_free(&scalar_plain);
    arrso_free(&source);
    arrso_free(&scalar_source);
    arrso_free(&scalar_value);
    arrso_free(&broadcast_oracle);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static oarrss_t expected_slice(const oarrss_t* source, uint64_t i0, uint64_t ni, int64_t istep,
                               uint64_t j0, uint64_t nj, int64_t jstep){

    oarrss_t result = oarrss_zeros(source->p_bases, source->nbases, ni, nj,
        source->trc_order);
    uint64_t i, j;

    for (j = 0; j < nj; j++){

        for (i = 0; i < ni; i++){

            uint64_t row = (uint64_t)((int64_t)i0 + (int64_t)i * istep);
            uint64_t col = (uint64_t)((int64_t)j0 + (int64_t)j * jstep);
            ssotinum_t value = oarrss_get_item(row, col, source);

            oarrss_set_item(&value, i, j, &result);
            ssoti_free(&value);

        }

    }

    return result;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void apply_expected_slice(const oarrss_t* values, uint64_t i0, uint64_t ni, int64_t istep,
                                 uint64_t j0, uint64_t nj, int64_t jstep, oarrss_t* target){

    uint64_t i, j;
    int broadcast = values->nrows == 1 && values->ncols == 1;

    for (j = 0; j < nj; j++){

        for (i = 0; i < ni; i++){

            uint64_t row = (uint64_t)((int64_t)i0 + (int64_t)i * istep);
            uint64_t col = (uint64_t)((int64_t)j0 + (int64_t)j * jstep);
            ssotinum_t value = oarrss_get_item(broadcast ? 0 : i, broadcast ? 0 : j, values);

            oarrss_set_item(&value, row, col, target);
            ssoti_free(&value);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_slices(dhelpl_t dhl){

    size_t si;
    ord_t order;

    for (order = 1; order <= MAX_ORDER; order++){

        for (si = 0; si < 3; si++){

            const scenario_t* sc = &SCENARIOS[si];
            uint64_t nip = NIPS[si];
            feoarrss_t source = build_fe_operand(3, 4, sc->bases_a, sc->k_a, order, nip, 0.0, dhl);
            feoarrss_t value = build_fe_operand(2, 2, sc->bases_b, sc->k_b, order, nip, 0.25, dhl);
            feoarrss_t scalar = build_fe_operand(1, 1, sc->bases_b, sc->k_b,
                order, nip, 0.45, dhl);
            feoarrss_t got = feoarrss_init();
            uint64_t ip;

            feoarrss_get_slice_to(&source, 0, 2, 1, 1, 2, 2, &got);

            for (ip = 0; ip < nip; ip++){

                oarrss_t src = oarrss_init();
                oarrss_t expected;
                arrso_t oracle;
                char label[128];

                feoarrss_get_ip_to(ip, &source, &src);
                expected = expected_slice(&src, 0, 2, 1, 1, 2, 2);
                oracle = oarrss_to_arrso(&expected, dhl);
                snprintf(label, sizeof(label), "get_slice positive order=%u ip=%llu",
                    (unsigned)order, (unsigned long long)ip);
                compare_fe_point(&got, ip, &oracle, dhl, 1e-13, label);
                oarrss_free(&src);
                oarrss_free(&expected);
                arrso_free(&oracle);

            }

            feoarrss_free(&got);
            got = feoarrss_init();
            feoarrss_get_slice_to(&source, 2, 2, -2, 3, 2, -2, &got);

            for (ip = 0; ip < nip; ip++){

                oarrss_t src = oarrss_init();
                oarrss_t expected;
                arrso_t oracle;
                char label[128];

                feoarrss_get_ip_to(ip, &source, &src);
                expected = expected_slice(&src, 2, 2, -2, 3, 2, -2);
                oracle = oarrss_to_arrso(&expected, dhl);
                snprintf(label, sizeof(label), "get_slice negative order=%u ip=%llu",
                    (unsigned)order, (unsigned long long)ip);
                compare_fe_point(&got, ip, &oracle, dhl, 1e-13, label);
                oarrss_free(&src);
                oarrss_free(&expected);
                arrso_free(&oracle);

            }

            feoarrss_free(&got);
            got = clone_fe(&source);
            feoarrss_set_slice(&value, 0, 2, 1, 0, 2, 2, &got);

            for (ip = 0; ip < nip; ip++){

                oarrss_t dst = oarrss_init(), val = oarrss_init();
                arrso_t oracle;
                char label[128];

                feoarrss_get_ip_to(ip, &source, &dst);
                feoarrss_get_ip_to(ip, &value, &val);
                apply_expected_slice(&val, 0, 2, 1, 0, 2, 2, &dst);
                oracle = oarrss_to_arrso(&dst, dhl);
                snprintf(label, sizeof(label), "set_slice positive order=%u ip=%llu",
                    (unsigned)order, (unsigned long long)ip);
                compare_fe_point(&got, ip, &oracle, dhl, 1e-13, label);
                oarrss_free(&dst);
                oarrss_free(&val);
                arrso_free(&oracle);

            }

            feoarrss_free(&got);
            got = clone_fe(&source);
            feoarrss_set_slice(&value, 2, 2, -2, 3, 2, -2, &got);

            for (ip = 0; ip < nip; ip++){

                oarrss_t dst = oarrss_init(), val = oarrss_init();
                arrso_t oracle;
                char label[128];

                feoarrss_get_ip_to(ip, &source, &dst);
                feoarrss_get_ip_to(ip, &value, &val);
                apply_expected_slice(&val, 2, 2, -2, 3, 2, -2, &dst);
                oracle = oarrss_to_arrso(&dst, dhl);
                snprintf(label, sizeof(label), "set_slice negative order=%u ip=%llu",
                    (unsigned)order, (unsigned long long)ip);
                compare_fe_point(&got, ip, &oracle, dhl, 1e-13, label);
                oarrss_free(&dst);
                oarrss_free(&val);
                arrso_free(&oracle);

            }

            feoarrss_free(&got);
            got = clone_fe(&source);
            feoarrss_set_slice(&scalar, 0, 3, 1, 0, 4, 1, &got);
            check(got.arr.trc_order == order, "set_slice broadcast keeps the current order");

            for (ip = 0; ip < nip; ip++){

                oarrss_t dst = oarrss_init(), val = oarrss_init();
                arrso_t oracle;
                char label[128];

                feoarrss_get_ip_to(ip, &source, &dst);
                feoarrss_get_ip_to(ip, &scalar, &val);
                apply_expected_slice(&val, 0, 3, 1, 0, 4, 1, &dst);
                oracle = oarrss_to_arrso(&dst, dhl);
                snprintf(label, sizeof(label), "set_slice 1x1 broadcast order=%u ip=%llu",
                    (unsigned)order, (unsigned long long)ip);
                compare_fe_point(&got, ip, &oracle, dhl, 1e-13, label);
                oarrss_free(&dst);
                oarrss_free(&val);
                arrso_free(&oracle);

            }

            feoarrss_free(&source);
            feoarrss_free(&value);
            feoarrss_free(&scalar);
            feoarrss_free(&got);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_set_ip_and_set_ijk(dhelpl_t dhl){

    static const bases_t replace_bases[2] = {3, 5};
    static const bases_t set_bases[2] = {2, 5};
    feoarrss_t fe = build_fe_operand(2, 2, SET_A, 2, 1, 3, 0.0, dhl);
    arrso_t replacement_sparse = build_arrso_operand(2, 2, replace_bases, 2, 4, 0.35, dhl);
    oarrss_t replacement = oarrss_from_arrso(&replacement_sparse, dhl);
    arrso_t oracle_points[3];
    oarrss_t before_points[3];
    uint64_t ip;

    for (ip = 0; ip < 3; ip++){

        before_points[ip] = oarrss_init();
        feoarrss_get_ip_to(ip, &fe, &before_points[ip]);
        oracle_points[ip] = oarrss_to_arrso(&before_points[ip], dhl);

    }

    feoarrss_set_ip(&replacement, 1, &fe);
    check(fe.arr.nbases == 4 && fe.arr.p_bases[0] == 1 && fe.arr.p_bases[1] == 2 &&
        fe.arr.p_bases[2] == 3 && fe.arr.p_bases[3] == 5, "set_ip grows active-set union");
    check(fe.arr.trc_order == 4, "set_ip raises truncation order");
    arrso_free(&oracle_points[1]);
    oracle_points[1] = oarrss_to_arrso(&replacement, dhl);

    for (ip = 0; ip < 3; ip++){

        char label[80];

        snprintf(label, sizeof(label), "set_ip preserves point %llu", (unsigned long long)ip);
        compare_fe_point(&fe, ip, &oracle_points[ip], dhl, 1e-13, label);
        oarrss_free(&before_points[ip]);
        arrso_free(&oracle_points[ip]);

    }

    {
        feoarrss_t set_fe = build_fe_operand(2, 2, SET_A, 2, 1, 3, 0.1, dhl);
        arrso_t set_oracle[3];
        ssotinum_t number = ssoti_create_empty(set_bases, 2, 4);
        sotinum_t sparse_number;
        bases_t tuple[4] = {2, 5, 5, 5};
        imdir_t direction = sshelp_global_rank(tuple, 4);

        for (ip = 0; ip < 3; ip++){

            oarrss_t point = oarrss_init();

            feoarrss_get_ip_to(ip, &set_fe, &point);
            set_oracle[ip] = oarrss_to_arrso(&point, dhl);
            oarrss_free(&point);

        }

        number.re = 3.75;
        ssoti_set_item(0.125, direction, 4, &number);
        sparse_number = ssoti_to_soti(&number, dhl);
        feoarrss_set_ijk_o(&number, 1, 0, 2, &set_fe);
        soti_copy_to(&sparse_number, &set_oracle[2].p_data[2], dhl);

        feoarrss_set_ijk_r(-2.5, 0, 1, 0, &set_fe);
        {
            sotinum_t real_value = soti_init();

            real_value.re = -2.5;
            soti_copy_to(&real_value, &set_oracle[0].p_data[1], dhl);
            soti_free(&real_value);
        }

        check(set_fe.arr.nbases == 3 && set_fe.arr.p_bases[0] == 1 &&
            set_fe.arr.p_bases[1] == 2 && set_fe.arr.p_bases[2] == 5,
            "set_ijk grows sorted bases");
        check(set_fe.arr.trc_order == 4, "set_ijk raises order");

        for (ip = 0; ip < 3; ip++){

            char label[80];

            snprintf(label, sizeof(label), "set_ijk oracle point %llu", (unsigned long long)ip);
            compare_fe_point(&set_fe, ip, &set_oracle[ip], dhl, 1e-13, label);
            arrso_free(&set_oracle[ip]);

        }

        ssoti_free(&number);
        soti_free(&sparse_number);
        feoarrss_free(&set_fe);

    }

    feoarrss_free(&fe);
    oarrss_free(&replacement);
    arrso_free(&replacement_sparse);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void verify_transpose(const feoarrss_t* input, const feoarrss_t* output, dhelpl_t dhl,
                             const char* label){

    uint64_t ip;

    for (ip = 0; ip < input->nip; ip++){

        oarrss_t a = oarrss_init(), got = oarrss_init(), expected = oarrss_init();
        arrso_t sparse_a, sparse_expected;

        feoarrss_get_ip_to(ip, input, &a);
        feoarrss_get_ip_to(ip, output, &got);
        oarrss_transpose_to(&a, &expected, dhl);
        sparse_a = oarrss_to_arrso(&a, dhl);
        sparse_expected = arrso_transpose(&sparse_a, dhl);
        compare_oarrss_vs_arrso(&expected, &sparse_expected, dhl, 1e-13, label);
        compare_oarrss_vs_arrso(&got, &sparse_expected, dhl, 1e-13, label);
        oarrss_free(&a);
        oarrss_free(&got);
        oarrss_free(&expected);
        arrso_free(&sparse_a);
        arrso_free(&sparse_expected);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_transpose(dhelpl_t dhl){

    size_t si, ni;
    ord_t order;

    for (si = 0; si < N_SCENARIOS; si++){

        for (order = 1; order <= MAX_ORDER; order++){

            for (ni = 0; ni < 3; ni++){

                feoarrss_t input = build_fe_operand(2, 3, SCENARIOS[si].bases_a,
                    SCENARIOS[si].k_a, order, NIPS[ni], 0.0, dhl);
                feoarrss_t result = feoarrss_init();
                feoarrss_t alias = clone_fe(&input);

                feoarrss_transpose_to(&input, &result);
                check(result.nrows == 3 && result.ncols == 2,
                    "transpose swaps matrix dimensions");
                verify_transpose(&input, &result, dhl, "transpose per-point oracle");
                feoarrss_transpose_to(&alias, &alias);
                check(alias.nrows == 3 && alias.ncols == 2, "transpose allows aliased result");
                verify_transpose(&input, &alias, dhl, "aliased transpose per-point oracle");

                feoarrss_free(&input);
                feoarrss_free(&result);
                feoarrss_free(&alias);

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void verify_matmul_FF(const feoarrss_t* a, const feoarrss_t* b, const feoarrss_t* result,
                             dhelpl_t dhl, const char* label){

    uint64_t ip;

    for (ip = 0; ip < a->nip; ip++){

        oarrss_t aa = oarrss_init(), bb = oarrss_init(), got = oarrss_init();
        oarrss_t point_result = oarrss_init();
        arrso_t sparse_a, sparse_b, sparse_result;
        int status;

        feoarrss_get_ip_to(ip, a, &aa);
        feoarrss_get_ip_to(ip, b, &bb);
        feoarrss_get_ip_to(ip, result, &got);
        status = oarrss_matmul_OO_to(&aa, &bb, &point_result, dhl);
        check(status == 0, "per-point oarrss matmul FF succeeds");
        sparse_a = oarrss_to_arrso(&aa, dhl);
        sparse_b = oarrss_to_arrso(&bb, dhl);
        sparse_result = arrso_matmul_OO(&sparse_a, &sparse_b, dhl);
        compare_oarrss_vs_arrso(&point_result, &sparse_result, dhl, 1e-13, label);
        compare_oarrss_vs_arrso(&got, &sparse_result, dhl, 1e-13, label);
        oarrss_free(&aa);
        oarrss_free(&bb);
        oarrss_free(&got);
        oarrss_free(&point_result);
        arrso_free(&sparse_a);
        arrso_free(&sparse_b);
        arrso_free(&sparse_result);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void verify_matmul_FO(const feoarrss_t* a, const oarrss_t* b, const feoarrss_t* result,
                             dhelpl_t dhl, const char* label){

    uint64_t ip;

    for (ip = 0; ip < a->nip; ip++){

        oarrss_t aa = oarrss_init(), got = oarrss_init(), point_result = oarrss_init();
        arrso_t sparse_a, sparse_b, sparse_result;
        int status;

        feoarrss_get_ip_to(ip, a, &aa);
        feoarrss_get_ip_to(ip, result, &got);
        status = oarrss_matmul_OO_to(&aa, b, &point_result, dhl);
        check(status == 0, "per-point oarrss matmul FO succeeds");
        sparse_a = oarrss_to_arrso(&aa, dhl);
        sparse_b = oarrss_to_arrso(b, dhl);
        sparse_result = arrso_matmul_OO(&sparse_a, &sparse_b, dhl);
        compare_oarrss_vs_arrso(&point_result, &sparse_result, dhl, 1e-13, label);
        compare_oarrss_vs_arrso(&got, &sparse_result, dhl, 1e-13, label);
        oarrss_free(&aa);
        oarrss_free(&got);
        oarrss_free(&point_result);
        arrso_free(&sparse_a);
        arrso_free(&sparse_b);
        arrso_free(&sparse_result);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void verify_matmul_OF(const oarrss_t* a, const feoarrss_t* b, const feoarrss_t* result,
                             dhelpl_t dhl, const char* label){

    uint64_t ip;

    for (ip = 0; ip < b->nip; ip++){

        oarrss_t bb = oarrss_init(), got = oarrss_init(), point_result = oarrss_init();
        arrso_t sparse_a, sparse_b, sparse_result;
        int status;

        feoarrss_get_ip_to(ip, b, &bb);
        feoarrss_get_ip_to(ip, result, &got);
        status = oarrss_matmul_OO_to(a, &bb, &point_result, dhl);
        check(status == 0, "per-point oarrss matmul OF succeeds");
        sparse_a = oarrss_to_arrso(a, dhl);
        sparse_b = oarrss_to_arrso(&bb, dhl);
        sparse_result = arrso_matmul_OO(&sparse_a, &sparse_b, dhl);
        compare_oarrss_vs_arrso(&point_result, &sparse_result, dhl, 1e-13, label);
        compare_oarrss_vs_arrso(&got, &sparse_result, dhl, 1e-13, label);
        oarrss_free(&bb);
        oarrss_free(&got);
        oarrss_free(&point_result);
        arrso_free(&sparse_a);
        arrso_free(&sparse_b);
        arrso_free(&sparse_result);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_matmul(dhelpl_t dhl){

    size_t si, ni;
    ord_t order;

    for (si = 0; si < N_SCENARIOS; si++){

        for (order = 1; order <= MAX_ORDER; order++){

            for (ni = 0; ni < 3; ni++){

                const scenario_t* sc = &SCENARIOS[si];
                uint64_t nip = NIPS[ni];
                feoarrss_t a = build_fe_operand(2, 3, sc->bases_a, sc->k_a, order,
                    nip, 0.0, dhl);
                feoarrss_t b = build_fe_operand(3, 2, sc->bases_b, sc->k_b, order,
                    nip, 0.1, dhl);
                arrso_t plain_a_sparse = build_arrso_operand(2, 3, sc->bases_a, sc->k_a,
                    order, 0.2, dhl);
                arrso_t plain_b_sparse = build_arrso_operand(3, 2, sc->bases_b, sc->k_b,
                    order, 0.3, dhl);
                oarrss_t plain_a = oarrss_from_arrso(&plain_a_sparse, dhl);
                oarrss_t plain_b = oarrss_from_arrso(&plain_b_sparse, dhl);
                feoarrss_t out_ff = feoarrss_init(), out_fo = feoarrss_init();
                feoarrss_t out_of = feoarrss_init();
                char label[128];
                int status;

                snprintf(label, sizeof(label), "matmul FF %s order=%u nip=%llu", sc->label,
                    (unsigned)order, (unsigned long long)nip);
                status = feoarrss_matmul_FF_to(&a, &b, &out_ff, dhl);
                check(status == 0, "matmul FF status 0");
                verify_matmul_FF(&a, &b, &out_ff, dhl, label);

                snprintf(label, sizeof(label), "matmul FO %s order=%u nip=%llu", sc->label,
                    (unsigned)order, (unsigned long long)nip);
                status = feoarrss_matmul_FO_to(&a, &plain_b, &out_fo, dhl);
                check(status == 0, "matmul FO status 0");
                verify_matmul_FO(&a, &plain_b, &out_fo, dhl, label);

                snprintf(label, sizeof(label), "matmul OF %s order=%u nip=%llu", sc->label,
                    (unsigned)order, (unsigned long long)nip);
                status = feoarrss_matmul_OF_to(&plain_a, &b, &out_of, dhl);
                check(status == 0, "matmul OF status 0");
                verify_matmul_OF(&plain_a, &b, &out_of, dhl, label);

                {
                    feoarrss_t alias_a = clone_fe(&a);

                    check(feoarrss_matmul_FF_to(&alias_a, &b, &alias_a, dhl) == 0,
                        "matmul FF alias result with left operand");
                    verify_matmul_FF(&a, &b, &alias_a, dhl, "matmul FF result aliases left");
                    feoarrss_free(&alias_a);
                }

                {
                    feoarrss_t alias_b = clone_fe(&b);

                    check(feoarrss_matmul_FF_to(&a, &alias_b, &alias_b, dhl) == 0,
                        "matmul FF alias result with right operand");
                    verify_matmul_FF(&a, &b, &alias_b, dhl, "matmul FF result aliases right");
                    feoarrss_free(&alias_b);
                }

                {
                    feoarrss_t alias_a = clone_fe(&a);

                    check(feoarrss_matmul_FO_to(&alias_a, &plain_b, &alias_a, dhl) == 0,
                        "matmul FO alias result with Gauss operand");
                    verify_matmul_FO(&a, &plain_b, &alias_a, dhl, "matmul FO result aliases input");
                    feoarrss_free(&alias_a);
                }

                {
                    feoarrss_t alias_b = clone_fe(&b);

                    check(feoarrss_matmul_OF_to(&plain_a, &alias_b, &alias_b, dhl) == 0,
                        "matmul OF alias result with Gauss operand");
                    verify_matmul_OF(&plain_a, &b, &alias_b, dhl, "matmul OF result aliases input");
                    feoarrss_free(&alias_b);
                }

                feoarrss_free(&a);
                feoarrss_free(&b);
                feoarrss_free(&out_ff);
                feoarrss_free(&out_fo);
                feoarrss_free(&out_of);
                oarrss_free(&plain_a);
                oarrss_free(&plain_b);
                arrso_free(&plain_a_sparse);
                arrso_free(&plain_b_sparse);

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void compare_fe_scalar_point(const feoarrss_t* fe, uint64_t ip, sotinum_t* expected,
                                    dhelpl_t dhl, double tol, const char* label){

    oarrss_t point = oarrss_init();
    ssotinum_t scalar;

    feoarrss_get_ip_to(ip, fe, &point);
    scalar = oarrss_get_item(0, 0, &point);
    compare_ssoti_vs_soti(&scalar, expected, dhl, tol, label);
    ssoti_free(&scalar);
    oarrss_free(&point);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void verify_dot_FO(const feoarrss_t* a, const oarrss_t* b, const feoarrss_t* result,
                          dhelpl_t dhl, const char* label){

    uint64_t ip;

    for (ip = 0; ip < a->nip; ip++){

        oarrss_t aa = oarrss_init();
        ssotinum_t point_result = ssoti_init();
        arrso_t sparse_a, sparse_b;
        sotinum_t sparse_result = soti_init();
        int status;

        feoarrss_get_ip_to(ip, a, &aa);
        status = oarrss_dot_product_OO_to(&aa, b, &point_result, dhl);
        check(status == 0, "per-point oarrss dot FO succeeds");
        sparse_a = oarrss_to_arrso(&aa, dhl);
        sparse_b = oarrss_to_arrso(b, dhl);
        arrso_dotproduct_OO_to(&sparse_a, &sparse_b, &sparse_result, dhl);
        compare_ssoti_vs_soti(&point_result, &sparse_result, dhl, 1e-13, label);
        compare_fe_scalar_point(result, ip, &sparse_result, dhl, 1e-13, label);
        oarrss_free(&aa);
        ssoti_free(&point_result);
        arrso_free(&sparse_a);
        arrso_free(&sparse_b);
        soti_free(&sparse_result);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void verify_dot_FF(const feoarrss_t* a, const feoarrss_t* b, const feoarrss_t* result,
                          dhelpl_t dhl, const char* label){

    uint64_t ip;

    for (ip = 0; ip < a->nip; ip++){

        oarrss_t aa = oarrss_init(), bb = oarrss_init();
        ssotinum_t point_result = ssoti_init();
        arrso_t sparse_a, sparse_b;
        sotinum_t sparse_result = soti_init();
        int status;

        feoarrss_get_ip_to(ip, a, &aa);
        feoarrss_get_ip_to(ip, b, &bb);
        status = oarrss_dot_product_OO_to(&aa, &bb, &point_result, dhl);
        check(status == 0, "per-point oarrss dot FF succeeds");
        sparse_a = oarrss_to_arrso(&aa, dhl);
        sparse_b = oarrss_to_arrso(&bb, dhl);
        arrso_dotproduct_OO_to(&sparse_a, &sparse_b, &sparse_result, dhl);
        compare_ssoti_vs_soti(&point_result, &sparse_result, dhl, 1e-13, label);
        compare_fe_scalar_point(result, ip, &sparse_result, dhl, 1e-13, label);
        oarrss_free(&aa);
        oarrss_free(&bb);
        ssoti_free(&point_result);
        arrso_free(&sparse_a);
        arrso_free(&sparse_b);
        soti_free(&sparse_result);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_dot_products(dhelpl_t dhl){

    size_t si, ni;
    ord_t order;

    for (si = 0; si < N_SCENARIOS; si++){

        for (order = 1; order <= MAX_ORDER; order++){

            for (ni = 0; ni < 3; ni++){

                const scenario_t* sc = &SCENARIOS[si];
                uint64_t nip = NIPS[ni];
                feoarrss_t a = build_fe_operand(2, 3, sc->bases_a, sc->k_a, order,
                    nip, 0.0, dhl);
                feoarrss_t b = build_fe_operand(2, 3, sc->bases_b, sc->k_b, order,
                    nip, 0.1, dhl);
                arrso_t plain_b_sparse = build_arrso_operand(2, 3, sc->bases_b, sc->k_b,
                    order, 0.2, dhl);
                oarrss_t plain_b = oarrss_from_arrso(&plain_b_sparse, dhl);
                feoarrss_t result_fo = feoarrss_init(), result_ff = feoarrss_init();
                char label[128];

                snprintf(label, sizeof(label), "dot FO %s order=%u nip=%llu", sc->label,
                    (unsigned)order, (unsigned long long)nip);
                check(feoarrss_dot_product_FO_to(&a, &plain_b, &result_fo, dhl) == 0,
                    "dot FO status 0");
                verify_dot_FO(&a, &plain_b, &result_fo, dhl, label);

                snprintf(label, sizeof(label), "dot FF %s order=%u nip=%llu", sc->label,
                    (unsigned)order, (unsigned long long)nip);
                check(feoarrss_dot_product_FF_to(&a, &b, &result_ff, dhl) == 0,
                    "dot FF status 0");
                verify_dot_FF(&a, &b, &result_ff, dhl, label);

                {
                    feoarrss_t alias = clone_fe(&a);

                    check(feoarrss_dot_product_FO_to(&alias, &plain_b, &alias, dhl) == 0,
                        "dot FO permits result aliasing Gauss input");
                    verify_dot_FO(&a, &plain_b, &alias, dhl, "dot FO aliased result");
                    feoarrss_free(&alias);
                }

                {
                    feoarrss_t alias_a = clone_fe(&a);

                    check(feoarrss_dot_product_FF_to(&alias_a, &b, &alias_a, dhl) == 0,
                        "dot FF permits result aliasing left input");
                    verify_dot_FF(&a, &b, &alias_a, dhl, "dot FF aliases left");
                    feoarrss_free(&alias_a);
                }

                {
                    feoarrss_t alias_b = clone_fe(&b);

                    check(feoarrss_dot_product_FF_to(&a, &alias_b, &alias_b, dhl) == 0,
                        "dot FF permits result aliasing right input");
                    verify_dot_FF(&a, &b, &alias_b, dhl, "dot FF aliases right");
                    feoarrss_free(&alias_b);
                }

                feoarrss_free(&a);
                feoarrss_free(&b);
                feoarrss_free(&result_fo);
                feoarrss_free(&result_ff);
                oarrss_free(&plain_b);
                arrso_free(&plain_b_sparse);

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static feoarrss_t build_gauss_matrix(uint64_t n, const bases_t* bases, bases_t k, ord_t order,
                                    uint64_t nip, dhelpl_t dhl){

    feoarrss_t fe = feoarrss_zeros(bases, k, n, n, nip, order);
    uint64_t ip, i;

    for (ip = 0; ip < nip; ip++){

        arrso_t sparse = build_arrso_operand(n, n, bases, k, order, 0.0, dhl);
        oarrss_t point;

        for (i = 0; i < n; i++){
            sparse.p_data[i * n + i].re += (coeff_t)n + 4.0;
        }

        point = oarrss_from_arrso(&sparse, dhl);
        feoarrss_set_ip(&point, ip, &fe);
        oarrss_free(&point);
        arrso_free(&sparse);

    }

    return fe;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_det_inv(dhelpl_t dhl){

    size_t si, ni;
    ord_t order;
    uint64_t n;

    for (si = 0; si < N_SCENARIOS; si++){

        for (order = 1; order <= MAX_ORDER; order++){

            for (ni = 0; ni < 3; ni++){

                for (n = 1; n <= 5; n++){

                    const scenario_t* sc = &SCENARIOS[si];
                    uint64_t nip = NIPS[ni], ip;
                    feoarrss_t matrix = build_gauss_matrix(n, sc->bases_a, sc->k_a,
                        order, nip, dhl);
                    feoarrss_t det = feoarrss_init(), inv = feoarrss_init();
                    char label[128];
                    int det_status, inv_status;

                    snprintf(label, sizeof(label), "det/inv n=%llu %s order=%u nip=%llu",
                        (unsigned long long)n, sc->label, (unsigned)order,
                        (unsigned long long)nip);
                    det_status = feoarrss_det_to(&matrix, &det, dhl);
                    inv_status = feoarrss_inv_to(&matrix, &inv, dhl);
                    check(det_status == 0, "det status success");
                    check(inv_status == 0, "inv status success");
                    check(det.nrows == 1 && det.ncols == 1 && det.nip == nip,
                        "det output is Gauss scalar");

                    for (ip = 0; ip < nip; ip++){

                        oarrss_t point = oarrss_init();
                        ssotinum_t plain_det = ssoti_init();
                        oarrss_t plain_inv = oarrss_init();
                        arrso_t sparse_point, sparse_inv;
                        sotinum_t sparse_det = soti_init();
                        int point_det_status, point_inv_status;
                        char point_label[192];

                        feoarrss_get_ip_to(ip, &matrix, &point);
                        point_det_status = oarrss_det_to(&point, &plain_det, dhl);
                        point_inv_status = oarrss_inv_to(&point, &plain_inv, dhl);
                        sparse_point = oarrss_to_arrso(&point, dhl);
                        sparse_inv = arrso_zeros_bases(n, n, 0, order, dhl);
                        snprintf(point_label, sizeof(point_label),
                            "%s point=%llu", label, (unsigned long long)ip);
                        check(arrso_det_to(&sparse_point, &sparse_det, dhl) == 0,
                            "arrso determinant oracle status");
                        check(arrso_invert_to(&sparse_point, &sparse_inv, dhl) == 0,
                            "arrso inverse oracle status");
                        check(point_det_status == 0 && point_inv_status == 0,
                            "plain oarrss determinant and inverse succeed");
                        compare_ssoti_vs_soti(&plain_det, &sparse_det, dhl,
                            n >= 4 ? 1e-12 : 1e-13, point_label);
                        compare_fe_scalar_point(&det, ip, &sparse_det, dhl,
                            n >= 4 ? 1e-12 : 1e-13, point_label);
                        {
                            oarrss_t inverse_point = oarrss_init();
                            char point_label[160];

                            feoarrss_get_ip_to(ip, &inv, &inverse_point);
                            snprintf(point_label, sizeof(point_label),
                                "Gauss inverse n=%llu order=%u point=%llu",
                                (unsigned long long)n, (unsigned)order,
                                (unsigned long long)ip);
                            compare_oarrss_vs_arrso(&plain_inv, &sparse_inv, dhl,
                                n >= 4 ? 1e-12 : 1e-13, "plain inverse vs arrso");
                            compare_oarrss_vs_arrso(&inverse_point, &sparse_inv, dhl,
                                n >= 4 ? 1e-12 : 1e-13, point_label);
                            oarrss_free(&inverse_point);
                        }

                        oarrss_free(&point);
                        ssoti_free(&plain_det);
                        oarrss_free(&plain_inv);
                        arrso_free(&sparse_point);
                        arrso_free(&sparse_inv);
                        soti_free(&sparse_det);

                    }

                    feoarrss_free(&matrix);
                    feoarrss_free(&det);
                    feoarrss_free(&inv);

                }

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_singular_and_size_errors(dhelpl_t dhl){

    feoarrss_t singular = feoarrss_zeros(NULL, 0, 4, 4, 3, 2);
    feoarrss_t det = feoarrss_init(), inv = feoarrss_init();
    oarrss_t singular_point = oarrss_zeros(NULL, 0, 4, 4, 2);
    feoarrss_t a = build_fe_operand(2, 3, SET_A, 2, 2, 3, 0.0, dhl);
    feoarrss_t b_bad = build_fe_operand(2, 2, SET_B, 4, 2, 3, 0.0, dhl);
    feoarrss_t b_right = build_fe_operand(3, 2, SET_B, 4, 2, 3, 0.0, dhl);
    feoarrss_t not_square = build_fe_operand(2, 3, SET_A, 2, 2, 3, 0.0, dhl);
    feoarrss_t wrong_nip = build_fe_operand(1, 1, SET_A, 2, 2, 1, 0.0, dhl);
    feoarrss_t wrong_nip_matrix = build_fe_operand(3, 2, SET_B, 4, 2, 1, 0.0, dhl);
    feoarrss_t wrong_weights = build_fe_operand(2, 1, SET_A, 2, 2, 3, 0.0, dhl);
    oarrss_t plain_bad = oarrss_zeros(SET_A, 2, 2, 2, 2);
    feoarrss_t output = feoarrss_init();
    oarrss_t integrated = oarrss_init();
    uint64_t i;

    for (i = 0; i < 3; i++){
        oarrss_set_item_r(i < 3 ? 1.0 : 0.0, i, i, &singular_point);
    }

    feoarrss_from_oarrss_to(&singular_point, 3, &singular);
    check(feoarrss_det_to(&singular, &det, dhl) > 0,
        "n=4 singular real determinant reports positive status");
    check(feoarrss_inv_to(&singular, &inv, dhl) > 0,
        "n=4 singular real inverse reports positive status");

    check(feoarrss_matmul_FF_to(&a, &b_bad, &output, dhl) == OTI_LINALG_ERR_SIZE,
        "matmul FF mismatched inner dimension reports size error");
    check(feoarrss_matmul_FO_to(&a, &plain_bad, &output, dhl) == OTI_LINALG_ERR_SIZE,
        "matmul FO mismatched inner dimension reports size error");
    check(feoarrss_matmul_OF_to(&plain_bad, &b_right, &output, dhl) == OTI_LINALG_ERR_SIZE,
        "matmul OF mismatched inner dimension reports size error");
    check(feoarrss_matmul_FF_to(&a, &wrong_nip_matrix, &output, dhl) == OTI_LINALG_ERR_SIZE,
        "matmul FF mismatched nip reports size error");
    check(feoarrss_dot_product_FO_to(&a, &plain_bad, &output, dhl) == OTI_LINALG_ERR_SIZE,
        "dot FO mismatched element count reports size error");
    check(feoarrss_dot_product_FF_to(&a, &b_bad, &output, dhl) == OTI_LINALG_ERR_SIZE,
        "dot FF mismatched element count reports size error");
    check(feoarrss_dot_product_FF_to(&a, &wrong_nip_matrix, &output, dhl) == OTI_LINALG_ERR_SIZE,
        "dot FF mismatched nip reports size error");
    check(feoarrss_integrate_to(&a, &wrong_weights, &integrated, dhl) == OTI_LINALG_ERR_SIZE,
        "integrate rejects non-scalar weights");
    check(feoarrss_integrate_to(&a, &wrong_nip, &integrated, dhl) == OTI_LINALG_ERR_SIZE,
        "integrate rejects mismatched weight nip");
    check(feoarrss_det_to(&not_square, &det, dhl) == OTI_LINALG_ERR_SIZE,
        "det rejects nonsquare matrix");
    check(feoarrss_inv_to(&not_square, &inv, dhl) == OTI_LINALG_ERR_SIZE,
        "inv rejects nonsquare matrix");

    feoarrss_free(&singular);
    feoarrss_free(&det);
    feoarrss_free(&inv);
    oarrss_free(&singular_point);
    feoarrss_free(&a);
    feoarrss_free(&b_bad);
    feoarrss_free(&b_right);
    feoarrss_free(&not_square);
    feoarrss_free(&wrong_nip);
    feoarrss_free(&wrong_nip_matrix);
    feoarrss_free(&wrong_weights);
    oarrss_free(&plain_bad);
    feoarrss_free(&output);
    oarrss_free(&integrated);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_integrate(dhelpl_t dhl){

    size_t si, ni;
    ord_t order;

    for (si = 0; si < N_SCENARIOS; si++){

        for (order = 1; order <= MAX_ORDER; order++){

            for (ni = 0; ni < 3; ni++){

                const scenario_t* sc = &SCENARIOS[si];
                uint64_t nip = NIPS[ni], ip;
                feoarrss_t values = build_fe_operand(2, 3, sc->bases_a, sc->k_a,
                    order, nip, 0.0, dhl);
                feoarrss_t weights = build_fe_operand(1, 1, sc->bases_b, sc->k_b,
                    order, nip, 0.2, dhl);
                oarrss_t semi_sum = oarrss_zeros(NULL, 0, 2, 3, order);
                arrso_t sparse_sum = arrso_zeros_bases(2, 3, 0, order, dhl);
                oarrss_t result = oarrss_init();
                char label[128];

                check(feoarrss_integrate_to(&values, &weights, &result, dhl) == 0,
                    "integrate status 0");

                for (ip = 0; ip < nip; ip++){

                    oarrss_t value_ip = oarrss_init(), weight_ip = oarrss_init();
                    oarrss_t term = oarrss_init(), next = oarrss_init();
                    arrso_t sparse_value, sparse_weight, sparse_term, sparse_next;
                    ssotinum_t weight_scalar;
                    sotinum_t sparse_weight_scalar;

                    feoarrss_get_ip_to(ip, &values, &value_ip);
                    feoarrss_get_ip_to(ip, &weights, &weight_ip);
                    weight_scalar = oarrss_get_item(0, 0, &weight_ip);
                    oarrss_mul_oO_to(&weight_scalar, &value_ip, &term, dhl);
                    oarrss_sum_OO_to(&semi_sum, &term, &next, dhl);
                    oarrss_free(&semi_sum);
                    semi_sum = next;
                    next = oarrss_init();
                    ssoti_free(&weight_scalar);

                    sparse_value = oarrss_to_arrso(&value_ip, dhl);
                    sparse_weight = oarrss_to_arrso(&weight_ip, dhl);
                    sparse_weight_scalar = arrso_get_item_ij(&sparse_weight, 0, 0, dhl);
                    sparse_term = arrso_zeros_bases(2, 3, 0, order, dhl);
                    arrso_mul_oO_to(&sparse_weight_scalar, &sparse_value, &sparse_term, dhl);
                    sparse_next = arrso_zeros_bases(2, 3, 0, order, dhl);
                    arrso_sum_OO_to(&sparse_sum, &sparse_term, &sparse_next, dhl);
                    arrso_free(&sparse_sum);
                    sparse_sum = sparse_next;
                    sparse_next = arrso_init();

                    arrso_free(&sparse_value);
                    arrso_free(&sparse_weight);
                    arrso_free(&sparse_term);
                    soti_free(&sparse_weight_scalar);
                    oarrss_free(&value_ip);
                    oarrss_free(&weight_ip);
                    oarrss_free(&term);
                    oarrss_free(&next);
                    arrso_free(&sparse_next);

                }

                snprintf(label, sizeof(label), "integrate %s order=%u nip=%llu", sc->label,
                    (unsigned)order, (unsigned long long)nip);
                compare_oarrss_vs_arrso(&semi_sum, &sparse_sum, dhl, 1e-13, label);
                compare_oarrss_vs_arrso(&result, &sparse_sum, dhl, 1e-13, label);
                check(result.nrows == 2 && result.ncols == 3, "integrate returns plain shape");

                feoarrss_free(&values);
                feoarrss_free(&weights);
                oarrss_free(&semi_sum);
                oarrss_free(&result);
                arrso_free(&sparse_sum);

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    dhelp_load(NULL, &dhl);
    test_memory_copy_grow(dhl);
    test_set_shape_from_oarrss_and_bcast(dhl);
    test_set_ip_and_set_ijk(dhl);
    test_slices(dhl);
    test_transpose(dhl);
    test_matmul(dhl);
    test_dot_products(dhl);
    test_integrate(dhl);
    test_det_inv(dhl);
    test_singular_and_size_errors(dhl);
    dhelp_free(&dhl);

    if (n_failed != 0){
        fprintf(stderr, "%d semi-sparse Gauss test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C semi-sparse Gauss tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
