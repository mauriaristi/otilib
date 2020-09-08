#ifndef OTI_ONUMM6N2_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM6N2_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n2_t feonumm6n2_neg(   feonumm6n2_t* num);
void     feonumm6n2_neg_to(feonumm6n2_t* num, feonumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n2_t feonumm6n2_sum_ff(   feonumm6n2_t* lhs, feonumm6n2_t* rhs);
void     feonumm6n2_sum_ff_to(feonumm6n2_t* lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_sum_of(   onumm6n2_t* lhs, feonumm6n2_t* rhs);
void     feonumm6n2_sum_of_to(onumm6n2_t* lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_sum_rf(   coeff_t lhs, feonumm6n2_t* rhs);
void     feonumm6n2_sum_rf_to(coeff_t lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n2_t feonumm6n2_sub_ff(     feonumm6n2_t* lhs,  feonumm6n2_t* rhs);
void     feonumm6n2_sub_ff_to(  feonumm6n2_t* lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_sub_of(    onumm6n2_t* lhs,  feonumm6n2_t* rhs);
void     feonumm6n2_sub_of_to( onumm6n2_t* lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_sub_fo(     feonumm6n2_t* lhs, onumm6n2_t* rhs);
void     feonumm6n2_sub_fo_to(  feonumm6n2_t* lhs, onumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_sub_rf(       coeff_t lhs,  feonumm6n2_t* rhs);
void     feonumm6n2_sub_rf_to(    coeff_t lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_sub_fr(     feonumm6n2_t* lhs,    coeff_t rhs);
void     feonumm6n2_sub_fr_to(  feonumm6n2_t* lhs,    coeff_t rhs, feonumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n2_t feonumm6n2_mul_ff(   feonumm6n2_t* lhs, feonumm6n2_t* rhs);
void     feonumm6n2_mul_ff_to(feonumm6n2_t* lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_mul_of(   onumm6n2_t* lhs, feonumm6n2_t* rhs);
void     feonumm6n2_mul_of_to(onumm6n2_t* lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_mul_rf(   coeff_t lhs, feonumm6n2_t* rhs);
void     feonumm6n2_mul_rf_to(coeff_t lhs, feonumm6n2_t* rhs, feonumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n2_t feonumm6n2_div_ff(     feonumm6n2_t* lhs,  feonumm6n2_t* rhs);
void     feonumm6n2_div_ff_to(  feonumm6n2_t* lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_div_of(    onumm6n2_t* lhs,  feonumm6n2_t* rhs);
void     feonumm6n2_div_of_to( onumm6n2_t* lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_div_fo(     feonumm6n2_t* lhs, onumm6n2_t* rhs);
void     feonumm6n2_div_fo_to(  feonumm6n2_t* lhs, onumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_div_rf(       coeff_t lhs,  feonumm6n2_t* rhs);
void     feonumm6n2_div_rf_to(    coeff_t lhs,  feonumm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feonumm6n2_div_fr(     feonumm6n2_t* lhs,    coeff_t rhs);
void     feonumm6n2_div_fr_to(  feonumm6n2_t* lhs,    coeff_t rhs, feonumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif