#ifndef OTI_MDNUM4_ARRAY_ALGEBRA_MATOPS_H
#define OTI_MDNUM4_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdarr4_dotproduct_OO(    mdarr4_t* lhs, mdarr4_t* rhs);
void      mdarr4_dotproduct_OO_to( mdarr4_t* lhs, mdarr4_t* rhs, mdnum4_t* res);

mdnum4_t mdarr4_dotproduct_RO(     darr_t* lhs, mdarr4_t* rhs);
void      mdarr4_dotproduct_RO_to(  darr_t* lhs, mdarr4_t* rhs, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr4_t mdarr4_matmul_OO(    mdarr4_t* lhs, mdarr4_t* rhs);
mdarr4_t mdarr4_matmul_OR(    mdarr4_t* lhs,  darr_t* rhs);
mdarr4_t mdarr4_matmul_RO(     darr_t* lhs, mdarr4_t* rhs);

void    mdarr4_matmul_OO_to( mdarr4_t* lhs, mdarr4_t* rhs, mdarr4_t* res);
void    mdarr4_matmul_OR_to( mdarr4_t* lhs,  darr_t* rhs, mdarr4_t* res);
void    mdarr4_matmul_RO_to(  darr_t* lhs, mdarr4_t* rhs, mdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr4_t mdarr4_transpose(    mdarr4_t* arr1);
void    mdarr4_transpose_to( mdarr4_t* arr1, mdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr4_t mdarr4_invert(    mdarr4_t* arr1);
void    mdarr4_invert_to( mdarr4_t* arr1, mdarr4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdarr4_det(    mdarr4_t* arr1);
void      mdarr4_det_to( mdarr4_t* arr1, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdarr4_norm(    mdarr4_t* arr1);
void      mdarr4_norm_to( mdarr4_t* arr1,  mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdarr4_pnorm(    mdarr4_t* arr1, coeff_t p);
void      mdarr4_pnorm_to( mdarr4_t* arr1, coeff_t p, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif