
cdef extern from "oti/oti.h" nogil:

  # Defs from "fem.h"
  ctypedef struct elem_t:
    uint64_t      nbasis
    uint64_t       order
    int64_t     geomBase
    int64_t         kind
    uint8_t         ndim
    uint64_t     nIntPts
    uint8_t         nder
    uint8_t       isInit
    uint8_t nDimAnalysis
    darr_t        intPts
    darr_t        intWts
    darr_t*  p_evalBasis
    # int64_t (*f_basis)(int64_t,int64_t,darr_t*,void*,darr_t*) nogil

  ctypedef struct fesoti_t:
    sotinum_t*  p_data    # Data array
    uint64_t    nip       # Number of integration points.

  ctypedef struct fearrso_t:
    arrso_t*      p_data # < Data array
    uint64_t      nrows  # < Number of rows.
    uint64_t      ncols  # < Number of cols.
    uint64_t       size  # < size of the array
    uint64_t        nip  # < Number of integration points.
  
  # Include functions from "fem.h"
  #---------------------------------------------------------------------------------------------------


  # Gauss: Array:
  fearrso_t fearrso_neg(    fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_neg_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sum_FF(   fearrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sum_FF_to(fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sum_fF(    fesoti_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sum_fF_to( fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sum_OF(     arrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sum_OF_to(  arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sum_RF(      darr_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sum_RF_to(   darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sum_oF(   sotinum_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sum_oF_to(sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sum_rF(     coeff_t  lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sum_rF_to(  coeff_t  lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sub_FF(    fearrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sub_FF_to( fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sub_fF(    fesoti_t* lhs, fearrso_t* rhs,                  dhelpl_t dhl);
  void      fearrso_sub_fF_to( fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res,  dhelpl_t dhl);
  fearrso_t fearrso_sub_Ff(    fearrso_t* lhs, fesoti_t* rhs,                  dhelpl_t dhl);
  void      fearrso_sub_Ff_to( fearrso_t* lhs, fesoti_t* rhs, fearrso_t* res,  dhelpl_t dhl);
  fearrso_t fearrso_sub_OF(      arrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sub_OF_to(   arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sub_FO(    fearrso_t* lhs,   arrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sub_FO_to( fearrso_t* lhs,   arrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sub_RF(       darr_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sub_RF_to(    darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sub_FR(    fearrso_t* lhs,    darr_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sub_FR_to( fearrso_t* lhs,    darr_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sub_oF(    sotinum_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sub_oF_to( sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sub_Fo(    fearrso_t* lhs, sotinum_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sub_Fo_to( fearrso_t* lhs, sotinum_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sub_rF(      coeff_t  lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_sub_rF_to(    coeff_t lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sub_Fr(    fearrso_t* lhs,   coeff_t  rhs,                 dhelpl_t dhl);
  void      fearrso_sub_Fr_to( fearrso_t* lhs,   coeff_t  rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_mul_FF(   fearrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_mul_FF_to(fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_mul_fF(    fesoti_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_mul_fF_to( fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_mul_OF(     arrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_mul_OF_to(  arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_mul_RF(      darr_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_mul_RF_to(   darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_mul_oF(   sotinum_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_mul_oF_to(sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_mul_rF(     coeff_t  lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_mul_rF_to(  coeff_t  lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_div_FF(    fearrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_div_FF_to( fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_div_fF(     fesoti_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_div_fF_to(  fesoti_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_div_Ff(    fearrso_t* lhs,  fesoti_t* rhs,                 dhelpl_t dhl);
  void      fearrso_div_Ff_to( fearrso_t* lhs,  fesoti_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_div_OF(      arrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_div_OF_to(   arrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_div_FO(    fearrso_t* lhs,   arrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_div_FO_to( fearrso_t* lhs,   arrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_div_RF(       darr_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_div_RF_to(    darr_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_div_FR(    fearrso_t* lhs,    darr_t* rhs,                 dhelpl_t dhl);
  void      fearrso_div_FR_to( fearrso_t* lhs,    darr_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_div_oF(    sotinum_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_div_oF_to( sotinum_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_div_Fo(    fearrso_t* lhs, sotinum_t* rhs,                 dhelpl_t dhl);
  void      fearrso_div_Fo_to( fearrso_t* lhs, sotinum_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_div_rF(      coeff_t  lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_div_rF_to(    coeff_t lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_div_Fr(    fearrso_t* lhs,   coeff_t  rhs,                 dhelpl_t dhl);
  void      fearrso_div_Fr_to( fearrso_t* lhs,   coeff_t  rhs, fearrso_t* res, dhelpl_t dhl);
  arrso_t   fearrso_integrate(    fearrso_t* arr, fesoti_t* w,               dhelpl_t dhl);
  void      fearrso_integrate_to( fearrso_t* arr, fesoti_t* w, arrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_matmul_FF(    fearrso_t* lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_matmul_FF_to( fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_matmul_OF(    arrso_t*   lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_matmul_OF_to( arrso_t*   lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_matmul_FO(    fearrso_t* lhs, arrso_t*   rhs,                 dhelpl_t dhl);
  void      fearrso_matmul_FO_to( fearrso_t* lhs, arrso_t*   rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_matmul_RF(    darr_t*    lhs, fearrso_t* rhs,                 dhelpl_t dhl);
  void      fearrso_matmul_RF_to( darr_t*    lhs, fearrso_t* rhs, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_matmul_FR(    fearrso_t* lhs, darr_t*    rhs,                 dhelpl_t dhl);
  void      fearrso_matmul_FR_to( fearrso_t* lhs, darr_t*    rhs, fearrso_t* res, dhelpl_t dhl);
  fesoti_t fearrso_det(   fearrso_t* arr,                dhelpl_t dhl);
  void     fearrso_det_to(fearrso_t* arr, fesoti_t* res, dhelpl_t dhl);
  fearrso_t   fearrso_invert(    fearrso_t* arr,                 dhelpl_t dhl);
  void        fearrso_invert_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t   fearrso_transpose(   fearrso_t* arr,                 dhelpl_t dhl);
  void        fearrso_transpose_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  
  void fearrso_dimCheck_FF_elementwise(fearrso_t* arr1, fearrso_t* arr2, fearrso_t* res);
  void fearrso_dimCheck_OF_elementwise(  arrso_t* arr1, fearrso_t* arr2, fearrso_t* res);
  void fearrso_dimCheck_RF_elementwise(   darr_t* arr1, fearrso_t* arr2, fearrso_t* res);
  void fearrso_dimCheck_fF_elementwise( fesoti_t* num1, fearrso_t* arr2, fearrso_t* res);
  void fearrso_dimCheck_Ff_elementwise(fearrso_t* arr1,  fesoti_t* num2, fearrso_t* res);
  void fearrso_dimCheck_FF_matmul( fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res);
  void fearrso_dimCheck_OF_matmul(   arrso_t* lhs, fearrso_t* rhs, fearrso_t* res);
  void fearrso_dimCheck_RF_matmul(    darr_t* lhs, fearrso_t* rhs, fearrso_t* res);
  void fearrso_dimCheck_FO_matmul( fearrso_t* lhs,   arrso_t* rhs, fearrso_t* res);
  void fearrso_dimCheck_FR_matmul( fearrso_t* lhs,    darr_t* rhs, fearrso_t* res);
  void fearrso_dimCheck_F_squareness( fearrso_t* arr1, fearrso_t* res);
  void fearrso_dimCheck_F_transpose( fearrso_t* arr1, fearrso_t* res);
  void fearrso_dimCheck_FfO_integrate(fearrso_t* arr, fesoti_t* num,arrso_t* res);

  fearrso_t fearrso_copy(   fearrso_t* src,                 dhelpl_t dhl);
  void      fearrso_copy_to(fearrso_t* src, fearrso_t* res, dhelpl_t dhl);
  arrso_t   fearrso_get_item_k(  fearrso_t* arr, uint64_t k,                         dhelpl_t dhl);
  sotinum_t fearrso_get_item_ijk(fearrso_t* arr, uint64_t i, uint64_t j, uint64_t k, dhelpl_t dhl);
  void fearrso_get_item_ij_to(  fearrso_t* arr, uint64_t i, uint64_t j, 
                                fearrso_t* res, dhelpl_t dhl);

  void fearrso_get_item_k_to(   fearrso_t* arr, uint64_t k, 
                                  arrso_t* res, dhelpl_t dhl);

  void fearrso_get_item_ijk_to( fearrso_t* arr, uint64_t i, uint64_t j, uint64_t k, 
                                sotinum_t* res, dhelpl_t dhl);
  void fearrso_set_item_ij( fesoti_t* elm, uint64_t i, uint64_t j,
                            fearrso_t* res, dhelpl_t dhl);

  void fearrso_set_item_k(    arrso_t* elm, 
                            uint64_t k, 
                            fearrso_t* res, dhelpl_t dhl);

  void fearrso_set_item_ijk(sotinum_t* elm, uint64_t i, uint64_t j, 
                            uint64_t k, 
                            fearrso_t* res, dhelpl_t dhl);
  void fearrso_set_all_o( sotinum_t* num, fearrso_t* arr, dhelpl_t dhl );
  void fearrso_set_all_r(    coeff_t num, fearrso_t* arr, dhelpl_t dhl );
  fearrso_t fearrso_zeros_bases( uint64_t nrows,   uint64_t ncols, 
                                 uint64_t nIntPts, bases_t  nbases, 
                                 ord_t    order,   dhelpl_t dhl     );
  fearrso_t fearrso_createEmpty_bases( uint64_t nrows,   uint64_t ncols,  
                                       uint64_t nIntPts, bases_t  nbases, 
                                       ord_t    order,   dhelpl_t dhl);
  void fearrso_free(fearrso_t* arr);
  ord_t fearrso_get_order(fearrso_t* arr);  
  fearrso_t fearrso_init();








  
  # Gauss :: Scalar
  fesoti_t fesoti_atanh(    fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_atanh_to( fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_asinh(    fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_asinh_to( fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_acosh(    fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_acosh_to( fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_tanh(     fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_tanh_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_cosh(     fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_cosh_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_sinh(     fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_sinh_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_asin(     fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_asin_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_acos(     fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_acos_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_atan(     fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_atan_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_tan(      fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_tan_to(   fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_cos(      fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_cos_to(   fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_sin(      fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_sin_to(   fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_logb(     fesoti_t* num, double base,                dhelpl_t dhl);
  void     fesoti_logb_to(  fesoti_t* num, double base, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_log10(    fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_log10_to( fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_log(      fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_log_to(   fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_exp(      fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_exp_to(   fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_cbrt(     fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_cbrt_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_sqrt(     fesoti_t* num,                             dhelpl_t dhl);
  void     fesoti_sqrt_to(  fesoti_t* num, fesoti_t* res,              dhelpl_t dhl);
  fesoti_t fesoti_pow(      fesoti_t* num, double e,                   dhelpl_t dhl);
  void     fesoti_pow_to(   fesoti_t* num, double e, fesoti_t* res,    dhelpl_t dhl);

  sotinum_t fesoti_integrate(    fesoti_t* num, fesoti_t* w,                 dhelpl_t dhl);
  void      fesoti_integrate_to( fesoti_t* num, fesoti_t* w, sotinum_t* res, dhelpl_t dhl);
  fesoti_t fesoti_neg(   fesoti_t* num,                dhelpl_t dhl);
  void     fesoti_neg_to(fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_sum_ff(   fesoti_t* lhs, fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_sum_ff_to(fesoti_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_sum_of(   sotinum_t* lhs, fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_sum_of_to(sotinum_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_sum_rf(   coeff_t lhs, fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_sum_rf_to(coeff_t lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_sub_ff(     fesoti_t* lhs,  fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_sub_ff_to(  fesoti_t* lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_sub_of(    sotinum_t* lhs,  fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_sub_of_to( sotinum_t* lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_sub_fo(     fesoti_t* lhs, sotinum_t* rhs,                dhelpl_t dhl);
  void     fesoti_sub_fo_to(  fesoti_t* lhs, sotinum_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_sub_rf(       coeff_t lhs,  fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_sub_rf_to(    coeff_t lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_sub_fr(     fesoti_t* lhs,    coeff_t rhs,                dhelpl_t dhl);
  void     fesoti_sub_fr_to(  fesoti_t* lhs,    coeff_t rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_mul_ff(   fesoti_t* lhs, fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_mul_ff_to(fesoti_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_mul_of(   sotinum_t* lhs, fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_mul_of_to(sotinum_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_mul_rf(   coeff_t lhs, fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_mul_rf_to(coeff_t lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_div_ff(     fesoti_t* lhs,  fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_div_ff_to(  fesoti_t* lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_div_of(    sotinum_t* lhs,  fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_div_of_to( sotinum_t* lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_div_fo(     fesoti_t* lhs, sotinum_t* rhs,                dhelpl_t dhl);
  void     fesoti_div_fo_to(  fesoti_t* lhs, sotinum_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_div_rf(       coeff_t lhs,  fesoti_t* rhs,                dhelpl_t dhl);
  void     fesoti_div_rf_to(    coeff_t lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_div_fr(     fesoti_t* lhs,    coeff_t rhs,                dhelpl_t dhl);
  void     fesoti_div_fr_to(  fesoti_t* lhs,    coeff_t rhs, fesoti_t* res, dhelpl_t dhl);
  void fesoti_dimCheck(fesoti_t* arr1,fesoti_t* arr2);
  void fesoti_set_all_o( sotinum_t* num, fesoti_t* res, dhelpl_t dhl);
  void fesoti_set_all_r(    coeff_t num, fesoti_t* res, dhelpl_t dhl);
  void fesoti_set_item_k_f( sotinum_t* num, uint64_t k, fesoti_t* res, dhelpl_t dhl);
  void fesoti_set_item_k_r(   coeff_t  num, uint64_t k, fesoti_t* res, dhelpl_t dhl);
  sotinum_t fesoti_get_item_k(   fesoti_t* num, uint64_t k,                 dhelpl_t dhl);
  void      fesoti_get_item_k_to(fesoti_t* num, uint64_t k, sotinum_t* res, dhelpl_t dhl);
  fesoti_t fesoti_zeros_bases(uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
  fesoti_t fesoti_createEmpty_bases(uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
  fesoti_t fesoti_empty_like(fesoti_t* arr, dhelpl_t dhl);
  ord_t fesoti_get_order( fesoti_t* num );
  fesoti_t fesoti_copy(    fesoti_t* src,                dhelpl_t dhl);
  void     fesoti_copy_to( fesoti_t* src, fesoti_t* dst, dhelpl_t dhl);
  void fesoti_free(fesoti_t* num);
  fesoti_t fesoti_init();

  # Gauss :: Array

  # Element
  uint8_t elem_is_started(   elem_t* elem );
  uint8_t elem_is_allocated( elem_t* elem );
  void elem_clear_flag_start(elem_t* elem );
  void elem_clear_flag_alloc(elem_t* elem );
  void elem_raise_flag_start(elem_t* elem );
  void elem_raise_flag_alloc(elem_t* elem );
  int64_t elem_end(elem_t* elem);
  int64_t elem_free( elem_t* elem );
  elem_t  elem_init(  );
  int64_t elem_start( elem_t* elem, uint64_t nbasis, int64_t geomBase, int64_t kind, uint8_t  ndim);
  int64_t elem_allocate(elem_t* elem, uint64_t intorder );
  int64_t fem_basisFunctions_N_QuadSerendP2_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_QuadP1_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_TriangP2_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_TriangP1_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_TriangP0_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_LineP2_1Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_LineP1_1Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_PntP0_0Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);

#-----------------------------------------------------------------------------------------------------

