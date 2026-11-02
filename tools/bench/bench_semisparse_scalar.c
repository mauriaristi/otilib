// C benchmark: semi-sparse scalar (ssotinum_t) against sparse scalar (sotinum_t).
//
// Operations (a, b are OTI scalars, both sides get the same coefficients):
//   mul  c = a * b      soti_mul_oo_to  / ssoti_mul_oo_to
//   add  c = a + b      soti_sum_oo_to  / ssoti_sum_oo_to
//   div  c = a / b      soti_div_oo_to  / ssoti_div_oo_to
//   exp  c = exp(a)     soti_exp_to     / ssoti_exp_to
// Fill patterns of each operand over its bases S, up to truncation order n:
//   full       every direction of orders 1..n over S (C(|S|+n, n) - 1 coefficients)
//   separable  only pure powers e_s^m, s in S, m = 1..n
//   first      only first-order directions e_s
// Set relations of (a, b) over bases 1..k: same (both 1..k), leading (a over 1..k/2, b over
// 1..k), interleaved (a over odd labels, b over even labels).
//
// The sparse type only multiplies correctly while k <= Nbasis(n) (dhelp_default_nbasis); past
// that its tables return wrong directions (PLAN-lazy-nbasis.md). Those cases report only the
// semi-sparse time.
//
// Output: CSV on stdout, metadata as '#' lines.
//   bench_semisparse_scalar [--quick]

#include "bench_common.h"


typedef struct {
    int         op; ///< 0 mul, 1 add, 2 div, 3 exp.
    sotinum_t*  oa; ///< Sparse operands and result.
    sotinum_t*  ob;
    sotinum_t*  oc;
    ssotinum_t* sa; ///< Semi-sparse operands and result.
    ssotinum_t* sb;
    ssotinum_t* sc;
    dhelpl_t   dhl;
} scalar_ctx_t;


// *******************************************************************************************************
static void run_sparse(void* p){

    scalar_ctx_t* c = (scalar_ctx_t*)p;

    switch (c->op){
        case 0: soti_mul_oo_to(c->oa, c->ob, c->oc, c->dhl); break;
        case 1: soti_sum_oo_to(c->oa, c->ob, c->oc, c->dhl); break;
        case 2: soti_div_oo_to(c->oa, c->ob, c->oc, c->dhl); break;
        default: soti_exp_to(c->oa, c->oc, c->dhl); break;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void run_semi(void* p){

    scalar_ctx_t* c = (scalar_ctx_t*)p;

    switch (c->op){
        case 0: ssoti_mul_oo_to(c->sa, c->sb, c->sc, c->dhl); break;
        case 1: ssoti_sum_oo_to(c->sa, c->sb, c->sc, c->dhl); break;
        case 2: ssoti_div_oo_to(c->sa, c->sb, c->sc, c->dhl); break;
        default: ssoti_exp_to(c->sa, c->sc, c->dhl); break;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Builds the semi-sparse operand directly (labels may exceed the sparse tables) and, when
// with_sparse is set, the identical sparse operand.
static void build_operand(const bases_t* S, bases_t k, ord_t n, int fill, uint64_t salt,
                          int with_sparse, ssotinum_t* s, sotinum_t* o, dhelpl_t dhl){

    bases_t u[256], g[256];
    ord_t p, i;
    ndir_t j, N;
    imdir_t idx;
    double v;
    uint64_t count = 0;

    *s = ssoti_create_empty(S, k, n);
    s->re = 2.0;

    if (with_sparse){
        *o = soti_createReal(2.0, n, dhl);
    }

    for (p = 1; p <= n; p++){

        N = sshelp_ndir_order(k, p);

        for (i = 0; i < p; i++){
            u[i] = 0;
        }

        for (j = 0; j < N; j++, sshelp_next_dir(u, p, k)){

            // separable keeps pure powers (u_0 == u_{p-1}); first keeps order 1.
            if ((fill == 1 && u[0] != u[p - 1]) || (fill == 2 && p > 1)){
                continue;
            }

            for (i = 0; i < p; i++){
                g[i] = S[u[i]];
            }

            idx = sshelp_global_rank(g, p);
            v   = bench_coef(salt, count++, 0.01) / p;

            ssoti_set_item(v, idx, p, s);

            if (with_sparse){
                soti_set_item(v, idx, p, o, dhl);
            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(int argc, char** argv){

    static const bases_t KS[] = {2, 5, 10, 11, 20, 50, 100};
    static const ord_t   NS[] = {1, 2, 3, 4, 5, 6, 8, 10};
    static const char*   OPS[] = {"mul", "add", "div", "exp"};
    static const char*   FILLS[] = {"full", "separable", "first"};
    static const char*   RELS[] = {"same", "leading", "interleaved"};
    int quick = (argc > 1 && strcmp(argv[1], "--quick") == 0);
    uint64_t cap = quick ? 2000 : 200000;
    dhelpl_t dhl;
    size_t ik, in;
    int op, fill, rel;

    dhelp_load(NULL, &dhl);

    printf("# bench_semisparse_scalar: median seconds per call, OpenMP threads %d\n",
        bench_threads());
    printf("op,k,order,fill,relation,ncoef,sparse_s,semi_s,speedup,max_rel_diff\n");

    for (ik = 0; ik < sizeof(KS) / sizeof(KS[0]); ik++){

        for (in = 0; in < sizeof(NS) / sizeof(NS[0]); in++){

            bases_t k = KS[ik], left[128], right[128], i, kl = 0, kr = 0;
            ord_t n = NS[in];
            uint64_t ncoef = sshelp_comb((uint64_t)k + n, n);
            int valid = (k <= dhelp_default_nbasis(n));

            // k = 11 only at order 5 (first order past the Nbasis(5) = 10 table limit).
            if (ncoef > cap || (k == 11 && n != 5) || (n == 5 && k != 10 && k != 11)){
                continue;
            }

            for (op = 0; op < 4; op++){

                for (fill = 0; fill < 3; fill++){

                    for (rel = 0; rel < 3; rel++){

                        ssotinum_t sa, sb, sc = ssoti_init();
                        sotinum_t  oa, ob, oc = soti_init();
                        scalar_ctx_t ctx;
                        double ts = NAN, tm, diff = NAN;

                        // exp is unary; only the "same" relation is meaningful.
                        if ((op == 3 && rel != 0) || (quick && fill != 0)){
                            continue;
                        }

                        for (kl = 0, kr = 0, i = 1; i <= k; i++){

                            if (rel == 0){
                                left[kl++] = i;
                                right[kr++] = i;
                            } else if (rel == 1){
                                if (i <= (k / 2 > 0 ? k / 2 : 1)){
                                    left[kl++] = i;
                                }
                                right[kr++] = i;
                            } else {
                                if (i % 2){
                                    left[kl++] = i;
                                } else {
                                    right[kr++] = i;
                                }
                            }

                        }

                        build_operand(left, kl, n, fill, 1, valid, &sa, &oa, dhl);
                        build_operand(right, kr, n, fill, 2, valid, &sb, &ob, dhl);

                        ctx.op = op;
                        ctx.oa = &oa; ctx.ob = &ob; ctx.oc = &oc;
                        ctx.sa = &sa; ctx.sb = &sb; ctx.sc = &sc;
                        ctx.dhl = dhl;

                        tm = bench_time(run_semi, &ctx, 5, 0.02);

                        if (valid){

                            ts   = bench_time(run_sparse, &ctx, 5, 0.02);
                            diff = bench_diff_scalar(&sc, &oc, dhl);
                            soti_free(&oa);
                            soti_free(&ob);
                            soti_free(&oc);

                        }

                        printf("%s,%u,%u,%s,%s,%llu,%.6e,%.6e,%.3f,%.2e\n", OPS[op], (unsigned)k,
                            (unsigned)n, FILLS[fill], RELS[rel], (unsigned long long)ncoef, ts, tm,
                            valid ? ts / tm : NAN, diff);
                        fflush(stdout);

                        ssoti_free(&sa);
                        ssoti_free(&sb);
                        ssoti_free(&sc);

                    }

                }

            }

        }

    }

    dhelp_free(&dhl);

    return 0;

}
// -------------------------------------------------------------------------------------------------------
