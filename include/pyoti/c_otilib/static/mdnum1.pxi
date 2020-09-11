cdef extern from "oti/oti.h" nogil:


  # From ../../../include/oti/static/mdnum1/scalar/structures.h
  
  ctypedef struct  mdnum1_t : # {
    coeff_t r;
    coeff_t e1;
  # } mdnum1_t;
  
  
  # From ../../../include/oti/static/mdnum1/array/structures.h
  
  ctypedef struct  mdarr1_t : # {
      mdnum1_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } mdarr1_t;
  
  
  # From ../../../include/oti/static/mdnum1/scalar/gauss/structures.h
  
  ctypedef struct  femdnum1_t: # {
      mdnum1_t*  p_data;
      uint64_t    nip;
  # } femdnum1_t;
  
  
  # From ../../../include/oti/static/mdnum1/array/gauss/structures.h
  
  ctypedef struct  femdarr1_t: # {
      mdarr1_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } femdarr1_t;
  
  # =========================================================================================
  # From ../../../include/oti/static/mdnum1/scalar/functions.h
  
  mdnum1_t mdnum1_atanh(mdnum1_t* num);
  void mdnum1_atanh_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_asinh(mdnum1_t* num);
  void mdnum1_asinh_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_acosh(mdnum1_t* num);
  void mdnum1_acosh_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_tanh(mdnum1_t* num);
  void mdnum1_tanh_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_sqrt(mdnum1_t* num);
  void mdnum1_sqrt_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_cbrt(mdnum1_t* num);
  void mdnum1_cbrt_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_cosh(mdnum1_t* num);
  void mdnum1_cosh_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_sinh(mdnum1_t* num);
  void mdnum1_sinh_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_asin(mdnum1_t* num);
  void mdnum1_asin_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_acos(mdnum1_t* num);
  void mdnum1_acos_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_atan(mdnum1_t* num);
  void mdnum1_atan_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_tan(mdnum1_t* num);
  void mdnum1_tan_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_cos(mdnum1_t* num);
  void mdnum1_cos_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_sin(mdnum1_t* num );
  void mdnum1_sin_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_logb(mdnum1_t* num, double base);
  void mdnum1_logb_to(mdnum1_t* num, double base, mdnum1_t* res);
  mdnum1_t mdnum1_log10(mdnum1_t* num);
  void mdnum1_log10_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_log(mdnum1_t* num);
  void mdnum1_log_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_exp(mdnum1_t* num);
  void mdnum1_exp_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_pow(mdnum1_t* num, double e);
  void mdnum1_pow_to(mdnum1_t* num, coeff_t e, mdnum1_t* res);
  
  
  # From ../../../include/oti/static/mdnum1/scalar/base.h
  
  void mdnum1_set_im_o(mdnum1_t* num, imdir_t idx, ord_t order, mdnum1_t* res);
  void mdnum1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum1_t* res);
  void mdnum1_set_deriv_o(mdnum1_t* num, imdir_t idx, ord_t order, mdnum1_t* res);
  void mdnum1_extract_im_to( imdir_t idx, ord_t order, mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_extract_im(imdir_t idx, ord_t order, mdnum1_t* num);
  mdnum1_t mdnum1_extract_deriv(imdir_t idx, ord_t order, mdnum1_t* num);
  void mdnum1_extract_deriv_to(imdir_t idx, ord_t order, mdnum1_t* num, mdnum1_t* res);
  void mdnum1_get_im_to_o(imdir_t idx, ord_t order, mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_get_im_o(imdir_t idx, ord_t order, mdnum1_t* num);
  void mdnum1_get_im_to_r(imdir_t idx, ord_t order, mdnum1_t* num, coeff_t* res);
  ord_t mdnum1_get_order(mdnum1_t* lhs);
  mdnum1_t mdnum1_get_deriv_o( imdir_t idx, ord_t order, mdnum1_t* num);
  void mdnum1_get_deriv_to( imdir_t idx, ord_t order, mdnum1_t* num, mdnum1_t* res);
  void mdnum1_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum1_t* res);
  mdnum1_t mdnum1_init();
  ndir_t mdnum1_get_ndir_order(ord_t order, mdnum1_t* num);
  ndir_t mdnum1_get_ndir_total(mdnum1_t* num);
  coeff_t* mdnum1_get_order_address(ord_t order, mdnum1_t* num);
  mdnum1_t mdnum1_create_r(  coeff_t lhs);
  void mdnum1_set_r(  coeff_t lhs, mdnum1_t* res);
  void mdnum1_set_o(  mdnum1_t* lhs, mdnum1_t* res);
  mdnum1_t mdnum1_get_order_im(ord_t order, mdnum1_t* lhs);
  void mdnum1_get_order_im_to(ord_t order, mdnum1_t* lhs, mdnum1_t* res);
  coeff_t mdnum1_get_item(imdir_t idx, ord_t order, mdnum1_t* lhs);
  coeff_t mdnum1_get_deriv(imdir_t idx, ord_t order, mdnum1_t* lhs);
  void mdnum1_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum1_t* x);
  mdnum1_t mdnum1_copy(  mdnum1_t* lhs);
  void mdnum1_copy_to(  mdnum1_t* lhs, mdnum1_t* res);
  mdnum1_t mdnum1_taylor_integrate(coeff_t* deltas,mdnum1_t* lhs);
  void mdnum1_taylor_integrate_to(coeff_t* deltas,mdnum1_t* lhs, mdnum1_t* res);
  mdnum1_t mdnum1_truncate_im(imdir_t idx, ord_t order, mdnum1_t* lhs);
  void mdnum1_truncate_im_to(imdir_t idx, ord_t order, mdnum1_t* lhs, mdnum1_t* res);
  void mdnum1_print(  mdnum1_t* lhs);
  imdir_t mdnum1_get_indx(imdir_t idx, ord_t order);
  
  
  # From ../../../include/oti/static/mdnum1/scalar/utils.h
  
  void mdnum1_get_active_bases(mdnum1_t* num, imdir_t* list);
  
  
  # From ../../../include/oti/static/mdnum1/scalar/algebra.h
  
  mdnum1_t mdnum1_abs(mdnum1_t* num);
  mdnum1_t mdnum1_div_ro(coeff_t num, mdnum1_t* den);
  mdnum1_t mdnum1_div_oo(mdnum1_t* num, mdnum1_t* den);
  mdnum1_t mdnum1_div_or(mdnum1_t* num, coeff_t val);
  void mdnum1_div_ro_to(coeff_t num, mdnum1_t* den, mdnum1_t* res);
  void mdnum1_div_oo_to(mdnum1_t* num, mdnum1_t* den, mdnum1_t* res);
  void mdnum1_div_or_to(mdnum1_t* num, coeff_t val, mdnum1_t* res);
  void mdnum1_abs_to(mdnum1_t* num, mdnum1_t* res);
  mdnum1_t mdnum1_neg(  mdnum1_t* lhs);
  void mdnum1_neg_to(  mdnum1_t* lhs, mdnum1_t* res);
  mdnum1_t mdnum1_sum_oo(  mdnum1_t* lhs,  mdnum1_t* rhs);
  void mdnum1_sum_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res);
  mdnum1_t mdnum1_sum_ro(  coeff_t lhs,  mdnum1_t* rhs);
  void mdnum1_sum_ro_to(  coeff_t lhs,  mdnum1_t* rhs, mdnum1_t* res);
  mdnum1_t mdnum1_sub_oo(  mdnum1_t* lhs,  mdnum1_t* rhs);
  void mdnum1_sub_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res);
  mdnum1_t mdnum1_sub_ro(  coeff_t lhs,  mdnum1_t* rhs);
  void mdnum1_sub_ro_to(  coeff_t lhs,  mdnum1_t* rhs, mdnum1_t* res);
  mdnum1_t mdnum1_sub_or(  mdnum1_t* lhs,  coeff_t rhs);
  void mdnum1_sub_or_to(  mdnum1_t* lhs,  coeff_t rhs, mdnum1_t* res);
  mdnum1_t mdnum1_mul_oo(  mdnum1_t* lhs,  mdnum1_t* rhs);
  void mdnum1_mul_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res);
  mdnum1_t mdnum1_mul_ro(  coeff_t lhs,  mdnum1_t* rhs);
  void mdnum1_mul_ro_to(  coeff_t lhs,  mdnum1_t* rhs, mdnum1_t* res);
  mdnum1_t mdnum1_trunc_mul_oo(  mdnum1_t* lhs,  mdnum1_t* rhs);
  void mdnum1_trunc_mul_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res);
  mdnum1_t mdnum1_gem_oo(  mdnum1_t* a,  mdnum1_t* b,  mdnum1_t* c);
  void mdnum1_gem_oo_to(  mdnum1_t* a,  mdnum1_t* b,  mdnum1_t* c, mdnum1_t* res);
  mdnum1_t mdnum1_gem_ro(  coeff_t a,  mdnum1_t* b,  mdnum1_t* c);
  void mdnum1_gem_ro_to(  coeff_t a,  mdnum1_t* b,  mdnum1_t* c, mdnum1_t* res);
  void mdnum1_trunc_gem_oo_to( ord_t ord_lhs,  mdnum1_t* a,  ord_t ord_rhs,  mdnum1_t* b,  mdnum1_t* c, mdnum1_t* res);
  void mdnum1_trunc_sum_oo_to(ord_t order, mdnum1_t* lhs,mdnum1_t* rhs, mdnum1_t* res);
  void mdnum1_trunc_sub_oo_to(ord_t order, mdnum1_t* lhs,mdnum1_t* rhs, mdnum1_t* res);
  mdnum1_t mdnum1_feval(coeff_t* feval_re, mdnum1_t* x);
  void mdnum1_feval_to(coeff_t* feval_re, mdnum1_t* x, mdnum1_t* res);
  
  
  # From ../../../include/oti/static/mdnum1/scalar/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum1/scalar/gauss/functions.h
  
  femdnum1_t femdnum1_atanh(    femdnum1_t* num);
  void     femdnum1_atanh_to( femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_asinh(    femdnum1_t* num);
  void     femdnum1_asinh_to( femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_acosh(    femdnum1_t* num);
  void     femdnum1_acosh_to( femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_tanh(     femdnum1_t* num);
  void     femdnum1_tanh_to(  femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_cosh(     femdnum1_t* num);
  void     femdnum1_cosh_to(  femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_sinh(     femdnum1_t* num);
  void     femdnum1_sinh_to(  femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_asin(     femdnum1_t* num);
  void     femdnum1_asin_to(  femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_acos(     femdnum1_t* num);
  void     femdnum1_acos_to(  femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_atan(     femdnum1_t* num);
  void     femdnum1_atan_to(  femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_tan(      femdnum1_t* num);
  void     femdnum1_tan_to(   femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_cos(      femdnum1_t* num);
  void     femdnum1_cos_to(   femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_sin(      femdnum1_t* num);
  void     femdnum1_sin_to(   femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_logb(     femdnum1_t* num, double base);
  void     femdnum1_logb_to(  femdnum1_t* num, double base, femdnum1_t* res);
  femdnum1_t femdnum1_log10(    femdnum1_t* num);
  void     femdnum1_log10_to( femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_log(      femdnum1_t* num);
  void     femdnum1_log_to(   femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_exp(      femdnum1_t* num);
  void     femdnum1_exp_to(   femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_cbrt(     femdnum1_t* num);
  void     femdnum1_cbrt_to(  femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_sqrt(     femdnum1_t* num);
  void     femdnum1_sqrt_to(  femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_pow(      femdnum1_t* num, double e);
  void     femdnum1_pow_to(   femdnum1_t* num, double e, femdnum1_t* res);
  mdnum1_t femdnum1_integrate(       femdnum1_t* num, femdnum1_t* w);
  void      femdnum1_integrate_to(    femdnum1_t* num, femdnum1_t* w, mdnum1_t* res);
  mdnum1_t femdnum1_integrate_f(     femdnum1_t* num, femdnum1_t* w);
  void      femdnum1_integrate_f_to(  femdnum1_t* num, femdnum1_t* w, mdnum1_t* res);
  mdnum1_t femdnum1_integrate_r(       coeff_t num, femdnum1_t* w);
  void      femdnum1_integrate_r_to(    coeff_t num, femdnum1_t* w, mdnum1_t* res);
  mdnum1_t femdnum1_integrate_o(    mdnum1_t* num, femdnum1_t* w);
  void      femdnum1_integrate_o_to( mdnum1_t* num, femdnum1_t* w, mdnum1_t* res);
  
  
  # From ../../../include/oti/static/mdnum1/scalar/gauss/base.h
  
  void     femdnum1_get_order_im_to( ord_t order, femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_get_order_im(    ord_t order, femdnum1_t* num);
  femdnum1_t femdnum1_get_im(    imdir_t idx, ord_t order, femdnum1_t* num);
  void     femdnum1_get_im_to( imdir_t idx, ord_t order, femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_get_deriv(    imdir_t idx, ord_t order, femdnum1_t* num);
  void     femdnum1_get_deriv_to( imdir_t idx, ord_t order, femdnum1_t* num, femdnum1_t* res);
  void femdnum1_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum1_t* num);
  void femdnum1_set_im_o( mdnum1_t* val, imdir_t idx, ord_t order, femdnum1_t* num);
  void femdnum1_set_im_f(  femdnum1_t* val, imdir_t idx, ord_t order, femdnum1_t* num);
  void femdnum1_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum1_t* num);
  void femdnum1_set_deriv_o( mdnum1_t* val, imdir_t idx, ord_t order, femdnum1_t* num);
  void femdnum1_set_deriv_f(  femdnum1_t* val, imdir_t idx, ord_t order, femdnum1_t* num);
  femdnum1_t femdnum1_extract_im(    imdir_t idx, ord_t order, femdnum1_t* num);
  void     femdnum1_extract_im_to( imdir_t idx, ord_t order, femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_extract_deriv(    imdir_t idx, ord_t order, femdnum1_t* num);
  void     femdnum1_extract_deriv_to( imdir_t idx, ord_t order, femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_truncate_im(    imdir_t idx, ord_t order, femdnum1_t* num);
  void     femdnum1_truncate_im_to( imdir_t idx, ord_t order, femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_copy(    femdnum1_t* src);
  void     femdnum1_copy_to( femdnum1_t* src, femdnum1_t* dst);
  void femdnum1_set_r(    coeff_t num, femdnum1_t* res);
  void femdnum1_set_o( mdnum1_t* num, femdnum1_t* res);
  void femdnum1_set_f(  femdnum1_t* num, femdnum1_t* res);
  void femdnum1_set_item_k_r(   coeff_t  num, uint64_t k, femdnum1_t* res);
  void femdnum1_set_item_k_o( mdnum1_t* num, uint64_t k, femdnum1_t* res);
  mdnum1_t femdnum1_get_item_k(   femdnum1_t* num, uint64_t k);
  void      femdnum1_get_item_k_to(femdnum1_t* num, uint64_t k, mdnum1_t* res);
  femdnum1_t femdnum1_zeros(uint64_t nIntPts);
  femdnum1_t femdnum1_createEmpty(uint64_t nIntPts);
  femdnum1_t femdnum1_empty_like(femdnum1_t* arr);
  void femdnum1_free(femdnum1_t* num);
  ord_t femdnum1_get_order( femdnum1_t* num );
  femdnum1_t femdnum1_init();
  
  
  # From ../../../include/oti/static/mdnum1/scalar/gauss/utils.h
  
  void femdnum1_dimCheck(femdnum1_t* arr1,femdnum1_t* arr2);
  void femdnum1_get_active_bases(femdnum1_t* num, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum1/scalar/gauss/algebra.h
  
  femdnum1_t femdnum1_neg(   femdnum1_t* num);
  void     femdnum1_neg_to(femdnum1_t* num, femdnum1_t* res);
  femdnum1_t femdnum1_sum_ff(   femdnum1_t* lhs, femdnum1_t* rhs);
  void     femdnum1_sum_ff_to(femdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_sum_of(   mdnum1_t* lhs, femdnum1_t* rhs);
  void     femdnum1_sum_of_to(mdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_sum_rf(   coeff_t lhs, femdnum1_t* rhs);
  void     femdnum1_sum_rf_to(coeff_t lhs, femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_sub_ff(     femdnum1_t* lhs,  femdnum1_t* rhs);
  void     femdnum1_sub_ff_to(  femdnum1_t* lhs,  femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_sub_of(    mdnum1_t* lhs,  femdnum1_t* rhs);
  void     femdnum1_sub_of_to( mdnum1_t* lhs,  femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_sub_fo(     femdnum1_t* lhs, mdnum1_t* rhs);
  void     femdnum1_sub_fo_to(  femdnum1_t* lhs, mdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_sub_rf(       coeff_t lhs,  femdnum1_t* rhs);
  void     femdnum1_sub_rf_to(    coeff_t lhs,  femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_sub_fr(     femdnum1_t* lhs,    coeff_t rhs);
  void     femdnum1_sub_fr_to(  femdnum1_t* lhs,    coeff_t rhs, femdnum1_t* res);
  femdnum1_t femdnum1_mul_ff(   femdnum1_t* lhs, femdnum1_t* rhs);
  void     femdnum1_mul_ff_to(femdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_mul_of(   mdnum1_t* lhs, femdnum1_t* rhs);
  void     femdnum1_mul_of_to(mdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_mul_rf(   coeff_t lhs, femdnum1_t* rhs);
  void     femdnum1_mul_rf_to(coeff_t lhs, femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_div_ff(     femdnum1_t* lhs,  femdnum1_t* rhs);
  void     femdnum1_div_ff_to(  femdnum1_t* lhs,  femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_div_of(    mdnum1_t* lhs,  femdnum1_t* rhs);
  void     femdnum1_div_of_to( mdnum1_t* lhs,  femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_div_fo(     femdnum1_t* lhs, mdnum1_t* rhs);
  void     femdnum1_div_fo_to(  femdnum1_t* lhs, mdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_div_rf(       coeff_t lhs,  femdnum1_t* rhs);
  void     femdnum1_div_rf_to(    coeff_t lhs,  femdnum1_t* rhs, femdnum1_t* res);
  femdnum1_t femdnum1_div_fr(     femdnum1_t* lhs,    coeff_t rhs);
  void     femdnum1_div_fr_to(  femdnum1_t* lhs,    coeff_t rhs, femdnum1_t* res);
  
  
  # From ../../../include/oti/static/mdnum1/array/functions.h
  
  mdarr1_t mdarr1_atanh(   mdarr1_t* arr);
  void    mdarr1_atanh_to(mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_asinh(   mdarr1_t* arr);
  void    mdarr1_asinh_to(mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_acosh(   mdarr1_t* arr);
  void    mdarr1_acosh_to(mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_tanh(    mdarr1_t* arr);
  void    mdarr1_tanh_to( mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_cbrt(    mdarr1_t* arr);
  void    mdarr1_cbrt_to( mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_sqrt(    mdarr1_t* arr);
  void    mdarr1_sqrt_to( mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_cosh(    mdarr1_t* arr);
  void    mdarr1_cosh_to( mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_sinh(    mdarr1_t* arr);
  void    mdarr1_sinh_to( mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_asin(    mdarr1_t* arr);
  void    mdarr1_asin_to( mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_acos(    mdarr1_t* arr);
  void    mdarr1_acos_to( mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_atan(    mdarr1_t* arr);
  void    mdarr1_atan_to( mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_tan(     mdarr1_t* arr);
  void    mdarr1_tan_to(  mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_cos(     mdarr1_t* arr);
  void    mdarr1_cos_to(  mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_sin(     mdarr1_t* arr);
  void    mdarr1_sin_to(  mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_logb(    mdarr1_t* arr, double base);
  void    mdarr1_logb_to( mdarr1_t* arr, double base, mdarr1_t* res);
  mdarr1_t mdarr1_log10(   mdarr1_t* arr);
  void    mdarr1_log10_to(mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_log(     mdarr1_t* arr);
  void    mdarr1_log_to(  mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_exp(     mdarr1_t* arr);
  void    mdarr1_exp_to(  mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_pow(     mdarr1_t* arr, double e);
  void    mdarr1_pow_to(  mdarr1_t* arr, double e, mdarr1_t* res);
  
  
  # From ../../../include/oti/static/mdnum1/array/algebra_elementwise.h
  
  mdarr1_t mdarr1_neg(mdarr1_t* arr);
  void mdarr1_neg_to(mdarr1_t* rhs, mdarr1_t* res);
  mdarr1_t mdarr1_sum_OO(mdarr1_t*   lhs, mdarr1_t* rhs);
  mdarr1_t mdarr1_sum_RO(darr_t*    lhs, mdarr1_t* rhs);
  mdarr1_t mdarr1_sum_oO(mdnum1_t* lhs, mdarr1_t* rhs);
  mdarr1_t mdarr1_sum_rO(coeff_t    lhs, mdarr1_t* rhs);
  void mdarr1_sum_OO_to(mdarr1_t*   lhs, mdarr1_t* rhs, mdarr1_t* res);
  void mdarr1_sum_RO_to(darr_t*    lhs, mdarr1_t* rhs, mdarr1_t* res);
  void mdarr1_sum_oO_to(mdnum1_t* lhs, mdarr1_t* rhs, mdarr1_t* res);
  void mdarr1_sum_rO_to(coeff_t    lhs, mdarr1_t* rhs, mdarr1_t* res);
  void mdarr1_trunc_sum_OO_to(ord_t order, mdarr1_t* arr1, mdarr1_t* arr2, mdarr1_t* res);
  mdarr1_t mdarr1_sub_OO(mdarr1_t*   lhs, mdarr1_t*   rhs);
  mdarr1_t mdarr1_sub_RO(darr_t*    lhs, mdarr1_t*   rhs);
  mdarr1_t mdarr1_sub_OR(mdarr1_t*   lhs, darr_t*    rhs);
  mdarr1_t mdarr1_sub_oO(mdnum1_t* lhs, mdarr1_t*   rhs);
  mdarr1_t mdarr1_sub_Oo(mdarr1_t*   lhs, mdnum1_t* rhs);
  mdarr1_t mdarr1_sub_rO(coeff_t    lhs, mdarr1_t*   rhs);
  mdarr1_t mdarr1_sub_Or(mdarr1_t*   lhs, coeff_t    rhs);
  void mdarr1_sub_OO_to( mdarr1_t*   lhs, mdarr1_t*   rhs, mdarr1_t* res);
  void mdarr1_sub_RO_to( darr_t*    lhs, mdarr1_t*   rhs, mdarr1_t* res);
  void mdarr1_sub_OR_to( mdarr1_t*   lhs, darr_t*    rhs, mdarr1_t* res);
  void mdarr1_sub_oO_to( mdnum1_t* lhs, mdarr1_t*   rhs, mdarr1_t* res);
  void mdarr1_sub_Oo_to( mdarr1_t*   lhs, mdnum1_t* rhs, mdarr1_t* res);
  void mdarr1_sub_rO_to( coeff_t    lhs, mdarr1_t*   rhs, mdarr1_t* res);
  void mdarr1_sub_Or_to( mdarr1_t*   lhs, coeff_t    rhs, mdarr1_t* res);
  void mdarr1_trunc_sub_OO_to(ord_t order, mdarr1_t* arr1, mdarr1_t* arr2, mdarr1_t* res);
  mdarr1_t mdarr1_mul_OO(mdarr1_t*   lhs, mdarr1_t* rhs);
  mdarr1_t mdarr1_mul_RO(darr_t*    lhs, mdarr1_t* rhs);
  mdarr1_t mdarr1_mul_oO(mdnum1_t* lhs, mdarr1_t* rhs);
  mdarr1_t mdarr1_mul_rO(coeff_t    lhs, mdarr1_t* rhs);
  void mdarr1_mul_OO_to(mdarr1_t*   lhs, mdarr1_t* rhs, mdarr1_t* res);
  void mdarr1_mul_RO_to(darr_t*    lhs, mdarr1_t* rhs, mdarr1_t* res);
  void mdarr1_mul_oO_to(mdnum1_t* lhs, mdarr1_t* rhs, mdarr1_t* res);
  void mdarr1_mul_rO_to(coeff_t    lhs, mdarr1_t* rhs, mdarr1_t* res);
  void mdarr1_gem_OO_to(  mdarr1_t* arr1, mdarr1_t* arr2, mdarr1_t* arr3, mdarr1_t* res);
  void mdarr1_gem_oO_to(mdnum1_t* arr1, mdarr1_t* arr2, mdarr1_t* arr3, mdarr1_t* res);
  mdarr1_t mdarr1_div_OO(mdarr1_t*   lhs, mdarr1_t*   rhs);
  mdarr1_t mdarr1_div_OR(mdarr1_t*   lhs, darr_t*    rhs);
  mdarr1_t mdarr1_div_RO(darr_t*    lhs, mdarr1_t*   rhs);
  mdarr1_t mdarr1_div_oO(mdnum1_t* lhs, mdarr1_t*   rhs);
  mdarr1_t mdarr1_div_Oo(mdarr1_t*   lhs, mdnum1_t* rhs);
  mdarr1_t mdarr1_div_rO(coeff_t    lhs, mdarr1_t*   rhs);
  mdarr1_t mdarr1_div_Or(mdarr1_t*   lhs, coeff_t    rhs);
  void mdarr1_div_OO_to(mdarr1_t*   lhs, mdarr1_t*   rhs, mdarr1_t* res);
  void mdarr1_div_RO_to(darr_t*    lhs, mdarr1_t*   rhs, mdarr1_t* res);
  void mdarr1_div_OR_to(mdarr1_t*   lhs, darr_t*    rhs, mdarr1_t* res);
  void mdarr1_div_oO_to(mdnum1_t* lhs, mdarr1_t*   rhs, mdarr1_t* res);
  void mdarr1_div_Oo_to(mdarr1_t*   lhs, mdnum1_t* rhs, mdarr1_t* res);
  void mdarr1_div_rO_to(coeff_t    lhs, mdarr1_t*   rhs, mdarr1_t* res);
  void mdarr1_div_Or_to(mdarr1_t*   lhs, coeff_t    rhs, mdarr1_t* res);
  
  
  # From ../../../include/oti/static/mdnum1/array/base.h
  
  void    mdarr1_taylor_integrate_to( coeff_t* deltas, mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_taylor_integrate(    coeff_t* deltas, mdarr1_t* arr);
  void    mdarr1_get_order_im_to( ord_t order, mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_get_order_im(    ord_t order, mdarr1_t* arr);
  void mdarr1_set_slice_r( coeff_t val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr1_t* res);
  void mdarr1_set_slice_O( mdarr1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr1_t* res);
  void mdarr1_set_slice_o( mdnum1_t* val,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr1_t* res);
  mdarr1_t mdarr1_get_slice( mdarr1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);
  void mdarr1_get_slice_to( mdarr1_t* arr,
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           mdarr1_t* res);
  mdarr1_t mdarr1_truncate_im(    imdir_t idx, ord_t order, mdarr1_t* arr);
  void    mdarr1_truncate_im_to( imdir_t idx, ord_t order, mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_extract_im(   imdir_t idx, ord_t order, mdarr1_t* arr);
  void    mdarr1_extract_im_to(imdir_t idx, ord_t order, mdarr1_t* arr, mdarr1_t* res);
  darr_t  mdarr1_get_deriv(    imdir_t idx, ord_t order, mdarr1_t* arr);
  void    mdarr1_get_deriv_to( imdir_t idx, ord_t order, mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_get_deriv_o(  imdir_t idx, ord_t order, mdarr1_t* arr);
  mdarr1_t mdarr1_extract_deriv(    imdir_t idx, ord_t order, mdarr1_t* arr);
  void    mdarr1_extract_deriv_to( imdir_t idx, ord_t order, mdarr1_t* arr, mdarr1_t* res);
  darr_t  mdarr1_get_im(   imdir_t idx, ord_t order, mdarr1_t* arr);
  mdarr1_t mdarr1_get_im_o( imdir_t idx, ord_t order, mdarr1_t* arr);
  void    mdarr1_get_im_to(imdir_t idx, ord_t order, mdarr1_t* arr, mdarr1_t* res);
  void    mdarr1_copy_to(mdarr1_t* arr, mdarr1_t* res);
  mdarr1_t mdarr1_copy(mdarr1_t* arr);
  void mdarr1_set_all_r( coeff_t num, mdarr1_t* arr);
  void mdarr1_set_item_i_r( coeff_t num, uint64_t i, mdarr1_t* arr);
  void mdarr1_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, mdarr1_t* arr);
  void mdarr1_set_r(   coeff_t  num,   mdarr1_t* arr);
  void mdarr1_set_o( mdnum1_t* num,   mdarr1_t* arr);
  void mdarr1_set_O(   mdarr1_t* arrin, mdarr1_t* arr);
  void mdarr1_set_all_o( mdnum1_t* src, mdarr1_t* arr);
  void mdarr1_set_item_i_o( mdnum1_t* num, uint64_t i, mdarr1_t* arr);
  void mdarr1_set_item_ij_o( mdnum1_t* num, uint64_t i, uint64_t j, mdarr1_t* arr);
  mdnum1_t mdarr1_get_item_i(    mdarr1_t* arr, uint64_t i);
  void      mdarr1_get_item_i_to( mdarr1_t* arr, uint64_t i,             mdnum1_t* res);
  mdnum1_t mdarr1_get_item_ij(   mdarr1_t* arr, uint64_t i, uint64_t j);
  void      mdarr1_get_item_ij_to(mdarr1_t* arr, uint64_t i, uint64_t j, mdnum1_t* res);
  mdarr1_t mdarr1_init();
  void mdarr1_free(mdarr1_t* arr);
  mdarr1_t mdarr1_empty_like(mdarr1_t* arr);
  mdarr1_t mdarr1_eye(uint64_t nrows);
  mdarr1_t mdarr1_ones(uint64_t nrows, uint64_t ncols);
  mdarr1_t mdarr1_zeros(uint64_t nrows, uint64_t ncols);
  mdarr1_t mdarr1_createEmpty(uint64_t nrows, uint64_t ncols);
  
  
  # From ../../../include/oti/static/mdnum1/array/utils.h
  
  void mdarr1_dimCheck_OO_elementwise(mdarr1_t* arr1, mdarr1_t* arr2, mdarr1_t* res);
  void mdarr1_dimCheck_RO_elementwise(darr_t*  arr1, mdarr1_t* arr2, mdarr1_t* res);
  void mdarr1_dimCheck_OO_matmul(mdarr1_t* arr1, mdarr1_t* arr2, mdarr1_t* res);
  void mdarr1_dimCheck_RO_matmul(darr_t*  arr1, mdarr1_t* arr2, mdarr1_t* res);
  void mdarr1_dimCheck_OR_matmul(mdarr1_t* arr1, darr_t*  arr2, mdarr1_t* res);
  void mdarr1_dimCheck_O_squareness(mdarr1_t* arr1, mdarr1_t* res);
  void mdarr1_dimCheck_OO_samesize(mdarr1_t* arr1, mdarr1_t* res);
  void mdarr1_dimCheck_RO_samesize(darr_t* arr1, mdarr1_t* res);
  ord_t mdarr1_get_order(mdarr1_t* arr);
  void mdarr1_get_active_bases(mdarr1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum1/array/algebra_matops.h
  
  mdnum1_t mdarr1_dotproduct_OO(    mdarr1_t* lhs, mdarr1_t* rhs);
  void      mdarr1_dotproduct_OO_to( mdarr1_t* lhs, mdarr1_t* rhs, mdnum1_t* res);
  mdnum1_t mdarr1_dotproduct_RO(     darr_t* lhs, mdarr1_t* rhs);
  void      mdarr1_dotproduct_RO_to(  darr_t* lhs, mdarr1_t* rhs, mdnum1_t* res);
  mdarr1_t mdarr1_matmul_OO(    mdarr1_t* lhs, mdarr1_t* rhs);
  mdarr1_t mdarr1_matmul_OR(    mdarr1_t* lhs,  darr_t* rhs);
  mdarr1_t mdarr1_matmul_RO(     darr_t* lhs, mdarr1_t* rhs);
  void    mdarr1_matmul_OO_to( mdarr1_t* lhs, mdarr1_t* rhs, mdarr1_t* res);
  void    mdarr1_matmul_OR_to( mdarr1_t* lhs,  darr_t* rhs, mdarr1_t* res);
  void    mdarr1_matmul_RO_to(  darr_t* lhs, mdarr1_t* rhs, mdarr1_t* res);
  mdarr1_t mdarr1_transpose(    mdarr1_t* arr1);
  void    mdarr1_transpose_to( mdarr1_t* arr1, mdarr1_t* res);
  mdarr1_t mdarr1_invert(    mdarr1_t* arr1);
  void    mdarr1_invert_to( mdarr1_t* arr1, mdarr1_t* res);
  mdnum1_t mdarr1_det(    mdarr1_t* arr1);
  void      mdarr1_det_to( mdarr1_t* arr1, mdnum1_t* res);
  mdnum1_t mdarr1_norm(    mdarr1_t* arr1);
  void      mdarr1_norm_to( mdarr1_t* arr1,  mdnum1_t* res);
  mdnum1_t mdarr1_pnorm(    mdarr1_t* arr1, coeff_t p);
  void      mdarr1_pnorm_to( mdarr1_t* arr1, coeff_t p, mdnum1_t* res);
  
  
  # From ../../../include/oti/static/mdnum1/array/gauss.h
  
  
  
  # From ../../../include/oti/static/mdnum1/array/gauss/functions.h
  
  femdarr1_t femdarr1_atanh(    femdarr1_t* arr);
  void      femdarr1_atanh_to( femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_asinh(    femdarr1_t* arr);
  void      femdarr1_asinh_to( femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_acosh(    femdarr1_t* arr);
  void      femdarr1_acosh_to( femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_tanh(     femdarr1_t* arr);
  void      femdarr1_tanh_to(  femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_sinh(     femdarr1_t* arr);
  void      femdarr1_sinh_to(  femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_cosh(     femdarr1_t* arr);
  void      femdarr1_cosh_to(  femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_atan(     femdarr1_t* arr);
  void      femdarr1_atan_to(  femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_asin(     femdarr1_t* arr);
  void      femdarr1_asin_to(  femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_acos(     femdarr1_t* arr);
  void      femdarr1_acos_to(  femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_tan(      femdarr1_t* arr);
  void      femdarr1_tan_to(   femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_sin(      femdarr1_t* arr);
  void      femdarr1_sin_to(   femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_cos(      femdarr1_t* arr);
  void      femdarr1_cos_to(   femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_logb(     femdarr1_t* arr, double base);
  void      femdarr1_logb_to(  femdarr1_t* arr, double base, femdarr1_t* res);
  femdarr1_t femdarr1_log10(    femdarr1_t* arr);
  void      femdarr1_log10_to( femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_log(      femdarr1_t* arr);
  void      femdarr1_log_to(   femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_exp(      femdarr1_t* arr);
  void      femdarr1_exp_to(   femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_cbrt(     femdarr1_t* arr);
  void      femdarr1_cbrt_to(  femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_sqrt(     femdarr1_t* arr);
  void      femdarr1_sqrt_to(  femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_pow(      femdarr1_t* arr, double e);
  void      femdarr1_pow_to(   femdarr1_t* arr, double e, femdarr1_t* res);
  
  
  # From ../../../include/oti/static/mdnum1/array/gauss/base.h
  
  void      femdarr1_get_order_im_to( ord_t order, femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_get_order_im(    ord_t order, femdarr1_t* arr);
  femdarr1_t femdarr1_get_deriv(   imdir_t idx, ord_t order, femdarr1_t* arr);
  void      femdarr1_get_deriv_to(imdir_t idx, ord_t order, femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_get_im(      imdir_t idx, ord_t order, femdarr1_t* arr);
  void      femdarr1_get_im_to(   imdir_t idx, ord_t order, femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_truncate_im(   imdir_t idx, ord_t order, femdarr1_t* arr);
  void      femdarr1_truncate_im_to(imdir_t idx, ord_t order, femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_copy(   femdarr1_t* src);
  void      femdarr1_copy_to(femdarr1_t* src, femdarr1_t* res);
  femdarr1_t femdarr1_get_im(    imdir_t idx, ord_t order, femdarr1_t* arr);
  void      femdarr1_get_im_to( imdir_t idx, ord_t order, femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_get_deriv(    imdir_t idx, ord_t order, femdarr1_t* arr);
  void      femdarr1_get_deriv_to( imdir_t idx, ord_t order, femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_extract_im(    imdir_t idx, ord_t order, femdarr1_t* arr);
  void      femdarr1_extract_im_to( imdir_t idx, ord_t order, femdarr1_t* arr,  femdarr1_t* res);
  femdarr1_t femdarr1_extract_deriv(    imdir_t idx, ord_t order, femdarr1_t* arr);
  void      femdarr1_extract_deriv_to( imdir_t idx, ord_t order, femdarr1_t* arr, femdarr1_t* res);
  mdarr1_t   femdarr1_get_item_k(  femdarr1_t* arr, uint64_t k);
  femdnum1_t  femdarr1_get_item_ij( femdarr1_t* arr, uint64_t i, uint64_t j);
  mdnum1_t femdarr1_get_item_ijk(femdarr1_t* arr, uint64_t i, uint64_t j, uint64_t k);
  void femdarr1_get_item_ij_to(  femdarr1_t* arr, uint64_t i, uint64_t j,
                                 femdnum1_t* res);
  void femdarr1_get_item_k_to(   femdarr1_t* arr, uint64_t k,
                                  mdarr1_t* res);
  void femdarr1_get_item_ijk_to( femdarr1_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                mdnum1_t* res);
  femdarr1_t femdarr1_get_slice(femdarr1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj);
  void      femdarr1_get_slice_to(femdarr1_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr1_t* res);
  void femdarr1_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              femdarr1_t* res);
  void femdarr1_set_item_ij_o(  mdnum1_t* elm, uint64_t i, uint64_t j,
                               femdarr1_t* res);
  void femdarr1_set_item_ij_f(  femdnum1_t* elm, uint64_t i, uint64_t j,
                              femdarr1_t* res);
  void femdarr1_set_item_k_r(    coeff_t  elm, uint64_t k,
                              femdarr1_t* res);
  void femdarr1_set_item_k_o(  mdnum1_t* elm, uint64_t k,
                              femdarr1_t* res);
  void femdarr1_set_item_k_R(    mdarr1_t* elm, uint64_t k,
                            femdarr1_t* res);
  void femdarr1_set_item_k_O(    mdarr1_t* elm, uint64_t k,
                            femdarr1_t* res);
  void femdarr1_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr1_t* res);
  void femdarr1_set_item_ijk_o( mdnum1_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               femdarr1_t* res);
  void femdarr1_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr1_t* res);
  void femdarr1_set_slice_o( mdnum1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr1_t* res);
  void femdarr1_set_slice_f( femdnum1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr1_t* res);
  void femdarr1_set_slice_O( mdarr1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr1_t* res);
  void femdarr1_set_slice_F( femdarr1_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            femdarr1_t* res);
  void femdarr1_set_all_o( mdnum1_t* num, femdarr1_t* arr );
  void femdarr1_set_all_r(   coeff_t  num, femdarr1_t* arr );
  void femdarr1_set_all_f(  femdnum1_t* num, femdarr1_t* arr );
  void femdarr1_set_r(    coeff_t src, femdarr1_t* res );
  void femdarr1_set_o( mdnum1_t* src, femdarr1_t* res );
  void femdarr1_set_f(  femdnum1_t* src, femdarr1_t* res );
  void femdarr1_set_R(    darr_t* src, femdarr1_t* res );
  void femdarr1_set_O(   mdarr1_t* src, femdarr1_t* res );
  void femdarr1_set_F( femdarr1_t* src, femdarr1_t* res );
  femdarr1_t femdarr1_eye( uint64_t size,  uint64_t nip);
  femdarr1_t femdarr1_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
  femdarr1_t femdarr1_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
  femdarr1_t femdarr1_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
  void femdarr1_free(femdarr1_t* arr);
  femdarr1_t femdarr1_init();
  ord_t femdarr1_get_order(femdarr1_t* arr);
  
  
  # From ../../../include/oti/static/mdnum1/array/gauss/utils.h
  
  void femdarr1_dimCheck_FF_samesize(femdarr1_t* arr1, femdarr1_t* arr2, femdnum1_t* res);
  void femdarr1_dimCheck_OF_samesize(  mdarr1_t* arr1, femdarr1_t* arr2, femdnum1_t* res);
  void femdarr1_dimCheck_RF_samesize(   darr_t* arr1, femdarr1_t* arr2, femdnum1_t* res);
  void femdarr1_dimCheck_FF_elementwise(femdarr1_t* arr1, femdarr1_t* arr2, femdarr1_t* res);
  void femdarr1_dimCheck_OF_elementwise(  mdarr1_t* arr1, femdarr1_t* arr2, femdarr1_t* res);
  void femdarr1_dimCheck_RF_elementwise(   darr_t* arr1, femdarr1_t* arr2, femdarr1_t* res);
  void femdarr1_dimCheck_fF_elementwise( femdnum1_t* num1, femdarr1_t* arr2, femdarr1_t* res);
  void femdarr1_dimCheck_Ff_elementwise(femdarr1_t* arr1,  femdnum1_t* num2, femdarr1_t* res);
  void femdarr1_dimCheck_FF_matmul( femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  void femdarr1_dimCheck_OF_matmul(   mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  void femdarr1_dimCheck_RF_matmul(    darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  void femdarr1_dimCheck_FO_matmul( femdarr1_t* lhs,   mdarr1_t* rhs, femdarr1_t* res);
  void femdarr1_dimCheck_FR_matmul( femdarr1_t* lhs,    darr_t* rhs, femdarr1_t* res);
  void femdarr1_dimCheck_F_squareness( femdarr1_t* arr1, femdarr1_t* res);
  void femdarr1_dimCheck_F_transpose( femdarr1_t* arr1, femdarr1_t* res);
  void femdarr1_dimCheck_FfO_integrate(femdarr1_t* arr, femdnum1_t* num,mdarr1_t* res);
  void femdarr1_get_active_bases(femdarr1_t* arr, imdir_t* list_vals);
  
  
  # From ../../../include/oti/static/mdnum1/array/gauss/algebra.h
  
  femdarr1_t femdarr1_neg(    femdarr1_t* arr);
  void      femdarr1_neg_to( femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t femdarr1_sum_FF(   femdarr1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_sum_FF_to(femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sum_fF(    femdnum1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_sum_fF_to( femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sum_OF(     mdarr1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_sum_OF_to(  mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sum_RF(      darr_t* lhs, femdarr1_t* rhs);
  void      femdarr1_sum_RF_to(   darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sum_oF(   mdnum1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_sum_oF_to(mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sum_rF(     coeff_t  lhs, femdarr1_t* rhs);
  void      femdarr1_sum_rF_to(  coeff_t  lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sub_FF(    femdarr1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_sub_FF_to( femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sub_fF(    femdnum1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_sub_fF_to( femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sub_Ff(    femdarr1_t* lhs, femdnum1_t* rhs);
  void      femdarr1_sub_Ff_to( femdarr1_t* lhs, femdnum1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sub_OF(      mdarr1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_sub_OF_to(   mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sub_FO(    femdarr1_t* lhs,   mdarr1_t* rhs);
  void      femdarr1_sub_FO_to( femdarr1_t* lhs,   mdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sub_RF(       darr_t* lhs, femdarr1_t* rhs);
  void      femdarr1_sub_RF_to(    darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sub_FR(    femdarr1_t* lhs,    darr_t* rhs);
  void      femdarr1_sub_FR_to( femdarr1_t* lhs,    darr_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sub_oF(    mdnum1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_sub_oF_to( mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sub_Fo(    femdarr1_t* lhs, mdnum1_t* rhs);
  void      femdarr1_sub_Fo_to( femdarr1_t* lhs, mdnum1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sub_rF(      coeff_t  lhs, femdarr1_t* rhs);
  void      femdarr1_sub_rF_to(    coeff_t lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_sub_Fr(    femdarr1_t* lhs,   coeff_t  rhs);
  void      femdarr1_sub_Fr_to( femdarr1_t* lhs,   coeff_t  rhs, femdarr1_t* res);
  femdarr1_t femdarr1_mul_FF(   femdarr1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_mul_FF_to(femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_mul_fF(    femdnum1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_mul_fF_to( femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_mul_OF(     mdarr1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_mul_OF_to(  mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_mul_RF(      darr_t* lhs, femdarr1_t* rhs);
  void      femdarr1_mul_RF_to(   darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_mul_oF(   mdnum1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_mul_oF_to(mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_mul_rF(     coeff_t  lhs, femdarr1_t* rhs);
  void      femdarr1_mul_rF_to(  coeff_t  lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_div_FF(    femdarr1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_div_FF_to( femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_div_fF(     femdnum1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_div_fF_to(  femdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_div_Ff(    femdarr1_t* lhs,  femdnum1_t* rhs);
  void      femdarr1_div_Ff_to( femdarr1_t* lhs,  femdnum1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_div_OF(      mdarr1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_div_OF_to(   mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_div_FO(    femdarr1_t* lhs,   mdarr1_t* rhs);
  void      femdarr1_div_FO_to( femdarr1_t* lhs,   mdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_div_RF(       darr_t* lhs, femdarr1_t* rhs);
  void      femdarr1_div_RF_to(    darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_div_FR(    femdarr1_t* lhs,    darr_t* rhs);
  void      femdarr1_div_FR_to( femdarr1_t* lhs,    darr_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_div_oF(    mdnum1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_div_oF_to( mdnum1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_div_Fo(    femdarr1_t* lhs, mdnum1_t* rhs);
  void      femdarr1_div_Fo_to( femdarr1_t* lhs, mdnum1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_div_rF(      coeff_t  lhs, femdarr1_t* rhs);
  void      femdarr1_div_rF_to(    coeff_t lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_div_Fr(    femdarr1_t* lhs,   coeff_t  rhs);
  void      femdarr1_div_Fr_to( femdarr1_t* lhs,   coeff_t  rhs, femdarr1_t* res);
  mdarr1_t femdarr1_integrate(    femdarr1_t* arr, femdnum1_t* w);
  void    femdarr1_integrate_to( femdarr1_t* arr, femdnum1_t* w, mdarr1_t* res);
  femdnum1_t femdarr1_dotproduct_FF(    femdarr1_t* lhs, femdarr1_t* rhs);
  void     femdarr1_dotproduct_FF_to( femdarr1_t* lhs, femdarr1_t* rhs, femdnum1_t* res);
  femdnum1_t femdarr1_dotproduct_OF(      mdarr1_t* lhs, femdarr1_t* rhs);
  void     femdarr1_dotproduct_OF_to(   mdarr1_t* lhs, femdarr1_t* rhs, femdnum1_t* res);
  femdnum1_t femdarr1_dotproduct_RF(       darr_t* lhs, femdarr1_t* rhs);
  void     femdarr1_dotproduct_RF_to(    darr_t* lhs, femdarr1_t* rhs, femdnum1_t* res);
  femdarr1_t femdarr1_matmul_FF(    femdarr1_t* lhs, femdarr1_t* rhs);
  void      femdarr1_matmul_FF_to( femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_matmul_OF(    mdarr1_t*   lhs, femdarr1_t* rhs);
  void      femdarr1_matmul_OF_to( mdarr1_t*   lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_matmul_FO(    femdarr1_t* lhs, mdarr1_t*   rhs);
  void      femdarr1_matmul_FO_to( femdarr1_t* lhs, mdarr1_t*   rhs, femdarr1_t* res);
  femdarr1_t femdarr1_matmul_RF(    darr_t*    lhs, femdarr1_t* rhs);
  void      femdarr1_matmul_RF_to( darr_t*    lhs, femdarr1_t* rhs, femdarr1_t* res);
  femdarr1_t femdarr1_matmul_FR(    femdarr1_t* lhs, darr_t*    rhs);
  void      femdarr1_matmul_FR_to( femdarr1_t* lhs, darr_t*    rhs, femdarr1_t* res);
  femdnum1_t femdarr1_det(   femdarr1_t* arr);
  void     femdarr1_det_to(femdarr1_t* arr, femdnum1_t* res);
  femdnum1_t femdarr1_norm(     femdarr1_t* arr);
  void     femdarr1_norm_to(  femdarr1_t* arr, femdnum1_t* res);
  femdnum1_t femdarr1_pnorm(    femdarr1_t* arr, coeff_t p);
  void     femdarr1_pnorm_to( femdarr1_t* arr, coeff_t p, femdnum1_t* res);
  femdarr1_t   femdarr1_invert(    femdarr1_t* arr);
  void        femdarr1_invert_to( femdarr1_t* arr, femdarr1_t* res);
  femdarr1_t   femdarr1_transpose(   femdarr1_t* arr);
  void        femdarr1_transpose_to(femdarr1_t* arr, femdarr1_t* res);
  
  