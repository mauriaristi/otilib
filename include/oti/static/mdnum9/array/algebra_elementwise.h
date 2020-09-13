#ifndef OTI_MDNUM9_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_MDNUM9_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr9_t mdarr9_neg(mdarr9_t* arr);

void mdarr9_neg_to(mdarr9_t* rhs, mdarr9_t* res);
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
mdarr9_t mdarr9_sum_OO(mdarr9_t*   lhs, mdarr9_t* rhs);
mdarr9_t mdarr9_sum_RO(darr_t*    lhs, mdarr9_t* rhs);
mdarr9_t mdarr9_sum_oO(mdnum9_t* lhs, mdarr9_t* rhs);
mdarr9_t mdarr9_sum_rO(coeff_t    lhs, mdarr9_t* rhs);

void mdarr9_sum_OO_to(mdarr9_t*   lhs, mdarr9_t* rhs, mdarr9_t* res);
void mdarr9_sum_RO_to(darr_t*    lhs, mdarr9_t* rhs, mdarr9_t* res);
void mdarr9_sum_oO_to(mdnum9_t* lhs, mdarr9_t* rhs, mdarr9_t* res);
void mdarr9_sum_rO_to(coeff_t    lhs, mdarr9_t* rhs, mdarr9_t* res);
void mdarr9_trunc_sum_OO_to(ord_t order, mdarr9_t* arr1, mdarr9_t* arr2, mdarr9_t* res);
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
mdarr9_t mdarr9_sub_OO(mdarr9_t*   lhs, mdarr9_t*   rhs);
mdarr9_t mdarr9_sub_RO(darr_t*    lhs, mdarr9_t*   rhs);
mdarr9_t mdarr9_sub_OR(mdarr9_t*   lhs, darr_t*    rhs);
mdarr9_t mdarr9_sub_oO(mdnum9_t* lhs, mdarr9_t*   rhs);
mdarr9_t mdarr9_sub_Oo(mdarr9_t*   lhs, mdnum9_t* rhs);
mdarr9_t mdarr9_sub_rO(coeff_t    lhs, mdarr9_t*   rhs);
mdarr9_t mdarr9_sub_Or(mdarr9_t*   lhs, coeff_t    rhs);

void mdarr9_sub_OO_to( mdarr9_t*   lhs, mdarr9_t*   rhs, mdarr9_t* res);
void mdarr9_sub_RO_to( darr_t*    lhs, mdarr9_t*   rhs, mdarr9_t* res);
void mdarr9_sub_OR_to( mdarr9_t*   lhs, darr_t*    rhs, mdarr9_t* res);
void mdarr9_sub_oO_to( mdnum9_t* lhs, mdarr9_t*   rhs, mdarr9_t* res);
void mdarr9_sub_Oo_to( mdarr9_t*   lhs, mdnum9_t* rhs, mdarr9_t* res);
void mdarr9_sub_rO_to( coeff_t    lhs, mdarr9_t*   rhs, mdarr9_t* res);
void mdarr9_sub_Or_to( mdarr9_t*   lhs, coeff_t    rhs, mdarr9_t* res);
void mdarr9_trunc_sub_OO_to(ord_t order, mdarr9_t* arr1, mdarr9_t* arr2, mdarr9_t* res);
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
mdarr9_t mdarr9_mul_OO(mdarr9_t*   lhs, mdarr9_t* rhs);
mdarr9_t mdarr9_mul_RO(darr_t*    lhs, mdarr9_t* rhs);
mdarr9_t mdarr9_mul_oO(mdnum9_t* lhs, mdarr9_t* rhs);
mdarr9_t mdarr9_mul_rO(coeff_t    lhs, mdarr9_t* rhs);

void mdarr9_mul_OO_to(mdarr9_t*   lhs, mdarr9_t* rhs, mdarr9_t* res);
void mdarr9_mul_RO_to(darr_t*    lhs, mdarr9_t* rhs, mdarr9_t* res);
void mdarr9_mul_oO_to(mdnum9_t* lhs, mdarr9_t* rhs, mdarr9_t* res);
void mdarr9_mul_rO_to(coeff_t    lhs, mdarr9_t* rhs, mdarr9_t* res);

// ARR1 * ARR2 + ARR3
void mdarr9_gem_OO_to(  mdarr9_t* arr1, mdarr9_t* arr2, mdarr9_t* arr3, mdarr9_t* res);
void mdarr9_gem_oO_to(mdnum9_t* arr1, mdarr9_t* arr2, mdarr9_t* arr3, mdarr9_t* res);
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
mdarr9_t mdarr9_div_OO(mdarr9_t*   lhs, mdarr9_t*   rhs);
mdarr9_t mdarr9_div_OR(mdarr9_t*   lhs, darr_t*    rhs);
mdarr9_t mdarr9_div_RO(darr_t*    lhs, mdarr9_t*   rhs);
mdarr9_t mdarr9_div_oO(mdnum9_t* lhs, mdarr9_t*   rhs);
mdarr9_t mdarr9_div_Oo(mdarr9_t*   lhs, mdnum9_t* rhs);
mdarr9_t mdarr9_div_rO(coeff_t    lhs, mdarr9_t*   rhs);
mdarr9_t mdarr9_div_Or(mdarr9_t*   lhs, coeff_t    rhs);

void mdarr9_div_OO_to(mdarr9_t*   lhs, mdarr9_t*   rhs, mdarr9_t* res);
void mdarr9_div_RO_to(darr_t*    lhs, mdarr9_t*   rhs, mdarr9_t* res);
void mdarr9_div_OR_to(mdarr9_t*   lhs, darr_t*    rhs, mdarr9_t* res);
void mdarr9_div_oO_to(mdnum9_t* lhs, mdarr9_t*   rhs, mdarr9_t* res);
void mdarr9_div_Oo_to(mdarr9_t*   lhs, mdnum9_t* rhs, mdarr9_t* res);
void mdarr9_div_rO_to(coeff_t    lhs, mdarr9_t*   rhs, mdarr9_t* res);
void mdarr9_div_Or_to(mdarr9_t*   lhs, coeff_t    rhs, mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
