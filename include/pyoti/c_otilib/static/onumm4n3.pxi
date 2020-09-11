cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm4n3/scalar/structures.h
  
  ctypedef struct  onumm4n3_t : # {
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
    coeff_t e114;
    coeff_t e124;
    coeff_t e224;
    coeff_t e134;
    coeff_t e234;
    coeff_t e334;
    coeff_t e144;
    coeff_t e244;
    coeff_t e344;
    coeff_t e444;
  # } onumm4n3_t;
  
  
  # From ../../../include/oti/static/onumm4n3/array/structures.h
  
  ctypedef struct  oarrm4n3_t : # {
      onumm4n3_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm4n3_t;
  
  
  # From ../../../include/oti/static/onumm4n3/scalar/gauss/structures.h
  
  ctypedef struct  feonumm4n3_t: # {
      onumm4n3_t*  p_data;
      uint64_t    nip;
  # } feonumm4n3_t;
  
  
  # From ../../../include/oti/static/onumm4n3/array/gauss/structures.h
  
  ctypedef struct  feoarrm4n3_t: # {
      oarrm4n3_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm4n3_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm4n3/scalar/functions.h
  
  onumm4n3_t onumm4n3_atanh(onumm4n3_t* num);
  void onumm4n3_atanh_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_asinh(onumm4n3_t* num);
  void onumm4n3_asinh_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_acosh(onumm4n3_t* num);
  void onumm4n3_acosh_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_tanh(onumm4n3_t* num);
  void onumm4n3_tanh_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_sqrt(onumm4n3_t* num);
  void onumm4n3_sqrt_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_cbrt(onumm4n3_t* num);
  void onumm4n3_cbrt_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_cosh(onumm4n3_t* num);
  void onumm4n3_cosh_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_sinh(onumm4n3_t* num);
  void onumm4n3_sinh_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_asin(onumm4n3_t* num);
  void onumm4n3_asin_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_acos(onumm4n3_t* num);
  void onumm4n3_acos_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_atan(onumm4n3_t* num);
  void onumm4n3_atan_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_tan(onumm4n3_t* num);
  void onumm4n3_tan_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_cos(onumm4n3_t* num);
  void onumm4n3_cos_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_sin(onumm4n3_t* num );
  void onumm4n3_sin_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_logb(onumm4n3_t* num, double base);
  void onumm4n3_logb_to(onumm4n3_t* num, double base, onumm4n3_t* res);
  onumm4n3_t onumm4n3_log10(onumm4n3_t* num);
  void onumm4n3_log10_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_log(onumm4n3_t* num);
  void onumm4n3_log_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_exp(onumm4n3_t* num);
  void onumm4n3_exp_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_pow(onumm4n3_t* num, double e);
  void onumm4n3_pow_to(onumm4n3_t* num, coeff_t e, onumm4n3_t* res);
  
  
  # From ../../../include/oti/static/onumm4n3/scalar/base.h
  
  void onumm4n3_set_im_o(onumm4n3_t* num, imdir_t idx, ord_t order, onumm4n3_t* res);
  void onumm4n3_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm4n3_t* res);
  void onumm4n3_set_deriv_o(onumm4n3_t* num, imdir_t idx, ord_t order, onumm4n3_t* res);
  void onumm4n3_extract_im_to( imdir_t idx, ord_t order, onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_extract_im(imdir_t idx, ord_t order, onumm4n3_t* num);
  onumm4n3_t onumm4n3_extract_deriv(imdir_t idx, ord_t order, onumm4n3_t* num);
  void onumm4n3_extract_deriv_to(imdir_t idx, ord_t order, onumm4n3_t* num, onumm4n3_t* res);
  void onumm4n3_get_im_to_o(imdir_t idx, ord_t order, onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_get_im_o(imdir_t idx, ord_t order, onumm4n3_t* num);
  void onumm4n3_get_im_to_r(imdir_t idx, ord_t order, onumm4n3_t* num, coeff_t* res);
  ord_t onumm4n3_get_order(onumm4n3_t* lhs);
  onumm4n3_t onumm4n3_get_deriv_o( imdir_t idx, ord_t order, onumm4n3_t* num);
  void onumm4n3_get_deriv_to( imdir_t idx, ord_t order, onumm4n3_t* num, onumm4n3_t* res);
  void onumm4n3_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm4n3_t* res);
  onumm4n3_t onumm4n3_init();
  ndir_t onumm4n3_get_ndir_order(ord_t order, onumm4n3_t* num);
  ndir_t onumm4n3_get_ndir_total(onumm4n3_t* num);
  coeff_t* onumm4n3_get_order_address(ord_t order, onumm4n3_t* num);
  onumm4n3_t onumm4n3_create_r(  coeff_t lhs);
  void onumm4n3_set_r(  coeff_t lhs, onumm4n3_t* res);
  void onumm4n3_set_o(  onumm4n3_t* lhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_get_order_im(ord_t order, onumm4n3_t* lhs);
  void onumm4n3_get_order_im_to(ord_t order, onumm4n3_t* lhs, onumm4n3_t* res);
  coeff_t onumm4n3_get_item(imdir_t idx, ord_t order, onumm4n3_t* lhs);
  coeff_t onumm4n3_get_deriv(imdir_t idx, ord_t order, onumm4n3_t* lhs);
  void onumm4n3_set_item(coeff_t val, imdir_t idx, ord_t order, onumm4n3_t* x);
  onumm4n3_t onumm4n3_copy(  onumm4n3_t* lhs);
  void onumm4n3_copy_to(  onumm4n3_t* lhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_taylor_integrate(coeff_t* deltas,onumm4n3_t* lhs);
  void onumm4n3_taylor_integrate_to(coeff_t* deltas,onumm4n3_t* lhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_truncate_im(imdir_t idx, ord_t order, onumm4n3_t* lhs);
  void onumm4n3_truncate_im_to(imdir_t idx, ord_t order, onumm4n3_t* lhs, onumm4n3_t* res);
  void onumm4n3_print(  onumm4n3_t* lhs);
  imdir_t onumm4n3_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm4n3/scalar/utils.h
  
  void onumm4n3_get_active_bases(onumm4n3_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm4n3/scalar/algebra.h
  
  onumm4n3_t onumm4n3_abs(onumm4n3_t* num);
  onumm4n3_t onumm4n3_div_ro(coeff_t num, onumm4n3_t* den);
  onumm4n3_t onumm4n3_div_oo(onumm4n3_t* num, onumm4n3_t* den);
  onumm4n3_t onumm4n3_div_or(onumm4n3_t* num, coeff_t val);
  void onumm4n3_div_ro_to(coeff_t num, onumm4n3_t* den, onumm4n3_t* res);
  void onumm4n3_div_oo_to(onumm4n3_t* num, onumm4n3_t* den, onumm4n3_t* res);
  void onumm4n3_div_or_to(onumm4n3_t* num, coeff_t val, onumm4n3_t* res);
  void onumm4n3_abs_to(onumm4n3_t* num, onumm4n3_t* res);
  onumm4n3_t onumm4n3_neg(  onumm4n3_t* lhs);
  void onumm4n3_neg_to(  onumm4n3_t* lhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_sum_oo(  onumm4n3_t* lhs,  onumm4n3_t* rhs);
  void onumm4n3_sum_oo_to(  onumm4n3_t* lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_sum_ro(  coeff_t lhs,  onumm4n3_t* rhs);
  void onumm4n3_sum_ro_to(  coeff_t lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_sub_oo(  onumm4n3_t* lhs,  onumm4n3_t* rhs);
  void onumm4n3_sub_oo_to(  onumm4n3_t* lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_sub_ro(  coeff_t lhs,  onumm4n3_t* rhs);
  void onumm4n3_sub_ro_to(  coeff_t lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_sub_or(  onumm4n3_t* lhs,  coeff_t rhs);
  void onumm4n3_sub_or_to(  onumm4n3_t* lhs,  coeff_t rhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_mul_oo(  onumm4n3_t* lhs,  onumm4n3_t* rhs);
  void onumm4n3_mul_oo_to(  onumm4n3_t* lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_mul_ro(  coeff_t lhs,  onumm4n3_t* rhs);
  void onumm4n3_mul_ro_to(  coeff_t lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_trunc_mul_oo(  onumm4n3_t* lhs,  onumm4n3_t* rhs);
  void onumm4n3_trunc_mul_oo_to(  onumm4n3_t* lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_gem_oo(  onumm4n3_t* a,  onumm4n3_t* b,  onumm4n3_t* c);
  void onumm4n3_gem_oo_to(  onumm4n3_t* a,  onumm4n3_t* b,  onumm4n3_t* c, onumm4n3_t* res);
  onumm4n3_t onumm4n3_gem_ro(  coeff_t a,  onumm4n3_t* b,  onumm4n3_t* c);
  void onumm4n3_gem_ro_to(  coeff_t a,  onumm4n3_t* b,  onumm4n3_t* c, onumm4n3_t* res);
  void onumm4n3_trunc_gem_oo_to( ord_t ord_lhs,  onumm4n3_t* a,  ord_t ord_rhs,  onumm4n3_t* b,  onumm4n3_t* c, onumm4n3_t* res);
  void onumm4n3_trunc_sum_oo_to(ord_t order, onumm4n3_t* lhs,onumm4n3_t* rhs, onumm4n3_t* res);
  void onumm4n3_trunc_sub_oo_to(ord_t order, onumm4n3_t* lhs,onumm4n3_t* rhs, onumm4n3_t* res);
  onumm4n3_t onumm4n3_feval(coeff_t* feval_re, onumm4n3_t* x);
  void onumm4n3_feval_to(coeff_t* feval_re, onumm4n3_t* x, onumm4n3_t* res);
  
  
  # From ../../../include/oti/static/onumm4n3/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm4n3/scalar/gauss/functions.h
  
  feonumm4n3_t feonumm4n3_atanh(    feonumm4n3_t* num);
  void     feonumm4n3_atanh_to( feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_asinh(    feonumm4n3_t* num);
  void     feonumm4n3_asinh_to( feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_acosh(    feonumm4n3_t* num);
  void     feonumm4n3_acosh_to( feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_tanh(     feonumm4n3_t* num);
  void     feonumm4n3_tanh_to(  feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_cosh(     feonumm4n3_t* num);
  void     feonumm4n3_cosh_to(  feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_sinh(     feonumm4n3_t* num);
  void     feonumm4n3_sinh_to(  feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_asin(     feonumm4n3_t* num);
  void     feonumm4n3_asin_to(  feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_acos(     feonumm4n3_t* num);
  void     feonumm4n3_acos_to(  feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_atan(     feonumm4n3_t* num);
  void     feonumm4n3_atan_to(  feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_tan(      feonumm4n3_t* num);
  void     feonumm4n3_tan_to(   feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_cos(      feonumm4n3_t* num);
  void     feonumm4n3_cos_to(   feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_sin(      feonumm4n3_t* num);
  void     feonumm4n3_sin_to(   feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_logb(     feonumm4n3_t* num, double base);
  void     feonumm4n3_logb_to(  feonumm4n3_t* num, double base, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_log10(    feonumm4n3_t* num);
  void     feonumm4n3_log10_to( feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_log(      feonumm4n3_t* num);
  void     feonumm4n3_log_to(   feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_exp(      feonumm4n3_t* num);
  void     feonumm4n3_exp_to(   feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_cbrt(     feonumm4n3_t* num);
  void     feonumm4n3_cbrt_to(  feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_sqrt(     feonumm4n3_t* num);
  void     feonumm4n3_sqrt_to(  feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_pow(      feonumm4n3_t* num, double e);
  void     feonumm4n3_pow_to(   feonumm4n3_t* num, double e, feonumm4n3_t* res);
  onumm4n3_t feonumm4n3_integrate(       feonumm4n3_t* num, feonumm4n3_t* w);
  void      feonumm4n3_integrate_to(    feonumm4n3_t* num, feonumm4n3_t* w, onumm4n3_t* res);
  onumm4n3_t feonumm4n3_integrate_f(     feonumm4n3_t* num, feonumm4n3_t* w);
  void      feonumm4n3_integrate_f_to(  feonumm4n3_t* num, feonumm4n3_t* w, onumm4n3_t* res);
  onumm4n3_t feonumm4n3_integrate_r(       coeff_t num, feonumm4n3_t* w);
  void      feonumm4n3_integrate_r_to(    coeff_t num, feonumm4n3_t* w, onumm4n3_t* res);
  onumm4n3_t feonumm4n3_integrate_o(    onumm4n3_t* num, feonumm4n3_t* w);
  void      feonumm4n3_integrate_o_to( onumm4n3_t* num, feonumm4n3_t* w, onumm4n3_t* res);
  
  
  # From ../../../include/oti/static/onumm4n3/scalar/gauss/base.h
  
  void     feonumm4n3_get_order_im_to( ord_t order, feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_get_order_im(    ord_t order, feonumm4n3_t* num);
  feonumm4n3_t feonumm4n3_get_im(    imdir_t idx, ord_t order, feonumm4n3_t* num);
  void     feonumm4n3_get_im_to( imdir_t idx, ord_t order, feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_get_deriv(    imdir_t idx, ord_t order, feonumm4n3_t* num);
  void     feonumm4n3_get_deriv_to( imdir_t idx, ord_t order, feonumm4n3_t* num, feonumm4n3_t* res);
  void feonumm4n3_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm4n3_t* num);
  void feonumm4n3_set_im_o( onumm4n3_t* val, imdir_t idx, ord_t order, feonumm4n3_t* num);
  void feonumm4n3_set_im_f(  feonumm4n3_t* val, imdir_t idx, ord_t order, feonumm4n3_t* num);
  void feonumm4n3_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm4n3_t* num);
  void feonumm4n3_set_deriv_o( onumm4n3_t* val, imdir_t idx, ord_t order, feonumm4n3_t* num);
  void feonumm4n3_set_deriv_f(  feonumm4n3_t* val, imdir_t idx, ord_t order, feonumm4n3_t* num);
  feonumm4n3_t feonumm4n3_extract_im(    imdir_t idx, ord_t order, feonumm4n3_t* num);
  void     feonumm4n3_extract_im_to( imdir_t idx, ord_t order, feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_extract_deriv(    imdir_t idx, ord_t order, feonumm4n3_t* num);
  void     feonumm4n3_extract_deriv_to( imdir_t idx, ord_t order, feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_truncate_im(    imdir_t idx, ord_t order, feonumm4n3_t* num);
  void     feonumm4n3_truncate_im_to( imdir_t idx, ord_t order, feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_copy(    feonumm4n3_t* src);
  void     feonumm4n3_copy_to( feonumm4n3_t* src, feonumm4n3_t* dst);
  void feonumm4n3_set_r(    coeff_t num, feonumm4n3_t* res);
  void feonumm4n3_set_o( onumm4n3_t* num, feonumm4n3_t* res);
  void feonumm4n3_set_f(  feonumm4n3_t* num, feonumm4n3_t* res);
  void feonumm4n3_set_item_k_r(   coeff_t  num, uint64_t k, feonumm4n3_t* res);
  void feonumm4n3_set_item_k_o( onumm4n3_t* num, uint64_t k, feonumm4n3_t* res);
  onumm4n3_t feonumm4n3_get_item_k(   feonumm4n3_t* num, uint64_t k);
  void      feonumm4n3_get_item_k_to(feonumm4n3_t* num, uint64_t k, onumm4n3_t* res);
  feonumm4n3_t feonumm4n3_zeros(uint64_t nIntPts);
  feonumm4n3_t feonumm4n3_createEmpty(uint64_t nIntPts);
  feonumm4n3_t feonumm4n3_empty_like(feonumm4n3_t* arr);
  void feonumm4n3_free(feonumm4n3_t* num);
  ord_t feonumm4n3_get_order( feonumm4n3_t* num );
  feonumm4n3_t feonumm4n3_init();
  
  
  # From ../../../include/oti/static/onumm4n3/scalar/gauss/utils.h
  
  void feonumm4n3_dimCheck(feonumm4n3_t* arr1,feonumm4n3_t* arr2);
  void feonumm4n3_get_active_bases(feonumm4n3_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n3/scalar/gauss/algebra.h
  
  feonumm4n3_t feonumm4n3_neg(   feonumm4n3_t* num);
  void     feonumm4n3_neg_to(feonumm4n3_t* num, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_sum_ff(   feonumm4n3_t* lhs, feonumm4n3_t* rhs);
  void     feonumm4n3_sum_ff_to(feonumm4n3_t* lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_sum_of(   onumm4n3_t* lhs, feonumm4n3_t* rhs);
  void     feonumm4n3_sum_of_to(onumm4n3_t* lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_sum_rf(   coeff_t lhs, feonumm4n3_t* rhs);
  void     feonumm4n3_sum_rf_to(coeff_t lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_sub_ff(     feonumm4n3_t* lhs,  feonumm4n3_t* rhs);
  void     feonumm4n3_sub_ff_to(  feonumm4n3_t* lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_sub_of(    onumm4n3_t* lhs,  feonumm4n3_t* rhs);
  void     feonumm4n3_sub_of_to( onumm4n3_t* lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_sub_fo(     feonumm4n3_t* lhs, onumm4n3_t* rhs);
  void     feonumm4n3_sub_fo_to(  feonumm4n3_t* lhs, onumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_sub_rf(       coeff_t lhs,  feonumm4n3_t* rhs);
  void     feonumm4n3_sub_rf_to(    coeff_t lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_sub_fr(     feonumm4n3_t* lhs,    coeff_t rhs);
  void     feonumm4n3_sub_fr_to(  feonumm4n3_t* lhs,    coeff_t rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_mul_ff(   feonumm4n3_t* lhs, feonumm4n3_t* rhs);
  void     feonumm4n3_mul_ff_to(feonumm4n3_t* lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_mul_of(   onumm4n3_t* lhs, feonumm4n3_t* rhs);
  void     feonumm4n3_mul_of_to(onumm4n3_t* lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_mul_rf(   coeff_t lhs, feonumm4n3_t* rhs);
  void     feonumm4n3_mul_rf_to(coeff_t lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_div_ff(     feonumm4n3_t* lhs,  feonumm4n3_t* rhs);
  void     feonumm4n3_div_ff_to(  feonumm4n3_t* lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_div_of(    onumm4n3_t* lhs,  feonumm4n3_t* rhs);
  void     feonumm4n3_div_of_to( onumm4n3_t* lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_div_fo(     feonumm4n3_t* lhs, onumm4n3_t* rhs);
  void     feonumm4n3_div_fo_to(  feonumm4n3_t* lhs, onumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_div_rf(       coeff_t lhs,  feonumm4n3_t* rhs);
  void     feonumm4n3_div_rf_to(    coeff_t lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feonumm4n3_div_fr(     feonumm4n3_t* lhs,    coeff_t rhs);
  void     feonumm4n3_div_fr_to(  feonumm4n3_t* lhs,    coeff_t rhs, feonumm4n3_t* res);
  
  
  # From ../../../include/oti/static/onumm4n3/array/functions.h
  
  oarrm4n3_t oarrm4n3_atanh(   oarrm4n3_t* arr);
  void    oarrm4n3_atanh_to(oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_asinh(   oarrm4n3_t* arr);
  void    oarrm4n3_asinh_to(oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_acosh(   oarrm4n3_t* arr);
  void    oarrm4n3_acosh_to(oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_tanh(    oarrm4n3_t* arr);
  void    oarrm4n3_tanh_to( oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_cbrt(    oarrm4n3_t* arr);
  void    oarrm4n3_cbrt_to( oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_sqrt(    oarrm4n3_t* arr);
  void    oarrm4n3_sqrt_to( oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_cosh(    oarrm4n3_t* arr);
  void    oarrm4n3_cosh_to( oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_sinh(    oarrm4n3_t* arr);
  void    oarrm4n3_sinh_to( oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_asin(    oarrm4n3_t* arr);
  void    oarrm4n3_asin_to( oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_acos(    oarrm4n3_t* arr);
  void    oarrm4n3_acos_to( oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_atan(    oarrm4n3_t* arr);
  void    oarrm4n3_atan_to( oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_tan(     oarrm4n3_t* arr);
  void    oarrm4n3_tan_to(  oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_cos(     oarrm4n3_t* arr);
  void    oarrm4n3_cos_to(  oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_sin(     oarrm4n3_t* arr);
  void    oarrm4n3_sin_to(  oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_logb(    oarrm4n3_t* arr, double base);
  void    oarrm4n3_logb_to( oarrm4n3_t* arr, double base, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_log10(   oarrm4n3_t* arr);
  void    oarrm4n3_log10_to(oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_log(     oarrm4n3_t* arr);
  void    oarrm4n3_log_to(  oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_exp(     oarrm4n3_t* arr);
  void    oarrm4n3_exp_to(  oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_pow(     oarrm4n3_t* arr, double e);
  void    oarrm4n3_pow_to(  oarrm4n3_t* arr, double e, oarrm4n3_t* res);
  
  
  # From ../../../include/oti/static/onumm4n3/array/algebra_elementwise.h
  
  oarrm4n3_t oarrm4n3_neg(oarrm4n3_t* arr);
  void oarrm4n3_neg_to(oarrm4n3_t* rhs, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_sum_OO(oarrm4n3_t*   lhs, oarrm4n3_t* rhs);
  oarrm4n3_t oarrm4n3_sum_RO(darr_t*    lhs, oarrm4n3_t* rhs);
  oarrm4n3_t oarrm4n3_sum_oO(onumm4n3_t* lhs, oarrm4n3_t* rhs);
  oarrm4n3_t oarrm4n3_sum_rO(coeff_t    lhs, oarrm4n3_t* rhs);
  void oarrm4n3_sum_OO_to(oarrm4n3_t*   lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
  void oarrm4n3_sum_RO_to(darr_t*    lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
  void oarrm4n3_sum_oO_to(onumm4n3_t* lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
  void oarrm4n3_sum_rO_to(coeff_t    lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
  void oarrm4n3_trunc_sum_OO_to(ord_t order, oarrm4n3_t* arr1, oarrm4n3_t* arr2, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_sub_OO(oarrm4n3_t*   lhs, oarrm4n3_t*   rhs);
  oarrm4n3_t oarrm4n3_sub_RO(darr_t*    lhs, oarrm4n3_t*   rhs);
  oarrm4n3_t oarrm4n3_sub_OR(oarrm4n3_t*   lhs, darr_t*    rhs);
  oarrm4n3_t oarrm4n3_sub_oO(onumm4n3_t* lhs, oarrm4n3_t*   rhs);
  oarrm4n3_t oarrm4n3_sub_Oo(oarrm4n3_t*   lhs, onumm4n3_t* rhs);
  oarrm4n3_t oarrm4n3_sub_rO(coeff_t    lhs, oarrm4n3_t*   rhs);
  oarrm4n3_t oarrm4n3_sub_Or(oarrm4n3_t*   lhs, coeff_t    rhs);
  void oarrm4n3_sub_OO_to( oarrm4n3_t*   lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
  void oarrm4n3_sub_RO_to( darr_t*    lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
  void oarrm4n3_sub_OR_to( oarrm4n3_t*   lhs, darr_t*    rhs, oarrm4n3_t* res);
  void oarrm4n3_sub_oO_to( onumm4n3_t* lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
  void oarrm4n3_sub_Oo_to( oarrm4n3_t*   lhs, onumm4n3_t* rhs, oarrm4n3_t* res);
  void oarrm4n3_sub_rO_to( coeff_t    lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
  void oarrm4n3_sub_Or_to( oarrm4n3_t*   lhs, coeff_t    rhs, oarrm4n3_t* res);
  void oarrm4n3_trunc_sub_OO_to(ord_t order, oarrm4n3_t* arr1, oarrm4n3_t* arr2, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_mul_OO(oarrm4n3_t*   lhs, oarrm4n3_t* rhs);
  oarrm4n3_t oarrm4n3_mul_RO(darr_t*    lhs, oarrm4n3_t* rhs);
  oarrm4n3_t oarrm4n3_mul_oO(onumm4n3_t* lhs, oarrm4n3_t* rhs);
  oarrm4n3_t oarrm4n3_mul_rO(coeff_t    lhs, oarrm4n3_t* rhs);
  void oarrm4n3_mul_OO_to(oarrm4n3_t*   lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
  void oarrm4n3_mul_RO_to(darr_t*    lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
  void oarrm4n3_mul_oO_to(onumm4n3_t* lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
  void oarrm4n3_mul_rO_to(coeff_t    lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
  void oarrm4n3_gem_OO_to(  oarrm4n3_t* arr1, oarrm4n3_t* arr2, oarrm4n3_t* arr3, oarrm4n3_t* res);
  void oarrm4n3_gem_oO_to(onumm4n3_t* arr1, oarrm4n3_t* arr2, oarrm4n3_t* arr3, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_div_OO(oarrm4n3_t*   lhs, oarrm4n3_t*   rhs);
  oarrm4n3_t oarrm4n3_div_OR(oarrm4n3_t*   lhs, darr_t*    rhs);
  oarrm4n3_t oarrm4n3_div_RO(darr_t*    lhs, oarrm4n3_t*   rhs);
  oarrm4n3_t oarrm4n3_div_oO(onumm4n3_t* lhs, oarrm4n3_t*   rhs);
  oarrm4n3_t oarrm4n3_div_Oo(oarrm4n3_t*   lhs, onumm4n3_t* rhs);
  oarrm4n3_t oarrm4n3_div_rO(coeff_t    lhs, oarrm4n3_t*   rhs);
  oarrm4n3_t oarrm4n3_div_Or(oarrm4n3_t*   lhs, coeff_t    rhs);
  void oarrm4n3_div_OO_to(oarrm4n3_t*   lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
  void oarrm4n3_div_RO_to(darr_t*    lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
  void oarrm4n3_div_OR_to(oarrm4n3_t*   lhs, darr_t*    rhs, oarrm4n3_t* res);
  void oarrm4n3_div_oO_to(onumm4n3_t* lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
  void oarrm4n3_div_Oo_to(oarrm4n3_t*   lhs, onumm4n3_t* rhs, oarrm4n3_t* res);
  void oarrm4n3_div_rO_to(coeff_t    lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
  void oarrm4n3_div_Or_to(oarrm4n3_t*   lhs, coeff_t    rhs, oarrm4n3_t* res);
  
  
  # From ../../../include/oti/static/onumm4n3/array/base.h
  
  void    oarrm4n3_taylor_integrate_to( coeff_t* deltas, oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_taylor_integrate(    coeff_t* deltas, oarrm4n3_t* arr);
  void    oarrm4n3_get_order_im_to( ord_t order, oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_get_order_im(    ord_t order, oarrm4n3_t* arr);
  void oarrm4n3_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n3_t* res);
  void oarrm4n3_set_slice_O( oarrm4n3_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n3_t* res);
  void oarrm4n3_set_slice_o( onumm4n3_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_get_slice( oarrm4n3_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm4n3_get_slice_to( oarrm4n3_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_truncate_im(    imdir_t idx, ord_t order, oarrm4n3_t* arr);
  void    oarrm4n3_truncate_im_to( imdir_t idx, ord_t order, oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_extract_im(   imdir_t idx, ord_t order, oarrm4n3_t* arr);
  void    oarrm4n3_extract_im_to(imdir_t idx, ord_t order, oarrm4n3_t* arr, oarrm4n3_t* res);
  darr_t  oarrm4n3_get_deriv(    imdir_t idx, ord_t order, oarrm4n3_t* arr);
  void    oarrm4n3_get_deriv_to( imdir_t idx, ord_t order, oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_get_deriv_o(  imdir_t idx, ord_t order, oarrm4n3_t* arr);
  oarrm4n3_t oarrm4n3_extract_deriv(    imdir_t idx, ord_t order, oarrm4n3_t* arr);
  void    oarrm4n3_extract_deriv_to( imdir_t idx, ord_t order, oarrm4n3_t* arr, oarrm4n3_t* res);
  darr_t  oarrm4n3_get_im(   imdir_t idx, ord_t order, oarrm4n3_t* arr);
  oarrm4n3_t oarrm4n3_get_im_o( imdir_t idx, ord_t order, oarrm4n3_t* arr);
  void    oarrm4n3_get_im_to(imdir_t idx, ord_t order, oarrm4n3_t* arr, oarrm4n3_t* res);
  void    oarrm4n3_copy_to(oarrm4n3_t* arr, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_copy(oarrm4n3_t* arr);
  void oarrm4n3_set_all_r( coeff_t num, oarrm4n3_t* arr);
  void oarrm4n3_set_item_i_r( coeff_t num, uint64_t i, oarrm4n3_t* arr);
  void oarrm4n3_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm4n3_t* arr);
  void oarrm4n3_set_r(   coeff_t  num,   oarrm4n3_t* arr);
  void oarrm4n3_set_o( onumm4n3_t* num,   oarrm4n3_t* arr);
  void oarrm4n3_set_O(   oarrm4n3_t* arrin, oarrm4n3_t* arr);
  void oarrm4n3_set_all_o( onumm4n3_t* src, oarrm4n3_t* arr);
  void oarrm4n3_set_item_i_o( onumm4n3_t* num, uint64_t i, oarrm4n3_t* arr);
  void oarrm4n3_set_item_ij_o( onumm4n3_t* num, uint64_t i, uint64_t j, oarrm4n3_t* arr);
  onumm4n3_t oarrm4n3_get_item_i(    oarrm4n3_t* arr, uint64_t i);
  void      oarrm4n3_get_item_i_to( oarrm4n3_t* arr, uint64_t i,             onumm4n3_t* res);
  onumm4n3_t oarrm4n3_get_item_ij(   oarrm4n3_t* arr, uint64_t i, uint64_t j);
  void      oarrm4n3_get_item_ij_to(oarrm4n3_t* arr, uint64_t i, uint64_t j, onumm4n3_t* res);
  oarrm4n3_t oarrm4n3_init();
  void oarrm4n3_free(oarrm4n3_t* arr);
  oarrm4n3_t oarrm4n3_empty_like(oarrm4n3_t* arr);
  oarrm4n3_t oarrm4n3_eye(uint64_t nrows);
  oarrm4n3_t oarrm4n3_ones(uint64_t nrows, uint64_t ncols);
  oarrm4n3_t oarrm4n3_zeros(uint64_t nrows, uint64_t ncols);
  oarrm4n3_t oarrm4n3_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm4n3/array/utils.h
  
  void oarrm4n3_dimCheck_OO_elementwise(oarrm4n3_t* arr1, oarrm4n3_t* arr2, oarrm4n3_t* res);
  void oarrm4n3_dimCheck_RO_elementwise(darr_t*  arr1, oarrm4n3_t* arr2, oarrm4n3_t* res);
  void oarrm4n3_dimCheck_OO_matmul(oarrm4n3_t* arr1, oarrm4n3_t* arr2, oarrm4n3_t* res);
  void oarrm4n3_dimCheck_RO_matmul(darr_t*  arr1, oarrm4n3_t* arr2, oarrm4n3_t* res);
  void oarrm4n3_dimCheck_OR_matmul(oarrm4n3_t* arr1, darr_t*  arr2, oarrm4n3_t* res);
  void oarrm4n3_dimCheck_O_squareness(oarrm4n3_t* arr1, oarrm4n3_t* res);
  void oarrm4n3_dimCheck_OO_samesize(oarrm4n3_t* arr1, oarrm4n3_t* res);
  void oarrm4n3_dimCheck_RO_samesize(darr_t* arr1, oarrm4n3_t* res);
  ord_t oarrm4n3_get_order(oarrm4n3_t* arr);
  void oarrm4n3_get_active_bases(oarrm4n3_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n3/array/algebra_matops.h
  
  onumm4n3_t oarrm4n3_dotproduct_OO(    oarrm4n3_t* lhs, oarrm4n3_t* rhs);
  void      oarrm4n3_dotproduct_OO_to( oarrm4n3_t* lhs, oarrm4n3_t* rhs, onumm4n3_t* res);
  onumm4n3_t oarrm4n3_dotproduct_RO(     darr_t* lhs, oarrm4n3_t* rhs);
  void      oarrm4n3_dotproduct_RO_to(  darr_t* lhs, oarrm4n3_t* rhs, onumm4n3_t* res);
  oarrm4n3_t oarrm4n3_matmul_OO(    oarrm4n3_t* lhs, oarrm4n3_t* rhs);
  oarrm4n3_t oarrm4n3_matmul_OR(    oarrm4n3_t* lhs,  darr_t* rhs);
  oarrm4n3_t oarrm4n3_matmul_RO(     darr_t* lhs, oarrm4n3_t* rhs);
  void    oarrm4n3_matmul_OO_to( oarrm4n3_t* lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
  void    oarrm4n3_matmul_OR_to( oarrm4n3_t* lhs,  darr_t* rhs, oarrm4n3_t* res);
  void    oarrm4n3_matmul_RO_to(  darr_t* lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_transpose(    oarrm4n3_t* arr1);
  void    oarrm4n3_transpose_to( oarrm4n3_t* arr1, oarrm4n3_t* res);
  oarrm4n3_t oarrm4n3_invert(    oarrm4n3_t* arr1);
  void    oarrm4n3_invert_to( oarrm4n3_t* arr1, oarrm4n3_t* res);
  onumm4n3_t oarrm4n3_det(    oarrm4n3_t* arr1);
  void      oarrm4n3_det_to( oarrm4n3_t* arr1, onumm4n3_t* res);
  onumm4n3_t oarrm4n3_norm(    oarrm4n3_t* arr1);
  void      oarrm4n3_norm_to( oarrm4n3_t* arr1,  onumm4n3_t* res);
  onumm4n3_t oarrm4n3_pnorm(    oarrm4n3_t* arr1, coeff_t p);
  void      oarrm4n3_pnorm_to( oarrm4n3_t* arr1, coeff_t p, onumm4n3_t* res);
  
  
  # From ../../../include/oti/static/onumm4n3/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm4n3/array/gauss/functions.h
  
  feoarrm4n3_t feoarrm4n3_atanh(    feoarrm4n3_t* arr);
  void      feoarrm4n3_atanh_to( feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_asinh(    feoarrm4n3_t* arr);
  void      feoarrm4n3_asinh_to( feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_acosh(    feoarrm4n3_t* arr);
  void      feoarrm4n3_acosh_to( feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_tanh(     feoarrm4n3_t* arr);
  void      feoarrm4n3_tanh_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sinh(     feoarrm4n3_t* arr);
  void      feoarrm4n3_sinh_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_cosh(     feoarrm4n3_t* arr);
  void      feoarrm4n3_cosh_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_atan(     feoarrm4n3_t* arr);
  void      feoarrm4n3_atan_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_asin(     feoarrm4n3_t* arr);
  void      feoarrm4n3_asin_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_acos(     feoarrm4n3_t* arr);
  void      feoarrm4n3_acos_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_tan(      feoarrm4n3_t* arr);
  void      feoarrm4n3_tan_to(   feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sin(      feoarrm4n3_t* arr);
  void      feoarrm4n3_sin_to(   feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_cos(      feoarrm4n3_t* arr);
  void      feoarrm4n3_cos_to(   feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_logb(     feoarrm4n3_t* arr, double base);
  void      feoarrm4n3_logb_to(  feoarrm4n3_t* arr, double base, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_log10(    feoarrm4n3_t* arr);
  void      feoarrm4n3_log10_to( feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_log(      feoarrm4n3_t* arr);
  void      feoarrm4n3_log_to(   feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_exp(      feoarrm4n3_t* arr);
  void      feoarrm4n3_exp_to(   feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_cbrt(     feoarrm4n3_t* arr);
  void      feoarrm4n3_cbrt_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sqrt(     feoarrm4n3_t* arr);
  void      feoarrm4n3_sqrt_to(  feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_pow(      feoarrm4n3_t* arr, double e);
  void      feoarrm4n3_pow_to(   feoarrm4n3_t* arr, double e, feoarrm4n3_t* res);
  
  
  # From ../../../include/oti/static/onumm4n3/array/gauss/base.h
  
  void      feoarrm4n3_get_order_im_to( ord_t order, feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_get_order_im(    ord_t order, feoarrm4n3_t* arr);
  feoarrm4n3_t feoarrm4n3_get_deriv(   imdir_t idx, ord_t order, feoarrm4n3_t* arr);
  void      feoarrm4n3_get_deriv_to(imdir_t idx, ord_t order, feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_get_im(      imdir_t idx, ord_t order, feoarrm4n3_t* arr);
  void      feoarrm4n3_get_im_to(   imdir_t idx, ord_t order, feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_truncate_im(   imdir_t idx, ord_t order, feoarrm4n3_t* arr);
  void      feoarrm4n3_truncate_im_to(imdir_t idx, ord_t order, feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_copy(   feoarrm4n3_t* src);
  void      feoarrm4n3_copy_to(feoarrm4n3_t* src, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_get_im(    imdir_t idx, ord_t order, feoarrm4n3_t* arr);
  void      feoarrm4n3_get_im_to( imdir_t idx, ord_t order, feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_get_deriv(    imdir_t idx, ord_t order, feoarrm4n3_t* arr);
  void      feoarrm4n3_get_deriv_to( imdir_t idx, ord_t order, feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_extract_im(    imdir_t idx, ord_t order, feoarrm4n3_t* arr);
  void      feoarrm4n3_extract_im_to( imdir_t idx, ord_t order, feoarrm4n3_t* arr,  feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_extract_deriv(    imdir_t idx, ord_t order, feoarrm4n3_t* arr);
  void      feoarrm4n3_extract_deriv_to( imdir_t idx, ord_t order, feoarrm4n3_t* arr, feoarrm4n3_t* res);
  oarrm4n3_t   feoarrm4n3_get_item_k(  feoarrm4n3_t* arr, uint64_t k);
  feonumm4n3_t  feoarrm4n3_get_item_ij( feoarrm4n3_t* arr, uint64_t i, uint64_t j);
  onumm4n3_t feoarrm4n3_get_item_ijk(feoarrm4n3_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm4n3_get_item_ij_to(  feoarrm4n3_t* arr, uint64_t i, uint64_t j,
                                 feonumm4n3_t* res);
  void feoarrm4n3_get_item_k_to(   feoarrm4n3_t* arr, uint64_t k,
                                  oarrm4n3_t* res);
  void feoarrm4n3_get_item_ijk_to( feoarrm4n3_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_get_slice(feoarrm4n3_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm4n3_get_slice_to(feoarrm4n3_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n3_t* res);
  void feoarrm4n3_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm4n3_t* res);
  void feoarrm4n3_set_item_ij_o(  onumm4n3_t* elm, uint64_t i, uint64_t j,
                               feoarrm4n3_t* res);
  void feoarrm4n3_set_item_ij_f(  feonumm4n3_t* elm, uint64_t i, uint64_t j,
                              feoarrm4n3_t* res);
  void feoarrm4n3_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm4n3_t* res);
  void feoarrm4n3_set_item_k_o(  onumm4n3_t* elm, uint64_t k,
                              feoarrm4n3_t* res);
  void feoarrm4n3_set_item_k_R(    oarrm4n3_t* elm, uint64_t k,
                            feoarrm4n3_t* res);
  void feoarrm4n3_set_item_k_O(    oarrm4n3_t* elm, uint64_t k,
                            feoarrm4n3_t* res);
  void feoarrm4n3_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm4n3_t* res);
  void feoarrm4n3_set_item_ijk_o( onumm4n3_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm4n3_t* res);
  void feoarrm4n3_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n3_t* res);
  void feoarrm4n3_set_slice_o( onumm4n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n3_t* res);
  void feoarrm4n3_set_slice_f( feonumm4n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n3_t* res);
  void feoarrm4n3_set_slice_O( oarrm4n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n3_t* res);
  void feoarrm4n3_set_slice_F( feoarrm4n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n3_t* res);
  void feoarrm4n3_set_all_o( onumm4n3_t* num, feoarrm4n3_t* arr );
  void feoarrm4n3_set_all_r(   coeff_t  num, feoarrm4n3_t* arr );
  void feoarrm4n3_set_all_f(  feonumm4n3_t* num, feoarrm4n3_t* arr );
  void feoarrm4n3_set_r(    coeff_t src, feoarrm4n3_t* res );
  void feoarrm4n3_set_o( onumm4n3_t* src, feoarrm4n3_t* res );
  void feoarrm4n3_set_f(  feonumm4n3_t* src, feoarrm4n3_t* res );
  void feoarrm4n3_set_R(    darr_t* src, feoarrm4n3_t* res );
  void feoarrm4n3_set_O(   oarrm4n3_t* src, feoarrm4n3_t* res );
  void feoarrm4n3_set_F( feoarrm4n3_t* src, feoarrm4n3_t* res );
  feoarrm4n3_t feoarrm4n3_eye( uint64_t size,  uint64_t nip);
  feoarrm4n3_t feoarrm4n3_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm4n3_t feoarrm4n3_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm4n3_t feoarrm4n3_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm4n3_free(feoarrm4n3_t* arr);
  feoarrm4n3_t feoarrm4n3_init();
  ord_t feoarrm4n3_get_order(feoarrm4n3_t* arr);
  
  
  # From ../../../include/oti/static/onumm4n3/array/gauss/utils.h
  
  void feoarrm4n3_dimCheck_FF_samesize(feoarrm4n3_t* arr1, feoarrm4n3_t* arr2, feonumm4n3_t* res);
  void feoarrm4n3_dimCheck_OF_samesize(  oarrm4n3_t* arr1, feoarrm4n3_t* arr2, feonumm4n3_t* res);
  void feoarrm4n3_dimCheck_RF_samesize(   darr_t* arr1, feoarrm4n3_t* arr2, feonumm4n3_t* res);
  void feoarrm4n3_dimCheck_FF_elementwise(feoarrm4n3_t* arr1, feoarrm4n3_t* arr2, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_OF_elementwise(  oarrm4n3_t* arr1, feoarrm4n3_t* arr2, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm4n3_t* arr2, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_fF_elementwise( feonumm4n3_t* num1, feoarrm4n3_t* arr2, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_Ff_elementwise(feoarrm4n3_t* arr1,  feonumm4n3_t* num2, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_FF_matmul( feoarrm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_OF_matmul(   oarrm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_RF_matmul(    darr_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_FO_matmul( feoarrm4n3_t* lhs,   oarrm4n3_t* rhs, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_FR_matmul( feoarrm4n3_t* lhs,    darr_t* rhs, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_F_squareness( feoarrm4n3_t* arr1, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_F_transpose( feoarrm4n3_t* arr1, feoarrm4n3_t* res);
  void feoarrm4n3_dimCheck_FfO_integrate(feoarrm4n3_t* arr, feonumm4n3_t* num,oarrm4n3_t* res);
  void feoarrm4n3_get_active_bases(feoarrm4n3_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n3/array/gauss/algebra.h
  
  feoarrm4n3_t feoarrm4n3_neg(    feoarrm4n3_t* arr);
  void      feoarrm4n3_neg_to( feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sum_FF(   feoarrm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sum_FF_to(feoarrm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sum_fF(    feonumm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sum_fF_to( feonumm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sum_OF(     oarrm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sum_OF_to(  oarrm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sum_RF(      darr_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sum_RF_to(   darr_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sum_oF(   onumm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sum_oF_to(onumm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sum_rF(     coeff_t  lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sum_rF_to(  coeff_t  lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sub_FF(    feoarrm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sub_FF_to( feoarrm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sub_fF(    feonumm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sub_fF_to( feonumm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sub_Ff(    feoarrm4n3_t* lhs, feonumm4n3_t* rhs);
  void      feoarrm4n3_sub_Ff_to( feoarrm4n3_t* lhs, feonumm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sub_OF(      oarrm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sub_OF_to(   oarrm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sub_FO(    feoarrm4n3_t* lhs,   oarrm4n3_t* rhs);
  void      feoarrm4n3_sub_FO_to( feoarrm4n3_t* lhs,   oarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sub_RF(       darr_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sub_RF_to(    darr_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sub_FR(    feoarrm4n3_t* lhs,    darr_t* rhs);
  void      feoarrm4n3_sub_FR_to( feoarrm4n3_t* lhs,    darr_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sub_oF(    onumm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sub_oF_to( onumm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sub_Fo(    feoarrm4n3_t* lhs, onumm4n3_t* rhs);
  void      feoarrm4n3_sub_Fo_to( feoarrm4n3_t* lhs, onumm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sub_rF(      coeff_t  lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_sub_rF_to(    coeff_t lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_sub_Fr(    feoarrm4n3_t* lhs,   coeff_t  rhs);
  void      feoarrm4n3_sub_Fr_to( feoarrm4n3_t* lhs,   coeff_t  rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_mul_FF(   feoarrm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_mul_FF_to(feoarrm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_mul_fF(    feonumm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_mul_fF_to( feonumm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_mul_OF(     oarrm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_mul_OF_to(  oarrm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_mul_RF(      darr_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_mul_RF_to(   darr_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_mul_oF(   onumm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_mul_oF_to(onumm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_mul_rF(     coeff_t  lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_mul_rF_to(  coeff_t  lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_div_FF(    feoarrm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_div_FF_to( feoarrm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_div_fF(     feonumm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_div_fF_to(  feonumm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_div_Ff(    feoarrm4n3_t* lhs,  feonumm4n3_t* rhs);
  void      feoarrm4n3_div_Ff_to( feoarrm4n3_t* lhs,  feonumm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_div_OF(      oarrm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_div_OF_to(   oarrm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_div_FO(    feoarrm4n3_t* lhs,   oarrm4n3_t* rhs);
  void      feoarrm4n3_div_FO_to( feoarrm4n3_t* lhs,   oarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_div_RF(       darr_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_div_RF_to(    darr_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_div_FR(    feoarrm4n3_t* lhs,    darr_t* rhs);
  void      feoarrm4n3_div_FR_to( feoarrm4n3_t* lhs,    darr_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_div_oF(    onumm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_div_oF_to( onumm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_div_Fo(    feoarrm4n3_t* lhs, onumm4n3_t* rhs);
  void      feoarrm4n3_div_Fo_to( feoarrm4n3_t* lhs, onumm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_div_rF(      coeff_t  lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_div_rF_to(    coeff_t lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_div_Fr(    feoarrm4n3_t* lhs,   coeff_t  rhs);
  void      feoarrm4n3_div_Fr_to( feoarrm4n3_t* lhs,   coeff_t  rhs, feoarrm4n3_t* res);
  oarrm4n3_t feoarrm4n3_integrate(    feoarrm4n3_t* arr, feonumm4n3_t* w);
  void    feoarrm4n3_integrate_to( feoarrm4n3_t* arr, feonumm4n3_t* w, oarrm4n3_t* res);
  feonumm4n3_t feoarrm4n3_dotproduct_FF(    feoarrm4n3_t* lhs, feoarrm4n3_t* rhs);
  void     feoarrm4n3_dotproduct_FF_to( feoarrm4n3_t* lhs, feoarrm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feoarrm4n3_dotproduct_OF(      oarrm4n3_t* lhs, feoarrm4n3_t* rhs);
  void     feoarrm4n3_dotproduct_OF_to(   oarrm4n3_t* lhs, feoarrm4n3_t* rhs, feonumm4n3_t* res);
  feonumm4n3_t feoarrm4n3_dotproduct_RF(       darr_t* lhs, feoarrm4n3_t* rhs);
  void     feoarrm4n3_dotproduct_RF_to(    darr_t* lhs, feoarrm4n3_t* rhs, feonumm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_matmul_FF(    feoarrm4n3_t* lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_matmul_FF_to( feoarrm4n3_t* lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_matmul_OF(    oarrm4n3_t*   lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_matmul_OF_to( oarrm4n3_t*   lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_matmul_FO(    feoarrm4n3_t* lhs, oarrm4n3_t*   rhs);
  void      feoarrm4n3_matmul_FO_to( feoarrm4n3_t* lhs, oarrm4n3_t*   rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_matmul_RF(    darr_t*    lhs, feoarrm4n3_t* rhs);
  void      feoarrm4n3_matmul_RF_to( darr_t*    lhs, feoarrm4n3_t* rhs, feoarrm4n3_t* res);
  feoarrm4n3_t feoarrm4n3_matmul_FR(    feoarrm4n3_t* lhs, darr_t*    rhs);
  void      feoarrm4n3_matmul_FR_to( feoarrm4n3_t* lhs, darr_t*    rhs, feoarrm4n3_t* res);
  feonumm4n3_t feoarrm4n3_det(   feoarrm4n3_t* arr);
  void     feoarrm4n3_det_to(feoarrm4n3_t* arr, feonumm4n3_t* res);
  feonumm4n3_t feoarrm4n3_norm(     feoarrm4n3_t* arr);
  void     feoarrm4n3_norm_to(  feoarrm4n3_t* arr, feonumm4n3_t* res);
  feonumm4n3_t feoarrm4n3_pnorm(    feoarrm4n3_t* arr, coeff_t p);
  void     feoarrm4n3_pnorm_to( feoarrm4n3_t* arr, coeff_t p, feonumm4n3_t* res);
  feoarrm4n3_t   feoarrm4n3_invert(    feoarrm4n3_t* arr);
  void        feoarrm4n3_invert_to( feoarrm4n3_t* arr, feoarrm4n3_t* res);
  feoarrm4n3_t   feoarrm4n3_transpose(   feoarrm4n3_t* arr);
  void        feoarrm4n3_transpose_to(feoarrm4n3_t* arr, feoarrm4n3_t* res);
  
  