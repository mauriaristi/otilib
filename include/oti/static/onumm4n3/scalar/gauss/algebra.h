#ifndef OTI_ONUMM4N3_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM4N3_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n3_t feonumm4n3_neg(   feonumm4n3_t* num);
void     feonumm4n3_neg_to(feonumm4n3_t* num, feonumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n3_t feonumm4n3_sum_ff(   feonumm4n3_t* lhs, feonumm4n3_t* rhs);
void     feonumm4n3_sum_ff_to(feonumm4n3_t* lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_sum_of(   onumm4n3_t* lhs, feonumm4n3_t* rhs);
void     feonumm4n3_sum_of_to(onumm4n3_t* lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_sum_rf(   coeff_t lhs, feonumm4n3_t* rhs);
void     feonumm4n3_sum_rf_to(coeff_t lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n3_t feonumm4n3_sub_ff(     feonumm4n3_t* lhs,  feonumm4n3_t* rhs);
void     feonumm4n3_sub_ff_to(  feonumm4n3_t* lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_sub_of(    onumm4n3_t* lhs,  feonumm4n3_t* rhs);
void     feonumm4n3_sub_of_to( onumm4n3_t* lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_sub_fo(     feonumm4n3_t* lhs, onumm4n3_t* rhs);
void     feonumm4n3_sub_fo_to(  feonumm4n3_t* lhs, onumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_sub_rf(       coeff_t lhs,  feonumm4n3_t* rhs);
void     feonumm4n3_sub_rf_to(    coeff_t lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_sub_fr(     feonumm4n3_t* lhs,    coeff_t rhs);
void     feonumm4n3_sub_fr_to(  feonumm4n3_t* lhs,    coeff_t rhs, feonumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n3_t feonumm4n3_mul_ff(   feonumm4n3_t* lhs, feonumm4n3_t* rhs);
void     feonumm4n3_mul_ff_to(feonumm4n3_t* lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_mul_of(   onumm4n3_t* lhs, feonumm4n3_t* rhs);
void     feonumm4n3_mul_of_to(onumm4n3_t* lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_mul_rf(   coeff_t lhs, feonumm4n3_t* rhs);
void     feonumm4n3_mul_rf_to(coeff_t lhs, feonumm4n3_t* rhs, feonumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm4n3_t feonumm4n3_div_ff(     feonumm4n3_t* lhs,  feonumm4n3_t* rhs);
void     feonumm4n3_div_ff_to(  feonumm4n3_t* lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_div_of(    onumm4n3_t* lhs,  feonumm4n3_t* rhs);
void     feonumm4n3_div_of_to( onumm4n3_t* lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_div_fo(     feonumm4n3_t* lhs, onumm4n3_t* rhs);
void     feonumm4n3_div_fo_to(  feonumm4n3_t* lhs, onumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_div_rf(       coeff_t lhs,  feonumm4n3_t* rhs);
void     feonumm4n3_div_rf_to(    coeff_t lhs,  feonumm4n3_t* rhs, feonumm4n3_t* res);

feonumm4n3_t feonumm4n3_div_fr(     feonumm4n3_t* lhs,    coeff_t rhs);
void     feonumm4n3_div_fr_to(  feonumm4n3_t* lhs,    coeff_t rhs, feonumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif