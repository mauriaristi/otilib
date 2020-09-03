#ifndef OTI_MDNUM4_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_MDNUM4_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr4_t mdarr4_neg(mdarr4_t* arr);

void mdarr4_neg_to(mdarr4_t* rhs, mdarr4_t* res);
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
mdarr4_t mdarr4_sum_OO(mdarr4_t*   lhs, mdarr4_t* rhs);
mdarr4_t mdarr4_sum_RO(darr_t*    lhs, mdarr4_t* rhs);
mdarr4_t mdarr4_sum_oO(mdnum4_t* lhs, mdarr4_t* rhs);
mdarr4_t mdarr4_sum_rO(coeff_t    lhs, mdarr4_t* rhs);

void mdarr4_sum_OO_to(mdarr4_t*   lhs, mdarr4_t* rhs, mdarr4_t* res);
void mdarr4_sum_RO_to(darr_t*    lhs, mdarr4_t* rhs, mdarr4_t* res);
void mdarr4_sum_oO_to(mdnum4_t* lhs, mdarr4_t* rhs, mdarr4_t* res);
void mdarr4_sum_rO_to(coeff_t    lhs, mdarr4_t* rhs, mdarr4_t* res);
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
mdarr4_t mdarr4_sub_OO(mdarr4_t*   lhs, mdarr4_t*   rhs);
mdarr4_t mdarr4_sub_RO(darr_t*    lhs, mdarr4_t*   rhs);
mdarr4_t mdarr4_sub_OR(mdarr4_t*   lhs, darr_t*    rhs);
mdarr4_t mdarr4_sub_oO(mdnum4_t* lhs, mdarr4_t*   rhs);
mdarr4_t mdarr4_sub_Oo(mdarr4_t*   lhs, mdnum4_t* rhs);
mdarr4_t mdarr4_sub_rO(coeff_t    lhs, mdarr4_t*   rhs);
mdarr4_t mdarr4_sub_Or(mdarr4_t*   lhs, coeff_t    rhs);

void mdarr4_sub_OO_to( mdarr4_t*   lhs, mdarr4_t*   rhs, mdarr4_t* res);
void mdarr4_sub_RO_to( darr_t*    lhs, mdarr4_t*   rhs, mdarr4_t* res);
void mdarr4_sub_OR_to( mdarr4_t*   lhs, darr_t*    rhs, mdarr4_t* res);
void mdarr4_sub_oO_to( mdnum4_t* lhs, mdarr4_t*   rhs, mdarr4_t* res);
void mdarr4_sub_Oo_to( mdarr4_t*   lhs, mdnum4_t* rhs, mdarr4_t* res);
void mdarr4_sub_rO_to( coeff_t    lhs, mdarr4_t*   rhs, mdarr4_t* res);
void mdarr4_sub_Or_to( mdarr4_t*   lhs, coeff_t    rhs, mdarr4_t* res);
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
mdarr4_t mdarr4_mul_OO(mdarr4_t*   lhs, mdarr4_t* rhs);
mdarr4_t mdarr4_mul_RO(darr_t*    lhs, mdarr4_t* rhs);
mdarr4_t mdarr4_mul_oO(mdnum4_t* lhs, mdarr4_t* rhs);
mdarr4_t mdarr4_mul_rO(coeff_t    lhs, mdarr4_t* rhs);

void mdarr4_mul_OO_to(mdarr4_t*   lhs, mdarr4_t* rhs, mdarr4_t* res);
void mdarr4_mul_RO_to(darr_t*    lhs, mdarr4_t* rhs, mdarr4_t* res);
void mdarr4_mul_oO_to(mdnum4_t* lhs, mdarr4_t* rhs, mdarr4_t* res);
void mdarr4_mul_rO_to(coeff_t    lhs, mdarr4_t* rhs, mdarr4_t* res);

// ARR1 * ARR2 + ARR3
void mdarr4_gem_OO_to(  mdarr4_t* arr1, mdarr4_t* arr2, mdarr4_t* arr3, mdarr4_t* res);
void mdarr4_gem_oO_to(mdnum4_t* arr1, mdarr4_t* arr2, mdarr4_t* arr3, mdarr4_t* res);
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
mdarr4_t mdarr4_div_OO(mdarr4_t*   lhs, mdarr4_t*   rhs);
mdarr4_t mdarr4_div_OR(mdarr4_t*   lhs, darr_t*    rhs);
mdarr4_t mdarr4_div_RO(darr_t*    lhs, mdarr4_t*   rhs);
mdarr4_t mdarr4_div_oO(mdnum4_t* lhs, mdarr4_t*   rhs);
mdarr4_t mdarr4_div_Oo(mdarr4_t*   lhs, mdnum4_t* rhs);
mdarr4_t mdarr4_div_rO(coeff_t    lhs, mdarr4_t*   rhs);
mdarr4_t mdarr4_div_Or(mdarr4_t*   lhs, coeff_t    rhs);

void mdarr4_div_OO_to(mdarr4_t*   lhs, mdarr4_t*   rhs, mdarr4_t* res);
void mdarr4_div_RO_to(darr_t*    lhs, mdarr4_t*   rhs, mdarr4_t* res);
void mdarr4_div_OR_to(mdarr4_t*   lhs, darr_t*    rhs, mdarr4_t* res);
void mdarr4_div_oO_to(mdnum4_t* lhs, mdarr4_t*   rhs, mdarr4_t* res);
void mdarr4_div_Oo_to(mdarr4_t*   lhs, mdnum4_t* rhs, mdarr4_t* res);
void mdarr4_div_rO_to(coeff_t    lhs, mdarr4_t*   rhs, mdarr4_t* res);
void mdarr4_div_Or_to(mdarr4_t*   lhs, coeff_t    rhs, mdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif