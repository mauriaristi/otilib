#ifndef OTI_ONUMM6N2_ARRAY_GAUSS_ALGEBRA_H
#define OTI_ONUMM6N2_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n2_t feoarrm6n2_neg(    feoarrm6n2_t* arr);
void      feoarrm6n2_neg_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n2_t feoarrm6n2_sum_FF(   feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sum_FF_to(feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sum_fF(    feonumm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sum_fF_to( feonumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sum_OF(     oarrm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sum_OF_to(  oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sum_RF(      darr_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sum_RF_to(   darr_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sum_oF(   onumm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sum_oF_to(onumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sum_rF(     coeff_t  lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sum_rF_to(  coeff_t  lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n2_t feoarrm6n2_sub_FF(    feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sub_FF_to( feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sub_fF(    feonumm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sub_fF_to( feonumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sub_Ff(    feoarrm6n2_t* lhs, feonumm6n2_t* rhs);
void      feoarrm6n2_sub_Ff_to( feoarrm6n2_t* lhs, feonumm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sub_OF(      oarrm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sub_OF_to(   oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sub_FO(    feoarrm6n2_t* lhs,   oarrm6n2_t* rhs);
void      feoarrm6n2_sub_FO_to( feoarrm6n2_t* lhs,   oarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sub_RF(       darr_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sub_RF_to(    darr_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sub_FR(    feoarrm6n2_t* lhs,    darr_t* rhs);
void      feoarrm6n2_sub_FR_to( feoarrm6n2_t* lhs,    darr_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sub_oF(    onumm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sub_oF_to( onumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sub_Fo(    feoarrm6n2_t* lhs, onumm6n2_t* rhs);
void      feoarrm6n2_sub_Fo_to( feoarrm6n2_t* lhs, onumm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sub_rF(      coeff_t  lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_sub_rF_to(    coeff_t lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_sub_Fr(    feoarrm6n2_t* lhs,   coeff_t  rhs);
void      feoarrm6n2_sub_Fr_to( feoarrm6n2_t* lhs,   coeff_t  rhs, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n2_t feoarrm6n2_mul_FF(   feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_mul_FF_to(feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_mul_fF(    feonumm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_mul_fF_to( feonumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_mul_OF(     oarrm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_mul_OF_to(  oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_mul_RF(      darr_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_mul_RF_to(   darr_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_mul_oF(   onumm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_mul_oF_to(onumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_mul_rF(     coeff_t  lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_mul_rF_to(  coeff_t  lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm6n2_t feoarrm6n2_div_FF(    feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_div_FF_to( feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_div_fF(     feonumm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_div_fF_to(  feonumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_div_Ff(    feoarrm6n2_t* lhs,  feonumm6n2_t* rhs);
void      feoarrm6n2_div_Ff_to( feoarrm6n2_t* lhs,  feonumm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_div_OF(      oarrm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_div_OF_to(   oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_div_FO(    feoarrm6n2_t* lhs,   oarrm6n2_t* rhs);
void      feoarrm6n2_div_FO_to( feoarrm6n2_t* lhs,   oarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_div_RF(       darr_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_div_RF_to(    darr_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_div_FR(    feoarrm6n2_t* lhs,    darr_t* rhs);
void      feoarrm6n2_div_FR_to( feoarrm6n2_t* lhs,    darr_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_div_oF(    onumm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_div_oF_to( onumm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_div_Fo(    feoarrm6n2_t* lhs, onumm6n2_t* rhs);
void      feoarrm6n2_div_Fo_to( feoarrm6n2_t* lhs, onumm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_div_rF(      coeff_t  lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_div_rF_to(    coeff_t lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_div_Fr(    feoarrm6n2_t* lhs,   coeff_t  rhs);
void      feoarrm6n2_div_Fr_to( feoarrm6n2_t* lhs,   coeff_t  rhs, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm6n2_t feoarrm6n2_integrate(    feoarrm6n2_t* arr, feonumm6n2_t* w);
void    feoarrm6n2_integrate_to( feoarrm6n2_t* arr, feonumm6n2_t* w, oarrm6n2_t* res);
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
feonumm6n2_t feoarrm6n2_dotproduct_FF(    feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
void     feoarrm6n2_dotproduct_FF_to( feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feoarrm6n2_dotproduct_OF(      oarrm6n2_t* lhs, feoarrm6n2_t* rhs);
void     feoarrm6n2_dotproduct_OF_to(   oarrm6n2_t* lhs, feoarrm6n2_t* rhs, feonumm6n2_t* res);

feonumm6n2_t feoarrm6n2_dotproduct_RF(       darr_t* lhs, feoarrm6n2_t* rhs);
void     feoarrm6n2_dotproduct_RF_to(    darr_t* lhs, feoarrm6n2_t* rhs, feonumm6n2_t* res);
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
feoarrm6n2_t feoarrm6n2_matmul_FF(    feoarrm6n2_t* lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_matmul_FF_to( feoarrm6n2_t* lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_matmul_OF(    oarrm6n2_t*   lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_matmul_OF_to( oarrm6n2_t*   lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_matmul_FO(    feoarrm6n2_t* lhs, oarrm6n2_t*   rhs);
void      feoarrm6n2_matmul_FO_to( feoarrm6n2_t* lhs, oarrm6n2_t*   rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_matmul_RF(    darr_t*    lhs, feoarrm6n2_t* rhs);
void      feoarrm6n2_matmul_RF_to( darr_t*    lhs, feoarrm6n2_t* rhs, feoarrm6n2_t* res);

feoarrm6n2_t feoarrm6n2_matmul_FR(    feoarrm6n2_t* lhs, darr_t*    rhs);
void      feoarrm6n2_matmul_FR_to( feoarrm6n2_t* lhs, darr_t*    rhs, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm6n2_t feoarrm6n2_det(   feoarrm6n2_t* arr);
void     feoarrm6n2_det_to(feoarrm6n2_t* arr, feonumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm6n2_t feoarrm6n2_norm(     feoarrm6n2_t* arr);
void     feoarrm6n2_norm_to(  feoarrm6n2_t* arr, feonumm6n2_t* res);

feonumm6n2_t feoarrm6n2_pnorm(    feoarrm6n2_t* arr, coeff_t p);
void     feoarrm6n2_pnorm_to( feoarrm6n2_t* arr, coeff_t p, feonumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm6n2_t   feoarrm6n2_invert(    feoarrm6n2_t* arr);
void        feoarrm6n2_invert_to( feoarrm6n2_t* arr, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm6n2_t   feoarrm6n2_transpose(   feoarrm6n2_t* arr);
void        feoarrm6n2_transpose_to(feoarrm6n2_t* arr, feoarrm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif