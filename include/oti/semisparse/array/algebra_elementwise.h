#ifndef OTI_SEMISPARSE_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_SEMISPARSE_ARRAY_ALGEBRA_ELEMENTWISE_H


/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
arrsso_t arrsso_neg(arrsso_t* arr, dhelpl_t dhl);

void arrsso_neg_to(arrsso_t* rhs, arrsso_t* res, dhelpl_t dhl);
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
arrsso_t arrsso_sum_OO(arrsso_t*   lhs, arrsso_t* rhs, dhelpl_t dhl);
arrsso_t arrsso_sum_RO(darr_t*    lhs, arrsso_t* rhs, dhelpl_t dhl);
arrsso_t arrsso_sum_oO(semiotin_t* lhs, arrsso_t* rhs, dhelpl_t dhl);
arrsso_t arrsso_sum_rO(coeff_t    lhs, arrsso_t* rhs, dhelpl_t dhl);

void arrsso_sum_OO_to(arrsso_t*   lhs, arrsso_t* rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_sum_RO_to(darr_t*    lhs, arrsso_t* rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_sum_oO_to(semiotin_t* lhs, arrsso_t* rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_sum_rO_to(coeff_t    lhs, arrsso_t* rhs, arrsso_t* res, dhelpl_t dhl);
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
arrsso_t arrsso_sub_OO(arrsso_t*   lhs, arrsso_t*   rhs, dhelpl_t dhl);
arrsso_t arrsso_sub_RO(darr_t*    lhs, arrsso_t*   rhs, dhelpl_t dhl);
arrsso_t arrsso_sub_OR(arrsso_t*   lhs, darr_t*    rhs, dhelpl_t dhl);
arrsso_t arrsso_sub_oO(semiotin_t* lhs, arrsso_t*   rhs, dhelpl_t dhl);
arrsso_t arrsso_sub_Oo(arrsso_t*   lhs, semiotin_t* rhs, dhelpl_t dhl);
arrsso_t arrsso_sub_rO(coeff_t    lhs, arrsso_t*   rhs, dhelpl_t dhl);
arrsso_t arrsso_sub_Or(arrsso_t*   lhs, coeff_t    rhs, dhelpl_t dhl);

void arrsso_sub_OO_to( arrsso_t*   lhs, arrsso_t*   rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_sub_RO_to( darr_t*    lhs, arrsso_t*   rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_sub_OR_to( arrsso_t*   lhs, darr_t*    rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_sub_oO_to( semiotin_t* lhs, arrsso_t*   rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_sub_Oo_to( arrsso_t*   lhs, semiotin_t* rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_sub_rO_to( coeff_t    lhs, arrsso_t*   rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_sub_Or_to( arrsso_t*   lhs, coeff_t    rhs, arrsso_t* res, dhelpl_t dhl);

void arrsso_trunc_sub_OO_to( ord_t ord, arrsso_t* arr1, arrsso_t* arr2, arrsso_t* res, dhelpl_t dhl);
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
arrsso_t arrsso_mul_OO(arrsso_t*   lhs, arrsso_t* rhs, dhelpl_t dhl);
arrsso_t arrsso_mul_RO(darr_t*    lhs, arrsso_t* rhs, dhelpl_t dhl);
arrsso_t arrsso_mul_oO(semiotin_t* lhs, arrsso_t* rhs, dhelpl_t dhl);
arrsso_t arrsso_mul_rO(coeff_t    lhs, arrsso_t* rhs, dhelpl_t dhl);

void arrsso_mul_OO_to(arrsso_t*   lhs, arrsso_t* rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_mul_RO_to(darr_t*    lhs, arrsso_t* rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_mul_oO_to(semiotin_t* lhs, arrsso_t* rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_mul_rO_to(coeff_t    lhs, arrsso_t* rhs, arrsso_t* res, dhelpl_t dhl);

// ARR1 * ARR2 + ARR3
void arrsso_gem_OO_to(  arrsso_t* arr1, arrsso_t* arr2, arrsso_t* arr3, arrsso_t* res, dhelpl_t dhl);
void arrsso_gem_oO_to(semiotin_t* arr1, arrsso_t* arr2, arrsso_t* arr3, arrsso_t* res, dhelpl_t dhl);
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
arrsso_t arrsso_div_OO(arrsso_t*   lhs, arrsso_t*   rhs, dhelpl_t dhl);
arrsso_t arrsso_div_OR(arrsso_t*   lhs, darr_t*    rhs, dhelpl_t dhl);
arrsso_t arrsso_div_RO(darr_t*    lhs, arrsso_t*   rhs, dhelpl_t dhl);
arrsso_t arrsso_div_oO(semiotin_t* lhs, arrsso_t*   rhs, dhelpl_t dhl);
arrsso_t arrsso_div_Oo(arrsso_t*   lhs, semiotin_t* rhs, dhelpl_t dhl);
arrsso_t arrsso_div_rO(coeff_t    lhs, arrsso_t*   rhs, dhelpl_t dhl);
arrsso_t arrsso_div_Or(arrsso_t*   lhs, coeff_t    rhs, dhelpl_t dhl);

void arrsso_div_OO_to(arrsso_t*   lhs, arrsso_t*   rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_div_RO_to(darr_t*    lhs, arrsso_t*   rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_div_OR_to(arrsso_t*   lhs, darr_t*    rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_div_oO_to(semiotin_t* lhs, arrsso_t*   rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_div_Oo_to(arrsso_t*   lhs, semiotin_t* rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_div_rO_to(coeff_t    lhs, arrsso_t*   rhs, arrsso_t* res, dhelpl_t dhl);
void arrsso_div_Or_to(arrsso_t*   lhs, coeff_t    rhs, arrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



#endif
