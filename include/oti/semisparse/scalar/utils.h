#ifndef OTI_SEMISPARSE_SCALAR_UTILS_H
#define OTI_SEMISPARSE_SCALAR_UTILS_H

/**************************************************************************************************//**
@brief Truncated self addition of two oti numbers. This function adds num1 and num2 just to obtain 
imaginary directions with orders greater than the given truncation order.

@param[in]    num1 Oti number 1.
@param[in]    ord  Truncation order.
@param[inout] res  OTI number out. It most come allocated. 
@param[in]    dhl  Direction helper list object.
******************************************************************************************************/ 
void ssoti_trunc_ssum(semiotin_t* num1, ord_t ord, semiotin_t* res, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncated integer power of an oti number. This function is useful for evaluation of functions 
at oti numbers.

The truncation is taken into account in the following manner. Ord1 and ord2 tells the function from 
which order to take into account the multiplication of coefficients from number 1 and number 2 
respectively. Then, standard OTI multiplication should be achieved if ord1 and ord2 are both equal 
to 0.

@param[in]    num1 Oti number 1.
@param[in]    ord1 Truncation order of num1. (>=1)
@param[in]    num2 Oti number 2.
@param[in]    ord2 Truncation order of num2. (>=1)
@param[inout] res  OTI number out. It most come allocated. 
@param[in]    dhl  Direction helper list object.
******************************************************************************************************/ 
void ssoti_trunc_mul(semiotin_t* num1, ord_t ord1, 
                    semiotin_t* num2, ord_t ord2, 
                    semiotin_t* dest, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply by real only coefficients with order ord and greater.

@param[in] a real number to be set.
@param[in] ord Order.
@param[in] res Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
void ssoti_trunc_smul_real(coeff_t a, ord_t ord, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



void ssoti_get_active_bases(semiotin_t* num, imdir_t* list, dhelpl_t dhl);



#endif