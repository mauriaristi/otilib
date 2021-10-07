cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm1n30/scalar/structures.h
  
  ctypedef struct  onumm1n30_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e11;
    coeff_t e111;
    coeff_t e1111;
    coeff_t e11111;
    coeff_t e111111;
    coeff_t e1111111;
    coeff_t e11111111;
    coeff_t e111111111;
    coeff_t e1111111111;
    coeff_t e11111111111;
    coeff_t e111111111111;
    coeff_t e1111111111111;
    coeff_t e11111111111111;
    coeff_t e111111111111111;
    coeff_t e1111111111111111;
    coeff_t e11111111111111111;
    coeff_t e111111111111111111;
    coeff_t e1111111111111111111;
    coeff_t e11111111111111111111;
    coeff_t e111111111111111111111;
    coeff_t e1111111111111111111111;
    coeff_t e11111111111111111111111;
    coeff_t e111111111111111111111111;
    coeff_t e1111111111111111111111111;
    coeff_t e11111111111111111111111111;
    coeff_t e111111111111111111111111111;
    coeff_t e1111111111111111111111111111;
    coeff_t e11111111111111111111111111111;
    coeff_t e111111111111111111111111111111;
  # } onumm1n30_t;
  
  
  # From ../../../include/oti/static/onumm1n30/array/structures.h
  
  ctypedef struct  oarrm1n30_t : # {
      onumm1n30_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm1n30_t;
  
  
  # From ../../../include/oti/static/onumm1n30/scalar/gauss/structures.h
  
  ctypedef struct  feonumm1n30_t: # {
      onumm1n30_t*  p_data;
      uint64_t    nip;
  # } feonumm1n30_t;
  
  
  # From ../../../include/oti/static/onumm1n30/array/gauss/structures.h
  
  ctypedef struct  feoarrm1n30_t: # {
      oarrm1n30_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm1n30_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm1n30/array/utils.h
  
  void oarrm1n30_dimCheck_OO_elementwise(oarrm1n30_t* arr1, oarrm1n30_t* arr2, oarrm1n30_t* res);
  void oarrm1n30_dimCheck_RO_elementwise(darr_t*  arr1, oarrm1n30_t* arr2, oarrm1n30_t* res);
  void oarrm1n30_dimCheck_OO_matmul(oarrm1n30_t* arr1, oarrm1n30_t* arr2, oarrm1n30_t* res);
  void oarrm1n30_dimCheck_RO_matmul(darr_t*  arr1, oarrm1n30_t* arr2, oarrm1n30_t* res);
  void oarrm1n30_dimCheck_OR_matmul(oarrm1n30_t* arr1, darr_t*  arr2, oarrm1n30_t* res);
  void oarrm1n30_dimCheck_O_squareness(oarrm1n30_t* arr1, oarrm1n30_t* res);
  void oarrm1n30_dimCheck_OO_samesize(oarrm1n30_t* arr1, oarrm1n30_t* res);
  void oarrm1n30_dimCheck_RO_samesize(darr_t* arr1, oarrm1n30_t* res);
  ord_t oarrm1n30_get_order(oarrm1n30_t* arr);
  void oarrm1n30_get_active_bases(oarrm1n30_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n30/array/algebra_elementwise.h
  
  oarrm1n30_t oarrm1n30_neg(oarrm1n30_t* arr);
  void oarrm1n30_neg_to(oarrm1n30_t* rhs, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_sum_OO(oarrm1n30_t*   lhs, oarrm1n30_t* rhs);
  oarrm1n30_t oarrm1n30_sum_RO(darr_t*    lhs, oarrm1n30_t* rhs);
  oarrm1n30_t oarrm1n30_sum_oO(onumm1n30_t* lhs, oarrm1n30_t* rhs);
  oarrm1n30_t oarrm1n30_sum_rO(coeff_t    lhs, oarrm1n30_t* rhs);
  void oarrm1n30_sum_OO_to(oarrm1n30_t*   lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
  void oarrm1n30_sum_RO_to(darr_t*    lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
  void oarrm1n30_sum_oO_to(onumm1n30_t* lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
  void oarrm1n30_sum_rO_to(coeff_t    lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
  void oarrm1n30_trunc_sum_OO_to(ord_t order, oarrm1n30_t* arr1, oarrm1n30_t* arr2, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_sub_OO(oarrm1n30_t*   lhs, oarrm1n30_t*   rhs);
  oarrm1n30_t oarrm1n30_sub_RO(darr_t*    lhs, oarrm1n30_t*   rhs);
  oarrm1n30_t oarrm1n30_sub_OR(oarrm1n30_t*   lhs, darr_t*    rhs);
  oarrm1n30_t oarrm1n30_sub_oO(onumm1n30_t* lhs, oarrm1n30_t*   rhs);
  oarrm1n30_t oarrm1n30_sub_Oo(oarrm1n30_t*   lhs, onumm1n30_t* rhs);
  oarrm1n30_t oarrm1n30_sub_rO(coeff_t    lhs, oarrm1n30_t*   rhs);
  oarrm1n30_t oarrm1n30_sub_Or(oarrm1n30_t*   lhs, coeff_t    rhs);
  void oarrm1n30_sub_OO_to( oarrm1n30_t*   lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
  void oarrm1n30_sub_RO_to( darr_t*    lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
  void oarrm1n30_sub_OR_to( oarrm1n30_t*   lhs, darr_t*    rhs, oarrm1n30_t* res);
  void oarrm1n30_sub_oO_to( onumm1n30_t* lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
  void oarrm1n30_sub_Oo_to( oarrm1n30_t*   lhs, onumm1n30_t* rhs, oarrm1n30_t* res);
  void oarrm1n30_sub_rO_to( coeff_t    lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
  void oarrm1n30_sub_Or_to( oarrm1n30_t*   lhs, coeff_t    rhs, oarrm1n30_t* res);
  void oarrm1n30_trunc_sub_OO_to(ord_t order, oarrm1n30_t* arr1, oarrm1n30_t* arr2, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_mul_OO(oarrm1n30_t*   lhs, oarrm1n30_t* rhs);
  oarrm1n30_t oarrm1n30_mul_RO(darr_t*    lhs, oarrm1n30_t* rhs);
  oarrm1n30_t oarrm1n30_mul_oO(onumm1n30_t* lhs, oarrm1n30_t* rhs);
  oarrm1n30_t oarrm1n30_mul_rO(coeff_t    lhs, oarrm1n30_t* rhs);
  void oarrm1n30_mul_OO_to(oarrm1n30_t*   lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
  void oarrm1n30_mul_RO_to(darr_t*    lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
  void oarrm1n30_mul_oO_to(onumm1n30_t* lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
  void oarrm1n30_mul_rO_to(coeff_t    lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
  void oarrm1n30_gem_OO_to(  oarrm1n30_t* arr1, oarrm1n30_t* arr2, oarrm1n30_t* arr3, oarrm1n30_t* res);
  void oarrm1n30_gem_oO_to(onumm1n30_t* arr1, oarrm1n30_t* arr2, oarrm1n30_t* arr3, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_div_OO(oarrm1n30_t*   lhs, oarrm1n30_t*   rhs);
  oarrm1n30_t oarrm1n30_div_OR(oarrm1n30_t*   lhs, darr_t*    rhs);
  oarrm1n30_t oarrm1n30_div_RO(darr_t*    lhs, oarrm1n30_t*   rhs);
  oarrm1n30_t oarrm1n30_div_oO(onumm1n30_t* lhs, oarrm1n30_t*   rhs);
  oarrm1n30_t oarrm1n30_div_Oo(oarrm1n30_t*   lhs, onumm1n30_t* rhs);
  oarrm1n30_t oarrm1n30_div_rO(coeff_t    lhs, oarrm1n30_t*   rhs);
  oarrm1n30_t oarrm1n30_div_Or(oarrm1n30_t*   lhs, coeff_t    rhs);
  void oarrm1n30_div_OO_to(oarrm1n30_t*   lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
  void oarrm1n30_div_RO_to(darr_t*    lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
  void oarrm1n30_div_OR_to(oarrm1n30_t*   lhs, darr_t*    rhs, oarrm1n30_t* res);
  void oarrm1n30_div_oO_to(onumm1n30_t* lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
  void oarrm1n30_div_Oo_to(oarrm1n30_t*   lhs, onumm1n30_t* rhs, oarrm1n30_t* res);
  void oarrm1n30_div_rO_to(coeff_t    lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
  void oarrm1n30_div_Or_to(oarrm1n30_t*   lhs, coeff_t    rhs, oarrm1n30_t* res);
  
  
  # From ../../../include/oti/static/onumm1n30/array/algebra_matops.h
  
  onumm1n30_t oarrm1n30_dotproduct_OO(    oarrm1n30_t* lhs, oarrm1n30_t* rhs);
  void      oarrm1n30_dotproduct_OO_to( oarrm1n30_t* lhs, oarrm1n30_t* rhs, onumm1n30_t* res);
  onumm1n30_t oarrm1n30_dotproduct_RO(     darr_t* lhs, oarrm1n30_t* rhs);
  void      oarrm1n30_dotproduct_RO_to(  darr_t* lhs, oarrm1n30_t* rhs, onumm1n30_t* res);
  oarrm1n30_t oarrm1n30_matmul_OO(    oarrm1n30_t* lhs, oarrm1n30_t* rhs);
  oarrm1n30_t oarrm1n30_matmul_OR(    oarrm1n30_t* lhs,  darr_t* rhs);
  oarrm1n30_t oarrm1n30_matmul_RO(     darr_t* lhs, oarrm1n30_t* rhs);
  void    oarrm1n30_matmul_OO_to( oarrm1n30_t* lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
  void    oarrm1n30_matmul_OR_to( oarrm1n30_t* lhs,  darr_t* rhs, oarrm1n30_t* res);
  void    oarrm1n30_matmul_RO_to(  darr_t* lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_transpose(    oarrm1n30_t* arr1);
  void    oarrm1n30_transpose_to( oarrm1n30_t* arr1, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_invert(    oarrm1n30_t* arr1);
  void    oarrm1n30_invert_to( oarrm1n30_t* arr1, oarrm1n30_t* res);
  onumm1n30_t oarrm1n30_det(    oarrm1n30_t* arr1);
  void      oarrm1n30_det_to( oarrm1n30_t* arr1, onumm1n30_t* res);
  onumm1n30_t oarrm1n30_norm(    oarrm1n30_t* arr1);
  void      oarrm1n30_norm_to( oarrm1n30_t* arr1,  onumm1n30_t* res);
  onumm1n30_t oarrm1n30_pnorm(    oarrm1n30_t* arr1, coeff_t p);
  void      oarrm1n30_pnorm_to( oarrm1n30_t* arr1, coeff_t p, onumm1n30_t* res);
  
  
  # From ../../../include/oti/static/onumm1n30/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm1n30/array/functions.h
  
  oarrm1n30_t oarrm1n30_atanh(   oarrm1n30_t* arr);
  void    oarrm1n30_atanh_to(oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_asinh(   oarrm1n30_t* arr);
  void    oarrm1n30_asinh_to(oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_acosh(   oarrm1n30_t* arr);
  void    oarrm1n30_acosh_to(oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_tanh(    oarrm1n30_t* arr);
  void    oarrm1n30_tanh_to( oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_cbrt(    oarrm1n30_t* arr);
  void    oarrm1n30_cbrt_to( oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_sqrt(    oarrm1n30_t* arr);
  void    oarrm1n30_sqrt_to( oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_cosh(    oarrm1n30_t* arr);
  void    oarrm1n30_cosh_to( oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_sinh(    oarrm1n30_t* arr);
  void    oarrm1n30_sinh_to( oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_asin(    oarrm1n30_t* arr);
  void    oarrm1n30_asin_to( oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_acos(    oarrm1n30_t* arr);
  void    oarrm1n30_acos_to( oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_atan(    oarrm1n30_t* arr);
  void    oarrm1n30_atan_to( oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_tan(     oarrm1n30_t* arr);
  void    oarrm1n30_tan_to(  oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_cos(     oarrm1n30_t* arr);
  void    oarrm1n30_cos_to(  oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_sin(     oarrm1n30_t* arr);
  void    oarrm1n30_sin_to(  oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_logb(    oarrm1n30_t* arr, double base);
  void    oarrm1n30_logb_to( oarrm1n30_t* arr, double base, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_log10(   oarrm1n30_t* arr);
  void    oarrm1n30_log10_to(oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_log(     oarrm1n30_t* arr);
  void    oarrm1n30_log_to(  oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_exp(     oarrm1n30_t* arr);
  void    oarrm1n30_exp_to(  oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_pow(     oarrm1n30_t* arr, double e);
  void    oarrm1n30_pow_to(  oarrm1n30_t* arr, double e, oarrm1n30_t* res);
  
  
  # From ../../../include/oti/static/onumm1n30/array/base.h
  
  void    oarrm1n30_taylor_integrate_to( coeff_t* deltas, oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_taylor_integrate(    coeff_t* deltas, oarrm1n30_t* arr);
  void    oarrm1n30_get_order_im_to( ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_get_order_im(    ord_t order, oarrm1n30_t* arr);
  void oarrm1n30_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n30_t* res);
  void oarrm1n30_set_slice_O( oarrm1n30_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n30_t* res);
  void oarrm1n30_set_slice_o( onumm1n30_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_get_slice( oarrm1n30_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm1n30_get_slice_to( oarrm1n30_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_truncate_im(    imdir_t idx, ord_t order, oarrm1n30_t* arr);
  void    oarrm1n30_truncate_im_to( imdir_t idx, ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_extract_im(   imdir_t idx, ord_t order, oarrm1n30_t* arr);
  void    oarrm1n30_extract_im_to(imdir_t idx, ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res);
  darr_t  oarrm1n30_get_deriv(    imdir_t idx, ord_t order, oarrm1n30_t* arr);
  void    oarrm1n30_get_deriv_to( imdir_t idx, ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_get_deriv_o(  imdir_t idx, ord_t order, oarrm1n30_t* arr);
  oarrm1n30_t oarrm1n30_extract_deriv(    imdir_t idx, ord_t order, oarrm1n30_t* arr);
  void    oarrm1n30_extract_deriv_to( imdir_t idx, ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res);
  darr_t  oarrm1n30_get_im(   imdir_t idx, ord_t order, oarrm1n30_t* arr);
  oarrm1n30_t oarrm1n30_get_im_o( imdir_t idx, ord_t order, oarrm1n30_t* arr);
  void    oarrm1n30_get_im_to(imdir_t idx, ord_t order, oarrm1n30_t* arr, oarrm1n30_t* res);
  void    oarrm1n30_copy_to(oarrm1n30_t* arr, oarrm1n30_t* res);
  oarrm1n30_t oarrm1n30_copy(oarrm1n30_t* arr);
  void oarrm1n30_set_all_r( coeff_t num, oarrm1n30_t* arr);
  void oarrm1n30_set_item_i_r( coeff_t num, uint64_t i, oarrm1n30_t* arr);
  void oarrm1n30_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm1n30_t* arr);
  void oarrm1n30_set_r(   coeff_t  num,   oarrm1n30_t* arr);
  void oarrm1n30_set_o( onumm1n30_t* num,   oarrm1n30_t* arr);
  void oarrm1n30_set_O(   oarrm1n30_t* arrin, oarrm1n30_t* arr);
  void oarrm1n30_set_all_o( onumm1n30_t* src, oarrm1n30_t* arr);
  void oarrm1n30_set_item_i_o( onumm1n30_t* num, uint64_t i, oarrm1n30_t* arr);
  void oarrm1n30_set_item_ij_o( onumm1n30_t* num, uint64_t i, uint64_t j, oarrm1n30_t* arr);
  onumm1n30_t oarrm1n30_get_item_i(    oarrm1n30_t* arr, uint64_t i);
  void      oarrm1n30_get_item_i_to( oarrm1n30_t* arr, uint64_t i,             onumm1n30_t* res);
  onumm1n30_t oarrm1n30_get_item_ij(   oarrm1n30_t* arr, uint64_t i, uint64_t j);
  void      oarrm1n30_get_item_ij_to(oarrm1n30_t* arr, uint64_t i, uint64_t j, onumm1n30_t* res);
  oarrm1n30_t oarrm1n30_init();
  void oarrm1n30_free(oarrm1n30_t* arr);
  oarrm1n30_t oarrm1n30_empty_like(oarrm1n30_t* arr);
  oarrm1n30_t oarrm1n30_eye(uint64_t nrows);
  oarrm1n30_t oarrm1n30_ones(uint64_t nrows, uint64_t ncols);
  oarrm1n30_t oarrm1n30_zeros(uint64_t nrows, uint64_t ncols);
  oarrm1n30_t oarrm1n30_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm1n30/array/gauss/utils.h
  
  void feoarrm1n30_dimCheck_FF_samesize(feoarrm1n30_t* arr1, feoarrm1n30_t* arr2, feonumm1n30_t* res);
  void feoarrm1n30_dimCheck_OF_samesize(  oarrm1n30_t* arr1, feoarrm1n30_t* arr2, feonumm1n30_t* res);
  void feoarrm1n30_dimCheck_RF_samesize(   darr_t* arr1, feoarrm1n30_t* arr2, feonumm1n30_t* res);
  void feoarrm1n30_dimCheck_FF_elementwise(feoarrm1n30_t* arr1, feoarrm1n30_t* arr2, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_OF_elementwise(  oarrm1n30_t* arr1, feoarrm1n30_t* arr2, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm1n30_t* arr2, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_fF_elementwise( feonumm1n30_t* num1, feoarrm1n30_t* arr2, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_Ff_elementwise(feoarrm1n30_t* arr1,  feonumm1n30_t* num2, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_FF_matmul( feoarrm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_OF_matmul(   oarrm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_RF_matmul(    darr_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_FO_matmul( feoarrm1n30_t* lhs,   oarrm1n30_t* rhs, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_FR_matmul( feoarrm1n30_t* lhs,    darr_t* rhs, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_F_squareness( feoarrm1n30_t* arr1, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_F_transpose( feoarrm1n30_t* arr1, feoarrm1n30_t* res);
  void feoarrm1n30_dimCheck_FfO_integrate(feoarrm1n30_t* arr, feonumm1n30_t* num,oarrm1n30_t* res);
  void feoarrm1n30_get_active_bases(feoarrm1n30_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n30/array/gauss/algebra.h
  
  feoarrm1n30_t feoarrm1n30_neg(    feoarrm1n30_t* arr);
  void      feoarrm1n30_neg_to( feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sum_FF(   feoarrm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sum_FF_to(feoarrm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sum_fF(    feonumm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sum_fF_to( feonumm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sum_OF(     oarrm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sum_OF_to(  oarrm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sum_RF(      darr_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sum_RF_to(   darr_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sum_oF(   onumm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sum_oF_to(onumm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sum_rF(     coeff_t  lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sum_rF_to(  coeff_t  lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sub_FF(    feoarrm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sub_FF_to( feoarrm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sub_fF(    feonumm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sub_fF_to( feonumm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sub_Ff(    feoarrm1n30_t* lhs, feonumm1n30_t* rhs);
  void      feoarrm1n30_sub_Ff_to( feoarrm1n30_t* lhs, feonumm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sub_OF(      oarrm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sub_OF_to(   oarrm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sub_FO(    feoarrm1n30_t* lhs,   oarrm1n30_t* rhs);
  void      feoarrm1n30_sub_FO_to( feoarrm1n30_t* lhs,   oarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sub_RF(       darr_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sub_RF_to(    darr_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sub_FR(    feoarrm1n30_t* lhs,    darr_t* rhs);
  void      feoarrm1n30_sub_FR_to( feoarrm1n30_t* lhs,    darr_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sub_oF(    onumm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sub_oF_to( onumm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sub_Fo(    feoarrm1n30_t* lhs, onumm1n30_t* rhs);
  void      feoarrm1n30_sub_Fo_to( feoarrm1n30_t* lhs, onumm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sub_rF(      coeff_t  lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_sub_rF_to(    coeff_t lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sub_Fr(    feoarrm1n30_t* lhs,   coeff_t  rhs);
  void      feoarrm1n30_sub_Fr_to( feoarrm1n30_t* lhs,   coeff_t  rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_mul_FF(   feoarrm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_mul_FF_to(feoarrm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_mul_fF(    feonumm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_mul_fF_to( feonumm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_mul_OF(     oarrm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_mul_OF_to(  oarrm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_mul_RF(      darr_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_mul_RF_to(   darr_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_mul_oF(   onumm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_mul_oF_to(onumm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_mul_rF(     coeff_t  lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_mul_rF_to(  coeff_t  lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_div_FF(    feoarrm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_div_FF_to( feoarrm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_div_fF(     feonumm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_div_fF_to(  feonumm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_div_Ff(    feoarrm1n30_t* lhs,  feonumm1n30_t* rhs);
  void      feoarrm1n30_div_Ff_to( feoarrm1n30_t* lhs,  feonumm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_div_OF(      oarrm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_div_OF_to(   oarrm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_div_FO(    feoarrm1n30_t* lhs,   oarrm1n30_t* rhs);
  void      feoarrm1n30_div_FO_to( feoarrm1n30_t* lhs,   oarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_div_RF(       darr_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_div_RF_to(    darr_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_div_FR(    feoarrm1n30_t* lhs,    darr_t* rhs);
  void      feoarrm1n30_div_FR_to( feoarrm1n30_t* lhs,    darr_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_div_oF(    onumm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_div_oF_to( onumm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_div_Fo(    feoarrm1n30_t* lhs, onumm1n30_t* rhs);
  void      feoarrm1n30_div_Fo_to( feoarrm1n30_t* lhs, onumm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_div_rF(      coeff_t  lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_div_rF_to(    coeff_t lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_div_Fr(    feoarrm1n30_t* lhs,   coeff_t  rhs);
  void      feoarrm1n30_div_Fr_to( feoarrm1n30_t* lhs,   coeff_t  rhs, feoarrm1n30_t* res);
  oarrm1n30_t feoarrm1n30_integrate(    feoarrm1n30_t* arr, feonumm1n30_t* w);
  void    feoarrm1n30_integrate_to( feoarrm1n30_t* arr, feonumm1n30_t* w, oarrm1n30_t* res);
  feonumm1n30_t feoarrm1n30_dotproduct_FF(    feoarrm1n30_t* lhs, feoarrm1n30_t* rhs);
  void     feoarrm1n30_dotproduct_FF_to( feoarrm1n30_t* lhs, feoarrm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feoarrm1n30_dotproduct_OF(      oarrm1n30_t* lhs, feoarrm1n30_t* rhs);
  void     feoarrm1n30_dotproduct_OF_to(   oarrm1n30_t* lhs, feoarrm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feoarrm1n30_dotproduct_RF(       darr_t* lhs, feoarrm1n30_t* rhs);
  void     feoarrm1n30_dotproduct_RF_to(    darr_t* lhs, feoarrm1n30_t* rhs, feonumm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_matmul_FF(    feoarrm1n30_t* lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_matmul_FF_to( feoarrm1n30_t* lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_matmul_OF(    oarrm1n30_t*   lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_matmul_OF_to( oarrm1n30_t*   lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_matmul_FO(    feoarrm1n30_t* lhs, oarrm1n30_t*   rhs);
  void      feoarrm1n30_matmul_FO_to( feoarrm1n30_t* lhs, oarrm1n30_t*   rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_matmul_RF(    darr_t*    lhs, feoarrm1n30_t* rhs);
  void      feoarrm1n30_matmul_RF_to( darr_t*    lhs, feoarrm1n30_t* rhs, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_matmul_FR(    feoarrm1n30_t* lhs, darr_t*    rhs);
  void      feoarrm1n30_matmul_FR_to( feoarrm1n30_t* lhs, darr_t*    rhs, feoarrm1n30_t* res);
  feonumm1n30_t feoarrm1n30_det(   feoarrm1n30_t* arr);
  void     feoarrm1n30_det_to(feoarrm1n30_t* arr, feonumm1n30_t* res);
  feonumm1n30_t feoarrm1n30_norm(     feoarrm1n30_t* arr);
  void     feoarrm1n30_norm_to(  feoarrm1n30_t* arr, feonumm1n30_t* res);
  feonumm1n30_t feoarrm1n30_pnorm(    feoarrm1n30_t* arr, coeff_t p);
  void     feoarrm1n30_pnorm_to( feoarrm1n30_t* arr, coeff_t p, feonumm1n30_t* res);
  feoarrm1n30_t   feoarrm1n30_invert(    feoarrm1n30_t* arr);
  void        feoarrm1n30_invert_to( feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t   feoarrm1n30_transpose(   feoarrm1n30_t* arr);
  void        feoarrm1n30_transpose_to(feoarrm1n30_t* arr, feoarrm1n30_t* res);
  
  
  # From ../../../include/oti/static/onumm1n30/array/gauss/functions.h
  
  feoarrm1n30_t feoarrm1n30_atanh(    feoarrm1n30_t* arr);
  void      feoarrm1n30_atanh_to( feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_asinh(    feoarrm1n30_t* arr);
  void      feoarrm1n30_asinh_to( feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_acosh(    feoarrm1n30_t* arr);
  void      feoarrm1n30_acosh_to( feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_tanh(     feoarrm1n30_t* arr);
  void      feoarrm1n30_tanh_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sinh(     feoarrm1n30_t* arr);
  void      feoarrm1n30_sinh_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_cosh(     feoarrm1n30_t* arr);
  void      feoarrm1n30_cosh_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_atan(     feoarrm1n30_t* arr);
  void      feoarrm1n30_atan_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_asin(     feoarrm1n30_t* arr);
  void      feoarrm1n30_asin_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_acos(     feoarrm1n30_t* arr);
  void      feoarrm1n30_acos_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_tan(      feoarrm1n30_t* arr);
  void      feoarrm1n30_tan_to(   feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sin(      feoarrm1n30_t* arr);
  void      feoarrm1n30_sin_to(   feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_cos(      feoarrm1n30_t* arr);
  void      feoarrm1n30_cos_to(   feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_logb(     feoarrm1n30_t* arr, double base);
  void      feoarrm1n30_logb_to(  feoarrm1n30_t* arr, double base, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_log10(    feoarrm1n30_t* arr);
  void      feoarrm1n30_log10_to( feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_log(      feoarrm1n30_t* arr);
  void      feoarrm1n30_log_to(   feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_exp(      feoarrm1n30_t* arr);
  void      feoarrm1n30_exp_to(   feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_cbrt(     feoarrm1n30_t* arr);
  void      feoarrm1n30_cbrt_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_sqrt(     feoarrm1n30_t* arr);
  void      feoarrm1n30_sqrt_to(  feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_pow(      feoarrm1n30_t* arr, double e);
  void      feoarrm1n30_pow_to(   feoarrm1n30_t* arr, double e, feoarrm1n30_t* res);
  
  
  # From ../../../include/oti/static/onumm1n30/array/gauss/base.h
  
  void      feoarrm1n30_get_order_im_to( ord_t order, feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_get_order_im(    ord_t order, feoarrm1n30_t* arr);
  feoarrm1n30_t feoarrm1n30_get_deriv(   imdir_t idx, ord_t order, feoarrm1n30_t* arr);
  void      feoarrm1n30_get_deriv_to(imdir_t idx, ord_t order, feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_get_im(      imdir_t idx, ord_t order, feoarrm1n30_t* arr);
  void      feoarrm1n30_get_im_to(   imdir_t idx, ord_t order, feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_truncate_im(   imdir_t idx, ord_t order, feoarrm1n30_t* arr);
  void      feoarrm1n30_truncate_im_to(imdir_t idx, ord_t order, feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_copy(   feoarrm1n30_t* src);
  void      feoarrm1n30_copy_to(feoarrm1n30_t* src, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_get_im(    imdir_t idx, ord_t order, feoarrm1n30_t* arr);
  void      feoarrm1n30_get_im_to( imdir_t idx, ord_t order, feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_get_deriv(    imdir_t idx, ord_t order, feoarrm1n30_t* arr);
  void      feoarrm1n30_get_deriv_to( imdir_t idx, ord_t order, feoarrm1n30_t* arr, feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_extract_im(    imdir_t idx, ord_t order, feoarrm1n30_t* arr);
  void      feoarrm1n30_extract_im_to( imdir_t idx, ord_t order, feoarrm1n30_t* arr,  feoarrm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_extract_deriv(    imdir_t idx, ord_t order, feoarrm1n30_t* arr);
  void      feoarrm1n30_extract_deriv_to( imdir_t idx, ord_t order, feoarrm1n30_t* arr, feoarrm1n30_t* res);
  oarrm1n30_t   feoarrm1n30_get_item_k(  feoarrm1n30_t* arr, uint64_t k);
  feonumm1n30_t  feoarrm1n30_get_item_ij( feoarrm1n30_t* arr, uint64_t i, uint64_t j);
  onumm1n30_t feoarrm1n30_get_item_ijk(feoarrm1n30_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm1n30_get_item_ij_to(  feoarrm1n30_t* arr, uint64_t i, uint64_t j,
                                 feonumm1n30_t* res);
  void feoarrm1n30_get_item_k_to(   feoarrm1n30_t* arr, uint64_t k,
                                  oarrm1n30_t* res);
  void feoarrm1n30_get_item_ijk_to( feoarrm1n30_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm1n30_t* res);
  feoarrm1n30_t feoarrm1n30_get_slice(feoarrm1n30_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm1n30_get_slice_to(feoarrm1n30_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n30_t* res);
  void feoarrm1n30_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm1n30_t* res);
  void feoarrm1n30_set_item_ij_o(  onumm1n30_t* elm, uint64_t i, uint64_t j,
                               feoarrm1n30_t* res);
  void feoarrm1n30_set_item_ij_f(  feonumm1n30_t* elm, uint64_t i, uint64_t j,
                              feoarrm1n30_t* res);
  void feoarrm1n30_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm1n30_t* res);
  void feoarrm1n30_set_item_k_o(  onumm1n30_t* elm, uint64_t k,
                              feoarrm1n30_t* res);
  void feoarrm1n30_set_item_k_R(    oarrm1n30_t* elm, uint64_t k,
                            feoarrm1n30_t* res);
  void feoarrm1n30_set_item_k_O(    oarrm1n30_t* elm, uint64_t k,
                            feoarrm1n30_t* res);
  void feoarrm1n30_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm1n30_t* res);
  void feoarrm1n30_set_item_ijk_o( onumm1n30_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm1n30_t* res);
  void feoarrm1n30_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n30_t* res);
  void feoarrm1n30_set_slice_o( onumm1n30_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n30_t* res);
  void feoarrm1n30_set_slice_f( feonumm1n30_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n30_t* res);
  void feoarrm1n30_set_slice_O( oarrm1n30_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n30_t* res);
  void feoarrm1n30_set_slice_F( feoarrm1n30_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n30_t* res);
  void feoarrm1n30_set_all_o( onumm1n30_t* num, feoarrm1n30_t* arr );
  void feoarrm1n30_set_all_r(   coeff_t  num, feoarrm1n30_t* arr );
  void feoarrm1n30_set_all_f(  feonumm1n30_t* num, feoarrm1n30_t* arr );
  void feoarrm1n30_set_r(    coeff_t src, feoarrm1n30_t* res );
  void feoarrm1n30_set_o( onumm1n30_t* src, feoarrm1n30_t* res );
  void feoarrm1n30_set_f(  feonumm1n30_t* src, feoarrm1n30_t* res );
  void feoarrm1n30_set_R(    darr_t* src, feoarrm1n30_t* res );
  void feoarrm1n30_set_O(   oarrm1n30_t* src, feoarrm1n30_t* res );
  void feoarrm1n30_set_F( feoarrm1n30_t* src, feoarrm1n30_t* res );
  feoarrm1n30_t feoarrm1n30_eye( uint64_t size,  uint64_t nip);
  feoarrm1n30_t feoarrm1n30_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm1n30_t feoarrm1n30_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm1n30_t feoarrm1n30_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm1n30_free(feoarrm1n30_t* arr);
  feoarrm1n30_t feoarrm1n30_init();
  ord_t feoarrm1n30_get_order(feoarrm1n30_t* arr);
  
  
  # From ../../../include/oti/static/onumm1n30/scalar/utils.h
  
  void onumm1n30_get_active_bases(onumm1n30_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm1n30/scalar/algebra.h
  
  onumm1n30_t onumm1n30_abs(onumm1n30_t* num);
  onumm1n30_t onumm1n30_div_ro(coeff_t num, onumm1n30_t* den);
  onumm1n30_t onumm1n30_div_oo(onumm1n30_t* num, onumm1n30_t* den);
  onumm1n30_t onumm1n30_div_or(onumm1n30_t* num, coeff_t val);
  void onumm1n30_div_ro_to(coeff_t num, onumm1n30_t* den, onumm1n30_t* res);
  void onumm1n30_div_oo_to(onumm1n30_t* num, onumm1n30_t* den, onumm1n30_t* res);
  void onumm1n30_div_or_to(onumm1n30_t* num, coeff_t val, onumm1n30_t* res);
  void onumm1n30_abs_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_neg(  onumm1n30_t* lhs);
  void onumm1n30_neg_to(  onumm1n30_t* lhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_sum_oo(  onumm1n30_t* lhs,  onumm1n30_t* rhs);
  void onumm1n30_sum_oo_to(  onumm1n30_t* lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_sum_ro(  coeff_t lhs,  onumm1n30_t* rhs);
  void onumm1n30_sum_ro_to(  coeff_t lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_sub_oo(  onumm1n30_t* lhs,  onumm1n30_t* rhs);
  void onumm1n30_sub_oo_to(  onumm1n30_t* lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_sub_ro(  coeff_t lhs,  onumm1n30_t* rhs);
  void onumm1n30_sub_ro_to(  coeff_t lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_sub_or(  onumm1n30_t* lhs,  coeff_t rhs);
  void onumm1n30_sub_or_to(  onumm1n30_t* lhs,  coeff_t rhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_mul_oo(  onumm1n30_t* lhs,  onumm1n30_t* rhs);
  void onumm1n30_mul_oo_to(  onumm1n30_t* lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_mul_ro(  coeff_t lhs,  onumm1n30_t* rhs);
  void onumm1n30_mul_ro_to(  coeff_t lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_trunc_mul_oo(  onumm1n30_t* lhs,  onumm1n30_t* rhs);
  void onumm1n30_trunc_mul_oo_to(  onumm1n30_t* lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_gem_oo(  onumm1n30_t* a,  onumm1n30_t* b,  onumm1n30_t* c);
  void onumm1n30_gem_oo_to(  onumm1n30_t* a,  onumm1n30_t* b,  onumm1n30_t* c, onumm1n30_t* res);
  onumm1n30_t onumm1n30_gem_ro(  coeff_t a,  onumm1n30_t* b,  onumm1n30_t* c);
  void onumm1n30_gem_ro_to(  coeff_t a,  onumm1n30_t* b,  onumm1n30_t* c, onumm1n30_t* res);
  void onumm1n30_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n30_t* a,  ord_t ord_rhs,  onumm1n30_t* b,  onumm1n30_t* c, onumm1n30_t* res);
  void onumm1n30_trunc_sum_oo_to(ord_t order, onumm1n30_t* lhs,onumm1n30_t* rhs, onumm1n30_t* res);
  void onumm1n30_trunc_sub_oo_to(ord_t order, onumm1n30_t* lhs,onumm1n30_t* rhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_feval(coeff_t* feval_re, onumm1n30_t* x);
  void onumm1n30_feval_to(coeff_t* feval_re, onumm1n30_t* x, onumm1n30_t* res);
  
  
  # From ../../../include/oti/static/onumm1n30/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm1n30/scalar/functions.h
  
  onumm1n30_t onumm1n30_atanh(onumm1n30_t* num);
  void onumm1n30_atanh_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_asinh(onumm1n30_t* num);
  void onumm1n30_asinh_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_acosh(onumm1n30_t* num);
  void onumm1n30_acosh_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_tanh(onumm1n30_t* num);
  void onumm1n30_tanh_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_sqrt(onumm1n30_t* num);
  void onumm1n30_sqrt_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_cbrt(onumm1n30_t* num);
  void onumm1n30_cbrt_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_cosh(onumm1n30_t* num);
  void onumm1n30_cosh_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_sinh(onumm1n30_t* num);
  void onumm1n30_sinh_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_asin(onumm1n30_t* num);
  void onumm1n30_asin_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_acos(onumm1n30_t* num);
  void onumm1n30_acos_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_atan(onumm1n30_t* num);
  void onumm1n30_atan_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_tan(onumm1n30_t* num);
  void onumm1n30_tan_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_cos(onumm1n30_t* num);
  void onumm1n30_cos_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_sin(onumm1n30_t* num );
  void onumm1n30_sin_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_logb(onumm1n30_t* num, double base);
  void onumm1n30_logb_to(onumm1n30_t* num, double base, onumm1n30_t* res);
  onumm1n30_t onumm1n30_log10(onumm1n30_t* num);
  void onumm1n30_log10_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_log(onumm1n30_t* num);
  void onumm1n30_log_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_exp(onumm1n30_t* num);
  void onumm1n30_exp_to(onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_pow(onumm1n30_t* num, double e);
  void onumm1n30_pow_to(onumm1n30_t* num, coeff_t e, onumm1n30_t* res);
  
  
  # From ../../../include/oti/static/onumm1n30/scalar/base.h
  
  void onumm1n30_set_im_o(onumm1n30_t* num, imdir_t idx, ord_t order, onumm1n30_t* res);
  void onumm1n30_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm1n30_t* res);
  void onumm1n30_set_deriv_o(onumm1n30_t* num, imdir_t idx, ord_t order, onumm1n30_t* res);
  void onumm1n30_extract_im_to( imdir_t idx, ord_t order, onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_extract_im(imdir_t idx, ord_t order, onumm1n30_t* num);
  onumm1n30_t onumm1n30_extract_deriv(imdir_t idx, ord_t order, onumm1n30_t* num);
  void onumm1n30_extract_deriv_to(imdir_t idx, ord_t order, onumm1n30_t* num, onumm1n30_t* res);
  void onumm1n30_get_im_to_o(imdir_t idx, ord_t order, onumm1n30_t* num, onumm1n30_t* res);
  onumm1n30_t onumm1n30_get_im_o(imdir_t idx, ord_t order, onumm1n30_t* num);
  void onumm1n30_get_im_to_r(imdir_t idx, ord_t order, onumm1n30_t* num, coeff_t* res);
  ord_t onumm1n30_get_order(onumm1n30_t* lhs);
  onumm1n30_t onumm1n30_get_deriv_o( imdir_t idx, ord_t order, onumm1n30_t* num);
  void onumm1n30_get_deriv_to( imdir_t idx, ord_t order, onumm1n30_t* num, onumm1n30_t* res);
  void onumm1n30_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm1n30_t* res);
  onumm1n30_t onumm1n30_init();
  ndir_t onumm1n30_get_ndir_order(ord_t order, onumm1n30_t* num);
  ndir_t onumm1n30_get_ndir_total(onumm1n30_t* num);
  coeff_t* onumm1n30_get_order_address(ord_t order, onumm1n30_t* num);
  onumm1n30_t onumm1n30_create_r(  coeff_t lhs);
  void onumm1n30_set_r(  coeff_t lhs, onumm1n30_t* res);
  void onumm1n30_set_o(  onumm1n30_t* lhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_get_order_im(ord_t order, onumm1n30_t* lhs);
  void onumm1n30_get_order_im_to(ord_t order, onumm1n30_t* lhs, onumm1n30_t* res);
  coeff_t onumm1n30_get_item(imdir_t idx, ord_t order, onumm1n30_t* lhs);
  coeff_t onumm1n30_get_deriv(imdir_t idx, ord_t order, onumm1n30_t* lhs);
  void onumm1n30_set_item(coeff_t val, imdir_t idx, ord_t order, onumm1n30_t* x);
  onumm1n30_t onumm1n30_copy(  onumm1n30_t* lhs);
  void onumm1n30_copy_to(  onumm1n30_t* lhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_taylor_integrate(coeff_t* deltas,onumm1n30_t* lhs);
  void onumm1n30_taylor_integrate_to(coeff_t* deltas,onumm1n30_t* lhs, onumm1n30_t* res);
  onumm1n30_t onumm1n30_truncate_im(imdir_t idx, ord_t order, onumm1n30_t* lhs);
  void onumm1n30_truncate_im_to(imdir_t idx, ord_t order, onumm1n30_t* lhs, onumm1n30_t* res);
  void onumm1n30_print(  onumm1n30_t* lhs);
  imdir_t onumm1n30_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm1n30/scalar/gauss/utils.h
  
  void feonumm1n30_dimCheck(feonumm1n30_t* arr1,feonumm1n30_t* arr2);
  void feonumm1n30_get_active_bases(feonumm1n30_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n30/scalar/gauss/algebra.h
  
  feonumm1n30_t feonumm1n30_neg(   feonumm1n30_t* num);
  void     feonumm1n30_neg_to(feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_sum_ff(   feonumm1n30_t* lhs, feonumm1n30_t* rhs);
  void     feonumm1n30_sum_ff_to(feonumm1n30_t* lhs, feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_sum_of(   onumm1n30_t* lhs, feonumm1n30_t* rhs);
  void     feonumm1n30_sum_of_to(onumm1n30_t* lhs, feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_sum_rf(   coeff_t lhs, feonumm1n30_t* rhs);
  void     feonumm1n30_sum_rf_to(coeff_t lhs, feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_sub_ff(     feonumm1n30_t* lhs,  feonumm1n30_t* rhs);
  void     feonumm1n30_sub_ff_to(  feonumm1n30_t* lhs,  feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_sub_of(    onumm1n30_t* lhs,  feonumm1n30_t* rhs);
  void     feonumm1n30_sub_of_to( onumm1n30_t* lhs,  feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_sub_fo(     feonumm1n30_t* lhs, onumm1n30_t* rhs);
  void     feonumm1n30_sub_fo_to(  feonumm1n30_t* lhs, onumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_sub_rf(       coeff_t lhs,  feonumm1n30_t* rhs);
  void     feonumm1n30_sub_rf_to(    coeff_t lhs,  feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_sub_fr(     feonumm1n30_t* lhs,    coeff_t rhs);
  void     feonumm1n30_sub_fr_to(  feonumm1n30_t* lhs,    coeff_t rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_mul_ff(   feonumm1n30_t* lhs, feonumm1n30_t* rhs);
  void     feonumm1n30_mul_ff_to(feonumm1n30_t* lhs, feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_mul_of(   onumm1n30_t* lhs, feonumm1n30_t* rhs);
  void     feonumm1n30_mul_of_to(onumm1n30_t* lhs, feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_mul_rf(   coeff_t lhs, feonumm1n30_t* rhs);
  void     feonumm1n30_mul_rf_to(coeff_t lhs, feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_div_ff(     feonumm1n30_t* lhs,  feonumm1n30_t* rhs);
  void     feonumm1n30_div_ff_to(  feonumm1n30_t* lhs,  feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_div_of(    onumm1n30_t* lhs,  feonumm1n30_t* rhs);
  void     feonumm1n30_div_of_to( onumm1n30_t* lhs,  feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_div_fo(     feonumm1n30_t* lhs, onumm1n30_t* rhs);
  void     feonumm1n30_div_fo_to(  feonumm1n30_t* lhs, onumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_div_rf(       coeff_t lhs,  feonumm1n30_t* rhs);
  void     feonumm1n30_div_rf_to(    coeff_t lhs,  feonumm1n30_t* rhs, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_div_fr(     feonumm1n30_t* lhs,    coeff_t rhs);
  void     feonumm1n30_div_fr_to(  feonumm1n30_t* lhs,    coeff_t rhs, feonumm1n30_t* res);
  
  
  # From ../../../include/oti/static/onumm1n30/scalar/gauss/functions.h
  
  feonumm1n30_t feonumm1n30_atanh(    feonumm1n30_t* num);
  void     feonumm1n30_atanh_to( feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_asinh(    feonumm1n30_t* num);
  void     feonumm1n30_asinh_to( feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_acosh(    feonumm1n30_t* num);
  void     feonumm1n30_acosh_to( feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_tanh(     feonumm1n30_t* num);
  void     feonumm1n30_tanh_to(  feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_cosh(     feonumm1n30_t* num);
  void     feonumm1n30_cosh_to(  feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_sinh(     feonumm1n30_t* num);
  void     feonumm1n30_sinh_to(  feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_asin(     feonumm1n30_t* num);
  void     feonumm1n30_asin_to(  feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_acos(     feonumm1n30_t* num);
  void     feonumm1n30_acos_to(  feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_atan(     feonumm1n30_t* num);
  void     feonumm1n30_atan_to(  feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_tan(      feonumm1n30_t* num);
  void     feonumm1n30_tan_to(   feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_cos(      feonumm1n30_t* num);
  void     feonumm1n30_cos_to(   feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_sin(      feonumm1n30_t* num);
  void     feonumm1n30_sin_to(   feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_logb(     feonumm1n30_t* num, double base);
  void     feonumm1n30_logb_to(  feonumm1n30_t* num, double base, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_log10(    feonumm1n30_t* num);
  void     feonumm1n30_log10_to( feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_log(      feonumm1n30_t* num);
  void     feonumm1n30_log_to(   feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_exp(      feonumm1n30_t* num);
  void     feonumm1n30_exp_to(   feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_cbrt(     feonumm1n30_t* num);
  void     feonumm1n30_cbrt_to(  feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_sqrt(     feonumm1n30_t* num);
  void     feonumm1n30_sqrt_to(  feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_pow(      feonumm1n30_t* num, double e);
  void     feonumm1n30_pow_to(   feonumm1n30_t* num, double e, feonumm1n30_t* res);
  onumm1n30_t feonumm1n30_integrate(       feonumm1n30_t* num, feonumm1n30_t* w);
  void      feonumm1n30_integrate_to(    feonumm1n30_t* num, feonumm1n30_t* w, onumm1n30_t* res);
  onumm1n30_t feonumm1n30_integrate_f(     feonumm1n30_t* num, feonumm1n30_t* w);
  void      feonumm1n30_integrate_f_to(  feonumm1n30_t* num, feonumm1n30_t* w, onumm1n30_t* res);
  onumm1n30_t feonumm1n30_integrate_r(       coeff_t num, feonumm1n30_t* w);
  void      feonumm1n30_integrate_r_to(    coeff_t num, feonumm1n30_t* w, onumm1n30_t* res);
  onumm1n30_t feonumm1n30_integrate_o(    onumm1n30_t* num, feonumm1n30_t* w);
  void      feonumm1n30_integrate_o_to( onumm1n30_t* num, feonumm1n30_t* w, onumm1n30_t* res);
  
  
  # From ../../../include/oti/static/onumm1n30/scalar/gauss/base.h
  
  void     feonumm1n30_get_order_im_to( ord_t order, feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_get_order_im(    ord_t order, feonumm1n30_t* num);
  feonumm1n30_t feonumm1n30_get_im(    imdir_t idx, ord_t order, feonumm1n30_t* num);
  void     feonumm1n30_get_im_to( imdir_t idx, ord_t order, feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_get_deriv(    imdir_t idx, ord_t order, feonumm1n30_t* num);
  void     feonumm1n30_get_deriv_to( imdir_t idx, ord_t order, feonumm1n30_t* num, feonumm1n30_t* res);
  void feonumm1n30_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm1n30_t* num);
  void feonumm1n30_set_im_o( onumm1n30_t* val, imdir_t idx, ord_t order, feonumm1n30_t* num);
  void feonumm1n30_set_im_f(  feonumm1n30_t* val, imdir_t idx, ord_t order, feonumm1n30_t* num);
  void feonumm1n30_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm1n30_t* num);
  void feonumm1n30_set_deriv_o( onumm1n30_t* val, imdir_t idx, ord_t order, feonumm1n30_t* num);
  void feonumm1n30_set_deriv_f(  feonumm1n30_t* val, imdir_t idx, ord_t order, feonumm1n30_t* num);
  feonumm1n30_t feonumm1n30_extract_im(    imdir_t idx, ord_t order, feonumm1n30_t* num);
  void     feonumm1n30_extract_im_to( imdir_t idx, ord_t order, feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_extract_deriv(    imdir_t idx, ord_t order, feonumm1n30_t* num);
  void     feonumm1n30_extract_deriv_to( imdir_t idx, ord_t order, feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_truncate_im(    imdir_t idx, ord_t order, feonumm1n30_t* num);
  void     feonumm1n30_truncate_im_to( imdir_t idx, ord_t order, feonumm1n30_t* num, feonumm1n30_t* res);
  feonumm1n30_t feonumm1n30_copy(    feonumm1n30_t* src);
  void     feonumm1n30_copy_to( feonumm1n30_t* src, feonumm1n30_t* dst);
  void feonumm1n30_set_r(    coeff_t num, feonumm1n30_t* res);
  void feonumm1n30_set_o( onumm1n30_t* num, feonumm1n30_t* res);
  void feonumm1n30_set_f(  feonumm1n30_t* num, feonumm1n30_t* res);
  void feonumm1n30_set_item_k_r(   coeff_t  num, uint64_t k, feonumm1n30_t* res);
  void feonumm1n30_set_item_k_o( onumm1n30_t* num, uint64_t k, feonumm1n30_t* res);
  onumm1n30_t feonumm1n30_get_item_k(   feonumm1n30_t* num, uint64_t k);
  void      feonumm1n30_get_item_k_to(feonumm1n30_t* num, uint64_t k, onumm1n30_t* res);
  feonumm1n30_t feonumm1n30_zeros(uint64_t nIntPts);
  feonumm1n30_t feonumm1n30_createEmpty(uint64_t nIntPts);
  feonumm1n30_t feonumm1n30_empty_like(feonumm1n30_t* arr);
  void feonumm1n30_free(feonumm1n30_t* num);
  ord_t feonumm1n30_get_order( feonumm1n30_t* num );
  feonumm1n30_t feonumm1n30_init();
  
  