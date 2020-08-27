#ifndef OTI_MDNUM2_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_MDNUM2_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr2_t mdarr2_neg(mdarr2_t* arr);

void mdarr2_neg_to(mdarr2_t* rhs, mdarr2_t* res);
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
mdarr2_t mdarr2_sum_OO(mdarr2_t*   lhs, mdarr2_t* rhs);
mdarr2_t mdarr2_sum_RO(darr_t*    lhs, mdarr2_t* rhs);
mdarr2_t mdarr2_sum_oO(mdnum2_t* lhs, mdarr2_t* rhs);
mdarr2_t mdarr2_sum_rO(coeff_t    lhs, mdarr2_t* rhs);

void mdarr2_sum_OO_to(mdarr2_t*   lhs, mdarr2_t* rhs, mdarr2_t* res);
void mdarr2_sum_RO_to(darr_t*    lhs, mdarr2_t* rhs, mdarr2_t* res);
void mdarr2_sum_oO_to(mdnum2_t* lhs, mdarr2_t* rhs, mdarr2_t* res);
void mdarr2_sum_rO_to(coeff_t    lhs, mdarr2_t* rhs, mdarr2_t* res);
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
mdarr2_t mdarr2_sub_OO(mdarr2_t*   lhs, mdarr2_t*   rhs);
mdarr2_t mdarr2_sub_RO(darr_t*    lhs, mdarr2_t*   rhs);
mdarr2_t mdarr2_sub_OR(mdarr2_t*   lhs, darr_t*    rhs);
mdarr2_t mdarr2_sub_oO(mdnum2_t* lhs, mdarr2_t*   rhs);
mdarr2_t mdarr2_sub_Oo(mdarr2_t*   lhs, mdnum2_t* rhs);
mdarr2_t mdarr2_sub_rO(coeff_t    lhs, mdarr2_t*   rhs);
mdarr2_t mdarr2_sub_Or(mdarr2_t*   lhs, coeff_t    rhs);

void mdarr2_sub_OO_to( mdarr2_t*   lhs, mdarr2_t*   rhs, mdarr2_t* res);
void mdarr2_sub_RO_to( darr_t*    lhs, mdarr2_t*   rhs, mdarr2_t* res);
void mdarr2_sub_OR_to( mdarr2_t*   lhs, darr_t*    rhs, mdarr2_t* res);
void mdarr2_sub_oO_to( mdnum2_t* lhs, mdarr2_t*   rhs, mdarr2_t* res);
void mdarr2_sub_Oo_to( mdarr2_t*   lhs, mdnum2_t* rhs, mdarr2_t* res);
void mdarr2_sub_rO_to( coeff_t    lhs, mdarr2_t*   rhs, mdarr2_t* res);
void mdarr2_sub_Or_to( mdarr2_t*   lhs, coeff_t    rhs, mdarr2_t* res);
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
mdarr2_t mdarr2_mul_OO(mdarr2_t*   lhs, mdarr2_t* rhs);
mdarr2_t mdarr2_mul_RO(darr_t*    lhs, mdarr2_t* rhs);
mdarr2_t mdarr2_mul_oO(mdnum2_t* lhs, mdarr2_t* rhs);
mdarr2_t mdarr2_mul_rO(coeff_t    lhs, mdarr2_t* rhs);

void mdarr2_mul_OO_to(mdarr2_t*   lhs, mdarr2_t* rhs, mdarr2_t* res);
void mdarr2_mul_RO_to(darr_t*    lhs, mdarr2_t* rhs, mdarr2_t* res);
void mdarr2_mul_oO_to(mdnum2_t* lhs, mdarr2_t* rhs, mdarr2_t* res);
void mdarr2_mul_rO_to(coeff_t    lhs, mdarr2_t* rhs, mdarr2_t* res);

// ARR1 * ARR2 + ARR3
void mdarr2_gem_OO_to(  mdarr2_t* arr1, mdarr2_t* arr2, mdarr2_t* arr3, mdarr2_t* res);
void mdarr2_gem_oO_to(mdnum2_t* arr1, mdarr2_t* arr2, mdarr2_t* arr3, mdarr2_t* res);
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
mdarr2_t mdarr2_div_OO(mdarr2_t*   lhs, mdarr2_t*   rhs);
mdarr2_t mdarr2_div_OR(mdarr2_t*   lhs, darr_t*    rhs);
mdarr2_t mdarr2_div_RO(darr_t*    lhs, mdarr2_t*   rhs);
mdarr2_t mdarr2_div_oO(mdnum2_t* lhs, mdarr2_t*   rhs);
mdarr2_t mdarr2_div_Oo(mdarr2_t*   lhs, mdnum2_t* rhs);
mdarr2_t mdarr2_div_rO(coeff_t    lhs, mdarr2_t*   rhs);
mdarr2_t mdarr2_div_Or(mdarr2_t*   lhs, coeff_t    rhs);

void mdarr2_div_OO_to(mdarr2_t*   lhs, mdarr2_t*   rhs, mdarr2_t* res);
void mdarr2_div_RO_to(darr_t*    lhs, mdarr2_t*   rhs, mdarr2_t* res);
void mdarr2_div_OR_to(mdarr2_t*   lhs, darr_t*    rhs, mdarr2_t* res);
void mdarr2_div_oO_to(mdnum2_t* lhs, mdarr2_t*   rhs, mdarr2_t* res);
void mdarr2_div_Oo_to(mdarr2_t*   lhs, mdnum2_t* rhs, mdarr2_t* res);
void mdarr2_div_rO_to(coeff_t    lhs, mdarr2_t*   rhs, mdarr2_t* res);
void mdarr2_div_Or_to(mdarr2_t*   lhs, coeff_t    rhs, mdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
