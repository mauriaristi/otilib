#ifndef OTI_MDNUM9_ARRAY_ALGEBRA_MATOPS_H
#define OTI_MDNUM9_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdarr9_dotproduct_OO(    mdarr9_t* lhs, mdarr9_t* rhs);
void      mdarr9_dotproduct_OO_to( mdarr9_t* lhs, mdarr9_t* rhs, mdnum9_t* res);

mdnum9_t mdarr9_dotproduct_RO(     darr_t* lhs, mdarr9_t* rhs);
void      mdarr9_dotproduct_RO_to(  darr_t* lhs, mdarr9_t* rhs, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr9_t mdarr9_matmul_OO(    mdarr9_t* lhs, mdarr9_t* rhs);
mdarr9_t mdarr9_matmul_OR(    mdarr9_t* lhs,  darr_t* rhs);
mdarr9_t mdarr9_matmul_RO(     darr_t* lhs, mdarr9_t* rhs);

void    mdarr9_matmul_OO_to( mdarr9_t* lhs, mdarr9_t* rhs, mdarr9_t* res);
void    mdarr9_matmul_OR_to( mdarr9_t* lhs,  darr_t* rhs, mdarr9_t* res);
void    mdarr9_matmul_RO_to(  darr_t* lhs, mdarr9_t* rhs, mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr9_t mdarr9_transpose(    mdarr9_t* arr1);
void    mdarr9_transpose_to( mdarr9_t* arr1, mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr9_t mdarr9_invert(    mdarr9_t* arr1);
void    mdarr9_invert_to( mdarr9_t* arr1, mdarr9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdarr9_det(    mdarr9_t* arr1);
void      mdarr9_det_to( mdarr9_t* arr1, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdarr9_norm(    mdarr9_t* arr1);
void      mdarr9_norm_to( mdarr9_t* arr1,  mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdarr9_pnorm(    mdarr9_t* arr1, coeff_t p);
void      mdarr9_pnorm_to( mdarr9_t* arr1, coeff_t p, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif