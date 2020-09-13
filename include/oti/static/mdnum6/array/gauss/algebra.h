#ifndef OTI_MDNUM6_ARRAY_GAUSS_ALGEBRA_H
#define OTI_MDNUM6_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr6_t femdarr6_neg(    femdarr6_t* arr);
void      femdarr6_neg_to( femdarr6_t* arr, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr6_t femdarr6_sum_FF(   femdarr6_t* lhs, femdarr6_t* rhs);
void      femdarr6_sum_FF_to(femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sum_fF(    femdnum6_t* lhs, femdarr6_t* rhs);
void      femdarr6_sum_fF_to( femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sum_OF(     mdarr6_t* lhs, femdarr6_t* rhs);
void      femdarr6_sum_OF_to(  mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sum_RF(      darr_t* lhs, femdarr6_t* rhs);
void      femdarr6_sum_RF_to(   darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sum_oF(   mdnum6_t* lhs, femdarr6_t* rhs);
void      femdarr6_sum_oF_to(mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sum_rF(     coeff_t  lhs, femdarr6_t* rhs);
void      femdarr6_sum_rF_to(  coeff_t  lhs, femdarr6_t* rhs, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr6_t femdarr6_sub_FF(    femdarr6_t* lhs, femdarr6_t* rhs);
void      femdarr6_sub_FF_to( femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sub_fF(    femdnum6_t* lhs, femdarr6_t* rhs);
void      femdarr6_sub_fF_to( femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sub_Ff(    femdarr6_t* lhs, femdnum6_t* rhs);
void      femdarr6_sub_Ff_to( femdarr6_t* lhs, femdnum6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sub_OF(      mdarr6_t* lhs, femdarr6_t* rhs);
void      femdarr6_sub_OF_to(   mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sub_FO(    femdarr6_t* lhs,   mdarr6_t* rhs);
void      femdarr6_sub_FO_to( femdarr6_t* lhs,   mdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sub_RF(       darr_t* lhs, femdarr6_t* rhs);
void      femdarr6_sub_RF_to(    darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sub_FR(    femdarr6_t* lhs,    darr_t* rhs);
void      femdarr6_sub_FR_to( femdarr6_t* lhs,    darr_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sub_oF(    mdnum6_t* lhs, femdarr6_t* rhs);
void      femdarr6_sub_oF_to( mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sub_Fo(    femdarr6_t* lhs, mdnum6_t* rhs);
void      femdarr6_sub_Fo_to( femdarr6_t* lhs, mdnum6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sub_rF(      coeff_t  lhs, femdarr6_t* rhs);
void      femdarr6_sub_rF_to(    coeff_t lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_sub_Fr(    femdarr6_t* lhs,   coeff_t  rhs);
void      femdarr6_sub_Fr_to( femdarr6_t* lhs,   coeff_t  rhs, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr6_t femdarr6_mul_FF(   femdarr6_t* lhs, femdarr6_t* rhs);
void      femdarr6_mul_FF_to(femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_mul_fF(    femdnum6_t* lhs, femdarr6_t* rhs);
void      femdarr6_mul_fF_to( femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_mul_OF(     mdarr6_t* lhs, femdarr6_t* rhs);
void      femdarr6_mul_OF_to(  mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_mul_RF(      darr_t* lhs, femdarr6_t* rhs);
void      femdarr6_mul_RF_to(   darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_mul_oF(   mdnum6_t* lhs, femdarr6_t* rhs);
void      femdarr6_mul_oF_to(mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_mul_rF(     coeff_t  lhs, femdarr6_t* rhs);
void      femdarr6_mul_rF_to(  coeff_t  lhs, femdarr6_t* rhs, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr6_t femdarr6_div_FF(    femdarr6_t* lhs, femdarr6_t* rhs);
void      femdarr6_div_FF_to( femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_div_fF(     femdnum6_t* lhs, femdarr6_t* rhs);
void      femdarr6_div_fF_to(  femdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_div_Ff(    femdarr6_t* lhs,  femdnum6_t* rhs);
void      femdarr6_div_Ff_to( femdarr6_t* lhs,  femdnum6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_div_OF(      mdarr6_t* lhs, femdarr6_t* rhs);
void      femdarr6_div_OF_to(   mdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_div_FO(    femdarr6_t* lhs,   mdarr6_t* rhs);
void      femdarr6_div_FO_to( femdarr6_t* lhs,   mdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_div_RF(       darr_t* lhs, femdarr6_t* rhs);
void      femdarr6_div_RF_to(    darr_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_div_FR(    femdarr6_t* lhs,    darr_t* rhs);
void      femdarr6_div_FR_to( femdarr6_t* lhs,    darr_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_div_oF(    mdnum6_t* lhs, femdarr6_t* rhs);
void      femdarr6_div_oF_to( mdnum6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_div_Fo(    femdarr6_t* lhs, mdnum6_t* rhs);
void      femdarr6_div_Fo_to( femdarr6_t* lhs, mdnum6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_div_rF(      coeff_t  lhs, femdarr6_t* rhs);
void      femdarr6_div_rF_to(    coeff_t lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_div_Fr(    femdarr6_t* lhs,   coeff_t  rhs);
void      femdarr6_div_Fr_to( femdarr6_t* lhs,   coeff_t  rhs, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdarr6_t femdarr6_integrate(    femdarr6_t* arr, femdnum6_t* w);
void    femdarr6_integrate_to( femdarr6_t* arr, femdnum6_t* w, mdarr6_t* res);
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
femdnum6_t femdarr6_dotproduct_FF(    femdarr6_t* lhs, femdarr6_t* rhs);
void     femdarr6_dotproduct_FF_to( femdarr6_t* lhs, femdarr6_t* rhs, femdnum6_t* res);

femdnum6_t femdarr6_dotproduct_OF(      mdarr6_t* lhs, femdarr6_t* rhs);
void     femdarr6_dotproduct_OF_to(   mdarr6_t* lhs, femdarr6_t* rhs, femdnum6_t* res);

femdnum6_t femdarr6_dotproduct_RF(       darr_t* lhs, femdarr6_t* rhs);
void     femdarr6_dotproduct_RF_to(    darr_t* lhs, femdarr6_t* rhs, femdnum6_t* res);
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
femdarr6_t femdarr6_matmul_FF(    femdarr6_t* lhs, femdarr6_t* rhs);
void      femdarr6_matmul_FF_to( femdarr6_t* lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_matmul_OF(    mdarr6_t*   lhs, femdarr6_t* rhs);
void      femdarr6_matmul_OF_to( mdarr6_t*   lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_matmul_FO(    femdarr6_t* lhs, mdarr6_t*   rhs);
void      femdarr6_matmul_FO_to( femdarr6_t* lhs, mdarr6_t*   rhs, femdarr6_t* res);

femdarr6_t femdarr6_matmul_RF(    darr_t*    lhs, femdarr6_t* rhs);
void      femdarr6_matmul_RF_to( darr_t*    lhs, femdarr6_t* rhs, femdarr6_t* res);

femdarr6_t femdarr6_matmul_FR(    femdarr6_t* lhs, darr_t*    rhs);
void      femdarr6_matmul_FR_to( femdarr6_t* lhs, darr_t*    rhs, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum6_t femdarr6_det(   femdarr6_t* arr);
void     femdarr6_det_to(femdarr6_t* arr, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum6_t femdarr6_norm(     femdarr6_t* arr);
void     femdarr6_norm_to(  femdarr6_t* arr, femdnum6_t* res);

femdnum6_t femdarr6_pnorm(    femdarr6_t* arr, coeff_t p);
void     femdarr6_pnorm_to( femdarr6_t* arr, coeff_t p, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr6_t   femdarr6_invert(    femdarr6_t* arr);
void        femdarr6_invert_to( femdarr6_t* arr, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr6_t   femdarr6_transpose(   femdarr6_t* arr);
void        femdarr6_transpose_to(femdarr6_t* arr, femdarr6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif