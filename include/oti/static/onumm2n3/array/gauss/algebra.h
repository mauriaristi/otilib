#ifndef OTI_ONUMM2N3_ARRAY_GAUSS_ALGEBRA_H
#define OTI_ONUMM2N3_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n3_t feoarrm2n3_neg(    feoarrm2n3_t* arr);
void      feoarrm2n3_neg_to( feoarrm2n3_t* arr, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n3_t feoarrm2n3_sum_FF(   feoarrm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sum_FF_to(feoarrm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sum_fF(    feonumm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sum_fF_to( feonumm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sum_OF(     oarrm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sum_OF_to(  oarrm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sum_RF(      darr_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sum_RF_to(   darr_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sum_oF(   onumm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sum_oF_to(onumm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sum_rF(     coeff_t  lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sum_rF_to(  coeff_t  lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n3_t feoarrm2n3_sub_FF(    feoarrm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sub_FF_to( feoarrm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sub_fF(    feonumm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sub_fF_to( feonumm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sub_Ff(    feoarrm2n3_t* lhs, feonumm2n3_t* rhs);
void      feoarrm2n3_sub_Ff_to( feoarrm2n3_t* lhs, feonumm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sub_OF(      oarrm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sub_OF_to(   oarrm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sub_FO(    feoarrm2n3_t* lhs,   oarrm2n3_t* rhs);
void      feoarrm2n3_sub_FO_to( feoarrm2n3_t* lhs,   oarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sub_RF(       darr_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sub_RF_to(    darr_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sub_FR(    feoarrm2n3_t* lhs,    darr_t* rhs);
void      feoarrm2n3_sub_FR_to( feoarrm2n3_t* lhs,    darr_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sub_oF(    onumm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sub_oF_to( onumm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sub_Fo(    feoarrm2n3_t* lhs, onumm2n3_t* rhs);
void      feoarrm2n3_sub_Fo_to( feoarrm2n3_t* lhs, onumm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sub_rF(      coeff_t  lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_sub_rF_to(    coeff_t lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_sub_Fr(    feoarrm2n3_t* lhs,   coeff_t  rhs);
void      feoarrm2n3_sub_Fr_to( feoarrm2n3_t* lhs,   coeff_t  rhs, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n3_t feoarrm2n3_mul_FF(   feoarrm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_mul_FF_to(feoarrm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_mul_fF(    feonumm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_mul_fF_to( feonumm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_mul_OF(     oarrm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_mul_OF_to(  oarrm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_mul_RF(      darr_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_mul_RF_to(   darr_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_mul_oF(   onumm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_mul_oF_to(onumm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_mul_rF(     coeff_t  lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_mul_rF_to(  coeff_t  lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm2n3_t feoarrm2n3_div_FF(    feoarrm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_div_FF_to( feoarrm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_div_fF(     feonumm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_div_fF_to(  feonumm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_div_Ff(    feoarrm2n3_t* lhs,  feonumm2n3_t* rhs);
void      feoarrm2n3_div_Ff_to( feoarrm2n3_t* lhs,  feonumm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_div_OF(      oarrm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_div_OF_to(   oarrm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_div_FO(    feoarrm2n3_t* lhs,   oarrm2n3_t* rhs);
void      feoarrm2n3_div_FO_to( feoarrm2n3_t* lhs,   oarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_div_RF(       darr_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_div_RF_to(    darr_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_div_FR(    feoarrm2n3_t* lhs,    darr_t* rhs);
void      feoarrm2n3_div_FR_to( feoarrm2n3_t* lhs,    darr_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_div_oF(    onumm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_div_oF_to( onumm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_div_Fo(    feoarrm2n3_t* lhs, onumm2n3_t* rhs);
void      feoarrm2n3_div_Fo_to( feoarrm2n3_t* lhs, onumm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_div_rF(      coeff_t  lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_div_rF_to(    coeff_t lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_div_Fr(    feoarrm2n3_t* lhs,   coeff_t  rhs);
void      feoarrm2n3_div_Fr_to( feoarrm2n3_t* lhs,   coeff_t  rhs, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm2n3_t feoarrm2n3_integrate(    feoarrm2n3_t* arr, feonumm2n3_t* w);
void    feoarrm2n3_integrate_to( feoarrm2n3_t* arr, feonumm2n3_t* w, oarrm2n3_t* res);
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
feonumm2n3_t feoarrm2n3_dotproduct_FF(    feoarrm2n3_t* lhs, feoarrm2n3_t* rhs);
void     feoarrm2n3_dotproduct_FF_to( feoarrm2n3_t* lhs, feoarrm2n3_t* rhs, feonumm2n3_t* res);

feonumm2n3_t feoarrm2n3_dotproduct_OF(      oarrm2n3_t* lhs, feoarrm2n3_t* rhs);
void     feoarrm2n3_dotproduct_OF_to(   oarrm2n3_t* lhs, feoarrm2n3_t* rhs, feonumm2n3_t* res);

feonumm2n3_t feoarrm2n3_dotproduct_RF(       darr_t* lhs, feoarrm2n3_t* rhs);
void     feoarrm2n3_dotproduct_RF_to(    darr_t* lhs, feoarrm2n3_t* rhs, feonumm2n3_t* res);
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
feoarrm2n3_t feoarrm2n3_matmul_FF(    feoarrm2n3_t* lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_matmul_FF_to( feoarrm2n3_t* lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_matmul_OF(    oarrm2n3_t*   lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_matmul_OF_to( oarrm2n3_t*   lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_matmul_FO(    feoarrm2n3_t* lhs, oarrm2n3_t*   rhs);
void      feoarrm2n3_matmul_FO_to( feoarrm2n3_t* lhs, oarrm2n3_t*   rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_matmul_RF(    darr_t*    lhs, feoarrm2n3_t* rhs);
void      feoarrm2n3_matmul_RF_to( darr_t*    lhs, feoarrm2n3_t* rhs, feoarrm2n3_t* res);

feoarrm2n3_t feoarrm2n3_matmul_FR(    feoarrm2n3_t* lhs, darr_t*    rhs);
void      feoarrm2n3_matmul_FR_to( feoarrm2n3_t* lhs, darr_t*    rhs, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm2n3_t feoarrm2n3_det(   feoarrm2n3_t* arr);
void     feoarrm2n3_det_to(feoarrm2n3_t* arr, feonumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm2n3_t feoarrm2n3_norm(     feoarrm2n3_t* arr);
void     feoarrm2n3_norm_to(  feoarrm2n3_t* arr, feonumm2n3_t* res);

feonumm2n3_t feoarrm2n3_pnorm(    feoarrm2n3_t* arr, coeff_t p);
void     feoarrm2n3_pnorm_to( feoarrm2n3_t* arr, coeff_t p, feonumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm2n3_t   feoarrm2n3_invert(    feoarrm2n3_t* arr);
void        feoarrm2n3_invert_to( feoarrm2n3_t* arr, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm2n3_t   feoarrm2n3_transpose(   feoarrm2n3_t* arr);
void        feoarrm2n3_transpose_to(feoarrm2n3_t* arr, feoarrm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif