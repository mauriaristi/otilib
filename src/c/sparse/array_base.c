







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
    
    p_array->ncols  =    0;
    p_array->nrows  =    0;
    p_array->size   =    0;
    p_array->order  =    0;
    
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








