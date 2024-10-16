#ifndef OTI_ONUMM2N1_ARRAY_GAUSS_UTILS_H
#define OTI_ONUMM2N1_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm2n1_dimCheck_FF_samesize(feoarrm2n1_t* arr1, feoarrm2n1_t* arr2, feonumm2n1_t* res);
void feoarrm2n1_dimCheck_OF_samesize(  oarrm2n1_t* arr1, feoarrm2n1_t* arr2, feonumm2n1_t* res);
void feoarrm2n1_dimCheck_RF_samesize(   darr_t* arr1, feoarrm2n1_t* arr2, feonumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm2n1_dimCheck_FF_elementwise(feoarrm2n1_t* arr1, feoarrm2n1_t* arr2, feoarrm2n1_t* res);
void feoarrm2n1_dimCheck_OF_elementwise(  oarrm2n1_t* arr1, feoarrm2n1_t* arr2, feoarrm2n1_t* res);
void feoarrm2n1_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm2n1_t* arr2, feoarrm2n1_t* res);
void feoarrm2n1_dimCheck_fF_elementwise( feonumm2n1_t* num1, feoarrm2n1_t* arr2, feoarrm2n1_t* res);
void feoarrm2n1_dimCheck_Ff_elementwise(feoarrm2n1_t* arr1,  feonumm2n1_t* num2, feoarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm2n1_dimCheck_FF_matmul( feoarrm2n1_t* lhs, feoarrm2n1_t* rhs, feoarrm2n1_t* res);
void feoarrm2n1_dimCheck_OF_matmul(   oarrm2n1_t* lhs, feoarrm2n1_t* rhs, feoarrm2n1_t* res);
void feoarrm2n1_dimCheck_RF_matmul(    darr_t* lhs, feoarrm2n1_t* rhs, feoarrm2n1_t* res);
void feoarrm2n1_dimCheck_FO_matmul( feoarrm2n1_t* lhs,   oarrm2n1_t* rhs, feoarrm2n1_t* res);
void feoarrm2n1_dimCheck_FR_matmul( feoarrm2n1_t* lhs,    darr_t* rhs, feoarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm2n1_dimCheck_F_squareness( feoarrm2n1_t* arr1, feoarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm2n1_dimCheck_F_transpose( feoarrm2n1_t* arr1, feoarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void feoarrm2n1_dimCheck_FfO_integrate(feoarrm2n1_t* arr, feonumm2n1_t* num,oarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void feoarrm2n1_get_active_bases(feoarrm2n1_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif