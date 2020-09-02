#ifndef OTI_ONUMM2N10_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_ONUMM2N10_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm2n10_t oarrm2n10_neg(oarrm2n10_t* arr);

void oarrm2n10_neg_to(oarrm2n10_t* rhs, oarrm2n10_t* res);
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
oarrm2n10_t oarrm2n10_sum_OO(oarrm2n10_t*   lhs, oarrm2n10_t* rhs);
oarrm2n10_t oarrm2n10_sum_RO(darr_t*    lhs, oarrm2n10_t* rhs);
oarrm2n10_t oarrm2n10_sum_oO(onumm2n10_t* lhs, oarrm2n10_t* rhs);
oarrm2n10_t oarrm2n10_sum_rO(coeff_t    lhs, oarrm2n10_t* rhs);

void oarrm2n10_sum_OO_to(oarrm2n10_t*   lhs, oarrm2n10_t* rhs, oarrm2n10_t* res);
void oarrm2n10_sum_RO_to(darr_t*    lhs, oarrm2n10_t* rhs, oarrm2n10_t* res);
void oarrm2n10_sum_oO_to(onumm2n10_t* lhs, oarrm2n10_t* rhs, oarrm2n10_t* res);
void oarrm2n10_sum_rO_to(coeff_t    lhs, oarrm2n10_t* rhs, oarrm2n10_t* res);
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
oarrm2n10_t oarrm2n10_sub_OO(oarrm2n10_t*   lhs, oarrm2n10_t*   rhs);
oarrm2n10_t oarrm2n10_sub_RO(darr_t*    lhs, oarrm2n10_t*   rhs);
oarrm2n10_t oarrm2n10_sub_OR(oarrm2n10_t*   lhs, darr_t*    rhs);
oarrm2n10_t oarrm2n10_sub_oO(onumm2n10_t* lhs, oarrm2n10_t*   rhs);
oarrm2n10_t oarrm2n10_sub_Oo(oarrm2n10_t*   lhs, onumm2n10_t* rhs);
oarrm2n10_t oarrm2n10_sub_rO(coeff_t    lhs, oarrm2n10_t*   rhs);
oarrm2n10_t oarrm2n10_sub_Or(oarrm2n10_t*   lhs, coeff_t    rhs);

void oarrm2n10_sub_OO_to( oarrm2n10_t*   lhs, oarrm2n10_t*   rhs, oarrm2n10_t* res);
void oarrm2n10_sub_RO_to( darr_t*    lhs, oarrm2n10_t*   rhs, oarrm2n10_t* res);
void oarrm2n10_sub_OR_to( oarrm2n10_t*   lhs, darr_t*    rhs, oarrm2n10_t* res);
void oarrm2n10_sub_oO_to( onumm2n10_t* lhs, oarrm2n10_t*   rhs, oarrm2n10_t* res);
void oarrm2n10_sub_Oo_to( oarrm2n10_t*   lhs, onumm2n10_t* rhs, oarrm2n10_t* res);
void oarrm2n10_sub_rO_to( coeff_t    lhs, oarrm2n10_t*   rhs, oarrm2n10_t* res);
void oarrm2n10_sub_Or_to( oarrm2n10_t*   lhs, coeff_t    rhs, oarrm2n10_t* res);
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
oarrm2n10_t oarrm2n10_mul_OO(oarrm2n10_t*   lhs, oarrm2n10_t* rhs);
oarrm2n10_t oarrm2n10_mul_RO(darr_t*    lhs, oarrm2n10_t* rhs);
oarrm2n10_t oarrm2n10_mul_oO(onumm2n10_t* lhs, oarrm2n10_t* rhs);
oarrm2n10_t oarrm2n10_mul_rO(coeff_t    lhs, oarrm2n10_t* rhs);

void oarrm2n10_mul_OO_to(oarrm2n10_t*   lhs, oarrm2n10_t* rhs, oarrm2n10_t* res);
void oarrm2n10_mul_RO_to(darr_t*    lhs, oarrm2n10_t* rhs, oarrm2n10_t* res);
void oarrm2n10_mul_oO_to(onumm2n10_t* lhs, oarrm2n10_t* rhs, oarrm2n10_t* res);
void oarrm2n10_mul_rO_to(coeff_t    lhs, oarrm2n10_t* rhs, oarrm2n10_t* res);

// ARR1 * ARR2 + ARR3
void oarrm2n10_gem_OO_to(  oarrm2n10_t* arr1, oarrm2n10_t* arr2, oarrm2n10_t* arr3, oarrm2n10_t* res);
void oarrm2n10_gem_oO_to(onumm2n10_t* arr1, oarrm2n10_t* arr2, oarrm2n10_t* arr3, oarrm2n10_t* res);
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
oarrm2n10_t oarrm2n10_div_OO(oarrm2n10_t*   lhs, oarrm2n10_t*   rhs);
oarrm2n10_t oarrm2n10_div_OR(oarrm2n10_t*   lhs, darr_t*    rhs);
oarrm2n10_t oarrm2n10_div_RO(darr_t*    lhs, oarrm2n10_t*   rhs);
oarrm2n10_t oarrm2n10_div_oO(onumm2n10_t* lhs, oarrm2n10_t*   rhs);
oarrm2n10_t oarrm2n10_div_Oo(oarrm2n10_t*   lhs, onumm2n10_t* rhs);
oarrm2n10_t oarrm2n10_div_rO(coeff_t    lhs, oarrm2n10_t*   rhs);
oarrm2n10_t oarrm2n10_div_Or(oarrm2n10_t*   lhs, coeff_t    rhs);

void oarrm2n10_div_OO_to(oarrm2n10_t*   lhs, oarrm2n10_t*   rhs, oarrm2n10_t* res);
void oarrm2n10_div_RO_to(darr_t*    lhs, oarrm2n10_t*   rhs, oarrm2n10_t* res);
void oarrm2n10_div_OR_to(oarrm2n10_t*   lhs, darr_t*    rhs, oarrm2n10_t* res);
void oarrm2n10_div_oO_to(onumm2n10_t* lhs, oarrm2n10_t*   rhs, oarrm2n10_t* res);
void oarrm2n10_div_Oo_to(oarrm2n10_t*   lhs, onumm2n10_t* rhs, oarrm2n10_t* res);
void oarrm2n10_div_rO_to(coeff_t    lhs, oarrm2n10_t*   rhs, oarrm2n10_t* res);
void oarrm2n10_div_Or_to(oarrm2n10_t*   lhs, coeff_t    rhs, oarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
