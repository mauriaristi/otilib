cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm2n7/scalar/structures.h
  
  ctypedef struct  onumm2n7_t : # {
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
    coeff_t e1111111;
    coeff_t e1111112;
    coeff_t e1111122;
    coeff_t e1111222;
    coeff_t e1112222;
    coeff_t e1122222;
    coeff_t e1222222;
    coeff_t e2222222;
  # } onumm2n7_t;
  
  
  # From ../../../include/oti/static/onumm2n7/array/structures.h
  
  ctypedef struct  oarrm2n7_t : # {
      onumm2n7_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
      flag_t          flag;
  # } oarrm2n7_t;
  
  
  # From ../../../include/oti/static/onumm2n7/scalar/gauss/structures.h
  
  ctypedef struct  feonumm2n7_t: # {
      onumm2n7_t*  p_data;
      uint64_t    nip;
  # } feonumm2n7_t;
  
  
  # From ../../../include/oti/static/onumm2n7/array/gauss/structures.h
  
  ctypedef struct  feoarrm2n7_t: # {
      oarrm2n7_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm2n7_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm2n7/scalar/functions.h
  
  onumm2n7_t onumm2n7_atanh(onumm2n7_t* num);
  void onumm2n7_atanh_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_asinh(onumm2n7_t* num);
  void onumm2n7_asinh_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_acosh(onumm2n7_t* num);
  void onumm2n7_acosh_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_tanh(onumm2n7_t* num);
  void onumm2n7_tanh_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_sqrt(onumm2n7_t* num);
  void onumm2n7_sqrt_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_cbrt(onumm2n7_t* num);
  void onumm2n7_cbrt_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_cosh(onumm2n7_t* num);
  void onumm2n7_cosh_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_sinh(onumm2n7_t* num);
  void onumm2n7_sinh_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_asin(onumm2n7_t* num);
  void onumm2n7_asin_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_acos(onumm2n7_t* num);
  void onumm2n7_acos_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_atan(onumm2n7_t* num);
  void onumm2n7_atan_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_tan(onumm2n7_t* num);
  void onumm2n7_tan_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_cos(onumm2n7_t* num);
  void onumm2n7_cos_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_sin(onumm2n7_t* num );
  void onumm2n7_sin_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_logb(onumm2n7_t* num, double base);
  void onumm2n7_logb_to(onumm2n7_t* num, double base, onumm2n7_t* res);
  onumm2n7_t onumm2n7_log10(onumm2n7_t* num);
  void onumm2n7_log10_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_log(onumm2n7_t* num);
  void onumm2n7_log_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_exp(onumm2n7_t* num);
  void onumm2n7_exp_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_pow(onumm2n7_t* num, double e);
  void onumm2n7_pow_to(onumm2n7_t* num, coeff_t e, onumm2n7_t* res);
  
  
  # From ../../../include/oti/static/onumm2n7/scalar/base.h
  
  void onumm2n7_set_im_o(onumm2n7_t* num, imdir_t idx, ord_t order, onumm2n7_t* res);
  void onumm2n7_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm2n7_t* res);
  void onumm2n7_set_deriv_o(onumm2n7_t* num, imdir_t idx, ord_t order, onumm2n7_t* res);
  void onumm2n7_extract_im_to( imdir_t idx, ord_t order, onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_extract_im(imdir_t idx, ord_t order, onumm2n7_t* num);
  onumm2n7_t onumm2n7_extract_deriv(imdir_t idx, ord_t order, onumm2n7_t* num);
  void onumm2n7_extract_deriv_to(imdir_t idx, ord_t order, onumm2n7_t* num, onumm2n7_t* res);
  void onumm2n7_get_im_to_o(imdir_t idx, ord_t order, onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_get_im_o(imdir_t idx, ord_t order, onumm2n7_t* num);
  void onumm2n7_get_im_to_r(imdir_t idx, ord_t order, onumm2n7_t* num, coeff_t* res);
  ord_t onumm2n7_get_order(onumm2n7_t* lhs);
  onumm2n7_t onumm2n7_get_deriv_o( imdir_t idx, ord_t order, onumm2n7_t* num);
  void onumm2n7_get_deriv_to( imdir_t idx, ord_t order, onumm2n7_t* num, onumm2n7_t* res);
  void onumm2n7_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm2n7_t* res);
  onumm2n7_t onumm2n7_init();
  ndir_t onumm2n7_get_ndir_order(ord_t order, onumm2n7_t* num);
  ndir_t onumm2n7_get_ndir_total(onumm2n7_t* num);
  coeff_t* onumm2n7_get_order_address(ord_t order, onumm2n7_t* num);
  onumm2n7_t onumm2n7_create_r(  coeff_t lhs);
  void onumm2n7_set_r(  coeff_t lhs, onumm2n7_t* res);
  void onumm2n7_set_o(  onumm2n7_t* lhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_get_order_im(ord_t order, onumm2n7_t* lhs);
  void onumm2n7_get_order_im_to(ord_t order, onumm2n7_t* lhs, onumm2n7_t* res);
  coeff_t onumm2n7_get_item(imdir_t idx, ord_t order, onumm2n7_t* lhs);
  coeff_t onumm2n7_get_deriv(imdir_t idx, ord_t order, onumm2n7_t* lhs);
  void onumm2n7_set_item(coeff_t val, imdir_t idx, ord_t order, onumm2n7_t* x);
  onumm2n7_t onumm2n7_copy(  onumm2n7_t* lhs);
  void onumm2n7_copy_to(  onumm2n7_t* lhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_taylor_integrate(coeff_t* deltas,onumm2n7_t* lhs);
  void onumm2n7_taylor_integrate_to(coeff_t* deltas,onumm2n7_t* lhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_truncate_im(imdir_t idx, ord_t order, onumm2n7_t* lhs);
  void onumm2n7_truncate_im_to(imdir_t idx, ord_t order, onumm2n7_t* lhs, onumm2n7_t* res);
  void onumm2n7_print(  onumm2n7_t* lhs);
  imdir_t onumm2n7_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm2n7/scalar/utils.h
  
  void onumm2n7_get_active_bases(onumm2n7_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm2n7/scalar/algebra.h
  
  onumm2n7_t onumm2n7_abs(onumm2n7_t* num);
  onumm2n7_t onumm2n7_div_ro(coeff_t num, onumm2n7_t* den);
  onumm2n7_t onumm2n7_div_oo(onumm2n7_t* num, onumm2n7_t* den);
  onumm2n7_t onumm2n7_div_or(onumm2n7_t* num, coeff_t val);
  void onumm2n7_div_ro_to(coeff_t num, onumm2n7_t* den, onumm2n7_t* res);
  void onumm2n7_div_oo_to(onumm2n7_t* num, onumm2n7_t* den, onumm2n7_t* res);
  void onumm2n7_div_or_to(onumm2n7_t* num, coeff_t val, onumm2n7_t* res);
  void onumm2n7_abs_to(onumm2n7_t* num, onumm2n7_t* res);
  onumm2n7_t onumm2n7_neg(  onumm2n7_t* lhs);
  void onumm2n7_neg_to(  onumm2n7_t* lhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_sum_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs);
  void onumm2n7_sum_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_sum_ro(  coeff_t lhs,  onumm2n7_t* rhs);
  void onumm2n7_sum_ro_to(  coeff_t lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_sub_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs);
  void onumm2n7_sub_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_sub_ro(  coeff_t lhs,  onumm2n7_t* rhs);
  void onumm2n7_sub_ro_to(  coeff_t lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_sub_or(  onumm2n7_t* lhs,  coeff_t rhs);
  void onumm2n7_sub_or_to(  onumm2n7_t* lhs,  coeff_t rhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_mul_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs);
  void onumm2n7_mul_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_mul_ro(  coeff_t lhs,  onumm2n7_t* rhs);
  void onumm2n7_mul_ro_to(  coeff_t lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_trunc_mul_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs);
  void onumm2n7_trunc_mul_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
  onumm2n7_t onumm2n7_gem_oo(  onumm2n7_t* a,  onumm2n7_t* b,  onumm2n7_t* c);
  void onumm2n7_gem_oo_to(  onumm2n7_t* a,  onumm2n7_t* b,  onumm2n7_t* c, onumm2n7_t* res);
  onumm2n7_t onumm2n7_gem_ro(  coeff_t a,  onumm2n7_t* b,  onumm2n7_t* c);
  void onumm2n7_gem_ro_to(  coeff_t a,  onumm2n7_t* b,  onumm2n7_t* c, onumm2n7_t* res);
  void onumm2n7_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n7_t* a,  ord_t ord_rhs,  onumm2n7_t* b,  onumm2n7_t* c, onumm2n7_t* res);
  onumm2n7_t onumm2n7_feval(coeff_t* feval_re, onumm2n7_t* x);
  void onumm2n7_feval_to(coeff_t* feval_re, onumm2n7_t* x, onumm2n7_t* res);
  
  
  # From ../../../include/oti/static/onumm2n7/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm2n7/scalar/gauss/functions.h
  
  feonumm2n7_t feonumm2n7_atanh(    feonumm2n7_t* num);
  void     feonumm2n7_atanh_to( feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_asinh(    feonumm2n7_t* num);
  void     feonumm2n7_asinh_to( feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_acosh(    feonumm2n7_t* num);
  void     feonumm2n7_acosh_to( feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_tanh(     feonumm2n7_t* num);
  void     feonumm2n7_tanh_to(  feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_cosh(     feonumm2n7_t* num);
  void     feonumm2n7_cosh_to(  feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_sinh(     feonumm2n7_t* num);
  void     feonumm2n7_sinh_to(  feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_asin(     feonumm2n7_t* num);
  void     feonumm2n7_asin_to(  feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_acos(     feonumm2n7_t* num);
  void     feonumm2n7_acos_to(  feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_atan(     feonumm2n7_t* num);
  void     feonumm2n7_atan_to(  feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_tan(      feonumm2n7_t* num);
  void     feonumm2n7_tan_to(   feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_cos(      feonumm2n7_t* num);
  void     feonumm2n7_cos_to(   feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_sin(      feonumm2n7_t* num);
  void     feonumm2n7_sin_to(   feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_logb(     feonumm2n7_t* num, double base);
  void     feonumm2n7_logb_to(  feonumm2n7_t* num, double base, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_log10(    feonumm2n7_t* num);
  void     feonumm2n7_log10_to( feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_log(      feonumm2n7_t* num);
  void     feonumm2n7_log_to(   feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_exp(      feonumm2n7_t* num);
  void     feonumm2n7_exp_to(   feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_cbrt(     feonumm2n7_t* num);
  void     feonumm2n7_cbrt_to(  feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_sqrt(     feonumm2n7_t* num);
  void     feonumm2n7_sqrt_to(  feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_pow(      feonumm2n7_t* num, double e);
  void     feonumm2n7_pow_to(   feonumm2n7_t* num, double e, feonumm2n7_t* res);
  onumm2n7_t feonumm2n7_integrate(       feonumm2n7_t* num, feonumm2n7_t* w);
  void      feonumm2n7_integrate_to(    feonumm2n7_t* num, feonumm2n7_t* w, onumm2n7_t* res);
  onumm2n7_t feonumm2n7_integrate_f(     feonumm2n7_t* num, feonumm2n7_t* w);
  void      feonumm2n7_integrate_f_to(  feonumm2n7_t* num, feonumm2n7_t* w, onumm2n7_t* res);
  onumm2n7_t feonumm2n7_integrate_r(       coeff_t num, feonumm2n7_t* w);
  void      feonumm2n7_integrate_r_to(    coeff_t num, feonumm2n7_t* w, onumm2n7_t* res);
  onumm2n7_t feonumm2n7_integrate_o(    onumm2n7_t* num, feonumm2n7_t* w);
  void      feonumm2n7_integrate_o_to( onumm2n7_t* num, feonumm2n7_t* w, onumm2n7_t* res);
  
  
  # From ../../../include/oti/static/onumm2n7/scalar/gauss/base.h
  
  void     feonumm2n7_get_order_im_to( ord_t order, feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_get_order_im(    ord_t order, feonumm2n7_t* num);
  feonumm2n7_t feonumm2n7_get_im(    imdir_t idx, ord_t order, feonumm2n7_t* num);
  void     feonumm2n7_get_im_to( imdir_t idx, ord_t order, feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_get_deriv(    imdir_t idx, ord_t order, feonumm2n7_t* num);
  void     feonumm2n7_get_deriv_to( imdir_t idx, ord_t order, feonumm2n7_t* num, feonumm2n7_t* res);
  void feonumm2n7_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm2n7_t* num);
  void feonumm2n7_set_im_o( onumm2n7_t* val, imdir_t idx, ord_t order, feonumm2n7_t* num);
  void feonumm2n7_set_im_f(  feonumm2n7_t* val, imdir_t idx, ord_t order, feonumm2n7_t* num);
  void feonumm2n7_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm2n7_t* num);
  void feonumm2n7_set_deriv_o( onumm2n7_t* val, imdir_t idx, ord_t order, feonumm2n7_t* num);
  void feonumm2n7_set_deriv_f(  feonumm2n7_t* val, imdir_t idx, ord_t order, feonumm2n7_t* num);
  feonumm2n7_t feonumm2n7_extract_im(    imdir_t idx, ord_t order, feonumm2n7_t* num);
  void     feonumm2n7_extract_im_to( imdir_t idx, ord_t order, feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_extract_deriv(    imdir_t idx, ord_t order, feonumm2n7_t* num);
  void     feonumm2n7_extract_deriv_to( imdir_t idx, ord_t order, feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_truncate_im(    imdir_t idx, ord_t order, feonumm2n7_t* num);
  void     feonumm2n7_truncate_im_to( imdir_t idx, ord_t order, feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_copy(    feonumm2n7_t* src);
  void     feonumm2n7_copy_to( feonumm2n7_t* src, feonumm2n7_t* dst);
  void feonumm2n7_set_r(    coeff_t num, feonumm2n7_t* res);
  void feonumm2n7_set_o( onumm2n7_t* num, feonumm2n7_t* res);
  void feonumm2n7_set_f(  feonumm2n7_t* num, feonumm2n7_t* res);
  void feonumm2n7_set_item_k_r(   coeff_t  num, uint64_t k, feonumm2n7_t* res);
  void feonumm2n7_set_item_k_o( onumm2n7_t* num, uint64_t k, feonumm2n7_t* res);
  onumm2n7_t feonumm2n7_get_item_k(   feonumm2n7_t* num, uint64_t k);
  void      feonumm2n7_get_item_k_to(feonumm2n7_t* num, uint64_t k, onumm2n7_t* res);
  feonumm2n7_t feonumm2n7_zeros(uint64_t nIntPts);
  feonumm2n7_t feonumm2n7_createEmpty(uint64_t nIntPts);
  feonumm2n7_t feonumm2n7_empty_like(feonumm2n7_t* arr);
  void feonumm2n7_free(feonumm2n7_t* num);
  ord_t feonumm2n7_get_order( feonumm2n7_t* num );
  feonumm2n7_t feonumm2n7_init();
  
  
  # From ../../../include/oti/static/onumm2n7/scalar/gauss/utils.h
  
  void feonumm2n7_dimCheck(feonumm2n7_t* arr1,feonumm2n7_t* arr2);
  void feonumm2n7_get_active_bases(feonumm2n7_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm2n7/scalar/gauss/algebra.h
  
  feonumm2n7_t feonumm2n7_neg(   feonumm2n7_t* num);
  void     feonumm2n7_neg_to(feonumm2n7_t* num, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_sum_ff(   feonumm2n7_t* lhs, feonumm2n7_t* rhs);
  void     feonumm2n7_sum_ff_to(feonumm2n7_t* lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_sum_of(   onumm2n7_t* lhs, feonumm2n7_t* rhs);
  void     feonumm2n7_sum_of_to(onumm2n7_t* lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_sum_rf(   coeff_t lhs, feonumm2n7_t* rhs);
  void     feonumm2n7_sum_rf_to(coeff_t lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_sub_ff(     feonumm2n7_t* lhs,  feonumm2n7_t* rhs);
  void     feonumm2n7_sub_ff_to(  feonumm2n7_t* lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_sub_of(    onumm2n7_t* lhs,  feonumm2n7_t* rhs);
  void     feonumm2n7_sub_of_to( onumm2n7_t* lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_sub_fo(     feonumm2n7_t* lhs, onumm2n7_t* rhs);
  void     feonumm2n7_sub_fo_to(  feonumm2n7_t* lhs, onumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_sub_rf(       coeff_t lhs,  feonumm2n7_t* rhs);
  void     feonumm2n7_sub_rf_to(    coeff_t lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_sub_fr(     feonumm2n7_t* lhs,    coeff_t rhs);
  void     feonumm2n7_sub_fr_to(  feonumm2n7_t* lhs,    coeff_t rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_mul_ff(   feonumm2n7_t* lhs, feonumm2n7_t* rhs);
  void     feonumm2n7_mul_ff_to(feonumm2n7_t* lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_mul_of(   onumm2n7_t* lhs, feonumm2n7_t* rhs);
  void     feonumm2n7_mul_of_to(onumm2n7_t* lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_mul_rf(   coeff_t lhs, feonumm2n7_t* rhs);
  void     feonumm2n7_mul_rf_to(coeff_t lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_div_ff(     feonumm2n7_t* lhs,  feonumm2n7_t* rhs);
  void     feonumm2n7_div_ff_to(  feonumm2n7_t* lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_div_of(    onumm2n7_t* lhs,  feonumm2n7_t* rhs);
  void     feonumm2n7_div_of_to( onumm2n7_t* lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_div_fo(     feonumm2n7_t* lhs, onumm2n7_t* rhs);
  void     feonumm2n7_div_fo_to(  feonumm2n7_t* lhs, onumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_div_rf(       coeff_t lhs,  feonumm2n7_t* rhs);
  void     feonumm2n7_div_rf_to(    coeff_t lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feonumm2n7_div_fr(     feonumm2n7_t* lhs,    coeff_t rhs);
  void     feonumm2n7_div_fr_to(  feonumm2n7_t* lhs,    coeff_t rhs, feonumm2n7_t* res);
  
  
  # From ../../../include/oti/static/onumm2n7/array/functions.h
  
  oarrm2n7_t oarrm2n7_atanh(   oarrm2n7_t* arr);
  void    oarrm2n7_atanh_to(oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_asinh(   oarrm2n7_t* arr);
  void    oarrm2n7_asinh_to(oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_acosh(   oarrm2n7_t* arr);
  void    oarrm2n7_acosh_to(oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_tanh(    oarrm2n7_t* arr);
  void    oarrm2n7_tanh_to( oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_cbrt(    oarrm2n7_t* arr);
  void    oarrm2n7_cbrt_to( oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_sqrt(    oarrm2n7_t* arr);
  void    oarrm2n7_sqrt_to( oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_cosh(    oarrm2n7_t* arr);
  void    oarrm2n7_cosh_to( oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_sinh(    oarrm2n7_t* arr);
  void    oarrm2n7_sinh_to( oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_asin(    oarrm2n7_t* arr);
  void    oarrm2n7_asin_to( oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_acos(    oarrm2n7_t* arr);
  void    oarrm2n7_acos_to( oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_atan(    oarrm2n7_t* arr);
  void    oarrm2n7_atan_to( oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_tan(     oarrm2n7_t* arr);
  void    oarrm2n7_tan_to(  oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_cos(     oarrm2n7_t* arr);
  void    oarrm2n7_cos_to(  oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_sin(     oarrm2n7_t* arr);
  void    oarrm2n7_sin_to(  oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_logb(    oarrm2n7_t* arr, double base);
  void    oarrm2n7_logb_to( oarrm2n7_t* arr, double base, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_log10(   oarrm2n7_t* arr);
  void    oarrm2n7_log10_to(oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_log(     oarrm2n7_t* arr);
  void    oarrm2n7_log_to(  oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_exp(     oarrm2n7_t* arr);
  void    oarrm2n7_exp_to(  oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_pow(     oarrm2n7_t* arr, double e);
  void    oarrm2n7_pow_to(  oarrm2n7_t* arr, double e, oarrm2n7_t* res);
  
  
  # From ../../../include/oti/static/onumm2n7/array/algebra_elementwise.h
  
  oarrm2n7_t oarrm2n7_neg(oarrm2n7_t* arr);
  void oarrm2n7_neg_to(oarrm2n7_t* rhs, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_sum_OO(oarrm2n7_t*   lhs, oarrm2n7_t* rhs);
  oarrm2n7_t oarrm2n7_sum_RO(darr_t*    lhs, oarrm2n7_t* rhs);
  oarrm2n7_t oarrm2n7_sum_oO(onumm2n7_t* lhs, oarrm2n7_t* rhs);
  oarrm2n7_t oarrm2n7_sum_rO(coeff_t    lhs, oarrm2n7_t* rhs);
  void oarrm2n7_sum_OO_to(oarrm2n7_t*   lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
  void oarrm2n7_sum_RO_to(darr_t*    lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
  void oarrm2n7_sum_oO_to(onumm2n7_t* lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
  void oarrm2n7_sum_rO_to(coeff_t    lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_sub_OO(oarrm2n7_t*   lhs, oarrm2n7_t*   rhs);
  oarrm2n7_t oarrm2n7_sub_RO(darr_t*    lhs, oarrm2n7_t*   rhs);
  oarrm2n7_t oarrm2n7_sub_OR(oarrm2n7_t*   lhs, darr_t*    rhs);
  oarrm2n7_t oarrm2n7_sub_oO(onumm2n7_t* lhs, oarrm2n7_t*   rhs);
  oarrm2n7_t oarrm2n7_sub_Oo(oarrm2n7_t*   lhs, onumm2n7_t* rhs);
  oarrm2n7_t oarrm2n7_sub_rO(coeff_t    lhs, oarrm2n7_t*   rhs);
  oarrm2n7_t oarrm2n7_sub_Or(oarrm2n7_t*   lhs, coeff_t    rhs);
  void oarrm2n7_sub_OO_to( oarrm2n7_t*   lhs, oarrm2n7_t*   rhs, oarrm2n7_t* res);
  void oarrm2n7_sub_RO_to( darr_t*    lhs, oarrm2n7_t*   rhs, oarrm2n7_t* res);
  void oarrm2n7_sub_OR_to( oarrm2n7_t*   lhs, darr_t*    rhs, oarrm2n7_t* res);
  void oarrm2n7_sub_oO_to( onumm2n7_t* lhs, oarrm2n7_t*   rhs, oarrm2n7_t* res);
  void oarrm2n7_sub_Oo_to( oarrm2n7_t*   lhs, onumm2n7_t* rhs, oarrm2n7_t* res);
  void oarrm2n7_sub_rO_to( coeff_t    lhs, oarrm2n7_t*   rhs, oarrm2n7_t* res);
  void oarrm2n7_sub_Or_to( oarrm2n7_t*   lhs, coeff_t    rhs, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_mul_OO(oarrm2n7_t*   lhs, oarrm2n7_t* rhs);
  oarrm2n7_t oarrm2n7_mul_RO(darr_t*    lhs, oarrm2n7_t* rhs);
  oarrm2n7_t oarrm2n7_mul_oO(onumm2n7_t* lhs, oarrm2n7_t* rhs);
  oarrm2n7_t oarrm2n7_mul_rO(coeff_t    lhs, oarrm2n7_t* rhs);
  void oarrm2n7_mul_OO_to(oarrm2n7_t*   lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
  void oarrm2n7_mul_RO_to(darr_t*    lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
  void oarrm2n7_mul_oO_to(onumm2n7_t* lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
  void oarrm2n7_mul_rO_to(coeff_t    lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
  void oarrm2n7_gem_OO_to(  oarrm2n7_t* arr1, oarrm2n7_t* arr2, oarrm2n7_t* arr3, oarrm2n7_t* res);
  void oarrm2n7_gem_oO_to(onumm2n7_t* arr1, oarrm2n7_t* arr2, oarrm2n7_t* arr3, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_div_OO(oarrm2n7_t*   lhs, oarrm2n7_t*   rhs);
  oarrm2n7_t oarrm2n7_div_OR(oarrm2n7_t*   lhs, darr_t*    rhs);
  oarrm2n7_t oarrm2n7_div_RO(darr_t*    lhs, oarrm2n7_t*   rhs);
  oarrm2n7_t oarrm2n7_div_oO(onumm2n7_t* lhs, oarrm2n7_t*   rhs);
  oarrm2n7_t oarrm2n7_div_Oo(oarrm2n7_t*   lhs, onumm2n7_t* rhs);
  oarrm2n7_t oarrm2n7_div_rO(coeff_t    lhs, oarrm2n7_t*   rhs);
  oarrm2n7_t oarrm2n7_div_Or(oarrm2n7_t*   lhs, coeff_t    rhs);
  void oarrm2n7_div_OO_to(oarrm2n7_t*   lhs, oarrm2n7_t*   rhs, oarrm2n7_t* res);
  void oarrm2n7_div_RO_to(darr_t*    lhs, oarrm2n7_t*   rhs, oarrm2n7_t* res);
  void oarrm2n7_div_OR_to(oarrm2n7_t*   lhs, darr_t*    rhs, oarrm2n7_t* res);
  void oarrm2n7_div_oO_to(onumm2n7_t* lhs, oarrm2n7_t*   rhs, oarrm2n7_t* res);
  void oarrm2n7_div_Oo_to(oarrm2n7_t*   lhs, onumm2n7_t* rhs, oarrm2n7_t* res);
  void oarrm2n7_div_rO_to(coeff_t    lhs, oarrm2n7_t*   rhs, oarrm2n7_t* res);
  void oarrm2n7_div_Or_to(oarrm2n7_t*   lhs, coeff_t    rhs, oarrm2n7_t* res);
  
  
  # From ../../../include/oti/static/onumm2n7/array/base.h
  
  void    oarrm2n7_taylor_integrate_to( coeff_t* deltas, oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_taylor_integrate(    coeff_t* deltas, oarrm2n7_t* arr);
  void    oarrm2n7_get_order_im_to( ord_t order, oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_get_order_im(    ord_t order, oarrm2n7_t* arr);
  void oarrm2n7_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n7_t* res);
  void oarrm2n7_set_slice_O( oarrm2n7_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n7_t* res);
  void oarrm2n7_set_slice_o( onumm2n7_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_get_slice( oarrm2n7_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm2n7_get_slice_to( oarrm2n7_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_truncate_im(    imdir_t idx, ord_t order, oarrm2n7_t* arr);
  void    oarrm2n7_truncate_im_to( imdir_t idx, ord_t order, oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_extract_im(   imdir_t idx, ord_t order, oarrm2n7_t* arr);
  void    oarrm2n7_extract_im_to(imdir_t idx, ord_t order, oarrm2n7_t* arr, oarrm2n7_t* res);
  darr_t  oarrm2n7_get_deriv(    imdir_t idx, ord_t order, oarrm2n7_t* arr);
  void    oarrm2n7_get_deriv_to( imdir_t idx, ord_t order, oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_get_deriv_o(  imdir_t idx, ord_t order, oarrm2n7_t* arr);
  oarrm2n7_t oarrm2n7_extract_deriv(    imdir_t idx, ord_t order, oarrm2n7_t* arr);
  void    oarrm2n7_extract_deriv_to( imdir_t idx, ord_t order, oarrm2n7_t* arr, oarrm2n7_t* res);
  darr_t  oarrm2n7_get_im(   imdir_t idx, ord_t order, oarrm2n7_t* arr);
  oarrm2n7_t oarrm2n7_get_im_o( imdir_t idx, ord_t order, oarrm2n7_t* arr);
  void    oarrm2n7_get_im_to(imdir_t idx, ord_t order, oarrm2n7_t* arr, oarrm2n7_t* res);
  void    oarrm2n7_copy_to(oarrm2n7_t* arr, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_copy(oarrm2n7_t* arr);
  void oarrm2n7_set_all_r( coeff_t num, oarrm2n7_t* arr);
  void oarrm2n7_set_item_i_r( coeff_t num, uint64_t i, oarrm2n7_t* arr);
  void oarrm2n7_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm2n7_t* arr);
  void oarrm2n7_set_r(   coeff_t  num,   oarrm2n7_t* arr);
  void oarrm2n7_set_o( onumm2n7_t* num,   oarrm2n7_t* arr);
  void oarrm2n7_set_O(   oarrm2n7_t* arrin, oarrm2n7_t* arr);
  void oarrm2n7_set_all_o( onumm2n7_t* src, oarrm2n7_t* arr);
  void oarrm2n7_set_item_i_o( onumm2n7_t* num, uint64_t i, oarrm2n7_t* arr);
  void oarrm2n7_set_item_ij_o( onumm2n7_t* num, uint64_t i, uint64_t j, oarrm2n7_t* arr);
  onumm2n7_t oarrm2n7_get_item_i(    oarrm2n7_t* arr, uint64_t i);
  void      oarrm2n7_get_item_i_to( oarrm2n7_t* arr, uint64_t i,             onumm2n7_t* res);
  onumm2n7_t oarrm2n7_get_item_ij(   oarrm2n7_t* arr, uint64_t i, uint64_t j);
  void      oarrm2n7_get_item_ij_to(oarrm2n7_t* arr, uint64_t i, uint64_t j, onumm2n7_t* res);
  oarrm2n7_t oarrm2n7_init();
  void oarrm2n7_free(oarrm2n7_t* arr);
  oarrm2n7_t oarrm2n7_empty_like(oarrm2n7_t* arr);
  oarrm2n7_t oarrm2n7_eye(uint64_t nrows);
  oarrm2n7_t oarrm2n7_ones(uint64_t nrows, uint64_t ncols);
  oarrm2n7_t oarrm2n7_zeros(uint64_t nrows, uint64_t ncols);
  oarrm2n7_t oarrm2n7_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm2n7/array/utils.h
  
  void oarrm2n7_dimCheck_OO_elementwise(oarrm2n7_t* arr1, oarrm2n7_t* arr2, oarrm2n7_t* res);
  void oarrm2n7_dimCheck_RO_elementwise(darr_t*  arr1, oarrm2n7_t* arr2, oarrm2n7_t* res);
  void oarrm2n7_dimCheck_OO_matmul(oarrm2n7_t* arr1, oarrm2n7_t* arr2, oarrm2n7_t* res);
  void oarrm2n7_dimCheck_RO_matmul(darr_t*  arr1, oarrm2n7_t* arr2, oarrm2n7_t* res);
  void oarrm2n7_dimCheck_OR_matmul(oarrm2n7_t* arr1, darr_t*  arr2, oarrm2n7_t* res);
  void oarrm2n7_dimCheck_O_squareness(oarrm2n7_t* arr1, oarrm2n7_t* res);
  void oarrm2n7_dimCheck_OO_samesize(oarrm2n7_t* arr1, oarrm2n7_t* res);
  void oarrm2n7_dimCheck_RO_samesize(darr_t* arr1, oarrm2n7_t* res);
  ord_t oarrm2n7_get_order(oarrm2n7_t* arr);
  void oarrm2n7_get_active_bases(oarrm2n7_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm2n7/array/algebra_matops.h
  
  onumm2n7_t oarrm2n7_dotproduct_OO(    oarrm2n7_t* lhs, oarrm2n7_t* rhs);
  void      oarrm2n7_dotproduct_OO_to( oarrm2n7_t* lhs, oarrm2n7_t* rhs, onumm2n7_t* res);
  onumm2n7_t oarrm2n7_dotproduct_RO(     darr_t* lhs, oarrm2n7_t* rhs);
  void      oarrm2n7_dotproduct_RO_to(  darr_t* lhs, oarrm2n7_t* rhs, onumm2n7_t* res);
  oarrm2n7_t oarrm2n7_matmul_OO(    oarrm2n7_t* lhs, oarrm2n7_t* rhs);
  oarrm2n7_t oarrm2n7_matmul_OR(    oarrm2n7_t* lhs,  darr_t* rhs);
  oarrm2n7_t oarrm2n7_matmul_RO(     darr_t* lhs, oarrm2n7_t* rhs);
  void    oarrm2n7_matmul_OO_to( oarrm2n7_t* lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
  void    oarrm2n7_matmul_OR_to( oarrm2n7_t* lhs,  darr_t* rhs, oarrm2n7_t* res);
  void    oarrm2n7_matmul_RO_to(  darr_t* lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_transpose(    oarrm2n7_t* arr1);
  void    oarrm2n7_transpose_to( oarrm2n7_t* arr1, oarrm2n7_t* res);
  oarrm2n7_t oarrm2n7_invert(    oarrm2n7_t* arr1);
  void    oarrm2n7_invert_to( oarrm2n7_t* arr1, oarrm2n7_t* res);
  onumm2n7_t oarrm2n7_det(    oarrm2n7_t* arr1);
  void      oarrm2n7_det_to( oarrm2n7_t* arr1, onumm2n7_t* res);
  onumm2n7_t oarrm2n7_norm(    oarrm2n7_t* arr1);
  void      oarrm2n7_norm_to( oarrm2n7_t* arr1,  onumm2n7_t* res);
  onumm2n7_t oarrm2n7_pnorm(    oarrm2n7_t* arr1, coeff_t p);
  void      oarrm2n7_pnorm_to( oarrm2n7_t* arr1, coeff_t p, onumm2n7_t* res);
  
  
  # From ../../../include/oti/static/onumm2n7/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm2n7/array/gauss/functions.h
  
  feoarrm2n7_t feoarrm2n7_atanh(    feoarrm2n7_t* arr);
  void      feoarrm2n7_atanh_to( feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_asinh(    feoarrm2n7_t* arr);
  void      feoarrm2n7_asinh_to( feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_acosh(    feoarrm2n7_t* arr);
  void      feoarrm2n7_acosh_to( feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_tanh(     feoarrm2n7_t* arr);
  void      feoarrm2n7_tanh_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sinh(     feoarrm2n7_t* arr);
  void      feoarrm2n7_sinh_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_cosh(     feoarrm2n7_t* arr);
  void      feoarrm2n7_cosh_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_atan(     feoarrm2n7_t* arr);
  void      feoarrm2n7_atan_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_asin(     feoarrm2n7_t* arr);
  void      feoarrm2n7_asin_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_acos(     feoarrm2n7_t* arr);
  void      feoarrm2n7_acos_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_tan(      feoarrm2n7_t* arr);
  void      feoarrm2n7_tan_to(   feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sin(      feoarrm2n7_t* arr);
  void      feoarrm2n7_sin_to(   feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_cos(      feoarrm2n7_t* arr);
  void      feoarrm2n7_cos_to(   feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_logb(     feoarrm2n7_t* arr, double base);
  void      feoarrm2n7_logb_to(  feoarrm2n7_t* arr, double base, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_log10(    feoarrm2n7_t* arr);
  void      feoarrm2n7_log10_to( feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_log(      feoarrm2n7_t* arr);
  void      feoarrm2n7_log_to(   feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_exp(      feoarrm2n7_t* arr);
  void      feoarrm2n7_exp_to(   feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_cbrt(     feoarrm2n7_t* arr);
  void      feoarrm2n7_cbrt_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sqrt(     feoarrm2n7_t* arr);
  void      feoarrm2n7_sqrt_to(  feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_pow(      feoarrm2n7_t* arr, double e);
  void      feoarrm2n7_pow_to(   feoarrm2n7_t* arr, double e, feoarrm2n7_t* res);
  
  
  # From ../../../include/oti/static/onumm2n7/array/gauss/base.h
  
  void      feoarrm2n7_get_order_im_to( ord_t order, feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_get_order_im(    ord_t order, feoarrm2n7_t* arr);
  feoarrm2n7_t feoarrm2n7_get_deriv(   imdir_t idx, ord_t order, feoarrm2n7_t* arr);
  void      feoarrm2n7_get_deriv_to(imdir_t idx, ord_t order, feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_get_im(      imdir_t idx, ord_t order, feoarrm2n7_t* arr);
  void      feoarrm2n7_get_im_to(   imdir_t idx, ord_t order, feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_truncate_im(   imdir_t idx, ord_t order, feoarrm2n7_t* arr);
  void      feoarrm2n7_truncate_im_to(imdir_t idx, ord_t order, feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_copy(   feoarrm2n7_t* src);
  void      feoarrm2n7_copy_to(feoarrm2n7_t* src, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_get_im(    imdir_t idx, ord_t order, feoarrm2n7_t* arr);
  void      feoarrm2n7_get_im_to( imdir_t idx, ord_t order, feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_get_deriv(    imdir_t idx, ord_t order, feoarrm2n7_t* arr);
  void      feoarrm2n7_get_deriv_to( imdir_t idx, ord_t order, feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_extract_im(    imdir_t idx, ord_t order, feoarrm2n7_t* arr);
  void      feoarrm2n7_extract_im_to( imdir_t idx, ord_t order, feoarrm2n7_t* arr,  feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_extract_deriv(    imdir_t idx, ord_t order, feoarrm2n7_t* arr);
  void      feoarrm2n7_extract_deriv_to( imdir_t idx, ord_t order, feoarrm2n7_t* arr, feoarrm2n7_t* res);
  oarrm2n7_t   feoarrm2n7_get_item_k(  feoarrm2n7_t* arr, uint64_t k);
  feonumm2n7_t  feoarrm2n7_get_item_ij( feoarrm2n7_t* arr, uint64_t i, uint64_t j);
  onumm2n7_t feoarrm2n7_get_item_ijk(feoarrm2n7_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm2n7_get_item_ij_to(  feoarrm2n7_t* arr, uint64_t i, uint64_t j,
                                 feonumm2n7_t* res);
  void feoarrm2n7_get_item_k_to(   feoarrm2n7_t* arr, uint64_t k,
                                  oarrm2n7_t* res);
  void feoarrm2n7_get_item_ijk_to( feoarrm2n7_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_get_slice(feoarrm2n7_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm2n7_get_slice_to(feoarrm2n7_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n7_t* res);
  void feoarrm2n7_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm2n7_t* res);
  void feoarrm2n7_set_item_ij_o(  onumm2n7_t* elm, uint64_t i, uint64_t j,
                               feoarrm2n7_t* res);
  void feoarrm2n7_set_item_ij_f(  feonumm2n7_t* elm, uint64_t i, uint64_t j,
                              feoarrm2n7_t* res);
  void feoarrm2n7_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm2n7_t* res);
  void feoarrm2n7_set_item_k_o(  onumm2n7_t* elm, uint64_t k,
                              feoarrm2n7_t* res);
  void feoarrm2n7_set_item_k_R(    oarrm2n7_t* elm, uint64_t k,
                            feoarrm2n7_t* res);
  void feoarrm2n7_set_item_k_O(    oarrm2n7_t* elm, uint64_t k,
                            feoarrm2n7_t* res);
  void feoarrm2n7_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm2n7_t* res);
  void feoarrm2n7_set_item_ijk_o( onumm2n7_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm2n7_t* res);
  void feoarrm2n7_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n7_t* res);
  void feoarrm2n7_set_slice_o( onumm2n7_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n7_t* res);
  void feoarrm2n7_set_slice_f( feonumm2n7_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n7_t* res);
  void feoarrm2n7_set_slice_O( oarrm2n7_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n7_t* res);
  void feoarrm2n7_set_slice_F( feoarrm2n7_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm2n7_t* res);
  void feoarrm2n7_set_all_o( onumm2n7_t* num, feoarrm2n7_t* arr );
  void feoarrm2n7_set_all_r(   coeff_t  num, feoarrm2n7_t* arr );
  void feoarrm2n7_set_all_f(  feonumm2n7_t* num, feoarrm2n7_t* arr );
  void feoarrm2n7_set_r(    coeff_t src, feoarrm2n7_t* res );
  void feoarrm2n7_set_o( onumm2n7_t* src, feoarrm2n7_t* res );
  void feoarrm2n7_set_f(  feonumm2n7_t* src, feoarrm2n7_t* res );
  void feoarrm2n7_set_R(    darr_t* src, feoarrm2n7_t* res );
  void feoarrm2n7_set_O(   oarrm2n7_t* src, feoarrm2n7_t* res );
  void feoarrm2n7_set_F( feoarrm2n7_t* src, feoarrm2n7_t* res );
  feoarrm2n7_t feoarrm2n7_eye( uint64_t size,  uint64_t nip);
  feoarrm2n7_t feoarrm2n7_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm2n7_t feoarrm2n7_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm2n7_t feoarrm2n7_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm2n7_free(feoarrm2n7_t* arr);
  feoarrm2n7_t feoarrm2n7_init();
  ord_t feoarrm2n7_get_order(feoarrm2n7_t* arr);
  
  
  # From ../../../include/oti/static/onumm2n7/array/gauss/utils.h
  
  void feoarrm2n7_dimCheck_FF_samesize(feoarrm2n7_t* arr1, feoarrm2n7_t* arr2, feonumm2n7_t* res);
  void feoarrm2n7_dimCheck_OF_samesize(  oarrm2n7_t* arr1, feoarrm2n7_t* arr2, feonumm2n7_t* res);
  void feoarrm2n7_dimCheck_RF_samesize(   darr_t* arr1, feoarrm2n7_t* arr2, feonumm2n7_t* res);
  void feoarrm2n7_dimCheck_FF_elementwise(feoarrm2n7_t* arr1, feoarrm2n7_t* arr2, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_OF_elementwise(  oarrm2n7_t* arr1, feoarrm2n7_t* arr2, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm2n7_t* arr2, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_fF_elementwise( feonumm2n7_t* num1, feoarrm2n7_t* arr2, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_Ff_elementwise(feoarrm2n7_t* arr1,  feonumm2n7_t* num2, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_FF_matmul( feoarrm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_OF_matmul(   oarrm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_RF_matmul(    darr_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_FO_matmul( feoarrm2n7_t* lhs,   oarrm2n7_t* rhs, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_FR_matmul( feoarrm2n7_t* lhs,    darr_t* rhs, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_F_squareness( feoarrm2n7_t* arr1, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_F_transpose( feoarrm2n7_t* arr1, feoarrm2n7_t* res);
  void feoarrm2n7_dimCheck_FfO_integrate(feoarrm2n7_t* arr, feonumm2n7_t* num,oarrm2n7_t* res);
  void feoarrm2n7_get_active_bases(feoarrm2n7_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm2n7/array/gauss/algebra.h
  
  feoarrm2n7_t feoarrm2n7_neg(    feoarrm2n7_t* arr);
  void      feoarrm2n7_neg_to( feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sum_FF(   feoarrm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sum_FF_to(feoarrm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sum_fF(    feonumm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sum_fF_to( feonumm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sum_OF(     oarrm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sum_OF_to(  oarrm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sum_RF(      darr_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sum_RF_to(   darr_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sum_oF(   onumm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sum_oF_to(onumm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sum_rF(     coeff_t  lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sum_rF_to(  coeff_t  lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sub_FF(    feoarrm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sub_FF_to( feoarrm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sub_fF(    feonumm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sub_fF_to( feonumm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sub_Ff(    feoarrm2n7_t* lhs, feonumm2n7_t* rhs);
  void      feoarrm2n7_sub_Ff_to( feoarrm2n7_t* lhs, feonumm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sub_OF(      oarrm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sub_OF_to(   oarrm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sub_FO(    feoarrm2n7_t* lhs,   oarrm2n7_t* rhs);
  void      feoarrm2n7_sub_FO_to( feoarrm2n7_t* lhs,   oarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sub_RF(       darr_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sub_RF_to(    darr_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sub_FR(    feoarrm2n7_t* lhs,    darr_t* rhs);
  void      feoarrm2n7_sub_FR_to( feoarrm2n7_t* lhs,    darr_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sub_oF(    onumm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sub_oF_to( onumm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sub_Fo(    feoarrm2n7_t* lhs, onumm2n7_t* rhs);
  void      feoarrm2n7_sub_Fo_to( feoarrm2n7_t* lhs, onumm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sub_rF(      coeff_t  lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_sub_rF_to(    coeff_t lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_sub_Fr(    feoarrm2n7_t* lhs,   coeff_t  rhs);
  void      feoarrm2n7_sub_Fr_to( feoarrm2n7_t* lhs,   coeff_t  rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_mul_FF(   feoarrm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_mul_FF_to(feoarrm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_mul_fF(    feonumm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_mul_fF_to( feonumm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_mul_OF(     oarrm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_mul_OF_to(  oarrm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_mul_RF(      darr_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_mul_RF_to(   darr_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_mul_oF(   onumm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_mul_oF_to(onumm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_mul_rF(     coeff_t  lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_mul_rF_to(  coeff_t  lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_div_FF(    feoarrm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_div_FF_to( feoarrm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_div_fF(     feonumm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_div_fF_to(  feonumm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_div_Ff(    feoarrm2n7_t* lhs,  feonumm2n7_t* rhs);
  void      feoarrm2n7_div_Ff_to( feoarrm2n7_t* lhs,  feonumm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_div_OF(      oarrm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_div_OF_to(   oarrm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_div_FO(    feoarrm2n7_t* lhs,   oarrm2n7_t* rhs);
  void      feoarrm2n7_div_FO_to( feoarrm2n7_t* lhs,   oarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_div_RF(       darr_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_div_RF_to(    darr_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_div_FR(    feoarrm2n7_t* lhs,    darr_t* rhs);
  void      feoarrm2n7_div_FR_to( feoarrm2n7_t* lhs,    darr_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_div_oF(    onumm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_div_oF_to( onumm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_div_Fo(    feoarrm2n7_t* lhs, onumm2n7_t* rhs);
  void      feoarrm2n7_div_Fo_to( feoarrm2n7_t* lhs, onumm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_div_rF(      coeff_t  lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_div_rF_to(    coeff_t lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_div_Fr(    feoarrm2n7_t* lhs,   coeff_t  rhs);
  void      feoarrm2n7_div_Fr_to( feoarrm2n7_t* lhs,   coeff_t  rhs, feoarrm2n7_t* res);
  oarrm2n7_t feoarrm2n7_integrate(    feoarrm2n7_t* arr, feonumm2n7_t* w);
  void    feoarrm2n7_integrate_to( feoarrm2n7_t* arr, feonumm2n7_t* w, oarrm2n7_t* res);
  feonumm2n7_t feoarrm2n7_dotproduct_FF(    feoarrm2n7_t* lhs, feoarrm2n7_t* rhs);
  void     feoarrm2n7_dotproduct_FF_to( feoarrm2n7_t* lhs, feoarrm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feoarrm2n7_dotproduct_OF(      oarrm2n7_t* lhs, feoarrm2n7_t* rhs);
  void     feoarrm2n7_dotproduct_OF_to(   oarrm2n7_t* lhs, feoarrm2n7_t* rhs, feonumm2n7_t* res);
  feonumm2n7_t feoarrm2n7_dotproduct_RF(       darr_t* lhs, feoarrm2n7_t* rhs);
  void     feoarrm2n7_dotproduct_RF_to(    darr_t* lhs, feoarrm2n7_t* rhs, feonumm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_matmul_FF(    feoarrm2n7_t* lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_matmul_FF_to( feoarrm2n7_t* lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_matmul_OF(    oarrm2n7_t*   lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_matmul_OF_to( oarrm2n7_t*   lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_matmul_FO(    feoarrm2n7_t* lhs, oarrm2n7_t*   rhs);
  void      feoarrm2n7_matmul_FO_to( feoarrm2n7_t* lhs, oarrm2n7_t*   rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_matmul_RF(    darr_t*    lhs, feoarrm2n7_t* rhs);
  void      feoarrm2n7_matmul_RF_to( darr_t*    lhs, feoarrm2n7_t* rhs, feoarrm2n7_t* res);
  feoarrm2n7_t feoarrm2n7_matmul_FR(    feoarrm2n7_t* lhs, darr_t*    rhs);
  void      feoarrm2n7_matmul_FR_to( feoarrm2n7_t* lhs, darr_t*    rhs, feoarrm2n7_t* res);
  feonumm2n7_t feoarrm2n7_det(   feoarrm2n7_t* arr);
  void     feoarrm2n7_det_to(feoarrm2n7_t* arr, feonumm2n7_t* res);
  feonumm2n7_t feoarrm2n7_norm(     feoarrm2n7_t* arr);
  void     feoarrm2n7_norm_to(  feoarrm2n7_t* arr, feonumm2n7_t* res);
  feonumm2n7_t feoarrm2n7_pnorm(    feoarrm2n7_t* arr, coeff_t p);
  void     feoarrm2n7_pnorm_to( feoarrm2n7_t* arr, coeff_t p, feonumm2n7_t* res);
  feoarrm2n7_t   feoarrm2n7_invert(    feoarrm2n7_t* arr);
  void        feoarrm2n7_invert_to( feoarrm2n7_t* arr, feoarrm2n7_t* res);
  feoarrm2n7_t   feoarrm2n7_transpose(   feoarrm2n7_t* arr);
  void        feoarrm2n7_transpose_to(feoarrm2n7_t* arr, feoarrm2n7_t* res);
  
  