#ifndef OTI_SPARSE_ARRAY_GAUSS_UTILS_H
#define OTI_SPARSE_ARRAY_GAUSS_UTILS_H









// /**************************************************************************************************//**
// @brief 
// 
// @param[in]
// ******************************************************************************************************/ 
// void fearrso_gaussIntegrateOverElement(fearrso_t* arr1, elemProps_t* elem, oarr_t* res, 
//     dhelpl_t dhl);
// // ----------------------------------------------------------------------------------------------------



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


#endif