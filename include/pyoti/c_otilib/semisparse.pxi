# Semi-sparse scalar and SoA declarations; the AoS binding awaits step 4.
cdef extern from "oti/core/semisparse.h":
    ctypedef struct sshelp_pair_t:
        const imdir_t *p_tab
        uint64_t stride
        int transpose

    ctypedef struct sshelp_rank_tab_t:
        ndir_t *p_c
        bases_t k
        ord_t n

    ctypedef struct sshelp_ws_t:
        coeff_t *p_coef
        ndir_t *p_map
        bases_t *p_bases
        size_t ncoef
        size_t nmap
        size_t nbases

    int sshelp_ndir_total_checked(bases_t k, ord_t n, ndir_t *nimag)
    bases_t sshelp_union_bases(const bases_t *a, bases_t na, const bases_t *b, bases_t nb,
                               bases_t *res, bases_t *pos_a, bases_t *pos_b)
    int sshelp_rank_tab_init(sshelp_rank_tab_t *tab, bases_t k, ord_t n)
    void sshelp_rank_tab_free(sshelp_rank_tab_t *tab)
    void sshelp_unrank(ndir_t idx, ord_t p, bases_t *u)
    void sshelp_local_dirs(bases_t k, ord_t p, bases_t *out)
    void sshelp_remap_order(bases_t k, const bases_t *pos, ord_t p,
                            const sshelp_rank_tab_t *tab, ndir_t *mapping, bases_t *u)
    imdir_t sshelp_global_rank(const bases_t *g, ord_t p)
    int sshelp_global_unrank(imdir_t idx, ord_t p, bases_t *g)
    int sshelp_local_to_global(ndir_t idx, ord_t p, const bases_t *bases, bases_t k,
                                imdir_t *global_idx)
    int sshelp_global_to_local(imdir_t idx, ord_t p, const bases_t *bases, bases_t k,
                                ndir_t *local_idx)
    sshelp_pair_t sshelp_get_pair(bases_t k, ord_t p, ord_t q, dhelpl_t dhl)
    sshelp_ws_t sshelp_ws_init()
    int sshelp_ws_reserve(sshelp_ws_t *ws, size_t ncoef, size_t nmap, size_t nbases)
    void sshelp_ws_free(sshelp_ws_t *ws)

cdef extern from "oti/semisparse.h":
    ctypedef struct ssotinum_t:
        coeff_t re
        coeff_t *p_im
        bases_t *p_bases
        bases_t nbases
        bases_t cap_bases
        ord_t act_order
        ord_t trc_order
        flag_t flag

    ctypedef struct oarrss_t:
        coeff_t *p_data
        bases_t *p_bases
        bases_t nbases
        bases_t cap_bases
        ord_t act_order
        ord_t trc_order
        uint64_t nrows
        uint64_t ncols
        uint64_t size
        flag_t flag

    ctypedef struct oarrss_lu_t:
        oarrss_t A
        int *p_ipiv

    ssotinum_t ssoti_init()
    ssotinum_t ssoti_create_empty(const bases_t *bases, bases_t k, ord_t order)
    ssotinum_t ssoti_create_r(coeff_t re, ord_t order)
    ssotinum_t ssoti_e(imdir_t idx, ord_t order, ord_t trc_order)
    void ssoti_reserve(ssotinum_t *num, bases_t cap, ord_t order)
    void ssoti_free(ssotinum_t *num)
    ssotinum_t ssoti_copy(const ssotinum_t *num)
    void ssoti_copy_to(const ssotinum_t *num, ssotinum_t *res)
    void ssoti_add_bases(const bases_t *bases, bases_t k, ssotinum_t *num)
    void ssoti_set_r(coeff_t re, ssotinum_t *num)
    coeff_t ssoti_get_item(imdir_t idx, ord_t order, const ssotinum_t *num)
    coeff_t ssoti_get_deriv(imdir_t idx, ord_t order, const ssotinum_t *num)
    void ssoti_set_item(coeff_t val, imdir_t idx, ord_t order, ssotinum_t *num)
    double ssoti_density(const ssotinum_t *num)
    size_t ssoti_memory_size(const ssotinum_t *num)
    void ssoti_print(const ssotinum_t *num)
    ssotinum_t ssoti_from_soti(const sotinum_t *num, dhelpl_t dhl)
    sotinum_t ssoti_to_soti(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_truncate_im(imdir_t idx, ord_t order, const ssotinum_t *num)
    void ssoti_truncate_im_to(imdir_t idx, ord_t order, const ssotinum_t *num,
                              ssotinum_t *res)
    ssotinum_t ssoti_truncate_order(ord_t order, const ssotinum_t *num)
    void ssoti_truncate_order_to(ord_t order, const ssotinum_t *num, ssotinum_t *res)
    ssotinum_t ssoti_get_order_im(ord_t order, const ssotinum_t *num)
    void ssoti_get_order_im_to(ord_t order, const ssotinum_t *num, ssotinum_t *res)
    ssotinum_t ssoti_compact(const ssotinum_t *num)
    void ssoti_compact_to(const ssotinum_t *num, ssotinum_t *res)
    sshelp_ws_t *ssoti_ws()
    void ssoti_ws_release()

    ssotinum_t ssoti_sum_oo(const ssotinum_t *a, const ssotinum_t *b, dhelpl_t dhl)
    ssotinum_t ssoti_sub_oo(const ssotinum_t *a, const ssotinum_t *b, dhelpl_t dhl)
    ssotinum_t ssoti_mul_oo(const ssotinum_t *a, const ssotinum_t *b, dhelpl_t dhl)
    ssotinum_t ssoti_div_oo(const ssotinum_t *a, const ssotinum_t *b, dhelpl_t dhl)
    ssotinum_t ssoti_neg(const ssotinum_t *num, dhelpl_t dhl)
    void ssoti_sum_oo_to(const ssotinum_t *a, const ssotinum_t *b, ssotinum_t *res,
                          dhelpl_t dhl)
    void ssoti_sub_oo_to(const ssotinum_t *a, const ssotinum_t *b, ssotinum_t *res,
                          dhelpl_t dhl)
    void ssoti_mul_oo_to(const ssotinum_t *a, const ssotinum_t *b, ssotinum_t *res,
                          dhelpl_t dhl)
    void ssoti_div_oo_to(const ssotinum_t *a, const ssotinum_t *b, ssotinum_t *res,
                          dhelpl_t dhl)
    void ssoti_gem_oo_to(const ssotinum_t *a, const ssotinum_t *b, const ssotinum_t *c,
                          ssotinum_t *res, dhelpl_t dhl)
    void ssoti_neg_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    ssotinum_t ssoti_sum_or(const ssotinum_t *num, coeff_t val, dhelpl_t dhl)
    ssotinum_t ssoti_sub_or(const ssotinum_t *num, coeff_t val, dhelpl_t dhl)
    ssotinum_t ssoti_sub_ro(coeff_t val, const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_mul_or(const ssotinum_t *num, coeff_t val, dhelpl_t dhl)
    ssotinum_t ssoti_div_or(const ssotinum_t *num, coeff_t val, dhelpl_t dhl)
    ssotinum_t ssoti_div_ro(coeff_t val, const ssotinum_t *num, dhelpl_t dhl)
    void ssoti_sum_or_to(const ssotinum_t *num, coeff_t val, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_sub_or_to(const ssotinum_t *num, coeff_t val, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_sub_ro_to(coeff_t val, const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_mul_or_to(const ssotinum_t *num, coeff_t val, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_div_or_to(const ssotinum_t *num, coeff_t val, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_div_ro_to(coeff_t val, const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_kernel_mul_acc(const coeff_t *a, ord_t alo, ord_t ahi, const coeff_t *b,
                               ord_t blo, ord_t bhi, bases_t k, ord_t trc, coeff_t *res,
                               dhelpl_t dhl)
    void ssoti_kernel_expand(const ssotinum_t *num, const bases_t *pos, bases_t k,
                              ord_t trc, coeff_t *res)
    ssotinum_t ssoti_feval(const coeff_t *derivs, const ssotinum_t *num, dhelpl_t dhl)
    void ssoti_feval_to(const coeff_t *derivs, const ssotinum_t *num, ssotinum_t *res,
                        dhelpl_t dhl)
    ssotinum_t ssoti_pow(const ssotinum_t *num, coeff_t e, dhelpl_t dhl)
    ssotinum_t ssoti_logb(const ssotinum_t *num, coeff_t base, dhelpl_t dhl)
    ssotinum_t ssoti_exp(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_log(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_log10(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_sqrt(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_cbrt(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_sin(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_cos(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_tan(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_asin(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_acos(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_atan(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_sinh(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_cosh(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_tanh(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_asinh(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_acosh(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_atanh(const ssotinum_t *num, dhelpl_t dhl)
    ssotinum_t ssoti_erf(const ssotinum_t *num, dhelpl_t dhl)
    void ssoti_exp_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_log_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_log10_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_sqrt_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_cbrt_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_sin_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_cos_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_tan_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_asin_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_acos_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_atan_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_sinh_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_cosh_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_tanh_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_asinh_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_acosh_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_atanh_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_erf_to(const ssotinum_t *num, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_pow_to(const ssotinum_t *num, coeff_t e, ssotinum_t *res, dhelpl_t dhl)
    void ssoti_logb_to(const ssotinum_t *num, coeff_t base, ssotinum_t *res, dhelpl_t dhl)

    oarrss_t oarrss_init()
    oarrss_t oarrss_zeros(const bases_t *bases, bases_t k, uint64_t rows, uint64_t cols,
                          ord_t order)
    oarrss_t oarrss_from_real(const coeff_t *data, uint64_t rows, uint64_t cols, ord_t order)
    oarrss_t oarrss_eye(uint64_t n, ord_t order)
    void oarrss_reserve(oarrss_t *arr, bases_t cap, uint64_t rows, uint64_t cols, ord_t order)
    void oarrss_free(oarrss_t *arr)
    oarrss_t oarrss_copy(const oarrss_t *arr)
    void oarrss_copy_to(const oarrss_t *arr, oarrss_t *res)
    void oarrss_add_bases(const bases_t *bases, bases_t k, oarrss_t *arr)
    void oarrss_kernel_expand(const oarrss_t *arr, const bases_t *pos, bases_t k,
                               ord_t trc, coeff_t *dst)
    coeff_t *oarrss_get_block(imdir_t idx, ord_t order, const oarrss_t *arr)
    ssotinum_t oarrss_get_item(uint64_t i, uint64_t j, const oarrss_t *arr)
    void oarrss_get_item_to(uint64_t i, uint64_t j, const oarrss_t *arr, ssotinum_t *res)
    void oarrss_set_item(const ssotinum_t *num, uint64_t i, uint64_t j, oarrss_t *arr)
    void oarrss_set_item_r(coeff_t val, uint64_t i, uint64_t j, oarrss_t *arr)
    double oarrss_density(const oarrss_t *arr)
    size_t oarrss_memory_size(const oarrss_t *arr)
    oarrss_t oarrss_from_arrso(const arrso_t *arr, dhelpl_t dhl)
    arrso_t oarrss_to_arrso(const oarrss_t *arr, dhelpl_t dhl)
    void oarrss_truncate_im_to(imdir_t idx, ord_t order, const oarrss_t *arr, oarrss_t *res)
    void oarrss_truncate_order_to(ord_t order, const oarrss_t *arr, oarrss_t *res)
    void oarrss_get_order_im_to(ord_t order, const oarrss_t *arr, oarrss_t *res)
    void oarrss_compact_to(const oarrss_t *arr, oarrss_t *res)

    void oarrss_sum_OO_to(const oarrss_t *a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_sum_oO_to(const ssotinum_t *a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_sum_rO_to(coeff_t a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_sub_OO_to(const oarrss_t *a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_sub_oO_to(const ssotinum_t *a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_sub_Oo_to(const oarrss_t *a, const ssotinum_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_sub_rO_to(coeff_t a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_sub_Or_to(const oarrss_t *a, coeff_t b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_mul_OO_to(const oarrss_t *a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_mul_oO_to(const ssotinum_t *a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_mul_rO_to(coeff_t a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_div_OO_to(const oarrss_t *a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_div_oO_to(const ssotinum_t *a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_div_Oo_to(const oarrss_t *a, const ssotinum_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_div_rO_to(coeff_t a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_div_Or_to(const oarrss_t *a, coeff_t b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_neg_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_kernel_mul_acc(const coeff_t *a, ord_t alo, ord_t ahi, const coeff_t *b,
                                ord_t blo, ord_t bhi, bases_t k, ord_t trc, uint64_t size,
                                uint64_t begin, uint64_t end, coeff_t *res, dhelpl_t dhl)
    int oarrss_kernel_matmul_acc(const coeff_t *a, ord_t alo, ord_t ahi, const coeff_t *b,
                                  ord_t blo, ord_t bhi, bases_t k, ord_t trc, uint64_t rows,
                                  uint64_t inner, uint64_t cols, coeff_t alpha, coeff_t *res,
                                  coeff_t *work, dhelpl_t dhl)
    void oarrss_feval_to(const coeff_t *derivs, const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_pow_to(const oarrss_t *a, coeff_t e, oarrss_t *res, dhelpl_t dhl)
    void oarrss_exp_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_log_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_log10_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_sqrt_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_cbrt_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_sin_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_cos_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_tan_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_asin_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_acos_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_atan_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_sinh_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_cosh_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_tanh_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_asinh_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_acosh_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_atanh_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    void oarrss_erf_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    int oarrss_matmul_OO_to(const oarrss_t *a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    void oarrss_transpose_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)

    int oarrss_lu_factor(const oarrss_t *a, oarrss_lu_t *lu)
    void oarrss_lu_free(oarrss_lu_t *lu)
    int oarrss_lu_solve(const oarrss_lu_t *lu, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    int oarrss_solve_to(const oarrss_t *a, const oarrss_t *b, oarrss_t *res, dhelpl_t dhl)
    int oarrss_inv_to(const oarrss_t *a, oarrss_t *res, dhelpl_t dhl)
    int oarrss_det_to(const oarrss_t *a, ssotinum_t *res, dhelpl_t dhl)

    ctypedef struct arrss_t:
        ssotinum_t *p_data
        uint64_t nrows
        uint64_t ncols
        uint64_t size
        flag_t flag

    arrss_t arrss_init()
    arrss_t arrss_zeros(uint64_t rows, uint64_t cols, ord_t order)
    void arrss_resize(uint64_t rows, uint64_t cols, ord_t order, arrss_t *arr)
    void arrss_free(arrss_t *arr)
    arrss_t arrss_copy(const arrss_t *arr)
    void arrss_copy_to(const arrss_t *arr, arrss_t *res)
    const ssotinum_t *arrss_get_item_ptr(uint64_t i, uint64_t j, const arrss_t *arr)
    void arrss_set_item(const ssotinum_t *num, uint64_t i, uint64_t j, arrss_t *arr)
    void arrss_set_item_r(coeff_t value, uint64_t i, uint64_t j, arrss_t *arr)
    arrss_t arrss_from_arrso(const arrso_t *arr, dhelpl_t dhl)
    arrso_t arrss_to_arrso(const arrss_t *arr, dhelpl_t dhl)
    void arrss_to_oarrss(const arrss_t *arr, oarrss_t *res)
    void arrss_from_oarrss(const oarrss_t *arr, arrss_t *res)
    void arrss_sum_OO_to(const arrss_t *a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_sum_oO_to(const ssotinum_t *a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_sum_rO_to(coeff_t a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_sub_OO_to(const arrss_t *a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_sub_oO_to(const ssotinum_t *a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_sub_Oo_to(const arrss_t *a, const ssotinum_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_sub_rO_to(coeff_t a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_sub_Or_to(const arrss_t *a, coeff_t b, arrss_t *res, dhelpl_t dhl)
    void arrss_mul_OO_to(const arrss_t *a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_mul_oO_to(const ssotinum_t *a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_mul_rO_to(coeff_t a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_div_OO_to(const arrss_t *a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_div_oO_to(const ssotinum_t *a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_div_Oo_to(const arrss_t *a, const ssotinum_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_div_rO_to(coeff_t a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_div_Or_to(const arrss_t *a, coeff_t b, arrss_t *res, dhelpl_t dhl)
    void arrss_neg_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_exp_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_log_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_log10_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_sqrt_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_cbrt_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_sin_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_cos_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_tan_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_asin_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_acos_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_atan_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_sinh_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_cosh_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_tanh_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_asinh_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_acosh_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_atanh_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_erf_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_pow_to(const arrss_t *a, coeff_t exponent, arrss_t *res, dhelpl_t dhl)
    void arrss_truncate_im_to(imdir_t idx, ord_t order, const arrss_t *a, arrss_t *res,
                               dhelpl_t dhl)
    void arrss_truncate_order_to(ord_t order, const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_get_order_im_to(ord_t order, const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_compact_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    void arrss_matmul_OO_to(const arrss_t *a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    void arrss_transpose_to(const arrss_t *a, arrss_t *res)
    int arrss_solve_to(const arrss_t *a, const arrss_t *b, arrss_t *res, dhelpl_t dhl)
    int arrss_inv_to(const arrss_t *a, arrss_t *res, dhelpl_t dhl)
    int arrss_det_to(const arrss_t *a, ssotinum_t *res, dhelpl_t dhl)
