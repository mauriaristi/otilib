#file c_otilib.pxd

from libc.stdint cimport uint8_t, uint16_t, uint32_t, uint64_t, int64_t, int16_t, int8_t, int32_t
cimport numpy
#-----------------------------------------------------------------------------------------------------
#--------------------------------------     TYPE DECLARATIONS     ------------------------------------
#-----------------------------------------------------------------------------------------------------
ctypedef double    coeff_t 
ctypedef double*     arr_t
ctypedef uint64_t  imdir_t
ctypedef uint64_t   ndir_t
ctypedef uint16_t  bases_t
ctypedef uint8_t     ord_t
ctypedef uint8_t     ndh_t
ctypedef uint8_t    flag_t
#-----------------------------------------------------------------------------------------------------




#-----------------------------------------------------------------------------------------------------
#-----------------------------------   IMPORT EXTERNAL C FUNCTIONS   ---------------------------------
#-----------------------------------------------------------------------------------------------------
# File created just to remove all warnings from numpy.
# cdef extern from "pyoti/numpy_warning.h" nogil:
#   cdef int NPY_NO_DEPRECATED_API;

cdef extern from "oti/oti.h" nogil:
  
  # Defs from "core.h"
  ctypedef struct imdir2d_t:
    imdir_t* p_arr     
    uint64_t shape[2]

  ctypedef struct dhelp_t:    
    bases_t*      p_fulldir
    imdir2d_t*  p_multtabls
    ndir_t*         p_ndirs
    coeff_t**          p_im
    imdir_t**         p_idx
    coeff_t***        p_ims
    imdir_t***        p_ids
    ndir_t**          p_nnz
    ndir_t**         p_size
    ndir_t        allocSize
    ndir_t            Ntmps
    ndir_t             Ndir
    ord_t             Nmult
    bases_t          Nbasis
    ord_t             order
  
  ctypedef struct dhelpl_t:
    dhelp_t* p_dh
    ndh_t     ndh
    ord_t*  order

  ctypedef struct coomat_ui64_t: 
    uint64_t*     p_data 
    uint64_t*     p_cols 
    uint64_t*     p_rows 
    uint64_t       sizex 
    uint64_t       sizey 
    uint64_t     nonzero 

  ctypedef struct csrmat_ui64_t:
    uint64_t*     p_data 
    uint64_t*  p_indices 
    uint64_t*   p_indptr 
    uint64_t       sizex 
    uint64_t       sizey 
    uint64_t     nonzero 

  ctypedef struct matrix_form_t:
    imdir_t*        p_im
    ord_t*         p_ord
    uint64_t*     p_cols
    uint64_t*     p_rows
    uint64_t       sizex
    uint64_t       sizey
    uint64_t     nonzero



  # Defs from "real.h"
  ctypedef struct darr_t:
    coeff_t*       p_data
    uint64_t        nrows
    uint64_t        ncols
    uint64_t         size

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
    somin_t*      p_data
    uint64_t       nrows
    uint64_t       ncols
    uint64_t        size
    ndir_t*       p_size
    ord_t          order
    flag_t          flag
  


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
    int64_t (*f_basis)(int64_t,int64_t,darr_t*,void*,darr_t*) nogil

    
  cdef enum operEnum :  
    opAdd         =   1 , 
    opSub         =   2 , 
    opMul         =   3 , 
    opTruediv     =   4 , 
    opPowr        =   5 , 
    opInt1d       =   6 , 
    opInt2d       =   7 , 
    opInt3d       =   8 , 
    opDx          =   9 , 
    opDy          =   10, 
    opDz          =   11, 
    opDxx         =   12, 
    opDyy         =   13, 
    opDzz         =   14, 
    opDxy         =   15, 
    opDxz         =   16, 
    opDyz         =   17, 
    opDef         =   18, 
    opOn          =   19, 
    opNeg         =   20, 
    subOpDefBasis =   50, 
    subOpDefKnown =   51, 
    subOpInt      =   52, 
    subOpNeg      =   53, 
    subOpMulRes   =   54, 
    subOpMulKnown =   55, 
    subOpOn       =   56, 
    subOpIntBound =   57, 
    basisN        =  101, 
    basisNx       =  102, 
    basisNxx      =  103, 
    basisNy       =  104, 
    basisNxy      =  105, 
    basisNyy      =  106, 
    basisNz       =  107, 
    basisNxz      =  108, 
    basisNyz      =  109, 
    basisNzz      =  110, 
    kindOtiArr    =  200, 
    kindOtiNum    =  201, 
    kindReal      =  202, 
    kindScalar    =  203, 
    kindFunc      =  204, 
    feConstant    =  301, 
    feVariable    =  302, 
    elNode        =  400, 
    elLine        =  401, 
    elTriangle    =  402, 
    elQuadrangle  =  403, 
    elTetrahedra  =  404, 
    elHexahedra   =  405, 
    elkindIso     =  501, 
    elkindAff     =  502, 
    derN          =  601, 
    derNa         =  602, 
    derNaa        =  603, 
    derNb         =  604, 
    derNab        =  605, 
    derNbb        =  606, 
    derNc         =  607, 
    derNac        =  608, 
    derNbc        =  609, 
    derNcc        =  610, 
    feNatTest     =  701, 
    feNatUndef    =  702, 
    feNatDef      =  703, 
    feNatDefConst =  704, 
    feNatOperRes  =  705, 
    feNatPostIntK =  706, 
    feNatPostIntF =  707, 
    feNatBoundary =  708  

  

  #---------------------------------------------------------------------------------------------------








  # Include functions from "real.h"
  #---------------------------------------------------------------------------------------------------

  darr_t darr_atanh(darr_t* arr);
  void darr_atanh_to(darr_t* arr, darr_t* res);
  darr_t darr_asinh(darr_t* arr);
  void darr_asinh_to(darr_t* arr, darr_t* res);
  darr_t darr_acosh(darr_t* arr);
  void darr_acosh_to(darr_t* arr, darr_t* res);
  darr_t darr_tanh(darr_t* arr);
  void darr_tanh_to(darr_t* arr, darr_t* res);
  darr_t darr_sqrt(darr_t* arr);
  void darr_sqrt_to(darr_t* arr, darr_t* res);
  darr_t darr_cosh(darr_t* arr);
  void darr_cosh_to(darr_t* arr, darr_t* res);
  darr_t darr_sinh(darr_t* arr);
  void darr_sinh_to(darr_t* arr, darr_t* res);
  darr_t darr_asin(darr_t* arr);
  void darr_asin_to(darr_t* arr, darr_t* res);
  darr_t darr_acos(darr_t* arr);
  void darr_acos_to(darr_t* arr, darr_t* res);
  darr_t darr_atan(darr_t* arr);
  void darr_atan_to(darr_t* arr, darr_t* res);
  darr_t darr_tan(darr_t* arr);
  void darr_tan_to(darr_t* arr, darr_t* res);
  darr_t darr_cos(darr_t* arr);
  void darr_cos_to(darr_t* arr, darr_t* res);
  darr_t darr_sin(darr_t* arr );
  void darr_sin_to(darr_t* arr, darr_t* res);
  darr_t darr_logb(darr_t* arr, double base);
  void darr_logb_to(darr_t* arr, double base, darr_t* res);
  darr_t darr_log10(darr_t* arr);
  void darr_log10_to(darr_t* arr, darr_t* res);
  darr_t darr_log(darr_t* arr);
  void darr_log_to(darr_t* arr, darr_t* res);
  darr_t darr_exp(darr_t* arr);
  void darr_exp_to(darr_t* arr, darr_t* res);
  darr_t darr_pow(darr_t* arr, double e);
  void darr_pow_to(darr_t* arr, double e, darr_t* res);

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
  
  darr_t darr_matmul(darr_t* arr1, darr_t* arr2 );
  void darr_matmul_to(darr_t* arr1, darr_t* arr2, darr_t* aRes );

  darr_t darr_transpose(darr_t* arr1);
  void darr_transpose_to(darr_t* arr1, darr_t* aRes);

  darr_t darr_invert(darr_t* arr1);
  void darr_invert_to(darr_t* arr1, darr_t* aRes);

  coeff_t darr_det( darr_t* arr1 );

  void darr_neg_to(darr_t* arr1, darr_t* aRes);
  darr_t darr_neg(darr_t* arr1);
  darr_t darr_div_RR(darr_t* arr1, darr_t* arr2);
  darr_t darr_div_Rr(darr_t* arr1, coeff_t num);
  darr_t darr_div_rR(coeff_t num, darr_t* arr1);
  void darr_div_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
  void darr_div_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes);
  void darr_div_rR_to(coeff_t num, darr_t* arr2, darr_t* aRes);
  darr_t darr_mul_RR(darr_t* arr1, darr_t* arr2);
  darr_t darr_mul_rR(coeff_t num, darr_t* arr1);
  void darr_mul_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
  void darr_mul_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes);
  darr_t darr_sub_RR(darr_t* arr1, darr_t* arr2);
  darr_t darr_sub_Rr(darr_t* arr1, coeff_t num);
  darr_t darr_sub_rR(coeff_t num, darr_t* arr1);
  void darr_sub_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
  void darr_sub_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes);
  void darr_sub_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes);
  darr_t darr_sum_RR(darr_t* arr1, darr_t* arr2);
  darr_t darr_sum_rR(coeff_t num, darr_t* arr1);
  void darr_sum_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
  void darr_sum_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes);
  void darr_set_all( coeff_t num, darr_t* arr);
  coeff_t darr_get_item_ij(darr_t* arr, uint64_t i, uint64_t j);
  coeff_t darr_get_item_i(darr_t* arr, uint64_t i);
  void darr_set_item_ij( coeff_t num, uint64_t i, uint64_t j, darr_t* arr);
  void darr_set_item_i( coeff_t num, uint64_t i, darr_t* arr);
  darr_t   darr_copy(darr_t* src );
  void     darr_copy_to(darr_t* src, darr_t* dst );
  uint64_t darr_getSize(darr_t* arr);
  darr_t darr_ones( uint64_t nrows, uint64_t ncols);
  darr_t darr_zeros( uint64_t nrows, uint64_t ncols);
  void darr_free(darr_t* arr);
  darr_t darr_createEmpty( uint64_t nrows, uint64_t ncols);
  #---------------------------------------------------------------------------------------------------

  # Include functions from "core.h"
  #---------------------------------------------------------------------------------------------------
  coeff_t dhelp_get_deriv_factor(imdir_t idx, ord_t order, dhelpl_t dhl);

  matrix_form_t dhelp_matrix_form_indices( bases_t nbases, ord_t order, dhelpl_t dhl);

  uint8_t  array2d_getel_ui8_t( uint8_t*  arr,uint64_t ncols, uint64_t i, uint64_t j );

  uint16_t array2d_getel_ui16_t(uint16_t* arr,uint64_t ncols, uint64_t i, uint64_t j );

  uint32_t array2d_getel_ui32_t(uint32_t* arr,uint64_t ncols, uint64_t i, uint64_t j );

  uint64_t array2d_getel_ui64_t(uint64_t* arr,uint64_t ncols, uint64_t i, uint64_t j );

  double   array2d_getel_f64_t( double*   arr,uint64_t ncols, uint64_t i, uint64_t j );

  float    array2d_getel_f32_t( float*    arr,uint64_t ncols, uint64_t i, uint64_t j );

  void loadnpy(char* filename, void** data, uint8_t* ndim, uint64_t* shape);

  void loadnpy_multtabls( char* strLocation, ord_t order, bases_t nbasis, dhelp_t* p_dH);

  void loadnpy_ndirs( char* strLocation, ord_t order, bases_t nbasis, dhelp_t* p_dH);

  void loadnpy_fulldir( char* strLocation, ord_t order, bases_t nbasis, dhelp_t* p_dH);

  void dhelp_dense_mult(coeff_t* p_im1, ndir_t ndir1, ord_t ord1, 
                        coeff_t* p_im2, ndir_t ndir2, ord_t ord2, 
                        coeff_t* p_imres, ndir_t ndirres,         
                        dhelpl_t dhl);

  void dhelp_dense_mult_real(coeff_t* p_im1, ndir_t ndir1,
                        coeff_t a,                        
                        coeff_t* p_imres, ndir_t ndirres, 
                        dhelpl_t dhl);                     

  ndir_t dhelp_extract_ndirOrder(bases_t nbases, ord_t order,dhelpl_t dhl);

  ndir_t dhelp_extract_ndirTotal(bases_t nbases, ord_t order,dhelpl_t dhl);

  int64_t dhelp_comb(int64_t a, int64_t b);

  ndir_t dhelp_ndirTotal(bases_t nbases, ord_t order);

  ndir_t dhelp_ndirOrder(bases_t nbases, ord_t order);

  void dhelp_load_singl( char* strLoc, ord_t order, bases_t nbasis, uint64_t nhelps, 
      ndir_t allocSize, dhelp_t* p_dH);

  void dhelp_multDir(imdir_t indx1, ord_t ord1, imdir_t indx2, ord_t ord2, 
      imdir_t* p_ixres, ord_t* p_ores, dhelpl_t dhl);

  void dhelp_freeItem(  dhelp_t* p_dH);

  void dhelp_free( dhelpl_t* dhl);

  void dhelp_load( char* strLocation, dhelpl_t* dhl);

  void dhelp_print( dhelp_t* p_dH);

  void dhelp_printList( const dhelpl_t dhl);

  bases_t* dhelp_get_imdir( imdir_t idx, ord_t order, dhelpl_t dhl);
  #---------------------------------------------------------------------------------------------------


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


  # Include functions from "fem.h"
  #---------------------------------------------------------------------------------------------------
  uint8_t elem_is_started(   elem_t* elem );
  uint8_t elem_is_allocated( elem_t* elem );
  void elem_clear_flag_start(elem_t* elem );
  void elem_clear_flag_alloc(elem_t* elem );
  void elem_raise_flag_start(elem_t* elem );
  void elem_raise_flag_alloc(elem_t* elem );
  int64_t elem_end(elem_t* elem);

  int64_t elem_free( elem_t* elem );
  
  elem_t  elem_init(  );

  int64_t elem_start( elem_t* elem, uint64_t nbasis, int64_t geomBase, int64_t kind, uint8_t  ndim,
                int64_t (*basis_f)( int64_t, int64_t, darr_t*, void*, darr_t*) );

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








#-----------------------------------------------------------------------------------------------------
