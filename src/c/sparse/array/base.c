

// typedef struct {
//     sotinum_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
// } arrso_t;                ///< Array of OTIs type.


// ****************************************************************************************************
void arrso_taylor_integrate_to( coeff_t* deltas, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;

    arrso_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){
        
        soti_taylor_integrate_to( deltas, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_taylor_integrate( coeff_t* deltas, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res;

    res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_taylor_integrate_to( deltas, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void arrso_get_order_im_to( ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;

    arrso_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){
        
        soti_get_order_im_to( order, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_get_order_im( ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res;

    res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_get_order_im_to( order, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void arrso_truncate_im_to( imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;

    arrso_dimCheck_OO_elementwise(arr,res,res);

    for (i = 0; i<arr->size; i++ ){
        
        soti_truncate_im_to( idx, order, &arr->p_data[i], &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_truncate_im( imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res;

    res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);

    arrso_truncate_im_to( idx, order, arr, &res, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------





// Copy operations.
// ****************************************************************************************************
void arrso_copy_to(arrso_t* arr, arrso_t* res, dhelpl_t dhl){

    uint64_t i;
    // TODO: add allocation check.
    if(res->nrows != arr->nrows || res->ncols != arr->ncols || res->size != arr->size){
        printf("ERROR: Assignment mismatch in dimensions. Check destination.\n");
        exit(OTI_undetErr);
    } 

    for (i=0; i<arr->size; i++){

        soti_copy_to(&arr->p_data[i],&res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_copy(arrso_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_empty_like(arr,dhl);

    arrso_copy_to(arr,&res,dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------








// Setters.
// Setter by one index.

// ****************************************************************************************************
inline void arrso_set_all_r( coeff_t num, arrso_t* arr, dhelpl_t dhl){
    
    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        arrso_set_item_i_r( num, i, arr, dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_r( coeff_t num, arrso_t* arr, dhelpl_t dhl){
    
    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        arrso_set_item_i_r( num, i, arr, dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_item_i_r( coeff_t num, uint64_t i, arrso_t* arr, dhelpl_t dhl){
        
    if( i<arr->size ){
        
        soti_set_r( num, &arr->p_data[i], dhl);

    } else {

        // res = soti_init();
        
        printf("ERROR: Index out of bounds in arrso_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl){

    arrso_set_item_i_r( num, j + i*arr->ncols, arr,  dhl);

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
inline void arrso_set_all_o( sotinum_t* num, arrso_t* arr, dhelpl_t dhl){

    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        arrso_set_item_i_o( num, i, arr, dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_o( sotinum_t* num, arrso_t* arr, dhelpl_t dhl){

    uint64_t i;

    for (i = 0; i<arr->size; i++ ){
        arrso_set_item_i_o( num, i, arr, dhl);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_item_i_o( sotinum_t* src, uint64_t i, arrso_t* arr, dhelpl_t dhl){
    
    if (i < arr->size){

        soti_copy_to(src, &arr->p_data[i],dhl);

    }  else {
        
        printf("ERROR: Index out of bounds in arrso_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_set_item_ij_o( sotinum_t* num, uint64_t i, uint64_t j, arrso_t* arr, dhelpl_t dhl){

    if ( i < arr->nrows && j < arr->ncols ){

        arrso_set_item_i_o( num, j + i*arr->ncols, arr, dhl);

    } else {

        printf("ERROR: Index out of bounds in arrso_get_item_ij(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_set_slice_O( arrso_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrso_t* res, dhelpl_t dhl){

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // printf("nrows: %lld, ncols %lld \n",nrows, ncols);

    // printf("i: (%lld, %lld, %lld) \n", starti, stopi, stepi);
    // printf("j: (%lld, %lld, %lld) \n", startj, stopj, stepj);

    // Check dimensions:
    if ( (arr->ncols != ncols) ||
         (arr->nrows != nrows)    ){

        printf("ERROR: Wrong dimensions for input array.\n");
        exit(OTI_BadIndx);

    }
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){

        jj = startj;
        
        for ( j = 0; j < ncols; j++){

            // printf("Setting result ( i, j) (%lld,%lld) from source (ii,jj) (%lld,%lld) \n", i, j, ii, jj);
            // printf("( i, j) (%lld,%lld) equates: %lld\n",  i,  j,  j +  i * res->ncols );
            // printf("(ii,jj) (%lld,%lld) equates: %lld\n", ii, jj, jj + ii * arr->ncols );

            soti_copy_to( &arr->p_data[  j +  i * arr->ncols ], 
                          &res->p_data[ jj + ii * res->ncols ], 
                          dhl);

            jj += stepj;
        
        }   

        ii += stepi;

    }



}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_set_slice_o( sotinum_t* num, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrso_t* res, dhelpl_t dhl){

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?
    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols < ncols) ||
         (res->nrows < nrows)    ){

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){

        jj = startj;
        
        for ( j = 0; j < ncols; j++){

            soti_set_o( num, 
                       &res->p_data[ jj + ii * res->ncols ],  
                        dhl);

            jj += stepj;
        
        }   

        ii += stepi;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_set_slice_r( coeff_t val, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrso_t* res, dhelpl_t dhl){

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // printf("nrows: %lld, ncols %lld \n",nrows, ncols);

    // printf("i: (%lld, %lld, %lld) \n", starti, stopi, stepi);
    // printf("j: (%lld, %lld, %lld) \n", startj, stopj, stepj);


    // Check dimensions:
    if ( (res->ncols < ncols) ||
         (res->nrows < nrows)    ){

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){

        jj = startj;
        
        for ( j = 0; j < ncols; j++){

            // printf("Setting result ( i, j) (%lld,%lld) from source (ii,jj) (%lld,%lld) \n", i, j, ii, jj);
            // printf("( i, j) (%lld,%lld) equates: %lld\n",  i,  j,  j +  i * res->ncols );
            // printf("(ii,jj) (%lld,%lld) equates: %lld\n", ii, jj, jj + ii * arr->ncols );

            soti_set_r( val, 
                        &res->p_data[ jj + ii * res->ncols ],  
                        dhl);

            jj += stepj;
        
        }   

        ii += stepi;

    }



}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_set_O( arrso_t* arrin, arrso_t* arr, dhelpl_t dhl){

    arrso_copy_to( arrin, arr, dhl);

}
// ----------------------------------------------------------------------------------------------------














































// ****************************************************************************************************
darr_t arrso_get_im(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    darr_t res = darr_zeros( arr->nrows, arr->ncols);
    uint64_t i;
    
    for( i = 0; i < arr->size ; i++ ){
        
        darr_set_item_i(  
            soti_get_item( idx, order, &arr->p_data[i],  dhl), 
            i, &res);

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
arrso_t arrso_extract_im(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_extract_im_to( idx, order, arr, &res, dhl);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_extract_im_to(imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check first dimensions.
    arrso_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
                
        soti_extract_im_to( idx, order, &arr->p_data[i], &res->p_data[i],  dhl);

    }
    
}
// ----------------------------------------------------------------------------------------------------










// ****************************************************************************************************
darr_t arrso_get_deriv(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    darr_t res = darr_zeros( arr->nrows, arr->ncols);
    uint64_t i;
    
    for( i = 0; i < arr->size ; i++ ){
        
        darr_set_item_i(  
            soti_get_deriv( idx, order, &arr->p_data[i],  dhl), 
            i, &res);

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------









// ****************************************************************************************************
arrso_t arrso_get_im_o(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_get_im_to( idx, order, arr, &res, dhl);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_get_im_to(imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check first dimensions.
    arrso_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
        
        soti_get_im_to_o( idx, order, &arr->p_data[i], &res->p_data[i],  dhl);

    }
    
}
// ----------------------------------------------------------------------------------------------------
















// ****************************************************************************************************
arrso_t arrso_get_deriv_o(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_get_deriv_to( idx, order, arr, &res, dhl);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_get_deriv_to(imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check first dimensions.
    arrso_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
        
        soti_get_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i],  dhl);

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_extract_deriv(imdir_t idx, ord_t order, arrso_t* arr, dhelpl_t dhl){
    
    arrso_t res = arrso_zeros_bases( arr->nrows, arr->ncols, 0, 0, dhl);
    
    arrso_extract_deriv_to( idx, order, arr, &res, dhl);

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_extract_deriv_to(imdir_t idx, ord_t order, arrso_t* arr, arrso_t* res, dhelpl_t dhl){
    
    uint64_t i;
    
    // Check first dimensions.
    arrso_dimCheck_OO_elementwise(arr,arr,res);

    for( i = 0; i < arr->size ; i++ ){
                
        soti_extract_deriv_to( idx, order, &arr->p_data[i], &res->p_data[i],  dhl);

    }
    
}
// ----------------------------------------------------------------------------------------------------



















// Getters.
// ****************************************************************************************************
inline sotinum_t arrso_get_item_i(arrso_t* arr, uint64_t i, dhelpl_t dhl){
    
    sotinum_t res;

    // Check boundness
    if (i < arr->size){

        res = arr->p_data[i];
        res.flag = 0;
        
    } else {

        // res = soti_init();
        
        printf("ERROR: Index out of bounds in arrso_get_item_i(...)\n Exiting...\n");
        exit(OTI_BadIndx);

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t arrso_get_item_ij(arrso_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl){

    sotinum_t res = arrso_get_item_i(arr, j + i*arr->ncols, dhl );

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_get_item_i_to(arrso_t* arr, uint64_t i, sotinum_t* res, dhelpl_t dhl){
    
    // Check boundness
    if (i < arr->size){

        soti_copy_to( &arr->p_data[i], res, dhl);
        
    } else {
        // Raise error?
        printf("ERROR: Index out of bounds in arrso_get_item_i_to(...)\n");
        exit(OTI_BadIndx);
    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_get_item_ij_to(arrso_t* arr, uint64_t i, uint64_t j, sotinum_t* res, dhelpl_t dhl){

    arrso_get_item_i_to(arr, j + i*arr->ncols, res, dhl);

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
arrso_t arrso_get_slice( arrso_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                        dhelpl_t dhl){

    uint64_t ncols, nrows; // Resulting number of rows and columns
    arrso_t res = arrso_init();

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);
    
    res = arrso_zeros_bases( nrows, ncols, 0, 0, dhl);

    arrso_get_slice_to( arr, starti, stopi, stepi, startj, stopj, stepj, &res, dhl);

    return res;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_get_slice_to( arrso_t* arr, 
                        int64_t starti, int64_t stopi, int64_t stepi,
                        int64_t startj, int64_t stopj, int64_t stepj,
                         arrso_t* res, dhelpl_t dhl){

    int64_t ncols = 0, nrows = 0; // Resulting number of rows and columns
    int64_t i, j, ii, jj; 

    // Handle broadcasting?

    nrows = slice_size(starti, stopi, stepi);
    ncols = slice_size(startj, stopj, stepj);

    // Check dimensions:
    if ( (res->ncols != ncols) || (res->nrows != nrows) ){

        printf("ERROR: Wrong dimensions resulting slicing array.\n");
        exit(OTI_BadIndx);

    }
    
    ii = starti;
    
    for ( i = 0; i < nrows; i++){

        jj = startj;
        
        for ( j = 0; j < ncols; j++){

            // printf("Setting result ( i, j) (%lld,%lld) from source (ii,jj) (%lld,%lld) \n", i, j, ii, jj);
            // printf("( i, j) (%lld,%lld) equates: %lld\n",  i,  j,  j +  i * res->ncols );
            // printf("(ii,jj) (%lld,%lld) equates: %lld\n", ii, jj, jj + ii * arr->ncols );

            soti_copy_to( &arr->p_data[ jj + ii * arr->ncols ], 
                          &res->p_data[  j +  i * res->ncols ], 
                          dhl);

            jj += stepj;
        
        }   

        ii += stepi;

    }

}
// ----------------------------------------------------------------------------------------------------
























// Memory management.


// ****************************************************************************************************
arrso_t arrso_eye_bases(uint64_t nrows, bases_t nbases, ord_t order, dhelpl_t dhl){

    arrso_t  res;
    uint64_t i;

    res = arrso_zeros_bases( nrows, nrows, nbases, order, dhl);
    
    for (i=0; i<res.nrows; i++ ){
        res.p_data[ i + i*res.ncols ].re = 1.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_ones_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl){

    arrso_t  res;
    uint64_t i;
    
    res = arrso_createEmpty_bases(nrows, ncols, nbases, order, dhl);

    for (i=0; i<res.size; i++ ){
        res.p_data[i].re = 1.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_zeros_bases(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl){
    
    arrso_t  res;
    uint64_t i;
    
    res = arrso_createEmpty_bases(nrows, ncols, nbases, order, dhl);
    
    for (i=0; i<res.size; i++ ){
        res.p_data[i].re = 0.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
arrso_t arrso_eye(uint64_t nrows, ndir_t* p_nnz, ord_t order, dhelpl_t dhl){

    arrso_t  res = arrso_zeros( nrows, nrows, p_nnz, order, dhl);
    uint64_t i;
    
    for (i=0; i<res.nrows; i++ ){
        
        res.p_data[ i + i*res.ncols ].re = 1.0;

    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_ones(uint64_t nrows, uint64_t ncols, ndir_t* p_nnz, ord_t order, dhelpl_t dhl){

    arrso_t  res = arrso_createEmpty_predef(nrows, ncols, p_nnz, order, dhl);
    uint64_t i;
    
    for (i=0; i<res.size; i++ ){
        res.p_data[i].re = 1.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
arrso_t arrso_zeros(uint64_t nrows, uint64_t ncols, ndir_t* p_nnz, ord_t order, dhelpl_t dhl){

    arrso_t  res = arrso_createEmpty_predef(nrows, ncols, p_nnz, order, dhl);
    uint64_t i;
    
    for (i=0; i<res.size; i++ ){
        res.p_data[i].re = 0.0;
    }
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void arrso_save(char* filename, arrso_t* arr, dhelpl_t dhl){
    
    uint64_t i;
    uint64_t mem_size=0;
    void *data = NULL;
    void *data_write;
    char *data_header;
    char magic[4] = {'\x93','O','T','I'}; 
    uint8_t major=1, minor = 0;
    uint8_t format=21;

    FILE* file_ptr = NULL;

    // check the memory required to store the array:
    for ( i=0; i < arr->size; i++ ){
        mem_size += soti_get_memsize_save( &arr->p_data[i], dhl);
    }

    // Header specifics for array
    // \x93OTI = 4 bytes
    //  Major version = 1 byte = 1
    //  Minor version = 1 byte = 0
    // format  1 byte == SOTI_SCALAR (20), SOTI_ARRAY(21), etc.
    // size of data (8 bytes) - uint64_t
    // if array, then
    // nrows = 8 bytes (uint64_t)
    // ncols = 8 bytes (uint64_t)

    

    // Allocate memory to be exported
    data = malloc(mem_size+64); // Add 64 byte header.
    if (data == NULL){
        printf("Memory error: Not enough memory to export array\n");
        exit(OTI_OutOfMemory);
    }

    
    data_header = (char*) data;
    memset(data_header, 0, 64); // Set all 64 bytes of header as zero.

    // write header
    memcpy(data_header, magic, 4);
    data_header += 4;

    data_header[0] = major;
    data_header[1] = minor;
    data_header[2] = format;
    data_header[3] = 0;

    data_header+=4;

    // set memory size
    memcpy(data_header, &mem_size, sizeof(uint64_t));
    data_header += sizeof(uint64_t);
    
    // set array nrows
    memcpy(data_header, &arr->nrows, sizeof(uint64_t));
    data_header += sizeof(uint64_t);
    
    // set array ncols
    memcpy(data_header, &arr->ncols, sizeof(uint64_t));
    data_header += sizeof(uint64_t);

    // Jump 64 bytes of header to write data.
    data_write = data + 64;
    for ( i=0; i < arr->size; i++ ){
        soti_save_to_mem( &arr->p_data[i],  data_write, dhl);
        // recompute OTI number size to jump to new storage point.
        data_write += soti_get_memsize_save( &arr->p_data[i], dhl);
    }

    file_ptr = fopen(filename, "wb");

    if (! file_ptr){
        printf("ERROR CREATING FILE\n");
        exit(OTI_undetErr);
    }

    fwrite(data,1,mem_size+64,file_ptr);

    fclose(file_ptr);

    free(data);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
arrso_t arrso_read(char* filename, dhelpl_t dhl){
    
    uint64_t i;
    uint64_t mem_size=0;
    uint64_t nrows=0,ncols=0;
    void *data = NULL;
    void *data_read;
    char data_header[64];
    char magic[4] = {'\x93','O','T','I'}; 
    // uint8_t major=1, minor = 0; // Version check.
    uint8_t format=21;
    // sotinum_t tmp2;
    arrso_t arr;

    FILE* file_ptr = NULL;

    file_ptr = fopen(filename, "rb");
    if (!file_ptr){
        printf("ERROR: Not such file or directory\n");
        exit(OTI_undetErr);
    }

    fread(data_header,1,64,file_ptr);

    for( i=0; i<4; i++){
        if (data_header[i]!=magic[i]){
            printf("ERROR: unrecognized file format\n");
            exit(OTI_undetErr);
        }
    }

    // TODO: Add version check.

    if (data_header[6]!= format){
        printf("ERROR: unrecognized data format\n");
        exit(OTI_undetErr);
    }

    
    memcpy(&mem_size, &data_header[8],sizeof(uint64_t));
    memcpy( &nrows,   &data_header[8+8], sizeof(uint64_t));
    memcpy( &ncols,   &data_header[8+16], sizeof(uint64_t));
    
    // printf("Read: mem_size %d, nrows = %d, ncols = %d\n",mem_size,nrows,ncols);
    arr = arrso_zeros_bases( nrows, ncols, 0, 0, dhl);
    
    // Allocate memory to be exported
    data = malloc(mem_size); 
    if (data == NULL){
        printf("Memory error: Not enough memory to read array\n");
        exit(OTI_OutOfMemory);
    }

    fread(data,1,mem_size,file_ptr);
    data_read = data;

    for ( i=0; i < arr.size; i++ ){
        // printf("iter %d\n",i);
        // tmp2 = soti_init();
        data_read = soti_read_from_mem_to( data_read, &arr.p_data[i], dhl);
        // data_read = soti_read_from_mem_to( data_read, &tmp2, dhl);
        // soti_print(&tmp2,dhl);
        // soti_free(&tmp2);
    }

    fclose(file_ptr);

    free(data);

    return arr;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline arrso_t arrso_empty_like(arrso_t* arr, dhelpl_t dhl){

    arrso_t  res;
    if (arr->size!=0){
        
        res = arrso_createEmpty_predef(arr->nrows, arr->ncols, arr->p_data[0].p_size, 
            arr->p_data[0].order, dhl);    

    }else{

        res = arrso_createEmpty_predef(arr->nrows, arr->ncols, NULL, 0, dhl);    

    }
    
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline arrso_t arrso_createEmpty_bases(uint64_t nrows, uint64_t ncols, 
                        bases_t nbases, ord_t order, dhelpl_t dhl){

    arrso_t  res ;
    ndir_t p_nnz[_MAXORDER_OTI];
    ord_t ordi;

    for ( ordi=0; ordi<order; ordi++){
        p_nnz[ordi] = dhelp_ndirOrder(nbases,ordi+1);
    }

    res = arrso_createEmpty_predef(nrows, ncols, p_nnz, order, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline arrso_t arrso_createEmpty_predef(uint64_t nrows, uint64_t ncols, 
                        ndir_t* p_nnz, ord_t order, dhelpl_t dhl){

    arrso_t  res = arrso_init();
    void*    memory = NULL;
    size_t   allocation_size;
    uint64_t i;
    allocation_size = arrso_memory_size( nrows * ncols, p_nnz, order);

    // Allocate memory and check if correctly allocated.
    memory = malloc(allocation_size);
    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of sparse otis.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    // Distributes the memory in the corresponding pointers. Sets the memory flag as 1.
    arrso_distribute_memory(memory, nrows, ncols, p_nnz, order, 1, &res);
    
    // Loop for all elements in the array
    for(i = 0; i < res.size; i++){

        // Allocate every number as indicated
        res.p_data[i] = soti_createEmpty_predef( p_nnz, order, dhl);
    
    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
size_t arrso_memory_size( uint64_t size,  ndir_t* p_nnz, ord_t order){

    size_t allocation_size = 0 ;

    // uint64_t otinum_size;

    //  Memory for p_data.
    allocation_size += size  * sizeof(sotinum_t); 
    
    // // Get the memory taken by each otinum.
    // otinum_size = soti_memory_size(p_nnz, order); 
    
    // // Add the memory of each otinum to the allocation size.
    // allocation_size += size * otinum_size;

    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_distribute_memory(void* mem, uint64_t nrows, uint64_t ncols,  ndir_t* p_nnz, 
                                ord_t order, flag_t flag, arrso_t* res){
    // size_t allocation_size=0;
    // uint64_t i;
    void* memory = mem;

    // flag_t otinum_flag = 0;

    // Set static elements accordingly.
    res->flag  = flag;
    res->nrows = nrows;
    res->ncols = ncols;
    res->size  = nrows * ncols;

    // Distribute data memory.
    res->p_data  = (sotinum_t* )memory;
    // memory    += res->size * sizeof(sotinum_t); // Move memory pointer.
    
    // // Loop for all elements in the array
    // for(i = 0; i < res->size; i++){
    //     // // Distribute the memory as required .
    //     // memory = soti_distribute_memory(memory, p_nnz, order, otinum_flag, & res->p_data[i]);

    //     // Allocate every number as indicated
    //     res->p_data[i] = soti_createEmpty_predef( p_nnz, order, dhl);
    
    // }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void arrso_free(arrso_t* arr){
    
    uint64_t i;

    for (i=0; i<arr->size; i++){
    
        soti_free( &arr->p_data[i] );
    
    }

    if ( (arr->flag != 0) && (arr->p_data!= NULL) ){
        
        free(arr->p_data);

    }

    (*arr) = arrso_init();

}
// ----------------------------------------------------------------------------------------------------





// Initialization
// ****************************************************************************************************
inline arrso_t arrso_init(void){

    arrso_t res;

    res.p_data = NULL;
    res.nrows = 0;
    res.ncols = 0;
    res.size  = 0;
    res.flag  = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------