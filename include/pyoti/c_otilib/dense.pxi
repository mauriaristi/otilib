# Dense C declarations: structures, status codes, scalar, SoA, linear algebra and AoS.
# GENERATED from include/oti/dense/**/*.h (PLAN-dense-update.md) by
# tools/gen_dense_pxi.py; re-run it when a dense header changes.
# Do not edit by hand.
cdef extern from "oti/dense.h" nogil:

    # scalar/structures.h
    cdef enum:
        DN_OK
        DN_ERR_SIZE
        DN_ERR_MEMORY
        DN_ERR_PIVOT
        DN_ERR_INDEX
        DN_ERR_ARGUMENT

    ctypedef struct otinum_t:
        coeff_t re
        coeff_t* p_im
        bases_t nbases
        bases_t nact
        ord_t trc_order
        ord_t act_order


    # scalar/base.h
    size_t dn_max_bytes()
    otinum_t oti_init()
    otinum_t oti_create_empty(bases_t nact, ord_t trc_order)
    int oti_create_empty_to(bases_t nact, ord_t trc_order, otinum_t* res)
    otinum_t oti_create_r(coeff_t re, ord_t trc_order)
    otinum_t oti_e(imdir_t idx, ord_t order, ord_t trc_order)
    int oti_e_to(imdir_t idx, ord_t order, ord_t trc_order, otinum_t* res)
    int oti_reserve(otinum_t* num, bases_t cap, ord_t trc_order)
    void oti_free(otinum_t* num)
    otinum_t oti_copy(const otinum_t* num)
    int oti_copy_to(const otinum_t* num, otinum_t* res)
    int oti_add_bases(bases_t nact, otinum_t* num)
    void oti_set_r(coeff_t val, otinum_t* num)
    coeff_t oti_get_item(imdir_t idx, ord_t order, const otinum_t* num)
    int oti_set_item(coeff_t val, imdir_t idx, ord_t order, otinum_t* num)
    coeff_t oti_get_deriv(imdir_t idx, ord_t order, const otinum_t* num)
    double oti_density(const otinum_t* num)
    size_t oti_memory_size(const otinum_t* num)
    void oti_print(const otinum_t* num)
    otinum_t oti_from_soti(const sotinum_t* num, dhelpl_t dhl)
    int oti_from_soti_to(const sotinum_t* num, otinum_t* res, dhelpl_t dhl)
    sotinum_t oti_to_soti(const otinum_t* num, dhelpl_t dhl)
    otinum_t oti_truncate_im(imdir_t idx, ord_t order, const otinum_t* num)
    int oti_truncate_im_to(imdir_t idx, ord_t order, const otinum_t* num, otinum_t* res)
    otinum_t oti_truncate_order(ord_t order, const otinum_t* num)
    int oti_truncate_order_to(ord_t order, const otinum_t* num, otinum_t* res)
    otinum_t oti_get_order_im(ord_t order, const otinum_t* num)
    int oti_get_order_im_to(ord_t order, const otinum_t* num, otinum_t* res)
    otinum_t oti_compact(const otinum_t* num)
    int oti_compact_to(const otinum_t* num, otinum_t* res)
    sshelp_ws_t* oti_ws()
    void oti_ws_release()

    # scalar/algebra.h
    otinum_t oti_sum_oo(const otinum_t* num1, const otinum_t* num2, dhelpl_t dhl)
    otinum_t oti_sum_or(const otinum_t* num1, coeff_t val, dhelpl_t dhl)
    int oti_sum_oo_to(const otinum_t* num1, const otinum_t* num2, otinum_t* res, dhelpl_t dhl)
    int oti_sum_or_to(const otinum_t* num1, coeff_t val, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_sub_oo(const otinum_t* num1, const otinum_t* num2, dhelpl_t dhl)
    otinum_t oti_sub_or(const otinum_t* num1, coeff_t val, dhelpl_t dhl)
    otinum_t oti_sub_ro(coeff_t val, const otinum_t* num1, dhelpl_t dhl)
    int oti_sub_oo_to(const otinum_t* num1, const otinum_t* num2, otinum_t* res, dhelpl_t dhl)
    int oti_sub_or_to(const otinum_t* num1, coeff_t val, otinum_t* res, dhelpl_t dhl)
    int oti_sub_ro_to(coeff_t val, const otinum_t* num1, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_neg(const otinum_t* num, dhelpl_t dhl)
    int oti_neg_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_mul_oo(const otinum_t* num1, const otinum_t* num2, dhelpl_t dhl)
    otinum_t oti_mul_or(const otinum_t* num1, coeff_t val, dhelpl_t dhl)
    int oti_mul_oo_to(const otinum_t* num1, const otinum_t* num2, otinum_t* res, dhelpl_t dhl)
    int oti_mul_or_to(const otinum_t* num1, coeff_t val, otinum_t* res, dhelpl_t dhl)
    int oti_gem_oo_to(const otinum_t* num1, const otinum_t* num2, const otinum_t* num3, otinum_t* res,
                      dhelpl_t dhl)
    otinum_t oti_div_oo(const otinum_t* num, const otinum_t* den, dhelpl_t dhl)
    otinum_t oti_div_ro(coeff_t val, const otinum_t* den, dhelpl_t dhl)
    otinum_t oti_div_or(const otinum_t* num, coeff_t val, dhelpl_t dhl)
    int oti_div_oo_to(const otinum_t* num, const otinum_t* den, otinum_t* res, dhelpl_t dhl)
    int oti_div_ro_to(coeff_t val, const otinum_t* den, otinum_t* res, dhelpl_t dhl)
    int oti_div_or_to(const otinum_t* num, coeff_t val, otinum_t* res, dhelpl_t dhl)
    void oti_kernel_mul_acc(const coeff_t* a_im, ord_t alo, ord_t ahi, const coeff_t* b_im, ord_t blo,
                            ord_t bhi, bases_t k, ord_t trc, coeff_t* res_im, dhelpl_t dhl)
    void oti_kernel_expand(const otinum_t* num, bases_t ku, ord_t trc, coeff_t* dst_im)

    # scalar/functions.h
    otinum_t oti_feval(const coeff_t* derivs, const otinum_t* num, dhelpl_t dhl)
    int oti_feval_to(const coeff_t* derivs, const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_exp(const otinum_t* num, dhelpl_t dhl)
    int oti_exp_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_log(const otinum_t* num, dhelpl_t dhl)
    int oti_log_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_log10(const otinum_t* num, dhelpl_t dhl)
    int oti_log10_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_sqrt(const otinum_t* num, dhelpl_t dhl)
    int oti_sqrt_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_cbrt(const otinum_t* num, dhelpl_t dhl)
    int oti_cbrt_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_sin(const otinum_t* num, dhelpl_t dhl)
    int oti_sin_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_cos(const otinum_t* num, dhelpl_t dhl)
    int oti_cos_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_tan(const otinum_t* num, dhelpl_t dhl)
    int oti_tan_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_asin(const otinum_t* num, dhelpl_t dhl)
    int oti_asin_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_acos(const otinum_t* num, dhelpl_t dhl)
    int oti_acos_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_atan(const otinum_t* num, dhelpl_t dhl)
    int oti_atan_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_sinh(const otinum_t* num, dhelpl_t dhl)
    int oti_sinh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_cosh(const otinum_t* num, dhelpl_t dhl)
    int oti_cosh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_tanh(const otinum_t* num, dhelpl_t dhl)
    int oti_tanh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_asinh(const otinum_t* num, dhelpl_t dhl)
    int oti_asinh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_acosh(const otinum_t* num, dhelpl_t dhl)
    int oti_acosh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_atanh(const otinum_t* num, dhelpl_t dhl)
    int oti_atanh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_erf(const otinum_t* num, dhelpl_t dhl)
    int oti_erf_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_pow(const otinum_t* num,coeff_t e, dhelpl_t dhl)
    int oti_pow_to(const otinum_t* num,coeff_t e, otinum_t* res, dhelpl_t dhl)
    otinum_t oti_logb(const otinum_t* num,coeff_t base, dhelpl_t dhl)
    int oti_logb_to(const otinum_t* num,coeff_t base, otinum_t* res, dhelpl_t dhl)

    # soa/structures.h
    ctypedef struct oarr_t:
        coeff_t* p_data
        bases_t nbases
        bases_t nact
        ord_t trc_order
        ord_t act_order
        uint64_t nrows
        uint64_t ncols
        uint64_t size

    ctypedef struct oarr_lu_t:
        oarr_t A
        int* p_ipiv


    # soa/base.h
    uint64_t oarr_block_index(bases_t k, ord_t p, ndir_t i)
    oarr_t oarr_init()
    int oarr_zeros_to(bases_t nact, uint64_t nrows, uint64_t ncols, ord_t trc_order, oarr_t* res)
    int oarr_from_real_to(const coeff_t* data, uint64_t nrows, uint64_t ncols, ord_t trc_order,
                          oarr_t* res)
    int oarr_eye_to(uint64_t n, ord_t trc_order, oarr_t* res)
    int oarr_reserve(oarr_t* arr, bases_t cap, uint64_t nrows, uint64_t ncols, ord_t trc_order)
    void oarr_free(oarr_t* arr)
    int oarr_copy_to(const oarr_t* arr, oarr_t* res)
    int oarr_add_bases(bases_t nact, oarr_t* arr)
    void oarr_kernel_expand(const oarr_t* arr, bases_t ku, ord_t trc, coeff_t* dst)
    coeff_t* oarr_get_block(imdir_t idx, ord_t order, const oarr_t* arr)
    int oarr_get_item_to(uint64_t i, uint64_t j, const oarr_t* arr, otinum_t* res)
    int oarr_set_item(const otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr)
    int oarr_set_item_r(coeff_t val, uint64_t i, uint64_t j, oarr_t* arr)
    double oarr_density(const oarr_t* arr)
    size_t oarr_memory_size(const oarr_t* arr)
    int oarr_from_arrso_to(const arrso_t* arr, oarr_t* res, dhelpl_t dhl)
    arrso_t oarr_to_arrso(const oarr_t* arr, dhelpl_t dhl)
    int oarr_truncate_im_to(imdir_t idx, ord_t order, const oarr_t* arr, oarr_t* res)
    int oarr_truncate_order_to(ord_t order, const oarr_t* arr, oarr_t* res)
    int oarr_get_order_im_to(ord_t order, const oarr_t* arr, oarr_t* res)
    int oarr_compact_to(const oarr_t* arr, oarr_t* res)

    # soa/algebra.h
    void oarr_kernel_mul_acc(const coeff_t* A, ord_t alo, ord_t ahi, const coeff_t* B, ord_t blo,
                             ord_t bhi, bases_t k, ord_t trc, uint64_t m, uint64_t e0, uint64_t e1,
                             coeff_t* R, dhelpl_t dhl)
    int oarr_kernel_matmul_acc(const coeff_t* A, ord_t alo, ord_t ahi, const coeff_t* B, ord_t blo,
                               ord_t bhi, bases_t k, ord_t trc, uint64_t nrows, uint64_t ninner,
                               uint64_t ncols, coeff_t alpha, coeff_t* R, coeff_t* work, dhelpl_t dhl)
    int oarr_sum_OO_to(const oarr_t* arr1, const oarr_t* arr2, oarr_t* res, dhelpl_t dhl)
    int oarr_sum_oO_to(const otinum_t* num, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_sum_rO_to(coeff_t val, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_sub_OO_to(const oarr_t* arr1, const oarr_t* arr2, oarr_t* res, dhelpl_t dhl)
    int oarr_sub_oO_to(const otinum_t* num, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_sub_rO_to(coeff_t val, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_sub_Oo_to(const oarr_t* arr1, const otinum_t* num, oarr_t* res, dhelpl_t dhl)
    int oarr_sub_Or_to(const oarr_t* arr1, coeff_t val, oarr_t* res, dhelpl_t dhl)
    int oarr_mul_OO_to(const oarr_t* arr1, const oarr_t* arr2, oarr_t* res, dhelpl_t dhl)
    int oarr_mul_oO_to(const otinum_t* num, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_mul_rO_to(coeff_t val, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_div_OO_to(const oarr_t* arr1, const oarr_t* arr2, oarr_t* res, dhelpl_t dhl)
    int oarr_div_oO_to(const otinum_t* num, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_div_rO_to(coeff_t val, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_div_Oo_to(const oarr_t* arr1, const otinum_t* num, oarr_t* res, dhelpl_t dhl)
    int oarr_div_Or_to(const oarr_t* arr1, coeff_t val, oarr_t* res, dhelpl_t dhl)
    int oarr_neg_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_feval_to(const coeff_t* derivs, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_exp_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_log_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_log10_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_sqrt_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_cbrt_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_sin_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_cos_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_tan_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_asin_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_acos_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_atan_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_sinh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_cosh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_tanh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_asinh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_acosh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_atanh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_erf_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)
    int oarr_pow_to(const oarr_t* arr1, coeff_t e, oarr_t* res, dhelpl_t dhl)
    int oarr_matmul_OO_to(const oarr_t* arr1, const oarr_t* arr2, oarr_t* res, dhelpl_t dhl)
    int oarr_transpose_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl)

    # soa/linalg.h
    int oarr_lu_factor(const oarr_t* A, oarr_lu_t* lu)
    void oarr_lu_free(oarr_lu_t* lu)
    int oarr_lu_solve(const oarr_lu_t* lu, const oarr_t* b, oarr_t* x, dhelpl_t dhl)
    int oarr_solve_to(const oarr_t* K, const oarr_t* b, oarr_t* x, dhelpl_t dhl)
    int oarr_inv_to(const oarr_t* A, oarr_t* res, dhelpl_t dhl)
    int oarr_det_to(const oarr_t* A, otinum_t* res, dhelpl_t dhl)

    # aos/aos.h
    ctypedef struct arro_t:
        otinum_t* p_data
        uint64_t nrows
        uint64_t ncols
        uint64_t size

    arro_t arro_init()
    int arro_zeros_to(uint64_t nrows, uint64_t ncols, ord_t trc_order, arro_t* res)
    int arro_resize(uint64_t nrows, uint64_t ncols, ord_t trc_order, arro_t* arr)
    void arro_free(arro_t* arr)
    int arro_copy_to(const arro_t* arr1, arro_t* res)
    const otinum_t* arro_get_item_ptr(uint64_t i, uint64_t j, const arro_t* arr1)
    int arro_set_item(const otinum_t* num, uint64_t i, uint64_t j, arro_t* arr1)
    int arro_set_item_r(coeff_t val, uint64_t i, uint64_t j, arro_t* arr1)
    int arro_from_arrso_to(const arrso_t* arr1, arro_t* res, dhelpl_t dhl)
    arrso_t arro_to_arrso(const arro_t* arr1, dhelpl_t dhl)
    int arro_to_oarr(const arro_t* arr1, oarr_t* res)
    int arro_from_oarr(const oarr_t* arr1, arro_t* res)
    int arro_sum_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl)
    int arro_sum_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_sum_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_sub_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl)
    int arro_sub_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_sub_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_sub_Oo_to(const arro_t* arr1, const otinum_t* num, arro_t* res, dhelpl_t dhl)
    int arro_sub_Or_to(const arro_t* arr1, coeff_t val, arro_t* res, dhelpl_t dhl)
    int arro_mul_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl)
    int arro_mul_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_mul_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_div_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl)
    int arro_div_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_div_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_div_Oo_to(const arro_t* arr1, const otinum_t* num, arro_t* res, dhelpl_t dhl)
    int arro_div_Or_to(const arro_t* arr1, coeff_t val, arro_t* res, dhelpl_t dhl)
    int arro_neg_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_exp_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_log_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_log10_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_sqrt_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_cbrt_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_sin_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_cos_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_tan_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_asin_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_acos_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_atan_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_sinh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_cosh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_tanh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_asinh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_acosh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_atanh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_erf_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_pow_to(const arro_t* arr1, coeff_t ex, arro_t* res, dhelpl_t dhl)
    int arro_truncate_im_to(imdir_t idx, ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_truncate_order_to(ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_get_order_im_to(ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_compact_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl)
    int arro_matmul_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl)
    int arro_transpose_to(const arro_t* arr1, arro_t* res)
    int arro_solve_to(const arro_t* K, const arro_t* b, arro_t* x, dhelpl_t dhl)
    int arro_inv_to(const arro_t* A, arro_t* res, dhelpl_t dhl)
    int arro_det_to(const arro_t* A, otinum_t* res, dhelpl_t dhl)
