cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm9n1/scalar/structures.h
  
  ctypedef struct  onumm9n1_t : # {
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
  # } onumm9n1_t;
  
  
  # From ../../../include/oti/static/onumm9n1/array/structures.h
  
  ctypedef struct  oarrm9n1_t : # {
      onumm9n1_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm9n1_t;
  
  
  # From ../../../include/oti/static/onumm9n1/scalar/gauss/structures.h
  
  ctypedef struct  feonumm9n1_t: # {
      onumm9n1_t*  p_data;
      uint64_t    nip;
  # } feonumm9n1_t;
  
  
  # From ../../../include/oti/static/onumm9n1/array/gauss/structures.h
  
  ctypedef struct  feoarrm9n1_t: # {
      oarrm9n1_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm9n1_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm9n1/scalar/functions.h
  
  onumm9n1_t onumm9n1_atanh(onumm9n1_t* num);
  void onumm9n1_atanh_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_asinh(onumm9n1_t* num);
  void onumm9n1_asinh_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_acosh(onumm9n1_t* num);
  void onumm9n1_acosh_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_tanh(onumm9n1_t* num);
  void onumm9n1_tanh_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_sqrt(onumm9n1_t* num);
  void onumm9n1_sqrt_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_cbrt(onumm9n1_t* num);
  void onumm9n1_cbrt_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_cosh(onumm9n1_t* num);
  void onumm9n1_cosh_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_sinh(onumm9n1_t* num);
  void onumm9n1_sinh_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_asin(onumm9n1_t* num);
  void onumm9n1_asin_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_acos(onumm9n1_t* num);
  void onumm9n1_acos_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_atan(onumm9n1_t* num);
  void onumm9n1_atan_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_tan(onumm9n1_t* num);
  void onumm9n1_tan_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_cos(onumm9n1_t* num);
  void onumm9n1_cos_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_sin(onumm9n1_t* num );
  void onumm9n1_sin_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_logb(onumm9n1_t* num, double base);
  void onumm9n1_logb_to(onumm9n1_t* num, double base, onumm9n1_t* res);
  onumm9n1_t onumm9n1_log10(onumm9n1_t* num);
  void onumm9n1_log10_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_log(onumm9n1_t* num);
  void onumm9n1_log_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_exp(onumm9n1_t* num);
  void onumm9n1_exp_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_pow(onumm9n1_t* num, double e);
  void onumm9n1_pow_to(onumm9n1_t* num, coeff_t e, onumm9n1_t* res);
  
  
  # From ../../../include/oti/static/onumm9n1/scalar/base.h
  
  void onumm9n1_set_im_o(onumm9n1_t* num, imdir_t idx, ord_t order, onumm9n1_t* res);
  void onumm9n1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm9n1_t* res);
  void onumm9n1_set_deriv_o(onumm9n1_t* num, imdir_t idx, ord_t order, onumm9n1_t* res);
  void onumm9n1_extract_im_to( imdir_t idx, ord_t order, onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_extract_im(imdir_t idx, ord_t order, onumm9n1_t* num);
  onumm9n1_t onumm9n1_extract_deriv(imdir_t idx, ord_t order, onumm9n1_t* num);
  void onumm9n1_extract_deriv_to(imdir_t idx, ord_t order, onumm9n1_t* num, onumm9n1_t* res);
  void onumm9n1_get_im_to_o(imdir_t idx, ord_t order, onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_get_im_o(imdir_t idx, ord_t order, onumm9n1_t* num);
  void onumm9n1_get_im_to_r(imdir_t idx, ord_t order, onumm9n1_t* num, coeff_t* res);
  ord_t onumm9n1_get_order(onumm9n1_t* lhs);
  onumm9n1_t onumm9n1_get_deriv_o( imdir_t idx, ord_t order, onumm9n1_t* num);
  void onumm9n1_get_deriv_to( imdir_t idx, ord_t order, onumm9n1_t* num, onumm9n1_t* res);
  void onumm9n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm9n1_t* res);
  onumm9n1_t onumm9n1_init();
  ndir_t onumm9n1_get_ndir_order(ord_t order, onumm9n1_t* num);
  ndir_t onumm9n1_get_ndir_total(onumm9n1_t* num);
  coeff_t* onumm9n1_get_order_address(ord_t order, onumm9n1_t* num);
  onumm9n1_t onumm9n1_create_r(  coeff_t lhs);
  void onumm9n1_set_r(  coeff_t lhs, onumm9n1_t* res);
  void onumm9n1_set_o(  onumm9n1_t* lhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_get_order_im(ord_t order, onumm9n1_t* lhs);
  void onumm9n1_get_order_im_to(ord_t order, onumm9n1_t* lhs, onumm9n1_t* res);
  coeff_t onumm9n1_get_item(imdir_t idx, ord_t order, onumm9n1_t* lhs);
  coeff_t onumm9n1_get_deriv(imdir_t idx, ord_t order, onumm9n1_t* lhs);
  void onumm9n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm9n1_t* x);
  onumm9n1_t onumm9n1_copy(  onumm9n1_t* lhs);
  void onumm9n1_copy_to(  onumm9n1_t* lhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_taylor_integrate(coeff_t* deltas,onumm9n1_t* lhs);
  void onumm9n1_taylor_integrate_to(coeff_t* deltas,onumm9n1_t* lhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_truncate_im(imdir_t idx, ord_t order, onumm9n1_t* lhs);
  void onumm9n1_truncate_im_to(imdir_t idx, ord_t order, onumm9n1_t* lhs, onumm9n1_t* res);
  void onumm9n1_print(  onumm9n1_t* lhs);
  imdir_t onumm9n1_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm9n1/scalar/utils.h
  
  void onumm9n1_get_active_bases(onumm9n1_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm9n1/scalar/algebra.h
  
  onumm9n1_t onumm9n1_abs(onumm9n1_t* num);
  onumm9n1_t onumm9n1_div_ro(coeff_t num, onumm9n1_t* den);
  onumm9n1_t onumm9n1_div_oo(onumm9n1_t* num, onumm9n1_t* den);
  onumm9n1_t onumm9n1_div_or(onumm9n1_t* num, coeff_t val);
  void onumm9n1_div_ro_to(coeff_t num, onumm9n1_t* den, onumm9n1_t* res);
  void onumm9n1_div_oo_to(onumm9n1_t* num, onumm9n1_t* den, onumm9n1_t* res);
  void onumm9n1_div_or_to(onumm9n1_t* num, coeff_t val, onumm9n1_t* res);
  void onumm9n1_abs_to(onumm9n1_t* num, onumm9n1_t* res);
  onumm9n1_t onumm9n1_neg(  onumm9n1_t* lhs);
  void onumm9n1_neg_to(  onumm9n1_t* lhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_sum_oo(  onumm9n1_t* lhs,  onumm9n1_t* rhs);
  void onumm9n1_sum_oo_to(  onumm9n1_t* lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_sum_ro(  coeff_t lhs,  onumm9n1_t* rhs);
  void onumm9n1_sum_ro_to(  coeff_t lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_sub_oo(  onumm9n1_t* lhs,  onumm9n1_t* rhs);
  void onumm9n1_sub_oo_to(  onumm9n1_t* lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_sub_ro(  coeff_t lhs,  onumm9n1_t* rhs);
  void onumm9n1_sub_ro_to(  coeff_t lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_sub_or(  onumm9n1_t* lhs,  coeff_t rhs);
  void onumm9n1_sub_or_to(  onumm9n1_t* lhs,  coeff_t rhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_mul_oo(  onumm9n1_t* lhs,  onumm9n1_t* rhs);
  void onumm9n1_mul_oo_to(  onumm9n1_t* lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_mul_ro(  coeff_t lhs,  onumm9n1_t* rhs);
  void onumm9n1_mul_ro_to(  coeff_t lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_trunc_mul_oo(  onumm9n1_t* lhs,  onumm9n1_t* rhs);
  void onumm9n1_trunc_mul_oo_to(  onumm9n1_t* lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
  onumm9n1_t onumm9n1_gem_oo(  onumm9n1_t* a,  onumm9n1_t* b,  onumm9n1_t* c);
  void onumm9n1_gem_oo_to(  onumm9n1_t* a,  onumm9n1_t* b,  onumm9n1_t* c, onumm9n1_t* res);
  onumm9n1_t onumm9n1_gem_ro(  coeff_t a,  onumm9n1_t* b,  onumm9n1_t* c);
  void onumm9n1_gem_ro_to(  coeff_t a,  onumm9n1_t* b,  onumm9n1_t* c, onumm9n1_t* res);
  void onumm9n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm9n1_t* a,  ord_t ord_rhs,  onumm9n1_t* b,  onumm9n1_t* c, onumm9n1_t* res);
  onumm9n1_t onumm9n1_feval(coeff_t* feval_re, onumm9n1_t* x);
  void onumm9n1_feval_to(coeff_t* feval_re, onumm9n1_t* x, onumm9n1_t* res);
  
  
  # From ../../../include/oti/static/onumm9n1/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm9n1/scalar/gauss/functions.h
  
  feonumm9n1_t feonumm9n1_atanh(    feonumm9n1_t* num);
  void     feonumm9n1_atanh_to( feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_asinh(    feonumm9n1_t* num);
  void     feonumm9n1_asinh_to( feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_acosh(    feonumm9n1_t* num);
  void     feonumm9n1_acosh_to( feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_tanh(     feonumm9n1_t* num);
  void     feonumm9n1_tanh_to(  feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_cosh(     feonumm9n1_t* num);
  void     feonumm9n1_cosh_to(  feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_sinh(     feonumm9n1_t* num);
  void     feonumm9n1_sinh_to(  feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_asin(     feonumm9n1_t* num);
  void     feonumm9n1_asin_to(  feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_acos(     feonumm9n1_t* num);
  void     feonumm9n1_acos_to(  feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_atan(     feonumm9n1_t* num);
  void     feonumm9n1_atan_to(  feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_tan(      feonumm9n1_t* num);
  void     feonumm9n1_tan_to(   feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_cos(      feonumm9n1_t* num);
  void     feonumm9n1_cos_to(   feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_sin(      feonumm9n1_t* num);
  void     feonumm9n1_sin_to(   feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_logb(     feonumm9n1_t* num, double base);
  void     feonumm9n1_logb_to(  feonumm9n1_t* num, double base, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_log10(    feonumm9n1_t* num);
  void     feonumm9n1_log10_to( feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_log(      feonumm9n1_t* num);
  void     feonumm9n1_log_to(   feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_exp(      feonumm9n1_t* num);
  void     feonumm9n1_exp_to(   feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_cbrt(     feonumm9n1_t* num);
  void     feonumm9n1_cbrt_to(  feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_sqrt(     feonumm9n1_t* num);
  void     feonumm9n1_sqrt_to(  feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_pow(      feonumm9n1_t* num, double e);
  void     feonumm9n1_pow_to(   feonumm9n1_t* num, double e, feonumm9n1_t* res);
  onumm9n1_t feonumm9n1_integrate(       feonumm9n1_t* num, feonumm9n1_t* w);
  void      feonumm9n1_integrate_to(    feonumm9n1_t* num, feonumm9n1_t* w, onumm9n1_t* res);
  onumm9n1_t feonumm9n1_integrate_f(     feonumm9n1_t* num, feonumm9n1_t* w);
  void      feonumm9n1_integrate_f_to(  feonumm9n1_t* num, feonumm9n1_t* w, onumm9n1_t* res);
  onumm9n1_t feonumm9n1_integrate_r(       coeff_t num, feonumm9n1_t* w);
  void      feonumm9n1_integrate_r_to(    coeff_t num, feonumm9n1_t* w, onumm9n1_t* res);
  onumm9n1_t feonumm9n1_integrate_o(    onumm9n1_t* num, feonumm9n1_t* w);
  void      feonumm9n1_integrate_o_to( onumm9n1_t* num, feonumm9n1_t* w, onumm9n1_t* res);
  
  
  # From ../../../include/oti/static/onumm9n1/scalar/gauss/base.h
  
  void     feonumm9n1_get_order_im_to( ord_t order, feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_get_order_im(    ord_t order, feonumm9n1_t* num);
  feonumm9n1_t feonumm9n1_get_im(    imdir_t idx, ord_t order, feonumm9n1_t* num);
  void     feonumm9n1_get_im_to( imdir_t idx, ord_t order, feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_get_deriv(    imdir_t idx, ord_t order, feonumm9n1_t* num);
  void     feonumm9n1_get_deriv_to( imdir_t idx, ord_t order, feonumm9n1_t* num, feonumm9n1_t* res);
  void feonumm9n1_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm9n1_t* num);
  void feonumm9n1_set_im_o( onumm9n1_t* val, imdir_t idx, ord_t order, feonumm9n1_t* num);
  void feonumm9n1_set_im_f(  feonumm9n1_t* val, imdir_t idx, ord_t order, feonumm9n1_t* num);
  void feonumm9n1_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm9n1_t* num);
  void feonumm9n1_set_deriv_o( onumm9n1_t* val, imdir_t idx, ord_t order, feonumm9n1_t* num);
  void feonumm9n1_set_deriv_f(  feonumm9n1_t* val, imdir_t idx, ord_t order, feonumm9n1_t* num);
  feonumm9n1_t feonumm9n1_extract_im(    imdir_t idx, ord_t order, feonumm9n1_t* num);
  void     feonumm9n1_extract_im_to( imdir_t idx, ord_t order, feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_extract_deriv(    imdir_t idx, ord_t order, feonumm9n1_t* num);
  void     feonumm9n1_extract_deriv_to( imdir_t idx, ord_t order, feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_truncate_im(    imdir_t idx, ord_t order, feonumm9n1_t* num);
  void     feonumm9n1_truncate_im_to( imdir_t idx, ord_t order, feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_copy(    feonumm9n1_t* src);
  void     feonumm9n1_copy_to( feonumm9n1_t* src, feonumm9n1_t* dst);
  void feonumm9n1_set_r(    coeff_t num, feonumm9n1_t* res);
  void feonumm9n1_set_o( onumm9n1_t* num, feonumm9n1_t* res);
  void feonumm9n1_set_f(  feonumm9n1_t* num, feonumm9n1_t* res);
  void feonumm9n1_set_item_k_r(   coeff_t  num, uint64_t k, feonumm9n1_t* res);
  void feonumm9n1_set_item_k_o( onumm9n1_t* num, uint64_t k, feonumm9n1_t* res);
  onumm9n1_t feonumm9n1_get_item_k(   feonumm9n1_t* num, uint64_t k);
  void      feonumm9n1_get_item_k_to(feonumm9n1_t* num, uint64_t k, onumm9n1_t* res);
  feonumm9n1_t feonumm9n1_zeros(uint64_t nIntPts);
  feonumm9n1_t feonumm9n1_createEmpty(uint64_t nIntPts);
  feonumm9n1_t feonumm9n1_empty_like(feonumm9n1_t* arr);
  void feonumm9n1_free(feonumm9n1_t* num);
  ord_t feonumm9n1_get_order( feonumm9n1_t* num );
  feonumm9n1_t feonumm9n1_init();
  
  
  # From ../../../include/oti/static/onumm9n1/scalar/gauss/utils.h
  
  void feonumm9n1_dimCheck(feonumm9n1_t* arr1,feonumm9n1_t* arr2);
  void feonumm9n1_get_active_bases(feonumm9n1_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm9n1/scalar/gauss/algebra.h
  
  feonumm9n1_t feonumm9n1_neg(   feonumm9n1_t* num);
  void     feonumm9n1_neg_to(feonumm9n1_t* num, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_sum_ff(   feonumm9n1_t* lhs, feonumm9n1_t* rhs);
  void     feonumm9n1_sum_ff_to(feonumm9n1_t* lhs, feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_sum_of(   onumm9n1_t* lhs, feonumm9n1_t* rhs);
  void     feonumm9n1_sum_of_to(onumm9n1_t* lhs, feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_sum_rf(   coeff_t lhs, feonumm9n1_t* rhs);
  void     feonumm9n1_sum_rf_to(coeff_t lhs, feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_sub_ff(     feonumm9n1_t* lhs,  feonumm9n1_t* rhs);
  void     feonumm9n1_sub_ff_to(  feonumm9n1_t* lhs,  feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_sub_of(    onumm9n1_t* lhs,  feonumm9n1_t* rhs);
  void     feonumm9n1_sub_of_to( onumm9n1_t* lhs,  feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_sub_fo(     feonumm9n1_t* lhs, onumm9n1_t* rhs);
  void     feonumm9n1_sub_fo_to(  feonumm9n1_t* lhs, onumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_sub_rf(       coeff_t lhs,  feonumm9n1_t* rhs);
  void     feonumm9n1_sub_rf_to(    coeff_t lhs,  feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_sub_fr(     feonumm9n1_t* lhs,    coeff_t rhs);
  void     feonumm9n1_sub_fr_to(  feonumm9n1_t* lhs,    coeff_t rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_mul_ff(   feonumm9n1_t* lhs, feonumm9n1_t* rhs);
  void     feonumm9n1_mul_ff_to(feonumm9n1_t* lhs, feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_mul_of(   onumm9n1_t* lhs, feonumm9n1_t* rhs);
  void     feonumm9n1_mul_of_to(onumm9n1_t* lhs, feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_mul_rf(   coeff_t lhs, feonumm9n1_t* rhs);
  void     feonumm9n1_mul_rf_to(coeff_t lhs, feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_div_ff(     feonumm9n1_t* lhs,  feonumm9n1_t* rhs);
  void     feonumm9n1_div_ff_to(  feonumm9n1_t* lhs,  feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_div_of(    onumm9n1_t* lhs,  feonumm9n1_t* rhs);
  void     feonumm9n1_div_of_to( onumm9n1_t* lhs,  feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_div_fo(     feonumm9n1_t* lhs, onumm9n1_t* rhs);
  void     feonumm9n1_div_fo_to(  feonumm9n1_t* lhs, onumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_div_rf(       coeff_t lhs,  feonumm9n1_t* rhs);
  void     feonumm9n1_div_rf_to(    coeff_t lhs,  feonumm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feonumm9n1_div_fr(     feonumm9n1_t* lhs,    coeff_t rhs);
  void     feonumm9n1_div_fr_to(  feonumm9n1_t* lhs,    coeff_t rhs, feonumm9n1_t* res);
  
  
  # From ../../../include/oti/static/onumm9n1/array/functions.h
  
  oarrm9n1_t oarrm9n1_atanh(   oarrm9n1_t* arr);
  void    oarrm9n1_atanh_to(oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_asinh(   oarrm9n1_t* arr);
  void    oarrm9n1_asinh_to(oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_acosh(   oarrm9n1_t* arr);
  void    oarrm9n1_acosh_to(oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_tanh(    oarrm9n1_t* arr);
  void    oarrm9n1_tanh_to( oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_cbrt(    oarrm9n1_t* arr);
  void    oarrm9n1_cbrt_to( oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_sqrt(    oarrm9n1_t* arr);
  void    oarrm9n1_sqrt_to( oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_cosh(    oarrm9n1_t* arr);
  void    oarrm9n1_cosh_to( oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_sinh(    oarrm9n1_t* arr);
  void    oarrm9n1_sinh_to( oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_asin(    oarrm9n1_t* arr);
  void    oarrm9n1_asin_to( oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_acos(    oarrm9n1_t* arr);
  void    oarrm9n1_acos_to( oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_atan(    oarrm9n1_t* arr);
  void    oarrm9n1_atan_to( oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_tan(     oarrm9n1_t* arr);
  void    oarrm9n1_tan_to(  oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_cos(     oarrm9n1_t* arr);
  void    oarrm9n1_cos_to(  oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_sin(     oarrm9n1_t* arr);
  void    oarrm9n1_sin_to(  oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_logb(    oarrm9n1_t* arr, double base);
  void    oarrm9n1_logb_to( oarrm9n1_t* arr, double base, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_log10(   oarrm9n1_t* arr);
  void    oarrm9n1_log10_to(oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_log(     oarrm9n1_t* arr);
  void    oarrm9n1_log_to(  oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_exp(     oarrm9n1_t* arr);
  void    oarrm9n1_exp_to(  oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_pow(     oarrm9n1_t* arr, double e);
  void    oarrm9n1_pow_to(  oarrm9n1_t* arr, double e, oarrm9n1_t* res);
  
  
  # From ../../../include/oti/static/onumm9n1/array/algebra_elementwise.h
  
  oarrm9n1_t oarrm9n1_neg(oarrm9n1_t* arr);
  void oarrm9n1_neg_to(oarrm9n1_t* rhs, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_sum_OO(oarrm9n1_t*   lhs, oarrm9n1_t* rhs);
  oarrm9n1_t oarrm9n1_sum_RO(darr_t*    lhs, oarrm9n1_t* rhs);
  oarrm9n1_t oarrm9n1_sum_oO(onumm9n1_t* lhs, oarrm9n1_t* rhs);
  oarrm9n1_t oarrm9n1_sum_rO(coeff_t    lhs, oarrm9n1_t* rhs);
  void oarrm9n1_sum_OO_to(oarrm9n1_t*   lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
  void oarrm9n1_sum_RO_to(darr_t*    lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
  void oarrm9n1_sum_oO_to(onumm9n1_t* lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
  void oarrm9n1_sum_rO_to(coeff_t    lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_sub_OO(oarrm9n1_t*   lhs, oarrm9n1_t*   rhs);
  oarrm9n1_t oarrm9n1_sub_RO(darr_t*    lhs, oarrm9n1_t*   rhs);
  oarrm9n1_t oarrm9n1_sub_OR(oarrm9n1_t*   lhs, darr_t*    rhs);
  oarrm9n1_t oarrm9n1_sub_oO(onumm9n1_t* lhs, oarrm9n1_t*   rhs);
  oarrm9n1_t oarrm9n1_sub_Oo(oarrm9n1_t*   lhs, onumm9n1_t* rhs);
  oarrm9n1_t oarrm9n1_sub_rO(coeff_t    lhs, oarrm9n1_t*   rhs);
  oarrm9n1_t oarrm9n1_sub_Or(oarrm9n1_t*   lhs, coeff_t    rhs);
  void oarrm9n1_sub_OO_to( oarrm9n1_t*   lhs, oarrm9n1_t*   rhs, oarrm9n1_t* res);
  void oarrm9n1_sub_RO_to( darr_t*    lhs, oarrm9n1_t*   rhs, oarrm9n1_t* res);
  void oarrm9n1_sub_OR_to( oarrm9n1_t*   lhs, darr_t*    rhs, oarrm9n1_t* res);
  void oarrm9n1_sub_oO_to( onumm9n1_t* lhs, oarrm9n1_t*   rhs, oarrm9n1_t* res);
  void oarrm9n1_sub_Oo_to( oarrm9n1_t*   lhs, onumm9n1_t* rhs, oarrm9n1_t* res);
  void oarrm9n1_sub_rO_to( coeff_t    lhs, oarrm9n1_t*   rhs, oarrm9n1_t* res);
  void oarrm9n1_sub_Or_to( oarrm9n1_t*   lhs, coeff_t    rhs, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_mul_OO(oarrm9n1_t*   lhs, oarrm9n1_t* rhs);
  oarrm9n1_t oarrm9n1_mul_RO(darr_t*    lhs, oarrm9n1_t* rhs);
  oarrm9n1_t oarrm9n1_mul_oO(onumm9n1_t* lhs, oarrm9n1_t* rhs);
  oarrm9n1_t oarrm9n1_mul_rO(coeff_t    lhs, oarrm9n1_t* rhs);
  void oarrm9n1_mul_OO_to(oarrm9n1_t*   lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
  void oarrm9n1_mul_RO_to(darr_t*    lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
  void oarrm9n1_mul_oO_to(onumm9n1_t* lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
  void oarrm9n1_mul_rO_to(coeff_t    lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
  void oarrm9n1_gem_OO_to(  oarrm9n1_t* arr1, oarrm9n1_t* arr2, oarrm9n1_t* arr3, oarrm9n1_t* res);
  void oarrm9n1_gem_oO_to(onumm9n1_t* arr1, oarrm9n1_t* arr2, oarrm9n1_t* arr3, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_div_OO(oarrm9n1_t*   lhs, oarrm9n1_t*   rhs);
  oarrm9n1_t oarrm9n1_div_OR(oarrm9n1_t*   lhs, darr_t*    rhs);
  oarrm9n1_t oarrm9n1_div_RO(darr_t*    lhs, oarrm9n1_t*   rhs);
  oarrm9n1_t oarrm9n1_div_oO(onumm9n1_t* lhs, oarrm9n1_t*   rhs);
  oarrm9n1_t oarrm9n1_div_Oo(oarrm9n1_t*   lhs, onumm9n1_t* rhs);
  oarrm9n1_t oarrm9n1_div_rO(coeff_t    lhs, oarrm9n1_t*   rhs);
  oarrm9n1_t oarrm9n1_div_Or(oarrm9n1_t*   lhs, coeff_t    rhs);
  void oarrm9n1_div_OO_to(oarrm9n1_t*   lhs, oarrm9n1_t*   rhs, oarrm9n1_t* res);
  void oarrm9n1_div_RO_to(darr_t*    lhs, oarrm9n1_t*   rhs, oarrm9n1_t* res);
  void oarrm9n1_div_OR_to(oarrm9n1_t*   lhs, darr_t*    rhs, oarrm9n1_t* res);
  void oarrm9n1_div_oO_to(onumm9n1_t* lhs, oarrm9n1_t*   rhs, oarrm9n1_t* res);
  void oarrm9n1_div_Oo_to(oarrm9n1_t*   lhs, onumm9n1_t* rhs, oarrm9n1_t* res);
  void oarrm9n1_div_rO_to(coeff_t    lhs, oarrm9n1_t*   rhs, oarrm9n1_t* res);
  void oarrm9n1_div_Or_to(oarrm9n1_t*   lhs, coeff_t    rhs, oarrm9n1_t* res);
  
  
  # From ../../../include/oti/static/onumm9n1/array/base.h
  
  void    oarrm9n1_taylor_integrate_to( coeff_t* deltas, oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_taylor_integrate(    coeff_t* deltas, oarrm9n1_t* arr);
  void    oarrm9n1_get_order_im_to( ord_t order, oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_get_order_im(    ord_t order, oarrm9n1_t* arr);
  void oarrm9n1_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm9n1_t* res);
  void oarrm9n1_set_slice_O( oarrm9n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm9n1_t* res);
  void oarrm9n1_set_slice_o( onumm9n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_get_slice( oarrm9n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm9n1_get_slice_to( oarrm9n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_truncate_im(    imdir_t idx, ord_t order, oarrm9n1_t* arr);
  void    oarrm9n1_truncate_im_to( imdir_t idx, ord_t order, oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_extract_im(   imdir_t idx, ord_t order, oarrm9n1_t* arr);
  void    oarrm9n1_extract_im_to(imdir_t idx, ord_t order, oarrm9n1_t* arr, oarrm9n1_t* res);
  darr_t  oarrm9n1_get_deriv(    imdir_t idx, ord_t order, oarrm9n1_t* arr);
  void    oarrm9n1_get_deriv_to( imdir_t idx, ord_t order, oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_get_deriv_o(  imdir_t idx, ord_t order, oarrm9n1_t* arr);
  oarrm9n1_t oarrm9n1_extract_deriv(    imdir_t idx, ord_t order, oarrm9n1_t* arr);
  void    oarrm9n1_extract_deriv_to( imdir_t idx, ord_t order, oarrm9n1_t* arr, oarrm9n1_t* res);
  darr_t  oarrm9n1_get_im(   imdir_t idx, ord_t order, oarrm9n1_t* arr);
  oarrm9n1_t oarrm9n1_get_im_o( imdir_t idx, ord_t order, oarrm9n1_t* arr);
  void    oarrm9n1_get_im_to(imdir_t idx, ord_t order, oarrm9n1_t* arr, oarrm9n1_t* res);
  void    oarrm9n1_copy_to(oarrm9n1_t* arr, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_copy(oarrm9n1_t* arr);
  void oarrm9n1_set_all_r( coeff_t num, oarrm9n1_t* arr);
  void oarrm9n1_set_item_i_r( coeff_t num, uint64_t i, oarrm9n1_t* arr);
  void oarrm9n1_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm9n1_t* arr);
  void oarrm9n1_set_r(   coeff_t  num,   oarrm9n1_t* arr);
  void oarrm9n1_set_o( onumm9n1_t* num,   oarrm9n1_t* arr);
  void oarrm9n1_set_O(   oarrm9n1_t* arrin, oarrm9n1_t* arr);
  void oarrm9n1_set_all_o( onumm9n1_t* src, oarrm9n1_t* arr);
  void oarrm9n1_set_item_i_o( onumm9n1_t* num, uint64_t i, oarrm9n1_t* arr);
  void oarrm9n1_set_item_ij_o( onumm9n1_t* num, uint64_t i, uint64_t j, oarrm9n1_t* arr);
  onumm9n1_t oarrm9n1_get_item_i(    oarrm9n1_t* arr, uint64_t i);
  void      oarrm9n1_get_item_i_to( oarrm9n1_t* arr, uint64_t i,             onumm9n1_t* res);
  onumm9n1_t oarrm9n1_get_item_ij(   oarrm9n1_t* arr, uint64_t i, uint64_t j);
  void      oarrm9n1_get_item_ij_to(oarrm9n1_t* arr, uint64_t i, uint64_t j, onumm9n1_t* res);
  oarrm9n1_t oarrm9n1_init();
  void oarrm9n1_free(oarrm9n1_t* arr);
  oarrm9n1_t oarrm9n1_empty_like(oarrm9n1_t* arr);
  oarrm9n1_t oarrm9n1_eye(uint64_t nrows);
  oarrm9n1_t oarrm9n1_ones(uint64_t nrows, uint64_t ncols);
  oarrm9n1_t oarrm9n1_zeros(uint64_t nrows, uint64_t ncols);
  oarrm9n1_t oarrm9n1_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm9n1/array/utils.h
  
  void oarrm9n1_dimCheck_OO_elementwise(oarrm9n1_t* arr1, oarrm9n1_t* arr2, oarrm9n1_t* res);
  void oarrm9n1_dimCheck_RO_elementwise(darr_t*  arr1, oarrm9n1_t* arr2, oarrm9n1_t* res);
  void oarrm9n1_dimCheck_OO_matmul(oarrm9n1_t* arr1, oarrm9n1_t* arr2, oarrm9n1_t* res);
  void oarrm9n1_dimCheck_RO_matmul(darr_t*  arr1, oarrm9n1_t* arr2, oarrm9n1_t* res);
  void oarrm9n1_dimCheck_OR_matmul(oarrm9n1_t* arr1, darr_t*  arr2, oarrm9n1_t* res);
  void oarrm9n1_dimCheck_O_squareness(oarrm9n1_t* arr1, oarrm9n1_t* res);
  void oarrm9n1_dimCheck_OO_samesize(oarrm9n1_t* arr1, oarrm9n1_t* res);
  void oarrm9n1_dimCheck_RO_samesize(darr_t* arr1, oarrm9n1_t* res);
  ord_t oarrm9n1_get_order(oarrm9n1_t* arr);
  void oarrm9n1_get_active_bases(oarrm9n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm9n1/array/algebra_matops.h
  
  onumm9n1_t oarrm9n1_dotproduct_OO(    oarrm9n1_t* lhs, oarrm9n1_t* rhs);
  void      oarrm9n1_dotproduct_OO_to( oarrm9n1_t* lhs, oarrm9n1_t* rhs, onumm9n1_t* res);
  onumm9n1_t oarrm9n1_dotproduct_RO(     darr_t* lhs, oarrm9n1_t* rhs);
  void      oarrm9n1_dotproduct_RO_to(  darr_t* lhs, oarrm9n1_t* rhs, onumm9n1_t* res);
  oarrm9n1_t oarrm9n1_matmul_OO(    oarrm9n1_t* lhs, oarrm9n1_t* rhs);
  oarrm9n1_t oarrm9n1_matmul_OR(    oarrm9n1_t* lhs,  darr_t* rhs);
  oarrm9n1_t oarrm9n1_matmul_RO(     darr_t* lhs, oarrm9n1_t* rhs);
  void    oarrm9n1_matmul_OO_to( oarrm9n1_t* lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
  void    oarrm9n1_matmul_OR_to( oarrm9n1_t* lhs,  darr_t* rhs, oarrm9n1_t* res);
  void    oarrm9n1_matmul_RO_to(  darr_t* lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_transpose(    oarrm9n1_t* arr1);
  void    oarrm9n1_transpose_to( oarrm9n1_t* arr1, oarrm9n1_t* res);
  oarrm9n1_t oarrm9n1_invert(    oarrm9n1_t* arr1);
  void    oarrm9n1_invert_to( oarrm9n1_t* arr1, oarrm9n1_t* res);
  onumm9n1_t oarrm9n1_det(    oarrm9n1_t* arr1);
  void      oarrm9n1_det_to( oarrm9n1_t* arr1, onumm9n1_t* res);
  onumm9n1_t oarrm9n1_norm(    oarrm9n1_t* arr1);
  void      oarrm9n1_norm_to( oarrm9n1_t* arr1,  onumm9n1_t* res);
  onumm9n1_t oarrm9n1_pnorm(    oarrm9n1_t* arr1, coeff_t p);
  void      oarrm9n1_pnorm_to( oarrm9n1_t* arr1, coeff_t p, onumm9n1_t* res);
  
  
  # From ../../../include/oti/static/onumm9n1/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm9n1/array/gauss/functions.h
  
  feoarrm9n1_t feoarrm9n1_atanh(    feoarrm9n1_t* arr);
  void      feoarrm9n1_atanh_to( feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_asinh(    feoarrm9n1_t* arr);
  void      feoarrm9n1_asinh_to( feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_acosh(    feoarrm9n1_t* arr);
  void      feoarrm9n1_acosh_to( feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_tanh(     feoarrm9n1_t* arr);
  void      feoarrm9n1_tanh_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sinh(     feoarrm9n1_t* arr);
  void      feoarrm9n1_sinh_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_cosh(     feoarrm9n1_t* arr);
  void      feoarrm9n1_cosh_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_atan(     feoarrm9n1_t* arr);
  void      feoarrm9n1_atan_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_asin(     feoarrm9n1_t* arr);
  void      feoarrm9n1_asin_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_acos(     feoarrm9n1_t* arr);
  void      feoarrm9n1_acos_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_tan(      feoarrm9n1_t* arr);
  void      feoarrm9n1_tan_to(   feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sin(      feoarrm9n1_t* arr);
  void      feoarrm9n1_sin_to(   feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_cos(      feoarrm9n1_t* arr);
  void      feoarrm9n1_cos_to(   feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_logb(     feoarrm9n1_t* arr, double base);
  void      feoarrm9n1_logb_to(  feoarrm9n1_t* arr, double base, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_log10(    feoarrm9n1_t* arr);
  void      feoarrm9n1_log10_to( feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_log(      feoarrm9n1_t* arr);
  void      feoarrm9n1_log_to(   feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_exp(      feoarrm9n1_t* arr);
  void      feoarrm9n1_exp_to(   feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_cbrt(     feoarrm9n1_t* arr);
  void      feoarrm9n1_cbrt_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sqrt(     feoarrm9n1_t* arr);
  void      feoarrm9n1_sqrt_to(  feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_pow(      feoarrm9n1_t* arr, double e);
  void      feoarrm9n1_pow_to(   feoarrm9n1_t* arr, double e, feoarrm9n1_t* res);
  
  
  # From ../../../include/oti/static/onumm9n1/array/gauss/base.h
  
  void      feoarrm9n1_get_order_im_to( ord_t order, feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_get_order_im(    ord_t order, feoarrm9n1_t* arr);
  feoarrm9n1_t feoarrm9n1_get_deriv(   imdir_t idx, ord_t order, feoarrm9n1_t* arr);
  void      feoarrm9n1_get_deriv_to(imdir_t idx, ord_t order, feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_get_im(      imdir_t idx, ord_t order, feoarrm9n1_t* arr);
  void      feoarrm9n1_get_im_to(   imdir_t idx, ord_t order, feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_truncate_im(   imdir_t idx, ord_t order, feoarrm9n1_t* arr);
  void      feoarrm9n1_truncate_im_to(imdir_t idx, ord_t order, feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_copy(   feoarrm9n1_t* src);
  void      feoarrm9n1_copy_to(feoarrm9n1_t* src, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_get_im(    imdir_t idx, ord_t order, feoarrm9n1_t* arr);
  void      feoarrm9n1_get_im_to( imdir_t idx, ord_t order, feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_get_deriv(    imdir_t idx, ord_t order, feoarrm9n1_t* arr);
  void      feoarrm9n1_get_deriv_to( imdir_t idx, ord_t order, feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_extract_im(    imdir_t idx, ord_t order, feoarrm9n1_t* arr);
  void      feoarrm9n1_extract_im_to( imdir_t idx, ord_t order, feoarrm9n1_t* arr,  feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_extract_deriv(    imdir_t idx, ord_t order, feoarrm9n1_t* arr);
  void      feoarrm9n1_extract_deriv_to( imdir_t idx, ord_t order, feoarrm9n1_t* arr, feoarrm9n1_t* res);
  oarrm9n1_t   feoarrm9n1_get_item_k(  feoarrm9n1_t* arr, uint64_t k);
  feonumm9n1_t  feoarrm9n1_get_item_ij( feoarrm9n1_t* arr, uint64_t i, uint64_t j);
  onumm9n1_t feoarrm9n1_get_item_ijk(feoarrm9n1_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm9n1_get_item_ij_to(  feoarrm9n1_t* arr, uint64_t i, uint64_t j,
                                 feonumm9n1_t* res);
  void feoarrm9n1_get_item_k_to(   feoarrm9n1_t* arr, uint64_t k,
                                  oarrm9n1_t* res);
  void feoarrm9n1_get_item_ijk_to( feoarrm9n1_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_get_slice(feoarrm9n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm9n1_get_slice_to(feoarrm9n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n1_t* res);
  void feoarrm9n1_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm9n1_t* res);
  void feoarrm9n1_set_item_ij_o(  onumm9n1_t* elm, uint64_t i, uint64_t j,
                               feoarrm9n1_t* res);
  void feoarrm9n1_set_item_ij_f(  feonumm9n1_t* elm, uint64_t i, uint64_t j,
                              feoarrm9n1_t* res);
  void feoarrm9n1_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm9n1_t* res);
  void feoarrm9n1_set_item_k_o(  onumm9n1_t* elm, uint64_t k,
                              feoarrm9n1_t* res);
  void feoarrm9n1_set_item_k_R(    oarrm9n1_t* elm, uint64_t k,
                            feoarrm9n1_t* res);
  void feoarrm9n1_set_item_k_O(    oarrm9n1_t* elm, uint64_t k,
                            feoarrm9n1_t* res);
  void feoarrm9n1_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm9n1_t* res);
  void feoarrm9n1_set_item_ijk_o( onumm9n1_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm9n1_t* res);
  void feoarrm9n1_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n1_t* res);
  void feoarrm9n1_set_slice_o( onumm9n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n1_t* res);
  void feoarrm9n1_set_slice_f( feonumm9n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n1_t* res);
  void feoarrm9n1_set_slice_O( oarrm9n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n1_t* res);
  void feoarrm9n1_set_slice_F( feoarrm9n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm9n1_t* res);
  void feoarrm9n1_set_all_o( onumm9n1_t* num, feoarrm9n1_t* arr );
  void feoarrm9n1_set_all_r(   coeff_t  num, feoarrm9n1_t* arr );
  void feoarrm9n1_set_all_f(  feonumm9n1_t* num, feoarrm9n1_t* arr );
  void feoarrm9n1_set_r(    coeff_t src, feoarrm9n1_t* res );
  void feoarrm9n1_set_o( onumm9n1_t* src, feoarrm9n1_t* res );
  void feoarrm9n1_set_f(  feonumm9n1_t* src, feoarrm9n1_t* res );
  void feoarrm9n1_set_R(    darr_t* src, feoarrm9n1_t* res );
  void feoarrm9n1_set_O(   oarrm9n1_t* src, feoarrm9n1_t* res );
  void feoarrm9n1_set_F( feoarrm9n1_t* src, feoarrm9n1_t* res );
  feoarrm9n1_t feoarrm9n1_eye( uint64_t size,  uint64_t nip);
  feoarrm9n1_t feoarrm9n1_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm9n1_t feoarrm9n1_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm9n1_t feoarrm9n1_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm9n1_free(feoarrm9n1_t* arr);
  feoarrm9n1_t feoarrm9n1_init();
  ord_t feoarrm9n1_get_order(feoarrm9n1_t* arr);
  
  
  # From ../../../include/oti/static/onumm9n1/array/gauss/utils.h
  
  void feoarrm9n1_dimCheck_FF_samesize(feoarrm9n1_t* arr1, feoarrm9n1_t* arr2, feonumm9n1_t* res);
  void feoarrm9n1_dimCheck_OF_samesize(  oarrm9n1_t* arr1, feoarrm9n1_t* arr2, feonumm9n1_t* res);
  void feoarrm9n1_dimCheck_RF_samesize(   darr_t* arr1, feoarrm9n1_t* arr2, feonumm9n1_t* res);
  void feoarrm9n1_dimCheck_FF_elementwise(feoarrm9n1_t* arr1, feoarrm9n1_t* arr2, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_OF_elementwise(  oarrm9n1_t* arr1, feoarrm9n1_t* arr2, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm9n1_t* arr2, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_fF_elementwise( feonumm9n1_t* num1, feoarrm9n1_t* arr2, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_Ff_elementwise(feoarrm9n1_t* arr1,  feonumm9n1_t* num2, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_FF_matmul( feoarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_OF_matmul(   oarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_FO_matmul( feoarrm9n1_t* lhs,   oarrm9n1_t* rhs, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_FR_matmul( feoarrm9n1_t* lhs,    darr_t* rhs, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_F_squareness( feoarrm9n1_t* arr1, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_F_transpose( feoarrm9n1_t* arr1, feoarrm9n1_t* res);
  void feoarrm9n1_dimCheck_FfO_integrate(feoarrm9n1_t* arr, feonumm9n1_t* num,oarrm9n1_t* res);
  void feoarrm9n1_get_active_bases(feoarrm9n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm9n1/array/gauss/algebra.h
  
  feoarrm9n1_t feoarrm9n1_neg(    feoarrm9n1_t* arr);
  void      feoarrm9n1_neg_to( feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sum_FF(   feoarrm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sum_FF_to(feoarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sum_fF(    feonumm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sum_fF_to( feonumm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sum_OF(     oarrm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sum_OF_to(  oarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sum_RF(      darr_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sum_RF_to(   darr_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sum_oF(   onumm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sum_oF_to(onumm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sum_rF(     coeff_t  lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sum_rF_to(  coeff_t  lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sub_FF(    feoarrm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sub_FF_to( feoarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sub_fF(    feonumm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sub_fF_to( feonumm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sub_Ff(    feoarrm9n1_t* lhs, feonumm9n1_t* rhs);
  void      feoarrm9n1_sub_Ff_to( feoarrm9n1_t* lhs, feonumm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sub_OF(      oarrm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sub_OF_to(   oarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sub_FO(    feoarrm9n1_t* lhs,   oarrm9n1_t* rhs);
  void      feoarrm9n1_sub_FO_to( feoarrm9n1_t* lhs,   oarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sub_RF(       darr_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sub_RF_to(    darr_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sub_FR(    feoarrm9n1_t* lhs,    darr_t* rhs);
  void      feoarrm9n1_sub_FR_to( feoarrm9n1_t* lhs,    darr_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sub_oF(    onumm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sub_oF_to( onumm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sub_Fo(    feoarrm9n1_t* lhs, onumm9n1_t* rhs);
  void      feoarrm9n1_sub_Fo_to( feoarrm9n1_t* lhs, onumm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sub_rF(      coeff_t  lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_sub_rF_to(    coeff_t lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_sub_Fr(    feoarrm9n1_t* lhs,   coeff_t  rhs);
  void      feoarrm9n1_sub_Fr_to( feoarrm9n1_t* lhs,   coeff_t  rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_mul_FF(   feoarrm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_mul_FF_to(feoarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_mul_fF(    feonumm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_mul_fF_to( feonumm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_mul_OF(     oarrm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_mul_OF_to(  oarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_mul_RF(      darr_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_mul_RF_to(   darr_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_mul_oF(   onumm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_mul_oF_to(onumm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_mul_rF(     coeff_t  lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_mul_rF_to(  coeff_t  lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_div_FF(    feoarrm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_div_FF_to( feoarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_div_fF(     feonumm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_div_fF_to(  feonumm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_div_Ff(    feoarrm9n1_t* lhs,  feonumm9n1_t* rhs);
  void      feoarrm9n1_div_Ff_to( feoarrm9n1_t* lhs,  feonumm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_div_OF(      oarrm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_div_OF_to(   oarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_div_FO(    feoarrm9n1_t* lhs,   oarrm9n1_t* rhs);
  void      feoarrm9n1_div_FO_to( feoarrm9n1_t* lhs,   oarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_div_RF(       darr_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_div_RF_to(    darr_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_div_FR(    feoarrm9n1_t* lhs,    darr_t* rhs);
  void      feoarrm9n1_div_FR_to( feoarrm9n1_t* lhs,    darr_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_div_oF(    onumm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_div_oF_to( onumm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_div_Fo(    feoarrm9n1_t* lhs, onumm9n1_t* rhs);
  void      feoarrm9n1_div_Fo_to( feoarrm9n1_t* lhs, onumm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_div_rF(      coeff_t  lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_div_rF_to(    coeff_t lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_div_Fr(    feoarrm9n1_t* lhs,   coeff_t  rhs);
  void      feoarrm9n1_div_Fr_to( feoarrm9n1_t* lhs,   coeff_t  rhs, feoarrm9n1_t* res);
  oarrm9n1_t feoarrm9n1_integrate(    feoarrm9n1_t* arr, feonumm9n1_t* w);
  void    feoarrm9n1_integrate_to( feoarrm9n1_t* arr, feonumm9n1_t* w, oarrm9n1_t* res);
  feonumm9n1_t feoarrm9n1_dotproduct_FF(    feoarrm9n1_t* lhs, feoarrm9n1_t* rhs);
  void     feoarrm9n1_dotproduct_FF_to( feoarrm9n1_t* lhs, feoarrm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feoarrm9n1_dotproduct_OF(      oarrm9n1_t* lhs, feoarrm9n1_t* rhs);
  void     feoarrm9n1_dotproduct_OF_to(   oarrm9n1_t* lhs, feoarrm9n1_t* rhs, feonumm9n1_t* res);
  feonumm9n1_t feoarrm9n1_dotproduct_RF(       darr_t* lhs, feoarrm9n1_t* rhs);
  void     feoarrm9n1_dotproduct_RF_to(    darr_t* lhs, feoarrm9n1_t* rhs, feonumm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_matmul_FF(    feoarrm9n1_t* lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_matmul_FF_to( feoarrm9n1_t* lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_matmul_OF(    oarrm9n1_t*   lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_matmul_OF_to( oarrm9n1_t*   lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_matmul_FO(    feoarrm9n1_t* lhs, oarrm9n1_t*   rhs);
  void      feoarrm9n1_matmul_FO_to( feoarrm9n1_t* lhs, oarrm9n1_t*   rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_matmul_RF(    darr_t*    lhs, feoarrm9n1_t* rhs);
  void      feoarrm9n1_matmul_RF_to( darr_t*    lhs, feoarrm9n1_t* rhs, feoarrm9n1_t* res);
  feoarrm9n1_t feoarrm9n1_matmul_FR(    feoarrm9n1_t* lhs, darr_t*    rhs);
  void      feoarrm9n1_matmul_FR_to( feoarrm9n1_t* lhs, darr_t*    rhs, feoarrm9n1_t* res);
  feonumm9n1_t feoarrm9n1_det(   feoarrm9n1_t* arr);
  void     feoarrm9n1_det_to(feoarrm9n1_t* arr, feonumm9n1_t* res);
  feonumm9n1_t feoarrm9n1_norm(     feoarrm9n1_t* arr);
  void     feoarrm9n1_norm_to(  feoarrm9n1_t* arr, feonumm9n1_t* res);
  feonumm9n1_t feoarrm9n1_pnorm(    feoarrm9n1_t* arr, coeff_t p);
  void     feoarrm9n1_pnorm_to( feoarrm9n1_t* arr, coeff_t p, feonumm9n1_t* res);
  feoarrm9n1_t   feoarrm9n1_invert(    feoarrm9n1_t* arr);
  void        feoarrm9n1_invert_to( feoarrm9n1_t* arr, feoarrm9n1_t* res);
  feoarrm9n1_t   feoarrm9n1_transpose(   feoarrm9n1_t* arr);
  void        feoarrm9n1_transpose_to(feoarrm9n1_t* arr, feoarrm9n1_t* res);
  
  