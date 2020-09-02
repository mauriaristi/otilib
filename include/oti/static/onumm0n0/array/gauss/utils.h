#ifndef OTI_ONUMM0N0_ARRAY_GAUSS_UTILS_H
#define OTI_ONUMM0N0_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm0n0_dimCheck_FF_samesize(feoarrm0n0_t* arr1, feoarrm0n0_t* arr2, feonumm0n0_t* res);
void feoarrm0n0_dimCheck_OF_samesize(  oarrm0n0_t* arr1, feoarrm0n0_t* arr2, feonumm0n0_t* res);
void feoarrm0n0_dimCheck_RF_samesize(   darr_t* arr1, feoarrm0n0_t* arr2, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm0n0_dimCheck_FF_elementwise(feoarrm0n0_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res);
void feoarrm0n0_dimCheck_OF_elementwise(  oarrm0n0_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res);
void feoarrm0n0_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm0n0_t* arr2, feoarrm0n0_t* res);
void feoarrm0n0_dimCheck_fF_elementwise( feonumm0n0_t* num1, feoarrm0n0_t* arr2, feoarrm0n0_t* res);
void feoarrm0n0_dimCheck_Ff_elementwise(feoarrm0n0_t* arr1,  feonumm0n0_t* num2, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm0n0_dimCheck_FF_matmul( feoarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
void feoarrm0n0_dimCheck_OF_matmul(   oarrm0n0_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
void feoarrm0n0_dimCheck_RF_matmul(    darr_t* lhs, feoarrm0n0_t* rhs, feoarrm0n0_t* res);
void feoarrm0n0_dimCheck_FO_matmul( feoarrm0n0_t* lhs,   oarrm0n0_t* rhs, feoarrm0n0_t* res);
void feoarrm0n0_dimCheck_FR_matmul( feoarrm0n0_t* lhs,    darr_t* rhs, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm0n0_dimCheck_F_squareness( feoarrm0n0_t* arr1, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm0n0_dimCheck_F_transpose( feoarrm0n0_t* arr1, feoarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void feoarrm0n0_dimCheck_FfO_integrate(feoarrm0n0_t* arr, feonumm0n0_t* num,oarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void feoarrm0n0_get_active_bases(feoarrm0n0_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif