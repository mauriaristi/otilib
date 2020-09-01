#ifndef OTI_MDNUM7_ARRAY_GAUSS_UTILS_H
#define OTI_MDNUM7_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr7_dimCheck_FF_samesize(femdarr7_t* arr1, femdarr7_t* arr2, femdnum7_t* res);
void femdarr7_dimCheck_OF_samesize(  mdarr7_t* arr1, femdarr7_t* arr2, femdnum7_t* res);
void femdarr7_dimCheck_RF_samesize(   darr_t* arr1, femdarr7_t* arr2, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr7_dimCheck_FF_elementwise(femdarr7_t* arr1, femdarr7_t* arr2, femdarr7_t* res);
void femdarr7_dimCheck_OF_elementwise(  mdarr7_t* arr1, femdarr7_t* arr2, femdarr7_t* res);
void femdarr7_dimCheck_RF_elementwise(   darr_t* arr1, femdarr7_t* arr2, femdarr7_t* res);
void femdarr7_dimCheck_fF_elementwise( femdnum7_t* num1, femdarr7_t* arr2, femdarr7_t* res);
void femdarr7_dimCheck_Ff_elementwise(femdarr7_t* arr1,  femdnum7_t* num2, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr7_dimCheck_FF_matmul( femdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
void femdarr7_dimCheck_OF_matmul(   mdarr7_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
void femdarr7_dimCheck_RF_matmul(    darr_t* lhs, femdarr7_t* rhs, femdarr7_t* res);
void femdarr7_dimCheck_FO_matmul( femdarr7_t* lhs,   mdarr7_t* rhs, femdarr7_t* res);
void femdarr7_dimCheck_FR_matmul( femdarr7_t* lhs,    darr_t* rhs, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr7_dimCheck_F_squareness( femdarr7_t* arr1, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void femdarr7_dimCheck_F_transpose( femdarr7_t* arr1, femdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void femdarr7_dimCheck_FfO_integrate(femdarr7_t* arr, femdnum7_t* num,mdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void femdarr7_get_active_bases(femdarr7_t* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif