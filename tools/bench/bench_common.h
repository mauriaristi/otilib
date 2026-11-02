#ifndef OTI_TOOLS_BENCH_COMMON_H
#define OTI_TOOLS_BENCH_COMMON_H

// Shared helpers of the C semi-sparse benchmarks (tools/bench/bench_semisparse_*.c).
//
// Every case builds its operands once as sotinum_t / arrso_t and converts them to the semi-sparse
// types, so both sides compute with the same coefficients. Every case also checks that both sides
// give the same result before it reports a time.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <oti/oti.h>
#include <oti/semisparse.h>

#ifdef _OPENMP
#include <omp.h>
#endif


// *******************************************************************************************************
// Monotonic wall-clock time in seconds.
static double bench_now(void){

    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (double)ts.tv_sec + 1e-9 * (double)ts.tv_nsec;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int bench_cmp_double(const void* a, const void* b){

    double x = *(const double*)a, y = *(const double*)b;

    return (x > y) - (x < y);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Median seconds per call of fn(ctx). One untimed warm-up call first (it builds the lazy tables).
// Calls are grouped in batches of at least min_batch seconds; the median over nbatch batches is
// reported, so sub-microsecond operations are not dominated by the clock resolution.
static double bench_time(void (*fn)(void*), void* ctx, int nbatch, double min_batch){

    double t0, dt, samples[32];
    long reps = 1, r;
    int b;

    fn(ctx);

    // Calibrate the batch size.
    for (;;){

        t0 = bench_now();

        for (r = 0; r < reps; r++){
            fn(ctx);
        }

        dt = bench_now() - t0;

        if (dt >= min_batch || reps >= (1L << 24)){
            break;
        }

        reps *= (dt <= 0.0) ? 16 : ((long)(min_batch / dt) + 1);

    }

    samples[0] = dt / (double)reps;

    for (b = 1; b < nbatch && b < 32; b++){

        t0 = bench_now();

        for (r = 0; r < reps; r++){
            fn(ctx);
        }

        samples[b] = (bench_now() - t0) / (double)reps;

    }

    qsort(samples, (size_t)b, sizeof(double), bench_cmp_double);

    return samples[b / 2];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Deterministic coefficient in [0.5, 1.5) * scale for a (salt, index) pair.
static double bench_coef(uint64_t salt, uint64_t i, double scale){

    uint64_t x = (salt + 1) * 0x9E3779B97F4A7C15ULL ^ (i + 0x632BE59BD9B4E019ULL);

    x ^= x >> 31;
    x *= 0xBF58476D1CE4E5B9ULL;
    x ^= x >> 27;

    return scale * (0.5 + (double)(x >> 11) / 9007199254740992.0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Largest relative difference between a semi-sparse number and a sparse one, over the real part,
// every direction of the semi-sparse active set, and every stored direction of the sparse number.
static double bench_diff_scalar(const ssotinum_t* s, sotinum_t* o, dhelpl_t dhl){

    double d, scale, worst;
    ord_t p;
    ndir_t i, nloc;
    imdir_t g;

    scale = fabs(o->re) > 1.0 ? fabs(o->re) : 1.0;
    worst = fabs(s->re - o->re) / scale;

    for (p = 1; p <= s->trc_order; p++){

        nloc = sshelp_ndir_order(s->nbases, p);

        for (i = 0; i < nloc; i++){

            sshelp_local_to_global(i, p, s->p_bases, s->nbases, &g);
            d = fabs(s->p_im[sshelp_order_offset(s->nbases, p) + i]
                     - (p <= o->trc_order ? soti_get_item(g, p, o, dhl) : 0.0));
            worst = (d / scale > worst) ? d / scale : worst;

        }

    }

    for (p = 1; p <= o->act_order; p++){

        for (i = 0; i < o->p_nnz[p - 1]; i++){

            d = fabs(o->p_im[p - 1][i] - ssoti_get_item(o->p_idx[p - 1][i], p, s));
            worst = (d / scale > worst) ? d / scale : worst;

        }

    }

    return worst;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Number of OpenMP threads the process will use.
static int bench_threads(void){

#ifdef _OPENMP
    return omp_get_max_threads();
#else
    return 1;
#endif

}
// -------------------------------------------------------------------------------------------------------

#endif
