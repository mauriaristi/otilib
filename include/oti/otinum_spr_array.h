// c_otilib.c
#ifndef OTI_SPR_ARRAY_H
#define OTI_SPR_ARRAY_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------
#include "oti/darray.h"
#include "oti/otinum_spr.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------


typedef struct{
    sotinum_t*    p_data; // Data array
    uint64_t       nrows; // Number of rows.
    uint64_t       ncols; // Number of cols.
    uint64_t        size; // Total size of the array.
    uint8_t        order;
} sotiarray_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd



// added to c_otilib.pxd

void c_sotiarray_setItemR_indx( double num, uint64_t i, sotiarray_t* p_array);

void c_sotiarray_setItemOTI_indx( sotinum_t* num, uint64_t i, sotiarray_t* p_array);

void c_sotiarray_oti_div(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_matdiv_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_div_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes);

void c_sotiarray_R_div(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_div_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_invert(sotiarray_t* p_arr1, sotiarray_t* p_arrRes, directionHelper* p_dH);

void c_sotiarray_det(sotiarray_t* p_arr1, sotinum_t* p_res, directionHelper* p_dH);

void c_sotiarray_transpose(sotiarray_t* p_arr1, sotiarray_t* p_arrRes);

void c_sotiarray_mul_sotiarr(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_neg(sotiarray_t* p_arr1, sotiarray_t* p_arrRes);

void c_sotiarray_matsub_Roti(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes);

void c_sotiarray_matsub_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes);

void c_sotiarray_matsub_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_oti_sub(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_R_sub(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes);

void c_sotiarray_sub_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_sub_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes);

void c_sotiarray_mul_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_mul_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes);

void c_sotiarray_sum_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_sum_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes); 

void c_sotiarray_matmul_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_matmul_Roti(darray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_matmul_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_matsum_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes);

void c_sotiarray_matsum_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_getItem(sotiarray_t* p_array, uint64_t i, uint64_t j, sotinum_t* num);

void c_sotiarray_setItemR( double num, uint64_t i, uint64_t j,sotiarray_t* p_array);

void c_sotiarray_setAllItems( sotinum_t* num, sotiarray_t* p_array);

void c_sotiarray_setItemOTI( sotinum_t* num, uint64_t i, uint64_t j,sotiarray_t* p_array);

void c_sotiarray_zeros(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, uint8_t order);

void c_sotiarray_free(sotiarray_t* p_array);

void c_sotiarray_createEmpty(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, uint8_t order);

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif