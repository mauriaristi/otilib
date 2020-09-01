#ifndef OTI_MDNUM3_SCALAR_GAUSS_ALGEBRA_H
#define OTI_MDNUM3_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum3_t femdnum3_neg(   femdnum3_t* num);
void     femdnum3_neg_to(femdnum3_t* num, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum3_t femdnum3_sum_ff(   femdnum3_t* lhs, femdnum3_t* rhs);
void     femdnum3_sum_ff_to(femdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_sum_of(   mdnum3_t* lhs, femdnum3_t* rhs);
void     femdnum3_sum_of_to(mdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_sum_rf(   coeff_t lhs, femdnum3_t* rhs);
void     femdnum3_sum_rf_to(coeff_t lhs, femdnum3_t* rhs, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum3_t femdnum3_sub_ff(     femdnum3_t* lhs,  femdnum3_t* rhs);
void     femdnum3_sub_ff_to(  femdnum3_t* lhs,  femdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_sub_of(    mdnum3_t* lhs,  femdnum3_t* rhs);
void     femdnum3_sub_of_to( mdnum3_t* lhs,  femdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_sub_fo(     femdnum3_t* lhs, mdnum3_t* rhs);
void     femdnum3_sub_fo_to(  femdnum3_t* lhs, mdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_sub_rf(       coeff_t lhs,  femdnum3_t* rhs);
void     femdnum3_sub_rf_to(    coeff_t lhs,  femdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_sub_fr(     femdnum3_t* lhs,    coeff_t rhs);
void     femdnum3_sub_fr_to(  femdnum3_t* lhs,    coeff_t rhs, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum3_t femdnum3_mul_ff(   femdnum3_t* lhs, femdnum3_t* rhs);
void     femdnum3_mul_ff_to(femdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_mul_of(   mdnum3_t* lhs, femdnum3_t* rhs);
void     femdnum3_mul_of_to(mdnum3_t* lhs, femdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_mul_rf(   coeff_t lhs, femdnum3_t* rhs);
void     femdnum3_mul_rf_to(coeff_t lhs, femdnum3_t* rhs, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum3_t femdnum3_div_ff(     femdnum3_t* lhs,  femdnum3_t* rhs);
void     femdnum3_div_ff_to(  femdnum3_t* lhs,  femdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_div_of(    mdnum3_t* lhs,  femdnum3_t* rhs);
void     femdnum3_div_of_to( mdnum3_t* lhs,  femdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_div_fo(     femdnum3_t* lhs, mdnum3_t* rhs);
void     femdnum3_div_fo_to(  femdnum3_t* lhs, mdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_div_rf(       coeff_t lhs,  femdnum3_t* rhs);
void     femdnum3_div_rf_to(    coeff_t lhs,  femdnum3_t* rhs, femdnum3_t* res);

femdnum3_t femdnum3_div_fr(     femdnum3_t* lhs,    coeff_t rhs);
void     femdnum3_div_fr_to(  femdnum3_t* lhs,    coeff_t rhs, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif