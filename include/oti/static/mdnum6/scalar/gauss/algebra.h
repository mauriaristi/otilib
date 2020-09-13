#ifndef OTI_MDNUM6_SCALAR_GAUSS_ALGEBRA_H
#define OTI_MDNUM6_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum6_t femdnum6_neg(   femdnum6_t* num);
void     femdnum6_neg_to(femdnum6_t* num, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum6_t femdnum6_sum_ff(   femdnum6_t* lhs, femdnum6_t* rhs);
void     femdnum6_sum_ff_to(femdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_sum_of(   mdnum6_t* lhs, femdnum6_t* rhs);
void     femdnum6_sum_of_to(mdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_sum_rf(   coeff_t lhs, femdnum6_t* rhs);
void     femdnum6_sum_rf_to(coeff_t lhs, femdnum6_t* rhs, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum6_t femdnum6_sub_ff(     femdnum6_t* lhs,  femdnum6_t* rhs);
void     femdnum6_sub_ff_to(  femdnum6_t* lhs,  femdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_sub_of(    mdnum6_t* lhs,  femdnum6_t* rhs);
void     femdnum6_sub_of_to( mdnum6_t* lhs,  femdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_sub_fo(     femdnum6_t* lhs, mdnum6_t* rhs);
void     femdnum6_sub_fo_to(  femdnum6_t* lhs, mdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_sub_rf(       coeff_t lhs,  femdnum6_t* rhs);
void     femdnum6_sub_rf_to(    coeff_t lhs,  femdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_sub_fr(     femdnum6_t* lhs,    coeff_t rhs);
void     femdnum6_sub_fr_to(  femdnum6_t* lhs,    coeff_t rhs, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum6_t femdnum6_mul_ff(   femdnum6_t* lhs, femdnum6_t* rhs);
void     femdnum6_mul_ff_to(femdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_mul_of(   mdnum6_t* lhs, femdnum6_t* rhs);
void     femdnum6_mul_of_to(mdnum6_t* lhs, femdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_mul_rf(   coeff_t lhs, femdnum6_t* rhs);
void     femdnum6_mul_rf_to(coeff_t lhs, femdnum6_t* rhs, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum6_t femdnum6_div_ff(     femdnum6_t* lhs,  femdnum6_t* rhs);
void     femdnum6_div_ff_to(  femdnum6_t* lhs,  femdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_div_of(    mdnum6_t* lhs,  femdnum6_t* rhs);
void     femdnum6_div_of_to( mdnum6_t* lhs,  femdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_div_fo(     femdnum6_t* lhs, mdnum6_t* rhs);
void     femdnum6_div_fo_to(  femdnum6_t* lhs, mdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_div_rf(       coeff_t lhs,  femdnum6_t* rhs);
void     femdnum6_div_rf_to(    coeff_t lhs,  femdnum6_t* rhs, femdnum6_t* res);

femdnum6_t femdnum6_div_fr(     femdnum6_t* lhs,    coeff_t rhs);
void     femdnum6_div_fr_to(  femdnum6_t* lhs,    coeff_t rhs, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif