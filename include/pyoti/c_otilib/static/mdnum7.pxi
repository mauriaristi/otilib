cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/mdnum7/scalar/structures.h
  
  ctypedef struct  mdnum7_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
    coeff_t e6;
    coeff_t e7;
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
    coeff_t e123456;
    coeff_t e123457;
    coeff_t e123467;
    coeff_t e123567;
    coeff_t e124567;
    coeff_t e134567;
    coeff_t e234567;
    coeff_t e1234567;
  # } mdnum7_t;
  
  
  # From ../../../include/oti/static/mdnum7/array/structures.h
  
  ctypedef struct  mdarr7_t : # {
      mdnum7_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
      flag_t          flag;
  # } mdarr7_t;
  
  
  # From ../../../include/oti/static/mdnum7/scalar/gauss/structures.h
  
  ctypedef struct  femdnum7_t: # {
      mdnum7_t*  p_data;
      uint64_t    nip;
  # } femdnum7_t;
  
  
  # From ../../../include/oti/static/mdnum7/array/gauss/structures.h
  
  ctypedef struct  femdarr7_t: # {
      mdarr7_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } femdarr7_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/mdnum7/scalar/functions.h
  
  mdnum7_t mdnum7_atanh(mdnum7_t* num);
  void mdnum7_atanh_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_asinh(mdnum7_t* num);
  void mdnum7_asinh_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_acosh(mdnum7_t* num);
  void mdnum7_acosh_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_tanh(mdnum7_t* num);
  void mdnum7_tanh_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_sqrt(mdnum7_t* num);
  void mdnum7_sqrt_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_cbrt(mdnum7_t* num);
  void mdnum7_cbrt_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_cosh(mdnum7_t* num);
  void mdnum7_cosh_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_sinh(mdnum7_t* num);
  void mdnum7_sinh_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_asin(mdnum7_t* num);
  void mdnum7_asin_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_acos(mdnum7_t* num);
  void mdnum7_acos_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_atan(mdnum7_t* num);
  void mdnum7_atan_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_tan(mdnum7_t* num);
  void mdnum7_tan_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_cos(mdnum7_t* num);
  void mdnum7_cos_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_sin(mdnum7_t* num );
  void mdnum7_sin_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_logb(mdnum7_t* num, double base);
  void mdnum7_logb_to(mdnum7_t* num, double base, mdnum7_t* res);
  mdnum7_t mdnum7_log10(mdnum7_t* num);
  void mdnum7_log10_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_log(mdnum7_t* num);
  void mdnum7_log_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_exp(mdnum7_t* num);
  void mdnum7_exp_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_pow(mdnum7_t* num, double e);
  void mdnum7_pow_to(mdnum7_t* num, coeff_t e, mdnum7_t* res);
  
  
  # From ../../../include/oti/static/mdnum7/scalar/base.h
  
  void mdnum7_set_im_o(mdnum7_t* num, imdir_t idx, ord_t order, mdnum7_t* res);
  void mdnum7_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum7_t* res);
  void mdnum7_set_deriv_o(mdnum7_t* num, imdir_t idx, ord_t order, mdnum7_t* res);
  void mdnum7_extract_im_to( imdir_t idx, ord_t order, mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_extract_im(imdir_t idx, ord_t order, mdnum7_t* num);
  mdnum7_t mdnum7_extract_deriv(imdir_t idx, ord_t order, mdnum7_t* num);
  void mdnum7_extract_deriv_to(imdir_t idx, ord_t order, mdnum7_t* num, mdnum7_t* res);
  void mdnum7_get_im_to_o(imdir_t idx, ord_t order, mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_get_im_o(imdir_t idx, ord_t order, mdnum7_t* num);
  void mdnum7_get_im_to_r(imdir_t idx, ord_t order, mdnum7_t* num, coeff_t* res);
  ord_t mdnum7_get_order(mdnum7_t* lhs);
  mdnum7_t mdnum7_get_deriv_o( imdir_t idx, ord_t order, mdnum7_t* num);
  void mdnum7_get_deriv_to( imdir_t idx, ord_t order, mdnum7_t* num, mdnum7_t* res);
  void mdnum7_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum7_t* res);
  mdnum7_t mdnum7_init();
  ndir_t mdnum7_get_ndir_order(ord_t order, mdnum7_t* num);
  ndir_t mdnum7_get_ndir_total(mdnum7_t* num);
  coeff_t* mdnum7_get_order_address(ord_t order, mdnum7_t* num);
  mdnum7_t mdnum7_create_r(  coeff_t lhs);
  void mdnum7_set_r(  coeff_t lhs, mdnum7_t* res);
  void mdnum7_set_o(  mdnum7_t* lhs, mdnum7_t* res);
  mdnum7_t mdnum7_get_order_im(ord_t order, mdnum7_t* lhs);
  void mdnum7_get_order_im_to(ord_t order, mdnum7_t* lhs, mdnum7_t* res);
  coeff_t mdnum7_get_item(imdir_t idx, ord_t order, mdnum7_t* lhs);
  coeff_t mdnum7_get_deriv(imdir_t idx, ord_t order, mdnum7_t* lhs);
  void mdnum7_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum7_t* x);
  mdnum7_t mdnum7_copy(  mdnum7_t* lhs);
  void mdnum7_copy_to(  mdnum7_t* lhs, mdnum7_t* res);
  mdnum7_t mdnum7_taylor_integrate(coeff_t* deltas,mdnum7_t* lhs);
  void mdnum7_taylor_integrate_to(coeff_t* deltas,mdnum7_t* lhs, mdnum7_t* res);
  mdnum7_t mdnum7_truncate_im(imdir_t idx, ord_t order, mdnum7_t* lhs);
  void mdnum7_truncate_im_to(imdir_t idx, ord_t order, mdnum7_t* lhs, mdnum7_t* res);
  void mdnum7_print(  mdnum7_t* lhs);
  imdir_t mdnum7_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/mdnum7/scalar/utils.h
  
  void mdnum7_get_active_bases(mdnum7_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/mdnum7/scalar/algebra.h
  
  mdnum7_t mdnum7_abs(mdnum7_t* num);
  mdnum7_t mdnum7_div_ro(coeff_t num, mdnum7_t* den);
  mdnum7_t mdnum7_div_oo(mdnum7_t* num, mdnum7_t* den);
  mdnum7_t mdnum7_div_or(mdnum7_t* num, coeff_t val);
  void mdnum7_div_ro_to(coeff_t num, mdnum7_t* den, mdnum7_t* res);
  void mdnum7_div_oo_to(mdnum7_t* num, mdnum7_t* den, mdnum7_t* res);
  void mdnum7_div_or_to(mdnum7_t* num, coeff_t val, mdnum7_t* res);
  void mdnum7_abs_to(mdnum7_t* num, mdnum7_t* res);
  mdnum7_t mdnum7_neg(  mdnum7_t* lhs);
  void mdnum7_neg_to(  mdnum7_t* lhs, mdnum7_t* res);
  mdnum7_t mdnum7_sum_oo(  mdnum7_t* lhs,  mdnum7_t* rhs);
  void mdnum7_sum_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res);
  mdnum7_t mdnum7_sum_ro(  coeff_t lhs,  mdnum7_t* rhs);
  void mdnum7_sum_ro_to(  coeff_t lhs,  mdnum7_t* rhs, mdnum7_t* res);
  mdnum7_t mdnum7_sub_oo(  mdnum7_t* lhs,  mdnum7_t* rhs);
  void mdnum7_sub_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res);
  mdnum7_t mdnum7_sub_ro(  coeff_t lhs,  mdnum7_t* rhs);
  void mdnum7_sub_ro_to(  coeff_t lhs,  mdnum7_t* rhs, mdnum7_t* res);
  mdnum7_t mdnum7_sub_or(  mdnum7_t* lhs,  coeff_t rhs);
  void mdnum7_sub_or_to(  mdnum7_t* lhs,  coeff_t rhs, mdnum7_t* res);
  mdnum7_t mdnum7_mul_oo(  mdnum7_t* lhs,  mdnum7_t* rhs);
  void mdnum7_mul_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res);
  mdnum7_t mdnum7_mul_ro(  coeff_t lhs,  mdnum7_t* rhs);
  void mdnum7_mul_ro_to(  coeff_t lhs,  mdnum7_t* rhs, mdnum7_t* res);
  mdnum7_t mdnum7_trunc_mul_oo(  mdnum7_t* lhs,  mdnum7_t* rhs);
  void mdnum7_trunc_mul_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res);
  mdnum7_t mdnum7_gem_oo(  mdnum7_t* a,  mdnum7_t* b,  mdnum7_t* c);
  void mdnum7_gem_oo_to(  mdnum7_t* a,  mdnum7_t* b,  mdnum7_t* c, mdnum7_t* res);
  mdnum7_t mdnum7_gem_ro(  coeff_t a,  mdnum7_t* b,  mdnum7_t* c);
  void mdnum7_gem_ro_to(  coeff_t a,  mdnum7_t* b,  mdnum7_t* c, mdnum7_t* res);
  void mdnum7_trunc_gem_oo_to( ord_t ord_lhs,  mdnum7_t* a,  ord_t ord_rhs,  mdnum7_t* b,  mdnum7_t* c, mdnum7_t* res);
  mdnum7_t mdnum7_feval(coeff_t* feval_re, mdnum7_t* x);
  void mdnum7_feval_to(coeff_t* feval_re, mdnum7_t* x, mdnum7_t* res);
  
  
  # From ../../../include/oti/static/mdnum7/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum7/scalar/gauss/functions.h
  
  femdnum7_t femdnum7_atanh(    femdnum7_t* num);
  void     femdnum7_atanh_to( femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_asinh(    femdnum7_t* num);
  void     femdnum7_asinh_to( femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_acosh(    femdnum7_t* num);
  void     femdnum7_acosh_to( femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_tanh(     femdnum7_t* num);
  void     femdnum7_tanh_to(  femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_cosh(     femdnum7_t* num);
  void     femdnum7_cosh_to(  femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_sinh(     femdnum7_t* num);
  void     femdnum7_sinh_to(  femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_asin(     femdnum7_t* num);
  void     femdnum7_asin_to(  femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_acos(     femdnum7_t* num);
  void     femdnum7_acos_to(  femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_atan(     femdnum7_t* num);
  void     femdnum7_atan_to(  femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_tan(      femdnum7_t* num);
  void     femdnum7_tan_to(   femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_cos(      femdnum7_t* num);
  void     femdnum7_cos_to(   femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_sin(      femdnum7_t* num);
  void     femdnum7_sin_to(   femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_logb(     femdnum7_t* num, double base);
  void     femdnum7_logb_to(  femdnum7_t* num, double base, femdnum7_t* res);
  femdnum7_t femdnum7_log10(    femdnum7_t* num);
  void     femdnum7_log10_to( femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_log(      femdnum7_t* num);
  void     femdnum7_log_to(   femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_exp(      femdnum7_t* num);
  void     femdnum7_exp_to(   femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_cbrt(     femdnum7_t* num);
  void     femdnum7_cbrt_to(  femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_sqrt(     femdnum7_t* num);
  void     femdnum7_sqrt_to(  femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_pow(      femdnum7_t* num, double e);
  void     femdnum7_pow_to(   femdnum7_t* num, double e, femdnum7_t* res);
  mdnum7_t femdnum7_integrate(       femdnum7_t* num, femdnum7_t* w);
  void      femdnum7_integrate_to(    femdnum7_t* num, femdnum7_t* w, mdnum7_t* res);
  mdnum7_t femdnum7_integrate_f(     femdnum7_t* num, femdnum7_t* w);
  void      femdnum7_integrate_f_to(  femdnum7_t* num, femdnum7_t* w, mdnum7_t* res);
  mdnum7_t femdnum7_integrate_r(       coeff_t num, femdnum7_t* w);
  void      femdnum7_integrate_r_to(    coeff_t num, femdnum7_t* w, mdnum7_t* res);
  mdnum7_t femdnum7_integrate_o(    mdnum7_t* num, femdnum7_t* w);
  void      femdnum7_integrate_o_to( mdnum7_t* num, femdnum7_t* w, mdnum7_t* res);
  
  
  # From ../../../include/oti/static/mdnum7/scalar/gauss/base.h
  
  void     femdnum7_get_order_im_to( ord_t order, femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_get_order_im(    ord_t order, femdnum7_t* num);
  femdnum7_t femdnum7_get_im(    imdir_t idx, ord_t order, femdnum7_t* num);
  void     femdnum7_get_im_to( imdir_t idx, ord_t order, femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_get_deriv(    imdir_t idx, ord_t order, femdnum7_t* num);
  void     femdnum7_get_deriv_to( imdir_t idx, ord_t order, femdnum7_t* num, femdnum7_t* res);
  void femdnum7_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum7_t* num);
  void femdnum7_set_im_o( mdnum7_t* val, imdir_t idx, ord_t order, femdnum7_t* num);
  void femdnum7_set_im_f(  femdnum7_t* val, imdir_t idx, ord_t order, femdnum7_t* num);
  void femdnum7_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum7_t* num);
  void femdnum7_set_deriv_o( mdnum7_t* val, imdir_t idx, ord_t order, femdnum7_t* num);
  void femdnum7_set_deriv_f(  femdnum7_t* val, imdir_t idx, ord_t order, femdnum7_t* num);
  femdnum7_t femdnum7_extract_im(    imdir_t idx, ord_t order, femdnum7_t* num);
  void     femdnum7_extract_im_to( imdir_t idx, ord_t order, femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_extract_deriv(    imdir_t idx, ord_t order, femdnum7_t* num);
  void     femdnum7_extract_deriv_to( imdir_t idx, ord_t order, femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_truncate_im(    imdir_t idx, ord_t order, femdnum7_t* num);
  void     femdnum7_truncate_im_to( imdir_t idx, ord_t order, femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_copy(    femdnum7_t* src);
  void     femdnum7_copy_to( femdnum7_t* src, femdnum7_t* dst);
  void femdnum7_set_r(    coeff_t num, femdnum7_t* res);
  void femdnum7_set_o( mdnum7_t* num, femdnum7_t* res);
  void femdnum7_set_f(  femdnum7_t* num, femdnum7_t* res);
  void femdnum7_set_item_k_r(   coeff_t  num, uint64_t k, femdnum7_t* res);
  void femdnum7_set_item_k_o( mdnum7_t* num, uint64_t k, femdnum7_t* res);
  mdnum7_t femdnum7_get_item_k(   femdnum7_t* num, uint64_t k);
  void      femdnum7_get_item_k_to(femdnum7_t* num, uint64_t k, mdnum7_t* res);
  femdnum7_t femdnum7_zeros(uint64_t nIntPts);
  femdnum7_t femdnum7_createEmpty(uint64_t nIntPts);
  femdnum7_t femdnum7_empty_like(femdnum7_t* arr);
  void femdnum7_free(femdnum7_t* num);
  ord_t femdnum7_get_order( femdnum7_t* num );
  femdnum7_t femdnum7_init();
  
  
  # From ../../../include/oti/static/mdnum7/scalar/gauss/utils.h
  
  void femdnum7_dimCheck(femdnum7_t* arr1,femdnum7_t* arr2);
  void femdnum7_get_active_bases(femdnum7_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum7/scalar/gauss/algebra.h
  
  femdnum7_t femdnum7_neg(   femdnum7_t* num);
  void     femdnum7_neg_to(femdnum7_t* num, femdnum7_t* res);
  femdnum7_t femdnum7_sum_ff(   femdnum7_t* lhs, femdnum7_t* rhs);
  void     femdnum7_sum_ff_to(femdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_sum_of(   mdnum7_t* lhs, femdnum7_t* rhs);
  void     femdnum7_sum_of_to(mdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_sum_rf(   coeff_t lhs, femdnum7_t* rhs);
  void     femdnum7_sum_rf_to(coeff_t lhs, femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_sub_ff(     femdnum7_t* lhs,  femdnum7_t* rhs);
  void     femdnum7_sub_ff_to(  femdnum7_t* lhs,  femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_sub_of(    mdnum7_t* lhs,  femdnum7_t* rhs);
  void     femdnum7_sub_of_to( mdnum7_t* lhs,  femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_sub_fo(     femdnum7_t* lhs, mdnum7_t* rhs);
  void     femdnum7_sub_fo_to(  femdnum7_t* lhs, mdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_sub_rf(       coeff_t lhs,  femdnum7_t* rhs);
  void     femdnum7_sub_rf_to(    coeff_t lhs,  femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_sub_fr(     femdnum7_t* lhs,    coeff_t rhs);
  void     femdnum7_sub_fr_to(  femdnum7_t* lhs,    coeff_t rhs, femdnum7_t* res);
  femdnum7_t femdnum7_mul_ff(   femdnum7_t* lhs, femdnum7_t* rhs);
  void     femdnum7_mul_ff_to(femdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_mul_of(   mdnum7_t* lhs, femdnum7_t* rhs);
  void     femdnum7_mul_of_to(mdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_mul_rf(   coeff_t lhs, femdnum7_t* rhs);
  void     femdnum7_mul_rf_to(coeff_t lhs, femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_div_ff(     femdnum7_t* lhs,  femdnum7_t* rhs);
  void     femdnum7_div_ff_to(  femdnum7_t* lhs,  femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_div_of(    mdnum7_t* lhs,  femdnum7_t* rhs);
  void     femdnum7_div_of_to( mdnum7_t* lhs,  femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_div_fo(     femdnum7_t* lhs, mdnum7_t* rhs);
  void     femdnum7_div_fo_to(  femdnum7_t* lhs, mdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_div_rf(       coeff_t lhs,  femdnum7_t* rhs);
  void     femdnum7_div_rf_to(    coeff_t lhs,  femdnum7_t* rhs, femdnum7_t* res);
  femdnum7_t femdnum7_div_fr(     femdnum7_t* lhs,    coeff_t rhs);
  void     femdnum7_div_fr_to(  femdnum7_t* lhs,    coeff_t rhs, femdnum7_t* res);
  
  
  # From ../../../include/oti/static/mdnum7/array/functions.h
  
  mdarr7_t mdarr7_atanh(   mdarr7_t* arr);
  void    mdarr7_atanh_to(mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_asinh(   mdarr7_t* arr);
  void    mdarr7_asinh_to(mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_acosh(   mdarr7_t* arr);
  void    mdarr7_acosh_to(mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_tanh(    mdarr7_t* arr);
  void    mdarr7_tanh_to( mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_cbrt(    mdarr7_t* arr);
  void    mdarr7_cbrt_to( mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_sqrt(    mdarr7_t* arr);
  void    mdarr7_sqrt_to( mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_cosh(    mdarr7_t* arr);
  void    mdarr7_cosh_to( mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_sinh(    mdarr7_t* arr);
  void    mdarr7_sinh_to( mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_asin(    mdarr7_t* arr);
  void    mdarr7_asin_to( mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_acos(    mdarr7_t* arr);
  void    mdarr7_acos_to( mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_atan(    mdarr7_t* arr);
  void    mdarr7_atan_to( mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_tan(     mdarr7_t* arr);
  void    mdarr7_tan_to(  mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_cos(     mdarr7_t* arr);
  void    mdarr7_cos_to(  mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_sin(     mdarr7_t* arr);
  void    mdarr7_sin_to(  mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_logb(    mdarr7_t* arr, double base);
  void    mdarr7_logb_to( mdarr7_t* arr, double base, mdarr7_t* res);
  mdarr7_t mdarr7_log10(   mdarr7_t* arr);
  void    mdarr7_log10_to(mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_log(     mdarr7_t* arr);
  void    mdarr7_log_to(  mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_exp(     mdarr7_t* arr);
  void    mdarr7_exp_to(  mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_pow(     mdarr7_t* arr, double e);
  void    mdarr7_pow_to(  mdarr7_t* arr, double e, mdarr7_t* res);
  
  
  # From ../../../include/oti/static/mdnum7/array/algebra_elementwise.h
  
  mdarr7_t mdarr7_neg(mdarr7_t* arr);
  void mdarr7_neg_to(mdarr7_t* rhs, mdarr7_t* res);
  mdarr7_t mdarr7_sum_OO(mdarr7_t*   lhs, mdarr7_t* rhs);
  mdarr7_t mdarr7_sum_RO(darr_t*    lhs, mdarr7_t* rhs);
  mdarr7_t mdarr7_sum_oO(mdnum7_t* lhs, mdarr7_t* rhs);
  mdarr7_t mdarr7_sum_rO(coeff_t    lhs, mdarr7_t* rhs);
  void mdarr7_sum_OO_to(mdarr7_t*   lhs, mdarr7_t* rhs, mdarr7_t* res);
  void mdarr7_sum_RO_to(darr_t*    lhs, mdarr7_t* rhs, mdarr7_t* res);
  void mdarr7_sum_oO_to(mdnum7_t* lhs, mdarr7_t* rhs, mdarr7_t* res);
  void mdarr7_sum_rO_to(coeff_t    lhs, mdarr7_t* rhs, mdarr7_t* res);
  mdarr7_t mdarr7_sub_OO(mdarr7_t*   lhs, mdarr7_t*   rhs);
  mdarr7_t mdarr7_sub_RO(darr_t*    lhs, mdarr7_t*   rhs);
  mdarr7_t mdarr7_sub_OR(mdarr7_t*   lhs, darr_t*    rhs);
  mdarr7_t mdarr7_sub_oO(mdnum7_t* lhs, mdarr7_t*   rhs);
  mdarr7_t mdarr7_sub_Oo(mdarr7_t*   lhs, mdnum7_t* rhs);
  mdarr7_t mdarr7_sub_rO(coeff_t    lhs, mdarr7_t*   rhs);
  mdarr7_t mdarr7_sub_Or(mdarr7_t*   lhs, coeff_t    rhs);
  void mdarr7_sub_OO_to( mdarr7_t*   lhs, mdarr7_t*   rhs, mdarr7_t* res);
  void mdarr7_sub_RO_to( darr_t*    lhs, mdarr7_t*   rhs, mdarr7_t* res);
  void mdarr7_sub_OR_to( mdarr7_t*   lhs, darr_t*    rhs, mdarr7_t* res);
  void mdarr7_sub_oO_to( mdnum7_t* lhs, mdarr7_t*   rhs, mdarr7_t* res);
  void mdarr7_sub_Oo_to( mdarr7_t*   lhs, mdnum7_t* rhs, mdarr7_t* res);
  void mdarr7_sub_rO_to( coeff_t    lhs, mdarr7_t*   rhs, mdarr7_t* res);
  void mdarr7_sub_Or_to( mdarr7_t*   lhs, coeff_t    rhs, mdarr7_t* res);
  mdarr7_t mdarr7_mul_OO(mdarr7_t*   lhs, mdarr7_t* rhs);
  mdarr7_t mdarr7_mul_RO(darr_t*    lhs, mdarr7_t* rhs);
  mdarr7_t mdarr7_mul_oO(mdnum7_t* lhs, mdarr7_t* rhs);
  mdarr7_t mdarr7_mul_rO(coeff_t    lhs, mdarr7_t* rhs);
  void mdarr7_mul_OO_to(mdarr7_t*   lhs, mdarr7_t* rhs, mdarr7_t* res);
  void mdarr7_mul_RO_to(darr_t*    lhs, mdarr7_t* rhs, mdarr7_t* res);
  void mdarr7_mul_oO_to(mdnum7_t* lhs, mdarr7_t* rhs, mdarr7_t* res);
  void mdarr7_mul_rO_to(coeff_t    lhs, mdarr7_t* rhs, mdarr7_t* res);
  void mdarr7_gem_OO_to(  mdarr7_t* arr1, mdarr7_t* arr2, mdarr7_t* arr3, mdarr7_t* res);
  void mdarr7_gem_oO_to(mdnum7_t* arr1, mdarr7_t* arr2, mdarr7_t* arr3, mdarr7_t* res);
  mdarr7_t mdarr7_div_OO(mdarr7_t*   lhs, mdarr7_t*   rhs);
  mdarr7_t mdarr7_div_OR(mdarr7_t*   lhs, darr_t*    rhs);
  mdarr7_t mdarr7_div_RO(darr_t*    lhs, mdarr7_t*   rhs);
  mdarr7_t mdarr7_div_oO(mdnum7_t* lhs, mdarr7_t*   rhs);
  mdarr7_t mdarr7_div_Oo(mdarr7_t*   lhs, mdnum7_t* rhs);
  mdarr7_t mdarr7_div_rO(coeff_t    lhs, mdarr7_t*   rhs);
  mdarr7_t mdarr7_div_Or(mdarr7_t*   lhs, coeff_t    rhs);
  void mdarr7_div_OO_to(mdarr7_t*   lhs, mdarr7_t*   rhs, mdarr7_t* res);
  void mdarr7_div_RO_to(darr_t*    lhs, mdarr7_t*   rhs, mdarr7_t* res);
  void mdarr7_div_OR_to(mdarr7_t*   lhs, darr_t*    rhs, mdarr7_t* res);
  void mdarr7_div_oO_to(mdnum7_t* lhs, mdarr7_t*   rhs, mdarr7_t* res);
  void mdarr7_div_Oo_to(mdarr7_t*   lhs, mdnum7_t* rhs, mdarr7_t* res);
  void mdarr7_div_rO_to(coeff_t    lhs, mdarr7_t*   rhs, mdarr7_t* res);
  void mdarr7_div_Or_to(mdarr7_t*   lhs, coeff_t    rhs, mdarr7_t* res);
  
  
  # From ../../../include/oti/static/mdnum7/array/base.h
  
  void    mdarr7_taylor_integrate_to( coeff_t* deltas, mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_taylor_integrate(    coeff_t* deltas, mdarr7_t* arr);
  void    mdarr7_get_order_im_to( ord_t order, mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_get_order_im(    ord_t order, mdarr7_t* arr);
  void mdarr7_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr7_t* res);
  void mdarr7_set_slice_O( mdarr7_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr7_t* res);
  void mdarr7_set_slice_o( mdnum7_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr7_t* res);
  mdarr7_t mdarr7_get_slice( mdarr7_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void mdarr7_get_slice_to( mdarr7_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr7_t* res);
  mdarr7_t mdarr7_truncate_im(    imdir_t idx, ord_t order, mdarr7_t* arr);
  void    mdarr7_truncate_im_to( imdir_t idx, ord_t order, mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_extract_im(   imdir_t idx, ord_t order, mdarr7_t* arr);
  void    mdarr7_extract_im_to(imdir_t idx, ord_t order, mdarr7_t* arr, mdarr7_t* res);
  darr_t  mdarr7_get_deriv(    imdir_t idx, ord_t order, mdarr7_t* arr);
  void    mdarr7_get_deriv_to( imdir_t idx, ord_t order, mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_get_deriv_o(  imdir_t idx, ord_t order, mdarr7_t* arr);
  mdarr7_t mdarr7_extract_deriv(    imdir_t idx, ord_t order, mdarr7_t* arr);
  void    mdarr7_extract_deriv_to( imdir_t idx, ord_t order, mdarr7_t* arr, mdarr7_t* res);
  darr_t  mdarr7_get_im(   imdir_t idx, ord_t order, mdarr7_t* arr);
  mdarr7_t mdarr7_get_im_o( imdir_t idx, ord_t order, mdarr7_t* arr);
  void    mdarr7_get_im_to(imdir_t idx, ord_t order, mdarr7_t* arr, mdarr7_t* res);
  void    mdarr7_copy_to(mdarr7_t* arr, mdarr7_t* res);
  mdarr7_t mdarr7_copy(mdarr7_t* arr);
  void mdarr7_set_all_r( coeff_t num, mdarr7_t* arr);
  void mdarr7_set_item_i_r( coeff_t num, uint64_t i, mdarr7_t* arr);
  void mdarr7_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, mdarr7_t* arr);
  void mdarr7_set_r(   coeff_t  num,   mdarr7_t* arr);
  void mdarr7_set_o( mdnum7_t* num,   mdarr7_t* arr);
  void mdarr7_set_O(   mdarr7_t* arrin, mdarr7_t* arr);
  void mdarr7_set_all_o( mdnum7_t* src, mdarr7_t* arr);
  void mdarr7_set_item_i_o( mdnum7_t* num, uint64_t i, mdarr7_t* arr);
  void mdarr7_set_item_ij_o( mdnum7_t* num, uint64_t i, uint64_t j, mdarr7_t* arr);
  mdnum7_t mdarr7_get_item_i(    mdarr7_t* arr, uint64_t i);
  void      mdarr7_get_item_i_to( mdarr7_t* arr, uint64_t i,             mdnum7_t* res);
  mdnum7_t mdarr7_get_item_ij(   mdarr7_t* arr, uint64_t i, uint64_t j);
  void      mdarr7_get_item_ij_to(mdarr7_t* arr, uint64_t i, uint64_t j, mdnum7_t* res);
  mdarr7_t mdarr7_init();
  void mdarr7_free(mdarr7_t* arr);
  mdarr7_t mdarr7_empty_like(mdarr7_t* arr);
  mdarr7_t mdarr7_eye(uint64_t nrows);
  mdarr7_t mdarr7_ones(uint64_t nrows, uint64_t ncols);
  mdarr7_t mdarr7_zeros(uint64_t nrows, uint64_t ncols);
  mdarr7_t mdarr7_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/mdnum7/array/utils.h
  
  void mdarr7_dimCheck_OO_elementwise(mdarr7_t* arr1, mdarr7_t* arr2, mdarr7_t* res);
  void mdarr7_dimCheck_RO_elementwise(darr_t*  arr1, mdarr7_t* arr2, mdarr7_t* res);
  void mdarr7_dimCheck_OO_matmul(mdarr7_t* arr1, mdarr7_t* arr2, mdarr7_t* res);
  void mdarr7_dimCheck_RO_matmul(darr_t*  arr1, mdarr7_t* arr2, mdarr7_t* res);
  void mdarr7_dimCheck_OR_matmul(mdarr7_t* arr1, darr_t*  arr2, mdarr7_t* res);
  void mdarr7_dimCheck_O_squareness(mdarr7_t* arr1, mdarr7_t* res);
  void mdarr7_dimCheck_OO_samesize(mdarr7_t* arr1, mdarr7_t* res);
  void mdarr7_dimCheck_RO_samesize(darr_t* arr1, mdarr7_t* res);
  ord_t mdarr7_get_order(mdarr7_t* arr);
  void mdarr7_get_active_bases(mdarr7_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum7/array/algebra_matops.h
  
  mdnum7_t mdarr7_dotproduct_OO(    mdarr7_t* lhs, mdarr7_t* rhs);
  void      mdarr7_dotproduct_OO_to( mdarr7_t* lhs, mdarr7_t* rhs, mdnum7_t* res);
  mdnum7_t mdarr7_dotproduct_RO(     darr_t* lhs, mdarr7_t* rhs);
  void      mdarr7_dotproduct_RO_to(  darr_t* lhs, mdarr7_t* rhs, mdnum7_t* res);
  mdarr7_t mdarr7_matmul_OO(    mdarr7_t* lhs, mdarr7_t* rhs);
  mdarr7_t mdarr7_matmul_OR(    mdarr7_t* lhs,  darr_t* rhs);
  mdarr7_t mdarr7_matmul_RO(     darr_t* lhs, mdarr7_t* rhs);
  void    mdarr7_matmul_OO_to( mdarr7_t* lhs, mdarr7_t* rhs, mdarr7_t* res);
  void    mdarr7_matmul_OR_to( mdarr7_t* lhs,  darr_t* rhs, mdarr7_t* res);
  void    mdarr7_matmul_RO_to(  darr_t* lhs, mdarr7_t* rhs, mdarr7_t* res);
  mdarr7_t mdarr7_transpose(    mdarr7_t* arr1);
  void    mdarr7_transpose_to( mdarr7_t* arr1, mdarr7_t* res);
  mdarr7_t mdarr7_invert(    mdarr7_t* arr1);
  void    mdarr7_invert_to( mdarr7_t* arr1, mdarr7_t* res);
  mdnum7_t mdarr7_det(    mdarr7_t* arr1);
  void      mdarr7_det_to( mdarr7_t* arr1, mdnum7_t* res);
  mdnum7_t mdarr7_norm(    mdarr7_t* arr1);
  void      mdarr7_norm_to( mdarr7_t* arr1,  mdnum7_t* res);
  mdnum7_t mdarr7_pnorm(    mdarr7_t* arr1, coeff_t p);
  void      mdarr7_pnorm_to( mdarr7_t* arr1, coeff_t p, mdnum7_t* res);
  
  
  # From ../../../include/oti/static/mdnum7/array/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum7/array/gauss/functions.h
  
  femdarr7_t femdarr7_atanh(    femdarr7_t* arr);
  void      femdarr7_atanh_to( femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_asinh(    femdarr7_t* arr);
  void      femdarr7_asinh_to( femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_acosh(    femdarr7_t* arr);
  void      femdarr7_acosh_to( femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_tanh(     femdarr7_t* arr);
  void      femdarr7_tanh_to(  femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_sinh(     femdarr7_t* arr);
  void      femdarr7_sinh_to(  femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_cosh(     femdarr7_t* arr);
  void      femdarr7_cosh_to(  femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_atan(     femdarr7_t* arr);
  void      femdarr7_atan_to(  femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_asin(     femdarr7_t* arr);
  void      femdarr7_asin_to(  femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_acos(     femdarr7_t* arr);
  void      femdarr7_acos_to(  femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_tan(      femdarr7_t* arr);
  void      femdarr7_tan_to(   femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_sin(      femdarr7_t* arr);
  void      femdarr7_sin_to(   femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_cos(      femdarr7_t* arr);
  void      femdarr7_cos_to(   femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_logb(     femdarr7_t* arr, double base);
  void      femdarr7_logb_to(  femdarr7_t* arr, double base, femdarr7_t* res);
  femdarr7_t femdarr7_log10(    femdarr7_t* arr);
  void      femdarr7_log10_to( femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_log(      femdarr7_t* arr);
  void      femdarr7_log_to(   femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_exp(      femdarr7_t* arr);
  void      femdarr7_exp_to(   femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_cbrt(     femdarr7_t* arr);
  void      femdarr7_cbrt_to(  femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_sqrt(     femdarr7_t* arr);
  void      femdarr7_sqrt_to(  femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_pow(      femdarr7_t* arr, double e);
  void      femdarr7_pow_to(   femdarr7_t* arr, double e, femdarr7_t* res);
  
  
  # From ../../../include/oti/static/mdnum7/array/gauss/base.h
  
  void      femdarr7_get_order_im_to( ord_t order, femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_get_order_im(    ord_t order, femdarr7_t* arr);
  femdarr7_t femdarr7_get_deriv(   imdir_t idx, ord_t order, femdarr7_t* arr);
  void      femdarr7_get_deriv_to(imdir_t idx, ord_t order, femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_get_im(      imdir_t idx, ord_t order, femdarr7_t* arr);
  void      femdarr7_get_im_to(   imdir_t idx, ord_t order, femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_truncate_im(   imdir_t idx, ord_t order, femdarr7_t* arr);
  void      femdarr7_truncate_im_to(imdir_t idx, ord_t order, femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_copy(   femdarr7_t* src);
  void      femdarr7_copy_to(femdarr7_t* src, femdarr7_t* res);
  femdarr7_t femdarr7_get_im(    imdir_t idx, ord_t order, femdarr7_t* arr);
  void      femdarr7_get_im_to( imdir_t idx, ord_t order, femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_get_deriv(    imdir_t idx, ord_t order, femdarr7_t* arr);
  void      femdarr7_get_deriv_to( imdir_t idx, ord_t order, femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_extract_im(    imdir_t idx, ord_t order, femdarr7_t* arr);
  void      femdarr7_extract_im_to( imdir_t idx, ord_t order, femdarr7_t* arr,  femdarr7_t* res);
  femdarr7_t femdarr7_extract_deriv(    imdir_t idx, ord_t order, femdarr7_t* arr);
  void      femdarr7_extract_deriv_to( imdir_t idx, ord_t order, femdarr7_t* arr, femdarr7_t* res);
  mdarr7_t   femdarr7_get_item_k(  femdarr7_t* arr, uint64_t k);
  femdnum7_t  femdarr7_get_item_ij( femdarr7_t* arr, uint64_t i, uint64_t j);
  mdnum7_t femdarr7_get_item_ijk(femdarr7_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void femdarr7_get_item_ij_to(  femdarr7_t* arr, uint64_t i, uint64_t j,
                                 femdnum7_t* res);
  void femdarr7_get_item_k_to(   femdarr7_t* arr, uint64_t k,
                                  mdarr7_t* res);
  void femdarr7_get_item_ijk_to( femdarr7_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                mdnum7_t* res);
  femdarr7_t femdarr7_get_slice(femdarr7_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      femdarr7_get_slice_to(femdarr7_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr7_t* res);
  void femdarr7_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              femdarr7_t* res);
  void femdarr7_set_item_ij_o(  mdnum7_t* elm, uint64_t i, uint64_t j,
                               femdarr7_t* res);
  void femdarr7_set_item_ij_f(  femdnum7_t* elm, uint64_t i, uint64_t j,
                              femdarr7_t* res);
  void femdarr7_set_item_k_r(    coeff_t  elm, uint64_t k,
                              femdarr7_t* res);
  void femdarr7_set_item_k_o(  mdnum7_t* elm, uint64_t k,
                              femdarr7_t* res);
  void femdarr7_set_item_k_R(    mdarr7_t* elm, uint64_t k,
                            femdarr7_t* res);
  void femdarr7_set_item_k_O(    mdarr7_t* elm, uint64_t k,
                            femdarr7_t* res);
  void femdarr7_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr7_t* res);
  void femdarr7_set_item_ijk_o( mdnum7_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr7_t* res);
  void femdarr7_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr7_t* res);
  void femdarr7_set_slice_o( mdnum7_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr7_t* res);
  void femdarr7_set_slice_f( femdnum7_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr7_t* res);
  void femdarr7_set_slice_O( mdarr7_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr7_t* res);
  void femdarr7_set_slice_F( femdarr7_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr7_t* res);
  void femdarr7_set_all_o( mdnum7_t* num, femdarr7_t* arr );
  void femdarr7_set_all_r(   coeff_t  num, femdarr7_t* arr );
  void femdarr7_set_all_f(  femdnum7_t* num, femdarr7_t* arr );
  void femdarr7_set_r(    coeff_t src, femdarr7_t* res );
  void femdarr7_set_o( mdnum7_t* src, femdarr7_t* res );
  void femdarr7_set_f(  femdnum7_t* src, femdarr7_t* res );
  void femdarr7_set_R(    darr_t* src, femdarr7_t* res );
  void femdarr7_set_O(   mdarr7_t* src, femdarr7_t* res );
  void femdarr7_set_F( femdarr7_t* src, femdarr7_t* res );
  femdarr7_t femdarr7_eye( uint64_t size,  uint64_t nip);
  femdarr7_t femdarr7_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  femdarr7_t femdarr7_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  femdarr7_t femdarr7_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void femdarr7_free(femdarr7_t* arr);
  femdarr7_t femdarr7_init();
  ord_t femdarr7_get_order(femdarr7_t* arr);
  
  
  # From ../../../include/oti/static/mdnum7/array/gauss/utils.h
  
  void femdarr7_dimCheck_FF_samesize(femdarr7_t* arr1, femdarr7_t* arr2, femdnum7_t* res);
  void femdarr7_dimCheck_OF_samesize(  mdarr7_t* arr1, femdarr7_t* arr2, femdnum7_t* res);
  void femdarr7_dimCheck_RF_samesize(   darr_t* arr1, femdarr7_t* arr2, femdnum7_t* res);
  void femdarr7_dimCheck_FF_elementwise(femdarr7_t* arr1, femdarr7_t* arr2, femdarr7_t* res);
  void femdarr7_dimCheck_OF_elementwise(  mdarr7_t* arr1, femdarr7_t* arr2, femdarr7_t* res);
  void femdarr7_dimCheck_RF_elementwise(   darr_t* arr1, femdarr7_t* arr2, femdarr7_t* res);
  void femdarr7_dimCheck_fF_elementwise( femdnum7_t* num1, femdarr7_t* arr2, femdarr7_t* res);
  void femdarr7_dimCheck_Ff_elementwise(femdarr7_t* arr1,  femdnum7_t* num2, femdarr7_t* res);
  void femdarr7_dimCheck_FF_matmul( femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  void femdarr7_dimCheck_OF_matmul(   mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  void femdarr7_dimCheck_RF_matmul(    darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  void femdarr7_dimCheck_FO_matmul( femdarr7_t* lhs,   mdarr7_t* rhs, femdarr7_t* res);
  void femdarr7_dimCheck_FR_matmul( femdarr7_t* lhs,    darr_t* rhs, femdarr7_t* res);
  void femdarr7_dimCheck_F_squareness( femdarr7_t* arr1, femdarr7_t* res);
  void femdarr7_dimCheck_F_transpose( femdarr7_t* arr1, femdarr7_t* res);
  void femdarr7_dimCheck_FfO_integrate(femdarr7_t* arr, femdnum7_t* num,mdarr7_t* res);
  void femdarr7_get_active_bases(femdarr7_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum7/array/gauss/algebra.h
  
  femdarr7_t femdarr7_neg(    femdarr7_t* arr);
  void      femdarr7_neg_to( femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t femdarr7_sum_FF(   femdarr7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_sum_FF_to(femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sum_fF(    femdnum7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_sum_fF_to( femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sum_OF(     mdarr7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_sum_OF_to(  mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sum_RF(      darr_t* lhs, femdarr7_t* rhs);
  void      femdarr7_sum_RF_to(   darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sum_oF(   mdnum7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_sum_oF_to(mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sum_rF(     coeff_t  lhs, femdarr7_t* rhs);
  void      femdarr7_sum_rF_to(  coeff_t  lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sub_FF(    femdarr7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_sub_FF_to( femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sub_fF(    femdnum7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_sub_fF_to( femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sub_Ff(    femdarr7_t* lhs, femdnum7_t* rhs);
  void      femdarr7_sub_Ff_to( femdarr7_t* lhs, femdnum7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sub_OF(      mdarr7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_sub_OF_to(   mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sub_FO(    femdarr7_t* lhs,   mdarr7_t* rhs);
  void      femdarr7_sub_FO_to( femdarr7_t* lhs,   mdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sub_RF(       darr_t* lhs, femdarr7_t* rhs);
  void      femdarr7_sub_RF_to(    darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sub_FR(    femdarr7_t* lhs,    darr_t* rhs);
  void      femdarr7_sub_FR_to( femdarr7_t* lhs,    darr_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sub_oF(    mdnum7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_sub_oF_to( mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sub_Fo(    femdarr7_t* lhs, mdnum7_t* rhs);
  void      femdarr7_sub_Fo_to( femdarr7_t* lhs, mdnum7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sub_rF(      coeff_t  lhs, femdarr7_t* rhs);
  void      femdarr7_sub_rF_to(    coeff_t lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_sub_Fr(    femdarr7_t* lhs,   coeff_t  rhs);
  void      femdarr7_sub_Fr_to( femdarr7_t* lhs,   coeff_t  rhs, femdarr7_t* res);
  femdarr7_t femdarr7_mul_FF(   femdarr7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_mul_FF_to(femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_mul_fF(    femdnum7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_mul_fF_to( femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_mul_OF(     mdarr7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_mul_OF_to(  mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_mul_RF(      darr_t* lhs, femdarr7_t* rhs);
  void      femdarr7_mul_RF_to(   darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_mul_oF(   mdnum7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_mul_oF_to(mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_mul_rF(     coeff_t  lhs, femdarr7_t* rhs);
  void      femdarr7_mul_rF_to(  coeff_t  lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_div_FF(    femdarr7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_div_FF_to( femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_div_fF(     femdnum7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_div_fF_to(  femdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_div_Ff(    femdarr7_t* lhs,  femdnum7_t* rhs);
  void      femdarr7_div_Ff_to( femdarr7_t* lhs,  femdnum7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_div_OF(      mdarr7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_div_OF_to(   mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_div_FO(    femdarr7_t* lhs,   mdarr7_t* rhs);
  void      femdarr7_div_FO_to( femdarr7_t* lhs,   mdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_div_RF(       darr_t* lhs, femdarr7_t* rhs);
  void      femdarr7_div_RF_to(    darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_div_FR(    femdarr7_t* lhs,    darr_t* rhs);
  void      femdarr7_div_FR_to( femdarr7_t* lhs,    darr_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_div_oF(    mdnum7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_div_oF_to( mdnum7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_div_Fo(    femdarr7_t* lhs, mdnum7_t* rhs);
  void      femdarr7_div_Fo_to( femdarr7_t* lhs, mdnum7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_div_rF(      coeff_t  lhs, femdarr7_t* rhs);
  void      femdarr7_div_rF_to(    coeff_t lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_div_Fr(    femdarr7_t* lhs,   coeff_t  rhs);
  void      femdarr7_div_Fr_to( femdarr7_t* lhs,   coeff_t  rhs, femdarr7_t* res);
  mdarr7_t femdarr7_integrate(    femdarr7_t* arr, femdnum7_t* w);
  void    femdarr7_integrate_to( femdarr7_t* arr, femdnum7_t* w, mdarr7_t* res);
  femdnum7_t femdarr7_dotproduct_FF(    femdarr7_t* lhs, femdarr7_t* rhs);
  void     femdarr7_dotproduct_FF_to( femdarr7_t* lhs, femdarr7_t* rhs, femdnum7_t* res);
  femdnum7_t femdarr7_dotproduct_OF(      mdarr7_t* lhs, femdarr7_t* rhs);
  void     femdarr7_dotproduct_OF_to(   mdarr7_t* lhs, femdarr7_t* rhs, femdnum7_t* res);
  femdnum7_t femdarr7_dotproduct_RF(       darr_t* lhs, femdarr7_t* rhs);
  void     femdarr7_dotproduct_RF_to(    darr_t* lhs, femdarr7_t* rhs, femdnum7_t* res);
  femdarr7_t femdarr7_matmul_FF(    femdarr7_t* lhs, femdarr7_t* rhs);
  void      femdarr7_matmul_FF_to( femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_matmul_OF(    mdarr7_t*   lhs, femdarr7_t* rhs);
  void      femdarr7_matmul_OF_to( mdarr7_t*   lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_matmul_FO(    femdarr7_t* lhs, mdarr7_t*   rhs);
  void      femdarr7_matmul_FO_to( femdarr7_t* lhs, mdarr7_t*   rhs, femdarr7_t* res);
  femdarr7_t femdarr7_matmul_RF(    darr_t*    lhs, femdarr7_t* rhs);
  void      femdarr7_matmul_RF_to( darr_t*    lhs, femdarr7_t* rhs, femdarr7_t* res);
  femdarr7_t femdarr7_matmul_FR(    femdarr7_t* lhs, darr_t*    rhs);
  void      femdarr7_matmul_FR_to( femdarr7_t* lhs, darr_t*    rhs, femdarr7_t* res);
  femdnum7_t femdarr7_det(   femdarr7_t* arr);
  void     femdarr7_det_to(femdarr7_t* arr, femdnum7_t* res);
  femdnum7_t femdarr7_norm(     femdarr7_t* arr);
  void     femdarr7_norm_to(  femdarr7_t* arr, femdnum7_t* res);
  femdnum7_t femdarr7_pnorm(    femdarr7_t* arr, coeff_t p);
  void     femdarr7_pnorm_to( femdarr7_t* arr, coeff_t p, femdnum7_t* res);
  femdarr7_t   femdarr7_invert(    femdarr7_t* arr);
  void        femdarr7_invert_to( femdarr7_t* arr, femdarr7_t* res);
  femdarr7_t   femdarr7_transpose(   femdarr7_t* arr);
  void        femdarr7_transpose_to(femdarr7_t* arr, femdarr7_t* res);
  
  