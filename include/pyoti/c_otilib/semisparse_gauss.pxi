# Semi-sparse C declarations, Phase 4: Gauss-point types (PLAN-semisparse-sparse-leveling.md).
# Layout and contracts in include/oti/semisparse/gauss/gauss.h.
cdef extern from "oti/semisparse.h":
    ctypedef struct feoarrss_t:
        oarrss_t arr
        uint64_t nrows
        uint64_t ncols
        uint64_t nip

    feoarrss_t feoarrss_init()
    feoarrss_t feoarrss_zeros(const bases_t *bases, bases_t k, uint64_t nrows, uint64_t ncols,
                              uint64_t nip, ord_t trc_order)
    void feoarrss_free(feoarrss_t *fe)
    void feoarrss_copy_to(const feoarrss_t *fe, feoarrss_t *res)
    void feoarrss_grow(const bases_t *bases, bases_t k, ord_t trc_order, feoarrss_t *fe)
    void feoarrss_set_shape(uint64_t nrows, uint64_t ncols, uint64_t nip, feoarrss_t *fe)

    void feoarrss_get_ip_to(uint64_t ip, const feoarrss_t *fe, oarrss_t *res)
    void feoarrss_set_ip(const oarrss_t *val, uint64_t ip, feoarrss_t *fe)
    void feoarrss_get_slice_to(const feoarrss_t *fe, uint64_t i0, uint64_t ni, int64_t istep,
                               uint64_t j0, uint64_t nj, int64_t jstep, feoarrss_t *res)
    void feoarrss_set_slice(const feoarrss_t *val, uint64_t i0, uint64_t ni, int64_t istep,
                            uint64_t j0, uint64_t nj, int64_t jstep, feoarrss_t *fe)
    void feoarrss_set_ijk_o(const ssotinum_t *num, uint64_t i, uint64_t j, uint64_t ip,
                            feoarrss_t *fe)
    void feoarrss_set_ijk_r(coeff_t val, uint64_t i, uint64_t j, uint64_t ip, feoarrss_t *fe)

    void feoarrss_from_oarrss_to(const oarrss_t *arr, uint64_t nip, feoarrss_t *res)
    void feoarrss_bcast_to(const feoarrss_t *num, uint64_t nrows, uint64_t ncols, feoarrss_t *res)

    void feoarrss_transpose_to(const feoarrss_t *fe, feoarrss_t *res)
    int feoarrss_matmul_FF_to(const feoarrss_t *a, const feoarrss_t *b, feoarrss_t *res,
                              dhelpl_t dhl)
    int feoarrss_matmul_FO_to(const feoarrss_t *a, const oarrss_t *b, feoarrss_t *res, dhelpl_t dhl)
    int feoarrss_matmul_OF_to(const oarrss_t *a, const feoarrss_t *b, feoarrss_t *res, dhelpl_t dhl)
    int feoarrss_dot_product_FO_to(const feoarrss_t *a, const oarrss_t *b, feoarrss_t *res,
                                   dhelpl_t dhl)
    int feoarrss_dot_product_FF_to(const feoarrss_t *a, const feoarrss_t *b, feoarrss_t *res,
                                   dhelpl_t dhl)
    int feoarrss_integrate_to(const feoarrss_t *val, const feoarrss_t *w, oarrss_t *res,
                              dhelpl_t dhl)
    int feoarrss_det_to(const feoarrss_t *fe, feoarrss_t *res, dhelpl_t dhl)
    int feoarrss_inv_to(const feoarrss_t *fe, feoarrss_t *res, dhelpl_t dhl)
