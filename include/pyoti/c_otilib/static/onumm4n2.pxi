cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm4n2/scalar/structures.h
  
  ctypedef struct  onumm4n2_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
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
  # } onumm4n2_t;
  
  
  # From ../../../include/oti/static/onumm4n2/array/structures.h
  
  ctypedef struct  oarrm4n2_t : # {
      onumm4n2_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm4n2_t;
  
  
  # From ../../../include/oti/static/onumm4n2/scalar/gauss/structures.h
  
  ctypedef struct  feonumm4n2_t: # {
      onumm4n2_t*  p_data;
      uint64_t    nip;
  # } feonumm4n2_t;
  
  
  # From ../../../include/oti/static/onumm4n2/array/gauss/structures.h
  
  ctypedef struct  feoarrm4n2_t: # {
      oarrm4n2_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm4n2_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm4n2/scalar/functions.h
  
  onumm4n2_t onumm4n2_atanh(onumm4n2_t* num);
  void onumm4n2_atanh_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_asinh(onumm4n2_t* num);
  void onumm4n2_asinh_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_acosh(onumm4n2_t* num);
  void onumm4n2_acosh_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_tanh(onumm4n2_t* num);
  void onumm4n2_tanh_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_sqrt(onumm4n2_t* num);
  void onumm4n2_sqrt_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_cbrt(onumm4n2_t* num);
  void onumm4n2_cbrt_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_cosh(onumm4n2_t* num);
  void onumm4n2_cosh_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_sinh(onumm4n2_t* num);
  void onumm4n2_sinh_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_asin(onumm4n2_t* num);
  void onumm4n2_asin_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_acos(onumm4n2_t* num);
  void onumm4n2_acos_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_atan(onumm4n2_t* num);
  void onumm4n2_atan_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_tan(onumm4n2_t* num);
  void onumm4n2_tan_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_cos(onumm4n2_t* num);
  void onumm4n2_cos_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_sin(onumm4n2_t* num );
  void onumm4n2_sin_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_logb(onumm4n2_t* num, double base);
  void onumm4n2_logb_to(onumm4n2_t* num, double base, onumm4n2_t* res);
  onumm4n2_t onumm4n2_log10(onumm4n2_t* num);
  void onumm4n2_log10_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_log(onumm4n2_t* num);
  void onumm4n2_log_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_exp(onumm4n2_t* num);
  void onumm4n2_exp_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_pow(onumm4n2_t* num, double e);
  void onumm4n2_pow_to(onumm4n2_t* num, coeff_t e, onumm4n2_t* res);
  
  
  # From ../../../include/oti/static/onumm4n2/scalar/base.h
  
  void onumm4n2_set_im_o(onumm4n2_t* num, imdir_t idx, ord_t order, onumm4n2_t* res);
  void onumm4n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm4n2_t* res);
  void onumm4n2_set_deriv_o(onumm4n2_t* num, imdir_t idx, ord_t order, onumm4n2_t* res);
  void onumm4n2_extract_im_to( imdir_t idx, ord_t order, onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_extract_im(imdir_t idx, ord_t order, onumm4n2_t* num);
  onumm4n2_t onumm4n2_extract_deriv(imdir_t idx, ord_t order, onumm4n2_t* num);
  void onumm4n2_extract_deriv_to(imdir_t idx, ord_t order, onumm4n2_t* num, onumm4n2_t* res);
  void onumm4n2_get_im_to_o(imdir_t idx, ord_t order, onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_get_im_o(imdir_t idx, ord_t order, onumm4n2_t* num);
  void onumm4n2_get_im_to_r(imdir_t idx, ord_t order, onumm4n2_t* num, coeff_t* res);
  ord_t onumm4n2_get_order(onumm4n2_t* lhs);
  onumm4n2_t onumm4n2_get_deriv_o( imdir_t idx, ord_t order, onumm4n2_t* num);
  void onumm4n2_get_deriv_to( imdir_t idx, ord_t order, onumm4n2_t* num, onumm4n2_t* res);
  void onumm4n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm4n2_t* res);
  onumm4n2_t onumm4n2_init();
  ndir_t onumm4n2_get_ndir_order(ord_t order, onumm4n2_t* num);
  ndir_t onumm4n2_get_ndir_total(onumm4n2_t* num);
  coeff_t* onumm4n2_get_order_address(ord_t order, onumm4n2_t* num);
  onumm4n2_t onumm4n2_create_r(  coeff_t lhs);
  void onumm4n2_set_r(  coeff_t lhs, onumm4n2_t* res);
  void onumm4n2_set_o(  onumm4n2_t* lhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_get_order_im(ord_t order, onumm4n2_t* lhs);
  void onumm4n2_get_order_im_to(ord_t order, onumm4n2_t* lhs, onumm4n2_t* res);
  coeff_t onumm4n2_get_item(imdir_t idx, ord_t order, onumm4n2_t* lhs);
  coeff_t onumm4n2_get_deriv(imdir_t idx, ord_t order, onumm4n2_t* lhs);
  void onumm4n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm4n2_t* x);
  onumm4n2_t onumm4n2_copy(  onumm4n2_t* lhs);
  void onumm4n2_copy_to(  onumm4n2_t* lhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_taylor_integrate(coeff_t* deltas,onumm4n2_t* lhs);
  void onumm4n2_taylor_integrate_to(coeff_t* deltas,onumm4n2_t* lhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_truncate_im(imdir_t idx, ord_t order, onumm4n2_t* lhs);
  void onumm4n2_truncate_im_to(imdir_t idx, ord_t order, onumm4n2_t* lhs, onumm4n2_t* res);
  void onumm4n2_print(  onumm4n2_t* lhs);
  imdir_t onumm4n2_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm4n2/scalar/utils.h
  
  void onumm4n2_get_active_bases(onumm4n2_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm4n2/scalar/algebra.h
  
  onumm4n2_t onumm4n2_abs(onumm4n2_t* num);
  onumm4n2_t onumm4n2_div_ro(coeff_t num, onumm4n2_t* den);
  onumm4n2_t onumm4n2_div_oo(onumm4n2_t* num, onumm4n2_t* den);
  onumm4n2_t onumm4n2_div_or(onumm4n2_t* num, coeff_t val);
  void onumm4n2_div_ro_to(coeff_t num, onumm4n2_t* den, onumm4n2_t* res);
  void onumm4n2_div_oo_to(onumm4n2_t* num, onumm4n2_t* den, onumm4n2_t* res);
  void onumm4n2_div_or_to(onumm4n2_t* num, coeff_t val, onumm4n2_t* res);
  void onumm4n2_abs_to(onumm4n2_t* num, onumm4n2_t* res);
  onumm4n2_t onumm4n2_neg(  onumm4n2_t* lhs);
  void onumm4n2_neg_to(  onumm4n2_t* lhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_sum_oo(  onumm4n2_t* lhs,  onumm4n2_t* rhs);
  void onumm4n2_sum_oo_to(  onumm4n2_t* lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_sum_ro(  coeff_t lhs,  onumm4n2_t* rhs);
  void onumm4n2_sum_ro_to(  coeff_t lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_sub_oo(  onumm4n2_t* lhs,  onumm4n2_t* rhs);
  void onumm4n2_sub_oo_to(  onumm4n2_t* lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_sub_ro(  coeff_t lhs,  onumm4n2_t* rhs);
  void onumm4n2_sub_ro_to(  coeff_t lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_sub_or(  onumm4n2_t* lhs,  coeff_t rhs);
  void onumm4n2_sub_or_to(  onumm4n2_t* lhs,  coeff_t rhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_mul_oo(  onumm4n2_t* lhs,  onumm4n2_t* rhs);
  void onumm4n2_mul_oo_to(  onumm4n2_t* lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_mul_ro(  coeff_t lhs,  onumm4n2_t* rhs);
  void onumm4n2_mul_ro_to(  coeff_t lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_trunc_mul_oo(  onumm4n2_t* lhs,  onumm4n2_t* rhs);
  void onumm4n2_trunc_mul_oo_to(  onumm4n2_t* lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
  onumm4n2_t onumm4n2_gem_oo(  onumm4n2_t* a,  onumm4n2_t* b,  onumm4n2_t* c);
  void onumm4n2_gem_oo_to(  onumm4n2_t* a,  onumm4n2_t* b,  onumm4n2_t* c, onumm4n2_t* res);
  onumm4n2_t onumm4n2_gem_ro(  coeff_t a,  onumm4n2_t* b,  onumm4n2_t* c);
  void onumm4n2_gem_ro_to(  coeff_t a,  onumm4n2_t* b,  onumm4n2_t* c, onumm4n2_t* res);
  void onumm4n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm4n2_t* a,  ord_t ord_rhs,  onumm4n2_t* b,  onumm4n2_t* c, onumm4n2_t* res);
  onumm4n2_t onumm4n2_feval(coeff_t* feval_re, onumm4n2_t* x);
  void onumm4n2_feval_to(coeff_t* feval_re, onumm4n2_t* x, onumm4n2_t* res);
  
  
  # From ../../../include/oti/static/onumm4n2/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm4n2/scalar/gauss/functions.h
  
  feonumm4n2_t feonumm4n2_atanh(    feonumm4n2_t* num);
  void     feonumm4n2_atanh_to( feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_asinh(    feonumm4n2_t* num);
  void     feonumm4n2_asinh_to( feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_acosh(    feonumm4n2_t* num);
  void     feonumm4n2_acosh_to( feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_tanh(     feonumm4n2_t* num);
  void     feonumm4n2_tanh_to(  feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_cosh(     feonumm4n2_t* num);
  void     feonumm4n2_cosh_to(  feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_sinh(     feonumm4n2_t* num);
  void     feonumm4n2_sinh_to(  feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_asin(     feonumm4n2_t* num);
  void     feonumm4n2_asin_to(  feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_acos(     feonumm4n2_t* num);
  void     feonumm4n2_acos_to(  feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_atan(     feonumm4n2_t* num);
  void     feonumm4n2_atan_to(  feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_tan(      feonumm4n2_t* num);
  void     feonumm4n2_tan_to(   feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_cos(      feonumm4n2_t* num);
  void     feonumm4n2_cos_to(   feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_sin(      feonumm4n2_t* num);
  void     feonumm4n2_sin_to(   feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_logb(     feonumm4n2_t* num, double base);
  void     feonumm4n2_logb_to(  feonumm4n2_t* num, double base, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_log10(    feonumm4n2_t* num);
  void     feonumm4n2_log10_to( feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_log(      feonumm4n2_t* num);
  void     feonumm4n2_log_to(   feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_exp(      feonumm4n2_t* num);
  void     feonumm4n2_exp_to(   feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_cbrt(     feonumm4n2_t* num);
  void     feonumm4n2_cbrt_to(  feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_sqrt(     feonumm4n2_t* num);
  void     feonumm4n2_sqrt_to(  feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_pow(      feonumm4n2_t* num, double e);
  void     feonumm4n2_pow_to(   feonumm4n2_t* num, double e, feonumm4n2_t* res);
  onumm4n2_t feonumm4n2_integrate(       feonumm4n2_t* num, feonumm4n2_t* w);
  void      feonumm4n2_integrate_to(    feonumm4n2_t* num, feonumm4n2_t* w, onumm4n2_t* res);
  onumm4n2_t feonumm4n2_integrate_f(     feonumm4n2_t* num, feonumm4n2_t* w);
  void      feonumm4n2_integrate_f_to(  feonumm4n2_t* num, feonumm4n2_t* w, onumm4n2_t* res);
  onumm4n2_t feonumm4n2_integrate_r(       coeff_t num, feonumm4n2_t* w);
  void      feonumm4n2_integrate_r_to(    coeff_t num, feonumm4n2_t* w, onumm4n2_t* res);
  onumm4n2_t feonumm4n2_integrate_o(    onumm4n2_t* num, feonumm4n2_t* w);
  void      feonumm4n2_integrate_o_to( onumm4n2_t* num, feonumm4n2_t* w, onumm4n2_t* res);
  
  
  # From ../../../include/oti/static/onumm4n2/scalar/gauss/base.h
  
  void     feonumm4n2_get_order_im_to( ord_t order, feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_get_order_im(    ord_t order, feonumm4n2_t* num);
  feonumm4n2_t feonumm4n2_get_im(    imdir_t idx, ord_t order, feonumm4n2_t* num);
  void     feonumm4n2_get_im_to( imdir_t idx, ord_t order, feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_get_deriv(    imdir_t idx, ord_t order, feonumm4n2_t* num);
  void     feonumm4n2_get_deriv_to( imdir_t idx, ord_t order, feonumm4n2_t* num, feonumm4n2_t* res);
  void feonumm4n2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm4n2_t* num);
  void feonumm4n2_set_im_o( onumm4n2_t* val, imdir_t idx, ord_t order, feonumm4n2_t* num);
  void feonumm4n2_set_im_f(  feonumm4n2_t* val, imdir_t idx, ord_t order, feonumm4n2_t* num);
  void feonumm4n2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm4n2_t* num);
  void feonumm4n2_set_deriv_o( onumm4n2_t* val, imdir_t idx, ord_t order, feonumm4n2_t* num);
  void feonumm4n2_set_deriv_f(  feonumm4n2_t* val, imdir_t idx, ord_t order, feonumm4n2_t* num);
  feonumm4n2_t feonumm4n2_extract_im(    imdir_t idx, ord_t order, feonumm4n2_t* num);
  void     feonumm4n2_extract_im_to( imdir_t idx, ord_t order, feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_extract_deriv(    imdir_t idx, ord_t order, feonumm4n2_t* num);
  void     feonumm4n2_extract_deriv_to( imdir_t idx, ord_t order, feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_truncate_im(    imdir_t idx, ord_t order, feonumm4n2_t* num);
  void     feonumm4n2_truncate_im_to( imdir_t idx, ord_t order, feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_copy(    feonumm4n2_t* src);
  void     feonumm4n2_copy_to( feonumm4n2_t* src, feonumm4n2_t* dst);
  void feonumm4n2_set_r(    coeff_t num, feonumm4n2_t* res);
  void feonumm4n2_set_o( onumm4n2_t* num, feonumm4n2_t* res);
  void feonumm4n2_set_f(  feonumm4n2_t* num, feonumm4n2_t* res);
  void feonumm4n2_set_item_k_r(   coeff_t  num, uint64_t k, feonumm4n2_t* res);
  void feonumm4n2_set_item_k_o( onumm4n2_t* num, uint64_t k, feonumm4n2_t* res);
  onumm4n2_t feonumm4n2_get_item_k(   feonumm4n2_t* num, uint64_t k);
  void      feonumm4n2_get_item_k_to(feonumm4n2_t* num, uint64_t k, onumm4n2_t* res);
  feonumm4n2_t feonumm4n2_zeros(uint64_t nIntPts);
  feonumm4n2_t feonumm4n2_createEmpty(uint64_t nIntPts);
  feonumm4n2_t feonumm4n2_empty_like(feonumm4n2_t* arr);
  void feonumm4n2_free(feonumm4n2_t* num);
  ord_t feonumm4n2_get_order( feonumm4n2_t* num );
  feonumm4n2_t feonumm4n2_init();
  
  
  # From ../../../include/oti/static/onumm4n2/scalar/gauss/utils.h
  
  void feonumm4n2_dimCheck(feonumm4n2_t* arr1,feonumm4n2_t* arr2);
  void feonumm4n2_get_active_bases(feonumm4n2_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n2/scalar/gauss/algebra.h
  
  feonumm4n2_t feonumm4n2_neg(   feonumm4n2_t* num);
  void     feonumm4n2_neg_to(feonumm4n2_t* num, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_sum_ff(   feonumm4n2_t* lhs, feonumm4n2_t* rhs);
  void     feonumm4n2_sum_ff_to(feonumm4n2_t* lhs, feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_sum_of(   onumm4n2_t* lhs, feonumm4n2_t* rhs);
  void     feonumm4n2_sum_of_to(onumm4n2_t* lhs, feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_sum_rf(   coeff_t lhs, feonumm4n2_t* rhs);
  void     feonumm4n2_sum_rf_to(coeff_t lhs, feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_sub_ff(     feonumm4n2_t* lhs,  feonumm4n2_t* rhs);
  void     feonumm4n2_sub_ff_to(  feonumm4n2_t* lhs,  feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_sub_of(    onumm4n2_t* lhs,  feonumm4n2_t* rhs);
  void     feonumm4n2_sub_of_to( onumm4n2_t* lhs,  feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_sub_fo(     feonumm4n2_t* lhs, onumm4n2_t* rhs);
  void     feonumm4n2_sub_fo_to(  feonumm4n2_t* lhs, onumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_sub_rf(       coeff_t lhs,  feonumm4n2_t* rhs);
  void     feonumm4n2_sub_rf_to(    coeff_t lhs,  feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_sub_fr(     feonumm4n2_t* lhs,    coeff_t rhs);
  void     feonumm4n2_sub_fr_to(  feonumm4n2_t* lhs,    coeff_t rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_mul_ff(   feonumm4n2_t* lhs, feonumm4n2_t* rhs);
  void     feonumm4n2_mul_ff_to(feonumm4n2_t* lhs, feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_mul_of(   onumm4n2_t* lhs, feonumm4n2_t* rhs);
  void     feonumm4n2_mul_of_to(onumm4n2_t* lhs, feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_mul_rf(   coeff_t lhs, feonumm4n2_t* rhs);
  void     feonumm4n2_mul_rf_to(coeff_t lhs, feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_div_ff(     feonumm4n2_t* lhs,  feonumm4n2_t* rhs);
  void     feonumm4n2_div_ff_to(  feonumm4n2_t* lhs,  feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_div_of(    onumm4n2_t* lhs,  feonumm4n2_t* rhs);
  void     feonumm4n2_div_of_to( onumm4n2_t* lhs,  feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_div_fo(     feonumm4n2_t* lhs, onumm4n2_t* rhs);
  void     feonumm4n2_div_fo_to(  feonumm4n2_t* lhs, onumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_div_rf(       coeff_t lhs,  feonumm4n2_t* rhs);
  void     feonumm4n2_div_rf_to(    coeff_t lhs,  feonumm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feonumm4n2_div_fr(     feonumm4n2_t* lhs,    coeff_t rhs);
  void     feonumm4n2_div_fr_to(  feonumm4n2_t* lhs,    coeff_t rhs, feonumm4n2_t* res);
  
  
  # From ../../../include/oti/static/onumm4n2/array/functions.h
  
  oarrm4n2_t oarrm4n2_atanh(   oarrm4n2_t* arr);
  void    oarrm4n2_atanh_to(oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_asinh(   oarrm4n2_t* arr);
  void    oarrm4n2_asinh_to(oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_acosh(   oarrm4n2_t* arr);
  void    oarrm4n2_acosh_to(oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_tanh(    oarrm4n2_t* arr);
  void    oarrm4n2_tanh_to( oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_cbrt(    oarrm4n2_t* arr);
  void    oarrm4n2_cbrt_to( oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_sqrt(    oarrm4n2_t* arr);
  void    oarrm4n2_sqrt_to( oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_cosh(    oarrm4n2_t* arr);
  void    oarrm4n2_cosh_to( oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_sinh(    oarrm4n2_t* arr);
  void    oarrm4n2_sinh_to( oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_asin(    oarrm4n2_t* arr);
  void    oarrm4n2_asin_to( oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_acos(    oarrm4n2_t* arr);
  void    oarrm4n2_acos_to( oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_atan(    oarrm4n2_t* arr);
  void    oarrm4n2_atan_to( oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_tan(     oarrm4n2_t* arr);
  void    oarrm4n2_tan_to(  oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_cos(     oarrm4n2_t* arr);
  void    oarrm4n2_cos_to(  oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_sin(     oarrm4n2_t* arr);
  void    oarrm4n2_sin_to(  oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_logb(    oarrm4n2_t* arr, double base);
  void    oarrm4n2_logb_to( oarrm4n2_t* arr, double base, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_log10(   oarrm4n2_t* arr);
  void    oarrm4n2_log10_to(oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_log(     oarrm4n2_t* arr);
  void    oarrm4n2_log_to(  oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_exp(     oarrm4n2_t* arr);
  void    oarrm4n2_exp_to(  oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_pow(     oarrm4n2_t* arr, double e);
  void    oarrm4n2_pow_to(  oarrm4n2_t* arr, double e, oarrm4n2_t* res);
  
  
  # From ../../../include/oti/static/onumm4n2/array/algebra_elementwise.h
  
  oarrm4n2_t oarrm4n2_neg(oarrm4n2_t* arr);
  void oarrm4n2_neg_to(oarrm4n2_t* rhs, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_sum_OO(oarrm4n2_t*   lhs, oarrm4n2_t* rhs);
  oarrm4n2_t oarrm4n2_sum_RO(darr_t*    lhs, oarrm4n2_t* rhs);
  oarrm4n2_t oarrm4n2_sum_oO(onumm4n2_t* lhs, oarrm4n2_t* rhs);
  oarrm4n2_t oarrm4n2_sum_rO(coeff_t    lhs, oarrm4n2_t* rhs);
  void oarrm4n2_sum_OO_to(oarrm4n2_t*   lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
  void oarrm4n2_sum_RO_to(darr_t*    lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
  void oarrm4n2_sum_oO_to(onumm4n2_t* lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
  void oarrm4n2_sum_rO_to(coeff_t    lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_sub_OO(oarrm4n2_t*   lhs, oarrm4n2_t*   rhs);
  oarrm4n2_t oarrm4n2_sub_RO(darr_t*    lhs, oarrm4n2_t*   rhs);
  oarrm4n2_t oarrm4n2_sub_OR(oarrm4n2_t*   lhs, darr_t*    rhs);
  oarrm4n2_t oarrm4n2_sub_oO(onumm4n2_t* lhs, oarrm4n2_t*   rhs);
  oarrm4n2_t oarrm4n2_sub_Oo(oarrm4n2_t*   lhs, onumm4n2_t* rhs);
  oarrm4n2_t oarrm4n2_sub_rO(coeff_t    lhs, oarrm4n2_t*   rhs);
  oarrm4n2_t oarrm4n2_sub_Or(oarrm4n2_t*   lhs, coeff_t    rhs);
  void oarrm4n2_sub_OO_to( oarrm4n2_t*   lhs, oarrm4n2_t*   rhs, oarrm4n2_t* res);
  void oarrm4n2_sub_RO_to( darr_t*    lhs, oarrm4n2_t*   rhs, oarrm4n2_t* res);
  void oarrm4n2_sub_OR_to( oarrm4n2_t*   lhs, darr_t*    rhs, oarrm4n2_t* res);
  void oarrm4n2_sub_oO_to( onumm4n2_t* lhs, oarrm4n2_t*   rhs, oarrm4n2_t* res);
  void oarrm4n2_sub_Oo_to( oarrm4n2_t*   lhs, onumm4n2_t* rhs, oarrm4n2_t* res);
  void oarrm4n2_sub_rO_to( coeff_t    lhs, oarrm4n2_t*   rhs, oarrm4n2_t* res);
  void oarrm4n2_sub_Or_to( oarrm4n2_t*   lhs, coeff_t    rhs, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_mul_OO(oarrm4n2_t*   lhs, oarrm4n2_t* rhs);
  oarrm4n2_t oarrm4n2_mul_RO(darr_t*    lhs, oarrm4n2_t* rhs);
  oarrm4n2_t oarrm4n2_mul_oO(onumm4n2_t* lhs, oarrm4n2_t* rhs);
  oarrm4n2_t oarrm4n2_mul_rO(coeff_t    lhs, oarrm4n2_t* rhs);
  void oarrm4n2_mul_OO_to(oarrm4n2_t*   lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
  void oarrm4n2_mul_RO_to(darr_t*    lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
  void oarrm4n2_mul_oO_to(onumm4n2_t* lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
  void oarrm4n2_mul_rO_to(coeff_t    lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
  void oarrm4n2_gem_OO_to(  oarrm4n2_t* arr1, oarrm4n2_t* arr2, oarrm4n2_t* arr3, oarrm4n2_t* res);
  void oarrm4n2_gem_oO_to(onumm4n2_t* arr1, oarrm4n2_t* arr2, oarrm4n2_t* arr3, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_div_OO(oarrm4n2_t*   lhs, oarrm4n2_t*   rhs);
  oarrm4n2_t oarrm4n2_div_OR(oarrm4n2_t*   lhs, darr_t*    rhs);
  oarrm4n2_t oarrm4n2_div_RO(darr_t*    lhs, oarrm4n2_t*   rhs);
  oarrm4n2_t oarrm4n2_div_oO(onumm4n2_t* lhs, oarrm4n2_t*   rhs);
  oarrm4n2_t oarrm4n2_div_Oo(oarrm4n2_t*   lhs, onumm4n2_t* rhs);
  oarrm4n2_t oarrm4n2_div_rO(coeff_t    lhs, oarrm4n2_t*   rhs);
  oarrm4n2_t oarrm4n2_div_Or(oarrm4n2_t*   lhs, coeff_t    rhs);
  void oarrm4n2_div_OO_to(oarrm4n2_t*   lhs, oarrm4n2_t*   rhs, oarrm4n2_t* res);
  void oarrm4n2_div_RO_to(darr_t*    lhs, oarrm4n2_t*   rhs, oarrm4n2_t* res);
  void oarrm4n2_div_OR_to(oarrm4n2_t*   lhs, darr_t*    rhs, oarrm4n2_t* res);
  void oarrm4n2_div_oO_to(onumm4n2_t* lhs, oarrm4n2_t*   rhs, oarrm4n2_t* res);
  void oarrm4n2_div_Oo_to(oarrm4n2_t*   lhs, onumm4n2_t* rhs, oarrm4n2_t* res);
  void oarrm4n2_div_rO_to(coeff_t    lhs, oarrm4n2_t*   rhs, oarrm4n2_t* res);
  void oarrm4n2_div_Or_to(oarrm4n2_t*   lhs, coeff_t    rhs, oarrm4n2_t* res);
  
  
  # From ../../../include/oti/static/onumm4n2/array/base.h
  
  void    oarrm4n2_taylor_integrate_to( coeff_t* deltas, oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_taylor_integrate(    coeff_t* deltas, oarrm4n2_t* arr);
  void    oarrm4n2_get_order_im_to( ord_t order, oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_get_order_im(    ord_t order, oarrm4n2_t* arr);
  void oarrm4n2_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n2_t* res);
  void oarrm4n2_set_slice_O( oarrm4n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n2_t* res);
  void oarrm4n2_set_slice_o( onumm4n2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_get_slice( oarrm4n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm4n2_get_slice_to( oarrm4n2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_truncate_im(    imdir_t idx, ord_t order, oarrm4n2_t* arr);
  void    oarrm4n2_truncate_im_to( imdir_t idx, ord_t order, oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_extract_im(   imdir_t idx, ord_t order, oarrm4n2_t* arr);
  void    oarrm4n2_extract_im_to(imdir_t idx, ord_t order, oarrm4n2_t* arr, oarrm4n2_t* res);
  darr_t  oarrm4n2_get_deriv(    imdir_t idx, ord_t order, oarrm4n2_t* arr);
  void    oarrm4n2_get_deriv_to( imdir_t idx, ord_t order, oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_get_deriv_o(  imdir_t idx, ord_t order, oarrm4n2_t* arr);
  oarrm4n2_t oarrm4n2_extract_deriv(    imdir_t idx, ord_t order, oarrm4n2_t* arr);
  void    oarrm4n2_extract_deriv_to( imdir_t idx, ord_t order, oarrm4n2_t* arr, oarrm4n2_t* res);
  darr_t  oarrm4n2_get_im(   imdir_t idx, ord_t order, oarrm4n2_t* arr);
  oarrm4n2_t oarrm4n2_get_im_o( imdir_t idx, ord_t order, oarrm4n2_t* arr);
  void    oarrm4n2_get_im_to(imdir_t idx, ord_t order, oarrm4n2_t* arr, oarrm4n2_t* res);
  void    oarrm4n2_copy_to(oarrm4n2_t* arr, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_copy(oarrm4n2_t* arr);
  void oarrm4n2_set_all_r( coeff_t num, oarrm4n2_t* arr);
  void oarrm4n2_set_item_i_r( coeff_t num, uint64_t i, oarrm4n2_t* arr);
  void oarrm4n2_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm4n2_t* arr);
  void oarrm4n2_set_r(   coeff_t  num,   oarrm4n2_t* arr);
  void oarrm4n2_set_o( onumm4n2_t* num,   oarrm4n2_t* arr);
  void oarrm4n2_set_O(   oarrm4n2_t* arrin, oarrm4n2_t* arr);
  void oarrm4n2_set_all_o( onumm4n2_t* src, oarrm4n2_t* arr);
  void oarrm4n2_set_item_i_o( onumm4n2_t* num, uint64_t i, oarrm4n2_t* arr);
  void oarrm4n2_set_item_ij_o( onumm4n2_t* num, uint64_t i, uint64_t j, oarrm4n2_t* arr);
  onumm4n2_t oarrm4n2_get_item_i(    oarrm4n2_t* arr, uint64_t i);
  void      oarrm4n2_get_item_i_to( oarrm4n2_t* arr, uint64_t i,             onumm4n2_t* res);
  onumm4n2_t oarrm4n2_get_item_ij(   oarrm4n2_t* arr, uint64_t i, uint64_t j);
  void      oarrm4n2_get_item_ij_to(oarrm4n2_t* arr, uint64_t i, uint64_t j, onumm4n2_t* res);
  oarrm4n2_t oarrm4n2_init();
  void oarrm4n2_free(oarrm4n2_t* arr);
  oarrm4n2_t oarrm4n2_empty_like(oarrm4n2_t* arr);
  oarrm4n2_t oarrm4n2_eye(uint64_t nrows);
  oarrm4n2_t oarrm4n2_ones(uint64_t nrows, uint64_t ncols);
  oarrm4n2_t oarrm4n2_zeros(uint64_t nrows, uint64_t ncols);
  oarrm4n2_t oarrm4n2_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm4n2/array/utils.h
  
  void oarrm4n2_dimCheck_OO_elementwise(oarrm4n2_t* arr1, oarrm4n2_t* arr2, oarrm4n2_t* res);
  void oarrm4n2_dimCheck_RO_elementwise(darr_t*  arr1, oarrm4n2_t* arr2, oarrm4n2_t* res);
  void oarrm4n2_dimCheck_OO_matmul(oarrm4n2_t* arr1, oarrm4n2_t* arr2, oarrm4n2_t* res);
  void oarrm4n2_dimCheck_RO_matmul(darr_t*  arr1, oarrm4n2_t* arr2, oarrm4n2_t* res);
  void oarrm4n2_dimCheck_OR_matmul(oarrm4n2_t* arr1, darr_t*  arr2, oarrm4n2_t* res);
  void oarrm4n2_dimCheck_O_squareness(oarrm4n2_t* arr1, oarrm4n2_t* res);
  void oarrm4n2_dimCheck_OO_samesize(oarrm4n2_t* arr1, oarrm4n2_t* res);
  void oarrm4n2_dimCheck_RO_samesize(darr_t* arr1, oarrm4n2_t* res);
  ord_t oarrm4n2_get_order(oarrm4n2_t* arr);
  void oarrm4n2_get_active_bases(oarrm4n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n2/array/algebra_matops.h
  
  onumm4n2_t oarrm4n2_dotproduct_OO(    oarrm4n2_t* lhs, oarrm4n2_t* rhs);
  void      oarrm4n2_dotproduct_OO_to( oarrm4n2_t* lhs, oarrm4n2_t* rhs, onumm4n2_t* res);
  onumm4n2_t oarrm4n2_dotproduct_RO(     darr_t* lhs, oarrm4n2_t* rhs);
  void      oarrm4n2_dotproduct_RO_to(  darr_t* lhs, oarrm4n2_t* rhs, onumm4n2_t* res);
  oarrm4n2_t oarrm4n2_matmul_OO(    oarrm4n2_t* lhs, oarrm4n2_t* rhs);
  oarrm4n2_t oarrm4n2_matmul_OR(    oarrm4n2_t* lhs,  darr_t* rhs);
  oarrm4n2_t oarrm4n2_matmul_RO(     darr_t* lhs, oarrm4n2_t* rhs);
  void    oarrm4n2_matmul_OO_to( oarrm4n2_t* lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
  void    oarrm4n2_matmul_OR_to( oarrm4n2_t* lhs,  darr_t* rhs, oarrm4n2_t* res);
  void    oarrm4n2_matmul_RO_to(  darr_t* lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_transpose(    oarrm4n2_t* arr1);
  void    oarrm4n2_transpose_to( oarrm4n2_t* arr1, oarrm4n2_t* res);
  oarrm4n2_t oarrm4n2_invert(    oarrm4n2_t* arr1);
  void    oarrm4n2_invert_to( oarrm4n2_t* arr1, oarrm4n2_t* res);
  onumm4n2_t oarrm4n2_det(    oarrm4n2_t* arr1);
  void      oarrm4n2_det_to( oarrm4n2_t* arr1, onumm4n2_t* res);
  onumm4n2_t oarrm4n2_norm(    oarrm4n2_t* arr1);
  void      oarrm4n2_norm_to( oarrm4n2_t* arr1,  onumm4n2_t* res);
  onumm4n2_t oarrm4n2_pnorm(    oarrm4n2_t* arr1, coeff_t p);
  void      oarrm4n2_pnorm_to( oarrm4n2_t* arr1, coeff_t p, onumm4n2_t* res);
  
  
  # From ../../../include/oti/static/onumm4n2/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm4n2/array/gauss/functions.h
  
  feoarrm4n2_t feoarrm4n2_atanh(    feoarrm4n2_t* arr);
  void      feoarrm4n2_atanh_to( feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_asinh(    feoarrm4n2_t* arr);
  void      feoarrm4n2_asinh_to( feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_acosh(    feoarrm4n2_t* arr);
  void      feoarrm4n2_acosh_to( feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_tanh(     feoarrm4n2_t* arr);
  void      feoarrm4n2_tanh_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sinh(     feoarrm4n2_t* arr);
  void      feoarrm4n2_sinh_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_cosh(     feoarrm4n2_t* arr);
  void      feoarrm4n2_cosh_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_atan(     feoarrm4n2_t* arr);
  void      feoarrm4n2_atan_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_asin(     feoarrm4n2_t* arr);
  void      feoarrm4n2_asin_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_acos(     feoarrm4n2_t* arr);
  void      feoarrm4n2_acos_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_tan(      feoarrm4n2_t* arr);
  void      feoarrm4n2_tan_to(   feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sin(      feoarrm4n2_t* arr);
  void      feoarrm4n2_sin_to(   feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_cos(      feoarrm4n2_t* arr);
  void      feoarrm4n2_cos_to(   feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_logb(     feoarrm4n2_t* arr, double base);
  void      feoarrm4n2_logb_to(  feoarrm4n2_t* arr, double base, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_log10(    feoarrm4n2_t* arr);
  void      feoarrm4n2_log10_to( feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_log(      feoarrm4n2_t* arr);
  void      feoarrm4n2_log_to(   feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_exp(      feoarrm4n2_t* arr);
  void      feoarrm4n2_exp_to(   feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_cbrt(     feoarrm4n2_t* arr);
  void      feoarrm4n2_cbrt_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sqrt(     feoarrm4n2_t* arr);
  void      feoarrm4n2_sqrt_to(  feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_pow(      feoarrm4n2_t* arr, double e);
  void      feoarrm4n2_pow_to(   feoarrm4n2_t* arr, double e, feoarrm4n2_t* res);
  
  
  # From ../../../include/oti/static/onumm4n2/array/gauss/base.h
  
  void      feoarrm4n2_get_order_im_to( ord_t order, feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_get_order_im(    ord_t order, feoarrm4n2_t* arr);
  feoarrm4n2_t feoarrm4n2_get_deriv(   imdir_t idx, ord_t order, feoarrm4n2_t* arr);
  void      feoarrm4n2_get_deriv_to(imdir_t idx, ord_t order, feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_get_im(      imdir_t idx, ord_t order, feoarrm4n2_t* arr);
  void      feoarrm4n2_get_im_to(   imdir_t idx, ord_t order, feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_truncate_im(   imdir_t idx, ord_t order, feoarrm4n2_t* arr);
  void      feoarrm4n2_truncate_im_to(imdir_t idx, ord_t order, feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_copy(   feoarrm4n2_t* src);
  void      feoarrm4n2_copy_to(feoarrm4n2_t* src, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_get_im(    imdir_t idx, ord_t order, feoarrm4n2_t* arr);
  void      feoarrm4n2_get_im_to( imdir_t idx, ord_t order, feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_get_deriv(    imdir_t idx, ord_t order, feoarrm4n2_t* arr);
  void      feoarrm4n2_get_deriv_to( imdir_t idx, ord_t order, feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_extract_im(    imdir_t idx, ord_t order, feoarrm4n2_t* arr);
  void      feoarrm4n2_extract_im_to( imdir_t idx, ord_t order, feoarrm4n2_t* arr,  feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_extract_deriv(    imdir_t idx, ord_t order, feoarrm4n2_t* arr);
  void      feoarrm4n2_extract_deriv_to( imdir_t idx, ord_t order, feoarrm4n2_t* arr, feoarrm4n2_t* res);
  oarrm4n2_t   feoarrm4n2_get_item_k(  feoarrm4n2_t* arr, uint64_t k);
  feonumm4n2_t  feoarrm4n2_get_item_ij( feoarrm4n2_t* arr, uint64_t i, uint64_t j);
  onumm4n2_t feoarrm4n2_get_item_ijk(feoarrm4n2_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm4n2_get_item_ij_to(  feoarrm4n2_t* arr, uint64_t i, uint64_t j,
                                 feonumm4n2_t* res);
  void feoarrm4n2_get_item_k_to(   feoarrm4n2_t* arr, uint64_t k,
                                  oarrm4n2_t* res);
  void feoarrm4n2_get_item_ijk_to( feoarrm4n2_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_get_slice(feoarrm4n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm4n2_get_slice_to(feoarrm4n2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n2_t* res);
  void feoarrm4n2_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm4n2_t* res);
  void feoarrm4n2_set_item_ij_o(  onumm4n2_t* elm, uint64_t i, uint64_t j,
                               feoarrm4n2_t* res);
  void feoarrm4n2_set_item_ij_f(  feonumm4n2_t* elm, uint64_t i, uint64_t j,
                              feoarrm4n2_t* res);
  void feoarrm4n2_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm4n2_t* res);
  void feoarrm4n2_set_item_k_o(  onumm4n2_t* elm, uint64_t k,
                              feoarrm4n2_t* res);
  void feoarrm4n2_set_item_k_R(    oarrm4n2_t* elm, uint64_t k,
                            feoarrm4n2_t* res);
  void feoarrm4n2_set_item_k_O(    oarrm4n2_t* elm, uint64_t k,
                            feoarrm4n2_t* res);
  void feoarrm4n2_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm4n2_t* res);
  void feoarrm4n2_set_item_ijk_o( onumm4n2_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm4n2_t* res);
  void feoarrm4n2_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n2_t* res);
  void feoarrm4n2_set_slice_o( onumm4n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n2_t* res);
  void feoarrm4n2_set_slice_f( feonumm4n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n2_t* res);
  void feoarrm4n2_set_slice_O( oarrm4n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n2_t* res);
  void feoarrm4n2_set_slice_F( feoarrm4n2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n2_t* res);
  void feoarrm4n2_set_all_o( onumm4n2_t* num, feoarrm4n2_t* arr );
  void feoarrm4n2_set_all_r(   coeff_t  num, feoarrm4n2_t* arr );
  void feoarrm4n2_set_all_f(  feonumm4n2_t* num, feoarrm4n2_t* arr );
  void feoarrm4n2_set_r(    coeff_t src, feoarrm4n2_t* res );
  void feoarrm4n2_set_o( onumm4n2_t* src, feoarrm4n2_t* res );
  void feoarrm4n2_set_f(  feonumm4n2_t* src, feoarrm4n2_t* res );
  void feoarrm4n2_set_R(    darr_t* src, feoarrm4n2_t* res );
  void feoarrm4n2_set_O(   oarrm4n2_t* src, feoarrm4n2_t* res );
  void feoarrm4n2_set_F( feoarrm4n2_t* src, feoarrm4n2_t* res );
  feoarrm4n2_t feoarrm4n2_eye( uint64_t size,  uint64_t nip);
  feoarrm4n2_t feoarrm4n2_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm4n2_t feoarrm4n2_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm4n2_t feoarrm4n2_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm4n2_free(feoarrm4n2_t* arr);
  feoarrm4n2_t feoarrm4n2_init();
  ord_t feoarrm4n2_get_order(feoarrm4n2_t* arr);
  
  
  # From ../../../include/oti/static/onumm4n2/array/gauss/utils.h
  
  void feoarrm4n2_dimCheck_FF_samesize(feoarrm4n2_t* arr1, feoarrm4n2_t* arr2, feonumm4n2_t* res);
  void feoarrm4n2_dimCheck_OF_samesize(  oarrm4n2_t* arr1, feoarrm4n2_t* arr2, feonumm4n2_t* res);
  void feoarrm4n2_dimCheck_RF_samesize(   darr_t* arr1, feoarrm4n2_t* arr2, feonumm4n2_t* res);
  void feoarrm4n2_dimCheck_FF_elementwise(feoarrm4n2_t* arr1, feoarrm4n2_t* arr2, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_OF_elementwise(  oarrm4n2_t* arr1, feoarrm4n2_t* arr2, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm4n2_t* arr2, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_fF_elementwise( feonumm4n2_t* num1, feoarrm4n2_t* arr2, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_Ff_elementwise(feoarrm4n2_t* arr1,  feonumm4n2_t* num2, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_FF_matmul( feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_OF_matmul(   oarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_FO_matmul( feoarrm4n2_t* lhs,   oarrm4n2_t* rhs, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_FR_matmul( feoarrm4n2_t* lhs,    darr_t* rhs, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_F_squareness( feoarrm4n2_t* arr1, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_F_transpose( feoarrm4n2_t* arr1, feoarrm4n2_t* res);
  void feoarrm4n2_dimCheck_FfO_integrate(feoarrm4n2_t* arr, feonumm4n2_t* num,oarrm4n2_t* res);
  void feoarrm4n2_get_active_bases(feoarrm4n2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n2/array/gauss/algebra.h
  
  feoarrm4n2_t feoarrm4n2_neg(    feoarrm4n2_t* arr);
  void      feoarrm4n2_neg_to( feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sum_FF(   feoarrm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sum_FF_to(feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sum_fF(    feonumm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sum_fF_to( feonumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sum_OF(     oarrm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sum_OF_to(  oarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sum_RF(      darr_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sum_RF_to(   darr_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sum_oF(   onumm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sum_oF_to(onumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sum_rF(     coeff_t  lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sum_rF_to(  coeff_t  lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sub_FF(    feoarrm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sub_FF_to( feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sub_fF(    feonumm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sub_fF_to( feonumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sub_Ff(    feoarrm4n2_t* lhs, feonumm4n2_t* rhs);
  void      feoarrm4n2_sub_Ff_to( feoarrm4n2_t* lhs, feonumm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sub_OF(      oarrm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sub_OF_to(   oarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sub_FO(    feoarrm4n2_t* lhs,   oarrm4n2_t* rhs);
  void      feoarrm4n2_sub_FO_to( feoarrm4n2_t* lhs,   oarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sub_RF(       darr_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sub_RF_to(    darr_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sub_FR(    feoarrm4n2_t* lhs,    darr_t* rhs);
  void      feoarrm4n2_sub_FR_to( feoarrm4n2_t* lhs,    darr_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sub_oF(    onumm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sub_oF_to( onumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sub_Fo(    feoarrm4n2_t* lhs, onumm4n2_t* rhs);
  void      feoarrm4n2_sub_Fo_to( feoarrm4n2_t* lhs, onumm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sub_rF(      coeff_t  lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_sub_rF_to(    coeff_t lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_sub_Fr(    feoarrm4n2_t* lhs,   coeff_t  rhs);
  void      feoarrm4n2_sub_Fr_to( feoarrm4n2_t* lhs,   coeff_t  rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_mul_FF(   feoarrm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_mul_FF_to(feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_mul_fF(    feonumm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_mul_fF_to( feonumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_mul_OF(     oarrm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_mul_OF_to(  oarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_mul_RF(      darr_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_mul_RF_to(   darr_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_mul_oF(   onumm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_mul_oF_to(onumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_mul_rF(     coeff_t  lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_mul_rF_to(  coeff_t  lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_div_FF(    feoarrm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_div_FF_to( feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_div_fF(     feonumm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_div_fF_to(  feonumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_div_Ff(    feoarrm4n2_t* lhs,  feonumm4n2_t* rhs);
  void      feoarrm4n2_div_Ff_to( feoarrm4n2_t* lhs,  feonumm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_div_OF(      oarrm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_div_OF_to(   oarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_div_FO(    feoarrm4n2_t* lhs,   oarrm4n2_t* rhs);
  void      feoarrm4n2_div_FO_to( feoarrm4n2_t* lhs,   oarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_div_RF(       darr_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_div_RF_to(    darr_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_div_FR(    feoarrm4n2_t* lhs,    darr_t* rhs);
  void      feoarrm4n2_div_FR_to( feoarrm4n2_t* lhs,    darr_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_div_oF(    onumm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_div_oF_to( onumm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_div_Fo(    feoarrm4n2_t* lhs, onumm4n2_t* rhs);
  void      feoarrm4n2_div_Fo_to( feoarrm4n2_t* lhs, onumm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_div_rF(      coeff_t  lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_div_rF_to(    coeff_t lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_div_Fr(    feoarrm4n2_t* lhs,   coeff_t  rhs);
  void      feoarrm4n2_div_Fr_to( feoarrm4n2_t* lhs,   coeff_t  rhs, feoarrm4n2_t* res);
  oarrm4n2_t feoarrm4n2_integrate(    feoarrm4n2_t* arr, feonumm4n2_t* w);
  void    feoarrm4n2_integrate_to( feoarrm4n2_t* arr, feonumm4n2_t* w, oarrm4n2_t* res);
  feonumm4n2_t feoarrm4n2_dotproduct_FF(    feoarrm4n2_t* lhs, feoarrm4n2_t* rhs);
  void     feoarrm4n2_dotproduct_FF_to( feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feoarrm4n2_dotproduct_OF(      oarrm4n2_t* lhs, feoarrm4n2_t* rhs);
  void     feoarrm4n2_dotproduct_OF_to(   oarrm4n2_t* lhs, feoarrm4n2_t* rhs, feonumm4n2_t* res);
  feonumm4n2_t feoarrm4n2_dotproduct_RF(       darr_t* lhs, feoarrm4n2_t* rhs);
  void     feoarrm4n2_dotproduct_RF_to(    darr_t* lhs, feoarrm4n2_t* rhs, feonumm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_matmul_FF(    feoarrm4n2_t* lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_matmul_FF_to( feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_matmul_OF(    oarrm4n2_t*   lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_matmul_OF_to( oarrm4n2_t*   lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_matmul_FO(    feoarrm4n2_t* lhs, oarrm4n2_t*   rhs);
  void      feoarrm4n2_matmul_FO_to( feoarrm4n2_t* lhs, oarrm4n2_t*   rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_matmul_RF(    darr_t*    lhs, feoarrm4n2_t* rhs);
  void      feoarrm4n2_matmul_RF_to( darr_t*    lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
  feoarrm4n2_t feoarrm4n2_matmul_FR(    feoarrm4n2_t* lhs, darr_t*    rhs);
  void      feoarrm4n2_matmul_FR_to( feoarrm4n2_t* lhs, darr_t*    rhs, feoarrm4n2_t* res);
  feonumm4n2_t feoarrm4n2_det(   feoarrm4n2_t* arr);
  void     feoarrm4n2_det_to(feoarrm4n2_t* arr, feonumm4n2_t* res);
  feonumm4n2_t feoarrm4n2_norm(     feoarrm4n2_t* arr);
  void     feoarrm4n2_norm_to(  feoarrm4n2_t* arr, feonumm4n2_t* res);
  feonumm4n2_t feoarrm4n2_pnorm(    feoarrm4n2_t* arr, coeff_t p);
  void     feoarrm4n2_pnorm_to( feoarrm4n2_t* arr, coeff_t p, feonumm4n2_t* res);
  feoarrm4n2_t   feoarrm4n2_invert(    feoarrm4n2_t* arr);
  void        feoarrm4n2_invert_to( feoarrm4n2_t* arr, feoarrm4n2_t* res);
  feoarrm4n2_t   feoarrm4n2_transpose(   feoarrm4n2_t* arr);
  void        feoarrm4n2_transpose_to(feoarrm4n2_t* arr, feoarrm4n2_t* res);
  
  