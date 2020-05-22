


cdef extern from "oti/oti.h" nogil:
  # globals
  int global_test;
  uint64_t is_python_error_def;
  void (*__PY_ERROR_OTI_EXIT)(int64_t) nogil;

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

  # Include functions from "core.h"
  #---------------------------------------------------------------------------------------------------
  void dhelp_div_imdir(imdir_t  numidx, ord_t  numord, 
                       imdir_t  denidx, ord_t  denord,
                       imdir_t* residx, ord_t* resord, 
                          int* success, dhelpl_t dhl);

  void dhelp_get_idx_ord(bases_t* dir, ord_t len, imdir_t* residx, ord_t* resord, dhelpl_t dhl);

  void print_python_error_def( );
  
  void set_global_test(int x);

  void print_global_test();

  void error_exit(int64_t error_id);

  void set_python_error_function(void (*error_function)(int64_t) nogil );

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

