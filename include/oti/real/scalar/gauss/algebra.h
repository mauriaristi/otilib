#ifndef OTI_REAL_SCALAR_GAUSS_ALGEBRA_H
#define OTI_REAL_SCALAR_GAUSS_ALGEBRA_H


/**************************************************************************************************//**
@brief Scalar negation.

res = - num

@param[in] num Number to negate.
@param[in] res Result.
******************************************************************************************************/
fednum_t fednum_neg(   fednum_t* num               );
void     fednum_neg_to(fednum_t* num, fednum_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar addition.

res = lhs + rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
******************************************************************************************************/
fednum_t fednum_sum_ff(   fednum_t* lhs, fednum_t* rhs               );
void     fednum_sum_ff_to(fednum_t* lhs, fednum_t* rhs, fednum_t* res);

fednum_t fednum_sum_rf(     coeff_t lhs, fednum_t* rhs               );
void     fednum_sum_rf_to(  coeff_t lhs, fednum_t* rhs, fednum_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar subtraction.

res = lhs - rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
******************************************************************************************************/
fednum_t fednum_sub_ff(     fednum_t* lhs,  fednum_t* rhs               );
void     fednum_sub_ff_to(  fednum_t* lhs,  fednum_t* rhs, fednum_t* res);

fednum_t fednum_sub_rf(       coeff_t lhs,  fednum_t* rhs               );
void     fednum_sub_rf_to(    coeff_t lhs,  fednum_t* rhs, fednum_t* res);

fednum_t fednum_sub_fr(     fednum_t* lhs,    coeff_t rhs               );
void     fednum_sub_fr_to(  fednum_t* lhs,    coeff_t rhs, fednum_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar multiplication.

res = lhs * rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
******************************************************************************************************/
fednum_t fednum_mul_ff(   fednum_t* lhs, fednum_t* rhs               );
void     fednum_mul_ff_to(fednum_t* lhs, fednum_t* rhs, fednum_t* res);

fednum_t fednum_mul_rf(     coeff_t lhs, fednum_t* rhs               );
void     fednum_mul_rf_to(  coeff_t lhs, fednum_t* rhs, fednum_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Scalar division.

res = lhs / rhs

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result.
******************************************************************************************************/
fednum_t fednum_div_ff(     fednum_t* lhs,  fednum_t* rhs               );
void     fednum_div_ff_to(  fednum_t* lhs,  fednum_t* rhs, fednum_t* res);

fednum_t fednum_div_rf(       coeff_t lhs,  fednum_t* rhs               );
void     fednum_div_rf_to(    coeff_t lhs,  fednum_t* rhs, fednum_t* res);

fednum_t fednum_div_fr(     fednum_t* lhs,    coeff_t rhs               );
void     fednum_div_fr_to(  fednum_t* lhs,    coeff_t rhs, fednum_t* res);
// ----------------------------------------------------------------------------------------------------




#endif