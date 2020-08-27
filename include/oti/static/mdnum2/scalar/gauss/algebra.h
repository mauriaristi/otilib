#ifndef OTI_MDNUM2_SCALAR_GAUSS_ALGEBRA_H
#define OTI_MDNUM2_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum2_t femdnum2_neg(   femdnum2_t* num);
void     femdnum2_neg_to(femdnum2_t* num, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum2_t femdnum2_sum_ff(   femdnum2_t* lhs, femdnum2_t* rhs);
void     femdnum2_sum_ff_to(femdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_sum_of(   mdnum2_t* lhs, femdnum2_t* rhs);
void     femdnum2_sum_of_to(mdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_sum_rf(   coeff_t lhs, femdnum2_t* rhs);
void     femdnum2_sum_rf_to(coeff_t lhs, femdnum2_t* rhs, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum2_t femdnum2_sub_ff(     femdnum2_t* lhs,  femdnum2_t* rhs);
void     femdnum2_sub_ff_to(  femdnum2_t* lhs,  femdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_sub_of(    mdnum2_t* lhs,  femdnum2_t* rhs);
void     femdnum2_sub_of_to( mdnum2_t* lhs,  femdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_sub_fo(     femdnum2_t* lhs, mdnum2_t* rhs);
void     femdnum2_sub_fo_to(  femdnum2_t* lhs, mdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_sub_rf(       coeff_t lhs,  femdnum2_t* rhs);
void     femdnum2_sub_rf_to(    coeff_t lhs,  femdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_sub_fr(     femdnum2_t* lhs,    coeff_t rhs);
void     femdnum2_sub_fr_to(  femdnum2_t* lhs,    coeff_t rhs, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum2_t femdnum2_mul_ff(   femdnum2_t* lhs, femdnum2_t* rhs);
void     femdnum2_mul_ff_to(femdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_mul_of(   mdnum2_t* lhs, femdnum2_t* rhs);
void     femdnum2_mul_of_to(mdnum2_t* lhs, femdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_mul_rf(   coeff_t lhs, femdnum2_t* rhs);
void     femdnum2_mul_rf_to(coeff_t lhs, femdnum2_t* rhs, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum2_t femdnum2_div_ff(     femdnum2_t* lhs,  femdnum2_t* rhs);
void     femdnum2_div_ff_to(  femdnum2_t* lhs,  femdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_div_of(    mdnum2_t* lhs,  femdnum2_t* rhs);
void     femdnum2_div_of_to( mdnum2_t* lhs,  femdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_div_fo(     femdnum2_t* lhs, mdnum2_t* rhs);
void     femdnum2_div_fo_to(  femdnum2_t* lhs, mdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_div_rf(       coeff_t lhs,  femdnum2_t* rhs);
void     femdnum2_div_rf_to(    coeff_t lhs,  femdnum2_t* rhs, femdnum2_t* res);

femdnum2_t femdnum2_div_fr(     femdnum2_t* lhs,    coeff_t rhs);
void     femdnum2_div_fr_to(  femdnum2_t* lhs,    coeff_t rhs, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif