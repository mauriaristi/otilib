cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm3n2/scalar/structures.h
  
  ctypedef struct  onumm3n2_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e11;
    coeff_t e12;
    coeff_t e22;
    coeff_t e13;
    coeff_t e23;
    coeff_t e33;
  # } onumm3n2_t;
  
  
  # From ../../../include/oti/static/onumm3n2/array/structures.h
  
  ctypedef struct  oarrm3n2_t : # {
      onumm3n2_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm3n2_t;
  
  
  # From ../../../include/oti/static/onumm3n2/scalar/gauss/structures.h
  
  ctypedef struct  feonumm3n2_t: # {
      onumm3n2_t*  p_data;
      uint64_t    nip;
  # } feonumm3n2_t;
  
  
  # From ../../../include/oti/static/onumm3n2/array/gauss/structures.h
  
  ctypedef struct  feoarrm3n2_t: # {
      oarrm3n2_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm3n2_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm3n2/scalar/functions.h
  
  onumm3n2_t onumm3n2_atanh(onumm3n2_t* num);
  void onumm3n2_atanh_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_asinh(onumm3n2_t* num);
  void onumm3n2_asinh_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_acosh(onumm3n2_t* num);
  void onumm3n2_acosh_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_tanh(onumm3n2_t* num);
  void onumm3n2_tanh_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_sqrt(onumm3n2_t* num);
  void onumm3n2_sqrt_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_cbrt(onumm3n2_t* num);
  void onumm3n2_cbrt_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_cosh(onumm3n2_t* num);
  void onumm3n2_cosh_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_sinh(onumm3n2_t* num);
  void onumm3n2_sinh_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_asin(onumm3n2_t* num);
  void onumm3n2_asin_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_acos(onumm3n2_t* num);
  void onumm3n2_acos_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_atan(onumm3n2_t* num);
  void onumm3n2_atan_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_tan(onumm3n2_t* num);
  void onumm3n2_tan_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_cos(onumm3n2_t* num);
  void onumm3n2_cos_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_sin(onumm3n2_t* num );
  void onumm3n2_sin_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_logb(onumm3n2_t* num, double base);
  void onumm3n2_logb_to(onumm3n2_t* num, double base, onumm3n2_t* res);
  onumm3n2_t onumm3n2_log10(onumm3n2_t* num);
  void onumm3n2_log10_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_log(onumm3n2_t* num);
  void onumm3n2_log_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_exp(onumm3n2_t* num);
  void onumm3n2_exp_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_pow(onumm3n2_t* num, double e);
  void onumm3n2_pow_to(onumm3n2_t* num, coeff_t e, onumm3n2_t* res);
  
  
  # From ../../../include/oti/static/onumm3n2/scalar/base.h
  
  void onumm3n2_set_im_o(onumm3n2_t* num, imdir_t idx, ord_t order, onumm3n2_t* res);
  void onumm3n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm3n2_t* res);
  void onumm3n2_set_deriv_o(onumm3n2_t* num, imdir_t idx, ord_t order, onumm3n2_t* res);
  void onumm3n2_extract_im_to( imdir_t idx, ord_t order, onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_extract_im(imdir_t idx, ord_t order, onumm3n2_t* num);
  onumm3n2_t onumm3n2_extract_deriv(imdir_t idx, ord_t order, onumm3n2_t* num);
  void onumm3n2_extract_deriv_to(imdir_t idx, ord_t order, onumm3n2_t* num, onumm3n2_t* res);
  void onumm3n2_get_im_to_o(imdir_t idx, ord_t order, onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_get_im_o(imdir_t idx, ord_t order, onumm3n2_t* num);
  void onumm3n2_get_im_to_r(imdir_t idx, ord_t order, onumm3n2_t* num, coeff_t* res);
  ord_t onumm3n2_get_order(onumm3n2_t* lhs);
  onumm3n2_t onumm3n2_get_deriv_o( imdir_t idx, ord_t order, onumm3n2_t* num);
  void onumm3n2_get_deriv_to( imdir_t idx, ord_t order, onumm3n2_t* num, onumm3n2_t* res);
  void onumm3n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm3n2_t* res);
  onumm3n2_t onumm3n2_init();
  ndir_t onumm3n2_get_ndir_order(ord_t order, onumm3n2_t* num);
  ndir_t onumm3n2_get_ndir_total(onumm3n2_t* num);
  coeff_t* onumm3n2_get_order_address(ord_t order, onumm3n2_t* num);
  onumm3n2_t onumm3n2_create_r(  coeff_t lhs);
  void onumm3n2_set_r(  coeff_t lhs, onumm3n2_t* res);
  void onumm3n2_set_o(  onumm3n2_t* lhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_get_order_im(ord_t order, onumm3n2_t* lhs);
  void onumm3n2_get_order_im_to(ord_t order, onumm3n2_t* lhs, onumm3n2_t* res);
  coeff_t onumm3n2_get_item(imdir_t idx, ord_t order, onumm3n2_t* lhs);
  coeff_t onumm3n2_get_deriv(imdir_t idx, ord_t order, onumm3n2_t* lhs);
  void onumm3n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm3n2_t* x);
  onumm3n2_t onumm3n2_copy(  onumm3n2_t* lhs);
  void onumm3n2_copy_to(  onumm3n2_t* lhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_taylor_integrate(coeff_t* deltas,onumm3n2_t* lhs);
  void onumm3n2_taylor_integrate_to(coeff_t* deltas,onumm3n2_t* lhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_truncate_im(imdir_t idx, ord_t order, onumm3n2_t* lhs);
  void onumm3n2_truncate_im_to(imdir_t idx, ord_t order, onumm3n2_t* lhs, onumm3n2_t* res);
  void onumm3n2_print(  onumm3n2_t* lhs);
  imdir_t onumm3n2_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm3n2/scalar/utils.h
  
  void onumm3n2_get_active_bases(onumm3n2_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm3n2/scalar/algebra.h
  
  onumm3n2_t onumm3n2_abs(onumm3n2_t* num);
  onumm3n2_t onumm3n2_div_ro(coeff_t num, onumm3n2_t* den);
  onumm3n2_t onumm3n2_div_oo(onumm3n2_t* num, onumm3n2_t* den);
  onumm3n2_t onumm3n2_div_or(onumm3n2_t* num, coeff_t val);
  void onumm3n2_div_ro_to(coeff_t num, onumm3n2_t* den, onumm3n2_t* res);
  void onumm3n2_div_oo_to(onumm3n2_t* num, onumm3n2_t* den, onumm3n2_t* res);
  void onumm3n2_div_or_to(onumm3n2_t* num, coeff_t val, onumm3n2_t* res);
  void onumm3n2_abs_to(onumm3n2_t* num, onumm3n2_t* res);
  onumm3n2_t onumm3n2_neg(  onumm3n2_t* lhs);
  void onumm3n2_neg_to(  onumm3n2_t* lhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_sum_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
  void onumm3n2_sum_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_sum_ro(  coeff_t lhs,  onumm3n2_t* rhs);
  void onumm3n2_sum_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_sub_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
  void onumm3n2_sub_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_sub_ro(  coeff_t lhs,  onumm3n2_t* rhs);
  void onumm3n2_sub_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_sub_or(  onumm3n2_t* lhs,  coeff_t rhs);
  void onumm3n2_sub_or_to(  onumm3n2_t* lhs,  coeff_t rhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_mul_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
  void onumm3n2_mul_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_mul_ro(  coeff_t lhs,  onumm3n2_t* rhs);
  void onumm3n2_mul_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_trunc_mul_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
  void onumm3n2_trunc_mul_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_gem_oo(  onumm3n2_t* a,  onumm3n2_t* b,  onumm3n2_t* c);
  void onumm3n2_gem_oo_to(  onumm3n2_t* a,  onumm3n2_t* b,  onumm3n2_t* c, onumm3n2_t* res);
  onumm3n2_t onumm3n2_gem_ro(  coeff_t a,  onumm3n2_t* b,  onumm3n2_t* c);
  void onumm3n2_gem_ro_to(  coeff_t a,  onumm3n2_t* b,  onumm3n2_t* c, onumm3n2_t* res);
  void onumm3n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm3n2_t* a,  ord_t ord_rhs,  onumm3n2_t* b,  onumm3n2_t* c, onumm3n2_t* res);
  void onumm3n2_trunc_sum_oo_to(ord_t order, onumm3n2_t* lhs,onumm3n2_t* rhs, onumm3n2_t* res);
  void onumm3n2_trunc_sub_oo_to(ord_t order, onumm3n2_t* lhs,onumm3n2_t* rhs, onumm3n2_t* res);
  onumm3n2_t onumm3n2_feval(coeff_t* feval_re, onumm3n2_t* x);
  void onumm3n2_feval_to(coeff_t* feval_re, onumm3n2_t* x, onumm3n2_t* res);
  
  
  # From ../../../include/oti/static/onumm3n2/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm3n2/scalar/gauss/functions.h
  
  feonumm3n2_t feonumm3n2_atanh(    feonumm3n2_t* num);
  void     feonumm3n2_atanh_to( feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_asinh(    feonumm3n2_t* num);
  void     feonumm3n2_asinh_to( feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_acosh(    feonumm3n2_t* num);
  void     feonumm3n2_acosh_to( feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_tanh(     feonumm3n2_t* num);
  void     feonumm3n2_tanh_to(  feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_cosh(     feonumm3n2_t* num);
  void     feonumm3n2_cosh_to(  feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_sinh(     feonumm3n2_t* num);
  void     feonumm3n2_sinh_to(  feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_asin(     feonumm3n2_t* num);
  void     feonumm3n2_asin_to(  feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_acos(     feonumm3n2_t* num);
  void     feonumm3n2_acos_to(  feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_atan(     feonumm3n2_t* num);
  void     feonumm3n2_atan_to(  feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_tan(      feonumm3n2_t* num);
  void     feonumm3n2_tan_to(   feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_cos(      feonumm3n2_t* num);
  void     feonumm3n2_cos_to(   feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_sin(      feonumm3n2_t* num);
  void     feonumm3n2_sin_to(   feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_logb(     feonumm3n2_t* num, double base);
  void     feonumm3n2_logb_to(  feonumm3n2_t* num, double base, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_log10(    feonumm3n2_t* num);
  void     feonumm3n2_log10_to( feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_log(      feonumm3n2_t* num);
  void     feonumm3n2_log_to(   feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_exp(      feonumm3n2_t* num);
  void     feonumm3n2_exp_to(   feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_cbrt(     feonumm3n2_t* num);
  void     feonumm3n2_cbrt_to(  feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_sqrt(     feonumm3n2_t* num);
  void     feonumm3n2_sqrt_to(  feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_pow(      feonumm3n2_t* num, double e);
  void     feonumm3n2_pow_to(   feonumm3n2_t* num, double e, feonumm3n2_t* res);
  onumm3n2_t feonumm3n2_integrate(       feonumm3n2_t* num, feonumm3n2_t* w);
  void      feonumm3n2_integrate_to(    feonumm3n2_t* num, feonumm3n2_t* w, onumm3n2_t* res);
  onumm3n2_t feonumm3n2_integrate_f(     feonumm3n2_t* num, feonumm3n2_t* w);
  void      feonumm3n2_integrate_f_to(  feonumm3n2_t* num, feonumm3n2_t* w, onumm3n2_t* res);
  onumm3n2_t feonumm3n2_integrate_r(       coeff_t num, feonumm3n2_t* w);
  void      feonumm3n2_integrate_r_to(    coeff_t num, feonumm3n2_t* w, onumm3n2_t* res);
  onumm3n2_t feonumm3n2_integrate_o(    onumm3n2_t* num, feonumm3n2_t* w);
  void      feonumm3n2_integrate_o_to( onumm3n2_t* num, feonumm3n2_t* w, onumm3n2_t* res);
  
  
  # From ../../../include/oti/static/onumm3n2/scalar/gauss/base.h
  
  void     feonumm3n2_get_order_im_to( ord_t order, feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_get_order_im(    ord_t order, feonumm3n2_t* num);
  feonumm3n2_t feonumm3n2_get_im(    imdir_t idx, ord_t order, feonumm3n2_t* num);
  void     feonumm3n2_get_im_to( imdir_t idx, ord_t order, feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_get_deriv(    imdir_t idx, ord_t order, feonumm3n2_t* num);
  void     feonumm3n2_get_deriv_to( imdir_t idx, ord_t order, feonumm3n2_t* num, feonumm3n2_t* res);
  void feonumm3n2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm3n2_t* num);
  void feonumm3n2_set_im_o( onumm3n2_t* val, imdir_t idx, ord_t order, feonumm3n2_t* num);
  void feonumm3n2_set_im_f(  feonumm3n2_t* val, imdir_t idx, ord_t order, feonumm3n2_t* num);
  void feonumm3n2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm3n2_t* num);
  void feonumm3n2_set_deriv_o( onumm3n2_t* val, imdir_t idx, ord_t order, feonumm3n2_t* num);
  void feonumm3n2_set_deriv_f(  feonumm3n2_t* val, imdir_t idx, ord_t order, feonumm3n2_t* num);
  feonumm3n2_t feonumm3n2_extract_im(    imdir_t idx, ord_t order, feonumm3n2_t* num);
  void     feonumm3n2_extract_im_to( imdir_t idx, ord_t order, feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_extract_deriv(    imdir_t idx, ord_t order, feonumm3n2_t* num);
  void     feonumm3n2_extract_deriv_to( imdir_t idx, ord_t order, feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_truncate_im(    imdir_t idx, ord_t order, feonumm3n2_t* num);
  void     feonumm3n2_truncate_im_to( imdir_t idx, ord_t order, feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_copy(    feonumm3n2_t* src);
  void     feonumm3n2_copy_to( feonumm3n2_t* src, feonumm3n2_t* dst);
  void feonumm3n2_set_r(    coeff_t num, feonumm3n2_t* res);
  void feonumm3n2_set_o( onumm3n2_t* num, feonumm3n2_t* res);
  void feonumm3n2_set_f(  feonumm3n2_t* num, feonumm3n2_t* res);
  void feonumm3n2_set_item_k_r(   coeff_t  num, uint64_t k, feonumm3n2_t* res);
  void feonumm3n2_set_item_k_o( onumm3n2_t* num, uint64_t k, feonumm3n2_t* res);
  onumm3n2_t feonumm3n2_get_item_k(   feonumm3n2_t* num, uint64_t k);
  void      feonumm3n2_get_item_k_to(feonumm3n2_t* num, uint64_t k, onumm3n2_t* res);
  feonumm3n2_t feonumm3n2_zeros(uint64_t nIntPts);
  feonumm3n2_t feonumm3n2_createEmpty(uint64_t nIntPts);
  feonumm3n2_t feonumm3n2_empty_like(feonumm3n2_t* arr);
  void feonumm3n2_free(feonumm3n2_t* num);
  ord_t feonumm3n2_get_order( feonumm3n2_t* num );
  feonumm3n2_t feonumm3n2_init();
  
  
  # From ../../../include/oti/static/onumm3n2/scalar/gauss/utils.h
  
  void feonumm3n2_dimCheck(feonumm3n2_t* arr1,feonumm3n2_t* arr2);
  void feonumm3n2_get_active_bases(feonumm3n2_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n2/scalar/gauss/algebra.h
  
  feonumm3n2_t feonumm3n2_neg(   feonumm3n2_t* num);
  void     feonumm3n2_neg_to(feonumm3n2_t* num, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_sum_ff(   feonumm3n2_t* lhs, feonumm3n2_t* rhs);
  void     feonumm3n2_sum_ff_to(feonumm3n2_t* lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_sum_of(   onumm3n2_t* lhs, feonumm3n2_t* rhs);
  void     feonumm3n2_sum_of_to(onumm3n2_t* lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_sum_rf(   coeff_t lhs, feonumm3n2_t* rhs);
  void     feonumm3n2_sum_rf_to(coeff_t lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_sub_ff(     feonumm3n2_t* lhs,  feonumm3n2_t* rhs);
  void     feonumm3n2_sub_ff_to(  feonumm3n2_t* lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_sub_of(    onumm3n2_t* lhs,  feonumm3n2_t* rhs);
  void     feonumm3n2_sub_of_to( onumm3n2_t* lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_sub_fo(     feonumm3n2_t* lhs, onumm3n2_t* rhs);
  void     feonumm3n2_sub_fo_to(  feonumm3n2_t* lhs, onumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_sub_rf(       coeff_t lhs,  feonumm3n2_t* rhs);
  void     feonumm3n2_sub_rf_to(    coeff_t lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_sub_fr(     feonumm3n2_t* lhs,    coeff_t rhs);
  void     feonumm3n2_sub_fr_to(  feonumm3n2_t* lhs,    coeff_t rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_mul_ff(   feonumm3n2_t* lhs, feonumm3n2_t* rhs);
  void     feonumm3n2_mul_ff_to(feonumm3n2_t* lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_mul_of(   onumm3n2_t* lhs, feonumm3n2_t* rhs);
  void     feonumm3n2_mul_of_to(onumm3n2_t* lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_mul_rf(   coeff_t lhs, feonumm3n2_t* rhs);
  void     feonumm3n2_mul_rf_to(coeff_t lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_div_ff(     feonumm3n2_t* lhs,  feonumm3n2_t* rhs);
  void     feonumm3n2_div_ff_to(  feonumm3n2_t* lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_div_of(    onumm3n2_t* lhs,  feonumm3n2_t* rhs);
  void     feonumm3n2_div_of_to( onumm3n2_t* lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_div_fo(     feonumm3n2_t* lhs, onumm3n2_t* rhs);
  void     feonumm3n2_div_fo_to(  feonumm3n2_t* lhs, onumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_div_rf(       coeff_t lhs,  feonumm3n2_t* rhs);
  void     feonumm3n2_div_rf_to(    coeff_t lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feonumm3n2_div_fr(     feonumm3n2_t* lhs,    coeff_t rhs);
  void     feonumm3n2_div_fr_to(  feonumm3n2_t* lhs,    coeff_t rhs, feonumm3n2_t* res);
  
  
  # From ../../../include/oti/static/onumm3n2/array/functions.h
  
  oarrm3n2_t oarrm3n2_atanh(   oarrm3n2_t* arr);
  void    oarrm3n2_atanh_to(oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_asinh(   oarrm3n2_t* arr);
  void    oarrm3n2_asinh_to(oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_acosh(   oarrm3n2_t* arr);
  void    oarrm3n2_acosh_to(oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_tanh(    oarrm3n2_t* arr);
  void    oarrm3n2_tanh_to( oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_cbrt(    oarrm3n2_t* arr);
  void    oarrm3n2_cbrt_to( oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_sqrt(    oarrm3n2_t* arr);
  void    oarrm3n2_sqrt_to( oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_cosh(    oarrm3n2_t* arr);
  void    oarrm3n2_cosh_to( oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_sinh(    oarrm3n2_t* arr);
  void    oarrm3n2_sinh_to( oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_asin(    oarrm3n2_t* arr);
  void    oarrm3n2_asin_to( oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_acos(    oarrm3n2_t* arr);
  void    oarrm3n2_acos_to( oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_atan(    oarrm3n2_t* arr);
  void    oarrm3n2_atan_to( oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_tan(     oarrm3n2_t* arr);
  void    oarrm3n2_tan_to(  oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_cos(     oarrm3n2_t* arr);
  void    oarrm3n2_cos_to(  oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_sin(     oarrm3n2_t* arr);
  void    oarrm3n2_sin_to(  oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_logb(    oarrm3n2_t* arr, double base);
  void    oarrm3n2_logb_to( oarrm3n2_t* arr, double base, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_log10(   oarrm3n2_t* arr);
  void    oarrm3n2_log10_to(oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_log(     oarrm3n2_t* arr);
  void    oarrm3n2_log_to(  oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_exp(     oarrm3n2_t* arr);
  void    oarrm3n2_exp_to(  oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_pow(     oarrm3n2_t* arr, double e);
  void    oarrm3n2_pow_to(  oarrm3n2_t* arr, double e, oarrm3n2_t* res);
  
  
  # From ../../../include/oti/static/onumm3n2/array/algebra_elementwise.h
  
  oarrm3n2_t oarrm3n2_neg(oarrm3n2_t* arr);
  void oarrm3n2_neg_to(oarrm3n2_t* rhs, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_sum_OO(oarrm3n2_t*   lhs, oarrm3n2_t* rhs);
  oarrm3n2_t oarrm3n2_sum_RO(darr_t*    lhs, oarrm3n2_t* rhs);
  oarrm3n2_t oarrm3n2_sum_oO(onumm3n2_t* lhs, oarrm3n2_t* rhs);
  oarrm3n2_t oarrm3n2_sum_rO(coeff_t    lhs, oarrm3n2_t* rhs);
  void oarrm3n2_sum_OO_to(oarrm3n2_t*   lhs, oarrm3n2_t* rhs, oarrm3n2_t* res);
  void oarrm3n2_sum_RO_to(darr_t*    lhs, oarrm3n2_t* rhs, oarrm3n2_t* res);
  void oarrm3n2_sum_oO_to(onumm3n2_t* lhs, oarrm3n2_t* rhs, oarrm3n2_t* res);
  void oarrm3n2_sum_rO_to(coeff_t    lhs, oarrm3n2_t* rhs, oarrm3n2_t* res);
  void oarrm3n2_trunc_sum_OO_to(ord_t order, oarrm3n2_t* arr1, oarrm3n2_t* arr2, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_sub_OO(oarrm3n2_t*   lhs, oarrm3n2_t*   rhs);
  oarrm3n2_t oarrm3n2_sub_RO(darr_t*    lhs, oarrm3n2_t*   rhs);
  oarrm3n2_t oarrm3n2_sub_OR(oarrm3n2_t*   lhs, darr_t*    rhs);
  oarrm3n2_t oarrm3n2_sub_oO(onumm3n2_t* lhs, oarrm3n2_t*   rhs);
  oarrm3n2_t oarrm3n2_sub_Oo(oarrm3n2_t*   lhs, onumm3n2_t* rhs);
  oarrm3n2_t oarrm3n2_sub_rO(coeff_t    lhs, oarrm3n2_t*   rhs);
  oarrm3n2_t oarrm3n2_sub_Or(oarrm3n2_t*   lhs, coeff_t    rhs);
  void oarrm3n2_sub_OO_to( oarrm3n2_t*   lhs, oarrm3n2_t*   rhs, oarrm3n2_t* res);
  void oarrm3n2_sub_RO_to( darr_t*    lhs, oarrm3n2_t*   rhs, oarrm3n2_t* res);
  void oarrm3n2_sub_OR_to( oarrm3n2_t*   lhs, darr_t*    rhs, oarrm3n2_t* res);
  void oarrm3n2_sub_oO_to( onumm3n2_t* lhs, oarrm3n2_t*   rhs, oarrm3n2_t* res);
  void oarrm3n2_sub_Oo_to( oarrm3n2_t*   lhs, onumm3n2_t* rhs, oarrm3n2_t* res);
  void oarrm3n2_sub_rO_to( coeff_t    lhs, oarrm3n2_t*   rhs, oarrm3n2_t* res);
  void oarrm3n2_sub_Or_to( oarrm3n2_t*   lhs, coeff_t    rhs, oarrm3n2_t* res);
  void oarrm3n2_trunc_sub_OO_to(ord_t order, oarrm3n2_t* arr1, oarrm3n2_t* arr2, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_mul_OO(oarrm3n2_t*   lhs, oarrm3n2_t* rhs);
  oarrm3n2_t oarrm3n2_mul_RO(darr_t*    lhs, oarrm3n2_t* rhs);
  oarrm3n2_t oarrm3n2_mul_oO(onumm3n2_t* lhs, oarrm3n2_t* rhs);
  oarrm3n2_t oarrm3n2_mul_rO(coeff_t    lhs, oarrm3n2_t* rhs);
  void oarrm3n2_mul_OO_to(oarrm3n2_t*   lhs, oarrm3n2_t* rhs, oarrm3n2_t* res);
  void oarrm3n2_mul_RO_to(darr_t*    lhs, oarrm3n2_t* rhs, oarrm3n2_t* res);
  void oarrm3n2_mul_oO_to(onumm3n2_t* lhs, oarrm3n2_t* rhs, oarrm3n2_t* res);
  void oarrm3n2_mul_rO_to(coeff_t    lhs, oarrm3n2_t* rhs, oarrm3n2_t* res);
  void oarrm3n2_gem_OO_to(  oarrm3n2_t* arr1, oarrm3n2_t* arr2, oarrm3n2_t* arr3, oarrm3n2_t* res);
  void oarrm3n2_gem_oO_to(onumm3n2_t* arr1, oarrm3n2_t* arr2, oarrm3n2_t* arr3, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_div_OO(oarrm3n2_t*   lhs, oarrm3n2_t*   rhs);
  oarrm3n2_t oarrm3n2_div_OR(oarrm3n2_t*   lhs, darr_t*    rhs);
  oarrm3n2_t oarrm3n2_div_RO(darr_t*    lhs, oarrm3n2_t*   rhs);
  oarrm3n2_t oarrm3n2_div_oO(onumm3n2_t* lhs, oarrm3n2_t*   rhs);
  oarrm3n2_t oarrm3n2_div_Oo(oarrm3n2_t*   lhs, onumm3n2_t* rhs);
  oarrm3n2_t oarrm3n2_div_rO(coeff_t    lhs, oarrm3n2_t*   rhs);
  oarrm3n2_t oarrm3n2_div_Or(oarrm3n2_t*   lhs, coeff_t    rhs);
  void oarrm3n2_div_OO_to(oarrm3n2_t*   lhs, oarrm3n2_t*   rhs, oarrm3n2_t* res);
  void oarrm3n2_div_RO_to(darr_t*    lhs, oarrm3n2_t*   rhs, oarrm3n2_t* res);
  void oarrm3n2_div_OR_to(oarrm3n2_t*   lhs, darr_t*    rhs, oarrm3n2_t* res);
  void oarrm3n2_div_oO_to(onumm3n2_t* lhs, oarrm3n2_t*   rhs, oarrm3n2_t* res);
  void oarrm3n2_div_Oo_to(oarrm3n2_t*   lhs, onumm3n2_t* rhs, oarrm3n2_t* res);
  void oarrm3n2_div_rO_to(coeff_t    lhs, oarrm3n2_t*   rhs, oarrm3n2_t* res);
  void oarrm3n2_div_Or_to(oarrm3n2_t*   lhs, coeff_t    rhs, oarrm3n2_t* res);
  
  
  # From ../../../include/oti/static/onumm3n2/array/base.h
  
  void    oarrm3n2_taylor_integrate_to( coeff_t* deltas, oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_taylor_integrate(    coeff_t* deltas, oarrm3n2_t* arr);
  void    oarrm3n2_get_order_im_to( ord_t order, oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_get_order_im(    ord_t order, oarrm3n2_t* arr);
  void oarrm3n2_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n2_t* res);
  void oarrm3n2_set_slice_O( oarrm3n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n2_t* res);
  void oarrm3n2_set_slice_o( onumm3n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_get_slice( oarrm3n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm3n2_get_slice_to( oarrm3n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_truncate_im(    imdir_t idx, ord_t order, oarrm3n2_t* arr);
  void    oarrm3n2_truncate_im_to( imdir_t idx, ord_t order, oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_extract_im(   imdir_t idx, ord_t order, oarrm3n2_t* arr);
  void    oarrm3n2_extract_im_to(imdir_t idx, ord_t order, oarrm3n2_t* arr, oarrm3n2_t* res);
  darr_t  oarrm3n2_get_deriv(    imdir_t idx, ord_t order, oarrm3n2_t* arr);
  void    oarrm3n2_get_deriv_to( imdir_t idx, ord_t order, oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_get_deriv_o(  imdir_t idx, ord_t order, oarrm3n2_t* arr);
  oarrm3n2_t oarrm3n2_extract_deriv(    imdir_t idx, ord_t order, oarrm3n2_t* arr);
  void    oarrm3n2_extract_deriv_to( imdir_t idx, ord_t order, oarrm3n2_t* arr, oarrm3n2_t* res);
  darr_t  oarrm3n2_get_im(   imdir_t idx, ord_t order, oarrm3n2_t* arr);
  oarrm3n2_t oarrm3n2_get_im_o( imdir_t idx, ord_t order, oarrm3n2_t* arr);
  void    oarrm3n2_get_im_to(imdir_t idx, ord_t order, oarrm3n2_t* arr, oarrm3n2_t* res);
  void    oarrm3n2_copy_to(oarrm3n2_t* arr, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_copy(oarrm3n2_t* arr);
  void oarrm3n2_set_all_r( coeff_t num, oarrm3n2_t* arr);
  void oarrm3n2_set_item_i_r( coeff_t num, uint64_t i, oarrm3n2_t* arr);
  void oarrm3n2_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm3n2_t* arr);
  void oarrm3n2_set_r(   coeff_t  num,   oarrm3n2_t* arr);
  void oarrm3n2_set_o( onumm3n2_t* num,   oarrm3n2_t* arr);
  void oarrm3n2_set_O(   oarrm3n2_t* arrin, oarrm3n2_t* arr);
  void oarrm3n2_set_all_o( onumm3n2_t* src, oarrm3n2_t* arr);
  void oarrm3n2_set_item_i_o( onumm3n2_t* num, uint64_t i, oarrm3n2_t* arr);
  void oarrm3n2_set_item_ij_o( onumm3n2_t* num, uint64_t i, uint64_t j, oarrm3n2_t* arr);
  onumm3n2_t oarrm3n2_get_item_i(    oarrm3n2_t* arr, uint64_t i);
  void      oarrm3n2_get_item_i_to( oarrm3n2_t* arr, uint64_t i,             onumm3n2_t* res);
  onumm3n2_t oarrm3n2_get_item_ij(   oarrm3n2_t* arr, uint64_t i, uint64_t j);
  void      oarrm3n2_get_item_ij_to(oarrm3n2_t* arr, uint64_t i, uint64_t j, onumm3n2_t* res);
  oarrm3n2_t oarrm3n2_init();
  void oarrm3n2_free(oarrm3n2_t* arr);
  oarrm3n2_t oarrm3n2_empty_like(oarrm3n2_t* arr);
  oarrm3n2_t oarrm3n2_eye(uint64_t nrows);
  oarrm3n2_t oarrm3n2_ones(uint64_t nrows, uint64_t ncols);
  oarrm3n2_t oarrm3n2_zeros(uint64_t nrows, uint64_t ncols);
  oarrm3n2_t oarrm3n2_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm3n2/array/utils.h
  
  void oarrm3n2_dimCheck_OO_elementwise(oarrm3n2_t* arr1, oarrm3n2_t* arr2, oarrm3n2_t* res);
  void oarrm3n2_dimCheck_RO_elementwise(darr_t*  arr1, oarrm3n2_t* arr2, oarrm3n2_t* res);
  void oarrm3n2_dimCheck_OO_matmul(oarrm3n2_t* arr1, oarrm3n2_t* arr2, oarrm3n2_t* res);
  void oarrm3n2_dimCheck_RO_matmul(darr_t*  arr1, oarrm3n2_t* arr2, oarrm3n2_t* res);
  void oarrm3n2_dimCheck_OR_matmul(oarrm3n2_t* arr1, darr_t*  arr2, oarrm3n2_t* res);
  void oarrm3n2_dimCheck_O_squareness(oarrm3n2_t* arr1, oarrm3n2_t* res);
  void oarrm3n2_dimCheck_OO_samesize(oarrm3n2_t* arr1, oarrm3n2_t* res);
  void oarrm3n2_dimCheck_RO_samesize(darr_t* arr1, oarrm3n2_t* res);
  ord_t oarrm3n2_get_order(oarrm3n2_t* arr);
  void oarrm3n2_get_active_bases(oarrm3n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n2/array/algebra_matops.h
  
  onumm3n2_t oarrm3n2_dotproduct_OO(    oarrm3n2_t* lhs, oarrm3n2_t* rhs);
  void      oarrm3n2_dotproduct_OO_to( oarrm3n2_t* lhs, oarrm3n2_t* rhs, onumm3n2_t* res);
  onumm3n2_t oarrm3n2_dotproduct_RO(     darr_t* lhs, oarrm3n2_t* rhs);
  void      oarrm3n2_dotproduct_RO_to(  darr_t* lhs, oarrm3n2_t* rhs, onumm3n2_t* res);
  oarrm3n2_t oarrm3n2_matmul_OO(    oarrm3n2_t* lhs, oarrm3n2_t* rhs);
  oarrm3n2_t oarrm3n2_matmul_OR(    oarrm3n2_t* lhs,  darr_t* rhs);
  oarrm3n2_t oarrm3n2_matmul_RO(     darr_t* lhs, oarrm3n2_t* rhs);
  void    oarrm3n2_matmul_OO_to( oarrm3n2_t* lhs, oarrm3n2_t* rhs, oarrm3n2_t* res);
  void    oarrm3n2_matmul_OR_to( oarrm3n2_t* lhs,  darr_t* rhs, oarrm3n2_t* res);
  void    oarrm3n2_matmul_RO_to(  darr_t* lhs, oarrm3n2_t* rhs, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_transpose(    oarrm3n2_t* arr1);
  void    oarrm3n2_transpose_to( oarrm3n2_t* arr1, oarrm3n2_t* res);
  oarrm3n2_t oarrm3n2_invert(    oarrm3n2_t* arr1);
  void    oarrm3n2_invert_to( oarrm3n2_t* arr1, oarrm3n2_t* res);
  onumm3n2_t oarrm3n2_det(    oarrm3n2_t* arr1);
  void      oarrm3n2_det_to( oarrm3n2_t* arr1, onumm3n2_t* res);
  onumm3n2_t oarrm3n2_norm(    oarrm3n2_t* arr1);
  void      oarrm3n2_norm_to( oarrm3n2_t* arr1,  onumm3n2_t* res);
  onumm3n2_t oarrm3n2_pnorm(    oarrm3n2_t* arr1, coeff_t p);
  void      oarrm3n2_pnorm_to( oarrm3n2_t* arr1, coeff_t p, onumm3n2_t* res);
  
  
  # From ../../../include/oti/static/onumm3n2/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm3n2/array/gauss/functions.h
  
  feoarrm3n2_t feoarrm3n2_atanh(    feoarrm3n2_t* arr);
  void      feoarrm3n2_atanh_to( feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_asinh(    feoarrm3n2_t* arr);
  void      feoarrm3n2_asinh_to( feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_acosh(    feoarrm3n2_t* arr);
  void      feoarrm3n2_acosh_to( feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_tanh(     feoarrm3n2_t* arr);
  void      feoarrm3n2_tanh_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sinh(     feoarrm3n2_t* arr);
  void      feoarrm3n2_sinh_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_cosh(     feoarrm3n2_t* arr);
  void      feoarrm3n2_cosh_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_atan(     feoarrm3n2_t* arr);
  void      feoarrm3n2_atan_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_asin(     feoarrm3n2_t* arr);
  void      feoarrm3n2_asin_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_acos(     feoarrm3n2_t* arr);
  void      feoarrm3n2_acos_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_tan(      feoarrm3n2_t* arr);
  void      feoarrm3n2_tan_to(   feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sin(      feoarrm3n2_t* arr);
  void      feoarrm3n2_sin_to(   feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_cos(      feoarrm3n2_t* arr);
  void      feoarrm3n2_cos_to(   feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_logb(     feoarrm3n2_t* arr, double base);
  void      feoarrm3n2_logb_to(  feoarrm3n2_t* arr, double base, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_log10(    feoarrm3n2_t* arr);
  void      feoarrm3n2_log10_to( feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_log(      feoarrm3n2_t* arr);
  void      feoarrm3n2_log_to(   feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_exp(      feoarrm3n2_t* arr);
  void      feoarrm3n2_exp_to(   feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_cbrt(     feoarrm3n2_t* arr);
  void      feoarrm3n2_cbrt_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sqrt(     feoarrm3n2_t* arr);
  void      feoarrm3n2_sqrt_to(  feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_pow(      feoarrm3n2_t* arr, double e);
  void      feoarrm3n2_pow_to(   feoarrm3n2_t* arr, double e, feoarrm3n2_t* res);
  
  
  # From ../../../include/oti/static/onumm3n2/array/gauss/base.h
  
  void      feoarrm3n2_get_order_im_to( ord_t order, feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_get_order_im(    ord_t order, feoarrm3n2_t* arr);
  feoarrm3n2_t feoarrm3n2_get_deriv(   imdir_t idx, ord_t order, feoarrm3n2_t* arr);
  void      feoarrm3n2_get_deriv_to(imdir_t idx, ord_t order, feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_get_im(      imdir_t idx, ord_t order, feoarrm3n2_t* arr);
  void      feoarrm3n2_get_im_to(   imdir_t idx, ord_t order, feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_truncate_im(   imdir_t idx, ord_t order, feoarrm3n2_t* arr);
  void      feoarrm3n2_truncate_im_to(imdir_t idx, ord_t order, feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_copy(   feoarrm3n2_t* src);
  void      feoarrm3n2_copy_to(feoarrm3n2_t* src, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_get_im(    imdir_t idx, ord_t order, feoarrm3n2_t* arr);
  void      feoarrm3n2_get_im_to( imdir_t idx, ord_t order, feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_get_deriv(    imdir_t idx, ord_t order, feoarrm3n2_t* arr);
  void      feoarrm3n2_get_deriv_to( imdir_t idx, ord_t order, feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_extract_im(    imdir_t idx, ord_t order, feoarrm3n2_t* arr);
  void      feoarrm3n2_extract_im_to( imdir_t idx, ord_t order, feoarrm3n2_t* arr,  feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_extract_deriv(    imdir_t idx, ord_t order, feoarrm3n2_t* arr);
  void      feoarrm3n2_extract_deriv_to( imdir_t idx, ord_t order, feoarrm3n2_t* arr, feoarrm3n2_t* res);
  oarrm3n2_t   feoarrm3n2_get_item_k(  feoarrm3n2_t* arr, uint64_t k);
  feonumm3n2_t  feoarrm3n2_get_item_ij( feoarrm3n2_t* arr, uint64_t i, uint64_t j);
  onumm3n2_t feoarrm3n2_get_item_ijk(feoarrm3n2_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm3n2_get_item_ij_to(  feoarrm3n2_t* arr, uint64_t i, uint64_t j,
                                 feonumm3n2_t* res);
  void feoarrm3n2_get_item_k_to(   feoarrm3n2_t* arr, uint64_t k,
                                  oarrm3n2_t* res);
  void feoarrm3n2_get_item_ijk_to( feoarrm3n2_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_get_slice(feoarrm3n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm3n2_get_slice_to(feoarrm3n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n2_t* res);
  void feoarrm3n2_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm3n2_t* res);
  void feoarrm3n2_set_item_ij_o(  onumm3n2_t* elm, uint64_t i, uint64_t j,
                               feoarrm3n2_t* res);
  void feoarrm3n2_set_item_ij_f(  feonumm3n2_t* elm, uint64_t i, uint64_t j,
                              feoarrm3n2_t* res);
  void feoarrm3n2_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm3n2_t* res);
  void feoarrm3n2_set_item_k_o(  onumm3n2_t* elm, uint64_t k,
                              feoarrm3n2_t* res);
  void feoarrm3n2_set_item_k_R(    oarrm3n2_t* elm, uint64_t k,
                            feoarrm3n2_t* res);
  void feoarrm3n2_set_item_k_O(    oarrm3n2_t* elm, uint64_t k,
                            feoarrm3n2_t* res);
  void feoarrm3n2_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm3n2_t* res);
  void feoarrm3n2_set_item_ijk_o( onumm3n2_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm3n2_t* res);
  void feoarrm3n2_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n2_t* res);
  void feoarrm3n2_set_slice_o( onumm3n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n2_t* res);
  void feoarrm3n2_set_slice_f( feonumm3n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n2_t* res);
  void feoarrm3n2_set_slice_O( oarrm3n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n2_t* res);
  void feoarrm3n2_set_slice_F( feoarrm3n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n2_t* res);
  void feoarrm3n2_set_all_o( onumm3n2_t* num, feoarrm3n2_t* arr );
  void feoarrm3n2_set_all_r(   coeff_t  num, feoarrm3n2_t* arr );
  void feoarrm3n2_set_all_f(  feonumm3n2_t* num, feoarrm3n2_t* arr );
  void feoarrm3n2_set_r(    coeff_t src, feoarrm3n2_t* res );
  void feoarrm3n2_set_o( onumm3n2_t* src, feoarrm3n2_t* res );
  void feoarrm3n2_set_f(  feonumm3n2_t* src, feoarrm3n2_t* res );
  void feoarrm3n2_set_R(    darr_t* src, feoarrm3n2_t* res );
  void feoarrm3n2_set_O(   oarrm3n2_t* src, feoarrm3n2_t* res );
  void feoarrm3n2_set_F( feoarrm3n2_t* src, feoarrm3n2_t* res );
  feoarrm3n2_t feoarrm3n2_eye( uint64_t size,  uint64_t nip);
  feoarrm3n2_t feoarrm3n2_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm3n2_t feoarrm3n2_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm3n2_t feoarrm3n2_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm3n2_free(feoarrm3n2_t* arr);
  feoarrm3n2_t feoarrm3n2_init();
  ord_t feoarrm3n2_get_order(feoarrm3n2_t* arr);
  
  
  # From ../../../include/oti/static/onumm3n2/array/gauss/utils.h
  
  void feoarrm3n2_dimCheck_FF_samesize(feoarrm3n2_t* arr1, feoarrm3n2_t* arr2, feonumm3n2_t* res);
  void feoarrm3n2_dimCheck_OF_samesize(  oarrm3n2_t* arr1, feoarrm3n2_t* arr2, feonumm3n2_t* res);
  void feoarrm3n2_dimCheck_RF_samesize(   darr_t* arr1, feoarrm3n2_t* arr2, feonumm3n2_t* res);
  void feoarrm3n2_dimCheck_FF_elementwise(feoarrm3n2_t* arr1, feoarrm3n2_t* arr2, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_OF_elementwise(  oarrm3n2_t* arr1, feoarrm3n2_t* arr2, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm3n2_t* arr2, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_fF_elementwise( feonumm3n2_t* num1, feoarrm3n2_t* arr2, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_Ff_elementwise(feoarrm3n2_t* arr1,  feonumm3n2_t* num2, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_FF_matmul( feoarrm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_OF_matmul(   oarrm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_FO_matmul( feoarrm3n2_t* lhs,   oarrm3n2_t* rhs, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_FR_matmul( feoarrm3n2_t* lhs,    darr_t* rhs, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_F_squareness( feoarrm3n2_t* arr1, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_F_transpose( feoarrm3n2_t* arr1, feoarrm3n2_t* res);
  void feoarrm3n2_dimCheck_FfO_integrate(feoarrm3n2_t* arr, feonumm3n2_t* num,oarrm3n2_t* res);
  void feoarrm3n2_get_active_bases(feoarrm3n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n2/array/gauss/algebra.h
  
  feoarrm3n2_t feoarrm3n2_neg(    feoarrm3n2_t* arr);
  void      feoarrm3n2_neg_to( feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sum_FF(   feoarrm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sum_FF_to(feoarrm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sum_fF(    feonumm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sum_fF_to( feonumm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sum_OF(     oarrm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sum_OF_to(  oarrm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sum_RF(      darr_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sum_RF_to(   darr_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sum_oF(   onumm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sum_oF_to(onumm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sum_rF(     coeff_t  lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sum_rF_to(  coeff_t  lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sub_FF(    feoarrm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sub_FF_to( feoarrm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sub_fF(    feonumm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sub_fF_to( feonumm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sub_Ff(    feoarrm3n2_t* lhs, feonumm3n2_t* rhs);
  void      feoarrm3n2_sub_Ff_to( feoarrm3n2_t* lhs, feonumm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sub_OF(      oarrm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sub_OF_to(   oarrm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sub_FO(    feoarrm3n2_t* lhs,   oarrm3n2_t* rhs);
  void      feoarrm3n2_sub_FO_to( feoarrm3n2_t* lhs,   oarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sub_RF(       darr_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sub_RF_to(    darr_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sub_FR(    feoarrm3n2_t* lhs,    darr_t* rhs);
  void      feoarrm3n2_sub_FR_to( feoarrm3n2_t* lhs,    darr_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sub_oF(    onumm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sub_oF_to( onumm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sub_Fo(    feoarrm3n2_t* lhs, onumm3n2_t* rhs);
  void      feoarrm3n2_sub_Fo_to( feoarrm3n2_t* lhs, onumm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sub_rF(      coeff_t  lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_sub_rF_to(    coeff_t lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_sub_Fr(    feoarrm3n2_t* lhs,   coeff_t  rhs);
  void      feoarrm3n2_sub_Fr_to( feoarrm3n2_t* lhs,   coeff_t  rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_mul_FF(   feoarrm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_mul_FF_to(feoarrm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_mul_fF(    feonumm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_mul_fF_to( feonumm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_mul_OF(     oarrm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_mul_OF_to(  oarrm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_mul_RF(      darr_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_mul_RF_to(   darr_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_mul_oF(   onumm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_mul_oF_to(onumm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_mul_rF(     coeff_t  lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_mul_rF_to(  coeff_t  lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_div_FF(    feoarrm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_div_FF_to( feoarrm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_div_fF(     feonumm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_div_fF_to(  feonumm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_div_Ff(    feoarrm3n2_t* lhs,  feonumm3n2_t* rhs);
  void      feoarrm3n2_div_Ff_to( feoarrm3n2_t* lhs,  feonumm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_div_OF(      oarrm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_div_OF_to(   oarrm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_div_FO(    feoarrm3n2_t* lhs,   oarrm3n2_t* rhs);
  void      feoarrm3n2_div_FO_to( feoarrm3n2_t* lhs,   oarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_div_RF(       darr_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_div_RF_to(    darr_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_div_FR(    feoarrm3n2_t* lhs,    darr_t* rhs);
  void      feoarrm3n2_div_FR_to( feoarrm3n2_t* lhs,    darr_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_div_oF(    onumm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_div_oF_to( onumm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_div_Fo(    feoarrm3n2_t* lhs, onumm3n2_t* rhs);
  void      feoarrm3n2_div_Fo_to( feoarrm3n2_t* lhs, onumm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_div_rF(      coeff_t  lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_div_rF_to(    coeff_t lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_div_Fr(    feoarrm3n2_t* lhs,   coeff_t  rhs);
  void      feoarrm3n2_div_Fr_to( feoarrm3n2_t* lhs,   coeff_t  rhs, feoarrm3n2_t* res);
  oarrm3n2_t feoarrm3n2_integrate(    feoarrm3n2_t* arr, feonumm3n2_t* w);
  void    feoarrm3n2_integrate_to( feoarrm3n2_t* arr, feonumm3n2_t* w, oarrm3n2_t* res);
  feonumm3n2_t feoarrm3n2_dotproduct_FF(    feoarrm3n2_t* lhs, feoarrm3n2_t* rhs);
  void     feoarrm3n2_dotproduct_FF_to( feoarrm3n2_t* lhs, feoarrm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feoarrm3n2_dotproduct_OF(      oarrm3n2_t* lhs, feoarrm3n2_t* rhs);
  void     feoarrm3n2_dotproduct_OF_to(   oarrm3n2_t* lhs, feoarrm3n2_t* rhs, feonumm3n2_t* res);
  feonumm3n2_t feoarrm3n2_dotproduct_RF(       darr_t* lhs, feoarrm3n2_t* rhs);
  void     feoarrm3n2_dotproduct_RF_to(    darr_t* lhs, feoarrm3n2_t* rhs, feonumm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_matmul_FF(    feoarrm3n2_t* lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_matmul_FF_to( feoarrm3n2_t* lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_matmul_OF(    oarrm3n2_t*   lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_matmul_OF_to( oarrm3n2_t*   lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_matmul_FO(    feoarrm3n2_t* lhs, oarrm3n2_t*   rhs);
  void      feoarrm3n2_matmul_FO_to( feoarrm3n2_t* lhs, oarrm3n2_t*   rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_matmul_RF(    darr_t*    lhs, feoarrm3n2_t* rhs);
  void      feoarrm3n2_matmul_RF_to( darr_t*    lhs, feoarrm3n2_t* rhs, feoarrm3n2_t* res);
  feoarrm3n2_t feoarrm3n2_matmul_FR(    feoarrm3n2_t* lhs, darr_t*    rhs);
  void      feoarrm3n2_matmul_FR_to( feoarrm3n2_t* lhs, darr_t*    rhs, feoarrm3n2_t* res);
  feonumm3n2_t feoarrm3n2_det(   feoarrm3n2_t* arr);
  void     feoarrm3n2_det_to(feoarrm3n2_t* arr, feonumm3n2_t* res);
  feonumm3n2_t feoarrm3n2_norm(     feoarrm3n2_t* arr);
  void     feoarrm3n2_norm_to(  feoarrm3n2_t* arr, feonumm3n2_t* res);
  feonumm3n2_t feoarrm3n2_pnorm(    feoarrm3n2_t* arr, coeff_t p);
  void     feoarrm3n2_pnorm_to( feoarrm3n2_t* arr, coeff_t p, feonumm3n2_t* res);
  feoarrm3n2_t   feoarrm3n2_invert(    feoarrm3n2_t* arr);
  void        feoarrm3n2_invert_to( feoarrm3n2_t* arr, feoarrm3n2_t* res);
  feoarrm3n2_t   feoarrm3n2_transpose(   feoarrm3n2_t* arr);
  void        feoarrm3n2_transpose_to(feoarrm3n2_t* arr, feoarrm3n2_t* res);
  
  