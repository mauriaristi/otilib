#ifndef OTI_MDNUM1_ARRAY_GAUSS_UTILS_H
#define OTI_MDNUM1_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr1_dimCheck_FF_samesize(femdarr1_t* arr1, femdarr1_t* arr2, femdnum1_t* res);
void femdarr1_dimCheck_OF_samesize(  mdarr1_t* arr1, femdarr1_t* arr2, femdnum1_t* res);
void femdarr1_dimCheck_RF_samesize(   darr_t* arr1, femdarr1_t* arr2, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr1_dimCheck_FF_elementwise(femdarr1_t* arr1, femdarr1_t* arr2, femdarr1_t* res);
void femdarr1_dimCheck_OF_elementwise(  mdarr1_t* arr1, femdarr1_t* arr2, femdarr1_t* res);
void femdarr1_dimCheck_RF_elementwise(   darr_t* arr1, femdarr1_t* arr2, femdarr1_t* res);
void femdarr1_dimCheck_fF_elementwise( femdnum1_t* num1, femdarr1_t* arr2, femdarr1_t* res);
void femdarr1_dimCheck_Ff_elementwise(femdarr1_t* arr1,  femdnum1_t* num2, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr1_dimCheck_FF_matmul( femdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
void femdarr1_dimCheck_OF_matmul(   mdarr1_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
void femdarr1_dimCheck_RF_matmul(    darr_t* lhs, femdarr1_t* rhs, femdarr1_t* res);
void femdarr1_dimCheck_FO_matmul( femdarr1_t* lhs,   mdarr1_t* rhs, femdarr1_t* res);
void femdarr1_dimCheck_FR_matmul( femdarr1_t* lhs,    darr_t* rhs, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr1_dimCheck_F_squareness( femdarr1_t* arr1, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr1_dimCheck_F_transpose( femdarr1_t* arr1, femdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void femdarr1_dimCheck_FfO_integrate(femdarr1_t* arr, femdnum1_t* num,mdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void femdarr1_get_active_bases(femdarr1_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif