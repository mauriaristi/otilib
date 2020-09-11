cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm3n1/scalar/structures.h
  
  ctypedef struct  onumm3n1_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
  # } onumm3n1_t;
  
  
  # From ../../../include/oti/static/onumm3n1/array/structures.h
  
  ctypedef struct  oarrm3n1_t : # {
      onumm3n1_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm3n1_t;
  
  
  # From ../../../include/oti/static/onumm3n1/scalar/gauss/structures.h
  
  ctypedef struct  feonumm3n1_t: # {
      onumm3n1_t*  p_data;
      uint64_t    nip;
  # } feonumm3n1_t;
  
  
  # From ../../../include/oti/static/onumm3n1/array/gauss/structures.h
  
  ctypedef struct  feoarrm3n1_t: # {
      oarrm3n1_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm3n1_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm3n1/scalar/functions.h
  
  onumm3n1_t onumm3n1_atanh(onumm3n1_t* num);
  void onumm3n1_atanh_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_asinh(onumm3n1_t* num);
  void onumm3n1_asinh_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_acosh(onumm3n1_t* num);
  void onumm3n1_acosh_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_tanh(onumm3n1_t* num);
  void onumm3n1_tanh_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_sqrt(onumm3n1_t* num);
  void onumm3n1_sqrt_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_cbrt(onumm3n1_t* num);
  void onumm3n1_cbrt_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_cosh(onumm3n1_t* num);
  void onumm3n1_cosh_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_sinh(onumm3n1_t* num);
  void onumm3n1_sinh_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_asin(onumm3n1_t* num);
  void onumm3n1_asin_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_acos(onumm3n1_t* num);
  void onumm3n1_acos_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_atan(onumm3n1_t* num);
  void onumm3n1_atan_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_tan(onumm3n1_t* num);
  void onumm3n1_tan_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_cos(onumm3n1_t* num);
  void onumm3n1_cos_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_sin(onumm3n1_t* num );
  void onumm3n1_sin_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_logb(onumm3n1_t* num, double base);
  void onumm3n1_logb_to(onumm3n1_t* num, double base, onumm3n1_t* res);
  onumm3n1_t onumm3n1_log10(onumm3n1_t* num);
  void onumm3n1_log10_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_log(onumm3n1_t* num);
  void onumm3n1_log_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_exp(onumm3n1_t* num);
  void onumm3n1_exp_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_pow(onumm3n1_t* num, double e);
  void onumm3n1_pow_to(onumm3n1_t* num, coeff_t e, onumm3n1_t* res);
  
  
  # From ../../../include/oti/static/onumm3n1/scalar/base.h
  
  void onumm3n1_set_im_o(onumm3n1_t* num, imdir_t idx, ord_t order, onumm3n1_t* res);
  void onumm3n1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm3n1_t* res);
  void onumm3n1_set_deriv_o(onumm3n1_t* num, imdir_t idx, ord_t order, onumm3n1_t* res);
  void onumm3n1_extract_im_to( imdir_t idx, ord_t order, onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_extract_im(imdir_t idx, ord_t order, onumm3n1_t* num);
  onumm3n1_t onumm3n1_extract_deriv(imdir_t idx, ord_t order, onumm3n1_t* num);
  void onumm3n1_extract_deriv_to(imdir_t idx, ord_t order, onumm3n1_t* num, onumm3n1_t* res);
  void onumm3n1_get_im_to_o(imdir_t idx, ord_t order, onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_get_im_o(imdir_t idx, ord_t order, onumm3n1_t* num);
  void onumm3n1_get_im_to_r(imdir_t idx, ord_t order, onumm3n1_t* num, coeff_t* res);
  ord_t onumm3n1_get_order(onumm3n1_t* lhs);
  onumm3n1_t onumm3n1_get_deriv_o( imdir_t idx, ord_t order, onumm3n1_t* num);
  void onumm3n1_get_deriv_to( imdir_t idx, ord_t order, onumm3n1_t* num, onumm3n1_t* res);
  void onumm3n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm3n1_t* res);
  onumm3n1_t onumm3n1_init();
  ndir_t onumm3n1_get_ndir_order(ord_t order, onumm3n1_t* num);
  ndir_t onumm3n1_get_ndir_total(onumm3n1_t* num);
  coeff_t* onumm3n1_get_order_address(ord_t order, onumm3n1_t* num);
  onumm3n1_t onumm3n1_create_r(  coeff_t lhs);
  void onumm3n1_set_r(  coeff_t lhs, onumm3n1_t* res);
  void onumm3n1_set_o(  onumm3n1_t* lhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_get_order_im(ord_t order, onumm3n1_t* lhs);
  void onumm3n1_get_order_im_to(ord_t order, onumm3n1_t* lhs, onumm3n1_t* res);
  coeff_t onumm3n1_get_item(imdir_t idx, ord_t order, onumm3n1_t* lhs);
  coeff_t onumm3n1_get_deriv(imdir_t idx, ord_t order, onumm3n1_t* lhs);
  void onumm3n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm3n1_t* x);
  onumm3n1_t onumm3n1_copy(  onumm3n1_t* lhs);
  void onumm3n1_copy_to(  onumm3n1_t* lhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_taylor_integrate(coeff_t* deltas,onumm3n1_t* lhs);
  void onumm3n1_taylor_integrate_to(coeff_t* deltas,onumm3n1_t* lhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_truncate_im(imdir_t idx, ord_t order, onumm3n1_t* lhs);
  void onumm3n1_truncate_im_to(imdir_t idx, ord_t order, onumm3n1_t* lhs, onumm3n1_t* res);
  void onumm3n1_print(  onumm3n1_t* lhs);
  imdir_t onumm3n1_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm3n1/scalar/utils.h
  
  void onumm3n1_get_active_bases(onumm3n1_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm3n1/scalar/algebra.h
  
  onumm3n1_t onumm3n1_abs(onumm3n1_t* num);
  onumm3n1_t onumm3n1_div_ro(coeff_t num, onumm3n1_t* den);
  onumm3n1_t onumm3n1_div_oo(onumm3n1_t* num, onumm3n1_t* den);
  onumm3n1_t onumm3n1_div_or(onumm3n1_t* num, coeff_t val);
  void onumm3n1_div_ro_to(coeff_t num, onumm3n1_t* den, onumm3n1_t* res);
  void onumm3n1_div_oo_to(onumm3n1_t* num, onumm3n1_t* den, onumm3n1_t* res);
  void onumm3n1_div_or_to(onumm3n1_t* num, coeff_t val, onumm3n1_t* res);
  void onumm3n1_abs_to(onumm3n1_t* num, onumm3n1_t* res);
  onumm3n1_t onumm3n1_neg(  onumm3n1_t* lhs);
  void onumm3n1_neg_to(  onumm3n1_t* lhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_sum_oo(  onumm3n1_t* lhs,  onumm3n1_t* rhs);
  void onumm3n1_sum_oo_to(  onumm3n1_t* lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_sum_ro(  coeff_t lhs,  onumm3n1_t* rhs);
  void onumm3n1_sum_ro_to(  coeff_t lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_sub_oo(  onumm3n1_t* lhs,  onumm3n1_t* rhs);
  void onumm3n1_sub_oo_to(  onumm3n1_t* lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_sub_ro(  coeff_t lhs,  onumm3n1_t* rhs);
  void onumm3n1_sub_ro_to(  coeff_t lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_sub_or(  onumm3n1_t* lhs,  coeff_t rhs);
  void onumm3n1_sub_or_to(  onumm3n1_t* lhs,  coeff_t rhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_mul_oo(  onumm3n1_t* lhs,  onumm3n1_t* rhs);
  void onumm3n1_mul_oo_to(  onumm3n1_t* lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_mul_ro(  coeff_t lhs,  onumm3n1_t* rhs);
  void onumm3n1_mul_ro_to(  coeff_t lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_trunc_mul_oo(  onumm3n1_t* lhs,  onumm3n1_t* rhs);
  void onumm3n1_trunc_mul_oo_to(  onumm3n1_t* lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_gem_oo(  onumm3n1_t* a,  onumm3n1_t* b,  onumm3n1_t* c);
  void onumm3n1_gem_oo_to(  onumm3n1_t* a,  onumm3n1_t* b,  onumm3n1_t* c, onumm3n1_t* res);
  onumm3n1_t onumm3n1_gem_ro(  coeff_t a,  onumm3n1_t* b,  onumm3n1_t* c);
  void onumm3n1_gem_ro_to(  coeff_t a,  onumm3n1_t* b,  onumm3n1_t* c, onumm3n1_t* res);
  void onumm3n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm3n1_t* a,  ord_t ord_rhs,  onumm3n1_t* b,  onumm3n1_t* c, onumm3n1_t* res);
  void onumm3n1_trunc_sum_oo_to(ord_t order, onumm3n1_t* lhs,onumm3n1_t* rhs, onumm3n1_t* res);
  void onumm3n1_trunc_sub_oo_to(ord_t order, onumm3n1_t* lhs,onumm3n1_t* rhs, onumm3n1_t* res);
  onumm3n1_t onumm3n1_feval(coeff_t* feval_re, onumm3n1_t* x);
  void onumm3n1_feval_to(coeff_t* feval_re, onumm3n1_t* x, onumm3n1_t* res);
  
  
  # From ../../../include/oti/static/onumm3n1/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm3n1/scalar/gauss/functions.h
  
  feonumm3n1_t feonumm3n1_atanh(    feonumm3n1_t* num);
  void     feonumm3n1_atanh_to( feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_asinh(    feonumm3n1_t* num);
  void     feonumm3n1_asinh_to( feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_acosh(    feonumm3n1_t* num);
  void     feonumm3n1_acosh_to( feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_tanh(     feonumm3n1_t* num);
  void     feonumm3n1_tanh_to(  feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_cosh(     feonumm3n1_t* num);
  void     feonumm3n1_cosh_to(  feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_sinh(     feonumm3n1_t* num);
  void     feonumm3n1_sinh_to(  feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_asin(     feonumm3n1_t* num);
  void     feonumm3n1_asin_to(  feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_acos(     feonumm3n1_t* num);
  void     feonumm3n1_acos_to(  feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_atan(     feonumm3n1_t* num);
  void     feonumm3n1_atan_to(  feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_tan(      feonumm3n1_t* num);
  void     feonumm3n1_tan_to(   feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_cos(      feonumm3n1_t* num);
  void     feonumm3n1_cos_to(   feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_sin(      feonumm3n1_t* num);
  void     feonumm3n1_sin_to(   feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_logb(     feonumm3n1_t* num, double base);
  void     feonumm3n1_logb_to(  feonumm3n1_t* num, double base, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_log10(    feonumm3n1_t* num);
  void     feonumm3n1_log10_to( feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_log(      feonumm3n1_t* num);
  void     feonumm3n1_log_to(   feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_exp(      feonumm3n1_t* num);
  void     feonumm3n1_exp_to(   feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_cbrt(     feonumm3n1_t* num);
  void     feonumm3n1_cbrt_to(  feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_sqrt(     feonumm3n1_t* num);
  void     feonumm3n1_sqrt_to(  feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_pow(      feonumm3n1_t* num, double e);
  void     feonumm3n1_pow_to(   feonumm3n1_t* num, double e, feonumm3n1_t* res);
  onumm3n1_t feonumm3n1_integrate(       feonumm3n1_t* num, feonumm3n1_t* w);
  void      feonumm3n1_integrate_to(    feonumm3n1_t* num, feonumm3n1_t* w, onumm3n1_t* res);
  onumm3n1_t feonumm3n1_integrate_f(     feonumm3n1_t* num, feonumm3n1_t* w);
  void      feonumm3n1_integrate_f_to(  feonumm3n1_t* num, feonumm3n1_t* w, onumm3n1_t* res);
  onumm3n1_t feonumm3n1_integrate_r(       coeff_t num, feonumm3n1_t* w);
  void      feonumm3n1_integrate_r_to(    coeff_t num, feonumm3n1_t* w, onumm3n1_t* res);
  onumm3n1_t feonumm3n1_integrate_o(    onumm3n1_t* num, feonumm3n1_t* w);
  void      feonumm3n1_integrate_o_to( onumm3n1_t* num, feonumm3n1_t* w, onumm3n1_t* res);
  
  
  # From ../../../include/oti/static/onumm3n1/scalar/gauss/base.h
  
  void     feonumm3n1_get_order_im_to( ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_get_order_im(    ord_t order, feonumm3n1_t* num);
  feonumm3n1_t feonumm3n1_get_im(    imdir_t idx, ord_t order, feonumm3n1_t* num);
  void     feonumm3n1_get_im_to( imdir_t idx, ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_get_deriv(    imdir_t idx, ord_t order, feonumm3n1_t* num);
  void     feonumm3n1_get_deriv_to( imdir_t idx, ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
  void feonumm3n1_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm3n1_t* num);
  void feonumm3n1_set_im_o( onumm3n1_t* val, imdir_t idx, ord_t order, feonumm3n1_t* num);
  void feonumm3n1_set_im_f(  feonumm3n1_t* val, imdir_t idx, ord_t order, feonumm3n1_t* num);
  void feonumm3n1_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm3n1_t* num);
  void feonumm3n1_set_deriv_o( onumm3n1_t* val, imdir_t idx, ord_t order, feonumm3n1_t* num);
  void feonumm3n1_set_deriv_f(  feonumm3n1_t* val, imdir_t idx, ord_t order, feonumm3n1_t* num);
  feonumm3n1_t feonumm3n1_extract_im(    imdir_t idx, ord_t order, feonumm3n1_t* num);
  void     feonumm3n1_extract_im_to( imdir_t idx, ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_extract_deriv(    imdir_t idx, ord_t order, feonumm3n1_t* num);
  void     feonumm3n1_extract_deriv_to( imdir_t idx, ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_truncate_im(    imdir_t idx, ord_t order, feonumm3n1_t* num);
  void     feonumm3n1_truncate_im_to( imdir_t idx, ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_copy(    feonumm3n1_t* src);
  void     feonumm3n1_copy_to( feonumm3n1_t* src, feonumm3n1_t* dst);
  void feonumm3n1_set_r(    coeff_t num, feonumm3n1_t* res);
  void feonumm3n1_set_o( onumm3n1_t* num, feonumm3n1_t* res);
  void feonumm3n1_set_f(  feonumm3n1_t* num, feonumm3n1_t* res);
  void feonumm3n1_set_item_k_r(   coeff_t  num, uint64_t k, feonumm3n1_t* res);
  void feonumm3n1_set_item_k_o( onumm3n1_t* num, uint64_t k, feonumm3n1_t* res);
  onumm3n1_t feonumm3n1_get_item_k(   feonumm3n1_t* num, uint64_t k);
  void      feonumm3n1_get_item_k_to(feonumm3n1_t* num, uint64_t k, onumm3n1_t* res);
  feonumm3n1_t feonumm3n1_zeros(uint64_t nIntPts);
  feonumm3n1_t feonumm3n1_createEmpty(uint64_t nIntPts);
  feonumm3n1_t feonumm3n1_empty_like(feonumm3n1_t* arr);
  void feonumm3n1_free(feonumm3n1_t* num);
  ord_t feonumm3n1_get_order( feonumm3n1_t* num );
  feonumm3n1_t feonumm3n1_init();
  
  
  # From ../../../include/oti/static/onumm3n1/scalar/gauss/utils.h
  
  void feonumm3n1_dimCheck(feonumm3n1_t* arr1,feonumm3n1_t* arr2);
  void feonumm3n1_get_active_bases(feonumm3n1_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n1/scalar/gauss/algebra.h
  
  feonumm3n1_t feonumm3n1_neg(   feonumm3n1_t* num);
  void     feonumm3n1_neg_to(feonumm3n1_t* num, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_sum_ff(   feonumm3n1_t* lhs, feonumm3n1_t* rhs);
  void     feonumm3n1_sum_ff_to(feonumm3n1_t* lhs, feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_sum_of(   onumm3n1_t* lhs, feonumm3n1_t* rhs);
  void     feonumm3n1_sum_of_to(onumm3n1_t* lhs, feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_sum_rf(   coeff_t lhs, feonumm3n1_t* rhs);
  void     feonumm3n1_sum_rf_to(coeff_t lhs, feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_sub_ff(     feonumm3n1_t* lhs,  feonumm3n1_t* rhs);
  void     feonumm3n1_sub_ff_to(  feonumm3n1_t* lhs,  feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_sub_of(    onumm3n1_t* lhs,  feonumm3n1_t* rhs);
  void     feonumm3n1_sub_of_to( onumm3n1_t* lhs,  feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_sub_fo(     feonumm3n1_t* lhs, onumm3n1_t* rhs);
  void     feonumm3n1_sub_fo_to(  feonumm3n1_t* lhs, onumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_sub_rf(       coeff_t lhs,  feonumm3n1_t* rhs);
  void     feonumm3n1_sub_rf_to(    coeff_t lhs,  feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_sub_fr(     feonumm3n1_t* lhs,    coeff_t rhs);
  void     feonumm3n1_sub_fr_to(  feonumm3n1_t* lhs,    coeff_t rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_mul_ff(   feonumm3n1_t* lhs, feonumm3n1_t* rhs);
  void     feonumm3n1_mul_ff_to(feonumm3n1_t* lhs, feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_mul_of(   onumm3n1_t* lhs, feonumm3n1_t* rhs);
  void     feonumm3n1_mul_of_to(onumm3n1_t* lhs, feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_mul_rf(   coeff_t lhs, feonumm3n1_t* rhs);
  void     feonumm3n1_mul_rf_to(coeff_t lhs, feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_div_ff(     feonumm3n1_t* lhs,  feonumm3n1_t* rhs);
  void     feonumm3n1_div_ff_to(  feonumm3n1_t* lhs,  feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_div_of(    onumm3n1_t* lhs,  feonumm3n1_t* rhs);
  void     feonumm3n1_div_of_to( onumm3n1_t* lhs,  feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_div_fo(     feonumm3n1_t* lhs, onumm3n1_t* rhs);
  void     feonumm3n1_div_fo_to(  feonumm3n1_t* lhs, onumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_div_rf(       coeff_t lhs,  feonumm3n1_t* rhs);
  void     feonumm3n1_div_rf_to(    coeff_t lhs,  feonumm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feonumm3n1_div_fr(     feonumm3n1_t* lhs,    coeff_t rhs);
  void     feonumm3n1_div_fr_to(  feonumm3n1_t* lhs,    coeff_t rhs, feonumm3n1_t* res);
  
  
  # From ../../../include/oti/static/onumm3n1/array/functions.h
  
  oarrm3n1_t oarrm3n1_atanh(   oarrm3n1_t* arr);
  void    oarrm3n1_atanh_to(oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_asinh(   oarrm3n1_t* arr);
  void    oarrm3n1_asinh_to(oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_acosh(   oarrm3n1_t* arr);
  void    oarrm3n1_acosh_to(oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_tanh(    oarrm3n1_t* arr);
  void    oarrm3n1_tanh_to( oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_cbrt(    oarrm3n1_t* arr);
  void    oarrm3n1_cbrt_to( oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_sqrt(    oarrm3n1_t* arr);
  void    oarrm3n1_sqrt_to( oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_cosh(    oarrm3n1_t* arr);
  void    oarrm3n1_cosh_to( oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_sinh(    oarrm3n1_t* arr);
  void    oarrm3n1_sinh_to( oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_asin(    oarrm3n1_t* arr);
  void    oarrm3n1_asin_to( oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_acos(    oarrm3n1_t* arr);
  void    oarrm3n1_acos_to( oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_atan(    oarrm3n1_t* arr);
  void    oarrm3n1_atan_to( oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_tan(     oarrm3n1_t* arr);
  void    oarrm3n1_tan_to(  oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_cos(     oarrm3n1_t* arr);
  void    oarrm3n1_cos_to(  oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_sin(     oarrm3n1_t* arr);
  void    oarrm3n1_sin_to(  oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_logb(    oarrm3n1_t* arr, double base);
  void    oarrm3n1_logb_to( oarrm3n1_t* arr, double base, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_log10(   oarrm3n1_t* arr);
  void    oarrm3n1_log10_to(oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_log(     oarrm3n1_t* arr);
  void    oarrm3n1_log_to(  oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_exp(     oarrm3n1_t* arr);
  void    oarrm3n1_exp_to(  oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_pow(     oarrm3n1_t* arr, double e);
  void    oarrm3n1_pow_to(  oarrm3n1_t* arr, double e, oarrm3n1_t* res);
  
  
  # From ../../../include/oti/static/onumm3n1/array/algebra_elementwise.h
  
  oarrm3n1_t oarrm3n1_neg(oarrm3n1_t* arr);
  void oarrm3n1_neg_to(oarrm3n1_t* rhs, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_sum_OO(oarrm3n1_t*   lhs, oarrm3n1_t* rhs);
  oarrm3n1_t oarrm3n1_sum_RO(darr_t*    lhs, oarrm3n1_t* rhs);
  oarrm3n1_t oarrm3n1_sum_oO(onumm3n1_t* lhs, oarrm3n1_t* rhs);
  oarrm3n1_t oarrm3n1_sum_rO(coeff_t    lhs, oarrm3n1_t* rhs);
  void oarrm3n1_sum_OO_to(oarrm3n1_t*   lhs, oarrm3n1_t* rhs, oarrm3n1_t* res);
  void oarrm3n1_sum_RO_to(darr_t*    lhs, oarrm3n1_t* rhs, oarrm3n1_t* res);
  void oarrm3n1_sum_oO_to(onumm3n1_t* lhs, oarrm3n1_t* rhs, oarrm3n1_t* res);
  void oarrm3n1_sum_rO_to(coeff_t    lhs, oarrm3n1_t* rhs, oarrm3n1_t* res);
  void oarrm3n1_trunc_sum_OO_to(ord_t order, oarrm3n1_t* arr1, oarrm3n1_t* arr2, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_sub_OO(oarrm3n1_t*   lhs, oarrm3n1_t*   rhs);
  oarrm3n1_t oarrm3n1_sub_RO(darr_t*    lhs, oarrm3n1_t*   rhs);
  oarrm3n1_t oarrm3n1_sub_OR(oarrm3n1_t*   lhs, darr_t*    rhs);
  oarrm3n1_t oarrm3n1_sub_oO(onumm3n1_t* lhs, oarrm3n1_t*   rhs);
  oarrm3n1_t oarrm3n1_sub_Oo(oarrm3n1_t*   lhs, onumm3n1_t* rhs);
  oarrm3n1_t oarrm3n1_sub_rO(coeff_t    lhs, oarrm3n1_t*   rhs);
  oarrm3n1_t oarrm3n1_sub_Or(oarrm3n1_t*   lhs, coeff_t    rhs);
  void oarrm3n1_sub_OO_to( oarrm3n1_t*   lhs, oarrm3n1_t*   rhs, oarrm3n1_t* res);
  void oarrm3n1_sub_RO_to( darr_t*    lhs, oarrm3n1_t*   rhs, oarrm3n1_t* res);
  void oarrm3n1_sub_OR_to( oarrm3n1_t*   lhs, darr_t*    rhs, oarrm3n1_t* res);
  void oarrm3n1_sub_oO_to( onumm3n1_t* lhs, oarrm3n1_t*   rhs, oarrm3n1_t* res);
  void oarrm3n1_sub_Oo_to( oarrm3n1_t*   lhs, onumm3n1_t* rhs, oarrm3n1_t* res);
  void oarrm3n1_sub_rO_to( coeff_t    lhs, oarrm3n1_t*   rhs, oarrm3n1_t* res);
  void oarrm3n1_sub_Or_to( oarrm3n1_t*   lhs, coeff_t    rhs, oarrm3n1_t* res);
  void oarrm3n1_trunc_sub_OO_to(ord_t order, oarrm3n1_t* arr1, oarrm3n1_t* arr2, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_mul_OO(oarrm3n1_t*   lhs, oarrm3n1_t* rhs);
  oarrm3n1_t oarrm3n1_mul_RO(darr_t*    lhs, oarrm3n1_t* rhs);
  oarrm3n1_t oarrm3n1_mul_oO(onumm3n1_t* lhs, oarrm3n1_t* rhs);
  oarrm3n1_t oarrm3n1_mul_rO(coeff_t    lhs, oarrm3n1_t* rhs);
  void oarrm3n1_mul_OO_to(oarrm3n1_t*   lhs, oarrm3n1_t* rhs, oarrm3n1_t* res);
  void oarrm3n1_mul_RO_to(darr_t*    lhs, oarrm3n1_t* rhs, oarrm3n1_t* res);
  void oarrm3n1_mul_oO_to(onumm3n1_t* lhs, oarrm3n1_t* rhs, oarrm3n1_t* res);
  void oarrm3n1_mul_rO_to(coeff_t    lhs, oarrm3n1_t* rhs, oarrm3n1_t* res);
  void oarrm3n1_gem_OO_to(  oarrm3n1_t* arr1, oarrm3n1_t* arr2, oarrm3n1_t* arr3, oarrm3n1_t* res);
  void oarrm3n1_gem_oO_to(onumm3n1_t* arr1, oarrm3n1_t* arr2, oarrm3n1_t* arr3, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_div_OO(oarrm3n1_t*   lhs, oarrm3n1_t*   rhs);
  oarrm3n1_t oarrm3n1_div_OR(oarrm3n1_t*   lhs, darr_t*    rhs);
  oarrm3n1_t oarrm3n1_div_RO(darr_t*    lhs, oarrm3n1_t*   rhs);
  oarrm3n1_t oarrm3n1_div_oO(onumm3n1_t* lhs, oarrm3n1_t*   rhs);
  oarrm3n1_t oarrm3n1_div_Oo(oarrm3n1_t*   lhs, onumm3n1_t* rhs);
  oarrm3n1_t oarrm3n1_div_rO(coeff_t    lhs, oarrm3n1_t*   rhs);
  oarrm3n1_t oarrm3n1_div_Or(oarrm3n1_t*   lhs, coeff_t    rhs);
  void oarrm3n1_div_OO_to(oarrm3n1_t*   lhs, oarrm3n1_t*   rhs, oarrm3n1_t* res);
  void oarrm3n1_div_RO_to(darr_t*    lhs, oarrm3n1_t*   rhs, oarrm3n1_t* res);
  void oarrm3n1_div_OR_to(oarrm3n1_t*   lhs, darr_t*    rhs, oarrm3n1_t* res);
  void oarrm3n1_div_oO_to(onumm3n1_t* lhs, oarrm3n1_t*   rhs, oarrm3n1_t* res);
  void oarrm3n1_div_Oo_to(oarrm3n1_t*   lhs, onumm3n1_t* rhs, oarrm3n1_t* res);
  void oarrm3n1_div_rO_to(coeff_t    lhs, oarrm3n1_t*   rhs, oarrm3n1_t* res);
  void oarrm3n1_div_Or_to(oarrm3n1_t*   lhs, coeff_t    rhs, oarrm3n1_t* res);
  
  
  # From ../../../include/oti/static/onumm3n1/array/base.h
  
  void    oarrm3n1_taylor_integrate_to( coeff_t* deltas, oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_taylor_integrate(    coeff_t* deltas, oarrm3n1_t* arr);
  void    oarrm3n1_get_order_im_to( ord_t order, oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_get_order_im(    ord_t order, oarrm3n1_t* arr);
  void oarrm3n1_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n1_t* res);
  void oarrm3n1_set_slice_O( oarrm3n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n1_t* res);
  void oarrm3n1_set_slice_o( onumm3n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_get_slice( oarrm3n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm3n1_get_slice_to( oarrm3n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_truncate_im(    imdir_t idx, ord_t order, oarrm3n1_t* arr);
  void    oarrm3n1_truncate_im_to( imdir_t idx, ord_t order, oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_extract_im(   imdir_t idx, ord_t order, oarrm3n1_t* arr);
  void    oarrm3n1_extract_im_to(imdir_t idx, ord_t order, oarrm3n1_t* arr, oarrm3n1_t* res);
  darr_t  oarrm3n1_get_deriv(    imdir_t idx, ord_t order, oarrm3n1_t* arr);
  void    oarrm3n1_get_deriv_to( imdir_t idx, ord_t order, oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_get_deriv_o(  imdir_t idx, ord_t order, oarrm3n1_t* arr);
  oarrm3n1_t oarrm3n1_extract_deriv(    imdir_t idx, ord_t order, oarrm3n1_t* arr);
  void    oarrm3n1_extract_deriv_to( imdir_t idx, ord_t order, oarrm3n1_t* arr, oarrm3n1_t* res);
  darr_t  oarrm3n1_get_im(   imdir_t idx, ord_t order, oarrm3n1_t* arr);
  oarrm3n1_t oarrm3n1_get_im_o( imdir_t idx, ord_t order, oarrm3n1_t* arr);
  void    oarrm3n1_get_im_to(imdir_t idx, ord_t order, oarrm3n1_t* arr, oarrm3n1_t* res);
  void    oarrm3n1_copy_to(oarrm3n1_t* arr, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_copy(oarrm3n1_t* arr);
  void oarrm3n1_set_all_r( coeff_t num, oarrm3n1_t* arr);
  void oarrm3n1_set_item_i_r( coeff_t num, uint64_t i, oarrm3n1_t* arr);
  void oarrm3n1_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm3n1_t* arr);
  void oarrm3n1_set_r(   coeff_t  num,   oarrm3n1_t* arr);
  void oarrm3n1_set_o( onumm3n1_t* num,   oarrm3n1_t* arr);
  void oarrm3n1_set_O(   oarrm3n1_t* arrin, oarrm3n1_t* arr);
  void oarrm3n1_set_all_o( onumm3n1_t* src, oarrm3n1_t* arr);
  void oarrm3n1_set_item_i_o( onumm3n1_t* num, uint64_t i, oarrm3n1_t* arr);
  void oarrm3n1_set_item_ij_o( onumm3n1_t* num, uint64_t i, uint64_t j, oarrm3n1_t* arr);
  onumm3n1_t oarrm3n1_get_item_i(    oarrm3n1_t* arr, uint64_t i);
  void      oarrm3n1_get_item_i_to( oarrm3n1_t* arr, uint64_t i,             onumm3n1_t* res);
  onumm3n1_t oarrm3n1_get_item_ij(   oarrm3n1_t* arr, uint64_t i, uint64_t j);
  void      oarrm3n1_get_item_ij_to(oarrm3n1_t* arr, uint64_t i, uint64_t j, onumm3n1_t* res);
  oarrm3n1_t oarrm3n1_init();
  void oarrm3n1_free(oarrm3n1_t* arr);
  oarrm3n1_t oarrm3n1_empty_like(oarrm3n1_t* arr);
  oarrm3n1_t oarrm3n1_eye(uint64_t nrows);
  oarrm3n1_t oarrm3n1_ones(uint64_t nrows, uint64_t ncols);
  oarrm3n1_t oarrm3n1_zeros(uint64_t nrows, uint64_t ncols);
  oarrm3n1_t oarrm3n1_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm3n1/array/utils.h
  
  void oarrm3n1_dimCheck_OO_elementwise(oarrm3n1_t* arr1, oarrm3n1_t* arr2, oarrm3n1_t* res);
  void oarrm3n1_dimCheck_RO_elementwise(darr_t*  arr1, oarrm3n1_t* arr2, oarrm3n1_t* res);
  void oarrm3n1_dimCheck_OO_matmul(oarrm3n1_t* arr1, oarrm3n1_t* arr2, oarrm3n1_t* res);
  void oarrm3n1_dimCheck_RO_matmul(darr_t*  arr1, oarrm3n1_t* arr2, oarrm3n1_t* res);
  void oarrm3n1_dimCheck_OR_matmul(oarrm3n1_t* arr1, darr_t*  arr2, oarrm3n1_t* res);
  void oarrm3n1_dimCheck_O_squareness(oarrm3n1_t* arr1, oarrm3n1_t* res);
  void oarrm3n1_dimCheck_OO_samesize(oarrm3n1_t* arr1, oarrm3n1_t* res);
  void oarrm3n1_dimCheck_RO_samesize(darr_t* arr1, oarrm3n1_t* res);
  ord_t oarrm3n1_get_order(oarrm3n1_t* arr);
  void oarrm3n1_get_active_bases(oarrm3n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n1/array/algebra_matops.h
  
  onumm3n1_t oarrm3n1_dotproduct_OO(    oarrm3n1_t* lhs, oarrm3n1_t* rhs);
  void      oarrm3n1_dotproduct_OO_to( oarrm3n1_t* lhs, oarrm3n1_t* rhs, onumm3n1_t* res);
  onumm3n1_t oarrm3n1_dotproduct_RO(     darr_t* lhs, oarrm3n1_t* rhs);
  void      oarrm3n1_dotproduct_RO_to(  darr_t* lhs, oarrm3n1_t* rhs, onumm3n1_t* res);
  oarrm3n1_t oarrm3n1_matmul_OO(    oarrm3n1_t* lhs, oarrm3n1_t* rhs);
  oarrm3n1_t oarrm3n1_matmul_OR(    oarrm3n1_t* lhs,  darr_t* rhs);
  oarrm3n1_t oarrm3n1_matmul_RO(     darr_t* lhs, oarrm3n1_t* rhs);
  void    oarrm3n1_matmul_OO_to( oarrm3n1_t* lhs, oarrm3n1_t* rhs, oarrm3n1_t* res);
  void    oarrm3n1_matmul_OR_to( oarrm3n1_t* lhs,  darr_t* rhs, oarrm3n1_t* res);
  void    oarrm3n1_matmul_RO_to(  darr_t* lhs, oarrm3n1_t* rhs, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_transpose(    oarrm3n1_t* arr1);
  void    oarrm3n1_transpose_to( oarrm3n1_t* arr1, oarrm3n1_t* res);
  oarrm3n1_t oarrm3n1_invert(    oarrm3n1_t* arr1);
  void    oarrm3n1_invert_to( oarrm3n1_t* arr1, oarrm3n1_t* res);
  onumm3n1_t oarrm3n1_det(    oarrm3n1_t* arr1);
  void      oarrm3n1_det_to( oarrm3n1_t* arr1, onumm3n1_t* res);
  onumm3n1_t oarrm3n1_norm(    oarrm3n1_t* arr1);
  void      oarrm3n1_norm_to( oarrm3n1_t* arr1,  onumm3n1_t* res);
  onumm3n1_t oarrm3n1_pnorm(    oarrm3n1_t* arr1, coeff_t p);
  void      oarrm3n1_pnorm_to( oarrm3n1_t* arr1, coeff_t p, onumm3n1_t* res);
  
  
  # From ../../../include/oti/static/onumm3n1/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm3n1/array/gauss/functions.h
  
  feoarrm3n1_t feoarrm3n1_atanh(    feoarrm3n1_t* arr);
  void      feoarrm3n1_atanh_to( feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_asinh(    feoarrm3n1_t* arr);
  void      feoarrm3n1_asinh_to( feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_acosh(    feoarrm3n1_t* arr);
  void      feoarrm3n1_acosh_to( feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_tanh(     feoarrm3n1_t* arr);
  void      feoarrm3n1_tanh_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sinh(     feoarrm3n1_t* arr);
  void      feoarrm3n1_sinh_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_cosh(     feoarrm3n1_t* arr);
  void      feoarrm3n1_cosh_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_atan(     feoarrm3n1_t* arr);
  void      feoarrm3n1_atan_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_asin(     feoarrm3n1_t* arr);
  void      feoarrm3n1_asin_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_acos(     feoarrm3n1_t* arr);
  void      feoarrm3n1_acos_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_tan(      feoarrm3n1_t* arr);
  void      feoarrm3n1_tan_to(   feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sin(      feoarrm3n1_t* arr);
  void      feoarrm3n1_sin_to(   feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_cos(      feoarrm3n1_t* arr);
  void      feoarrm3n1_cos_to(   feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_logb(     feoarrm3n1_t* arr, double base);
  void      feoarrm3n1_logb_to(  feoarrm3n1_t* arr, double base, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_log10(    feoarrm3n1_t* arr);
  void      feoarrm3n1_log10_to( feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_log(      feoarrm3n1_t* arr);
  void      feoarrm3n1_log_to(   feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_exp(      feoarrm3n1_t* arr);
  void      feoarrm3n1_exp_to(   feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_cbrt(     feoarrm3n1_t* arr);
  void      feoarrm3n1_cbrt_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sqrt(     feoarrm3n1_t* arr);
  void      feoarrm3n1_sqrt_to(  feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_pow(      feoarrm3n1_t* arr, double e);
  void      feoarrm3n1_pow_to(   feoarrm3n1_t* arr, double e, feoarrm3n1_t* res);
  
  
  # From ../../../include/oti/static/onumm3n1/array/gauss/base.h
  
  void      feoarrm3n1_get_order_im_to( ord_t order, feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_get_order_im(    ord_t order, feoarrm3n1_t* arr);
  feoarrm3n1_t feoarrm3n1_get_deriv(   imdir_t idx, ord_t order, feoarrm3n1_t* arr);
  void      feoarrm3n1_get_deriv_to(imdir_t idx, ord_t order, feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_get_im(      imdir_t idx, ord_t order, feoarrm3n1_t* arr);
  void      feoarrm3n1_get_im_to(   imdir_t idx, ord_t order, feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_truncate_im(   imdir_t idx, ord_t order, feoarrm3n1_t* arr);
  void      feoarrm3n1_truncate_im_to(imdir_t idx, ord_t order, feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_copy(   feoarrm3n1_t* src);
  void      feoarrm3n1_copy_to(feoarrm3n1_t* src, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_get_im(    imdir_t idx, ord_t order, feoarrm3n1_t* arr);
  void      feoarrm3n1_get_im_to( imdir_t idx, ord_t order, feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_get_deriv(    imdir_t idx, ord_t order, feoarrm3n1_t* arr);
  void      feoarrm3n1_get_deriv_to( imdir_t idx, ord_t order, feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_extract_im(    imdir_t idx, ord_t order, feoarrm3n1_t* arr);
  void      feoarrm3n1_extract_im_to( imdir_t idx, ord_t order, feoarrm3n1_t* arr,  feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_extract_deriv(    imdir_t idx, ord_t order, feoarrm3n1_t* arr);
  void      feoarrm3n1_extract_deriv_to( imdir_t idx, ord_t order, feoarrm3n1_t* arr, feoarrm3n1_t* res);
  oarrm3n1_t   feoarrm3n1_get_item_k(  feoarrm3n1_t* arr, uint64_t k);
  feonumm3n1_t  feoarrm3n1_get_item_ij( feoarrm3n1_t* arr, uint64_t i, uint64_t j);
  onumm3n1_t feoarrm3n1_get_item_ijk(feoarrm3n1_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm3n1_get_item_ij_to(  feoarrm3n1_t* arr, uint64_t i, uint64_t j,
                                 feonumm3n1_t* res);
  void feoarrm3n1_get_item_k_to(   feoarrm3n1_t* arr, uint64_t k,
                                  oarrm3n1_t* res);
  void feoarrm3n1_get_item_ijk_to( feoarrm3n1_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_get_slice(feoarrm3n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm3n1_get_slice_to(feoarrm3n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n1_t* res);
  void feoarrm3n1_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm3n1_t* res);
  void feoarrm3n1_set_item_ij_o(  onumm3n1_t* elm, uint64_t i, uint64_t j,
                               feoarrm3n1_t* res);
  void feoarrm3n1_set_item_ij_f(  feonumm3n1_t* elm, uint64_t i, uint64_t j,
                              feoarrm3n1_t* res);
  void feoarrm3n1_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm3n1_t* res);
  void feoarrm3n1_set_item_k_o(  onumm3n1_t* elm, uint64_t k,
                              feoarrm3n1_t* res);
  void feoarrm3n1_set_item_k_R(    oarrm3n1_t* elm, uint64_t k,
                            feoarrm3n1_t* res);
  void feoarrm3n1_set_item_k_O(    oarrm3n1_t* elm, uint64_t k,
                            feoarrm3n1_t* res);
  void feoarrm3n1_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm3n1_t* res);
  void feoarrm3n1_set_item_ijk_o( onumm3n1_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm3n1_t* res);
  void feoarrm3n1_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n1_t* res);
  void feoarrm3n1_set_slice_o( onumm3n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n1_t* res);
  void feoarrm3n1_set_slice_f( feonumm3n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n1_t* res);
  void feoarrm3n1_set_slice_O( oarrm3n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n1_t* res);
  void feoarrm3n1_set_slice_F( feoarrm3n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n1_t* res);
  void feoarrm3n1_set_all_o( onumm3n1_t* num, feoarrm3n1_t* arr );
  void feoarrm3n1_set_all_r(   coeff_t  num, feoarrm3n1_t* arr );
  void feoarrm3n1_set_all_f(  feonumm3n1_t* num, feoarrm3n1_t* arr );
  void feoarrm3n1_set_r(    coeff_t src, feoarrm3n1_t* res );
  void feoarrm3n1_set_o( onumm3n1_t* src, feoarrm3n1_t* res );
  void feoarrm3n1_set_f(  feonumm3n1_t* src, feoarrm3n1_t* res );
  void feoarrm3n1_set_R(    darr_t* src, feoarrm3n1_t* res );
  void feoarrm3n1_set_O(   oarrm3n1_t* src, feoarrm3n1_t* res );
  void feoarrm3n1_set_F( feoarrm3n1_t* src, feoarrm3n1_t* res );
  feoarrm3n1_t feoarrm3n1_eye( uint64_t size,  uint64_t nip);
  feoarrm3n1_t feoarrm3n1_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm3n1_t feoarrm3n1_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm3n1_t feoarrm3n1_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm3n1_free(feoarrm3n1_t* arr);
  feoarrm3n1_t feoarrm3n1_init();
  ord_t feoarrm3n1_get_order(feoarrm3n1_t* arr);
  
  
  # From ../../../include/oti/static/onumm3n1/array/gauss/utils.h
  
  void feoarrm3n1_dimCheck_FF_samesize(feoarrm3n1_t* arr1, feoarrm3n1_t* arr2, feonumm3n1_t* res);
  void feoarrm3n1_dimCheck_OF_samesize(  oarrm3n1_t* arr1, feoarrm3n1_t* arr2, feonumm3n1_t* res);
  void feoarrm3n1_dimCheck_RF_samesize(   darr_t* arr1, feoarrm3n1_t* arr2, feonumm3n1_t* res);
  void feoarrm3n1_dimCheck_FF_elementwise(feoarrm3n1_t* arr1, feoarrm3n1_t* arr2, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_OF_elementwise(  oarrm3n1_t* arr1, feoarrm3n1_t* arr2, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm3n1_t* arr2, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_fF_elementwise( feonumm3n1_t* num1, feoarrm3n1_t* arr2, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_Ff_elementwise(feoarrm3n1_t* arr1,  feonumm3n1_t* num2, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_FF_matmul( feoarrm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_OF_matmul(   oarrm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_FO_matmul( feoarrm3n1_t* lhs,   oarrm3n1_t* rhs, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_FR_matmul( feoarrm3n1_t* lhs,    darr_t* rhs, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_F_squareness( feoarrm3n1_t* arr1, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_F_transpose( feoarrm3n1_t* arr1, feoarrm3n1_t* res);
  void feoarrm3n1_dimCheck_FfO_integrate(feoarrm3n1_t* arr, feonumm3n1_t* num,oarrm3n1_t* res);
  void feoarrm3n1_get_active_bases(feoarrm3n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n1/array/gauss/algebra.h
  
  feoarrm3n1_t feoarrm3n1_neg(    feoarrm3n1_t* arr);
  void      feoarrm3n1_neg_to( feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sum_FF(   feoarrm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sum_FF_to(feoarrm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sum_fF(    feonumm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sum_fF_to( feonumm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sum_OF(     oarrm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sum_OF_to(  oarrm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sum_RF(      darr_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sum_RF_to(   darr_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sum_oF(   onumm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sum_oF_to(onumm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sum_rF(     coeff_t  lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sum_rF_to(  coeff_t  lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sub_FF(    feoarrm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sub_FF_to( feoarrm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sub_fF(    feonumm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sub_fF_to( feonumm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sub_Ff(    feoarrm3n1_t* lhs, feonumm3n1_t* rhs);
  void      feoarrm3n1_sub_Ff_to( feoarrm3n1_t* lhs, feonumm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sub_OF(      oarrm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sub_OF_to(   oarrm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sub_FO(    feoarrm3n1_t* lhs,   oarrm3n1_t* rhs);
  void      feoarrm3n1_sub_FO_to( feoarrm3n1_t* lhs,   oarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sub_RF(       darr_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sub_RF_to(    darr_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sub_FR(    feoarrm3n1_t* lhs,    darr_t* rhs);
  void      feoarrm3n1_sub_FR_to( feoarrm3n1_t* lhs,    darr_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sub_oF(    onumm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sub_oF_to( onumm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sub_Fo(    feoarrm3n1_t* lhs, onumm3n1_t* rhs);
  void      feoarrm3n1_sub_Fo_to( feoarrm3n1_t* lhs, onumm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sub_rF(      coeff_t  lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_sub_rF_to(    coeff_t lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_sub_Fr(    feoarrm3n1_t* lhs,   coeff_t  rhs);
  void      feoarrm3n1_sub_Fr_to( feoarrm3n1_t* lhs,   coeff_t  rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_mul_FF(   feoarrm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_mul_FF_to(feoarrm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_mul_fF(    feonumm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_mul_fF_to( feonumm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_mul_OF(     oarrm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_mul_OF_to(  oarrm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_mul_RF(      darr_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_mul_RF_to(   darr_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_mul_oF(   onumm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_mul_oF_to(onumm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_mul_rF(     coeff_t  lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_mul_rF_to(  coeff_t  lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_div_FF(    feoarrm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_div_FF_to( feoarrm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_div_fF(     feonumm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_div_fF_to(  feonumm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_div_Ff(    feoarrm3n1_t* lhs,  feonumm3n1_t* rhs);
  void      feoarrm3n1_div_Ff_to( feoarrm3n1_t* lhs,  feonumm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_div_OF(      oarrm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_div_OF_to(   oarrm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_div_FO(    feoarrm3n1_t* lhs,   oarrm3n1_t* rhs);
  void      feoarrm3n1_div_FO_to( feoarrm3n1_t* lhs,   oarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_div_RF(       darr_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_div_RF_to(    darr_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_div_FR(    feoarrm3n1_t* lhs,    darr_t* rhs);
  void      feoarrm3n1_div_FR_to( feoarrm3n1_t* lhs,    darr_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_div_oF(    onumm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_div_oF_to( onumm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_div_Fo(    feoarrm3n1_t* lhs, onumm3n1_t* rhs);
  void      feoarrm3n1_div_Fo_to( feoarrm3n1_t* lhs, onumm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_div_rF(      coeff_t  lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_div_rF_to(    coeff_t lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_div_Fr(    feoarrm3n1_t* lhs,   coeff_t  rhs);
  void      feoarrm3n1_div_Fr_to( feoarrm3n1_t* lhs,   coeff_t  rhs, feoarrm3n1_t* res);
  oarrm3n1_t feoarrm3n1_integrate(    feoarrm3n1_t* arr, feonumm3n1_t* w);
  void    feoarrm3n1_integrate_to( feoarrm3n1_t* arr, feonumm3n1_t* w, oarrm3n1_t* res);
  feonumm3n1_t feoarrm3n1_dotproduct_FF(    feoarrm3n1_t* lhs, feoarrm3n1_t* rhs);
  void     feoarrm3n1_dotproduct_FF_to( feoarrm3n1_t* lhs, feoarrm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feoarrm3n1_dotproduct_OF(      oarrm3n1_t* lhs, feoarrm3n1_t* rhs);
  void     feoarrm3n1_dotproduct_OF_to(   oarrm3n1_t* lhs, feoarrm3n1_t* rhs, feonumm3n1_t* res);
  feonumm3n1_t feoarrm3n1_dotproduct_RF(       darr_t* lhs, feoarrm3n1_t* rhs);
  void     feoarrm3n1_dotproduct_RF_to(    darr_t* lhs, feoarrm3n1_t* rhs, feonumm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_matmul_FF(    feoarrm3n1_t* lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_matmul_FF_to( feoarrm3n1_t* lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_matmul_OF(    oarrm3n1_t*   lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_matmul_OF_to( oarrm3n1_t*   lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_matmul_FO(    feoarrm3n1_t* lhs, oarrm3n1_t*   rhs);
  void      feoarrm3n1_matmul_FO_to( feoarrm3n1_t* lhs, oarrm3n1_t*   rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_matmul_RF(    darr_t*    lhs, feoarrm3n1_t* rhs);
  void      feoarrm3n1_matmul_RF_to( darr_t*    lhs, feoarrm3n1_t* rhs, feoarrm3n1_t* res);
  feoarrm3n1_t feoarrm3n1_matmul_FR(    feoarrm3n1_t* lhs, darr_t*    rhs);
  void      feoarrm3n1_matmul_FR_to( feoarrm3n1_t* lhs, darr_t*    rhs, feoarrm3n1_t* res);
  feonumm3n1_t feoarrm3n1_det(   feoarrm3n1_t* arr);
  void     feoarrm3n1_det_to(feoarrm3n1_t* arr, feonumm3n1_t* res);
  feonumm3n1_t feoarrm3n1_norm(     feoarrm3n1_t* arr);
  void     feoarrm3n1_norm_to(  feoarrm3n1_t* arr, feonumm3n1_t* res);
  feonumm3n1_t feoarrm3n1_pnorm(    feoarrm3n1_t* arr, coeff_t p);
  void     feoarrm3n1_pnorm_to( feoarrm3n1_t* arr, coeff_t p, feonumm3n1_t* res);
  feoarrm3n1_t   feoarrm3n1_invert(    feoarrm3n1_t* arr);
  void        feoarrm3n1_invert_to( feoarrm3n1_t* arr, feoarrm3n1_t* res);
  feoarrm3n1_t   feoarrm3n1_transpose(   feoarrm3n1_t* arr);
  void        feoarrm3n1_transpose_to(feoarrm3n1_t* arr, feoarrm3n1_t* res);
  
  