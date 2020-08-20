#ifndef OTI_MDNUM2_ARRAY_GAUSS_UTILS_H
#define OTI_MDNUM2_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr2_dimCheck_FF_samesize(femdarr2_t* arr1, femdarr2_t* arr2, femdnum2_t* res);
void femdarr2_dimCheck_OF_samesize(  mdarr2_t* arr1, femdarr2_t* arr2, femdnum2_t* res);
void femdarr2_dimCheck_RF_samesize(   darr_t* arr1, femdarr2_t* arr2, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr2_dimCheck_FF_elementwise(femdarr2_t* arr1, femdarr2_t* arr2, femdarr2_t* res);
void femdarr2_dimCheck_OF_elementwise(  mdarr2_t* arr1, femdarr2_t* arr2, femdarr2_t* res);
void femdarr2_dimCheck_RF_elementwise(   darr_t* arr1, femdarr2_t* arr2, femdarr2_t* res);
void femdarr2_dimCheck_fF_elementwise( femdnum2_t* num1, femdarr2_t* arr2, femdarr2_t* res);
void femdarr2_dimCheck_Ff_elementwise(femdarr2_t* arr1,  femdnum2_t* num2, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr2_dimCheck_FF_matmul( femdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
void femdarr2_dimCheck_OF_matmul(   mdarr2_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
void femdarr2_dimCheck_RF_matmul(    darr_t* lhs, femdarr2_t* rhs, femdarr2_t* res);
void femdarr2_dimCheck_FO_matmul( femdarr2_t* lhs,   mdarr2_t* rhs, femdarr2_t* res);
void femdarr2_dimCheck_FR_matmul( femdarr2_t* lhs,    darr_t* rhs, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr2_dimCheck_F_squareness( femdarr2_t* arr1, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr2_dimCheck_F_transpose( femdarr2_t* arr1, femdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void femdarr2_dimCheck_FfO_integrate(femdarr2_t* arr, femdnum2_t* num,mdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void femdarr2_get_active_bases(femdarr2_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif