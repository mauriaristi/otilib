#ifndef OTI_MDNUM3_ARRAY_GAUSS_BASE_H
#define OTI_MDNUM3_ARRAY_GAUSS_BASE_H

void      femdarr3_get_order_im_to( ord_t order, femdarr3_t* arr, femdarr3_t* res);
femdarr3_t femdarr3_get_order_im(    ord_t order, femdarr3_t* arr);

femdarr3_t femdarr3_get_deriv(   imdir_t idx, ord_t order, femdarr3_t* arr);
void      femdarr3_get_deriv_to(imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

femdarr3_t femdarr3_get_im(      imdir_t idx, ord_t order, femdarr3_t* arr);
void      femdarr3_get_im_to(   imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

femdarr3_t femdarr3_truncate_im(   imdir_t idx, ord_t order, femdarr3_t* arr);
void      femdarr3_truncate_im_to(imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy Gauss array.

@param[in] src. Item to copy.
@param[in] res  Result.
@param[in] dhl  Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_copy(   femdarr3_t* src);
void      femdarr3_copy_to(femdarr3_t* src, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Imaginary direction getters.

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_get_im(    imdir_t idx, ord_t order, femdarr3_t* arr);
void      femdarr3_get_im_to( imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);

femdarr3_t femdarr3_get_deriv(    imdir_t idx, ord_t order, femdarr3_t* arr);
void      femdarr3_get_deriv_to( imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Imaginary derivative extractors.

@param[in] idx Imagianry index.
@param[in] order Imagianry index.
@param[in] arr Gauss array.
@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_extract_im(    imdir_t idx, ord_t order, femdarr3_t* arr);
void      femdarr3_extract_im_to( imdir_t idx, ord_t order, femdarr3_t* arr,  femdarr3_t* res);

femdarr3_t femdarr3_extract_deriv(    imdir_t idx, ord_t order, femdarr3_t* arr);
void      femdarr3_extract_deriv_to( imdir_t idx, ord_t order, femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Item getters.

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdarr3_t   femdarr3_get_item_k(  femdarr3_t* arr, uint64_t k);
femdnum3_t  femdarr3_get_item_ij( femdarr3_t* arr, uint64_t i, uint64_t j);
mdnum3_t femdarr3_get_item_ijk(femdarr3_t* arr, uint64_t i, uint64_t j, uint64_t k);

void femdarr3_get_item_ij_to(  femdarr3_t* arr, uint64_t i, uint64_t j, 
                               femdnum3_t* res);

void femdarr3_get_item_k_to(   femdarr3_t* arr, uint64_t k, 
                                mdarr3_t* res);

void femdarr3_get_item_ijk_to( femdarr3_t* arr, uint64_t i, uint64_t j, uint64_t k, 
                              mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get slice from femdarr3 object.

@param[in]    arr    array to get slice.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder (if any)
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
femdarr3_t femdarr3_get_slice(femdarr3_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                           dhelpl_t dhl);

void      femdarr3_get_slice_to(femdarr3_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Item setters

@param[in] elm   Element to set
@param[in] i     Row.
@param[in] j     Column.
@param[in] k     Integration point.
@param[in] dhl   Direction helper list.
******************************************************************************************************/
void femdarr3_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                            femdarr3_t* res);

void femdarr3_set_item_ij_o(  mdnum3_t* elm, uint64_t i, uint64_t j,
                             femdarr3_t* res);

void femdarr3_set_item_ij_f(  femdnum3_t* elm, uint64_t i, uint64_t j,
                            femdarr3_t* res);

void femdarr3_set_item_k_r(    coeff_t  elm, uint64_t k, 
                            femdarr3_t* res);

void femdarr3_set_item_k_o(  mdnum3_t* elm, uint64_t k, 
                            femdarr3_t* res);

void femdarr3_set_item_k_R(    mdarr3_t* elm, uint64_t k, 
                          femdarr3_t* res);

void femdarr3_set_item_k_O(    mdarr3_t* elm, uint64_t k, 
                          femdarr3_t* res);

void femdarr3_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k, 
                             femdarr3_t* res);

void femdarr3_set_item_ijk_o( mdnum3_t* elm, uint64_t i, uint64_t j, uint64_t k, 
                             femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set slice to femdarr3 object.

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
void femdarr3_set_slice_r( coeff_t val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          femdarr3_t* res);
void femdarr3_set_slice_o( mdnum3_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          femdarr3_t* res);
void femdarr3_set_slice_f( femdnum3_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          femdarr3_t* res);
void femdarr3_set_slice_O( mdarr3_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          femdarr3_t* res);
void femdarr3_set_slice_F( femdarr3_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Broadcasted setter.

@param[in]
@param[in] dhl Direction helper list.
******************************************************************************************************/
void femdarr3_set_all_o( mdnum3_t* num, femdarr3_t* arr );
void femdarr3_set_all_r(   coeff_t  num, femdarr3_t* arr );
void femdarr3_set_all_f(  femdnum3_t* num, femdarr3_t* arr );

void femdarr3_set_r(    coeff_t src, femdarr3_t* res );
void femdarr3_set_o( mdnum3_t* src, femdarr3_t* res );
void femdarr3_set_f(  femdnum3_t* src, femdarr3_t* res );

void femdarr3_set_R(    darr_t* src, femdarr3_t* res );
void femdarr3_set_O(   mdarr3_t* src, femdarr3_t* res );
void femdarr3_set_F( femdarr3_t* src, femdarr3_t* res );

// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss array as the identity matrix.

@param[in] size     Size of the matrix (final shape: <size,size>)
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_eye( uint64_t size,  uint64_t nip);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss array of Zeros.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss array of ones.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an empty gauss object.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory of Gauss array.

@param[in] arr. Gauss array to free memory.
******************************************************************************************************/
void femdarr3_free(femdarr3_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of Gauss array

******************************************************************************************************/
femdarr3_t femdarr3_init(void);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get the max trunctation order of the OTI structure.

@param[in] arr. Gauss array.
@param[in] dhl. Direction helper list.
@param[out] ord. Maximum truncation order.
******************************************************************************************************/
ord_t femdarr3_get_order(femdarr3_t* arr);
// ----------------------------------------------------------------------------------------------------

#endif