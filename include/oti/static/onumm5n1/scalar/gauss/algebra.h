#ifndef OTI_ONUMM5N1_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM5N1_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n1_t feonumm5n1_neg(   feonumm5n1_t* num);
void     feonumm5n1_neg_to(feonumm5n1_t* num, feonumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n1_t feonumm5n1_sum_ff(   feonumm5n1_t* lhs, feonumm5n1_t* rhs);
void     feonumm5n1_sum_ff_to(feonumm5n1_t* lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_sum_of(   onumm5n1_t* lhs, feonumm5n1_t* rhs);
void     feonumm5n1_sum_of_to(onumm5n1_t* lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_sum_rf(   coeff_t lhs, feonumm5n1_t* rhs);
void     feonumm5n1_sum_rf_to(coeff_t lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n1_t feonumm5n1_sub_ff(     feonumm5n1_t* lhs,  feonumm5n1_t* rhs);
void     feonumm5n1_sub_ff_to(  feonumm5n1_t* lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_sub_of(    onumm5n1_t* lhs,  feonumm5n1_t* rhs);
void     feonumm5n1_sub_of_to( onumm5n1_t* lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_sub_fo(     feonumm5n1_t* lhs, onumm5n1_t* rhs);
void     feonumm5n1_sub_fo_to(  feonumm5n1_t* lhs, onumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_sub_rf(       coeff_t lhs,  feonumm5n1_t* rhs);
void     feonumm5n1_sub_rf_to(    coeff_t lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_sub_fr(     feonumm5n1_t* lhs,    coeff_t rhs);
void     feonumm5n1_sub_fr_to(  feonumm5n1_t* lhs,    coeff_t rhs, feonumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n1_t feonumm5n1_mul_ff(   feonumm5n1_t* lhs, feonumm5n1_t* rhs);
void     feonumm5n1_mul_ff_to(feonumm5n1_t* lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_mul_of(   onumm5n1_t* lhs, feonumm5n1_t* rhs);
void     feonumm5n1_mul_of_to(onumm5n1_t* lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_mul_rf(   coeff_t lhs, feonumm5n1_t* rhs);
void     feonumm5n1_mul_rf_to(coeff_t lhs, feonumm5n1_t* rhs, feonumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n1_t feonumm5n1_div_ff(     feonumm5n1_t* lhs,  feonumm5n1_t* rhs);
void     feonumm5n1_div_ff_to(  feonumm5n1_t* lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_div_of(    onumm5n1_t* lhs,  feonumm5n1_t* rhs);
void     feonumm5n1_div_of_to( onumm5n1_t* lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_div_fo(     feonumm5n1_t* lhs, onumm5n1_t* rhs);
void     feonumm5n1_div_fo_to(  feonumm5n1_t* lhs, onumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_div_rf(       coeff_t lhs,  feonumm5n1_t* rhs);
void     feonumm5n1_div_rf_to(    coeff_t lhs,  feonumm5n1_t* rhs, feonumm5n1_t* res);

feonumm5n1_t feonumm5n1_div_fr(     feonumm5n1_t* lhs,    coeff_t rhs);
void     feonumm5n1_div_fr_to(  feonumm5n1_t* lhs,    coeff_t rhs, feonumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif