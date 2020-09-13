#ifndef OTI_MDNUM9_SCALAR_GAUSS_ALGEBRA_H
#define OTI_MDNUM9_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum9_t femdnum9_neg(   femdnum9_t* num);
void     femdnum9_neg_to(femdnum9_t* num, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum9_t femdnum9_sum_ff(   femdnum9_t* lhs, femdnum9_t* rhs);
void     femdnum9_sum_ff_to(femdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_sum_of(   mdnum9_t* lhs, femdnum9_t* rhs);
void     femdnum9_sum_of_to(mdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_sum_rf(   coeff_t lhs, femdnum9_t* rhs);
void     femdnum9_sum_rf_to(coeff_t lhs, femdnum9_t* rhs, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum9_t femdnum9_sub_ff(     femdnum9_t* lhs,  femdnum9_t* rhs);
void     femdnum9_sub_ff_to(  femdnum9_t* lhs,  femdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_sub_of(    mdnum9_t* lhs,  femdnum9_t* rhs);
void     femdnum9_sub_of_to( mdnum9_t* lhs,  femdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_sub_fo(     femdnum9_t* lhs, mdnum9_t* rhs);
void     femdnum9_sub_fo_to(  femdnum9_t* lhs, mdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_sub_rf(       coeff_t lhs,  femdnum9_t* rhs);
void     femdnum9_sub_rf_to(    coeff_t lhs,  femdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_sub_fr(     femdnum9_t* lhs,    coeff_t rhs);
void     femdnum9_sub_fr_to(  femdnum9_t* lhs,    coeff_t rhs, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum9_t femdnum9_mul_ff(   femdnum9_t* lhs, femdnum9_t* rhs);
void     femdnum9_mul_ff_to(femdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_mul_of(   mdnum9_t* lhs, femdnum9_t* rhs);
void     femdnum9_mul_of_to(mdnum9_t* lhs, femdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_mul_rf(   coeff_t lhs, femdnum9_t* rhs);
void     femdnum9_mul_rf_to(coeff_t lhs, femdnum9_t* rhs, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum9_t femdnum9_div_ff(     femdnum9_t* lhs,  femdnum9_t* rhs);
void     femdnum9_div_ff_to(  femdnum9_t* lhs,  femdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_div_of(    mdnum9_t* lhs,  femdnum9_t* rhs);
void     femdnum9_div_of_to( mdnum9_t* lhs,  femdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_div_fo(     femdnum9_t* lhs, mdnum9_t* rhs);
void     femdnum9_div_fo_to(  femdnum9_t* lhs, mdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_div_rf(       coeff_t lhs,  femdnum9_t* rhs);
void     femdnum9_div_rf_to(    coeff_t lhs,  femdnum9_t* rhs, femdnum9_t* res);

femdnum9_t femdnum9_div_fr(     femdnum9_t* lhs,    coeff_t rhs);
void     femdnum9_div_fr_to(  femdnum9_t* lhs,    coeff_t rhs, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif