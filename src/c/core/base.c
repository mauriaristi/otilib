
















// ****************************************************************************************************
void dhelp_load( char* strLocation, dhelpl_t* dhl){          
    
    // TODO: Make a reload function that is capable of loading different set of files.
    // TODO: Add a default configuration file that indicates the number of elements to be loaded
    int i;
    
    
    
    dhl->ndh  = 20;             // Number of elements in the ndirs array

                                  //                    Order
    bases_t nbases_ord[]   = {10, // ------------------   1 
                              10, // ------------------   2
                              10, // ------------------   3
                              10, // ------------------   4
                              10, // ------------------   5
                              10, // ------------------   6
                              10, // ------------------   7 
                              10, // ------------------   8
                              10, // ------------------   9
                              10, // ------------------  10
                               5, // ------------------  11
                               5, // ------------------  12
                               5, // ------------------  13
                               5, // ------------------  14
                               5, // ------------------  15
                               5, // ------------------  16
                               5, // ------------------  17
                               5, // ------------------  18
                               5, // ------------------  19
                               5  // ------------------  20
    };


    ndir_t allocSzs_ord[]   = { 2, // ------------------   1 
                                3, // ------------------   2
                                4, // ------------------   3
                                0, // ------------------   4
                                0, // ------------------   5
                                0, // ------------------   6
                                0, // ------------------   7 
                                0, // ------------------   8
                                0, // ------------------   9
                                0, // ------------------  11
                                0, // ------------------  12
                                0, // ------------------  13
                                0, // ------------------  14
                                0, // ------------------  15
                                0, // ------------------  16
                                0, // ------------------  17
                                0, // ------------------  18
                                0, // ------------------  19
                                0  // ------------------  20
    };



    dhl->p_dh = (dhelp_t* )malloc(dhl->ndh*sizeof(dhelp_t));

    dhl->order    = (ord_t*)malloc(1);
    dhl->order[0] = 10;         // Global truncation order.

    if (dhl->p_dh == NULL){

      printf("ERROR: Not enough memory for helper array. Exiting...\n");
      exit(OTI_OutOfMemory);

    }

    ndir_t  ntmps =  25; // Number of arrays for temporal variables.
    
    for( i = 1; i<=dhl->ndh; i++){
      // printf("Loading dhelp %d\n",i);
      dhelp_load_singl(strLocation, i, nbases_ord[i-1], ntmps,allocSzs_ord[i-1], &(dhl->p_dh[i-1]));

    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void dhelp_freeItem( dhelp_t* p_dH){          
    
    uint64_t i;
    
    // Free helper arrays values

    if (p_dH->p_fulldir != NULL){
        free(p_dH->p_fulldir);
    }
    

    if (p_dH->p_ndirs != NULL){
        free(p_dH->p_ndirs);
    }
    

    if (p_dH->p_multtabls != NULL){

        for (i=0;i<p_dH->Nmult;i++){

            free(p_dH->p_multtabls[i].p_arr);

        }

        free(p_dH->p_multtabls);
    }    


    // Free temporal arrays.
    if (p_dH->p_im != NULL){

        for (i=0;i<p_dH->Ntmps;i++){

            free(p_dH->p_im[i]);

        }

        free(p_dH->p_im);
    }  


    if (p_dH->p_idx != NULL){

        for (i=0;i<p_dH->Ntmps;i++){

            free(p_dH->p_idx[i]);

        }

        free(p_dH->p_idx);
    }  


    if (p_dH->p_nnz != NULL){

        for (i=0;i<p_dH->Ntmps;i++){
        
            free(p_dH->p_nnz[i]);

        }

        
        free(p_dH->p_nnz);
    } 


    if (p_dH->p_size != NULL){

        for (i=0;i<p_dH->Ntmps;i++){

            free(p_dH->p_size[i]);

        }

        free(p_dH->p_size);
    } 


    if (p_dH->p_ids != NULL){

        for (i=0;i<p_dH->Ntmps;i++){

            free(p_dH->p_ids[i]);

        }

        free(p_dH->p_ids);
    }

    if (p_dH->p_ims != NULL){

        for (i=0;i<p_dH->Ntmps;i++){

            free(p_dH->p_ims[i]);

        }

        free(p_dH->p_ims);
    }

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void dhelp_print( dhelp_t* p_dH){          
    
    printf("DIRECTION HELPER:\n");
    printf("  Order: ---------------- "_PORDT _ENDL, p_dH->order);
    printf("  Num. Im. directions: -- "_PNDIRT _ENDL, p_dH->Ndir);
    printf("  Num. Im. basis: ------- "_PBASEST _ENDL, p_dH->Nbasis);
    printf("  Num. mult. tables: ---- "_PORDT _ENDL, p_dH->Nmult);
    


}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void dhelp_free(dhelpl_t* dhl){          
    int i;

    for( i = 1; i<=dhl->ndh; i++){
      // printf("Order: "_PORDT"\n",i);
      dhelp_freeItem( &dhl->p_dh[i-1] );

    }

    // Free the list 
    free(dhl->p_dh);
    dhl->p_dh = NULL;

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void dhelp_printImdir(imdir_t indx, ord_t order, dhelpl_t dhl){          

    ord_t i;

    printf("e(");
    for(i = 0; i<order; i++){
        
        printf(_PBASEST ",", array2d_getel_ui16_t(dhl.p_dh[order-1].p_fulldir, order, indx, i));

    }
    printf("\b)");

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_printList(const dhelpl_t dhl){          
    
    ord_t i;

    for( i =0; i<dhl.ndh; i++){

        dhelp_print( &dhl.p_dh[i] );

    }

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void dhelp_multDir(imdir_t  indx1,   ord_t  ord1,   imdir_t indx2, ord_t ord2, 
                   imdir_t* p_ixres, ord_t* p_ores, dhelpl_t dhl){

    ord_t     tmp_ord      = ord1 + ord2;
    imdir2d_t tmp_multtabl ;

    // Check first that the resulting order lies within the available orders:
    if (tmp_ord > dhl.ndh){
        printf("ERROR: Invalid multiplication orders directions: ");
        printf("(idx:"_PIMDIRT",ord:"_PORDT") and (idx:"_PIMDIRT",ord:"_PORDT")", 
            indx1, ord1, indx2, ord2);
        exit(OTI_BadIndx);
    }

    // At this point it is feasible to perform the computations.
    // Assign the resulting order
    *p_ores = tmp_ord;

    if (ord1<ord2){
        
        tmp_multtabl = dhl.p_dh[tmp_ord-1].p_multtabls[ord1-1];
        *p_ixres = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],indx1,indx2);    

    } else {

        tmp_multtabl = dhl.p_dh[tmp_ord-1].p_multtabls[ord2-1];
        *p_ixres = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],indx2,indx1);    

    }


}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
ndir_t dhelp_extract_ndirTotal(bases_t nbases, ord_t order, dhelpl_t dhl){

    ndir_t ndir_total = 1;
    ord_t ord;
    for( ord = 1; ord <= order; ord++){

        //extract each order
        ndir_total += dhelp_extract_ndirOrder( nbases, ord, dhl );

    }

    return ndir_total;
    
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
ndir_t dhelp_ndirTotal(bases_t nbases,ord_t order){

    return dhelp_comb( nbases + order , nbases );

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
ndir_t dhelp_ndirOrder(bases_t nbases,ord_t order){

    return dhelp_comb( nbases + order - 1 , nbases-1 );

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
bases_t* dhelp_get_imdir( imdir_t idx, ord_t order, dhelpl_t dhl){
    
    return &dhl.p_dh[order-1].p_fulldir[idx*order];
}
// ----------------------------------------------------------------------------------------------------








// ****************************************************************************************************
ndir_t dhelp_extract_ndirOrder(bases_t nbases,ord_t order,dhelpl_t dhl){

    // printf("\n ---- Extracting %hu bases and %hhu order\n", nbases, order);

    if (order == 0){

        return 1;

    } else if ( order <= (dhl.ndh + 1) ){
        
        if ( nbases <= dhl.p_dh[order-1].Nbasis){

            // printf("\n ---- Number of directions: %lu\n", dhl.p_dh[order-1].p_ndirs[nbases]);
            // printf("\n ---- In if\n");
            // Extract only when the number of bases exists in the precomputed data.
            return dhl.p_dh[order-1].p_ndirs[nbases];

        } else {

            printf("ERROR: nbases greater than the available precomputed data.\n");
            exit(OTI_NonPreComp);

        }

    } else {

        printf("ERROR: Order greater than the available orders in the precomputed data.\n");
        exit(OTI_NonPreComp);

    }

} 
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void dhelp_imdir2str(imdir_t imdir, ord_t ord, dhelpl_t* dhl, char* str){          
    
    //TODO: Check for inconsistencies.
    int i;
    
    // Get the 
        
    for ( i=0; i<ord; i++){
        sprintf(str,"%hu,",dhl->p_dh[ord].p_fulldir[ord*(imdir-1)+i]);
    }

}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
coeff_t dhelp_get_deriv_factor(imdir_t idx, ord_t order, dhelpl_t dhl){

    coeff_t factor = 1.0;
    bases_t* dirs;
    bases_t dir_prev;
    ord_t i, j = 2;
    
    dirs = dhelp_get_imdir( idx, order, dhl);

    dir_prev = dirs[0];

    for (i=1; i<order; i++){

        if (dirs[i] == dir_prev){
            
            factor *= j;
            j+=1;

        } else{

            j=2;

            dir_prev = dirs[i];
        }
    }

    return factor;

}
// ----------------------------------------------------------------------------------------------------















