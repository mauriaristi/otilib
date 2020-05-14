
cdef extern from "oti/oti.h" nogil:
  
  # Defs from "sparse.h"
  ctypedef struct sotinum_t:
    coeff_t          re
    coeff_t**      p_im
    imdir_t**     p_idx
    ndir_t*       p_nnz
    ndir_t*      p_size
    ord_t         order
    flag_t         flag


  ctypedef struct somin_t:
    coeff_t          re
    coeff_t**      p_im
    imdir_t**     p_idx
    ndir_t*       p_nnz

  ctypedef struct  arrso_t:
    sotinum_t*    p_data
    uint64_t       nrows
    uint64_t       ncols
    uint64_t        size
    flag_t          flag

  # Include functions from "sparse.h"
  #---------------------------------------------------------------------------------------------------
  void arrso_copy_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_copy(arrso_t* arr, dhelpl_t dhl);
  arrso_t arrso_eye_bases(uint64_t nrows, bases_t nbases, ord_t order, dhelpl_t dhl);
  arrso_t arrso_ones_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
  arrso_t arrso_zeros_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
  void arrso_set_all_r( coeff_t num, arrso_t* arr, dhelpl_t dhl);
  void arrso_set_item_i_r( coeff_t num, uint64_t i, arrso_t* arr, dhelpl_t dhl);
  void arrso_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl);
  void arrso_set_all_o( sotinum_t* src, arrso_t* arr, dhelpl_t dhl);
  void arrso_set_item_i_o( sotinum_t* num, uint64_t i, arrso_t* arr, dhelpl_t dhl);
  void arrso_set_item_ij_o( sotinum_t* num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl);
  sotinum_t arrso_get_item_i(arrso_t* arr, uint64_t i, dhelpl_t dhl);
  sotinum_t arrso_get_item_ij(arrso_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl);
  arrso_t arrso_init();
  void arrso_free(arrso_t* arr);
  arrso_t arrso_eye(uint64_t nrows, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
  arrso_t arrso_ones(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
  arrso_t arrso_zeros(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
  arrso_t arrso_createEmpty_predef(uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
  size_t arrso_memory_size( uint64_t size, const ndir_t* p_nnz, ord_t order);
  void arrso_distribute_memory(void* mem, uint64_t nrows, uint64_t ncols, const ndir_t* p_nnz, ord_t order, 
      flag_t flag, arrso_t* res);


  sotinum_t soti_cbrt(sotinum_t* num, dhelpl_t dhl);
  void soti_cbrt_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_atanh(sotinum_t* num, dhelpl_t dhl);
  void soti_atanh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_asinh(sotinum_t* num, dhelpl_t dhl);
  void soti_asinh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_acosh(sotinum_t* num, dhelpl_t dhl);
  void soti_acosh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_tanh(sotinum_t* num, dhelpl_t dhl);
  void soti_tanh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_sqrt(sotinum_t* num, dhelpl_t dhl);
  void soti_sqrt_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_cosh(sotinum_t* num, dhelpl_t dhl);
  void soti_cosh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_sinh(sotinum_t* num, dhelpl_t dhl);
  void soti_sinh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_asin(sotinum_t* num, dhelpl_t dhl);
  void soti_asin_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_acos(sotinum_t* num, dhelpl_t dhl);
  void soti_acos_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_atan(sotinum_t* num, dhelpl_t dhl);
  void soti_atan_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_tan(sotinum_t* num, dhelpl_t dhl);
  void soti_tan_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_cos(sotinum_t* num, dhelpl_t dhl);
  void soti_cos_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_sin(sotinum_t* num, dhelpl_t dhl );
  void soti_sin_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_logb(sotinum_t* num, double base, dhelpl_t dhl);
  void soti_logb_to(sotinum_t* num, double base, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_log10(sotinum_t* num, dhelpl_t dhl);
  void soti_log10_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_log(sotinum_t* num, dhelpl_t dhl);
  void soti_log_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_exp(sotinum_t* num, dhelpl_t dhl);
  void soti_exp_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_pow(sotinum_t* num, double e, dhelpl_t dhl);
  void soti_pow_to(sotinum_t* num, coeff_t e, sotinum_t* res, dhelpl_t dhl);
  void soti_trunc_ssum(sotinum_t* num1, ord_t ord, sotinum_t* res, dhelpl_t dhl );
  void soti_trunc_mul(sotinum_t* num1, ord_t ord1, 
                      sotinum_t* num2, ord_t ord2, 
                      sotinum_t* dest, dhelpl_t dhl );
  void soti_trunc_smul_real(coeff_t a, ord_t ord, sotinum_t* res, dhelpl_t dhl);
  void soti_set( sotinum_t* src, sotinum_t* dest, dhelpl_t dhl);
  void soti_set_trunc( sotinum_t* src, ord_t ord, sotinum_t* dest, dhelpl_t dhl);
  void soti_setFromReal( coeff_t a, sotinum_t* num, dhelpl_t dhl);
  sotinum_t soti_feval(coeff_t* feval_re, sotinum_t* num, dhelpl_t dhl );
  sotinum_t soti_base_feval(coeff_t* feval_re, sotinum_t* num, dhelpl_t dhl );
  void soti_feval_to(coeff_t* feval_re, sotinum_t* num, sotinum_t* res, dhelpl_t dhl );
  sotinum_t soti_div_oo(sotinum_t* num, sotinum_t* den, dhelpl_t dhl);
  sotinum_t soti_div_ro(coeff_t num, sotinum_t* den, dhelpl_t dhl);
  sotinum_t soti_div_or(sotinum_t* num, coeff_t val, dhelpl_t dhl);
  void soti_div_oo_to(sotinum_t* num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl);
  void soti_div_ro_to(coeff_t num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl);
  void soti_div_or_to(sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl);
  coeff_t soti_get_deriv( imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
  sotinum_t soti_mul_oo(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
  sotinum_t soti_mul_ro(coeff_t val, sotinum_t* num, dhelpl_t dhl);
  sotinum_t soti_base_mul(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
  void soti_mul_oo_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl);
  void soti_mul_ro_to(coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_sub_oo(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
  sotinum_t soti_sub_ro( coeff_t val, sotinum_t* num, dhelpl_t dhl);
  sotinum_t soti_sub_or(sotinum_t* num, coeff_t val, dhelpl_t dhl);
  sotinum_t soti_base_sub(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
  void soti_sub_oo_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl);
  void soti_sub_ro_to( coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  void soti_sub_or_to(sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_sum_oo(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
  sotinum_t soti_sum_ro(coeff_t val, sotinum_t* num, dhelpl_t dhl);
  sotinum_t soti_base_sum(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
  void soti_sum_oo_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl);
  void soti_sum_ro_to(coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_get_tmp(ndir_t ntmp, ord_t order, dhelpl_t dhl);
  sotinum_t soti_get_rtmp(ndir_t ntmp, ord_t order, dhelpl_t dhl);
  sotinum_t soti_neg(sotinum_t* num, dhelpl_t dhl);
  void soti_neg_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  void soti_insert_item(ndir_t pos, coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
  void soti_set_item(coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
  coeff_t soti_get_item(imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
  sotinum_t soti_copy(sotinum_t* num, dhelpl_t dhl);
  void soti_copy_to(sotinum_t* src, sotinum_t* dest, dhelpl_t dhl);
  void soti_print(sotinum_t* num, dhelpl_t dhl);
  void soti_free(sotinum_t* num);
  sotinum_t soti_init();
  sotinum_t soti_createReal(coeff_t num, ord_t order, dhelpl_t dhl);
  sotinum_t soti_createEmpty( ord_t order, dhelpl_t dhl); 
  sotinum_t soti_createEmpty_predef(ndir_t* p_nnz, ord_t order, dhelpl_t dhl); 

  #---------------------------------------------------------------------------------------------------

  