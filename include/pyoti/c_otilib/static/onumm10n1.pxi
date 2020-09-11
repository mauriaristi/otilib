cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm10n1/scalar/structures.h
  
  ctypedef struct  onumm10n1_t : # {
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
  # } onumm10n1_t;
  
  
  # From ../../../include/oti/static/onumm10n1/array/structures.h
  
  ctypedef struct  oarrm10n1_t : # {
      onumm10n1_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm10n1_t;
  
  
  # From ../../../include/oti/static/onumm10n1/scalar/gauss/structures.h
  
  ctypedef struct  feonumm10n1_t: # {
      onumm10n1_t*  p_data;
      uint64_t    nip;
  # } feonumm10n1_t;
  
  
  # From ../../../include/oti/static/onumm10n1/array/gauss/structures.h
  
  ctypedef struct  feoarrm10n1_t: # {
      oarrm10n1_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm10n1_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm10n1/scalar/functions.h
  
  onumm10n1_t onumm10n1_atanh(onumm10n1_t* num);
  void onumm10n1_atanh_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_asinh(onumm10n1_t* num);
  void onumm10n1_asinh_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_acosh(onumm10n1_t* num);
  void onumm10n1_acosh_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_tanh(onumm10n1_t* num);
  void onumm10n1_tanh_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_sqrt(onumm10n1_t* num);
  void onumm10n1_sqrt_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_cbrt(onumm10n1_t* num);
  void onumm10n1_cbrt_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_cosh(onumm10n1_t* num);
  void onumm10n1_cosh_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_sinh(onumm10n1_t* num);
  void onumm10n1_sinh_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_asin(onumm10n1_t* num);
  void onumm10n1_asin_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_acos(onumm10n1_t* num);
  void onumm10n1_acos_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_atan(onumm10n1_t* num);
  void onumm10n1_atan_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_tan(onumm10n1_t* num);
  void onumm10n1_tan_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_cos(onumm10n1_t* num);
  void onumm10n1_cos_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_sin(onumm10n1_t* num );
  void onumm10n1_sin_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_logb(onumm10n1_t* num, double base);
  void onumm10n1_logb_to(onumm10n1_t* num, double base, onumm10n1_t* res);
  onumm10n1_t onumm10n1_log10(onumm10n1_t* num);
  void onumm10n1_log10_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_log(onumm10n1_t* num);
  void onumm10n1_log_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_exp(onumm10n1_t* num);
  void onumm10n1_exp_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_pow(onumm10n1_t* num, double e);
  void onumm10n1_pow_to(onumm10n1_t* num, coeff_t e, onumm10n1_t* res);
  
  
  # From ../../../include/oti/static/onumm10n1/scalar/base.h
  
  void onumm10n1_set_im_o(onumm10n1_t* num, imdir_t idx, ord_t order, onumm10n1_t* res);
  void onumm10n1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm10n1_t* res);
  void onumm10n1_set_deriv_o(onumm10n1_t* num, imdir_t idx, ord_t order, onumm10n1_t* res);
  void onumm10n1_extract_im_to( imdir_t idx, ord_t order, onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_extract_im(imdir_t idx, ord_t order, onumm10n1_t* num);
  onumm10n1_t onumm10n1_extract_deriv(imdir_t idx, ord_t order, onumm10n1_t* num);
  void onumm10n1_extract_deriv_to(imdir_t idx, ord_t order, onumm10n1_t* num, onumm10n1_t* res);
  void onumm10n1_get_im_to_o(imdir_t idx, ord_t order, onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_get_im_o(imdir_t idx, ord_t order, onumm10n1_t* num);
  void onumm10n1_get_im_to_r(imdir_t idx, ord_t order, onumm10n1_t* num, coeff_t* res);
  ord_t onumm10n1_get_order(onumm10n1_t* lhs);
  onumm10n1_t onumm10n1_get_deriv_o( imdir_t idx, ord_t order, onumm10n1_t* num);
  void onumm10n1_get_deriv_to( imdir_t idx, ord_t order, onumm10n1_t* num, onumm10n1_t* res);
  void onumm10n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm10n1_t* res);
  onumm10n1_t onumm10n1_init();
  ndir_t onumm10n1_get_ndir_order(ord_t order, onumm10n1_t* num);
  ndir_t onumm10n1_get_ndir_total(onumm10n1_t* num);
  coeff_t* onumm10n1_get_order_address(ord_t order, onumm10n1_t* num);
  onumm10n1_t onumm10n1_create_r(  coeff_t lhs);
  void onumm10n1_set_r(  coeff_t lhs, onumm10n1_t* res);
  void onumm10n1_set_o(  onumm10n1_t* lhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_get_order_im(ord_t order, onumm10n1_t* lhs);
  void onumm10n1_get_order_im_to(ord_t order, onumm10n1_t* lhs, onumm10n1_t* res);
  coeff_t onumm10n1_get_item(imdir_t idx, ord_t order, onumm10n1_t* lhs);
  coeff_t onumm10n1_get_deriv(imdir_t idx, ord_t order, onumm10n1_t* lhs);
  void onumm10n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm10n1_t* x);
  onumm10n1_t onumm10n1_copy(  onumm10n1_t* lhs);
  void onumm10n1_copy_to(  onumm10n1_t* lhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_taylor_integrate(coeff_t* deltas,onumm10n1_t* lhs);
  void onumm10n1_taylor_integrate_to(coeff_t* deltas,onumm10n1_t* lhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_truncate_im(imdir_t idx, ord_t order, onumm10n1_t* lhs);
  void onumm10n1_truncate_im_to(imdir_t idx, ord_t order, onumm10n1_t* lhs, onumm10n1_t* res);
  void onumm10n1_print(  onumm10n1_t* lhs);
  imdir_t onumm10n1_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm10n1/scalar/utils.h
  
  void onumm10n1_get_active_bases(onumm10n1_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm10n1/scalar/algebra.h
  
  onumm10n1_t onumm10n1_abs(onumm10n1_t* num);
  onumm10n1_t onumm10n1_div_ro(coeff_t num, onumm10n1_t* den);
  onumm10n1_t onumm10n1_div_oo(onumm10n1_t* num, onumm10n1_t* den);
  onumm10n1_t onumm10n1_div_or(onumm10n1_t* num, coeff_t val);
  void onumm10n1_div_ro_to(coeff_t num, onumm10n1_t* den, onumm10n1_t* res);
  void onumm10n1_div_oo_to(onumm10n1_t* num, onumm10n1_t* den, onumm10n1_t* res);
  void onumm10n1_div_or_to(onumm10n1_t* num, coeff_t val, onumm10n1_t* res);
  void onumm10n1_abs_to(onumm10n1_t* num, onumm10n1_t* res);
  onumm10n1_t onumm10n1_neg(  onumm10n1_t* lhs);
  void onumm10n1_neg_to(  onumm10n1_t* lhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_sum_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs);
  void onumm10n1_sum_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_sum_ro(  coeff_t lhs,  onumm10n1_t* rhs);
  void onumm10n1_sum_ro_to(  coeff_t lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_sub_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs);
  void onumm10n1_sub_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_sub_ro(  coeff_t lhs,  onumm10n1_t* rhs);
  void onumm10n1_sub_ro_to(  coeff_t lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_sub_or(  onumm10n1_t* lhs,  coeff_t rhs);
  void onumm10n1_sub_or_to(  onumm10n1_t* lhs,  coeff_t rhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_mul_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs);
  void onumm10n1_mul_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_mul_ro(  coeff_t lhs,  onumm10n1_t* rhs);
  void onumm10n1_mul_ro_to(  coeff_t lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_trunc_mul_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs);
  void onumm10n1_trunc_mul_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_gem_oo(  onumm10n1_t* a,  onumm10n1_t* b,  onumm10n1_t* c);
  void onumm10n1_gem_oo_to(  onumm10n1_t* a,  onumm10n1_t* b,  onumm10n1_t* c, onumm10n1_t* res);
  onumm10n1_t onumm10n1_gem_ro(  coeff_t a,  onumm10n1_t* b,  onumm10n1_t* c);
  void onumm10n1_gem_ro_to(  coeff_t a,  onumm10n1_t* b,  onumm10n1_t* c, onumm10n1_t* res);
  void onumm10n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm10n1_t* a,  ord_t ord_rhs,  onumm10n1_t* b,  onumm10n1_t* c, onumm10n1_t* res);
  void onumm10n1_trunc_sum_oo_to(ord_t order, onumm10n1_t* lhs,onumm10n1_t* rhs, onumm10n1_t* res);
  void onumm10n1_trunc_sub_oo_to(ord_t order, onumm10n1_t* lhs,onumm10n1_t* rhs, onumm10n1_t* res);
  onumm10n1_t onumm10n1_feval(coeff_t* feval_re, onumm10n1_t* x);
  void onumm10n1_feval_to(coeff_t* feval_re, onumm10n1_t* x, onumm10n1_t* res);
  
  
  # From ../../../include/oti/static/onumm10n1/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm10n1/scalar/gauss/functions.h
  
  feonumm10n1_t feonumm10n1_atanh(    feonumm10n1_t* num);
  void     feonumm10n1_atanh_to( feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_asinh(    feonumm10n1_t* num);
  void     feonumm10n1_asinh_to( feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_acosh(    feonumm10n1_t* num);
  void     feonumm10n1_acosh_to( feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_tanh(     feonumm10n1_t* num);
  void     feonumm10n1_tanh_to(  feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_cosh(     feonumm10n1_t* num);
  void     feonumm10n1_cosh_to(  feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_sinh(     feonumm10n1_t* num);
  void     feonumm10n1_sinh_to(  feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_asin(     feonumm10n1_t* num);
  void     feonumm10n1_asin_to(  feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_acos(     feonumm10n1_t* num);
  void     feonumm10n1_acos_to(  feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_atan(     feonumm10n1_t* num);
  void     feonumm10n1_atan_to(  feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_tan(      feonumm10n1_t* num);
  void     feonumm10n1_tan_to(   feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_cos(      feonumm10n1_t* num);
  void     feonumm10n1_cos_to(   feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_sin(      feonumm10n1_t* num);
  void     feonumm10n1_sin_to(   feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_logb(     feonumm10n1_t* num, double base);
  void     feonumm10n1_logb_to(  feonumm10n1_t* num, double base, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_log10(    feonumm10n1_t* num);
  void     feonumm10n1_log10_to( feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_log(      feonumm10n1_t* num);
  void     feonumm10n1_log_to(   feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_exp(      feonumm10n1_t* num);
  void     feonumm10n1_exp_to(   feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_cbrt(     feonumm10n1_t* num);
  void     feonumm10n1_cbrt_to(  feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_sqrt(     feonumm10n1_t* num);
  void     feonumm10n1_sqrt_to(  feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_pow(      feonumm10n1_t* num, double e);
  void     feonumm10n1_pow_to(   feonumm10n1_t* num, double e, feonumm10n1_t* res);
  onumm10n1_t feonumm10n1_integrate(       feonumm10n1_t* num, feonumm10n1_t* w);
  void      feonumm10n1_integrate_to(    feonumm10n1_t* num, feonumm10n1_t* w, onumm10n1_t* res);
  onumm10n1_t feonumm10n1_integrate_f(     feonumm10n1_t* num, feonumm10n1_t* w);
  void      feonumm10n1_integrate_f_to(  feonumm10n1_t* num, feonumm10n1_t* w, onumm10n1_t* res);
  onumm10n1_t feonumm10n1_integrate_r(       coeff_t num, feonumm10n1_t* w);
  void      feonumm10n1_integrate_r_to(    coeff_t num, feonumm10n1_t* w, onumm10n1_t* res);
  onumm10n1_t feonumm10n1_integrate_o(    onumm10n1_t* num, feonumm10n1_t* w);
  void      feonumm10n1_integrate_o_to( onumm10n1_t* num, feonumm10n1_t* w, onumm10n1_t* res);
  
  
  # From ../../../include/oti/static/onumm10n1/scalar/gauss/base.h
  
  void     feonumm10n1_get_order_im_to( ord_t order, feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_get_order_im(    ord_t order, feonumm10n1_t* num);
  feonumm10n1_t feonumm10n1_get_im(    imdir_t idx, ord_t order, feonumm10n1_t* num);
  void     feonumm10n1_get_im_to( imdir_t idx, ord_t order, feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_get_deriv(    imdir_t idx, ord_t order, feonumm10n1_t* num);
  void     feonumm10n1_get_deriv_to( imdir_t idx, ord_t order, feonumm10n1_t* num, feonumm10n1_t* res);
  void feonumm10n1_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm10n1_t* num);
  void feonumm10n1_set_im_o( onumm10n1_t* val, imdir_t idx, ord_t order, feonumm10n1_t* num);
  void feonumm10n1_set_im_f(  feonumm10n1_t* val, imdir_t idx, ord_t order, feonumm10n1_t* num);
  void feonumm10n1_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm10n1_t* num);
  void feonumm10n1_set_deriv_o( onumm10n1_t* val, imdir_t idx, ord_t order, feonumm10n1_t* num);
  void feonumm10n1_set_deriv_f(  feonumm10n1_t* val, imdir_t idx, ord_t order, feonumm10n1_t* num);
  feonumm10n1_t feonumm10n1_extract_im(    imdir_t idx, ord_t order, feonumm10n1_t* num);
  void     feonumm10n1_extract_im_to( imdir_t idx, ord_t order, feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_extract_deriv(    imdir_t idx, ord_t order, feonumm10n1_t* num);
  void     feonumm10n1_extract_deriv_to( imdir_t idx, ord_t order, feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_truncate_im(    imdir_t idx, ord_t order, feonumm10n1_t* num);
  void     feonumm10n1_truncate_im_to( imdir_t idx, ord_t order, feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_copy(    feonumm10n1_t* src);
  void     feonumm10n1_copy_to( feonumm10n1_t* src, feonumm10n1_t* dst);
  void feonumm10n1_set_r(    coeff_t num, feonumm10n1_t* res);
  void feonumm10n1_set_o( onumm10n1_t* num, feonumm10n1_t* res);
  void feonumm10n1_set_f(  feonumm10n1_t* num, feonumm10n1_t* res);
  void feonumm10n1_set_item_k_r(   coeff_t  num, uint64_t k, feonumm10n1_t* res);
  void feonumm10n1_set_item_k_o( onumm10n1_t* num, uint64_t k, feonumm10n1_t* res);
  onumm10n1_t feonumm10n1_get_item_k(   feonumm10n1_t* num, uint64_t k);
  void      feonumm10n1_get_item_k_to(feonumm10n1_t* num, uint64_t k, onumm10n1_t* res);
  feonumm10n1_t feonumm10n1_zeros(uint64_t nIntPts);
  feonumm10n1_t feonumm10n1_createEmpty(uint64_t nIntPts);
  feonumm10n1_t feonumm10n1_empty_like(feonumm10n1_t* arr);
  void feonumm10n1_free(feonumm10n1_t* num);
  ord_t feonumm10n1_get_order( feonumm10n1_t* num );
  feonumm10n1_t feonumm10n1_init();
  
  
  # From ../../../include/oti/static/onumm10n1/scalar/gauss/utils.h
  
  void feonumm10n1_dimCheck(feonumm10n1_t* arr1,feonumm10n1_t* arr2);
  void feonumm10n1_get_active_bases(feonumm10n1_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm10n1/scalar/gauss/algebra.h
  
  feonumm10n1_t feonumm10n1_neg(   feonumm10n1_t* num);
  void     feonumm10n1_neg_to(feonumm10n1_t* num, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_sum_ff(   feonumm10n1_t* lhs, feonumm10n1_t* rhs);
  void     feonumm10n1_sum_ff_to(feonumm10n1_t* lhs, feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_sum_of(   onumm10n1_t* lhs, feonumm10n1_t* rhs);
  void     feonumm10n1_sum_of_to(onumm10n1_t* lhs, feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_sum_rf(   coeff_t lhs, feonumm10n1_t* rhs);
  void     feonumm10n1_sum_rf_to(coeff_t lhs, feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_sub_ff(     feonumm10n1_t* lhs,  feonumm10n1_t* rhs);
  void     feonumm10n1_sub_ff_to(  feonumm10n1_t* lhs,  feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_sub_of(    onumm10n1_t* lhs,  feonumm10n1_t* rhs);
  void     feonumm10n1_sub_of_to( onumm10n1_t* lhs,  feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_sub_fo(     feonumm10n1_t* lhs, onumm10n1_t* rhs);
  void     feonumm10n1_sub_fo_to(  feonumm10n1_t* lhs, onumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_sub_rf(       coeff_t lhs,  feonumm10n1_t* rhs);
  void     feonumm10n1_sub_rf_to(    coeff_t lhs,  feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_sub_fr(     feonumm10n1_t* lhs,    coeff_t rhs);
  void     feonumm10n1_sub_fr_to(  feonumm10n1_t* lhs,    coeff_t rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_mul_ff(   feonumm10n1_t* lhs, feonumm10n1_t* rhs);
  void     feonumm10n1_mul_ff_to(feonumm10n1_t* lhs, feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_mul_of(   onumm10n1_t* lhs, feonumm10n1_t* rhs);
  void     feonumm10n1_mul_of_to(onumm10n1_t* lhs, feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_mul_rf(   coeff_t lhs, feonumm10n1_t* rhs);
  void     feonumm10n1_mul_rf_to(coeff_t lhs, feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_div_ff(     feonumm10n1_t* lhs,  feonumm10n1_t* rhs);
  void     feonumm10n1_div_ff_to(  feonumm10n1_t* lhs,  feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_div_of(    onumm10n1_t* lhs,  feonumm10n1_t* rhs);
  void     feonumm10n1_div_of_to( onumm10n1_t* lhs,  feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_div_fo(     feonumm10n1_t* lhs, onumm10n1_t* rhs);
  void     feonumm10n1_div_fo_to(  feonumm10n1_t* lhs, onumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_div_rf(       coeff_t lhs,  feonumm10n1_t* rhs);
  void     feonumm10n1_div_rf_to(    coeff_t lhs,  feonumm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feonumm10n1_div_fr(     feonumm10n1_t* lhs,    coeff_t rhs);
  void     feonumm10n1_div_fr_to(  feonumm10n1_t* lhs,    coeff_t rhs, feonumm10n1_t* res);
  
  
  # From ../../../include/oti/static/onumm10n1/array/functions.h
  
  oarrm10n1_t oarrm10n1_atanh(   oarrm10n1_t* arr);
  void    oarrm10n1_atanh_to(oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_asinh(   oarrm10n1_t* arr);
  void    oarrm10n1_asinh_to(oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_acosh(   oarrm10n1_t* arr);
  void    oarrm10n1_acosh_to(oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_tanh(    oarrm10n1_t* arr);
  void    oarrm10n1_tanh_to( oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_cbrt(    oarrm10n1_t* arr);
  void    oarrm10n1_cbrt_to( oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_sqrt(    oarrm10n1_t* arr);
  void    oarrm10n1_sqrt_to( oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_cosh(    oarrm10n1_t* arr);
  void    oarrm10n1_cosh_to( oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_sinh(    oarrm10n1_t* arr);
  void    oarrm10n1_sinh_to( oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_asin(    oarrm10n1_t* arr);
  void    oarrm10n1_asin_to( oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_acos(    oarrm10n1_t* arr);
  void    oarrm10n1_acos_to( oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_atan(    oarrm10n1_t* arr);
  void    oarrm10n1_atan_to( oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_tan(     oarrm10n1_t* arr);
  void    oarrm10n1_tan_to(  oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_cos(     oarrm10n1_t* arr);
  void    oarrm10n1_cos_to(  oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_sin(     oarrm10n1_t* arr);
  void    oarrm10n1_sin_to(  oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_logb(    oarrm10n1_t* arr, double base);
  void    oarrm10n1_logb_to( oarrm10n1_t* arr, double base, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_log10(   oarrm10n1_t* arr);
  void    oarrm10n1_log10_to(oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_log(     oarrm10n1_t* arr);
  void    oarrm10n1_log_to(  oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_exp(     oarrm10n1_t* arr);
  void    oarrm10n1_exp_to(  oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_pow(     oarrm10n1_t* arr, double e);
  void    oarrm10n1_pow_to(  oarrm10n1_t* arr, double e, oarrm10n1_t* res);
  
  
  # From ../../../include/oti/static/onumm10n1/array/algebra_elementwise.h
  
  oarrm10n1_t oarrm10n1_neg(oarrm10n1_t* arr);
  void oarrm10n1_neg_to(oarrm10n1_t* rhs, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_sum_OO(oarrm10n1_t*   lhs, oarrm10n1_t* rhs);
  oarrm10n1_t oarrm10n1_sum_RO(darr_t*    lhs, oarrm10n1_t* rhs);
  oarrm10n1_t oarrm10n1_sum_oO(onumm10n1_t* lhs, oarrm10n1_t* rhs);
  oarrm10n1_t oarrm10n1_sum_rO(coeff_t    lhs, oarrm10n1_t* rhs);
  void oarrm10n1_sum_OO_to(oarrm10n1_t*   lhs, oarrm10n1_t* rhs, oarrm10n1_t* res);
  void oarrm10n1_sum_RO_to(darr_t*    lhs, oarrm10n1_t* rhs, oarrm10n1_t* res);
  void oarrm10n1_sum_oO_to(onumm10n1_t* lhs, oarrm10n1_t* rhs, oarrm10n1_t* res);
  void oarrm10n1_sum_rO_to(coeff_t    lhs, oarrm10n1_t* rhs, oarrm10n1_t* res);
  void oarrm10n1_trunc_sum_OO_to(ord_t order, oarrm10n1_t* arr1, oarrm10n1_t* arr2, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_sub_OO(oarrm10n1_t*   lhs, oarrm10n1_t*   rhs);
  oarrm10n1_t oarrm10n1_sub_RO(darr_t*    lhs, oarrm10n1_t*   rhs);
  oarrm10n1_t oarrm10n1_sub_OR(oarrm10n1_t*   lhs, darr_t*    rhs);
  oarrm10n1_t oarrm10n1_sub_oO(onumm10n1_t* lhs, oarrm10n1_t*   rhs);
  oarrm10n1_t oarrm10n1_sub_Oo(oarrm10n1_t*   lhs, onumm10n1_t* rhs);
  oarrm10n1_t oarrm10n1_sub_rO(coeff_t    lhs, oarrm10n1_t*   rhs);
  oarrm10n1_t oarrm10n1_sub_Or(oarrm10n1_t*   lhs, coeff_t    rhs);
  void oarrm10n1_sub_OO_to( oarrm10n1_t*   lhs, oarrm10n1_t*   rhs, oarrm10n1_t* res);
  void oarrm10n1_sub_RO_to( darr_t*    lhs, oarrm10n1_t*   rhs, oarrm10n1_t* res);
  void oarrm10n1_sub_OR_to( oarrm10n1_t*   lhs, darr_t*    rhs, oarrm10n1_t* res);
  void oarrm10n1_sub_oO_to( onumm10n1_t* lhs, oarrm10n1_t*   rhs, oarrm10n1_t* res);
  void oarrm10n1_sub_Oo_to( oarrm10n1_t*   lhs, onumm10n1_t* rhs, oarrm10n1_t* res);
  void oarrm10n1_sub_rO_to( coeff_t    lhs, oarrm10n1_t*   rhs, oarrm10n1_t* res);
  void oarrm10n1_sub_Or_to( oarrm10n1_t*   lhs, coeff_t    rhs, oarrm10n1_t* res);
  void oarrm10n1_trunc_sub_OO_to(ord_t order, oarrm10n1_t* arr1, oarrm10n1_t* arr2, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_mul_OO(oarrm10n1_t*   lhs, oarrm10n1_t* rhs);
  oarrm10n1_t oarrm10n1_mul_RO(darr_t*    lhs, oarrm10n1_t* rhs);
  oarrm10n1_t oarrm10n1_mul_oO(onumm10n1_t* lhs, oarrm10n1_t* rhs);
  oarrm10n1_t oarrm10n1_mul_rO(coeff_t    lhs, oarrm10n1_t* rhs);
  void oarrm10n1_mul_OO_to(oarrm10n1_t*   lhs, oarrm10n1_t* rhs, oarrm10n1_t* res);
  void oarrm10n1_mul_RO_to(darr_t*    lhs, oarrm10n1_t* rhs, oarrm10n1_t* res);
  void oarrm10n1_mul_oO_to(onumm10n1_t* lhs, oarrm10n1_t* rhs, oarrm10n1_t* res);
  void oarrm10n1_mul_rO_to(coeff_t    lhs, oarrm10n1_t* rhs, oarrm10n1_t* res);
  void oarrm10n1_gem_OO_to(  oarrm10n1_t* arr1, oarrm10n1_t* arr2, oarrm10n1_t* arr3, oarrm10n1_t* res);
  void oarrm10n1_gem_oO_to(onumm10n1_t* arr1, oarrm10n1_t* arr2, oarrm10n1_t* arr3, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_div_OO(oarrm10n1_t*   lhs, oarrm10n1_t*   rhs);
  oarrm10n1_t oarrm10n1_div_OR(oarrm10n1_t*   lhs, darr_t*    rhs);
  oarrm10n1_t oarrm10n1_div_RO(darr_t*    lhs, oarrm10n1_t*   rhs);
  oarrm10n1_t oarrm10n1_div_oO(onumm10n1_t* lhs, oarrm10n1_t*   rhs);
  oarrm10n1_t oarrm10n1_div_Oo(oarrm10n1_t*   lhs, onumm10n1_t* rhs);
  oarrm10n1_t oarrm10n1_div_rO(coeff_t    lhs, oarrm10n1_t*   rhs);
  oarrm10n1_t oarrm10n1_div_Or(oarrm10n1_t*   lhs, coeff_t    rhs);
  void oarrm10n1_div_OO_to(oarrm10n1_t*   lhs, oarrm10n1_t*   rhs, oarrm10n1_t* res);
  void oarrm10n1_div_RO_to(darr_t*    lhs, oarrm10n1_t*   rhs, oarrm10n1_t* res);
  void oarrm10n1_div_OR_to(oarrm10n1_t*   lhs, darr_t*    rhs, oarrm10n1_t* res);
  void oarrm10n1_div_oO_to(onumm10n1_t* lhs, oarrm10n1_t*   rhs, oarrm10n1_t* res);
  void oarrm10n1_div_Oo_to(oarrm10n1_t*   lhs, onumm10n1_t* rhs, oarrm10n1_t* res);
  void oarrm10n1_div_rO_to(coeff_t    lhs, oarrm10n1_t*   rhs, oarrm10n1_t* res);
  void oarrm10n1_div_Or_to(oarrm10n1_t*   lhs, coeff_t    rhs, oarrm10n1_t* res);
  
  
  # From ../../../include/oti/static/onumm10n1/array/base.h
  
  void    oarrm10n1_taylor_integrate_to( coeff_t* deltas, oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_taylor_integrate(    coeff_t* deltas, oarrm10n1_t* arr);
  void    oarrm10n1_get_order_im_to( ord_t order, oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_get_order_im(    ord_t order, oarrm10n1_t* arr);
  void oarrm10n1_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm10n1_t* res);
  void oarrm10n1_set_slice_O( oarrm10n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm10n1_t* res);
  void oarrm10n1_set_slice_o( onumm10n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_get_slice( oarrm10n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm10n1_get_slice_to( oarrm10n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_truncate_im(    imdir_t idx, ord_t order, oarrm10n1_t* arr);
  void    oarrm10n1_truncate_im_to( imdir_t idx, ord_t order, oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_extract_im(   imdir_t idx, ord_t order, oarrm10n1_t* arr);
  void    oarrm10n1_extract_im_to(imdir_t idx, ord_t order, oarrm10n1_t* arr, oarrm10n1_t* res);
  darr_t  oarrm10n1_get_deriv(    imdir_t idx, ord_t order, oarrm10n1_t* arr);
  void    oarrm10n1_get_deriv_to( imdir_t idx, ord_t order, oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_get_deriv_o(  imdir_t idx, ord_t order, oarrm10n1_t* arr);
  oarrm10n1_t oarrm10n1_extract_deriv(    imdir_t idx, ord_t order, oarrm10n1_t* arr);
  void    oarrm10n1_extract_deriv_to( imdir_t idx, ord_t order, oarrm10n1_t* arr, oarrm10n1_t* res);
  darr_t  oarrm10n1_get_im(   imdir_t idx, ord_t order, oarrm10n1_t* arr);
  oarrm10n1_t oarrm10n1_get_im_o( imdir_t idx, ord_t order, oarrm10n1_t* arr);
  void    oarrm10n1_get_im_to(imdir_t idx, ord_t order, oarrm10n1_t* arr, oarrm10n1_t* res);
  void    oarrm10n1_copy_to(oarrm10n1_t* arr, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_copy(oarrm10n1_t* arr);
  void oarrm10n1_set_all_r( coeff_t num, oarrm10n1_t* arr);
  void oarrm10n1_set_item_i_r( coeff_t num, uint64_t i, oarrm10n1_t* arr);
  void oarrm10n1_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm10n1_t* arr);
  void oarrm10n1_set_r(   coeff_t  num,   oarrm10n1_t* arr);
  void oarrm10n1_set_o( onumm10n1_t* num,   oarrm10n1_t* arr);
  void oarrm10n1_set_O(   oarrm10n1_t* arrin, oarrm10n1_t* arr);
  void oarrm10n1_set_all_o( onumm10n1_t* src, oarrm10n1_t* arr);
  void oarrm10n1_set_item_i_o( onumm10n1_t* num, uint64_t i, oarrm10n1_t* arr);
  void oarrm10n1_set_item_ij_o( onumm10n1_t* num, uint64_t i, uint64_t j, oarrm10n1_t* arr);
  onumm10n1_t oarrm10n1_get_item_i(    oarrm10n1_t* arr, uint64_t i);
  void      oarrm10n1_get_item_i_to( oarrm10n1_t* arr, uint64_t i,             onumm10n1_t* res);
  onumm10n1_t oarrm10n1_get_item_ij(   oarrm10n1_t* arr, uint64_t i, uint64_t j);
  void      oarrm10n1_get_item_ij_to(oarrm10n1_t* arr, uint64_t i, uint64_t j, onumm10n1_t* res);
  oarrm10n1_t oarrm10n1_init();
  void oarrm10n1_free(oarrm10n1_t* arr);
  oarrm10n1_t oarrm10n1_empty_like(oarrm10n1_t* arr);
  oarrm10n1_t oarrm10n1_eye(uint64_t nrows);
  oarrm10n1_t oarrm10n1_ones(uint64_t nrows, uint64_t ncols);
  oarrm10n1_t oarrm10n1_zeros(uint64_t nrows, uint64_t ncols);
  oarrm10n1_t oarrm10n1_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm10n1/array/utils.h
  
  void oarrm10n1_dimCheck_OO_elementwise(oarrm10n1_t* arr1, oarrm10n1_t* arr2, oarrm10n1_t* res);
  void oarrm10n1_dimCheck_RO_elementwise(darr_t*  arr1, oarrm10n1_t* arr2, oarrm10n1_t* res);
  void oarrm10n1_dimCheck_OO_matmul(oarrm10n1_t* arr1, oarrm10n1_t* arr2, oarrm10n1_t* res);
  void oarrm10n1_dimCheck_RO_matmul(darr_t*  arr1, oarrm10n1_t* arr2, oarrm10n1_t* res);
  void oarrm10n1_dimCheck_OR_matmul(oarrm10n1_t* arr1, darr_t*  arr2, oarrm10n1_t* res);
  void oarrm10n1_dimCheck_O_squareness(oarrm10n1_t* arr1, oarrm10n1_t* res);
  void oarrm10n1_dimCheck_OO_samesize(oarrm10n1_t* arr1, oarrm10n1_t* res);
  void oarrm10n1_dimCheck_RO_samesize(darr_t* arr1, oarrm10n1_t* res);
  ord_t oarrm10n1_get_order(oarrm10n1_t* arr);
  void oarrm10n1_get_active_bases(oarrm10n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm10n1/array/algebra_matops.h
  
  onumm10n1_t oarrm10n1_dotproduct_OO(    oarrm10n1_t* lhs, oarrm10n1_t* rhs);
  void      oarrm10n1_dotproduct_OO_to( oarrm10n1_t* lhs, oarrm10n1_t* rhs, onumm10n1_t* res);
  onumm10n1_t oarrm10n1_dotproduct_RO(     darr_t* lhs, oarrm10n1_t* rhs);
  void      oarrm10n1_dotproduct_RO_to(  darr_t* lhs, oarrm10n1_t* rhs, onumm10n1_t* res);
  oarrm10n1_t oarrm10n1_matmul_OO(    oarrm10n1_t* lhs, oarrm10n1_t* rhs);
  oarrm10n1_t oarrm10n1_matmul_OR(    oarrm10n1_t* lhs,  darr_t* rhs);
  oarrm10n1_t oarrm10n1_matmul_RO(     darr_t* lhs, oarrm10n1_t* rhs);
  void    oarrm10n1_matmul_OO_to( oarrm10n1_t* lhs, oarrm10n1_t* rhs, oarrm10n1_t* res);
  void    oarrm10n1_matmul_OR_to( oarrm10n1_t* lhs,  darr_t* rhs, oarrm10n1_t* res);
  void    oarrm10n1_matmul_RO_to(  darr_t* lhs, oarrm10n1_t* rhs, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_transpose(    oarrm10n1_t* arr1);
  void    oarrm10n1_transpose_to( oarrm10n1_t* arr1, oarrm10n1_t* res);
  oarrm10n1_t oarrm10n1_invert(    oarrm10n1_t* arr1);
  void    oarrm10n1_invert_to( oarrm10n1_t* arr1, oarrm10n1_t* res);
  onumm10n1_t oarrm10n1_det(    oarrm10n1_t* arr1);
  void      oarrm10n1_det_to( oarrm10n1_t* arr1, onumm10n1_t* res);
  onumm10n1_t oarrm10n1_norm(    oarrm10n1_t* arr1);
  void      oarrm10n1_norm_to( oarrm10n1_t* arr1,  onumm10n1_t* res);
  onumm10n1_t oarrm10n1_pnorm(    oarrm10n1_t* arr1, coeff_t p);
  void      oarrm10n1_pnorm_to( oarrm10n1_t* arr1, coeff_t p, onumm10n1_t* res);
  
  
  # From ../../../include/oti/static/onumm10n1/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm10n1/array/gauss/functions.h
  
  feoarrm10n1_t feoarrm10n1_atanh(    feoarrm10n1_t* arr);
  void      feoarrm10n1_atanh_to( feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_asinh(    feoarrm10n1_t* arr);
  void      feoarrm10n1_asinh_to( feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_acosh(    feoarrm10n1_t* arr);
  void      feoarrm10n1_acosh_to( feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_tanh(     feoarrm10n1_t* arr);
  void      feoarrm10n1_tanh_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sinh(     feoarrm10n1_t* arr);
  void      feoarrm10n1_sinh_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_cosh(     feoarrm10n1_t* arr);
  void      feoarrm10n1_cosh_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_atan(     feoarrm10n1_t* arr);
  void      feoarrm10n1_atan_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_asin(     feoarrm10n1_t* arr);
  void      feoarrm10n1_asin_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_acos(     feoarrm10n1_t* arr);
  void      feoarrm10n1_acos_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_tan(      feoarrm10n1_t* arr);
  void      feoarrm10n1_tan_to(   feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sin(      feoarrm10n1_t* arr);
  void      feoarrm10n1_sin_to(   feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_cos(      feoarrm10n1_t* arr);
  void      feoarrm10n1_cos_to(   feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_logb(     feoarrm10n1_t* arr, double base);
  void      feoarrm10n1_logb_to(  feoarrm10n1_t* arr, double base, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_log10(    feoarrm10n1_t* arr);
  void      feoarrm10n1_log10_to( feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_log(      feoarrm10n1_t* arr);
  void      feoarrm10n1_log_to(   feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_exp(      feoarrm10n1_t* arr);
  void      feoarrm10n1_exp_to(   feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_cbrt(     feoarrm10n1_t* arr);
  void      feoarrm10n1_cbrt_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sqrt(     feoarrm10n1_t* arr);
  void      feoarrm10n1_sqrt_to(  feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_pow(      feoarrm10n1_t* arr, double e);
  void      feoarrm10n1_pow_to(   feoarrm10n1_t* arr, double e, feoarrm10n1_t* res);
  
  
  # From ../../../include/oti/static/onumm10n1/array/gauss/base.h
  
  void      feoarrm10n1_get_order_im_to( ord_t order, feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_get_order_im(    ord_t order, feoarrm10n1_t* arr);
  feoarrm10n1_t feoarrm10n1_get_deriv(   imdir_t idx, ord_t order, feoarrm10n1_t* arr);
  void      feoarrm10n1_get_deriv_to(imdir_t idx, ord_t order, feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_get_im(      imdir_t idx, ord_t order, feoarrm10n1_t* arr);
  void      feoarrm10n1_get_im_to(   imdir_t idx, ord_t order, feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_truncate_im(   imdir_t idx, ord_t order, feoarrm10n1_t* arr);
  void      feoarrm10n1_truncate_im_to(imdir_t idx, ord_t order, feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_copy(   feoarrm10n1_t* src);
  void      feoarrm10n1_copy_to(feoarrm10n1_t* src, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_get_im(    imdir_t idx, ord_t order, feoarrm10n1_t* arr);
  void      feoarrm10n1_get_im_to( imdir_t idx, ord_t order, feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_get_deriv(    imdir_t idx, ord_t order, feoarrm10n1_t* arr);
  void      feoarrm10n1_get_deriv_to( imdir_t idx, ord_t order, feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_extract_im(    imdir_t idx, ord_t order, feoarrm10n1_t* arr);
  void      feoarrm10n1_extract_im_to( imdir_t idx, ord_t order, feoarrm10n1_t* arr,  feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_extract_deriv(    imdir_t idx, ord_t order, feoarrm10n1_t* arr);
  void      feoarrm10n1_extract_deriv_to( imdir_t idx, ord_t order, feoarrm10n1_t* arr, feoarrm10n1_t* res);
  oarrm10n1_t   feoarrm10n1_get_item_k(  feoarrm10n1_t* arr, uint64_t k);
  feonumm10n1_t  feoarrm10n1_get_item_ij( feoarrm10n1_t* arr, uint64_t i, uint64_t j);
  onumm10n1_t feoarrm10n1_get_item_ijk(feoarrm10n1_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm10n1_get_item_ij_to(  feoarrm10n1_t* arr, uint64_t i, uint64_t j,
                                 feonumm10n1_t* res);
  void feoarrm10n1_get_item_k_to(   feoarrm10n1_t* arr, uint64_t k,
                                  oarrm10n1_t* res);
  void feoarrm10n1_get_item_ijk_to( feoarrm10n1_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_get_slice(feoarrm10n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm10n1_get_slice_to(feoarrm10n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n1_t* res);
  void feoarrm10n1_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm10n1_t* res);
  void feoarrm10n1_set_item_ij_o(  onumm10n1_t* elm, uint64_t i, uint64_t j,
                               feoarrm10n1_t* res);
  void feoarrm10n1_set_item_ij_f(  feonumm10n1_t* elm, uint64_t i, uint64_t j,
                              feoarrm10n1_t* res);
  void feoarrm10n1_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm10n1_t* res);
  void feoarrm10n1_set_item_k_o(  onumm10n1_t* elm, uint64_t k,
                              feoarrm10n1_t* res);
  void feoarrm10n1_set_item_k_R(    oarrm10n1_t* elm, uint64_t k,
                            feoarrm10n1_t* res);
  void feoarrm10n1_set_item_k_O(    oarrm10n1_t* elm, uint64_t k,
                            feoarrm10n1_t* res);
  void feoarrm10n1_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm10n1_t* res);
  void feoarrm10n1_set_item_ijk_o( onumm10n1_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm10n1_t* res);
  void feoarrm10n1_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n1_t* res);
  void feoarrm10n1_set_slice_o( onumm10n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n1_t* res);
  void feoarrm10n1_set_slice_f( feonumm10n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n1_t* res);
  void feoarrm10n1_set_slice_O( oarrm10n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n1_t* res);
  void feoarrm10n1_set_slice_F( feoarrm10n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm10n1_t* res);
  void feoarrm10n1_set_all_o( onumm10n1_t* num, feoarrm10n1_t* arr );
  void feoarrm10n1_set_all_r(   coeff_t  num, feoarrm10n1_t* arr );
  void feoarrm10n1_set_all_f(  feonumm10n1_t* num, feoarrm10n1_t* arr );
  void feoarrm10n1_set_r(    coeff_t src, feoarrm10n1_t* res );
  void feoarrm10n1_set_o( onumm10n1_t* src, feoarrm10n1_t* res );
  void feoarrm10n1_set_f(  feonumm10n1_t* src, feoarrm10n1_t* res );
  void feoarrm10n1_set_R(    darr_t* src, feoarrm10n1_t* res );
  void feoarrm10n1_set_O(   oarrm10n1_t* src, feoarrm10n1_t* res );
  void feoarrm10n1_set_F( feoarrm10n1_t* src, feoarrm10n1_t* res );
  feoarrm10n1_t feoarrm10n1_eye( uint64_t size,  uint64_t nip);
  feoarrm10n1_t feoarrm10n1_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm10n1_t feoarrm10n1_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm10n1_t feoarrm10n1_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm10n1_free(feoarrm10n1_t* arr);
  feoarrm10n1_t feoarrm10n1_init();
  ord_t feoarrm10n1_get_order(feoarrm10n1_t* arr);
  
  
  # From ../../../include/oti/static/onumm10n1/array/gauss/utils.h
  
  void feoarrm10n1_dimCheck_FF_samesize(feoarrm10n1_t* arr1, feoarrm10n1_t* arr2, feonumm10n1_t* res);
  void feoarrm10n1_dimCheck_OF_samesize(  oarrm10n1_t* arr1, feoarrm10n1_t* arr2, feonumm10n1_t* res);
  void feoarrm10n1_dimCheck_RF_samesize(   darr_t* arr1, feoarrm10n1_t* arr2, feonumm10n1_t* res);
  void feoarrm10n1_dimCheck_FF_elementwise(feoarrm10n1_t* arr1, feoarrm10n1_t* arr2, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_OF_elementwise(  oarrm10n1_t* arr1, feoarrm10n1_t* arr2, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm10n1_t* arr2, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_fF_elementwise( feonumm10n1_t* num1, feoarrm10n1_t* arr2, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_Ff_elementwise(feoarrm10n1_t* arr1,  feonumm10n1_t* num2, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_FF_matmul( feoarrm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_OF_matmul(   oarrm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_FO_matmul( feoarrm10n1_t* lhs,   oarrm10n1_t* rhs, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_FR_matmul( feoarrm10n1_t* lhs,    darr_t* rhs, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_F_squareness( feoarrm10n1_t* arr1, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_F_transpose( feoarrm10n1_t* arr1, feoarrm10n1_t* res);
  void feoarrm10n1_dimCheck_FfO_integrate(feoarrm10n1_t* arr, feonumm10n1_t* num,oarrm10n1_t* res);
  void feoarrm10n1_get_active_bases(feoarrm10n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm10n1/array/gauss/algebra.h
  
  feoarrm10n1_t feoarrm10n1_neg(    feoarrm10n1_t* arr);
  void      feoarrm10n1_neg_to( feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sum_FF(   feoarrm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sum_FF_to(feoarrm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sum_fF(    feonumm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sum_fF_to( feonumm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sum_OF(     oarrm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sum_OF_to(  oarrm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sum_RF(      darr_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sum_RF_to(   darr_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sum_oF(   onumm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sum_oF_to(onumm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sum_rF(     coeff_t  lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sum_rF_to(  coeff_t  lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sub_FF(    feoarrm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sub_FF_to( feoarrm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sub_fF(    feonumm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sub_fF_to( feonumm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sub_Ff(    feoarrm10n1_t* lhs, feonumm10n1_t* rhs);
  void      feoarrm10n1_sub_Ff_to( feoarrm10n1_t* lhs, feonumm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sub_OF(      oarrm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sub_OF_to(   oarrm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sub_FO(    feoarrm10n1_t* lhs,   oarrm10n1_t* rhs);
  void      feoarrm10n1_sub_FO_to( feoarrm10n1_t* lhs,   oarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sub_RF(       darr_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sub_RF_to(    darr_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sub_FR(    feoarrm10n1_t* lhs,    darr_t* rhs);
  void      feoarrm10n1_sub_FR_to( feoarrm10n1_t* lhs,    darr_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sub_oF(    onumm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sub_oF_to( onumm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sub_Fo(    feoarrm10n1_t* lhs, onumm10n1_t* rhs);
  void      feoarrm10n1_sub_Fo_to( feoarrm10n1_t* lhs, onumm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sub_rF(      coeff_t  lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_sub_rF_to(    coeff_t lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_sub_Fr(    feoarrm10n1_t* lhs,   coeff_t  rhs);
  void      feoarrm10n1_sub_Fr_to( feoarrm10n1_t* lhs,   coeff_t  rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_mul_FF(   feoarrm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_mul_FF_to(feoarrm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_mul_fF(    feonumm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_mul_fF_to( feonumm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_mul_OF(     oarrm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_mul_OF_to(  oarrm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_mul_RF(      darr_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_mul_RF_to(   darr_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_mul_oF(   onumm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_mul_oF_to(onumm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_mul_rF(     coeff_t  lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_mul_rF_to(  coeff_t  lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_div_FF(    feoarrm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_div_FF_to( feoarrm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_div_fF(     feonumm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_div_fF_to(  feonumm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_div_Ff(    feoarrm10n1_t* lhs,  feonumm10n1_t* rhs);
  void      feoarrm10n1_div_Ff_to( feoarrm10n1_t* lhs,  feonumm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_div_OF(      oarrm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_div_OF_to(   oarrm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_div_FO(    feoarrm10n1_t* lhs,   oarrm10n1_t* rhs);
  void      feoarrm10n1_div_FO_to( feoarrm10n1_t* lhs,   oarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_div_RF(       darr_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_div_RF_to(    darr_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_div_FR(    feoarrm10n1_t* lhs,    darr_t* rhs);
  void      feoarrm10n1_div_FR_to( feoarrm10n1_t* lhs,    darr_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_div_oF(    onumm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_div_oF_to( onumm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_div_Fo(    feoarrm10n1_t* lhs, onumm10n1_t* rhs);
  void      feoarrm10n1_div_Fo_to( feoarrm10n1_t* lhs, onumm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_div_rF(      coeff_t  lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_div_rF_to(    coeff_t lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_div_Fr(    feoarrm10n1_t* lhs,   coeff_t  rhs);
  void      feoarrm10n1_div_Fr_to( feoarrm10n1_t* lhs,   coeff_t  rhs, feoarrm10n1_t* res);
  oarrm10n1_t feoarrm10n1_integrate(    feoarrm10n1_t* arr, feonumm10n1_t* w);
  void    feoarrm10n1_integrate_to( feoarrm10n1_t* arr, feonumm10n1_t* w, oarrm10n1_t* res);
  feonumm10n1_t feoarrm10n1_dotproduct_FF(    feoarrm10n1_t* lhs, feoarrm10n1_t* rhs);
  void     feoarrm10n1_dotproduct_FF_to( feoarrm10n1_t* lhs, feoarrm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feoarrm10n1_dotproduct_OF(      oarrm10n1_t* lhs, feoarrm10n1_t* rhs);
  void     feoarrm10n1_dotproduct_OF_to(   oarrm10n1_t* lhs, feoarrm10n1_t* rhs, feonumm10n1_t* res);
  feonumm10n1_t feoarrm10n1_dotproduct_RF(       darr_t* lhs, feoarrm10n1_t* rhs);
  void     feoarrm10n1_dotproduct_RF_to(    darr_t* lhs, feoarrm10n1_t* rhs, feonumm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_matmul_FF(    feoarrm10n1_t* lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_matmul_FF_to( feoarrm10n1_t* lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_matmul_OF(    oarrm10n1_t*   lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_matmul_OF_to( oarrm10n1_t*   lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_matmul_FO(    feoarrm10n1_t* lhs, oarrm10n1_t*   rhs);
  void      feoarrm10n1_matmul_FO_to( feoarrm10n1_t* lhs, oarrm10n1_t*   rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_matmul_RF(    darr_t*    lhs, feoarrm10n1_t* rhs);
  void      feoarrm10n1_matmul_RF_to( darr_t*    lhs, feoarrm10n1_t* rhs, feoarrm10n1_t* res);
  feoarrm10n1_t feoarrm10n1_matmul_FR(    feoarrm10n1_t* lhs, darr_t*    rhs);
  void      feoarrm10n1_matmul_FR_to( feoarrm10n1_t* lhs, darr_t*    rhs, feoarrm10n1_t* res);
  feonumm10n1_t feoarrm10n1_det(   feoarrm10n1_t* arr);
  void     feoarrm10n1_det_to(feoarrm10n1_t* arr, feonumm10n1_t* res);
  feonumm10n1_t feoarrm10n1_norm(     feoarrm10n1_t* arr);
  void     feoarrm10n1_norm_to(  feoarrm10n1_t* arr, feonumm10n1_t* res);
  feonumm10n1_t feoarrm10n1_pnorm(    feoarrm10n1_t* arr, coeff_t p);
  void     feoarrm10n1_pnorm_to( feoarrm10n1_t* arr, coeff_t p, feonumm10n1_t* res);
  feoarrm10n1_t   feoarrm10n1_invert(    feoarrm10n1_t* arr);
  void        feoarrm10n1_invert_to( feoarrm10n1_t* arr, feoarrm10n1_t* res);
  feoarrm10n1_t   feoarrm10n1_transpose(   feoarrm10n1_t* arr);
  void        feoarrm10n1_transpose_to(feoarrm10n1_t* arr, feoarrm10n1_t* res);
  
  