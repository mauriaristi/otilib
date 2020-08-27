cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm1n2/scalar/structures.h
  
  ctypedef struct  onumm1n2_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e11;
  # } onumm1n2_t;
  
  
  # From ../../../include/oti/static/onumm1n2/array/structures.h
  
  ctypedef struct  oarrm1n2_t : # {
      onumm1n2_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
      flag_t          flag;
  # } oarrm1n2_t;
  
  
  # From ../../../include/oti/static/onumm1n2/scalar/gauss/structures.h
  
  ctypedef struct  feonumm1n2_t: # {
      onumm1n2_t*  p_data;
      uint64_t    nip;
  # } feonumm1n2_t;
  
  
  # From ../../../include/oti/static/onumm1n2/array/gauss/structures.h
  
  ctypedef struct  feoarrm1n2_t: # {
      oarrm1n2_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm1n2_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm1n2/array/utils.h
  
  void oarrm1n2_dimCheck_OO_elementwise(oarrm1n2_t* arr1, oarrm1n2_t* arr2, oarrm1n2_t* res);
  void oarrm1n2_dimCheck_RO_elementwise(darr_t*  arr1, oarrm1n2_t* arr2, oarrm1n2_t* res);
  void oarrm1n2_dimCheck_OO_matmul(oarrm1n2_t* arr1, oarrm1n2_t* arr2, oarrm1n2_t* res);
  void oarrm1n2_dimCheck_RO_matmul(darr_t*  arr1, oarrm1n2_t* arr2, oarrm1n2_t* res);
  void oarrm1n2_dimCheck_OR_matmul(oarrm1n2_t* arr1, darr_t*  arr2, oarrm1n2_t* res);
  void oarrm1n2_dimCheck_O_squareness(oarrm1n2_t* arr1, oarrm1n2_t* res);
  void oarrm1n2_dimCheck_OO_samesize(oarrm1n2_t* arr1, oarrm1n2_t* res);
  void oarrm1n2_dimCheck_RO_samesize(darr_t* arr1, oarrm1n2_t* res);
  ord_t oarrm1n2_get_order(oarrm1n2_t* arr);
  void oarrm1n2_get_active_bases(oarrm1n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n2/array/algebra_elementwise.h
  
  oarrm1n2_t oarrm1n2_neg(oarrm1n2_t* arr);
  void oarrm1n2_neg_to(oarrm1n2_t* rhs, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_sum_OO(oarrm1n2_t*   lhs, oarrm1n2_t* rhs);
  oarrm1n2_t oarrm1n2_sum_RO(darr_t*    lhs, oarrm1n2_t* rhs);
  oarrm1n2_t oarrm1n2_sum_oO(onumm1n2_t* lhs, oarrm1n2_t* rhs);
  oarrm1n2_t oarrm1n2_sum_rO(coeff_t    lhs, oarrm1n2_t* rhs);
  void oarrm1n2_sum_OO_to(oarrm1n2_t*   lhs, oarrm1n2_t* rhs, oarrm1n2_t* res);
  void oarrm1n2_sum_RO_to(darr_t*    lhs, oarrm1n2_t* rhs, oarrm1n2_t* res);
  void oarrm1n2_sum_oO_to(onumm1n2_t* lhs, oarrm1n2_t* rhs, oarrm1n2_t* res);
  void oarrm1n2_sum_rO_to(coeff_t    lhs, oarrm1n2_t* rhs, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_sub_OO(oarrm1n2_t*   lhs, oarrm1n2_t*   rhs);
  oarrm1n2_t oarrm1n2_sub_RO(darr_t*    lhs, oarrm1n2_t*   rhs);
  oarrm1n2_t oarrm1n2_sub_OR(oarrm1n2_t*   lhs, darr_t*    rhs);
  oarrm1n2_t oarrm1n2_sub_oO(onumm1n2_t* lhs, oarrm1n2_t*   rhs);
  oarrm1n2_t oarrm1n2_sub_Oo(oarrm1n2_t*   lhs, onumm1n2_t* rhs);
  oarrm1n2_t oarrm1n2_sub_rO(coeff_t    lhs, oarrm1n2_t*   rhs);
  oarrm1n2_t oarrm1n2_sub_Or(oarrm1n2_t*   lhs, coeff_t    rhs);
  void oarrm1n2_sub_OO_to( oarrm1n2_t*   lhs, oarrm1n2_t*   rhs, oarrm1n2_t* res);
  void oarrm1n2_sub_RO_to( darr_t*    lhs, oarrm1n2_t*   rhs, oarrm1n2_t* res);
  void oarrm1n2_sub_OR_to( oarrm1n2_t*   lhs, darr_t*    rhs, oarrm1n2_t* res);
  void oarrm1n2_sub_oO_to( onumm1n2_t* lhs, oarrm1n2_t*   rhs, oarrm1n2_t* res);
  void oarrm1n2_sub_Oo_to( oarrm1n2_t*   lhs, onumm1n2_t* rhs, oarrm1n2_t* res);
  void oarrm1n2_sub_rO_to( coeff_t    lhs, oarrm1n2_t*   rhs, oarrm1n2_t* res);
  void oarrm1n2_sub_Or_to( oarrm1n2_t*   lhs, coeff_t    rhs, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_mul_OO(oarrm1n2_t*   lhs, oarrm1n2_t* rhs);
  oarrm1n2_t oarrm1n2_mul_RO(darr_t*    lhs, oarrm1n2_t* rhs);
  oarrm1n2_t oarrm1n2_mul_oO(onumm1n2_t* lhs, oarrm1n2_t* rhs);
  oarrm1n2_t oarrm1n2_mul_rO(coeff_t    lhs, oarrm1n2_t* rhs);
  void oarrm1n2_mul_OO_to(oarrm1n2_t*   lhs, oarrm1n2_t* rhs, oarrm1n2_t* res);
  void oarrm1n2_mul_RO_to(darr_t*    lhs, oarrm1n2_t* rhs, oarrm1n2_t* res);
  void oarrm1n2_mul_oO_to(onumm1n2_t* lhs, oarrm1n2_t* rhs, oarrm1n2_t* res);
  void oarrm1n2_mul_rO_to(coeff_t    lhs, oarrm1n2_t* rhs, oarrm1n2_t* res);
  void oarrm1n2_gem_OO_to(  oarrm1n2_t* arr1, oarrm1n2_t* arr2, oarrm1n2_t* arr3, oarrm1n2_t* res);
  void oarrm1n2_gem_oO_to(onumm1n2_t* arr1, oarrm1n2_t* arr2, oarrm1n2_t* arr3, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_div_OO(oarrm1n2_t*   lhs, oarrm1n2_t*   rhs);
  oarrm1n2_t oarrm1n2_div_OR(oarrm1n2_t*   lhs, darr_t*    rhs);
  oarrm1n2_t oarrm1n2_div_RO(darr_t*    lhs, oarrm1n2_t*   rhs);
  oarrm1n2_t oarrm1n2_div_oO(onumm1n2_t* lhs, oarrm1n2_t*   rhs);
  oarrm1n2_t oarrm1n2_div_Oo(oarrm1n2_t*   lhs, onumm1n2_t* rhs);
  oarrm1n2_t oarrm1n2_div_rO(coeff_t    lhs, oarrm1n2_t*   rhs);
  oarrm1n2_t oarrm1n2_div_Or(oarrm1n2_t*   lhs, coeff_t    rhs);
  void oarrm1n2_div_OO_to(oarrm1n2_t*   lhs, oarrm1n2_t*   rhs, oarrm1n2_t* res);
  void oarrm1n2_div_RO_to(darr_t*    lhs, oarrm1n2_t*   rhs, oarrm1n2_t* res);
  void oarrm1n2_div_OR_to(oarrm1n2_t*   lhs, darr_t*    rhs, oarrm1n2_t* res);
  void oarrm1n2_div_oO_to(onumm1n2_t* lhs, oarrm1n2_t*   rhs, oarrm1n2_t* res);
  void oarrm1n2_div_Oo_to(oarrm1n2_t*   lhs, onumm1n2_t* rhs, oarrm1n2_t* res);
  void oarrm1n2_div_rO_to(coeff_t    lhs, oarrm1n2_t*   rhs, oarrm1n2_t* res);
  void oarrm1n2_div_Or_to(oarrm1n2_t*   lhs, coeff_t    rhs, oarrm1n2_t* res);
  
  
  # From ../../../include/oti/static/onumm1n2/array/algebra_matops.h
  
  onumm1n2_t oarrm1n2_dotproduct_OO(    oarrm1n2_t* lhs, oarrm1n2_t* rhs);
  void      oarrm1n2_dotproduct_OO_to( oarrm1n2_t* lhs, oarrm1n2_t* rhs, onumm1n2_t* res);
  onumm1n2_t oarrm1n2_dotproduct_RO(     darr_t* lhs, oarrm1n2_t* rhs);
  void      oarrm1n2_dotproduct_RO_to(  darr_t* lhs, oarrm1n2_t* rhs, onumm1n2_t* res);
  oarrm1n2_t oarrm1n2_matmul_OO(    oarrm1n2_t* lhs, oarrm1n2_t* rhs);
  oarrm1n2_t oarrm1n2_matmul_OR(    oarrm1n2_t* lhs,  darr_t* rhs);
  oarrm1n2_t oarrm1n2_matmul_RO(     darr_t* lhs, oarrm1n2_t* rhs);
  void    oarrm1n2_matmul_OO_to( oarrm1n2_t* lhs, oarrm1n2_t* rhs, oarrm1n2_t* res);
  void    oarrm1n2_matmul_OR_to( oarrm1n2_t* lhs,  darr_t* rhs, oarrm1n2_t* res);
  void    oarrm1n2_matmul_RO_to(  darr_t* lhs, oarrm1n2_t* rhs, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_transpose(    oarrm1n2_t* arr1);
  void    oarrm1n2_transpose_to( oarrm1n2_t* arr1, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_invert(    oarrm1n2_t* arr1);
  void    oarrm1n2_invert_to( oarrm1n2_t* arr1, oarrm1n2_t* res);
  onumm1n2_t oarrm1n2_det(    oarrm1n2_t* arr1);
  void      oarrm1n2_det_to( oarrm1n2_t* arr1, onumm1n2_t* res);
  onumm1n2_t oarrm1n2_norm(    oarrm1n2_t* arr1);
  void      oarrm1n2_norm_to( oarrm1n2_t* arr1,  onumm1n2_t* res);
  onumm1n2_t oarrm1n2_pnorm(    oarrm1n2_t* arr1, coeff_t p);
  void      oarrm1n2_pnorm_to( oarrm1n2_t* arr1, coeff_t p, onumm1n2_t* res);
  
  
  # From ../../../include/oti/static/onumm1n2/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm1n2/array/functions.h
  
  oarrm1n2_t oarrm1n2_atanh(   oarrm1n2_t* arr);
  void    oarrm1n2_atanh_to(oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_asinh(   oarrm1n2_t* arr);
  void    oarrm1n2_asinh_to(oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_acosh(   oarrm1n2_t* arr);
  void    oarrm1n2_acosh_to(oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_tanh(    oarrm1n2_t* arr);
  void    oarrm1n2_tanh_to( oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_cbrt(    oarrm1n2_t* arr);
  void    oarrm1n2_cbrt_to( oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_sqrt(    oarrm1n2_t* arr);
  void    oarrm1n2_sqrt_to( oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_cosh(    oarrm1n2_t* arr);
  void    oarrm1n2_cosh_to( oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_sinh(    oarrm1n2_t* arr);
  void    oarrm1n2_sinh_to( oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_asin(    oarrm1n2_t* arr);
  void    oarrm1n2_asin_to( oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_acos(    oarrm1n2_t* arr);
  void    oarrm1n2_acos_to( oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_atan(    oarrm1n2_t* arr);
  void    oarrm1n2_atan_to( oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_tan(     oarrm1n2_t* arr);
  void    oarrm1n2_tan_to(  oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_cos(     oarrm1n2_t* arr);
  void    oarrm1n2_cos_to(  oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_sin(     oarrm1n2_t* arr);
  void    oarrm1n2_sin_to(  oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_logb(    oarrm1n2_t* arr, double base);
  void    oarrm1n2_logb_to( oarrm1n2_t* arr, double base, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_log10(   oarrm1n2_t* arr);
  void    oarrm1n2_log10_to(oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_log(     oarrm1n2_t* arr);
  void    oarrm1n2_log_to(  oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_exp(     oarrm1n2_t* arr);
  void    oarrm1n2_exp_to(  oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_pow(     oarrm1n2_t* arr, double e);
  void    oarrm1n2_pow_to(  oarrm1n2_t* arr, double e, oarrm1n2_t* res);
  
  
  # From ../../../include/oti/static/onumm1n2/array/base.h
  
  void    oarrm1n2_taylor_integrate_to( coeff_t* deltas, oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_taylor_integrate(    coeff_t* deltas, oarrm1n2_t* arr);
  void    oarrm1n2_get_order_im_to( ord_t order, oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_get_order_im(    ord_t order, oarrm1n2_t* arr);
  void oarrm1n2_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n2_t* res);
  void oarrm1n2_set_slice_O( oarrm1n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n2_t* res);
  void oarrm1n2_set_slice_o( onumm1n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_get_slice( oarrm1n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm1n2_get_slice_to( oarrm1n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_truncate_im(    imdir_t idx, ord_t order, oarrm1n2_t* arr);
  void    oarrm1n2_truncate_im_to( imdir_t idx, ord_t order, oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_extract_im(   imdir_t idx, ord_t order, oarrm1n2_t* arr);
  void    oarrm1n2_extract_im_to(imdir_t idx, ord_t order, oarrm1n2_t* arr, oarrm1n2_t* res);
  darr_t  oarrm1n2_get_deriv(    imdir_t idx, ord_t order, oarrm1n2_t* arr);
  void    oarrm1n2_get_deriv_to( imdir_t idx, ord_t order, oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_get_deriv_o(  imdir_t idx, ord_t order, oarrm1n2_t* arr);
  oarrm1n2_t oarrm1n2_extract_deriv(    imdir_t idx, ord_t order, oarrm1n2_t* arr);
  void    oarrm1n2_extract_deriv_to( imdir_t idx, ord_t order, oarrm1n2_t* arr, oarrm1n2_t* res);
  darr_t  oarrm1n2_get_im(   imdir_t idx, ord_t order, oarrm1n2_t* arr);
  oarrm1n2_t oarrm1n2_get_im_o( imdir_t idx, ord_t order, oarrm1n2_t* arr);
  void    oarrm1n2_get_im_to(imdir_t idx, ord_t order, oarrm1n2_t* arr, oarrm1n2_t* res);
  void    oarrm1n2_copy_to(oarrm1n2_t* arr, oarrm1n2_t* res);
  oarrm1n2_t oarrm1n2_copy(oarrm1n2_t* arr);
  void oarrm1n2_set_all_r( coeff_t num, oarrm1n2_t* arr);
  void oarrm1n2_set_item_i_r( coeff_t num, uint64_t i, oarrm1n2_t* arr);
  void oarrm1n2_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm1n2_t* arr);
  void oarrm1n2_set_r(   coeff_t  num,   oarrm1n2_t* arr);
  void oarrm1n2_set_o( onumm1n2_t* num,   oarrm1n2_t* arr);
  void oarrm1n2_set_O(   oarrm1n2_t* arrin, oarrm1n2_t* arr);
  void oarrm1n2_set_all_o( onumm1n2_t* src, oarrm1n2_t* arr);
  void oarrm1n2_set_item_i_o( onumm1n2_t* num, uint64_t i, oarrm1n2_t* arr);
  void oarrm1n2_set_item_ij_o( onumm1n2_t* num, uint64_t i, uint64_t j, oarrm1n2_t* arr);
  onumm1n2_t oarrm1n2_get_item_i(    oarrm1n2_t* arr, uint64_t i);
  void      oarrm1n2_get_item_i_to( oarrm1n2_t* arr, uint64_t i,             onumm1n2_t* res);
  onumm1n2_t oarrm1n2_get_item_ij(   oarrm1n2_t* arr, uint64_t i, uint64_t j);
  void      oarrm1n2_get_item_ij_to(oarrm1n2_t* arr, uint64_t i, uint64_t j, onumm1n2_t* res);
  oarrm1n2_t oarrm1n2_init();
  void oarrm1n2_free(oarrm1n2_t* arr);
  oarrm1n2_t oarrm1n2_empty_like(oarrm1n2_t* arr);
  oarrm1n2_t oarrm1n2_eye(uint64_t nrows);
  oarrm1n2_t oarrm1n2_ones(uint64_t nrows, uint64_t ncols);
  oarrm1n2_t oarrm1n2_zeros(uint64_t nrows, uint64_t ncols);
  oarrm1n2_t oarrm1n2_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm1n2/array/gauss/utils.h
  
  void feoarrm1n2_dimCheck_FF_samesize(feoarrm1n2_t* arr1, feoarrm1n2_t* arr2, feonumm1n2_t* res);
  void feoarrm1n2_dimCheck_OF_samesize(  oarrm1n2_t* arr1, feoarrm1n2_t* arr2, feonumm1n2_t* res);
  void feoarrm1n2_dimCheck_RF_samesize(   darr_t* arr1, feoarrm1n2_t* arr2, feonumm1n2_t* res);
  void feoarrm1n2_dimCheck_FF_elementwise(feoarrm1n2_t* arr1, feoarrm1n2_t* arr2, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_OF_elementwise(  oarrm1n2_t* arr1, feoarrm1n2_t* arr2, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm1n2_t* arr2, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_fF_elementwise( feonumm1n2_t* num1, feoarrm1n2_t* arr2, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_Ff_elementwise(feoarrm1n2_t* arr1,  feonumm1n2_t* num2, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_FF_matmul( feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_OF_matmul(   oarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_FO_matmul( feoarrm1n2_t* lhs,   oarrm1n2_t* rhs, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_FR_matmul( feoarrm1n2_t* lhs,    darr_t* rhs, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_F_squareness( feoarrm1n2_t* arr1, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_F_transpose( feoarrm1n2_t* arr1, feoarrm1n2_t* res);
  void feoarrm1n2_dimCheck_FfO_integrate(feoarrm1n2_t* arr, feonumm1n2_t* num,oarrm1n2_t* res);
  void feoarrm1n2_get_active_bases(feoarrm1n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n2/array/gauss/algebra.h
  
  feoarrm1n2_t feoarrm1n2_neg(    feoarrm1n2_t* arr);
  void      feoarrm1n2_neg_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sum_FF(   feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sum_FF_to(feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sum_fF(    feonumm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sum_fF_to( feonumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sum_OF(     oarrm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sum_OF_to(  oarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sum_RF(      darr_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sum_RF_to(   darr_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sum_oF(   onumm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sum_oF_to(onumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sum_rF(     coeff_t  lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sum_rF_to(  coeff_t  lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sub_FF(    feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sub_FF_to( feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sub_fF(    feonumm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sub_fF_to( feonumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sub_Ff(    feoarrm1n2_t* lhs, feonumm1n2_t* rhs);
  void      feoarrm1n2_sub_Ff_to( feoarrm1n2_t* lhs, feonumm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sub_OF(      oarrm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sub_OF_to(   oarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sub_FO(    feoarrm1n2_t* lhs,   oarrm1n2_t* rhs);
  void      feoarrm1n2_sub_FO_to( feoarrm1n2_t* lhs,   oarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sub_RF(       darr_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sub_RF_to(    darr_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sub_FR(    feoarrm1n2_t* lhs,    darr_t* rhs);
  void      feoarrm1n2_sub_FR_to( feoarrm1n2_t* lhs,    darr_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sub_oF(    onumm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sub_oF_to( onumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sub_Fo(    feoarrm1n2_t* lhs, onumm1n2_t* rhs);
  void      feoarrm1n2_sub_Fo_to( feoarrm1n2_t* lhs, onumm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sub_rF(      coeff_t  lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_sub_rF_to(    coeff_t lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sub_Fr(    feoarrm1n2_t* lhs,   coeff_t  rhs);
  void      feoarrm1n2_sub_Fr_to( feoarrm1n2_t* lhs,   coeff_t  rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_mul_FF(   feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_mul_FF_to(feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_mul_fF(    feonumm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_mul_fF_to( feonumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_mul_OF(     oarrm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_mul_OF_to(  oarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_mul_RF(      darr_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_mul_RF_to(   darr_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_mul_oF(   onumm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_mul_oF_to(onumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_mul_rF(     coeff_t  lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_mul_rF_to(  coeff_t  lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_div_FF(    feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_div_FF_to( feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_div_fF(     feonumm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_div_fF_to(  feonumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_div_Ff(    feoarrm1n2_t* lhs,  feonumm1n2_t* rhs);
  void      feoarrm1n2_div_Ff_to( feoarrm1n2_t* lhs,  feonumm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_div_OF(      oarrm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_div_OF_to(   oarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_div_FO(    feoarrm1n2_t* lhs,   oarrm1n2_t* rhs);
  void      feoarrm1n2_div_FO_to( feoarrm1n2_t* lhs,   oarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_div_RF(       darr_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_div_RF_to(    darr_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_div_FR(    feoarrm1n2_t* lhs,    darr_t* rhs);
  void      feoarrm1n2_div_FR_to( feoarrm1n2_t* lhs,    darr_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_div_oF(    onumm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_div_oF_to( onumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_div_Fo(    feoarrm1n2_t* lhs, onumm1n2_t* rhs);
  void      feoarrm1n2_div_Fo_to( feoarrm1n2_t* lhs, onumm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_div_rF(      coeff_t  lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_div_rF_to(    coeff_t lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_div_Fr(    feoarrm1n2_t* lhs,   coeff_t  rhs);
  void      feoarrm1n2_div_Fr_to( feoarrm1n2_t* lhs,   coeff_t  rhs, feoarrm1n2_t* res);
  oarrm1n2_t feoarrm1n2_integrate(    feoarrm1n2_t* arr, feonumm1n2_t* w);
  void    feoarrm1n2_integrate_to( feoarrm1n2_t* arr, feonumm1n2_t* w, oarrm1n2_t* res);
  feonumm1n2_t feoarrm1n2_dotproduct_FF(    feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
  void     feoarrm1n2_dotproduct_FF_to( feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feoarrm1n2_dotproduct_OF(      oarrm1n2_t* lhs, feoarrm1n2_t* rhs);
  void     feoarrm1n2_dotproduct_OF_to(   oarrm1n2_t* lhs, feoarrm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feoarrm1n2_dotproduct_RF(       darr_t* lhs, feoarrm1n2_t* rhs);
  void     feoarrm1n2_dotproduct_RF_to(    darr_t* lhs, feoarrm1n2_t* rhs, feonumm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_matmul_FF(    feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_matmul_FF_to( feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_matmul_OF(    oarrm1n2_t*   lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_matmul_OF_to( oarrm1n2_t*   lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_matmul_FO(    feoarrm1n2_t* lhs, oarrm1n2_t*   rhs);
  void      feoarrm1n2_matmul_FO_to( feoarrm1n2_t* lhs, oarrm1n2_t*   rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_matmul_RF(    darr_t*    lhs, feoarrm1n2_t* rhs);
  void      feoarrm1n2_matmul_RF_to( darr_t*    lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_matmul_FR(    feoarrm1n2_t* lhs, darr_t*    rhs);
  void      feoarrm1n2_matmul_FR_to( feoarrm1n2_t* lhs, darr_t*    rhs, feoarrm1n2_t* res);
  feonumm1n2_t feoarrm1n2_det(   feoarrm1n2_t* arr);
  void     feoarrm1n2_det_to(feoarrm1n2_t* arr, feonumm1n2_t* res);
  feonumm1n2_t feoarrm1n2_norm(     feoarrm1n2_t* arr);
  void     feoarrm1n2_norm_to(  feoarrm1n2_t* arr, feonumm1n2_t* res);
  feonumm1n2_t feoarrm1n2_pnorm(    feoarrm1n2_t* arr, coeff_t p);
  void     feoarrm1n2_pnorm_to( feoarrm1n2_t* arr, coeff_t p, feonumm1n2_t* res);
  feoarrm1n2_t   feoarrm1n2_invert(    feoarrm1n2_t* arr);
  void        feoarrm1n2_invert_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t   feoarrm1n2_transpose(   feoarrm1n2_t* arr);
  void        feoarrm1n2_transpose_to(feoarrm1n2_t* arr, feoarrm1n2_t* res);
  
  
  # From ../../../include/oti/static/onumm1n2/array/gauss/functions.h
  
  feoarrm1n2_t feoarrm1n2_atanh(    feoarrm1n2_t* arr);
  void      feoarrm1n2_atanh_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_asinh(    feoarrm1n2_t* arr);
  void      feoarrm1n2_asinh_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_acosh(    feoarrm1n2_t* arr);
  void      feoarrm1n2_acosh_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_tanh(     feoarrm1n2_t* arr);
  void      feoarrm1n2_tanh_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sinh(     feoarrm1n2_t* arr);
  void      feoarrm1n2_sinh_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_cosh(     feoarrm1n2_t* arr);
  void      feoarrm1n2_cosh_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_atan(     feoarrm1n2_t* arr);
  void      feoarrm1n2_atan_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_asin(     feoarrm1n2_t* arr);
  void      feoarrm1n2_asin_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_acos(     feoarrm1n2_t* arr);
  void      feoarrm1n2_acos_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_tan(      feoarrm1n2_t* arr);
  void      feoarrm1n2_tan_to(   feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sin(      feoarrm1n2_t* arr);
  void      feoarrm1n2_sin_to(   feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_cos(      feoarrm1n2_t* arr);
  void      feoarrm1n2_cos_to(   feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_logb(     feoarrm1n2_t* arr, double base);
  void      feoarrm1n2_logb_to(  feoarrm1n2_t* arr, double base, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_log10(    feoarrm1n2_t* arr);
  void      feoarrm1n2_log10_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_log(      feoarrm1n2_t* arr);
  void      feoarrm1n2_log_to(   feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_exp(      feoarrm1n2_t* arr);
  void      feoarrm1n2_exp_to(   feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_cbrt(     feoarrm1n2_t* arr);
  void      feoarrm1n2_cbrt_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_sqrt(     feoarrm1n2_t* arr);
  void      feoarrm1n2_sqrt_to(  feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_pow(      feoarrm1n2_t* arr, double e);
  void      feoarrm1n2_pow_to(   feoarrm1n2_t* arr, double e, feoarrm1n2_t* res);
  
  
  # From ../../../include/oti/static/onumm1n2/array/gauss/base.h
  
  void      feoarrm1n2_get_order_im_to( ord_t order, feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_get_order_im(    ord_t order, feoarrm1n2_t* arr);
  feoarrm1n2_t feoarrm1n2_get_deriv(   imdir_t idx, ord_t order, feoarrm1n2_t* arr);
  void      feoarrm1n2_get_deriv_to(imdir_t idx, ord_t order, feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_get_im(      imdir_t idx, ord_t order, feoarrm1n2_t* arr);
  void      feoarrm1n2_get_im_to(   imdir_t idx, ord_t order, feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_truncate_im(   imdir_t idx, ord_t order, feoarrm1n2_t* arr);
  void      feoarrm1n2_truncate_im_to(imdir_t idx, ord_t order, feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_copy(   feoarrm1n2_t* src);
  void      feoarrm1n2_copy_to(feoarrm1n2_t* src, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_get_im(    imdir_t idx, ord_t order, feoarrm1n2_t* arr);
  void      feoarrm1n2_get_im_to( imdir_t idx, ord_t order, feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_get_deriv(    imdir_t idx, ord_t order, feoarrm1n2_t* arr);
  void      feoarrm1n2_get_deriv_to( imdir_t idx, ord_t order, feoarrm1n2_t* arr, feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_extract_im(    imdir_t idx, ord_t order, feoarrm1n2_t* arr);
  void      feoarrm1n2_extract_im_to( imdir_t idx, ord_t order, feoarrm1n2_t* arr,  feoarrm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_extract_deriv(    imdir_t idx, ord_t order, feoarrm1n2_t* arr);
  void      feoarrm1n2_extract_deriv_to( imdir_t idx, ord_t order, feoarrm1n2_t* arr, feoarrm1n2_t* res);
  oarrm1n2_t   feoarrm1n2_get_item_k(  feoarrm1n2_t* arr, uint64_t k);
  feonumm1n2_t  feoarrm1n2_get_item_ij( feoarrm1n2_t* arr, uint64_t i, uint64_t j);
  onumm1n2_t feoarrm1n2_get_item_ijk(feoarrm1n2_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm1n2_get_item_ij_to(  feoarrm1n2_t* arr, uint64_t i, uint64_t j,
                                 feonumm1n2_t* res);
  void feoarrm1n2_get_item_k_to(   feoarrm1n2_t* arr, uint64_t k,
                                  oarrm1n2_t* res);
  void feoarrm1n2_get_item_ijk_to( feoarrm1n2_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm1n2_t* res);
  feoarrm1n2_t feoarrm1n2_get_slice(feoarrm1n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm1n2_get_slice_to(feoarrm1n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n2_t* res);
  void feoarrm1n2_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm1n2_t* res);
  void feoarrm1n2_set_item_ij_o(  onumm1n2_t* elm, uint64_t i, uint64_t j,
                               feoarrm1n2_t* res);
  void feoarrm1n2_set_item_ij_f(  feonumm1n2_t* elm, uint64_t i, uint64_t j,
                              feoarrm1n2_t* res);
  void feoarrm1n2_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm1n2_t* res);
  void feoarrm1n2_set_item_k_o(  onumm1n2_t* elm, uint64_t k,
                              feoarrm1n2_t* res);
  void feoarrm1n2_set_item_k_R(    oarrm1n2_t* elm, uint64_t k,
                            feoarrm1n2_t* res);
  void feoarrm1n2_set_item_k_O(    oarrm1n2_t* elm, uint64_t k,
                            feoarrm1n2_t* res);
  void feoarrm1n2_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm1n2_t* res);
  void feoarrm1n2_set_item_ijk_o( onumm1n2_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm1n2_t* res);
  void feoarrm1n2_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n2_t* res);
  void feoarrm1n2_set_slice_o( onumm1n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n2_t* res);
  void feoarrm1n2_set_slice_f( feonumm1n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n2_t* res);
  void feoarrm1n2_set_slice_O( oarrm1n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n2_t* res);
  void feoarrm1n2_set_slice_F( feoarrm1n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n2_t* res);
  void feoarrm1n2_set_all_o( onumm1n2_t* num, feoarrm1n2_t* arr );
  void feoarrm1n2_set_all_r(   coeff_t  num, feoarrm1n2_t* arr );
  void feoarrm1n2_set_all_f(  feonumm1n2_t* num, feoarrm1n2_t* arr );
  void feoarrm1n2_set_r(    coeff_t src, feoarrm1n2_t* res );
  void feoarrm1n2_set_o( onumm1n2_t* src, feoarrm1n2_t* res );
  void feoarrm1n2_set_f(  feonumm1n2_t* src, feoarrm1n2_t* res );
  void feoarrm1n2_set_R(    darr_t* src, feoarrm1n2_t* res );
  void feoarrm1n2_set_O(   oarrm1n2_t* src, feoarrm1n2_t* res );
  void feoarrm1n2_set_F( feoarrm1n2_t* src, feoarrm1n2_t* res );
  feoarrm1n2_t feoarrm1n2_eye( uint64_t size,  uint64_t nip);
  feoarrm1n2_t feoarrm1n2_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm1n2_t feoarrm1n2_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm1n2_t feoarrm1n2_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm1n2_free(feoarrm1n2_t* arr);
  feoarrm1n2_t feoarrm1n2_init();
  ord_t feoarrm1n2_get_order(feoarrm1n2_t* arr);
  
  
  # From ../../../include/oti/static/onumm1n2/scalar/utils.h
  
  void onumm1n2_get_active_bases(onumm1n2_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm1n2/scalar/algebra.h
  
  onumm1n2_t onumm1n2_abs(onumm1n2_t* num);
  onumm1n2_t onumm1n2_div_ro(coeff_t num, onumm1n2_t* den);
  onumm1n2_t onumm1n2_div_oo(onumm1n2_t* num, onumm1n2_t* den);
  onumm1n2_t onumm1n2_div_or(onumm1n2_t* num, coeff_t val);
  void onumm1n2_div_ro_to(coeff_t num, onumm1n2_t* den, onumm1n2_t* res);
  void onumm1n2_div_oo_to(onumm1n2_t* num, onumm1n2_t* den, onumm1n2_t* res);
  void onumm1n2_div_or_to(onumm1n2_t* num, coeff_t val, onumm1n2_t* res);
  void onumm1n2_abs_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_neg(  onumm1n2_t* lhs);
  void onumm1n2_neg_to(  onumm1n2_t* lhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_sum_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
  void onumm1n2_sum_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_sum_ro(  coeff_t lhs,  onumm1n2_t* rhs);
  void onumm1n2_sum_ro_to(  coeff_t lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_sub_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
  void onumm1n2_sub_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_sub_ro(  coeff_t lhs,  onumm1n2_t* rhs);
  void onumm1n2_sub_ro_to(  coeff_t lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_sub_or(  onumm1n2_t* lhs,  coeff_t rhs);
  void onumm1n2_sub_or_to(  onumm1n2_t* lhs,  coeff_t rhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_mul_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
  void onumm1n2_mul_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_mul_ro(  coeff_t lhs,  onumm1n2_t* rhs);
  void onumm1n2_mul_ro_to(  coeff_t lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_trunc_mul_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
  void onumm1n2_trunc_mul_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_gem_oo(  onumm1n2_t* a,  onumm1n2_t* b,  onumm1n2_t* c);
  void onumm1n2_gem_oo_to(  onumm1n2_t* a,  onumm1n2_t* b,  onumm1n2_t* c, onumm1n2_t* res);
  onumm1n2_t onumm1n2_gem_ro(  coeff_t a,  onumm1n2_t* b,  onumm1n2_t* c);
  void onumm1n2_gem_ro_to(  coeff_t a,  onumm1n2_t* b,  onumm1n2_t* c, onumm1n2_t* res);
  onumm1n2_t onumm1n2_feval(coeff_t* feval_re, onumm1n2_t* x);
  void onumm1n2_feval_to(coeff_t* feval_re, onumm1n2_t* x, onumm1n2_t* res);
  
  
  # From ../../../include/oti/static/onumm1n2/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm1n2/scalar/functions.h
  
  onumm1n2_t onumm1n2_atanh(onumm1n2_t* num);
  void onumm1n2_atanh_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_asinh(onumm1n2_t* num);
  void onumm1n2_asinh_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_acosh(onumm1n2_t* num);
  void onumm1n2_acosh_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_tanh(onumm1n2_t* num);
  void onumm1n2_tanh_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_sqrt(onumm1n2_t* num);
  void onumm1n2_sqrt_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_cbrt(onumm1n2_t* num);
  void onumm1n2_cbrt_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_cosh(onumm1n2_t* num);
  void onumm1n2_cosh_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_sinh(onumm1n2_t* num);
  void onumm1n2_sinh_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_asin(onumm1n2_t* num);
  void onumm1n2_asin_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_acos(onumm1n2_t* num);
  void onumm1n2_acos_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_atan(onumm1n2_t* num);
  void onumm1n2_atan_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_tan(onumm1n2_t* num);
  void onumm1n2_tan_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_cos(onumm1n2_t* num);
  void onumm1n2_cos_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_sin(onumm1n2_t* num );
  void onumm1n2_sin_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_logb(onumm1n2_t* num, double base);
  void onumm1n2_logb_to(onumm1n2_t* num, double base, onumm1n2_t* res);
  onumm1n2_t onumm1n2_log10(onumm1n2_t* num);
  void onumm1n2_log10_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_log(onumm1n2_t* num);
  void onumm1n2_log_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_exp(onumm1n2_t* num);
  void onumm1n2_exp_to(onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_pow(onumm1n2_t* num, double e);
  void onumm1n2_pow_to(onumm1n2_t* num, coeff_t e, onumm1n2_t* res);
  
  
  # From ../../../include/oti/static/onumm1n2/scalar/base.h
  
  void onumm1n2_set_im_o(onumm1n2_t* num, imdir_t idx, ord_t order, onumm1n2_t* res);
  void onumm1n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm1n2_t* res);
  void onumm1n2_set_deriv_o(onumm1n2_t* num, imdir_t idx, ord_t order, onumm1n2_t* res);
  void onumm1n2_extract_im_to( imdir_t idx, ord_t order, onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_extract_im(imdir_t idx, ord_t order, onumm1n2_t* num);
  onumm1n2_t onumm1n2_extract_deriv(imdir_t idx, ord_t order, onumm1n2_t* num);
  void onumm1n2_extract_deriv_to(imdir_t idx, ord_t order, onumm1n2_t* num, onumm1n2_t* res);
  void onumm1n2_get_im_to_o(imdir_t idx, ord_t order, onumm1n2_t* num, onumm1n2_t* res);
  onumm1n2_t onumm1n2_get_im_o(imdir_t idx, ord_t order, onumm1n2_t* num);
  void onumm1n2_get_im_to_r(imdir_t idx, ord_t order, onumm1n2_t* num, coeff_t* res);
  ord_t onumm1n2_get_order(onumm1n2_t* lhs);
  onumm1n2_t onumm1n2_get_deriv_o( imdir_t idx, ord_t order, onumm1n2_t* num);
  void onumm1n2_get_deriv_to( imdir_t idx, ord_t order, onumm1n2_t* num, onumm1n2_t* res);
  void onumm1n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm1n2_t* res);
  onumm1n2_t onumm1n2_init();
  ndir_t onumm1n2_get_ndir_order(ord_t order, onumm1n2_t* num);
  ndir_t onumm1n2_get_ndir_total(onumm1n2_t* num);
  onumm1n2_t onumm1n2_create_r(  coeff_t lhs);
  void onumm1n2_set_r(  coeff_t lhs, onumm1n2_t* res);
  void onumm1n2_set_o(  onumm1n2_t* lhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_get_order_im(ord_t order, onumm1n2_t* lhs);
  void onumm1n2_get_order_im_to(ord_t order, onumm1n2_t* lhs, onumm1n2_t* res);
  coeff_t onumm1n2_get_item(imdir_t idx, ord_t order, onumm1n2_t* lhs);
  coeff_t onumm1n2_get_deriv(imdir_t idx, ord_t order, onumm1n2_t* lhs);
  void onumm1n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm1n2_t* x);
  onumm1n2_t onumm1n2_copy(  onumm1n2_t* lhs);
  void onumm1n2_copy_to(  onumm1n2_t* lhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_taylor_integrate(coeff_t* deltas,onumm1n2_t* lhs);
  void onumm1n2_taylor_integrate_to(coeff_t* deltas,onumm1n2_t* lhs, onumm1n2_t* res);
  onumm1n2_t onumm1n2_truncate_im(imdir_t idx, ord_t order, onumm1n2_t* lhs);
  void onumm1n2_truncate_im_to(imdir_t idx, ord_t order, onumm1n2_t* lhs, onumm1n2_t* res);
  void onumm1n2_print(  onumm1n2_t* lhs);
  imdir_t onumm1n2_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm1n2/scalar/gauss/utils.h
  
  void feonumm1n2_dimCheck(feonumm1n2_t* arr1,feonumm1n2_t* arr2);
  void feonumm1n2_get_active_bases(feonumm1n2_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n2/scalar/gauss/algebra.h
  
  feonumm1n2_t feonumm1n2_neg(   feonumm1n2_t* num);
  void     feonumm1n2_neg_to(feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_sum_ff(   feonumm1n2_t* lhs, feonumm1n2_t* rhs);
  void     feonumm1n2_sum_ff_to(feonumm1n2_t* lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_sum_of(   onumm1n2_t* lhs, feonumm1n2_t* rhs);
  void     feonumm1n2_sum_of_to(onumm1n2_t* lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_sum_rf(   coeff_t lhs, feonumm1n2_t* rhs);
  void     feonumm1n2_sum_rf_to(coeff_t lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_sub_ff(     feonumm1n2_t* lhs,  feonumm1n2_t* rhs);
  void     feonumm1n2_sub_ff_to(  feonumm1n2_t* lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_sub_of(    onumm1n2_t* lhs,  feonumm1n2_t* rhs);
  void     feonumm1n2_sub_of_to( onumm1n2_t* lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_sub_fo(     feonumm1n2_t* lhs, onumm1n2_t* rhs);
  void     feonumm1n2_sub_fo_to(  feonumm1n2_t* lhs, onumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_sub_rf(       coeff_t lhs,  feonumm1n2_t* rhs);
  void     feonumm1n2_sub_rf_to(    coeff_t lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_sub_fr(     feonumm1n2_t* lhs,    coeff_t rhs);
  void     feonumm1n2_sub_fr_to(  feonumm1n2_t* lhs,    coeff_t rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_mul_ff(   feonumm1n2_t* lhs, feonumm1n2_t* rhs);
  void     feonumm1n2_mul_ff_to(feonumm1n2_t* lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_mul_of(   onumm1n2_t* lhs, feonumm1n2_t* rhs);
  void     feonumm1n2_mul_of_to(onumm1n2_t* lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_mul_rf(   coeff_t lhs, feonumm1n2_t* rhs);
  void     feonumm1n2_mul_rf_to(coeff_t lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_div_ff(     feonumm1n2_t* lhs,  feonumm1n2_t* rhs);
  void     feonumm1n2_div_ff_to(  feonumm1n2_t* lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_div_of(    onumm1n2_t* lhs,  feonumm1n2_t* rhs);
  void     feonumm1n2_div_of_to( onumm1n2_t* lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_div_fo(     feonumm1n2_t* lhs, onumm1n2_t* rhs);
  void     feonumm1n2_div_fo_to(  feonumm1n2_t* lhs, onumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_div_rf(       coeff_t lhs,  feonumm1n2_t* rhs);
  void     feonumm1n2_div_rf_to(    coeff_t lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_div_fr(     feonumm1n2_t* lhs,    coeff_t rhs);
  void     feonumm1n2_div_fr_to(  feonumm1n2_t* lhs,    coeff_t rhs, feonumm1n2_t* res);
  
  
  # From ../../../include/oti/static/onumm1n2/scalar/gauss/functions.h
  
  feonumm1n2_t feonumm1n2_atanh(    feonumm1n2_t* num);
  void     feonumm1n2_atanh_to( feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_asinh(    feonumm1n2_t* num);
  void     feonumm1n2_asinh_to( feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_acosh(    feonumm1n2_t* num);
  void     feonumm1n2_acosh_to( feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_tanh(     feonumm1n2_t* num);
  void     feonumm1n2_tanh_to(  feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_cosh(     feonumm1n2_t* num);
  void     feonumm1n2_cosh_to(  feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_sinh(     feonumm1n2_t* num);
  void     feonumm1n2_sinh_to(  feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_asin(     feonumm1n2_t* num);
  void     feonumm1n2_asin_to(  feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_acos(     feonumm1n2_t* num);
  void     feonumm1n2_acos_to(  feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_atan(     feonumm1n2_t* num);
  void     feonumm1n2_atan_to(  feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_tan(      feonumm1n2_t* num);
  void     feonumm1n2_tan_to(   feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_cos(      feonumm1n2_t* num);
  void     feonumm1n2_cos_to(   feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_sin(      feonumm1n2_t* num);
  void     feonumm1n2_sin_to(   feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_logb(     feonumm1n2_t* num, double base);
  void     feonumm1n2_logb_to(  feonumm1n2_t* num, double base, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_log10(    feonumm1n2_t* num);
  void     feonumm1n2_log10_to( feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_log(      feonumm1n2_t* num);
  void     feonumm1n2_log_to(   feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_exp(      feonumm1n2_t* num);
  void     feonumm1n2_exp_to(   feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_cbrt(     feonumm1n2_t* num);
  void     feonumm1n2_cbrt_to(  feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_sqrt(     feonumm1n2_t* num);
  void     feonumm1n2_sqrt_to(  feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_pow(      feonumm1n2_t* num, double e);
  void     feonumm1n2_pow_to(   feonumm1n2_t* num, double e, feonumm1n2_t* res);
  onumm1n2_t feonumm1n2_integrate(       feonumm1n2_t* num, feonumm1n2_t* w);
  void      feonumm1n2_integrate_to(    feonumm1n2_t* num, feonumm1n2_t* w, onumm1n2_t* res);
  onumm1n2_t feonumm1n2_integrate_f(     feonumm1n2_t* num, feonumm1n2_t* w);
  void      feonumm1n2_integrate_f_to(  feonumm1n2_t* num, feonumm1n2_t* w, onumm1n2_t* res);
  onumm1n2_t feonumm1n2_integrate_r(       coeff_t num, feonumm1n2_t* w);
  void      feonumm1n2_integrate_r_to(    coeff_t num, feonumm1n2_t* w, onumm1n2_t* res);
  onumm1n2_t feonumm1n2_integrate_o(    onumm1n2_t* num, feonumm1n2_t* w);
  void      feonumm1n2_integrate_o_to( onumm1n2_t* num, feonumm1n2_t* w, onumm1n2_t* res);
  
  
  # From ../../../include/oti/static/onumm1n2/scalar/gauss/base.h
  
  void     feonumm1n2_get_order_im_to( ord_t order, feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_get_order_im(    ord_t order, feonumm1n2_t* num);
  feonumm1n2_t feonumm1n2_get_im(    imdir_t idx, ord_t order, feonumm1n2_t* num);
  void     feonumm1n2_get_im_to( imdir_t idx, ord_t order, feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_get_deriv(    imdir_t idx, ord_t order, feonumm1n2_t* num);
  void     feonumm1n2_get_deriv_to( imdir_t idx, ord_t order, feonumm1n2_t* num, feonumm1n2_t* res);
  void feonumm1n2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm1n2_t* num);
  void feonumm1n2_set_im_o( onumm1n2_t* val, imdir_t idx, ord_t order, feonumm1n2_t* num);
  void feonumm1n2_set_im_f(  feonumm1n2_t* val, imdir_t idx, ord_t order, feonumm1n2_t* num);
  void feonumm1n2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm1n2_t* num);
  void feonumm1n2_set_deriv_o( onumm1n2_t* val, imdir_t idx, ord_t order, feonumm1n2_t* num);
  void feonumm1n2_set_deriv_f(  feonumm1n2_t* val, imdir_t idx, ord_t order, feonumm1n2_t* num);
  feonumm1n2_t feonumm1n2_extract_im(    imdir_t idx, ord_t order, feonumm1n2_t* num);
  void     feonumm1n2_extract_im_to( imdir_t idx, ord_t order, feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_extract_deriv(    imdir_t idx, ord_t order, feonumm1n2_t* num);
  void     feonumm1n2_extract_deriv_to( imdir_t idx, ord_t order, feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_truncate_im(    imdir_t idx, ord_t order, feonumm1n2_t* num);
  void     feonumm1n2_truncate_im_to( imdir_t idx, ord_t order, feonumm1n2_t* num, feonumm1n2_t* res);
  feonumm1n2_t feonumm1n2_copy(    feonumm1n2_t* src);
  void     feonumm1n2_copy_to( feonumm1n2_t* src, feonumm1n2_t* dst);
  void feonumm1n2_set_r(    coeff_t num, feonumm1n2_t* res);
  void feonumm1n2_set_o( onumm1n2_t* num, feonumm1n2_t* res);
  void feonumm1n2_set_f(  feonumm1n2_t* num, feonumm1n2_t* res);
  void feonumm1n2_set_item_k_r(   coeff_t  num, uint64_t k, feonumm1n2_t* res);
  void feonumm1n2_set_item_k_o( onumm1n2_t* num, uint64_t k, feonumm1n2_t* res);
  onumm1n2_t feonumm1n2_get_item_k(   feonumm1n2_t* num, uint64_t k);
  void      feonumm1n2_get_item_k_to(feonumm1n2_t* num, uint64_t k, onumm1n2_t* res);
  feonumm1n2_t feonumm1n2_zeros(uint64_t nIntPts);
  feonumm1n2_t feonumm1n2_createEmpty(uint64_t nIntPts);
  feonumm1n2_t feonumm1n2_empty_like(feonumm1n2_t* arr);
  void feonumm1n2_free(feonumm1n2_t* num);
  ord_t feonumm1n2_get_order( feonumm1n2_t* num );
  feonumm1n2_t feonumm1n2_init();
  
  