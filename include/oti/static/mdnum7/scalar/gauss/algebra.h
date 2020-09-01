#ifndef OTI_MDNUM7_SCALAR_GAUSS_ALGEBRA_H
#define OTI_MDNUM7_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum7_t femdnum7_neg(   femdnum7_t* num);
void     femdnum7_neg_to(femdnum7_t* num, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum7_t femdnum7_sum_ff(   femdnum7_t* lhs, femdnum7_t* rhs);
void     femdnum7_sum_ff_to(femdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_sum_of(   mdnum7_t* lhs, femdnum7_t* rhs);
void     femdnum7_sum_of_to(mdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_sum_rf(   coeff_t lhs, femdnum7_t* rhs);
void     femdnum7_sum_rf_to(coeff_t lhs, femdnum7_t* rhs, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum7_t femdnum7_sub_ff(     femdnum7_t* lhs,  femdnum7_t* rhs);
void     femdnum7_sub_ff_to(  femdnum7_t* lhs,  femdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_sub_of(    mdnum7_t* lhs,  femdnum7_t* rhs);
void     femdnum7_sub_of_to( mdnum7_t* lhs,  femdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_sub_fo(     femdnum7_t* lhs, mdnum7_t* rhs);
void     femdnum7_sub_fo_to(  femdnum7_t* lhs, mdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_sub_rf(       coeff_t lhs,  femdnum7_t* rhs);
void     femdnum7_sub_rf_to(    coeff_t lhs,  femdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_sub_fr(     femdnum7_t* lhs,    coeff_t rhs);
void     femdnum7_sub_fr_to(  femdnum7_t* lhs,    coeff_t rhs, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum7_t femdnum7_mul_ff(   femdnum7_t* lhs, femdnum7_t* rhs);
void     femdnum7_mul_ff_to(femdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_mul_of(   mdnum7_t* lhs, femdnum7_t* rhs);
void     femdnum7_mul_of_to(mdnum7_t* lhs, femdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_mul_rf(   coeff_t lhs, femdnum7_t* rhs);
void     femdnum7_mul_rf_to(coeff_t lhs, femdnum7_t* rhs, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum7_t femdnum7_div_ff(     femdnum7_t* lhs,  femdnum7_t* rhs);
void     femdnum7_div_ff_to(  femdnum7_t* lhs,  femdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_div_of(    mdnum7_t* lhs,  femdnum7_t* rhs);
void     femdnum7_div_of_to( mdnum7_t* lhs,  femdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_div_fo(     femdnum7_t* lhs, mdnum7_t* rhs);
void     femdnum7_div_fo_to(  femdnum7_t* lhs, mdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_div_rf(       coeff_t lhs,  femdnum7_t* rhs);
void     femdnum7_div_rf_to(    coeff_t lhs,  femdnum7_t* rhs, femdnum7_t* res);

femdnum7_t femdnum7_div_fr(     femdnum7_t* lhs,    coeff_t rhs);
void     femdnum7_div_fr_to(  femdnum7_t* lhs,    coeff_t rhs, femdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif