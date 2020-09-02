#ifndef OTI_MDNUM1_SCALAR_GAUSS_ALGEBRA_H
#define OTI_MDNUM1_SCALAR_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum1_t femdnum1_neg(   femdnum1_t* num);
void     femdnum1_neg_to(femdnum1_t* num, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum1_t femdnum1_sum_ff(   femdnum1_t* lhs, femdnum1_t* rhs);
void     femdnum1_sum_ff_to(femdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_sum_of(   mdnum1_t* lhs, femdnum1_t* rhs);
void     femdnum1_sum_of_to(mdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_sum_rf(   coeff_t lhs, femdnum1_t* rhs);
void     femdnum1_sum_rf_to(coeff_t lhs, femdnum1_t* rhs, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum1_t femdnum1_sub_ff(     femdnum1_t* lhs,  femdnum1_t* rhs);
void     femdnum1_sub_ff_to(  femdnum1_t* lhs,  femdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_sub_of(    mdnum1_t* lhs,  femdnum1_t* rhs);
void     femdnum1_sub_of_to( mdnum1_t* lhs,  femdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_sub_fo(     femdnum1_t* lhs, mdnum1_t* rhs);
void     femdnum1_sub_fo_to(  femdnum1_t* lhs, mdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_sub_rf(       coeff_t lhs,  femdnum1_t* rhs);
void     femdnum1_sub_rf_to(    coeff_t lhs,  femdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_sub_fr(     femdnum1_t* lhs,    coeff_t rhs);
void     femdnum1_sub_fr_to(  femdnum1_t* lhs,    coeff_t rhs, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum1_t femdnum1_mul_ff(   femdnum1_t* lhs, femdnum1_t* rhs);
void     femdnum1_mul_ff_to(femdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_mul_of(   mdnum1_t* lhs, femdnum1_t* rhs);
void     femdnum1_mul_of_to(mdnum1_t* lhs, femdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_mul_rf(   coeff_t lhs, femdnum1_t* rhs);
void     femdnum1_mul_rf_to(coeff_t lhs, femdnum1_t* rhs, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum1_t femdnum1_div_ff(     femdnum1_t* lhs,  femdnum1_t* rhs);
void     femdnum1_div_ff_to(  femdnum1_t* lhs,  femdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_div_of(    mdnum1_t* lhs,  femdnum1_t* rhs);
void     femdnum1_div_of_to( mdnum1_t* lhs,  femdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_div_fo(     femdnum1_t* lhs, mdnum1_t* rhs);
void     femdnum1_div_fo_to(  femdnum1_t* lhs, mdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_div_rf(       coeff_t lhs,  femdnum1_t* rhs);
void     femdnum1_div_rf_to(    coeff_t lhs,  femdnum1_t* rhs, femdnum1_t* res);

femdnum1_t femdnum1_div_fr(     femdnum1_t* lhs,    coeff_t rhs);
void     femdnum1_div_fr_to(  femdnum1_t* lhs,    coeff_t rhs, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif