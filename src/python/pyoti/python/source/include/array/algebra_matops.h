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
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
arrso_t arrso_invert(    arrso_t* arr1,               dhelpl_t dhl);
void    arrso_invert_to( arrso_t* arr1, arrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
sotinum_t arrso_det(    arrso_t* arr1,                 dhelpl_t dhl);
void      arrso_det_to( arrso_t* arr1, sotinum_t* res, dhelpl_t dhl);
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