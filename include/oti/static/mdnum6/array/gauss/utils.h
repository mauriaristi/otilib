#ifndef OTI_MDNUM6_ARRAY_GAUSS_UTILS_H
#define OTI_MDNUM6_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr6_dimCheck_FF_samesize(femdarr6_t* arr1, femdarr6_t* arr2, femdnum6_t* res);
void femdarr6_dimCheck_OF_samesize(  mdarr6_t* arr1, femdarr6_t* arr2, femdnum6_t* res);
void femdarr6_dimCheck_RF_samesize(   darr_t* arr1, femdarr6_t* arr2, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr6_dimCheck_FF_elementwise(femdarr6_t* arr1, femdarr6_t* arr2, femdarr6_t* res);
void femdarr6_dimCheck_OF_elementwise(  mdarr6_t* arr1, femdarr6_t* arr2, femdarr6_t* res);
void femdarr6_dimCheck_RF_elementwise(   darr_t* arr1, femdarr6_t* arr2, femdarr6_t* res);
void femdarr6_dimCheck_fF_elementwise( femdnum6_t* num1, femdarr6_t* arr2, femdarr6_t* res);
void femdarr6_dimCheck_Ff_elementwise(femdarr6_t* arr1,  femdnum6_t* num2, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr6_dimCheck_FF_matmul( femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
void femdarr6_dimCheck_OF_matmul(   mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
void femdarr6_dimCheck_RF_matmul(    darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res);
void femdarr6_dimCheck_FO_matmul( femdarr6_t* lhs,   mdarr6_t* rhs, femdarr6_t* res);
void femdarr6_dimCheck_FR_matmul( femdarr6_t* lhs,    darr_t* rhs, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr6_dimCheck_F_squareness( femdarr6_t* arr1, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr6_dimCheck_F_transpose( femdarr6_t* arr1, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void femdarr6_dimCheck_FfO_integrate(femdarr6_t* arr, femdnum6_t* num,mdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void femdarr6_get_active_bases(femdarr6_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif