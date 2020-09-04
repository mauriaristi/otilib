cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm4n4/scalar/structures.h
  
  ctypedef struct  onumm4n4_t : # {
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
    coeff_t e1114;
    coeff_t e1124;
    coeff_t e1224;
    coeff_t e2224;
    coeff_t e1134;
    coeff_t e1234;
    coeff_t e2234;
    coeff_t e1334;
    coeff_t e2334;
    coeff_t e3334;
    coeff_t e1144;
    coeff_t e1244;
    coeff_t e2244;
    coeff_t e1344;
    coeff_t e2344;
    coeff_t e3344;
    coeff_t e1444;
    coeff_t e2444;
    coeff_t e3444;
    coeff_t e4444;
  # } onumm4n4_t;
  
  
  # From ../../../include/oti/static/onumm4n4/array/structures.h
  
  ctypedef struct  oarrm4n4_t : # {
      onumm4n4_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm4n4_t;
  
  
  # From ../../../include/oti/static/onumm4n4/scalar/gauss/structures.h
  
  ctypedef struct  feonumm4n4_t: # {
      onumm4n4_t*  p_data;
      uint64_t    nip;
  # } feonumm4n4_t;
  
  
  # From ../../../include/oti/static/onumm4n4/array/gauss/structures.h
  
  ctypedef struct  feoarrm4n4_t: # {
      oarrm4n4_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm4n4_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm4n4/scalar/functions.h
  
  onumm4n4_t onumm4n4_atanh(onumm4n4_t* num);
  void onumm4n4_atanh_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_asinh(onumm4n4_t* num);
  void onumm4n4_asinh_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_acosh(onumm4n4_t* num);
  void onumm4n4_acosh_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_tanh(onumm4n4_t* num);
  void onumm4n4_tanh_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_sqrt(onumm4n4_t* num);
  void onumm4n4_sqrt_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_cbrt(onumm4n4_t* num);
  void onumm4n4_cbrt_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_cosh(onumm4n4_t* num);
  void onumm4n4_cosh_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_sinh(onumm4n4_t* num);
  void onumm4n4_sinh_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_asin(onumm4n4_t* num);
  void onumm4n4_asin_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_acos(onumm4n4_t* num);
  void onumm4n4_acos_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_atan(onumm4n4_t* num);
  void onumm4n4_atan_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_tan(onumm4n4_t* num);
  void onumm4n4_tan_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_cos(onumm4n4_t* num);
  void onumm4n4_cos_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_sin(onumm4n4_t* num );
  void onumm4n4_sin_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_logb(onumm4n4_t* num, double base);
  void onumm4n4_logb_to(onumm4n4_t* num, double base, onumm4n4_t* res);
  onumm4n4_t onumm4n4_log10(onumm4n4_t* num);
  void onumm4n4_log10_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_log(onumm4n4_t* num);
  void onumm4n4_log_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_exp(onumm4n4_t* num);
  void onumm4n4_exp_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_pow(onumm4n4_t* num, double e);
  void onumm4n4_pow_to(onumm4n4_t* num, coeff_t e, onumm4n4_t* res);
  
  
  # From ../../../include/oti/static/onumm4n4/scalar/base.h
  
  void onumm4n4_set_im_o(onumm4n4_t* num, imdir_t idx, ord_t order, onumm4n4_t* res);
  void onumm4n4_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm4n4_t* res);
  void onumm4n4_set_deriv_o(onumm4n4_t* num, imdir_t idx, ord_t order, onumm4n4_t* res);
  void onumm4n4_extract_im_to( imdir_t idx, ord_t order, onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_extract_im(imdir_t idx, ord_t order, onumm4n4_t* num);
  onumm4n4_t onumm4n4_extract_deriv(imdir_t idx, ord_t order, onumm4n4_t* num);
  void onumm4n4_extract_deriv_to(imdir_t idx, ord_t order, onumm4n4_t* num, onumm4n4_t* res);
  void onumm4n4_get_im_to_o(imdir_t idx, ord_t order, onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_get_im_o(imdir_t idx, ord_t order, onumm4n4_t* num);
  void onumm4n4_get_im_to_r(imdir_t idx, ord_t order, onumm4n4_t* num, coeff_t* res);
  ord_t onumm4n4_get_order(onumm4n4_t* lhs);
  onumm4n4_t onumm4n4_get_deriv_o( imdir_t idx, ord_t order, onumm4n4_t* num);
  void onumm4n4_get_deriv_to( imdir_t idx, ord_t order, onumm4n4_t* num, onumm4n4_t* res);
  void onumm4n4_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm4n4_t* res);
  onumm4n4_t onumm4n4_init();
  ndir_t onumm4n4_get_ndir_order(ord_t order, onumm4n4_t* num);
  ndir_t onumm4n4_get_ndir_total(onumm4n4_t* num);
  coeff_t* onumm4n4_get_order_address(ord_t order, onumm4n4_t* num);
  onumm4n4_t onumm4n4_create_r(  coeff_t lhs);
  void onumm4n4_set_r(  coeff_t lhs, onumm4n4_t* res);
  void onumm4n4_set_o(  onumm4n4_t* lhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_get_order_im(ord_t order, onumm4n4_t* lhs);
  void onumm4n4_get_order_im_to(ord_t order, onumm4n4_t* lhs, onumm4n4_t* res);
  coeff_t onumm4n4_get_item(imdir_t idx, ord_t order, onumm4n4_t* lhs);
  coeff_t onumm4n4_get_deriv(imdir_t idx, ord_t order, onumm4n4_t* lhs);
  void onumm4n4_set_item(coeff_t val, imdir_t idx, ord_t order, onumm4n4_t* x);
  onumm4n4_t onumm4n4_copy(  onumm4n4_t* lhs);
  void onumm4n4_copy_to(  onumm4n4_t* lhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_taylor_integrate(coeff_t* deltas,onumm4n4_t* lhs);
  void onumm4n4_taylor_integrate_to(coeff_t* deltas,onumm4n4_t* lhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_truncate_im(imdir_t idx, ord_t order, onumm4n4_t* lhs);
  void onumm4n4_truncate_im_to(imdir_t idx, ord_t order, onumm4n4_t* lhs, onumm4n4_t* res);
  void onumm4n4_print(  onumm4n4_t* lhs);
  imdir_t onumm4n4_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm4n4/scalar/utils.h
  
  void onumm4n4_get_active_bases(onumm4n4_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm4n4/scalar/algebra.h
  
  onumm4n4_t onumm4n4_abs(onumm4n4_t* num);
  onumm4n4_t onumm4n4_div_ro(coeff_t num, onumm4n4_t* den);
  onumm4n4_t onumm4n4_div_oo(onumm4n4_t* num, onumm4n4_t* den);
  onumm4n4_t onumm4n4_div_or(onumm4n4_t* num, coeff_t val);
  void onumm4n4_div_ro_to(coeff_t num, onumm4n4_t* den, onumm4n4_t* res);
  void onumm4n4_div_oo_to(onumm4n4_t* num, onumm4n4_t* den, onumm4n4_t* res);
  void onumm4n4_div_or_to(onumm4n4_t* num, coeff_t val, onumm4n4_t* res);
  void onumm4n4_abs_to(onumm4n4_t* num, onumm4n4_t* res);
  onumm4n4_t onumm4n4_neg(  onumm4n4_t* lhs);
  void onumm4n4_neg_to(  onumm4n4_t* lhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_sum_oo(  onumm4n4_t* lhs,  onumm4n4_t* rhs);
  void onumm4n4_sum_oo_to(  onumm4n4_t* lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_sum_ro(  coeff_t lhs,  onumm4n4_t* rhs);
  void onumm4n4_sum_ro_to(  coeff_t lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_sub_oo(  onumm4n4_t* lhs,  onumm4n4_t* rhs);
  void onumm4n4_sub_oo_to(  onumm4n4_t* lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_sub_ro(  coeff_t lhs,  onumm4n4_t* rhs);
  void onumm4n4_sub_ro_to(  coeff_t lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_sub_or(  onumm4n4_t* lhs,  coeff_t rhs);
  void onumm4n4_sub_or_to(  onumm4n4_t* lhs,  coeff_t rhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_mul_oo(  onumm4n4_t* lhs,  onumm4n4_t* rhs);
  void onumm4n4_mul_oo_to(  onumm4n4_t* lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_mul_ro(  coeff_t lhs,  onumm4n4_t* rhs);
  void onumm4n4_mul_ro_to(  coeff_t lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_trunc_mul_oo(  onumm4n4_t* lhs,  onumm4n4_t* rhs);
  void onumm4n4_trunc_mul_oo_to(  onumm4n4_t* lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
  onumm4n4_t onumm4n4_gem_oo(  onumm4n4_t* a,  onumm4n4_t* b,  onumm4n4_t* c);
  void onumm4n4_gem_oo_to(  onumm4n4_t* a,  onumm4n4_t* b,  onumm4n4_t* c, onumm4n4_t* res);
  onumm4n4_t onumm4n4_gem_ro(  coeff_t a,  onumm4n4_t* b,  onumm4n4_t* c);
  void onumm4n4_gem_ro_to(  coeff_t a,  onumm4n4_t* b,  onumm4n4_t* c, onumm4n4_t* res);
  void onumm4n4_trunc_gem_oo_to( ord_t ord_lhs,  onumm4n4_t* a,  ord_t ord_rhs,  onumm4n4_t* b,  onumm4n4_t* c, onumm4n4_t* res);
  onumm4n4_t onumm4n4_feval(coeff_t* feval_re, onumm4n4_t* x);
  void onumm4n4_feval_to(coeff_t* feval_re, onumm4n4_t* x, onumm4n4_t* res);
  
  
  # From ../../../include/oti/static/onumm4n4/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm4n4/scalar/gauss/functions.h
  
  feonumm4n4_t feonumm4n4_atanh(    feonumm4n4_t* num);
  void     feonumm4n4_atanh_to( feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_asinh(    feonumm4n4_t* num);
  void     feonumm4n4_asinh_to( feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_acosh(    feonumm4n4_t* num);
  void     feonumm4n4_acosh_to( feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_tanh(     feonumm4n4_t* num);
  void     feonumm4n4_tanh_to(  feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_cosh(     feonumm4n4_t* num);
  void     feonumm4n4_cosh_to(  feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_sinh(     feonumm4n4_t* num);
  void     feonumm4n4_sinh_to(  feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_asin(     feonumm4n4_t* num);
  void     feonumm4n4_asin_to(  feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_acos(     feonumm4n4_t* num);
  void     feonumm4n4_acos_to(  feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_atan(     feonumm4n4_t* num);
  void     feonumm4n4_atan_to(  feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_tan(      feonumm4n4_t* num);
  void     feonumm4n4_tan_to(   feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_cos(      feonumm4n4_t* num);
  void     feonumm4n4_cos_to(   feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_sin(      feonumm4n4_t* num);
  void     feonumm4n4_sin_to(   feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_logb(     feonumm4n4_t* num, double base);
  void     feonumm4n4_logb_to(  feonumm4n4_t* num, double base, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_log10(    feonumm4n4_t* num);
  void     feonumm4n4_log10_to( feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_log(      feonumm4n4_t* num);
  void     feonumm4n4_log_to(   feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_exp(      feonumm4n4_t* num);
  void     feonumm4n4_exp_to(   feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_cbrt(     feonumm4n4_t* num);
  void     feonumm4n4_cbrt_to(  feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_sqrt(     feonumm4n4_t* num);
  void     feonumm4n4_sqrt_to(  feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_pow(      feonumm4n4_t* num, double e);
  void     feonumm4n4_pow_to(   feonumm4n4_t* num, double e, feonumm4n4_t* res);
  onumm4n4_t feonumm4n4_integrate(       feonumm4n4_t* num, feonumm4n4_t* w);
  void      feonumm4n4_integrate_to(    feonumm4n4_t* num, feonumm4n4_t* w, onumm4n4_t* res);
  onumm4n4_t feonumm4n4_integrate_f(     feonumm4n4_t* num, feonumm4n4_t* w);
  void      feonumm4n4_integrate_f_to(  feonumm4n4_t* num, feonumm4n4_t* w, onumm4n4_t* res);
  onumm4n4_t feonumm4n4_integrate_r(       coeff_t num, feonumm4n4_t* w);
  void      feonumm4n4_integrate_r_to(    coeff_t num, feonumm4n4_t* w, onumm4n4_t* res);
  onumm4n4_t feonumm4n4_integrate_o(    onumm4n4_t* num, feonumm4n4_t* w);
  void      feonumm4n4_integrate_o_to( onumm4n4_t* num, feonumm4n4_t* w, onumm4n4_t* res);
  
  
  # From ../../../include/oti/static/onumm4n4/scalar/gauss/base.h
  
  void     feonumm4n4_get_order_im_to( ord_t order, feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_get_order_im(    ord_t order, feonumm4n4_t* num);
  feonumm4n4_t feonumm4n4_get_im(    imdir_t idx, ord_t order, feonumm4n4_t* num);
  void     feonumm4n4_get_im_to( imdir_t idx, ord_t order, feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_get_deriv(    imdir_t idx, ord_t order, feonumm4n4_t* num);
  void     feonumm4n4_get_deriv_to( imdir_t idx, ord_t order, feonumm4n4_t* num, feonumm4n4_t* res);
  void feonumm4n4_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm4n4_t* num);
  void feonumm4n4_set_im_o( onumm4n4_t* val, imdir_t idx, ord_t order, feonumm4n4_t* num);
  void feonumm4n4_set_im_f(  feonumm4n4_t* val, imdir_t idx, ord_t order, feonumm4n4_t* num);
  void feonumm4n4_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm4n4_t* num);
  void feonumm4n4_set_deriv_o( onumm4n4_t* val, imdir_t idx, ord_t order, feonumm4n4_t* num);
  void feonumm4n4_set_deriv_f(  feonumm4n4_t* val, imdir_t idx, ord_t order, feonumm4n4_t* num);
  feonumm4n4_t feonumm4n4_extract_im(    imdir_t idx, ord_t order, feonumm4n4_t* num);
  void     feonumm4n4_extract_im_to( imdir_t idx, ord_t order, feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_extract_deriv(    imdir_t idx, ord_t order, feonumm4n4_t* num);
  void     feonumm4n4_extract_deriv_to( imdir_t idx, ord_t order, feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_truncate_im(    imdir_t idx, ord_t order, feonumm4n4_t* num);
  void     feonumm4n4_truncate_im_to( imdir_t idx, ord_t order, feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_copy(    feonumm4n4_t* src);
  void     feonumm4n4_copy_to( feonumm4n4_t* src, feonumm4n4_t* dst);
  void feonumm4n4_set_r(    coeff_t num, feonumm4n4_t* res);
  void feonumm4n4_set_o( onumm4n4_t* num, feonumm4n4_t* res);
  void feonumm4n4_set_f(  feonumm4n4_t* num, feonumm4n4_t* res);
  void feonumm4n4_set_item_k_r(   coeff_t  num, uint64_t k, feonumm4n4_t* res);
  void feonumm4n4_set_item_k_o( onumm4n4_t* num, uint64_t k, feonumm4n4_t* res);
  onumm4n4_t feonumm4n4_get_item_k(   feonumm4n4_t* num, uint64_t k);
  void      feonumm4n4_get_item_k_to(feonumm4n4_t* num, uint64_t k, onumm4n4_t* res);
  feonumm4n4_t feonumm4n4_zeros(uint64_t nIntPts);
  feonumm4n4_t feonumm4n4_createEmpty(uint64_t nIntPts);
  feonumm4n4_t feonumm4n4_empty_like(feonumm4n4_t* arr);
  void feonumm4n4_free(feonumm4n4_t* num);
  ord_t feonumm4n4_get_order( feonumm4n4_t* num );
  feonumm4n4_t feonumm4n4_init();
  
  
  # From ../../../include/oti/static/onumm4n4/scalar/gauss/utils.h
  
  void feonumm4n4_dimCheck(feonumm4n4_t* arr1,feonumm4n4_t* arr2);
  void feonumm4n4_get_active_bases(feonumm4n4_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n4/scalar/gauss/algebra.h
  
  feonumm4n4_t feonumm4n4_neg(   feonumm4n4_t* num);
  void     feonumm4n4_neg_to(feonumm4n4_t* num, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_sum_ff(   feonumm4n4_t* lhs, feonumm4n4_t* rhs);
  void     feonumm4n4_sum_ff_to(feonumm4n4_t* lhs, feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_sum_of(   onumm4n4_t* lhs, feonumm4n4_t* rhs);
  void     feonumm4n4_sum_of_to(onumm4n4_t* lhs, feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_sum_rf(   coeff_t lhs, feonumm4n4_t* rhs);
  void     feonumm4n4_sum_rf_to(coeff_t lhs, feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_sub_ff(     feonumm4n4_t* lhs,  feonumm4n4_t* rhs);
  void     feonumm4n4_sub_ff_to(  feonumm4n4_t* lhs,  feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_sub_of(    onumm4n4_t* lhs,  feonumm4n4_t* rhs);
  void     feonumm4n4_sub_of_to( onumm4n4_t* lhs,  feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_sub_fo(     feonumm4n4_t* lhs, onumm4n4_t* rhs);
  void     feonumm4n4_sub_fo_to(  feonumm4n4_t* lhs, onumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_sub_rf(       coeff_t lhs,  feonumm4n4_t* rhs);
  void     feonumm4n4_sub_rf_to(    coeff_t lhs,  feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_sub_fr(     feonumm4n4_t* lhs,    coeff_t rhs);
  void     feonumm4n4_sub_fr_to(  feonumm4n4_t* lhs,    coeff_t rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_mul_ff(   feonumm4n4_t* lhs, feonumm4n4_t* rhs);
  void     feonumm4n4_mul_ff_to(feonumm4n4_t* lhs, feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_mul_of(   onumm4n4_t* lhs, feonumm4n4_t* rhs);
  void     feonumm4n4_mul_of_to(onumm4n4_t* lhs, feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_mul_rf(   coeff_t lhs, feonumm4n4_t* rhs);
  void     feonumm4n4_mul_rf_to(coeff_t lhs, feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_div_ff(     feonumm4n4_t* lhs,  feonumm4n4_t* rhs);
  void     feonumm4n4_div_ff_to(  feonumm4n4_t* lhs,  feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_div_of(    onumm4n4_t* lhs,  feonumm4n4_t* rhs);
  void     feonumm4n4_div_of_to( onumm4n4_t* lhs,  feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_div_fo(     feonumm4n4_t* lhs, onumm4n4_t* rhs);
  void     feonumm4n4_div_fo_to(  feonumm4n4_t* lhs, onumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_div_rf(       coeff_t lhs,  feonumm4n4_t* rhs);
  void     feonumm4n4_div_rf_to(    coeff_t lhs,  feonumm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feonumm4n4_div_fr(     feonumm4n4_t* lhs,    coeff_t rhs);
  void     feonumm4n4_div_fr_to(  feonumm4n4_t* lhs,    coeff_t rhs, feonumm4n4_t* res);
  
  
  # From ../../../include/oti/static/onumm4n4/array/functions.h
  
  oarrm4n4_t oarrm4n4_atanh(   oarrm4n4_t* arr);
  void    oarrm4n4_atanh_to(oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_asinh(   oarrm4n4_t* arr);
  void    oarrm4n4_asinh_to(oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_acosh(   oarrm4n4_t* arr);
  void    oarrm4n4_acosh_to(oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_tanh(    oarrm4n4_t* arr);
  void    oarrm4n4_tanh_to( oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_cbrt(    oarrm4n4_t* arr);
  void    oarrm4n4_cbrt_to( oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_sqrt(    oarrm4n4_t* arr);
  void    oarrm4n4_sqrt_to( oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_cosh(    oarrm4n4_t* arr);
  void    oarrm4n4_cosh_to( oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_sinh(    oarrm4n4_t* arr);
  void    oarrm4n4_sinh_to( oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_asin(    oarrm4n4_t* arr);
  void    oarrm4n4_asin_to( oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_acos(    oarrm4n4_t* arr);
  void    oarrm4n4_acos_to( oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_atan(    oarrm4n4_t* arr);
  void    oarrm4n4_atan_to( oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_tan(     oarrm4n4_t* arr);
  void    oarrm4n4_tan_to(  oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_cos(     oarrm4n4_t* arr);
  void    oarrm4n4_cos_to(  oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_sin(     oarrm4n4_t* arr);
  void    oarrm4n4_sin_to(  oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_logb(    oarrm4n4_t* arr, double base);
  void    oarrm4n4_logb_to( oarrm4n4_t* arr, double base, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_log10(   oarrm4n4_t* arr);
  void    oarrm4n4_log10_to(oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_log(     oarrm4n4_t* arr);
  void    oarrm4n4_log_to(  oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_exp(     oarrm4n4_t* arr);
  void    oarrm4n4_exp_to(  oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_pow(     oarrm4n4_t* arr, double e);
  void    oarrm4n4_pow_to(  oarrm4n4_t* arr, double e, oarrm4n4_t* res);
  
  
  # From ../../../include/oti/static/onumm4n4/array/algebra_elementwise.h
  
  oarrm4n4_t oarrm4n4_neg(oarrm4n4_t* arr);
  void oarrm4n4_neg_to(oarrm4n4_t* rhs, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_sum_OO(oarrm4n4_t*   lhs, oarrm4n4_t* rhs);
  oarrm4n4_t oarrm4n4_sum_RO(darr_t*    lhs, oarrm4n4_t* rhs);
  oarrm4n4_t oarrm4n4_sum_oO(onumm4n4_t* lhs, oarrm4n4_t* rhs);
  oarrm4n4_t oarrm4n4_sum_rO(coeff_t    lhs, oarrm4n4_t* rhs);
  void oarrm4n4_sum_OO_to(oarrm4n4_t*   lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
  void oarrm4n4_sum_RO_to(darr_t*    lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
  void oarrm4n4_sum_oO_to(onumm4n4_t* lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
  void oarrm4n4_sum_rO_to(coeff_t    lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_sub_OO(oarrm4n4_t*   lhs, oarrm4n4_t*   rhs);
  oarrm4n4_t oarrm4n4_sub_RO(darr_t*    lhs, oarrm4n4_t*   rhs);
  oarrm4n4_t oarrm4n4_sub_OR(oarrm4n4_t*   lhs, darr_t*    rhs);
  oarrm4n4_t oarrm4n4_sub_oO(onumm4n4_t* lhs, oarrm4n4_t*   rhs);
  oarrm4n4_t oarrm4n4_sub_Oo(oarrm4n4_t*   lhs, onumm4n4_t* rhs);
  oarrm4n4_t oarrm4n4_sub_rO(coeff_t    lhs, oarrm4n4_t*   rhs);
  oarrm4n4_t oarrm4n4_sub_Or(oarrm4n4_t*   lhs, coeff_t    rhs);
  void oarrm4n4_sub_OO_to( oarrm4n4_t*   lhs, oarrm4n4_t*   rhs, oarrm4n4_t* res);
  void oarrm4n4_sub_RO_to( darr_t*    lhs, oarrm4n4_t*   rhs, oarrm4n4_t* res);
  void oarrm4n4_sub_OR_to( oarrm4n4_t*   lhs, darr_t*    rhs, oarrm4n4_t* res);
  void oarrm4n4_sub_oO_to( onumm4n4_t* lhs, oarrm4n4_t*   rhs, oarrm4n4_t* res);
  void oarrm4n4_sub_Oo_to( oarrm4n4_t*   lhs, onumm4n4_t* rhs, oarrm4n4_t* res);
  void oarrm4n4_sub_rO_to( coeff_t    lhs, oarrm4n4_t*   rhs, oarrm4n4_t* res);
  void oarrm4n4_sub_Or_to( oarrm4n4_t*   lhs, coeff_t    rhs, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_mul_OO(oarrm4n4_t*   lhs, oarrm4n4_t* rhs);
  oarrm4n4_t oarrm4n4_mul_RO(darr_t*    lhs, oarrm4n4_t* rhs);
  oarrm4n4_t oarrm4n4_mul_oO(onumm4n4_t* lhs, oarrm4n4_t* rhs);
  oarrm4n4_t oarrm4n4_mul_rO(coeff_t    lhs, oarrm4n4_t* rhs);
  void oarrm4n4_mul_OO_to(oarrm4n4_t*   lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
  void oarrm4n4_mul_RO_to(darr_t*    lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
  void oarrm4n4_mul_oO_to(onumm4n4_t* lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
  void oarrm4n4_mul_rO_to(coeff_t    lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
  void oarrm4n4_gem_OO_to(  oarrm4n4_t* arr1, oarrm4n4_t* arr2, oarrm4n4_t* arr3, oarrm4n4_t* res);
  void oarrm4n4_gem_oO_to(onumm4n4_t* arr1, oarrm4n4_t* arr2, oarrm4n4_t* arr3, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_div_OO(oarrm4n4_t*   lhs, oarrm4n4_t*   rhs);
  oarrm4n4_t oarrm4n4_div_OR(oarrm4n4_t*   lhs, darr_t*    rhs);
  oarrm4n4_t oarrm4n4_div_RO(darr_t*    lhs, oarrm4n4_t*   rhs);
  oarrm4n4_t oarrm4n4_div_oO(onumm4n4_t* lhs, oarrm4n4_t*   rhs);
  oarrm4n4_t oarrm4n4_div_Oo(oarrm4n4_t*   lhs, onumm4n4_t* rhs);
  oarrm4n4_t oarrm4n4_div_rO(coeff_t    lhs, oarrm4n4_t*   rhs);
  oarrm4n4_t oarrm4n4_div_Or(oarrm4n4_t*   lhs, coeff_t    rhs);
  void oarrm4n4_div_OO_to(oarrm4n4_t*   lhs, oarrm4n4_t*   rhs, oarrm4n4_t* res);
  void oarrm4n4_div_RO_to(darr_t*    lhs, oarrm4n4_t*   rhs, oarrm4n4_t* res);
  void oarrm4n4_div_OR_to(oarrm4n4_t*   lhs, darr_t*    rhs, oarrm4n4_t* res);
  void oarrm4n4_div_oO_to(onumm4n4_t* lhs, oarrm4n4_t*   rhs, oarrm4n4_t* res);
  void oarrm4n4_div_Oo_to(oarrm4n4_t*   lhs, onumm4n4_t* rhs, oarrm4n4_t* res);
  void oarrm4n4_div_rO_to(coeff_t    lhs, oarrm4n4_t*   rhs, oarrm4n4_t* res);
  void oarrm4n4_div_Or_to(oarrm4n4_t*   lhs, coeff_t    rhs, oarrm4n4_t* res);
  
  
  # From ../../../include/oti/static/onumm4n4/array/base.h
  
  void    oarrm4n4_taylor_integrate_to( coeff_t* deltas, oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_taylor_integrate(    coeff_t* deltas, oarrm4n4_t* arr);
  void    oarrm4n4_get_order_im_to( ord_t order, oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_get_order_im(    ord_t order, oarrm4n4_t* arr);
  void oarrm4n4_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n4_t* res);
  void oarrm4n4_set_slice_O( oarrm4n4_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n4_t* res);
  void oarrm4n4_set_slice_o( onumm4n4_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_get_slice( oarrm4n4_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm4n4_get_slice_to( oarrm4n4_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_truncate_im(    imdir_t idx, ord_t order, oarrm4n4_t* arr);
  void    oarrm4n4_truncate_im_to( imdir_t idx, ord_t order, oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_extract_im(   imdir_t idx, ord_t order, oarrm4n4_t* arr);
  void    oarrm4n4_extract_im_to(imdir_t idx, ord_t order, oarrm4n4_t* arr, oarrm4n4_t* res);
  darr_t  oarrm4n4_get_deriv(    imdir_t idx, ord_t order, oarrm4n4_t* arr);
  void    oarrm4n4_get_deriv_to( imdir_t idx, ord_t order, oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_get_deriv_o(  imdir_t idx, ord_t order, oarrm4n4_t* arr);
  oarrm4n4_t oarrm4n4_extract_deriv(    imdir_t idx, ord_t order, oarrm4n4_t* arr);
  void    oarrm4n4_extract_deriv_to( imdir_t idx, ord_t order, oarrm4n4_t* arr, oarrm4n4_t* res);
  darr_t  oarrm4n4_get_im(   imdir_t idx, ord_t order, oarrm4n4_t* arr);
  oarrm4n4_t oarrm4n4_get_im_o( imdir_t idx, ord_t order, oarrm4n4_t* arr);
  void    oarrm4n4_get_im_to(imdir_t idx, ord_t order, oarrm4n4_t* arr, oarrm4n4_t* res);
  void    oarrm4n4_copy_to(oarrm4n4_t* arr, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_copy(oarrm4n4_t* arr);
  void oarrm4n4_set_all_r( coeff_t num, oarrm4n4_t* arr);
  void oarrm4n4_set_item_i_r( coeff_t num, uint64_t i, oarrm4n4_t* arr);
  void oarrm4n4_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm4n4_t* arr);
  void oarrm4n4_set_r(   coeff_t  num,   oarrm4n4_t* arr);
  void oarrm4n4_set_o( onumm4n4_t* num,   oarrm4n4_t* arr);
  void oarrm4n4_set_O(   oarrm4n4_t* arrin, oarrm4n4_t* arr);
  void oarrm4n4_set_all_o( onumm4n4_t* src, oarrm4n4_t* arr);
  void oarrm4n4_set_item_i_o( onumm4n4_t* num, uint64_t i, oarrm4n4_t* arr);
  void oarrm4n4_set_item_ij_o( onumm4n4_t* num, uint64_t i, uint64_t j, oarrm4n4_t* arr);
  onumm4n4_t oarrm4n4_get_item_i(    oarrm4n4_t* arr, uint64_t i);
  void      oarrm4n4_get_item_i_to( oarrm4n4_t* arr, uint64_t i,             onumm4n4_t* res);
  onumm4n4_t oarrm4n4_get_item_ij(   oarrm4n4_t* arr, uint64_t i, uint64_t j);
  void      oarrm4n4_get_item_ij_to(oarrm4n4_t* arr, uint64_t i, uint64_t j, onumm4n4_t* res);
  oarrm4n4_t oarrm4n4_init();
  void oarrm4n4_free(oarrm4n4_t* arr);
  oarrm4n4_t oarrm4n4_empty_like(oarrm4n4_t* arr);
  oarrm4n4_t oarrm4n4_eye(uint64_t nrows);
  oarrm4n4_t oarrm4n4_ones(uint64_t nrows, uint64_t ncols);
  oarrm4n4_t oarrm4n4_zeros(uint64_t nrows, uint64_t ncols);
  oarrm4n4_t oarrm4n4_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm4n4/array/utils.h
  
  void oarrm4n4_dimCheck_OO_elementwise(oarrm4n4_t* arr1, oarrm4n4_t* arr2, oarrm4n4_t* res);
  void oarrm4n4_dimCheck_RO_elementwise(darr_t*  arr1, oarrm4n4_t* arr2, oarrm4n4_t* res);
  void oarrm4n4_dimCheck_OO_matmul(oarrm4n4_t* arr1, oarrm4n4_t* arr2, oarrm4n4_t* res);
  void oarrm4n4_dimCheck_RO_matmul(darr_t*  arr1, oarrm4n4_t* arr2, oarrm4n4_t* res);
  void oarrm4n4_dimCheck_OR_matmul(oarrm4n4_t* arr1, darr_t*  arr2, oarrm4n4_t* res);
  void oarrm4n4_dimCheck_O_squareness(oarrm4n4_t* arr1, oarrm4n4_t* res);
  void oarrm4n4_dimCheck_OO_samesize(oarrm4n4_t* arr1, oarrm4n4_t* res);
  void oarrm4n4_dimCheck_RO_samesize(darr_t* arr1, oarrm4n4_t* res);
  ord_t oarrm4n4_get_order(oarrm4n4_t* arr);
  void oarrm4n4_get_active_bases(oarrm4n4_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n4/array/algebra_matops.h
  
  onumm4n4_t oarrm4n4_dotproduct_OO(    oarrm4n4_t* lhs, oarrm4n4_t* rhs);
  void      oarrm4n4_dotproduct_OO_to( oarrm4n4_t* lhs, oarrm4n4_t* rhs, onumm4n4_t* res);
  onumm4n4_t oarrm4n4_dotproduct_RO(     darr_t* lhs, oarrm4n4_t* rhs);
  void      oarrm4n4_dotproduct_RO_to(  darr_t* lhs, oarrm4n4_t* rhs, onumm4n4_t* res);
  oarrm4n4_t oarrm4n4_matmul_OO(    oarrm4n4_t* lhs, oarrm4n4_t* rhs);
  oarrm4n4_t oarrm4n4_matmul_OR(    oarrm4n4_t* lhs,  darr_t* rhs);
  oarrm4n4_t oarrm4n4_matmul_RO(     darr_t* lhs, oarrm4n4_t* rhs);
  void    oarrm4n4_matmul_OO_to( oarrm4n4_t* lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
  void    oarrm4n4_matmul_OR_to( oarrm4n4_t* lhs,  darr_t* rhs, oarrm4n4_t* res);
  void    oarrm4n4_matmul_RO_to(  darr_t* lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_transpose(    oarrm4n4_t* arr1);
  void    oarrm4n4_transpose_to( oarrm4n4_t* arr1, oarrm4n4_t* res);
  oarrm4n4_t oarrm4n4_invert(    oarrm4n4_t* arr1);
  void    oarrm4n4_invert_to( oarrm4n4_t* arr1, oarrm4n4_t* res);
  onumm4n4_t oarrm4n4_det(    oarrm4n4_t* arr1);
  void      oarrm4n4_det_to( oarrm4n4_t* arr1, onumm4n4_t* res);
  onumm4n4_t oarrm4n4_norm(    oarrm4n4_t* arr1);
  void      oarrm4n4_norm_to( oarrm4n4_t* arr1,  onumm4n4_t* res);
  onumm4n4_t oarrm4n4_pnorm(    oarrm4n4_t* arr1, coeff_t p);
  void      oarrm4n4_pnorm_to( oarrm4n4_t* arr1, coeff_t p, onumm4n4_t* res);
  
  
  # From ../../../include/oti/static/onumm4n4/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm4n4/array/gauss/functions.h
  
  feoarrm4n4_t feoarrm4n4_atanh(    feoarrm4n4_t* arr);
  void      feoarrm4n4_atanh_to( feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_asinh(    feoarrm4n4_t* arr);
  void      feoarrm4n4_asinh_to( feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_acosh(    feoarrm4n4_t* arr);
  void      feoarrm4n4_acosh_to( feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_tanh(     feoarrm4n4_t* arr);
  void      feoarrm4n4_tanh_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sinh(     feoarrm4n4_t* arr);
  void      feoarrm4n4_sinh_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_cosh(     feoarrm4n4_t* arr);
  void      feoarrm4n4_cosh_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_atan(     feoarrm4n4_t* arr);
  void      feoarrm4n4_atan_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_asin(     feoarrm4n4_t* arr);
  void      feoarrm4n4_asin_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_acos(     feoarrm4n4_t* arr);
  void      feoarrm4n4_acos_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_tan(      feoarrm4n4_t* arr);
  void      feoarrm4n4_tan_to(   feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sin(      feoarrm4n4_t* arr);
  void      feoarrm4n4_sin_to(   feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_cos(      feoarrm4n4_t* arr);
  void      feoarrm4n4_cos_to(   feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_logb(     feoarrm4n4_t* arr, double base);
  void      feoarrm4n4_logb_to(  feoarrm4n4_t* arr, double base, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_log10(    feoarrm4n4_t* arr);
  void      feoarrm4n4_log10_to( feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_log(      feoarrm4n4_t* arr);
  void      feoarrm4n4_log_to(   feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_exp(      feoarrm4n4_t* arr);
  void      feoarrm4n4_exp_to(   feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_cbrt(     feoarrm4n4_t* arr);
  void      feoarrm4n4_cbrt_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sqrt(     feoarrm4n4_t* arr);
  void      feoarrm4n4_sqrt_to(  feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_pow(      feoarrm4n4_t* arr, double e);
  void      feoarrm4n4_pow_to(   feoarrm4n4_t* arr, double e, feoarrm4n4_t* res);
  
  
  # From ../../../include/oti/static/onumm4n4/array/gauss/base.h
  
  void      feoarrm4n4_get_order_im_to( ord_t order, feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_get_order_im(    ord_t order, feoarrm4n4_t* arr);
  feoarrm4n4_t feoarrm4n4_get_deriv(   imdir_t idx, ord_t order, feoarrm4n4_t* arr);
  void      feoarrm4n4_get_deriv_to(imdir_t idx, ord_t order, feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_get_im(      imdir_t idx, ord_t order, feoarrm4n4_t* arr);
  void      feoarrm4n4_get_im_to(   imdir_t idx, ord_t order, feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_truncate_im(   imdir_t idx, ord_t order, feoarrm4n4_t* arr);
  void      feoarrm4n4_truncate_im_to(imdir_t idx, ord_t order, feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_copy(   feoarrm4n4_t* src);
  void      feoarrm4n4_copy_to(feoarrm4n4_t* src, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_get_im(    imdir_t idx, ord_t order, feoarrm4n4_t* arr);
  void      feoarrm4n4_get_im_to( imdir_t idx, ord_t order, feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_get_deriv(    imdir_t idx, ord_t order, feoarrm4n4_t* arr);
  void      feoarrm4n4_get_deriv_to( imdir_t idx, ord_t order, feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_extract_im(    imdir_t idx, ord_t order, feoarrm4n4_t* arr);
  void      feoarrm4n4_extract_im_to( imdir_t idx, ord_t order, feoarrm4n4_t* arr,  feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_extract_deriv(    imdir_t idx, ord_t order, feoarrm4n4_t* arr);
  void      feoarrm4n4_extract_deriv_to( imdir_t idx, ord_t order, feoarrm4n4_t* arr, feoarrm4n4_t* res);
  oarrm4n4_t   feoarrm4n4_get_item_k(  feoarrm4n4_t* arr, uint64_t k);
  feonumm4n4_t  feoarrm4n4_get_item_ij( feoarrm4n4_t* arr, uint64_t i, uint64_t j);
  onumm4n4_t feoarrm4n4_get_item_ijk(feoarrm4n4_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm4n4_get_item_ij_to(  feoarrm4n4_t* arr, uint64_t i, uint64_t j,
                                 feonumm4n4_t* res);
  void feoarrm4n4_get_item_k_to(   feoarrm4n4_t* arr, uint64_t k,
                                  oarrm4n4_t* res);
  void feoarrm4n4_get_item_ijk_to( feoarrm4n4_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_get_slice(feoarrm4n4_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm4n4_get_slice_to(feoarrm4n4_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n4_t* res);
  void feoarrm4n4_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm4n4_t* res);
  void feoarrm4n4_set_item_ij_o(  onumm4n4_t* elm, uint64_t i, uint64_t j,
                               feoarrm4n4_t* res);
  void feoarrm4n4_set_item_ij_f(  feonumm4n4_t* elm, uint64_t i, uint64_t j,
                              feoarrm4n4_t* res);
  void feoarrm4n4_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm4n4_t* res);
  void feoarrm4n4_set_item_k_o(  onumm4n4_t* elm, uint64_t k,
                              feoarrm4n4_t* res);
  void feoarrm4n4_set_item_k_R(    oarrm4n4_t* elm, uint64_t k,
                            feoarrm4n4_t* res);
  void feoarrm4n4_set_item_k_O(    oarrm4n4_t* elm, uint64_t k,
                            feoarrm4n4_t* res);
  void feoarrm4n4_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm4n4_t* res);
  void feoarrm4n4_set_item_ijk_o( onumm4n4_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm4n4_t* res);
  void feoarrm4n4_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n4_t* res);
  void feoarrm4n4_set_slice_o( onumm4n4_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n4_t* res);
  void feoarrm4n4_set_slice_f( feonumm4n4_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n4_t* res);
  void feoarrm4n4_set_slice_O( oarrm4n4_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n4_t* res);
  void feoarrm4n4_set_slice_F( feoarrm4n4_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n4_t* res);
  void feoarrm4n4_set_all_o( onumm4n4_t* num, feoarrm4n4_t* arr );
  void feoarrm4n4_set_all_r(   coeff_t  num, feoarrm4n4_t* arr );
  void feoarrm4n4_set_all_f(  feonumm4n4_t* num, feoarrm4n4_t* arr );
  void feoarrm4n4_set_r(    coeff_t src, feoarrm4n4_t* res );
  void feoarrm4n4_set_o( onumm4n4_t* src, feoarrm4n4_t* res );
  void feoarrm4n4_set_f(  feonumm4n4_t* src, feoarrm4n4_t* res );
  void feoarrm4n4_set_R(    darr_t* src, feoarrm4n4_t* res );
  void feoarrm4n4_set_O(   oarrm4n4_t* src, feoarrm4n4_t* res );
  void feoarrm4n4_set_F( feoarrm4n4_t* src, feoarrm4n4_t* res );
  feoarrm4n4_t feoarrm4n4_eye( uint64_t size,  uint64_t nip);
  feoarrm4n4_t feoarrm4n4_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm4n4_t feoarrm4n4_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm4n4_t feoarrm4n4_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm4n4_free(feoarrm4n4_t* arr);
  feoarrm4n4_t feoarrm4n4_init();
  ord_t feoarrm4n4_get_order(feoarrm4n4_t* arr);
  
  
  # From ../../../include/oti/static/onumm4n4/array/gauss/utils.h
  
  void feoarrm4n4_dimCheck_FF_samesize(feoarrm4n4_t* arr1, feoarrm4n4_t* arr2, feonumm4n4_t* res);
  void feoarrm4n4_dimCheck_OF_samesize(  oarrm4n4_t* arr1, feoarrm4n4_t* arr2, feonumm4n4_t* res);
  void feoarrm4n4_dimCheck_RF_samesize(   darr_t* arr1, feoarrm4n4_t* arr2, feonumm4n4_t* res);
  void feoarrm4n4_dimCheck_FF_elementwise(feoarrm4n4_t* arr1, feoarrm4n4_t* arr2, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_OF_elementwise(  oarrm4n4_t* arr1, feoarrm4n4_t* arr2, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm4n4_t* arr2, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_fF_elementwise( feonumm4n4_t* num1, feoarrm4n4_t* arr2, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_Ff_elementwise(feoarrm4n4_t* arr1,  feonumm4n4_t* num2, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_FF_matmul( feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_OF_matmul(   oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_RF_matmul(    darr_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_FO_matmul( feoarrm4n4_t* lhs,   oarrm4n4_t* rhs, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_FR_matmul( feoarrm4n4_t* lhs,    darr_t* rhs, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_F_squareness( feoarrm4n4_t* arr1, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_F_transpose( feoarrm4n4_t* arr1, feoarrm4n4_t* res);
  void feoarrm4n4_dimCheck_FfO_integrate(feoarrm4n4_t* arr, feonumm4n4_t* num,oarrm4n4_t* res);
  void feoarrm4n4_get_active_bases(feoarrm4n4_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n4/array/gauss/algebra.h
  
  feoarrm4n4_t feoarrm4n4_neg(    feoarrm4n4_t* arr);
  void      feoarrm4n4_neg_to( feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sum_FF(   feoarrm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sum_FF_to(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sum_fF(    feonumm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sum_fF_to( feonumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sum_OF(     oarrm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sum_OF_to(  oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sum_RF(      darr_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sum_RF_to(   darr_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sum_oF(   onumm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sum_oF_to(onumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sum_rF(     coeff_t  lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sum_rF_to(  coeff_t  lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sub_FF(    feoarrm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sub_FF_to( feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sub_fF(    feonumm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sub_fF_to( feonumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sub_Ff(    feoarrm4n4_t* lhs, feonumm4n4_t* rhs);
  void      feoarrm4n4_sub_Ff_to( feoarrm4n4_t* lhs, feonumm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sub_OF(      oarrm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sub_OF_to(   oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sub_FO(    feoarrm4n4_t* lhs,   oarrm4n4_t* rhs);
  void      feoarrm4n4_sub_FO_to( feoarrm4n4_t* lhs,   oarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sub_RF(       darr_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sub_RF_to(    darr_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sub_FR(    feoarrm4n4_t* lhs,    darr_t* rhs);
  void      feoarrm4n4_sub_FR_to( feoarrm4n4_t* lhs,    darr_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sub_oF(    onumm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sub_oF_to( onumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sub_Fo(    feoarrm4n4_t* lhs, onumm4n4_t* rhs);
  void      feoarrm4n4_sub_Fo_to( feoarrm4n4_t* lhs, onumm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sub_rF(      coeff_t  lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_sub_rF_to(    coeff_t lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_sub_Fr(    feoarrm4n4_t* lhs,   coeff_t  rhs);
  void      feoarrm4n4_sub_Fr_to( feoarrm4n4_t* lhs,   coeff_t  rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_mul_FF(   feoarrm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_mul_FF_to(feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_mul_fF(    feonumm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_mul_fF_to( feonumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_mul_OF(     oarrm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_mul_OF_to(  oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_mul_RF(      darr_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_mul_RF_to(   darr_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_mul_oF(   onumm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_mul_oF_to(onumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_mul_rF(     coeff_t  lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_mul_rF_to(  coeff_t  lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_div_FF(    feoarrm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_div_FF_to( feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_div_fF(     feonumm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_div_fF_to(  feonumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_div_Ff(    feoarrm4n4_t* lhs,  feonumm4n4_t* rhs);
  void      feoarrm4n4_div_Ff_to( feoarrm4n4_t* lhs,  feonumm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_div_OF(      oarrm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_div_OF_to(   oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_div_FO(    feoarrm4n4_t* lhs,   oarrm4n4_t* rhs);
  void      feoarrm4n4_div_FO_to( feoarrm4n4_t* lhs,   oarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_div_RF(       darr_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_div_RF_to(    darr_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_div_FR(    feoarrm4n4_t* lhs,    darr_t* rhs);
  void      feoarrm4n4_div_FR_to( feoarrm4n4_t* lhs,    darr_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_div_oF(    onumm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_div_oF_to( onumm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_div_Fo(    feoarrm4n4_t* lhs, onumm4n4_t* rhs);
  void      feoarrm4n4_div_Fo_to( feoarrm4n4_t* lhs, onumm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_div_rF(      coeff_t  lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_div_rF_to(    coeff_t lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_div_Fr(    feoarrm4n4_t* lhs,   coeff_t  rhs);
  void      feoarrm4n4_div_Fr_to( feoarrm4n4_t* lhs,   coeff_t  rhs, feoarrm4n4_t* res);
  oarrm4n4_t feoarrm4n4_integrate(    feoarrm4n4_t* arr, feonumm4n4_t* w);
  void    feoarrm4n4_integrate_to( feoarrm4n4_t* arr, feonumm4n4_t* w, oarrm4n4_t* res);
  feonumm4n4_t feoarrm4n4_dotproduct_FF(    feoarrm4n4_t* lhs, feoarrm4n4_t* rhs);
  void     feoarrm4n4_dotproduct_FF_to( feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feoarrm4n4_dotproduct_OF(      oarrm4n4_t* lhs, feoarrm4n4_t* rhs);
  void     feoarrm4n4_dotproduct_OF_to(   oarrm4n4_t* lhs, feoarrm4n4_t* rhs, feonumm4n4_t* res);
  feonumm4n4_t feoarrm4n4_dotproduct_RF(       darr_t* lhs, feoarrm4n4_t* rhs);
  void     feoarrm4n4_dotproduct_RF_to(    darr_t* lhs, feoarrm4n4_t* rhs, feonumm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_matmul_FF(    feoarrm4n4_t* lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_matmul_FF_to( feoarrm4n4_t* lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_matmul_OF(    oarrm4n4_t*   lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_matmul_OF_to( oarrm4n4_t*   lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_matmul_FO(    feoarrm4n4_t* lhs, oarrm4n4_t*   rhs);
  void      feoarrm4n4_matmul_FO_to( feoarrm4n4_t* lhs, oarrm4n4_t*   rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_matmul_RF(    darr_t*    lhs, feoarrm4n4_t* rhs);
  void      feoarrm4n4_matmul_RF_to( darr_t*    lhs, feoarrm4n4_t* rhs, feoarrm4n4_t* res);
  feoarrm4n4_t feoarrm4n4_matmul_FR(    feoarrm4n4_t* lhs, darr_t*    rhs);
  void      feoarrm4n4_matmul_FR_to( feoarrm4n4_t* lhs, darr_t*    rhs, feoarrm4n4_t* res);
  feonumm4n4_t feoarrm4n4_det(   feoarrm4n4_t* arr);
  void     feoarrm4n4_det_to(feoarrm4n4_t* arr, feonumm4n4_t* res);
  feonumm4n4_t feoarrm4n4_norm(     feoarrm4n4_t* arr);
  void     feoarrm4n4_norm_to(  feoarrm4n4_t* arr, feonumm4n4_t* res);
  feonumm4n4_t feoarrm4n4_pnorm(    feoarrm4n4_t* arr, coeff_t p);
  void     feoarrm4n4_pnorm_to( feoarrm4n4_t* arr, coeff_t p, feonumm4n4_t* res);
  feoarrm4n4_t   feoarrm4n4_invert(    feoarrm4n4_t* arr);
  void        feoarrm4n4_invert_to( feoarrm4n4_t* arr, feoarrm4n4_t* res);
  feoarrm4n4_t   feoarrm4n4_transpose(   feoarrm4n4_t* arr);
  void        feoarrm4n4_transpose_to(feoarrm4n4_t* arr, feoarrm4n4_t* res);
  
  