// c_otilib.c
#ifndef OTI_SPARSE_H
#define OTI_SPARSE_H
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
    double*         p_coefs;  // Array with all Coefficients. Shape: ( 1, Ndir)
    uint64_t*        p_indx;  // Directions associated to each coefficient.
    uint64_t           size;  // Number of directions in the number.
    uint8_t           order;  // Maximum order of the number.
} sotinum_t;

// typedef struct {
//     double               e0;  // "Element with order zero"
//     double*         p_coefs;  // Array with all Coefficients. Shape: ( 1, Ndir)
//     uint64_t*        p_indx;  // Directions associated to each coefficient.
//     uint64_t          csize;  // Number of directions in the number.
//     uint8_t           order;  // Maximum order of the number.
// } sotinume_t;  // Sparse OTI number, order-based 



// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd




// added to c_otilib.pxd


void c_soti_fdiv(double numx, sotinum_t* numy, sotinum_t* res, directionHelper* p_dH);

void c_soti_divf(sotinum_t* numx, double numy, sotinum_t* res);

void c_soti_div(sotinum_t* numx, sotinum_t* numy, sotinum_t* res, directionHelper* p_dH);

double c_soti_getReal(sotinum_t* num);

void c_soti_atan2(sotinum_t* numx, sotinum_t* numy, directionHelper* p_dH, sotinum_t* res);

void c_soti_logb(sotinum_t* num, int base, directionHelper* p_dH, sotinum_t* res);

void c_soti_log10(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_atanh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_asinh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_acosh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_tanh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_sqrt(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_cosh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_sinh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_asin(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_acos(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_atan(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_tan(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_cos(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_sin(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_log(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_exp(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);
 
void c_soti_derivFunc(double* fder, sotinum_t* g, directionHelper* p_dH, sotinum_t* feval);

void c_soti_smulf(sotinum_t* num1, double num2);

void c_soti_copy(sotinum_t* res, sotinum_t* num1);

void c_soti_pow(sotinum_t* num, double exponent, directionHelper* p_dH,sotinum_t* res);

void c_soti_ipowfast(sotinum_t* num1, uint8_t exp, sotinum_t* res, directionHelper* p_dH); 

void c_soti_ipow(sotinum_t* num1, uint8_t exp, sotinum_t* res, directionHelper* p_dH);

void c_soti_neg( sotinum_t* num1, sotinum_t* res);

void c_soti_fsub(sotinum_t* num1, double num2, sotinum_t* res);

void c_soti_subf(sotinum_t* num1, double num2, sotinum_t* res);

void c_soti_sub(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH);

void c_soti_sumf(sotinum_t* num1, double num2, sotinum_t* res);

void c_soti_mulf(sotinum_t* num1, double num2, sotinum_t* res);

void c_soti_mul(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH);

void c_soti_sum(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH);

void c_soti_free(sotinum_t* numHolder);

void c_soti_createFromReal(double num, sotinum_t* numHolder, uint8_t order);

void c_soti_createEmpty(sotinum_t* numHolder, uint64_t ncoefs, uint8_t order);

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------


#endif