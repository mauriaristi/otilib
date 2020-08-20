#ifndef OTI_{module_name_upper}_ARRAY_GAUSS_UTILS_H
#define OTI_{module_name_upper}_ARRAY_GAUSS_UTILS_H

/**************************************************************************************************//**
@brief Check dimensions for arrays to have the same number of elements. (specific for dot product oper.)

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void {fearr_func}_dimCheck_FF_samesize({fearr_type}* arr1, {fearr_type}* arr2, {fenum_type}* res);
void {fearr_func}_dimCheck_OF_samesize(  {arr_type}* arr1, {fearr_type}* arr2, {fenum_type}* res);
void {fearr_func}_dimCheck_RF_samesize(   darr_t* arr1, {fearr_type}* arr2, {fenum_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for Elementwise matrix operation (such as addition or subtraction).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void {fearr_func}_dimCheck_FF_elementwise({fearr_type}* arr1, {fearr_type}* arr2, {fearr_type}* res);
void {fearr_func}_dimCheck_OF_elementwise(  {arr_type}* arr1, {fearr_type}* arr2, {fearr_type}* res);
void {fearr_func}_dimCheck_RF_elementwise(   darr_t* arr1, {fearr_type}* arr2, {fearr_type}* res);
void {fearr_func}_dimCheck_fF_elementwise( {fenum_type}* num1, {fearr_type}* arr2, {fearr_type}* res);
void {fearr_func}_dimCheck_Ff_elementwise({fearr_type}* arr1,  {fenum_type}* num2, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for matrix multiplication operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void {fearr_func}_dimCheck_FF_matmul( {fearr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);
void {fearr_func}_dimCheck_OF_matmul(   {arr_type}* lhs, {fearr_type}* rhs, {fearr_type}* res);
void {fearr_func}_dimCheck_RF_matmul(    darr_t* lhs, {fearr_type}* rhs, {fearr_type}* res);
void {fearr_func}_dimCheck_FO_matmul( {fearr_type}* lhs,   {arr_type}* rhs, {fearr_type}* res);
void {fearr_func}_dimCheck_FR_matmul( {fearr_type}* lhs,    darr_t* rhs, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions operation requiring square matrix (such as inversion or determinant).

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void {fearr_func}_dimCheck_F_squareness( {fearr_type}* arr1, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for transpose operation.

@param[in] lhs Left hand side
@param[in] rhs Right hand side
@param[in] res Result
******************************************************************************************************/ 
void {fearr_func}_dimCheck_F_transpose( {fearr_type}* arr1, {fearr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Check dimensions for integration operation.

@param[in] arr Gauss Array
@param[in] num Gauss Number
@param[in] res Result
******************************************************************************************************/ 
void {fearr_func}_dimCheck_FfO_integrate({fearr_type}* arr, {fenum_type}* num,{arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get active bases of the oti structure.

@param[in] arr Gauss Array.
@param[in] list_vals Array to activate corresponding directions.
@param[in] dhl Direction helper list
******************************************************************************************************/ 
void {fearr_func}_get_active_bases({fearr_type}* arr, imdir_t* list_vals);
// ----------------------------------------------------------------------------------------------------

#endif