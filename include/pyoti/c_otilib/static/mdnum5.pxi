cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/mdnum5/scalar/structures.h
  
  ctypedef struct  mdnum5_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e4;
    coeff_t e5;
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
    coeff_t e1234;
    coeff_t e1235;
    coeff_t e1245;
    coeff_t e1345;
    coeff_t e2345;
    coeff_t e12345;
  # } mdnum5_t;
  
  
  # From ../../../include/oti/static/mdnum5/array/structures.h
  
  ctypedef struct  mdarr5_t : # {
      mdnum5_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } mdarr5_t;
  
  
  # From ../../../include/oti/static/mdnum5/scalar/gauss/structures.h
  
  ctypedef struct  femdnum5_t: # {
      mdnum5_t*  p_data;
      uint64_t    nip;
  # } femdnum5_t;
  
  
  # From ../../../include/oti/static/mdnum5/array/gauss/structures.h
  
  ctypedef struct  femdarr5_t: # {
      mdarr5_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } femdarr5_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/mdnum5/scalar/functions.h
  
  mdnum5_t mdnum5_atanh(mdnum5_t* num);
  void mdnum5_atanh_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_asinh(mdnum5_t* num);
  void mdnum5_asinh_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_acosh(mdnum5_t* num);
  void mdnum5_acosh_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_tanh(mdnum5_t* num);
  void mdnum5_tanh_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_sqrt(mdnum5_t* num);
  void mdnum5_sqrt_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_cbrt(mdnum5_t* num);
  void mdnum5_cbrt_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_cosh(mdnum5_t* num);
  void mdnum5_cosh_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_sinh(mdnum5_t* num);
  void mdnum5_sinh_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_asin(mdnum5_t* num);
  void mdnum5_asin_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_acos(mdnum5_t* num);
  void mdnum5_acos_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_atan(mdnum5_t* num);
  void mdnum5_atan_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_tan(mdnum5_t* num);
  void mdnum5_tan_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_cos(mdnum5_t* num);
  void mdnum5_cos_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_sin(mdnum5_t* num );
  void mdnum5_sin_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_logb(mdnum5_t* num, double base);
  void mdnum5_logb_to(mdnum5_t* num, double base, mdnum5_t* res);
  mdnum5_t mdnum5_log10(mdnum5_t* num);
  void mdnum5_log10_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_log(mdnum5_t* num);
  void mdnum5_log_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_exp(mdnum5_t* num);
  void mdnum5_exp_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_pow(mdnum5_t* num, double e);
  void mdnum5_pow_to(mdnum5_t* num, coeff_t e, mdnum5_t* res);
  
  
  # From ../../../include/oti/static/mdnum5/scalar/base.h
  
  void mdnum5_set_im_o(mdnum5_t* num, imdir_t idx, ord_t order, mdnum5_t* res);
  void mdnum5_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum5_t* res);
  void mdnum5_set_deriv_o(mdnum5_t* num, imdir_t idx, ord_t order, mdnum5_t* res);
  void mdnum5_extract_im_to( imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_extract_im(imdir_t idx, ord_t order, mdnum5_t* num);
  mdnum5_t mdnum5_extract_deriv(imdir_t idx, ord_t order, mdnum5_t* num);
  void mdnum5_extract_deriv_to(imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res);
  void mdnum5_get_im_to_o(imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_get_im_o(imdir_t idx, ord_t order, mdnum5_t* num);
  void mdnum5_get_im_to_r(imdir_t idx, ord_t order, mdnum5_t* num, coeff_t* res);
  ord_t mdnum5_get_order(mdnum5_t* lhs);
  mdnum5_t mdnum5_get_deriv_o( imdir_t idx, ord_t order, mdnum5_t* num);
  void mdnum5_get_deriv_to( imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res);
  void mdnum5_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum5_t* res);
  mdnum5_t mdnum5_init();
  ndir_t mdnum5_get_ndir_order(ord_t order, mdnum5_t* num);
  ndir_t mdnum5_get_ndir_total(mdnum5_t* num);
  coeff_t* mdnum5_get_order_address(ord_t order, mdnum5_t* num);
  mdnum5_t mdnum5_create_r(  coeff_t lhs);
  void mdnum5_set_r(  coeff_t lhs, mdnum5_t* res);
  void mdnum5_set_o(  mdnum5_t* lhs, mdnum5_t* res);
  mdnum5_t mdnum5_get_order_im(ord_t order, mdnum5_t* lhs);
  void mdnum5_get_order_im_to(ord_t order, mdnum5_t* lhs, mdnum5_t* res);
  coeff_t mdnum5_get_item(imdir_t idx, ord_t order, mdnum5_t* lhs);
  coeff_t mdnum5_get_deriv(imdir_t idx, ord_t order, mdnum5_t* lhs);
  void mdnum5_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum5_t* x);
  mdnum5_t mdnum5_copy(  mdnum5_t* lhs);
  void mdnum5_copy_to(  mdnum5_t* lhs, mdnum5_t* res);
  mdnum5_t mdnum5_taylor_integrate(coeff_t* deltas,mdnum5_t* lhs);
  void mdnum5_taylor_integrate_to(coeff_t* deltas,mdnum5_t* lhs, mdnum5_t* res);
  mdnum5_t mdnum5_truncate_im(imdir_t idx, ord_t order, mdnum5_t* lhs);
  void mdnum5_truncate_im_to(imdir_t idx, ord_t order, mdnum5_t* lhs, mdnum5_t* res);
  void mdnum5_print(  mdnum5_t* lhs);
  imdir_t mdnum5_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/mdnum5/scalar/utils.h
  
  void mdnum5_get_active_bases(mdnum5_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/mdnum5/scalar/algebra.h
  
  mdnum5_t mdnum5_abs(mdnum5_t* num);
  mdnum5_t mdnum5_div_ro(coeff_t num, mdnum5_t* den);
  mdnum5_t mdnum5_div_oo(mdnum5_t* num, mdnum5_t* den);
  mdnum5_t mdnum5_div_or(mdnum5_t* num, coeff_t val);
  void mdnum5_div_ro_to(coeff_t num, mdnum5_t* den, mdnum5_t* res);
  void mdnum5_div_oo_to(mdnum5_t* num, mdnum5_t* den, mdnum5_t* res);
  void mdnum5_div_or_to(mdnum5_t* num, coeff_t val, mdnum5_t* res);
  void mdnum5_abs_to(mdnum5_t* num, mdnum5_t* res);
  mdnum5_t mdnum5_neg(  mdnum5_t* lhs);
  void mdnum5_neg_to(  mdnum5_t* lhs, mdnum5_t* res);
  mdnum5_t mdnum5_sum_oo(  mdnum5_t* lhs,  mdnum5_t* rhs);
  void mdnum5_sum_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res);
  mdnum5_t mdnum5_sum_ro(  coeff_t lhs,  mdnum5_t* rhs);
  void mdnum5_sum_ro_to(  coeff_t lhs,  mdnum5_t* rhs, mdnum5_t* res);
  mdnum5_t mdnum5_sub_oo(  mdnum5_t* lhs,  mdnum5_t* rhs);
  void mdnum5_sub_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res);
  mdnum5_t mdnum5_sub_ro(  coeff_t lhs,  mdnum5_t* rhs);
  void mdnum5_sub_ro_to(  coeff_t lhs,  mdnum5_t* rhs, mdnum5_t* res);
  mdnum5_t mdnum5_sub_or(  mdnum5_t* lhs,  coeff_t rhs);
  void mdnum5_sub_or_to(  mdnum5_t* lhs,  coeff_t rhs, mdnum5_t* res);
  mdnum5_t mdnum5_mul_oo(  mdnum5_t* lhs,  mdnum5_t* rhs);
  void mdnum5_mul_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res);
  mdnum5_t mdnum5_mul_ro(  coeff_t lhs,  mdnum5_t* rhs);
  void mdnum5_mul_ro_to(  coeff_t lhs,  mdnum5_t* rhs, mdnum5_t* res);
  mdnum5_t mdnum5_trunc_mul_oo(  mdnum5_t* lhs,  mdnum5_t* rhs);
  void mdnum5_trunc_mul_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res);
  mdnum5_t mdnum5_gem_oo(  mdnum5_t* a,  mdnum5_t* b,  mdnum5_t* c);
  void mdnum5_gem_oo_to(  mdnum5_t* a,  mdnum5_t* b,  mdnum5_t* c, mdnum5_t* res);
  mdnum5_t mdnum5_gem_ro(  coeff_t a,  mdnum5_t* b,  mdnum5_t* c);
  void mdnum5_gem_ro_to(  coeff_t a,  mdnum5_t* b,  mdnum5_t* c, mdnum5_t* res);
  void mdnum5_trunc_gem_oo_to( ord_t ord_lhs,  mdnum5_t* a,  ord_t ord_rhs,  mdnum5_t* b,  mdnum5_t* c, mdnum5_t* res);
  void mdnum5_trunc_sum_oo_to(ord_t order, mdnum5_t* lhs,mdnum5_t* rhs, mdnum5_t* res);
  void mdnum5_trunc_sub_oo_to(ord_t order, mdnum5_t* lhs,mdnum5_t* rhs, mdnum5_t* res);
  mdnum5_t mdnum5_feval(coeff_t* feval_re, mdnum5_t* x);
  void mdnum5_feval_to(coeff_t* feval_re, mdnum5_t* x, mdnum5_t* res);
  
  
  # From ../../../include/oti/static/mdnum5/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum5/scalar/gauss/functions.h
  
  femdnum5_t femdnum5_atanh(    femdnum5_t* num);
  void     femdnum5_atanh_to( femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_asinh(    femdnum5_t* num);
  void     femdnum5_asinh_to( femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_acosh(    femdnum5_t* num);
  void     femdnum5_acosh_to( femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_tanh(     femdnum5_t* num);
  void     femdnum5_tanh_to(  femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_cosh(     femdnum5_t* num);
  void     femdnum5_cosh_to(  femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_sinh(     femdnum5_t* num);
  void     femdnum5_sinh_to(  femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_asin(     femdnum5_t* num);
  void     femdnum5_asin_to(  femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_acos(     femdnum5_t* num);
  void     femdnum5_acos_to(  femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_atan(     femdnum5_t* num);
  void     femdnum5_atan_to(  femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_tan(      femdnum5_t* num);
  void     femdnum5_tan_to(   femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_cos(      femdnum5_t* num);
  void     femdnum5_cos_to(   femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_sin(      femdnum5_t* num);
  void     femdnum5_sin_to(   femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_logb(     femdnum5_t* num, double base);
  void     femdnum5_logb_to(  femdnum5_t* num, double base, femdnum5_t* res);
  femdnum5_t femdnum5_log10(    femdnum5_t* num);
  void     femdnum5_log10_to( femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_log(      femdnum5_t* num);
  void     femdnum5_log_to(   femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_exp(      femdnum5_t* num);
  void     femdnum5_exp_to(   femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_cbrt(     femdnum5_t* num);
  void     femdnum5_cbrt_to(  femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_sqrt(     femdnum5_t* num);
  void     femdnum5_sqrt_to(  femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_pow(      femdnum5_t* num, double e);
  void     femdnum5_pow_to(   femdnum5_t* num, double e, femdnum5_t* res);
  mdnum5_t femdnum5_integrate(       femdnum5_t* num, femdnum5_t* w);
  void      femdnum5_integrate_to(    femdnum5_t* num, femdnum5_t* w, mdnum5_t* res);
  mdnum5_t femdnum5_integrate_f(     femdnum5_t* num, femdnum5_t* w);
  void      femdnum5_integrate_f_to(  femdnum5_t* num, femdnum5_t* w, mdnum5_t* res);
  mdnum5_t femdnum5_integrate_r(       coeff_t num, femdnum5_t* w);
  void      femdnum5_integrate_r_to(    coeff_t num, femdnum5_t* w, mdnum5_t* res);
  mdnum5_t femdnum5_integrate_o(    mdnum5_t* num, femdnum5_t* w);
  void      femdnum5_integrate_o_to( mdnum5_t* num, femdnum5_t* w, mdnum5_t* res);
  
  
  # From ../../../include/oti/static/mdnum5/scalar/gauss/base.h
  
  void     femdnum5_get_order_im_to( ord_t order, femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_get_order_im(    ord_t order, femdnum5_t* num);
  femdnum5_t femdnum5_get_im(    imdir_t idx, ord_t order, femdnum5_t* num);
  void     femdnum5_get_im_to( imdir_t idx, ord_t order, femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_get_deriv(    imdir_t idx, ord_t order, femdnum5_t* num);
  void     femdnum5_get_deriv_to( imdir_t idx, ord_t order, femdnum5_t* num, femdnum5_t* res);
  void femdnum5_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum5_t* num);
  void femdnum5_set_im_o( mdnum5_t* val, imdir_t idx, ord_t order, femdnum5_t* num);
  void femdnum5_set_im_f(  femdnum5_t* val, imdir_t idx, ord_t order, femdnum5_t* num);
  void femdnum5_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum5_t* num);
  void femdnum5_set_deriv_o( mdnum5_t* val, imdir_t idx, ord_t order, femdnum5_t* num);
  void femdnum5_set_deriv_f(  femdnum5_t* val, imdir_t idx, ord_t order, femdnum5_t* num);
  femdnum5_t femdnum5_extract_im(    imdir_t idx, ord_t order, femdnum5_t* num);
  void     femdnum5_extract_im_to( imdir_t idx, ord_t order, femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_extract_deriv(    imdir_t idx, ord_t order, femdnum5_t* num);
  void     femdnum5_extract_deriv_to( imdir_t idx, ord_t order, femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_truncate_im(    imdir_t idx, ord_t order, femdnum5_t* num);
  void     femdnum5_truncate_im_to( imdir_t idx, ord_t order, femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_copy(    femdnum5_t* src);
  void     femdnum5_copy_to( femdnum5_t* src, femdnum5_t* dst);
  void femdnum5_set_r(    coeff_t num, femdnum5_t* res);
  void femdnum5_set_o( mdnum5_t* num, femdnum5_t* res);
  void femdnum5_set_f(  femdnum5_t* num, femdnum5_t* res);
  void femdnum5_set_item_k_r(   coeff_t  num, uint64_t k, femdnum5_t* res);
  void femdnum5_set_item_k_o( mdnum5_t* num, uint64_t k, femdnum5_t* res);
  mdnum5_t femdnum5_get_item_k(   femdnum5_t* num, uint64_t k);
  void      femdnum5_get_item_k_to(femdnum5_t* num, uint64_t k, mdnum5_t* res);
  femdnum5_t femdnum5_zeros(uint64_t nIntPts);
  femdnum5_t femdnum5_createEmpty(uint64_t nIntPts);
  femdnum5_t femdnum5_empty_like(femdnum5_t* arr);
  void femdnum5_free(femdnum5_t* num);
  ord_t femdnum5_get_order( femdnum5_t* num );
  femdnum5_t femdnum5_init();
  
  
  # From ../../../include/oti/static/mdnum5/scalar/gauss/utils.h
  
  void femdnum5_dimCheck(femdnum5_t* arr1,femdnum5_t* arr2);
  void femdnum5_get_active_bases(femdnum5_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum5/scalar/gauss/algebra.h
  
  femdnum5_t femdnum5_neg(   femdnum5_t* num);
  void     femdnum5_neg_to(femdnum5_t* num, femdnum5_t* res);
  femdnum5_t femdnum5_sum_ff(   femdnum5_t* lhs, femdnum5_t* rhs);
  void     femdnum5_sum_ff_to(femdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_sum_of(   mdnum5_t* lhs, femdnum5_t* rhs);
  void     femdnum5_sum_of_to(mdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_sum_rf(   coeff_t lhs, femdnum5_t* rhs);
  void     femdnum5_sum_rf_to(coeff_t lhs, femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_sub_ff(     femdnum5_t* lhs,  femdnum5_t* rhs);
  void     femdnum5_sub_ff_to(  femdnum5_t* lhs,  femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_sub_of(    mdnum5_t* lhs,  femdnum5_t* rhs);
  void     femdnum5_sub_of_to( mdnum5_t* lhs,  femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_sub_fo(     femdnum5_t* lhs, mdnum5_t* rhs);
  void     femdnum5_sub_fo_to(  femdnum5_t* lhs, mdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_sub_rf(       coeff_t lhs,  femdnum5_t* rhs);
  void     femdnum5_sub_rf_to(    coeff_t lhs,  femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_sub_fr(     femdnum5_t* lhs,    coeff_t rhs);
  void     femdnum5_sub_fr_to(  femdnum5_t* lhs,    coeff_t rhs, femdnum5_t* res);
  femdnum5_t femdnum5_mul_ff(   femdnum5_t* lhs, femdnum5_t* rhs);
  void     femdnum5_mul_ff_to(femdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_mul_of(   mdnum5_t* lhs, femdnum5_t* rhs);
  void     femdnum5_mul_of_to(mdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_mul_rf(   coeff_t lhs, femdnum5_t* rhs);
  void     femdnum5_mul_rf_to(coeff_t lhs, femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_div_ff(     femdnum5_t* lhs,  femdnum5_t* rhs);
  void     femdnum5_div_ff_to(  femdnum5_t* lhs,  femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_div_of(    mdnum5_t* lhs,  femdnum5_t* rhs);
  void     femdnum5_div_of_to( mdnum5_t* lhs,  femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_div_fo(     femdnum5_t* lhs, mdnum5_t* rhs);
  void     femdnum5_div_fo_to(  femdnum5_t* lhs, mdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_div_rf(       coeff_t lhs,  femdnum5_t* rhs);
  void     femdnum5_div_rf_to(    coeff_t lhs,  femdnum5_t* rhs, femdnum5_t* res);
  femdnum5_t femdnum5_div_fr(     femdnum5_t* lhs,    coeff_t rhs);
  void     femdnum5_div_fr_to(  femdnum5_t* lhs,    coeff_t rhs, femdnum5_t* res);
  
  
  # From ../../../include/oti/static/mdnum5/array/functions.h
  
  mdarr5_t mdarr5_atanh(   mdarr5_t* arr);
  void    mdarr5_atanh_to(mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_asinh(   mdarr5_t* arr);
  void    mdarr5_asinh_to(mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_acosh(   mdarr5_t* arr);
  void    mdarr5_acosh_to(mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_tanh(    mdarr5_t* arr);
  void    mdarr5_tanh_to( mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_cbrt(    mdarr5_t* arr);
  void    mdarr5_cbrt_to( mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_sqrt(    mdarr5_t* arr);
  void    mdarr5_sqrt_to( mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_cosh(    mdarr5_t* arr);
  void    mdarr5_cosh_to( mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_sinh(    mdarr5_t* arr);
  void    mdarr5_sinh_to( mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_asin(    mdarr5_t* arr);
  void    mdarr5_asin_to( mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_acos(    mdarr5_t* arr);
  void    mdarr5_acos_to( mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_atan(    mdarr5_t* arr);
  void    mdarr5_atan_to( mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_tan(     mdarr5_t* arr);
  void    mdarr5_tan_to(  mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_cos(     mdarr5_t* arr);
  void    mdarr5_cos_to(  mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_sin(     mdarr5_t* arr);
  void    mdarr5_sin_to(  mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_logb(    mdarr5_t* arr, double base);
  void    mdarr5_logb_to( mdarr5_t* arr, double base, mdarr5_t* res);
  mdarr5_t mdarr5_log10(   mdarr5_t* arr);
  void    mdarr5_log10_to(mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_log(     mdarr5_t* arr);
  void    mdarr5_log_to(  mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_exp(     mdarr5_t* arr);
  void    mdarr5_exp_to(  mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_pow(     mdarr5_t* arr, double e);
  void    mdarr5_pow_to(  mdarr5_t* arr, double e, mdarr5_t* res);
  
  
  # From ../../../include/oti/static/mdnum5/array/algebra_elementwise.h
  
  mdarr5_t mdarr5_neg(mdarr5_t* arr);
  void mdarr5_neg_to(mdarr5_t* rhs, mdarr5_t* res);
  mdarr5_t mdarr5_sum_OO(mdarr5_t*   lhs, mdarr5_t* rhs);
  mdarr5_t mdarr5_sum_RO(darr_t*    lhs, mdarr5_t* rhs);
  mdarr5_t mdarr5_sum_oO(mdnum5_t* lhs, mdarr5_t* rhs);
  mdarr5_t mdarr5_sum_rO(coeff_t    lhs, mdarr5_t* rhs);
  void mdarr5_sum_OO_to(mdarr5_t*   lhs, mdarr5_t* rhs, mdarr5_t* res);
  void mdarr5_sum_RO_to(darr_t*    lhs, mdarr5_t* rhs, mdarr5_t* res);
  void mdarr5_sum_oO_to(mdnum5_t* lhs, mdarr5_t* rhs, mdarr5_t* res);
  void mdarr5_sum_rO_to(coeff_t    lhs, mdarr5_t* rhs, mdarr5_t* res);
  void mdarr5_trunc_sum_OO_to(ord_t order, mdarr5_t* arr1, mdarr5_t* arr2, mdarr5_t* res);
  mdarr5_t mdarr5_sub_OO(mdarr5_t*   lhs, mdarr5_t*   rhs);
  mdarr5_t mdarr5_sub_RO(darr_t*    lhs, mdarr5_t*   rhs);
  mdarr5_t mdarr5_sub_OR(mdarr5_t*   lhs, darr_t*    rhs);
  mdarr5_t mdarr5_sub_oO(mdnum5_t* lhs, mdarr5_t*   rhs);
  mdarr5_t mdarr5_sub_Oo(mdarr5_t*   lhs, mdnum5_t* rhs);
  mdarr5_t mdarr5_sub_rO(coeff_t    lhs, mdarr5_t*   rhs);
  mdarr5_t mdarr5_sub_Or(mdarr5_t*   lhs, coeff_t    rhs);
  void mdarr5_sub_OO_to( mdarr5_t*   lhs, mdarr5_t*   rhs, mdarr5_t* res);
  void mdarr5_sub_RO_to( darr_t*    lhs, mdarr5_t*   rhs, mdarr5_t* res);
  void mdarr5_sub_OR_to( mdarr5_t*   lhs, darr_t*    rhs, mdarr5_t* res);
  void mdarr5_sub_oO_to( mdnum5_t* lhs, mdarr5_t*   rhs, mdarr5_t* res);
  void mdarr5_sub_Oo_to( mdarr5_t*   lhs, mdnum5_t* rhs, mdarr5_t* res);
  void mdarr5_sub_rO_to( coeff_t    lhs, mdarr5_t*   rhs, mdarr5_t* res);
  void mdarr5_sub_Or_to( mdarr5_t*   lhs, coeff_t    rhs, mdarr5_t* res);
  void mdarr5_trunc_sub_OO_to(ord_t order, mdarr5_t* arr1, mdarr5_t* arr2, mdarr5_t* res);
  mdarr5_t mdarr5_mul_OO(mdarr5_t*   lhs, mdarr5_t* rhs);
  mdarr5_t mdarr5_mul_RO(darr_t*    lhs, mdarr5_t* rhs);
  mdarr5_t mdarr5_mul_oO(mdnum5_t* lhs, mdarr5_t* rhs);
  mdarr5_t mdarr5_mul_rO(coeff_t    lhs, mdarr5_t* rhs);
  void mdarr5_mul_OO_to(mdarr5_t*   lhs, mdarr5_t* rhs, mdarr5_t* res);
  void mdarr5_mul_RO_to(darr_t*    lhs, mdarr5_t* rhs, mdarr5_t* res);
  void mdarr5_mul_oO_to(mdnum5_t* lhs, mdarr5_t* rhs, mdarr5_t* res);
  void mdarr5_mul_rO_to(coeff_t    lhs, mdarr5_t* rhs, mdarr5_t* res);
  void mdarr5_gem_OO_to(  mdarr5_t* arr1, mdarr5_t* arr2, mdarr5_t* arr3, mdarr5_t* res);
  void mdarr5_gem_oO_to(mdnum5_t* arr1, mdarr5_t* arr2, mdarr5_t* arr3, mdarr5_t* res);
  mdarr5_t mdarr5_div_OO(mdarr5_t*   lhs, mdarr5_t*   rhs);
  mdarr5_t mdarr5_div_OR(mdarr5_t*   lhs, darr_t*    rhs);
  mdarr5_t mdarr5_div_RO(darr_t*    lhs, mdarr5_t*   rhs);
  mdarr5_t mdarr5_div_oO(mdnum5_t* lhs, mdarr5_t*   rhs);
  mdarr5_t mdarr5_div_Oo(mdarr5_t*   lhs, mdnum5_t* rhs);
  mdarr5_t mdarr5_div_rO(coeff_t    lhs, mdarr5_t*   rhs);
  mdarr5_t mdarr5_div_Or(mdarr5_t*   lhs, coeff_t    rhs);
  void mdarr5_div_OO_to(mdarr5_t*   lhs, mdarr5_t*   rhs, mdarr5_t* res);
  void mdarr5_div_RO_to(darr_t*    lhs, mdarr5_t*   rhs, mdarr5_t* res);
  void mdarr5_div_OR_to(mdarr5_t*   lhs, darr_t*    rhs, mdarr5_t* res);
  void mdarr5_div_oO_to(mdnum5_t* lhs, mdarr5_t*   rhs, mdarr5_t* res);
  void mdarr5_div_Oo_to(mdarr5_t*   lhs, mdnum5_t* rhs, mdarr5_t* res);
  void mdarr5_div_rO_to(coeff_t    lhs, mdarr5_t*   rhs, mdarr5_t* res);
  void mdarr5_div_Or_to(mdarr5_t*   lhs, coeff_t    rhs, mdarr5_t* res);
  
  
  # From ../../../include/oti/static/mdnum5/array/base.h
  
  void    mdarr5_taylor_integrate_to( coeff_t* deltas, mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_taylor_integrate(    coeff_t* deltas, mdarr5_t* arr);
  void    mdarr5_get_order_im_to( ord_t order, mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_get_order_im(    ord_t order, mdarr5_t* arr);
  void mdarr5_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr5_t* res);
  void mdarr5_set_slice_O( mdarr5_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr5_t* res);
  void mdarr5_set_slice_o( mdnum5_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr5_t* res);
  mdarr5_t mdarr5_get_slice( mdarr5_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void mdarr5_get_slice_to( mdarr5_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr5_t* res);
  mdarr5_t mdarr5_truncate_im(    imdir_t idx, ord_t order, mdarr5_t* arr);
  void    mdarr5_truncate_im_to( imdir_t idx, ord_t order, mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_extract_im(   imdir_t idx, ord_t order, mdarr5_t* arr);
  void    mdarr5_extract_im_to(imdir_t idx, ord_t order, mdarr5_t* arr, mdarr5_t* res);
  darr_t  mdarr5_get_deriv(    imdir_t idx, ord_t order, mdarr5_t* arr);
  void    mdarr5_get_deriv_to( imdir_t idx, ord_t order, mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_get_deriv_o(  imdir_t idx, ord_t order, mdarr5_t* arr);
  mdarr5_t mdarr5_extract_deriv(    imdir_t idx, ord_t order, mdarr5_t* arr);
  void    mdarr5_extract_deriv_to( imdir_t idx, ord_t order, mdarr5_t* arr, mdarr5_t* res);
  darr_t  mdarr5_get_im(   imdir_t idx, ord_t order, mdarr5_t* arr);
  mdarr5_t mdarr5_get_im_o( imdir_t idx, ord_t order, mdarr5_t* arr);
  void    mdarr5_get_im_to(imdir_t idx, ord_t order, mdarr5_t* arr, mdarr5_t* res);
  void    mdarr5_copy_to(mdarr5_t* arr, mdarr5_t* res);
  mdarr5_t mdarr5_copy(mdarr5_t* arr);
  void mdarr5_set_all_r( coeff_t num, mdarr5_t* arr);
  void mdarr5_set_item_i_r( coeff_t num, uint64_t i, mdarr5_t* arr);
  void mdarr5_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, mdarr5_t* arr);
  void mdarr5_set_r(   coeff_t  num,   mdarr5_t* arr);
  void mdarr5_set_o( mdnum5_t* num,   mdarr5_t* arr);
  void mdarr5_set_O(   mdarr5_t* arrin, mdarr5_t* arr);
  void mdarr5_set_all_o( mdnum5_t* src, mdarr5_t* arr);
  void mdarr5_set_item_i_o( mdnum5_t* num, uint64_t i, mdarr5_t* arr);
  void mdarr5_set_item_ij_o( mdnum5_t* num, uint64_t i, uint64_t j, mdarr5_t* arr);
  mdnum5_t mdarr5_get_item_i(    mdarr5_t* arr, uint64_t i);
  void      mdarr5_get_item_i_to( mdarr5_t* arr, uint64_t i,             mdnum5_t* res);
  mdnum5_t mdarr5_get_item_ij(   mdarr5_t* arr, uint64_t i, uint64_t j);
  void      mdarr5_get_item_ij_to(mdarr5_t* arr, uint64_t i, uint64_t j, mdnum5_t* res);
  mdarr5_t mdarr5_init();
  void mdarr5_free(mdarr5_t* arr);
  mdarr5_t mdarr5_empty_like(mdarr5_t* arr);
  mdarr5_t mdarr5_eye(uint64_t nrows);
  mdarr5_t mdarr5_ones(uint64_t nrows, uint64_t ncols);
  mdarr5_t mdarr5_zeros(uint64_t nrows, uint64_t ncols);
  mdarr5_t mdarr5_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/mdnum5/array/utils.h
  
  void mdarr5_dimCheck_OO_elementwise(mdarr5_t* arr1, mdarr5_t* arr2, mdarr5_t* res);
  void mdarr5_dimCheck_RO_elementwise(darr_t*  arr1, mdarr5_t* arr2, mdarr5_t* res);
  void mdarr5_dimCheck_OO_matmul(mdarr5_t* arr1, mdarr5_t* arr2, mdarr5_t* res);
  void mdarr5_dimCheck_RO_matmul(darr_t*  arr1, mdarr5_t* arr2, mdarr5_t* res);
  void mdarr5_dimCheck_OR_matmul(mdarr5_t* arr1, darr_t*  arr2, mdarr5_t* res);
  void mdarr5_dimCheck_O_squareness(mdarr5_t* arr1, mdarr5_t* res);
  void mdarr5_dimCheck_OO_samesize(mdarr5_t* arr1, mdarr5_t* res);
  void mdarr5_dimCheck_RO_samesize(darr_t* arr1, mdarr5_t* res);
  ord_t mdarr5_get_order(mdarr5_t* arr);
  void mdarr5_get_active_bases(mdarr5_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum5/array/algebra_matops.h
  
  mdnum5_t mdarr5_dotproduct_OO(    mdarr5_t* lhs, mdarr5_t* rhs);
  void      mdarr5_dotproduct_OO_to( mdarr5_t* lhs, mdarr5_t* rhs, mdnum5_t* res);
  mdnum5_t mdarr5_dotproduct_RO(     darr_t* lhs, mdarr5_t* rhs);
  void      mdarr5_dotproduct_RO_to(  darr_t* lhs, mdarr5_t* rhs, mdnum5_t* res);
  mdarr5_t mdarr5_matmul_OO(    mdarr5_t* lhs, mdarr5_t* rhs);
  mdarr5_t mdarr5_matmul_OR(    mdarr5_t* lhs,  darr_t* rhs);
  mdarr5_t mdarr5_matmul_RO(     darr_t* lhs, mdarr5_t* rhs);
  void    mdarr5_matmul_OO_to( mdarr5_t* lhs, mdarr5_t* rhs, mdarr5_t* res);
  void    mdarr5_matmul_OR_to( mdarr5_t* lhs,  darr_t* rhs, mdarr5_t* res);
  void    mdarr5_matmul_RO_to(  darr_t* lhs, mdarr5_t* rhs, mdarr5_t* res);
  mdarr5_t mdarr5_transpose(    mdarr5_t* arr1);
  void    mdarr5_transpose_to( mdarr5_t* arr1, mdarr5_t* res);
  mdarr5_t mdarr5_invert(    mdarr5_t* arr1);
  void    mdarr5_invert_to( mdarr5_t* arr1, mdarr5_t* res);
  mdnum5_t mdarr5_det(    mdarr5_t* arr1);
  void      mdarr5_det_to( mdarr5_t* arr1, mdnum5_t* res);
  mdnum5_t mdarr5_norm(    mdarr5_t* arr1);
  void      mdarr5_norm_to( mdarr5_t* arr1,  mdnum5_t* res);
  mdnum5_t mdarr5_pnorm(    mdarr5_t* arr1, coeff_t p);
  void      mdarr5_pnorm_to( mdarr5_t* arr1, coeff_t p, mdnum5_t* res);
  
  
  # From ../../../include/oti/static/mdnum5/array/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum5/array/gauss/functions.h
  
  femdarr5_t femdarr5_atanh(    femdarr5_t* arr);
  void      femdarr5_atanh_to( femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_asinh(    femdarr5_t* arr);
  void      femdarr5_asinh_to( femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_acosh(    femdarr5_t* arr);
  void      femdarr5_acosh_to( femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_tanh(     femdarr5_t* arr);
  void      femdarr5_tanh_to(  femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_sinh(     femdarr5_t* arr);
  void      femdarr5_sinh_to(  femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_cosh(     femdarr5_t* arr);
  void      femdarr5_cosh_to(  femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_atan(     femdarr5_t* arr);
  void      femdarr5_atan_to(  femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_asin(     femdarr5_t* arr);
  void      femdarr5_asin_to(  femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_acos(     femdarr5_t* arr);
  void      femdarr5_acos_to(  femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_tan(      femdarr5_t* arr);
  void      femdarr5_tan_to(   femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_sin(      femdarr5_t* arr);
  void      femdarr5_sin_to(   femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_cos(      femdarr5_t* arr);
  void      femdarr5_cos_to(   femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_logb(     femdarr5_t* arr, double base);
  void      femdarr5_logb_to(  femdarr5_t* arr, double base, femdarr5_t* res);
  femdarr5_t femdarr5_log10(    femdarr5_t* arr);
  void      femdarr5_log10_to( femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_log(      femdarr5_t* arr);
  void      femdarr5_log_to(   femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_exp(      femdarr5_t* arr);
  void      femdarr5_exp_to(   femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_cbrt(     femdarr5_t* arr);
  void      femdarr5_cbrt_to(  femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_sqrt(     femdarr5_t* arr);
  void      femdarr5_sqrt_to(  femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_pow(      femdarr5_t* arr, double e);
  void      femdarr5_pow_to(   femdarr5_t* arr, double e, femdarr5_t* res);
  
  
  # From ../../../include/oti/static/mdnum5/array/gauss/base.h
  
  void      femdarr5_get_order_im_to( ord_t order, femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_get_order_im(    ord_t order, femdarr5_t* arr);
  femdarr5_t femdarr5_get_deriv(   imdir_t idx, ord_t order, femdarr5_t* arr);
  void      femdarr5_get_deriv_to(imdir_t idx, ord_t order, femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_get_im(      imdir_t idx, ord_t order, femdarr5_t* arr);
  void      femdarr5_get_im_to(   imdir_t idx, ord_t order, femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_truncate_im(   imdir_t idx, ord_t order, femdarr5_t* arr);
  void      femdarr5_truncate_im_to(imdir_t idx, ord_t order, femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_copy(   femdarr5_t* src);
  void      femdarr5_copy_to(femdarr5_t* src, femdarr5_t* res);
  femdarr5_t femdarr5_get_im(    imdir_t idx, ord_t order, femdarr5_t* arr);
  void      femdarr5_get_im_to( imdir_t idx, ord_t order, femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_get_deriv(    imdir_t idx, ord_t order, femdarr5_t* arr);
  void      femdarr5_get_deriv_to( imdir_t idx, ord_t order, femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_extract_im(    imdir_t idx, ord_t order, femdarr5_t* arr);
  void      femdarr5_extract_im_to( imdir_t idx, ord_t order, femdarr5_t* arr,  femdarr5_t* res);
  femdarr5_t femdarr5_extract_deriv(    imdir_t idx, ord_t order, femdarr5_t* arr);
  void      femdarr5_extract_deriv_to( imdir_t idx, ord_t order, femdarr5_t* arr, femdarr5_t* res);
  mdarr5_t   femdarr5_get_item_k(  femdarr5_t* arr, uint64_t k);
  femdnum5_t  femdarr5_get_item_ij( femdarr5_t* arr, uint64_t i, uint64_t j);
  mdnum5_t femdarr5_get_item_ijk(femdarr5_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void femdarr5_get_item_ij_to(  femdarr5_t* arr, uint64_t i, uint64_t j,
                                 femdnum5_t* res);
  void femdarr5_get_item_k_to(   femdarr5_t* arr, uint64_t k,
                                  mdarr5_t* res);
  void femdarr5_get_item_ijk_to( femdarr5_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                mdnum5_t* res);
  femdarr5_t femdarr5_get_slice(femdarr5_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      femdarr5_get_slice_to(femdarr5_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr5_t* res);
  void femdarr5_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              femdarr5_t* res);
  void femdarr5_set_item_ij_o(  mdnum5_t* elm, uint64_t i, uint64_t j,
                               femdarr5_t* res);
  void femdarr5_set_item_ij_f(  femdnum5_t* elm, uint64_t i, uint64_t j,
                              femdarr5_t* res);
  void femdarr5_set_item_k_r(    coeff_t  elm, uint64_t k,
                              femdarr5_t* res);
  void femdarr5_set_item_k_o(  mdnum5_t* elm, uint64_t k,
                              femdarr5_t* res);
  void femdarr5_set_item_k_R(    mdarr5_t* elm, uint64_t k,
                            femdarr5_t* res);
  void femdarr5_set_item_k_O(    mdarr5_t* elm, uint64_t k,
                            femdarr5_t* res);
  void femdarr5_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr5_t* res);
  void femdarr5_set_item_ijk_o( mdnum5_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr5_t* res);
  void femdarr5_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr5_t* res);
  void femdarr5_set_slice_o( mdnum5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr5_t* res);
  void femdarr5_set_slice_f( femdnum5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr5_t* res);
  void femdarr5_set_slice_O( mdarr5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr5_t* res);
  void femdarr5_set_slice_F( femdarr5_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr5_t* res);
  void femdarr5_set_all_o( mdnum5_t* num, femdarr5_t* arr );
  void femdarr5_set_all_r(   coeff_t  num, femdarr5_t* arr );
  void femdarr5_set_all_f(  femdnum5_t* num, femdarr5_t* arr );
  void femdarr5_set_r(    coeff_t src, femdarr5_t* res );
  void femdarr5_set_o( mdnum5_t* src, femdarr5_t* res );
  void femdarr5_set_f(  femdnum5_t* src, femdarr5_t* res );
  void femdarr5_set_R(    darr_t* src, femdarr5_t* res );
  void femdarr5_set_O(   mdarr5_t* src, femdarr5_t* res );
  void femdarr5_set_F( femdarr5_t* src, femdarr5_t* res );
  femdarr5_t femdarr5_eye( uint64_t size,  uint64_t nip);
  femdarr5_t femdarr5_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  femdarr5_t femdarr5_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  femdarr5_t femdarr5_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void femdarr5_free(femdarr5_t* arr);
  femdarr5_t femdarr5_init();
  ord_t femdarr5_get_order(femdarr5_t* arr);
  
  
  # From ../../../include/oti/static/mdnum5/array/gauss/utils.h
  
  void femdarr5_dimCheck_FF_samesize(femdarr5_t* arr1, femdarr5_t* arr2, femdnum5_t* res);
  void femdarr5_dimCheck_OF_samesize(  mdarr5_t* arr1, femdarr5_t* arr2, femdnum5_t* res);
  void femdarr5_dimCheck_RF_samesize(   darr_t* arr1, femdarr5_t* arr2, femdnum5_t* res);
  void femdarr5_dimCheck_FF_elementwise(femdarr5_t* arr1, femdarr5_t* arr2, femdarr5_t* res);
  void femdarr5_dimCheck_OF_elementwise(  mdarr5_t* arr1, femdarr5_t* arr2, femdarr5_t* res);
  void femdarr5_dimCheck_RF_elementwise(   darr_t* arr1, femdarr5_t* arr2, femdarr5_t* res);
  void femdarr5_dimCheck_fF_elementwise( femdnum5_t* num1, femdarr5_t* arr2, femdarr5_t* res);
  void femdarr5_dimCheck_Ff_elementwise(femdarr5_t* arr1,  femdnum5_t* num2, femdarr5_t* res);
  void femdarr5_dimCheck_FF_matmul( femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  void femdarr5_dimCheck_OF_matmul(   mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  void femdarr5_dimCheck_RF_matmul(    darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  void femdarr5_dimCheck_FO_matmul( femdarr5_t* lhs,   mdarr5_t* rhs, femdarr5_t* res);
  void femdarr5_dimCheck_FR_matmul( femdarr5_t* lhs,    darr_t* rhs, femdarr5_t* res);
  void femdarr5_dimCheck_F_squareness( femdarr5_t* arr1, femdarr5_t* res);
  void femdarr5_dimCheck_F_transpose( femdarr5_t* arr1, femdarr5_t* res);
  void femdarr5_dimCheck_FfO_integrate(femdarr5_t* arr, femdnum5_t* num,mdarr5_t* res);
  void femdarr5_get_active_bases(femdarr5_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum5/array/gauss/algebra.h
  
  femdarr5_t femdarr5_neg(    femdarr5_t* arr);
  void      femdarr5_neg_to( femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t femdarr5_sum_FF(   femdarr5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_sum_FF_to(femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sum_fF(    femdnum5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_sum_fF_to( femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sum_OF(     mdarr5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_sum_OF_to(  mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sum_RF(      darr_t* lhs, femdarr5_t* rhs);
  void      femdarr5_sum_RF_to(   darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sum_oF(   mdnum5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_sum_oF_to(mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sum_rF(     coeff_t  lhs, femdarr5_t* rhs);
  void      femdarr5_sum_rF_to(  coeff_t  lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sub_FF(    femdarr5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_sub_FF_to( femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sub_fF(    femdnum5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_sub_fF_to( femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sub_Ff(    femdarr5_t* lhs, femdnum5_t* rhs);
  void      femdarr5_sub_Ff_to( femdarr5_t* lhs, femdnum5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sub_OF(      mdarr5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_sub_OF_to(   mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sub_FO(    femdarr5_t* lhs,   mdarr5_t* rhs);
  void      femdarr5_sub_FO_to( femdarr5_t* lhs,   mdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sub_RF(       darr_t* lhs, femdarr5_t* rhs);
  void      femdarr5_sub_RF_to(    darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sub_FR(    femdarr5_t* lhs,    darr_t* rhs);
  void      femdarr5_sub_FR_to( femdarr5_t* lhs,    darr_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sub_oF(    mdnum5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_sub_oF_to( mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sub_Fo(    femdarr5_t* lhs, mdnum5_t* rhs);
  void      femdarr5_sub_Fo_to( femdarr5_t* lhs, mdnum5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sub_rF(      coeff_t  lhs, femdarr5_t* rhs);
  void      femdarr5_sub_rF_to(    coeff_t lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_sub_Fr(    femdarr5_t* lhs,   coeff_t  rhs);
  void      femdarr5_sub_Fr_to( femdarr5_t* lhs,   coeff_t  rhs, femdarr5_t* res);
  femdarr5_t femdarr5_mul_FF(   femdarr5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_mul_FF_to(femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_mul_fF(    femdnum5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_mul_fF_to( femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_mul_OF(     mdarr5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_mul_OF_to(  mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_mul_RF(      darr_t* lhs, femdarr5_t* rhs);
  void      femdarr5_mul_RF_to(   darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_mul_oF(   mdnum5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_mul_oF_to(mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_mul_rF(     coeff_t  lhs, femdarr5_t* rhs);
  void      femdarr5_mul_rF_to(  coeff_t  lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_div_FF(    femdarr5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_div_FF_to( femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_div_fF(     femdnum5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_div_fF_to(  femdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_div_Ff(    femdarr5_t* lhs,  femdnum5_t* rhs);
  void      femdarr5_div_Ff_to( femdarr5_t* lhs,  femdnum5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_div_OF(      mdarr5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_div_OF_to(   mdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_div_FO(    femdarr5_t* lhs,   mdarr5_t* rhs);
  void      femdarr5_div_FO_to( femdarr5_t* lhs,   mdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_div_RF(       darr_t* lhs, femdarr5_t* rhs);
  void      femdarr5_div_RF_to(    darr_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_div_FR(    femdarr5_t* lhs,    darr_t* rhs);
  void      femdarr5_div_FR_to( femdarr5_t* lhs,    darr_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_div_oF(    mdnum5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_div_oF_to( mdnum5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_div_Fo(    femdarr5_t* lhs, mdnum5_t* rhs);
  void      femdarr5_div_Fo_to( femdarr5_t* lhs, mdnum5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_div_rF(      coeff_t  lhs, femdarr5_t* rhs);
  void      femdarr5_div_rF_to(    coeff_t lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_div_Fr(    femdarr5_t* lhs,   coeff_t  rhs);
  void      femdarr5_div_Fr_to( femdarr5_t* lhs,   coeff_t  rhs, femdarr5_t* res);
  mdarr5_t femdarr5_integrate(    femdarr5_t* arr, femdnum5_t* w);
  void    femdarr5_integrate_to( femdarr5_t* arr, femdnum5_t* w, mdarr5_t* res);
  femdnum5_t femdarr5_dotproduct_FF(    femdarr5_t* lhs, femdarr5_t* rhs);
  void     femdarr5_dotproduct_FF_to( femdarr5_t* lhs, femdarr5_t* rhs, femdnum5_t* res);
  femdnum5_t femdarr5_dotproduct_OF(      mdarr5_t* lhs, femdarr5_t* rhs);
  void     femdarr5_dotproduct_OF_to(   mdarr5_t* lhs, femdarr5_t* rhs, femdnum5_t* res);
  femdnum5_t femdarr5_dotproduct_RF(       darr_t* lhs, femdarr5_t* rhs);
  void     femdarr5_dotproduct_RF_to(    darr_t* lhs, femdarr5_t* rhs, femdnum5_t* res);
  femdarr5_t femdarr5_matmul_FF(    femdarr5_t* lhs, femdarr5_t* rhs);
  void      femdarr5_matmul_FF_to( femdarr5_t* lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_matmul_OF(    mdarr5_t*   lhs, femdarr5_t* rhs);
  void      femdarr5_matmul_OF_to( mdarr5_t*   lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_matmul_FO(    femdarr5_t* lhs, mdarr5_t*   rhs);
  void      femdarr5_matmul_FO_to( femdarr5_t* lhs, mdarr5_t*   rhs, femdarr5_t* res);
  femdarr5_t femdarr5_matmul_RF(    darr_t*    lhs, femdarr5_t* rhs);
  void      femdarr5_matmul_RF_to( darr_t*    lhs, femdarr5_t* rhs, femdarr5_t* res);
  femdarr5_t femdarr5_matmul_FR(    femdarr5_t* lhs, darr_t*    rhs);
  void      femdarr5_matmul_FR_to( femdarr5_t* lhs, darr_t*    rhs, femdarr5_t* res);
  femdnum5_t femdarr5_det(   femdarr5_t* arr);
  void     femdarr5_det_to(femdarr5_t* arr, femdnum5_t* res);
  femdnum5_t femdarr5_norm(     femdarr5_t* arr);
  void     femdarr5_norm_to(  femdarr5_t* arr, femdnum5_t* res);
  femdnum5_t femdarr5_pnorm(    femdarr5_t* arr, coeff_t p);
  void     femdarr5_pnorm_to( femdarr5_t* arr, coeff_t p, femdnum5_t* res);
  femdarr5_t   femdarr5_invert(    femdarr5_t* arr);
  void        femdarr5_invert_to( femdarr5_t* arr, femdarr5_t* res);
  femdarr5_t   femdarr5_transpose(   femdarr5_t* arr);
  void        femdarr5_transpose_to(femdarr5_t* arr, femdarr5_t* res);
  
  