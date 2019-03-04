#file c_otilib.pxd

from libc.stdint cimport uint8_t, uint16_t,uint32_t, uint64_t, int64_t
#-----------------------------------------------------------------------------------------------------
#--------------------------------------     TYPE DECLARATIONS     ------------------------------------
#-----------------------------------------------------------------------------------------------------
ctypedef double    coeff_t 
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
    ndir_t        allocSize
    ndir_t            Ntmps
    ndir_t             Ndir
    ord_t             Nmult
    bases_t          Nbasis
    ord_t             order
  
  ctypedef struct dhelpl_t:
    dhelp_t* p_dh
    ndh_t     ndh

  # Defs from "otinum_dense.h"
  ctypedef struct otinum_t:
    coeff_t          re
    coeff_t**      p_im
    ndir_t*      p_ndpo
    ndir_t         ndir
    bases_t      nbases
    ord_t         order

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

  # Defs from "otinum_spr.h"
  ctypedef struct sotinum_t:
    coeff_t          re
    coeff_t**      p_im
    imdir_t**     p_idx
    ndir_t*       p_nnz
    ndir_t*      p_size
    ord_t         order

  

  #---------------------------------------------------------------------------------------------------

  # Include functions from "core.h"
  #---------------------------------------------------------------------------------------------------
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


  # Include functions from "otinum_dense.h"
  #---------------------------------------------------------------------------------------------------
  otinum_t oti_atanh(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_asinh(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_acosh(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_tanh(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_sqrt(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_cosh(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_sinh(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_asin(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_acos(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_atan(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_tan(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_cos(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_sin(otinum_t* num, dhelpl_t dhl );

  otinum_t oti_logb(otinum_t* num, double base, dhelpl_t dhl);

  otinum_t oti_log10(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_log(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_exp(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_pow(otinum_t* num, double e, dhelpl_t dhl);

  otinum_t oti_feval(coeff_t* feval_re, otinum_t* num, dhelpl_t dhl );

  void oti_trunc_ssum(otinum_t* num1,  
                     ord_t ord, otinum_t* res,  dhelpl_t dhl );

  void oti_trunc_mul(otinum_t* num1, ord_t ord1, 
                   otinum_t* num2, ord_t ord2, 
                   otinum_t* res, dhelpl_t dhl );

  void oti_trunc_smul_real(coeff_t a, ord_t ord, otinum_t* num, dhelpl_t dhl);

  otinum_t oti_neg(otinum_t* num1, dhelpl_t dhl);

  otinum_t oti_sub_otireal(otinum_t* num1, coeff_t a, dhelpl_t dhl);

  otinum_t oti_sub_realoti(coeff_t a, otinum_t* num2, dhelpl_t dhl);

  otinum_t oti_sub(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);

  otinum_t oti_div(otinum_t* num, otinum_t* den, dhelpl_t dhl );

  otinum_t oti_div_otireal(otinum_t* num, coeff_t den, dhelpl_t dhl );

  otinum_t oti_div_realoti(coeff_t num, otinum_t* den, dhelpl_t dhl );

  otinum_t oti_mul(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);

  otinum_t oti_mul_real(coeff_t a, otinum_t* num1, dhelpl_t dhl);

  otinum_t oti_sum(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);

  otinum_t oti_copy(otinum_t* num, dhelpl_t dhl);

  otinum_t oti_sum_real(coeff_t a, otinum_t* num1, dhelpl_t dhl);

  void oti_sum_real_r(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl);

  void oti_setIm_IdxOrd( coeff_t a, imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);

  coeff_t oti_get( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);

  coeff_t oti_get_deriv( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);

  otinum_t oti_createZero( bases_t nbases, ord_t order, dhelpl_t dhl);

  otinum_t oti_createEmpty( bases_t nbases, ord_t order, dhelpl_t dhl);

  void oti_set( otinum_t* num, otinum_t* res, dhelpl_t dhl);

  void oti_setFromReal( coeff_t a, otinum_t* num, dhelpl_t dhl);

  void oti_print( otinum_t* num, dhelpl_t dhl);

  void oti_free( otinum_t* num );

  #---------------------------------------------------------------------------------------------------


  # Include functions from "otinum_spr.h"
  #---------------------------------------------------------------------------------------------------
  sotinum_t soti_mul(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
  
  sotinum_t soti_sub(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
  
  sotinum_t soti_sum(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);

  sotinum_t soti_get_tmp(ndir_t ntmp, ord_t order, dhelpl_t dhl);

  sotinum_t soti_div_otireal(sotinum_t* num, coeff_t val, dhelpl_t dhl);

  sotinum_t soti_sub_realoti( coeff_t val, sotinum_t* num, dhelpl_t dhl);

  sotinum_t soti_sub_otireal(sotinum_t* num, coeff_t val, dhelpl_t dhl);

  sotinum_t soti_neg(sotinum_t* num, dhelpl_t dhl);

  sotinum_t soti_mul_real(coeff_t val, sotinum_t* num, dhelpl_t dhl);

  sotinum_t soti_sum_real(coeff_t val, sotinum_t* num, dhelpl_t dhl);

  void soti_insert_item(ndir_t pos, coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);

  void soti_set_item(coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);

  coeff_t soti_get_item(imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);

  sotinum_t soti_copy(sotinum_t* num, dhelpl_t dhl);

  void soti_print(sotinum_t* num, dhelpl_t dhl);

  void soti_free(sotinum_t* num);

  sotinum_t soti_createReal(coeff_t num, ord_t order, dhelpl_t dhl);
  
  sotinum_t soti_createEmpty( ord_t order, dhelpl_t dhl); 
  
  sotinum_t soti_createEmpty_predef(ndir_t* p_nnz, ord_t order, dhelpl_t dhl); 

  #---------------------------------------------------------------------------------------------------


  # Include functions from "otinum_dense.h"
  #---------------------------------------------------------------------------------------------------

#-----------------------------------------------------------------------------------------------------








#-----------------------------------------------------------------------------------------------------
