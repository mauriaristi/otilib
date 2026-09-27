#ifndef OTI_SPARSE_ARRAY_ALGEBRA_MATOPS_H
#define OTI_SPARSE_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
sotinum_t arrso_dotproduct_OO(    arrso_t* lhs, arrso_t* rhs,                 dhelpl_t dhl);
void      arrso_dotproduct_OO_to( arrso_t* lhs, arrso_t* rhs, sotinum_t* res, dhelpl_t dhl);

sotinum_t arrso_dotproduct_RO(     darr_t* lhs, arrso_t* rhs,                 dhelpl_t dhl);
void      arrso_dotproduct_RO_to(  darr_t* lhs, arrso_t* rhs, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrso_t arrso_matmul_OO(    arrso_t* lhs, arrso_t* rhs,               dhelpl_t dhl);
arrso_t arrso_matmul_OR(    arrso_t* lhs,  darr_t* rhs,               dhelpl_t dhl);
arrso_t arrso_matmul_RO(     darr_t* lhs, arrso_t* rhs,               dhelpl_t dhl);

void    arrso_matmul_OO_to( arrso_t* lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
void    arrso_matmul_OR_to( arrso_t* lhs,  darr_t* rhs, arrso_t* res, dhelpl_t dhl);
void    arrso_matmul_RO_to(  darr_t* lhs, arrso_t* rhs, arrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrso_t arrso_transpose(    arrso_t* arr1,               dhelpl_t dhl);
void    arrso_transpose_to( arrso_t* arr1, arrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Matrix inversion.

RES  = INVERSE( ARR1 )

n <= _OTI_LINALG_CLOSED_FORM_MAX (at most 3): closed forms (cofactors over the determinant).
Larger n: block solver on the LAPACK LU factors of the real part, arrso_solve_to(ARR1, I, RES).

@param[in]  arr1   Square array to be inverted.
@param[out] res    Result, same shape, allocated by the caller (_to variant). May be arr1.
@param[in]  dhl    Direction helper list object.

@return (_to) 0 on success; > 0 if the real part of arr1 is singular; < 0 on a size or memory error
        (see algebra_lu.h). On failure res is filled with NaN. The allocating variant returns a new
        array owned by the caller (NaN-filled on failure).
******************************************************************************************************/ 
arrso_t arrso_invert(    arrso_t* arr1,               dhelpl_t dhl);
int     arrso_invert_to( arrso_t* arr1, arrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

n <= _OTI_LINALG_CLOSED_FORM_MAX (at most 3): closed forms (valid for any real part).
Larger n: det = sign(P) prod_i U_ii from the OTI LU factorization (arrso_lu_factor_to). Known
limitation: a singular real part is not supported for n > 3 (status > 0, NaN result).

@param[in]  arr1   Square array.
@param[out] res    Result (_to variant). Its memory is reallocated if needed.
@param[in]  dhl    Direction helper list object.

@return (_to) 0 on success; > 0 if the LU path met a singular real part; < 0 on a size or memory
        error (see algebra_lu.h). On failure res is NaN. The allocating variant returns a new
        sotinum_t owned by the caller, to be released with soti_free() (NaN on failure).
******************************************************************************************************/ 
sotinum_t arrso_det(    arrso_t* arr1,                 dhelpl_t dhl);
int       arrso_det_to( arrso_t* arr1, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
sotinum_t arrso_norm(    arrso_t* arr1,                  dhelpl_t dhl);
void      arrso_norm_to( arrso_t* arr1,  sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
sotinum_t arrso_pnorm(    arrso_t* arr1, coeff_t p,                 dhelpl_t dhl);
void      arrso_pnorm_to( arrso_t* arr1, coeff_t p, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

#endif