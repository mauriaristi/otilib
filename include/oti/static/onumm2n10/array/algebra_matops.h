#ifndef OTI_ONUMM2N10_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM2N10_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t oarrm2n10_dotproduct_OO(    oarrm2n10_t* lhs, oarrm2n10_t* rhs);
void      oarrm2n10_dotproduct_OO_to( oarrm2n10_t* lhs, oarrm2n10_t* rhs, onumm2n10_t* res);

onumm2n10_t oarrm2n10_dotproduct_RO(     darr_t* lhs, oarrm2n10_t* rhs);
void      oarrm2n10_dotproduct_RO_to(  darr_t* lhs, oarrm2n10_t* rhs, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm2n10_t oarrm2n10_matmul_OO(    oarrm2n10_t* lhs, oarrm2n10_t* rhs);
oarrm2n10_t oarrm2n10_matmul_OR(    oarrm2n10_t* lhs,  darr_t* rhs);
oarrm2n10_t oarrm2n10_matmul_RO(     darr_t* lhs, oarrm2n10_t* rhs);

void    oarrm2n10_matmul_OO_to( oarrm2n10_t* lhs, oarrm2n10_t* rhs, oarrm2n10_t* res);
void    oarrm2n10_matmul_OR_to( oarrm2n10_t* lhs,  darr_t* rhs, oarrm2n10_t* res);
void    oarrm2n10_matmul_RO_to(  darr_t* lhs, oarrm2n10_t* rhs, oarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm2n10_t oarrm2n10_transpose(    oarrm2n10_t* arr1);
void    oarrm2n10_transpose_to( oarrm2n10_t* arr1, oarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm2n10_t oarrm2n10_invert(    oarrm2n10_t* arr1);
void    oarrm2n10_invert_to( oarrm2n10_t* arr1, oarrm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t oarrm2n10_det(    oarrm2n10_t* arr1);
void      oarrm2n10_det_to( oarrm2n10_t* arr1, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t oarrm2n10_norm(    oarrm2n10_t* arr1);
void      oarrm2n10_norm_to( oarrm2n10_t* arr1,  onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t oarrm2n10_pnorm(    oarrm2n10_t* arr1, coeff_t p);
void      oarrm2n10_pnorm_to( oarrm2n10_t* arr1, coeff_t p, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif