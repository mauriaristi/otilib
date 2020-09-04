cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm3n3/scalar/structures.h
  
  ctypedef struct  onumm3n3_t : # {
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
    coeff_t e111;
    coeff_t e112;
    coeff_t e122;
    coeff_t e222;
    coeff_t e113;
    coeff_t e123;
    coeff_t e223;
    coeff_t e133;
    coeff_t e233;
    coeff_t e333;
  # } onumm3n3_t;
  
  
  # From ../../../include/oti/static/onumm3n3/array/structures.h
  
  ctypedef struct  oarrm3n3_t : # {
      onumm3n3_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm3n3_t;
  
  
  # From ../../../include/oti/static/onumm3n3/scalar/gauss/structures.h
  
  ctypedef struct  feonumm3n3_t: # {
      onumm3n3_t*  p_data;
      uint64_t    nip;
  # } feonumm3n3_t;
  
  
  # From ../../../include/oti/static/onumm3n3/array/gauss/structures.h
  
  ctypedef struct  feoarrm3n3_t: # {
      oarrm3n3_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm3n3_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm3n3/scalar/functions.h
  
  onumm3n3_t onumm3n3_atanh(onumm3n3_t* num);
  void onumm3n3_atanh_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_asinh(onumm3n3_t* num);
  void onumm3n3_asinh_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_acosh(onumm3n3_t* num);
  void onumm3n3_acosh_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_tanh(onumm3n3_t* num);
  void onumm3n3_tanh_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_sqrt(onumm3n3_t* num);
  void onumm3n3_sqrt_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_cbrt(onumm3n3_t* num);
  void onumm3n3_cbrt_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_cosh(onumm3n3_t* num);
  void onumm3n3_cosh_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_sinh(onumm3n3_t* num);
  void onumm3n3_sinh_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_asin(onumm3n3_t* num);
  void onumm3n3_asin_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_acos(onumm3n3_t* num);
  void onumm3n3_acos_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_atan(onumm3n3_t* num);
  void onumm3n3_atan_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_tan(onumm3n3_t* num);
  void onumm3n3_tan_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_cos(onumm3n3_t* num);
  void onumm3n3_cos_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_sin(onumm3n3_t* num );
  void onumm3n3_sin_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_logb(onumm3n3_t* num, double base);
  void onumm3n3_logb_to(onumm3n3_t* num, double base, onumm3n3_t* res);
  onumm3n3_t onumm3n3_log10(onumm3n3_t* num);
  void onumm3n3_log10_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_log(onumm3n3_t* num);
  void onumm3n3_log_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_exp(onumm3n3_t* num);
  void onumm3n3_exp_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_pow(onumm3n3_t* num, double e);
  void onumm3n3_pow_to(onumm3n3_t* num, coeff_t e, onumm3n3_t* res);
  
  
  # From ../../../include/oti/static/onumm3n3/scalar/base.h
  
  void onumm3n3_set_im_o(onumm3n3_t* num, imdir_t idx, ord_t order, onumm3n3_t* res);
  void onumm3n3_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm3n3_t* res);
  void onumm3n3_set_deriv_o(onumm3n3_t* num, imdir_t idx, ord_t order, onumm3n3_t* res);
  void onumm3n3_extract_im_to( imdir_t idx, ord_t order, onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_extract_im(imdir_t idx, ord_t order, onumm3n3_t* num);
  onumm3n3_t onumm3n3_extract_deriv(imdir_t idx, ord_t order, onumm3n3_t* num);
  void onumm3n3_extract_deriv_to(imdir_t idx, ord_t order, onumm3n3_t* num, onumm3n3_t* res);
  void onumm3n3_get_im_to_o(imdir_t idx, ord_t order, onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_get_im_o(imdir_t idx, ord_t order, onumm3n3_t* num);
  void onumm3n3_get_im_to_r(imdir_t idx, ord_t order, onumm3n3_t* num, coeff_t* res);
  ord_t onumm3n3_get_order(onumm3n3_t* lhs);
  onumm3n3_t onumm3n3_get_deriv_o( imdir_t idx, ord_t order, onumm3n3_t* num);
  void onumm3n3_get_deriv_to( imdir_t idx, ord_t order, onumm3n3_t* num, onumm3n3_t* res);
  void onumm3n3_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm3n3_t* res);
  onumm3n3_t onumm3n3_init();
  ndir_t onumm3n3_get_ndir_order(ord_t order, onumm3n3_t* num);
  ndir_t onumm3n3_get_ndir_total(onumm3n3_t* num);
  coeff_t* onumm3n3_get_order_address(ord_t order, onumm3n3_t* num);
  onumm3n3_t onumm3n3_create_r(  coeff_t lhs);
  void onumm3n3_set_r(  coeff_t lhs, onumm3n3_t* res);
  void onumm3n3_set_o(  onumm3n3_t* lhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_get_order_im(ord_t order, onumm3n3_t* lhs);
  void onumm3n3_get_order_im_to(ord_t order, onumm3n3_t* lhs, onumm3n3_t* res);
  coeff_t onumm3n3_get_item(imdir_t idx, ord_t order, onumm3n3_t* lhs);
  coeff_t onumm3n3_get_deriv(imdir_t idx, ord_t order, onumm3n3_t* lhs);
  void onumm3n3_set_item(coeff_t val, imdir_t idx, ord_t order, onumm3n3_t* x);
  onumm3n3_t onumm3n3_copy(  onumm3n3_t* lhs);
  void onumm3n3_copy_to(  onumm3n3_t* lhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_taylor_integrate(coeff_t* deltas,onumm3n3_t* lhs);
  void onumm3n3_taylor_integrate_to(coeff_t* deltas,onumm3n3_t* lhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_truncate_im(imdir_t idx, ord_t order, onumm3n3_t* lhs);
  void onumm3n3_truncate_im_to(imdir_t idx, ord_t order, onumm3n3_t* lhs, onumm3n3_t* res);
  void onumm3n3_print(  onumm3n3_t* lhs);
  imdir_t onumm3n3_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm3n3/scalar/utils.h
  
  void onumm3n3_get_active_bases(onumm3n3_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm3n3/scalar/algebra.h
  
  onumm3n3_t onumm3n3_abs(onumm3n3_t* num);
  onumm3n3_t onumm3n3_div_ro(coeff_t num, onumm3n3_t* den);
  onumm3n3_t onumm3n3_div_oo(onumm3n3_t* num, onumm3n3_t* den);
  onumm3n3_t onumm3n3_div_or(onumm3n3_t* num, coeff_t val);
  void onumm3n3_div_ro_to(coeff_t num, onumm3n3_t* den, onumm3n3_t* res);
  void onumm3n3_div_oo_to(onumm3n3_t* num, onumm3n3_t* den, onumm3n3_t* res);
  void onumm3n3_div_or_to(onumm3n3_t* num, coeff_t val, onumm3n3_t* res);
  void onumm3n3_abs_to(onumm3n3_t* num, onumm3n3_t* res);
  onumm3n3_t onumm3n3_neg(  onumm3n3_t* lhs);
  void onumm3n3_neg_to(  onumm3n3_t* lhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_sum_oo(  onumm3n3_t* lhs,  onumm3n3_t* rhs);
  void onumm3n3_sum_oo_to(  onumm3n3_t* lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_sum_ro(  coeff_t lhs,  onumm3n3_t* rhs);
  void onumm3n3_sum_ro_to(  coeff_t lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_sub_oo(  onumm3n3_t* lhs,  onumm3n3_t* rhs);
  void onumm3n3_sub_oo_to(  onumm3n3_t* lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_sub_ro(  coeff_t lhs,  onumm3n3_t* rhs);
  void onumm3n3_sub_ro_to(  coeff_t lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_sub_or(  onumm3n3_t* lhs,  coeff_t rhs);
  void onumm3n3_sub_or_to(  onumm3n3_t* lhs,  coeff_t rhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_mul_oo(  onumm3n3_t* lhs,  onumm3n3_t* rhs);
  void onumm3n3_mul_oo_to(  onumm3n3_t* lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_mul_ro(  coeff_t lhs,  onumm3n3_t* rhs);
  void onumm3n3_mul_ro_to(  coeff_t lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_trunc_mul_oo(  onumm3n3_t* lhs,  onumm3n3_t* rhs);
  void onumm3n3_trunc_mul_oo_to(  onumm3n3_t* lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
  onumm3n3_t onumm3n3_gem_oo(  onumm3n3_t* a,  onumm3n3_t* b,  onumm3n3_t* c);
  void onumm3n3_gem_oo_to(  onumm3n3_t* a,  onumm3n3_t* b,  onumm3n3_t* c, onumm3n3_t* res);
  onumm3n3_t onumm3n3_gem_ro(  coeff_t a,  onumm3n3_t* b,  onumm3n3_t* c);
  void onumm3n3_gem_ro_to(  coeff_t a,  onumm3n3_t* b,  onumm3n3_t* c, onumm3n3_t* res);
  void onumm3n3_trunc_gem_oo_to( ord_t ord_lhs,  onumm3n3_t* a,  ord_t ord_rhs,  onumm3n3_t* b,  onumm3n3_t* c, onumm3n3_t* res);
  onumm3n3_t onumm3n3_feval(coeff_t* feval_re, onumm3n3_t* x);
  void onumm3n3_feval_to(coeff_t* feval_re, onumm3n3_t* x, onumm3n3_t* res);
  
  
  # From ../../../include/oti/static/onumm3n3/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm3n3/scalar/gauss/functions.h
  
  feonumm3n3_t feonumm3n3_atanh(    feonumm3n3_t* num);
  void     feonumm3n3_atanh_to( feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_asinh(    feonumm3n3_t* num);
  void     feonumm3n3_asinh_to( feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_acosh(    feonumm3n3_t* num);
  void     feonumm3n3_acosh_to( feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_tanh(     feonumm3n3_t* num);
  void     feonumm3n3_tanh_to(  feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_cosh(     feonumm3n3_t* num);
  void     feonumm3n3_cosh_to(  feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_sinh(     feonumm3n3_t* num);
  void     feonumm3n3_sinh_to(  feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_asin(     feonumm3n3_t* num);
  void     feonumm3n3_asin_to(  feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_acos(     feonumm3n3_t* num);
  void     feonumm3n3_acos_to(  feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_atan(     feonumm3n3_t* num);
  void     feonumm3n3_atan_to(  feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_tan(      feonumm3n3_t* num);
  void     feonumm3n3_tan_to(   feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_cos(      feonumm3n3_t* num);
  void     feonumm3n3_cos_to(   feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_sin(      feonumm3n3_t* num);
  void     feonumm3n3_sin_to(   feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_logb(     feonumm3n3_t* num, double base);
  void     feonumm3n3_logb_to(  feonumm3n3_t* num, double base, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_log10(    feonumm3n3_t* num);
  void     feonumm3n3_log10_to( feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_log(      feonumm3n3_t* num);
  void     feonumm3n3_log_to(   feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_exp(      feonumm3n3_t* num);
  void     feonumm3n3_exp_to(   feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_cbrt(     feonumm3n3_t* num);
  void     feonumm3n3_cbrt_to(  feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_sqrt(     feonumm3n3_t* num);
  void     feonumm3n3_sqrt_to(  feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_pow(      feonumm3n3_t* num, double e);
  void     feonumm3n3_pow_to(   feonumm3n3_t* num, double e, feonumm3n3_t* res);
  onumm3n3_t feonumm3n3_integrate(       feonumm3n3_t* num, feonumm3n3_t* w);
  void      feonumm3n3_integrate_to(    feonumm3n3_t* num, feonumm3n3_t* w, onumm3n3_t* res);
  onumm3n3_t feonumm3n3_integrate_f(     feonumm3n3_t* num, feonumm3n3_t* w);
  void      feonumm3n3_integrate_f_to(  feonumm3n3_t* num, feonumm3n3_t* w, onumm3n3_t* res);
  onumm3n3_t feonumm3n3_integrate_r(       coeff_t num, feonumm3n3_t* w);
  void      feonumm3n3_integrate_r_to(    coeff_t num, feonumm3n3_t* w, onumm3n3_t* res);
  onumm3n3_t feonumm3n3_integrate_o(    onumm3n3_t* num, feonumm3n3_t* w);
  void      feonumm3n3_integrate_o_to( onumm3n3_t* num, feonumm3n3_t* w, onumm3n3_t* res);
  
  
  # From ../../../include/oti/static/onumm3n3/scalar/gauss/base.h
  
  void     feonumm3n3_get_order_im_to( ord_t order, feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_get_order_im(    ord_t order, feonumm3n3_t* num);
  feonumm3n3_t feonumm3n3_get_im(    imdir_t idx, ord_t order, feonumm3n3_t* num);
  void     feonumm3n3_get_im_to( imdir_t idx, ord_t order, feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_get_deriv(    imdir_t idx, ord_t order, feonumm3n3_t* num);
  void     feonumm3n3_get_deriv_to( imdir_t idx, ord_t order, feonumm3n3_t* num, feonumm3n3_t* res);
  void feonumm3n3_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm3n3_t* num);
  void feonumm3n3_set_im_o( onumm3n3_t* val, imdir_t idx, ord_t order, feonumm3n3_t* num);
  void feonumm3n3_set_im_f(  feonumm3n3_t* val, imdir_t idx, ord_t order, feonumm3n3_t* num);
  void feonumm3n3_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm3n3_t* num);
  void feonumm3n3_set_deriv_o( onumm3n3_t* val, imdir_t idx, ord_t order, feonumm3n3_t* num);
  void feonumm3n3_set_deriv_f(  feonumm3n3_t* val, imdir_t idx, ord_t order, feonumm3n3_t* num);
  feonumm3n3_t feonumm3n3_extract_im(    imdir_t idx, ord_t order, feonumm3n3_t* num);
  void     feonumm3n3_extract_im_to( imdir_t idx, ord_t order, feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_extract_deriv(    imdir_t idx, ord_t order, feonumm3n3_t* num);
  void     feonumm3n3_extract_deriv_to( imdir_t idx, ord_t order, feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_truncate_im(    imdir_t idx, ord_t order, feonumm3n3_t* num);
  void     feonumm3n3_truncate_im_to( imdir_t idx, ord_t order, feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_copy(    feonumm3n3_t* src);
  void     feonumm3n3_copy_to( feonumm3n3_t* src, feonumm3n3_t* dst);
  void feonumm3n3_set_r(    coeff_t num, feonumm3n3_t* res);
  void feonumm3n3_set_o( onumm3n3_t* num, feonumm3n3_t* res);
  void feonumm3n3_set_f(  feonumm3n3_t* num, feonumm3n3_t* res);
  void feonumm3n3_set_item_k_r(   coeff_t  num, uint64_t k, feonumm3n3_t* res);
  void feonumm3n3_set_item_k_o( onumm3n3_t* num, uint64_t k, feonumm3n3_t* res);
  onumm3n3_t feonumm3n3_get_item_k(   feonumm3n3_t* num, uint64_t k);
  void      feonumm3n3_get_item_k_to(feonumm3n3_t* num, uint64_t k, onumm3n3_t* res);
  feonumm3n3_t feonumm3n3_zeros(uint64_t nIntPts);
  feonumm3n3_t feonumm3n3_createEmpty(uint64_t nIntPts);
  feonumm3n3_t feonumm3n3_empty_like(feonumm3n3_t* arr);
  void feonumm3n3_free(feonumm3n3_t* num);
  ord_t feonumm3n3_get_order( feonumm3n3_t* num );
  feonumm3n3_t feonumm3n3_init();
  
  
  # From ../../../include/oti/static/onumm3n3/scalar/gauss/utils.h
  
  void feonumm3n3_dimCheck(feonumm3n3_t* arr1,feonumm3n3_t* arr2);
  void feonumm3n3_get_active_bases(feonumm3n3_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n3/scalar/gauss/algebra.h
  
  feonumm3n3_t feonumm3n3_neg(   feonumm3n3_t* num);
  void     feonumm3n3_neg_to(feonumm3n3_t* num, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_sum_ff(   feonumm3n3_t* lhs, feonumm3n3_t* rhs);
  void     feonumm3n3_sum_ff_to(feonumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_sum_of(   onumm3n3_t* lhs, feonumm3n3_t* rhs);
  void     feonumm3n3_sum_of_to(onumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_sum_rf(   coeff_t lhs, feonumm3n3_t* rhs);
  void     feonumm3n3_sum_rf_to(coeff_t lhs, feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_sub_ff(     feonumm3n3_t* lhs,  feonumm3n3_t* rhs);
  void     feonumm3n3_sub_ff_to(  feonumm3n3_t* lhs,  feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_sub_of(    onumm3n3_t* lhs,  feonumm3n3_t* rhs);
  void     feonumm3n3_sub_of_to( onumm3n3_t* lhs,  feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_sub_fo(     feonumm3n3_t* lhs, onumm3n3_t* rhs);
  void     feonumm3n3_sub_fo_to(  feonumm3n3_t* lhs, onumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_sub_rf(       coeff_t lhs,  feonumm3n3_t* rhs);
  void     feonumm3n3_sub_rf_to(    coeff_t lhs,  feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_sub_fr(     feonumm3n3_t* lhs,    coeff_t rhs);
  void     feonumm3n3_sub_fr_to(  feonumm3n3_t* lhs,    coeff_t rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_mul_ff(   feonumm3n3_t* lhs, feonumm3n3_t* rhs);
  void     feonumm3n3_mul_ff_to(feonumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_mul_of(   onumm3n3_t* lhs, feonumm3n3_t* rhs);
  void     feonumm3n3_mul_of_to(onumm3n3_t* lhs, feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_mul_rf(   coeff_t lhs, feonumm3n3_t* rhs);
  void     feonumm3n3_mul_rf_to(coeff_t lhs, feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_div_ff(     feonumm3n3_t* lhs,  feonumm3n3_t* rhs);
  void     feonumm3n3_div_ff_to(  feonumm3n3_t* lhs,  feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_div_of(    onumm3n3_t* lhs,  feonumm3n3_t* rhs);
  void     feonumm3n3_div_of_to( onumm3n3_t* lhs,  feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_div_fo(     feonumm3n3_t* lhs, onumm3n3_t* rhs);
  void     feonumm3n3_div_fo_to(  feonumm3n3_t* lhs, onumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_div_rf(       coeff_t lhs,  feonumm3n3_t* rhs);
  void     feonumm3n3_div_rf_to(    coeff_t lhs,  feonumm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feonumm3n3_div_fr(     feonumm3n3_t* lhs,    coeff_t rhs);
  void     feonumm3n3_div_fr_to(  feonumm3n3_t* lhs,    coeff_t rhs, feonumm3n3_t* res);
  
  
  # From ../../../include/oti/static/onumm3n3/array/functions.h
  
  oarrm3n3_t oarrm3n3_atanh(   oarrm3n3_t* arr);
  void    oarrm3n3_atanh_to(oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_asinh(   oarrm3n3_t* arr);
  void    oarrm3n3_asinh_to(oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_acosh(   oarrm3n3_t* arr);
  void    oarrm3n3_acosh_to(oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_tanh(    oarrm3n3_t* arr);
  void    oarrm3n3_tanh_to( oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_cbrt(    oarrm3n3_t* arr);
  void    oarrm3n3_cbrt_to( oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_sqrt(    oarrm3n3_t* arr);
  void    oarrm3n3_sqrt_to( oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_cosh(    oarrm3n3_t* arr);
  void    oarrm3n3_cosh_to( oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_sinh(    oarrm3n3_t* arr);
  void    oarrm3n3_sinh_to( oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_asin(    oarrm3n3_t* arr);
  void    oarrm3n3_asin_to( oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_acos(    oarrm3n3_t* arr);
  void    oarrm3n3_acos_to( oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_atan(    oarrm3n3_t* arr);
  void    oarrm3n3_atan_to( oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_tan(     oarrm3n3_t* arr);
  void    oarrm3n3_tan_to(  oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_cos(     oarrm3n3_t* arr);
  void    oarrm3n3_cos_to(  oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_sin(     oarrm3n3_t* arr);
  void    oarrm3n3_sin_to(  oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_logb(    oarrm3n3_t* arr, double base);
  void    oarrm3n3_logb_to( oarrm3n3_t* arr, double base, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_log10(   oarrm3n3_t* arr);
  void    oarrm3n3_log10_to(oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_log(     oarrm3n3_t* arr);
  void    oarrm3n3_log_to(  oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_exp(     oarrm3n3_t* arr);
  void    oarrm3n3_exp_to(  oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_pow(     oarrm3n3_t* arr, double e);
  void    oarrm3n3_pow_to(  oarrm3n3_t* arr, double e, oarrm3n3_t* res);
  
  
  # From ../../../include/oti/static/onumm3n3/array/algebra_elementwise.h
  
  oarrm3n3_t oarrm3n3_neg(oarrm3n3_t* arr);
  void oarrm3n3_neg_to(oarrm3n3_t* rhs, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_sum_OO(oarrm3n3_t*   lhs, oarrm3n3_t* rhs);
  oarrm3n3_t oarrm3n3_sum_RO(darr_t*    lhs, oarrm3n3_t* rhs);
  oarrm3n3_t oarrm3n3_sum_oO(onumm3n3_t* lhs, oarrm3n3_t* rhs);
  oarrm3n3_t oarrm3n3_sum_rO(coeff_t    lhs, oarrm3n3_t* rhs);
  void oarrm3n3_sum_OO_to(oarrm3n3_t*   lhs, oarrm3n3_t* rhs, oarrm3n3_t* res);
  void oarrm3n3_sum_RO_to(darr_t*    lhs, oarrm3n3_t* rhs, oarrm3n3_t* res);
  void oarrm3n3_sum_oO_to(onumm3n3_t* lhs, oarrm3n3_t* rhs, oarrm3n3_t* res);
  void oarrm3n3_sum_rO_to(coeff_t    lhs, oarrm3n3_t* rhs, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_sub_OO(oarrm3n3_t*   lhs, oarrm3n3_t*   rhs);
  oarrm3n3_t oarrm3n3_sub_RO(darr_t*    lhs, oarrm3n3_t*   rhs);
  oarrm3n3_t oarrm3n3_sub_OR(oarrm3n3_t*   lhs, darr_t*    rhs);
  oarrm3n3_t oarrm3n3_sub_oO(onumm3n3_t* lhs, oarrm3n3_t*   rhs);
  oarrm3n3_t oarrm3n3_sub_Oo(oarrm3n3_t*   lhs, onumm3n3_t* rhs);
  oarrm3n3_t oarrm3n3_sub_rO(coeff_t    lhs, oarrm3n3_t*   rhs);
  oarrm3n3_t oarrm3n3_sub_Or(oarrm3n3_t*   lhs, coeff_t    rhs);
  void oarrm3n3_sub_OO_to( oarrm3n3_t*   lhs, oarrm3n3_t*   rhs, oarrm3n3_t* res);
  void oarrm3n3_sub_RO_to( darr_t*    lhs, oarrm3n3_t*   rhs, oarrm3n3_t* res);
  void oarrm3n3_sub_OR_to( oarrm3n3_t*   lhs, darr_t*    rhs, oarrm3n3_t* res);
  void oarrm3n3_sub_oO_to( onumm3n3_t* lhs, oarrm3n3_t*   rhs, oarrm3n3_t* res);
  void oarrm3n3_sub_Oo_to( oarrm3n3_t*   lhs, onumm3n3_t* rhs, oarrm3n3_t* res);
  void oarrm3n3_sub_rO_to( coeff_t    lhs, oarrm3n3_t*   rhs, oarrm3n3_t* res);
  void oarrm3n3_sub_Or_to( oarrm3n3_t*   lhs, coeff_t    rhs, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_mul_OO(oarrm3n3_t*   lhs, oarrm3n3_t* rhs);
  oarrm3n3_t oarrm3n3_mul_RO(darr_t*    lhs, oarrm3n3_t* rhs);
  oarrm3n3_t oarrm3n3_mul_oO(onumm3n3_t* lhs, oarrm3n3_t* rhs);
  oarrm3n3_t oarrm3n3_mul_rO(coeff_t    lhs, oarrm3n3_t* rhs);
  void oarrm3n3_mul_OO_to(oarrm3n3_t*   lhs, oarrm3n3_t* rhs, oarrm3n3_t* res);
  void oarrm3n3_mul_RO_to(darr_t*    lhs, oarrm3n3_t* rhs, oarrm3n3_t* res);
  void oarrm3n3_mul_oO_to(onumm3n3_t* lhs, oarrm3n3_t* rhs, oarrm3n3_t* res);
  void oarrm3n3_mul_rO_to(coeff_t    lhs, oarrm3n3_t* rhs, oarrm3n3_t* res);
  void oarrm3n3_gem_OO_to(  oarrm3n3_t* arr1, oarrm3n3_t* arr2, oarrm3n3_t* arr3, oarrm3n3_t* res);
  void oarrm3n3_gem_oO_to(onumm3n3_t* arr1, oarrm3n3_t* arr2, oarrm3n3_t* arr3, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_div_OO(oarrm3n3_t*   lhs, oarrm3n3_t*   rhs);
  oarrm3n3_t oarrm3n3_div_OR(oarrm3n3_t*   lhs, darr_t*    rhs);
  oarrm3n3_t oarrm3n3_div_RO(darr_t*    lhs, oarrm3n3_t*   rhs);
  oarrm3n3_t oarrm3n3_div_oO(onumm3n3_t* lhs, oarrm3n3_t*   rhs);
  oarrm3n3_t oarrm3n3_div_Oo(oarrm3n3_t*   lhs, onumm3n3_t* rhs);
  oarrm3n3_t oarrm3n3_div_rO(coeff_t    lhs, oarrm3n3_t*   rhs);
  oarrm3n3_t oarrm3n3_div_Or(oarrm3n3_t*   lhs, coeff_t    rhs);
  void oarrm3n3_div_OO_to(oarrm3n3_t*   lhs, oarrm3n3_t*   rhs, oarrm3n3_t* res);
  void oarrm3n3_div_RO_to(darr_t*    lhs, oarrm3n3_t*   rhs, oarrm3n3_t* res);
  void oarrm3n3_div_OR_to(oarrm3n3_t*   lhs, darr_t*    rhs, oarrm3n3_t* res);
  void oarrm3n3_div_oO_to(onumm3n3_t* lhs, oarrm3n3_t*   rhs, oarrm3n3_t* res);
  void oarrm3n3_div_Oo_to(oarrm3n3_t*   lhs, onumm3n3_t* rhs, oarrm3n3_t* res);
  void oarrm3n3_div_rO_to(coeff_t    lhs, oarrm3n3_t*   rhs, oarrm3n3_t* res);
  void oarrm3n3_div_Or_to(oarrm3n3_t*   lhs, coeff_t    rhs, oarrm3n3_t* res);
  
  
  # From ../../../include/oti/static/onumm3n3/array/base.h
  
  void    oarrm3n3_taylor_integrate_to( coeff_t* deltas, oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_taylor_integrate(    coeff_t* deltas, oarrm3n3_t* arr);
  void    oarrm3n3_get_order_im_to( ord_t order, oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_get_order_im(    ord_t order, oarrm3n3_t* arr);
  void oarrm3n3_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n3_t* res);
  void oarrm3n3_set_slice_O( oarrm3n3_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n3_t* res);
  void oarrm3n3_set_slice_o( onumm3n3_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_get_slice( oarrm3n3_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm3n3_get_slice_to( oarrm3n3_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_truncate_im(    imdir_t idx, ord_t order, oarrm3n3_t* arr);
  void    oarrm3n3_truncate_im_to( imdir_t idx, ord_t order, oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_extract_im(   imdir_t idx, ord_t order, oarrm3n3_t* arr);
  void    oarrm3n3_extract_im_to(imdir_t idx, ord_t order, oarrm3n3_t* arr, oarrm3n3_t* res);
  darr_t  oarrm3n3_get_deriv(    imdir_t idx, ord_t order, oarrm3n3_t* arr);
  void    oarrm3n3_get_deriv_to( imdir_t idx, ord_t order, oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_get_deriv_o(  imdir_t idx, ord_t order, oarrm3n3_t* arr);
  oarrm3n3_t oarrm3n3_extract_deriv(    imdir_t idx, ord_t order, oarrm3n3_t* arr);
  void    oarrm3n3_extract_deriv_to( imdir_t idx, ord_t order, oarrm3n3_t* arr, oarrm3n3_t* res);
  darr_t  oarrm3n3_get_im(   imdir_t idx, ord_t order, oarrm3n3_t* arr);
  oarrm3n3_t oarrm3n3_get_im_o( imdir_t idx, ord_t order, oarrm3n3_t* arr);
  void    oarrm3n3_get_im_to(imdir_t idx, ord_t order, oarrm3n3_t* arr, oarrm3n3_t* res);
  void    oarrm3n3_copy_to(oarrm3n3_t* arr, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_copy(oarrm3n3_t* arr);
  void oarrm3n3_set_all_r( coeff_t num, oarrm3n3_t* arr);
  void oarrm3n3_set_item_i_r( coeff_t num, uint64_t i, oarrm3n3_t* arr);
  void oarrm3n3_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm3n3_t* arr);
  void oarrm3n3_set_r(   coeff_t  num,   oarrm3n3_t* arr);
  void oarrm3n3_set_o( onumm3n3_t* num,   oarrm3n3_t* arr);
  void oarrm3n3_set_O(   oarrm3n3_t* arrin, oarrm3n3_t* arr);
  void oarrm3n3_set_all_o( onumm3n3_t* src, oarrm3n3_t* arr);
  void oarrm3n3_set_item_i_o( onumm3n3_t* num, uint64_t i, oarrm3n3_t* arr);
  void oarrm3n3_set_item_ij_o( onumm3n3_t* num, uint64_t i, uint64_t j, oarrm3n3_t* arr);
  onumm3n3_t oarrm3n3_get_item_i(    oarrm3n3_t* arr, uint64_t i);
  void      oarrm3n3_get_item_i_to( oarrm3n3_t* arr, uint64_t i,             onumm3n3_t* res);
  onumm3n3_t oarrm3n3_get_item_ij(   oarrm3n3_t* arr, uint64_t i, uint64_t j);
  void      oarrm3n3_get_item_ij_to(oarrm3n3_t* arr, uint64_t i, uint64_t j, onumm3n3_t* res);
  oarrm3n3_t oarrm3n3_init();
  void oarrm3n3_free(oarrm3n3_t* arr);
  oarrm3n3_t oarrm3n3_empty_like(oarrm3n3_t* arr);
  oarrm3n3_t oarrm3n3_eye(uint64_t nrows);
  oarrm3n3_t oarrm3n3_ones(uint64_t nrows, uint64_t ncols);
  oarrm3n3_t oarrm3n3_zeros(uint64_t nrows, uint64_t ncols);
  oarrm3n3_t oarrm3n3_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm3n3/array/utils.h
  
  void oarrm3n3_dimCheck_OO_elementwise(oarrm3n3_t* arr1, oarrm3n3_t* arr2, oarrm3n3_t* res);
  void oarrm3n3_dimCheck_RO_elementwise(darr_t*  arr1, oarrm3n3_t* arr2, oarrm3n3_t* res);
  void oarrm3n3_dimCheck_OO_matmul(oarrm3n3_t* arr1, oarrm3n3_t* arr2, oarrm3n3_t* res);
  void oarrm3n3_dimCheck_RO_matmul(darr_t*  arr1, oarrm3n3_t* arr2, oarrm3n3_t* res);
  void oarrm3n3_dimCheck_OR_matmul(oarrm3n3_t* arr1, darr_t*  arr2, oarrm3n3_t* res);
  void oarrm3n3_dimCheck_O_squareness(oarrm3n3_t* arr1, oarrm3n3_t* res);
  void oarrm3n3_dimCheck_OO_samesize(oarrm3n3_t* arr1, oarrm3n3_t* res);
  void oarrm3n3_dimCheck_RO_samesize(darr_t* arr1, oarrm3n3_t* res);
  ord_t oarrm3n3_get_order(oarrm3n3_t* arr);
  void oarrm3n3_get_active_bases(oarrm3n3_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n3/array/algebra_matops.h
  
  onumm3n3_t oarrm3n3_dotproduct_OO(    oarrm3n3_t* lhs, oarrm3n3_t* rhs);
  void      oarrm3n3_dotproduct_OO_to( oarrm3n3_t* lhs, oarrm3n3_t* rhs, onumm3n3_t* res);
  onumm3n3_t oarrm3n3_dotproduct_RO(     darr_t* lhs, oarrm3n3_t* rhs);
  void      oarrm3n3_dotproduct_RO_to(  darr_t* lhs, oarrm3n3_t* rhs, onumm3n3_t* res);
  oarrm3n3_t oarrm3n3_matmul_OO(    oarrm3n3_t* lhs, oarrm3n3_t* rhs);
  oarrm3n3_t oarrm3n3_matmul_OR(    oarrm3n3_t* lhs,  darr_t* rhs);
  oarrm3n3_t oarrm3n3_matmul_RO(     darr_t* lhs, oarrm3n3_t* rhs);
  void    oarrm3n3_matmul_OO_to( oarrm3n3_t* lhs, oarrm3n3_t* rhs, oarrm3n3_t* res);
  void    oarrm3n3_matmul_OR_to( oarrm3n3_t* lhs,  darr_t* rhs, oarrm3n3_t* res);
  void    oarrm3n3_matmul_RO_to(  darr_t* lhs, oarrm3n3_t* rhs, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_transpose(    oarrm3n3_t* arr1);
  void    oarrm3n3_transpose_to( oarrm3n3_t* arr1, oarrm3n3_t* res);
  oarrm3n3_t oarrm3n3_invert(    oarrm3n3_t* arr1);
  void    oarrm3n3_invert_to( oarrm3n3_t* arr1, oarrm3n3_t* res);
  onumm3n3_t oarrm3n3_det(    oarrm3n3_t* arr1);
  void      oarrm3n3_det_to( oarrm3n3_t* arr1, onumm3n3_t* res);
  onumm3n3_t oarrm3n3_norm(    oarrm3n3_t* arr1);
  void      oarrm3n3_norm_to( oarrm3n3_t* arr1,  onumm3n3_t* res);
  onumm3n3_t oarrm3n3_pnorm(    oarrm3n3_t* arr1, coeff_t p);
  void      oarrm3n3_pnorm_to( oarrm3n3_t* arr1, coeff_t p, onumm3n3_t* res);
  
  
  # From ../../../include/oti/static/onumm3n3/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm3n3/array/gauss/functions.h
  
  feoarrm3n3_t feoarrm3n3_atanh(    feoarrm3n3_t* arr);
  void      feoarrm3n3_atanh_to( feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_asinh(    feoarrm3n3_t* arr);
  void      feoarrm3n3_asinh_to( feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_acosh(    feoarrm3n3_t* arr);
  void      feoarrm3n3_acosh_to( feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_tanh(     feoarrm3n3_t* arr);
  void      feoarrm3n3_tanh_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sinh(     feoarrm3n3_t* arr);
  void      feoarrm3n3_sinh_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_cosh(     feoarrm3n3_t* arr);
  void      feoarrm3n3_cosh_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_atan(     feoarrm3n3_t* arr);
  void      feoarrm3n3_atan_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_asin(     feoarrm3n3_t* arr);
  void      feoarrm3n3_asin_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_acos(     feoarrm3n3_t* arr);
  void      feoarrm3n3_acos_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_tan(      feoarrm3n3_t* arr);
  void      feoarrm3n3_tan_to(   feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sin(      feoarrm3n3_t* arr);
  void      feoarrm3n3_sin_to(   feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_cos(      feoarrm3n3_t* arr);
  void      feoarrm3n3_cos_to(   feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_logb(     feoarrm3n3_t* arr, double base);
  void      feoarrm3n3_logb_to(  feoarrm3n3_t* arr, double base, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_log10(    feoarrm3n3_t* arr);
  void      feoarrm3n3_log10_to( feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_log(      feoarrm3n3_t* arr);
  void      feoarrm3n3_log_to(   feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_exp(      feoarrm3n3_t* arr);
  void      feoarrm3n3_exp_to(   feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_cbrt(     feoarrm3n3_t* arr);
  void      feoarrm3n3_cbrt_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sqrt(     feoarrm3n3_t* arr);
  void      feoarrm3n3_sqrt_to(  feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_pow(      feoarrm3n3_t* arr, double e);
  void      feoarrm3n3_pow_to(   feoarrm3n3_t* arr, double e, feoarrm3n3_t* res);
  
  
  # From ../../../include/oti/static/onumm3n3/array/gauss/base.h
  
  void      feoarrm3n3_get_order_im_to( ord_t order, feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_get_order_im(    ord_t order, feoarrm3n3_t* arr);
  feoarrm3n3_t feoarrm3n3_get_deriv(   imdir_t idx, ord_t order, feoarrm3n3_t* arr);
  void      feoarrm3n3_get_deriv_to(imdir_t idx, ord_t order, feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_get_im(      imdir_t idx, ord_t order, feoarrm3n3_t* arr);
  void      feoarrm3n3_get_im_to(   imdir_t idx, ord_t order, feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_truncate_im(   imdir_t idx, ord_t order, feoarrm3n3_t* arr);
  void      feoarrm3n3_truncate_im_to(imdir_t idx, ord_t order, feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_copy(   feoarrm3n3_t* src);
  void      feoarrm3n3_copy_to(feoarrm3n3_t* src, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_get_im(    imdir_t idx, ord_t order, feoarrm3n3_t* arr);
  void      feoarrm3n3_get_im_to( imdir_t idx, ord_t order, feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_get_deriv(    imdir_t idx, ord_t order, feoarrm3n3_t* arr);
  void      feoarrm3n3_get_deriv_to( imdir_t idx, ord_t order, feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_extract_im(    imdir_t idx, ord_t order, feoarrm3n3_t* arr);
  void      feoarrm3n3_extract_im_to( imdir_t idx, ord_t order, feoarrm3n3_t* arr,  feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_extract_deriv(    imdir_t idx, ord_t order, feoarrm3n3_t* arr);
  void      feoarrm3n3_extract_deriv_to( imdir_t idx, ord_t order, feoarrm3n3_t* arr, feoarrm3n3_t* res);
  oarrm3n3_t   feoarrm3n3_get_item_k(  feoarrm3n3_t* arr, uint64_t k);
  feonumm3n3_t  feoarrm3n3_get_item_ij( feoarrm3n3_t* arr, uint64_t i, uint64_t j);
  onumm3n3_t feoarrm3n3_get_item_ijk(feoarrm3n3_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm3n3_get_item_ij_to(  feoarrm3n3_t* arr, uint64_t i, uint64_t j,
                                 feonumm3n3_t* res);
  void feoarrm3n3_get_item_k_to(   feoarrm3n3_t* arr, uint64_t k,
                                  oarrm3n3_t* res);
  void feoarrm3n3_get_item_ijk_to( feoarrm3n3_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_get_slice(feoarrm3n3_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm3n3_get_slice_to(feoarrm3n3_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n3_t* res);
  void feoarrm3n3_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm3n3_t* res);
  void feoarrm3n3_set_item_ij_o(  onumm3n3_t* elm, uint64_t i, uint64_t j,
                               feoarrm3n3_t* res);
  void feoarrm3n3_set_item_ij_f(  feonumm3n3_t* elm, uint64_t i, uint64_t j,
                              feoarrm3n3_t* res);
  void feoarrm3n3_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm3n3_t* res);
  void feoarrm3n3_set_item_k_o(  onumm3n3_t* elm, uint64_t k,
                              feoarrm3n3_t* res);
  void feoarrm3n3_set_item_k_R(    oarrm3n3_t* elm, uint64_t k,
                            feoarrm3n3_t* res);
  void feoarrm3n3_set_item_k_O(    oarrm3n3_t* elm, uint64_t k,
                            feoarrm3n3_t* res);
  void feoarrm3n3_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm3n3_t* res);
  void feoarrm3n3_set_item_ijk_o( onumm3n3_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm3n3_t* res);
  void feoarrm3n3_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n3_t* res);
  void feoarrm3n3_set_slice_o( onumm3n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n3_t* res);
  void feoarrm3n3_set_slice_f( feonumm3n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n3_t* res);
  void feoarrm3n3_set_slice_O( oarrm3n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n3_t* res);
  void feoarrm3n3_set_slice_F( feoarrm3n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n3_t* res);
  void feoarrm3n3_set_all_o( onumm3n3_t* num, feoarrm3n3_t* arr );
  void feoarrm3n3_set_all_r(   coeff_t  num, feoarrm3n3_t* arr );
  void feoarrm3n3_set_all_f(  feonumm3n3_t* num, feoarrm3n3_t* arr );
  void feoarrm3n3_set_r(    coeff_t src, feoarrm3n3_t* res );
  void feoarrm3n3_set_o( onumm3n3_t* src, feoarrm3n3_t* res );
  void feoarrm3n3_set_f(  feonumm3n3_t* src, feoarrm3n3_t* res );
  void feoarrm3n3_set_R(    darr_t* src, feoarrm3n3_t* res );
  void feoarrm3n3_set_O(   oarrm3n3_t* src, feoarrm3n3_t* res );
  void feoarrm3n3_set_F( feoarrm3n3_t* src, feoarrm3n3_t* res );
  feoarrm3n3_t feoarrm3n3_eye( uint64_t size,  uint64_t nip);
  feoarrm3n3_t feoarrm3n3_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm3n3_t feoarrm3n3_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm3n3_t feoarrm3n3_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm3n3_free(feoarrm3n3_t* arr);
  feoarrm3n3_t feoarrm3n3_init();
  ord_t feoarrm3n3_get_order(feoarrm3n3_t* arr);
  
  
  # From ../../../include/oti/static/onumm3n3/array/gauss/utils.h
  
  void feoarrm3n3_dimCheck_FF_samesize(feoarrm3n3_t* arr1, feoarrm3n3_t* arr2, feonumm3n3_t* res);
  void feoarrm3n3_dimCheck_OF_samesize(  oarrm3n3_t* arr1, feoarrm3n3_t* arr2, feonumm3n3_t* res);
  void feoarrm3n3_dimCheck_RF_samesize(   darr_t* arr1, feoarrm3n3_t* arr2, feonumm3n3_t* res);
  void feoarrm3n3_dimCheck_FF_elementwise(feoarrm3n3_t* arr1, feoarrm3n3_t* arr2, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_OF_elementwise(  oarrm3n3_t* arr1, feoarrm3n3_t* arr2, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm3n3_t* arr2, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_fF_elementwise( feonumm3n3_t* num1, feoarrm3n3_t* arr2, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_Ff_elementwise(feoarrm3n3_t* arr1,  feonumm3n3_t* num2, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_FF_matmul( feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_OF_matmul(   oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_RF_matmul(    darr_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_FO_matmul( feoarrm3n3_t* lhs,   oarrm3n3_t* rhs, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_FR_matmul( feoarrm3n3_t* lhs,    darr_t* rhs, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_F_squareness( feoarrm3n3_t* arr1, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_F_transpose( feoarrm3n3_t* arr1, feoarrm3n3_t* res);
  void feoarrm3n3_dimCheck_FfO_integrate(feoarrm3n3_t* arr, feonumm3n3_t* num,oarrm3n3_t* res);
  void feoarrm3n3_get_active_bases(feoarrm3n3_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n3/array/gauss/algebra.h
  
  feoarrm3n3_t feoarrm3n3_neg(    feoarrm3n3_t* arr);
  void      feoarrm3n3_neg_to( feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sum_FF(   feoarrm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sum_FF_to(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sum_fF(    feonumm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sum_fF_to( feonumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sum_OF(     oarrm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sum_OF_to(  oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sum_RF(      darr_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sum_RF_to(   darr_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sum_oF(   onumm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sum_oF_to(onumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sum_rF(     coeff_t  lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sum_rF_to(  coeff_t  lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sub_FF(    feoarrm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sub_FF_to( feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sub_fF(    feonumm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sub_fF_to( feonumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sub_Ff(    feoarrm3n3_t* lhs, feonumm3n3_t* rhs);
  void      feoarrm3n3_sub_Ff_to( feoarrm3n3_t* lhs, feonumm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sub_OF(      oarrm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sub_OF_to(   oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sub_FO(    feoarrm3n3_t* lhs,   oarrm3n3_t* rhs);
  void      feoarrm3n3_sub_FO_to( feoarrm3n3_t* lhs,   oarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sub_RF(       darr_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sub_RF_to(    darr_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sub_FR(    feoarrm3n3_t* lhs,    darr_t* rhs);
  void      feoarrm3n3_sub_FR_to( feoarrm3n3_t* lhs,    darr_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sub_oF(    onumm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sub_oF_to( onumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sub_Fo(    feoarrm3n3_t* lhs, onumm3n3_t* rhs);
  void      feoarrm3n3_sub_Fo_to( feoarrm3n3_t* lhs, onumm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sub_rF(      coeff_t  lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_sub_rF_to(    coeff_t lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_sub_Fr(    feoarrm3n3_t* lhs,   coeff_t  rhs);
  void      feoarrm3n3_sub_Fr_to( feoarrm3n3_t* lhs,   coeff_t  rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_mul_FF(   feoarrm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_mul_FF_to(feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_mul_fF(    feonumm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_mul_fF_to( feonumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_mul_OF(     oarrm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_mul_OF_to(  oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_mul_RF(      darr_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_mul_RF_to(   darr_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_mul_oF(   onumm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_mul_oF_to(onumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_mul_rF(     coeff_t  lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_mul_rF_to(  coeff_t  lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_div_FF(    feoarrm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_div_FF_to( feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_div_fF(     feonumm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_div_fF_to(  feonumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_div_Ff(    feoarrm3n3_t* lhs,  feonumm3n3_t* rhs);
  void      feoarrm3n3_div_Ff_to( feoarrm3n3_t* lhs,  feonumm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_div_OF(      oarrm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_div_OF_to(   oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_div_FO(    feoarrm3n3_t* lhs,   oarrm3n3_t* rhs);
  void      feoarrm3n3_div_FO_to( feoarrm3n3_t* lhs,   oarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_div_RF(       darr_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_div_RF_to(    darr_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_div_FR(    feoarrm3n3_t* lhs,    darr_t* rhs);
  void      feoarrm3n3_div_FR_to( feoarrm3n3_t* lhs,    darr_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_div_oF(    onumm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_div_oF_to( onumm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_div_Fo(    feoarrm3n3_t* lhs, onumm3n3_t* rhs);
  void      feoarrm3n3_div_Fo_to( feoarrm3n3_t* lhs, onumm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_div_rF(      coeff_t  lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_div_rF_to(    coeff_t lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_div_Fr(    feoarrm3n3_t* lhs,   coeff_t  rhs);
  void      feoarrm3n3_div_Fr_to( feoarrm3n3_t* lhs,   coeff_t  rhs, feoarrm3n3_t* res);
  oarrm3n3_t feoarrm3n3_integrate(    feoarrm3n3_t* arr, feonumm3n3_t* w);
  void    feoarrm3n3_integrate_to( feoarrm3n3_t* arr, feonumm3n3_t* w, oarrm3n3_t* res);
  feonumm3n3_t feoarrm3n3_dotproduct_FF(    feoarrm3n3_t* lhs, feoarrm3n3_t* rhs);
  void     feoarrm3n3_dotproduct_FF_to( feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feoarrm3n3_dotproduct_OF(      oarrm3n3_t* lhs, feoarrm3n3_t* rhs);
  void     feoarrm3n3_dotproduct_OF_to(   oarrm3n3_t* lhs, feoarrm3n3_t* rhs, feonumm3n3_t* res);
  feonumm3n3_t feoarrm3n3_dotproduct_RF(       darr_t* lhs, feoarrm3n3_t* rhs);
  void     feoarrm3n3_dotproduct_RF_to(    darr_t* lhs, feoarrm3n3_t* rhs, feonumm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_matmul_FF(    feoarrm3n3_t* lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_matmul_FF_to( feoarrm3n3_t* lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_matmul_OF(    oarrm3n3_t*   lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_matmul_OF_to( oarrm3n3_t*   lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_matmul_FO(    feoarrm3n3_t* lhs, oarrm3n3_t*   rhs);
  void      feoarrm3n3_matmul_FO_to( feoarrm3n3_t* lhs, oarrm3n3_t*   rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_matmul_RF(    darr_t*    lhs, feoarrm3n3_t* rhs);
  void      feoarrm3n3_matmul_RF_to( darr_t*    lhs, feoarrm3n3_t* rhs, feoarrm3n3_t* res);
  feoarrm3n3_t feoarrm3n3_matmul_FR(    feoarrm3n3_t* lhs, darr_t*    rhs);
  void      feoarrm3n3_matmul_FR_to( feoarrm3n3_t* lhs, darr_t*    rhs, feoarrm3n3_t* res);
  feonumm3n3_t feoarrm3n3_det(   feoarrm3n3_t* arr);
  void     feoarrm3n3_det_to(feoarrm3n3_t* arr, feonumm3n3_t* res);
  feonumm3n3_t feoarrm3n3_norm(     feoarrm3n3_t* arr);
  void     feoarrm3n3_norm_to(  feoarrm3n3_t* arr, feonumm3n3_t* res);
  feonumm3n3_t feoarrm3n3_pnorm(    feoarrm3n3_t* arr, coeff_t p);
  void     feoarrm3n3_pnorm_to( feoarrm3n3_t* arr, coeff_t p, feonumm3n3_t* res);
  feoarrm3n3_t   feoarrm3n3_invert(    feoarrm3n3_t* arr);
  void        feoarrm3n3_invert_to( feoarrm3n3_t* arr, feoarrm3n3_t* res);
  feoarrm3n3_t   feoarrm3n3_transpose(   feoarrm3n3_t* arr);
  void        feoarrm3n3_transpose_to(feoarrm3n3_t* arr, feoarrm3n3_t* res);
  
  