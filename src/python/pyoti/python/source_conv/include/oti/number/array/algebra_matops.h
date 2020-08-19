#ifndef OTI_{module_name_upper}_ARRAY_ALGEBRA_MATOPS_H
#define OTI_{module_name_upper}_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{num_type} {arr_func}_dotproduct_OO(    {arr_type}* lhs, {arr_type}* rhs);
void      {arr_func}_dotproduct_OO_to( {arr_type}* lhs, {arr_type}* rhs, {num_type}* res);

{num_type} {arr_func}_dotproduct_RO(     darr_t* lhs, {arr_type}* rhs);
void      {arr_func}_dotproduct_RO_to(  darr_t* lhs, {arr_type}* rhs, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_matmul_OO(    {arr_type}* lhs, {arr_type}* rhs);
{arr_type} {arr_func}_matmul_OR(    {arr_type}* lhs,  darr_t* rhs);
{arr_type} {arr_func}_matmul_RO(     darr_t* lhs, {arr_type}* rhs);

void    {arr_func}_matmul_OO_to( {arr_type}* lhs, {arr_type}* rhs, {arr_type}* res);
void    {arr_func}_matmul_OR_to( {arr_type}* lhs,  darr_t* rhs, {arr_type}* res);
void    {arr_func}_matmul_RO_to(  darr_t* lhs, {arr_type}* rhs, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_type}ranspose(    {arr_type}* arr1);
void    {arr_type}ranspose_to( {arr_type}* arr1, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_invert(    {arr_type}* arr1);
void    {arr_func}_invert_to( {arr_type}* arr1, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{num_type} {arr_func}_det(    {arr_type}* arr1);
void      {arr_func}_det_to( {arr_type}* arr1, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{num_type} {arr_func}_norm(    {arr_type}* arr1);
void      {arr_func}_norm_to( {arr_type}* arr1,  {num_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
{num_type} {arr_func}_pnorm(    {arr_type}* arr1, coeff_t p);
void      {arr_func}_pnorm_to( {arr_type}* arr1, coeff_t p, {num_type}* res);
// ----------------------------------------------------------------------------------------------------

#endif