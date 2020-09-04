#ifndef OTI_ONUMM8N1_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_ONUMM8N1_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm8n1_t oarrm8n1_neg(oarrm8n1_t* arr);

void oarrm8n1_neg_to(oarrm8n1_t* rhs, oarrm8n1_t* res);
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
oarrm8n1_t oarrm8n1_sum_OO(oarrm8n1_t*   lhs, oarrm8n1_t* rhs);
oarrm8n1_t oarrm8n1_sum_RO(darr_t*    lhs, oarrm8n1_t* rhs);
oarrm8n1_t oarrm8n1_sum_oO(onumm8n1_t* lhs, oarrm8n1_t* rhs);
oarrm8n1_t oarrm8n1_sum_rO(coeff_t    lhs, oarrm8n1_t* rhs);

void oarrm8n1_sum_OO_to(oarrm8n1_t*   lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
void oarrm8n1_sum_RO_to(darr_t*    lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
void oarrm8n1_sum_oO_to(onumm8n1_t* lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
void oarrm8n1_sum_rO_to(coeff_t    lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
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
oarrm8n1_t oarrm8n1_sub_OO(oarrm8n1_t*   lhs, oarrm8n1_t*   rhs);
oarrm8n1_t oarrm8n1_sub_RO(darr_t*    lhs, oarrm8n1_t*   rhs);
oarrm8n1_t oarrm8n1_sub_OR(oarrm8n1_t*   lhs, darr_t*    rhs);
oarrm8n1_t oarrm8n1_sub_oO(onumm8n1_t* lhs, oarrm8n1_t*   rhs);
oarrm8n1_t oarrm8n1_sub_Oo(oarrm8n1_t*   lhs, onumm8n1_t* rhs);
oarrm8n1_t oarrm8n1_sub_rO(coeff_t    lhs, oarrm8n1_t*   rhs);
oarrm8n1_t oarrm8n1_sub_Or(oarrm8n1_t*   lhs, coeff_t    rhs);

void oarrm8n1_sub_OO_to( oarrm8n1_t*   lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
void oarrm8n1_sub_RO_to( darr_t*    lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
void oarrm8n1_sub_OR_to( oarrm8n1_t*   lhs, darr_t*    rhs, oarrm8n1_t* res);
void oarrm8n1_sub_oO_to( onumm8n1_t* lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
void oarrm8n1_sub_Oo_to( oarrm8n1_t*   lhs, onumm8n1_t* rhs, oarrm8n1_t* res);
void oarrm8n1_sub_rO_to( coeff_t    lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
void oarrm8n1_sub_Or_to( oarrm8n1_t*   lhs, coeff_t    rhs, oarrm8n1_t* res);
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
oarrm8n1_t oarrm8n1_mul_OO(oarrm8n1_t*   lhs, oarrm8n1_t* rhs);
oarrm8n1_t oarrm8n1_mul_RO(darr_t*    lhs, oarrm8n1_t* rhs);
oarrm8n1_t oarrm8n1_mul_oO(onumm8n1_t* lhs, oarrm8n1_t* rhs);
oarrm8n1_t oarrm8n1_mul_rO(coeff_t    lhs, oarrm8n1_t* rhs);

void oarrm8n1_mul_OO_to(oarrm8n1_t*   lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
void oarrm8n1_mul_RO_to(darr_t*    lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
void oarrm8n1_mul_oO_to(onumm8n1_t* lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);
void oarrm8n1_mul_rO_to(coeff_t    lhs, oarrm8n1_t* rhs, oarrm8n1_t* res);

// ARR1 * ARR2 + ARR3
void oarrm8n1_gem_OO_to(  oarrm8n1_t* arr1, oarrm8n1_t* arr2, oarrm8n1_t* arr3, oarrm8n1_t* res);
void oarrm8n1_gem_oO_to(onumm8n1_t* arr1, oarrm8n1_t* arr2, oarrm8n1_t* arr3, oarrm8n1_t* res);
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
oarrm8n1_t oarrm8n1_div_OO(oarrm8n1_t*   lhs, oarrm8n1_t*   rhs);
oarrm8n1_t oarrm8n1_div_OR(oarrm8n1_t*   lhs, darr_t*    rhs);
oarrm8n1_t oarrm8n1_div_RO(darr_t*    lhs, oarrm8n1_t*   rhs);
oarrm8n1_t oarrm8n1_div_oO(onumm8n1_t* lhs, oarrm8n1_t*   rhs);
oarrm8n1_t oarrm8n1_div_Oo(oarrm8n1_t*   lhs, onumm8n1_t* rhs);
oarrm8n1_t oarrm8n1_div_rO(coeff_t    lhs, oarrm8n1_t*   rhs);
oarrm8n1_t oarrm8n1_div_Or(oarrm8n1_t*   lhs, coeff_t    rhs);

void oarrm8n1_div_OO_to(oarrm8n1_t*   lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
void oarrm8n1_div_RO_to(darr_t*    lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
void oarrm8n1_div_OR_to(oarrm8n1_t*   lhs, darr_t*    rhs, oarrm8n1_t* res);
void oarrm8n1_div_oO_to(onumm8n1_t* lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
void oarrm8n1_div_Oo_to(oarrm8n1_t*   lhs, onumm8n1_t* rhs, oarrm8n1_t* res);
void oarrm8n1_div_rO_to(coeff_t    lhs, oarrm8n1_t*   rhs, oarrm8n1_t* res);
void oarrm8n1_div_Or_to(oarrm8n1_t*   lhs, coeff_t    rhs, oarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
