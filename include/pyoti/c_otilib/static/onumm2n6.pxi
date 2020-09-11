cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm2n6/scalar/structures.h
  
  ctypedef struct  onumm2n6_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e11;
    coeff_t e12;
    coeff_t e22;
    coeff_t e111;
    coeff_t e112;
    coeff_t e122;
    coeff_t e222;
    coeff_t e1111;
    coeff_t e1112;
    coeff_t e1122;
    coeff_t e1222;
    coeff_t e2222;
    coeff_t e11111;
    coeff_t e11112;
    coeff_t e11122;
    coeff_t e11222;
    coeff_t e12222;
    coeff_t e22222;
    coeff_t e111111;
    coeff_t e111112;
    coeff_t e111122;
    coeff_t e111222;
    coeff_t e112222;
    coeff_t e122222;
    coeff_t e222222;
  # } onumm2n6_t;
  
  
  # From ../../../include/oti/static/onumm2n6/array/structures.h
  
  ctypedef struct  oarrm2n6_t : # {
      onumm2n6_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm2n6_t;
  
  
  # From ../../../include/oti/static/onumm2n6/scalar/gauss/structures.h
  
  ctypedef struct  feonumm2n6_t: # {
      onumm2n6_t*  p_data;
      uint64_t    nip;
  # } feonumm2n6_t;
  
  
  # From ../../../include/oti/static/onumm2n6/array/gauss/structures.h
  
  ctypedef struct  feoarrm2n6_t: # {
      oarrm2n6_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm2n6_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm2n6/scalar/functions.h
  
  onumm2n6_t onumm2n6_atanh(onumm2n6_t* num);
  void onumm2n6_atanh_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_asinh(onumm2n6_t* num);
  void onumm2n6_asinh_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_acosh(onumm2n6_t* num);
  void onumm2n6_acosh_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_tanh(onumm2n6_t* num);
  void onumm2n6_tanh_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_sqrt(onumm2n6_t* num);
  void onumm2n6_sqrt_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_cbrt(onumm2n6_t* num);
  void onumm2n6_cbrt_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_cosh(onumm2n6_t* num);
  void onumm2n6_cosh_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_sinh(onumm2n6_t* num);
  void onumm2n6_sinh_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_asin(onumm2n6_t* num);
  void onumm2n6_asin_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_acos(onumm2n6_t* num);
  void onumm2n6_acos_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_atan(onumm2n6_t* num);
  void onumm2n6_atan_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_tan(onumm2n6_t* num);
  void onumm2n6_tan_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_cos(onumm2n6_t* num);
  void onumm2n6_cos_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_sin(onumm2n6_t* num );
  void onumm2n6_sin_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_logb(onumm2n6_t* num, double base);
  void onumm2n6_logb_to(onumm2n6_t* num, double base, onumm2n6_t* res);
  onumm2n6_t onumm2n6_log10(onumm2n6_t* num);
  void onumm2n6_log10_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_log(onumm2n6_t* num);
  void onumm2n6_log_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_exp(onumm2n6_t* num);
  void onumm2n6_exp_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_pow(onumm2n6_t* num, double e);
  void onumm2n6_pow_to(onumm2n6_t* num, coeff_t e, onumm2n6_t* res);
  
  
  # From ../../../include/oti/static/onumm2n6/scalar/base.h
  
  void onumm2n6_set_im_o(onumm2n6_t* num, imdir_t idx, ord_t order, onumm2n6_t* res);
  void onumm2n6_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm2n6_t* res);
  void onumm2n6_set_deriv_o(onumm2n6_t* num, imdir_t idx, ord_t order, onumm2n6_t* res);
  void onumm2n6_extract_im_to( imdir_t idx, ord_t order, onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_extract_im(imdir_t idx, ord_t order, onumm2n6_t* num);
  onumm2n6_t onumm2n6_extract_deriv(imdir_t idx, ord_t order, onumm2n6_t* num);
  void onumm2n6_extract_deriv_to(imdir_t idx, ord_t order, onumm2n6_t* num, onumm2n6_t* res);
  void onumm2n6_get_im_to_o(imdir_t idx, ord_t order, onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_get_im_o(imdir_t idx, ord_t order, onumm2n6_t* num);
  void onumm2n6_get_im_to_r(imdir_t idx, ord_t order, onumm2n6_t* num, coeff_t* res);
  ord_t onumm2n6_get_order(onumm2n6_t* lhs);
  onumm2n6_t onumm2n6_get_deriv_o( imdir_t idx, ord_t order, onumm2n6_t* num);
  void onumm2n6_get_deriv_to( imdir_t idx, ord_t order, onumm2n6_t* num, onumm2n6_t* res);
  void onumm2n6_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm2n6_t* res);
  onumm2n6_t onumm2n6_init();
  ndir_t onumm2n6_get_ndir_order(ord_t order, onumm2n6_t* num);
  ndir_t onumm2n6_get_ndir_total(onumm2n6_t* num);
  coeff_t* onumm2n6_get_order_address(ord_t order, onumm2n6_t* num);
  onumm2n6_t onumm2n6_create_r(  coeff_t lhs);
  void onumm2n6_set_r(  coeff_t lhs, onumm2n6_t* res);
  void onumm2n6_set_o(  onumm2n6_t* lhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_get_order_im(ord_t order, onumm2n6_t* lhs);
  void onumm2n6_get_order_im_to(ord_t order, onumm2n6_t* lhs, onumm2n6_t* res);
  coeff_t onumm2n6_get_item(imdir_t idx, ord_t order, onumm2n6_t* lhs);
  coeff_t onumm2n6_get_deriv(imdir_t idx, ord_t order, onumm2n6_t* lhs);
  void onumm2n6_set_item(coeff_t val, imdir_t idx, ord_t order, onumm2n6_t* x);
  onumm2n6_t onumm2n6_copy(  onumm2n6_t* lhs);
  void onumm2n6_copy_to(  onumm2n6_t* lhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_taylor_integrate(coeff_t* deltas,onumm2n6_t* lhs);
  void onumm2n6_taylor_integrate_to(coeff_t* deltas,onumm2n6_t* lhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_truncate_im(imdir_t idx, ord_t order, onumm2n6_t* lhs);
  void onumm2n6_truncate_im_to(imdir_t idx, ord_t order, onumm2n6_t* lhs, onumm2n6_t* res);
  void onumm2n6_print(  onumm2n6_t* lhs);
  imdir_t onumm2n6_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm2n6/scalar/utils.h
  
  void onumm2n6_get_active_bases(onumm2n6_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm2n6/scalar/algebra.h
  
  onumm2n6_t onumm2n6_abs(onumm2n6_t* num);
  onumm2n6_t onumm2n6_div_ro(coeff_t num, onumm2n6_t* den);
  onumm2n6_t onumm2n6_div_oo(onumm2n6_t* num, onumm2n6_t* den);
  onumm2n6_t onumm2n6_div_or(onumm2n6_t* num, coeff_t val);
  void onumm2n6_div_ro_to(coeff_t num, onumm2n6_t* den, onumm2n6_t* res);
  void onumm2n6_div_oo_to(onumm2n6_t* num, onumm2n6_t* den, onumm2n6_t* res);
  void onumm2n6_div_or_to(onumm2n6_t* num, coeff_t val, onumm2n6_t* res);
  void onumm2n6_abs_to(onumm2n6_t* num, onumm2n6_t* res);
  onumm2n6_t onumm2n6_neg(  onumm2n6_t* lhs);
  void onumm2n6_neg_to(  onumm2n6_t* lhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_sum_oo(  onumm2n6_t* lhs,  onumm2n6_t* rhs);
  void onumm2n6_sum_oo_to(  onumm2n6_t* lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_sum_ro(  coeff_t lhs,  onumm2n6_t* rhs);
  void onumm2n6_sum_ro_to(  coeff_t lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_sub_oo(  onumm2n6_t* lhs,  onumm2n6_t* rhs);
  void onumm2n6_sub_oo_to(  onumm2n6_t* lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_sub_ro(  coeff_t lhs,  onumm2n6_t* rhs);
  void onumm2n6_sub_ro_to(  coeff_t lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_sub_or(  onumm2n6_t* lhs,  coeff_t rhs);
  void onumm2n6_sub_or_to(  onumm2n6_t* lhs,  coeff_t rhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_mul_oo(  onumm2n6_t* lhs,  onumm2n6_t* rhs);
  void onumm2n6_mul_oo_to(  onumm2n6_t* lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_mul_ro(  coeff_t lhs,  onumm2n6_t* rhs);
  void onumm2n6_mul_ro_to(  coeff_t lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_trunc_mul_oo(  onumm2n6_t* lhs,  onumm2n6_t* rhs);
  void onumm2n6_trunc_mul_oo_to(  onumm2n6_t* lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_gem_oo(  onumm2n6_t* a,  onumm2n6_t* b,  onumm2n6_t* c);
  void onumm2n6_gem_oo_to(  onumm2n6_t* a,  onumm2n6_t* b,  onumm2n6_t* c, onumm2n6_t* res);
  onumm2n6_t onumm2n6_gem_ro(  coeff_t a,  onumm2n6_t* b,  onumm2n6_t* c);
  void onumm2n6_gem_ro_to(  coeff_t a,  onumm2n6_t* b,  onumm2n6_t* c, onumm2n6_t* res);
  void onumm2n6_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n6_t* a,  ord_t ord_rhs,  onumm2n6_t* b,  onumm2n6_t* c, onumm2n6_t* res);
  void onumm2n6_trunc_sum_oo_to(ord_t order, onumm2n6_t* lhs,onumm2n6_t* rhs, onumm2n6_t* res);
  void onumm2n6_trunc_sub_oo_to(ord_t order, onumm2n6_t* lhs,onumm2n6_t* rhs, onumm2n6_t* res);
  onumm2n6_t onumm2n6_feval(coeff_t* feval_re, onumm2n6_t* x);
  void onumm2n6_feval_to(coeff_t* feval_re, onumm2n6_t* x, onumm2n6_t* res);
  
  
  # From ../../../include/oti/static/onumm2n6/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm2n6/scalar/gauss/functions.h
  
  feonumm2n6_t feonumm2n6_atanh(    feonumm2n6_t* num);
  void     feonumm2n6_atanh_to( feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_asinh(    feonumm2n6_t* num);
  void     feonumm2n6_asinh_to( feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_acosh(    feonumm2n6_t* num);
  void     feonumm2n6_acosh_to( feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_tanh(     feonumm2n6_t* num);
  void     feonumm2n6_tanh_to(  feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_cosh(     feonumm2n6_t* num);
  void     feonumm2n6_cosh_to(  feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_sinh(     feonumm2n6_t* num);
  void     feonumm2n6_sinh_to(  feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_asin(     feonumm2n6_t* num);
  void     feonumm2n6_asin_to(  feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_acos(     feonumm2n6_t* num);
  void     feonumm2n6_acos_to(  feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_atan(     feonumm2n6_t* num);
  void     feonumm2n6_atan_to(  feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_tan(      feonumm2n6_t* num);
  void     feonumm2n6_tan_to(   feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_cos(      feonumm2n6_t* num);
  void     feonumm2n6_cos_to(   feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_sin(      feonumm2n6_t* num);
  void     feonumm2n6_sin_to(   feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_logb(     feonumm2n6_t* num, double base);
  void     feonumm2n6_logb_to(  feonumm2n6_t* num, double base, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_log10(    feonumm2n6_t* num);
  void     feonumm2n6_log10_to( feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_log(      feonumm2n6_t* num);
  void     feonumm2n6_log_to(   feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_exp(      feonumm2n6_t* num);
  void     feonumm2n6_exp_to(   feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_cbrt(     feonumm2n6_t* num);
  void     feonumm2n6_cbrt_to(  feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_sqrt(     feonumm2n6_t* num);
  void     feonumm2n6_sqrt_to(  feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_pow(      feonumm2n6_t* num, double e);
  void     feonumm2n6_pow_to(   feonumm2n6_t* num, double e, feonumm2n6_t* res);
  onumm2n6_t feonumm2n6_integrate(       feonumm2n6_t* num, feonumm2n6_t* w);
  void      feonumm2n6_integrate_to(    feonumm2n6_t* num, feonumm2n6_t* w, onumm2n6_t* res);
  onumm2n6_t feonumm2n6_integrate_f(     feonumm2n6_t* num, feonumm2n6_t* w);
  void      feonumm2n6_integrate_f_to(  feonumm2n6_t* num, feonumm2n6_t* w, onumm2n6_t* res);
  onumm2n6_t feonumm2n6_integrate_r(       coeff_t num, feonumm2n6_t* w);
  void      feonumm2n6_integrate_r_to(    coeff_t num, feonumm2n6_t* w, onumm2n6_t* res);
  onumm2n6_t feonumm2n6_integrate_o(    onumm2n6_t* num, feonumm2n6_t* w);
  void      feonumm2n6_integrate_o_to( onumm2n6_t* num, feonumm2n6_t* w, onumm2n6_t* res);
  
  
  # From ../../../include/oti/static/onumm2n6/scalar/gauss/base.h
  
  void     feonumm2n6_get_order_im_to( ord_t order, feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_get_order_im(    ord_t order, feonumm2n6_t* num);
  feonumm2n6_t feonumm2n6_get_im(    imdir_t idx, ord_t order, feonumm2n6_t* num);
  void     feonumm2n6_get_im_to( imdir_t idx, ord_t order, feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_get_deriv(    imdir_t idx, ord_t order, feonumm2n6_t* num);
  void     feonumm2n6_get_deriv_to( imdir_t idx, ord_t order, feonumm2n6_t* num, feonumm2n6_t* res);
  void feonumm2n6_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm2n6_t* num);
  void feonumm2n6_set_im_o( onumm2n6_t* val, imdir_t idx, ord_t order, feonumm2n6_t* num);
  void feonumm2n6_set_im_f(  feonumm2n6_t* val, imdir_t idx, ord_t order, feonumm2n6_t* num);
  void feonumm2n6_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm2n6_t* num);
  void feonumm2n6_set_deriv_o( onumm2n6_t* val, imdir_t idx, ord_t order, feonumm2n6_t* num);
  void feonumm2n6_set_deriv_f(  feonumm2n6_t* val, imdir_t idx, ord_t order, feonumm2n6_t* num);
  feonumm2n6_t feonumm2n6_extract_im(    imdir_t idx, ord_t order, feonumm2n6_t* num);
  void     feonumm2n6_extract_im_to( imdir_t idx, ord_t order, feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_extract_deriv(    imdir_t idx, ord_t order, feonumm2n6_t* num);
  void     feonumm2n6_extract_deriv_to( imdir_t idx, ord_t order, feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_truncate_im(    imdir_t idx, ord_t order, feonumm2n6_t* num);
  void     feonumm2n6_truncate_im_to( imdir_t idx, ord_t order, feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_copy(    feonumm2n6_t* src);
  void     feonumm2n6_copy_to( feonumm2n6_t* src, feonumm2n6_t* dst);
  void feonumm2n6_set_r(    coeff_t num, feonumm2n6_t* res);
  void feonumm2n6_set_o( onumm2n6_t* num, feonumm2n6_t* res);
  void feonumm2n6_set_f(  feonumm2n6_t* num, feonumm2n6_t* res);
  void feonumm2n6_set_item_k_r(   coeff_t  num, uint64_t k, feonumm2n6_t* res);
  void feonumm2n6_set_item_k_o( onumm2n6_t* num, uint64_t k, feonumm2n6_t* res);
  onumm2n6_t feonumm2n6_get_item_k(   feonumm2n6_t* num, uint64_t k);
  void      feonumm2n6_get_item_k_to(feonumm2n6_t* num, uint64_t k, onumm2n6_t* res);
  feonumm2n6_t feonumm2n6_zeros(uint64_t nIntPts);
  feonumm2n6_t feonumm2n6_createEmpty(uint64_t nIntPts);
  feonumm2n6_t feonumm2n6_empty_like(feonumm2n6_t* arr);
  void feonumm2n6_free(feonumm2n6_t* num);
  ord_t feonumm2n6_get_order( feonumm2n6_t* num );
  feonumm2n6_t feonumm2n6_init();
  
  
  # From ../../../include/oti/static/onumm2n6/scalar/gauss/utils.h
  
  void feonumm2n6_dimCheck(feonumm2n6_t* arr1,feonumm2n6_t* arr2);
  void feonumm2n6_get_active_bases(feonumm2n6_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm2n6/scalar/gauss/algebra.h
  
  feonumm2n6_t feonumm2n6_neg(   feonumm2n6_t* num);
  void     feonumm2n6_neg_to(feonumm2n6_t* num, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_sum_ff(   feonumm2n6_t* lhs, feonumm2n6_t* rhs);
  void     feonumm2n6_sum_ff_to(feonumm2n6_t* lhs, feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_sum_of(   onumm2n6_t* lhs, feonumm2n6_t* rhs);
  void     feonumm2n6_sum_of_to(onumm2n6_t* lhs, feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_sum_rf(   coeff_t lhs, feonumm2n6_t* rhs);
  void     feonumm2n6_sum_rf_to(coeff_t lhs, feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_sub_ff(     feonumm2n6_t* lhs,  feonumm2n6_t* rhs);
  void     feonumm2n6_sub_ff_to(  feonumm2n6_t* lhs,  feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_sub_of(    onumm2n6_t* lhs,  feonumm2n6_t* rhs);
  void     feonumm2n6_sub_of_to( onumm2n6_t* lhs,  feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_sub_fo(     feonumm2n6_t* lhs, onumm2n6_t* rhs);
  void     feonumm2n6_sub_fo_to(  feonumm2n6_t* lhs, onumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_sub_rf(       coeff_t lhs,  feonumm2n6_t* rhs);
  void     feonumm2n6_sub_rf_to(    coeff_t lhs,  feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_sub_fr(     feonumm2n6_t* lhs,    coeff_t rhs);
  void     feonumm2n6_sub_fr_to(  feonumm2n6_t* lhs,    coeff_t rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_mul_ff(   feonumm2n6_t* lhs, feonumm2n6_t* rhs);
  void     feonumm2n6_mul_ff_to(feonumm2n6_t* lhs, feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_mul_of(   onumm2n6_t* lhs, feonumm2n6_t* rhs);
  void     feonumm2n6_mul_of_to(onumm2n6_t* lhs, feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_mul_rf(   coeff_t lhs, feonumm2n6_t* rhs);
  void     feonumm2n6_mul_rf_to(coeff_t lhs, feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_div_ff(     feonumm2n6_t* lhs,  feonumm2n6_t* rhs);
  void     feonumm2n6_div_ff_to(  feonumm2n6_t* lhs,  feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_div_of(    onumm2n6_t* lhs,  feonumm2n6_t* rhs);
  void     feonumm2n6_div_of_to( onumm2n6_t* lhs,  feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_div_fo(     feonumm2n6_t* lhs, onumm2n6_t* rhs);
  void     feonumm2n6_div_fo_to(  feonumm2n6_t* lhs, onumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_div_rf(       coeff_t lhs,  feonumm2n6_t* rhs);
  void     feonumm2n6_div_rf_to(    coeff_t lhs,  feonumm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feonumm2n6_div_fr(     feonumm2n6_t* lhs,    coeff_t rhs);
  void     feonumm2n6_div_fr_to(  feonumm2n6_t* lhs,    coeff_t rhs, feonumm2n6_t* res);
  
  
  # From ../../../include/oti/static/onumm2n6/array/functions.h
  
  oarrm2n6_t oarrm2n6_atanh(   oarrm2n6_t* arr);
  void    oarrm2n6_atanh_to(oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_asinh(   oarrm2n6_t* arr);
  void    oarrm2n6_asinh_to(oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_acosh(   oarrm2n6_t* arr);
  void    oarrm2n6_acosh_to(oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_tanh(    oarrm2n6_t* arr);
  void    oarrm2n6_tanh_to( oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_cbrt(    oarrm2n6_t* arr);
  void    oarrm2n6_cbrt_to( oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_sqrt(    oarrm2n6_t* arr);
  void    oarrm2n6_sqrt_to( oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_cosh(    oarrm2n6_t* arr);
  void    oarrm2n6_cosh_to( oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_sinh(    oarrm2n6_t* arr);
  void    oarrm2n6_sinh_to( oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_asin(    oarrm2n6_t* arr);
  void    oarrm2n6_asin_to( oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_acos(    oarrm2n6_t* arr);
  void    oarrm2n6_acos_to( oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_atan(    oarrm2n6_t* arr);
  void    oarrm2n6_atan_to( oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_tan(     oarrm2n6_t* arr);
  void    oarrm2n6_tan_to(  oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_cos(     oarrm2n6_t* arr);
  void    oarrm2n6_cos_to(  oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_sin(     oarrm2n6_t* arr);
  void    oarrm2n6_sin_to(  oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_logb(    oarrm2n6_t* arr, double base);
  void    oarrm2n6_logb_to( oarrm2n6_t* arr, double base, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_log10(   oarrm2n6_t* arr);
  void    oarrm2n6_log10_to(oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_log(     oarrm2n6_t* arr);
  void    oarrm2n6_log_to(  oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_exp(     oarrm2n6_t* arr);
  void    oarrm2n6_exp_to(  oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_pow(     oarrm2n6_t* arr, double e);
  void    oarrm2n6_pow_to(  oarrm2n6_t* arr, double e, oarrm2n6_t* res);
  
  
  # From ../../../include/oti/static/onumm2n6/array/algebra_elementwise.h
  
  oarrm2n6_t oarrm2n6_neg(oarrm2n6_t* arr);
  void oarrm2n6_neg_to(oarrm2n6_t* rhs, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_sum_OO(oarrm2n6_t*   lhs, oarrm2n6_t* rhs);
  oarrm2n6_t oarrm2n6_sum_RO(darr_t*    lhs, oarrm2n6_t* rhs);
  oarrm2n6_t oarrm2n6_sum_oO(onumm2n6_t* lhs, oarrm2n6_t* rhs);
  oarrm2n6_t oarrm2n6_sum_rO(coeff_t    lhs, oarrm2n6_t* rhs);
  void oarrm2n6_sum_OO_to(oarrm2n6_t*   lhs, oarrm2n6_t* rhs, oarrm2n6_t* res);
  void oarrm2n6_sum_RO_to(darr_t*    lhs, oarrm2n6_t* rhs, oarrm2n6_t* res);
  void oarrm2n6_sum_oO_to(onumm2n6_t* lhs, oarrm2n6_t* rhs, oarrm2n6_t* res);
  void oarrm2n6_sum_rO_to(coeff_t    lhs, oarrm2n6_t* rhs, oarrm2n6_t* res);
  void oarrm2n6_trunc_sum_OO_to(ord_t order, oarrm2n6_t* arr1, oarrm2n6_t* arr2, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_sub_OO(oarrm2n6_t*   lhs, oarrm2n6_t*   rhs);
  oarrm2n6_t oarrm2n6_sub_RO(darr_t*    lhs, oarrm2n6_t*   rhs);
  oarrm2n6_t oarrm2n6_sub_OR(oarrm2n6_t*   lhs, darr_t*    rhs);
  oarrm2n6_t oarrm2n6_sub_oO(onumm2n6_t* lhs, oarrm2n6_t*   rhs);
  oarrm2n6_t oarrm2n6_sub_Oo(oarrm2n6_t*   lhs, onumm2n6_t* rhs);
  oarrm2n6_t oarrm2n6_sub_rO(coeff_t    lhs, oarrm2n6_t*   rhs);
  oarrm2n6_t oarrm2n6_sub_Or(oarrm2n6_t*   lhs, coeff_t    rhs);
  void oarrm2n6_sub_OO_to( oarrm2n6_t*   lhs, oarrm2n6_t*   rhs, oarrm2n6_t* res);
  void oarrm2n6_sub_RO_to( darr_t*    lhs, oarrm2n6_t*   rhs, oarrm2n6_t* res);
  void oarrm2n6_sub_OR_to( oarrm2n6_t*   lhs, darr_t*    rhs, oarrm2n6_t* res);
  void oarrm2n6_sub_oO_to( onumm2n6_t* lhs, oarrm2n6_t*   rhs, oarrm2n6_t* res);
  void oarrm2n6_sub_Oo_to( oarrm2n6_t*   lhs, onumm2n6_t* rhs, oarrm2n6_t* res);
  void oarrm2n6_sub_rO_to( coeff_t    lhs, oarrm2n6_t*   rhs, oarrm2n6_t* res);
  void oarrm2n6_sub_Or_to( oarrm2n6_t*   lhs, coeff_t    rhs, oarrm2n6_t* res);
  void oarrm2n6_trunc_sub_OO_to(ord_t order, oarrm2n6_t* arr1, oarrm2n6_t* arr2, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_mul_OO(oarrm2n6_t*   lhs, oarrm2n6_t* rhs);
  oarrm2n6_t oarrm2n6_mul_RO(darr_t*    lhs, oarrm2n6_t* rhs);
  oarrm2n6_t oarrm2n6_mul_oO(onumm2n6_t* lhs, oarrm2n6_t* rhs);
  oarrm2n6_t oarrm2n6_mul_rO(coeff_t    lhs, oarrm2n6_t* rhs);
  void oarrm2n6_mul_OO_to(oarrm2n6_t*   lhs, oarrm2n6_t* rhs, oarrm2n6_t* res);
  void oarrm2n6_mul_RO_to(darr_t*    lhs, oarrm2n6_t* rhs, oarrm2n6_t* res);
  void oarrm2n6_mul_oO_to(onumm2n6_t* lhs, oarrm2n6_t* rhs, oarrm2n6_t* res);
  void oarrm2n6_mul_rO_to(coeff_t    lhs, oarrm2n6_t* rhs, oarrm2n6_t* res);
  void oarrm2n6_gem_OO_to(  oarrm2n6_t* arr1, oarrm2n6_t* arr2, oarrm2n6_t* arr3, oarrm2n6_t* res);
  void oarrm2n6_gem_oO_to(onumm2n6_t* arr1, oarrm2n6_t* arr2, oarrm2n6_t* arr3, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_div_OO(oarrm2n6_t*   lhs, oarrm2n6_t*   rhs);
  oarrm2n6_t oarrm2n6_div_OR(oarrm2n6_t*   lhs, darr_t*    rhs);
  oarrm2n6_t oarrm2n6_div_RO(darr_t*    lhs, oarrm2n6_t*   rhs);
  oarrm2n6_t oarrm2n6_div_oO(onumm2n6_t* lhs, oarrm2n6_t*   rhs);
  oarrm2n6_t oarrm2n6_div_Oo(oarrm2n6_t*   lhs, onumm2n6_t* rhs);
  oarrm2n6_t oarrm2n6_div_rO(coeff_t    lhs, oarrm2n6_t*   rhs);
  oarrm2n6_t oarrm2n6_div_Or(oarrm2n6_t*   lhs, coeff_t    rhs);
  void oarrm2n6_div_OO_to(oarrm2n6_t*   lhs, oarrm2n6_t*   rhs, oarrm2n6_t* res);
  void oarrm2n6_div_RO_to(darr_t*    lhs, oarrm2n6_t*   rhs, oarrm2n6_t* res);
  void oarrm2n6_div_OR_to(oarrm2n6_t*   lhs, darr_t*    rhs, oarrm2n6_t* res);
  void oarrm2n6_div_oO_to(onumm2n6_t* lhs, oarrm2n6_t*   rhs, oarrm2n6_t* res);
  void oarrm2n6_div_Oo_to(oarrm2n6_t*   lhs, onumm2n6_t* rhs, oarrm2n6_t* res);
  void oarrm2n6_div_rO_to(coeff_t    lhs, oarrm2n6_t*   rhs, oarrm2n6_t* res);
  void oarrm2n6_div_Or_to(oarrm2n6_t*   lhs, coeff_t    rhs, oarrm2n6_t* res);
  
  
  # From ../../../include/oti/static/onumm2n6/array/base.h
  
  void    oarrm2n6_taylor_integrate_to( coeff_t* deltas, oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_taylor_integrate(    coeff_t* deltas, oarrm2n6_t* arr);
  void    oarrm2n6_get_order_im_to( ord_t order, oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_get_order_im(    ord_t order, oarrm2n6_t* arr);
  void oarrm2n6_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n6_t* res);
  void oarrm2n6_set_slice_O( oarrm2n6_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n6_t* res);
  void oarrm2n6_set_slice_o( onumm2n6_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_get_slice( oarrm2n6_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm2n6_get_slice_to( oarrm2n6_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_truncate_im(    imdir_t idx, ord_t order, oarrm2n6_t* arr);
  void    oarrm2n6_truncate_im_to( imdir_t idx, ord_t order, oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_extract_im(   imdir_t idx, ord_t order, oarrm2n6_t* arr);
  void    oarrm2n6_extract_im_to(imdir_t idx, ord_t order, oarrm2n6_t* arr, oarrm2n6_t* res);
  darr_t  oarrm2n6_get_deriv(    imdir_t idx, ord_t order, oarrm2n6_t* arr);
  void    oarrm2n6_get_deriv_to( imdir_t idx, ord_t order, oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_get_deriv_o(  imdir_t idx, ord_t order, oarrm2n6_t* arr);
  oarrm2n6_t oarrm2n6_extract_deriv(    imdir_t idx, ord_t order, oarrm2n6_t* arr);
  void    oarrm2n6_extract_deriv_to( imdir_t idx, ord_t order, oarrm2n6_t* arr, oarrm2n6_t* res);
  darr_t  oarrm2n6_get_im(   imdir_t idx, ord_t order, oarrm2n6_t* arr);
  oarrm2n6_t oarrm2n6_get_im_o( imdir_t idx, ord_t order, oarrm2n6_t* arr);
  void    oarrm2n6_get_im_to(imdir_t idx, ord_t order, oarrm2n6_t* arr, oarrm2n6_t* res);
  void    oarrm2n6_copy_to(oarrm2n6_t* arr, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_copy(oarrm2n6_t* arr);
  void oarrm2n6_set_all_r( coeff_t num, oarrm2n6_t* arr);
  void oarrm2n6_set_item_i_r( coeff_t num, uint64_t i, oarrm2n6_t* arr);
  void oarrm2n6_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm2n6_t* arr);
  void oarrm2n6_set_r(   coeff_t  num,   oarrm2n6_t* arr);
  void oarrm2n6_set_o( onumm2n6_t* num,   oarrm2n6_t* arr);
  void oarrm2n6_set_O(   oarrm2n6_t* arrin, oarrm2n6_t* arr);
  void oarrm2n6_set_all_o( onumm2n6_t* src, oarrm2n6_t* arr);
  void oarrm2n6_set_item_i_o( onumm2n6_t* num, uint64_t i, oarrm2n6_t* arr);
  void oarrm2n6_set_item_ij_o( onumm2n6_t* num, uint64_t i, uint64_t j, oarrm2n6_t* arr);
  onumm2n6_t oarrm2n6_get_item_i(    oarrm2n6_t* arr, uint64_t i);
  void      oarrm2n6_get_item_i_to( oarrm2n6_t* arr, uint64_t i,             onumm2n6_t* res);
  onumm2n6_t oarrm2n6_get_item_ij(   oarrm2n6_t* arr, uint64_t i, uint64_t j);
  void      oarrm2n6_get_item_ij_to(oarrm2n6_t* arr, uint64_t i, uint64_t j, onumm2n6_t* res);
  oarrm2n6_t oarrm2n6_init();
  void oarrm2n6_free(oarrm2n6_t* arr);
  oarrm2n6_t oarrm2n6_empty_like(oarrm2n6_t* arr);
  oarrm2n6_t oarrm2n6_eye(uint64_t nrows);
  oarrm2n6_t oarrm2n6_ones(uint64_t nrows, uint64_t ncols);
  oarrm2n6_t oarrm2n6_zeros(uint64_t nrows, uint64_t ncols);
  oarrm2n6_t oarrm2n6_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm2n6/array/utils.h
  
  void oarrm2n6_dimCheck_OO_elementwise(oarrm2n6_t* arr1, oarrm2n6_t* arr2, oarrm2n6_t* res);
  void oarrm2n6_dimCheck_RO_elementwise(darr_t*  arr1, oarrm2n6_t* arr2, oarrm2n6_t* res);
  void oarrm2n6_dimCheck_OO_matmul(oarrm2n6_t* arr1, oarrm2n6_t* arr2, oarrm2n6_t* res);
  void oarrm2n6_dimCheck_RO_matmul(darr_t*  arr1, oarrm2n6_t* arr2, oarrm2n6_t* res);
  void oarrm2n6_dimCheck_OR_matmul(oarrm2n6_t* arr1, darr_t*  arr2, oarrm2n6_t* res);
  void oarrm2n6_dimCheck_O_squareness(oarrm2n6_t* arr1, oarrm2n6_t* res);
  void oarrm2n6_dimCheck_OO_samesize(oarrm2n6_t* arr1, oarrm2n6_t* res);
  void oarrm2n6_dimCheck_RO_samesize(darr_t* arr1, oarrm2n6_t* res);
  ord_t oarrm2n6_get_order(oarrm2n6_t* arr);
  void oarrm2n6_get_active_bases(oarrm2n6_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm2n6/array/algebra_matops.h
  
  onumm2n6_t oarrm2n6_dotproduct_OO(    oarrm2n6_t* lhs, oarrm2n6_t* rhs);
  void      oarrm2n6_dotproduct_OO_to( oarrm2n6_t* lhs, oarrm2n6_t* rhs, onumm2n6_t* res);
  onumm2n6_t oarrm2n6_dotproduct_RO(     darr_t* lhs, oarrm2n6_t* rhs);
  void      oarrm2n6_dotproduct_RO_to(  darr_t* lhs, oarrm2n6_t* rhs, onumm2n6_t* res);
  oarrm2n6_t oarrm2n6_matmul_OO(    oarrm2n6_t* lhs, oarrm2n6_t* rhs);
  oarrm2n6_t oarrm2n6_matmul_OR(    oarrm2n6_t* lhs,  darr_t* rhs);
  oarrm2n6_t oarrm2n6_matmul_RO(     darr_t* lhs, oarrm2n6_t* rhs);
  void    oarrm2n6_matmul_OO_to( oarrm2n6_t* lhs, oarrm2n6_t* rhs, oarrm2n6_t* res);
  void    oarrm2n6_matmul_OR_to( oarrm2n6_t* lhs,  darr_t* rhs, oarrm2n6_t* res);
  void    oarrm2n6_matmul_RO_to(  darr_t* lhs, oarrm2n6_t* rhs, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_transpose(    oarrm2n6_t* arr1);
  void    oarrm2n6_transpose_to( oarrm2n6_t* arr1, oarrm2n6_t* res);
  oarrm2n6_t oarrm2n6_invert(    oarrm2n6_t* arr1);
  void    oarrm2n6_invert_to( oarrm2n6_t* arr1, oarrm2n6_t* res);
  onumm2n6_t oarrm2n6_det(    oarrm2n6_t* arr1);
  void      oarrm2n6_det_to( oarrm2n6_t* arr1, onumm2n6_t* res);
  onumm2n6_t oarrm2n6_norm(    oarrm2n6_t* arr1);
  void      oarrm2n6_norm_to( oarrm2n6_t* arr1,  onumm2n6_t* res);
  onumm2n6_t oarrm2n6_pnorm(    oarrm2n6_t* arr1, coeff_t p);
  void      oarrm2n6_pnorm_to( oarrm2n6_t* arr1, coeff_t p, onumm2n6_t* res);
  
  
  # From ../../../include/oti/static/onumm2n6/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm2n6/array/gauss/functions.h
  
  feoarrm2n6_t feoarrm2n6_atanh(    feoarrm2n6_t* arr);
  void      feoarrm2n6_atanh_to( feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_asinh(    feoarrm2n6_t* arr);
  void      feoarrm2n6_asinh_to( feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_acosh(    feoarrm2n6_t* arr);
  void      feoarrm2n6_acosh_to( feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_tanh(     feoarrm2n6_t* arr);
  void      feoarrm2n6_tanh_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sinh(     feoarrm2n6_t* arr);
  void      feoarrm2n6_sinh_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_cosh(     feoarrm2n6_t* arr);
  void      feoarrm2n6_cosh_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_atan(     feoarrm2n6_t* arr);
  void      feoarrm2n6_atan_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_asin(     feoarrm2n6_t* arr);
  void      feoarrm2n6_asin_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_acos(     feoarrm2n6_t* arr);
  void      feoarrm2n6_acos_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_tan(      feoarrm2n6_t* arr);
  void      feoarrm2n6_tan_to(   feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sin(      feoarrm2n6_t* arr);
  void      feoarrm2n6_sin_to(   feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_cos(      feoarrm2n6_t* arr);
  void      feoarrm2n6_cos_to(   feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_logb(     feoarrm2n6_t* arr, double base);
  void      feoarrm2n6_logb_to(  feoarrm2n6_t* arr, double base, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_log10(    feoarrm2n6_t* arr);
  void      feoarrm2n6_log10_to( feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_log(      feoarrm2n6_t* arr);
  void      feoarrm2n6_log_to(   feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_exp(      feoarrm2n6_t* arr);
  void      feoarrm2n6_exp_to(   feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_cbrt(     feoarrm2n6_t* arr);
  void      feoarrm2n6_cbrt_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sqrt(     feoarrm2n6_t* arr);
  void      feoarrm2n6_sqrt_to(  feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_pow(      feoarrm2n6_t* arr, double e);
  void      feoarrm2n6_pow_to(   feoarrm2n6_t* arr, double e, feoarrm2n6_t* res);
  
  
  # From ../../../include/oti/static/onumm2n6/array/gauss/base.h
  
  void      feoarrm2n6_get_order_im_to( ord_t order, feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_get_order_im(    ord_t order, feoarrm2n6_t* arr);
  feoarrm2n6_t feoarrm2n6_get_deriv(   imdir_t idx, ord_t order, feoarrm2n6_t* arr);
  void      feoarrm2n6_get_deriv_to(imdir_t idx, ord_t order, feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_get_im(      imdir_t idx, ord_t order, feoarrm2n6_t* arr);
  void      feoarrm2n6_get_im_to(   imdir_t idx, ord_t order, feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_truncate_im(   imdir_t idx, ord_t order, feoarrm2n6_t* arr);
  void      feoarrm2n6_truncate_im_to(imdir_t idx, ord_t order, feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_copy(   feoarrm2n6_t* src);
  void      feoarrm2n6_copy_to(feoarrm2n6_t* src, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_get_im(    imdir_t idx, ord_t order, feoarrm2n6_t* arr);
  void      feoarrm2n6_get_im_to( imdir_t idx, ord_t order, feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_get_deriv(    imdir_t idx, ord_t order, feoarrm2n6_t* arr);
  void      feoarrm2n6_get_deriv_to( imdir_t idx, ord_t order, feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_extract_im(    imdir_t idx, ord_t order, feoarrm2n6_t* arr);
  void      feoarrm2n6_extract_im_to( imdir_t idx, ord_t order, feoarrm2n6_t* arr,  feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_extract_deriv(    imdir_t idx, ord_t order, feoarrm2n6_t* arr);
  void      feoarrm2n6_extract_deriv_to( imdir_t idx, ord_t order, feoarrm2n6_t* arr, feoarrm2n6_t* res);
  oarrm2n6_t   feoarrm2n6_get_item_k(  feoarrm2n6_t* arr, uint64_t k);
  feonumm2n6_t  feoarrm2n6_get_item_ij( feoarrm2n6_t* arr, uint64_t i, uint64_t j);
  onumm2n6_t feoarrm2n6_get_item_ijk(feoarrm2n6_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm2n6_get_item_ij_to(  feoarrm2n6_t* arr, uint64_t i, uint64_t j,
                                 feonumm2n6_t* res);
  void feoarrm2n6_get_item_k_to(   feoarrm2n6_t* arr, uint64_t k,
                                  oarrm2n6_t* res);
  void feoarrm2n6_get_item_ijk_to( feoarrm2n6_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_get_slice(feoarrm2n6_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm2n6_get_slice_to(feoarrm2n6_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n6_t* res);
  void feoarrm2n6_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm2n6_t* res);
  void feoarrm2n6_set_item_ij_o(  onumm2n6_t* elm, uint64_t i, uint64_t j,
                               feoarrm2n6_t* res);
  void feoarrm2n6_set_item_ij_f(  feonumm2n6_t* elm, uint64_t i, uint64_t j,
                              feoarrm2n6_t* res);
  void feoarrm2n6_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm2n6_t* res);
  void feoarrm2n6_set_item_k_o(  onumm2n6_t* elm, uint64_t k,
                              feoarrm2n6_t* res);
  void feoarrm2n6_set_item_k_R(    oarrm2n6_t* elm, uint64_t k,
                            feoarrm2n6_t* res);
  void feoarrm2n6_set_item_k_O(    oarrm2n6_t* elm, uint64_t k,
                            feoarrm2n6_t* res);
  void feoarrm2n6_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm2n6_t* res);
  void feoarrm2n6_set_item_ijk_o( onumm2n6_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm2n6_t* res);
  void feoarrm2n6_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n6_t* res);
  void feoarrm2n6_set_slice_o( onumm2n6_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n6_t* res);
  void feoarrm2n6_set_slice_f( feonumm2n6_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n6_t* res);
  void feoarrm2n6_set_slice_O( oarrm2n6_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n6_t* res);
  void feoarrm2n6_set_slice_F( feoarrm2n6_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n6_t* res);
  void feoarrm2n6_set_all_o( onumm2n6_t* num, feoarrm2n6_t* arr );
  void feoarrm2n6_set_all_r(   coeff_t  num, feoarrm2n6_t* arr );
  void feoarrm2n6_set_all_f(  feonumm2n6_t* num, feoarrm2n6_t* arr );
  void feoarrm2n6_set_r(    coeff_t src, feoarrm2n6_t* res );
  void feoarrm2n6_set_o( onumm2n6_t* src, feoarrm2n6_t* res );
  void feoarrm2n6_set_f(  feonumm2n6_t* src, feoarrm2n6_t* res );
  void feoarrm2n6_set_R(    darr_t* src, feoarrm2n6_t* res );
  void feoarrm2n6_set_O(   oarrm2n6_t* src, feoarrm2n6_t* res );
  void feoarrm2n6_set_F( feoarrm2n6_t* src, feoarrm2n6_t* res );
  feoarrm2n6_t feoarrm2n6_eye( uint64_t size,  uint64_t nip);
  feoarrm2n6_t feoarrm2n6_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm2n6_t feoarrm2n6_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm2n6_t feoarrm2n6_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm2n6_free(feoarrm2n6_t* arr);
  feoarrm2n6_t feoarrm2n6_init();
  ord_t feoarrm2n6_get_order(feoarrm2n6_t* arr);
  
  
  # From ../../../include/oti/static/onumm2n6/array/gauss/utils.h
  
  void feoarrm2n6_dimCheck_FF_samesize(feoarrm2n6_t* arr1, feoarrm2n6_t* arr2, feonumm2n6_t* res);
  void feoarrm2n6_dimCheck_OF_samesize(  oarrm2n6_t* arr1, feoarrm2n6_t* arr2, feonumm2n6_t* res);
  void feoarrm2n6_dimCheck_RF_samesize(   darr_t* arr1, feoarrm2n6_t* arr2, feonumm2n6_t* res);
  void feoarrm2n6_dimCheck_FF_elementwise(feoarrm2n6_t* arr1, feoarrm2n6_t* arr2, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_OF_elementwise(  oarrm2n6_t* arr1, feoarrm2n6_t* arr2, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm2n6_t* arr2, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_fF_elementwise( feonumm2n6_t* num1, feoarrm2n6_t* arr2, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_Ff_elementwise(feoarrm2n6_t* arr1,  feonumm2n6_t* num2, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_FF_matmul( feoarrm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_OF_matmul(   oarrm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_RF_matmul(    darr_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_FO_matmul( feoarrm2n6_t* lhs,   oarrm2n6_t* rhs, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_FR_matmul( feoarrm2n6_t* lhs,    darr_t* rhs, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_F_squareness( feoarrm2n6_t* arr1, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_F_transpose( feoarrm2n6_t* arr1, feoarrm2n6_t* res);
  void feoarrm2n6_dimCheck_FfO_integrate(feoarrm2n6_t* arr, feonumm2n6_t* num,oarrm2n6_t* res);
  void feoarrm2n6_get_active_bases(feoarrm2n6_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm2n6/array/gauss/algebra.h
  
  feoarrm2n6_t feoarrm2n6_neg(    feoarrm2n6_t* arr);
  void      feoarrm2n6_neg_to( feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sum_FF(   feoarrm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sum_FF_to(feoarrm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sum_fF(    feonumm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sum_fF_to( feonumm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sum_OF(     oarrm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sum_OF_to(  oarrm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sum_RF(      darr_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sum_RF_to(   darr_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sum_oF(   onumm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sum_oF_to(onumm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sum_rF(     coeff_t  lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sum_rF_to(  coeff_t  lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sub_FF(    feoarrm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sub_FF_to( feoarrm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sub_fF(    feonumm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sub_fF_to( feonumm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sub_Ff(    feoarrm2n6_t* lhs, feonumm2n6_t* rhs);
  void      feoarrm2n6_sub_Ff_to( feoarrm2n6_t* lhs, feonumm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sub_OF(      oarrm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sub_OF_to(   oarrm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sub_FO(    feoarrm2n6_t* lhs,   oarrm2n6_t* rhs);
  void      feoarrm2n6_sub_FO_to( feoarrm2n6_t* lhs,   oarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sub_RF(       darr_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sub_RF_to(    darr_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sub_FR(    feoarrm2n6_t* lhs,    darr_t* rhs);
  void      feoarrm2n6_sub_FR_to( feoarrm2n6_t* lhs,    darr_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sub_oF(    onumm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sub_oF_to( onumm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sub_Fo(    feoarrm2n6_t* lhs, onumm2n6_t* rhs);
  void      feoarrm2n6_sub_Fo_to( feoarrm2n6_t* lhs, onumm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sub_rF(      coeff_t  lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_sub_rF_to(    coeff_t lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_sub_Fr(    feoarrm2n6_t* lhs,   coeff_t  rhs);
  void      feoarrm2n6_sub_Fr_to( feoarrm2n6_t* lhs,   coeff_t  rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_mul_FF(   feoarrm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_mul_FF_to(feoarrm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_mul_fF(    feonumm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_mul_fF_to( feonumm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_mul_OF(     oarrm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_mul_OF_to(  oarrm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_mul_RF(      darr_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_mul_RF_to(   darr_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_mul_oF(   onumm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_mul_oF_to(onumm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_mul_rF(     coeff_t  lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_mul_rF_to(  coeff_t  lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_div_FF(    feoarrm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_div_FF_to( feoarrm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_div_fF(     feonumm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_div_fF_to(  feonumm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_div_Ff(    feoarrm2n6_t* lhs,  feonumm2n6_t* rhs);
  void      feoarrm2n6_div_Ff_to( feoarrm2n6_t* lhs,  feonumm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_div_OF(      oarrm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_div_OF_to(   oarrm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_div_FO(    feoarrm2n6_t* lhs,   oarrm2n6_t* rhs);
  void      feoarrm2n6_div_FO_to( feoarrm2n6_t* lhs,   oarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_div_RF(       darr_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_div_RF_to(    darr_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_div_FR(    feoarrm2n6_t* lhs,    darr_t* rhs);
  void      feoarrm2n6_div_FR_to( feoarrm2n6_t* lhs,    darr_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_div_oF(    onumm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_div_oF_to( onumm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_div_Fo(    feoarrm2n6_t* lhs, onumm2n6_t* rhs);
  void      feoarrm2n6_div_Fo_to( feoarrm2n6_t* lhs, onumm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_div_rF(      coeff_t  lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_div_rF_to(    coeff_t lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_div_Fr(    feoarrm2n6_t* lhs,   coeff_t  rhs);
  void      feoarrm2n6_div_Fr_to( feoarrm2n6_t* lhs,   coeff_t  rhs, feoarrm2n6_t* res);
  oarrm2n6_t feoarrm2n6_integrate(    feoarrm2n6_t* arr, feonumm2n6_t* w);
  void    feoarrm2n6_integrate_to( feoarrm2n6_t* arr, feonumm2n6_t* w, oarrm2n6_t* res);
  feonumm2n6_t feoarrm2n6_dotproduct_FF(    feoarrm2n6_t* lhs, feoarrm2n6_t* rhs);
  void     feoarrm2n6_dotproduct_FF_to( feoarrm2n6_t* lhs, feoarrm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feoarrm2n6_dotproduct_OF(      oarrm2n6_t* lhs, feoarrm2n6_t* rhs);
  void     feoarrm2n6_dotproduct_OF_to(   oarrm2n6_t* lhs, feoarrm2n6_t* rhs, feonumm2n6_t* res);
  feonumm2n6_t feoarrm2n6_dotproduct_RF(       darr_t* lhs, feoarrm2n6_t* rhs);
  void     feoarrm2n6_dotproduct_RF_to(    darr_t* lhs, feoarrm2n6_t* rhs, feonumm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_matmul_FF(    feoarrm2n6_t* lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_matmul_FF_to( feoarrm2n6_t* lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_matmul_OF(    oarrm2n6_t*   lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_matmul_OF_to( oarrm2n6_t*   lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_matmul_FO(    feoarrm2n6_t* lhs, oarrm2n6_t*   rhs);
  void      feoarrm2n6_matmul_FO_to( feoarrm2n6_t* lhs, oarrm2n6_t*   rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_matmul_RF(    darr_t*    lhs, feoarrm2n6_t* rhs);
  void      feoarrm2n6_matmul_RF_to( darr_t*    lhs, feoarrm2n6_t* rhs, feoarrm2n6_t* res);
  feoarrm2n6_t feoarrm2n6_matmul_FR(    feoarrm2n6_t* lhs, darr_t*    rhs);
  void      feoarrm2n6_matmul_FR_to( feoarrm2n6_t* lhs, darr_t*    rhs, feoarrm2n6_t* res);
  feonumm2n6_t feoarrm2n6_det(   feoarrm2n6_t* arr);
  void     feoarrm2n6_det_to(feoarrm2n6_t* arr, feonumm2n6_t* res);
  feonumm2n6_t feoarrm2n6_norm(     feoarrm2n6_t* arr);
  void     feoarrm2n6_norm_to(  feoarrm2n6_t* arr, feonumm2n6_t* res);
  feonumm2n6_t feoarrm2n6_pnorm(    feoarrm2n6_t* arr, coeff_t p);
  void     feoarrm2n6_pnorm_to( feoarrm2n6_t* arr, coeff_t p, feonumm2n6_t* res);
  feoarrm2n6_t   feoarrm2n6_invert(    feoarrm2n6_t* arr);
  void        feoarrm2n6_invert_to( feoarrm2n6_t* arr, feoarrm2n6_t* res);
  feoarrm2n6_t   feoarrm2n6_transpose(   feoarrm2n6_t* arr);
  void        feoarrm2n6_transpose_to(feoarrm2n6_t* arr, feoarrm2n6_t* res);
  
  