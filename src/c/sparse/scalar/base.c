





// Temporal number extractors.

// ****************************************************************************************************
sotinum_t soti_get_rtmp(ndir_t ntmp, ord_t order, dhelpl_t dhl){
    
    sotinum_t res;
    ord_t i=0;

    if (order == 0){
        // In case order==0, no allocated array exists.
        res = soti_createEmpty(0,dhl);
        return res;
    }
    if (order > dhl.ndh){
        printf("ERROR: Maximum order not allowed in soti_get_rtmp.\n");
        exit(OTI_undetErr);
    }
    if (ntmp >= dhl.p_dh[order-1].Ntmps){
        printf("ERROR: Trying to get a temporal that does not exist.\n");
        exit(OTI_undetErr);   
    }

    res.p_im   = dhl.p_dh[order-1].p_ims[ntmp]; 
    res.p_idx  = dhl.p_dh[order-1].p_ids[ntmp]; 
    res.p_nnz  = dhl.p_dh[order-1].p_nnz[ntmp]; 
    res.p_size = dhl.p_dh[order-1].p_size[ntmp]; 
    res.order  = order; 

    for (i=0; i<order; i++){

        res.p_im[i]  = dhl.p_dh[i].p_im[ntmp];
        res.p_idx[i] = dhl.p_dh[i].p_idx[ntmp];
        res.p_nnz[i] = 0; // Initialize to zero elements.
        res.p_size[i]= dhl.p_dh[i].Ndir;

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_get_tmp(ndir_t ntmp, ord_t order, dhelpl_t dhl){
    
    sotinum_t res;
    ord_t i=0;

    if (order == 0){
        // In case order==0, no allocated array exists.
        res = soti_createEmpty(0,dhl);
        return res;
    }
    if (order > dhl.ndh){
        printf("ERROR: Maximum order not allowed in soti_get_tmp.\n");
        exit(OTI_undetErr);
    }
    if (ntmp >= (dhl.p_dh[order-1].Ntmps - 10) ){
        printf("ERROR: Trying to get a temporal that does not exist.\n");
        exit(OTI_undetErr);   
    }

    res.p_im   = dhl.p_dh[order-1].p_ims[ ntmp+10]; 
    res.p_idx  = dhl.p_dh[order-1].p_ids[ ntmp+10]; 
    res.p_nnz  = dhl.p_dh[order-1].p_nnz[ ntmp+10]; 
    res.p_size = dhl.p_dh[order-1].p_size[ntmp+10]; 
    res.order  = order; 

    for (i=0; i<order; i++){

        res.p_im[i]  = dhl.p_dh[i].p_im[ntmp+10];
        res.p_idx[i] = dhl.p_dh[i].p_idx[ntmp+10];
        res.p_nnz[i] = 0; // Initialize to zero elements.
        res.p_size[i]= dhl.p_dh[i].Ndir;

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------



















// Setter.

// ****************************************************************************************************
void soti_insert_item( ndir_t pos, coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, 
    dhelpl_t dhl){
    
    

    coeff_t* p_tmpim  = NULL;
    imdir_t* p_tmpidx = NULL;

    if ( num->p_nnz[order-1] == num->p_size[order-1] ){
        // Reallocation in memory is necessary.

        num->p_nnz[order-1] += _REALLOC_SIZE;

        sotinum_t tmp = soti_createEmpty_like(num,dhl);

        num->p_nnz[order-1] -= _REALLOC_SIZE;
        
        soti_copy_to( num, &tmp, dhl);
        
        soti_free(num);
        
        *num = tmp;

    }

    if (pos < num->p_nnz[order-1]){
        // Memory copy is necesary

        //get temporal pointers
        p_tmpim = dhl.p_dh[order-1].p_im[0];
        p_tmpidx= dhl.p_dh[order-1].p_idx[0];

        // copy to pointer:
        memcpy(p_tmpim ,&num->p_im[order-1][pos] ,(num->p_nnz[order-1]-pos)*sizeof(coeff_t));
        memcpy(p_tmpidx,&num->p_idx[order-1][pos],(num->p_nnz[order-1]-pos)*sizeof(imdir_t));

        // copy back to new position
        memcpy(&num->p_im[order-1][pos+1] ,p_tmpim ,(num->p_nnz[order-1]-pos)*sizeof(coeff_t));
        memcpy(&num->p_idx[order-1][pos+1],p_tmpidx,(num->p_nnz[order-1]-pos)*sizeof(imdir_t));        
        
    }

    // Set the new position.
    num->p_im[order-1][pos] = val;
    num->p_idx[order-1][pos] = idx;
    num->p_nnz[order-1] += 1;
    

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void soti_set_item(coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    flag_t flag;
    imdir_t pos;
    
    if (order == 0){
        
        num->re = val;

    }else{

        if ( order <= num->order ){

            pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );

            if ( flag != 0 ){

                // pos exists within num and already contains a value.
                num->p_im[order-1][pos] = val;

            } else {

                // pos is not contained within num, thus has to be inserted.
                soti_insert_item( pos, val, idx, order, num, dhl);

            }

        } // what happens if the order is greater than the number?
        // Change order and add one element to the specified order.

    }

}
// ----------------------------------------------------------------------------------------------------









// ****************************************************************************************************
void soti_set_r( coeff_t a, sotinum_t* num, dhelpl_t dhl){
    
    ord_t i;
    num->re = a;

    for ( i = 0; i<num->order; i++){
        // Set number of non-zero and allocated size to 0.
        num->p_nnz[i] = 0;
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_set_o( sotinum_t* src, sotinum_t* dest, dhelpl_t dhl){
    
    // This function sets an oti number from another OTI number.
    uint8_t reallocate = soti_requiresrealloc(src, dest);
    ord_t i;

    // TODO: Add check to wheather dest has not been initialized.
    // TODO: Add case when the two elements have different orders.
    // TODO: Add check if dest is a tmp function.

    if( reallocate ){
        // Reallocation IS required.
        // Easiest way: Free current memory in dest and allocate new memory.
        
        if (dest->flag != 0){

            soti_free(dest);  
            *dest = soti_createEmpty_like( src, dhl);        

        } else {

            // TODO: What happens if this is a tmp value?
            printf("ERROR: Cant change memory of \n");
            exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.

        }

    }

    // Copy real coefficient
    dest->re = src->re;

    // Copy imaginary coefficients
    for ( i = 0; i < src->order; i++){
        // Copy memory to dest number. Only copy non zeros.
        memcpy(dest->p_im[i], src->p_im[i], src->p_nnz[i]*sizeof(coeff_t) );
        memcpy(dest->p_idx[i],src->p_idx[i],src->p_nnz[i]*sizeof(imdir_t) );

        dest->p_nnz[i] = src->p_nnz[i]; 
    }

    // Set all other elements in the imaginary directions to zero.
    for (; i<dest->order;i++){
        dest->p_nnz[i] = 0;
    }

}
// ----------------------------------------------------------------------------------------------------





























// Getters.

// ****************************************************************************************************
coeff_t soti_get_deriv( imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){

    coeff_t coef   = soti_get_item(idx,order,num,dhl);
    coeff_t factor = dhelp_get_deriv_factor(idx, order, dhl);

    // error_exit(OTI_OutOfMemory);

    return coef*factor;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
coeff_t soti_get_item(imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl){
    
    coeff_t res = 0.0; // Default answer.
    flag_t flag;
    imdir_t pos;
    
    if (order == 0){
        
        res = num->re;

    } else {

        if ( order<=num->order ){            
            if(num->p_nnz[order-1] != 0){
                pos = binSearchUI64(idx, num->p_idx[order-1], num->p_nnz[order-1], &flag );
                if (flag != 0){
                    res = num->p_im[order-1][pos];
                }
            }
        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
uint64_t soti_get_min_memsize(sotinum_t* num, dhelpl_t dhl){

    uint64_t allocation_size = 0;
    ord_t i;
    
    // Get the allocation size of the OTI number:
    allocation_size = num->order*(sizeof(coeff_t*)+sizeof(imdir_t*)+sizeof(ndir_t)+sizeof(ndir_t));

    // Add the standard allocation sizes:
    for ( i =0; i < num->order ; i++){
        
        allocation_size += num->p_nnz[i]*(sizeof(coeff_t)+sizeof(imdir_t));

    }

    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
uint64_t soti_get_total_memsize(sotinum_t* num, dhelpl_t dhl){

    uint64_t allocation_size = 0;
    ord_t i;

    // Get the allocation size of the OTI number:
    allocation_size = num->order*(sizeof(coeff_t*)+sizeof(imdir_t*)+sizeof(ndir_t)+sizeof(ndir_t));

    // Add the standard allocation sizes:
    for ( i = 0; i<num->order; i++){
        
        allocation_size += num->p_size[i]*(sizeof(coeff_t)+sizeof(imdir_t));

    }

    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
uint8_t soti_requiresrealloc(sotinum_t* src, sotinum_t* dest){
    
    uint8_t reallocate = 0; // False
    ord_t i;

    // Check if reallocation is necessary
    if (src->order != dest->order ){

        reallocate = 0xFF; // True

    } else {
       
        for ( i = 0; i < src->order; i++){

            // Check if the number of non zeros is greater to the size allocated
            // in destination.
            if ( src->p_nnz[i] > dest->p_size[i] ){

                reallocate = 0xFF; // True
                break;

            }
        }

    }

    return reallocate;
}
// ----------------------------------------------------------------------------------------------------


// Copy operations.

// ****************************************************************************************************
void soti_copy_to(sotinum_t* src, sotinum_t* dest, dhelpl_t dhl){
        
    uint8_t reallocate = soti_requiresrealloc(src, dest);
    ord_t i;

    // TODO: Add check to wheather dest has not been initialized.
    // TODO: Add case when the two elements have different orders.
    // TODO: Add check if dest is a tmp function.

    if( reallocate ){
        // Reallocation IS required.
        // Easiest way: Free current memory in dest and allocate new memory.
        

        if (dest->flag != 0){

            soti_free(dest);            
            (*dest) = soti_createEmpty_like( src, dhl);

        } else {
            // TODO: What happens if this is a tmp value?
            printf("ERROR: Cant change memory of the given number (function soti_copy_to(...) ) \n");
            exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
        }

    }

    // Is it required to copy the order?
    // dest->order = src->order;

    // Copy real coefficient
    dest->re = src->re;

    // Copy imaginary coefficients
    for ( i = 0; i < src->order; i++){
        
        // Copy memory to dest number. Only copy non zeros.
        memcpy(dest->p_im[i], src->p_im[i], src->p_nnz[i]*sizeof(coeff_t) );
        memcpy(dest->p_idx[i],src->p_idx[i],src->p_nnz[i]*sizeof(imdir_t) );

        dest->p_nnz[i] = src->p_nnz[i]; 

    }  

    // Set all other elements in the imaginary directions to zero.
    for (; i<dest->order;i++){
        dest->p_nnz[i] = 0;
    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
sotinum_t soti_copy(sotinum_t* num, dhelpl_t dhl){

    ord_t i;
    sotinum_t res = soti_createEmpty_like( num, dhl);

    res.re    = num->re;

    for ( i = 0; i < res.order; i++){
        
        // Set number of non-zero and allocated size to 0.
        res.p_nnz[i]  = num->p_nnz[i]; // Just use nnz.
        
        if ( res.p_nnz[i] != 0 ){

            // copy data.
            memcpy(res.p_im[i], num->p_im[i], res.p_nnz[i]*sizeof(coeff_t));
            memcpy(res.p_idx[i],num->p_idx[i],res.p_nnz[i]*sizeof(imdir_t));

        }
    
    }

    return res;

}
// ----------------------------------------------------------------------------------------------------



// Helpers

// ****************************************************************************************************
void soti_print(sotinum_t* num, dhelpl_t dhl){

    ndir_t nnz_total = 1, dir;
    ord_t ordi,ord;
    
    for( ordi = 0; ordi<num->order; ordi++){
        nnz_total += num->p_nnz[ordi];
    }

    printf("  Order: "_PORDT", non_zero: "_PNDIRT", re: %11.4e\n",
        num->order, nnz_total, num->re);
    printf("  ORD ,    IMDIR  ,   VALUE   \n");

    printf("    0 ,         0 , "_PCOEFFT"\n",num->re);

    for( ord = 1; ord<=num->order; ord++){

        ndir_t ndir_i = num->p_nnz[ord];

        for ( dir=0; dir< ndir_i; dir++){
            
            printf(" " _PORDT " , " _PNDIRT " ," _PCOEFFT "\n",
                ord, num->p_idx[ord-1][dir], num->p_im[ord-1][dir]);

        }

    }

}
// ----------------------------------------------------------------------------------------------------






















// Memory management.

// ****************************************************************************************************
inline sotinum_t soti_init(void){

    sotinum_t res;

    res.p_im  = NULL;
    res.p_idx = NULL;
    res.p_nnz = NULL;
    res.p_size= NULL;
    
    res.order  = 0;
    res.torder = 0;
    res.flag   = 1; 

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_free(sotinum_t* num){
                
    if (num->p_im != NULL && num->flag != 0){
        free(num->p_im);
    }

    *num = soti_init();
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_createReal(coeff_t num, ord_t order, dhelpl_t dhl){
    
    sotinum_t res = soti_createEmpty(order,dhl);

    res.re = num;

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_createEmpty( ord_t order, dhelpl_t dhl){
    
    sotinum_t res;
    
    ndir_t p_nnz[_MAXORDER_OTI]; 

    ord_t i;
    
    // Define allocation sizes.
    for ( i = 0; i < order; i++){
        p_nnz[i] = dhl.p_dh[i].allocSize; // Get standard allocation sizes.
    }
    
    res = soti_createEmpty_predef(p_nnz, order, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
sotinum_t soti_createEmpty_like( sotinum_t* other, dhelpl_t dhl){
    
    // This function assumes that 'other' is correctly allocated.
    // Defines a new memory space from the p_nnz (not p_size) of the input sparse number.
    sotinum_t res = soti_createEmpty_predef(other->p_nnz, other->order, dhl);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline sotinum_t soti_createEmpty_predef(ndir_t* p_nnz, ord_t order, dhelpl_t dhl){
    
    sotinum_t res = soti_init(); // Initialize pointer values.

    void * memory = NULL;
    uint64_t allocation_size = 0;
    ord_t i;

    res.order = order;
    
    if (res.order != 0){

        // Get the allocation size of the OTI number:
        allocation_size = res.order*(sizeof(coeff_t*)+sizeof(imdir_t*)+sizeof(ndir_t)+sizeof(ndir_t));

        // Add the standard allocation sizes:
        for ( i = 0; i<res.order; i++){
            
            allocation_size += p_nnz[i]*(sizeof(coeff_t)+sizeof(imdir_t));

        }

        // Allocate memory and check if correctly allocated.
        memory = malloc(allocation_size);
        if ( memory == NULL ){
            printf("ERROR: Not enough memory to handle oti number.\n Exiting...\n");
            exit(OTI_OutOfMemory); // TODO: Raise error instead of quitting the program.
        }

        // Distribute memory among the different pointers.
        res.p_im  = (coeff_t**)memory;
        memory    += res.order * sizeof(coeff_t*);

        res.p_idx = (imdir_t**)memory;
        memory    += res.order * sizeof(imdir_t*);

        res.p_nnz = (ndir_t*  )memory;
        memory    += res.order * sizeof(ndir_t);

        res.p_size= (ndir_t*  )memory;
        memory    += res.order * sizeof(ndir_t);
        
        for ( i = 0; i < res.order; i++){
            
            // Distribute memory.
            res.p_im[i] = (coeff_t*)memory;
            memory += p_nnz[i]*sizeof(coeff_t); 

            res.p_idx[i]= (imdir_t*)memory;
            memory += p_nnz[i]*sizeof(imdir_t); 

            // Set number of non-zero and allocated size to 0.
            res.p_size[i] = p_nnz[i]; 
            res.p_nnz[i]  = 0; 

        }

        // Raise flag for OTI number.
        res.flag = 1;

    } 
    // Raise flag for OTI number.
    res.flag = 1;

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
size_t soti_memory_size( const ndir_t* p_nnz, ord_t order){

    size_t allocation_size = 0;
    ord_t i = 0;

    if (order != 0){
        
        // Get the allocation size of the OTI number:
        allocation_size = order * (sizeof(coeff_t*)+sizeof(imdir_t*)+sizeof(ndir_t)+sizeof(ndir_t));

        // Add the standard allocation sizes:
        for ( i = 0; i < order; i++){
            
            allocation_size += p_nnz[i]*(sizeof(coeff_t)+sizeof(imdir_t));

        }
    }

    return allocation_size;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void* soti_distribute_memory(void* mem, const ndir_t* p_nnz, ord_t order, flag_t flag, sotinum_t* res){

    ord_t i;
    void* memory = mem;

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

    // If necessary, returns end of memory.
    return memory;

}
// ----------------------------------------------------------------------------------------------------


    













