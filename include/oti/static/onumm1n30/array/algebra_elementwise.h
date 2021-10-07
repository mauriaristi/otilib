#ifndef OTI_ONUMM1N30_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_ONUMM1N30_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm1n30_t oarrm1n30_neg(oarrm1n30_t* arr);

void oarrm1n30_neg_to(oarrm1n30_t* rhs, oarrm1n30_t* res);
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
oarrm1n30_t oarrm1n30_sum_OO(oarrm1n30_t*   lhs, oarrm1n30_t* rhs);
oarrm1n30_t oarrm1n30_sum_RO(darr_t*    lhs, oarrm1n30_t* rhs);
oarrm1n30_t oarrm1n30_sum_oO(onumm1n30_t* lhs, oarrm1n30_t* rhs);
oarrm1n30_t oarrm1n30_sum_rO(coeff_t    lhs, oarrm1n30_t* rhs);

void oarrm1n30_sum_OO_to(oarrm1n30_t*   lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
void oarrm1n30_sum_RO_to(darr_t*    lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
void oarrm1n30_sum_oO_to(onumm1n30_t* lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
void oarrm1n30_sum_rO_to(coeff_t    lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
void oarrm1n30_trunc_sum_OO_to(ord_t order, oarrm1n30_t* arr1, oarrm1n30_t* arr2, oarrm1n30_t* res);
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
oarrm1n30_t oarrm1n30_sub_OO(oarrm1n30_t*   lhs, oarrm1n30_t*   rhs);
oarrm1n30_t oarrm1n30_sub_RO(darr_t*    lhs, oarrm1n30_t*   rhs);
oarrm1n30_t oarrm1n30_sub_OR(oarrm1n30_t*   lhs, darr_t*    rhs);
oarrm1n30_t oarrm1n30_sub_oO(onumm1n30_t* lhs, oarrm1n30_t*   rhs);
oarrm1n30_t oarrm1n30_sub_Oo(oarrm1n30_t*   lhs, onumm1n30_t* rhs);
oarrm1n30_t oarrm1n30_sub_rO(coeff_t    lhs, oarrm1n30_t*   rhs);
oarrm1n30_t oarrm1n30_sub_Or(oarrm1n30_t*   lhs, coeff_t    rhs);

void oarrm1n30_sub_OO_to( oarrm1n30_t*   lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
void oarrm1n30_sub_RO_to( darr_t*    lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
void oarrm1n30_sub_OR_to( oarrm1n30_t*   lhs, darr_t*    rhs, oarrm1n30_t* res);
void oarrm1n30_sub_oO_to( onumm1n30_t* lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
void oarrm1n30_sub_Oo_to( oarrm1n30_t*   lhs, onumm1n30_t* rhs, oarrm1n30_t* res);
void oarrm1n30_sub_rO_to( coeff_t    lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
void oarrm1n30_sub_Or_to( oarrm1n30_t*   lhs, coeff_t    rhs, oarrm1n30_t* res);
void oarrm1n30_trunc_sub_OO_to(ord_t order, oarrm1n30_t* arr1, oarrm1n30_t* arr2, oarrm1n30_t* res);
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
oarrm1n30_t oarrm1n30_mul_OO(oarrm1n30_t*   lhs, oarrm1n30_t* rhs);
oarrm1n30_t oarrm1n30_mul_RO(darr_t*    lhs, oarrm1n30_t* rhs);
oarrm1n30_t oarrm1n30_mul_oO(onumm1n30_t* lhs, oarrm1n30_t* rhs);
oarrm1n30_t oarrm1n30_mul_rO(coeff_t    lhs, oarrm1n30_t* rhs);

void oarrm1n30_mul_OO_to(oarrm1n30_t*   lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
void oarrm1n30_mul_RO_to(darr_t*    lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
void oarrm1n30_mul_oO_to(onumm1n30_t* lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);
void oarrm1n30_mul_rO_to(coeff_t    lhs, oarrm1n30_t* rhs, oarrm1n30_t* res);

// ARR1 * ARR2 + ARR3
void oarrm1n30_gem_OO_to(  oarrm1n30_t* arr1, oarrm1n30_t* arr2, oarrm1n30_t* arr3, oarrm1n30_t* res);
void oarrm1n30_gem_oO_to(onumm1n30_t* arr1, oarrm1n30_t* arr2, oarrm1n30_t* arr3, oarrm1n30_t* res);
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
oarrm1n30_t oarrm1n30_div_OO(oarrm1n30_t*   lhs, oarrm1n30_t*   rhs);
oarrm1n30_t oarrm1n30_div_OR(oarrm1n30_t*   lhs, darr_t*    rhs);
oarrm1n30_t oarrm1n30_div_RO(darr_t*    lhs, oarrm1n30_t*   rhs);
oarrm1n30_t oarrm1n30_div_oO(onumm1n30_t* lhs, oarrm1n30_t*   rhs);
oarrm1n30_t oarrm1n30_div_Oo(oarrm1n30_t*   lhs, onumm1n30_t* rhs);
oarrm1n30_t oarrm1n30_div_rO(coeff_t    lhs, oarrm1n30_t*   rhs);
oarrm1n30_t oarrm1n30_div_Or(oarrm1n30_t*   lhs, coeff_t    rhs);

void oarrm1n30_div_OO_to(oarrm1n30_t*   lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
void oarrm1n30_div_RO_to(darr_t*    lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
void oarrm1n30_div_OR_to(oarrm1n30_t*   lhs, darr_t*    rhs, oarrm1n30_t* res);
void oarrm1n30_div_oO_to(onumm1n30_t* lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
void oarrm1n30_div_Oo_to(oarrm1n30_t*   lhs, onumm1n30_t* rhs, oarrm1n30_t* res);
void oarrm1n30_div_rO_to(coeff_t    lhs, oarrm1n30_t*   rhs, oarrm1n30_t* res);
void oarrm1n30_div_Or_to(oarrm1n30_t*   lhs, coeff_t    rhs, oarrm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
