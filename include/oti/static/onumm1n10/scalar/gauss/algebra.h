#ifndef OTI_ONUMM1N10_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM1N10_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n10_t feonumm1n10_neg(   feonumm1n10_t* num);
void     feonumm1n10_neg_to(feonumm1n10_t* num, feonumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n10_t feonumm1n10_sum_ff(   feonumm1n10_t* lhs, feonumm1n10_t* rhs);
void     feonumm1n10_sum_ff_to(feonumm1n10_t* lhs, feonumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_sum_of(   onumm1n10_t* lhs, feonumm1n10_t* rhs);
void     feonumm1n10_sum_of_to(onumm1n10_t* lhs, feonumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_sum_rf(   coeff_t lhs, feonumm1n10_t* rhs);
void     feonumm1n10_sum_rf_to(coeff_t lhs, feonumm1n10_t* rhs, feonumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n10_t feonumm1n10_sub_ff(     feonumm1n10_t* lhs,  feonumm1n10_t* rhs);
void     feonumm1n10_sub_ff_to(  feonumm1n10_t* lhs,  feonumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_sub_of(    onumm1n10_t* lhs,  feonumm1n10_t* rhs);
void     feonumm1n10_sub_of_to( onumm1n10_t* lhs,  feonumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_sub_fo(     feonumm1n10_t* lhs, onumm1n10_t* rhs);
void     feonumm1n10_sub_fo_to(  feonumm1n10_t* lhs, onumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_sub_rf(       coeff_t lhs,  feonumm1n10_t* rhs);
void     feonumm1n10_sub_rf_to(    coeff_t lhs,  feonumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_sub_fr(     feonumm1n10_t* lhs,    coeff_t rhs);
void     feonumm1n10_sub_fr_to(  feonumm1n10_t* lhs,    coeff_t rhs, feonumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n10_t feonumm1n10_mul_ff(   feonumm1n10_t* lhs, feonumm1n10_t* rhs);
void     feonumm1n10_mul_ff_to(feonumm1n10_t* lhs, feonumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_mul_of(   onumm1n10_t* lhs, feonumm1n10_t* rhs);
void     feonumm1n10_mul_of_to(onumm1n10_t* lhs, feonumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_mul_rf(   coeff_t lhs, feonumm1n10_t* rhs);
void     feonumm1n10_mul_rf_to(coeff_t lhs, feonumm1n10_t* rhs, feonumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n10_t feonumm1n10_div_ff(     feonumm1n10_t* lhs,  feonumm1n10_t* rhs);
void     feonumm1n10_div_ff_to(  feonumm1n10_t* lhs,  feonumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_div_of(    onumm1n10_t* lhs,  feonumm1n10_t* rhs);
void     feonumm1n10_div_of_to( onumm1n10_t* lhs,  feonumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_div_fo(     feonumm1n10_t* lhs, onumm1n10_t* rhs);
void     feonumm1n10_div_fo_to(  feonumm1n10_t* lhs, onumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_div_rf(       coeff_t lhs,  feonumm1n10_t* rhs);
void     feonumm1n10_div_rf_to(    coeff_t lhs,  feonumm1n10_t* rhs, feonumm1n10_t* res);

feonumm1n10_t feonumm1n10_div_fr(     feonumm1n10_t* lhs,    coeff_t rhs);
void     feonumm1n10_div_fr_to(  feonumm1n10_t* lhs,    coeff_t rhs, feonumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif