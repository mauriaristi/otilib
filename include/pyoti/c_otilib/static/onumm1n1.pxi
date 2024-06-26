cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm1n1/scalar/structures.h
  
  ctypedef struct  onumm1n1_t : # {
    coeff_t r;
    coeff_t e1;
  # } onumm1n1_t;
  
  
  # From ../../../include/oti/static/onumm1n1/array/structures.h
  
  ctypedef struct  oarrm1n1_t : # {
      onumm1n1_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm1n1_t;
  
  
  # From ../../../include/oti/static/onumm1n1/scalar/gauss/structures.h
  
  ctypedef struct  feonumm1n1_t: # {
      onumm1n1_t*  p_data;
      uint64_t    nip;
  # } feonumm1n1_t;
  
  
  # From ../../../include/oti/static/onumm1n1/array/gauss/structures.h
  
  ctypedef struct  feoarrm1n1_t: # {
      oarrm1n1_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm1n1_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm1n1/scalar/utils.h
  
  void onumm1n1_get_active_bases(onumm1n1_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm1n1/scalar/algebra.h
  
  onumm1n1_t onumm1n1_abs(onumm1n1_t* num);
  onumm1n1_t onumm1n1_div_ro(coeff_t num, onumm1n1_t* den);
  onumm1n1_t onumm1n1_div_oo(onumm1n1_t* num, onumm1n1_t* den);
  onumm1n1_t onumm1n1_div_or(onumm1n1_t* num, coeff_t val);
  void onumm1n1_div_ro_to(coeff_t num, onumm1n1_t* den, onumm1n1_t* res);
  void onumm1n1_div_oo_to(onumm1n1_t* num, onumm1n1_t* den, onumm1n1_t* res);
  void onumm1n1_div_or_to(onumm1n1_t* num, coeff_t val, onumm1n1_t* res);
  void onumm1n1_abs_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_neg(  onumm1n1_t* lhs);
  void onumm1n1_neg_to(  onumm1n1_t* lhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_sum_oo(  onumm1n1_t* lhs,  onumm1n1_t* rhs);
  void onumm1n1_sum_oo_to(  onumm1n1_t* lhs,  onumm1n1_t* rhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_sum_ro(  coeff_t lhs,  onumm1n1_t* rhs);
  void onumm1n1_sum_ro_to(  coeff_t lhs,  onumm1n1_t* rhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_sub_oo(  onumm1n1_t* lhs,  onumm1n1_t* rhs);
  void onumm1n1_sub_oo_to(  onumm1n1_t* lhs,  onumm1n1_t* rhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_sub_ro(  coeff_t lhs,  onumm1n1_t* rhs);
  void onumm1n1_sub_ro_to(  coeff_t lhs,  onumm1n1_t* rhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_sub_or(  onumm1n1_t* lhs,  coeff_t rhs);
  void onumm1n1_sub_or_to(  onumm1n1_t* lhs,  coeff_t rhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_mul_oo(  onumm1n1_t* lhs,  onumm1n1_t* rhs);
  void onumm1n1_mul_oo_to(  onumm1n1_t* lhs,  onumm1n1_t* rhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_mul_ro(  coeff_t lhs,  onumm1n1_t* rhs);
  void onumm1n1_mul_ro_to(  coeff_t lhs,  onumm1n1_t* rhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_trunc_mul_oo(  onumm1n1_t* lhs,  onumm1n1_t* rhs);
  void onumm1n1_trunc_mul_oo_to(  onumm1n1_t* lhs,  onumm1n1_t* rhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_gem_oo(  onumm1n1_t* a,  onumm1n1_t* b,  onumm1n1_t* c);
  void onumm1n1_gem_oo_to(  onumm1n1_t* a,  onumm1n1_t* b,  onumm1n1_t* c, onumm1n1_t* res);
  onumm1n1_t onumm1n1_gem_ro(  coeff_t a,  onumm1n1_t* b,  onumm1n1_t* c);
  void onumm1n1_gem_ro_to(  coeff_t a,  onumm1n1_t* b,  onumm1n1_t* c, onumm1n1_t* res);
  void onumm1n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n1_t* a,  ord_t ord_rhs,  onumm1n1_t* b,  onumm1n1_t* c, onumm1n1_t* res);
  void onumm1n1_trunc_sum_oo_to(ord_t order, onumm1n1_t* lhs,onumm1n1_t* rhs, onumm1n1_t* res);
  void onumm1n1_trunc_sub_oo_to(ord_t order, onumm1n1_t* lhs,onumm1n1_t* rhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_feval(coeff_t* feval_re, onumm1n1_t* x);
  void onumm1n1_feval_to(coeff_t* feval_re, onumm1n1_t* x, onumm1n1_t* res);
  
  
  # From ../../../include/oti/static/onumm1n1/scalar/base.h
  
  void onumm1n1_set_im_o(onumm1n1_t* num, imdir_t idx, ord_t order, onumm1n1_t* res);
  void onumm1n1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm1n1_t* res);
  void onumm1n1_set_deriv_o(onumm1n1_t* num, imdir_t idx, ord_t order, onumm1n1_t* res);
  void onumm1n1_extract_im_to( imdir_t idx, ord_t order, onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_extract_im(imdir_t idx, ord_t order, onumm1n1_t* num);
  onumm1n1_t onumm1n1_extract_deriv(imdir_t idx, ord_t order, onumm1n1_t* num);
  void onumm1n1_extract_deriv_to(imdir_t idx, ord_t order, onumm1n1_t* num, onumm1n1_t* res);
  void onumm1n1_get_im_to_o(imdir_t idx, ord_t order, onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_get_im_o(imdir_t idx, ord_t order, onumm1n1_t* num);
  void onumm1n1_get_im_to_r(imdir_t idx, ord_t order, onumm1n1_t* num, coeff_t* res);
  ord_t onumm1n1_get_order(onumm1n1_t* lhs);
  onumm1n1_t onumm1n1_get_deriv_o( imdir_t idx, ord_t order, onumm1n1_t* num);
  void onumm1n1_get_deriv_to( imdir_t idx, ord_t order, onumm1n1_t* num, onumm1n1_t* res);
  void onumm1n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm1n1_t* res);
  onumm1n1_t onumm1n1_init();
  ndir_t onumm1n1_get_ndir_order(ord_t order, onumm1n1_t* num);
  ndir_t onumm1n1_get_ndir_total(onumm1n1_t* num);
  coeff_t* onumm1n1_get_order_address(ord_t order, onumm1n1_t* num);
  onumm1n1_t onumm1n1_create_r(  coeff_t lhs);
  void onumm1n1_set_r(  coeff_t lhs, onumm1n1_t* res);
  void onumm1n1_set_o(  onumm1n1_t* lhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_get_order_im(ord_t order, onumm1n1_t* lhs);
  void onumm1n1_get_order_im_to(ord_t order, onumm1n1_t* lhs, onumm1n1_t* res);
  coeff_t onumm1n1_get_item(imdir_t idx, ord_t order, onumm1n1_t* lhs);
  coeff_t onumm1n1_get_deriv(imdir_t idx, ord_t order, onumm1n1_t* lhs);
  void onumm1n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm1n1_t* x);
  onumm1n1_t onumm1n1_copy(  onumm1n1_t* lhs);
  void onumm1n1_copy_to(  onumm1n1_t* lhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_taylor_integrate(coeff_t* deltas,onumm1n1_t* lhs);
  void onumm1n1_taylor_integrate_to(coeff_t* deltas,onumm1n1_t* lhs, onumm1n1_t* res);
  onumm1n1_t onumm1n1_truncate_im(imdir_t idx, ord_t order, onumm1n1_t* lhs);
  void onumm1n1_truncate_im_to(imdir_t idx, ord_t order, onumm1n1_t* lhs, onumm1n1_t* res);
  void onumm1n1_print(  onumm1n1_t* lhs);
  imdir_t onumm1n1_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm1n1/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm1n1/scalar/functions.h
  
  onumm1n1_t onumm1n1_atanh(onumm1n1_t* num);
  void onumm1n1_atanh_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_asinh(onumm1n1_t* num);
  void onumm1n1_asinh_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_acosh(onumm1n1_t* num);
  void onumm1n1_acosh_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_tanh(onumm1n1_t* num);
  void onumm1n1_tanh_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_sqrt(onumm1n1_t* num);
  void onumm1n1_sqrt_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_cbrt(onumm1n1_t* num);
  void onumm1n1_cbrt_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_cosh(onumm1n1_t* num);
  void onumm1n1_cosh_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_sinh(onumm1n1_t* num);
  void onumm1n1_sinh_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_asin(onumm1n1_t* num);
  void onumm1n1_asin_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_acos(onumm1n1_t* num);
  void onumm1n1_acos_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_atan(onumm1n1_t* num);
  void onumm1n1_atan_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_tan(onumm1n1_t* num);
  void onumm1n1_tan_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_cos(onumm1n1_t* num);
  void onumm1n1_cos_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_sin(onumm1n1_t* num );
  void onumm1n1_sin_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_logb(onumm1n1_t* num, double base);
  void onumm1n1_logb_to(onumm1n1_t* num, double base, onumm1n1_t* res);
  onumm1n1_t onumm1n1_log10(onumm1n1_t* num);
  void onumm1n1_log10_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_log(onumm1n1_t* num);
  void onumm1n1_log_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_exp(onumm1n1_t* num);
  void onumm1n1_exp_to(onumm1n1_t* num, onumm1n1_t* res);
  onumm1n1_t onumm1n1_pow(onumm1n1_t* num, double e);
  void onumm1n1_pow_to(onumm1n1_t* num, coeff_t e, onumm1n1_t* res);
  
  
  # From ../../../include/oti/static/onumm1n1/scalar/gauss/utils.h
  
  void feonumm1n1_dimCheck(feonumm1n1_t* arr1,feonumm1n1_t* arr2);
  void feonumm1n1_get_active_bases(feonumm1n1_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n1/scalar/gauss/algebra.h
  
  feonumm1n1_t feonumm1n1_neg(   feonumm1n1_t* num);
  void     feonumm1n1_neg_to(feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_sum_ff(   feonumm1n1_t* lhs, feonumm1n1_t* rhs);
  void     feonumm1n1_sum_ff_to(feonumm1n1_t* lhs, feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_sum_of(   onumm1n1_t* lhs, feonumm1n1_t* rhs);
  void     feonumm1n1_sum_of_to(onumm1n1_t* lhs, feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_sum_rf(   coeff_t lhs, feonumm1n1_t* rhs);
  void     feonumm1n1_sum_rf_to(coeff_t lhs, feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_sub_ff(     feonumm1n1_t* lhs,  feonumm1n1_t* rhs);
  void     feonumm1n1_sub_ff_to(  feonumm1n1_t* lhs,  feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_sub_of(    onumm1n1_t* lhs,  feonumm1n1_t* rhs);
  void     feonumm1n1_sub_of_to( onumm1n1_t* lhs,  feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_sub_fo(     feonumm1n1_t* lhs, onumm1n1_t* rhs);
  void     feonumm1n1_sub_fo_to(  feonumm1n1_t* lhs, onumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_sub_rf(       coeff_t lhs,  feonumm1n1_t* rhs);
  void     feonumm1n1_sub_rf_to(    coeff_t lhs,  feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_sub_fr(     feonumm1n1_t* lhs,    coeff_t rhs);
  void     feonumm1n1_sub_fr_to(  feonumm1n1_t* lhs,    coeff_t rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_mul_ff(   feonumm1n1_t* lhs, feonumm1n1_t* rhs);
  void     feonumm1n1_mul_ff_to(feonumm1n1_t* lhs, feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_mul_of(   onumm1n1_t* lhs, feonumm1n1_t* rhs);
  void     feonumm1n1_mul_of_to(onumm1n1_t* lhs, feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_mul_rf(   coeff_t lhs, feonumm1n1_t* rhs);
  void     feonumm1n1_mul_rf_to(coeff_t lhs, feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_div_ff(     feonumm1n1_t* lhs,  feonumm1n1_t* rhs);
  void     feonumm1n1_div_ff_to(  feonumm1n1_t* lhs,  feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_div_of(    onumm1n1_t* lhs,  feonumm1n1_t* rhs);
  void     feonumm1n1_div_of_to( onumm1n1_t* lhs,  feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_div_fo(     feonumm1n1_t* lhs, onumm1n1_t* rhs);
  void     feonumm1n1_div_fo_to(  feonumm1n1_t* lhs, onumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_div_rf(       coeff_t lhs,  feonumm1n1_t* rhs);
  void     feonumm1n1_div_rf_to(    coeff_t lhs,  feonumm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_div_fr(     feonumm1n1_t* lhs,    coeff_t rhs);
  void     feonumm1n1_div_fr_to(  feonumm1n1_t* lhs,    coeff_t rhs, feonumm1n1_t* res);
  
  
  # From ../../../include/oti/static/onumm1n1/scalar/gauss/base.h
  
  void     feonumm1n1_get_order_im_to( ord_t order, feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_get_order_im(    ord_t order, feonumm1n1_t* num);
  feonumm1n1_t feonumm1n1_get_im(    imdir_t idx, ord_t order, feonumm1n1_t* num);
  void     feonumm1n1_get_im_to( imdir_t idx, ord_t order, feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_get_deriv(    imdir_t idx, ord_t order, feonumm1n1_t* num);
  void     feonumm1n1_get_deriv_to( imdir_t idx, ord_t order, feonumm1n1_t* num, feonumm1n1_t* res);
  void feonumm1n1_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm1n1_t* num);
  void feonumm1n1_set_im_o( onumm1n1_t* val, imdir_t idx, ord_t order, feonumm1n1_t* num);
  void feonumm1n1_set_im_f(  feonumm1n1_t* val, imdir_t idx, ord_t order, feonumm1n1_t* num);
  void feonumm1n1_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm1n1_t* num);
  void feonumm1n1_set_deriv_o( onumm1n1_t* val, imdir_t idx, ord_t order, feonumm1n1_t* num);
  void feonumm1n1_set_deriv_f(  feonumm1n1_t* val, imdir_t idx, ord_t order, feonumm1n1_t* num);
  feonumm1n1_t feonumm1n1_extract_im(    imdir_t idx, ord_t order, feonumm1n1_t* num);
  void     feonumm1n1_extract_im_to( imdir_t idx, ord_t order, feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_extract_deriv(    imdir_t idx, ord_t order, feonumm1n1_t* num);
  void     feonumm1n1_extract_deriv_to( imdir_t idx, ord_t order, feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_truncate_im(    imdir_t idx, ord_t order, feonumm1n1_t* num);
  void     feonumm1n1_truncate_im_to( imdir_t idx, ord_t order, feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_copy(    feonumm1n1_t* src);
  void     feonumm1n1_copy_to( feonumm1n1_t* src, feonumm1n1_t* dst);
  void feonumm1n1_set_r(    coeff_t num, feonumm1n1_t* res);
  void feonumm1n1_set_o( onumm1n1_t* num, feonumm1n1_t* res);
  void feonumm1n1_set_f(  feonumm1n1_t* num, feonumm1n1_t* res);
  void feonumm1n1_set_item_k_r(   coeff_t  num, uint64_t k, feonumm1n1_t* res);
  void feonumm1n1_set_item_k_o( onumm1n1_t* num, uint64_t k, feonumm1n1_t* res);
  onumm1n1_t feonumm1n1_get_item_k(   feonumm1n1_t* num, uint64_t k);
  void      feonumm1n1_get_item_k_to(feonumm1n1_t* num, uint64_t k, onumm1n1_t* res);
  feonumm1n1_t feonumm1n1_zeros(uint64_t nIntPts);
  feonumm1n1_t feonumm1n1_createEmpty(uint64_t nIntPts);
  feonumm1n1_t feonumm1n1_empty_like(feonumm1n1_t* arr);
  void feonumm1n1_free(feonumm1n1_t* num);
  ord_t feonumm1n1_get_order( feonumm1n1_t* num );
  feonumm1n1_t feonumm1n1_init();
  
  
  # From ../../../include/oti/static/onumm1n1/scalar/gauss/functions.h
  
  feonumm1n1_t feonumm1n1_atanh(    feonumm1n1_t* num);
  void     feonumm1n1_atanh_to( feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_asinh(    feonumm1n1_t* num);
  void     feonumm1n1_asinh_to( feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_acosh(    feonumm1n1_t* num);
  void     feonumm1n1_acosh_to( feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_tanh(     feonumm1n1_t* num);
  void     feonumm1n1_tanh_to(  feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_cosh(     feonumm1n1_t* num);
  void     feonumm1n1_cosh_to(  feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_sinh(     feonumm1n1_t* num);
  void     feonumm1n1_sinh_to(  feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_asin(     feonumm1n1_t* num);
  void     feonumm1n1_asin_to(  feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_acos(     feonumm1n1_t* num);
  void     feonumm1n1_acos_to(  feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_atan(     feonumm1n1_t* num);
  void     feonumm1n1_atan_to(  feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_tan(      feonumm1n1_t* num);
  void     feonumm1n1_tan_to(   feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_cos(      feonumm1n1_t* num);
  void     feonumm1n1_cos_to(   feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_sin(      feonumm1n1_t* num);
  void     feonumm1n1_sin_to(   feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_logb(     feonumm1n1_t* num, double base);
  void     feonumm1n1_logb_to(  feonumm1n1_t* num, double base, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_log10(    feonumm1n1_t* num);
  void     feonumm1n1_log10_to( feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_log(      feonumm1n1_t* num);
  void     feonumm1n1_log_to(   feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_exp(      feonumm1n1_t* num);
  void     feonumm1n1_exp_to(   feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_cbrt(     feonumm1n1_t* num);
  void     feonumm1n1_cbrt_to(  feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_sqrt(     feonumm1n1_t* num);
  void     feonumm1n1_sqrt_to(  feonumm1n1_t* num, feonumm1n1_t* res);
  feonumm1n1_t feonumm1n1_pow(      feonumm1n1_t* num, double e);
  void     feonumm1n1_pow_to(   feonumm1n1_t* num, double e, feonumm1n1_t* res);
  onumm1n1_t feonumm1n1_integrate(       feonumm1n1_t* num, feonumm1n1_t* w);
  void      feonumm1n1_integrate_to(    feonumm1n1_t* num, feonumm1n1_t* w, onumm1n1_t* res);
  onumm1n1_t feonumm1n1_integrate_f(     feonumm1n1_t* num, feonumm1n1_t* w);
  void      feonumm1n1_integrate_f_to(  feonumm1n1_t* num, feonumm1n1_t* w, onumm1n1_t* res);
  onumm1n1_t feonumm1n1_integrate_r(       coeff_t num, feonumm1n1_t* w);
  void      feonumm1n1_integrate_r_to(    coeff_t num, feonumm1n1_t* w, onumm1n1_t* res);
  onumm1n1_t feonumm1n1_integrate_o(    onumm1n1_t* num, feonumm1n1_t* w);
  void      feonumm1n1_integrate_o_to( onumm1n1_t* num, feonumm1n1_t* w, onumm1n1_t* res);
  
  
  # From ../../../include/oti/static/onumm1n1/array/utils.h
  
  void oarrm1n1_dimCheck_OO_elementwise(oarrm1n1_t* arr1, oarrm1n1_t* arr2, oarrm1n1_t* res);
  void oarrm1n1_dimCheck_RO_elementwise(darr_t*  arr1, oarrm1n1_t* arr2, oarrm1n1_t* res);
  void oarrm1n1_dimCheck_OO_matmul(oarrm1n1_t* arr1, oarrm1n1_t* arr2, oarrm1n1_t* res);
  void oarrm1n1_dimCheck_RO_matmul(darr_t*  arr1, oarrm1n1_t* arr2, oarrm1n1_t* res);
  void oarrm1n1_dimCheck_OR_matmul(oarrm1n1_t* arr1, darr_t*  arr2, oarrm1n1_t* res);
  void oarrm1n1_dimCheck_O_squareness(oarrm1n1_t* arr1, oarrm1n1_t* res);
  void oarrm1n1_dimCheck_OO_samesize(oarrm1n1_t* arr1, oarrm1n1_t* res);
  void oarrm1n1_dimCheck_RO_samesize(darr_t* arr1, oarrm1n1_t* res);
  ord_t oarrm1n1_get_order(oarrm1n1_t* arr);
  void oarrm1n1_get_active_bases(oarrm1n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n1/array/algebra_elementwise.h
  
  oarrm1n1_t oarrm1n1_neg(oarrm1n1_t* arr);
  void oarrm1n1_neg_to(oarrm1n1_t* rhs, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_sum_OO(oarrm1n1_t*   lhs, oarrm1n1_t* rhs);
  oarrm1n1_t oarrm1n1_sum_RO(darr_t*    lhs, oarrm1n1_t* rhs);
  oarrm1n1_t oarrm1n1_sum_oO(onumm1n1_t* lhs, oarrm1n1_t* rhs);
  oarrm1n1_t oarrm1n1_sum_rO(coeff_t    lhs, oarrm1n1_t* rhs);
  void oarrm1n1_sum_OO_to(oarrm1n1_t*   lhs, oarrm1n1_t* rhs, oarrm1n1_t* res);
  void oarrm1n1_sum_RO_to(darr_t*    lhs, oarrm1n1_t* rhs, oarrm1n1_t* res);
  void oarrm1n1_sum_oO_to(onumm1n1_t* lhs, oarrm1n1_t* rhs, oarrm1n1_t* res);
  void oarrm1n1_sum_rO_to(coeff_t    lhs, oarrm1n1_t* rhs, oarrm1n1_t* res);
  void oarrm1n1_trunc_sum_OO_to(ord_t order, oarrm1n1_t* arr1, oarrm1n1_t* arr2, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_sub_OO(oarrm1n1_t*   lhs, oarrm1n1_t*   rhs);
  oarrm1n1_t oarrm1n1_sub_RO(darr_t*    lhs, oarrm1n1_t*   rhs);
  oarrm1n1_t oarrm1n1_sub_OR(oarrm1n1_t*   lhs, darr_t*    rhs);
  oarrm1n1_t oarrm1n1_sub_oO(onumm1n1_t* lhs, oarrm1n1_t*   rhs);
  oarrm1n1_t oarrm1n1_sub_Oo(oarrm1n1_t*   lhs, onumm1n1_t* rhs);
  oarrm1n1_t oarrm1n1_sub_rO(coeff_t    lhs, oarrm1n1_t*   rhs);
  oarrm1n1_t oarrm1n1_sub_Or(oarrm1n1_t*   lhs, coeff_t    rhs);
  void oarrm1n1_sub_OO_to( oarrm1n1_t*   lhs, oarrm1n1_t*   rhs, oarrm1n1_t* res);
  void oarrm1n1_sub_RO_to( darr_t*    lhs, oarrm1n1_t*   rhs, oarrm1n1_t* res);
  void oarrm1n1_sub_OR_to( oarrm1n1_t*   lhs, darr_t*    rhs, oarrm1n1_t* res);
  void oarrm1n1_sub_oO_to( onumm1n1_t* lhs, oarrm1n1_t*   rhs, oarrm1n1_t* res);
  void oarrm1n1_sub_Oo_to( oarrm1n1_t*   lhs, onumm1n1_t* rhs, oarrm1n1_t* res);
  void oarrm1n1_sub_rO_to( coeff_t    lhs, oarrm1n1_t*   rhs, oarrm1n1_t* res);
  void oarrm1n1_sub_Or_to( oarrm1n1_t*   lhs, coeff_t    rhs, oarrm1n1_t* res);
  void oarrm1n1_trunc_sub_OO_to(ord_t order, oarrm1n1_t* arr1, oarrm1n1_t* arr2, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_mul_OO(oarrm1n1_t*   lhs, oarrm1n1_t* rhs);
  oarrm1n1_t oarrm1n1_mul_RO(darr_t*    lhs, oarrm1n1_t* rhs);
  oarrm1n1_t oarrm1n1_mul_oO(onumm1n1_t* lhs, oarrm1n1_t* rhs);
  oarrm1n1_t oarrm1n1_mul_rO(coeff_t    lhs, oarrm1n1_t* rhs);
  void oarrm1n1_mul_OO_to(oarrm1n1_t*   lhs, oarrm1n1_t* rhs, oarrm1n1_t* res);
  void oarrm1n1_mul_RO_to(darr_t*    lhs, oarrm1n1_t* rhs, oarrm1n1_t* res);
  void oarrm1n1_mul_oO_to(onumm1n1_t* lhs, oarrm1n1_t* rhs, oarrm1n1_t* res);
  void oarrm1n1_mul_rO_to(coeff_t    lhs, oarrm1n1_t* rhs, oarrm1n1_t* res);
  void oarrm1n1_gem_OO_to(  oarrm1n1_t* arr1, oarrm1n1_t* arr2, oarrm1n1_t* arr3, oarrm1n1_t* res);
  void oarrm1n1_gem_oO_to(onumm1n1_t* arr1, oarrm1n1_t* arr2, oarrm1n1_t* arr3, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_div_OO(oarrm1n1_t*   lhs, oarrm1n1_t*   rhs);
  oarrm1n1_t oarrm1n1_div_OR(oarrm1n1_t*   lhs, darr_t*    rhs);
  oarrm1n1_t oarrm1n1_div_RO(darr_t*    lhs, oarrm1n1_t*   rhs);
  oarrm1n1_t oarrm1n1_div_oO(onumm1n1_t* lhs, oarrm1n1_t*   rhs);
  oarrm1n1_t oarrm1n1_div_Oo(oarrm1n1_t*   lhs, onumm1n1_t* rhs);
  oarrm1n1_t oarrm1n1_div_rO(coeff_t    lhs, oarrm1n1_t*   rhs);
  oarrm1n1_t oarrm1n1_div_Or(oarrm1n1_t*   lhs, coeff_t    rhs);
  void oarrm1n1_div_OO_to(oarrm1n1_t*   lhs, oarrm1n1_t*   rhs, oarrm1n1_t* res);
  void oarrm1n1_div_RO_to(darr_t*    lhs, oarrm1n1_t*   rhs, oarrm1n1_t* res);
  void oarrm1n1_div_OR_to(oarrm1n1_t*   lhs, darr_t*    rhs, oarrm1n1_t* res);
  void oarrm1n1_div_oO_to(onumm1n1_t* lhs, oarrm1n1_t*   rhs, oarrm1n1_t* res);
  void oarrm1n1_div_Oo_to(oarrm1n1_t*   lhs, onumm1n1_t* rhs, oarrm1n1_t* res);
  void oarrm1n1_div_rO_to(coeff_t    lhs, oarrm1n1_t*   rhs, oarrm1n1_t* res);
  void oarrm1n1_div_Or_to(oarrm1n1_t*   lhs, coeff_t    rhs, oarrm1n1_t* res);
  
  
  # From ../../../include/oti/static/onumm1n1/array/base.h
  
  void    oarrm1n1_taylor_integrate_to( coeff_t* deltas, oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_taylor_integrate(    coeff_t* deltas, oarrm1n1_t* arr);
  void    oarrm1n1_get_order_im_to( ord_t order, oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_get_order_im(    ord_t order, oarrm1n1_t* arr);
  void oarrm1n1_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n1_t* res);
  void oarrm1n1_set_slice_O( oarrm1n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n1_t* res);
  void oarrm1n1_set_slice_o( onumm1n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_get_slice( oarrm1n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm1n1_get_slice_to( oarrm1n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_truncate_im(    imdir_t idx, ord_t order, oarrm1n1_t* arr);
  void    oarrm1n1_truncate_im_to( imdir_t idx, ord_t order, oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_extract_im(   imdir_t idx, ord_t order, oarrm1n1_t* arr);
  void    oarrm1n1_extract_im_to(imdir_t idx, ord_t order, oarrm1n1_t* arr, oarrm1n1_t* res);
  darr_t  oarrm1n1_get_deriv(    imdir_t idx, ord_t order, oarrm1n1_t* arr);
  void    oarrm1n1_get_deriv_to( imdir_t idx, ord_t order, oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_get_deriv_o(  imdir_t idx, ord_t order, oarrm1n1_t* arr);
  oarrm1n1_t oarrm1n1_extract_deriv(    imdir_t idx, ord_t order, oarrm1n1_t* arr);
  void    oarrm1n1_extract_deriv_to( imdir_t idx, ord_t order, oarrm1n1_t* arr, oarrm1n1_t* res);
  darr_t  oarrm1n1_get_im(   imdir_t idx, ord_t order, oarrm1n1_t* arr);
  oarrm1n1_t oarrm1n1_get_im_o( imdir_t idx, ord_t order, oarrm1n1_t* arr);
  void    oarrm1n1_get_im_to(imdir_t idx, ord_t order, oarrm1n1_t* arr, oarrm1n1_t* res);
  void    oarrm1n1_copy_to(oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_copy(oarrm1n1_t* arr);
  void oarrm1n1_set_all_r( coeff_t num, oarrm1n1_t* arr);
  void oarrm1n1_set_item_i_r( coeff_t num, uint64_t i, oarrm1n1_t* arr);
  void oarrm1n1_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm1n1_t* arr);
  void oarrm1n1_set_r(   coeff_t  num,   oarrm1n1_t* arr);
  void oarrm1n1_set_o( onumm1n1_t* num,   oarrm1n1_t* arr);
  void oarrm1n1_set_O(   oarrm1n1_t* arrin, oarrm1n1_t* arr);
  void oarrm1n1_set_all_o( onumm1n1_t* src, oarrm1n1_t* arr);
  void oarrm1n1_set_item_i_o( onumm1n1_t* num, uint64_t i, oarrm1n1_t* arr);
  void oarrm1n1_set_item_ij_o( onumm1n1_t* num, uint64_t i, uint64_t j, oarrm1n1_t* arr);
  onumm1n1_t oarrm1n1_get_item_i(    oarrm1n1_t* arr, uint64_t i);
  void      oarrm1n1_get_item_i_to( oarrm1n1_t* arr, uint64_t i,             onumm1n1_t* res);
  onumm1n1_t oarrm1n1_get_item_ij(   oarrm1n1_t* arr, uint64_t i, uint64_t j);
  void      oarrm1n1_get_item_ij_to(oarrm1n1_t* arr, uint64_t i, uint64_t j, onumm1n1_t* res);
  oarrm1n1_t oarrm1n1_init();
  void oarrm1n1_free(oarrm1n1_t* arr);
  oarrm1n1_t oarrm1n1_empty_like(oarrm1n1_t* arr);
  oarrm1n1_t oarrm1n1_eye(uint64_t nrows);
  oarrm1n1_t oarrm1n1_ones(uint64_t nrows, uint64_t ncols);
  oarrm1n1_t oarrm1n1_zeros(uint64_t nrows, uint64_t ncols);
  oarrm1n1_t oarrm1n1_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm1n1/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm1n1/array/algebra_matops.h
  
  onumm1n1_t oarrm1n1_dotproduct_OO(    oarrm1n1_t* lhs, oarrm1n1_t* rhs);
  void      oarrm1n1_dotproduct_OO_to( oarrm1n1_t* lhs, oarrm1n1_t* rhs, onumm1n1_t* res);
  onumm1n1_t oarrm1n1_dotproduct_RO(     darr_t* lhs, oarrm1n1_t* rhs);
  void      oarrm1n1_dotproduct_RO_to(  darr_t* lhs, oarrm1n1_t* rhs, onumm1n1_t* res);
  oarrm1n1_t oarrm1n1_matmul_OO(    oarrm1n1_t* lhs, oarrm1n1_t* rhs);
  oarrm1n1_t oarrm1n1_matmul_OR(    oarrm1n1_t* lhs,  darr_t* rhs);
  oarrm1n1_t oarrm1n1_matmul_RO(     darr_t* lhs, oarrm1n1_t* rhs);
  void    oarrm1n1_matmul_OO_to( oarrm1n1_t* lhs, oarrm1n1_t* rhs, oarrm1n1_t* res);
  void    oarrm1n1_matmul_OR_to( oarrm1n1_t* lhs,  darr_t* rhs, oarrm1n1_t* res);
  void    oarrm1n1_matmul_RO_to(  darr_t* lhs, oarrm1n1_t* rhs, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_transpose(    oarrm1n1_t* arr1);
  void    oarrm1n1_transpose_to( oarrm1n1_t* arr1, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_invert(    oarrm1n1_t* arr1);
  void    oarrm1n1_invert_to( oarrm1n1_t* arr1, oarrm1n1_t* res);
  onumm1n1_t oarrm1n1_det(    oarrm1n1_t* arr1);
  void      oarrm1n1_det_to( oarrm1n1_t* arr1, onumm1n1_t* res);
  onumm1n1_t oarrm1n1_norm(    oarrm1n1_t* arr1);
  void      oarrm1n1_norm_to( oarrm1n1_t* arr1,  onumm1n1_t* res);
  onumm1n1_t oarrm1n1_pnorm(    oarrm1n1_t* arr1, coeff_t p);
  void      oarrm1n1_pnorm_to( oarrm1n1_t* arr1, coeff_t p, onumm1n1_t* res);
  
  
  # From ../../../include/oti/static/onumm1n1/array/functions.h
  
  oarrm1n1_t oarrm1n1_atanh(   oarrm1n1_t* arr);
  void    oarrm1n1_atanh_to(oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_asinh(   oarrm1n1_t* arr);
  void    oarrm1n1_asinh_to(oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_acosh(   oarrm1n1_t* arr);
  void    oarrm1n1_acosh_to(oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_tanh(    oarrm1n1_t* arr);
  void    oarrm1n1_tanh_to( oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_cbrt(    oarrm1n1_t* arr);
  void    oarrm1n1_cbrt_to( oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_sqrt(    oarrm1n1_t* arr);
  void    oarrm1n1_sqrt_to( oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_cosh(    oarrm1n1_t* arr);
  void    oarrm1n1_cosh_to( oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_sinh(    oarrm1n1_t* arr);
  void    oarrm1n1_sinh_to( oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_asin(    oarrm1n1_t* arr);
  void    oarrm1n1_asin_to( oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_acos(    oarrm1n1_t* arr);
  void    oarrm1n1_acos_to( oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_atan(    oarrm1n1_t* arr);
  void    oarrm1n1_atan_to( oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_tan(     oarrm1n1_t* arr);
  void    oarrm1n1_tan_to(  oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_cos(     oarrm1n1_t* arr);
  void    oarrm1n1_cos_to(  oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_sin(     oarrm1n1_t* arr);
  void    oarrm1n1_sin_to(  oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_logb(    oarrm1n1_t* arr, double base);
  void    oarrm1n1_logb_to( oarrm1n1_t* arr, double base, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_log10(   oarrm1n1_t* arr);
  void    oarrm1n1_log10_to(oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_log(     oarrm1n1_t* arr);
  void    oarrm1n1_log_to(  oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_exp(     oarrm1n1_t* arr);
  void    oarrm1n1_exp_to(  oarrm1n1_t* arr, oarrm1n1_t* res);
  oarrm1n1_t oarrm1n1_pow(     oarrm1n1_t* arr, double e);
  void    oarrm1n1_pow_to(  oarrm1n1_t* arr, double e, oarrm1n1_t* res);
  
  
  # From ../../../include/oti/static/onumm1n1/array/gauss/utils.h
  
  void feoarrm1n1_dimCheck_FF_samesize(feoarrm1n1_t* arr1, feoarrm1n1_t* arr2, feonumm1n1_t* res);
  void feoarrm1n1_dimCheck_OF_samesize(  oarrm1n1_t* arr1, feoarrm1n1_t* arr2, feonumm1n1_t* res);
  void feoarrm1n1_dimCheck_RF_samesize(   darr_t* arr1, feoarrm1n1_t* arr2, feonumm1n1_t* res);
  void feoarrm1n1_dimCheck_FF_elementwise(feoarrm1n1_t* arr1, feoarrm1n1_t* arr2, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_OF_elementwise(  oarrm1n1_t* arr1, feoarrm1n1_t* arr2, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm1n1_t* arr2, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_fF_elementwise( feonumm1n1_t* num1, feoarrm1n1_t* arr2, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_Ff_elementwise(feoarrm1n1_t* arr1,  feonumm1n1_t* num2, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_FF_matmul( feoarrm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_OF_matmul(   oarrm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_FO_matmul( feoarrm1n1_t* lhs,   oarrm1n1_t* rhs, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_FR_matmul( feoarrm1n1_t* lhs,    darr_t* rhs, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_F_squareness( feoarrm1n1_t* arr1, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_F_transpose( feoarrm1n1_t* arr1, feoarrm1n1_t* res);
  void feoarrm1n1_dimCheck_FfO_integrate(feoarrm1n1_t* arr, feonumm1n1_t* num,oarrm1n1_t* res);
  void feoarrm1n1_get_active_bases(feoarrm1n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n1/array/gauss/algebra.h
  
  feoarrm1n1_t feoarrm1n1_neg(    feoarrm1n1_t* arr);
  void      feoarrm1n1_neg_to( feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sum_FF(   feoarrm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sum_FF_to(feoarrm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sum_fF(    feonumm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sum_fF_to( feonumm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sum_OF(     oarrm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sum_OF_to(  oarrm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sum_RF(      darr_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sum_RF_to(   darr_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sum_oF(   onumm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sum_oF_to(onumm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sum_rF(     coeff_t  lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sum_rF_to(  coeff_t  lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sub_FF(    feoarrm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sub_FF_to( feoarrm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sub_fF(    feonumm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sub_fF_to( feonumm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sub_Ff(    feoarrm1n1_t* lhs, feonumm1n1_t* rhs);
  void      feoarrm1n1_sub_Ff_to( feoarrm1n1_t* lhs, feonumm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sub_OF(      oarrm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sub_OF_to(   oarrm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sub_FO(    feoarrm1n1_t* lhs,   oarrm1n1_t* rhs);
  void      feoarrm1n1_sub_FO_to( feoarrm1n1_t* lhs,   oarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sub_RF(       darr_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sub_RF_to(    darr_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sub_FR(    feoarrm1n1_t* lhs,    darr_t* rhs);
  void      feoarrm1n1_sub_FR_to( feoarrm1n1_t* lhs,    darr_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sub_oF(    onumm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sub_oF_to( onumm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sub_Fo(    feoarrm1n1_t* lhs, onumm1n1_t* rhs);
  void      feoarrm1n1_sub_Fo_to( feoarrm1n1_t* lhs, onumm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sub_rF(      coeff_t  lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_sub_rF_to(    coeff_t lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sub_Fr(    feoarrm1n1_t* lhs,   coeff_t  rhs);
  void      feoarrm1n1_sub_Fr_to( feoarrm1n1_t* lhs,   coeff_t  rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_mul_FF(   feoarrm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_mul_FF_to(feoarrm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_mul_fF(    feonumm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_mul_fF_to( feonumm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_mul_OF(     oarrm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_mul_OF_to(  oarrm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_mul_RF(      darr_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_mul_RF_to(   darr_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_mul_oF(   onumm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_mul_oF_to(onumm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_mul_rF(     coeff_t  lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_mul_rF_to(  coeff_t  lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_div_FF(    feoarrm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_div_FF_to( feoarrm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_div_fF(     feonumm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_div_fF_to(  feonumm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_div_Ff(    feoarrm1n1_t* lhs,  feonumm1n1_t* rhs);
  void      feoarrm1n1_div_Ff_to( feoarrm1n1_t* lhs,  feonumm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_div_OF(      oarrm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_div_OF_to(   oarrm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_div_FO(    feoarrm1n1_t* lhs,   oarrm1n1_t* rhs);
  void      feoarrm1n1_div_FO_to( feoarrm1n1_t* lhs,   oarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_div_RF(       darr_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_div_RF_to(    darr_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_div_FR(    feoarrm1n1_t* lhs,    darr_t* rhs);
  void      feoarrm1n1_div_FR_to( feoarrm1n1_t* lhs,    darr_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_div_oF(    onumm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_div_oF_to( onumm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_div_Fo(    feoarrm1n1_t* lhs, onumm1n1_t* rhs);
  void      feoarrm1n1_div_Fo_to( feoarrm1n1_t* lhs, onumm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_div_rF(      coeff_t  lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_div_rF_to(    coeff_t lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_div_Fr(    feoarrm1n1_t* lhs,   coeff_t  rhs);
  void      feoarrm1n1_div_Fr_to( feoarrm1n1_t* lhs,   coeff_t  rhs, feoarrm1n1_t* res);
  oarrm1n1_t feoarrm1n1_integrate(    feoarrm1n1_t* arr, feonumm1n1_t* w);
  void    feoarrm1n1_integrate_to( feoarrm1n1_t* arr, feonumm1n1_t* w, oarrm1n1_t* res);
  feonumm1n1_t feoarrm1n1_dotproduct_FF(    feoarrm1n1_t* lhs, feoarrm1n1_t* rhs);
  void     feoarrm1n1_dotproduct_FF_to( feoarrm1n1_t* lhs, feoarrm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feoarrm1n1_dotproduct_OF(      oarrm1n1_t* lhs, feoarrm1n1_t* rhs);
  void     feoarrm1n1_dotproduct_OF_to(   oarrm1n1_t* lhs, feoarrm1n1_t* rhs, feonumm1n1_t* res);
  feonumm1n1_t feoarrm1n1_dotproduct_RF(       darr_t* lhs, feoarrm1n1_t* rhs);
  void     feoarrm1n1_dotproduct_RF_to(    darr_t* lhs, feoarrm1n1_t* rhs, feonumm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_matmul_FF(    feoarrm1n1_t* lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_matmul_FF_to( feoarrm1n1_t* lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_matmul_OF(    oarrm1n1_t*   lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_matmul_OF_to( oarrm1n1_t*   lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_matmul_FO(    feoarrm1n1_t* lhs, oarrm1n1_t*   rhs);
  void      feoarrm1n1_matmul_FO_to( feoarrm1n1_t* lhs, oarrm1n1_t*   rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_matmul_RF(    darr_t*    lhs, feoarrm1n1_t* rhs);
  void      feoarrm1n1_matmul_RF_to( darr_t*    lhs, feoarrm1n1_t* rhs, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_matmul_FR(    feoarrm1n1_t* lhs, darr_t*    rhs);
  void      feoarrm1n1_matmul_FR_to( feoarrm1n1_t* lhs, darr_t*    rhs, feoarrm1n1_t* res);
  feonumm1n1_t feoarrm1n1_det(   feoarrm1n1_t* arr);
  void     feoarrm1n1_det_to(feoarrm1n1_t* arr, feonumm1n1_t* res);
  feonumm1n1_t feoarrm1n1_norm(     feoarrm1n1_t* arr);
  void     feoarrm1n1_norm_to(  feoarrm1n1_t* arr, feonumm1n1_t* res);
  feonumm1n1_t feoarrm1n1_pnorm(    feoarrm1n1_t* arr, coeff_t p);
  void     feoarrm1n1_pnorm_to( feoarrm1n1_t* arr, coeff_t p, feonumm1n1_t* res);
  feoarrm1n1_t   feoarrm1n1_invert(    feoarrm1n1_t* arr);
  void        feoarrm1n1_invert_to( feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t   feoarrm1n1_transpose(   feoarrm1n1_t* arr);
  void        feoarrm1n1_transpose_to(feoarrm1n1_t* arr, feoarrm1n1_t* res);
  
  
  # From ../../../include/oti/static/onumm1n1/array/gauss/base.h
  
  void      feoarrm1n1_get_order_im_to( ord_t order, feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_get_order_im(    ord_t order, feoarrm1n1_t* arr);
  feoarrm1n1_t feoarrm1n1_get_deriv(   imdir_t idx, ord_t order, feoarrm1n1_t* arr);
  void      feoarrm1n1_get_deriv_to(imdir_t idx, ord_t order, feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_get_im(      imdir_t idx, ord_t order, feoarrm1n1_t* arr);
  void      feoarrm1n1_get_im_to(   imdir_t idx, ord_t order, feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_truncate_im(   imdir_t idx, ord_t order, feoarrm1n1_t* arr);
  void      feoarrm1n1_truncate_im_to(imdir_t idx, ord_t order, feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_copy(   feoarrm1n1_t* src);
  void      feoarrm1n1_copy_to(feoarrm1n1_t* src, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_get_im(    imdir_t idx, ord_t order, feoarrm1n1_t* arr);
  void      feoarrm1n1_get_im_to( imdir_t idx, ord_t order, feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_get_deriv(    imdir_t idx, ord_t order, feoarrm1n1_t* arr);
  void      feoarrm1n1_get_deriv_to( imdir_t idx, ord_t order, feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_extract_im(    imdir_t idx, ord_t order, feoarrm1n1_t* arr);
  void      feoarrm1n1_extract_im_to( imdir_t idx, ord_t order, feoarrm1n1_t* arr,  feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_extract_deriv(    imdir_t idx, ord_t order, feoarrm1n1_t* arr);
  void      feoarrm1n1_extract_deriv_to( imdir_t idx, ord_t order, feoarrm1n1_t* arr, feoarrm1n1_t* res);
  oarrm1n1_t   feoarrm1n1_get_item_k(  feoarrm1n1_t* arr, uint64_t k);
  feonumm1n1_t  feoarrm1n1_get_item_ij( feoarrm1n1_t* arr, uint64_t i, uint64_t j);
  onumm1n1_t feoarrm1n1_get_item_ijk(feoarrm1n1_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm1n1_get_item_ij_to(  feoarrm1n1_t* arr, uint64_t i, uint64_t j,
                                 feonumm1n1_t* res);
  void feoarrm1n1_get_item_k_to(   feoarrm1n1_t* arr, uint64_t k,
                                  oarrm1n1_t* res);
  void feoarrm1n1_get_item_ijk_to( feoarrm1n1_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_get_slice(feoarrm1n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm1n1_get_slice_to(feoarrm1n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n1_t* res);
  void feoarrm1n1_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm1n1_t* res);
  void feoarrm1n1_set_item_ij_o(  onumm1n1_t* elm, uint64_t i, uint64_t j,
                               feoarrm1n1_t* res);
  void feoarrm1n1_set_item_ij_f(  feonumm1n1_t* elm, uint64_t i, uint64_t j,
                              feoarrm1n1_t* res);
  void feoarrm1n1_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm1n1_t* res);
  void feoarrm1n1_set_item_k_o(  onumm1n1_t* elm, uint64_t k,
                              feoarrm1n1_t* res);
  void feoarrm1n1_set_item_k_R(    oarrm1n1_t* elm, uint64_t k,
                            feoarrm1n1_t* res);
  void feoarrm1n1_set_item_k_O(    oarrm1n1_t* elm, uint64_t k,
                            feoarrm1n1_t* res);
  void feoarrm1n1_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm1n1_t* res);
  void feoarrm1n1_set_item_ijk_o( onumm1n1_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm1n1_t* res);
  void feoarrm1n1_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n1_t* res);
  void feoarrm1n1_set_slice_o( onumm1n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n1_t* res);
  void feoarrm1n1_set_slice_f( feonumm1n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n1_t* res);
  void feoarrm1n1_set_slice_O( oarrm1n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n1_t* res);
  void feoarrm1n1_set_slice_F( feoarrm1n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n1_t* res);
  void feoarrm1n1_set_all_o( onumm1n1_t* num, feoarrm1n1_t* arr );
  void feoarrm1n1_set_all_r(   coeff_t  num, feoarrm1n1_t* arr );
  void feoarrm1n1_set_all_f(  feonumm1n1_t* num, feoarrm1n1_t* arr );
  void feoarrm1n1_set_r(    coeff_t src, feoarrm1n1_t* res );
  void feoarrm1n1_set_o( onumm1n1_t* src, feoarrm1n1_t* res );
  void feoarrm1n1_set_f(  feonumm1n1_t* src, feoarrm1n1_t* res );
  void feoarrm1n1_set_R(    darr_t* src, feoarrm1n1_t* res );
  void feoarrm1n1_set_O(   oarrm1n1_t* src, feoarrm1n1_t* res );
  void feoarrm1n1_set_F( feoarrm1n1_t* src, feoarrm1n1_t* res );
  feoarrm1n1_t feoarrm1n1_eye( uint64_t size,  uint64_t nip);
  feoarrm1n1_t feoarrm1n1_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm1n1_t feoarrm1n1_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm1n1_t feoarrm1n1_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm1n1_free(feoarrm1n1_t* arr);
  feoarrm1n1_t feoarrm1n1_init();
  ord_t feoarrm1n1_get_order(feoarrm1n1_t* arr);
  
  
  # From ../../../include/oti/static/onumm1n1/array/gauss/functions.h
  
  feoarrm1n1_t feoarrm1n1_atanh(    feoarrm1n1_t* arr);
  void      feoarrm1n1_atanh_to( feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_asinh(    feoarrm1n1_t* arr);
  void      feoarrm1n1_asinh_to( feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_acosh(    feoarrm1n1_t* arr);
  void      feoarrm1n1_acosh_to( feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_tanh(     feoarrm1n1_t* arr);
  void      feoarrm1n1_tanh_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sinh(     feoarrm1n1_t* arr);
  void      feoarrm1n1_sinh_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_cosh(     feoarrm1n1_t* arr);
  void      feoarrm1n1_cosh_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_atan(     feoarrm1n1_t* arr);
  void      feoarrm1n1_atan_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_asin(     feoarrm1n1_t* arr);
  void      feoarrm1n1_asin_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_acos(     feoarrm1n1_t* arr);
  void      feoarrm1n1_acos_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_tan(      feoarrm1n1_t* arr);
  void      feoarrm1n1_tan_to(   feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sin(      feoarrm1n1_t* arr);
  void      feoarrm1n1_sin_to(   feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_cos(      feoarrm1n1_t* arr);
  void      feoarrm1n1_cos_to(   feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_logb(     feoarrm1n1_t* arr, double base);
  void      feoarrm1n1_logb_to(  feoarrm1n1_t* arr, double base, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_log10(    feoarrm1n1_t* arr);
  void      feoarrm1n1_log10_to( feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_log(      feoarrm1n1_t* arr);
  void      feoarrm1n1_log_to(   feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_exp(      feoarrm1n1_t* arr);
  void      feoarrm1n1_exp_to(   feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_cbrt(     feoarrm1n1_t* arr);
  void      feoarrm1n1_cbrt_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_sqrt(     feoarrm1n1_t* arr);
  void      feoarrm1n1_sqrt_to(  feoarrm1n1_t* arr, feoarrm1n1_t* res);
  feoarrm1n1_t feoarrm1n1_pow(      feoarrm1n1_t* arr, double e);
  void      feoarrm1n1_pow_to(   feoarrm1n1_t* arr, double e, feoarrm1n1_t* res);
  
  