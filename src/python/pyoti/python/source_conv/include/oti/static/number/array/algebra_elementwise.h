#ifndef OTI_{module_name_upper}_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_{module_name_upper}_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_neg({arr_type}* arr);

void {arr_func}_neg_to({arr_type}* rhs, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Addition operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = lhs + rhs

- OO: Array of SOTIs   +  Array of SOTIs
- RO: Array of REALS   +  Array of SOTIs
- oO: OTI number       +  Array of SOTIs
- rO: Real number      +  Array of SOTIs

@param[in]    lhs    Left hand side element of the operation.
@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_sum_OO({arr_type}*   lhs, {arr_type}* rhs);
{arr_type} {arr_func}_sum_RO(darr_t*    lhs, {arr_type}* rhs);
{arr_type} {arr_func}_sum_oO({num_type}* lhs, {arr_type}* rhs);
{arr_type} {arr_func}_sum_rO(coeff_t    lhs, {arr_type}* rhs);

void {arr_func}_sum_OO_to({arr_type}*   lhs, {arr_type}* rhs, {arr_type}* res);
void {arr_func}_sum_RO_to(darr_t*    lhs, {arr_type}* rhs, {arr_type}* res);
void {arr_func}_sum_oO_to({num_type}* lhs, {arr_type}* rhs, {arr_type}* res);
void {arr_func}_sum_rO_to(coeff_t    lhs, {arr_type}* rhs, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtraction operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = lhs - rhs

- OO: Array of SOTIs   -  Array of SOTIs
- OR: Array of SOTIs   -  Real number
- RO: Array of REALS   -  Array of SOTIs
- Oo: Array of SOTIs   -  OTI number
- oO: OTI number       -  Array of SOTIs
- Or: Array of SOTIs   -  Real number
- rO: Real number      -  Array of SOTIs

@param[in]    lhs    Left hand side element of the operation.
@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_sub_OO({arr_type}*   lhs, {arr_type}*   rhs);
{arr_type} {arr_func}_sub_RO(darr_t*    lhs, {arr_type}*   rhs);
{arr_type} {arr_func}_sub_OR({arr_type}*   lhs, darr_t*    rhs);
{arr_type} {arr_func}_sub_oO({num_type}* lhs, {arr_type}*   rhs);
{arr_type} {arr_func}_sub_Oo({arr_type}*   lhs, {num_type}* rhs);
{arr_type} {arr_func}_sub_rO(coeff_t    lhs, {arr_type}*   rhs);
{arr_type} {arr_func}_sub_Or({arr_type}*   lhs, coeff_t    rhs);

void {arr_func}_sub_OO_to( {arr_type}*   lhs, {arr_type}*   rhs, {arr_type}* res);
void {arr_func}_sub_RO_to( darr_t*    lhs, {arr_type}*   rhs, {arr_type}* res);
void {arr_func}_sub_OR_to( {arr_type}*   lhs, darr_t*    rhs, {arr_type}* res);
void {arr_func}_sub_oO_to( {num_type}* lhs, {arr_type}*   rhs, {arr_type}* res);
void {arr_func}_sub_Oo_to( {arr_type}*   lhs, {num_type}* rhs, {arr_type}* res);
void {arr_func}_sub_rO_to( coeff_t    lhs, {arr_type}*   rhs, {arr_type}* res);
void {arr_func}_sub_Or_to( {arr_type}*   lhs, coeff_t    rhs, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiplication operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = lhs * rhs

- OO: Array of SOTIs   *  Array of SOTIs
- RO: Array of REALS   *  Array of SOTIs
- oO: OTI number       *  Array of SOTIs
- rO: Real number      *  Array of SOTIs

@param[in]    lhs    Left hand side element of the operation.
@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_mul_OO({arr_type}*   lhs, {arr_type}* rhs);
{arr_type} {arr_func}_mul_RO(darr_t*    lhs, {arr_type}* rhs);
{arr_type} {arr_func}_mul_oO({num_type}* lhs, {arr_type}* rhs);
{arr_type} {arr_func}_mul_rO(coeff_t    lhs, {arr_type}* rhs);

void {arr_func}_mul_OO_to({arr_type}*   lhs, {arr_type}* rhs, {arr_type}* res);
void {arr_func}_mul_RO_to(darr_t*    lhs, {arr_type}* rhs, {arr_type}* res);
void {arr_func}_mul_oO_to({num_type}* lhs, {arr_type}* rhs, {arr_type}* res);
void {arr_func}_mul_rO_to(coeff_t    lhs, {arr_type}* rhs, {arr_type}* res);

// ARR1 * ARR2 + ARR3
void {arr_func}_gem_OO_to(  {arr_type}* arr1, {arr_type}* arr2, {arr_type}* arr3, {arr_type}* res);
void {arr_func}_gem_oO_to({num_type}* arr1, {arr_type}* arr2, {arr_type}* arr3, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise division operation for array of sparse oti numbers object type. The following 
operations are supported:

       res = lhs / rhs

- OO: Array of SOTIs   /  Array of SOTIs
- OR: Array of SOTIs   /  Real number
- RO: Array of REALS   /  Array of SOTIs
- Oo: Array of SOTIs   /  OTI number
- oO: OTI number       /  Array of SOTIs
- Or: Array of SOTIs   /  Real number
- rO: Real number      /  Array of SOTIs

@param[in]    lhs    Left hand side element of the operation.
@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
{arr_type} {arr_func}_div_OO({arr_type}*   lhs, {arr_type}*   rhs);
{arr_type} {arr_func}_div_OR({arr_type}*   lhs, darr_t*    rhs);
{arr_type} {arr_func}_div_RO(darr_t*    lhs, {arr_type}*   rhs);
{arr_type} {arr_func}_div_oO({num_type}* lhs, {arr_type}*   rhs);
{arr_type} {arr_func}_div_Oo({arr_type}*   lhs, {num_type}* rhs);
{arr_type} {arr_func}_div_rO(coeff_t    lhs, {arr_type}*   rhs);
{arr_type} {arr_func}_div_Or({arr_type}*   lhs, coeff_t    rhs);

void {arr_func}_div_OO_to({arr_type}*   lhs, {arr_type}*   rhs, {arr_type}* res);
void {arr_func}_div_RO_to(darr_t*    lhs, {arr_type}*   rhs, {arr_type}* res);
void {arr_func}_div_OR_to({arr_type}*   lhs, darr_t*    rhs, {arr_type}* res);
void {arr_func}_div_oO_to({num_type}* lhs, {arr_type}*   rhs, {arr_type}* res);
void {arr_func}_div_Oo_to({arr_type}*   lhs, {num_type}* rhs, {arr_type}* res);
void {arr_func}_div_rO_to(coeff_t    lhs, {arr_type}*   rhs, {arr_type}* res);
void {arr_func}_div_Or_to({arr_type}*   lhs, coeff_t    rhs, {arr_type}* res);
// ----------------------------------------------------------------------------------------------------

#endif
