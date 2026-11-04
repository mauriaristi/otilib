/* Regression test of slice_size() (src/c/core/utils.c, include/oti/core/utils.h) and of the 2-D slicers
 * built on it (W4, found by py): an empty range gave 1 for |step| >= 2 (e.g. (0, 0, 2)) and a reversed
 * range gave 0 or a negative size, so arrso_get_slice() and the static oarr*_get_slice() returned one
 * row (or failed) for an empty slice.
 *
 * Written by nd-core. Oracle: Python's len(range(start, stop, step)), counted by a loop here, over every
 * normalized (start, stop) in [-1, 12] and step in +-1 .. +-5; then the sparse (arrso_t) and static
 * (oarrm2n3_t) get_slice / get_slice_to on empty and non-empty ranges with positive and negative steps,
 * values checked element by element. Fix round 2 (critic F11): get_slice_size() of the legacy real arrays
 * (src/c/real/array/utils.c) and darr_get_slice / darr_set_slice_r. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <oti/oti.h>

static int n_failed = 0;
static int n_passed = 0;


// *******************************************************************************************************
static void check(int cond, const char* name){

    if (!cond){
        fprintf(stderr, "FAILED: %s\n", name);
        n_failed++;
    } else {
        n_passed++;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// len(range(start, stop, step)) by counting.
static int64_t range_len(int64_t start, int64_t stop, int64_t step){

    int64_t n = 0, i;

    if (step > 0){
        for (i = start; i < stop; i += step){
            n++;
        }
    } else {
        for (i = start; i > stop; i += step){
            n++;
        }
    }

    return n;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_slice_size(void){

    int64_t start, stop, step;
    int ok = 1;

    for (step = -5; step <= 5; step++){
        if (step == 0){
            continue;
        }
        for (start = -1; start <= 12; start++){
            for (stop = -1; stop <= 12; stop++){
                if (slice_size(start, stop, step) != range_len(start, stop, step)){
                    ok = 0;
                    fprintf(stderr, "slice_size(%lld, %lld, %lld) = %lld, expected %lld\n",
                            (long long)start, (long long)stop, (long long)step,
                            (long long)slice_size(start, stop, step),
                            (long long)range_len(start, stop, step));
                }
            }
        }
    }
    check(ok, "slice_size == len(range()) over start, stop in [-1, 12], step in +-1..+-5");
    check(slice_size(0, 0, 2) == 0, "slice_size(0, 0, 2) == 0 (was 1)");
    check(slice_size(3, 3, -2) == 0, "slice_size(3, 3, -2) == 0 (was 1)");
    check(slice_size(5, 2, 1) == 0, "slice_size(5, 2, 1) == 0 (was -2)");
    check(slice_size(5, 2, 2) == 0, "slice_size(5, 2, 2) == 0 (was -1)");
    check(slice_size(2, 5, -1) == 0, "slice_size(2, 5, -1) == 0 (was -2)");
    check(slice_size(0, 10, 3) == 4 && slice_size(9, -1, -3) == 4 && slice_size(4, -1, -1) == 5,
          "slice_size: non-empty ranges unchanged");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// len(range(start, stop, step)) in 128-bit arithmetic (no overflow for any int64_t input), saturated to
// INT64_MAX like slice_size().
__extension__ typedef __int128 i128_t;

static int64_t range_len_wide(int64_t start, int64_t stop, int64_t step){

    i128_t a = start, b = stop, s = step, n = 0;

    if (s > 0 && b > a){
        n = (b - a - 1) / s + 1;
    } else if (s < 0 && a > b){
        n = (a - b - 1) / (-s) + 1;
    }

    return n > (i128_t)INT64_MAX ? INT64_MAX : (int64_t)n;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Boundary steps and huge ranges (checker W4 finding 2): step == INT64_MIN used to negate into signed
// overflow, and stop - start overflowed for ranges wider than INT64_MAX. Run under UBSan in the
// sanitizer tree. Every (start, stop, step) over a boundary set is compared with the 128-bit oracle.
static void test_slice_size_boundary(void){

    static const int64_t bnd[] = {
        INT64_MIN, INT64_MIN + 1, INT64_MIN + 2, -((int64_t)1 << 62), -3, -2, -1, 0, 1, 2, 3,
        (int64_t)1 << 62, INT64_MAX - 2, INT64_MAX - 1, INT64_MAX
    };
    const int nb = (int)(sizeof(bnd) / sizeof(bnd[0]));
    int ia, ib, is, ok = 1;

    for (is = 0; is < nb; is++){
        if (bnd[is] == 0){
            continue;
        }
        for (ia = 0; ia < nb; ia++){
            for (ib = 0; ib < nb; ib++){
                if (slice_size(bnd[ia], bnd[ib], bnd[is]) != range_len_wide(bnd[ia], bnd[ib], bnd[is])){
                    ok = 0;
                    fprintf(stderr, "slice_size(%lld, %lld, %lld) = %lld, expected %lld\n",
                            (long long)bnd[ia], (long long)bnd[ib], (long long)bnd[is],
                            (long long)slice_size(bnd[ia], bnd[ib], bnd[is]),
                            (long long)range_len_wide(bnd[ia], bnd[ib], bnd[is]));
                }
            }
        }
    }
    check(ok, "slice_size == 128-bit len(range()) over boundary start, stop, step (15^3 - 15^2 cases)");

    check(slice_size(2, -1, INT64_MIN) == 1, "slice_size(2, -1, INT64_MIN) == 1 (was -INT64_MIN: UB)");
    check(slice_size(0, 1, INT64_MIN) == 0 && slice_size(INT64_MIN, INT64_MIN, INT64_MIN) == 0,
          "slice_size: empty ranges with step INT64_MIN");
    check(slice_size(INT64_MAX, INT64_MIN, INT64_MIN) == 2,
          "slice_size(INT64_MAX, INT64_MIN, INT64_MIN) == 2");
    check(slice_size(0, 3, INT64_MAX) == 1 && slice_size(1, 3, INT64_MAX) == 1 &&
          slice_size(0, INT64_MAX, INT64_MAX) == 1, "slice_size: step INT64_MAX, one element");
    check(slice_size(INT64_MIN, INT64_MAX, INT64_MAX) == 3,
          "slice_size(INT64_MIN, INT64_MAX, INT64_MAX) == 3 (range wider than INT64_MAX)");
    check(slice_size(INT64_MIN, INT64_MAX, 3) == INT64_C(6148914691236517205),
          "slice_size(INT64_MIN, INT64_MAX, 3) == (2^64 - 2) / 3 + 1");
    check(slice_size(0, INT64_MAX, 1) == INT64_MAX && slice_size(INT64_MAX, 0, -1) == INT64_MAX,
          "slice_size: count INT64_MAX exactly");
    check(slice_size(INT64_MIN, INT64_MAX, 1) == INT64_MAX && slice_size(INT64_MIN, INT64_MAX, 2) ==
          INT64_MAX && slice_size(INT64_MAX, INT64_MIN, -1) == INT64_MAX,
          "slice_size: counts above INT64_MAX saturate to INT64_MAX");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// get_slice_size() of the legacy real (darr_t / fedarr_t) arrays, src/c/real/array/utils.c (W4 fix round
// 2, critic F11): the same bug and the same fix as slice_size(); checked against both oracles.
static void test_get_slice_size(void){

    static const int64_t bnd[] = {
        INT64_MIN, INT64_MIN + 1, -((int64_t)1 << 62), -3, -1, 0, 1, 2, 3, (int64_t)1 << 62,
        INT64_MAX - 1, INT64_MAX
    };
    const int nb = (int)(sizeof(bnd) / sizeof(bnd[0]));
    int64_t start, stop, step;
    int ia, ib, is, ok = 1;

    for (step = -5; step <= 5; step++){
        if (step == 0){
            continue;
        }
        for (start = -1; start <= 12; start++){
            for (stop = -1; stop <= 12; stop++){
                ok = ok && get_slice_size(start, stop, step) == range_len(start, stop, step);
            }
        }
    }
    check(ok, "get_slice_size == len(range()) over start, stop in [-1, 12], step in +-1..+-5");

    ok = 1;
    for (is = 0; is < nb; is++){
        if (bnd[is] == 0){
            continue;
        }
        for (ia = 0; ia < nb; ia++){
            for (ib = 0; ib < nb; ib++){
                ok = ok && get_slice_size(bnd[ia], bnd[ib], bnd[is]) ==
                           range_len_wide(bnd[ia], bnd[ib], bnd[is]);
            }
        }
    }
    check(ok, "get_slice_size == 128-bit len(range()) over boundary start, stop, step");
    check(get_slice_size(0, 0, 2) == 0 && get_slice_size(3, 3, -2) == 0 && get_slice_size(5, 2, 1) == 0 &&
          get_slice_size(2, 5, -1) == 0,
          "get_slice_size: empty ranges (0, 0, 2), (3, 3, -2), stop < start");
    check(get_slice_size(2, -1, INT64_MIN) == 1 && get_slice_size(INT64_MIN, INT64_MAX, 1) == INT64_MAX,
          "get_slice_size: step INT64_MIN, saturation");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Legacy real arrays: a 4x5 darr_t with values 10 * i + j.
static void test_darr(void){

    darr_t a = darr_zeros(4, 5), r;
    uint64_t i, j;
    int ok;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            a.p_data[j + i * a.ncols] = (double)(10 * i + j);
        }
    }

    r = darr_get_slice(&a, 0, 0, 2, 0, 5, 1);
    check(r.nrows == 0 && r.ncols == 5, "darr_get_slice rows (0, 0, 2): 0 x 5 (was 1 x 5)");
    darr_free(&r);
    r = darr_get_slice(&a, 3, 1, 1, 4, 4, -2);
    check(r.nrows == 0 && r.ncols == 0, "darr_get_slice (3, 1, 1) x (4, 4, -2): 0 x 0");
    darr_free(&r);

    // Non-empty: rows 3, 1 and columns 1, 4.
    r = darr_get_slice(&a, 3, -1, -2, 1, 5, 3);
    ok = (r.nrows == 2 && r.ncols == 2);
    for (i = 0; ok && i < 2; i++){
        for (j = 0; j < 2; j++){
            ok = ok && r.p_data[j + i * r.ncols] == (double)(10 * (3 - 2 * i) + (1 + 3 * j));
        }
    }
    check(ok, "darr_get_slice (3, -1, -2) x (1, 5, 3): values");
    darr_free(&r);

    // Extreme steps (post-increments 3 + INT64_MIN and 0 + INT64_MAX representable).
    r = darr_get_slice(&a, 3, -1, INT64_MIN, 0, 5, INT64_MAX);
    check(r.nrows == 1 && r.ncols == 1 && r.p_data[0] == 30.0,
          "darr_get_slice (3, -1, INT64_MIN) x (0, 5, INT64_MAX): 1 x 1, value");
    darr_free(&r);

    // An empty set writes nothing (it wrote one element before).
    darr_set_slice_r(-1.0, 2, 2, 2, 0, 5, 1, &a);
    ok = 1;
    for (i = 0; i < 20; i++){
        ok = ok && a.p_data[i] == (double)(10 * (i / 5) + (i % 5));
    }
    check(ok, "darr_set_slice_r on rows (2, 2, 2) writes nothing");
    darr_free(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Sparse arrays: a 4x5 array with real parts 10 * i + j.
static void test_arrso(dhelpl_t dhl){

    arrso_t a = arrso_zeros_bases(4, 5, 0, 0, dhl), r;
    uint64_t i, j;
    int ok;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            a.p_data[j + i * a.ncols].re = (double)(10 * i + j);
        }
    }

    r = arrso_get_slice(&a, 0, 0, 2, 0, 5, 1, dhl);
    check(r.nrows == 0 && r.ncols == 5, "arrso_get_slice rows (0, 0, 2): 0 x 5 (was 1 x 5)");
    arrso_free(&r);
    r = arrso_get_slice(&a, 1, 3, 1, 4, 4, -1, dhl);
    check(r.nrows == 2 && r.ncols == 0, "arrso_get_slice cols (4, 4, -1): 2 x 0");
    arrso_free(&r);
    r = arrso_get_slice(&a, 3, 1, 1, 0, 5, 2, dhl);
    check(r.nrows == 0 && r.ncols == 3, "arrso_get_slice rows (3, 1, 1), stop < start: 0 x 3");
    arrso_free(&r);
    r = arrso_get_slice(&a, 0, 4, 1, 1, 3, -2, dhl);
    check(r.nrows == 4 && r.ncols == 0, "arrso_get_slice cols (1, 3, -2): 4 x 0");
    arrso_free(&r);

    // Non-empty: rows 1, 3 and columns 4, 2, 0.
    r = arrso_get_slice(&a, 1, 4, 2, 4, -1, -2, dhl);
    ok = (r.nrows == 2 && r.ncols == 3);
    for (i = 0; ok && i < 2; i++){
        for (j = 0; j < 3; j++){
            ok = ok && r.p_data[j + i * r.ncols].re == (double)(10 * (1 + 2 * i) + (4 - 2 * j));
        }
    }
    check(ok, "arrso_get_slice (1, 4, 2) x (4, -1, -2): values");
    arrso_free(&r);

    // Extreme steps as Python's slice.indices() passes them (a[3::-2**63], a[:, ::2**63 - 1]): one
    // element each; the loops' post-increments 3 + INT64_MIN and 0 + INT64_MAX are representable.
    r = arrso_get_slice(&a, 3, -1, INT64_MIN, 0, 5, INT64_MAX, dhl);
    check(r.nrows == 1 && r.ncols == 1 && r.p_data[0].re == 30.0,
          "arrso_get_slice (3, -1, INT64_MIN) x (0, 5, INT64_MAX): 1 x 1, value");
    arrso_free(&r);
    arrso_free(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Static arrays (one module stands for all: they share the generated code and slice_size()).
static void test_static(void){

    oarrm2n3_t a = oarrm2n3_zeros(4, 5), r;
    uint64_t i, j;
    int ok;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            a.p_data[j + i * a.ncols].r = (double)(10 * i + j);
        }
    }

    r = oarrm2n3_get_slice(&a, 0, 0, 2, 0, 5, 1);
    check(r.nrows == 0 && r.ncols == 5, "oarrm2n3_get_slice rows (0, 0, 2): 0 x 5 (was 1 x 5)");
    oarrm2n3_free(&r);
    r = oarrm2n3_get_slice(&a, 2, 0, 1, 0, 5, 1);
    check(r.nrows == 0 && r.ncols == 5, "oarrm2n3_get_slice rows (2, 0, 1), stop < start: 0 x 5");
    oarrm2n3_free(&r);
    r = oarrm2n3_get_slice(&a, 3, -1, -1, 2, 2, -3);
    check(r.nrows == 4 && r.ncols == 0, "oarrm2n3_get_slice cols (2, 2, -3): 4 x 0");
    oarrm2n3_free(&r);

    // Non-empty: rows 3, 2, 1, 0 and columns 0, 3.
    r = oarrm2n3_get_slice(&a, 3, -1, -1, 0, 5, 3);
    ok = (r.nrows == 4 && r.ncols == 2);
    for (i = 0; ok && i < 4; i++){
        for (j = 0; j < 2; j++){
            ok = ok && r.p_data[j + i * r.ncols].r == (double)(10 * (3 - i) + 3 * j);
        }
    }
    check(ok, "oarrm2n3_get_slice (3, -1, -1) x (0, 5, 3): values");
    oarrm2n3_free(&r);

    // Extreme steps, one element each (post-increments 0 + INT64_MAX and 4 + INT64_MIN representable).
    r = oarrm2n3_get_slice(&a, 0, 4, INT64_MAX, 4, -1, INT64_MIN);
    check(r.nrows == 1 && r.ncols == 1 && r.p_data[0].r == 4.0,
          "oarrm2n3_get_slice (0, 4, INT64_MAX) x (4, -1, INT64_MIN): 1 x 1, value");
    oarrm2n3_free(&r);
    oarrm2n3_free(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    dhelp_load(NULL, &dhl);
    test_slice_size();
    test_slice_size_boundary();
    test_get_slice_size();
    test_darr();
    test_arrso(dhl);
    test_static();
    dhelp_free(&dhl);

    printf("test_core_slice: %d passed, %d failed\n", n_passed, n_failed);

    return n_failed == 0 ? 0 : 1;

}
// -------------------------------------------------------------------------------------------------------
