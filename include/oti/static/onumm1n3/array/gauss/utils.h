#ifndef OTI_ONUMM1N3_ARRAY_GAUSS_UTILS_H
#define OTI_ONUMM1N3_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm1n3_dimCheck_FF_samesize(feoarrm1n3_t* arr1, feoarrm1n3_t* arr2, feonumm1n3_t* res);
void feoarrm1n3_dimCheck_OF_samesize(  oarrm1n3_t* arr1, feoarrm1n3_t* arr2, feonumm1n3_t* res);
void feoarrm1n3_dimCheck_RF_samesize(   darr_t* arr1, feoarrm1n3_t* arr2, feonumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm1n3_dimCheck_FF_elementwise(feoarrm1n3_t* arr1, feoarrm1n3_t* arr2, feoarrm1n3_t* res);
void feoarrm1n3_dimCheck_OF_elementwise(  oarrm1n3_t* arr1, feoarrm1n3_t* arr2, feoarrm1n3_t* res);
void feoarrm1n3_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm1n3_t* arr2, feoarrm1n3_t* res);
void feoarrm1n3_dimCheck_fF_elementwise( feonumm1n3_t* num1, feoarrm1n3_t* arr2, feoarrm1n3_t* res);
void feoarrm1n3_dimCheck_Ff_elementwise(feoarrm1n3_t* arr1,  feonumm1n3_t* num2, feoarrm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm1n3_dimCheck_FF_matmul( feoarrm1n3_t* lhs, feoarrm1n3_t* rhs, feoarrm1n3_t* res);
void feoarrm1n3_dimCheck_OF_matmul(   oarrm1n3_t* lhs, feoarrm1n3_t* rhs, feoarrm1n3_t* res);
void feoarrm1n3_dimCheck_RF_matmul(    darr_t* lhs, feoarrm1n3_t* rhs, feoarrm1n3_t* res);
void feoarrm1n3_dimCheck_FO_matmul( feoarrm1n3_t* lhs,   oarrm1n3_t* rhs, feoarrm1n3_t* res);
void feoarrm1n3_dimCheck_FR_matmul( feoarrm1n3_t* lhs,    darr_t* rhs, feoarrm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm1n3_dimCheck_F_squareness( feoarrm1n3_t* arr1, feoarrm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm1n3_dimCheck_F_transpose( feoarrm1n3_t* arr1, feoarrm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void feoarrm1n3_dimCheck_FfO_integrate(feoarrm1n3_t* arr, feonumm1n3_t* num,oarrm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void feoarrm1n3_get_active_bases(feoarrm1n3_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif