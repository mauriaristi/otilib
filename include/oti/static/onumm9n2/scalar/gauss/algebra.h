#ifndef OTI_ONUMM9N2_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM9N2_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n2_t feonumm9n2_neg(   feonumm9n2_t* num);
void     feonumm9n2_neg_to(feonumm9n2_t* num, feonumm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n2_t feonumm9n2_sum_ff(   feonumm9n2_t* lhs, feonumm9n2_t* rhs);
void     feonumm9n2_sum_ff_to(feonumm9n2_t* lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_sum_of(   onumm9n2_t* lhs, feonumm9n2_t* rhs);
void     feonumm9n2_sum_of_to(onumm9n2_t* lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_sum_rf(   coeff_t lhs, feonumm9n2_t* rhs);
void     feonumm9n2_sum_rf_to(coeff_t lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n2_t feonumm9n2_sub_ff(     feonumm9n2_t* lhs,  feonumm9n2_t* rhs);
void     feonumm9n2_sub_ff_to(  feonumm9n2_t* lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_sub_of(    onumm9n2_t* lhs,  feonumm9n2_t* rhs);
void     feonumm9n2_sub_of_to( onumm9n2_t* lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_sub_fo(     feonumm9n2_t* lhs, onumm9n2_t* rhs);
void     feonumm9n2_sub_fo_to(  feonumm9n2_t* lhs, onumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_sub_rf(       coeff_t lhs,  feonumm9n2_t* rhs);
void     feonumm9n2_sub_rf_to(    coeff_t lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_sub_fr(     feonumm9n2_t* lhs,    coeff_t rhs);
void     feonumm9n2_sub_fr_to(  feonumm9n2_t* lhs,    coeff_t rhs, feonumm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n2_t feonumm9n2_mul_ff(   feonumm9n2_t* lhs, feonumm9n2_t* rhs);
void     feonumm9n2_mul_ff_to(feonumm9n2_t* lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_mul_of(   onumm9n2_t* lhs, feonumm9n2_t* rhs);
void     feonumm9n2_mul_of_to(onumm9n2_t* lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_mul_rf(   coeff_t lhs, feonumm9n2_t* rhs);
void     feonumm9n2_mul_rf_to(coeff_t lhs, feonumm9n2_t* rhs, feonumm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm9n2_t feonumm9n2_div_ff(     feonumm9n2_t* lhs,  feonumm9n2_t* rhs);
void     feonumm9n2_div_ff_to(  feonumm9n2_t* lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_div_of(    onumm9n2_t* lhs,  feonumm9n2_t* rhs);
void     feonumm9n2_div_of_to( onumm9n2_t* lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_div_fo(     feonumm9n2_t* lhs, onumm9n2_t* rhs);
void     feonumm9n2_div_fo_to(  feonumm9n2_t* lhs, onumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_div_rf(       coeff_t lhs,  feonumm9n2_t* rhs);
void     feonumm9n2_div_rf_to(    coeff_t lhs,  feonumm9n2_t* rhs, feonumm9n2_t* res);

feonumm9n2_t feonumm9n2_div_fr(     feonumm9n2_t* lhs,    coeff_t rhs);
void     feonumm9n2_div_fr_to(  feonumm9n2_t* lhs,    coeff_t rhs, feonumm9n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif