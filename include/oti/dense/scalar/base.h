#ifndef OTI_DENSE_SCALAR_BASE_H
#define OTI_DENSE_SCALAR_BASE_H

// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd




/**************************************************************************************************//**
@brief Generate a temporal sparse otinum with the allocated data in the direction helper.

@param[in] ntmp Number of temporal array to be retreived.
@param[in] order Truncation order.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
otinum_t oti_get_tmp( ndir_t ntmp, ord_t order, bases_t nbases, dhelpl_t dhl);
otinum_t oti_get_rtmp( ndir_t ntmp, ord_t order, bases_t nbases, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Truncated self addition of two oti numbers. This function adds num1 and num2 just to obtain 
imaginary directions with orders greater than the given truncation order.

@param[in]    num1 Oti number 1.
@param[in]    ord  Truncation order.
@param[inout] res  OTI number out. It most come allocated. 
@param[in]    dhl  Direction helper list object.
******************************************************************************************************/ 
void oti_trunc_ssum(otinum_t* num1,  
                   ord_t ord, otinum_t* res,  dhelpl_t dhl );
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
void oti_trunc_mul(otinum_t* num1, ord_t ord1, 
	               otinum_t* num2, ord_t ord2, 
	               otinum_t* res, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncated Self multiplication of an oti number with a real number.

@param[in] a Real number.
@param[in] ord Truncation order.
@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_trunc_smul_real(coeff_t a, ord_t ord, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief  Set the value of an imaginary coefficient given the index and order.

@param[in] a Coefficient to be implemented.
@param[in] idx index of the imaginary direction.
@param[in] order Order of the imagianry direction.
@param[inout] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_setIm_IdxOrd( coeff_t a, imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Get the imaginary direction coefficient given the index and order.

@param[in] idx Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[in] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
coeff_t oti_get( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Get the derivative corresponding to the index and order.

@param[in] idx Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[in] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
coeff_t oti_get_deriv( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create Zero.

@param[in] nbases Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[inout] num Address of the object to be created.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_createZero( bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocation of a dense oti number.

@param[in] nbases Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[inout] num Address of the object to be created.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_createEmpty( bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize otinum_t struct, Initializing all pointers to NULL and seting order to 0.

******************************************************************************************************/ 
otinum_t oti_init( void );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Assign an oti number copying the values from another oti number.

@param[in] OTI number.
@param[inout] num Address of the oti number to be assigned.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_copy(otinum_t* num, dhelpl_t dhl);
void     oti_copy_to( otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void oti_setup(otinum_t* num,  bases_t nbases, ord_t order, dhelpl_t dhl );

/**************************************************************************************************//**
@brief Assign an oti number the value of a given real number.

@param[in] a Real number.
@param[inout] num Address of the oti number to be assigned
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_setFromReal( coeff_t a, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Print an oti number to console.

@param[in] num Address of the oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_print( otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free the memory in an oti number object.

@param[in] num Address of the oti number.  
******************************************************************************************************/ 
void oti_free( otinum_t* num );
// ----------------------------------------------------------------------------------------------------

#endif