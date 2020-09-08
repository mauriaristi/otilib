#ifndef OTI_ONUMM8N2_SCALAR_GAUSS_ALGEBRA_H
#define OTI_ONUMM8N2_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n2_t feonumm8n2_neg(   feonumm8n2_t* num);
void     feonumm8n2_neg_to(feonumm8n2_t* num, feonumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n2_t feonumm8n2_sum_ff(   feonumm8n2_t* lhs, feonumm8n2_t* rhs);
void     feonumm8n2_sum_ff_to(feonumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_sum_of(   onumm8n2_t* lhs, feonumm8n2_t* rhs);
void     feonumm8n2_sum_of_to(onumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_sum_rf(   coeff_t lhs, feonumm8n2_t* rhs);
void     feonumm8n2_sum_rf_to(coeff_t lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n2_t feonumm8n2_sub_ff(     feonumm8n2_t* lhs,  feonumm8n2_t* rhs);
void     feonumm8n2_sub_ff_to(  feonumm8n2_t* lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_sub_of(    onumm8n2_t* lhs,  feonumm8n2_t* rhs);
void     feonumm8n2_sub_of_to( onumm8n2_t* lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_sub_fo(     feonumm8n2_t* lhs, onumm8n2_t* rhs);
void     feonumm8n2_sub_fo_to(  feonumm8n2_t* lhs, onumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_sub_rf(       coeff_t lhs,  feonumm8n2_t* rhs);
void     feonumm8n2_sub_rf_to(    coeff_t lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_sub_fr(     feonumm8n2_t* lhs,    coeff_t rhs);
void     feonumm8n2_sub_fr_to(  feonumm8n2_t* lhs,    coeff_t rhs, feonumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n2_t feonumm8n2_mul_ff(   feonumm8n2_t* lhs, feonumm8n2_t* rhs);
void     feonumm8n2_mul_ff_to(feonumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_mul_of(   onumm8n2_t* lhs, feonumm8n2_t* rhs);
void     feonumm8n2_mul_of_to(onumm8n2_t* lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_mul_rf(   coeff_t lhs, feonumm8n2_t* rhs);
void     feonumm8n2_mul_rf_to(coeff_t lhs, feonumm8n2_t* rhs, feonumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n2_t feonumm8n2_div_ff(     feonumm8n2_t* lhs,  feonumm8n2_t* rhs);
void     feonumm8n2_div_ff_to(  feonumm8n2_t* lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_div_of(    onumm8n2_t* lhs,  feonumm8n2_t* rhs);
void     feonumm8n2_div_of_to( onumm8n2_t* lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_div_fo(     feonumm8n2_t* lhs, onumm8n2_t* rhs);
void     feonumm8n2_div_fo_to(  feonumm8n2_t* lhs, onumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_div_rf(       coeff_t lhs,  feonumm8n2_t* rhs);
void     feonumm8n2_div_rf_to(    coeff_t lhs,  feonumm8n2_t* rhs, feonumm8n2_t* res);

feonumm8n2_t feonumm8n2_div_fr(     feonumm8n2_t* lhs,    coeff_t rhs);
void     feonumm8n2_div_fr_to(  feonumm8n2_t* lhs,    coeff_t rhs, feonumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif