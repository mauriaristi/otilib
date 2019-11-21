// ****************************************************************************************************
void dhelp_precompute(char* directory, bases_t* max_basis_k, ord_t maxorder ){

    dhelpl_t dhl;
    ord_t order,ntabls;
    // char fullpathname[1024];
    // char filename[1024], holder[1024];

    dhl.p_dh = (dhelp_t* )malloc( maxorder * sizeof(dhelp_t) );

    if (dhl.p_dh == NULL){

      printf("ERROR: Not enough memory for helper array. Exiting...\n");
      exit(OTI_OutOfMemory);

    }
    for ( order = 1; order<=maxorder; order++){
        

        
        // ndirs
        printf("\n\n---------------------------------------------------\n");
        printf("Precomputing data for order " _PUINT8T ".\n",order);
        // printf("Generating ndirs\n");
        
        dhelp_precompute_ndirs( order, max_basis_k[order-1], &dhl); 
        
        // printf("Successfully generated ndirs\n");
        
        dhelp_save_ndirs(directory,max_basis_k[order-1],order,dhl);


        // Full dir.
        // printf("Generating fulldir\n");
        
        dhelp_precompute_fulldir( order, max_basis_k[order-1], &dhl);   
        
        // printf("Successfully generated fulldir\n");

        dhelp_save_fulldir(directory,max_basis_k[order-1],order,dhl);
        



        // printf("Generating multtabls\n");
        dhelp_precompute_multtabls( order,  max_basis_k[order-1], &dhl);
        
        dhelp_save_multtabls( directory, max_basis_k[order-1], order, dhl);

    }

    printf("Exiting:\n");
    
    for ( order = 1; order<=maxorder; order++){
        free(dhl.p_dh[order-1].p_fulldir);
        free(dhl.p_dh[order-1].p_ndirs);
        
        for (ntabls = 0; ntabls < dhl.p_dh[order-1].Nmult; ntabls++){
            free(dhl.p_dh[order-1].p_multtabls[ntabls].p_arr);  
        }
        free(dhl.p_dh[order-1].p_multtabls);    
    }
    free(dhl.p_dh); 
}
// ----------------------------------------------------------------------------------------------------






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
                // i1+=1; i2+=1; ires+=2;
            } else {
                if (dir1[i1]<dir2[i2]){
                    sorted[ires++] = dir1[i1++];
                    // res++; i1++;
                }else{
                    sorted[ires++] = dir2[i2++];
                    // res++; i2++;
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
        // printf("%hu,",base);
        idx  += dhl.p_dh[i1].p_ndirs[base-1];

    }
    // printf("\n%lu\n",idx);
    return idx;
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_precompute_multtabls(ord_t order, bases_t nbases, dhelpl_t* dhl){
    
    ndir_t ndirs_o1, ndirs_o2, idx1, idx2,i=0;
    // Define the number of multiplication tables 
    ord_t n_multtabls = order / 2, o1, o2,j ;
    bases_t* dirs1;
    bases_t* dirs2;
    ord_t table;
    
    dhl->p_dh[order-1].Nmult = n_multtabls;
    dhl->p_dh[order-1].p_multtabls = (imdir2d_t*)malloc( n_multtabls*sizeof(imdir2d_t) );
    
    if (dhl->p_dh[order-1].p_multtabls==NULL){
        
        printf("ERROR: Not enough memory for ndirs array. Exiting...\n");
        exit(OTI_OutOfMemory);

    }


    for(table = 0; table<n_multtabls; table++ ){

        o1 = table+1;
        o2 = order-table-1;

        printf("    Multiplication table " _PORDT "\n",o1);
        printf("       order " _PORDT " X " _PORDT "\n",o1,o2);

        ndirs_o1 = dhl->p_dh[o1-1].p_ndirs[nbases];
        ndirs_o2 = dhl->p_dh[o2-1].p_ndirs[nbases];


        dhl->p_dh[order-1].p_multtabls[table].p_arr = 
            (imdir_t*)malloc( ndirs_o1*ndirs_o2*sizeof(imdir_t) );
        dhl->p_dh[order-1].p_multtabls[table].shape[0] = ndirs_o1;
        dhl->p_dh[order-1].p_multtabls[table].shape[1] = ndirs_o2;

        if (dhl->p_dh[order-1].p_multtabls==NULL){
        
            printf("ERROR: Not enough memory for ndirs array. Exiting...\n");
            exit(OTI_OutOfMemory);

        }
        i=0;
        for(idx1=0;idx1<ndirs_o1;idx1++){

            dirs1  = &dhl->p_dh[o1-1].p_fulldir[idx1*o1]; 
            // printf("%lu\n",i);
            if ( (i%100) == 0){
                printf("        mult [");
                for (j=0;j<o1;j++){
                    printf("%hu,",dirs1[j]);
                }
                printf("\b] iter " _PNDIRT "/" _PNDIRT " \n ",idx1*ndirs_o2+1,ndirs_o1*ndirs_o2);
            }
            i+=1;

            for(idx2=0;idx2<ndirs_o2;idx2++){
                
                dirs2  = &dhl->p_dh[o2-1].p_fulldir[idx2*o2]; 
                
                dhl->p_dh[order-1].p_multtabls[table].p_arr[idx1*ndirs_o2+idx2] =  
                    dhelp_precompute_multiply( dirs1, o1, dirs2, o2, *dhl);

            }           
        }

    }

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

// ****************************************************************************************************
void dhelp_save_fulldir(char* directory, bases_t base, ord_t order, dhelpl_t dhl ){

    char fullpathname[1024];
    char filename[1024], holder[1024];

    strcpy(fullpathname,directory);
        
    strcpy(filename,"fulldir_n");
    sprintf(holder, _PORDT, order);
    strcat(filename,holder);
    strcat(filename,"_m");
    sprintf(holder, _PBASEST, base);
    strcat(filename,holder);
    strcat(filename,".npy");
    
    strcat(fullpathname,filename);

    printf("Saving file: %s \n",fullpathname);
    savenpy(fullpathname,2,dhl.p_dh[order-1].p_fulldir,dhl.p_dh[order-1].Ndir,order);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_save_ndirs(char* directory, bases_t base, ord_t order,  dhelpl_t dhl){

    char fullpathname[1024];
    char filename[1024], holder[1024];
    

    strcpy(fullpathname,directory);

    strcpy(filename,"ndirs_n");
    sprintf(holder, _PORDT, order);
    strcat(filename,holder);
    strcat(filename,"_m");
    sprintf(holder, _PBASEST, base);
    strcat(filename,holder);
    strcat(filename,".npy");
    strcat(fullpathname,filename);

    printf("Saving file: %s \n",fullpathname);
    savenpy(fullpathname,4,dhl.p_dh[order-1].p_ndirs, base + 1,0);


}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_save_multtabls(char* directory, bases_t base, ord_t order,  dhelpl_t dhl){

    char fullpathname[1024];
    char filename[1024], holder[1024];
    
    ord_t nmults = dhl.p_dh[order-1].Nmult;
    ord_t i;
    ndir_t shapex, shapey;

    for ( i=0; i<nmults; i++ ){

        strcpy(fullpathname,directory);

        strcpy(filename,"multtabl_n");
        sprintf(holder, _PORDT, order);
        strcat(filename,holder);
        strcat(filename,"_m");
        sprintf(holder, _PBASEST, base);
        strcat(filename,holder);
        strcat(filename,"_");
        sprintf(holder, _PORDT, i);
        strcat(filename,holder);
        strcat(filename,".npy");
        strcat(fullpathname,filename);

        printf("Saving file: %s \n",fullpathname);

        shapex = dhl.p_dh[order-1].p_multtabls[i].shape[0];
        shapey = dhl.p_dh[order-1].p_multtabls[i].shape[1];

        savenpy(fullpathname,4,dhl.p_dh[order-1].p_multtabls[i].p_arr, shapex, shapey);

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void savenpy(char* filename, uint8_t dtype, void* data, uint64_t shapex, 
    uint64_t shapey){
    
    // uint8_t n_known_types = 5; // Number of known types

    char known_types_char[5][76]={
      " '|u1'",                     // uint8_t // '<u2': Little endian, unsigned int, 2 bytes
      " '<u1'",                     // uint8_t
      " '<u2'",                     // uint16_t 
      " '<u4'",                     // uint32_t
      " '<u8'",                     // uint64_t
    };

    uint8_t known_types_size[5]={
      sizeof(uint8_t),              // uint8_t
      sizeof(uint8_t),              // uint8_t
      sizeof(uint16_t),             // uint16_t
      sizeof(uint32_t),             // uint32_t
      sizeof(uint64_t),             // uint64_t
    };

    char header[65536], header_body[65536];
    char magic[7] = {0x93,'N','U','M','P','Y','\0'}; // Magic keyword
    char version[3] = {1,0,'\0'}; // Only V1.0 supported for now.
    char shape_str[1024];

    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size, heade_len_factor;
    short unsigned int size_2_print;
    uint64_t  size_of_data=1,wrote;
    uint16_t j;

    strcpy(header, magic);
    header[6] = version[0]; header[7] = version[1];

    

    if (shapey != 0){
        
        size_of_data = shapex*shapey;
        sprintf(shape_str,_PUINT64T","_PUINT64T,shapex,shapey);

    } else {
        
        size_of_data = shapex;
        sprintf(shape_str,_PUINT64T",",shapex);

    }

    sprintf(header_body,"{'descr':%s,'fortran_order': False, 'shape': (%s), }",
        known_types_char[dtype],shape_str);
    header_size = strlen(header_body);

    heade_len_factor = (10+header_size)/16 + 1;
    size_2_print = heade_len_factor*16-10;
    // fill with spaces
    for( j = header_size; j<size_2_print; j++){
        header_body[j] = ' ';
    }
    header_body[size_2_print-1] = '\n';
    header_body[size_2_print] = '\0';
    
    header[8]=((char*)(&size_2_print))[0];
    header[9]=((char*)(&size_2_print))[1];// Todo add support to check Endianness
    
    for( j = 0; j<size_2_print; j++){
        header[j+10] = header_body[j];
    }


    // printf("header body: '%s'\n",header_body);
    // printf("header body length: '%hu'\n",header_size);
    // printf("header final body length: '%hu'\n",size_2_print);
    // printf("size first byte: '%hhu, %c, %hhu'\n", ((char*)(&size_2_print))[0], ((char*)(&size_2_print))[0], header[8]);
    // printf("size second byte: '%hhu, %c, %hhu'\n",((char*)(&size_2_print))[1], ((char*)(&size_2_print))[1], header[9]);
    
    if(filename != NULL ){
        
        cfPtr = fopen( filename, "wb" );
        if (cfPtr == NULL){
            printf("Error: Could not create file %s.\n",filename);
            exit(OTI_undetErr);
        }
        wrote = fwrite(header,sizeof(char),size_2_print+10,cfPtr);

        if (wrote != size_2_print+10){
            printf("Error: written sizes dont match.\n");
            exit(OTI_undetErr);
        }

        wrote = fwrite(data,known_types_size[dtype],size_of_data,cfPtr);        

        if (wrote != size_of_data){
            printf("Error: written sizes dont match.\n");
            exit(OTI_undetErr);
        }

        fclose(cfPtr);
    }
    

    

}
// ----------------------------------------------------------------------------------------------------



