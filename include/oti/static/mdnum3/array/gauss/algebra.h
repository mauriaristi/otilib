#ifndef OTI_MDNUM3_ARRAY_GAUSS_ALGEBRA_H
#define OTI_MDNUM3_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_neg(    femdarr3_t* arr);
void      femdarr3_neg_to( femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_sum_FF(   femdarr3_t* lhs, femdarr3_t* rhs);
void      femdarr3_sum_FF_to(femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sum_fF(    femdnum3_t* lhs, femdarr3_t* rhs);
void      femdarr3_sum_fF_to( femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sum_OF(     mdarr3_t* lhs, femdarr3_t* rhs);
void      femdarr3_sum_OF_to(  mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sum_RF(      darr_t* lhs, femdarr3_t* rhs);
void      femdarr3_sum_RF_to(   darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sum_oF(   mdnum3_t* lhs, femdarr3_t* rhs);
void      femdarr3_sum_oF_to(mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sum_rF(     coeff_t  lhs, femdarr3_t* rhs);
void      femdarr3_sum_rF_to(  coeff_t  lhs, femdarr3_t* rhs, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_sub_FF(    femdarr3_t* lhs, femdarr3_t* rhs);
void      femdarr3_sub_FF_to( femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sub_fF(    femdnum3_t* lhs, femdarr3_t* rhs);
void      femdarr3_sub_fF_to( femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sub_Ff(    femdarr3_t* lhs, femdnum3_t* rhs);
void      femdarr3_sub_Ff_to( femdarr3_t* lhs, femdnum3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sub_OF(      mdarr3_t* lhs, femdarr3_t* rhs);
void      femdarr3_sub_OF_to(   mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sub_FO(    femdarr3_t* lhs,   mdarr3_t* rhs);
void      femdarr3_sub_FO_to( femdarr3_t* lhs,   mdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sub_RF(       darr_t* lhs, femdarr3_t* rhs);
void      femdarr3_sub_RF_to(    darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sub_FR(    femdarr3_t* lhs,    darr_t* rhs);
void      femdarr3_sub_FR_to( femdarr3_t* lhs,    darr_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sub_oF(    mdnum3_t* lhs, femdarr3_t* rhs);
void      femdarr3_sub_oF_to( mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sub_Fo(    femdarr3_t* lhs, mdnum3_t* rhs);
void      femdarr3_sub_Fo_to( femdarr3_t* lhs, mdnum3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sub_rF(      coeff_t  lhs, femdarr3_t* rhs);
void      femdarr3_sub_rF_to(    coeff_t lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_sub_Fr(    femdarr3_t* lhs,   coeff_t  rhs);
void      femdarr3_sub_Fr_to( femdarr3_t* lhs,   coeff_t  rhs, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_mul_FF(   femdarr3_t* lhs, femdarr3_t* rhs);
void      femdarr3_mul_FF_to(femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_mul_fF(    femdnum3_t* lhs, femdarr3_t* rhs);
void      femdarr3_mul_fF_to( femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_mul_OF(     mdarr3_t* lhs, femdarr3_t* rhs);
void      femdarr3_mul_OF_to(  mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_mul_RF(      darr_t* lhs, femdarr3_t* rhs);
void      femdarr3_mul_RF_to(   darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_mul_oF(   mdnum3_t* lhs, femdarr3_t* rhs);
void      femdarr3_mul_oF_to(mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_mul_rF(     coeff_t  lhs, femdarr3_t* rhs);
void      femdarr3_mul_rF_to(  coeff_t  lhs, femdarr3_t* rhs, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr3_t femdarr3_div_FF(    femdarr3_t* lhs, femdarr3_t* rhs);
void      femdarr3_div_FF_to( femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_div_fF(     femdnum3_t* lhs, femdarr3_t* rhs);
void      femdarr3_div_fF_to(  femdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_div_Ff(    femdarr3_t* lhs,  femdnum3_t* rhs);
void      femdarr3_div_Ff_to( femdarr3_t* lhs,  femdnum3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_div_OF(      mdarr3_t* lhs, femdarr3_t* rhs);
void      femdarr3_div_OF_to(   mdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_div_FO(    femdarr3_t* lhs,   mdarr3_t* rhs);
void      femdarr3_div_FO_to( femdarr3_t* lhs,   mdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_div_RF(       darr_t* lhs, femdarr3_t* rhs);
void      femdarr3_div_RF_to(    darr_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_div_FR(    femdarr3_t* lhs,    darr_t* rhs);
void      femdarr3_div_FR_to( femdarr3_t* lhs,    darr_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_div_oF(    mdnum3_t* lhs, femdarr3_t* rhs);
void      femdarr3_div_oF_to( mdnum3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_div_Fo(    femdarr3_t* lhs, mdnum3_t* rhs);
void      femdarr3_div_Fo_to( femdarr3_t* lhs, mdnum3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_div_rF(      coeff_t  lhs, femdarr3_t* rhs);
void      femdarr3_div_rF_to(    coeff_t lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_div_Fr(    femdarr3_t* lhs,   coeff_t  rhs);
void      femdarr3_div_Fr_to( femdarr3_t* lhs,   coeff_t  rhs, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdarr3_t femdarr3_integrate(    femdarr3_t* arr, femdnum3_t* w);
void    femdarr3_integrate_to( femdarr3_t* arr, femdnum3_t* w, mdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

// VECTOR ALGEBRA

/**************************************************************************************************//**
@brief Dot product between two vectors

RES = DOT_PRODUCT( LHS, RHS )

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res result
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum3_t femdarr3_dotproduct_FF(    femdarr3_t* lhs, femdarr3_t* rhs);
void     femdarr3_dotproduct_FF_to( femdarr3_t* lhs, femdarr3_t* rhs, femdnum3_t* res);

femdnum3_t femdarr3_dotproduct_OF(      mdarr3_t* lhs, femdarr3_t* rhs);
void     femdarr3_dotproduct_OF_to(   mdarr3_t* lhs, femdarr3_t* rhs, femdnum3_t* res);

femdnum3_t femdarr3_dotproduct_RF(       darr_t* lhs, femdarr3_t* rhs);
void     femdarr3_dotproduct_RF_to(    darr_t* lhs, femdarr3_t* rhs, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

// MATRIX ALGEBRA.

/**************************************************************************************************//**
@brief Matrix multiplication

RES = MATMUL( LHS, RHS )

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res result
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr3_t femdarr3_matmul_FF(    femdarr3_t* lhs, femdarr3_t* rhs);
void      femdarr3_matmul_FF_to( femdarr3_t* lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_matmul_OF(    mdarr3_t*   lhs, femdarr3_t* rhs);
void      femdarr3_matmul_OF_to( mdarr3_t*   lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_matmul_FO(    femdarr3_t* lhs, mdarr3_t*   rhs);
void      femdarr3_matmul_FO_to( femdarr3_t* lhs, mdarr3_t*   rhs, femdarr3_t* res);

femdarr3_t femdarr3_matmul_RF(    darr_t*    lhs, femdarr3_t* rhs);
void      femdarr3_matmul_RF_to( darr_t*    lhs, femdarr3_t* rhs, femdarr3_t* res);

femdarr3_t femdarr3_matmul_FR(    femdarr3_t* lhs, darr_t*    rhs);
void      femdarr3_matmul_FR_to( femdarr3_t* lhs, darr_t*    rhs, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum3_t femdarr3_det(   femdarr3_t* arr);
void     femdarr3_det_to(femdarr3_t* arr, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum3_t femdarr3_norm(     femdarr3_t* arr);
void     femdarr3_norm_to(  femdarr3_t* arr, femdnum3_t* res);

femdnum3_t femdarr3_pnorm(    femdarr3_t* arr, coeff_t p);
void     femdarr3_pnorm_to( femdarr3_t* arr, coeff_t p, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr3_t   femdarr3_invert(    femdarr3_t* arr);
void        femdarr3_invert_to( femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr3_t   femdarr3_transpose(   femdarr3_t* arr);
void        femdarr3_transpose_to(femdarr3_t* arr, femdarr3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif