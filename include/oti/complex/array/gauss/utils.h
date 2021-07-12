#ifndef OTI_COMPLEX_ARRAY_GAUSS_UTILS_H
#define OTI_COMPLEX_ARRAY_GAUSS_UTILS_H


/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fecarr_dimCheck_FF_samesize( fecarr_t* arr1, fecarr_t* arr2, fecnum_t* res);
void fecarr_dimCheck_RF_samesize(   carr_t* arr1, fecarr_t* arr2, fecnum_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fecarr_dimCheck_FF_elementwise( fecarr_t* arr1,  fecarr_t* arr2, fecarr_t* res);
void fecarr_dimCheck_RF_elementwise(   carr_t* arr1,  fecarr_t* arr2, fecarr_t* res);
void fecarr_dimCheck_fF_elementwise( fecnum_t* num1,  fecarr_t* arr2, fecarr_t* res);
void fecarr_dimCheck_Ff_elementwise( fecarr_t* arr1,  fecnum_t* num2, fecarr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fecarr_dimCheck_FF_matmul( fecarr_t* lhs, fecarr_t* rhs, fecarr_t* res);
void fecarr_dimCheck_RF_matmul(   carr_t* lhs, fecarr_t* rhs, fecarr_t* res);
void fecarr_dimCheck_FR_matmul( fecarr_t* lhs,   carr_t* rhs, fecarr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fecarr_dimCheck_F_squareness( fecarr_t* arr1, fecarr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fecarr_dimCheck_F_transpose( fecarr_t* arr1, fecarr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void fecarr_dimCheck_FfR_integrate(fecarr_t* arr, fecnum_t* num,carr_t* res);
// ----------------------------------------------------------------------------------------------------


#endif