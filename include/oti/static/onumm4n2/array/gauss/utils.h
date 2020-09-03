#ifndef OTI_ONUMM4N2_ARRAY_GAUSS_UTILS_H
#define OTI_ONUMM4N2_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm4n2_dimCheck_FF_samesize(feoarrm4n2_t* arr1, feoarrm4n2_t* arr2, feonumm4n2_t* res);
void feoarrm4n2_dimCheck_OF_samesize(  oarrm4n2_t* arr1, feoarrm4n2_t* arr2, feonumm4n2_t* res);
void feoarrm4n2_dimCheck_RF_samesize(   darr_t* arr1, feoarrm4n2_t* arr2, feonumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm4n2_dimCheck_FF_elementwise(feoarrm4n2_t* arr1, feoarrm4n2_t* arr2, feoarrm4n2_t* res);
void feoarrm4n2_dimCheck_OF_elementwise(  oarrm4n2_t* arr1, feoarrm4n2_t* arr2, feoarrm4n2_t* res);
void feoarrm4n2_dimCheck_RF_elementwise(   darr_t* arr1, feoarrm4n2_t* arr2, feoarrm4n2_t* res);
void feoarrm4n2_dimCheck_fF_elementwise( feonumm4n2_t* num1, feoarrm4n2_t* arr2, feoarrm4n2_t* res);
void feoarrm4n2_dimCheck_Ff_elementwise(feoarrm4n2_t* arr1,  feonumm4n2_t* num2, feoarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm4n2_dimCheck_FF_matmul( feoarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
void feoarrm4n2_dimCheck_OF_matmul(   oarrm4n2_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
void feoarrm4n2_dimCheck_RF_matmul(    darr_t* lhs, feoarrm4n2_t* rhs, feoarrm4n2_t* res);
void feoarrm4n2_dimCheck_FO_matmul( feoarrm4n2_t* lhs,   oarrm4n2_t* rhs, feoarrm4n2_t* res);
void feoarrm4n2_dimCheck_FR_matmul( feoarrm4n2_t* lhs,    darr_t* rhs, feoarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm4n2_dimCheck_F_squareness( feoarrm4n2_t* arr1, feoarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void feoarrm4n2_dimCheck_F_transpose( feoarrm4n2_t* arr1, feoarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void feoarrm4n2_dimCheck_FfO_integrate(feoarrm4n2_t* arr, feonumm4n2_t* num,oarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void feoarrm4n2_get_active_bases(feoarrm4n2_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif