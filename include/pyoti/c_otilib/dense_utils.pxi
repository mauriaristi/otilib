# Dense C declarations: order and derivative plumbing, truncated products, rom_eval, interp1d.
# GENERATED from include/oti/dense/**/*.h (PLAN-dense-update.md) by
# tools/gen_dense_pxi.py; re-run it when a dense header changes.
# Do not edit by hand.
cdef extern from "oti/dense.h" nogil:

    # scalar/utils.h
    coeff_t dnutil_tuple_factor(const bases_t* u, ord_t p)
    void dnutil_merge_tuples(const bases_t* a, ord_t p, const bases_t* b, ord_t q, bases_t* out)
    int dnutil_dir_inside(imdir_t idx, ord_t order, bases_t nact)
    otinum_t oti_extract_im(imdir_t idx, ord_t order, const otinum_t* num)
    int oti_extract_im_to(imdir_t idx, ord_t order, const otinum_t* num, otinum_t* res)
    otinum_t oti_extract_deriv(imdir_t idx, ord_t order, const otinum_t* num)
    int oti_extract_deriv_to(imdir_t idx, ord_t order, const otinum_t* num, otinum_t* res)
    int oti_trunc_sub_to(ord_t order, const otinum_t* num1, const otinum_t* num2, otinum_t* res)
    coeff_t oti_rom_eval(const otinum_t* num, const coeff_t* deltas)
    int oti_rom_eval_points(const otinum_t* num, const coeff_t* deltas, uint64_t npts, coeff_t* out)
    void oti_get_all_ims_to(const otinum_t* num, bases_t nbasis, ord_t order, int derivs, coeff_t* out,
                            uint64_t stride)
    bases_t oti_order_max_base(ord_t p, const otinum_t* num)
    void oti_scatter_order_im(ord_t p, const otinum_t* num, ndir_t width, coeff_t* out, uint64_t stride)
    int oti_add_order_im_global(ord_t p, const coeff_t* vals, ndir_t nvals, uint64_t stride,
                                otinum_t* num)

    # soa/utils.h
    int oarr_extract_im_to(imdir_t idx, ord_t order, const oarr_t* arr, oarr_t* res)
    int oarr_extract_deriv_to(imdir_t idx, ord_t order, const oarr_t* arr, oarr_t* res)
    int oarr_trunc_matmul_OO_to(ord_t orda, const oarr_t* A, ord_t ordb, const oarr_t* B, oarr_t* res,
                                dhelpl_t dhl)
    int oarr_trunc_sub_OO_to(ord_t order, const oarr_t* A, const oarr_t* B, oarr_t* res)
    int oarr_dot_product_OO_to(const oarr_t* A, const oarr_t* B, otinum_t* res, dhelpl_t dhl)
    int oarr_rom_eval_to(const oarr_t* arr, const coeff_t* deltas, oarr_t* res)
    int oarr_get_all_ims_to(const oarr_t* arr, bases_t nbasis, ord_t order, int derivs, coeff_t* out)
    bases_t oarr_order_max_base(ord_t p, const oarr_t* arr)
    int oarr_get_order_im_array_to(ord_t p, const oarr_t* arr, ndir_t width, coeff_t* out)
    int oarr_add_order_im_array(ord_t p, const coeff_t* vals, ndir_t width, oarr_t* arr)
    int oarr_moving_average_to(const oarr_t* arr, uint64_t size, oarr_t* res)
    int oarr_interp1d_o_to(const oarr_t* xvals, const oarr_t* yvals, const otinum_t* x, otinum_t* res,
                           dhelpl_t dhl)
    int oarr_interp1d_O_to(const oarr_t* xvals, const oarr_t* yvals, const oarr_t* X, oarr_t* res,
                           dhelpl_t dhl)
