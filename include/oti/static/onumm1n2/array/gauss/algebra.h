#ifndef OTI_ONUMM1N2_ARRAY_GAUSS_ALGEBRA_H
#define OTI_ONUMM1N2_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n2_t feoarrm1n2_neg(    feoarrm1n2_t* arr);
void      feoarrm1n2_neg_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n2_t feoarrm1n2_sum_FF(   feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sum_FF_to(feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sum_fF(    feonumm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sum_fF_to( feonumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sum_OF(     oarrm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sum_OF_to(  oarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sum_RF(      darr_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sum_RF_to(   darr_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sum_oF(   onumm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sum_oF_to(onumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sum_rF(     coeff_t  lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sum_rF_to(  coeff_t  lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n2_t feoarrm1n2_sub_FF(    feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sub_FF_to( feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sub_fF(    feonumm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sub_fF_to( feonumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sub_Ff(    feoarrm1n2_t* lhs, feonumm1n2_t* rhs);
void      feoarrm1n2_sub_Ff_to( feoarrm1n2_t* lhs, feonumm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sub_OF(      oarrm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sub_OF_to(   oarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sub_FO(    feoarrm1n2_t* lhs,   oarrm1n2_t* rhs);
void      feoarrm1n2_sub_FO_to( feoarrm1n2_t* lhs,   oarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sub_RF(       darr_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sub_RF_to(    darr_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sub_FR(    feoarrm1n2_t* lhs,    darr_t* rhs);
void      feoarrm1n2_sub_FR_to( feoarrm1n2_t* lhs,    darr_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sub_oF(    onumm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sub_oF_to( onumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sub_Fo(    feoarrm1n2_t* lhs, onumm1n2_t* rhs);
void      feoarrm1n2_sub_Fo_to( feoarrm1n2_t* lhs, onumm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sub_rF(      coeff_t  lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_sub_rF_to(    coeff_t lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_sub_Fr(    feoarrm1n2_t* lhs,   coeff_t  rhs);
void      feoarrm1n2_sub_Fr_to( feoarrm1n2_t* lhs,   coeff_t  rhs, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n2_t feoarrm1n2_mul_FF(   feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_mul_FF_to(feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_mul_fF(    feonumm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_mul_fF_to( feonumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_mul_OF(     oarrm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_mul_OF_to(  oarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_mul_RF(      darr_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_mul_RF_to(   darr_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_mul_oF(   onumm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_mul_oF_to(onumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_mul_rF(     coeff_t  lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_mul_rF_to(  coeff_t  lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm1n2_t feoarrm1n2_div_FF(    feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_div_FF_to( feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_div_fF(     feonumm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_div_fF_to(  feonumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_div_Ff(    feoarrm1n2_t* lhs,  feonumm1n2_t* rhs);
void      feoarrm1n2_div_Ff_to( feoarrm1n2_t* lhs,  feonumm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_div_OF(      oarrm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_div_OF_to(   oarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_div_FO(    feoarrm1n2_t* lhs,   oarrm1n2_t* rhs);
void      feoarrm1n2_div_FO_to( feoarrm1n2_t* lhs,   oarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_div_RF(       darr_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_div_RF_to(    darr_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_div_FR(    feoarrm1n2_t* lhs,    darr_t* rhs);
void      feoarrm1n2_div_FR_to( feoarrm1n2_t* lhs,    darr_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_div_oF(    onumm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_div_oF_to( onumm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_div_Fo(    feoarrm1n2_t* lhs, onumm1n2_t* rhs);
void      feoarrm1n2_div_Fo_to( feoarrm1n2_t* lhs, onumm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_div_rF(      coeff_t  lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_div_rF_to(    coeff_t lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_div_Fr(    feoarrm1n2_t* lhs,   coeff_t  rhs);
void      feoarrm1n2_div_Fr_to( feoarrm1n2_t* lhs,   coeff_t  rhs, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm1n2_t feoarrm1n2_integrate(    feoarrm1n2_t* arr, feonumm1n2_t* w);
void    feoarrm1n2_integrate_to( feoarrm1n2_t* arr, feonumm1n2_t* w, oarrm1n2_t* res);
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
feonumm1n2_t feoarrm1n2_dotproduct_FF(    feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
void     feoarrm1n2_dotproduct_FF_to( feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feoarrm1n2_dotproduct_OF(      oarrm1n2_t* lhs, feoarrm1n2_t* rhs);
void     feoarrm1n2_dotproduct_OF_to(   oarrm1n2_t* lhs, feoarrm1n2_t* rhs, feonumm1n2_t* res);

feonumm1n2_t feoarrm1n2_dotproduct_RF(       darr_t* lhs, feoarrm1n2_t* rhs);
void     feoarrm1n2_dotproduct_RF_to(    darr_t* lhs, feoarrm1n2_t* rhs, feonumm1n2_t* res);
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
feoarrm1n2_t feoarrm1n2_matmul_FF(    feoarrm1n2_t* lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_matmul_FF_to( feoarrm1n2_t* lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_matmul_OF(    oarrm1n2_t*   lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_matmul_OF_to( oarrm1n2_t*   lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_matmul_FO(    feoarrm1n2_t* lhs, oarrm1n2_t*   rhs);
void      feoarrm1n2_matmul_FO_to( feoarrm1n2_t* lhs, oarrm1n2_t*   rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_matmul_RF(    darr_t*    lhs, feoarrm1n2_t* rhs);
void      feoarrm1n2_matmul_RF_to( darr_t*    lhs, feoarrm1n2_t* rhs, feoarrm1n2_t* res);

feoarrm1n2_t feoarrm1n2_matmul_FR(    feoarrm1n2_t* lhs, darr_t*    rhs);
void      feoarrm1n2_matmul_FR_to( feoarrm1n2_t* lhs, darr_t*    rhs, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm1n2_t feoarrm1n2_det(   feoarrm1n2_t* arr);
void     feoarrm1n2_det_to(feoarrm1n2_t* arr, feonumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm1n2_t feoarrm1n2_norm(     feoarrm1n2_t* arr);
void     feoarrm1n2_norm_to(  feoarrm1n2_t* arr, feonumm1n2_t* res);

feonumm1n2_t feoarrm1n2_pnorm(    feoarrm1n2_t* arr, coeff_t p);
void     feoarrm1n2_pnorm_to( feoarrm1n2_t* arr, coeff_t p, feonumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm1n2_t   feoarrm1n2_invert(    feoarrm1n2_t* arr);
void        feoarrm1n2_invert_to( feoarrm1n2_t* arr, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm1n2_t   feoarrm1n2_transpose(   feoarrm1n2_t* arr);
void        feoarrm1n2_transpose_to(feoarrm1n2_t* arr, feoarrm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif