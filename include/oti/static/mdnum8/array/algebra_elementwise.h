#ifndef OTI_MDNUM8_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_MDNUM8_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr8_t mdarr8_neg(mdarr8_t* arr);

void mdarr8_neg_to(mdarr8_t* rhs, mdarr8_t* res);
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
mdarr8_t mdarr8_sum_OO(mdarr8_t*   lhs, mdarr8_t* rhs);
mdarr8_t mdarr8_sum_RO(darr_t*    lhs, mdarr8_t* rhs);
mdarr8_t mdarr8_sum_oO(mdnum8_t* lhs, mdarr8_t* rhs);
mdarr8_t mdarr8_sum_rO(coeff_t    lhs, mdarr8_t* rhs);

void mdarr8_sum_OO_to(mdarr8_t*   lhs, mdarr8_t* rhs, mdarr8_t* res);
void mdarr8_sum_RO_to(darr_t*    lhs, mdarr8_t* rhs, mdarr8_t* res);
void mdarr8_sum_oO_to(mdnum8_t* lhs, mdarr8_t* rhs, mdarr8_t* res);
void mdarr8_sum_rO_to(coeff_t    lhs, mdarr8_t* rhs, mdarr8_t* res);
void mdarr8_trunc_sum_OO_to(ord_t order, mdarr8_t* arr1, mdarr8_t* arr2, mdarr8_t* res);
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
mdarr8_t mdarr8_sub_OO(mdarr8_t*   lhs, mdarr8_t*   rhs);
mdarr8_t mdarr8_sub_RO(darr_t*    lhs, mdarr8_t*   rhs);
mdarr8_t mdarr8_sub_OR(mdarr8_t*   lhs, darr_t*    rhs);
mdarr8_t mdarr8_sub_oO(mdnum8_t* lhs, mdarr8_t*   rhs);
mdarr8_t mdarr8_sub_Oo(mdarr8_t*   lhs, mdnum8_t* rhs);
mdarr8_t mdarr8_sub_rO(coeff_t    lhs, mdarr8_t*   rhs);
mdarr8_t mdarr8_sub_Or(mdarr8_t*   lhs, coeff_t    rhs);

void mdarr8_sub_OO_to( mdarr8_t*   lhs, mdarr8_t*   rhs, mdarr8_t* res);
void mdarr8_sub_RO_to( darr_t*    lhs, mdarr8_t*   rhs, mdarr8_t* res);
void mdarr8_sub_OR_to( mdarr8_t*   lhs, darr_t*    rhs, mdarr8_t* res);
void mdarr8_sub_oO_to( mdnum8_t* lhs, mdarr8_t*   rhs, mdarr8_t* res);
void mdarr8_sub_Oo_to( mdarr8_t*   lhs, mdnum8_t* rhs, mdarr8_t* res);
void mdarr8_sub_rO_to( coeff_t    lhs, mdarr8_t*   rhs, mdarr8_t* res);
void mdarr8_sub_Or_to( mdarr8_t*   lhs, coeff_t    rhs, mdarr8_t* res);
void mdarr8_trunc_sub_OO_to(ord_t order, mdarr8_t* arr1, mdarr8_t* arr2, mdarr8_t* res);
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
mdarr8_t mdarr8_mul_OO(mdarr8_t*   lhs, mdarr8_t* rhs);
mdarr8_t mdarr8_mul_RO(darr_t*    lhs, mdarr8_t* rhs);
mdarr8_t mdarr8_mul_oO(mdnum8_t* lhs, mdarr8_t* rhs);
mdarr8_t mdarr8_mul_rO(coeff_t    lhs, mdarr8_t* rhs);

void mdarr8_mul_OO_to(mdarr8_t*   lhs, mdarr8_t* rhs, mdarr8_t* res);
void mdarr8_mul_RO_to(darr_t*    lhs, mdarr8_t* rhs, mdarr8_t* res);
void mdarr8_mul_oO_to(mdnum8_t* lhs, mdarr8_t* rhs, mdarr8_t* res);
void mdarr8_mul_rO_to(coeff_t    lhs, mdarr8_t* rhs, mdarr8_t* res);

// ARR1 * ARR2 + ARR3
void mdarr8_gem_OO_to(  mdarr8_t* arr1, mdarr8_t* arr2, mdarr8_t* arr3, mdarr8_t* res);
void mdarr8_gem_oO_to(mdnum8_t* arr1, mdarr8_t* arr2, mdarr8_t* arr3, mdarr8_t* res);
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
mdarr8_t mdarr8_div_OO(mdarr8_t*   lhs, mdarr8_t*   rhs);
mdarr8_t mdarr8_div_OR(mdarr8_t*   lhs, darr_t*    rhs);
mdarr8_t mdarr8_div_RO(darr_t*    lhs, mdarr8_t*   rhs);
mdarr8_t mdarr8_div_oO(mdnum8_t* lhs, mdarr8_t*   rhs);
mdarr8_t mdarr8_div_Oo(mdarr8_t*   lhs, mdnum8_t* rhs);
mdarr8_t mdarr8_div_rO(coeff_t    lhs, mdarr8_t*   rhs);
mdarr8_t mdarr8_div_Or(mdarr8_t*   lhs, coeff_t    rhs);

void mdarr8_div_OO_to(mdarr8_t*   lhs, mdarr8_t*   rhs, mdarr8_t* res);
void mdarr8_div_RO_to(darr_t*    lhs, mdarr8_t*   rhs, mdarr8_t* res);
void mdarr8_div_OR_to(mdarr8_t*   lhs, darr_t*    rhs, mdarr8_t* res);
void mdarr8_div_oO_to(mdnum8_t* lhs, mdarr8_t*   rhs, mdarr8_t* res);
void mdarr8_div_Oo_to(mdarr8_t*   lhs, mdnum8_t* rhs, mdarr8_t* res);
void mdarr8_div_rO_to(coeff_t    lhs, mdarr8_t*   rhs, mdarr8_t* res);
void mdarr8_div_Or_to(mdarr8_t*   lhs, coeff_t    rhs, mdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
