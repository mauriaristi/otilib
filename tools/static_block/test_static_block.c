// Opt-in harness (tools/static_block/CMakeLists.txt): the generated static block kernels
// (src/python/pyoti/python/block_kernel_writer.py) against the dense SoA product, bit for bit.
//
// For each (k, p) in {(1, 1), (1, 10), (2, 4), (3, 3), (10, 2)} and each kernel (mul, trunc_mul,
// mul_acc), the reference is oarr_kernel_mul_acc() (src/c/dense/soa/kernels.c) on the same blocks:
// mul over orders [0, p] x [0, p] into a zeroed result, trunc_mul over [1, p] x [1, p] into a zeroed
// result, mul_acc over [0, p] x [0, p] into a filled result. The generated kernel runs on copies with
// their own block strides (padding between blocks) and an element sub-range, and must leave every
// element outside that range untouched. Exit status: 0 when every comparison is bit-identical.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include <oti/oti.h>
#include <oti/dense.h>

#include "oti_static_block.h"

typedef void (*blk_kernel_t)(const coeff_t* restrict A, int64_t sa, const coeff_t* restrict B,
                             int64_t sb, coeff_t* restrict R, int64_t sr, int64_t n);

typedef struct {
    bases_t      k;     ///< Number of bases.
    ord_t        p;     ///< Truncation order.
    blk_kernel_t fn[3]; ///< mul, trunc_mul, mul_acc.
} blk_case_t;

static const char* const BLK_KIND[3] = {"mul", "trunc_mul", "mul_acc"};

static const blk_case_t BLK_CASES[] = {
    {1, 1, {oarrm1n1_kernel_mul, oarrm1n1_kernel_trunc_mul, oarrm1n1_kernel_mul_acc}},
    {1, 10, {oarrm1n10_kernel_mul, oarrm1n10_kernel_trunc_mul, oarrm1n10_kernel_mul_acc}},
    {2, 4, {oarrm2n4_kernel_mul, oarrm2n4_kernel_trunc_mul, oarrm2n4_kernel_mul_acc}},
    {3, 3, {oarrm3n3_kernel_mul, oarrm3n3_kernel_trunc_mul, oarrm3n3_kernel_mul_acc}},
    {10, 2, {oarrm10n2_kernel_mul, oarrm10n2_kernel_trunc_mul, oarrm10n2_kernel_mul_acc}},
};

/// Value of the padding and of the untouched elements of the generated kernel's result.
#define BLK_SENTINEL 1234.5

/// Data kinds of a scenario.
enum { BLK_DATA_RANDOM = 0, BLK_DATA_ZEROS = 1 };

typedef struct {
    const char* name;  ///< Scenario label.
    int64_t     m;     ///< Elements per block (packed reference stride).
    int64_t     e0;    ///< First element of the run.
    int64_t     e1;    ///< One past the last element of the run.
    int64_t     pad_a; ///< Extra elements between blocks of A (stride m + pad_a).
    int64_t     pad_b; ///< Extra elements between blocks of B.
    int64_t     pad_r; ///< Extra elements between blocks of R.
    int         data;  ///< BLK_DATA_*.
    int         same;  ///< Nonzero: B is A (a square).
} blk_scenario_t;

static const blk_scenario_t BLK_SCENARIOS[] = {
    {"packed, all elements", 37, 0, 37, 0, 0, 0, BLK_DATA_RANDOM, 0},
    {"strided, sub-range", 37, 5, 30, 3, 1, 5, BLK_DATA_RANDOM, 0},
    {"one element", 1, 0, 1, 2, 0, 1, BLK_DATA_RANDOM, 0},
    {"zero block, signed zeros", 16, 0, 16, 1, 2, 3, BLK_DATA_ZEROS, 0},
    {"square (B is A)", 23, 2, 21, 4, 4, 2, BLK_DATA_RANDOM, 1},
    {"empty run", 9, 4, 4, 1, 1, 1, BLK_DATA_RANDOM, 0},
};

static uint64_t blk_rng_state = 0x9E3779B97F4A7C15ULL;


// *******************************************************************************************************
// Deterministic xorshift64* in [-1, 1), never exactly zero.
static double blk_rand(void){

    uint64_t x = blk_rng_state;
    double v;

    x ^= x >> 12;
    x ^= x << 25;
    x ^= x >> 27;
    blk_rng_state = x;
    v = (double)((x * 0x2545F4914F6CDD1DULL) >> 11) / 9007199254740992.0 * 2.0 - 1.0;

    return (v == 0.0) ? 0.5 : v;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether two doubles have the same bits.
static int blk_same_bits(double x, double y){

    uint64_t a, b;

    memcpy(&a, &x, sizeof(a));
    memcpy(&b, &y, sizeof(b));

    return a == b;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fills packed operand blocks. BLK_DATA_ZEROS: block 1 (if any) all zero, every fifth element -0.0
// and every seventh +0.0; the accumulator (is_acc) keeps nonzero values so that it holds no -0.0.
static void blk_fill(coeff_t* x, int64_t nblocks, int64_t m, int data, int is_acc){

    int64_t d, e;

    for (d = 0; d < nblocks; d++){

        for (e = 0; e < m; e++){

            coeff_t v = blk_rand();

            if (data == BLK_DATA_ZEROS && !is_acc){

                if (d == 1){
                    v = 0.0;
                } else if (e % 5 == 0){
                    v = -0.0;
                } else if (e % 7 == 0){
                    v = 0.0;
                }

            }

            x[d * m + e] = v;

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Copies packed blocks (stride m) into strided blocks (stride s), filling the rest with the sentinel.
static void blk_spread(const coeff_t* src, int64_t nblocks, int64_t m, int64_t s, coeff_t* dst){

    int64_t d, e;

    for (e = 0; e < nblocks * s; e++){
        dst[e] = BLK_SENTINEL;
    }

    for (d = 0; d < nblocks; d++){

        for (e = 0; e < m; e++){
            dst[d * s + e] = src[d * m + e];
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs one kernel of one case in one scenario; returns the number of mismatching elements.
static int64_t blk_run(const blk_case_t* c, int kind, const blk_scenario_t* sc, dhelpl_t dhl){

    int64_t nblocks = (int64_t)sshelp_ndir_total(c->k, c->p) + 1;
    int64_t m = sc->m, sa = m + sc->pad_a, sb = m + sc->pad_b, sr = m + sc->pad_r;
    int64_t d, e, bad = 0;
    ord_t lo = (kind == 1) ? 1 : 0;
    coeff_t *A, *B, *R, *A2, *B2, *R2, *R2init;

    A = malloc((size_t)(nblocks * m) * sizeof(coeff_t));
    B = malloc((size_t)(nblocks * m) * sizeof(coeff_t));
    R = malloc((size_t)(nblocks * m) * sizeof(coeff_t));
    A2 = malloc((size_t)(nblocks * sa) * sizeof(coeff_t));
    B2 = malloc((size_t)(nblocks * sb) * sizeof(coeff_t));
    R2 = malloc((size_t)(nblocks * sr) * sizeof(coeff_t));
    R2init = malloc((size_t)(nblocks * sr) * sizeof(coeff_t));

    if (!A || !B || !R || !A2 || !B2 || !R2 || !R2init){
        fprintf(stderr, "allocation failed\n");
        exit(2);
    }

    blk_fill(A, nblocks, m, sc->data, 0);
    blk_fill(B, nblocks, m, sc->data, 0);
    blk_fill(R, nblocks, m, sc->data, 1);

    if (sc->same){
        memcpy(B, A, (size_t)(nblocks * m) * sizeof(coeff_t));
    }

    blk_spread(A, nblocks, m, sa, A2);
    blk_spread(B, nblocks, m, sb, B2);

    // The accumulating kernel starts from R; the assigning ones from the sentinel everywhere.
    blk_spread(R, nblocks, m, sr, R2);

    if (kind != 2){

        for (d = 0; d < nblocks; d++){

            for (e = sc->e0; e < sc->e1; e++){
                R2[d * sr + e] = BLK_SENTINEL;
                R[d * m + e] = 0.0;
            }

        }

    }

    memcpy(R2init, R2, (size_t)(nblocks * sr) * sizeof(coeff_t));

    // Reference: the dense kernel on the packed blocks, elements [e0, e1).
    oarr_kernel_mul_acc(A, lo, c->p, sc->same ? A : B, lo, c->p, c->k, c->p, (uint64_t)m,
                        (uint64_t)sc->e0, (uint64_t)sc->e1, R, dhl);

    // Generated kernel: its own strides, pointers at the first element of the run.
    c->fn[kind](A2 + sc->e0, sa, (sc->same ? A2 : B2) + sc->e0, sc->same ? sa : sb, R2 + sc->e0, sr,
                sc->e1 - sc->e0);

    for (d = 0; d < nblocks; d++){

        for (e = 0; e < sr; e++){

            int inside = (e >= sc->e0 && e < sc->e1);
            double want = inside ? R[d * m + e] : R2init[d * sr + e];
            double got = R2[d * sr + e];

            if (!blk_same_bits(want, got)){

                if (bad < 3){
                    fprintf(stderr, "  k=%d p=%d %s [%s]: block %lld element %lld: %.17g, want "
                            "%.17g%s\n", (int)c->k, (int)c->p, BLK_KIND[kind], sc->name,
                            (long long)d, (long long)e, got, want, inside ? "" : " (outside the run)");
                }

                bad++;

            }

        }

    }

    free(A);
    free(B);
    free(R);
    free(A2);
    free(B2);
    free(R2);
    free(R2init);

    return bad;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    dhelpl_t dhl;
    size_t c, s;
    int kind;
    int64_t bad, total = 0, runs = 0;

    dhelp_load(NULL, &dhl);

    for (c = 0; c < sizeof(BLK_CASES) / sizeof(BLK_CASES[0]); c++){

        int64_t case_bad = 0;

        for (kind = 0; kind < 3; kind++){

            for (s = 0; s < sizeof(BLK_SCENARIOS) / sizeof(BLK_SCENARIOS[0]); s++){

                bad = blk_run(&BLK_CASES[c], kind, &BLK_SCENARIOS[s], dhl);
                case_bad += bad;
                runs++;

            }

        }

        printf("k=%-2d p=%-2d blocks=%-3lld %s\n", (int)BLK_CASES[c].k, (int)BLK_CASES[c].p,
               (long long)(sshelp_ndir_total(BLK_CASES[c].k, BLK_CASES[c].p) + 1),
               case_bad ? "MISMATCH" : "bit-identical (mul, trunc_mul, mul_acc; 6 scenarios)");
        total += case_bad;

    }

    dhelp_free(&dhl);

    printf("%lld runs, %lld mismatching elements\n", (long long)runs, (long long)total);

    return total == 0 ? 0 : 1;

}
// -------------------------------------------------------------------------------------------------------
