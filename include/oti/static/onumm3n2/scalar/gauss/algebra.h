#ifndef OTI_ONUMM3N2_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM3N2_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n2_t feonumm3n2_neg(   feonumm3n2_t* num);
void     feonumm3n2_neg_to(feonumm3n2_t* num, feonumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n2_t feonumm3n2_sum_ff(   feonumm3n2_t* lhs, feonumm3n2_t* rhs);
void     feonumm3n2_sum_ff_to(feonumm3n2_t* lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_sum_of(   onumm3n2_t* lhs, feonumm3n2_t* rhs);
void     feonumm3n2_sum_of_to(onumm3n2_t* lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_sum_rf(   coeff_t lhs, feonumm3n2_t* rhs);
void     feonumm3n2_sum_rf_to(coeff_t lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n2_t feonumm3n2_sub_ff(     feonumm3n2_t* lhs,  feonumm3n2_t* rhs);
void     feonumm3n2_sub_ff_to(  feonumm3n2_t* lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_sub_of(    onumm3n2_t* lhs,  feonumm3n2_t* rhs);
void     feonumm3n2_sub_of_to( onumm3n2_t* lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_sub_fo(     feonumm3n2_t* lhs, onumm3n2_t* rhs);
void     feonumm3n2_sub_fo_to(  feonumm3n2_t* lhs, onumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_sub_rf(       coeff_t lhs,  feonumm3n2_t* rhs);
void     feonumm3n2_sub_rf_to(    coeff_t lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_sub_fr(     feonumm3n2_t* lhs,    coeff_t rhs);
void     feonumm3n2_sub_fr_to(  feonumm3n2_t* lhs,    coeff_t rhs, feonumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n2_t feonumm3n2_mul_ff(   feonumm3n2_t* lhs, feonumm3n2_t* rhs);
void     feonumm3n2_mul_ff_to(feonumm3n2_t* lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_mul_of(   onumm3n2_t* lhs, feonumm3n2_t* rhs);
void     feonumm3n2_mul_of_to(onumm3n2_t* lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_mul_rf(   coeff_t lhs, feonumm3n2_t* rhs);
void     feonumm3n2_mul_rf_to(coeff_t lhs, feonumm3n2_t* rhs, feonumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm3n2_t feonumm3n2_div_ff(     feonumm3n2_t* lhs,  feonumm3n2_t* rhs);
void     feonumm3n2_div_ff_to(  feonumm3n2_t* lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_div_of(    onumm3n2_t* lhs,  feonumm3n2_t* rhs);
void     feonumm3n2_div_of_to( onumm3n2_t* lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_div_fo(     feonumm3n2_t* lhs, onumm3n2_t* rhs);
void     feonumm3n2_div_fo_to(  feonumm3n2_t* lhs, onumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_div_rf(       coeff_t lhs,  feonumm3n2_t* rhs);
void     feonumm3n2_div_rf_to(    coeff_t lhs,  feonumm3n2_t* rhs, feonumm3n2_t* res);

feonumm3n2_t feonumm3n2_div_fr(     feonumm3n2_t* lhs,    coeff_t rhs);
void     feonumm3n2_div_fr_to(  feonumm3n2_t* lhs,    coeff_t rhs, feonumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif