#ifndef OTI_SEMISPARSE_SCALAR_GAUSS_ALGEBRA_H
#define OTI_SEMISPARSE_SCALAR_GAUSS_ALGEBRA_H






/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fessoti_t fessoti_neg(   fessoti_t* num,                dhelpl_t dhl);
void     fessoti_neg_to(fessoti_t* num, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fessoti_t fessoti_sum_ff(   fessoti_t* lhs, fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_sum_ff_to(fessoti_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_sum_of(   semiotin_t* lhs, fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_sum_of_to(semiotin_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_sum_rf(   coeff_t lhs, fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_sum_rf_to(coeff_t lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fessoti_t fessoti_sub_ff(     fessoti_t* lhs,  fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_sub_ff_to(  fessoti_t* lhs,  fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_sub_of(    semiotin_t* lhs,  fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_sub_of_to( semiotin_t* lhs,  fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_sub_fo(     fessoti_t* lhs, semiotin_t* rhs,                dhelpl_t dhl);
void     fessoti_sub_fo_to(  fessoti_t* lhs, semiotin_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_sub_rf(       coeff_t lhs,  fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_sub_rf_to(    coeff_t lhs,  fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_sub_fr(     fessoti_t* lhs,    coeff_t rhs,                dhelpl_t dhl);
void     fessoti_sub_fr_to(  fessoti_t* lhs,    coeff_t rhs, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fessoti_t fessoti_mul_ff(   fessoti_t* lhs, fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_mul_ff_to(fessoti_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_mul_of(   semiotin_t* lhs, fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_mul_of_to(semiotin_t* lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_mul_rf(   coeff_t lhs, fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_mul_rf_to(coeff_t lhs, fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fessoti_t fessoti_div_ff(     fessoti_t* lhs,  fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_div_ff_to(  fessoti_t* lhs,  fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_div_of(    semiotin_t* lhs,  fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_div_of_to( semiotin_t* lhs,  fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_div_fo(     fessoti_t* lhs, semiotin_t* rhs,                dhelpl_t dhl);
void     fessoti_div_fo_to(  fessoti_t* lhs, semiotin_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_div_rf(       coeff_t lhs,  fessoti_t* rhs,                dhelpl_t dhl);
void     fessoti_div_rf_to(    coeff_t lhs,  fessoti_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fessoti_div_fr(     fessoti_t* lhs,    coeff_t rhs,                dhelpl_t dhl);
void     fessoti_div_fr_to(  fessoti_t* lhs,    coeff_t rhs, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------







#endif