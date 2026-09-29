// Semi-sparse SoA arrays: elementwise and matrix block-product kernels.


// *******************************************************************************************************
// Local direction tuples of one order for the rank fallback (NULL for order 0). Caller frees.
static bases_t* oarrss_dirs_alloc(bases_t k, ord_t p){

    ndir_t n = sshelp_ndir_order(k, p);
    bases_t* dirs;

    if (p == 0){
        return NULL;
    }

    dirs = (bases_t*)malloc((size_t)n * p * sizeof(bases_t) + 1);

    if (dirs == NULL){
        ssoti_out_of_memory();
    }

    sshelp_local_dirs(k, p, dirs);

    return dirs;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Product-index source for an order pair, including order 0 (identity) and the rank fallback.
typedef struct {
    sshelp_pair_t     pair; ///< Table pair (p, q >= 1).
    sshelp_rank_tab_t  tab; ///< Rank table (fallback only).
    bases_t*        dirs_p; ///< Order-p tuples (fallback only).
    bases_t*        dirs_q; ///< Order-q tuples (fallback only).
    ord_t             p, q; ///< Orders.
} oarrss_pairsrc_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static oarrss_pairsrc_t oarrss_pairsrc_init(bases_t k, ord_t p, ord_t q, dhelpl_t dhl){

    oarrss_pairsrc_t src;

    src.p      = p;
    src.q      = q;
    src.dirs_p = NULL;
    src.dirs_q = NULL;
    src.tab.p_c = NULL;
    src.tab.k   = 0;
    src.tab.n   = 0;
    src.pair.p_tab     = NULL;
    src.pair.stride    = 0;
    src.pair.transpose = 0;

    if (p == 0 || q == 0){
        return src;
    }

    src.pair = sshelp_get_pair(k, p, q, dhl);

    if (src.pair.p_tab == NULL){

        if (sshelp_rank_tab_init(&src.tab, k, p + q) != SSHELP_OK){
            ssoti_out_of_memory();
        }

        src.dirs_p = oarrss_dirs_alloc(k, p);
        src.dirs_q = oarrss_dirs_alloc(k, q);

    }

    return src;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Local product index of directions i (order p) and j (order q) within order p + q.
static inline ndir_t oarrss_pairsrc_idx(const oarrss_pairsrc_t* src, ndir_t i, ndir_t j){

    if (src->p == 0){
        return j;
    }

    if (src->q == 0){
        return i;
    }

    if (src->pair.p_tab != NULL){
        return sshelp_pair_idx(&src->pair, i, j);
    }

    return sshelp_prod_rank(&src->dirs_p[i * src->p], src->p, &src->dirs_q[j * src->q], src->q,
                            &src->tab);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void oarrss_pairsrc_free(oarrss_pairsrc_t* src){

    sshelp_rank_tab_free(&src->tab);
    free(src->dirs_p);
    free(src->dirs_q);

    src->dirs_p = NULL;
    src->dirs_q = NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether n reals are all zero.
static int oarrss_all_zero(const coeff_t* x, uint64_t n){

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
void oarrss_kernel_mul_acc(const coeff_t* A, ord_t alo, ord_t ahi, const coeff_t* B, ord_t blo,
                           ord_t bhi, bases_t k, ord_t trc, uint64_t m, uint64_t e0, uint64_t e1,
                           coeff_t* R, dhelpl_t dhl){

    ord_t p, q;
    ndir_t i, j, Np, Nq;
    uint64_t e, len = e1 - e0;
    const coeff_t *Ai, *Bj;
    coeff_t* Rd;
    oarrss_pairsrc_t src;

    if (e1 <= e0){
        return;
    }

    for (p = alo; p <= ahi && p + blo <= trc; p++){

        Np = sshelp_ndir_order(k, p);

        for (q = blo; q <= bhi && p + q <= trc; q++){

            Nq  = sshelp_ndir_order(k, q);
            src = oarrss_pairsrc_init(k, p, q, dhl);

            for (i = 0; i < Np; i++){

                Ai = A + oarrss_block_index(k, p, i) * m + e0;

                if (oarrss_all_zero(Ai, len)){
                    continue;
                }

                for (j = 0; j < Nq; j++){

                    Bj = B + oarrss_block_index(k, q, j) * m + e0;
                    Rd = R + oarrss_block_index(k, p + q, oarrss_pairsrc_idx(&src, i, j)) * m + e0;

                    for (e = 0; e < len; e++){
                        Rd[e] += Ai[e] * Bj[e];
                    }

                }

            }

            oarrss_pairsrc_free(&src);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_kernel_matmul_acc(const coeff_t* A, ord_t alo, ord_t ahi, const coeff_t* B, ord_t blo,
                             ord_t bhi, bases_t k, ord_t trc, uint64_t nrows, uint64_t ninner,
                             uint64_t ncols, coeff_t alpha, coeff_t* R, coeff_t* work,
                             dhelpl_t dhl){

    ord_t p, q;
    ndir_t i, j, Np, Nq;
    uint64_t e, sa = nrows * ninner, sb = ninner * ncols, sr = nrows * ncols;
    const coeff_t *Ai, *Bq;
    coeff_t *Rd, *Wj;
    oarrss_pairsrc_t src;

    if (nrows == 0 || ncols == 0){
        return 0;
    }

    if (!oti_lapack_fits(nrows) || !oti_lapack_fits(ninner) || !oti_lapack_fits(ncols)){
        return OTI_LINALG_ERR_SIZE;
    }

    for (q = blo; q <= bhi; q++){

        if (!oti_lapack_fits(ncols * sshelp_ndir_order(k, q))){
            return OTI_LINALG_ERR_SIZE;
        }

    }

    // An empty inner dimension adds nothing (dgemm would only scale by beta).
    if (ninner == 0){
        return 0;
    }

    for (p = alo; p <= ahi && p + blo <= trc; p++){

        Np = sshelp_ndir_order(k, p);

        for (q = blo; q <= bhi && p + q <= trc; q++){

            Nq  = sshelp_ndir_order(k, q);
            Bq  = B + oarrss_block_index(k, q, 0) * sb;
            src = oarrss_pairsrc_init(k, p, q, dhl);

            if (Nq == 0){
                oarrss_pairsrc_free(&src);
                continue;
            }

            for (i = 0; i < Np; i++){

                Ai = A + oarrss_block_index(k, p, i) * sa;

                if (oarrss_all_zero(Ai, sa)){
                    continue;
                }

                if (p == 0 || q == 0){

                    // Identity product index: the order-q blocks (or the one block) of the result
                    // are contiguous, so the product goes straight into R.
                    Rd = R + oarrss_block_index(k, p + q, (p == 0) ? 0 : i) * sr;
                    oti_dgemm('N', 'N', (int)nrows, (int)(ncols * Nq), (int)ninner, alpha, Ai,
                              (int)nrows, Bq, (int)ninner, 1.0, Rd, (int)nrows);

                } else {

                    // A_i x [B_1 ... B_Nq] into scratch, then scatter-add each block.
                    oti_dgemm('N', 'N', (int)nrows, (int)(ncols * Nq), (int)ninner, alpha, Ai,
                              (int)nrows, Bq, (int)ninner, 0.0, work, (int)nrows);

                    for (j = 0; j < Nq; j++){

                        Wj = work + j * sr;
                        Rd = R + oarrss_block_index(k, p + q, oarrss_pairsrc_idx(&src, i, j)) * sr;

                        for (e = 0; e < sr; e++){
                            Rd[e] += Wj[e];
                        }

                    }

                }

            }

            oarrss_pairsrc_free(&src);

        }

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------
