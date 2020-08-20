#ifndef OTI_MDNUM5_SCALAR_GAUSS_ALGEBRA_H
#define OTI_MDNUM5_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum5_t femdnum5_neg(   femdnum5_t* num);
void     femdnum5_neg_to(femdnum5_t* num, femdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum5_t femdnum5_sum_ff(   femdnum5_t* lhs, femdnum5_t* rhs);
void     femdnum5_sum_ff_to(femdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_sum_of(   mdnum5_t* lhs, femdnum5_t* rhs);
void     femdnum5_sum_of_to(mdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_sum_rf(   coeff_t lhs, femdnum5_t* rhs);
void     femdnum5_sum_rf_to(coeff_t lhs, femdnum5_t* rhs, femdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum5_t femdnum5_sub_ff(     femdnum5_t* lhs,  femdnum5_t* rhs);
void     femdnum5_sub_ff_to(  femdnum5_t* lhs,  femdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_sub_of(    mdnum5_t* lhs,  femdnum5_t* rhs);
void     femdnum5_sub_of_to( mdnum5_t* lhs,  femdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_sub_fo(     femdnum5_t* lhs, mdnum5_t* rhs);
void     femdnum5_sub_fo_to(  femdnum5_t* lhs, mdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_sub_rf(       coeff_t lhs,  femdnum5_t* rhs);
void     femdnum5_sub_rf_to(    coeff_t lhs,  femdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_sub_fr(     femdnum5_t* lhs,    coeff_t rhs);
void     femdnum5_sub_fr_to(  femdnum5_t* lhs,    coeff_t rhs, femdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum5_t femdnum5_mul_ff(   femdnum5_t* lhs, femdnum5_t* rhs);
void     femdnum5_mul_ff_to(femdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_mul_of(   mdnum5_t* lhs, femdnum5_t* rhs);
void     femdnum5_mul_of_to(mdnum5_t* lhs, femdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_mul_rf(   coeff_t lhs, femdnum5_t* rhs);
void     femdnum5_mul_rf_to(coeff_t lhs, femdnum5_t* rhs, femdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum5_t femdnum5_div_ff(     femdnum5_t* lhs,  femdnum5_t* rhs);
void     femdnum5_div_ff_to(  femdnum5_t* lhs,  femdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_div_of(    mdnum5_t* lhs,  femdnum5_t* rhs);
void     femdnum5_div_of_to( mdnum5_t* lhs,  femdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_div_fo(     femdnum5_t* lhs, mdnum5_t* rhs);
void     femdnum5_div_fo_to(  femdnum5_t* lhs, mdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_div_rf(       coeff_t lhs,  femdnum5_t* rhs);
void     femdnum5_div_rf_to(    coeff_t lhs,  femdnum5_t* rhs, femdnum5_t* res);

femdnum5_t femdnum5_div_fr(     femdnum5_t* lhs,    coeff_t rhs);
void     femdnum5_div_fr_to(  femdnum5_t* lhs,    coeff_t rhs, femdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif