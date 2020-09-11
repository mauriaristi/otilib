#ifndef OTI_MDNUM5_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_MDNUM5_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr5_t mdarr5_neg(mdarr5_t* arr);

void mdarr5_neg_to(mdarr5_t* rhs, mdarr5_t* res);
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
mdarr5_t mdarr5_sum_OO(mdarr5_t*   lhs, mdarr5_t* rhs);
mdarr5_t mdarr5_sum_RO(darr_t*    lhs, mdarr5_t* rhs);
mdarr5_t mdarr5_sum_oO(mdnum5_t* lhs, mdarr5_t* rhs);
mdarr5_t mdarr5_sum_rO(coeff_t    lhs, mdarr5_t* rhs);

void mdarr5_sum_OO_to(mdarr5_t*   lhs, mdarr5_t* rhs, mdarr5_t* res);
void mdarr5_sum_RO_to(darr_t*    lhs, mdarr5_t* rhs, mdarr5_t* res);
void mdarr5_sum_oO_to(mdnum5_t* lhs, mdarr5_t* rhs, mdarr5_t* res);
void mdarr5_sum_rO_to(coeff_t    lhs, mdarr5_t* rhs, mdarr5_t* res);
void mdarr5_trunc_sum_OO_to(ord_t order, mdarr5_t* arr1, mdarr5_t* arr2, mdarr5_t* res);
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
mdarr5_t mdarr5_sub_OO(mdarr5_t*   lhs, mdarr5_t*   rhs);
mdarr5_t mdarr5_sub_RO(darr_t*    lhs, mdarr5_t*   rhs);
mdarr5_t mdarr5_sub_OR(mdarr5_t*   lhs, darr_t*    rhs);
mdarr5_t mdarr5_sub_oO(mdnum5_t* lhs, mdarr5_t*   rhs);
mdarr5_t mdarr5_sub_Oo(mdarr5_t*   lhs, mdnum5_t* rhs);
mdarr5_t mdarr5_sub_rO(coeff_t    lhs, mdarr5_t*   rhs);
mdarr5_t mdarr5_sub_Or(mdarr5_t*   lhs, coeff_t    rhs);

void mdarr5_sub_OO_to( mdarr5_t*   lhs, mdarr5_t*   rhs, mdarr5_t* res);
void mdarr5_sub_RO_to( darr_t*    lhs, mdarr5_t*   rhs, mdarr5_t* res);
void mdarr5_sub_OR_to( mdarr5_t*   lhs, darr_t*    rhs, mdarr5_t* res);
void mdarr5_sub_oO_to( mdnum5_t* lhs, mdarr5_t*   rhs, mdarr5_t* res);
void mdarr5_sub_Oo_to( mdarr5_t*   lhs, mdnum5_t* rhs, mdarr5_t* res);
void mdarr5_sub_rO_to( coeff_t    lhs, mdarr5_t*   rhs, mdarr5_t* res);
void mdarr5_sub_Or_to( mdarr5_t*   lhs, coeff_t    rhs, mdarr5_t* res);
void mdarr5_trunc_sub_OO_to(ord_t order, mdarr5_t* arr1, mdarr5_t* arr2, mdarr5_t* res);
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
mdarr5_t mdarr5_mul_OO(mdarr5_t*   lhs, mdarr5_t* rhs);
mdarr5_t mdarr5_mul_RO(darr_t*    lhs, mdarr5_t* rhs);
mdarr5_t mdarr5_mul_oO(mdnum5_t* lhs, mdarr5_t* rhs);
mdarr5_t mdarr5_mul_rO(coeff_t    lhs, mdarr5_t* rhs);

void mdarr5_mul_OO_to(mdarr5_t*   lhs, mdarr5_t* rhs, mdarr5_t* res);
void mdarr5_mul_RO_to(darr_t*    lhs, mdarr5_t* rhs, mdarr5_t* res);
void mdarr5_mul_oO_to(mdnum5_t* lhs, mdarr5_t* rhs, mdarr5_t* res);
void mdarr5_mul_rO_to(coeff_t    lhs, mdarr5_t* rhs, mdarr5_t* res);

// ARR1 * ARR2 + ARR3
void mdarr5_gem_OO_to(  mdarr5_t* arr1, mdarr5_t* arr2, mdarr5_t* arr3, mdarr5_t* res);
void mdarr5_gem_oO_to(mdnum5_t* arr1, mdarr5_t* arr2, mdarr5_t* arr3, mdarr5_t* res);
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
mdarr5_t mdarr5_div_OO(mdarr5_t*   lhs, mdarr5_t*   rhs);
mdarr5_t mdarr5_div_OR(mdarr5_t*   lhs, darr_t*    rhs);
mdarr5_t mdarr5_div_RO(darr_t*    lhs, mdarr5_t*   rhs);
mdarr5_t mdarr5_div_oO(mdnum5_t* lhs, mdarr5_t*   rhs);
mdarr5_t mdarr5_div_Oo(mdarr5_t*   lhs, mdnum5_t* rhs);
mdarr5_t mdarr5_div_rO(coeff_t    lhs, mdarr5_t*   rhs);
mdarr5_t mdarr5_div_Or(mdarr5_t*   lhs, coeff_t    rhs);

void mdarr5_div_OO_to(mdarr5_t*   lhs, mdarr5_t*   rhs, mdarr5_t* res);
void mdarr5_div_RO_to(darr_t*    lhs, mdarr5_t*   rhs, mdarr5_t* res);
void mdarr5_div_OR_to(mdarr5_t*   lhs, darr_t*    rhs, mdarr5_t* res);
void mdarr5_div_oO_to(mdnum5_t* lhs, mdarr5_t*   rhs, mdarr5_t* res);
void mdarr5_div_Oo_to(mdarr5_t*   lhs, mdnum5_t* rhs, mdarr5_t* res);
void mdarr5_div_rO_to(coeff_t    lhs, mdarr5_t*   rhs, mdarr5_t* res);
void mdarr5_div_Or_to(mdarr5_t*   lhs, coeff_t    rhs, mdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
