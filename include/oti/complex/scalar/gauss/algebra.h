#ifndef OTI_COMPLEX_SCALAR_GAUSS_ALGEBRA_H
#define OTI_COMPLEX_SCALAR_GAUSS_ALGEBRA_H


/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
******************************************************************************************************/
fecnum_t fecnum_neg(   fecnum_t* num               );
void     fecnum_neg_to(fecnum_t* num, fecnum_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
******************************************************************************************************/
fecnum_t fecnum_sum_ff(   fecnum_t* lhs, fecnum_t* rhs               );
void     fecnum_sum_ff_to(fecnum_t* lhs, fecnum_t* rhs, fecnum_t* res);

fecnum_t fecnum_sum_rf(     ccoeff_t lhs, fecnum_t* rhs               );
void     fecnum_sum_rf_to(  ccoeff_t lhs, fecnum_t* rhs, fecnum_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
******************************************************************************************************/
fecnum_t fecnum_sub_ff(     fecnum_t* lhs,  fecnum_t* rhs               );
void     fecnum_sub_ff_to(  fecnum_t* lhs,  fecnum_t* rhs, fecnum_t* res);

fecnum_t fecnum_sub_rf(       ccoeff_t lhs,  fecnum_t* rhs               );
void     fecnum_sub_rf_to(    ccoeff_t lhs,  fecnum_t* rhs, fecnum_t* res);

fecnum_t fecnum_sub_fr(     fecnum_t* lhs,    ccoeff_t rhs               );
void     fecnum_sub_fr_to(  fecnum_t* lhs,    ccoeff_t rhs, fecnum_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
******************************************************************************************************/
fecnum_t fecnum_mul_ff(   fecnum_t* lhs, fecnum_t* rhs               );
void     fecnum_mul_ff_to(fecnum_t* lhs, fecnum_t* rhs, fecnum_t* res);

fecnum_t fecnum_mul_rf(     ccoeff_t lhs, fecnum_t* rhs               );
void     fecnum_mul_rf_to(  ccoeff_t lhs, fecnum_t* rhs, fecnum_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
******************************************************************************************************/
fecnum_t fecnum_div_ff(     fecnum_t* lhs,  fecnum_t* rhs               );
void     fecnum_div_ff_to(  fecnum_t* lhs,  fecnum_t* rhs, fecnum_t* res);

fecnum_t fecnum_div_rf(       ccoeff_t lhs,  fecnum_t* rhs               );
void     fecnum_div_rf_to(    ccoeff_t lhs,  fecnum_t* rhs, fecnum_t* res);

fecnum_t fecnum_div_fr(     fecnum_t* lhs,    ccoeff_t rhs               );
void     fecnum_div_fr_to(  fecnum_t* lhs,    ccoeff_t rhs, fecnum_t* res);
// ----------------------------------------------------------------------------------------------------




#endif