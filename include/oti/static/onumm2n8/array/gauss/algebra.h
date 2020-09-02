#ifndef OTI_ONUMM2N8_ARRAY_GAUSS_ALGEBRA_H
#define OTI_ONUMM2N8_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n8_t feoarrm2n8_neg(    feoarrm2n8_t* arr);
void      feoarrm2n8_neg_to( feoarrm2n8_t* arr, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n8_t feoarrm2n8_sum_FF(   feoarrm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sum_FF_to(feoarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sum_fF(    feonumm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sum_fF_to( feonumm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sum_OF(     oarrm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sum_OF_to(  oarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sum_RF(      darr_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sum_RF_to(   darr_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sum_oF(   onumm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sum_oF_to(onumm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sum_rF(     coeff_t  lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sum_rF_to(  coeff_t  lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n8_t feoarrm2n8_sub_FF(    feoarrm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sub_FF_to( feoarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sub_fF(    feonumm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sub_fF_to( feonumm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sub_Ff(    feoarrm2n8_t* lhs, feonumm2n8_t* rhs);
void      feoarrm2n8_sub_Ff_to( feoarrm2n8_t* lhs, feonumm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sub_OF(      oarrm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sub_OF_to(   oarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sub_FO(    feoarrm2n8_t* lhs,   oarrm2n8_t* rhs);
void      feoarrm2n8_sub_FO_to( feoarrm2n8_t* lhs,   oarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sub_RF(       darr_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sub_RF_to(    darr_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sub_FR(    feoarrm2n8_t* lhs,    darr_t* rhs);
void      feoarrm2n8_sub_FR_to( feoarrm2n8_t* lhs,    darr_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sub_oF(    onumm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sub_oF_to( onumm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sub_Fo(    feoarrm2n8_t* lhs, onumm2n8_t* rhs);
void      feoarrm2n8_sub_Fo_to( feoarrm2n8_t* lhs, onumm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sub_rF(      coeff_t  lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_sub_rF_to(    coeff_t lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_sub_Fr(    feoarrm2n8_t* lhs,   coeff_t  rhs);
void      feoarrm2n8_sub_Fr_to( feoarrm2n8_t* lhs,   coeff_t  rhs, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n8_t feoarrm2n8_mul_FF(   feoarrm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_mul_FF_to(feoarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_mul_fF(    feonumm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_mul_fF_to( feonumm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_mul_OF(     oarrm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_mul_OF_to(  oarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_mul_RF(      darr_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_mul_RF_to(   darr_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_mul_oF(   onumm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_mul_oF_to(onumm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_mul_rF(     coeff_t  lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_mul_rF_to(  coeff_t  lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n8_t feoarrm2n8_div_FF(    feoarrm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_div_FF_to( feoarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_div_fF(     feonumm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_div_fF_to(  feonumm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_div_Ff(    feoarrm2n8_t* lhs,  feonumm2n8_t* rhs);
void      feoarrm2n8_div_Ff_to( feoarrm2n8_t* lhs,  feonumm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_div_OF(      oarrm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_div_OF_to(   oarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_div_FO(    feoarrm2n8_t* lhs,   oarrm2n8_t* rhs);
void      feoarrm2n8_div_FO_to( feoarrm2n8_t* lhs,   oarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_div_RF(       darr_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_div_RF_to(    darr_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_div_FR(    feoarrm2n8_t* lhs,    darr_t* rhs);
void      feoarrm2n8_div_FR_to( feoarrm2n8_t* lhs,    darr_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_div_oF(    onumm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_div_oF_to( onumm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_div_Fo(    feoarrm2n8_t* lhs, onumm2n8_t* rhs);
void      feoarrm2n8_div_Fo_to( feoarrm2n8_t* lhs, onumm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_div_rF(      coeff_t  lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_div_rF_to(    coeff_t lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_div_Fr(    feoarrm2n8_t* lhs,   coeff_t  rhs);
void      feoarrm2n8_div_Fr_to( feoarrm2n8_t* lhs,   coeff_t  rhs, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm2n8_t feoarrm2n8_integrate(    feoarrm2n8_t* arr, feonumm2n8_t* w);
void    feoarrm2n8_integrate_to( feoarrm2n8_t* arr, feonumm2n8_t* w, oarrm2n8_t* res);
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
feonumm2n8_t feoarrm2n8_dotproduct_FF(    feoarrm2n8_t* lhs, feoarrm2n8_t* rhs);
void     feoarrm2n8_dotproduct_FF_to( feoarrm2n8_t* lhs, feoarrm2n8_t* rhs, feonumm2n8_t* res);

feonumm2n8_t feoarrm2n8_dotproduct_OF(      oarrm2n8_t* lhs, feoarrm2n8_t* rhs);
void     feoarrm2n8_dotproduct_OF_to(   oarrm2n8_t* lhs, feoarrm2n8_t* rhs, feonumm2n8_t* res);

feonumm2n8_t feoarrm2n8_dotproduct_RF(       darr_t* lhs, feoarrm2n8_t* rhs);
void     feoarrm2n8_dotproduct_RF_to(    darr_t* lhs, feoarrm2n8_t* rhs, feonumm2n8_t* res);
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
feoarrm2n8_t feoarrm2n8_matmul_FF(    feoarrm2n8_t* lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_matmul_FF_to( feoarrm2n8_t* lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_matmul_OF(    oarrm2n8_t*   lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_matmul_OF_to( oarrm2n8_t*   lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_matmul_FO(    feoarrm2n8_t* lhs, oarrm2n8_t*   rhs);
void      feoarrm2n8_matmul_FO_to( feoarrm2n8_t* lhs, oarrm2n8_t*   rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_matmul_RF(    darr_t*    lhs, feoarrm2n8_t* rhs);
void      feoarrm2n8_matmul_RF_to( darr_t*    lhs, feoarrm2n8_t* rhs, feoarrm2n8_t* res);

feoarrm2n8_t feoarrm2n8_matmul_FR(    feoarrm2n8_t* lhs, darr_t*    rhs);
void      feoarrm2n8_matmul_FR_to( feoarrm2n8_t* lhs, darr_t*    rhs, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm2n8_t feoarrm2n8_det(   feoarrm2n8_t* arr);
void     feoarrm2n8_det_to(feoarrm2n8_t* arr, feonumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n8_t feoarrm2n8_norm(     feoarrm2n8_t* arr);
void     feoarrm2n8_norm_to(  feoarrm2n8_t* arr, feonumm2n8_t* res);

feonumm2n8_t feoarrm2n8_pnorm(    feoarrm2n8_t* arr, coeff_t p);
void     feoarrm2n8_pnorm_to( feoarrm2n8_t* arr, coeff_t p, feonumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm2n8_t   feoarrm2n8_invert(    feoarrm2n8_t* arr);
void        feoarrm2n8_invert_to( feoarrm2n8_t* arr, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm2n8_t   feoarrm2n8_transpose(   feoarrm2n8_t* arr);
void        feoarrm2n8_transpose_to(feoarrm2n8_t* arr, feoarrm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif