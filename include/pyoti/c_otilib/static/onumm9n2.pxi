cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm9n2/scalar/structures.h
  
  ctypedef struct  onumm9n2_t : # {
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
  # } onumm9n2_t;
  
  
  # From ../../../include/oti/static/onumm9n2/array/structures.h
  
  ctypedef struct  oarrm9n2_t : # {
      onumm9n2_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm9n2_t;
  
  
  # From ../../../include/oti/static/onumm9n2/scalar/gauss/structures.h
  
  ctypedef struct  feonumm9n2_t: # {
      onumm9n2_t*  p_data;
      uint64_t    nip;
  # } feonumm9n2_t;
  
  
  # From ../../../include/oti/static/onumm9n2/array/gauss/structures.h
  
  ctypedef struct  feoarrm9n2_t: # {
      oarrm9n2_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm9n2_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm9n2/scalar/functions.h
  
  onumm9n2_t onumm9n2_atanh(onumm9n2_t* num);
  void onumm9n2_atanh_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_asinh(onumm9n2_t* num);
  void onumm9n2_asinh_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_acosh(onumm9n2_t* num);
  void onumm9n2_acosh_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_tanh(onumm9n2_t* num);
  void onumm9n2_tanh_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_sqrt(onumm9n2_t* num);
  void onumm9n2_sqrt_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_cbrt(onumm9n2_t* num);
  void onumm9n2_cbrt_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_cosh(onumm9n2_t* num);
  void onumm9n2_cosh_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_sinh(onumm9n2_t* num);
  void onumm9n2_sinh_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_asin(onumm9n2_t* num);
  void onumm9n2_asin_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_acos(onumm9n2_t* num);
  void onumm9n2_acos_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_atan(onumm9n2_t* num);
  void onumm9n2_atan_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_tan(onumm9n2_t* num);
  void onumm9n2_tan_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_cos(onumm9n2_t* num);
  void onumm9n2_cos_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_sin(onumm9n2_t* num );
  void onumm9n2_sin_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_logb(onumm9n2_t* num, double base);
  void onumm9n2_logb_to(onumm9n2_t* num, double base, onumm9n2_t* res);
  onumm9n2_t onumm9n2_log10(onumm9n2_t* num);
  void onumm9n2_log10_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_log(onumm9n2_t* num);
  void onumm9n2_log_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_exp(onumm9n2_t* num);
  void onumm9n2_exp_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_pow(onumm9n2_t* num, double e);
  void onumm9n2_pow_to(onumm9n2_t* num, coeff_t e, onumm9n2_t* res);
  
  
  # From ../../../include/oti/static/onumm9n2/scalar/base.h
  
  void onumm9n2_set_im_o(onumm9n2_t* num, imdir_t idx, ord_t order, onumm9n2_t* res);
  void onumm9n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm9n2_t* res);
  void onumm9n2_set_deriv_o(onumm9n2_t* num, imdir_t idx, ord_t order, onumm9n2_t* res);
  void onumm9n2_extract_im_to( imdir_t idx, ord_t order, onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_extract_im(imdir_t idx, ord_t order, onumm9n2_t* num);
  onumm9n2_t onumm9n2_extract_deriv(imdir_t idx, ord_t order, onumm9n2_t* num);
  void onumm9n2_extract_deriv_to(imdir_t idx, ord_t order, onumm9n2_t* num, onumm9n2_t* res);
  void onumm9n2_get_im_to_o(imdir_t idx, ord_t order, onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_get_im_o(imdir_t idx, ord_t order, onumm9n2_t* num);
  void onumm9n2_get_im_to_r(imdir_t idx, ord_t order, onumm9n2_t* num, coeff_t* res);
  ord_t onumm9n2_get_order(onumm9n2_t* lhs);
  onumm9n2_t onumm9n2_get_deriv_o( imdir_t idx, ord_t order, onumm9n2_t* num);
  void onumm9n2_get_deriv_to( imdir_t idx, ord_t order, onumm9n2_t* num, onumm9n2_t* res);
  void onumm9n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm9n2_t* res);
  onumm9n2_t onumm9n2_init();
  ndir_t onumm9n2_get_ndir_order(ord_t order, onumm9n2_t* num);
  ndir_t onumm9n2_get_ndir_total(onumm9n2_t* num);
  coeff_t* onumm9n2_get_order_address(ord_t order, onumm9n2_t* num);
  onumm9n2_t onumm9n2_create_r(  coeff_t lhs);
  void onumm9n2_set_r(  coeff_t lhs, onumm9n2_t* res);
  void onumm9n2_set_o(  onumm9n2_t* lhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_get_order_im(ord_t order, onumm9n2_t* lhs);
  void onumm9n2_get_order_im_to(ord_t order, onumm9n2_t* lhs, onumm9n2_t* res);
  coeff_t onumm9n2_get_item(imdir_t idx, ord_t order, onumm9n2_t* lhs);
  coeff_t onumm9n2_get_deriv(imdir_t idx, ord_t order, onumm9n2_t* lhs);
  void onumm9n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm9n2_t* x);
  onumm9n2_t onumm9n2_copy(  onumm9n2_t* lhs);
  void onumm9n2_copy_to(  onumm9n2_t* lhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_taylor_integrate(coeff_t* deltas,onumm9n2_t* lhs);
  void onumm9n2_taylor_integrate_to(coeff_t* deltas,onumm9n2_t* lhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_truncate_im(imdir_t idx, ord_t order, onumm9n2_t* lhs);
  void onumm9n2_truncate_im_to(imdir_t idx, ord_t order, onumm9n2_t* lhs, onumm9n2_t* res);
  void onumm9n2_print(  onumm9n2_t* lhs);
  imdir_t onumm9n2_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm9n2/scalar/utils.h
  
  void onumm9n2_get_active_bases(onumm9n2_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm9n2/scalar/algebra.h
  
  onumm9n2_t onumm9n2_abs(onumm9n2_t* num);
  onumm9n2_t onumm9n2_div_ro(coeff_t num, onumm9n2_t* den);
  onumm9n2_t onumm9n2_div_oo(onumm9n2_t* num, onumm9n2_t* den);
  onumm9n2_t onumm9n2_div_or(onumm9n2_t* num, coeff_t val);
  void onumm9n2_div_ro_to(coeff_t num, onumm9n2_t* den, onumm9n2_t* res);
  void onumm9n2_div_oo_to(onumm9n2_t* num, onumm9n2_t* den, onumm9n2_t* res);
  void onumm9n2_div_or_to(onumm9n2_t* num, coeff_t val, onumm9n2_t* res);
  void onumm9n2_abs_to(onumm9n2_t* num, onumm9n2_t* res);
  onumm9n2_t onumm9n2_neg(  onumm9n2_t* lhs);
  void onumm9n2_neg_to(  onumm9n2_t* lhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_sum_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs);
  void onumm9n2_sum_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_sum_ro(  coeff_t lhs,  onumm9n2_t* rhs);
  void onumm9n2_sum_ro_to(  coeff_t lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_sub_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs);
  void onumm9n2_sub_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_sub_ro(  coeff_t lhs,  onumm9n2_t* rhs);
  void onumm9n2_sub_ro_to(  coeff_t lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_sub_or(  onumm9n2_t* lhs,  coeff_t rhs);
  void onumm9n2_sub_or_to(  onumm9n2_t* lhs,  coeff_t rhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_mul_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs);
  void onumm9n2_mul_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_mul_ro(  coeff_t lhs,  onumm9n2_t* rhs);
  void onumm9n2_mul_ro_to(  coeff_t lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_trunc_mul_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs);
  void onumm9n2_trunc_mul_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
  onumm9n2_t onumm9n2_gem_oo(  onumm9n2_t* a,  onumm9n2_t* b,  onumm9n2_t* c);
  void onumm9n2_gem_oo_to(  onumm9n2_t* a,  onumm9n2_t* b,  onumm9n2_t* c, onumm9n2_t* res);
  onumm9n2_t onumm9n2_gem_ro(  coeff_t a,  onumm9n2_t* b,  onumm9n2_t* c);
  void onumm9n2_gem_ro_to(  coeff_t a,  onumm9n2_t* b,  onumm9n2_t* c, onumm9n2_t* res);
  void onumm9n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm9n2_t* a,  ord_t ord_rhs,  onumm9n2_t* b,  onumm9n2_t* c, onumm9n2_t* res);
  onumm9n2_t onumm9n2_feval(coeff_t* feval_re, onumm9n2_t* x);
  void onumm9n2_feval_to(coeff_t* feval_re, onumm9n2_t* x, onumm9n2_t* res);
  
  
  # From ../../../include/oti/static/onumm9n2/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm9n2/scalar/gauss/functions.h
  
  feonumm9n2_t feonumm9n2_atanh(    feonumm9n2_t* num);
  void     feonumm9n2_atanh_to( feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_asinh(    feonumm9n2_t* num);
  void     feonumm9n2_asinh_to( feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_acosh(    feonumm9n2_t* num);
  void     feonumm9n2_acosh_to( feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_tanh(     feonumm9n2_t* num);
  void     feonumm9n2_tanh_to(  feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_cosh(     feonumm9n2_t* num);
  void     feonumm9n2_cosh_to(  feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_sinh(     feonumm9n2_t* num);
  void     feonumm9n2_sinh_to(  feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_asin(     feonumm9n2_t* num);
  void     feonumm9n2_asin_to(  feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_acos(     feonumm9n2_t* num);
  void     feonumm9n2_acos_to(  feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_atan(     feonumm9n2_t* num);
  void     feonumm9n2_atan_to(  feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_tan(      feonumm9n2_t* num);
  void     feonumm9n2_tan_to(   feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_cos(      feonumm9n2_t* num);
  void     feonumm9n2_cos_to(   feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_sin(      feonumm9n2_t* num);
  void     feonumm9n2_sin_to(   feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_logb(     feonumm9n2_t* num, double base);
  void     feonumm9n2_logb_to(  feonumm9n2_t* num, double base, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_log10(    feonumm9n2_t* num);
  void     feonumm9n2_log10_to( feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_log(      feonumm9n2_t* num);
  void     feonumm9n2_log_to(   feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_exp(      feonumm9n2_t* num);
  void     feonumm9n2_exp_to(   feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_cbrt(     feonumm9n2_t* num);
  void     feonumm9n2_cbrt_to(  feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_sqrt(     feonumm9n2_t* num);
  void     feonumm9n2_sqrt_to(  feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_pow(      feonumm9n2_t* num, double e);
  void     feonumm9n2_pow_to(   feonumm9n2_t* num, double e, feonumm9n2_t* res);
  onumm9n2_t feonumm9n2_integrate(       feonumm9n2_t* num, feonumm9n2_t* w);
  void      feonumm9n2_integrate_to(    feonumm9n2_t* num, feonumm9n2_t* w, onumm9n2_t* res);
  onumm9n2_t feonumm9n2_integrate_f(     feonumm9n2_t* num, feonumm9n2_t* w);
  void      feonumm9n2_integrate_f_to(  feonumm9n2_t* num, feonumm9n2_t* w, onumm9n2_t* res);
  onumm9n2_t feonumm9n2_integrate_r(       coeff_t num, feonumm9n2_t* w);
  void      feonumm9n2_integrate_r_to(    coeff_t num, feonumm9n2_t* w, onumm9n2_t* res);
  onumm9n2_t feonumm9n2_integrate_o(    onumm9n2_t* num, feonumm9n2_t* w);
  void      feonumm9n2_integrate_o_to( onumm9n2_t* num, feonumm9n2_t* w, onumm9n2_t* res);
  
  
  # From ../../../include/oti/static/onumm9n2/scalar/gauss/base.h
  
  void     feonumm9n2_get_order_im_to( ord_t order, feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_get_order_im(    ord_t order, feonumm9n2_t* num);
  feonumm9n2_t feonumm9n2_get_im(    imdir_t idx, ord_t order, feonumm9n2_t* num);
  void     feonumm9n2_get_im_to( imdir_t idx, ord_t order, feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_get_deriv(    imdir_t idx, ord_t order, feonumm9n2_t* num);
  void     feonumm9n2_get_deriv_to( imdir_t idx, ord_t order, feonumm9n2_t* num, feonumm9n2_t* res);
  void feonumm9n2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm9n2_t* num);
  void feonumm9n2_set_im_o( onumm9n2_t* val, imdir_t idx, ord_t order, feonumm9n2_t* num);
  void feonumm9n2_set_im_f(  feonumm9n2_t* val, imdir_t idx, ord_t order, feonumm9n2_t* num);
  void feonumm9n2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm9n2_t* num);
  void feonumm9n2_set_deriv_o( onumm9n2_t* val, imdir_t idx, ord_t order, feonumm9n2_t* num);
  void feonumm9n2_set_deriv_f(  feonumm9n2_t* val, imdir_t idx, ord_t order, feonumm9n2_t* num);
  feonumm9n2_t feonumm9n2_extract_im(    imdir_t idx, ord_t order, feonumm9n2_t* num);
  void     feonumm9n2_extract_im_to( imdir_t idx, ord_t order, feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_extract_deriv(    imdir_t idx, ord_t order, feonumm9n2_t* num);
  void     feonumm9n2_extract_deriv_to( imdir_t idx, ord_t order, feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_truncate_im(    imdir_t idx, ord_t order, feonumm9n2_t* num);
  void     feonumm9n2_truncate_im_to( imdir_t idx, ord_t order, feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_copy(    feonumm9n2_t* src);
  void     feonumm9n2_copy_to( feonumm9n2_t* src, feonumm9n2_t* dst);
  void feonumm9n2_set_r(    coeff_t num, feonumm9n2_t* res);
  void feonumm9n2_set_o( onumm9n2_t* num, feonumm9n2_t* res);
  void feonumm9n2_set_f(  feonumm9n2_t* num, feonumm9n2_t* res);
  void feonumm9n2_set_item_k_r(   coeff_t  num, uint64_t k, feonumm9n2_t* res);
  void feonumm9n2_set_item_k_o( onumm9n2_t* num, uint64_t k, feonumm9n2_t* res);
  onumm9n2_t feonumm9n2_get_item_k(   feonumm9n2_t* num, uint64_t k);
  void      feonumm9n2_get_item_k_to(feonumm9n2_t* num, uint64_t k, onumm9n2_t* res);
  feonumm9n2_t feonumm9n2_zeros(uint64_t nIntPts);
  feonumm9n2_t feonumm9n2_createEmpty(uint64_t nIntPts);
  feonumm9n2_t feonumm9n2_empty_like(feonumm9n2_t* arr);
  void feonumm9n2_free(feonumm9n2_t* num);
  ord_t feonumm9n2_get_order( feonumm9n2_t* num );
  feonumm9n2_t feonumm9n2_init();
  
  
  # From ../../../include/oti/static/onumm9n2/scalar/gauss/utils.h
  
  void feonumm9n2_dimCheck(feonumm9n2_t* arr1,feonumm9n2_t* arr2);
  void feonumm9n2_get_active_bases(feonumm9n2_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm9n2/scalar/gauss/algebra.h
  
  feonumm9n2_t feonumm9n2_neg(   feonumm9n2_t* num);
  void     feonumm9n2_neg_to(feonumm9n2_t* num, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_sum_ff(   feonumm9n2_t* lhs, feonumm9n2_t* rhs);
  void     feonumm9n2_sum_ff_to(feonumm9n2_t* lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_sum_of(   onumm9n2_t* lhs, feonumm9n2_t* rhs);
  void     feonumm9n2_sum_of_to(onumm9n2_t* lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_sum_rf(   coeff_t lhs, feonumm9n2_t* rhs);
  void     feonumm9n2_sum_rf_to(coeff_t lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_sub_ff(     feonumm9n2_t* lhs,  feonumm9n2_t* rhs);
  void     feonumm9n2_sub_ff_to(  feonumm9n2_t* lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_sub_of(    onumm9n2_t* lhs,  feonumm9n2_t* rhs);
  void     feonumm9n2_sub_of_to( onumm9n2_t* lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_sub_fo(     feonumm9n2_t* lhs, onumm9n2_t* rhs);
  void     feonumm9n2_sub_fo_to(  feonumm9n2_t* lhs, onumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_sub_rf(       coeff_t lhs,  feonumm9n2_t* rhs);
  void     feonumm9n2_sub_rf_to(    coeff_t lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_sub_fr(     feonumm9n2_t* lhs,    coeff_t rhs);
  void     feonumm9n2_sub_fr_to(  feonumm9n2_t* lhs,    coeff_t rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_mul_ff(   feonumm9n2_t* lhs, feonumm9n2_t* rhs);
  void     feonumm9n2_mul_ff_to(feonumm9n2_t* lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_mul_of(   onumm9n2_t* lhs, feonumm9n2_t* rhs);
  void     feonumm9n2_mul_of_to(onumm9n2_t* lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_mul_rf(   coeff_t lhs, feonumm9n2_t* rhs);
  void     feonumm9n2_mul_rf_to(coeff_t lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_div_ff(     feonumm9n2_t* lhs,  feonumm9n2_t* rhs);
  void     feonumm9n2_div_ff_to(  feonumm9n2_t* lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_div_of(    onumm9n2_t* lhs,  feonumm9n2_t* rhs);
  void     feonumm9n2_div_of_to( onumm9n2_t* lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_div_fo(     feonumm9n2_t* lhs, onumm9n2_t* rhs);
  void     feonumm9n2_div_fo_to(  feonumm9n2_t* lhs, onumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_div_rf(       coeff_t lhs,  feonumm9n2_t* rhs);
  void     feonumm9n2_div_rf_to(    coeff_t lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feonumm9n2_div_fr(     feonumm9n2_t* lhs,    coeff_t rhs);
  void     feonumm9n2_div_fr_to(  feonumm9n2_t* lhs,    coeff_t rhs, feonumm9n2_t* res);
  
  
  # From ../../../include/oti/static/onumm9n2/array/functions.h
  
  oarrm9n2_t oarrm9n2_atanh(   oarrm9n2_t* arr);
  void    oarrm9n2_atanh_to(oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_asinh(   oarrm9n2_t* arr);
  void    oarrm9n2_asinh_to(oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_acosh(   oarrm9n2_t* arr);
  void    oarrm9n2_acosh_to(oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_tanh(    oarrm9n2_t* arr);
  void    oarrm9n2_tanh_to( oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_cbrt(    oarrm9n2_t* arr);
  void    oarrm9n2_cbrt_to( oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_sqrt(    oarrm9n2_t* arr);
  void    oarrm9n2_sqrt_to( oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_cosh(    oarrm9n2_t* arr);
  void    oarrm9n2_cosh_to( oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_sinh(    oarrm9n2_t* arr);
  void    oarrm9n2_sinh_to( oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_asin(    oarrm9n2_t* arr);
  void    oarrm9n2_asin_to( oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_acos(    oarrm9n2_t* arr);
  void    oarrm9n2_acos_to( oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_atan(    oarrm9n2_t* arr);
  void    oarrm9n2_atan_to( oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_tan(     oarrm9n2_t* arr);
  void    oarrm9n2_tan_to(  oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_cos(     oarrm9n2_t* arr);
  void    oarrm9n2_cos_to(  oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_sin(     oarrm9n2_t* arr);
  void    oarrm9n2_sin_to(  oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_logb(    oarrm9n2_t* arr, double base);
  void    oarrm9n2_logb_to( oarrm9n2_t* arr, double base, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_log10(   oarrm9n2_t* arr);
  void    oarrm9n2_log10_to(oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_log(     oarrm9n2_t* arr);
  void    oarrm9n2_log_to(  oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_exp(     oarrm9n2_t* arr);
  void    oarrm9n2_exp_to(  oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_pow(     oarrm9n2_t* arr, double e);
  void    oarrm9n2_pow_to(  oarrm9n2_t* arr, double e, oarrm9n2_t* res);
  
  
  # From ../../../include/oti/static/onumm9n2/array/algebra_elementwise.h
  
  oarrm9n2_t oarrm9n2_neg(oarrm9n2_t* arr);
  void oarrm9n2_neg_to(oarrm9n2_t* rhs, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_sum_OO(oarrm9n2_t*   lhs, oarrm9n2_t* rhs);
  oarrm9n2_t oarrm9n2_sum_RO(darr_t*    lhs, oarrm9n2_t* rhs);
  oarrm9n2_t oarrm9n2_sum_oO(onumm9n2_t* lhs, oarrm9n2_t* rhs);
  oarrm9n2_t oarrm9n2_sum_rO(coeff_t    lhs, oarrm9n2_t* rhs);
  void oarrm9n2_sum_OO_to(oarrm9n2_t*   lhs, oarrm9n2_t* rhs, oarrm9n2_t* res);
  void oarrm9n2_sum_RO_to(darr_t*    lhs, oarrm9n2_t* rhs, oarrm9n2_t* res);
  void oarrm9n2_sum_oO_to(onumm9n2_t* lhs, oarrm9n2_t* rhs, oarrm9n2_t* res);
  void oarrm9n2_sum_rO_to(coeff_t    lhs, oarrm9n2_t* rhs, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_sub_OO(oarrm9n2_t*   lhs, oarrm9n2_t*   rhs);
  oarrm9n2_t oarrm9n2_sub_RO(darr_t*    lhs, oarrm9n2_t*   rhs);
  oarrm9n2_t oarrm9n2_sub_OR(oarrm9n2_t*   lhs, darr_t*    rhs);
  oarrm9n2_t oarrm9n2_sub_oO(onumm9n2_t* lhs, oarrm9n2_t*   rhs);
  oarrm9n2_t oarrm9n2_sub_Oo(oarrm9n2_t*   lhs, onumm9n2_t* rhs);
  oarrm9n2_t oarrm9n2_sub_rO(coeff_t    lhs, oarrm9n2_t*   rhs);
  oarrm9n2_t oarrm9n2_sub_Or(oarrm9n2_t*   lhs, coeff_t    rhs);
  void oarrm9n2_sub_OO_to( oarrm9n2_t*   lhs, oarrm9n2_t*   rhs, oarrm9n2_t* res);
  void oarrm9n2_sub_RO_to( darr_t*    lhs, oarrm9n2_t*   rhs, oarrm9n2_t* res);
  void oarrm9n2_sub_OR_to( oarrm9n2_t*   lhs, darr_t*    rhs, oarrm9n2_t* res);
  void oarrm9n2_sub_oO_to( onumm9n2_t* lhs, oarrm9n2_t*   rhs, oarrm9n2_t* res);
  void oarrm9n2_sub_Oo_to( oarrm9n2_t*   lhs, onumm9n2_t* rhs, oarrm9n2_t* res);
  void oarrm9n2_sub_rO_to( coeff_t    lhs, oarrm9n2_t*   rhs, oarrm9n2_t* res);
  void oarrm9n2_sub_Or_to( oarrm9n2_t*   lhs, coeff_t    rhs, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_mul_OO(oarrm9n2_t*   lhs, oarrm9n2_t* rhs);
  oarrm9n2_t oarrm9n2_mul_RO(darr_t*    lhs, oarrm9n2_t* rhs);
  oarrm9n2_t oarrm9n2_mul_oO(onumm9n2_t* lhs, oarrm9n2_t* rhs);
  oarrm9n2_t oarrm9n2_mul_rO(coeff_t    lhs, oarrm9n2_t* rhs);
  void oarrm9n2_mul_OO_to(oarrm9n2_t*   lhs, oarrm9n2_t* rhs, oarrm9n2_t* res);
  void oarrm9n2_mul_RO_to(darr_t*    lhs, oarrm9n2_t* rhs, oarrm9n2_t* res);
  void oarrm9n2_mul_oO_to(onumm9n2_t* lhs, oarrm9n2_t* rhs, oarrm9n2_t* res);
  void oarrm9n2_mul_rO_to(coeff_t    lhs, oarrm9n2_t* rhs, oarrm9n2_t* res);
  void oarrm9n2_gem_OO_to(  oarrm9n2_t* arr1, oarrm9n2_t* arr2, oarrm9n2_t* arr3, oarrm9n2_t* res);
  void oarrm9n2_gem_oO_to(onumm9n2_t* arr1, oarrm9n2_t* arr2, oarrm9n2_t* arr3, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_div_OO(oarrm9n2_t*   lhs, oarrm9n2_t*   rhs);
  oarrm9n2_t oarrm9n2_div_OR(oarrm9n2_t*   lhs, darr_t*    rhs);
  oarrm9n2_t oarrm9n2_div_RO(darr_t*    lhs, oarrm9n2_t*   rhs);
  oarrm9n2_t oarrm9n2_div_oO(onumm9n2_t* lhs, oarrm9n2_t*   rhs);
  oarrm9n2_t oarrm9n2_div_Oo(oarrm9n2_t*   lhs, onumm9n2_t* rhs);
  oarrm9n2_t oarrm9n2_div_rO(coeff_t    lhs, oarrm9n2_t*   rhs);
  oarrm9n2_t oarrm9n2_div_Or(oarrm9n2_t*   lhs, coeff_t    rhs);
  void oarrm9n2_div_OO_to(oarrm9n2_t*   lhs, oarrm9n2_t*   rhs, oarrm9n2_t* res);
  void oarrm9n2_div_RO_to(darr_t*    lhs, oarrm9n2_t*   rhs, oarrm9n2_t* res);
  void oarrm9n2_div_OR_to(oarrm9n2_t*   lhs, darr_t*    rhs, oarrm9n2_t* res);
  void oarrm9n2_div_oO_to(onumm9n2_t* lhs, oarrm9n2_t*   rhs, oarrm9n2_t* res);
  void oarrm9n2_div_Oo_to(oarrm9n2_t*   lhs, onumm9n2_t* rhs, oarrm9n2_t* res);
  void oarrm9n2_div_rO_to(coeff_t    lhs, oarrm9n2_t*   rhs, oarrm9n2_t* res);
  void oarrm9n2_div_Or_to(oarrm9n2_t*   lhs, coeff_t    rhs, oarrm9n2_t* res);
  
  
  # From ../../../include/oti/static/onumm9n2/array/base.h
  
  void    oarrm9n2_taylor_integrate_to( coeff_t* deltas, oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_taylor_integrate(    coeff_t* deltas, oarrm9n2_t* arr);
  void    oarrm9n2_get_order_im_to( ord_t order, oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_get_order_im(    ord_t order, oarrm9n2_t* arr);
  void oarrm9n2_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm9n2_t* res);
  void oarrm9n2_set_slice_O( oarrm9n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm9n2_t* res);
  void oarrm9n2_set_slice_o( onumm9n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_get_slice( oarrm9n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm9n2_get_slice_to( oarrm9n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_truncate_im(    imdir_t idx, ord_t order, oarrm9n2_t* arr);
  void    oarrm9n2_truncate_im_to( imdir_t idx, ord_t order, oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_extract_im(   imdir_t idx, ord_t order, oarrm9n2_t* arr);
  void    oarrm9n2_extract_im_to(imdir_t idx, ord_t order, oarrm9n2_t* arr, oarrm9n2_t* res);
  darr_t  oarrm9n2_get_deriv(    imdir_t idx, ord_t order, oarrm9n2_t* arr);
  void    oarrm9n2_get_deriv_to( imdir_t idx, ord_t order, oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_get_deriv_o(  imdir_t idx, ord_t order, oarrm9n2_t* arr);
  oarrm9n2_t oarrm9n2_extract_deriv(    imdir_t idx, ord_t order, oarrm9n2_t* arr);
  void    oarrm9n2_extract_deriv_to( imdir_t idx, ord_t order, oarrm9n2_t* arr, oarrm9n2_t* res);
  darr_t  oarrm9n2_get_im(   imdir_t idx, ord_t order, oarrm9n2_t* arr);
  oarrm9n2_t oarrm9n2_get_im_o( imdir_t idx, ord_t order, oarrm9n2_t* arr);
  void    oarrm9n2_get_im_to(imdir_t idx, ord_t order, oarrm9n2_t* arr, oarrm9n2_t* res);
  void    oarrm9n2_copy_to(oarrm9n2_t* arr, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_copy(oarrm9n2_t* arr);
  void oarrm9n2_set_all_r( coeff_t num, oarrm9n2_t* arr);
  void oarrm9n2_set_item_i_r( coeff_t num, uint64_t i, oarrm9n2_t* arr);
  void oarrm9n2_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm9n2_t* arr);
  void oarrm9n2_set_r(   coeff_t  num,   oarrm9n2_t* arr);
  void oarrm9n2_set_o( onumm9n2_t* num,   oarrm9n2_t* arr);
  void oarrm9n2_set_O(   oarrm9n2_t* arrin, oarrm9n2_t* arr);
  void oarrm9n2_set_all_o( onumm9n2_t* src, oarrm9n2_t* arr);
  void oarrm9n2_set_item_i_o( onumm9n2_t* num, uint64_t i, oarrm9n2_t* arr);
  void oarrm9n2_set_item_ij_o( onumm9n2_t* num, uint64_t i, uint64_t j, oarrm9n2_t* arr);
  onumm9n2_t oarrm9n2_get_item_i(    oarrm9n2_t* arr, uint64_t i);
  void      oarrm9n2_get_item_i_to( oarrm9n2_t* arr, uint64_t i,             onumm9n2_t* res);
  onumm9n2_t oarrm9n2_get_item_ij(   oarrm9n2_t* arr, uint64_t i, uint64_t j);
  void      oarrm9n2_get_item_ij_to(oarrm9n2_t* arr, uint64_t i, uint64_t j, onumm9n2_t* res);
  oarrm9n2_t oarrm9n2_init();
  void oarrm9n2_free(oarrm9n2_t* arr);
  oarrm9n2_t oarrm9n2_empty_like(oarrm9n2_t* arr);
  oarrm9n2_t oarrm9n2_eye(uint64_t nrows);
  oarrm9n2_t oarrm9n2_ones(uint64_t nrows, uint64_t ncols);
  oarrm9n2_t oarrm9n2_zeros(uint64_t nrows, uint64_t ncols);
  oarrm9n2_t oarrm9n2_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm9n2/array/utils.h
  
  void oarrm9n2_dimCheck_OO_elementwise(oarrm9n2_t* arr1, oarrm9n2_t* arr2, oarrm9n2_t* res);
  void oarrm9n2_dimCheck_RO_elementwise(darr_t*  arr1, oarrm9n2_t* arr2, oarrm9n2_t* res);
  void oarrm9n2_dimCheck_OO_matmul(oarrm9n2_t* arr1, oarrm9n2_t* arr2, oarrm9n2_t* res);
  void oarrm9n2_dimCheck_RO_matmul(darr_t*  arr1, oarrm9n2_t* arr2, oarrm9n2_t* res);
  void oarrm9n2_dimCheck_OR_matmul(oarrm9n2_t* arr1, darr_t*  arr2, oarrm9n2_t* res);
  void oarrm9n2_dimCheck_O_squareness(oarrm9n2_t* arr1, oarrm9n2_t* res);
  void oarrm9n2_dimCheck_OO_samesize(oarrm9n2_t* arr1, oarrm9n2_t* res);
  void oarrm9n2_dimCheck_RO_samesize(darr_t* arr1, oarrm9n2_t* res);
  ord_t oarrm9n2_get_order(oarrm9n2_t* arr);
  void oarrm9n2_get_active_bases(oarrm9n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm9n2/array/algebra_matops.h
  
  onumm9n2_t oarrm9n2_dotproduct_OO(    oarrm9n2_t* lhs, oarrm9n2_t* rhs);
  void      oarrm9n2_dotproduct_OO_to( oarrm9n2_t* lhs, oarrm9n2_t* rhs, onumm9n2_t* res);
  onumm9n2_t oarrm9n2_dotproduct_RO(     darr_t* lhs, oarrm9n2_t* rhs);
  void      oarrm9n2_dotproduct_RO_to(  darr_t* lhs, oarrm9n2_t* rhs, onumm9n2_t* res);
  oarrm9n2_t oarrm9n2_matmul_OO(    oarrm9n2_t* lhs, oarrm9n2_t* rhs);
  oarrm9n2_t oarrm9n2_matmul_OR(    oarrm9n2_t* lhs,  darr_t* rhs);
  oarrm9n2_t oarrm9n2_matmul_RO(     darr_t* lhs, oarrm9n2_t* rhs);
  void    oarrm9n2_matmul_OO_to( oarrm9n2_t* lhs, oarrm9n2_t* rhs, oarrm9n2_t* res);
  void    oarrm9n2_matmul_OR_to( oarrm9n2_t* lhs,  darr_t* rhs, oarrm9n2_t* res);
  void    oarrm9n2_matmul_RO_to(  darr_t* lhs, oarrm9n2_t* rhs, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_transpose(    oarrm9n2_t* arr1);
  void    oarrm9n2_transpose_to( oarrm9n2_t* arr1, oarrm9n2_t* res);
  oarrm9n2_t oarrm9n2_invert(    oarrm9n2_t* arr1);
  void    oarrm9n2_invert_to( oarrm9n2_t* arr1, oarrm9n2_t* res);
  onumm9n2_t oarrm9n2_det(    oarrm9n2_t* arr1);
  void      oarrm9n2_det_to( oarrm9n2_t* arr1, onumm9n2_t* res);
  onumm9n2_t oarrm9n2_norm(    oarrm9n2_t* arr1);
  void      oarrm9n2_norm_to( oarrm9n2_t* arr1,  onumm9n2_t* res);
  onumm9n2_t oarrm9n2_pnorm(    oarrm9n2_t* arr1, coeff_t p);
  void      oarrm9n2_pnorm_to( oarrm9n2_t* arr1, coeff_t p, onumm9n2_t* res);
  
  
  # From ../../../include/oti/static/onumm9n2/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm9n2/array/gauss/functions.h
  
  feoarrm9n2_t feoarrm9n2_atanh(    feoarrm9n2_t* arr);
  void      feoarrm9n2_atanh_to( feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_asinh(    feoarrm9n2_t* arr);
  void      feoarrm9n2_asinh_to( feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_acosh(    feoarrm9n2_t* arr);
  void      feoarrm9n2_acosh_to( feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_tanh(     feoarrm9n2_t* arr);
  void      feoarrm9n2_tanh_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sinh(     feoarrm9n2_t* arr);
  void      feoarrm9n2_sinh_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_cosh(     feoarrm9n2_t* arr);
  void      feoarrm9n2_cosh_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_atan(     feoarrm9n2_t* arr);
  void      feoarrm9n2_atan_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_asin(     feoarrm9n2_t* arr);
  void      feoarrm9n2_asin_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_acos(     feoarrm9n2_t* arr);
  void      feoarrm9n2_acos_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_tan(      feoarrm9n2_t* arr);
  void      feoarrm9n2_tan_to(   feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sin(      feoarrm9n2_t* arr);
  void      feoarrm9n2_sin_to(   feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_cos(      feoarrm9n2_t* arr);
  void      feoarrm9n2_cos_to(   feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_logb(     feoarrm9n2_t* arr, double base);
  void      feoarrm9n2_logb_to(  feoarrm9n2_t* arr, double base, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_log10(    feoarrm9n2_t* arr);
  void      feoarrm9n2_log10_to( feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_log(      feoarrm9n2_t* arr);
  void      feoarrm9n2_log_to(   feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_exp(      feoarrm9n2_t* arr);
  void      feoarrm9n2_exp_to(   feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_cbrt(     feoarrm9n2_t* arr);
  void      feoarrm9n2_cbrt_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sqrt(     feoarrm9n2_t* arr);
  void      feoarrm9n2_sqrt_to(  feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_pow(      feoarrm9n2_t* arr, double e);
  void      feoarrm9n2_pow_to(   feoarrm9n2_t* arr, double e, feoarrm9n2_t* res);
  
  
  # From ../../../include/oti/static/onumm9n2/array/gauss/base.h
  
  void      feoarrm9n2_get_order_im_to( ord_t order, feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_get_order_im(    ord_t order, feoarrm9n2_t* arr);
  feoarrm9n2_t feoarrm9n2_get_deriv(   imdir_t idx, ord_t order, feoarrm9n2_t* arr);
  void      feoarrm9n2_get_deriv_to(imdir_t idx, ord_t order, feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_get_im(      imdir_t idx, ord_t order, feoarrm9n2_t* arr);
  void      feoarrm9n2_get_im_to(   imdir_t idx, ord_t order, feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_truncate_im(   imdir_t idx, ord_t order, feoarrm9n2_t* arr);
  void      feoarrm9n2_truncate_im_to(imdir_t idx, ord_t order, feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_copy(   feoarrm9n2_t* src);
  void      feoarrm9n2_copy_to(feoarrm9n2_t* src, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_get_im(    imdir_t idx, ord_t order, feoarrm9n2_t* arr);
  void      feoarrm9n2_get_im_to( imdir_t idx, ord_t order, feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_get_deriv(    imdir_t idx, ord_t order, feoarrm9n2_t* arr);
  void      feoarrm9n2_get_deriv_to( imdir_t idx, ord_t order, feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_extract_im(    imdir_t idx, ord_t order, feoarrm9n2_t* arr);
  void      feoarrm9n2_extract_im_to( imdir_t idx, ord_t order, feoarrm9n2_t* arr,  feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_extract_deriv(    imdir_t idx, ord_t order, feoarrm9n2_t* arr);
  void      feoarrm9n2_extract_deriv_to( imdir_t idx, ord_t order, feoarrm9n2_t* arr, feoarrm9n2_t* res);
  oarrm9n2_t   feoarrm9n2_get_item_k(  feoarrm9n2_t* arr, uint64_t k);
  feonumm9n2_t  feoarrm9n2_get_item_ij( feoarrm9n2_t* arr, uint64_t i, uint64_t j);
  onumm9n2_t feoarrm9n2_get_item_ijk(feoarrm9n2_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm9n2_get_item_ij_to(  feoarrm9n2_t* arr, uint64_t i, uint64_t j,
                                 feonumm9n2_t* res);
  void feoarrm9n2_get_item_k_to(   feoarrm9n2_t* arr, uint64_t k,
                                  oarrm9n2_t* res);
  void feoarrm9n2_get_item_ijk_to( feoarrm9n2_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_get_slice(feoarrm9n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm9n2_get_slice_to(feoarrm9n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n2_t* res);
  void feoarrm9n2_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm9n2_t* res);
  void feoarrm9n2_set_item_ij_o(  onumm9n2_t* elm, uint64_t i, uint64_t j,
                               feoarrm9n2_t* res);
  void feoarrm9n2_set_item_ij_f(  feonumm9n2_t* elm, uint64_t i, uint64_t j,
                              feoarrm9n2_t* res);
  void feoarrm9n2_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm9n2_t* res);
  void feoarrm9n2_set_item_k_o(  onumm9n2_t* elm, uint64_t k,
                              feoarrm9n2_t* res);
  void feoarrm9n2_set_item_k_R(    oarrm9n2_t* elm, uint64_t k,
                            feoarrm9n2_t* res);
  void feoarrm9n2_set_item_k_O(    oarrm9n2_t* elm, uint64_t k,
                            feoarrm9n2_t* res);
  void feoarrm9n2_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm9n2_t* res);
  void feoarrm9n2_set_item_ijk_o( onumm9n2_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm9n2_t* res);
  void feoarrm9n2_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n2_t* res);
  void feoarrm9n2_set_slice_o( onumm9n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n2_t* res);
  void feoarrm9n2_set_slice_f( feonumm9n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n2_t* res);
  void feoarrm9n2_set_slice_O( oarrm9n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n2_t* res);
  void feoarrm9n2_set_slice_F( feoarrm9n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n2_t* res);
  void feoarrm9n2_set_all_o( onumm9n2_t* num, feoarrm9n2_t* arr );
  void feoarrm9n2_set_all_r(   coeff_t  num, feoarrm9n2_t* arr );
  void feoarrm9n2_set_all_f(  feonumm9n2_t* num, feoarrm9n2_t* arr );
  void feoarrm9n2_set_r(    coeff_t src, feoarrm9n2_t* res );
  void feoarrm9n2_set_o( onumm9n2_t* src, feoarrm9n2_t* res );
  void feoarrm9n2_set_f(  feonumm9n2_t* src, feoarrm9n2_t* res );
  void feoarrm9n2_set_R(    darr_t* src, feoarrm9n2_t* res );
  void feoarrm9n2_set_O(   oarrm9n2_t* src, feoarrm9n2_t* res );
  void feoarrm9n2_set_F( feoarrm9n2_t* src, feoarrm9n2_t* res );
  feoarrm9n2_t feoarrm9n2_eye( uint64_t size,  uint64_t nip);
  feoarrm9n2_t feoarrm9n2_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm9n2_t feoarrm9n2_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm9n2_t feoarrm9n2_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm9n2_free(feoarrm9n2_t* arr);
  feoarrm9n2_t feoarrm9n2_init();
  ord_t feoarrm9n2_get_order(feoarrm9n2_t* arr);
  
  
  # From ../../../include/oti/static/onumm9n2/array/gauss/utils.h
  
  void feoarrm9n2_dimCheck_FF_samesize(feoarrm9n2_t* arr1, feoarrm9n2_t* arr2, feonumm9n2_t* res);
  void feoarrm9n2_dimCheck_OF_samesize(  oarrm9n2_t* arr1, feoarrm9n2_t* arr2, feonumm9n2_t* res);
  void feoarrm9n2_dimCheck_RF_samesize(   darr_t* arr1, feoarrm9n2_t* arr2, feonumm9n2_t* res);
  void feoarrm9n2_dimCheck_FF_elementwise(feoarrm9n2_t* arr1, feoarrm9n2_t* arr2, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_OF_elementwise(  oarrm9n2_t* arr1, feoarrm9n2_t* arr2, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm9n2_t* arr2, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_fF_elementwise( feonumm9n2_t* num1, feoarrm9n2_t* arr2, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_Ff_elementwise(feoarrm9n2_t* arr1,  feonumm9n2_t* num2, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_FF_matmul( feoarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_OF_matmul(   oarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_FO_matmul( feoarrm9n2_t* lhs,   oarrm9n2_t* rhs, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_FR_matmul( feoarrm9n2_t* lhs,    darr_t* rhs, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_F_squareness( feoarrm9n2_t* arr1, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_F_transpose( feoarrm9n2_t* arr1, feoarrm9n2_t* res);
  void feoarrm9n2_dimCheck_FfO_integrate(feoarrm9n2_t* arr, feonumm9n2_t* num,oarrm9n2_t* res);
  void feoarrm9n2_get_active_bases(feoarrm9n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm9n2/array/gauss/algebra.h
  
  feoarrm9n2_t feoarrm9n2_neg(    feoarrm9n2_t* arr);
  void      feoarrm9n2_neg_to( feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sum_FF(   feoarrm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sum_FF_to(feoarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sum_fF(    feonumm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sum_fF_to( feonumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sum_OF(     oarrm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sum_OF_to(  oarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sum_RF(      darr_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sum_RF_to(   darr_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sum_oF(   onumm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sum_oF_to(onumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sum_rF(     coeff_t  lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sum_rF_to(  coeff_t  lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sub_FF(    feoarrm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sub_FF_to( feoarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sub_fF(    feonumm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sub_fF_to( feonumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sub_Ff(    feoarrm9n2_t* lhs, feonumm9n2_t* rhs);
  void      feoarrm9n2_sub_Ff_to( feoarrm9n2_t* lhs, feonumm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sub_OF(      oarrm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sub_OF_to(   oarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sub_FO(    feoarrm9n2_t* lhs,   oarrm9n2_t* rhs);
  void      feoarrm9n2_sub_FO_to( feoarrm9n2_t* lhs,   oarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sub_RF(       darr_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sub_RF_to(    darr_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sub_FR(    feoarrm9n2_t* lhs,    darr_t* rhs);
  void      feoarrm9n2_sub_FR_to( feoarrm9n2_t* lhs,    darr_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sub_oF(    onumm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sub_oF_to( onumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sub_Fo(    feoarrm9n2_t* lhs, onumm9n2_t* rhs);
  void      feoarrm9n2_sub_Fo_to( feoarrm9n2_t* lhs, onumm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sub_rF(      coeff_t  lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_sub_rF_to(    coeff_t lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_sub_Fr(    feoarrm9n2_t* lhs,   coeff_t  rhs);
  void      feoarrm9n2_sub_Fr_to( feoarrm9n2_t* lhs,   coeff_t  rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_mul_FF(   feoarrm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_mul_FF_to(feoarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_mul_fF(    feonumm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_mul_fF_to( feonumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_mul_OF(     oarrm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_mul_OF_to(  oarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_mul_RF(      darr_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_mul_RF_to(   darr_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_mul_oF(   onumm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_mul_oF_to(onumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_mul_rF(     coeff_t  lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_mul_rF_to(  coeff_t  lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_div_FF(    feoarrm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_div_FF_to( feoarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_div_fF(     feonumm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_div_fF_to(  feonumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_div_Ff(    feoarrm9n2_t* lhs,  feonumm9n2_t* rhs);
  void      feoarrm9n2_div_Ff_to( feoarrm9n2_t* lhs,  feonumm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_div_OF(      oarrm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_div_OF_to(   oarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_div_FO(    feoarrm9n2_t* lhs,   oarrm9n2_t* rhs);
  void      feoarrm9n2_div_FO_to( feoarrm9n2_t* lhs,   oarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_div_RF(       darr_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_div_RF_to(    darr_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_div_FR(    feoarrm9n2_t* lhs,    darr_t* rhs);
  void      feoarrm9n2_div_FR_to( feoarrm9n2_t* lhs,    darr_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_div_oF(    onumm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_div_oF_to( onumm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_div_Fo(    feoarrm9n2_t* lhs, onumm9n2_t* rhs);
  void      feoarrm9n2_div_Fo_to( feoarrm9n2_t* lhs, onumm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_div_rF(      coeff_t  lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_div_rF_to(    coeff_t lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_div_Fr(    feoarrm9n2_t* lhs,   coeff_t  rhs);
  void      feoarrm9n2_div_Fr_to( feoarrm9n2_t* lhs,   coeff_t  rhs, feoarrm9n2_t* res);
  oarrm9n2_t feoarrm9n2_integrate(    feoarrm9n2_t* arr, feonumm9n2_t* w);
  void    feoarrm9n2_integrate_to( feoarrm9n2_t* arr, feonumm9n2_t* w, oarrm9n2_t* res);
  feonumm9n2_t feoarrm9n2_dotproduct_FF(    feoarrm9n2_t* lhs, feoarrm9n2_t* rhs);
  void     feoarrm9n2_dotproduct_FF_to( feoarrm9n2_t* lhs, feoarrm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feoarrm9n2_dotproduct_OF(      oarrm9n2_t* lhs, feoarrm9n2_t* rhs);
  void     feoarrm9n2_dotproduct_OF_to(   oarrm9n2_t* lhs, feoarrm9n2_t* rhs, feonumm9n2_t* res);
  feonumm9n2_t feoarrm9n2_dotproduct_RF(       darr_t* lhs, feoarrm9n2_t* rhs);
  void     feoarrm9n2_dotproduct_RF_to(    darr_t* lhs, feoarrm9n2_t* rhs, feonumm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_matmul_FF(    feoarrm9n2_t* lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_matmul_FF_to( feoarrm9n2_t* lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_matmul_OF(    oarrm9n2_t*   lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_matmul_OF_to( oarrm9n2_t*   lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_matmul_FO(    feoarrm9n2_t* lhs, oarrm9n2_t*   rhs);
  void      feoarrm9n2_matmul_FO_to( feoarrm9n2_t* lhs, oarrm9n2_t*   rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_matmul_RF(    darr_t*    lhs, feoarrm9n2_t* rhs);
  void      feoarrm9n2_matmul_RF_to( darr_t*    lhs, feoarrm9n2_t* rhs, feoarrm9n2_t* res);
  feoarrm9n2_t feoarrm9n2_matmul_FR(    feoarrm9n2_t* lhs, darr_t*    rhs);
  void      feoarrm9n2_matmul_FR_to( feoarrm9n2_t* lhs, darr_t*    rhs, feoarrm9n2_t* res);
  feonumm9n2_t feoarrm9n2_det(   feoarrm9n2_t* arr);
  void     feoarrm9n2_det_to(feoarrm9n2_t* arr, feonumm9n2_t* res);
  feonumm9n2_t feoarrm9n2_norm(     feoarrm9n2_t* arr);
  void     feoarrm9n2_norm_to(  feoarrm9n2_t* arr, feonumm9n2_t* res);
  feonumm9n2_t feoarrm9n2_pnorm(    feoarrm9n2_t* arr, coeff_t p);
  void     feoarrm9n2_pnorm_to( feoarrm9n2_t* arr, coeff_t p, feonumm9n2_t* res);
  feoarrm9n2_t   feoarrm9n2_invert(    feoarrm9n2_t* arr);
  void        feoarrm9n2_invert_to( feoarrm9n2_t* arr, feoarrm9n2_t* res);
  feoarrm9n2_t   feoarrm9n2_transpose(   feoarrm9n2_t* arr);
  void        feoarrm9n2_transpose_to(feoarrm9n2_t* arr, feoarrm9n2_t* res);
  
  