
cdef extern from "oti/oti.h" nogil:
  
  # From oti/sparse/scalar/structures.h

  ctypedef struct sotinum_t: # {
      coeff_t          re;
      coeff_t**      p_im;
      imdir_t**     p_idx;
      ndir_t*       p_nnz;
      ndir_t*      p_size;
      ord_t         order;
      ord_t        torder;
      flag_t         flag;
  # } sotinum_t;
  ctypedef struct somin_t: # {
      coeff_t          re;
      coeff_t**      p_im;
      imdir_t**     p_idx;
      ndir_t*       p_nnz;
  # } somin_t;


  # From oti/sparse/array/structures.h

  ctypedef struct arrso_t: # {
      sotinum_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
      flag_t          flag;
  # } arrso_t;


  # From oti/sparse/array/oti_of_array/structures_array.h

  ctypedef struct sarr_t: # {
      sotinum_t*    p_data;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
      flag_t          flag;
  # } sarr_t;


  # From oti/sparse/array/oti_of_array/structures.h

  ctypedef struct soarr_t: # {
      arr_t            re;
      arr_t**        p_im;
      imdir_t**     p_idx;
      ndir_t*       p_nnz;
      ndir_t*      p_size;
      ord_t         order;
      uint64_t       nrows;
      uint64_t       ncols;
      uint64_t        size;
  # } soarr_t;


  # From oti/sparse/array/gauss/structures.h

  ctypedef struct fearrso_t: # {
      arrso_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t       size;
      uint64_t        nip;
  # } fearrso_t;


  


  # From oti/sparse/scalar/gauss/structures.h

  ctypedef struct fesoti_t: # {
      sotinum_t*  p_data;
      uint64_t    nip;
  # } fesoti_t;


  # =========================================================================================

  # From oti/sparse/array/utils.h

  void arrso_dimCheck_OO_elementwise(arrso_t* arr1, arrso_t* arr2, arrso_t* res);
  void arrso_dimCheck_RO_elementwise(darr_t*  arr1, arrso_t* arr2, arrso_t* res);
  void arrso_dimCheck_OO_matmul(arrso_t* arr1, arrso_t* arr2, arrso_t* res);
  void arrso_dimCheck_RO_matmul(darr_t*  arr1, arrso_t* arr2, arrso_t* res);
  void arrso_dimCheck_OR_matmul(arrso_t* arr1, darr_t*  arr2, arrso_t* res);
  void arrso_dimCheck_O_squareness(arrso_t* arr1, arrso_t* res);
  ord_t arrso_get_order(arrso_t* arr);
  void arrso_get_active_bases(arrso_t* arr, imdir_t* list_vals, dhelpl_t dhl);


  # From oti/sparse/array/algebra_elementwise.h

  arrso_t arrso_neg(arrso_t* arr, dhelpl_t dhl);
  void arrso_neg_to(arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_sum_OO(arrso_t*   lhs, arrso_t* rhs, dhelpl_t dhl);
  arrso_t arrso_sum_RO(darr_t*    lhs, arrso_t* rhs, dhelpl_t dhl);
  arrso_t arrso_sum_oO(sotinum_t* lhs, arrso_t* rhs, dhelpl_t dhl);
  arrso_t arrso_sum_rO(coeff_t    lhs, arrso_t* rhs, dhelpl_t dhl);
  void arrso_sum_OO_to(arrso_t*   lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_sum_RO_to(darr_t*    lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_sum_oO_to(sotinum_t* lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_sum_rO_to(coeff_t    lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_sub_OO(arrso_t*   lhs, arrso_t*   rhs, dhelpl_t dhl);
  arrso_t arrso_sub_RO(darr_t*    lhs, arrso_t*   rhs, dhelpl_t dhl);
  arrso_t arrso_sub_OR(arrso_t*   lhs, darr_t*    rhs, dhelpl_t dhl);
  arrso_t arrso_sub_oO(sotinum_t* lhs, arrso_t*   rhs, dhelpl_t dhl);
  arrso_t arrso_sub_Oo(arrso_t*   lhs, sotinum_t* rhs, dhelpl_t dhl);
  arrso_t arrso_sub_rO(coeff_t    lhs, arrso_t*   rhs, dhelpl_t dhl);
  arrso_t arrso_sub_Or(arrso_t*   lhs, coeff_t    rhs, dhelpl_t dhl);
  void arrso_sub_OO_to( arrso_t*   lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_sub_RO_to( darr_t*    lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_sub_OR_to( arrso_t*   lhs, darr_t*    rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_sub_oO_to( sotinum_t* lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_sub_Oo_to( arrso_t*   lhs, sotinum_t* rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_sub_rO_to( coeff_t    lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_sub_Or_to( arrso_t*   lhs, coeff_t    rhs, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_mul_OO(arrso_t*   lhs, arrso_t* rhs, dhelpl_t dhl);
  arrso_t arrso_mul_RO(darr_t*    lhs, arrso_t* rhs, dhelpl_t dhl);
  arrso_t arrso_mul_oO(sotinum_t* lhs, arrso_t* rhs, dhelpl_t dhl);
  arrso_t arrso_mul_rO(coeff_t    lhs, arrso_t* rhs, dhelpl_t dhl);
  void arrso_mul_OO_to(arrso_t*   lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_mul_RO_to(darr_t*    lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_mul_oO_to(sotinum_t* lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_mul_rO_to(coeff_t    lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_gem_OO_to(  arrso_t* arr1, arrso_t* arr2, arrso_t* arr3, arrso_t* res, dhelpl_t dhl);
  void arrso_gem_oO_to(sotinum_t* arr1, arrso_t* arr2, arrso_t* arr3, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_div_OO(arrso_t*   lhs, arrso_t*   rhs, dhelpl_t dhl);
  arrso_t arrso_div_OR(arrso_t*   lhs, darr_t*    rhs, dhelpl_t dhl);
  arrso_t arrso_div_RO(darr_t*    lhs, arrso_t*   rhs, dhelpl_t dhl);
  arrso_t arrso_div_oO(sotinum_t* lhs, arrso_t*   rhs, dhelpl_t dhl);
  arrso_t arrso_div_Oo(arrso_t*   lhs, sotinum_t* rhs, dhelpl_t dhl);
  arrso_t arrso_div_rO(coeff_t    lhs, arrso_t*   rhs, dhelpl_t dhl);
  arrso_t arrso_div_Or(arrso_t*   lhs, coeff_t    rhs, dhelpl_t dhl);
  void arrso_div_OO_to(arrso_t*   lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_div_RO_to(darr_t*    lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_div_OR_to(arrso_t*   lhs, darr_t*    rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_div_oO_to(sotinum_t* lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_div_Oo_to(arrso_t*   lhs, sotinum_t* rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_div_rO_to(coeff_t    lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
  void arrso_div_Or_to(arrso_t*   lhs, coeff_t    rhs, arrso_t* res, dhelpl_t dhl);


  # From oti/sparse/array/algebra_matops.h
  sotinum_t arrso_dotproduct_OO(    arrso_t* lhs, arrso_t* rhs,                 dhelpl_t dhl);
  void      arrso_dotproduct_OO_to( arrso_t* lhs, arrso_t* rhs, sotinum_t* res, dhelpl_t dhl);
  sotinum_t arrso_dotproduct_RO(     darr_t* lhs, arrso_t* rhs,                 dhelpl_t dhl);
  void      arrso_dotproduct_RO_to(  darr_t* lhs, arrso_t* rhs, sotinum_t* res, dhelpl_t dhl);
  arrso_t arrso_matmul_OO(    arrso_t* lhs, arrso_t* rhs,               dhelpl_t dhl);
  arrso_t arrso_matmul_OR(    arrso_t* lhs,  darr_t* rhs,               dhelpl_t dhl);
  arrso_t arrso_matmul_RO(     darr_t* lhs, arrso_t* rhs,               dhelpl_t dhl);
  void    arrso_matmul_OO_to( arrso_t* lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
  void    arrso_matmul_OR_to( arrso_t* lhs,  darr_t* rhs, arrso_t* res, dhelpl_t dhl);
  void    arrso_matmul_RO_to(  darr_t* lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_transpose(    arrso_t* arr1,               dhelpl_t dhl);
  void    arrso_transpose_to( arrso_t* arr1, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_invert(    arrso_t* arr1,               dhelpl_t dhl);
  void    arrso_invert_to( arrso_t* arr1, arrso_t* res, dhelpl_t dhl);
  sotinum_t arrso_det(    arrso_t* arr1,                 dhelpl_t dhl);
  void      arrso_det_to( arrso_t* arr1, sotinum_t* res, dhelpl_t dhl);
  sotinum_t arrso_norm(    arrso_t* arr1,                  dhelpl_t dhl);
  void      arrso_norm_to( arrso_t* arr1,  sotinum_t* res, dhelpl_t dhl);
  sotinum_t arrso_pnorm(    arrso_t* arr1, coeff_t p,                 dhelpl_t dhl);
  void      arrso_pnorm_to( arrso_t* arr1, coeff_t p, sotinum_t* res, dhelpl_t dhl);


  # From oti/sparse/array/gauss.h



  # From oti/sparse/array/functions.h

  arrso_t arrso_atanh(   arrso_t* arr,               dhelpl_t dhl);
  void    arrso_atanh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_asinh(   arrso_t* arr,               dhelpl_t dhl);
  void    arrso_asinh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_acosh(   arrso_t* arr,               dhelpl_t dhl);
  void    arrso_acosh_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_tanh(    arrso_t* arr,               dhelpl_t dhl);
  void    arrso_tanh_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_cbrt(    arrso_t* arr,               dhelpl_t dhl);
  void    arrso_cbrt_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_sqrt(    arrso_t* arr,               dhelpl_t dhl);
  void    arrso_sqrt_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_cosh(    arrso_t* arr,               dhelpl_t dhl);
  void    arrso_cosh_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_sinh(    arrso_t* arr,               dhelpl_t dhl);
  void    arrso_sinh_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_asin(    arrso_t* arr,               dhelpl_t dhl);
  void    arrso_asin_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_acos(    arrso_t* arr,               dhelpl_t dhl);
  void    arrso_acos_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_atan(    arrso_t* arr,               dhelpl_t dhl);
  void    arrso_atan_to( arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_tan(     arrso_t* arr,               dhelpl_t dhl);
  void    arrso_tan_to(  arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_cos(     arrso_t* arr,               dhelpl_t dhl);
  void    arrso_cos_to(  arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_sin(     arrso_t* arr,               dhelpl_t dhl);
  void    arrso_sin_to(  arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_logb(    arrso_t* arr, double base,               dhelpl_t dhl);
  void    arrso_logb_to( arrso_t* arr, double base, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_log10(   arrso_t* arr,               dhelpl_t dhl);
  void    arrso_log10_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_log(     arrso_t* arr,               dhelpl_t dhl);
  void    arrso_log_to(  arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_exp(     arrso_t* arr,               dhelpl_t dhl);
  void    arrso_exp_to(  arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_pow(     arrso_t* arr, double e,               dhelpl_t dhl);
  void    arrso_pow_to(  arrso_t* arr, double e, arrso_t* res, dhelpl_t dhl);


  # From oti/sparse/array/base.h
  void    arrso_taylor_integrate_to( coeff_t* deltas, arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_taylor_integrate(    coeff_t* deltas, arrso_t* arr,               dhelpl_t dhl);
  void    arrso_get_order_im_to( ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_get_order_im(    ord_t order, arrso_t* arr,               dhelpl_t dhl);
  arrso_t arrso_get_slice( arrso_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                          dhelpl_t dhl);
  void arrso_get_slice_to( arrso_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           arrso_t* res, dhelpl_t dhl);
  void arrso_set_r(   coeff_t  num,   arrso_t* arr, dhelpl_t dhl);
  void arrso_set_o( sotinum_t* num,   arrso_t* arr, dhelpl_t dhl);
  void arrso_set_O(   arrso_t* arrin, arrso_t* arr, dhelpl_t dhl);
  darr_t  arrso_get_im(   imdir_t idx, ord_t order, arrso_t* arr,               dhelpl_t dhl);
  arrso_t arrso_get_im_o( imdir_t idx, ord_t order, arrso_t* arr,               dhelpl_t dhl);
  void    arrso_get_im_to(imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_truncate_im(    imdir_t idx, ord_t order, arrso_t* arr,               dhelpl_t dhl);
  void    arrso_truncate_im_to( imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  darr_t  arrso_get_deriv(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl);
  arrso_t arrso_get_deriv_o(  imdir_t idx, ord_t order, arrso_t* arr,               dhelpl_t dhl);
  void    arrso_get_deriv_to( imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_extract_im(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl);
  void    arrso_extract_im_to(imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_extract_deriv(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl);
  void    arrso_extract_deriv_to(imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  darr_t arrso_get_im(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl);
  void arrso_copy_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl);
  arrso_t arrso_copy(arrso_t* arr, dhelpl_t dhl);
  void arrso_set_slice_r( coeff_t val, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           arrso_t* res, dhelpl_t dhl);
  void arrso_set_slice_O( arrso_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           arrso_t* res, dhelpl_t dhl);
  void arrso_set_slice_o( sotinum_t* num, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                           arrso_t* res, dhelpl_t dhl);
  void arrso_set_all_r( coeff_t num, arrso_t* arr, dhelpl_t dhl);
  void arrso_set_item_i_r( coeff_t num, uint64_t i, arrso_t* arr, dhelpl_t dhl);
  void arrso_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl);
  void arrso_set_all_o( sotinum_t* src, arrso_t* arr, dhelpl_t dhl);
  void arrso_set_item_i_o( sotinum_t* num, uint64_t i, arrso_t* arr, dhelpl_t dhl);
  void arrso_set_item_ij_o( sotinum_t* num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl);
  sotinum_t arrso_get_item_i(    arrso_t* arr, uint64_t i,                             dhelpl_t dhl);
  void      arrso_get_item_i_to( arrso_t* arr, uint64_t i,             sotinum_t* res, dhelpl_t dhl);
  sotinum_t arrso_get_item_ij(   arrso_t* arr, uint64_t i, uint64_t j,                 dhelpl_t dhl);
  void      arrso_get_item_ij_to(arrso_t* arr, uint64_t i, uint64_t j, sotinum_t* res, dhelpl_t dhl);
  arrso_t arrso_init();
  void arrso_free(arrso_t* arr);
  arrso_t arrso_empty_like(arrso_t* arr, dhelpl_t dhl);
  arrso_t arrso_eye(uint64_t nrows, ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
  arrso_t arrso_eye_bases(uint64_t nrows, bases_t nbases, ord_t order, dhelpl_t dhl);
  arrso_t arrso_ones(uint64_t nrows, uint64_t ncols, ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
  arrso_t arrso_ones_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
  arrso_t arrso_zeros(uint64_t nrows, uint64_t ncols, ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
  arrso_t arrso_zeros_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
  arrso_t arrso_createEmpty_predef(uint64_t nrows, uint64_t ncols, ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
  arrso_t arrso_createEmpty_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
  size_t arrso_memory_size( uint64_t size, ndir_t* p_nnz, ord_t order);
  void arrso_distribute_memory(void* mem, uint64_t nrows, uint64_t ncols, ndir_t* p_nnz, ord_t order,
      flag_t flag, arrso_t* res);


  # From oti/sparse/array/oti_of_array/base.h


  # From oti/sparse/array/gauss/utils.h
  void fearrso_dimCheck_FF_samesize(fearrso_t* arr1, fearrso_t* arr2, fesoti_t* res);
  void fearrso_dimCheck_OF_samesize(  arrso_t* arr1, fearrso_t* arr2, fesoti_t* res);
  void fearrso_dimCheck_RF_samesize(   darr_t* arr1, fearrso_t* arr2, fesoti_t* res);
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
  void fearrso_get_active_bases(fearrso_t* arr, imdir_t* list_vals, dhelpl_t dhl);


  # From oti/sparse/array/gauss/algebra.h

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
  arrso_t fearrso_integrate(    fearrso_t* arr, fesoti_t* w,               dhelpl_t dhl);
  void    fearrso_integrate_to( fearrso_t* arr, fesoti_t* w, arrso_t* res, dhelpl_t dhl);
  fesoti_t fearrso_dotproduct_FF(    fearrso_t* lhs, fearrso_t* rhs,                dhelpl_t dhl);
  void     fearrso_dotproduct_FF_to( fearrso_t* lhs, fearrso_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fearrso_dotproduct_OF(      arrso_t* lhs, fearrso_t* rhs,                dhelpl_t dhl);
  void     fearrso_dotproduct_OF_to(   arrso_t* lhs, fearrso_t* rhs, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fearrso_dotproduct_RF(       darr_t* lhs, fearrso_t* rhs,                dhelpl_t dhl);
  void     fearrso_dotproduct_RF_to(    darr_t* lhs, fearrso_t* rhs, fesoti_t* res, dhelpl_t dhl);
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
  fesoti_t fearrso_norm(     fearrso_t* arr,                dhelpl_t dhl);
  void     fearrso_norm_to(  fearrso_t* arr, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fearrso_pnorm(    fearrso_t* arr, coeff_t p,                dhelpl_t dhl);
  void     fearrso_pnorm_to( fearrso_t* arr, coeff_t p, fesoti_t* res, dhelpl_t dhl);
  fearrso_t   fearrso_invert(    fearrso_t* arr,                 dhelpl_t dhl);
  void        fearrso_invert_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t   fearrso_transpose(   fearrso_t* arr,                 dhelpl_t dhl);
  void        fearrso_transpose_to(fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);


  # From oti/sparse/array/gauss/functions.h

  fearrso_t fearrso_atanh(    fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_atanh_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_asinh(    fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_asinh_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_acosh(    fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_acosh_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_tanh(     fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_tanh_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sinh(     fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_sinh_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_cosh(     fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_cosh_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_atan(     fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_atan_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_asin(     fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_asin_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_acos(     fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_acos_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_tan(      fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_tan_to(   fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sin(      fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_sin_to(   fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_cos(      fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_cos_to(   fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_logb(     fearrso_t* arr, double base,                 dhelpl_t dhl);
  void      fearrso_logb_to(  fearrso_t* arr, double base, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_log10(    fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_log10_to( fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_log(      fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_log_to(   fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_exp(      fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_exp_to(   fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_cbrt(     fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_cbrt_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_sqrt(     fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_sqrt_to(  fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_pow(      fearrso_t* arr, double e,                    dhelpl_t dhl);
  void      fearrso_pow_to(   fearrso_t* arr, double e, fearrso_t* res,    dhelpl_t dhl);


  # From oti/sparse/array/gauss/base.h
  void      fearrso_get_order_im_to( ord_t order, fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_get_order_im(    ord_t order, fearrso_t* arr,                 dhelpl_t dhl);
  fearrso_t fearrso_get_deriv(   imdir_t idx, ord_t order, fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_get_deriv_to(imdir_t idx, ord_t order, fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_get_im(      imdir_t idx, ord_t order, fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_get_im_to(   imdir_t idx, ord_t order, fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_truncate_im(   imdir_t idx, ord_t order, fearrso_t* arr,                 dhelpl_t dhl);
  void      fearrso_truncate_im_to(imdir_t idx, ord_t order, fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_copy(   fearrso_t* src,                 dhelpl_t dhl);
  void      fearrso_copy_to(fearrso_t* src, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_get_im(    imdir_t idx, ord_t order, fearrso_t* arr,
                                               dhelpl_t dhl);
  void      fearrso_get_im_to( imdir_t idx, ord_t order, fearrso_t* arr,
                               fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_get_deriv(    imdir_t idx, ord_t order,
                                   fearrso_t* arr, dhelpl_t dhl);
  void      fearrso_get_deriv_to( imdir_t idx, ord_t order,
                                   fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_extract_im(    imdir_t idx, ord_t order, fearrso_t* arr,
                                                    dhelpl_t dhl);
  void      fearrso_extract_im_to( imdir_t idx, ord_t order, fearrso_t* arr,
                                    fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_extract_deriv(    imdir_t idx, ord_t order,
                                      fearrso_t* arr, dhelpl_t dhl);
  void      fearrso_extract_deriv_to( imdir_t idx, ord_t order,
                                      fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
  arrso_t   fearrso_get_item_k(  fearrso_t* arr, uint64_t k,                         dhelpl_t dhl);
  fesoti_t  fearrso_get_item_ij( fearrso_t* arr, uint64_t i, uint64_t j,             dhelpl_t dhl);
  sotinum_t fearrso_get_item_ijk(fearrso_t* arr, uint64_t i, uint64_t j, uint64_t k, dhelpl_t dhl);
  void fearrso_get_item_ij_to(  fearrso_t* arr, uint64_t i, uint64_t j,
                                 fesoti_t* res, dhelpl_t dhl);
  void fearrso_get_item_k_to(   fearrso_t* arr, uint64_t k,
                                  arrso_t* res, dhelpl_t dhl);
  void fearrso_get_item_ijk_to( fearrso_t* arr, uint64_t i, uint64_t j, uint64_t k,
                                sotinum_t* res, dhelpl_t dhl);
  void fearrso_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                              fearrso_t* res, dhelpl_t dhl);
  void fearrso_set_item_ij_o(  sotinum_t* elm, uint64_t i, uint64_t j,
                               fearrso_t* res, dhelpl_t dhl);
  void fearrso_set_item_ij_f(  fesoti_t* elm, uint64_t i, uint64_t j,
                              fearrso_t* res, dhelpl_t dhl);
  void fearrso_set_item_k_r(    coeff_t  elm, uint64_t k,
                              fearrso_t* res, dhelpl_t dhl);
  void fearrso_set_item_k_o(  sotinum_t* elm, uint64_t k,
                              fearrso_t* res, dhelpl_t dhl);
  void fearrso_set_item_k_R(    arrso_t* elm, uint64_t k,
                            fearrso_t* res, dhelpl_t dhl);
  void fearrso_set_item_k_O(    arrso_t* elm, uint64_t k,
                            fearrso_t* res, dhelpl_t dhl);
  void fearrso_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k,
                               fearrso_t* res, dhelpl_t dhl);
  void fearrso_set_item_ijk_o( sotinum_t* elm, uint64_t i, uint64_t j, uint64_t k,
                               fearrso_t* res, dhelpl_t dhl);
  fearrso_t fearrso_get_slice(fearrso_t* arr, 
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj, 
                             dhelpl_t dhl);
  void      fearrso_get_slice_to(fearrso_t* arr, 
                            int64_t starti, int64_t stopi, int64_t stepi,
                            int64_t startj, int64_t stopj, int64_t stepj, 
                            fearrso_t* res, dhelpl_t dhl);
  void fearrso_set_all_o( sotinum_t* num, fearrso_t* arr, dhelpl_t dhl );
  void fearrso_set_all_r(    coeff_t num, fearrso_t* arr, dhelpl_t dhl );
  void fearrso_set_r(    coeff_t src, fearrso_t* res, dhelpl_t dhl );
  void fearrso_set_o( sotinum_t* src, fearrso_t* res, dhelpl_t dhl );
  void fearrso_set_f(  fesoti_t* src, fearrso_t* res, dhelpl_t dhl );
  void fearrso_set_R(    darr_t* src, fearrso_t* res, dhelpl_t dhl );
  void fearrso_set_O(   arrso_t* src, fearrso_t* res, dhelpl_t dhl );
  void fearrso_set_F( fearrso_t* src, fearrso_t* res, dhelpl_t dhl );
  fearrso_t fearrso_eye_bases( uint64_t size,
                               uint64_t nip, bases_t  nbases, 
                               ord_t    order,   dhelpl_t dhl     );
  fearrso_t fearrso_zeros_bases( uint64_t nrows,   uint64_t ncols,
                                 uint64_t nIntPts, bases_t  nbases,
                                 ord_t    order,   dhelpl_t dhl     );
  fearrso_t fearrso_ones_bases(  uint64_t nrows,   uint64_t ncols, 
                                 uint64_t nip, bases_t  nbases, 
                                 ord_t    order,   dhelpl_t dhl     );
  fearrso_t fearrso_createEmpty_bases( uint64_t nrows,   uint64_t ncols,
                                       uint64_t nIntPts, bases_t  nbases,
                                       ord_t    order,   dhelpl_t dhl);
  void fearrso_free(fearrso_t* arr);
  fearrso_t fearrso_init();
  ord_t fearrso_get_order(fearrso_t* arr);


  # From oti/sparse/scalar/utils.h

  void soti_trunc_ssum(sotinum_t* num1, ord_t ord, sotinum_t* res, dhelpl_t dhl );
  void soti_trunc_mul(sotinum_t* num1, ord_t ord1,
                      sotinum_t* num2, ord_t ord2,
                      sotinum_t* dest, dhelpl_t dhl );
  void soti_trunc_smul_real(coeff_t a, ord_t ord, sotinum_t* res, dhelpl_t dhl);
  void soti_get_active_bases(sotinum_t* num, imdir_t* list, dhelpl_t dhl);


  # From oti/sparse/scalar/algebra.h

  sotinum_t soti_div_oo(sotinum_t* num, sotinum_t* den, dhelpl_t dhl);
  sotinum_t soti_div_ro(coeff_t num, sotinum_t* den, dhelpl_t dhl);
  sotinum_t soti_div_or(sotinum_t* num, coeff_t val, dhelpl_t dhl);
  void      soti_div_oo_to(sotinum_t* num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl);
  void      soti_div_ro_to(coeff_t num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl);
  void      soti_div_or_to(sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_mul_oo(   sotinum_t* num1, sotinum_t* num2,                 dhelpl_t dhl);
  sotinum_t soti_mul_ro(      coeff_t num1, sotinum_t* num2,                 dhelpl_t dhl);
  sotinum_t soti_mul_or(   sotinum_t* num1,    coeff_t num2,                 dhelpl_t dhl);
  sotinum_t soti_base_mul( sotinum_t* num1, sotinum_t* num2,                 dhelpl_t dhl);
  void      soti_mul_oo_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl);
  void      soti_mul_ro_to(   coeff_t num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl);
  void      soti_mul_or_to(sotinum_t* num1,    coeff_t num2, sotinum_t* res, dhelpl_t dhl);
  void soti_gem_oo_to(sotinum_t* a, sotinum_t* b, sotinum_t* c, sotinum_t* res, dhelpl_t dhl);
  void soti_gem_or_to( sotinum_t* a,    coeff_t b, sotinum_t* c, sotinum_t* res, dhelpl_t dhl);
  void soti_gem_ro_to(    coeff_t a, sotinum_t* b, sotinum_t* c, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_sub_oo(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
  sotinum_t soti_sub_ro( coeff_t val, sotinum_t* num, dhelpl_t dhl);
  sotinum_t soti_sub_or(sotinum_t* num, coeff_t val, dhelpl_t dhl);
  sotinum_t soti_base_sub(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
  void      soti_sub_oo_to(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl);
  void      soti_sub_ro_to( coeff_t val, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  void      soti_sub_or_to(sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_sum_oo(    sotinum_t* num1, sotinum_t* num2,                 dhelpl_t dhl);
  sotinum_t soti_sum_ro(       coeff_t num1, sotinum_t* num2,                 dhelpl_t dhl);
  sotinum_t soti_sum_or(    sotinum_t* num1,    coeff_t num2,                 dhelpl_t dhl);
  sotinum_t soti_base_sum(  sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
  void      soti_sum_oo_to( sotinum_t* num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl);
  void      soti_sum_ro_to(    coeff_t num1, sotinum_t* num2, sotinum_t* res, dhelpl_t dhl);
  void      soti_sum_or_to( sotinum_t* num1,    coeff_t num2, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_neg(sotinum_t* num, dhelpl_t dhl);
  void      soti_neg_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_abs(   sotinum_t* num,                 dhelpl_t dhl);
  void      soti_abs_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);


  # From oti/sparse/scalar/gauss.h



  # From oti/sparse/scalar/functions.h

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
  sotinum_t soti_cbrt(sotinum_t* num, dhelpl_t dhl);
  void soti_cbrt_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
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
  sotinum_t soti_feval(coeff_t* feval_re, sotinum_t* num, dhelpl_t dhl );
  sotinum_t soti_base_feval(coeff_t* feval_re, sotinum_t* num, dhelpl_t dhl );
  void soti_feval_to(coeff_t* feval_re, sotinum_t* num, sotinum_t* res, dhelpl_t dhl );


  # From oti/sparse/scalar/base.h
  sotinum_t soti_taylor_integrate(    coeff_t* deltas, sotinum_t* num,                 dhelpl_t dhl);
  void      soti_taylor_integrate_to( coeff_t* deltas, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_get_order_im(    ord_t order, sotinum_t* num,                 dhelpl_t dhl);
  void      soti_get_order_im_to( ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_truncate_im(   imdir_t idx, ord_t order, sotinum_t* num,                 dhelpl_t dhl);
  void      soti_truncate_im_to(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_extract_deriv(   imdir_t idx, ord_t ord, sotinum_t* num,                 dhelpl_t dhl);
  void      soti_extract_deriv_to(imdir_t idx, ord_t ord, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_extract_im(   imdir_t idx, ord_t ord, sotinum_t* num,                 dhelpl_t dhl);
  void      soti_extract_im_to(imdir_t idx, ord_t ord, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  void* soti_distribute_memory(void* mem, const ndir_t* p_nnz, ord_t order, flag_t flag, sotinum_t* res);
  size_t soti_memory_size( const ndir_t* p_nnz, ord_t order);
  uint8_t soti_requiresrealloc(sotinum_t* src, sotinum_t* dest);
  sotinum_t soti_init();
  void soti_set_o( sotinum_t* src, sotinum_t* dest, dhelpl_t dhl);
  void soti_set_r(    coeff_t src, sotinum_t* dest, dhelpl_t dhl);
  void soti_set_trunc( sotinum_t* src, ord_t ord, sotinum_t* dest, dhelpl_t dhl);
  void soti_set_deriv_r(   coeff_t  coef, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
  void soti_set_deriv_o( sotinum_t* coef, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
  coeff_t soti_get_deriv( imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
  sotinum_t soti_get_deriv_o(  imdir_t idx, ord_t order, sotinum_t* num,                 dhelpl_t dhl);
  void      soti_get_deriv_to( imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  sotinum_t soti_get_tmp( ndir_t ntmp, ord_t order, dhelpl_t dhl);
  sotinum_t soti_get_rtmp(ndir_t ntmp, ord_t order, dhelpl_t dhl);
  void soti_insert_item(ndir_t pos, coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
  void soti_set_item(   coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
  void soti_set_im_r(   coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
  void soti_set_im_o(sotinum_t* val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
  coeff_t soti_get_item(    imdir_t idx, ord_t order, sotinum_t* num,                 dhelpl_t dhl);
  coeff_t soti_get_im(      imdir_t idx, ord_t order, sotinum_t* num,                 dhelpl_t dhl);
  sotinum_t soti_get_im_o(  imdir_t idx, ord_t order, sotinum_t* num,                 dhelpl_t dhl);
  void    soti_get_im_to_o( imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
  void    soti_get_im_to_r( imdir_t idx, ord_t order, sotinum_t* num,   coeff_t* res, dhelpl_t dhl);
  sotinum_t soti_copy(             sotinum_t* num,                  dhelpl_t dhl);
  void      soti_copy_to(          sotinum_t* src, sotinum_t* dest, dhelpl_t dhl);
  void      soti_copy_nomemchk_to( sotinum_t* src, sotinum_t* dest, dhelpl_t dhl);
  void soti_print(sotinum_t* num, dhelpl_t dhl);
  void soti_free(sotinum_t* num);
  sotinum_t soti_createReal_bases(  coeff_t num, bases_t nbases, ord_t order, dhelpl_t dhl);
  sotinum_t soti_createEmpty_bases(              bases_t nbases, ord_t order, dhelpl_t dhl);
  sotinum_t soti_createReal(coeff_t num, ord_t order, dhelpl_t dhl);
  sotinum_t soti_createEmpty( ord_t order, dhelpl_t dhl);
  sotinum_t soti_createEmpty_like( sotinum_t* other, dhelpl_t dhl);
  sotinum_t soti_createEmpty_predef(ndir_t* p_nnz, ord_t order, dhelpl_t dhl);


  # From oti/sparse/scalar/gauss/utils.h

  void fesoti_dimCheck(fesoti_t* arr1,fesoti_t* arr2);
  void fesoti_get_active_bases(fesoti_t* num, imdir_t* list_vals, dhelpl_t dhl);


  # From oti/sparse/scalar/gauss/algebra.h

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


  # From oti/sparse/scalar/gauss/functions.h

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
  sotinum_t fesoti_integrate_f(     fesoti_t* num, fesoti_t* w,                 dhelpl_t dhl);
  void      fesoti_integrate_f_to(  fesoti_t* num, fesoti_t* w, sotinum_t* res, dhelpl_t dhl);
  sotinum_t fesoti_integrate_r(       coeff_t num, fesoti_t* w,                 dhelpl_t dhl);
  void      fesoti_integrate_r_to(    coeff_t num, fesoti_t* w, sotinum_t* res, dhelpl_t dhl);
  sotinum_t fesoti_integrate_o(    sotinum_t* num, fesoti_t* w,                 dhelpl_t dhl);
  void      fesoti_integrate_o_to( sotinum_t* num, fesoti_t* w, sotinum_t* res, dhelpl_t dhl);


  # From oti/sparse/scalar/gauss/base.h
  void     fesoti_get_order_im_to( ord_t order, fesoti_t* arr, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_get_order_im(    ord_t order, fesoti_t* arr,                dhelpl_t dhl);
  fesoti_t fesoti_get_deriv(    imdir_t idx, ord_t order, fesoti_t* num,                dhelpl_t dhl);
  void     fesoti_get_deriv_to( imdir_t idx, ord_t order, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
  void fesoti_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
  void fesoti_set_im_o( sotinum_t* val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
  void fesoti_set_im_f(  fesoti_t* val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
  void fesoti_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
  void fesoti_set_deriv_o( sotinum_t* val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
  void fesoti_set_deriv_f(  fesoti_t* val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
  fesoti_t fesoti_get_im(    imdir_t idx, ord_t order, fesoti_t* num,                dhelpl_t dhl);
  void     fesoti_get_im_to( imdir_t idx, ord_t order, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_extract_im(    imdir_t idx, ord_t order, fesoti_t* num,                dhelpl_t dhl);
  void     fesoti_extract_im_to( imdir_t idx, ord_t order, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_extract_deriv(    imdir_t idx, ord_t order, fesoti_t* num,                dhelpl_t dhl);
  void     fesoti_extract_deriv_to( imdir_t idx, ord_t order, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_truncate_im(    imdir_t idx, ord_t order, fesoti_t* num,                dhelpl_t dhl);
  void     fesoti_truncate_im_to( imdir_t idx, ord_t order, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
  fesoti_t fesoti_copy(    fesoti_t* src,                dhelpl_t dhl);
  void     fesoti_copy_to( fesoti_t* src, fesoti_t* dst, dhelpl_t dhl);
  void fesoti_set_r(    coeff_t num, fesoti_t* res, dhelpl_t dhl);
  void fesoti_set_o( sotinum_t* num, fesoti_t* res, dhelpl_t dhl);
  void fesoti_set_f(  fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
  void fesoti_set_item_k_r(   coeff_t  num, uint64_t k, fesoti_t* res, dhelpl_t dhl);
  void fesoti_set_item_k_o( sotinum_t* num, uint64_t k, fesoti_t* res, dhelpl_t dhl);
  sotinum_t fesoti_get_item_k(   fesoti_t* num, uint64_t k,                 dhelpl_t dhl);
  void      fesoti_get_item_k_to(fesoti_t* num, uint64_t k, sotinum_t* res, dhelpl_t dhl);
  fesoti_t fesoti_zeros_bases(uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
  fesoti_t fesoti_createEmpty_bases(uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
  fesoti_t fesoti_empty_like(fesoti_t* arr, dhelpl_t dhl);
  void fesoti_free(fesoti_t* num);
  ord_t fesoti_get_order( fesoti_t* num );
  fesoti_t fesoti_init();



  #---------------------------------------------------------------------------------------------------

  
