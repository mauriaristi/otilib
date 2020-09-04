cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/mdnum2/scalar/structures.h
  
  ctypedef struct  mdnum2_t : # {
    coeff_t r;
    coeff_t e1;
    coeff_t e2;
    coeff_t e12;
  # } mdnum2_t;
  
  
  # From ../../../include/oti/static/mdnum2/array/structures.h
  
  ctypedef struct  mdarr2_t : # {
      mdnum2_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } mdarr2_t;
  
  
  # From ../../../include/oti/static/mdnum2/scalar/gauss/structures.h
  
  ctypedef struct  femdnum2_t: # {
      mdnum2_t*  p_data;
      uint64_t    nip;
  # } femdnum2_t;
  
  
  # From ../../../include/oti/static/mdnum2/array/gauss/structures.h
  
  ctypedef struct  femdarr2_t: # {
      mdarr2_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } femdarr2_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/mdnum2/scalar/functions.h
  
  mdnum2_t mdnum2_atanh(mdnum2_t* num);
  void mdnum2_atanh_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_asinh(mdnum2_t* num);
  void mdnum2_asinh_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_acosh(mdnum2_t* num);
  void mdnum2_acosh_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_tanh(mdnum2_t* num);
  void mdnum2_tanh_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_sqrt(mdnum2_t* num);
  void mdnum2_sqrt_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_cbrt(mdnum2_t* num);
  void mdnum2_cbrt_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_cosh(mdnum2_t* num);
  void mdnum2_cosh_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_sinh(mdnum2_t* num);
  void mdnum2_sinh_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_asin(mdnum2_t* num);
  void mdnum2_asin_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_acos(mdnum2_t* num);
  void mdnum2_acos_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_atan(mdnum2_t* num);
  void mdnum2_atan_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_tan(mdnum2_t* num);
  void mdnum2_tan_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_cos(mdnum2_t* num);
  void mdnum2_cos_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_sin(mdnum2_t* num );
  void mdnum2_sin_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_logb(mdnum2_t* num, double base);
  void mdnum2_logb_to(mdnum2_t* num, double base, mdnum2_t* res);
  mdnum2_t mdnum2_log10(mdnum2_t* num);
  void mdnum2_log10_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_log(mdnum2_t* num);
  void mdnum2_log_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_exp(mdnum2_t* num);
  void mdnum2_exp_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_pow(mdnum2_t* num, double e);
  void mdnum2_pow_to(mdnum2_t* num, coeff_t e, mdnum2_t* res);
  
  
  # From ../../../include/oti/static/mdnum2/scalar/base.h
  
  void mdnum2_set_im_o(mdnum2_t* num, imdir_t idx, ord_t order, mdnum2_t* res);
  void mdnum2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum2_t* res);
  void mdnum2_set_deriv_o(mdnum2_t* num, imdir_t idx, ord_t order, mdnum2_t* res);
  void mdnum2_extract_im_to( imdir_t idx, ord_t order, mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_extract_im(imdir_t idx, ord_t order, mdnum2_t* num);
  mdnum2_t mdnum2_extract_deriv(imdir_t idx, ord_t order, mdnum2_t* num);
  void mdnum2_extract_deriv_to(imdir_t idx, ord_t order, mdnum2_t* num, mdnum2_t* res);
  void mdnum2_get_im_to_o(imdir_t idx, ord_t order, mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_get_im_o(imdir_t idx, ord_t order, mdnum2_t* num);
  void mdnum2_get_im_to_r(imdir_t idx, ord_t order, mdnum2_t* num, coeff_t* res);
  ord_t mdnum2_get_order(mdnum2_t* lhs);
  mdnum2_t mdnum2_get_deriv_o( imdir_t idx, ord_t order, mdnum2_t* num);
  void mdnum2_get_deriv_to( imdir_t idx, ord_t order, mdnum2_t* num, mdnum2_t* res);
  void mdnum2_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum2_t* res);
  mdnum2_t mdnum2_init();
  ndir_t mdnum2_get_ndir_order(ord_t order, mdnum2_t* num);
  ndir_t mdnum2_get_ndir_total(mdnum2_t* num);
  coeff_t* mdnum2_get_order_address(ord_t order, mdnum2_t* num);
  mdnum2_t mdnum2_create_r(  coeff_t lhs);
  void mdnum2_set_r(  coeff_t lhs, mdnum2_t* res);
  void mdnum2_set_o(  mdnum2_t* lhs, mdnum2_t* res);
  mdnum2_t mdnum2_get_order_im(ord_t order, mdnum2_t* lhs);
  void mdnum2_get_order_im_to(ord_t order, mdnum2_t* lhs, mdnum2_t* res);
  coeff_t mdnum2_get_item(imdir_t idx, ord_t order, mdnum2_t* lhs);
  coeff_t mdnum2_get_deriv(imdir_t idx, ord_t order, mdnum2_t* lhs);
  void mdnum2_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum2_t* x);
  mdnum2_t mdnum2_copy(  mdnum2_t* lhs);
  void mdnum2_copy_to(  mdnum2_t* lhs, mdnum2_t* res);
  mdnum2_t mdnum2_taylor_integrate(coeff_t* deltas,mdnum2_t* lhs);
  void mdnum2_taylor_integrate_to(coeff_t* deltas,mdnum2_t* lhs, mdnum2_t* res);
  mdnum2_t mdnum2_truncate_im(imdir_t idx, ord_t order, mdnum2_t* lhs);
  void mdnum2_truncate_im_to(imdir_t idx, ord_t order, mdnum2_t* lhs, mdnum2_t* res);
  void mdnum2_print(  mdnum2_t* lhs);
  imdir_t mdnum2_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/mdnum2/scalar/utils.h
  
  void mdnum2_get_active_bases(mdnum2_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/mdnum2/scalar/algebra.h
  
  mdnum2_t mdnum2_abs(mdnum2_t* num);
  mdnum2_t mdnum2_div_ro(coeff_t num, mdnum2_t* den);
  mdnum2_t mdnum2_div_oo(mdnum2_t* num, mdnum2_t* den);
  mdnum2_t mdnum2_div_or(mdnum2_t* num, coeff_t val);
  void mdnum2_div_ro_to(coeff_t num, mdnum2_t* den, mdnum2_t* res);
  void mdnum2_div_oo_to(mdnum2_t* num, mdnum2_t* den, mdnum2_t* res);
  void mdnum2_div_or_to(mdnum2_t* num, coeff_t val, mdnum2_t* res);
  void mdnum2_abs_to(mdnum2_t* num, mdnum2_t* res);
  mdnum2_t mdnum2_neg(  mdnum2_t* lhs);
  void mdnum2_neg_to(  mdnum2_t* lhs, mdnum2_t* res);
  mdnum2_t mdnum2_sum_oo(  mdnum2_t* lhs,  mdnum2_t* rhs);
  void mdnum2_sum_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res);
  mdnum2_t mdnum2_sum_ro(  coeff_t lhs,  mdnum2_t* rhs);
  void mdnum2_sum_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res);
  mdnum2_t mdnum2_sub_oo(  mdnum2_t* lhs,  mdnum2_t* rhs);
  void mdnum2_sub_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res);
  mdnum2_t mdnum2_sub_ro(  coeff_t lhs,  mdnum2_t* rhs);
  void mdnum2_sub_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res);
  mdnum2_t mdnum2_sub_or(  mdnum2_t* lhs,  coeff_t rhs);
  void mdnum2_sub_or_to(  mdnum2_t* lhs,  coeff_t rhs, mdnum2_t* res);
  mdnum2_t mdnum2_mul_oo(  mdnum2_t* lhs,  mdnum2_t* rhs);
  void mdnum2_mul_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res);
  mdnum2_t mdnum2_mul_ro(  coeff_t lhs,  mdnum2_t* rhs);
  void mdnum2_mul_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res);
  mdnum2_t mdnum2_trunc_mul_oo(  mdnum2_t* lhs,  mdnum2_t* rhs);
  void mdnum2_trunc_mul_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res);
  mdnum2_t mdnum2_gem_oo(  mdnum2_t* a,  mdnum2_t* b,  mdnum2_t* c);
  void mdnum2_gem_oo_to(  mdnum2_t* a,  mdnum2_t* b,  mdnum2_t* c, mdnum2_t* res);
  mdnum2_t mdnum2_gem_ro(  coeff_t a,  mdnum2_t* b,  mdnum2_t* c);
  void mdnum2_gem_ro_to(  coeff_t a,  mdnum2_t* b,  mdnum2_t* c, mdnum2_t* res);
  void mdnum2_trunc_gem_oo_to( ord_t ord_lhs,  mdnum2_t* a,  ord_t ord_rhs,  mdnum2_t* b,  mdnum2_t* c, mdnum2_t* res);
  mdnum2_t mdnum2_feval(coeff_t* feval_re, mdnum2_t* x);
  void mdnum2_feval_to(coeff_t* feval_re, mdnum2_t* x, mdnum2_t* res);
  
  
  # From ../../../include/oti/static/mdnum2/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum2/scalar/gauss/functions.h
  
  femdnum2_t femdnum2_atanh(    femdnum2_t* num);
  void     femdnum2_atanh_to( femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_asinh(    femdnum2_t* num);
  void     femdnum2_asinh_to( femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_acosh(    femdnum2_t* num);
  void     femdnum2_acosh_to( femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_tanh(     femdnum2_t* num);
  void     femdnum2_tanh_to(  femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_cosh(     femdnum2_t* num);
  void     femdnum2_cosh_to(  femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_sinh(     femdnum2_t* num);
  void     femdnum2_sinh_to(  femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_asin(     femdnum2_t* num);
  void     femdnum2_asin_to(  femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_acos(     femdnum2_t* num);
  void     femdnum2_acos_to(  femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_atan(     femdnum2_t* num);
  void     femdnum2_atan_to(  femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_tan(      femdnum2_t* num);
  void     femdnum2_tan_to(   femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_cos(      femdnum2_t* num);
  void     femdnum2_cos_to(   femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_sin(      femdnum2_t* num);
  void     femdnum2_sin_to(   femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_logb(     femdnum2_t* num, double base);
  void     femdnum2_logb_to(  femdnum2_t* num, double base, femdnum2_t* res);
  femdnum2_t femdnum2_log10(    femdnum2_t* num);
  void     femdnum2_log10_to( femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_log(      femdnum2_t* num);
  void     femdnum2_log_to(   femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_exp(      femdnum2_t* num);
  void     femdnum2_exp_to(   femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_cbrt(     femdnum2_t* num);
  void     femdnum2_cbrt_to(  femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_sqrt(     femdnum2_t* num);
  void     femdnum2_sqrt_to(  femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_pow(      femdnum2_t* num, double e);
  void     femdnum2_pow_to(   femdnum2_t* num, double e, femdnum2_t* res);
  mdnum2_t femdnum2_integrate(       femdnum2_t* num, femdnum2_t* w);
  void      femdnum2_integrate_to(    femdnum2_t* num, femdnum2_t* w, mdnum2_t* res);
  mdnum2_t femdnum2_integrate_f(     femdnum2_t* num, femdnum2_t* w);
  void      femdnum2_integrate_f_to(  femdnum2_t* num, femdnum2_t* w, mdnum2_t* res);
  mdnum2_t femdnum2_integrate_r(       coeff_t num, femdnum2_t* w);
  void      femdnum2_integrate_r_to(    coeff_t num, femdnum2_t* w, mdnum2_t* res);
  mdnum2_t femdnum2_integrate_o(    mdnum2_t* num, femdnum2_t* w);
  void      femdnum2_integrate_o_to( mdnum2_t* num, femdnum2_t* w, mdnum2_t* res);
  
  
  # From ../../../include/oti/static/mdnum2/scalar/gauss/base.h
  
  void     femdnum2_get_order_im_to( ord_t order, femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_get_order_im(    ord_t order, femdnum2_t* num);
  femdnum2_t femdnum2_get_im(    imdir_t idx, ord_t order, femdnum2_t* num);
  void     femdnum2_get_im_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_get_deriv(    imdir_t idx, ord_t order, femdnum2_t* num);
  void     femdnum2_get_deriv_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res);
  void femdnum2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum2_t* num);
  void femdnum2_set_im_o( mdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num);
  void femdnum2_set_im_f(  femdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num);
  void femdnum2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum2_t* num);
  void femdnum2_set_deriv_o( mdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num);
  void femdnum2_set_deriv_f(  femdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num);
  femdnum2_t femdnum2_extract_im(    imdir_t idx, ord_t order, femdnum2_t* num);
  void     femdnum2_extract_im_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_extract_deriv(    imdir_t idx, ord_t order, femdnum2_t* num);
  void     femdnum2_extract_deriv_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_truncate_im(    imdir_t idx, ord_t order, femdnum2_t* num);
  void     femdnum2_truncate_im_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_copy(    femdnum2_t* src);
  void     femdnum2_copy_to( femdnum2_t* src, femdnum2_t* dst);
  void femdnum2_set_r(    coeff_t num, femdnum2_t* res);
  void femdnum2_set_o( mdnum2_t* num, femdnum2_t* res);
  void femdnum2_set_f(  femdnum2_t* num, femdnum2_t* res);
  void femdnum2_set_item_k_r(   coeff_t  num, uint64_t k, femdnum2_t* res);
  void femdnum2_set_item_k_o( mdnum2_t* num, uint64_t k, femdnum2_t* res);
  mdnum2_t femdnum2_get_item_k(   femdnum2_t* num, uint64_t k);
  void      femdnum2_get_item_k_to(femdnum2_t* num, uint64_t k, mdnum2_t* res);
  femdnum2_t femdnum2_zeros(uint64_t nIntPts);
  femdnum2_t femdnum2_createEmpty(uint64_t nIntPts);
  femdnum2_t femdnum2_empty_like(femdnum2_t* arr);
  void femdnum2_free(femdnum2_t* num);
  ord_t femdnum2_get_order( femdnum2_t* num );
  femdnum2_t femdnum2_init();
  
  
  # From ../../../include/oti/static/mdnum2/scalar/gauss/utils.h
  
  void femdnum2_dimCheck(femdnum2_t* arr1,femdnum2_t* arr2);
  void femdnum2_get_active_bases(femdnum2_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum2/scalar/gauss/algebra.h
  
  femdnum2_t femdnum2_neg(   femdnum2_t* num);
  void     femdnum2_neg_to(femdnum2_t* num, femdnum2_t* res);
  femdnum2_t femdnum2_sum_ff(   femdnum2_t* lhs, femdnum2_t* rhs);
  void     femdnum2_sum_ff_to(femdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_sum_of(   mdnum2_t* lhs, femdnum2_t* rhs);
  void     femdnum2_sum_of_to(mdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_sum_rf(   coeff_t lhs, femdnum2_t* rhs);
  void     femdnum2_sum_rf_to(coeff_t lhs, femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_sub_ff(     femdnum2_t* lhs,  femdnum2_t* rhs);
  void     femdnum2_sub_ff_to(  femdnum2_t* lhs,  femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_sub_of(    mdnum2_t* lhs,  femdnum2_t* rhs);
  void     femdnum2_sub_of_to( mdnum2_t* lhs,  femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_sub_fo(     femdnum2_t* lhs, mdnum2_t* rhs);
  void     femdnum2_sub_fo_to(  femdnum2_t* lhs, mdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_sub_rf(       coeff_t lhs,  femdnum2_t* rhs);
  void     femdnum2_sub_rf_to(    coeff_t lhs,  femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_sub_fr(     femdnum2_t* lhs,    coeff_t rhs);
  void     femdnum2_sub_fr_to(  femdnum2_t* lhs,    coeff_t rhs, femdnum2_t* res);
  femdnum2_t femdnum2_mul_ff(   femdnum2_t* lhs, femdnum2_t* rhs);
  void     femdnum2_mul_ff_to(femdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_mul_of(   mdnum2_t* lhs, femdnum2_t* rhs);
  void     femdnum2_mul_of_to(mdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_mul_rf(   coeff_t lhs, femdnum2_t* rhs);
  void     femdnum2_mul_rf_to(coeff_t lhs, femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_div_ff(     femdnum2_t* lhs,  femdnum2_t* rhs);
  void     femdnum2_div_ff_to(  femdnum2_t* lhs,  femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_div_of(    mdnum2_t* lhs,  femdnum2_t* rhs);
  void     femdnum2_div_of_to( mdnum2_t* lhs,  femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_div_fo(     femdnum2_t* lhs, mdnum2_t* rhs);
  void     femdnum2_div_fo_to(  femdnum2_t* lhs, mdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_div_rf(       coeff_t lhs,  femdnum2_t* rhs);
  void     femdnum2_div_rf_to(    coeff_t lhs,  femdnum2_t* rhs, femdnum2_t* res);
  femdnum2_t femdnum2_div_fr(     femdnum2_t* lhs,    coeff_t rhs);
  void     femdnum2_div_fr_to(  femdnum2_t* lhs,    coeff_t rhs, femdnum2_t* res);
  
  
  # From ../../../include/oti/static/mdnum2/array/functions.h
  
  mdarr2_t mdarr2_atanh(   mdarr2_t* arr);
  void    mdarr2_atanh_to(mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_asinh(   mdarr2_t* arr);
  void    mdarr2_asinh_to(mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_acosh(   mdarr2_t* arr);
  void    mdarr2_acosh_to(mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_tanh(    mdarr2_t* arr);
  void    mdarr2_tanh_to( mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_cbrt(    mdarr2_t* arr);
  void    mdarr2_cbrt_to( mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_sqrt(    mdarr2_t* arr);
  void    mdarr2_sqrt_to( mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_cosh(    mdarr2_t* arr);
  void    mdarr2_cosh_to( mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_sinh(    mdarr2_t* arr);
  void    mdarr2_sinh_to( mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_asin(    mdarr2_t* arr);
  void    mdarr2_asin_to( mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_acos(    mdarr2_t* arr);
  void    mdarr2_acos_to( mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_atan(    mdarr2_t* arr);
  void    mdarr2_atan_to( mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_tan(     mdarr2_t* arr);
  void    mdarr2_tan_to(  mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_cos(     mdarr2_t* arr);
  void    mdarr2_cos_to(  mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_sin(     mdarr2_t* arr);
  void    mdarr2_sin_to(  mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_logb(    mdarr2_t* arr, double base);
  void    mdarr2_logb_to( mdarr2_t* arr, double base, mdarr2_t* res);
  mdarr2_t mdarr2_log10(   mdarr2_t* arr);
  void    mdarr2_log10_to(mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_log(     mdarr2_t* arr);
  void    mdarr2_log_to(  mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_exp(     mdarr2_t* arr);
  void    mdarr2_exp_to(  mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_pow(     mdarr2_t* arr, double e);
  void    mdarr2_pow_to(  mdarr2_t* arr, double e, mdarr2_t* res);
  
  
  # From ../../../include/oti/static/mdnum2/array/algebra_elementwise.h
  
  mdarr2_t mdarr2_neg(mdarr2_t* arr);
  void mdarr2_neg_to(mdarr2_t* rhs, mdarr2_t* res);
  mdarr2_t mdarr2_sum_OO(mdarr2_t*   lhs, mdarr2_t* rhs);
  mdarr2_t mdarr2_sum_RO(darr_t*    lhs, mdarr2_t* rhs);
  mdarr2_t mdarr2_sum_oO(mdnum2_t* lhs, mdarr2_t* rhs);
  mdarr2_t mdarr2_sum_rO(coeff_t    lhs, mdarr2_t* rhs);
  void mdarr2_sum_OO_to(mdarr2_t*   lhs, mdarr2_t* rhs, mdarr2_t* res);
  void mdarr2_sum_RO_to(darr_t*    lhs, mdarr2_t* rhs, mdarr2_t* res);
  void mdarr2_sum_oO_to(mdnum2_t* lhs, mdarr2_t* rhs, mdarr2_t* res);
  void mdarr2_sum_rO_to(coeff_t    lhs, mdarr2_t* rhs, mdarr2_t* res);
  mdarr2_t mdarr2_sub_OO(mdarr2_t*   lhs, mdarr2_t*   rhs);
  mdarr2_t mdarr2_sub_RO(darr_t*    lhs, mdarr2_t*   rhs);
  mdarr2_t mdarr2_sub_OR(mdarr2_t*   lhs, darr_t*    rhs);
  mdarr2_t mdarr2_sub_oO(mdnum2_t* lhs, mdarr2_t*   rhs);
  mdarr2_t mdarr2_sub_Oo(mdarr2_t*   lhs, mdnum2_t* rhs);
  mdarr2_t mdarr2_sub_rO(coeff_t    lhs, mdarr2_t*   rhs);
  mdarr2_t mdarr2_sub_Or(mdarr2_t*   lhs, coeff_t    rhs);
  void mdarr2_sub_OO_to( mdarr2_t*   lhs, mdarr2_t*   rhs, mdarr2_t* res);
  void mdarr2_sub_RO_to( darr_t*    lhs, mdarr2_t*   rhs, mdarr2_t* res);
  void mdarr2_sub_OR_to( mdarr2_t*   lhs, darr_t*    rhs, mdarr2_t* res);
  void mdarr2_sub_oO_to( mdnum2_t* lhs, mdarr2_t*   rhs, mdarr2_t* res);
  void mdarr2_sub_Oo_to( mdarr2_t*   lhs, mdnum2_t* rhs, mdarr2_t* res);
  void mdarr2_sub_rO_to( coeff_t    lhs, mdarr2_t*   rhs, mdarr2_t* res);
  void mdarr2_sub_Or_to( mdarr2_t*   lhs, coeff_t    rhs, mdarr2_t* res);
  mdarr2_t mdarr2_mul_OO(mdarr2_t*   lhs, mdarr2_t* rhs);
  mdarr2_t mdarr2_mul_RO(darr_t*    lhs, mdarr2_t* rhs);
  mdarr2_t mdarr2_mul_oO(mdnum2_t* lhs, mdarr2_t* rhs);
  mdarr2_t mdarr2_mul_rO(coeff_t    lhs, mdarr2_t* rhs);
  void mdarr2_mul_OO_to(mdarr2_t*   lhs, mdarr2_t* rhs, mdarr2_t* res);
  void mdarr2_mul_RO_to(darr_t*    lhs, mdarr2_t* rhs, mdarr2_t* res);
  void mdarr2_mul_oO_to(mdnum2_t* lhs, mdarr2_t* rhs, mdarr2_t* res);
  void mdarr2_mul_rO_to(coeff_t    lhs, mdarr2_t* rhs, mdarr2_t* res);
  void mdarr2_gem_OO_to(  mdarr2_t* arr1, mdarr2_t* arr2, mdarr2_t* arr3, mdarr2_t* res);
  void mdarr2_gem_oO_to(mdnum2_t* arr1, mdarr2_t* arr2, mdarr2_t* arr3, mdarr2_t* res);
  mdarr2_t mdarr2_div_OO(mdarr2_t*   lhs, mdarr2_t*   rhs);
  mdarr2_t mdarr2_div_OR(mdarr2_t*   lhs, darr_t*    rhs);
  mdarr2_t mdarr2_div_RO(darr_t*    lhs, mdarr2_t*   rhs);
  mdarr2_t mdarr2_div_oO(mdnum2_t* lhs, mdarr2_t*   rhs);
  mdarr2_t mdarr2_div_Oo(mdarr2_t*   lhs, mdnum2_t* rhs);
  mdarr2_t mdarr2_div_rO(coeff_t    lhs, mdarr2_t*   rhs);
  mdarr2_t mdarr2_div_Or(mdarr2_t*   lhs, coeff_t    rhs);
  void mdarr2_div_OO_to(mdarr2_t*   lhs, mdarr2_t*   rhs, mdarr2_t* res);
  void mdarr2_div_RO_to(darr_t*    lhs, mdarr2_t*   rhs, mdarr2_t* res);
  void mdarr2_div_OR_to(mdarr2_t*   lhs, darr_t*    rhs, mdarr2_t* res);
  void mdarr2_div_oO_to(mdnum2_t* lhs, mdarr2_t*   rhs, mdarr2_t* res);
  void mdarr2_div_Oo_to(mdarr2_t*   lhs, mdnum2_t* rhs, mdarr2_t* res);
  void mdarr2_div_rO_to(coeff_t    lhs, mdarr2_t*   rhs, mdarr2_t* res);
  void mdarr2_div_Or_to(mdarr2_t*   lhs, coeff_t    rhs, mdarr2_t* res);
  
  
  # From ../../../include/oti/static/mdnum2/array/base.h
  
  void    mdarr2_taylor_integrate_to( coeff_t* deltas, mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_taylor_integrate(    coeff_t* deltas, mdarr2_t* arr);
  void    mdarr2_get_order_im_to( ord_t order, mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_get_order_im(    ord_t order, mdarr2_t* arr);
  void mdarr2_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr2_t* res);
  void mdarr2_set_slice_O( mdarr2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr2_t* res);
  void mdarr2_set_slice_o( mdnum2_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr2_t* res);
  mdarr2_t mdarr2_get_slice( mdarr2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void mdarr2_get_slice_to( mdarr2_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr2_t* res);
  mdarr2_t mdarr2_truncate_im(    imdir_t idx, ord_t order, mdarr2_t* arr);
  void    mdarr2_truncate_im_to( imdir_t idx, ord_t order, mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_extract_im(   imdir_t idx, ord_t order, mdarr2_t* arr);
  void    mdarr2_extract_im_to(imdir_t idx, ord_t order, mdarr2_t* arr, mdarr2_t* res);
  darr_t  mdarr2_get_deriv(    imdir_t idx, ord_t order, mdarr2_t* arr);
  void    mdarr2_get_deriv_to( imdir_t idx, ord_t order, mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_get_deriv_o(  imdir_t idx, ord_t order, mdarr2_t* arr);
  mdarr2_t mdarr2_extract_deriv(    imdir_t idx, ord_t order, mdarr2_t* arr);
  void    mdarr2_extract_deriv_to( imdir_t idx, ord_t order, mdarr2_t* arr, mdarr2_t* res);
  darr_t  mdarr2_get_im(   imdir_t idx, ord_t order, mdarr2_t* arr);
  mdarr2_t mdarr2_get_im_o( imdir_t idx, ord_t order, mdarr2_t* arr);
  void    mdarr2_get_im_to(imdir_t idx, ord_t order, mdarr2_t* arr, mdarr2_t* res);
  void    mdarr2_copy_to(mdarr2_t* arr, mdarr2_t* res);
  mdarr2_t mdarr2_copy(mdarr2_t* arr);
  void mdarr2_set_all_r( coeff_t num, mdarr2_t* arr);
  void mdarr2_set_item_i_r( coeff_t num, uint64_t i, mdarr2_t* arr);
  void mdarr2_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, mdarr2_t* arr);
  void mdarr2_set_r(   coeff_t  num,   mdarr2_t* arr);
  void mdarr2_set_o( mdnum2_t* num,   mdarr2_t* arr);
  void mdarr2_set_O(   mdarr2_t* arrin, mdarr2_t* arr);
  void mdarr2_set_all_o( mdnum2_t* src, mdarr2_t* arr);
  void mdarr2_set_item_i_o( mdnum2_t* num, uint64_t i, mdarr2_t* arr);
  void mdarr2_set_item_ij_o( mdnum2_t* num, uint64_t i, uint64_t j, mdarr2_t* arr);
  mdnum2_t mdarr2_get_item_i(    mdarr2_t* arr, uint64_t i);
  void      mdarr2_get_item_i_to( mdarr2_t* arr, uint64_t i,             mdnum2_t* res);
  mdnum2_t mdarr2_get_item_ij(   mdarr2_t* arr, uint64_t i, uint64_t j);
  void      mdarr2_get_item_ij_to(mdarr2_t* arr, uint64_t i, uint64_t j, mdnum2_t* res);
  mdarr2_t mdarr2_init();
  void mdarr2_free(mdarr2_t* arr);
  mdarr2_t mdarr2_empty_like(mdarr2_t* arr);
  mdarr2_t mdarr2_eye(uint64_t nrows);
  mdarr2_t mdarr2_ones(uint64_t nrows, uint64_t ncols);
  mdarr2_t mdarr2_zeros(uint64_t nrows, uint64_t ncols);
  mdarr2_t mdarr2_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/mdnum2/array/utils.h
  
  void mdarr2_dimCheck_OO_elementwise(mdarr2_t* arr1, mdarr2_t* arr2, mdarr2_t* res);
  void mdarr2_dimCheck_RO_elementwise(darr_t*  arr1, mdarr2_t* arr2, mdarr2_t* res);
  void mdarr2_dimCheck_OO_matmul(mdarr2_t* arr1, mdarr2_t* arr2, mdarr2_t* res);
  void mdarr2_dimCheck_RO_matmul(darr_t*  arr1, mdarr2_t* arr2, mdarr2_t* res);
  void mdarr2_dimCheck_OR_matmul(mdarr2_t* arr1, darr_t*  arr2, mdarr2_t* res);
  void mdarr2_dimCheck_O_squareness(mdarr2_t* arr1, mdarr2_t* res);
  void mdarr2_dimCheck_OO_samesize(mdarr2_t* arr1, mdarr2_t* res);
  void mdarr2_dimCheck_RO_samesize(darr_t* arr1, mdarr2_t* res);
  ord_t mdarr2_get_order(mdarr2_t* arr);
  void mdarr2_get_active_bases(mdarr2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum2/array/algebra_matops.h
  
  mdnum2_t mdarr2_dotproduct_OO(    mdarr2_t* lhs, mdarr2_t* rhs);
  void      mdarr2_dotproduct_OO_to( mdarr2_t* lhs, mdarr2_t* rhs, mdnum2_t* res);
  mdnum2_t mdarr2_dotproduct_RO(     darr_t* lhs, mdarr2_t* rhs);
  void      mdarr2_dotproduct_RO_to(  darr_t* lhs, mdarr2_t* rhs, mdnum2_t* res);
  mdarr2_t mdarr2_matmul_OO(    mdarr2_t* lhs, mdarr2_t* rhs);
  mdarr2_t mdarr2_matmul_OR(    mdarr2_t* lhs,  darr_t* rhs);
  mdarr2_t mdarr2_matmul_RO(     darr_t* lhs, mdarr2_t* rhs);
  void    mdarr2_matmul_OO_to( mdarr2_t* lhs, mdarr2_t* rhs, mdarr2_t* res);
  void    mdarr2_matmul_OR_to( mdarr2_t* lhs,  darr_t* rhs, mdarr2_t* res);
  void    mdarr2_matmul_RO_to(  darr_t* lhs, mdarr2_t* rhs, mdarr2_t* res);
  mdarr2_t mdarr2_transpose(    mdarr2_t* arr1);
  void    mdarr2_transpose_to( mdarr2_t* arr1, mdarr2_t* res);
  mdarr2_t mdarr2_invert(    mdarr2_t* arr1);
  void    mdarr2_invert_to( mdarr2_t* arr1, mdarr2_t* res);
  mdnum2_t mdarr2_det(    mdarr2_t* arr1);
  void      mdarr2_det_to( mdarr2_t* arr1, mdnum2_t* res);
  mdnum2_t mdarr2_norm(    mdarr2_t* arr1);
  void      mdarr2_norm_to( mdarr2_t* arr1,  mdnum2_t* res);
  mdnum2_t mdarr2_pnorm(    mdarr2_t* arr1, coeff_t p);
  void      mdarr2_pnorm_to( mdarr2_t* arr1, coeff_t p, mdnum2_t* res);
  
  
  # From ../../../include/oti/static/mdnum2/array/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum2/array/gauss/functions.h
  
  femdarr2_t femdarr2_atanh(    femdarr2_t* arr);
  void      femdarr2_atanh_to( femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_asinh(    femdarr2_t* arr);
  void      femdarr2_asinh_to( femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_acosh(    femdarr2_t* arr);
  void      femdarr2_acosh_to( femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_tanh(     femdarr2_t* arr);
  void      femdarr2_tanh_to(  femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_sinh(     femdarr2_t* arr);
  void      femdarr2_sinh_to(  femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_cosh(     femdarr2_t* arr);
  void      femdarr2_cosh_to(  femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_atan(     femdarr2_t* arr);
  void      femdarr2_atan_to(  femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_asin(     femdarr2_t* arr);
  void      femdarr2_asin_to(  femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_acos(     femdarr2_t* arr);
  void      femdarr2_acos_to(  femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_tan(      femdarr2_t* arr);
  void      femdarr2_tan_to(   femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_sin(      femdarr2_t* arr);
  void      femdarr2_sin_to(   femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_cos(      femdarr2_t* arr);
  void      femdarr2_cos_to(   femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_logb(     femdarr2_t* arr, double base);
  void      femdarr2_logb_to(  femdarr2_t* arr, double base, femdarr2_t* res);
  femdarr2_t femdarr2_log10(    femdarr2_t* arr);
  void      femdarr2_log10_to( femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_log(      femdarr2_t* arr);
  void      femdarr2_log_to(   femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_exp(      femdarr2_t* arr);
  void      femdarr2_exp_to(   femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_cbrt(     femdarr2_t* arr);
  void      femdarr2_cbrt_to(  femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_sqrt(     femdarr2_t* arr);
  void      femdarr2_sqrt_to(  femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_pow(      femdarr2_t* arr, double e);
  void      femdarr2_pow_to(   femdarr2_t* arr, double e, femdarr2_t* res);
  
  
  # From ../../../include/oti/static/mdnum2/array/gauss/base.h
  
  void      femdarr2_get_order_im_to( ord_t order, femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_get_order_im(    ord_t order, femdarr2_t* arr);
  femdarr2_t femdarr2_get_deriv(   imdir_t idx, ord_t order, femdarr2_t* arr);
  void      femdarr2_get_deriv_to(imdir_t idx, ord_t order, femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_get_im(      imdir_t idx, ord_t order, femdarr2_t* arr);
  void      femdarr2_get_im_to(   imdir_t idx, ord_t order, femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_truncate_im(   imdir_t idx, ord_t order, femdarr2_t* arr);
  void      femdarr2_truncate_im_to(imdir_t idx, ord_t order, femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_copy(   femdarr2_t* src);
  void      femdarr2_copy_to(femdarr2_t* src, femdarr2_t* res);
  femdarr2_t femdarr2_get_im(    imdir_t idx, ord_t order, femdarr2_t* arr);
  void      femdarr2_get_im_to( imdir_t idx, ord_t order, femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_get_deriv(    imdir_t idx, ord_t order, femdarr2_t* arr);
  void      femdarr2_get_deriv_to( imdir_t idx, ord_t order, femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_extract_im(    imdir_t idx, ord_t order, femdarr2_t* arr);
  void      femdarr2_extract_im_to( imdir_t idx, ord_t order, femdarr2_t* arr,  femdarr2_t* res);
  femdarr2_t femdarr2_extract_deriv(    imdir_t idx, ord_t order, femdarr2_t* arr);
  void      femdarr2_extract_deriv_to( imdir_t idx, ord_t order, femdarr2_t* arr, femdarr2_t* res);
  mdarr2_t   femdarr2_get_item_k(  femdarr2_t* arr, uint64_t k);
  femdnum2_t  femdarr2_get_item_ij( femdarr2_t* arr, uint64_t i, uint64_t j);
  mdnum2_t femdarr2_get_item_ijk(femdarr2_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void femdarr2_get_item_ij_to(  femdarr2_t* arr, uint64_t i, uint64_t j,
                                 femdnum2_t* res);
  void femdarr2_get_item_k_to(   femdarr2_t* arr, uint64_t k,
                                  mdarr2_t* res);
  void femdarr2_get_item_ijk_to( femdarr2_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                mdnum2_t* res);
  femdarr2_t femdarr2_get_slice(femdarr2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      femdarr2_get_slice_to(femdarr2_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr2_t* res);
  void femdarr2_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              femdarr2_t* res);
  void femdarr2_set_item_ij_o(  mdnum2_t* elm, uint64_t i, uint64_t j,
                               femdarr2_t* res);
  void femdarr2_set_item_ij_f(  femdnum2_t* elm, uint64_t i, uint64_t j,
                              femdarr2_t* res);
  void femdarr2_set_item_k_r(    coeff_t  elm, uint64_t k,
                              femdarr2_t* res);
  void femdarr2_set_item_k_o(  mdnum2_t* elm, uint64_t k,
                              femdarr2_t* res);
  void femdarr2_set_item_k_R(    mdarr2_t* elm, uint64_t k,
                            femdarr2_t* res);
  void femdarr2_set_item_k_O(    mdarr2_t* elm, uint64_t k,
                            femdarr2_t* res);
  void femdarr2_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr2_t* res);
  void femdarr2_set_item_ijk_o( mdnum2_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr2_t* res);
  void femdarr2_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr2_t* res);
  void femdarr2_set_slice_o( mdnum2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr2_t* res);
  void femdarr2_set_slice_f( femdnum2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr2_t* res);
  void femdarr2_set_slice_O( mdarr2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr2_t* res);
  void femdarr2_set_slice_F( femdarr2_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr2_t* res);
  void femdarr2_set_all_o( mdnum2_t* num, femdarr2_t* arr );
  void femdarr2_set_all_r(   coeff_t  num, femdarr2_t* arr );
  void femdarr2_set_all_f(  femdnum2_t* num, femdarr2_t* arr );
  void femdarr2_set_r(    coeff_t src, femdarr2_t* res );
  void femdarr2_set_o( mdnum2_t* src, femdarr2_t* res );
  void femdarr2_set_f(  femdnum2_t* src, femdarr2_t* res );
  void femdarr2_set_R(    darr_t* src, femdarr2_t* res );
  void femdarr2_set_O(   mdarr2_t* src, femdarr2_t* res );
  void femdarr2_set_F( femdarr2_t* src, femdarr2_t* res );
  femdarr2_t femdarr2_eye( uint64_t size,  uint64_t nip);
  femdarr2_t femdarr2_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  femdarr2_t femdarr2_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  femdarr2_t femdarr2_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void femdarr2_free(femdarr2_t* arr);
  femdarr2_t femdarr2_init();
  ord_t femdarr2_get_order(femdarr2_t* arr);
  
  
  # From ../../../include/oti/static/mdnum2/array/gauss/utils.h
  
  void femdarr2_dimCheck_FF_samesize(femdarr2_t* arr1, femdarr2_t* arr2, femdnum2_t* res);
  void femdarr2_dimCheck_OF_samesize(  mdarr2_t* arr1, femdarr2_t* arr2, femdnum2_t* res);
  void femdarr2_dimCheck_RF_samesize(   darr_t* arr1, femdarr2_t* arr2, femdnum2_t* res);
  void femdarr2_dimCheck_FF_elementwise(femdarr2_t* arr1, femdarr2_t* arr2, femdarr2_t* res);
  void femdarr2_dimCheck_OF_elementwise(  mdarr2_t* arr1, femdarr2_t* arr2, femdarr2_t* res);
  void femdarr2_dimCheck_RF_elementwise(   darr_t* arr1, femdarr2_t* arr2, femdarr2_t* res);
  void femdarr2_dimCheck_fF_elementwise( femdnum2_t* num1, femdarr2_t* arr2, femdarr2_t* res);
  void femdarr2_dimCheck_Ff_elementwise(femdarr2_t* arr1,  femdnum2_t* num2, femdarr2_t* res);
  void femdarr2_dimCheck_FF_matmul( femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  void femdarr2_dimCheck_OF_matmul(   mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  void femdarr2_dimCheck_RF_matmul(    darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  void femdarr2_dimCheck_FO_matmul( femdarr2_t* lhs,   mdarr2_t* rhs, femdarr2_t* res);
  void femdarr2_dimCheck_FR_matmul( femdarr2_t* lhs,    darr_t* rhs, femdarr2_t* res);
  void femdarr2_dimCheck_F_squareness( femdarr2_t* arr1, femdarr2_t* res);
  void femdarr2_dimCheck_F_transpose( femdarr2_t* arr1, femdarr2_t* res);
  void femdarr2_dimCheck_FfO_integrate(femdarr2_t* arr, femdnum2_t* num,mdarr2_t* res);
  void femdarr2_get_active_bases(femdarr2_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum2/array/gauss/algebra.h
  
  femdarr2_t femdarr2_neg(    femdarr2_t* arr);
  void      femdarr2_neg_to( femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t femdarr2_sum_FF(   femdarr2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_sum_FF_to(femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sum_fF(    femdnum2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_sum_fF_to( femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sum_OF(     mdarr2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_sum_OF_to(  mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sum_RF(      darr_t* lhs, femdarr2_t* rhs);
  void      femdarr2_sum_RF_to(   darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sum_oF(   mdnum2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_sum_oF_to(mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sum_rF(     coeff_t  lhs, femdarr2_t* rhs);
  void      femdarr2_sum_rF_to(  coeff_t  lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sub_FF(    femdarr2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_sub_FF_to( femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sub_fF(    femdnum2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_sub_fF_to( femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sub_Ff(    femdarr2_t* lhs, femdnum2_t* rhs);
  void      femdarr2_sub_Ff_to( femdarr2_t* lhs, femdnum2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sub_OF(      mdarr2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_sub_OF_to(   mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sub_FO(    femdarr2_t* lhs,   mdarr2_t* rhs);
  void      femdarr2_sub_FO_to( femdarr2_t* lhs,   mdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sub_RF(       darr_t* lhs, femdarr2_t* rhs);
  void      femdarr2_sub_RF_to(    darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sub_FR(    femdarr2_t* lhs,    darr_t* rhs);
  void      femdarr2_sub_FR_to( femdarr2_t* lhs,    darr_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sub_oF(    mdnum2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_sub_oF_to( mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sub_Fo(    femdarr2_t* lhs, mdnum2_t* rhs);
  void      femdarr2_sub_Fo_to( femdarr2_t* lhs, mdnum2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sub_rF(      coeff_t  lhs, femdarr2_t* rhs);
  void      femdarr2_sub_rF_to(    coeff_t lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_sub_Fr(    femdarr2_t* lhs,   coeff_t  rhs);
  void      femdarr2_sub_Fr_to( femdarr2_t* lhs,   coeff_t  rhs, femdarr2_t* res);
  femdarr2_t femdarr2_mul_FF(   femdarr2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_mul_FF_to(femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_mul_fF(    femdnum2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_mul_fF_to( femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_mul_OF(     mdarr2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_mul_OF_to(  mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_mul_RF(      darr_t* lhs, femdarr2_t* rhs);
  void      femdarr2_mul_RF_to(   darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_mul_oF(   mdnum2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_mul_oF_to(mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_mul_rF(     coeff_t  lhs, femdarr2_t* rhs);
  void      femdarr2_mul_rF_to(  coeff_t  lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_div_FF(    femdarr2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_div_FF_to( femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_div_fF(     femdnum2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_div_fF_to(  femdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_div_Ff(    femdarr2_t* lhs,  femdnum2_t* rhs);
  void      femdarr2_div_Ff_to( femdarr2_t* lhs,  femdnum2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_div_OF(      mdarr2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_div_OF_to(   mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_div_FO(    femdarr2_t* lhs,   mdarr2_t* rhs);
  void      femdarr2_div_FO_to( femdarr2_t* lhs,   mdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_div_RF(       darr_t* lhs, femdarr2_t* rhs);
  void      femdarr2_div_RF_to(    darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_div_FR(    femdarr2_t* lhs,    darr_t* rhs);
  void      femdarr2_div_FR_to( femdarr2_t* lhs,    darr_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_div_oF(    mdnum2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_div_oF_to( mdnum2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_div_Fo(    femdarr2_t* lhs, mdnum2_t* rhs);
  void      femdarr2_div_Fo_to( femdarr2_t* lhs, mdnum2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_div_rF(      coeff_t  lhs, femdarr2_t* rhs);
  void      femdarr2_div_rF_to(    coeff_t lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_div_Fr(    femdarr2_t* lhs,   coeff_t  rhs);
  void      femdarr2_div_Fr_to( femdarr2_t* lhs,   coeff_t  rhs, femdarr2_t* res);
  mdarr2_t femdarr2_integrate(    femdarr2_t* arr, femdnum2_t* w);
  void    femdarr2_integrate_to( femdarr2_t* arr, femdnum2_t* w, mdarr2_t* res);
  femdnum2_t femdarr2_dotproduct_FF(    femdarr2_t* lhs, femdarr2_t* rhs);
  void     femdarr2_dotproduct_FF_to( femdarr2_t* lhs, femdarr2_t* rhs, femdnum2_t* res);
  femdnum2_t femdarr2_dotproduct_OF(      mdarr2_t* lhs, femdarr2_t* rhs);
  void     femdarr2_dotproduct_OF_to(   mdarr2_t* lhs, femdarr2_t* rhs, femdnum2_t* res);
  femdnum2_t femdarr2_dotproduct_RF(       darr_t* lhs, femdarr2_t* rhs);
  void     femdarr2_dotproduct_RF_to(    darr_t* lhs, femdarr2_t* rhs, femdnum2_t* res);
  femdarr2_t femdarr2_matmul_FF(    femdarr2_t* lhs, femdarr2_t* rhs);
  void      femdarr2_matmul_FF_to( femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_matmul_OF(    mdarr2_t*   lhs, femdarr2_t* rhs);
  void      femdarr2_matmul_OF_to( mdarr2_t*   lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_matmul_FO(    femdarr2_t* lhs, mdarr2_t*   rhs);
  void      femdarr2_matmul_FO_to( femdarr2_t* lhs, mdarr2_t*   rhs, femdarr2_t* res);
  femdarr2_t femdarr2_matmul_RF(    darr_t*    lhs, femdarr2_t* rhs);
  void      femdarr2_matmul_RF_to( darr_t*    lhs, femdarr2_t* rhs, femdarr2_t* res);
  femdarr2_t femdarr2_matmul_FR(    femdarr2_t* lhs, darr_t*    rhs);
  void      femdarr2_matmul_FR_to( femdarr2_t* lhs, darr_t*    rhs, femdarr2_t* res);
  femdnum2_t femdarr2_det(   femdarr2_t* arr);
  void     femdarr2_det_to(femdarr2_t* arr, femdnum2_t* res);
  femdnum2_t femdarr2_norm(     femdarr2_t* arr);
  void     femdarr2_norm_to(  femdarr2_t* arr, femdnum2_t* res);
  femdnum2_t femdarr2_pnorm(    femdarr2_t* arr, coeff_t p);
  void     femdarr2_pnorm_to( femdarr2_t* arr, coeff_t p, femdnum2_t* res);
  femdarr2_t   femdarr2_invert(    femdarr2_t* arr);
  void        femdarr2_invert_to( femdarr2_t* arr, femdarr2_t* res);
  femdarr2_t   femdarr2_transpose(   femdarr2_t* arr);
  void        femdarr2_transpose_to(femdarr2_t* arr, femdarr2_t* res);
  
  