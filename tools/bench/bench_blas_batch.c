// Costs behind the ndarray BLAS batch model (PLAN-ndarray-contracts.md S28; the NDBL_COST table of
// src/c/real/ndarray/blas.c). Built only with -DOTI_BUILD_BENCH=ON and never run by ctest or gates.
//
//   ./tools/bench/bench_blas_batch [--quick]
//
// Prints three tables (ns per call, medians of 5 runs):
//   1. raw provider calls through the oti_d* wrappers from T threads of one OpenMP region (each in
//      its BLAS scope), as oti_parallel_for_blas() runs them: dgemm, memcpy + dgetrf, dgetrs (k = 1),
//      dgetri and dpotrf at n = 2, 3, 8, 20, 32, 100; the T = 1 column is what NDBL_COST models;
//   2. batched ndarray calls (nd_matmul_to, nd_solve with k = 1, nd_det) on C-layout stacks, with a
//      one-thread context (t1) against the default context (td), and the speedup;
//   3. the provider, its caps and oti_blas_contention_ns().
// Compare table 1's T = 1 column with NDBL_COST and table 2's speedups with 1.0 (no stacked call may be
// slower than serial) after changing the constants or the floors.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <oti/oti.h>
#include "oti/core/exec.h"
#include "oti/real/ndarray.h"

#ifdef _OPENMP
#include <omp.h>
#endif

#define BB_RUNS 5


// *******************************************************************************************************
static double bb_now(void){

    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (double)ts.tv_sec + 1e-9 * (double)ts.tv_nsec;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int bb_cmp(const void* a, const void* b){

    double x = *(const double*)a, y = *(const double*)b;

    return x < y ? -1 : x > y;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double bb_median(double* v, int n){

    qsort(v, (size_t)n, sizeof(double), bb_cmp);

    return v[n / 2];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fills an n x n column-major matrix, diagonally dominant (and symmetric when sym).
static void bb_fill(double* a, int n, int sym){

    int i, j;

    for (j = 0; j < n; j++){
        for (i = 0; i < n; i++){
            a[i + j * n] = sym ? 1.0 / (double)(1 + i + j) : (double)((i * 7 + j * 3) % 11) / 11.0;
        }
        a[j + j * n] += (double)n + 1.0;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// `calls` calls of one routine on private operands. 0 dgemm, 1 memcpy + dgetrf, 2 dgetrs, 3 dgetri,
// 4 dpotrf (memcpy first).
static void bb_calls(int routine, int n, int calls){

    size_t nn = (size_t)n * (size_t)n;
    double* a = (double*)malloc(nn * sizeof(double));
    double* f = (double*)malloc(nn * sizeof(double));
    double* c = (double*)malloc(nn * sizeof(double));
    double* w = (double*)malloc(64 * nn * sizeof(double) + 64 * sizeof(double));
    int*    p = (int*)malloc((size_t)n * sizeof(int));
    int     i, info = 0;

    bb_fill(a, n, routine == 4);
    memcpy(f, a, nn * sizeof(double));
    oti_dgetrf(n, n, f, n, p, &info);

    for (i = 0; i < calls; i++){
        switch (routine){
        case 0:
            oti_dgemm('N', 'N', n, n, n, 1.0, a, n, a, n, 0.0, c, n);
            break;
        case 1:
            memcpy(c, a, nn * sizeof(double));
            oti_dgetrf(n, n, c, n, p, &info);
            break;
        case 2:
            memcpy(c, a, (size_t)n * sizeof(double));
            oti_dgetrs('N', n, 1, f, n, p, c, n, &info);
            break;
        case 3:
            memcpy(c, f, nn * sizeof(double));
            oti_dgetri(n, c, n, p, w, 64 * n, &info);
            break;
        default:
            memcpy(c, a, nn * sizeof(double));
            oti_dpotrf('L', n, c, n, &info);
            break;
        }
    }

    free(a);
    free(f);
    free(c);
    free(w);
    free(p);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// ns per call of `total` calls split over T threads of one region (T = 1: no region).
static double bb_raw(int routine, int n, int T, int total){

    double t[BB_RUNS];
    int r;

    bb_calls(routine, n, total / 8 + 1);   // warm-up

    for (r = 0; r < BB_RUNS; r++){

        double t0 = bb_now();

#ifdef _OPENMP
        if (T > 1){
            #pragma omp parallel num_threads(T)
            {
                oti_blas_scope_t sc;

                (void)oti_blas_scope_enter(&sc);
                bb_calls(routine, n, total / omp_get_num_threads());
                oti_blas_scope_exit(&sc);
            }
        } else
#endif
        {
            bb_calls(routine, n, total);
        }

        t[r] = (bb_now() - t0) / (double)total * 1e9;

    }

    return bb_median(t, BB_RUNS);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// ns per stacked call (0 matmul_to, 1 solve, 2 det) on nb matrices of n x n, with ctx.
static double bb_batch(oti_ctx* ctx, int op, int64_t nb, int64_t n){

    int64_t sa[3] = { nb, n, n }, sv[3] = { nb, n, 1 };
    ndarr_t a, b, o, r;
    double t[BB_RUNS], *pa;
    int64_t i, reps = (int64_t)(2e6 / (double)(nb * n * n * n + 1000)) + 1;
    int k, st = OTI_OK;

    nd_init_empty(&a);
    nd_init_empty(&b);
    nd_init_empty(&o);

    if (nd_alloc(NULL, OTI_F64, 3, sa, ND_LAYOUT_C, 0, &a) != OTI_OK
        || nd_alloc(NULL, OTI_F64, 3, op == 1 ? sv : sa, ND_LAYOUT_C, 0, &b) != OTI_OK
        || nd_alloc(NULL, OTI_F64, 3, sa, ND_LAYOUT_C, 0, &o) != OTI_OK){
        fprintf(stderr, "allocation failed\n");
        exit(1);
    }

    pa = (double*)a.data;

    for (i = 0; i < nb; i++){
        bb_fill(pa + i * n * n, (int)n, 0);
    }
    for (i = 0; i < nd_size(&b); i++){
        ((double*)b.data)[i] = 1.0 + (double)(i % 5);
    }

    for (k = 0; k <= BB_RUNS; k++){

        double t0 = bb_now();

        for (i = 0; i < reps && st == OTI_OK; i++){
            nd_init_empty(&r);
            if (op == 0){
                st = nd_matmul_to(ctx, &a, &a, &o);
            } else if (op == 1){
                st = nd_solve(ctx, &a, &b, &r);
            } else {
                st = nd_det(ctx, &a, &r);
            }
            nd_release(&r);
        }

        if (k > 0){
            t[k - 1] = (bb_now() - t0) / (double)reps * 1e9;   // run 0 is the warm-up
        }

    }

    if (st != OTI_OK){
        fprintf(stderr, "batched call failed: %d\n", st);
        exit(1);
    }

    nd_release(&a);
    nd_release(&b);
    nd_release(&o);

    return bb_median(t, BB_RUNS);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(int argc, char** argv){

    static const char* rname[5] = { "dgemm", "memcpy+dgetrf", "dgetrs k=1", "dgetri", "dpotrf" };
    static const char* oname[3] = { "matmul_to", "solve k=1", "det" };
    static const int   sizes[6] = { 2, 3, 8, 20, 32, 100 };
    static const int   teams[5] = { 1, 2, 4, 8, 14 };
    static const int64_t nbs[5] = { 4, 16, 64, 256, 1024 };
    const oti_lapack_provider_t* p = oti_lapack_provider();
    int quick = argc > 1 && strcmp(argv[1], "--quick") == 0;
    int nsz = quick ? 3 : 6, nnb = quick ? 2 : 5, maxt = 1, r, i, j;
    oti_ctx one;

#ifdef _OPENMP
    maxt = omp_get_max_threads();
#endif

    printf("# provider: %s; caps 0x%x; contention %.1f ns per small call\n",
           p->name != NULL ? p->name : "(null)", (unsigned)oti_blas_caps(), oti_blas_contention_ns());

    printf("\n# 1. raw calls, ns per call from T threads of one region\n");
    printf("%-14s %5s", "routine", "n");
    for (j = 0; j < 5; j++){
        printf(" %10s%-2d", "T=", teams[j]);
    }
    printf("\n");

    for (r = 0; r < 5; r++){
        for (i = 0; i < nsz; i++){
            int n = sizes[i], total = n >= 100 ? 512 : n >= 20 ? 4096 : 16384;
            printf("%-14s %5d", rname[r], n);
            for (j = 0; j < 5; j++){
                if (teams[j] > maxt && j > 0){
                    printf(" %12s", "-");
                } else {
                    printf(" %12.0f", bb_raw(r, n, teams[j], quick ? total / 8 : total));
                }
            }
            printf("\n");
        }
    }

    oti_ctx_init(&one);
    one.exec.nthreads = 1;

    printf("\n# 2. batched ndarray calls (C-layout stacks), ns per call: t1 / td (speedup)\n");

    for (r = 0; r < 3; r++){
        for (i = 0; i < 2; i++){
            int64_t n = i == 0 ? 8 : 32;
            printf("%-10s %3lld:", oname[r], (long long)n);
            for (j = 0; j < nnb; j++){
                double t1 = bb_batch(&one, r, nbs[j], n), td = bb_batch(NULL, r, nbs[j], n);
                printf("  nb=%lld %.0f / %.0f (%.2fx)", (long long)nbs[j], t1, td, t1 / td);
            }
            printf("\n");
        }
    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------
