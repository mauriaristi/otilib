#ifndef OTI_MDNUM9_ARRAY_BASE_H
#define OTI_MDNUM9_ARRAY_BASE_H

/**************************************************************************************************//**
@brief Perform taylor series evaluation given the array of deltas..

@param[in]    deltas Array of delta values for every imaginary basis.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
void    mdarr9_taylor_integrate_to( coeff_t* deltas, mdarr9_t* arr, mdarr9_t* res);
mdarr9_t mdarr9_taylor_integrate(    coeff_t* deltas, mdarr9_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get all imaginary coefficients of given order in mdarr9 object.

@param[in]    order  Order to get data from.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
void    mdarr9_get_order_im_to( ord_t order, mdarr9_t* arr, mdarr9_t* res);
mdarr9_t mdarr9_get_order_im(    ord_t order, mdarr9_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set slice to mdarr9 object.

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
void mdarr9_set_slice_r( coeff_t val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         mdarr9_t* res);
void mdarr9_set_slice_O( mdarr9_t* val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         mdarr9_t* res);
void mdarr9_set_slice_o( mdnum9_t* val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get slice from mdarr9 object.

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
mdarr9_t mdarr9_get_slice( mdarr9_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj);
void mdarr9_get_slice_to( mdarr9_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate imaginary direction in mdarr9 object.

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr9_t mdarr9_truncate_im(    imdir_t idx, ord_t order, mdarr9_t* arr);
void    mdarr9_truncate_im_to( imdir_t idx, ord_t order, mdarr9_t* arr, mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Imaignary direction extractor from mdarr9 object..

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr9_t mdarr9_extract_im(   imdir_t idx, ord_t order, mdarr9_t* arr);
void    mdarr9_extract_im_to(imdir_t idx, ord_t order, mdarr9_t* arr, mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get derivative from mdarr9 object..

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
darr_t  mdarr9_get_deriv(    imdir_t idx, ord_t order, mdarr9_t* arr);
void    mdarr9_get_deriv_to( imdir_t idx, ord_t order, mdarr9_t* arr, mdarr9_t* res);
mdarr9_t mdarr9_get_deriv_o(  imdir_t idx, ord_t order, mdarr9_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivative extractor from mdarr9 object.

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr9_t mdarr9_extract_deriv(    imdir_t idx, ord_t order, mdarr9_t* arr);
void    mdarr9_extract_deriv_to( imdir_t idx, ord_t order, mdarr9_t* arr, mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get imaginary direction from mdarr9 object..

@param[in]    idx    Imaginary index.
@param[in]    order  Order of the imaignary direction.
@param[in]    arr    Address of array from which to get data.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
darr_t  mdarr9_get_im(   imdir_t idx, ord_t order, mdarr9_t* arr);
mdarr9_t mdarr9_get_im_o( imdir_t idx, ord_t order, mdarr9_t* arr);
void    mdarr9_get_im_to(imdir_t idx, ord_t order, mdarr9_t* arr, mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy an existing array. Data is copied to the new memory.

@param[in] arr    Address of array from which to get data.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
void    mdarr9_copy_to(mdarr9_t* arr, mdarr9_t* res);
mdarr9_t mdarr9_copy(mdarr9_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Setter functions. These functions sets the specified elements of an array given a real number.

******************************************************************************************************/ 
void mdarr9_set_all_r( coeff_t num, mdarr9_t* arr);
void mdarr9_set_item_i_r( coeff_t num, uint64_t i, mdarr9_t* arr);
void mdarr9_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, mdarr9_t* arr);
// ----------------------------------------------------------------------------------------------------

void mdarr9_set_r(   coeff_t  num,   mdarr9_t* arr);
void mdarr9_set_o( mdnum9_t* num,   mdarr9_t* arr);
void mdarr9_set_O(   mdarr9_t* arrin, mdarr9_t* arr);

/**************************************************************************************************//**
@brief Setter functions. These functions sets the specified elements of an array given an OTI number.

******************************************************************************************************/ 
void mdarr9_set_all_o( mdnum9_t* src, mdarr9_t* arr);
void mdarr9_set_item_i_o( mdnum9_t* num, uint64_t i, mdarr9_t* arr);
void mdarr9_set_item_ij_o( mdnum9_t* num, uint64_t i, uint64_t j, mdarr9_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Getter functions. These functions extract a member of the array.

******************************************************************************************************/ 
mdnum9_t mdarr9_get_item_i(    mdarr9_t* arr, uint64_t i);
void      mdarr9_get_item_i_to( mdarr9_t* arr, uint64_t i,             mdnum9_t* res);
mdnum9_t mdarr9_get_item_ij(   mdarr9_t* arr, uint64_t i, uint64_t j);
void      mdarr9_get_item_ij_to(mdarr9_t* arr, uint64_t i, uint64_t j, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of the mdarr9_t type. In this case, all pointers are initialized to NULL to avoid
       unwanted segmentation faults.

       Usage is as follows:
       mdarr9_t myArray = mdarr9_init();

******************************************************************************************************/ 
mdarr9_t mdarr9_init(void);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of the mdarr9_t type. In this case, all pointers are initialized to NULL to avoid
       unwanted segmentation faults.

       Usage is as follows:
       mdarr9_t myArray = mdarr9_init();

******************************************************************************************************/ 
void mdarr9_free(mdarr9_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an empty array similar in order, allocation size and shape from the given array.

@param[in] arr    Address of array from which to get the allocation information.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr9_t mdarr9_empty_like(mdarr9_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an identity array, all zeros and diagonal all ones. All members defined as sparse oti 
       numbers. This is allocated given the number of imagianary directions per order in p_nnz.

@param[in] nrows  Number of rows of the array (This array is square).
@param[in] p_nnz  Array with the number of im dir to allocate for each order.
@param[in] order  Truncation order of the array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr9_t mdarr9_eye(uint64_t nrows);
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
mdarr9_t mdarr9_ones(uint64_t nrows, uint64_t ncols);
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
mdarr9_t mdarr9_zeros(uint64_t nrows, uint64_t ncols);
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
mdarr9_t mdarr9_createEmpty(uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

#endif