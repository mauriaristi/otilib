#ifndef OTI_MDNUM10_ARRAY_GAUSS_ALGEBRA_H
#define OTI_MDNUM10_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr10_t femdarr10_neg(    femdarr10_t* arr);
void      femdarr10_neg_to( femdarr10_t* arr, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr10_t femdarr10_sum_FF(   femdarr10_t* lhs, femdarr10_t* rhs);
void      femdarr10_sum_FF_to(femdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sum_fF(    femdnum10_t* lhs, femdarr10_t* rhs);
void      femdarr10_sum_fF_to( femdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sum_OF(     mdarr10_t* lhs, femdarr10_t* rhs);
void      femdarr10_sum_OF_to(  mdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sum_RF(      darr_t* lhs, femdarr10_t* rhs);
void      femdarr10_sum_RF_to(   darr_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sum_oF(   mdnum10_t* lhs, femdarr10_t* rhs);
void      femdarr10_sum_oF_to(mdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sum_rF(     coeff_t  lhs, femdarr10_t* rhs);
void      femdarr10_sum_rF_to(  coeff_t  lhs, femdarr10_t* rhs, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr10_t femdarr10_sub_FF(    femdarr10_t* lhs, femdarr10_t* rhs);
void      femdarr10_sub_FF_to( femdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sub_fF(    femdnum10_t* lhs, femdarr10_t* rhs);
void      femdarr10_sub_fF_to( femdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sub_Ff(    femdarr10_t* lhs, femdnum10_t* rhs);
void      femdarr10_sub_Ff_to( femdarr10_t* lhs, femdnum10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sub_OF(      mdarr10_t* lhs, femdarr10_t* rhs);
void      femdarr10_sub_OF_to(   mdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sub_FO(    femdarr10_t* lhs,   mdarr10_t* rhs);
void      femdarr10_sub_FO_to( femdarr10_t* lhs,   mdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sub_RF(       darr_t* lhs, femdarr10_t* rhs);
void      femdarr10_sub_RF_to(    darr_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sub_FR(    femdarr10_t* lhs,    darr_t* rhs);
void      femdarr10_sub_FR_to( femdarr10_t* lhs,    darr_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sub_oF(    mdnum10_t* lhs, femdarr10_t* rhs);
void      femdarr10_sub_oF_to( mdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sub_Fo(    femdarr10_t* lhs, mdnum10_t* rhs);
void      femdarr10_sub_Fo_to( femdarr10_t* lhs, mdnum10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sub_rF(      coeff_t  lhs, femdarr10_t* rhs);
void      femdarr10_sub_rF_to(    coeff_t lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_sub_Fr(    femdarr10_t* lhs,   coeff_t  rhs);
void      femdarr10_sub_Fr_to( femdarr10_t* lhs,   coeff_t  rhs, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr10_t femdarr10_mul_FF(   femdarr10_t* lhs, femdarr10_t* rhs);
void      femdarr10_mul_FF_to(femdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_mul_fF(    femdnum10_t* lhs, femdarr10_t* rhs);
void      femdarr10_mul_fF_to( femdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_mul_OF(     mdarr10_t* lhs, femdarr10_t* rhs);
void      femdarr10_mul_OF_to(  mdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_mul_RF(      darr_t* lhs, femdarr10_t* rhs);
void      femdarr10_mul_RF_to(   darr_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_mul_oF(   mdnum10_t* lhs, femdarr10_t* rhs);
void      femdarr10_mul_oF_to(mdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_mul_rF(     coeff_t  lhs, femdarr10_t* rhs);
void      femdarr10_mul_rF_to(  coeff_t  lhs, femdarr10_t* rhs, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr10_t femdarr10_div_FF(    femdarr10_t* lhs, femdarr10_t* rhs);
void      femdarr10_div_FF_to( femdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_div_fF(     femdnum10_t* lhs, femdarr10_t* rhs);
void      femdarr10_div_fF_to(  femdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_div_Ff(    femdarr10_t* lhs,  femdnum10_t* rhs);
void      femdarr10_div_Ff_to( femdarr10_t* lhs,  femdnum10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_div_OF(      mdarr10_t* lhs, femdarr10_t* rhs);
void      femdarr10_div_OF_to(   mdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_div_FO(    femdarr10_t* lhs,   mdarr10_t* rhs);
void      femdarr10_div_FO_to( femdarr10_t* lhs,   mdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_div_RF(       darr_t* lhs, femdarr10_t* rhs);
void      femdarr10_div_RF_to(    darr_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_div_FR(    femdarr10_t* lhs,    darr_t* rhs);
void      femdarr10_div_FR_to( femdarr10_t* lhs,    darr_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_div_oF(    mdnum10_t* lhs, femdarr10_t* rhs);
void      femdarr10_div_oF_to( mdnum10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_div_Fo(    femdarr10_t* lhs, mdnum10_t* rhs);
void      femdarr10_div_Fo_to( femdarr10_t* lhs, mdnum10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_div_rF(      coeff_t  lhs, femdarr10_t* rhs);
void      femdarr10_div_rF_to(    coeff_t lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_div_Fr(    femdarr10_t* lhs,   coeff_t  rhs);
void      femdarr10_div_Fr_to( femdarr10_t* lhs,   coeff_t  rhs, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdarr10_t femdarr10_integrate(    femdarr10_t* arr, femdnum10_t* w);
void    femdarr10_integrate_to( femdarr10_t* arr, femdnum10_t* w, mdarr10_t* res);
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
femdnum10_t femdarr10_dotproduct_FF(    femdarr10_t* lhs, femdarr10_t* rhs);
void     femdarr10_dotproduct_FF_to( femdarr10_t* lhs, femdarr10_t* rhs, femdnum10_t* res);

femdnum10_t femdarr10_dotproduct_OF(      mdarr10_t* lhs, femdarr10_t* rhs);
void     femdarr10_dotproduct_OF_to(   mdarr10_t* lhs, femdarr10_t* rhs, femdnum10_t* res);

femdnum10_t femdarr10_dotproduct_RF(       darr_t* lhs, femdarr10_t* rhs);
void     femdarr10_dotproduct_RF_to(    darr_t* lhs, femdarr10_t* rhs, femdnum10_t* res);
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
femdarr10_t femdarr10_matmul_FF(    femdarr10_t* lhs, femdarr10_t* rhs);
void      femdarr10_matmul_FF_to( femdarr10_t* lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_matmul_OF(    mdarr10_t*   lhs, femdarr10_t* rhs);
void      femdarr10_matmul_OF_to( mdarr10_t*   lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_matmul_FO(    femdarr10_t* lhs, mdarr10_t*   rhs);
void      femdarr10_matmul_FO_to( femdarr10_t* lhs, mdarr10_t*   rhs, femdarr10_t* res);

femdarr10_t femdarr10_matmul_RF(    darr_t*    lhs, femdarr10_t* rhs);
void      femdarr10_matmul_RF_to( darr_t*    lhs, femdarr10_t* rhs, femdarr10_t* res);

femdarr10_t femdarr10_matmul_FR(    femdarr10_t* lhs, darr_t*    rhs);
void      femdarr10_matmul_FR_to( femdarr10_t* lhs, darr_t*    rhs, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum10_t femdarr10_det(   femdarr10_t* arr);
void     femdarr10_det_to(femdarr10_t* arr, femdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum10_t femdarr10_norm(     femdarr10_t* arr);
void     femdarr10_norm_to(  femdarr10_t* arr, femdnum10_t* res);

femdnum10_t femdarr10_pnorm(    femdarr10_t* arr, coeff_t p);
void     femdarr10_pnorm_to( femdarr10_t* arr, coeff_t p, femdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr10_t   femdarr10_invert(    femdarr10_t* arr);
void        femdarr10_invert_to( femdarr10_t* arr, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr10_t   femdarr10_transpose(   femdarr10_t* arr);
void        femdarr10_transpose_to(femdarr10_t* arr, femdarr10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif