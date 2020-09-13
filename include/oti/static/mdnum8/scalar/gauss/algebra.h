#ifndef OTI_MDNUM8_SCALAR_GAUSS_ALGEBRA_H
#define OTI_MDNUM8_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum8_t femdnum8_neg(   femdnum8_t* num);
void     femdnum8_neg_to(femdnum8_t* num, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum8_t femdnum8_sum_ff(   femdnum8_t* lhs, femdnum8_t* rhs);
void     femdnum8_sum_ff_to(femdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_sum_of(   mdnum8_t* lhs, femdnum8_t* rhs);
void     femdnum8_sum_of_to(mdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_sum_rf(   coeff_t lhs, femdnum8_t* rhs);
void     femdnum8_sum_rf_to(coeff_t lhs, femdnum8_t* rhs, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum8_t femdnum8_sub_ff(     femdnum8_t* lhs,  femdnum8_t* rhs);
void     femdnum8_sub_ff_to(  femdnum8_t* lhs,  femdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_sub_of(    mdnum8_t* lhs,  femdnum8_t* rhs);
void     femdnum8_sub_of_to( mdnum8_t* lhs,  femdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_sub_fo(     femdnum8_t* lhs, mdnum8_t* rhs);
void     femdnum8_sub_fo_to(  femdnum8_t* lhs, mdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_sub_rf(       coeff_t lhs,  femdnum8_t* rhs);
void     femdnum8_sub_rf_to(    coeff_t lhs,  femdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_sub_fr(     femdnum8_t* lhs,    coeff_t rhs);
void     femdnum8_sub_fr_to(  femdnum8_t* lhs,    coeff_t rhs, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum8_t femdnum8_mul_ff(   femdnum8_t* lhs, femdnum8_t* rhs);
void     femdnum8_mul_ff_to(femdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_mul_of(   mdnum8_t* lhs, femdnum8_t* rhs);
void     femdnum8_mul_of_to(mdnum8_t* lhs, femdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_mul_rf(   coeff_t lhs, femdnum8_t* rhs);
void     femdnum8_mul_rf_to(coeff_t lhs, femdnum8_t* rhs, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum8_t femdnum8_div_ff(     femdnum8_t* lhs,  femdnum8_t* rhs);
void     femdnum8_div_ff_to(  femdnum8_t* lhs,  femdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_div_of(    mdnum8_t* lhs,  femdnum8_t* rhs);
void     femdnum8_div_of_to( mdnum8_t* lhs,  femdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_div_fo(     femdnum8_t* lhs, mdnum8_t* rhs);
void     femdnum8_div_fo_to(  femdnum8_t* lhs, mdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_div_rf(       coeff_t lhs,  femdnum8_t* rhs);
void     femdnum8_div_rf_to(    coeff_t lhs,  femdnum8_t* rhs, femdnum8_t* res);

femdnum8_t femdnum8_div_fr(     femdnum8_t* lhs,    coeff_t rhs);
void     femdnum8_div_fr_to(  femdnum8_t* lhs,    coeff_t rhs, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif