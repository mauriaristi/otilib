#ifndef OTI_SPARSE_ARRAY_UTILS_H
#define OTI_SPARSE_ARRAY_UTILS_H

/**************************************************************************************************//**
@brief Function that checks dimensions for an elementwise operation.
This function checks that arr1.ncols == arr2.ncols and arr1.nrows = arr2.nrows. It raises an 
Bad Dimension error if dimensions mismatch.

@param[in] arr1 Array.
@param[in] arr2 Array.
******************************************************************************************************/ 
void arrso_dimCheck_OO_elementwise(arrso_t* arr1, arrso_t* arr2, arrso_t* res);
void arrso_dimCheck_RO_elementwise(darr_t*  arr1, arrso_t* arr2, arrso_t* res);

void arrso_dimCheck_OO_matmul(arrso_t* arr1, arrso_t* arr2, arrso_t* res);
void arrso_dimCheck_RO_matmul(darr_t*  arr1, arrso_t* arr2, arrso_t* res);
void arrso_dimCheck_OR_matmul(arrso_t* arr1, darr_t*  arr2, arrso_t* res);

void arrso_dimCheck_O_squareness(arrso_t* arr1, arrso_t* res);
void arrso_dimCheck_OO_samesize(arrso_t* arr1, arrso_t* res);
void arrso_dimCheck_RO_samesize(darr_t* arr1, arrso_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Function to return the order of a Sparse OTI array.

@param[in] arr OTI Array.
******************************************************************************************************/ 
ord_t arrso_get_order(arrso_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active OTI bases in the array.

@param[in]    arr        Array.
@param[inout] list_vals  Initialized list of values. Must come with all directions deactivated.
@param[in]    dhl        Direction helper list.
******************************************************************************************************/ 
void arrso_get_active_bases(arrso_t* arr, imdir_t* list_vals, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

#endif