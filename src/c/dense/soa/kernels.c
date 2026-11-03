// Dense SoA arrays: elementwise and matrix block-product kernels (include/oti/dense/soa/algebra.h).
// Template: src/c/semisparse/soa/kernels.c.
//
// The kernels take each operand with its own nact: an operand over ka <= k bases is a prefix of the
// result layout over k bases (its order-p direction i is direction i of the result layout), so it is
// read in place at its own block offsets and never expanded. Product indices come from
// sshelp_get_pair() over the result's k (global table sub-block, cached local table), or the rank of
// the merged tuples when no table is available. Unity-included from src/c/dense.c: static helpers
// carry the dnok_ prefix.

/// Elementwise kernels may run in parallel (oti_parallel_for(), disjoint element ranges with all their
/// blocks) from this many elements: the per-loop floor of the OTI products (contracts S27).
#define DNOK_OMP_MIN_ELEMS 4096

/// Fixed logical chunk of the elementwise kernels, in elements (contracts 5.3): the serial and the
/// parallel paths run the same chunks, so the values do not depend on the number of workers.
#define DNOK_CHUNK_ELEMS OTI_EXEC_CHUNK_ELEMS

/// Estimated serial cost of one block pair per element (ns, one core): one multiply-add on contiguous
/// data (the elementwise floor NDE_NS_ARITH of the ndarray kernels).
#define DNOK_NS_PAIR 0.15

/// Whole-block zero flags of up to this many blocks live on the stack (dnok_mul_acc_all()).
#define DNOK_NZ_STACK 512


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
// Elementwise block product with per-operand nact, accumulated into R over (k, trc), for a run of n
// elements. Every operand comes as a pointer to the first element of the run in its block 0 and its
// block stride (sa, sb, sr), the signature of the generated static block kernels (kernel(A, sa, B,
// sb, R, sr, n)), so strided element runs plug in unchanged. A is over ka bases and B over kb bases
// (both <= k). With a_bcast set, A is one coefficient per direction (a scalar broadcast over the
// elements: sa = 1, no element offset). Orders p of A in [alo, ahi], q of B in [blo, bhi], p + q <= trc.
//
// An A block that is zero is skipped. With anz != NULL, anz[b] tells whether A block b is nonzero over
// the WHOLE array (dnok_block_nz(), computed once and shared by every chunk), so the skip, and with it
// the propagation of a non-finite B (0 * inf), does not depend on how the elements are chunked: the
// result is that of one call over all elements (1.x at one thread) for every worker count. With anz
// NULL the run itself is tested (oarr_kernel_mul_acc()).
static void dnok_mul_acc(const coeff_t* A, int64_t sa, bases_t ka, int a_bcast, ord_t alo, ord_t ahi,
                         const coeff_t* B, int64_t sb, bases_t kb, ord_t blo, ord_t bhi, coeff_t* R,
                         int64_t sr, bases_t k, ord_t trc, int64_t n, const uint8_t* anz, dhelpl_t dhl){

    ord_t p, q;
    ndir_t i, j, Np, Nq;
    uint64_t bp, bq, bpq;
    int64_t e;
    const coeff_t *Ai, *Bj;
    coeff_t* Rd;
    dnok_pairsrc_t src;
    bases_t ui[256], uj[256];

    if (n <= 0){
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

                    coeff_t a = A[(int64_t)(bp + i) * sa];

                    if (a != 0.0){

                        dnok_tuple_reset(uj, q);

                        for (j = 0; j < Nq; j++){

                            Bj = B + (int64_t)(bq + j) * sb;
                            Rd = R + (int64_t)(bpq + dnok_pair_idx(&src, i, ui, j, uj)) * sr;

                            for (e = 0; e < n; e++){
                                Rd[e] += a * Bj[e];
                            }

                            if (src.fallback){
                                sshelp_next_dir(uj, q, k);
                            }

                        }

                    }

                } else {

                    Ai = A + (int64_t)(bp + i) * sa;

                    if ((anz != NULL) ? anz[bp + i] : !dnok_all_zero(Ai, (uint64_t)n)){

                        dnok_tuple_reset(uj, q);

                        for (j = 0; j < Nq; j++){

                            Bj = B + (int64_t)(bq + j) * sb;
                            Rd = R + (int64_t)(bpq + dnok_pair_idx(&src, i, ui, j, uj)) * sr;

                            for (e = 0; e < n; e++){
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
// The whole-block zero predicate of dnok_mul_acc(): nz[b] = 1 when block b of X (stride sx, n
// elements) holds a nonzero, for the blocks b0 <= b < b1; nz[b] = 0 below b0. One scan per block,
// stopping at the first nonzero.
static void dnok_block_nz(const coeff_t* X, int64_t sx, uint64_t n, uint64_t b0, uint64_t b1,
                          uint8_t* nz){

    uint64_t b;

    for (b = 0; b < b0; b++){
        nz[b] = 0;
    }

    for (b = b0; b < b1; b++){
        nz[b] = (uint8_t)!dnok_all_zero(X + (int64_t)b * sx, n);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Number of block pairs (i, j) dnok_mul_acc() visits per element: its cost model (oti_exec_plan()).
static double dnok_pair_count(bases_t ka, ord_t alo, ord_t ahi, bases_t kb, ord_t blo, ord_t bhi,
                              ord_t trc){

    double n = 0.0;
    unsigned p, q;

    for (p = alo; p <= ahi && p + blo <= trc; p++){

        double Np = (double)sshelp_ndir_order(ka, (ord_t)p);

        for (q = blo; q <= bhi && p + q <= trc; q++){
            n += Np * (double)sshelp_ndir_order(kb, (ord_t)q);
        }

    }

    return n;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs fn over the fixed DNOK_CHUNK_ELEMS-element chunks of m elements (contracts 5.3, 5.8; S27): in
// parallel, with the worker count of oti_exec_plan() for ns nanoseconds per element, when that is
// >= 2 and m reaches DNOK_OMP_MIN_ELEMS; serially otherwise (also inside an enclosing parallel
// region). Each chunk is a range of complete elements with all their blocks, and both paths run the
// same chunks, so results are bit-identical for every worker count.
static void dnok_for(uint64_t m, double ns, oti_chunk_fn fn, void* arg){

    int64_t nch = oti_exec_nchunks((int64_t)m, DNOK_CHUNK_ELEMS);

    if (m >= DNOK_OMP_MIN_ELEMS && nch >= 2){

        int32_t w = oti_exec_plan(NULL, (int64_t)m, DNOK_CHUNK_ELEMS, ns);

        if (w >= 2){

            oti_ctx run = *oti_ctx_default();

            run.exec.nthreads = w;
            (void)oti_parallel_for(&run, nch, fn, arg);

            return;

        }

    }

    (void)oti_serial_for(nch, fn, arg);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Arguments of dnok_mul_acc() for the chunks of dnok_mul_acc_all().
typedef struct {
    const coeff_t* A; ///< First operand blocks (or the broadcast scalar's coefficients).
    const coeff_t* B; ///< Second operand blocks.
    coeff_t*       R; ///< Result blocks.
    const uint8_t* anz; ///< Whole-block nonzero flags of A (NULL for a broadcast A).
    uint64_t       m; ///< Block stride of A (unless broadcast), B and R, and number of elements.
    dhelpl_t     dhl; ///< Direction helper.
    bases_t       ka; ///< nact of A.
    bases_t       kb; ///< nact of B.
    bases_t        k; ///< nact of the result.
    int      a_bcast; ///< A is a scalar broadcast over the elements.
    ord_t   alo, ahi; ///< Orders of A.
    ord_t   blo, bhi; ///< Orders of B.
    ord_t        trc; ///< Result truncation order.
} dnok_mul_job_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int dnok_mul_chunk(void* arg, int64_t chunk, int32_t worker){

    const dnok_mul_job_t* j = (const dnok_mul_job_t*)arg;
    uint64_t e0 = (uint64_t)chunk * DNOK_CHUNK_ELEMS, e1 = e0 + DNOK_CHUNK_ELEMS;
    int64_t sm = (int64_t)j->m;

    (void)worker;

    if (e1 > j->m){
        e1 = j->m;
    }

    dnok_mul_acc(j->a_bcast ? j->A : j->A + e0, j->a_bcast ? 1 : sm, j->ka, j->a_bcast, j->alo, j->ahi,
                 j->B + e0, sm, j->kb, j->blo, j->bhi, j->R + e0, sm, j->k, j->trc, (int64_t)(e1 - e0),
                 j->anz, j->dhl);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// dnok_mul_acc() over all m elements, in the fixed element chunks of dnok_for(), with the whole-block
// zero predicate of A computed once (a stack table for up to DNOK_NZ_STACK blocks; if a larger table
// cannot be allocated, each chunk tests its own run, the 1.x multithreaded behaviour).
static void dnok_mul_acc_all(const coeff_t* A, bases_t ka, int a_bcast, ord_t alo, ord_t ahi,
                             const coeff_t* B, bases_t kb, ord_t blo, ord_t bhi, bases_t k,
                             ord_t trc, uint64_t m, coeff_t* R, dhelpl_t dhl){

    dnok_mul_job_t j;
    uint8_t nz_stack[DNOK_NZ_STACK], *nz = NULL;
    ord_t top = (ahi + blo <= trc) ? ahi : (ord_t)(trc - blo);
    uint64_t nb = 0;

    if (!a_bcast && m > 0 && alo + blo <= trc){

        nb = dnob_nblocks(ka, top);
        nz = (nb <= DNOK_NZ_STACK) ? nz_stack : (uint8_t*)malloc((size_t)nb);

        if (nz != NULL){
            dnok_block_nz(A, (int64_t)m, m, oarr_block_index(ka, alo, 0), nb, nz);
        }

    }

    j.A = A;   j.ka = ka;   j.a_bcast = a_bcast;   j.alo = alo;   j.ahi = ahi;   j.anz = nz;
    j.B = B;   j.kb = kb;   j.blo = blo;           j.bhi = bhi;
    j.k = k;   j.trc = trc; j.m = m;               j.R = R;       j.dhl = dhl;

    dnok_for(m, DNOK_NS_PAIR * dnok_pair_count(ka, alo, ahi, kb, blo, bhi, trc), dnok_mul_chunk, &j);

    if (nz != nz_stack){
        free(nz);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarr_kernel_mul_acc(const coeff_t* A, ord_t alo, ord_t ahi, const coeff_t* B, ord_t blo,
                         ord_t bhi, bases_t k, ord_t trc, uint64_t m, uint64_t e0, uint64_t e1,
                         coeff_t* R, dhelpl_t dhl){

    if (e1 <= e0){
        return;
    }

    dnok_mul_acc(A + e0, (int64_t)m, k, 0, alo, ahi, B + e0, (int64_t)m, k, blo, bhi, R + e0, (int64_t)m,
                 k, trc, (int64_t)(e1 - e0), NULL, dhl);

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
// R over (k, trc), each with its block stride (sa, sb, sr). Blocks of A are column-major nrows x
// ninner, of B ninner x ncols, of R nrows x ncols. `work` holds nrows * ncols * max_q N_q(kb) reals.
// Returns DN_OK, DN_ERR_SIZE (LAPACK integers) or DN_ERR_ARGUMENT (strides, see below).
static int dnok_matmul_acc(const coeff_t* A, int64_t sa, bases_t ka, ord_t alo, ord_t ahi,
                           const coeff_t* B, int64_t sb, bases_t kb, ord_t blo, ord_t bhi, bases_t k,
                           ord_t trc, uint64_t nrows, uint64_t ninner, uint64_t ncols, coeff_t alpha,
                           coeff_t* R, int64_t sr, coeff_t* work, dhelpl_t dhl){

    ord_t p, q;
    ndir_t i, j, Np, Nq;
    uint64_t e, ma = nrows * ninner, mr = nrows * ncols, bp, bpq;
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

    // The order-q blocks of B are read, and those of R written, as one F matrix of ncols * N_q
    // columns: their block strides must be the matrix sizes; A's blocks are column-major nrows x
    // ninner matrices at any stride from that size.
    if (sa < (int64_t)ma || sb != (int64_t)(ninner * ncols) || sr != (int64_t)mr){
        return DN_ERR_ARGUMENT;
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
            Bq  = B + (int64_t)oarr_block_index(kb, q, 0) * sb;
            bpq = oarr_block_index(k, (ord_t)(p + q), 0);

            if (Np == 0 || Nq == 0){
                continue;
            }

            src = dnok_pairsrc_init(k, p, q, dhl);
            dnok_tuple_reset(ui, p);

            for (i = 0; i < Np; i++){

                Ai = A + (int64_t)(bp + i) * sa;

                if (dnok_all_zero(Ai, ma)){

                    if (src.fallback){
                        sshelp_next_dir(ui, p, k);
                    }

                    continue;

                }

                if (p == 0 || q == 0){

                    // Identity product index: the order-q blocks of B (or the one block) land on
                    // contiguous result blocks (a prefix of the order), so dgemm writes into R.
                    Rd = R + (int64_t)(bpq + ((p == 0) ? 0 : i)) * sr;
                    oti_dgemm('N', 'N', (int)nrows, (int)(ncols * Nq), (int)ninner, alpha, Ai,
                              (int)nrows, Bq, (int)ninner, 1.0, Rd, (int)nrows);

                } else {

                    // A_i x [B_1 ... B_Nq] into scratch, then scatter-add each block.
                    oti_dgemm('N', 'N', (int)nrows, (int)(ncols * Nq), (int)ninner, alpha, Ai,
                              (int)nrows, Bq, (int)ninner, 0.0, work, (int)nrows);

                    dnok_tuple_reset(uj, q);

                    for (j = 0; j < Nq; j++){

                        Wj = work + j * mr;
                        Rd = R + (int64_t)(bpq + dnok_pair_idx(&src, i, ui, j, uj)) * sr;

                        for (e = 0; e < mr; e++){
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

    return dnok_matmul_acc(A, (int64_t)(nrows * ninner), k, alo, ahi, B, (int64_t)(ninner * ncols), k,
                           blo,
                           bhi, k, trc, nrows, ninner, ncols, alpha, R, (int64_t)(nrows * ncols), work,
                           dhl);

}
// -------------------------------------------------------------------------------------------------------
