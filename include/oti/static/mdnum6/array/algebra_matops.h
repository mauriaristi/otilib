#ifndef OTI_MDNUM6_ARRAY_ALGEBRA_MATOPS_H
#define OTI_MDNUM6_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdarr6_dotproduct_OO(    mdarr6_t* lhs, mdarr6_t* rhs);
void      mdarr6_dotproduct_OO_to( mdarr6_t* lhs, mdarr6_t* rhs, mdnum6_t* res);

mdnum6_t mdarr6_dotproduct_RO(     darr_t* lhs, mdarr6_t* rhs);
void      mdarr6_dotproduct_RO_to(  darr_t* lhs, mdarr6_t* rhs, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr6_t mdarr6_matmul_OO(    mdarr6_t* lhs, mdarr6_t* rhs);
mdarr6_t mdarr6_matmul_OR(    mdarr6_t* lhs,  darr_t* rhs);
mdarr6_t mdarr6_matmul_RO(     darr_t* lhs, mdarr6_t* rhs);

void    mdarr6_matmul_OO_to( mdarr6_t* lhs, mdarr6_t* rhs, mdarr6_t* res);
void    mdarr6_matmul_OR_to( mdarr6_t* lhs,  darr_t* rhs, mdarr6_t* res);
void    mdarr6_matmul_RO_to(  darr_t* lhs, mdarr6_t* rhs, mdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr6_t mdarr6_transpose(    mdarr6_t* arr1);
void    mdarr6_transpose_to( mdarr6_t* arr1, mdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr6_t mdarr6_invert(    mdarr6_t* arr1);
void    mdarr6_invert_to( mdarr6_t* arr1, mdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdarr6_det(    mdarr6_t* arr1);
void      mdarr6_det_to( mdarr6_t* arr1, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdarr6_norm(    mdarr6_t* arr1);
void      mdarr6_norm_to( mdarr6_t* arr1,  mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdarr6_pnorm(    mdarr6_t* arr1, coeff_t p);
void      mdarr6_pnorm_to( mdarr6_t* arr1, coeff_t p, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif