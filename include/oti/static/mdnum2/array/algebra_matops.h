#ifndef OTI_MDNUM2_ARRAY_ALGEBRA_MATOPS_H
#define OTI_MDNUM2_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdarr2_dotproduct_OO(    mdarr2_t* lhs, mdarr2_t* rhs);
void      mdarr2_dotproduct_OO_to( mdarr2_t* lhs, mdarr2_t* rhs, mdnum2_t* res);

mdnum2_t mdarr2_dotproduct_RO(     darr_t* lhs, mdarr2_t* rhs);
void      mdarr2_dotproduct_RO_to(  darr_t* lhs, mdarr2_t* rhs, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr2_t mdarr2_matmul_OO(    mdarr2_t* lhs, mdarr2_t* rhs);
mdarr2_t mdarr2_matmul_OR(    mdarr2_t* lhs,  darr_t* rhs);
mdarr2_t mdarr2_matmul_RO(     darr_t* lhs, mdarr2_t* rhs);

void    mdarr2_matmul_OO_to( mdarr2_t* lhs, mdarr2_t* rhs, mdarr2_t* res);
void    mdarr2_matmul_OR_to( mdarr2_t* lhs,  darr_t* rhs, mdarr2_t* res);
void    mdarr2_matmul_RO_to(  darr_t* lhs, mdarr2_t* rhs, mdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr2_t mdarr2_transpose(    mdarr2_t* arr1);
void    mdarr2_transpose_to( mdarr2_t* arr1, mdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr2_t mdarr2_invert(    mdarr2_t* arr1);
void    mdarr2_invert_to( mdarr2_t* arr1, mdarr2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdarr2_det(    mdarr2_t* arr1);
void      mdarr2_det_to( mdarr2_t* arr1, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdarr2_norm(    mdarr2_t* arr1);
void      mdarr2_norm_to( mdarr2_t* arr1,  mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdarr2_pnorm(    mdarr2_t* arr1, coeff_t p);
void      mdarr2_pnorm_to( mdarr2_t* arr1, coeff_t p, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif