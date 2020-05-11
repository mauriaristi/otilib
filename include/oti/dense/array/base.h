#ifndef OTI_DENSE_ARRAY_BASE_H
#define OTI_DENSE_ARRAY_BASE_H


/**************************************************************************************************//**
@brief Set an element of an OTI array by either a real coefficient or an oti number.

ARR[i,j] = num

@param[in] num Number to be set.
@param[in] i Row to set the element.
@param[in] j Column to set the element.
@param[in] arr Array to place the new elet
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oarr_set_all_r(     coeff_t num,                         oarr_t* arr, dhelpl_t dhl);
void oarr_set_item_i_r(  coeff_t num, uint64_t i,             oarr_t* arr, dhelpl_t dhl);
void oarr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl);

void oarr_set_all_o(     otinum_t* num,                         oarr_t* arr, dhelpl_t dhl);
void oarr_set_item_i_o(  otinum_t* num, uint64_t i,             oarr_t* arr, dhelpl_t dhl);
void oarr_set_item_ij_o( otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Getter functions. Extract an element of an OTI array.

res = ARR[i,j]

@param[in] arr Array to extract the new element.
@param[in] i   Row where the element is located.
@param[in] j   Column where the element is located
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oarr_get_item_i(  oarr_t* arr, uint64_t i,             dhelpl_t dhl);
otinum_t oarr_get_item_ij( oarr_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl);

void oarr_get_item_i_to(   oarr_t* arr, uint64_t i,             otinum_t* res, dhelpl_t dhl);
void oarr_get_item_ij_to(  oarr_t* arr, uint64_t i, uint64_t j, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy an oti array.

@param[in] 
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
oarr_t oarr_copy(   oarr_t* arr,              dhelpl_t dhl);
void   oarr_copy_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory of an OTI array that has been allocated.

@param[in] 
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oarr_free(oarr_t* arr);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Create an identity matrix.

@param[in] size Size of the matrix to be created (creates a 2d matrix with shape  size x size )
@param[in] nbases Number of bases of the OTI number.
@param[in] order Truncation order of the imaginary number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
oarr_t oarr_eye(uint64_t size, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Create an array filled with ones.

@param[in] nrows Number of rows of the array
@param[in] ncols Number of columns of the array
@param[in] nbases Number of bases of the OTI number.
@param[in] order Truncation order of the imaginary number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
oarr_t oarr_ones(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Create an array filled with zeros.

@param[in] nrows Number of rows of the array
@param[in] ncols Number of columns of the array
@param[in] nbases Number of bases of the OTI number.
@param[in] order Truncation order of the imaginary number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
oarr_t oarr_zeros(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in] 
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
oarr_t oarr_createEmpty( uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

#endif