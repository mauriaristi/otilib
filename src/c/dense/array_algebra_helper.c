    



// ****************************************************************************************************
inline void dhelp_oarr_mul_RR(oarr_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl){
    
    darr_t tmp_lhs, tmp_rhs, tmp_res;

    // Copy info.
    tmp_lhs.nrows  = lhs->nrows;
    tmp_lhs.ncols  = lhs->ncols;
    tmp_lhs.size   = lhs->size ;
    tmp_lhs.p_data = lhs->re   ;

    tmp_rhs.nrows  = rhs->nrows;
    tmp_rhs.ncols  = rhs->ncols;
    tmp_rhs.size   = rhs->size ;
    tmp_rhs.p_data = rhs->re   ;

    tmp_res.nrows  = res->nrows;
    tmp_res.ncols  = res->ncols;
    tmp_res.size   = res->size ;
    tmp_res.p_data = res->re   ;

    // Perform the multiplication.
    darr_mul_RR_to( &tmp_lhs, &tmp_rhs, &tmp_res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void dhelp_oarr_mul_RI(oarr_t* lhs, oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl ){
    
    ndir_t i;
    darr_t tmp_lhs, tmp_rhs, tmp_res;

    // Copy info.
    // TODO: Eliminate all this copy. in the for cycle.
    tmp_lhs.nrows  = lhs->nrows;
    tmp_lhs.ncols  = lhs->ncols;
    tmp_lhs.size   = lhs->size ;
    tmp_lhs.p_data = lhs->re   ;

    tmp_rhs.nrows  = rhs->nrows;
    tmp_rhs.ncols  = rhs->ncols;
    tmp_rhs.size   = rhs->size ;

    tmp_res.nrows  = res->nrows;
    tmp_res.ncols  = res->ncols;
    tmp_res.size   = res->size ;

    for ( i = 0; i < rhs->p_ndpo[ord_rhs-1]; i++){
        

        tmp_rhs.p_data = rhs->p_im[ord_rhs-1][i];
        tmp_res.p_data = res->p_im[ord_rhs-1][i];

        // Perform 
        // res(ord_rhs)[i] += lhs(re) * rhs(ord_rhs)[i]

        darr_mul_and_selfsum_RR_to( &tmp_lhs, &tmp_rhs, &tmp_res);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void dhelp_oarr_mul_II(oarr_t* lhs, ord_t ord_lhs, // Input 1
                       oarr_t* rhs, ord_t ord_rhs, // Input 2
                       oarr_t* res, dhelpl_t dhl){ // Helper
    
    darr_t tmp_lhs, tmp_rhs, tmp_res;
    imdir_t i, j, k;
    ord_t ord_res = ord_lhs + ord_rhs;


    // Copy info.
    // TODO: Eliminate all this copy. in the for cycle.

    tmp_lhs.nrows  = lhs->nrows;
    tmp_lhs.ncols  = lhs->ncols;
    tmp_lhs.size   = lhs->size ;

    tmp_rhs.nrows  = rhs->nrows;
    tmp_rhs.ncols  = rhs->ncols;
    tmp_rhs.size   = rhs->size ;

    tmp_res.nrows  = res->nrows;
    tmp_res.ncols  = res->ncols;
    tmp_res.size   = res->size ;

    imdir2d_t tmp_multtabl ;
    
    // The multiplication tables are made in a specific order.
    // Therefore, it is important to select the correct one.
    if (ord_lhs < ord_rhs){
        
        tmp_multtabl = dhl.p_dh[ord_res-1].p_multtabls[ord_lhs-1];

        // Perform the multiplication.
        for ( i = 0; i < lhs->p_ndpo[ord_lhs-1]; i++){

            tmp_lhs.p_data = lhs->p_im[ord_lhs-1][i];

            for ( j = 0; j < rhs->p_ndpo[ord_rhs-1]; j++){
                
                tmp_rhs.p_data = rhs->p_im[ord_rhs-1][j];

                // Get the resulting imaginary direction.
                k = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],i,j);

                tmp_res.p_data = res->p_im[ord_res-1][k];                

                // Multiply the imaginary directions, performing
                // res(ord_res)[k] += lhs(ord_lhs)[i] * rhs(ord_rhs)[j]
                darr_mul_and_selfsum_RR_to( &tmp_lhs, &tmp_rhs, &tmp_res);

            }

        }

    } else {

        // Get the multiplication table of the 
        tmp_multtabl = dhl.p_dh[ord_res-1].p_multtabls[ord_rhs-1];

        // Perform the multiplication.
        for ( i = 0; i < lhs->p_ndpo[ord_lhs-1]; i++){

            tmp_lhs.p_data = lhs->p_im[ord_lhs-1][i];

            for ( j = 0; j < rhs->p_ndpo[ord_rhs-1]; j++){
                
                tmp_rhs.p_data = rhs->p_im[ord_rhs-1][j];

                // Get the resulting imaginary direction.
                k = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],j,i);

                tmp_res.p_data = res->p_im[ord_res-1][k];                

                // Multiply the imaginary directions, performing
                // res(ord_res)[k] += lhs(ord_lhs)[i] * rhs(ord_rhs)[j]
                darr_mul_and_selfsum_RR_to( &tmp_lhs, &tmp_rhs, &tmp_res);

            }

        }

    }

}
// ----------------------------------------------------------------------------------------------------






















































// ****************************************************************************************************
inline void dhelp_oarr_mul_rR(otinum_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl){
    
    darr_t tmp_rhs, tmp_res;

    // Copy info.
    tmp_rhs.nrows  = rhs->nrows;
    tmp_rhs.ncols  = rhs->ncols;
    tmp_rhs.size   = rhs->size ;
    tmp_rhs.p_data = rhs->re   ;

    tmp_res.nrows  = res->nrows;
    tmp_res.ncols  = res->ncols;
    tmp_res.size   = res->size ;
    tmp_res.p_data = res->re   ;

    // Perform the multiplication.
    darr_mul_rR_to( lhs->re, &tmp_rhs, &tmp_res);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void dhelp_oarr_mul_rI(otinum_t* lhs, oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl ){
    
    ndir_t i;
    darr_t tmp_rhs, tmp_res;

    // Copy info.
    // TODO: Eliminate all this copy. in the for cycle.
    tmp_rhs.nrows  = rhs->nrows;
    tmp_rhs.ncols  = rhs->ncols;
    tmp_rhs.size   = rhs->size ;

    tmp_res.nrows  = res->nrows;
    tmp_res.ncols  = res->ncols;
    tmp_res.size   = res->size ;

    for ( i = 0; i < rhs->p_ndpo[ord_rhs-1]; i++){
        

        tmp_rhs.p_data = rhs->p_im[ord_rhs-1][i];
        tmp_res.p_data = res->p_im[ord_rhs-1][i];

        // Perform 
        // res(ord_rhs)[i] += lhs(re) * rhs(ord_rhs)[i]

        darr_mul_and_selfsum_rR_to( lhs->re, &tmp_rhs, &tmp_res);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void dhelp_oarr_mul_Ri(oarr_t* lhs, otinum_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl ){
    
    ndir_t i;
    darr_t tmp_lhs, tmp_res;

    // Copy info.
    // TODO: Eliminate all this copy. in the for cycle.
    tmp_lhs.nrows  = lhs->nrows;
    tmp_lhs.ncols  = lhs->ncols;
    tmp_lhs.size   = lhs->size ;
    tmp_lhs.p_data = lhs->re   ;

    tmp_res.nrows  = res->nrows;
    tmp_res.ncols  = res->ncols;
    tmp_res.size   = res->size ;

    for ( i = 0; i < rhs->p_ndpo[ord_rhs-1]; i++){
        
        tmp_res.p_data = res->p_im[ord_rhs-1][i];

        // Perform 
        // res(ord_rhs)[i] += lhs(re) * rhs(ord_rhs)[i]

        darr_mul_and_selfsum_rR_to( rhs->p_im[ord_rhs-1][i], &tmp_lhs, &tmp_res);

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void dhelp_oarr_mul_iI(otinum_t* lhs, ord_t ord_lhs, // Input 1
                       oarr_t* rhs, ord_t ord_rhs, // Input 2
                       oarr_t* res, dhelpl_t dhl){ // Helper
    
    darr_t tmp_rhs, tmp_res;
    imdir_t i, j, k;
    ord_t ord_res = ord_lhs + ord_rhs;


    // Copy info.
    // TODO: Eliminate all this copy. in the for cycle.
    tmp_rhs.nrows  = rhs->nrows;
    tmp_rhs.ncols  = rhs->ncols;
    tmp_rhs.size   = rhs->size ;

    tmp_res.nrows  = res->nrows;
    tmp_res.ncols  = res->ncols;
    tmp_res.size   = res->size ;

    imdir2d_t tmp_multtabl ;
    
    // The multiplication tables are made in a specific order.
    // Therefore, it is important to select the correct one.
    if (ord_lhs < ord_rhs){
        
        tmp_multtabl = dhl.p_dh[ord_res-1].p_multtabls[ord_lhs-1];

        // Perform the multiplication.
        for ( i = 0; i < lhs->p_ndpo[ord_lhs-1]; i++){

            for ( j = 0; j < rhs->p_ndpo[ord_rhs-1]; j++){
                
                tmp_rhs.p_data = rhs->p_im[ord_rhs-1][j];

                // Get the resulting imaginary direction.
                k = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],i,j);

                tmp_res.p_data = res->p_im[ord_res-1][k];                

                // Multiply the imaginary directions, performing
                // res(ord_res)[k] += lhs(ord_lhs)[i] * rhs(ord_rhs)[j]
                darr_mul_and_selfsum_rR_to( lhs->p_im[ord_lhs-1][i], &tmp_rhs, &tmp_res);

            }

        }

    } else {

        // Get the multiplication table of the 
        tmp_multtabl = dhl.p_dh[ord_res-1].p_multtabls[ord_rhs-1];

        // Perform the multiplication.
        for ( i = 0; i < lhs->p_ndpo[ord_lhs-1]; i++){

            for ( j = 0; j < rhs->p_ndpo[ord_rhs-1]; j++){
                
                tmp_rhs.p_data = rhs->p_im[ord_rhs-1][j];

                // Get the resulting imaginary direction.
                k = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],j,i);

                tmp_res.p_data = res->p_im[ord_res-1][k];                

                // Multiply the imaginary directions, performing
                // res(ord_res)[k] += lhs(ord_lhs)[i] * rhs(ord_rhs)[j]
                darr_mul_and_selfsum_rR_to( lhs->p_im[ord_lhs-1][i], &tmp_rhs, &tmp_res);

            }

        }

    }

}
// ----------------------------------------------------------------------------------------------------

























// ****************************************************************************************************
void oarr_trc_self_mul_r( darr_t* a, ord_t ord, oarr_t* res, dhelpl_t dhl){

    ord_t ordi;
    ndir_t i;  
    darr_t tmp_arr;

    tmp_arr.nrows  = res->nrows;
    tmp_arr.ncols  = res->ncols;
    tmp_arr.size   = res->size ;

    for ( ordi = ord-1; ordi < res->order; ordi++){

        for ( i=0; i<res->p_ndpo[ordi]; i++){
            
            tmp_arr.p_data = res->p_im[ordi][i];
            darr_self_mul_R(a, &tmp_arr);
            
        }

    }

}
// ----------------------------------------------------------------------------------------------------

// // ****************************************************************************************************
void oarr_trc_self_sum(oarr_t* arr, ord_t ord, oarr_t* res, dhelpl_t dhl ){
    
    // Initialize
    ord_t ordi;
    ndir_t i; 
    darr_t tmp_res,tmp_arr;

    tmp_arr.nrows  = arr->nrows;
    tmp_arr.ncols  = arr->ncols;
    tmp_arr.size   = arr->size ;

    tmp_res.nrows  = res->nrows;
    tmp_res.ncols  = res->ncols;
    tmp_res.size   = res->size ;

    for (  ordi = ord-1; ordi < res->order; ordi++){

        for ( i=0; i < res->p_ndpo[ordi]; i++){
                
            tmp_arr.p_data = arr->p_im[ordi][i];
            tmp_res.p_data = res->p_im[ordi][i];

            darr_self_sum_R( &tmp_arr, &tmp_res );

        }

    }
    
}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void oarr_trc_mul( oarr_t* arr1, ord_t ord1, oarr_t* arr2, ord_t ord2, oarr_t* res, dhelpl_t dhl ){
    
    ord_t ord_mul1, ord_mul2;
    
    for ( ord_mul1 =ord1; ord_mul1 <= res->order; ord_mul1++){

        for ( ord_mul2 = res->order-ord_mul1; ord_mul2 >= ord2; ord_mul2--){

            dhelp_oarr_mul_II(arr1, ord1, arr2, ord2, res, dhl);

        }   

    }
    

}
// ----------------------------------------------------------------------------------------------------

































