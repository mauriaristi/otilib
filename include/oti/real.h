#ifndef OTI_REAL_H
#define OTI_REAL_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "oti/comm.h" 
#include <math.h>

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    coeff_t*       p_data; // Data array
    uint64_t       nrows; // Number of rows.
    uint64_t       ncols; // Number of cols.
    uint64_t        size; // Total size of the array.
} darr_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------










darr_t darr_init( void );

void darr_matmul_and_selfsum_RR_to(darr_t* arr1, darr_t* arr2, darr_t* res );





// ----------------------------------------------------------------------------------------------------
// ---------------------------------    MATH FUNCTIONS    ---------------------------------------------
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the two argument inverse tangent function. 

@param x Evaluation point.
@param y Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_atan2(coeff_t x, coeff_t y, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the base b logarith, function. 

@param x Evaluation point.
@param base Base of the logarithm.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_logb(coeff_t x, coeff_t base, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the base 10 logarithm function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_log10(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse hyperbolic tangent function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_atanh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse hyperbolic sine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_asinh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse hyperbolic cosine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_acosh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the hyperbolic tangent function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_tanh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the square root function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_sqrt(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the hyperbolic cosine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_cosh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the hyperbolic sine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_sinh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse sine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_asin(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse cosine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_acos(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse tangent function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_atan(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the tangent function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_tan(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the cosine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_cos(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the sine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_sin(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the Natural logarithm function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/ 
void der_r_log(coeff_t x , ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Derivatives of Exponential function.

@param x Evaluation point.
@param order Maximum order of derivative to be computed.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/ 
void der_r_exp(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Real derivatives of the power function. In particular useful for non integer exponents.

Evaluating    \f$    x^e    \f$

@param x Evaluation base of the power function.
@param e Exponent to power x.
@param order Maximum order of derivative to be retreived.
@param[out] derivs Array with the derivative information. It must come allocated.
******************************************************************************************************/ 
void der_r_pow(coeff_t x, coeff_t e, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ---------------------------------    MATH FUNCTIONS    ---------------------------------------------
// ----------------------------------------------------------------------------------------------------










// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------

darr_t darr_atanh(darr_t* arr);
void darr_atanh_to(darr_t* arr, darr_t* res);

darr_t darr_asinh(darr_t* arr);
void darr_asinh_to(darr_t* arr, darr_t* res);

darr_t darr_acosh(darr_t* arr);
void darr_acosh_to(darr_t* arr, darr_t* res);

darr_t darr_tanh(darr_t* arr);
void darr_tanh_to(darr_t* arr, darr_t* res);

darr_t darr_sqrt(darr_t* arr);
void darr_sqrt_to(darr_t* arr, darr_t* res);

darr_t darr_cosh(darr_t* arr);
void darr_cosh_to(darr_t* arr, darr_t* res);

darr_t darr_sinh(darr_t* arr);
void darr_sinh_to(darr_t* arr, darr_t* res);

darr_t darr_asin(darr_t* arr);
void darr_asin_to(darr_t* arr, darr_t* res);

darr_t darr_acos(darr_t* arr);
void darr_acos_to(darr_t* arr, darr_t* res);

darr_t darr_atan(darr_t* arr);
void darr_atan_to(darr_t* arr, darr_t* res);

darr_t darr_tan(darr_t* arr);
void darr_tan_to(darr_t* arr, darr_t* res);

darr_t darr_cos(darr_t* arr);
void darr_cos_to(darr_t* arr, darr_t* res);

darr_t darr_sin(darr_t* arr );
void darr_sin_to(darr_t* arr, darr_t* res);

darr_t darr_logb(darr_t* arr, double base);
void darr_logb_to(darr_t* arr, double base, darr_t* res);

darr_t darr_log10(darr_t* arr);
void darr_log10_to(darr_t* arr, darr_t* res);

darr_t darr_log(darr_t* arr);
void darr_log_to(darr_t* arr, darr_t* res);

darr_t darr_exp(darr_t* arr);
void darr_exp_to(darr_t* arr, darr_t* res);

darr_t darr_pow(darr_t* arr, double e);
void darr_pow_to(darr_t* arr, double e, darr_t* res);


darr_t darr_matmul(darr_t* arr1, darr_t* arr2 );
void darr_matmul_to(darr_t* arr1, darr_t* arr2, darr_t* aRes );

darr_t darr_transpose(darr_t* arr1);
void darr_transpose_to(darr_t* arr1, darr_t* aRes);

darr_t darr_invert(darr_t* arr1);
void darr_invert_to(darr_t* arr1, darr_t* aRes);

coeff_t darr_det( darr_t* arr1 );



// Self operations.
void darr_self_neg( darr_t* res);
void darr_self_sum_R(darr_t* arr1, darr_t* res);
void darr_self_sum_r(coeff_t num, darr_t* res);
void darr_self_sub_R(darr_t* arr1, darr_t* res);
void darr_self_sub_r(coeff_t num, darr_t* res);
void darr_self_mul_R(darr_t* arr1, darr_t* res);
void darr_self_mul_r(coeff_t num, darr_t* aRes);



/**************************************************************************************************//**
@brief Negate an array. 

@param[in]      p_arr1: Address of the array.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
void darr_neg_to(darr_t* arr1, darr_t* aRes);

darr_t darr_neg(darr_t* arr1);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise division of arrays. Must have same dimensions. 

@param[in] p_arr1: Address of the array 1.
@param[in] p_arr2: Address of the array 2.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
darr_t darr_div_RR(darr_t* arr1, darr_t* arr2);
darr_t darr_div_Rr(darr_t* arr1, coeff_t num);
darr_t darr_div_rR(coeff_t num, darr_t* arr1);

void darr_div_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
void darr_div_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes);
void darr_div_rR_to(coeff_t num, darr_t* arr2, darr_t* aRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise multiplication of arrays. Must have same dimensions. 

@param[in] p_arr1: Address of the array 1.
@param[in] p_arr2: Address of the array 2.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
darr_t darr_mul_RR(darr_t* arr1, darr_t* arr2);
darr_t darr_mul_rR(coeff_t num, darr_t* arr1);

void darr_mul_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
void darr_mul_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes);

void darr_mul_and_selfsum_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
void darr_mul_and_selfsum_rR_to(coeff_t num, darr_t* arr2, darr_t* aRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise subtraction of arrays. Must have same dimensions. 

@param[in] p_arr1: Address of the array 1.
@param[in] p_arr2: Address of the array 2.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
darr_t darr_sub_RR(darr_t* arr1, darr_t* arr2);
darr_t darr_sub_Rr(darr_t* arr1, coeff_t num);
darr_t darr_sub_rR(coeff_t num, darr_t* arr1);

void darr_sub_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
void darr_sub_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes);
void darr_sub_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise addition of arrays. Must have same dimensions. 

@param[in] p_arr1: Address of the array 1.
@param[in] p_arr2: Address of the array 2.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
darr_t darr_sum_RR(darr_t* arr1, darr_t* arr2);
darr_t darr_sum_rR(coeff_t num, darr_t* arr1);

void darr_sum_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
void darr_sum_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes);
// ----------------------------------------------------------------------------------------------------







void darr_set_all( coeff_t num, darr_t* arr);


/**************************************************************************************************//**
@brief Get element at position i,j in p_array. 

@param[inout] p_array: Address of the array.
@param[in] i: Row
@param[in] j: Column
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
coeff_t darr_get_item_ij(darr_t* arr, uint64_t i, uint64_t j);
coeff_t darr_get_item_i(darr_t* arr, uint64_t i);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set an item at position i,j in p_array. To be called only when p_array has already been created
and has some correct values in it.

@param[in] num: Value to be set.
@param[in] i: Row
@param[in] j: Column
@param[inout] p_array: Address of the array.
******************************************************************************************************/ 
void darr_set_item_ij( coeff_t num, uint64_t i, uint64_t j, darr_t* arr);
void darr_set_item_i( coeff_t num, uint64_t i, darr_t* arr);

// ----------------------------------------------------------------------------------------------------



darr_t   darr_copy(darr_t* src );
void     darr_copy_to(darr_t* src, darr_t* dst );
uint64_t darr_getSize(darr_t* arr);


/**************************************************************************************************//**
@brief C-level memory allocation of a real array setting all values to 1.

@param[inout] arr: Address of the array.
@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
darr_t darr_ones( uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of a real array setting all values to 0.

@param[inout] p_array: Address of the array.
@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
darr_t darr_zeros( uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of a real array creating an identity matrix.

@param[inout] p_array: Address of the array.
@param[in] size: Number of elements.
******************************************************************************************************/ 
darr_t darr_eye( uint64_t size);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free all memory associated with the array.

@param[inout] arr: Address of the array.
******************************************************************************************************/ 
void darr_free(darr_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of array.

@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
darr_t darr_createEmpty( uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif