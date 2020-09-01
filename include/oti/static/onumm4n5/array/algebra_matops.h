#ifndef OTI_ONUMM4N5_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM4N5_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t oarrm4n5_dotproduct_OO(    oarrm4n5_t* lhs, oarrm4n5_t* rhs);
void      oarrm4n5_dotproduct_OO_to( oarrm4n5_t* lhs, oarrm4n5_t* rhs, onumm4n5_t* res);

onumm4n5_t oarrm4n5_dotproduct_RO(     darr_t* lhs, oarrm4n5_t* rhs);
void      oarrm4n5_dotproduct_RO_to(  darr_t* lhs, oarrm4n5_t* rhs, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm4n5_t oarrm4n5_matmul_OO(    oarrm4n5_t* lhs, oarrm4n5_t* rhs);
oarrm4n5_t oarrm4n5_matmul_OR(    oarrm4n5_t* lhs,  darr_t* rhs);
oarrm4n5_t oarrm4n5_matmul_RO(     darr_t* lhs, oarrm4n5_t* rhs);

void    oarrm4n5_matmul_OO_to( oarrm4n5_t* lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
void    oarrm4n5_matmul_OR_to( oarrm4n5_t* lhs,  darr_t* rhs, oarrm4n5_t* res);
void    oarrm4n5_matmul_RO_to(  darr_t* lhs, oarrm4n5_t* rhs, oarrm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm4n5_t oarrm4n5_transpose(    oarrm4n5_t* arr1);
void    oarrm4n5_transpose_to( oarrm4n5_t* arr1, oarrm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm4n5_t oarrm4n5_invert(    oarrm4n5_t* arr1);
void    oarrm4n5_invert_to( oarrm4n5_t* arr1, oarrm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t oarrm4n5_det(    oarrm4n5_t* arr1);
void      oarrm4n5_det_to( oarrm4n5_t* arr1, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t oarrm4n5_norm(    oarrm4n5_t* arr1);
void      oarrm4n5_norm_to( oarrm4n5_t* arr1,  onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t oarrm4n5_pnorm(    oarrm4n5_t* arr1, coeff_t p);
void      oarrm4n5_pnorm_to( oarrm4n5_t* arr1, coeff_t p, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif