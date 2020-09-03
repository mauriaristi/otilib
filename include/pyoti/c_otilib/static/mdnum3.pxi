cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/mdnum3/scalar/structures.h
  
  ctypedef struct  mdnum3_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e3;
    coeff_t e12;
    coeff_t e13;
    coeff_t e23;
    coeff_t e123;
  # } mdnum3_t;
  
  
  # From ../../../include/oti/static/mdnum3/array/structures.h
  
  ctypedef struct  mdarr3_t : # {
      mdnum3_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
      flag_t          flag;
  # } mdarr3_t;
  
  
  # From ../../../include/oti/static/mdnum3/scalar/gauss/structures.h
  
  ctypedef struct  femdnum3_t: # {
      mdnum3_t*  p_data;
      uint64_t    nip;
  # } femdnum3_t;
  
  
  # From ../../../include/oti/static/mdnum3/array/gauss/structures.h
  
  ctypedef struct  femdarr3_t: # {
      mdarr3_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } femdarr3_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/mdnum3/scalar/functions.h
  
  mdnum3_t mdnum3_atanh(mdnum3_t* num);
  void mdnum3_atanh_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_asinh(mdnum3_t* num);
  void mdnum3_asinh_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_acosh(mdnum3_t* num);
  void mdnum3_acosh_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_tanh(mdnum3_t* num);
  void mdnum3_tanh_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_sqrt(mdnum3_t* num);
  void mdnum3_sqrt_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_cbrt(mdnum3_t* num);
  void mdnum3_cbrt_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_cosh(mdnum3_t* num);
  void mdnum3_cosh_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_sinh(mdnum3_t* num);
  void mdnum3_sinh_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_asin(mdnum3_t* num);
  void mdnum3_asin_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_acos(mdnum3_t* num);
  void mdnum3_acos_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_atan(mdnum3_t* num);
  void mdnum3_atan_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_tan(mdnum3_t* num);
  void mdnum3_tan_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_cos(mdnum3_t* num);
  void mdnum3_cos_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_sin(mdnum3_t* num );
  void mdnum3_sin_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_logb(mdnum3_t* num, double base);
  void mdnum3_logb_to(mdnum3_t* num, double base, mdnum3_t* res);
  mdnum3_t mdnum3_log10(mdnum3_t* num);
  void mdnum3_log10_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_log(mdnum3_t* num);
  void mdnum3_log_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_exp(mdnum3_t* num);
  void mdnum3_exp_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_pow(mdnum3_t* num, double e);
  void mdnum3_pow_to(mdnum3_t* num, coeff_t e, mdnum3_t* res);
  
  
  # From ../../../include/oti/static/mdnum3/scalar/base.h
  
  void mdnum3_set_im_o(mdnum3_t* num, imdir_t idx, ord_t order, mdnum3_t* res);
  void mdnum3_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum3_t* res);
  void mdnum3_set_deriv_o(mdnum3_t* num, imdir_t idx, ord_t order, mdnum3_t* res);
  void mdnum3_extract_im_to( imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_extract_im(imdir_t idx, ord_t order, mdnum3_t* num);
  mdnum3_t mdnum3_extract_deriv(imdir_t idx, ord_t order, mdnum3_t* num);
  void mdnum3_extract_deriv_to(imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res);
  void mdnum3_get_im_to_o(imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_get_im_o(imdir_t idx, ord_t order, mdnum3_t* num);
  void mdnum3_get_im_to_r(imdir_t idx, ord_t order, mdnum3_t* num, coeff_t* res);
  ord_t mdnum3_get_order(mdnum3_t* lhs);
  mdnum3_t mdnum3_get_deriv_o( imdir_t idx, ord_t order, mdnum3_t* num);
  void mdnum3_get_deriv_to( imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res);
  void mdnum3_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum3_t* res);
  mdnum3_t mdnum3_init();
  ndir_t mdnum3_get_ndir_order(ord_t order, mdnum3_t* num);
  ndir_t mdnum3_get_ndir_total(mdnum3_t* num);
  coeff_t* mdnum3_get_order_address(ord_t order, mdnum3_t* num);
  mdnum3_t mdnum3_create_r(  coeff_t lhs);
  void mdnum3_set_r(  coeff_t lhs, mdnum3_t* res);
  void mdnum3_set_o(  mdnum3_t* lhs, mdnum3_t* res);
  mdnum3_t mdnum3_get_order_im(ord_t order, mdnum3_t* lhs);
  void mdnum3_get_order_im_to(ord_t order, mdnum3_t* lhs, mdnum3_t* res);
  coeff_t mdnum3_get_item(imdir_t idx, ord_t order, mdnum3_t* lhs);
  coeff_t mdnum3_get_deriv(imdir_t idx, ord_t order, mdnum3_t* lhs);
  void mdnum3_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum3_t* x);
  mdnum3_t mdnum3_copy(  mdnum3_t* lhs);
  void mdnum3_copy_to(  mdnum3_t* lhs, mdnum3_t* res);
  mdnum3_t mdnum3_taylor_integrate(coeff_t* deltas,mdnum3_t* lhs);
  void mdnum3_taylor_integrate_to(coeff_t* deltas,mdnum3_t* lhs, mdnum3_t* res);
  mdnum3_t mdnum3_truncate_im(imdir_t idx, ord_t order, mdnum3_t* lhs);
  void mdnum3_truncate_im_to(imdir_t idx, ord_t order, mdnum3_t* lhs, mdnum3_t* res);
  void mdnum3_print(  mdnum3_t* lhs);
  imdir_t mdnum3_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/mdnum3/scalar/utils.h
  
  void mdnum3_get_active_bases(mdnum3_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/mdnum3/scalar/algebra.h
  
  mdnum3_t mdnum3_abs(mdnum3_t* num);
  mdnum3_t mdnum3_div_ro(coeff_t num, mdnum3_t* den);
  mdnum3_t mdnum3_div_oo(mdnum3_t* num, mdnum3_t* den);
  mdnum3_t mdnum3_div_or(mdnum3_t* num, coeff_t val);
  void mdnum3_div_ro_to(coeff_t num, mdnum3_t* den, mdnum3_t* res);
  void mdnum3_div_oo_to(mdnum3_t* num, mdnum3_t* den, mdnum3_t* res);
  void mdnum3_div_or_to(mdnum3_t* num, coeff_t val, mdnum3_t* res);
  void mdnum3_abs_to(mdnum3_t* num, mdnum3_t* res);
  mdnum3_t mdnum3_neg(  mdnum3_t* lhs);
  void mdnum3_neg_to(  mdnum3_t* lhs, mdnum3_t* res);
  mdnum3_t mdnum3_sum_oo(  mdnum3_t* lhs,  mdnum3_t* rhs);
  void mdnum3_sum_oo_to(  mdnum3_t* lhs,  mdnum3_t* rhs, mdnum3_t* res);
  mdnum3_t mdnum3_sum_ro(  coeff_t lhs,  mdnum3_t* rhs);
  void mdnum3_sum_ro_to(  coeff_t lhs,  mdnum3_t* rhs, mdnum3_t* res);
  mdnum3_t mdnum3_sub_oo(  mdnum3_t* lhs,  mdnum3_t* rhs);
  void mdnum3_sub_oo_to(  mdnum3_t* lhs,  mdnum3_t* rhs, mdnum3_t* res);
  mdnum3_t mdnum3_sub_ro(  coeff_t lhs,  mdnum3_t* rhs);
  void mdnum3_sub_ro_to(  coeff_t lhs,  mdnum3_t* rhs, mdnum3_t* res);
  mdnum3_t mdnum3_sub_or(  mdnum3_t* lhs,  coeff_t rhs);
  void mdnum3_sub_or_to(  mdnum3_t* lhs,  coeff_t rhs, mdnum3_t* res);
  mdnum3_t mdnum3_mul_oo(  mdnum3_t* lhs,  mdnum3_t* rhs);
  void mdnum3_mul_oo_to(  mdnum3_t* lhs,  mdnum3_t* rhs, mdnum3_t* res);
  mdnum3_t mdnum3_mul_ro(  coeff_t lhs,  mdnum3_t* rhs);
  void mdnum3_mul_ro_to(  coeff_t lhs,  mdnum3_t* rhs, mdnum3_t* res);
  mdnum3_t mdnum3_trunc_mul_oo(  mdnum3_t* lhs,  mdnum3_t* rhs);
  void mdnum3_trunc_mul_oo_to(  mdnum3_t* lhs,  mdnum3_t* rhs, mdnum3_t* res);
  mdnum3_t mdnum3_gem_oo(  mdnum3_t* a,  mdnum3_t* b,  mdnum3_t* c);
  void mdnum3_gem_oo_to(  mdnum3_t* a,  mdnum3_t* b,  mdnum3_t* c, mdnum3_t* res);
  mdnum3_t mdnum3_gem_ro(  coeff_t a,  mdnum3_t* b,  mdnum3_t* c);
  void mdnum3_gem_ro_to(  coeff_t a,  mdnum3_t* b,  mdnum3_t* c, mdnum3_t* res);
  void mdnum3_trunc_gem_oo_to( ord_t ord_lhs,  mdnum3_t* a,  ord_t ord_rhs,  mdnum3_t* b,  mdnum3_t* c, mdnum3_t* res);
  mdnum3_t mdnum3_feval(coeff_t* feval_re, mdnum3_t* x);
  void mdnum3_feval_to(coeff_t* feval_re, mdnum3_t* x, mdnum3_t* res);
  
  
  # From ../../../include/oti/static/mdnum3/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum3/scalar/gauss/functions.h
  
  femdnum3_t femdnum3_atanh(    femdnum3_t* num);
  void     femdnum3_atanh_to( femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_asinh(    femdnum3_t* num);
  void     femdnum3_asinh_to( femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_acosh(    femdnum3_t* num);
  void     femdnum3_acosh_to( femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_tanh(     femdnum3_t* num);
  void     femdnum3_tanh_to(  femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_cosh(     femdnum3_t* num);
  void     femdnum3_cosh_to(  femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_sinh(     femdnum3_t* num);
  void     femdnum3_sinh_to(  femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_asin(     femdnum3_t* num);
  void     femdnum3_asin_to(  femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_acos(     femdnum3_t* num);
  void     femdnum3_acos_to(  femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_atan(     femdnum3_t* num);
  void     femdnum3_atan_to(  femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_tan(      femdnum3_t* num);
  void     femdnum3_tan_to(   femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_cos(      femdnum3_t* num);
  void     femdnum3_cos_to(   femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_sin(      femdnum3_t* num);
  void     femdnum3_sin_to(   femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_logb(     femdnum3_t* num, double base);
  void     femdnum3_logb_to(  femdnum3_t* num, double base, femdnum3_t* res);
  femdnum3_t femdnum3_log10(    femdnum3_t* num);
  void     femdnum3_log10_to( femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_log(      femdnum3_t* num);
  void     femdnum3_log_to(   femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_exp(      femdnum3_t* num);
  void     femdnum3_exp_to(   femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_cbrt(     femdnum3_t* num);
  void     femdnum3_cbrt_to(  femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_sqrt(     femdnum3_t* num);
  void     femdnum3_sqrt_to(  femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_pow(      femdnum3_t* num, double e);
  void     femdnum3_pow_to(   femdnum3_t* num, double e, femdnum3_t* res);
  mdnum3_t femdnum3_integrate(       femdnum3_t* num, femdnum3_t* w);
  void      femdnum3_integrate_to(    femdnum3_t* num, femdnum3_t* w, mdnum3_t* res);
  mdnum3_t femdnum3_integrate_f(     femdnum3_t* num, femdnum3_t* w);
  void      femdnum3_integrate_f_to(  femdnum3_t* num, femdnum3_t* w, mdnum3_t* res);
  mdnum3_t femdnum3_integrate_r(       coeff_t num, femdnum3_t* w);
  void      femdnum3_integrate_r_to(    coeff_t num, femdnum3_t* w, mdnum3_t* res);
  mdnum3_t femdnum3_integrate_o(    mdnum3_t* num, femdnum3_t* w);
  void      femdnum3_integrate_o_to( mdnum3_t* num, femdnum3_t* w, mdnum3_t* res);
  
  
  # From ../../../include/oti/static/mdnum3/scalar/gauss/base.h
  
  void     femdnum3_get_order_im_to( ord_t order, femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_get_order_im(    ord_t order, femdnum3_t* num);
  femdnum3_t femdnum3_get_im(    imdir_t idx, ord_t order, femdnum3_t* num);
  void     femdnum3_get_im_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_get_deriv(    imdir_t idx, ord_t order, femdnum3_t* num);
  void     femdnum3_get_deriv_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res);
  void femdnum3_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum3_t* num);
  void femdnum3_set_im_o( mdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num);
  void femdnum3_set_im_f(  femdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num);
  void femdnum3_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum3_t* num);
  void femdnum3_set_deriv_o( mdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num);
  void femdnum3_set_deriv_f(  femdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num);
  femdnum3_t femdnum3_extract_im(    imdir_t idx, ord_t order, femdnum3_t* num);
  void     femdnum3_extract_im_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_extract_deriv(    imdir_t idx, ord_t order, femdnum3_t* num);
  void     femdnum3_extract_deriv_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_truncate_im(    imdir_t idx, ord_t order, femdnum3_t* num);
  void     femdnum3_truncate_im_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_copy(    femdnum3_t* src);
  void     femdnum3_copy_to( femdnum3_t* src, femdnum3_t* dst);
  void femdnum3_set_r(    coeff_t num, femdnum3_t* res);
  void femdnum3_set_o( mdnum3_t* num, femdnum3_t* res);
  void femdnum3_set_f(  femdnum3_t* num, femdnum3_t* res);
  void femdnum3_set_item_k_r(   coeff_t  num, uint64_t k, femdnum3_t* res);
  void femdnum3_set_item_k_o( mdnum3_t* num, uint64_t k, femdnum3_t* res);
  mdnum3_t femdnum3_get_item_k(   femdnum3_t* num, uint64_t k);
  void      femdnum3_get_item_k_to(femdnum3_t* num, uint64_t k, mdnum3_t* res);
  femdnum3_t femdnum3_zeros(uint64_t nIntPts);
  femdnum3_t femdnum3_createEmpty(uint64_t nIntPts);
  femdnum3_t femdnum3_empty_like(femdnum3_t* arr);
  void femdnum3_free(femdnum3_t* num);
  ord_t femdnum3_get_order( femdnum3_t* num );
  femdnum3_t femdnum3_init();
  
  
  # From ../../../include/oti/static/mdnum3/scalar/gauss/utils.h
  
  void femdnum3_dimCheck(femdnum3_t* arr1,femdnum3_t* arr2);
  void femdnum3_get_active_bases(femdnum3_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum3/scalar/gauss/algebra.h
  
  femdnum3_t femdnum3_neg(   femdnum3_t* num);
  void     femdnum3_neg_to(femdnum3_t* num, femdnum3_t* res);
  femdnum3_t femdnum3_sum_ff(   femdnum3_t* lhs, femdnum3_t* rhs);
  void     femdnum3_sum_ff_to(femdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_sum_of(   mdnum3_t* lhs, femdnum3_t* rhs);
  void     femdnum3_sum_of_to(mdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_sum_rf(   coeff_t lhs, femdnum3_t* rhs);
  void     femdnum3_sum_rf_to(coeff_t lhs, femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_sub_ff(     femdnum3_t* lhs,  femdnum3_t* rhs);
  void     femdnum3_sub_ff_to(  femdnum3_t* lhs,  femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_sub_of(    mdnum3_t* lhs,  femdnum3_t* rhs);
  void     femdnum3_sub_of_to( mdnum3_t* lhs,  femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_sub_fo(     femdnum3_t* lhs, mdnum3_t* rhs);
  void     femdnum3_sub_fo_to(  femdnum3_t* lhs, mdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_sub_rf(       coeff_t lhs,  femdnum3_t* rhs);
  void     femdnum3_sub_rf_to(    coeff_t lhs,  femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_sub_fr(     femdnum3_t* lhs,    coeff_t rhs);
  void     femdnum3_sub_fr_to(  femdnum3_t* lhs,    coeff_t rhs, femdnum3_t* res);
  femdnum3_t femdnum3_mul_ff(   femdnum3_t* lhs, femdnum3_t* rhs);
  void     femdnum3_mul_ff_to(femdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_mul_of(   mdnum3_t* lhs, femdnum3_t* rhs);
  void     femdnum3_mul_of_to(mdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_mul_rf(   coeff_t lhs, femdnum3_t* rhs);
  void     femdnum3_mul_rf_to(coeff_t lhs, femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_div_ff(     femdnum3_t* lhs,  femdnum3_t* rhs);
  void     femdnum3_div_ff_to(  femdnum3_t* lhs,  femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_div_of(    mdnum3_t* lhs,  femdnum3_t* rhs);
  void     femdnum3_div_of_to( mdnum3_t* lhs,  femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_div_fo(     femdnum3_t* lhs, mdnum3_t* rhs);
  void     femdnum3_div_fo_to(  femdnum3_t* lhs, mdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_div_rf(       coeff_t lhs,  femdnum3_t* rhs);
  void     femdnum3_div_rf_to(    coeff_t lhs,  femdnum3_t* rhs, femdnum3_t* res);
  femdnum3_t femdnum3_div_fr(     femdnum3_t* lhs,    coeff_t rhs);
  void     femdnum3_div_fr_to(  femdnum3_t* lhs,    coeff_t rhs, femdnum3_t* res);
  
  
  # From ../../../include/oti/static/mdnum3/array/functions.h
  
  mdarr3_t mdarr3_atanh(   mdarr3_t* arr);
  void    mdarr3_atanh_to(mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_asinh(   mdarr3_t* arr);
  void    mdarr3_asinh_to(mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_acosh(   mdarr3_t* arr);
  void    mdarr3_acosh_to(mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_tanh(    mdarr3_t* arr);
  void    mdarr3_tanh_to( mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_cbrt(    mdarr3_t* arr);
  void    mdarr3_cbrt_to( mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_sqrt(    mdarr3_t* arr);
  void    mdarr3_sqrt_to( mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_cosh(    mdarr3_t* arr);
  void    mdarr3_cosh_to( mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_sinh(    mdarr3_t* arr);
  void    mdarr3_sinh_to( mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_asin(    mdarr3_t* arr);
  void    mdarr3_asin_to( mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_acos(    mdarr3_t* arr);
  void    mdarr3_acos_to( mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_atan(    mdarr3_t* arr);
  void    mdarr3_atan_to( mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_tan(     mdarr3_t* arr);
  void    mdarr3_tan_to(  mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_cos(     mdarr3_t* arr);
  void    mdarr3_cos_to(  mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_sin(     mdarr3_t* arr);
  void    mdarr3_sin_to(  mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_logb(    mdarr3_t* arr, double base);
  void    mdarr3_logb_to( mdarr3_t* arr, double base, mdarr3_t* res);
  mdarr3_t mdarr3_log10(   mdarr3_t* arr);
  void    mdarr3_log10_to(mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_log(     mdarr3_t* arr);
  void    mdarr3_log_to(  mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_exp(     mdarr3_t* arr);
  void    mdarr3_exp_to(  mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_pow(     mdarr3_t* arr, double e);
  void    mdarr3_pow_to(  mdarr3_t* arr, double e, mdarr3_t* res);
  
  
  # From ../../../include/oti/static/mdnum3/array/algebra_elementwise.h
  
  mdarr3_t mdarr3_neg(mdarr3_t* arr);
  void mdarr3_neg_to(mdarr3_t* rhs, mdarr3_t* res);
  mdarr3_t mdarr3_sum_OO(mdarr3_t*   lhs, mdarr3_t* rhs);
  mdarr3_t mdarr3_sum_RO(darr_t*    lhs, mdarr3_t* rhs);
  mdarr3_t mdarr3_sum_oO(mdnum3_t* lhs, mdarr3_t* rhs);
  mdarr3_t mdarr3_sum_rO(coeff_t    lhs, mdarr3_t* rhs);
  void mdarr3_sum_OO_to(mdarr3_t*   lhs, mdarr3_t* rhs, mdarr3_t* res);
  void mdarr3_sum_RO_to(darr_t*    lhs, mdarr3_t* rhs, mdarr3_t* res);
  void mdarr3_sum_oO_to(mdnum3_t* lhs, mdarr3_t* rhs, mdarr3_t* res);
  void mdarr3_sum_rO_to(coeff_t    lhs, mdarr3_t* rhs, mdarr3_t* res);
  mdarr3_t mdarr3_sub_OO(mdarr3_t*   lhs, mdarr3_t*   rhs);
  mdarr3_t mdarr3_sub_RO(darr_t*    lhs, mdarr3_t*   rhs);
  mdarr3_t mdarr3_sub_OR(mdarr3_t*   lhs, darr_t*    rhs);
  mdarr3_t mdarr3_sub_oO(mdnum3_t* lhs, mdarr3_t*   rhs);
  mdarr3_t mdarr3_sub_Oo(mdarr3_t*   lhs, mdnum3_t* rhs);
  mdarr3_t mdarr3_sub_rO(coeff_t    lhs, mdarr3_t*   rhs);
  mdarr3_t mdarr3_sub_Or(mdarr3_t*   lhs, coeff_t    rhs);
  void mdarr3_sub_OO_to( mdarr3_t*   lhs, mdarr3_t*   rhs, mdarr3_t* res);
  void mdarr3_sub_RO_to( darr_t*    lhs, mdarr3_t*   rhs, mdarr3_t* res);
  void mdarr3_sub_OR_to( mdarr3_t*   lhs, darr_t*    rhs, mdarr3_t* res);
  void mdarr3_sub_oO_to( mdnum3_t* lhs, mdarr3_t*   rhs, mdarr3_t* res);
  void mdarr3_sub_Oo_to( mdarr3_t*   lhs, mdnum3_t* rhs, mdarr3_t* res);
  void mdarr3_sub_rO_to( coeff_t    lhs, mdarr3_t*   rhs, mdarr3_t* res);
  void mdarr3_sub_Or_to( mdarr3_t*   lhs, coeff_t    rhs, mdarr3_t* res);
  mdarr3_t mdarr3_mul_OO(mdarr3_t*   lhs, mdarr3_t* rhs);
  mdarr3_t mdarr3_mul_RO(darr_t*    lhs, mdarr3_t* rhs);
  mdarr3_t mdarr3_mul_oO(mdnum3_t* lhs, mdarr3_t* rhs);
  mdarr3_t mdarr3_mul_rO(coeff_t    lhs, mdarr3_t* rhs);
  void mdarr3_mul_OO_to(mdarr3_t*   lhs, mdarr3_t* rhs, mdarr3_t* res);
  void mdarr3_mul_RO_to(darr_t*    lhs, mdarr3_t* rhs, mdarr3_t* res);
  void mdarr3_mul_oO_to(mdnum3_t* lhs, mdarr3_t* rhs, mdarr3_t* res);
  void mdarr3_mul_rO_to(coeff_t    lhs, mdarr3_t* rhs, mdarr3_t* res);
  void mdarr3_gem_OO_to(  mdarr3_t* arr1, mdarr3_t* arr2, mdarr3_t* arr3, mdarr3_t* res);
  void mdarr3_gem_oO_to(mdnum3_t* arr1, mdarr3_t* arr2, mdarr3_t* arr3, mdarr3_t* res);
  mdarr3_t mdarr3_div_OO(mdarr3_t*   lhs, mdarr3_t*   rhs);
  mdarr3_t mdarr3_div_OR(mdarr3_t*   lhs, darr_t*    rhs);
  mdarr3_t mdarr3_div_RO(darr_t*    lhs, mdarr3_t*   rhs);
  mdarr3_t mdarr3_div_oO(mdnum3_t* lhs, mdarr3_t*   rhs);
  mdarr3_t mdarr3_div_Oo(mdarr3_t*   lhs, mdnum3_t* rhs);
  mdarr3_t mdarr3_div_rO(coeff_t    lhs, mdarr3_t*   rhs);
  mdarr3_t mdarr3_div_Or(mdarr3_t*   lhs, coeff_t    rhs);
  void mdarr3_div_OO_to(mdarr3_t*   lhs, mdarr3_t*   rhs, mdarr3_t* res);
  void mdarr3_div_RO_to(darr_t*    lhs, mdarr3_t*   rhs, mdarr3_t* res);
  void mdarr3_div_OR_to(mdarr3_t*   lhs, darr_t*    rhs, mdarr3_t* res);
  void mdarr3_div_oO_to(mdnum3_t* lhs, mdarr3_t*   rhs, mdarr3_t* res);
  void mdarr3_div_Oo_to(mdarr3_t*   lhs, mdnum3_t* rhs, mdarr3_t* res);
  void mdarr3_div_rO_to(coeff_t    lhs, mdarr3_t*   rhs, mdarr3_t* res);
  void mdarr3_div_Or_to(mdarr3_t*   lhs, coeff_t    rhs, mdarr3_t* res);
  
  
  # From ../../../include/oti/static/mdnum3/array/base.h
  
  void    mdarr3_taylor_integrate_to( coeff_t* deltas, mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_taylor_integrate(    coeff_t* deltas, mdarr3_t* arr);
  void    mdarr3_get_order_im_to( ord_t order, mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_get_order_im(    ord_t order, mdarr3_t* arr);
  void mdarr3_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr3_t* res);
  void mdarr3_set_slice_O( mdarr3_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr3_t* res);
  void mdarr3_set_slice_o( mdnum3_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr3_t* res);
  mdarr3_t mdarr3_get_slice( mdarr3_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void mdarr3_get_slice_to( mdarr3_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr3_t* res);
  mdarr3_t mdarr3_truncate_im(    imdir_t idx, ord_t order, mdarr3_t* arr);
  void    mdarr3_truncate_im_to( imdir_t idx, ord_t order, mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_extract_im(   imdir_t idx, ord_t order, mdarr3_t* arr);
  void    mdarr3_extract_im_to(imdir_t idx, ord_t order, mdarr3_t* arr, mdarr3_t* res);
  darr_t  mdarr3_get_deriv(    imdir_t idx, ord_t order, mdarr3_t* arr);
  void    mdarr3_get_deriv_to( imdir_t idx, ord_t order, mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_get_deriv_o(  imdir_t idx, ord_t order, mdarr3_t* arr);
  mdarr3_t mdarr3_extract_deriv(    imdir_t idx, ord_t order, mdarr3_t* arr);
  void    mdarr3_extract_deriv_to( imdir_t idx, ord_t order, mdarr3_t* arr, mdarr3_t* res);
  darr_t  mdarr3_get_im(   imdir_t idx, ord_t order, mdarr3_t* arr);
  mdarr3_t mdarr3_get_im_o( imdir_t idx, ord_t order, mdarr3_t* arr);
  void    mdarr3_get_im_to(imdir_t idx, ord_t order, mdarr3_t* arr, mdarr3_t* res);
  void    mdarr3_copy_to(mdarr3_t* arr, mdarr3_t* res);
  mdarr3_t mdarr3_copy(mdarr3_t* arr);
  void mdarr3_set_all_r( coeff_t num, mdarr3_t* arr);
  void mdarr3_set_item_i_r( coeff_t num, uint64_t i, mdarr3_t* arr);
  void mdarr3_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, mdarr3_t* arr);
  void mdarr3_set_r(   coeff_t  num,   mdarr3_t* arr);
  void mdarr3_set_o( mdnum3_t* num,   mdarr3_t* arr);
  void mdarr3_set_O(   mdarr3_t* arrin, mdarr3_t* arr);
  void mdarr3_set_all_o( mdnum3_t* src, mdarr3_t* arr);
  void mdarr3_set_item_i_o( mdnum3_t* num, uint64_t i, mdarr3_t* arr);
  void mdarr3_set_item_ij_o( mdnum3_t* num, uint64_t i, uint64_t j, mdarr3_t* arr);
  mdnum3_t mdarr3_get_item_i(    mdarr3_t* arr, uint64_t i);
  void      mdarr3_get_item_i_to( mdarr3_t* arr, uint64_t i,             mdnum3_t* res);
  mdnum3_t mdarr3_get_item_ij(   mdarr3_t* arr, uint64_t i, uint64_t j);
  void      mdarr3_get_item_ij_to(mdarr3_t* arr, uint64_t i, uint64_t j, mdnum3_t* res);
  mdarr3_t mdarr3_init();
  void mdarr3_free(mdarr3_t* arr);
  mdarr3_t mdarr3_empty_like(mdarr3_t* arr);
  mdarr3_t mdarr3_eye(uint64_t nrows);
  mdarr3_t mdarr3_ones(uint64_t nrows, uint64_t ncols);
  mdarr3_t mdarr3_zeros(uint64_t nrows, uint64_t ncols);
  mdarr3_t mdarr3_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/mdnum3/array/utils.h
  
  void mdarr3_dimCheck_OO_elementwise(mdarr3_t* arr1, mdarr3_t* arr2, mdarr3_t* res);
  void mdarr3_dimCheck_RO_elementwise(darr_t*  arr1, mdarr3_t* arr2, mdarr3_t* res);
  void mdarr3_dimCheck_OO_matmul(mdarr3_t* arr1, mdarr3_t* arr2, mdarr3_t* res);
  void mdarr3_dimCheck_RO_matmul(darr_t*  arr1, mdarr3_t* arr2, mdarr3_t* res);
  void mdarr3_dimCheck_OR_matmul(mdarr3_t* arr1, darr_t*  arr2, mdarr3_t* res);
  void mdarr3_dimCheck_O_squareness(mdarr3_t* arr1, mdarr3_t* res);
  void mdarr3_dimCheck_OO_samesize(mdarr3_t* arr1, mdarr3_t* res);
  void mdarr3_dimCheck_RO_samesize(darr_t* arr1, mdarr3_t* res);
  ord_t mdarr3_get_order(mdarr3_t* arr);
  void mdarr3_get_active_bases(mdarr3_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum3/array/algebra_matops.h
  
  mdnum3_t mdarr3_dotproduct_OO(    mdarr3_t* lhs, mdarr3_t* rhs);
  void      mdarr3_dotproduct_OO_to( mdarr3_t* lhs, mdarr3_t* rhs, mdnum3_t* res);
  mdnum3_t mdarr3_dotproduct_RO(     darr_t* lhs, mdarr3_t* rhs);
  void      mdarr3_dotproduct_RO_to(  darr_t* lhs, mdarr3_t* rhs, mdnum3_t* res);
  mdarr3_t mdarr3_matmul_OO(    mdarr3_t* lhs, mdarr3_t* rhs);
  mdarr3_t mdarr3_matmul_OR(    mdarr3_t* lhs,  darr_t* rhs);
  mdarr3_t mdarr3_matmul_RO(     darr_t* lhs, mdarr3_t* rhs);
  void    mdarr3_matmul_OO_to( mdarr3_t* lhs, mdarr3_t* rhs, mdarr3_t* res);
  void    mdarr3_matmul_OR_to( mdarr3_t* lhs,  darr_t* rhs, mdarr3_t* res);
  void    mdarr3_matmul_RO_to(  darr_t* lhs, mdarr3_t* rhs, mdarr3_t* res);
  mdarr3_t mdarr3_transpose(    mdarr3_t* arr1);
  void    mdarr3_transpose_to( mdarr3_t* arr1, mdarr3_t* res);
  mdarr3_t mdarr3_invert(    mdarr3_t* arr1);
  void    mdarr3_invert_to( mdarr3_t* arr1, mdarr3_t* res);
  mdnum3_t mdarr3_det(    mdarr3_t* arr1);
  void      mdarr3_det_to( mdarr3_t* arr1, mdnum3_t* res);
  mdnum3_t mdarr3_norm(    mdarr3_t* arr1);
  void      mdarr3_norm_to( mdarr3_t* arr1,  mdnum3_t* res);
  mdnum3_t mdarr3_pnorm(    mdarr3_t* arr1, coeff_t p);
  void      mdarr3_pnorm_to( mdarr3_t* arr1, coeff_t p, mdnum3_t* res);
  
  
  # From ../../../include/oti/static/mdnum3/array/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum3/array/gauss/functions.h
  
  femdarr3_t femdarr3_atanh(    femdarr3_t* arr);
  void      femdarr3_atanh_to( femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_asinh(    femdarr3_t* arr);
  void      femdarr3_asinh_to( femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_acosh(    femdarr3_t* arr);
  void      femdarr3_acosh_to( femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_tanh(     femdarr3_t* arr);
  void      femdarr3_tanh_to(  femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_sinh(     femdarr3_t* arr);
  void      femdarr3_sinh_to(  femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_cosh(     femdarr3_t* arr);
  void      femdarr3_cosh_to(  femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_atan(     femdarr3_t* arr);
  void      femdarr3_atan_to(  femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_asin(     femdarr3_t* arr);
  void      femdarr3_asin_to(  femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_acos(     femdarr3_t* arr);
  void      femdarr3_acos_to(  femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_tan(      femdarr3_t* arr);
  void      femdarr3_tan_to(   femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_sin(      femdarr3_t* arr);
  void      femdarr3_sin_to(   femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_cos(      femdarr3_t* arr);
  void      femdarr3_cos_to(   femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_logb(     femdarr3_t* arr, double base);
  void      femdarr3_logb_to(  femdarr3_t* arr, double base, femdarr3_t* res);
  femdarr3_t femdarr3_log10(    femdarr3_t* arr);
  void      femdarr3_log10_to( femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_log(      femdarr3_t* arr);
  void      femdarr3_log_to(   femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_exp(      femdarr3_t* arr);
  void      femdarr3_exp_to(   femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_cbrt(     femdarr3_t* arr);
  void      femdarr3_cbrt_to(  femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_sqrt(     femdarr3_t* arr);
  void      femdarr3_sqrt_to(  femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_pow(      femdarr3_t* arr, double e);
  void      femdarr3_pow_to(   femdarr3_t* arr, double e, femdarr3_t* res);
  
  
  # From ../../../include/oti/static/mdnum3/array/gauss/base.h
  
  void      femdarr3_get_order_im_to( ord_t order, femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_get_order_im(    ord_t order, femdarr3_t* arr);
  femdarr3_t femdarr3_get_deriv(   imdir_t idx, ord_t order, femdarr3_t* arr);
  void      femdarr3_get_deriv_to(imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_get_im(      imdir_t idx, ord_t order, femdarr3_t* arr);
  void      femdarr3_get_im_to(   imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_truncate_im(   imdir_t idx, ord_t order, femdarr3_t* arr);
  void      femdarr3_truncate_im_to(imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_copy(   femdarr3_t* src);
  void      femdarr3_copy_to(femdarr3_t* src, femdarr3_t* res);
  femdarr3_t femdarr3_get_im(    imdir_t idx, ord_t order, femdarr3_t* arr);
  void      femdarr3_get_im_to( imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_get_deriv(    imdir_t idx, ord_t order, femdarr3_t* arr);
  void      femdarr3_get_deriv_to( imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_extract_im(    imdir_t idx, ord_t order, femdarr3_t* arr);
  void      femdarr3_extract_im_to( imdir_t idx, ord_t order, femdarr3_t* arr,  femdarr3_t* res);
  femdarr3_t femdarr3_extract_deriv(    imdir_t idx, ord_t order, femdarr3_t* arr);
  void      femdarr3_extract_deriv_to( imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);
  mdarr3_t   femdarr3_get_item_k(  femdarr3_t* arr, uint64_t k);
  femdnum3_t  femdarr3_get_item_ij( femdarr3_t* arr, uint64_t i, uint64_t j);
  mdnum3_t femdarr3_get_item_ijk(femdarr3_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void femdarr3_get_item_ij_to(  femdarr3_t* arr, uint64_t i, uint64_t j,
                                 femdnum3_t* res);
  void femdarr3_get_item_k_to(   femdarr3_t* arr, uint64_t k,
                                  mdarr3_t* res);
  void femdarr3_get_item_ijk_to( femdarr3_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                mdnum3_t* res);
  femdarr3_t femdarr3_get_slice(femdarr3_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      femdarr3_get_slice_to(femdarr3_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr3_t* res);
  void femdarr3_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              femdarr3_t* res);
  void femdarr3_set_item_ij_o(  mdnum3_t* elm, uint64_t i, uint64_t j,
                               femdarr3_t* res);
  void femdarr3_set_item_ij_f(  femdnum3_t* elm, uint64_t i, uint64_t j,
                              femdarr3_t* res);
  void femdarr3_set_item_k_r(    coeff_t  elm, uint64_t k,
                              femdarr3_t* res);
  void femdarr3_set_item_k_o(  mdnum3_t* elm, uint64_t k,
                              femdarr3_t* res);
  void femdarr3_set_item_k_R(    mdarr3_t* elm, uint64_t k,
                            femdarr3_t* res);
  void femdarr3_set_item_k_O(    mdarr3_t* elm, uint64_t k,
                            femdarr3_t* res);
  void femdarr3_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr3_t* res);
  void femdarr3_set_item_ijk_o( mdnum3_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr3_t* res);
  void femdarr3_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr3_t* res);
  void femdarr3_set_slice_o( mdnum3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr3_t* res);
  void femdarr3_set_slice_f( femdnum3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr3_t* res);
  void femdarr3_set_slice_O( mdarr3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr3_t* res);
  void femdarr3_set_slice_F( femdarr3_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr3_t* res);
  void femdarr3_set_all_o( mdnum3_t* num, femdarr3_t* arr );
  void femdarr3_set_all_r(   coeff_t  num, femdarr3_t* arr );
  void femdarr3_set_all_f(  femdnum3_t* num, femdarr3_t* arr );
  void femdarr3_set_r(    coeff_t src, femdarr3_t* res );
  void femdarr3_set_o( mdnum3_t* src, femdarr3_t* res );
  void femdarr3_set_f(  femdnum3_t* src, femdarr3_t* res );
  void femdarr3_set_R(    darr_t* src, femdarr3_t* res );
  void femdarr3_set_O(   mdarr3_t* src, femdarr3_t* res );
  void femdarr3_set_F( femdarr3_t* src, femdarr3_t* res );
  femdarr3_t femdarr3_eye( uint64_t size,  uint64_t nip);
  femdarr3_t femdarr3_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  femdarr3_t femdarr3_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  femdarr3_t femdarr3_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void femdarr3_free(femdarr3_t* arr);
  femdarr3_t femdarr3_init();
  ord_t femdarr3_get_order(femdarr3_t* arr);
  
  
  # From ../../../include/oti/static/mdnum3/array/gauss/utils.h
  
  void femdarr3_dimCheck_FF_samesize(femdarr3_t* arr1, femdarr3_t* arr2, femdnum3_t* res);
  void femdarr3_dimCheck_OF_samesize(  mdarr3_t* arr1, femdarr3_t* arr2, femdnum3_t* res);
  void femdarr3_dimCheck_RF_samesize(   darr_t* arr1, femdarr3_t* arr2, femdnum3_t* res);
  void femdarr3_dimCheck_FF_elementwise(femdarr3_t* arr1, femdarr3_t* arr2, femdarr3_t* res);
  void femdarr3_dimCheck_OF_elementwise(  mdarr3_t* arr1, femdarr3_t* arr2, femdarr3_t* res);
  void femdarr3_dimCheck_RF_elementwise(   darr_t* arr1, femdarr3_t* arr2, femdarr3_t* res);
  void femdarr3_dimCheck_fF_elementwise( femdnum3_t* num1, femdarr3_t* arr2, femdarr3_t* res);
  void femdarr3_dimCheck_Ff_elementwise(femdarr3_t* arr1,  femdnum3_t* num2, femdarr3_t* res);
  void femdarr3_dimCheck_FF_matmul( femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  void femdarr3_dimCheck_OF_matmul(   mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  void femdarr3_dimCheck_RF_matmul(    darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  void femdarr3_dimCheck_FO_matmul( femdarr3_t* lhs,   mdarr3_t* rhs, femdarr3_t* res);
  void femdarr3_dimCheck_FR_matmul( femdarr3_t* lhs,    darr_t* rhs, femdarr3_t* res);
  void femdarr3_dimCheck_F_squareness( femdarr3_t* arr1, femdarr3_t* res);
  void femdarr3_dimCheck_F_transpose( femdarr3_t* arr1, femdarr3_t* res);
  void femdarr3_dimCheck_FfO_integrate(femdarr3_t* arr, femdnum3_t* num,mdarr3_t* res);
  void femdarr3_get_active_bases(femdarr3_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum3/array/gauss/algebra.h
  
  femdarr3_t femdarr3_neg(    femdarr3_t* arr);
  void      femdarr3_neg_to( femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t femdarr3_sum_FF(   femdarr3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_sum_FF_to(femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sum_fF(    femdnum3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_sum_fF_to( femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sum_OF(     mdarr3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_sum_OF_to(  mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sum_RF(      darr_t* lhs, femdarr3_t* rhs);
  void      femdarr3_sum_RF_to(   darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sum_oF(   mdnum3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_sum_oF_to(mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sum_rF(     coeff_t  lhs, femdarr3_t* rhs);
  void      femdarr3_sum_rF_to(  coeff_t  lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sub_FF(    femdarr3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_sub_FF_to( femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sub_fF(    femdnum3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_sub_fF_to( femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sub_Ff(    femdarr3_t* lhs, femdnum3_t* rhs);
  void      femdarr3_sub_Ff_to( femdarr3_t* lhs, femdnum3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sub_OF(      mdarr3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_sub_OF_to(   mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sub_FO(    femdarr3_t* lhs,   mdarr3_t* rhs);
  void      femdarr3_sub_FO_to( femdarr3_t* lhs,   mdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sub_RF(       darr_t* lhs, femdarr3_t* rhs);
  void      femdarr3_sub_RF_to(    darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sub_FR(    femdarr3_t* lhs,    darr_t* rhs);
  void      femdarr3_sub_FR_to( femdarr3_t* lhs,    darr_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sub_oF(    mdnum3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_sub_oF_to( mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sub_Fo(    femdarr3_t* lhs, mdnum3_t* rhs);
  void      femdarr3_sub_Fo_to( femdarr3_t* lhs, mdnum3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sub_rF(      coeff_t  lhs, femdarr3_t* rhs);
  void      femdarr3_sub_rF_to(    coeff_t lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_sub_Fr(    femdarr3_t* lhs,   coeff_t  rhs);
  void      femdarr3_sub_Fr_to( femdarr3_t* lhs,   coeff_t  rhs, femdarr3_t* res);
  femdarr3_t femdarr3_mul_FF(   femdarr3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_mul_FF_to(femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_mul_fF(    femdnum3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_mul_fF_to( femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_mul_OF(     mdarr3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_mul_OF_to(  mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_mul_RF(      darr_t* lhs, femdarr3_t* rhs);
  void      femdarr3_mul_RF_to(   darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_mul_oF(   mdnum3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_mul_oF_to(mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_mul_rF(     coeff_t  lhs, femdarr3_t* rhs);
  void      femdarr3_mul_rF_to(  coeff_t  lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_div_FF(    femdarr3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_div_FF_to( femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_div_fF(     femdnum3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_div_fF_to(  femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_div_Ff(    femdarr3_t* lhs,  femdnum3_t* rhs);
  void      femdarr3_div_Ff_to( femdarr3_t* lhs,  femdnum3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_div_OF(      mdarr3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_div_OF_to(   mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_div_FO(    femdarr3_t* lhs,   mdarr3_t* rhs);
  void      femdarr3_div_FO_to( femdarr3_t* lhs,   mdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_div_RF(       darr_t* lhs, femdarr3_t* rhs);
  void      femdarr3_div_RF_to(    darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_div_FR(    femdarr3_t* lhs,    darr_t* rhs);
  void      femdarr3_div_FR_to( femdarr3_t* lhs,    darr_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_div_oF(    mdnum3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_div_oF_to( mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_div_Fo(    femdarr3_t* lhs, mdnum3_t* rhs);
  void      femdarr3_div_Fo_to( femdarr3_t* lhs, mdnum3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_div_rF(      coeff_t  lhs, femdarr3_t* rhs);
  void      femdarr3_div_rF_to(    coeff_t lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_div_Fr(    femdarr3_t* lhs,   coeff_t  rhs);
  void      femdarr3_div_Fr_to( femdarr3_t* lhs,   coeff_t  rhs, femdarr3_t* res);
  mdarr3_t femdarr3_integrate(    femdarr3_t* arr, femdnum3_t* w);
  void    femdarr3_integrate_to( femdarr3_t* arr, femdnum3_t* w, mdarr3_t* res);
  femdnum3_t femdarr3_dotproduct_FF(    femdarr3_t* lhs, femdarr3_t* rhs);
  void     femdarr3_dotproduct_FF_to( femdarr3_t* lhs, femdarr3_t* rhs, femdnum3_t* res);
  femdnum3_t femdarr3_dotproduct_OF(      mdarr3_t* lhs, femdarr3_t* rhs);
  void     femdarr3_dotproduct_OF_to(   mdarr3_t* lhs, femdarr3_t* rhs, femdnum3_t* res);
  femdnum3_t femdarr3_dotproduct_RF(       darr_t* lhs, femdarr3_t* rhs);
  void     femdarr3_dotproduct_RF_to(    darr_t* lhs, femdarr3_t* rhs, femdnum3_t* res);
  femdarr3_t femdarr3_matmul_FF(    femdarr3_t* lhs, femdarr3_t* rhs);
  void      femdarr3_matmul_FF_to( femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_matmul_OF(    mdarr3_t*   lhs, femdarr3_t* rhs);
  void      femdarr3_matmul_OF_to( mdarr3_t*   lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_matmul_FO(    femdarr3_t* lhs, mdarr3_t*   rhs);
  void      femdarr3_matmul_FO_to( femdarr3_t* lhs, mdarr3_t*   rhs, femdarr3_t* res);
  femdarr3_t femdarr3_matmul_RF(    darr_t*    lhs, femdarr3_t* rhs);
  void      femdarr3_matmul_RF_to( darr_t*    lhs, femdarr3_t* rhs, femdarr3_t* res);
  femdarr3_t femdarr3_matmul_FR(    femdarr3_t* lhs, darr_t*    rhs);
  void      femdarr3_matmul_FR_to( femdarr3_t* lhs, darr_t*    rhs, femdarr3_t* res);
  femdnum3_t femdarr3_det(   femdarr3_t* arr);
  void     femdarr3_det_to(femdarr3_t* arr, femdnum3_t* res);
  femdnum3_t femdarr3_norm(     femdarr3_t* arr);
  void     femdarr3_norm_to(  femdarr3_t* arr, femdnum3_t* res);
  femdnum3_t femdarr3_pnorm(    femdarr3_t* arr, coeff_t p);
  void     femdarr3_pnorm_to( femdarr3_t* arr, coeff_t p, femdnum3_t* res);
  femdarr3_t   femdarr3_invert(    femdarr3_t* arr);
  void        femdarr3_invert_to( femdarr3_t* arr, femdarr3_t* res);
  femdarr3_t   femdarr3_transpose(   femdarr3_t* arr);
  void        femdarr3_transpose_to(femdarr3_t* arr, femdarr3_t* res);
  
  