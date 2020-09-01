cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm5n1/scalar/structures.h
  
  ctypedef struct  onumm5n1_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
  # } onumm5n1_t;
  
  
  # From ../../../include/oti/static/onumm5n1/array/structures.h
  
  ctypedef struct  oarrm5n1_t : # {
      onumm5n1_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
      flag_t          flag;
  # } oarrm5n1_t;
  
  
  # From ../../../include/oti/static/onumm5n1/scalar/gauss/structures.h
  
  ctypedef struct  feonumm5n1_t: # {
      onumm5n1_t*  p_data;
      uint64_t    nip;
  # } feonumm5n1_t;
  
  
  # From ../../../include/oti/static/onumm5n1/array/gauss/structures.h
  
  ctypedef struct  feoarrm5n1_t: # {
      oarrm5n1_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm5n1_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm5n1/scalar/functions.h
  
  onumm5n1_t onumm5n1_atanh(onumm5n1_t* num);
  void onumm5n1_atanh_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_asinh(onumm5n1_t* num);
  void onumm5n1_asinh_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_acosh(onumm5n1_t* num);
  void onumm5n1_acosh_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_tanh(onumm5n1_t* num);
  void onumm5n1_tanh_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_sqrt(onumm5n1_t* num);
  void onumm5n1_sqrt_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_cbrt(onumm5n1_t* num);
  void onumm5n1_cbrt_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_cosh(onumm5n1_t* num);
  void onumm5n1_cosh_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_sinh(onumm5n1_t* num);
  void onumm5n1_sinh_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_asin(onumm5n1_t* num);
  void onumm5n1_asin_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_acos(onumm5n1_t* num);
  void onumm5n1_acos_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_atan(onumm5n1_t* num);
  void onumm5n1_atan_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_tan(onumm5n1_t* num);
  void onumm5n1_tan_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_cos(onumm5n1_t* num);
  void onumm5n1_cos_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_sin(onumm5n1_t* num );
  void onumm5n1_sin_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_logb(onumm5n1_t* num, double base);
  void onumm5n1_logb_to(onumm5n1_t* num, double base, onumm5n1_t* res);
  onumm5n1_t onumm5n1_log10(onumm5n1_t* num);
  void onumm5n1_log10_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_log(onumm5n1_t* num);
  void onumm5n1_log_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_exp(onumm5n1_t* num);
  void onumm5n1_exp_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_pow(onumm5n1_t* num, double e);
  void onumm5n1_pow_to(onumm5n1_t* num, coeff_t e, onumm5n1_t* res);
  
  
  # From ../../../include/oti/static/onumm5n1/scalar/base.h
  
  void onumm5n1_set_im_o(onumm5n1_t* num, imdir_t idx, ord_t order, onumm5n1_t* res);
  void onumm5n1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm5n1_t* res);
  void onumm5n1_set_deriv_o(onumm5n1_t* num, imdir_t idx, ord_t order, onumm5n1_t* res);
  void onumm5n1_extract_im_to( imdir_t idx, ord_t order, onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_extract_im(imdir_t idx, ord_t order, onumm5n1_t* num);
  onumm5n1_t onumm5n1_extract_deriv(imdir_t idx, ord_t order, onumm5n1_t* num);
  void onumm5n1_extract_deriv_to(imdir_t idx, ord_t order, onumm5n1_t* num, onumm5n1_t* res);
  void onumm5n1_get_im_to_o(imdir_t idx, ord_t order, onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_get_im_o(imdir_t idx, ord_t order, onumm5n1_t* num);
  void onumm5n1_get_im_to_r(imdir_t idx, ord_t order, onumm5n1_t* num, coeff_t* res);
  ord_t onumm5n1_get_order(onumm5n1_t* lhs);
  onumm5n1_t onumm5n1_get_deriv_o( imdir_t idx, ord_t order, onumm5n1_t* num);
  void onumm5n1_get_deriv_to( imdir_t idx, ord_t order, onumm5n1_t* num, onumm5n1_t* res);
  void onumm5n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm5n1_t* res);
  onumm5n1_t onumm5n1_init();
  ndir_t onumm5n1_get_ndir_order(ord_t order, onumm5n1_t* num);
  ndir_t onumm5n1_get_ndir_total(onumm5n1_t* num);
  coeff_t* onumm5n1_get_order_address(ord_t order, onumm5n1_t* num);
  onumm5n1_t onumm5n1_create_r(  coeff_t lhs);
  void onumm5n1_set_r(  coeff_t lhs, onumm5n1_t* res);
  void onumm5n1_set_o(  onumm5n1_t* lhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_get_order_im(ord_t order, onumm5n1_t* lhs);
  void onumm5n1_get_order_im_to(ord_t order, onumm5n1_t* lhs, onumm5n1_t* res);
  coeff_t onumm5n1_get_item(imdir_t idx, ord_t order, onumm5n1_t* lhs);
  coeff_t onumm5n1_get_deriv(imdir_t idx, ord_t order, onumm5n1_t* lhs);
  void onumm5n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm5n1_t* x);
  onumm5n1_t onumm5n1_copy(  onumm5n1_t* lhs);
  void onumm5n1_copy_to(  onumm5n1_t* lhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_taylor_integrate(coeff_t* deltas,onumm5n1_t* lhs);
  void onumm5n1_taylor_integrate_to(coeff_t* deltas,onumm5n1_t* lhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_truncate_im(imdir_t idx, ord_t order, onumm5n1_t* lhs);
  void onumm5n1_truncate_im_to(imdir_t idx, ord_t order, onumm5n1_t* lhs, onumm5n1_t* res);
  void onumm5n1_print(  onumm5n1_t* lhs);
  imdir_t onumm5n1_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm5n1/scalar/utils.h
  
  void onumm5n1_get_active_bases(onumm5n1_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm5n1/scalar/algebra.h
  
  onumm5n1_t onumm5n1_abs(onumm5n1_t* num);
  onumm5n1_t onumm5n1_div_ro(coeff_t num, onumm5n1_t* den);
  onumm5n1_t onumm5n1_div_oo(onumm5n1_t* num, onumm5n1_t* den);
  onumm5n1_t onumm5n1_div_or(onumm5n1_t* num, coeff_t val);
  void onumm5n1_div_ro_to(coeff_t num, onumm5n1_t* den, onumm5n1_t* res);
  void onumm5n1_div_oo_to(onumm5n1_t* num, onumm5n1_t* den, onumm5n1_t* res);
  void onumm5n1_div_or_to(onumm5n1_t* num, coeff_t val, onumm5n1_t* res);
  void onumm5n1_abs_to(onumm5n1_t* num, onumm5n1_t* res);
  onumm5n1_t onumm5n1_neg(  onumm5n1_t* lhs);
  void onumm5n1_neg_to(  onumm5n1_t* lhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_sum_oo(  onumm5n1_t* lhs,  onumm5n1_t* rhs);
  void onumm5n1_sum_oo_to(  onumm5n1_t* lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_sum_ro(  coeff_t lhs,  onumm5n1_t* rhs);
  void onumm5n1_sum_ro_to(  coeff_t lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_sub_oo(  onumm5n1_t* lhs,  onumm5n1_t* rhs);
  void onumm5n1_sub_oo_to(  onumm5n1_t* lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_sub_ro(  coeff_t lhs,  onumm5n1_t* rhs);
  void onumm5n1_sub_ro_to(  coeff_t lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_sub_or(  onumm5n1_t* lhs,  coeff_t rhs);
  void onumm5n1_sub_or_to(  onumm5n1_t* lhs,  coeff_t rhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_mul_oo(  onumm5n1_t* lhs,  onumm5n1_t* rhs);
  void onumm5n1_mul_oo_to(  onumm5n1_t* lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_mul_ro(  coeff_t lhs,  onumm5n1_t* rhs);
  void onumm5n1_mul_ro_to(  coeff_t lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_trunc_mul_oo(  onumm5n1_t* lhs,  onumm5n1_t* rhs);
  void onumm5n1_trunc_mul_oo_to(  onumm5n1_t* lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
  onumm5n1_t onumm5n1_gem_oo(  onumm5n1_t* a,  onumm5n1_t* b,  onumm5n1_t* c);
  void onumm5n1_gem_oo_to(  onumm5n1_t* a,  onumm5n1_t* b,  onumm5n1_t* c, onumm5n1_t* res);
  onumm5n1_t onumm5n1_gem_ro(  coeff_t a,  onumm5n1_t* b,  onumm5n1_t* c);
  void onumm5n1_gem_ro_to(  coeff_t a,  onumm5n1_t* b,  onumm5n1_t* c, onumm5n1_t* res);
  void onumm5n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n1_t* a,  ord_t ord_rhs,  onumm5n1_t* b,  onumm5n1_t* c, onumm5n1_t* res);
  onumm5n1_t onumm5n1_feval(coeff_t* feval_re, onumm5n1_t* x);
  void onumm5n1_feval_to(coeff_t* feval_re, onumm5n1_t* x, onumm5n1_t* res);
  
  
  # From ../../../include/oti/static/onumm5n1/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm5n1/scalar/gauss/functions.h
  
  feonumm5n1_t feonumm5n1_atanh(    feonumm5n1_t* num);
  void     feonumm5n1_atanh_to( feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_asinh(    feonumm5n1_t* num);
  void     feonumm5n1_asinh_to( feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_acosh(    feonumm5n1_t* num);
  void     feonumm5n1_acosh_to( feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_tanh(     feonumm5n1_t* num);
  void     feonumm5n1_tanh_to(  feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_cosh(     feonumm5n1_t* num);
  void     feonumm5n1_cosh_to(  feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_sinh(     feonumm5n1_t* num);
  void     feonumm5n1_sinh_to(  feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_asin(     feonumm5n1_t* num);
  void     feonumm5n1_asin_to(  feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_acos(     feonumm5n1_t* num);
  void     feonumm5n1_acos_to(  feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_atan(     feonumm5n1_t* num);
  void     feonumm5n1_atan_to(  feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_tan(      feonumm5n1_t* num);
  void     feonumm5n1_tan_to(   feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_cos(      feonumm5n1_t* num);
  void     feonumm5n1_cos_to(   feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_sin(      feonumm5n1_t* num);
  void     feonumm5n1_sin_to(   feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_logb(     feonumm5n1_t* num, double base);
  void     feonumm5n1_logb_to(  feonumm5n1_t* num, double base, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_log10(    feonumm5n1_t* num);
  void     feonumm5n1_log10_to( feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_log(      feonumm5n1_t* num);
  void     feonumm5n1_log_to(   feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_exp(      feonumm5n1_t* num);
  void     feonumm5n1_exp_to(   feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_cbrt(     feonumm5n1_t* num);
  void     feonumm5n1_cbrt_to(  feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_sqrt(     feonumm5n1_t* num);
  void     feonumm5n1_sqrt_to(  feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_pow(      feonumm5n1_t* num, double e);
  void     feonumm5n1_pow_to(   feonumm5n1_t* num, double e, feonumm5n1_t* res);
  onumm5n1_t feonumm5n1_integrate(       feonumm5n1_t* num, feonumm5n1_t* w);
  void      feonumm5n1_integrate_to(    feonumm5n1_t* num, feonumm5n1_t* w, onumm5n1_t* res);
  onumm5n1_t feonumm5n1_integrate_f(     feonumm5n1_t* num, feonumm5n1_t* w);
  void      feonumm5n1_integrate_f_to(  feonumm5n1_t* num, feonumm5n1_t* w, onumm5n1_t* res);
  onumm5n1_t feonumm5n1_integrate_r(       coeff_t num, feonumm5n1_t* w);
  void      feonumm5n1_integrate_r_to(    coeff_t num, feonumm5n1_t* w, onumm5n1_t* res);
  onumm5n1_t feonumm5n1_integrate_o(    onumm5n1_t* num, feonumm5n1_t* w);
  void      feonumm5n1_integrate_o_to( onumm5n1_t* num, feonumm5n1_t* w, onumm5n1_t* res);
  
  
  # From ../../../include/oti/static/onumm5n1/scalar/gauss/base.h
  
  void     feonumm5n1_get_order_im_to( ord_t order, feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_get_order_im(    ord_t order, feonumm5n1_t* num);
  feonumm5n1_t feonumm5n1_get_im(    imdir_t idx, ord_t order, feonumm5n1_t* num);
  void     feonumm5n1_get_im_to( imdir_t idx, ord_t order, feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_get_deriv(    imdir_t idx, ord_t order, feonumm5n1_t* num);
  void     feonumm5n1_get_deriv_to( imdir_t idx, ord_t order, feonumm5n1_t* num, feonumm5n1_t* res);
  void feonumm5n1_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm5n1_t* num);
  void feonumm5n1_set_im_o( onumm5n1_t* val, imdir_t idx, ord_t order, feonumm5n1_t* num);
  void feonumm5n1_set_im_f(  feonumm5n1_t* val, imdir_t idx, ord_t order, feonumm5n1_t* num);
  void feonumm5n1_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm5n1_t* num);
  void feonumm5n1_set_deriv_o( onumm5n1_t* val, imdir_t idx, ord_t order, feonumm5n1_t* num);
  void feonumm5n1_set_deriv_f(  feonumm5n1_t* val, imdir_t idx, ord_t order, feonumm5n1_t* num);
  feonumm5n1_t feonumm5n1_extract_im(    imdir_t idx, ord_t order, feonumm5n1_t* num);
  void     feonumm5n1_extract_im_to( imdir_t idx, ord_t order, feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_extract_deriv(    imdir_t idx, ord_t order, feonumm5n1_t* num);
  void     feonumm5n1_extract_deriv_to( imdir_t idx, ord_t order, feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_truncate_im(    imdir_t idx, ord_t order, feonumm5n1_t* num);
  void     feonumm5n1_truncate_im_to( imdir_t idx, ord_t order, feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_copy(    feonumm5n1_t* src);
  void     feonumm5n1_copy_to( feonumm5n1_t* src, feonumm5n1_t* dst);
  void feonumm5n1_set_r(    coeff_t num, feonumm5n1_t* res);
  void feonumm5n1_set_o( onumm5n1_t* num, feonumm5n1_t* res);
  void feonumm5n1_set_f(  feonumm5n1_t* num, feonumm5n1_t* res);
  void feonumm5n1_set_item_k_r(   coeff_t  num, uint64_t k, feonumm5n1_t* res);
  void feonumm5n1_set_item_k_o( onumm5n1_t* num, uint64_t k, feonumm5n1_t* res);
  onumm5n1_t feonumm5n1_get_item_k(   feonumm5n1_t* num, uint64_t k);
  void      feonumm5n1_get_item_k_to(feonumm5n1_t* num, uint64_t k, onumm5n1_t* res);
  feonumm5n1_t feonumm5n1_zeros(uint64_t nIntPts);
  feonumm5n1_t feonumm5n1_createEmpty(uint64_t nIntPts);
  feonumm5n1_t feonumm5n1_empty_like(feonumm5n1_t* arr);
  void feonumm5n1_free(feonumm5n1_t* num);
  ord_t feonumm5n1_get_order( feonumm5n1_t* num );
  feonumm5n1_t feonumm5n1_init();
  
  
  # From ../../../include/oti/static/onumm5n1/scalar/gauss/utils.h
  
  void feonumm5n1_dimCheck(feonumm5n1_t* arr1,feonumm5n1_t* arr2);
  void feonumm5n1_get_active_bases(feonumm5n1_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n1/scalar/gauss/algebra.h
  
  feonumm5n1_t feonumm5n1_neg(   feonumm5n1_t* num);
  void     feonumm5n1_neg_to(feonumm5n1_t* num, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_sum_ff(   feonumm5n1_t* lhs, feonumm5n1_t* rhs);
  void     feonumm5n1_sum_ff_to(feonumm5n1_t* lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_sum_of(   onumm5n1_t* lhs, feonumm5n1_t* rhs);
  void     feonumm5n1_sum_of_to(onumm5n1_t* lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_sum_rf(   coeff_t lhs, feonumm5n1_t* rhs);
  void     feonumm5n1_sum_rf_to(coeff_t lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_sub_ff(     feonumm5n1_t* lhs,  feonumm5n1_t* rhs);
  void     feonumm5n1_sub_ff_to(  feonumm5n1_t* lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_sub_of(    onumm5n1_t* lhs,  feonumm5n1_t* rhs);
  void     feonumm5n1_sub_of_to( onumm5n1_t* lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_sub_fo(     feonumm5n1_t* lhs, onumm5n1_t* rhs);
  void     feonumm5n1_sub_fo_to(  feonumm5n1_t* lhs, onumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_sub_rf(       coeff_t lhs,  feonumm5n1_t* rhs);
  void     feonumm5n1_sub_rf_to(    coeff_t lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_sub_fr(     feonumm5n1_t* lhs,    coeff_t rhs);
  void     feonumm5n1_sub_fr_to(  feonumm5n1_t* lhs,    coeff_t rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_mul_ff(   feonumm5n1_t* lhs, feonumm5n1_t* rhs);
  void     feonumm5n1_mul_ff_to(feonumm5n1_t* lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_mul_of(   onumm5n1_t* lhs, feonumm5n1_t* rhs);
  void     feonumm5n1_mul_of_to(onumm5n1_t* lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_mul_rf(   coeff_t lhs, feonumm5n1_t* rhs);
  void     feonumm5n1_mul_rf_to(coeff_t lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_div_ff(     feonumm5n1_t* lhs,  feonumm5n1_t* rhs);
  void     feonumm5n1_div_ff_to(  feonumm5n1_t* lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_div_of(    onumm5n1_t* lhs,  feonumm5n1_t* rhs);
  void     feonumm5n1_div_of_to( onumm5n1_t* lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_div_fo(     feonumm5n1_t* lhs, onumm5n1_t* rhs);
  void     feonumm5n1_div_fo_to(  feonumm5n1_t* lhs, onumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_div_rf(       coeff_t lhs,  feonumm5n1_t* rhs);
  void     feonumm5n1_div_rf_to(    coeff_t lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feonumm5n1_div_fr(     feonumm5n1_t* lhs,    coeff_t rhs);
  void     feonumm5n1_div_fr_to(  feonumm5n1_t* lhs,    coeff_t rhs, feonumm5n1_t* res);
  
  
  # From ../../../include/oti/static/onumm5n1/array/functions.h
  
  oarrm5n1_t oarrm5n1_atanh(   oarrm5n1_t* arr);
  void    oarrm5n1_atanh_to(oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_asinh(   oarrm5n1_t* arr);
  void    oarrm5n1_asinh_to(oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_acosh(   oarrm5n1_t* arr);
  void    oarrm5n1_acosh_to(oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_tanh(    oarrm5n1_t* arr);
  void    oarrm5n1_tanh_to( oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_cbrt(    oarrm5n1_t* arr);
  void    oarrm5n1_cbrt_to( oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_sqrt(    oarrm5n1_t* arr);
  void    oarrm5n1_sqrt_to( oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_cosh(    oarrm5n1_t* arr);
  void    oarrm5n1_cosh_to( oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_sinh(    oarrm5n1_t* arr);
  void    oarrm5n1_sinh_to( oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_asin(    oarrm5n1_t* arr);
  void    oarrm5n1_asin_to( oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_acos(    oarrm5n1_t* arr);
  void    oarrm5n1_acos_to( oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_atan(    oarrm5n1_t* arr);
  void    oarrm5n1_atan_to( oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_tan(     oarrm5n1_t* arr);
  void    oarrm5n1_tan_to(  oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_cos(     oarrm5n1_t* arr);
  void    oarrm5n1_cos_to(  oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_sin(     oarrm5n1_t* arr);
  void    oarrm5n1_sin_to(  oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_logb(    oarrm5n1_t* arr, double base);
  void    oarrm5n1_logb_to( oarrm5n1_t* arr, double base, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_log10(   oarrm5n1_t* arr);
  void    oarrm5n1_log10_to(oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_log(     oarrm5n1_t* arr);
  void    oarrm5n1_log_to(  oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_exp(     oarrm5n1_t* arr);
  void    oarrm5n1_exp_to(  oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_pow(     oarrm5n1_t* arr, double e);
  void    oarrm5n1_pow_to(  oarrm5n1_t* arr, double e, oarrm5n1_t* res);
  
  
  # From ../../../include/oti/static/onumm5n1/array/algebra_elementwise.h
  
  oarrm5n1_t oarrm5n1_neg(oarrm5n1_t* arr);
  void oarrm5n1_neg_to(oarrm5n1_t* rhs, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_sum_OO(oarrm5n1_t*   lhs, oarrm5n1_t* rhs);
  oarrm5n1_t oarrm5n1_sum_RO(darr_t*    lhs, oarrm5n1_t* rhs);
  oarrm5n1_t oarrm5n1_sum_oO(onumm5n1_t* lhs, oarrm5n1_t* rhs);
  oarrm5n1_t oarrm5n1_sum_rO(coeff_t    lhs, oarrm5n1_t* rhs);
  void oarrm5n1_sum_OO_to(oarrm5n1_t*   lhs, oarrm5n1_t* rhs, oarrm5n1_t* res);
  void oarrm5n1_sum_RO_to(darr_t*    lhs, oarrm5n1_t* rhs, oarrm5n1_t* res);
  void oarrm5n1_sum_oO_to(onumm5n1_t* lhs, oarrm5n1_t* rhs, oarrm5n1_t* res);
  void oarrm5n1_sum_rO_to(coeff_t    lhs, oarrm5n1_t* rhs, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_sub_OO(oarrm5n1_t*   lhs, oarrm5n1_t*   rhs);
  oarrm5n1_t oarrm5n1_sub_RO(darr_t*    lhs, oarrm5n1_t*   rhs);
  oarrm5n1_t oarrm5n1_sub_OR(oarrm5n1_t*   lhs, darr_t*    rhs);
  oarrm5n1_t oarrm5n1_sub_oO(onumm5n1_t* lhs, oarrm5n1_t*   rhs);
  oarrm5n1_t oarrm5n1_sub_Oo(oarrm5n1_t*   lhs, onumm5n1_t* rhs);
  oarrm5n1_t oarrm5n1_sub_rO(coeff_t    lhs, oarrm5n1_t*   rhs);
  oarrm5n1_t oarrm5n1_sub_Or(oarrm5n1_t*   lhs, coeff_t    rhs);
  void oarrm5n1_sub_OO_to( oarrm5n1_t*   lhs, oarrm5n1_t*   rhs, oarrm5n1_t* res);
  void oarrm5n1_sub_RO_to( darr_t*    lhs, oarrm5n1_t*   rhs, oarrm5n1_t* res);
  void oarrm5n1_sub_OR_to( oarrm5n1_t*   lhs, darr_t*    rhs, oarrm5n1_t* res);
  void oarrm5n1_sub_oO_to( onumm5n1_t* lhs, oarrm5n1_t*   rhs, oarrm5n1_t* res);
  void oarrm5n1_sub_Oo_to( oarrm5n1_t*   lhs, onumm5n1_t* rhs, oarrm5n1_t* res);
  void oarrm5n1_sub_rO_to( coeff_t    lhs, oarrm5n1_t*   rhs, oarrm5n1_t* res);
  void oarrm5n1_sub_Or_to( oarrm5n1_t*   lhs, coeff_t    rhs, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_mul_OO(oarrm5n1_t*   lhs, oarrm5n1_t* rhs);
  oarrm5n1_t oarrm5n1_mul_RO(darr_t*    lhs, oarrm5n1_t* rhs);
  oarrm5n1_t oarrm5n1_mul_oO(onumm5n1_t* lhs, oarrm5n1_t* rhs);
  oarrm5n1_t oarrm5n1_mul_rO(coeff_t    lhs, oarrm5n1_t* rhs);
  void oarrm5n1_mul_OO_to(oarrm5n1_t*   lhs, oarrm5n1_t* rhs, oarrm5n1_t* res);
  void oarrm5n1_mul_RO_to(darr_t*    lhs, oarrm5n1_t* rhs, oarrm5n1_t* res);
  void oarrm5n1_mul_oO_to(onumm5n1_t* lhs, oarrm5n1_t* rhs, oarrm5n1_t* res);
  void oarrm5n1_mul_rO_to(coeff_t    lhs, oarrm5n1_t* rhs, oarrm5n1_t* res);
  void oarrm5n1_gem_OO_to(  oarrm5n1_t* arr1, oarrm5n1_t* arr2, oarrm5n1_t* arr3, oarrm5n1_t* res);
  void oarrm5n1_gem_oO_to(onumm5n1_t* arr1, oarrm5n1_t* arr2, oarrm5n1_t* arr3, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_div_OO(oarrm5n1_t*   lhs, oarrm5n1_t*   rhs);
  oarrm5n1_t oarrm5n1_div_OR(oarrm5n1_t*   lhs, darr_t*    rhs);
  oarrm5n1_t oarrm5n1_div_RO(darr_t*    lhs, oarrm5n1_t*   rhs);
  oarrm5n1_t oarrm5n1_div_oO(onumm5n1_t* lhs, oarrm5n1_t*   rhs);
  oarrm5n1_t oarrm5n1_div_Oo(oarrm5n1_t*   lhs, onumm5n1_t* rhs);
  oarrm5n1_t oarrm5n1_div_rO(coeff_t    lhs, oarrm5n1_t*   rhs);
  oarrm5n1_t oarrm5n1_div_Or(oarrm5n1_t*   lhs, coeff_t    rhs);
  void oarrm5n1_div_OO_to(oarrm5n1_t*   lhs, oarrm5n1_t*   rhs, oarrm5n1_t* res);
  void oarrm5n1_div_RO_to(darr_t*    lhs, oarrm5n1_t*   rhs, oarrm5n1_t* res);
  void oarrm5n1_div_OR_to(oarrm5n1_t*   lhs, darr_t*    rhs, oarrm5n1_t* res);
  void oarrm5n1_div_oO_to(onumm5n1_t* lhs, oarrm5n1_t*   rhs, oarrm5n1_t* res);
  void oarrm5n1_div_Oo_to(oarrm5n1_t*   lhs, onumm5n1_t* rhs, oarrm5n1_t* res);
  void oarrm5n1_div_rO_to(coeff_t    lhs, oarrm5n1_t*   rhs, oarrm5n1_t* res);
  void oarrm5n1_div_Or_to(oarrm5n1_t*   lhs, coeff_t    rhs, oarrm5n1_t* res);
  
  
  # From ../../../include/oti/static/onumm5n1/array/base.h
  
  void    oarrm5n1_taylor_integrate_to( coeff_t* deltas, oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_taylor_integrate(    coeff_t* deltas, oarrm5n1_t* arr);
  void    oarrm5n1_get_order_im_to( ord_t order, oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_get_order_im(    ord_t order, oarrm5n1_t* arr);
  void oarrm5n1_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n1_t* res);
  void oarrm5n1_set_slice_O( oarrm5n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n1_t* res);
  void oarrm5n1_set_slice_o( onumm5n1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_get_slice( oarrm5n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm5n1_get_slice_to( oarrm5n1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_truncate_im(    imdir_t idx, ord_t order, oarrm5n1_t* arr);
  void    oarrm5n1_truncate_im_to( imdir_t idx, ord_t order, oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_extract_im(   imdir_t idx, ord_t order, oarrm5n1_t* arr);
  void    oarrm5n1_extract_im_to(imdir_t idx, ord_t order, oarrm5n1_t* arr, oarrm5n1_t* res);
  darr_t  oarrm5n1_get_deriv(    imdir_t idx, ord_t order, oarrm5n1_t* arr);
  void    oarrm5n1_get_deriv_to( imdir_t idx, ord_t order, oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_get_deriv_o(  imdir_t idx, ord_t order, oarrm5n1_t* arr);
  oarrm5n1_t oarrm5n1_extract_deriv(    imdir_t idx, ord_t order, oarrm5n1_t* arr);
  void    oarrm5n1_extract_deriv_to( imdir_t idx, ord_t order, oarrm5n1_t* arr, oarrm5n1_t* res);
  darr_t  oarrm5n1_get_im(   imdir_t idx, ord_t order, oarrm5n1_t* arr);
  oarrm5n1_t oarrm5n1_get_im_o( imdir_t idx, ord_t order, oarrm5n1_t* arr);
  void    oarrm5n1_get_im_to(imdir_t idx, ord_t order, oarrm5n1_t* arr, oarrm5n1_t* res);
  void    oarrm5n1_copy_to(oarrm5n1_t* arr, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_copy(oarrm5n1_t* arr);
  void oarrm5n1_set_all_r( coeff_t num, oarrm5n1_t* arr);
  void oarrm5n1_set_item_i_r( coeff_t num, uint64_t i, oarrm5n1_t* arr);
  void oarrm5n1_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm5n1_t* arr);
  void oarrm5n1_set_r(   coeff_t  num,   oarrm5n1_t* arr);
  void oarrm5n1_set_o( onumm5n1_t* num,   oarrm5n1_t* arr);
  void oarrm5n1_set_O(   oarrm5n1_t* arrin, oarrm5n1_t* arr);
  void oarrm5n1_set_all_o( onumm5n1_t* src, oarrm5n1_t* arr);
  void oarrm5n1_set_item_i_o( onumm5n1_t* num, uint64_t i, oarrm5n1_t* arr);
  void oarrm5n1_set_item_ij_o( onumm5n1_t* num, uint64_t i, uint64_t j, oarrm5n1_t* arr);
  onumm5n1_t oarrm5n1_get_item_i(    oarrm5n1_t* arr, uint64_t i);
  void      oarrm5n1_get_item_i_to( oarrm5n1_t* arr, uint64_t i,             onumm5n1_t* res);
  onumm5n1_t oarrm5n1_get_item_ij(   oarrm5n1_t* arr, uint64_t i, uint64_t j);
  void      oarrm5n1_get_item_ij_to(oarrm5n1_t* arr, uint64_t i, uint64_t j, onumm5n1_t* res);
  oarrm5n1_t oarrm5n1_init();
  void oarrm5n1_free(oarrm5n1_t* arr);
  oarrm5n1_t oarrm5n1_empty_like(oarrm5n1_t* arr);
  oarrm5n1_t oarrm5n1_eye(uint64_t nrows);
  oarrm5n1_t oarrm5n1_ones(uint64_t nrows, uint64_t ncols);
  oarrm5n1_t oarrm5n1_zeros(uint64_t nrows, uint64_t ncols);
  oarrm5n1_t oarrm5n1_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm5n1/array/utils.h
  
  void oarrm5n1_dimCheck_OO_elementwise(oarrm5n1_t* arr1, oarrm5n1_t* arr2, oarrm5n1_t* res);
  void oarrm5n1_dimCheck_RO_elementwise(darr_t*  arr1, oarrm5n1_t* arr2, oarrm5n1_t* res);
  void oarrm5n1_dimCheck_OO_matmul(oarrm5n1_t* arr1, oarrm5n1_t* arr2, oarrm5n1_t* res);
  void oarrm5n1_dimCheck_RO_matmul(darr_t*  arr1, oarrm5n1_t* arr2, oarrm5n1_t* res);
  void oarrm5n1_dimCheck_OR_matmul(oarrm5n1_t* arr1, darr_t*  arr2, oarrm5n1_t* res);
  void oarrm5n1_dimCheck_O_squareness(oarrm5n1_t* arr1, oarrm5n1_t* res);
  void oarrm5n1_dimCheck_OO_samesize(oarrm5n1_t* arr1, oarrm5n1_t* res);
  void oarrm5n1_dimCheck_RO_samesize(darr_t* arr1, oarrm5n1_t* res);
  ord_t oarrm5n1_get_order(oarrm5n1_t* arr);
  void oarrm5n1_get_active_bases(oarrm5n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n1/array/algebra_matops.h
  
  onumm5n1_t oarrm5n1_dotproduct_OO(    oarrm5n1_t* lhs, oarrm5n1_t* rhs);
  void      oarrm5n1_dotproduct_OO_to( oarrm5n1_t* lhs, oarrm5n1_t* rhs, onumm5n1_t* res);
  onumm5n1_t oarrm5n1_dotproduct_RO(     darr_t* lhs, oarrm5n1_t* rhs);
  void      oarrm5n1_dotproduct_RO_to(  darr_t* lhs, oarrm5n1_t* rhs, onumm5n1_t* res);
  oarrm5n1_t oarrm5n1_matmul_OO(    oarrm5n1_t* lhs, oarrm5n1_t* rhs);
  oarrm5n1_t oarrm5n1_matmul_OR(    oarrm5n1_t* lhs,  darr_t* rhs);
  oarrm5n1_t oarrm5n1_matmul_RO(     darr_t* lhs, oarrm5n1_t* rhs);
  void    oarrm5n1_matmul_OO_to( oarrm5n1_t* lhs, oarrm5n1_t* rhs, oarrm5n1_t* res);
  void    oarrm5n1_matmul_OR_to( oarrm5n1_t* lhs,  darr_t* rhs, oarrm5n1_t* res);
  void    oarrm5n1_matmul_RO_to(  darr_t* lhs, oarrm5n1_t* rhs, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_transpose(    oarrm5n1_t* arr1);
  void    oarrm5n1_transpose_to( oarrm5n1_t* arr1, oarrm5n1_t* res);
  oarrm5n1_t oarrm5n1_invert(    oarrm5n1_t* arr1);
  void    oarrm5n1_invert_to( oarrm5n1_t* arr1, oarrm5n1_t* res);
  onumm5n1_t oarrm5n1_det(    oarrm5n1_t* arr1);
  void      oarrm5n1_det_to( oarrm5n1_t* arr1, onumm5n1_t* res);
  onumm5n1_t oarrm5n1_norm(    oarrm5n1_t* arr1);
  void      oarrm5n1_norm_to( oarrm5n1_t* arr1,  onumm5n1_t* res);
  onumm5n1_t oarrm5n1_pnorm(    oarrm5n1_t* arr1, coeff_t p);
  void      oarrm5n1_pnorm_to( oarrm5n1_t* arr1, coeff_t p, onumm5n1_t* res);
  
  
  # From ../../../include/oti/static/onumm5n1/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm5n1/array/gauss/functions.h
  
  feoarrm5n1_t feoarrm5n1_atanh(    feoarrm5n1_t* arr);
  void      feoarrm5n1_atanh_to( feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_asinh(    feoarrm5n1_t* arr);
  void      feoarrm5n1_asinh_to( feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_acosh(    feoarrm5n1_t* arr);
  void      feoarrm5n1_acosh_to( feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_tanh(     feoarrm5n1_t* arr);
  void      feoarrm5n1_tanh_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sinh(     feoarrm5n1_t* arr);
  void      feoarrm5n1_sinh_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_cosh(     feoarrm5n1_t* arr);
  void      feoarrm5n1_cosh_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_atan(     feoarrm5n1_t* arr);
  void      feoarrm5n1_atan_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_asin(     feoarrm5n1_t* arr);
  void      feoarrm5n1_asin_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_acos(     feoarrm5n1_t* arr);
  void      feoarrm5n1_acos_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_tan(      feoarrm5n1_t* arr);
  void      feoarrm5n1_tan_to(   feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sin(      feoarrm5n1_t* arr);
  void      feoarrm5n1_sin_to(   feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_cos(      feoarrm5n1_t* arr);
  void      feoarrm5n1_cos_to(   feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_logb(     feoarrm5n1_t* arr, double base);
  void      feoarrm5n1_logb_to(  feoarrm5n1_t* arr, double base, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_log10(    feoarrm5n1_t* arr);
  void      feoarrm5n1_log10_to( feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_log(      feoarrm5n1_t* arr);
  void      feoarrm5n1_log_to(   feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_exp(      feoarrm5n1_t* arr);
  void      feoarrm5n1_exp_to(   feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_cbrt(     feoarrm5n1_t* arr);
  void      feoarrm5n1_cbrt_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sqrt(     feoarrm5n1_t* arr);
  void      feoarrm5n1_sqrt_to(  feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_pow(      feoarrm5n1_t* arr, double e);
  void      feoarrm5n1_pow_to(   feoarrm5n1_t* arr, double e, feoarrm5n1_t* res);
  
  
  # From ../../../include/oti/static/onumm5n1/array/gauss/base.h
  
  void      feoarrm5n1_get_order_im_to( ord_t order, feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_get_order_im(    ord_t order, feoarrm5n1_t* arr);
  feoarrm5n1_t feoarrm5n1_get_deriv(   imdir_t idx, ord_t order, feoarrm5n1_t* arr);
  void      feoarrm5n1_get_deriv_to(imdir_t idx, ord_t order, feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_get_im(      imdir_t idx, ord_t order, feoarrm5n1_t* arr);
  void      feoarrm5n1_get_im_to(   imdir_t idx, ord_t order, feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_truncate_im(   imdir_t idx, ord_t order, feoarrm5n1_t* arr);
  void      feoarrm5n1_truncate_im_to(imdir_t idx, ord_t order, feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_copy(   feoarrm5n1_t* src);
  void      feoarrm5n1_copy_to(feoarrm5n1_t* src, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_get_im(    imdir_t idx, ord_t order, feoarrm5n1_t* arr);
  void      feoarrm5n1_get_im_to( imdir_t idx, ord_t order, feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_get_deriv(    imdir_t idx, ord_t order, feoarrm5n1_t* arr);
  void      feoarrm5n1_get_deriv_to( imdir_t idx, ord_t order, feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_extract_im(    imdir_t idx, ord_t order, feoarrm5n1_t* arr);
  void      feoarrm5n1_extract_im_to( imdir_t idx, ord_t order, feoarrm5n1_t* arr,  feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_extract_deriv(    imdir_t idx, ord_t order, feoarrm5n1_t* arr);
  void      feoarrm5n1_extract_deriv_to( imdir_t idx, ord_t order, feoarrm5n1_t* arr, feoarrm5n1_t* res);
  oarrm5n1_t   feoarrm5n1_get_item_k(  feoarrm5n1_t* arr, uint64_t k);
  feonumm5n1_t  feoarrm5n1_get_item_ij( feoarrm5n1_t* arr, uint64_t i, uint64_t j);
  onumm5n1_t feoarrm5n1_get_item_ijk(feoarrm5n1_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm5n1_get_item_ij_to(  feoarrm5n1_t* arr, uint64_t i, uint64_t j,
                                 feonumm5n1_t* res);
  void feoarrm5n1_get_item_k_to(   feoarrm5n1_t* arr, uint64_t k,
                                  oarrm5n1_t* res);
  void feoarrm5n1_get_item_ijk_to( feoarrm5n1_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_get_slice(feoarrm5n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm5n1_get_slice_to(feoarrm5n1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n1_t* res);
  void feoarrm5n1_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm5n1_t* res);
  void feoarrm5n1_set_item_ij_o(  onumm5n1_t* elm, uint64_t i, uint64_t j,
                               feoarrm5n1_t* res);
  void feoarrm5n1_set_item_ij_f(  feonumm5n1_t* elm, uint64_t i, uint64_t j,
                              feoarrm5n1_t* res);
  void feoarrm5n1_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm5n1_t* res);
  void feoarrm5n1_set_item_k_o(  onumm5n1_t* elm, uint64_t k,
                              feoarrm5n1_t* res);
  void feoarrm5n1_set_item_k_R(    oarrm5n1_t* elm, uint64_t k,
                            feoarrm5n1_t* res);
  void feoarrm5n1_set_item_k_O(    oarrm5n1_t* elm, uint64_t k,
                            feoarrm5n1_t* res);
  void feoarrm5n1_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm5n1_t* res);
  void feoarrm5n1_set_item_ijk_o( onumm5n1_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm5n1_t* res);
  void feoarrm5n1_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n1_t* res);
  void feoarrm5n1_set_slice_o( onumm5n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n1_t* res);
  void feoarrm5n1_set_slice_f( feonumm5n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n1_t* res);
  void feoarrm5n1_set_slice_O( oarrm5n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n1_t* res);
  void feoarrm5n1_set_slice_F( feoarrm5n1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n1_t* res);
  void feoarrm5n1_set_all_o( onumm5n1_t* num, feoarrm5n1_t* arr );
  void feoarrm5n1_set_all_r(   coeff_t  num, feoarrm5n1_t* arr );
  void feoarrm5n1_set_all_f(  feonumm5n1_t* num, feoarrm5n1_t* arr );
  void feoarrm5n1_set_r(    coeff_t src, feoarrm5n1_t* res );
  void feoarrm5n1_set_o( onumm5n1_t* src, feoarrm5n1_t* res );
  void feoarrm5n1_set_f(  feonumm5n1_t* src, feoarrm5n1_t* res );
  void feoarrm5n1_set_R(    darr_t* src, feoarrm5n1_t* res );
  void feoarrm5n1_set_O(   oarrm5n1_t* src, feoarrm5n1_t* res );
  void feoarrm5n1_set_F( feoarrm5n1_t* src, feoarrm5n1_t* res );
  feoarrm5n1_t feoarrm5n1_eye( uint64_t size,  uint64_t nip);
  feoarrm5n1_t feoarrm5n1_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm5n1_t feoarrm5n1_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm5n1_t feoarrm5n1_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm5n1_free(feoarrm5n1_t* arr);
  feoarrm5n1_t feoarrm5n1_init();
  ord_t feoarrm5n1_get_order(feoarrm5n1_t* arr);
  
  
  # From ../../../include/oti/static/onumm5n1/array/gauss/utils.h
  
  void feoarrm5n1_dimCheck_FF_samesize(feoarrm5n1_t* arr1, feoarrm5n1_t* arr2, feonumm5n1_t* res);
  void feoarrm5n1_dimCheck_OF_samesize(  oarrm5n1_t* arr1, feoarrm5n1_t* arr2, feonumm5n1_t* res);
  void feoarrm5n1_dimCheck_RF_samesize(   darr_t* arr1, feoarrm5n1_t* arr2, feonumm5n1_t* res);
  void feoarrm5n1_dimCheck_FF_elementwise(feoarrm5n1_t* arr1, feoarrm5n1_t* arr2, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_OF_elementwise(  oarrm5n1_t* arr1, feoarrm5n1_t* arr2, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm5n1_t* arr2, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_fF_elementwise( feonumm5n1_t* num1, feoarrm5n1_t* arr2, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_Ff_elementwise(feoarrm5n1_t* arr1,  feonumm5n1_t* num2, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_FF_matmul( feoarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_OF_matmul(   oarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_FO_matmul( feoarrm5n1_t* lhs,   oarrm5n1_t* rhs, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_FR_matmul( feoarrm5n1_t* lhs,    darr_t* rhs, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_F_squareness( feoarrm5n1_t* arr1, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_F_transpose( feoarrm5n1_t* arr1, feoarrm5n1_t* res);
  void feoarrm5n1_dimCheck_FfO_integrate(feoarrm5n1_t* arr, feonumm5n1_t* num,oarrm5n1_t* res);
  void feoarrm5n1_get_active_bases(feoarrm5n1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n1/array/gauss/algebra.h
  
  feoarrm5n1_t feoarrm5n1_neg(    feoarrm5n1_t* arr);
  void      feoarrm5n1_neg_to( feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sum_FF(   feoarrm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sum_FF_to(feoarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sum_fF(    feonumm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sum_fF_to( feonumm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sum_OF(     oarrm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sum_OF_to(  oarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sum_RF(      darr_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sum_RF_to(   darr_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sum_oF(   onumm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sum_oF_to(onumm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sum_rF(     coeff_t  lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sum_rF_to(  coeff_t  lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sub_FF(    feoarrm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sub_FF_to( feoarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sub_fF(    feonumm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sub_fF_to( feonumm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sub_Ff(    feoarrm5n1_t* lhs, feonumm5n1_t* rhs);
  void      feoarrm5n1_sub_Ff_to( feoarrm5n1_t* lhs, feonumm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sub_OF(      oarrm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sub_OF_to(   oarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sub_FO(    feoarrm5n1_t* lhs,   oarrm5n1_t* rhs);
  void      feoarrm5n1_sub_FO_to( feoarrm5n1_t* lhs,   oarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sub_RF(       darr_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sub_RF_to(    darr_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sub_FR(    feoarrm5n1_t* lhs,    darr_t* rhs);
  void      feoarrm5n1_sub_FR_to( feoarrm5n1_t* lhs,    darr_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sub_oF(    onumm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sub_oF_to( onumm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sub_Fo(    feoarrm5n1_t* lhs, onumm5n1_t* rhs);
  void      feoarrm5n1_sub_Fo_to( feoarrm5n1_t* lhs, onumm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sub_rF(      coeff_t  lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_sub_rF_to(    coeff_t lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_sub_Fr(    feoarrm5n1_t* lhs,   coeff_t  rhs);
  void      feoarrm5n1_sub_Fr_to( feoarrm5n1_t* lhs,   coeff_t  rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_mul_FF(   feoarrm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_mul_FF_to(feoarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_mul_fF(    feonumm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_mul_fF_to( feonumm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_mul_OF(     oarrm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_mul_OF_to(  oarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_mul_RF(      darr_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_mul_RF_to(   darr_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_mul_oF(   onumm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_mul_oF_to(onumm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_mul_rF(     coeff_t  lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_mul_rF_to(  coeff_t  lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_div_FF(    feoarrm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_div_FF_to( feoarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_div_fF(     feonumm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_div_fF_to(  feonumm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_div_Ff(    feoarrm5n1_t* lhs,  feonumm5n1_t* rhs);
  void      feoarrm5n1_div_Ff_to( feoarrm5n1_t* lhs,  feonumm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_div_OF(      oarrm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_div_OF_to(   oarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_div_FO(    feoarrm5n1_t* lhs,   oarrm5n1_t* rhs);
  void      feoarrm5n1_div_FO_to( feoarrm5n1_t* lhs,   oarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_div_RF(       darr_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_div_RF_to(    darr_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_div_FR(    feoarrm5n1_t* lhs,    darr_t* rhs);
  void      feoarrm5n1_div_FR_to( feoarrm5n1_t* lhs,    darr_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_div_oF(    onumm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_div_oF_to( onumm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_div_Fo(    feoarrm5n1_t* lhs, onumm5n1_t* rhs);
  void      feoarrm5n1_div_Fo_to( feoarrm5n1_t* lhs, onumm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_div_rF(      coeff_t  lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_div_rF_to(    coeff_t lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_div_Fr(    feoarrm5n1_t* lhs,   coeff_t  rhs);
  void      feoarrm5n1_div_Fr_to( feoarrm5n1_t* lhs,   coeff_t  rhs, feoarrm5n1_t* res);
  oarrm5n1_t feoarrm5n1_integrate(    feoarrm5n1_t* arr, feonumm5n1_t* w);
  void    feoarrm5n1_integrate_to( feoarrm5n1_t* arr, feonumm5n1_t* w, oarrm5n1_t* res);
  feonumm5n1_t feoarrm5n1_dotproduct_FF(    feoarrm5n1_t* lhs, feoarrm5n1_t* rhs);
  void     feoarrm5n1_dotproduct_FF_to( feoarrm5n1_t* lhs, feoarrm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feoarrm5n1_dotproduct_OF(      oarrm5n1_t* lhs, feoarrm5n1_t* rhs);
  void     feoarrm5n1_dotproduct_OF_to(   oarrm5n1_t* lhs, feoarrm5n1_t* rhs, feonumm5n1_t* res);
  feonumm5n1_t feoarrm5n1_dotproduct_RF(       darr_t* lhs, feoarrm5n1_t* rhs);
  void     feoarrm5n1_dotproduct_RF_to(    darr_t* lhs, feoarrm5n1_t* rhs, feonumm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_matmul_FF(    feoarrm5n1_t* lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_matmul_FF_to( feoarrm5n1_t* lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_matmul_OF(    oarrm5n1_t*   lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_matmul_OF_to( oarrm5n1_t*   lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_matmul_FO(    feoarrm5n1_t* lhs, oarrm5n1_t*   rhs);
  void      feoarrm5n1_matmul_FO_to( feoarrm5n1_t* lhs, oarrm5n1_t*   rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_matmul_RF(    darr_t*    lhs, feoarrm5n1_t* rhs);
  void      feoarrm5n1_matmul_RF_to( darr_t*    lhs, feoarrm5n1_t* rhs, feoarrm5n1_t* res);
  feoarrm5n1_t feoarrm5n1_matmul_FR(    feoarrm5n1_t* lhs, darr_t*    rhs);
  void      feoarrm5n1_matmul_FR_to( feoarrm5n1_t* lhs, darr_t*    rhs, feoarrm5n1_t* res);
  feonumm5n1_t feoarrm5n1_det(   feoarrm5n1_t* arr);
  void     feoarrm5n1_det_to(feoarrm5n1_t* arr, feonumm5n1_t* res);
  feonumm5n1_t feoarrm5n1_norm(     feoarrm5n1_t* arr);
  void     feoarrm5n1_norm_to(  feoarrm5n1_t* arr, feonumm5n1_t* res);
  feonumm5n1_t feoarrm5n1_pnorm(    feoarrm5n1_t* arr, coeff_t p);
  void     feoarrm5n1_pnorm_to( feoarrm5n1_t* arr, coeff_t p, feonumm5n1_t* res);
  feoarrm5n1_t   feoarrm5n1_invert(    feoarrm5n1_t* arr);
  void        feoarrm5n1_invert_to( feoarrm5n1_t* arr, feoarrm5n1_t* res);
  feoarrm5n1_t   feoarrm5n1_transpose(   feoarrm5n1_t* arr);
  void        feoarrm5n1_transpose_to(feoarrm5n1_t* arr, feoarrm5n1_t* res);
  
  