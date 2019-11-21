
















// ****************************************************************************************************
void loadnpy_fulldir( char* strLocation, ord_t order, bases_t nbasis, dhelp_t* p_dH){

    char filename[1000], holder[100];
    uint64_t shape[2]={1,1};
    uint8_t   ndim;

    // printf("Loading dhelp Full dir\n");

    // Concatenate the filename.
    strcpy(filename,strLocation);
    strcat(filename,"/fulldir_n");
    sprintf(holder, _PORDT, order);
    strcat(filename,holder);
    strcat(filename,"_m");
    sprintf(holder, _PBASEST, nbasis);
    strcat(filename,holder);
    strcat(filename,".npy");

    // printf("%s\n",filename);

    // Load array.
    loadnpy(filename, (void**) &p_dH->p_fulldir, &ndim, shape);
    p_dH->Ndir = shape[0];
    p_dH->order= order;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void loadnpy_multtabls( char* strLocation, ord_t order, bases_t nbasis, dhelp_t* p_dH){
    
    char filename[1000], holder[100];
    //uint64_t shape[2]={1,1};
    uint8_t   ndim;
    uint64_t k;

    // Determine the number of operations.
    p_dH->Nmult = order/2;

    p_dH->p_multtabls = (imdir2d_t*)malloc(p_dH->Nmult*sizeof(imdir2d_t));

    if (p_dH->p_multtabls!=NULL){

        for (k=0;k<p_dH->Nmult;k++){

            // Concatenate the filename.
            strcpy(filename,strLocation);
            strcat(filename,"/multtabl_n");
            sprintf(holder, _PORDT, order);
            strcat(filename,holder);
            strcat(filename,"_m");
            sprintf(holder, _PBASEST, nbasis);
            strcat(filename,holder);
            strcat(filename,"_");
            sprintf(holder, _PUINT64T, k);
            strcat(filename,holder);
            strcat(filename,".npy");
            

            // Load the numpy array.
            loadnpy(filename, (void**) &p_dH->p_multtabls[k].p_arr, &ndim, p_dH->p_multtabls[k].shape);

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void loadnpy_ndirs( char* strLocation, ord_t order, bases_t nbasis, dhelp_t* p_dH){
   
    char filename[1000], holder[100];
    uint64_t shape[2]={1,1};
    uint8_t   ndim;

    // printf("Loading ndirs\n");

    // Concatenate the filename
    strcpy(filename,strLocation);
    strcat(filename,"/ndirs_n");
    sprintf(holder, _PORDT, order);
    strcat(filename,holder);
    strcat(filename,"_m");
    sprintf(holder, _PBASEST, nbasis);
    strcat(filename,holder);
    strcat(filename,".npy");
    

    // printf("%s\n",filename);

    // Load the array.
    loadnpy(filename, (void**) &p_dH->p_ndirs, &ndim, shape);    

}
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
void dhelp_load_tmps( dhelp_t* p_dH){

    ndir_t i;
    // Allocate pointers
    p_dH->p_im  = ( coeff_t**) malloc(p_dH->Ntmps*sizeof( coeff_t*));
    p_dH->p_idx = ( imdir_t**) malloc(p_dH->Ntmps*sizeof( imdir_t*)); 
    
    p_dH->p_ims = (coeff_t***) malloc(p_dH->Ntmps*sizeof(coeff_t**));
    p_dH->p_ids = (imdir_t***) malloc(p_dH->Ntmps*sizeof(imdir_t**));

    p_dH->p_nnz = (  ndir_t**) malloc(p_dH->Ntmps*sizeof(  ndir_t*));
    p_dH->p_size= (  ndir_t**) malloc(p_dH->Ntmps*sizeof(  ndir_t*));

    if ( p_dH->p_im  == NULL || p_dH->p_idx  == NULL ||
         p_dH->p_ims == NULL || p_dH->p_ids  == NULL ||
         p_dH->p_nnz == NULL || p_dH->p_size == NULL   ){

      printf("ERROR: Not enough memory for temporal arrays. Exiting...\n");
      exit(OTI_OutOfMemory);

    }

    for (i = 0; i<p_dH->Ntmps; i++){

        p_dH->p_im[i]   = (coeff_t*) malloc( p_dH->Ndir*sizeof(coeff_t));
        p_dH->p_idx[i]  = (imdir_t*) malloc( p_dH->Ndir*sizeof(imdir_t));

        p_dH->p_ims[i]  = (coeff_t**) malloc( p_dH->order*sizeof(coeff_t*));
        p_dH->p_ids[i]  = (imdir_t**) malloc( p_dH->order*sizeof(imdir_t*));

        p_dH->p_nnz[i]  = ( ndir_t*) malloc(p_dH->order*sizeof( ndir_t));
        p_dH->p_size[i] = ( ndir_t*) malloc(p_dH->order*sizeof( ndir_t));

        if ( p_dH->p_im[i]  == NULL || p_dH->p_idx[i] == NULL ||
             p_dH->p_ims[i] == NULL || p_dH->p_ids[i] == NULL ||
             p_dH->p_size[i]== NULL || p_dH->p_nnz[i] == NULL   ){
            printf("ERROR: Not enough memory for temporal arrays. Exiting...\n");
            exit(OTI_OutOfMemory);
        }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_load_singl( char* strLocation, ord_t order, bases_t nbasis, ndir_t ntemps, 
    ndir_t allocSize, dhelp_t* p_dH){ 

    p_dH->Nbasis     = nbasis;
    p_dH->Ntmps      = ntemps;
    p_dH->allocSize  = allocSize;

    // Load arrays from files.
    loadnpy_fulldir(   strLocation, order, nbasis, p_dH);
    loadnpy_ndirs(     strLocation, order, nbasis, p_dH);    
    loadnpy_multtabls( strLocation, order, nbasis, p_dH);

    // Load temporals
    dhelp_load_tmps( p_dH );
}
// ----------------------------------------------------------------------------------------------------














// ****************************************************************************************************
void loadnpy(char* filename, void** data, uint8_t* ndim, uint64_t* shape){
    
    uint8_t n_known_types = 5; // Number of known types

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

    char *header;//,holder[1024],one_char='0';
    char magic_read[7];
    // char kwds[3][64]={"'descr':","'fortran_order':","'shape':"};
    char shape_str[1024],fortran_order[1024],descr[1024];
    char descr_tmp[1024],fortran_order_tmp[1024],shape_str_tmp[1024];
    char magic[7] = {0x93,'N','U','M','P','Y','\0'};
    // char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size, data_start=0;
    uint8_t MINOR, MAJOR,flag,dtype;
    char * pt;//, *pt2, *pt3;
    uint64_t shape_tmp,total_nels;
    uint64_t i;
    size_t fread_res=0;
    
    if(filename != NULL ){
        
        cfPtr = fopen( filename, "rb" );

        if (cfPtr != NULL){

            // printf("Successfully opened %s\n",filename);
            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread_res=fread(magic_read, sizeof(char), 6, cfPtr);
            magic_read[6] = '\0';

            if ( strcmp(magic_read,magic) ){ // Checks that the file starts correctly
                
                printf("Error: File is not in NUMPY '.npy' format.\n");
                exit(-1);

            } else {

                // Get the version of the file.
                fread_res=fread(&MAJOR, sizeof(char), 1, cfPtr);
                fread_res=fread(&MINOR, sizeof(char), 1, cfPtr);
                
                // Read header size
                fread_res=fread(&header_size, sizeof(uint16_t), 1, cfPtr);
                
                // Allocate header
                header = (char *)malloc((header_size+1)*sizeof(char));

                if (header == NULL){
                    printf("\nERROR: Not enough memory.\n Exiting\n");
                    exit(-1);
                }
                // Read header
                fread_res=fread(header, sizeof(char), header_size, cfPtr);
                header[header_size] = '\0';

                // printf("%s",header);

                // Data:
                if ((header_size+12)%16!=0){
                    
                    data_start = (1+(header_size+12)/16)*16;

                } else {

                    data_start = header_size+12;

                }
                
                // printf("Here, before pt\n");
                // printf("%s\n",header);
                // Read the header:
                pt = strtok(header,":");
                // Read descr:
                pt = strtok(NULL, ":");
                // printf( " %s\n", pt );
                strcpy(descr_tmp,pt);
                                
                pt = strtok(NULL, ":");
                // printf( " %s\n", pt );
                strcpy(fortran_order_tmp,pt);

                
                pt = strtok(NULL, ":");
                // printf( " %s\n", pt );
                strcpy(shape_str_tmp,pt);
                // printf( " %s\n", shape_str_tmp );

                pt = strtok(NULL, ":"); // Becomes null.


                // printf("%s\n",descr_tmp);
                pt = strtok(descr_tmp,",");
                // printf( " %s\n", pt );
                strcpy(descr,pt);
                // printf("%s\n",descr);
                pt = strtok(NULL, ":");
                pt = strtok(NULL, ":");

                pt = strtok(fortran_order_tmp,",");
                strcpy(fortran_order,pt);
                // printf( " %s\n", pt );
                pt = strtok(NULL, ":");
                pt = strtok(NULL, ":");
                // printf("before strok %s\n",shape_str_tmp);
                pt = strtok(shape_str_tmp,")");
                // printf("after strok %s\n",shape_str_tmp);
                strcpy(descr_tmp,pt); // TODO: Do not overlap
                // printf("after strcpy %s\n",shape_str_tmp);
                while(pt!=NULL){
                    pt = strtok(NULL, ")");
                }
                // printf("after %s\n",shape_str_tmp);

                pt = strtok(descr_tmp,"(");

                // printf("after %s\n",descr_tmp);                
                pt = strtok(NULL, "(");
                // printf("after %s\n",pt);  
                strcpy(shape_str_tmp,pt); // TODO: DO not overlap
                strcpy(shape_str,shape_str_tmp);
                // printf( " %s\n", shape_str );
                pt = strtok(NULL, "(");

                pt = strtok(shape_str_tmp,",");

                total_nels=1;
                *ndim=0;
                while(pt !=NULL){

                    *ndim=*ndim+1;
                    
                    sscanf(pt,_PUINT64T, &shape_tmp);
                    total_nels*=shape_tmp;
                    // printf("The read shape is: %lu\n", shape_tmp);   
                    pt = strtok(NULL,",");

                }

                
                strcpy(shape_str_tmp,shape_str);

                pt = strtok(shape_str_tmp,",");
                
                i=0;
                while(pt !=NULL){
                    
                    sscanf(pt,_PUINT64T, &(shape[i]));
                    pt = strtok(NULL,",");
                    i+=1;

                }

                flag = 0; // Flag for known data
                
                for(i=0;i<n_known_types;i++){
                    
                    if (!strcmp(descr,known_types_char[i])){
                        
                        flag=1;
                        dtype = i;
                        break;

                    }

                }

                if (flag==0){

                    printf("ERROR: Data type %s not supported\n Exiting",descr);
                    exit(-1);

                }
                
                // Allocate pointer of data
                data[0]=malloc(total_nels*known_types_size[dtype]);

                if (data[0]!=NULL){

                    fread_res=fread(data[0], known_types_size[dtype] , total_nels, cfPtr);

                } else {

                    printf("\nERROR: Not enough memory.\n Exiting\n");
                    exit(-1);

                }           

                // Free memory.
                free(header);
                
            }

            fclose(cfPtr);

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }

    }

}
// ----------------------------------------------------------------------------------------------------