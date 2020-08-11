#ifndef OTI_REAL_ARRAY_GAUSS_ALGEBRA_H
#define OTI_REAL_ARRAY_GAUSS_ALGEBRA_H






/**************************************************************************************************//**
@brief Matrix negation.

RES = - ARR

@param[in] arr Matrix to be negated
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fedarr_t  fedarr_neg(    fedarr_t * arr                );
void      fedarr_neg_to( fedarr_t * arr, fedarr_t * res);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Matrix elementwise Addition.

RES = LHS + RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fedarr_t  fedarr_sum_FF(   fedarr_t * lhs, fedarr_t * rhs                );
void      fedarr_sum_FF_to(fedarr_t * lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_sum_fF(    fednum_t* lhs, fedarr_t * rhs                );
void      fedarr_sum_fF_to( fednum_t* lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_sum_RF(      darr_t* lhs, fedarr_t * rhs                );
void      fedarr_sum_RF_to(   darr_t* lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_sum_rF(     coeff_t  lhs, fedarr_t * rhs                );
void      fedarr_sum_rF_to(  coeff_t  lhs, fedarr_t * rhs, fedarr_t * res);
// ----------------------------------------------------------------------------------------------------






/**************************************************************************************************//**
@brief Matrix elementwise subtraction.

RES = LHS - RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fedarr_t  fedarr_sub_FF(    fedarr_t * lhs, fedarr_t * rhs                );
void      fedarr_sub_FF_to( fedarr_t * lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_sub_fF(    fednum_t* lhs, fedarr_t * rhs                 );
void      fedarr_sub_fF_to( fednum_t* lhs, fedarr_t * rhs, fedarr_t * res );

fedarr_t  fedarr_sub_Ff(    fedarr_t * lhs, fednum_t* rhs                 );
void      fedarr_sub_Ff_to( fedarr_t * lhs, fednum_t* rhs, fedarr_t * res );

fedarr_t  fedarr_sub_RF(       darr_t* lhs, fedarr_t * rhs                );
void      fedarr_sub_RF_to(    darr_t* lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_sub_FR(    fedarr_t * lhs,    darr_t* rhs                );
void      fedarr_sub_FR_to( fedarr_t * lhs,    darr_t* rhs, fedarr_t * res);

fedarr_t  fedarr_sub_rF(      coeff_t  lhs, fedarr_t * rhs                );
void      fedarr_sub_rF_to(    coeff_t lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_sub_Fr(    fedarr_t * lhs,   coeff_t  rhs                );
void      fedarr_sub_Fr_to( fedarr_t * lhs,   coeff_t  rhs, fedarr_t * res);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Matrix elementwise multiplication.

RES = LHS * RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fedarr_t  fedarr_mul_FF(   fedarr_t * lhs, fedarr_t * rhs                );
void      fedarr_mul_FF_to(fedarr_t * lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_mul_fF(    fednum_t* lhs, fedarr_t * rhs                );
void      fedarr_mul_fF_to( fednum_t* lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_mul_RF(      darr_t* lhs, fedarr_t * rhs                );
void      fedarr_mul_RF_to(   darr_t* lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_mul_rF(     coeff_t  lhs, fedarr_t * rhs                );
void      fedarr_mul_rF_to(  coeff_t  lhs, fedarr_t * rhs, fedarr_t * res);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Matrix elementwise division.

RES = LHS / RHS

@param[in] lhs Left hand side.
@param[in] rhs Right hand side.
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
fedarr_t  fedarr_div_FF(    fedarr_t * lhs, fedarr_t * rhs                );
void      fedarr_div_FF_to( fedarr_t * lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_div_fF(     fednum_t* lhs, fedarr_t * rhs                );
void      fedarr_div_fF_to(  fednum_t* lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_div_Ff(    fedarr_t* lhs,  fednum_t* rhs                );
void      fedarr_div_Ff_to( fedarr_t* lhs,  fednum_t* rhs, fedarr_t * res);

fedarr_t  fedarr_div_RF(       darr_t* lhs, fedarr_t * rhs                );
void      fedarr_div_RF_to(    darr_t* lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_div_FR(    fedarr_t* lhs,    darr_t* rhs                );
void      fedarr_div_FR_to( fedarr_t* lhs,    darr_t* rhs, fedarr_t * res);

fedarr_t  fedarr_div_rF(      coeff_t  lhs, fedarr_t * rhs                );
void      fedarr_div_rF_to(    coeff_t lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_div_Fr(    fedarr_t* lhs,   coeff_t  rhs                );
void      fedarr_div_Fr_to( fedarr_t* lhs,   coeff_t  rhs, fedarr_t * res);
// ----------------------------------------------------------------------------------------------------






/**************************************************************************************************//**
@brief Gauss integration.

@param[in] arr Array to integrate.
@param[in] w   Integration weights (scalar)
@param[in] res Result
@param[in] dhl Direction helper list.
******************************************************************************************************/
darr_t fedarr_integrate(    fedarr_t* arr, fednum_t* w              );
void    fedarr_integrate_to( fedarr_t* arr, fednum_t* w, darr_t* res);
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
fednum_t fedarr_dotproduct_FF(    fedarr_t* lhs, fedarr_t * rhs               );
void     fedarr_dotproduct_FF_to( fedarr_t* lhs, fedarr_t * rhs, fednum_t* res);

fednum_t fedarr_dotproduct_RF(       darr_t* lhs, fedarr_t * rhs               );
void     fedarr_dotproduct_RF_to(    darr_t* lhs, fedarr_t * rhs, fednum_t* res);
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
fedarr_t  fedarr_matmul_FF(    fedarr_t* lhs, fedarr_t * rhs                );
void      fedarr_matmul_FF_to( fedarr_t* lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_matmul_RF(    darr_t*    lhs, fedarr_t * rhs                );
void      fedarr_matmul_RF_to( darr_t*    lhs, fedarr_t * rhs, fedarr_t * res);

fedarr_t  fedarr_matmul_FR(    fedarr_t* lhs, darr_t*    rhs                );
void      fedarr_matmul_FR_to( fedarr_t* lhs, darr_t*    rhs, fedarr_t * res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix determinant.

res = DET( ARR )

@param[in] arr Array to compute determinant.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fednum_t fedarr_det(   fedarr_t* arr               );
void     fedarr_det_to(fedarr_t* arr, fednum_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief P-norm of array.

res = NORM( ARR )

@param[in] arr Array.
@param[in] p   Value p of norm.
@param[in] res Result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fednum_t fedarr_norm(     fedarr_t* arr               );
void     fedarr_norm_to(  fedarr_t* arr, fednum_t* res);

fednum_t fedarr_pnorm(    fedarr_t* arr, coeff_t p               );
void     fedarr_pnorm_to( fedarr_t* arr, coeff_t p, fednum_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Matrix invertion.

RES = ARR^( -1 )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fedarr_t    fedarr_invert(    fedarr_t* arr                );
void        fedarr_invert_to( fedarr_t* arr, fedarr_t * res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Matrix Transpose operation.

RES = TRANSPOSE( ARR )

@param[in] arr Array to invert.
@param[in] res Result 
@param[in] dhl Direction helper list
******************************************************************************************************/
fedarr_t    fedarr_transpose(   fedarr_t* arr                );
void        fedarr_transpose_to(fedarr_t* arr, fedarr_t * res);
// ----------------------------------------------------------------------------------------------------









#endif