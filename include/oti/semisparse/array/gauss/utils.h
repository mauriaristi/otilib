#ifndef OTI_SEMISPARSE_ARRAY_GAUSS_UTILS_H
#define OTI_SEMISPARSE_ARRAY_GAUSS_UTILS_H


/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fearrsso_dimCheck_FF_samesize(fearrsso_t* arr1, fearrsso_t* arr2, fessoti_t* res);
void fearrsso_dimCheck_OF_samesize(  arrsso_t* arr1, fearrsso_t* arr2, fessoti_t* res);
void fearrsso_dimCheck_RF_samesize(   darr_t* arr1, fearrsso_t* arr2, fessoti_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fearrsso_dimCheck_FF_elementwise(fearrsso_t* arr1, fearrsso_t* arr2, fearrsso_t* res);
void fearrsso_dimCheck_OF_elementwise(  arrsso_t* arr1, fearrsso_t* arr2, fearrsso_t* res);
void fearrsso_dimCheck_RF_elementwise(   darr_t* arr1, fearrsso_t* arr2, fearrsso_t* res);
void fearrsso_dimCheck_fF_elementwise( fessoti_t* num1, fearrsso_t* arr2, fearrsso_t* res);
void fearrsso_dimCheck_Ff_elementwise(fearrsso_t* arr1,  fessoti_t* num2, fearrsso_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fearrsso_dimCheck_FF_matmul( fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res);
void fearrsso_dimCheck_OF_matmul(   arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res);
void fearrsso_dimCheck_RF_matmul(    darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res);
void fearrsso_dimCheck_FO_matmul( fearrsso_t* lhs,   arrsso_t* rhs, fearrsso_t* res);
void fearrsso_dimCheck_FR_matmul( fearrsso_t* lhs,    darr_t* rhs, fearrsso_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fearrsso_dimCheck_F_squareness( fearrsso_t* arr1, fearrsso_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void fearrsso_dimCheck_F_transpose( fearrsso_t* arr1, fearrsso_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void fearrsso_dimCheck_FfO_integrate(fearrsso_t* arr, fessoti_t* num,arrsso_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void fearrsso_get_active_bases(fearrsso_t* arr, imdir_t* list_vals, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


#endif