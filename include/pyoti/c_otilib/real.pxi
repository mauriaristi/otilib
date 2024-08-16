
cdef extern from "oti/oti.h" nogil:
  # From oti/real/array/structures.h

  ctypedef struct darr_t: # {
      coeff_t*      p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } darr_t;


  # From oti/real/array/gauss/structures.h

  ctypedef struct fedarr_t: # {
      darr_t*       p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
      uint64_t         nip;
  # } fedarr_t;


  # From oti/real/scalar/gauss/structures.h

  ctypedef struct fednum_t: # {
      coeff_t*      p_data;
      uint64_t         nip;
  # } fednum_t;


  # =========================================================================================

  # From oti/real/derivatives.h

  void der_r_erf(coeff_t x,  ord_t order, coeff_t* derivs);
  void der_r_atan2(coeff_t x, coeff_t y, ord_t order, coeff_t* derivs);
  void der_r_logb(coeff_t x, coeff_t base, ord_t order, coeff_t* derivs);
  void der_r_log10(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_atanh(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_asinh(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_acosh(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_tanh(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_sqrt(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_cosh(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_sinh(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_asin(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_acos(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_atan(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_tan(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_cos(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_sin(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_log(coeff_t x , ord_t order, coeff_t* derivs);
  void der_r_exp(coeff_t x, ord_t order, coeff_t* derivs);
  void der_r_pow(coeff_t x, coeff_t e, ord_t order, coeff_t* derivs);


  # From oti/real/array/utils.h

  int64_t get_slice_size(int64_t start, int64_t stop, int64_t step);
  void darr_set_slice_R( darr_t* arr, int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj, darr_t* res   );
  void darr_set_slice_r( coeff_t val, int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,darr_t* res   );
  void darr_dimCheck_RR_samesize(darr_t* lhs, darr_t* rhs);
  void darr_dimCheck_RR_elementwise(darr_t* lhs, darr_t* rhs, darr_t* res);
  void darr_dimCheck_RR_matmul( darr_t* lhs, darr_t* rhs, darr_t* res);
  void darr_dimCheck_R_squareness( darr_t* lhs, darr_t* res);
  void darr_dimCheck_R_transpose( darr_t* lhs, darr_t* res);


  # From oti/real/array/algebra.h

  darr_t darr_neg(    darr_t* arr              );
  void   darr_neg_to( darr_t* arr, darr_t* res );
  darr_t darr_abs(    darr_t* arr              );
  void   darr_abs_to( darr_t* arr, darr_t* res );
  darr_t darr_div_RR(    darr_t* lhs, darr_t* rhs              );
  darr_t darr_div_Rr(    darr_t* lhs, coeff_t rhs              );
  darr_t darr_div_rR(    coeff_t lhs, darr_t* rhs              );
  void   darr_div_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res );
  void   darr_div_Rr_to( darr_t* lhs, coeff_t rhs, darr_t* res );
  void   darr_div_rR_to( coeff_t lhs, darr_t* rhs, darr_t* res );
  darr_t darr_mul_RR(    darr_t* lhs, darr_t* rhs              );
  void   darr_mul_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res );
  darr_t darr_mul_rR(    coeff_t lhs, darr_t* rhs              );
  void   darr_mul_rR_to( coeff_t lhs, darr_t* rhs, darr_t* res );
  darr_t darr_mul_Rr(    darr_t* lhs, coeff_t rhs              );
  void   darr_mul_Rr_to( darr_t* lhs, coeff_t rhs, darr_t* res );
  void darr_mul_and_selfsum_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res);
  void darr_mul_and_selfsum_rR_to( coeff_t lhs, darr_t* rhs, darr_t* res);
  void darr_mul_and_selfsum_Rr_to( darr_t* lhs, coeff_t rhs, darr_t* res);
  darr_t darr_sub_RR(    darr_t* lhs, darr_t* rhs             );
  void   darr_sub_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res);
  darr_t darr_sub_Rr(darr_t* lhs, coeff_t rhs);
  darr_t darr_sub_rR(coeff_t lhs, darr_t* rhs);
  void darr_sub_Rr_to(darr_t* lhs, coeff_t rhs, darr_t* res);
  void darr_sub_rR_to(coeff_t lhs, darr_t* rhs, darr_t* res);
  darr_t darr_sum_RR(    darr_t* lhs, darr_t* rhs              );
  void   darr_sum_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res );
  darr_t darr_sum_rR(    coeff_t lhs, darr_t* rhs              );
  void   darr_sum_rR_to( coeff_t lhs, darr_t* rhs, darr_t* res );
  darr_t darr_sum_Rr(    darr_t* lhs, coeff_t rhs              );
  void   darr_sum_Rr_to( darr_t* lhs, coeff_t rhs, darr_t* res );
  coeff_t darr_dotproduct_RR(    darr_t* lhs, darr_t* rh              );
  void    darr_dotproduct_RR_to( darr_t* lhs, darr_t* rh, coeff_t* res);
  void darr_matmul_and_selfsum_RR_to(darr_t* lhs, darr_t* rhs, darr_t* res );
  darr_t darr_matmul(    darr_t* lhs, darr_t* rhs               );
  void   darr_matmul_to( darr_t* lhs, darr_t* rhs, darr_t* res );
  darr_t darr_matmul_RR(    darr_t* lhs, darr_t* rhs               );
  void   darr_matmul_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res );
  darr_t darr_transpose(    darr_t* arr             );
  void   darr_transpose_to( darr_t* arr, darr_t* res);
  darr_t darr_invert(    darr_t* arr             );
  void   darr_invert_to( darr_t* arr, darr_t* res);
  coeff_t darr_det( darr_t* arr );
  coeff_t darr_pnorm( darr_t* arr, coeff_t p );
  coeff_t darr_norm(  darr_t* arr );
  void darr_pnorm_to( darr_t* arr1, coeff_t p, coeff_t* res );
  void darr_norm_to( darr_t* arr1, coeff_t* res );
  void darr_self_neg(  darr_t* res);
  void darr_self_sum_R( darr_t* rhs, darr_t* res );
  void darr_self_sum_r( coeff_t rhs, darr_t* res );
  void darr_self_sub_R(darr_t* rhs, darr_t* res);
  void darr_self_sub_r(coeff_t rhs, darr_t* res);
  void darr_self_mul_R( darr_t* rhs, darr_t* res );
  void darr_self_mul_r( coeff_t rhs, darr_t* res );
  darr_t darr_gem_RR(   darr_t* arr1, darr_t* arr2, darr_t* arr3             );
  darr_t darr_gem_rR(   coeff_t arr1, darr_t* arr2, darr_t* arr3             );
  void   darr_gem_RR_to(darr_t* arr1, darr_t* arr2, darr_t* arr3, darr_t* res);
  void   darr_gem_rR_to(coeff_t arr1, darr_t* arr2, darr_t* arr3, darr_t* res);


  # From oti/real/array/functions.h

  darr_t darr_erf(darr_t* arr);
  void   darr_erf_to(darr_t* arr, darr_t* res);
  darr_t darr_atanh(darr_t* arr);
  void   darr_atanh_to(darr_t* arr, darr_t* res);
  darr_t darr_asinh(darr_t* arr);
  void   darr_asinh_to(darr_t* arr, darr_t* res);
  darr_t darr_acosh(darr_t* arr);
  void   darr_acosh_to(darr_t* arr, darr_t* res);
  darr_t darr_tanh(darr_t* arr);
  void   darr_tanh_to(darr_t* arr, darr_t* res);
  darr_t darr_cbrt(darr_t* arr);
  void darr_cbrt_to(darr_t* arr, darr_t* res);
  darr_t darr_sqrt(darr_t* arr);
  void   darr_sqrt_to(darr_t* arr, darr_t* res);
  darr_t darr_cosh(darr_t* arr);
  void   darr_cosh_to(darr_t* arr, darr_t* res);
  darr_t darr_sinh(darr_t* arr);
  void   darr_sinh_to(darr_t* arr, darr_t* res);
  darr_t darr_asin(darr_t* arr);
  void   darr_asin_to(darr_t* arr, darr_t* res);
  darr_t darr_acos(darr_t* arr);
  void   darr_acos_to(darr_t* arr, darr_t* res);
  darr_t darr_atan(darr_t* arr);
  void   darr_atan_to(darr_t* arr, darr_t* res);
  darr_t darr_tan(darr_t* arr);
  void   darr_tan_to(darr_t* arr, darr_t* res);
  darr_t darr_cos(darr_t* arr);
  void   darr_cos_to(darr_t* arr, darr_t* res);
  darr_t darr_sin(darr_t* arr );
  void   darr_sin_to(darr_t* arr, darr_t* res);
  darr_t darr_logb(darr_t* arr, double base);
  void   darr_logb_to(darr_t* arr, double base, darr_t* res);
  darr_t darr_log10(darr_t* arr);
  void   darr_log10_to(darr_t* arr, darr_t* res);
  darr_t darr_log(darr_t* arr);
  void   darr_log_to(darr_t* arr, darr_t* res);
  darr_t darr_exp(darr_t* arr);
  void   darr_exp_to(darr_t* arr, darr_t* res);
  darr_t darr_pow(darr_t* arr, double e);
  void   darr_pow_to(darr_t* arr, double e, darr_t* res);


  # From oti/real/array/base.h

  void darr_set_all(   coeff_t num, darr_t* arr);
  void darr_set_all_r( coeff_t num, darr_t* arr);
  coeff_t darr_get_item_i(  darr_t* arr, uint64_t i             );
  coeff_t darr_get_item_ij( darr_t* arr, uint64_t i, uint64_t j );
  void darr_get_item_ij_to( darr_t* arr, uint64_t i, uint64_t j, coeff_t* res );
  void darr_get_item_i_to(  darr_t* arr, uint64_t i,             coeff_t* res );
  darr_t darr_get_slice(    darr_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj  );
  void   darr_get_slice_to( darr_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            darr_t* res);
  void darr_set_item_i(    coeff_t num, uint64_t i,             darr_t* arr );
  void darr_set_item_i_r(  coeff_t num, uint64_t i,             darr_t* arr );
  void darr_set_item_ij(   coeff_t num, uint64_t i, uint64_t j, darr_t* arr );
  void darr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, darr_t* arr );
  darr_t darr_copy(    darr_t* arr              );
  void   darr_copy_to( darr_t* src, darr_t* dst );
  uint64_t darr_getSize(darr_t* arr);
  darr_t darr_ones( uint64_t nrows, uint64_t ncols);
  darr_t darr_zeros( uint64_t nrows, uint64_t ncols);
  darr_t darr_eye( uint64_t size);
  void darr_free(darr_t* arr);
  darr_t darr_createEmpty( uint64_t nrows, uint64_t ncols);
  darr_t darr_init();


  # From oti/real/array/gauss/utils.h

  void fedarr_dimCheck_FF_samesize( fedarr_t* arr1, fedarr_t* arr2, fednum_t* res);
  void fedarr_dimCheck_RF_samesize(   darr_t* arr1, fedarr_t* arr2, fednum_t* res);
  void fedarr_dimCheck_FF_elementwise( fedarr_t* arr1,  fedarr_t* arr2, fedarr_t* res);
  void fedarr_dimCheck_RF_elementwise(   darr_t* arr1,  fedarr_t* arr2, fedarr_t* res);
  void fedarr_dimCheck_fF_elementwise( fednum_t* num1,  fedarr_t* arr2, fedarr_t* res);
  void fedarr_dimCheck_Ff_elementwise( fedarr_t* arr1,  fednum_t* num2, fedarr_t* res);
  void fedarr_dimCheck_FF_matmul( fedarr_t* lhs, fedarr_t* rhs, fedarr_t* res);
  void fedarr_dimCheck_RF_matmul(   darr_t* lhs, fedarr_t* rhs, fedarr_t* res);
  void fedarr_dimCheck_FR_matmul( fedarr_t* lhs,   darr_t* rhs, fedarr_t* res);
  void fedarr_dimCheck_F_squareness( fedarr_t* arr1, fedarr_t* res);
  void fedarr_dimCheck_F_transpose( fedarr_t* arr1, fedarr_t* res);
  void fedarr_dimCheck_FfR_integrate(fedarr_t* arr, fednum_t* num,darr_t* res);


  # From oti/real/array/gauss/algebra.h

  fedarr_t  fedarr_neg(    fedarr_t * arr                );
  void      fedarr_neg_to( fedarr_t * arr, fedarr_t * res);
  fedarr_t  fedarr_sum_FF(   fedarr_t * lhs, fedarr_t * rhs                );
  void      fedarr_sum_FF_to(fedarr_t * lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_sum_fF(    fednum_t* lhs, fedarr_t * rhs                );
  void      fedarr_sum_fF_to( fednum_t* lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_sum_RF(      darr_t* lhs, fedarr_t * rhs                );
  void      fedarr_sum_RF_to(   darr_t* lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_sum_rF(     coeff_t  lhs, fedarr_t * rhs                );
  void      fedarr_sum_rF_to(  coeff_t  lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_sub_FF(    fedarr_t * lhs, fedarr_t * rhs                );
  void      fedarr_sub_FF_to( fedarr_t * lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_sub_fF(    fednum_t* lhs, fedarr_t * rhs                 );
  void      fedarr_sub_fF_to( fednum_t* lhs, fedarr_t * rhs, fedarr_t * res );
  fedarr_t  fedarr_sub_Ff(    fedarr_t * lhs, fednum_t* rhs                 );
  void      fedarr_sub_Ff_to( fedarr_t * lhs, fednum_t* rhs, fedarr_t * res );
  fedarr_t  fedarr_sub_RF(       darr_t* lhs, fedarr_t * rhs                );
  void      fedarr_sub_RF_to(    darr_t* lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_sub_FR(    fedarr_t * lhs,    darr_t* rhs                );
  void      fedarr_sub_FR_to( fedarr_t * lhs,    darr_t* rhs, fedarr_t * res);
  fedarr_t  fedarr_sub_rF(      coeff_t  lhs, fedarr_t * rhs                );
  void      fedarr_sub_rF_to(    coeff_t lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_sub_Fr(    fedarr_t * lhs,   coeff_t  rhs                );
  void      fedarr_sub_Fr_to( fedarr_t * lhs,   coeff_t  rhs, fedarr_t * res);
  fedarr_t  fedarr_mul_FF(   fedarr_t * lhs, fedarr_t * rhs                );
  void      fedarr_mul_FF_to(fedarr_t * lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_mul_fF(    fednum_t* lhs, fedarr_t * rhs                );
  void      fedarr_mul_fF_to( fednum_t* lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_mul_RF(      darr_t* lhs, fedarr_t * rhs                );
  void      fedarr_mul_RF_to(   darr_t* lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_mul_rF(     coeff_t  lhs, fedarr_t * rhs                );
  void      fedarr_mul_rF_to(  coeff_t  lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_div_FF(    fedarr_t * lhs, fedarr_t * rhs                );
  void      fedarr_div_FF_to( fedarr_t * lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_div_fF(     fednum_t* lhs, fedarr_t * rhs                );
  void      fedarr_div_fF_to(  fednum_t* lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_div_Ff(    fedarr_t* lhs,  fednum_t* rhs                );
  void      fedarr_div_Ff_to( fedarr_t* lhs,  fednum_t* rhs, fedarr_t * res);
  fedarr_t  fedarr_div_RF(       darr_t* lhs, fedarr_t * rhs                );
  void      fedarr_div_RF_to(    darr_t* lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_div_FR(    fedarr_t* lhs,    darr_t* rhs                );
  void      fedarr_div_FR_to( fedarr_t* lhs,    darr_t* rhs, fedarr_t * res);
  fedarr_t  fedarr_div_rF(      coeff_t  lhs, fedarr_t * rhs                );
  void      fedarr_div_rF_to(    coeff_t lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_div_Fr(    fedarr_t* lhs,   coeff_t  rhs                );
  void      fedarr_div_Fr_to( fedarr_t* lhs,   coeff_t  rhs, fedarr_t * res);
  darr_t fedarr_integrate(    fedarr_t* arr, fednum_t* w              );
  void    fedarr_integrate_to( fedarr_t* arr, fednum_t* w, darr_t* res);
  fednum_t fedarr_dotproduct_FF(    fedarr_t* lhs, fedarr_t * rhs               );
  void     fedarr_dotproduct_FF_to( fedarr_t* lhs, fedarr_t * rhs, fednum_t* res);
  fednum_t fedarr_dotproduct_RF(       darr_t* lhs, fedarr_t * rhs               );
  void     fedarr_dotproduct_RF_to(    darr_t* lhs, fedarr_t * rhs, fednum_t* res);
  fedarr_t  fedarr_matmul_FF(    fedarr_t* lhs, fedarr_t * rhs                );
  void      fedarr_matmul_FF_to( fedarr_t* lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_matmul_RF(    darr_t*    lhs, fedarr_t * rhs                );
  void      fedarr_matmul_RF_to( darr_t*    lhs, fedarr_t * rhs, fedarr_t * res);
  fedarr_t  fedarr_matmul_FR(    fedarr_t* lhs, darr_t*    rhs                );
  void      fedarr_matmul_FR_to( fedarr_t* lhs, darr_t*    rhs, fedarr_t * res);
  fednum_t fedarr_det(   fedarr_t* arr               );
  void     fedarr_det_to(fedarr_t* arr, fednum_t* res);
  fednum_t fedarr_norm(     fedarr_t* arr               );
  void     fedarr_norm_to(  fedarr_t* arr, fednum_t* res);
  fednum_t fedarr_pnorm(    fedarr_t* arr, coeff_t p               );
  void     fedarr_pnorm_to( fedarr_t* arr, coeff_t p, fednum_t* res);
  fedarr_t    fedarr_invert(    fedarr_t* arr                );
  void        fedarr_invert_to( fedarr_t* arr, fedarr_t * res);
  fedarr_t    fedarr_transpose(   fedarr_t* arr                );
  void        fedarr_transpose_to(fedarr_t* arr, fedarr_t * res);


  # From oti/real/array/gauss/functions.h

  fedarr_t  fedarr_erf(    fedarr_t* arr               );
  void      fedarr_erf_to( fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_atanh(    fedarr_t* arr               );
  void      fedarr_atanh_to( fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_asinh(    fedarr_t* arr               );
  void      fedarr_asinh_to( fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_acosh(    fedarr_t* arr               );
  void      fedarr_acosh_to( fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_tanh(     fedarr_t* arr               );
  void      fedarr_tanh_to(  fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_sinh(     fedarr_t* arr               );
  void      fedarr_sinh_to(  fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_cosh(     fedarr_t* arr               );
  void      fedarr_cosh_to(  fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_atan(     fedarr_t* arr               );
  void      fedarr_atan_to(  fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_asin(     fedarr_t* arr               );
  void      fedarr_asin_to(  fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_acos(     fedarr_t* arr               );
  void      fedarr_acos_to(  fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_tan(      fedarr_t* arr               );
  void      fedarr_tan_to(   fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_sin(      fedarr_t* arr               );
  void      fedarr_sin_to(   fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_cos(      fedarr_t* arr               );
  void      fedarr_cos_to(   fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_logb(     fedarr_t* arr, double base               );
  void      fedarr_logb_to(  fedarr_t* arr, double base, fedarr_t* res);
  fedarr_t  fedarr_log10(    fedarr_t* arr               );
  void      fedarr_log10_to( fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_log(      fedarr_t* arr               );
  void      fedarr_log_to(   fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_exp(      fedarr_t* arr               );
  void      fedarr_exp_to(   fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_cbrt(     fedarr_t* arr               );
  void      fedarr_cbrt_to(  fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_sqrt(     fedarr_t* arr               );
  void      fedarr_sqrt_to(  fedarr_t* arr, fedarr_t* res);
  fedarr_t  fedarr_pow(      fedarr_t* arr, double e               );
  void      fedarr_pow_to(   fedarr_t* arr, double e, fedarr_t* res);


  # From oti/real/array/gauss/base.h

  fedarr_t fedarr_copy(   fedarr_t* src               );
  void     fedarr_copy_to(fedarr_t* src, fedarr_t* res);
  darr_t   fedarr_get_item_k(  fedarr_t* arr, uint64_t k                         );
  fednum_t fedarr_get_item_ij( fedarr_t* arr, uint64_t i, uint64_t j             );
  coeff_t  fedarr_get_item_ijk(fedarr_t* arr, uint64_t i, uint64_t j, uint64_t k );
  void fedarr_get_item_ij_to(  fedarr_t* arr, uint64_t i, uint64_t j, fednum_t* res);
  void fedarr_get_item_k_to(   fedarr_t* arr, uint64_t k, darr_t* res);
  void fedarr_get_item_ijk_to( fedarr_t* arr, uint64_t i, uint64_t j, uint64_t k, coeff_t* res);
  fedarr_t fedarr_get_slice(fedarr_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj );
  void     fedarr_get_slice_to(fedarr_t* arr,
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj,
                            fedarr_t* res);
  void fedarr_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j, fedarr_t* res);
  void fedarr_set_item_ij_f(  fednum_t* elm, uint64_t i, uint64_t j, fedarr_t* res);
  void fedarr_set_item_k_r(    coeff_t  elm, uint64_t k, fedarr_t* res);
  void fedarr_set_item_k_R(     darr_t* elm, uint64_t k, fedarr_t* res);
  void fedarr_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k, fedarr_t* res);
  void fedarr_set_slice_r( coeff_t val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            fedarr_t* res);
  void fedarr_set_slice_f( fednum_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            fedarr_t* res);
  void fedarr_set_slice_R( darr_t* val, 
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            fedarr_t* res);
  void fedarr_set_slice_F( fedarr_t* val,
                           int64_t starti, int64_t stopi, int64_t stepi,
                           int64_t startj, int64_t stopj, int64_t stepj,
                            fedarr_t* res);
  void fedarr_set_all_r(   coeff_t  num, fedarr_t* arr );
  void fedarr_set_all_f(  fednum_t* num, fedarr_t* arr );
  void fedarr_set_r(    coeff_t src, fedarr_t* res );
  void fedarr_set_f(  fednum_t* src, fedarr_t* res );
  void fedarr_set_R(    darr_t* src, fedarr_t* res );
  void fedarr_set_F(  fedarr_t* src, fedarr_t* res );
  fedarr_t fedarr_eye( uint64_t size, uint64_t nip );
  fedarr_t fedarr_zeros( uint64_t nrows, uint64_t ncols, uint64_t nIntPts );
  fedarr_t fedarr_ones( uint64_t nrows, uint64_t ncols, uint64_t nip );
  fedarr_t fedarr_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t nIntPts );
  void fedarr_free(fedarr_t* arr);
  fedarr_t fedarr_init();


  # From oti/real/scalar/gauss/utils.h

  void fednum_dimCheck(fednum_t* num1,fednum_t* num2);


  # From oti/real/scalar/gauss/algebra.h

  fednum_t fednum_neg(   fednum_t* num               );
  void     fednum_neg_to(fednum_t* num, fednum_t* res);
  fednum_t fednum_sum_ff(   fednum_t* lhs, fednum_t* rhs               );
  void     fednum_sum_ff_to(fednum_t* lhs, fednum_t* rhs, fednum_t* res);
  fednum_t fednum_sum_rf(     coeff_t lhs, fednum_t* rhs               );
  void     fednum_sum_rf_to(  coeff_t lhs, fednum_t* rhs, fednum_t* res);
  fednum_t fednum_sub_ff(     fednum_t* lhs,  fednum_t* rhs               );
  void     fednum_sub_ff_to(  fednum_t* lhs,  fednum_t* rhs, fednum_t* res);
  fednum_t fednum_sub_rf(       coeff_t lhs,  fednum_t* rhs               );
  void     fednum_sub_rf_to(    coeff_t lhs,  fednum_t* rhs, fednum_t* res);
  fednum_t fednum_sub_fr(     fednum_t* lhs,    coeff_t rhs               );
  void     fednum_sub_fr_to(  fednum_t* lhs,    coeff_t rhs, fednum_t* res);
  fednum_t fednum_mul_ff(   fednum_t* lhs, fednum_t* rhs               );
  void     fednum_mul_ff_to(fednum_t* lhs, fednum_t* rhs, fednum_t* res);
  fednum_t fednum_mul_rf(     coeff_t lhs, fednum_t* rhs               );
  void     fednum_mul_rf_to(  coeff_t lhs, fednum_t* rhs, fednum_t* res);
  fednum_t fednum_div_ff(     fednum_t* lhs,  fednum_t* rhs               );
  void     fednum_div_ff_to(  fednum_t* lhs,  fednum_t* rhs, fednum_t* res);
  fednum_t fednum_div_rf(       coeff_t lhs,  fednum_t* rhs               );
  void     fednum_div_rf_to(    coeff_t lhs,  fednum_t* rhs, fednum_t* res);
  fednum_t fednum_div_fr(     fednum_t* lhs,    coeff_t rhs               );
  void     fednum_div_fr_to(  fednum_t* lhs,    coeff_t rhs, fednum_t* res);


  # From oti/real/scalar/gauss/functions.h

  fednum_t fednum_erf(    fednum_t* num                );
  void     fednum_erf_to( fednum_t* num, fednum_t* res );
  fednum_t fednum_atanh(    fednum_t* num                );
  void     fednum_atanh_to( fednum_t* num, fednum_t* res );
  fednum_t fednum_asinh(    fednum_t* num                );
  void     fednum_asinh_to( fednum_t* num, fednum_t* res );
  fednum_t fednum_acosh(    fednum_t* num                );
  void     fednum_acosh_to( fednum_t* num, fednum_t* res );
  fednum_t fednum_tanh(     fednum_t* num                );
  void     fednum_tanh_to(  fednum_t* num, fednum_t* res );
  fednum_t fednum_cosh(     fednum_t* num                );
  void     fednum_cosh_to(  fednum_t* num, fednum_t* res );
  fednum_t fednum_sinh(     fednum_t* num                );
  void     fednum_sinh_to(  fednum_t* num, fednum_t* res );
  fednum_t fednum_asin(     fednum_t* num                );
  void     fednum_asin_to(  fednum_t* num, fednum_t* res );
  fednum_t fednum_acos(     fednum_t* num                );
  void     fednum_acos_to(  fednum_t* num, fednum_t* res );
  fednum_t fednum_atan(     fednum_t* num                );
  void     fednum_atan_to(  fednum_t* num, fednum_t* res );
  fednum_t fednum_tan(      fednum_t* num                );
  void     fednum_tan_to(   fednum_t* num, fednum_t* res );
  fednum_t fednum_cos(      fednum_t* num                );
  void     fednum_cos_to(   fednum_t* num, fednum_t* res );
  fednum_t fednum_sin(      fednum_t* num                );
  void     fednum_sin_to(   fednum_t* num, fednum_t* res );
  fednum_t fednum_logb(     fednum_t* num, double base                );
  void     fednum_logb_to(  fednum_t* num, double base, fednum_t* res );
  fednum_t fednum_log10(    fednum_t* num                             );
  void     fednum_log10_to( fednum_t* num, fednum_t* res              );
  fednum_t fednum_log(      fednum_t* num                             );
  void     fednum_log_to(   fednum_t* num, fednum_t* res              );
  fednum_t fednum_exp(      fednum_t* num                             );
  void     fednum_exp_to(   fednum_t* num, fednum_t* res              );
  fednum_t fednum_cbrt(     fednum_t* num                          );
  void     fednum_cbrt_to(  fednum_t* num, fednum_t* res           );
  fednum_t fednum_sqrt(     fednum_t* num                          );
  void     fednum_sqrt_to(  fednum_t* num, fednum_t* res           );
  fednum_t fednum_pow(      fednum_t* num, double e                );
  void     fednum_pow_to(   fednum_t* num, double e, fednum_t* res );
  coeff_t   fednum_integrate(       fednum_t* num, fednum_t* w                 );
  void      fednum_integrate_to(    fednum_t* num, fednum_t* w, coeff_t  * res );
  coeff_t   fednum_integrate_f(     fednum_t* num, fednum_t* w                 );
  void      fednum_integrate_f_to(  fednum_t* num, fednum_t* w, coeff_t  * res );
  coeff_t   fednum_integrate_r(       coeff_t num, fednum_t* w                 );
  void      fednum_integrate_r_to(    coeff_t num, fednum_t* w, coeff_t  * res );


  # From oti/real/scalar/gauss/base.h

  fednum_t fednum_copy(    fednum_t* src               );
  void     fednum_copy_to( fednum_t* src, fednum_t* dst);
  void fednum_set_r(    coeff_t num, fednum_t* res);
  void fednum_set_f(  fednum_t* num, fednum_t* res);
  void fednum_set_item_k_r(   coeff_t  num, uint64_t k, fednum_t* res);
  coeff_t fednum_get_item_k(   fednum_t* num, uint64_t k              );
  void    fednum_get_item_k_to(fednum_t* num, uint64_t k, coeff_t* res);
  fednum_t fednum_zeros(uint64_t nIntPts);
  fednum_t fednum_createEmpty(uint64_t nIntPts);
  fednum_t fednum_empty_like(fednum_t* arr);
  void fednum_free(fednum_t* num);
  fednum_t fednum_init();


































  # # Defs from "real.h"
  # ctypedef struct darr_t:
  #   coeff_t*       p_data
  #   uint64_t        nrows
  #   uint64_t        ncols
  #   uint64_t         size

  # # Include functions from "real.h"
  # #---------------------------------------------------------------------------------------------------

  # darr_t darr_atanh(   darr_t* arr             );
  # void   darr_atanh_to(darr_t* arr, darr_t* res);
  # darr_t darr_asinh(   darr_t* arr             );
  # void   darr_asinh_to(darr_t* arr, darr_t* res);
  # darr_t darr_acosh(   darr_t* arr             );
  # void   darr_acosh_to(darr_t* arr, darr_t* res);
  # darr_t darr_tanh(    darr_t* arr             );
  # void   darr_tanh_to( darr_t* arr, darr_t* res);
  # darr_t darr_cbrt(    darr_t* arr             );
  # void   darr_cbrt_to( darr_t* arr, darr_t* res);
  # darr_t darr_sqrt(    darr_t* arr             );
  # void   darr_sqrt_to( darr_t* arr, darr_t* res);
  # darr_t darr_cosh(    darr_t* arr             );
  # void   darr_cosh_to( darr_t* arr, darr_t* res);
  # darr_t darr_sinh(    darr_t* arr             );
  # void   darr_sinh_to( darr_t* arr, darr_t* res);
  # darr_t darr_asin(    darr_t* arr             );
  # void   darr_asin_to( darr_t* arr, darr_t* res);
  # darr_t darr_acos(    darr_t* arr             );
  # void   darr_acos_to( darr_t* arr, darr_t* res);
  # darr_t darr_atan(    darr_t* arr             );
  # void   darr_atan_to( darr_t* arr, darr_t* res);
  # darr_t darr_tan(     darr_t* arr             );
  # void   darr_tan_to(  darr_t* arr, darr_t* res);
  # darr_t darr_cos(     darr_t* arr             );
  # void   darr_cos_to(  darr_t* arr, darr_t* res);
  # darr_t darr_sin(     darr_t* arr             );
  # void   darr_sin_to(  darr_t* arr, darr_t* res);
  # darr_t darr_logb(    darr_t* arr, double base             );
  # void   darr_logb_to( darr_t* arr, double base, darr_t* res);
  # darr_t darr_log10(   darr_t* arr             );
  # void   darr_log10_to(darr_t* arr, darr_t* res);
  # darr_t darr_log(     darr_t* arr             );
  # void   darr_log_to(  darr_t* arr, darr_t* res);
  # darr_t darr_exp(     darr_t* arr             );
  # void   darr_exp_to(  darr_t* arr, darr_t* res);
  # darr_t darr_pow(     darr_t* arr, double e             );
  # void   darr_pow_to(  darr_t* arr, double e, darr_t* res);

  # void der_r_atan2(coeff_t x, coeff_t y, ord_t order, coeff_t* derivs);
  # void der_r_logb(coeff_t x, coeff_t base, ord_t order, coeff_t* derivs);
  # void der_r_log10(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_atanh(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_asinh(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_acosh(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_tanh(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_sqrt(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_cosh(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_sinh(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_asin(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_acos(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_atan(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_tan(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_cos(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_sin(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_log(coeff_t x , ord_t order, coeff_t* derivs);
  # void der_r_exp(coeff_t x, ord_t order, coeff_t* derivs);
  # void der_r_pow(coeff_t x, coeff_t e, ord_t order, coeff_t* derivs);
  
  # darr_t darr_matmul(darr_t* arr1, darr_t* arr2 );
  # void darr_matmul_to(darr_t* arr1, darr_t* arr2, darr_t* aRes );

  # darr_t darr_transpose(darr_t* arr1);
  # void darr_transpose_to(darr_t* arr1, darr_t* aRes);

  # darr_t darr_invert(darr_t* arr1);
  # void darr_invert_to(darr_t* arr1, darr_t* aRes);

  # coeff_t darr_det( darr_t* arr1 );

  # coeff_t darr_pnorm( darr_t* arr, coeff_t p );
  # coeff_t darr_norm(  darr_t* arr );

  # void darr_neg_to(darr_t* arr1, darr_t* aRes);
  # darr_t darr_neg(darr_t* arr1);
  # darr_t darr_div_RR(darr_t* arr1, darr_t* arr2);
  # darr_t darr_div_Rr(darr_t* arr1, coeff_t num);
  # darr_t darr_div_rR(coeff_t num, darr_t* arr1);
  # void darr_div_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
  # void darr_div_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes);
  # void darr_div_rR_to(coeff_t num, darr_t* arr2, darr_t* aRes);
  # darr_t darr_mul_RR(    darr_t* lhs, darr_t* rhs              );
  # void   darr_mul_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res );
  # darr_t darr_mul_rR(    coeff_t lhs, darr_t* rhs              );
  # void   darr_mul_rR_to( coeff_t lhs, darr_t* rhs, darr_t* res );
  # darr_t darr_mul_Rr(    darr_t* lhs, coeff_t rhs              );
  # void   darr_mul_Rr_to( darr_t* lhs, coeff_t rhs, darr_t* res );
  # darr_t darr_sub_RR(darr_t* arr1, darr_t* arr2);
  # darr_t darr_sub_Rr(darr_t* arr1, coeff_t num);
  # darr_t darr_sub_rR(coeff_t num, darr_t* arr1);
  # void darr_sub_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
  # void darr_sub_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes);
  # void darr_sub_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes);
  # darr_t darr_sum_RR(    darr_t* lhs, darr_t* rhs              );
  # void   darr_sum_RR_to( darr_t* lhs, darr_t* rhs, darr_t* res );
  # darr_t darr_sum_rR(    coeff_t lhs, darr_t* rhs              );
  # void   darr_sum_rR_to( coeff_t lhs, darr_t* rhs, darr_t* res );
  # darr_t darr_sum_Rr(    darr_t* lhs, coeff_t rhs              );
  # void   darr_sum_Rr_to( darr_t* lhs, coeff_t rhs, darr_t* res );
  # void darr_set_all( coeff_t num, darr_t* arr);
  # coeff_t darr_get_item_ij(darr_t* arr, uint64_t i, uint64_t j);
  # coeff_t darr_get_item_i(darr_t* arr, uint64_t i);
  # void darr_set_item_ij( coeff_t num, uint64_t i, uint64_t j, darr_t* arr);
  # void darr_set_item_i( coeff_t num, uint64_t i, darr_t* arr);
  # darr_t   darr_copy(darr_t* src );
  # void     darr_copy_to(darr_t* src, darr_t* dst );
  # uint64_t darr_getSize(darr_t* arr);
  # darr_t darr_ones( uint64_t nrows, uint64_t ncols);
  # darr_t darr_zeros( uint64_t nrows, uint64_t ncols);
  # void darr_free(darr_t* arr);
  # darr_t darr_createEmpty( uint64_t nrows, uint64_t ncols);
  # #---------------------------------------------------------------------------------------------------