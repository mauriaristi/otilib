#ifndef OTI_ONUMM2N4_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM2N4_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n4_t feonumm2n4_neg(   feonumm2n4_t* num);
void     feonumm2n4_neg_to(feonumm2n4_t* num, feonumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n4_t feonumm2n4_sum_ff(   feonumm2n4_t* lhs, feonumm2n4_t* rhs);
void     feonumm2n4_sum_ff_to(feonumm2n4_t* lhs, feonumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_sum_of(   onumm2n4_t* lhs, feonumm2n4_t* rhs);
void     feonumm2n4_sum_of_to(onumm2n4_t* lhs, feonumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_sum_rf(   coeff_t lhs, feonumm2n4_t* rhs);
void     feonumm2n4_sum_rf_to(coeff_t lhs, feonumm2n4_t* rhs, feonumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n4_t feonumm2n4_sub_ff(     feonumm2n4_t* lhs,  feonumm2n4_t* rhs);
void     feonumm2n4_sub_ff_to(  feonumm2n4_t* lhs,  feonumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_sub_of(    onumm2n4_t* lhs,  feonumm2n4_t* rhs);
void     feonumm2n4_sub_of_to( onumm2n4_t* lhs,  feonumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_sub_fo(     feonumm2n4_t* lhs, onumm2n4_t* rhs);
void     feonumm2n4_sub_fo_to(  feonumm2n4_t* lhs, onumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_sub_rf(       coeff_t lhs,  feonumm2n4_t* rhs);
void     feonumm2n4_sub_rf_to(    coeff_t lhs,  feonumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_sub_fr(     feonumm2n4_t* lhs,    coeff_t rhs);
void     feonumm2n4_sub_fr_to(  feonumm2n4_t* lhs,    coeff_t rhs, feonumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n4_t feonumm2n4_mul_ff(   feonumm2n4_t* lhs, feonumm2n4_t* rhs);
void     feonumm2n4_mul_ff_to(feonumm2n4_t* lhs, feonumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_mul_of(   onumm2n4_t* lhs, feonumm2n4_t* rhs);
void     feonumm2n4_mul_of_to(onumm2n4_t* lhs, feonumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_mul_rf(   coeff_t lhs, feonumm2n4_t* rhs);
void     feonumm2n4_mul_rf_to(coeff_t lhs, feonumm2n4_t* rhs, feonumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n4_t feonumm2n4_div_ff(     feonumm2n4_t* lhs,  feonumm2n4_t* rhs);
void     feonumm2n4_div_ff_to(  feonumm2n4_t* lhs,  feonumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_div_of(    onumm2n4_t* lhs,  feonumm2n4_t* rhs);
void     feonumm2n4_div_of_to( onumm2n4_t* lhs,  feonumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_div_fo(     feonumm2n4_t* lhs, onumm2n4_t* rhs);
void     feonumm2n4_div_fo_to(  feonumm2n4_t* lhs, onumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_div_rf(       coeff_t lhs,  feonumm2n4_t* rhs);
void     feonumm2n4_div_rf_to(    coeff_t lhs,  feonumm2n4_t* rhs, feonumm2n4_t* res);

feonumm2n4_t feonumm2n4_div_fr(     feonumm2n4_t* lhs,    coeff_t rhs);
void     feonumm2n4_div_fr_to(  feonumm2n4_t* lhs,    coeff_t rhs, feonumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif