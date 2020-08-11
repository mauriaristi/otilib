#ifndef OTI_REAL_ARRAY_GAUSS_UTILS_H
#define OTI_REAL_ARRAY_GAUSS_UTILS_H


/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fedarr_dimCheck_FF_samesize( fedarr_t* arr1, fedarr_t* arr2, fednum_t* res);
void fedarr_dimCheck_RF_samesize(   darr_t* arr1, fedarr_t* arr2, fednum_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fedarr_dimCheck_FF_elementwise( fedarr_t* arr1,  fedarr_t* arr2, fedarr_t* res);
void fedarr_dimCheck_RF_elementwise(   darr_t* arr1,  fedarr_t* arr2, fedarr_t* res);
void fedarr_dimCheck_fF_elementwise( fednum_t* num1,  fedarr_t* arr2, fedarr_t* res);
void fedarr_dimCheck_Ff_elementwise( fedarr_t* arr1,  fednum_t* num2, fedarr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fedarr_dimCheck_FF_matmul( fedarr_t* lhs, fedarr_t* rhs, fedarr_t* res);
void fedarr_dimCheck_RF_matmul(   darr_t* lhs, fedarr_t* rhs, fedarr_t* res);
void fedarr_dimCheck_FR_matmul( fedarr_t* lhs,   darr_t* rhs, fedarr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fedarr_dimCheck_F_squareness( fedarr_t* arr1, fedarr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fedarr_dimCheck_F_transpose( fedarr_t* arr1, fedarr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void fedarr_dimCheck_FfR_integrate(fedarr_t* arr, fednum_t* num,darr_t* res);
// ----------------------------------------------------------------------------------------------------


#endif