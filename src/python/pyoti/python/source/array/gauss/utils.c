

// ****************************************************************************************************
inline void fearrso_dimCheck_FF_samesize(fearrso_t* arr1,fearrso_t* arr2,fesoti_t* res){{

     if( arr1->size != arr2->size || arr1->nip != arr2->nip || arr2->nip != res->nip ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two fearrso arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrso_dimCheck_OF_samesize(arrso_t* arr1,fearrso_t* arr2, fesoti_t* res){{

     if( arr1->size != arr2->size || arr2->nip != res->nip ){{
        printf("ERROR: Wrong dimensions in elementwise operation between fearrso and real arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrso_dimCheck_RF_samesize(darr_t* arr1, fearrso_t* arr2, fesoti_t* res){{

    if( arr1->size != arr2->size || arr2->nip != res->nip ){{
        printf("ERROR: Wrong dimensions in elementwise operation between fearrso and real arrays.\n");
        exit(OTI_BadDim);
    }}

}}
// ----------------------------------------------------------------------------------------------------
















// ****************************************************************************************************
inline void fearrso_dimCheck_FF_elementwise(fearrso_t* arr1,fearrso_t* arr2,fearrso_t* res){{

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two fearrso arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrso_dimCheck_fF_elementwise(fesoti_t* arr1,fearrso_t* arr2,fearrso_t* res){{

     if( arr2->size !=  res->size || arr2->ncols !=  res->ncols || arr2->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two fearrso arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrso_dimCheck_Ff_elementwise(fearrso_t* arr1,fesoti_t* arr2,fearrso_t* res){{

     if( arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two fearrso arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrso_dimCheck_OF_elementwise(arrso_t* arr1,fearrso_t* arr2, fearrso_t* res){{

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr2->nip !=  res->nip   ){{
        printf("ERROR: Wrong dimensions in elementwise operation between fearrso and real arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrso_dimCheck_RF_elementwise(darr_t* arr1, fearrso_t* arr2, fearrso_t* res){{

    if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
        arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
        arr2->nip != res->nip                         ){{
        printf("ERROR: Wrong dimensions in elementwise operation between fearrso and real arrays.\n");
        exit(OTI_BadDim);
    }}

}}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
inline void fearrso_dimCheck_FfO_integrate(fearrso_t* arr,fesoti_t* num,arrso_t* res){{

     if( arr->size !=  res->size || arr->ncols != res->ncols || arr->nrows != res->nrows ||
         arr->nip != num->nip   ){{
        printf("ERROR: Wrong dimensions in integration operation between two fearrso arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------











// ****************************************************************************************************
inline void fearrso_dimCheck_FF_matmul( fearrso_t* arr1, fearrso_t* arr2, fearrso_t* res){{

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip || 
        arr2->nip !=  res->nip      ){{
       printf("ERROR: Wrong dimensions in matmul-like operation between two fearrso arrays.\n");
       exit(OTI_BadDim);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrso_dimCheck_OF_matmul( arrso_t* arr1, fearrso_t* arr2, fearrso_t* res){{

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and fearrso arrays.\n");
        exit(OTI_BadDim);
    }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrso_dimCheck_RF_matmul( darr_t* arr1, fearrso_t* arr2, fearrso_t* res){{

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and fearrso arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline void fearrso_dimCheck_FO_matmul( fearrso_t* arr1, arrso_t* arr2, fearrso_t* res){{

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip    ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between fearrso and darr arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrso_dimCheck_FR_matmul( fearrso_t* arr1, darr_t* arr2, fearrso_t* res){{

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip     ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between fearrso and darr arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------












// ****************************************************************************************************
inline void fearrso_dimCheck_F_squareness( fearrso_t* arr1, fearrso_t* res){{

    if( arr1->ncols != arr1->nrows ||
        arr1->nrows !=  res->nrows || 
        arr1->ncols !=  res->ncols ||
        arr1->nip !=  res->nip   ){{
        printf("ERROR: fearrso array not square.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline void fearrso_dimCheck_F_transpose( fearrso_t* arr1, fearrso_t* res){{

    if( arr1->nrows !=  res->ncols || 
        arr1->ncols !=  res->nrows ||
        arr1->nip !=  res->nip   ){{
        printf("ERROR: fearrso array not compliant with transpose operation.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void fearrso_get_active_bases(fearrso_t* arr, imdir_t* list_vals){{
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<arr->nip; i++ ){{
        
        arrso_get_active_bases( &arr->p_data[i], list_vals, dhl);
    
    }}
    
}}
// ----------------------------------------------------------------------------------------------------











