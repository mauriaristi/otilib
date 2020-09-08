cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm6n2/scalar/structures.h
  
  ctypedef struct  onumm6n2_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
    coeff_t e6;
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
  # } onumm6n2_t;
  
  
  # From ../../../include/oti/static/onumm6n2/array/structures.h
  
  ctypedef struct  oarrm6n2_t : # {
      onumm6n2_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm6n2_t;
  
  
  # From ../../../include/oti/static/onumm6n2/scalar/gauss/structures.h
  
  ctypedef struct  feonumm6n2_t: # {
      onumm6n2_t*  p_data;
      uint64_t    nip;
  # } feonumm6n2_t;
  
  
  # From ../../../include/oti/static/onumm6n2/array/gauss/structures.h
  
  ctypedef struct  feoarrm6n2_t: # {
      oarrm6n2_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm6n2_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm6n2/scalar/functions.h
  
  onumm6n2_t onumm6n2_atanh(onumm6n2_t* num);
  void onumm6n2_atanh_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_asinh(onumm6n2_t* num);
  void onumm6n2_asinh_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_acosh(onumm6n2_t* num);
  void onumm6n2_acosh_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_tanh(onumm6n2_t* num);
  void onumm6n2_tanh_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_sqrt(onumm6n2_t* num);
  void onumm6n2_sqrt_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_cbrt(onumm6n2_t* num);
  void onumm6n2_cbrt_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_cosh(onumm6n2_t* num);
  void onumm6n2_cosh_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_sinh(onumm6n2_t* num);
  void onumm6n2_sinh_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_asin(onumm6n2_t* num);
  void onumm6n2_asin_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_acos(onumm6n2_t* num);
  void onumm6n2_acos_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_atan(onumm6n2_t* num);
  void onumm6n2_atan_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_tan(onumm6n2_t* num);
  void onumm6n2_tan_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_cos(onumm6n2_t* num);
  void onumm6n2_cos_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_sin(onumm6n2_t* num );
  void onumm6n2_sin_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_logb(onumm6n2_t* num, double base);
  void onumm6n2_logb_to(onumm6n2_t* num, double base, onumm6n2_t* res);
  onumm6n2_t onumm6n2_log10(onumm6n2_t* num);
  void onumm6n2_log10_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_log(onumm6n2_t* num);
  void onumm6n2_log_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_exp(onumm6n2_t* num);
  void onumm6n2_exp_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_pow(onumm6n2_t* num, double e);
  void onumm6n2_pow_to(onumm6n2_t* num, coeff_t e, onumm6n2_t* res);
  
  
  # From ../../../include/oti/static/onumm6n2/scalar/base.h
  
  void onumm6n2_set_im_o(onumm6n2_t* num, imdir_t idx, ord_t order, onumm6n2_t* res);
  void onumm6n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm6n2_t* res);
  void onumm6n2_set_deriv_o(onumm6n2_t* num, imdir_t idx, ord_t order, onumm6n2_t* res);
  void onumm6n2_extract_im_to( imdir_t idx, ord_t order, onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_extract_im(imdir_t idx, ord_t order, onumm6n2_t* num);
  onumm6n2_t onumm6n2_extract_deriv(imdir_t idx, ord_t order, onumm6n2_t* num);
  void onumm6n2_extract_deriv_to(imdir_t idx, ord_t order, onumm6n2_t* num, onumm6n2_t* res);
  void onumm6n2_get_im_to_o(imdir_t idx, ord_t order, onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_get_im_o(imdir_t idx, ord_t order, onumm6n2_t* num);
  void onumm6n2_get_im_to_r(imdir_t idx, ord_t order, onumm6n2_t* num, coeff_t* res);
  ord_t onumm6n2_get_order(onumm6n2_t* lhs);
  onumm6n2_t onumm6n2_get_deriv_o( imdir_t idx, ord_t order, onumm6n2_t* num);
  void onumm6n2_get_deriv_to( imdir_t idx, ord_t order, onumm6n2_t* num, onumm6n2_t* res);
  void onumm6n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm6n2_t* res);
  onumm6n2_t onumm6n2_init();
  ndir_t onumm6n2_get_ndir_order(ord_t order, onumm6n2_t* num);
  ndir_t onumm6n2_get_ndir_total(onumm6n2_t* num);
  coeff_t* onumm6n2_get_order_address(ord_t order, onumm6n2_t* num);
  onumm6n2_t onumm6n2_create_r(  coeff_t lhs);
  void onumm6n2_set_r(  coeff_t lhs, onumm6n2_t* res);
  void onumm6n2_set_o(  onumm6n2_t* lhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_get_order_im(ord_t order, onumm6n2_t* lhs);
  void onumm6n2_get_order_im_to(ord_t order, onumm6n2_t* lhs, onumm6n2_t* res);
  coeff_t onumm6n2_get_item(imdir_t idx, ord_t order, onumm6n2_t* lhs);
  coeff_t onumm6n2_get_deriv(imdir_t idx, ord_t order, onumm6n2_t* lhs);
  void onumm6n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm6n2_t* x);
  onumm6n2_t onumm6n2_copy(  onumm6n2_t* lhs);
  void onumm6n2_copy_to(  onumm6n2_t* lhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_taylor_integrate(coeff_t* deltas,onumm6n2_t* lhs);
  void onumm6n2_taylor_integrate_to(coeff_t* deltas,onumm6n2_t* lhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_truncate_im(imdir_t idx, ord_t order, onumm6n2_t* lhs);
  void onumm6n2_truncate_im_to(imdir_t idx, ord_t order, onumm6n2_t* lhs, onumm6n2_t* res);
  void onumm6n2_print(  onumm6n2_t* lhs);
  imdir_t onumm6n2_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm6n2/scalar/utils.h
  
  void onumm6n2_get_active_bases(onumm6n2_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm6n2/scalar/algebra.h
  
  onumm6n2_t onumm6n2_abs(onumm6n2_t* num);
  onumm6n2_t onumm6n2_div_ro(coeff_t num, onumm6n2_t* den);
  onumm6n2_t onumm6n2_div_oo(onumm6n2_t* num, onumm6n2_t* den);
  onumm6n2_t onumm6n2_div_or(onumm6n2_t* num, coeff_t val);
  void onumm6n2_div_ro_to(coeff_t num, onumm6n2_t* den, onumm6n2_t* res);
  void onumm6n2_div_oo_to(onumm6n2_t* num, onumm6n2_t* den, onumm6n2_t* res);
  void onumm6n2_div_or_to(onumm6n2_t* num, coeff_t val, onumm6n2_t* res);
  void onumm6n2_abs_to(onumm6n2_t* num, onumm6n2_t* res);
  onumm6n2_t onumm6n2_neg(  onumm6n2_t* lhs);
  void onumm6n2_neg_to(  onumm6n2_t* lhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_sum_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs);
  void onumm6n2_sum_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_sum_ro(  coeff_t lhs,  onumm6n2_t* rhs);
  void onumm6n2_sum_ro_to(  coeff_t lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_sub_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs);
  void onumm6n2_sub_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_sub_ro(  coeff_t lhs,  onumm6n2_t* rhs);
  void onumm6n2_sub_ro_to(  coeff_t lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_sub_or(  onumm6n2_t* lhs,  coeff_t rhs);
  void onumm6n2_sub_or_to(  onumm6n2_t* lhs,  coeff_t rhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_mul_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs);
  void onumm6n2_mul_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_mul_ro(  coeff_t lhs,  onumm6n2_t* rhs);
  void onumm6n2_mul_ro_to(  coeff_t lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_trunc_mul_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs);
  void onumm6n2_trunc_mul_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
  onumm6n2_t onumm6n2_gem_oo(  onumm6n2_t* a,  onumm6n2_t* b,  onumm6n2_t* c);
  void onumm6n2_gem_oo_to(  onumm6n2_t* a,  onumm6n2_t* b,  onumm6n2_t* c, onumm6n2_t* res);
  onumm6n2_t onumm6n2_gem_ro(  coeff_t a,  onumm6n2_t* b,  onumm6n2_t* c);
  void onumm6n2_gem_ro_to(  coeff_t a,  onumm6n2_t* b,  onumm6n2_t* c, onumm6n2_t* res);
  void onumm6n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm6n2_t* a,  ord_t ord_rhs,  onumm6n2_t* b,  onumm6n2_t* c, onumm6n2_t* res);
  onumm6n2_t onumm6n2_feval(coeff_t* feval_re, onumm6n2_t* x);
  void onumm6n2_feval_to(coeff_t* feval_re, onumm6n2_t* x, onumm6n2_t* res);
  
  
  # From ../../../include/oti/static/onumm6n2/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm6n2/scalar/gauss/functions.h
  
  feonumm6n2_t feonumm6n2_atanh(    feonumm6n2_t* num);
  void     feonumm6n2_atanh_to( feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_asinh(    feonumm6n2_t* num);
  void     feonumm6n2_asinh_to( feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_acosh(    feonumm6n2_t* num);
  void     feonumm6n2_acosh_to( feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_tanh(     feonumm6n2_t* num);
  void     feonumm6n2_tanh_to(  feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_cosh(     feonumm6n2_t* num);
  void     feonumm6n2_cosh_to(  feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_sinh(     feonumm6n2_t* num);
  void     feonumm6n2_sinh_to(  feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_asin(     feonumm6n2_t* num);
  void     feonumm6n2_asin_to(  feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_acos(     feonumm6n2_t* num);
  void     feonumm6n2_acos_to(  feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_atan(     feonumm6n2_t* num);
  void     feonumm6n2_atan_to(  feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_tan(      feonumm6n2_t* num);
  void     feonumm6n2_tan_to(   feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_cos(      feonumm6n2_t* num);
  void     feonumm6n2_cos_to(   feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_sin(      feonumm6n2_t* num);
  void     feonumm6n2_sin_to(   feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_logb(     feonumm6n2_t* num, double base);
  void     feonumm6n2_logb_to(  feonumm6n2_t* num, double base, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_log10(    feonumm6n2_t* num);
  void     feonumm6n2_log10_to( feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_log(      feonumm6n2_t* num);
  void     feonumm6n2_log_to(   feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_exp(      feonumm6n2_t* num);
  void     feonumm6n2_exp_to(   feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_cbrt(     feonumm6n2_t* num);
  void     feonumm6n2_cbrt_to(  feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_sqrt(     feonumm6n2_t* num);
  void     feonumm6n2_sqrt_to(  feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_pow(      feonumm6n2_t* num, double e);
  void     feonumm6n2_pow_to(   feonumm6n2_t* num, double e, feonumm6n2_t* res);
  onumm6n2_t feonumm6n2_integrate(       feonumm6n2_t* num, feonumm6n2_t* w);
  void      feonumm6n2_integrate_to(    feonumm6n2_t* num, feonumm6n2_t* w, onumm6n2_t* res);
  onumm6n2_t feonumm6n2_integrate_f(     feonumm6n2_t* num, feonumm6n2_t* w);
  void      feonumm6n2_integrate_f_to(  feonumm6n2_t* num, feonumm6n2_t* w, onumm6n2_t* res);
  onumm6n2_t feonumm6n2_integrate_r(       coeff_t num, feonumm6n2_t* w);
  void      feonumm6n2_integrate_r_to(    coeff_t num, feonumm6n2_t* w, onumm6n2_t* res);
  onumm6n2_t feonumm6n2_integrate_o(    onumm6n2_t* num, feonumm6n2_t* w);
  void      feonumm6n2_integrate_o_to( onumm6n2_t* num, feonumm6n2_t* w, onumm6n2_t* res);
  
  
  # From ../../../include/oti/static/onumm6n2/scalar/gauss/base.h
  
  void     feonumm6n2_get_order_im_to( ord_t order, feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_get_order_im(    ord_t order, feonumm6n2_t* num);
  feonumm6n2_t feonumm6n2_get_im(    imdir_t idx, ord_t order, feonumm6n2_t* num);
  void     feonumm6n2_get_im_to( imdir_t idx, ord_t order, feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_get_deriv(    imdir_t idx, ord_t order, feonumm6n2_t* num);
  void     feonumm6n2_get_deriv_to( imdir_t idx, ord_t order, feonumm6n2_t* num, feonumm6n2_t* res);
  void feonumm6n2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm6n2_t* num);
  void feonumm6n2_set_im_o( onumm6n2_t* val, imdir_t idx, ord_t order, feonumm6n2_t* num);
  void feonumm6n2_set_im_f(  feonumm6n2_t* val, imdir_t idx, ord_t order, feonumm6n2_t* num);
  void feonumm6n2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm6n2_t* num);
  void feonumm6n2_set_deriv_o( onumm6n2_t* val, imdir_t idx, ord_t order, feonumm6n2_t* num);
  void feonumm6n2_set_deriv_f(  feonumm6n2_t* val, imdir_t idx, ord_t order, feonumm6n2_t* num);
  feonumm6n2_t feonumm6n2_extract_im(    imdir_t idx, ord_t order, feonumm6n2_t* num);
  void     feonumm6n2_extract_im_to( imdir_t idx, ord_t order, feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_extract_deriv(    imdir_t idx, ord_t order, feonumm6n2_t* num);
  void     feonumm6n2_extract_deriv_to( imdir_t idx, ord_t order, feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_truncate_im(    imdir_t idx, ord_t order, feonumm6n2_t* num);
  void     feonumm6n2_truncate_im_to( imdir_t idx, ord_t order, feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_copy(    feonumm6n2_t* src);
  void     feonumm6n2_copy_to( feonumm6n2_t* src, feonumm6n2_t* dst);
  void feonumm6n2_set_r(    coeff_t num, feonumm6n2_t* res);
  void feonumm6n2_set_o( onumm6n2_t* num, feonumm6n2_t* res);
  void feonumm6n2_set_f(  feonumm6n2_t* num, feonumm6n2_t* res);
  void feonumm6n2_set_item_k_r(   coeff_t  num, uint64_t k, feonumm6n2_t* res);
  void feonumm6n2_set_item_k_o( onumm6n2_t* num, uint64_t k, feonumm6n2_t* res);
  onumm6n2_t feonumm6n2_get_item_k(   feonumm6n2_t* num, uint64_t k);
  void      feonumm6n2_get_item_k_to(feonumm6n2_t* num, uint64_t k, onumm6n2_t* res);
  feonumm6n2_t feonumm6n2_zeros(uint64_t nIntPts);
  feonumm6n2_t feonumm6n2_createEmpty(uint64_t nIntPts);
  feonumm6n2_t feonumm6n2_empty_like(feonumm6n2_t* arr);
  void feonumm6n2_free(feonumm6n2_t* num);
  ord_t feonumm6n2_get_order( feonumm6n2_t* num );
  feonumm6n2_t feonumm6n2_init();
  
  
  # From ../../../include/oti/static/onumm6n2/scalar/gauss/utils.h
  
  void feonumm6n2_dimCheck(feonumm6n2_t* arr1,feonumm6n2_t* arr2);
  void feonumm6n2_get_active_bases(feonumm6n2_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm6n2/scalar/gauss/algebra.h
  
  feonumm6n2_t feonumm6n2_neg(   feonumm6n2_t* num);
  void     feonumm6n2_neg_to(feonumm6n2_t* num, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_sum_ff(   feonumm6n2_t* lhs, feonumm6n2_t* rhs);
  void     feonumm6n2_sum_ff_to(feonumm6n2_t* lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_sum_of(   onumm6n2_t* lhs, feonumm6n2_t* rhs);
  void     feonumm6n2_sum_of_to(onumm6n2_t* lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_sum_rf(   coeff_t lhs, feonumm6n2_t* rhs);
  void     feonumm6n2_sum_rf_to(coeff_t lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_sub_ff(     feonumm6n2_t* lhs,  feonumm6n2_t* rhs);
  void     feonumm6n2_sub_ff_to(  feonumm6n2_t* lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_sub_of(    onumm6n2_t* lhs,  feonumm6n2_t* rhs);
  void     feonumm6n2_sub_of_to( onumm6n2_t* lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_sub_fo(     feonumm6n2_t* lhs, onumm6n2_t* rhs);
  void     feonumm6n2_sub_fo_to(  feonumm6n2_t* lhs, onumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_sub_rf(       coeff_t lhs,  feonumm6n2_t* rhs);
  void     feonumm6n2_sub_rf_to(    coeff_t lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_sub_fr(     feonumm6n2_t* lhs,    coeff_t rhs);
  void     feonumm6n2_sub_fr_to(  feonumm6n2_t* lhs,    coeff_t rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_mul_ff(   feonumm6n2_t* lhs, feonumm6n2_t* rhs);
  void     feonumm6n2_mul_ff_to(feonumm6n2_t* lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_mul_of(   onumm6n2_t* lhs, feonumm6n2_t* rhs);
  void     feonumm6n2_mul_of_to(onumm6n2_t* lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_mul_rf(   coeff_t lhs, feonumm6n2_t* rhs);
  void     feonumm6n2_mul_rf_to(coeff_t lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_div_ff(     feonumm6n2_t* lhs,  feonumm6n2_t* rhs);
  void     feonumm6n2_div_ff_to(  feonumm6n2_t* lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_div_of(    onumm6n2_t* lhs,  feonumm6n2_t* rhs);
  void     feonumm6n2_div_of_to( onumm6n2_t* lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_div_fo(     feonumm6n2_t* lhs, onumm6n2_t* rhs);
  void     feonumm6n2_div_fo_to(  feonumm6n2_t* lhs, onumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_div_rf(       coeff_t lhs,  feonumm6n2_t* rhs);
  void     feonumm6n2_div_rf_to(    coeff_t lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feonumm6n2_div_fr(     feonumm6n2_t* lhs,    coeff_t rhs);
  void     feonumm6n2_div_fr_to(  feonumm6n2_t* lhs,    coeff_t rhs, feonumm6n2_t* res);
  
  
  # From ../../../include/oti/static/onumm6n2/array/functions.h
  
  oarrm6n2_t oarrm6n2_atanh(   oarrm6n2_t* arr);
  void    oarrm6n2_atanh_to(oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_asinh(   oarrm6n2_t* arr);
  void    oarrm6n2_asinh_to(oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_acosh(   oarrm6n2_t* arr);
  void    oarrm6n2_acosh_to(oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_tanh(    oarrm6n2_t* arr);
  void    oarrm6n2_tanh_to( oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_cbrt(    oarrm6n2_t* arr);
  void    oarrm6n2_cbrt_to( oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_sqrt(    oarrm6n2_t* arr);
  void    oarrm6n2_sqrt_to( oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_cosh(    oarrm6n2_t* arr);
  void    oarrm6n2_cosh_to( oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_sinh(    oarrm6n2_t* arr);
  void    oarrm6n2_sinh_to( oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_asin(    oarrm6n2_t* arr);
  void    oarrm6n2_asin_to( oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_acos(    oarrm6n2_t* arr);
  void    oarrm6n2_acos_to( oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_atan(    oarrm6n2_t* arr);
  void    oarrm6n2_atan_to( oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_tan(     oarrm6n2_t* arr);
  void    oarrm6n2_tan_to(  oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_cos(     oarrm6n2_t* arr);
  void    oarrm6n2_cos_to(  oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_sin(     oarrm6n2_t* arr);
  void    oarrm6n2_sin_to(  oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_logb(    oarrm6n2_t* arr, double base);
  void    oarrm6n2_logb_to( oarrm6n2_t* arr, double base, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_log10(   oarrm6n2_t* arr);
  void    oarrm6n2_log10_to(oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_log(     oarrm6n2_t* arr);
  void    oarrm6n2_log_to(  oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_exp(     oarrm6n2_t* arr);
  void    oarrm6n2_exp_to(  oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_pow(     oarrm6n2_t* arr, double e);
  void    oarrm6n2_pow_to(  oarrm6n2_t* arr, double e, oarrm6n2_t* res);
  
  
  # From ../../../include/oti/static/onumm6n2/array/algebra_elementwise.h
  
  oarrm6n2_t oarrm6n2_neg(oarrm6n2_t* arr);
  void oarrm6n2_neg_to(oarrm6n2_t* rhs, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_sum_OO(oarrm6n2_t*   lhs, oarrm6n2_t* rhs);
  oarrm6n2_t oarrm6n2_sum_RO(darr_t*    lhs, oarrm6n2_t* rhs);
  oarrm6n2_t oarrm6n2_sum_oO(onumm6n2_t* lhs, oarrm6n2_t* rhs);
  oarrm6n2_t oarrm6n2_sum_rO(coeff_t    lhs, oarrm6n2_t* rhs);
  void oarrm6n2_sum_OO_to(oarrm6n2_t*   lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
  void oarrm6n2_sum_RO_to(darr_t*    lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
  void oarrm6n2_sum_oO_to(onumm6n2_t* lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
  void oarrm6n2_sum_rO_to(coeff_t    lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_sub_OO(oarrm6n2_t*   lhs, oarrm6n2_t*   rhs);
  oarrm6n2_t oarrm6n2_sub_RO(darr_t*    lhs, oarrm6n2_t*   rhs);
  oarrm6n2_t oarrm6n2_sub_OR(oarrm6n2_t*   lhs, darr_t*    rhs);
  oarrm6n2_t oarrm6n2_sub_oO(onumm6n2_t* lhs, oarrm6n2_t*   rhs);
  oarrm6n2_t oarrm6n2_sub_Oo(oarrm6n2_t*   lhs, onumm6n2_t* rhs);
  oarrm6n2_t oarrm6n2_sub_rO(coeff_t    lhs, oarrm6n2_t*   rhs);
  oarrm6n2_t oarrm6n2_sub_Or(oarrm6n2_t*   lhs, coeff_t    rhs);
  void oarrm6n2_sub_OO_to( oarrm6n2_t*   lhs, oarrm6n2_t*   rhs, oarrm6n2_t* res);
  void oarrm6n2_sub_RO_to( darr_t*    lhs, oarrm6n2_t*   rhs, oarrm6n2_t* res);
  void oarrm6n2_sub_OR_to( oarrm6n2_t*   lhs, darr_t*    rhs, oarrm6n2_t* res);
  void oarrm6n2_sub_oO_to( onumm6n2_t* lhs, oarrm6n2_t*   rhs, oarrm6n2_t* res);
  void oarrm6n2_sub_Oo_to( oarrm6n2_t*   lhs, onumm6n2_t* rhs, oarrm6n2_t* res);
  void oarrm6n2_sub_rO_to( coeff_t    lhs, oarrm6n2_t*   rhs, oarrm6n2_t* res);
  void oarrm6n2_sub_Or_to( oarrm6n2_t*   lhs, coeff_t    rhs, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_mul_OO(oarrm6n2_t*   lhs, oarrm6n2_t* rhs);
  oarrm6n2_t oarrm6n2_mul_RO(darr_t*    lhs, oarrm6n2_t* rhs);
  oarrm6n2_t oarrm6n2_mul_oO(onumm6n2_t* lhs, oarrm6n2_t* rhs);
  oarrm6n2_t oarrm6n2_mul_rO(coeff_t    lhs, oarrm6n2_t* rhs);
  void oarrm6n2_mul_OO_to(oarrm6n2_t*   lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
  void oarrm6n2_mul_RO_to(darr_t*    lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
  void oarrm6n2_mul_oO_to(onumm6n2_t* lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
  void oarrm6n2_mul_rO_to(coeff_t    lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
  void oarrm6n2_gem_OO_to(  oarrm6n2_t* arr1, oarrm6n2_t* arr2, oarrm6n2_t* arr3, oarrm6n2_t* res);
  void oarrm6n2_gem_oO_to(onumm6n2_t* arr1, oarrm6n2_t* arr2, oarrm6n2_t* arr3, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_div_OO(oarrm6n2_t*   lhs, oarrm6n2_t*   rhs);
  oarrm6n2_t oarrm6n2_div_OR(oarrm6n2_t*   lhs, darr_t*    rhs);
  oarrm6n2_t oarrm6n2_div_RO(darr_t*    lhs, oarrm6n2_t*   rhs);
  oarrm6n2_t oarrm6n2_div_oO(onumm6n2_t* lhs, oarrm6n2_t*   rhs);
  oarrm6n2_t oarrm6n2_div_Oo(oarrm6n2_t*   lhs, onumm6n2_t* rhs);
  oarrm6n2_t oarrm6n2_div_rO(coeff_t    lhs, oarrm6n2_t*   rhs);
  oarrm6n2_t oarrm6n2_div_Or(oarrm6n2_t*   lhs, coeff_t    rhs);
  void oarrm6n2_div_OO_to(oarrm6n2_t*   lhs, oarrm6n2_t*   rhs, oarrm6n2_t* res);
  void oarrm6n2_div_RO_to(darr_t*    lhs, oarrm6n2_t*   rhs, oarrm6n2_t* res);
  void oarrm6n2_div_OR_to(oarrm6n2_t*   lhs, darr_t*    rhs, oarrm6n2_t* res);
  void oarrm6n2_div_oO_to(onumm6n2_t* lhs, oarrm6n2_t*   rhs, oarrm6n2_t* res);
  void oarrm6n2_div_Oo_to(oarrm6n2_t*   lhs, onumm6n2_t* rhs, oarrm6n2_t* res);
  void oarrm6n2_div_rO_to(coeff_t    lhs, oarrm6n2_t*   rhs, oarrm6n2_t* res);
  void oarrm6n2_div_Or_to(oarrm6n2_t*   lhs, coeff_t    rhs, oarrm6n2_t* res);
  
  
  # From ../../../include/oti/static/onumm6n2/array/base.h
  
  void    oarrm6n2_taylor_integrate_to( coeff_t* deltas, oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_taylor_integrate(    coeff_t* deltas, oarrm6n2_t* arr);
  void    oarrm6n2_get_order_im_to( ord_t order, oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_get_order_im(    ord_t order, oarrm6n2_t* arr);
  void oarrm6n2_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm6n2_t* res);
  void oarrm6n2_set_slice_O( oarrm6n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm6n2_t* res);
  void oarrm6n2_set_slice_o( onumm6n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_get_slice( oarrm6n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm6n2_get_slice_to( oarrm6n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_truncate_im(    imdir_t idx, ord_t order, oarrm6n2_t* arr);
  void    oarrm6n2_truncate_im_to( imdir_t idx, ord_t order, oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_extract_im(   imdir_t idx, ord_t order, oarrm6n2_t* arr);
  void    oarrm6n2_extract_im_to(imdir_t idx, ord_t order, oarrm6n2_t* arr, oarrm6n2_t* res);
  darr_t  oarrm6n2_get_deriv(    imdir_t idx, ord_t order, oarrm6n2_t* arr);
  void    oarrm6n2_get_deriv_to( imdir_t idx, ord_t order, oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_get_deriv_o(  imdir_t idx, ord_t order, oarrm6n2_t* arr);
  oarrm6n2_t oarrm6n2_extract_deriv(    imdir_t idx, ord_t order, oarrm6n2_t* arr);
  void    oarrm6n2_extract_deriv_to( imdir_t idx, ord_t order, oarrm6n2_t* arr, oarrm6n2_t* res);
  darr_t  oarrm6n2_get_im(   imdir_t idx, ord_t order, oarrm6n2_t* arr);
  oarrm6n2_t oarrm6n2_get_im_o( imdir_t idx, ord_t order, oarrm6n2_t* arr);
  void    oarrm6n2_get_im_to(imdir_t idx, ord_t order, oarrm6n2_t* arr, oarrm6n2_t* res);
  void    oarrm6n2_copy_to(oarrm6n2_t* arr, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_copy(oarrm6n2_t* arr);
  void oarrm6n2_set_all_r( coeff_t num, oarrm6n2_t* arr);
  void oarrm6n2_set_item_i_r( coeff_t num, uint64_t i, oarrm6n2_t* arr);
  void oarrm6n2_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm6n2_t* arr);
  void oarrm6n2_set_r(   coeff_t  num,   oarrm6n2_t* arr);
  void oarrm6n2_set_o( onumm6n2_t* num,   oarrm6n2_t* arr);
  void oarrm6n2_set_O(   oarrm6n2_t* arrin, oarrm6n2_t* arr);
  void oarrm6n2_set_all_o( onumm6n2_t* src, oarrm6n2_t* arr);
  void oarrm6n2_set_item_i_o( onumm6n2_t* num, uint64_t i, oarrm6n2_t* arr);
  void oarrm6n2_set_item_ij_o( onumm6n2_t* num, uint64_t i, uint64_t j, oarrm6n2_t* arr);
  onumm6n2_t oarrm6n2_get_item_i(    oarrm6n2_t* arr, uint64_t i);
  void      oarrm6n2_get_item_i_to( oarrm6n2_t* arr, uint64_t i,             onumm6n2_t* res);
  onumm6n2_t oarrm6n2_get_item_ij(   oarrm6n2_t* arr, uint64_t i, uint64_t j);
  void      oarrm6n2_get_item_ij_to(oarrm6n2_t* arr, uint64_t i, uint64_t j, onumm6n2_t* res);
  oarrm6n2_t oarrm6n2_init();
  void oarrm6n2_free(oarrm6n2_t* arr);
  oarrm6n2_t oarrm6n2_empty_like(oarrm6n2_t* arr);
  oarrm6n2_t oarrm6n2_eye(uint64_t nrows);
  oarrm6n2_t oarrm6n2_ones(uint64_t nrows, uint64_t ncols);
  oarrm6n2_t oarrm6n2_zeros(uint64_t nrows, uint64_t ncols);
  oarrm6n2_t oarrm6n2_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm6n2/array/utils.h
  
  void oarrm6n2_dimCheck_OO_elementwise(oarrm6n2_t* arr1, oarrm6n2_t* arr2, oarrm6n2_t* res);
  void oarrm6n2_dimCheck_RO_elementwise(darr_t*  arr1, oarrm6n2_t* arr2, oarrm6n2_t* res);
  void oarrm6n2_dimCheck_OO_matmul(oarrm6n2_t* arr1, oarrm6n2_t* arr2, oarrm6n2_t* res);
  void oarrm6n2_dimCheck_RO_matmul(darr_t*  arr1, oarrm6n2_t* arr2, oarrm6n2_t* res);
  void oarrm6n2_dimCheck_OR_matmul(oarrm6n2_t* arr1, darr_t*  arr2, oarrm6n2_t* res);
  void oarrm6n2_dimCheck_O_squareness(oarrm6n2_t* arr1, oarrm6n2_t* res);
  void oarrm6n2_dimCheck_OO_samesize(oarrm6n2_t* arr1, oarrm6n2_t* res);
  void oarrm6n2_dimCheck_RO_samesize(darr_t* arr1, oarrm6n2_t* res);
  ord_t oarrm6n2_get_order(oarrm6n2_t* arr);
  void oarrm6n2_get_active_bases(oarrm6n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm6n2/array/algebra_matops.h
  
  onumm6n2_t oarrm6n2_dotproduct_OO(    oarrm6n2_t* lhs, oarrm6n2_t* rhs);
  void      oarrm6n2_dotproduct_OO_to( oarrm6n2_t* lhs, oarrm6n2_t* rhs, onumm6n2_t* res);
  onumm6n2_t oarrm6n2_dotproduct_RO(     darr_t* lhs, oarrm6n2_t* rhs);
  void      oarrm6n2_dotproduct_RO_to(  darr_t* lhs, oarrm6n2_t* rhs, onumm6n2_t* res);
  oarrm6n2_t oarrm6n2_matmul_OO(    oarrm6n2_t* lhs, oarrm6n2_t* rhs);
  oarrm6n2_t oarrm6n2_matmul_OR(    oarrm6n2_t* lhs,  darr_t* rhs);
  oarrm6n2_t oarrm6n2_matmul_RO(     darr_t* lhs, oarrm6n2_t* rhs);
  void    oarrm6n2_matmul_OO_to( oarrm6n2_t* lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
  void    oarrm6n2_matmul_OR_to( oarrm6n2_t* lhs,  darr_t* rhs, oarrm6n2_t* res);
  void    oarrm6n2_matmul_RO_to(  darr_t* lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_transpose(    oarrm6n2_t* arr1);
  void    oarrm6n2_transpose_to( oarrm6n2_t* arr1, oarrm6n2_t* res);
  oarrm6n2_t oarrm6n2_invert(    oarrm6n2_t* arr1);
  void    oarrm6n2_invert_to( oarrm6n2_t* arr1, oarrm6n2_t* res);
  onumm6n2_t oarrm6n2_det(    oarrm6n2_t* arr1);
  void      oarrm6n2_det_to( oarrm6n2_t* arr1, onumm6n2_t* res);
  onumm6n2_t oarrm6n2_norm(    oarrm6n2_t* arr1);
  void      oarrm6n2_norm_to( oarrm6n2_t* arr1,  onumm6n2_t* res);
  onumm6n2_t oarrm6n2_pnorm(    oarrm6n2_t* arr1, coeff_t p);
  void      oarrm6n2_pnorm_to( oarrm6n2_t* arr1, coeff_t p, onumm6n2_t* res);
  
  
  # From ../../../include/oti/static/onumm6n2/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm6n2/array/gauss/functions.h
  
  feoarrm6n2_t feoarrm6n2_atanh(    feoarrm6n2_t* arr);
  void      feoarrm6n2_atanh_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_asinh(    feoarrm6n2_t* arr);
  void      feoarrm6n2_asinh_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_acosh(    feoarrm6n2_t* arr);
  void      feoarrm6n2_acosh_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_tanh(     feoarrm6n2_t* arr);
  void      feoarrm6n2_tanh_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sinh(     feoarrm6n2_t* arr);
  void      feoarrm6n2_sinh_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_cosh(     feoarrm6n2_t* arr);
  void      feoarrm6n2_cosh_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_atan(     feoarrm6n2_t* arr);
  void      feoarrm6n2_atan_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_asin(     feoarrm6n2_t* arr);
  void      feoarrm6n2_asin_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_acos(     feoarrm6n2_t* arr);
  void      feoarrm6n2_acos_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_tan(      feoarrm6n2_t* arr);
  void      feoarrm6n2_tan_to(   feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sin(      feoarrm6n2_t* arr);
  void      feoarrm6n2_sin_to(   feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_cos(      feoarrm6n2_t* arr);
  void      feoarrm6n2_cos_to(   feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_logb(     feoarrm6n2_t* arr, double base);
  void      feoarrm6n2_logb_to(  feoarrm6n2_t* arr, double base, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_log10(    feoarrm6n2_t* arr);
  void      feoarrm6n2_log10_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_log(      feoarrm6n2_t* arr);
  void      feoarrm6n2_log_to(   feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_exp(      feoarrm6n2_t* arr);
  void      feoarrm6n2_exp_to(   feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_cbrt(     feoarrm6n2_t* arr);
  void      feoarrm6n2_cbrt_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sqrt(     feoarrm6n2_t* arr);
  void      feoarrm6n2_sqrt_to(  feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_pow(      feoarrm6n2_t* arr, double e);
  void      feoarrm6n2_pow_to(   feoarrm6n2_t* arr, double e, feoarrm6n2_t* res);
  
  
  # From ../../../include/oti/static/onumm6n2/array/gauss/base.h
  
  void      feoarrm6n2_get_order_im_to( ord_t order, feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_get_order_im(    ord_t order, feoarrm6n2_t* arr);
  feoarrm6n2_t feoarrm6n2_get_deriv(   imdir_t idx, ord_t order, feoarrm6n2_t* arr);
  void      feoarrm6n2_get_deriv_to(imdir_t idx, ord_t order, feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_get_im(      imdir_t idx, ord_t order, feoarrm6n2_t* arr);
  void      feoarrm6n2_get_im_to(   imdir_t idx, ord_t order, feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_truncate_im(   imdir_t idx, ord_t order, feoarrm6n2_t* arr);
  void      feoarrm6n2_truncate_im_to(imdir_t idx, ord_t order, feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_copy(   feoarrm6n2_t* src);
  void      feoarrm6n2_copy_to(feoarrm6n2_t* src, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_get_im(    imdir_t idx, ord_t order, feoarrm6n2_t* arr);
  void      feoarrm6n2_get_im_to( imdir_t idx, ord_t order, feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_get_deriv(    imdir_t idx, ord_t order, feoarrm6n2_t* arr);
  void      feoarrm6n2_get_deriv_to( imdir_t idx, ord_t order, feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_extract_im(    imdir_t idx, ord_t order, feoarrm6n2_t* arr);
  void      feoarrm6n2_extract_im_to( imdir_t idx, ord_t order, feoarrm6n2_t* arr,  feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_extract_deriv(    imdir_t idx, ord_t order, feoarrm6n2_t* arr);
  void      feoarrm6n2_extract_deriv_to( imdir_t idx, ord_t order, feoarrm6n2_t* arr, feoarrm6n2_t* res);
  oarrm6n2_t   feoarrm6n2_get_item_k(  feoarrm6n2_t* arr, uint64_t k);
  feonumm6n2_t  feoarrm6n2_get_item_ij( feoarrm6n2_t* arr, uint64_t i, uint64_t j);
  onumm6n2_t feoarrm6n2_get_item_ijk(feoarrm6n2_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm6n2_get_item_ij_to(  feoarrm6n2_t* arr, uint64_t i, uint64_t j,
                                 feonumm6n2_t* res);
  void feoarrm6n2_get_item_k_to(   feoarrm6n2_t* arr, uint64_t k,
                                  oarrm6n2_t* res);
  void feoarrm6n2_get_item_ijk_to( feoarrm6n2_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_get_slice(feoarrm6n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm6n2_get_slice_to(feoarrm6n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm6n2_t* res);
  void feoarrm6n2_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm6n2_t* res);
  void feoarrm6n2_set_item_ij_o(  onumm6n2_t* elm, uint64_t i, uint64_t j,
                               feoarrm6n2_t* res);
  void feoarrm6n2_set_item_ij_f(  feonumm6n2_t* elm, uint64_t i, uint64_t j,
                              feoarrm6n2_t* res);
  void feoarrm6n2_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm6n2_t* res);
  void feoarrm6n2_set_item_k_o(  onumm6n2_t* elm, uint64_t k,
                              feoarrm6n2_t* res);
  void feoarrm6n2_set_item_k_R(    oarrm6n2_t* elm, uint64_t k,
                            feoarrm6n2_t* res);
  void feoarrm6n2_set_item_k_O(    oarrm6n2_t* elm, uint64_t k,
                            feoarrm6n2_t* res);
  void feoarrm6n2_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm6n2_t* res);
  void feoarrm6n2_set_item_ijk_o( onumm6n2_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm6n2_t* res);
  void feoarrm6n2_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm6n2_t* res);
  void feoarrm6n2_set_slice_o( onumm6n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm6n2_t* res);
  void feoarrm6n2_set_slice_f( feonumm6n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm6n2_t* res);
  void feoarrm6n2_set_slice_O( oarrm6n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm6n2_t* res);
  void feoarrm6n2_set_slice_F( feoarrm6n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm6n2_t* res);
  void feoarrm6n2_set_all_o( onumm6n2_t* num, feoarrm6n2_t* arr );
  void feoarrm6n2_set_all_r(   coeff_t  num, feoarrm6n2_t* arr );
  void feoarrm6n2_set_all_f(  feonumm6n2_t* num, feoarrm6n2_t* arr );
  void feoarrm6n2_set_r(    coeff_t src, feoarrm6n2_t* res );
  void feoarrm6n2_set_o( onumm6n2_t* src, feoarrm6n2_t* res );
  void feoarrm6n2_set_f(  feonumm6n2_t* src, feoarrm6n2_t* res );
  void feoarrm6n2_set_R(    darr_t* src, feoarrm6n2_t* res );
  void feoarrm6n2_set_O(   oarrm6n2_t* src, feoarrm6n2_t* res );
  void feoarrm6n2_set_F( feoarrm6n2_t* src, feoarrm6n2_t* res );
  feoarrm6n2_t feoarrm6n2_eye( uint64_t size,  uint64_t nip);
  feoarrm6n2_t feoarrm6n2_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm6n2_t feoarrm6n2_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm6n2_t feoarrm6n2_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm6n2_free(feoarrm6n2_t* arr);
  feoarrm6n2_t feoarrm6n2_init();
  ord_t feoarrm6n2_get_order(feoarrm6n2_t* arr);
  
  
  # From ../../../include/oti/static/onumm6n2/array/gauss/utils.h
  
  void feoarrm6n2_dimCheck_FF_samesize(feoarrm6n2_t* arr1, feoarrm6n2_t* arr2, feonumm6n2_t* res);
  void feoarrm6n2_dimCheck_OF_samesize(  oarrm6n2_t* arr1, feoarrm6n2_t* arr2, feonumm6n2_t* res);
  void feoarrm6n2_dimCheck_RF_samesize(   darr_t* arr1, feoarrm6n2_t* arr2, feonumm6n2_t* res);
  void feoarrm6n2_dimCheck_FF_elementwise(feoarrm6n2_t* arr1, feoarrm6n2_t* arr2, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_OF_elementwise(  oarrm6n2_t* arr1, feoarrm6n2_t* arr2, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm6n2_t* arr2, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_fF_elementwise( feonumm6n2_t* num1, feoarrm6n2_t* arr2, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_Ff_elementwise(feoarrm6n2_t* arr1,  feonumm6n2_t* num2, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_FF_matmul( feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_OF_matmul(   oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_FO_matmul( feoarrm6n2_t* lhs,   oarrm6n2_t* rhs, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_FR_matmul( feoarrm6n2_t* lhs,    darr_t* rhs, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_F_squareness( feoarrm6n2_t* arr1, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_F_transpose( feoarrm6n2_t* arr1, feoarrm6n2_t* res);
  void feoarrm6n2_dimCheck_FfO_integrate(feoarrm6n2_t* arr, feonumm6n2_t* num,oarrm6n2_t* res);
  void feoarrm6n2_get_active_bases(feoarrm6n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm6n2/array/gauss/algebra.h
  
  feoarrm6n2_t feoarrm6n2_neg(    feoarrm6n2_t* arr);
  void      feoarrm6n2_neg_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sum_FF(   feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sum_FF_to(feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sum_fF(    feonumm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sum_fF_to( feonumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sum_OF(     oarrm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sum_OF_to(  oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sum_RF(      darr_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sum_RF_to(   darr_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sum_oF(   onumm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sum_oF_to(onumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sum_rF(     coeff_t  lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sum_rF_to(  coeff_t  lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sub_FF(    feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sub_FF_to( feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sub_fF(    feonumm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sub_fF_to( feonumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sub_Ff(    feoarrm6n2_t* lhs, feonumm6n2_t* rhs);
  void      feoarrm6n2_sub_Ff_to( feoarrm6n2_t* lhs, feonumm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sub_OF(      oarrm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sub_OF_to(   oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sub_FO(    feoarrm6n2_t* lhs,   oarrm6n2_t* rhs);
  void      feoarrm6n2_sub_FO_to( feoarrm6n2_t* lhs,   oarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sub_RF(       darr_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sub_RF_to(    darr_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sub_FR(    feoarrm6n2_t* lhs,    darr_t* rhs);
  void      feoarrm6n2_sub_FR_to( feoarrm6n2_t* lhs,    darr_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sub_oF(    onumm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sub_oF_to( onumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sub_Fo(    feoarrm6n2_t* lhs, onumm6n2_t* rhs);
  void      feoarrm6n2_sub_Fo_to( feoarrm6n2_t* lhs, onumm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sub_rF(      coeff_t  lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_sub_rF_to(    coeff_t lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_sub_Fr(    feoarrm6n2_t* lhs,   coeff_t  rhs);
  void      feoarrm6n2_sub_Fr_to( feoarrm6n2_t* lhs,   coeff_t  rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_mul_FF(   feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_mul_FF_to(feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_mul_fF(    feonumm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_mul_fF_to( feonumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_mul_OF(     oarrm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_mul_OF_to(  oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_mul_RF(      darr_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_mul_RF_to(   darr_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_mul_oF(   onumm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_mul_oF_to(onumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_mul_rF(     coeff_t  lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_mul_rF_to(  coeff_t  lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_div_FF(    feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_div_FF_to( feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_div_fF(     feonumm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_div_fF_to(  feonumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_div_Ff(    feoarrm6n2_t* lhs,  feonumm6n2_t* rhs);
  void      feoarrm6n2_div_Ff_to( feoarrm6n2_t* lhs,  feonumm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_div_OF(      oarrm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_div_OF_to(   oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_div_FO(    feoarrm6n2_t* lhs,   oarrm6n2_t* rhs);
  void      feoarrm6n2_div_FO_to( feoarrm6n2_t* lhs,   oarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_div_RF(       darr_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_div_RF_to(    darr_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_div_FR(    feoarrm6n2_t* lhs,    darr_t* rhs);
  void      feoarrm6n2_div_FR_to( feoarrm6n2_t* lhs,    darr_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_div_oF(    onumm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_div_oF_to( onumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_div_Fo(    feoarrm6n2_t* lhs, onumm6n2_t* rhs);
  void      feoarrm6n2_div_Fo_to( feoarrm6n2_t* lhs, onumm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_div_rF(      coeff_t  lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_div_rF_to(    coeff_t lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_div_Fr(    feoarrm6n2_t* lhs,   coeff_t  rhs);
  void      feoarrm6n2_div_Fr_to( feoarrm6n2_t* lhs,   coeff_t  rhs, feoarrm6n2_t* res);
  oarrm6n2_t feoarrm6n2_integrate(    feoarrm6n2_t* arr, feonumm6n2_t* w);
  void    feoarrm6n2_integrate_to( feoarrm6n2_t* arr, feonumm6n2_t* w, oarrm6n2_t* res);
  feonumm6n2_t feoarrm6n2_dotproduct_FF(    feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
  void     feoarrm6n2_dotproduct_FF_to( feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feoarrm6n2_dotproduct_OF(      oarrm6n2_t* lhs, feoarrm6n2_t* rhs);
  void     feoarrm6n2_dotproduct_OF_to(   oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feonumm6n2_t* res);
  feonumm6n2_t feoarrm6n2_dotproduct_RF(       darr_t* lhs, feoarrm6n2_t* rhs);
  void     feoarrm6n2_dotproduct_RF_to(    darr_t* lhs, feoarrm6n2_t* rhs, feonumm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_matmul_FF(    feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_matmul_FF_to( feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_matmul_OF(    oarrm6n2_t*   lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_matmul_OF_to( oarrm6n2_t*   lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_matmul_FO(    feoarrm6n2_t* lhs, oarrm6n2_t*   rhs);
  void      feoarrm6n2_matmul_FO_to( feoarrm6n2_t* lhs, oarrm6n2_t*   rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_matmul_RF(    darr_t*    lhs, feoarrm6n2_t* rhs);
  void      feoarrm6n2_matmul_RF_to( darr_t*    lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
  feoarrm6n2_t feoarrm6n2_matmul_FR(    feoarrm6n2_t* lhs, darr_t*    rhs);
  void      feoarrm6n2_matmul_FR_to( feoarrm6n2_t* lhs, darr_t*    rhs, feoarrm6n2_t* res);
  feonumm6n2_t feoarrm6n2_det(   feoarrm6n2_t* arr);
  void     feoarrm6n2_det_to(feoarrm6n2_t* arr, feonumm6n2_t* res);
  feonumm6n2_t feoarrm6n2_norm(     feoarrm6n2_t* arr);
  void     feoarrm6n2_norm_to(  feoarrm6n2_t* arr, feonumm6n2_t* res);
  feonumm6n2_t feoarrm6n2_pnorm(    feoarrm6n2_t* arr, coeff_t p);
  void     feoarrm6n2_pnorm_to( feoarrm6n2_t* arr, coeff_t p, feonumm6n2_t* res);
  feoarrm6n2_t   feoarrm6n2_invert(    feoarrm6n2_t* arr);
  void        feoarrm6n2_invert_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
  feoarrm6n2_t   feoarrm6n2_transpose(   feoarrm6n2_t* arr);
  void        feoarrm6n2_transpose_to(feoarrm6n2_t* arr, feoarrm6n2_t* res);
  
  