cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm4n1/scalar/structures.h
  
  ctypedef struct  onumm4n1_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
  # } onumm4n1_t;
  
  
  # From ../../../include/oti/static/onumm4n1/array/structures.h
  
  ctypedef struct  oarrm4n1_t : # {
      onumm4n1_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm4n1_t;
  
  
  # From ../../../include/oti/static/onumm4n1/scalar/gauss/structures.h
  
  ctypedef struct  feonumm4n1_t: # {
      onumm4n1_t*  p_data;
      uint64_t    nip;
  # } feonumm4n1_t;
  
  
  # From ../../../include/oti/static/onumm4n1/array/gauss/structures.h
  
  ctypedef struct  feoarrm4n1_t: # {
      oarrm4n1_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm4n1_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm4n1/scalar/functions.h
  
  onumm4n1_t onumm4n1_atanh(onumm4n1_t* num);
  void onumm4n1_atanh_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_asinh(onumm4n1_t* num);
  void onumm4n1_asinh_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_acosh(onumm4n1_t* num);
  void onumm4n1_acosh_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_tanh(onumm4n1_t* num);
  void onumm4n1_tanh_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_sqrt(onumm4n1_t* num);
  void onumm4n1_sqrt_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_cbrt(onumm4n1_t* num);
  void onumm4n1_cbrt_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_cosh(onumm4n1_t* num);
  void onumm4n1_cosh_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_sinh(onumm4n1_t* num);
  void onumm4n1_sinh_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_asin(onumm4n1_t* num);
  void onumm4n1_asin_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_acos(onumm4n1_t* num);
  void onumm4n1_acos_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_atan(onumm4n1_t* num);
  void onumm4n1_atan_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_tan(onumm4n1_t* num);
  void onumm4n1_tan_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_cos(onumm4n1_t* num);
  void onumm4n1_cos_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_sin(onumm4n1_t* num );
  void onumm4n1_sin_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_logb(onumm4n1_t* num, double base);
  void onumm4n1_logb_to(onumm4n1_t* num, double base, onumm4n1_t* res);
  onumm4n1_t onumm4n1_log10(onumm4n1_t* num);
  void onumm4n1_log10_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_log(onumm4n1_t* num);
  void onumm4n1_log_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_exp(onumm4n1_t* num);
  void onumm4n1_exp_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_pow(onumm4n1_t* num, double e);
  void onumm4n1_pow_to(onumm4n1_t* num, coeff_t e, onumm4n1_t* res);
  
  
  # From ../../../include/oti/static/onumm4n1/scalar/base.h
  
  void onumm4n1_set_im_o(onumm4n1_t* num, imdir_t idx, ord_t order, onumm4n1_t* res);
  void onumm4n1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm4n1_t* res);
  void onumm4n1_set_deriv_o(onumm4n1_t* num, imdir_t idx, ord_t order, onumm4n1_t* res);
  void onumm4n1_extract_im_to( imdir_t idx, ord_t order, onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_extract_im(imdir_t idx, ord_t order, onumm4n1_t* num);
  onumm4n1_t onumm4n1_extract_deriv(imdir_t idx, ord_t order, onumm4n1_t* num);
  void onumm4n1_extract_deriv_to(imdir_t idx, ord_t order, onumm4n1_t* num, onumm4n1_t* res);
  void onumm4n1_get_im_to_o(imdir_t idx, ord_t order, onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_get_im_o(imdir_t idx, ord_t order, onumm4n1_t* num);
  void onumm4n1_get_im_to_r(imdir_t idx, ord_t order, onumm4n1_t* num, coeff_t* res);
  ord_t onumm4n1_get_order(onumm4n1_t* lhs);
  onumm4n1_t onumm4n1_get_deriv_o( imdir_t idx, ord_t order, onumm4n1_t* num);
  void onumm4n1_get_deriv_to( imdir_t idx, ord_t order, onumm4n1_t* num, onumm4n1_t* res);
  void onumm4n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm4n1_t* res);
  onumm4n1_t onumm4n1_init();
  ndir_t onumm4n1_get_ndir_order(ord_t order, onumm4n1_t* num);
  ndir_t onumm4n1_get_ndir_total(onumm4n1_t* num);
  coeff_t* onumm4n1_get_order_address(ord_t order, onumm4n1_t* num);
  onumm4n1_t onumm4n1_create_r(  coeff_t lhs);
  void onumm4n1_set_r(  coeff_t lhs, onumm4n1_t* res);
  void onumm4n1_set_o(  onumm4n1_t* lhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_get_order_im(ord_t order, onumm4n1_t* lhs);
  void onumm4n1_get_order_im_to(ord_t order, onumm4n1_t* lhs, onumm4n1_t* res);
  coeff_t onumm4n1_get_item(imdir_t idx, ord_t order, onumm4n1_t* lhs);
  coeff_t onumm4n1_get_deriv(imdir_t idx, ord_t order, onumm4n1_t* lhs);
  void onumm4n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm4n1_t* x);
  onumm4n1_t onumm4n1_copy(  onumm4n1_t* lhs);
  void onumm4n1_copy_to(  onumm4n1_t* lhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_taylor_integrate(coeff_t* deltas,onumm4n1_t* lhs);
  void onumm4n1_taylor_integrate_to(coeff_t* deltas,onumm4n1_t* lhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_truncate_im(imdir_t idx, ord_t order, onumm4n1_t* lhs);
  void onumm4n1_truncate_im_to(imdir_t idx, ord_t order, onumm4n1_t* lhs, onumm4n1_t* res);
  void onumm4n1_print(  onumm4n1_t* lhs);
  imdir_t onumm4n1_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm4n1/scalar/utils.h
  
  void onumm4n1_get_active_bases(onumm4n1_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm4n1/scalar/algebra.h
  
  onumm4n1_t onumm4n1_abs(onumm4n1_t* num);
  onumm4n1_t onumm4n1_div_ro(coeff_t num, onumm4n1_t* den);
  onumm4n1_t onumm4n1_div_oo(onumm4n1_t* num, onumm4n1_t* den);
  onumm4n1_t onumm4n1_div_or(onumm4n1_t* num, coeff_t val);
  void onumm4n1_div_ro_to(coeff_t num, onumm4n1_t* den, onumm4n1_t* res);
  void onumm4n1_div_oo_to(onumm4n1_t* num, onumm4n1_t* den, onumm4n1_t* res);
  void onumm4n1_div_or_to(onumm4n1_t* num, coeff_t val, onumm4n1_t* res);
  void onumm4n1_abs_to(onumm4n1_t* num, onumm4n1_t* res);
  onumm4n1_t onumm4n1_neg(  onumm4n1_t* lhs);
  void onumm4n1_neg_to(  onumm4n1_t* lhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_sum_oo(  onumm4n1_t* lhs,  onumm4n1_t* rhs);
  void onumm4n1_sum_oo_to(  onumm4n1_t* lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_sum_ro(  coeff_t lhs,  onumm4n1_t* rhs);
  void onumm4n1_sum_ro_to(  coeff_t lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_sub_oo(  onumm4n1_t* lhs,  onumm4n1_t* rhs);
  void onumm4n1_sub_oo_to(  onumm4n1_t* lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_sub_ro(  coeff_t lhs,  onumm4n1_t* rhs);
  void onumm4n1_sub_ro_to(  coeff_t lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_sub_or(  onumm4n1_t* lhs,  coeff_t rhs);
  void onumm4n1_sub_or_to(  onumm4n1_t* lhs,  coeff_t rhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_mul_oo(  onumm4n1_t* lhs,  onumm4n1_t* rhs);
  void onumm4n1_mul_oo_to(  onumm4n1_t* lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_mul_ro(  coeff_t lhs,  onumm4n1_t* rhs);
  void onumm4n1_mul_ro_to(  coeff_t lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_trunc_mul_oo(  onumm4n1_t* lhs,  onumm4n1_t* rhs);
  void onumm4n1_trunc_mul_oo_to(  onumm4n1_t* lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
  onumm4n1_t onumm4n1_gem_oo(  onumm4n1_t* a,  onumm4n1_t* b,  onumm4n1_t* c);
  void onumm4n1_gem_oo_to(  onumm4n1_t* a,  onumm4n1_t* b,  onumm4n1_t* c, onumm4n1_t* res);
  onumm4n1_t onumm4n1_gem_ro(  coeff_t a,  onumm4n1_t* b,  onumm4n1_t* c);
  void onumm4n1_gem_ro_to(  coeff_t a,  onumm4n1_t* b,  onumm4n1_t* c, onumm4n1_t* res);
  void onumm4n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm4n1_t* a,  ord_t ord_rhs,  onumm4n1_t* b,  onumm4n1_t* c, onumm4n1_t* res);
  onumm4n1_t onumm4n1_feval(coeff_t* feval_re, onumm4n1_t* x);
  void onumm4n1_feval_to(coeff_t* feval_re, onumm4n1_t* x, onumm4n1_t* res);
  
  
  # From ../../../include/oti/static/onumm4n1/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm4n1/scalar/gauss/functions.h
  
  feonumm4n1_t feonumm4n1_atanh(    feonumm4n1_t* num);
  void     feonumm4n1_atanh_to( feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_asinh(    feonumm4n1_t* num);
  void     feonumm4n1_asinh_to( feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_acosh(    feonumm4n1_t* num);
  void     feonumm4n1_acosh_to( feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_tanh(     feonumm4n1_t* num);
  void     feonumm4n1_tanh_to(  feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_cosh(     feonumm4n1_t* num);
  void     feonumm4n1_cosh_to(  feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_sinh(     feonumm4n1_t* num);
  void     feonumm4n1_sinh_to(  feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_asin(     feonumm4n1_t* num);
  void     feonumm4n1_asin_to(  feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_acos(     feonumm4n1_t* num);
  void     feonumm4n1_acos_to(  feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_atan(     feonumm4n1_t* num);
  void     feonumm4n1_atan_to(  feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_tan(      feonumm4n1_t* num);
  void     feonumm4n1_tan_to(   feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_cos(      feonumm4n1_t* num);
  void     feonumm4n1_cos_to(   feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_sin(      feonumm4n1_t* num);
  void     feonumm4n1_sin_to(   feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_logb(     feonumm4n1_t* num, double base);
  void     feonumm4n1_logb_to(  feonumm4n1_t* num, double base, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_log10(    feonumm4n1_t* num);
  void     feonumm4n1_log10_to( feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_log(      feonumm4n1_t* num);
  void     feonumm4n1_log_to(   feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_exp(      feonumm4n1_t* num);
  void     feonumm4n1_exp_to(   feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_cbrt(     feonumm4n1_t* num);
  void     feonumm4n1_cbrt_to(  feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_sqrt(     feonumm4n1_t* num);
  void     feonumm4n1_sqrt_to(  feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_pow(      feonumm4n1_t* num, double e);
  void     feonumm4n1_pow_to(   feonumm4n1_t* num, double e, feonumm4n1_t* res);
  onumm4n1_t feonumm4n1_integrate(       feonumm4n1_t* num, feonumm4n1_t* w);
  void      feonumm4n1_integrate_to(    feonumm4n1_t* num, feonumm4n1_t* w, onumm4n1_t* res);
  onumm4n1_t feonumm4n1_integrate_f(     feonumm4n1_t* num, feonumm4n1_t* w);
  void      feonumm4n1_integrate_f_to(  feonumm4n1_t* num, feonumm4n1_t* w, onumm4n1_t* res);
  onumm4n1_t feonumm4n1_integrate_r(       coeff_t num, feonumm4n1_t* w);
  void      feonumm4n1_integrate_r_to(    coeff_t num, feonumm4n1_t* w, onumm4n1_t* res);
  onumm4n1_t feonumm4n1_integrate_o(    onumm4n1_t* num, feonumm4n1_t* w);
  void      feonumm4n1_integrate_o_to( onumm4n1_t* num, feonumm4n1_t* w, onumm4n1_t* res);
  
  
  # From ../../../include/oti/static/onumm4n1/scalar/gauss/base.h
  
  void     feonumm4n1_get_order_im_to( ord_t order, feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_get_order_im(    ord_t order, feonumm4n1_t* num);
  feonumm4n1_t feonumm4n1_get_im(    imdir_t idx, ord_t order, feonumm4n1_t* num);
  void     feonumm4n1_get_im_to( imdir_t idx, ord_t order, feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_get_deriv(    imdir_t idx, ord_t order, feonumm4n1_t* num);
  void     feonumm4n1_get_deriv_to( imdir_t idx, ord_t order, feonumm4n1_t* num, feonumm4n1_t* res);
  void feonumm4n1_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm4n1_t* num);
  void feonumm4n1_set_im_o( onumm4n1_t* val, imdir_t idx, ord_t order, feonumm4n1_t* num);
  void feonumm4n1_set_im_f(  feonumm4n1_t* val, imdir_t idx, ord_t order, feonumm4n1_t* num);
  void feonumm4n1_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm4n1_t* num);
  void feonumm4n1_set_deriv_o( onumm4n1_t* val, imdir_t idx, ord_t order, feonumm4n1_t* num);
  void feonumm4n1_set_deriv_f(  feonumm4n1_t* val, imdir_t idx, ord_t order, feonumm4n1_t* num);
  feonumm4n1_t feonumm4n1_extract_im(    imdir_t idx, ord_t order, feonumm4n1_t* num);
  void     feonumm4n1_extract_im_to( imdir_t idx, ord_t order, feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_extract_deriv(    imdir_t idx, ord_t order, feonumm4n1_t* num);
  void     feonumm4n1_extract_deriv_to( imdir_t idx, ord_t order, feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_truncate_im(    imdir_t idx, ord_t order, feonumm4n1_t* num);
  void     feonumm4n1_truncate_im_to( imdir_t idx, ord_t order, feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_copy(    feonumm4n1_t* src);
  void     feonumm4n1_copy_to( feonumm4n1_t* src, feonumm4n1_t* dst);
  void feonumm4n1_set_r(    coeff_t num, feonumm4n1_t* res);
  void feonumm4n1_set_o( onumm4n1_t* num, feonumm4n1_t* res);
  void feonumm4n1_set_f(  feonumm4n1_t* num, feonumm4n1_t* res);
  void feonumm4n1_set_item_k_r(   coeff_t  num, uint64_t k, feonumm4n1_t* res);
  void feonumm4n1_set_item_k_o( onumm4n1_t* num, uint64_t k, feonumm4n1_t* res);
  onumm4n1_t feonumm4n1_get_item_k(   feonumm4n1_t* num, uint64_t k);
  void      feonumm4n1_get_item_k_to(feonumm4n1_t* num, uint64_t k, onumm4n1_t* res);
  feonumm4n1_t feonumm4n1_zeros(uint64_t nIntPts);
  feonumm4n1_t feonumm4n1_createEmpty(uint64_t nIntPts);
  feonumm4n1_t feonumm4n1_empty_like(feonumm4n1_t* arr);
  void feonumm4n1_free(feonumm4n1_t* num);
  ord_t feonumm4n1_get_order( feonumm4n1_t* num );
  feonumm4n1_t feonumm4n1_init();
  
  
  # From ../../../include/oti/static/onumm4n1/scalar/gauss/utils.h
  
  void feonumm4n1_dimCheck(feonumm4n1_t* arr1,feonumm4n1_t* arr2);
  void feonumm4n1_get_active_bases(feonumm4n1_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n1/scalar/gauss/algebra.h
  
  feonumm4n1_t feonumm4n1_neg(   feonumm4n1_t* num);
  void     feonumm4n1_neg_to(feonumm4n1_t* num, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_sum_ff(   feonumm4n1_t* lhs, feonumm4n1_t* rhs);
  void     feonumm4n1_sum_ff_to(feonumm4n1_t* lhs, feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_sum_of(   onumm4n1_t* lhs, feonumm4n1_t* rhs);
  void     feonumm4n1_sum_of_to(onumm4n1_t* lhs, feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_sum_rf(   coeff_t lhs, feonumm4n1_t* rhs);
  void     feonumm4n1_sum_rf_to(coeff_t lhs, feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_sub_ff(     feonumm4n1_t* lhs,  feonumm4n1_t* rhs);
  void     feonumm4n1_sub_ff_to(  feonumm4n1_t* lhs,  feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_sub_of(    onumm4n1_t* lhs,  feonumm4n1_t* rhs);
  void     feonumm4n1_sub_of_to( onumm4n1_t* lhs,  feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_sub_fo(     feonumm4n1_t* lhs, onumm4n1_t* rhs);
  void     feonumm4n1_sub_fo_to(  feonumm4n1_t* lhs, onumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_sub_rf(       coeff_t lhs,  feonumm4n1_t* rhs);
  void     feonumm4n1_sub_rf_to(    coeff_t lhs,  feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_sub_fr(     feonumm4n1_t* lhs,    coeff_t rhs);
  void     feonumm4n1_sub_fr_to(  feonumm4n1_t* lhs,    coeff_t rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_mul_ff(   feonumm4n1_t* lhs, feonumm4n1_t* rhs);
  void     feonumm4n1_mul_ff_to(feonumm4n1_t* lhs, feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_mul_of(   onumm4n1_t* lhs, feonumm4n1_t* rhs);
  void     feonumm4n1_mul_of_to(onumm4n1_t* lhs, feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_mul_rf(   coeff_t lhs, feonumm4n1_t* rhs);
  void     feonumm4n1_mul_rf_to(coeff_t lhs, feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_div_ff(     feonumm4n1_t* lhs,  feonumm4n1_t* rhs);
  void     feonumm4n1_div_ff_to(  feonumm4n1_t* lhs,  feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_div_of(    onumm4n1_t* lhs,  feonumm4n1_t* rhs);
  void     feonumm4n1_div_of_to( onumm4n1_t* lhs,  feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_div_fo(     feonumm4n1_t* lhs, onumm4n1_t* rhs);
  void     feonumm4n1_div_fo_to(  feonumm4n1_t* lhs, onumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_div_rf(       coeff_t lhs,  feonumm4n1_t* rhs);
  void     feonumm4n1_div_rf_to(    coeff_t lhs,  feonumm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feonumm4n1_div_fr(     feonumm4n1_t* lhs,    coeff_t rhs);
  void     feonumm4n1_div_fr_to(  feonumm4n1_t* lhs,    coeff_t rhs, feonumm4n1_t* res);
  
  
  # From ../../../include/oti/static/onumm4n1/array/functions.h
  
  oarrm4n1_t oarrm4n1_atanh(   oarrm4n1_t* arr);
  void    oarrm4n1_atanh_to(oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_asinh(   oarrm4n1_t* arr);
  void    oarrm4n1_asinh_to(oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_acosh(   oarrm4n1_t* arr);
  void    oarrm4n1_acosh_to(oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_tanh(    oarrm4n1_t* arr);
  void    oarrm4n1_tanh_to( oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_cbrt(    oarrm4n1_t* arr);
  void    oarrm4n1_cbrt_to( oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_sqrt(    oarrm4n1_t* arr);
  void    oarrm4n1_sqrt_to( oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_cosh(    oarrm4n1_t* arr);
  void    oarrm4n1_cosh_to( oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_sinh(    oarrm4n1_t* arr);
  void    oarrm4n1_sinh_to( oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_asin(    oarrm4n1_t* arr);
  void    oarrm4n1_asin_to( oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_acos(    oarrm4n1_t* arr);
  void    oarrm4n1_acos_to( oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_atan(    oarrm4n1_t* arr);
  void    oarrm4n1_atan_to( oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_tan(     oarrm4n1_t* arr);
  void    oarrm4n1_tan_to(  oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_cos(     oarrm4n1_t* arr);
  void    oarrm4n1_cos_to(  oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_sin(     oarrm4n1_t* arr);
  void    oarrm4n1_sin_to(  oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_logb(    oarrm4n1_t* arr, double base);
  void    oarrm4n1_logb_to( oarrm4n1_t* arr, double base, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_log10(   oarrm4n1_t* arr);
  void    oarrm4n1_log10_to(oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_log(     oarrm4n1_t* arr);
  void    oarrm4n1_log_to(  oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_exp(     oarrm4n1_t* arr);
  void    oarrm4n1_exp_to(  oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_pow(     oarrm4n1_t* arr, double e);
  void    oarrm4n1_pow_to(  oarrm4n1_t* arr, double e, oarrm4n1_t* res);
  
  
  # From ../../../include/oti/static/onumm4n1/array/algebra_elementwise.h
  
  oarrm4n1_t oarrm4n1_neg(oarrm4n1_t* arr);
  void oarrm4n1_neg_to(oarrm4n1_t* rhs, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_sum_OO(oarrm4n1_t*   lhs, oarrm4n1_t* rhs);
  oarrm4n1_t oarrm4n1_sum_RO(darr_t*    lhs, oarrm4n1_t* rhs);
  oarrm4n1_t oarrm4n1_sum_oO(onumm4n1_t* lhs, oarrm4n1_t* rhs);
  oarrm4n1_t oarrm4n1_sum_rO(coeff_t    lhs, oarrm4n1_t* rhs);
  void oarrm4n1_sum_OO_to(oarrm4n1_t*   lhs, oarrm4n1_t* rhs, oarrm4n1_t* res);
  void oarrm4n1_sum_RO_to(darr_t*    lhs, oarrm4n1_t* rhs, oarrm4n1_t* res);
  void oarrm4n1_sum_oO_to(onumm4n1_t* lhs, oarrm4n1_t* rhs, oarrm4n1_t* res);
  void oarrm4n1_sum_rO_to(coeff_t    lhs, oarrm4n1_t* rhs, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_sub_OO(oarrm4n1_t*   lhs, oarrm4n1_t*   rhs);
  oarrm4n1_t oarrm4n1_sub_RO(darr_t*    lhs, oarrm4n1_t*   rhs);
  oarrm4n1_t oarrm4n1_sub_OR(oarrm4n1_t*   lhs, darr_t*    rhs);
  oarrm4n1_t oarrm4n1_sub_oO(onumm4n1_t* lhs, oarrm4n1_t*   rhs);
  oarrm4n1_t oarrm4n1_sub_Oo(oarrm4n1_t*   lhs, onumm4n1_t* rhs);
  oarrm4n1_t oarrm4n1_sub_rO(coeff_t    lhs, oarrm4n1_t*   rhs);
  oarrm4n1_t oarrm4n1_sub_Or(oarrm4n1_t*   lhs, coeff_t    rhs);
  void oarrm4n1_sub_OO_to( oarrm4n1_t*   lhs, oarrm4n1_t*   rhs, oarrm4n1_t* res);
  void oarrm4n1_sub_RO_to( darr_t*    lhs, oarrm4n1_t*   rhs, oarrm4n1_t* res);
  void oarrm4n1_sub_OR_to( oarrm4n1_t*   lhs, darr_t*    rhs, oarrm4n1_t* res);
  void oarrm4n1_sub_oO_to( onumm4n1_t* lhs, oarrm4n1_t*   rhs, oarrm4n1_t* res);
  void oarrm4n1_sub_Oo_to( oarrm4n1_t*   lhs, onumm4n1_t* rhs, oarrm4n1_t* res);
  void oarrm4n1_sub_rO_to( coeff_t    lhs, oarrm4n1_t*   rhs, oarrm4n1_t* res);
  void oarrm4n1_sub_Or_to( oarrm4n1_t*   lhs, coeff_t    rhs, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_mul_OO(oarrm4n1_t*   lhs, oarrm4n1_t* rhs);
  oarrm4n1_t oarrm4n1_mul_RO(darr_t*    lhs, oarrm4n1_t* rhs);
  oarrm4n1_t oarrm4n1_mul_oO(onumm4n1_t* lhs, oarrm4n1_t* rhs);
  oarrm4n1_t oarrm4n1_mul_rO(coeff_t    lhs, oarrm4n1_t* rhs);
  void oarrm4n1_mul_OO_to(oarrm4n1_t*   lhs, oarrm4n1_t* rhs, oarrm4n1_t* res);
  void oarrm4n1_mul_RO_to(darr_t*    lhs, oarrm4n1_t* rhs, oarrm4n1_t* res);
  void oarrm4n1_mul_oO_to(onumm4n1_t* lhs, oarrm4n1_t* rhs, oarrm4n1_t* res);
  void oarrm4n1_mul_rO_to(coeff_t    lhs, oarrm4n1_t* rhs, oarrm4n1_t* res);
  void oarrm4n1_gem_OO_to(  oarrm4n1_t* arr1, oarrm4n1_t* arr2, oarrm4n1_t* arr3, oarrm4n1_t* res);
  void oarrm4n1_gem_oO_to(onumm4n1_t* arr1, oarrm4n1_t* arr2, oarrm4n1_t* arr3, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_div_OO(oarrm4n1_t*   lhs, oarrm4n1_t*   rhs);
  oarrm4n1_t oarrm4n1_div_OR(oarrm4n1_t*   lhs, darr_t*    rhs);
  oarrm4n1_t oarrm4n1_div_RO(darr_t*    lhs, oarrm4n1_t*   rhs);
  oarrm4n1_t oarrm4n1_div_oO(onumm4n1_t* lhs, oarrm4n1_t*   rhs);
  oarrm4n1_t oarrm4n1_div_Oo(oarrm4n1_t*   lhs, onumm4n1_t* rhs);
  oarrm4n1_t oarrm4n1_div_rO(coeff_t    lhs, oarrm4n1_t*   rhs);
  oarrm4n1_t oarrm4n1_div_Or(oarrm4n1_t*   lhs, coeff_t    rhs);
  void oarrm4n1_div_OO_to(oarrm4n1_t*   lhs, oarrm4n1_t*   rhs, oarrm4n1_t* res);
  void oarrm4n1_div_RO_to(darr_t*    lhs, oarrm4n1_t*   rhs, oarrm4n1_t* res);
  void oarrm4n1_div_OR_to(oarrm4n1_t*   lhs, darr_t*    rhs, oarrm4n1_t* res);
  void oarrm4n1_div_oO_to(onumm4n1_t* lhs, oarrm4n1_t*   rhs, oarrm4n1_t* res);
  void oarrm4n1_div_Oo_to(oarrm4n1_t*   lhs, onumm4n1_t* rhs, oarrm4n1_t* res);
  void oarrm4n1_div_rO_to(coeff_t    lhs, oarrm4n1_t*   rhs, oarrm4n1_t* res);
  void oarrm4n1_div_Or_to(oarrm4n1_t*   lhs, coeff_t    rhs, oarrm4n1_t* res);
  
  
  # From ../../../include/oti/static/onumm4n1/array/base.h
  
  void    oarrm4n1_taylor_integrate_to( coeff_t* deltas, oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_taylor_integrate(    coeff_t* deltas, oarrm4n1_t* arr);
  void    oarrm4n1_get_order_im_to( ord_t order, oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_get_order_im(    ord_t order, oarrm4n1_t* arr);
  void oarrm4n1_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n1_t* res);
  void oarrm4n1_set_slice_O( oarrm4n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n1_t* res);
  void oarrm4n1_set_slice_o( onumm4n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_get_slice( oarrm4n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm4n1_get_slice_to( oarrm4n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_truncate_im(    imdir_t idx, ord_t order, oarrm4n1_t* arr);
  void    oarrm4n1_truncate_im_to( imdir_t idx, ord_t order, oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_extract_im(   imdir_t idx, ord_t order, oarrm4n1_t* arr);
  void    oarrm4n1_extract_im_to(imdir_t idx, ord_t order, oarrm4n1_t* arr, oarrm4n1_t* res);
  darr_t  oarrm4n1_get_deriv(    imdir_t idx, ord_t order, oarrm4n1_t* arr);
  void    oarrm4n1_get_deriv_to( imdir_t idx, ord_t order, oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_get_deriv_o(  imdir_t idx, ord_t order, oarrm4n1_t* arr);
  oarrm4n1_t oarrm4n1_extract_deriv(    imdir_t idx, ord_t order, oarrm4n1_t* arr);
  void    oarrm4n1_extract_deriv_to( imdir_t idx, ord_t order, oarrm4n1_t* arr, oarrm4n1_t* res);
  darr_t  oarrm4n1_get_im(   imdir_t idx, ord_t order, oarrm4n1_t* arr);
  oarrm4n1_t oarrm4n1_get_im_o( imdir_t idx, ord_t order, oarrm4n1_t* arr);
  void    oarrm4n1_get_im_to(imdir_t idx, ord_t order, oarrm4n1_t* arr, oarrm4n1_t* res);
  void    oarrm4n1_copy_to(oarrm4n1_t* arr, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_copy(oarrm4n1_t* arr);
  void oarrm4n1_set_all_r( coeff_t num, oarrm4n1_t* arr);
  void oarrm4n1_set_item_i_r( coeff_t num, uint64_t i, oarrm4n1_t* arr);
  void oarrm4n1_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm4n1_t* arr);
  void oarrm4n1_set_r(   coeff_t  num,   oarrm4n1_t* arr);
  void oarrm4n1_set_o( onumm4n1_t* num,   oarrm4n1_t* arr);
  void oarrm4n1_set_O(   oarrm4n1_t* arrin, oarrm4n1_t* arr);
  void oarrm4n1_set_all_o( onumm4n1_t* src, oarrm4n1_t* arr);
  void oarrm4n1_set_item_i_o( onumm4n1_t* num, uint64_t i, oarrm4n1_t* arr);
  void oarrm4n1_set_item_ij_o( onumm4n1_t* num, uint64_t i, uint64_t j, oarrm4n1_t* arr);
  onumm4n1_t oarrm4n1_get_item_i(    oarrm4n1_t* arr, uint64_t i);
  void      oarrm4n1_get_item_i_to( oarrm4n1_t* arr, uint64_t i,             onumm4n1_t* res);
  onumm4n1_t oarrm4n1_get_item_ij(   oarrm4n1_t* arr, uint64_t i, uint64_t j);
  void      oarrm4n1_get_item_ij_to(oarrm4n1_t* arr, uint64_t i, uint64_t j, onumm4n1_t* res);
  oarrm4n1_t oarrm4n1_init();
  void oarrm4n1_free(oarrm4n1_t* arr);
  oarrm4n1_t oarrm4n1_empty_like(oarrm4n1_t* arr);
  oarrm4n1_t oarrm4n1_eye(uint64_t nrows);
  oarrm4n1_t oarrm4n1_ones(uint64_t nrows, uint64_t ncols);
  oarrm4n1_t oarrm4n1_zeros(uint64_t nrows, uint64_t ncols);
  oarrm4n1_t oarrm4n1_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm4n1/array/utils.h
  
  void oarrm4n1_dimCheck_OO_elementwise(oarrm4n1_t* arr1, oarrm4n1_t* arr2, oarrm4n1_t* res);
  void oarrm4n1_dimCheck_RO_elementwise(darr_t*  arr1, oarrm4n1_t* arr2, oarrm4n1_t* res);
  void oarrm4n1_dimCheck_OO_matmul(oarrm4n1_t* arr1, oarrm4n1_t* arr2, oarrm4n1_t* res);
  void oarrm4n1_dimCheck_RO_matmul(darr_t*  arr1, oarrm4n1_t* arr2, oarrm4n1_t* res);
  void oarrm4n1_dimCheck_OR_matmul(oarrm4n1_t* arr1, darr_t*  arr2, oarrm4n1_t* res);
  void oarrm4n1_dimCheck_O_squareness(oarrm4n1_t* arr1, oarrm4n1_t* res);
  void oarrm4n1_dimCheck_OO_samesize(oarrm4n1_t* arr1, oarrm4n1_t* res);
  void oarrm4n1_dimCheck_RO_samesize(darr_t* arr1, oarrm4n1_t* res);
  ord_t oarrm4n1_get_order(oarrm4n1_t* arr);
  void oarrm4n1_get_active_bases(oarrm4n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n1/array/algebra_matops.h
  
  onumm4n1_t oarrm4n1_dotproduct_OO(    oarrm4n1_t* lhs, oarrm4n1_t* rhs);
  void      oarrm4n1_dotproduct_OO_to( oarrm4n1_t* lhs, oarrm4n1_t* rhs, onumm4n1_t* res);
  onumm4n1_t oarrm4n1_dotproduct_RO(     darr_t* lhs, oarrm4n1_t* rhs);
  void      oarrm4n1_dotproduct_RO_to(  darr_t* lhs, oarrm4n1_t* rhs, onumm4n1_t* res);
  oarrm4n1_t oarrm4n1_matmul_OO(    oarrm4n1_t* lhs, oarrm4n1_t* rhs);
  oarrm4n1_t oarrm4n1_matmul_OR(    oarrm4n1_t* lhs,  darr_t* rhs);
  oarrm4n1_t oarrm4n1_matmul_RO(     darr_t* lhs, oarrm4n1_t* rhs);
  void    oarrm4n1_matmul_OO_to( oarrm4n1_t* lhs, oarrm4n1_t* rhs, oarrm4n1_t* res);
  void    oarrm4n1_matmul_OR_to( oarrm4n1_t* lhs,  darr_t* rhs, oarrm4n1_t* res);
  void    oarrm4n1_matmul_RO_to(  darr_t* lhs, oarrm4n1_t* rhs, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_transpose(    oarrm4n1_t* arr1);
  void    oarrm4n1_transpose_to( oarrm4n1_t* arr1, oarrm4n1_t* res);
  oarrm4n1_t oarrm4n1_invert(    oarrm4n1_t* arr1);
  void    oarrm4n1_invert_to( oarrm4n1_t* arr1, oarrm4n1_t* res);
  onumm4n1_t oarrm4n1_det(    oarrm4n1_t* arr1);
  void      oarrm4n1_det_to( oarrm4n1_t* arr1, onumm4n1_t* res);
  onumm4n1_t oarrm4n1_norm(    oarrm4n1_t* arr1);
  void      oarrm4n1_norm_to( oarrm4n1_t* arr1,  onumm4n1_t* res);
  onumm4n1_t oarrm4n1_pnorm(    oarrm4n1_t* arr1, coeff_t p);
  void      oarrm4n1_pnorm_to( oarrm4n1_t* arr1, coeff_t p, onumm4n1_t* res);
  
  
  # From ../../../include/oti/static/onumm4n1/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm4n1/array/gauss/functions.h
  
  feoarrm4n1_t feoarrm4n1_atanh(    feoarrm4n1_t* arr);
  void      feoarrm4n1_atanh_to( feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_asinh(    feoarrm4n1_t* arr);
  void      feoarrm4n1_asinh_to( feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_acosh(    feoarrm4n1_t* arr);
  void      feoarrm4n1_acosh_to( feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_tanh(     feoarrm4n1_t* arr);
  void      feoarrm4n1_tanh_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sinh(     feoarrm4n1_t* arr);
  void      feoarrm4n1_sinh_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_cosh(     feoarrm4n1_t* arr);
  void      feoarrm4n1_cosh_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_atan(     feoarrm4n1_t* arr);
  void      feoarrm4n1_atan_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_asin(     feoarrm4n1_t* arr);
  void      feoarrm4n1_asin_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_acos(     feoarrm4n1_t* arr);
  void      feoarrm4n1_acos_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_tan(      feoarrm4n1_t* arr);
  void      feoarrm4n1_tan_to(   feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sin(      feoarrm4n1_t* arr);
  void      feoarrm4n1_sin_to(   feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_cos(      feoarrm4n1_t* arr);
  void      feoarrm4n1_cos_to(   feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_logb(     feoarrm4n1_t* arr, double base);
  void      feoarrm4n1_logb_to(  feoarrm4n1_t* arr, double base, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_log10(    feoarrm4n1_t* arr);
  void      feoarrm4n1_log10_to( feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_log(      feoarrm4n1_t* arr);
  void      feoarrm4n1_log_to(   feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_exp(      feoarrm4n1_t* arr);
  void      feoarrm4n1_exp_to(   feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_cbrt(     feoarrm4n1_t* arr);
  void      feoarrm4n1_cbrt_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sqrt(     feoarrm4n1_t* arr);
  void      feoarrm4n1_sqrt_to(  feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_pow(      feoarrm4n1_t* arr, double e);
  void      feoarrm4n1_pow_to(   feoarrm4n1_t* arr, double e, feoarrm4n1_t* res);
  
  
  # From ../../../include/oti/static/onumm4n1/array/gauss/base.h
  
  void      feoarrm4n1_get_order_im_to( ord_t order, feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_get_order_im(    ord_t order, feoarrm4n1_t* arr);
  feoarrm4n1_t feoarrm4n1_get_deriv(   imdir_t idx, ord_t order, feoarrm4n1_t* arr);
  void      feoarrm4n1_get_deriv_to(imdir_t idx, ord_t order, feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_get_im(      imdir_t idx, ord_t order, feoarrm4n1_t* arr);
  void      feoarrm4n1_get_im_to(   imdir_t idx, ord_t order, feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_truncate_im(   imdir_t idx, ord_t order, feoarrm4n1_t* arr);
  void      feoarrm4n1_truncate_im_to(imdir_t idx, ord_t order, feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_copy(   feoarrm4n1_t* src);
  void      feoarrm4n1_copy_to(feoarrm4n1_t* src, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_get_im(    imdir_t idx, ord_t order, feoarrm4n1_t* arr);
  void      feoarrm4n1_get_im_to( imdir_t idx, ord_t order, feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_get_deriv(    imdir_t idx, ord_t order, feoarrm4n1_t* arr);
  void      feoarrm4n1_get_deriv_to( imdir_t idx, ord_t order, feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_extract_im(    imdir_t idx, ord_t order, feoarrm4n1_t* arr);
  void      feoarrm4n1_extract_im_to( imdir_t idx, ord_t order, feoarrm4n1_t* arr,  feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_extract_deriv(    imdir_t idx, ord_t order, feoarrm4n1_t* arr);
  void      feoarrm4n1_extract_deriv_to( imdir_t idx, ord_t order, feoarrm4n1_t* arr, feoarrm4n1_t* res);
  oarrm4n1_t   feoarrm4n1_get_item_k(  feoarrm4n1_t* arr, uint64_t k);
  feonumm4n1_t  feoarrm4n1_get_item_ij( feoarrm4n1_t* arr, uint64_t i, uint64_t j);
  onumm4n1_t feoarrm4n1_get_item_ijk(feoarrm4n1_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm4n1_get_item_ij_to(  feoarrm4n1_t* arr, uint64_t i, uint64_t j,
                                 feonumm4n1_t* res);
  void feoarrm4n1_get_item_k_to(   feoarrm4n1_t* arr, uint64_t k,
                                  oarrm4n1_t* res);
  void feoarrm4n1_get_item_ijk_to( feoarrm4n1_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_get_slice(feoarrm4n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm4n1_get_slice_to(feoarrm4n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n1_t* res);
  void feoarrm4n1_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm4n1_t* res);
  void feoarrm4n1_set_item_ij_o(  onumm4n1_t* elm, uint64_t i, uint64_t j,
                               feoarrm4n1_t* res);
  void feoarrm4n1_set_item_ij_f(  feonumm4n1_t* elm, uint64_t i, uint64_t j,
                              feoarrm4n1_t* res);
  void feoarrm4n1_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm4n1_t* res);
  void feoarrm4n1_set_item_k_o(  onumm4n1_t* elm, uint64_t k,
                              feoarrm4n1_t* res);
  void feoarrm4n1_set_item_k_R(    oarrm4n1_t* elm, uint64_t k,
                            feoarrm4n1_t* res);
  void feoarrm4n1_set_item_k_O(    oarrm4n1_t* elm, uint64_t k,
                            feoarrm4n1_t* res);
  void feoarrm4n1_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm4n1_t* res);
  void feoarrm4n1_set_item_ijk_o( onumm4n1_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm4n1_t* res);
  void feoarrm4n1_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n1_t* res);
  void feoarrm4n1_set_slice_o( onumm4n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n1_t* res);
  void feoarrm4n1_set_slice_f( feonumm4n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n1_t* res);
  void feoarrm4n1_set_slice_O( oarrm4n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n1_t* res);
  void feoarrm4n1_set_slice_F( feoarrm4n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n1_t* res);
  void feoarrm4n1_set_all_o( onumm4n1_t* num, feoarrm4n1_t* arr );
  void feoarrm4n1_set_all_r(   coeff_t  num, feoarrm4n1_t* arr );
  void feoarrm4n1_set_all_f(  feonumm4n1_t* num, feoarrm4n1_t* arr );
  void feoarrm4n1_set_r(    coeff_t src, feoarrm4n1_t* res );
  void feoarrm4n1_set_o( onumm4n1_t* src, feoarrm4n1_t* res );
  void feoarrm4n1_set_f(  feonumm4n1_t* src, feoarrm4n1_t* res );
  void feoarrm4n1_set_R(    darr_t* src, feoarrm4n1_t* res );
  void feoarrm4n1_set_O(   oarrm4n1_t* src, feoarrm4n1_t* res );
  void feoarrm4n1_set_F( feoarrm4n1_t* src, feoarrm4n1_t* res );
  feoarrm4n1_t feoarrm4n1_eye( uint64_t size,  uint64_t nip);
  feoarrm4n1_t feoarrm4n1_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm4n1_t feoarrm4n1_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm4n1_t feoarrm4n1_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm4n1_free(feoarrm4n1_t* arr);
  feoarrm4n1_t feoarrm4n1_init();
  ord_t feoarrm4n1_get_order(feoarrm4n1_t* arr);
  
  
  # From ../../../include/oti/static/onumm4n1/array/gauss/utils.h
  
  void feoarrm4n1_dimCheck_FF_samesize(feoarrm4n1_t* arr1, feoarrm4n1_t* arr2, feonumm4n1_t* res);
  void feoarrm4n1_dimCheck_OF_samesize(  oarrm4n1_t* arr1, feoarrm4n1_t* arr2, feonumm4n1_t* res);
  void feoarrm4n1_dimCheck_RF_samesize(   darr_t* arr1, feoarrm4n1_t* arr2, feonumm4n1_t* res);
  void feoarrm4n1_dimCheck_FF_elementwise(feoarrm4n1_t* arr1, feoarrm4n1_t* arr2, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_OF_elementwise(  oarrm4n1_t* arr1, feoarrm4n1_t* arr2, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm4n1_t* arr2, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_fF_elementwise( feonumm4n1_t* num1, feoarrm4n1_t* arr2, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_Ff_elementwise(feoarrm4n1_t* arr1,  feonumm4n1_t* num2, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_FF_matmul( feoarrm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_OF_matmul(   oarrm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_FO_matmul( feoarrm4n1_t* lhs,   oarrm4n1_t* rhs, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_FR_matmul( feoarrm4n1_t* lhs,    darr_t* rhs, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_F_squareness( feoarrm4n1_t* arr1, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_F_transpose( feoarrm4n1_t* arr1, feoarrm4n1_t* res);
  void feoarrm4n1_dimCheck_FfO_integrate(feoarrm4n1_t* arr, feonumm4n1_t* num,oarrm4n1_t* res);
  void feoarrm4n1_get_active_bases(feoarrm4n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n1/array/gauss/algebra.h
  
  feoarrm4n1_t feoarrm4n1_neg(    feoarrm4n1_t* arr);
  void      feoarrm4n1_neg_to( feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sum_FF(   feoarrm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sum_FF_to(feoarrm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sum_fF(    feonumm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sum_fF_to( feonumm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sum_OF(     oarrm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sum_OF_to(  oarrm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sum_RF(      darr_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sum_RF_to(   darr_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sum_oF(   onumm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sum_oF_to(onumm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sum_rF(     coeff_t  lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sum_rF_to(  coeff_t  lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sub_FF(    feoarrm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sub_FF_to( feoarrm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sub_fF(    feonumm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sub_fF_to( feonumm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sub_Ff(    feoarrm4n1_t* lhs, feonumm4n1_t* rhs);
  void      feoarrm4n1_sub_Ff_to( feoarrm4n1_t* lhs, feonumm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sub_OF(      oarrm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sub_OF_to(   oarrm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sub_FO(    feoarrm4n1_t* lhs,   oarrm4n1_t* rhs);
  void      feoarrm4n1_sub_FO_to( feoarrm4n1_t* lhs,   oarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sub_RF(       darr_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sub_RF_to(    darr_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sub_FR(    feoarrm4n1_t* lhs,    darr_t* rhs);
  void      feoarrm4n1_sub_FR_to( feoarrm4n1_t* lhs,    darr_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sub_oF(    onumm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sub_oF_to( onumm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sub_Fo(    feoarrm4n1_t* lhs, onumm4n1_t* rhs);
  void      feoarrm4n1_sub_Fo_to( feoarrm4n1_t* lhs, onumm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sub_rF(      coeff_t  lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_sub_rF_to(    coeff_t lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_sub_Fr(    feoarrm4n1_t* lhs,   coeff_t  rhs);
  void      feoarrm4n1_sub_Fr_to( feoarrm4n1_t* lhs,   coeff_t  rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_mul_FF(   feoarrm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_mul_FF_to(feoarrm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_mul_fF(    feonumm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_mul_fF_to( feonumm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_mul_OF(     oarrm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_mul_OF_to(  oarrm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_mul_RF(      darr_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_mul_RF_to(   darr_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_mul_oF(   onumm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_mul_oF_to(onumm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_mul_rF(     coeff_t  lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_mul_rF_to(  coeff_t  lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_div_FF(    feoarrm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_div_FF_to( feoarrm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_div_fF(     feonumm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_div_fF_to(  feonumm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_div_Ff(    feoarrm4n1_t* lhs,  feonumm4n1_t* rhs);
  void      feoarrm4n1_div_Ff_to( feoarrm4n1_t* lhs,  feonumm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_div_OF(      oarrm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_div_OF_to(   oarrm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_div_FO(    feoarrm4n1_t* lhs,   oarrm4n1_t* rhs);
  void      feoarrm4n1_div_FO_to( feoarrm4n1_t* lhs,   oarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_div_RF(       darr_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_div_RF_to(    darr_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_div_FR(    feoarrm4n1_t* lhs,    darr_t* rhs);
  void      feoarrm4n1_div_FR_to( feoarrm4n1_t* lhs,    darr_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_div_oF(    onumm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_div_oF_to( onumm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_div_Fo(    feoarrm4n1_t* lhs, onumm4n1_t* rhs);
  void      feoarrm4n1_div_Fo_to( feoarrm4n1_t* lhs, onumm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_div_rF(      coeff_t  lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_div_rF_to(    coeff_t lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_div_Fr(    feoarrm4n1_t* lhs,   coeff_t  rhs);
  void      feoarrm4n1_div_Fr_to( feoarrm4n1_t* lhs,   coeff_t  rhs, feoarrm4n1_t* res);
  oarrm4n1_t feoarrm4n1_integrate(    feoarrm4n1_t* arr, feonumm4n1_t* w);
  void    feoarrm4n1_integrate_to( feoarrm4n1_t* arr, feonumm4n1_t* w, oarrm4n1_t* res);
  feonumm4n1_t feoarrm4n1_dotproduct_FF(    feoarrm4n1_t* lhs, feoarrm4n1_t* rhs);
  void     feoarrm4n1_dotproduct_FF_to( feoarrm4n1_t* lhs, feoarrm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feoarrm4n1_dotproduct_OF(      oarrm4n1_t* lhs, feoarrm4n1_t* rhs);
  void     feoarrm4n1_dotproduct_OF_to(   oarrm4n1_t* lhs, feoarrm4n1_t* rhs, feonumm4n1_t* res);
  feonumm4n1_t feoarrm4n1_dotproduct_RF(       darr_t* lhs, feoarrm4n1_t* rhs);
  void     feoarrm4n1_dotproduct_RF_to(    darr_t* lhs, feoarrm4n1_t* rhs, feonumm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_matmul_FF(    feoarrm4n1_t* lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_matmul_FF_to( feoarrm4n1_t* lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_matmul_OF(    oarrm4n1_t*   lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_matmul_OF_to( oarrm4n1_t*   lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_matmul_FO(    feoarrm4n1_t* lhs, oarrm4n1_t*   rhs);
  void      feoarrm4n1_matmul_FO_to( feoarrm4n1_t* lhs, oarrm4n1_t*   rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_matmul_RF(    darr_t*    lhs, feoarrm4n1_t* rhs);
  void      feoarrm4n1_matmul_RF_to( darr_t*    lhs, feoarrm4n1_t* rhs, feoarrm4n1_t* res);
  feoarrm4n1_t feoarrm4n1_matmul_FR(    feoarrm4n1_t* lhs, darr_t*    rhs);
  void      feoarrm4n1_matmul_FR_to( feoarrm4n1_t* lhs, darr_t*    rhs, feoarrm4n1_t* res);
  feonumm4n1_t feoarrm4n1_det(   feoarrm4n1_t* arr);
  void     feoarrm4n1_det_to(feoarrm4n1_t* arr, feonumm4n1_t* res);
  feonumm4n1_t feoarrm4n1_norm(     feoarrm4n1_t* arr);
  void     feoarrm4n1_norm_to(  feoarrm4n1_t* arr, feonumm4n1_t* res);
  feonumm4n1_t feoarrm4n1_pnorm(    feoarrm4n1_t* arr, coeff_t p);
  void     feoarrm4n1_pnorm_to( feoarrm4n1_t* arr, coeff_t p, feonumm4n1_t* res);
  feoarrm4n1_t   feoarrm4n1_invert(    feoarrm4n1_t* arr);
  void        feoarrm4n1_invert_to( feoarrm4n1_t* arr, feoarrm4n1_t* res);
  feoarrm4n1_t   feoarrm4n1_transpose(   feoarrm4n1_t* arr);
  void        feoarrm4n1_transpose_to(feoarrm4n1_t* arr, feoarrm4n1_t* res);
  
  