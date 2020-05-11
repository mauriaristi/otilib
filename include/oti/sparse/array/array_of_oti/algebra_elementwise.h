#ifndef OTI_SPARSE_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_SPARSE_ARRAY_ALGEBRA_ELEMENTWISE_H


/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
arrso_t arrso_neg(arrso_t* arr, dhelpl_t dhl);

void arrso_neg_to(arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
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
arrso_t arrso_sum_OO(arrso_t*   lhs, arrso_t* rhs, dhelpl_t dhl);
arrso_t arrso_sum_RO(darr_t*    lhs, arrso_t* rhs, dhelpl_t dhl);
arrso_t arrso_sum_oO(sotinum_t* lhs, arrso_t* rhs, dhelpl_t dhl);
arrso_t arrso_sum_rO(coeff_t    lhs, arrso_t* rhs, dhelpl_t dhl);

void arrso_sum_OO_to(arrso_t*   lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
void arrso_sum_RO_to(darr_t*    lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
void arrso_sum_oO_to(sotinum_t* lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
void arrso_sum_rO_to(coeff_t    lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
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
arrso_t arrso_sub_OO(arrso_t*   lhs, arrso_t*   rhs, dhelpl_t dhl);
arrso_t arrso_sub_RO(darr_t*    lhs, arrso_t*   rhs, dhelpl_t dhl);
arrso_t arrso_sub_OR(arrso_t*   lhs, darr_t*    rhs, dhelpl_t dhl);
arrso_t arrso_sub_oO(sotinum_t* lhs, arrso_t*   rhs, dhelpl_t dhl);
arrso_t arrso_sub_Oo(arrso_t*   lhs, sotinum_t* rhs, dhelpl_t dhl);
arrso_t arrso_sub_rO(coeff_t    lhs, arrso_t*   rhs, dhelpl_t dhl);
arrso_t arrso_sub_Or(arrso_t*   lhs, coeff_t    rhs, dhelpl_t dhl);

void arrso_sub_OO_to( arrso_t*   lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
void arrso_sub_RO_to( darr_t*    lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
void arrso_sub_OR_to( arrso_t*   lhs, darr_t*    rhs, arrso_t* res, dhelpl_t dhl);
void arrso_sub_oO_to( sotinum_t* lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
void arrso_sub_Oo_to( arrso_t*   lhs, sotinum_t* rhs, arrso_t* res, dhelpl_t dhl);
void arrso_sub_rO_to( coeff_t    lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
void arrso_sub_Or_to( arrso_t*   lhs, coeff_t    rhs, arrso_t* res, dhelpl_t dhl);
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
arrso_t arrso_mul_OO(arrso_t*   lhs, arrso_t* rhs, dhelpl_t dhl);
arrso_t arrso_mul_RO(darr_t*    lhs, arrso_t* rhs, dhelpl_t dhl);
arrso_t arrso_mul_oO(sotinum_t* lhs, arrso_t* rhs, dhelpl_t dhl);
arrso_t arrso_mul_rO(coeff_t    lhs, arrso_t* rhs, dhelpl_t dhl);

void arrso_mul_OO_to(arrso_t*   lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
void arrso_mul_RO_to(darr_t*    lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
void arrso_mul_oO_to(sotinum_t* lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
void arrso_mul_rO_to(coeff_t    lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
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
arrso_t arrso_div_OO(arrso_t*   lhs, arrso_t*   rhs, dhelpl_t dhl);
arrso_t arrso_div_OR(arrso_t*   lhs, darr_t*    rhs, dhelpl_t dhl);
arrso_t arrso_div_RO(darr_t*    lhs, arrso_t*   rhs, dhelpl_t dhl);
arrso_t arrso_div_oO(sotinum_t* lhs, arrso_t*   rhs, dhelpl_t dhl);
arrso_t arrso_div_Oo(arrso_t*   lhs, sotinum_t* rhs, dhelpl_t dhl);
arrso_t arrso_div_rO(coeff_t    lhs, arrso_t*   rhs, dhelpl_t dhl);
arrso_t arrso_div_Or(arrso_t*   lhs, coeff_t    rhs, dhelpl_t dhl);

void arrso_div_OO_to(arrso_t*   lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
void arrso_div_RO_to(darr_t*    lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
void arrso_div_OR_to(arrso_t*   lhs, darr_t*    rhs, arrso_t* res, dhelpl_t dhl);
void arrso_div_oO_to(sotinum_t* lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
void arrso_div_Oo_to(arrso_t*   lhs, sotinum_t* rhs, arrso_t* res, dhelpl_t dhl);
void arrso_div_rO_to(coeff_t    lhs, arrso_t*   rhs, arrso_t* res, dhelpl_t dhl);
void arrso_div_Or_to(arrso_t*   lhs, coeff_t    rhs, arrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------










#endif
