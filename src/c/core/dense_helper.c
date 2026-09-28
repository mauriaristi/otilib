
// ****************************************************************************************************
void dhelp_dense_mult(coeff_t* p_im1, ndir_t ndir1, ord_t ord1, // Input 1
                      coeff_t* p_im2, ndir_t ndir2, ord_t ord2, // Input 2
                      coeff_t* p_imres, ndir_t ndirres,         // Result
                      dhelpl_t dhl){                            // Helper
    
    const imdir2d_t* tmp_multtabl ;
    ndir_t ndir_i1, ndir_i2;
    imdir_t i,j;
    coeff_t* p_dir1;
    coeff_t* p_dir2;
        
    if (ord1<ord2){
    
        tmp_multtabl = dhelp_get_multtabl(ord1+ord2, ord1, dhl);
        ndir_i1 = ndir1; ndir_i2 = ndir2;
        p_dir1 = p_im1;
        p_dir2 = p_im2;

    } else {

        tmp_multtabl = dhelp_get_multtabl(ord1+ord2, ord2, dhl);
        ndir_i1 = ndir2; ndir_i2 = ndir1;
        p_dir1 = p_im2;
        p_dir2 = p_im1;
    }

    for ( i =0; i<ndir_i1; i++){

        for ( j =0; j<ndir_i2; j++){
        
            imdir_t imdir_res = 
                array2d_getel_ui64_t(tmp_multtabl->p_arr,tmp_multtabl->shape[1],i,j);

            p_imres[imdir_res] +=  p_dir1[i]*p_dir2[j] ;

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void dhelp_dense_mult_real(coeff_t* p_im1, ndir_t ndir1, // Input 1
                      coeff_t a,                         // Input 2
                      coeff_t* p_imres, ndir_t ndirres,  // Result
                      dhelpl_t dhl){                     // Helper
    
    ndir_t i;
        
    for ( i =0; i< MIN( ndir1, ndirres ); i++){
        
        p_imres[i] +=  a*p_im1[i] ;

    }

}
// ----------------------------------------------------------------------------------------------------













