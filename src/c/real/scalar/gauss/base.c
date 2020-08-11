// typedef struct{
//     coeff_t* p_data;  ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } fednum_t;



// ****************************************************************************************************
fednum_t fednum_copy( fednum_t* src){
    
    fednum_t res = fednum_init();

    res = fednum_createEmpty(src->nip);

    fednum_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fednum_copy_to( fednum_t* src, fednum_t* dst){
    
    uint64_t i;

    fednum_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        dst->p_data[i] = src->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------














// ****************************************************************************************************
void fednum_set_f( fednum_t* num, fednum_t* res){
    
    fednum_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fednum_set_r( coeff_t num, fednum_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        res->p_data[i] =  num;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fednum_set_item_k_r(   coeff_t  num, uint64_t k, fednum_t* res){

    if (k < res->nip){

        res->p_data[k] = num; 

    } else {

        printf("ERROR: Index out of bounds in fednum_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
coeff_t fednum_get_item_k(fednum_t* num, uint64_t k){

    coeff_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in fednum_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fednum_get_item_k_to(fednum_t* num, uint64_t k, coeff_t* res){
    
    
    if (k < num->nip){

        (*res) = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in fednum_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------





























// ****************************************************************************************************
fednum_t fednum_zeros(uint64_t nip){

    fednum_t  res  = fednum_createEmpty(nip);
    
    fednum_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline fednum_t fednum_createEmpty(uint64_t nip){

    fednum_t  res ;   
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( coeff_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle fednum.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( coeff_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------










// ****************************************************************************************************
void fednum_free(fednum_t* num){
    
    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){

        // Free pointer 
        free(num->p_data);

    }

    *num = fednum_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline fednum_t fednum_init(void){
    
    fednum_t res;
    
    res.p_data  = NULL;    
    res.nip     = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline fednum_t fednum_empty_like(fednum_t* src){

    fednum_t res = fednum_createEmpty( src->nip );

    return res;

}
// ----------------------------------------------------------------------------------------------------
