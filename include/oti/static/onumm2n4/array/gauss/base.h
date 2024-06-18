#ifndef OTI_ONUMM2N4_ARRAY_GAUSS_BASE_H
#define OTI_ONUMM2N4_ARRAY_GAUSS_BASE_H

void      feoarrm2n4_get_order_im_to( ord_t order, feoarrm2n4_t* arr, feoarrm2n4_t* res);
feoarrm2n4_t feoarrm2n4_get_order_im(    ord_t order, feoarrm2n4_t* arr);

feoarrm2n4_t feoarrm2n4_get_deriv(   imdir_t idx, ord_t order, feoarrm2n4_t* arr);
void      feoarrm2n4_get_deriv_to(imdir_t idx, ord_t order, feoarrm2n4_t* arr, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

feoarrm2n4_t feoarrm2n4_get_im(      imdir_t idx, ord_t order, feoarrm2n4_t* arr);
void      feoarrm2n4_get_im_to(   imdir_t idx, ord_t order, feoarrm2n4_t* arr, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

feoarrm2n4_t feoarrm2n4_truncate_im(   imdir_t idx, ord_t order, feoarrm2n4_t* arr);
void      feoarrm2n4_truncate_im_to(imdir_t idx, ord_t order, feoarrm2n4_t* arr, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy Gauss array.

@param[in] src. Item to copy.
@param[in] res  Result.
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm2n4_t feoarrm2n4_copy(   feoarrm2n4_t* src);
void      feoarrm2n4_copy_to(feoarrm2n4_t* src, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Imaginary direction getters.

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n4_t feoarrm2n4_get_im(    imdir_t idx, ord_t order, feoarrm2n4_t* arr);
void      feoarrm2n4_get_im_to( imdir_t idx, ord_t order, feoarrm2n4_t* arr, feoarrm2n4_t* res);

feoarrm2n4_t feoarrm2n4_get_deriv(    imdir_t idx, ord_t order, feoarrm2n4_t* arr);
void      feoarrm2n4_get_deriv_to( imdir_t idx, ord_t order, feoarrm2n4_t* arr, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Imaginary derivative extractors.

@param[in] idx Imagianry index.
@param[in] order Imagianry index.
@param[in] arr Gauss array.
@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n4_t feoarrm2n4_extract_im(    imdir_t idx, ord_t order, feoarrm2n4_t* arr);
void      feoarrm2n4_extract_im_to( imdir_t idx, ord_t order, feoarrm2n4_t* arr,  feoarrm2n4_t* res);

feoarrm2n4_t feoarrm2n4_extract_deriv(    imdir_t idx, ord_t order, feoarrm2n4_t* arr);
void      feoarrm2n4_extract_deriv_to( imdir_t idx, ord_t order, feoarrm2n4_t* arr, feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Item getters.

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm2n4_t   feoarrm2n4_get_item_k(  feoarrm2n4_t* arr, uint64_t k);
feonumm2n4_t  feoarrm2n4_get_item_ij( feoarrm2n4_t* arr, uint64_t i, uint64_t j);
onumm2n4_t feoarrm2n4_get_item_ijk(feoarrm2n4_t* arr, uint64_t i, uint64_t j, uint64_t k);

void feoarrm2n4_get_item_ij_to(  feoarrm2n4_t* arr, uint64_t i, uint64_t j, 
                               feonumm2n4_t* res);

void feoarrm2n4_get_item_k_to(   feoarrm2n4_t* arr, uint64_t k, 
                                oarrm2n4_t* res);

void feoarrm2n4_get_item_ijk_to( feoarrm2n4_t* arr, uint64_t i, uint64_t j, uint64_t k, 
                              onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get slice from feoarrm2n4 object.

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
feoarrm2n4_t feoarrm2n4_get_slice(feoarrm2n4_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);

void      feoarrm2n4_get_slice_to(feoarrm2n4_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Item setters

@param[in] elm   Element to set
@param[in] i     Row.
@param[in] j     Column.
@param[in] k     Integration point.
@param[in] dhl   Direction helper list.
******************************************************************************************************/
void feoarrm2n4_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                            feoarrm2n4_t* res);

void feoarrm2n4_set_item_ij_o(  onumm2n4_t* elm, uint64_t i, uint64_t j,
                             feoarrm2n4_t* res);

void feoarrm2n4_set_item_ij_f(  feonumm2n4_t* elm, uint64_t i, uint64_t j,
                            feoarrm2n4_t* res);

void feoarrm2n4_set_item_k_r(    coeff_t  elm, uint64_t k, 
                            feoarrm2n4_t* res);

void feoarrm2n4_set_item_k_o(  onumm2n4_t* elm, uint64_t k, 
                            feoarrm2n4_t* res);

void feoarrm2n4_set_item_k_R(    oarrm2n4_t* elm, uint64_t k, 
                          feoarrm2n4_t* res);

void feoarrm2n4_set_item_k_O(    oarrm2n4_t* elm, uint64_t k, 
                          feoarrm2n4_t* res);

void feoarrm2n4_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k, 
                             feoarrm2n4_t* res);

void feoarrm2n4_set_item_ijk_o( onumm2n4_t* elm, uint64_t i, uint64_t j, uint64_t k, 
                             feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set slice to feoarrm2n4 object.

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
void feoarrm2n4_set_slice_r( coeff_t val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          feoarrm2n4_t* res);
void feoarrm2n4_set_slice_o( onumm2n4_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          feoarrm2n4_t* res);
void feoarrm2n4_set_slice_f( feonumm2n4_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          feoarrm2n4_t* res);
void feoarrm2n4_set_slice_O( oarrm2n4_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          feoarrm2n4_t* res);
void feoarrm2n4_set_slice_F( feoarrm2n4_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          feoarrm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Broadcasted setter.

@param[in]
@param[in] dhl Direction helper list.
******************************************************************************************************/
void feoarrm2n4_set_all_o( onumm2n4_t* num, feoarrm2n4_t* arr );
void feoarrm2n4_set_all_r(   coeff_t  num, feoarrm2n4_t* arr );
void feoarrm2n4_set_all_f(  feonumm2n4_t* num, feoarrm2n4_t* arr );

void feoarrm2n4_set_r(    coeff_t src, feoarrm2n4_t* res );
void feoarrm2n4_set_o( onumm2n4_t* src, feoarrm2n4_t* res );
void feoarrm2n4_set_f(  feonumm2n4_t* src, feoarrm2n4_t* res );

void feoarrm2n4_set_R(    darr_t* src, feoarrm2n4_t* res );
void feoarrm2n4_set_O(   oarrm2n4_t* src, feoarrm2n4_t* res );
void feoarrm2n4_set_F( feoarrm2n4_t* src, feoarrm2n4_t* res );

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
feoarrm2n4_t feoarrm2n4_eye( uint64_t size,  uint64_t nip);
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
feoarrm2n4_t feoarrm2n4_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
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
feoarrm2n4_t feoarrm2n4_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
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
feoarrm2n4_t feoarrm2n4_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory of Gauss array.

@param[in] arr. Gauss array to free memory.
******************************************************************************************************/
void feoarrm2n4_free(feoarrm2n4_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of Gauss array

******************************************************************************************************/
feoarrm2n4_t feoarrm2n4_init(void);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get the max trunctation order of the OTI structure.

@param[in] arr. Gauss array.
@param[in] dhl. Direction helper list.
@param[out] ord. Maximum truncation order.
******************************************************************************************************/
ord_t feoarrm2n4_get_order(feoarrm2n4_t* arr);
// ----------------------------------------------------------------------------------------------------

#endif