#ifndef OTI_ONUMM2N2_ARRAY_UTILS_H
#define OTI_ONUMM2N2_ARRAY_UTILS_H

/**************************************************************************************************//**
@brief Function that checks dimensions for an elementwise operation.
This function checks that arr1.ncols == arr2.ncols and arr1.nrows = arr2.nrows. It raises an 
Bad Dimension error if dimensions mismatch.

@param[in] arr1 Array.
@param[in] arr2 Array.
******************************************************************************************************/ 
void oarrm2n2_dimCheck_OO_elementwise(oarrm2n2_t* arr1, oarrm2n2_t* arr2, oarrm2n2_t* res);
void oarrm2n2_dimCheck_RO_elementwise(darr_t*  arr1, oarrm2n2_t* arr2, oarrm2n2_t* res);

void oarrm2n2_dimCheck_OO_matmul(oarrm2n2_t* arr1, oarrm2n2_t* arr2, oarrm2n2_t* res);
void oarrm2n2_dimCheck_RO_matmul(darr_t*  arr1, oarrm2n2_t* arr2, oarrm2n2_t* res);
void oarrm2n2_dimCheck_OR_matmul(oarrm2n2_t* arr1, darr_t*  arr2, oarrm2n2_t* res);

void oarrm2n2_dimCheck_O_squareness(oarrm2n2_t* arr1, oarrm2n2_t* res);
void oarrm2n2_dimCheck_OO_samesize(oarrm2n2_t* arr1, oarrm2n2_t* res);
void oarrm2n2_dimCheck_RO_samesize(darr_t* arr1, oarrm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function to return the order of a Sparse OTI array.

@param[in] arr OTI Array.
******************************************************************************************************/ 
ord_t oarrm2n2_get_order(oarrm2n2_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active OTI bases in the array.

@param[in]    arr        Array.
@param[inout] list_vals  Initialized list of values. Must come with all directions deactivated.
@param[in]    dhl        Direction helper list.
******************************************************************************************************/ 
void oarrm2n2_get_active_bases(oarrm2n2_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif