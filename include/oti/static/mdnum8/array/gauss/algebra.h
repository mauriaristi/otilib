#ifndef OTI_MDNUM8_ARRAY_GAUSS_ALGEBRA_H
#define OTI_MDNUM8_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr8_t femdarr8_neg(    femdarr8_t* arr);
void      femdarr8_neg_to( femdarr8_t* arr, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr8_t femdarr8_sum_FF(   femdarr8_t* lhs, femdarr8_t* rhs);
void      femdarr8_sum_FF_to(femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sum_fF(    femdnum8_t* lhs, femdarr8_t* rhs);
void      femdarr8_sum_fF_to( femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sum_OF(     mdarr8_t* lhs, femdarr8_t* rhs);
void      femdarr8_sum_OF_to(  mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sum_RF(      darr_t* lhs, femdarr8_t* rhs);
void      femdarr8_sum_RF_to(   darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sum_oF(   mdnum8_t* lhs, femdarr8_t* rhs);
void      femdarr8_sum_oF_to(mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sum_rF(     coeff_t  lhs, femdarr8_t* rhs);
void      femdarr8_sum_rF_to(  coeff_t  lhs, femdarr8_t* rhs, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr8_t femdarr8_sub_FF(    femdarr8_t* lhs, femdarr8_t* rhs);
void      femdarr8_sub_FF_to( femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sub_fF(    femdnum8_t* lhs, femdarr8_t* rhs);
void      femdarr8_sub_fF_to( femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sub_Ff(    femdarr8_t* lhs, femdnum8_t* rhs);
void      femdarr8_sub_Ff_to( femdarr8_t* lhs, femdnum8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sub_OF(      mdarr8_t* lhs, femdarr8_t* rhs);
void      femdarr8_sub_OF_to(   mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sub_FO(    femdarr8_t* lhs,   mdarr8_t* rhs);
void      femdarr8_sub_FO_to( femdarr8_t* lhs,   mdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sub_RF(       darr_t* lhs, femdarr8_t* rhs);
void      femdarr8_sub_RF_to(    darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sub_FR(    femdarr8_t* lhs,    darr_t* rhs);
void      femdarr8_sub_FR_to( femdarr8_t* lhs,    darr_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sub_oF(    mdnum8_t* lhs, femdarr8_t* rhs);
void      femdarr8_sub_oF_to( mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sub_Fo(    femdarr8_t* lhs, mdnum8_t* rhs);
void      femdarr8_sub_Fo_to( femdarr8_t* lhs, mdnum8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sub_rF(      coeff_t  lhs, femdarr8_t* rhs);
void      femdarr8_sub_rF_to(    coeff_t lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_sub_Fr(    femdarr8_t* lhs,   coeff_t  rhs);
void      femdarr8_sub_Fr_to( femdarr8_t* lhs,   coeff_t  rhs, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr8_t femdarr8_mul_FF(   femdarr8_t* lhs, femdarr8_t* rhs);
void      femdarr8_mul_FF_to(femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_mul_fF(    femdnum8_t* lhs, femdarr8_t* rhs);
void      femdarr8_mul_fF_to( femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_mul_OF(     mdarr8_t* lhs, femdarr8_t* rhs);
void      femdarr8_mul_OF_to(  mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_mul_RF(      darr_t* lhs, femdarr8_t* rhs);
void      femdarr8_mul_RF_to(   darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_mul_oF(   mdnum8_t* lhs, femdarr8_t* rhs);
void      femdarr8_mul_oF_to(mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_mul_rF(     coeff_t  lhs, femdarr8_t* rhs);
void      femdarr8_mul_rF_to(  coeff_t  lhs, femdarr8_t* rhs, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdarr8_t femdarr8_div_FF(    femdarr8_t* lhs, femdarr8_t* rhs);
void      femdarr8_div_FF_to( femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_div_fF(     femdnum8_t* lhs, femdarr8_t* rhs);
void      femdarr8_div_fF_to(  femdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_div_Ff(    femdarr8_t* lhs,  femdnum8_t* rhs);
void      femdarr8_div_Ff_to( femdarr8_t* lhs,  femdnum8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_div_OF(      mdarr8_t* lhs, femdarr8_t* rhs);
void      femdarr8_div_OF_to(   mdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_div_FO(    femdarr8_t* lhs,   mdarr8_t* rhs);
void      femdarr8_div_FO_to( femdarr8_t* lhs,   mdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_div_RF(       darr_t* lhs, femdarr8_t* rhs);
void      femdarr8_div_RF_to(    darr_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_div_FR(    femdarr8_t* lhs,    darr_t* rhs);
void      femdarr8_div_FR_to( femdarr8_t* lhs,    darr_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_div_oF(    mdnum8_t* lhs, femdarr8_t* rhs);
void      femdarr8_div_oF_to( mdnum8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_div_Fo(    femdarr8_t* lhs, mdnum8_t* rhs);
void      femdarr8_div_Fo_to( femdarr8_t* lhs, mdnum8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_div_rF(      coeff_t  lhs, femdarr8_t* rhs);
void      femdarr8_div_rF_to(    coeff_t lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_div_Fr(    femdarr8_t* lhs,   coeff_t  rhs);
void      femdarr8_div_Fr_to( femdarr8_t* lhs,   coeff_t  rhs, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
mdarr8_t femdarr8_integrate(    femdarr8_t* arr, femdnum8_t* w);
void    femdarr8_integrate_to( femdarr8_t* arr, femdnum8_t* w, mdarr8_t* res);
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
femdnum8_t femdarr8_dotproduct_FF(    femdarr8_t* lhs, femdarr8_t* rhs);
void     femdarr8_dotproduct_FF_to( femdarr8_t* lhs, femdarr8_t* rhs, femdnum8_t* res);

femdnum8_t femdarr8_dotproduct_OF(      mdarr8_t* lhs, femdarr8_t* rhs);
void     femdarr8_dotproduct_OF_to(   mdarr8_t* lhs, femdarr8_t* rhs, femdnum8_t* res);

femdnum8_t femdarr8_dotproduct_RF(       darr_t* lhs, femdarr8_t* rhs);
void     femdarr8_dotproduct_RF_to(    darr_t* lhs, femdarr8_t* rhs, femdnum8_t* res);
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
femdarr8_t femdarr8_matmul_FF(    femdarr8_t* lhs, femdarr8_t* rhs);
void      femdarr8_matmul_FF_to( femdarr8_t* lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_matmul_OF(    mdarr8_t*   lhs, femdarr8_t* rhs);
void      femdarr8_matmul_OF_to( mdarr8_t*   lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_matmul_FO(    femdarr8_t* lhs, mdarr8_t*   rhs);
void      femdarr8_matmul_FO_to( femdarr8_t* lhs, mdarr8_t*   rhs, femdarr8_t* res);

femdarr8_t femdarr8_matmul_RF(    darr_t*    lhs, femdarr8_t* rhs);
void      femdarr8_matmul_RF_to( darr_t*    lhs, femdarr8_t* rhs, femdarr8_t* res);

femdarr8_t femdarr8_matmul_FR(    femdarr8_t* lhs, darr_t*    rhs);
void      femdarr8_matmul_FR_to( femdarr8_t* lhs, darr_t*    rhs, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum8_t femdarr8_det(   femdarr8_t* arr);
void     femdarr8_det_to(femdarr8_t* arr, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
femdnum8_t femdarr8_norm(     femdarr8_t* arr);
void     femdarr8_norm_to(  femdarr8_t* arr, femdnum8_t* res);

femdnum8_t femdarr8_pnorm(    femdarr8_t* arr, coeff_t p);
void     femdarr8_pnorm_to( femdarr8_t* arr, coeff_t p, femdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr8_t   femdarr8_invert(    femdarr8_t* arr);
void        femdarr8_invert_to( femdarr8_t* arr, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
femdarr8_t   femdarr8_transpose(   femdarr8_t* arr);
void        femdarr8_transpose_to(femdarr8_t* arr, femdarr8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif