#ifndef OTI_ONUMM2N9_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM2N9_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n9_t feonumm2n9_neg(   feonumm2n9_t* num);
void     feonumm2n9_neg_to(feonumm2n9_t* num, feonumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n9_t feonumm2n9_sum_ff(   feonumm2n9_t* lhs, feonumm2n9_t* rhs);
void     feonumm2n9_sum_ff_to(feonumm2n9_t* lhs, feonumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_sum_of(   onumm2n9_t* lhs, feonumm2n9_t* rhs);
void     feonumm2n9_sum_of_to(onumm2n9_t* lhs, feonumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_sum_rf(   coeff_t lhs, feonumm2n9_t* rhs);
void     feonumm2n9_sum_rf_to(coeff_t lhs, feonumm2n9_t* rhs, feonumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n9_t feonumm2n9_sub_ff(     feonumm2n9_t* lhs,  feonumm2n9_t* rhs);
void     feonumm2n9_sub_ff_to(  feonumm2n9_t* lhs,  feonumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_sub_of(    onumm2n9_t* lhs,  feonumm2n9_t* rhs);
void     feonumm2n9_sub_of_to( onumm2n9_t* lhs,  feonumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_sub_fo(     feonumm2n9_t* lhs, onumm2n9_t* rhs);
void     feonumm2n9_sub_fo_to(  feonumm2n9_t* lhs, onumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_sub_rf(       coeff_t lhs,  feonumm2n9_t* rhs);
void     feonumm2n9_sub_rf_to(    coeff_t lhs,  feonumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_sub_fr(     feonumm2n9_t* lhs,    coeff_t rhs);
void     feonumm2n9_sub_fr_to(  feonumm2n9_t* lhs,    coeff_t rhs, feonumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n9_t feonumm2n9_mul_ff(   feonumm2n9_t* lhs, feonumm2n9_t* rhs);
void     feonumm2n9_mul_ff_to(feonumm2n9_t* lhs, feonumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_mul_of(   onumm2n9_t* lhs, feonumm2n9_t* rhs);
void     feonumm2n9_mul_of_to(onumm2n9_t* lhs, feonumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_mul_rf(   coeff_t lhs, feonumm2n9_t* rhs);
void     feonumm2n9_mul_rf_to(coeff_t lhs, feonumm2n9_t* rhs, feonumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n9_t feonumm2n9_div_ff(     feonumm2n9_t* lhs,  feonumm2n9_t* rhs);
void     feonumm2n9_div_ff_to(  feonumm2n9_t* lhs,  feonumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_div_of(    onumm2n9_t* lhs,  feonumm2n9_t* rhs);
void     feonumm2n9_div_of_to( onumm2n9_t* lhs,  feonumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_div_fo(     feonumm2n9_t* lhs, onumm2n9_t* rhs);
void     feonumm2n9_div_fo_to(  feonumm2n9_t* lhs, onumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_div_rf(       coeff_t lhs,  feonumm2n9_t* rhs);
void     feonumm2n9_div_rf_to(    coeff_t lhs,  feonumm2n9_t* rhs, feonumm2n9_t* res);

feonumm2n9_t feonumm2n9_div_fr(     feonumm2n9_t* lhs,    coeff_t rhs);
void     feonumm2n9_div_fr_to(  feonumm2n9_t* lhs,    coeff_t rhs, feonumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif