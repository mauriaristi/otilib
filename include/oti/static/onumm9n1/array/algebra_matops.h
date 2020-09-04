#ifndef OTI_ONUMM9N1_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM9N1_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t oarrm9n1_dotproduct_OO(    oarrm9n1_t* lhs, oarrm9n1_t* rhs);
void      oarrm9n1_dotproduct_OO_to( oarrm9n1_t* lhs, oarrm9n1_t* rhs, onumm9n1_t* res);

onumm9n1_t oarrm9n1_dotproduct_RO(     darr_t* lhs, oarrm9n1_t* rhs);
void      oarrm9n1_dotproduct_RO_to(  darr_t* lhs, oarrm9n1_t* rhs, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm9n1_t oarrm9n1_matmul_OO(    oarrm9n1_t* lhs, oarrm9n1_t* rhs);
oarrm9n1_t oarrm9n1_matmul_OR(    oarrm9n1_t* lhs,  darr_t* rhs);
oarrm9n1_t oarrm9n1_matmul_RO(     darr_t* lhs, oarrm9n1_t* rhs);

void    oarrm9n1_matmul_OO_to( oarrm9n1_t* lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
void    oarrm9n1_matmul_OR_to( oarrm9n1_t* lhs,  darr_t* rhs, oarrm9n1_t* res);
void    oarrm9n1_matmul_RO_to(  darr_t* lhs, oarrm9n1_t* rhs, oarrm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm9n1_t oarrm9n1_transpose(    oarrm9n1_t* arr1);
void    oarrm9n1_transpose_to( oarrm9n1_t* arr1, oarrm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm9n1_t oarrm9n1_invert(    oarrm9n1_t* arr1);
void    oarrm9n1_invert_to( oarrm9n1_t* arr1, oarrm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t oarrm9n1_det(    oarrm9n1_t* arr1);
void      oarrm9n1_det_to( oarrm9n1_t* arr1, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t oarrm9n1_norm(    oarrm9n1_t* arr1);
void      oarrm9n1_norm_to( oarrm9n1_t* arr1,  onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t oarrm9n1_pnorm(    oarrm9n1_t* arr1, coeff_t p);
void      oarrm9n1_pnorm_to( oarrm9n1_t* arr1, coeff_t p, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif