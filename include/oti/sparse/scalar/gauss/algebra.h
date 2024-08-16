#ifndef OTI_SPARSE_SCALAR_GAUSS_ALGEBRA_H
#define OTI_SPARSE_SCALAR_GAUSS_ALGEBRA_H






/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fesoti_t fesoti_neg(   fesoti_t* num,                dhelpl_t dhl);
void     fesoti_neg_to(fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar abs.

res =  abs( num )

@param[in] num Number to negate.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fesoti_t fesoti_abs(   fesoti_t* num,                dhelpl_t dhl);
void     fesoti_abs_to(fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fesoti_t fesoti_sum_ff(   fesoti_t* lhs, fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_sum_ff_to(fesoti_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_sum_of(   sotinum_t* lhs, fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_sum_of_to(sotinum_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_sum_rf(   coeff_t lhs, fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_sum_rf_to(coeff_t lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fesoti_t fesoti_sub_ff(     fesoti_t* lhs,  fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_sub_ff_to(  fesoti_t* lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_sub_of(    sotinum_t* lhs,  fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_sub_of_to( sotinum_t* lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_sub_fo(     fesoti_t* lhs, sotinum_t* rhs,                dhelpl_t dhl);
void     fesoti_sub_fo_to(  fesoti_t* lhs, sotinum_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_sub_rf(       coeff_t lhs,  fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_sub_rf_to(    coeff_t lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_sub_fr(     fesoti_t* lhs,    coeff_t rhs,                dhelpl_t dhl);
void     fesoti_sub_fr_to(  fesoti_t* lhs,    coeff_t rhs, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fesoti_t fesoti_mul_ff(   fesoti_t* lhs, fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_mul_ff_to(fesoti_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_mul_of(   sotinum_t* lhs, fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_mul_of_to(sotinum_t* lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_mul_rf(   coeff_t lhs, fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_mul_rf_to(coeff_t lhs, fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fesoti_t fesoti_div_ff(     fesoti_t* lhs,  fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_div_ff_to(  fesoti_t* lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_div_of(    sotinum_t* lhs,  fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_div_of_to( sotinum_t* lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_div_fo(     fesoti_t* lhs, sotinum_t* rhs,                dhelpl_t dhl);
void     fesoti_div_fo_to(  fesoti_t* lhs, sotinum_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_div_rf(       coeff_t lhs,  fesoti_t* rhs,                dhelpl_t dhl);
void     fesoti_div_rf_to(    coeff_t lhs,  fesoti_t* rhs, fesoti_t* res, dhelpl_t dhl);

fesoti_t fesoti_div_fr(     fesoti_t* lhs,    coeff_t rhs,                dhelpl_t dhl);
void     fesoti_div_fr_to(  fesoti_t* lhs,    coeff_t rhs, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------







#endif