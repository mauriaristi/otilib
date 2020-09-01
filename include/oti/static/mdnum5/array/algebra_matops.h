#ifndef OTI_MDNUM5_ARRAY_ALGEBRA_MATOPS_H
#define OTI_MDNUM5_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdarr5_dotproduct_OO(    mdarr5_t* lhs, mdarr5_t* rhs);
void      mdarr5_dotproduct_OO_to( mdarr5_t* lhs, mdarr5_t* rhs, mdnum5_t* res);

mdnum5_t mdarr5_dotproduct_RO(     darr_t* lhs, mdarr5_t* rhs);
void      mdarr5_dotproduct_RO_to(  darr_t* lhs, mdarr5_t* rhs, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr5_t mdarr5_matmul_OO(    mdarr5_t* lhs, mdarr5_t* rhs);
mdarr5_t mdarr5_matmul_OR(    mdarr5_t* lhs,  darr_t* rhs);
mdarr5_t mdarr5_matmul_RO(     darr_t* lhs, mdarr5_t* rhs);

void    mdarr5_matmul_OO_to( mdarr5_t* lhs, mdarr5_t* rhs, mdarr5_t* res);
void    mdarr5_matmul_OR_to( mdarr5_t* lhs,  darr_t* rhs, mdarr5_t* res);
void    mdarr5_matmul_RO_to(  darr_t* lhs, mdarr5_t* rhs, mdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr5_t mdarr5_transpose(    mdarr5_t* arr1);
void    mdarr5_transpose_to( mdarr5_t* arr1, mdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr5_t mdarr5_invert(    mdarr5_t* arr1);
void    mdarr5_invert_to( mdarr5_t* arr1, mdarr5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdarr5_det(    mdarr5_t* arr1);
void      mdarr5_det_to( mdarr5_t* arr1, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdarr5_norm(    mdarr5_t* arr1);
void      mdarr5_norm_to( mdarr5_t* arr1,  mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdarr5_pnorm(    mdarr5_t* arr1, coeff_t p);
void      mdarr5_pnorm_to( mdarr5_t* arr1, coeff_t p, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif