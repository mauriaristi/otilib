#ifndef OTI_MDNUM9_ARRAY_GAUSS_UTILS_H
#define OTI_MDNUM9_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr9_dimCheck_FF_samesize(femdarr9_t* arr1, femdarr9_t* arr2, femdnum9_t* res);
void femdarr9_dimCheck_OF_samesize(  mdarr9_t* arr1, femdarr9_t* arr2, femdnum9_t* res);
void femdarr9_dimCheck_RF_samesize(   darr_t* arr1, femdarr9_t* arr2, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr9_dimCheck_FF_elementwise(femdarr9_t* arr1, femdarr9_t* arr2, femdarr9_t* res);
void femdarr9_dimCheck_OF_elementwise(  mdarr9_t* arr1, femdarr9_t* arr2, femdarr9_t* res);
void femdarr9_dimCheck_RF_elementwise(   darr_t* arr1, femdarr9_t* arr2, femdarr9_t* res);
void femdarr9_dimCheck_fF_elementwise( femdnum9_t* num1, femdarr9_t* arr2, femdarr9_t* res);
void femdarr9_dimCheck_Ff_elementwise(femdarr9_t* arr1,  femdnum9_t* num2, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr9_dimCheck_FF_matmul( femdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
void femdarr9_dimCheck_OF_matmul(   mdarr9_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
void femdarr9_dimCheck_RF_matmul(    darr_t* lhs, femdarr9_t* rhs, femdarr9_t* res);
void femdarr9_dimCheck_FO_matmul( femdarr9_t* lhs,   mdarr9_t* rhs, femdarr9_t* res);
void femdarr9_dimCheck_FR_matmul( femdarr9_t* lhs,    darr_t* rhs, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr9_dimCheck_F_squareness( femdarr9_t* arr1, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr9_dimCheck_F_transpose( femdarr9_t* arr1, femdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void femdarr9_dimCheck_FfO_integrate(femdarr9_t* arr, femdnum9_t* num,mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void femdarr9_get_active_bases(femdarr9_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif