cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm4n5/scalar/structures.h
  
  ctypedef struct  onumm4n5_t : # {
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
    coeff_t e11114;
    coeff_t e11124;
    coeff_t e11224;
    coeff_t e12224;
    coeff_t e22224;
    coeff_t e11134;
    coeff_t e11234;
    coeff_t e12234;
    coeff_t e22234;
    coeff_t e11334;
    coeff_t e12334;
    coeff_t e22334;
    coeff_t e13334;
    coeff_t e23334;
    coeff_t e33334;
    coeff_t e11144;
    coeff_t e11244;
    coeff_t e12244;
    coeff_t e22244;
    coeff_t e11344;
    coeff_t e12344;
    coeff_t e22344;
    coeff_t e13344;
    coeff_t e23344;
    coeff_t e33344;
    coeff_t e11444;
    coeff_t e12444;
    coeff_t e22444;
    coeff_t e13444;
    coeff_t e23444;
    coeff_t e33444;
    coeff_t e14444;
    coeff_t e24444;
    coeff_t e34444;
    coeff_t e44444;
  # } onumm4n5_t;
  
  
  # From ../../../include/oti/static/onumm4n5/array/structures.h
  
  ctypedef struct  oarrm4n5_t : # {
      onumm4n5_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm4n5_t;
  
  
  # From ../../../include/oti/static/onumm4n5/scalar/gauss/structures.h
  
  ctypedef struct  feonumm4n5_t: # {
      onumm4n5_t*  p_data;
      uint64_t    nip;
  # } feonumm4n5_t;
  
  
  # From ../../../include/oti/static/onumm4n5/array/gauss/structures.h
  
  ctypedef struct  feoarrm4n5_t: # {
      oarrm4n5_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm4n5_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm4n5/scalar/functions.h
  
  onumm4n5_t onumm4n5_atanh(onumm4n5_t* num);
  void onumm4n5_atanh_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_asinh(onumm4n5_t* num);
  void onumm4n5_asinh_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_acosh(onumm4n5_t* num);
  void onumm4n5_acosh_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_tanh(onumm4n5_t* num);
  void onumm4n5_tanh_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_sqrt(onumm4n5_t* num);
  void onumm4n5_sqrt_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_cbrt(onumm4n5_t* num);
  void onumm4n5_cbrt_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_cosh(onumm4n5_t* num);
  void onumm4n5_cosh_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_sinh(onumm4n5_t* num);
  void onumm4n5_sinh_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_asin(onumm4n5_t* num);
  void onumm4n5_asin_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_acos(onumm4n5_t* num);
  void onumm4n5_acos_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_atan(onumm4n5_t* num);
  void onumm4n5_atan_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_tan(onumm4n5_t* num);
  void onumm4n5_tan_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_cos(onumm4n5_t* num);
  void onumm4n5_cos_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_sin(onumm4n5_t* num );
  void onumm4n5_sin_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_logb(onumm4n5_t* num, double base);
  void onumm4n5_logb_to(onumm4n5_t* num, double base, onumm4n5_t* res);
  onumm4n5_t onumm4n5_log10(onumm4n5_t* num);
  void onumm4n5_log10_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_log(onumm4n5_t* num);
  void onumm4n5_log_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_exp(onumm4n5_t* num);
  void onumm4n5_exp_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_pow(onumm4n5_t* num, double e);
  void onumm4n5_pow_to(onumm4n5_t* num, coeff_t e, onumm4n5_t* res);
  
  
  # From ../../../include/oti/static/onumm4n5/scalar/base.h
  
  void onumm4n5_set_im_o(onumm4n5_t* num, imdir_t idx, ord_t order, onumm4n5_t* res);
  void onumm4n5_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm4n5_t* res);
  void onumm4n5_set_deriv_o(onumm4n5_t* num, imdir_t idx, ord_t order, onumm4n5_t* res);
  void onumm4n5_extract_im_to( imdir_t idx, ord_t order, onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_extract_im(imdir_t idx, ord_t order, onumm4n5_t* num);
  onumm4n5_t onumm4n5_extract_deriv(imdir_t idx, ord_t order, onumm4n5_t* num);
  void onumm4n5_extract_deriv_to(imdir_t idx, ord_t order, onumm4n5_t* num, onumm4n5_t* res);
  void onumm4n5_get_im_to_o(imdir_t idx, ord_t order, onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_get_im_o(imdir_t idx, ord_t order, onumm4n5_t* num);
  void onumm4n5_get_im_to_r(imdir_t idx, ord_t order, onumm4n5_t* num, coeff_t* res);
  ord_t onumm4n5_get_order(onumm4n5_t* lhs);
  onumm4n5_t onumm4n5_get_deriv_o( imdir_t idx, ord_t order, onumm4n5_t* num);
  void onumm4n5_get_deriv_to( imdir_t idx, ord_t order, onumm4n5_t* num, onumm4n5_t* res);
  void onumm4n5_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm4n5_t* res);
  onumm4n5_t onumm4n5_init();
  ndir_t onumm4n5_get_ndir_order(ord_t order, onumm4n5_t* num);
  ndir_t onumm4n5_get_ndir_total(onumm4n5_t* num);
  coeff_t* onumm4n5_get_order_address(ord_t order, onumm4n5_t* num);
  onumm4n5_t onumm4n5_create_r(  coeff_t lhs);
  void onumm4n5_set_r(  coeff_t lhs, onumm4n5_t* res);
  void onumm4n5_set_o(  onumm4n5_t* lhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_get_order_im(ord_t order, onumm4n5_t* lhs);
  void onumm4n5_get_order_im_to(ord_t order, onumm4n5_t* lhs, onumm4n5_t* res);
  coeff_t onumm4n5_get_item(imdir_t idx, ord_t order, onumm4n5_t* lhs);
  coeff_t onumm4n5_get_deriv(imdir_t idx, ord_t order, onumm4n5_t* lhs);
  void onumm4n5_set_item(coeff_t val, imdir_t idx, ord_t order, onumm4n5_t* x);
  onumm4n5_t onumm4n5_copy(  onumm4n5_t* lhs);
  void onumm4n5_copy_to(  onumm4n5_t* lhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_taylor_integrate(coeff_t* deltas,onumm4n5_t* lhs);
  void onumm4n5_taylor_integrate_to(coeff_t* deltas,onumm4n5_t* lhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_truncate_im(imdir_t idx, ord_t order, onumm4n5_t* lhs);
  void onumm4n5_truncate_im_to(imdir_t idx, ord_t order, onumm4n5_t* lhs, onumm4n5_t* res);
  void onumm4n5_print(  onumm4n5_t* lhs);
  imdir_t onumm4n5_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm4n5/scalar/utils.h
  
  void onumm4n5_get_active_bases(onumm4n5_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm4n5/scalar/algebra.h
  
  onumm4n5_t onumm4n5_abs(onumm4n5_t* num);
  onumm4n5_t onumm4n5_div_ro(coeff_t num, onumm4n5_t* den);
  onumm4n5_t onumm4n5_div_oo(onumm4n5_t* num, onumm4n5_t* den);
  onumm4n5_t onumm4n5_div_or(onumm4n5_t* num, coeff_t val);
  void onumm4n5_div_ro_to(coeff_t num, onumm4n5_t* den, onumm4n5_t* res);
  void onumm4n5_div_oo_to(onumm4n5_t* num, onumm4n5_t* den, onumm4n5_t* res);
  void onumm4n5_div_or_to(onumm4n5_t* num, coeff_t val, onumm4n5_t* res);
  void onumm4n5_abs_to(onumm4n5_t* num, onumm4n5_t* res);
  onumm4n5_t onumm4n5_neg(  onumm4n5_t* lhs);
  void onumm4n5_neg_to(  onumm4n5_t* lhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_sum_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs);
  void onumm4n5_sum_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_sum_ro(  coeff_t lhs,  onumm4n5_t* rhs);
  void onumm4n5_sum_ro_to(  coeff_t lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_sub_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs);
  void onumm4n5_sub_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_sub_ro(  coeff_t lhs,  onumm4n5_t* rhs);
  void onumm4n5_sub_ro_to(  coeff_t lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_sub_or(  onumm4n5_t* lhs,  coeff_t rhs);
  void onumm4n5_sub_or_to(  onumm4n5_t* lhs,  coeff_t rhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_mul_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs);
  void onumm4n5_mul_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_mul_ro(  coeff_t lhs,  onumm4n5_t* rhs);
  void onumm4n5_mul_ro_to(  coeff_t lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_trunc_mul_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs);
  void onumm4n5_trunc_mul_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_gem_oo(  onumm4n5_t* a,  onumm4n5_t* b,  onumm4n5_t* c);
  void onumm4n5_gem_oo_to(  onumm4n5_t* a,  onumm4n5_t* b,  onumm4n5_t* c, onumm4n5_t* res);
  onumm4n5_t onumm4n5_gem_ro(  coeff_t a,  onumm4n5_t* b,  onumm4n5_t* c);
  void onumm4n5_gem_ro_to(  coeff_t a,  onumm4n5_t* b,  onumm4n5_t* c, onumm4n5_t* res);
  void onumm4n5_trunc_gem_oo_to( ord_t ord_lhs,  onumm4n5_t* a,  ord_t ord_rhs,  onumm4n5_t* b,  onumm4n5_t* c, onumm4n5_t* res);
  void onumm4n5_trunc_sum_oo_to(ord_t order, onumm4n5_t* lhs,onumm4n5_t* rhs, onumm4n5_t* res);
  void onumm4n5_trunc_sub_oo_to(ord_t order, onumm4n5_t* lhs,onumm4n5_t* rhs, onumm4n5_t* res);
  onumm4n5_t onumm4n5_feval(coeff_t* feval_re, onumm4n5_t* x);
  void onumm4n5_feval_to(coeff_t* feval_re, onumm4n5_t* x, onumm4n5_t* res);
  
  
  # From ../../../include/oti/static/onumm4n5/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm4n5/scalar/gauss/functions.h
  
  feonumm4n5_t feonumm4n5_atanh(    feonumm4n5_t* num);
  void     feonumm4n5_atanh_to( feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_asinh(    feonumm4n5_t* num);
  void     feonumm4n5_asinh_to( feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_acosh(    feonumm4n5_t* num);
  void     feonumm4n5_acosh_to( feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_tanh(     feonumm4n5_t* num);
  void     feonumm4n5_tanh_to(  feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_cosh(     feonumm4n5_t* num);
  void     feonumm4n5_cosh_to(  feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_sinh(     feonumm4n5_t* num);
  void     feonumm4n5_sinh_to(  feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_asin(     feonumm4n5_t* num);
  void     feonumm4n5_asin_to(  feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_acos(     feonumm4n5_t* num);
  void     feonumm4n5_acos_to(  feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_atan(     feonumm4n5_t* num);
  void     feonumm4n5_atan_to(  feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_tan(      feonumm4n5_t* num);
  void     feonumm4n5_tan_to(   feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_cos(      feonumm4n5_t* num);
  void     feonumm4n5_cos_to(   feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_sin(      feonumm4n5_t* num);
  void     feonumm4n5_sin_to(   feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_logb(     feonumm4n5_t* num, double base);
  void     feonumm4n5_logb_to(  feonumm4n5_t* num, double base, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_log10(    feonumm4n5_t* num);
  void     feonumm4n5_log10_to( feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_log(      feonumm4n5_t* num);
  void     feonumm4n5_log_to(   feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_exp(      feonumm4n5_t* num);
  void     feonumm4n5_exp_to(   feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_cbrt(     feonumm4n5_t* num);
  void     feonumm4n5_cbrt_to(  feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_sqrt(     feonumm4n5_t* num);
  void     feonumm4n5_sqrt_to(  feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_pow(      feonumm4n5_t* num, double e);
  void     feonumm4n5_pow_to(   feonumm4n5_t* num, double e, feonumm4n5_t* res);
  onumm4n5_t feonumm4n5_integrate(       feonumm4n5_t* num, feonumm4n5_t* w);
  void      feonumm4n5_integrate_to(    feonumm4n5_t* num, feonumm4n5_t* w, onumm4n5_t* res);
  onumm4n5_t feonumm4n5_integrate_f(     feonumm4n5_t* num, feonumm4n5_t* w);
  void      feonumm4n5_integrate_f_to(  feonumm4n5_t* num, feonumm4n5_t* w, onumm4n5_t* res);
  onumm4n5_t feonumm4n5_integrate_r(       coeff_t num, feonumm4n5_t* w);
  void      feonumm4n5_integrate_r_to(    coeff_t num, feonumm4n5_t* w, onumm4n5_t* res);
  onumm4n5_t feonumm4n5_integrate_o(    onumm4n5_t* num, feonumm4n5_t* w);
  void      feonumm4n5_integrate_o_to( onumm4n5_t* num, feonumm4n5_t* w, onumm4n5_t* res);
  
  
  # From ../../../include/oti/static/onumm4n5/scalar/gauss/base.h
  
  void     feonumm4n5_get_order_im_to( ord_t order, feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_get_order_im(    ord_t order, feonumm4n5_t* num);
  feonumm4n5_t feonumm4n5_get_im(    imdir_t idx, ord_t order, feonumm4n5_t* num);
  void     feonumm4n5_get_im_to( imdir_t idx, ord_t order, feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_get_deriv(    imdir_t idx, ord_t order, feonumm4n5_t* num);
  void     feonumm4n5_get_deriv_to( imdir_t idx, ord_t order, feonumm4n5_t* num, feonumm4n5_t* res);
  void feonumm4n5_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm4n5_t* num);
  void feonumm4n5_set_im_o( onumm4n5_t* val, imdir_t idx, ord_t order, feonumm4n5_t* num);
  void feonumm4n5_set_im_f(  feonumm4n5_t* val, imdir_t idx, ord_t order, feonumm4n5_t* num);
  void feonumm4n5_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm4n5_t* num);
  void feonumm4n5_set_deriv_o( onumm4n5_t* val, imdir_t idx, ord_t order, feonumm4n5_t* num);
  void feonumm4n5_set_deriv_f(  feonumm4n5_t* val, imdir_t idx, ord_t order, feonumm4n5_t* num);
  feonumm4n5_t feonumm4n5_extract_im(    imdir_t idx, ord_t order, feonumm4n5_t* num);
  void     feonumm4n5_extract_im_to( imdir_t idx, ord_t order, feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_extract_deriv(    imdir_t idx, ord_t order, feonumm4n5_t* num);
  void     feonumm4n5_extract_deriv_to( imdir_t idx, ord_t order, feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_truncate_im(    imdir_t idx, ord_t order, feonumm4n5_t* num);
  void     feonumm4n5_truncate_im_to( imdir_t idx, ord_t order, feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_copy(    feonumm4n5_t* src);
  void     feonumm4n5_copy_to( feonumm4n5_t* src, feonumm4n5_t* dst);
  void feonumm4n5_set_r(    coeff_t num, feonumm4n5_t* res);
  void feonumm4n5_set_o( onumm4n5_t* num, feonumm4n5_t* res);
  void feonumm4n5_set_f(  feonumm4n5_t* num, feonumm4n5_t* res);
  void feonumm4n5_set_item_k_r(   coeff_t  num, uint64_t k, feonumm4n5_t* res);
  void feonumm4n5_set_item_k_o( onumm4n5_t* num, uint64_t k, feonumm4n5_t* res);
  onumm4n5_t feonumm4n5_get_item_k(   feonumm4n5_t* num, uint64_t k);
  void      feonumm4n5_get_item_k_to(feonumm4n5_t* num, uint64_t k, onumm4n5_t* res);
  feonumm4n5_t feonumm4n5_zeros(uint64_t nIntPts);
  feonumm4n5_t feonumm4n5_createEmpty(uint64_t nIntPts);
  feonumm4n5_t feonumm4n5_empty_like(feonumm4n5_t* arr);
  void feonumm4n5_free(feonumm4n5_t* num);
  ord_t feonumm4n5_get_order( feonumm4n5_t* num );
  feonumm4n5_t feonumm4n5_init();
  
  
  # From ../../../include/oti/static/onumm4n5/scalar/gauss/utils.h
  
  void feonumm4n5_dimCheck(feonumm4n5_t* arr1,feonumm4n5_t* arr2);
  void feonumm4n5_get_active_bases(feonumm4n5_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n5/scalar/gauss/algebra.h
  
  feonumm4n5_t feonumm4n5_neg(   feonumm4n5_t* num);
  void     feonumm4n5_neg_to(feonumm4n5_t* num, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_sum_ff(   feonumm4n5_t* lhs, feonumm4n5_t* rhs);
  void     feonumm4n5_sum_ff_to(feonumm4n5_t* lhs, feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_sum_of(   onumm4n5_t* lhs, feonumm4n5_t* rhs);
  void     feonumm4n5_sum_of_to(onumm4n5_t* lhs, feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_sum_rf(   coeff_t lhs, feonumm4n5_t* rhs);
  void     feonumm4n5_sum_rf_to(coeff_t lhs, feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_sub_ff(     feonumm4n5_t* lhs,  feonumm4n5_t* rhs);
  void     feonumm4n5_sub_ff_to(  feonumm4n5_t* lhs,  feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_sub_of(    onumm4n5_t* lhs,  feonumm4n5_t* rhs);
  void     feonumm4n5_sub_of_to( onumm4n5_t* lhs,  feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_sub_fo(     feonumm4n5_t* lhs, onumm4n5_t* rhs);
  void     feonumm4n5_sub_fo_to(  feonumm4n5_t* lhs, onumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_sub_rf(       coeff_t lhs,  feonumm4n5_t* rhs);
  void     feonumm4n5_sub_rf_to(    coeff_t lhs,  feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_sub_fr(     feonumm4n5_t* lhs,    coeff_t rhs);
  void     feonumm4n5_sub_fr_to(  feonumm4n5_t* lhs,    coeff_t rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_mul_ff(   feonumm4n5_t* lhs, feonumm4n5_t* rhs);
  void     feonumm4n5_mul_ff_to(feonumm4n5_t* lhs, feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_mul_of(   onumm4n5_t* lhs, feonumm4n5_t* rhs);
  void     feonumm4n5_mul_of_to(onumm4n5_t* lhs, feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_mul_rf(   coeff_t lhs, feonumm4n5_t* rhs);
  void     feonumm4n5_mul_rf_to(coeff_t lhs, feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_div_ff(     feonumm4n5_t* lhs,  feonumm4n5_t* rhs);
  void     feonumm4n5_div_ff_to(  feonumm4n5_t* lhs,  feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_div_of(    onumm4n5_t* lhs,  feonumm4n5_t* rhs);
  void     feonumm4n5_div_of_to( onumm4n5_t* lhs,  feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_div_fo(     feonumm4n5_t* lhs, onumm4n5_t* rhs);
  void     feonumm4n5_div_fo_to(  feonumm4n5_t* lhs, onumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_div_rf(       coeff_t lhs,  feonumm4n5_t* rhs);
  void     feonumm4n5_div_rf_to(    coeff_t lhs,  feonumm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feonumm4n5_div_fr(     feonumm4n5_t* lhs,    coeff_t rhs);
  void     feonumm4n5_div_fr_to(  feonumm4n5_t* lhs,    coeff_t rhs, feonumm4n5_t* res);
  
  
  # From ../../../include/oti/static/onumm4n5/array/functions.h
  
  oarrm4n5_t oarrm4n5_atanh(   oarrm4n5_t* arr);
  void    oarrm4n5_atanh_to(oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_asinh(   oarrm4n5_t* arr);
  void    oarrm4n5_asinh_to(oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_acosh(   oarrm4n5_t* arr);
  void    oarrm4n5_acosh_to(oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_tanh(    oarrm4n5_t* arr);
  void    oarrm4n5_tanh_to( oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_cbrt(    oarrm4n5_t* arr);
  void    oarrm4n5_cbrt_to( oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_sqrt(    oarrm4n5_t* arr);
  void    oarrm4n5_sqrt_to( oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_cosh(    oarrm4n5_t* arr);
  void    oarrm4n5_cosh_to( oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_sinh(    oarrm4n5_t* arr);
  void    oarrm4n5_sinh_to( oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_asin(    oarrm4n5_t* arr);
  void    oarrm4n5_asin_to( oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_acos(    oarrm4n5_t* arr);
  void    oarrm4n5_acos_to( oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_atan(    oarrm4n5_t* arr);
  void    oarrm4n5_atan_to( oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_tan(     oarrm4n5_t* arr);
  void    oarrm4n5_tan_to(  oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_cos(     oarrm4n5_t* arr);
  void    oarrm4n5_cos_to(  oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_sin(     oarrm4n5_t* arr);
  void    oarrm4n5_sin_to(  oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_logb(    oarrm4n5_t* arr, double base);
  void    oarrm4n5_logb_to( oarrm4n5_t* arr, double base, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_log10(   oarrm4n5_t* arr);
  void    oarrm4n5_log10_to(oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_log(     oarrm4n5_t* arr);
  void    oarrm4n5_log_to(  oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_exp(     oarrm4n5_t* arr);
  void    oarrm4n5_exp_to(  oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_pow(     oarrm4n5_t* arr, double e);
  void    oarrm4n5_pow_to(  oarrm4n5_t* arr, double e, oarrm4n5_t* res);
  
  
  # From ../../../include/oti/static/onumm4n5/array/algebra_elementwise.h
  
  oarrm4n5_t oarrm4n5_neg(oarrm4n5_t* arr);
  void oarrm4n5_neg_to(oarrm4n5_t* rhs, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_sum_OO(oarrm4n5_t*   lhs, oarrm4n5_t* rhs);
  oarrm4n5_t oarrm4n5_sum_RO(darr_t*    lhs, oarrm4n5_t* rhs);
  oarrm4n5_t oarrm4n5_sum_oO(onumm4n5_t* lhs, oarrm4n5_t* rhs);
  oarrm4n5_t oarrm4n5_sum_rO(coeff_t    lhs, oarrm4n5_t* rhs);
  void oarrm4n5_sum_OO_to(oarrm4n5_t*   lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
  void oarrm4n5_sum_RO_to(darr_t*    lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
  void oarrm4n5_sum_oO_to(onumm4n5_t* lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
  void oarrm4n5_sum_rO_to(coeff_t    lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
  void oarrm4n5_trunc_sum_OO_to(ord_t order, oarrm4n5_t* arr1, oarrm4n5_t* arr2, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_sub_OO(oarrm4n5_t*   lhs, oarrm4n5_t*   rhs);
  oarrm4n5_t oarrm4n5_sub_RO(darr_t*    lhs, oarrm4n5_t*   rhs);
  oarrm4n5_t oarrm4n5_sub_OR(oarrm4n5_t*   lhs, darr_t*    rhs);
  oarrm4n5_t oarrm4n5_sub_oO(onumm4n5_t* lhs, oarrm4n5_t*   rhs);
  oarrm4n5_t oarrm4n5_sub_Oo(oarrm4n5_t*   lhs, onumm4n5_t* rhs);
  oarrm4n5_t oarrm4n5_sub_rO(coeff_t    lhs, oarrm4n5_t*   rhs);
  oarrm4n5_t oarrm4n5_sub_Or(oarrm4n5_t*   lhs, coeff_t    rhs);
  void oarrm4n5_sub_OO_to( oarrm4n5_t*   lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
  void oarrm4n5_sub_RO_to( darr_t*    lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
  void oarrm4n5_sub_OR_to( oarrm4n5_t*   lhs, darr_t*    rhs, oarrm4n5_t* res);
  void oarrm4n5_sub_oO_to( onumm4n5_t* lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
  void oarrm4n5_sub_Oo_to( oarrm4n5_t*   lhs, onumm4n5_t* rhs, oarrm4n5_t* res);
  void oarrm4n5_sub_rO_to( coeff_t    lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
  void oarrm4n5_sub_Or_to( oarrm4n5_t*   lhs, coeff_t    rhs, oarrm4n5_t* res);
  void oarrm4n5_trunc_sub_OO_to(ord_t order, oarrm4n5_t* arr1, oarrm4n5_t* arr2, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_mul_OO(oarrm4n5_t*   lhs, oarrm4n5_t* rhs);
  oarrm4n5_t oarrm4n5_mul_RO(darr_t*    lhs, oarrm4n5_t* rhs);
  oarrm4n5_t oarrm4n5_mul_oO(onumm4n5_t* lhs, oarrm4n5_t* rhs);
  oarrm4n5_t oarrm4n5_mul_rO(coeff_t    lhs, oarrm4n5_t* rhs);
  void oarrm4n5_mul_OO_to(oarrm4n5_t*   lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
  void oarrm4n5_mul_RO_to(darr_t*    lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
  void oarrm4n5_mul_oO_to(onumm4n5_t* lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
  void oarrm4n5_mul_rO_to(coeff_t    lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
  void oarrm4n5_gem_OO_to(  oarrm4n5_t* arr1, oarrm4n5_t* arr2, oarrm4n5_t* arr3, oarrm4n5_t* res);
  void oarrm4n5_gem_oO_to(onumm4n5_t* arr1, oarrm4n5_t* arr2, oarrm4n5_t* arr3, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_div_OO(oarrm4n5_t*   lhs, oarrm4n5_t*   rhs);
  oarrm4n5_t oarrm4n5_div_OR(oarrm4n5_t*   lhs, darr_t*    rhs);
  oarrm4n5_t oarrm4n5_div_RO(darr_t*    lhs, oarrm4n5_t*   rhs);
  oarrm4n5_t oarrm4n5_div_oO(onumm4n5_t* lhs, oarrm4n5_t*   rhs);
  oarrm4n5_t oarrm4n5_div_Oo(oarrm4n5_t*   lhs, onumm4n5_t* rhs);
  oarrm4n5_t oarrm4n5_div_rO(coeff_t    lhs, oarrm4n5_t*   rhs);
  oarrm4n5_t oarrm4n5_div_Or(oarrm4n5_t*   lhs, coeff_t    rhs);
  void oarrm4n5_div_OO_to(oarrm4n5_t*   lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
  void oarrm4n5_div_RO_to(darr_t*    lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
  void oarrm4n5_div_OR_to(oarrm4n5_t*   lhs, darr_t*    rhs, oarrm4n5_t* res);
  void oarrm4n5_div_oO_to(onumm4n5_t* lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
  void oarrm4n5_div_Oo_to(oarrm4n5_t*   lhs, onumm4n5_t* rhs, oarrm4n5_t* res);
  void oarrm4n5_div_rO_to(coeff_t    lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
  void oarrm4n5_div_Or_to(oarrm4n5_t*   lhs, coeff_t    rhs, oarrm4n5_t* res);
  
  
  # From ../../../include/oti/static/onumm4n5/array/base.h
  
  void    oarrm4n5_taylor_integrate_to( coeff_t* deltas, oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_taylor_integrate(    coeff_t* deltas, oarrm4n5_t* arr);
  void    oarrm4n5_get_order_im_to( ord_t order, oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_get_order_im(    ord_t order, oarrm4n5_t* arr);
  void oarrm4n5_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n5_t* res);
  void oarrm4n5_set_slice_O( oarrm4n5_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n5_t* res);
  void oarrm4n5_set_slice_o( onumm4n5_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_get_slice( oarrm4n5_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm4n5_get_slice_to( oarrm4n5_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_truncate_im(    imdir_t idx, ord_t order, oarrm4n5_t* arr);
  void    oarrm4n5_truncate_im_to( imdir_t idx, ord_t order, oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_extract_im(   imdir_t idx, ord_t order, oarrm4n5_t* arr);
  void    oarrm4n5_extract_im_to(imdir_t idx, ord_t order, oarrm4n5_t* arr, oarrm4n5_t* res);
  darr_t  oarrm4n5_get_deriv(    imdir_t idx, ord_t order, oarrm4n5_t* arr);
  void    oarrm4n5_get_deriv_to( imdir_t idx, ord_t order, oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_get_deriv_o(  imdir_t idx, ord_t order, oarrm4n5_t* arr);
  oarrm4n5_t oarrm4n5_extract_deriv(    imdir_t idx, ord_t order, oarrm4n5_t* arr);
  void    oarrm4n5_extract_deriv_to( imdir_t idx, ord_t order, oarrm4n5_t* arr, oarrm4n5_t* res);
  darr_t  oarrm4n5_get_im(   imdir_t idx, ord_t order, oarrm4n5_t* arr);
  oarrm4n5_t oarrm4n5_get_im_o( imdir_t idx, ord_t order, oarrm4n5_t* arr);
  void    oarrm4n5_get_im_to(imdir_t idx, ord_t order, oarrm4n5_t* arr, oarrm4n5_t* res);
  void    oarrm4n5_copy_to(oarrm4n5_t* arr, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_copy(oarrm4n5_t* arr);
  void oarrm4n5_set_all_r( coeff_t num, oarrm4n5_t* arr);
  void oarrm4n5_set_item_i_r( coeff_t num, uint64_t i, oarrm4n5_t* arr);
  void oarrm4n5_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm4n5_t* arr);
  void oarrm4n5_set_r(   coeff_t  num,   oarrm4n5_t* arr);
  void oarrm4n5_set_o( onumm4n5_t* num,   oarrm4n5_t* arr);
  void oarrm4n5_set_O(   oarrm4n5_t* arrin, oarrm4n5_t* arr);
  void oarrm4n5_set_all_o( onumm4n5_t* src, oarrm4n5_t* arr);
  void oarrm4n5_set_item_i_o( onumm4n5_t* num, uint64_t i, oarrm4n5_t* arr);
  void oarrm4n5_set_item_ij_o( onumm4n5_t* num, uint64_t i, uint64_t j, oarrm4n5_t* arr);
  onumm4n5_t oarrm4n5_get_item_i(    oarrm4n5_t* arr, uint64_t i);
  void      oarrm4n5_get_item_i_to( oarrm4n5_t* arr, uint64_t i,             onumm4n5_t* res);
  onumm4n5_t oarrm4n5_get_item_ij(   oarrm4n5_t* arr, uint64_t i, uint64_t j);
  void      oarrm4n5_get_item_ij_to(oarrm4n5_t* arr, uint64_t i, uint64_t j, onumm4n5_t* res);
  oarrm4n5_t oarrm4n5_init();
  void oarrm4n5_free(oarrm4n5_t* arr);
  oarrm4n5_t oarrm4n5_empty_like(oarrm4n5_t* arr);
  oarrm4n5_t oarrm4n5_eye(uint64_t nrows);
  oarrm4n5_t oarrm4n5_ones(uint64_t nrows, uint64_t ncols);
  oarrm4n5_t oarrm4n5_zeros(uint64_t nrows, uint64_t ncols);
  oarrm4n5_t oarrm4n5_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm4n5/array/utils.h
  
  void oarrm4n5_dimCheck_OO_elementwise(oarrm4n5_t* arr1, oarrm4n5_t* arr2, oarrm4n5_t* res);
  void oarrm4n5_dimCheck_RO_elementwise(darr_t*  arr1, oarrm4n5_t* arr2, oarrm4n5_t* res);
  void oarrm4n5_dimCheck_OO_matmul(oarrm4n5_t* arr1, oarrm4n5_t* arr2, oarrm4n5_t* res);
  void oarrm4n5_dimCheck_RO_matmul(darr_t*  arr1, oarrm4n5_t* arr2, oarrm4n5_t* res);
  void oarrm4n5_dimCheck_OR_matmul(oarrm4n5_t* arr1, darr_t*  arr2, oarrm4n5_t* res);
  void oarrm4n5_dimCheck_O_squareness(oarrm4n5_t* arr1, oarrm4n5_t* res);
  void oarrm4n5_dimCheck_OO_samesize(oarrm4n5_t* arr1, oarrm4n5_t* res);
  void oarrm4n5_dimCheck_RO_samesize(darr_t* arr1, oarrm4n5_t* res);
  ord_t oarrm4n5_get_order(oarrm4n5_t* arr);
  void oarrm4n5_get_active_bases(oarrm4n5_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n5/array/algebra_matops.h
  
  onumm4n5_t oarrm4n5_dotproduct_OO(    oarrm4n5_t* lhs, oarrm4n5_t* rhs);
  void      oarrm4n5_dotproduct_OO_to( oarrm4n5_t* lhs, oarrm4n5_t* rhs, onumm4n5_t* res);
  onumm4n5_t oarrm4n5_dotproduct_RO(     darr_t* lhs, oarrm4n5_t* rhs);
  void      oarrm4n5_dotproduct_RO_to(  darr_t* lhs, oarrm4n5_t* rhs, onumm4n5_t* res);
  oarrm4n5_t oarrm4n5_matmul_OO(    oarrm4n5_t* lhs, oarrm4n5_t* rhs);
  oarrm4n5_t oarrm4n5_matmul_OR(    oarrm4n5_t* lhs,  darr_t* rhs);
  oarrm4n5_t oarrm4n5_matmul_RO(     darr_t* lhs, oarrm4n5_t* rhs);
  void    oarrm4n5_matmul_OO_to( oarrm4n5_t* lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
  void    oarrm4n5_matmul_OR_to( oarrm4n5_t* lhs,  darr_t* rhs, oarrm4n5_t* res);
  void    oarrm4n5_matmul_RO_to(  darr_t* lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_transpose(    oarrm4n5_t* arr1);
  void    oarrm4n5_transpose_to( oarrm4n5_t* arr1, oarrm4n5_t* res);
  oarrm4n5_t oarrm4n5_invert(    oarrm4n5_t* arr1);
  void    oarrm4n5_invert_to( oarrm4n5_t* arr1, oarrm4n5_t* res);
  onumm4n5_t oarrm4n5_det(    oarrm4n5_t* arr1);
  void      oarrm4n5_det_to( oarrm4n5_t* arr1, onumm4n5_t* res);
  onumm4n5_t oarrm4n5_norm(    oarrm4n5_t* arr1);
  void      oarrm4n5_norm_to( oarrm4n5_t* arr1,  onumm4n5_t* res);
  onumm4n5_t oarrm4n5_pnorm(    oarrm4n5_t* arr1, coeff_t p);
  void      oarrm4n5_pnorm_to( oarrm4n5_t* arr1, coeff_t p, onumm4n5_t* res);
  
  
  # From ../../../include/oti/static/onumm4n5/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm4n5/array/gauss/functions.h
  
  feoarrm4n5_t feoarrm4n5_atanh(    feoarrm4n5_t* arr);
  void      feoarrm4n5_atanh_to( feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_asinh(    feoarrm4n5_t* arr);
  void      feoarrm4n5_asinh_to( feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_acosh(    feoarrm4n5_t* arr);
  void      feoarrm4n5_acosh_to( feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_tanh(     feoarrm4n5_t* arr);
  void      feoarrm4n5_tanh_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sinh(     feoarrm4n5_t* arr);
  void      feoarrm4n5_sinh_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_cosh(     feoarrm4n5_t* arr);
  void      feoarrm4n5_cosh_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_atan(     feoarrm4n5_t* arr);
  void      feoarrm4n5_atan_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_asin(     feoarrm4n5_t* arr);
  void      feoarrm4n5_asin_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_acos(     feoarrm4n5_t* arr);
  void      feoarrm4n5_acos_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_tan(      feoarrm4n5_t* arr);
  void      feoarrm4n5_tan_to(   feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sin(      feoarrm4n5_t* arr);
  void      feoarrm4n5_sin_to(   feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_cos(      feoarrm4n5_t* arr);
  void      feoarrm4n5_cos_to(   feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_logb(     feoarrm4n5_t* arr, double base);
  void      feoarrm4n5_logb_to(  feoarrm4n5_t* arr, double base, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_log10(    feoarrm4n5_t* arr);
  void      feoarrm4n5_log10_to( feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_log(      feoarrm4n5_t* arr);
  void      feoarrm4n5_log_to(   feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_exp(      feoarrm4n5_t* arr);
  void      feoarrm4n5_exp_to(   feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_cbrt(     feoarrm4n5_t* arr);
  void      feoarrm4n5_cbrt_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sqrt(     feoarrm4n5_t* arr);
  void      feoarrm4n5_sqrt_to(  feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_pow(      feoarrm4n5_t* arr, double e);
  void      feoarrm4n5_pow_to(   feoarrm4n5_t* arr, double e, feoarrm4n5_t* res);
  
  
  # From ../../../include/oti/static/onumm4n5/array/gauss/base.h
  
  void      feoarrm4n5_get_order_im_to( ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_get_order_im(    ord_t order, feoarrm4n5_t* arr);
  feoarrm4n5_t feoarrm4n5_get_deriv(   imdir_t idx, ord_t order, feoarrm4n5_t* arr);
  void      feoarrm4n5_get_deriv_to(imdir_t idx, ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_get_im(      imdir_t idx, ord_t order, feoarrm4n5_t* arr);
  void      feoarrm4n5_get_im_to(   imdir_t idx, ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_truncate_im(   imdir_t idx, ord_t order, feoarrm4n5_t* arr);
  void      feoarrm4n5_truncate_im_to(imdir_t idx, ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_copy(   feoarrm4n5_t* src);
  void      feoarrm4n5_copy_to(feoarrm4n5_t* src, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_get_im(    imdir_t idx, ord_t order, feoarrm4n5_t* arr);
  void      feoarrm4n5_get_im_to( imdir_t idx, ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_get_deriv(    imdir_t idx, ord_t order, feoarrm4n5_t* arr);
  void      feoarrm4n5_get_deriv_to( imdir_t idx, ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_extract_im(    imdir_t idx, ord_t order, feoarrm4n5_t* arr);
  void      feoarrm4n5_extract_im_to( imdir_t idx, ord_t order, feoarrm4n5_t* arr,  feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_extract_deriv(    imdir_t idx, ord_t order, feoarrm4n5_t* arr);
  void      feoarrm4n5_extract_deriv_to( imdir_t idx, ord_t order, feoarrm4n5_t* arr, feoarrm4n5_t* res);
  oarrm4n5_t   feoarrm4n5_get_item_k(  feoarrm4n5_t* arr, uint64_t k);
  feonumm4n5_t  feoarrm4n5_get_item_ij( feoarrm4n5_t* arr, uint64_t i, uint64_t j);
  onumm4n5_t feoarrm4n5_get_item_ijk(feoarrm4n5_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm4n5_get_item_ij_to(  feoarrm4n5_t* arr, uint64_t i, uint64_t j,
                                 feonumm4n5_t* res);
  void feoarrm4n5_get_item_k_to(   feoarrm4n5_t* arr, uint64_t k,
                                  oarrm4n5_t* res);
  void feoarrm4n5_get_item_ijk_to( feoarrm4n5_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_get_slice(feoarrm4n5_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm4n5_get_slice_to(feoarrm4n5_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n5_t* res);
  void feoarrm4n5_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm4n5_t* res);
  void feoarrm4n5_set_item_ij_o(  onumm4n5_t* elm, uint64_t i, uint64_t j,
                               feoarrm4n5_t* res);
  void feoarrm4n5_set_item_ij_f(  feonumm4n5_t* elm, uint64_t i, uint64_t j,
                              feoarrm4n5_t* res);
  void feoarrm4n5_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm4n5_t* res);
  void feoarrm4n5_set_item_k_o(  onumm4n5_t* elm, uint64_t k,
                              feoarrm4n5_t* res);
  void feoarrm4n5_set_item_k_R(    oarrm4n5_t* elm, uint64_t k,
                            feoarrm4n5_t* res);
  void feoarrm4n5_set_item_k_O(    oarrm4n5_t* elm, uint64_t k,
                            feoarrm4n5_t* res);
  void feoarrm4n5_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm4n5_t* res);
  void feoarrm4n5_set_item_ijk_o( onumm4n5_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm4n5_t* res);
  void feoarrm4n5_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n5_t* res);
  void feoarrm4n5_set_slice_o( onumm4n5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n5_t* res);
  void feoarrm4n5_set_slice_f( feonumm4n5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n5_t* res);
  void feoarrm4n5_set_slice_O( oarrm4n5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n5_t* res);
  void feoarrm4n5_set_slice_F( feoarrm4n5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm4n5_t* res);
  void feoarrm4n5_set_all_o( onumm4n5_t* num, feoarrm4n5_t* arr );
  void feoarrm4n5_set_all_r(   coeff_t  num, feoarrm4n5_t* arr );
  void feoarrm4n5_set_all_f(  feonumm4n5_t* num, feoarrm4n5_t* arr );
  void feoarrm4n5_set_r(    coeff_t src, feoarrm4n5_t* res );
  void feoarrm4n5_set_o( onumm4n5_t* src, feoarrm4n5_t* res );
  void feoarrm4n5_set_f(  feonumm4n5_t* src, feoarrm4n5_t* res );
  void feoarrm4n5_set_R(    darr_t* src, feoarrm4n5_t* res );
  void feoarrm4n5_set_O(   oarrm4n5_t* src, feoarrm4n5_t* res );
  void feoarrm4n5_set_F( feoarrm4n5_t* src, feoarrm4n5_t* res );
  feoarrm4n5_t feoarrm4n5_eye( uint64_t size,  uint64_t nip);
  feoarrm4n5_t feoarrm4n5_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm4n5_t feoarrm4n5_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm4n5_t feoarrm4n5_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm4n5_free(feoarrm4n5_t* arr);
  feoarrm4n5_t feoarrm4n5_init();
  ord_t feoarrm4n5_get_order(feoarrm4n5_t* arr);
  
  
  # From ../../../include/oti/static/onumm4n5/array/gauss/utils.h
  
  void feoarrm4n5_dimCheck_FF_samesize(feoarrm4n5_t* arr1, feoarrm4n5_t* arr2, feonumm4n5_t* res);
  void feoarrm4n5_dimCheck_OF_samesize(  oarrm4n5_t* arr1, feoarrm4n5_t* arr2, feonumm4n5_t* res);
  void feoarrm4n5_dimCheck_RF_samesize(   darr_t* arr1, feoarrm4n5_t* arr2, feonumm4n5_t* res);
  void feoarrm4n5_dimCheck_FF_elementwise(feoarrm4n5_t* arr1, feoarrm4n5_t* arr2, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_OF_elementwise(  oarrm4n5_t* arr1, feoarrm4n5_t* arr2, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm4n5_t* arr2, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_fF_elementwise( feonumm4n5_t* num1, feoarrm4n5_t* arr2, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_Ff_elementwise(feoarrm4n5_t* arr1,  feonumm4n5_t* num2, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_FF_matmul( feoarrm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_OF_matmul(   oarrm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_RF_matmul(    darr_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_FO_matmul( feoarrm4n5_t* lhs,   oarrm4n5_t* rhs, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_FR_matmul( feoarrm4n5_t* lhs,    darr_t* rhs, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_F_squareness( feoarrm4n5_t* arr1, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_F_transpose( feoarrm4n5_t* arr1, feoarrm4n5_t* res);
  void feoarrm4n5_dimCheck_FfO_integrate(feoarrm4n5_t* arr, feonumm4n5_t* num,oarrm4n5_t* res);
  void feoarrm4n5_get_active_bases(feoarrm4n5_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm4n5/array/gauss/algebra.h
  
  feoarrm4n5_t feoarrm4n5_neg(    feoarrm4n5_t* arr);
  void      feoarrm4n5_neg_to( feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sum_FF(   feoarrm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sum_FF_to(feoarrm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sum_fF(    feonumm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sum_fF_to( feonumm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sum_OF(     oarrm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sum_OF_to(  oarrm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sum_RF(      darr_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sum_RF_to(   darr_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sum_oF(   onumm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sum_oF_to(onumm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sum_rF(     coeff_t  lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sum_rF_to(  coeff_t  lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sub_FF(    feoarrm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sub_FF_to( feoarrm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sub_fF(    feonumm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sub_fF_to( feonumm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sub_Ff(    feoarrm4n5_t* lhs, feonumm4n5_t* rhs);
  void      feoarrm4n5_sub_Ff_to( feoarrm4n5_t* lhs, feonumm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sub_OF(      oarrm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sub_OF_to(   oarrm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sub_FO(    feoarrm4n5_t* lhs,   oarrm4n5_t* rhs);
  void      feoarrm4n5_sub_FO_to( feoarrm4n5_t* lhs,   oarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sub_RF(       darr_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sub_RF_to(    darr_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sub_FR(    feoarrm4n5_t* lhs,    darr_t* rhs);
  void      feoarrm4n5_sub_FR_to( feoarrm4n5_t* lhs,    darr_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sub_oF(    onumm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sub_oF_to( onumm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sub_Fo(    feoarrm4n5_t* lhs, onumm4n5_t* rhs);
  void      feoarrm4n5_sub_Fo_to( feoarrm4n5_t* lhs, onumm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sub_rF(      coeff_t  lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_sub_rF_to(    coeff_t lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_sub_Fr(    feoarrm4n5_t* lhs,   coeff_t  rhs);
  void      feoarrm4n5_sub_Fr_to( feoarrm4n5_t* lhs,   coeff_t  rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_mul_FF(   feoarrm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_mul_FF_to(feoarrm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_mul_fF(    feonumm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_mul_fF_to( feonumm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_mul_OF(     oarrm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_mul_OF_to(  oarrm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_mul_RF(      darr_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_mul_RF_to(   darr_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_mul_oF(   onumm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_mul_oF_to(onumm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_mul_rF(     coeff_t  lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_mul_rF_to(  coeff_t  lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_div_FF(    feoarrm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_div_FF_to( feoarrm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_div_fF(     feonumm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_div_fF_to(  feonumm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_div_Ff(    feoarrm4n5_t* lhs,  feonumm4n5_t* rhs);
  void      feoarrm4n5_div_Ff_to( feoarrm4n5_t* lhs,  feonumm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_div_OF(      oarrm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_div_OF_to(   oarrm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_div_FO(    feoarrm4n5_t* lhs,   oarrm4n5_t* rhs);
  void      feoarrm4n5_div_FO_to( feoarrm4n5_t* lhs,   oarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_div_RF(       darr_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_div_RF_to(    darr_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_div_FR(    feoarrm4n5_t* lhs,    darr_t* rhs);
  void      feoarrm4n5_div_FR_to( feoarrm4n5_t* lhs,    darr_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_div_oF(    onumm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_div_oF_to( onumm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_div_Fo(    feoarrm4n5_t* lhs, onumm4n5_t* rhs);
  void      feoarrm4n5_div_Fo_to( feoarrm4n5_t* lhs, onumm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_div_rF(      coeff_t  lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_div_rF_to(    coeff_t lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_div_Fr(    feoarrm4n5_t* lhs,   coeff_t  rhs);
  void      feoarrm4n5_div_Fr_to( feoarrm4n5_t* lhs,   coeff_t  rhs, feoarrm4n5_t* res);
  oarrm4n5_t feoarrm4n5_integrate(    feoarrm4n5_t* arr, feonumm4n5_t* w);
  void    feoarrm4n5_integrate_to( feoarrm4n5_t* arr, feonumm4n5_t* w, oarrm4n5_t* res);
  feonumm4n5_t feoarrm4n5_dotproduct_FF(    feoarrm4n5_t* lhs, feoarrm4n5_t* rhs);
  void     feoarrm4n5_dotproduct_FF_to( feoarrm4n5_t* lhs, feoarrm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feoarrm4n5_dotproduct_OF(      oarrm4n5_t* lhs, feoarrm4n5_t* rhs);
  void     feoarrm4n5_dotproduct_OF_to(   oarrm4n5_t* lhs, feoarrm4n5_t* rhs, feonumm4n5_t* res);
  feonumm4n5_t feoarrm4n5_dotproduct_RF(       darr_t* lhs, feoarrm4n5_t* rhs);
  void     feoarrm4n5_dotproduct_RF_to(    darr_t* lhs, feoarrm4n5_t* rhs, feonumm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_matmul_FF(    feoarrm4n5_t* lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_matmul_FF_to( feoarrm4n5_t* lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_matmul_OF(    oarrm4n5_t*   lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_matmul_OF_to( oarrm4n5_t*   lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_matmul_FO(    feoarrm4n5_t* lhs, oarrm4n5_t*   rhs);
  void      feoarrm4n5_matmul_FO_to( feoarrm4n5_t* lhs, oarrm4n5_t*   rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_matmul_RF(    darr_t*    lhs, feoarrm4n5_t* rhs);
  void      feoarrm4n5_matmul_RF_to( darr_t*    lhs, feoarrm4n5_t* rhs, feoarrm4n5_t* res);
  feoarrm4n5_t feoarrm4n5_matmul_FR(    feoarrm4n5_t* lhs, darr_t*    rhs);
  void      feoarrm4n5_matmul_FR_to( feoarrm4n5_t* lhs, darr_t*    rhs, feoarrm4n5_t* res);
  feonumm4n5_t feoarrm4n5_det(   feoarrm4n5_t* arr);
  void     feoarrm4n5_det_to(feoarrm4n5_t* arr, feonumm4n5_t* res);
  feonumm4n5_t feoarrm4n5_norm(     feoarrm4n5_t* arr);
  void     feoarrm4n5_norm_to(  feoarrm4n5_t* arr, feonumm4n5_t* res);
  feonumm4n5_t feoarrm4n5_pnorm(    feoarrm4n5_t* arr, coeff_t p);
  void     feoarrm4n5_pnorm_to( feoarrm4n5_t* arr, coeff_t p, feonumm4n5_t* res);
  feoarrm4n5_t   feoarrm4n5_invert(    feoarrm4n5_t* arr);
  void        feoarrm4n5_invert_to( feoarrm4n5_t* arr, feoarrm4n5_t* res);
  feoarrm4n5_t   feoarrm4n5_transpose(   feoarrm4n5_t* arr);
  void        feoarrm4n5_transpose_to(feoarrm4n5_t* arr, feoarrm4n5_t* res);
  
  