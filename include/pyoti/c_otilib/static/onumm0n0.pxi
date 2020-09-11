cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm0n0/scalar/structures.h
  
  ctypedef struct  onumm0n0_t : # {
    coeff_t r;
  # } onumm0n0_t;
  
  
  # From ../../../include/oti/static/onumm0n0/array/structures.h
  
  ctypedef struct  oarrm0n0_t : # {
      onumm0n0_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm0n0_t;
  
  
  # From ../../../include/oti/static/onumm0n0/scalar/gauss/structures.h
  
  ctypedef struct  feonumm0n0_t: # {
      onumm0n0_t*  p_data;
      uint64_t    nip;
  # } feonumm0n0_t;
  
  
  # From ../../../include/oti/static/onumm0n0/array/gauss/structures.h
  
  ctypedef struct  feoarrm0n0_t: # {
      oarrm0n0_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm0n0_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm0n0/scalar/functions.h
  
  onumm0n0_t onumm0n0_atanh(onumm0n0_t* num);
  void onumm0n0_atanh_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_asinh(onumm0n0_t* num);
  void onumm0n0_asinh_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_acosh(onumm0n0_t* num);
  void onumm0n0_acosh_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_tanh(onumm0n0_t* num);
  void onumm0n0_tanh_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_sqrt(onumm0n0_t* num);
  void onumm0n0_sqrt_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_cbrt(onumm0n0_t* num);
  void onumm0n0_cbrt_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_cosh(onumm0n0_t* num);
  void onumm0n0_cosh_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_sinh(onumm0n0_t* num);
  void onumm0n0_sinh_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_asin(onumm0n0_t* num);
  void onumm0n0_asin_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_acos(onumm0n0_t* num);
  void onumm0n0_acos_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_atan(onumm0n0_t* num);
  void onumm0n0_atan_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_tan(onumm0n0_t* num);
  void onumm0n0_tan_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_cos(onumm0n0_t* num);
  void onumm0n0_cos_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_sin(onumm0n0_t* num );
  void onumm0n0_sin_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_logb(onumm0n0_t* num, double base);
  void onumm0n0_logb_to(onumm0n0_t* num, double base, onumm0n0_t* res);
  onumm0n0_t onumm0n0_log10(onumm0n0_t* num);
  void onumm0n0_log10_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_log(onumm0n0_t* num);
  void onumm0n0_log_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_exp(onumm0n0_t* num);
  void onumm0n0_exp_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_pow(onumm0n0_t* num, double e);
  void onumm0n0_pow_to(onumm0n0_t* num, coeff_t e, onumm0n0_t* res);
  
  
  # From ../../../include/oti/static/onumm0n0/scalar/base.h
  
  void onumm0n0_set_im_o(onumm0n0_t* num, imdir_t idx, ord_t order, onumm0n0_t* res);
  void onumm0n0_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm0n0_t* res);
  void onumm0n0_set_deriv_o(onumm0n0_t* num, imdir_t idx, ord_t order, onumm0n0_t* res);
  void onumm0n0_extract_im_to( imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_extract_im(imdir_t idx, ord_t order, onumm0n0_t* num);
  onumm0n0_t onumm0n0_extract_deriv(imdir_t idx, ord_t order, onumm0n0_t* num);
  void onumm0n0_extract_deriv_to(imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res);
  void onumm0n0_get_im_to_o(imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_get_im_o(imdir_t idx, ord_t order, onumm0n0_t* num);
  void onumm0n0_get_im_to_r(imdir_t idx, ord_t order, onumm0n0_t* num, coeff_t* res);
  ord_t onumm0n0_get_order(onumm0n0_t* lhs);
  onumm0n0_t onumm0n0_get_deriv_o( imdir_t idx, ord_t order, onumm0n0_t* num);
  void onumm0n0_get_deriv_to( imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res);
  void onumm0n0_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm0n0_t* res);
  onumm0n0_t onumm0n0_init();
  ndir_t onumm0n0_get_ndir_order(ord_t order, onumm0n0_t* num);
  ndir_t onumm0n0_get_ndir_total(onumm0n0_t* num);
  coeff_t* onumm0n0_get_order_address(ord_t order, onumm0n0_t* num);
  onumm0n0_t onumm0n0_create_r(  coeff_t lhs);
  void onumm0n0_set_r(  coeff_t lhs, onumm0n0_t* res);
  void onumm0n0_set_o(  onumm0n0_t* lhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_get_order_im(ord_t order, onumm0n0_t* lhs);
  void onumm0n0_get_order_im_to(ord_t order, onumm0n0_t* lhs, onumm0n0_t* res);
  coeff_t onumm0n0_get_item(imdir_t idx, ord_t order, onumm0n0_t* lhs);
  coeff_t onumm0n0_get_deriv(imdir_t idx, ord_t order, onumm0n0_t* lhs);
  void onumm0n0_set_item(coeff_t val, imdir_t idx, ord_t order, onumm0n0_t* x);
  onumm0n0_t onumm0n0_copy(  onumm0n0_t* lhs);
  void onumm0n0_copy_to(  onumm0n0_t* lhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_taylor_integrate(coeff_t* deltas,onumm0n0_t* lhs);
  void onumm0n0_taylor_integrate_to(coeff_t* deltas,onumm0n0_t* lhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_truncate_im(imdir_t idx, ord_t order, onumm0n0_t* lhs);
  void onumm0n0_truncate_im_to(imdir_t idx, ord_t order, onumm0n0_t* lhs, onumm0n0_t* res);
  void onumm0n0_print(  onumm0n0_t* lhs);
  imdir_t onumm0n0_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm0n0/scalar/utils.h
  
  void onumm0n0_get_active_bases(onumm0n0_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm0n0/scalar/algebra.h
  
  onumm0n0_t onumm0n0_abs(onumm0n0_t* num);
  onumm0n0_t onumm0n0_div_ro(coeff_t num, onumm0n0_t* den);
  onumm0n0_t onumm0n0_div_oo(onumm0n0_t* num, onumm0n0_t* den);
  onumm0n0_t onumm0n0_div_or(onumm0n0_t* num, coeff_t val);
  void onumm0n0_div_ro_to(coeff_t num, onumm0n0_t* den, onumm0n0_t* res);
  void onumm0n0_div_oo_to(onumm0n0_t* num, onumm0n0_t* den, onumm0n0_t* res);
  void onumm0n0_div_or_to(onumm0n0_t* num, coeff_t val, onumm0n0_t* res);
  void onumm0n0_abs_to(onumm0n0_t* num, onumm0n0_t* res);
  onumm0n0_t onumm0n0_neg(  onumm0n0_t* lhs);
  void onumm0n0_neg_to(  onumm0n0_t* lhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_sum_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs);
  void onumm0n0_sum_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_sum_ro(  coeff_t lhs,  onumm0n0_t* rhs);
  void onumm0n0_sum_ro_to(  coeff_t lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_sub_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs);
  void onumm0n0_sub_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_sub_ro(  coeff_t lhs,  onumm0n0_t* rhs);
  void onumm0n0_sub_ro_to(  coeff_t lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_sub_or(  onumm0n0_t* lhs,  coeff_t rhs);
  void onumm0n0_sub_or_to(  onumm0n0_t* lhs,  coeff_t rhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_mul_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs);
  void onumm0n0_mul_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_mul_ro(  coeff_t lhs,  onumm0n0_t* rhs);
  void onumm0n0_mul_ro_to(  coeff_t lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_trunc_mul_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs);
  void onumm0n0_trunc_mul_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_gem_oo(  onumm0n0_t* a,  onumm0n0_t* b,  onumm0n0_t* c);
  void onumm0n0_gem_oo_to(  onumm0n0_t* a,  onumm0n0_t* b,  onumm0n0_t* c, onumm0n0_t* res);
  onumm0n0_t onumm0n0_gem_ro(  coeff_t a,  onumm0n0_t* b,  onumm0n0_t* c);
  void onumm0n0_gem_ro_to(  coeff_t a,  onumm0n0_t* b,  onumm0n0_t* c, onumm0n0_t* res);
  void onumm0n0_trunc_gem_oo_to( ord_t ord_lhs,  onumm0n0_t* a,  ord_t ord_rhs,  onumm0n0_t* b,  onumm0n0_t* c, onumm0n0_t* res);
  void onumm0n0_trunc_sum_oo_to(ord_t order, onumm0n0_t* lhs,onumm0n0_t* rhs, onumm0n0_t* res);
  void onumm0n0_trunc_sub_oo_to(ord_t order, onumm0n0_t* lhs,onumm0n0_t* rhs, onumm0n0_t* res);
  onumm0n0_t onumm0n0_feval(coeff_t* feval_re, onumm0n0_t* x);
  void onumm0n0_feval_to(coeff_t* feval_re, onumm0n0_t* x, onumm0n0_t* res);
  
  
  # From ../../../include/oti/static/onumm0n0/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm0n0/scalar/gauss/functions.h
  
  feonumm0n0_t feonumm0n0_atanh(    feonumm0n0_t* num);
  void     feonumm0n0_atanh_to( feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_asinh(    feonumm0n0_t* num);
  void     feonumm0n0_asinh_to( feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_acosh(    feonumm0n0_t* num);
  void     feonumm0n0_acosh_to( feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_tanh(     feonumm0n0_t* num);
  void     feonumm0n0_tanh_to(  feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_cosh(     feonumm0n0_t* num);
  void     feonumm0n0_cosh_to(  feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_sinh(     feonumm0n0_t* num);
  void     feonumm0n0_sinh_to(  feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_asin(     feonumm0n0_t* num);
  void     feonumm0n0_asin_to(  feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_acos(     feonumm0n0_t* num);
  void     feonumm0n0_acos_to(  feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_atan(     feonumm0n0_t* num);
  void     feonumm0n0_atan_to(  feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_tan(      feonumm0n0_t* num);
  void     feonumm0n0_tan_to(   feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_cos(      feonumm0n0_t* num);
  void     feonumm0n0_cos_to(   feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_sin(      feonumm0n0_t* num);
  void     feonumm0n0_sin_to(   feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_logb(     feonumm0n0_t* num, double base);
  void     feonumm0n0_logb_to(  feonumm0n0_t* num, double base, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_log10(    feonumm0n0_t* num);
  void     feonumm0n0_log10_to( feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_log(      feonumm0n0_t* num);
  void     feonumm0n0_log_to(   feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_exp(      feonumm0n0_t* num);
  void     feonumm0n0_exp_to(   feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_cbrt(     feonumm0n0_t* num);
  void     feonumm0n0_cbrt_to(  feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_sqrt(     feonumm0n0_t* num);
  void     feonumm0n0_sqrt_to(  feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_pow(      feonumm0n0_t* num, double e);
  void     feonumm0n0_pow_to(   feonumm0n0_t* num, double e, feonumm0n0_t* res);
  onumm0n0_t feonumm0n0_integrate(       feonumm0n0_t* num, feonumm0n0_t* w);
  void      feonumm0n0_integrate_to(    feonumm0n0_t* num, feonumm0n0_t* w, onumm0n0_t* res);
  onumm0n0_t feonumm0n0_integrate_f(     feonumm0n0_t* num, feonumm0n0_t* w);
  void      feonumm0n0_integrate_f_to(  feonumm0n0_t* num, feonumm0n0_t* w, onumm0n0_t* res);
  onumm0n0_t feonumm0n0_integrate_r(       coeff_t num, feonumm0n0_t* w);
  void      feonumm0n0_integrate_r_to(    coeff_t num, feonumm0n0_t* w, onumm0n0_t* res);
  onumm0n0_t feonumm0n0_integrate_o(    onumm0n0_t* num, feonumm0n0_t* w);
  void      feonumm0n0_integrate_o_to( onumm0n0_t* num, feonumm0n0_t* w, onumm0n0_t* res);
  
  
  # From ../../../include/oti/static/onumm0n0/scalar/gauss/base.h
  
  void     feonumm0n0_get_order_im_to( ord_t order, feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_get_order_im(    ord_t order, feonumm0n0_t* num);
  feonumm0n0_t feonumm0n0_get_im(    imdir_t idx, ord_t order, feonumm0n0_t* num);
  void     feonumm0n0_get_im_to( imdir_t idx, ord_t order, feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_get_deriv(    imdir_t idx, ord_t order, feonumm0n0_t* num);
  void     feonumm0n0_get_deriv_to( imdir_t idx, ord_t order, feonumm0n0_t* num, feonumm0n0_t* res);
  void feonumm0n0_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm0n0_t* num);
  void feonumm0n0_set_im_o( onumm0n0_t* val, imdir_t idx, ord_t order, feonumm0n0_t* num);
  void feonumm0n0_set_im_f(  feonumm0n0_t* val, imdir_t idx, ord_t order, feonumm0n0_t* num);
  void feonumm0n0_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm0n0_t* num);
  void feonumm0n0_set_deriv_o( onumm0n0_t* val, imdir_t idx, ord_t order, feonumm0n0_t* num);
  void feonumm0n0_set_deriv_f(  feonumm0n0_t* val, imdir_t idx, ord_t order, feonumm0n0_t* num);
  feonumm0n0_t feonumm0n0_extract_im(    imdir_t idx, ord_t order, feonumm0n0_t* num);
  void     feonumm0n0_extract_im_to( imdir_t idx, ord_t order, feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_extract_deriv(    imdir_t idx, ord_t order, feonumm0n0_t* num);
  void     feonumm0n0_extract_deriv_to( imdir_t idx, ord_t order, feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_truncate_im(    imdir_t idx, ord_t order, feonumm0n0_t* num);
  void     feonumm0n0_truncate_im_to( imdir_t idx, ord_t order, feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_copy(    feonumm0n0_t* src);
  void     feonumm0n0_copy_to( feonumm0n0_t* src, feonumm0n0_t* dst);
  void feonumm0n0_set_r(    coeff_t num, feonumm0n0_t* res);
  void feonumm0n0_set_o( onumm0n0_t* num, feonumm0n0_t* res);
  void feonumm0n0_set_f(  feonumm0n0_t* num, feonumm0n0_t* res);
  void feonumm0n0_set_item_k_r(   coeff_t  num, uint64_t k, feonumm0n0_t* res);
  void feonumm0n0_set_item_k_o( onumm0n0_t* num, uint64_t k, feonumm0n0_t* res);
  onumm0n0_t feonumm0n0_get_item_k(   feonumm0n0_t* num, uint64_t k);
  void      feonumm0n0_get_item_k_to(feonumm0n0_t* num, uint64_t k, onumm0n0_t* res);
  feonumm0n0_t feonumm0n0_zeros(uint64_t nIntPts);
  feonumm0n0_t feonumm0n0_createEmpty(uint64_t nIntPts);
  feonumm0n0_t feonumm0n0_empty_like(feonumm0n0_t* arr);
  void feonumm0n0_free(feonumm0n0_t* num);
  ord_t feonumm0n0_get_order( feonumm0n0_t* num );
  feonumm0n0_t feonumm0n0_init();
  
  
  # From ../../../include/oti/static/onumm0n0/scalar/gauss/utils.h
  
  void feonumm0n0_dimCheck(feonumm0n0_t* arr1,feonumm0n0_t* arr2);
  void feonumm0n0_get_active_bases(feonumm0n0_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm0n0/scalar/gauss/algebra.h
  
  feonumm0n0_t feonumm0n0_neg(   feonumm0n0_t* num);
  void     feonumm0n0_neg_to(feonumm0n0_t* num, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_sum_ff(   feonumm0n0_t* lhs, feonumm0n0_t* rhs);
  void     feonumm0n0_sum_ff_to(feonumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_sum_of(   onumm0n0_t* lhs, feonumm0n0_t* rhs);
  void     feonumm0n0_sum_of_to(onumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_sum_rf(   coeff_t lhs, feonumm0n0_t* rhs);
  void     feonumm0n0_sum_rf_to(coeff_t lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_sub_ff(     feonumm0n0_t* lhs,  feonumm0n0_t* rhs);
  void     feonumm0n0_sub_ff_to(  feonumm0n0_t* lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_sub_of(    onumm0n0_t* lhs,  feonumm0n0_t* rhs);
  void     feonumm0n0_sub_of_to( onumm0n0_t* lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_sub_fo(     feonumm0n0_t* lhs, onumm0n0_t* rhs);
  void     feonumm0n0_sub_fo_to(  feonumm0n0_t* lhs, onumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_sub_rf(       coeff_t lhs,  feonumm0n0_t* rhs);
  void     feonumm0n0_sub_rf_to(    coeff_t lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_sub_fr(     feonumm0n0_t* lhs,    coeff_t rhs);
  void     feonumm0n0_sub_fr_to(  feonumm0n0_t* lhs,    coeff_t rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_mul_ff(   feonumm0n0_t* lhs, feonumm0n0_t* rhs);
  void     feonumm0n0_mul_ff_to(feonumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_mul_of(   onumm0n0_t* lhs, feonumm0n0_t* rhs);
  void     feonumm0n0_mul_of_to(onumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_mul_rf(   coeff_t lhs, feonumm0n0_t* rhs);
  void     feonumm0n0_mul_rf_to(coeff_t lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_div_ff(     feonumm0n0_t* lhs,  feonumm0n0_t* rhs);
  void     feonumm0n0_div_ff_to(  feonumm0n0_t* lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_div_of(    onumm0n0_t* lhs,  feonumm0n0_t* rhs);
  void     feonumm0n0_div_of_to( onumm0n0_t* lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_div_fo(     feonumm0n0_t* lhs, onumm0n0_t* rhs);
  void     feonumm0n0_div_fo_to(  feonumm0n0_t* lhs, onumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_div_rf(       coeff_t lhs,  feonumm0n0_t* rhs);
  void     feonumm0n0_div_rf_to(    coeff_t lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feonumm0n0_div_fr(     feonumm0n0_t* lhs,    coeff_t rhs);
  void     feonumm0n0_div_fr_to(  feonumm0n0_t* lhs,    coeff_t rhs, feonumm0n0_t* res);
  
  
  # From ../../../include/oti/static/onumm0n0/array/functions.h
  
  oarrm0n0_t oarrm0n0_atanh(   oarrm0n0_t* arr);
  void    oarrm0n0_atanh_to(oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_asinh(   oarrm0n0_t* arr);
  void    oarrm0n0_asinh_to(oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_acosh(   oarrm0n0_t* arr);
  void    oarrm0n0_acosh_to(oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_tanh(    oarrm0n0_t* arr);
  void    oarrm0n0_tanh_to( oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_cbrt(    oarrm0n0_t* arr);
  void    oarrm0n0_cbrt_to( oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_sqrt(    oarrm0n0_t* arr);
  void    oarrm0n0_sqrt_to( oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_cosh(    oarrm0n0_t* arr);
  void    oarrm0n0_cosh_to( oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_sinh(    oarrm0n0_t* arr);
  void    oarrm0n0_sinh_to( oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_asin(    oarrm0n0_t* arr);
  void    oarrm0n0_asin_to( oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_acos(    oarrm0n0_t* arr);
  void    oarrm0n0_acos_to( oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_atan(    oarrm0n0_t* arr);
  void    oarrm0n0_atan_to( oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_tan(     oarrm0n0_t* arr);
  void    oarrm0n0_tan_to(  oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_cos(     oarrm0n0_t* arr);
  void    oarrm0n0_cos_to(  oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_sin(     oarrm0n0_t* arr);
  void    oarrm0n0_sin_to(  oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_logb(    oarrm0n0_t* arr, double base);
  void    oarrm0n0_logb_to( oarrm0n0_t* arr, double base, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_log10(   oarrm0n0_t* arr);
  void    oarrm0n0_log10_to(oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_log(     oarrm0n0_t* arr);
  void    oarrm0n0_log_to(  oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_exp(     oarrm0n0_t* arr);
  void    oarrm0n0_exp_to(  oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_pow(     oarrm0n0_t* arr, double e);
  void    oarrm0n0_pow_to(  oarrm0n0_t* arr, double e, oarrm0n0_t* res);
  
  
  # From ../../../include/oti/static/onumm0n0/array/algebra_elementwise.h
  
  oarrm0n0_t oarrm0n0_neg(oarrm0n0_t* arr);
  void oarrm0n0_neg_to(oarrm0n0_t* rhs, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_sum_OO(oarrm0n0_t*   lhs, oarrm0n0_t* rhs);
  oarrm0n0_t oarrm0n0_sum_RO(darr_t*    lhs, oarrm0n0_t* rhs);
  oarrm0n0_t oarrm0n0_sum_oO(onumm0n0_t* lhs, oarrm0n0_t* rhs);
  oarrm0n0_t oarrm0n0_sum_rO(coeff_t    lhs, oarrm0n0_t* rhs);
  void oarrm0n0_sum_OO_to(oarrm0n0_t*   lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
  void oarrm0n0_sum_RO_to(darr_t*    lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
  void oarrm0n0_sum_oO_to(onumm0n0_t* lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
  void oarrm0n0_sum_rO_to(coeff_t    lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
  void oarrm0n0_trunc_sum_OO_to(ord_t order, oarrm0n0_t* arr1, oarrm0n0_t* arr2, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_sub_OO(oarrm0n0_t*   lhs, oarrm0n0_t*   rhs);
  oarrm0n0_t oarrm0n0_sub_RO(darr_t*    lhs, oarrm0n0_t*   rhs);
  oarrm0n0_t oarrm0n0_sub_OR(oarrm0n0_t*   lhs, darr_t*    rhs);
  oarrm0n0_t oarrm0n0_sub_oO(onumm0n0_t* lhs, oarrm0n0_t*   rhs);
  oarrm0n0_t oarrm0n0_sub_Oo(oarrm0n0_t*   lhs, onumm0n0_t* rhs);
  oarrm0n0_t oarrm0n0_sub_rO(coeff_t    lhs, oarrm0n0_t*   rhs);
  oarrm0n0_t oarrm0n0_sub_Or(oarrm0n0_t*   lhs, coeff_t    rhs);
  void oarrm0n0_sub_OO_to( oarrm0n0_t*   lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
  void oarrm0n0_sub_RO_to( darr_t*    lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
  void oarrm0n0_sub_OR_to( oarrm0n0_t*   lhs, darr_t*    rhs, oarrm0n0_t* res);
  void oarrm0n0_sub_oO_to( onumm0n0_t* lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
  void oarrm0n0_sub_Oo_to( oarrm0n0_t*   lhs, onumm0n0_t* rhs, oarrm0n0_t* res);
  void oarrm0n0_sub_rO_to( coeff_t    lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
  void oarrm0n0_sub_Or_to( oarrm0n0_t*   lhs, coeff_t    rhs, oarrm0n0_t* res);
  void oarrm0n0_trunc_sub_OO_to(ord_t order, oarrm0n0_t* arr1, oarrm0n0_t* arr2, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_mul_OO(oarrm0n0_t*   lhs, oarrm0n0_t* rhs);
  oarrm0n0_t oarrm0n0_mul_RO(darr_t*    lhs, oarrm0n0_t* rhs);
  oarrm0n0_t oarrm0n0_mul_oO(onumm0n0_t* lhs, oarrm0n0_t* rhs);
  oarrm0n0_t oarrm0n0_mul_rO(coeff_t    lhs, oarrm0n0_t* rhs);
  void oarrm0n0_mul_OO_to(oarrm0n0_t*   lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
  void oarrm0n0_mul_RO_to(darr_t*    lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
  void oarrm0n0_mul_oO_to(onumm0n0_t* lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
  void oarrm0n0_mul_rO_to(coeff_t    lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
  void oarrm0n0_gem_OO_to(  oarrm0n0_t* arr1, oarrm0n0_t* arr2, oarrm0n0_t* arr3, oarrm0n0_t* res);
  void oarrm0n0_gem_oO_to(onumm0n0_t* arr1, oarrm0n0_t* arr2, oarrm0n0_t* arr3, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_div_OO(oarrm0n0_t*   lhs, oarrm0n0_t*   rhs);
  oarrm0n0_t oarrm0n0_div_OR(oarrm0n0_t*   lhs, darr_t*    rhs);
  oarrm0n0_t oarrm0n0_div_RO(darr_t*    lhs, oarrm0n0_t*   rhs);
  oarrm0n0_t oarrm0n0_div_oO(onumm0n0_t* lhs, oarrm0n0_t*   rhs);
  oarrm0n0_t oarrm0n0_div_Oo(oarrm0n0_t*   lhs, onumm0n0_t* rhs);
  oarrm0n0_t oarrm0n0_div_rO(coeff_t    lhs, oarrm0n0_t*   rhs);
  oarrm0n0_t oarrm0n0_div_Or(oarrm0n0_t*   lhs, coeff_t    rhs);
  void oarrm0n0_div_OO_to(oarrm0n0_t*   lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
  void oarrm0n0_div_RO_to(darr_t*    lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
  void oarrm0n0_div_OR_to(oarrm0n0_t*   lhs, darr_t*    rhs, oarrm0n0_t* res);
  void oarrm0n0_div_oO_to(onumm0n0_t* lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
  void oarrm0n0_div_Oo_to(oarrm0n0_t*   lhs, onumm0n0_t* rhs, oarrm0n0_t* res);
  void oarrm0n0_div_rO_to(coeff_t    lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
  void oarrm0n0_div_Or_to(oarrm0n0_t*   lhs, coeff_t    rhs, oarrm0n0_t* res);
  
  
  # From ../../../include/oti/static/onumm0n0/array/base.h
  
  void    oarrm0n0_taylor_integrate_to( coeff_t* deltas, oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_taylor_integrate(    coeff_t* deltas, oarrm0n0_t* arr);
  void    oarrm0n0_get_order_im_to( ord_t order, oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_get_order_im(    ord_t order, oarrm0n0_t* arr);
  void oarrm0n0_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm0n0_t* res);
  void oarrm0n0_set_slice_O( oarrm0n0_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm0n0_t* res);
  void oarrm0n0_set_slice_o( onumm0n0_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_get_slice( oarrm0n0_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm0n0_get_slice_to( oarrm0n0_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_truncate_im(    imdir_t idx, ord_t order, oarrm0n0_t* arr);
  void    oarrm0n0_truncate_im_to( imdir_t idx, ord_t order, oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_extract_im(   imdir_t idx, ord_t order, oarrm0n0_t* arr);
  void    oarrm0n0_extract_im_to(imdir_t idx, ord_t order, oarrm0n0_t* arr, oarrm0n0_t* res);
  darr_t  oarrm0n0_get_deriv(    imdir_t idx, ord_t order, oarrm0n0_t* arr);
  void    oarrm0n0_get_deriv_to( imdir_t idx, ord_t order, oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_get_deriv_o(  imdir_t idx, ord_t order, oarrm0n0_t* arr);
  oarrm0n0_t oarrm0n0_extract_deriv(    imdir_t idx, ord_t order, oarrm0n0_t* arr);
  void    oarrm0n0_extract_deriv_to( imdir_t idx, ord_t order, oarrm0n0_t* arr, oarrm0n0_t* res);
  darr_t  oarrm0n0_get_im(   imdir_t idx, ord_t order, oarrm0n0_t* arr);
  oarrm0n0_t oarrm0n0_get_im_o( imdir_t idx, ord_t order, oarrm0n0_t* arr);
  void    oarrm0n0_get_im_to(imdir_t idx, ord_t order, oarrm0n0_t* arr, oarrm0n0_t* res);
  void    oarrm0n0_copy_to(oarrm0n0_t* arr, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_copy(oarrm0n0_t* arr);
  void oarrm0n0_set_all_r( coeff_t num, oarrm0n0_t* arr);
  void oarrm0n0_set_item_i_r( coeff_t num, uint64_t i, oarrm0n0_t* arr);
  void oarrm0n0_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm0n0_t* arr);
  void oarrm0n0_set_r(   coeff_t  num,   oarrm0n0_t* arr);
  void oarrm0n0_set_o( onumm0n0_t* num,   oarrm0n0_t* arr);
  void oarrm0n0_set_O(   oarrm0n0_t* arrin, oarrm0n0_t* arr);
  void oarrm0n0_set_all_o( onumm0n0_t* src, oarrm0n0_t* arr);
  void oarrm0n0_set_item_i_o( onumm0n0_t* num, uint64_t i, oarrm0n0_t* arr);
  void oarrm0n0_set_item_ij_o( onumm0n0_t* num, uint64_t i, uint64_t j, oarrm0n0_t* arr);
  onumm0n0_t oarrm0n0_get_item_i(    oarrm0n0_t* arr, uint64_t i);
  void      oarrm0n0_get_item_i_to( oarrm0n0_t* arr, uint64_t i,             onumm0n0_t* res);
  onumm0n0_t oarrm0n0_get_item_ij(   oarrm0n0_t* arr, uint64_t i, uint64_t j);
  void      oarrm0n0_get_item_ij_to(oarrm0n0_t* arr, uint64_t i, uint64_t j, onumm0n0_t* res);
  oarrm0n0_t oarrm0n0_init();
  void oarrm0n0_free(oarrm0n0_t* arr);
  oarrm0n0_t oarrm0n0_empty_like(oarrm0n0_t* arr);
  oarrm0n0_t oarrm0n0_eye(uint64_t nrows);
  oarrm0n0_t oarrm0n0_ones(uint64_t nrows, uint64_t ncols);
  oarrm0n0_t oarrm0n0_zeros(uint64_t nrows, uint64_t ncols);
  oarrm0n0_t oarrm0n0_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm0n0/array/utils.h
  
  void oarrm0n0_dimCheck_OO_elementwise(oarrm0n0_t* arr1, oarrm0n0_t* arr2, oarrm0n0_t* res);
  void oarrm0n0_dimCheck_RO_elementwise(darr_t*  arr1, oarrm0n0_t* arr2, oarrm0n0_t* res);
  void oarrm0n0_dimCheck_OO_matmul(oarrm0n0_t* arr1, oarrm0n0_t* arr2, oarrm0n0_t* res);
  void oarrm0n0_dimCheck_RO_matmul(darr_t*  arr1, oarrm0n0_t* arr2, oarrm0n0_t* res);
  void oarrm0n0_dimCheck_OR_matmul(oarrm0n0_t* arr1, darr_t*  arr2, oarrm0n0_t* res);
  void oarrm0n0_dimCheck_O_squareness(oarrm0n0_t* arr1, oarrm0n0_t* res);
  void oarrm0n0_dimCheck_OO_samesize(oarrm0n0_t* arr1, oarrm0n0_t* res);
  void oarrm0n0_dimCheck_RO_samesize(darr_t* arr1, oarrm0n0_t* res);
  ord_t oarrm0n0_get_order(oarrm0n0_t* arr);
  void oarrm0n0_get_active_bases(oarrm0n0_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm0n0/array/algebra_matops.h
  
  onumm0n0_t oarrm0n0_dotproduct_OO(    oarrm0n0_t* lhs, oarrm0n0_t* rhs);
  void      oarrm0n0_dotproduct_OO_to( oarrm0n0_t* lhs, oarrm0n0_t* rhs, onumm0n0_t* res);
  onumm0n0_t oarrm0n0_dotproduct_RO(     darr_t* lhs, oarrm0n0_t* rhs);
  void      oarrm0n0_dotproduct_RO_to(  darr_t* lhs, oarrm0n0_t* rhs, onumm0n0_t* res);
  oarrm0n0_t oarrm0n0_matmul_OO(    oarrm0n0_t* lhs, oarrm0n0_t* rhs);
  oarrm0n0_t oarrm0n0_matmul_OR(    oarrm0n0_t* lhs,  darr_t* rhs);
  oarrm0n0_t oarrm0n0_matmul_RO(     darr_t* lhs, oarrm0n0_t* rhs);
  void    oarrm0n0_matmul_OO_to( oarrm0n0_t* lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
  void    oarrm0n0_matmul_OR_to( oarrm0n0_t* lhs,  darr_t* rhs, oarrm0n0_t* res);
  void    oarrm0n0_matmul_RO_to(  darr_t* lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_transpose(    oarrm0n0_t* arr1);
  void    oarrm0n0_transpose_to( oarrm0n0_t* arr1, oarrm0n0_t* res);
  oarrm0n0_t oarrm0n0_invert(    oarrm0n0_t* arr1);
  void    oarrm0n0_invert_to( oarrm0n0_t* arr1, oarrm0n0_t* res);
  onumm0n0_t oarrm0n0_det(    oarrm0n0_t* arr1);
  void      oarrm0n0_det_to( oarrm0n0_t* arr1, onumm0n0_t* res);
  onumm0n0_t oarrm0n0_norm(    oarrm0n0_t* arr1);
  void      oarrm0n0_norm_to( oarrm0n0_t* arr1,  onumm0n0_t* res);
  onumm0n0_t oarrm0n0_pnorm(    oarrm0n0_t* arr1, coeff_t p);
  void      oarrm0n0_pnorm_to( oarrm0n0_t* arr1, coeff_t p, onumm0n0_t* res);
  
  
  # From ../../../include/oti/static/onumm0n0/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm0n0/array/gauss/functions.h
  
  feoarrm0n0_t feoarrm0n0_atanh(    feoarrm0n0_t* arr);
  void      feoarrm0n0_atanh_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_asinh(    feoarrm0n0_t* arr);
  void      feoarrm0n0_asinh_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_acosh(    feoarrm0n0_t* arr);
  void      feoarrm0n0_acosh_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_tanh(     feoarrm0n0_t* arr);
  void      feoarrm0n0_tanh_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sinh(     feoarrm0n0_t* arr);
  void      feoarrm0n0_sinh_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_cosh(     feoarrm0n0_t* arr);
  void      feoarrm0n0_cosh_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_atan(     feoarrm0n0_t* arr);
  void      feoarrm0n0_atan_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_asin(     feoarrm0n0_t* arr);
  void      feoarrm0n0_asin_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_acos(     feoarrm0n0_t* arr);
  void      feoarrm0n0_acos_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_tan(      feoarrm0n0_t* arr);
  void      feoarrm0n0_tan_to(   feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sin(      feoarrm0n0_t* arr);
  void      feoarrm0n0_sin_to(   feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_cos(      feoarrm0n0_t* arr);
  void      feoarrm0n0_cos_to(   feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_logb(     feoarrm0n0_t* arr, double base);
  void      feoarrm0n0_logb_to(  feoarrm0n0_t* arr, double base, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_log10(    feoarrm0n0_t* arr);
  void      feoarrm0n0_log10_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_log(      feoarrm0n0_t* arr);
  void      feoarrm0n0_log_to(   feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_exp(      feoarrm0n0_t* arr);
  void      feoarrm0n0_exp_to(   feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_cbrt(     feoarrm0n0_t* arr);
  void      feoarrm0n0_cbrt_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sqrt(     feoarrm0n0_t* arr);
  void      feoarrm0n0_sqrt_to(  feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_pow(      feoarrm0n0_t* arr, double e);
  void      feoarrm0n0_pow_to(   feoarrm0n0_t* arr, double e, feoarrm0n0_t* res);
  
  
  # From ../../../include/oti/static/onumm0n0/array/gauss/base.h
  
  void      feoarrm0n0_get_order_im_to( ord_t order, feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_get_order_im(    ord_t order, feoarrm0n0_t* arr);
  feoarrm0n0_t feoarrm0n0_get_deriv(   imdir_t idx, ord_t order, feoarrm0n0_t* arr);
  void      feoarrm0n0_get_deriv_to(imdir_t idx, ord_t order, feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_get_im(      imdir_t idx, ord_t order, feoarrm0n0_t* arr);
  void      feoarrm0n0_get_im_to(   imdir_t idx, ord_t order, feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_truncate_im(   imdir_t idx, ord_t order, feoarrm0n0_t* arr);
  void      feoarrm0n0_truncate_im_to(imdir_t idx, ord_t order, feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_copy(   feoarrm0n0_t* src);
  void      feoarrm0n0_copy_to(feoarrm0n0_t* src, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_get_im(    imdir_t idx, ord_t order, feoarrm0n0_t* arr);
  void      feoarrm0n0_get_im_to( imdir_t idx, ord_t order, feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_get_deriv(    imdir_t idx, ord_t order, feoarrm0n0_t* arr);
  void      feoarrm0n0_get_deriv_to( imdir_t idx, ord_t order, feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_extract_im(    imdir_t idx, ord_t order, feoarrm0n0_t* arr);
  void      feoarrm0n0_extract_im_to( imdir_t idx, ord_t order, feoarrm0n0_t* arr,  feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_extract_deriv(    imdir_t idx, ord_t order, feoarrm0n0_t* arr);
  void      feoarrm0n0_extract_deriv_to( imdir_t idx, ord_t order, feoarrm0n0_t* arr, feoarrm0n0_t* res);
  oarrm0n0_t   feoarrm0n0_get_item_k(  feoarrm0n0_t* arr, uint64_t k);
  feonumm0n0_t  feoarrm0n0_get_item_ij( feoarrm0n0_t* arr, uint64_t i, uint64_t j);
  onumm0n0_t feoarrm0n0_get_item_ijk(feoarrm0n0_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm0n0_get_item_ij_to(  feoarrm0n0_t* arr, uint64_t i, uint64_t j,
                                 feonumm0n0_t* res);
  void feoarrm0n0_get_item_k_to(   feoarrm0n0_t* arr, uint64_t k,
                                  oarrm0n0_t* res);
  void feoarrm0n0_get_item_ijk_to( feoarrm0n0_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_get_slice(feoarrm0n0_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm0n0_get_slice_to(feoarrm0n0_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm0n0_t* res);
  void feoarrm0n0_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm0n0_t* res);
  void feoarrm0n0_set_item_ij_o(  onumm0n0_t* elm, uint64_t i, uint64_t j,
                               feoarrm0n0_t* res);
  void feoarrm0n0_set_item_ij_f(  feonumm0n0_t* elm, uint64_t i, uint64_t j,
                              feoarrm0n0_t* res);
  void feoarrm0n0_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm0n0_t* res);
  void feoarrm0n0_set_item_k_o(  onumm0n0_t* elm, uint64_t k,
                              feoarrm0n0_t* res);
  void feoarrm0n0_set_item_k_R(    oarrm0n0_t* elm, uint64_t k,
                            feoarrm0n0_t* res);
  void feoarrm0n0_set_item_k_O(    oarrm0n0_t* elm, uint64_t k,
                            feoarrm0n0_t* res);
  void feoarrm0n0_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm0n0_t* res);
  void feoarrm0n0_set_item_ijk_o( onumm0n0_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm0n0_t* res);
  void feoarrm0n0_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm0n0_t* res);
  void feoarrm0n0_set_slice_o( onumm0n0_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm0n0_t* res);
  void feoarrm0n0_set_slice_f( feonumm0n0_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm0n0_t* res);
  void feoarrm0n0_set_slice_O( oarrm0n0_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm0n0_t* res);
  void feoarrm0n0_set_slice_F( feoarrm0n0_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm0n0_t* res);
  void feoarrm0n0_set_all_o( onumm0n0_t* num, feoarrm0n0_t* arr );
  void feoarrm0n0_set_all_r(   coeff_t  num, feoarrm0n0_t* arr );
  void feoarrm0n0_set_all_f(  feonumm0n0_t* num, feoarrm0n0_t* arr );
  void feoarrm0n0_set_r(    coeff_t src, feoarrm0n0_t* res );
  void feoarrm0n0_set_o( onumm0n0_t* src, feoarrm0n0_t* res );
  void feoarrm0n0_set_f(  feonumm0n0_t* src, feoarrm0n0_t* res );
  void feoarrm0n0_set_R(    darr_t* src, feoarrm0n0_t* res );
  void feoarrm0n0_set_O(   oarrm0n0_t* src, feoarrm0n0_t* res );
  void feoarrm0n0_set_F( feoarrm0n0_t* src, feoarrm0n0_t* res );
  feoarrm0n0_t feoarrm0n0_eye( uint64_t size,  uint64_t nip);
  feoarrm0n0_t feoarrm0n0_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm0n0_t feoarrm0n0_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm0n0_t feoarrm0n0_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm0n0_free(feoarrm0n0_t* arr);
  feoarrm0n0_t feoarrm0n0_init();
  ord_t feoarrm0n0_get_order(feoarrm0n0_t* arr);
  
  
  # From ../../../include/oti/static/onumm0n0/array/gauss/utils.h
  
  void feoarrm0n0_dimCheck_FF_samesize(feoarrm0n0_t* arr1, feoarrm0n0_t* arr2, feonumm0n0_t* res);
  void feoarrm0n0_dimCheck_OF_samesize(  oarrm0n0_t* arr1, feoarrm0n0_t* arr2, feonumm0n0_t* res);
  void feoarrm0n0_dimCheck_RF_samesize(   darr_t* arr1, feoarrm0n0_t* arr2, feonumm0n0_t* res);
  void feoarrm0n0_dimCheck_FF_elementwise(feoarrm0n0_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_OF_elementwise(  oarrm0n0_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_fF_elementwise( feonumm0n0_t* num1, feoarrm0n0_t* arr2, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_Ff_elementwise(feoarrm0n0_t* arr1,  feonumm0n0_t* num2, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_FF_matmul( feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_OF_matmul(   oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_RF_matmul(    darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_FO_matmul( feoarrm0n0_t* lhs,   oarrm0n0_t* rhs, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_FR_matmul( feoarrm0n0_t* lhs,    darr_t* rhs, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_F_squareness( feoarrm0n0_t* arr1, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_F_transpose( feoarrm0n0_t* arr1, feoarrm0n0_t* res);
  void feoarrm0n0_dimCheck_FfO_integrate(feoarrm0n0_t* arr, feonumm0n0_t* num,oarrm0n0_t* res);
  void feoarrm0n0_get_active_bases(feoarrm0n0_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm0n0/array/gauss/algebra.h
  
  feoarrm0n0_t feoarrm0n0_neg(    feoarrm0n0_t* arr);
  void      feoarrm0n0_neg_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sum_FF(   feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sum_FF_to(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sum_fF(    feonumm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sum_fF_to( feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sum_OF(     oarrm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sum_OF_to(  oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sum_RF(      darr_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sum_RF_to(   darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sum_oF(   onumm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sum_oF_to(onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sum_rF(     coeff_t  lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sum_rF_to(  coeff_t  lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sub_FF(    feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sub_FF_to( feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sub_fF(    feonumm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sub_fF_to( feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sub_Ff(    feoarrm0n0_t* lhs, feonumm0n0_t* rhs);
  void      feoarrm0n0_sub_Ff_to( feoarrm0n0_t* lhs, feonumm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sub_OF(      oarrm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sub_OF_to(   oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sub_FO(    feoarrm0n0_t* lhs,   oarrm0n0_t* rhs);
  void      feoarrm0n0_sub_FO_to( feoarrm0n0_t* lhs,   oarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sub_RF(       darr_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sub_RF_to(    darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sub_FR(    feoarrm0n0_t* lhs,    darr_t* rhs);
  void      feoarrm0n0_sub_FR_to( feoarrm0n0_t* lhs,    darr_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sub_oF(    onumm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sub_oF_to( onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sub_Fo(    feoarrm0n0_t* lhs, onumm0n0_t* rhs);
  void      feoarrm0n0_sub_Fo_to( feoarrm0n0_t* lhs, onumm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sub_rF(      coeff_t  lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_sub_rF_to(    coeff_t lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_sub_Fr(    feoarrm0n0_t* lhs,   coeff_t  rhs);
  void      feoarrm0n0_sub_Fr_to( feoarrm0n0_t* lhs,   coeff_t  rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_mul_FF(   feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_mul_FF_to(feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_mul_fF(    feonumm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_mul_fF_to( feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_mul_OF(     oarrm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_mul_OF_to(  oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_mul_RF(      darr_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_mul_RF_to(   darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_mul_oF(   onumm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_mul_oF_to(onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_mul_rF(     coeff_t  lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_mul_rF_to(  coeff_t  lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_div_FF(    feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_div_FF_to( feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_div_fF(     feonumm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_div_fF_to(  feonumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_div_Ff(    feoarrm0n0_t* lhs,  feonumm0n0_t* rhs);
  void      feoarrm0n0_div_Ff_to( feoarrm0n0_t* lhs,  feonumm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_div_OF(      oarrm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_div_OF_to(   oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_div_FO(    feoarrm0n0_t* lhs,   oarrm0n0_t* rhs);
  void      feoarrm0n0_div_FO_to( feoarrm0n0_t* lhs,   oarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_div_RF(       darr_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_div_RF_to(    darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_div_FR(    feoarrm0n0_t* lhs,    darr_t* rhs);
  void      feoarrm0n0_div_FR_to( feoarrm0n0_t* lhs,    darr_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_div_oF(    onumm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_div_oF_to( onumm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_div_Fo(    feoarrm0n0_t* lhs, onumm0n0_t* rhs);
  void      feoarrm0n0_div_Fo_to( feoarrm0n0_t* lhs, onumm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_div_rF(      coeff_t  lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_div_rF_to(    coeff_t lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_div_Fr(    feoarrm0n0_t* lhs,   coeff_t  rhs);
  void      feoarrm0n0_div_Fr_to( feoarrm0n0_t* lhs,   coeff_t  rhs, feoarrm0n0_t* res);
  oarrm0n0_t feoarrm0n0_integrate(    feoarrm0n0_t* arr, feonumm0n0_t* w);
  void    feoarrm0n0_integrate_to( feoarrm0n0_t* arr, feonumm0n0_t* w, oarrm0n0_t* res);
  feonumm0n0_t feoarrm0n0_dotproduct_FF(    feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
  void     feoarrm0n0_dotproduct_FF_to( feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feoarrm0n0_dotproduct_OF(      oarrm0n0_t* lhs, feoarrm0n0_t* rhs);
  void     feoarrm0n0_dotproduct_OF_to(   oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feonumm0n0_t* res);
  feonumm0n0_t feoarrm0n0_dotproduct_RF(       darr_t* lhs, feoarrm0n0_t* rhs);
  void     feoarrm0n0_dotproduct_RF_to(    darr_t* lhs, feoarrm0n0_t* rhs, feonumm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_matmul_FF(    feoarrm0n0_t* lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_matmul_FF_to( feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_matmul_OF(    oarrm0n0_t*   lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_matmul_OF_to( oarrm0n0_t*   lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_matmul_FO(    feoarrm0n0_t* lhs, oarrm0n0_t*   rhs);
  void      feoarrm0n0_matmul_FO_to( feoarrm0n0_t* lhs, oarrm0n0_t*   rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_matmul_RF(    darr_t*    lhs, feoarrm0n0_t* rhs);
  void      feoarrm0n0_matmul_RF_to( darr_t*    lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
  feoarrm0n0_t feoarrm0n0_matmul_FR(    feoarrm0n0_t* lhs, darr_t*    rhs);
  void      feoarrm0n0_matmul_FR_to( feoarrm0n0_t* lhs, darr_t*    rhs, feoarrm0n0_t* res);
  feonumm0n0_t feoarrm0n0_det(   feoarrm0n0_t* arr);
  void     feoarrm0n0_det_to(feoarrm0n0_t* arr, feonumm0n0_t* res);
  feonumm0n0_t feoarrm0n0_norm(     feoarrm0n0_t* arr);
  void     feoarrm0n0_norm_to(  feoarrm0n0_t* arr, feonumm0n0_t* res);
  feonumm0n0_t feoarrm0n0_pnorm(    feoarrm0n0_t* arr, coeff_t p);
  void     feoarrm0n0_pnorm_to( feoarrm0n0_t* arr, coeff_t p, feonumm0n0_t* res);
  feoarrm0n0_t   feoarrm0n0_invert(    feoarrm0n0_t* arr);
  void        feoarrm0n0_invert_to( feoarrm0n0_t* arr, feoarrm0n0_t* res);
  feoarrm0n0_t   feoarrm0n0_transpose(   feoarrm0n0_t* arr);
  void        feoarrm0n0_transpose_to(feoarrm0n0_t* arr, feoarrm0n0_t* res);
  
  