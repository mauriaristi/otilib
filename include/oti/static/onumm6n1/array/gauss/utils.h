#ifndef OTI_ONUMM6N1_ARRAY_GAUSS_UTILS_H
#define OTI_ONUMM6N1_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm6n1_dimCheck_FF_samesize(feoarrm6n1_t* arr1, feoarrm6n1_t* arr2, feonumm6n1_t* res);
void feoarrm6n1_dimCheck_OF_samesize(  oarrm6n1_t* arr1, feoarrm6n1_t* arr2, feonumm6n1_t* res);
void feoarrm6n1_dimCheck_RF_samesize(   darr_t* arr1, feoarrm6n1_t* arr2, feonumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm6n1_dimCheck_FF_elementwise(feoarrm6n1_t* arr1, feoarrm6n1_t* arr2, feoarrm6n1_t* res);
void feoarrm6n1_dimCheck_OF_elementwise(  oarrm6n1_t* arr1, feoarrm6n1_t* arr2, feoarrm6n1_t* res);
void feoarrm6n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm6n1_t* arr2, feoarrm6n1_t* res);
void feoarrm6n1_dimCheck_fF_elementwise( feonumm6n1_t* num1, feoarrm6n1_t* arr2, feoarrm6n1_t* res);
void feoarrm6n1_dimCheck_Ff_elementwise(feoarrm6n1_t* arr1,  feonumm6n1_t* num2, feoarrm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm6n1_dimCheck_FF_matmul( feoarrm6n1_t* lhs, feoarrm6n1_t* rhs, feoarrm6n1_t* res);
void feoarrm6n1_dimCheck_OF_matmul(   oarrm6n1_t* lhs, feoarrm6n1_t* rhs, feoarrm6n1_t* res);
void feoarrm6n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm6n1_t* rhs, feoarrm6n1_t* res);
void feoarrm6n1_dimCheck_FO_matmul( feoarrm6n1_t* lhs,   oarrm6n1_t* rhs, feoarrm6n1_t* res);
void feoarrm6n1_dimCheck_FR_matmul( feoarrm6n1_t* lhs,    darr_t* rhs, feoarrm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm6n1_dimCheck_F_squareness( feoarrm6n1_t* arr1, feoarrm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm6n1_dimCheck_F_transpose( feoarrm6n1_t* arr1, feoarrm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void feoarrm6n1_dimCheck_FfO_integrate(feoarrm6n1_t* arr, feonumm6n1_t* num,oarrm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void feoarrm6n1_get_active_bases(feoarrm6n1_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif