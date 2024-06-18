#ifndef OTI_ONUMM3N4_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM3N4_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n4_t feonumm3n4_neg(   feonumm3n4_t* num);
void     feonumm3n4_neg_to(feonumm3n4_t* num, feonumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n4_t feonumm3n4_sum_ff(   feonumm3n4_t* lhs, feonumm3n4_t* rhs);
void     feonumm3n4_sum_ff_to(feonumm3n4_t* lhs, feonumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_sum_of(   onumm3n4_t* lhs, feonumm3n4_t* rhs);
void     feonumm3n4_sum_of_to(onumm3n4_t* lhs, feonumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_sum_rf(   coeff_t lhs, feonumm3n4_t* rhs);
void     feonumm3n4_sum_rf_to(coeff_t lhs, feonumm3n4_t* rhs, feonumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n4_t feonumm3n4_sub_ff(     feonumm3n4_t* lhs,  feonumm3n4_t* rhs);
void     feonumm3n4_sub_ff_to(  feonumm3n4_t* lhs,  feonumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_sub_of(    onumm3n4_t* lhs,  feonumm3n4_t* rhs);
void     feonumm3n4_sub_of_to( onumm3n4_t* lhs,  feonumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_sub_fo(     feonumm3n4_t* lhs, onumm3n4_t* rhs);
void     feonumm3n4_sub_fo_to(  feonumm3n4_t* lhs, onumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_sub_rf(       coeff_t lhs,  feonumm3n4_t* rhs);
void     feonumm3n4_sub_rf_to(    coeff_t lhs,  feonumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_sub_fr(     feonumm3n4_t* lhs,    coeff_t rhs);
void     feonumm3n4_sub_fr_to(  feonumm3n4_t* lhs,    coeff_t rhs, feonumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n4_t feonumm3n4_mul_ff(   feonumm3n4_t* lhs, feonumm3n4_t* rhs);
void     feonumm3n4_mul_ff_to(feonumm3n4_t* lhs, feonumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_mul_of(   onumm3n4_t* lhs, feonumm3n4_t* rhs);
void     feonumm3n4_mul_of_to(onumm3n4_t* lhs, feonumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_mul_rf(   coeff_t lhs, feonumm3n4_t* rhs);
void     feonumm3n4_mul_rf_to(coeff_t lhs, feonumm3n4_t* rhs, feonumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n4_t feonumm3n4_div_ff(     feonumm3n4_t* lhs,  feonumm3n4_t* rhs);
void     feonumm3n4_div_ff_to(  feonumm3n4_t* lhs,  feonumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_div_of(    onumm3n4_t* lhs,  feonumm3n4_t* rhs);
void     feonumm3n4_div_of_to( onumm3n4_t* lhs,  feonumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_div_fo(     feonumm3n4_t* lhs, onumm3n4_t* rhs);
void     feonumm3n4_div_fo_to(  feonumm3n4_t* lhs, onumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_div_rf(       coeff_t lhs,  feonumm3n4_t* rhs);
void     feonumm3n4_div_rf_to(    coeff_t lhs,  feonumm3n4_t* rhs, feonumm3n4_t* res);

feonumm3n4_t feonumm3n4_div_fr(     feonumm3n4_t* lhs,    coeff_t rhs);
void     feonumm3n4_div_fr_to(  feonumm3n4_t* lhs,    coeff_t rhs, feonumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif