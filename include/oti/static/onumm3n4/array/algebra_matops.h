#ifndef OTI_ONUMM3N4_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM3N4_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t oarrm3n4_dotproduct_OO(    oarrm3n4_t* lhs, oarrm3n4_t* rhs);
void      oarrm3n4_dotproduct_OO_to( oarrm3n4_t* lhs, oarrm3n4_t* rhs, onumm3n4_t* res);

onumm3n4_t oarrm3n4_dotproduct_RO(     darr_t* lhs, oarrm3n4_t* rhs);
void      oarrm3n4_dotproduct_RO_to(  darr_t* lhs, oarrm3n4_t* rhs, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm3n4_t oarrm3n4_matmul_OO(    oarrm3n4_t* lhs, oarrm3n4_t* rhs);
oarrm3n4_t oarrm3n4_matmul_OR(    oarrm3n4_t* lhs,  darr_t* rhs);
oarrm3n4_t oarrm3n4_matmul_RO(     darr_t* lhs, oarrm3n4_t* rhs);

void    oarrm3n4_matmul_OO_to( oarrm3n4_t* lhs, oarrm3n4_t* rhs, oarrm3n4_t* res);
void    oarrm3n4_matmul_OR_to( oarrm3n4_t* lhs,  darr_t* rhs, oarrm3n4_t* res);
void    oarrm3n4_matmul_RO_to(  darr_t* lhs, oarrm3n4_t* rhs, oarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm3n4_t oarrm3n4_transpose(    oarrm3n4_t* arr1);
void    oarrm3n4_transpose_to( oarrm3n4_t* arr1, oarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm3n4_t oarrm3n4_invert(    oarrm3n4_t* arr1);
void    oarrm3n4_invert_to( oarrm3n4_t* arr1, oarrm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t oarrm3n4_det(    oarrm3n4_t* arr1);
void      oarrm3n4_det_to( oarrm3n4_t* arr1, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t oarrm3n4_norm(    oarrm3n4_t* arr1);
void      oarrm3n4_norm_to( oarrm3n4_t* arr1,  onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t oarrm3n4_pnorm(    oarrm3n4_t* arr1, coeff_t p);
void      oarrm3n4_pnorm_to( oarrm3n4_t* arr1, coeff_t p, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif