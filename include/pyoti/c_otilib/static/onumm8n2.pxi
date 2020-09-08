cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm8n2/scalar/structures.h
  
  ctypedef struct  onumm8n2_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
    coeff_t e6;
    coeff_t e7;
    coeff_t e8;
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
  # } onumm8n2_t;
  
  
  # From ../../../include/oti/static/onumm8n2/array/structures.h
  
  ctypedef struct  oarrm8n2_t : # {
      onumm8n2_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm8n2_t;
  
  
  # From ../../../include/oti/static/onumm8n2/scalar/gauss/structures.h
  
  ctypedef struct  feonumm8n2_t: # {
      onumm8n2_t*  p_data;
      uint64_t    nip;
  # } feonumm8n2_t;
  
  
  # From ../../../include/oti/static/onumm8n2/array/gauss/structures.h
  
  ctypedef struct  feoarrm8n2_t: # {
      oarrm8n2_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm8n2_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm8n2/scalar/functions.h
  
  onumm8n2_t onumm8n2_atanh(onumm8n2_t* num);
  void onumm8n2_atanh_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_asinh(onumm8n2_t* num);
  void onumm8n2_asinh_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_acosh(onumm8n2_t* num);
  void onumm8n2_acosh_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_tanh(onumm8n2_t* num);
  void onumm8n2_tanh_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_sqrt(onumm8n2_t* num);
  void onumm8n2_sqrt_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_cbrt(onumm8n2_t* num);
  void onumm8n2_cbrt_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_cosh(onumm8n2_t* num);
  void onumm8n2_cosh_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_sinh(onumm8n2_t* num);
  void onumm8n2_sinh_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_asin(onumm8n2_t* num);
  void onumm8n2_asin_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_acos(onumm8n2_t* num);
  void onumm8n2_acos_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_atan(onumm8n2_t* num);
  void onumm8n2_atan_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_tan(onumm8n2_t* num);
  void onumm8n2_tan_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_cos(onumm8n2_t* num);
  void onumm8n2_cos_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_sin(onumm8n2_t* num );
  void onumm8n2_sin_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_logb(onumm8n2_t* num, double base);
  void onumm8n2_logb_to(onumm8n2_t* num, double base, onumm8n2_t* res);
  onumm8n2_t onumm8n2_log10(onumm8n2_t* num);
  void onumm8n2_log10_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_log(onumm8n2_t* num);
  void onumm8n2_log_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_exp(onumm8n2_t* num);
  void onumm8n2_exp_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_pow(onumm8n2_t* num, double e);
  void onumm8n2_pow_to(onumm8n2_t* num, coeff_t e, onumm8n2_t* res);
  
  
  # From ../../../include/oti/static/onumm8n2/scalar/base.h
  
  void onumm8n2_set_im_o(onumm8n2_t* num, imdir_t idx, ord_t order, onumm8n2_t* res);
  void onumm8n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm8n2_t* res);
  void onumm8n2_set_deriv_o(onumm8n2_t* num, imdir_t idx, ord_t order, onumm8n2_t* res);
  void onumm8n2_extract_im_to( imdir_t idx, ord_t order, onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_extract_im(imdir_t idx, ord_t order, onumm8n2_t* num);
  onumm8n2_t onumm8n2_extract_deriv(imdir_t idx, ord_t order, onumm8n2_t* num);
  void onumm8n2_extract_deriv_to(imdir_t idx, ord_t order, onumm8n2_t* num, onumm8n2_t* res);
  void onumm8n2_get_im_to_o(imdir_t idx, ord_t order, onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_get_im_o(imdir_t idx, ord_t order, onumm8n2_t* num);
  void onumm8n2_get_im_to_r(imdir_t idx, ord_t order, onumm8n2_t* num, coeff_t* res);
  ord_t onumm8n2_get_order(onumm8n2_t* lhs);
  onumm8n2_t onumm8n2_get_deriv_o( imdir_t idx, ord_t order, onumm8n2_t* num);
  void onumm8n2_get_deriv_to( imdir_t idx, ord_t order, onumm8n2_t* num, onumm8n2_t* res);
  void onumm8n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm8n2_t* res);
  onumm8n2_t onumm8n2_init();
  ndir_t onumm8n2_get_ndir_order(ord_t order, onumm8n2_t* num);
  ndir_t onumm8n2_get_ndir_total(onumm8n2_t* num);
  coeff_t* onumm8n2_get_order_address(ord_t order, onumm8n2_t* num);
  onumm8n2_t onumm8n2_create_r(  coeff_t lhs);
  void onumm8n2_set_r(  coeff_t lhs, onumm8n2_t* res);
  void onumm8n2_set_o(  onumm8n2_t* lhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_get_order_im(ord_t order, onumm8n2_t* lhs);
  void onumm8n2_get_order_im_to(ord_t order, onumm8n2_t* lhs, onumm8n2_t* res);
  coeff_t onumm8n2_get_item(imdir_t idx, ord_t order, onumm8n2_t* lhs);
  coeff_t onumm8n2_get_deriv(imdir_t idx, ord_t order, onumm8n2_t* lhs);
  void onumm8n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm8n2_t* x);
  onumm8n2_t onumm8n2_copy(  onumm8n2_t* lhs);
  void onumm8n2_copy_to(  onumm8n2_t* lhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_taylor_integrate(coeff_t* deltas,onumm8n2_t* lhs);
  void onumm8n2_taylor_integrate_to(coeff_t* deltas,onumm8n2_t* lhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_truncate_im(imdir_t idx, ord_t order, onumm8n2_t* lhs);
  void onumm8n2_truncate_im_to(imdir_t idx, ord_t order, onumm8n2_t* lhs, onumm8n2_t* res);
  void onumm8n2_print(  onumm8n2_t* lhs);
  imdir_t onumm8n2_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm8n2/scalar/utils.h
  
  void onumm8n2_get_active_bases(onumm8n2_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm8n2/scalar/algebra.h
  
  onumm8n2_t onumm8n2_abs(onumm8n2_t* num);
  onumm8n2_t onumm8n2_div_ro(coeff_t num, onumm8n2_t* den);
  onumm8n2_t onumm8n2_div_oo(onumm8n2_t* num, onumm8n2_t* den);
  onumm8n2_t onumm8n2_div_or(onumm8n2_t* num, coeff_t val);
  void onumm8n2_div_ro_to(coeff_t num, onumm8n2_t* den, onumm8n2_t* res);
  void onumm8n2_div_oo_to(onumm8n2_t* num, onumm8n2_t* den, onumm8n2_t* res);
  void onumm8n2_div_or_to(onumm8n2_t* num, coeff_t val, onumm8n2_t* res);
  void onumm8n2_abs_to(onumm8n2_t* num, onumm8n2_t* res);
  onumm8n2_t onumm8n2_neg(  onumm8n2_t* lhs);
  void onumm8n2_neg_to(  onumm8n2_t* lhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_sum_oo(  onumm8n2_t* lhs,  onumm8n2_t* rhs);
  void onumm8n2_sum_oo_to(  onumm8n2_t* lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_sum_ro(  coeff_t lhs,  onumm8n2_t* rhs);
  void onumm8n2_sum_ro_to(  coeff_t lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_sub_oo(  onumm8n2_t* lhs,  onumm8n2_t* rhs);
  void onumm8n2_sub_oo_to(  onumm8n2_t* lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_sub_ro(  coeff_t lhs,  onumm8n2_t* rhs);
  void onumm8n2_sub_ro_to(  coeff_t lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_sub_or(  onumm8n2_t* lhs,  coeff_t rhs);
  void onumm8n2_sub_or_to(  onumm8n2_t* lhs,  coeff_t rhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_mul_oo(  onumm8n2_t* lhs,  onumm8n2_t* rhs);
  void onumm8n2_mul_oo_to(  onumm8n2_t* lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_mul_ro(  coeff_t lhs,  onumm8n2_t* rhs);
  void onumm8n2_mul_ro_to(  coeff_t lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_trunc_mul_oo(  onumm8n2_t* lhs,  onumm8n2_t* rhs);
  void onumm8n2_trunc_mul_oo_to(  onumm8n2_t* lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
  onumm8n2_t onumm8n2_gem_oo(  onumm8n2_t* a,  onumm8n2_t* b,  onumm8n2_t* c);
  void onumm8n2_gem_oo_to(  onumm8n2_t* a,  onumm8n2_t* b,  onumm8n2_t* c, onumm8n2_t* res);
  onumm8n2_t onumm8n2_gem_ro(  coeff_t a,  onumm8n2_t* b,  onumm8n2_t* c);
  void onumm8n2_gem_ro_to(  coeff_t a,  onumm8n2_t* b,  onumm8n2_t* c, onumm8n2_t* res);
  void onumm8n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm8n2_t* a,  ord_t ord_rhs,  onumm8n2_t* b,  onumm8n2_t* c, onumm8n2_t* res);
  onumm8n2_t onumm8n2_feval(coeff_t* feval_re, onumm8n2_t* x);
  void onumm8n2_feval_to(coeff_t* feval_re, onumm8n2_t* x, onumm8n2_t* res);
  
  
  # From ../../../include/oti/static/onumm8n2/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm8n2/scalar/gauss/functions.h
  
  feonumm8n2_t feonumm8n2_atanh(    feonumm8n2_t* num);
  void     feonumm8n2_atanh_to( feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_asinh(    feonumm8n2_t* num);
  void     feonumm8n2_asinh_to( feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_acosh(    feonumm8n2_t* num);
  void     feonumm8n2_acosh_to( feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_tanh(     feonumm8n2_t* num);
  void     feonumm8n2_tanh_to(  feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_cosh(     feonumm8n2_t* num);
  void     feonumm8n2_cosh_to(  feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_sinh(     feonumm8n2_t* num);
  void     feonumm8n2_sinh_to(  feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_asin(     feonumm8n2_t* num);
  void     feonumm8n2_asin_to(  feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_acos(     feonumm8n2_t* num);
  void     feonumm8n2_acos_to(  feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_atan(     feonumm8n2_t* num);
  void     feonumm8n2_atan_to(  feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_tan(      feonumm8n2_t* num);
  void     feonumm8n2_tan_to(   feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_cos(      feonumm8n2_t* num);
  void     feonumm8n2_cos_to(   feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_sin(      feonumm8n2_t* num);
  void     feonumm8n2_sin_to(   feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_logb(     feonumm8n2_t* num, double base);
  void     feonumm8n2_logb_to(  feonumm8n2_t* num, double base, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_log10(    feonumm8n2_t* num);
  void     feonumm8n2_log10_to( feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_log(      feonumm8n2_t* num);
  void     feonumm8n2_log_to(   feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_exp(      feonumm8n2_t* num);
  void     feonumm8n2_exp_to(   feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_cbrt(     feonumm8n2_t* num);
  void     feonumm8n2_cbrt_to(  feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_sqrt(     feonumm8n2_t* num);
  void     feonumm8n2_sqrt_to(  feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_pow(      feonumm8n2_t* num, double e);
  void     feonumm8n2_pow_to(   feonumm8n2_t* num, double e, feonumm8n2_t* res);
  onumm8n2_t feonumm8n2_integrate(       feonumm8n2_t* num, feonumm8n2_t* w);
  void      feonumm8n2_integrate_to(    feonumm8n2_t* num, feonumm8n2_t* w, onumm8n2_t* res);
  onumm8n2_t feonumm8n2_integrate_f(     feonumm8n2_t* num, feonumm8n2_t* w);
  void      feonumm8n2_integrate_f_to(  feonumm8n2_t* num, feonumm8n2_t* w, onumm8n2_t* res);
  onumm8n2_t feonumm8n2_integrate_r(       coeff_t num, feonumm8n2_t* w);
  void      feonumm8n2_integrate_r_to(    coeff_t num, feonumm8n2_t* w, onumm8n2_t* res);
  onumm8n2_t feonumm8n2_integrate_o(    onumm8n2_t* num, feonumm8n2_t* w);
  void      feonumm8n2_integrate_o_to( onumm8n2_t* num, feonumm8n2_t* w, onumm8n2_t* res);
  
  
  # From ../../../include/oti/static/onumm8n2/scalar/gauss/base.h
  
  void     feonumm8n2_get_order_im_to( ord_t order, feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_get_order_im(    ord_t order, feonumm8n2_t* num);
  feonumm8n2_t feonumm8n2_get_im(    imdir_t idx, ord_t order, feonumm8n2_t* num);
  void     feonumm8n2_get_im_to( imdir_t idx, ord_t order, feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_get_deriv(    imdir_t idx, ord_t order, feonumm8n2_t* num);
  void     feonumm8n2_get_deriv_to( imdir_t idx, ord_t order, feonumm8n2_t* num, feonumm8n2_t* res);
  void feonumm8n2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm8n2_t* num);
  void feonumm8n2_set_im_o( onumm8n2_t* val, imdir_t idx, ord_t order, feonumm8n2_t* num);
  void feonumm8n2_set_im_f(  feonumm8n2_t* val, imdir_t idx, ord_t order, feonumm8n2_t* num);
  void feonumm8n2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm8n2_t* num);
  void feonumm8n2_set_deriv_o( onumm8n2_t* val, imdir_t idx, ord_t order, feonumm8n2_t* num);
  void feonumm8n2_set_deriv_f(  feonumm8n2_t* val, imdir_t idx, ord_t order, feonumm8n2_t* num);
  feonumm8n2_t feonumm8n2_extract_im(    imdir_t idx, ord_t order, feonumm8n2_t* num);
  void     feonumm8n2_extract_im_to( imdir_t idx, ord_t order, feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_extract_deriv(    imdir_t idx, ord_t order, feonumm8n2_t* num);
  void     feonumm8n2_extract_deriv_to( imdir_t idx, ord_t order, feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_truncate_im(    imdir_t idx, ord_t order, feonumm8n2_t* num);
  void     feonumm8n2_truncate_im_to( imdir_t idx, ord_t order, feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_copy(    feonumm8n2_t* src);
  void     feonumm8n2_copy_to( feonumm8n2_t* src, feonumm8n2_t* dst);
  void feonumm8n2_set_r(    coeff_t num, feonumm8n2_t* res);
  void feonumm8n2_set_o( onumm8n2_t* num, feonumm8n2_t* res);
  void feonumm8n2_set_f(  feonumm8n2_t* num, feonumm8n2_t* res);
  void feonumm8n2_set_item_k_r(   coeff_t  num, uint64_t k, feonumm8n2_t* res);
  void feonumm8n2_set_item_k_o( onumm8n2_t* num, uint64_t k, feonumm8n2_t* res);
  onumm8n2_t feonumm8n2_get_item_k(   feonumm8n2_t* num, uint64_t k);
  void      feonumm8n2_get_item_k_to(feonumm8n2_t* num, uint64_t k, onumm8n2_t* res);
  feonumm8n2_t feonumm8n2_zeros(uint64_t nIntPts);
  feonumm8n2_t feonumm8n2_createEmpty(uint64_t nIntPts);
  feonumm8n2_t feonumm8n2_empty_like(feonumm8n2_t* arr);
  void feonumm8n2_free(feonumm8n2_t* num);
  ord_t feonumm8n2_get_order( feonumm8n2_t* num );
  feonumm8n2_t feonumm8n2_init();
  
  
  # From ../../../include/oti/static/onumm8n2/scalar/gauss/utils.h
  
  void feonumm8n2_dimCheck(feonumm8n2_t* arr1,feonumm8n2_t* arr2);
  void feonumm8n2_get_active_bases(feonumm8n2_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm8n2/scalar/gauss/algebra.h
  
  feonumm8n2_t feonumm8n2_neg(   feonumm8n2_t* num);
  void     feonumm8n2_neg_to(feonumm8n2_t* num, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_sum_ff(   feonumm8n2_t* lhs, feonumm8n2_t* rhs);
  void     feonumm8n2_sum_ff_to(feonumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_sum_of(   onumm8n2_t* lhs, feonumm8n2_t* rhs);
  void     feonumm8n2_sum_of_to(onumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_sum_rf(   coeff_t lhs, feonumm8n2_t* rhs);
  void     feonumm8n2_sum_rf_to(coeff_t lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_sub_ff(     feonumm8n2_t* lhs,  feonumm8n2_t* rhs);
  void     feonumm8n2_sub_ff_to(  feonumm8n2_t* lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_sub_of(    onumm8n2_t* lhs,  feonumm8n2_t* rhs);
  void     feonumm8n2_sub_of_to( onumm8n2_t* lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_sub_fo(     feonumm8n2_t* lhs, onumm8n2_t* rhs);
  void     feonumm8n2_sub_fo_to(  feonumm8n2_t* lhs, onumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_sub_rf(       coeff_t lhs,  feonumm8n2_t* rhs);
  void     feonumm8n2_sub_rf_to(    coeff_t lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_sub_fr(     feonumm8n2_t* lhs,    coeff_t rhs);
  void     feonumm8n2_sub_fr_to(  feonumm8n2_t* lhs,    coeff_t rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_mul_ff(   feonumm8n2_t* lhs, feonumm8n2_t* rhs);
  void     feonumm8n2_mul_ff_to(feonumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_mul_of(   onumm8n2_t* lhs, feonumm8n2_t* rhs);
  void     feonumm8n2_mul_of_to(onumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_mul_rf(   coeff_t lhs, feonumm8n2_t* rhs);
  void     feonumm8n2_mul_rf_to(coeff_t lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_div_ff(     feonumm8n2_t* lhs,  feonumm8n2_t* rhs);
  void     feonumm8n2_div_ff_to(  feonumm8n2_t* lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_div_of(    onumm8n2_t* lhs,  feonumm8n2_t* rhs);
  void     feonumm8n2_div_of_to( onumm8n2_t* lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_div_fo(     feonumm8n2_t* lhs, onumm8n2_t* rhs);
  void     feonumm8n2_div_fo_to(  feonumm8n2_t* lhs, onumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_div_rf(       coeff_t lhs,  feonumm8n2_t* rhs);
  void     feonumm8n2_div_rf_to(    coeff_t lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feonumm8n2_div_fr(     feonumm8n2_t* lhs,    coeff_t rhs);
  void     feonumm8n2_div_fr_to(  feonumm8n2_t* lhs,    coeff_t rhs, feonumm8n2_t* res);
  
  
  # From ../../../include/oti/static/onumm8n2/array/functions.h
  
  oarrm8n2_t oarrm8n2_atanh(   oarrm8n2_t* arr);
  void    oarrm8n2_atanh_to(oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_asinh(   oarrm8n2_t* arr);
  void    oarrm8n2_asinh_to(oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_acosh(   oarrm8n2_t* arr);
  void    oarrm8n2_acosh_to(oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_tanh(    oarrm8n2_t* arr);
  void    oarrm8n2_tanh_to( oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_cbrt(    oarrm8n2_t* arr);
  void    oarrm8n2_cbrt_to( oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_sqrt(    oarrm8n2_t* arr);
  void    oarrm8n2_sqrt_to( oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_cosh(    oarrm8n2_t* arr);
  void    oarrm8n2_cosh_to( oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_sinh(    oarrm8n2_t* arr);
  void    oarrm8n2_sinh_to( oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_asin(    oarrm8n2_t* arr);
  void    oarrm8n2_asin_to( oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_acos(    oarrm8n2_t* arr);
  void    oarrm8n2_acos_to( oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_atan(    oarrm8n2_t* arr);
  void    oarrm8n2_atan_to( oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_tan(     oarrm8n2_t* arr);
  void    oarrm8n2_tan_to(  oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_cos(     oarrm8n2_t* arr);
  void    oarrm8n2_cos_to(  oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_sin(     oarrm8n2_t* arr);
  void    oarrm8n2_sin_to(  oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_logb(    oarrm8n2_t* arr, double base);
  void    oarrm8n2_logb_to( oarrm8n2_t* arr, double base, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_log10(   oarrm8n2_t* arr);
  void    oarrm8n2_log10_to(oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_log(     oarrm8n2_t* arr);
  void    oarrm8n2_log_to(  oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_exp(     oarrm8n2_t* arr);
  void    oarrm8n2_exp_to(  oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_pow(     oarrm8n2_t* arr, double e);
  void    oarrm8n2_pow_to(  oarrm8n2_t* arr, double e, oarrm8n2_t* res);
  
  
  # From ../../../include/oti/static/onumm8n2/array/algebra_elementwise.h
  
  oarrm8n2_t oarrm8n2_neg(oarrm8n2_t* arr);
  void oarrm8n2_neg_to(oarrm8n2_t* rhs, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_sum_OO(oarrm8n2_t*   lhs, oarrm8n2_t* rhs);
  oarrm8n2_t oarrm8n2_sum_RO(darr_t*    lhs, oarrm8n2_t* rhs);
  oarrm8n2_t oarrm8n2_sum_oO(onumm8n2_t* lhs, oarrm8n2_t* rhs);
  oarrm8n2_t oarrm8n2_sum_rO(coeff_t    lhs, oarrm8n2_t* rhs);
  void oarrm8n2_sum_OO_to(oarrm8n2_t*   lhs, oarrm8n2_t* rhs, oarrm8n2_t* res);
  void oarrm8n2_sum_RO_to(darr_t*    lhs, oarrm8n2_t* rhs, oarrm8n2_t* res);
  void oarrm8n2_sum_oO_to(onumm8n2_t* lhs, oarrm8n2_t* rhs, oarrm8n2_t* res);
  void oarrm8n2_sum_rO_to(coeff_t    lhs, oarrm8n2_t* rhs, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_sub_OO(oarrm8n2_t*   lhs, oarrm8n2_t*   rhs);
  oarrm8n2_t oarrm8n2_sub_RO(darr_t*    lhs, oarrm8n2_t*   rhs);
  oarrm8n2_t oarrm8n2_sub_OR(oarrm8n2_t*   lhs, darr_t*    rhs);
  oarrm8n2_t oarrm8n2_sub_oO(onumm8n2_t* lhs, oarrm8n2_t*   rhs);
  oarrm8n2_t oarrm8n2_sub_Oo(oarrm8n2_t*   lhs, onumm8n2_t* rhs);
  oarrm8n2_t oarrm8n2_sub_rO(coeff_t    lhs, oarrm8n2_t*   rhs);
  oarrm8n2_t oarrm8n2_sub_Or(oarrm8n2_t*   lhs, coeff_t    rhs);
  void oarrm8n2_sub_OO_to( oarrm8n2_t*   lhs, oarrm8n2_t*   rhs, oarrm8n2_t* res);
  void oarrm8n2_sub_RO_to( darr_t*    lhs, oarrm8n2_t*   rhs, oarrm8n2_t* res);
  void oarrm8n2_sub_OR_to( oarrm8n2_t*   lhs, darr_t*    rhs, oarrm8n2_t* res);
  void oarrm8n2_sub_oO_to( onumm8n2_t* lhs, oarrm8n2_t*   rhs, oarrm8n2_t* res);
  void oarrm8n2_sub_Oo_to( oarrm8n2_t*   lhs, onumm8n2_t* rhs, oarrm8n2_t* res);
  void oarrm8n2_sub_rO_to( coeff_t    lhs, oarrm8n2_t*   rhs, oarrm8n2_t* res);
  void oarrm8n2_sub_Or_to( oarrm8n2_t*   lhs, coeff_t    rhs, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_mul_OO(oarrm8n2_t*   lhs, oarrm8n2_t* rhs);
  oarrm8n2_t oarrm8n2_mul_RO(darr_t*    lhs, oarrm8n2_t* rhs);
  oarrm8n2_t oarrm8n2_mul_oO(onumm8n2_t* lhs, oarrm8n2_t* rhs);
  oarrm8n2_t oarrm8n2_mul_rO(coeff_t    lhs, oarrm8n2_t* rhs);
  void oarrm8n2_mul_OO_to(oarrm8n2_t*   lhs, oarrm8n2_t* rhs, oarrm8n2_t* res);
  void oarrm8n2_mul_RO_to(darr_t*    lhs, oarrm8n2_t* rhs, oarrm8n2_t* res);
  void oarrm8n2_mul_oO_to(onumm8n2_t* lhs, oarrm8n2_t* rhs, oarrm8n2_t* res);
  void oarrm8n2_mul_rO_to(coeff_t    lhs, oarrm8n2_t* rhs, oarrm8n2_t* res);
  void oarrm8n2_gem_OO_to(  oarrm8n2_t* arr1, oarrm8n2_t* arr2, oarrm8n2_t* arr3, oarrm8n2_t* res);
  void oarrm8n2_gem_oO_to(onumm8n2_t* arr1, oarrm8n2_t* arr2, oarrm8n2_t* arr3, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_div_OO(oarrm8n2_t*   lhs, oarrm8n2_t*   rhs);
  oarrm8n2_t oarrm8n2_div_OR(oarrm8n2_t*   lhs, darr_t*    rhs);
  oarrm8n2_t oarrm8n2_div_RO(darr_t*    lhs, oarrm8n2_t*   rhs);
  oarrm8n2_t oarrm8n2_div_oO(onumm8n2_t* lhs, oarrm8n2_t*   rhs);
  oarrm8n2_t oarrm8n2_div_Oo(oarrm8n2_t*   lhs, onumm8n2_t* rhs);
  oarrm8n2_t oarrm8n2_div_rO(coeff_t    lhs, oarrm8n2_t*   rhs);
  oarrm8n2_t oarrm8n2_div_Or(oarrm8n2_t*   lhs, coeff_t    rhs);
  void oarrm8n2_div_OO_to(oarrm8n2_t*   lhs, oarrm8n2_t*   rhs, oarrm8n2_t* res);
  void oarrm8n2_div_RO_to(darr_t*    lhs, oarrm8n2_t*   rhs, oarrm8n2_t* res);
  void oarrm8n2_div_OR_to(oarrm8n2_t*   lhs, darr_t*    rhs, oarrm8n2_t* res);
  void oarrm8n2_div_oO_to(onumm8n2_t* lhs, oarrm8n2_t*   rhs, oarrm8n2_t* res);
  void oarrm8n2_div_Oo_to(oarrm8n2_t*   lhs, onumm8n2_t* rhs, oarrm8n2_t* res);
  void oarrm8n2_div_rO_to(coeff_t    lhs, oarrm8n2_t*   rhs, oarrm8n2_t* res);
  void oarrm8n2_div_Or_to(oarrm8n2_t*   lhs, coeff_t    rhs, oarrm8n2_t* res);
  
  
  # From ../../../include/oti/static/onumm8n2/array/base.h
  
  void    oarrm8n2_taylor_integrate_to( coeff_t* deltas, oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_taylor_integrate(    coeff_t* deltas, oarrm8n2_t* arr);
  void    oarrm8n2_get_order_im_to( ord_t order, oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_get_order_im(    ord_t order, oarrm8n2_t* arr);
  void oarrm8n2_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm8n2_t* res);
  void oarrm8n2_set_slice_O( oarrm8n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm8n2_t* res);
  void oarrm8n2_set_slice_o( onumm8n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_get_slice( oarrm8n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm8n2_get_slice_to( oarrm8n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_truncate_im(    imdir_t idx, ord_t order, oarrm8n2_t* arr);
  void    oarrm8n2_truncate_im_to( imdir_t idx, ord_t order, oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_extract_im(   imdir_t idx, ord_t order, oarrm8n2_t* arr);
  void    oarrm8n2_extract_im_to(imdir_t idx, ord_t order, oarrm8n2_t* arr, oarrm8n2_t* res);
  darr_t  oarrm8n2_get_deriv(    imdir_t idx, ord_t order, oarrm8n2_t* arr);
  void    oarrm8n2_get_deriv_to( imdir_t idx, ord_t order, oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_get_deriv_o(  imdir_t idx, ord_t order, oarrm8n2_t* arr);
  oarrm8n2_t oarrm8n2_extract_deriv(    imdir_t idx, ord_t order, oarrm8n2_t* arr);
  void    oarrm8n2_extract_deriv_to( imdir_t idx, ord_t order, oarrm8n2_t* arr, oarrm8n2_t* res);
  darr_t  oarrm8n2_get_im(   imdir_t idx, ord_t order, oarrm8n2_t* arr);
  oarrm8n2_t oarrm8n2_get_im_o( imdir_t idx, ord_t order, oarrm8n2_t* arr);
  void    oarrm8n2_get_im_to(imdir_t idx, ord_t order, oarrm8n2_t* arr, oarrm8n2_t* res);
  void    oarrm8n2_copy_to(oarrm8n2_t* arr, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_copy(oarrm8n2_t* arr);
  void oarrm8n2_set_all_r( coeff_t num, oarrm8n2_t* arr);
  void oarrm8n2_set_item_i_r( coeff_t num, uint64_t i, oarrm8n2_t* arr);
  void oarrm8n2_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm8n2_t* arr);
  void oarrm8n2_set_r(   coeff_t  num,   oarrm8n2_t* arr);
  void oarrm8n2_set_o( onumm8n2_t* num,   oarrm8n2_t* arr);
  void oarrm8n2_set_O(   oarrm8n2_t* arrin, oarrm8n2_t* arr);
  void oarrm8n2_set_all_o( onumm8n2_t* src, oarrm8n2_t* arr);
  void oarrm8n2_set_item_i_o( onumm8n2_t* num, uint64_t i, oarrm8n2_t* arr);
  void oarrm8n2_set_item_ij_o( onumm8n2_t* num, uint64_t i, uint64_t j, oarrm8n2_t* arr);
  onumm8n2_t oarrm8n2_get_item_i(    oarrm8n2_t* arr, uint64_t i);
  void      oarrm8n2_get_item_i_to( oarrm8n2_t* arr, uint64_t i,             onumm8n2_t* res);
  onumm8n2_t oarrm8n2_get_item_ij(   oarrm8n2_t* arr, uint64_t i, uint64_t j);
  void      oarrm8n2_get_item_ij_to(oarrm8n2_t* arr, uint64_t i, uint64_t j, onumm8n2_t* res);
  oarrm8n2_t oarrm8n2_init();
  void oarrm8n2_free(oarrm8n2_t* arr);
  oarrm8n2_t oarrm8n2_empty_like(oarrm8n2_t* arr);
  oarrm8n2_t oarrm8n2_eye(uint64_t nrows);
  oarrm8n2_t oarrm8n2_ones(uint64_t nrows, uint64_t ncols);
  oarrm8n2_t oarrm8n2_zeros(uint64_t nrows, uint64_t ncols);
  oarrm8n2_t oarrm8n2_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm8n2/array/utils.h
  
  void oarrm8n2_dimCheck_OO_elementwise(oarrm8n2_t* arr1, oarrm8n2_t* arr2, oarrm8n2_t* res);
  void oarrm8n2_dimCheck_RO_elementwise(darr_t*  arr1, oarrm8n2_t* arr2, oarrm8n2_t* res);
  void oarrm8n2_dimCheck_OO_matmul(oarrm8n2_t* arr1, oarrm8n2_t* arr2, oarrm8n2_t* res);
  void oarrm8n2_dimCheck_RO_matmul(darr_t*  arr1, oarrm8n2_t* arr2, oarrm8n2_t* res);
  void oarrm8n2_dimCheck_OR_matmul(oarrm8n2_t* arr1, darr_t*  arr2, oarrm8n2_t* res);
  void oarrm8n2_dimCheck_O_squareness(oarrm8n2_t* arr1, oarrm8n2_t* res);
  void oarrm8n2_dimCheck_OO_samesize(oarrm8n2_t* arr1, oarrm8n2_t* res);
  void oarrm8n2_dimCheck_RO_samesize(darr_t* arr1, oarrm8n2_t* res);
  ord_t oarrm8n2_get_order(oarrm8n2_t* arr);
  void oarrm8n2_get_active_bases(oarrm8n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm8n2/array/algebra_matops.h
  
  onumm8n2_t oarrm8n2_dotproduct_OO(    oarrm8n2_t* lhs, oarrm8n2_t* rhs);
  void      oarrm8n2_dotproduct_OO_to( oarrm8n2_t* lhs, oarrm8n2_t* rhs, onumm8n2_t* res);
  onumm8n2_t oarrm8n2_dotproduct_RO(     darr_t* lhs, oarrm8n2_t* rhs);
  void      oarrm8n2_dotproduct_RO_to(  darr_t* lhs, oarrm8n2_t* rhs, onumm8n2_t* res);
  oarrm8n2_t oarrm8n2_matmul_OO(    oarrm8n2_t* lhs, oarrm8n2_t* rhs);
  oarrm8n2_t oarrm8n2_matmul_OR(    oarrm8n2_t* lhs,  darr_t* rhs);
  oarrm8n2_t oarrm8n2_matmul_RO(     darr_t* lhs, oarrm8n2_t* rhs);
  void    oarrm8n2_matmul_OO_to( oarrm8n2_t* lhs, oarrm8n2_t* rhs, oarrm8n2_t* res);
  void    oarrm8n2_matmul_OR_to( oarrm8n2_t* lhs,  darr_t* rhs, oarrm8n2_t* res);
  void    oarrm8n2_matmul_RO_to(  darr_t* lhs, oarrm8n2_t* rhs, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_transpose(    oarrm8n2_t* arr1);
  void    oarrm8n2_transpose_to( oarrm8n2_t* arr1, oarrm8n2_t* res);
  oarrm8n2_t oarrm8n2_invert(    oarrm8n2_t* arr1);
  void    oarrm8n2_invert_to( oarrm8n2_t* arr1, oarrm8n2_t* res);
  onumm8n2_t oarrm8n2_det(    oarrm8n2_t* arr1);
  void      oarrm8n2_det_to( oarrm8n2_t* arr1, onumm8n2_t* res);
  onumm8n2_t oarrm8n2_norm(    oarrm8n2_t* arr1);
  void      oarrm8n2_norm_to( oarrm8n2_t* arr1,  onumm8n2_t* res);
  onumm8n2_t oarrm8n2_pnorm(    oarrm8n2_t* arr1, coeff_t p);
  void      oarrm8n2_pnorm_to( oarrm8n2_t* arr1, coeff_t p, onumm8n2_t* res);
  
  
  # From ../../../include/oti/static/onumm8n2/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm8n2/array/gauss/functions.h
  
  feoarrm8n2_t feoarrm8n2_atanh(    feoarrm8n2_t* arr);
  void      feoarrm8n2_atanh_to( feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_asinh(    feoarrm8n2_t* arr);
  void      feoarrm8n2_asinh_to( feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_acosh(    feoarrm8n2_t* arr);
  void      feoarrm8n2_acosh_to( feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_tanh(     feoarrm8n2_t* arr);
  void      feoarrm8n2_tanh_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sinh(     feoarrm8n2_t* arr);
  void      feoarrm8n2_sinh_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_cosh(     feoarrm8n2_t* arr);
  void      feoarrm8n2_cosh_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_atan(     feoarrm8n2_t* arr);
  void      feoarrm8n2_atan_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_asin(     feoarrm8n2_t* arr);
  void      feoarrm8n2_asin_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_acos(     feoarrm8n2_t* arr);
  void      feoarrm8n2_acos_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_tan(      feoarrm8n2_t* arr);
  void      feoarrm8n2_tan_to(   feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sin(      feoarrm8n2_t* arr);
  void      feoarrm8n2_sin_to(   feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_cos(      feoarrm8n2_t* arr);
  void      feoarrm8n2_cos_to(   feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_logb(     feoarrm8n2_t* arr, double base);
  void      feoarrm8n2_logb_to(  feoarrm8n2_t* arr, double base, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_log10(    feoarrm8n2_t* arr);
  void      feoarrm8n2_log10_to( feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_log(      feoarrm8n2_t* arr);
  void      feoarrm8n2_log_to(   feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_exp(      feoarrm8n2_t* arr);
  void      feoarrm8n2_exp_to(   feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_cbrt(     feoarrm8n2_t* arr);
  void      feoarrm8n2_cbrt_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sqrt(     feoarrm8n2_t* arr);
  void      feoarrm8n2_sqrt_to(  feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_pow(      feoarrm8n2_t* arr, double e);
  void      feoarrm8n2_pow_to(   feoarrm8n2_t* arr, double e, feoarrm8n2_t* res);
  
  
  # From ../../../include/oti/static/onumm8n2/array/gauss/base.h
  
  void      feoarrm8n2_get_order_im_to( ord_t order, feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_get_order_im(    ord_t order, feoarrm8n2_t* arr);
  feoarrm8n2_t feoarrm8n2_get_deriv(   imdir_t idx, ord_t order, feoarrm8n2_t* arr);
  void      feoarrm8n2_get_deriv_to(imdir_t idx, ord_t order, feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_get_im(      imdir_t idx, ord_t order, feoarrm8n2_t* arr);
  void      feoarrm8n2_get_im_to(   imdir_t idx, ord_t order, feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_truncate_im(   imdir_t idx, ord_t order, feoarrm8n2_t* arr);
  void      feoarrm8n2_truncate_im_to(imdir_t idx, ord_t order, feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_copy(   feoarrm8n2_t* src);
  void      feoarrm8n2_copy_to(feoarrm8n2_t* src, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_get_im(    imdir_t idx, ord_t order, feoarrm8n2_t* arr);
  void      feoarrm8n2_get_im_to( imdir_t idx, ord_t order, feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_get_deriv(    imdir_t idx, ord_t order, feoarrm8n2_t* arr);
  void      feoarrm8n2_get_deriv_to( imdir_t idx, ord_t order, feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_extract_im(    imdir_t idx, ord_t order, feoarrm8n2_t* arr);
  void      feoarrm8n2_extract_im_to( imdir_t idx, ord_t order, feoarrm8n2_t* arr,  feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_extract_deriv(    imdir_t idx, ord_t order, feoarrm8n2_t* arr);
  void      feoarrm8n2_extract_deriv_to( imdir_t idx, ord_t order, feoarrm8n2_t* arr, feoarrm8n2_t* res);
  oarrm8n2_t   feoarrm8n2_get_item_k(  feoarrm8n2_t* arr, uint64_t k);
  feonumm8n2_t  feoarrm8n2_get_item_ij( feoarrm8n2_t* arr, uint64_t i, uint64_t j);
  onumm8n2_t feoarrm8n2_get_item_ijk(feoarrm8n2_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm8n2_get_item_ij_to(  feoarrm8n2_t* arr, uint64_t i, uint64_t j,
                                 feonumm8n2_t* res);
  void feoarrm8n2_get_item_k_to(   feoarrm8n2_t* arr, uint64_t k,
                                  oarrm8n2_t* res);
  void feoarrm8n2_get_item_ijk_to( feoarrm8n2_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_get_slice(feoarrm8n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm8n2_get_slice_to(feoarrm8n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n2_t* res);
  void feoarrm8n2_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm8n2_t* res);
  void feoarrm8n2_set_item_ij_o(  onumm8n2_t* elm, uint64_t i, uint64_t j,
                               feoarrm8n2_t* res);
  void feoarrm8n2_set_item_ij_f(  feonumm8n2_t* elm, uint64_t i, uint64_t j,
                              feoarrm8n2_t* res);
  void feoarrm8n2_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm8n2_t* res);
  void feoarrm8n2_set_item_k_o(  onumm8n2_t* elm, uint64_t k,
                              feoarrm8n2_t* res);
  void feoarrm8n2_set_item_k_R(    oarrm8n2_t* elm, uint64_t k,
                            feoarrm8n2_t* res);
  void feoarrm8n2_set_item_k_O(    oarrm8n2_t* elm, uint64_t k,
                            feoarrm8n2_t* res);
  void feoarrm8n2_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm8n2_t* res);
  void feoarrm8n2_set_item_ijk_o( onumm8n2_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm8n2_t* res);
  void feoarrm8n2_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n2_t* res);
  void feoarrm8n2_set_slice_o( onumm8n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n2_t* res);
  void feoarrm8n2_set_slice_f( feonumm8n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n2_t* res);
  void feoarrm8n2_set_slice_O( oarrm8n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n2_t* res);
  void feoarrm8n2_set_slice_F( feoarrm8n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n2_t* res);
  void feoarrm8n2_set_all_o( onumm8n2_t* num, feoarrm8n2_t* arr );
  void feoarrm8n2_set_all_r(   coeff_t  num, feoarrm8n2_t* arr );
  void feoarrm8n2_set_all_f(  feonumm8n2_t* num, feoarrm8n2_t* arr );
  void feoarrm8n2_set_r(    coeff_t src, feoarrm8n2_t* res );
  void feoarrm8n2_set_o( onumm8n2_t* src, feoarrm8n2_t* res );
  void feoarrm8n2_set_f(  feonumm8n2_t* src, feoarrm8n2_t* res );
  void feoarrm8n2_set_R(    darr_t* src, feoarrm8n2_t* res );
  void feoarrm8n2_set_O(   oarrm8n2_t* src, feoarrm8n2_t* res );
  void feoarrm8n2_set_F( feoarrm8n2_t* src, feoarrm8n2_t* res );
  feoarrm8n2_t feoarrm8n2_eye( uint64_t size,  uint64_t nip);
  feoarrm8n2_t feoarrm8n2_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm8n2_t feoarrm8n2_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm8n2_t feoarrm8n2_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm8n2_free(feoarrm8n2_t* arr);
  feoarrm8n2_t feoarrm8n2_init();
  ord_t feoarrm8n2_get_order(feoarrm8n2_t* arr);
  
  
  # From ../../../include/oti/static/onumm8n2/array/gauss/utils.h
  
  void feoarrm8n2_dimCheck_FF_samesize(feoarrm8n2_t* arr1, feoarrm8n2_t* arr2, feonumm8n2_t* res);
  void feoarrm8n2_dimCheck_OF_samesize(  oarrm8n2_t* arr1, feoarrm8n2_t* arr2, feonumm8n2_t* res);
  void feoarrm8n2_dimCheck_RF_samesize(   darr_t* arr1, feoarrm8n2_t* arr2, feonumm8n2_t* res);
  void feoarrm8n2_dimCheck_FF_elementwise(feoarrm8n2_t* arr1, feoarrm8n2_t* arr2, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_OF_elementwise(  oarrm8n2_t* arr1, feoarrm8n2_t* arr2, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm8n2_t* arr2, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_fF_elementwise( feonumm8n2_t* num1, feoarrm8n2_t* arr2, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_Ff_elementwise(feoarrm8n2_t* arr1,  feonumm8n2_t* num2, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_FF_matmul( feoarrm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_OF_matmul(   oarrm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_FO_matmul( feoarrm8n2_t* lhs,   oarrm8n2_t* rhs, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_FR_matmul( feoarrm8n2_t* lhs,    darr_t* rhs, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_F_squareness( feoarrm8n2_t* arr1, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_F_transpose( feoarrm8n2_t* arr1, feoarrm8n2_t* res);
  void feoarrm8n2_dimCheck_FfO_integrate(feoarrm8n2_t* arr, feonumm8n2_t* num,oarrm8n2_t* res);
  void feoarrm8n2_get_active_bases(feoarrm8n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm8n2/array/gauss/algebra.h
  
  feoarrm8n2_t feoarrm8n2_neg(    feoarrm8n2_t* arr);
  void      feoarrm8n2_neg_to( feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sum_FF(   feoarrm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sum_FF_to(feoarrm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sum_fF(    feonumm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sum_fF_to( feonumm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sum_OF(     oarrm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sum_OF_to(  oarrm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sum_RF(      darr_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sum_RF_to(   darr_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sum_oF(   onumm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sum_oF_to(onumm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sum_rF(     coeff_t  lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sum_rF_to(  coeff_t  lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sub_FF(    feoarrm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sub_FF_to( feoarrm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sub_fF(    feonumm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sub_fF_to( feonumm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sub_Ff(    feoarrm8n2_t* lhs, feonumm8n2_t* rhs);
  void      feoarrm8n2_sub_Ff_to( feoarrm8n2_t* lhs, feonumm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sub_OF(      oarrm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sub_OF_to(   oarrm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sub_FO(    feoarrm8n2_t* lhs,   oarrm8n2_t* rhs);
  void      feoarrm8n2_sub_FO_to( feoarrm8n2_t* lhs,   oarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sub_RF(       darr_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sub_RF_to(    darr_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sub_FR(    feoarrm8n2_t* lhs,    darr_t* rhs);
  void      feoarrm8n2_sub_FR_to( feoarrm8n2_t* lhs,    darr_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sub_oF(    onumm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sub_oF_to( onumm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sub_Fo(    feoarrm8n2_t* lhs, onumm8n2_t* rhs);
  void      feoarrm8n2_sub_Fo_to( feoarrm8n2_t* lhs, onumm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sub_rF(      coeff_t  lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_sub_rF_to(    coeff_t lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_sub_Fr(    feoarrm8n2_t* lhs,   coeff_t  rhs);
  void      feoarrm8n2_sub_Fr_to( feoarrm8n2_t* lhs,   coeff_t  rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_mul_FF(   feoarrm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_mul_FF_to(feoarrm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_mul_fF(    feonumm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_mul_fF_to( feonumm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_mul_OF(     oarrm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_mul_OF_to(  oarrm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_mul_RF(      darr_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_mul_RF_to(   darr_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_mul_oF(   onumm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_mul_oF_to(onumm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_mul_rF(     coeff_t  lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_mul_rF_to(  coeff_t  lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_div_FF(    feoarrm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_div_FF_to( feoarrm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_div_fF(     feonumm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_div_fF_to(  feonumm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_div_Ff(    feoarrm8n2_t* lhs,  feonumm8n2_t* rhs);
  void      feoarrm8n2_div_Ff_to( feoarrm8n2_t* lhs,  feonumm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_div_OF(      oarrm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_div_OF_to(   oarrm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_div_FO(    feoarrm8n2_t* lhs,   oarrm8n2_t* rhs);
  void      feoarrm8n2_div_FO_to( feoarrm8n2_t* lhs,   oarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_div_RF(       darr_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_div_RF_to(    darr_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_div_FR(    feoarrm8n2_t* lhs,    darr_t* rhs);
  void      feoarrm8n2_div_FR_to( feoarrm8n2_t* lhs,    darr_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_div_oF(    onumm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_div_oF_to( onumm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_div_Fo(    feoarrm8n2_t* lhs, onumm8n2_t* rhs);
  void      feoarrm8n2_div_Fo_to( feoarrm8n2_t* lhs, onumm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_div_rF(      coeff_t  lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_div_rF_to(    coeff_t lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_div_Fr(    feoarrm8n2_t* lhs,   coeff_t  rhs);
  void      feoarrm8n2_div_Fr_to( feoarrm8n2_t* lhs,   coeff_t  rhs, feoarrm8n2_t* res);
  oarrm8n2_t feoarrm8n2_integrate(    feoarrm8n2_t* arr, feonumm8n2_t* w);
  void    feoarrm8n2_integrate_to( feoarrm8n2_t* arr, feonumm8n2_t* w, oarrm8n2_t* res);
  feonumm8n2_t feoarrm8n2_dotproduct_FF(    feoarrm8n2_t* lhs, feoarrm8n2_t* rhs);
  void     feoarrm8n2_dotproduct_FF_to( feoarrm8n2_t* lhs, feoarrm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feoarrm8n2_dotproduct_OF(      oarrm8n2_t* lhs, feoarrm8n2_t* rhs);
  void     feoarrm8n2_dotproduct_OF_to(   oarrm8n2_t* lhs, feoarrm8n2_t* rhs, feonumm8n2_t* res);
  feonumm8n2_t feoarrm8n2_dotproduct_RF(       darr_t* lhs, feoarrm8n2_t* rhs);
  void     feoarrm8n2_dotproduct_RF_to(    darr_t* lhs, feoarrm8n2_t* rhs, feonumm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_matmul_FF(    feoarrm8n2_t* lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_matmul_FF_to( feoarrm8n2_t* lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_matmul_OF(    oarrm8n2_t*   lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_matmul_OF_to( oarrm8n2_t*   lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_matmul_FO(    feoarrm8n2_t* lhs, oarrm8n2_t*   rhs);
  void      feoarrm8n2_matmul_FO_to( feoarrm8n2_t* lhs, oarrm8n2_t*   rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_matmul_RF(    darr_t*    lhs, feoarrm8n2_t* rhs);
  void      feoarrm8n2_matmul_RF_to( darr_t*    lhs, feoarrm8n2_t* rhs, feoarrm8n2_t* res);
  feoarrm8n2_t feoarrm8n2_matmul_FR(    feoarrm8n2_t* lhs, darr_t*    rhs);
  void      feoarrm8n2_matmul_FR_to( feoarrm8n2_t* lhs, darr_t*    rhs, feoarrm8n2_t* res);
  feonumm8n2_t feoarrm8n2_det(   feoarrm8n2_t* arr);
  void     feoarrm8n2_det_to(feoarrm8n2_t* arr, feonumm8n2_t* res);
  feonumm8n2_t feoarrm8n2_norm(     feoarrm8n2_t* arr);
  void     feoarrm8n2_norm_to(  feoarrm8n2_t* arr, feonumm8n2_t* res);
  feonumm8n2_t feoarrm8n2_pnorm(    feoarrm8n2_t* arr, coeff_t p);
  void     feoarrm8n2_pnorm_to( feoarrm8n2_t* arr, coeff_t p, feonumm8n2_t* res);
  feoarrm8n2_t   feoarrm8n2_invert(    feoarrm8n2_t* arr);
  void        feoarrm8n2_invert_to( feoarrm8n2_t* arr, feoarrm8n2_t* res);
  feoarrm8n2_t   feoarrm8n2_transpose(   feoarrm8n2_t* arr);
  void        feoarrm8n2_transpose_to(feoarrm8n2_t* arr, feoarrm8n2_t* res);
  
  