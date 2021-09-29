#ifndef OTI_SEMISPARSE_ARRAY_GAUSS_ALGEBRA_H
#define OTI_SEMISPARSE_ARRAY_GAUSS_ALGEBRA_H





/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrsso_t fearrsso_neg(    fearrsso_t* arr,                 dhelpl_t dhl);
void      fearrsso_neg_to( fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrsso_t fearrsso_sum_FF(   fearrsso_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sum_FF_to(fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sum_fF(    fessoti_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sum_fF_to( fessoti_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sum_OF(     arrsso_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sum_OF_to(  arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sum_RF(      darr_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sum_RF_to(   darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sum_oF(   semiotin_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sum_oF_to(semiotin_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sum_rF(     coeff_t  lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sum_rF_to(  coeff_t  lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------






/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrsso_t fearrsso_sub_FF(    fearrsso_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sub_FF_to( fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sub_fF(    fessoti_t* lhs, fearrsso_t* rhs,                  dhelpl_t dhl);
void      fearrsso_sub_fF_to( fessoti_t* lhs, fearrsso_t* rhs, fearrsso_t* res,  dhelpl_t dhl);

fearrsso_t fearrsso_sub_Ff(    fearrsso_t* lhs, fessoti_t* rhs,                  dhelpl_t dhl);
void      fearrsso_sub_Ff_to( fearrsso_t* lhs, fessoti_t* rhs, fearrsso_t* res,  dhelpl_t dhl);

fearrsso_t fearrsso_sub_OF(      arrsso_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sub_OF_to(   arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sub_FO(    fearrsso_t* lhs,   arrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sub_FO_to( fearrsso_t* lhs,   arrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sub_RF(       darr_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sub_RF_to(    darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sub_FR(    fearrsso_t* lhs,    darr_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sub_FR_to( fearrsso_t* lhs,    darr_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sub_oF(    semiotin_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sub_oF_to( semiotin_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sub_Fo(    fearrsso_t* lhs, semiotin_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sub_Fo_to( fearrsso_t* lhs, semiotin_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sub_rF(      coeff_t  lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_sub_rF_to(    coeff_t lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_sub_Fr(    fearrsso_t* lhs,   coeff_t  rhs,                 dhelpl_t dhl);
void      fearrsso_sub_Fr_to( fearrsso_t* lhs,   coeff_t  rhs, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrsso_t fearrsso_mul_FF(   fearrsso_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_mul_FF_to(fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_mul_fF(    fessoti_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_mul_fF_to( fessoti_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_mul_OF(     arrsso_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_mul_OF_to(  arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_mul_RF(      darr_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_mul_RF_to(   darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_mul_oF(   semiotin_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_mul_oF_to(semiotin_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_mul_rF(     coeff_t  lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_mul_rF_to(  coeff_t  lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrsso_t fearrsso_div_FF(    fearrsso_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_div_FF_to( fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_div_fF(     fessoti_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_div_fF_to(  fessoti_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_div_Ff(    fearrsso_t* lhs,  fessoti_t* rhs,                 dhelpl_t dhl);
void      fearrsso_div_Ff_to( fearrsso_t* lhs,  fessoti_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_div_OF(      arrsso_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_div_OF_to(   arrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_div_FO(    fearrsso_t* lhs,   arrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_div_FO_to( fearrsso_t* lhs,   arrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_div_RF(       darr_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_div_RF_to(    darr_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_div_FR(    fearrsso_t* lhs,    darr_t* rhs,                 dhelpl_t dhl);
void      fearrsso_div_FR_to( fearrsso_t* lhs,    darr_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_div_oF(    semiotin_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_div_oF_to( semiotin_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_div_Fo(    fearrsso_t* lhs, semiotin_t* rhs,                 dhelpl_t dhl);
void      fearrsso_div_Fo_to( fearrsso_t* lhs, semiotin_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_div_rF(      coeff_t  lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_div_rF_to(    coeff_t lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_div_Fr(    fearrsso_t* lhs,   coeff_t  rhs,                 dhelpl_t dhl);
void      fearrsso_div_Fr_to( fearrsso_t* lhs,   coeff_t  rhs, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------






/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
arrsso_t fearrsso_integrate(    fearrsso_t* arr, fessoti_t* w,               dhelpl_t dhl);
void    fearrsso_integrate_to( fearrsso_t* arr, fessoti_t* w, arrsso_t* res, dhelpl_t dhl);
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
fessoti_t fearrsso_dotproduct_FF(    fearrsso_t* lhs, fearrsso_t* rhs,                dhelpl_t dhl);
void     fearrsso_dotproduct_FF_to( fearrsso_t* lhs, fearrsso_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fearrsso_dotproduct_OF(      arrsso_t* lhs, fearrsso_t* rhs,                dhelpl_t dhl);
void     fearrsso_dotproduct_OF_to(   arrsso_t* lhs, fearrsso_t* rhs, fessoti_t* res, dhelpl_t dhl);

fessoti_t fearrsso_dotproduct_RF(       darr_t* lhs, fearrsso_t* rhs,                dhelpl_t dhl);
void     fearrsso_dotproduct_RF_to(    darr_t* lhs, fearrsso_t* rhs, fessoti_t* res, dhelpl_t dhl);
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
fearrsso_t fearrsso_matmul_FF(    fearrsso_t* lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_matmul_FF_to( fearrsso_t* lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_matmul_OF(    arrsso_t*   lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_matmul_OF_to( arrsso_t*   lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_matmul_FO(    fearrsso_t* lhs, arrsso_t*   rhs,                 dhelpl_t dhl);
void      fearrsso_matmul_FO_to( fearrsso_t* lhs, arrsso_t*   rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_matmul_RF(    darr_t*    lhs, fearrsso_t* rhs,                 dhelpl_t dhl);
void      fearrsso_matmul_RF_to( darr_t*    lhs, fearrsso_t* rhs, fearrsso_t* res, dhelpl_t dhl);

fearrsso_t fearrsso_matmul_FR(    fearrsso_t* lhs, darr_t*    rhs,                 dhelpl_t dhl);
void      fearrsso_matmul_FR_to( fearrsso_t* lhs, darr_t*    rhs, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fessoti_t fearrsso_det(   fearrsso_t* arr,                dhelpl_t dhl);
void     fearrsso_det_to(fearrsso_t* arr, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fessoti_t fearrsso_norm(     fearrsso_t* arr,                dhelpl_t dhl);
void     fearrsso_norm_to(  fearrsso_t* arr, fessoti_t* res, dhelpl_t dhl);

fessoti_t fearrsso_pnorm(    fearrsso_t* arr, coeff_t p,                dhelpl_t dhl);
void     fearrsso_pnorm_to( fearrsso_t* arr, coeff_t p, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fearrsso_t   fearrsso_invert(    fearrsso_t* arr,                 dhelpl_t dhl);
void        fearrsso_invert_to( fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fearrsso_t   fearrsso_transpose(   fearrsso_t* arr,                 dhelpl_t dhl);
void        fearrsso_transpose_to(fearrsso_t* arr, fearrsso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------













#endif