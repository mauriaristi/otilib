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
    p_dH->p_im = (coeff_t**) malloc(p_dH->Ntmps*sizeof(coeff_t*));
    p_dH->p_idx= (imdir_t**) malloc(p_dH->Ntmps*sizeof(imdir_t*));

    if ( p_dH->p_im == NULL || p_dH->p_idx == NULL ){

      printf("ERROR: Not enough memory for temporal arrays. Exiting...\n");
      exit(OTI_OutOfMemory);

    }

    for (ndir_t i = 0; i<p_dH->Ntmps; i++){

        p_dH->p_im[i] = (coeff_t*) malloc(p_dH->Ndir*sizeof(coeff_t));
        p_dH->p_idx[i]= (imdir_t*) malloc(p_dH->Ndir*sizeof(imdir_t));

        if ( p_dH->p_im == NULL || p_dH->p_idx == NULL ){
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

    ndir_t  ntmps =  3; // Number of arrays for temporal variables.
    
    for( int i = 1; i<=dhl->ndh; i++){
      // printf("Loading dhelp %d\n",i);
      dhelp_load_singl(strLocation, i, nbases_ord[i-1], ntmps,allocSzs_ord[i-1], &(dhl->p_dh[i-1]));

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void dhelp_freeItem(  dhelp_t* p_dH){          
    
    uint64_t i;
    
    // Initialize known values
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