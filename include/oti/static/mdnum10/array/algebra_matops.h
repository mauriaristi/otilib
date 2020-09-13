#ifndef OTI_MDNUM10_ARRAY_ALGEBRA_MATOPS_H
#define OTI_MDNUM10_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdarr10_dotproduct_OO(    mdarr10_t* lhs, mdarr10_t* rhs);
void      mdarr10_dotproduct_OO_to( mdarr10_t* lhs, mdarr10_t* rhs, mdnum10_t* res);

mdnum10_t mdarr10_dotproduct_RO(     darr_t* lhs, mdarr10_t* rhs);
void      mdarr10_dotproduct_RO_to(  darr_t* lhs, mdarr10_t* rhs, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr10_t mdarr10_matmul_OO(    mdarr10_t* lhs, mdarr10_t* rhs);
mdarr10_t mdarr10_matmul_OR(    mdarr10_t* lhs,  darr_t* rhs);
mdarr10_t mdarr10_matmul_RO(     darr_t* lhs, mdarr10_t* rhs);

void    mdarr10_matmul_OO_to( mdarr10_t* lhs, mdarr10_t* rhs, mdarr10_t* res);
void    mdarr10_matmul_OR_to( mdarr10_t* lhs,  darr_t* rhs, mdarr10_t* res);
void    mdarr10_matmul_RO_to(  darr_t* lhs, mdarr10_t* rhs, mdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr10_t mdarr10_transpose(    mdarr10_t* arr1);
void    mdarr10_transpose_to( mdarr10_t* arr1, mdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr10_t mdarr10_invert(    mdarr10_t* arr1);
void    mdarr10_invert_to( mdarr10_t* arr1, mdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdarr10_det(    mdarr10_t* arr1);
void      mdarr10_det_to( mdarr10_t* arr1, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdarr10_norm(    mdarr10_t* arr1);
void      mdarr10_norm_to( mdarr10_t* arr1,  mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdarr10_pnorm(    mdarr10_t* arr1, coeff_t p);
void      mdarr10_pnorm_to( mdarr10_t* arr1, coeff_t p, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif