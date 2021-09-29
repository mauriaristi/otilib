#ifndef OTI_SEMISPARSE_ARRAY_BASE_H
#define OTI_SEMISPARSE_ARRAY_BASE_H


/**************************************************************************************************//**
@brief Perform taylor series evaluation given the array of deltas..

@param[in]    deltas Array of delta values for every imaginary basis.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
void    arrsso_taylor_integrate_to( coeff_t* deltas, arrsso_t* arr, arrsso_t* res, dhelpl_t dhl);
arrsso_t arrsso_taylor_integrate(    coeff_t* deltas, arrsso_t* arr,               dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get all imaginary coefficients of given order in arrso object.

@param[in]    order  Order to get data from.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
void    arrsso_get_order_im_to( ord_t order, arrsso_t* arr, arrsso_t* res, dhelpl_t dhl);
arrsso_t arrsso_get_order_im(    ord_t order, arrsso_t* arr,               dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set slice to arrso object.

@param[in]    val    Value to set in res array.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
void arrsso_set_slice_r( coeff_t val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrsso_t* res, dhelpl_t dhl);
void arrsso_set_slice_O( arrsso_t* val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrsso_t* res, dhelpl_t dhl);
void arrsso_set_slice_o( semiotin_t* val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get slice from arrso object.

@param[in]    arr    Address of array from which to get data.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_get_slice( arrsso_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                        dhelpl_t dhl);
void arrsso_get_slice_to( arrsso_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate imaginary direction in arrso object.

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_truncate_im(    imdir_t idx, ord_t order, arrsso_t* arr,               dhelpl_t dhl);
void    arrsso_truncate_im_to( imdir_t idx, ord_t order, arrsso_t* arr, arrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Imaignary direction extractor from arrso object..

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_extract_im(   imdir_t idx, ord_t order, arrsso_t* arr,               dhelpl_t dhl);
void    arrsso_extract_im_to(imdir_t idx, ord_t order, arrsso_t* arr, arrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get derivative from arrso object..

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
darr_t  arrsso_get_deriv(    imdir_t idx, ord_t order, arrsso_t* arr,               dhelpl_t dhl);
void    arrsso_get_deriv_to( imdir_t idx, ord_t order, arrsso_t* arr, arrsso_t* res, dhelpl_t dhl);
arrsso_t arrsso_get_deriv_o(  imdir_t idx, ord_t order, arrsso_t* arr,               dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivative extractor from arrso object.

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_extract_deriv(    imdir_t idx, ord_t order, arrsso_t* arr,               dhelpl_t dhl);
void    arrsso_extract_deriv_to( imdir_t idx, ord_t order, arrsso_t* arr, arrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get imaginary direction from arrso object..

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
darr_t  arrsso_get_im(   imdir_t idx, ord_t order, arrsso_t* arr,               dhelpl_t dhl);
arrsso_t arrsso_get_im_o( imdir_t idx, ord_t order, arrsso_t* arr,               dhelpl_t dhl);
void    arrsso_get_im_to(imdir_t idx, ord_t order, arrsso_t* arr, arrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy an existing array. Data is copied to the new memory.

@param[in] arr    Address of array from which to get data.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
void    arrsso_copy_to(arrsso_t* arr, arrsso_t* res, dhelpl_t dhl);
arrsso_t arrsso_copy(arrsso_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Setter functions. These functions sets the specified elements of an array given a real number.

******************************************************************************************************/ 
void arrsso_set_all_r( coeff_t num, arrsso_t* arr, dhelpl_t dhl);
void arrsso_set_item_i_r( coeff_t num, uint64_t i, arrsso_t* arr, dhelpl_t dhl);
void arrsso_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, arrsso_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void arrsso_set_r(   coeff_t  num,   arrsso_t* arr, dhelpl_t dhl);
void arrsso_set_o( semiotin_t* num,   arrsso_t* arr, dhelpl_t dhl);
void arrsso_set_O(   arrsso_t* arrin, arrsso_t* arr, dhelpl_t dhl);

/**************************************************************************************************//**
@brief Setter functions. These functions sets the specified elements of an array given an OTI number.

******************************************************************************************************/ 
void arrsso_set_all_o( semiotin_t* src, arrsso_t* arr, dhelpl_t dhl);
void arrsso_set_item_i_o( semiotin_t* num, uint64_t i, arrsso_t* arr, dhelpl_t dhl);
void arrsso_set_item_ij_o( semiotin_t* num, uint64_t i, uint64_t j, arrsso_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Getter functions. These functions extract a member of the array.

******************************************************************************************************/ 
semiotin_t arrsso_get_item_i(    arrsso_t* arr, uint64_t i,                             dhelpl_t dhl);
void      arrsso_get_item_i_to( arrsso_t* arr, uint64_t i,             semiotin_t* res, dhelpl_t dhl);
semiotin_t arrsso_get_item_ij(   arrsso_t* arr, uint64_t i, uint64_t j,                 dhelpl_t dhl);
void      arrsso_get_item_ij_to(arrsso_t* arr, uint64_t i, uint64_t j, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Initialization of the arrsso_t type. In this case, all pointers are initialized to NULL to avoid
       unwanted segmentation faults.

       Usage is as follows:
       arrsso_t myArray = arrsso_init();

******************************************************************************************************/ 
arrsso_t arrsso_init(void);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of the arrsso_t type. In this case, all pointers are initialized to NULL to avoid
       unwanted segmentation faults.

       Usage is as follows:
       arrsso_t myArray = arrsso_init();

******************************************************************************************************/ 
void arrsso_free(arrsso_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an empty array similar in order, allocation size and shape from the given array.

@param[in] arr    Address of array from which to get the allocation information.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_empty_like(arrsso_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an identity array, all zeros and diagonal all ones. All members defined as sparse oti 
       numbers. This is allocated given the number of imagianary directions per order in p_nnz.

@param[in] nrows  Number of rows of the array (This array is square).
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_eye(uint64_t nrows, ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
arrsso_t arrsso_eye_bases(uint64_t nrows, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an array filled with ones, defined as sparse oti numbers. This is allocated given the
       number of imagianry directions per order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_ones(uint64_t nrows, uint64_t ncols, ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
arrsso_t arrsso_ones_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an array filled with zeros, defined as sparse oti numbers. This is allocated given the
       number of imagianry directions per order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_zeros(uint64_t nrows, uint64_t ncols, ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
arrsso_t arrsso_zeros_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an empty array of sparse oti numbers. This is allocated given the
       number of imagianry directions per order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_createEmpty_predef(uint64_t nrows, uint64_t ncols, ndir_t* p_nnz, ord_t order, dhelpl_t dhl);
arrsso_t arrsso_createEmpty_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an array filled with zeros, defined as sparse oti numbers. This is allocated given
       ammount of memory to allocate for each order, in p_nnz.

@param[in] nrows  Number of rows of the array.
@param[in] ncols  Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
size_t arrsso_memory_size( uint64_t size, ndir_t* p_nnz, ord_t order);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Create an array filled with zeros, defined as sparse oti numbers. This is allocated given
       ammount of memory to allocate for each order, in p_nnz.

@param[in] mem   Number of rows of the array.
@param[in] ncols Number of columns of the array.
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order Truncation order of the array.
@param[in] dhl   Direction helper list object.
******************************************************************************************************/ 
void arrsso_distribute_memory(void* mem, uint64_t nrows, uint64_t ncols, ndir_t* p_nnz, ord_t order, 
    flag_t flag, arrsso_t* res);
// ----------------------------------------------------------------------------------------------------


void arrsso_save(char* filename, arrsso_t* arr, dhelpl_t dhl);
arrsso_t arrsso_read(char* filename, dhelpl_t dhl);

#endif