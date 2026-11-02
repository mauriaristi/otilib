# Dense C declarations: Gauss-point types.
# GENERATED from include/oti/dense/**/*.h (PLAN-dense-update.md) by
# tools/gen_dense_pxi.py; re-run it when a dense header changes.
# Do not edit by hand.
cdef extern from "oti/dense.h" nogil:

    # gauss/gauss.h
    ctypedef struct feoarr_t:
        oarr_t arr
        uint64_t nrows
        uint64_t ncols
        uint64_t nip

    ctypedef feoarr_t feotinum_t

    feoarr_t fearr_init()
    int fearr_zeros_to(bases_t nact, uint64_t nrows, uint64_t ncols, uint64_t nip, ord_t trc_order,
                       feoarr_t* res)
    void fearr_free(feoarr_t* fe)
    int fearr_copy_to(const feoarr_t* fe, feoarr_t* res)
    int fearr_grow(bases_t nact, ord_t trc_order, feoarr_t* fe)
    int fearr_set_shape(uint64_t nrows, uint64_t ncols, uint64_t nip, feoarr_t* fe)
    int fearr_get_ip_to(uint64_t ip, const feoarr_t* fe, oarr_t* res)
    int fearr_set_ip(const oarr_t* val, uint64_t ip, feoarr_t* fe)
    int fearr_get_slice_to(const feoarr_t* fe, uint64_t i0, uint64_t ni, int64_t istep, uint64_t j0,
                           uint64_t nj, int64_t jstep, feoarr_t* res)
    int fearr_set_slice(const feoarr_t* val, uint64_t i0, uint64_t ni, int64_t istep, uint64_t j0,
                        uint64_t nj, int64_t jstep, feoarr_t* fe)
    int fearr_set_ijk_o(const otinum_t* num, uint64_t i, uint64_t j, uint64_t ip, feoarr_t* fe)
    int fearr_set_ijk_r(coeff_t val, uint64_t i, uint64_t j, uint64_t ip, feoarr_t* fe)
    int fearr_from_oarr_to(const oarr_t* arr, uint64_t nip, feoarr_t* res)
    int fearr_bcast_to(const feoarr_t* num, uint64_t nrows, uint64_t ncols, feoarr_t* res)
    int fearr_transpose_to(const feoarr_t* fe, feoarr_t* res)
    int fearr_matmul_FF_to(const feoarr_t* a, const feoarr_t* b, feoarr_t* res, dhelpl_t dhl)
    int fearr_matmul_FO_to(const feoarr_t* a, const oarr_t* b, feoarr_t* res, dhelpl_t dhl)
    int fearr_matmul_OF_to(const oarr_t* a, const feoarr_t* b, feoarr_t* res, dhelpl_t dhl)
    int fearr_dot_product_FO_to(const feoarr_t* a, const oarr_t* b, feoarr_t* res, dhelpl_t dhl)
    int fearr_dot_product_FF_to(const feoarr_t* a, const feoarr_t* b, feoarr_t* res, dhelpl_t dhl)
    int fearr_integrate_to(const feoarr_t* val, const feoarr_t* w, oarr_t* res, dhelpl_t dhl)
    int fearr_det_to(const feoarr_t* fe, feoarr_t* res, dhelpl_t dhl)
    int fearr_inv_to(const feoarr_t* fe, feoarr_t* res, dhelpl_t dhl)
