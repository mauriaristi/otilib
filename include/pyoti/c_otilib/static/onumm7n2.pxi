cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm7n2/scalar/structures.h
  
  ctypedef struct  onumm7n2_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
    coeff_t e6;
    coeff_t e7;
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
  # } onumm7n2_t;
  
  
  # From ../../../include/oti/static/onumm7n2/array/structures.h
  
  ctypedef struct  oarrm7n2_t : # {
      onumm7n2_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm7n2_t;
  
  
  # From ../../../include/oti/static/onumm7n2/scalar/gauss/structures.h
  
  ctypedef struct  feonumm7n2_t: # {
      onumm7n2_t*  p_data;
      uint64_t    nip;
  # } feonumm7n2_t;
  
  
  # From ../../../include/oti/static/onumm7n2/array/gauss/structures.h
  
  ctypedef struct  feoarrm7n2_t: # {
      oarrm7n2_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm7n2_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm7n2/scalar/functions.h
  
  onumm7n2_t onumm7n2_atanh(onumm7n2_t* num);
  void onumm7n2_atanh_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_asinh(onumm7n2_t* num);
  void onumm7n2_asinh_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_acosh(onumm7n2_t* num);
  void onumm7n2_acosh_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_tanh(onumm7n2_t* num);
  void onumm7n2_tanh_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_sqrt(onumm7n2_t* num);
  void onumm7n2_sqrt_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_cbrt(onumm7n2_t* num);
  void onumm7n2_cbrt_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_cosh(onumm7n2_t* num);
  void onumm7n2_cosh_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_sinh(onumm7n2_t* num);
  void onumm7n2_sinh_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_asin(onumm7n2_t* num);
  void onumm7n2_asin_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_acos(onumm7n2_t* num);
  void onumm7n2_acos_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_atan(onumm7n2_t* num);
  void onumm7n2_atan_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_tan(onumm7n2_t* num);
  void onumm7n2_tan_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_cos(onumm7n2_t* num);
  void onumm7n2_cos_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_sin(onumm7n2_t* num );
  void onumm7n2_sin_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_logb(onumm7n2_t* num, double base);
  void onumm7n2_logb_to(onumm7n2_t* num, double base, onumm7n2_t* res);
  onumm7n2_t onumm7n2_log10(onumm7n2_t* num);
  void onumm7n2_log10_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_log(onumm7n2_t* num);
  void onumm7n2_log_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_exp(onumm7n2_t* num);
  void onumm7n2_exp_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_pow(onumm7n2_t* num, double e);
  void onumm7n2_pow_to(onumm7n2_t* num, coeff_t e, onumm7n2_t* res);
  
  
  # From ../../../include/oti/static/onumm7n2/scalar/base.h
  
  void onumm7n2_set_im_o(onumm7n2_t* num, imdir_t idx, ord_t order, onumm7n2_t* res);
  void onumm7n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm7n2_t* res);
  void onumm7n2_set_deriv_o(onumm7n2_t* num, imdir_t idx, ord_t order, onumm7n2_t* res);
  void onumm7n2_extract_im_to( imdir_t idx, ord_t order, onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_extract_im(imdir_t idx, ord_t order, onumm7n2_t* num);
  onumm7n2_t onumm7n2_extract_deriv(imdir_t idx, ord_t order, onumm7n2_t* num);
  void onumm7n2_extract_deriv_to(imdir_t idx, ord_t order, onumm7n2_t* num, onumm7n2_t* res);
  void onumm7n2_get_im_to_o(imdir_t idx, ord_t order, onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_get_im_o(imdir_t idx, ord_t order, onumm7n2_t* num);
  void onumm7n2_get_im_to_r(imdir_t idx, ord_t order, onumm7n2_t* num, coeff_t* res);
  ord_t onumm7n2_get_order(onumm7n2_t* lhs);
  onumm7n2_t onumm7n2_get_deriv_o( imdir_t idx, ord_t order, onumm7n2_t* num);
  void onumm7n2_get_deriv_to( imdir_t idx, ord_t order, onumm7n2_t* num, onumm7n2_t* res);
  void onumm7n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm7n2_t* res);
  onumm7n2_t onumm7n2_init();
  ndir_t onumm7n2_get_ndir_order(ord_t order, onumm7n2_t* num);
  ndir_t onumm7n2_get_ndir_total(onumm7n2_t* num);
  coeff_t* onumm7n2_get_order_address(ord_t order, onumm7n2_t* num);
  onumm7n2_t onumm7n2_create_r(  coeff_t lhs);
  void onumm7n2_set_r(  coeff_t lhs, onumm7n2_t* res);
  void onumm7n2_set_o(  onumm7n2_t* lhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_get_order_im(ord_t order, onumm7n2_t* lhs);
  void onumm7n2_get_order_im_to(ord_t order, onumm7n2_t* lhs, onumm7n2_t* res);
  coeff_t onumm7n2_get_item(imdir_t idx, ord_t order, onumm7n2_t* lhs);
  coeff_t onumm7n2_get_deriv(imdir_t idx, ord_t order, onumm7n2_t* lhs);
  void onumm7n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm7n2_t* x);
  onumm7n2_t onumm7n2_copy(  onumm7n2_t* lhs);
  void onumm7n2_copy_to(  onumm7n2_t* lhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_taylor_integrate(coeff_t* deltas,onumm7n2_t* lhs);
  void onumm7n2_taylor_integrate_to(coeff_t* deltas,onumm7n2_t* lhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_truncate_im(imdir_t idx, ord_t order, onumm7n2_t* lhs);
  void onumm7n2_truncate_im_to(imdir_t idx, ord_t order, onumm7n2_t* lhs, onumm7n2_t* res);
  void onumm7n2_print(  onumm7n2_t* lhs);
  imdir_t onumm7n2_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm7n2/scalar/utils.h
  
  void onumm7n2_get_active_bases(onumm7n2_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm7n2/scalar/algebra.h
  
  onumm7n2_t onumm7n2_abs(onumm7n2_t* num);
  onumm7n2_t onumm7n2_div_ro(coeff_t num, onumm7n2_t* den);
  onumm7n2_t onumm7n2_div_oo(onumm7n2_t* num, onumm7n2_t* den);
  onumm7n2_t onumm7n2_div_or(onumm7n2_t* num, coeff_t val);
  void onumm7n2_div_ro_to(coeff_t num, onumm7n2_t* den, onumm7n2_t* res);
  void onumm7n2_div_oo_to(onumm7n2_t* num, onumm7n2_t* den, onumm7n2_t* res);
  void onumm7n2_div_or_to(onumm7n2_t* num, coeff_t val, onumm7n2_t* res);
  void onumm7n2_abs_to(onumm7n2_t* num, onumm7n2_t* res);
  onumm7n2_t onumm7n2_neg(  onumm7n2_t* lhs);
  void onumm7n2_neg_to(  onumm7n2_t* lhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_sum_oo(  onumm7n2_t* lhs,  onumm7n2_t* rhs);
  void onumm7n2_sum_oo_to(  onumm7n2_t* lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_sum_ro(  coeff_t lhs,  onumm7n2_t* rhs);
  void onumm7n2_sum_ro_to(  coeff_t lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_sub_oo(  onumm7n2_t* lhs,  onumm7n2_t* rhs);
  void onumm7n2_sub_oo_to(  onumm7n2_t* lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_sub_ro(  coeff_t lhs,  onumm7n2_t* rhs);
  void onumm7n2_sub_ro_to(  coeff_t lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_sub_or(  onumm7n2_t* lhs,  coeff_t rhs);
  void onumm7n2_sub_or_to(  onumm7n2_t* lhs,  coeff_t rhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_mul_oo(  onumm7n2_t* lhs,  onumm7n2_t* rhs);
  void onumm7n2_mul_oo_to(  onumm7n2_t* lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_mul_ro(  coeff_t lhs,  onumm7n2_t* rhs);
  void onumm7n2_mul_ro_to(  coeff_t lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_trunc_mul_oo(  onumm7n2_t* lhs,  onumm7n2_t* rhs);
  void onumm7n2_trunc_mul_oo_to(  onumm7n2_t* lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
  onumm7n2_t onumm7n2_gem_oo(  onumm7n2_t* a,  onumm7n2_t* b,  onumm7n2_t* c);
  void onumm7n2_gem_oo_to(  onumm7n2_t* a,  onumm7n2_t* b,  onumm7n2_t* c, onumm7n2_t* res);
  onumm7n2_t onumm7n2_gem_ro(  coeff_t a,  onumm7n2_t* b,  onumm7n2_t* c);
  void onumm7n2_gem_ro_to(  coeff_t a,  onumm7n2_t* b,  onumm7n2_t* c, onumm7n2_t* res);
  void onumm7n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm7n2_t* a,  ord_t ord_rhs,  onumm7n2_t* b,  onumm7n2_t* c, onumm7n2_t* res);
  onumm7n2_t onumm7n2_feval(coeff_t* feval_re, onumm7n2_t* x);
  void onumm7n2_feval_to(coeff_t* feval_re, onumm7n2_t* x, onumm7n2_t* res);
  
  
  # From ../../../include/oti/static/onumm7n2/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm7n2/scalar/gauss/functions.h
  
  feonumm7n2_t feonumm7n2_atanh(    feonumm7n2_t* num);
  void     feonumm7n2_atanh_to( feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_asinh(    feonumm7n2_t* num);
  void     feonumm7n2_asinh_to( feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_acosh(    feonumm7n2_t* num);
  void     feonumm7n2_acosh_to( feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_tanh(     feonumm7n2_t* num);
  void     feonumm7n2_tanh_to(  feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_cosh(     feonumm7n2_t* num);
  void     feonumm7n2_cosh_to(  feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_sinh(     feonumm7n2_t* num);
  void     feonumm7n2_sinh_to(  feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_asin(     feonumm7n2_t* num);
  void     feonumm7n2_asin_to(  feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_acos(     feonumm7n2_t* num);
  void     feonumm7n2_acos_to(  feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_atan(     feonumm7n2_t* num);
  void     feonumm7n2_atan_to(  feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_tan(      feonumm7n2_t* num);
  void     feonumm7n2_tan_to(   feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_cos(      feonumm7n2_t* num);
  void     feonumm7n2_cos_to(   feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_sin(      feonumm7n2_t* num);
  void     feonumm7n2_sin_to(   feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_logb(     feonumm7n2_t* num, double base);
  void     feonumm7n2_logb_to(  feonumm7n2_t* num, double base, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_log10(    feonumm7n2_t* num);
  void     feonumm7n2_log10_to( feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_log(      feonumm7n2_t* num);
  void     feonumm7n2_log_to(   feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_exp(      feonumm7n2_t* num);
  void     feonumm7n2_exp_to(   feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_cbrt(     feonumm7n2_t* num);
  void     feonumm7n2_cbrt_to(  feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_sqrt(     feonumm7n2_t* num);
  void     feonumm7n2_sqrt_to(  feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_pow(      feonumm7n2_t* num, double e);
  void     feonumm7n2_pow_to(   feonumm7n2_t* num, double e, feonumm7n2_t* res);
  onumm7n2_t feonumm7n2_integrate(       feonumm7n2_t* num, feonumm7n2_t* w);
  void      feonumm7n2_integrate_to(    feonumm7n2_t* num, feonumm7n2_t* w, onumm7n2_t* res);
  onumm7n2_t feonumm7n2_integrate_f(     feonumm7n2_t* num, feonumm7n2_t* w);
  void      feonumm7n2_integrate_f_to(  feonumm7n2_t* num, feonumm7n2_t* w, onumm7n2_t* res);
  onumm7n2_t feonumm7n2_integrate_r(       coeff_t num, feonumm7n2_t* w);
  void      feonumm7n2_integrate_r_to(    coeff_t num, feonumm7n2_t* w, onumm7n2_t* res);
  onumm7n2_t feonumm7n2_integrate_o(    onumm7n2_t* num, feonumm7n2_t* w);
  void      feonumm7n2_integrate_o_to( onumm7n2_t* num, feonumm7n2_t* w, onumm7n2_t* res);
  
  
  # From ../../../include/oti/static/onumm7n2/scalar/gauss/base.h
  
  void     feonumm7n2_get_order_im_to( ord_t order, feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_get_order_im(    ord_t order, feonumm7n2_t* num);
  feonumm7n2_t feonumm7n2_get_im(    imdir_t idx, ord_t order, feonumm7n2_t* num);
  void     feonumm7n2_get_im_to( imdir_t idx, ord_t order, feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_get_deriv(    imdir_t idx, ord_t order, feonumm7n2_t* num);
  void     feonumm7n2_get_deriv_to( imdir_t idx, ord_t order, feonumm7n2_t* num, feonumm7n2_t* res);
  void feonumm7n2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm7n2_t* num);
  void feonumm7n2_set_im_o( onumm7n2_t* val, imdir_t idx, ord_t order, feonumm7n2_t* num);
  void feonumm7n2_set_im_f(  feonumm7n2_t* val, imdir_t idx, ord_t order, feonumm7n2_t* num);
  void feonumm7n2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm7n2_t* num);
  void feonumm7n2_set_deriv_o( onumm7n2_t* val, imdir_t idx, ord_t order, feonumm7n2_t* num);
  void feonumm7n2_set_deriv_f(  feonumm7n2_t* val, imdir_t idx, ord_t order, feonumm7n2_t* num);
  feonumm7n2_t feonumm7n2_extract_im(    imdir_t idx, ord_t order, feonumm7n2_t* num);
  void     feonumm7n2_extract_im_to( imdir_t idx, ord_t order, feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_extract_deriv(    imdir_t idx, ord_t order, feonumm7n2_t* num);
  void     feonumm7n2_extract_deriv_to( imdir_t idx, ord_t order, feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_truncate_im(    imdir_t idx, ord_t order, feonumm7n2_t* num);
  void     feonumm7n2_truncate_im_to( imdir_t idx, ord_t order, feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_copy(    feonumm7n2_t* src);
  void     feonumm7n2_copy_to( feonumm7n2_t* src, feonumm7n2_t* dst);
  void feonumm7n2_set_r(    coeff_t num, feonumm7n2_t* res);
  void feonumm7n2_set_o( onumm7n2_t* num, feonumm7n2_t* res);
  void feonumm7n2_set_f(  feonumm7n2_t* num, feonumm7n2_t* res);
  void feonumm7n2_set_item_k_r(   coeff_t  num, uint64_t k, feonumm7n2_t* res);
  void feonumm7n2_set_item_k_o( onumm7n2_t* num, uint64_t k, feonumm7n2_t* res);
  onumm7n2_t feonumm7n2_get_item_k(   feonumm7n2_t* num, uint64_t k);
  void      feonumm7n2_get_item_k_to(feonumm7n2_t* num, uint64_t k, onumm7n2_t* res);
  feonumm7n2_t feonumm7n2_zeros(uint64_t nIntPts);
  feonumm7n2_t feonumm7n2_createEmpty(uint64_t nIntPts);
  feonumm7n2_t feonumm7n2_empty_like(feonumm7n2_t* arr);
  void feonumm7n2_free(feonumm7n2_t* num);
  ord_t feonumm7n2_get_order( feonumm7n2_t* num );
  feonumm7n2_t feonumm7n2_init();
  
  
  # From ../../../include/oti/static/onumm7n2/scalar/gauss/utils.h
  
  void feonumm7n2_dimCheck(feonumm7n2_t* arr1,feonumm7n2_t* arr2);
  void feonumm7n2_get_active_bases(feonumm7n2_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm7n2/scalar/gauss/algebra.h
  
  feonumm7n2_t feonumm7n2_neg(   feonumm7n2_t* num);
  void     feonumm7n2_neg_to(feonumm7n2_t* num, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_sum_ff(   feonumm7n2_t* lhs, feonumm7n2_t* rhs);
  void     feonumm7n2_sum_ff_to(feonumm7n2_t* lhs, feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_sum_of(   onumm7n2_t* lhs, feonumm7n2_t* rhs);
  void     feonumm7n2_sum_of_to(onumm7n2_t* lhs, feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_sum_rf(   coeff_t lhs, feonumm7n2_t* rhs);
  void     feonumm7n2_sum_rf_to(coeff_t lhs, feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_sub_ff(     feonumm7n2_t* lhs,  feonumm7n2_t* rhs);
  void     feonumm7n2_sub_ff_to(  feonumm7n2_t* lhs,  feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_sub_of(    onumm7n2_t* lhs,  feonumm7n2_t* rhs);
  void     feonumm7n2_sub_of_to( onumm7n2_t* lhs,  feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_sub_fo(     feonumm7n2_t* lhs, onumm7n2_t* rhs);
  void     feonumm7n2_sub_fo_to(  feonumm7n2_t* lhs, onumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_sub_rf(       coeff_t lhs,  feonumm7n2_t* rhs);
  void     feonumm7n2_sub_rf_to(    coeff_t lhs,  feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_sub_fr(     feonumm7n2_t* lhs,    coeff_t rhs);
  void     feonumm7n2_sub_fr_to(  feonumm7n2_t* lhs,    coeff_t rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_mul_ff(   feonumm7n2_t* lhs, feonumm7n2_t* rhs);
  void     feonumm7n2_mul_ff_to(feonumm7n2_t* lhs, feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_mul_of(   onumm7n2_t* lhs, feonumm7n2_t* rhs);
  void     feonumm7n2_mul_of_to(onumm7n2_t* lhs, feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_mul_rf(   coeff_t lhs, feonumm7n2_t* rhs);
  void     feonumm7n2_mul_rf_to(coeff_t lhs, feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_div_ff(     feonumm7n2_t* lhs,  feonumm7n2_t* rhs);
  void     feonumm7n2_div_ff_to(  feonumm7n2_t* lhs,  feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_div_of(    onumm7n2_t* lhs,  feonumm7n2_t* rhs);
  void     feonumm7n2_div_of_to( onumm7n2_t* lhs,  feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_div_fo(     feonumm7n2_t* lhs, onumm7n2_t* rhs);
  void     feonumm7n2_div_fo_to(  feonumm7n2_t* lhs, onumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_div_rf(       coeff_t lhs,  feonumm7n2_t* rhs);
  void     feonumm7n2_div_rf_to(    coeff_t lhs,  feonumm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feonumm7n2_div_fr(     feonumm7n2_t* lhs,    coeff_t rhs);
  void     feonumm7n2_div_fr_to(  feonumm7n2_t* lhs,    coeff_t rhs, feonumm7n2_t* res);
  
  
  # From ../../../include/oti/static/onumm7n2/array/functions.h
  
  oarrm7n2_t oarrm7n2_atanh(   oarrm7n2_t* arr);
  void    oarrm7n2_atanh_to(oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_asinh(   oarrm7n2_t* arr);
  void    oarrm7n2_asinh_to(oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_acosh(   oarrm7n2_t* arr);
  void    oarrm7n2_acosh_to(oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_tanh(    oarrm7n2_t* arr);
  void    oarrm7n2_tanh_to( oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_cbrt(    oarrm7n2_t* arr);
  void    oarrm7n2_cbrt_to( oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_sqrt(    oarrm7n2_t* arr);
  void    oarrm7n2_sqrt_to( oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_cosh(    oarrm7n2_t* arr);
  void    oarrm7n2_cosh_to( oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_sinh(    oarrm7n2_t* arr);
  void    oarrm7n2_sinh_to( oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_asin(    oarrm7n2_t* arr);
  void    oarrm7n2_asin_to( oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_acos(    oarrm7n2_t* arr);
  void    oarrm7n2_acos_to( oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_atan(    oarrm7n2_t* arr);
  void    oarrm7n2_atan_to( oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_tan(     oarrm7n2_t* arr);
  void    oarrm7n2_tan_to(  oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_cos(     oarrm7n2_t* arr);
  void    oarrm7n2_cos_to(  oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_sin(     oarrm7n2_t* arr);
  void    oarrm7n2_sin_to(  oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_logb(    oarrm7n2_t* arr, double base);
  void    oarrm7n2_logb_to( oarrm7n2_t* arr, double base, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_log10(   oarrm7n2_t* arr);
  void    oarrm7n2_log10_to(oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_log(     oarrm7n2_t* arr);
  void    oarrm7n2_log_to(  oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_exp(     oarrm7n2_t* arr);
  void    oarrm7n2_exp_to(  oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_pow(     oarrm7n2_t* arr, double e);
  void    oarrm7n2_pow_to(  oarrm7n2_t* arr, double e, oarrm7n2_t* res);
  
  
  # From ../../../include/oti/static/onumm7n2/array/algebra_elementwise.h
  
  oarrm7n2_t oarrm7n2_neg(oarrm7n2_t* arr);
  void oarrm7n2_neg_to(oarrm7n2_t* rhs, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_sum_OO(oarrm7n2_t*   lhs, oarrm7n2_t* rhs);
  oarrm7n2_t oarrm7n2_sum_RO(darr_t*    lhs, oarrm7n2_t* rhs);
  oarrm7n2_t oarrm7n2_sum_oO(onumm7n2_t* lhs, oarrm7n2_t* rhs);
  oarrm7n2_t oarrm7n2_sum_rO(coeff_t    lhs, oarrm7n2_t* rhs);
  void oarrm7n2_sum_OO_to(oarrm7n2_t*   lhs, oarrm7n2_t* rhs, oarrm7n2_t* res);
  void oarrm7n2_sum_RO_to(darr_t*    lhs, oarrm7n2_t* rhs, oarrm7n2_t* res);
  void oarrm7n2_sum_oO_to(onumm7n2_t* lhs, oarrm7n2_t* rhs, oarrm7n2_t* res);
  void oarrm7n2_sum_rO_to(coeff_t    lhs, oarrm7n2_t* rhs, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_sub_OO(oarrm7n2_t*   lhs, oarrm7n2_t*   rhs);
  oarrm7n2_t oarrm7n2_sub_RO(darr_t*    lhs, oarrm7n2_t*   rhs);
  oarrm7n2_t oarrm7n2_sub_OR(oarrm7n2_t*   lhs, darr_t*    rhs);
  oarrm7n2_t oarrm7n2_sub_oO(onumm7n2_t* lhs, oarrm7n2_t*   rhs);
  oarrm7n2_t oarrm7n2_sub_Oo(oarrm7n2_t*   lhs, onumm7n2_t* rhs);
  oarrm7n2_t oarrm7n2_sub_rO(coeff_t    lhs, oarrm7n2_t*   rhs);
  oarrm7n2_t oarrm7n2_sub_Or(oarrm7n2_t*   lhs, coeff_t    rhs);
  void oarrm7n2_sub_OO_to( oarrm7n2_t*   lhs, oarrm7n2_t*   rhs, oarrm7n2_t* res);
  void oarrm7n2_sub_RO_to( darr_t*    lhs, oarrm7n2_t*   rhs, oarrm7n2_t* res);
  void oarrm7n2_sub_OR_to( oarrm7n2_t*   lhs, darr_t*    rhs, oarrm7n2_t* res);
  void oarrm7n2_sub_oO_to( onumm7n2_t* lhs, oarrm7n2_t*   rhs, oarrm7n2_t* res);
  void oarrm7n2_sub_Oo_to( oarrm7n2_t*   lhs, onumm7n2_t* rhs, oarrm7n2_t* res);
  void oarrm7n2_sub_rO_to( coeff_t    lhs, oarrm7n2_t*   rhs, oarrm7n2_t* res);
  void oarrm7n2_sub_Or_to( oarrm7n2_t*   lhs, coeff_t    rhs, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_mul_OO(oarrm7n2_t*   lhs, oarrm7n2_t* rhs);
  oarrm7n2_t oarrm7n2_mul_RO(darr_t*    lhs, oarrm7n2_t* rhs);
  oarrm7n2_t oarrm7n2_mul_oO(onumm7n2_t* lhs, oarrm7n2_t* rhs);
  oarrm7n2_t oarrm7n2_mul_rO(coeff_t    lhs, oarrm7n2_t* rhs);
  void oarrm7n2_mul_OO_to(oarrm7n2_t*   lhs, oarrm7n2_t* rhs, oarrm7n2_t* res);
  void oarrm7n2_mul_RO_to(darr_t*    lhs, oarrm7n2_t* rhs, oarrm7n2_t* res);
  void oarrm7n2_mul_oO_to(onumm7n2_t* lhs, oarrm7n2_t* rhs, oarrm7n2_t* res);
  void oarrm7n2_mul_rO_to(coeff_t    lhs, oarrm7n2_t* rhs, oarrm7n2_t* res);
  void oarrm7n2_gem_OO_to(  oarrm7n2_t* arr1, oarrm7n2_t* arr2, oarrm7n2_t* arr3, oarrm7n2_t* res);
  void oarrm7n2_gem_oO_to(onumm7n2_t* arr1, oarrm7n2_t* arr2, oarrm7n2_t* arr3, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_div_OO(oarrm7n2_t*   lhs, oarrm7n2_t*   rhs);
  oarrm7n2_t oarrm7n2_div_OR(oarrm7n2_t*   lhs, darr_t*    rhs);
  oarrm7n2_t oarrm7n2_div_RO(darr_t*    lhs, oarrm7n2_t*   rhs);
  oarrm7n2_t oarrm7n2_div_oO(onumm7n2_t* lhs, oarrm7n2_t*   rhs);
  oarrm7n2_t oarrm7n2_div_Oo(oarrm7n2_t*   lhs, onumm7n2_t* rhs);
  oarrm7n2_t oarrm7n2_div_rO(coeff_t    lhs, oarrm7n2_t*   rhs);
  oarrm7n2_t oarrm7n2_div_Or(oarrm7n2_t*   lhs, coeff_t    rhs);
  void oarrm7n2_div_OO_to(oarrm7n2_t*   lhs, oarrm7n2_t*   rhs, oarrm7n2_t* res);
  void oarrm7n2_div_RO_to(darr_t*    lhs, oarrm7n2_t*   rhs, oarrm7n2_t* res);
  void oarrm7n2_div_OR_to(oarrm7n2_t*   lhs, darr_t*    rhs, oarrm7n2_t* res);
  void oarrm7n2_div_oO_to(onumm7n2_t* lhs, oarrm7n2_t*   rhs, oarrm7n2_t* res);
  void oarrm7n2_div_Oo_to(oarrm7n2_t*   lhs, onumm7n2_t* rhs, oarrm7n2_t* res);
  void oarrm7n2_div_rO_to(coeff_t    lhs, oarrm7n2_t*   rhs, oarrm7n2_t* res);
  void oarrm7n2_div_Or_to(oarrm7n2_t*   lhs, coeff_t    rhs, oarrm7n2_t* res);
  
  
  # From ../../../include/oti/static/onumm7n2/array/base.h
  
  void    oarrm7n2_taylor_integrate_to( coeff_t* deltas, oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_taylor_integrate(    coeff_t* deltas, oarrm7n2_t* arr);
  void    oarrm7n2_get_order_im_to( ord_t order, oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_get_order_im(    ord_t order, oarrm7n2_t* arr);
  void oarrm7n2_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm7n2_t* res);
  void oarrm7n2_set_slice_O( oarrm7n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm7n2_t* res);
  void oarrm7n2_set_slice_o( onumm7n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_get_slice( oarrm7n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm7n2_get_slice_to( oarrm7n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_truncate_im(    imdir_t idx, ord_t order, oarrm7n2_t* arr);
  void    oarrm7n2_truncate_im_to( imdir_t idx, ord_t order, oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_extract_im(   imdir_t idx, ord_t order, oarrm7n2_t* arr);
  void    oarrm7n2_extract_im_to(imdir_t idx, ord_t order, oarrm7n2_t* arr, oarrm7n2_t* res);
  darr_t  oarrm7n2_get_deriv(    imdir_t idx, ord_t order, oarrm7n2_t* arr);
  void    oarrm7n2_get_deriv_to( imdir_t idx, ord_t order, oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_get_deriv_o(  imdir_t idx, ord_t order, oarrm7n2_t* arr);
  oarrm7n2_t oarrm7n2_extract_deriv(    imdir_t idx, ord_t order, oarrm7n2_t* arr);
  void    oarrm7n2_extract_deriv_to( imdir_t idx, ord_t order, oarrm7n2_t* arr, oarrm7n2_t* res);
  darr_t  oarrm7n2_get_im(   imdir_t idx, ord_t order, oarrm7n2_t* arr);
  oarrm7n2_t oarrm7n2_get_im_o( imdir_t idx, ord_t order, oarrm7n2_t* arr);
  void    oarrm7n2_get_im_to(imdir_t idx, ord_t order, oarrm7n2_t* arr, oarrm7n2_t* res);
  void    oarrm7n2_copy_to(oarrm7n2_t* arr, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_copy(oarrm7n2_t* arr);
  void oarrm7n2_set_all_r( coeff_t num, oarrm7n2_t* arr);
  void oarrm7n2_set_item_i_r( coeff_t num, uint64_t i, oarrm7n2_t* arr);
  void oarrm7n2_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm7n2_t* arr);
  void oarrm7n2_set_r(   coeff_t  num,   oarrm7n2_t* arr);
  void oarrm7n2_set_o( onumm7n2_t* num,   oarrm7n2_t* arr);
  void oarrm7n2_set_O(   oarrm7n2_t* arrin, oarrm7n2_t* arr);
  void oarrm7n2_set_all_o( onumm7n2_t* src, oarrm7n2_t* arr);
  void oarrm7n2_set_item_i_o( onumm7n2_t* num, uint64_t i, oarrm7n2_t* arr);
  void oarrm7n2_set_item_ij_o( onumm7n2_t* num, uint64_t i, uint64_t j, oarrm7n2_t* arr);
  onumm7n2_t oarrm7n2_get_item_i(    oarrm7n2_t* arr, uint64_t i);
  void      oarrm7n2_get_item_i_to( oarrm7n2_t* arr, uint64_t i,             onumm7n2_t* res);
  onumm7n2_t oarrm7n2_get_item_ij(   oarrm7n2_t* arr, uint64_t i, uint64_t j);
  void      oarrm7n2_get_item_ij_to(oarrm7n2_t* arr, uint64_t i, uint64_t j, onumm7n2_t* res);
  oarrm7n2_t oarrm7n2_init();
  void oarrm7n2_free(oarrm7n2_t* arr);
  oarrm7n2_t oarrm7n2_empty_like(oarrm7n2_t* arr);
  oarrm7n2_t oarrm7n2_eye(uint64_t nrows);
  oarrm7n2_t oarrm7n2_ones(uint64_t nrows, uint64_t ncols);
  oarrm7n2_t oarrm7n2_zeros(uint64_t nrows, uint64_t ncols);
  oarrm7n2_t oarrm7n2_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm7n2/array/utils.h
  
  void oarrm7n2_dimCheck_OO_elementwise(oarrm7n2_t* arr1, oarrm7n2_t* arr2, oarrm7n2_t* res);
  void oarrm7n2_dimCheck_RO_elementwise(darr_t*  arr1, oarrm7n2_t* arr2, oarrm7n2_t* res);
  void oarrm7n2_dimCheck_OO_matmul(oarrm7n2_t* arr1, oarrm7n2_t* arr2, oarrm7n2_t* res);
  void oarrm7n2_dimCheck_RO_matmul(darr_t*  arr1, oarrm7n2_t* arr2, oarrm7n2_t* res);
  void oarrm7n2_dimCheck_OR_matmul(oarrm7n2_t* arr1, darr_t*  arr2, oarrm7n2_t* res);
  void oarrm7n2_dimCheck_O_squareness(oarrm7n2_t* arr1, oarrm7n2_t* res);
  void oarrm7n2_dimCheck_OO_samesize(oarrm7n2_t* arr1, oarrm7n2_t* res);
  void oarrm7n2_dimCheck_RO_samesize(darr_t* arr1, oarrm7n2_t* res);
  ord_t oarrm7n2_get_order(oarrm7n2_t* arr);
  void oarrm7n2_get_active_bases(oarrm7n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm7n2/array/algebra_matops.h
  
  onumm7n2_t oarrm7n2_dotproduct_OO(    oarrm7n2_t* lhs, oarrm7n2_t* rhs);
  void      oarrm7n2_dotproduct_OO_to( oarrm7n2_t* lhs, oarrm7n2_t* rhs, onumm7n2_t* res);
  onumm7n2_t oarrm7n2_dotproduct_RO(     darr_t* lhs, oarrm7n2_t* rhs);
  void      oarrm7n2_dotproduct_RO_to(  darr_t* lhs, oarrm7n2_t* rhs, onumm7n2_t* res);
  oarrm7n2_t oarrm7n2_matmul_OO(    oarrm7n2_t* lhs, oarrm7n2_t* rhs);
  oarrm7n2_t oarrm7n2_matmul_OR(    oarrm7n2_t* lhs,  darr_t* rhs);
  oarrm7n2_t oarrm7n2_matmul_RO(     darr_t* lhs, oarrm7n2_t* rhs);
  void    oarrm7n2_matmul_OO_to( oarrm7n2_t* lhs, oarrm7n2_t* rhs, oarrm7n2_t* res);
  void    oarrm7n2_matmul_OR_to( oarrm7n2_t* lhs,  darr_t* rhs, oarrm7n2_t* res);
  void    oarrm7n2_matmul_RO_to(  darr_t* lhs, oarrm7n2_t* rhs, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_transpose(    oarrm7n2_t* arr1);
  void    oarrm7n2_transpose_to( oarrm7n2_t* arr1, oarrm7n2_t* res);
  oarrm7n2_t oarrm7n2_invert(    oarrm7n2_t* arr1);
  void    oarrm7n2_invert_to( oarrm7n2_t* arr1, oarrm7n2_t* res);
  onumm7n2_t oarrm7n2_det(    oarrm7n2_t* arr1);
  void      oarrm7n2_det_to( oarrm7n2_t* arr1, onumm7n2_t* res);
  onumm7n2_t oarrm7n2_norm(    oarrm7n2_t* arr1);
  void      oarrm7n2_norm_to( oarrm7n2_t* arr1,  onumm7n2_t* res);
  onumm7n2_t oarrm7n2_pnorm(    oarrm7n2_t* arr1, coeff_t p);
  void      oarrm7n2_pnorm_to( oarrm7n2_t* arr1, coeff_t p, onumm7n2_t* res);
  
  
  # From ../../../include/oti/static/onumm7n2/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm7n2/array/gauss/functions.h
  
  feoarrm7n2_t feoarrm7n2_atanh(    feoarrm7n2_t* arr);
  void      feoarrm7n2_atanh_to( feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_asinh(    feoarrm7n2_t* arr);
  void      feoarrm7n2_asinh_to( feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_acosh(    feoarrm7n2_t* arr);
  void      feoarrm7n2_acosh_to( feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_tanh(     feoarrm7n2_t* arr);
  void      feoarrm7n2_tanh_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sinh(     feoarrm7n2_t* arr);
  void      feoarrm7n2_sinh_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_cosh(     feoarrm7n2_t* arr);
  void      feoarrm7n2_cosh_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_atan(     feoarrm7n2_t* arr);
  void      feoarrm7n2_atan_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_asin(     feoarrm7n2_t* arr);
  void      feoarrm7n2_asin_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_acos(     feoarrm7n2_t* arr);
  void      feoarrm7n2_acos_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_tan(      feoarrm7n2_t* arr);
  void      feoarrm7n2_tan_to(   feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sin(      feoarrm7n2_t* arr);
  void      feoarrm7n2_sin_to(   feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_cos(      feoarrm7n2_t* arr);
  void      feoarrm7n2_cos_to(   feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_logb(     feoarrm7n2_t* arr, double base);
  void      feoarrm7n2_logb_to(  feoarrm7n2_t* arr, double base, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_log10(    feoarrm7n2_t* arr);
  void      feoarrm7n2_log10_to( feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_log(      feoarrm7n2_t* arr);
  void      feoarrm7n2_log_to(   feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_exp(      feoarrm7n2_t* arr);
  void      feoarrm7n2_exp_to(   feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_cbrt(     feoarrm7n2_t* arr);
  void      feoarrm7n2_cbrt_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sqrt(     feoarrm7n2_t* arr);
  void      feoarrm7n2_sqrt_to(  feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_pow(      feoarrm7n2_t* arr, double e);
  void      feoarrm7n2_pow_to(   feoarrm7n2_t* arr, double e, feoarrm7n2_t* res);
  
  
  # From ../../../include/oti/static/onumm7n2/array/gauss/base.h
  
  void      feoarrm7n2_get_order_im_to( ord_t order, feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_get_order_im(    ord_t order, feoarrm7n2_t* arr);
  feoarrm7n2_t feoarrm7n2_get_deriv(   imdir_t idx, ord_t order, feoarrm7n2_t* arr);
  void      feoarrm7n2_get_deriv_to(imdir_t idx, ord_t order, feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_get_im(      imdir_t idx, ord_t order, feoarrm7n2_t* arr);
  void      feoarrm7n2_get_im_to(   imdir_t idx, ord_t order, feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_truncate_im(   imdir_t idx, ord_t order, feoarrm7n2_t* arr);
  void      feoarrm7n2_truncate_im_to(imdir_t idx, ord_t order, feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_copy(   feoarrm7n2_t* src);
  void      feoarrm7n2_copy_to(feoarrm7n2_t* src, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_get_im(    imdir_t idx, ord_t order, feoarrm7n2_t* arr);
  void      feoarrm7n2_get_im_to( imdir_t idx, ord_t order, feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_get_deriv(    imdir_t idx, ord_t order, feoarrm7n2_t* arr);
  void      feoarrm7n2_get_deriv_to( imdir_t idx, ord_t order, feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_extract_im(    imdir_t idx, ord_t order, feoarrm7n2_t* arr);
  void      feoarrm7n2_extract_im_to( imdir_t idx, ord_t order, feoarrm7n2_t* arr,  feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_extract_deriv(    imdir_t idx, ord_t order, feoarrm7n2_t* arr);
  void      feoarrm7n2_extract_deriv_to( imdir_t idx, ord_t order, feoarrm7n2_t* arr, feoarrm7n2_t* res);
  oarrm7n2_t   feoarrm7n2_get_item_k(  feoarrm7n2_t* arr, uint64_t k);
  feonumm7n2_t  feoarrm7n2_get_item_ij( feoarrm7n2_t* arr, uint64_t i, uint64_t j);
  onumm7n2_t feoarrm7n2_get_item_ijk(feoarrm7n2_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm7n2_get_item_ij_to(  feoarrm7n2_t* arr, uint64_t i, uint64_t j,
                                 feonumm7n2_t* res);
  void feoarrm7n2_get_item_k_to(   feoarrm7n2_t* arr, uint64_t k,
                                  oarrm7n2_t* res);
  void feoarrm7n2_get_item_ijk_to( feoarrm7n2_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_get_slice(feoarrm7n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm7n2_get_slice_to(feoarrm7n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n2_t* res);
  void feoarrm7n2_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm7n2_t* res);
  void feoarrm7n2_set_item_ij_o(  onumm7n2_t* elm, uint64_t i, uint64_t j,
                               feoarrm7n2_t* res);
  void feoarrm7n2_set_item_ij_f(  feonumm7n2_t* elm, uint64_t i, uint64_t j,
                              feoarrm7n2_t* res);
  void feoarrm7n2_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm7n2_t* res);
  void feoarrm7n2_set_item_k_o(  onumm7n2_t* elm, uint64_t k,
                              feoarrm7n2_t* res);
  void feoarrm7n2_set_item_k_R(    oarrm7n2_t* elm, uint64_t k,
                            feoarrm7n2_t* res);
  void feoarrm7n2_set_item_k_O(    oarrm7n2_t* elm, uint64_t k,
                            feoarrm7n2_t* res);
  void feoarrm7n2_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm7n2_t* res);
  void feoarrm7n2_set_item_ijk_o( onumm7n2_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm7n2_t* res);
  void feoarrm7n2_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n2_t* res);
  void feoarrm7n2_set_slice_o( onumm7n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n2_t* res);
  void feoarrm7n2_set_slice_f( feonumm7n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n2_t* res);
  void feoarrm7n2_set_slice_O( oarrm7n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n2_t* res);
  void feoarrm7n2_set_slice_F( feoarrm7n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n2_t* res);
  void feoarrm7n2_set_all_o( onumm7n2_t* num, feoarrm7n2_t* arr );
  void feoarrm7n2_set_all_r(   coeff_t  num, feoarrm7n2_t* arr );
  void feoarrm7n2_set_all_f(  feonumm7n2_t* num, feoarrm7n2_t* arr );
  void feoarrm7n2_set_r(    coeff_t src, feoarrm7n2_t* res );
  void feoarrm7n2_set_o( onumm7n2_t* src, feoarrm7n2_t* res );
  void feoarrm7n2_set_f(  feonumm7n2_t* src, feoarrm7n2_t* res );
  void feoarrm7n2_set_R(    darr_t* src, feoarrm7n2_t* res );
  void feoarrm7n2_set_O(   oarrm7n2_t* src, feoarrm7n2_t* res );
  void feoarrm7n2_set_F( feoarrm7n2_t* src, feoarrm7n2_t* res );
  feoarrm7n2_t feoarrm7n2_eye( uint64_t size,  uint64_t nip);
  feoarrm7n2_t feoarrm7n2_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm7n2_t feoarrm7n2_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm7n2_t feoarrm7n2_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm7n2_free(feoarrm7n2_t* arr);
  feoarrm7n2_t feoarrm7n2_init();
  ord_t feoarrm7n2_get_order(feoarrm7n2_t* arr);
  
  
  # From ../../../include/oti/static/onumm7n2/array/gauss/utils.h
  
  void feoarrm7n2_dimCheck_FF_samesize(feoarrm7n2_t* arr1, feoarrm7n2_t* arr2, feonumm7n2_t* res);
  void feoarrm7n2_dimCheck_OF_samesize(  oarrm7n2_t* arr1, feoarrm7n2_t* arr2, feonumm7n2_t* res);
  void feoarrm7n2_dimCheck_RF_samesize(   darr_t* arr1, feoarrm7n2_t* arr2, feonumm7n2_t* res);
  void feoarrm7n2_dimCheck_FF_elementwise(feoarrm7n2_t* arr1, feoarrm7n2_t* arr2, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_OF_elementwise(  oarrm7n2_t* arr1, feoarrm7n2_t* arr2, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm7n2_t* arr2, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_fF_elementwise( feonumm7n2_t* num1, feoarrm7n2_t* arr2, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_Ff_elementwise(feoarrm7n2_t* arr1,  feonumm7n2_t* num2, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_FF_matmul( feoarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_OF_matmul(   oarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_FO_matmul( feoarrm7n2_t* lhs,   oarrm7n2_t* rhs, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_FR_matmul( feoarrm7n2_t* lhs,    darr_t* rhs, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_F_squareness( feoarrm7n2_t* arr1, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_F_transpose( feoarrm7n2_t* arr1, feoarrm7n2_t* res);
  void feoarrm7n2_dimCheck_FfO_integrate(feoarrm7n2_t* arr, feonumm7n2_t* num,oarrm7n2_t* res);
  void feoarrm7n2_get_active_bases(feoarrm7n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm7n2/array/gauss/algebra.h
  
  feoarrm7n2_t feoarrm7n2_neg(    feoarrm7n2_t* arr);
  void      feoarrm7n2_neg_to( feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sum_FF(   feoarrm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sum_FF_to(feoarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sum_fF(    feonumm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sum_fF_to( feonumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sum_OF(     oarrm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sum_OF_to(  oarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sum_RF(      darr_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sum_RF_to(   darr_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sum_oF(   onumm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sum_oF_to(onumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sum_rF(     coeff_t  lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sum_rF_to(  coeff_t  lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sub_FF(    feoarrm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sub_FF_to( feoarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sub_fF(    feonumm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sub_fF_to( feonumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sub_Ff(    feoarrm7n2_t* lhs, feonumm7n2_t* rhs);
  void      feoarrm7n2_sub_Ff_to( feoarrm7n2_t* lhs, feonumm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sub_OF(      oarrm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sub_OF_to(   oarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sub_FO(    feoarrm7n2_t* lhs,   oarrm7n2_t* rhs);
  void      feoarrm7n2_sub_FO_to( feoarrm7n2_t* lhs,   oarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sub_RF(       darr_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sub_RF_to(    darr_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sub_FR(    feoarrm7n2_t* lhs,    darr_t* rhs);
  void      feoarrm7n2_sub_FR_to( feoarrm7n2_t* lhs,    darr_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sub_oF(    onumm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sub_oF_to( onumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sub_Fo(    feoarrm7n2_t* lhs, onumm7n2_t* rhs);
  void      feoarrm7n2_sub_Fo_to( feoarrm7n2_t* lhs, onumm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sub_rF(      coeff_t  lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_sub_rF_to(    coeff_t lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_sub_Fr(    feoarrm7n2_t* lhs,   coeff_t  rhs);
  void      feoarrm7n2_sub_Fr_to( feoarrm7n2_t* lhs,   coeff_t  rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_mul_FF(   feoarrm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_mul_FF_to(feoarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_mul_fF(    feonumm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_mul_fF_to( feonumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_mul_OF(     oarrm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_mul_OF_to(  oarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_mul_RF(      darr_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_mul_RF_to(   darr_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_mul_oF(   onumm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_mul_oF_to(onumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_mul_rF(     coeff_t  lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_mul_rF_to(  coeff_t  lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_div_FF(    feoarrm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_div_FF_to( feoarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_div_fF(     feonumm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_div_fF_to(  feonumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_div_Ff(    feoarrm7n2_t* lhs,  feonumm7n2_t* rhs);
  void      feoarrm7n2_div_Ff_to( feoarrm7n2_t* lhs,  feonumm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_div_OF(      oarrm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_div_OF_to(   oarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_div_FO(    feoarrm7n2_t* lhs,   oarrm7n2_t* rhs);
  void      feoarrm7n2_div_FO_to( feoarrm7n2_t* lhs,   oarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_div_RF(       darr_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_div_RF_to(    darr_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_div_FR(    feoarrm7n2_t* lhs,    darr_t* rhs);
  void      feoarrm7n2_div_FR_to( feoarrm7n2_t* lhs,    darr_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_div_oF(    onumm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_div_oF_to( onumm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_div_Fo(    feoarrm7n2_t* lhs, onumm7n2_t* rhs);
  void      feoarrm7n2_div_Fo_to( feoarrm7n2_t* lhs, onumm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_div_rF(      coeff_t  lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_div_rF_to(    coeff_t lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_div_Fr(    feoarrm7n2_t* lhs,   coeff_t  rhs);
  void      feoarrm7n2_div_Fr_to( feoarrm7n2_t* lhs,   coeff_t  rhs, feoarrm7n2_t* res);
  oarrm7n2_t feoarrm7n2_integrate(    feoarrm7n2_t* arr, feonumm7n2_t* w);
  void    feoarrm7n2_integrate_to( feoarrm7n2_t* arr, feonumm7n2_t* w, oarrm7n2_t* res);
  feonumm7n2_t feoarrm7n2_dotproduct_FF(    feoarrm7n2_t* lhs, feoarrm7n2_t* rhs);
  void     feoarrm7n2_dotproduct_FF_to( feoarrm7n2_t* lhs, feoarrm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feoarrm7n2_dotproduct_OF(      oarrm7n2_t* lhs, feoarrm7n2_t* rhs);
  void     feoarrm7n2_dotproduct_OF_to(   oarrm7n2_t* lhs, feoarrm7n2_t* rhs, feonumm7n2_t* res);
  feonumm7n2_t feoarrm7n2_dotproduct_RF(       darr_t* lhs, feoarrm7n2_t* rhs);
  void     feoarrm7n2_dotproduct_RF_to(    darr_t* lhs, feoarrm7n2_t* rhs, feonumm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_matmul_FF(    feoarrm7n2_t* lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_matmul_FF_to( feoarrm7n2_t* lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_matmul_OF(    oarrm7n2_t*   lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_matmul_OF_to( oarrm7n2_t*   lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_matmul_FO(    feoarrm7n2_t* lhs, oarrm7n2_t*   rhs);
  void      feoarrm7n2_matmul_FO_to( feoarrm7n2_t* lhs, oarrm7n2_t*   rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_matmul_RF(    darr_t*    lhs, feoarrm7n2_t* rhs);
  void      feoarrm7n2_matmul_RF_to( darr_t*    lhs, feoarrm7n2_t* rhs, feoarrm7n2_t* res);
  feoarrm7n2_t feoarrm7n2_matmul_FR(    feoarrm7n2_t* lhs, darr_t*    rhs);
  void      feoarrm7n2_matmul_FR_to( feoarrm7n2_t* lhs, darr_t*    rhs, feoarrm7n2_t* res);
  feonumm7n2_t feoarrm7n2_det(   feoarrm7n2_t* arr);
  void     feoarrm7n2_det_to(feoarrm7n2_t* arr, feonumm7n2_t* res);
  feonumm7n2_t feoarrm7n2_norm(     feoarrm7n2_t* arr);
  void     feoarrm7n2_norm_to(  feoarrm7n2_t* arr, feonumm7n2_t* res);
  feonumm7n2_t feoarrm7n2_pnorm(    feoarrm7n2_t* arr, coeff_t p);
  void     feoarrm7n2_pnorm_to( feoarrm7n2_t* arr, coeff_t p, feonumm7n2_t* res);
  feoarrm7n2_t   feoarrm7n2_invert(    feoarrm7n2_t* arr);
  void        feoarrm7n2_invert_to( feoarrm7n2_t* arr, feoarrm7n2_t* res);
  feoarrm7n2_t   feoarrm7n2_transpose(   feoarrm7n2_t* arr);
  void        feoarrm7n2_transpose_to(feoarrm7n2_t* arr, feoarrm7n2_t* res);
  
  