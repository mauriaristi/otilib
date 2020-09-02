#ifndef OTI_ONUMM2N7_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM2N7_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n7_t feonumm2n7_neg(   feonumm2n7_t* num);
void     feonumm2n7_neg_to(feonumm2n7_t* num, feonumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n7_t feonumm2n7_sum_ff(   feonumm2n7_t* lhs, feonumm2n7_t* rhs);
void     feonumm2n7_sum_ff_to(feonumm2n7_t* lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_sum_of(   onumm2n7_t* lhs, feonumm2n7_t* rhs);
void     feonumm2n7_sum_of_to(onumm2n7_t* lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_sum_rf(   coeff_t lhs, feonumm2n7_t* rhs);
void     feonumm2n7_sum_rf_to(coeff_t lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n7_t feonumm2n7_sub_ff(     feonumm2n7_t* lhs,  feonumm2n7_t* rhs);
void     feonumm2n7_sub_ff_to(  feonumm2n7_t* lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_sub_of(    onumm2n7_t* lhs,  feonumm2n7_t* rhs);
void     feonumm2n7_sub_of_to( onumm2n7_t* lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_sub_fo(     feonumm2n7_t* lhs, onumm2n7_t* rhs);
void     feonumm2n7_sub_fo_to(  feonumm2n7_t* lhs, onumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_sub_rf(       coeff_t lhs,  feonumm2n7_t* rhs);
void     feonumm2n7_sub_rf_to(    coeff_t lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_sub_fr(     feonumm2n7_t* lhs,    coeff_t rhs);
void     feonumm2n7_sub_fr_to(  feonumm2n7_t* lhs,    coeff_t rhs, feonumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n7_t feonumm2n7_mul_ff(   feonumm2n7_t* lhs, feonumm2n7_t* rhs);
void     feonumm2n7_mul_ff_to(feonumm2n7_t* lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_mul_of(   onumm2n7_t* lhs, feonumm2n7_t* rhs);
void     feonumm2n7_mul_of_to(onumm2n7_t* lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_mul_rf(   coeff_t lhs, feonumm2n7_t* rhs);
void     feonumm2n7_mul_rf_to(coeff_t lhs, feonumm2n7_t* rhs, feonumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n7_t feonumm2n7_div_ff(     feonumm2n7_t* lhs,  feonumm2n7_t* rhs);
void     feonumm2n7_div_ff_to(  feonumm2n7_t* lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_div_of(    onumm2n7_t* lhs,  feonumm2n7_t* rhs);
void     feonumm2n7_div_of_to( onumm2n7_t* lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_div_fo(     feonumm2n7_t* lhs, onumm2n7_t* rhs);
void     feonumm2n7_div_fo_to(  feonumm2n7_t* lhs, onumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_div_rf(       coeff_t lhs,  feonumm2n7_t* rhs);
void     feonumm2n7_div_rf_to(    coeff_t lhs,  feonumm2n7_t* rhs, feonumm2n7_t* res);

feonumm2n7_t feonumm2n7_div_fr(     feonumm2n7_t* lhs,    coeff_t rhs);
void     feonumm2n7_div_fr_to(  feonumm2n7_t* lhs,    coeff_t rhs, feonumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif