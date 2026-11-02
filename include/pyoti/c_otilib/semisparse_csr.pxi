# Semi-sparse C declarations, Phase 6: OTI sparse matrices (CSR, triplet builder, solve).
# (PLAN-semisparse-sparse-leveling.md). Declare against "oti/semisparse.h".
cdef extern from "oti/semisparse.h":
    ctypedef struct lilss_t:
        ssotinum_t *p_val
        uint64_t *p_row
        uint64_t *p_col
        uint64_t *p_slot
        uint64_t nnz
        uint64_t cap
        uint64_t nslot
        uint64_t nrows
        uint64_t ncols

    ctypedef struct csrss_t:
        const oarrss_t *p_val
        const int64_t *p_indices
        const int64_t *p_indptr
        uint64_t nrows
        uint64_t ncols

    cdef enum:
        CSRSS_OK
        CSRSS_ERR_SIZE
        CSRSS_ERR_INDEX
        CSRSS_ERR_SET
        CSRSS_ERR_ORDER

    lilss_t lilss_init(uint64_t nrows, uint64_t ncols)
    void lilss_free(lilss_t *lil)
    const ssotinum_t *lilss_get(const lilss_t *lil, uint64_t i, uint64_t j)
    void lilss_set(lilss_t *lil, uint64_t i, uint64_t j, const ssotinum_t *val)
    void lilss_set_r(lilss_t *lil, uint64_t i, uint64_t j, coeff_t val)
    void lilss_add(lilss_t *lil, uint64_t i, uint64_t j, const ssotinum_t *val, dhelpl_t dhl)
    int lilss_add_block(lilss_t *lil, const uint64_t *rows, uint64_t nr, const uint64_t *cols,
                        uint64_t nc, const oarrss_t *blk, dhelpl_t dhl)
    void lilss_copy_to(const lilss_t *src, lilss_t *dst)
    ord_t lilss_trc_order(const lilss_t *lil)
    int lilss_sorted(const lilss_t *lil, uint64_t *perm, int64_t *indptr)
    int lilss_to_csr(const lilss_t *lil, oarrss_t *val, int64_t *indices, int64_t *indptr)

    int csrss_check(const csrss_t *K)
    void csrss_to_dense(const csrss_t *K, oarrss_t *res)
    int csrss_matmul_to(const csrss_t *K, const oarrss_t *x, oarrss_t *res, dhelpl_t dhl)
    int csrss_solve_init(const csrss_t *K, const oarrss_t *b, oarrss_t *u)
    int csrss_solve_rhs(const csrss_t *K, oarrss_t *u, ord_t n, dhelpl_t dhl)
