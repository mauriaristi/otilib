cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm5n2/scalar/structures.h
  
  ctypedef struct  onumm5n2_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
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
  # } onumm5n2_t;
  
  
  # From ../../../include/oti/static/onumm5n2/array/structures.h
  
  ctypedef struct  oarrm5n2_t : # {
      onumm5n2_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm5n2_t;
  
  
  # From ../../../include/oti/static/onumm5n2/scalar/gauss/structures.h
  
  ctypedef struct  feonumm5n2_t: # {
      onumm5n2_t*  p_data;
      uint64_t    nip;
  # } feonumm5n2_t;
  
  
  # From ../../../include/oti/static/onumm5n2/array/gauss/structures.h
  
  ctypedef struct  feoarrm5n2_t: # {
      oarrm5n2_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm5n2_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm5n2/scalar/functions.h
  
  onumm5n2_t onumm5n2_atanh(onumm5n2_t* num);
  void onumm5n2_atanh_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_asinh(onumm5n2_t* num);
  void onumm5n2_asinh_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_acosh(onumm5n2_t* num);
  void onumm5n2_acosh_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_tanh(onumm5n2_t* num);
  void onumm5n2_tanh_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_sqrt(onumm5n2_t* num);
  void onumm5n2_sqrt_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_cbrt(onumm5n2_t* num);
  void onumm5n2_cbrt_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_cosh(onumm5n2_t* num);
  void onumm5n2_cosh_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_sinh(onumm5n2_t* num);
  void onumm5n2_sinh_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_asin(onumm5n2_t* num);
  void onumm5n2_asin_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_acos(onumm5n2_t* num);
  void onumm5n2_acos_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_atan(onumm5n2_t* num);
  void onumm5n2_atan_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_tan(onumm5n2_t* num);
  void onumm5n2_tan_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_cos(onumm5n2_t* num);
  void onumm5n2_cos_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_sin(onumm5n2_t* num );
  void onumm5n2_sin_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_logb(onumm5n2_t* num, double base);
  void onumm5n2_logb_to(onumm5n2_t* num, double base, onumm5n2_t* res);
  onumm5n2_t onumm5n2_log10(onumm5n2_t* num);
  void onumm5n2_log10_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_log(onumm5n2_t* num);
  void onumm5n2_log_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_exp(onumm5n2_t* num);
  void onumm5n2_exp_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_pow(onumm5n2_t* num, double e);
  void onumm5n2_pow_to(onumm5n2_t* num, coeff_t e, onumm5n2_t* res);
  
  
  # From ../../../include/oti/static/onumm5n2/scalar/base.h
  
  void onumm5n2_set_im_o(onumm5n2_t* num, imdir_t idx, ord_t order, onumm5n2_t* res);
  void onumm5n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm5n2_t* res);
  void onumm5n2_set_deriv_o(onumm5n2_t* num, imdir_t idx, ord_t order, onumm5n2_t* res);
  void onumm5n2_extract_im_to( imdir_t idx, ord_t order, onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_extract_im(imdir_t idx, ord_t order, onumm5n2_t* num);
  onumm5n2_t onumm5n2_extract_deriv(imdir_t idx, ord_t order, onumm5n2_t* num);
  void onumm5n2_extract_deriv_to(imdir_t idx, ord_t order, onumm5n2_t* num, onumm5n2_t* res);
  void onumm5n2_get_im_to_o(imdir_t idx, ord_t order, onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_get_im_o(imdir_t idx, ord_t order, onumm5n2_t* num);
  void onumm5n2_get_im_to_r(imdir_t idx, ord_t order, onumm5n2_t* num, coeff_t* res);
  ord_t onumm5n2_get_order(onumm5n2_t* lhs);
  onumm5n2_t onumm5n2_get_deriv_o( imdir_t idx, ord_t order, onumm5n2_t* num);
  void onumm5n2_get_deriv_to( imdir_t idx, ord_t order, onumm5n2_t* num, onumm5n2_t* res);
  void onumm5n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm5n2_t* res);
  onumm5n2_t onumm5n2_init();
  ndir_t onumm5n2_get_ndir_order(ord_t order, onumm5n2_t* num);
  ndir_t onumm5n2_get_ndir_total(onumm5n2_t* num);
  coeff_t* onumm5n2_get_order_address(ord_t order, onumm5n2_t* num);
  onumm5n2_t onumm5n2_create_r(  coeff_t lhs);
  void onumm5n2_set_r(  coeff_t lhs, onumm5n2_t* res);
  void onumm5n2_set_o(  onumm5n2_t* lhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_get_order_im(ord_t order, onumm5n2_t* lhs);
  void onumm5n2_get_order_im_to(ord_t order, onumm5n2_t* lhs, onumm5n2_t* res);
  coeff_t onumm5n2_get_item(imdir_t idx, ord_t order, onumm5n2_t* lhs);
  coeff_t onumm5n2_get_deriv(imdir_t idx, ord_t order, onumm5n2_t* lhs);
  void onumm5n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm5n2_t* x);
  onumm5n2_t onumm5n2_copy(  onumm5n2_t* lhs);
  void onumm5n2_copy_to(  onumm5n2_t* lhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_taylor_integrate(coeff_t* deltas,onumm5n2_t* lhs);
  void onumm5n2_taylor_integrate_to(coeff_t* deltas,onumm5n2_t* lhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_truncate_im(imdir_t idx, ord_t order, onumm5n2_t* lhs);
  void onumm5n2_truncate_im_to(imdir_t idx, ord_t order, onumm5n2_t* lhs, onumm5n2_t* res);
  void onumm5n2_print(  onumm5n2_t* lhs);
  imdir_t onumm5n2_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm5n2/scalar/utils.h
  
  void onumm5n2_get_active_bases(onumm5n2_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm5n2/scalar/algebra.h
  
  onumm5n2_t onumm5n2_abs(onumm5n2_t* num);
  onumm5n2_t onumm5n2_div_ro(coeff_t num, onumm5n2_t* den);
  onumm5n2_t onumm5n2_div_oo(onumm5n2_t* num, onumm5n2_t* den);
  onumm5n2_t onumm5n2_div_or(onumm5n2_t* num, coeff_t val);
  void onumm5n2_div_ro_to(coeff_t num, onumm5n2_t* den, onumm5n2_t* res);
  void onumm5n2_div_oo_to(onumm5n2_t* num, onumm5n2_t* den, onumm5n2_t* res);
  void onumm5n2_div_or_to(onumm5n2_t* num, coeff_t val, onumm5n2_t* res);
  void onumm5n2_abs_to(onumm5n2_t* num, onumm5n2_t* res);
  onumm5n2_t onumm5n2_neg(  onumm5n2_t* lhs);
  void onumm5n2_neg_to(  onumm5n2_t* lhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_sum_oo(  onumm5n2_t* lhs,  onumm5n2_t* rhs);
  void onumm5n2_sum_oo_to(  onumm5n2_t* lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_sum_ro(  coeff_t lhs,  onumm5n2_t* rhs);
  void onumm5n2_sum_ro_to(  coeff_t lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_sub_oo(  onumm5n2_t* lhs,  onumm5n2_t* rhs);
  void onumm5n2_sub_oo_to(  onumm5n2_t* lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_sub_ro(  coeff_t lhs,  onumm5n2_t* rhs);
  void onumm5n2_sub_ro_to(  coeff_t lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_sub_or(  onumm5n2_t* lhs,  coeff_t rhs);
  void onumm5n2_sub_or_to(  onumm5n2_t* lhs,  coeff_t rhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_mul_oo(  onumm5n2_t* lhs,  onumm5n2_t* rhs);
  void onumm5n2_mul_oo_to(  onumm5n2_t* lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_mul_ro(  coeff_t lhs,  onumm5n2_t* rhs);
  void onumm5n2_mul_ro_to(  coeff_t lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_trunc_mul_oo(  onumm5n2_t* lhs,  onumm5n2_t* rhs);
  void onumm5n2_trunc_mul_oo_to(  onumm5n2_t* lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
  onumm5n2_t onumm5n2_gem_oo(  onumm5n2_t* a,  onumm5n2_t* b,  onumm5n2_t* c);
  void onumm5n2_gem_oo_to(  onumm5n2_t* a,  onumm5n2_t* b,  onumm5n2_t* c, onumm5n2_t* res);
  onumm5n2_t onumm5n2_gem_ro(  coeff_t a,  onumm5n2_t* b,  onumm5n2_t* c);
  void onumm5n2_gem_ro_to(  coeff_t a,  onumm5n2_t* b,  onumm5n2_t* c, onumm5n2_t* res);
  void onumm5n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n2_t* a,  ord_t ord_rhs,  onumm5n2_t* b,  onumm5n2_t* c, onumm5n2_t* res);
  onumm5n2_t onumm5n2_feval(coeff_t* feval_re, onumm5n2_t* x);
  void onumm5n2_feval_to(coeff_t* feval_re, onumm5n2_t* x, onumm5n2_t* res);
  
  
  # From ../../../include/oti/static/onumm5n2/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm5n2/scalar/gauss/functions.h
  
  feonumm5n2_t feonumm5n2_atanh(    feonumm5n2_t* num);
  void     feonumm5n2_atanh_to( feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_asinh(    feonumm5n2_t* num);
  void     feonumm5n2_asinh_to( feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_acosh(    feonumm5n2_t* num);
  void     feonumm5n2_acosh_to( feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_tanh(     feonumm5n2_t* num);
  void     feonumm5n2_tanh_to(  feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_cosh(     feonumm5n2_t* num);
  void     feonumm5n2_cosh_to(  feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_sinh(     feonumm5n2_t* num);
  void     feonumm5n2_sinh_to(  feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_asin(     feonumm5n2_t* num);
  void     feonumm5n2_asin_to(  feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_acos(     feonumm5n2_t* num);
  void     feonumm5n2_acos_to(  feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_atan(     feonumm5n2_t* num);
  void     feonumm5n2_atan_to(  feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_tan(      feonumm5n2_t* num);
  void     feonumm5n2_tan_to(   feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_cos(      feonumm5n2_t* num);
  void     feonumm5n2_cos_to(   feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_sin(      feonumm5n2_t* num);
  void     feonumm5n2_sin_to(   feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_logb(     feonumm5n2_t* num, double base);
  void     feonumm5n2_logb_to(  feonumm5n2_t* num, double base, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_log10(    feonumm5n2_t* num);
  void     feonumm5n2_log10_to( feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_log(      feonumm5n2_t* num);
  void     feonumm5n2_log_to(   feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_exp(      feonumm5n2_t* num);
  void     feonumm5n2_exp_to(   feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_cbrt(     feonumm5n2_t* num);
  void     feonumm5n2_cbrt_to(  feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_sqrt(     feonumm5n2_t* num);
  void     feonumm5n2_sqrt_to(  feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_pow(      feonumm5n2_t* num, double e);
  void     feonumm5n2_pow_to(   feonumm5n2_t* num, double e, feonumm5n2_t* res);
  onumm5n2_t feonumm5n2_integrate(       feonumm5n2_t* num, feonumm5n2_t* w);
  void      feonumm5n2_integrate_to(    feonumm5n2_t* num, feonumm5n2_t* w, onumm5n2_t* res);
  onumm5n2_t feonumm5n2_integrate_f(     feonumm5n2_t* num, feonumm5n2_t* w);
  void      feonumm5n2_integrate_f_to(  feonumm5n2_t* num, feonumm5n2_t* w, onumm5n2_t* res);
  onumm5n2_t feonumm5n2_integrate_r(       coeff_t num, feonumm5n2_t* w);
  void      feonumm5n2_integrate_r_to(    coeff_t num, feonumm5n2_t* w, onumm5n2_t* res);
  onumm5n2_t feonumm5n2_integrate_o(    onumm5n2_t* num, feonumm5n2_t* w);
  void      feonumm5n2_integrate_o_to( onumm5n2_t* num, feonumm5n2_t* w, onumm5n2_t* res);
  
  
  # From ../../../include/oti/static/onumm5n2/scalar/gauss/base.h
  
  void     feonumm5n2_get_order_im_to( ord_t order, feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_get_order_im(    ord_t order, feonumm5n2_t* num);
  feonumm5n2_t feonumm5n2_get_im(    imdir_t idx, ord_t order, feonumm5n2_t* num);
  void     feonumm5n2_get_im_to( imdir_t idx, ord_t order, feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_get_deriv(    imdir_t idx, ord_t order, feonumm5n2_t* num);
  void     feonumm5n2_get_deriv_to( imdir_t idx, ord_t order, feonumm5n2_t* num, feonumm5n2_t* res);
  void feonumm5n2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm5n2_t* num);
  void feonumm5n2_set_im_o( onumm5n2_t* val, imdir_t idx, ord_t order, feonumm5n2_t* num);
  void feonumm5n2_set_im_f(  feonumm5n2_t* val, imdir_t idx, ord_t order, feonumm5n2_t* num);
  void feonumm5n2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm5n2_t* num);
  void feonumm5n2_set_deriv_o( onumm5n2_t* val, imdir_t idx, ord_t order, feonumm5n2_t* num);
  void feonumm5n2_set_deriv_f(  feonumm5n2_t* val, imdir_t idx, ord_t order, feonumm5n2_t* num);
  feonumm5n2_t feonumm5n2_extract_im(    imdir_t idx, ord_t order, feonumm5n2_t* num);
  void     feonumm5n2_extract_im_to( imdir_t idx, ord_t order, feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_extract_deriv(    imdir_t idx, ord_t order, feonumm5n2_t* num);
  void     feonumm5n2_extract_deriv_to( imdir_t idx, ord_t order, feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_truncate_im(    imdir_t idx, ord_t order, feonumm5n2_t* num);
  void     feonumm5n2_truncate_im_to( imdir_t idx, ord_t order, feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_copy(    feonumm5n2_t* src);
  void     feonumm5n2_copy_to( feonumm5n2_t* src, feonumm5n2_t* dst);
  void feonumm5n2_set_r(    coeff_t num, feonumm5n2_t* res);
  void feonumm5n2_set_o( onumm5n2_t* num, feonumm5n2_t* res);
  void feonumm5n2_set_f(  feonumm5n2_t* num, feonumm5n2_t* res);
  void feonumm5n2_set_item_k_r(   coeff_t  num, uint64_t k, feonumm5n2_t* res);
  void feonumm5n2_set_item_k_o( onumm5n2_t* num, uint64_t k, feonumm5n2_t* res);
  onumm5n2_t feonumm5n2_get_item_k(   feonumm5n2_t* num, uint64_t k);
  void      feonumm5n2_get_item_k_to(feonumm5n2_t* num, uint64_t k, onumm5n2_t* res);
  feonumm5n2_t feonumm5n2_zeros(uint64_t nIntPts);
  feonumm5n2_t feonumm5n2_createEmpty(uint64_t nIntPts);
  feonumm5n2_t feonumm5n2_empty_like(feonumm5n2_t* arr);
  void feonumm5n2_free(feonumm5n2_t* num);
  ord_t feonumm5n2_get_order( feonumm5n2_t* num );
  feonumm5n2_t feonumm5n2_init();
  
  
  # From ../../../include/oti/static/onumm5n2/scalar/gauss/utils.h
  
  void feonumm5n2_dimCheck(feonumm5n2_t* arr1,feonumm5n2_t* arr2);
  void feonumm5n2_get_active_bases(feonumm5n2_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n2/scalar/gauss/algebra.h
  
  feonumm5n2_t feonumm5n2_neg(   feonumm5n2_t* num);
  void     feonumm5n2_neg_to(feonumm5n2_t* num, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_sum_ff(   feonumm5n2_t* lhs, feonumm5n2_t* rhs);
  void     feonumm5n2_sum_ff_to(feonumm5n2_t* lhs, feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_sum_of(   onumm5n2_t* lhs, feonumm5n2_t* rhs);
  void     feonumm5n2_sum_of_to(onumm5n2_t* lhs, feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_sum_rf(   coeff_t lhs, feonumm5n2_t* rhs);
  void     feonumm5n2_sum_rf_to(coeff_t lhs, feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_sub_ff(     feonumm5n2_t* lhs,  feonumm5n2_t* rhs);
  void     feonumm5n2_sub_ff_to(  feonumm5n2_t* lhs,  feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_sub_of(    onumm5n2_t* lhs,  feonumm5n2_t* rhs);
  void     feonumm5n2_sub_of_to( onumm5n2_t* lhs,  feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_sub_fo(     feonumm5n2_t* lhs, onumm5n2_t* rhs);
  void     feonumm5n2_sub_fo_to(  feonumm5n2_t* lhs, onumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_sub_rf(       coeff_t lhs,  feonumm5n2_t* rhs);
  void     feonumm5n2_sub_rf_to(    coeff_t lhs,  feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_sub_fr(     feonumm5n2_t* lhs,    coeff_t rhs);
  void     feonumm5n2_sub_fr_to(  feonumm5n2_t* lhs,    coeff_t rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_mul_ff(   feonumm5n2_t* lhs, feonumm5n2_t* rhs);
  void     feonumm5n2_mul_ff_to(feonumm5n2_t* lhs, feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_mul_of(   onumm5n2_t* lhs, feonumm5n2_t* rhs);
  void     feonumm5n2_mul_of_to(onumm5n2_t* lhs, feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_mul_rf(   coeff_t lhs, feonumm5n2_t* rhs);
  void     feonumm5n2_mul_rf_to(coeff_t lhs, feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_div_ff(     feonumm5n2_t* lhs,  feonumm5n2_t* rhs);
  void     feonumm5n2_div_ff_to(  feonumm5n2_t* lhs,  feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_div_of(    onumm5n2_t* lhs,  feonumm5n2_t* rhs);
  void     feonumm5n2_div_of_to( onumm5n2_t* lhs,  feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_div_fo(     feonumm5n2_t* lhs, onumm5n2_t* rhs);
  void     feonumm5n2_div_fo_to(  feonumm5n2_t* lhs, onumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_div_rf(       coeff_t lhs,  feonumm5n2_t* rhs);
  void     feonumm5n2_div_rf_to(    coeff_t lhs,  feonumm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feonumm5n2_div_fr(     feonumm5n2_t* lhs,    coeff_t rhs);
  void     feonumm5n2_div_fr_to(  feonumm5n2_t* lhs,    coeff_t rhs, feonumm5n2_t* res);
  
  
  # From ../../../include/oti/static/onumm5n2/array/functions.h
  
  oarrm5n2_t oarrm5n2_atanh(   oarrm5n2_t* arr);
  void    oarrm5n2_atanh_to(oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_asinh(   oarrm5n2_t* arr);
  void    oarrm5n2_asinh_to(oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_acosh(   oarrm5n2_t* arr);
  void    oarrm5n2_acosh_to(oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_tanh(    oarrm5n2_t* arr);
  void    oarrm5n2_tanh_to( oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_cbrt(    oarrm5n2_t* arr);
  void    oarrm5n2_cbrt_to( oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_sqrt(    oarrm5n2_t* arr);
  void    oarrm5n2_sqrt_to( oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_cosh(    oarrm5n2_t* arr);
  void    oarrm5n2_cosh_to( oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_sinh(    oarrm5n2_t* arr);
  void    oarrm5n2_sinh_to( oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_asin(    oarrm5n2_t* arr);
  void    oarrm5n2_asin_to( oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_acos(    oarrm5n2_t* arr);
  void    oarrm5n2_acos_to( oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_atan(    oarrm5n2_t* arr);
  void    oarrm5n2_atan_to( oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_tan(     oarrm5n2_t* arr);
  void    oarrm5n2_tan_to(  oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_cos(     oarrm5n2_t* arr);
  void    oarrm5n2_cos_to(  oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_sin(     oarrm5n2_t* arr);
  void    oarrm5n2_sin_to(  oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_logb(    oarrm5n2_t* arr, double base);
  void    oarrm5n2_logb_to( oarrm5n2_t* arr, double base, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_log10(   oarrm5n2_t* arr);
  void    oarrm5n2_log10_to(oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_log(     oarrm5n2_t* arr);
  void    oarrm5n2_log_to(  oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_exp(     oarrm5n2_t* arr);
  void    oarrm5n2_exp_to(  oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_pow(     oarrm5n2_t* arr, double e);
  void    oarrm5n2_pow_to(  oarrm5n2_t* arr, double e, oarrm5n2_t* res);
  
  
  # From ../../../include/oti/static/onumm5n2/array/algebra_elementwise.h
  
  oarrm5n2_t oarrm5n2_neg(oarrm5n2_t* arr);
  void oarrm5n2_neg_to(oarrm5n2_t* rhs, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_sum_OO(oarrm5n2_t*   lhs, oarrm5n2_t* rhs);
  oarrm5n2_t oarrm5n2_sum_RO(darr_t*    lhs, oarrm5n2_t* rhs);
  oarrm5n2_t oarrm5n2_sum_oO(onumm5n2_t* lhs, oarrm5n2_t* rhs);
  oarrm5n2_t oarrm5n2_sum_rO(coeff_t    lhs, oarrm5n2_t* rhs);
  void oarrm5n2_sum_OO_to(oarrm5n2_t*   lhs, oarrm5n2_t* rhs, oarrm5n2_t* res);
  void oarrm5n2_sum_RO_to(darr_t*    lhs, oarrm5n2_t* rhs, oarrm5n2_t* res);
  void oarrm5n2_sum_oO_to(onumm5n2_t* lhs, oarrm5n2_t* rhs, oarrm5n2_t* res);
  void oarrm5n2_sum_rO_to(coeff_t    lhs, oarrm5n2_t* rhs, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_sub_OO(oarrm5n2_t*   lhs, oarrm5n2_t*   rhs);
  oarrm5n2_t oarrm5n2_sub_RO(darr_t*    lhs, oarrm5n2_t*   rhs);
  oarrm5n2_t oarrm5n2_sub_OR(oarrm5n2_t*   lhs, darr_t*    rhs);
  oarrm5n2_t oarrm5n2_sub_oO(onumm5n2_t* lhs, oarrm5n2_t*   rhs);
  oarrm5n2_t oarrm5n2_sub_Oo(oarrm5n2_t*   lhs, onumm5n2_t* rhs);
  oarrm5n2_t oarrm5n2_sub_rO(coeff_t    lhs, oarrm5n2_t*   rhs);
  oarrm5n2_t oarrm5n2_sub_Or(oarrm5n2_t*   lhs, coeff_t    rhs);
  void oarrm5n2_sub_OO_to( oarrm5n2_t*   lhs, oarrm5n2_t*   rhs, oarrm5n2_t* res);
  void oarrm5n2_sub_RO_to( darr_t*    lhs, oarrm5n2_t*   rhs, oarrm5n2_t* res);
  void oarrm5n2_sub_OR_to( oarrm5n2_t*   lhs, darr_t*    rhs, oarrm5n2_t* res);
  void oarrm5n2_sub_oO_to( onumm5n2_t* lhs, oarrm5n2_t*   rhs, oarrm5n2_t* res);
  void oarrm5n2_sub_Oo_to( oarrm5n2_t*   lhs, onumm5n2_t* rhs, oarrm5n2_t* res);
  void oarrm5n2_sub_rO_to( coeff_t    lhs, oarrm5n2_t*   rhs, oarrm5n2_t* res);
  void oarrm5n2_sub_Or_to( oarrm5n2_t*   lhs, coeff_t    rhs, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_mul_OO(oarrm5n2_t*   lhs, oarrm5n2_t* rhs);
  oarrm5n2_t oarrm5n2_mul_RO(darr_t*    lhs, oarrm5n2_t* rhs);
  oarrm5n2_t oarrm5n2_mul_oO(onumm5n2_t* lhs, oarrm5n2_t* rhs);
  oarrm5n2_t oarrm5n2_mul_rO(coeff_t    lhs, oarrm5n2_t* rhs);
  void oarrm5n2_mul_OO_to(oarrm5n2_t*   lhs, oarrm5n2_t* rhs, oarrm5n2_t* res);
  void oarrm5n2_mul_RO_to(darr_t*    lhs, oarrm5n2_t* rhs, oarrm5n2_t* res);
  void oarrm5n2_mul_oO_to(onumm5n2_t* lhs, oarrm5n2_t* rhs, oarrm5n2_t* res);
  void oarrm5n2_mul_rO_to(coeff_t    lhs, oarrm5n2_t* rhs, oarrm5n2_t* res);
  void oarrm5n2_gem_OO_to(  oarrm5n2_t* arr1, oarrm5n2_t* arr2, oarrm5n2_t* arr3, oarrm5n2_t* res);
  void oarrm5n2_gem_oO_to(onumm5n2_t* arr1, oarrm5n2_t* arr2, oarrm5n2_t* arr3, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_div_OO(oarrm5n2_t*   lhs, oarrm5n2_t*   rhs);
  oarrm5n2_t oarrm5n2_div_OR(oarrm5n2_t*   lhs, darr_t*    rhs);
  oarrm5n2_t oarrm5n2_div_RO(darr_t*    lhs, oarrm5n2_t*   rhs);
  oarrm5n2_t oarrm5n2_div_oO(onumm5n2_t* lhs, oarrm5n2_t*   rhs);
  oarrm5n2_t oarrm5n2_div_Oo(oarrm5n2_t*   lhs, onumm5n2_t* rhs);
  oarrm5n2_t oarrm5n2_div_rO(coeff_t    lhs, oarrm5n2_t*   rhs);
  oarrm5n2_t oarrm5n2_div_Or(oarrm5n2_t*   lhs, coeff_t    rhs);
  void oarrm5n2_div_OO_to(oarrm5n2_t*   lhs, oarrm5n2_t*   rhs, oarrm5n2_t* res);
  void oarrm5n2_div_RO_to(darr_t*    lhs, oarrm5n2_t*   rhs, oarrm5n2_t* res);
  void oarrm5n2_div_OR_to(oarrm5n2_t*   lhs, darr_t*    rhs, oarrm5n2_t* res);
  void oarrm5n2_div_oO_to(onumm5n2_t* lhs, oarrm5n2_t*   rhs, oarrm5n2_t* res);
  void oarrm5n2_div_Oo_to(oarrm5n2_t*   lhs, onumm5n2_t* rhs, oarrm5n2_t* res);
  void oarrm5n2_div_rO_to(coeff_t    lhs, oarrm5n2_t*   rhs, oarrm5n2_t* res);
  void oarrm5n2_div_Or_to(oarrm5n2_t*   lhs, coeff_t    rhs, oarrm5n2_t* res);
  
  
  # From ../../../include/oti/static/onumm5n2/array/base.h
  
  void    oarrm5n2_taylor_integrate_to( coeff_t* deltas, oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_taylor_integrate(    coeff_t* deltas, oarrm5n2_t* arr);
  void    oarrm5n2_get_order_im_to( ord_t order, oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_get_order_im(    ord_t order, oarrm5n2_t* arr);
  void oarrm5n2_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n2_t* res);
  void oarrm5n2_set_slice_O( oarrm5n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n2_t* res);
  void oarrm5n2_set_slice_o( onumm5n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_get_slice( oarrm5n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm5n2_get_slice_to( oarrm5n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_truncate_im(    imdir_t idx, ord_t order, oarrm5n2_t* arr);
  void    oarrm5n2_truncate_im_to( imdir_t idx, ord_t order, oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_extract_im(   imdir_t idx, ord_t order, oarrm5n2_t* arr);
  void    oarrm5n2_extract_im_to(imdir_t idx, ord_t order, oarrm5n2_t* arr, oarrm5n2_t* res);
  darr_t  oarrm5n2_get_deriv(    imdir_t idx, ord_t order, oarrm5n2_t* arr);
  void    oarrm5n2_get_deriv_to( imdir_t idx, ord_t order, oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_get_deriv_o(  imdir_t idx, ord_t order, oarrm5n2_t* arr);
  oarrm5n2_t oarrm5n2_extract_deriv(    imdir_t idx, ord_t order, oarrm5n2_t* arr);
  void    oarrm5n2_extract_deriv_to( imdir_t idx, ord_t order, oarrm5n2_t* arr, oarrm5n2_t* res);
  darr_t  oarrm5n2_get_im(   imdir_t idx, ord_t order, oarrm5n2_t* arr);
  oarrm5n2_t oarrm5n2_get_im_o( imdir_t idx, ord_t order, oarrm5n2_t* arr);
  void    oarrm5n2_get_im_to(imdir_t idx, ord_t order, oarrm5n2_t* arr, oarrm5n2_t* res);
  void    oarrm5n2_copy_to(oarrm5n2_t* arr, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_copy(oarrm5n2_t* arr);
  void oarrm5n2_set_all_r( coeff_t num, oarrm5n2_t* arr);
  void oarrm5n2_set_item_i_r( coeff_t num, uint64_t i, oarrm5n2_t* arr);
  void oarrm5n2_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm5n2_t* arr);
  void oarrm5n2_set_r(   coeff_t  num,   oarrm5n2_t* arr);
  void oarrm5n2_set_o( onumm5n2_t* num,   oarrm5n2_t* arr);
  void oarrm5n2_set_O(   oarrm5n2_t* arrin, oarrm5n2_t* arr);
  void oarrm5n2_set_all_o( onumm5n2_t* src, oarrm5n2_t* arr);
  void oarrm5n2_set_item_i_o( onumm5n2_t* num, uint64_t i, oarrm5n2_t* arr);
  void oarrm5n2_set_item_ij_o( onumm5n2_t* num, uint64_t i, uint64_t j, oarrm5n2_t* arr);
  onumm5n2_t oarrm5n2_get_item_i(    oarrm5n2_t* arr, uint64_t i);
  void      oarrm5n2_get_item_i_to( oarrm5n2_t* arr, uint64_t i,             onumm5n2_t* res);
  onumm5n2_t oarrm5n2_get_item_ij(   oarrm5n2_t* arr, uint64_t i, uint64_t j);
  void      oarrm5n2_get_item_ij_to(oarrm5n2_t* arr, uint64_t i, uint64_t j, onumm5n2_t* res);
  oarrm5n2_t oarrm5n2_init();
  void oarrm5n2_free(oarrm5n2_t* arr);
  oarrm5n2_t oarrm5n2_empty_like(oarrm5n2_t* arr);
  oarrm5n2_t oarrm5n2_eye(uint64_t nrows);
  oarrm5n2_t oarrm5n2_ones(uint64_t nrows, uint64_t ncols);
  oarrm5n2_t oarrm5n2_zeros(uint64_t nrows, uint64_t ncols);
  oarrm5n2_t oarrm5n2_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm5n2/array/utils.h
  
  void oarrm5n2_dimCheck_OO_elementwise(oarrm5n2_t* arr1, oarrm5n2_t* arr2, oarrm5n2_t* res);
  void oarrm5n2_dimCheck_RO_elementwise(darr_t*  arr1, oarrm5n2_t* arr2, oarrm5n2_t* res);
  void oarrm5n2_dimCheck_OO_matmul(oarrm5n2_t* arr1, oarrm5n2_t* arr2, oarrm5n2_t* res);
  void oarrm5n2_dimCheck_RO_matmul(darr_t*  arr1, oarrm5n2_t* arr2, oarrm5n2_t* res);
  void oarrm5n2_dimCheck_OR_matmul(oarrm5n2_t* arr1, darr_t*  arr2, oarrm5n2_t* res);
  void oarrm5n2_dimCheck_O_squareness(oarrm5n2_t* arr1, oarrm5n2_t* res);
  void oarrm5n2_dimCheck_OO_samesize(oarrm5n2_t* arr1, oarrm5n2_t* res);
  void oarrm5n2_dimCheck_RO_samesize(darr_t* arr1, oarrm5n2_t* res);
  ord_t oarrm5n2_get_order(oarrm5n2_t* arr);
  void oarrm5n2_get_active_bases(oarrm5n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n2/array/algebra_matops.h
  
  onumm5n2_t oarrm5n2_dotproduct_OO(    oarrm5n2_t* lhs, oarrm5n2_t* rhs);
  void      oarrm5n2_dotproduct_OO_to( oarrm5n2_t* lhs, oarrm5n2_t* rhs, onumm5n2_t* res);
  onumm5n2_t oarrm5n2_dotproduct_RO(     darr_t* lhs, oarrm5n2_t* rhs);
  void      oarrm5n2_dotproduct_RO_to(  darr_t* lhs, oarrm5n2_t* rhs, onumm5n2_t* res);
  oarrm5n2_t oarrm5n2_matmul_OO(    oarrm5n2_t* lhs, oarrm5n2_t* rhs);
  oarrm5n2_t oarrm5n2_matmul_OR(    oarrm5n2_t* lhs,  darr_t* rhs);
  oarrm5n2_t oarrm5n2_matmul_RO(     darr_t* lhs, oarrm5n2_t* rhs);
  void    oarrm5n2_matmul_OO_to( oarrm5n2_t* lhs, oarrm5n2_t* rhs, oarrm5n2_t* res);
  void    oarrm5n2_matmul_OR_to( oarrm5n2_t* lhs,  darr_t* rhs, oarrm5n2_t* res);
  void    oarrm5n2_matmul_RO_to(  darr_t* lhs, oarrm5n2_t* rhs, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_transpose(    oarrm5n2_t* arr1);
  void    oarrm5n2_transpose_to( oarrm5n2_t* arr1, oarrm5n2_t* res);
  oarrm5n2_t oarrm5n2_invert(    oarrm5n2_t* arr1);
  void    oarrm5n2_invert_to( oarrm5n2_t* arr1, oarrm5n2_t* res);
  onumm5n2_t oarrm5n2_det(    oarrm5n2_t* arr1);
  void      oarrm5n2_det_to( oarrm5n2_t* arr1, onumm5n2_t* res);
  onumm5n2_t oarrm5n2_norm(    oarrm5n2_t* arr1);
  void      oarrm5n2_norm_to( oarrm5n2_t* arr1,  onumm5n2_t* res);
  onumm5n2_t oarrm5n2_pnorm(    oarrm5n2_t* arr1, coeff_t p);
  void      oarrm5n2_pnorm_to( oarrm5n2_t* arr1, coeff_t p, onumm5n2_t* res);
  
  
  # From ../../../include/oti/static/onumm5n2/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm5n2/array/gauss/functions.h
  
  feoarrm5n2_t feoarrm5n2_atanh(    feoarrm5n2_t* arr);
  void      feoarrm5n2_atanh_to( feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_asinh(    feoarrm5n2_t* arr);
  void      feoarrm5n2_asinh_to( feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_acosh(    feoarrm5n2_t* arr);
  void      feoarrm5n2_acosh_to( feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_tanh(     feoarrm5n2_t* arr);
  void      feoarrm5n2_tanh_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sinh(     feoarrm5n2_t* arr);
  void      feoarrm5n2_sinh_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_cosh(     feoarrm5n2_t* arr);
  void      feoarrm5n2_cosh_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_atan(     feoarrm5n2_t* arr);
  void      feoarrm5n2_atan_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_asin(     feoarrm5n2_t* arr);
  void      feoarrm5n2_asin_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_acos(     feoarrm5n2_t* arr);
  void      feoarrm5n2_acos_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_tan(      feoarrm5n2_t* arr);
  void      feoarrm5n2_tan_to(   feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sin(      feoarrm5n2_t* arr);
  void      feoarrm5n2_sin_to(   feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_cos(      feoarrm5n2_t* arr);
  void      feoarrm5n2_cos_to(   feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_logb(     feoarrm5n2_t* arr, double base);
  void      feoarrm5n2_logb_to(  feoarrm5n2_t* arr, double base, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_log10(    feoarrm5n2_t* arr);
  void      feoarrm5n2_log10_to( feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_log(      feoarrm5n2_t* arr);
  void      feoarrm5n2_log_to(   feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_exp(      feoarrm5n2_t* arr);
  void      feoarrm5n2_exp_to(   feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_cbrt(     feoarrm5n2_t* arr);
  void      feoarrm5n2_cbrt_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sqrt(     feoarrm5n2_t* arr);
  void      feoarrm5n2_sqrt_to(  feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_pow(      feoarrm5n2_t* arr, double e);
  void      feoarrm5n2_pow_to(   feoarrm5n2_t* arr, double e, feoarrm5n2_t* res);
  
  
  # From ../../../include/oti/static/onumm5n2/array/gauss/base.h
  
  void      feoarrm5n2_get_order_im_to( ord_t order, feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_get_order_im(    ord_t order, feoarrm5n2_t* arr);
  feoarrm5n2_t feoarrm5n2_get_deriv(   imdir_t idx, ord_t order, feoarrm5n2_t* arr);
  void      feoarrm5n2_get_deriv_to(imdir_t idx, ord_t order, feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_get_im(      imdir_t idx, ord_t order, feoarrm5n2_t* arr);
  void      feoarrm5n2_get_im_to(   imdir_t idx, ord_t order, feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_truncate_im(   imdir_t idx, ord_t order, feoarrm5n2_t* arr);
  void      feoarrm5n2_truncate_im_to(imdir_t idx, ord_t order, feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_copy(   feoarrm5n2_t* src);
  void      feoarrm5n2_copy_to(feoarrm5n2_t* src, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_get_im(    imdir_t idx, ord_t order, feoarrm5n2_t* arr);
  void      feoarrm5n2_get_im_to( imdir_t idx, ord_t order, feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_get_deriv(    imdir_t idx, ord_t order, feoarrm5n2_t* arr);
  void      feoarrm5n2_get_deriv_to( imdir_t idx, ord_t order, feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_extract_im(    imdir_t idx, ord_t order, feoarrm5n2_t* arr);
  void      feoarrm5n2_extract_im_to( imdir_t idx, ord_t order, feoarrm5n2_t* arr,  feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_extract_deriv(    imdir_t idx, ord_t order, feoarrm5n2_t* arr);
  void      feoarrm5n2_extract_deriv_to( imdir_t idx, ord_t order, feoarrm5n2_t* arr, feoarrm5n2_t* res);
  oarrm5n2_t   feoarrm5n2_get_item_k(  feoarrm5n2_t* arr, uint64_t k);
  feonumm5n2_t  feoarrm5n2_get_item_ij( feoarrm5n2_t* arr, uint64_t i, uint64_t j);
  onumm5n2_t feoarrm5n2_get_item_ijk(feoarrm5n2_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm5n2_get_item_ij_to(  feoarrm5n2_t* arr, uint64_t i, uint64_t j,
                                 feonumm5n2_t* res);
  void feoarrm5n2_get_item_k_to(   feoarrm5n2_t* arr, uint64_t k,
                                  oarrm5n2_t* res);
  void feoarrm5n2_get_item_ijk_to( feoarrm5n2_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_get_slice(feoarrm5n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm5n2_get_slice_to(feoarrm5n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n2_t* res);
  void feoarrm5n2_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm5n2_t* res);
  void feoarrm5n2_set_item_ij_o(  onumm5n2_t* elm, uint64_t i, uint64_t j,
                               feoarrm5n2_t* res);
  void feoarrm5n2_set_item_ij_f(  feonumm5n2_t* elm, uint64_t i, uint64_t j,
                              feoarrm5n2_t* res);
  void feoarrm5n2_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm5n2_t* res);
  void feoarrm5n2_set_item_k_o(  onumm5n2_t* elm, uint64_t k,
                              feoarrm5n2_t* res);
  void feoarrm5n2_set_item_k_R(    oarrm5n2_t* elm, uint64_t k,
                            feoarrm5n2_t* res);
  void feoarrm5n2_set_item_k_O(    oarrm5n2_t* elm, uint64_t k,
                            feoarrm5n2_t* res);
  void feoarrm5n2_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm5n2_t* res);
  void feoarrm5n2_set_item_ijk_o( onumm5n2_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm5n2_t* res);
  void feoarrm5n2_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n2_t* res);
  void feoarrm5n2_set_slice_o( onumm5n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n2_t* res);
  void feoarrm5n2_set_slice_f( feonumm5n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n2_t* res);
  void feoarrm5n2_set_slice_O( oarrm5n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n2_t* res);
  void feoarrm5n2_set_slice_F( feoarrm5n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n2_t* res);
  void feoarrm5n2_set_all_o( onumm5n2_t* num, feoarrm5n2_t* arr );
  void feoarrm5n2_set_all_r(   coeff_t  num, feoarrm5n2_t* arr );
  void feoarrm5n2_set_all_f(  feonumm5n2_t* num, feoarrm5n2_t* arr );
  void feoarrm5n2_set_r(    coeff_t src, feoarrm5n2_t* res );
  void feoarrm5n2_set_o( onumm5n2_t* src, feoarrm5n2_t* res );
  void feoarrm5n2_set_f(  feonumm5n2_t* src, feoarrm5n2_t* res );
  void feoarrm5n2_set_R(    darr_t* src, feoarrm5n2_t* res );
  void feoarrm5n2_set_O(   oarrm5n2_t* src, feoarrm5n2_t* res );
  void feoarrm5n2_set_F( feoarrm5n2_t* src, feoarrm5n2_t* res );
  feoarrm5n2_t feoarrm5n2_eye( uint64_t size,  uint64_t nip);
  feoarrm5n2_t feoarrm5n2_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm5n2_t feoarrm5n2_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm5n2_t feoarrm5n2_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm5n2_free(feoarrm5n2_t* arr);
  feoarrm5n2_t feoarrm5n2_init();
  ord_t feoarrm5n2_get_order(feoarrm5n2_t* arr);
  
  
  # From ../../../include/oti/static/onumm5n2/array/gauss/utils.h
  
  void feoarrm5n2_dimCheck_FF_samesize(feoarrm5n2_t* arr1, feoarrm5n2_t* arr2, feonumm5n2_t* res);
  void feoarrm5n2_dimCheck_OF_samesize(  oarrm5n2_t* arr1, feoarrm5n2_t* arr2, feonumm5n2_t* res);
  void feoarrm5n2_dimCheck_RF_samesize(   darr_t* arr1, feoarrm5n2_t* arr2, feonumm5n2_t* res);
  void feoarrm5n2_dimCheck_FF_elementwise(feoarrm5n2_t* arr1, feoarrm5n2_t* arr2, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_OF_elementwise(  oarrm5n2_t* arr1, feoarrm5n2_t* arr2, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm5n2_t* arr2, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_fF_elementwise( feonumm5n2_t* num1, feoarrm5n2_t* arr2, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_Ff_elementwise(feoarrm5n2_t* arr1,  feonumm5n2_t* num2, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_FF_matmul( feoarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_OF_matmul(   oarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_FO_matmul( feoarrm5n2_t* lhs,   oarrm5n2_t* rhs, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_FR_matmul( feoarrm5n2_t* lhs,    darr_t* rhs, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_F_squareness( feoarrm5n2_t* arr1, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_F_transpose( feoarrm5n2_t* arr1, feoarrm5n2_t* res);
  void feoarrm5n2_dimCheck_FfO_integrate(feoarrm5n2_t* arr, feonumm5n2_t* num,oarrm5n2_t* res);
  void feoarrm5n2_get_active_bases(feoarrm5n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n2/array/gauss/algebra.h
  
  feoarrm5n2_t feoarrm5n2_neg(    feoarrm5n2_t* arr);
  void      feoarrm5n2_neg_to( feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sum_FF(   feoarrm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sum_FF_to(feoarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sum_fF(    feonumm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sum_fF_to( feonumm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sum_OF(     oarrm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sum_OF_to(  oarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sum_RF(      darr_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sum_RF_to(   darr_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sum_oF(   onumm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sum_oF_to(onumm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sum_rF(     coeff_t  lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sum_rF_to(  coeff_t  lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sub_FF(    feoarrm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sub_FF_to( feoarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sub_fF(    feonumm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sub_fF_to( feonumm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sub_Ff(    feoarrm5n2_t* lhs, feonumm5n2_t* rhs);
  void      feoarrm5n2_sub_Ff_to( feoarrm5n2_t* lhs, feonumm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sub_OF(      oarrm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sub_OF_to(   oarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sub_FO(    feoarrm5n2_t* lhs,   oarrm5n2_t* rhs);
  void      feoarrm5n2_sub_FO_to( feoarrm5n2_t* lhs,   oarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sub_RF(       darr_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sub_RF_to(    darr_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sub_FR(    feoarrm5n2_t* lhs,    darr_t* rhs);
  void      feoarrm5n2_sub_FR_to( feoarrm5n2_t* lhs,    darr_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sub_oF(    onumm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sub_oF_to( onumm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sub_Fo(    feoarrm5n2_t* lhs, onumm5n2_t* rhs);
  void      feoarrm5n2_sub_Fo_to( feoarrm5n2_t* lhs, onumm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sub_rF(      coeff_t  lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_sub_rF_to(    coeff_t lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_sub_Fr(    feoarrm5n2_t* lhs,   coeff_t  rhs);
  void      feoarrm5n2_sub_Fr_to( feoarrm5n2_t* lhs,   coeff_t  rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_mul_FF(   feoarrm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_mul_FF_to(feoarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_mul_fF(    feonumm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_mul_fF_to( feonumm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_mul_OF(     oarrm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_mul_OF_to(  oarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_mul_RF(      darr_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_mul_RF_to(   darr_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_mul_oF(   onumm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_mul_oF_to(onumm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_mul_rF(     coeff_t  lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_mul_rF_to(  coeff_t  lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_div_FF(    feoarrm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_div_FF_to( feoarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_div_fF(     feonumm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_div_fF_to(  feonumm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_div_Ff(    feoarrm5n2_t* lhs,  feonumm5n2_t* rhs);
  void      feoarrm5n2_div_Ff_to( feoarrm5n2_t* lhs,  feonumm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_div_OF(      oarrm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_div_OF_to(   oarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_div_FO(    feoarrm5n2_t* lhs,   oarrm5n2_t* rhs);
  void      feoarrm5n2_div_FO_to( feoarrm5n2_t* lhs,   oarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_div_RF(       darr_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_div_RF_to(    darr_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_div_FR(    feoarrm5n2_t* lhs,    darr_t* rhs);
  void      feoarrm5n2_div_FR_to( feoarrm5n2_t* lhs,    darr_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_div_oF(    onumm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_div_oF_to( onumm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_div_Fo(    feoarrm5n2_t* lhs, onumm5n2_t* rhs);
  void      feoarrm5n2_div_Fo_to( feoarrm5n2_t* lhs, onumm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_div_rF(      coeff_t  lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_div_rF_to(    coeff_t lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_div_Fr(    feoarrm5n2_t* lhs,   coeff_t  rhs);
  void      feoarrm5n2_div_Fr_to( feoarrm5n2_t* lhs,   coeff_t  rhs, feoarrm5n2_t* res);
  oarrm5n2_t feoarrm5n2_integrate(    feoarrm5n2_t* arr, feonumm5n2_t* w);
  void    feoarrm5n2_integrate_to( feoarrm5n2_t* arr, feonumm5n2_t* w, oarrm5n2_t* res);
  feonumm5n2_t feoarrm5n2_dotproduct_FF(    feoarrm5n2_t* lhs, feoarrm5n2_t* rhs);
  void     feoarrm5n2_dotproduct_FF_to( feoarrm5n2_t* lhs, feoarrm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feoarrm5n2_dotproduct_OF(      oarrm5n2_t* lhs, feoarrm5n2_t* rhs);
  void     feoarrm5n2_dotproduct_OF_to(   oarrm5n2_t* lhs, feoarrm5n2_t* rhs, feonumm5n2_t* res);
  feonumm5n2_t feoarrm5n2_dotproduct_RF(       darr_t* lhs, feoarrm5n2_t* rhs);
  void     feoarrm5n2_dotproduct_RF_to(    darr_t* lhs, feoarrm5n2_t* rhs, feonumm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_matmul_FF(    feoarrm5n2_t* lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_matmul_FF_to( feoarrm5n2_t* lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_matmul_OF(    oarrm5n2_t*   lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_matmul_OF_to( oarrm5n2_t*   lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_matmul_FO(    feoarrm5n2_t* lhs, oarrm5n2_t*   rhs);
  void      feoarrm5n2_matmul_FO_to( feoarrm5n2_t* lhs, oarrm5n2_t*   rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_matmul_RF(    darr_t*    lhs, feoarrm5n2_t* rhs);
  void      feoarrm5n2_matmul_RF_to( darr_t*    lhs, feoarrm5n2_t* rhs, feoarrm5n2_t* res);
  feoarrm5n2_t feoarrm5n2_matmul_FR(    feoarrm5n2_t* lhs, darr_t*    rhs);
  void      feoarrm5n2_matmul_FR_to( feoarrm5n2_t* lhs, darr_t*    rhs, feoarrm5n2_t* res);
  feonumm5n2_t feoarrm5n2_det(   feoarrm5n2_t* arr);
  void     feoarrm5n2_det_to(feoarrm5n2_t* arr, feonumm5n2_t* res);
  feonumm5n2_t feoarrm5n2_norm(     feoarrm5n2_t* arr);
  void     feoarrm5n2_norm_to(  feoarrm5n2_t* arr, feonumm5n2_t* res);
  feonumm5n2_t feoarrm5n2_pnorm(    feoarrm5n2_t* arr, coeff_t p);
  void     feoarrm5n2_pnorm_to( feoarrm5n2_t* arr, coeff_t p, feonumm5n2_t* res);
  feoarrm5n2_t   feoarrm5n2_invert(    feoarrm5n2_t* arr);
  void        feoarrm5n2_invert_to( feoarrm5n2_t* arr, feoarrm5n2_t* res);
  feoarrm5n2_t   feoarrm5n2_transpose(   feoarrm5n2_t* arr);
  void        feoarrm5n2_transpose_to(feoarrm5n2_t* arr, feoarrm5n2_t* res);
  
  