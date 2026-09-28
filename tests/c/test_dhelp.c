/* Tests of the lazy, in-memory multiplication tables (include/oti/core/dhelp_inline.h,
 * src/c/core/base.c): the per-order basis schedule, that tables start unbuilt after dhelp_load,
 * that dhelp_get_multtabl matches the independent dhelp_precompute_multiply generator, and that
 * the first build of a table is safe under concurrent OpenMP access. */
#include <stdio.h>
#include <stdlib.h>
#include <oti/oti.h>

#ifdef _OPENMP
#include <omp.h>
#endif

#define MAX_THREADS 64

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
/* dhelp_default_nbasis against the documented schedule (AGENTS.md / PLAN-lazy-dhelp-tables.md). */
static void test_default_nbasis_schedule(void){

    static const struct { ord_t lo, hi; bases_t nbasis; } schedule[] = {
        {   1,   1, 65000 },
        {   2,   2,  1000 },
        {   3,   4,   100 },
        {   5,  10,    10 },
        {  11,  20,     5 },
        {  21,  50,     3 },
        {  51, 150,     2 },
    };
    size_t s;
    ord_t order;
    char name[64];

    for (s = 0; s < sizeof(schedule) / sizeof(schedule[0]); s++){

        for (order = schedule[s].lo; order <= schedule[s].hi; order++){

            snprintf(name, sizeof(name), "nbasis schedule order %u", (unsigned)order);
            check(dhelp_default_nbasis(order) == schedule[s].nbasis, name);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Every multiplication table is shaped and tagged with its (ord1, ord2) at load time, but its p_arr
 * stays NULL until dhelp_get_multtabl is called for it. */
static void test_tables_unbuilt_after_load(dhelpl_t dhl){

    ord_t ord_res, k;
    char name[80];

    for (ord_res = 2; ord_res <= 10; ord_res++){

        for (k = 0; k < dhl.p_dh[ord_res-1].Nmult; k++){

            imdir2d_t* tabl = &dhl.p_dh[ord_res-1].p_multtabls[k];

            snprintf(name, sizeof(name), "table (res=%u,small=%u) unbuilt after load",
                (unsigned)ord_res, (unsigned)(k + 1));
            check(tabl->p_arr == NULL, name);

            snprintf(name, sizeof(name), "table (res=%u,small=%u) ord1/ord2",
                (unsigned)ord_res, (unsigned)(k + 1));
            check(tabl->ord1 == (ord_t)(k + 1) && tabl->ord2 == (ord_t)(ord_res - (k + 1)), name);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Deterministic pseudo-random spread over [0, n): avoids re-checking the same handful of entries
 * of a large table every run while staying reproducible. */
static uint64_t sample_index(uint64_t s, uint64_t salt, uint64_t n){

    uint64_t h = (s + 1) * 2654435761ULL + salt * 40503ULL;
    return h % n;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* Checks dhelp_get_multtabl(ord_res, ord_small, dhl) against dhelp_precompute_multiply: every
 * entry when n_samples == 0, otherwise a deterministic sample of n_samples entries. */
static void check_multtabl(ord_t ord_res, ord_t ord_small, uint64_t n_samples, dhelpl_t dhl){

    ord_t ord_big = ord_res - ord_small;
    bases_t nb = dhl.p_dh[ord_res-1].Nbasis;
    ndir_t n1 = dhl.p_dh[ord_small-1].p_ndirs[nb];
    ndir_t n2 = dhl.p_dh[ord_big-1].p_ndirs[nb];
    const imdir2d_t* tabl = dhelp_get_multtabl(ord_res, ord_small, dhl);
    uint64_t total = (uint64_t)n1 * (uint64_t)n2;
    uint64_t s;
    char name[96];

    snprintf(name, sizeof(name), "multtabl(res=%u,small=%u) built",
        (unsigned)ord_res, (unsigned)ord_small);
    check(tabl != NULL && tabl->p_arr != NULL, name);

    snprintf(name, sizeof(name), "multtabl(res=%u,small=%u) shape",
        (unsigned)ord_res, (unsigned)ord_small);
    check(tabl->shape[0] == n1 && tabl->shape[1] == n2, name);

    if (n_samples == 0 || n_samples > total){
        n_samples = total;
    }

    {
        uint64_t n_mismatch = 0;
        const uint64_t max_reported = 5;

        for (s = 0; s < n_samples; s++){

            uint64_t idx1, idx2;
            imdir_t expected, got;

            if (n_samples == total){
                idx1 = s / n2;
                idx2 = s % n2;
            } else {
                idx1 = sample_index(s, 1, n1);
                idx2 = sample_index(s, 2, n2);
            }

            expected = dhelp_precompute_multiply(
                &dhl.p_dh[ord_small-1].p_fulldir[idx1 * ord_small], ord_small,
                &dhl.p_dh[ord_big-1].p_fulldir[idx2 * ord_big], ord_big, dhl);
            got = array2d_getel_ui64_t(tabl->p_arr, tabl->shape[1], idx1, idx2);

            if (got != expected){

                if (n_mismatch < max_reported){
                    fprintf(stderr, "  mismatch multtabl(res=%u,small=%u)[%llu,%llu]: got %llu, "
                        "expected %llu\n", (unsigned)ord_res, (unsigned)ord_small,
                        (unsigned long long)idx1, (unsigned long long)idx2,
                        (unsigned long long)got, (unsigned long long)expected);
                }
                n_mismatch++;

            }

        }

        snprintf(name, sizeof(name), "multtabl(res=%u,small=%u): %llu/%llu entries match",
            (unsigned)ord_res, (unsigned)ord_small,
            (unsigned long long)(n_samples - n_mismatch), (unsigned long long)n_samples);
        check(n_mismatch == 0, name);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
/* A table not yet touched by any earlier test: many OpenMP threads call dhelp_get_multtabl on it
 * at once. Every thread must observe the same pointer, and its contents must be correct. */
static void test_parallel_first_touch(dhelpl_t dhl){

    ord_t ord_res = 6, ord_small = 2;
    const imdir2d_t* ptrs[MAX_THREADS];
    const imdir2d_t* after;
    int nt = 1;
    int t;
    int same = 1;

    #ifdef _OPENMP
    nt = omp_get_max_threads();
    if (nt > MAX_THREADS){
        nt = MAX_THREADS;
    }
    if (nt < 2){
        nt = 2;
    }
    #endif

    #pragma omp parallel num_threads(nt)
    {
        int tid = 0;

        #ifdef _OPENMP
        tid = omp_get_thread_num();
        #endif

        ptrs[tid] = dhelp_get_multtabl(ord_res, ord_small, dhl);

    }

    for (t = 1; t < nt; t++){
        if (ptrs[t] != ptrs[0]){
            same = 0;
        }
    }

    check(same && ptrs[0] != NULL && ptrs[0]->p_arr != NULL,
        "parallel first touch: every thread sees the same built table");

    after = dhelp_get_multtabl(ord_res, ord_small, dhl);
    check(after == ptrs[0], "parallel first touch: cached pointer stable across a later call");

    check_multtabl(ord_res, ord_small, 300, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;

    dhelp_load(NULL, &dhl);

    test_default_nbasis_schedule();
    test_tables_unbuilt_after_load(dhl);

    check_multtabl(2, 1, 0, dhl);   /* full: single, small table */
    check_multtabl(4, 1, 0, dhl);   /* full */
    check_multtabl(4, 2, 0, dhl);   /* full */
    check_multtabl(10, 1, 300, dhl);
    check_multtabl(10, 2, 300, dhl);
    check_multtabl(10, 3, 300, dhl);
    check_multtabl(10, 4, 300, dhl);
    check_multtabl(10, 5, 300, dhl);

    test_parallel_first_touch(dhl);   /* order 6: untouched by the checks above */

    dhelp_free(&dhl);

    if (n_failed != 0){
        fprintf(stderr, "%d dhelp test(s) failed.\n", n_failed);
        return 1;
    }

    printf("C dhelp tests passed successfully.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
