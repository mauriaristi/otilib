#ifndef OTI_MDNUM1_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_MDNUM1_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr1_t mdarr1_neg(mdarr1_t* arr);

void mdarr1_neg_to(mdarr1_t* rhs, mdarr1_t* res);
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
mdarr1_t mdarr1_sum_OO(mdarr1_t*   lhs, mdarr1_t* rhs);
mdarr1_t mdarr1_sum_RO(darr_t*    lhs, mdarr1_t* rhs);
mdarr1_t mdarr1_sum_oO(mdnum1_t* lhs, mdarr1_t* rhs);
mdarr1_t mdarr1_sum_rO(coeff_t    lhs, mdarr1_t* rhs);

void mdarr1_sum_OO_to(mdarr1_t*   lhs, mdarr1_t* rhs, mdarr1_t* res);
void mdarr1_sum_RO_to(darr_t*    lhs, mdarr1_t* rhs, mdarr1_t* res);
void mdarr1_sum_oO_to(mdnum1_t* lhs, mdarr1_t* rhs, mdarr1_t* res);
void mdarr1_sum_rO_to(coeff_t    lhs, mdarr1_t* rhs, mdarr1_t* res);
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
mdarr1_t mdarr1_sub_OO(mdarr1_t*   lhs, mdarr1_t*   rhs);
mdarr1_t mdarr1_sub_RO(darr_t*    lhs, mdarr1_t*   rhs);
mdarr1_t mdarr1_sub_OR(mdarr1_t*   lhs, darr_t*    rhs);
mdarr1_t mdarr1_sub_oO(mdnum1_t* lhs, mdarr1_t*   rhs);
mdarr1_t mdarr1_sub_Oo(mdarr1_t*   lhs, mdnum1_t* rhs);
mdarr1_t mdarr1_sub_rO(coeff_t    lhs, mdarr1_t*   rhs);
mdarr1_t mdarr1_sub_Or(mdarr1_t*   lhs, coeff_t    rhs);

void mdarr1_sub_OO_to( mdarr1_t*   lhs, mdarr1_t*   rhs, mdarr1_t* res);
void mdarr1_sub_RO_to( darr_t*    lhs, mdarr1_t*   rhs, mdarr1_t* res);
void mdarr1_sub_OR_to( mdarr1_t*   lhs, darr_t*    rhs, mdarr1_t* res);
void mdarr1_sub_oO_to( mdnum1_t* lhs, mdarr1_t*   rhs, mdarr1_t* res);
void mdarr1_sub_Oo_to( mdarr1_t*   lhs, mdnum1_t* rhs, mdarr1_t* res);
void mdarr1_sub_rO_to( coeff_t    lhs, mdarr1_t*   rhs, mdarr1_t* res);
void mdarr1_sub_Or_to( mdarr1_t*   lhs, coeff_t    rhs, mdarr1_t* res);
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
mdarr1_t mdarr1_mul_OO(mdarr1_t*   lhs, mdarr1_t* rhs);
mdarr1_t mdarr1_mul_RO(darr_t*    lhs, mdarr1_t* rhs);
mdarr1_t mdarr1_mul_oO(mdnum1_t* lhs, mdarr1_t* rhs);
mdarr1_t mdarr1_mul_rO(coeff_t    lhs, mdarr1_t* rhs);

void mdarr1_mul_OO_to(mdarr1_t*   lhs, mdarr1_t* rhs, mdarr1_t* res);
void mdarr1_mul_RO_to(darr_t*    lhs, mdarr1_t* rhs, mdarr1_t* res);
void mdarr1_mul_oO_to(mdnum1_t* lhs, mdarr1_t* rhs, mdarr1_t* res);
void mdarr1_mul_rO_to(coeff_t    lhs, mdarr1_t* rhs, mdarr1_t* res);

// ARR1 * ARR2 + ARR3
void mdarr1_gem_OO_to(  mdarr1_t* arr1, mdarr1_t* arr2, mdarr1_t* arr3, mdarr1_t* res);
void mdarr1_gem_oO_to(mdnum1_t* arr1, mdarr1_t* arr2, mdarr1_t* arr3, mdarr1_t* res);
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
mdarr1_t mdarr1_div_OO(mdarr1_t*   lhs, mdarr1_t*   rhs);
mdarr1_t mdarr1_div_OR(mdarr1_t*   lhs, darr_t*    rhs);
mdarr1_t mdarr1_div_RO(darr_t*    lhs, mdarr1_t*   rhs);
mdarr1_t mdarr1_div_oO(mdnum1_t* lhs, mdarr1_t*   rhs);
mdarr1_t mdarr1_div_Oo(mdarr1_t*   lhs, mdnum1_t* rhs);
mdarr1_t mdarr1_div_rO(coeff_t    lhs, mdarr1_t*   rhs);
mdarr1_t mdarr1_div_Or(mdarr1_t*   lhs, coeff_t    rhs);

void mdarr1_div_OO_to(mdarr1_t*   lhs, mdarr1_t*   rhs, mdarr1_t* res);
void mdarr1_div_RO_to(darr_t*    lhs, mdarr1_t*   rhs, mdarr1_t* res);
void mdarr1_div_OR_to(mdarr1_t*   lhs, darr_t*    rhs, mdarr1_t* res);
void mdarr1_div_oO_to(mdnum1_t* lhs, mdarr1_t*   rhs, mdarr1_t* res);
void mdarr1_div_Oo_to(mdarr1_t*   lhs, mdnum1_t* rhs, mdarr1_t* res);
void mdarr1_div_rO_to(coeff_t    lhs, mdarr1_t*   rhs, mdarr1_t* res);
void mdarr1_div_Or_to(mdarr1_t*   lhs, coeff_t    rhs, mdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
