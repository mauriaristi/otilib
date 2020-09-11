cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm1n8/scalar/structures.h
  
  ctypedef struct  onumm1n8_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e11;
    coeff_t e111;
    coeff_t e1111;
    coeff_t e11111;
    coeff_t e111111;
    coeff_t e1111111;
    coeff_t e11111111;
  # } onumm1n8_t;
  
  
  # From ../../../include/oti/static/onumm1n8/array/structures.h
  
  ctypedef struct  oarrm1n8_t : # {
      onumm1n8_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm1n8_t;
  
  
  # From ../../../include/oti/static/onumm1n8/scalar/gauss/structures.h
  
  ctypedef struct  feonumm1n8_t: # {
      onumm1n8_t*  p_data;
      uint64_t    nip;
  # } feonumm1n8_t;
  
  
  # From ../../../include/oti/static/onumm1n8/array/gauss/structures.h
  
  ctypedef struct  feoarrm1n8_t: # {
      oarrm1n8_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm1n8_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm1n8/scalar/functions.h
  
  onumm1n8_t onumm1n8_atanh(onumm1n8_t* num);
  void onumm1n8_atanh_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_asinh(onumm1n8_t* num);
  void onumm1n8_asinh_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_acosh(onumm1n8_t* num);
  void onumm1n8_acosh_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_tanh(onumm1n8_t* num);
  void onumm1n8_tanh_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_sqrt(onumm1n8_t* num);
  void onumm1n8_sqrt_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_cbrt(onumm1n8_t* num);
  void onumm1n8_cbrt_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_cosh(onumm1n8_t* num);
  void onumm1n8_cosh_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_sinh(onumm1n8_t* num);
  void onumm1n8_sinh_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_asin(onumm1n8_t* num);
  void onumm1n8_asin_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_acos(onumm1n8_t* num);
  void onumm1n8_acos_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_atan(onumm1n8_t* num);
  void onumm1n8_atan_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_tan(onumm1n8_t* num);
  void onumm1n8_tan_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_cos(onumm1n8_t* num);
  void onumm1n8_cos_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_sin(onumm1n8_t* num );
  void onumm1n8_sin_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_logb(onumm1n8_t* num, double base);
  void onumm1n8_logb_to(onumm1n8_t* num, double base, onumm1n8_t* res);
  onumm1n8_t onumm1n8_log10(onumm1n8_t* num);
  void onumm1n8_log10_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_log(onumm1n8_t* num);
  void onumm1n8_log_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_exp(onumm1n8_t* num);
  void onumm1n8_exp_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_pow(onumm1n8_t* num, double e);
  void onumm1n8_pow_to(onumm1n8_t* num, coeff_t e, onumm1n8_t* res);
  
  
  # From ../../../include/oti/static/onumm1n8/scalar/base.h
  
  void onumm1n8_set_im_o(onumm1n8_t* num, imdir_t idx, ord_t order, onumm1n8_t* res);
  void onumm1n8_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm1n8_t* res);
  void onumm1n8_set_deriv_o(onumm1n8_t* num, imdir_t idx, ord_t order, onumm1n8_t* res);
  void onumm1n8_extract_im_to( imdir_t idx, ord_t order, onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_extract_im(imdir_t idx, ord_t order, onumm1n8_t* num);
  onumm1n8_t onumm1n8_extract_deriv(imdir_t idx, ord_t order, onumm1n8_t* num);
  void onumm1n8_extract_deriv_to(imdir_t idx, ord_t order, onumm1n8_t* num, onumm1n8_t* res);
  void onumm1n8_get_im_to_o(imdir_t idx, ord_t order, onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_get_im_o(imdir_t idx, ord_t order, onumm1n8_t* num);
  void onumm1n8_get_im_to_r(imdir_t idx, ord_t order, onumm1n8_t* num, coeff_t* res);
  ord_t onumm1n8_get_order(onumm1n8_t* lhs);
  onumm1n8_t onumm1n8_get_deriv_o( imdir_t idx, ord_t order, onumm1n8_t* num);
  void onumm1n8_get_deriv_to( imdir_t idx, ord_t order, onumm1n8_t* num, onumm1n8_t* res);
  void onumm1n8_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm1n8_t* res);
  onumm1n8_t onumm1n8_init();
  ndir_t onumm1n8_get_ndir_order(ord_t order, onumm1n8_t* num);
  ndir_t onumm1n8_get_ndir_total(onumm1n8_t* num);
  coeff_t* onumm1n8_get_order_address(ord_t order, onumm1n8_t* num);
  onumm1n8_t onumm1n8_create_r(  coeff_t lhs);
  void onumm1n8_set_r(  coeff_t lhs, onumm1n8_t* res);
  void onumm1n8_set_o(  onumm1n8_t* lhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_get_order_im(ord_t order, onumm1n8_t* lhs);
  void onumm1n8_get_order_im_to(ord_t order, onumm1n8_t* lhs, onumm1n8_t* res);
  coeff_t onumm1n8_get_item(imdir_t idx, ord_t order, onumm1n8_t* lhs);
  coeff_t onumm1n8_get_deriv(imdir_t idx, ord_t order, onumm1n8_t* lhs);
  void onumm1n8_set_item(coeff_t val, imdir_t idx, ord_t order, onumm1n8_t* x);
  onumm1n8_t onumm1n8_copy(  onumm1n8_t* lhs);
  void onumm1n8_copy_to(  onumm1n8_t* lhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_taylor_integrate(coeff_t* deltas,onumm1n8_t* lhs);
  void onumm1n8_taylor_integrate_to(coeff_t* deltas,onumm1n8_t* lhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_truncate_im(imdir_t idx, ord_t order, onumm1n8_t* lhs);
  void onumm1n8_truncate_im_to(imdir_t idx, ord_t order, onumm1n8_t* lhs, onumm1n8_t* res);
  void onumm1n8_print(  onumm1n8_t* lhs);
  imdir_t onumm1n8_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm1n8/scalar/utils.h
  
  void onumm1n8_get_active_bases(onumm1n8_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm1n8/scalar/algebra.h
  
  onumm1n8_t onumm1n8_abs(onumm1n8_t* num);
  onumm1n8_t onumm1n8_div_ro(coeff_t num, onumm1n8_t* den);
  onumm1n8_t onumm1n8_div_oo(onumm1n8_t* num, onumm1n8_t* den);
  onumm1n8_t onumm1n8_div_or(onumm1n8_t* num, coeff_t val);
  void onumm1n8_div_ro_to(coeff_t num, onumm1n8_t* den, onumm1n8_t* res);
  void onumm1n8_div_oo_to(onumm1n8_t* num, onumm1n8_t* den, onumm1n8_t* res);
  void onumm1n8_div_or_to(onumm1n8_t* num, coeff_t val, onumm1n8_t* res);
  void onumm1n8_abs_to(onumm1n8_t* num, onumm1n8_t* res);
  onumm1n8_t onumm1n8_neg(  onumm1n8_t* lhs);
  void onumm1n8_neg_to(  onumm1n8_t* lhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_sum_oo(  onumm1n8_t* lhs,  onumm1n8_t* rhs);
  void onumm1n8_sum_oo_to(  onumm1n8_t* lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_sum_ro(  coeff_t lhs,  onumm1n8_t* rhs);
  void onumm1n8_sum_ro_to(  coeff_t lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_sub_oo(  onumm1n8_t* lhs,  onumm1n8_t* rhs);
  void onumm1n8_sub_oo_to(  onumm1n8_t* lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_sub_ro(  coeff_t lhs,  onumm1n8_t* rhs);
  void onumm1n8_sub_ro_to(  coeff_t lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_sub_or(  onumm1n8_t* lhs,  coeff_t rhs);
  void onumm1n8_sub_or_to(  onumm1n8_t* lhs,  coeff_t rhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_mul_oo(  onumm1n8_t* lhs,  onumm1n8_t* rhs);
  void onumm1n8_mul_oo_to(  onumm1n8_t* lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_mul_ro(  coeff_t lhs,  onumm1n8_t* rhs);
  void onumm1n8_mul_ro_to(  coeff_t lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_trunc_mul_oo(  onumm1n8_t* lhs,  onumm1n8_t* rhs);
  void onumm1n8_trunc_mul_oo_to(  onumm1n8_t* lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_gem_oo(  onumm1n8_t* a,  onumm1n8_t* b,  onumm1n8_t* c);
  void onumm1n8_gem_oo_to(  onumm1n8_t* a,  onumm1n8_t* b,  onumm1n8_t* c, onumm1n8_t* res);
  onumm1n8_t onumm1n8_gem_ro(  coeff_t a,  onumm1n8_t* b,  onumm1n8_t* c);
  void onumm1n8_gem_ro_to(  coeff_t a,  onumm1n8_t* b,  onumm1n8_t* c, onumm1n8_t* res);
  void onumm1n8_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n8_t* a,  ord_t ord_rhs,  onumm1n8_t* b,  onumm1n8_t* c, onumm1n8_t* res);
  void onumm1n8_trunc_sum_oo_to(ord_t order, onumm1n8_t* lhs,onumm1n8_t* rhs, onumm1n8_t* res);
  void onumm1n8_trunc_sub_oo_to(ord_t order, onumm1n8_t* lhs,onumm1n8_t* rhs, onumm1n8_t* res);
  onumm1n8_t onumm1n8_feval(coeff_t* feval_re, onumm1n8_t* x);
  void onumm1n8_feval_to(coeff_t* feval_re, onumm1n8_t* x, onumm1n8_t* res);
  
  
  # From ../../../include/oti/static/onumm1n8/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm1n8/scalar/gauss/functions.h
  
  feonumm1n8_t feonumm1n8_atanh(    feonumm1n8_t* num);
  void     feonumm1n8_atanh_to( feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_asinh(    feonumm1n8_t* num);
  void     feonumm1n8_asinh_to( feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_acosh(    feonumm1n8_t* num);
  void     feonumm1n8_acosh_to( feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_tanh(     feonumm1n8_t* num);
  void     feonumm1n8_tanh_to(  feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_cosh(     feonumm1n8_t* num);
  void     feonumm1n8_cosh_to(  feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_sinh(     feonumm1n8_t* num);
  void     feonumm1n8_sinh_to(  feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_asin(     feonumm1n8_t* num);
  void     feonumm1n8_asin_to(  feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_acos(     feonumm1n8_t* num);
  void     feonumm1n8_acos_to(  feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_atan(     feonumm1n8_t* num);
  void     feonumm1n8_atan_to(  feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_tan(      feonumm1n8_t* num);
  void     feonumm1n8_tan_to(   feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_cos(      feonumm1n8_t* num);
  void     feonumm1n8_cos_to(   feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_sin(      feonumm1n8_t* num);
  void     feonumm1n8_sin_to(   feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_logb(     feonumm1n8_t* num, double base);
  void     feonumm1n8_logb_to(  feonumm1n8_t* num, double base, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_log10(    feonumm1n8_t* num);
  void     feonumm1n8_log10_to( feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_log(      feonumm1n8_t* num);
  void     feonumm1n8_log_to(   feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_exp(      feonumm1n8_t* num);
  void     feonumm1n8_exp_to(   feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_cbrt(     feonumm1n8_t* num);
  void     feonumm1n8_cbrt_to(  feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_sqrt(     feonumm1n8_t* num);
  void     feonumm1n8_sqrt_to(  feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_pow(      feonumm1n8_t* num, double e);
  void     feonumm1n8_pow_to(   feonumm1n8_t* num, double e, feonumm1n8_t* res);
  onumm1n8_t feonumm1n8_integrate(       feonumm1n8_t* num, feonumm1n8_t* w);
  void      feonumm1n8_integrate_to(    feonumm1n8_t* num, feonumm1n8_t* w, onumm1n8_t* res);
  onumm1n8_t feonumm1n8_integrate_f(     feonumm1n8_t* num, feonumm1n8_t* w);
  void      feonumm1n8_integrate_f_to(  feonumm1n8_t* num, feonumm1n8_t* w, onumm1n8_t* res);
  onumm1n8_t feonumm1n8_integrate_r(       coeff_t num, feonumm1n8_t* w);
  void      feonumm1n8_integrate_r_to(    coeff_t num, feonumm1n8_t* w, onumm1n8_t* res);
  onumm1n8_t feonumm1n8_integrate_o(    onumm1n8_t* num, feonumm1n8_t* w);
  void      feonumm1n8_integrate_o_to( onumm1n8_t* num, feonumm1n8_t* w, onumm1n8_t* res);
  
  
  # From ../../../include/oti/static/onumm1n8/scalar/gauss/base.h
  
  void     feonumm1n8_get_order_im_to( ord_t order, feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_get_order_im(    ord_t order, feonumm1n8_t* num);
  feonumm1n8_t feonumm1n8_get_im(    imdir_t idx, ord_t order, feonumm1n8_t* num);
  void     feonumm1n8_get_im_to( imdir_t idx, ord_t order, feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_get_deriv(    imdir_t idx, ord_t order, feonumm1n8_t* num);
  void     feonumm1n8_get_deriv_to( imdir_t idx, ord_t order, feonumm1n8_t* num, feonumm1n8_t* res);
  void feonumm1n8_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm1n8_t* num);
  void feonumm1n8_set_im_o( onumm1n8_t* val, imdir_t idx, ord_t order, feonumm1n8_t* num);
  void feonumm1n8_set_im_f(  feonumm1n8_t* val, imdir_t idx, ord_t order, feonumm1n8_t* num);
  void feonumm1n8_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm1n8_t* num);
  void feonumm1n8_set_deriv_o( onumm1n8_t* val, imdir_t idx, ord_t order, feonumm1n8_t* num);
  void feonumm1n8_set_deriv_f(  feonumm1n8_t* val, imdir_t idx, ord_t order, feonumm1n8_t* num);
  feonumm1n8_t feonumm1n8_extract_im(    imdir_t idx, ord_t order, feonumm1n8_t* num);
  void     feonumm1n8_extract_im_to( imdir_t idx, ord_t order, feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_extract_deriv(    imdir_t idx, ord_t order, feonumm1n8_t* num);
  void     feonumm1n8_extract_deriv_to( imdir_t idx, ord_t order, feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_truncate_im(    imdir_t idx, ord_t order, feonumm1n8_t* num);
  void     feonumm1n8_truncate_im_to( imdir_t idx, ord_t order, feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_copy(    feonumm1n8_t* src);
  void     feonumm1n8_copy_to( feonumm1n8_t* src, feonumm1n8_t* dst);
  void feonumm1n8_set_r(    coeff_t num, feonumm1n8_t* res);
  void feonumm1n8_set_o( onumm1n8_t* num, feonumm1n8_t* res);
  void feonumm1n8_set_f(  feonumm1n8_t* num, feonumm1n8_t* res);
  void feonumm1n8_set_item_k_r(   coeff_t  num, uint64_t k, feonumm1n8_t* res);
  void feonumm1n8_set_item_k_o( onumm1n8_t* num, uint64_t k, feonumm1n8_t* res);
  onumm1n8_t feonumm1n8_get_item_k(   feonumm1n8_t* num, uint64_t k);
  void      feonumm1n8_get_item_k_to(feonumm1n8_t* num, uint64_t k, onumm1n8_t* res);
  feonumm1n8_t feonumm1n8_zeros(uint64_t nIntPts);
  feonumm1n8_t feonumm1n8_createEmpty(uint64_t nIntPts);
  feonumm1n8_t feonumm1n8_empty_like(feonumm1n8_t* arr);
  void feonumm1n8_free(feonumm1n8_t* num);
  ord_t feonumm1n8_get_order( feonumm1n8_t* num );
  feonumm1n8_t feonumm1n8_init();
  
  
  # From ../../../include/oti/static/onumm1n8/scalar/gauss/utils.h
  
  void feonumm1n8_dimCheck(feonumm1n8_t* arr1,feonumm1n8_t* arr2);
  void feonumm1n8_get_active_bases(feonumm1n8_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n8/scalar/gauss/algebra.h
  
  feonumm1n8_t feonumm1n8_neg(   feonumm1n8_t* num);
  void     feonumm1n8_neg_to(feonumm1n8_t* num, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_sum_ff(   feonumm1n8_t* lhs, feonumm1n8_t* rhs);
  void     feonumm1n8_sum_ff_to(feonumm1n8_t* lhs, feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_sum_of(   onumm1n8_t* lhs, feonumm1n8_t* rhs);
  void     feonumm1n8_sum_of_to(onumm1n8_t* lhs, feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_sum_rf(   coeff_t lhs, feonumm1n8_t* rhs);
  void     feonumm1n8_sum_rf_to(coeff_t lhs, feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_sub_ff(     feonumm1n8_t* lhs,  feonumm1n8_t* rhs);
  void     feonumm1n8_sub_ff_to(  feonumm1n8_t* lhs,  feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_sub_of(    onumm1n8_t* lhs,  feonumm1n8_t* rhs);
  void     feonumm1n8_sub_of_to( onumm1n8_t* lhs,  feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_sub_fo(     feonumm1n8_t* lhs, onumm1n8_t* rhs);
  void     feonumm1n8_sub_fo_to(  feonumm1n8_t* lhs, onumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_sub_rf(       coeff_t lhs,  feonumm1n8_t* rhs);
  void     feonumm1n8_sub_rf_to(    coeff_t lhs,  feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_sub_fr(     feonumm1n8_t* lhs,    coeff_t rhs);
  void     feonumm1n8_sub_fr_to(  feonumm1n8_t* lhs,    coeff_t rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_mul_ff(   feonumm1n8_t* lhs, feonumm1n8_t* rhs);
  void     feonumm1n8_mul_ff_to(feonumm1n8_t* lhs, feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_mul_of(   onumm1n8_t* lhs, feonumm1n8_t* rhs);
  void     feonumm1n8_mul_of_to(onumm1n8_t* lhs, feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_mul_rf(   coeff_t lhs, feonumm1n8_t* rhs);
  void     feonumm1n8_mul_rf_to(coeff_t lhs, feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_div_ff(     feonumm1n8_t* lhs,  feonumm1n8_t* rhs);
  void     feonumm1n8_div_ff_to(  feonumm1n8_t* lhs,  feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_div_of(    onumm1n8_t* lhs,  feonumm1n8_t* rhs);
  void     feonumm1n8_div_of_to( onumm1n8_t* lhs,  feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_div_fo(     feonumm1n8_t* lhs, onumm1n8_t* rhs);
  void     feonumm1n8_div_fo_to(  feonumm1n8_t* lhs, onumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_div_rf(       coeff_t lhs,  feonumm1n8_t* rhs);
  void     feonumm1n8_div_rf_to(    coeff_t lhs,  feonumm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feonumm1n8_div_fr(     feonumm1n8_t* lhs,    coeff_t rhs);
  void     feonumm1n8_div_fr_to(  feonumm1n8_t* lhs,    coeff_t rhs, feonumm1n8_t* res);
  
  
  # From ../../../include/oti/static/onumm1n8/array/functions.h
  
  oarrm1n8_t oarrm1n8_atanh(   oarrm1n8_t* arr);
  void    oarrm1n8_atanh_to(oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_asinh(   oarrm1n8_t* arr);
  void    oarrm1n8_asinh_to(oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_acosh(   oarrm1n8_t* arr);
  void    oarrm1n8_acosh_to(oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_tanh(    oarrm1n8_t* arr);
  void    oarrm1n8_tanh_to( oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_cbrt(    oarrm1n8_t* arr);
  void    oarrm1n8_cbrt_to( oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_sqrt(    oarrm1n8_t* arr);
  void    oarrm1n8_sqrt_to( oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_cosh(    oarrm1n8_t* arr);
  void    oarrm1n8_cosh_to( oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_sinh(    oarrm1n8_t* arr);
  void    oarrm1n8_sinh_to( oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_asin(    oarrm1n8_t* arr);
  void    oarrm1n8_asin_to( oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_acos(    oarrm1n8_t* arr);
  void    oarrm1n8_acos_to( oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_atan(    oarrm1n8_t* arr);
  void    oarrm1n8_atan_to( oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_tan(     oarrm1n8_t* arr);
  void    oarrm1n8_tan_to(  oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_cos(     oarrm1n8_t* arr);
  void    oarrm1n8_cos_to(  oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_sin(     oarrm1n8_t* arr);
  void    oarrm1n8_sin_to(  oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_logb(    oarrm1n8_t* arr, double base);
  void    oarrm1n8_logb_to( oarrm1n8_t* arr, double base, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_log10(   oarrm1n8_t* arr);
  void    oarrm1n8_log10_to(oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_log(     oarrm1n8_t* arr);
  void    oarrm1n8_log_to(  oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_exp(     oarrm1n8_t* arr);
  void    oarrm1n8_exp_to(  oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_pow(     oarrm1n8_t* arr, double e);
  void    oarrm1n8_pow_to(  oarrm1n8_t* arr, double e, oarrm1n8_t* res);
  
  
  # From ../../../include/oti/static/onumm1n8/array/algebra_elementwise.h
  
  oarrm1n8_t oarrm1n8_neg(oarrm1n8_t* arr);
  void oarrm1n8_neg_to(oarrm1n8_t* rhs, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_sum_OO(oarrm1n8_t*   lhs, oarrm1n8_t* rhs);
  oarrm1n8_t oarrm1n8_sum_RO(darr_t*    lhs, oarrm1n8_t* rhs);
  oarrm1n8_t oarrm1n8_sum_oO(onumm1n8_t* lhs, oarrm1n8_t* rhs);
  oarrm1n8_t oarrm1n8_sum_rO(coeff_t    lhs, oarrm1n8_t* rhs);
  void oarrm1n8_sum_OO_to(oarrm1n8_t*   lhs, oarrm1n8_t* rhs, oarrm1n8_t* res);
  void oarrm1n8_sum_RO_to(darr_t*    lhs, oarrm1n8_t* rhs, oarrm1n8_t* res);
  void oarrm1n8_sum_oO_to(onumm1n8_t* lhs, oarrm1n8_t* rhs, oarrm1n8_t* res);
  void oarrm1n8_sum_rO_to(coeff_t    lhs, oarrm1n8_t* rhs, oarrm1n8_t* res);
  void oarrm1n8_trunc_sum_OO_to(ord_t order, oarrm1n8_t* arr1, oarrm1n8_t* arr2, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_sub_OO(oarrm1n8_t*   lhs, oarrm1n8_t*   rhs);
  oarrm1n8_t oarrm1n8_sub_RO(darr_t*    lhs, oarrm1n8_t*   rhs);
  oarrm1n8_t oarrm1n8_sub_OR(oarrm1n8_t*   lhs, darr_t*    rhs);
  oarrm1n8_t oarrm1n8_sub_oO(onumm1n8_t* lhs, oarrm1n8_t*   rhs);
  oarrm1n8_t oarrm1n8_sub_Oo(oarrm1n8_t*   lhs, onumm1n8_t* rhs);
  oarrm1n8_t oarrm1n8_sub_rO(coeff_t    lhs, oarrm1n8_t*   rhs);
  oarrm1n8_t oarrm1n8_sub_Or(oarrm1n8_t*   lhs, coeff_t    rhs);
  void oarrm1n8_sub_OO_to( oarrm1n8_t*   lhs, oarrm1n8_t*   rhs, oarrm1n8_t* res);
  void oarrm1n8_sub_RO_to( darr_t*    lhs, oarrm1n8_t*   rhs, oarrm1n8_t* res);
  void oarrm1n8_sub_OR_to( oarrm1n8_t*   lhs, darr_t*    rhs, oarrm1n8_t* res);
  void oarrm1n8_sub_oO_to( onumm1n8_t* lhs, oarrm1n8_t*   rhs, oarrm1n8_t* res);
  void oarrm1n8_sub_Oo_to( oarrm1n8_t*   lhs, onumm1n8_t* rhs, oarrm1n8_t* res);
  void oarrm1n8_sub_rO_to( coeff_t    lhs, oarrm1n8_t*   rhs, oarrm1n8_t* res);
  void oarrm1n8_sub_Or_to( oarrm1n8_t*   lhs, coeff_t    rhs, oarrm1n8_t* res);
  void oarrm1n8_trunc_sub_OO_to(ord_t order, oarrm1n8_t* arr1, oarrm1n8_t* arr2, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_mul_OO(oarrm1n8_t*   lhs, oarrm1n8_t* rhs);
  oarrm1n8_t oarrm1n8_mul_RO(darr_t*    lhs, oarrm1n8_t* rhs);
  oarrm1n8_t oarrm1n8_mul_oO(onumm1n8_t* lhs, oarrm1n8_t* rhs);
  oarrm1n8_t oarrm1n8_mul_rO(coeff_t    lhs, oarrm1n8_t* rhs);
  void oarrm1n8_mul_OO_to(oarrm1n8_t*   lhs, oarrm1n8_t* rhs, oarrm1n8_t* res);
  void oarrm1n8_mul_RO_to(darr_t*    lhs, oarrm1n8_t* rhs, oarrm1n8_t* res);
  void oarrm1n8_mul_oO_to(onumm1n8_t* lhs, oarrm1n8_t* rhs, oarrm1n8_t* res);
  void oarrm1n8_mul_rO_to(coeff_t    lhs, oarrm1n8_t* rhs, oarrm1n8_t* res);
  void oarrm1n8_gem_OO_to(  oarrm1n8_t* arr1, oarrm1n8_t* arr2, oarrm1n8_t* arr3, oarrm1n8_t* res);
  void oarrm1n8_gem_oO_to(onumm1n8_t* arr1, oarrm1n8_t* arr2, oarrm1n8_t* arr3, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_div_OO(oarrm1n8_t*   lhs, oarrm1n8_t*   rhs);
  oarrm1n8_t oarrm1n8_div_OR(oarrm1n8_t*   lhs, darr_t*    rhs);
  oarrm1n8_t oarrm1n8_div_RO(darr_t*    lhs, oarrm1n8_t*   rhs);
  oarrm1n8_t oarrm1n8_div_oO(onumm1n8_t* lhs, oarrm1n8_t*   rhs);
  oarrm1n8_t oarrm1n8_div_Oo(oarrm1n8_t*   lhs, onumm1n8_t* rhs);
  oarrm1n8_t oarrm1n8_div_rO(coeff_t    lhs, oarrm1n8_t*   rhs);
  oarrm1n8_t oarrm1n8_div_Or(oarrm1n8_t*   lhs, coeff_t    rhs);
  void oarrm1n8_div_OO_to(oarrm1n8_t*   lhs, oarrm1n8_t*   rhs, oarrm1n8_t* res);
  void oarrm1n8_div_RO_to(darr_t*    lhs, oarrm1n8_t*   rhs, oarrm1n8_t* res);
  void oarrm1n8_div_OR_to(oarrm1n8_t*   lhs, darr_t*    rhs, oarrm1n8_t* res);
  void oarrm1n8_div_oO_to(onumm1n8_t* lhs, oarrm1n8_t*   rhs, oarrm1n8_t* res);
  void oarrm1n8_div_Oo_to(oarrm1n8_t*   lhs, onumm1n8_t* rhs, oarrm1n8_t* res);
  void oarrm1n8_div_rO_to(coeff_t    lhs, oarrm1n8_t*   rhs, oarrm1n8_t* res);
  void oarrm1n8_div_Or_to(oarrm1n8_t*   lhs, coeff_t    rhs, oarrm1n8_t* res);
  
  
  # From ../../../include/oti/static/onumm1n8/array/base.h
  
  void    oarrm1n8_taylor_integrate_to( coeff_t* deltas, oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_taylor_integrate(    coeff_t* deltas, oarrm1n8_t* arr);
  void    oarrm1n8_get_order_im_to( ord_t order, oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_get_order_im(    ord_t order, oarrm1n8_t* arr);
  void oarrm1n8_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n8_t* res);
  void oarrm1n8_set_slice_O( oarrm1n8_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n8_t* res);
  void oarrm1n8_set_slice_o( onumm1n8_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_get_slice( oarrm1n8_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm1n8_get_slice_to( oarrm1n8_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_truncate_im(    imdir_t idx, ord_t order, oarrm1n8_t* arr);
  void    oarrm1n8_truncate_im_to( imdir_t idx, ord_t order, oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_extract_im(   imdir_t idx, ord_t order, oarrm1n8_t* arr);
  void    oarrm1n8_extract_im_to(imdir_t idx, ord_t order, oarrm1n8_t* arr, oarrm1n8_t* res);
  darr_t  oarrm1n8_get_deriv(    imdir_t idx, ord_t order, oarrm1n8_t* arr);
  void    oarrm1n8_get_deriv_to( imdir_t idx, ord_t order, oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_get_deriv_o(  imdir_t idx, ord_t order, oarrm1n8_t* arr);
  oarrm1n8_t oarrm1n8_extract_deriv(    imdir_t idx, ord_t order, oarrm1n8_t* arr);
  void    oarrm1n8_extract_deriv_to( imdir_t idx, ord_t order, oarrm1n8_t* arr, oarrm1n8_t* res);
  darr_t  oarrm1n8_get_im(   imdir_t idx, ord_t order, oarrm1n8_t* arr);
  oarrm1n8_t oarrm1n8_get_im_o( imdir_t idx, ord_t order, oarrm1n8_t* arr);
  void    oarrm1n8_get_im_to(imdir_t idx, ord_t order, oarrm1n8_t* arr, oarrm1n8_t* res);
  void    oarrm1n8_copy_to(oarrm1n8_t* arr, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_copy(oarrm1n8_t* arr);
  void oarrm1n8_set_all_r( coeff_t num, oarrm1n8_t* arr);
  void oarrm1n8_set_item_i_r( coeff_t num, uint64_t i, oarrm1n8_t* arr);
  void oarrm1n8_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm1n8_t* arr);
  void oarrm1n8_set_r(   coeff_t  num,   oarrm1n8_t* arr);
  void oarrm1n8_set_o( onumm1n8_t* num,   oarrm1n8_t* arr);
  void oarrm1n8_set_O(   oarrm1n8_t* arrin, oarrm1n8_t* arr);
  void oarrm1n8_set_all_o( onumm1n8_t* src, oarrm1n8_t* arr);
  void oarrm1n8_set_item_i_o( onumm1n8_t* num, uint64_t i, oarrm1n8_t* arr);
  void oarrm1n8_set_item_ij_o( onumm1n8_t* num, uint64_t i, uint64_t j, oarrm1n8_t* arr);
  onumm1n8_t oarrm1n8_get_item_i(    oarrm1n8_t* arr, uint64_t i);
  void      oarrm1n8_get_item_i_to( oarrm1n8_t* arr, uint64_t i,             onumm1n8_t* res);
  onumm1n8_t oarrm1n8_get_item_ij(   oarrm1n8_t* arr, uint64_t i, uint64_t j);
  void      oarrm1n8_get_item_ij_to(oarrm1n8_t* arr, uint64_t i, uint64_t j, onumm1n8_t* res);
  oarrm1n8_t oarrm1n8_init();
  void oarrm1n8_free(oarrm1n8_t* arr);
  oarrm1n8_t oarrm1n8_empty_like(oarrm1n8_t* arr);
  oarrm1n8_t oarrm1n8_eye(uint64_t nrows);
  oarrm1n8_t oarrm1n8_ones(uint64_t nrows, uint64_t ncols);
  oarrm1n8_t oarrm1n8_zeros(uint64_t nrows, uint64_t ncols);
  oarrm1n8_t oarrm1n8_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm1n8/array/utils.h
  
  void oarrm1n8_dimCheck_OO_elementwise(oarrm1n8_t* arr1, oarrm1n8_t* arr2, oarrm1n8_t* res);
  void oarrm1n8_dimCheck_RO_elementwise(darr_t*  arr1, oarrm1n8_t* arr2, oarrm1n8_t* res);
  void oarrm1n8_dimCheck_OO_matmul(oarrm1n8_t* arr1, oarrm1n8_t* arr2, oarrm1n8_t* res);
  void oarrm1n8_dimCheck_RO_matmul(darr_t*  arr1, oarrm1n8_t* arr2, oarrm1n8_t* res);
  void oarrm1n8_dimCheck_OR_matmul(oarrm1n8_t* arr1, darr_t*  arr2, oarrm1n8_t* res);
  void oarrm1n8_dimCheck_O_squareness(oarrm1n8_t* arr1, oarrm1n8_t* res);
  void oarrm1n8_dimCheck_OO_samesize(oarrm1n8_t* arr1, oarrm1n8_t* res);
  void oarrm1n8_dimCheck_RO_samesize(darr_t* arr1, oarrm1n8_t* res);
  ord_t oarrm1n8_get_order(oarrm1n8_t* arr);
  void oarrm1n8_get_active_bases(oarrm1n8_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n8/array/algebra_matops.h
  
  onumm1n8_t oarrm1n8_dotproduct_OO(    oarrm1n8_t* lhs, oarrm1n8_t* rhs);
  void      oarrm1n8_dotproduct_OO_to( oarrm1n8_t* lhs, oarrm1n8_t* rhs, onumm1n8_t* res);
  onumm1n8_t oarrm1n8_dotproduct_RO(     darr_t* lhs, oarrm1n8_t* rhs);
  void      oarrm1n8_dotproduct_RO_to(  darr_t* lhs, oarrm1n8_t* rhs, onumm1n8_t* res);
  oarrm1n8_t oarrm1n8_matmul_OO(    oarrm1n8_t* lhs, oarrm1n8_t* rhs);
  oarrm1n8_t oarrm1n8_matmul_OR(    oarrm1n8_t* lhs,  darr_t* rhs);
  oarrm1n8_t oarrm1n8_matmul_RO(     darr_t* lhs, oarrm1n8_t* rhs);
  void    oarrm1n8_matmul_OO_to( oarrm1n8_t* lhs, oarrm1n8_t* rhs, oarrm1n8_t* res);
  void    oarrm1n8_matmul_OR_to( oarrm1n8_t* lhs,  darr_t* rhs, oarrm1n8_t* res);
  void    oarrm1n8_matmul_RO_to(  darr_t* lhs, oarrm1n8_t* rhs, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_transpose(    oarrm1n8_t* arr1);
  void    oarrm1n8_transpose_to( oarrm1n8_t* arr1, oarrm1n8_t* res);
  oarrm1n8_t oarrm1n8_invert(    oarrm1n8_t* arr1);
  void    oarrm1n8_invert_to( oarrm1n8_t* arr1, oarrm1n8_t* res);
  onumm1n8_t oarrm1n8_det(    oarrm1n8_t* arr1);
  void      oarrm1n8_det_to( oarrm1n8_t* arr1, onumm1n8_t* res);
  onumm1n8_t oarrm1n8_norm(    oarrm1n8_t* arr1);
  void      oarrm1n8_norm_to( oarrm1n8_t* arr1,  onumm1n8_t* res);
  onumm1n8_t oarrm1n8_pnorm(    oarrm1n8_t* arr1, coeff_t p);
  void      oarrm1n8_pnorm_to( oarrm1n8_t* arr1, coeff_t p, onumm1n8_t* res);
  
  
  # From ../../../include/oti/static/onumm1n8/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm1n8/array/gauss/functions.h
  
  feoarrm1n8_t feoarrm1n8_atanh(    feoarrm1n8_t* arr);
  void      feoarrm1n8_atanh_to( feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_asinh(    feoarrm1n8_t* arr);
  void      feoarrm1n8_asinh_to( feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_acosh(    feoarrm1n8_t* arr);
  void      feoarrm1n8_acosh_to( feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_tanh(     feoarrm1n8_t* arr);
  void      feoarrm1n8_tanh_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sinh(     feoarrm1n8_t* arr);
  void      feoarrm1n8_sinh_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_cosh(     feoarrm1n8_t* arr);
  void      feoarrm1n8_cosh_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_atan(     feoarrm1n8_t* arr);
  void      feoarrm1n8_atan_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_asin(     feoarrm1n8_t* arr);
  void      feoarrm1n8_asin_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_acos(     feoarrm1n8_t* arr);
  void      feoarrm1n8_acos_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_tan(      feoarrm1n8_t* arr);
  void      feoarrm1n8_tan_to(   feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sin(      feoarrm1n8_t* arr);
  void      feoarrm1n8_sin_to(   feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_cos(      feoarrm1n8_t* arr);
  void      feoarrm1n8_cos_to(   feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_logb(     feoarrm1n8_t* arr, double base);
  void      feoarrm1n8_logb_to(  feoarrm1n8_t* arr, double base, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_log10(    feoarrm1n8_t* arr);
  void      feoarrm1n8_log10_to( feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_log(      feoarrm1n8_t* arr);
  void      feoarrm1n8_log_to(   feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_exp(      feoarrm1n8_t* arr);
  void      feoarrm1n8_exp_to(   feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_cbrt(     feoarrm1n8_t* arr);
  void      feoarrm1n8_cbrt_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sqrt(     feoarrm1n8_t* arr);
  void      feoarrm1n8_sqrt_to(  feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_pow(      feoarrm1n8_t* arr, double e);
  void      feoarrm1n8_pow_to(   feoarrm1n8_t* arr, double e, feoarrm1n8_t* res);
  
  
  # From ../../../include/oti/static/onumm1n8/array/gauss/base.h
  
  void      feoarrm1n8_get_order_im_to( ord_t order, feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_get_order_im(    ord_t order, feoarrm1n8_t* arr);
  feoarrm1n8_t feoarrm1n8_get_deriv(   imdir_t idx, ord_t order, feoarrm1n8_t* arr);
  void      feoarrm1n8_get_deriv_to(imdir_t idx, ord_t order, feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_get_im(      imdir_t idx, ord_t order, feoarrm1n8_t* arr);
  void      feoarrm1n8_get_im_to(   imdir_t idx, ord_t order, feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_truncate_im(   imdir_t idx, ord_t order, feoarrm1n8_t* arr);
  void      feoarrm1n8_truncate_im_to(imdir_t idx, ord_t order, feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_copy(   feoarrm1n8_t* src);
  void      feoarrm1n8_copy_to(feoarrm1n8_t* src, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_get_im(    imdir_t idx, ord_t order, feoarrm1n8_t* arr);
  void      feoarrm1n8_get_im_to( imdir_t idx, ord_t order, feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_get_deriv(    imdir_t idx, ord_t order, feoarrm1n8_t* arr);
  void      feoarrm1n8_get_deriv_to( imdir_t idx, ord_t order, feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_extract_im(    imdir_t idx, ord_t order, feoarrm1n8_t* arr);
  void      feoarrm1n8_extract_im_to( imdir_t idx, ord_t order, feoarrm1n8_t* arr,  feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_extract_deriv(    imdir_t idx, ord_t order, feoarrm1n8_t* arr);
  void      feoarrm1n8_extract_deriv_to( imdir_t idx, ord_t order, feoarrm1n8_t* arr, feoarrm1n8_t* res);
  oarrm1n8_t   feoarrm1n8_get_item_k(  feoarrm1n8_t* arr, uint64_t k);
  feonumm1n8_t  feoarrm1n8_get_item_ij( feoarrm1n8_t* arr, uint64_t i, uint64_t j);
  onumm1n8_t feoarrm1n8_get_item_ijk(feoarrm1n8_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm1n8_get_item_ij_to(  feoarrm1n8_t* arr, uint64_t i, uint64_t j,
                                 feonumm1n8_t* res);
  void feoarrm1n8_get_item_k_to(   feoarrm1n8_t* arr, uint64_t k,
                                  oarrm1n8_t* res);
  void feoarrm1n8_get_item_ijk_to( feoarrm1n8_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_get_slice(feoarrm1n8_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm1n8_get_slice_to(feoarrm1n8_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n8_t* res);
  void feoarrm1n8_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm1n8_t* res);
  void feoarrm1n8_set_item_ij_o(  onumm1n8_t* elm, uint64_t i, uint64_t j,
                               feoarrm1n8_t* res);
  void feoarrm1n8_set_item_ij_f(  feonumm1n8_t* elm, uint64_t i, uint64_t j,
                              feoarrm1n8_t* res);
  void feoarrm1n8_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm1n8_t* res);
  void feoarrm1n8_set_item_k_o(  onumm1n8_t* elm, uint64_t k,
                              feoarrm1n8_t* res);
  void feoarrm1n8_set_item_k_R(    oarrm1n8_t* elm, uint64_t k,
                            feoarrm1n8_t* res);
  void feoarrm1n8_set_item_k_O(    oarrm1n8_t* elm, uint64_t k,
                            feoarrm1n8_t* res);
  void feoarrm1n8_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm1n8_t* res);
  void feoarrm1n8_set_item_ijk_o( onumm1n8_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm1n8_t* res);
  void feoarrm1n8_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n8_t* res);
  void feoarrm1n8_set_slice_o( onumm1n8_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n8_t* res);
  void feoarrm1n8_set_slice_f( feonumm1n8_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n8_t* res);
  void feoarrm1n8_set_slice_O( oarrm1n8_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n8_t* res);
  void feoarrm1n8_set_slice_F( feoarrm1n8_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm1n8_t* res);
  void feoarrm1n8_set_all_o( onumm1n8_t* num, feoarrm1n8_t* arr );
  void feoarrm1n8_set_all_r(   coeff_t  num, feoarrm1n8_t* arr );
  void feoarrm1n8_set_all_f(  feonumm1n8_t* num, feoarrm1n8_t* arr );
  void feoarrm1n8_set_r(    coeff_t src, feoarrm1n8_t* res );
  void feoarrm1n8_set_o( onumm1n8_t* src, feoarrm1n8_t* res );
  void feoarrm1n8_set_f(  feonumm1n8_t* src, feoarrm1n8_t* res );
  void feoarrm1n8_set_R(    darr_t* src, feoarrm1n8_t* res );
  void feoarrm1n8_set_O(   oarrm1n8_t* src, feoarrm1n8_t* res );
  void feoarrm1n8_set_F( feoarrm1n8_t* src, feoarrm1n8_t* res );
  feoarrm1n8_t feoarrm1n8_eye( uint64_t size,  uint64_t nip);
  feoarrm1n8_t feoarrm1n8_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm1n8_t feoarrm1n8_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm1n8_t feoarrm1n8_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm1n8_free(feoarrm1n8_t* arr);
  feoarrm1n8_t feoarrm1n8_init();
  ord_t feoarrm1n8_get_order(feoarrm1n8_t* arr);
  
  
  # From ../../../include/oti/static/onumm1n8/array/gauss/utils.h
  
  void feoarrm1n8_dimCheck_FF_samesize(feoarrm1n8_t* arr1, feoarrm1n8_t* arr2, feonumm1n8_t* res);
  void feoarrm1n8_dimCheck_OF_samesize(  oarrm1n8_t* arr1, feoarrm1n8_t* arr2, feonumm1n8_t* res);
  void feoarrm1n8_dimCheck_RF_samesize(   darr_t* arr1, feoarrm1n8_t* arr2, feonumm1n8_t* res);
  void feoarrm1n8_dimCheck_FF_elementwise(feoarrm1n8_t* arr1, feoarrm1n8_t* arr2, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_OF_elementwise(  oarrm1n8_t* arr1, feoarrm1n8_t* arr2, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm1n8_t* arr2, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_fF_elementwise( feonumm1n8_t* num1, feoarrm1n8_t* arr2, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_Ff_elementwise(feoarrm1n8_t* arr1,  feonumm1n8_t* num2, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_FF_matmul( feoarrm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_OF_matmul(   oarrm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_RF_matmul(    darr_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_FO_matmul( feoarrm1n8_t* lhs,   oarrm1n8_t* rhs, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_FR_matmul( feoarrm1n8_t* lhs,    darr_t* rhs, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_F_squareness( feoarrm1n8_t* arr1, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_F_transpose( feoarrm1n8_t* arr1, feoarrm1n8_t* res);
  void feoarrm1n8_dimCheck_FfO_integrate(feoarrm1n8_t* arr, feonumm1n8_t* num,oarrm1n8_t* res);
  void feoarrm1n8_get_active_bases(feoarrm1n8_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm1n8/array/gauss/algebra.h
  
  feoarrm1n8_t feoarrm1n8_neg(    feoarrm1n8_t* arr);
  void      feoarrm1n8_neg_to( feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sum_FF(   feoarrm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sum_FF_to(feoarrm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sum_fF(    feonumm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sum_fF_to( feonumm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sum_OF(     oarrm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sum_OF_to(  oarrm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sum_RF(      darr_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sum_RF_to(   darr_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sum_oF(   onumm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sum_oF_to(onumm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sum_rF(     coeff_t  lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sum_rF_to(  coeff_t  lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sub_FF(    feoarrm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sub_FF_to( feoarrm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sub_fF(    feonumm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sub_fF_to( feonumm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sub_Ff(    feoarrm1n8_t* lhs, feonumm1n8_t* rhs);
  void      feoarrm1n8_sub_Ff_to( feoarrm1n8_t* lhs, feonumm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sub_OF(      oarrm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sub_OF_to(   oarrm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sub_FO(    feoarrm1n8_t* lhs,   oarrm1n8_t* rhs);
  void      feoarrm1n8_sub_FO_to( feoarrm1n8_t* lhs,   oarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sub_RF(       darr_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sub_RF_to(    darr_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sub_FR(    feoarrm1n8_t* lhs,    darr_t* rhs);
  void      feoarrm1n8_sub_FR_to( feoarrm1n8_t* lhs,    darr_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sub_oF(    onumm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sub_oF_to( onumm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sub_Fo(    feoarrm1n8_t* lhs, onumm1n8_t* rhs);
  void      feoarrm1n8_sub_Fo_to( feoarrm1n8_t* lhs, onumm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sub_rF(      coeff_t  lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_sub_rF_to(    coeff_t lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_sub_Fr(    feoarrm1n8_t* lhs,   coeff_t  rhs);
  void      feoarrm1n8_sub_Fr_to( feoarrm1n8_t* lhs,   coeff_t  rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_mul_FF(   feoarrm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_mul_FF_to(feoarrm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_mul_fF(    feonumm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_mul_fF_to( feonumm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_mul_OF(     oarrm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_mul_OF_to(  oarrm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_mul_RF(      darr_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_mul_RF_to(   darr_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_mul_oF(   onumm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_mul_oF_to(onumm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_mul_rF(     coeff_t  lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_mul_rF_to(  coeff_t  lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_div_FF(    feoarrm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_div_FF_to( feoarrm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_div_fF(     feonumm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_div_fF_to(  feonumm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_div_Ff(    feoarrm1n8_t* lhs,  feonumm1n8_t* rhs);
  void      feoarrm1n8_div_Ff_to( feoarrm1n8_t* lhs,  feonumm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_div_OF(      oarrm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_div_OF_to(   oarrm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_div_FO(    feoarrm1n8_t* lhs,   oarrm1n8_t* rhs);
  void      feoarrm1n8_div_FO_to( feoarrm1n8_t* lhs,   oarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_div_RF(       darr_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_div_RF_to(    darr_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_div_FR(    feoarrm1n8_t* lhs,    darr_t* rhs);
  void      feoarrm1n8_div_FR_to( feoarrm1n8_t* lhs,    darr_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_div_oF(    onumm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_div_oF_to( onumm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_div_Fo(    feoarrm1n8_t* lhs, onumm1n8_t* rhs);
  void      feoarrm1n8_div_Fo_to( feoarrm1n8_t* lhs, onumm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_div_rF(      coeff_t  lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_div_rF_to(    coeff_t lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_div_Fr(    feoarrm1n8_t* lhs,   coeff_t  rhs);
  void      feoarrm1n8_div_Fr_to( feoarrm1n8_t* lhs,   coeff_t  rhs, feoarrm1n8_t* res);
  oarrm1n8_t feoarrm1n8_integrate(    feoarrm1n8_t* arr, feonumm1n8_t* w);
  void    feoarrm1n8_integrate_to( feoarrm1n8_t* arr, feonumm1n8_t* w, oarrm1n8_t* res);
  feonumm1n8_t feoarrm1n8_dotproduct_FF(    feoarrm1n8_t* lhs, feoarrm1n8_t* rhs);
  void     feoarrm1n8_dotproduct_FF_to( feoarrm1n8_t* lhs, feoarrm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feoarrm1n8_dotproduct_OF(      oarrm1n8_t* lhs, feoarrm1n8_t* rhs);
  void     feoarrm1n8_dotproduct_OF_to(   oarrm1n8_t* lhs, feoarrm1n8_t* rhs, feonumm1n8_t* res);
  feonumm1n8_t feoarrm1n8_dotproduct_RF(       darr_t* lhs, feoarrm1n8_t* rhs);
  void     feoarrm1n8_dotproduct_RF_to(    darr_t* lhs, feoarrm1n8_t* rhs, feonumm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_matmul_FF(    feoarrm1n8_t* lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_matmul_FF_to( feoarrm1n8_t* lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_matmul_OF(    oarrm1n8_t*   lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_matmul_OF_to( oarrm1n8_t*   lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_matmul_FO(    feoarrm1n8_t* lhs, oarrm1n8_t*   rhs);
  void      feoarrm1n8_matmul_FO_to( feoarrm1n8_t* lhs, oarrm1n8_t*   rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_matmul_RF(    darr_t*    lhs, feoarrm1n8_t* rhs);
  void      feoarrm1n8_matmul_RF_to( darr_t*    lhs, feoarrm1n8_t* rhs, feoarrm1n8_t* res);
  feoarrm1n8_t feoarrm1n8_matmul_FR(    feoarrm1n8_t* lhs, darr_t*    rhs);
  void      feoarrm1n8_matmul_FR_to( feoarrm1n8_t* lhs, darr_t*    rhs, feoarrm1n8_t* res);
  feonumm1n8_t feoarrm1n8_det(   feoarrm1n8_t* arr);
  void     feoarrm1n8_det_to(feoarrm1n8_t* arr, feonumm1n8_t* res);
  feonumm1n8_t feoarrm1n8_norm(     feoarrm1n8_t* arr);
  void     feoarrm1n8_norm_to(  feoarrm1n8_t* arr, feonumm1n8_t* res);
  feonumm1n8_t feoarrm1n8_pnorm(    feoarrm1n8_t* arr, coeff_t p);
  void     feoarrm1n8_pnorm_to( feoarrm1n8_t* arr, coeff_t p, feonumm1n8_t* res);
  feoarrm1n8_t   feoarrm1n8_invert(    feoarrm1n8_t* arr);
  void        feoarrm1n8_invert_to( feoarrm1n8_t* arr, feoarrm1n8_t* res);
  feoarrm1n8_t   feoarrm1n8_transpose(   feoarrm1n8_t* arr);
  void        feoarrm1n8_transpose_to(feoarrm1n8_t* arr, feoarrm1n8_t* res);
  
  