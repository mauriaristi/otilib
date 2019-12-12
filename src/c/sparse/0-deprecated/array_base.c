







// Setters.

// ****************************************************************************************************
void soarr_setItemR_indx( double num, uint64_t i, soarr_t* p_array){
        
    sotinum_t* tmp = &p_array->p_data[i];
    soti_free(tmp);
    soti_createEmpty(tmp, 1, p_array->order);
    tmp->p_coefs[0] = num;
    tmp->p_indx[0]  = 0; 

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soarr_setItemR( double num, uint64_t i, uint64_t j, soarr_t* p_array){
    
    sotinum_t* tmp = &p_array->p_data[j+i*p_array->ncols];
    soti_free(tmp);
    soti_createEmpty(tmp, 1, p_array->order);
    tmp->p_coefs[0] = num;
    tmp->p_indx[0]  = 0; 

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void soarr_setItemOTI_indx( sotinum_t* num, uint64_t i, soarr_t* p_array){
    
    soti_free(&p_array->p_data[i]);
    p_array->p_data[i] = num[0]; // Does not copy coefficients, just takes the pointer!

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soarr_setAllItems( sotinum_t* num, soarr_t* p_array){
    
    uint64_t i;
    sotinum_t tmp;

    for (i=0; i<p_array->size; i++){
    
        soti_free(&p_array->p_data[i]);
        soti_copy(&tmp,num);
        p_array->p_data[i] = tmp;

    }
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soarr_setItemOTI( sotinum_t* num, uint64_t i, uint64_t j, soarr_t* p_array){

    soti_free(&p_array->p_data[j+i*p_array->ncols]);

    // Does not copy coefficients, just takes the pointer! Less efficient?
    p_array->p_data[j+i*p_array->ncols] = num[0]; 

}
// ----------------------------------------------------------------------------------------------------

































// Getters.


// ****************************************************************************************************
void soarr_getItem(soarr_t* p_array, uint64_t i, uint64_t j, sotinum_t* num){
    
    num[0] = p_array->p_data[j+i*p_array->ncols];

}
// ----------------------------------------------------------------------------------------------------




























// Copy operations.

































// Helpers.

































// Memory management.


// ****************************************************************************************************
void soarr_zeros(soarr_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order){
    
    uint64_t i;
    sotinum_t value;

    value.p_coefs=  NULL;
    value.p_indx =  NULL;
    value.size   =     0;
    value.order  = order;

    p_array->ncols  = ncols       ;
    p_array->nrows  = nrows       ;
    p_array->size   = ncols*nrows ;
    p_array->order  = order       ;
    p_array->p_data = (sotinum_t*) malloc( p_array->size * sizeof(sotinum_t) );

    if (p_array->p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    for( i = 0; i < p_array->size; i++){

        p_array->p_data[i] = value;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soarr_free(soarr_t* p_array){
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if( p_array->p_data != NULL && p_array->size != 0){

        for (i = 0; i<p_array->size; i++){
            
            soti_free(&p_array->p_data[i]); 

        }
        free( p_array->p_data);
        p_array->p_data = NULL;

    }

    // Free pointer 
    
    p_array->ncols  = 0;
    p_array->nrows  = 0;
    p_array->size   = 0;
    p_array->order  = 0;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soarr_createEmpty(soarr_t* p_array, uint64_t nrows, uint64_t ncols, uint8_t order){
    
    p_array->ncols  = ncols;
    p_array->nrows  = nrows;
    p_array->size   = ncols*nrows;
    p_array->order  = order;
    p_array->p_data = (sotinum_t*) malloc( p_array->size * sizeof(sotinum_t) );

    if (p_array->p_data == NULL){
        printf("--- MemoryError ---\n");
        exit(1);
    }

    // Initialize all values of the number to 0.
    // for(){

    // }

}
// ----------------------------------------------------------------------------------------------------




// typedef struct {
//     coeff_t          re; ///< Real coefficient.
//     coeff_t**      p_im; ///< Array with all imaginary coefficients per order.
//     imdir_t**     p_idx; ///< Directions associated to each coefficient per order.
//     ndir_t*       p_nnz; ///< Number of non zero coefficients per order.
//     ndir_t*      p_size; ///< Allocated size per order.
//     ord_t         order; ///< Truncation order of the number.
//     flag_t         flag; ///< Memory flag.
// } sotinum_t;             ///< Sparse OTI number type


// typedef struct {
//     sotinum_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
// } soarr_t;                ///< SOTI array type.





// ****************************************************************************************************
size_t soarr_memory_size( uint64_t size, ndir_t* p_nnz, ord_t order){

    size_t allocation_size = 0 ;
    ord_t i = 0;


    allocation_size += order * sizeof(ndir_t);    //  Memory for common size array.
    allocation_size += size  * sizeof(sotinum_t); //  Memory for all elements .

    if (order != 0){
        
        // Get the allocation size of the OTI number:
        allocation_size = size * order * (sizeof(coeff_t*)+ // for p_im
                                          sizeof(imdir_t*)+ // for p_idx
                                          sizeof(ndir_t)+   // for p_nnz
                                          );

        // Add the standard allocation sizes:
        for ( i = 0; i < order; i++){
            
            allocation_size += size * p_nnz[i] * ( sizeof(coeff_t)+
                                                   sizeof(imdir_t)
                                                 );

        }

    }

    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_distribute_memory(void* memory, ndir_t* p_nnz, ord_t order, flag_t flag, sotinum_t* res){

    ord_t i;

    res->order = order;

    // Distribute memory among the different pointers.
    res->p_im  = (coeff_t**)memory;
    memory    += res->order * sizeof(coeff_t*);

    res->p_idx = (imdir_t**)memory;
    memory    += res->order * sizeof(imdir_t*);

    res->p_nnz = (ndir_t*  )memory;
    memory    += res->order * sizeof(ndir_t);

    res->p_size= (ndir_t*  )memory;
    memory    += res->order * sizeof(ndir_t);
    
    for ( i = 0; i < res->order; i++){
        
        // Distribute memory.
        res->p_im[i] = (coeff_t*)memory;
        memory += p_nnz[i]*sizeof(coeff_t); 

        res->p_idx[i]= (imdir_t*)memory;
        memory += p_nnz[i]*sizeof(imdir_t); 

        // Set number of non-zero and allocated size to 0.
        res->p_size[i] = p_nnz[i]; 
        res->p_nnz[i]  = 0; 

    }

    // Raise flag for OTI number.
    res->flag = flag;

}
// ----------------------------------------------------------------------------------------------------
























































































// Setters.
// Setter by one index.
// ****************************************************************************************************
void oarr_set_all_r( coeff_t num, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_set_item_i_r( coeff_t num, uint64_t i, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_set_all_o( otinum_t* num, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_set_item_i_o( otinum_t* num, uint64_t i, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_set_item_ij_o( otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------


// Getters.
// ****************************************************************************************************
otinum_t oarr_get_item_i(oarr_t* arr, uint64_t i, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oarr_get_item_ij(oarr_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_get_item_i_to(oarr_t* arr, uint64_t i,  otinum_t* res, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_get_item_ij_to(oarr_t* arr, uint64_t i, uint64_t j, otinum_t* res, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------


// Copy operations.
// ****************************************************************************************************
void oarr_copy_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
oarr_t oarr_copy(oarr_t* arr, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// Helpers.

// Memory management.
// ****************************************************************************************************
soarr_t oarr_eye(uint64_t size, bases_t nbases, ord_t order, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
soarr_t oarr_ones(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
soarr_t oarr_zeros(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_free(soarr_t* arr)
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
soarr_t oarr_createEmpty( uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl)
// ----------------------------------------------------------------------------------------------------





