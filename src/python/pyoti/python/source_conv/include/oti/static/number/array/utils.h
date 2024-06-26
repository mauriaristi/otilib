#ifndef OTI_{module_name_upper}_ARRAY_UTILS_H
#define OTI_{module_name_upper}_ARRAY_UTILS_H

/**************************************************************************************************//**
@brief Function that checks dimensions for an elementwise operation.
This function checks that arr1.ncols == arr2.ncols and arr1.nrows = arr2.nrows. It raises an 
Bad Dimension error if dimensions mismatch.

@param[in] arr1 Array.
@param[in] arr2 Array.
******************************************************************************************************/ 
void {arr_func}_dimCheck_OO_elementwise({arr_type}* arr1, {arr_type}* arr2, {arr_type}* res);
void {arr_func}_dimCheck_RO_elementwise(darr_t*  arr1, {arr_type}* arr2, {arr_type}* res);

void {arr_func}_dimCheck_OO_matmul({arr_type}* arr1, {arr_type}* arr2, {arr_type}* res);
void {arr_func}_dimCheck_RO_matmul(darr_t*  arr1, {arr_type}* arr2, {arr_type}* res);
void {arr_func}_dimCheck_OR_matmul({arr_type}* arr1, darr_t*  arr2, {arr_type}* res);

void {arr_func}_dimCheck_O_squareness({arr_type}* arr1, {arr_type}* res);
void {arr_func}_dimCheck_OO_samesize({arr_type}* arr1, {arr_type}* res);
void {arr_func}_dimCheck_RO_samesize(darr_t* arr1, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function to return the order of a Sparse OTI array.

@param[in] arr OTI Array.
******************************************************************************************************/ 
ord_t {arr_func}_get_order({arr_type}* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active OTI bases in the array.

@param[in]    arr        Array.
@param[inout] list_vals  Initialized list of values. Must come with all directions deactivated.
@param[in]    dhl        Direction helper list.
******************************************************************************************************/ 
void {arr_func}_get_active_bases({arr_type}* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif