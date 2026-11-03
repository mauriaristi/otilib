// Per-call cost of the dense SoA / AoS C API (critic W3 finding 1): the rows the Phase 7a benchmark
// campaign compares between the 1.x structs (base ac7381c5) and the 7a structs (ndarr_t + oti_meta_t).
// Built only with -DOTI_BUILD_BENCH=ON (tools/bench/CMakeLists.txt compiles it with -DOTI7A, the 7a
// accessors); never run by ctest or at gates (runs need approval). Usage:
//   OMP_NUM_THREADS=1 ./tools/bench/bench_7a     FEM sizes (2x2 .. 20x20), one thread
//   ./tools/bench/bench_7a large                 large arrays at the default thread count (the plan)
// Without -DOTI7A it builds against the 1.x headers, for the base side of the comparison.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <oti/oti.h>
#include <oti/dense.h>

#ifdef OTI7A
#define DATA(a)     oarr_data(&(a))
#define SIZE(a)     oarr_size(&(a))
#define SETACT(a,p) oarr_set_act_order(&(a), (p))
#define ADATA(a)    arro_data(&(a))
#else
#define DATA(a)     ((a).p_data)
#define SIZE(a)     ((a).size)
#define SETACT(a,p) ((a).act_order = (p))
#define ADATA(a)    ((a).p_data)
#endif

#define TIME(stmt, reps, out) do {                                                                  \
        double _t0 = now_ns();                                                                       \
        long _i;                                                                                     \
        for (_i = 0; _i < (reps); _i++){ stmt; }                                                     \
        out = (now_ns() - _t0) / (reps);                                                             \
    } while (0)

static volatile double sink;


// *******************************************************************************************************
static double now_ns(void){

    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (double)ts.tv_sec * 1e9 + (double)ts.tv_nsec;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static long reps_for(double est){

    long r = (long)(1.5e8 / (est > 1 ? est : 1));

    return r < 5 ? 5 : r > 2000000 ? 2000000 : r;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void fill(coeff_t* p, uint64_t n, double v){

    uint64_t i;

    for (i = 0; i < n; i++){
        p[i] = v + 1e-3 * (double)(i % 7);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void soa(bases_t k, ord_t p, uint64_t nr, uint64_t nc, dhelpl_t dhl, int large){

    oarr_t A = oarr_init(), B = oarr_init(), R = oarr_init(), T;
    otinum_t num = oti_init();
    uint64_t nblocks = 1 + sshelp_ndir_total(k, p), total;
    long reps;
    double t_alloc, t_sum, t_mul, t_scal, t_neg, t_copy, t_get, t_set, t_sum_new;
    double t_mm = 0, t_lu = 0, t_det = 0;

    oarr_zeros_to(k, nr, nc, p, &A);
    oarr_zeros_to(k, nr, nc, p, &B);
    oarr_zeros_to(k, nr, nc, p, &R);
    total = nblocks * SIZE(A);
    fill(DATA(A), total, 1.5);
    fill(DATA(B), total, 2.5);
    SETACT(A, p);
    SETACT(B, p);
    reps = reps_for((double)total * 0.3 + 50);

    if (large){
        reps = reps < 200 ? 200 : reps;
    }

    TIME({ T = oarr_init(); oarr_zeros_to(k, nr, nc, p, &T); sink = DATA(T)[0]; oarr_free(&T); }, reps,
         t_alloc);
    TIME(oarr_sum_OO_to(&A, &B, &R, dhl), reps, t_sum);
    sink = DATA(R)[1];
    TIME({ T = oarr_init(); oarr_sum_OO_to(&A, &B, &T, dhl); sink = DATA(T)[1]; oarr_free(&T); }, reps,
         t_sum_new);
    TIME(oarr_mul_rO_to(2.0, &A, &R, dhl), reps, t_scal);
    sink = DATA(R)[1];
    TIME(oarr_neg_to(&A, &R, dhl), reps, t_neg);
    sink = DATA(R)[1];
    TIME(oarr_copy_to(&A, &R), reps, t_copy);
    sink = DATA(R)[1];

    {
        long r2 = reps / 4 + 1;

        TIME(oarr_mul_OO_to(&A, &B, &R, dhl), r2, t_mul);
        sink = DATA(R)[1];
    }

    TIME(oarr_get_item_to(1 % nr, 1 % nc, &A, &num), reps, t_get);
    sink = num.re;
    TIME(oarr_set_item(&num, 1 % nr, 1 % nc, &R), reps, t_set);
    sink = DATA(R)[1];

    if (!large && nr == nc){

        oarr_lu_t lu;
        long r3 = reps / 4 + 1;
        otinum_t d = oti_init();

        TIME(oarr_matmul_OO_to(&A, &B, &R, dhl), r3, t_mm);
        sink = DATA(R)[1];
        TIME({ oarr_lu_factor(&A, &lu); sink = DATA(lu.A)[0]; oarr_lu_free(&lu); }, r3, t_lu);
        TIME({ oarr_det_to(&A, &d, dhl); sink = d.re; }, r3, t_det);
        oti_free(&d);

    }

    printf("SoA k=%2d p=%d %4llux%-4llu blocks=%3llu n=%7llu | zeros+free %7.0f | sum_to %7.0f | "
           "sum(new)+free %7.0f | scal %7.0f | neg %7.0f | copy %7.0f | mul %8.0f | "
           "get %5.0f set %5.0f | matmul %7.0f lu %7.0f det %7.0f ns\n",
           (int)k, (int)p, (unsigned long long)nr, (unsigned long long)nc, (unsigned long long)nblocks,
           (unsigned long long)total, t_alloc, t_sum, t_sum_new, t_scal, t_neg, t_copy, t_mul, t_get,
           t_set, t_mm, t_lu, t_det);

    oti_free(&num);
    oarr_free(&A);
    oarr_free(&B);
    oarr_free(&R);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void aos(uint64_t nr, uint64_t nc, bases_t k, ord_t p, dhelpl_t dhl){

    arro_t A = arro_init(), B = arro_init(), R = arro_init(), T;
    uint64_t e, n = nr * nc, i;
    ndir_t nim = sshelp_ndir_total(k, p);
    long reps;
    double t_alloc, t_sum, t_mul;

    arro_zeros_to(nr, nc, p, &A);
    arro_zeros_to(nr, nc, p, &B);
    arro_zeros_to(nr, nc, p, &R);

    for (e = 0; e < n; e++){

        oti_create_empty_to(k, p, &ADATA(A)[e]);
        oti_create_empty_to(k, p, &ADATA(B)[e]);
        ADATA(A)[e].re = 1.5;
        ADATA(B)[e].re = 2.5;
        ADATA(A)[e].act_order = p;
        ADATA(B)[e].act_order = p;

        for (i = 0; i < nim; i++){

            ADATA(A)[e].p_im[i] = 1e-3 * (double)(i + 1);
            ADATA(B)[e].p_im[i] = 2e-3 * (double)(i + 1);

        }

    }

    reps = reps_for((double)n * 60.0 + 100);
    TIME({ T = arro_init(); arro_zeros_to(nr, nc, p, &T); sink = ADATA(T)[0].re; arro_free(&T); }, reps,
         t_alloc);
    TIME(arro_sum_OO_to(&A, &B, &R, dhl), reps, t_sum);
    sink = ADATA(R)[0].re;
    TIME(arro_mul_OO_to(&A, &B, &R, dhl), reps, t_mul);
    sink = ADATA(R)[0].re;
    printf("AoS %4llux%-4llu elems k=%d p=%d | zeros+free %8.0f | sum_to %8.0f | mul_to %8.0f ns\n",
           (unsigned long long)nr, (unsigned long long)nc, (int)k, (int)p, t_alloc, t_sum, t_mul);

    arro_free(&A);
    arro_free(&B);
    arro_free(&R);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(int argc, char** argv){

    dhelpl_t dhl;
    int large = argc > 1;

    (void)argv;
    dhelp_load(NULL, &dhl);

#ifdef OTI7A
    printf("7a build; sizeof(oarr_t)=%zu sizeof(arro_t)=%zu\n", sizeof(oarr_t), sizeof(arro_t));
#else
    printf("base build; sizeof(oarr_t)=%zu sizeof(arro_t)=%zu\n", sizeof(oarr_t), sizeof(arro_t));
#endif

    if (!large){

        soa(2, 2, 2, 2, dhl, 0);
        soa(2, 2, 3, 3, dhl, 0);
        soa(3, 2, 8, 8, dhl, 0);
        soa(5, 3, 8, 8, dhl, 0);
        soa(3, 2, 20, 20, dhl, 0);
        aos(2, 2, 2, 2, dhl);
        aos(8, 8, 2, 2, dhl);
        aos(8, 8, 3, 2, dhl);

    } else {

        soa(2, 2, 100, 100, dhl, 1);
        soa(3, 2, 200, 200, dhl, 1);
        soa(3, 3, 300, 300, dhl, 1);
        soa(1, 1, 1000, 1000, dhl, 1);
        aos(8, 8, 2, 2, dhl);
        aos(100, 100, 2, 2, dhl);
        aos(300, 300, 3, 2, dhl);

    }

    oti_ws_release();
    dhelp_free(&dhl);

    return 0;

}
// -------------------------------------------------------------------------------------------------------
