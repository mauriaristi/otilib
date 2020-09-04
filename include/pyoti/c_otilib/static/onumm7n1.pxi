cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm7n1/scalar/structures.h
  
  ctypedef struct  onumm7n1_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
    coeff_t e6;
    coeff_t e7;
  # } onumm7n1_t;
  
  
  # From ../../../include/oti/static/onumm7n1/array/structures.h
  
  ctypedef struct  oarrm7n1_t : # {
      onumm7n1_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm7n1_t;
  
  
  # From ../../../include/oti/static/onumm7n1/scalar/gauss/structures.h
  
  ctypedef struct  feonumm7n1_t: # {
      onumm7n1_t*  p_data;
      uint64_t    nip;
  # } feonumm7n1_t;
  
  
  # From ../../../include/oti/static/onumm7n1/array/gauss/structures.h
  
  ctypedef struct  feoarrm7n1_t: # {
      oarrm7n1_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm7n1_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm7n1/scalar/functions.h
  
  onumm7n1_t onumm7n1_atanh(onumm7n1_t* num);
  void onumm7n1_atanh_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_asinh(onumm7n1_t* num);
  void onumm7n1_asinh_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_acosh(onumm7n1_t* num);
  void onumm7n1_acosh_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_tanh(onumm7n1_t* num);
  void onumm7n1_tanh_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_sqrt(onumm7n1_t* num);
  void onumm7n1_sqrt_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_cbrt(onumm7n1_t* num);
  void onumm7n1_cbrt_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_cosh(onumm7n1_t* num);
  void onumm7n1_cosh_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_sinh(onumm7n1_t* num);
  void onumm7n1_sinh_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_asin(onumm7n1_t* num);
  void onumm7n1_asin_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_acos(onumm7n1_t* num);
  void onumm7n1_acos_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_atan(onumm7n1_t* num);
  void onumm7n1_atan_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_tan(onumm7n1_t* num);
  void onumm7n1_tan_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_cos(onumm7n1_t* num);
  void onumm7n1_cos_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_sin(onumm7n1_t* num );
  void onumm7n1_sin_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_logb(onumm7n1_t* num, double base);
  void onumm7n1_logb_to(onumm7n1_t* num, double base, onumm7n1_t* res);
  onumm7n1_t onumm7n1_log10(onumm7n1_t* num);
  void onumm7n1_log10_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_log(onumm7n1_t* num);
  void onumm7n1_log_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_exp(onumm7n1_t* num);
  void onumm7n1_exp_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_pow(onumm7n1_t* num, double e);
  void onumm7n1_pow_to(onumm7n1_t* num, coeff_t e, onumm7n1_t* res);
  
  
  # From ../../../include/oti/static/onumm7n1/scalar/base.h
  
  void onumm7n1_set_im_o(onumm7n1_t* num, imdir_t idx, ord_t order, onumm7n1_t* res);
  void onumm7n1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm7n1_t* res);
  void onumm7n1_set_deriv_o(onumm7n1_t* num, imdir_t idx, ord_t order, onumm7n1_t* res);
  void onumm7n1_extract_im_to( imdir_t idx, ord_t order, onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_extract_im(imdir_t idx, ord_t order, onumm7n1_t* num);
  onumm7n1_t onumm7n1_extract_deriv(imdir_t idx, ord_t order, onumm7n1_t* num);
  void onumm7n1_extract_deriv_to(imdir_t idx, ord_t order, onumm7n1_t* num, onumm7n1_t* res);
  void onumm7n1_get_im_to_o(imdir_t idx, ord_t order, onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_get_im_o(imdir_t idx, ord_t order, onumm7n1_t* num);
  void onumm7n1_get_im_to_r(imdir_t idx, ord_t order, onumm7n1_t* num, coeff_t* res);
  ord_t onumm7n1_get_order(onumm7n1_t* lhs);
  onumm7n1_t onumm7n1_get_deriv_o( imdir_t idx, ord_t order, onumm7n1_t* num);
  void onumm7n1_get_deriv_to( imdir_t idx, ord_t order, onumm7n1_t* num, onumm7n1_t* res);
  void onumm7n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm7n1_t* res);
  onumm7n1_t onumm7n1_init();
  ndir_t onumm7n1_get_ndir_order(ord_t order, onumm7n1_t* num);
  ndir_t onumm7n1_get_ndir_total(onumm7n1_t* num);
  coeff_t* onumm7n1_get_order_address(ord_t order, onumm7n1_t* num);
  onumm7n1_t onumm7n1_create_r(  coeff_t lhs);
  void onumm7n1_set_r(  coeff_t lhs, onumm7n1_t* res);
  void onumm7n1_set_o(  onumm7n1_t* lhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_get_order_im(ord_t order, onumm7n1_t* lhs);
  void onumm7n1_get_order_im_to(ord_t order, onumm7n1_t* lhs, onumm7n1_t* res);
  coeff_t onumm7n1_get_item(imdir_t idx, ord_t order, onumm7n1_t* lhs);
  coeff_t onumm7n1_get_deriv(imdir_t idx, ord_t order, onumm7n1_t* lhs);
  void onumm7n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm7n1_t* x);
  onumm7n1_t onumm7n1_copy(  onumm7n1_t* lhs);
  void onumm7n1_copy_to(  onumm7n1_t* lhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_taylor_integrate(coeff_t* deltas,onumm7n1_t* lhs);
  void onumm7n1_taylor_integrate_to(coeff_t* deltas,onumm7n1_t* lhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_truncate_im(imdir_t idx, ord_t order, onumm7n1_t* lhs);
  void onumm7n1_truncate_im_to(imdir_t idx, ord_t order, onumm7n1_t* lhs, onumm7n1_t* res);
  void onumm7n1_print(  onumm7n1_t* lhs);
  imdir_t onumm7n1_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm7n1/scalar/utils.h
  
  void onumm7n1_get_active_bases(onumm7n1_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm7n1/scalar/algebra.h
  
  onumm7n1_t onumm7n1_abs(onumm7n1_t* num);
  onumm7n1_t onumm7n1_div_ro(coeff_t num, onumm7n1_t* den);
  onumm7n1_t onumm7n1_div_oo(onumm7n1_t* num, onumm7n1_t* den);
  onumm7n1_t onumm7n1_div_or(onumm7n1_t* num, coeff_t val);
  void onumm7n1_div_ro_to(coeff_t num, onumm7n1_t* den, onumm7n1_t* res);
  void onumm7n1_div_oo_to(onumm7n1_t* num, onumm7n1_t* den, onumm7n1_t* res);
  void onumm7n1_div_or_to(onumm7n1_t* num, coeff_t val, onumm7n1_t* res);
  void onumm7n1_abs_to(onumm7n1_t* num, onumm7n1_t* res);
  onumm7n1_t onumm7n1_neg(  onumm7n1_t* lhs);
  void onumm7n1_neg_to(  onumm7n1_t* lhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_sum_oo(  onumm7n1_t* lhs,  onumm7n1_t* rhs);
  void onumm7n1_sum_oo_to(  onumm7n1_t* lhs,  onumm7n1_t* rhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_sum_ro(  coeff_t lhs,  onumm7n1_t* rhs);
  void onumm7n1_sum_ro_to(  coeff_t lhs,  onumm7n1_t* rhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_sub_oo(  onumm7n1_t* lhs,  onumm7n1_t* rhs);
  void onumm7n1_sub_oo_to(  onumm7n1_t* lhs,  onumm7n1_t* rhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_sub_ro(  coeff_t lhs,  onumm7n1_t* rhs);
  void onumm7n1_sub_ro_to(  coeff_t lhs,  onumm7n1_t* rhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_sub_or(  onumm7n1_t* lhs,  coeff_t rhs);
  void onumm7n1_sub_or_to(  onumm7n1_t* lhs,  coeff_t rhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_mul_oo(  onumm7n1_t* lhs,  onumm7n1_t* rhs);
  void onumm7n1_mul_oo_to(  onumm7n1_t* lhs,  onumm7n1_t* rhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_mul_ro(  coeff_t lhs,  onumm7n1_t* rhs);
  void onumm7n1_mul_ro_to(  coeff_t lhs,  onumm7n1_t* rhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_trunc_mul_oo(  onumm7n1_t* lhs,  onumm7n1_t* rhs);
  void onumm7n1_trunc_mul_oo_to(  onumm7n1_t* lhs,  onumm7n1_t* rhs, onumm7n1_t* res);
  onumm7n1_t onumm7n1_gem_oo(  onumm7n1_t* a,  onumm7n1_t* b,  onumm7n1_t* c);
  void onumm7n1_gem_oo_to(  onumm7n1_t* a,  onumm7n1_t* b,  onumm7n1_t* c, onumm7n1_t* res);
  onumm7n1_t onumm7n1_gem_ro(  coeff_t a,  onumm7n1_t* b,  onumm7n1_t* c);
  void onumm7n1_gem_ro_to(  coeff_t a,  onumm7n1_t* b,  onumm7n1_t* c, onumm7n1_t* res);
  void onumm7n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm7n1_t* a,  ord_t ord_rhs,  onumm7n1_t* b,  onumm7n1_t* c, onumm7n1_t* res);
  onumm7n1_t onumm7n1_feval(coeff_t* feval_re, onumm7n1_t* x);
  void onumm7n1_feval_to(coeff_t* feval_re, onumm7n1_t* x, onumm7n1_t* res);
  
  
  # From ../../../include/oti/static/onumm7n1/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm7n1/scalar/gauss/functions.h
  
  feonumm7n1_t feonumm7n1_atanh(    feonumm7n1_t* num);
  void     feonumm7n1_atanh_to( feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_asinh(    feonumm7n1_t* num);
  void     feonumm7n1_asinh_to( feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_acosh(    feonumm7n1_t* num);
  void     feonumm7n1_acosh_to( feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_tanh(     feonumm7n1_t* num);
  void     feonumm7n1_tanh_to(  feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_cosh(     feonumm7n1_t* num);
  void     feonumm7n1_cosh_to(  feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_sinh(     feonumm7n1_t* num);
  void     feonumm7n1_sinh_to(  feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_asin(     feonumm7n1_t* num);
  void     feonumm7n1_asin_to(  feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_acos(     feonumm7n1_t* num);
  void     feonumm7n1_acos_to(  feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_atan(     feonumm7n1_t* num);
  void     feonumm7n1_atan_to(  feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_tan(      feonumm7n1_t* num);
  void     feonumm7n1_tan_to(   feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_cos(      feonumm7n1_t* num);
  void     feonumm7n1_cos_to(   feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_sin(      feonumm7n1_t* num);
  void     feonumm7n1_sin_to(   feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_logb(     feonumm7n1_t* num, double base);
  void     feonumm7n1_logb_to(  feonumm7n1_t* num, double base, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_log10(    feonumm7n1_t* num);
  void     feonumm7n1_log10_to( feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_log(      feonumm7n1_t* num);
  void     feonumm7n1_log_to(   feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_exp(      feonumm7n1_t* num);
  void     feonumm7n1_exp_to(   feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_cbrt(     feonumm7n1_t* num);
  void     feonumm7n1_cbrt_to(  feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_sqrt(     feonumm7n1_t* num);
  void     feonumm7n1_sqrt_to(  feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_pow(      feonumm7n1_t* num, double e);
  void     feonumm7n1_pow_to(   feonumm7n1_t* num, double e, feonumm7n1_t* res);
  onumm7n1_t feonumm7n1_integrate(       feonumm7n1_t* num, feonumm7n1_t* w);
  void      feonumm7n1_integrate_to(    feonumm7n1_t* num, feonumm7n1_t* w, onumm7n1_t* res);
  onumm7n1_t feonumm7n1_integrate_f(     feonumm7n1_t* num, feonumm7n1_t* w);
  void      feonumm7n1_integrate_f_to(  feonumm7n1_t* num, feonumm7n1_t* w, onumm7n1_t* res);
  onumm7n1_t feonumm7n1_integrate_r(       coeff_t num, feonumm7n1_t* w);
  void      feonumm7n1_integrate_r_to(    coeff_t num, feonumm7n1_t* w, onumm7n1_t* res);
  onumm7n1_t feonumm7n1_integrate_o(    onumm7n1_t* num, feonumm7n1_t* w);
  void      feonumm7n1_integrate_o_to( onumm7n1_t* num, feonumm7n1_t* w, onumm7n1_t* res);
  
  
  # From ../../../include/oti/static/onumm7n1/scalar/gauss/base.h
  
  void     feonumm7n1_get_order_im_to( ord_t order, feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_get_order_im(    ord_t order, feonumm7n1_t* num);
  feonumm7n1_t feonumm7n1_get_im(    imdir_t idx, ord_t order, feonumm7n1_t* num);
  void     feonumm7n1_get_im_to( imdir_t idx, ord_t order, feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_get_deriv(    imdir_t idx, ord_t order, feonumm7n1_t* num);
  void     feonumm7n1_get_deriv_to( imdir_t idx, ord_t order, feonumm7n1_t* num, feonumm7n1_t* res);
  void feonumm7n1_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm7n1_t* num);
  void feonumm7n1_set_im_o( onumm7n1_t* val, imdir_t idx, ord_t order, feonumm7n1_t* num);
  void feonumm7n1_set_im_f(  feonumm7n1_t* val, imdir_t idx, ord_t order, feonumm7n1_t* num);
  void feonumm7n1_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm7n1_t* num);
  void feonumm7n1_set_deriv_o( onumm7n1_t* val, imdir_t idx, ord_t order, feonumm7n1_t* num);
  void feonumm7n1_set_deriv_f(  feonumm7n1_t* val, imdir_t idx, ord_t order, feonumm7n1_t* num);
  feonumm7n1_t feonumm7n1_extract_im(    imdir_t idx, ord_t order, feonumm7n1_t* num);
  void     feonumm7n1_extract_im_to( imdir_t idx, ord_t order, feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_extract_deriv(    imdir_t idx, ord_t order, feonumm7n1_t* num);
  void     feonumm7n1_extract_deriv_to( imdir_t idx, ord_t order, feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_truncate_im(    imdir_t idx, ord_t order, feonumm7n1_t* num);
  void     feonumm7n1_truncate_im_to( imdir_t idx, ord_t order, feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_copy(    feonumm7n1_t* src);
  void     feonumm7n1_copy_to( feonumm7n1_t* src, feonumm7n1_t* dst);
  void feonumm7n1_set_r(    coeff_t num, feonumm7n1_t* res);
  void feonumm7n1_set_o( onumm7n1_t* num, feonumm7n1_t* res);
  void feonumm7n1_set_f(  feonumm7n1_t* num, feonumm7n1_t* res);
  void feonumm7n1_set_item_k_r(   coeff_t  num, uint64_t k, feonumm7n1_t* res);
  void feonumm7n1_set_item_k_o( onumm7n1_t* num, uint64_t k, feonumm7n1_t* res);
  onumm7n1_t feonumm7n1_get_item_k(   feonumm7n1_t* num, uint64_t k);
  void      feonumm7n1_get_item_k_to(feonumm7n1_t* num, uint64_t k, onumm7n1_t* res);
  feonumm7n1_t feonumm7n1_zeros(uint64_t nIntPts);
  feonumm7n1_t feonumm7n1_createEmpty(uint64_t nIntPts);
  feonumm7n1_t feonumm7n1_empty_like(feonumm7n1_t* arr);
  void feonumm7n1_free(feonumm7n1_t* num);
  ord_t feonumm7n1_get_order( feonumm7n1_t* num );
  feonumm7n1_t feonumm7n1_init();
  
  
  # From ../../../include/oti/static/onumm7n1/scalar/gauss/utils.h
  
  void feonumm7n1_dimCheck(feonumm7n1_t* arr1,feonumm7n1_t* arr2);
  void feonumm7n1_get_active_bases(feonumm7n1_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm7n1/scalar/gauss/algebra.h
  
  feonumm7n1_t feonumm7n1_neg(   feonumm7n1_t* num);
  void     feonumm7n1_neg_to(feonumm7n1_t* num, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_sum_ff(   feonumm7n1_t* lhs, feonumm7n1_t* rhs);
  void     feonumm7n1_sum_ff_to(feonumm7n1_t* lhs, feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_sum_of(   onumm7n1_t* lhs, feonumm7n1_t* rhs);
  void     feonumm7n1_sum_of_to(onumm7n1_t* lhs, feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_sum_rf(   coeff_t lhs, feonumm7n1_t* rhs);
  void     feonumm7n1_sum_rf_to(coeff_t lhs, feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_sub_ff(     feonumm7n1_t* lhs,  feonumm7n1_t* rhs);
  void     feonumm7n1_sub_ff_to(  feonumm7n1_t* lhs,  feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_sub_of(    onumm7n1_t* lhs,  feonumm7n1_t* rhs);
  void     feonumm7n1_sub_of_to( onumm7n1_t* lhs,  feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_sub_fo(     feonumm7n1_t* lhs, onumm7n1_t* rhs);
  void     feonumm7n1_sub_fo_to(  feonumm7n1_t* lhs, onumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_sub_rf(       coeff_t lhs,  feonumm7n1_t* rhs);
  void     feonumm7n1_sub_rf_to(    coeff_t lhs,  feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_sub_fr(     feonumm7n1_t* lhs,    coeff_t rhs);
  void     feonumm7n1_sub_fr_to(  feonumm7n1_t* lhs,    coeff_t rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_mul_ff(   feonumm7n1_t* lhs, feonumm7n1_t* rhs);
  void     feonumm7n1_mul_ff_to(feonumm7n1_t* lhs, feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_mul_of(   onumm7n1_t* lhs, feonumm7n1_t* rhs);
  void     feonumm7n1_mul_of_to(onumm7n1_t* lhs, feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_mul_rf(   coeff_t lhs, feonumm7n1_t* rhs);
  void     feonumm7n1_mul_rf_to(coeff_t lhs, feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_div_ff(     feonumm7n1_t* lhs,  feonumm7n1_t* rhs);
  void     feonumm7n1_div_ff_to(  feonumm7n1_t* lhs,  feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_div_of(    onumm7n1_t* lhs,  feonumm7n1_t* rhs);
  void     feonumm7n1_div_of_to( onumm7n1_t* lhs,  feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_div_fo(     feonumm7n1_t* lhs, onumm7n1_t* rhs);
  void     feonumm7n1_div_fo_to(  feonumm7n1_t* lhs, onumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_div_rf(       coeff_t lhs,  feonumm7n1_t* rhs);
  void     feonumm7n1_div_rf_to(    coeff_t lhs,  feonumm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feonumm7n1_div_fr(     feonumm7n1_t* lhs,    coeff_t rhs);
  void     feonumm7n1_div_fr_to(  feonumm7n1_t* lhs,    coeff_t rhs, feonumm7n1_t* res);
  
  
  # From ../../../include/oti/static/onumm7n1/array/functions.h
  
  oarrm7n1_t oarrm7n1_atanh(   oarrm7n1_t* arr);
  void    oarrm7n1_atanh_to(oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_asinh(   oarrm7n1_t* arr);
  void    oarrm7n1_asinh_to(oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_acosh(   oarrm7n1_t* arr);
  void    oarrm7n1_acosh_to(oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_tanh(    oarrm7n1_t* arr);
  void    oarrm7n1_tanh_to( oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_cbrt(    oarrm7n1_t* arr);
  void    oarrm7n1_cbrt_to( oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_sqrt(    oarrm7n1_t* arr);
  void    oarrm7n1_sqrt_to( oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_cosh(    oarrm7n1_t* arr);
  void    oarrm7n1_cosh_to( oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_sinh(    oarrm7n1_t* arr);
  void    oarrm7n1_sinh_to( oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_asin(    oarrm7n1_t* arr);
  void    oarrm7n1_asin_to( oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_acos(    oarrm7n1_t* arr);
  void    oarrm7n1_acos_to( oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_atan(    oarrm7n1_t* arr);
  void    oarrm7n1_atan_to( oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_tan(     oarrm7n1_t* arr);
  void    oarrm7n1_tan_to(  oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_cos(     oarrm7n1_t* arr);
  void    oarrm7n1_cos_to(  oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_sin(     oarrm7n1_t* arr);
  void    oarrm7n1_sin_to(  oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_logb(    oarrm7n1_t* arr, double base);
  void    oarrm7n1_logb_to( oarrm7n1_t* arr, double base, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_log10(   oarrm7n1_t* arr);
  void    oarrm7n1_log10_to(oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_log(     oarrm7n1_t* arr);
  void    oarrm7n1_log_to(  oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_exp(     oarrm7n1_t* arr);
  void    oarrm7n1_exp_to(  oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_pow(     oarrm7n1_t* arr, double e);
  void    oarrm7n1_pow_to(  oarrm7n1_t* arr, double e, oarrm7n1_t* res);
  
  
  # From ../../../include/oti/static/onumm7n1/array/algebra_elementwise.h
  
  oarrm7n1_t oarrm7n1_neg(oarrm7n1_t* arr);
  void oarrm7n1_neg_to(oarrm7n1_t* rhs, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_sum_OO(oarrm7n1_t*   lhs, oarrm7n1_t* rhs);
  oarrm7n1_t oarrm7n1_sum_RO(darr_t*    lhs, oarrm7n1_t* rhs);
  oarrm7n1_t oarrm7n1_sum_oO(onumm7n1_t* lhs, oarrm7n1_t* rhs);
  oarrm7n1_t oarrm7n1_sum_rO(coeff_t    lhs, oarrm7n1_t* rhs);
  void oarrm7n1_sum_OO_to(oarrm7n1_t*   lhs, oarrm7n1_t* rhs, oarrm7n1_t* res);
  void oarrm7n1_sum_RO_to(darr_t*    lhs, oarrm7n1_t* rhs, oarrm7n1_t* res);
  void oarrm7n1_sum_oO_to(onumm7n1_t* lhs, oarrm7n1_t* rhs, oarrm7n1_t* res);
  void oarrm7n1_sum_rO_to(coeff_t    lhs, oarrm7n1_t* rhs, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_sub_OO(oarrm7n1_t*   lhs, oarrm7n1_t*   rhs);
  oarrm7n1_t oarrm7n1_sub_RO(darr_t*    lhs, oarrm7n1_t*   rhs);
  oarrm7n1_t oarrm7n1_sub_OR(oarrm7n1_t*   lhs, darr_t*    rhs);
  oarrm7n1_t oarrm7n1_sub_oO(onumm7n1_t* lhs, oarrm7n1_t*   rhs);
  oarrm7n1_t oarrm7n1_sub_Oo(oarrm7n1_t*   lhs, onumm7n1_t* rhs);
  oarrm7n1_t oarrm7n1_sub_rO(coeff_t    lhs, oarrm7n1_t*   rhs);
  oarrm7n1_t oarrm7n1_sub_Or(oarrm7n1_t*   lhs, coeff_t    rhs);
  void oarrm7n1_sub_OO_to( oarrm7n1_t*   lhs, oarrm7n1_t*   rhs, oarrm7n1_t* res);
  void oarrm7n1_sub_RO_to( darr_t*    lhs, oarrm7n1_t*   rhs, oarrm7n1_t* res);
  void oarrm7n1_sub_OR_to( oarrm7n1_t*   lhs, darr_t*    rhs, oarrm7n1_t* res);
  void oarrm7n1_sub_oO_to( onumm7n1_t* lhs, oarrm7n1_t*   rhs, oarrm7n1_t* res);
  void oarrm7n1_sub_Oo_to( oarrm7n1_t*   lhs, onumm7n1_t* rhs, oarrm7n1_t* res);
  void oarrm7n1_sub_rO_to( coeff_t    lhs, oarrm7n1_t*   rhs, oarrm7n1_t* res);
  void oarrm7n1_sub_Or_to( oarrm7n1_t*   lhs, coeff_t    rhs, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_mul_OO(oarrm7n1_t*   lhs, oarrm7n1_t* rhs);
  oarrm7n1_t oarrm7n1_mul_RO(darr_t*    lhs, oarrm7n1_t* rhs);
  oarrm7n1_t oarrm7n1_mul_oO(onumm7n1_t* lhs, oarrm7n1_t* rhs);
  oarrm7n1_t oarrm7n1_mul_rO(coeff_t    lhs, oarrm7n1_t* rhs);
  void oarrm7n1_mul_OO_to(oarrm7n1_t*   lhs, oarrm7n1_t* rhs, oarrm7n1_t* res);
  void oarrm7n1_mul_RO_to(darr_t*    lhs, oarrm7n1_t* rhs, oarrm7n1_t* res);
  void oarrm7n1_mul_oO_to(onumm7n1_t* lhs, oarrm7n1_t* rhs, oarrm7n1_t* res);
  void oarrm7n1_mul_rO_to(coeff_t    lhs, oarrm7n1_t* rhs, oarrm7n1_t* res);
  void oarrm7n1_gem_OO_to(  oarrm7n1_t* arr1, oarrm7n1_t* arr2, oarrm7n1_t* arr3, oarrm7n1_t* res);
  void oarrm7n1_gem_oO_to(onumm7n1_t* arr1, oarrm7n1_t* arr2, oarrm7n1_t* arr3, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_div_OO(oarrm7n1_t*   lhs, oarrm7n1_t*   rhs);
  oarrm7n1_t oarrm7n1_div_OR(oarrm7n1_t*   lhs, darr_t*    rhs);
  oarrm7n1_t oarrm7n1_div_RO(darr_t*    lhs, oarrm7n1_t*   rhs);
  oarrm7n1_t oarrm7n1_div_oO(onumm7n1_t* lhs, oarrm7n1_t*   rhs);
  oarrm7n1_t oarrm7n1_div_Oo(oarrm7n1_t*   lhs, onumm7n1_t* rhs);
  oarrm7n1_t oarrm7n1_div_rO(coeff_t    lhs, oarrm7n1_t*   rhs);
  oarrm7n1_t oarrm7n1_div_Or(oarrm7n1_t*   lhs, coeff_t    rhs);
  void oarrm7n1_div_OO_to(oarrm7n1_t*   lhs, oarrm7n1_t*   rhs, oarrm7n1_t* res);
  void oarrm7n1_div_RO_to(darr_t*    lhs, oarrm7n1_t*   rhs, oarrm7n1_t* res);
  void oarrm7n1_div_OR_to(oarrm7n1_t*   lhs, darr_t*    rhs, oarrm7n1_t* res);
  void oarrm7n1_div_oO_to(onumm7n1_t* lhs, oarrm7n1_t*   rhs, oarrm7n1_t* res);
  void oarrm7n1_div_Oo_to(oarrm7n1_t*   lhs, onumm7n1_t* rhs, oarrm7n1_t* res);
  void oarrm7n1_div_rO_to(coeff_t    lhs, oarrm7n1_t*   rhs, oarrm7n1_t* res);
  void oarrm7n1_div_Or_to(oarrm7n1_t*   lhs, coeff_t    rhs, oarrm7n1_t* res);
  
  
  # From ../../../include/oti/static/onumm7n1/array/base.h
  
  void    oarrm7n1_taylor_integrate_to( coeff_t* deltas, oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_taylor_integrate(    coeff_t* deltas, oarrm7n1_t* arr);
  void    oarrm7n1_get_order_im_to( ord_t order, oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_get_order_im(    ord_t order, oarrm7n1_t* arr);
  void oarrm7n1_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm7n1_t* res);
  void oarrm7n1_set_slice_O( oarrm7n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm7n1_t* res);
  void oarrm7n1_set_slice_o( onumm7n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_get_slice( oarrm7n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm7n1_get_slice_to( oarrm7n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_truncate_im(    imdir_t idx, ord_t order, oarrm7n1_t* arr);
  void    oarrm7n1_truncate_im_to( imdir_t idx, ord_t order, oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_extract_im(   imdir_t idx, ord_t order, oarrm7n1_t* arr);
  void    oarrm7n1_extract_im_to(imdir_t idx, ord_t order, oarrm7n1_t* arr, oarrm7n1_t* res);
  darr_t  oarrm7n1_get_deriv(    imdir_t idx, ord_t order, oarrm7n1_t* arr);
  void    oarrm7n1_get_deriv_to( imdir_t idx, ord_t order, oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_get_deriv_o(  imdir_t idx, ord_t order, oarrm7n1_t* arr);
  oarrm7n1_t oarrm7n1_extract_deriv(    imdir_t idx, ord_t order, oarrm7n1_t* arr);
  void    oarrm7n1_extract_deriv_to( imdir_t idx, ord_t order, oarrm7n1_t* arr, oarrm7n1_t* res);
  darr_t  oarrm7n1_get_im(   imdir_t idx, ord_t order, oarrm7n1_t* arr);
  oarrm7n1_t oarrm7n1_get_im_o( imdir_t idx, ord_t order, oarrm7n1_t* arr);
  void    oarrm7n1_get_im_to(imdir_t idx, ord_t order, oarrm7n1_t* arr, oarrm7n1_t* res);
  void    oarrm7n1_copy_to(oarrm7n1_t* arr, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_copy(oarrm7n1_t* arr);
  void oarrm7n1_set_all_r( coeff_t num, oarrm7n1_t* arr);
  void oarrm7n1_set_item_i_r( coeff_t num, uint64_t i, oarrm7n1_t* arr);
  void oarrm7n1_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm7n1_t* arr);
  void oarrm7n1_set_r(   coeff_t  num,   oarrm7n1_t* arr);
  void oarrm7n1_set_o( onumm7n1_t* num,   oarrm7n1_t* arr);
  void oarrm7n1_set_O(   oarrm7n1_t* arrin, oarrm7n1_t* arr);
  void oarrm7n1_set_all_o( onumm7n1_t* src, oarrm7n1_t* arr);
  void oarrm7n1_set_item_i_o( onumm7n1_t* num, uint64_t i, oarrm7n1_t* arr);
  void oarrm7n1_set_item_ij_o( onumm7n1_t* num, uint64_t i, uint64_t j, oarrm7n1_t* arr);
  onumm7n1_t oarrm7n1_get_item_i(    oarrm7n1_t* arr, uint64_t i);
  void      oarrm7n1_get_item_i_to( oarrm7n1_t* arr, uint64_t i,             onumm7n1_t* res);
  onumm7n1_t oarrm7n1_get_item_ij(   oarrm7n1_t* arr, uint64_t i, uint64_t j);
  void      oarrm7n1_get_item_ij_to(oarrm7n1_t* arr, uint64_t i, uint64_t j, onumm7n1_t* res);
  oarrm7n1_t oarrm7n1_init();
  void oarrm7n1_free(oarrm7n1_t* arr);
  oarrm7n1_t oarrm7n1_empty_like(oarrm7n1_t* arr);
  oarrm7n1_t oarrm7n1_eye(uint64_t nrows);
  oarrm7n1_t oarrm7n1_ones(uint64_t nrows, uint64_t ncols);
  oarrm7n1_t oarrm7n1_zeros(uint64_t nrows, uint64_t ncols);
  oarrm7n1_t oarrm7n1_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm7n1/array/utils.h
  
  void oarrm7n1_dimCheck_OO_elementwise(oarrm7n1_t* arr1, oarrm7n1_t* arr2, oarrm7n1_t* res);
  void oarrm7n1_dimCheck_RO_elementwise(darr_t*  arr1, oarrm7n1_t* arr2, oarrm7n1_t* res);
  void oarrm7n1_dimCheck_OO_matmul(oarrm7n1_t* arr1, oarrm7n1_t* arr2, oarrm7n1_t* res);
  void oarrm7n1_dimCheck_RO_matmul(darr_t*  arr1, oarrm7n1_t* arr2, oarrm7n1_t* res);
  void oarrm7n1_dimCheck_OR_matmul(oarrm7n1_t* arr1, darr_t*  arr2, oarrm7n1_t* res);
  void oarrm7n1_dimCheck_O_squareness(oarrm7n1_t* arr1, oarrm7n1_t* res);
  void oarrm7n1_dimCheck_OO_samesize(oarrm7n1_t* arr1, oarrm7n1_t* res);
  void oarrm7n1_dimCheck_RO_samesize(darr_t* arr1, oarrm7n1_t* res);
  ord_t oarrm7n1_get_order(oarrm7n1_t* arr);
  void oarrm7n1_get_active_bases(oarrm7n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm7n1/array/algebra_matops.h
  
  onumm7n1_t oarrm7n1_dotproduct_OO(    oarrm7n1_t* lhs, oarrm7n1_t* rhs);
  void      oarrm7n1_dotproduct_OO_to( oarrm7n1_t* lhs, oarrm7n1_t* rhs, onumm7n1_t* res);
  onumm7n1_t oarrm7n1_dotproduct_RO(     darr_t* lhs, oarrm7n1_t* rhs);
  void      oarrm7n1_dotproduct_RO_to(  darr_t* lhs, oarrm7n1_t* rhs, onumm7n1_t* res);
  oarrm7n1_t oarrm7n1_matmul_OO(    oarrm7n1_t* lhs, oarrm7n1_t* rhs);
  oarrm7n1_t oarrm7n1_matmul_OR(    oarrm7n1_t* lhs,  darr_t* rhs);
  oarrm7n1_t oarrm7n1_matmul_RO(     darr_t* lhs, oarrm7n1_t* rhs);
  void    oarrm7n1_matmul_OO_to( oarrm7n1_t* lhs, oarrm7n1_t* rhs, oarrm7n1_t* res);
  void    oarrm7n1_matmul_OR_to( oarrm7n1_t* lhs,  darr_t* rhs, oarrm7n1_t* res);
  void    oarrm7n1_matmul_RO_to(  darr_t* lhs, oarrm7n1_t* rhs, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_transpose(    oarrm7n1_t* arr1);
  void    oarrm7n1_transpose_to( oarrm7n1_t* arr1, oarrm7n1_t* res);
  oarrm7n1_t oarrm7n1_invert(    oarrm7n1_t* arr1);
  void    oarrm7n1_invert_to( oarrm7n1_t* arr1, oarrm7n1_t* res);
  onumm7n1_t oarrm7n1_det(    oarrm7n1_t* arr1);
  void      oarrm7n1_det_to( oarrm7n1_t* arr1, onumm7n1_t* res);
  onumm7n1_t oarrm7n1_norm(    oarrm7n1_t* arr1);
  void      oarrm7n1_norm_to( oarrm7n1_t* arr1,  onumm7n1_t* res);
  onumm7n1_t oarrm7n1_pnorm(    oarrm7n1_t* arr1, coeff_t p);
  void      oarrm7n1_pnorm_to( oarrm7n1_t* arr1, coeff_t p, onumm7n1_t* res);
  
  
  # From ../../../include/oti/static/onumm7n1/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm7n1/array/gauss/functions.h
  
  feoarrm7n1_t feoarrm7n1_atanh(    feoarrm7n1_t* arr);
  void      feoarrm7n1_atanh_to( feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_asinh(    feoarrm7n1_t* arr);
  void      feoarrm7n1_asinh_to( feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_acosh(    feoarrm7n1_t* arr);
  void      feoarrm7n1_acosh_to( feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_tanh(     feoarrm7n1_t* arr);
  void      feoarrm7n1_tanh_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sinh(     feoarrm7n1_t* arr);
  void      feoarrm7n1_sinh_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_cosh(     feoarrm7n1_t* arr);
  void      feoarrm7n1_cosh_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_atan(     feoarrm7n1_t* arr);
  void      feoarrm7n1_atan_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_asin(     feoarrm7n1_t* arr);
  void      feoarrm7n1_asin_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_acos(     feoarrm7n1_t* arr);
  void      feoarrm7n1_acos_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_tan(      feoarrm7n1_t* arr);
  void      feoarrm7n1_tan_to(   feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sin(      feoarrm7n1_t* arr);
  void      feoarrm7n1_sin_to(   feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_cos(      feoarrm7n1_t* arr);
  void      feoarrm7n1_cos_to(   feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_logb(     feoarrm7n1_t* arr, double base);
  void      feoarrm7n1_logb_to(  feoarrm7n1_t* arr, double base, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_log10(    feoarrm7n1_t* arr);
  void      feoarrm7n1_log10_to( feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_log(      feoarrm7n1_t* arr);
  void      feoarrm7n1_log_to(   feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_exp(      feoarrm7n1_t* arr);
  void      feoarrm7n1_exp_to(   feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_cbrt(     feoarrm7n1_t* arr);
  void      feoarrm7n1_cbrt_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sqrt(     feoarrm7n1_t* arr);
  void      feoarrm7n1_sqrt_to(  feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_pow(      feoarrm7n1_t* arr, double e);
  void      feoarrm7n1_pow_to(   feoarrm7n1_t* arr, double e, feoarrm7n1_t* res);
  
  
  # From ../../../include/oti/static/onumm7n1/array/gauss/base.h
  
  void      feoarrm7n1_get_order_im_to( ord_t order, feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_get_order_im(    ord_t order, feoarrm7n1_t* arr);
  feoarrm7n1_t feoarrm7n1_get_deriv(   imdir_t idx, ord_t order, feoarrm7n1_t* arr);
  void      feoarrm7n1_get_deriv_to(imdir_t idx, ord_t order, feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_get_im(      imdir_t idx, ord_t order, feoarrm7n1_t* arr);
  void      feoarrm7n1_get_im_to(   imdir_t idx, ord_t order, feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_truncate_im(   imdir_t idx, ord_t order, feoarrm7n1_t* arr);
  void      feoarrm7n1_truncate_im_to(imdir_t idx, ord_t order, feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_copy(   feoarrm7n1_t* src);
  void      feoarrm7n1_copy_to(feoarrm7n1_t* src, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_get_im(    imdir_t idx, ord_t order, feoarrm7n1_t* arr);
  void      feoarrm7n1_get_im_to( imdir_t idx, ord_t order, feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_get_deriv(    imdir_t idx, ord_t order, feoarrm7n1_t* arr);
  void      feoarrm7n1_get_deriv_to( imdir_t idx, ord_t order, feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_extract_im(    imdir_t idx, ord_t order, feoarrm7n1_t* arr);
  void      feoarrm7n1_extract_im_to( imdir_t idx, ord_t order, feoarrm7n1_t* arr,  feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_extract_deriv(    imdir_t idx, ord_t order, feoarrm7n1_t* arr);
  void      feoarrm7n1_extract_deriv_to( imdir_t idx, ord_t order, feoarrm7n1_t* arr, feoarrm7n1_t* res);
  oarrm7n1_t   feoarrm7n1_get_item_k(  feoarrm7n1_t* arr, uint64_t k);
  feonumm7n1_t  feoarrm7n1_get_item_ij( feoarrm7n1_t* arr, uint64_t i, uint64_t j);
  onumm7n1_t feoarrm7n1_get_item_ijk(feoarrm7n1_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm7n1_get_item_ij_to(  feoarrm7n1_t* arr, uint64_t i, uint64_t j,
                                 feonumm7n1_t* res);
  void feoarrm7n1_get_item_k_to(   feoarrm7n1_t* arr, uint64_t k,
                                  oarrm7n1_t* res);
  void feoarrm7n1_get_item_ijk_to( feoarrm7n1_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_get_slice(feoarrm7n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm7n1_get_slice_to(feoarrm7n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n1_t* res);
  void feoarrm7n1_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm7n1_t* res);
  void feoarrm7n1_set_item_ij_o(  onumm7n1_t* elm, uint64_t i, uint64_t j,
                               feoarrm7n1_t* res);
  void feoarrm7n1_set_item_ij_f(  feonumm7n1_t* elm, uint64_t i, uint64_t j,
                              feoarrm7n1_t* res);
  void feoarrm7n1_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm7n1_t* res);
  void feoarrm7n1_set_item_k_o(  onumm7n1_t* elm, uint64_t k,
                              feoarrm7n1_t* res);
  void feoarrm7n1_set_item_k_R(    oarrm7n1_t* elm, uint64_t k,
                            feoarrm7n1_t* res);
  void feoarrm7n1_set_item_k_O(    oarrm7n1_t* elm, uint64_t k,
                            feoarrm7n1_t* res);
  void feoarrm7n1_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm7n1_t* res);
  void feoarrm7n1_set_item_ijk_o( onumm7n1_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm7n1_t* res);
  void feoarrm7n1_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n1_t* res);
  void feoarrm7n1_set_slice_o( onumm7n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n1_t* res);
  void feoarrm7n1_set_slice_f( feonumm7n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n1_t* res);
  void feoarrm7n1_set_slice_O( oarrm7n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n1_t* res);
  void feoarrm7n1_set_slice_F( feoarrm7n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm7n1_t* res);
  void feoarrm7n1_set_all_o( onumm7n1_t* num, feoarrm7n1_t* arr );
  void feoarrm7n1_set_all_r(   coeff_t  num, feoarrm7n1_t* arr );
  void feoarrm7n1_set_all_f(  feonumm7n1_t* num, feoarrm7n1_t* arr );
  void feoarrm7n1_set_r(    coeff_t src, feoarrm7n1_t* res );
  void feoarrm7n1_set_o( onumm7n1_t* src, feoarrm7n1_t* res );
  void feoarrm7n1_set_f(  feonumm7n1_t* src, feoarrm7n1_t* res );
  void feoarrm7n1_set_R(    darr_t* src, feoarrm7n1_t* res );
  void feoarrm7n1_set_O(   oarrm7n1_t* src, feoarrm7n1_t* res );
  void feoarrm7n1_set_F( feoarrm7n1_t* src, feoarrm7n1_t* res );
  feoarrm7n1_t feoarrm7n1_eye( uint64_t size,  uint64_t nip);
  feoarrm7n1_t feoarrm7n1_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm7n1_t feoarrm7n1_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm7n1_t feoarrm7n1_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm7n1_free(feoarrm7n1_t* arr);
  feoarrm7n1_t feoarrm7n1_init();
  ord_t feoarrm7n1_get_order(feoarrm7n1_t* arr);
  
  
  # From ../../../include/oti/static/onumm7n1/array/gauss/utils.h
  
  void feoarrm7n1_dimCheck_FF_samesize(feoarrm7n1_t* arr1, feoarrm7n1_t* arr2, feonumm7n1_t* res);
  void feoarrm7n1_dimCheck_OF_samesize(  oarrm7n1_t* arr1, feoarrm7n1_t* arr2, feonumm7n1_t* res);
  void feoarrm7n1_dimCheck_RF_samesize(   darr_t* arr1, feoarrm7n1_t* arr2, feonumm7n1_t* res);
  void feoarrm7n1_dimCheck_FF_elementwise(feoarrm7n1_t* arr1, feoarrm7n1_t* arr2, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_OF_elementwise(  oarrm7n1_t* arr1, feoarrm7n1_t* arr2, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm7n1_t* arr2, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_fF_elementwise( feonumm7n1_t* num1, feoarrm7n1_t* arr2, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_Ff_elementwise(feoarrm7n1_t* arr1,  feonumm7n1_t* num2, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_FF_matmul( feoarrm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_OF_matmul(   oarrm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_FO_matmul( feoarrm7n1_t* lhs,   oarrm7n1_t* rhs, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_FR_matmul( feoarrm7n1_t* lhs,    darr_t* rhs, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_F_squareness( feoarrm7n1_t* arr1, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_F_transpose( feoarrm7n1_t* arr1, feoarrm7n1_t* res);
  void feoarrm7n1_dimCheck_FfO_integrate(feoarrm7n1_t* arr, feonumm7n1_t* num,oarrm7n1_t* res);
  void feoarrm7n1_get_active_bases(feoarrm7n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm7n1/array/gauss/algebra.h
  
  feoarrm7n1_t feoarrm7n1_neg(    feoarrm7n1_t* arr);
  void      feoarrm7n1_neg_to( feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sum_FF(   feoarrm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sum_FF_to(feoarrm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sum_fF(    feonumm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sum_fF_to( feonumm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sum_OF(     oarrm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sum_OF_to(  oarrm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sum_RF(      darr_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sum_RF_to(   darr_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sum_oF(   onumm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sum_oF_to(onumm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sum_rF(     coeff_t  lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sum_rF_to(  coeff_t  lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sub_FF(    feoarrm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sub_FF_to( feoarrm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sub_fF(    feonumm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sub_fF_to( feonumm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sub_Ff(    feoarrm7n1_t* lhs, feonumm7n1_t* rhs);
  void      feoarrm7n1_sub_Ff_to( feoarrm7n1_t* lhs, feonumm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sub_OF(      oarrm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sub_OF_to(   oarrm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sub_FO(    feoarrm7n1_t* lhs,   oarrm7n1_t* rhs);
  void      feoarrm7n1_sub_FO_to( feoarrm7n1_t* lhs,   oarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sub_RF(       darr_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sub_RF_to(    darr_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sub_FR(    feoarrm7n1_t* lhs,    darr_t* rhs);
  void      feoarrm7n1_sub_FR_to( feoarrm7n1_t* lhs,    darr_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sub_oF(    onumm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sub_oF_to( onumm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sub_Fo(    feoarrm7n1_t* lhs, onumm7n1_t* rhs);
  void      feoarrm7n1_sub_Fo_to( feoarrm7n1_t* lhs, onumm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sub_rF(      coeff_t  lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_sub_rF_to(    coeff_t lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_sub_Fr(    feoarrm7n1_t* lhs,   coeff_t  rhs);
  void      feoarrm7n1_sub_Fr_to( feoarrm7n1_t* lhs,   coeff_t  rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_mul_FF(   feoarrm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_mul_FF_to(feoarrm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_mul_fF(    feonumm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_mul_fF_to( feonumm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_mul_OF(     oarrm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_mul_OF_to(  oarrm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_mul_RF(      darr_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_mul_RF_to(   darr_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_mul_oF(   onumm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_mul_oF_to(onumm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_mul_rF(     coeff_t  lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_mul_rF_to(  coeff_t  lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_div_FF(    feoarrm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_div_FF_to( feoarrm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_div_fF(     feonumm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_div_fF_to(  feonumm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_div_Ff(    feoarrm7n1_t* lhs,  feonumm7n1_t* rhs);
  void      feoarrm7n1_div_Ff_to( feoarrm7n1_t* lhs,  feonumm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_div_OF(      oarrm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_div_OF_to(   oarrm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_div_FO(    feoarrm7n1_t* lhs,   oarrm7n1_t* rhs);
  void      feoarrm7n1_div_FO_to( feoarrm7n1_t* lhs,   oarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_div_RF(       darr_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_div_RF_to(    darr_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_div_FR(    feoarrm7n1_t* lhs,    darr_t* rhs);
  void      feoarrm7n1_div_FR_to( feoarrm7n1_t* lhs,    darr_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_div_oF(    onumm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_div_oF_to( onumm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_div_Fo(    feoarrm7n1_t* lhs, onumm7n1_t* rhs);
  void      feoarrm7n1_div_Fo_to( feoarrm7n1_t* lhs, onumm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_div_rF(      coeff_t  lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_div_rF_to(    coeff_t lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_div_Fr(    feoarrm7n1_t* lhs,   coeff_t  rhs);
  void      feoarrm7n1_div_Fr_to( feoarrm7n1_t* lhs,   coeff_t  rhs, feoarrm7n1_t* res);
  oarrm7n1_t feoarrm7n1_integrate(    feoarrm7n1_t* arr, feonumm7n1_t* w);
  void    feoarrm7n1_integrate_to( feoarrm7n1_t* arr, feonumm7n1_t* w, oarrm7n1_t* res);
  feonumm7n1_t feoarrm7n1_dotproduct_FF(    feoarrm7n1_t* lhs, feoarrm7n1_t* rhs);
  void     feoarrm7n1_dotproduct_FF_to( feoarrm7n1_t* lhs, feoarrm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feoarrm7n1_dotproduct_OF(      oarrm7n1_t* lhs, feoarrm7n1_t* rhs);
  void     feoarrm7n1_dotproduct_OF_to(   oarrm7n1_t* lhs, feoarrm7n1_t* rhs, feonumm7n1_t* res);
  feonumm7n1_t feoarrm7n1_dotproduct_RF(       darr_t* lhs, feoarrm7n1_t* rhs);
  void     feoarrm7n1_dotproduct_RF_to(    darr_t* lhs, feoarrm7n1_t* rhs, feonumm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_matmul_FF(    feoarrm7n1_t* lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_matmul_FF_to( feoarrm7n1_t* lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_matmul_OF(    oarrm7n1_t*   lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_matmul_OF_to( oarrm7n1_t*   lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_matmul_FO(    feoarrm7n1_t* lhs, oarrm7n1_t*   rhs);
  void      feoarrm7n1_matmul_FO_to( feoarrm7n1_t* lhs, oarrm7n1_t*   rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_matmul_RF(    darr_t*    lhs, feoarrm7n1_t* rhs);
  void      feoarrm7n1_matmul_RF_to( darr_t*    lhs, feoarrm7n1_t* rhs, feoarrm7n1_t* res);
  feoarrm7n1_t feoarrm7n1_matmul_FR(    feoarrm7n1_t* lhs, darr_t*    rhs);
  void      feoarrm7n1_matmul_FR_to( feoarrm7n1_t* lhs, darr_t*    rhs, feoarrm7n1_t* res);
  feonumm7n1_t feoarrm7n1_det(   feoarrm7n1_t* arr);
  void     feoarrm7n1_det_to(feoarrm7n1_t* arr, feonumm7n1_t* res);
  feonumm7n1_t feoarrm7n1_norm(     feoarrm7n1_t* arr);
  void     feoarrm7n1_norm_to(  feoarrm7n1_t* arr, feonumm7n1_t* res);
  feonumm7n1_t feoarrm7n1_pnorm(    feoarrm7n1_t* arr, coeff_t p);
  void     feoarrm7n1_pnorm_to( feoarrm7n1_t* arr, coeff_t p, feonumm7n1_t* res);
  feoarrm7n1_t   feoarrm7n1_invert(    feoarrm7n1_t* arr);
  void        feoarrm7n1_invert_to( feoarrm7n1_t* arr, feoarrm7n1_t* res);
  feoarrm7n1_t   feoarrm7n1_transpose(   feoarrm7n1_t* arr);
  void        feoarrm7n1_transpose_to(feoarrm7n1_t* arr, feoarrm7n1_t* res);
  
  