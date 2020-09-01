#ifndef OTI_ONUMM5N3_ARRAY_GAUSS_ALGEBRA_H
#define OTI_ONUMM5N3_ARRAY_GAUSS_ALGEBRA_H

/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n3_t feoarrm5n3_neg(    feoarrm5n3_t* arr);
void      feoarrm5n3_neg_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n3_t feoarrm5n3_sum_FF(   feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sum_FF_to(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sum_fF(    feonumm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sum_fF_to( feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sum_OF(     oarrm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sum_OF_to(  oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sum_RF(      darr_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sum_RF_to(   darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sum_oF(   onumm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sum_oF_to(onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sum_rF(     coeff_t  lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sum_rF_to(  coeff_t  lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n3_t feoarrm5n3_sub_FF(    feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sub_FF_to( feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sub_fF(    feonumm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sub_fF_to( feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sub_Ff(    feoarrm5n3_t* lhs, feonumm5n3_t* rhs);
void      feoarrm5n3_sub_Ff_to( feoarrm5n3_t* lhs, feonumm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sub_OF(      oarrm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sub_OF_to(   oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sub_FO(    feoarrm5n3_t* lhs,   oarrm5n3_t* rhs);
void      feoarrm5n3_sub_FO_to( feoarrm5n3_t* lhs,   oarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sub_RF(       darr_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sub_RF_to(    darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sub_FR(    feoarrm5n3_t* lhs,    darr_t* rhs);
void      feoarrm5n3_sub_FR_to( feoarrm5n3_t* lhs,    darr_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sub_oF(    onumm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sub_oF_to( onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sub_Fo(    feoarrm5n3_t* lhs, onumm5n3_t* rhs);
void      feoarrm5n3_sub_Fo_to( feoarrm5n3_t* lhs, onumm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sub_rF(      coeff_t  lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_sub_rF_to(    coeff_t lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_sub_Fr(    feoarrm5n3_t* lhs,   coeff_t  rhs);
void      feoarrm5n3_sub_Fr_to( feoarrm5n3_t* lhs,   coeff_t  rhs, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n3_t feoarrm5n3_mul_FF(   feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_mul_FF_to(feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_mul_fF(    feonumm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_mul_fF_to( feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_mul_OF(     oarrm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_mul_OF_to(  oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_mul_RF(      darr_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_mul_RF_to(   darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_mul_oF(   onumm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_mul_oF_to(onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_mul_rF(     coeff_t  lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_mul_rF_to(  coeff_t  lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
feoarrm5n3_t feoarrm5n3_div_FF(    feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_div_FF_to( feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_div_fF(     feonumm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_div_fF_to(  feonumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_div_Ff(    feoarrm5n3_t* lhs,  feonumm5n3_t* rhs);
void      feoarrm5n3_div_Ff_to( feoarrm5n3_t* lhs,  feonumm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_div_OF(      oarrm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_div_OF_to(   oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_div_FO(    feoarrm5n3_t* lhs,   oarrm5n3_t* rhs);
void      feoarrm5n3_div_FO_to( feoarrm5n3_t* lhs,   oarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_div_RF(       darr_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_div_RF_to(    darr_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_div_FR(    feoarrm5n3_t* lhs,    darr_t* rhs);
void      feoarrm5n3_div_FR_to( feoarrm5n3_t* lhs,    darr_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_div_oF(    onumm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_div_oF_to( onumm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_div_Fo(    feoarrm5n3_t* lhs, onumm5n3_t* rhs);
void      feoarrm5n3_div_Fo_to( feoarrm5n3_t* lhs, onumm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_div_rF(      coeff_t  lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_div_rF_to(    coeff_t lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_div_Fr(    feoarrm5n3_t* lhs,   coeff_t  rhs);
void      feoarrm5n3_div_Fr_to( feoarrm5n3_t* lhs,   coeff_t  rhs, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
oarrm5n3_t feoarrm5n3_integrate(    feoarrm5n3_t* arr, feonumm5n3_t* w);
void    feoarrm5n3_integrate_to( feoarrm5n3_t* arr, feonumm5n3_t* w, oarrm5n3_t* res);
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
feonumm5n3_t feoarrm5n3_dotproduct_FF(    feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
void     feoarrm5n3_dotproduct_FF_to( feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feoarrm5n3_dotproduct_OF(      oarrm5n3_t* lhs, feoarrm5n3_t* rhs);
void     feoarrm5n3_dotproduct_OF_to(   oarrm5n3_t* lhs, feoarrm5n3_t* rhs, feonumm5n3_t* res);

feonumm5n3_t feoarrm5n3_dotproduct_RF(       darr_t* lhs, feoarrm5n3_t* rhs);
void     feoarrm5n3_dotproduct_RF_to(    darr_t* lhs, feoarrm5n3_t* rhs, feonumm5n3_t* res);
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
feoarrm5n3_t feoarrm5n3_matmul_FF(    feoarrm5n3_t* lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_matmul_FF_to( feoarrm5n3_t* lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_matmul_OF(    oarrm5n3_t*   lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_matmul_OF_to( oarrm5n3_t*   lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_matmul_FO(    feoarrm5n3_t* lhs, oarrm5n3_t*   rhs);
void      feoarrm5n3_matmul_FO_to( feoarrm5n3_t* lhs, oarrm5n3_t*   rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_matmul_RF(    darr_t*    lhs, feoarrm5n3_t* rhs);
void      feoarrm5n3_matmul_RF_to( darr_t*    lhs, feoarrm5n3_t* rhs, feoarrm5n3_t* res);

feoarrm5n3_t feoarrm5n3_matmul_FR(    feoarrm5n3_t* lhs, darr_t*    rhs);
void      feoarrm5n3_matmul_FR_to( feoarrm5n3_t* lhs, darr_t*    rhs, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm5n3_t feoarrm5n3_det(   feoarrm5n3_t* arr);
void     feoarrm5n3_det_to(feoarrm5n3_t* arr, feonumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
feonumm5n3_t feoarrm5n3_norm(     feoarrm5n3_t* arr);
void     feoarrm5n3_norm_to(  feoarrm5n3_t* arr, feonumm5n3_t* res);

feonumm5n3_t feoarrm5n3_pnorm(    feoarrm5n3_t* arr, coeff_t p);
void     feoarrm5n3_pnorm_to( feoarrm5n3_t* arr, coeff_t p, feonumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm5n3_t   feoarrm5n3_invert(    feoarrm5n3_t* arr);
void        feoarrm5n3_invert_to( feoarrm5n3_t* arr, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
feoarrm5n3_t   feoarrm5n3_transpose(   feoarrm5n3_t* arr);
void        feoarrm5n3_transpose_to(feoarrm5n3_t* arr, feoarrm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif