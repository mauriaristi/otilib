cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/mdnum6/scalar/structures.h
  
  ctypedef struct  mdnum6_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
    coeff_t e6;
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
    coeff_t e12345;
    coeff_t e12346;
    coeff_t e12356;
    coeff_t e12456;
    coeff_t e13456;
    coeff_t e23456;
    coeff_t e123456;
  # } mdnum6_t;
  
  
  # From ../../../include/oti/static/mdnum6/array/structures.h
  
  ctypedef struct  mdarr6_t : # {
      mdnum6_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } mdarr6_t;
  
  
  # From ../../../include/oti/static/mdnum6/scalar/gauss/structures.h
  
  ctypedef struct  femdnum6_t: # {
      mdnum6_t*  p_data;
      uint64_t    nip;
  # } femdnum6_t;
  
  
  # From ../../../include/oti/static/mdnum6/array/gauss/structures.h
  
  ctypedef struct  femdarr6_t: # {
      mdarr6_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } femdarr6_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/mdnum6/scalar/functions.h
  
  mdnum6_t mdnum6_atanh(mdnum6_t* num);
  void mdnum6_atanh_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_asinh(mdnum6_t* num);
  void mdnum6_asinh_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_acosh(mdnum6_t* num);
  void mdnum6_acosh_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_tanh(mdnum6_t* num);
  void mdnum6_tanh_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_sqrt(mdnum6_t* num);
  void mdnum6_sqrt_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_cbrt(mdnum6_t* num);
  void mdnum6_cbrt_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_cosh(mdnum6_t* num);
  void mdnum6_cosh_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_sinh(mdnum6_t* num);
  void mdnum6_sinh_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_asin(mdnum6_t* num);
  void mdnum6_asin_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_acos(mdnum6_t* num);
  void mdnum6_acos_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_atan(mdnum6_t* num);
  void mdnum6_atan_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_tan(mdnum6_t* num);
  void mdnum6_tan_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_cos(mdnum6_t* num);
  void mdnum6_cos_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_sin(mdnum6_t* num );
  void mdnum6_sin_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_logb(mdnum6_t* num, double base);
  void mdnum6_logb_to(mdnum6_t* num, double base, mdnum6_t* res);
  mdnum6_t mdnum6_log10(mdnum6_t* num);
  void mdnum6_log10_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_log(mdnum6_t* num);
  void mdnum6_log_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_exp(mdnum6_t* num);
  void mdnum6_exp_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_pow(mdnum6_t* num, double e);
  void mdnum6_pow_to(mdnum6_t* num, coeff_t e, mdnum6_t* res);
  
  
  # From ../../../include/oti/static/mdnum6/scalar/base.h
  
  void mdnum6_set_im_o(mdnum6_t* num, imdir_t idx, ord_t order, mdnum6_t* res);
  void mdnum6_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum6_t* res);
  void mdnum6_set_deriv_o(mdnum6_t* num, imdir_t idx, ord_t order, mdnum6_t* res);
  void mdnum6_extract_im_to( imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_extract_im(imdir_t idx, ord_t order, mdnum6_t* num);
  mdnum6_t mdnum6_extract_deriv(imdir_t idx, ord_t order, mdnum6_t* num);
  void mdnum6_extract_deriv_to(imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res);
  void mdnum6_get_im_to_o(imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_get_im_o(imdir_t idx, ord_t order, mdnum6_t* num);
  void mdnum6_get_im_to_r(imdir_t idx, ord_t order, mdnum6_t* num, coeff_t* res);
  ord_t mdnum6_get_order(mdnum6_t* lhs);
  mdnum6_t mdnum6_get_deriv_o( imdir_t idx, ord_t order, mdnum6_t* num);
  void mdnum6_get_deriv_to( imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res);
  void mdnum6_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum6_t* res);
  mdnum6_t mdnum6_init();
  ndir_t mdnum6_get_ndir_order(ord_t order, mdnum6_t* num);
  ndir_t mdnum6_get_ndir_total(mdnum6_t* num);
  coeff_t* mdnum6_get_order_address(ord_t order, mdnum6_t* num);
  mdnum6_t mdnum6_create_r(  coeff_t lhs);
  void mdnum6_set_r(  coeff_t lhs, mdnum6_t* res);
  void mdnum6_set_o(  mdnum6_t* lhs, mdnum6_t* res);
  mdnum6_t mdnum6_get_order_im(ord_t order, mdnum6_t* lhs);
  void mdnum6_get_order_im_to(ord_t order, mdnum6_t* lhs, mdnum6_t* res);
  coeff_t mdnum6_get_item(imdir_t idx, ord_t order, mdnum6_t* lhs);
  coeff_t mdnum6_get_deriv(imdir_t idx, ord_t order, mdnum6_t* lhs);
  void mdnum6_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum6_t* x);
  mdnum6_t mdnum6_copy(  mdnum6_t* lhs);
  void mdnum6_copy_to(  mdnum6_t* lhs, mdnum6_t* res);
  mdnum6_t mdnum6_taylor_integrate(coeff_t* deltas,mdnum6_t* lhs);
  void mdnum6_taylor_integrate_to(coeff_t* deltas,mdnum6_t* lhs, mdnum6_t* res);
  mdnum6_t mdnum6_truncate_im(imdir_t idx, ord_t order, mdnum6_t* lhs);
  void mdnum6_truncate_im_to(imdir_t idx, ord_t order, mdnum6_t* lhs, mdnum6_t* res);
  void mdnum6_print(  mdnum6_t* lhs);
  imdir_t mdnum6_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/mdnum6/scalar/utils.h
  
  void mdnum6_get_active_bases(mdnum6_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/mdnum6/scalar/algebra.h
  
  mdnum6_t mdnum6_abs(mdnum6_t* num);
  mdnum6_t mdnum6_div_ro(coeff_t num, mdnum6_t* den);
  mdnum6_t mdnum6_div_oo(mdnum6_t* num, mdnum6_t* den);
  mdnum6_t mdnum6_div_or(mdnum6_t* num, coeff_t val);
  void mdnum6_div_ro_to(coeff_t num, mdnum6_t* den, mdnum6_t* res);
  void mdnum6_div_oo_to(mdnum6_t* num, mdnum6_t* den, mdnum6_t* res);
  void mdnum6_div_or_to(mdnum6_t* num, coeff_t val, mdnum6_t* res);
  void mdnum6_abs_to(mdnum6_t* num, mdnum6_t* res);
  mdnum6_t mdnum6_neg(  mdnum6_t* lhs);
  void mdnum6_neg_to(  mdnum6_t* lhs, mdnum6_t* res);
  mdnum6_t mdnum6_sum_oo(  mdnum6_t* lhs,  mdnum6_t* rhs);
  void mdnum6_sum_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res);
  mdnum6_t mdnum6_sum_ro(  coeff_t lhs,  mdnum6_t* rhs);
  void mdnum6_sum_ro_to(  coeff_t lhs,  mdnum6_t* rhs, mdnum6_t* res);
  mdnum6_t mdnum6_sub_oo(  mdnum6_t* lhs,  mdnum6_t* rhs);
  void mdnum6_sub_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res);
  mdnum6_t mdnum6_sub_ro(  coeff_t lhs,  mdnum6_t* rhs);
  void mdnum6_sub_ro_to(  coeff_t lhs,  mdnum6_t* rhs, mdnum6_t* res);
  mdnum6_t mdnum6_sub_or(  mdnum6_t* lhs,  coeff_t rhs);
  void mdnum6_sub_or_to(  mdnum6_t* lhs,  coeff_t rhs, mdnum6_t* res);
  mdnum6_t mdnum6_mul_oo(  mdnum6_t* lhs,  mdnum6_t* rhs);
  void mdnum6_mul_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res);
  mdnum6_t mdnum6_mul_ro(  coeff_t lhs,  mdnum6_t* rhs);
  void mdnum6_mul_ro_to(  coeff_t lhs,  mdnum6_t* rhs, mdnum6_t* res);
  mdnum6_t mdnum6_trunc_mul_oo(  mdnum6_t* lhs,  mdnum6_t* rhs);
  void mdnum6_trunc_mul_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res);
  mdnum6_t mdnum6_gem_oo(  mdnum6_t* a,  mdnum6_t* b,  mdnum6_t* c);
  void mdnum6_gem_oo_to(  mdnum6_t* a,  mdnum6_t* b,  mdnum6_t* c, mdnum6_t* res);
  mdnum6_t mdnum6_gem_ro(  coeff_t a,  mdnum6_t* b,  mdnum6_t* c);
  void mdnum6_gem_ro_to(  coeff_t a,  mdnum6_t* b,  mdnum6_t* c, mdnum6_t* res);
  void mdnum6_trunc_gem_oo_to( ord_t ord_lhs,  mdnum6_t* a,  ord_t ord_rhs,  mdnum6_t* b,  mdnum6_t* c, mdnum6_t* res);
  void mdnum6_trunc_sum_oo_to(ord_t order, mdnum6_t* lhs,mdnum6_t* rhs, mdnum6_t* res);
  void mdnum6_trunc_sub_oo_to(ord_t order, mdnum6_t* lhs,mdnum6_t* rhs, mdnum6_t* res);
  mdnum6_t mdnum6_feval(coeff_t* feval_re, mdnum6_t* x);
  void mdnum6_feval_to(coeff_t* feval_re, mdnum6_t* x, mdnum6_t* res);
  
  
  # From ../../../include/oti/static/mdnum6/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum6/scalar/gauss/functions.h
  
  femdnum6_t femdnum6_atanh(    femdnum6_t* num);
  void     femdnum6_atanh_to( femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_asinh(    femdnum6_t* num);
  void     femdnum6_asinh_to( femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_acosh(    femdnum6_t* num);
  void     femdnum6_acosh_to( femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_tanh(     femdnum6_t* num);
  void     femdnum6_tanh_to(  femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_cosh(     femdnum6_t* num);
  void     femdnum6_cosh_to(  femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_sinh(     femdnum6_t* num);
  void     femdnum6_sinh_to(  femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_asin(     femdnum6_t* num);
  void     femdnum6_asin_to(  femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_acos(     femdnum6_t* num);
  void     femdnum6_acos_to(  femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_atan(     femdnum6_t* num);
  void     femdnum6_atan_to(  femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_tan(      femdnum6_t* num);
  void     femdnum6_tan_to(   femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_cos(      femdnum6_t* num);
  void     femdnum6_cos_to(   femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_sin(      femdnum6_t* num);
  void     femdnum6_sin_to(   femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_logb(     femdnum6_t* num, double base);
  void     femdnum6_logb_to(  femdnum6_t* num, double base, femdnum6_t* res);
  femdnum6_t femdnum6_log10(    femdnum6_t* num);
  void     femdnum6_log10_to( femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_log(      femdnum6_t* num);
  void     femdnum6_log_to(   femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_exp(      femdnum6_t* num);
  void     femdnum6_exp_to(   femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_cbrt(     femdnum6_t* num);
  void     femdnum6_cbrt_to(  femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_sqrt(     femdnum6_t* num);
  void     femdnum6_sqrt_to(  femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_pow(      femdnum6_t* num, double e);
  void     femdnum6_pow_to(   femdnum6_t* num, double e, femdnum6_t* res);
  mdnum6_t femdnum6_integrate(       femdnum6_t* num, femdnum6_t* w);
  void      femdnum6_integrate_to(    femdnum6_t* num, femdnum6_t* w, mdnum6_t* res);
  mdnum6_t femdnum6_integrate_f(     femdnum6_t* num, femdnum6_t* w);
  void      femdnum6_integrate_f_to(  femdnum6_t* num, femdnum6_t* w, mdnum6_t* res);
  mdnum6_t femdnum6_integrate_r(       coeff_t num, femdnum6_t* w);
  void      femdnum6_integrate_r_to(    coeff_t num, femdnum6_t* w, mdnum6_t* res);
  mdnum6_t femdnum6_integrate_o(    mdnum6_t* num, femdnum6_t* w);
  void      femdnum6_integrate_o_to( mdnum6_t* num, femdnum6_t* w, mdnum6_t* res);
  
  
  # From ../../../include/oti/static/mdnum6/scalar/gauss/base.h
  
  void     femdnum6_get_order_im_to( ord_t order, femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_get_order_im(    ord_t order, femdnum6_t* num);
  femdnum6_t femdnum6_get_im(    imdir_t idx, ord_t order, femdnum6_t* num);
  void     femdnum6_get_im_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_get_deriv(    imdir_t idx, ord_t order, femdnum6_t* num);
  void     femdnum6_get_deriv_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res);
  void femdnum6_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum6_t* num);
  void femdnum6_set_im_o( mdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num);
  void femdnum6_set_im_f(  femdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num);
  void femdnum6_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum6_t* num);
  void femdnum6_set_deriv_o( mdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num);
  void femdnum6_set_deriv_f(  femdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num);
  femdnum6_t femdnum6_extract_im(    imdir_t idx, ord_t order, femdnum6_t* num);
  void     femdnum6_extract_im_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_extract_deriv(    imdir_t idx, ord_t order, femdnum6_t* num);
  void     femdnum6_extract_deriv_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_truncate_im(    imdir_t idx, ord_t order, femdnum6_t* num);
  void     femdnum6_truncate_im_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_copy(    femdnum6_t* src);
  void     femdnum6_copy_to( femdnum6_t* src, femdnum6_t* dst);
  void femdnum6_set_r(    coeff_t num, femdnum6_t* res);
  void femdnum6_set_o( mdnum6_t* num, femdnum6_t* res);
  void femdnum6_set_f(  femdnum6_t* num, femdnum6_t* res);
  void femdnum6_set_item_k_r(   coeff_t  num, uint64_t k, femdnum6_t* res);
  void femdnum6_set_item_k_o( mdnum6_t* num, uint64_t k, femdnum6_t* res);
  mdnum6_t femdnum6_get_item_k(   femdnum6_t* num, uint64_t k);
  void      femdnum6_get_item_k_to(femdnum6_t* num, uint64_t k, mdnum6_t* res);
  femdnum6_t femdnum6_zeros(uint64_t nIntPts);
  femdnum6_t femdnum6_createEmpty(uint64_t nIntPts);
  femdnum6_t femdnum6_empty_like(femdnum6_t* arr);
  void femdnum6_free(femdnum6_t* num);
  ord_t femdnum6_get_order( femdnum6_t* num );
  femdnum6_t femdnum6_init();
  
  
  # From ../../../include/oti/static/mdnum6/scalar/gauss/utils.h
  
  void femdnum6_dimCheck(femdnum6_t* arr1,femdnum6_t* arr2);
  void femdnum6_get_active_bases(femdnum6_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum6/scalar/gauss/algebra.h
  
  femdnum6_t femdnum6_neg(   femdnum6_t* num);
  void     femdnum6_neg_to(femdnum6_t* num, femdnum6_t* res);
  femdnum6_t femdnum6_sum_ff(   femdnum6_t* lhs, femdnum6_t* rhs);
  void     femdnum6_sum_ff_to(femdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_sum_of(   mdnum6_t* lhs, femdnum6_t* rhs);
  void     femdnum6_sum_of_to(mdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_sum_rf(   coeff_t lhs, femdnum6_t* rhs);
  void     femdnum6_sum_rf_to(coeff_t lhs, femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_sub_ff(     femdnum6_t* lhs,  femdnum6_t* rhs);
  void     femdnum6_sub_ff_to(  femdnum6_t* lhs,  femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_sub_of(    mdnum6_t* lhs,  femdnum6_t* rhs);
  void     femdnum6_sub_of_to( mdnum6_t* lhs,  femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_sub_fo(     femdnum6_t* lhs, mdnum6_t* rhs);
  void     femdnum6_sub_fo_to(  femdnum6_t* lhs, mdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_sub_rf(       coeff_t lhs,  femdnum6_t* rhs);
  void     femdnum6_sub_rf_to(    coeff_t lhs,  femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_sub_fr(     femdnum6_t* lhs,    coeff_t rhs);
  void     femdnum6_sub_fr_to(  femdnum6_t* lhs,    coeff_t rhs, femdnum6_t* res);
  femdnum6_t femdnum6_mul_ff(   femdnum6_t* lhs, femdnum6_t* rhs);
  void     femdnum6_mul_ff_to(femdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_mul_of(   mdnum6_t* lhs, femdnum6_t* rhs);
  void     femdnum6_mul_of_to(mdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_mul_rf(   coeff_t lhs, femdnum6_t* rhs);
  void     femdnum6_mul_rf_to(coeff_t lhs, femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_div_ff(     femdnum6_t* lhs,  femdnum6_t* rhs);
  void     femdnum6_div_ff_to(  femdnum6_t* lhs,  femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_div_of(    mdnum6_t* lhs,  femdnum6_t* rhs);
  void     femdnum6_div_of_to( mdnum6_t* lhs,  femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_div_fo(     femdnum6_t* lhs, mdnum6_t* rhs);
  void     femdnum6_div_fo_to(  femdnum6_t* lhs, mdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_div_rf(       coeff_t lhs,  femdnum6_t* rhs);
  void     femdnum6_div_rf_to(    coeff_t lhs,  femdnum6_t* rhs, femdnum6_t* res);
  femdnum6_t femdnum6_div_fr(     femdnum6_t* lhs,    coeff_t rhs);
  void     femdnum6_div_fr_to(  femdnum6_t* lhs,    coeff_t rhs, femdnum6_t* res);
  
  
  # From ../../../include/oti/static/mdnum6/array/functions.h
  
  mdarr6_t mdarr6_atanh(   mdarr6_t* arr);
  void    mdarr6_atanh_to(mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_asinh(   mdarr6_t* arr);
  void    mdarr6_asinh_to(mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_acosh(   mdarr6_t* arr);
  void    mdarr6_acosh_to(mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_tanh(    mdarr6_t* arr);
  void    mdarr6_tanh_to( mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_cbrt(    mdarr6_t* arr);
  void    mdarr6_cbrt_to( mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_sqrt(    mdarr6_t* arr);
  void    mdarr6_sqrt_to( mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_cosh(    mdarr6_t* arr);
  void    mdarr6_cosh_to( mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_sinh(    mdarr6_t* arr);
  void    mdarr6_sinh_to( mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_asin(    mdarr6_t* arr);
  void    mdarr6_asin_to( mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_acos(    mdarr6_t* arr);
  void    mdarr6_acos_to( mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_atan(    mdarr6_t* arr);
  void    mdarr6_atan_to( mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_tan(     mdarr6_t* arr);
  void    mdarr6_tan_to(  mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_cos(     mdarr6_t* arr);
  void    mdarr6_cos_to(  mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_sin(     mdarr6_t* arr);
  void    mdarr6_sin_to(  mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_logb(    mdarr6_t* arr, double base);
  void    mdarr6_logb_to( mdarr6_t* arr, double base, mdarr6_t* res);
  mdarr6_t mdarr6_log10(   mdarr6_t* arr);
  void    mdarr6_log10_to(mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_log(     mdarr6_t* arr);
  void    mdarr6_log_to(  mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_exp(     mdarr6_t* arr);
  void    mdarr6_exp_to(  mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_pow(     mdarr6_t* arr, double e);
  void    mdarr6_pow_to(  mdarr6_t* arr, double e, mdarr6_t* res);
  
  
  # From ../../../include/oti/static/mdnum6/array/algebra_elementwise.h
  
  mdarr6_t mdarr6_neg(mdarr6_t* arr);
  void mdarr6_neg_to(mdarr6_t* rhs, mdarr6_t* res);
  mdarr6_t mdarr6_sum_OO(mdarr6_t*   lhs, mdarr6_t* rhs);
  mdarr6_t mdarr6_sum_RO(darr_t*    lhs, mdarr6_t* rhs);
  mdarr6_t mdarr6_sum_oO(mdnum6_t* lhs, mdarr6_t* rhs);
  mdarr6_t mdarr6_sum_rO(coeff_t    lhs, mdarr6_t* rhs);
  void mdarr6_sum_OO_to(mdarr6_t*   lhs, mdarr6_t* rhs, mdarr6_t* res);
  void mdarr6_sum_RO_to(darr_t*    lhs, mdarr6_t* rhs, mdarr6_t* res);
  void mdarr6_sum_oO_to(mdnum6_t* lhs, mdarr6_t* rhs, mdarr6_t* res);
  void mdarr6_sum_rO_to(coeff_t    lhs, mdarr6_t* rhs, mdarr6_t* res);
  void mdarr6_trunc_sum_OO_to(ord_t order, mdarr6_t* arr1, mdarr6_t* arr2, mdarr6_t* res);
  mdarr6_t mdarr6_sub_OO(mdarr6_t*   lhs, mdarr6_t*   rhs);
  mdarr6_t mdarr6_sub_RO(darr_t*    lhs, mdarr6_t*   rhs);
  mdarr6_t mdarr6_sub_OR(mdarr6_t*   lhs, darr_t*    rhs);
  mdarr6_t mdarr6_sub_oO(mdnum6_t* lhs, mdarr6_t*   rhs);
  mdarr6_t mdarr6_sub_Oo(mdarr6_t*   lhs, mdnum6_t* rhs);
  mdarr6_t mdarr6_sub_rO(coeff_t    lhs, mdarr6_t*   rhs);
  mdarr6_t mdarr6_sub_Or(mdarr6_t*   lhs, coeff_t    rhs);
  void mdarr6_sub_OO_to( mdarr6_t*   lhs, mdarr6_t*   rhs, mdarr6_t* res);
  void mdarr6_sub_RO_to( darr_t*    lhs, mdarr6_t*   rhs, mdarr6_t* res);
  void mdarr6_sub_OR_to( mdarr6_t*   lhs, darr_t*    rhs, mdarr6_t* res);
  void mdarr6_sub_oO_to( mdnum6_t* lhs, mdarr6_t*   rhs, mdarr6_t* res);
  void mdarr6_sub_Oo_to( mdarr6_t*   lhs, mdnum6_t* rhs, mdarr6_t* res);
  void mdarr6_sub_rO_to( coeff_t    lhs, mdarr6_t*   rhs, mdarr6_t* res);
  void mdarr6_sub_Or_to( mdarr6_t*   lhs, coeff_t    rhs, mdarr6_t* res);
  void mdarr6_trunc_sub_OO_to(ord_t order, mdarr6_t* arr1, mdarr6_t* arr2, mdarr6_t* res);
  mdarr6_t mdarr6_mul_OO(mdarr6_t*   lhs, mdarr6_t* rhs);
  mdarr6_t mdarr6_mul_RO(darr_t*    lhs, mdarr6_t* rhs);
  mdarr6_t mdarr6_mul_oO(mdnum6_t* lhs, mdarr6_t* rhs);
  mdarr6_t mdarr6_mul_rO(coeff_t    lhs, mdarr6_t* rhs);
  void mdarr6_mul_OO_to(mdarr6_t*   lhs, mdarr6_t* rhs, mdarr6_t* res);
  void mdarr6_mul_RO_to(darr_t*    lhs, mdarr6_t* rhs, mdarr6_t* res);
  void mdarr6_mul_oO_to(mdnum6_t* lhs, mdarr6_t* rhs, mdarr6_t* res);
  void mdarr6_mul_rO_to(coeff_t    lhs, mdarr6_t* rhs, mdarr6_t* res);
  void mdarr6_gem_OO_to(  mdarr6_t* arr1, mdarr6_t* arr2, mdarr6_t* arr3, mdarr6_t* res);
  void mdarr6_gem_oO_to(mdnum6_t* arr1, mdarr6_t* arr2, mdarr6_t* arr3, mdarr6_t* res);
  mdarr6_t mdarr6_div_OO(mdarr6_t*   lhs, mdarr6_t*   rhs);
  mdarr6_t mdarr6_div_OR(mdarr6_t*   lhs, darr_t*    rhs);
  mdarr6_t mdarr6_div_RO(darr_t*    lhs, mdarr6_t*   rhs);
  mdarr6_t mdarr6_div_oO(mdnum6_t* lhs, mdarr6_t*   rhs);
  mdarr6_t mdarr6_div_Oo(mdarr6_t*   lhs, mdnum6_t* rhs);
  mdarr6_t mdarr6_div_rO(coeff_t    lhs, mdarr6_t*   rhs);
  mdarr6_t mdarr6_div_Or(mdarr6_t*   lhs, coeff_t    rhs);
  void mdarr6_div_OO_to(mdarr6_t*   lhs, mdarr6_t*   rhs, mdarr6_t* res);
  void mdarr6_div_RO_to(darr_t*    lhs, mdarr6_t*   rhs, mdarr6_t* res);
  void mdarr6_div_OR_to(mdarr6_t*   lhs, darr_t*    rhs, mdarr6_t* res);
  void mdarr6_div_oO_to(mdnum6_t* lhs, mdarr6_t*   rhs, mdarr6_t* res);
  void mdarr6_div_Oo_to(mdarr6_t*   lhs, mdnum6_t* rhs, mdarr6_t* res);
  void mdarr6_div_rO_to(coeff_t    lhs, mdarr6_t*   rhs, mdarr6_t* res);
  void mdarr6_div_Or_to(mdarr6_t*   lhs, coeff_t    rhs, mdarr6_t* res);
  
  
  # From ../../../include/oti/static/mdnum6/array/base.h
  
  void    mdarr6_taylor_integrate_to( coeff_t* deltas, mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_taylor_integrate(    coeff_t* deltas, mdarr6_t* arr);
  void    mdarr6_get_order_im_to( ord_t order, mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_get_order_im(    ord_t order, mdarr6_t* arr);
  void mdarr6_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr6_t* res);
  void mdarr6_set_slice_O( mdarr6_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr6_t* res);
  void mdarr6_set_slice_o( mdnum6_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr6_t* res);
  mdarr6_t mdarr6_get_slice( mdarr6_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void mdarr6_get_slice_to( mdarr6_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr6_t* res);
  mdarr6_t mdarr6_truncate_im(    imdir_t idx, ord_t order, mdarr6_t* arr);
  void    mdarr6_truncate_im_to( imdir_t idx, ord_t order, mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_extract_im(   imdir_t idx, ord_t order, mdarr6_t* arr);
  void    mdarr6_extract_im_to(imdir_t idx, ord_t order, mdarr6_t* arr, mdarr6_t* res);
  darr_t  mdarr6_get_deriv(    imdir_t idx, ord_t order, mdarr6_t* arr);
  void    mdarr6_get_deriv_to( imdir_t idx, ord_t order, mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_get_deriv_o(  imdir_t idx, ord_t order, mdarr6_t* arr);
  mdarr6_t mdarr6_extract_deriv(    imdir_t idx, ord_t order, mdarr6_t* arr);
  void    mdarr6_extract_deriv_to( imdir_t idx, ord_t order, mdarr6_t* arr, mdarr6_t* res);
  darr_t  mdarr6_get_im(   imdir_t idx, ord_t order, mdarr6_t* arr);
  mdarr6_t mdarr6_get_im_o( imdir_t idx, ord_t order, mdarr6_t* arr);
  void    mdarr6_get_im_to(imdir_t idx, ord_t order, mdarr6_t* arr, mdarr6_t* res);
  void    mdarr6_copy_to(mdarr6_t* arr, mdarr6_t* res);
  mdarr6_t mdarr6_copy(mdarr6_t* arr);
  void mdarr6_set_all_r( coeff_t num, mdarr6_t* arr);
  void mdarr6_set_item_i_r( coeff_t num, uint64_t i, mdarr6_t* arr);
  void mdarr6_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, mdarr6_t* arr);
  void mdarr6_set_r(   coeff_t  num,   mdarr6_t* arr);
  void mdarr6_set_o( mdnum6_t* num,   mdarr6_t* arr);
  void mdarr6_set_O(   mdarr6_t* arrin, mdarr6_t* arr);
  void mdarr6_set_all_o( mdnum6_t* src, mdarr6_t* arr);
  void mdarr6_set_item_i_o( mdnum6_t* num, uint64_t i, mdarr6_t* arr);
  void mdarr6_set_item_ij_o( mdnum6_t* num, uint64_t i, uint64_t j, mdarr6_t* arr);
  mdnum6_t mdarr6_get_item_i(    mdarr6_t* arr, uint64_t i);
  void      mdarr6_get_item_i_to( mdarr6_t* arr, uint64_t i,             mdnum6_t* res);
  mdnum6_t mdarr6_get_item_ij(   mdarr6_t* arr, uint64_t i, uint64_t j);
  void      mdarr6_get_item_ij_to(mdarr6_t* arr, uint64_t i, uint64_t j, mdnum6_t* res);
  mdarr6_t mdarr6_init();
  void mdarr6_free(mdarr6_t* arr);
  mdarr6_t mdarr6_empty_like(mdarr6_t* arr);
  mdarr6_t mdarr6_eye(uint64_t nrows);
  mdarr6_t mdarr6_ones(uint64_t nrows, uint64_t ncols);
  mdarr6_t mdarr6_zeros(uint64_t nrows, uint64_t ncols);
  mdarr6_t mdarr6_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/mdnum6/array/utils.h
  
  void mdarr6_dimCheck_OO_elementwise(mdarr6_t* arr1, mdarr6_t* arr2, mdarr6_t* res);
  void mdarr6_dimCheck_RO_elementwise(darr_t*  arr1, mdarr6_t* arr2, mdarr6_t* res);
  void mdarr6_dimCheck_OO_matmul(mdarr6_t* arr1, mdarr6_t* arr2, mdarr6_t* res);
  void mdarr6_dimCheck_RO_matmul(darr_t*  arr1, mdarr6_t* arr2, mdarr6_t* res);
  void mdarr6_dimCheck_OR_matmul(mdarr6_t* arr1, darr_t*  arr2, mdarr6_t* res);
  void mdarr6_dimCheck_O_squareness(mdarr6_t* arr1, mdarr6_t* res);
  void mdarr6_dimCheck_OO_samesize(mdarr6_t* arr1, mdarr6_t* res);
  void mdarr6_dimCheck_RO_samesize(darr_t* arr1, mdarr6_t* res);
  ord_t mdarr6_get_order(mdarr6_t* arr);
  void mdarr6_get_active_bases(mdarr6_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum6/array/algebra_matops.h
  
  mdnum6_t mdarr6_dotproduct_OO(    mdarr6_t* lhs, mdarr6_t* rhs);
  void      mdarr6_dotproduct_OO_to( mdarr6_t* lhs, mdarr6_t* rhs, mdnum6_t* res);
  mdnum6_t mdarr6_dotproduct_RO(     darr_t* lhs, mdarr6_t* rhs);
  void      mdarr6_dotproduct_RO_to(  darr_t* lhs, mdarr6_t* rhs, mdnum6_t* res);
  mdarr6_t mdarr6_matmul_OO(    mdarr6_t* lhs, mdarr6_t* rhs);
  mdarr6_t mdarr6_matmul_OR(    mdarr6_t* lhs,  darr_t* rhs);
  mdarr6_t mdarr6_matmul_RO(     darr_t* lhs, mdarr6_t* rhs);
  void    mdarr6_matmul_OO_to( mdarr6_t* lhs, mdarr6_t* rhs, mdarr6_t* res);
  void    mdarr6_matmul_OR_to( mdarr6_t* lhs,  darr_t* rhs, mdarr6_t* res);
  void    mdarr6_matmul_RO_to(  darr_t* lhs, mdarr6_t* rhs, mdarr6_t* res);
  mdarr6_t mdarr6_transpose(    mdarr6_t* arr1);
  void    mdarr6_transpose_to( mdarr6_t* arr1, mdarr6_t* res);
  mdarr6_t mdarr6_invert(    mdarr6_t* arr1);
  void    mdarr6_invert_to( mdarr6_t* arr1, mdarr6_t* res);
  mdnum6_t mdarr6_det(    mdarr6_t* arr1);
  void      mdarr6_det_to( mdarr6_t* arr1, mdnum6_t* res);
  mdnum6_t mdarr6_norm(    mdarr6_t* arr1);
  void      mdarr6_norm_to( mdarr6_t* arr1,  mdnum6_t* res);
  mdnum6_t mdarr6_pnorm(    mdarr6_t* arr1, coeff_t p);
  void      mdarr6_pnorm_to( mdarr6_t* arr1, coeff_t p, mdnum6_t* res);
  
  
  # From ../../../include/oti/static/mdnum6/array/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum6/array/gauss/functions.h
  
  femdarr6_t femdarr6_atanh(    femdarr6_t* arr);
  void      femdarr6_atanh_to( femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_asinh(    femdarr6_t* arr);
  void      femdarr6_asinh_to( femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_acosh(    femdarr6_t* arr);
  void      femdarr6_acosh_to( femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_tanh(     femdarr6_t* arr);
  void      femdarr6_tanh_to(  femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_sinh(     femdarr6_t* arr);
  void      femdarr6_sinh_to(  femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_cosh(     femdarr6_t* arr);
  void      femdarr6_cosh_to(  femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_atan(     femdarr6_t* arr);
  void      femdarr6_atan_to(  femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_asin(     femdarr6_t* arr);
  void      femdarr6_asin_to(  femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_acos(     femdarr6_t* arr);
  void      femdarr6_acos_to(  femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_tan(      femdarr6_t* arr);
  void      femdarr6_tan_to(   femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_sin(      femdarr6_t* arr);
  void      femdarr6_sin_to(   femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_cos(      femdarr6_t* arr);
  void      femdarr6_cos_to(   femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_logb(     femdarr6_t* arr, double base);
  void      femdarr6_logb_to(  femdarr6_t* arr, double base, femdarr6_t* res);
  femdarr6_t femdarr6_log10(    femdarr6_t* arr);
  void      femdarr6_log10_to( femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_log(      femdarr6_t* arr);
  void      femdarr6_log_to(   femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_exp(      femdarr6_t* arr);
  void      femdarr6_exp_to(   femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_cbrt(     femdarr6_t* arr);
  void      femdarr6_cbrt_to(  femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_sqrt(     femdarr6_t* arr);
  void      femdarr6_sqrt_to(  femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_pow(      femdarr6_t* arr, double e);
  void      femdarr6_pow_to(   femdarr6_t* arr, double e, femdarr6_t* res);
  
  
  # From ../../../include/oti/static/mdnum6/array/gauss/base.h
  
  void      femdarr6_get_order_im_to( ord_t order, femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_get_order_im(    ord_t order, femdarr6_t* arr);
  femdarr6_t femdarr6_get_deriv(   imdir_t idx, ord_t order, femdarr6_t* arr);
  void      femdarr6_get_deriv_to(imdir_t idx, ord_t order, femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_get_im(      imdir_t idx, ord_t order, femdarr6_t* arr);
  void      femdarr6_get_im_to(   imdir_t idx, ord_t order, femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_truncate_im(   imdir_t idx, ord_t order, femdarr6_t* arr);
  void      femdarr6_truncate_im_to(imdir_t idx, ord_t order, femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_copy(   femdarr6_t* src);
  void      femdarr6_copy_to(femdarr6_t* src, femdarr6_t* res);
  femdarr6_t femdarr6_get_im(    imdir_t idx, ord_t order, femdarr6_t* arr);
  void      femdarr6_get_im_to( imdir_t idx, ord_t order, femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_get_deriv(    imdir_t idx, ord_t order, femdarr6_t* arr);
  void      femdarr6_get_deriv_to( imdir_t idx, ord_t order, femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_extract_im(    imdir_t idx, ord_t order, femdarr6_t* arr);
  void      femdarr6_extract_im_to( imdir_t idx, ord_t order, femdarr6_t* arr,  femdarr6_t* res);
  femdarr6_t femdarr6_extract_deriv(    imdir_t idx, ord_t order, femdarr6_t* arr);
  void      femdarr6_extract_deriv_to( imdir_t idx, ord_t order, femdarr6_t* arr, femdarr6_t* res);
  mdarr6_t   femdarr6_get_item_k(  femdarr6_t* arr, uint64_t k);
  femdnum6_t  femdarr6_get_item_ij( femdarr6_t* arr, uint64_t i, uint64_t j);
  mdnum6_t femdarr6_get_item_ijk(femdarr6_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void femdarr6_get_item_ij_to(  femdarr6_t* arr, uint64_t i, uint64_t j,
                                 femdnum6_t* res);
  void femdarr6_get_item_k_to(   femdarr6_t* arr, uint64_t k,
                                  mdarr6_t* res);
  void femdarr6_get_item_ijk_to( femdarr6_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                mdnum6_t* res);
  femdarr6_t femdarr6_get_slice(femdarr6_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      femdarr6_get_slice_to(femdarr6_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr6_t* res);
  void femdarr6_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              femdarr6_t* res);
  void femdarr6_set_item_ij_o(  mdnum6_t* elm, uint64_t i, uint64_t j,
                               femdarr6_t* res);
  void femdarr6_set_item_ij_f(  femdnum6_t* elm, uint64_t i, uint64_t j,
                              femdarr6_t* res);
  void femdarr6_set_item_k_r(    coeff_t  elm, uint64_t k,
                              femdarr6_t* res);
  void femdarr6_set_item_k_o(  mdnum6_t* elm, uint64_t k,
                              femdarr6_t* res);
  void femdarr6_set_item_k_R(    mdarr6_t* elm, uint64_t k,
                            femdarr6_t* res);
  void femdarr6_set_item_k_O(    mdarr6_t* elm, uint64_t k,
                            femdarr6_t* res);
  void femdarr6_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr6_t* res);
  void femdarr6_set_item_ijk_o( mdnum6_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr6_t* res);
  void femdarr6_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr6_t* res);
  void femdarr6_set_slice_o( mdnum6_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr6_t* res);
  void femdarr6_set_slice_f( femdnum6_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr6_t* res);
  void femdarr6_set_slice_O( mdarr6_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr6_t* res);
  void femdarr6_set_slice_F( femdarr6_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr6_t* res);
  void femdarr6_set_all_o( mdnum6_t* num, femdarr6_t* arr );
  void femdarr6_set_all_r(   coeff_t  num, femdarr6_t* arr );
  void femdarr6_set_all_f(  femdnum6_t* num, femdarr6_t* arr );
  void femdarr6_set_r(    coeff_t src, femdarr6_t* res );
  void femdarr6_set_o( mdnum6_t* src, femdarr6_t* res );
  void femdarr6_set_f(  femdnum6_t* src, femdarr6_t* res );
  void femdarr6_set_R(    darr_t* src, femdarr6_t* res );
  void femdarr6_set_O(   mdarr6_t* src, femdarr6_t* res );
  void femdarr6_set_F( femdarr6_t* src, femdarr6_t* res );
  femdarr6_t femdarr6_eye( uint64_t size,  uint64_t nip);
  femdarr6_t femdarr6_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  femdarr6_t femdarr6_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  femdarr6_t femdarr6_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void femdarr6_free(femdarr6_t* arr);
  femdarr6_t femdarr6_init();
  ord_t femdarr6_get_order(femdarr6_t* arr);
  
  
  # From ../../../include/oti/static/mdnum6/array/gauss/utils.h
  
  void femdarr6_dimCheck_FF_samesize(femdarr6_t* arr1, femdarr6_t* arr2, femdnum6_t* res);
  void femdarr6_dimCheck_OF_samesize(  mdarr6_t* arr1, femdarr6_t* arr2, femdnum6_t* res);
  void femdarr6_dimCheck_RF_samesize(   darr_t* arr1, femdarr6_t* arr2, femdnum6_t* res);
  void femdarr6_dimCheck_FF_elementwise(femdarr6_t* arr1, femdarr6_t* arr2, femdarr6_t* res);
  void femdarr6_dimCheck_OF_elementwise(  mdarr6_t* arr1, femdarr6_t* arr2, femdarr6_t* res);
  void femdarr6_dimCheck_RF_elementwise(   darr_t* arr1, femdarr6_t* arr2, femdarr6_t* res);
  void femdarr6_dimCheck_fF_elementwise( femdnum6_t* num1, femdarr6_t* arr2, femdarr6_t* res);
  void femdarr6_dimCheck_Ff_elementwise(femdarr6_t* arr1,  femdnum6_t* num2, femdarr6_t* res);
  void femdarr6_dimCheck_FF_matmul( femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  void femdarr6_dimCheck_OF_matmul(   mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  void femdarr6_dimCheck_RF_matmul(    darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  void femdarr6_dimCheck_FO_matmul( femdarr6_t* lhs,   mdarr6_t* rhs, femdarr6_t* res);
  void femdarr6_dimCheck_FR_matmul( femdarr6_t* lhs,    darr_t* rhs, femdarr6_t* res);
  void femdarr6_dimCheck_F_squareness( femdarr6_t* arr1, femdarr6_t* res);
  void femdarr6_dimCheck_F_transpose( femdarr6_t* arr1, femdarr6_t* res);
  void femdarr6_dimCheck_FfO_integrate(femdarr6_t* arr, femdnum6_t* num,mdarr6_t* res);
  void femdarr6_get_active_bases(femdarr6_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum6/array/gauss/algebra.h
  
  femdarr6_t femdarr6_neg(    femdarr6_t* arr);
  void      femdarr6_neg_to( femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t femdarr6_sum_FF(   femdarr6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_sum_FF_to(femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sum_fF(    femdnum6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_sum_fF_to( femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sum_OF(     mdarr6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_sum_OF_to(  mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sum_RF(      darr_t* lhs, femdarr6_t* rhs);
  void      femdarr6_sum_RF_to(   darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sum_oF(   mdnum6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_sum_oF_to(mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sum_rF(     coeff_t  lhs, femdarr6_t* rhs);
  void      femdarr6_sum_rF_to(  coeff_t  lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sub_FF(    femdarr6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_sub_FF_to( femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sub_fF(    femdnum6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_sub_fF_to( femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sub_Ff(    femdarr6_t* lhs, femdnum6_t* rhs);
  void      femdarr6_sub_Ff_to( femdarr6_t* lhs, femdnum6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sub_OF(      mdarr6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_sub_OF_to(   mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sub_FO(    femdarr6_t* lhs,   mdarr6_t* rhs);
  void      femdarr6_sub_FO_to( femdarr6_t* lhs,   mdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sub_RF(       darr_t* lhs, femdarr6_t* rhs);
  void      femdarr6_sub_RF_to(    darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sub_FR(    femdarr6_t* lhs,    darr_t* rhs);
  void      femdarr6_sub_FR_to( femdarr6_t* lhs,    darr_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sub_oF(    mdnum6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_sub_oF_to( mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sub_Fo(    femdarr6_t* lhs, mdnum6_t* rhs);
  void      femdarr6_sub_Fo_to( femdarr6_t* lhs, mdnum6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sub_rF(      coeff_t  lhs, femdarr6_t* rhs);
  void      femdarr6_sub_rF_to(    coeff_t lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_sub_Fr(    femdarr6_t* lhs,   coeff_t  rhs);
  void      femdarr6_sub_Fr_to( femdarr6_t* lhs,   coeff_t  rhs, femdarr6_t* res);
  femdarr6_t femdarr6_mul_FF(   femdarr6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_mul_FF_to(femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_mul_fF(    femdnum6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_mul_fF_to( femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_mul_OF(     mdarr6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_mul_OF_to(  mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_mul_RF(      darr_t* lhs, femdarr6_t* rhs);
  void      femdarr6_mul_RF_to(   darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_mul_oF(   mdnum6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_mul_oF_to(mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_mul_rF(     coeff_t  lhs, femdarr6_t* rhs);
  void      femdarr6_mul_rF_to(  coeff_t  lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_div_FF(    femdarr6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_div_FF_to( femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_div_fF(     femdnum6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_div_fF_to(  femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_div_Ff(    femdarr6_t* lhs,  femdnum6_t* rhs);
  void      femdarr6_div_Ff_to( femdarr6_t* lhs,  femdnum6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_div_OF(      mdarr6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_div_OF_to(   mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_div_FO(    femdarr6_t* lhs,   mdarr6_t* rhs);
  void      femdarr6_div_FO_to( femdarr6_t* lhs,   mdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_div_RF(       darr_t* lhs, femdarr6_t* rhs);
  void      femdarr6_div_RF_to(    darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_div_FR(    femdarr6_t* lhs,    darr_t* rhs);
  void      femdarr6_div_FR_to( femdarr6_t* lhs,    darr_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_div_oF(    mdnum6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_div_oF_to( mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_div_Fo(    femdarr6_t* lhs, mdnum6_t* rhs);
  void      femdarr6_div_Fo_to( femdarr6_t* lhs, mdnum6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_div_rF(      coeff_t  lhs, femdarr6_t* rhs);
  void      femdarr6_div_rF_to(    coeff_t lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_div_Fr(    femdarr6_t* lhs,   coeff_t  rhs);
  void      femdarr6_div_Fr_to( femdarr6_t* lhs,   coeff_t  rhs, femdarr6_t* res);
  mdarr6_t femdarr6_integrate(    femdarr6_t* arr, femdnum6_t* w);
  void    femdarr6_integrate_to( femdarr6_t* arr, femdnum6_t* w, mdarr6_t* res);
  femdnum6_t femdarr6_dotproduct_FF(    femdarr6_t* lhs, femdarr6_t* rhs);
  void     femdarr6_dotproduct_FF_to( femdarr6_t* lhs, femdarr6_t* rhs, femdnum6_t* res);
  femdnum6_t femdarr6_dotproduct_OF(      mdarr6_t* lhs, femdarr6_t* rhs);
  void     femdarr6_dotproduct_OF_to(   mdarr6_t* lhs, femdarr6_t* rhs, femdnum6_t* res);
  femdnum6_t femdarr6_dotproduct_RF(       darr_t* lhs, femdarr6_t* rhs);
  void     femdarr6_dotproduct_RF_to(    darr_t* lhs, femdarr6_t* rhs, femdnum6_t* res);
  femdarr6_t femdarr6_matmul_FF(    femdarr6_t* lhs, femdarr6_t* rhs);
  void      femdarr6_matmul_FF_to( femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_matmul_OF(    mdarr6_t*   lhs, femdarr6_t* rhs);
  void      femdarr6_matmul_OF_to( mdarr6_t*   lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_matmul_FO(    femdarr6_t* lhs, mdarr6_t*   rhs);
  void      femdarr6_matmul_FO_to( femdarr6_t* lhs, mdarr6_t*   rhs, femdarr6_t* res);
  femdarr6_t femdarr6_matmul_RF(    darr_t*    lhs, femdarr6_t* rhs);
  void      femdarr6_matmul_RF_to( darr_t*    lhs, femdarr6_t* rhs, femdarr6_t* res);
  femdarr6_t femdarr6_matmul_FR(    femdarr6_t* lhs, darr_t*    rhs);
  void      femdarr6_matmul_FR_to( femdarr6_t* lhs, darr_t*    rhs, femdarr6_t* res);
  femdnum6_t femdarr6_det(   femdarr6_t* arr);
  void     femdarr6_det_to(femdarr6_t* arr, femdnum6_t* res);
  femdnum6_t femdarr6_norm(     femdarr6_t* arr);
  void     femdarr6_norm_to(  femdarr6_t* arr, femdnum6_t* res);
  femdnum6_t femdarr6_pnorm(    femdarr6_t* arr, coeff_t p);
  void     femdarr6_pnorm_to( femdarr6_t* arr, coeff_t p, femdnum6_t* res);
  femdarr6_t   femdarr6_invert(    femdarr6_t* arr);
  void        femdarr6_invert_to( femdarr6_t* arr, femdarr6_t* res);
  femdarr6_t   femdarr6_transpose(   femdarr6_t* arr);
  void        femdarr6_transpose_to(femdarr6_t* arr, femdarr6_t* res);
  
  