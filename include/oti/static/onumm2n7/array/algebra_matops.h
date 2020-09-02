#ifndef OTI_ONUMM2N7_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM2N7_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t oarrm2n7_dotproduct_OO(    oarrm2n7_t* lhs, oarrm2n7_t* rhs);
void      oarrm2n7_dotproduct_OO_to( oarrm2n7_t* lhs, oarrm2n7_t* rhs, onumm2n7_t* res);

onumm2n7_t oarrm2n7_dotproduct_RO(     darr_t* lhs, oarrm2n7_t* rhs);
void      oarrm2n7_dotproduct_RO_to(  darr_t* lhs, oarrm2n7_t* rhs, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm2n7_t oarrm2n7_matmul_OO(    oarrm2n7_t* lhs, oarrm2n7_t* rhs);
oarrm2n7_t oarrm2n7_matmul_OR(    oarrm2n7_t* lhs,  darr_t* rhs);
oarrm2n7_t oarrm2n7_matmul_RO(     darr_t* lhs, oarrm2n7_t* rhs);

void    oarrm2n7_matmul_OO_to( oarrm2n7_t* lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
void    oarrm2n7_matmul_OR_to( oarrm2n7_t* lhs,  darr_t* rhs, oarrm2n7_t* res);
void    oarrm2n7_matmul_RO_to(  darr_t* lhs, oarrm2n7_t* rhs, oarrm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm2n7_t oarrm2n7_transpose(    oarrm2n7_t* arr1);
void    oarrm2n7_transpose_to( oarrm2n7_t* arr1, oarrm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm2n7_t oarrm2n7_invert(    oarrm2n7_t* arr1);
void    oarrm2n7_invert_to( oarrm2n7_t* arr1, oarrm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t oarrm2n7_det(    oarrm2n7_t* arr1);
void      oarrm2n7_det_to( oarrm2n7_t* arr1, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t oarrm2n7_norm(    oarrm2n7_t* arr1);
void      oarrm2n7_norm_to( oarrm2n7_t* arr1,  onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t oarrm2n7_pnorm(    oarrm2n7_t* arr1, coeff_t p);
void      oarrm2n7_pnorm_to( oarrm2n7_t* arr1, coeff_t p, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif