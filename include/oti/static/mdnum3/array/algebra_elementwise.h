#ifndef OTI_MDNUM3_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_MDNUM3_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr3_t mdarr3_neg(mdarr3_t* arr);

void mdarr3_neg_to(mdarr3_t* rhs, mdarr3_t* res);
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
mdarr3_t mdarr3_sum_OO(mdarr3_t*   lhs, mdarr3_t* rhs);
mdarr3_t mdarr3_sum_RO(darr_t*    lhs, mdarr3_t* rhs);
mdarr3_t mdarr3_sum_oO(mdnum3_t* lhs, mdarr3_t* rhs);
mdarr3_t mdarr3_sum_rO(coeff_t    lhs, mdarr3_t* rhs);

void mdarr3_sum_OO_to(mdarr3_t*   lhs, mdarr3_t* rhs, mdarr3_t* res);
void mdarr3_sum_RO_to(darr_t*    lhs, mdarr3_t* rhs, mdarr3_t* res);
void mdarr3_sum_oO_to(mdnum3_t* lhs, mdarr3_t* rhs, mdarr3_t* res);
void mdarr3_sum_rO_to(coeff_t    lhs, mdarr3_t* rhs, mdarr3_t* res);
void mdarr3_trunc_sum_OO_to(ord_t order, mdarr3_t* arr1, mdarr3_t* arr2, mdarr3_t* res);
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
mdarr3_t mdarr3_sub_OO(mdarr3_t*   lhs, mdarr3_t*   rhs);
mdarr3_t mdarr3_sub_RO(darr_t*    lhs, mdarr3_t*   rhs);
mdarr3_t mdarr3_sub_OR(mdarr3_t*   lhs, darr_t*    rhs);
mdarr3_t mdarr3_sub_oO(mdnum3_t* lhs, mdarr3_t*   rhs);
mdarr3_t mdarr3_sub_Oo(mdarr3_t*   lhs, mdnum3_t* rhs);
mdarr3_t mdarr3_sub_rO(coeff_t    lhs, mdarr3_t*   rhs);
mdarr3_t mdarr3_sub_Or(mdarr3_t*   lhs, coeff_t    rhs);

void mdarr3_sub_OO_to( mdarr3_t*   lhs, mdarr3_t*   rhs, mdarr3_t* res);
void mdarr3_sub_RO_to( darr_t*    lhs, mdarr3_t*   rhs, mdarr3_t* res);
void mdarr3_sub_OR_to( mdarr3_t*   lhs, darr_t*    rhs, mdarr3_t* res);
void mdarr3_sub_oO_to( mdnum3_t* lhs, mdarr3_t*   rhs, mdarr3_t* res);
void mdarr3_sub_Oo_to( mdarr3_t*   lhs, mdnum3_t* rhs, mdarr3_t* res);
void mdarr3_sub_rO_to( coeff_t    lhs, mdarr3_t*   rhs, mdarr3_t* res);
void mdarr3_sub_Or_to( mdarr3_t*   lhs, coeff_t    rhs, mdarr3_t* res);
void mdarr3_trunc_sub_OO_to(ord_t order, mdarr3_t* arr1, mdarr3_t* arr2, mdarr3_t* res);
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
mdarr3_t mdarr3_mul_OO(mdarr3_t*   lhs, mdarr3_t* rhs);
mdarr3_t mdarr3_mul_RO(darr_t*    lhs, mdarr3_t* rhs);
mdarr3_t mdarr3_mul_oO(mdnum3_t* lhs, mdarr3_t* rhs);
mdarr3_t mdarr3_mul_rO(coeff_t    lhs, mdarr3_t* rhs);

void mdarr3_mul_OO_to(mdarr3_t*   lhs, mdarr3_t* rhs, mdarr3_t* res);
void mdarr3_mul_RO_to(darr_t*    lhs, mdarr3_t* rhs, mdarr3_t* res);
void mdarr3_mul_oO_to(mdnum3_t* lhs, mdarr3_t* rhs, mdarr3_t* res);
void mdarr3_mul_rO_to(coeff_t    lhs, mdarr3_t* rhs, mdarr3_t* res);

// ARR1 * ARR2 + ARR3
void mdarr3_gem_OO_to(  mdarr3_t* arr1, mdarr3_t* arr2, mdarr3_t* arr3, mdarr3_t* res);
void mdarr3_gem_oO_to(mdnum3_t* arr1, mdarr3_t* arr2, mdarr3_t* arr3, mdarr3_t* res);
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
mdarr3_t mdarr3_div_OO(mdarr3_t*   lhs, mdarr3_t*   rhs);
mdarr3_t mdarr3_div_OR(mdarr3_t*   lhs, darr_t*    rhs);
mdarr3_t mdarr3_div_RO(darr_t*    lhs, mdarr3_t*   rhs);
mdarr3_t mdarr3_div_oO(mdnum3_t* lhs, mdarr3_t*   rhs);
mdarr3_t mdarr3_div_Oo(mdarr3_t*   lhs, mdnum3_t* rhs);
mdarr3_t mdarr3_div_rO(coeff_t    lhs, mdarr3_t*   rhs);
mdarr3_t mdarr3_div_Or(mdarr3_t*   lhs, coeff_t    rhs);

void mdarr3_div_OO_to(mdarr3_t*   lhs, mdarr3_t*   rhs, mdarr3_t* res);
void mdarr3_div_RO_to(darr_t*    lhs, mdarr3_t*   rhs, mdarr3_t* res);
void mdarr3_div_OR_to(mdarr3_t*   lhs, darr_t*    rhs, mdarr3_t* res);
void mdarr3_div_oO_to(mdnum3_t* lhs, mdarr3_t*   rhs, mdarr3_t* res);
void mdarr3_div_Oo_to(mdarr3_t*   lhs, mdnum3_t* rhs, mdarr3_t* res);
void mdarr3_div_rO_to(coeff_t    lhs, mdarr3_t*   rhs, mdarr3_t* res);
void mdarr3_div_Or_to(mdarr3_t*   lhs, coeff_t    rhs, mdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
