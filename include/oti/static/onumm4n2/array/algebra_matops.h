#ifndef OTI_ONUMM4N2_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM4N2_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t oarrm4n2_dotproduct_OO(    oarrm4n2_t* lhs, oarrm4n2_t* rhs);
void      oarrm4n2_dotproduct_OO_to( oarrm4n2_t* lhs, oarrm4n2_t* rhs, onumm4n2_t* res);

onumm4n2_t oarrm4n2_dotproduct_RO(     darr_t* lhs, oarrm4n2_t* rhs);
void      oarrm4n2_dotproduct_RO_to(  darr_t* lhs, oarrm4n2_t* rhs, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm4n2_t oarrm4n2_matmul_OO(    oarrm4n2_t* lhs, oarrm4n2_t* rhs);
oarrm4n2_t oarrm4n2_matmul_OR(    oarrm4n2_t* lhs,  darr_t* rhs);
oarrm4n2_t oarrm4n2_matmul_RO(     darr_t* lhs, oarrm4n2_t* rhs);

void    oarrm4n2_matmul_OO_to( oarrm4n2_t* lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
void    oarrm4n2_matmul_OR_to( oarrm4n2_t* lhs,  darr_t* rhs, oarrm4n2_t* res);
void    oarrm4n2_matmul_RO_to(  darr_t* lhs, oarrm4n2_t* rhs, oarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm4n2_t oarrm4n2_transpose(    oarrm4n2_t* arr1);
void    oarrm4n2_transpose_to( oarrm4n2_t* arr1, oarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm4n2_t oarrm4n2_invert(    oarrm4n2_t* arr1);
void    oarrm4n2_invert_to( oarrm4n2_t* arr1, oarrm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t oarrm4n2_det(    oarrm4n2_t* arr1);
void      oarrm4n2_det_to( oarrm4n2_t* arr1, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t oarrm4n2_norm(    oarrm4n2_t* arr1);
void      oarrm4n2_norm_to( oarrm4n2_t* arr1,  onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t oarrm4n2_pnorm(    oarrm4n2_t* arr1, coeff_t p);
void      oarrm4n2_pnorm_to( oarrm4n2_t* arr1, coeff_t p, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif