#ifndef OTI_ONUMM1N2_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM1N2_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n2_t feonumm1n2_neg(   feonumm1n2_t* num);
void     feonumm1n2_neg_to(feonumm1n2_t* num, feonumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n2_t feonumm1n2_sum_ff(   feonumm1n2_t* lhs, feonumm1n2_t* rhs);
void     feonumm1n2_sum_ff_to(feonumm1n2_t* lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_sum_of(   onumm1n2_t* lhs, feonumm1n2_t* rhs);
void     feonumm1n2_sum_of_to(onumm1n2_t* lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_sum_rf(   coeff_t lhs, feonumm1n2_t* rhs);
void     feonumm1n2_sum_rf_to(coeff_t lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n2_t feonumm1n2_sub_ff(     feonumm1n2_t* lhs,  feonumm1n2_t* rhs);
void     feonumm1n2_sub_ff_to(  feonumm1n2_t* lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_sub_of(    onumm1n2_t* lhs,  feonumm1n2_t* rhs);
void     feonumm1n2_sub_of_to( onumm1n2_t* lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_sub_fo(     feonumm1n2_t* lhs, onumm1n2_t* rhs);
void     feonumm1n2_sub_fo_to(  feonumm1n2_t* lhs, onumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_sub_rf(       coeff_t lhs,  feonumm1n2_t* rhs);
void     feonumm1n2_sub_rf_to(    coeff_t lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_sub_fr(     feonumm1n2_t* lhs,    coeff_t rhs);
void     feonumm1n2_sub_fr_to(  feonumm1n2_t* lhs,    coeff_t rhs, feonumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n2_t feonumm1n2_mul_ff(   feonumm1n2_t* lhs, feonumm1n2_t* rhs);
void     feonumm1n2_mul_ff_to(feonumm1n2_t* lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_mul_of(   onumm1n2_t* lhs, feonumm1n2_t* rhs);
void     feonumm1n2_mul_of_to(onumm1n2_t* lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_mul_rf(   coeff_t lhs, feonumm1n2_t* rhs);
void     feonumm1n2_mul_rf_to(coeff_t lhs, feonumm1n2_t* rhs, feonumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n2_t feonumm1n2_div_ff(     feonumm1n2_t* lhs,  feonumm1n2_t* rhs);
void     feonumm1n2_div_ff_to(  feonumm1n2_t* lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_div_of(    onumm1n2_t* lhs,  feonumm1n2_t* rhs);
void     feonumm1n2_div_of_to( onumm1n2_t* lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_div_fo(     feonumm1n2_t* lhs, onumm1n2_t* rhs);
void     feonumm1n2_div_fo_to(  feonumm1n2_t* lhs, onumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_div_rf(       coeff_t lhs,  feonumm1n2_t* rhs);
void     feonumm1n2_div_rf_to(    coeff_t lhs,  feonumm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feonumm1n2_div_fr(     feonumm1n2_t* lhs,    coeff_t rhs);
void     feonumm1n2_div_fr_to(  feonumm1n2_t* lhs,    coeff_t rhs, feonumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif