#ifndef OTI_MDNUM8_ARRAY_GAUSS_UTILS_H
#define OTI_MDNUM8_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr8_dimCheck_FF_samesize(femdarr8_t* arr1, femdarr8_t* arr2, femdnum8_t* res);
void femdarr8_dimCheck_OF_samesize(  mdarr8_t* arr1, femdarr8_t* arr2, femdnum8_t* res);
void femdarr8_dimCheck_RF_samesize(   darr_t* arr1, femdarr8_t* arr2, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr8_dimCheck_FF_elementwise(femdarr8_t* arr1, femdarr8_t* arr2, femdarr8_t* res);
void femdarr8_dimCheck_OF_elementwise(  mdarr8_t* arr1, femdarr8_t* arr2, femdarr8_t* res);
void femdarr8_dimCheck_RF_elementwise(   darr_t* arr1, femdarr8_t* arr2, femdarr8_t* res);
void femdarr8_dimCheck_fF_elementwise( femdnum8_t* num1, femdarr8_t* arr2, femdarr8_t* res);
void femdarr8_dimCheck_Ff_elementwise(femdarr8_t* arr1,  femdnum8_t* num2, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr8_dimCheck_FF_matmul( femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
void femdarr8_dimCheck_OF_matmul(   mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
void femdarr8_dimCheck_RF_matmul(    darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res);
void femdarr8_dimCheck_FO_matmul( femdarr8_t* lhs,   mdarr8_t* rhs, femdarr8_t* res);
void femdarr8_dimCheck_FR_matmul( femdarr8_t* lhs,    darr_t* rhs, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr8_dimCheck_F_squareness( femdarr8_t* arr1, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr8_dimCheck_F_transpose( femdarr8_t* arr1, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void femdarr8_dimCheck_FfO_integrate(femdarr8_t* arr, femdnum8_t* num,mdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void femdarr8_get_active_bases(femdarr8_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif