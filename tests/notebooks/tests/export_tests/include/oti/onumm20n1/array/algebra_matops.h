#ifndef OTI_ONUMM20N1_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM20N1_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t oarrm20n1_dotproduct_OO(    oarrm20n1_t* lhs, oarrm20n1_t* rhs);
void      oarrm20n1_dotproduct_OO_to( oarrm20n1_t* lhs, oarrm20n1_t* rhs, onumm20n1_t* res);

onumm20n1_t oarrm20n1_dotproduct_RO(     darr_t* lhs, oarrm20n1_t* rhs);
void      oarrm20n1_dotproduct_RO_to(  darr_t* lhs, oarrm20n1_t* rhs, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm20n1_t oarrm20n1_matmul_OO(    oarrm20n1_t* lhs, oarrm20n1_t* rhs);
oarrm20n1_t oarrm20n1_matmul_OR(    oarrm20n1_t* lhs,  darr_t* rhs);
oarrm20n1_t oarrm20n1_matmul_RO(     darr_t* lhs, oarrm20n1_t* rhs);

void    oarrm20n1_matmul_OO_to( oarrm20n1_t* lhs, oarrm20n1_t* rhs, oarrm20n1_t* res);
void    oarrm20n1_matmul_OR_to( oarrm20n1_t* lhs,  darr_t* rhs, oarrm20n1_t* res);
void    oarrm20n1_matmul_RO_to(  darr_t* lhs, oarrm20n1_t* rhs, oarrm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm20n1_t oarrm20n1_transpose(    oarrm20n1_t* arr1);
void    oarrm20n1_transpose_to( oarrm20n1_t* arr1, oarrm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm20n1_t oarrm20n1_invert(    oarrm20n1_t* arr1);
void    oarrm20n1_invert_to( oarrm20n1_t* arr1, oarrm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t oarrm20n1_det(    oarrm20n1_t* arr1);
void      oarrm20n1_det_to( oarrm20n1_t* arr1, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t oarrm20n1_norm(    oarrm20n1_t* arr1);
void      oarrm20n1_norm_to( oarrm20n1_t* arr1,  onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t oarrm20n1_pnorm(    oarrm20n1_t* arr1, coeff_t p);
void      oarrm20n1_pnorm_to( oarrm20n1_t* arr1, coeff_t p, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif