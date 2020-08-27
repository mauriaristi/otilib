#ifndef OTI_MDNUM2_ARRAY_UTILS_H
#define OTI_MDNUM2_ARRAY_UTILS_H

/**************************************************************************************************//**
@brief Function that checks dimensions for an elementwise operation.
This function checks that arr1.ncols == arr2.ncols and arr1.nrows = arr2.nrows. It raises an 
Bad Dimension error if dimensions mismatch.

@param[in] arr1 Array.
@param[in] arr2 Array.
******************************************************************************************************/ 
void mdarr2_dimCheck_OO_elementwise(mdarr2_t* arr1, mdarr2_t* arr2, mdarr2_t* res);
void mdarr2_dimCheck_RO_elementwise(darr_t*  arr1, mdarr2_t* arr2, mdarr2_t* res);

void mdarr2_dimCheck_OO_matmul(mdarr2_t* arr1, mdarr2_t* arr2, mdarr2_t* res);
void mdarr2_dimCheck_RO_matmul(darr_t*  arr1, mdarr2_t* arr2, mdarr2_t* res);
void mdarr2_dimCheck_OR_matmul(mdarr2_t* arr1, darr_t*  arr2, mdarr2_t* res);

void mdarr2_dimCheck_O_squareness(mdarr2_t* arr1, mdarr2_t* res);
void mdarr2_dimCheck_OO_samesize(mdarr2_t* arr1, mdarr2_t* res);
void mdarr2_dimCheck_RO_samesize(darr_t* arr1, mdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function to return the order of a Sparse OTI array.

@param[in] arr OTI Array.
******************************************************************************************************/ 
ord_t mdarr2_get_order(mdarr2_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active OTI bases in the array.

@param[in]    arr        Array.
@param[inout] list_vals  Initialized list of values. Must come with all directions deactivated.
@param[in]    dhl        Direction helper list.
******************************************************************************************************/ 
void mdarr2_get_active_bases(mdarr2_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif