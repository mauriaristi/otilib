# Dense C declarations: CSR builder and view.
# GENERATED from include/oti/dense/**/*.h (PLAN-dense-update.md) by
# tools/gen_dense_pxi.py; re-run it when a dense header changes.
# Do not edit by hand.
cdef extern from "oti/dense.h" nogil:

    # csr/csr.h
    cdef enum:
        CSRO_OK
        CSRO_ERR_SIZE
        CSRO_ERR_MEMORY
        CSRO_ERR_INDEX
        CSRO_ERR_NACT
        CSRO_ERR_ORDER

    ctypedef struct lilo_t:
        otinum_t* p_val
        uint64_t* p_row
        uint64_t* p_col
        uint64_t* p_slot
        uint64_t nnz
        uint64_t cap
        uint64_t nslot
        uint64_t nrows
        uint64_t ncols

    ctypedef struct csro_t:
        const oarr_t* p_val
        const int64_t* p_indices
        const int64_t* p_indptr
        uint64_t nrows
        uint64_t ncols

    lilo_t lilo_init(uint64_t nrows, uint64_t ncols)
    void lilo_free(lilo_t* lil)
    const otinum_t* lilo_get(const lilo_t* lil, uint64_t i, uint64_t j)
    int lilo_set(lilo_t* lil, uint64_t i, uint64_t j, const otinum_t* val)
    int lilo_set_r(lilo_t* lil, uint64_t i, uint64_t j, coeff_t val)
    int lilo_add(lilo_t* lil, uint64_t i, uint64_t j, const otinum_t* val, dhelpl_t dhl)
    int lilo_add_block(lilo_t* lil, const uint64_t* rows, uint64_t nr, const uint64_t* cols, uint64_t nc,
                       const oarr_t* blk, dhelpl_t dhl)
    int lilo_copy_to(const lilo_t* src, lilo_t* dst)
    ord_t lilo_trc_order(const lilo_t* lil)
    int lilo_sorted(const lilo_t* lil, uint64_t* perm, int64_t* indptr)
    int lilo_to_csr(const lilo_t* lil, oarr_t* val, int64_t* indices, int64_t* indptr)
    int csro_check(const csro_t* K)
    int csro_to_dense(const csro_t* K, oarr_t* res)
    int csro_matmul_to(const csro_t* K, const oarr_t* x, oarr_t* res, dhelpl_t dhl)
    int csro_solve_init(const csro_t* K, const oarr_t* b, oarr_t* u)
    int csro_solve_rhs(const csro_t* K, oarr_t* u, ord_t n, dhelpl_t dhl)
