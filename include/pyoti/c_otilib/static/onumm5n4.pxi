cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/onumm5n4/scalar/structures.h
  
  ctypedef struct  onumm5n4_t : # {
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
    coeff_t e1115;
    coeff_t e1125;
    coeff_t e1225;
    coeff_t e2225;
    coeff_t e1135;
    coeff_t e1235;
    coeff_t e2235;
    coeff_t e1335;
    coeff_t e2335;
    coeff_t e3335;
    coeff_t e1145;
    coeff_t e1245;
    coeff_t e2245;
    coeff_t e1345;
    coeff_t e2345;
    coeff_t e3345;
    coeff_t e1445;
    coeff_t e2445;
    coeff_t e3445;
    coeff_t e4445;
    coeff_t e1155;
    coeff_t e1255;
    coeff_t e2255;
    coeff_t e1355;
    coeff_t e2355;
    coeff_t e3355;
    coeff_t e1455;
    coeff_t e2455;
    coeff_t e3455;
    coeff_t e4455;
    coeff_t e1555;
    coeff_t e2555;
    coeff_t e3555;
    coeff_t e4555;
    coeff_t e5555;
  # } onumm5n4_t;
  
  
  # From ../../../include/oti/static/onumm5n4/array/structures.h
  
  ctypedef struct  oarrm5n4_t : # {
      onumm5n4_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } oarrm5n4_t;
  
  
  # From ../../../include/oti/static/onumm5n4/scalar/gauss/structures.h
  
  ctypedef struct  feonumm5n4_t: # {
      onumm5n4_t*  p_data;
      uint64_t    nip;
  # } feonumm5n4_t;
  
  
  # From ../../../include/oti/static/onumm5n4/array/gauss/structures.h
  
  ctypedef struct  feoarrm5n4_t: # {
      oarrm5n4_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } feoarrm5n4_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/onumm5n4/scalar/functions.h
  
  onumm5n4_t onumm5n4_atanh(onumm5n4_t* num);
  void onumm5n4_atanh_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_asinh(onumm5n4_t* num);
  void onumm5n4_asinh_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_acosh(onumm5n4_t* num);
  void onumm5n4_acosh_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_tanh(onumm5n4_t* num);
  void onumm5n4_tanh_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_sqrt(onumm5n4_t* num);
  void onumm5n4_sqrt_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_cbrt(onumm5n4_t* num);
  void onumm5n4_cbrt_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_cosh(onumm5n4_t* num);
  void onumm5n4_cosh_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_sinh(onumm5n4_t* num);
  void onumm5n4_sinh_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_asin(onumm5n4_t* num);
  void onumm5n4_asin_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_acos(onumm5n4_t* num);
  void onumm5n4_acos_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_atan(onumm5n4_t* num);
  void onumm5n4_atan_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_tan(onumm5n4_t* num);
  void onumm5n4_tan_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_cos(onumm5n4_t* num);
  void onumm5n4_cos_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_sin(onumm5n4_t* num );
  void onumm5n4_sin_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_logb(onumm5n4_t* num, double base);
  void onumm5n4_logb_to(onumm5n4_t* num, double base, onumm5n4_t* res);
  onumm5n4_t onumm5n4_log10(onumm5n4_t* num);
  void onumm5n4_log10_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_log(onumm5n4_t* num);
  void onumm5n4_log_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_exp(onumm5n4_t* num);
  void onumm5n4_exp_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_pow(onumm5n4_t* num, double e);
  void onumm5n4_pow_to(onumm5n4_t* num, coeff_t e, onumm5n4_t* res);
  
  
  # From ../../../include/oti/static/onumm5n4/scalar/base.h
  
  void onumm5n4_set_im_o(onumm5n4_t* num, imdir_t idx, ord_t order, onumm5n4_t* res);
  void onumm5n4_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm5n4_t* res);
  void onumm5n4_set_deriv_o(onumm5n4_t* num, imdir_t idx, ord_t order, onumm5n4_t* res);
  void onumm5n4_extract_im_to( imdir_t idx, ord_t order, onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_extract_im(imdir_t idx, ord_t order, onumm5n4_t* num);
  onumm5n4_t onumm5n4_extract_deriv(imdir_t idx, ord_t order, onumm5n4_t* num);
  void onumm5n4_extract_deriv_to(imdir_t idx, ord_t order, onumm5n4_t* num, onumm5n4_t* res);
  void onumm5n4_get_im_to_o(imdir_t idx, ord_t order, onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_get_im_o(imdir_t idx, ord_t order, onumm5n4_t* num);
  void onumm5n4_get_im_to_r(imdir_t idx, ord_t order, onumm5n4_t* num, coeff_t* res);
  ord_t onumm5n4_get_order(onumm5n4_t* lhs);
  onumm5n4_t onumm5n4_get_deriv_o( imdir_t idx, ord_t order, onumm5n4_t* num);
  void onumm5n4_get_deriv_to( imdir_t idx, ord_t order, onumm5n4_t* num, onumm5n4_t* res);
  void onumm5n4_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm5n4_t* res);
  onumm5n4_t onumm5n4_init();
  ndir_t onumm5n4_get_ndir_order(ord_t order, onumm5n4_t* num);
  ndir_t onumm5n4_get_ndir_total(onumm5n4_t* num);
  coeff_t* onumm5n4_get_order_address(ord_t order, onumm5n4_t* num);
  onumm5n4_t onumm5n4_create_r(  coeff_t lhs);
  void onumm5n4_set_r(  coeff_t lhs, onumm5n4_t* res);
  void onumm5n4_set_o(  onumm5n4_t* lhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_get_order_im(ord_t order, onumm5n4_t* lhs);
  void onumm5n4_get_order_im_to(ord_t order, onumm5n4_t* lhs, onumm5n4_t* res);
  coeff_t onumm5n4_get_item(imdir_t idx, ord_t order, onumm5n4_t* lhs);
  coeff_t onumm5n4_get_deriv(imdir_t idx, ord_t order, onumm5n4_t* lhs);
  void onumm5n4_set_item(coeff_t val, imdir_t idx, ord_t order, onumm5n4_t* x);
  onumm5n4_t onumm5n4_copy(  onumm5n4_t* lhs);
  void onumm5n4_copy_to(  onumm5n4_t* lhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_taylor_integrate(coeff_t* deltas,onumm5n4_t* lhs);
  void onumm5n4_taylor_integrate_to(coeff_t* deltas,onumm5n4_t* lhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_truncate_im(imdir_t idx, ord_t order, onumm5n4_t* lhs);
  void onumm5n4_truncate_im_to(imdir_t idx, ord_t order, onumm5n4_t* lhs, onumm5n4_t* res);
  void onumm5n4_print(  onumm5n4_t* lhs);
  imdir_t onumm5n4_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/onumm5n4/scalar/utils.h
  
  void onumm5n4_get_active_bases(onumm5n4_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/onumm5n4/scalar/algebra.h
  
  onumm5n4_t onumm5n4_abs(onumm5n4_t* num);
  onumm5n4_t onumm5n4_div_ro(coeff_t num, onumm5n4_t* den);
  onumm5n4_t onumm5n4_div_oo(onumm5n4_t* num, onumm5n4_t* den);
  onumm5n4_t onumm5n4_div_or(onumm5n4_t* num, coeff_t val);
  void onumm5n4_div_ro_to(coeff_t num, onumm5n4_t* den, onumm5n4_t* res);
  void onumm5n4_div_oo_to(onumm5n4_t* num, onumm5n4_t* den, onumm5n4_t* res);
  void onumm5n4_div_or_to(onumm5n4_t* num, coeff_t val, onumm5n4_t* res);
  void onumm5n4_abs_to(onumm5n4_t* num, onumm5n4_t* res);
  onumm5n4_t onumm5n4_neg(  onumm5n4_t* lhs);
  void onumm5n4_neg_to(  onumm5n4_t* lhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_sum_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs);
  void onumm5n4_sum_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_sum_ro(  coeff_t lhs,  onumm5n4_t* rhs);
  void onumm5n4_sum_ro_to(  coeff_t lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_sub_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs);
  void onumm5n4_sub_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_sub_ro(  coeff_t lhs,  onumm5n4_t* rhs);
  void onumm5n4_sub_ro_to(  coeff_t lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_sub_or(  onumm5n4_t* lhs,  coeff_t rhs);
  void onumm5n4_sub_or_to(  onumm5n4_t* lhs,  coeff_t rhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_mul_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs);
  void onumm5n4_mul_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_mul_ro(  coeff_t lhs,  onumm5n4_t* rhs);
  void onumm5n4_mul_ro_to(  coeff_t lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_trunc_mul_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs);
  void onumm5n4_trunc_mul_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
  onumm5n4_t onumm5n4_gem_oo(  onumm5n4_t* a,  onumm5n4_t* b,  onumm5n4_t* c);
  void onumm5n4_gem_oo_to(  onumm5n4_t* a,  onumm5n4_t* b,  onumm5n4_t* c, onumm5n4_t* res);
  onumm5n4_t onumm5n4_gem_ro(  coeff_t a,  onumm5n4_t* b,  onumm5n4_t* c);
  void onumm5n4_gem_ro_to(  coeff_t a,  onumm5n4_t* b,  onumm5n4_t* c, onumm5n4_t* res);
  void onumm5n4_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n4_t* a,  ord_t ord_rhs,  onumm5n4_t* b,  onumm5n4_t* c, onumm5n4_t* res);
  onumm5n4_t onumm5n4_feval(coeff_t* feval_re, onumm5n4_t* x);
  void onumm5n4_feval_to(coeff_t* feval_re, onumm5n4_t* x, onumm5n4_t* res);
  
  
  # From ../../../include/oti/static/onumm5n4/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm5n4/scalar/gauss/functions.h
  
  feonumm5n4_t feonumm5n4_atanh(    feonumm5n4_t* num);
  void     feonumm5n4_atanh_to( feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_asinh(    feonumm5n4_t* num);
  void     feonumm5n4_asinh_to( feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_acosh(    feonumm5n4_t* num);
  void     feonumm5n4_acosh_to( feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_tanh(     feonumm5n4_t* num);
  void     feonumm5n4_tanh_to(  feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_cosh(     feonumm5n4_t* num);
  void     feonumm5n4_cosh_to(  feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_sinh(     feonumm5n4_t* num);
  void     feonumm5n4_sinh_to(  feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_asin(     feonumm5n4_t* num);
  void     feonumm5n4_asin_to(  feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_acos(     feonumm5n4_t* num);
  void     feonumm5n4_acos_to(  feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_atan(     feonumm5n4_t* num);
  void     feonumm5n4_atan_to(  feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_tan(      feonumm5n4_t* num);
  void     feonumm5n4_tan_to(   feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_cos(      feonumm5n4_t* num);
  void     feonumm5n4_cos_to(   feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_sin(      feonumm5n4_t* num);
  void     feonumm5n4_sin_to(   feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_logb(     feonumm5n4_t* num, double base);
  void     feonumm5n4_logb_to(  feonumm5n4_t* num, double base, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_log10(    feonumm5n4_t* num);
  void     feonumm5n4_log10_to( feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_log(      feonumm5n4_t* num);
  void     feonumm5n4_log_to(   feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_exp(      feonumm5n4_t* num);
  void     feonumm5n4_exp_to(   feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_cbrt(     feonumm5n4_t* num);
  void     feonumm5n4_cbrt_to(  feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_sqrt(     feonumm5n4_t* num);
  void     feonumm5n4_sqrt_to(  feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_pow(      feonumm5n4_t* num, double e);
  void     feonumm5n4_pow_to(   feonumm5n4_t* num, double e, feonumm5n4_t* res);
  onumm5n4_t feonumm5n4_integrate(       feonumm5n4_t* num, feonumm5n4_t* w);
  void      feonumm5n4_integrate_to(    feonumm5n4_t* num, feonumm5n4_t* w, onumm5n4_t* res);
  onumm5n4_t feonumm5n4_integrate_f(     feonumm5n4_t* num, feonumm5n4_t* w);
  void      feonumm5n4_integrate_f_to(  feonumm5n4_t* num, feonumm5n4_t* w, onumm5n4_t* res);
  onumm5n4_t feonumm5n4_integrate_r(       coeff_t num, feonumm5n4_t* w);
  void      feonumm5n4_integrate_r_to(    coeff_t num, feonumm5n4_t* w, onumm5n4_t* res);
  onumm5n4_t feonumm5n4_integrate_o(    onumm5n4_t* num, feonumm5n4_t* w);
  void      feonumm5n4_integrate_o_to( onumm5n4_t* num, feonumm5n4_t* w, onumm5n4_t* res);
  
  
  # From ../../../include/oti/static/onumm5n4/scalar/gauss/base.h
  
  void     feonumm5n4_get_order_im_to( ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_get_order_im(    ord_t order, feonumm5n4_t* num);
  feonumm5n4_t feonumm5n4_get_im(    imdir_t idx, ord_t order, feonumm5n4_t* num);
  void     feonumm5n4_get_im_to( imdir_t idx, ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_get_deriv(    imdir_t idx, ord_t order, feonumm5n4_t* num);
  void     feonumm5n4_get_deriv_to( imdir_t idx, ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
  void feonumm5n4_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm5n4_t* num);
  void feonumm5n4_set_im_o( onumm5n4_t* val, imdir_t idx, ord_t order, feonumm5n4_t* num);
  void feonumm5n4_set_im_f(  feonumm5n4_t* val, imdir_t idx, ord_t order, feonumm5n4_t* num);
  void feonumm5n4_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm5n4_t* num);
  void feonumm5n4_set_deriv_o( onumm5n4_t* val, imdir_t idx, ord_t order, feonumm5n4_t* num);
  void feonumm5n4_set_deriv_f(  feonumm5n4_t* val, imdir_t idx, ord_t order, feonumm5n4_t* num);
  feonumm5n4_t feonumm5n4_extract_im(    imdir_t idx, ord_t order, feonumm5n4_t* num);
  void     feonumm5n4_extract_im_to( imdir_t idx, ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_extract_deriv(    imdir_t idx, ord_t order, feonumm5n4_t* num);
  void     feonumm5n4_extract_deriv_to( imdir_t idx, ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_truncate_im(    imdir_t idx, ord_t order, feonumm5n4_t* num);
  void     feonumm5n4_truncate_im_to( imdir_t idx, ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_copy(    feonumm5n4_t* src);
  void     feonumm5n4_copy_to( feonumm5n4_t* src, feonumm5n4_t* dst);
  void feonumm5n4_set_r(    coeff_t num, feonumm5n4_t* res);
  void feonumm5n4_set_o( onumm5n4_t* num, feonumm5n4_t* res);
  void feonumm5n4_set_f(  feonumm5n4_t* num, feonumm5n4_t* res);
  void feonumm5n4_set_item_k_r(   coeff_t  num, uint64_t k, feonumm5n4_t* res);
  void feonumm5n4_set_item_k_o( onumm5n4_t* num, uint64_t k, feonumm5n4_t* res);
  onumm5n4_t feonumm5n4_get_item_k(   feonumm5n4_t* num, uint64_t k);
  void      feonumm5n4_get_item_k_to(feonumm5n4_t* num, uint64_t k, onumm5n4_t* res);
  feonumm5n4_t feonumm5n4_zeros(uint64_t nIntPts);
  feonumm5n4_t feonumm5n4_createEmpty(uint64_t nIntPts);
  feonumm5n4_t feonumm5n4_empty_like(feonumm5n4_t* arr);
  void feonumm5n4_free(feonumm5n4_t* num);
  ord_t feonumm5n4_get_order( feonumm5n4_t* num );
  feonumm5n4_t feonumm5n4_init();
  
  
  # From ../../../include/oti/static/onumm5n4/scalar/gauss/utils.h
  
  void feonumm5n4_dimCheck(feonumm5n4_t* arr1,feonumm5n4_t* arr2);
  void feonumm5n4_get_active_bases(feonumm5n4_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n4/scalar/gauss/algebra.h
  
  feonumm5n4_t feonumm5n4_neg(   feonumm5n4_t* num);
  void     feonumm5n4_neg_to(feonumm5n4_t* num, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_sum_ff(   feonumm5n4_t* lhs, feonumm5n4_t* rhs);
  void     feonumm5n4_sum_ff_to(feonumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_sum_of(   onumm5n4_t* lhs, feonumm5n4_t* rhs);
  void     feonumm5n4_sum_of_to(onumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_sum_rf(   coeff_t lhs, feonumm5n4_t* rhs);
  void     feonumm5n4_sum_rf_to(coeff_t lhs, feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_sub_ff(     feonumm5n4_t* lhs,  feonumm5n4_t* rhs);
  void     feonumm5n4_sub_ff_to(  feonumm5n4_t* lhs,  feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_sub_of(    onumm5n4_t* lhs,  feonumm5n4_t* rhs);
  void     feonumm5n4_sub_of_to( onumm5n4_t* lhs,  feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_sub_fo(     feonumm5n4_t* lhs, onumm5n4_t* rhs);
  void     feonumm5n4_sub_fo_to(  feonumm5n4_t* lhs, onumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_sub_rf(       coeff_t lhs,  feonumm5n4_t* rhs);
  void     feonumm5n4_sub_rf_to(    coeff_t lhs,  feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_sub_fr(     feonumm5n4_t* lhs,    coeff_t rhs);
  void     feonumm5n4_sub_fr_to(  feonumm5n4_t* lhs,    coeff_t rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_mul_ff(   feonumm5n4_t* lhs, feonumm5n4_t* rhs);
  void     feonumm5n4_mul_ff_to(feonumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_mul_of(   onumm5n4_t* lhs, feonumm5n4_t* rhs);
  void     feonumm5n4_mul_of_to(onumm5n4_t* lhs, feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_mul_rf(   coeff_t lhs, feonumm5n4_t* rhs);
  void     feonumm5n4_mul_rf_to(coeff_t lhs, feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_div_ff(     feonumm5n4_t* lhs,  feonumm5n4_t* rhs);
  void     feonumm5n4_div_ff_to(  feonumm5n4_t* lhs,  feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_div_of(    onumm5n4_t* lhs,  feonumm5n4_t* rhs);
  void     feonumm5n4_div_of_to( onumm5n4_t* lhs,  feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_div_fo(     feonumm5n4_t* lhs, onumm5n4_t* rhs);
  void     feonumm5n4_div_fo_to(  feonumm5n4_t* lhs, onumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_div_rf(       coeff_t lhs,  feonumm5n4_t* rhs);
  void     feonumm5n4_div_rf_to(    coeff_t lhs,  feonumm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feonumm5n4_div_fr(     feonumm5n4_t* lhs,    coeff_t rhs);
  void     feonumm5n4_div_fr_to(  feonumm5n4_t* lhs,    coeff_t rhs, feonumm5n4_t* res);
  
  
  # From ../../../include/oti/static/onumm5n4/array/functions.h
  
  oarrm5n4_t oarrm5n4_atanh(   oarrm5n4_t* arr);
  void    oarrm5n4_atanh_to(oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_asinh(   oarrm5n4_t* arr);
  void    oarrm5n4_asinh_to(oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_acosh(   oarrm5n4_t* arr);
  void    oarrm5n4_acosh_to(oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_tanh(    oarrm5n4_t* arr);
  void    oarrm5n4_tanh_to( oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_cbrt(    oarrm5n4_t* arr);
  void    oarrm5n4_cbrt_to( oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_sqrt(    oarrm5n4_t* arr);
  void    oarrm5n4_sqrt_to( oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_cosh(    oarrm5n4_t* arr);
  void    oarrm5n4_cosh_to( oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_sinh(    oarrm5n4_t* arr);
  void    oarrm5n4_sinh_to( oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_asin(    oarrm5n4_t* arr);
  void    oarrm5n4_asin_to( oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_acos(    oarrm5n4_t* arr);
  void    oarrm5n4_acos_to( oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_atan(    oarrm5n4_t* arr);
  void    oarrm5n4_atan_to( oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_tan(     oarrm5n4_t* arr);
  void    oarrm5n4_tan_to(  oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_cos(     oarrm5n4_t* arr);
  void    oarrm5n4_cos_to(  oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_sin(     oarrm5n4_t* arr);
  void    oarrm5n4_sin_to(  oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_logb(    oarrm5n4_t* arr, double base);
  void    oarrm5n4_logb_to( oarrm5n4_t* arr, double base, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_log10(   oarrm5n4_t* arr);
  void    oarrm5n4_log10_to(oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_log(     oarrm5n4_t* arr);
  void    oarrm5n4_log_to(  oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_exp(     oarrm5n4_t* arr);
  void    oarrm5n4_exp_to(  oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_pow(     oarrm5n4_t* arr, double e);
  void    oarrm5n4_pow_to(  oarrm5n4_t* arr, double e, oarrm5n4_t* res);
  
  
  # From ../../../include/oti/static/onumm5n4/array/algebra_elementwise.h
  
  oarrm5n4_t oarrm5n4_neg(oarrm5n4_t* arr);
  void oarrm5n4_neg_to(oarrm5n4_t* rhs, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_sum_OO(oarrm5n4_t*   lhs, oarrm5n4_t* rhs);
  oarrm5n4_t oarrm5n4_sum_RO(darr_t*    lhs, oarrm5n4_t* rhs);
  oarrm5n4_t oarrm5n4_sum_oO(onumm5n4_t* lhs, oarrm5n4_t* rhs);
  oarrm5n4_t oarrm5n4_sum_rO(coeff_t    lhs, oarrm5n4_t* rhs);
  void oarrm5n4_sum_OO_to(oarrm5n4_t*   lhs, oarrm5n4_t* rhs, oarrm5n4_t* res);
  void oarrm5n4_sum_RO_to(darr_t*    lhs, oarrm5n4_t* rhs, oarrm5n4_t* res);
  void oarrm5n4_sum_oO_to(onumm5n4_t* lhs, oarrm5n4_t* rhs, oarrm5n4_t* res);
  void oarrm5n4_sum_rO_to(coeff_t    lhs, oarrm5n4_t* rhs, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_sub_OO(oarrm5n4_t*   lhs, oarrm5n4_t*   rhs);
  oarrm5n4_t oarrm5n4_sub_RO(darr_t*    lhs, oarrm5n4_t*   rhs);
  oarrm5n4_t oarrm5n4_sub_OR(oarrm5n4_t*   lhs, darr_t*    rhs);
  oarrm5n4_t oarrm5n4_sub_oO(onumm5n4_t* lhs, oarrm5n4_t*   rhs);
  oarrm5n4_t oarrm5n4_sub_Oo(oarrm5n4_t*   lhs, onumm5n4_t* rhs);
  oarrm5n4_t oarrm5n4_sub_rO(coeff_t    lhs, oarrm5n4_t*   rhs);
  oarrm5n4_t oarrm5n4_sub_Or(oarrm5n4_t*   lhs, coeff_t    rhs);
  void oarrm5n4_sub_OO_to( oarrm5n4_t*   lhs, oarrm5n4_t*   rhs, oarrm5n4_t* res);
  void oarrm5n4_sub_RO_to( darr_t*    lhs, oarrm5n4_t*   rhs, oarrm5n4_t* res);
  void oarrm5n4_sub_OR_to( oarrm5n4_t*   lhs, darr_t*    rhs, oarrm5n4_t* res);
  void oarrm5n4_sub_oO_to( onumm5n4_t* lhs, oarrm5n4_t*   rhs, oarrm5n4_t* res);
  void oarrm5n4_sub_Oo_to( oarrm5n4_t*   lhs, onumm5n4_t* rhs, oarrm5n4_t* res);
  void oarrm5n4_sub_rO_to( coeff_t    lhs, oarrm5n4_t*   rhs, oarrm5n4_t* res);
  void oarrm5n4_sub_Or_to( oarrm5n4_t*   lhs, coeff_t    rhs, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_mul_OO(oarrm5n4_t*   lhs, oarrm5n4_t* rhs);
  oarrm5n4_t oarrm5n4_mul_RO(darr_t*    lhs, oarrm5n4_t* rhs);
  oarrm5n4_t oarrm5n4_mul_oO(onumm5n4_t* lhs, oarrm5n4_t* rhs);
  oarrm5n4_t oarrm5n4_mul_rO(coeff_t    lhs, oarrm5n4_t* rhs);
  void oarrm5n4_mul_OO_to(oarrm5n4_t*   lhs, oarrm5n4_t* rhs, oarrm5n4_t* res);
  void oarrm5n4_mul_RO_to(darr_t*    lhs, oarrm5n4_t* rhs, oarrm5n4_t* res);
  void oarrm5n4_mul_oO_to(onumm5n4_t* lhs, oarrm5n4_t* rhs, oarrm5n4_t* res);
  void oarrm5n4_mul_rO_to(coeff_t    lhs, oarrm5n4_t* rhs, oarrm5n4_t* res);
  void oarrm5n4_gem_OO_to(  oarrm5n4_t* arr1, oarrm5n4_t* arr2, oarrm5n4_t* arr3, oarrm5n4_t* res);
  void oarrm5n4_gem_oO_to(onumm5n4_t* arr1, oarrm5n4_t* arr2, oarrm5n4_t* arr3, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_div_OO(oarrm5n4_t*   lhs, oarrm5n4_t*   rhs);
  oarrm5n4_t oarrm5n4_div_OR(oarrm5n4_t*   lhs, darr_t*    rhs);
  oarrm5n4_t oarrm5n4_div_RO(darr_t*    lhs, oarrm5n4_t*   rhs);
  oarrm5n4_t oarrm5n4_div_oO(onumm5n4_t* lhs, oarrm5n4_t*   rhs);
  oarrm5n4_t oarrm5n4_div_Oo(oarrm5n4_t*   lhs, onumm5n4_t* rhs);
  oarrm5n4_t oarrm5n4_div_rO(coeff_t    lhs, oarrm5n4_t*   rhs);
  oarrm5n4_t oarrm5n4_div_Or(oarrm5n4_t*   lhs, coeff_t    rhs);
  void oarrm5n4_div_OO_to(oarrm5n4_t*   lhs, oarrm5n4_t*   rhs, oarrm5n4_t* res);
  void oarrm5n4_div_RO_to(darr_t*    lhs, oarrm5n4_t*   rhs, oarrm5n4_t* res);
  void oarrm5n4_div_OR_to(oarrm5n4_t*   lhs, darr_t*    rhs, oarrm5n4_t* res);
  void oarrm5n4_div_oO_to(onumm5n4_t* lhs, oarrm5n4_t*   rhs, oarrm5n4_t* res);
  void oarrm5n4_div_Oo_to(oarrm5n4_t*   lhs, onumm5n4_t* rhs, oarrm5n4_t* res);
  void oarrm5n4_div_rO_to(coeff_t    lhs, oarrm5n4_t*   rhs, oarrm5n4_t* res);
  void oarrm5n4_div_Or_to(oarrm5n4_t*   lhs, coeff_t    rhs, oarrm5n4_t* res);
  
  
  # From ../../../include/oti/static/onumm5n4/array/base.h
  
  void    oarrm5n4_taylor_integrate_to( coeff_t* deltas, oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_taylor_integrate(    coeff_t* deltas, oarrm5n4_t* arr);
  void    oarrm5n4_get_order_im_to( ord_t order, oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_get_order_im(    ord_t order, oarrm5n4_t* arr);
  void oarrm5n4_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n4_t* res);
  void oarrm5n4_set_slice_O( oarrm5n4_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n4_t* res);
  void oarrm5n4_set_slice_o( onumm5n4_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_get_slice( oarrm5n4_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void oarrm5n4_get_slice_to( oarrm5n4_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_truncate_im(    imdir_t idx, ord_t order, oarrm5n4_t* arr);
  void    oarrm5n4_truncate_im_to( imdir_t idx, ord_t order, oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_extract_im(   imdir_t idx, ord_t order, oarrm5n4_t* arr);
  void    oarrm5n4_extract_im_to(imdir_t idx, ord_t order, oarrm5n4_t* arr, oarrm5n4_t* res);
  darr_t  oarrm5n4_get_deriv(    imdir_t idx, ord_t order, oarrm5n4_t* arr);
  void    oarrm5n4_get_deriv_to( imdir_t idx, ord_t order, oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_get_deriv_o(  imdir_t idx, ord_t order, oarrm5n4_t* arr);
  oarrm5n4_t oarrm5n4_extract_deriv(    imdir_t idx, ord_t order, oarrm5n4_t* arr);
  void    oarrm5n4_extract_deriv_to( imdir_t idx, ord_t order, oarrm5n4_t* arr, oarrm5n4_t* res);
  darr_t  oarrm5n4_get_im(   imdir_t idx, ord_t order, oarrm5n4_t* arr);
  oarrm5n4_t oarrm5n4_get_im_o( imdir_t idx, ord_t order, oarrm5n4_t* arr);
  void    oarrm5n4_get_im_to(imdir_t idx, ord_t order, oarrm5n4_t* arr, oarrm5n4_t* res);
  void    oarrm5n4_copy_to(oarrm5n4_t* arr, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_copy(oarrm5n4_t* arr);
  void oarrm5n4_set_all_r( coeff_t num, oarrm5n4_t* arr);
  void oarrm5n4_set_item_i_r( coeff_t num, uint64_t i, oarrm5n4_t* arr);
  void oarrm5n4_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarrm5n4_t* arr);
  void oarrm5n4_set_r(   coeff_t  num,   oarrm5n4_t* arr);
  void oarrm5n4_set_o( onumm5n4_t* num,   oarrm5n4_t* arr);
  void oarrm5n4_set_O(   oarrm5n4_t* arrin, oarrm5n4_t* arr);
  void oarrm5n4_set_all_o( onumm5n4_t* src, oarrm5n4_t* arr);
  void oarrm5n4_set_item_i_o( onumm5n4_t* num, uint64_t i, oarrm5n4_t* arr);
  void oarrm5n4_set_item_ij_o( onumm5n4_t* num, uint64_t i, uint64_t j, oarrm5n4_t* arr);
  onumm5n4_t oarrm5n4_get_item_i(    oarrm5n4_t* arr, uint64_t i);
  void      oarrm5n4_get_item_i_to( oarrm5n4_t* arr, uint64_t i,             onumm5n4_t* res);
  onumm5n4_t oarrm5n4_get_item_ij(   oarrm5n4_t* arr, uint64_t i, uint64_t j);
  void      oarrm5n4_get_item_ij_to(oarrm5n4_t* arr, uint64_t i, uint64_t j, onumm5n4_t* res);
  oarrm5n4_t oarrm5n4_init();
  void oarrm5n4_free(oarrm5n4_t* arr);
  oarrm5n4_t oarrm5n4_empty_like(oarrm5n4_t* arr);
  oarrm5n4_t oarrm5n4_eye(uint64_t nrows);
  oarrm5n4_t oarrm5n4_ones(uint64_t nrows, uint64_t ncols);
  oarrm5n4_t oarrm5n4_zeros(uint64_t nrows, uint64_t ncols);
  oarrm5n4_t oarrm5n4_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/onumm5n4/array/utils.h
  
  void oarrm5n4_dimCheck_OO_elementwise(oarrm5n4_t* arr1, oarrm5n4_t* arr2, oarrm5n4_t* res);
  void oarrm5n4_dimCheck_RO_elementwise(darr_t*  arr1, oarrm5n4_t* arr2, oarrm5n4_t* res);
  void oarrm5n4_dimCheck_OO_matmul(oarrm5n4_t* arr1, oarrm5n4_t* arr2, oarrm5n4_t* res);
  void oarrm5n4_dimCheck_RO_matmul(darr_t*  arr1, oarrm5n4_t* arr2, oarrm5n4_t* res);
  void oarrm5n4_dimCheck_OR_matmul(oarrm5n4_t* arr1, darr_t*  arr2, oarrm5n4_t* res);
  void oarrm5n4_dimCheck_O_squareness(oarrm5n4_t* arr1, oarrm5n4_t* res);
  void oarrm5n4_dimCheck_OO_samesize(oarrm5n4_t* arr1, oarrm5n4_t* res);
  void oarrm5n4_dimCheck_RO_samesize(darr_t* arr1, oarrm5n4_t* res);
  ord_t oarrm5n4_get_order(oarrm5n4_t* arr);
  void oarrm5n4_get_active_bases(oarrm5n4_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n4/array/algebra_matops.h
  
  onumm5n4_t oarrm5n4_dotproduct_OO(    oarrm5n4_t* lhs, oarrm5n4_t* rhs);
  void      oarrm5n4_dotproduct_OO_to( oarrm5n4_t* lhs, oarrm5n4_t* rhs, onumm5n4_t* res);
  onumm5n4_t oarrm5n4_dotproduct_RO(     darr_t* lhs, oarrm5n4_t* rhs);
  void      oarrm5n4_dotproduct_RO_to(  darr_t* lhs, oarrm5n4_t* rhs, onumm5n4_t* res);
  oarrm5n4_t oarrm5n4_matmul_OO(    oarrm5n4_t* lhs, oarrm5n4_t* rhs);
  oarrm5n4_t oarrm5n4_matmul_OR(    oarrm5n4_t* lhs,  darr_t* rhs);
  oarrm5n4_t oarrm5n4_matmul_RO(     darr_t* lhs, oarrm5n4_t* rhs);
  void    oarrm5n4_matmul_OO_to( oarrm5n4_t* lhs, oarrm5n4_t* rhs, oarrm5n4_t* res);
  void    oarrm5n4_matmul_OR_to( oarrm5n4_t* lhs,  darr_t* rhs, oarrm5n4_t* res);
  void    oarrm5n4_matmul_RO_to(  darr_t* lhs, oarrm5n4_t* rhs, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_transpose(    oarrm5n4_t* arr1);
  void    oarrm5n4_transpose_to( oarrm5n4_t* arr1, oarrm5n4_t* res);
  oarrm5n4_t oarrm5n4_invert(    oarrm5n4_t* arr1);
  void    oarrm5n4_invert_to( oarrm5n4_t* arr1, oarrm5n4_t* res);
  onumm5n4_t oarrm5n4_det(    oarrm5n4_t* arr1);
  void      oarrm5n4_det_to( oarrm5n4_t* arr1, onumm5n4_t* res);
  onumm5n4_t oarrm5n4_norm(    oarrm5n4_t* arr1);
  void      oarrm5n4_norm_to( oarrm5n4_t* arr1,  onumm5n4_t* res);
  onumm5n4_t oarrm5n4_pnorm(    oarrm5n4_t* arr1, coeff_t p);
  void      oarrm5n4_pnorm_to( oarrm5n4_t* arr1, coeff_t p, onumm5n4_t* res);
  
  
  # From ../../../include/oti/static/onumm5n4/array/gauss.h
  
  
  
  # From ../../../include/oti/static/onumm5n4/array/gauss/functions.h
  
  feoarrm5n4_t feoarrm5n4_atanh(    feoarrm5n4_t* arr);
  void      feoarrm5n4_atanh_to( feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_asinh(    feoarrm5n4_t* arr);
  void      feoarrm5n4_asinh_to( feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_acosh(    feoarrm5n4_t* arr);
  void      feoarrm5n4_acosh_to( feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_tanh(     feoarrm5n4_t* arr);
  void      feoarrm5n4_tanh_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sinh(     feoarrm5n4_t* arr);
  void      feoarrm5n4_sinh_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_cosh(     feoarrm5n4_t* arr);
  void      feoarrm5n4_cosh_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_atan(     feoarrm5n4_t* arr);
  void      feoarrm5n4_atan_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_asin(     feoarrm5n4_t* arr);
  void      feoarrm5n4_asin_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_acos(     feoarrm5n4_t* arr);
  void      feoarrm5n4_acos_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_tan(      feoarrm5n4_t* arr);
  void      feoarrm5n4_tan_to(   feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sin(      feoarrm5n4_t* arr);
  void      feoarrm5n4_sin_to(   feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_cos(      feoarrm5n4_t* arr);
  void      feoarrm5n4_cos_to(   feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_logb(     feoarrm5n4_t* arr, double base);
  void      feoarrm5n4_logb_to(  feoarrm5n4_t* arr, double base, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_log10(    feoarrm5n4_t* arr);
  void      feoarrm5n4_log10_to( feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_log(      feoarrm5n4_t* arr);
  void      feoarrm5n4_log_to(   feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_exp(      feoarrm5n4_t* arr);
  void      feoarrm5n4_exp_to(   feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_cbrt(     feoarrm5n4_t* arr);
  void      feoarrm5n4_cbrt_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sqrt(     feoarrm5n4_t* arr);
  void      feoarrm5n4_sqrt_to(  feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_pow(      feoarrm5n4_t* arr, double e);
  void      feoarrm5n4_pow_to(   feoarrm5n4_t* arr, double e, feoarrm5n4_t* res);
  
  
  # From ../../../include/oti/static/onumm5n4/array/gauss/base.h
  
  void      feoarrm5n4_get_order_im_to( ord_t order, feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_get_order_im(    ord_t order, feoarrm5n4_t* arr);
  feoarrm5n4_t feoarrm5n4_get_deriv(   imdir_t idx, ord_t order, feoarrm5n4_t* arr);
  void      feoarrm5n4_get_deriv_to(imdir_t idx, ord_t order, feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_get_im(      imdir_t idx, ord_t order, feoarrm5n4_t* arr);
  void      feoarrm5n4_get_im_to(   imdir_t idx, ord_t order, feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_truncate_im(   imdir_t idx, ord_t order, feoarrm5n4_t* arr);
  void      feoarrm5n4_truncate_im_to(imdir_t idx, ord_t order, feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_copy(   feoarrm5n4_t* src);
  void      feoarrm5n4_copy_to(feoarrm5n4_t* src, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_get_im(    imdir_t idx, ord_t order, feoarrm5n4_t* arr);
  void      feoarrm5n4_get_im_to( imdir_t idx, ord_t order, feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_get_deriv(    imdir_t idx, ord_t order, feoarrm5n4_t* arr);
  void      feoarrm5n4_get_deriv_to( imdir_t idx, ord_t order, feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_extract_im(    imdir_t idx, ord_t order, feoarrm5n4_t* arr);
  void      feoarrm5n4_extract_im_to( imdir_t idx, ord_t order, feoarrm5n4_t* arr,  feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_extract_deriv(    imdir_t idx, ord_t order, feoarrm5n4_t* arr);
  void      feoarrm5n4_extract_deriv_to( imdir_t idx, ord_t order, feoarrm5n4_t* arr, feoarrm5n4_t* res);
  oarrm5n4_t   feoarrm5n4_get_item_k(  feoarrm5n4_t* arr, uint64_t k);
  feonumm5n4_t  feoarrm5n4_get_item_ij( feoarrm5n4_t* arr, uint64_t i, uint64_t j);
  onumm5n4_t feoarrm5n4_get_item_ijk(feoarrm5n4_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void feoarrm5n4_get_item_ij_to(  feoarrm5n4_t* arr, uint64_t i, uint64_t j,
                                 feonumm5n4_t* res);
  void feoarrm5n4_get_item_k_to(   feoarrm5n4_t* arr, uint64_t k,
                                  oarrm5n4_t* res);
  void feoarrm5n4_get_item_ijk_to( feoarrm5n4_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                onumm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_get_slice(feoarrm5n4_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      feoarrm5n4_get_slice_to(feoarrm5n4_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n4_t* res);
  void feoarrm5n4_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              feoarrm5n4_t* res);
  void feoarrm5n4_set_item_ij_o(  onumm5n4_t* elm, uint64_t i, uint64_t j,
                               feoarrm5n4_t* res);
  void feoarrm5n4_set_item_ij_f(  feonumm5n4_t* elm, uint64_t i, uint64_t j,
                              feoarrm5n4_t* res);
  void feoarrm5n4_set_item_k_r(    coeff_t  elm, uint64_t k,
                              feoarrm5n4_t* res);
  void feoarrm5n4_set_item_k_o(  onumm5n4_t* elm, uint64_t k,
                              feoarrm5n4_t* res);
  void feoarrm5n4_set_item_k_R(    oarrm5n4_t* elm, uint64_t k,
                            feoarrm5n4_t* res);
  void feoarrm5n4_set_item_k_O(    oarrm5n4_t* elm, uint64_t k,
                            feoarrm5n4_t* res);
  void feoarrm5n4_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm5n4_t* res);
  void feoarrm5n4_set_item_ijk_o( onumm5n4_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               feoarrm5n4_t* res);
  void feoarrm5n4_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n4_t* res);
  void feoarrm5n4_set_slice_o( onumm5n4_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n4_t* res);
  void feoarrm5n4_set_slice_f( feonumm5n4_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n4_t* res);
  void feoarrm5n4_set_slice_O( oarrm5n4_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n4_t* res);
  void feoarrm5n4_set_slice_F( feoarrm5n4_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            feoarrm5n4_t* res);
  void feoarrm5n4_set_all_o( onumm5n4_t* num, feoarrm5n4_t* arr );
  void feoarrm5n4_set_all_r(   coeff_t  num, feoarrm5n4_t* arr );
  void feoarrm5n4_set_all_f(  feonumm5n4_t* num, feoarrm5n4_t* arr );
  void feoarrm5n4_set_r(    coeff_t src, feoarrm5n4_t* res );
  void feoarrm5n4_set_o( onumm5n4_t* src, feoarrm5n4_t* res );
  void feoarrm5n4_set_f(  feonumm5n4_t* src, feoarrm5n4_t* res );
  void feoarrm5n4_set_R(    darr_t* src, feoarrm5n4_t* res );
  void feoarrm5n4_set_O(   oarrm5n4_t* src, feoarrm5n4_t* res );
  void feoarrm5n4_set_F( feoarrm5n4_t* src, feoarrm5n4_t* res );
  feoarrm5n4_t feoarrm5n4_eye( uint64_t size,  uint64_t nip);
  feoarrm5n4_t feoarrm5n4_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  feoarrm5n4_t feoarrm5n4_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  feoarrm5n4_t feoarrm5n4_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void feoarrm5n4_free(feoarrm5n4_t* arr);
  feoarrm5n4_t feoarrm5n4_init();
  ord_t feoarrm5n4_get_order(feoarrm5n4_t* arr);
  
  
  # From ../../../include/oti/static/onumm5n4/array/gauss/utils.h
  
  void feoarrm5n4_dimCheck_FF_samesize(feoarrm5n4_t* arr1, feoarrm5n4_t* arr2, feonumm5n4_t* res);
  void feoarrm5n4_dimCheck_OF_samesize(  oarrm5n4_t* arr1, feoarrm5n4_t* arr2, feonumm5n4_t* res);
  void feoarrm5n4_dimCheck_RF_samesize(   darr_t* arr1, feoarrm5n4_t* arr2, feonumm5n4_t* res);
  void feoarrm5n4_dimCheck_FF_elementwise(feoarrm5n4_t* arr1, feoarrm5n4_t* arr2, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_OF_elementwise(  oarrm5n4_t* arr1, feoarrm5n4_t* arr2, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm5n4_t* arr2, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_fF_elementwise( feonumm5n4_t* num1, feoarrm5n4_t* arr2, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_Ff_elementwise(feoarrm5n4_t* arr1,  feonumm5n4_t* num2, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_FF_matmul( feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_OF_matmul(   oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_RF_matmul(    darr_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_FO_matmul( feoarrm5n4_t* lhs,   oarrm5n4_t* rhs, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_FR_matmul( feoarrm5n4_t* lhs,    darr_t* rhs, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_F_squareness( feoarrm5n4_t* arr1, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_F_transpose( feoarrm5n4_t* arr1, feoarrm5n4_t* res);
  void feoarrm5n4_dimCheck_FfO_integrate(feoarrm5n4_t* arr, feonumm5n4_t* num,oarrm5n4_t* res);
  void feoarrm5n4_get_active_bases(feoarrm5n4_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/onumm5n4/array/gauss/algebra.h
  
  feoarrm5n4_t feoarrm5n4_neg(    feoarrm5n4_t* arr);
  void      feoarrm5n4_neg_to( feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sum_FF(   feoarrm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sum_FF_to(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sum_fF(    feonumm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sum_fF_to( feonumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sum_OF(     oarrm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sum_OF_to(  oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sum_RF(      darr_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sum_RF_to(   darr_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sum_oF(   onumm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sum_oF_to(onumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sum_rF(     coeff_t  lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sum_rF_to(  coeff_t  lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sub_FF(    feoarrm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sub_FF_to( feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sub_fF(    feonumm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sub_fF_to( feonumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sub_Ff(    feoarrm5n4_t* lhs, feonumm5n4_t* rhs);
  void      feoarrm5n4_sub_Ff_to( feoarrm5n4_t* lhs, feonumm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sub_OF(      oarrm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sub_OF_to(   oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sub_FO(    feoarrm5n4_t* lhs,   oarrm5n4_t* rhs);
  void      feoarrm5n4_sub_FO_to( feoarrm5n4_t* lhs,   oarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sub_RF(       darr_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sub_RF_to(    darr_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sub_FR(    feoarrm5n4_t* lhs,    darr_t* rhs);
  void      feoarrm5n4_sub_FR_to( feoarrm5n4_t* lhs,    darr_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sub_oF(    onumm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sub_oF_to( onumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sub_Fo(    feoarrm5n4_t* lhs, onumm5n4_t* rhs);
  void      feoarrm5n4_sub_Fo_to( feoarrm5n4_t* lhs, onumm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sub_rF(      coeff_t  lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_sub_rF_to(    coeff_t lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_sub_Fr(    feoarrm5n4_t* lhs,   coeff_t  rhs);
  void      feoarrm5n4_sub_Fr_to( feoarrm5n4_t* lhs,   coeff_t  rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_mul_FF(   feoarrm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_mul_FF_to(feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_mul_fF(    feonumm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_mul_fF_to( feonumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_mul_OF(     oarrm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_mul_OF_to(  oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_mul_RF(      darr_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_mul_RF_to(   darr_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_mul_oF(   onumm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_mul_oF_to(onumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_mul_rF(     coeff_t  lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_mul_rF_to(  coeff_t  lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_div_FF(    feoarrm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_div_FF_to( feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_div_fF(     feonumm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_div_fF_to(  feonumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_div_Ff(    feoarrm5n4_t* lhs,  feonumm5n4_t* rhs);
  void      feoarrm5n4_div_Ff_to( feoarrm5n4_t* lhs,  feonumm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_div_OF(      oarrm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_div_OF_to(   oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_div_FO(    feoarrm5n4_t* lhs,   oarrm5n4_t* rhs);
  void      feoarrm5n4_div_FO_to( feoarrm5n4_t* lhs,   oarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_div_RF(       darr_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_div_RF_to(    darr_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_div_FR(    feoarrm5n4_t* lhs,    darr_t* rhs);
  void      feoarrm5n4_div_FR_to( feoarrm5n4_t* lhs,    darr_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_div_oF(    onumm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_div_oF_to( onumm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_div_Fo(    feoarrm5n4_t* lhs, onumm5n4_t* rhs);
  void      feoarrm5n4_div_Fo_to( feoarrm5n4_t* lhs, onumm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_div_rF(      coeff_t  lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_div_rF_to(    coeff_t lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_div_Fr(    feoarrm5n4_t* lhs,   coeff_t  rhs);
  void      feoarrm5n4_div_Fr_to( feoarrm5n4_t* lhs,   coeff_t  rhs, feoarrm5n4_t* res);
  oarrm5n4_t feoarrm5n4_integrate(    feoarrm5n4_t* arr, feonumm5n4_t* w);
  void    feoarrm5n4_integrate_to( feoarrm5n4_t* arr, feonumm5n4_t* w, oarrm5n4_t* res);
  feonumm5n4_t feoarrm5n4_dotproduct_FF(    feoarrm5n4_t* lhs, feoarrm5n4_t* rhs);
  void     feoarrm5n4_dotproduct_FF_to( feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feoarrm5n4_dotproduct_OF(      oarrm5n4_t* lhs, feoarrm5n4_t* rhs);
  void     feoarrm5n4_dotproduct_OF_to(   oarrm5n4_t* lhs, feoarrm5n4_t* rhs, feonumm5n4_t* res);
  feonumm5n4_t feoarrm5n4_dotproduct_RF(       darr_t* lhs, feoarrm5n4_t* rhs);
  void     feoarrm5n4_dotproduct_RF_to(    darr_t* lhs, feoarrm5n4_t* rhs, feonumm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_matmul_FF(    feoarrm5n4_t* lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_matmul_FF_to( feoarrm5n4_t* lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_matmul_OF(    oarrm5n4_t*   lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_matmul_OF_to( oarrm5n4_t*   lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_matmul_FO(    feoarrm5n4_t* lhs, oarrm5n4_t*   rhs);
  void      feoarrm5n4_matmul_FO_to( feoarrm5n4_t* lhs, oarrm5n4_t*   rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_matmul_RF(    darr_t*    lhs, feoarrm5n4_t* rhs);
  void      feoarrm5n4_matmul_RF_to( darr_t*    lhs, feoarrm5n4_t* rhs, feoarrm5n4_t* res);
  feoarrm5n4_t feoarrm5n4_matmul_FR(    feoarrm5n4_t* lhs, darr_t*    rhs);
  void      feoarrm5n4_matmul_FR_to( feoarrm5n4_t* lhs, darr_t*    rhs, feoarrm5n4_t* res);
  feonumm5n4_t feoarrm5n4_det(   feoarrm5n4_t* arr);
  void     feoarrm5n4_det_to(feoarrm5n4_t* arr, feonumm5n4_t* res);
  feonumm5n4_t feoarrm5n4_norm(     feoarrm5n4_t* arr);
  void     feoarrm5n4_norm_to(  feoarrm5n4_t* arr, feonumm5n4_t* res);
  feonumm5n4_t feoarrm5n4_pnorm(    feoarrm5n4_t* arr, coeff_t p);
  void     feoarrm5n4_pnorm_to( feoarrm5n4_t* arr, coeff_t p, feonumm5n4_t* res);
  feoarrm5n4_t   feoarrm5n4_invert(    feoarrm5n4_t* arr);
  void        feoarrm5n4_invert_to( feoarrm5n4_t* arr, feoarrm5n4_t* res);
  feoarrm5n4_t   feoarrm5n4_transpose(   feoarrm5n4_t* arr);
  void        feoarrm5n4_transpose_to(feoarrm5n4_t* arr, feoarrm5n4_t* res);
  
  