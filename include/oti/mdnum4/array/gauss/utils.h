#ifndef OTI_MDNUM4_ARRAY_GAUSS_UTILS_H
#define OTI_MDNUM4_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr4_dimCheck_FF_samesize(femdarr4_t* arr1, femdarr4_t* arr2, femdnum4_t* res);
void femdarr4_dimCheck_OF_samesize(  mdarr4_t* arr1, femdarr4_t* arr2, femdnum4_t* res);
void femdarr4_dimCheck_RF_samesize(   darr_t* arr1, femdarr4_t* arr2, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr4_dimCheck_FF_elementwise(femdarr4_t* arr1, femdarr4_t* arr2, femdarr4_t* res);
void femdarr4_dimCheck_OF_elementwise(  mdarr4_t* arr1, femdarr4_t* arr2, femdarr4_t* res);
void femdarr4_dimCheck_RF_elementwise(   darr_t* arr1, femdarr4_t* arr2, femdarr4_t* res);
void femdarr4_dimCheck_fF_elementwise( femdnum4_t* num1, femdarr4_t* arr2, femdarr4_t* res);
void femdarr4_dimCheck_Ff_elementwise(femdarr4_t* arr1,  femdnum4_t* num2, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr4_dimCheck_FF_matmul( femdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);
void femdarr4_dimCheck_OF_matmul(   mdarr4_t* lhs, femdarr4_t* rhs, femdarr4_t* res);
void femdarr4_dimCheck_RF_matmul(    darr_t* lhs, femdarr4_t* rhs, femdarr4_t* res);
void femdarr4_dimCheck_FO_matmul( femdarr4_t* lhs,   mdarr4_t* rhs, femdarr4_t* res);
void femdarr4_dimCheck_FR_matmul( femdarr4_t* lhs,    darr_t* rhs, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr4_dimCheck_F_squareness( femdarr4_t* arr1, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr4_dimCheck_F_transpose( femdarr4_t* arr1, femdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void femdarr4_dimCheck_FfO_integrate(femdarr4_t* arr, femdnum4_t* num,mdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void femdarr4_get_active_bases(femdarr4_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif