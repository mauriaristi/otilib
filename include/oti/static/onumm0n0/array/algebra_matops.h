#ifndef OTI_ONUMM0N0_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM0N0_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t oarrm0n0_dotproduct_OO(    oarrm0n0_t* lhs, oarrm0n0_t* rhs);
void      oarrm0n0_dotproduct_OO_to( oarrm0n0_t* lhs, oarrm0n0_t* rhs, onumm0n0_t* res);

onumm0n0_t oarrm0n0_dotproduct_RO(     darr_t* lhs, oarrm0n0_t* rhs);
void      oarrm0n0_dotproduct_RO_to(  darr_t* lhs, oarrm0n0_t* rhs, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm0n0_t oarrm0n0_matmul_OO(    oarrm0n0_t* lhs, oarrm0n0_t* rhs);
oarrm0n0_t oarrm0n0_matmul_OR(    oarrm0n0_t* lhs,  darr_t* rhs);
oarrm0n0_t oarrm0n0_matmul_RO(     darr_t* lhs, oarrm0n0_t* rhs);

void    oarrm0n0_matmul_OO_to( oarrm0n0_t* lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
void    oarrm0n0_matmul_OR_to( oarrm0n0_t* lhs,  darr_t* rhs, oarrm0n0_t* res);
void    oarrm0n0_matmul_RO_to(  darr_t* lhs, oarrm0n0_t* rhs, oarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm0n0_t oarrm0n0_transpose(    oarrm0n0_t* arr1);
void    oarrm0n0_transpose_to( oarrm0n0_t* arr1, oarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm0n0_t oarrm0n0_invert(    oarrm0n0_t* arr1);
void    oarrm0n0_invert_to( oarrm0n0_t* arr1, oarrm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t oarrm0n0_det(    oarrm0n0_t* arr1);
void      oarrm0n0_det_to( oarrm0n0_t* arr1, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t oarrm0n0_norm(    oarrm0n0_t* arr1);
void      oarrm0n0_norm_to( oarrm0n0_t* arr1,  onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t oarrm0n0_pnorm(    oarrm0n0_t* arr1, coeff_t p);
void      oarrm0n0_pnorm_to( oarrm0n0_t* arr1, coeff_t p, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

#endif