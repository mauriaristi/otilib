#ifndef OTI_ONUMM8N1_ARRAY_GAUSS_BASE_H
#define OTI_ONUMM8N1_ARRAY_GAUSS_BASE_H

void      feoarrm8n1_get_order_im_to( ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
feoarrm8n1_t feoarrm8n1_get_order_im(    ord_t order, feoarrm8n1_t* arr);

feoarrm8n1_t feoarrm8n1_get_deriv(   imdir_t idx, ord_t order, feoarrm8n1_t* arr);
void      feoarrm8n1_get_deriv_to(imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

feoarrm8n1_t feoarrm8n1_get_im(      imdir_t idx, ord_t order, feoarrm8n1_t* arr);
void      feoarrm8n1_get_im_to(   imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

feoarrm8n1_t feoarrm8n1_truncate_im(   imdir_t idx, ord_t order, feoarrm8n1_t* arr);
void      feoarrm8n1_truncate_im_to(imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy Gauss array.

@param[in] src. Item to copy.
@param[in] res  Result.
@param[in] dhl  Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_copy(   feoarrm8n1_t* src);
void      feoarrm8n1_copy_to(feoarrm8n1_t* src, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Imaginary direction getters.

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_get_im(    imdir_t idx, ord_t order, feoarrm8n1_t* arr);
void      feoarrm8n1_get_im_to( imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_get_deriv(    imdir_t idx, ord_t order, feoarrm8n1_t* arr);
void      feoarrm8n1_get_deriv_to( imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Imaginary derivative extractors.

@param[in] idx Imagianry index.
@param[in] order Imagianry index.
@param[in] arr Gauss array.
@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_extract_im(    imdir_t idx, ord_t order, feoarrm8n1_t* arr);
void      feoarrm8n1_extract_im_to( imdir_t idx, ord_t order, feoarrm8n1_t* arr,  feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_extract_deriv(    imdir_t idx, ord_t order, feoarrm8n1_t* arr);
void      feoarrm8n1_extract_deriv_to( imdir_t idx, ord_t order, feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Item getters.

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm8n1_t   feoarrm8n1_get_item_k(  feoarrm8n1_t* arr, uint64_t k);
feonumm8n1_t  feoarrm8n1_get_item_ij( feoarrm8n1_t* arr, uint64_t i, uint64_t j);
onumm8n1_t feoarrm8n1_get_item_ijk(feoarrm8n1_t* arr, uint64_t i, uint64_t j, uint64_t k);

void feoarrm8n1_get_item_ij_to(  feoarrm8n1_t* arr, uint64_t i, uint64_t j, 
                               feonumm8n1_t* res);

void feoarrm8n1_get_item_k_to(   feoarrm8n1_t* arr, uint64_t k, 
                                oarrm8n1_t* res);

void feoarrm8n1_get_item_ijk_to( feoarrm8n1_t* arr, uint64_t i, uint64_t j, uint64_t k, 
                              onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get slice from feoarrm8n1 object.

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
feoarrm8n1_t feoarrm8n1_get_slice(feoarrm8n1_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj);

void      feoarrm8n1_get_slice_to(feoarrm8n1_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Item setters

@param[in] elm   Element to set
@param[in] i     Row.
@param[in] j     Column.
@param[in] k     Integration point.
@param[in] dhl   Direction helper list.
******************************************************************************************************/
void feoarrm8n1_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                            feoarrm8n1_t* res);

void feoarrm8n1_set_item_ij_o(  onumm8n1_t* elm, uint64_t i, uint64_t j,
                             feoarrm8n1_t* res);

void feoarrm8n1_set_item_ij_f(  feonumm8n1_t* elm, uint64_t i, uint64_t j,
                            feoarrm8n1_t* res);

void feoarrm8n1_set_item_k_r(    coeff_t  elm, uint64_t k, 
                            feoarrm8n1_t* res);

void feoarrm8n1_set_item_k_o(  onumm8n1_t* elm, uint64_t k, 
                            feoarrm8n1_t* res);

void feoarrm8n1_set_item_k_R(    oarrm8n1_t* elm, uint64_t k, 
                          feoarrm8n1_t* res);

void feoarrm8n1_set_item_k_O(    oarrm8n1_t* elm, uint64_t k, 
                          feoarrm8n1_t* res);

void feoarrm8n1_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k, 
                             feoarrm8n1_t* res);

void feoarrm8n1_set_item_ijk_o( onumm8n1_t* elm, uint64_t i, uint64_t j, uint64_t k, 
                             feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set slice to feoarrm8n1 object.

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
void feoarrm8n1_set_slice_r( coeff_t val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          feoarrm8n1_t* res);
void feoarrm8n1_set_slice_o( onumm8n1_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          feoarrm8n1_t* res);
void feoarrm8n1_set_slice_f( feonumm8n1_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          feoarrm8n1_t* res);
void feoarrm8n1_set_slice_O( oarrm8n1_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          feoarrm8n1_t* res);
void feoarrm8n1_set_slice_F( feoarrm8n1_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Broadcasted setter.

@param[in]
@param[in] dhl Direction helper list.
******************************************************************************************************/
void feoarrm8n1_set_all_o( onumm8n1_t* num, feoarrm8n1_t* arr );
void feoarrm8n1_set_all_r(   coeff_t  num, feoarrm8n1_t* arr );
void feoarrm8n1_set_all_f(  feonumm8n1_t* num, feoarrm8n1_t* arr );

void feoarrm8n1_set_r(    coeff_t src, feoarrm8n1_t* res );
void feoarrm8n1_set_o( onumm8n1_t* src, feoarrm8n1_t* res );
void feoarrm8n1_set_f(  feonumm8n1_t* src, feoarrm8n1_t* res );

void feoarrm8n1_set_R(    darr_t* src, feoarrm8n1_t* res );
void feoarrm8n1_set_O(   oarrm8n1_t* src, feoarrm8n1_t* res );
void feoarrm8n1_set_F( feoarrm8n1_t* src, feoarrm8n1_t* res );

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
feoarrm8n1_t feoarrm8n1_eye( uint64_t size,  uint64_t nip);
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
feoarrm8n1_t feoarrm8n1_zeros(  uint64_t nrows,   uint64_t ncols, uint64_t nip    );
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
feoarrm8n1_t feoarrm8n1_ones( uint64_t nrows,   uint64_t ncols, uint64_t nip     );
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
feoarrm8n1_t feoarrm8n1_createEmpty( uint64_t nrows,   uint64_t ncols, uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory of Gauss array.

@param[in] arr. Gauss array to free memory.
******************************************************************************************************/
void feoarrm8n1_free(feoarrm8n1_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of Gauss array

******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_init(void);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get the max trunctation order of the OTI structure.

@param[in] arr. Gauss array.
@param[in] dhl. Direction helper list.
@param[out] ord. Maximum truncation order.
******************************************************************************************************/
ord_t feoarrm8n1_get_order(feoarrm8n1_t* arr);
// ----------------------------------------------------------------------------------------------------

#endif