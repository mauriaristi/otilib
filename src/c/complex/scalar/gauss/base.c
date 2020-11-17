// typedef struct{
//     coeff_t* p_data;  ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } fecnum_t;



// ****************************************************************************************************
fecnum_t fecnum_copy( fecnum_t* src){
    
    fecnum_t res = fecnum_init();

    res = fecnum_createEmpty(src->nip);

    fecnum_copy_to( src, &res);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fecnum_copy_to( fecnum_t* src, fecnum_t* dst){
    
    uint64_t i;

    fecnum_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        dst->p_data[i] = src->p_data[i];

    }

}
// ----------------------------------------------------------------------------------------------------














// ****************************************************************************************************
void fecnum_set_f( fecnum_t* num, fecnum_t* res){
    
    fecnum_copy_to(num,res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fecnum_set_r( coeff_t num, fecnum_t* res){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        res->p_data[i] =  num;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecnum_set_item_k_r(   coeff_t  num, uint64_t k, fecnum_t* res){

    if (k < res->nip){

        res->p_data[k] = num; 

    } else {

        printf("ERROR: Index out of bounds in fecnum_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
coeff_t fecnum_get_item_k(fecnum_t* num, uint64_t k){

    coeff_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

        res = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in fecnum_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fecnum_get_item_k_to(fecnum_t* num, uint64_t k, coeff_t* res){
    
    
    if (k < num->nip){

        (*res) = num->p_data[k];

    } else {

        printf("ERROR: Index out of bounds in fecnum_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------





























// ****************************************************************************************************
fecnum_t fecnum_zeros(uint64_t nip){

    fecnum_t  res  = fecnum_createEmpty(nip);
    
    fecnum_set_r( 0.0, &res);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline fecnum_t fecnum_createEmpty(uint64_t nip){

    fecnum_t  res ;   
    void * memory = NULL;

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( coeff_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle fecnum.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( coeff_t* ) memory;
    res.nip = nip;

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------










// ****************************************************************************************************
void fecnum_free(fecnum_t* num){
    
    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){

        // Free pointer 
        free(num->p_data);

    }

    *num = fecnum_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline fecnum_t fecnum_init(void){
    
    fecnum_t res;
    
    res.p_data  = NULL;    
    res.nip     = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline fecnum_t fecnum_empty_like(fecnum_t* src){

    fecnum_t res = fecnum_createEmpty( src->nip );

    return res;

}
// ----------------------------------------------------------------------------------------------------
