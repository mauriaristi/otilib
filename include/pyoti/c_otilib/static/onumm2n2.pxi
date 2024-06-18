cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm2n2/scalar/structures.h
  
  ctypedef struct  onumm2n2_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e11;
    coeff_t e12;
    coeff_t e22;
  # } onumm2n2_t;
  
  
  # From ../../../include/oti/static/onumm2n2/array/structures.h
  
  ctypedef struct  oarrm2n2_t : # {
      onumm2n2_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm2n2_t;
  
  
  # From ../../../include/oti/static/onumm2n2/scalar/gauss/structures.h
  
  ctypedef struct  feonumm2n2_t: # {
      onumm2n2_t*  p_data;
      uint64_t    nip;
  # } feonumm2n2_t;
  
  
  # From ../../../include/oti/static/onumm2n2/array/gauss/structures.h
  
  ctypedef struct  feoarrm2n2_t: # {
      oarrm2n2_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm2n2_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm2n2/scalar/utils.h
  
  void onumm2n2_get_active_bases(onumm2n2_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm2n2/scalar/algebra.h
  
  onumm2n2_t onumm2n2_abs(onumm2n2_t* num);
  onumm2n2_t onumm2n2_div_ro(coeff_t num, onumm2n2_t* den);
  onumm2n2_t onumm2n2_div_oo(onumm2n2_t* num, onumm2n2_t* den);
  onumm2n2_t onumm2n2_div_or(onumm2n2_t* num, coeff_t val);
  void onumm2n2_div_ro_to(coeff_t num, onumm2n2_t* den, onumm2n2_t* res);
  void onumm2n2_div_oo_to(onumm2n2_t* num, onumm2n2_t* den, onumm2n2_t* res);
  void onumm2n2_div_or_to(onumm2n2_t* num, coeff_t val, onumm2n2_t* res);
  void onumm2n2_abs_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_neg(  onumm2n2_t* lhs);
  void onumm2n2_neg_to(  onumm2n2_t* lhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_sum_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
  void onumm2n2_sum_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_sum_ro(  coeff_t lhs,  onumm2n2_t* rhs);
  void onumm2n2_sum_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_sub_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
  void onumm2n2_sub_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_sub_ro(  coeff_t lhs,  onumm2n2_t* rhs);
  void onumm2n2_sub_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_sub_or(  onumm2n2_t* lhs,  coeff_t rhs);
  void onumm2n2_sub_or_to(  onumm2n2_t* lhs,  coeff_t rhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_mul_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
  void onumm2n2_mul_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_mul_ro(  coeff_t lhs,  onumm2n2_t* rhs);
  void onumm2n2_mul_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_trunc_mul_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
  void onumm2n2_trunc_mul_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_gem_oo(  onumm2n2_t* a,  onumm2n2_t* b,  onumm2n2_t* c);
  void onumm2n2_gem_oo_to(  onumm2n2_t* a,  onumm2n2_t* b,  onumm2n2_t* c, onumm2n2_t* res);
  onumm2n2_t onumm2n2_gem_ro(  coeff_t a,  onumm2n2_t* b,  onumm2n2_t* c);
  void onumm2n2_gem_ro_to(  coeff_t a,  onumm2n2_t* b,  onumm2n2_t* c, onumm2n2_t* res);
  void onumm2n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n2_t* a,  ord_t ord_rhs,  onumm2n2_t* b,  onumm2n2_t* c, onumm2n2_t* res);
  void onumm2n2_trunc_sum_oo_to(ord_t order, onumm2n2_t* lhs,onumm2n2_t* rhs, onumm2n2_t* res);
  void onumm2n2_trunc_sub_oo_to(ord_t order, onumm2n2_t* lhs,onumm2n2_t* rhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_feval(coeff_t* feval_re, onumm2n2_t* x);
  void onumm2n2_feval_to(coeff_t* feval_re, onumm2n2_t* x, onumm2n2_t* res);
  
  
  # From ../../../include/oti/static/onumm2n2/scalar/base.h
  
  void onumm2n2_set_im_o(onumm2n2_t* num, imdir_t idx, ord_t order, onumm2n2_t* res);
  void onumm2n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm2n2_t* res);
  void onumm2n2_set_deriv_o(onumm2n2_t* num, imdir_t idx, ord_t order, onumm2n2_t* res);
  void onumm2n2_extract_im_to( imdir_t idx, ord_t order, onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_extract_im(imdir_t idx, ord_t order, onumm2n2_t* num);
  onumm2n2_t onumm2n2_extract_deriv(imdir_t idx, ord_t order, onumm2n2_t* num);
  void onumm2n2_extract_deriv_to(imdir_t idx, ord_t order, onumm2n2_t* num, onumm2n2_t* res);
  void onumm2n2_get_im_to_o(imdir_t idx, ord_t order, onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_get_im_o(imdir_t idx, ord_t order, onumm2n2_t* num);
  void onumm2n2_get_im_to_r(imdir_t idx, ord_t order, onumm2n2_t* num, coeff_t* res);
  ord_t onumm2n2_get_order(onumm2n2_t* lhs);
  onumm2n2_t onumm2n2_get_deriv_o( imdir_t idx, ord_t order, onumm2n2_t* num);
  void onumm2n2_get_deriv_to( imdir_t idx, ord_t order, onumm2n2_t* num, onumm2n2_t* res);
  void onumm2n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm2n2_t* res);
  onumm2n2_t onumm2n2_init();
  ndir_t onumm2n2_get_ndir_order(ord_t order, onumm2n2_t* num);
  ndir_t onumm2n2_get_ndir_total(onumm2n2_t* num);
  coeff_t* onumm2n2_get_order_address(ord_t order, onumm2n2_t* num);
  onumm2n2_t onumm2n2_create_r(  coeff_t lhs);
  void onumm2n2_set_r(  coeff_t lhs, onumm2n2_t* res);
  void onumm2n2_set_o(  onumm2n2_t* lhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_get_order_im(ord_t order, onumm2n2_t* lhs);
  void onumm2n2_get_order_im_to(ord_t order, onumm2n2_t* lhs, onumm2n2_t* res);
  coeff_t onumm2n2_get_item(imdir_t idx, ord_t order, onumm2n2_t* lhs);
  coeff_t onumm2n2_get_deriv(imdir_t idx, ord_t order, onumm2n2_t* lhs);
  void onumm2n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm2n2_t* x);
  onumm2n2_t onumm2n2_copy(  onumm2n2_t* lhs);
  void onumm2n2_copy_to(  onumm2n2_t* lhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_taylor_integrate(coeff_t* deltas,onumm2n2_t* lhs);
  void onumm2n2_taylor_integrate_to(coeff_t* deltas,onumm2n2_t* lhs, onumm2n2_t* res);
  onumm2n2_t onumm2n2_truncate_im(imdir_t idx, ord_t order, onumm2n2_t* lhs);
  void onumm2n2_truncate_im_to(imdir_t idx, ord_t order, onumm2n2_t* lhs, onumm2n2_t* res);
  void onumm2n2_print(  onumm2n2_t* lhs);
  imdir_t onumm2n2_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm2n2/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm2n2/scalar/functions.h
  
  onumm2n2_t onumm2n2_atanh(onumm2n2_t* num);
  void onumm2n2_atanh_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_asinh(onumm2n2_t* num);
  void onumm2n2_asinh_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_acosh(onumm2n2_t* num);
  void onumm2n2_acosh_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_tanh(onumm2n2_t* num);
  void onumm2n2_tanh_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_sqrt(onumm2n2_t* num);
  void onumm2n2_sqrt_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_cbrt(onumm2n2_t* num);
  void onumm2n2_cbrt_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_cosh(onumm2n2_t* num);
  void onumm2n2_cosh_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_sinh(onumm2n2_t* num);
  void onumm2n2_sinh_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_asin(onumm2n2_t* num);
  void onumm2n2_asin_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_acos(onumm2n2_t* num);
  void onumm2n2_acos_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_atan(onumm2n2_t* num);
  void onumm2n2_atan_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_tan(onumm2n2_t* num);
  void onumm2n2_tan_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_cos(onumm2n2_t* num);
  void onumm2n2_cos_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_sin(onumm2n2_t* num );
  void onumm2n2_sin_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_logb(onumm2n2_t* num, double base);
  void onumm2n2_logb_to(onumm2n2_t* num, double base, onumm2n2_t* res);
  onumm2n2_t onumm2n2_log10(onumm2n2_t* num);
  void onumm2n2_log10_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_log(onumm2n2_t* num);
  void onumm2n2_log_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_exp(onumm2n2_t* num);
  void onumm2n2_exp_to(onumm2n2_t* num, onumm2n2_t* res);
  onumm2n2_t onumm2n2_pow(onumm2n2_t* num, double e);
  void onumm2n2_pow_to(onumm2n2_t* num, coeff_t e, onumm2n2_t* res);
  
  
  # From ../../../include/oti/static/onumm2n2/scalar/gauss/utils.h
  
  void feonumm2n2_dimCheck(feonumm2n2_t* arr1,feonumm2n2_t* arr2);
  void feonumm2n2_get_active_bases(feonumm2n2_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm2n2/scalar/gauss/algebra.h
  
  feonumm2n2_t feonumm2n2_neg(   feonumm2n2_t* num);
  void     feonumm2n2_neg_to(feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_sum_ff(   feonumm2n2_t* lhs, feonumm2n2_t* rhs);
  void     feonumm2n2_sum_ff_to(feonumm2n2_t* lhs, feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_sum_of(   onumm2n2_t* lhs, feonumm2n2_t* rhs);
  void     feonumm2n2_sum_of_to(onumm2n2_t* lhs, feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_sum_rf(   coeff_t lhs, feonumm2n2_t* rhs);
  void     feonumm2n2_sum_rf_to(coeff_t lhs, feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_sub_ff(     feonumm2n2_t* lhs,  feonumm2n2_t* rhs);
  void     feonumm2n2_sub_ff_to(  feonumm2n2_t* lhs,  feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_sub_of(    onumm2n2_t* lhs,  feonumm2n2_t* rhs);
  void     feonumm2n2_sub_of_to( onumm2n2_t* lhs,  feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_sub_fo(     feonumm2n2_t* lhs, onumm2n2_t* rhs);
  void     feonumm2n2_sub_fo_to(  feonumm2n2_t* lhs, onumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_sub_rf(       coeff_t lhs,  feonumm2n2_t* rhs);
  void     feonumm2n2_sub_rf_to(    coeff_t lhs,  feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_sub_fr(     feonumm2n2_t* lhs,    coeff_t rhs);
  void     feonumm2n2_sub_fr_to(  feonumm2n2_t* lhs,    coeff_t rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_mul_ff(   feonumm2n2_t* lhs, feonumm2n2_t* rhs);
  void     feonumm2n2_mul_ff_to(feonumm2n2_t* lhs, feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_mul_of(   onumm2n2_t* lhs, feonumm2n2_t* rhs);
  void     feonumm2n2_mul_of_to(onumm2n2_t* lhs, feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_mul_rf(   coeff_t lhs, feonumm2n2_t* rhs);
  void     feonumm2n2_mul_rf_to(coeff_t lhs, feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_div_ff(     feonumm2n2_t* lhs,  feonumm2n2_t* rhs);
  void     feonumm2n2_div_ff_to(  feonumm2n2_t* lhs,  feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_div_of(    onumm2n2_t* lhs,  feonumm2n2_t* rhs);
  void     feonumm2n2_div_of_to( onumm2n2_t* lhs,  feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_div_fo(     feonumm2n2_t* lhs, onumm2n2_t* rhs);
  void     feonumm2n2_div_fo_to(  feonumm2n2_t* lhs, onumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_div_rf(       coeff_t lhs,  feonumm2n2_t* rhs);
  void     feonumm2n2_div_rf_to(    coeff_t lhs,  feonumm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_div_fr(     feonumm2n2_t* lhs,    coeff_t rhs);
  void     feonumm2n2_div_fr_to(  feonumm2n2_t* lhs,    coeff_t rhs, feonumm2n2_t* res);
  
  
  # From ../../../include/oti/static/onumm2n2/scalar/gauss/base.h
  
  void     feonumm2n2_get_order_im_to( ord_t order, feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_get_order_im(    ord_t order, feonumm2n2_t* num);
  feonumm2n2_t feonumm2n2_get_im(    imdir_t idx, ord_t order, feonumm2n2_t* num);
  void     feonumm2n2_get_im_to( imdir_t idx, ord_t order, feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_get_deriv(    imdir_t idx, ord_t order, feonumm2n2_t* num);
  void     feonumm2n2_get_deriv_to( imdir_t idx, ord_t order, feonumm2n2_t* num, feonumm2n2_t* res);
  void feonumm2n2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm2n2_t* num);
  void feonumm2n2_set_im_o( onumm2n2_t* val, imdir_t idx, ord_t order, feonumm2n2_t* num);
  void feonumm2n2_set_im_f(  feonumm2n2_t* val, imdir_t idx, ord_t order, feonumm2n2_t* num);
  void feonumm2n2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm2n2_t* num);
  void feonumm2n2_set_deriv_o( onumm2n2_t* val, imdir_t idx, ord_t order, feonumm2n2_t* num);
  void feonumm2n2_set_deriv_f(  feonumm2n2_t* val, imdir_t idx, ord_t order, feonumm2n2_t* num);
  feonumm2n2_t feonumm2n2_extract_im(    imdir_t idx, ord_t order, feonumm2n2_t* num);
  void     feonumm2n2_extract_im_to( imdir_t idx, ord_t order, feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_extract_deriv(    imdir_t idx, ord_t order, feonumm2n2_t* num);
  void     feonumm2n2_extract_deriv_to( imdir_t idx, ord_t order, feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_truncate_im(    imdir_t idx, ord_t order, feonumm2n2_t* num);
  void     feonumm2n2_truncate_im_to( imdir_t idx, ord_t order, feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_copy(    feonumm2n2_t* src);
  void     feonumm2n2_copy_to( feonumm2n2_t* src, feonumm2n2_t* dst);
  void feonumm2n2_set_r(    coeff_t num, feonumm2n2_t* res);
  void feonumm2n2_set_o( onumm2n2_t* num, feonumm2n2_t* res);
  void feonumm2n2_set_f(  feonumm2n2_t* num, feonumm2n2_t* res);
  void feonumm2n2_set_item_k_r(   coeff_t  num, uint64_t k, feonumm2n2_t* res);
  void feonumm2n2_set_item_k_o( onumm2n2_t* num, uint64_t k, feonumm2n2_t* res);
  onumm2n2_t feonumm2n2_get_item_k(   feonumm2n2_t* num, uint64_t k);
  void      feonumm2n2_get_item_k_to(feonumm2n2_t* num, uint64_t k, onumm2n2_t* res);
  feonumm2n2_t feonumm2n2_zeros(uint64_t nIntPts);
  feonumm2n2_t feonumm2n2_createEmpty(uint64_t nIntPts);
  feonumm2n2_t feonumm2n2_empty_like(feonumm2n2_t* arr);
  void feonumm2n2_free(feonumm2n2_t* num);
  ord_t feonumm2n2_get_order( feonumm2n2_t* num );
  feonumm2n2_t feonumm2n2_init();
  
  
  # From ../../../include/oti/static/onumm2n2/scalar/gauss/functions.h
  
  feonumm2n2_t feonumm2n2_atanh(    feonumm2n2_t* num);
  void     feonumm2n2_atanh_to( feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_asinh(    feonumm2n2_t* num);
  void     feonumm2n2_asinh_to( feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_acosh(    feonumm2n2_t* num);
  void     feonumm2n2_acosh_to( feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_tanh(     feonumm2n2_t* num);
  void     feonumm2n2_tanh_to(  feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_cosh(     feonumm2n2_t* num);
  void     feonumm2n2_cosh_to(  feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_sinh(     feonumm2n2_t* num);
  void     feonumm2n2_sinh_to(  feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_asin(     feonumm2n2_t* num);
  void     feonumm2n2_asin_to(  feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_acos(     feonumm2n2_t* num);
  void     feonumm2n2_acos_to(  feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_atan(     feonumm2n2_t* num);
  void     feonumm2n2_atan_to(  feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_tan(      feonumm2n2_t* num);
  void     feonumm2n2_tan_to(   feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_cos(      feonumm2n2_t* num);
  void     feonumm2n2_cos_to(   feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_sin(      feonumm2n2_t* num);
  void     feonumm2n2_sin_to(   feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_logb(     feonumm2n2_t* num, double base);
  void     feonumm2n2_logb_to(  feonumm2n2_t* num, double base, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_log10(    feonumm2n2_t* num);
  void     feonumm2n2_log10_to( feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_log(      feonumm2n2_t* num);
  void     feonumm2n2_log_to(   feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_exp(      feonumm2n2_t* num);
  void     feonumm2n2_exp_to(   feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_cbrt(     feonumm2n2_t* num);
  void     feonumm2n2_cbrt_to(  feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_sqrt(     feonumm2n2_t* num);
  void     feonumm2n2_sqrt_to(  feonumm2n2_t* num, feonumm2n2_t* res);
  feonumm2n2_t feonumm2n2_pow(      feonumm2n2_t* num, double e);
  void     feonumm2n2_pow_to(   feonumm2n2_t* num, double e, feonumm2n2_t* res);
  onumm2n2_t feonumm2n2_integrate(       feonumm2n2_t* num, feonumm2n2_t* w);
  void      feonumm2n2_integrate_to(    feonumm2n2_t* num, feonumm2n2_t* w, onumm2n2_t* res);
  onumm2n2_t feonumm2n2_integrate_f(     feonumm2n2_t* num, feonumm2n2_t* w);
  void      feonumm2n2_integrate_f_to(  feonumm2n2_t* num, feonumm2n2_t* w, onumm2n2_t* res);
  onumm2n2_t feonumm2n2_integrate_r(       coeff_t num, feonumm2n2_t* w);
  void      feonumm2n2_integrate_r_to(    coeff_t num, feonumm2n2_t* w, onumm2n2_t* res);
  onumm2n2_t feonumm2n2_integrate_o(    onumm2n2_t* num, feonumm2n2_t* w);
  void      feonumm2n2_integrate_o_to( onumm2n2_t* num, feonumm2n2_t* w, onumm2n2_t* res);
  
  
  # From ../../../include/oti/static/onumm2n2/array/utils.h
  
  void oarrm2n2_dimCheck_OO_elementwise(oarrm2n2_t* arr1, oarrm2n2_t* arr2, oarrm2n2_t* res);
  void oarrm2n2_dimCheck_RO_elementwise(darr_t*  arr1, oarrm2n2_t* arr2, oarrm2n2_t* res);
  void oarrm2n2_dimCheck_OO_matmul(oarrm2n2_t* arr1, oarrm2n2_t* arr2, oarrm2n2_t* res);
  void oarrm2n2_dimCheck_RO_matmul(darr_t*  arr1, oarrm2n2_t* arr2, oarrm2n2_t* res);
  void oarrm2n2_dimCheck_OR_matmul(oarrm2n2_t* arr1, darr_t*  arr2, oarrm2n2_t* res);
  void oarrm2n2_dimCheck_O_squareness(oarrm2n2_t* arr1, oarrm2n2_t* res);
  void oarrm2n2_dimCheck_OO_samesize(oarrm2n2_t* arr1, oarrm2n2_t* res);
  void oarrm2n2_dimCheck_RO_samesize(darr_t* arr1, oarrm2n2_t* res);
  ord_t oarrm2n2_get_order(oarrm2n2_t* arr);
  void oarrm2n2_get_active_bases(oarrm2n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm2n2/array/algebra_elementwise.h
  
  oarrm2n2_t oarrm2n2_neg(oarrm2n2_t* arr);
  void oarrm2n2_neg_to(oarrm2n2_t* rhs, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_sum_OO(oarrm2n2_t*   lhs, oarrm2n2_t* rhs);
  oarrm2n2_t oarrm2n2_sum_RO(darr_t*    lhs, oarrm2n2_t* rhs);
  oarrm2n2_t oarrm2n2_sum_oO(onumm2n2_t* lhs, oarrm2n2_t* rhs);
  oarrm2n2_t oarrm2n2_sum_rO(coeff_t    lhs, oarrm2n2_t* rhs);
  void oarrm2n2_sum_OO_to(oarrm2n2_t*   lhs, oarrm2n2_t* rhs, oarrm2n2_t* res);
  void oarrm2n2_sum_RO_to(darr_t*    lhs, oarrm2n2_t* rhs, oarrm2n2_t* res);
  void oarrm2n2_sum_oO_to(onumm2n2_t* lhs, oarrm2n2_t* rhs, oarrm2n2_t* res);
  void oarrm2n2_sum_rO_to(coeff_t    lhs, oarrm2n2_t* rhs, oarrm2n2_t* res);
  void oarrm2n2_trunc_sum_OO_to(ord_t order, oarrm2n2_t* arr1, oarrm2n2_t* arr2, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_sub_OO(oarrm2n2_t*   lhs, oarrm2n2_t*   rhs);
  oarrm2n2_t oarrm2n2_sub_RO(darr_t*    lhs, oarrm2n2_t*   rhs);
  oarrm2n2_t oarrm2n2_sub_OR(oarrm2n2_t*   lhs, darr_t*    rhs);
  oarrm2n2_t oarrm2n2_sub_oO(onumm2n2_t* lhs, oarrm2n2_t*   rhs);
  oarrm2n2_t oarrm2n2_sub_Oo(oarrm2n2_t*   lhs, onumm2n2_t* rhs);
  oarrm2n2_t oarrm2n2_sub_rO(coeff_t    lhs, oarrm2n2_t*   rhs);
  oarrm2n2_t oarrm2n2_sub_Or(oarrm2n2_t*   lhs, coeff_t    rhs);
  void oarrm2n2_sub_OO_to( oarrm2n2_t*   lhs, oarrm2n2_t*   rhs, oarrm2n2_t* res);
  void oarrm2n2_sub_RO_to( darr_t*    lhs, oarrm2n2_t*   rhs, oarrm2n2_t* res);
  void oarrm2n2_sub_OR_to( oarrm2n2_t*   lhs, darr_t*    rhs, oarrm2n2_t* res);
  void oarrm2n2_sub_oO_to( onumm2n2_t* lhs, oarrm2n2_t*   rhs, oarrm2n2_t* res);
  void oarrm2n2_sub_Oo_to( oarrm2n2_t*   lhs, onumm2n2_t* rhs, oarrm2n2_t* res);
  void oarrm2n2_sub_rO_to( coeff_t    lhs, oarrm2n2_t*   rhs, oarrm2n2_t* res);
  void oarrm2n2_sub_Or_to( oarrm2n2_t*   lhs, coeff_t    rhs, oarrm2n2_t* res);
  void oarrm2n2_trunc_sub_OO_to(ord_t order, oarrm2n2_t* arr1, oarrm2n2_t* arr2, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_mul_OO(oarrm2n2_t*   lhs, oarrm2n2_t* rhs);
  oarrm2n2_t oarrm2n2_mul_RO(darr_t*    lhs, oarrm2n2_t* rhs);
  oarrm2n2_t oarrm2n2_mul_oO(onumm2n2_t* lhs, oarrm2n2_t* rhs);
  oarrm2n2_t oarrm2n2_mul_rO(coeff_t    lhs, oarrm2n2_t* rhs);
  void oarrm2n2_mul_OO_to(oarrm2n2_t*   lhs, oarrm2n2_t* rhs, oarrm2n2_t* res);
  void oarrm2n2_mul_RO_to(darr_t*    lhs, oarrm2n2_t* rhs, oarrm2n2_t* res);
  void oarrm2n2_mul_oO_to(onumm2n2_t* lhs, oarrm2n2_t* rhs, oarrm2n2_t* res);
  void oarrm2n2_mul_rO_to(coeff_t    lhs, oarrm2n2_t* rhs, oarrm2n2_t* res);
  void oarrm2n2_gem_OO_to(  oarrm2n2_t* arr1, oarrm2n2_t* arr2, oarrm2n2_t* arr3, oarrm2n2_t* res);
  void oarrm2n2_gem_oO_to(onumm2n2_t* arr1, oarrm2n2_t* arr2, oarrm2n2_t* arr3, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_div_OO(oarrm2n2_t*   lhs, oarrm2n2_t*   rhs);
  oarrm2n2_t oarrm2n2_div_OR(oarrm2n2_t*   lhs, darr_t*    rhs);
  oarrm2n2_t oarrm2n2_div_RO(darr_t*    lhs, oarrm2n2_t*   rhs);
  oarrm2n2_t oarrm2n2_div_oO(onumm2n2_t* lhs, oarrm2n2_t*   rhs);
  oarrm2n2_t oarrm2n2_div_Oo(oarrm2n2_t*   lhs, onumm2n2_t* rhs);
  oarrm2n2_t oarrm2n2_div_rO(coeff_t    lhs, oarrm2n2_t*   rhs);
  oarrm2n2_t oarrm2n2_div_Or(oarrm2n2_t*   lhs, coeff_t    rhs);
  void oarrm2n2_div_OO_to(oarrm2n2_t*   lhs, oarrm2n2_t*   rhs, oarrm2n2_t* res);
  void oarrm2n2_div_RO_to(darr_t*    lhs, oarrm2n2_t*   rhs, oarrm2n2_t* res);
  void oarrm2n2_div_OR_to(oarrm2n2_t*   lhs, darr_t*    rhs, oarrm2n2_t* res);
  void oarrm2n2_div_oO_to(onumm2n2_t* lhs, oarrm2n2_t*   rhs, oarrm2n2_t* res);
  void oarrm2n2_div_Oo_to(oarrm2n2_t*   lhs, onumm2n2_t* rhs, oarrm2n2_t* res);
  void oarrm2n2_div_rO_to(coeff_t    lhs, oarrm2n2_t*   rhs, oarrm2n2_t* res);
  void oarrm2n2_div_Or_to(oarrm2n2_t*   lhs, coeff_t    rhs, oarrm2n2_t* res);
  
  
  # From ../../../include/oti/static/onumm2n2/array/base.h
  
  void    oarrm2n2_taylor_integrate_to( coeff_t* deltas, oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_taylor_integrate(    coeff_t* deltas, oarrm2n2_t* arr);
  void    oarrm2n2_get_order_im_to( ord_t order, oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_get_order_im(    ord_t order, oarrm2n2_t* arr);
  void oarrm2n2_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n2_t* res);
  void oarrm2n2_set_slice_O( oarrm2n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n2_t* res);
  void oarrm2n2_set_slice_o( onumm2n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_get_slice( oarrm2n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm2n2_get_slice_to( oarrm2n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_truncate_im(    imdir_t idx, ord_t order, oarrm2n2_t* arr);
  void    oarrm2n2_truncate_im_to( imdir_t idx, ord_t order, oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_extract_im(   imdir_t idx, ord_t order, oarrm2n2_t* arr);
  void    oarrm2n2_extract_im_to(imdir_t idx, ord_t order, oarrm2n2_t* arr, oarrm2n2_t* res);
  darr_t  oarrm2n2_get_deriv(    imdir_t idx, ord_t order, oarrm2n2_t* arr);
  void    oarrm2n2_get_deriv_to( imdir_t idx, ord_t order, oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_get_deriv_o(  imdir_t idx, ord_t order, oarrm2n2_t* arr);
  oarrm2n2_t oarrm2n2_extract_deriv(    imdir_t idx, ord_t order, oarrm2n2_t* arr);
  void    oarrm2n2_extract_deriv_to( imdir_t idx, ord_t order, oarrm2n2_t* arr, oarrm2n2_t* res);
  darr_t  oarrm2n2_get_im(   imdir_t idx, ord_t order, oarrm2n2_t* arr);
  oarrm2n2_t oarrm2n2_get_im_o( imdir_t idx, ord_t order, oarrm2n2_t* arr);
  void    oarrm2n2_get_im_to(imdir_t idx, ord_t order, oarrm2n2_t* arr, oarrm2n2_t* res);
  void    oarrm2n2_copy_to(oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_copy(oarrm2n2_t* arr);
  void oarrm2n2_set_all_r( coeff_t num, oarrm2n2_t* arr);
  void oarrm2n2_set_item_i_r( coeff_t num, uint64_t i, oarrm2n2_t* arr);
  void oarrm2n2_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm2n2_t* arr);
  void oarrm2n2_set_r(   coeff_t  num,   oarrm2n2_t* arr);
  void oarrm2n2_set_o( onumm2n2_t* num,   oarrm2n2_t* arr);
  void oarrm2n2_set_O(   oarrm2n2_t* arrin, oarrm2n2_t* arr);
  void oarrm2n2_set_all_o( onumm2n2_t* src, oarrm2n2_t* arr);
  void oarrm2n2_set_item_i_o( onumm2n2_t* num, uint64_t i, oarrm2n2_t* arr);
  void oarrm2n2_set_item_ij_o( onumm2n2_t* num, uint64_t i, uint64_t j, oarrm2n2_t* arr);
  onumm2n2_t oarrm2n2_get_item_i(    oarrm2n2_t* arr, uint64_t i);
  void      oarrm2n2_get_item_i_to( oarrm2n2_t* arr, uint64_t i,             onumm2n2_t* res);
  onumm2n2_t oarrm2n2_get_item_ij(   oarrm2n2_t* arr, uint64_t i, uint64_t j);
  void      oarrm2n2_get_item_ij_to(oarrm2n2_t* arr, uint64_t i, uint64_t j, onumm2n2_t* res);
  oarrm2n2_t oarrm2n2_init();
  void oarrm2n2_free(oarrm2n2_t* arr);
  oarrm2n2_t oarrm2n2_empty_like(oarrm2n2_t* arr);
  oarrm2n2_t oarrm2n2_eye(uint64_t nrows);
  oarrm2n2_t oarrm2n2_ones(uint64_t nrows, uint64_t ncols);
  oarrm2n2_t oarrm2n2_zeros(uint64_t nrows, uint64_t ncols);
  oarrm2n2_t oarrm2n2_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm2n2/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm2n2/array/algebra_matops.h
  
  onumm2n2_t oarrm2n2_dotproduct_OO(    oarrm2n2_t* lhs, oarrm2n2_t* rhs);
  void      oarrm2n2_dotproduct_OO_to( oarrm2n2_t* lhs, oarrm2n2_t* rhs, onumm2n2_t* res);
  onumm2n2_t oarrm2n2_dotproduct_RO(     darr_t* lhs, oarrm2n2_t* rhs);
  void      oarrm2n2_dotproduct_RO_to(  darr_t* lhs, oarrm2n2_t* rhs, onumm2n2_t* res);
  oarrm2n2_t oarrm2n2_matmul_OO(    oarrm2n2_t* lhs, oarrm2n2_t* rhs);
  oarrm2n2_t oarrm2n2_matmul_OR(    oarrm2n2_t* lhs,  darr_t* rhs);
  oarrm2n2_t oarrm2n2_matmul_RO(     darr_t* lhs, oarrm2n2_t* rhs);
  void    oarrm2n2_matmul_OO_to( oarrm2n2_t* lhs, oarrm2n2_t* rhs, oarrm2n2_t* res);
  void    oarrm2n2_matmul_OR_to( oarrm2n2_t* lhs,  darr_t* rhs, oarrm2n2_t* res);
  void    oarrm2n2_matmul_RO_to(  darr_t* lhs, oarrm2n2_t* rhs, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_transpose(    oarrm2n2_t* arr1);
  void    oarrm2n2_transpose_to( oarrm2n2_t* arr1, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_invert(    oarrm2n2_t* arr1);
  void    oarrm2n2_invert_to( oarrm2n2_t* arr1, oarrm2n2_t* res);
  onumm2n2_t oarrm2n2_det(    oarrm2n2_t* arr1);
  void      oarrm2n2_det_to( oarrm2n2_t* arr1, onumm2n2_t* res);
  onumm2n2_t oarrm2n2_norm(    oarrm2n2_t* arr1);
  void      oarrm2n2_norm_to( oarrm2n2_t* arr1,  onumm2n2_t* res);
  onumm2n2_t oarrm2n2_pnorm(    oarrm2n2_t* arr1, coeff_t p);
  void      oarrm2n2_pnorm_to( oarrm2n2_t* arr1, coeff_t p, onumm2n2_t* res);
  
  
  # From ../../../include/oti/static/onumm2n2/array/functions.h
  
  oarrm2n2_t oarrm2n2_atanh(   oarrm2n2_t* arr);
  void    oarrm2n2_atanh_to(oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_asinh(   oarrm2n2_t* arr);
  void    oarrm2n2_asinh_to(oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_acosh(   oarrm2n2_t* arr);
  void    oarrm2n2_acosh_to(oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_tanh(    oarrm2n2_t* arr);
  void    oarrm2n2_tanh_to( oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_cbrt(    oarrm2n2_t* arr);
  void    oarrm2n2_cbrt_to( oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_sqrt(    oarrm2n2_t* arr);
  void    oarrm2n2_sqrt_to( oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_cosh(    oarrm2n2_t* arr);
  void    oarrm2n2_cosh_to( oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_sinh(    oarrm2n2_t* arr);
  void    oarrm2n2_sinh_to( oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_asin(    oarrm2n2_t* arr);
  void    oarrm2n2_asin_to( oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_acos(    oarrm2n2_t* arr);
  void    oarrm2n2_acos_to( oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_atan(    oarrm2n2_t* arr);
  void    oarrm2n2_atan_to( oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_tan(     oarrm2n2_t* arr);
  void    oarrm2n2_tan_to(  oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_cos(     oarrm2n2_t* arr);
  void    oarrm2n2_cos_to(  oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_sin(     oarrm2n2_t* arr);
  void    oarrm2n2_sin_to(  oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_logb(    oarrm2n2_t* arr, double base);
  void    oarrm2n2_logb_to( oarrm2n2_t* arr, double base, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_log10(   oarrm2n2_t* arr);
  void    oarrm2n2_log10_to(oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_log(     oarrm2n2_t* arr);
  void    oarrm2n2_log_to(  oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_exp(     oarrm2n2_t* arr);
  void    oarrm2n2_exp_to(  oarrm2n2_t* arr, oarrm2n2_t* res);
  oarrm2n2_t oarrm2n2_pow(     oarrm2n2_t* arr, double e);
  void    oarrm2n2_pow_to(  oarrm2n2_t* arr, double e, oarrm2n2_t* res);
  
  
  # From ../../../include/oti/static/onumm2n2/array/gauss/utils.h
  
  void feoarrm2n2_dimCheck_FF_samesize(feoarrm2n2_t* arr1, feoarrm2n2_t* arr2, feonumm2n2_t* res);
  void feoarrm2n2_dimCheck_OF_samesize(  oarrm2n2_t* arr1, feoarrm2n2_t* arr2, feonumm2n2_t* res);
  void feoarrm2n2_dimCheck_RF_samesize(   darr_t* arr1, feoarrm2n2_t* arr2, feonumm2n2_t* res);
  void feoarrm2n2_dimCheck_FF_elementwise(feoarrm2n2_t* arr1, feoarrm2n2_t* arr2, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_OF_elementwise(  oarrm2n2_t* arr1, feoarrm2n2_t* arr2, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm2n2_t* arr2, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_fF_elementwise( feonumm2n2_t* num1, feoarrm2n2_t* arr2, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_Ff_elementwise(feoarrm2n2_t* arr1,  feonumm2n2_t* num2, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_FF_matmul( feoarrm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_OF_matmul(   oarrm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_FO_matmul( feoarrm2n2_t* lhs,   oarrm2n2_t* rhs, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_FR_matmul( feoarrm2n2_t* lhs,    darr_t* rhs, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_F_squareness( feoarrm2n2_t* arr1, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_F_transpose( feoarrm2n2_t* arr1, feoarrm2n2_t* res);
  void feoarrm2n2_dimCheck_FfO_integrate(feoarrm2n2_t* arr, feonumm2n2_t* num,oarrm2n2_t* res);
  void feoarrm2n2_get_active_bases(feoarrm2n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm2n2/array/gauss/algebra.h
  
  feoarrm2n2_t feoarrm2n2_neg(    feoarrm2n2_t* arr);
  void      feoarrm2n2_neg_to( feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sum_FF(   feoarrm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sum_FF_to(feoarrm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sum_fF(    feonumm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sum_fF_to( feonumm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sum_OF(     oarrm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sum_OF_to(  oarrm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sum_RF(      darr_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sum_RF_to(   darr_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sum_oF(   onumm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sum_oF_to(onumm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sum_rF(     coeff_t  lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sum_rF_to(  coeff_t  lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sub_FF(    feoarrm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sub_FF_to( feoarrm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sub_fF(    feonumm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sub_fF_to( feonumm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sub_Ff(    feoarrm2n2_t* lhs, feonumm2n2_t* rhs);
  void      feoarrm2n2_sub_Ff_to( feoarrm2n2_t* lhs, feonumm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sub_OF(      oarrm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sub_OF_to(   oarrm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sub_FO(    feoarrm2n2_t* lhs,   oarrm2n2_t* rhs);
  void      feoarrm2n2_sub_FO_to( feoarrm2n2_t* lhs,   oarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sub_RF(       darr_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sub_RF_to(    darr_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sub_FR(    feoarrm2n2_t* lhs,    darr_t* rhs);
  void      feoarrm2n2_sub_FR_to( feoarrm2n2_t* lhs,    darr_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sub_oF(    onumm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sub_oF_to( onumm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sub_Fo(    feoarrm2n2_t* lhs, onumm2n2_t* rhs);
  void      feoarrm2n2_sub_Fo_to( feoarrm2n2_t* lhs, onumm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sub_rF(      coeff_t  lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_sub_rF_to(    coeff_t lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sub_Fr(    feoarrm2n2_t* lhs,   coeff_t  rhs);
  void      feoarrm2n2_sub_Fr_to( feoarrm2n2_t* lhs,   coeff_t  rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_mul_FF(   feoarrm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_mul_FF_to(feoarrm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_mul_fF(    feonumm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_mul_fF_to( feonumm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_mul_OF(     oarrm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_mul_OF_to(  oarrm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_mul_RF(      darr_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_mul_RF_to(   darr_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_mul_oF(   onumm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_mul_oF_to(onumm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_mul_rF(     coeff_t  lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_mul_rF_to(  coeff_t  lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_div_FF(    feoarrm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_div_FF_to( feoarrm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_div_fF(     feonumm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_div_fF_to(  feonumm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_div_Ff(    feoarrm2n2_t* lhs,  feonumm2n2_t* rhs);
  void      feoarrm2n2_div_Ff_to( feoarrm2n2_t* lhs,  feonumm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_div_OF(      oarrm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_div_OF_to(   oarrm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_div_FO(    feoarrm2n2_t* lhs,   oarrm2n2_t* rhs);
  void      feoarrm2n2_div_FO_to( feoarrm2n2_t* lhs,   oarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_div_RF(       darr_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_div_RF_to(    darr_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_div_FR(    feoarrm2n2_t* lhs,    darr_t* rhs);
  void      feoarrm2n2_div_FR_to( feoarrm2n2_t* lhs,    darr_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_div_oF(    onumm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_div_oF_to( onumm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_div_Fo(    feoarrm2n2_t* lhs, onumm2n2_t* rhs);
  void      feoarrm2n2_div_Fo_to( feoarrm2n2_t* lhs, onumm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_div_rF(      coeff_t  lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_div_rF_to(    coeff_t lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_div_Fr(    feoarrm2n2_t* lhs,   coeff_t  rhs);
  void      feoarrm2n2_div_Fr_to( feoarrm2n2_t* lhs,   coeff_t  rhs, feoarrm2n2_t* res);
  oarrm2n2_t feoarrm2n2_integrate(    feoarrm2n2_t* arr, feonumm2n2_t* w);
  void    feoarrm2n2_integrate_to( feoarrm2n2_t* arr, feonumm2n2_t* w, oarrm2n2_t* res);
  feonumm2n2_t feoarrm2n2_dotproduct_FF(    feoarrm2n2_t* lhs, feoarrm2n2_t* rhs);
  void     feoarrm2n2_dotproduct_FF_to( feoarrm2n2_t* lhs, feoarrm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feoarrm2n2_dotproduct_OF(      oarrm2n2_t* lhs, feoarrm2n2_t* rhs);
  void     feoarrm2n2_dotproduct_OF_to(   oarrm2n2_t* lhs, feoarrm2n2_t* rhs, feonumm2n2_t* res);
  feonumm2n2_t feoarrm2n2_dotproduct_RF(       darr_t* lhs, feoarrm2n2_t* rhs);
  void     feoarrm2n2_dotproduct_RF_to(    darr_t* lhs, feoarrm2n2_t* rhs, feonumm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_matmul_FF(    feoarrm2n2_t* lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_matmul_FF_to( feoarrm2n2_t* lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_matmul_OF(    oarrm2n2_t*   lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_matmul_OF_to( oarrm2n2_t*   lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_matmul_FO(    feoarrm2n2_t* lhs, oarrm2n2_t*   rhs);
  void      feoarrm2n2_matmul_FO_to( feoarrm2n2_t* lhs, oarrm2n2_t*   rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_matmul_RF(    darr_t*    lhs, feoarrm2n2_t* rhs);
  void      feoarrm2n2_matmul_RF_to( darr_t*    lhs, feoarrm2n2_t* rhs, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_matmul_FR(    feoarrm2n2_t* lhs, darr_t*    rhs);
  void      feoarrm2n2_matmul_FR_to( feoarrm2n2_t* lhs, darr_t*    rhs, feoarrm2n2_t* res);
  feonumm2n2_t feoarrm2n2_det(   feoarrm2n2_t* arr);
  void     feoarrm2n2_det_to(feoarrm2n2_t* arr, feonumm2n2_t* res);
  feonumm2n2_t feoarrm2n2_norm(     feoarrm2n2_t* arr);
  void     feoarrm2n2_norm_to(  feoarrm2n2_t* arr, feonumm2n2_t* res);
  feonumm2n2_t feoarrm2n2_pnorm(    feoarrm2n2_t* arr, coeff_t p);
  void     feoarrm2n2_pnorm_to( feoarrm2n2_t* arr, coeff_t p, feonumm2n2_t* res);
  feoarrm2n2_t   feoarrm2n2_invert(    feoarrm2n2_t* arr);
  void        feoarrm2n2_invert_to( feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t   feoarrm2n2_transpose(   feoarrm2n2_t* arr);
  void        feoarrm2n2_transpose_to(feoarrm2n2_t* arr, feoarrm2n2_t* res);
  
  
  # From ../../../include/oti/static/onumm2n2/array/gauss/base.h
  
  void      feoarrm2n2_get_order_im_to( ord_t order, feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_get_order_im(    ord_t order, feoarrm2n2_t* arr);
  feoarrm2n2_t feoarrm2n2_get_deriv(   imdir_t idx, ord_t order, feoarrm2n2_t* arr);
  void      feoarrm2n2_get_deriv_to(imdir_t idx, ord_t order, feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_get_im(      imdir_t idx, ord_t order, feoarrm2n2_t* arr);
  void      feoarrm2n2_get_im_to(   imdir_t idx, ord_t order, feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_truncate_im(   imdir_t idx, ord_t order, feoarrm2n2_t* arr);
  void      feoarrm2n2_truncate_im_to(imdir_t idx, ord_t order, feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_copy(   feoarrm2n2_t* src);
  void      feoarrm2n2_copy_to(feoarrm2n2_t* src, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_get_im(    imdir_t idx, ord_t order, feoarrm2n2_t* arr);
  void      feoarrm2n2_get_im_to( imdir_t idx, ord_t order, feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_get_deriv(    imdir_t idx, ord_t order, feoarrm2n2_t* arr);
  void      feoarrm2n2_get_deriv_to( imdir_t idx, ord_t order, feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_extract_im(    imdir_t idx, ord_t order, feoarrm2n2_t* arr);
  void      feoarrm2n2_extract_im_to( imdir_t idx, ord_t order, feoarrm2n2_t* arr,  feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_extract_deriv(    imdir_t idx, ord_t order, feoarrm2n2_t* arr);
  void      feoarrm2n2_extract_deriv_to( imdir_t idx, ord_t order, feoarrm2n2_t* arr, feoarrm2n2_t* res);
  oarrm2n2_t   feoarrm2n2_get_item_k(  feoarrm2n2_t* arr, uint64_t k);
  feonumm2n2_t  feoarrm2n2_get_item_ij( feoarrm2n2_t* arr, uint64_t i, uint64_t j);
  onumm2n2_t feoarrm2n2_get_item_ijk(feoarrm2n2_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm2n2_get_item_ij_to(  feoarrm2n2_t* arr, uint64_t i, uint64_t j,
                                 feonumm2n2_t* res);
  void feoarrm2n2_get_item_k_to(   feoarrm2n2_t* arr, uint64_t k,
                                  oarrm2n2_t* res);
  void feoarrm2n2_get_item_ijk_to( feoarrm2n2_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_get_slice(feoarrm2n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm2n2_get_slice_to(feoarrm2n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n2_t* res);
  void feoarrm2n2_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm2n2_t* res);
  void feoarrm2n2_set_item_ij_o(  onumm2n2_t* elm, uint64_t i, uint64_t j,
                               feoarrm2n2_t* res);
  void feoarrm2n2_set_item_ij_f(  feonumm2n2_t* elm, uint64_t i, uint64_t j,
                              feoarrm2n2_t* res);
  void feoarrm2n2_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm2n2_t* res);
  void feoarrm2n2_set_item_k_o(  onumm2n2_t* elm, uint64_t k,
                              feoarrm2n2_t* res);
  void feoarrm2n2_set_item_k_R(    oarrm2n2_t* elm, uint64_t k,
                            feoarrm2n2_t* res);
  void feoarrm2n2_set_item_k_O(    oarrm2n2_t* elm, uint64_t k,
                            feoarrm2n2_t* res);
  void feoarrm2n2_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm2n2_t* res);
  void feoarrm2n2_set_item_ijk_o( onumm2n2_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm2n2_t* res);
  void feoarrm2n2_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n2_t* res);
  void feoarrm2n2_set_slice_o( onumm2n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n2_t* res);
  void feoarrm2n2_set_slice_f( feonumm2n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n2_t* res);
  void feoarrm2n2_set_slice_O( oarrm2n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n2_t* res);
  void feoarrm2n2_set_slice_F( feoarrm2n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n2_t* res);
  void feoarrm2n2_set_all_o( onumm2n2_t* num, feoarrm2n2_t* arr );
  void feoarrm2n2_set_all_r(   coeff_t  num, feoarrm2n2_t* arr );
  void feoarrm2n2_set_all_f(  feonumm2n2_t* num, feoarrm2n2_t* arr );
  void feoarrm2n2_set_r(    coeff_t src, feoarrm2n2_t* res );
  void feoarrm2n2_set_o( onumm2n2_t* src, feoarrm2n2_t* res );
  void feoarrm2n2_set_f(  feonumm2n2_t* src, feoarrm2n2_t* res );
  void feoarrm2n2_set_R(    darr_t* src, feoarrm2n2_t* res );
  void feoarrm2n2_set_O(   oarrm2n2_t* src, feoarrm2n2_t* res );
  void feoarrm2n2_set_F( feoarrm2n2_t* src, feoarrm2n2_t* res );
  feoarrm2n2_t feoarrm2n2_eye( uint64_t size,  uint64_t nip);
  feoarrm2n2_t feoarrm2n2_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm2n2_t feoarrm2n2_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm2n2_t feoarrm2n2_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm2n2_free(feoarrm2n2_t* arr);
  feoarrm2n2_t feoarrm2n2_init();
  ord_t feoarrm2n2_get_order(feoarrm2n2_t* arr);
  
  
  # From ../../../include/oti/static/onumm2n2/array/gauss/functions.h
  
  feoarrm2n2_t feoarrm2n2_atanh(    feoarrm2n2_t* arr);
  void      feoarrm2n2_atanh_to( feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_asinh(    feoarrm2n2_t* arr);
  void      feoarrm2n2_asinh_to( feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_acosh(    feoarrm2n2_t* arr);
  void      feoarrm2n2_acosh_to( feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_tanh(     feoarrm2n2_t* arr);
  void      feoarrm2n2_tanh_to(  feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sinh(     feoarrm2n2_t* arr);
  void      feoarrm2n2_sinh_to(  feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_cosh(     feoarrm2n2_t* arr);
  void      feoarrm2n2_cosh_to(  feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_atan(     feoarrm2n2_t* arr);
  void      feoarrm2n2_atan_to(  feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_asin(     feoarrm2n2_t* arr);
  void      feoarrm2n2_asin_to(  feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_acos(     feoarrm2n2_t* arr);
  void      feoarrm2n2_acos_to(  feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_tan(      feoarrm2n2_t* arr);
  void      feoarrm2n2_tan_to(   feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sin(      feoarrm2n2_t* arr);
  void      feoarrm2n2_sin_to(   feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_cos(      feoarrm2n2_t* arr);
  void      feoarrm2n2_cos_to(   feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_logb(     feoarrm2n2_t* arr, double base);
  void      feoarrm2n2_logb_to(  feoarrm2n2_t* arr, double base, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_log10(    feoarrm2n2_t* arr);
  void      feoarrm2n2_log10_to( feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_log(      feoarrm2n2_t* arr);
  void      feoarrm2n2_log_to(   feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_exp(      feoarrm2n2_t* arr);
  void      feoarrm2n2_exp_to(   feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_cbrt(     feoarrm2n2_t* arr);
  void      feoarrm2n2_cbrt_to(  feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_sqrt(     feoarrm2n2_t* arr);
  void      feoarrm2n2_sqrt_to(  feoarrm2n2_t* arr, feoarrm2n2_t* res);
  feoarrm2n2_t feoarrm2n2_pow(      feoarrm2n2_t* arr, double e);
  void      feoarrm2n2_pow_to(   feoarrm2n2_t* arr, double e, feoarrm2n2_t* res);
  
  