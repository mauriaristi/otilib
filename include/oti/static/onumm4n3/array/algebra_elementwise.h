#ifndef OTI_ONUMM4N3_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_ONUMM4N3_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm4n3_t oarrm4n3_neg(oarrm4n3_t* arr);

void oarrm4n3_neg_to(oarrm4n3_t* rhs, oarrm4n3_t* res);
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
oarrm4n3_t oarrm4n3_sum_OO(oarrm4n3_t*   lhs, oarrm4n3_t* rhs);
oarrm4n3_t oarrm4n3_sum_RO(darr_t*    lhs, oarrm4n3_t* rhs);
oarrm4n3_t oarrm4n3_sum_oO(onumm4n3_t* lhs, oarrm4n3_t* rhs);
oarrm4n3_t oarrm4n3_sum_rO(coeff_t    lhs, oarrm4n3_t* rhs);

void oarrm4n3_sum_OO_to(oarrm4n3_t*   lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
void oarrm4n3_sum_RO_to(darr_t*    lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
void oarrm4n3_sum_oO_to(onumm4n3_t* lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
void oarrm4n3_sum_rO_to(coeff_t    lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
void oarrm4n3_trunc_sum_OO_to(ord_t order, oarrm4n3_t* arr1, oarrm4n3_t* arr2, oarrm4n3_t* res);
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
oarrm4n3_t oarrm4n3_sub_OO(oarrm4n3_t*   lhs, oarrm4n3_t*   rhs);
oarrm4n3_t oarrm4n3_sub_RO(darr_t*    lhs, oarrm4n3_t*   rhs);
oarrm4n3_t oarrm4n3_sub_OR(oarrm4n3_t*   lhs, darr_t*    rhs);
oarrm4n3_t oarrm4n3_sub_oO(onumm4n3_t* lhs, oarrm4n3_t*   rhs);
oarrm4n3_t oarrm4n3_sub_Oo(oarrm4n3_t*   lhs, onumm4n3_t* rhs);
oarrm4n3_t oarrm4n3_sub_rO(coeff_t    lhs, oarrm4n3_t*   rhs);
oarrm4n3_t oarrm4n3_sub_Or(oarrm4n3_t*   lhs, coeff_t    rhs);

void oarrm4n3_sub_OO_to( oarrm4n3_t*   lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
void oarrm4n3_sub_RO_to( darr_t*    lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
void oarrm4n3_sub_OR_to( oarrm4n3_t*   lhs, darr_t*    rhs, oarrm4n3_t* res);
void oarrm4n3_sub_oO_to( onumm4n3_t* lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
void oarrm4n3_sub_Oo_to( oarrm4n3_t*   lhs, onumm4n3_t* rhs, oarrm4n3_t* res);
void oarrm4n3_sub_rO_to( coeff_t    lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
void oarrm4n3_sub_Or_to( oarrm4n3_t*   lhs, coeff_t    rhs, oarrm4n3_t* res);
void oarrm4n3_trunc_sub_OO_to(ord_t order, oarrm4n3_t* arr1, oarrm4n3_t* arr2, oarrm4n3_t* res);
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
oarrm4n3_t oarrm4n3_mul_OO(oarrm4n3_t*   lhs, oarrm4n3_t* rhs);
oarrm4n3_t oarrm4n3_mul_RO(darr_t*    lhs, oarrm4n3_t* rhs);
oarrm4n3_t oarrm4n3_mul_oO(onumm4n3_t* lhs, oarrm4n3_t* rhs);
oarrm4n3_t oarrm4n3_mul_rO(coeff_t    lhs, oarrm4n3_t* rhs);

void oarrm4n3_mul_OO_to(oarrm4n3_t*   lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
void oarrm4n3_mul_RO_to(darr_t*    lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
void oarrm4n3_mul_oO_to(onumm4n3_t* lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);
void oarrm4n3_mul_rO_to(coeff_t    lhs, oarrm4n3_t* rhs, oarrm4n3_t* res);

// ARR1 * ARR2 + ARR3
void oarrm4n3_gem_OO_to(  oarrm4n3_t* arr1, oarrm4n3_t* arr2, oarrm4n3_t* arr3, oarrm4n3_t* res);
void oarrm4n3_gem_oO_to(onumm4n3_t* arr1, oarrm4n3_t* arr2, oarrm4n3_t* arr3, oarrm4n3_t* res);
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
oarrm4n3_t oarrm4n3_div_OO(oarrm4n3_t*   lhs, oarrm4n3_t*   rhs);
oarrm4n3_t oarrm4n3_div_OR(oarrm4n3_t*   lhs, darr_t*    rhs);
oarrm4n3_t oarrm4n3_div_RO(darr_t*    lhs, oarrm4n3_t*   rhs);
oarrm4n3_t oarrm4n3_div_oO(onumm4n3_t* lhs, oarrm4n3_t*   rhs);
oarrm4n3_t oarrm4n3_div_Oo(oarrm4n3_t*   lhs, onumm4n3_t* rhs);
oarrm4n3_t oarrm4n3_div_rO(coeff_t    lhs, oarrm4n3_t*   rhs);
oarrm4n3_t oarrm4n3_div_Or(oarrm4n3_t*   lhs, coeff_t    rhs);

void oarrm4n3_div_OO_to(oarrm4n3_t*   lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
void oarrm4n3_div_RO_to(darr_t*    lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
void oarrm4n3_div_OR_to(oarrm4n3_t*   lhs, darr_t*    rhs, oarrm4n3_t* res);
void oarrm4n3_div_oO_to(onumm4n3_t* lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
void oarrm4n3_div_Oo_to(oarrm4n3_t*   lhs, onumm4n3_t* rhs, oarrm4n3_t* res);
void oarrm4n3_div_rO_to(coeff_t    lhs, oarrm4n3_t*   rhs, oarrm4n3_t* res);
void oarrm4n3_div_Or_to(oarrm4n3_t*   lhs, coeff_t    rhs, oarrm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
