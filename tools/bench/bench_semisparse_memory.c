// C benchmark: heap memory of the semi-sparse types against the sparse types, one case per process.
//
// Runs one operation of bench_semisparse_scalar.c or bench_semisparse_arrays.c (same operands,
// same calls) on one backend, and reports the heap bytes it holds and touches. The process is
// linked with memtrack (tools/bench/memtrack.c), which counts every malloc family call. A fresh
// process per case means each backend pays for the lazy tables it needs itself.
//
// Measured quantities, in bytes:
//   base       bytes held after dhelp_load, before any operand exists (same for every case)
//   operand    storage of the operands (a, b; or A, B, b), built for this backend only
//   onetime    bytes still held after the first call once its result is freed: lazy product
//              tables, cached local tables, workspaces
//   result     storage of the result after a warm call into a fresh destination
//   scratch    peak of the warm call above its final live bytes (temporaries freed on return)
//   peak       peak of the warm call above its starting live bytes (result + scratch)
//   leak       bytes a warm call leaves behind once its result is freed (0 unless something leaks)
//   rss        process peak resident set (ru_maxrss), everything included
// The heap counts see allocated bytes, touched or not. dhelp_load mallocs the sparse temporaries
// up front, so sparse scratch sits in "base" and only shows up as touched pages. The physical
// footprint (TASK_VM_INFO, touched pages) columns catch it:
//   fp_base      footprint after dhelp_load
//   fp_operand   footprint growth while building the operands
//   fp_calls     footprint growth over both calls (tables, temporaries touched, results)
//   fp_peak      process peak footprint above the footprint before the first call
//
//   bench_semisparse_memory scalar <mul|add|div|exp> <k> <n> <full|separable|first>
//                                  <same|leading|interleaved> <sparse|semi>
//   bench_semisparse_memory array  <mul|matmul|solve|inv|det> <N> <k> <n> <sparse|aos|soa>
//   bench_semisparse_memory header
//
// Output: one CSV row on stdout.

#include <mach/mach.h>
#include <sys/resource.h>

#include "bench_common.h"

int64_t memtrack_live(void);
int64_t memtrack_peak(void);
void    memtrack_reset_peak(void);


typedef struct {
    int         kind; ///< 0 scalar, 1 array.
    int           op; ///< Operation index (see OPS_S / OPS_A).
    int      backend; ///< 0 sparse, 1 semi-sparse (scalar) or AoS (array), 2 SoA.
    sotinum_t   oa, ob, oc;
    ssotinum_t  sa, sb, sc;
    arrso_t     oA, oB, ob_, oC;
    arrss_t     aA, aB, ab, aC;
    oarrss_t    sA, sB, sb_, sC;
    uint64_t    rows, cols;
    dhelpl_t    dhl;
} mem_ctx_t;

static const char* OPS_S[] = {"mul", "add", "div", "exp"};
static const char* OPS_A[] = {"mul", "matmul", "solve", "inv", "det"};
static const char* FILLS[] = {"full", "separable", "first"};
static const char* RELS[]  = {"same", "leading", "interleaved"};


// *******************************************************************************************************
// Physical footprint of the process (current, or the process peak when peak is set), in bytes.
static int64_t footprint(int peak){

    task_vm_info_data_t info;
    mach_msg_type_number_t count = TASK_VM_INFO_COUNT;

    if (task_info(mach_task_self(), TASK_VM_INFO, (task_info_t)&info, &count) != KERN_SUCCESS){
        return -1;
    }

    return (int64_t)(peak ? info.ledger_phys_footprint_peak : info.phys_footprint);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int find_name(const char* name, const char** names, int n){

    int i;

    for (i = 0; i < n; i++){
        if (strcmp(name, names[i]) == 0){
            return i;
        }
    }

    fprintf(stderr, "unknown name: %s\n", name);
    exit(2);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Same operand as build_operand in bench_semisparse_scalar.c: the semi-sparse number and the
// identical sparse one.
static void build_operand(const bases_t* S, bases_t k, ord_t n, int fill, uint64_t salt,
                          ssotinum_t* s, sotinum_t* o, dhelpl_t dhl){

    bases_t u[256], g[256];
    ord_t p, i;
    ndir_t j, N;
    imdir_t idx;
    double v;
    uint64_t count = 0;

    *s = ssoti_create_empty(S, k, n);
    s->re = 2.0;
    *o = soti_createReal(2.0, n, dhl);

    for (p = 1; p <= n; p++){

        N = sshelp_ndir_order(k, p);

        for (i = 0; i < p; i++){
            u[i] = 0;
        }

        for (j = 0; j < N; j++, sshelp_next_dir(u, p, k)){

            if ((fill == 1 && u[0] != u[p - 1]) || (fill == 2 && p > 1)){
                continue;
            }

            for (i = 0; i < p; i++){
                g[i] = S[u[i]];
            }

            idx = sshelp_global_rank(g, p);
            v   = bench_coef(salt, count++, 0.01) / p;

            ssoti_set_item(v, idx, p, s);
            soti_set_item(v, idx, p, o, dhl);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Same matrix as build_matrix in bench_semisparse_arrays.c.
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
static void run_case(mem_ctx_t* c){

    if (c->kind == 0){

        if (c->backend == 0){
            switch (c->op){
                case 0: soti_mul_oo_to(&c->oa, &c->ob, &c->oc, c->dhl); break;
                case 1: soti_sum_oo_to(&c->oa, &c->ob, &c->oc, c->dhl); break;
                case 2: soti_div_oo_to(&c->oa, &c->ob, &c->oc, c->dhl); break;
                default: soti_exp_to(&c->oa, &c->oc, c->dhl); break;
            }
        } else {
            switch (c->op){
                case 0: ssoti_mul_oo_to(&c->sa, &c->sb, &c->sc, c->dhl); break;
                case 1: ssoti_sum_oo_to(&c->sa, &c->sb, &c->sc, c->dhl); break;
                case 2: ssoti_div_oo_to(&c->sa, &c->sb, &c->sc, c->dhl); break;
                default: ssoti_exp_to(&c->sa, &c->sc, c->dhl); break;
            }
        }

    } else if (c->backend == 0){

        switch (c->op){
            case 0: arrso_mul_OO_to(&c->oA, &c->oB, &c->oC, c->dhl); break;
            case 1: arrso_matmul_OO_to(&c->oA, &c->oB, &c->oC, c->dhl); break;
            case 2: arrso_solve_to(&c->oA, &c->ob_, &c->oC, c->dhl); break;
            case 3: arrso_invert_to(&c->oA, &c->oC, c->dhl); break;
            default: arrso_det_to(&c->oA, &c->oc, c->dhl); break;
        }

    } else if (c->backend == 1){

        switch (c->op){
            case 0: arrss_mul_OO_to(&c->aA, &c->aB, &c->aC, c->dhl); break;
            case 1: arrss_matmul_OO_to(&c->aA, &c->aB, &c->aC, c->dhl); break;
            case 2: arrss_solve_to(&c->aA, &c->ab, &c->aC, c->dhl); break;
            case 3: arrss_inv_to(&c->aA, &c->aC, c->dhl); break;
            default: arrss_det_to(&c->aA, &c->sc, c->dhl); break;
        }

    } else {

        switch (c->op){
            case 0: oarrss_mul_OO_to(&c->sA, &c->sB, &c->sC, c->dhl); break;
            case 1: oarrss_matmul_OO_to(&c->sA, &c->sB, &c->sC, c->dhl); break;
            case 2: oarrss_solve_to(&c->sA, &c->sb_, &c->sC, c->dhl); break;
            case 3: oarrss_inv_to(&c->sA, &c->sC, c->dhl); break;
            default: oarrss_det_to(&c->sA, &c->sc, c->dhl); break;
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fresh, empty destination for the result (arrso _to functions need the right shape).
static void init_result(mem_ctx_t* c){

    c->oc = soti_init();
    c->sc = ssoti_init();
    c->aC = arrss_init();
    c->sC = oarrss_init();

    if (c->kind == 1 && c->backend == 0 && c->op != 4){
        c->oC = arrso_zeros_bases(c->rows, c->cols, 0, 0, c->dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void free_result(mem_ctx_t* c){

    soti_free(&c->oc);
    ssoti_free(&c->sc);
    arrss_free(&c->aC);
    oarrss_free(&c->sC);

    if (c->kind == 1 && c->backend == 0 && c->op != 4){
        arrso_free(&c->oC);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(int argc, char** argv){

    static const char* BACK_S[] = {"sparse", "semi"};
    static const char* BACK_A[] = {"sparse", "aos", "soa"};
    mem_ctx_t c;
    int64_t fp0, fp1, fp2, live0, live1, live_a, live_c, live_d, peak_d, live_e, live_f;
    uint64_t N = 1, ncoef;
    bases_t k;
    ord_t n;
    int fill = 0, rel = 0;
    struct rusage ru;

    if (argc > 1 && strcmp(argv[1], "header") == 0){
        printf("kind,op,N,k,order,fill,relation,backend,ncoef,base_bytes,operand_bytes,onetime_bytes,"
               "result_bytes,scratch_bytes,peak_bytes,rss_bytes,fp_base,fp_operand,fp_calls,fp_peak,leak_bytes\n");
        return 0;
    }

    memset(&c, 0, sizeof(c));

    if (argc == 8 && strcmp(argv[1], "scalar") == 0){

        c.kind    = 0;
        c.op      = find_name(argv[2], OPS_S, 4);
        k         = (bases_t)atoi(argv[3]);
        n         = (ord_t)atoi(argv[4]);
        fill      = find_name(argv[5], FILLS, 3);
        rel       = find_name(argv[6], RELS, 3);
        c.backend = find_name(argv[7], BACK_S, 2);

    } else if (argc == 7 && strcmp(argv[1], "array") == 0){

        c.kind    = 1;
        c.op      = find_name(argv[2], OPS_A, 5);
        N         = (uint64_t)atoll(argv[3]);
        k         = (bases_t)atoi(argv[4]);
        n         = (ord_t)atoi(argv[5]);
        c.backend = find_name(argv[6], BACK_A, 3);

    } else {

        fprintf(stderr, "usage: see the header of tools/bench/bench_semisparse_memory.c\n");
        return 2;

    }

    ncoef = sshelp_comb((uint64_t)k + n, n);
    dhelp_load(NULL, &c.dhl);
    live0 = memtrack_live();
    fp0   = footprint(0);

    // Operands for this backend only.
    if (c.kind == 0){

        bases_t left[128], right[128], i, kl = 0, kr = 0;

        for (i = 1; i <= k; i++){

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

        build_operand(left, kl, n, fill, 1, &c.sa, &c.oa, c.dhl);
        build_operand(right, kr, n, fill, 2, &c.sb, &c.ob, c.dhl);

        if (c.backend == 0){
            ssoti_free(&c.sa);
            ssoti_free(&c.sb);
        } else {
            soti_free(&c.oa);
            soti_free(&c.ob);
        }

    } else {

        c.oA  = build_matrix(N, N, k, n, 1, 1, c.dhl);
        c.oB  = build_matrix(N, N, k, n, 2, 1, c.dhl);
        c.ob_ = build_matrix(N, 1, k, n, 3, 0, c.dhl);

        if (c.backend == 1){
            c.aA = arrss_from_arrso(&c.oA, c.dhl);
            c.aB = arrss_from_arrso(&c.oB, c.dhl);
            c.ab = arrss_from_arrso(&c.ob_, c.dhl);
        } else if (c.backend == 2){
            c.sA  = oarrss_from_arrso(&c.oA, c.dhl);
            c.sB  = oarrss_from_arrso(&c.oB, c.dhl);
            c.sb_ = oarrss_from_arrso(&c.ob_, c.dhl);
        }

        if (c.backend != 0){
            arrso_free(&c.oA);
            arrso_free(&c.oB);
            arrso_free(&c.ob_);
        }

        c.rows = N;
        c.cols = (c.op == 2) ? 1 : N;

    }

    live1 = memtrack_live();
    fp1   = footprint(0);

    // First call: result plus one-time allocations.
    live_a = memtrack_live();
    init_result(&c);
    memtrack_reset_peak();
    run_case(&c);
    free_result(&c);
    live_e = memtrack_live();

    // Warm call into a fresh destination: result and scratch only.
    live_c = memtrack_live();
    init_result(&c);
    memtrack_reset_peak();
    run_case(&c);
    live_d = memtrack_live();
    peak_d = memtrack_peak();

    fp2 = footprint(0);
    free_result(&c);
    live_f = memtrack_live();
    getrusage(RUSAGE_SELF, &ru);

    printf("%s,%s,%llu,%u,%u,%s,%s,%s,%llu,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld\n",
        c.kind ? "array" : "scalar", c.kind ? OPS_A[c.op] : OPS_S[c.op],
        (unsigned long long)N, (unsigned)k, (unsigned)n, c.kind ? "full" : FILLS[fill],
        c.kind ? "same" : RELS[rel], c.kind ? BACK_A[c.backend] : BACK_S[c.backend],
        (unsigned long long)ncoef, (long long)live0, (long long)(live1 - live0),
        (long long)(live_e - live_a), (long long)(live_d - live_c),
        (long long)(peak_d - live_d), (long long)(peak_d - live_c), (long long)ru.ru_maxrss,
        (long long)fp0, (long long)(fp1 - fp0), (long long)(fp2 - fp1),
        (long long)(footprint(1) - fp1), (long long)(live_f - live_e));

    return 0;

}
// -------------------------------------------------------------------------------------------------------
