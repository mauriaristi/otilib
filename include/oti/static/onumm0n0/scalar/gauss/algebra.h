#ifndef OTI_ONUMM0N0_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM0N0_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm0n0_t feonumm0n0_neg(   feonumm0n0_t* num);
void     feonumm0n0_neg_to(feonumm0n0_t* num, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm0n0_t feonumm0n0_sum_ff(   feonumm0n0_t* lhs, feonumm0n0_t* rhs);
void     feonumm0n0_sum_ff_to(feonumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_sum_of(   onumm0n0_t* lhs, feonumm0n0_t* rhs);
void     feonumm0n0_sum_of_to(onumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_sum_rf(   coeff_t lhs, feonumm0n0_t* rhs);
void     feonumm0n0_sum_rf_to(coeff_t lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm0n0_t feonumm0n0_sub_ff(     feonumm0n0_t* lhs,  feonumm0n0_t* rhs);
void     feonumm0n0_sub_ff_to(  feonumm0n0_t* lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_sub_of(    onumm0n0_t* lhs,  feonumm0n0_t* rhs);
void     feonumm0n0_sub_of_to( onumm0n0_t* lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_sub_fo(     feonumm0n0_t* lhs, onumm0n0_t* rhs);
void     feonumm0n0_sub_fo_to(  feonumm0n0_t* lhs, onumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_sub_rf(       coeff_t lhs,  feonumm0n0_t* rhs);
void     feonumm0n0_sub_rf_to(    coeff_t lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_sub_fr(     feonumm0n0_t* lhs,    coeff_t rhs);
void     feonumm0n0_sub_fr_to(  feonumm0n0_t* lhs,    coeff_t rhs, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm0n0_t feonumm0n0_mul_ff(   feonumm0n0_t* lhs, feonumm0n0_t* rhs);
void     feonumm0n0_mul_ff_to(feonumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_mul_of(   onumm0n0_t* lhs, feonumm0n0_t* rhs);
void     feonumm0n0_mul_of_to(onumm0n0_t* lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_mul_rf(   coeff_t lhs, feonumm0n0_t* rhs);
void     feonumm0n0_mul_rf_to(coeff_t lhs, feonumm0n0_t* rhs, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm0n0_t feonumm0n0_div_ff(     feonumm0n0_t* lhs,  feonumm0n0_t* rhs);
void     feonumm0n0_div_ff_to(  feonumm0n0_t* lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_div_of(    onumm0n0_t* lhs,  feonumm0n0_t* rhs);
void     feonumm0n0_div_of_to( onumm0n0_t* lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_div_fo(     feonumm0n0_t* lhs, onumm0n0_t* rhs);
void     feonumm0n0_div_fo_to(  feonumm0n0_t* lhs, onumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_div_rf(       coeff_t lhs,  feonumm0n0_t* rhs);
void     feonumm0n0_div_rf_to(    coeff_t lhs,  feonumm0n0_t* rhs, feonumm0n0_t* res);

feonumm0n0_t feonumm0n0_div_fr(     feonumm0n0_t* lhs,    coeff_t rhs);
void     feonumm0n0_div_fr_to(  feonumm0n0_t* lhs,    coeff_t rhs, feonumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

#endif