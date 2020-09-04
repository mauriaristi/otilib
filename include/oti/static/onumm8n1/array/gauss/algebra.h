#ifndef OTI_ONUMM8N1_ARRAY_GAUSS_ALGEBRA_H
#define OTI_ONUMM8N1_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_neg(    feoarrm8n1_t* arr);
void      feoarrm8n1_neg_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_sum_FF(   feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sum_FF_to(feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sum_fF(    feonumm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sum_fF_to( feonumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sum_OF(     oarrm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sum_OF_to(  oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sum_RF(      darr_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sum_RF_to(   darr_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sum_oF(   onumm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sum_oF_to(onumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sum_rF(     coeff_t  lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sum_rF_to(  coeff_t  lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_sub_FF(    feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sub_FF_to( feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sub_fF(    feonumm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sub_fF_to( feonumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sub_Ff(    feoarrm8n1_t* lhs, feonumm8n1_t* rhs);
void      feoarrm8n1_sub_Ff_to( feoarrm8n1_t* lhs, feonumm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sub_OF(      oarrm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sub_OF_to(   oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sub_FO(    feoarrm8n1_t* lhs,   oarrm8n1_t* rhs);
void      feoarrm8n1_sub_FO_to( feoarrm8n1_t* lhs,   oarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sub_RF(       darr_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sub_RF_to(    darr_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sub_FR(    feoarrm8n1_t* lhs,    darr_t* rhs);
void      feoarrm8n1_sub_FR_to( feoarrm8n1_t* lhs,    darr_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sub_oF(    onumm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sub_oF_to( onumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sub_Fo(    feoarrm8n1_t* lhs, onumm8n1_t* rhs);
void      feoarrm8n1_sub_Fo_to( feoarrm8n1_t* lhs, onumm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sub_rF(      coeff_t  lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_sub_rF_to(    coeff_t lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_sub_Fr(    feoarrm8n1_t* lhs,   coeff_t  rhs);
void      feoarrm8n1_sub_Fr_to( feoarrm8n1_t* lhs,   coeff_t  rhs, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_mul_FF(   feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_mul_FF_to(feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_mul_fF(    feonumm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_mul_fF_to( feonumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_mul_OF(     oarrm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_mul_OF_to(  oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_mul_RF(      darr_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_mul_RF_to(   darr_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_mul_oF(   onumm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_mul_oF_to(onumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_mul_rF(     coeff_t  lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_mul_rF_to(  coeff_t  lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm8n1_t feoarrm8n1_div_FF(    feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_div_FF_to( feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_div_fF(     feonumm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_div_fF_to(  feonumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_div_Ff(    feoarrm8n1_t* lhs,  feonumm8n1_t* rhs);
void      feoarrm8n1_div_Ff_to( feoarrm8n1_t* lhs,  feonumm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_div_OF(      oarrm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_div_OF_to(   oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_div_FO(    feoarrm8n1_t* lhs,   oarrm8n1_t* rhs);
void      feoarrm8n1_div_FO_to( feoarrm8n1_t* lhs,   oarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_div_RF(       darr_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_div_RF_to(    darr_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_div_FR(    feoarrm8n1_t* lhs,    darr_t* rhs);
void      feoarrm8n1_div_FR_to( feoarrm8n1_t* lhs,    darr_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_div_oF(    onumm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_div_oF_to( onumm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_div_Fo(    feoarrm8n1_t* lhs, onumm8n1_t* rhs);
void      feoarrm8n1_div_Fo_to( feoarrm8n1_t* lhs, onumm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_div_rF(      coeff_t  lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_div_rF_to(    coeff_t lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_div_Fr(    feoarrm8n1_t* lhs,   coeff_t  rhs);
void      feoarrm8n1_div_Fr_to( feoarrm8n1_t* lhs,   coeff_t  rhs, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm8n1_t feoarrm8n1_integrate(    feoarrm8n1_t* arr, feonumm8n1_t* w);
void    feoarrm8n1_integrate_to( feoarrm8n1_t* arr, feonumm8n1_t* w, oarrm8n1_t* res);
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
feonumm8n1_t feoarrm8n1_dotproduct_FF(    feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
void     feoarrm8n1_dotproduct_FF_to( feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feonumm8n1_t* res);

feonumm8n1_t feoarrm8n1_dotproduct_OF(      oarrm8n1_t* lhs, feoarrm8n1_t* rhs);
void     feoarrm8n1_dotproduct_OF_to(   oarrm8n1_t* lhs, feoarrm8n1_t* rhs, feonumm8n1_t* res);

feonumm8n1_t feoarrm8n1_dotproduct_RF(       darr_t* lhs, feoarrm8n1_t* rhs);
void     feoarrm8n1_dotproduct_RF_to(    darr_t* lhs, feoarrm8n1_t* rhs, feonumm8n1_t* res);
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
feoarrm8n1_t feoarrm8n1_matmul_FF(    feoarrm8n1_t* lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_matmul_FF_to( feoarrm8n1_t* lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_matmul_OF(    oarrm8n1_t*   lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_matmul_OF_to( oarrm8n1_t*   lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_matmul_FO(    feoarrm8n1_t* lhs, oarrm8n1_t*   rhs);
void      feoarrm8n1_matmul_FO_to( feoarrm8n1_t* lhs, oarrm8n1_t*   rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_matmul_RF(    darr_t*    lhs, feoarrm8n1_t* rhs);
void      feoarrm8n1_matmul_RF_to( darr_t*    lhs, feoarrm8n1_t* rhs, feoarrm8n1_t* res);

feoarrm8n1_t feoarrm8n1_matmul_FR(    feoarrm8n1_t* lhs, darr_t*    rhs);
void      feoarrm8n1_matmul_FR_to( feoarrm8n1_t* lhs, darr_t*    rhs, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm8n1_t feoarrm8n1_det(   feoarrm8n1_t* arr);
void     feoarrm8n1_det_to(feoarrm8n1_t* arr, feonumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm8n1_t feoarrm8n1_norm(     feoarrm8n1_t* arr);
void     feoarrm8n1_norm_to(  feoarrm8n1_t* arr, feonumm8n1_t* res);

feonumm8n1_t feoarrm8n1_pnorm(    feoarrm8n1_t* arr, coeff_t p);
void     feoarrm8n1_pnorm_to( feoarrm8n1_t* arr, coeff_t p, feonumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm8n1_t   feoarrm8n1_invert(    feoarrm8n1_t* arr);
void        feoarrm8n1_invert_to( feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm8n1_t   feoarrm8n1_transpose(   feoarrm8n1_t* arr);
void        feoarrm8n1_transpose_to(feoarrm8n1_t* arr, feoarrm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif