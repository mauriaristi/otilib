#ifndef OTI_MDNUM7_ARRAY_ALGEBRA_ELEMENTWISE_H
#define OTI_MDNUM7_ARRAY_ALGEBRA_ELEMENTWISE_H

/**************************************************************************************************//**
@brief Negation operation for array of sparse oti numbers object type. The following operations 
       are supported:

       res = - rhs

- OO:  -  Array of SOTIs

@param[in]    rhs    Reft hand side element of the operation.
@param[inout] res    Arrso object with the result of the operation.
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr7_t mdarr7_neg(mdarr7_t* arr);

void mdarr7_neg_to(mdarr7_t* rhs, mdarr7_t* res);
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
mdarr7_t mdarr7_sum_OO(mdarr7_t*   lhs, mdarr7_t* rhs);
mdarr7_t mdarr7_sum_RO(darr_t*    lhs, mdarr7_t* rhs);
mdarr7_t mdarr7_sum_oO(mdnum7_t* lhs, mdarr7_t* rhs);
mdarr7_t mdarr7_sum_rO(coeff_t    lhs, mdarr7_t* rhs);

void mdarr7_sum_OO_to(mdarr7_t*   lhs, mdarr7_t* rhs, mdarr7_t* res);
void mdarr7_sum_RO_to(darr_t*    lhs, mdarr7_t* rhs, mdarr7_t* res);
void mdarr7_sum_oO_to(mdnum7_t* lhs, mdarr7_t* rhs, mdarr7_t* res);
void mdarr7_sum_rO_to(coeff_t    lhs, mdarr7_t* rhs, mdarr7_t* res);
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
mdarr7_t mdarr7_sub_OO(mdarr7_t*   lhs, mdarr7_t*   rhs);
mdarr7_t mdarr7_sub_RO(darr_t*    lhs, mdarr7_t*   rhs);
mdarr7_t mdarr7_sub_OR(mdarr7_t*   lhs, darr_t*    rhs);
mdarr7_t mdarr7_sub_oO(mdnum7_t* lhs, mdarr7_t*   rhs);
mdarr7_t mdarr7_sub_Oo(mdarr7_t*   lhs, mdnum7_t* rhs);
mdarr7_t mdarr7_sub_rO(coeff_t    lhs, mdarr7_t*   rhs);
mdarr7_t mdarr7_sub_Or(mdarr7_t*   lhs, coeff_t    rhs);

void mdarr7_sub_OO_to( mdarr7_t*   lhs, mdarr7_t*   rhs, mdarr7_t* res);
void mdarr7_sub_RO_to( darr_t*    lhs, mdarr7_t*   rhs, mdarr7_t* res);
void mdarr7_sub_OR_to( mdarr7_t*   lhs, darr_t*    rhs, mdarr7_t* res);
void mdarr7_sub_oO_to( mdnum7_t* lhs, mdarr7_t*   rhs, mdarr7_t* res);
void mdarr7_sub_Oo_to( mdarr7_t*   lhs, mdnum7_t* rhs, mdarr7_t* res);
void mdarr7_sub_rO_to( coeff_t    lhs, mdarr7_t*   rhs, mdarr7_t* res);
void mdarr7_sub_Or_to( mdarr7_t*   lhs, coeff_t    rhs, mdarr7_t* res);
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
mdarr7_t mdarr7_mul_OO(mdarr7_t*   lhs, mdarr7_t* rhs);
mdarr7_t mdarr7_mul_RO(darr_t*    lhs, mdarr7_t* rhs);
mdarr7_t mdarr7_mul_oO(mdnum7_t* lhs, mdarr7_t* rhs);
mdarr7_t mdarr7_mul_rO(coeff_t    lhs, mdarr7_t* rhs);

void mdarr7_mul_OO_to(mdarr7_t*   lhs, mdarr7_t* rhs, mdarr7_t* res);
void mdarr7_mul_RO_to(darr_t*    lhs, mdarr7_t* rhs, mdarr7_t* res);
void mdarr7_mul_oO_to(mdnum7_t* lhs, mdarr7_t* rhs, mdarr7_t* res);
void mdarr7_mul_rO_to(coeff_t    lhs, mdarr7_t* rhs, mdarr7_t* res);

// ARR1 * ARR2 + ARR3
void mdarr7_gem_OO_to(  mdarr7_t* arr1, mdarr7_t* arr2, mdarr7_t* arr3, mdarr7_t* res);
void mdarr7_gem_oO_to(mdnum7_t* arr1, mdarr7_t* arr2, mdarr7_t* arr3, mdarr7_t* res);
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
mdarr7_t mdarr7_div_OO(mdarr7_t*   lhs, mdarr7_t*   rhs);
mdarr7_t mdarr7_div_OR(mdarr7_t*   lhs, darr_t*    rhs);
mdarr7_t mdarr7_div_RO(darr_t*    lhs, mdarr7_t*   rhs);
mdarr7_t mdarr7_div_oO(mdnum7_t* lhs, mdarr7_t*   rhs);
mdarr7_t mdarr7_div_Oo(mdarr7_t*   lhs, mdnum7_t* rhs);
mdarr7_t mdarr7_div_rO(coeff_t    lhs, mdarr7_t*   rhs);
mdarr7_t mdarr7_div_Or(mdarr7_t*   lhs, coeff_t    rhs);

void mdarr7_div_OO_to(mdarr7_t*   lhs, mdarr7_t*   rhs, mdarr7_t* res);
void mdarr7_div_RO_to(darr_t*    lhs, mdarr7_t*   rhs, mdarr7_t* res);
void mdarr7_div_OR_to(mdarr7_t*   lhs, darr_t*    rhs, mdarr7_t* res);
void mdarr7_div_oO_to(mdnum7_t* lhs, mdarr7_t*   rhs, mdarr7_t* res);
void mdarr7_div_Oo_to(mdarr7_t*   lhs, mdnum7_t* rhs, mdarr7_t* res);
void mdarr7_div_rO_to(coeff_t    lhs, mdarr7_t*   rhs, mdarr7_t* res);
void mdarr7_div_Or_to(mdarr7_t*   lhs, coeff_t    rhs, mdarr7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif
