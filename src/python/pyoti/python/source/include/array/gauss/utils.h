#ifndef OTI_SPARSE_ARRAY_GAUSS_UTILS_H
#define OTI_SPARSE_ARRAY_GAUSS_UTILS_H


/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fearrso_dimCheck_FF_samesize(fearrso_t* arr1, fearrso_t* arr2, fesoti_t* res);
void fearrso_dimCheck_OF_samesize(  arrso_t* arr1, fearrso_t* arr2, fesoti_t* res);
void fearrso_dimCheck_RF_samesize(   darr_t* arr1, fearrso_t* arr2, fesoti_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fearrso_dimCheck_FF_elementwise(fearrso_t* arr1, fearrso_t* arr2, fearrso_t* res);
void fearrso_dimCheck_OF_elementwise(  arrso_t* arr1, fearrso_t* arr2, fearrso_t* res);
void fearrso_dimCheck_RF_elementwise(   darr_t* arr1, fearrso_t* arr2, fearrso_t* res);
void fearrso_dimCheck_fF_elementwise( fesoti_t* num1, fearrso_t* arr2, fearrso_t* res);
void fearrso_dimCheck_Ff_elementwise(fearrso_t* arr1,  fesoti_t* num2, fearrso_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fearrso_dimCheck_FF_matmul( fearrso_t* lhs, fearrso_t* rhs, fearrso_t* res);
void fearrso_dimCheck_OF_matmul(   arrso_t* lhs, fearrso_t* rhs, fearrso_t* res);
void fearrso_dimCheck_RF_matmul(    darr_t* lhs, fearrso_t* rhs, fearrso_t* res);
void fearrso_dimCheck_FO_matmul( fearrso_t* lhs,   arrso_t* rhs, fearrso_t* res);
void fearrso_dimCheck_FR_matmul( fearrso_t* lhs,    darr_t* rhs, fearrso_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fearrso_dimCheck_F_squareness( fearrso_t* arr1, fearrso_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fearrso_dimCheck_F_transpose( fearrso_t* arr1, fearrso_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void fearrso_dimCheck_FfO_integrate(fearrso_t* arr, fesoti_t* num,arrso_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void fearrso_get_active_bases(fearrso_t* arr, imdir_t* list_vals, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


#endif