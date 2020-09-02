#ifndef OTI_ONUMM2N10_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM2N10_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n10_t feonumm2n10_neg(   feonumm2n10_t* num);
void     feonumm2n10_neg_to(feonumm2n10_t* num, feonumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n10_t feonumm2n10_sum_ff(   feonumm2n10_t* lhs, feonumm2n10_t* rhs);
void     feonumm2n10_sum_ff_to(feonumm2n10_t* lhs, feonumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_sum_of(   onumm2n10_t* lhs, feonumm2n10_t* rhs);
void     feonumm2n10_sum_of_to(onumm2n10_t* lhs, feonumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_sum_rf(   coeff_t lhs, feonumm2n10_t* rhs);
void     feonumm2n10_sum_rf_to(coeff_t lhs, feonumm2n10_t* rhs, feonumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n10_t feonumm2n10_sub_ff(     feonumm2n10_t* lhs,  feonumm2n10_t* rhs);
void     feonumm2n10_sub_ff_to(  feonumm2n10_t* lhs,  feonumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_sub_of(    onumm2n10_t* lhs,  feonumm2n10_t* rhs);
void     feonumm2n10_sub_of_to( onumm2n10_t* lhs,  feonumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_sub_fo(     feonumm2n10_t* lhs, onumm2n10_t* rhs);
void     feonumm2n10_sub_fo_to(  feonumm2n10_t* lhs, onumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_sub_rf(       coeff_t lhs,  feonumm2n10_t* rhs);
void     feonumm2n10_sub_rf_to(    coeff_t lhs,  feonumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_sub_fr(     feonumm2n10_t* lhs,    coeff_t rhs);
void     feonumm2n10_sub_fr_to(  feonumm2n10_t* lhs,    coeff_t rhs, feonumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n10_t feonumm2n10_mul_ff(   feonumm2n10_t* lhs, feonumm2n10_t* rhs);
void     feonumm2n10_mul_ff_to(feonumm2n10_t* lhs, feonumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_mul_of(   onumm2n10_t* lhs, feonumm2n10_t* rhs);
void     feonumm2n10_mul_of_to(onumm2n10_t* lhs, feonumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_mul_rf(   coeff_t lhs, feonumm2n10_t* rhs);
void     feonumm2n10_mul_rf_to(coeff_t lhs, feonumm2n10_t* rhs, feonumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n10_t feonumm2n10_div_ff(     feonumm2n10_t* lhs,  feonumm2n10_t* rhs);
void     feonumm2n10_div_ff_to(  feonumm2n10_t* lhs,  feonumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_div_of(    onumm2n10_t* lhs,  feonumm2n10_t* rhs);
void     feonumm2n10_div_of_to( onumm2n10_t* lhs,  feonumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_div_fo(     feonumm2n10_t* lhs, onumm2n10_t* rhs);
void     feonumm2n10_div_fo_to(  feonumm2n10_t* lhs, onumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_div_rf(       coeff_t lhs,  feonumm2n10_t* rhs);
void     feonumm2n10_div_rf_to(    coeff_t lhs,  feonumm2n10_t* rhs, feonumm2n10_t* res);

feonumm2n10_t feonumm2n10_div_fr(     feonumm2n10_t* lhs,    coeff_t rhs);
void     feonumm2n10_div_fr_to(  feonumm2n10_t* lhs,    coeff_t rhs, feonumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif