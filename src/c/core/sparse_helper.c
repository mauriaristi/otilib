// ****************************************************************************************************
void dhelp_sparse_mult_real( coeff_t val,
                       coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,         
                       dhelpl_t dhl){                            // Helper

    ndir_t i;
    (*ndirres) = ndir1;

    for ( i = 0; i<ndir1; i++){

        p_imres[i]  = val*p_im1[i];
        p_idxres[i] = p_idx1[i];

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_sparse_copy(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       dhelpl_t dhl){                            // Helper

    
    if( ndir1 != 0 ){
        
        memcpy(p_imres,  p_im1,  ndir1*sizeof(coeff_t) );
        memcpy(p_idxres, p_idx1, ndir1*sizeof(imdir_t) );    

    }
    

    (*ndirres) = ndir1;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline void dhelp_sparse_sub_dirs(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                           coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, 
                           coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           
                           dhelpl_t dhl){

    ndir_t j1, j2, jres;
    imdir_t dir1, dir2;

    j1   = 0; 
    j2   = 0;
    jres = 0;
    
    while( 1 ){
    
        if ( j1 < ndir1 && j2 < ndir2 ){
            
            dir1 = p_idx1[j1];
            dir2 = p_idx2[j2];
            
            if (dir1 == dir2){
                
                p_imres[jres] = p_im1[j1] - p_im2[j2];
                p_idxres[jres] = dir1;
                j1++; j2++; jres++;

            } else if ( dir1 < dir2 ){

                p_imres[jres] = p_im1[j1];
                p_idxres[jres] = dir1;
                jres++; j1++;

            } else {

                p_imres[jres]  = -p_im2[j2];
                p_idxres[jres] = dir2;
                jres++; j2++;

            }

        } else if ( j1 < ndir1 ){

            while( j1 < ndir1 ){

                p_imres[jres]  = p_im1[j1];
                p_idxres[jres] = p_idx1[j1];
                jres++; j1++;    

            }

            break;

        } else if ( j2 < ndir2 ){   

            while ( j2 < ndir2 ){

                p_imres[jres]  = -p_im2[j2];
                p_idxres[jres] = p_idx2[j2];
                jres++; j2++;    

            }

            break;

        } else {

            break;

        }
    
    }

    (*ndirres) = jres;
}
// ----------------------------------------------------------------------------------------------------











// ****************************************************************************************************
inline void dhelp_sparse_add_dirs_new(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                           coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, 
                           coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           
                           dhelpl_t dhl){

    ndir_t  j2, jres; //, offset;
    // imdir_t dir1, dir2;
    // coeff_t im1, im2;

    flag_t flag1;
    
    // Copy all elements fron dir1 to the result: a*a
    memcpy(p_imres ,p_im1 ,ndir1*sizeof(coeff_t));
    memcpy(p_idxres,p_idx1,ndir1*sizeof(imdir_t));
    *ndirres = ndir1;

    // offset   = 0;
    j2   = 0;
    jres = 0;
    
    for( j2=0; j2 < ndir2; j2++ ){ 
        
        
        // printf("Seraching %lu\n",p_idx2[j2]);
        // offset = jres;
        jres += binSearchUI64( p_idx2[j2], &p_idxres[jres], *ndirres-jres, &flag1);
        // jres = binSearchUI64( p_idx2[j2], p_idxres,        *ndirres,      &flag1);

        if (flag1){
            // The elment exists in res, add them together
            // printf("Found same indx, adding up\n");
            p_imres[jres] += p_im2[j2];

        } else {
            // Insert the element in the list at the proper position.
            // printf("Found different indx, inserting new element\n");
            memmove( &p_idxres[jres+1], &p_idxres[jres], (*ndirres-jres)*sizeof(imdir_t));
            memmove( &p_imres[jres+1],  &p_imres[jres],  (*ndirres-jres)*sizeof(coeff_t));
            
            p_imres[jres]  = p_im2[j2] ;
            p_idxres[jres] = p_idx2[j2];
            (*ndirres)    += 1;


        }
        // printArrayDBL( p_imres, *ndirres);printf("\n");
        // printArrayUI64(p_idxres,*ndirres);printf("\n\n");

        
        

    }

    
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void dhelp_sparse_add_dirs_old(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                           coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, 
                           coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           
                           dhelpl_t dhl){

    ndir_t j1, j2, jres;
    imdir_t dir1, dir2;
    coeff_t im1, im2;

    flag_t upd_1, upd_2;

    j1   = 0;
    j2   = 0;
    jres = 0;
    
    while(  j1 < ndir1 && j2 < ndir2 ){        

        dir1 = p_idx1[j1];
        im1  = p_im1[j1];

        dir2 = p_idx2[j2];
        im2  = p_im2[j2];        
        
        upd_1=(dir1<=dir2);
        upd_2=(dir2<=dir1);

        p_imres[jres]  = upd_1*im1  + upd_2*im2;
        p_idxres[jres] = upd_1*dir1 + (dir2<dir1)*dir2;

        j1+=upd_1; 
        j2+=upd_2; 

        jres++;
    
    }

    for( ; j1 < ndir1; j1++ ){

        p_imres[jres]  = p_im1[j1];
        p_idxres[jres] = p_idx1[j1];
        jres++;  

    }

    for ( ; j2 < ndir2; j2++ ){

        p_imres[jres]  = p_im2[j2];
        p_idxres[jres] = p_idx2[j2];
        jres++;   

    }

    (*ndirres) = jres;
}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void dhelp_sparse_add_dirs(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                           coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, 
                           coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           
                           dhelpl_t dhl){

    ndir_t j1, j2, jres;
    imdir_t dir1, dir2;

    j1   = 0;
    j2   = 0;
    jres = 0;
    
    while( 1 ){
    
        if ( j1 < ndir1 && j2 < ndir2 ){
            
            dir1 = p_idx1[j1];
            dir2 = p_idx2[j2];
            
            if (dir1 == dir2){
                
                p_imres[jres] = p_im1[j1] + p_im2[j2];
                p_idxres[jres] = dir1;
                j1++; j2++; jres++;

            } else if ( dir1 < dir2 ){
                
                // while(dir1 < dir2 && j1 < ndir1){

                //     dir1 = p_idx1[j1];

                    p_imres[jres] = p_im1[j1];
                    p_idxres[jres] = dir1;
                    jres++; j1++;    

                // }
                

            } else {

                // while(dir2 < dir1 && j2 < ndir2){

                    // dir2 = p_idx2[j2];

                    p_imres[jres]  = p_im2[j2];
                    p_idxres[jres] = dir2;
                    jres++; j2++;

                // }

            }

        } else if ( j1 < ndir1 ){

            for( ; j1 < ndir1; j1++ ){

                p_imres[jres]  = p_im1[j1];
                p_idxres[jres] = p_idx1[j1];
                jres++;  

            }

            break;

        } else if ( j2 < ndir2 ){   

            for ( ; j2 < ndir2; j2++ ){

                p_imres[jres]  = p_im2[j2];
                p_idxres[jres] = p_idx2[j2];
                jres++;   

            }

            break;            

        } else {

            break;

        }
    
    }

    (*ndirres) = jres;
}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void dhelp_sparse_mult(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1, // Input 1
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2, // Input 2
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       dhelpl_t dhl){                            // Helper

    // This function multiplies two arrays of imaginary coefficients.
    ord_t     tmp_ord      = ord1 + ord2;
    imdir2d_t tmp_multtabl ;
    ndir_t i,j;

    // Get temporal arrays 0,1 and 2. These must be reserved at all times for this porpuses.
    coeff_t* p_im_tmp1  = dhl.p_dh[tmp_ord-1].p_im[0] ;
    coeff_t* p_im_tmp2  = dhl.p_dh[tmp_ord-1].p_im[1] ;
    coeff_t* p_im_tmp3  = dhl.p_dh[tmp_ord-1].p_im[2] ;

    imdir_t* p_idx_tmp1 = dhl.p_dh[tmp_ord-1].p_idx[0] ;
    imdir_t* p_idx_tmp2 = dhl.p_dh[tmp_ord-1].p_idx[1] ;
    imdir_t* p_idx_tmp3 = dhl.p_dh[tmp_ord-1].p_idx[2] ;
    

    // Define temporal swappers.
    coeff_t* p_im_tmpsrc = p_im_tmp2;
    coeff_t* p_im_tmpdest= p_im_tmp3;
    coeff_t* p_im_tmpswap;
    imdir_t* p_idx_tmpsrc = p_idx_tmp2;
    imdir_t* p_idx_tmpdest= p_idx_tmp3;
    imdir_t* p_idx_tmpswap;

    // ndir_t   ndirtmp=0;
    ndir_t   ndirtmpsrc=0;
    ndir_t   ndirtmpdest=0;
    ndir_t   ndirtmpswap;
    
    imdir_t idx_next_res = 0;
    imdir_t idx_i;
    coeff_t im_i;
    (*ndirres) = 0;

    flag_t flag =0;
    
    coeff_t* p_immin;
    imdir_t* p_idxmin;
    ndir_t   ndirmin;
    ord_t    ordmin;

    coeff_t* p_immax;
    imdir_t* p_idxmax;
    ndir_t  ndirmax;
    ord_t ordmax;

    if (ndir1 >0 && ndir2 >0){

        // Sort input directions by length.        
        if(ndir1 < ndir2){

            p_immin  = p_im1;
            p_idxmin = p_idx1;
            ndirmin  = ndir1;
            ordmin   = ord1;

            p_immax  = p_im2;
            p_idxmax = p_idx2;
            ndirmax  = ndir2;
            ordmax   = ord2;

        } else {
            
            p_immin  = p_im2;
            p_idxmin = p_idx2;
            ndirmin  = ndir2;
            ordmin   = ord2;

            p_immax  = p_im1;
            p_idxmax = p_idx1;
            ndirmax  = ndir1;
            ordmax   = ord1;

        }

        if (ordmax < ordmin){
            flag=1;
        }

        // Get the relevant multiplication table.
        if ( flag ){
            
            tmp_multtabl = dhl.p_dh[tmp_ord-1].p_multtabls[ordmax-1];

        } else {
            
            tmp_multtabl = dhl.p_dh[tmp_ord-1].p_multtabls[ordmin-1];

        }
        
        
        
        // Check previous elements from next direction.:
        for ( i = 0; i<ndirmin; i++){

            idx_i = p_idxmin[i];
            im_i = p_immin[i];

            for ( j = 0; j<ndirmax; j++){

                // Multiply the elements
                if (flag){
                    
                    idx_next_res = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],
                        p_idxmax[j],idx_i); 

                } else {

                    idx_next_res = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],
                        idx_i,p_idxmax[j]); 

                }
                
                // Add index to temporal result.
                p_im_tmp1[j] = im_i * p_immax[j];
                p_idx_tmp1[j] = idx_next_res;
                
            }


            // // Add to temporal holding the result.
            // dhelp_sparse_copy(p_imres, p_idxres, *ndirres,
            //            p_im_tmp2, p_idx_tmp2, &ndirtmp,dhl);
            
            // dhelp_sparse_add_dirs(p_im_tmp2, p_idx_tmp2, ndirtmp,
            //                p_im_tmp1, p_idx_tmp1, ndirmax,
            //                p_imres, p_idxres, ndirres, dhl);

            // Swap terms.
            p_im_tmpswap = p_im_tmpsrc; 
            p_im_tmpsrc  = p_im_tmpdest; 
            p_im_tmpdest = p_im_tmpswap;

            p_idx_tmpswap = p_idx_tmpsrc; 
            p_idx_tmpsrc  = p_idx_tmpdest; 
            p_idx_tmpdest = p_idx_tmpswap;
            
            ndirtmpswap = ndirtmpsrc; 
            ndirtmpsrc  = ndirtmpdest; 
            ndirtmpdest = ndirtmpswap;
            
            dhelp_sparse_add_dirs(p_im_tmpsrc, p_idx_tmpsrc, ndirtmpsrc,
                           p_im_tmp1, p_idx_tmp1, ndirmax,
                           p_im_tmpdest, p_idx_tmpdest, &ndirtmpdest, dhl);

        }
        
    }

    dhelp_sparse_copy(p_im_tmpdest, p_idx_tmpdest, ndirtmpdest,
                       p_imres, p_idxres, ndirres, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void dhelp_sparse_mult_old(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1, // Input 1
                           coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2, // Input 2
                           coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                           dhelpl_t dhl){                            // Helper


    ord_t     tmp_ord      = ord1 + ord2;
    imdir2d_t tmp_multtabl ;
    ndir_t i,j;

    imdir_t idx_curr_res = 0;
    imdir_t idx_next_res = 0;
    (*ndirres) = 0;
    
    coeff_t* p_immin;
    imdir_t* p_idxmin;
    ndir_t   ndirmin;
    ord_t    ordmin;

    coeff_t* p_immax;
    imdir_t* p_idxmax;
    ndir_t  ndirmax;
    ord_t ordmax;

    if (ndir1 >0 && ndir2 >0){

        // Sort input directions by order.
        
        if(ord1 < ord2){

            p_immin  = p_im1;
            p_idxmin = p_idx1;
            ndirmin  = ndir1;
            ordmin   = ord1;

            p_immax  = p_im2;
            p_idxmax = p_idx2;
            ndirmax  = ndir2;
            ordmax   = ord2;

        } else {
            
            p_immin  = p_im2;
            p_idxmin = p_idx2;
            ndirmin  = ndir2;
            ordmin   = ord2;

            p_immax  = p_im1;
            p_idxmax = p_idx1;
            ndirmax  = ndir1;
            ordmax   = ord1;

        }

        // Get the relevant multiplication table.
        tmp_multtabl = dhl.p_dh[tmp_ord-1].p_multtabls[ordmin-1];
        
        // Do first multiplication:
        // idx1[0] * idx2[0];
        
        idx_next_res = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],
            p_idxmin[0],p_idxmax[0]); 

        // printf("Adding %lu\n",idx_next_res);
        // (*ndirres)+=1;
        
        dhelp_add_coeff( p_imres, p_idxres, ndirres, 
                        p_immin[0]*p_immax[0], idx_next_res );

        idx_curr_res = idx_next_res;    
        // Check previous elements from next direction.:
        for (i = 0; i<ndirmin; i++){

            for (j = 0; j<ndirmax; j++){

                idx_next_res = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],
                    p_idxmin[i],p_idxmax[j]); 

                if (idx_next_res > idx_curr_res){
                    // printf("next: %lu, prev: %lu,\n",idx_next_res,idx_curr_res);
                    dhelp_search_prev_dir(  p_immin,  p_idxmin, ndirmin, ordmin, 
                                      p_immax,  p_idxmax, ndirmax, ordmax, 
                                      p_imres,  p_idxres, ndirres,         
                                      idx_curr_res, idx_next_res, i, j,tmp_multtabl);
                    // Add direction
                        
                    dhelp_add_coeff( p_imres, p_idxres, ndirres, 
                        p_immin[i]*p_immax[j], idx_next_res );

                    idx_curr_res = idx_next_res;    
                }
            }
        }
    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
