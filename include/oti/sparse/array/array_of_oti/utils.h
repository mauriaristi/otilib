

/**************************************************************************************************//**
@brief Function that checks dimensions for an elementwise operation.
This function checks that arr1.ncols == arr2.ncols and arr1.nrows = arr2.nrows. It raises an 
Bad Dimension error if dimensions mismatch.

@param[in] arr1 Array.
@param[in] arr2 Array.
******************************************************************************************************/ 
void arrso_dimCheck_OO_elementwise(arrso_t* arr1, arrso_t* arr2);
void arrso_dimCheck_RO_elementwise(darr_t*  arr1, arrso_t* arr2);

void arrso_dimCheck_OO_matmul(arrso_t* arr1, arrso_t* arr2);
void arrso_dimCheck_RO_matmul(darr_t*  arr1, arrso_t* arr2);
void arrso_dimCheck_OR_matmul(arrso_t* arr1, darr_t*  arr2);

void arrso_dimCheck_OR_squareness(arrso_t* arr1);
// ----------------------------------------------------------------------------------------------------



ord_t arrso_get_order(arrso_t* arr);


