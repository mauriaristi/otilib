#ifndef OTI_ONUMM9N1_ARRAY_UTILS_H
#define OTI_ONUMM9N1_ARRAY_UTILS_H

/**************************************************************************************************//**
@brief Function that checks dimensions for an elementwise operation.
This function checks that arr1.ncols == arr2.ncols and arr1.nrows = arr2.nrows. It raises an 
Bad Dimension error if dimensions mismatch.

@param[in] arr1 Array.
@param[in] arr2 Array.
******************************************************************************************************/ 
void oarrm9n1_dimCheck_OO_elementwise(oarrm9n1_t* arr1, oarrm9n1_t* arr2, oarrm9n1_t* res);
void oarrm9n1_dimCheck_RO_elementwise(darr_t*  arr1, oarrm9n1_t* arr2, oarrm9n1_t* res);

void oarrm9n1_dimCheck_OO_matmul(oarrm9n1_t* arr1, oarrm9n1_t* arr2, oarrm9n1_t* res);
void oarrm9n1_dimCheck_RO_matmul(darr_t*  arr1, oarrm9n1_t* arr2, oarrm9n1_t* res);
void oarrm9n1_dimCheck_OR_matmul(oarrm9n1_t* arr1, darr_t*  arr2, oarrm9n1_t* res);

void oarrm9n1_dimCheck_O_squareness(oarrm9n1_t* arr1, oarrm9n1_t* res);
void oarrm9n1_dimCheck_OO_samesize(oarrm9n1_t* arr1, oarrm9n1_t* res);
void oarrm9n1_dimCheck_RO_samesize(darr_t* arr1, oarrm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function to return the order of a Sparse OTI array.

@param[in] arr OTI Array.
******************************************************************************************************/ 
ord_t oarrm9n1_get_order(oarrm9n1_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active OTI bases in the array.

@param[in]    arr        Array.
@param[inout] list_vals  Initialized list of values. Must come with all directions deactivated.
@param[in]    dhl        Direction helper list.
******************************************************************************************************/ 
void oarrm9n1_get_active_bases(oarrm9n1_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif