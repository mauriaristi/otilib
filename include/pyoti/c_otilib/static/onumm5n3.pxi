cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm5n3/scalar/structures.h
  
  ctypedef struct  onumm5n3_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
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
    coeff_t e15;
    coeff_t e25;
    coeff_t e35;
    coeff_t e45;
    coeff_t e55;
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
    coeff_t e115;
    coeff_t e125;
    coeff_t e225;
    coeff_t e135;
    coeff_t e235;
    coeff_t e335;
    coeff_t e145;
    coeff_t e245;
    coeff_t e345;
    coeff_t e445;
    coeff_t e155;
    coeff_t e255;
    coeff_t e355;
    coeff_t e455;
    coeff_t e555;
  # } onumm5n3_t;
  
  
  # From ../../../include/oti/static/onumm5n3/array/structures.h
  
  ctypedef struct  oarrm5n3_t : # {
      onumm5n3_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm5n3_t;
  
  
  # From ../../../include/oti/static/onumm5n3/scalar/gauss/structures.h
  
  ctypedef struct  feonumm5n3_t: # {
      onumm5n3_t*  p_data;
      uint64_t    nip;
  # } feonumm5n3_t;
  
  
  # From ../../../include/oti/static/onumm5n3/array/gauss/structures.h
  
  ctypedef struct  feoarrm5n3_t: # {
      oarrm5n3_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm5n3_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm5n3/scalar/functions.h
  
  onumm5n3_t onumm5n3_atanh(onumm5n3_t* num);
  void onumm5n3_atanh_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_asinh(onumm5n3_t* num);
  void onumm5n3_asinh_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_acosh(onumm5n3_t* num);
  void onumm5n3_acosh_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_tanh(onumm5n3_t* num);
  void onumm5n3_tanh_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_sqrt(onumm5n3_t* num);
  void onumm5n3_sqrt_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_cbrt(onumm5n3_t* num);
  void onumm5n3_cbrt_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_cosh(onumm5n3_t* num);
  void onumm5n3_cosh_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_sinh(onumm5n3_t* num);
  void onumm5n3_sinh_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_asin(onumm5n3_t* num);
  void onumm5n3_asin_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_acos(onumm5n3_t* num);
  void onumm5n3_acos_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_atan(onumm5n3_t* num);
  void onumm5n3_atan_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_tan(onumm5n3_t* num);
  void onumm5n3_tan_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_cos(onumm5n3_t* num);
  void onumm5n3_cos_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_sin(onumm5n3_t* num );
  void onumm5n3_sin_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_logb(onumm5n3_t* num, double base);
  void onumm5n3_logb_to(onumm5n3_t* num, double base, onumm5n3_t* res);
  onumm5n3_t onumm5n3_log10(onumm5n3_t* num);
  void onumm5n3_log10_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_log(onumm5n3_t* num);
  void onumm5n3_log_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_exp(onumm5n3_t* num);
  void onumm5n3_exp_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_pow(onumm5n3_t* num, double e);
  void onumm5n3_pow_to(onumm5n3_t* num, coeff_t e, onumm5n3_t* res);
  
  
  # From ../../../include/oti/static/onumm5n3/scalar/base.h
  
  void onumm5n3_set_im_o(onumm5n3_t* num, imdir_t idx, ord_t order, onumm5n3_t* res);
  void onumm5n3_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm5n3_t* res);
  void onumm5n3_set_deriv_o(onumm5n3_t* num, imdir_t idx, ord_t order, onumm5n3_t* res);
  void onumm5n3_extract_im_to( imdir_t idx, ord_t order, onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_extract_im(imdir_t idx, ord_t order, onumm5n3_t* num);
  onumm5n3_t onumm5n3_extract_deriv(imdir_t idx, ord_t order, onumm5n3_t* num);
  void onumm5n3_extract_deriv_to(imdir_t idx, ord_t order, onumm5n3_t* num, onumm5n3_t* res);
  void onumm5n3_get_im_to_o(imdir_t idx, ord_t order, onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_get_im_o(imdir_t idx, ord_t order, onumm5n3_t* num);
  void onumm5n3_get_im_to_r(imdir_t idx, ord_t order, onumm5n3_t* num, coeff_t* res);
  ord_t onumm5n3_get_order(onumm5n3_t* lhs);
  onumm5n3_t onumm5n3_get_deriv_o( imdir_t idx, ord_t order, onumm5n3_t* num);
  void onumm5n3_get_deriv_to( imdir_t idx, ord_t order, onumm5n3_t* num, onumm5n3_t* res);
  void onumm5n3_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm5n3_t* res);
  onumm5n3_t onumm5n3_init();
  ndir_t onumm5n3_get_ndir_order(ord_t order, onumm5n3_t* num);
  ndir_t onumm5n3_get_ndir_total(onumm5n3_t* num);
  coeff_t* onumm5n3_get_order_address(ord_t order, onumm5n3_t* num);
  onumm5n3_t onumm5n3_create_r(  coeff_t lhs);
  void onumm5n3_set_r(  coeff_t lhs, onumm5n3_t* res);
  void onumm5n3_set_o(  onumm5n3_t* lhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_get_order_im(ord_t order, onumm5n3_t* lhs);
  void onumm5n3_get_order_im_to(ord_t order, onumm5n3_t* lhs, onumm5n3_t* res);
  coeff_t onumm5n3_get_item(imdir_t idx, ord_t order, onumm5n3_t* lhs);
  coeff_t onumm5n3_get_deriv(imdir_t idx, ord_t order, onumm5n3_t* lhs);
  void onumm5n3_set_item(coeff_t val, imdir_t idx, ord_t order, onumm5n3_t* x);
  onumm5n3_t onumm5n3_copy(  onumm5n3_t* lhs);
  void onumm5n3_copy_to(  onumm5n3_t* lhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_taylor_integrate(coeff_t* deltas,onumm5n3_t* lhs);
  void onumm5n3_taylor_integrate_to(coeff_t* deltas,onumm5n3_t* lhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_truncate_im(imdir_t idx, ord_t order, onumm5n3_t* lhs);
  void onumm5n3_truncate_im_to(imdir_t idx, ord_t order, onumm5n3_t* lhs, onumm5n3_t* res);
  void onumm5n3_print(  onumm5n3_t* lhs);
  imdir_t onumm5n3_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm5n3/scalar/utils.h
  
  void onumm5n3_get_active_bases(onumm5n3_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm5n3/scalar/algebra.h
  
  onumm5n3_t onumm5n3_abs(onumm5n3_t* num);
  onumm5n3_t onumm5n3_div_ro(coeff_t num, onumm5n3_t* den);
  onumm5n3_t onumm5n3_div_oo(onumm5n3_t* num, onumm5n3_t* den);
  onumm5n3_t onumm5n3_div_or(onumm5n3_t* num, coeff_t val);
  void onumm5n3_div_ro_to(coeff_t num, onumm5n3_t* den, onumm5n3_t* res);
  void onumm5n3_div_oo_to(onumm5n3_t* num, onumm5n3_t* den, onumm5n3_t* res);
  void onumm5n3_div_or_to(onumm5n3_t* num, coeff_t val, onumm5n3_t* res);
  void onumm5n3_abs_to(onumm5n3_t* num, onumm5n3_t* res);
  onumm5n3_t onumm5n3_neg(  onumm5n3_t* lhs);
  void onumm5n3_neg_to(  onumm5n3_t* lhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_sum_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs);
  void onumm5n3_sum_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_sum_ro(  coeff_t lhs,  onumm5n3_t* rhs);
  void onumm5n3_sum_ro_to(  coeff_t lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_sub_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs);
  void onumm5n3_sub_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_sub_ro(  coeff_t lhs,  onumm5n3_t* rhs);
  void onumm5n3_sub_ro_to(  coeff_t lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_sub_or(  onumm5n3_t* lhs,  coeff_t rhs);
  void onumm5n3_sub_or_to(  onumm5n3_t* lhs,  coeff_t rhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_mul_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs);
  void onumm5n3_mul_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_mul_ro(  coeff_t lhs,  onumm5n3_t* rhs);
  void onumm5n3_mul_ro_to(  coeff_t lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_trunc_mul_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs);
  void onumm5n3_trunc_mul_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_gem_oo(  onumm5n3_t* a,  onumm5n3_t* b,  onumm5n3_t* c);
  void onumm5n3_gem_oo_to(  onumm5n3_t* a,  onumm5n3_t* b,  onumm5n3_t* c, onumm5n3_t* res);
  onumm5n3_t onumm5n3_gem_ro(  coeff_t a,  onumm5n3_t* b,  onumm5n3_t* c);
  void onumm5n3_gem_ro_to(  coeff_t a,  onumm5n3_t* b,  onumm5n3_t* c, onumm5n3_t* res);
  void onumm5n3_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n3_t* a,  ord_t ord_rhs,  onumm5n3_t* b,  onumm5n3_t* c, onumm5n3_t* res);
  void onumm5n3_trunc_sum_oo_to(ord_t order, onumm5n3_t* lhs,onumm5n3_t* rhs, onumm5n3_t* res);
  void onumm5n3_trunc_sub_oo_to(ord_t order, onumm5n3_t* lhs,onumm5n3_t* rhs, onumm5n3_t* res);
  onumm5n3_t onumm5n3_feval(coeff_t* feval_re, onumm5n3_t* x);
  void onumm5n3_feval_to(coeff_t* feval_re, onumm5n3_t* x, onumm5n3_t* res);
  
  
  # From ../../../include/oti/static/onumm5n3/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm5n3/scalar/gauss/functions.h
  
  feonumm5n3_t feonumm5n3_atanh(    feonumm5n3_t* num);
  void     feonumm5n3_atanh_to( feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_asinh(    feonumm5n3_t* num);
  void     feonumm5n3_asinh_to( feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_acosh(    feonumm5n3_t* num);
  void     feonumm5n3_acosh_to( feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_tanh(     feonumm5n3_t* num);
  void     feonumm5n3_tanh_to(  feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_cosh(     feonumm5n3_t* num);
  void     feonumm5n3_cosh_to(  feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_sinh(     feonumm5n3_t* num);
  void     feonumm5n3_sinh_to(  feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_asin(     feonumm5n3_t* num);
  void     feonumm5n3_asin_to(  feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_acos(     feonumm5n3_t* num);
  void     feonumm5n3_acos_to(  feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_atan(     feonumm5n3_t* num);
  void     feonumm5n3_atan_to(  feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_tan(      feonumm5n3_t* num);
  void     feonumm5n3_tan_to(   feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_cos(      feonumm5n3_t* num);
  void     feonumm5n3_cos_to(   feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_sin(      feonumm5n3_t* num);
  void     feonumm5n3_sin_to(   feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_logb(     feonumm5n3_t* num, double base);
  void     feonumm5n3_logb_to(  feonumm5n3_t* num, double base, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_log10(    feonumm5n3_t* num);
  void     feonumm5n3_log10_to( feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_log(      feonumm5n3_t* num);
  void     feonumm5n3_log_to(   feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_exp(      feonumm5n3_t* num);
  void     feonumm5n3_exp_to(   feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_cbrt(     feonumm5n3_t* num);
  void     feonumm5n3_cbrt_to(  feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_sqrt(     feonumm5n3_t* num);
  void     feonumm5n3_sqrt_to(  feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_pow(      feonumm5n3_t* num, double e);
  void     feonumm5n3_pow_to(   feonumm5n3_t* num, double e, feonumm5n3_t* res);
  onumm5n3_t feonumm5n3_integrate(       feonumm5n3_t* num, feonumm5n3_t* w);
  void      feonumm5n3_integrate_to(    feonumm5n3_t* num, feonumm5n3_t* w, onumm5n3_t* res);
  onumm5n3_t feonumm5n3_integrate_f(     feonumm5n3_t* num, feonumm5n3_t* w);
  void      feonumm5n3_integrate_f_to(  feonumm5n3_t* num, feonumm5n3_t* w, onumm5n3_t* res);
  onumm5n3_t feonumm5n3_integrate_r(       coeff_t num, feonumm5n3_t* w);
  void      feonumm5n3_integrate_r_to(    coeff_t num, feonumm5n3_t* w, onumm5n3_t* res);
  onumm5n3_t feonumm5n3_integrate_o(    onumm5n3_t* num, feonumm5n3_t* w);
  void      feonumm5n3_integrate_o_to( onumm5n3_t* num, feonumm5n3_t* w, onumm5n3_t* res);
  
  
  # From ../../../include/oti/static/onumm5n3/scalar/gauss/base.h
  
  void     feonumm5n3_get_order_im_to( ord_t order, feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_get_order_im(    ord_t order, feonumm5n3_t* num);
  feonumm5n3_t feonumm5n3_get_im(    imdir_t idx, ord_t order, feonumm5n3_t* num);
  void     feonumm5n3_get_im_to( imdir_t idx, ord_t order, feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_get_deriv(    imdir_t idx, ord_t order, feonumm5n3_t* num);
  void     feonumm5n3_get_deriv_to( imdir_t idx, ord_t order, feonumm5n3_t* num, feonumm5n3_t* res);
  void feonumm5n3_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm5n3_t* num);
  void feonumm5n3_set_im_o( onumm5n3_t* val, imdir_t idx, ord_t order, feonumm5n3_t* num);
  void feonumm5n3_set_im_f(  feonumm5n3_t* val, imdir_t idx, ord_t order, feonumm5n3_t* num);
  void feonumm5n3_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm5n3_t* num);
  void feonumm5n3_set_deriv_o( onumm5n3_t* val, imdir_t idx, ord_t order, feonumm5n3_t* num);
  void feonumm5n3_set_deriv_f(  feonumm5n3_t* val, imdir_t idx, ord_t order, feonumm5n3_t* num);
  feonumm5n3_t feonumm5n3_extract_im(    imdir_t idx, ord_t order, feonumm5n3_t* num);
  void     feonumm5n3_extract_im_to( imdir_t idx, ord_t order, feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_extract_deriv(    imdir_t idx, ord_t order, feonumm5n3_t* num);
  void     feonumm5n3_extract_deriv_to( imdir_t idx, ord_t order, feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_truncate_im(    imdir_t idx, ord_t order, feonumm5n3_t* num);
  void     feonumm5n3_truncate_im_to( imdir_t idx, ord_t order, feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_copy(    feonumm5n3_t* src);
  void     feonumm5n3_copy_to( feonumm5n3_t* src, feonumm5n3_t* dst);
  void feonumm5n3_set_r(    coeff_t num, feonumm5n3_t* res);
  void feonumm5n3_set_o( onumm5n3_t* num, feonumm5n3_t* res);
  void feonumm5n3_set_f(  feonumm5n3_t* num, feonumm5n3_t* res);
  void feonumm5n3_set_item_k_r(   coeff_t  num, uint64_t k, feonumm5n3_t* res);
  void feonumm5n3_set_item_k_o( onumm5n3_t* num, uint64_t k, feonumm5n3_t* res);
  onumm5n3_t feonumm5n3_get_item_k(   feonumm5n3_t* num, uint64_t k);
  void      feonumm5n3_get_item_k_to(feonumm5n3_t* num, uint64_t k, onumm5n3_t* res);
  feonumm5n3_t feonumm5n3_zeros(uint64_t nIntPts);
  feonumm5n3_t feonumm5n3_createEmpty(uint64_t nIntPts);
  feonumm5n3_t feonumm5n3_empty_like(feonumm5n3_t* arr);
  void feonumm5n3_free(feonumm5n3_t* num);
  ord_t feonumm5n3_get_order( feonumm5n3_t* num );
  feonumm5n3_t feonumm5n3_init();
  
  
  # From ../../../include/oti/static/onumm5n3/scalar/gauss/utils.h
  
  void feonumm5n3_dimCheck(feonumm5n3_t* arr1,feonumm5n3_t* arr2);
  void feonumm5n3_get_active_bases(feonumm5n3_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n3/scalar/gauss/algebra.h
  
  feonumm5n3_t feonumm5n3_neg(   feonumm5n3_t* num);
  void     feonumm5n3_neg_to(feonumm5n3_t* num, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_sum_ff(   feonumm5n3_t* lhs, feonumm5n3_t* rhs);
  void     feonumm5n3_sum_ff_to(feonumm5n3_t* lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_sum_of(   onumm5n3_t* lhs, feonumm5n3_t* rhs);
  void     feonumm5n3_sum_of_to(onumm5n3_t* lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_sum_rf(   coeff_t lhs, feonumm5n3_t* rhs);
  void     feonumm5n3_sum_rf_to(coeff_t lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_sub_ff(     feonumm5n3_t* lhs,  feonumm5n3_t* rhs);
  void     feonumm5n3_sub_ff_to(  feonumm5n3_t* lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_sub_of(    onumm5n3_t* lhs,  feonumm5n3_t* rhs);
  void     feonumm5n3_sub_of_to( onumm5n3_t* lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_sub_fo(     feonumm5n3_t* lhs, onumm5n3_t* rhs);
  void     feonumm5n3_sub_fo_to(  feonumm5n3_t* lhs, onumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_sub_rf(       coeff_t lhs,  feonumm5n3_t* rhs);
  void     feonumm5n3_sub_rf_to(    coeff_t lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_sub_fr(     feonumm5n3_t* lhs,    coeff_t rhs);
  void     feonumm5n3_sub_fr_to(  feonumm5n3_t* lhs,    coeff_t rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_mul_ff(   feonumm5n3_t* lhs, feonumm5n3_t* rhs);
  void     feonumm5n3_mul_ff_to(feonumm5n3_t* lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_mul_of(   onumm5n3_t* lhs, feonumm5n3_t* rhs);
  void     feonumm5n3_mul_of_to(onumm5n3_t* lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_mul_rf(   coeff_t lhs, feonumm5n3_t* rhs);
  void     feonumm5n3_mul_rf_to(coeff_t lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_div_ff(     feonumm5n3_t* lhs,  feonumm5n3_t* rhs);
  void     feonumm5n3_div_ff_to(  feonumm5n3_t* lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_div_of(    onumm5n3_t* lhs,  feonumm5n3_t* rhs);
  void     feonumm5n3_div_of_to( onumm5n3_t* lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_div_fo(     feonumm5n3_t* lhs, onumm5n3_t* rhs);
  void     feonumm5n3_div_fo_to(  feonumm5n3_t* lhs, onumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_div_rf(       coeff_t lhs,  feonumm5n3_t* rhs);
  void     feonumm5n3_div_rf_to(    coeff_t lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feonumm5n3_div_fr(     feonumm5n3_t* lhs,    coeff_t rhs);
  void     feonumm5n3_div_fr_to(  feonumm5n3_t* lhs,    coeff_t rhs, feonumm5n3_t* res);
  
  
  # From ../../../include/oti/static/onumm5n3/array/functions.h
  
  oarrm5n3_t oarrm5n3_atanh(   oarrm5n3_t* arr);
  void    oarrm5n3_atanh_to(oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_asinh(   oarrm5n3_t* arr);
  void    oarrm5n3_asinh_to(oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_acosh(   oarrm5n3_t* arr);
  void    oarrm5n3_acosh_to(oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_tanh(    oarrm5n3_t* arr);
  void    oarrm5n3_tanh_to( oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_cbrt(    oarrm5n3_t* arr);
  void    oarrm5n3_cbrt_to( oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_sqrt(    oarrm5n3_t* arr);
  void    oarrm5n3_sqrt_to( oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_cosh(    oarrm5n3_t* arr);
  void    oarrm5n3_cosh_to( oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_sinh(    oarrm5n3_t* arr);
  void    oarrm5n3_sinh_to( oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_asin(    oarrm5n3_t* arr);
  void    oarrm5n3_asin_to( oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_acos(    oarrm5n3_t* arr);
  void    oarrm5n3_acos_to( oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_atan(    oarrm5n3_t* arr);
  void    oarrm5n3_atan_to( oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_tan(     oarrm5n3_t* arr);
  void    oarrm5n3_tan_to(  oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_cos(     oarrm5n3_t* arr);
  void    oarrm5n3_cos_to(  oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_sin(     oarrm5n3_t* arr);
  void    oarrm5n3_sin_to(  oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_logb(    oarrm5n3_t* arr, double base);
  void    oarrm5n3_logb_to( oarrm5n3_t* arr, double base, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_log10(   oarrm5n3_t* arr);
  void    oarrm5n3_log10_to(oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_log(     oarrm5n3_t* arr);
  void    oarrm5n3_log_to(  oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_exp(     oarrm5n3_t* arr);
  void    oarrm5n3_exp_to(  oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_pow(     oarrm5n3_t* arr, double e);
  void    oarrm5n3_pow_to(  oarrm5n3_t* arr, double e, oarrm5n3_t* res);
  
  
  # From ../../../include/oti/static/onumm5n3/array/algebra_elementwise.h
  
  oarrm5n3_t oarrm5n3_neg(oarrm5n3_t* arr);
  void oarrm5n3_neg_to(oarrm5n3_t* rhs, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_sum_OO(oarrm5n3_t*   lhs, oarrm5n3_t* rhs);
  oarrm5n3_t oarrm5n3_sum_RO(darr_t*    lhs, oarrm5n3_t* rhs);
  oarrm5n3_t oarrm5n3_sum_oO(onumm5n3_t* lhs, oarrm5n3_t* rhs);
  oarrm5n3_t oarrm5n3_sum_rO(coeff_t    lhs, oarrm5n3_t* rhs);
  void oarrm5n3_sum_OO_to(oarrm5n3_t*   lhs, oarrm5n3_t* rhs, oarrm5n3_t* res);
  void oarrm5n3_sum_RO_to(darr_t*    lhs, oarrm5n3_t* rhs, oarrm5n3_t* res);
  void oarrm5n3_sum_oO_to(onumm5n3_t* lhs, oarrm5n3_t* rhs, oarrm5n3_t* res);
  void oarrm5n3_sum_rO_to(coeff_t    lhs, oarrm5n3_t* rhs, oarrm5n3_t* res);
  void oarrm5n3_trunc_sum_OO_to(ord_t order, oarrm5n3_t* arr1, oarrm5n3_t* arr2, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_sub_OO(oarrm5n3_t*   lhs, oarrm5n3_t*   rhs);
  oarrm5n3_t oarrm5n3_sub_RO(darr_t*    lhs, oarrm5n3_t*   rhs);
  oarrm5n3_t oarrm5n3_sub_OR(oarrm5n3_t*   lhs, darr_t*    rhs);
  oarrm5n3_t oarrm5n3_sub_oO(onumm5n3_t* lhs, oarrm5n3_t*   rhs);
  oarrm5n3_t oarrm5n3_sub_Oo(oarrm5n3_t*   lhs, onumm5n3_t* rhs);
  oarrm5n3_t oarrm5n3_sub_rO(coeff_t    lhs, oarrm5n3_t*   rhs);
  oarrm5n3_t oarrm5n3_sub_Or(oarrm5n3_t*   lhs, coeff_t    rhs);
  void oarrm5n3_sub_OO_to( oarrm5n3_t*   lhs, oarrm5n3_t*   rhs, oarrm5n3_t* res);
  void oarrm5n3_sub_RO_to( darr_t*    lhs, oarrm5n3_t*   rhs, oarrm5n3_t* res);
  void oarrm5n3_sub_OR_to( oarrm5n3_t*   lhs, darr_t*    rhs, oarrm5n3_t* res);
  void oarrm5n3_sub_oO_to( onumm5n3_t* lhs, oarrm5n3_t*   rhs, oarrm5n3_t* res);
  void oarrm5n3_sub_Oo_to( oarrm5n3_t*   lhs, onumm5n3_t* rhs, oarrm5n3_t* res);
  void oarrm5n3_sub_rO_to( coeff_t    lhs, oarrm5n3_t*   rhs, oarrm5n3_t* res);
  void oarrm5n3_sub_Or_to( oarrm5n3_t*   lhs, coeff_t    rhs, oarrm5n3_t* res);
  void oarrm5n3_trunc_sub_OO_to(ord_t order, oarrm5n3_t* arr1, oarrm5n3_t* arr2, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_mul_OO(oarrm5n3_t*   lhs, oarrm5n3_t* rhs);
  oarrm5n3_t oarrm5n3_mul_RO(darr_t*    lhs, oarrm5n3_t* rhs);
  oarrm5n3_t oarrm5n3_mul_oO(onumm5n3_t* lhs, oarrm5n3_t* rhs);
  oarrm5n3_t oarrm5n3_mul_rO(coeff_t    lhs, oarrm5n3_t* rhs);
  void oarrm5n3_mul_OO_to(oarrm5n3_t*   lhs, oarrm5n3_t* rhs, oarrm5n3_t* res);
  void oarrm5n3_mul_RO_to(darr_t*    lhs, oarrm5n3_t* rhs, oarrm5n3_t* res);
  void oarrm5n3_mul_oO_to(onumm5n3_t* lhs, oarrm5n3_t* rhs, oarrm5n3_t* res);
  void oarrm5n3_mul_rO_to(coeff_t    lhs, oarrm5n3_t* rhs, oarrm5n3_t* res);
  void oarrm5n3_gem_OO_to(  oarrm5n3_t* arr1, oarrm5n3_t* arr2, oarrm5n3_t* arr3, oarrm5n3_t* res);
  void oarrm5n3_gem_oO_to(onumm5n3_t* arr1, oarrm5n3_t* arr2, oarrm5n3_t* arr3, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_div_OO(oarrm5n3_t*   lhs, oarrm5n3_t*   rhs);
  oarrm5n3_t oarrm5n3_div_OR(oarrm5n3_t*   lhs, darr_t*    rhs);
  oarrm5n3_t oarrm5n3_div_RO(darr_t*    lhs, oarrm5n3_t*   rhs);
  oarrm5n3_t oarrm5n3_div_oO(onumm5n3_t* lhs, oarrm5n3_t*   rhs);
  oarrm5n3_t oarrm5n3_div_Oo(oarrm5n3_t*   lhs, onumm5n3_t* rhs);
  oarrm5n3_t oarrm5n3_div_rO(coeff_t    lhs, oarrm5n3_t*   rhs);
  oarrm5n3_t oarrm5n3_div_Or(oarrm5n3_t*   lhs, coeff_t    rhs);
  void oarrm5n3_div_OO_to(oarrm5n3_t*   lhs, oarrm5n3_t*   rhs, oarrm5n3_t* res);
  void oarrm5n3_div_RO_to(darr_t*    lhs, oarrm5n3_t*   rhs, oarrm5n3_t* res);
  void oarrm5n3_div_OR_to(oarrm5n3_t*   lhs, darr_t*    rhs, oarrm5n3_t* res);
  void oarrm5n3_div_oO_to(onumm5n3_t* lhs, oarrm5n3_t*   rhs, oarrm5n3_t* res);
  void oarrm5n3_div_Oo_to(oarrm5n3_t*   lhs, onumm5n3_t* rhs, oarrm5n3_t* res);
  void oarrm5n3_div_rO_to(coeff_t    lhs, oarrm5n3_t*   rhs, oarrm5n3_t* res);
  void oarrm5n3_div_Or_to(oarrm5n3_t*   lhs, coeff_t    rhs, oarrm5n3_t* res);
  
  
  # From ../../../include/oti/static/onumm5n3/array/base.h
  
  void    oarrm5n3_taylor_integrate_to( coeff_t* deltas, oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_taylor_integrate(    coeff_t* deltas, oarrm5n3_t* arr);
  void    oarrm5n3_get_order_im_to( ord_t order, oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_get_order_im(    ord_t order, oarrm5n3_t* arr);
  void oarrm5n3_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n3_t* res);
  void oarrm5n3_set_slice_O( oarrm5n3_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n3_t* res);
  void oarrm5n3_set_slice_o( onumm5n3_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_get_slice( oarrm5n3_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm5n3_get_slice_to( oarrm5n3_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_truncate_im(    imdir_t idx, ord_t order, oarrm5n3_t* arr);
  void    oarrm5n3_truncate_im_to( imdir_t idx, ord_t order, oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_extract_im(   imdir_t idx, ord_t order, oarrm5n3_t* arr);
  void    oarrm5n3_extract_im_to(imdir_t idx, ord_t order, oarrm5n3_t* arr, oarrm5n3_t* res);
  darr_t  oarrm5n3_get_deriv(    imdir_t idx, ord_t order, oarrm5n3_t* arr);
  void    oarrm5n3_get_deriv_to( imdir_t idx, ord_t order, oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_get_deriv_o(  imdir_t idx, ord_t order, oarrm5n3_t* arr);
  oarrm5n3_t oarrm5n3_extract_deriv(    imdir_t idx, ord_t order, oarrm5n3_t* arr);
  void    oarrm5n3_extract_deriv_to( imdir_t idx, ord_t order, oarrm5n3_t* arr, oarrm5n3_t* res);
  darr_t  oarrm5n3_get_im(   imdir_t idx, ord_t order, oarrm5n3_t* arr);
  oarrm5n3_t oarrm5n3_get_im_o( imdir_t idx, ord_t order, oarrm5n3_t* arr);
  void    oarrm5n3_get_im_to(imdir_t idx, ord_t order, oarrm5n3_t* arr, oarrm5n3_t* res);
  void    oarrm5n3_copy_to(oarrm5n3_t* arr, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_copy(oarrm5n3_t* arr);
  void oarrm5n3_set_all_r( coeff_t num, oarrm5n3_t* arr);
  void oarrm5n3_set_item_i_r( coeff_t num, uint64_t i, oarrm5n3_t* arr);
  void oarrm5n3_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm5n3_t* arr);
  void oarrm5n3_set_r(   coeff_t  num,   oarrm5n3_t* arr);
  void oarrm5n3_set_o( onumm5n3_t* num,   oarrm5n3_t* arr);
  void oarrm5n3_set_O(   oarrm5n3_t* arrin, oarrm5n3_t* arr);
  void oarrm5n3_set_all_o( onumm5n3_t* src, oarrm5n3_t* arr);
  void oarrm5n3_set_item_i_o( onumm5n3_t* num, uint64_t i, oarrm5n3_t* arr);
  void oarrm5n3_set_item_ij_o( onumm5n3_t* num, uint64_t i, uint64_t j, oarrm5n3_t* arr);
  onumm5n3_t oarrm5n3_get_item_i(    oarrm5n3_t* arr, uint64_t i);
  void      oarrm5n3_get_item_i_to( oarrm5n3_t* arr, uint64_t i,             onumm5n3_t* res);
  onumm5n3_t oarrm5n3_get_item_ij(   oarrm5n3_t* arr, uint64_t i, uint64_t j);
  void      oarrm5n3_get_item_ij_to(oarrm5n3_t* arr, uint64_t i, uint64_t j, onumm5n3_t* res);
  oarrm5n3_t oarrm5n3_init();
  void oarrm5n3_free(oarrm5n3_t* arr);
  oarrm5n3_t oarrm5n3_empty_like(oarrm5n3_t* arr);
  oarrm5n3_t oarrm5n3_eye(uint64_t nrows);
  oarrm5n3_t oarrm5n3_ones(uint64_t nrows, uint64_t ncols);
  oarrm5n3_t oarrm5n3_zeros(uint64_t nrows, uint64_t ncols);
  oarrm5n3_t oarrm5n3_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm5n3/array/utils.h
  
  void oarrm5n3_dimCheck_OO_elementwise(oarrm5n3_t* arr1, oarrm5n3_t* arr2, oarrm5n3_t* res);
  void oarrm5n3_dimCheck_RO_elementwise(darr_t*  arr1, oarrm5n3_t* arr2, oarrm5n3_t* res);
  void oarrm5n3_dimCheck_OO_matmul(oarrm5n3_t* arr1, oarrm5n3_t* arr2, oarrm5n3_t* res);
  void oarrm5n3_dimCheck_RO_matmul(darr_t*  arr1, oarrm5n3_t* arr2, oarrm5n3_t* res);
  void oarrm5n3_dimCheck_OR_matmul(oarrm5n3_t* arr1, darr_t*  arr2, oarrm5n3_t* res);
  void oarrm5n3_dimCheck_O_squareness(oarrm5n3_t* arr1, oarrm5n3_t* res);
  void oarrm5n3_dimCheck_OO_samesize(oarrm5n3_t* arr1, oarrm5n3_t* res);
  void oarrm5n3_dimCheck_RO_samesize(darr_t* arr1, oarrm5n3_t* res);
  ord_t oarrm5n3_get_order(oarrm5n3_t* arr);
  void oarrm5n3_get_active_bases(oarrm5n3_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n3/array/algebra_matops.h
  
  onumm5n3_t oarrm5n3_dotproduct_OO(    oarrm5n3_t* lhs, oarrm5n3_t* rhs);
  void      oarrm5n3_dotproduct_OO_to( oarrm5n3_t* lhs, oarrm5n3_t* rhs, onumm5n3_t* res);
  onumm5n3_t oarrm5n3_dotproduct_RO(     darr_t* lhs, oarrm5n3_t* rhs);
  void      oarrm5n3_dotproduct_RO_to(  darr_t* lhs, oarrm5n3_t* rhs, onumm5n3_t* res);
  oarrm5n3_t oarrm5n3_matmul_OO(    oarrm5n3_t* lhs, oarrm5n3_t* rhs);
  oarrm5n3_t oarrm5n3_matmul_OR(    oarrm5n3_t* lhs,  darr_t* rhs);
  oarrm5n3_t oarrm5n3_matmul_RO(     darr_t* lhs, oarrm5n3_t* rhs);
  void    oarrm5n3_matmul_OO_to( oarrm5n3_t* lhs, oarrm5n3_t* rhs, oarrm5n3_t* res);
  void    oarrm5n3_matmul_OR_to( oarrm5n3_t* lhs,  darr_t* rhs, oarrm5n3_t* res);
  void    oarrm5n3_matmul_RO_to(  darr_t* lhs, oarrm5n3_t* rhs, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_transpose(    oarrm5n3_t* arr1);
  void    oarrm5n3_transpose_to( oarrm5n3_t* arr1, oarrm5n3_t* res);
  oarrm5n3_t oarrm5n3_invert(    oarrm5n3_t* arr1);
  void    oarrm5n3_invert_to( oarrm5n3_t* arr1, oarrm5n3_t* res);
  onumm5n3_t oarrm5n3_det(    oarrm5n3_t* arr1);
  void      oarrm5n3_det_to( oarrm5n3_t* arr1, onumm5n3_t* res);
  onumm5n3_t oarrm5n3_norm(    oarrm5n3_t* arr1);
  void      oarrm5n3_norm_to( oarrm5n3_t* arr1,  onumm5n3_t* res);
  onumm5n3_t oarrm5n3_pnorm(    oarrm5n3_t* arr1, coeff_t p);
  void      oarrm5n3_pnorm_to( oarrm5n3_t* arr1, coeff_t p, onumm5n3_t* res);
  
  
  # From ../../../include/oti/static/onumm5n3/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm5n3/array/gauss/functions.h
  
  feoarrm5n3_t feoarrm5n3_atanh(    feoarrm5n3_t* arr);
  void      feoarrm5n3_atanh_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_asinh(    feoarrm5n3_t* arr);
  void      feoarrm5n3_asinh_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_acosh(    feoarrm5n3_t* arr);
  void      feoarrm5n3_acosh_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_tanh(     feoarrm5n3_t* arr);
  void      feoarrm5n3_tanh_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sinh(     feoarrm5n3_t* arr);
  void      feoarrm5n3_sinh_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_cosh(     feoarrm5n3_t* arr);
  void      feoarrm5n3_cosh_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_atan(     feoarrm5n3_t* arr);
  void      feoarrm5n3_atan_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_asin(     feoarrm5n3_t* arr);
  void      feoarrm5n3_asin_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_acos(     feoarrm5n3_t* arr);
  void      feoarrm5n3_acos_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_tan(      feoarrm5n3_t* arr);
  void      feoarrm5n3_tan_to(   feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sin(      feoarrm5n3_t* arr);
  void      feoarrm5n3_sin_to(   feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_cos(      feoarrm5n3_t* arr);
  void      feoarrm5n3_cos_to(   feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_logb(     feoarrm5n3_t* arr, double base);
  void      feoarrm5n3_logb_to(  feoarrm5n3_t* arr, double base, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_log10(    feoarrm5n3_t* arr);
  void      feoarrm5n3_log10_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_log(      feoarrm5n3_t* arr);
  void      feoarrm5n3_log_to(   feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_exp(      feoarrm5n3_t* arr);
  void      feoarrm5n3_exp_to(   feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_cbrt(     feoarrm5n3_t* arr);
  void      feoarrm5n3_cbrt_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sqrt(     feoarrm5n3_t* arr);
  void      feoarrm5n3_sqrt_to(  feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_pow(      feoarrm5n3_t* arr, double e);
  void      feoarrm5n3_pow_to(   feoarrm5n3_t* arr, double e, feoarrm5n3_t* res);
  
  
  # From ../../../include/oti/static/onumm5n3/array/gauss/base.h
  
  void      feoarrm5n3_get_order_im_to( ord_t order, feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_get_order_im(    ord_t order, feoarrm5n3_t* arr);
  feoarrm5n3_t feoarrm5n3_get_deriv(   imdir_t idx, ord_t order, feoarrm5n3_t* arr);
  void      feoarrm5n3_get_deriv_to(imdir_t idx, ord_t order, feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_get_im(      imdir_t idx, ord_t order, feoarrm5n3_t* arr);
  void      feoarrm5n3_get_im_to(   imdir_t idx, ord_t order, feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_truncate_im(   imdir_t idx, ord_t order, feoarrm5n3_t* arr);
  void      feoarrm5n3_truncate_im_to(imdir_t idx, ord_t order, feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_copy(   feoarrm5n3_t* src);
  void      feoarrm5n3_copy_to(feoarrm5n3_t* src, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_get_im(    imdir_t idx, ord_t order, feoarrm5n3_t* arr);
  void      feoarrm5n3_get_im_to( imdir_t idx, ord_t order, feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_get_deriv(    imdir_t idx, ord_t order, feoarrm5n3_t* arr);
  void      feoarrm5n3_get_deriv_to( imdir_t idx, ord_t order, feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_extract_im(    imdir_t idx, ord_t order, feoarrm5n3_t* arr);
  void      feoarrm5n3_extract_im_to( imdir_t idx, ord_t order, feoarrm5n3_t* arr,  feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_extract_deriv(    imdir_t idx, ord_t order, feoarrm5n3_t* arr);
  void      feoarrm5n3_extract_deriv_to( imdir_t idx, ord_t order, feoarrm5n3_t* arr, feoarrm5n3_t* res);
  oarrm5n3_t   feoarrm5n3_get_item_k(  feoarrm5n3_t* arr, uint64_t k);
  feonumm5n3_t  feoarrm5n3_get_item_ij( feoarrm5n3_t* arr, uint64_t i, uint64_t j);
  onumm5n3_t feoarrm5n3_get_item_ijk(feoarrm5n3_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm5n3_get_item_ij_to(  feoarrm5n3_t* arr, uint64_t i, uint64_t j,
                                 feonumm5n3_t* res);
  void feoarrm5n3_get_item_k_to(   feoarrm5n3_t* arr, uint64_t k,
                                  oarrm5n3_t* res);
  void feoarrm5n3_get_item_ijk_to( feoarrm5n3_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_get_slice(feoarrm5n3_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm5n3_get_slice_to(feoarrm5n3_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n3_t* res);
  void feoarrm5n3_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm5n3_t* res);
  void feoarrm5n3_set_item_ij_o(  onumm5n3_t* elm, uint64_t i, uint64_t j,
                               feoarrm5n3_t* res);
  void feoarrm5n3_set_item_ij_f(  feonumm5n3_t* elm, uint64_t i, uint64_t j,
                              feoarrm5n3_t* res);
  void feoarrm5n3_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm5n3_t* res);
  void feoarrm5n3_set_item_k_o(  onumm5n3_t* elm, uint64_t k,
                              feoarrm5n3_t* res);
  void feoarrm5n3_set_item_k_R(    oarrm5n3_t* elm, uint64_t k,
                            feoarrm5n3_t* res);
  void feoarrm5n3_set_item_k_O(    oarrm5n3_t* elm, uint64_t k,
                            feoarrm5n3_t* res);
  void feoarrm5n3_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm5n3_t* res);
  void feoarrm5n3_set_item_ijk_o( onumm5n3_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm5n3_t* res);
  void feoarrm5n3_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n3_t* res);
  void feoarrm5n3_set_slice_o( onumm5n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n3_t* res);
  void feoarrm5n3_set_slice_f( feonumm5n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n3_t* res);
  void feoarrm5n3_set_slice_O( oarrm5n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n3_t* res);
  void feoarrm5n3_set_slice_F( feoarrm5n3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n3_t* res);
  void feoarrm5n3_set_all_o( onumm5n3_t* num, feoarrm5n3_t* arr );
  void feoarrm5n3_set_all_r(   coeff_t  num, feoarrm5n3_t* arr );
  void feoarrm5n3_set_all_f(  feonumm5n3_t* num, feoarrm5n3_t* arr );
  void feoarrm5n3_set_r(    coeff_t src, feoarrm5n3_t* res );
  void feoarrm5n3_set_o( onumm5n3_t* src, feoarrm5n3_t* res );
  void feoarrm5n3_set_f(  feonumm5n3_t* src, feoarrm5n3_t* res );
  void feoarrm5n3_set_R(    darr_t* src, feoarrm5n3_t* res );
  void feoarrm5n3_set_O(   oarrm5n3_t* src, feoarrm5n3_t* res );
  void feoarrm5n3_set_F( feoarrm5n3_t* src, feoarrm5n3_t* res );
  feoarrm5n3_t feoarrm5n3_eye( uint64_t size,  uint64_t nip);
  feoarrm5n3_t feoarrm5n3_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm5n3_t feoarrm5n3_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm5n3_t feoarrm5n3_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm5n3_free(feoarrm5n3_t* arr);
  feoarrm5n3_t feoarrm5n3_init();
  ord_t feoarrm5n3_get_order(feoarrm5n3_t* arr);
  
  
  # From ../../../include/oti/static/onumm5n3/array/gauss/utils.h
  
  void feoarrm5n3_dimCheck_FF_samesize(feoarrm5n3_t* arr1, feoarrm5n3_t* arr2, feonumm5n3_t* res);
  void feoarrm5n3_dimCheck_OF_samesize(  oarrm5n3_t* arr1, feoarrm5n3_t* arr2, feonumm5n3_t* res);
  void feoarrm5n3_dimCheck_RF_samesize(   darr_t* arr1, feoarrm5n3_t* arr2, feonumm5n3_t* res);
  void feoarrm5n3_dimCheck_FF_elementwise(feoarrm5n3_t* arr1, feoarrm5n3_t* arr2, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_OF_elementwise(  oarrm5n3_t* arr1, feoarrm5n3_t* arr2, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm5n3_t* arr2, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_fF_elementwise( feonumm5n3_t* num1, feoarrm5n3_t* arr2, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_Ff_elementwise(feoarrm5n3_t* arr1,  feonumm5n3_t* num2, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_FF_matmul( feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_OF_matmul(   oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_RF_matmul(    darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_FO_matmul( feoarrm5n3_t* lhs,   oarrm5n3_t* rhs, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_FR_matmul( feoarrm5n3_t* lhs,    darr_t* rhs, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_F_squareness( feoarrm5n3_t* arr1, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_F_transpose( feoarrm5n3_t* arr1, feoarrm5n3_t* res);
  void feoarrm5n3_dimCheck_FfO_integrate(feoarrm5n3_t* arr, feonumm5n3_t* num,oarrm5n3_t* res);
  void feoarrm5n3_get_active_bases(feoarrm5n3_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n3/array/gauss/algebra.h
  
  feoarrm5n3_t feoarrm5n3_neg(    feoarrm5n3_t* arr);
  void      feoarrm5n3_neg_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sum_FF(   feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sum_FF_to(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sum_fF(    feonumm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sum_fF_to( feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sum_OF(     oarrm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sum_OF_to(  oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sum_RF(      darr_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sum_RF_to(   darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sum_oF(   onumm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sum_oF_to(onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sum_rF(     coeff_t  lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sum_rF_to(  coeff_t  lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sub_FF(    feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sub_FF_to( feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sub_fF(    feonumm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sub_fF_to( feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sub_Ff(    feoarrm5n3_t* lhs, feonumm5n3_t* rhs);
  void      feoarrm5n3_sub_Ff_to( feoarrm5n3_t* lhs, feonumm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sub_OF(      oarrm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sub_OF_to(   oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sub_FO(    feoarrm5n3_t* lhs,   oarrm5n3_t* rhs);
  void      feoarrm5n3_sub_FO_to( feoarrm5n3_t* lhs,   oarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sub_RF(       darr_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sub_RF_to(    darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sub_FR(    feoarrm5n3_t* lhs,    darr_t* rhs);
  void      feoarrm5n3_sub_FR_to( feoarrm5n3_t* lhs,    darr_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sub_oF(    onumm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sub_oF_to( onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sub_Fo(    feoarrm5n3_t* lhs, onumm5n3_t* rhs);
  void      feoarrm5n3_sub_Fo_to( feoarrm5n3_t* lhs, onumm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sub_rF(      coeff_t  lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_sub_rF_to(    coeff_t lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_sub_Fr(    feoarrm5n3_t* lhs,   coeff_t  rhs);
  void      feoarrm5n3_sub_Fr_to( feoarrm5n3_t* lhs,   coeff_t  rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_mul_FF(   feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_mul_FF_to(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_mul_fF(    feonumm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_mul_fF_to( feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_mul_OF(     oarrm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_mul_OF_to(  oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_mul_RF(      darr_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_mul_RF_to(   darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_mul_oF(   onumm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_mul_oF_to(onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_mul_rF(     coeff_t  lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_mul_rF_to(  coeff_t  lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_div_FF(    feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_div_FF_to( feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_div_fF(     feonumm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_div_fF_to(  feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_div_Ff(    feoarrm5n3_t* lhs,  feonumm5n3_t* rhs);
  void      feoarrm5n3_div_Ff_to( feoarrm5n3_t* lhs,  feonumm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_div_OF(      oarrm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_div_OF_to(   oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_div_FO(    feoarrm5n3_t* lhs,   oarrm5n3_t* rhs);
  void      feoarrm5n3_div_FO_to( feoarrm5n3_t* lhs,   oarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_div_RF(       darr_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_div_RF_to(    darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_div_FR(    feoarrm5n3_t* lhs,    darr_t* rhs);
  void      feoarrm5n3_div_FR_to( feoarrm5n3_t* lhs,    darr_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_div_oF(    onumm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_div_oF_to( onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_div_Fo(    feoarrm5n3_t* lhs, onumm5n3_t* rhs);
  void      feoarrm5n3_div_Fo_to( feoarrm5n3_t* lhs, onumm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_div_rF(      coeff_t  lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_div_rF_to(    coeff_t lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_div_Fr(    feoarrm5n3_t* lhs,   coeff_t  rhs);
  void      feoarrm5n3_div_Fr_to( feoarrm5n3_t* lhs,   coeff_t  rhs, feoarrm5n3_t* res);
  oarrm5n3_t feoarrm5n3_integrate(    feoarrm5n3_t* arr, feonumm5n3_t* w);
  void    feoarrm5n3_integrate_to( feoarrm5n3_t* arr, feonumm5n3_t* w, oarrm5n3_t* res);
  feonumm5n3_t feoarrm5n3_dotproduct_FF(    feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
  void     feoarrm5n3_dotproduct_FF_to( feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feoarrm5n3_dotproduct_OF(      oarrm5n3_t* lhs, feoarrm5n3_t* rhs);
  void     feoarrm5n3_dotproduct_OF_to(   oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feonumm5n3_t* res);
  feonumm5n3_t feoarrm5n3_dotproduct_RF(       darr_t* lhs, feoarrm5n3_t* rhs);
  void     feoarrm5n3_dotproduct_RF_to(    darr_t* lhs, feoarrm5n3_t* rhs, feonumm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_matmul_FF(    feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_matmul_FF_to( feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_matmul_OF(    oarrm5n3_t*   lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_matmul_OF_to( oarrm5n3_t*   lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_matmul_FO(    feoarrm5n3_t* lhs, oarrm5n3_t*   rhs);
  void      feoarrm5n3_matmul_FO_to( feoarrm5n3_t* lhs, oarrm5n3_t*   rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_matmul_RF(    darr_t*    lhs, feoarrm5n3_t* rhs);
  void      feoarrm5n3_matmul_RF_to( darr_t*    lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
  feoarrm5n3_t feoarrm5n3_matmul_FR(    feoarrm5n3_t* lhs, darr_t*    rhs);
  void      feoarrm5n3_matmul_FR_to( feoarrm5n3_t* lhs, darr_t*    rhs, feoarrm5n3_t* res);
  feonumm5n3_t feoarrm5n3_det(   feoarrm5n3_t* arr);
  void     feoarrm5n3_det_to(feoarrm5n3_t* arr, feonumm5n3_t* res);
  feonumm5n3_t feoarrm5n3_norm(     feoarrm5n3_t* arr);
  void     feoarrm5n3_norm_to(  feoarrm5n3_t* arr, feonumm5n3_t* res);
  feonumm5n3_t feoarrm5n3_pnorm(    feoarrm5n3_t* arr, coeff_t p);
  void     feoarrm5n3_pnorm_to( feoarrm5n3_t* arr, coeff_t p, feonumm5n3_t* res);
  feoarrm5n3_t   feoarrm5n3_invert(    feoarrm5n3_t* arr);
  void        feoarrm5n3_invert_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
  feoarrm5n3_t   feoarrm5n3_transpose(   feoarrm5n3_t* arr);
  void        feoarrm5n3_transpose_to(feoarrm5n3_t* arr, feoarrm5n3_t* res);
  
  