
// ****************************************************************************************************
inline void {arr_func}_dimCheck_OO_elementwise({arr_type}* arr1,{arr_type}* arr2,{arr_type}* res){{

     if( arr1->size  != arr2->size  || 
         arr1->ncols != arr2->ncols ||
         arr1->nrows != arr2->nrows ||
         arr1->size  !=  res->size  || 
         arr1->ncols !=  res->ncols ||
         arr1->nrows !=  res->nrows    ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two {arr_func} arrays.\n");
        printf("Exiting from test.\n");
        error_exit(OTI_BadDim);
        // exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_dimCheck_RO_elementwise(darr_t* arr1,{arr_type}* arr2, {arr_type}* res){{

     if( arr1->size  != arr2->size  || 
         arr1->ncols != arr2->ncols ||
         arr1->nrows != arr2->nrows ||
         arr1->size  !=  res->size  || 
         arr1->ncols !=  res->ncols ||
         arr1->nrows !=  res->nrows    ){{
        printf("ERROR: Wrong dimensions in elementwise operation between {arr_func} and real arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_dimCheck_OO_matmul( {arr_type}* arr1, {arr_type}* arr2, {arr_type}* res){{

     if( arr1->ncols != arr2->nrows ||
         arr1->nrows !=  res->nrows || 
         arr2->ncols !=  res->ncols    ){{
        printf("lhs(%llu,%llu), rhs(%llu,%llu), res(%llu,%llu)\n", 
            arr1->nrows,arr1->ncols, 
            arr2->nrows,arr2->ncols,
             res->nrows, res->ncols  );
        printf("ERROR: Wrong dimensions in matmul-like operation between two {arr_func} arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_dimCheck_RO_matmul( darr_t* arr1, {arr_type}* arr2, {arr_type}* res){{

     if( arr1->ncols != arr2->nrows ||
         arr1->nrows !=  res->nrows || 
         arr2->ncols !=  res->ncols    ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and {arr_func} arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_dimCheck_OR_matmul( {arr_type}* arr1, darr_t* arr2, {arr_type}* res){{

     if( arr1->ncols != arr2->nrows ||
         arr1->nrows !=  res->nrows || 
         arr2->ncols !=  res->ncols    ){{
        printf("ERROR: Wrong dimensions in matmul-like operation between {arr_func} and darr arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_dimCheck_OO_samesize( {arr_type}* arr1, {arr_type}* arr2){{

     if( arr1->size != arr2->size ){{
        printf("ERROR: Arrays don't have the same number of elements.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_dimCheck_RO_samesize( darr_t* arr1, {arr_type}* arr2){{

     if( arr1->size != arr2->size ){{
        printf("ERROR: Arrays don't have the same number of elements.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void {arr_func}_dimCheck_O_squareness( {arr_type}* arr1, {arr_type}* res){{

     if( arr1->nrows != arr1->ncols ||
         arr1->nrows !=  res->nrows || 
         arr1->ncols !=  res->ncols    ){{
        printf("ERROR: Arrso array not square.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------