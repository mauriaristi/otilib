cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm1n20/scalar/structures.h
  
  ctypedef struct  onumm1n20_t : # {
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
  # } onumm1n20_t;
  
  
  # From ../../../include/oti/static/onumm1n20/array/structures.h
  
  ctypedef struct  oarrm1n20_t : # {
      onumm1n20_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm1n20_t;
  
  
  # From ../../../include/oti/static/onumm1n20/scalar/gauss/structures.h
  
  ctypedef struct  feonumm1n20_t: # {
      onumm1n20_t*  p_data;
      uint64_t    nip;
  # } feonumm1n20_t;
  
  
  # From ../../../include/oti/static/onumm1n20/array/gauss/structures.h
  
  ctypedef struct  feoarrm1n20_t: # {
      oarrm1n20_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm1n20_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm1n20/array/utils.h
  
  void oarrm1n20_dimCheck_OO_elementwise(oarrm1n20_t* arr1, oarrm1n20_t* arr2, oarrm1n20_t* res);
  void oarrm1n20_dimCheck_RO_elementwise(darr_t*  arr1, oarrm1n20_t* arr2, oarrm1n20_t* res);
  void oarrm1n20_dimCheck_OO_matmul(oarrm1n20_t* arr1, oarrm1n20_t* arr2, oarrm1n20_t* res);
  void oarrm1n20_dimCheck_RO_matmul(darr_t*  arr1, oarrm1n20_t* arr2, oarrm1n20_t* res);
  void oarrm1n20_dimCheck_OR_matmul(oarrm1n20_t* arr1, darr_t*  arr2, oarrm1n20_t* res);
  void oarrm1n20_dimCheck_O_squareness(oarrm1n20_t* arr1, oarrm1n20_t* res);
  void oarrm1n20_dimCheck_OO_samesize(oarrm1n20_t* arr1, oarrm1n20_t* res);
  void oarrm1n20_dimCheck_RO_samesize(darr_t* arr1, oarrm1n20_t* res);
  ord_t oarrm1n20_get_order(oarrm1n20_t* arr);
  void oarrm1n20_get_active_bases(oarrm1n20_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n20/array/algebra_elementwise.h
  
  oarrm1n20_t oarrm1n20_neg(oarrm1n20_t* arr);
  void oarrm1n20_neg_to(oarrm1n20_t* rhs, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_sum_OO(oarrm1n20_t*   lhs, oarrm1n20_t* rhs);
  oarrm1n20_t oarrm1n20_sum_RO(darr_t*    lhs, oarrm1n20_t* rhs);
  oarrm1n20_t oarrm1n20_sum_oO(onumm1n20_t* lhs, oarrm1n20_t* rhs);
  oarrm1n20_t oarrm1n20_sum_rO(coeff_t    lhs, oarrm1n20_t* rhs);
  void oarrm1n20_sum_OO_to(oarrm1n20_t*   lhs, oarrm1n20_t* rhs, oarrm1n20_t* res);
  void oarrm1n20_sum_RO_to(darr_t*    lhs, oarrm1n20_t* rhs, oarrm1n20_t* res);
  void oarrm1n20_sum_oO_to(onumm1n20_t* lhs, oarrm1n20_t* rhs, oarrm1n20_t* res);
  void oarrm1n20_sum_rO_to(coeff_t    lhs, oarrm1n20_t* rhs, oarrm1n20_t* res);
  void oarrm1n20_trunc_sum_OO_to(ord_t order, oarrm1n20_t* arr1, oarrm1n20_t* arr2, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_sub_OO(oarrm1n20_t*   lhs, oarrm1n20_t*   rhs);
  oarrm1n20_t oarrm1n20_sub_RO(darr_t*    lhs, oarrm1n20_t*   rhs);
  oarrm1n20_t oarrm1n20_sub_OR(oarrm1n20_t*   lhs, darr_t*    rhs);
  oarrm1n20_t oarrm1n20_sub_oO(onumm1n20_t* lhs, oarrm1n20_t*   rhs);
  oarrm1n20_t oarrm1n20_sub_Oo(oarrm1n20_t*   lhs, onumm1n20_t* rhs);
  oarrm1n20_t oarrm1n20_sub_rO(coeff_t    lhs, oarrm1n20_t*   rhs);
  oarrm1n20_t oarrm1n20_sub_Or(oarrm1n20_t*   lhs, coeff_t    rhs);
  void oarrm1n20_sub_OO_to( oarrm1n20_t*   lhs, oarrm1n20_t*   rhs, oarrm1n20_t* res);
  void oarrm1n20_sub_RO_to( darr_t*    lhs, oarrm1n20_t*   rhs, oarrm1n20_t* res);
  void oarrm1n20_sub_OR_to( oarrm1n20_t*   lhs, darr_t*    rhs, oarrm1n20_t* res);
  void oarrm1n20_sub_oO_to( onumm1n20_t* lhs, oarrm1n20_t*   rhs, oarrm1n20_t* res);
  void oarrm1n20_sub_Oo_to( oarrm1n20_t*   lhs, onumm1n20_t* rhs, oarrm1n20_t* res);
  void oarrm1n20_sub_rO_to( coeff_t    lhs, oarrm1n20_t*   rhs, oarrm1n20_t* res);
  void oarrm1n20_sub_Or_to( oarrm1n20_t*   lhs, coeff_t    rhs, oarrm1n20_t* res);
  void oarrm1n20_trunc_sub_OO_to(ord_t order, oarrm1n20_t* arr1, oarrm1n20_t* arr2, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_mul_OO(oarrm1n20_t*   lhs, oarrm1n20_t* rhs);
  oarrm1n20_t oarrm1n20_mul_RO(darr_t*    lhs, oarrm1n20_t* rhs);
  oarrm1n20_t oarrm1n20_mul_oO(onumm1n20_t* lhs, oarrm1n20_t* rhs);
  oarrm1n20_t oarrm1n20_mul_rO(coeff_t    lhs, oarrm1n20_t* rhs);
  void oarrm1n20_mul_OO_to(oarrm1n20_t*   lhs, oarrm1n20_t* rhs, oarrm1n20_t* res);
  void oarrm1n20_mul_RO_to(darr_t*    lhs, oarrm1n20_t* rhs, oarrm1n20_t* res);
  void oarrm1n20_mul_oO_to(onumm1n20_t* lhs, oarrm1n20_t* rhs, oarrm1n20_t* res);
  void oarrm1n20_mul_rO_to(coeff_t    lhs, oarrm1n20_t* rhs, oarrm1n20_t* res);
  void oarrm1n20_gem_OO_to(  oarrm1n20_t* arr1, oarrm1n20_t* arr2, oarrm1n20_t* arr3, oarrm1n20_t* res);
  void oarrm1n20_gem_oO_to(onumm1n20_t* arr1, oarrm1n20_t* arr2, oarrm1n20_t* arr3, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_div_OO(oarrm1n20_t*   lhs, oarrm1n20_t*   rhs);
  oarrm1n20_t oarrm1n20_div_OR(oarrm1n20_t*   lhs, darr_t*    rhs);
  oarrm1n20_t oarrm1n20_div_RO(darr_t*    lhs, oarrm1n20_t*   rhs);
  oarrm1n20_t oarrm1n20_div_oO(onumm1n20_t* lhs, oarrm1n20_t*   rhs);
  oarrm1n20_t oarrm1n20_div_Oo(oarrm1n20_t*   lhs, onumm1n20_t* rhs);
  oarrm1n20_t oarrm1n20_div_rO(coeff_t    lhs, oarrm1n20_t*   rhs);
  oarrm1n20_t oarrm1n20_div_Or(oarrm1n20_t*   lhs, coeff_t    rhs);
  void oarrm1n20_div_OO_to(oarrm1n20_t*   lhs, oarrm1n20_t*   rhs, oarrm1n20_t* res);
  void oarrm1n20_div_RO_to(darr_t*    lhs, oarrm1n20_t*   rhs, oarrm1n20_t* res);
  void oarrm1n20_div_OR_to(oarrm1n20_t*   lhs, darr_t*    rhs, oarrm1n20_t* res);
  void oarrm1n20_div_oO_to(onumm1n20_t* lhs, oarrm1n20_t*   rhs, oarrm1n20_t* res);
  void oarrm1n20_div_Oo_to(oarrm1n20_t*   lhs, onumm1n20_t* rhs, oarrm1n20_t* res);
  void oarrm1n20_div_rO_to(coeff_t    lhs, oarrm1n20_t*   rhs, oarrm1n20_t* res);
  void oarrm1n20_div_Or_to(oarrm1n20_t*   lhs, coeff_t    rhs, oarrm1n20_t* res);
  
  
  # From ../../../include/oti/static/onumm1n20/array/algebra_matops.h
  
  onumm1n20_t oarrm1n20_dotproduct_OO(    oarrm1n20_t* lhs, oarrm1n20_t* rhs);
  void      oarrm1n20_dotproduct_OO_to( oarrm1n20_t* lhs, oarrm1n20_t* rhs, onumm1n20_t* res);
  onumm1n20_t oarrm1n20_dotproduct_RO(     darr_t* lhs, oarrm1n20_t* rhs);
  void      oarrm1n20_dotproduct_RO_to(  darr_t* lhs, oarrm1n20_t* rhs, onumm1n20_t* res);
  oarrm1n20_t oarrm1n20_matmul_OO(    oarrm1n20_t* lhs, oarrm1n20_t* rhs);
  oarrm1n20_t oarrm1n20_matmul_OR(    oarrm1n20_t* lhs,  darr_t* rhs);
  oarrm1n20_t oarrm1n20_matmul_RO(     darr_t* lhs, oarrm1n20_t* rhs);
  void    oarrm1n20_matmul_OO_to( oarrm1n20_t* lhs, oarrm1n20_t* rhs, oarrm1n20_t* res);
  void    oarrm1n20_matmul_OR_to( oarrm1n20_t* lhs,  darr_t* rhs, oarrm1n20_t* res);
  void    oarrm1n20_matmul_RO_to(  darr_t* lhs, oarrm1n20_t* rhs, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_transpose(    oarrm1n20_t* arr1);
  void    oarrm1n20_transpose_to( oarrm1n20_t* arr1, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_invert(    oarrm1n20_t* arr1);
  void    oarrm1n20_invert_to( oarrm1n20_t* arr1, oarrm1n20_t* res);
  onumm1n20_t oarrm1n20_det(    oarrm1n20_t* arr1);
  void      oarrm1n20_det_to( oarrm1n20_t* arr1, onumm1n20_t* res);
  onumm1n20_t oarrm1n20_norm(    oarrm1n20_t* arr1);
  void      oarrm1n20_norm_to( oarrm1n20_t* arr1,  onumm1n20_t* res);
  onumm1n20_t oarrm1n20_pnorm(    oarrm1n20_t* arr1, coeff_t p);
  void      oarrm1n20_pnorm_to( oarrm1n20_t* arr1, coeff_t p, onumm1n20_t* res);
  
  
  # From ../../../include/oti/static/onumm1n20/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm1n20/array/functions.h
  
  oarrm1n20_t oarrm1n20_atanh(   oarrm1n20_t* arr);
  void    oarrm1n20_atanh_to(oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_asinh(   oarrm1n20_t* arr);
  void    oarrm1n20_asinh_to(oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_acosh(   oarrm1n20_t* arr);
  void    oarrm1n20_acosh_to(oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_tanh(    oarrm1n20_t* arr);
  void    oarrm1n20_tanh_to( oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_cbrt(    oarrm1n20_t* arr);
  void    oarrm1n20_cbrt_to( oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_sqrt(    oarrm1n20_t* arr);
  void    oarrm1n20_sqrt_to( oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_cosh(    oarrm1n20_t* arr);
  void    oarrm1n20_cosh_to( oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_sinh(    oarrm1n20_t* arr);
  void    oarrm1n20_sinh_to( oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_asin(    oarrm1n20_t* arr);
  void    oarrm1n20_asin_to( oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_acos(    oarrm1n20_t* arr);
  void    oarrm1n20_acos_to( oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_atan(    oarrm1n20_t* arr);
  void    oarrm1n20_atan_to( oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_tan(     oarrm1n20_t* arr);
  void    oarrm1n20_tan_to(  oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_cos(     oarrm1n20_t* arr);
  void    oarrm1n20_cos_to(  oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_sin(     oarrm1n20_t* arr);
  void    oarrm1n20_sin_to(  oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_logb(    oarrm1n20_t* arr, double base);
  void    oarrm1n20_logb_to( oarrm1n20_t* arr, double base, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_log10(   oarrm1n20_t* arr);
  void    oarrm1n20_log10_to(oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_log(     oarrm1n20_t* arr);
  void    oarrm1n20_log_to(  oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_exp(     oarrm1n20_t* arr);
  void    oarrm1n20_exp_to(  oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_pow(     oarrm1n20_t* arr, double e);
  void    oarrm1n20_pow_to(  oarrm1n20_t* arr, double e, oarrm1n20_t* res);
  
  
  # From ../../../include/oti/static/onumm1n20/array/base.h
  
  void    oarrm1n20_taylor_integrate_to( coeff_t* deltas, oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_taylor_integrate(    coeff_t* deltas, oarrm1n20_t* arr);
  void    oarrm1n20_get_order_im_to( ord_t order, oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_get_order_im(    ord_t order, oarrm1n20_t* arr);
  void oarrm1n20_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n20_t* res);
  void oarrm1n20_set_slice_O( oarrm1n20_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n20_t* res);
  void oarrm1n20_set_slice_o( onumm1n20_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_get_slice( oarrm1n20_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm1n20_get_slice_to( oarrm1n20_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_truncate_im(    imdir_t idx, ord_t order, oarrm1n20_t* arr);
  void    oarrm1n20_truncate_im_to( imdir_t idx, ord_t order, oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_extract_im(   imdir_t idx, ord_t order, oarrm1n20_t* arr);
  void    oarrm1n20_extract_im_to(imdir_t idx, ord_t order, oarrm1n20_t* arr, oarrm1n20_t* res);
  darr_t  oarrm1n20_get_deriv(    imdir_t idx, ord_t order, oarrm1n20_t* arr);
  void    oarrm1n20_get_deriv_to( imdir_t idx, ord_t order, oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_get_deriv_o(  imdir_t idx, ord_t order, oarrm1n20_t* arr);
  oarrm1n20_t oarrm1n20_extract_deriv(    imdir_t idx, ord_t order, oarrm1n20_t* arr);
  void    oarrm1n20_extract_deriv_to( imdir_t idx, ord_t order, oarrm1n20_t* arr, oarrm1n20_t* res);
  darr_t  oarrm1n20_get_im(   imdir_t idx, ord_t order, oarrm1n20_t* arr);
  oarrm1n20_t oarrm1n20_get_im_o( imdir_t idx, ord_t order, oarrm1n20_t* arr);
  void    oarrm1n20_get_im_to(imdir_t idx, ord_t order, oarrm1n20_t* arr, oarrm1n20_t* res);
  void    oarrm1n20_copy_to(oarrm1n20_t* arr, oarrm1n20_t* res);
  oarrm1n20_t oarrm1n20_copy(oarrm1n20_t* arr);
  void oarrm1n20_set_all_r( coeff_t num, oarrm1n20_t* arr);
  void oarrm1n20_set_item_i_r( coeff_t num, uint64_t i, oarrm1n20_t* arr);
  void oarrm1n20_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm1n20_t* arr);
  void oarrm1n20_set_r(   coeff_t  num,   oarrm1n20_t* arr);
  void oarrm1n20_set_o( onumm1n20_t* num,   oarrm1n20_t* arr);
  void oarrm1n20_set_O(   oarrm1n20_t* arrin, oarrm1n20_t* arr);
  void oarrm1n20_set_all_o( onumm1n20_t* src, oarrm1n20_t* arr);
  void oarrm1n20_set_item_i_o( onumm1n20_t* num, uint64_t i, oarrm1n20_t* arr);
  void oarrm1n20_set_item_ij_o( onumm1n20_t* num, uint64_t i, uint64_t j, oarrm1n20_t* arr);
  onumm1n20_t oarrm1n20_get_item_i(    oarrm1n20_t* arr, uint64_t i);
  void      oarrm1n20_get_item_i_to( oarrm1n20_t* arr, uint64_t i,             onumm1n20_t* res);
  onumm1n20_t oarrm1n20_get_item_ij(   oarrm1n20_t* arr, uint64_t i, uint64_t j);
  void      oarrm1n20_get_item_ij_to(oarrm1n20_t* arr, uint64_t i, uint64_t j, onumm1n20_t* res);
  oarrm1n20_t oarrm1n20_init();
  void oarrm1n20_free(oarrm1n20_t* arr);
  oarrm1n20_t oarrm1n20_empty_like(oarrm1n20_t* arr);
  oarrm1n20_t oarrm1n20_eye(uint64_t nrows);
  oarrm1n20_t oarrm1n20_ones(uint64_t nrows, uint64_t ncols);
  oarrm1n20_t oarrm1n20_zeros(uint64_t nrows, uint64_t ncols);
  oarrm1n20_t oarrm1n20_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm1n20/array/gauss/utils.h
  
  void feoarrm1n20_dimCheck_FF_samesize(feoarrm1n20_t* arr1, feoarrm1n20_t* arr2, feonumm1n20_t* res);
  void feoarrm1n20_dimCheck_OF_samesize(  oarrm1n20_t* arr1, feoarrm1n20_t* arr2, feonumm1n20_t* res);
  void feoarrm1n20_dimCheck_RF_samesize(   darr_t* arr1, feoarrm1n20_t* arr2, feonumm1n20_t* res);
  void feoarrm1n20_dimCheck_FF_elementwise(feoarrm1n20_t* arr1, feoarrm1n20_t* arr2, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_OF_elementwise(  oarrm1n20_t* arr1, feoarrm1n20_t* arr2, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm1n20_t* arr2, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_fF_elementwise( feonumm1n20_t* num1, feoarrm1n20_t* arr2, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_Ff_elementwise(feoarrm1n20_t* arr1,  feonumm1n20_t* num2, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_FF_matmul( feoarrm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_OF_matmul(   oarrm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_RF_matmul(    darr_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_FO_matmul( feoarrm1n20_t* lhs,   oarrm1n20_t* rhs, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_FR_matmul( feoarrm1n20_t* lhs,    darr_t* rhs, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_F_squareness( feoarrm1n20_t* arr1, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_F_transpose( feoarrm1n20_t* arr1, feoarrm1n20_t* res);
  void feoarrm1n20_dimCheck_FfO_integrate(feoarrm1n20_t* arr, feonumm1n20_t* num,oarrm1n20_t* res);
  void feoarrm1n20_get_active_bases(feoarrm1n20_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n20/array/gauss/algebra.h
  
  feoarrm1n20_t feoarrm1n20_neg(    feoarrm1n20_t* arr);
  void      feoarrm1n20_neg_to( feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sum_FF(   feoarrm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sum_FF_to(feoarrm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sum_fF(    feonumm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sum_fF_to( feonumm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sum_OF(     oarrm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sum_OF_to(  oarrm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sum_RF(      darr_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sum_RF_to(   darr_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sum_oF(   onumm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sum_oF_to(onumm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sum_rF(     coeff_t  lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sum_rF_to(  coeff_t  lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sub_FF(    feoarrm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sub_FF_to( feoarrm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sub_fF(    feonumm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sub_fF_to( feonumm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sub_Ff(    feoarrm1n20_t* lhs, feonumm1n20_t* rhs);
  void      feoarrm1n20_sub_Ff_to( feoarrm1n20_t* lhs, feonumm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sub_OF(      oarrm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sub_OF_to(   oarrm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sub_FO(    feoarrm1n20_t* lhs,   oarrm1n20_t* rhs);
  void      feoarrm1n20_sub_FO_to( feoarrm1n20_t* lhs,   oarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sub_RF(       darr_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sub_RF_to(    darr_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sub_FR(    feoarrm1n20_t* lhs,    darr_t* rhs);
  void      feoarrm1n20_sub_FR_to( feoarrm1n20_t* lhs,    darr_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sub_oF(    onumm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sub_oF_to( onumm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sub_Fo(    feoarrm1n20_t* lhs, onumm1n20_t* rhs);
  void      feoarrm1n20_sub_Fo_to( feoarrm1n20_t* lhs, onumm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sub_rF(      coeff_t  lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_sub_rF_to(    coeff_t lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sub_Fr(    feoarrm1n20_t* lhs,   coeff_t  rhs);
  void      feoarrm1n20_sub_Fr_to( feoarrm1n20_t* lhs,   coeff_t  rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_mul_FF(   feoarrm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_mul_FF_to(feoarrm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_mul_fF(    feonumm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_mul_fF_to( feonumm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_mul_OF(     oarrm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_mul_OF_to(  oarrm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_mul_RF(      darr_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_mul_RF_to(   darr_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_mul_oF(   onumm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_mul_oF_to(onumm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_mul_rF(     coeff_t  lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_mul_rF_to(  coeff_t  lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_div_FF(    feoarrm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_div_FF_to( feoarrm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_div_fF(     feonumm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_div_fF_to(  feonumm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_div_Ff(    feoarrm1n20_t* lhs,  feonumm1n20_t* rhs);
  void      feoarrm1n20_div_Ff_to( feoarrm1n20_t* lhs,  feonumm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_div_OF(      oarrm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_div_OF_to(   oarrm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_div_FO(    feoarrm1n20_t* lhs,   oarrm1n20_t* rhs);
  void      feoarrm1n20_div_FO_to( feoarrm1n20_t* lhs,   oarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_div_RF(       darr_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_div_RF_to(    darr_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_div_FR(    feoarrm1n20_t* lhs,    darr_t* rhs);
  void      feoarrm1n20_div_FR_to( feoarrm1n20_t* lhs,    darr_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_div_oF(    onumm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_div_oF_to( onumm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_div_Fo(    feoarrm1n20_t* lhs, onumm1n20_t* rhs);
  void      feoarrm1n20_div_Fo_to( feoarrm1n20_t* lhs, onumm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_div_rF(      coeff_t  lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_div_rF_to(    coeff_t lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_div_Fr(    feoarrm1n20_t* lhs,   coeff_t  rhs);
  void      feoarrm1n20_div_Fr_to( feoarrm1n20_t* lhs,   coeff_t  rhs, feoarrm1n20_t* res);
  oarrm1n20_t feoarrm1n20_integrate(    feoarrm1n20_t* arr, feonumm1n20_t* w);
  void    feoarrm1n20_integrate_to( feoarrm1n20_t* arr, feonumm1n20_t* w, oarrm1n20_t* res);
  feonumm1n20_t feoarrm1n20_dotproduct_FF(    feoarrm1n20_t* lhs, feoarrm1n20_t* rhs);
  void     feoarrm1n20_dotproduct_FF_to( feoarrm1n20_t* lhs, feoarrm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feoarrm1n20_dotproduct_OF(      oarrm1n20_t* lhs, feoarrm1n20_t* rhs);
  void     feoarrm1n20_dotproduct_OF_to(   oarrm1n20_t* lhs, feoarrm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feoarrm1n20_dotproduct_RF(       darr_t* lhs, feoarrm1n20_t* rhs);
  void     feoarrm1n20_dotproduct_RF_to(    darr_t* lhs, feoarrm1n20_t* rhs, feonumm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_matmul_FF(    feoarrm1n20_t* lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_matmul_FF_to( feoarrm1n20_t* lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_matmul_OF(    oarrm1n20_t*   lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_matmul_OF_to( oarrm1n20_t*   lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_matmul_FO(    feoarrm1n20_t* lhs, oarrm1n20_t*   rhs);
  void      feoarrm1n20_matmul_FO_to( feoarrm1n20_t* lhs, oarrm1n20_t*   rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_matmul_RF(    darr_t*    lhs, feoarrm1n20_t* rhs);
  void      feoarrm1n20_matmul_RF_to( darr_t*    lhs, feoarrm1n20_t* rhs, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_matmul_FR(    feoarrm1n20_t* lhs, darr_t*    rhs);
  void      feoarrm1n20_matmul_FR_to( feoarrm1n20_t* lhs, darr_t*    rhs, feoarrm1n20_t* res);
  feonumm1n20_t feoarrm1n20_det(   feoarrm1n20_t* arr);
  void     feoarrm1n20_det_to(feoarrm1n20_t* arr, feonumm1n20_t* res);
  feonumm1n20_t feoarrm1n20_norm(     feoarrm1n20_t* arr);
  void     feoarrm1n20_norm_to(  feoarrm1n20_t* arr, feonumm1n20_t* res);
  feonumm1n20_t feoarrm1n20_pnorm(    feoarrm1n20_t* arr, coeff_t p);
  void     feoarrm1n20_pnorm_to( feoarrm1n20_t* arr, coeff_t p, feonumm1n20_t* res);
  feoarrm1n20_t   feoarrm1n20_invert(    feoarrm1n20_t* arr);
  void        feoarrm1n20_invert_to( feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t   feoarrm1n20_transpose(   feoarrm1n20_t* arr);
  void        feoarrm1n20_transpose_to(feoarrm1n20_t* arr, feoarrm1n20_t* res);
  
  
  # From ../../../include/oti/static/onumm1n20/array/gauss/functions.h
  
  feoarrm1n20_t feoarrm1n20_atanh(    feoarrm1n20_t* arr);
  void      feoarrm1n20_atanh_to( feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_asinh(    feoarrm1n20_t* arr);
  void      feoarrm1n20_asinh_to( feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_acosh(    feoarrm1n20_t* arr);
  void      feoarrm1n20_acosh_to( feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_tanh(     feoarrm1n20_t* arr);
  void      feoarrm1n20_tanh_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sinh(     feoarrm1n20_t* arr);
  void      feoarrm1n20_sinh_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_cosh(     feoarrm1n20_t* arr);
  void      feoarrm1n20_cosh_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_atan(     feoarrm1n20_t* arr);
  void      feoarrm1n20_atan_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_asin(     feoarrm1n20_t* arr);
  void      feoarrm1n20_asin_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_acos(     feoarrm1n20_t* arr);
  void      feoarrm1n20_acos_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_tan(      feoarrm1n20_t* arr);
  void      feoarrm1n20_tan_to(   feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sin(      feoarrm1n20_t* arr);
  void      feoarrm1n20_sin_to(   feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_cos(      feoarrm1n20_t* arr);
  void      feoarrm1n20_cos_to(   feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_logb(     feoarrm1n20_t* arr, double base);
  void      feoarrm1n20_logb_to(  feoarrm1n20_t* arr, double base, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_log10(    feoarrm1n20_t* arr);
  void      feoarrm1n20_log10_to( feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_log(      feoarrm1n20_t* arr);
  void      feoarrm1n20_log_to(   feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_exp(      feoarrm1n20_t* arr);
  void      feoarrm1n20_exp_to(   feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_cbrt(     feoarrm1n20_t* arr);
  void      feoarrm1n20_cbrt_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_sqrt(     feoarrm1n20_t* arr);
  void      feoarrm1n20_sqrt_to(  feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_pow(      feoarrm1n20_t* arr, double e);
  void      feoarrm1n20_pow_to(   feoarrm1n20_t* arr, double e, feoarrm1n20_t* res);
  
  
  # From ../../../include/oti/static/onumm1n20/array/gauss/base.h
  
  void      feoarrm1n20_get_order_im_to( ord_t order, feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_get_order_im(    ord_t order, feoarrm1n20_t* arr);
  feoarrm1n20_t feoarrm1n20_get_deriv(   imdir_t idx, ord_t order, feoarrm1n20_t* arr);
  void      feoarrm1n20_get_deriv_to(imdir_t idx, ord_t order, feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_get_im(      imdir_t idx, ord_t order, feoarrm1n20_t* arr);
  void      feoarrm1n20_get_im_to(   imdir_t idx, ord_t order, feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_truncate_im(   imdir_t idx, ord_t order, feoarrm1n20_t* arr);
  void      feoarrm1n20_truncate_im_to(imdir_t idx, ord_t order, feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_copy(   feoarrm1n20_t* src);
  void      feoarrm1n20_copy_to(feoarrm1n20_t* src, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_get_im(    imdir_t idx, ord_t order, feoarrm1n20_t* arr);
  void      feoarrm1n20_get_im_to( imdir_t idx, ord_t order, feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_get_deriv(    imdir_t idx, ord_t order, feoarrm1n20_t* arr);
  void      feoarrm1n20_get_deriv_to( imdir_t idx, ord_t order, feoarrm1n20_t* arr, feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_extract_im(    imdir_t idx, ord_t order, feoarrm1n20_t* arr);
  void      feoarrm1n20_extract_im_to( imdir_t idx, ord_t order, feoarrm1n20_t* arr,  feoarrm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_extract_deriv(    imdir_t idx, ord_t order, feoarrm1n20_t* arr);
  void      feoarrm1n20_extract_deriv_to( imdir_t idx, ord_t order, feoarrm1n20_t* arr, feoarrm1n20_t* res);
  oarrm1n20_t   feoarrm1n20_get_item_k(  feoarrm1n20_t* arr, uint64_t k);
  feonumm1n20_t  feoarrm1n20_get_item_ij( feoarrm1n20_t* arr, uint64_t i, uint64_t j);
  onumm1n20_t feoarrm1n20_get_item_ijk(feoarrm1n20_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm1n20_get_item_ij_to(  feoarrm1n20_t* arr, uint64_t i, uint64_t j,
                                 feonumm1n20_t* res);
  void feoarrm1n20_get_item_k_to(   feoarrm1n20_t* arr, uint64_t k,
                                  oarrm1n20_t* res);
  void feoarrm1n20_get_item_ijk_to( feoarrm1n20_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm1n20_t* res);
  feoarrm1n20_t feoarrm1n20_get_slice(feoarrm1n20_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm1n20_get_slice_to(feoarrm1n20_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n20_t* res);
  void feoarrm1n20_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm1n20_t* res);
  void feoarrm1n20_set_item_ij_o(  onumm1n20_t* elm, uint64_t i, uint64_t j,
                               feoarrm1n20_t* res);
  void feoarrm1n20_set_item_ij_f(  feonumm1n20_t* elm, uint64_t i, uint64_t j,
                              feoarrm1n20_t* res);
  void feoarrm1n20_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm1n20_t* res);
  void feoarrm1n20_set_item_k_o(  onumm1n20_t* elm, uint64_t k,
                              feoarrm1n20_t* res);
  void feoarrm1n20_set_item_k_R(    oarrm1n20_t* elm, uint64_t k,
                            feoarrm1n20_t* res);
  void feoarrm1n20_set_item_k_O(    oarrm1n20_t* elm, uint64_t k,
                            feoarrm1n20_t* res);
  void feoarrm1n20_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm1n20_t* res);
  void feoarrm1n20_set_item_ijk_o( onumm1n20_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm1n20_t* res);
  void feoarrm1n20_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n20_t* res);
  void feoarrm1n20_set_slice_o( onumm1n20_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n20_t* res);
  void feoarrm1n20_set_slice_f( feonumm1n20_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n20_t* res);
  void feoarrm1n20_set_slice_O( oarrm1n20_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n20_t* res);
  void feoarrm1n20_set_slice_F( feoarrm1n20_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n20_t* res);
  void feoarrm1n20_set_all_o( onumm1n20_t* num, feoarrm1n20_t* arr );
  void feoarrm1n20_set_all_r(   coeff_t  num, feoarrm1n20_t* arr );
  void feoarrm1n20_set_all_f(  feonumm1n20_t* num, feoarrm1n20_t* arr );
  void feoarrm1n20_set_r(    coeff_t src, feoarrm1n20_t* res );
  void feoarrm1n20_set_o( onumm1n20_t* src, feoarrm1n20_t* res );
  void feoarrm1n20_set_f(  feonumm1n20_t* src, feoarrm1n20_t* res );
  void feoarrm1n20_set_R(    darr_t* src, feoarrm1n20_t* res );
  void feoarrm1n20_set_O(   oarrm1n20_t* src, feoarrm1n20_t* res );
  void feoarrm1n20_set_F( feoarrm1n20_t* src, feoarrm1n20_t* res );
  feoarrm1n20_t feoarrm1n20_eye( uint64_t size,  uint64_t nip);
  feoarrm1n20_t feoarrm1n20_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm1n20_t feoarrm1n20_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm1n20_t feoarrm1n20_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm1n20_free(feoarrm1n20_t* arr);
  feoarrm1n20_t feoarrm1n20_init();
  ord_t feoarrm1n20_get_order(feoarrm1n20_t* arr);
  
  
  # From ../../../include/oti/static/onumm1n20/scalar/utils.h
  
  void onumm1n20_get_active_bases(onumm1n20_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm1n20/scalar/algebra.h
  
  onumm1n20_t onumm1n20_abs(onumm1n20_t* num);
  onumm1n20_t onumm1n20_div_ro(coeff_t num, onumm1n20_t* den);
  onumm1n20_t onumm1n20_div_oo(onumm1n20_t* num, onumm1n20_t* den);
  onumm1n20_t onumm1n20_div_or(onumm1n20_t* num, coeff_t val);
  void onumm1n20_div_ro_to(coeff_t num, onumm1n20_t* den, onumm1n20_t* res);
  void onumm1n20_div_oo_to(onumm1n20_t* num, onumm1n20_t* den, onumm1n20_t* res);
  void onumm1n20_div_or_to(onumm1n20_t* num, coeff_t val, onumm1n20_t* res);
  void onumm1n20_abs_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_neg(  onumm1n20_t* lhs);
  void onumm1n20_neg_to(  onumm1n20_t* lhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_sum_oo(  onumm1n20_t* lhs,  onumm1n20_t* rhs);
  void onumm1n20_sum_oo_to(  onumm1n20_t* lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_sum_ro(  coeff_t lhs,  onumm1n20_t* rhs);
  void onumm1n20_sum_ro_to(  coeff_t lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_sub_oo(  onumm1n20_t* lhs,  onumm1n20_t* rhs);
  void onumm1n20_sub_oo_to(  onumm1n20_t* lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_sub_ro(  coeff_t lhs,  onumm1n20_t* rhs);
  void onumm1n20_sub_ro_to(  coeff_t lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_sub_or(  onumm1n20_t* lhs,  coeff_t rhs);
  void onumm1n20_sub_or_to(  onumm1n20_t* lhs,  coeff_t rhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_mul_oo(  onumm1n20_t* lhs,  onumm1n20_t* rhs);
  void onumm1n20_mul_oo_to(  onumm1n20_t* lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_mul_ro(  coeff_t lhs,  onumm1n20_t* rhs);
  void onumm1n20_mul_ro_to(  coeff_t lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_trunc_mul_oo(  onumm1n20_t* lhs,  onumm1n20_t* rhs);
  void onumm1n20_trunc_mul_oo_to(  onumm1n20_t* lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_gem_oo(  onumm1n20_t* a,  onumm1n20_t* b,  onumm1n20_t* c);
  void onumm1n20_gem_oo_to(  onumm1n20_t* a,  onumm1n20_t* b,  onumm1n20_t* c, onumm1n20_t* res);
  onumm1n20_t onumm1n20_gem_ro(  coeff_t a,  onumm1n20_t* b,  onumm1n20_t* c);
  void onumm1n20_gem_ro_to(  coeff_t a,  onumm1n20_t* b,  onumm1n20_t* c, onumm1n20_t* res);
  void onumm1n20_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n20_t* a,  ord_t ord_rhs,  onumm1n20_t* b,  onumm1n20_t* c, onumm1n20_t* res);
  void onumm1n20_trunc_sum_oo_to(ord_t order, onumm1n20_t* lhs,onumm1n20_t* rhs, onumm1n20_t* res);
  void onumm1n20_trunc_sub_oo_to(ord_t order, onumm1n20_t* lhs,onumm1n20_t* rhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_feval(coeff_t* feval_re, onumm1n20_t* x);
  void onumm1n20_feval_to(coeff_t* feval_re, onumm1n20_t* x, onumm1n20_t* res);
  
  
  # From ../../../include/oti/static/onumm1n20/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm1n20/scalar/functions.h
  
  onumm1n20_t onumm1n20_atanh(onumm1n20_t* num);
  void onumm1n20_atanh_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_asinh(onumm1n20_t* num);
  void onumm1n20_asinh_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_acosh(onumm1n20_t* num);
  void onumm1n20_acosh_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_tanh(onumm1n20_t* num);
  void onumm1n20_tanh_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_sqrt(onumm1n20_t* num);
  void onumm1n20_sqrt_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_cbrt(onumm1n20_t* num);
  void onumm1n20_cbrt_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_cosh(onumm1n20_t* num);
  void onumm1n20_cosh_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_sinh(onumm1n20_t* num);
  void onumm1n20_sinh_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_asin(onumm1n20_t* num);
  void onumm1n20_asin_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_acos(onumm1n20_t* num);
  void onumm1n20_acos_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_atan(onumm1n20_t* num);
  void onumm1n20_atan_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_tan(onumm1n20_t* num);
  void onumm1n20_tan_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_cos(onumm1n20_t* num);
  void onumm1n20_cos_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_sin(onumm1n20_t* num );
  void onumm1n20_sin_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_logb(onumm1n20_t* num, double base);
  void onumm1n20_logb_to(onumm1n20_t* num, double base, onumm1n20_t* res);
  onumm1n20_t onumm1n20_log10(onumm1n20_t* num);
  void onumm1n20_log10_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_log(onumm1n20_t* num);
  void onumm1n20_log_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_exp(onumm1n20_t* num);
  void onumm1n20_exp_to(onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_pow(onumm1n20_t* num, double e);
  void onumm1n20_pow_to(onumm1n20_t* num, coeff_t e, onumm1n20_t* res);
  
  
  # From ../../../include/oti/static/onumm1n20/scalar/base.h
  
  void onumm1n20_set_im_o(onumm1n20_t* num, imdir_t idx, ord_t order, onumm1n20_t* res);
  void onumm1n20_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm1n20_t* res);
  void onumm1n20_set_deriv_o(onumm1n20_t* num, imdir_t idx, ord_t order, onumm1n20_t* res);
  void onumm1n20_extract_im_to( imdir_t idx, ord_t order, onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_extract_im(imdir_t idx, ord_t order, onumm1n20_t* num);
  onumm1n20_t onumm1n20_extract_deriv(imdir_t idx, ord_t order, onumm1n20_t* num);
  void onumm1n20_extract_deriv_to(imdir_t idx, ord_t order, onumm1n20_t* num, onumm1n20_t* res);
  void onumm1n20_get_im_to_o(imdir_t idx, ord_t order, onumm1n20_t* num, onumm1n20_t* res);
  onumm1n20_t onumm1n20_get_im_o(imdir_t idx, ord_t order, onumm1n20_t* num);
  void onumm1n20_get_im_to_r(imdir_t idx, ord_t order, onumm1n20_t* num, coeff_t* res);
  ord_t onumm1n20_get_order(onumm1n20_t* lhs);
  onumm1n20_t onumm1n20_get_deriv_o( imdir_t idx, ord_t order, onumm1n20_t* num);
  void onumm1n20_get_deriv_to( imdir_t idx, ord_t order, onumm1n20_t* num, onumm1n20_t* res);
  void onumm1n20_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm1n20_t* res);
  onumm1n20_t onumm1n20_init();
  ndir_t onumm1n20_get_ndir_order(ord_t order, onumm1n20_t* num);
  ndir_t onumm1n20_get_ndir_total(onumm1n20_t* num);
  coeff_t* onumm1n20_get_order_address(ord_t order, onumm1n20_t* num);
  onumm1n20_t onumm1n20_create_r(  coeff_t lhs);
  void onumm1n20_set_r(  coeff_t lhs, onumm1n20_t* res);
  void onumm1n20_set_o(  onumm1n20_t* lhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_get_order_im(ord_t order, onumm1n20_t* lhs);
  void onumm1n20_get_order_im_to(ord_t order, onumm1n20_t* lhs, onumm1n20_t* res);
  coeff_t onumm1n20_get_item(imdir_t idx, ord_t order, onumm1n20_t* lhs);
  coeff_t onumm1n20_get_deriv(imdir_t idx, ord_t order, onumm1n20_t* lhs);
  void onumm1n20_set_item(coeff_t val, imdir_t idx, ord_t order, onumm1n20_t* x);
  onumm1n20_t onumm1n20_copy(  onumm1n20_t* lhs);
  void onumm1n20_copy_to(  onumm1n20_t* lhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_taylor_integrate(coeff_t* deltas,onumm1n20_t* lhs);
  void onumm1n20_taylor_integrate_to(coeff_t* deltas,onumm1n20_t* lhs, onumm1n20_t* res);
  onumm1n20_t onumm1n20_truncate_im(imdir_t idx, ord_t order, onumm1n20_t* lhs);
  void onumm1n20_truncate_im_to(imdir_t idx, ord_t order, onumm1n20_t* lhs, onumm1n20_t* res);
  void onumm1n20_print(  onumm1n20_t* lhs);
  imdir_t onumm1n20_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm1n20/scalar/gauss/utils.h
  
  void feonumm1n20_dimCheck(feonumm1n20_t* arr1,feonumm1n20_t* arr2);
  void feonumm1n20_get_active_bases(feonumm1n20_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n20/scalar/gauss/algebra.h
  
  feonumm1n20_t feonumm1n20_neg(   feonumm1n20_t* num);
  void     feonumm1n20_neg_to(feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_sum_ff(   feonumm1n20_t* lhs, feonumm1n20_t* rhs);
  void     feonumm1n20_sum_ff_to(feonumm1n20_t* lhs, feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_sum_of(   onumm1n20_t* lhs, feonumm1n20_t* rhs);
  void     feonumm1n20_sum_of_to(onumm1n20_t* lhs, feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_sum_rf(   coeff_t lhs, feonumm1n20_t* rhs);
  void     feonumm1n20_sum_rf_to(coeff_t lhs, feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_sub_ff(     feonumm1n20_t* lhs,  feonumm1n20_t* rhs);
  void     feonumm1n20_sub_ff_to(  feonumm1n20_t* lhs,  feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_sub_of(    onumm1n20_t* lhs,  feonumm1n20_t* rhs);
  void     feonumm1n20_sub_of_to( onumm1n20_t* lhs,  feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_sub_fo(     feonumm1n20_t* lhs, onumm1n20_t* rhs);
  void     feonumm1n20_sub_fo_to(  feonumm1n20_t* lhs, onumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_sub_rf(       coeff_t lhs,  feonumm1n20_t* rhs);
  void     feonumm1n20_sub_rf_to(    coeff_t lhs,  feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_sub_fr(     feonumm1n20_t* lhs,    coeff_t rhs);
  void     feonumm1n20_sub_fr_to(  feonumm1n20_t* lhs,    coeff_t rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_mul_ff(   feonumm1n20_t* lhs, feonumm1n20_t* rhs);
  void     feonumm1n20_mul_ff_to(feonumm1n20_t* lhs, feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_mul_of(   onumm1n20_t* lhs, feonumm1n20_t* rhs);
  void     feonumm1n20_mul_of_to(onumm1n20_t* lhs, feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_mul_rf(   coeff_t lhs, feonumm1n20_t* rhs);
  void     feonumm1n20_mul_rf_to(coeff_t lhs, feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_div_ff(     feonumm1n20_t* lhs,  feonumm1n20_t* rhs);
  void     feonumm1n20_div_ff_to(  feonumm1n20_t* lhs,  feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_div_of(    onumm1n20_t* lhs,  feonumm1n20_t* rhs);
  void     feonumm1n20_div_of_to( onumm1n20_t* lhs,  feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_div_fo(     feonumm1n20_t* lhs, onumm1n20_t* rhs);
  void     feonumm1n20_div_fo_to(  feonumm1n20_t* lhs, onumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_div_rf(       coeff_t lhs,  feonumm1n20_t* rhs);
  void     feonumm1n20_div_rf_to(    coeff_t lhs,  feonumm1n20_t* rhs, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_div_fr(     feonumm1n20_t* lhs,    coeff_t rhs);
  void     feonumm1n20_div_fr_to(  feonumm1n20_t* lhs,    coeff_t rhs, feonumm1n20_t* res);
  
  
  # From ../../../include/oti/static/onumm1n20/scalar/gauss/functions.h
  
  feonumm1n20_t feonumm1n20_atanh(    feonumm1n20_t* num);
  void     feonumm1n20_atanh_to( feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_asinh(    feonumm1n20_t* num);
  void     feonumm1n20_asinh_to( feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_acosh(    feonumm1n20_t* num);
  void     feonumm1n20_acosh_to( feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_tanh(     feonumm1n20_t* num);
  void     feonumm1n20_tanh_to(  feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_cosh(     feonumm1n20_t* num);
  void     feonumm1n20_cosh_to(  feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_sinh(     feonumm1n20_t* num);
  void     feonumm1n20_sinh_to(  feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_asin(     feonumm1n20_t* num);
  void     feonumm1n20_asin_to(  feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_acos(     feonumm1n20_t* num);
  void     feonumm1n20_acos_to(  feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_atan(     feonumm1n20_t* num);
  void     feonumm1n20_atan_to(  feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_tan(      feonumm1n20_t* num);
  void     feonumm1n20_tan_to(   feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_cos(      feonumm1n20_t* num);
  void     feonumm1n20_cos_to(   feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_sin(      feonumm1n20_t* num);
  void     feonumm1n20_sin_to(   feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_logb(     feonumm1n20_t* num, double base);
  void     feonumm1n20_logb_to(  feonumm1n20_t* num, double base, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_log10(    feonumm1n20_t* num);
  void     feonumm1n20_log10_to( feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_log(      feonumm1n20_t* num);
  void     feonumm1n20_log_to(   feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_exp(      feonumm1n20_t* num);
  void     feonumm1n20_exp_to(   feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_cbrt(     feonumm1n20_t* num);
  void     feonumm1n20_cbrt_to(  feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_sqrt(     feonumm1n20_t* num);
  void     feonumm1n20_sqrt_to(  feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_pow(      feonumm1n20_t* num, double e);
  void     feonumm1n20_pow_to(   feonumm1n20_t* num, double e, feonumm1n20_t* res);
  onumm1n20_t feonumm1n20_integrate(       feonumm1n20_t* num, feonumm1n20_t* w);
  void      feonumm1n20_integrate_to(    feonumm1n20_t* num, feonumm1n20_t* w, onumm1n20_t* res);
  onumm1n20_t feonumm1n20_integrate_f(     feonumm1n20_t* num, feonumm1n20_t* w);
  void      feonumm1n20_integrate_f_to(  feonumm1n20_t* num, feonumm1n20_t* w, onumm1n20_t* res);
  onumm1n20_t feonumm1n20_integrate_r(       coeff_t num, feonumm1n20_t* w);
  void      feonumm1n20_integrate_r_to(    coeff_t num, feonumm1n20_t* w, onumm1n20_t* res);
  onumm1n20_t feonumm1n20_integrate_o(    onumm1n20_t* num, feonumm1n20_t* w);
  void      feonumm1n20_integrate_o_to( onumm1n20_t* num, feonumm1n20_t* w, onumm1n20_t* res);
  
  
  # From ../../../include/oti/static/onumm1n20/scalar/gauss/base.h
  
  void     feonumm1n20_get_order_im_to( ord_t order, feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_get_order_im(    ord_t order, feonumm1n20_t* num);
  feonumm1n20_t feonumm1n20_get_im(    imdir_t idx, ord_t order, feonumm1n20_t* num);
  void     feonumm1n20_get_im_to( imdir_t idx, ord_t order, feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_get_deriv(    imdir_t idx, ord_t order, feonumm1n20_t* num);
  void     feonumm1n20_get_deriv_to( imdir_t idx, ord_t order, feonumm1n20_t* num, feonumm1n20_t* res);
  void feonumm1n20_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm1n20_t* num);
  void feonumm1n20_set_im_o( onumm1n20_t* val, imdir_t idx, ord_t order, feonumm1n20_t* num);
  void feonumm1n20_set_im_f(  feonumm1n20_t* val, imdir_t idx, ord_t order, feonumm1n20_t* num);
  void feonumm1n20_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm1n20_t* num);
  void feonumm1n20_set_deriv_o( onumm1n20_t* val, imdir_t idx, ord_t order, feonumm1n20_t* num);
  void feonumm1n20_set_deriv_f(  feonumm1n20_t* val, imdir_t idx, ord_t order, feonumm1n20_t* num);
  feonumm1n20_t feonumm1n20_extract_im(    imdir_t idx, ord_t order, feonumm1n20_t* num);
  void     feonumm1n20_extract_im_to( imdir_t idx, ord_t order, feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_extract_deriv(    imdir_t idx, ord_t order, feonumm1n20_t* num);
  void     feonumm1n20_extract_deriv_to( imdir_t idx, ord_t order, feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_truncate_im(    imdir_t idx, ord_t order, feonumm1n20_t* num);
  void     feonumm1n20_truncate_im_to( imdir_t idx, ord_t order, feonumm1n20_t* num, feonumm1n20_t* res);
  feonumm1n20_t feonumm1n20_copy(    feonumm1n20_t* src);
  void     feonumm1n20_copy_to( feonumm1n20_t* src, feonumm1n20_t* dst);
  void feonumm1n20_set_r(    coeff_t num, feonumm1n20_t* res);
  void feonumm1n20_set_o( onumm1n20_t* num, feonumm1n20_t* res);
  void feonumm1n20_set_f(  feonumm1n20_t* num, feonumm1n20_t* res);
  void feonumm1n20_set_item_k_r(   coeff_t  num, uint64_t k, feonumm1n20_t* res);
  void feonumm1n20_set_item_k_o( onumm1n20_t* num, uint64_t k, feonumm1n20_t* res);
  onumm1n20_t feonumm1n20_get_item_k(   feonumm1n20_t* num, uint64_t k);
  void      feonumm1n20_get_item_k_to(feonumm1n20_t* num, uint64_t k, onumm1n20_t* res);
  feonumm1n20_t feonumm1n20_zeros(uint64_t nIntPts);
  feonumm1n20_t feonumm1n20_createEmpty(uint64_t nIntPts);
  feonumm1n20_t feonumm1n20_empty_like(feonumm1n20_t* arr);
  void feonumm1n20_free(feonumm1n20_t* num);
  ord_t feonumm1n20_get_order( feonumm1n20_t* num );
  feonumm1n20_t feonumm1n20_init();
  
  