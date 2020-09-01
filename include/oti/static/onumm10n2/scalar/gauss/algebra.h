#ifndef OTI_ONUMM10N2_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM10N2_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n2_t feonumm10n2_neg(   feonumm10n2_t* num);
void     feonumm10n2_neg_to(feonumm10n2_t* num, feonumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n2_t feonumm10n2_sum_ff(   feonumm10n2_t* lhs, feonumm10n2_t* rhs);
void     feonumm10n2_sum_ff_to(feonumm10n2_t* lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_sum_of(   onumm10n2_t* lhs, feonumm10n2_t* rhs);
void     feonumm10n2_sum_of_to(onumm10n2_t* lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_sum_rf(   coeff_t lhs, feonumm10n2_t* rhs);
void     feonumm10n2_sum_rf_to(coeff_t lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n2_t feonumm10n2_sub_ff(     feonumm10n2_t* lhs,  feonumm10n2_t* rhs);
void     feonumm10n2_sub_ff_to(  feonumm10n2_t* lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_sub_of(    onumm10n2_t* lhs,  feonumm10n2_t* rhs);
void     feonumm10n2_sub_of_to( onumm10n2_t* lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_sub_fo(     feonumm10n2_t* lhs, onumm10n2_t* rhs);
void     feonumm10n2_sub_fo_to(  feonumm10n2_t* lhs, onumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_sub_rf(       coeff_t lhs,  feonumm10n2_t* rhs);
void     feonumm10n2_sub_rf_to(    coeff_t lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_sub_fr(     feonumm10n2_t* lhs,    coeff_t rhs);
void     feonumm10n2_sub_fr_to(  feonumm10n2_t* lhs,    coeff_t rhs, feonumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n2_t feonumm10n2_mul_ff(   feonumm10n2_t* lhs, feonumm10n2_t* rhs);
void     feonumm10n2_mul_ff_to(feonumm10n2_t* lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_mul_of(   onumm10n2_t* lhs, feonumm10n2_t* rhs);
void     feonumm10n2_mul_of_to(onumm10n2_t* lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_mul_rf(   coeff_t lhs, feonumm10n2_t* rhs);
void     feonumm10n2_mul_rf_to(coeff_t lhs, feonumm10n2_t* rhs, feonumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm10n2_t feonumm10n2_div_ff(     feonumm10n2_t* lhs,  feonumm10n2_t* rhs);
void     feonumm10n2_div_ff_to(  feonumm10n2_t* lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_div_of(    onumm10n2_t* lhs,  feonumm10n2_t* rhs);
void     feonumm10n2_div_of_to( onumm10n2_t* lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_div_fo(     feonumm10n2_t* lhs, onumm10n2_t* rhs);
void     feonumm10n2_div_fo_to(  feonumm10n2_t* lhs, onumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_div_rf(       coeff_t lhs,  feonumm10n2_t* rhs);
void     feonumm10n2_div_rf_to(    coeff_t lhs,  feonumm10n2_t* rhs, feonumm10n2_t* res);

feonumm10n2_t feonumm10n2_div_fr(     feonumm10n2_t* lhs,    coeff_t rhs);
void     feonumm10n2_div_fr_to(  feonumm10n2_t* lhs,    coeff_t rhs, feonumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif