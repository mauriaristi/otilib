// Dense SoA arrays: elementwise and matrix block-product kernels (include/oti/dense/soa/algebra.h).
// Template: src/c/semisparse/soa/kernels.c.
//
// The kernels take each operand with its own nact: an operand over ka <= k bases is a prefix of the
// result layout over k bases (its order-p direction i is direction i of the result layout), so it is
// read in place at its own block offsets and never expanded. Product indices come from
// sshelp_get_pair() over the result's k (global table sub-block, cached local table), or the rank of
// the merged tuples when no table is available. Unity-included from src/c/dense.c: static helpers
// carry the dnok_ prefix.

#ifdef _OPENMP
#include <omp.h>
#endif

/// Elementwise kernels run on OpenMP threads (disjoint element ranges) from this many elements.
#define DNOK_OMP_MIN_ELEMS 4096


// *******************************************************************************************************
// Product-index source for an (order p, order q) pair over k bases, order 0 included (identity).
// When neither the global table nor the local cache covers the pair, the kernels rank the merged
// direction tuples, which they track alongside the indices (no tuple lists are allocated).
typedef struct {
    sshelp_pair_t     pair; ///< Table pair (p, q >= 1); p_tab NULL for the rank fallback.
    sshelp_rank_tab_t  tab; ///< Binomial table of the fallback; p_c NULL means binomials on the fly.
    ord_t             p, q; ///< Orders.
    int           fallback; ///< Nonzero when products are ranked (p, q >= 1 and no table).
} dnok_pairsrc_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static dnok_pairsrc_t dnok_pairsrc_init(bases_t k, ord_t p, ord_t q, dhelpl_t dhl){

    dnok_pairsrc_t src;

    src.p        = p;
    src.q        = q;
    src.fallback = 0;
    src.tab.p_c  = NULL;
    src.tab.k    = 0;
    src.tab.n    = 0;
    src.pair.p_tab     = NULL;
    src.pair.stride    = 0;
    src.pair.transpose = 0;

    if (p == 0 || q == 0){
        return src;
    }

    src.pair = sshelp_get_pair(k, p, q, dhl);

    if (src.pair.p_tab == NULL){

        src.fallback = 1;

        // Without the (small) binomial table the ranks are computed with sshelp_comb(): slower,
        // same result, so an allocation failure here needs no status.
        if (sshelp_rank_tab_init(&src.tab, k, (ord_t)(p + q)) != SSHELP_OK){
            src.tab.p_c = NULL;
        }

    }

    return src;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void dnok_pairsrc_free(dnok_pairsrc_t* src){

    sshelp_rank_tab_free(&src->tab);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Index within order p + q of the product of direction i (tuple ui, order p) and direction j (tuple
// uj, order q). The tuples are only read in the rank fallback.
static inline ndir_t dnok_pair_idx(const dnok_pairsrc_t* src, ndir_t i, const bases_t* ui, ndir_t j,
                                   const bases_t* uj){

    ndir_t r = 0;
    ord_t a = 0, b = 0, t = 0;
    bases_t v;

    if (src->p == 0){
        return j;
    }

    if (src->q == 0){
        return i;
    }

    if (!src->fallback){
        return sshelp_pair_idx(&src->pair, i, j);
    }

    // Merge the sorted tuples and rank: term t is C(v + t, t + 1) (sshelp_prod_rank()).
    while (a < src->p || b < src->q){

        if (b == src->q || (a < src->p && ui[a] <= uj[b])){
            v = ui[a++];
        } else {
            v = uj[b++];
        }

        r += (src->tab.p_c != NULL) ? src->tab.p_c[(size_t)t * src->tab.k + v]
                                    : sshelp_comb((uint64_t)v + t, (uint64_t)t + 1);
        t++;

    }

    return r;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Resets a direction tuple to the first direction of its order.
static inline void dnok_tuple_reset(bases_t* u, ord_t p){

    ord_t i;

    for (i = 0; i < p; i++){
        u[i] = 0;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether n reals are all zero.
static inline int dnok_all_zero(const coeff_t* x, uint64_t n){

    uint64_t e;

    for (e = 0; e < n; e++){

        if (x[e] != 0.0){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Elementwise block product with per-operand nact, accumulated into R over (k, trc), for elements
// [e0, e1). A is over ka bases and B over kb bases (both <= k); their blocks are m reals long. With
// a_bcast set, A is one coefficient per direction (a scalar broadcast over the elements: block
// stride 1, no element offset). Orders p of A in [alo, ahi], q of B in [blo, bhi], p + q <= trc.
static void dnok_mul_acc(const coeff_t* A, bases_t ka, int a_bcast, ord_t alo, ord_t ahi,
                         const coeff_t* B, bases_t kb, ord_t blo, ord_t bhi, bases_t k, ord_t trc,
                         uint64_t m, uint64_t e0, uint64_t e1, coeff_t* R, dhelpl_t dhl){

    ord_t p, q;
    ndir_t i, j, Np, Nq;
    uint64_t e, len = e1 - e0, bp, bq, bpq;
    const coeff_t *Ai, *Bj;
    coeff_t* Rd;
    dnok_pairsrc_t src;
    bases_t ui[256], uj[256];

    if (e1 <= e0){
        return;
    }

    for (p = alo; p <= ahi && p + blo <= trc; p++){

        // Block offsets once per order (direction i of order p: block bp + i).
        Np = sshelp_ndir_order(ka, p);
        bp = oarr_block_index(ka, p, 0);

        for (q = blo; q <= bhi && p + q <= trc; q++){

            Nq  = sshelp_ndir_order(kb, q);
            bq  = oarr_block_index(kb, q, 0);
            bpq = oarr_block_index(k, (ord_t)(p + q), 0);

            if (Np == 0 || Nq == 0){
                continue;
            }

            src = dnok_pairsrc_init(k, p, q, dhl);
            dnok_tuple_reset(ui, p);

            for (i = 0; i < Np; i++){

                if (a_bcast){

                    coeff_t a = A[bp + i];

                    if (a != 0.0){

                        dnok_tuple_reset(uj, q);

                        for (j = 0; j < Nq; j++){

                            Bj = B + (bq + j) * m + e0;
                            Rd = R + (bpq + dnok_pair_idx(&src, i, ui, j, uj)) * m + e0;

                            for (e = 0; e < len; e++){
                                Rd[e] += a * Bj[e];
                            }

                            if (src.fallback){
                                sshelp_next_dir(uj, q, k);
                            }

                        }

                    }

                } else {

                    Ai = A + (bp + i) * m + e0;

                    if (!dnok_all_zero(Ai, len)){

                        dnok_tuple_reset(uj, q);

                        for (j = 0; j < Nq; j++){

                            Bj = B + (bq + j) * m + e0;
                            Rd = R + (bpq + dnok_pair_idx(&src, i, ui, j, uj)) * m + e0;

                            for (e = 0; e < len; e++){
                                Rd[e] += Ai[e] * Bj[e];
                            }

                            if (src.fallback){
                                sshelp_next_dir(uj, q, k);
                            }

                        }

                    }

                }

                if (src.fallback){
                    sshelp_next_dir(ui, p, k);
                }

            }

            dnok_pairsrc_free(&src);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// dnok_mul_acc() over all m elements, split into disjoint element ranges over OpenMP threads from
// DNOK_OMP_MIN_ELEMS elements (never inside an enclosing parallel region). Each element is computed
// by the same sequence of operations whatever the thread count, so results are bit-identical.
static void dnok_mul_acc_all(const coeff_t* A, bases_t ka, int a_bcast, ord_t alo, ord_t ahi,
                             const coeff_t* B, bases_t kb, ord_t blo, ord_t bhi, bases_t k,
                             ord_t trc, uint64_t m, coeff_t* R, dhelpl_t dhl){

#ifdef _OPENMP
    if (m >= DNOK_OMP_MIN_ELEMS && !omp_in_parallel() && omp_get_max_threads() > 1){

        #pragma omp parallel
        {
            uint64_t nt  = (uint64_t)omp_get_num_threads();
            uint64_t tid = (uint64_t)omp_get_thread_num();

            dnok_mul_acc(A, ka, a_bcast, alo, ahi, B, kb, blo, bhi, k, trc, m, (m * tid) / nt,
                         (m * (tid + 1)) / nt, R, dhl);

        }

        return;

    }
#endif

    dnok_mul_acc(A, ka, a_bcast, alo, ahi, B, kb, blo, bhi, k, trc, m, 0, m, R, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarr_kernel_mul_acc(const coeff_t* A, ord_t alo, ord_t ahi, const coeff_t* B, ord_t blo,
                         ord_t bhi, bases_t k, ord_t trc, uint64_t m, uint64_t e0, uint64_t e1,
                         coeff_t* R, dhelpl_t dhl){

    dnok_mul_acc(A, k, 0, alo, ahi, B, k, blo, bhi, k, trc, m, e0, e1, R, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Size checks of a matrix block product: every dimension handed to oti_dgemm as an int, including the
// column count ncols * N_q(kb) of each order of B in [blo, bhi].
static int dnok_matmul_fits(bases_t kb, ord_t blo, ord_t bhi, uint64_t nrows, uint64_t ninner,
                            uint64_t ncols){

    ord_t q;

    if (!oti_lapack_fits(nrows) || !oti_lapack_fits(ninner) || !oti_lapack_fits(ncols)){
        return DN_ERR_SIZE;
    }

    for (q = blo; q <= bhi; q++){

        ndir_t Nq = sshelp_ndir_order(kb, q);

        if (ncols != 0 && Nq > UINT64_MAX / ncols){
            return DN_ERR_SIZE;
        }

        if (!oti_lapack_fits(ncols * Nq)){
            return DN_ERR_SIZE;
        }

        // Stop before q wraps around at the top of ord_t.
        if (q == bhi){
            break;
        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Matrix block product with per-operand nact (see dnok_mul_acc()): A over ka bases, B over kb bases,
// R over (k, trc). Blocks of A are nrows x ninner, of B ninner x ncols, of R nrows x ncols. `work`
// holds nrows * ncols * max_q N_q(kb) reals.
static int dnok_matmul_acc(const coeff_t* A, bases_t ka, ord_t alo, ord_t ahi, const coeff_t* B,
                           bases_t kb, ord_t blo, ord_t bhi, bases_t k, ord_t trc, uint64_t nrows,
                           uint64_t ninner, uint64_t ncols, coeff_t alpha, coeff_t* R, coeff_t* work,
                           dhelpl_t dhl){

    ord_t p, q;
    ndir_t i, j, Np, Nq;
    uint64_t e, sa = nrows * ninner, sb = ninner * ncols, sr = nrows * ncols, bp, bpq;
    const coeff_t *Ai, *Bq;
    coeff_t *Rd, *Wj;
    dnok_pairsrc_t src;
    bases_t ui[256], uj[256];
    int status;

    if (nrows == 0 || ncols == 0){
        return DN_OK;
    }

    status = dnok_matmul_fits(kb, blo, bhi, nrows, ninner, ncols);

    if (status != DN_OK){
        return status;
    }

    // An empty inner dimension adds nothing (dgemm would only scale by beta).
    if (ninner == 0){
        return DN_OK;
    }

    for (p = alo; p <= ahi && p + blo <= trc; p++){

        Np = sshelp_ndir_order(ka, p);
        bp = oarr_block_index(ka, p, 0);

        for (q = blo; q <= bhi && p + q <= trc; q++){

            Nq  = sshelp_ndir_order(kb, q);
            Bq  = B + oarr_block_index(kb, q, 0) * sb;
            bpq = oarr_block_index(k, (ord_t)(p + q), 0);

            if (Np == 0 || Nq == 0){
                continue;
            }

            src = dnok_pairsrc_init(k, p, q, dhl);
            dnok_tuple_reset(ui, p);

            for (i = 0; i < Np; i++){

                Ai = A + (bp + i) * sa;

                if (dnok_all_zero(Ai, sa)){

                    if (src.fallback){
                        sshelp_next_dir(ui, p, k);
                    }

                    continue;

                }

                if (p == 0 || q == 0){

                    // Identity product index: the order-q blocks of B (or the one block) land on
                    // contiguous result blocks (a prefix of the order), so dgemm writes into R.
                    Rd = R + (bpq + ((p == 0) ? 0 : i)) * sr;
                    oti_dgemm('N', 'N', (int)nrows, (int)(ncols * Nq), (int)ninner, alpha, Ai,
                              (int)nrows, Bq, (int)ninner, 1.0, Rd, (int)nrows);

                } else {

                    // A_i x [B_1 ... B_Nq] into scratch, then scatter-add each block.
                    oti_dgemm('N', 'N', (int)nrows, (int)(ncols * Nq), (int)ninner, alpha, Ai,
                              (int)nrows, Bq, (int)ninner, 0.0, work, (int)nrows);

                    dnok_tuple_reset(uj, q);

                    for (j = 0; j < Nq; j++){

                        Wj = work + j * sr;
                        Rd = R + (bpq + dnok_pair_idx(&src, i, ui, j, uj)) * sr;

                        for (e = 0; e < sr; e++){
                            Rd[e] += Wj[e];
                        }

                        if (src.fallback){
                            sshelp_next_dir(uj, q, k);
                        }

                    }

                }

                if (src.fallback){
                    sshelp_next_dir(ui, p, k);
                }

            }

            dnok_pairsrc_free(&src);

        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_kernel_matmul_acc(const coeff_t* A, ord_t alo, ord_t ahi, const coeff_t* B, ord_t blo,
                           ord_t bhi, bases_t k, ord_t trc, uint64_t nrows, uint64_t ninner,
                           uint64_t ncols, coeff_t alpha, coeff_t* R, coeff_t* work,
                           dhelpl_t dhl){

    return dnok_matmul_acc(A, k, alo, ahi, B, k, blo, bhi, k, trc, nrows, ninner, ncols, alpha, R,
                           work, dhl);

}
// -------------------------------------------------------------------------------------------------------
