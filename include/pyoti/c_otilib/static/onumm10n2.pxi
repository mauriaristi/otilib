cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm10n2/scalar/structures.h
  
  ctypedef struct  onumm10n2_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
    coeff_t e6;
    coeff_t e7;
    coeff_t e8;
    coeff_t e9;
    coeff_t eA;
    coeff_t e11;
    coeff_t e12;
    coeff_t e22;
    coeff_t e13;
    coeff_t e23;
    coeff_t e33;
    coeff_t e14;
    coeff_t e24;
    coeff_t e34;
    coeff_t e44;
    coeff_t e15;
    coeff_t e25;
    coeff_t e35;
    coeff_t e45;
    coeff_t e55;
    coeff_t e16;
    coeff_t e26;
    coeff_t e36;
    coeff_t e46;
    coeff_t e56;
    coeff_t e66;
    coeff_t e17;
    coeff_t e27;
    coeff_t e37;
    coeff_t e47;
    coeff_t e57;
    coeff_t e67;
    coeff_t e77;
    coeff_t e18;
    coeff_t e28;
    coeff_t e38;
    coeff_t e48;
    coeff_t e58;
    coeff_t e68;
    coeff_t e78;
    coeff_t e88;
    coeff_t e19;
    coeff_t e29;
    coeff_t e39;
    coeff_t e49;
    coeff_t e59;
    coeff_t e69;
    coeff_t e79;
    coeff_t e89;
    coeff_t e99;
    coeff_t e1A;
    coeff_t e2A;
    coeff_t e3A;
    coeff_t e4A;
    coeff_t e5A;
    coeff_t e6A;
    coeff_t e7A;
    coeff_t e8A;
    coeff_t e9A;
    coeff_t eAA;
  # } onumm10n2_t;
  
  
  # From ../../../include/oti/static/onumm10n2/array/structures.h
  
  ctypedef struct  oarrm10n2_t : # {
      onumm10n2_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
      flag_t          flag;
  # } oarrm10n2_t;
  
  
  # From ../../../include/oti/static/onumm10n2/scalar/gauss/structures.h
  
  ctypedef struct  feonumm10n2_t: # {
      onumm10n2_t*  p_data;
      uint64_t    nip;
  # } feonumm10n2_t;
  
  
  # From ../../../include/oti/static/onumm10n2/array/gauss/structures.h
  
  ctypedef struct  feoarrm10n2_t: # {
      oarrm10n2_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm10n2_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm10n2/array/utils.h
  
  void oarrm10n2_dimCheck_OO_elementwise(oarrm10n2_t* arr1, oarrm10n2_t* arr2, oarrm10n2_t* res);
  void oarrm10n2_dimCheck_RO_elementwise(darr_t*  arr1, oarrm10n2_t* arr2, oarrm10n2_t* res);
  void oarrm10n2_dimCheck_OO_matmul(oarrm10n2_t* arr1, oarrm10n2_t* arr2, oarrm10n2_t* res);
  void oarrm10n2_dimCheck_RO_matmul(darr_t*  arr1, oarrm10n2_t* arr2, oarrm10n2_t* res);
  void oarrm10n2_dimCheck_OR_matmul(oarrm10n2_t* arr1, darr_t*  arr2, oarrm10n2_t* res);
  void oarrm10n2_dimCheck_O_squareness(oarrm10n2_t* arr1, oarrm10n2_t* res);
  void oarrm10n2_dimCheck_OO_samesize(oarrm10n2_t* arr1, oarrm10n2_t* res);
  void oarrm10n2_dimCheck_RO_samesize(darr_t* arr1, oarrm10n2_t* res);
  ord_t oarrm10n2_get_order(oarrm10n2_t* arr);
  void oarrm10n2_get_active_bases(oarrm10n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm10n2/array/algebra_elementwise.h
  
  oarrm10n2_t oarrm10n2_neg(oarrm10n2_t* arr);
  void oarrm10n2_neg_to(oarrm10n2_t* rhs, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_sum_OO(oarrm10n2_t*   lhs, oarrm10n2_t* rhs);
  oarrm10n2_t oarrm10n2_sum_RO(darr_t*    lhs, oarrm10n2_t* rhs);
  oarrm10n2_t oarrm10n2_sum_oO(onumm10n2_t* lhs, oarrm10n2_t* rhs);
  oarrm10n2_t oarrm10n2_sum_rO(coeff_t    lhs, oarrm10n2_t* rhs);
  void oarrm10n2_sum_OO_to(oarrm10n2_t*   lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
  void oarrm10n2_sum_RO_to(darr_t*    lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
  void oarrm10n2_sum_oO_to(onumm10n2_t* lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
  void oarrm10n2_sum_rO_to(coeff_t    lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_sub_OO(oarrm10n2_t*   lhs, oarrm10n2_t*   rhs);
  oarrm10n2_t oarrm10n2_sub_RO(darr_t*    lhs, oarrm10n2_t*   rhs);
  oarrm10n2_t oarrm10n2_sub_OR(oarrm10n2_t*   lhs, darr_t*    rhs);
  oarrm10n2_t oarrm10n2_sub_oO(onumm10n2_t* lhs, oarrm10n2_t*   rhs);
  oarrm10n2_t oarrm10n2_sub_Oo(oarrm10n2_t*   lhs, onumm10n2_t* rhs);
  oarrm10n2_t oarrm10n2_sub_rO(coeff_t    lhs, oarrm10n2_t*   rhs);
  oarrm10n2_t oarrm10n2_sub_Or(oarrm10n2_t*   lhs, coeff_t    rhs);
  void oarrm10n2_sub_OO_to( oarrm10n2_t*   lhs, oarrm10n2_t*   rhs, oarrm10n2_t* res);
  void oarrm10n2_sub_RO_to( darr_t*    lhs, oarrm10n2_t*   rhs, oarrm10n2_t* res);
  void oarrm10n2_sub_OR_to( oarrm10n2_t*   lhs, darr_t*    rhs, oarrm10n2_t* res);
  void oarrm10n2_sub_oO_to( onumm10n2_t* lhs, oarrm10n2_t*   rhs, oarrm10n2_t* res);
  void oarrm10n2_sub_Oo_to( oarrm10n2_t*   lhs, onumm10n2_t* rhs, oarrm10n2_t* res);
  void oarrm10n2_sub_rO_to( coeff_t    lhs, oarrm10n2_t*   rhs, oarrm10n2_t* res);
  void oarrm10n2_sub_Or_to( oarrm10n2_t*   lhs, coeff_t    rhs, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_mul_OO(oarrm10n2_t*   lhs, oarrm10n2_t* rhs);
  oarrm10n2_t oarrm10n2_mul_RO(darr_t*    lhs, oarrm10n2_t* rhs);
  oarrm10n2_t oarrm10n2_mul_oO(onumm10n2_t* lhs, oarrm10n2_t* rhs);
  oarrm10n2_t oarrm10n2_mul_rO(coeff_t    lhs, oarrm10n2_t* rhs);
  void oarrm10n2_mul_OO_to(oarrm10n2_t*   lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
  void oarrm10n2_mul_RO_to(darr_t*    lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
  void oarrm10n2_mul_oO_to(onumm10n2_t* lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
  void oarrm10n2_mul_rO_to(coeff_t    lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
  void oarrm10n2_gem_OO_to(  oarrm10n2_t* arr1, oarrm10n2_t* arr2, oarrm10n2_t* arr3, oarrm10n2_t* res);
  void oarrm10n2_gem_oO_to(onumm10n2_t* arr1, oarrm10n2_t* arr2, oarrm10n2_t* arr3, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_div_OO(oarrm10n2_t*   lhs, oarrm10n2_t*   rhs);
  oarrm10n2_t oarrm10n2_div_OR(oarrm10n2_t*   lhs, darr_t*    rhs);
  oarrm10n2_t oarrm10n2_div_RO(darr_t*    lhs, oarrm10n2_t*   rhs);
  oarrm10n2_t oarrm10n2_div_oO(onumm10n2_t* lhs, oarrm10n2_t*   rhs);
  oarrm10n2_t oarrm10n2_div_Oo(oarrm10n2_t*   lhs, onumm10n2_t* rhs);
  oarrm10n2_t oarrm10n2_div_rO(coeff_t    lhs, oarrm10n2_t*   rhs);
  oarrm10n2_t oarrm10n2_div_Or(oarrm10n2_t*   lhs, coeff_t    rhs);
  void oarrm10n2_div_OO_to(oarrm10n2_t*   lhs, oarrm10n2_t*   rhs, oarrm10n2_t* res);
  void oarrm10n2_div_RO_to(darr_t*    lhs, oarrm10n2_t*   rhs, oarrm10n2_t* res);
  void oarrm10n2_div_OR_to(oarrm10n2_t*   lhs, darr_t*    rhs, oarrm10n2_t* res);
  void oarrm10n2_div_oO_to(onumm10n2_t* lhs, oarrm10n2_t*   rhs, oarrm10n2_t* res);
  void oarrm10n2_div_Oo_to(oarrm10n2_t*   lhs, onumm10n2_t* rhs, oarrm10n2_t* res);
  void oarrm10n2_div_rO_to(coeff_t    lhs, oarrm10n2_t*   rhs, oarrm10n2_t* res);
  void oarrm10n2_div_Or_to(oarrm10n2_t*   lhs, coeff_t    rhs, oarrm10n2_t* res);
  
  
  # From ../../../include/oti/static/onumm10n2/array/algebra_matops.h
  
  onumm10n2_t oarrm10n2_dotproduct_OO(    oarrm10n2_t* lhs, oarrm10n2_t* rhs);
  void      oarrm10n2_dotproduct_OO_to( oarrm10n2_t* lhs, oarrm10n2_t* rhs, onumm10n2_t* res);
  onumm10n2_t oarrm10n2_dotproduct_RO(     darr_t* lhs, oarrm10n2_t* rhs);
  void      oarrm10n2_dotproduct_RO_to(  darr_t* lhs, oarrm10n2_t* rhs, onumm10n2_t* res);
  oarrm10n2_t oarrm10n2_matmul_OO(    oarrm10n2_t* lhs, oarrm10n2_t* rhs);
  oarrm10n2_t oarrm10n2_matmul_OR(    oarrm10n2_t* lhs,  darr_t* rhs);
  oarrm10n2_t oarrm10n2_matmul_RO(     darr_t* lhs, oarrm10n2_t* rhs);
  void    oarrm10n2_matmul_OO_to( oarrm10n2_t* lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
  void    oarrm10n2_matmul_OR_to( oarrm10n2_t* lhs,  darr_t* rhs, oarrm10n2_t* res);
  void    oarrm10n2_matmul_RO_to(  darr_t* lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_transpose(    oarrm10n2_t* arr1);
  void    oarrm10n2_transpose_to( oarrm10n2_t* arr1, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_invert(    oarrm10n2_t* arr1);
  void    oarrm10n2_invert_to( oarrm10n2_t* arr1, oarrm10n2_t* res);
  onumm10n2_t oarrm10n2_det(    oarrm10n2_t* arr1);
  void      oarrm10n2_det_to( oarrm10n2_t* arr1, onumm10n2_t* res);
  onumm10n2_t oarrm10n2_norm(    oarrm10n2_t* arr1);
  void      oarrm10n2_norm_to( oarrm10n2_t* arr1,  onumm10n2_t* res);
  onumm10n2_t oarrm10n2_pnorm(    oarrm10n2_t* arr1, coeff_t p);
  void      oarrm10n2_pnorm_to( oarrm10n2_t* arr1, coeff_t p, onumm10n2_t* res);
  
  
  # From ../../../include/oti/static/onumm10n2/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm10n2/array/functions.h
  
  oarrm10n2_t oarrm10n2_atanh(   oarrm10n2_t* arr);
  void    oarrm10n2_atanh_to(oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_asinh(   oarrm10n2_t* arr);
  void    oarrm10n2_asinh_to(oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_acosh(   oarrm10n2_t* arr);
  void    oarrm10n2_acosh_to(oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_tanh(    oarrm10n2_t* arr);
  void    oarrm10n2_tanh_to( oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_cbrt(    oarrm10n2_t* arr);
  void    oarrm10n2_cbrt_to( oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_sqrt(    oarrm10n2_t* arr);
  void    oarrm10n2_sqrt_to( oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_cosh(    oarrm10n2_t* arr);
  void    oarrm10n2_cosh_to( oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_sinh(    oarrm10n2_t* arr);
  void    oarrm10n2_sinh_to( oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_asin(    oarrm10n2_t* arr);
  void    oarrm10n2_asin_to( oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_acos(    oarrm10n2_t* arr);
  void    oarrm10n2_acos_to( oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_atan(    oarrm10n2_t* arr);
  void    oarrm10n2_atan_to( oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_tan(     oarrm10n2_t* arr);
  void    oarrm10n2_tan_to(  oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_cos(     oarrm10n2_t* arr);
  void    oarrm10n2_cos_to(  oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_sin(     oarrm10n2_t* arr);
  void    oarrm10n2_sin_to(  oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_logb(    oarrm10n2_t* arr, double base);
  void    oarrm10n2_logb_to( oarrm10n2_t* arr, double base, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_log10(   oarrm10n2_t* arr);
  void    oarrm10n2_log10_to(oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_log(     oarrm10n2_t* arr);
  void    oarrm10n2_log_to(  oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_exp(     oarrm10n2_t* arr);
  void    oarrm10n2_exp_to(  oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_pow(     oarrm10n2_t* arr, double e);
  void    oarrm10n2_pow_to(  oarrm10n2_t* arr, double e, oarrm10n2_t* res);
  
  
  # From ../../../include/oti/static/onumm10n2/array/base.h
  
  void    oarrm10n2_taylor_integrate_to( coeff_t* deltas, oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_taylor_integrate(    coeff_t* deltas, oarrm10n2_t* arr);
  void    oarrm10n2_get_order_im_to( ord_t order, oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_get_order_im(    ord_t order, oarrm10n2_t* arr);
  void oarrm10n2_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm10n2_t* res);
  void oarrm10n2_set_slice_O( oarrm10n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm10n2_t* res);
  void oarrm10n2_set_slice_o( onumm10n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_get_slice( oarrm10n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm10n2_get_slice_to( oarrm10n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_truncate_im(    imdir_t idx, ord_t order, oarrm10n2_t* arr);
  void    oarrm10n2_truncate_im_to( imdir_t idx, ord_t order, oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_extract_im(   imdir_t idx, ord_t order, oarrm10n2_t* arr);
  void    oarrm10n2_extract_im_to(imdir_t idx, ord_t order, oarrm10n2_t* arr, oarrm10n2_t* res);
  darr_t  oarrm10n2_get_deriv(    imdir_t idx, ord_t order, oarrm10n2_t* arr);
  void    oarrm10n2_get_deriv_to( imdir_t idx, ord_t order, oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_get_deriv_o(  imdir_t idx, ord_t order, oarrm10n2_t* arr);
  oarrm10n2_t oarrm10n2_extract_deriv(    imdir_t idx, ord_t order, oarrm10n2_t* arr);
  void    oarrm10n2_extract_deriv_to( imdir_t idx, ord_t order, oarrm10n2_t* arr, oarrm10n2_t* res);
  darr_t  oarrm10n2_get_im(   imdir_t idx, ord_t order, oarrm10n2_t* arr);
  oarrm10n2_t oarrm10n2_get_im_o( imdir_t idx, ord_t order, oarrm10n2_t* arr);
  void    oarrm10n2_get_im_to(imdir_t idx, ord_t order, oarrm10n2_t* arr, oarrm10n2_t* res);
  void    oarrm10n2_copy_to(oarrm10n2_t* arr, oarrm10n2_t* res);
  oarrm10n2_t oarrm10n2_copy(oarrm10n2_t* arr);
  void oarrm10n2_set_all_r( coeff_t num, oarrm10n2_t* arr);
  void oarrm10n2_set_item_i_r( coeff_t num, uint64_t i, oarrm10n2_t* arr);
  void oarrm10n2_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm10n2_t* arr);
  void oarrm10n2_set_r(   coeff_t  num,   oarrm10n2_t* arr);
  void oarrm10n2_set_o( onumm10n2_t* num,   oarrm10n2_t* arr);
  void oarrm10n2_set_O(   oarrm10n2_t* arrin, oarrm10n2_t* arr);
  void oarrm10n2_set_all_o( onumm10n2_t* src, oarrm10n2_t* arr);
  void oarrm10n2_set_item_i_o( onumm10n2_t* num, uint64_t i, oarrm10n2_t* arr);
  void oarrm10n2_set_item_ij_o( onumm10n2_t* num, uint64_t i, uint64_t j, oarrm10n2_t* arr);
  onumm10n2_t oarrm10n2_get_item_i(    oarrm10n2_t* arr, uint64_t i);
  void      oarrm10n2_get_item_i_to( oarrm10n2_t* arr, uint64_t i,             onumm10n2_t* res);
  onumm10n2_t oarrm10n2_get_item_ij(   oarrm10n2_t* arr, uint64_t i, uint64_t j);
  void      oarrm10n2_get_item_ij_to(oarrm10n2_t* arr, uint64_t i, uint64_t j, onumm10n2_t* res);
  oarrm10n2_t oarrm10n2_init();
  void oarrm10n2_free(oarrm10n2_t* arr);
  oarrm10n2_t oarrm10n2_empty_like(oarrm10n2_t* arr);
  oarrm10n2_t oarrm10n2_eye(uint64_t nrows);
  oarrm10n2_t oarrm10n2_ones(uint64_t nrows, uint64_t ncols);
  oarrm10n2_t oarrm10n2_zeros(uint64_t nrows, uint64_t ncols);
  oarrm10n2_t oarrm10n2_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm10n2/array/gauss/utils.h
  
  void feoarrm10n2_dimCheck_FF_samesize(feoarrm10n2_t* arr1, feoarrm10n2_t* arr2, feonumm10n2_t* res);
  void feoarrm10n2_dimCheck_OF_samesize(  oarrm10n2_t* arr1, feoarrm10n2_t* arr2, feonumm10n2_t* res);
  void feoarrm10n2_dimCheck_RF_samesize(   darr_t* arr1, feoarrm10n2_t* arr2, feonumm10n2_t* res);
  void feoarrm10n2_dimCheck_FF_elementwise(feoarrm10n2_t* arr1, feoarrm10n2_t* arr2, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_OF_elementwise(  oarrm10n2_t* arr1, feoarrm10n2_t* arr2, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm10n2_t* arr2, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_fF_elementwise( feonumm10n2_t* num1, feoarrm10n2_t* arr2, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_Ff_elementwise(feoarrm10n2_t* arr1,  feonumm10n2_t* num2, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_FF_matmul( feoarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_OF_matmul(   oarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_FO_matmul( feoarrm10n2_t* lhs,   oarrm10n2_t* rhs, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_FR_matmul( feoarrm10n2_t* lhs,    darr_t* rhs, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_F_squareness( feoarrm10n2_t* arr1, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_F_transpose( feoarrm10n2_t* arr1, feoarrm10n2_t* res);
  void feoarrm10n2_dimCheck_FfO_integrate(feoarrm10n2_t* arr, feonumm10n2_t* num,oarrm10n2_t* res);
  void feoarrm10n2_get_active_bases(feoarrm10n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm10n2/array/gauss/algebra.h
  
  feoarrm10n2_t feoarrm10n2_neg(    feoarrm10n2_t* arr);
  void      feoarrm10n2_neg_to( feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sum_FF(   feoarrm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sum_FF_to(feoarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sum_fF(    feonumm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sum_fF_to( feonumm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sum_OF(     oarrm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sum_OF_to(  oarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sum_RF(      darr_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sum_RF_to(   darr_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sum_oF(   onumm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sum_oF_to(onumm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sum_rF(     coeff_t  lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sum_rF_to(  coeff_t  lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sub_FF(    feoarrm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sub_FF_to( feoarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sub_fF(    feonumm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sub_fF_to( feonumm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sub_Ff(    feoarrm10n2_t* lhs, feonumm10n2_t* rhs);
  void      feoarrm10n2_sub_Ff_to( feoarrm10n2_t* lhs, feonumm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sub_OF(      oarrm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sub_OF_to(   oarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sub_FO(    feoarrm10n2_t* lhs,   oarrm10n2_t* rhs);
  void      feoarrm10n2_sub_FO_to( feoarrm10n2_t* lhs,   oarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sub_RF(       darr_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sub_RF_to(    darr_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sub_FR(    feoarrm10n2_t* lhs,    darr_t* rhs);
  void      feoarrm10n2_sub_FR_to( feoarrm10n2_t* lhs,    darr_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sub_oF(    onumm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sub_oF_to( onumm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sub_Fo(    feoarrm10n2_t* lhs, onumm10n2_t* rhs);
  void      feoarrm10n2_sub_Fo_to( feoarrm10n2_t* lhs, onumm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sub_rF(      coeff_t  lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_sub_rF_to(    coeff_t lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sub_Fr(    feoarrm10n2_t* lhs,   coeff_t  rhs);
  void      feoarrm10n2_sub_Fr_to( feoarrm10n2_t* lhs,   coeff_t  rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_mul_FF(   feoarrm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_mul_FF_to(feoarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_mul_fF(    feonumm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_mul_fF_to( feonumm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_mul_OF(     oarrm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_mul_OF_to(  oarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_mul_RF(      darr_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_mul_RF_to(   darr_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_mul_oF(   onumm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_mul_oF_to(onumm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_mul_rF(     coeff_t  lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_mul_rF_to(  coeff_t  lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_div_FF(    feoarrm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_div_FF_to( feoarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_div_fF(     feonumm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_div_fF_to(  feonumm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_div_Ff(    feoarrm10n2_t* lhs,  feonumm10n2_t* rhs);
  void      feoarrm10n2_div_Ff_to( feoarrm10n2_t* lhs,  feonumm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_div_OF(      oarrm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_div_OF_to(   oarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_div_FO(    feoarrm10n2_t* lhs,   oarrm10n2_t* rhs);
  void      feoarrm10n2_div_FO_to( feoarrm10n2_t* lhs,   oarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_div_RF(       darr_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_div_RF_to(    darr_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_div_FR(    feoarrm10n2_t* lhs,    darr_t* rhs);
  void      feoarrm10n2_div_FR_to( feoarrm10n2_t* lhs,    darr_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_div_oF(    onumm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_div_oF_to( onumm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_div_Fo(    feoarrm10n2_t* lhs, onumm10n2_t* rhs);
  void      feoarrm10n2_div_Fo_to( feoarrm10n2_t* lhs, onumm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_div_rF(      coeff_t  lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_div_rF_to(    coeff_t lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_div_Fr(    feoarrm10n2_t* lhs,   coeff_t  rhs);
  void      feoarrm10n2_div_Fr_to( feoarrm10n2_t* lhs,   coeff_t  rhs, feoarrm10n2_t* res);
  oarrm10n2_t feoarrm10n2_integrate(    feoarrm10n2_t* arr, feonumm10n2_t* w);
  void    feoarrm10n2_integrate_to( feoarrm10n2_t* arr, feonumm10n2_t* w, oarrm10n2_t* res);
  feonumm10n2_t feoarrm10n2_dotproduct_FF(    feoarrm10n2_t* lhs, feoarrm10n2_t* rhs);
  void     feoarrm10n2_dotproduct_FF_to( feoarrm10n2_t* lhs, feoarrm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feoarrm10n2_dotproduct_OF(      oarrm10n2_t* lhs, feoarrm10n2_t* rhs);
  void     feoarrm10n2_dotproduct_OF_to(   oarrm10n2_t* lhs, feoarrm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feoarrm10n2_dotproduct_RF(       darr_t* lhs, feoarrm10n2_t* rhs);
  void     feoarrm10n2_dotproduct_RF_to(    darr_t* lhs, feoarrm10n2_t* rhs, feonumm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_matmul_FF(    feoarrm10n2_t* lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_matmul_FF_to( feoarrm10n2_t* lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_matmul_OF(    oarrm10n2_t*   lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_matmul_OF_to( oarrm10n2_t*   lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_matmul_FO(    feoarrm10n2_t* lhs, oarrm10n2_t*   rhs);
  void      feoarrm10n2_matmul_FO_to( feoarrm10n2_t* lhs, oarrm10n2_t*   rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_matmul_RF(    darr_t*    lhs, feoarrm10n2_t* rhs);
  void      feoarrm10n2_matmul_RF_to( darr_t*    lhs, feoarrm10n2_t* rhs, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_matmul_FR(    feoarrm10n2_t* lhs, darr_t*    rhs);
  void      feoarrm10n2_matmul_FR_to( feoarrm10n2_t* lhs, darr_t*    rhs, feoarrm10n2_t* res);
  feonumm10n2_t feoarrm10n2_det(   feoarrm10n2_t* arr);
  void     feoarrm10n2_det_to(feoarrm10n2_t* arr, feonumm10n2_t* res);
  feonumm10n2_t feoarrm10n2_norm(     feoarrm10n2_t* arr);
  void     feoarrm10n2_norm_to(  feoarrm10n2_t* arr, feonumm10n2_t* res);
  feonumm10n2_t feoarrm10n2_pnorm(    feoarrm10n2_t* arr, coeff_t p);
  void     feoarrm10n2_pnorm_to( feoarrm10n2_t* arr, coeff_t p, feonumm10n2_t* res);
  feoarrm10n2_t   feoarrm10n2_invert(    feoarrm10n2_t* arr);
  void        feoarrm10n2_invert_to( feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t   feoarrm10n2_transpose(   feoarrm10n2_t* arr);
  void        feoarrm10n2_transpose_to(feoarrm10n2_t* arr, feoarrm10n2_t* res);
  
  
  # From ../../../include/oti/static/onumm10n2/array/gauss/functions.h
  
  feoarrm10n2_t feoarrm10n2_atanh(    feoarrm10n2_t* arr);
  void      feoarrm10n2_atanh_to( feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_asinh(    feoarrm10n2_t* arr);
  void      feoarrm10n2_asinh_to( feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_acosh(    feoarrm10n2_t* arr);
  void      feoarrm10n2_acosh_to( feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_tanh(     feoarrm10n2_t* arr);
  void      feoarrm10n2_tanh_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sinh(     feoarrm10n2_t* arr);
  void      feoarrm10n2_sinh_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_cosh(     feoarrm10n2_t* arr);
  void      feoarrm10n2_cosh_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_atan(     feoarrm10n2_t* arr);
  void      feoarrm10n2_atan_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_asin(     feoarrm10n2_t* arr);
  void      feoarrm10n2_asin_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_acos(     feoarrm10n2_t* arr);
  void      feoarrm10n2_acos_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_tan(      feoarrm10n2_t* arr);
  void      feoarrm10n2_tan_to(   feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sin(      feoarrm10n2_t* arr);
  void      feoarrm10n2_sin_to(   feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_cos(      feoarrm10n2_t* arr);
  void      feoarrm10n2_cos_to(   feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_logb(     feoarrm10n2_t* arr, double base);
  void      feoarrm10n2_logb_to(  feoarrm10n2_t* arr, double base, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_log10(    feoarrm10n2_t* arr);
  void      feoarrm10n2_log10_to( feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_log(      feoarrm10n2_t* arr);
  void      feoarrm10n2_log_to(   feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_exp(      feoarrm10n2_t* arr);
  void      feoarrm10n2_exp_to(   feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_cbrt(     feoarrm10n2_t* arr);
  void      feoarrm10n2_cbrt_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_sqrt(     feoarrm10n2_t* arr);
  void      feoarrm10n2_sqrt_to(  feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_pow(      feoarrm10n2_t* arr, double e);
  void      feoarrm10n2_pow_to(   feoarrm10n2_t* arr, double e, feoarrm10n2_t* res);
  
  
  # From ../../../include/oti/static/onumm10n2/array/gauss/base.h
  
  void      feoarrm10n2_get_order_im_to( ord_t order, feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_get_order_im(    ord_t order, feoarrm10n2_t* arr);
  feoarrm10n2_t feoarrm10n2_get_deriv(   imdir_t idx, ord_t order, feoarrm10n2_t* arr);
  void      feoarrm10n2_get_deriv_to(imdir_t idx, ord_t order, feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_get_im(      imdir_t idx, ord_t order, feoarrm10n2_t* arr);
  void      feoarrm10n2_get_im_to(   imdir_t idx, ord_t order, feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_truncate_im(   imdir_t idx, ord_t order, feoarrm10n2_t* arr);
  void      feoarrm10n2_truncate_im_to(imdir_t idx, ord_t order, feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_copy(   feoarrm10n2_t* src);
  void      feoarrm10n2_copy_to(feoarrm10n2_t* src, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_get_im(    imdir_t idx, ord_t order, feoarrm10n2_t* arr);
  void      feoarrm10n2_get_im_to( imdir_t idx, ord_t order, feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_get_deriv(    imdir_t idx, ord_t order, feoarrm10n2_t* arr);
  void      feoarrm10n2_get_deriv_to( imdir_t idx, ord_t order, feoarrm10n2_t* arr, feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_extract_im(    imdir_t idx, ord_t order, feoarrm10n2_t* arr);
  void      feoarrm10n2_extract_im_to( imdir_t idx, ord_t order, feoarrm10n2_t* arr,  feoarrm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_extract_deriv(    imdir_t idx, ord_t order, feoarrm10n2_t* arr);
  void      feoarrm10n2_extract_deriv_to( imdir_t idx, ord_t order, feoarrm10n2_t* arr, feoarrm10n2_t* res);
  oarrm10n2_t   feoarrm10n2_get_item_k(  feoarrm10n2_t* arr, uint64_t k);
  feonumm10n2_t  feoarrm10n2_get_item_ij( feoarrm10n2_t* arr, uint64_t i, uint64_t j);
  onumm10n2_t feoarrm10n2_get_item_ijk(feoarrm10n2_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm10n2_get_item_ij_to(  feoarrm10n2_t* arr, uint64_t i, uint64_t j,
                                 feonumm10n2_t* res);
  void feoarrm10n2_get_item_k_to(   feoarrm10n2_t* arr, uint64_t k,
                                  oarrm10n2_t* res);
  void feoarrm10n2_get_item_ijk_to( feoarrm10n2_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm10n2_t* res);
  feoarrm10n2_t feoarrm10n2_get_slice(feoarrm10n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm10n2_get_slice_to(feoarrm10n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n2_t* res);
  void feoarrm10n2_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm10n2_t* res);
  void feoarrm10n2_set_item_ij_o(  onumm10n2_t* elm, uint64_t i, uint64_t j,
                               feoarrm10n2_t* res);
  void feoarrm10n2_set_item_ij_f(  feonumm10n2_t* elm, uint64_t i, uint64_t j,
                              feoarrm10n2_t* res);
  void feoarrm10n2_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm10n2_t* res);
  void feoarrm10n2_set_item_k_o(  onumm10n2_t* elm, uint64_t k,
                              feoarrm10n2_t* res);
  void feoarrm10n2_set_item_k_R(    oarrm10n2_t* elm, uint64_t k,
                            feoarrm10n2_t* res);
  void feoarrm10n2_set_item_k_O(    oarrm10n2_t* elm, uint64_t k,
                            feoarrm10n2_t* res);
  void feoarrm10n2_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm10n2_t* res);
  void feoarrm10n2_set_item_ijk_o( onumm10n2_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm10n2_t* res);
  void feoarrm10n2_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n2_t* res);
  void feoarrm10n2_set_slice_o( onumm10n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n2_t* res);
  void feoarrm10n2_set_slice_f( feonumm10n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n2_t* res);
  void feoarrm10n2_set_slice_O( oarrm10n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n2_t* res);
  void feoarrm10n2_set_slice_F( feoarrm10n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n2_t* res);
  void feoarrm10n2_set_all_o( onumm10n2_t* num, feoarrm10n2_t* arr );
  void feoarrm10n2_set_all_r(   coeff_t  num, feoarrm10n2_t* arr );
  void feoarrm10n2_set_all_f(  feonumm10n2_t* num, feoarrm10n2_t* arr );
  void feoarrm10n2_set_r(    coeff_t src, feoarrm10n2_t* res );
  void feoarrm10n2_set_o( onumm10n2_t* src, feoarrm10n2_t* res );
  void feoarrm10n2_set_f(  feonumm10n2_t* src, feoarrm10n2_t* res );
  void feoarrm10n2_set_R(    darr_t* src, feoarrm10n2_t* res );
  void feoarrm10n2_set_O(   oarrm10n2_t* src, feoarrm10n2_t* res );
  void feoarrm10n2_set_F( feoarrm10n2_t* src, feoarrm10n2_t* res );
  feoarrm10n2_t feoarrm10n2_eye( uint64_t size,  uint64_t nip);
  feoarrm10n2_t feoarrm10n2_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm10n2_t feoarrm10n2_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm10n2_t feoarrm10n2_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm10n2_free(feoarrm10n2_t* arr);
  feoarrm10n2_t feoarrm10n2_init();
  ord_t feoarrm10n2_get_order(feoarrm10n2_t* arr);
  
  
  # From ../../../include/oti/static/onumm10n2/scalar/utils.h
  
  void onumm10n2_get_active_bases(onumm10n2_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm10n2/scalar/algebra.h
  
  onumm10n2_t onumm10n2_abs(onumm10n2_t* num);
  onumm10n2_t onumm10n2_div_ro(coeff_t num, onumm10n2_t* den);
  onumm10n2_t onumm10n2_div_oo(onumm10n2_t* num, onumm10n2_t* den);
  onumm10n2_t onumm10n2_div_or(onumm10n2_t* num, coeff_t val);
  void onumm10n2_div_ro_to(coeff_t num, onumm10n2_t* den, onumm10n2_t* res);
  void onumm10n2_div_oo_to(onumm10n2_t* num, onumm10n2_t* den, onumm10n2_t* res);
  void onumm10n2_div_or_to(onumm10n2_t* num, coeff_t val, onumm10n2_t* res);
  void onumm10n2_abs_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_neg(  onumm10n2_t* lhs);
  void onumm10n2_neg_to(  onumm10n2_t* lhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_sum_oo(  onumm10n2_t* lhs,  onumm10n2_t* rhs);
  void onumm10n2_sum_oo_to(  onumm10n2_t* lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_sum_ro(  coeff_t lhs,  onumm10n2_t* rhs);
  void onumm10n2_sum_ro_to(  coeff_t lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_sub_oo(  onumm10n2_t* lhs,  onumm10n2_t* rhs);
  void onumm10n2_sub_oo_to(  onumm10n2_t* lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_sub_ro(  coeff_t lhs,  onumm10n2_t* rhs);
  void onumm10n2_sub_ro_to(  coeff_t lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_sub_or(  onumm10n2_t* lhs,  coeff_t rhs);
  void onumm10n2_sub_or_to(  onumm10n2_t* lhs,  coeff_t rhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_mul_oo(  onumm10n2_t* lhs,  onumm10n2_t* rhs);
  void onumm10n2_mul_oo_to(  onumm10n2_t* lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_mul_ro(  coeff_t lhs,  onumm10n2_t* rhs);
  void onumm10n2_mul_ro_to(  coeff_t lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_trunc_mul_oo(  onumm10n2_t* lhs,  onumm10n2_t* rhs);
  void onumm10n2_trunc_mul_oo_to(  onumm10n2_t* lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_gem_oo(  onumm10n2_t* a,  onumm10n2_t* b,  onumm10n2_t* c);
  void onumm10n2_gem_oo_to(  onumm10n2_t* a,  onumm10n2_t* b,  onumm10n2_t* c, onumm10n2_t* res);
  onumm10n2_t onumm10n2_gem_ro(  coeff_t a,  onumm10n2_t* b,  onumm10n2_t* c);
  void onumm10n2_gem_ro_to(  coeff_t a,  onumm10n2_t* b,  onumm10n2_t* c, onumm10n2_t* res);
  void onumm10n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm10n2_t* a,  ord_t ord_rhs,  onumm10n2_t* b,  onumm10n2_t* c, onumm10n2_t* res);
  onumm10n2_t onumm10n2_feval(coeff_t* feval_re, onumm10n2_t* x);
  void onumm10n2_feval_to(coeff_t* feval_re, onumm10n2_t* x, onumm10n2_t* res);
  
  
  # From ../../../include/oti/static/onumm10n2/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm10n2/scalar/functions.h
  
  onumm10n2_t onumm10n2_atanh(onumm10n2_t* num);
  void onumm10n2_atanh_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_asinh(onumm10n2_t* num);
  void onumm10n2_asinh_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_acosh(onumm10n2_t* num);
  void onumm10n2_acosh_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_tanh(onumm10n2_t* num);
  void onumm10n2_tanh_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_sqrt(onumm10n2_t* num);
  void onumm10n2_sqrt_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_cbrt(onumm10n2_t* num);
  void onumm10n2_cbrt_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_cosh(onumm10n2_t* num);
  void onumm10n2_cosh_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_sinh(onumm10n2_t* num);
  void onumm10n2_sinh_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_asin(onumm10n2_t* num);
  void onumm10n2_asin_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_acos(onumm10n2_t* num);
  void onumm10n2_acos_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_atan(onumm10n2_t* num);
  void onumm10n2_atan_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_tan(onumm10n2_t* num);
  void onumm10n2_tan_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_cos(onumm10n2_t* num);
  void onumm10n2_cos_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_sin(onumm10n2_t* num );
  void onumm10n2_sin_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_logb(onumm10n2_t* num, double base);
  void onumm10n2_logb_to(onumm10n2_t* num, double base, onumm10n2_t* res);
  onumm10n2_t onumm10n2_log10(onumm10n2_t* num);
  void onumm10n2_log10_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_log(onumm10n2_t* num);
  void onumm10n2_log_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_exp(onumm10n2_t* num);
  void onumm10n2_exp_to(onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_pow(onumm10n2_t* num, double e);
  void onumm10n2_pow_to(onumm10n2_t* num, coeff_t e, onumm10n2_t* res);
  
  
  # From ../../../include/oti/static/onumm10n2/scalar/base.h
  
  void onumm10n2_set_im_o(onumm10n2_t* num, imdir_t idx, ord_t order, onumm10n2_t* res);
  void onumm10n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm10n2_t* res);
  void onumm10n2_set_deriv_o(onumm10n2_t* num, imdir_t idx, ord_t order, onumm10n2_t* res);
  void onumm10n2_extract_im_to( imdir_t idx, ord_t order, onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_extract_im(imdir_t idx, ord_t order, onumm10n2_t* num);
  onumm10n2_t onumm10n2_extract_deriv(imdir_t idx, ord_t order, onumm10n2_t* num);
  void onumm10n2_extract_deriv_to(imdir_t idx, ord_t order, onumm10n2_t* num, onumm10n2_t* res);
  void onumm10n2_get_im_to_o(imdir_t idx, ord_t order, onumm10n2_t* num, onumm10n2_t* res);
  onumm10n2_t onumm10n2_get_im_o(imdir_t idx, ord_t order, onumm10n2_t* num);
  void onumm10n2_get_im_to_r(imdir_t idx, ord_t order, onumm10n2_t* num, coeff_t* res);
  ord_t onumm10n2_get_order(onumm10n2_t* lhs);
  onumm10n2_t onumm10n2_get_deriv_o( imdir_t idx, ord_t order, onumm10n2_t* num);
  void onumm10n2_get_deriv_to( imdir_t idx, ord_t order, onumm10n2_t* num, onumm10n2_t* res);
  void onumm10n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm10n2_t* res);
  onumm10n2_t onumm10n2_init();
  ndir_t onumm10n2_get_ndir_order(ord_t order, onumm10n2_t* num);
  ndir_t onumm10n2_get_ndir_total(onumm10n2_t* num);
  coeff_t* onumm10n2_get_order_address(ord_t order, onumm10n2_t* num);
  onumm10n2_t onumm10n2_create_r(  coeff_t lhs);
  void onumm10n2_set_r(  coeff_t lhs, onumm10n2_t* res);
  void onumm10n2_set_o(  onumm10n2_t* lhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_get_order_im(ord_t order, onumm10n2_t* lhs);
  void onumm10n2_get_order_im_to(ord_t order, onumm10n2_t* lhs, onumm10n2_t* res);
  coeff_t onumm10n2_get_item(imdir_t idx, ord_t order, onumm10n2_t* lhs);
  coeff_t onumm10n2_get_deriv(imdir_t idx, ord_t order, onumm10n2_t* lhs);
  void onumm10n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm10n2_t* x);
  onumm10n2_t onumm10n2_copy(  onumm10n2_t* lhs);
  void onumm10n2_copy_to(  onumm10n2_t* lhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_taylor_integrate(coeff_t* deltas,onumm10n2_t* lhs);
  void onumm10n2_taylor_integrate_to(coeff_t* deltas,onumm10n2_t* lhs, onumm10n2_t* res);
  onumm10n2_t onumm10n2_truncate_im(imdir_t idx, ord_t order, onumm10n2_t* lhs);
  void onumm10n2_truncate_im_to(imdir_t idx, ord_t order, onumm10n2_t* lhs, onumm10n2_t* res);
  void onumm10n2_print(  onumm10n2_t* lhs);
  imdir_t onumm10n2_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm10n2/scalar/gauss/utils.h
  
  void feonumm10n2_dimCheck(feonumm10n2_t* arr1,feonumm10n2_t* arr2);
  void feonumm10n2_get_active_bases(feonumm10n2_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm10n2/scalar/gauss/algebra.h
  
  feonumm10n2_t feonumm10n2_neg(   feonumm10n2_t* num);
  void     feonumm10n2_neg_to(feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_sum_ff(   feonumm10n2_t* lhs, feonumm10n2_t* rhs);
  void     feonumm10n2_sum_ff_to(feonumm10n2_t* lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_sum_of(   onumm10n2_t* lhs, feonumm10n2_t* rhs);
  void     feonumm10n2_sum_of_to(onumm10n2_t* lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_sum_rf(   coeff_t lhs, feonumm10n2_t* rhs);
  void     feonumm10n2_sum_rf_to(coeff_t lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_sub_ff(     feonumm10n2_t* lhs,  feonumm10n2_t* rhs);
  void     feonumm10n2_sub_ff_to(  feonumm10n2_t* lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_sub_of(    onumm10n2_t* lhs,  feonumm10n2_t* rhs);
  void     feonumm10n2_sub_of_to( onumm10n2_t* lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_sub_fo(     feonumm10n2_t* lhs, onumm10n2_t* rhs);
  void     feonumm10n2_sub_fo_to(  feonumm10n2_t* lhs, onumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_sub_rf(       coeff_t lhs,  feonumm10n2_t* rhs);
  void     feonumm10n2_sub_rf_to(    coeff_t lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_sub_fr(     feonumm10n2_t* lhs,    coeff_t rhs);
  void     feonumm10n2_sub_fr_to(  feonumm10n2_t* lhs,    coeff_t rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_mul_ff(   feonumm10n2_t* lhs, feonumm10n2_t* rhs);
  void     feonumm10n2_mul_ff_to(feonumm10n2_t* lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_mul_of(   onumm10n2_t* lhs, feonumm10n2_t* rhs);
  void     feonumm10n2_mul_of_to(onumm10n2_t* lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_mul_rf(   coeff_t lhs, feonumm10n2_t* rhs);
  void     feonumm10n2_mul_rf_to(coeff_t lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_div_ff(     feonumm10n2_t* lhs,  feonumm10n2_t* rhs);
  void     feonumm10n2_div_ff_to(  feonumm10n2_t* lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_div_of(    onumm10n2_t* lhs,  feonumm10n2_t* rhs);
  void     feonumm10n2_div_of_to( onumm10n2_t* lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_div_fo(     feonumm10n2_t* lhs, onumm10n2_t* rhs);
  void     feonumm10n2_div_fo_to(  feonumm10n2_t* lhs, onumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_div_rf(       coeff_t lhs,  feonumm10n2_t* rhs);
  void     feonumm10n2_div_rf_to(    coeff_t lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_div_fr(     feonumm10n2_t* lhs,    coeff_t rhs);
  void     feonumm10n2_div_fr_to(  feonumm10n2_t* lhs,    coeff_t rhs, feonumm10n2_t* res);
  
  
  # From ../../../include/oti/static/onumm10n2/scalar/gauss/functions.h
  
  feonumm10n2_t feonumm10n2_atanh(    feonumm10n2_t* num);
  void     feonumm10n2_atanh_to( feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_asinh(    feonumm10n2_t* num);
  void     feonumm10n2_asinh_to( feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_acosh(    feonumm10n2_t* num);
  void     feonumm10n2_acosh_to( feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_tanh(     feonumm10n2_t* num);
  void     feonumm10n2_tanh_to(  feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_cosh(     feonumm10n2_t* num);
  void     feonumm10n2_cosh_to(  feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_sinh(     feonumm10n2_t* num);
  void     feonumm10n2_sinh_to(  feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_asin(     feonumm10n2_t* num);
  void     feonumm10n2_asin_to(  feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_acos(     feonumm10n2_t* num);
  void     feonumm10n2_acos_to(  feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_atan(     feonumm10n2_t* num);
  void     feonumm10n2_atan_to(  feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_tan(      feonumm10n2_t* num);
  void     feonumm10n2_tan_to(   feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_cos(      feonumm10n2_t* num);
  void     feonumm10n2_cos_to(   feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_sin(      feonumm10n2_t* num);
  void     feonumm10n2_sin_to(   feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_logb(     feonumm10n2_t* num, double base);
  void     feonumm10n2_logb_to(  feonumm10n2_t* num, double base, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_log10(    feonumm10n2_t* num);
  void     feonumm10n2_log10_to( feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_log(      feonumm10n2_t* num);
  void     feonumm10n2_log_to(   feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_exp(      feonumm10n2_t* num);
  void     feonumm10n2_exp_to(   feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_cbrt(     feonumm10n2_t* num);
  void     feonumm10n2_cbrt_to(  feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_sqrt(     feonumm10n2_t* num);
  void     feonumm10n2_sqrt_to(  feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_pow(      feonumm10n2_t* num, double e);
  void     feonumm10n2_pow_to(   feonumm10n2_t* num, double e, feonumm10n2_t* res);
  onumm10n2_t feonumm10n2_integrate(       feonumm10n2_t* num, feonumm10n2_t* w);
  void      feonumm10n2_integrate_to(    feonumm10n2_t* num, feonumm10n2_t* w, onumm10n2_t* res);
  onumm10n2_t feonumm10n2_integrate_f(     feonumm10n2_t* num, feonumm10n2_t* w);
  void      feonumm10n2_integrate_f_to(  feonumm10n2_t* num, feonumm10n2_t* w, onumm10n2_t* res);
  onumm10n2_t feonumm10n2_integrate_r(       coeff_t num, feonumm10n2_t* w);
  void      feonumm10n2_integrate_r_to(    coeff_t num, feonumm10n2_t* w, onumm10n2_t* res);
  onumm10n2_t feonumm10n2_integrate_o(    onumm10n2_t* num, feonumm10n2_t* w);
  void      feonumm10n2_integrate_o_to( onumm10n2_t* num, feonumm10n2_t* w, onumm10n2_t* res);
  
  
  # From ../../../include/oti/static/onumm10n2/scalar/gauss/base.h
  
  void     feonumm10n2_get_order_im_to( ord_t order, feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_get_order_im(    ord_t order, feonumm10n2_t* num);
  feonumm10n2_t feonumm10n2_get_im(    imdir_t idx, ord_t order, feonumm10n2_t* num);
  void     feonumm10n2_get_im_to( imdir_t idx, ord_t order, feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_get_deriv(    imdir_t idx, ord_t order, feonumm10n2_t* num);
  void     feonumm10n2_get_deriv_to( imdir_t idx, ord_t order, feonumm10n2_t* num, feonumm10n2_t* res);
  void feonumm10n2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm10n2_t* num);
  void feonumm10n2_set_im_o( onumm10n2_t* val, imdir_t idx, ord_t order, feonumm10n2_t* num);
  void feonumm10n2_set_im_f(  feonumm10n2_t* val, imdir_t idx, ord_t order, feonumm10n2_t* num);
  void feonumm10n2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm10n2_t* num);
  void feonumm10n2_set_deriv_o( onumm10n2_t* val, imdir_t idx, ord_t order, feonumm10n2_t* num);
  void feonumm10n2_set_deriv_f(  feonumm10n2_t* val, imdir_t idx, ord_t order, feonumm10n2_t* num);
  feonumm10n2_t feonumm10n2_extract_im(    imdir_t idx, ord_t order, feonumm10n2_t* num);
  void     feonumm10n2_extract_im_to( imdir_t idx, ord_t order, feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_extract_deriv(    imdir_t idx, ord_t order, feonumm10n2_t* num);
  void     feonumm10n2_extract_deriv_to( imdir_t idx, ord_t order, feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_truncate_im(    imdir_t idx, ord_t order, feonumm10n2_t* num);
  void     feonumm10n2_truncate_im_to( imdir_t idx, ord_t order, feonumm10n2_t* num, feonumm10n2_t* res);
  feonumm10n2_t feonumm10n2_copy(    feonumm10n2_t* src);
  void     feonumm10n2_copy_to( feonumm10n2_t* src, feonumm10n2_t* dst);
  void feonumm10n2_set_r(    coeff_t num, feonumm10n2_t* res);
  void feonumm10n2_set_o( onumm10n2_t* num, feonumm10n2_t* res);
  void feonumm10n2_set_f(  feonumm10n2_t* num, feonumm10n2_t* res);
  void feonumm10n2_set_item_k_r(   coeff_t  num, uint64_t k, feonumm10n2_t* res);
  void feonumm10n2_set_item_k_o( onumm10n2_t* num, uint64_t k, feonumm10n2_t* res);
  onumm10n2_t feonumm10n2_get_item_k(   feonumm10n2_t* num, uint64_t k);
  void      feonumm10n2_get_item_k_to(feonumm10n2_t* num, uint64_t k, onumm10n2_t* res);
  feonumm10n2_t feonumm10n2_zeros(uint64_t nIntPts);
  feonumm10n2_t feonumm10n2_createEmpty(uint64_t nIntPts);
  feonumm10n2_t feonumm10n2_empty_like(feonumm10n2_t* arr);
  void feonumm10n2_free(feonumm10n2_t* num);
  ord_t feonumm10n2_get_order( feonumm10n2_t* num );
  feonumm10n2_t feonumm10n2_init();
  
  