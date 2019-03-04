#include "oti/core.h"

 

// ----------------------------------------------------------------------------------------------------
// ---------------------------------------  ARRAY FUNCTIONS  ------------------------------------------
// ----------------------------------------------------------------------------------------------------

// Get the element (i,j) from a given C array.
inline uint8_t array2d_getel_ui8_t(uint8_t* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}

inline uint16_t array2d_getel_ui16_t(uint16_t* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}

inline uint32_t array2d_getel_ui32_t(uint32_t* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}

inline uint64_t array2d_getel_ui64_t(uint64_t* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}

inline double array2d_getel_f64_t(double* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}

inline float array2d_getel_f32_t(float* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}

// ----------------------------------------------------------------------------------------------------
// ---------------------------------    END ARRAY FUNCTIONS  ------------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ---------------------------------     DHELP FUNCTIONS  ---------------------------------------------
// ----------------------------------------------------------------------------------------------------




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
            sprintf(holder, "%lu", k);
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

    for (ndir_t i = 0; i<p_dH->Ntmps; i++){

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
void dhelp_dense_mult(coeff_t* p_im1, ndir_t ndir1, ord_t ord1, // Input 1
                      coeff_t* p_im2, ndir_t ndir2, ord_t ord2, // Input 2
                      coeff_t* p_imres, ndir_t ndirres,         // Result
                      dhelpl_t dhl){                            // Helper
    
    imdir2d_t tmp_multtabl ;
    ndir_t ndir_i1, ndir_i2;
    coeff_t* p_dir1;
    coeff_t* p_dir2;
        
    if (ord1<ord2){
    
        tmp_multtabl = dhl.p_dh[ord1+ord2-1].p_multtabls[ord1-1];
        ndir_i1 = ndir1; ndir_i2 = ndir2;
        p_dir1 = p_im1;
        p_dir2 = p_im2;

    } else {

        tmp_multtabl = dhl.p_dh[ord1+ord2-1].p_multtabls[ord2-1];
        ndir_i1 = ndir2; ndir_i2 = ndir1;
        p_dir1 = p_im2;
        p_dir2 = p_im1;
    }

    for (imdir_t i =0; i<ndir_i1; i++){

        for (imdir_t j =0; j<ndir_i2; j++){
        
            imdir_t imdir_res = 
                array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],i,j);

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

    if (ndir1 == ndirres){
        
        for (ndir_t i =0; i<ndir1; i++){
            
            p_imres[i] +=  a*p_im1[i] ;

        }

    } else {

        printf("Error: Multiplication to elements of different sizes not yet implemented\n");
        exit(OTI_NotImplemented);
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_imdir2str(imdir_t imdir, ord_t ord, dhelpl_t* dhl, char* str){          
    
    

    //TODO: Check for inconsistencies.
    
    

    // Get the 
        
    for (int i=0; i<ord; i++){
        sprintf(str,"%hu,",dhl->p_dh[ord].p_fulldir[ord*(imdir-1)+i]);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_load( char* strLocation, dhelpl_t* dhl){          
    
    // TODO: Make a reload function that is capable of loading different set of files.
    // TODO: Add a default configuration file that indicates the number of elements to be loaded
    
    dhl->ndh = 10;               // Number of elements in the ndirs array

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
                              10  // ------------------  10
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
                                0  // ------------------  10
    };

    dhl->p_dh = (dhelp_t* )malloc(dhl->ndh*sizeof(dhelp_t));

    if (dhl->p_dh == NULL){

      printf("ERROR: Not enough memory for helper array. Exiting...\n");
      exit(OTI_OutOfMemory);

    }

    ndir_t  ntmps =  5; // Number of arrays for temporal variables.
    
    for( int i = 1; i<=dhl->ndh; i++){
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
inline int64_t dhelp_comb(int64_t a, int64_t b){
    
    int64_t niter = a - MAX(a-b,b);
    int64_t num = 1, den=1;

    for(int64_t i = 0; i<niter; i++){

        den = den * (i+1) ;
        num = num * (a-i) ;

    }

    return num/den;

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
ndir_t dhelp_extract_ndirTotal(bases_t nbases, ord_t order, dhelpl_t dhl){

    ndir_t ndir_total = 1;

    for(ord_t ord = 1; ord <= order; ord++){

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
void dhelp_printImdir(imdir_t indx, ord_t order, dhelpl_t dhl){          

    printf("e(");
    for(ord_t i = 0; i<order; i++){
        
        printf(_PBASEST ",", array2d_getel_ui16_t(dhl.p_dh[order-1].p_fulldir, order, indx, i));

    }
    printf("\b)");

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_printList(const dhelpl_t dhl){          
    
    for(int i =0; i<dhl.ndh; i++){

        dhelp_print( &dhl.p_dh[i] );

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
    
    for( int i = 1; i<=dhl->ndh; i++){
      // printf("Order: "_PORDT"\n",i);
      dhelp_freeItem( &dhl->p_dh[i-1] );

    }

    // Free the list 
    free(dhl->p_dh);
    dhl->p_dh = NULL;

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
    char descr[1024],fortran_order[1024],shape_str[1024];
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
                    
                    sscanf(pt,"%lu", &shape_tmp);
                    total_nels*=shape_tmp;
                    // printf("The read shape is: %lu\n", shape_tmp);   
                    pt = strtok(NULL,",");

                }

                
                strcpy(shape_str_tmp,shape_str);

                pt = strtok(shape_str_tmp,",");
                
                i=0;
                while(pt !=NULL){
                    
                    sscanf(pt,"%lu", &(shape[i]));
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


// ****************************************************************************************************
void savenpy(char* filename, uint8_t dtype, void* data, uint64_t shapex, 
    uint64_t shapey){
    
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

    char header[65536], header_body[65536];
    char magic[7] = {0x93,'N','U','M','P','Y','\0'}; // Magic keyword
    char version[3] = {1,0,'\0'}; // Only V1.0 supported for now.
    char descr[1024],fortran_order[1024],shape_str[1024];

    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size, heade_len_factor;
    short unsigned int size_2_print;
    uint64_t i, size_of_data=1,wrote;
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
    ndir_t ndirs_o1, ndirs_o2, idx1, idx2,idxres,i=0;
    // Define the number of multiplication tables 
    ord_t n_multtabls = order / 2, o1, o2,j ;
    bases_t* dirs1;
    bases_t* dirs2;
    
    dhl->p_dh[order-1].Nmult = n_multtabls;
    dhl->p_dh[order-1].p_multtabls = (imdir2d_t*)malloc( n_multtabls*sizeof(imdir2d_t) );
    
    if (dhl->p_dh[order-1].p_multtabls==NULL){
        
        printf("ERROR: Not enough memory for ndirs array. Exiting...\n");
        exit(OTI_OutOfMemory);

    }


    for(ord_t table = 0; table<n_multtabls; table++ ){

        o1 = table+1;
        o2 = order-table-1;

        printf("    Multiplication table %hhu\n",o1);
        printf("       order %hhu X %hhu\n",o1,o2);

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
                printf("\b] iter %lu/%lu \n ",idx1*ndirs_o2+1,ndirs_o1*ndirs_o2);
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
void dhelp_precompute(char* directory, bases_t* max_basis_k, ord_t maxorder ){

    dhelpl_t dhl;
    // char fullpathname[1024];
    // char filename[1024], holder[1024];

    dhl.p_dh = (dhelp_t* )malloc( maxorder * sizeof(dhelp_t) );

    if (dhl.p_dh == NULL){

      printf("ERROR: Not enough memory for helper array. Exiting...\n");
      exit(OTI_OutOfMemory);

    }
    for (ord_t order = 1; order<=maxorder; order++){
        

        
        // ndirs
        printf("\n\n---------------------------------------------------\n");
        printf("Precomputing data for order %hu.\n",order);
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
    
    for (ord_t order = 1; order<=maxorder; order++){
        free(dhl.p_dh[order-1].p_fulldir);
        free(dhl.p_dh[order-1].p_ndirs);
        
        for (ord_t ntabls = 0; ntabls < dhl.p_dh[order-1].Nmult; ntabls++){
            free(dhl.p_dh[order-1].p_multtabls[ntabls].p_arr);  
        }
        free(dhl.p_dh[order-1].p_multtabls);    
    }
    free(dhl.p_dh); 
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
    imdir_t idx_res;

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


// ****************************************************************************************************
void dhelp_sparse_sub_dirs(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
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

                p_imres[jres] = p_im1[j1];
                p_idxres[jres] = dir1;
                jres++; j1++;

            } else {

                p_imres[jres]  = p_im2[j2];
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

                p_imres[jres]  = p_im2[j2];
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
void dhelp_sparse_mult(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1, // Input 1
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2, // Input 2
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       dhelpl_t dhl){                            // Helper


    ord_t     tmp_ord      = ord1 + ord2;
    imdir2d_t tmp_multtabl ;

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
        for (ndir_t i = 0; i<ndirmin; i++){

            for (ndir_t j = 0; j<ndirmax; j++){

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
void dhelp_sparse_mult_real( coeff_t val,
                       coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,         
                       dhelpl_t dhl){                            // Helper

    (*ndirres) = ndir1;

    for (ndir_t i = 0; i<ndir1; i++){

        p_imres[i]  = val*p_im1[i];
        p_idxres[i] = p_idx1[i];

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void dhelp_sparse_copy(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1,
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       dhelpl_t dhl){                            // Helper

    memcpy(p_imres,  p_im1,  ndir1*sizeof(coeff_t) );
    memcpy(p_idxres, p_idx1, ndir1*sizeof(imdir_t) );

    (*ndirres) = ndir1;

}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// --------------------------------     END DHELP FUNCTIONS   -----------------------------------------
// ----------------------------------------------------------------------------------------------------







// ****************************************************************************************************
uint64_t binSearchUI64( uint64_t elem,  uint64_t* p_arr, uint64_t  size,flag_t* flag){          
    
    uint64_t min_i = 0;
    uint64_t max_i = size;
    uint64_t pos = min_i+(max_i-min_i)/2; // Automatically truncates the result.
    *flag = 0;
    
    // Case length 0.
    if(min_i==max_i){
        
        return 0;

    }
    
    // Case when the element is not contained within the array or it is the first element.
    if (elem <= p_arr[min_i]){
        
        if (elem == p_arr[min_i]){

            *flag = 1;

        }
        
        return min_i;

    } else if (elem > p_arr[max_i-1]){
        
        return max_i;

    }

    

    
    while(  (max_i-min_i)>2  ){

        
        if (elem > p_arr[pos]){

            min_i = pos;

        }else{

            max_i = pos+1;

        }
        // Convert both arrays to 

        pos = min_i+(max_i-min_i)/2 ;

    }

    if (p_arr[pos] == elem){

        *flag = 1;

    }

    return pos;


}
// ----------------------------------------------------------------------------------------------------