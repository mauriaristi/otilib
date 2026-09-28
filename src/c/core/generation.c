// ****************************************************************************************************
imdir_t dhelp_precompute_multiply(bases_t* dir1,ord_t ord1, bases_t* dir2,ord_t ord2, dhelpl_t dhl){
    
    bases_t sorted[256], base;
    ord_t ores = ord1+ord2, i1=0, i2=0, ires=0;
    imdir_t idx =0;
    
    // Sort
    while( 1 ){
        
        if (i1 == ord1 && i2 == ord2){
            
            break;

        } else if (i1 != ord1 && i2 != ord2){
            
            if (dir1[i1] == dir2[i2]){

                sorted[ires++] = dir1[i1++];
                sorted[ires++] = dir2[i2++];
                
            } else {

                if (dir1[i1]<dir2[i2]){
                    sorted[ires++] = dir1[i1++];                    
                }else{
                    sorted[ires++] = dir2[i2++];                    
                }

            }

        } else if(i1 == ord1){
            
            sorted[ires++] = dir2[i2++];

        } else {

            sorted[ires++] = dir1[i1++];

        }
    }

    // Find associated index:
    for (i1 = 0; i1<ores;i1++){
        
        base = sorted[i1];
        
        idx  += dhl.p_dh[i1].p_ndirs[base-1];

    }
    
    return idx;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void dhelp_init_multtabls(ord_t order, bases_t nbases, dhelpl_t* dhl){
    
    ord_t table, o1, o2;
    dhelp_t* p_dH = &dhl->p_dh[order-1];

    // Define the number of multiplication tables 
    p_dH->Nmult = order / 2;
    p_dH->p_multtabls = NULL;

    if (p_dH->Nmult == 0){
        return;
    }

    p_dH->p_multtabls = (imdir2d_t*)malloc( p_dH->Nmult*sizeof(imdir2d_t) );
    
    if (p_dH->p_multtabls==NULL){
        
        printf("ERROR: Not enough memory for multiplication tables. Exiting...\n");
        exit(OTI_OutOfMemory);

    }

    for(table = 0; table<p_dH->Nmult; table++ ){

        o1 = table+1;
        o2 = order-o1;

        // Tables are built on first use (see dhelp_get_multtabl).
        p_dH->p_multtabls[table].p_arr    = NULL;
        p_dH->p_multtabls[table].shape[0] = dhl->p_dh[o1-1].p_ndirs[nbases];
        p_dH->p_multtabls[table].shape[1] = dhl->p_dh[o2-1].p_ndirs[nbases];
        p_dH->p_multtabls[table].ord1     = o1;
        p_dH->p_multtabls[table].ord2     = o2;

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
imdir_t* dhelp_fill_multtabl(ord_t order, ord_t table, dhelpl_t dhl){
    
    const imdir2d_t* p_tabl = &dhl.p_dh[order-1].p_multtabls[table];
    ord_t    o1 = p_tabl->ord1, o2 = p_tabl->ord2;
    uint64_t ndirs_o1 = p_tabl->shape[0], ndirs_o2 = p_tabl->shape[1];
    uint64_t idx1, idx2;
    bases_t* dirs1;
    bases_t* dirs2;
    imdir_t* p_arr;

    p_arr = (imdir_t*)malloc( ndirs_o1*ndirs_o2*sizeof(imdir_t) );

    if (p_arr==NULL){
    
        printf("ERROR: Not enough memory for multiplication table. Exiting...\n");
        exit(OTI_OutOfMemory);

    }

    for(idx1=0;idx1<ndirs_o1;idx1++){

        dirs1  = &dhl.p_dh[o1-1].p_fulldir[idx1*o1]; 

        for(idx2=0;idx2<ndirs_o2;idx2++){
            
            dirs2  = &dhl.p_dh[o2-1].p_fulldir[idx2*o2]; 
            
            p_arr[idx1*ndirs_o2+idx2] = dhelp_precompute_multiply( dirs1, o1, dirs2, o2, dhl);

        }           
    }

    return p_arr;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_precompute_fulldir(ord_t order, bases_t nbases, dhelpl_t* dhl){

    ndir_t ndirs = dhelp_comb(order+nbases-1,order);
    ndir_t i, kk, j, k, ndir_ord_m_1;
    
    dhl->p_dh[order-1].Ndir = ndirs;
    dhl->p_dh[order-1].p_fulldir = (bases_t*)malloc( (ndirs*order)*sizeof(bases_t) );
    
    if (dhl->p_dh[order-1].p_fulldir==NULL){
        
        printf("ERROR: Not enough memory for ndirs array. Exiting...\n");
        exit(OTI_OutOfMemory);

    }

    if (order == 1){
        
        for (i=1; i<=nbases;i++){
            dhl->p_dh[order-1].p_fulldir[i-1] = i;      
        }

    } else {

        kk = 0;
        
        for (i=1; i<=nbases;i++){
            
            ndir_ord_m_1 = dhl->p_dh[order-2].p_ndirs[i];

            for (j=0;j<ndir_ord_m_1;j++){
                
                for ( k=0; k<(order-1); k++){
                    
                    dhl->p_dh[order-1].p_fulldir[(kk+j)*order +k] = 
                        dhl->p_dh[order-2].p_fulldir[ j*(order-1) + k];
                
                }
                
                dhl->p_dh[order-1].p_fulldir[(kk+j+1)*order-1] = i;

            }

            kk += ndir_ord_m_1;
        
        }       

    }
    // // Set value for 0.
    // dhl.p_dh[order-1].p_ndirs[0] = 0;

    // for (i=0; i<ndirs; i++){

    //  dhl.p_dh[order-1].p_[i] = comb(order+m-1,order);
    // }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void dhelp_precompute_ndirs(ord_t order, bases_t nbases, dhelpl_t* dhl){

    bases_t m = 0;
    
    dhl->p_dh[order-1].p_ndirs = (ndir_t*)malloc( (nbases+1)*sizeof(ndir_t) );
    
    if (dhl->p_dh[order-1].p_ndirs==NULL){
        
        printf("ERROR: Not enough memory for ndirs array. Exiting...\n");
        exit(OTI_OutOfMemory);

    }

    // Set value for 0.
    dhl->p_dh[order-1].p_ndirs[0] = 0;

    for (m=1; m<(nbases+1); m++){

        dhl->p_dh[order-1].p_ndirs[m] = dhelp_comb(order+m-1,order);
    }

}
// ----------------------------------------------------------------------------------------------------
