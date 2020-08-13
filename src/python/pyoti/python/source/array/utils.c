
// ****************************************************************************************************
inline void arrso_dimCheck_OO_elementwise(arrso_t* arr1,arrso_t* arr2,arrso_t* res){{

     if( arr1->size  != arr2->size  || 
         arr1->ncols != arr2->ncols ||
         arr1->nrows != arr2->nrows ||
         arr1->size  !=  res->size  || 
         arr1->ncols !=  res->ncols ||
         arr1->nrows !=  res->nrows    ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two arrso arrays.\n");
        printf("Exiting from test.\n");
        error_exit(OTI_BadDim);
        // exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_dimCheck_RO_elementwise(darr_t* arr1,arrso_t* arr2, arrso_t* res){{

     if( arr1->size  != arr2->size  || 
         arr1->ncols != arr2->ncols ||
         arr1->nrows != arr2->nrows ||
         arr1->size  !=  res->size  || 
         arr1->ncols !=  res->ncols ||
         arr1->nrows !=  res->nrows    ){{
        printf("ERROR: Wrong dimensions in elementwise operation between arrso and real arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void arrso_dimCheck_OO_matmul( arrso_t* arr1, arrso_t* arr2, arrso_t* res){{

     if( arr1->ncols != arr2->nrows ||
         arr1->nrows !=  res->nrows || 
         arr2->ncols !=  res->ncols    ){{
        printf("lhs(%llu,%llu), rhs(%llu,%llu), res(%llu,%llu)\n", 
            arr1->nrows,arr1->ncols, 
            arr2->nrows,arr2->ncols,
             res->nrows, res->ncols  );
        printf("ERROR: Wrong dimensions in matmul-like operation between two arrso arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_dimCheck_RO_matmul( darr_t* arr1, arrso_t* arr2, arrso_t* res){{

     if( arr1->ncols != arr2->nrows ||
         arr1->nrows !=  res->nrows || 
         arr2->ncols !=  res->ncols    ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and arrso arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_dimCheck_OR_matmul( arrso_t* arr1, darr_t* arr2, arrso_t* res){{

     if( arr1->ncols != arr2->nrows ||
         arr1->nrows !=  res->nrows || 
         arr2->ncols !=  res->ncols    ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between arrso and darr arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_dimCheck_OO_samesize( arrso_t* arr1, arrso_t* arr2){{

     if( arr1->size != arr2->size ){{
        printf("ERROR: Arrays don't have the same number of elements.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_dimCheck_RO_samesize( darr_t* arr1, arrso_t* arr2){{

     if( arr1->size != arr2->size ){{
        printf("ERROR: Arrays don't have the same number of elements.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_dimCheck_O_squareness( arrso_t* arr1, arrso_t* res){{

     if( arr1->nrows != arr1->ncols ||
         arr1->nrows !=  res->nrows || 
         arr1->ncols !=  res->ncols    ){{
        printf("ERROR: Arrso array not square.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
ord_t arrso_get_order( arrso_t* arr ){{
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i=0; i<arr->size; i++ ){{
        
        order = MAX(order,arr->p_data[0].order);
    
    }}

    return order;
    
}}
// ----------------------------------------------------------------------------------------------------


