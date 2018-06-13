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
    double*         p_coefs;  // Array with all exponents. Shape: ( Ndir,  order)
    uint64_t           Ndir;  // Number of directions in the number.
    uint8_t           order;  // Maximum order of the number.
} otinum_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd

// added to c_otilib.pxd

coomat_ui64_t c_oti_matform( uint64_t nvar, uint8_t order, directionHelper* p_dH);

void c_oti_atan2(otinum_t* numx, otinum_t* numy, directionHelper* p_dH, otinum_t* res);

void c_oti_logb(otinum_t* num, int base, directionHelper* p_dH, otinum_t* res);

void c_oti_log10(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_atanh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_asinh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_acosh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_tanh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_sqrt(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_cosh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_sinh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_asin(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_acos(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_atan(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_tan(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_cos(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_sin(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_log(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_exp(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_pow(otinum_t* num, double exponent, directionHelper* p_dH,otinum_t* res);

double c_oti_FaaDiBruno(uint64_t indx, double* fder, otinum_t* g, directionHelper* p_dH);

void c_oti_derivFunc(double* fder, otinum_t* g, directionHelper* p_dH, otinum_t* feval);

void c_oti_collapseDirA(uint16_t* array, uint8_t order, uint16_t* dirA, uint8_t* expA);

void c_oti_expandDirA(uint16_t* p_dirA,uint8_t* p_expA, uint8_t order, uint16_t* p_expandArr);

double* c_oti_num2mat(otinum_t* num, uint64_t size, directionHelper* p_dH);

void c_oti_mulf(otinum_t* num1, double num2, otinum_t* res);

void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH);

void c_oti_sub(otinum_t* num1, otinum_t* num2, otinum_t* res);

void c_oti_neg(otinum_t* num1);

void c_oti_changeOrderToNew(otinum_t* num, uint8_t neword, directionHelper* p_dH , otinum_t* res);

void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res);

void c_oti_free(otinum_t* numHolder);

void c_oti_createEmpty(otinum_t* numHolder,   uint64_t ndir, uint8_t order);

void c_oti_copy(otinum_t* numDest, otinum_t* numSrc); // inline

void c_oti_changeOrder(otinum_t* num, uint8_t neword, directionHelper* p_dH );

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------


#endif