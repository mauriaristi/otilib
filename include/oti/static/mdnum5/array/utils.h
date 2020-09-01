#ifndef OTI_MDNUM5_ARRAY_UTILS_H
#define OTI_MDNUM5_ARRAY_UTILS_H

/**************************************************************************************************//**
@brief Function that checks dimensions for an elementwise operation.
This function checks that arr1.ncols == arr2.ncols and arr1.nrows = arr2.nrows. It raises an 
Bad Dimension error if dimensions mismatch.

@param[in] arr1 Array.
@param[in] arr2 Array.
******************************************************************************************************/ 
void mdarr5_dimCheck_OO_elementwise(mdarr5_t* arr1, mdarr5_t* arr2, mdarr5_t* res);
void mdarr5_dimCheck_RO_elementwise(darr_t*  arr1, mdarr5_t* arr2, mdarr5_t* res);

void mdarr5_dimCheck_OO_matmul(mdarr5_t* arr1, mdarr5_t* arr2, mdarr5_t* res);
void mdarr5_dimCheck_RO_matmul(darr_t*  arr1, mdarr5_t* arr2, mdarr5_t* res);
void mdarr5_dimCheck_OR_matmul(mdarr5_t* arr1, darr_t*  arr2, mdarr5_t* res);

void mdarr5_dimCheck_O_squareness(mdarr5_t* arr1, mdarr5_t* res);
void mdarr5_dimCheck_OO_samesize(mdarr5_t* arr1, mdarr5_t* res);
void mdarr5_dimCheck_RO_samesize(darr_t* arr1, mdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function to return the order of a Sparse OTI array.

@param[in] arr OTI Array.
******************************************************************************************************/ 
ord_t mdarr5_get_order(mdarr5_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active OTI bases in the array.

@param[in]    arr        Array.
@param[inout] list_vals  Initialized list of values. Must come with all directions deactivated.
@param[in]    dhl        Direction helper list.
******************************************************************************************************/ 
void mdarr5_get_active_bases(mdarr5_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif