#ifndef OTI_SPARSE_SCALAR_UTILS_H
#define OTI_SPARSE_SCALAR_UTILS_H

/**************************************************************************************************//**
@brief Truncated self addition of two oti numbers. This function adds num1 and num2 just to obtain 
imaginary directions with orders greater than the given truncation order.

@param[in]    num1 Oti number 1.
@param[in]    ord  Truncation order.
@param[inout] res  OTI number out. It most come allocated. 
@param[in]    dhl  Direction helper list object.
******************************************************************************************************/ 
void soti_trunc_ssum(sotinum_t* num1, ord_t ord, sotinum_t* res, dhelpl_t dhl );
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
void soti_trunc_mul(sotinum_t* num1, ord_t ord1, 
                    sotinum_t* num2, ord_t ord2, 
                    sotinum_t* dest, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply by real only coefficients with order ord and greater.

@param[in] a real number to be set.
@param[in] ord Order.
@param[in] res Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
void soti_trunc_smul_real(coeff_t a, ord_t ord, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Returns a list of the active bases in an OTI number.

@param[in] num OTI number to be analyzed.
@param[in] list Imaginary direction list where to set 
@param[in] res Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
void soti_get_active_bases(sotinum_t* num, imdir_t* list, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Returns the maximum imaginary basis being used in the number.

@param[in] num OTI number to be analyzed.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
bases_t soti_max_active_basis(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


#endif