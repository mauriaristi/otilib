// typedef struct{
//     sotinum_t*  p_data;   ///< Data array
//     uint64_t    nIntPts;  ///< Number of integration points.
// } fesoti_t;





// ****************************************************************************************************
void fesoti_set_all_o( sotinum_t* num, fesoti_t* res, dhelpl_t dhl){
    
    uint64_t i;

    for (i = 0; i<res->nIntPts; i++ ){
        
        soti_set_o( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fesoti_set_all_r( coeff_t num, fesoti_t* res, dhelpl_t dhl){
    
    uint64_t i;

    for (i = 0; i<res->nIntPts; i++ ){
        
        soti_set_r( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------











// ****************************************************************************************************
sotinum_t fesoti_get_item_k(fesoti_t* num, uint64_t k, dhelpl_t dhl){

    sotinum_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nIntPts){

        res = num->p_data[k];   
        res.flag = 0;

    } else {

        printf("ERROR: Index out of bounds in fesoti_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void fesoti_get_item_k_to(fesoti_t* num, uint64_t k, sotinum_t* res, dhelpl_t dhl){
    
    
    if (k < num->nIntPts){

        soti_copy_to( &num->p_data[k], res, dhl);

    } else {

        printf("ERROR: Index out of bounds in fesoti_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------











// ****************************************************************************************************
inline fesoti_t fesoti_createEmpty_bases(uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl){

    fesoti_t  res ;
    ndir_t p_nnz[_MAXORDER_OTI];
    ord_t    ordi;
    uint64_t i;    
    void * memory = NULL;

    for ( ordi = 0; ordi < order ; ordi++ ){

        p_nnz[ ordi ] = dhelp_ndirOrder( nbases, ordi+1 );

    }

    // Allocate memory and check if correctly allocated.
    memory = malloc( nIntPts * sizeof( sotinum_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of fesoti.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( sotinum_t* ) memory;
    res.nIntPts = nIntPts;

    // Loop for all elements in the array
    for(i = 0; i < res.nIntPts; i++){

        // Allocate every number as indicated
        res.p_data[i] = soti_createEmpty_predef( p_nnz, order, dhl);
    
    }

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------










// ****************************************************************************************************
void fesoti_free(fesoti_t* num){
    
    uint64_t i;

    // Free all memory within each coefficient in p_array

    if (num->p_data != NULL){

        // Free all arrays.
        for (i = 0; i<num->nIntPts; i++){
        
            soti_free(&num->p_data[i]); 

        }

        // Free pointer 
        free(num->p_data);

    }

    *num = fesoti_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline fesoti_t fesoti_init(void){
    
    fesoti_t res;
    
    res.p_data  = NULL;    
    res.nIntPts = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
inline fesoti_t fesoti_empty_like(fesoti_t* arr, dhelpl_t dhl){

    fesoti_t res = fesoti_createEmpty_bases(arr->nIntPts, 0, 0, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------




