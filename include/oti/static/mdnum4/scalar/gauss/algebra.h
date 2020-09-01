#ifndef OTI_MDNUM4_SCALAR_GAUSS_ALGEBRA_H
#define OTI_MDNUM4_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum4_t femdnum4_neg(   femdnum4_t* num);
void     femdnum4_neg_to(femdnum4_t* num, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum4_t femdnum4_sum_ff(   femdnum4_t* lhs, femdnum4_t* rhs);
void     femdnum4_sum_ff_to(femdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_sum_of(   mdnum4_t* lhs, femdnum4_t* rhs);
void     femdnum4_sum_of_to(mdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_sum_rf(   coeff_t lhs, femdnum4_t* rhs);
void     femdnum4_sum_rf_to(coeff_t lhs, femdnum4_t* rhs, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum4_t femdnum4_sub_ff(     femdnum4_t* lhs,  femdnum4_t* rhs);
void     femdnum4_sub_ff_to(  femdnum4_t* lhs,  femdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_sub_of(    mdnum4_t* lhs,  femdnum4_t* rhs);
void     femdnum4_sub_of_to( mdnum4_t* lhs,  femdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_sub_fo(     femdnum4_t* lhs, mdnum4_t* rhs);
void     femdnum4_sub_fo_to(  femdnum4_t* lhs, mdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_sub_rf(       coeff_t lhs,  femdnum4_t* rhs);
void     femdnum4_sub_rf_to(    coeff_t lhs,  femdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_sub_fr(     femdnum4_t* lhs,    coeff_t rhs);
void     femdnum4_sub_fr_to(  femdnum4_t* lhs,    coeff_t rhs, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum4_t femdnum4_mul_ff(   femdnum4_t* lhs, femdnum4_t* rhs);
void     femdnum4_mul_ff_to(femdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_mul_of(   mdnum4_t* lhs, femdnum4_t* rhs);
void     femdnum4_mul_of_to(mdnum4_t* lhs, femdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_mul_rf(   coeff_t lhs, femdnum4_t* rhs);
void     femdnum4_mul_rf_to(coeff_t lhs, femdnum4_t* rhs, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum4_t femdnum4_div_ff(     femdnum4_t* lhs,  femdnum4_t* rhs);
void     femdnum4_div_ff_to(  femdnum4_t* lhs,  femdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_div_of(    mdnum4_t* lhs,  femdnum4_t* rhs);
void     femdnum4_div_of_to( mdnum4_t* lhs,  femdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_div_fo(     femdnum4_t* lhs, mdnum4_t* rhs);
void     femdnum4_div_fo_to(  femdnum4_t* lhs, mdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_div_rf(       coeff_t lhs,  femdnum4_t* rhs);
void     femdnum4_div_rf_to(    coeff_t lhs,  femdnum4_t* rhs, femdnum4_t* res);

femdnum4_t femdnum4_div_fr(     femdnum4_t* lhs,    coeff_t rhs);
void     femdnum4_div_fr_to(  femdnum4_t* lhs,    coeff_t rhs, femdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif