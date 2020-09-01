#ifndef OTI_ONUMM10N2_ARRAY_ALGEBRA_MATOPS_H
#define OTI_ONUMM10N2_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t oarrm10n2_dotproduct_OO(    oarrm10n2_t* lhs, oarrm10n2_t* rhs);
void      oarrm10n2_dotproduct_OO_to( oarrm10n2_t* lhs, oarrm10n2_t* rhs, onumm10n2_t* res);

onumm10n2_t oarrm10n2_dotproduct_RO(     darr_t* lhs, oarrm10n2_t* rhs);
void      oarrm10n2_dotproduct_RO_to(  darr_t* lhs, oarrm10n2_t* rhs, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm10n2_t oarrm10n2_matmul_OO(    oarrm10n2_t* lhs, oarrm10n2_t* rhs);
oarrm10n2_t oarrm10n2_matmul_OR(    oarrm10n2_t* lhs,  darr_t* rhs);
oarrm10n2_t oarrm10n2_matmul_RO(     darr_t* lhs, oarrm10n2_t* rhs);

void    oarrm10n2_matmul_OO_to( oarrm10n2_t* lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
void    oarrm10n2_matmul_OR_to( oarrm10n2_t* lhs,  darr_t* rhs, oarrm10n2_t* res);
void    oarrm10n2_matmul_RO_to(  darr_t* lhs, oarrm10n2_t* rhs, oarrm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm10n2_t oarrm10n2_transpose(    oarrm10n2_t* arr1);
void    oarrm10n2_transpose_to( oarrm10n2_t* arr1, oarrm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
oarrm10n2_t oarrm10n2_invert(    oarrm10n2_t* arr1);
void    oarrm10n2_invert_to( oarrm10n2_t* arr1, oarrm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t oarrm10n2_det(    oarrm10n2_t* arr1);
void      oarrm10n2_det_to( oarrm10n2_t* arr1, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t oarrm10n2_norm(    oarrm10n2_t* arr1);
void      oarrm10n2_norm_to( oarrm10n2_t* arr1,  onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t oarrm10n2_pnorm(    oarrm10n2_t* arr1, coeff_t p);
void      oarrm10n2_pnorm_to( oarrm10n2_t* arr1, coeff_t p, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif