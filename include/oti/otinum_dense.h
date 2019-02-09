#ifndef OTI_DENSE_H
#define OTI_DENSE_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "oti/core.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct {
    coeff_t          re;  //< Real Coefficient.
    coeff_t*       p_im;  //< Array of imaginary coefficients.
    ndir_t         ndir;  //< Number of imaginary directions.
    bases_t      nbases;  //< Number of bases.
    ord_t         order;  //< Truncation order. 
} otinum_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd







/**************************************************************************************************//**
@brief This function returns the starting poisition of the coefficients of the given order

@param[in] order Order of interest.
@param[in] num OTI number to look for order.
@param[inout] start Address of the starting coefficients (this will be returned).
@param[inout] ndir Total number of elements for the given order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_get_order_coeffs(ord_t order, otinum_t* num, coeff_t** start, ndir_t* ndir, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiplication between two oti numbers.

@param[in] num1 Oti number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_mul(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiplication of an oti numbers and a real number

@param[in] a Real number.
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_mul_real(coeff_t a, otinum_t* num1, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Addition of two oti numbers.

@param[in] num1 Oti number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sum(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Addition of one oti number and a scalar number.

@param[in] a Real number
@param[in] num1 Oti number. 
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sum_real(coeff_t a, otinum_t* num1, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Addition of one oti number and a scalar number, driven by an already created oti number.

@param[in] nbases New number of imaginary bases.
@param[in] num1 New truncation order of the number.
@param[inout] num Address of the oti number to receive the result.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_sum_real_r(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Set the value of an imaginary coefficient given the index and order.

@param[in] nbases Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[inout] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_setIm_IdxOrd( coeff_t a, imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocation of a dense oti number.

@param[in] nbases Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[inout] num Address of the object to be created.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_createEmpty( bases_t nbases, ord_t order, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

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


// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------





// added to c_otilib.pxd

// coomat_ui64_t c_oti_matform( uint64_t nvar, uint8_t order, directionHelper* p_dH);

// void c_oti_atan2(otinum_t* numx, otinum_t* numy, directionHelper* p_dH, otinum_t* res);

// void c_oti_logb(otinum_t* num, int base, directionHelper* p_dH, otinum_t* res);

// void c_oti_log10(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_atanh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_asinh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_acosh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_tanh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_sqrt(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_cosh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_sinh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_asin(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_acos(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_atan(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_tan(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_cos(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_sin(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_log(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_exp(otinum_t* num, directionHelper* p_dH, otinum_t* res);

// void c_oti_pow(otinum_t* num, double exponent, directionHelper* p_dH,otinum_t* res);

// double c_oti_FaaDiBruno(uint64_t indx, double* fder, otinum_t* g, directionHelper* p_dH);

// void c_oti_derivFunc(double* fder, otinum_t* g, directionHelper* p_dH, otinum_t* feval);

// void c_oti_collapseDirA(uint16_t* array, uint8_t order, uint16_t* dirA, uint8_t* expA);

// void c_oti_expandDirA(uint16_t* p_dirA,uint8_t* p_expA, uint8_t order, uint16_t* p_expandArr);

// double* c_oti_num2mat(otinum_t* num, uint64_t size, directionHelper* p_dH);

// void c_oti_mulf(otinum_t* num1, double num2, otinum_t* res);

// void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH);

// void c_oti_sub(otinum_t* num1, otinum_t* num2, otinum_t* res);

// void c_oti_neg(otinum_t* num1);

// void c_oti_changeOrderToNew(otinum_t* num, uint8_t neword, directionHelper* p_dH , otinum_t* res);

// void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res);

// void c_oti_free(otinum_t* numHolder);

// void c_oti_copy(otinum_t* numDest, otinum_t* numSrc); // inline

// void c_oti_changeOrder(otinum_t* num, uint8_t neword, directionHelper* p_dH );


#endif