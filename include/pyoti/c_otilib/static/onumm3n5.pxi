cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm3n5/scalar/structures.h
  
  ctypedef struct  onumm3n5_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e11;
    coeff_t e12;
    coeff_t e22;
    coeff_t e13;
    coeff_t e23;
    coeff_t e33;
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
    coeff_t e1111;
    coeff_t e1112;
    coeff_t e1122;
    coeff_t e1222;
    coeff_t e2222;
    coeff_t e1113;
    coeff_t e1123;
    coeff_t e1223;
    coeff_t e2223;
    coeff_t e1133;
    coeff_t e1233;
    coeff_t e2233;
    coeff_t e1333;
    coeff_t e2333;
    coeff_t e3333;
    coeff_t e11111;
    coeff_t e11112;
    coeff_t e11122;
    coeff_t e11222;
    coeff_t e12222;
    coeff_t e22222;
    coeff_t e11113;
    coeff_t e11123;
    coeff_t e11223;
    coeff_t e12223;
    coeff_t e22223;
    coeff_t e11133;
    coeff_t e11233;
    coeff_t e12233;
    coeff_t e22233;
    coeff_t e11333;
    coeff_t e12333;
    coeff_t e22333;
    coeff_t e13333;
    coeff_t e23333;
    coeff_t e33333;
  # } onumm3n5_t;
  
  
  # From ../../../include/oti/static/onumm3n5/array/structures.h
  
  ctypedef struct  oarrm3n5_t : # {
      onumm3n5_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm3n5_t;
  
  
  # From ../../../include/oti/static/onumm3n5/scalar/gauss/structures.h
  
  ctypedef struct  feonumm3n5_t: # {
      onumm3n5_t*  p_data;
      uint64_t    nip;
  # } feonumm3n5_t;
  
  
  # From ../../../include/oti/static/onumm3n5/array/gauss/structures.h
  
  ctypedef struct  feoarrm3n5_t: # {
      oarrm3n5_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm3n5_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm3n5/scalar/functions.h
  
  onumm3n5_t onumm3n5_atanh(onumm3n5_t* num);
  void onumm3n5_atanh_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_asinh(onumm3n5_t* num);
  void onumm3n5_asinh_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_acosh(onumm3n5_t* num);
  void onumm3n5_acosh_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_tanh(onumm3n5_t* num);
  void onumm3n5_tanh_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_sqrt(onumm3n5_t* num);
  void onumm3n5_sqrt_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_cbrt(onumm3n5_t* num);
  void onumm3n5_cbrt_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_cosh(onumm3n5_t* num);
  void onumm3n5_cosh_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_sinh(onumm3n5_t* num);
  void onumm3n5_sinh_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_asin(onumm3n5_t* num);
  void onumm3n5_asin_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_acos(onumm3n5_t* num);
  void onumm3n5_acos_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_atan(onumm3n5_t* num);
  void onumm3n5_atan_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_tan(onumm3n5_t* num);
  void onumm3n5_tan_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_cos(onumm3n5_t* num);
  void onumm3n5_cos_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_sin(onumm3n5_t* num );
  void onumm3n5_sin_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_logb(onumm3n5_t* num, double base);
  void onumm3n5_logb_to(onumm3n5_t* num, double base, onumm3n5_t* res);
  onumm3n5_t onumm3n5_log10(onumm3n5_t* num);
  void onumm3n5_log10_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_log(onumm3n5_t* num);
  void onumm3n5_log_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_exp(onumm3n5_t* num);
  void onumm3n5_exp_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_pow(onumm3n5_t* num, double e);
  void onumm3n5_pow_to(onumm3n5_t* num, coeff_t e, onumm3n5_t* res);
  
  
  # From ../../../include/oti/static/onumm3n5/scalar/base.h
  
  void onumm3n5_set_im_o(onumm3n5_t* num, imdir_t idx, ord_t order, onumm3n5_t* res);
  void onumm3n5_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm3n5_t* res);
  void onumm3n5_set_deriv_o(onumm3n5_t* num, imdir_t idx, ord_t order, onumm3n5_t* res);
  void onumm3n5_extract_im_to( imdir_t idx, ord_t order, onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_extract_im(imdir_t idx, ord_t order, onumm3n5_t* num);
  onumm3n5_t onumm3n5_extract_deriv(imdir_t idx, ord_t order, onumm3n5_t* num);
  void onumm3n5_extract_deriv_to(imdir_t idx, ord_t order, onumm3n5_t* num, onumm3n5_t* res);
  void onumm3n5_get_im_to_o(imdir_t idx, ord_t order, onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_get_im_o(imdir_t idx, ord_t order, onumm3n5_t* num);
  void onumm3n5_get_im_to_r(imdir_t idx, ord_t order, onumm3n5_t* num, coeff_t* res);
  ord_t onumm3n5_get_order(onumm3n5_t* lhs);
  onumm3n5_t onumm3n5_get_deriv_o( imdir_t idx, ord_t order, onumm3n5_t* num);
  void onumm3n5_get_deriv_to( imdir_t idx, ord_t order, onumm3n5_t* num, onumm3n5_t* res);
  void onumm3n5_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm3n5_t* res);
  onumm3n5_t onumm3n5_init();
  ndir_t onumm3n5_get_ndir_order(ord_t order, onumm3n5_t* num);
  ndir_t onumm3n5_get_ndir_total(onumm3n5_t* num);
  coeff_t* onumm3n5_get_order_address(ord_t order, onumm3n5_t* num);
  onumm3n5_t onumm3n5_create_r(  coeff_t lhs);
  void onumm3n5_set_r(  coeff_t lhs, onumm3n5_t* res);
  void onumm3n5_set_o(  onumm3n5_t* lhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_get_order_im(ord_t order, onumm3n5_t* lhs);
  void onumm3n5_get_order_im_to(ord_t order, onumm3n5_t* lhs, onumm3n5_t* res);
  coeff_t onumm3n5_get_item(imdir_t idx, ord_t order, onumm3n5_t* lhs);
  coeff_t onumm3n5_get_deriv(imdir_t idx, ord_t order, onumm3n5_t* lhs);
  void onumm3n5_set_item(coeff_t val, imdir_t idx, ord_t order, onumm3n5_t* x);
  onumm3n5_t onumm3n5_copy(  onumm3n5_t* lhs);
  void onumm3n5_copy_to(  onumm3n5_t* lhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_taylor_integrate(coeff_t* deltas,onumm3n5_t* lhs);
  void onumm3n5_taylor_integrate_to(coeff_t* deltas,onumm3n5_t* lhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_truncate_im(imdir_t idx, ord_t order, onumm3n5_t* lhs);
  void onumm3n5_truncate_im_to(imdir_t idx, ord_t order, onumm3n5_t* lhs, onumm3n5_t* res);
  void onumm3n5_print(  onumm3n5_t* lhs);
  imdir_t onumm3n5_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm3n5/scalar/utils.h
  
  void onumm3n5_get_active_bases(onumm3n5_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm3n5/scalar/algebra.h
  
  onumm3n5_t onumm3n5_abs(onumm3n5_t* num);
  onumm3n5_t onumm3n5_div_ro(coeff_t num, onumm3n5_t* den);
  onumm3n5_t onumm3n5_div_oo(onumm3n5_t* num, onumm3n5_t* den);
  onumm3n5_t onumm3n5_div_or(onumm3n5_t* num, coeff_t val);
  void onumm3n5_div_ro_to(coeff_t num, onumm3n5_t* den, onumm3n5_t* res);
  void onumm3n5_div_oo_to(onumm3n5_t* num, onumm3n5_t* den, onumm3n5_t* res);
  void onumm3n5_div_or_to(onumm3n5_t* num, coeff_t val, onumm3n5_t* res);
  void onumm3n5_abs_to(onumm3n5_t* num, onumm3n5_t* res);
  onumm3n5_t onumm3n5_neg(  onumm3n5_t* lhs);
  void onumm3n5_neg_to(  onumm3n5_t* lhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_sum_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs);
  void onumm3n5_sum_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_sum_ro(  coeff_t lhs,  onumm3n5_t* rhs);
  void onumm3n5_sum_ro_to(  coeff_t lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_sub_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs);
  void onumm3n5_sub_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_sub_ro(  coeff_t lhs,  onumm3n5_t* rhs);
  void onumm3n5_sub_ro_to(  coeff_t lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_sub_or(  onumm3n5_t* lhs,  coeff_t rhs);
  void onumm3n5_sub_or_to(  onumm3n5_t* lhs,  coeff_t rhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_mul_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs);
  void onumm3n5_mul_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_mul_ro(  coeff_t lhs,  onumm3n5_t* rhs);
  void onumm3n5_mul_ro_to(  coeff_t lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_trunc_mul_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs);
  void onumm3n5_trunc_mul_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_gem_oo(  onumm3n5_t* a,  onumm3n5_t* b,  onumm3n5_t* c);
  void onumm3n5_gem_oo_to(  onumm3n5_t* a,  onumm3n5_t* b,  onumm3n5_t* c, onumm3n5_t* res);
  onumm3n5_t onumm3n5_gem_ro(  coeff_t a,  onumm3n5_t* b,  onumm3n5_t* c);
  void onumm3n5_gem_ro_to(  coeff_t a,  onumm3n5_t* b,  onumm3n5_t* c, onumm3n5_t* res);
  void onumm3n5_trunc_gem_oo_to( ord_t ord_lhs,  onumm3n5_t* a,  ord_t ord_rhs,  onumm3n5_t* b,  onumm3n5_t* c, onumm3n5_t* res);
  void onumm3n5_trunc_sum_oo_to(ord_t order, onumm3n5_t* lhs,onumm3n5_t* rhs, onumm3n5_t* res);
  void onumm3n5_trunc_sub_oo_to(ord_t order, onumm3n5_t* lhs,onumm3n5_t* rhs, onumm3n5_t* res);
  onumm3n5_t onumm3n5_feval(coeff_t* feval_re, onumm3n5_t* x);
  void onumm3n5_feval_to(coeff_t* feval_re, onumm3n5_t* x, onumm3n5_t* res);
  
  
  # From ../../../include/oti/static/onumm3n5/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm3n5/scalar/gauss/functions.h
  
  feonumm3n5_t feonumm3n5_atanh(    feonumm3n5_t* num);
  void     feonumm3n5_atanh_to( feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_asinh(    feonumm3n5_t* num);
  void     feonumm3n5_asinh_to( feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_acosh(    feonumm3n5_t* num);
  void     feonumm3n5_acosh_to( feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_tanh(     feonumm3n5_t* num);
  void     feonumm3n5_tanh_to(  feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_cosh(     feonumm3n5_t* num);
  void     feonumm3n5_cosh_to(  feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_sinh(     feonumm3n5_t* num);
  void     feonumm3n5_sinh_to(  feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_asin(     feonumm3n5_t* num);
  void     feonumm3n5_asin_to(  feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_acos(     feonumm3n5_t* num);
  void     feonumm3n5_acos_to(  feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_atan(     feonumm3n5_t* num);
  void     feonumm3n5_atan_to(  feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_tan(      feonumm3n5_t* num);
  void     feonumm3n5_tan_to(   feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_cos(      feonumm3n5_t* num);
  void     feonumm3n5_cos_to(   feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_sin(      feonumm3n5_t* num);
  void     feonumm3n5_sin_to(   feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_logb(     feonumm3n5_t* num, double base);
  void     feonumm3n5_logb_to(  feonumm3n5_t* num, double base, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_log10(    feonumm3n5_t* num);
  void     feonumm3n5_log10_to( feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_log(      feonumm3n5_t* num);
  void     feonumm3n5_log_to(   feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_exp(      feonumm3n5_t* num);
  void     feonumm3n5_exp_to(   feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_cbrt(     feonumm3n5_t* num);
  void     feonumm3n5_cbrt_to(  feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_sqrt(     feonumm3n5_t* num);
  void     feonumm3n5_sqrt_to(  feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_pow(      feonumm3n5_t* num, double e);
  void     feonumm3n5_pow_to(   feonumm3n5_t* num, double e, feonumm3n5_t* res);
  onumm3n5_t feonumm3n5_integrate(       feonumm3n5_t* num, feonumm3n5_t* w);
  void      feonumm3n5_integrate_to(    feonumm3n5_t* num, feonumm3n5_t* w, onumm3n5_t* res);
  onumm3n5_t feonumm3n5_integrate_f(     feonumm3n5_t* num, feonumm3n5_t* w);
  void      feonumm3n5_integrate_f_to(  feonumm3n5_t* num, feonumm3n5_t* w, onumm3n5_t* res);
  onumm3n5_t feonumm3n5_integrate_r(       coeff_t num, feonumm3n5_t* w);
  void      feonumm3n5_integrate_r_to(    coeff_t num, feonumm3n5_t* w, onumm3n5_t* res);
  onumm3n5_t feonumm3n5_integrate_o(    onumm3n5_t* num, feonumm3n5_t* w);
  void      feonumm3n5_integrate_o_to( onumm3n5_t* num, feonumm3n5_t* w, onumm3n5_t* res);
  
  
  # From ../../../include/oti/static/onumm3n5/scalar/gauss/base.h
  
  void     feonumm3n5_get_order_im_to( ord_t order, feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_get_order_im(    ord_t order, feonumm3n5_t* num);
  feonumm3n5_t feonumm3n5_get_im(    imdir_t idx, ord_t order, feonumm3n5_t* num);
  void     feonumm3n5_get_im_to( imdir_t idx, ord_t order, feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_get_deriv(    imdir_t idx, ord_t order, feonumm3n5_t* num);
  void     feonumm3n5_get_deriv_to( imdir_t idx, ord_t order, feonumm3n5_t* num, feonumm3n5_t* res);
  void feonumm3n5_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm3n5_t* num);
  void feonumm3n5_set_im_o( onumm3n5_t* val, imdir_t idx, ord_t order, feonumm3n5_t* num);
  void feonumm3n5_set_im_f(  feonumm3n5_t* val, imdir_t idx, ord_t order, feonumm3n5_t* num);
  void feonumm3n5_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm3n5_t* num);
  void feonumm3n5_set_deriv_o( onumm3n5_t* val, imdir_t idx, ord_t order, feonumm3n5_t* num);
  void feonumm3n5_set_deriv_f(  feonumm3n5_t* val, imdir_t idx, ord_t order, feonumm3n5_t* num);
  feonumm3n5_t feonumm3n5_extract_im(    imdir_t idx, ord_t order, feonumm3n5_t* num);
  void     feonumm3n5_extract_im_to( imdir_t idx, ord_t order, feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_extract_deriv(    imdir_t idx, ord_t order, feonumm3n5_t* num);
  void     feonumm3n5_extract_deriv_to( imdir_t idx, ord_t order, feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_truncate_im(    imdir_t idx, ord_t order, feonumm3n5_t* num);
  void     feonumm3n5_truncate_im_to( imdir_t idx, ord_t order, feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_copy(    feonumm3n5_t* src);
  void     feonumm3n5_copy_to( feonumm3n5_t* src, feonumm3n5_t* dst);
  void feonumm3n5_set_r(    coeff_t num, feonumm3n5_t* res);
  void feonumm3n5_set_o( onumm3n5_t* num, feonumm3n5_t* res);
  void feonumm3n5_set_f(  feonumm3n5_t* num, feonumm3n5_t* res);
  void feonumm3n5_set_item_k_r(   coeff_t  num, uint64_t k, feonumm3n5_t* res);
  void feonumm3n5_set_item_k_o( onumm3n5_t* num, uint64_t k, feonumm3n5_t* res);
  onumm3n5_t feonumm3n5_get_item_k(   feonumm3n5_t* num, uint64_t k);
  void      feonumm3n5_get_item_k_to(feonumm3n5_t* num, uint64_t k, onumm3n5_t* res);
  feonumm3n5_t feonumm3n5_zeros(uint64_t nIntPts);
  feonumm3n5_t feonumm3n5_createEmpty(uint64_t nIntPts);
  feonumm3n5_t feonumm3n5_empty_like(feonumm3n5_t* arr);
  void feonumm3n5_free(feonumm3n5_t* num);
  ord_t feonumm3n5_get_order( feonumm3n5_t* num );
  feonumm3n5_t feonumm3n5_init();
  
  
  # From ../../../include/oti/static/onumm3n5/scalar/gauss/utils.h
  
  void feonumm3n5_dimCheck(feonumm3n5_t* arr1,feonumm3n5_t* arr2);
  void feonumm3n5_get_active_bases(feonumm3n5_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n5/scalar/gauss/algebra.h
  
  feonumm3n5_t feonumm3n5_neg(   feonumm3n5_t* num);
  void     feonumm3n5_neg_to(feonumm3n5_t* num, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_sum_ff(   feonumm3n5_t* lhs, feonumm3n5_t* rhs);
  void     feonumm3n5_sum_ff_to(feonumm3n5_t* lhs, feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_sum_of(   onumm3n5_t* lhs, feonumm3n5_t* rhs);
  void     feonumm3n5_sum_of_to(onumm3n5_t* lhs, feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_sum_rf(   coeff_t lhs, feonumm3n5_t* rhs);
  void     feonumm3n5_sum_rf_to(coeff_t lhs, feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_sub_ff(     feonumm3n5_t* lhs,  feonumm3n5_t* rhs);
  void     feonumm3n5_sub_ff_to(  feonumm3n5_t* lhs,  feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_sub_of(    onumm3n5_t* lhs,  feonumm3n5_t* rhs);
  void     feonumm3n5_sub_of_to( onumm3n5_t* lhs,  feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_sub_fo(     feonumm3n5_t* lhs, onumm3n5_t* rhs);
  void     feonumm3n5_sub_fo_to(  feonumm3n5_t* lhs, onumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_sub_rf(       coeff_t lhs,  feonumm3n5_t* rhs);
  void     feonumm3n5_sub_rf_to(    coeff_t lhs,  feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_sub_fr(     feonumm3n5_t* lhs,    coeff_t rhs);
  void     feonumm3n5_sub_fr_to(  feonumm3n5_t* lhs,    coeff_t rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_mul_ff(   feonumm3n5_t* lhs, feonumm3n5_t* rhs);
  void     feonumm3n5_mul_ff_to(feonumm3n5_t* lhs, feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_mul_of(   onumm3n5_t* lhs, feonumm3n5_t* rhs);
  void     feonumm3n5_mul_of_to(onumm3n5_t* lhs, feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_mul_rf(   coeff_t lhs, feonumm3n5_t* rhs);
  void     feonumm3n5_mul_rf_to(coeff_t lhs, feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_div_ff(     feonumm3n5_t* lhs,  feonumm3n5_t* rhs);
  void     feonumm3n5_div_ff_to(  feonumm3n5_t* lhs,  feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_div_of(    onumm3n5_t* lhs,  feonumm3n5_t* rhs);
  void     feonumm3n5_div_of_to( onumm3n5_t* lhs,  feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_div_fo(     feonumm3n5_t* lhs, onumm3n5_t* rhs);
  void     feonumm3n5_div_fo_to(  feonumm3n5_t* lhs, onumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_div_rf(       coeff_t lhs,  feonumm3n5_t* rhs);
  void     feonumm3n5_div_rf_to(    coeff_t lhs,  feonumm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feonumm3n5_div_fr(     feonumm3n5_t* lhs,    coeff_t rhs);
  void     feonumm3n5_div_fr_to(  feonumm3n5_t* lhs,    coeff_t rhs, feonumm3n5_t* res);
  
  
  # From ../../../include/oti/static/onumm3n5/array/functions.h
  
  oarrm3n5_t oarrm3n5_atanh(   oarrm3n5_t* arr);
  void    oarrm3n5_atanh_to(oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_asinh(   oarrm3n5_t* arr);
  void    oarrm3n5_asinh_to(oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_acosh(   oarrm3n5_t* arr);
  void    oarrm3n5_acosh_to(oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_tanh(    oarrm3n5_t* arr);
  void    oarrm3n5_tanh_to( oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_cbrt(    oarrm3n5_t* arr);
  void    oarrm3n5_cbrt_to( oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_sqrt(    oarrm3n5_t* arr);
  void    oarrm3n5_sqrt_to( oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_cosh(    oarrm3n5_t* arr);
  void    oarrm3n5_cosh_to( oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_sinh(    oarrm3n5_t* arr);
  void    oarrm3n5_sinh_to( oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_asin(    oarrm3n5_t* arr);
  void    oarrm3n5_asin_to( oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_acos(    oarrm3n5_t* arr);
  void    oarrm3n5_acos_to( oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_atan(    oarrm3n5_t* arr);
  void    oarrm3n5_atan_to( oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_tan(     oarrm3n5_t* arr);
  void    oarrm3n5_tan_to(  oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_cos(     oarrm3n5_t* arr);
  void    oarrm3n5_cos_to(  oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_sin(     oarrm3n5_t* arr);
  void    oarrm3n5_sin_to(  oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_logb(    oarrm3n5_t* arr, double base);
  void    oarrm3n5_logb_to( oarrm3n5_t* arr, double base, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_log10(   oarrm3n5_t* arr);
  void    oarrm3n5_log10_to(oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_log(     oarrm3n5_t* arr);
  void    oarrm3n5_log_to(  oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_exp(     oarrm3n5_t* arr);
  void    oarrm3n5_exp_to(  oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_pow(     oarrm3n5_t* arr, double e);
  void    oarrm3n5_pow_to(  oarrm3n5_t* arr, double e, oarrm3n5_t* res);
  
  
  # From ../../../include/oti/static/onumm3n5/array/algebra_elementwise.h
  
  oarrm3n5_t oarrm3n5_neg(oarrm3n5_t* arr);
  void oarrm3n5_neg_to(oarrm3n5_t* rhs, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_sum_OO(oarrm3n5_t*   lhs, oarrm3n5_t* rhs);
  oarrm3n5_t oarrm3n5_sum_RO(darr_t*    lhs, oarrm3n5_t* rhs);
  oarrm3n5_t oarrm3n5_sum_oO(onumm3n5_t* lhs, oarrm3n5_t* rhs);
  oarrm3n5_t oarrm3n5_sum_rO(coeff_t    lhs, oarrm3n5_t* rhs);
  void oarrm3n5_sum_OO_to(oarrm3n5_t*   lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
  void oarrm3n5_sum_RO_to(darr_t*    lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
  void oarrm3n5_sum_oO_to(onumm3n5_t* lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
  void oarrm3n5_sum_rO_to(coeff_t    lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
  void oarrm3n5_trunc_sum_OO_to(ord_t order, oarrm3n5_t* arr1, oarrm3n5_t* arr2, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_sub_OO(oarrm3n5_t*   lhs, oarrm3n5_t*   rhs);
  oarrm3n5_t oarrm3n5_sub_RO(darr_t*    lhs, oarrm3n5_t*   rhs);
  oarrm3n5_t oarrm3n5_sub_OR(oarrm3n5_t*   lhs, darr_t*    rhs);
  oarrm3n5_t oarrm3n5_sub_oO(onumm3n5_t* lhs, oarrm3n5_t*   rhs);
  oarrm3n5_t oarrm3n5_sub_Oo(oarrm3n5_t*   lhs, onumm3n5_t* rhs);
  oarrm3n5_t oarrm3n5_sub_rO(coeff_t    lhs, oarrm3n5_t*   rhs);
  oarrm3n5_t oarrm3n5_sub_Or(oarrm3n5_t*   lhs, coeff_t    rhs);
  void oarrm3n5_sub_OO_to( oarrm3n5_t*   lhs, oarrm3n5_t*   rhs, oarrm3n5_t* res);
  void oarrm3n5_sub_RO_to( darr_t*    lhs, oarrm3n5_t*   rhs, oarrm3n5_t* res);
  void oarrm3n5_sub_OR_to( oarrm3n5_t*   lhs, darr_t*    rhs, oarrm3n5_t* res);
  void oarrm3n5_sub_oO_to( onumm3n5_t* lhs, oarrm3n5_t*   rhs, oarrm3n5_t* res);
  void oarrm3n5_sub_Oo_to( oarrm3n5_t*   lhs, onumm3n5_t* rhs, oarrm3n5_t* res);
  void oarrm3n5_sub_rO_to( coeff_t    lhs, oarrm3n5_t*   rhs, oarrm3n5_t* res);
  void oarrm3n5_sub_Or_to( oarrm3n5_t*   lhs, coeff_t    rhs, oarrm3n5_t* res);
  void oarrm3n5_trunc_sub_OO_to(ord_t order, oarrm3n5_t* arr1, oarrm3n5_t* arr2, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_mul_OO(oarrm3n5_t*   lhs, oarrm3n5_t* rhs);
  oarrm3n5_t oarrm3n5_mul_RO(darr_t*    lhs, oarrm3n5_t* rhs);
  oarrm3n5_t oarrm3n5_mul_oO(onumm3n5_t* lhs, oarrm3n5_t* rhs);
  oarrm3n5_t oarrm3n5_mul_rO(coeff_t    lhs, oarrm3n5_t* rhs);
  void oarrm3n5_mul_OO_to(oarrm3n5_t*   lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
  void oarrm3n5_mul_RO_to(darr_t*    lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
  void oarrm3n5_mul_oO_to(onumm3n5_t* lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
  void oarrm3n5_mul_rO_to(coeff_t    lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
  void oarrm3n5_gem_OO_to(  oarrm3n5_t* arr1, oarrm3n5_t* arr2, oarrm3n5_t* arr3, oarrm3n5_t* res);
  void oarrm3n5_gem_oO_to(onumm3n5_t* arr1, oarrm3n5_t* arr2, oarrm3n5_t* arr3, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_div_OO(oarrm3n5_t*   lhs, oarrm3n5_t*   rhs);
  oarrm3n5_t oarrm3n5_div_OR(oarrm3n5_t*   lhs, darr_t*    rhs);
  oarrm3n5_t oarrm3n5_div_RO(darr_t*    lhs, oarrm3n5_t*   rhs);
  oarrm3n5_t oarrm3n5_div_oO(onumm3n5_t* lhs, oarrm3n5_t*   rhs);
  oarrm3n5_t oarrm3n5_div_Oo(oarrm3n5_t*   lhs, onumm3n5_t* rhs);
  oarrm3n5_t oarrm3n5_div_rO(coeff_t    lhs, oarrm3n5_t*   rhs);
  oarrm3n5_t oarrm3n5_div_Or(oarrm3n5_t*   lhs, coeff_t    rhs);
  void oarrm3n5_div_OO_to(oarrm3n5_t*   lhs, oarrm3n5_t*   rhs, oarrm3n5_t* res);
  void oarrm3n5_div_RO_to(darr_t*    lhs, oarrm3n5_t*   rhs, oarrm3n5_t* res);
  void oarrm3n5_div_OR_to(oarrm3n5_t*   lhs, darr_t*    rhs, oarrm3n5_t* res);
  void oarrm3n5_div_oO_to(onumm3n5_t* lhs, oarrm3n5_t*   rhs, oarrm3n5_t* res);
  void oarrm3n5_div_Oo_to(oarrm3n5_t*   lhs, onumm3n5_t* rhs, oarrm3n5_t* res);
  void oarrm3n5_div_rO_to(coeff_t    lhs, oarrm3n5_t*   rhs, oarrm3n5_t* res);
  void oarrm3n5_div_Or_to(oarrm3n5_t*   lhs, coeff_t    rhs, oarrm3n5_t* res);
  
  
  # From ../../../include/oti/static/onumm3n5/array/base.h
  
  void    oarrm3n5_taylor_integrate_to( coeff_t* deltas, oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_taylor_integrate(    coeff_t* deltas, oarrm3n5_t* arr);
  void    oarrm3n5_get_order_im_to( ord_t order, oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_get_order_im(    ord_t order, oarrm3n5_t* arr);
  void oarrm3n5_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n5_t* res);
  void oarrm3n5_set_slice_O( oarrm3n5_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n5_t* res);
  void oarrm3n5_set_slice_o( onumm3n5_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_get_slice( oarrm3n5_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm3n5_get_slice_to( oarrm3n5_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_truncate_im(    imdir_t idx, ord_t order, oarrm3n5_t* arr);
  void    oarrm3n5_truncate_im_to( imdir_t idx, ord_t order, oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_extract_im(   imdir_t idx, ord_t order, oarrm3n5_t* arr);
  void    oarrm3n5_extract_im_to(imdir_t idx, ord_t order, oarrm3n5_t* arr, oarrm3n5_t* res);
  darr_t  oarrm3n5_get_deriv(    imdir_t idx, ord_t order, oarrm3n5_t* arr);
  void    oarrm3n5_get_deriv_to( imdir_t idx, ord_t order, oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_get_deriv_o(  imdir_t idx, ord_t order, oarrm3n5_t* arr);
  oarrm3n5_t oarrm3n5_extract_deriv(    imdir_t idx, ord_t order, oarrm3n5_t* arr);
  void    oarrm3n5_extract_deriv_to( imdir_t idx, ord_t order, oarrm3n5_t* arr, oarrm3n5_t* res);
  darr_t  oarrm3n5_get_im(   imdir_t idx, ord_t order, oarrm3n5_t* arr);
  oarrm3n5_t oarrm3n5_get_im_o( imdir_t idx, ord_t order, oarrm3n5_t* arr);
  void    oarrm3n5_get_im_to(imdir_t idx, ord_t order, oarrm3n5_t* arr, oarrm3n5_t* res);
  void    oarrm3n5_copy_to(oarrm3n5_t* arr, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_copy(oarrm3n5_t* arr);
  void oarrm3n5_set_all_r( coeff_t num, oarrm3n5_t* arr);
  void oarrm3n5_set_item_i_r( coeff_t num, uint64_t i, oarrm3n5_t* arr);
  void oarrm3n5_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm3n5_t* arr);
  void oarrm3n5_set_r(   coeff_t  num,   oarrm3n5_t* arr);
  void oarrm3n5_set_o( onumm3n5_t* num,   oarrm3n5_t* arr);
  void oarrm3n5_set_O(   oarrm3n5_t* arrin, oarrm3n5_t* arr);
  void oarrm3n5_set_all_o( onumm3n5_t* src, oarrm3n5_t* arr);
  void oarrm3n5_set_item_i_o( onumm3n5_t* num, uint64_t i, oarrm3n5_t* arr);
  void oarrm3n5_set_item_ij_o( onumm3n5_t* num, uint64_t i, uint64_t j, oarrm3n5_t* arr);
  onumm3n5_t oarrm3n5_get_item_i(    oarrm3n5_t* arr, uint64_t i);
  void      oarrm3n5_get_item_i_to( oarrm3n5_t* arr, uint64_t i,             onumm3n5_t* res);
  onumm3n5_t oarrm3n5_get_item_ij(   oarrm3n5_t* arr, uint64_t i, uint64_t j);
  void      oarrm3n5_get_item_ij_to(oarrm3n5_t* arr, uint64_t i, uint64_t j, onumm3n5_t* res);
  oarrm3n5_t oarrm3n5_init();
  void oarrm3n5_free(oarrm3n5_t* arr);
  oarrm3n5_t oarrm3n5_empty_like(oarrm3n5_t* arr);
  oarrm3n5_t oarrm3n5_eye(uint64_t nrows);
  oarrm3n5_t oarrm3n5_ones(uint64_t nrows, uint64_t ncols);
  oarrm3n5_t oarrm3n5_zeros(uint64_t nrows, uint64_t ncols);
  oarrm3n5_t oarrm3n5_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm3n5/array/utils.h
  
  void oarrm3n5_dimCheck_OO_elementwise(oarrm3n5_t* arr1, oarrm3n5_t* arr2, oarrm3n5_t* res);
  void oarrm3n5_dimCheck_RO_elementwise(darr_t*  arr1, oarrm3n5_t* arr2, oarrm3n5_t* res);
  void oarrm3n5_dimCheck_OO_matmul(oarrm3n5_t* arr1, oarrm3n5_t* arr2, oarrm3n5_t* res);
  void oarrm3n5_dimCheck_RO_matmul(darr_t*  arr1, oarrm3n5_t* arr2, oarrm3n5_t* res);
  void oarrm3n5_dimCheck_OR_matmul(oarrm3n5_t* arr1, darr_t*  arr2, oarrm3n5_t* res);
  void oarrm3n5_dimCheck_O_squareness(oarrm3n5_t* arr1, oarrm3n5_t* res);
  void oarrm3n5_dimCheck_OO_samesize(oarrm3n5_t* arr1, oarrm3n5_t* res);
  void oarrm3n5_dimCheck_RO_samesize(darr_t* arr1, oarrm3n5_t* res);
  ord_t oarrm3n5_get_order(oarrm3n5_t* arr);
  void oarrm3n5_get_active_bases(oarrm3n5_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n5/array/algebra_matops.h
  
  onumm3n5_t oarrm3n5_dotproduct_OO(    oarrm3n5_t* lhs, oarrm3n5_t* rhs);
  void      oarrm3n5_dotproduct_OO_to( oarrm3n5_t* lhs, oarrm3n5_t* rhs, onumm3n5_t* res);
  onumm3n5_t oarrm3n5_dotproduct_RO(     darr_t* lhs, oarrm3n5_t* rhs);
  void      oarrm3n5_dotproduct_RO_to(  darr_t* lhs, oarrm3n5_t* rhs, onumm3n5_t* res);
  oarrm3n5_t oarrm3n5_matmul_OO(    oarrm3n5_t* lhs, oarrm3n5_t* rhs);
  oarrm3n5_t oarrm3n5_matmul_OR(    oarrm3n5_t* lhs,  darr_t* rhs);
  oarrm3n5_t oarrm3n5_matmul_RO(     darr_t* lhs, oarrm3n5_t* rhs);
  void    oarrm3n5_matmul_OO_to( oarrm3n5_t* lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
  void    oarrm3n5_matmul_OR_to( oarrm3n5_t* lhs,  darr_t* rhs, oarrm3n5_t* res);
  void    oarrm3n5_matmul_RO_to(  darr_t* lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_transpose(    oarrm3n5_t* arr1);
  void    oarrm3n5_transpose_to( oarrm3n5_t* arr1, oarrm3n5_t* res);
  oarrm3n5_t oarrm3n5_invert(    oarrm3n5_t* arr1);
  void    oarrm3n5_invert_to( oarrm3n5_t* arr1, oarrm3n5_t* res);
  onumm3n5_t oarrm3n5_det(    oarrm3n5_t* arr1);
  void      oarrm3n5_det_to( oarrm3n5_t* arr1, onumm3n5_t* res);
  onumm3n5_t oarrm3n5_norm(    oarrm3n5_t* arr1);
  void      oarrm3n5_norm_to( oarrm3n5_t* arr1,  onumm3n5_t* res);
  onumm3n5_t oarrm3n5_pnorm(    oarrm3n5_t* arr1, coeff_t p);
  void      oarrm3n5_pnorm_to( oarrm3n5_t* arr1, coeff_t p, onumm3n5_t* res);
  
  
  # From ../../../include/oti/static/onumm3n5/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm3n5/array/gauss/functions.h
  
  feoarrm3n5_t feoarrm3n5_atanh(    feoarrm3n5_t* arr);
  void      feoarrm3n5_atanh_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_asinh(    feoarrm3n5_t* arr);
  void      feoarrm3n5_asinh_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_acosh(    feoarrm3n5_t* arr);
  void      feoarrm3n5_acosh_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_tanh(     feoarrm3n5_t* arr);
  void      feoarrm3n5_tanh_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sinh(     feoarrm3n5_t* arr);
  void      feoarrm3n5_sinh_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_cosh(     feoarrm3n5_t* arr);
  void      feoarrm3n5_cosh_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_atan(     feoarrm3n5_t* arr);
  void      feoarrm3n5_atan_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_asin(     feoarrm3n5_t* arr);
  void      feoarrm3n5_asin_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_acos(     feoarrm3n5_t* arr);
  void      feoarrm3n5_acos_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_tan(      feoarrm3n5_t* arr);
  void      feoarrm3n5_tan_to(   feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sin(      feoarrm3n5_t* arr);
  void      feoarrm3n5_sin_to(   feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_cos(      feoarrm3n5_t* arr);
  void      feoarrm3n5_cos_to(   feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_logb(     feoarrm3n5_t* arr, double base);
  void      feoarrm3n5_logb_to(  feoarrm3n5_t* arr, double base, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_log10(    feoarrm3n5_t* arr);
  void      feoarrm3n5_log10_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_log(      feoarrm3n5_t* arr);
  void      feoarrm3n5_log_to(   feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_exp(      feoarrm3n5_t* arr);
  void      feoarrm3n5_exp_to(   feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_cbrt(     feoarrm3n5_t* arr);
  void      feoarrm3n5_cbrt_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sqrt(     feoarrm3n5_t* arr);
  void      feoarrm3n5_sqrt_to(  feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_pow(      feoarrm3n5_t* arr, double e);
  void      feoarrm3n5_pow_to(   feoarrm3n5_t* arr, double e, feoarrm3n5_t* res);
  
  
  # From ../../../include/oti/static/onumm3n5/array/gauss/base.h
  
  void      feoarrm3n5_get_order_im_to( ord_t order, feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_get_order_im(    ord_t order, feoarrm3n5_t* arr);
  feoarrm3n5_t feoarrm3n5_get_deriv(   imdir_t idx, ord_t order, feoarrm3n5_t* arr);
  void      feoarrm3n5_get_deriv_to(imdir_t idx, ord_t order, feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_get_im(      imdir_t idx, ord_t order, feoarrm3n5_t* arr);
  void      feoarrm3n5_get_im_to(   imdir_t idx, ord_t order, feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_truncate_im(   imdir_t idx, ord_t order, feoarrm3n5_t* arr);
  void      feoarrm3n5_truncate_im_to(imdir_t idx, ord_t order, feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_copy(   feoarrm3n5_t* src);
  void      feoarrm3n5_copy_to(feoarrm3n5_t* src, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_get_im(    imdir_t idx, ord_t order, feoarrm3n5_t* arr);
  void      feoarrm3n5_get_im_to( imdir_t idx, ord_t order, feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_get_deriv(    imdir_t idx, ord_t order, feoarrm3n5_t* arr);
  void      feoarrm3n5_get_deriv_to( imdir_t idx, ord_t order, feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_extract_im(    imdir_t idx, ord_t order, feoarrm3n5_t* arr);
  void      feoarrm3n5_extract_im_to( imdir_t idx, ord_t order, feoarrm3n5_t* arr,  feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_extract_deriv(    imdir_t idx, ord_t order, feoarrm3n5_t* arr);
  void      feoarrm3n5_extract_deriv_to( imdir_t idx, ord_t order, feoarrm3n5_t* arr, feoarrm3n5_t* res);
  oarrm3n5_t   feoarrm3n5_get_item_k(  feoarrm3n5_t* arr, uint64_t k);
  feonumm3n5_t  feoarrm3n5_get_item_ij( feoarrm3n5_t* arr, uint64_t i, uint64_t j);
  onumm3n5_t feoarrm3n5_get_item_ijk(feoarrm3n5_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm3n5_get_item_ij_to(  feoarrm3n5_t* arr, uint64_t i, uint64_t j,
                                 feonumm3n5_t* res);
  void feoarrm3n5_get_item_k_to(   feoarrm3n5_t* arr, uint64_t k,
                                  oarrm3n5_t* res);
  void feoarrm3n5_get_item_ijk_to( feoarrm3n5_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_get_slice(feoarrm3n5_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm3n5_get_slice_to(feoarrm3n5_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n5_t* res);
  void feoarrm3n5_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm3n5_t* res);
  void feoarrm3n5_set_item_ij_o(  onumm3n5_t* elm, uint64_t i, uint64_t j,
                               feoarrm3n5_t* res);
  void feoarrm3n5_set_item_ij_f(  feonumm3n5_t* elm, uint64_t i, uint64_t j,
                              feoarrm3n5_t* res);
  void feoarrm3n5_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm3n5_t* res);
  void feoarrm3n5_set_item_k_o(  onumm3n5_t* elm, uint64_t k,
                              feoarrm3n5_t* res);
  void feoarrm3n5_set_item_k_R(    oarrm3n5_t* elm, uint64_t k,
                            feoarrm3n5_t* res);
  void feoarrm3n5_set_item_k_O(    oarrm3n5_t* elm, uint64_t k,
                            feoarrm3n5_t* res);
  void feoarrm3n5_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm3n5_t* res);
  void feoarrm3n5_set_item_ijk_o( onumm3n5_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm3n5_t* res);
  void feoarrm3n5_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n5_t* res);
  void feoarrm3n5_set_slice_o( onumm3n5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n5_t* res);
  void feoarrm3n5_set_slice_f( feonumm3n5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n5_t* res);
  void feoarrm3n5_set_slice_O( oarrm3n5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n5_t* res);
  void feoarrm3n5_set_slice_F( feoarrm3n5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm3n5_t* res);
  void feoarrm3n5_set_all_o( onumm3n5_t* num, feoarrm3n5_t* arr );
  void feoarrm3n5_set_all_r(   coeff_t  num, feoarrm3n5_t* arr );
  void feoarrm3n5_set_all_f(  feonumm3n5_t* num, feoarrm3n5_t* arr );
  void feoarrm3n5_set_r(    coeff_t src, feoarrm3n5_t* res );
  void feoarrm3n5_set_o( onumm3n5_t* src, feoarrm3n5_t* res );
  void feoarrm3n5_set_f(  feonumm3n5_t* src, feoarrm3n5_t* res );
  void feoarrm3n5_set_R(    darr_t* src, feoarrm3n5_t* res );
  void feoarrm3n5_set_O(   oarrm3n5_t* src, feoarrm3n5_t* res );
  void feoarrm3n5_set_F( feoarrm3n5_t* src, feoarrm3n5_t* res );
  feoarrm3n5_t feoarrm3n5_eye( uint64_t size,  uint64_t nip);
  feoarrm3n5_t feoarrm3n5_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm3n5_t feoarrm3n5_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm3n5_t feoarrm3n5_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm3n5_free(feoarrm3n5_t* arr);
  feoarrm3n5_t feoarrm3n5_init();
  ord_t feoarrm3n5_get_order(feoarrm3n5_t* arr);
  
  
  # From ../../../include/oti/static/onumm3n5/array/gauss/utils.h
  
  void feoarrm3n5_dimCheck_FF_samesize(feoarrm3n5_t* arr1, feoarrm3n5_t* arr2, feonumm3n5_t* res);
  void feoarrm3n5_dimCheck_OF_samesize(  oarrm3n5_t* arr1, feoarrm3n5_t* arr2, feonumm3n5_t* res);
  void feoarrm3n5_dimCheck_RF_samesize(   darr_t* arr1, feoarrm3n5_t* arr2, feonumm3n5_t* res);
  void feoarrm3n5_dimCheck_FF_elementwise(feoarrm3n5_t* arr1, feoarrm3n5_t* arr2, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_OF_elementwise(  oarrm3n5_t* arr1, feoarrm3n5_t* arr2, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm3n5_t* arr2, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_fF_elementwise( feonumm3n5_t* num1, feoarrm3n5_t* arr2, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_Ff_elementwise(feoarrm3n5_t* arr1,  feonumm3n5_t* num2, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_FF_matmul( feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_OF_matmul(   oarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_RF_matmul(    darr_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_FO_matmul( feoarrm3n5_t* lhs,   oarrm3n5_t* rhs, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_FR_matmul( feoarrm3n5_t* lhs,    darr_t* rhs, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_F_squareness( feoarrm3n5_t* arr1, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_F_transpose( feoarrm3n5_t* arr1, feoarrm3n5_t* res);
  void feoarrm3n5_dimCheck_FfO_integrate(feoarrm3n5_t* arr, feonumm3n5_t* num,oarrm3n5_t* res);
  void feoarrm3n5_get_active_bases(feoarrm3n5_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm3n5/array/gauss/algebra.h
  
  feoarrm3n5_t feoarrm3n5_neg(    feoarrm3n5_t* arr);
  void      feoarrm3n5_neg_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sum_FF(   feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sum_FF_to(feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sum_fF(    feonumm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sum_fF_to( feonumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sum_OF(     oarrm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sum_OF_to(  oarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sum_RF(      darr_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sum_RF_to(   darr_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sum_oF(   onumm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sum_oF_to(onumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sum_rF(     coeff_t  lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sum_rF_to(  coeff_t  lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sub_FF(    feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sub_FF_to( feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sub_fF(    feonumm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sub_fF_to( feonumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sub_Ff(    feoarrm3n5_t* lhs, feonumm3n5_t* rhs);
  void      feoarrm3n5_sub_Ff_to( feoarrm3n5_t* lhs, feonumm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sub_OF(      oarrm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sub_OF_to(   oarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sub_FO(    feoarrm3n5_t* lhs,   oarrm3n5_t* rhs);
  void      feoarrm3n5_sub_FO_to( feoarrm3n5_t* lhs,   oarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sub_RF(       darr_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sub_RF_to(    darr_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sub_FR(    feoarrm3n5_t* lhs,    darr_t* rhs);
  void      feoarrm3n5_sub_FR_to( feoarrm3n5_t* lhs,    darr_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sub_oF(    onumm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sub_oF_to( onumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sub_Fo(    feoarrm3n5_t* lhs, onumm3n5_t* rhs);
  void      feoarrm3n5_sub_Fo_to( feoarrm3n5_t* lhs, onumm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sub_rF(      coeff_t  lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_sub_rF_to(    coeff_t lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_sub_Fr(    feoarrm3n5_t* lhs,   coeff_t  rhs);
  void      feoarrm3n5_sub_Fr_to( feoarrm3n5_t* lhs,   coeff_t  rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_mul_FF(   feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_mul_FF_to(feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_mul_fF(    feonumm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_mul_fF_to( feonumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_mul_OF(     oarrm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_mul_OF_to(  oarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_mul_RF(      darr_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_mul_RF_to(   darr_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_mul_oF(   onumm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_mul_oF_to(onumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_mul_rF(     coeff_t  lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_mul_rF_to(  coeff_t  lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_div_FF(    feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_div_FF_to( feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_div_fF(     feonumm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_div_fF_to(  feonumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_div_Ff(    feoarrm3n5_t* lhs,  feonumm3n5_t* rhs);
  void      feoarrm3n5_div_Ff_to( feoarrm3n5_t* lhs,  feonumm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_div_OF(      oarrm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_div_OF_to(   oarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_div_FO(    feoarrm3n5_t* lhs,   oarrm3n5_t* rhs);
  void      feoarrm3n5_div_FO_to( feoarrm3n5_t* lhs,   oarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_div_RF(       darr_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_div_RF_to(    darr_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_div_FR(    feoarrm3n5_t* lhs,    darr_t* rhs);
  void      feoarrm3n5_div_FR_to( feoarrm3n5_t* lhs,    darr_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_div_oF(    onumm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_div_oF_to( onumm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_div_Fo(    feoarrm3n5_t* lhs, onumm3n5_t* rhs);
  void      feoarrm3n5_div_Fo_to( feoarrm3n5_t* lhs, onumm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_div_rF(      coeff_t  lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_div_rF_to(    coeff_t lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_div_Fr(    feoarrm3n5_t* lhs,   coeff_t  rhs);
  void      feoarrm3n5_div_Fr_to( feoarrm3n5_t* lhs,   coeff_t  rhs, feoarrm3n5_t* res);
  oarrm3n5_t feoarrm3n5_integrate(    feoarrm3n5_t* arr, feonumm3n5_t* w);
  void    feoarrm3n5_integrate_to( feoarrm3n5_t* arr, feonumm3n5_t* w, oarrm3n5_t* res);
  feonumm3n5_t feoarrm3n5_dotproduct_FF(    feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
  void     feoarrm3n5_dotproduct_FF_to( feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feoarrm3n5_dotproduct_OF(      oarrm3n5_t* lhs, feoarrm3n5_t* rhs);
  void     feoarrm3n5_dotproduct_OF_to(   oarrm3n5_t* lhs, feoarrm3n5_t* rhs, feonumm3n5_t* res);
  feonumm3n5_t feoarrm3n5_dotproduct_RF(       darr_t* lhs, feoarrm3n5_t* rhs);
  void     feoarrm3n5_dotproduct_RF_to(    darr_t* lhs, feoarrm3n5_t* rhs, feonumm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_matmul_FF(    feoarrm3n5_t* lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_matmul_FF_to( feoarrm3n5_t* lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_matmul_OF(    oarrm3n5_t*   lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_matmul_OF_to( oarrm3n5_t*   lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_matmul_FO(    feoarrm3n5_t* lhs, oarrm3n5_t*   rhs);
  void      feoarrm3n5_matmul_FO_to( feoarrm3n5_t* lhs, oarrm3n5_t*   rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_matmul_RF(    darr_t*    lhs, feoarrm3n5_t* rhs);
  void      feoarrm3n5_matmul_RF_to( darr_t*    lhs, feoarrm3n5_t* rhs, feoarrm3n5_t* res);
  feoarrm3n5_t feoarrm3n5_matmul_FR(    feoarrm3n5_t* lhs, darr_t*    rhs);
  void      feoarrm3n5_matmul_FR_to( feoarrm3n5_t* lhs, darr_t*    rhs, feoarrm3n5_t* res);
  feonumm3n5_t feoarrm3n5_det(   feoarrm3n5_t* arr);
  void     feoarrm3n5_det_to(feoarrm3n5_t* arr, feonumm3n5_t* res);
  feonumm3n5_t feoarrm3n5_norm(     feoarrm3n5_t* arr);
  void     feoarrm3n5_norm_to(  feoarrm3n5_t* arr, feonumm3n5_t* res);
  feonumm3n5_t feoarrm3n5_pnorm(    feoarrm3n5_t* arr, coeff_t p);
  void     feoarrm3n5_pnorm_to( feoarrm3n5_t* arr, coeff_t p, feonumm3n5_t* res);
  feoarrm3n5_t   feoarrm3n5_invert(    feoarrm3n5_t* arr);
  void        feoarrm3n5_invert_to( feoarrm3n5_t* arr, feoarrm3n5_t* res);
  feoarrm3n5_t   feoarrm3n5_transpose(   feoarrm3n5_t* arr);
  void        feoarrm3n5_transpose_to(feoarrm3n5_t* arr, feoarrm3n5_t* res);
  
  