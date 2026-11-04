/* Regression test of the absolute value of legacy real arrays (darr_t), src/c/real/array/
 * algebra_elementwise.c: darr_abs, darr_abs_to and darr_self_abs called the integer abs() on doubles
 * (found by oracle-py, W4), truncating -1.5 to 1, -0.25 to 0 and making 1e300, inf and nan undefined.
 *
 * Written by nd-core. Oracle: C99 fabs() semantics, checked bit-wise where it matters: |-0.0| is +0.0,
 * |-inf| is +inf, |nan| and |-nan| are nan with the sign bit cleared; the shape is kept and the input of
 * darr_abs / darr_abs_to is left unchanged. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <oti/oti.h>

static int n_failed = 0;
static int n_passed = 0;

#define NV 12


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
// A 3 x 4 array of the test values (row-major as darr_t stores them).
static darr_t make_input(void){

    const double v[NV] = {
        -1.5, -0.25, 2.75, -0.0, 0.0, -INFINITY, INFINITY, NAN, -NAN, -1e300, -4.9e-324, -3.0
    };
    darr_t a = darr_zeros(3, 4);
    int i;

    for (i = 0; i < NV; i++){
        a.p_data[i] = v[i];
    }

    return a;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The expected |v| of element i, compared exactly (nan: any nan with a cleared sign bit).
static int holds_abs(const darr_t* r, const char* name){

    const double e[NV] = {
        1.5, 0.25, 2.75, 0.0, 0.0, INFINITY, INFINITY, NAN, NAN, 1e300, 4.9e-324, 3.0
    };
    char msg[160];
    int i, ok = (r->nrows == 3 && r->ncols == 4 && r->size == NV);

    snprintf(msg, sizeof(msg), "%s: shape 3 x 4 kept", name);
    check(ok, msg);
    if (!ok){
        return 0;
    }
    for (i = 0; i < NV; i++){
        if (isnan(e[i])){
            ok = isnan(r->p_data[i]) && !signbit(r->p_data[i]);
        } else {
            ok = (r->p_data[i] == e[i]) && !signbit(r->p_data[i]);
        }
        snprintf(msg, sizeof(msg), "%s: element %d is |v| (got %.17g)", name, i, r->p_data[i]);
        check(ok, msg);
    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The input after darr_abs / darr_abs_to is bit-identical to a fresh one.
static void check_input_kept(const darr_t* a, const char* name){

    darr_t f = make_input();
    char msg[160];

    snprintf(msg, sizeof(msg), "%s: input unchanged", name);
    check(memcmp(a->p_data, f.p_data, NV * sizeof(double)) == 0, msg);
    darr_free(&f);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    darr_t a, r;

    a = make_input();
    r = darr_abs(&a);
    holds_abs(&r, "darr_abs");
    check_input_kept(&a, "darr_abs");
    darr_free(&r);
    darr_free(&a);

    a = make_input();
    r = darr_zeros(3, 4);
    darr_abs_to(&a, &r);
    holds_abs(&r, "darr_abs_to");
    check_input_kept(&a, "darr_abs_to");
    darr_free(&r);
    darr_free(&a);

    a = make_input();
    darr_self_abs(&a);
    holds_abs(&a, "darr_self_abs");
    darr_free(&a);

    printf("test_real_darr_abs: %d passed, %d failed\n", n_passed, n_failed);

    return n_failed == 0 ? 0 : 1;

}
// -------------------------------------------------------------------------------------------------------
