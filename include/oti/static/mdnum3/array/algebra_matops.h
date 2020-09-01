#ifndef OTI_MDNUM3_ARRAY_ALGEBRA_MATOPS_H
#define OTI_MDNUM3_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdarr3_dotproduct_OO(    mdarr3_t* lhs, mdarr3_t* rhs);
void      mdarr3_dotproduct_OO_to( mdarr3_t* lhs, mdarr3_t* rhs, mdnum3_t* res);

mdnum3_t mdarr3_dotproduct_RO(     darr_t* lhs, mdarr3_t* rhs);
void      mdarr3_dotproduct_RO_to(  darr_t* lhs, mdarr3_t* rhs, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr3_t mdarr3_matmul_OO(    mdarr3_t* lhs, mdarr3_t* rhs);
mdarr3_t mdarr3_matmul_OR(    mdarr3_t* lhs,  darr_t* rhs);
mdarr3_t mdarr3_matmul_RO(     darr_t* lhs, mdarr3_t* rhs);

void    mdarr3_matmul_OO_to( mdarr3_t* lhs, mdarr3_t* rhs, mdarr3_t* res);
void    mdarr3_matmul_OR_to( mdarr3_t* lhs,  darr_t* rhs, mdarr3_t* res);
void    mdarr3_matmul_RO_to(  darr_t* lhs, mdarr3_t* rhs, mdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr3_t mdarr3_transpose(    mdarr3_t* arr1);
void    mdarr3_transpose_to( mdarr3_t* arr1, mdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr3_t mdarr3_invert(    mdarr3_t* arr1);
void    mdarr3_invert_to( mdarr3_t* arr1, mdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdarr3_det(    mdarr3_t* arr1);
void      mdarr3_det_to( mdarr3_t* arr1, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdarr3_norm(    mdarr3_t* arr1);
void      mdarr3_norm_to( mdarr3_t* arr1,  mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdarr3_pnorm(    mdarr3_t* arr1, coeff_t p);
void      mdarr3_pnorm_to( mdarr3_t* arr1, coeff_t p, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif