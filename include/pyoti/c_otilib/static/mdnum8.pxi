cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/mdnum8/scalar/structures.h
  
  ctypedef struct  mdnum8_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
    coeff_t e6;
    coeff_t e7;
    coeff_t e8;
    coeff_t e12;
    coeff_t e13;
    coeff_t e23;
    coeff_t e14;
    coeff_t e24;
    coeff_t e34;
    coeff_t e15;
    coeff_t e25;
    coeff_t e35;
    coeff_t e45;
    coeff_t e16;
    coeff_t e26;
    coeff_t e36;
    coeff_t e46;
    coeff_t e56;
    coeff_t e17;
    coeff_t e27;
    coeff_t e37;
    coeff_t e47;
    coeff_t e57;
    coeff_t e67;
    coeff_t e18;
    coeff_t e28;
    coeff_t e38;
    coeff_t e48;
    coeff_t e58;
    coeff_t e68;
    coeff_t e78;
    coeff_t e123;
    coeff_t e124;
    coeff_t e134;
    coeff_t e234;
    coeff_t e125;
    coeff_t e135;
    coeff_t e235;
    coeff_t e145;
    coeff_t e245;
    coeff_t e345;
    coeff_t e126;
    coeff_t e136;
    coeff_t e236;
    coeff_t e146;
    coeff_t e246;
    coeff_t e346;
    coeff_t e156;
    coeff_t e256;
    coeff_t e356;
    coeff_t e456;
    coeff_t e127;
    coeff_t e137;
    coeff_t e237;
    coeff_t e147;
    coeff_t e247;
    coeff_t e347;
    coeff_t e157;
    coeff_t e257;
    coeff_t e357;
    coeff_t e457;
    coeff_t e167;
    coeff_t e267;
    coeff_t e367;
    coeff_t e467;
    coeff_t e567;
    coeff_t e128;
    coeff_t e138;
    coeff_t e238;
    coeff_t e148;
    coeff_t e248;
    coeff_t e348;
    coeff_t e158;
    coeff_t e258;
    coeff_t e358;
    coeff_t e458;
    coeff_t e168;
    coeff_t e268;
    coeff_t e368;
    coeff_t e468;
    coeff_t e568;
    coeff_t e178;
    coeff_t e278;
    coeff_t e378;
    coeff_t e478;
    coeff_t e578;
    coeff_t e678;
    coeff_t e1234;
    coeff_t e1235;
    coeff_t e1245;
    coeff_t e1345;
    coeff_t e2345;
    coeff_t e1236;
    coeff_t e1246;
    coeff_t e1346;
    coeff_t e2346;
    coeff_t e1256;
    coeff_t e1356;
    coeff_t e2356;
    coeff_t e1456;
    coeff_t e2456;
    coeff_t e3456;
    coeff_t e1237;
    coeff_t e1247;
    coeff_t e1347;
    coeff_t e2347;
    coeff_t e1257;
    coeff_t e1357;
    coeff_t e2357;
    coeff_t e1457;
    coeff_t e2457;
    coeff_t e3457;
    coeff_t e1267;
    coeff_t e1367;
    coeff_t e2367;
    coeff_t e1467;
    coeff_t e2467;
    coeff_t e3467;
    coeff_t e1567;
    coeff_t e2567;
    coeff_t e3567;
    coeff_t e4567;
    coeff_t e1238;
    coeff_t e1248;
    coeff_t e1348;
    coeff_t e2348;
    coeff_t e1258;
    coeff_t e1358;
    coeff_t e2358;
    coeff_t e1458;
    coeff_t e2458;
    coeff_t e3458;
    coeff_t e1268;
    coeff_t e1368;
    coeff_t e2368;
    coeff_t e1468;
    coeff_t e2468;
    coeff_t e3468;
    coeff_t e1568;
    coeff_t e2568;
    coeff_t e3568;
    coeff_t e4568;
    coeff_t e1278;
    coeff_t e1378;
    coeff_t e2378;
    coeff_t e1478;
    coeff_t e2478;
    coeff_t e3478;
    coeff_t e1578;
    coeff_t e2578;
    coeff_t e3578;
    coeff_t e4578;
    coeff_t e1678;
    coeff_t e2678;
    coeff_t e3678;
    coeff_t e4678;
    coeff_t e5678;
    coeff_t e12345;
    coeff_t e12346;
    coeff_t e12356;
    coeff_t e12456;
    coeff_t e13456;
    coeff_t e23456;
    coeff_t e12347;
    coeff_t e12357;
    coeff_t e12457;
    coeff_t e13457;
    coeff_t e23457;
    coeff_t e12367;
    coeff_t e12467;
    coeff_t e13467;
    coeff_t e23467;
    coeff_t e12567;
    coeff_t e13567;
    coeff_t e23567;
    coeff_t e14567;
    coeff_t e24567;
    coeff_t e34567;
    coeff_t e12348;
    coeff_t e12358;
    coeff_t e12458;
    coeff_t e13458;
    coeff_t e23458;
    coeff_t e12368;
    coeff_t e12468;
    coeff_t e13468;
    coeff_t e23468;
    coeff_t e12568;
    coeff_t e13568;
    coeff_t e23568;
    coeff_t e14568;
    coeff_t e24568;
    coeff_t e34568;
    coeff_t e12378;
    coeff_t e12478;
    coeff_t e13478;
    coeff_t e23478;
    coeff_t e12578;
    coeff_t e13578;
    coeff_t e23578;
    coeff_t e14578;
    coeff_t e24578;
    coeff_t e34578;
    coeff_t e12678;
    coeff_t e13678;
    coeff_t e23678;
    coeff_t e14678;
    coeff_t e24678;
    coeff_t e34678;
    coeff_t e15678;
    coeff_t e25678;
    coeff_t e35678;
    coeff_t e45678;
    coeff_t e123456;
    coeff_t e123457;
    coeff_t e123467;
    coeff_t e123567;
    coeff_t e124567;
    coeff_t e134567;
    coeff_t e234567;
    coeff_t e123458;
    coeff_t e123468;
    coeff_t e123568;
    coeff_t e124568;
    coeff_t e134568;
    coeff_t e234568;
    coeff_t e123478;
    coeff_t e123578;
    coeff_t e124578;
    coeff_t e134578;
    coeff_t e234578;
    coeff_t e123678;
    coeff_t e124678;
    coeff_t e134678;
    coeff_t e234678;
    coeff_t e125678;
    coeff_t e135678;
    coeff_t e235678;
    coeff_t e145678;
    coeff_t e245678;
    coeff_t e345678;
    coeff_t e1234567;
    coeff_t e1234568;
    coeff_t e1234578;
    coeff_t e1234678;
    coeff_t e1235678;
    coeff_t e1245678;
    coeff_t e1345678;
    coeff_t e2345678;
    coeff_t e12345678;
  # } mdnum8_t;
  
  
  # From ../../../include/oti/static/mdnum8/array/structures.h
  
  ctypedef struct  mdarr8_t : # {
      mdnum8_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } mdarr8_t;
  
  
  # From ../../../include/oti/static/mdnum8/scalar/gauss/structures.h
  
  ctypedef struct  femdnum8_t: # {
      mdnum8_t*  p_data;
      uint64_t    nip;
  # } femdnum8_t;
  
  
  # From ../../../include/oti/static/mdnum8/array/gauss/structures.h
  
  ctypedef struct  femdarr8_t: # {
      mdarr8_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } femdarr8_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/mdnum8/scalar/functions.h
  
  mdnum8_t mdnum8_atanh(mdnum8_t* num);
  void mdnum8_atanh_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_asinh(mdnum8_t* num);
  void mdnum8_asinh_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_acosh(mdnum8_t* num);
  void mdnum8_acosh_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_tanh(mdnum8_t* num);
  void mdnum8_tanh_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_sqrt(mdnum8_t* num);
  void mdnum8_sqrt_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_cbrt(mdnum8_t* num);
  void mdnum8_cbrt_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_cosh(mdnum8_t* num);
  void mdnum8_cosh_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_sinh(mdnum8_t* num);
  void mdnum8_sinh_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_asin(mdnum8_t* num);
  void mdnum8_asin_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_acos(mdnum8_t* num);
  void mdnum8_acos_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_atan(mdnum8_t* num);
  void mdnum8_atan_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_tan(mdnum8_t* num);
  void mdnum8_tan_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_cos(mdnum8_t* num);
  void mdnum8_cos_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_sin(mdnum8_t* num );
  void mdnum8_sin_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_logb(mdnum8_t* num, double base);
  void mdnum8_logb_to(mdnum8_t* num, double base, mdnum8_t* res);
  mdnum8_t mdnum8_log10(mdnum8_t* num);
  void mdnum8_log10_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_log(mdnum8_t* num);
  void mdnum8_log_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_exp(mdnum8_t* num);
  void mdnum8_exp_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_pow(mdnum8_t* num, double e);
  void mdnum8_pow_to(mdnum8_t* num, coeff_t e, mdnum8_t* res);
  
  
  # From ../../../include/oti/static/mdnum8/scalar/base.h
  
  void mdnum8_set_im_o(mdnum8_t* num, imdir_t idx, ord_t order, mdnum8_t* res);
  void mdnum8_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum8_t* res);
  void mdnum8_set_deriv_o(mdnum8_t* num, imdir_t idx, ord_t order, mdnum8_t* res);
  void mdnum8_extract_im_to( imdir_t idx, ord_t order, mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_extract_im(imdir_t idx, ord_t order, mdnum8_t* num);
  mdnum8_t mdnum8_extract_deriv(imdir_t idx, ord_t order, mdnum8_t* num);
  void mdnum8_extract_deriv_to(imdir_t idx, ord_t order, mdnum8_t* num, mdnum8_t* res);
  void mdnum8_get_im_to_o(imdir_t idx, ord_t order, mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_get_im_o(imdir_t idx, ord_t order, mdnum8_t* num);
  void mdnum8_get_im_to_r(imdir_t idx, ord_t order, mdnum8_t* num, coeff_t* res);
  ord_t mdnum8_get_order(mdnum8_t* lhs);
  mdnum8_t mdnum8_get_deriv_o( imdir_t idx, ord_t order, mdnum8_t* num);
  void mdnum8_get_deriv_to( imdir_t idx, ord_t order, mdnum8_t* num, mdnum8_t* res);
  void mdnum8_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum8_t* res);
  mdnum8_t mdnum8_init();
  ndir_t mdnum8_get_ndir_order(ord_t order, mdnum8_t* num);
  ndir_t mdnum8_get_ndir_total(mdnum8_t* num);
  coeff_t* mdnum8_get_order_address(ord_t order, mdnum8_t* num);
  mdnum8_t mdnum8_create_r(  coeff_t lhs);
  void mdnum8_set_r(  coeff_t lhs, mdnum8_t* res);
  void mdnum8_set_o(  mdnum8_t* lhs, mdnum8_t* res);
  mdnum8_t mdnum8_get_order_im(ord_t order, mdnum8_t* lhs);
  void mdnum8_get_order_im_to(ord_t order, mdnum8_t* lhs, mdnum8_t* res);
  coeff_t mdnum8_get_item(imdir_t idx, ord_t order, mdnum8_t* lhs);
  coeff_t mdnum8_get_deriv(imdir_t idx, ord_t order, mdnum8_t* lhs);
  void mdnum8_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum8_t* x);
  mdnum8_t mdnum8_copy(  mdnum8_t* lhs);
  void mdnum8_copy_to(  mdnum8_t* lhs, mdnum8_t* res);
  mdnum8_t mdnum8_taylor_integrate(coeff_t* deltas,mdnum8_t* lhs);
  void mdnum8_taylor_integrate_to(coeff_t* deltas,mdnum8_t* lhs, mdnum8_t* res);
  mdnum8_t mdnum8_truncate_im(imdir_t idx, ord_t order, mdnum8_t* lhs);
  void mdnum8_truncate_im_to(imdir_t idx, ord_t order, mdnum8_t* lhs, mdnum8_t* res);
  void mdnum8_print(  mdnum8_t* lhs);
  imdir_t mdnum8_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/mdnum8/scalar/utils.h
  
  void mdnum8_get_active_bases(mdnum8_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/mdnum8/scalar/algebra.h
  
  mdnum8_t mdnum8_abs(mdnum8_t* num);
  mdnum8_t mdnum8_div_ro(coeff_t num, mdnum8_t* den);
  mdnum8_t mdnum8_div_oo(mdnum8_t* num, mdnum8_t* den);
  mdnum8_t mdnum8_div_or(mdnum8_t* num, coeff_t val);
  void mdnum8_div_ro_to(coeff_t num, mdnum8_t* den, mdnum8_t* res);
  void mdnum8_div_oo_to(mdnum8_t* num, mdnum8_t* den, mdnum8_t* res);
  void mdnum8_div_or_to(mdnum8_t* num, coeff_t val, mdnum8_t* res);
  void mdnum8_abs_to(mdnum8_t* num, mdnum8_t* res);
  mdnum8_t mdnum8_neg(  mdnum8_t* lhs);
  void mdnum8_neg_to(  mdnum8_t* lhs, mdnum8_t* res);
  mdnum8_t mdnum8_sum_oo(  mdnum8_t* lhs,  mdnum8_t* rhs);
  void mdnum8_sum_oo_to(  mdnum8_t* lhs,  mdnum8_t* rhs, mdnum8_t* res);
  mdnum8_t mdnum8_sum_ro(  coeff_t lhs,  mdnum8_t* rhs);
  void mdnum8_sum_ro_to(  coeff_t lhs,  mdnum8_t* rhs, mdnum8_t* res);
  mdnum8_t mdnum8_sub_oo(  mdnum8_t* lhs,  mdnum8_t* rhs);
  void mdnum8_sub_oo_to(  mdnum8_t* lhs,  mdnum8_t* rhs, mdnum8_t* res);
  mdnum8_t mdnum8_sub_ro(  coeff_t lhs,  mdnum8_t* rhs);
  void mdnum8_sub_ro_to(  coeff_t lhs,  mdnum8_t* rhs, mdnum8_t* res);
  mdnum8_t mdnum8_sub_or(  mdnum8_t* lhs,  coeff_t rhs);
  void mdnum8_sub_or_to(  mdnum8_t* lhs,  coeff_t rhs, mdnum8_t* res);
  mdnum8_t mdnum8_mul_oo(  mdnum8_t* lhs,  mdnum8_t* rhs);
  void mdnum8_mul_oo_to(  mdnum8_t* lhs,  mdnum8_t* rhs, mdnum8_t* res);
  mdnum8_t mdnum8_mul_ro(  coeff_t lhs,  mdnum8_t* rhs);
  void mdnum8_mul_ro_to(  coeff_t lhs,  mdnum8_t* rhs, mdnum8_t* res);
  mdnum8_t mdnum8_trunc_mul_oo(  mdnum8_t* lhs,  mdnum8_t* rhs);
  void mdnum8_trunc_mul_oo_to(  mdnum8_t* lhs,  mdnum8_t* rhs, mdnum8_t* res);
  mdnum8_t mdnum8_gem_oo(  mdnum8_t* a,  mdnum8_t* b,  mdnum8_t* c);
  void mdnum8_gem_oo_to(  mdnum8_t* a,  mdnum8_t* b,  mdnum8_t* c, mdnum8_t* res);
  mdnum8_t mdnum8_gem_ro(  coeff_t a,  mdnum8_t* b,  mdnum8_t* c);
  void mdnum8_gem_ro_to(  coeff_t a,  mdnum8_t* b,  mdnum8_t* c, mdnum8_t* res);
  void mdnum8_trunc_gem_oo_to( ord_t ord_lhs,  mdnum8_t* a,  ord_t ord_rhs,  mdnum8_t* b,  mdnum8_t* c, mdnum8_t* res);
  void mdnum8_trunc_sum_oo_to(ord_t order, mdnum8_t* lhs,mdnum8_t* rhs, mdnum8_t* res);
  void mdnum8_trunc_sub_oo_to(ord_t order, mdnum8_t* lhs,mdnum8_t* rhs, mdnum8_t* res);
  mdnum8_t mdnum8_feval(coeff_t* feval_re, mdnum8_t* x);
  void mdnum8_feval_to(coeff_t* feval_re, mdnum8_t* x, mdnum8_t* res);
  
  
  # From ../../../include/oti/static/mdnum8/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum8/scalar/gauss/functions.h
  
  femdnum8_t femdnum8_atanh(    femdnum8_t* num);
  void     femdnum8_atanh_to( femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_asinh(    femdnum8_t* num);
  void     femdnum8_asinh_to( femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_acosh(    femdnum8_t* num);
  void     femdnum8_acosh_to( femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_tanh(     femdnum8_t* num);
  void     femdnum8_tanh_to(  femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_cosh(     femdnum8_t* num);
  void     femdnum8_cosh_to(  femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_sinh(     femdnum8_t* num);
  void     femdnum8_sinh_to(  femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_asin(     femdnum8_t* num);
  void     femdnum8_asin_to(  femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_acos(     femdnum8_t* num);
  void     femdnum8_acos_to(  femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_atan(     femdnum8_t* num);
  void     femdnum8_atan_to(  femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_tan(      femdnum8_t* num);
  void     femdnum8_tan_to(   femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_cos(      femdnum8_t* num);
  void     femdnum8_cos_to(   femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_sin(      femdnum8_t* num);
  void     femdnum8_sin_to(   femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_logb(     femdnum8_t* num, double base);
  void     femdnum8_logb_to(  femdnum8_t* num, double base, femdnum8_t* res);
  femdnum8_t femdnum8_log10(    femdnum8_t* num);
  void     femdnum8_log10_to( femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_log(      femdnum8_t* num);
  void     femdnum8_log_to(   femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_exp(      femdnum8_t* num);
  void     femdnum8_exp_to(   femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_cbrt(     femdnum8_t* num);
  void     femdnum8_cbrt_to(  femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_sqrt(     femdnum8_t* num);
  void     femdnum8_sqrt_to(  femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_pow(      femdnum8_t* num, double e);
  void     femdnum8_pow_to(   femdnum8_t* num, double e, femdnum8_t* res);
  mdnum8_t femdnum8_integrate(       femdnum8_t* num, femdnum8_t* w);
  void      femdnum8_integrate_to(    femdnum8_t* num, femdnum8_t* w, mdnum8_t* res);
  mdnum8_t femdnum8_integrate_f(     femdnum8_t* num, femdnum8_t* w);
  void      femdnum8_integrate_f_to(  femdnum8_t* num, femdnum8_t* w, mdnum8_t* res);
  mdnum8_t femdnum8_integrate_r(       coeff_t num, femdnum8_t* w);
  void      femdnum8_integrate_r_to(    coeff_t num, femdnum8_t* w, mdnum8_t* res);
  mdnum8_t femdnum8_integrate_o(    mdnum8_t* num, femdnum8_t* w);
  void      femdnum8_integrate_o_to( mdnum8_t* num, femdnum8_t* w, mdnum8_t* res);
  
  
  # From ../../../include/oti/static/mdnum8/scalar/gauss/base.h
  
  void     femdnum8_get_order_im_to( ord_t order, femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_get_order_im(    ord_t order, femdnum8_t* num);
  femdnum8_t femdnum8_get_im(    imdir_t idx, ord_t order, femdnum8_t* num);
  void     femdnum8_get_im_to( imdir_t idx, ord_t order, femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_get_deriv(    imdir_t idx, ord_t order, femdnum8_t* num);
  void     femdnum8_get_deriv_to( imdir_t idx, ord_t order, femdnum8_t* num, femdnum8_t* res);
  void femdnum8_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum8_t* num);
  void femdnum8_set_im_o( mdnum8_t* val, imdir_t idx, ord_t order, femdnum8_t* num);
  void femdnum8_set_im_f(  femdnum8_t* val, imdir_t idx, ord_t order, femdnum8_t* num);
  void femdnum8_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum8_t* num);
  void femdnum8_set_deriv_o( mdnum8_t* val, imdir_t idx, ord_t order, femdnum8_t* num);
  void femdnum8_set_deriv_f(  femdnum8_t* val, imdir_t idx, ord_t order, femdnum8_t* num);
  femdnum8_t femdnum8_extract_im(    imdir_t idx, ord_t order, femdnum8_t* num);
  void     femdnum8_extract_im_to( imdir_t idx, ord_t order, femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_extract_deriv(    imdir_t idx, ord_t order, femdnum8_t* num);
  void     femdnum8_extract_deriv_to( imdir_t idx, ord_t order, femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_truncate_im(    imdir_t idx, ord_t order, femdnum8_t* num);
  void     femdnum8_truncate_im_to( imdir_t idx, ord_t order, femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_copy(    femdnum8_t* src);
  void     femdnum8_copy_to( femdnum8_t* src, femdnum8_t* dst);
  void femdnum8_set_r(    coeff_t num, femdnum8_t* res);
  void femdnum8_set_o( mdnum8_t* num, femdnum8_t* res);
  void femdnum8_set_f(  femdnum8_t* num, femdnum8_t* res);
  void femdnum8_set_item_k_r(   coeff_t  num, uint64_t k, femdnum8_t* res);
  void femdnum8_set_item_k_o( mdnum8_t* num, uint64_t k, femdnum8_t* res);
  mdnum8_t femdnum8_get_item_k(   femdnum8_t* num, uint64_t k);
  void      femdnum8_get_item_k_to(femdnum8_t* num, uint64_t k, mdnum8_t* res);
  femdnum8_t femdnum8_zeros(uint64_t nIntPts);
  femdnum8_t femdnum8_createEmpty(uint64_t nIntPts);
  femdnum8_t femdnum8_empty_like(femdnum8_t* arr);
  void femdnum8_free(femdnum8_t* num);
  ord_t femdnum8_get_order( femdnum8_t* num );
  femdnum8_t femdnum8_init();
  
  
  # From ../../../include/oti/static/mdnum8/scalar/gauss/utils.h
  
  void femdnum8_dimCheck(femdnum8_t* arr1,femdnum8_t* arr2);
  void femdnum8_get_active_bases(femdnum8_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum8/scalar/gauss/algebra.h
  
  femdnum8_t femdnum8_neg(   femdnum8_t* num);
  void     femdnum8_neg_to(femdnum8_t* num, femdnum8_t* res);
  femdnum8_t femdnum8_sum_ff(   femdnum8_t* lhs, femdnum8_t* rhs);
  void     femdnum8_sum_ff_to(femdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_sum_of(   mdnum8_t* lhs, femdnum8_t* rhs);
  void     femdnum8_sum_of_to(mdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_sum_rf(   coeff_t lhs, femdnum8_t* rhs);
  void     femdnum8_sum_rf_to(coeff_t lhs, femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_sub_ff(     femdnum8_t* lhs,  femdnum8_t* rhs);
  void     femdnum8_sub_ff_to(  femdnum8_t* lhs,  femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_sub_of(    mdnum8_t* lhs,  femdnum8_t* rhs);
  void     femdnum8_sub_of_to( mdnum8_t* lhs,  femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_sub_fo(     femdnum8_t* lhs, mdnum8_t* rhs);
  void     femdnum8_sub_fo_to(  femdnum8_t* lhs, mdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_sub_rf(       coeff_t lhs,  femdnum8_t* rhs);
  void     femdnum8_sub_rf_to(    coeff_t lhs,  femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_sub_fr(     femdnum8_t* lhs,    coeff_t rhs);
  void     femdnum8_sub_fr_to(  femdnum8_t* lhs,    coeff_t rhs, femdnum8_t* res);
  femdnum8_t femdnum8_mul_ff(   femdnum8_t* lhs, femdnum8_t* rhs);
  void     femdnum8_mul_ff_to(femdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_mul_of(   mdnum8_t* lhs, femdnum8_t* rhs);
  void     femdnum8_mul_of_to(mdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_mul_rf(   coeff_t lhs, femdnum8_t* rhs);
  void     femdnum8_mul_rf_to(coeff_t lhs, femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_div_ff(     femdnum8_t* lhs,  femdnum8_t* rhs);
  void     femdnum8_div_ff_to(  femdnum8_t* lhs,  femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_div_of(    mdnum8_t* lhs,  femdnum8_t* rhs);
  void     femdnum8_div_of_to( mdnum8_t* lhs,  femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_div_fo(     femdnum8_t* lhs, mdnum8_t* rhs);
  void     femdnum8_div_fo_to(  femdnum8_t* lhs, mdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_div_rf(       coeff_t lhs,  femdnum8_t* rhs);
  void     femdnum8_div_rf_to(    coeff_t lhs,  femdnum8_t* rhs, femdnum8_t* res);
  femdnum8_t femdnum8_div_fr(     femdnum8_t* lhs,    coeff_t rhs);
  void     femdnum8_div_fr_to(  femdnum8_t* lhs,    coeff_t rhs, femdnum8_t* res);
  
  
  # From ../../../include/oti/static/mdnum8/array/functions.h
  
  mdarr8_t mdarr8_atanh(   mdarr8_t* arr);
  void    mdarr8_atanh_to(mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_asinh(   mdarr8_t* arr);
  void    mdarr8_asinh_to(mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_acosh(   mdarr8_t* arr);
  void    mdarr8_acosh_to(mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_tanh(    mdarr8_t* arr);
  void    mdarr8_tanh_to( mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_cbrt(    mdarr8_t* arr);
  void    mdarr8_cbrt_to( mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_sqrt(    mdarr8_t* arr);
  void    mdarr8_sqrt_to( mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_cosh(    mdarr8_t* arr);
  void    mdarr8_cosh_to( mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_sinh(    mdarr8_t* arr);
  void    mdarr8_sinh_to( mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_asin(    mdarr8_t* arr);
  void    mdarr8_asin_to( mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_acos(    mdarr8_t* arr);
  void    mdarr8_acos_to( mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_atan(    mdarr8_t* arr);
  void    mdarr8_atan_to( mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_tan(     mdarr8_t* arr);
  void    mdarr8_tan_to(  mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_cos(     mdarr8_t* arr);
  void    mdarr8_cos_to(  mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_sin(     mdarr8_t* arr);
  void    mdarr8_sin_to(  mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_logb(    mdarr8_t* arr, double base);
  void    mdarr8_logb_to( mdarr8_t* arr, double base, mdarr8_t* res);
  mdarr8_t mdarr8_log10(   mdarr8_t* arr);
  void    mdarr8_log10_to(mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_log(     mdarr8_t* arr);
  void    mdarr8_log_to(  mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_exp(     mdarr8_t* arr);
  void    mdarr8_exp_to(  mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_pow(     mdarr8_t* arr, double e);
  void    mdarr8_pow_to(  mdarr8_t* arr, double e, mdarr8_t* res);
  
  
  # From ../../../include/oti/static/mdnum8/array/algebra_elementwise.h
  
  mdarr8_t mdarr8_neg(mdarr8_t* arr);
  void mdarr8_neg_to(mdarr8_t* rhs, mdarr8_t* res);
  mdarr8_t mdarr8_sum_OO(mdarr8_t*   lhs, mdarr8_t* rhs);
  mdarr8_t mdarr8_sum_RO(darr_t*    lhs, mdarr8_t* rhs);
  mdarr8_t mdarr8_sum_oO(mdnum8_t* lhs, mdarr8_t* rhs);
  mdarr8_t mdarr8_sum_rO(coeff_t    lhs, mdarr8_t* rhs);
  void mdarr8_sum_OO_to(mdarr8_t*   lhs, mdarr8_t* rhs, mdarr8_t* res);
  void mdarr8_sum_RO_to(darr_t*    lhs, mdarr8_t* rhs, mdarr8_t* res);
  void mdarr8_sum_oO_to(mdnum8_t* lhs, mdarr8_t* rhs, mdarr8_t* res);
  void mdarr8_sum_rO_to(coeff_t    lhs, mdarr8_t* rhs, mdarr8_t* res);
  void mdarr8_trunc_sum_OO_to(ord_t order, mdarr8_t* arr1, mdarr8_t* arr2, mdarr8_t* res);
  mdarr8_t mdarr8_sub_OO(mdarr8_t*   lhs, mdarr8_t*   rhs);
  mdarr8_t mdarr8_sub_RO(darr_t*    lhs, mdarr8_t*   rhs);
  mdarr8_t mdarr8_sub_OR(mdarr8_t*   lhs, darr_t*    rhs);
  mdarr8_t mdarr8_sub_oO(mdnum8_t* lhs, mdarr8_t*   rhs);
  mdarr8_t mdarr8_sub_Oo(mdarr8_t*   lhs, mdnum8_t* rhs);
  mdarr8_t mdarr8_sub_rO(coeff_t    lhs, mdarr8_t*   rhs);
  mdarr8_t mdarr8_sub_Or(mdarr8_t*   lhs, coeff_t    rhs);
  void mdarr8_sub_OO_to( mdarr8_t*   lhs, mdarr8_t*   rhs, mdarr8_t* res);
  void mdarr8_sub_RO_to( darr_t*    lhs, mdarr8_t*   rhs, mdarr8_t* res);
  void mdarr8_sub_OR_to( mdarr8_t*   lhs, darr_t*    rhs, mdarr8_t* res);
  void mdarr8_sub_oO_to( mdnum8_t* lhs, mdarr8_t*   rhs, mdarr8_t* res);
  void mdarr8_sub_Oo_to( mdarr8_t*   lhs, mdnum8_t* rhs, mdarr8_t* res);
  void mdarr8_sub_rO_to( coeff_t    lhs, mdarr8_t*   rhs, mdarr8_t* res);
  void mdarr8_sub_Or_to( mdarr8_t*   lhs, coeff_t    rhs, mdarr8_t* res);
  void mdarr8_trunc_sub_OO_to(ord_t order, mdarr8_t* arr1, mdarr8_t* arr2, mdarr8_t* res);
  mdarr8_t mdarr8_mul_OO(mdarr8_t*   lhs, mdarr8_t* rhs);
  mdarr8_t mdarr8_mul_RO(darr_t*    lhs, mdarr8_t* rhs);
  mdarr8_t mdarr8_mul_oO(mdnum8_t* lhs, mdarr8_t* rhs);
  mdarr8_t mdarr8_mul_rO(coeff_t    lhs, mdarr8_t* rhs);
  void mdarr8_mul_OO_to(mdarr8_t*   lhs, mdarr8_t* rhs, mdarr8_t* res);
  void mdarr8_mul_RO_to(darr_t*    lhs, mdarr8_t* rhs, mdarr8_t* res);
  void mdarr8_mul_oO_to(mdnum8_t* lhs, mdarr8_t* rhs, mdarr8_t* res);
  void mdarr8_mul_rO_to(coeff_t    lhs, mdarr8_t* rhs, mdarr8_t* res);
  void mdarr8_gem_OO_to(  mdarr8_t* arr1, mdarr8_t* arr2, mdarr8_t* arr3, mdarr8_t* res);
  void mdarr8_gem_oO_to(mdnum8_t* arr1, mdarr8_t* arr2, mdarr8_t* arr3, mdarr8_t* res);
  mdarr8_t mdarr8_div_OO(mdarr8_t*   lhs, mdarr8_t*   rhs);
  mdarr8_t mdarr8_div_OR(mdarr8_t*   lhs, darr_t*    rhs);
  mdarr8_t mdarr8_div_RO(darr_t*    lhs, mdarr8_t*   rhs);
  mdarr8_t mdarr8_div_oO(mdnum8_t* lhs, mdarr8_t*   rhs);
  mdarr8_t mdarr8_div_Oo(mdarr8_t*   lhs, mdnum8_t* rhs);
  mdarr8_t mdarr8_div_rO(coeff_t    lhs, mdarr8_t*   rhs);
  mdarr8_t mdarr8_div_Or(mdarr8_t*   lhs, coeff_t    rhs);
  void mdarr8_div_OO_to(mdarr8_t*   lhs, mdarr8_t*   rhs, mdarr8_t* res);
  void mdarr8_div_RO_to(darr_t*    lhs, mdarr8_t*   rhs, mdarr8_t* res);
  void mdarr8_div_OR_to(mdarr8_t*   lhs, darr_t*    rhs, mdarr8_t* res);
  void mdarr8_div_oO_to(mdnum8_t* lhs, mdarr8_t*   rhs, mdarr8_t* res);
  void mdarr8_div_Oo_to(mdarr8_t*   lhs, mdnum8_t* rhs, mdarr8_t* res);
  void mdarr8_div_rO_to(coeff_t    lhs, mdarr8_t*   rhs, mdarr8_t* res);
  void mdarr8_div_Or_to(mdarr8_t*   lhs, coeff_t    rhs, mdarr8_t* res);
  
  
  # From ../../../include/oti/static/mdnum8/array/base.h
  
  void    mdarr8_taylor_integrate_to( coeff_t* deltas, mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_taylor_integrate(    coeff_t* deltas, mdarr8_t* arr);
  void    mdarr8_get_order_im_to( ord_t order, mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_get_order_im(    ord_t order, mdarr8_t* arr);
  void mdarr8_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr8_t* res);
  void mdarr8_set_slice_O( mdarr8_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr8_t* res);
  void mdarr8_set_slice_o( mdnum8_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr8_t* res);
  mdarr8_t mdarr8_get_slice( mdarr8_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void mdarr8_get_slice_to( mdarr8_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr8_t* res);
  mdarr8_t mdarr8_truncate_im(    imdir_t idx, ord_t order, mdarr8_t* arr);
  void    mdarr8_truncate_im_to( imdir_t idx, ord_t order, mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_extract_im(   imdir_t idx, ord_t order, mdarr8_t* arr);
  void    mdarr8_extract_im_to(imdir_t idx, ord_t order, mdarr8_t* arr, mdarr8_t* res);
  darr_t  mdarr8_get_deriv(    imdir_t idx, ord_t order, mdarr8_t* arr);
  void    mdarr8_get_deriv_to( imdir_t idx, ord_t order, mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_get_deriv_o(  imdir_t idx, ord_t order, mdarr8_t* arr);
  mdarr8_t mdarr8_extract_deriv(    imdir_t idx, ord_t order, mdarr8_t* arr);
  void    mdarr8_extract_deriv_to( imdir_t idx, ord_t order, mdarr8_t* arr, mdarr8_t* res);
  darr_t  mdarr8_get_im(   imdir_t idx, ord_t order, mdarr8_t* arr);
  mdarr8_t mdarr8_get_im_o( imdir_t idx, ord_t order, mdarr8_t* arr);
  void    mdarr8_get_im_to(imdir_t idx, ord_t order, mdarr8_t* arr, mdarr8_t* res);
  void    mdarr8_copy_to(mdarr8_t* arr, mdarr8_t* res);
  mdarr8_t mdarr8_copy(mdarr8_t* arr);
  void mdarr8_set_all_r( coeff_t num, mdarr8_t* arr);
  void mdarr8_set_item_i_r( coeff_t num, uint64_t i, mdarr8_t* arr);
  void mdarr8_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, mdarr8_t* arr);
  void mdarr8_set_r(   coeff_t  num,   mdarr8_t* arr);
  void mdarr8_set_o( mdnum8_t* num,   mdarr8_t* arr);
  void mdarr8_set_O(   mdarr8_t* arrin, mdarr8_t* arr);
  void mdarr8_set_all_o( mdnum8_t* src, mdarr8_t* arr);
  void mdarr8_set_item_i_o( mdnum8_t* num, uint64_t i, mdarr8_t* arr);
  void mdarr8_set_item_ij_o( mdnum8_t* num, uint64_t i, uint64_t j, mdarr8_t* arr);
  mdnum8_t mdarr8_get_item_i(    mdarr8_t* arr, uint64_t i);
  void      mdarr8_get_item_i_to( mdarr8_t* arr, uint64_t i,             mdnum8_t* res);
  mdnum8_t mdarr8_get_item_ij(   mdarr8_t* arr, uint64_t i, uint64_t j);
  void      mdarr8_get_item_ij_to(mdarr8_t* arr, uint64_t i, uint64_t j, mdnum8_t* res);
  mdarr8_t mdarr8_init();
  void mdarr8_free(mdarr8_t* arr);
  mdarr8_t mdarr8_empty_like(mdarr8_t* arr);
  mdarr8_t mdarr8_eye(uint64_t nrows);
  mdarr8_t mdarr8_ones(uint64_t nrows, uint64_t ncols);
  mdarr8_t mdarr8_zeros(uint64_t nrows, uint64_t ncols);
  mdarr8_t mdarr8_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/mdnum8/array/utils.h
  
  void mdarr8_dimCheck_OO_elementwise(mdarr8_t* arr1, mdarr8_t* arr2, mdarr8_t* res);
  void mdarr8_dimCheck_RO_elementwise(darr_t*  arr1, mdarr8_t* arr2, mdarr8_t* res);
  void mdarr8_dimCheck_OO_matmul(mdarr8_t* arr1, mdarr8_t* arr2, mdarr8_t* res);
  void mdarr8_dimCheck_RO_matmul(darr_t*  arr1, mdarr8_t* arr2, mdarr8_t* res);
  void mdarr8_dimCheck_OR_matmul(mdarr8_t* arr1, darr_t*  arr2, mdarr8_t* res);
  void mdarr8_dimCheck_O_squareness(mdarr8_t* arr1, mdarr8_t* res);
  void mdarr8_dimCheck_OO_samesize(mdarr8_t* arr1, mdarr8_t* res);
  void mdarr8_dimCheck_RO_samesize(darr_t* arr1, mdarr8_t* res);
  ord_t mdarr8_get_order(mdarr8_t* arr);
  void mdarr8_get_active_bases(mdarr8_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum8/array/algebra_matops.h
  
  mdnum8_t mdarr8_dotproduct_OO(    mdarr8_t* lhs, mdarr8_t* rhs);
  void      mdarr8_dotproduct_OO_to( mdarr8_t* lhs, mdarr8_t* rhs, mdnum8_t* res);
  mdnum8_t mdarr8_dotproduct_RO(     darr_t* lhs, mdarr8_t* rhs);
  void      mdarr8_dotproduct_RO_to(  darr_t* lhs, mdarr8_t* rhs, mdnum8_t* res);
  mdarr8_t mdarr8_matmul_OO(    mdarr8_t* lhs, mdarr8_t* rhs);
  mdarr8_t mdarr8_matmul_OR(    mdarr8_t* lhs,  darr_t* rhs);
  mdarr8_t mdarr8_matmul_RO(     darr_t* lhs, mdarr8_t* rhs);
  void    mdarr8_matmul_OO_to( mdarr8_t* lhs, mdarr8_t* rhs, mdarr8_t* res);
  void    mdarr8_matmul_OR_to( mdarr8_t* lhs,  darr_t* rhs, mdarr8_t* res);
  void    mdarr8_matmul_RO_to(  darr_t* lhs, mdarr8_t* rhs, mdarr8_t* res);
  mdarr8_t mdarr8_transpose(    mdarr8_t* arr1);
  void    mdarr8_transpose_to( mdarr8_t* arr1, mdarr8_t* res);
  mdarr8_t mdarr8_invert(    mdarr8_t* arr1);
  void    mdarr8_invert_to( mdarr8_t* arr1, mdarr8_t* res);
  mdnum8_t mdarr8_det(    mdarr8_t* arr1);
  void      mdarr8_det_to( mdarr8_t* arr1, mdnum8_t* res);
  mdnum8_t mdarr8_norm(    mdarr8_t* arr1);
  void      mdarr8_norm_to( mdarr8_t* arr1,  mdnum8_t* res);
  mdnum8_t mdarr8_pnorm(    mdarr8_t* arr1, coeff_t p);
  void      mdarr8_pnorm_to( mdarr8_t* arr1, coeff_t p, mdnum8_t* res);
  
  
  # From ../../../include/oti/static/mdnum8/array/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum8/array/gauss/functions.h
  
  femdarr8_t femdarr8_atanh(    femdarr8_t* arr);
  void      femdarr8_atanh_to( femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_asinh(    femdarr8_t* arr);
  void      femdarr8_asinh_to( femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_acosh(    femdarr8_t* arr);
  void      femdarr8_acosh_to( femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_tanh(     femdarr8_t* arr);
  void      femdarr8_tanh_to(  femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_sinh(     femdarr8_t* arr);
  void      femdarr8_sinh_to(  femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_cosh(     femdarr8_t* arr);
  void      femdarr8_cosh_to(  femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_atan(     femdarr8_t* arr);
  void      femdarr8_atan_to(  femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_asin(     femdarr8_t* arr);
  void      femdarr8_asin_to(  femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_acos(     femdarr8_t* arr);
  void      femdarr8_acos_to(  femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_tan(      femdarr8_t* arr);
  void      femdarr8_tan_to(   femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_sin(      femdarr8_t* arr);
  void      femdarr8_sin_to(   femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_cos(      femdarr8_t* arr);
  void      femdarr8_cos_to(   femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_logb(     femdarr8_t* arr, double base);
  void      femdarr8_logb_to(  femdarr8_t* arr, double base, femdarr8_t* res);
  femdarr8_t femdarr8_log10(    femdarr8_t* arr);
  void      femdarr8_log10_to( femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_log(      femdarr8_t* arr);
  void      femdarr8_log_to(   femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_exp(      femdarr8_t* arr);
  void      femdarr8_exp_to(   femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_cbrt(     femdarr8_t* arr);
  void      femdarr8_cbrt_to(  femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_sqrt(     femdarr8_t* arr);
  void      femdarr8_sqrt_to(  femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_pow(      femdarr8_t* arr, double e);
  void      femdarr8_pow_to(   femdarr8_t* arr, double e, femdarr8_t* res);
  
  
  # From ../../../include/oti/static/mdnum8/array/gauss/base.h
  
  void      femdarr8_get_order_im_to( ord_t order, femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_get_order_im(    ord_t order, femdarr8_t* arr);
  femdarr8_t femdarr8_get_deriv(   imdir_t idx, ord_t order, femdarr8_t* arr);
  void      femdarr8_get_deriv_to(imdir_t idx, ord_t order, femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_get_im(      imdir_t idx, ord_t order, femdarr8_t* arr);
  void      femdarr8_get_im_to(   imdir_t idx, ord_t order, femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_truncate_im(   imdir_t idx, ord_t order, femdarr8_t* arr);
  void      femdarr8_truncate_im_to(imdir_t idx, ord_t order, femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_copy(   femdarr8_t* src);
  void      femdarr8_copy_to(femdarr8_t* src, femdarr8_t* res);
  femdarr8_t femdarr8_get_im(    imdir_t idx, ord_t order, femdarr8_t* arr);
  void      femdarr8_get_im_to( imdir_t idx, ord_t order, femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_get_deriv(    imdir_t idx, ord_t order, femdarr8_t* arr);
  void      femdarr8_get_deriv_to( imdir_t idx, ord_t order, femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_extract_im(    imdir_t idx, ord_t order, femdarr8_t* arr);
  void      femdarr8_extract_im_to( imdir_t idx, ord_t order, femdarr8_t* arr,  femdarr8_t* res);
  femdarr8_t femdarr8_extract_deriv(    imdir_t idx, ord_t order, femdarr8_t* arr);
  void      femdarr8_extract_deriv_to( imdir_t idx, ord_t order, femdarr8_t* arr, femdarr8_t* res);
  mdarr8_t   femdarr8_get_item_k(  femdarr8_t* arr, uint64_t k);
  femdnum8_t  femdarr8_get_item_ij( femdarr8_t* arr, uint64_t i, uint64_t j);
  mdnum8_t femdarr8_get_item_ijk(femdarr8_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void femdarr8_get_item_ij_to(  femdarr8_t* arr, uint64_t i, uint64_t j,
                                 femdnum8_t* res);
  void femdarr8_get_item_k_to(   femdarr8_t* arr, uint64_t k,
                                  mdarr8_t* res);
  void femdarr8_get_item_ijk_to( femdarr8_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                mdnum8_t* res);
  femdarr8_t femdarr8_get_slice(femdarr8_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      femdarr8_get_slice_to(femdarr8_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr8_t* res);
  void femdarr8_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              femdarr8_t* res);
  void femdarr8_set_item_ij_o(  mdnum8_t* elm, uint64_t i, uint64_t j,
                               femdarr8_t* res);
  void femdarr8_set_item_ij_f(  femdnum8_t* elm, uint64_t i, uint64_t j,
                              femdarr8_t* res);
  void femdarr8_set_item_k_r(    coeff_t  elm, uint64_t k,
                              femdarr8_t* res);
  void femdarr8_set_item_k_o(  mdnum8_t* elm, uint64_t k,
                              femdarr8_t* res);
  void femdarr8_set_item_k_R(    mdarr8_t* elm, uint64_t k,
                            femdarr8_t* res);
  void femdarr8_set_item_k_O(    mdarr8_t* elm, uint64_t k,
                            femdarr8_t* res);
  void femdarr8_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr8_t* res);
  void femdarr8_set_item_ijk_o( mdnum8_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr8_t* res);
  void femdarr8_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr8_t* res);
  void femdarr8_set_slice_o( mdnum8_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr8_t* res);
  void femdarr8_set_slice_f( femdnum8_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr8_t* res);
  void femdarr8_set_slice_O( mdarr8_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr8_t* res);
  void femdarr8_set_slice_F( femdarr8_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr8_t* res);
  void femdarr8_set_all_o( mdnum8_t* num, femdarr8_t* arr );
  void femdarr8_set_all_r(   coeff_t  num, femdarr8_t* arr );
  void femdarr8_set_all_f(  femdnum8_t* num, femdarr8_t* arr );
  void femdarr8_set_r(    coeff_t src, femdarr8_t* res );
  void femdarr8_set_o( mdnum8_t* src, femdarr8_t* res );
  void femdarr8_set_f(  femdnum8_t* src, femdarr8_t* res );
  void femdarr8_set_R(    darr_t* src, femdarr8_t* res );
  void femdarr8_set_O(   mdarr8_t* src, femdarr8_t* res );
  void femdarr8_set_F( femdarr8_t* src, femdarr8_t* res );
  femdarr8_t femdarr8_eye( uint64_t size,  uint64_t nip);
  femdarr8_t femdarr8_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  femdarr8_t femdarr8_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  femdarr8_t femdarr8_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void femdarr8_free(femdarr8_t* arr);
  femdarr8_t femdarr8_init();
  ord_t femdarr8_get_order(femdarr8_t* arr);
  
  
  # From ../../../include/oti/static/mdnum8/array/gauss/utils.h
  
  void femdarr8_dimCheck_FF_samesize(femdarr8_t* arr1, femdarr8_t* arr2, femdnum8_t* res);
  void femdarr8_dimCheck_OF_samesize(  mdarr8_t* arr1, femdarr8_t* arr2, femdnum8_t* res);
  void femdarr8_dimCheck_RF_samesize(   darr_t* arr1, femdarr8_t* arr2, femdnum8_t* res);
  void femdarr8_dimCheck_FF_elementwise(femdarr8_t* arr1, femdarr8_t* arr2, femdarr8_t* res);
  void femdarr8_dimCheck_OF_elementwise(  mdarr8_t* arr1, femdarr8_t* arr2, femdarr8_t* res);
  void femdarr8_dimCheck_RF_elementwise(   darr_t* arr1, femdarr8_t* arr2, femdarr8_t* res);
  void femdarr8_dimCheck_fF_elementwise( femdnum8_t* num1, femdarr8_t* arr2, femdarr8_t* res);
  void femdarr8_dimCheck_Ff_elementwise(femdarr8_t* arr1,  femdnum8_t* num2, femdarr8_t* res);
  void femdarr8_dimCheck_FF_matmul( femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  void femdarr8_dimCheck_OF_matmul(   mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  void femdarr8_dimCheck_RF_matmul(    darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  void femdarr8_dimCheck_FO_matmul( femdarr8_t* lhs,   mdarr8_t* rhs, femdarr8_t* res);
  void femdarr8_dimCheck_FR_matmul( femdarr8_t* lhs,    darr_t* rhs, femdarr8_t* res);
  void femdarr8_dimCheck_F_squareness( femdarr8_t* arr1, femdarr8_t* res);
  void femdarr8_dimCheck_F_transpose( femdarr8_t* arr1, femdarr8_t* res);
  void femdarr8_dimCheck_FfO_integrate(femdarr8_t* arr, femdnum8_t* num,mdarr8_t* res);
  void femdarr8_get_active_bases(femdarr8_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum8/array/gauss/algebra.h
  
  femdarr8_t femdarr8_neg(    femdarr8_t* arr);
  void      femdarr8_neg_to( femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t femdarr8_sum_FF(   femdarr8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_sum_FF_to(femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sum_fF(    femdnum8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_sum_fF_to( femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sum_OF(     mdarr8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_sum_OF_to(  mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sum_RF(      darr_t* lhs, femdarr8_t* rhs);
  void      femdarr8_sum_RF_to(   darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sum_oF(   mdnum8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_sum_oF_to(mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sum_rF(     coeff_t  lhs, femdarr8_t* rhs);
  void      femdarr8_sum_rF_to(  coeff_t  lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sub_FF(    femdarr8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_sub_FF_to( femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sub_fF(    femdnum8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_sub_fF_to( femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sub_Ff(    femdarr8_t* lhs, femdnum8_t* rhs);
  void      femdarr8_sub_Ff_to( femdarr8_t* lhs, femdnum8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sub_OF(      mdarr8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_sub_OF_to(   mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sub_FO(    femdarr8_t* lhs,   mdarr8_t* rhs);
  void      femdarr8_sub_FO_to( femdarr8_t* lhs,   mdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sub_RF(       darr_t* lhs, femdarr8_t* rhs);
  void      femdarr8_sub_RF_to(    darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sub_FR(    femdarr8_t* lhs,    darr_t* rhs);
  void      femdarr8_sub_FR_to( femdarr8_t* lhs,    darr_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sub_oF(    mdnum8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_sub_oF_to( mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sub_Fo(    femdarr8_t* lhs, mdnum8_t* rhs);
  void      femdarr8_sub_Fo_to( femdarr8_t* lhs, mdnum8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sub_rF(      coeff_t  lhs, femdarr8_t* rhs);
  void      femdarr8_sub_rF_to(    coeff_t lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_sub_Fr(    femdarr8_t* lhs,   coeff_t  rhs);
  void      femdarr8_sub_Fr_to( femdarr8_t* lhs,   coeff_t  rhs, femdarr8_t* res);
  femdarr8_t femdarr8_mul_FF(   femdarr8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_mul_FF_to(femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_mul_fF(    femdnum8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_mul_fF_to( femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_mul_OF(     mdarr8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_mul_OF_to(  mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_mul_RF(      darr_t* lhs, femdarr8_t* rhs);
  void      femdarr8_mul_RF_to(   darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_mul_oF(   mdnum8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_mul_oF_to(mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_mul_rF(     coeff_t  lhs, femdarr8_t* rhs);
  void      femdarr8_mul_rF_to(  coeff_t  lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_div_FF(    femdarr8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_div_FF_to( femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_div_fF(     femdnum8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_div_fF_to(  femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_div_Ff(    femdarr8_t* lhs,  femdnum8_t* rhs);
  void      femdarr8_div_Ff_to( femdarr8_t* lhs,  femdnum8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_div_OF(      mdarr8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_div_OF_to(   mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_div_FO(    femdarr8_t* lhs,   mdarr8_t* rhs);
  void      femdarr8_div_FO_to( femdarr8_t* lhs,   mdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_div_RF(       darr_t* lhs, femdarr8_t* rhs);
  void      femdarr8_div_RF_to(    darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_div_FR(    femdarr8_t* lhs,    darr_t* rhs);
  void      femdarr8_div_FR_to( femdarr8_t* lhs,    darr_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_div_oF(    mdnum8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_div_oF_to( mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_div_Fo(    femdarr8_t* lhs, mdnum8_t* rhs);
  void      femdarr8_div_Fo_to( femdarr8_t* lhs, mdnum8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_div_rF(      coeff_t  lhs, femdarr8_t* rhs);
  void      femdarr8_div_rF_to(    coeff_t lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_div_Fr(    femdarr8_t* lhs,   coeff_t  rhs);
  void      femdarr8_div_Fr_to( femdarr8_t* lhs,   coeff_t  rhs, femdarr8_t* res);
  mdarr8_t femdarr8_integrate(    femdarr8_t* arr, femdnum8_t* w);
  void    femdarr8_integrate_to( femdarr8_t* arr, femdnum8_t* w, mdarr8_t* res);
  femdnum8_t femdarr8_dotproduct_FF(    femdarr8_t* lhs, femdarr8_t* rhs);
  void     femdarr8_dotproduct_FF_to( femdarr8_t* lhs, femdarr8_t* rhs, femdnum8_t* res);
  femdnum8_t femdarr8_dotproduct_OF(      mdarr8_t* lhs, femdarr8_t* rhs);
  void     femdarr8_dotproduct_OF_to(   mdarr8_t* lhs, femdarr8_t* rhs, femdnum8_t* res);
  femdnum8_t femdarr8_dotproduct_RF(       darr_t* lhs, femdarr8_t* rhs);
  void     femdarr8_dotproduct_RF_to(    darr_t* lhs, femdarr8_t* rhs, femdnum8_t* res);
  femdarr8_t femdarr8_matmul_FF(    femdarr8_t* lhs, femdarr8_t* rhs);
  void      femdarr8_matmul_FF_to( femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_matmul_OF(    mdarr8_t*   lhs, femdarr8_t* rhs);
  void      femdarr8_matmul_OF_to( mdarr8_t*   lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_matmul_FO(    femdarr8_t* lhs, mdarr8_t*   rhs);
  void      femdarr8_matmul_FO_to( femdarr8_t* lhs, mdarr8_t*   rhs, femdarr8_t* res);
  femdarr8_t femdarr8_matmul_RF(    darr_t*    lhs, femdarr8_t* rhs);
  void      femdarr8_matmul_RF_to( darr_t*    lhs, femdarr8_t* rhs, femdarr8_t* res);
  femdarr8_t femdarr8_matmul_FR(    femdarr8_t* lhs, darr_t*    rhs);
  void      femdarr8_matmul_FR_to( femdarr8_t* lhs, darr_t*    rhs, femdarr8_t* res);
  femdnum8_t femdarr8_det(   femdarr8_t* arr);
  void     femdarr8_det_to(femdarr8_t* arr, femdnum8_t* res);
  femdnum8_t femdarr8_norm(     femdarr8_t* arr);
  void     femdarr8_norm_to(  femdarr8_t* arr, femdnum8_t* res);
  femdnum8_t femdarr8_pnorm(    femdarr8_t* arr, coeff_t p);
  void     femdarr8_pnorm_to( femdarr8_t* arr, coeff_t p, femdnum8_t* res);
  femdarr8_t   femdarr8_invert(    femdarr8_t* arr);
  void        femdarr8_invert_to( femdarr8_t* arr, femdarr8_t* res);
  femdarr8_t   femdarr8_transpose(   femdarr8_t* arr);
  void        femdarr8_transpose_to(femdarr8_t* arr, femdarr8_t* res);
  
  