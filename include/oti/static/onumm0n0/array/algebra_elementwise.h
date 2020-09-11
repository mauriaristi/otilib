#ifndef OTI_ONUMM0N0_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_ONUMM0N0_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm0n0_t oarrm0n0_neg(oarrm0n0_t* arr);

void oarrm0n0_neg_to(oarrm0n0_t* rhs, oarrm0n0_t* res);
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
oarrm0n0_t oarrm0n0_sum_OO(oarrm0n0_t*   lhs, oarrm0n0_t* rhs);
oarrm0n0_t oarrm0n0_sum_RO(darr_t*    lhs, oarrm0n0_t* rhs);
oarrm0n0_t oarrm0n0_sum_oO(onumm0n0_t* lhs, oarrm0n0_t* rhs);
oarrm0n0_t oarrm0n0_sum_rO(coeff_t    lhs, oarrm0n0_t* rhs);

void oarrm0n0_sum_OO_to(oarrm0n0_t*   lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
void oarrm0n0_sum_RO_to(darr_t*    lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
void oarrm0n0_sum_oO_to(onumm0n0_t* lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
void oarrm0n0_sum_rO_to(coeff_t    lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
void oarrm0n0_trunc_sum_OO_to(ord_t order, oarrm0n0_t* arr1, oarrm0n0_t* arr2, oarrm0n0_t* res);
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
oarrm0n0_t oarrm0n0_sub_OO(oarrm0n0_t*   lhs, oarrm0n0_t*   rhs);
oarrm0n0_t oarrm0n0_sub_RO(darr_t*    lhs, oarrm0n0_t*   rhs);
oarrm0n0_t oarrm0n0_sub_OR(oarrm0n0_t*   lhs, darr_t*    rhs);
oarrm0n0_t oarrm0n0_sub_oO(onumm0n0_t* lhs, oarrm0n0_t*   rhs);
oarrm0n0_t oarrm0n0_sub_Oo(oarrm0n0_t*   lhs, onumm0n0_t* rhs);
oarrm0n0_t oarrm0n0_sub_rO(coeff_t    lhs, oarrm0n0_t*   rhs);
oarrm0n0_t oarrm0n0_sub_Or(oarrm0n0_t*   lhs, coeff_t    rhs);

void oarrm0n0_sub_OO_to( oarrm0n0_t*   lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
void oarrm0n0_sub_RO_to( darr_t*    lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
void oarrm0n0_sub_OR_to( oarrm0n0_t*   lhs, darr_t*    rhs, oarrm0n0_t* res);
void oarrm0n0_sub_oO_to( onumm0n0_t* lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
void oarrm0n0_sub_Oo_to( oarrm0n0_t*   lhs, onumm0n0_t* rhs, oarrm0n0_t* res);
void oarrm0n0_sub_rO_to( coeff_t    lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
void oarrm0n0_sub_Or_to( oarrm0n0_t*   lhs, coeff_t    rhs, oarrm0n0_t* res);
void oarrm0n0_trunc_sub_OO_to(ord_t order, oarrm0n0_t* arr1, oarrm0n0_t* arr2, oarrm0n0_t* res);
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
oarrm0n0_t oarrm0n0_mul_OO(oarrm0n0_t*   lhs, oarrm0n0_t* rhs);
oarrm0n0_t oarrm0n0_mul_RO(darr_t*    lhs, oarrm0n0_t* rhs);
oarrm0n0_t oarrm0n0_mul_oO(onumm0n0_t* lhs, oarrm0n0_t* rhs);
oarrm0n0_t oarrm0n0_mul_rO(coeff_t    lhs, oarrm0n0_t* rhs);

void oarrm0n0_mul_OO_to(oarrm0n0_t*   lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
void oarrm0n0_mul_RO_to(darr_t*    lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
void oarrm0n0_mul_oO_to(onumm0n0_t* lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
void oarrm0n0_mul_rO_to(coeff_t    lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);

// ARR1 * ARR2 + ARR3
void oarrm0n0_gem_OO_to(  oarrm0n0_t* arr1, oarrm0n0_t* arr2, oarrm0n0_t* arr3, oarrm0n0_t* res);
void oarrm0n0_gem_oO_to(onumm0n0_t* arr1, oarrm0n0_t* arr2, oarrm0n0_t* arr3, oarrm0n0_t* res);
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
oarrm0n0_t oarrm0n0_div_OO(oarrm0n0_t*   lhs, oarrm0n0_t*   rhs);
oarrm0n0_t oarrm0n0_div_OR(oarrm0n0_t*   lhs, darr_t*    rhs);
oarrm0n0_t oarrm0n0_div_RO(darr_t*    lhs, oarrm0n0_t*   rhs);
oarrm0n0_t oarrm0n0_div_oO(onumm0n0_t* lhs, oarrm0n0_t*   rhs);
oarrm0n0_t oarrm0n0_div_Oo(oarrm0n0_t*   lhs, onumm0n0_t* rhs);
oarrm0n0_t oarrm0n0_div_rO(coeff_t    lhs, oarrm0n0_t*   rhs);
oarrm0n0_t oarrm0n0_div_Or(oarrm0n0_t*   lhs, coeff_t    rhs);

void oarrm0n0_div_OO_to(oarrm0n0_t*   lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
void oarrm0n0_div_RO_to(darr_t*    lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
void oarrm0n0_div_OR_to(oarrm0n0_t*   lhs, darr_t*    rhs, oarrm0n0_t* res);
void oarrm0n0_div_oO_to(onumm0n0_t* lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
void oarrm0n0_div_Oo_to(oarrm0n0_t*   lhs, onumm0n0_t* rhs, oarrm0n0_t* res);
void oarrm0n0_div_rO_to(coeff_t    lhs, oarrm0n0_t*   rhs, oarrm0n0_t* res);
void oarrm0n0_div_Or_to(oarrm0n0_t*   lhs, coeff_t    rhs, oarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
