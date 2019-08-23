

// 2. Array operations.


// 2.1. Inner product.
// 2.1.1. OTI Array   - OTI Array.
// ****************************************************************************************************
oarr_t oarr_matmul_OO(oarr_t* lhs, oarr_t* rhs, dhelpl_t dhl){

    oarr_t res = oarr_zeros(lhs->nrows, rhs->ncols,  lhs->nbases, lhs->order, dhl);    

    ord_t ord_res, ord_mul1;
    
    // First multiply both real parts.

    // lhs real part times rhs real part.
    dhelp_oarr_matmul_RR(lhs, rhs, &res, dhl);

    // Loop to get each resulting order.
    for (  ord_res = 1; ord_res <= res.order; ord_res++){

        // Multiply  lhs(re) x rhs(ord_res)
        dhelp_oarr_matmul_RI( lhs, rhs, ord_res, &res, dhl);

        // Multiply  lhs(ord_res) x rhs(re)
        dhelp_oarr_matmul_IR( lhs, rhs, ord_res, &res, dhl);

        // Loop for every combination of orders such that the resulting order is ord_res.
        for ( ord_mul1 = 1; ord_mul1 <= ord_res/2; ord_mul1++){

            ord_t ord_mul2 = ord_res - ord_mul1;

            dhelp_oarr_matmul_II(lhs, ord_mul1, rhs, ord_mul2, &res, dhl);

            // In the case that the orders are the same, the operation is not the same.
            // It might be different in the case of matmul.
            if (ord_mul1 != ord_mul2){

                dhelp_oarr_matmul_II(lhs, ord_mul2, rhs, ord_mul1, &res, dhl);

            }  

        }
        

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_matmul_OO_to(oarr_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl){

    oarr_set_all_r(0.0, res, dhl);

    ord_t ord_res, ord_mul1;
    
    // First multiply both real parts.

    // lhs real part times rhs real part.
    dhelp_oarr_matmul_RR(lhs, rhs, res, dhl);

    // Loop to get each resulting order.
    for (  ord_res = 1; ord_res <= res->order; ord_res++){

        // Multiply  lhs(re) x rhs(ord_res)
        dhelp_oarr_matmul_RI( lhs, rhs, ord_res, res, dhl);

        // Multiply  lhs(ord_res) x rhs(re)
        dhelp_oarr_matmul_IR( lhs, rhs, ord_res, res, dhl);

        // Loop for every combination of orders such that the resulting order is ord_res.
        for ( ord_mul1 = 1; ord_mul1 <= ord_res/2; ord_mul1++){

            ord_t ord_mul2 = ord_res - ord_mul1;

            dhelp_oarr_matmul_II(lhs, ord_mul1, rhs, ord_mul2, res, dhl);

            // In the case that the orders are the same, the operation is not the same.
            // It might be different in the case of matmul.
            if (ord_mul1 != ord_mul2){

                dhelp_oarr_matmul_II(lhs, ord_mul2, rhs, ord_mul1, res, dhl);

            }  

        }
     
    }

}
// ----------------------------------------------------------------------------------------------------


// 2.1.2. OTI Array   - Real Array.
// ****************************************************************************************************
oarr_t oarr_matmul_OR(oarr_t* lhs, darr_t* rhs, dhelpl_t dhl){
        
    oarr_t res = oarr_zeros(lhs->nrows, rhs->ncols,  lhs->nbases, lhs->order, dhl);    
    oarr_t tmp_rhs;
    ord_t ord_res;

    // This tmp is set to "fake" an oarr to pass it to the following functions.
    tmp_rhs.nbases = lhs->nbases ;
    tmp_rhs.order  = lhs->order  ;
    tmp_rhs.ndir   = lhs->ndir   ;
    tmp_rhs.nrows  = rhs->nrows  ;
    tmp_rhs.ncols  = rhs->ncols  ;
    tmp_rhs.size   = rhs->size   ;
    tmp_rhs.re     = rhs->p_data ; 

    
    // First multiply both real parts.

    // lhs real part times rhs real part.
    dhelp_oarr_matmul_RR(lhs, &tmp_rhs, &res, dhl);

    // Loop to get each resulting order.
    for (  ord_res = 1; ord_res <= res.order; ord_res++){

        // Multiply  lhs(ord_res) x rhs(re)
        dhelp_oarr_matmul_IR( lhs, &tmp_rhs, ord_res, &res, dhl);

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oarr_matmul_OR_to(oarr_t* lhs, darr_t* rhs, oarr_t* res, dhelpl_t dhl){
        
    oarr_set_all_r(0.0,res,dhl);

    oarr_t tmp_rhs;
    ord_t ord_res;

    // This tmp is set to "fake" an oarr to pass it to the following functions.
    tmp_rhs.nbases = lhs->nbases ;
    tmp_rhs.order  = lhs->order  ;
    tmp_rhs.ndir   = lhs->ndir   ;
    tmp_rhs.nrows  = rhs->nrows  ;
    tmp_rhs.ncols  = rhs->ncols  ;
    tmp_rhs.size   = rhs->size   ;
    tmp_rhs.re     = rhs->p_data ; 

    
    // First multiply both real parts.

    // lhs real part times rhs real part.
    dhelp_oarr_matmul_RR(lhs, &tmp_rhs, res, dhl);

    // Loop to get each resulting order.
    for (  ord_res = 1; ord_res <= res->order; ord_res++){

        // Multiply  lhs(ord_res) x rhs(re)
        dhelp_oarr_matmul_IR( lhs, &tmp_rhs, ord_res, res, dhl);

    }    

}
// ----------------------------------------------------------------------------------------------------




// 2.1.3. Real Array  - OTI Array.
// ****************************************************************************************************
oarr_t oarr_matmul_RO(darr_t* lhs, oarr_t* rhs, dhelpl_t dhl){
        
    oarr_t res = oarr_zeros(lhs->nrows, rhs->ncols,  rhs->nbases, rhs->order, dhl);    
    oarr_t tmp_lhs;
    ord_t ord_res;

    // This tmp is set to "fake" an oarr to pass it to the following functions.
    tmp_lhs.nbases = rhs->nbases ;
    tmp_lhs.order  = rhs->order  ;
    tmp_lhs.ndir   = rhs->ndir  ;
    tmp_lhs.nrows  = lhs->nrows  ;
    tmp_lhs.ncols  = lhs->ncols  ;
    tmp_lhs.size   = lhs->size   ;
    tmp_lhs.re     = lhs->p_data ; 

    
    // First multiply both real parts.

    // lhs real part times rhs real part.
    dhelp_oarr_matmul_RR(&tmp_lhs, rhs, &res, dhl);

    // Loop to get each resulting order.
    for (  ord_res = 1; ord_res <= res.order; ord_res++){

        // Multiply  lhs(re) x rhs(ord_res)
        dhelp_oarr_matmul_RI( &tmp_lhs, rhs, ord_res, &res, dhl);

    }

    return res;
    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void oarr_matmul_RO_to(darr_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl){
        
    oarr_set_all_r( 0.0, res, dhl);

    oarr_t tmp_lhs;
    ord_t ord_res;

    // This tmp is set to "fake" an oarr to pass it to the following functions.
    tmp_lhs.nbases = rhs->nbases ;
    tmp_lhs.order  = rhs->order  ;
    tmp_lhs.ndir   = rhs->ndir   ;
    tmp_lhs.nrows  = lhs->nrows  ;
    tmp_lhs.ncols  = lhs->ncols  ;
    tmp_lhs.size   = lhs->size   ;
    tmp_lhs.re     = lhs->p_data ; 

    
    // First multiply both real parts.
    // lhs real part times rhs real part.
    dhelp_oarr_matmul_RR(&tmp_lhs, rhs, res, dhl);

    // Loop to get each resulting order.
    for (  ord_res = 1; ord_res <= res->order; ord_res++){

        // Multiply  lhs(re) x rhs(ord_res)
        dhelp_oarr_matmul_RI( &tmp_lhs, rhs, ord_res, res, dhl);

    }
    
}
// ----------------------------------------------------------------------------------------------------














// 2.2. Transpose.
// ****************************************************************************************************
oarr_t oarr_transpose(oarr_t* arr, dhelpl_t dhl){
    
    uint64_t i;
    oarr_t res;    
    
    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    // Array specific attributes:
    res.nrows  = arr->ncols;
    res.ncols  = arr->nrows;
    res.size   = arr->size ;

    // Get the number of imaginary directions for nbases and order.
    res.ndir = arr->ndir; // Excludes the real direction.
    // Set the values of the number first.
    res.order  = arr->order;
    res.nbases = arr->nbases;

    tmp_arr1.ncols = arr->ncols;
    tmp_arr1.nrows = arr->nrows;
    tmp_arr1.size  = arr->size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr->re;
    tmp_arr2 =  darr_transpose(&tmp_arr1);
    res.re = tmp_arr2.p_data; //  Comes newly allocated.
    
    if (res.order != 0){
            
        // Allocate memory.
        res.p_im   = ( arr_t** ) malloc( res.order*sizeof(arr_t*) );
        res.p_ndpo = ( ndir_t* ) malloc( res.order*sizeof(ndir_t) );

        if (res.p_im == NULL  || res.p_ndpo == NULL ){
            printf("--- ERROR: Out of memory\n");
            exit(OTI_OutOfMemory);
        }

        for (ordi = 0; ordi<res.order; ordi++){

            res.p_ndpo[ordi] = arr->p_ndpo[ordi];
            
            res.p_im[ordi]   = ( arr_t* ) malloc( res.p_ndpo[ordi]*sizeof(arr_t) );


            if ( res.p_im[ordi] == NULL ){
                printf("--- ERROR: Out of memory\n");
                exit(OTI_OutOfMemory);
            }

            // Initialize memory within each array.
            for( i = 0; i < res.p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr->p_im[ordi][i];
                tmp_arr2 = darr_transpose( &tmp_arr1);

                res.p_im[ordi][i] = tmp_arr2.p_data;

            }

        }

    } else {

        // Set pointer to null
        res.p_im = NULL;   
        res.p_ndpo = NULL;     
    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void oarr_transpose_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl){
    
    uint64_t i;    
    
    darr_t tmp_arr1 , tmp_arr2; // Temporal real array.
    ord_t ordi; 


    // Initialize global attributes.

    tmp_arr1.ncols = arr->ncols;
    tmp_arr1.nrows = arr->nrows;
    tmp_arr1.size  = arr->size ;

    tmp_arr2.ncols = res->ncols;
    tmp_arr2.nrows = res->nrows;
    tmp_arr2.size  = res->size ;

    // Initialize real direction.
    tmp_arr1.p_data = arr->re;
    tmp_arr2.p_data = res->re;
    darr_transpose_to(&tmp_arr1,&tmp_arr2);
    
    if (res->order != 0){
            
        for (ordi = 0; ordi<res->order; ordi++){

            // Initialize memory within each array.
            for( i = 0; i < res->p_ndpo[ordi]; i++){

                tmp_arr1.p_data = arr->p_im[ordi][i];
                tmp_arr2.p_data = res->p_im[ordi][i];

                darr_transpose_to( &tmp_arr1,&tmp_arr2);

            }

        }

    } 

}
// ----------------------------------------------------------------------------------------------------





















// 2.3. Inversion.
// ****************************************************************************************************
 oarr_t oarr_invert(oarr_t* arr, dhelpl_t dhl){
    
    otinum_t detInv;
    otinum_t tmp1, tmp2;
    oarr_t res,A;



    if (arr->ncols != arr->nrows){
        printf("--- DimensionError in matrix inverse. Only square matrices are invertible. ---\n");
        exit(1);
    }
    
    res = oarr_zeros(arr->nrows,arr->ncols, arr->nbases, arr->order, dhl);

    if ( arr->ncols == 1 ){

        // Get temporal
        tmp1 = oti_get_tmp( 0, arr->order, arr->nbases,  dhl);
        tmp2 = oti_get_tmp( 1, arr->order, arr->nbases,  dhl);
        
        // Get item
        oarr_get_item_i_to(arr,0,&tmp1,dhl);

        // Perform x^{-1}

        oti_pow_to( &tmp1, -1.0, &tmp2, dhl);
        
        oarr_set_item_i_o( &tmp2, 0, &res, dhl);


    } else if (arr->ncols == 2){

        // Get temporal
        tmp1   = oti_get_tmp( 5, arr->order, arr->nbases,  dhl);
        tmp2   = oti_get_tmp( 6, arr->order, arr->nbases,  dhl);
        detInv = oti_get_tmp( 8, arr->order, arr->nbases,  dhl);


        // Get the determinant and its inverse.
        // Get determinant
        oarr_det_to(  arr, &tmp1, dhl); 
        oti_pow_to( &tmp1,  -1.0, &detInv, dhl);

        // Set position 0,0
        oarr_get_item_ij_to(arr,1,1,&tmp1,dhl);
        // Multiply it by the iverse of the determinant
        oti_mul_oo_to( &detInv, &tmp1, &tmp2, dhl);
        // Set item 0,0 to matrix:
        oarr_set_item_ij_o( &tmp2, 0,0, &res, dhl);     


        // Set position 1,1
        oarr_get_item_ij_to(arr,0,0,&tmp1,dhl);
        // Multiply it by the iverse of the determinant
        oti_mul_oo_to( &detInv, &tmp1, &tmp2, dhl);
        // Set item 0,0 to matrix:
        oarr_set_item_ij_o( &tmp2, 1,1, &res, dhl);     


        // Set position 0,1
        oarr_get_item_ij_to(arr,0,1,&tmp1,dhl);
        // Multiply it by the iverse of the determinant
        oti_mul_oo_to( &detInv, &tmp1, &tmp2, dhl);
        oti_neg_to( &tmp2, &tmp1, dhl);
        // Set item 0,0 to matrix:
        oarr_set_item_ij_o( &tmp1, 0,1, &res, dhl);     

        // Set position 1,0
        oarr_get_item_ij_to(arr,1,0,&tmp1,dhl);
        // Multiply it by the iverse of the determinant
        oti_mul_oo_to( &detInv, &tmp1, &tmp2, dhl);
        oti_neg_to( &tmp2, &tmp1, dhl);
        // Set item 0,0 to matrix:
        oarr_set_item_ij_o( &tmp1,1,0, &res, dhl);        


    } else if (arr->ncols == 3){

        // Get temporal
        tmp1   = oti_get_tmp( 5, arr->order, arr->nbases,  dhl);
        tmp2   = oti_get_tmp( 6, arr->order, arr->nbases,  dhl);
        detInv = oti_get_tmp( 7, arr->order, arr->nbases,  dhl);

        A = oarr_zeros( 2, 2, arr->nbases,arr->order,  dhl);

        // Get the determinant and its inverse.
        // Get determinant
        oarr_det_to(  arr, &tmp1, dhl); 
        oti_pow_to( &tmp1,  -1.0, &detInv, dhl);



        // Set position 0,0
        // A[0] = arr[4]
        oarr_get_item_i_to(arr,4,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[5]
        oarr_get_item_i_to(arr,5,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[7]
        oarr_get_item_i_to(arr,7,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[8]
        oarr_get_item_i_to(arr,8,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);
        
        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 0, 0, &res, dhl);  




        // Set position 0,1
        // A[0] = arr[2]
        oarr_get_item_i_to(arr,2,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[1]
        oarr_get_item_i_to(arr,1,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[8]
        oarr_get_item_i_to(arr,8,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[7]
        oarr_get_item_i_to(arr,7,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 0, 1, &res, dhl);  





        // Set position 0,2
        // A[0] = arr[1]
        oarr_get_item_i_to(arr,1,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[2]
        oarr_get_item_i_to(arr,2,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[4]
        oarr_get_item_i_to(arr,4,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[5]
        oarr_get_item_i_to(arr,5,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 0, 2, &res, dhl);  




        // Set position 1,0
        // A[0] = arr[5]
        oarr_get_item_i_to(arr,5,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[3]
        oarr_get_item_i_to(arr,3,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[8]
        oarr_get_item_i_to(arr,8,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[6]
        oarr_get_item_i_to(arr,6,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 1, 0, &res, dhl);  



        // Set position 1,1
        // A[0] = arr[0]
        oarr_get_item_i_to(arr,0,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[2]
        oarr_get_item_i_to(arr,2,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[6]
        oarr_get_item_i_to(arr,6,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[8]
        oarr_get_item_i_to(arr,8,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 1, 1, &res, dhl);  



        // Set position 1,2
        // A[0] = arr[2]
        oarr_get_item_i_to(arr,2,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[0]
        oarr_get_item_i_to(arr,0,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[5]
        oarr_get_item_i_to(arr,5,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[3]
        oarr_get_item_i_to(arr,3,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 1, 2, &res, dhl);  


        // Set position 2,0
        // A[0] = arr[3]
        oarr_get_item_i_to(arr,3,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[4]
        oarr_get_item_i_to(arr,4,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[6]
        oarr_get_item_i_to(arr,6,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[7]
        oarr_get_item_i_to(arr,7,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 2, 0, &res, dhl);  



        // Set position 2,1
        // A[0] = arr[1]
        oarr_get_item_i_to(arr,1,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[0]
        oarr_get_item_i_to(arr,0,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[7]
        oarr_get_item_i_to(arr,7,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[6]
        oarr_get_item_i_to(arr,6,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);
      
        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 2, 1, &res, dhl);  




        // Set position 2,2
        // A[0] = arr[0]
        oarr_get_item_i_to(arr,0,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[1]
        oarr_get_item_i_to(arr,1,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[3]
        oarr_get_item_i_to(arr,3,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[4]
        oarr_get_item_i_to(arr,4,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 2, 2, &res, dhl);  

        oarr_free(&A);

    }

    return res;
    

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void oarr_invert_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl){
    
    otinum_t detInv;
    otinum_t tmp1, tmp2;
    oarr_t A;
    
    oarr_set_all_r(0.0, res, dhl);

    if ( arr->ncols == 1 ){

        // Get temporal
        tmp1 = oti_get_tmp( 0, arr->order, arr->nbases,  dhl);
        tmp2 = oti_get_tmp( 1, arr->order, arr->nbases,  dhl);
        
        // Get item
        oarr_get_item_i_to(arr,0,&tmp1,dhl);

        // Perform x^{-1}

        oti_pow_to( &tmp1, -1.0, &tmp2, dhl);
        
        oarr_set_item_i_o( &tmp2, 0, res, dhl);


    } else if (arr->ncols == 2){

        // Get temporal
        tmp1   = oti_get_tmp( 5, arr->order, arr->nbases,  dhl);
        tmp2   = oti_get_tmp( 6, arr->order, arr->nbases,  dhl);
        detInv = oti_get_tmp( 8, arr->order, arr->nbases,  dhl);


        // Get the determinant and its inverse.
        // Get determinant
        oarr_det_to(  arr, &tmp1, dhl); 
        oti_pow_to( &tmp1,  -1.0, &detInv, dhl);

        // Set position 0,0
        oarr_get_item_ij_to(arr,1,1,&tmp1,dhl);
        // Multiply it by the iverse of the determinant
        oti_mul_oo_to( &detInv, &tmp1, &tmp2, dhl);
        // Set item 0,0 to matrix:
        oarr_set_item_ij_o( &tmp2, 0,0, res, dhl);     


        // Set position 1,1
        oarr_get_item_ij_to(arr,0,0,&tmp1,dhl);
        // Multiply it by the iverse of the determinant
        oti_mul_oo_to( &detInv, &tmp1, &tmp2, dhl);
        // Set item 0,0 to matrix:
        oarr_set_item_ij_o( &tmp2, 1,1, res, dhl);     


        // Set position 0,1
        oarr_get_item_ij_to(arr,0,1,&tmp1,dhl);
        // Multiply it by the iverse of the determinant
        oti_mul_oo_to( &detInv, &tmp1, &tmp2, dhl);
        oti_neg_to( &tmp2, &tmp1, dhl);
        // Set item 0,0 to matrix:
        oarr_set_item_ij_o( &tmp1, 0,1, res, dhl);     

        // Set position 1,0
        oarr_get_item_ij_to(arr,1,0,&tmp1,dhl);
        // Multiply it by the iverse of the determinant
        oti_mul_oo_to( &detInv, &tmp1, &tmp2, dhl);
        oti_neg_to( &tmp2, &tmp1, dhl);
        // Set item 0,0 to matrix:
        oarr_set_item_ij_o( &tmp1,1,0, res, dhl);        


    } else if (arr->ncols == 3){

        // Get temporal
        tmp1   = oti_get_tmp( 5, arr->order, arr->nbases,  dhl);
        tmp2   = oti_get_tmp( 6, arr->order, arr->nbases,  dhl);
        detInv = oti_get_tmp( 7, arr->order, arr->nbases,  dhl);

        A = oarr_zeros( 2, 2, arr->nbases,arr->order,  dhl);

        // Get the determinant and its inverse.
        // Get determinant
        oarr_det_to(  arr, &tmp1, dhl); 
        oti_pow_to( &tmp1,  -1.0, &detInv, dhl);



        // Set position 0,0
        // A[0] = arr[4]
        oarr_get_item_i_to(arr,4,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[5]
        oarr_get_item_i_to(arr,5,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[7]
        oarr_get_item_i_to(arr,7,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[8]
        oarr_get_item_i_to(arr,8,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);
        
        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 0, 0, res, dhl);  




        // Set position 0,1
        // A[0] = arr[2]
        oarr_get_item_i_to(arr,2,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[1]
        oarr_get_item_i_to(arr,1,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[8]
        oarr_get_item_i_to(arr,8,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[7]
        oarr_get_item_i_to(arr,7,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 0, 1, res, dhl);  





        // Set position 0,2
        // A[0] = arr[1]
        oarr_get_item_i_to(arr,1,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[2]
        oarr_get_item_i_to(arr,2,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[4]
        oarr_get_item_i_to(arr,4,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[5]
        oarr_get_item_i_to(arr,5,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 0, 2, res, dhl);  




        // Set position 1,0
        // A[0] = arr[5]
        oarr_get_item_i_to(arr,5,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[3]
        oarr_get_item_i_to(arr,3,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[8]
        oarr_get_item_i_to(arr,8,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[6]
        oarr_get_item_i_to(arr,6,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 1, 0, res, dhl);  



        // Set position 1,1
        // A[0] = arr[0]
        oarr_get_item_i_to(arr,0,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[2]
        oarr_get_item_i_to(arr,2,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[6]
        oarr_get_item_i_to(arr,6,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[8]
        oarr_get_item_i_to(arr,8,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 1, 1, res, dhl);  



        // Set position 1,2
        // A[0] = arr[2]
        oarr_get_item_i_to(arr,2,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[0]
        oarr_get_item_i_to(arr,0,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[5]
        oarr_get_item_i_to(arr,5,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[3]
        oarr_get_item_i_to(arr,3,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 1, 2, res, dhl);  


        // Set position 2,0
        // A[0] = arr[3]
        oarr_get_item_i_to(arr,3,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[4]
        oarr_get_item_i_to(arr,4,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[6]
        oarr_get_item_i_to(arr,6,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[7]
        oarr_get_item_i_to(arr,7,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 2, 0, res, dhl);  



        // Set position 2,1
        // A[0] = arr[1]
        oarr_get_item_i_to(arr,1,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[0]
        oarr_get_item_i_to(arr,0,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[7]
        oarr_get_item_i_to(arr,7,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[6]
        oarr_get_item_i_to(arr,6,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);
      
        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 2, 1, res, dhl);  




        // Set position 2,2
        // A[0] = arr[0]
        oarr_get_item_i_to(arr,0,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,0,&A,dhl);
        // A[1] = arr[1]
        oarr_get_item_i_to(arr,1,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,1,&A,dhl);
        // A[2] = arr[3]
        oarr_get_item_i_to(arr,3,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,2,&A,dhl);
        // A[3] = arr[4]
        oarr_get_item_i_to(arr,4,&tmp1,dhl);
        oarr_set_item_i_o(&tmp1,3,&A,dhl);

        oarr_det_to(&A,&tmp1,dhl);
        oti_mul_oo_to(&tmp1,&detInv,&tmp2,dhl);

        oarr_set_item_ij_o( &tmp2 , 2, 2, res, dhl);  

        oarr_free(&A);

    }

}
// ----------------------------------------------------------------------------------------------------

















// 2.4. Determinant.

// ****************************************************************************************************
otinum_t oarr_det(oarr_t* arr, dhelpl_t dhl){
    
    uint64_t i, j ;
    otinum_t res = oti_createZero( arr->nbases, arr->order, dhl);
    otinum_t tmp1, tmp2, tmp3, tmp4;

    if (arr->ncols != arr->nrows){
        printf("--- DimensionError in matrix determinant. Only square matrices are valid. ---\n");
        exit(1);
    }



    if ( arr->ncols == 1 ){

        // Initialize temporals.
        oarr_get_item_i_to(arr, 0, &res, dhl);

    } else if (arr->ncols == 2){

        // Initialize temporals
        tmp1 = oti_get_tmp( 0, arr->order, arr->nbases,  dhl);
        tmp2 = oti_get_tmp( 1, arr->order, arr->nbases,  dhl);
        tmp3 = oti_get_tmp( 2, arr->order, arr->nbases,  dhl);
        tmp4 = oti_get_tmp( 3, arr->order, arr->nbases,  dhl);

        // Operate determinant:

        // do: tmp3 = A[0,0]*A[1,1]
        oarr_get_item_ij_to(arr,0,0,&tmp1,dhl);
        oarr_get_item_ij_to(arr,1,1,&tmp2,dhl);
        oti_mul_oo_to(&tmp1,&tmp2,&tmp3,dhl);

        // Do: res = tmp3
        // oti_copy_to(&tmp3,&res,dhl);

        // Do: tmp3 = A[1,0]*A[0,1]
        oarr_get_item_ij_to(arr,0,1,&tmp1,dhl);
        oarr_get_item_ij_to(arr,1,0,&tmp2,dhl);
        oti_mul_oo_to(&tmp1,&tmp2,&tmp4,dhl); 



        oti_sub_oo_to(&tmp3,&tmp4,&res,dhl);

        // No need to free memory.

    } else {
        
        // Initialize temporals
        tmp1 = oti_get_tmp( 0, arr->order, arr->nbases,  dhl);
        tmp2 = oti_get_tmp( 1, arr->order, arr->nbases,  dhl);
        tmp3 = oti_get_tmp( 2, arr->order, arr->nbases,  dhl);
        tmp4 = oti_get_tmp( 3, arr->order, arr->nbases,  dhl);

        for (j=0; j<arr->ncols; j++){
            
            // tmp1 = arr->p_data[j];
            oarr_get_item_i_to(arr, j, &tmp1, dhl);
            
            for (i=1; i<arr->nrows; i++){        
                
                oarr_get_item_i_to(arr, ((i+j)%arr->ncols)+i*arr->ncols, &tmp2, dhl);
                oti_copy_to( &tmp1, &tmp3, dhl);
                oti_mul_oo_to(&tmp3,&tmp2,&tmp1, dhl);
                
                // tmp1 *= arr->p_data[ ( (i+j)%arr->ncols ) + i*arr->ncols];

            }

            oti_copy_to( &res, &tmp4, dhl);

            oti_sum_oo_to( &tmp4, &tmp1, &res, dhl);

            // res += tmp1;

        }

        for (j=0; j<arr->ncols; j++){
            
            // tmp1 = arr->p_data[arr->ncols-1-j];
            oarr_get_item_i_to(arr, arr->ncols-1-j, &tmp1, dhl);
            
            for (i=1; i<arr->nrows; i++){        
                
                // tmp1 *= arr->p_data[ (arr->ncols-1 - (i+j)%arr->ncols ) + i*arr->ncols];
                oarr_get_item_i_to(arr, (arr->ncols-1-(i+j)%arr->ncols)+i*arr->ncols, &tmp2, dhl);
                oti_copy_to( &tmp1, &tmp3, dhl);
                oti_mul_oo_to(&tmp3,&tmp2,&tmp1, dhl);

            }

            oti_copy_to( &res, &tmp4, dhl);

            oti_sub_oo_to( &tmp4, &tmp1, &res, dhl);

            // res -= tmp1;

        }
        
    }

    return res;
}
// ----------------------------------------------------------------------------------------------------







// ****************************************************************************************************
void oarr_det_to(oarr_t* arr, otinum_t* res, dhelpl_t dhl){
    
    uint64_t i, j ;
    
    otinum_t tmp1, tmp2, tmp3, tmp4;

    // Set all zeros to the result holder:
    oti_setFromReal( 0.0, res, dhl);

    if (arr->ncols != arr->nrows){
        printf("--- DimensionError in matrix determinant. Only square matrices are valid. ---\n");
        exit(1);
    }



    if ( arr->ncols == 1 ){

        // Initialize temporals.
        oarr_get_item_i_to(arr, 0, res, dhl);

    } else if (arr->ncols == 2){

        // Initialize temporals
        tmp1 = oti_get_tmp( 0, arr->order, arr->nbases,  dhl);
        tmp2 = oti_get_tmp( 1, arr->order, arr->nbases,  dhl);
        tmp3 = oti_get_tmp( 2, arr->order, arr->nbases,  dhl);
        tmp4 = oti_get_tmp( 3, arr->order, arr->nbases,  dhl);

        // Operate determinant:

        // do: tmp3 = A[0,0]*A[1,1]
        oarr_get_item_ij_to(arr,0,0,&tmp1,dhl);
        oarr_get_item_ij_to(arr,1,1,&tmp2,dhl);
        oti_mul_oo_to(&tmp1,&tmp2,&tmp3,dhl);

        // Do: res = tmp3
        // oti_copy_to(&tmp3,&res,dhl);

        // Do: tmp3 = A[1,0]*A[0,1]
        oarr_get_item_ij_to(arr,0,1,&tmp1,dhl);
        oarr_get_item_ij_to(arr,1,0,&tmp2,dhl);
        oti_mul_oo_to(&tmp1,&tmp2,&tmp4,dhl); 



        oti_sub_oo_to(&tmp3,&tmp4,res,dhl);

        // No need to free memory.

    } else {
        
        // Initialize temporals
        tmp1 = oti_get_tmp( 0, arr->order, arr->nbases,  dhl);
        tmp2 = oti_get_tmp( 1, arr->order, arr->nbases,  dhl);
        tmp3 = oti_get_tmp( 2, arr->order, arr->nbases,  dhl);
        tmp4 = oti_get_tmp( 3, arr->order, arr->nbases,  dhl);

        for (j=0; j<arr->ncols; j++){
            
            // tmp1 = arr->p_data[j];
            oarr_get_item_i_to(arr, j, &tmp1, dhl);
            
            for (i=1; i<arr->nrows; i++){        
                
                oarr_get_item_i_to(arr, ((i+j)%arr->ncols)+i*arr->ncols, &tmp2, dhl);
                oti_copy_to( &tmp1, &tmp3, dhl);
                oti_mul_oo_to(&tmp3,&tmp2,&tmp1, dhl);
                
                // tmp1 *= arr->p_data[ ( (i+j)%arr->ncols ) + i*arr->ncols];

            }

            oti_copy_to( res, &tmp4, dhl);

            oti_sum_oo_to( &tmp4, &tmp1, res, dhl);

            // res += tmp1;

        }

        for (j=0; j<arr->ncols; j++){
            
            // tmp1 = arr->p_data[arr->ncols-1-j];
            oarr_get_item_i_to(arr, arr->ncols-1-j, &tmp1, dhl);
            
            for (i=1; i<arr->nrows; i++){        
                
                // tmp1 *= arr->p_data[ (arr->ncols-1 - (i+j)%arr->ncols ) + i*arr->ncols];
                oarr_get_item_i_to(arr, (arr->ncols-1-(i+j)%arr->ncols)+i*arr->ncols, &tmp2, dhl);
                oti_copy_to( &tmp1, &tmp3, dhl);
                oti_mul_oo_to(&tmp3,&tmp2,&tmp1, dhl);

            }

            oti_copy_to( res, &tmp4, dhl);

            oti_sub_oo_to( &tmp4, &tmp1, res, dhl);

            // res -= tmp1;

        }
        
    }

}
// ----------------------------------------------------------------------------------------------------






