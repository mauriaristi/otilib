
cdef extern from "oti/oti.h" nogil:

	# Defs from "dense.h"
  ctypedef struct otinum_t:
    coeff_t          re
    coeff_t**      p_im
    ndir_t*      p_ndpo
    ndir_t         ndir
    bases_t      nbases
    ord_t         order

  ctypedef struct oarr_t:
    arr_t            re
    arr_t**        p_im
    ndir_t*      p_ndpo
    ndir_t         ndir
    bases_t      nbases
    ord_t         order
    uint64_t      nrows
    uint64_t      ncols
    uint64_t       size


  # Include functions from "dense.h"
  #---------------------------------------------------------------------------------------------------
  darr_t oti_to_cr_dense(otinum_t* num,  dhelpl_t dhl);

  otinum_t oarr_det(oarr_t* arr, dhelpl_t dhl);
  void oarr_det_to(oarr_t* arr, otinum_t* res, dhelpl_t dhl);

  oarr_t oarr_transpose(oarr_t* arr, dhelpl_t dhl);
  void oarr_transpose_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl);

  oarr_t oarr_invert(oarr_t* arr, dhelpl_t dhl);
  void oarr_invert_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl);
  
  oarr_t oarr_eye(uint64_t size, bases_t nbases, ord_t order, dhelpl_t dhl);

  oarr_t oarr_matmul_OO(oarr_t* lhs, oarr_t* rhs, dhelpl_t dhl);
  oarr_t oarr_matmul_OR(oarr_t* lhs, darr_t* rhs, dhelpl_t dhl);
  oarr_t oarr_matmul_RO(darr_t* lhs, oarr_t* rhs, dhelpl_t dhl);

  oarr_t oarr_neg( oarr_t* arr1, dhelpl_t dhl);
  void oarr_neg_to(oarr_t* arr1, oarr_t* res, dhelpl_t dhl);

  oarr_t oarr_sum_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
  void oarr_sum_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_sum_oO(otinum_t* num, oarr_t* arr1, dhelpl_t dhl);
  void oarr_sum_oO_to(otinum_t* num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_sum_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
  void oarr_sum_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_sum_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
  void oarr_sum_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);

  oarr_t oarr_sub_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
  void oarr_sub_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_sub_oO(otinum_t* num, oarr_t* arr1, dhelpl_t dhl);
  void oarr_sub_oO_to(otinum_t* num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_sub_Oo(oarr_t* arr1, otinum_t* num, dhelpl_t dhl);
  void oarr_sub_Oo_to(oarr_t* arr1, otinum_t* num, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_sub_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
  void oarr_sub_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_sub_OR(oarr_t* arr1, darr_t* arr2, dhelpl_t dhl);
  void oarr_sub_OR_to(oarr_t* arr1, darr_t* arr2, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_sub_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
  void oarr_sub_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_sub_Or( oarr_t* arr1, coeff_t num, dhelpl_t dhl);
  void oarr_sub_Or_to( oarr_t* arr1, coeff_t num, oarr_t* res, dhelpl_t dhl);

  oarr_t oarr_mul_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
  void oarr_mul_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_mul_oO(otinum_t* num, oarr_t* arr1, dhelpl_t dhl);
  void oarr_mul_oO_to(otinum_t* num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_mul_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
  void oarr_mul_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_mul_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
  void oarr_mul_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);

  oarr_t oarr_div_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
  void oarr_div_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_div_oO(otinum_t* num, oarr_t* arr1, dhelpl_t dhl);
  void oarr_div_oO_to(otinum_t* num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_div_Oo(oarr_t* arr1, otinum_t* num, dhelpl_t dhl);
  void oarr_div_Oo_to(oarr_t* arr1, otinum_t* num, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_div_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
  void oarr_div_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_div_OR(oarr_t* arr1, darr_t* arr2, dhelpl_t dhl);
  void oarr_div_OR_to(oarr_t* arr1, darr_t* arr2, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_div_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
  void oarr_div_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_div_Or( oarr_t* arr1, coeff_t num, dhelpl_t dhl);
  void oarr_div_Or_to( oarr_t* arr1, coeff_t num, oarr_t* res, dhelpl_t dhl);


  void oarr_set_all_r( coeff_t num, oarr_t* arr, dhelpl_t dhl);
  void oarr_set_item_i_r( coeff_t num, uint64_t i, oarr_t* arr, dhelpl_t dhl);
  void oarr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl);
  void oarr_set_all_o( otinum_t* num, oarr_t* arr, dhelpl_t dhl);
  void oarr_set_item_i_o( otinum_t* num, uint64_t i, oarr_t* arr, dhelpl_t dhl);
  void oarr_set_item_ij_o( otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl);
  otinum_t oarr_get_item_i(oarr_t* arr, uint64_t i, dhelpl_t dhl);
  otinum_t oarr_get_item_ij(oarr_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl);
  void oarr_get_item_i_to(oarr_t* p_array, uint64_t i, otinum_t* res, dhelpl_t dhl);
  void oarr_get_item_ij_to(oarr_t* p_array, uint64_t i, uint64_t j, otinum_t* res, dhelpl_t dhl);
  void oarr_copy_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl);
  oarr_t oarr_copy(oarr_t* arr, dhelpl_t dhl);
  oarr_t oarr_ones(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
  oarr_t oarr_zeros(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
  void oarr_free(oarr_t* arr);
  oarr_t oarr_createEmpty( uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
  otinum_t oti_get_tmp( ndir_t ntmp, ord_t order, bases_t nbases, dhelpl_t dhl);
  otinum_t oti_get_rtmp( ndir_t ntmp, ord_t order, bases_t nbases, dhelpl_t dhl);
  otinum_t oti_atanh(otinum_t* num, dhelpl_t dhl);
  void oti_atanh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_asinh(otinum_t* num, dhelpl_t dhl);
  void oti_asinh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_acosh(otinum_t* num, dhelpl_t dhl);
  void oti_acosh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_tanh(otinum_t* num, dhelpl_t dhl);
  void oti_tanh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_sqrt(otinum_t* num, dhelpl_t dhl);
  void oti_sqrt_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_cosh(otinum_t* num, dhelpl_t dhl);
  void oti_cosh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_sinh(otinum_t* num, dhelpl_t dhl);
  void oti_sinh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_asin(otinum_t* num, dhelpl_t dhl);
  void oti_asin_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_acos(otinum_t* num, dhelpl_t dhl);
  void oti_acos_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_atan(otinum_t* num, dhelpl_t dhl);
  void oti_atan_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_tan(otinum_t* num, dhelpl_t dhl);
  void oti_tan_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_cos(otinum_t* num, dhelpl_t dhl);
  void oti_cos_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_sin(otinum_t* num, dhelpl_t dhl );
  void oti_sin_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_logb(otinum_t* num, double base, dhelpl_t dhl);
  void oti_logb_to(otinum_t* num, double base, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_log10(otinum_t* num, dhelpl_t dhl);
  void oti_log10_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_log(otinum_t* num, dhelpl_t dhl);
  void oti_log_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_exp(otinum_t* num, dhelpl_t dhl);
  void oti_exp_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_pow(otinum_t* num, double e, dhelpl_t dhl);
  void oti_pow_to(otinum_t* num, double e, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_feval(coeff_t* feval_re, otinum_t* num, dhelpl_t dhl );
  void oti_feval_to(coeff_t* feval_re, otinum_t* num, otinum_t* res, dhelpl_t dhl );
  void oti_trunc_ssum(otinum_t* num1,  
                     ord_t ord, otinum_t* res,  dhelpl_t dhl );
  void oti_trunc_mul(otinum_t* num1, ord_t ord1, 
                   otinum_t* num2, ord_t ord2, 
                   otinum_t* res, dhelpl_t dhl );
  void oti_trunc_smul_real(coeff_t a, ord_t ord, otinum_t* num, dhelpl_t dhl);
  otinum_t oti_neg(otinum_t* num1, dhelpl_t dhl);
  void oti_neg_to(otinum_t* num1, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_sub_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
  otinum_t oti_sub_or(otinum_t* num1, coeff_t a, dhelpl_t dhl);
  otinum_t oti_sub_ro(coeff_t a, otinum_t* num2, dhelpl_t dhl);
  void oti_sub_or_to(otinum_t* num1, coeff_t a, otinum_t* res, dhelpl_t dhl);
  void oti_sub_ro_to(coeff_t a, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
  void oti_sub_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_div_oo(otinum_t* num, otinum_t* den, dhelpl_t dhl );
  otinum_t oti_div_ro(coeff_t num, otinum_t* den, dhelpl_t dhl );
  otinum_t oti_div_or(otinum_t* num, coeff_t den, dhelpl_t dhl );
  void oti_div_or_to(otinum_t* num, coeff_t den, otinum_t* res, dhelpl_t dhl );
  void oti_div_ro_to(coeff_t num, otinum_t* den, otinum_t* res, dhelpl_t dhl );
  void oti_div_oo_to(otinum_t* num, otinum_t* den, otinum_t* res, dhelpl_t dhl );
  otinum_t oti_mul_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
  otinum_t oti_mul_ro(coeff_t a, otinum_t* num1, dhelpl_t dhl);
  void oti_mul_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
  void oti_mul_ro_to(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl);
  otinum_t oti_sum_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
  otinum_t oti_sum_ro(coeff_t a, otinum_t* num1, dhelpl_t dhl);
  void oti_sum_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
  void oti_sum_ro_to(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl);
  void oti_setIm_IdxOrd( coeff_t a, imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);
  coeff_t oti_get( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);
  coeff_t oti_get_deriv( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);
  otinum_t oti_createZero( bases_t nbases, ord_t order, dhelpl_t dhl);
  otinum_t oti_createEmpty( bases_t nbases, ord_t order, dhelpl_t dhl);
  otinum_t oti_init(  );
  otinum_t oti_copy(otinum_t* num, dhelpl_t dhl);
  void oti_copy_to( otinum_t* num, otinum_t* res, dhelpl_t dhl);
  void oti_setFromReal( coeff_t a, otinum_t* num, dhelpl_t dhl);
  void oti_print( otinum_t* num, dhelpl_t dhl);
  void oti_free( otinum_t* num );

  #---------------------------------------------------------------------------------------------------

