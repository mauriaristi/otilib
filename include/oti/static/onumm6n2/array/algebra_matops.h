#ifndef OTI_ONUMM6N2_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM6N2_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t oarrm6n2_dotproduct_OO(    oarrm6n2_t* lhs, oarrm6n2_t* rhs);
void      oarrm6n2_dotproduct_OO_to( oarrm6n2_t* lhs, oarrm6n2_t* rhs, onumm6n2_t* res);

onumm6n2_t oarrm6n2_dotproduct_RO(     darr_t* lhs, oarrm6n2_t* rhs);
void      oarrm6n2_dotproduct_RO_to(  darr_t* lhs, oarrm6n2_t* rhs, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm6n2_t oarrm6n2_matmul_OO(    oarrm6n2_t* lhs, oarrm6n2_t* rhs);
oarrm6n2_t oarrm6n2_matmul_OR(    oarrm6n2_t* lhs,  darr_t* rhs);
oarrm6n2_t oarrm6n2_matmul_RO(     darr_t* lhs, oarrm6n2_t* rhs);

void    oarrm6n2_matmul_OO_to( oarrm6n2_t* lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
void    oarrm6n2_matmul_OR_to( oarrm6n2_t* lhs,  darr_t* rhs, oarrm6n2_t* res);
void    oarrm6n2_matmul_RO_to(  darr_t* lhs, oarrm6n2_t* rhs, oarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm6n2_t oarrm6n2_transpose(    oarrm6n2_t* arr1);
void    oarrm6n2_transpose_to( oarrm6n2_t* arr1, oarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm6n2_t oarrm6n2_invert(    oarrm6n2_t* arr1);
void    oarrm6n2_invert_to( oarrm6n2_t* arr1, oarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t oarrm6n2_det(    oarrm6n2_t* arr1);
void      oarrm6n2_det_to( oarrm6n2_t* arr1, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t oarrm6n2_norm(    oarrm6n2_t* arr1);
void      oarrm6n2_norm_to( oarrm6n2_t* arr1,  onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t oarrm6n2_pnorm(    oarrm6n2_t* arr1, coeff_t p);
void      oarrm6n2_pnorm_to( oarrm6n2_t* arr1, coeff_t p, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif