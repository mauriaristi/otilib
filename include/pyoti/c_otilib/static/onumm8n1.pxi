cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm8n1/scalar/structures.h
  
  ctypedef struct  onumm8n1_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
    coeff_t e6;
    coeff_t e7;
    coeff_t e8;
  # } onumm8n1_t;
  
  
  # From ../../../include/oti/static/onumm8n1/array/structures.h
  
  ctypedef struct  oarrm8n1_t : # {
      onumm8n1_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm8n1_t;
  
  
  # From ../../../include/oti/static/onumm8n1/scalar/gauss/structures.h
  
  ctypedef struct  feonumm8n1_t: # {
      onumm8n1_t*  p_data;
      uint64_t    nip;
  # } feonumm8n1_t;
  
  
  # From ../../../include/oti/static/onumm8n1/array/gauss/structures.h
  
  ctypedef struct  feoarrm8n1_t: # {
      oarrm8n1_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm8n1_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm8n1/scalar/functions.h
  
  onumm8n1_t onumm8n1_atanh(onumm8n1_t* num);
  void onumm8n1_atanh_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_asinh(onumm8n1_t* num);
  void onumm8n1_asinh_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_acosh(onumm8n1_t* num);
  void onumm8n1_acosh_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_tanh(onumm8n1_t* num);
  void onumm8n1_tanh_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_sqrt(onumm8n1_t* num);
  void onumm8n1_sqrt_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_cbrt(onumm8n1_t* num);
  void onumm8n1_cbrt_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_cosh(onumm8n1_t* num);
  void onumm8n1_cosh_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_sinh(onumm8n1_t* num);
  void onumm8n1_sinh_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_asin(onumm8n1_t* num);
  void onumm8n1_asin_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_acos(onumm8n1_t* num);
  void onumm8n1_acos_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_atan(onumm8n1_t* num);
  void onumm8n1_atan_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_tan(onumm8n1_t* num);
  void onumm8n1_tan_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_cos(onumm8n1_t* num);
  void onumm8n1_cos_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_sin(onumm8n1_t* num );
  void onumm8n1_sin_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_logb(onumm8n1_t* num, double base);
  void onumm8n1_logb_to(onumm8n1_t* num, double base, onumm8n1_t* res);
  onumm8n1_t onumm8n1_log10(onumm8n1_t* num);
  void onumm8n1_log10_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_log(onumm8n1_t* num);
  void onumm8n1_log_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_exp(onumm8n1_t* num);
  void onumm8n1_exp_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_pow(onumm8n1_t* num, double e);
  void onumm8n1_pow_to(onumm8n1_t* num, coeff_t e, onumm8n1_t* res);
  
  
  # From ../../../include/oti/static/onumm8n1/scalar/base.h
  
  void onumm8n1_set_im_o(onumm8n1_t* num, imdir_t idx, ord_t order, onumm8n1_t* res);
  void onumm8n1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm8n1_t* res);
  void onumm8n1_set_deriv_o(onumm8n1_t* num, imdir_t idx, ord_t order, onumm8n1_t* res);
  void onumm8n1_extract_im_to( imdir_t idx, ord_t order, onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_extract_im(imdir_t idx, ord_t order, onumm8n1_t* num);
  onumm8n1_t onumm8n1_extract_deriv(imdir_t idx, ord_t order, onumm8n1_t* num);
  void onumm8n1_extract_deriv_to(imdir_t idx, ord_t order, onumm8n1_t* num, onumm8n1_t* res);
  void onumm8n1_get_im_to_o(imdir_t idx, ord_t order, onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_get_im_o(imdir_t idx, ord_t order, onumm8n1_t* num);
  void onumm8n1_get_im_to_r(imdir_t idx, ord_t order, onumm8n1_t* num, coeff_t* res);
  ord_t onumm8n1_get_order(onumm8n1_t* lhs);
  onumm8n1_t onumm8n1_get_deriv_o( imdir_t idx, ord_t order, onumm8n1_t* num);
  void onumm8n1_get_deriv_to( imdir_t idx, ord_t order, onumm8n1_t* num, onumm8n1_t* res);
  void onumm8n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm8n1_t* res);
  onumm8n1_t onumm8n1_init();
  ndir_t onumm8n1_get_ndir_order(ord_t order, onumm8n1_t* num);
  ndir_t onumm8n1_get_ndir_total(onumm8n1_t* num);
  coeff_t* onumm8n1_get_order_address(ord_t order, onumm8n1_t* num);
  onumm8n1_t onumm8n1_create_r(  coeff_t lhs);
  void onumm8n1_set_r(  coeff_t lhs, onumm8n1_t* res);
  void onumm8n1_set_o(  onumm8n1_t* lhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_get_order_im(ord_t order, onumm8n1_t* lhs);
  void onumm8n1_get_order_im_to(ord_t order, onumm8n1_t* lhs, onumm8n1_t* res);
  coeff_t onumm8n1_get_item(imdir_t idx, ord_t order, onumm8n1_t* lhs);
  coeff_t onumm8n1_get_deriv(imdir_t idx, ord_t order, onumm8n1_t* lhs);
  void onumm8n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm8n1_t* x);
  onumm8n1_t onumm8n1_copy(  onumm8n1_t* lhs);
  void onumm8n1_copy_to(  onumm8n1_t* lhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_taylor_integrate(coeff_t* deltas,onumm8n1_t* lhs);
  void onumm8n1_taylor_integrate_to(coeff_t* deltas,onumm8n1_t* lhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_truncate_im(imdir_t idx, ord_t order, onumm8n1_t* lhs);
  void onumm8n1_truncate_im_to(imdir_t idx, ord_t order, onumm8n1_t* lhs, onumm8n1_t* res);
  void onumm8n1_print(  onumm8n1_t* lhs);
  imdir_t onumm8n1_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm8n1/scalar/utils.h
  
  void onumm8n1_get_active_bases(onumm8n1_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm8n1/scalar/algebra.h
  
  onumm8n1_t onumm8n1_abs(onumm8n1_t* num);
  onumm8n1_t onumm8n1_div_ro(coeff_t num, onumm8n1_t* den);
  onumm8n1_t onumm8n1_div_oo(onumm8n1_t* num, onumm8n1_t* den);
  onumm8n1_t onumm8n1_div_or(onumm8n1_t* num, coeff_t val);
  void onumm8n1_div_ro_to(coeff_t num, onumm8n1_t* den, onumm8n1_t* res);
  void onumm8n1_div_oo_to(onumm8n1_t* num, onumm8n1_t* den, onumm8n1_t* res);
  void onumm8n1_div_or_to(onumm8n1_t* num, coeff_t val, onumm8n1_t* res);
  void onumm8n1_abs_to(onumm8n1_t* num, onumm8n1_t* res);
  onumm8n1_t onumm8n1_neg(  onumm8n1_t* lhs);
  void onumm8n1_neg_to(  onumm8n1_t* lhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_sum_oo(  onumm8n1_t* lhs,  onumm8n1_t* rhs);
  void onumm8n1_sum_oo_to(  onumm8n1_t* lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_sum_ro(  coeff_t lhs,  onumm8n1_t* rhs);
  void onumm8n1_sum_ro_to(  coeff_t lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_sub_oo(  onumm8n1_t* lhs,  onumm8n1_t* rhs);
  void onumm8n1_sub_oo_to(  onumm8n1_t* lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_sub_ro(  coeff_t lhs,  onumm8n1_t* rhs);
  void onumm8n1_sub_ro_to(  coeff_t lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_sub_or(  onumm8n1_t* lhs,  coeff_t rhs);
  void onumm8n1_sub_or_to(  onumm8n1_t* lhs,  coeff_t rhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_mul_oo(  onumm8n1_t* lhs,  onumm8n1_t* rhs);
  void onumm8n1_mul_oo_to(  onumm8n1_t* lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_mul_ro(  coeff_t lhs,  onumm8n1_t* rhs);
  void onumm8n1_mul_ro_to(  coeff_t lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_trunc_mul_oo(  onumm8n1_t* lhs,  onumm8n1_t* rhs);
  void onumm8n1_trunc_mul_oo_to(  onumm8n1_t* lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
  onumm8n1_t onumm8n1_gem_oo(  onumm8n1_t* a,  onumm8n1_t* b,  onumm8n1_t* c);
  void onumm8n1_gem_oo_to(  onumm8n1_t* a,  onumm8n1_t* b,  onumm8n1_t* c, onumm8n1_t* res);
  onumm8n1_t onumm8n1_gem_ro(  coeff_t a,  onumm8n1_t* b,  onumm8n1_t* c);
  void onumm8n1_gem_ro_to(  coeff_t a,  onumm8n1_t* b,  onumm8n1_t* c, onumm8n1_t* res);
  void onumm8n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm8n1_t* a,  ord_t ord_rhs,  onumm8n1_t* b,  onumm8n1_t* c, onumm8n1_t* res);
  onumm8n1_t onumm8n1_feval(coeff_t* feval_re, onumm8n1_t* x);
  void onumm8n1_feval_to(coeff_t* feval_re, onumm8n1_t* x, onumm8n1_t* res);
  
  
  # From ../../../include/oti/static/onumm8n1/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm8n1/scalar/gauss/functions.h
  
  feonumm8n1_t feonumm8n1_atanh(    feonumm8n1_t* num);
  void     feonumm8n1_atanh_to( feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_asinh(    feonumm8n1_t* num);
  void     feonumm8n1_asinh_to( feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_acosh(    feonumm8n1_t* num);
  void     feonumm8n1_acosh_to( feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_tanh(     feonumm8n1_t* num);
  void     feonumm8n1_tanh_to(  feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_cosh(     feonumm8n1_t* num);
  void     feonumm8n1_cosh_to(  feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_sinh(     feonumm8n1_t* num);
  void     feonumm8n1_sinh_to(  feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_asin(     feonumm8n1_t* num);
  void     feonumm8n1_asin_to(  feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_acos(     feonumm8n1_t* num);
  void     feonumm8n1_acos_to(  feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_atan(     feonumm8n1_t* num);
  void     feonumm8n1_atan_to(  feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_tan(      feonumm8n1_t* num);
  void     feonumm8n1_tan_to(   feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_cos(      feonumm8n1_t* num);
  void     feonumm8n1_cos_to(   feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_sin(      feonumm8n1_t* num);
  void     feonumm8n1_sin_to(   feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_logb(     feonumm8n1_t* num, double base);
  void     feonumm8n1_logb_to(  feonumm8n1_t* num, double base, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_log10(    feonumm8n1_t* num);
  void     feonumm8n1_log10_to( feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_log(      feonumm8n1_t* num);
  void     feonumm8n1_log_to(   feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_exp(      feonumm8n1_t* num);
  void     feonumm8n1_exp_to(   feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_cbrt(     feonumm8n1_t* num);
  void     feonumm8n1_cbrt_to(  feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_sqrt(     feonumm8n1_t* num);
  void     feonumm8n1_sqrt_to(  feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_pow(      feonumm8n1_t* num, double e);
  void     feonumm8n1_pow_to(   feonumm8n1_t* num, double e, feonumm8n1_t* res);
  onumm8n1_t feonumm8n1_integrate(       feonumm8n1_t* num, feonumm8n1_t* w);
  void      feonumm8n1_integrate_to(    feonumm8n1_t* num, feonumm8n1_t* w, onumm8n1_t* res);
  onumm8n1_t feonumm8n1_integrate_f(     feonumm8n1_t* num, feonumm8n1_t* w);
  void      feonumm8n1_integrate_f_to(  feonumm8n1_t* num, feonumm8n1_t* w, onumm8n1_t* res);
  onumm8n1_t feonumm8n1_integrate_r(       coeff_t num, feonumm8n1_t* w);
  void      feonumm8n1_integrate_r_to(    coeff_t num, feonumm8n1_t* w, onumm8n1_t* res);
  onumm8n1_t feonumm8n1_integrate_o(    onumm8n1_t* num, feonumm8n1_t* w);
  void      feonumm8n1_integrate_o_to( onumm8n1_t* num, feonumm8n1_t* w, onumm8n1_t* res);
  
  
  # From ../../../include/oti/static/onumm8n1/scalar/gauss/base.h
  
  void     feonumm8n1_get_order_im_to( ord_t order, feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_get_order_im(    ord_t order, feonumm8n1_t* num);
  feonumm8n1_t feonumm8n1_get_im(    imdir_t idx, ord_t order, feonumm8n1_t* num);
  void     feonumm8n1_get_im_to( imdir_t idx, ord_t order, feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_get_deriv(    imdir_t idx, ord_t order, feonumm8n1_t* num);
  void     feonumm8n1_get_deriv_to( imdir_t idx, ord_t order, feonumm8n1_t* num, feonumm8n1_t* res);
  void feonumm8n1_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm8n1_t* num);
  void feonumm8n1_set_im_o( onumm8n1_t* val, imdir_t idx, ord_t order, feonumm8n1_t* num);
  void feonumm8n1_set_im_f(  feonumm8n1_t* val, imdir_t idx, ord_t order, feonumm8n1_t* num);
  void feonumm8n1_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm8n1_t* num);
  void feonumm8n1_set_deriv_o( onumm8n1_t* val, imdir_t idx, ord_t order, feonumm8n1_t* num);
  void feonumm8n1_set_deriv_f(  feonumm8n1_t* val, imdir_t idx, ord_t order, feonumm8n1_t* num);
  feonumm8n1_t feonumm8n1_extract_im(    imdir_t idx, ord_t order, feonumm8n1_t* num);
  void     feonumm8n1_extract_im_to( imdir_t idx, ord_t order, feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_extract_deriv(    imdir_t idx, ord_t order, feonumm8n1_t* num);
  void     feonumm8n1_extract_deriv_to( imdir_t idx, ord_t order, feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_truncate_im(    imdir_t idx, ord_t order, feonumm8n1_t* num);
  void     feonumm8n1_truncate_im_to( imdir_t idx, ord_t order, feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_copy(    feonumm8n1_t* src);
  void     feonumm8n1_copy_to( feonumm8n1_t* src, feonumm8n1_t* dst);
  void feonumm8n1_set_r(    coeff_t num, feonumm8n1_t* res);
  void feonumm8n1_set_o( onumm8n1_t* num, feonumm8n1_t* res);
  void feonumm8n1_set_f(  feonumm8n1_t* num, feonumm8n1_t* res);
  void feonumm8n1_set_item_k_r(   coeff_t  num, uint64_t k, feonumm8n1_t* res);
  void feonumm8n1_set_item_k_o( onumm8n1_t* num, uint64_t k, feonumm8n1_t* res);
  onumm8n1_t feonumm8n1_get_item_k(   feonumm8n1_t* num, uint64_t k);
  void      feonumm8n1_get_item_k_to(feonumm8n1_t* num, uint64_t k, onumm8n1_t* res);
  feonumm8n1_t feonumm8n1_zeros(uint64_t nIntPts);
  feonumm8n1_t feonumm8n1_createEmpty(uint64_t nIntPts);
  feonumm8n1_t feonumm8n1_empty_like(feonumm8n1_t* arr);
  void feonumm8n1_free(feonumm8n1_t* num);
  ord_t feonumm8n1_get_order( feonumm8n1_t* num );
  feonumm8n1_t feonumm8n1_init();
  
  
  # From ../../../include/oti/static/onumm8n1/scalar/gauss/utils.h
  
  void feonumm8n1_dimCheck(feonumm8n1_t* arr1,feonumm8n1_t* arr2);
  void feonumm8n1_get_active_bases(feonumm8n1_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm8n1/scalar/gauss/algebra.h
  
  feonumm8n1_t feonumm8n1_neg(   feonumm8n1_t* num);
  void     feonumm8n1_neg_to(feonumm8n1_t* num, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_sum_ff(   feonumm8n1_t* lhs, feonumm8n1_t* rhs);
  void     feonumm8n1_sum_ff_to(feonumm8n1_t* lhs, feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_sum_of(   onumm8n1_t* lhs, feonumm8n1_t* rhs);
  void     feonumm8n1_sum_of_to(onumm8n1_t* lhs, feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_sum_rf(   coeff_t lhs, feonumm8n1_t* rhs);
  void     feonumm8n1_sum_rf_to(coeff_t lhs, feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_sub_ff(     feonumm8n1_t* lhs,  feonumm8n1_t* rhs);
  void     feonumm8n1_sub_ff_to(  feonumm8n1_t* lhs,  feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_sub_of(    onumm8n1_t* lhs,  feonumm8n1_t* rhs);
  void     feonumm8n1_sub_of_to( onumm8n1_t* lhs,  feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_sub_fo(     feonumm8n1_t* lhs, onumm8n1_t* rhs);
  void     feonumm8n1_sub_fo_to(  feonumm8n1_t* lhs, onumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_sub_rf(       coeff_t lhs,  feonumm8n1_t* rhs);
  void     feonumm8n1_sub_rf_to(    coeff_t lhs,  feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_sub_fr(     feonumm8n1_t* lhs,    coeff_t rhs);
  void     feonumm8n1_sub_fr_to(  feonumm8n1_t* lhs,    coeff_t rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_mul_ff(   feonumm8n1_t* lhs, feonumm8n1_t* rhs);
  void     feonumm8n1_mul_ff_to(feonumm8n1_t* lhs, feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_mul_of(   onumm8n1_t* lhs, feonumm8n1_t* rhs);
  void     feonumm8n1_mul_of_to(onumm8n1_t* lhs, feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_mul_rf(   coeff_t lhs, feonumm8n1_t* rhs);
  void     feonumm8n1_mul_rf_to(coeff_t lhs, feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_div_ff(     feonumm8n1_t* lhs,  feonumm8n1_t* rhs);
  void     feonumm8n1_div_ff_to(  feonumm8n1_t* lhs,  feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_div_of(    onumm8n1_t* lhs,  feonumm8n1_t* rhs);
  void     feonumm8n1_div_of_to( onumm8n1_t* lhs,  feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_div_fo(     feonumm8n1_t* lhs, onumm8n1_t* rhs);
  void     feonumm8n1_div_fo_to(  feonumm8n1_t* lhs, onumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_div_rf(       coeff_t lhs,  feonumm8n1_t* rhs);
  void     feonumm8n1_div_rf_to(    coeff_t lhs,  feonumm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feonumm8n1_div_fr(     feonumm8n1_t* lhs,    coeff_t rhs);
  void     feonumm8n1_div_fr_to(  feonumm8n1_t* lhs,    coeff_t rhs, feonumm8n1_t* res);
  
  
  # From ../../../include/oti/static/onumm8n1/array/functions.h
  
  oarrm8n1_t oarrm8n1_atanh(   oarrm8n1_t* arr);
  void    oarrm8n1_atanh_to(oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_asinh(   oarrm8n1_t* arr);
  void    oarrm8n1_asinh_to(oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_acosh(   oarrm8n1_t* arr);
  void    oarrm8n1_acosh_to(oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_tanh(    oarrm8n1_t* arr);
  void    oarrm8n1_tanh_to( oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_cbrt(    oarrm8n1_t* arr);
  void    oarrm8n1_cbrt_to( oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_sqrt(    oarrm8n1_t* arr);
  void    oarrm8n1_sqrt_to( oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_cosh(    oarrm8n1_t* arr);
  void    oarrm8n1_cosh_to( oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_sinh(    oarrm8n1_t* arr);
  void    oarrm8n1_sinh_to( oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_asin(    oarrm8n1_t* arr);
  void    oarrm8n1_asin_to( oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_acos(    oarrm8n1_t* arr);
  void    oarrm8n1_acos_to( oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_atan(    oarrm8n1_t* arr);
  void    oarrm8n1_atan_to( oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_tan(     oarrm8n1_t* arr);
  void    oarrm8n1_tan_to(  oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_cos(     oarrm8n1_t* arr);
  void    oarrm8n1_cos_to(  oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_sin(     oarrm8n1_t* arr);
  void    oarrm8n1_sin_to(  oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_logb(    oarrm8n1_t* arr, double base);
  void    oarrm8n1_logb_to( oarrm8n1_t* arr, double base, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_log10(   oarrm8n1_t* arr);
  void    oarrm8n1_log10_to(oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_log(     oarrm8n1_t* arr);
  void    oarrm8n1_log_to(  oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_exp(     oarrm8n1_t* arr);
  void    oarrm8n1_exp_to(  oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_pow(     oarrm8n1_t* arr, double e);
  void    oarrm8n1_pow_to(  oarrm8n1_t* arr, double e, oarrm8n1_t* res);
  
  
  # From ../../../include/oti/static/onumm8n1/array/algebra_elementwise.h
  
  oarrm8n1_t oarrm8n1_neg(oarrm8n1_t* arr);
  void oarrm8n1_neg_to(oarrm8n1_t* rhs, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_sum_OO(oarrm8n1_t*   lhs, oarrm8n1_t* rhs);
  oarrm8n1_t oarrm8n1_sum_RO(darr_t*    lhs, oarrm8n1_t* rhs);
  oarrm8n1_t oarrm8n1_sum_oO(onumm8n1_t* lhs, oarrm8n1_t* rhs);
  oarrm8n1_t oarrm8n1_sum_rO(coeff_t    lhs, oarrm8n1_t* rhs);
  void oarrm8n1_sum_OO_to(oarrm8n1_t*   lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
  void oarrm8n1_sum_RO_to(darr_t*    lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
  void oarrm8n1_sum_oO_to(onumm8n1_t* lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
  void oarrm8n1_sum_rO_to(coeff_t    lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_sub_OO(oarrm8n1_t*   lhs, oarrm8n1_t*   rhs);
  oarrm8n1_t oarrm8n1_sub_RO(darr_t*    lhs, oarrm8n1_t*   rhs);
  oarrm8n1_t oarrm8n1_sub_OR(oarrm8n1_t*   lhs, darr_t*    rhs);
  oarrm8n1_t oarrm8n1_sub_oO(onumm8n1_t* lhs, oarrm8n1_t*   rhs);
  oarrm8n1_t oarrm8n1_sub_Oo(oarrm8n1_t*   lhs, onumm8n1_t* rhs);
  oarrm8n1_t oarrm8n1_sub_rO(coeff_t    lhs, oarrm8n1_t*   rhs);
  oarrm8n1_t oarrm8n1_sub_Or(oarrm8n1_t*   lhs, coeff_t    rhs);
  void oarrm8n1_sub_OO_to( oarrm8n1_t*   lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
  void oarrm8n1_sub_RO_to( darr_t*    lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
  void oarrm8n1_sub_OR_to( oarrm8n1_t*   lhs, darr_t*    rhs, oarrm8n1_t* res);
  void oarrm8n1_sub_oO_to( onumm8n1_t* lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
  void oarrm8n1_sub_Oo_to( oarrm8n1_t*   lhs, onumm8n1_t* rhs, oarrm8n1_t* res);
  void oarrm8n1_sub_rO_to( coeff_t    lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
  void oarrm8n1_sub_Or_to( oarrm8n1_t*   lhs, coeff_t    rhs, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_mul_OO(oarrm8n1_t*   lhs, oarrm8n1_t* rhs);
  oarrm8n1_t oarrm8n1_mul_RO(darr_t*    lhs, oarrm8n1_t* rhs);
  oarrm8n1_t oarrm8n1_mul_oO(onumm8n1_t* lhs, oarrm8n1_t* rhs);
  oarrm8n1_t oarrm8n1_mul_rO(coeff_t    lhs, oarrm8n1_t* rhs);
  void oarrm8n1_mul_OO_to(oarrm8n1_t*   lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
  void oarrm8n1_mul_RO_to(darr_t*    lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
  void oarrm8n1_mul_oO_to(onumm8n1_t* lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
  void oarrm8n1_mul_rO_to(coeff_t    lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
  void oarrm8n1_gem_OO_to(  oarrm8n1_t* arr1, oarrm8n1_t* arr2, oarrm8n1_t* arr3, oarrm8n1_t* res);
  void oarrm8n1_gem_oO_to(onumm8n1_t* arr1, oarrm8n1_t* arr2, oarrm8n1_t* arr3, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_div_OO(oarrm8n1_t*   lhs, oarrm8n1_t*   rhs);
  oarrm8n1_t oarrm8n1_div_OR(oarrm8n1_t*   lhs, darr_t*    rhs);
  oarrm8n1_t oarrm8n1_div_RO(darr_t*    lhs, oarrm8n1_t*   rhs);
  oarrm8n1_t oarrm8n1_div_oO(onumm8n1_t* lhs, oarrm8n1_t*   rhs);
  oarrm8n1_t oarrm8n1_div_Oo(oarrm8n1_t*   lhs, onumm8n1_t* rhs);
  oarrm8n1_t oarrm8n1_div_rO(coeff_t    lhs, oarrm8n1_t*   rhs);
  oarrm8n1_t oarrm8n1_div_Or(oarrm8n1_t*   lhs, coeff_t    rhs);
  void oarrm8n1_div_OO_to(oarrm8n1_t*   lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
  void oarrm8n1_div_RO_to(darr_t*    lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
  void oarrm8n1_div_OR_to(oarrm8n1_t*   lhs, darr_t*    rhs, oarrm8n1_t* res);
  void oarrm8n1_div_oO_to(onumm8n1_t* lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
  void oarrm8n1_div_Oo_to(oarrm8n1_t*   lhs, onumm8n1_t* rhs, oarrm8n1_t* res);
  void oarrm8n1_div_rO_to(coeff_t    lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
  void oarrm8n1_div_Or_to(oarrm8n1_t*   lhs, coeff_t    rhs, oarrm8n1_t* res);
  
  
  # From ../../../include/oti/static/onumm8n1/array/base.h
  
  void    oarrm8n1_taylor_integrate_to( coeff_t* deltas, oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_taylor_integrate(    coeff_t* deltas, oarrm8n1_t* arr);
  void    oarrm8n1_get_order_im_to( ord_t order, oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_get_order_im(    ord_t order, oarrm8n1_t* arr);
  void oarrm8n1_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm8n1_t* res);
  void oarrm8n1_set_slice_O( oarrm8n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm8n1_t* res);
  void oarrm8n1_set_slice_o( onumm8n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_get_slice( oarrm8n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm8n1_get_slice_to( oarrm8n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_truncate_im(    imdir_t idx, ord_t order, oarrm8n1_t* arr);
  void    oarrm8n1_truncate_im_to( imdir_t idx, ord_t order, oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_extract_im(   imdir_t idx, ord_t order, oarrm8n1_t* arr);
  void    oarrm8n1_extract_im_to(imdir_t idx, ord_t order, oarrm8n1_t* arr, oarrm8n1_t* res);
  darr_t  oarrm8n1_get_deriv(    imdir_t idx, ord_t order, oarrm8n1_t* arr);
  void    oarrm8n1_get_deriv_to( imdir_t idx, ord_t order, oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_get_deriv_o(  imdir_t idx, ord_t order, oarrm8n1_t* arr);
  oarrm8n1_t oarrm8n1_extract_deriv(    imdir_t idx, ord_t order, oarrm8n1_t* arr);
  void    oarrm8n1_extract_deriv_to( imdir_t idx, ord_t order, oarrm8n1_t* arr, oarrm8n1_t* res);
  darr_t  oarrm8n1_get_im(   imdir_t idx, ord_t order, oarrm8n1_t* arr);
  oarrm8n1_t oarrm8n1_get_im_o( imdir_t idx, ord_t order, oarrm8n1_t* arr);
  void    oarrm8n1_get_im_to(imdir_t idx, ord_t order, oarrm8n1_t* arr, oarrm8n1_t* res);
  void    oarrm8n1_copy_to(oarrm8n1_t* arr, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_copy(oarrm8n1_t* arr);
  void oarrm8n1_set_all_r( coeff_t num, oarrm8n1_t* arr);
  void oarrm8n1_set_item_i_r( coeff_t num, uint64_t i, oarrm8n1_t* arr);
  void oarrm8n1_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm8n1_t* arr);
  void oarrm8n1_set_r(   coeff_t  num,   oarrm8n1_t* arr);
  void oarrm8n1_set_o( onumm8n1_t* num,   oarrm8n1_t* arr);
  void oarrm8n1_set_O(   oarrm8n1_t* arrin, oarrm8n1_t* arr);
  void oarrm8n1_set_all_o( onumm8n1_t* src, oarrm8n1_t* arr);
  void oarrm8n1_set_item_i_o( onumm8n1_t* num, uint64_t i, oarrm8n1_t* arr);
  void oarrm8n1_set_item_ij_o( onumm8n1_t* num, uint64_t i, uint64_t j, oarrm8n1_t* arr);
  onumm8n1_t oarrm8n1_get_item_i(    oarrm8n1_t* arr, uint64_t i);
  void      oarrm8n1_get_item_i_to( oarrm8n1_t* arr, uint64_t i,             onumm8n1_t* res);
  onumm8n1_t oarrm8n1_get_item_ij(   oarrm8n1_t* arr, uint64_t i, uint64_t j);
  void      oarrm8n1_get_item_ij_to(oarrm8n1_t* arr, uint64_t i, uint64_t j, onumm8n1_t* res);
  oarrm8n1_t oarrm8n1_init();
  void oarrm8n1_free(oarrm8n1_t* arr);
  oarrm8n1_t oarrm8n1_empty_like(oarrm8n1_t* arr);
  oarrm8n1_t oarrm8n1_eye(uint64_t nrows);
  oarrm8n1_t oarrm8n1_ones(uint64_t nrows, uint64_t ncols);
  oarrm8n1_t oarrm8n1_zeros(uint64_t nrows, uint64_t ncols);
  oarrm8n1_t oarrm8n1_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm8n1/array/utils.h
  
  void oarrm8n1_dimCheck_OO_elementwise(oarrm8n1_t* arr1, oarrm8n1_t* arr2, oarrm8n1_t* res);
  void oarrm8n1_dimCheck_RO_elementwise(darr_t*  arr1, oarrm8n1_t* arr2, oarrm8n1_t* res);
  void oarrm8n1_dimCheck_OO_matmul(oarrm8n1_t* arr1, oarrm8n1_t* arr2, oarrm8n1_t* res);
  void oarrm8n1_dimCheck_RO_matmul(darr_t*  arr1, oarrm8n1_t* arr2, oarrm8n1_t* res);
  void oarrm8n1_dimCheck_OR_matmul(oarrm8n1_t* arr1, darr_t*  arr2, oarrm8n1_t* res);
  void oarrm8n1_dimCheck_O_squareness(oarrm8n1_t* arr1, oarrm8n1_t* res);
  void oarrm8n1_dimCheck_OO_samesize(oarrm8n1_t* arr1, oarrm8n1_t* res);
  void oarrm8n1_dimCheck_RO_samesize(darr_t* arr1, oarrm8n1_t* res);
  ord_t oarrm8n1_get_order(oarrm8n1_t* arr);
  void oarrm8n1_get_active_bases(oarrm8n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm8n1/array/algebra_matops.h
  
  onumm8n1_t oarrm8n1_dotproduct_OO(    oarrm8n1_t* lhs, oarrm8n1_t* rhs);
  void      oarrm8n1_dotproduct_OO_to( oarrm8n1_t* lhs, oarrm8n1_t* rhs, onumm8n1_t* res);
  onumm8n1_t oarrm8n1_dotproduct_RO(     darr_t* lhs, oarrm8n1_t* rhs);
  void      oarrm8n1_dotproduct_RO_to(  darr_t* lhs, oarrm8n1_t* rhs, onumm8n1_t* res);
  oarrm8n1_t oarrm8n1_matmul_OO(    oarrm8n1_t* lhs, oarrm8n1_t* rhs);
  oarrm8n1_t oarrm8n1_matmul_OR(    oarrm8n1_t* lhs,  darr_t* rhs);
  oarrm8n1_t oarrm8n1_matmul_RO(     darr_t* lhs, oarrm8n1_t* rhs);
  void    oarrm8n1_matmul_OO_to( oarrm8n1_t* lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
  void    oarrm8n1_matmul_OR_to( oarrm8n1_t* lhs,  darr_t* rhs, oarrm8n1_t* res);
  void    oarrm8n1_matmul_RO_to(  darr_t* lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_transpose(    oarrm8n1_t* arr1);
  void    oarrm8n1_transpose_to( oarrm8n1_t* arr1, oarrm8n1_t* res);
  oarrm8n1_t oarrm8n1_invert(    oarrm8n1_t* arr1);
  void    oarrm8n1_invert_to( oarrm8n1_t* arr1, oarrm8n1_t* res);
  onumm8n1_t oarrm8n1_det(    oarrm8n1_t* arr1);
  void      oarrm8n1_det_to( oarrm8n1_t* arr1, onumm8n1_t* res);
  onumm8n1_t oarrm8n1_norm(    oarrm8n1_t* arr1);
  void      oarrm8n1_norm_to( oarrm8n1_t* arr1,  onumm8n1_t* res);
  onumm8n1_t oarrm8n1_pnorm(    oarrm8n1_t* arr1, coeff_t p);
  void      oarrm8n1_pnorm_to( oarrm8n1_t* arr1, coeff_t p, onumm8n1_t* res);
  
  
  # From ../../../include/oti/static/onumm8n1/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm8n1/array/gauss/functions.h
  
  feoarrm8n1_t feoarrm8n1_atanh(    feoarrm8n1_t* arr);
  void      feoarrm8n1_atanh_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_asinh(    feoarrm8n1_t* arr);
  void      feoarrm8n1_asinh_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_acosh(    feoarrm8n1_t* arr);
  void      feoarrm8n1_acosh_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_tanh(     feoarrm8n1_t* arr);
  void      feoarrm8n1_tanh_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sinh(     feoarrm8n1_t* arr);
  void      feoarrm8n1_sinh_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_cosh(     feoarrm8n1_t* arr);
  void      feoarrm8n1_cosh_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_atan(     feoarrm8n1_t* arr);
  void      feoarrm8n1_atan_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_asin(     feoarrm8n1_t* arr);
  void      feoarrm8n1_asin_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_acos(     feoarrm8n1_t* arr);
  void      feoarrm8n1_acos_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_tan(      feoarrm8n1_t* arr);
  void      feoarrm8n1_tan_to(   feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sin(      feoarrm8n1_t* arr);
  void      feoarrm8n1_sin_to(   feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_cos(      feoarrm8n1_t* arr);
  void      feoarrm8n1_cos_to(   feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_logb(     feoarrm8n1_t* arr, double base);
  void      feoarrm8n1_logb_to(  feoarrm8n1_t* arr, double base, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_log10(    feoarrm8n1_t* arr);
  void      feoarrm8n1_log10_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_log(      feoarrm8n1_t* arr);
  void      feoarrm8n1_log_to(   feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_exp(      feoarrm8n1_t* arr);
  void      feoarrm8n1_exp_to(   feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_cbrt(     feoarrm8n1_t* arr);
  void      feoarrm8n1_cbrt_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sqrt(     feoarrm8n1_t* arr);
  void      feoarrm8n1_sqrt_to(  feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_pow(      feoarrm8n1_t* arr, double e);
  void      feoarrm8n1_pow_to(   feoarrm8n1_t* arr, double e, feoarrm8n1_t* res);
  
  
  # From ../../../include/oti/static/onumm8n1/array/gauss/base.h
  
  void      feoarrm8n1_get_order_im_to( ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_get_order_im(    ord_t order, feoarrm8n1_t* arr);
  feoarrm8n1_t feoarrm8n1_get_deriv(   imdir_t idx, ord_t order, feoarrm8n1_t* arr);
  void      feoarrm8n1_get_deriv_to(imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_get_im(      imdir_t idx, ord_t order, feoarrm8n1_t* arr);
  void      feoarrm8n1_get_im_to(   imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_truncate_im(   imdir_t idx, ord_t order, feoarrm8n1_t* arr);
  void      feoarrm8n1_truncate_im_to(imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_copy(   feoarrm8n1_t* src);
  void      feoarrm8n1_copy_to(feoarrm8n1_t* src, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_get_im(    imdir_t idx, ord_t order, feoarrm8n1_t* arr);
  void      feoarrm8n1_get_im_to( imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_get_deriv(    imdir_t idx, ord_t order, feoarrm8n1_t* arr);
  void      feoarrm8n1_get_deriv_to( imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_extract_im(    imdir_t idx, ord_t order, feoarrm8n1_t* arr);
  void      feoarrm8n1_extract_im_to( imdir_t idx, ord_t order, feoarrm8n1_t* arr,  feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_extract_deriv(    imdir_t idx, ord_t order, feoarrm8n1_t* arr);
  void      feoarrm8n1_extract_deriv_to( imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
  oarrm8n1_t   feoarrm8n1_get_item_k(  feoarrm8n1_t* arr, uint64_t k);
  feonumm8n1_t  feoarrm8n1_get_item_ij( feoarrm8n1_t* arr, uint64_t i, uint64_t j);
  onumm8n1_t feoarrm8n1_get_item_ijk(feoarrm8n1_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm8n1_get_item_ij_to(  feoarrm8n1_t* arr, uint64_t i, uint64_t j,
                                 feonumm8n1_t* res);
  void feoarrm8n1_get_item_k_to(   feoarrm8n1_t* arr, uint64_t k,
                                  oarrm8n1_t* res);
  void feoarrm8n1_get_item_ijk_to( feoarrm8n1_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_get_slice(feoarrm8n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm8n1_get_slice_to(feoarrm8n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n1_t* res);
  void feoarrm8n1_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm8n1_t* res);
  void feoarrm8n1_set_item_ij_o(  onumm8n1_t* elm, uint64_t i, uint64_t j,
                               feoarrm8n1_t* res);
  void feoarrm8n1_set_item_ij_f(  feonumm8n1_t* elm, uint64_t i, uint64_t j,
                              feoarrm8n1_t* res);
  void feoarrm8n1_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm8n1_t* res);
  void feoarrm8n1_set_item_k_o(  onumm8n1_t* elm, uint64_t k,
                              feoarrm8n1_t* res);
  void feoarrm8n1_set_item_k_R(    oarrm8n1_t* elm, uint64_t k,
                            feoarrm8n1_t* res);
  void feoarrm8n1_set_item_k_O(    oarrm8n1_t* elm, uint64_t k,
                            feoarrm8n1_t* res);
  void feoarrm8n1_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm8n1_t* res);
  void feoarrm8n1_set_item_ijk_o( onumm8n1_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm8n1_t* res);
  void feoarrm8n1_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n1_t* res);
  void feoarrm8n1_set_slice_o( onumm8n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n1_t* res);
  void feoarrm8n1_set_slice_f( feonumm8n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n1_t* res);
  void feoarrm8n1_set_slice_O( oarrm8n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n1_t* res);
  void feoarrm8n1_set_slice_F( feoarrm8n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm8n1_t* res);
  void feoarrm8n1_set_all_o( onumm8n1_t* num, feoarrm8n1_t* arr );
  void feoarrm8n1_set_all_r(   coeff_t  num, feoarrm8n1_t* arr );
  void feoarrm8n1_set_all_f(  feonumm8n1_t* num, feoarrm8n1_t* arr );
  void feoarrm8n1_set_r(    coeff_t src, feoarrm8n1_t* res );
  void feoarrm8n1_set_o( onumm8n1_t* src, feoarrm8n1_t* res );
  void feoarrm8n1_set_f(  feonumm8n1_t* src, feoarrm8n1_t* res );
  void feoarrm8n1_set_R(    darr_t* src, feoarrm8n1_t* res );
  void feoarrm8n1_set_O(   oarrm8n1_t* src, feoarrm8n1_t* res );
  void feoarrm8n1_set_F( feoarrm8n1_t* src, feoarrm8n1_t* res );
  feoarrm8n1_t feoarrm8n1_eye( uint64_t size,  uint64_t nip);
  feoarrm8n1_t feoarrm8n1_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm8n1_t feoarrm8n1_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm8n1_t feoarrm8n1_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm8n1_free(feoarrm8n1_t* arr);
  feoarrm8n1_t feoarrm8n1_init();
  ord_t feoarrm8n1_get_order(feoarrm8n1_t* arr);
  
  
  # From ../../../include/oti/static/onumm8n1/array/gauss/utils.h
  
  void feoarrm8n1_dimCheck_FF_samesize(feoarrm8n1_t* arr1, feoarrm8n1_t* arr2, feonumm8n1_t* res);
  void feoarrm8n1_dimCheck_OF_samesize(  oarrm8n1_t* arr1, feoarrm8n1_t* arr2, feonumm8n1_t* res);
  void feoarrm8n1_dimCheck_RF_samesize(   darr_t* arr1, feoarrm8n1_t* arr2, feonumm8n1_t* res);
  void feoarrm8n1_dimCheck_FF_elementwise(feoarrm8n1_t* arr1, feoarrm8n1_t* arr2, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_OF_elementwise(  oarrm8n1_t* arr1, feoarrm8n1_t* arr2, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm8n1_t* arr2, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_fF_elementwise( feonumm8n1_t* num1, feoarrm8n1_t* arr2, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_Ff_elementwise(feoarrm8n1_t* arr1,  feonumm8n1_t* num2, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_FF_matmul( feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_OF_matmul(   oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_FO_matmul( feoarrm8n1_t* lhs,   oarrm8n1_t* rhs, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_FR_matmul( feoarrm8n1_t* lhs,    darr_t* rhs, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_F_squareness( feoarrm8n1_t* arr1, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_F_transpose( feoarrm8n1_t* arr1, feoarrm8n1_t* res);
  void feoarrm8n1_dimCheck_FfO_integrate(feoarrm8n1_t* arr, feonumm8n1_t* num,oarrm8n1_t* res);
  void feoarrm8n1_get_active_bases(feoarrm8n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm8n1/array/gauss/algebra.h
  
  feoarrm8n1_t feoarrm8n1_neg(    feoarrm8n1_t* arr);
  void      feoarrm8n1_neg_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sum_FF(   feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sum_FF_to(feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sum_fF(    feonumm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sum_fF_to( feonumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sum_OF(     oarrm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sum_OF_to(  oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sum_RF(      darr_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sum_RF_to(   darr_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sum_oF(   onumm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sum_oF_to(onumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sum_rF(     coeff_t  lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sum_rF_to(  coeff_t  lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sub_FF(    feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sub_FF_to( feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sub_fF(    feonumm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sub_fF_to( feonumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sub_Ff(    feoarrm8n1_t* lhs, feonumm8n1_t* rhs);
  void      feoarrm8n1_sub_Ff_to( feoarrm8n1_t* lhs, feonumm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sub_OF(      oarrm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sub_OF_to(   oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sub_FO(    feoarrm8n1_t* lhs,   oarrm8n1_t* rhs);
  void      feoarrm8n1_sub_FO_to( feoarrm8n1_t* lhs,   oarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sub_RF(       darr_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sub_RF_to(    darr_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sub_FR(    feoarrm8n1_t* lhs,    darr_t* rhs);
  void      feoarrm8n1_sub_FR_to( feoarrm8n1_t* lhs,    darr_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sub_oF(    onumm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sub_oF_to( onumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sub_Fo(    feoarrm8n1_t* lhs, onumm8n1_t* rhs);
  void      feoarrm8n1_sub_Fo_to( feoarrm8n1_t* lhs, onumm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sub_rF(      coeff_t  lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_sub_rF_to(    coeff_t lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_sub_Fr(    feoarrm8n1_t* lhs,   coeff_t  rhs);
  void      feoarrm8n1_sub_Fr_to( feoarrm8n1_t* lhs,   coeff_t  rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_mul_FF(   feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_mul_FF_to(feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_mul_fF(    feonumm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_mul_fF_to( feonumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_mul_OF(     oarrm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_mul_OF_to(  oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_mul_RF(      darr_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_mul_RF_to(   darr_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_mul_oF(   onumm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_mul_oF_to(onumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_mul_rF(     coeff_t  lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_mul_rF_to(  coeff_t  lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_div_FF(    feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_div_FF_to( feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_div_fF(     feonumm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_div_fF_to(  feonumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_div_Ff(    feoarrm8n1_t* lhs,  feonumm8n1_t* rhs);
  void      feoarrm8n1_div_Ff_to( feoarrm8n1_t* lhs,  feonumm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_div_OF(      oarrm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_div_OF_to(   oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_div_FO(    feoarrm8n1_t* lhs,   oarrm8n1_t* rhs);
  void      feoarrm8n1_div_FO_to( feoarrm8n1_t* lhs,   oarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_div_RF(       darr_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_div_RF_to(    darr_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_div_FR(    feoarrm8n1_t* lhs,    darr_t* rhs);
  void      feoarrm8n1_div_FR_to( feoarrm8n1_t* lhs,    darr_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_div_oF(    onumm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_div_oF_to( onumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_div_Fo(    feoarrm8n1_t* lhs, onumm8n1_t* rhs);
  void      feoarrm8n1_div_Fo_to( feoarrm8n1_t* lhs, onumm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_div_rF(      coeff_t  lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_div_rF_to(    coeff_t lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_div_Fr(    feoarrm8n1_t* lhs,   coeff_t  rhs);
  void      feoarrm8n1_div_Fr_to( feoarrm8n1_t* lhs,   coeff_t  rhs, feoarrm8n1_t* res);
  oarrm8n1_t feoarrm8n1_integrate(    feoarrm8n1_t* arr, feonumm8n1_t* w);
  void    feoarrm8n1_integrate_to( feoarrm8n1_t* arr, feonumm8n1_t* w, oarrm8n1_t* res);
  feonumm8n1_t feoarrm8n1_dotproduct_FF(    feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
  void     feoarrm8n1_dotproduct_FF_to( feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feoarrm8n1_dotproduct_OF(      oarrm8n1_t* lhs, feoarrm8n1_t* rhs);
  void     feoarrm8n1_dotproduct_OF_to(   oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feonumm8n1_t* res);
  feonumm8n1_t feoarrm8n1_dotproduct_RF(       darr_t* lhs, feoarrm8n1_t* rhs);
  void     feoarrm8n1_dotproduct_RF_to(    darr_t* lhs, feoarrm8n1_t* rhs, feonumm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_matmul_FF(    feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_matmul_FF_to( feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_matmul_OF(    oarrm8n1_t*   lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_matmul_OF_to( oarrm8n1_t*   lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_matmul_FO(    feoarrm8n1_t* lhs, oarrm8n1_t*   rhs);
  void      feoarrm8n1_matmul_FO_to( feoarrm8n1_t* lhs, oarrm8n1_t*   rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_matmul_RF(    darr_t*    lhs, feoarrm8n1_t* rhs);
  void      feoarrm8n1_matmul_RF_to( darr_t*    lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
  feoarrm8n1_t feoarrm8n1_matmul_FR(    feoarrm8n1_t* lhs, darr_t*    rhs);
  void      feoarrm8n1_matmul_FR_to( feoarrm8n1_t* lhs, darr_t*    rhs, feoarrm8n1_t* res);
  feonumm8n1_t feoarrm8n1_det(   feoarrm8n1_t* arr);
  void     feoarrm8n1_det_to(feoarrm8n1_t* arr, feonumm8n1_t* res);
  feonumm8n1_t feoarrm8n1_norm(     feoarrm8n1_t* arr);
  void     feoarrm8n1_norm_to(  feoarrm8n1_t* arr, feonumm8n1_t* res);
  feonumm8n1_t feoarrm8n1_pnorm(    feoarrm8n1_t* arr, coeff_t p);
  void     feoarrm8n1_pnorm_to( feoarrm8n1_t* arr, coeff_t p, feonumm8n1_t* res);
  feoarrm8n1_t   feoarrm8n1_invert(    feoarrm8n1_t* arr);
  void        feoarrm8n1_invert_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
  feoarrm8n1_t   feoarrm8n1_transpose(   feoarrm8n1_t* arr);
  void        feoarrm8n1_transpose_to(feoarrm8n1_t* arr, feoarrm8n1_t* res);
  
  