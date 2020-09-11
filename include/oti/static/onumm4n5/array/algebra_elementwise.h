#ifndef OTI_ONUMM4N5_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_ONUMM4N5_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm4n5_t oarrm4n5_neg(oarrm4n5_t* arr);

void oarrm4n5_neg_to(oarrm4n5_t* rhs, oarrm4n5_t* res);
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
oarrm4n5_t oarrm4n5_sum_OO(oarrm4n5_t*   lhs, oarrm4n5_t* rhs);
oarrm4n5_t oarrm4n5_sum_RO(darr_t*    lhs, oarrm4n5_t* rhs);
oarrm4n5_t oarrm4n5_sum_oO(onumm4n5_t* lhs, oarrm4n5_t* rhs);
oarrm4n5_t oarrm4n5_sum_rO(coeff_t    lhs, oarrm4n5_t* rhs);

void oarrm4n5_sum_OO_to(oarrm4n5_t*   lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
void oarrm4n5_sum_RO_to(darr_t*    lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
void oarrm4n5_sum_oO_to(onumm4n5_t* lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
void oarrm4n5_sum_rO_to(coeff_t    lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
void oarrm4n5_trunc_sum_OO_to(ord_t order, oarrm4n5_t* arr1, oarrm4n5_t* arr2, oarrm4n5_t* res);
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
oarrm4n5_t oarrm4n5_sub_OO(oarrm4n5_t*   lhs, oarrm4n5_t*   rhs);
oarrm4n5_t oarrm4n5_sub_RO(darr_t*    lhs, oarrm4n5_t*   rhs);
oarrm4n5_t oarrm4n5_sub_OR(oarrm4n5_t*   lhs, darr_t*    rhs);
oarrm4n5_t oarrm4n5_sub_oO(onumm4n5_t* lhs, oarrm4n5_t*   rhs);
oarrm4n5_t oarrm4n5_sub_Oo(oarrm4n5_t*   lhs, onumm4n5_t* rhs);
oarrm4n5_t oarrm4n5_sub_rO(coeff_t    lhs, oarrm4n5_t*   rhs);
oarrm4n5_t oarrm4n5_sub_Or(oarrm4n5_t*   lhs, coeff_t    rhs);

void oarrm4n5_sub_OO_to( oarrm4n5_t*   lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
void oarrm4n5_sub_RO_to( darr_t*    lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
void oarrm4n5_sub_OR_to( oarrm4n5_t*   lhs, darr_t*    rhs, oarrm4n5_t* res);
void oarrm4n5_sub_oO_to( onumm4n5_t* lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
void oarrm4n5_sub_Oo_to( oarrm4n5_t*   lhs, onumm4n5_t* rhs, oarrm4n5_t* res);
void oarrm4n5_sub_rO_to( coeff_t    lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
void oarrm4n5_sub_Or_to( oarrm4n5_t*   lhs, coeff_t    rhs, oarrm4n5_t* res);
void oarrm4n5_trunc_sub_OO_to(ord_t order, oarrm4n5_t* arr1, oarrm4n5_t* arr2, oarrm4n5_t* res);
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
oarrm4n5_t oarrm4n5_mul_OO(oarrm4n5_t*   lhs, oarrm4n5_t* rhs);
oarrm4n5_t oarrm4n5_mul_RO(darr_t*    lhs, oarrm4n5_t* rhs);
oarrm4n5_t oarrm4n5_mul_oO(onumm4n5_t* lhs, oarrm4n5_t* rhs);
oarrm4n5_t oarrm4n5_mul_rO(coeff_t    lhs, oarrm4n5_t* rhs);

void oarrm4n5_mul_OO_to(oarrm4n5_t*   lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
void oarrm4n5_mul_RO_to(darr_t*    lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
void oarrm4n5_mul_oO_to(onumm4n5_t* lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
void oarrm4n5_mul_rO_to(coeff_t    lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);

// ARR1 * ARR2 + ARR3
void oarrm4n5_gem_OO_to(  oarrm4n5_t* arr1, oarrm4n5_t* arr2, oarrm4n5_t* arr3, oarrm4n5_t* res);
void oarrm4n5_gem_oO_to(onumm4n5_t* arr1, oarrm4n5_t* arr2, oarrm4n5_t* arr3, oarrm4n5_t* res);
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
oarrm4n5_t oarrm4n5_div_OO(oarrm4n5_t*   lhs, oarrm4n5_t*   rhs);
oarrm4n5_t oarrm4n5_div_OR(oarrm4n5_t*   lhs, darr_t*    rhs);
oarrm4n5_t oarrm4n5_div_RO(darr_t*    lhs, oarrm4n5_t*   rhs);
oarrm4n5_t oarrm4n5_div_oO(onumm4n5_t* lhs, oarrm4n5_t*   rhs);
oarrm4n5_t oarrm4n5_div_Oo(oarrm4n5_t*   lhs, onumm4n5_t* rhs);
oarrm4n5_t oarrm4n5_div_rO(coeff_t    lhs, oarrm4n5_t*   rhs);
oarrm4n5_t oarrm4n5_div_Or(oarrm4n5_t*   lhs, coeff_t    rhs);

void oarrm4n5_div_OO_to(oarrm4n5_t*   lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
void oarrm4n5_div_RO_to(darr_t*    lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
void oarrm4n5_div_OR_to(oarrm4n5_t*   lhs, darr_t*    rhs, oarrm4n5_t* res);
void oarrm4n5_div_oO_to(onumm4n5_t* lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
void oarrm4n5_div_Oo_to(oarrm4n5_t*   lhs, onumm4n5_t* rhs, oarrm4n5_t* res);
void oarrm4n5_div_rO_to(coeff_t    lhs, oarrm4n5_t*   rhs, oarrm4n5_t* res);
void oarrm4n5_div_Or_to(oarrm4n5_t*   lhs, coeff_t    rhs, oarrm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
