#ifndef OTI_MDNUM1_ARRAY_ALGEBRA_MATOPS_H
#define OTI_MDNUM1_ARRAY_ALGEBRA_MATOPS_H

/**************************************************************************************************//**
@brief Vector dot product

RES  = DOT_PRODUCT( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdarr1_dotproduct_OO(    mdarr1_t* lhs, mdarr1_t* rhs);
void      mdarr1_dotproduct_OO_to( mdarr1_t* lhs, mdarr1_t* rhs, mdnum1_t* res);

mdnum1_t mdarr1_dotproduct_RO(     darr_t* lhs, mdarr1_t* rhs);
void      mdarr1_dotproduct_RO_to(  darr_t* lhs, mdarr1_t* rhs, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix multiplication.

RES  = MATMUL( LHS,  RHS)

@param[in] lhs    Left hand side array.
@param[in] rhs    Right hand side array.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr1_t mdarr1_matmul_OO(    mdarr1_t* lhs, mdarr1_t* rhs);
mdarr1_t mdarr1_matmul_OR(    mdarr1_t* lhs,  darr_t* rhs);
mdarr1_t mdarr1_matmul_RO(     darr_t* lhs, mdarr1_t* rhs);

void    mdarr1_matmul_OO_to( mdarr1_t* lhs, mdarr1_t* rhs, mdarr1_t* res);
void    mdarr1_matmul_OR_to( mdarr1_t* lhs,  darr_t* rhs, mdarr1_t* res);
void    mdarr1_matmul_RO_to(  darr_t* lhs, mdarr1_t* rhs, mdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix transpose.

RES  = TRANSPOSE( ARR1 )

@param[in] arr1   Array to be transposed
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr1_t mdarr1_transpose(    mdarr1_t* arr1);
void    mdarr1_transpose_to( mdarr1_t* arr1, mdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES  = INVERSE( ARR1 )

@param[in] arr1   Array to be inverted.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdarr1_t mdarr1_invert(    mdarr1_t* arr1);
void    mdarr1_invert_to( mdarr1_t* arr1, mdarr1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

RES  = DET( ARR1 )

@param[in] arr1   Array to compute determinant.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdarr1_det(    mdarr1_t* arr1);
void      mdarr1_det_to( mdarr1_t* arr1, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Norm.

RES  = NORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdarr1_norm(    mdarr1_t* arr1);
void      mdarr1_norm_to( mdarr1_t* arr1,  mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-Norm for "vector".

RES  = PNORM( ARR1 )

@param[in] arr1   Array to compute norm.
@param[in] p      P-value of norm.
@param[in] dhl    Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdarr1_pnorm(    mdarr1_t* arr1, coeff_t p);
void      mdarr1_pnorm_to( mdarr1_t* arr1, coeff_t p, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif