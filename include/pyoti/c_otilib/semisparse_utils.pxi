# Semi-sparse C declarations, Phase 2: order/derivative plumbing, trunc_dot/trunc_sub/dot_product,
# rom_eval, interp1d, inv_block (PLAN-semisparse-sparse-leveling.md). Declare against "oti/semisparse.h".
cdef extern from "oti/semisparse.h":

    # Scalars (include/oti/semisparse/scalar/utils.h).
    ssotinum_t ssoti_extract_im(imdir_t idx, ord_t order, const ssotinum_t *num)
    void ssoti_extract_im_to(imdir_t idx, ord_t order, const ssotinum_t *num, ssotinum_t *res)
    ssotinum_t ssoti_extract_deriv(imdir_t idx, ord_t order, const ssotinum_t *num)
    void ssoti_extract_deriv_to(imdir_t idx, ord_t order, const ssotinum_t *num,
                                ssotinum_t *res)
    void ssoti_trunc_sub_to(ord_t order, const ssotinum_t *num1, const ssotinum_t *num2,
                            ssotinum_t *res)
    coeff_t ssoti_rom_eval(const ssotinum_t *num, const coeff_t *deltas)
    int ssoti_rom_eval_points(const ssotinum_t *num, const coeff_t *deltas, uint64_t npts,
                              coeff_t *out)
    void ssoti_get_all_ims_to(const ssotinum_t *num, bases_t nbasis, ord_t order, int derivs,
                              coeff_t *out, uint64_t stride)
    bases_t ssoti_order_max_base(ord_t p, const ssotinum_t *num)
    void ssoti_scatter_order_im(ord_t p, const ssotinum_t *num, ndir_t width, coeff_t *out,
                                uint64_t stride)
    void ssoti_add_order_im_global(ord_t p, const coeff_t *vals, ndir_t nvals, uint64_t stride,
                                   ssotinum_t *num)

    # SoA arrays (include/oti/semisparse/soa/utils.h).
    void oarrss_extract_im_to(imdir_t idx, ord_t order, const oarrss_t *arr, oarrss_t *res)
    void oarrss_extract_deriv_to(imdir_t idx, ord_t order, const oarrss_t *arr, oarrss_t *res)
    int oarrss_trunc_matmul_OO_to(ord_t orda, const oarrss_t *A, ord_t ordb, const oarrss_t *B,
                                  oarrss_t *res, dhelpl_t dhl)
    int oarrss_trunc_sub_OO_to(ord_t order, const oarrss_t *A, const oarrss_t *B, oarrss_t *res)
    int oarrss_dot_product_OO_to(const oarrss_t *A, const oarrss_t *B, ssotinum_t *res,
                                 dhelpl_t dhl)
    void oarrss_rom_eval_to(const oarrss_t *arr, const coeff_t *deltas, oarrss_t *res)
    void oarrss_get_all_ims_to(const oarrss_t *arr, bases_t nbasis, ord_t order, int derivs,
                               coeff_t *out)
    bases_t oarrss_order_max_base(ord_t p, const oarrss_t *arr)
    void oarrss_get_order_im_array_to(ord_t p, const oarrss_t *arr, ndir_t width, coeff_t *out)
    void oarrss_add_order_im_array(ord_t p, const coeff_t *inp, ndir_t width, oarrss_t *arr)
    int oarrss_moving_average_to(const oarrss_t *arr, uint64_t size, oarrss_t *res)
    int oarrss_interp1d_o_to(const oarrss_t *xvals, const oarrss_t *yvals, const ssotinum_t *x,
                             ssotinum_t *res, dhelpl_t dhl)
    int oarrss_interp1d_O_to(const oarrss_t *xvals, const oarrss_t *yvals, const oarrss_t *X,
                             oarrss_t *res, dhelpl_t dhl)