inline void dhelp_add_coeff( coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres, 
    coeff_t im, imdir_t idx ){

    // This function assumes that the 
    if (*ndirres != 0){
        
        if (p_idxres[(*ndirres)-1] == idx){
            
            p_imres[(*ndirres)-1] += im;

        } else {
        
            p_imres[(*ndirres)] = im;
            p_idxres[(*ndirres)] = idx;
            (*ndirres) += 1;

        }

    } else {

        p_imres[0]  = im;
        p_idxres[0] = idx;
        (*ndirres) = 1;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_search_prev_dir(  coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1, // Input 1
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2, // Input 2 
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       imdir_t prev_idx, imdir_t next_idx, ndir_t curr_i1, ndir_t curr_i2,
                       imdir2d_t tmp_multtabl){                                        // Helper
    
    // i1 - > Index along im1
    // i2 - > Index along im2
    
    // Looking forward directions in the multtabl of im1 x im2 that are:
    // 
    // idx > prev_idx && idx <= next_idx
     
    ndir_t  next_i1;
    ndir_t  next_i2;
    // ord_t   ord_res;
    imdir_t idx_res= 0 ;

    if (curr_i1 == ndir1-1){

        // No need to find more values.
        return;

    } else {
        next_i1 = curr_i1+1;

        for (next_i2 = 0; next_i2<curr_i2; next_i2++){

            // Find the result of multiplying the next elements
            idx_res = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],
                p_idx1[next_i1], p_idx2[next_i2] ); 


            if (idx_res > prev_idx ){
                

                if (idx_res <= next_idx ){
                    // Perform recursive call
                    dhelp_search_prev_dir(p_im1, p_idx1, ndir1, ord1, // Input 1
                                    p_im2, p_idx2, ndir2, ord2, // Input 2 
                                    p_imres, p_idxres, ndirres, // Result
                                    prev_idx, idx_res, next_i1, next_i2,
                                    tmp_multtabl);

                    // Add direction
                    dhelp_add_coeff( p_imres, p_idxres, ndirres, 
                        p_im1[next_i1]*p_im2[next_i2], idx_res );

                    dhelp_search_prev_dir(p_im1, p_idx1, ndir1, ord1, // Input 1
                                    p_im2, p_idx2, ndir2, ord2, // Input 2 
                                    p_imres, p_idxres, ndirres, // Result
                                    idx_res, next_idx, next_i1, curr_i2,
                                    tmp_multtabl);
                    
                } else {
                    dhelp_search_prev_dir(p_im1, p_idx1, ndir1, ord1, // Input 1
                                    p_im2, p_idx2, ndir2, ord2, // Input 2 
                                    p_imres, p_idxres, ndirres, // Result
                                    prev_idx, next_idx, next_i1, curr_i2,
                                    tmp_multtabl);
                    break;
                }

            }
        
        }
        if (idx_res<= prev_idx){
            dhelp_search_prev_dir(p_im1, p_idx1, ndir1, ord1, // Input 1
                        p_im2, p_idx2, ndir2, ord2, // Input 2 
                        p_imres, p_idxres, ndirres, // Result
                        prev_idx, next_idx, next_i1, curr_i2,
                        tmp_multtabl);  
        }

        return;

    }

}
// ----------------------------------------------------------------------------------------------------


