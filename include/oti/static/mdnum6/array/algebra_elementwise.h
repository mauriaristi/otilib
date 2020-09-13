#ifndef OTI_MDNUM6_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_MDNUM6_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr6_t mdarr6_neg(mdarr6_t* arr);

void mdarr6_neg_to(mdarr6_t* rhs, mdarr6_t* res);
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
mdarr6_t mdarr6_sum_OO(mdarr6_t*   lhs, mdarr6_t* rhs);
mdarr6_t mdarr6_sum_RO(darr_t*    lhs, mdarr6_t* rhs);
mdarr6_t mdarr6_sum_oO(mdnum6_t* lhs, mdarr6_t* rhs);
mdarr6_t mdarr6_sum_rO(coeff_t    lhs, mdarr6_t* rhs);

void mdarr6_sum_OO_to(mdarr6_t*   lhs, mdarr6_t* rhs, mdarr6_t* res);
void mdarr6_sum_RO_to(darr_t*    lhs, mdarr6_t* rhs, mdarr6_t* res);
void mdarr6_sum_oO_to(mdnum6_t* lhs, mdarr6_t* rhs, mdarr6_t* res);
void mdarr6_sum_rO_to(coeff_t    lhs, mdarr6_t* rhs, mdarr6_t* res);
void mdarr6_trunc_sum_OO_to(ord_t order, mdarr6_t* arr1, mdarr6_t* arr2, mdarr6_t* res);
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
mdarr6_t mdarr6_sub_OO(mdarr6_t*   lhs, mdarr6_t*   rhs);
mdarr6_t mdarr6_sub_RO(darr_t*    lhs, mdarr6_t*   rhs);
mdarr6_t mdarr6_sub_OR(mdarr6_t*   lhs, darr_t*    rhs);
mdarr6_t mdarr6_sub_oO(mdnum6_t* lhs, mdarr6_t*   rhs);
mdarr6_t mdarr6_sub_Oo(mdarr6_t*   lhs, mdnum6_t* rhs);
mdarr6_t mdarr6_sub_rO(coeff_t    lhs, mdarr6_t*   rhs);
mdarr6_t mdarr6_sub_Or(mdarr6_t*   lhs, coeff_t    rhs);

void mdarr6_sub_OO_to( mdarr6_t*   lhs, mdarr6_t*   rhs, mdarr6_t* res);
void mdarr6_sub_RO_to( darr_t*    lhs, mdarr6_t*   rhs, mdarr6_t* res);
void mdarr6_sub_OR_to( mdarr6_t*   lhs, darr_t*    rhs, mdarr6_t* res);
void mdarr6_sub_oO_to( mdnum6_t* lhs, mdarr6_t*   rhs, mdarr6_t* res);
void mdarr6_sub_Oo_to( mdarr6_t*   lhs, mdnum6_t* rhs, mdarr6_t* res);
void mdarr6_sub_rO_to( coeff_t    lhs, mdarr6_t*   rhs, mdarr6_t* res);
void mdarr6_sub_Or_to( mdarr6_t*   lhs, coeff_t    rhs, mdarr6_t* res);
void mdarr6_trunc_sub_OO_to(ord_t order, mdarr6_t* arr1, mdarr6_t* arr2, mdarr6_t* res);
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
mdarr6_t mdarr6_mul_OO(mdarr6_t*   lhs, mdarr6_t* rhs);
mdarr6_t mdarr6_mul_RO(darr_t*    lhs, mdarr6_t* rhs);
mdarr6_t mdarr6_mul_oO(mdnum6_t* lhs, mdarr6_t* rhs);
mdarr6_t mdarr6_mul_rO(coeff_t    lhs, mdarr6_t* rhs);

void mdarr6_mul_OO_to(mdarr6_t*   lhs, mdarr6_t* rhs, mdarr6_t* res);
void mdarr6_mul_RO_to(darr_t*    lhs, mdarr6_t* rhs, mdarr6_t* res);
void mdarr6_mul_oO_to(mdnum6_t* lhs, mdarr6_t* rhs, mdarr6_t* res);
void mdarr6_mul_rO_to(coeff_t    lhs, mdarr6_t* rhs, mdarr6_t* res);

// ARR1 * ARR2 + ARR3
void mdarr6_gem_OO_to(  mdarr6_t* arr1, mdarr6_t* arr2, mdarr6_t* arr3, mdarr6_t* res);
void mdarr6_gem_oO_to(mdnum6_t* arr1, mdarr6_t* arr2, mdarr6_t* arr3, mdarr6_t* res);
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
mdarr6_t mdarr6_div_OO(mdarr6_t*   lhs, mdarr6_t*   rhs);
mdarr6_t mdarr6_div_OR(mdarr6_t*   lhs, darr_t*    rhs);
mdarr6_t mdarr6_div_RO(darr_t*    lhs, mdarr6_t*   rhs);
mdarr6_t mdarr6_div_oO(mdnum6_t* lhs, mdarr6_t*   rhs);
mdarr6_t mdarr6_div_Oo(mdarr6_t*   lhs, mdnum6_t* rhs);
mdarr6_t mdarr6_div_rO(coeff_t    lhs, mdarr6_t*   rhs);
mdarr6_t mdarr6_div_Or(mdarr6_t*   lhs, coeff_t    rhs);

void mdarr6_div_OO_to(mdarr6_t*   lhs, mdarr6_t*   rhs, mdarr6_t* res);
void mdarr6_div_RO_to(darr_t*    lhs, mdarr6_t*   rhs, mdarr6_t* res);
void mdarr6_div_OR_to(mdarr6_t*   lhs, darr_t*    rhs, mdarr6_t* res);
void mdarr6_div_oO_to(mdnum6_t* lhs, mdarr6_t*   rhs, mdarr6_t* res);
void mdarr6_div_Oo_to(mdarr6_t*   lhs, mdnum6_t* rhs, mdarr6_t* res);
void mdarr6_div_rO_to(coeff_t    lhs, mdarr6_t*   rhs, mdarr6_t* res);
void mdarr6_div_Or_to(mdarr6_t*   lhs, coeff_t    rhs, mdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
