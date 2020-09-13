#ifndef OTI_MDNUM8_ARRAY_ALGEBRA_MATOPS_H
#define OTI_MDNUM8_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdarr8_dotproduct_OO(    mdarr8_t* lhs, mdarr8_t* rhs);
void      mdarr8_dotproduct_OO_to( mdarr8_t* lhs, mdarr8_t* rhs, mdnum8_t* res);

mdnum8_t mdarr8_dotproduct_RO(     darr_t* lhs, mdarr8_t* rhs);
void      mdarr8_dotproduct_RO_to(  darr_t* lhs, mdarr8_t* rhs, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr8_t mdarr8_matmul_OO(    mdarr8_t* lhs, mdarr8_t* rhs);
mdarr8_t mdarr8_matmul_OR(    mdarr8_t* lhs,  darr_t* rhs);
mdarr8_t mdarr8_matmul_RO(     darr_t* lhs, mdarr8_t* rhs);

void    mdarr8_matmul_OO_to( mdarr8_t* lhs, mdarr8_t* rhs, mdarr8_t* res);
void    mdarr8_matmul_OR_to( mdarr8_t* lhs,  darr_t* rhs, mdarr8_t* res);
void    mdarr8_matmul_RO_to(  darr_t* lhs, mdarr8_t* rhs, mdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr8_t mdarr8_transpose(    mdarr8_t* arr1);
void    mdarr8_transpose_to( mdarr8_t* arr1, mdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr8_t mdarr8_invert(    mdarr8_t* arr1);
void    mdarr8_invert_to( mdarr8_t* arr1, mdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdarr8_det(    mdarr8_t* arr1);
void      mdarr8_det_to( mdarr8_t* arr1, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdarr8_norm(    mdarr8_t* arr1);
void      mdarr8_norm_to( mdarr8_t* arr1,  mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdarr8_pnorm(    mdarr8_t* arr1, coeff_t p);
void      mdarr8_pnorm_to( mdarr8_t* arr1, coeff_t p, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif