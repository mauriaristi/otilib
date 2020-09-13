#ifndef OTI_MDNUM8_ARRAY_UTILS_H
#define OTI_MDNUM8_ARRAY_UTILS_H

/**************************************************************************************************//**
@brief Function that checks dimensions for an elementwise operation.
This function checks that arr1.ncols == arr2.ncols and arr1.nrows = arr2.nrows. It raises an 
Bad Dimension error if dimensions mismatch.

@param[in] arr1 Array.
@param[in] arr2 Array.
******************************************************************************************************/ 
void mdarr8_dimCheck_OO_elementwise(mdarr8_t* arr1, mdarr8_t* arr2, mdarr8_t* res);
void mdarr8_dimCheck_RO_elementwise(darr_t*  arr1, mdarr8_t* arr2, mdarr8_t* res);

void mdarr8_dimCheck_OO_matmul(mdarr8_t* arr1, mdarr8_t* arr2, mdarr8_t* res);
void mdarr8_dimCheck_RO_matmul(darr_t*  arr1, mdarr8_t* arr2, mdarr8_t* res);
void mdarr8_dimCheck_OR_matmul(mdarr8_t* arr1, darr_t*  arr2, mdarr8_t* res);

void mdarr8_dimCheck_O_squareness(mdarr8_t* arr1, mdarr8_t* res);
void mdarr8_dimCheck_OO_samesize(mdarr8_t* arr1, mdarr8_t* res);
void mdarr8_dimCheck_RO_samesize(darr_t* arr1, mdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function to return the order of a Sparse OTI array.

@param[in] arr OTI Array.
******************************************************************************************************/ 
ord_t mdarr8_get_order(mdarr8_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active OTI bases in the array.

@param[in]    arr        Array.
@param[inout] list_vals  Initialized list of values. Must come with all directions deactivated.
@param[in]    dhl        Direction helper list.
******************************************************************************************************/ 
void mdarr8_get_active_bases(mdarr8_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif