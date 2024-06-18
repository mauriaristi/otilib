#ifndef OTI_ONUMM2N1_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM2N1_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t oarrm2n1_dotproduct_OO(    oarrm2n1_t* lhs, oarrm2n1_t* rhs);
void      oarrm2n1_dotproduct_OO_to( oarrm2n1_t* lhs, oarrm2n1_t* rhs, onumm2n1_t* res);

onumm2n1_t oarrm2n1_dotproduct_RO(     darr_t* lhs, oarrm2n1_t* rhs);
void      oarrm2n1_dotproduct_RO_to(  darr_t* lhs, oarrm2n1_t* rhs, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm2n1_t oarrm2n1_matmul_OO(    oarrm2n1_t* lhs, oarrm2n1_t* rhs);
oarrm2n1_t oarrm2n1_matmul_OR(    oarrm2n1_t* lhs,  darr_t* rhs);
oarrm2n1_t oarrm2n1_matmul_RO(     darr_t* lhs, oarrm2n1_t* rhs);

void    oarrm2n1_matmul_OO_to( oarrm2n1_t* lhs, oarrm2n1_t* rhs, oarrm2n1_t* res);
void    oarrm2n1_matmul_OR_to( oarrm2n1_t* lhs,  darr_t* rhs, oarrm2n1_t* res);
void    oarrm2n1_matmul_RO_to(  darr_t* lhs, oarrm2n1_t* rhs, oarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm2n1_t oarrm2n1_transpose(    oarrm2n1_t* arr1);
void    oarrm2n1_transpose_to( oarrm2n1_t* arr1, oarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm2n1_t oarrm2n1_invert(    oarrm2n1_t* arr1);
void    oarrm2n1_invert_to( oarrm2n1_t* arr1, oarrm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t oarrm2n1_det(    oarrm2n1_t* arr1);
void      oarrm2n1_det_to( oarrm2n1_t* arr1, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t oarrm2n1_norm(    oarrm2n1_t* arr1);
void      oarrm2n1_norm_to( oarrm2n1_t* arr1,  onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t oarrm2n1_pnorm(    oarrm2n1_t* arr1, coeff_t p);
void      oarrm2n1_pnorm_to( oarrm2n1_t* arr1, coeff_t p, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif