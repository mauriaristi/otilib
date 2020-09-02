

// ****************************************************************************************************
inline void femdarr1_dimCheck_FF_samesize(femdarr1_t* arr1,femdarr1_t* arr2,femdnum1_t* res){

     if( arr1->size != arr2->size || arr1->nip != arr2->nip || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two femdarr1 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_OF_samesize(mdarr1_t* arr1,femdarr1_t* arr2, femdnum1_t* res){

     if( arr1->size != arr2->size || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between femdarr1 and real arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_RF_samesize(darr_t* arr1, femdarr1_t* arr2, femdnum1_t* res){

    if( arr1->size != arr2->size || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between femdarr1 and real arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_FF_elementwise(femdarr1_t* arr1,femdarr1_t* arr2,femdarr1_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two femdarr1 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_fF_elementwise(femdnum1_t* arr1,femdarr1_t* arr2,femdarr1_t* res){

     if( arr2->size !=  res->size || arr2->ncols !=  res->ncols || arr2->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two femdarr1 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_Ff_elementwise(femdarr1_t* arr1,femdnum1_t* arr2,femdarr1_t* res){

     if( arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two femdarr1 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_OF_elementwise(mdarr1_t* arr1,femdarr1_t* arr2, femdarr1_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr2->nip !=  res->nip   ){
        printf("ERROR: Wrong dimensions in elementwise operation between femdarr1 and real arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_RF_elementwise(darr_t* arr1, femdarr1_t* arr2, femdarr1_t* res){

    if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
        arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
        arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between femdarr1 and real arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_FfO_integrate(femdarr1_t* arr,femdnum1_t* num,mdarr1_t* res){

     if( arr->size !=  res->size || arr->ncols != res->ncols || arr->nrows != res->nrows ||
         arr->nip != num->nip   ){
        printf("ERROR: Wrong dimensions in integration operation between two femdarr1 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_FF_matmul( femdarr1_t* arr1, femdarr1_t* arr2, femdarr1_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip || 
        arr2->nip !=  res->nip      ){
       printf("ERROR: Wrong dimensions in matmul-like operation between two femdarr1 arrays.\n");
       exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_OF_matmul( mdarr1_t* arr1, femdarr1_t* arr2, femdarr1_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and femdarr1 arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_RF_matmul( darr_t* arr1, femdarr1_t* arr2, femdarr1_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and femdarr1 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_FO_matmul( femdarr1_t* arr1, mdarr1_t* arr2, femdarr1_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip    ){
        printf("ERROR: Wrong dimensions in matmul-like operation between femdarr1 and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_FR_matmul( femdarr1_t* arr1, darr_t* arr2, femdarr1_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip     ){
        printf("ERROR: Wrong dimensions in matmul-like operation between femdarr1 and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_F_squareness( femdarr1_t* arr1, femdarr1_t* res){

    if( arr1->ncols != arr1->nrows ||
        arr1->nrows !=  res->nrows || 
        arr1->ncols !=  res->ncols ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: femdarr1 array not square.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void femdarr1_dimCheck_F_transpose( femdarr1_t* arr1, femdarr1_t* res){

    if( arr1->nrows !=  res->ncols || 
        arr1->ncols !=  res->nrows ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: femdarr1 array not compliant with transpose operation.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void femdarr1_get_active_bases(femdarr1_t* arr, imdir_t* list_vals){
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<arr->nip; i++ ){
        
        mdarr1_get_active_bases( &arr->p_data[i], list_vals);
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

