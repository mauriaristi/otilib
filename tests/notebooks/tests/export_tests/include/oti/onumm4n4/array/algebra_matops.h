#ifndef OTI_ONUMM4N4_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM4N4_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t oarrm4n4_dotproduct_OO(    oarrm4n4_t* lhs, oarrm4n4_t* rhs);
void      oarrm4n4_dotproduct_OO_to( oarrm4n4_t* lhs, oarrm4n4_t* rhs, onumm4n4_t* res);

onumm4n4_t oarrm4n4_dotproduct_RO(     darr_t* lhs, oarrm4n4_t* rhs);
void      oarrm4n4_dotproduct_RO_to(  darr_t* lhs, oarrm4n4_t* rhs, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm4n4_t oarrm4n4_matmul_OO(    oarrm4n4_t* lhs, oarrm4n4_t* rhs);
oarrm4n4_t oarrm4n4_matmul_OR(    oarrm4n4_t* lhs,  darr_t* rhs);
oarrm4n4_t oarrm4n4_matmul_RO(     darr_t* lhs, oarrm4n4_t* rhs);

void    oarrm4n4_matmul_OO_to( oarrm4n4_t* lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
void    oarrm4n4_matmul_OR_to( oarrm4n4_t* lhs,  darr_t* rhs, oarrm4n4_t* res);
void    oarrm4n4_matmul_RO_to(  darr_t* lhs, oarrm4n4_t* rhs, oarrm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm4n4_t oarrm4n4_transpose(    oarrm4n4_t* arr1);
void    oarrm4n4_transpose_to( oarrm4n4_t* arr1, oarrm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm4n4_t oarrm4n4_invert(    oarrm4n4_t* arr1);
void    oarrm4n4_invert_to( oarrm4n4_t* arr1, oarrm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t oarrm4n4_det(    oarrm4n4_t* arr1);
void      oarrm4n4_det_to( oarrm4n4_t* arr1, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t oarrm4n4_norm(    oarrm4n4_t* arr1);
void      oarrm4n4_norm_to( oarrm4n4_t* arr1,  onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t oarrm4n4_pnorm(    oarrm4n4_t* arr1, coeff_t p);
void      oarrm4n4_pnorm_to( oarrm4n4_t* arr1, coeff_t p, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif