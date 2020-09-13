#ifndef OTI_MDNUM10_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_MDNUM10_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr10_t mdarr10_neg(mdarr10_t* arr);

void mdarr10_neg_to(mdarr10_t* rhs, mdarr10_t* res);
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
mdarr10_t mdarr10_sum_OO(mdarr10_t*   lhs, mdarr10_t* rhs);
mdarr10_t mdarr10_sum_RO(darr_t*    lhs, mdarr10_t* rhs);
mdarr10_t mdarr10_sum_oO(mdnum10_t* lhs, mdarr10_t* rhs);
mdarr10_t mdarr10_sum_rO(coeff_t    lhs, mdarr10_t* rhs);

void mdarr10_sum_OO_to(mdarr10_t*   lhs, mdarr10_t* rhs, mdarr10_t* res);
void mdarr10_sum_RO_to(darr_t*    lhs, mdarr10_t* rhs, mdarr10_t* res);
void mdarr10_sum_oO_to(mdnum10_t* lhs, mdarr10_t* rhs, mdarr10_t* res);
void mdarr10_sum_rO_to(coeff_t    lhs, mdarr10_t* rhs, mdarr10_t* res);
void mdarr10_trunc_sum_OO_to(ord_t order, mdarr10_t* arr1, mdarr10_t* arr2, mdarr10_t* res);
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
mdarr10_t mdarr10_sub_OO(mdarr10_t*   lhs, mdarr10_t*   rhs);
mdarr10_t mdarr10_sub_RO(darr_t*    lhs, mdarr10_t*   rhs);
mdarr10_t mdarr10_sub_OR(mdarr10_t*   lhs, darr_t*    rhs);
mdarr10_t mdarr10_sub_oO(mdnum10_t* lhs, mdarr10_t*   rhs);
mdarr10_t mdarr10_sub_Oo(mdarr10_t*   lhs, mdnum10_t* rhs);
mdarr10_t mdarr10_sub_rO(coeff_t    lhs, mdarr10_t*   rhs);
mdarr10_t mdarr10_sub_Or(mdarr10_t*   lhs, coeff_t    rhs);

void mdarr10_sub_OO_to( mdarr10_t*   lhs, mdarr10_t*   rhs, mdarr10_t* res);
void mdarr10_sub_RO_to( darr_t*    lhs, mdarr10_t*   rhs, mdarr10_t* res);
void mdarr10_sub_OR_to( mdarr10_t*   lhs, darr_t*    rhs, mdarr10_t* res);
void mdarr10_sub_oO_to( mdnum10_t* lhs, mdarr10_t*   rhs, mdarr10_t* res);
void mdarr10_sub_Oo_to( mdarr10_t*   lhs, mdnum10_t* rhs, mdarr10_t* res);
void mdarr10_sub_rO_to( coeff_t    lhs, mdarr10_t*   rhs, mdarr10_t* res);
void mdarr10_sub_Or_to( mdarr10_t*   lhs, coeff_t    rhs, mdarr10_t* res);
void mdarr10_trunc_sub_OO_to(ord_t order, mdarr10_t* arr1, mdarr10_t* arr2, mdarr10_t* res);
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
mdarr10_t mdarr10_mul_OO(mdarr10_t*   lhs, mdarr10_t* rhs);
mdarr10_t mdarr10_mul_RO(darr_t*    lhs, mdarr10_t* rhs);
mdarr10_t mdarr10_mul_oO(mdnum10_t* lhs, mdarr10_t* rhs);
mdarr10_t mdarr10_mul_rO(coeff_t    lhs, mdarr10_t* rhs);

void mdarr10_mul_OO_to(mdarr10_t*   lhs, mdarr10_t* rhs, mdarr10_t* res);
void mdarr10_mul_RO_to(darr_t*    lhs, mdarr10_t* rhs, mdarr10_t* res);
void mdarr10_mul_oO_to(mdnum10_t* lhs, mdarr10_t* rhs, mdarr10_t* res);
void mdarr10_mul_rO_to(coeff_t    lhs, mdarr10_t* rhs, mdarr10_t* res);

// ARR1 * ARR2 + ARR3
void mdarr10_gem_OO_to(  mdarr10_t* arr1, mdarr10_t* arr2, mdarr10_t* arr3, mdarr10_t* res);
void mdarr10_gem_oO_to(mdnum10_t* arr1, mdarr10_t* arr2, mdarr10_t* arr3, mdarr10_t* res);
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
mdarr10_t mdarr10_div_OO(mdarr10_t*   lhs, mdarr10_t*   rhs);
mdarr10_t mdarr10_div_OR(mdarr10_t*   lhs, darr_t*    rhs);
mdarr10_t mdarr10_div_RO(darr_t*    lhs, mdarr10_t*   rhs);
mdarr10_t mdarr10_div_oO(mdnum10_t* lhs, mdarr10_t*   rhs);
mdarr10_t mdarr10_div_Oo(mdarr10_t*   lhs, mdnum10_t* rhs);
mdarr10_t mdarr10_div_rO(coeff_t    lhs, mdarr10_t*   rhs);
mdarr10_t mdarr10_div_Or(mdarr10_t*   lhs, coeff_t    rhs);

void mdarr10_div_OO_to(mdarr10_t*   lhs, mdarr10_t*   rhs, mdarr10_t* res);
void mdarr10_div_RO_to(darr_t*    lhs, mdarr10_t*   rhs, mdarr10_t* res);
void mdarr10_div_OR_to(mdarr10_t*   lhs, darr_t*    rhs, mdarr10_t* res);
void mdarr10_div_oO_to(mdnum10_t* lhs, mdarr10_t*   rhs, mdarr10_t* res);
void mdarr10_div_Oo_to(mdarr10_t*   lhs, mdnum10_t* rhs, mdarr10_t* res);
void mdarr10_div_rO_to(coeff_t    lhs, mdarr10_t*   rhs, mdarr10_t* res);
void mdarr10_div_Or_to(mdarr10_t*   lhs, coeff_t    rhs, mdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
