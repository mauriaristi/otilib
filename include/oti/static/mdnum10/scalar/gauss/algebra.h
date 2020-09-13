#ifndef OTI_MDNUM10_SCALAR_GAUSS_ALGEBRA_H
#define OTI_MDNUM10_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum10_t femdnum10_neg(   femdnum10_t* num);
void     femdnum10_neg_to(femdnum10_t* num, femdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum10_t femdnum10_sum_ff(   femdnum10_t* lhs, femdnum10_t* rhs);
void     femdnum10_sum_ff_to(femdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_sum_of(   mdnum10_t* lhs, femdnum10_t* rhs);
void     femdnum10_sum_of_to(mdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_sum_rf(   coeff_t lhs, femdnum10_t* rhs);
void     femdnum10_sum_rf_to(coeff_t lhs, femdnum10_t* rhs, femdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum10_t femdnum10_sub_ff(     femdnum10_t* lhs,  femdnum10_t* rhs);
void     femdnum10_sub_ff_to(  femdnum10_t* lhs,  femdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_sub_of(    mdnum10_t* lhs,  femdnum10_t* rhs);
void     femdnum10_sub_of_to( mdnum10_t* lhs,  femdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_sub_fo(     femdnum10_t* lhs, mdnum10_t* rhs);
void     femdnum10_sub_fo_to(  femdnum10_t* lhs, mdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_sub_rf(       coeff_t lhs,  femdnum10_t* rhs);
void     femdnum10_sub_rf_to(    coeff_t lhs,  femdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_sub_fr(     femdnum10_t* lhs,    coeff_t rhs);
void     femdnum10_sub_fr_to(  femdnum10_t* lhs,    coeff_t rhs, femdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum10_t femdnum10_mul_ff(   femdnum10_t* lhs, femdnum10_t* rhs);
void     femdnum10_mul_ff_to(femdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_mul_of(   mdnum10_t* lhs, femdnum10_t* rhs);
void     femdnum10_mul_of_to(mdnum10_t* lhs, femdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_mul_rf(   coeff_t lhs, femdnum10_t* rhs);
void     femdnum10_mul_rf_to(coeff_t lhs, femdnum10_t* rhs, femdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum10_t femdnum10_div_ff(     femdnum10_t* lhs,  femdnum10_t* rhs);
void     femdnum10_div_ff_to(  femdnum10_t* lhs,  femdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_div_of(    mdnum10_t* lhs,  femdnum10_t* rhs);
void     femdnum10_div_of_to( mdnum10_t* lhs,  femdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_div_fo(     femdnum10_t* lhs, mdnum10_t* rhs);
void     femdnum10_div_fo_to(  femdnum10_t* lhs, mdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_div_rf(       coeff_t lhs,  femdnum10_t* rhs);
void     femdnum10_div_rf_to(    coeff_t lhs,  femdnum10_t* rhs, femdnum10_t* res);

femdnum10_t femdnum10_div_fr(     femdnum10_t* lhs,    coeff_t rhs);
void     femdnum10_div_fr_to(  femdnum10_t* lhs,    coeff_t rhs, femdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif