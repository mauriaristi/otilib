
// ****************************************************************************************************
inline void oarrm2n9_dimCheck_OO_elementwise(oarrm2n9_t* arr1,oarrm2n9_t* arr2,oarrm2n9_t* res){

     if( arr1->size  != arr2->size  || 
         arr1->ncols != arr2->ncols ||
         arr1->nrows != arr2->nrows ||
         arr1->size  !=  res->size  || 
         arr1->ncols !=  res->ncols ||
         arr1->nrows !=  res->nrows    ){
        printf("ERROR: Wrong dimensions in elementwise operation between two oarrm2n9 arrays.\n");
        printf("Exiting from test.\n");
        error_exit(OTI_BadDim);
        // exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm2n9_dimCheck_RO_elementwise(darr_t* arr1,oarrm2n9_t* arr2, oarrm2n9_t* res){

     if( arr1->size  != arr2->size  || 
         arr1->ncols != arr2->ncols ||
         arr1->nrows != arr2->nrows ||
         arr1->size  !=  res->size  || 
         arr1->ncols !=  res->ncols ||
         arr1->nrows !=  res->nrows    ){
        printf("ERROR: Wrong dimensions in elementwise operation between oarrm2n9 and real arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm2n9_dimCheck_OO_matmul( oarrm2n9_t* arr1, oarrm2n9_t* arr2, oarrm2n9_t* res){

     if( arr1->ncols != arr2->nrows ||
         arr1->nrows !=  res->nrows || 
         arr2->ncols !=  res->ncols    ){
        printf("lhs(%llu,%llu), rhs(%llu,%llu), res(%llu,%llu)\n", 
            arr1->nrows,arr1->ncols, 
            arr2->nrows,arr2->ncols,
             res->nrows, res->ncols  );
        printf("ERROR: Wrong dimensions in matmul-like operation between two oarrm2n9 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm2n9_dimCheck_RO_matmul( darr_t* arr1, oarrm2n9_t* arr2, oarrm2n9_t* res){

     if( arr1->ncols != arr2->nrows ||
         arr1->nrows !=  res->nrows || 
         arr2->ncols !=  res->ncols    ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and oarrm2n9 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm2n9_dimCheck_OR_matmul( oarrm2n9_t* arr1, darr_t* arr2, oarrm2n9_t* res){

     if( arr1->ncols != arr2->nrows ||
         arr1->nrows !=  res->nrows || 
         arr2->ncols !=  res->ncols    ){
        printf("ERROR: Wrong dimensions in matmul-like operation between oarrm2n9 and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm2n9_dimCheck_OO_samesize( oarrm2n9_t* arr1, oarrm2n9_t* arr2){

     if( arr1->size != arr2->size ){
        printf("ERROR: Arrays don't have the same number of elements.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm2n9_dimCheck_RO_samesize( darr_t* arr1, oarrm2n9_t* arr2){

     if( arr1->size != arr2->size ){
        printf("ERROR: Arrays don't have the same number of elements.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void oarrm2n9_dimCheck_O_squareness( oarrm2n9_t* arr1, oarrm2n9_t* res){

     if( arr1->nrows != arr1->ncols ||
         arr1->nrows !=  res->nrows || 
         arr1->ncols !=  res->ncols    ){
        printf("ERROR: Arrso array not square.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
ord_t oarrm2n9_get_order( oarrm2n9_t* arr ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i=0; i<arr->size; i++ ){
        
        order = MAX( order, onumm2n9_get_order(&arr->p_data[i]) );
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarrm2n9_get_active_bases(oarrm2n9_t* arr, imdir_t* list_vals){
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i = 0; i < arr->size; i++ ){
        
        onumm2n9_get_active_bases( &arr->p_data[i], list_vals);
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

