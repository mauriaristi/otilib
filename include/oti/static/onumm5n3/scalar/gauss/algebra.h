#ifndef OTI_ONUMM5N3_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM5N3_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n3_t feonumm5n3_neg(   feonumm5n3_t* num);
void     feonumm5n3_neg_to(feonumm5n3_t* num, feonumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n3_t feonumm5n3_sum_ff(   feonumm5n3_t* lhs, feonumm5n3_t* rhs);
void     feonumm5n3_sum_ff_to(feonumm5n3_t* lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_sum_of(   onumm5n3_t* lhs, feonumm5n3_t* rhs);
void     feonumm5n3_sum_of_to(onumm5n3_t* lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_sum_rf(   coeff_t lhs, feonumm5n3_t* rhs);
void     feonumm5n3_sum_rf_to(coeff_t lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n3_t feonumm5n3_sub_ff(     feonumm5n3_t* lhs,  feonumm5n3_t* rhs);
void     feonumm5n3_sub_ff_to(  feonumm5n3_t* lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_sub_of(    onumm5n3_t* lhs,  feonumm5n3_t* rhs);
void     feonumm5n3_sub_of_to( onumm5n3_t* lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_sub_fo(     feonumm5n3_t* lhs, onumm5n3_t* rhs);
void     feonumm5n3_sub_fo_to(  feonumm5n3_t* lhs, onumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_sub_rf(       coeff_t lhs,  feonumm5n3_t* rhs);
void     feonumm5n3_sub_rf_to(    coeff_t lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_sub_fr(     feonumm5n3_t* lhs,    coeff_t rhs);
void     feonumm5n3_sub_fr_to(  feonumm5n3_t* lhs,    coeff_t rhs, feonumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n3_t feonumm5n3_mul_ff(   feonumm5n3_t* lhs, feonumm5n3_t* rhs);
void     feonumm5n3_mul_ff_to(feonumm5n3_t* lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_mul_of(   onumm5n3_t* lhs, feonumm5n3_t* rhs);
void     feonumm5n3_mul_of_to(onumm5n3_t* lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_mul_rf(   coeff_t lhs, feonumm5n3_t* rhs);
void     feonumm5n3_mul_rf_to(coeff_t lhs, feonumm5n3_t* rhs, feonumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n3_t feonumm5n3_div_ff(     feonumm5n3_t* lhs,  feonumm5n3_t* rhs);
void     feonumm5n3_div_ff_to(  feonumm5n3_t* lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_div_of(    onumm5n3_t* lhs,  feonumm5n3_t* rhs);
void     feonumm5n3_div_of_to( onumm5n3_t* lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_div_fo(     feonumm5n3_t* lhs, onumm5n3_t* rhs);
void     feonumm5n3_div_fo_to(  feonumm5n3_t* lhs, onumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_div_rf(       coeff_t lhs,  feonumm5n3_t* rhs);
void     feonumm5n3_div_rf_to(    coeff_t lhs,  feonumm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feonumm5n3_div_fr(     feonumm5n3_t* lhs,    coeff_t rhs);
void     feonumm5n3_div_fr_to(  feonumm5n3_t* lhs,    coeff_t rhs, feonumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif