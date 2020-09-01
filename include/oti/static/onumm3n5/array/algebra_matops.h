#ifndef OTI_ONUMM3N5_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM3N5_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t oarrm3n5_dotproduct_OO(    oarrm3n5_t* lhs, oarrm3n5_t* rhs);
void      oarrm3n5_dotproduct_OO_to( oarrm3n5_t* lhs, oarrm3n5_t* rhs, onumm3n5_t* res);

onumm3n5_t oarrm3n5_dotproduct_RO(     darr_t* lhs, oarrm3n5_t* rhs);
void      oarrm3n5_dotproduct_RO_to(  darr_t* lhs, oarrm3n5_t* rhs, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm3n5_t oarrm3n5_matmul_OO(    oarrm3n5_t* lhs, oarrm3n5_t* rhs);
oarrm3n5_t oarrm3n5_matmul_OR(    oarrm3n5_t* lhs,  darr_t* rhs);
oarrm3n5_t oarrm3n5_matmul_RO(     darr_t* lhs, oarrm3n5_t* rhs);

void    oarrm3n5_matmul_OO_to( oarrm3n5_t* lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
void    oarrm3n5_matmul_OR_to( oarrm3n5_t* lhs,  darr_t* rhs, oarrm3n5_t* res);
void    oarrm3n5_matmul_RO_to(  darr_t* lhs, oarrm3n5_t* rhs, oarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm3n5_t oarrm3n5_transpose(    oarrm3n5_t* arr1);
void    oarrm3n5_transpose_to( oarrm3n5_t* arr1, oarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm3n5_t oarrm3n5_invert(    oarrm3n5_t* arr1);
void    oarrm3n5_invert_to( oarrm3n5_t* arr1, oarrm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t oarrm3n5_det(    oarrm3n5_t* arr1);
void      oarrm3n5_det_to( oarrm3n5_t* arr1, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t oarrm3n5_norm(    oarrm3n5_t* arr1);
void      oarrm3n5_norm_to( oarrm3n5_t* arr1,  onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t oarrm3n5_pnorm(    oarrm3n5_t* arr1, coeff_t p);
void      oarrm3n5_pnorm_to( oarrm3n5_t* arr1, coeff_t p, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif