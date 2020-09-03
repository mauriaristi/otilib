#ifndef OTI_MDNUM3_ARRAY_GAUSS_UTILS_H
#define OTI_MDNUM3_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr3_dimCheck_FF_samesize(femdarr3_t* arr1, femdarr3_t* arr2, femdnum3_t* res);
void femdarr3_dimCheck_OF_samesize(  mdarr3_t* arr1, femdarr3_t* arr2, femdnum3_t* res);
void femdarr3_dimCheck_RF_samesize(   darr_t* arr1, femdarr3_t* arr2, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr3_dimCheck_FF_elementwise(femdarr3_t* arr1, femdarr3_t* arr2, femdarr3_t* res);
void femdarr3_dimCheck_OF_elementwise(  mdarr3_t* arr1, femdarr3_t* arr2, femdarr3_t* res);
void femdarr3_dimCheck_RF_elementwise(   darr_t* arr1, femdarr3_t* arr2, femdarr3_t* res);
void femdarr3_dimCheck_fF_elementwise( femdnum3_t* num1, femdarr3_t* arr2, femdarr3_t* res);
void femdarr3_dimCheck_Ff_elementwise(femdarr3_t* arr1,  femdnum3_t* num2, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr3_dimCheck_FF_matmul( femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
void femdarr3_dimCheck_OF_matmul(   mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
void femdarr3_dimCheck_RF_matmul(    darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res);
void femdarr3_dimCheck_FO_matmul( femdarr3_t* lhs,   mdarr3_t* rhs, femdarr3_t* res);
void femdarr3_dimCheck_FR_matmul( femdarr3_t* lhs,    darr_t* rhs, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr3_dimCheck_F_squareness( femdarr3_t* arr1, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr3_dimCheck_F_transpose( femdarr3_t* arr1, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void femdarr3_dimCheck_FfO_integrate(femdarr3_t* arr, femdnum3_t* num,mdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void femdarr3_get_active_bases(femdarr3_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif