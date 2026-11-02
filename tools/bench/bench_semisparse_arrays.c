// C benchmark: semi-sparse arrays (SoA oarrss_t, AoS arrss_t) against sparse arrays (arrso_t).
//
// Operands are n x n matrices A, B and an n x 1 right-hand side b. Every entry has every
// direction of orders 1..trc over bases 1..k filled ("full" fill, the worst case for sparse
// storage). A and B have a diagonally dominant real part (A_ii ~ n + 2), so solve, inv and det
// are well conditioned. The same coefficients go to all three types (built as arrso_t, then
// converted with oarrss_from_arrso / arrss_from_arrso).
//
// Operations:
//   mul     C = A o B (elementwise)   arrso_mul_OO_to    / arrss_mul_OO_to    / oarrss_mul_OO_to
//   matmul  C = A B                   arrso_matmul_OO_to / arrss_matmul_OO_to / oarrss_matmul_OO_to
//   solve   x = A^-1 b                arrso_solve_to     / arrss_solve_to     / oarrss_solve_to
//   inv     C = A^-1                  arrso_invert_to    / arrss_inv_to       / oarrss_inv_to
//   det     d = det A                 arrso_det_to       / arrss_det_to       / oarrss_det_to
//
// Output: CSV on stdout, metadata as '#' lines.
//   bench_semisparse_arrays [--quick]

#include "bench_common.h"


typedef struct {
    int         op; ///< 0 mul, 1 matmul, 2 solve, 3 inv, 4 det.
    int    backend; ///< 0 sparse, 1 AoS, 2 SoA.
    arrso_t   *oA, *oB, *ob, *oC;
    arrss_t   *aA, *aB, *ab, *aC;
    oarrss_t  *sA, *sB, *sb, *sC;
    sotinum_t   od;
    ssotinum_t  sd;
    dhelpl_t   dhl;
} array_ctx_t;


// *******************************************************************************************************
static void run_case(void* p){

    array_ctx_t* c = (array_ctx_t*)p;

    if (c->backend == 0){

        switch (c->op){
            case 0: arrso_mul_OO_to(c->oA, c->oB, c->oC, c->dhl); break;
            case 1: arrso_matmul_OO_to(c->oA, c->oB, c->oC, c->dhl); break;
            case 2: arrso_solve_to(c->oA, c->ob, c->oC, c->dhl); break;
            case 3: arrso_invert_to(c->oA, c->oC, c->dhl); break;
            default: arrso_det_to(c->oA, &c->od, c->dhl); break;
        }

    } else if (c->backend == 1){

        switch (c->op){
            case 0: arrss_mul_OO_to(c->aA, c->aB, c->aC, c->dhl); break;
            case 1: arrss_matmul_OO_to(c->aA, c->aB, c->aC, c->dhl); break;
            case 2: arrss_solve_to(c->aA, c->ab, c->aC, c->dhl); break;
            case 3: arrss_inv_to(c->aA, c->aC, c->dhl); break;
            default: arrss_det_to(c->aA, &c->sd, c->dhl); break;
        }

    } else {

        switch (c->op){
            case 0: oarrss_mul_OO_to(c->sA, c->sB, c->sC, c->dhl); break;
            case 1: oarrss_matmul_OO_to(c->sA, c->sB, c->sC, c->dhl); break;
            case 2: oarrss_solve_to(c->sA, c->sb, c->sC, c->dhl); break;
            case 3: oarrss_inv_to(c->sA, c->sC, c->dhl); break;
            default: oarrss_det_to(c->sA, &c->sd, c->dhl); break;
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fully filled n x m sparse matrix over bases 1..k; diag adds a dominant real diagonal.
static arrso_t build_matrix(uint64_t n, uint64_t m, bases_t k, ord_t trc, uint64_t salt,
                            int diag, dhelpl_t dhl){

    arrso_t A = arrso_zeros_bases(n, m, 0, 0, dhl);
    bases_t u[256], g[256];
    uint64_t e, count = 0;
    ord_t p, i;
    ndir_t j, N;

    for (e = 0; e < A.size; e++){

        sotinum_t x;
        uint64_t r = e / m, c = e % m;

        x = soti_createReal(bench_coef(salt, count++, 0.01) + ((diag && r == c) ? n + 2.0 : 0.0),
                            trc, dhl);

        for (p = 1; p <= trc; p++){

            N = sshelp_ndir_order(k, p);

            for (i = 0; i < p; i++){
                u[i] = 0;
            }

            for (j = 0; j < N; j++, sshelp_next_dir(u, p, k)){

                for (i = 0; i < p; i++){
                    g[i] = (bases_t)(u[i] + 1);
                }

                soti_set_item(bench_coef(salt, count++, 0.01) / p, sshelp_global_rank(g, p), p,
                              &x, dhl);

            }

        }

        soti_free(&A.p_data[e]);
        A.p_data[e] = x;

    }

    return A;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Largest relative element difference of a semi-sparse result against the sparse one.
static double diff_soa(const oarrss_t* s, arrso_t* o, dhelpl_t dhl){

    double d, worst = 0.0;
    uint64_t i, j;
    ssotinum_t x = ssoti_init();

    for (i = 0; i < s->nrows; i++){

        for (j = 0; j < s->ncols; j++){

            oarrss_get_item_to(i, j, s, &x);
            d = bench_diff_scalar(&x, &o->p_data[j + i * o->ncols], dhl);
            worst = (d > worst) ? d : worst;

        }

    }

    ssoti_free(&x);

    return worst;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static double diff_aos(const arrss_t* s, arrso_t* o, dhelpl_t dhl){

    double d, worst = 0.0;
    uint64_t e;

    for (e = 0; e < s->size; e++){

        d = bench_diff_scalar(&s->p_data[e], &o->p_data[e], dhl);
        worst = (d > worst) ? d : worst;

    }

    return worst;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(int argc, char** argv){

    static const struct { bases_t k; ord_t trc; } KO[] = {{2, 2}, {5, 3}, {10, 3}, {3, 5}};
    static const uint64_t NS[] = {10, 100, 1000};
    static const char* OPS[] = {"mul", "matmul", "solve", "inv", "det"};
    int quick = (argc > 1 && strcmp(argv[1], "--quick") == 0);
    dhelpl_t dhl;
    size_t ic, in;
    int op;

    dhelp_load(NULL, &dhl);

    printf("# bench_semisparse_arrays: median seconds per call, OpenMP threads %d\n",
        bench_threads());
    printf("op,n,k,order,ncoef,sparse_s,aos_s,soa_s,speedup_aos,speedup_soa,"
           "diff_aos,diff_soa\n");

    for (ic = 0; ic < sizeof(KO) / sizeof(KO[0]); ic++){

        for (in = 0; in < sizeof(NS) / sizeof(NS[0]); in++){

            bases_t k = KO[ic].k;
            ord_t trc = KO[ic].trc;
            uint64_t n = NS[in];
            // n = 1000: SoA only, and only where one matrix stays under ~0.5 GB.
            int big = (n >= 1000), soa_only = big;
            uint64_t ncoef = sshelp_comb((uint64_t)k + trc, trc);
            arrso_t oA, oB, ob, oC;
            arrss_t aA = arrss_init(), aB = arrss_init(), ab = arrss_init(), aC = arrss_init();
            oarrss_t sA, sB, sb, sC = oarrss_init();

            if ((quick && (n > 10 || ic > 1)) || (big && ncoef * n * n * 8 > (1ULL << 29))){
                continue;
            }

            oA = build_matrix(n, n, k, trc, 1, 1, dhl);
            oB = build_matrix(n, n, k, trc, 2, 1, dhl);
            ob = build_matrix(n, 1, k, trc, 3, 0, dhl);
            sA = oarrss_from_arrso(&oA, dhl);
            sB = oarrss_from_arrso(&oB, dhl);
            sb = oarrss_from_arrso(&ob, dhl);

            if (!soa_only){

                aA = arrss_from_arrso(&oA, dhl);
                aB = arrss_from_arrso(&oB, dhl);
                ab = arrss_from_arrso(&ob, dhl);

            }

            for (op = 0; op < 5; op++){

                array_ctx_t ctx;
                double ts = NAN, ta = NAN, tm, da = NAN, dm = NAN;
                uint64_t rows = n, cols = (op == 2) ? 1 : n;

                // n = 1000: only the operations that stay within a few seconds.
                if (big && op > 2){
                    continue;
                }

                ctx.op = op;
                ctx.oA = &oA; ctx.oB = &oB; ctx.ob = &ob; ctx.oC = &oC;
                ctx.aA = &aA; ctx.aB = &aB; ctx.ab = &ab; ctx.aC = &aC;
                ctx.sA = &sA; ctx.sB = &sB; ctx.sb = &sb; ctx.sC = &sC;
                ctx.od = soti_init();
                ctx.sd = ssoti_init();
                ctx.dhl = dhl;

                ctx.backend = 2;
                tm = bench_time(run_case, &ctx, 3, 0.05);

                if (!soa_only){

                    // arrso _to functions need a destination of the right shape.
                    oC = arrso_zeros_bases(rows, cols, 0, 0, dhl);

                    ctx.backend = 0;
                    ts = bench_time(run_case, &ctx, 3, 0.05);
                    ctx.backend = 1;
                    ta = bench_time(run_case, &ctx, 3, 0.05);

                    if (op == 4){

                        da = bench_diff_scalar(&ctx.sd, &ctx.od, dhl);
                        ctx.backend = 2;
                        run_case(&ctx);
                        dm = bench_diff_scalar(&ctx.sd, &ctx.od, dhl);

                    } else {

                        da = diff_aos(&aC, &oC, dhl);
                        dm = diff_soa(&sC, &oC, dhl);

                    }

                    arrso_free(&oC);

                }

                printf("%s,%llu,%u,%u,%llu,%.6e,%.6e,%.6e,%.2f,%.2f,%.2e,%.2e\n", OPS[op],
                    (unsigned long long)n, (unsigned)k, (unsigned)trc, (unsigned long long)ncoef,
                    ts, ta, tm, ts / ta, ts / tm, da, dm);
                fflush(stdout);

                soti_free(&ctx.od);
                ssoti_free(&ctx.sd);

            }

            arrso_free(&oA);
            arrso_free(&oB);
            arrso_free(&ob);
            arrss_free(&aA);
            arrss_free(&aB);
            arrss_free(&ab);
            arrss_free(&aC);
            oarrss_free(&sA);
            oarrss_free(&sB);
            oarrss_free(&sb);
            oarrss_free(&sC);

        }

    }

    dhelp_free(&dhl);

    return 0;

}
// -------------------------------------------------------------------------------------------------------
