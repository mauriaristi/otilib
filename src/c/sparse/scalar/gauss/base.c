// typedef struct{
//     sotinum_t*  p_data;   ///< Data array
//     uint64_t    nip;  ///< Number of integration points.
// } fesoti_t;


// ****************************************************************************************************
ord_t fesoti_get_order( fesoti_t* num ){
    
    ord_t order = 0;
    uint64_t i;

    // Finds the maximum order in the array.
    for( i = 0; i<num->nip; i++ ){
        
        order = MAX(order,num->p_data[0].order);
    
    }

    return order;
    
}
// ----------------------------------------------------------------------------------------------------


























// ****************************************************************************************************
void fesoti_set_to( fesoti_t* src, fesoti_t* dst, dhelpl_t dhl){
    
    uint64_t i;

    fesoti_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        soti_copy_to( &src->p_data[i], &dst->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
fesoti_t fesoti_copy( fesoti_t* src, dhelpl_t dhl){
    
    fesoti_t res = fesoti_init();

    res = fesoti_createEmpty_bases(src->nip, 0,0, dhl);

    fesoti_copy_to( src, &res, dhl);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fesoti_copy_to( fesoti_t* src, fesoti_t* dst, dhelpl_t dhl){
    
    uint64_t i;

    fesoti_dimCheck(src,dst);

    for (i = 0; i<src->nip; i++ ){
        
        soti_copy_to( &src->p_data[i], &dst->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------














// ****************************************************************************************************
void fesoti_set_f( fesoti_t* num, fesoti_t* res, dhelpl_t dhl){
    
    fesoti_copy_to(num,res,dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fesoti_set_o( sotinum_t* num, fesoti_t* res, dhelpl_t dhl){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        soti_set_o( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fesoti_set_r( coeff_t num, fesoti_t* res, dhelpl_t dhl){
    
    uint64_t i;

    for (i = 0; i<res->nip; i++ ){
        
        soti_set_r( num, &res->p_data[i], dhl);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fesoti_set_item_k_o( sotinum_t* num, uint64_t k, fesoti_t* res, dhelpl_t dhl){
    
    if (k < res->nip){

        soti_set_o(num, &res->p_data[k], dhl); 

    } else {

        printf("ERROR: Index out of bounds in fesoti_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void fesoti_set_item_k_r(   coeff_t  num, uint64_t k, fesoti_t* res, dhelpl_t dhl){

    if (k < res->nip){

        soti_set_r(num, &res->p_data[k], dhl); 

    } else {

        printf("ERROR: Index out of bounds in fesoti_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t fesoti_get_item_k(fesoti_t* num, uint64_t k, dhelpl_t dhl){

    sotinum_t  res ;
    
    // TODO: Check dimensions
    
    if (k < num->nip){

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
    
    
    if (k < num->nip){

        soti_copy_to( &num->p_data[k], res, dhl);

    } else {

        printf("ERROR: Index out of bounds in fesoti_get_item_k.\n");
        exit(OTI_BadIndx); // TODO: Raise error instead of quitting the program.

    }

}
// ----------------------------------------------------------------------------------------------------





























// ****************************************************************************************************
fesoti_t fesoti_zeros_bases(uint64_t nip, bases_t nbases, ord_t order, dhelpl_t dhl){

    fesoti_t  res  = fesoti_createEmpty_bases(nip, nbases, order, dhl);
    
    fesoti_set_r( 0.0, &res, dhl);

    // This is returned uninitialized.
    return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline fesoti_t fesoti_createEmpty_bases(uint64_t nip, bases_t nbases, ord_t order, dhelpl_t dhl){

    fesoti_t  res ;
    ndir_t p_nnz[_MAXORDER_OTI];
    ord_t    ordi;
    uint64_t i;    
    void * memory = NULL;

    for ( ordi = 0; ordi < order ; ordi++ ){

        p_nnz[ ordi ] = dhelp_ndirOrder( nbases, ordi+1 );

    }

    // Allocate memory and check if correctly allocated.
    memory = malloc( nip * sizeof( sotinum_t ) );

    if ( memory == NULL ){
        printf("ERROR: Not enough memory to handle array of fesoti.\n Exiting...\n");
        exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
    }
    
    res.p_data = ( sotinum_t* ) memory;
    res.nip = nip;

    // Loop for all elements in the array
    for(i = 0; i < res.nip; i++){

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
        for (i = 0; i<num->nip; i++){
        
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
    res.nip = 0;

    return res;

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
inline fesoti_t fesoti_empty_like(fesoti_t* arr, dhelpl_t dhl){

    fesoti_t res = fesoti_createEmpty_bases(arr->nip, 0, 0, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------




