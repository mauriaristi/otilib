
#include "read_npy.h"




int main(){

	char* strLocation="/home/maristi7/coding/otilib/build/data/v1.0";
	
	directionHelper2* p_dH=NULL;

	c_helper_load2(strLocation,&p_dH);

	// Do the following.
	
	


	c_helper_free2(&p_dH,10);
	
}/**/


// ----------------------------------------------------------------------------------------------------
// ---------------------------------     HELPER 2 FUNCTIONS  ------------------------------------------
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_loadFulldir( char* strLocation, uint8_t order, uint16_t nbasis, directionHelper2* p_dH){
    /*
    c_loadFulldir( strLocation, order,  nbasis,  dHelp)

    Loads the fulldir array for order "order" and number of basis given in "nbasis" from a file that
    is located at the folder given in strLocation.

    INPUTS:
        -> strLocation: String with the location of the folder that contains the npy file with fulldir.
        
        -> order:    Order to be loaded.
            Example: 3

        ->  nbasis:    Number of basis.
            Example: 10

        ->p_dH:    Adress of the helper to be loaded.

    OUTPUTS:
        -> The result is the direction helper containing the loaded data.
    */ 
    // ************************************************************************************************

    char filename[1000], holder[100];
    uint64_t shape[2]={1,1};
    uint8_t   ndim;
    uint64_t   i,j;

    // Concatenate the filename.
    strcpy(filename,strLocation);
    strcat(filename,"/fulldir_n");
    sprintf(holder, "%hhu", order);
    strcat(filename,holder);
    strcat(filename,"_m");
    sprintf(holder, "%hu", nbasis);
    strcat(filename,holder);
    strcat(filename,".npy");
    

    // Load array.

    load_npy(filename, (void**) &p_dH->p_fulldir, &ndim, shape);
    p_dH->Ndir = shape[0];
    p_dH->order= order;


}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_loadMulttabls( char* strLocation, uint8_t order, uint16_t nbasis, directionHelper2* p_dH){
    /*
    c_loadFulldir( strLocation, order,  nbasis,  dHelp)

    Loads the multtab arrays for order "order" and number of basis given in "nbasis" from the files 
    located at the folder given in strLocation.

    INPUTS:
        -> strLocation: String with the location of the folder that contains the npy file with fulldir.
        
        -> order:    Order to be loaded.
            Example: 3

        ->  nbasis:    Number of basis.
            Example: 10

        ->p_dH:    Adress of the helper to be loaded.

    OUTPUTS:
        -> The result is the direction helper containing the loaded data.
    */ 
    // ************************************************************************************************

    char filename[1000], holder[100];
    uint64_t shape[2]={1,1};
    uint8_t   ndim;
    uint64_t i,j,k;

    // Determine the number of operations.
    p_dH->Nmult = order/2;

    p_dH->p_multtabls = (uint64_t**)malloc(p_dH->Nmult*sizeof(uint64_t*));

    if (p_dH->p_multtabls!=NULL){

        for (k=0;k<p_dH->Nmult;k++){

            // Concatenate the filename.
            strcpy(filename,strLocation);
            strcat(filename,"/multtabl_n");
            sprintf(holder, "%hhu", order);
            strcat(filename,holder);
            strcat(filename,"_m");
            sprintf(holder, "%hu", nbasis);
            strcat(filename,holder);
            strcat(filename,"_");
            sprintf(holder, "%lu", k);
            strcat(filename,holder);
            strcat(filename,".npy");
            

            // Load the numpy array.
            load_npy(filename, (void**) &p_dH->p_multtabls[k], &ndim, shape);

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_loadNdirs( char* strLocation, uint8_t order, uint16_t nbasis, directionHelper2* p_dH){
    /*
    c_loadNdirs( strLocation, order,  nbasis,  dHelp)

    Loads the fulldir array for order "order" and number of basis given in "nbasis" from a file that
    is located at the folder given in strLocation.

    INPUTS:
        -> strLocation: String with the location of the folder that contains the npy file with fulldir.
        
        -> order:    Order to be loaded.
            Example: 3

        ->  nbasis:  Number of basis.
            Example: 10

        ->p_dH:      Adress of the helper to be loaded.

    OUTPUTS:
        -> The result is the direction helper containing the loaded data.
    */ 
    // ************************************************************************************************

    char filename[1000], holder[100];
    uint64_t shape[2]={1,1};
    uint8_t   ndim;

    // Concatenate the filename
    strcpy(filename,strLocation);
    strcat(filename,"/ndirs_n");
    sprintf(holder, "%hhu", order);
    strcat(filename,holder);
    strcat(filename,"_m");
    sprintf(holder, "%hu", nbasis);
    strcat(filename,holder);
    strcat(filename,".npy");
    
    // Load the array.
    load_npy(filename, (void**) &p_dH->p_ndirs, &ndim, shape);    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_loadDirHelper2( char* strLocation, uint8_t order,   uint16_t nbasis, uint8_t nhelps, 
    directionHelper2* p_dH){          
    /*
    c_loadDirHelper2( strLocation, order, nbasis, nhelps, p_dH)

    Loads a direction helper from a set of files within the folder specified in strLocation. 

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  nbasis:    Number of basis directions to load.
            Example: 100

        ->nhelps:   Number of help arrays to be allocated in the array.

        ->p_dH:    Adress of the helper to be loaded.

    OUTPUTS:
        -> The result is the direction helper with the loaded data.
    */ 
    // ************************************************************************************************

    // Initialize known values
    /*
    typedef struct {

        uint16_t*      p_mapder;  // Temporal mapping array.   Shape: (      nn, 2*order)   
        uint8_t*       p_multpl;  // Array to hold multiples.  Shape: ( 2^order,   order)
        double*          p_fder;  // Preallocated array for general function evaluation. size: order+1
        double*         p_coefs;  // Preallocated array for general multiplication coefs. Shape: (Ndir,1)
        uint64_t*        p_indx;  // Preallocated array for general multiplication indx.  Shape: (Ndir,1)
    } directionHelper2;
    */    

    c_loadFulldir(   strLocation, order, nbasis, p_dH);
    c_loadNdirs(     strLocation, order, nbasis, p_dH);
    c_loadMulttabls( strLocation, order, nbasis, p_dH);
       
    // dHelp->p_udirA  = (uint16_t*)malloc(  nhelps*order*sizeof(uint16_t)    ); 
    // dHelp->p_uexpA  = (uint8_t* )malloc(  nhelps*order*sizeof(uint8_t )    ); 
    // dHelp->p_rdirA  = (uint16_t*)malloc(  nhelps*order*sizeof(uint16_t)    ); 
    // dHelp->p_rexpA  = (uint8_t* )malloc(  nhelps*order*sizeof(uint8_t )    ); 
    // dHelp->p_mdirA  = (uint16_t*)malloc(  nhelps*order*sizeof(uint16_t)    ); 
    // dHelp->p_mexpA  = (uint8_t* )malloc(  nhelps*order*sizeof(uint8_t )    ); 
    // dHelp->p_mapder = (uint16_t*)malloc(2*nhelps*order*sizeof(uint16_t)    ); 
    // dHelp->p_multpl = (uint8_t* )malloc( c_fastpow(2,order)*order*sizeof(uint8_t )); 
    // dHelp->p_fder   = (double*  )malloc( (order+1    )*sizeof(double  )    );
    // dHelp->p_coefs  = (double*  )malloc( (dHelp->Ndir)*sizeof(double  )    );
    // dHelp->p_indx   = (uint64_t*)malloc( (dHelp->Ndir)*sizeof(uint64_t)    );

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_helper_load2( char* strLocation, directionHelper2** p_dH){          
    /*
    c_helper_load2(strLocation, p_dH)

    Load a set of 10 helpers from order 1 until order 10 with 10 bases.

    INPUTS:
        
        -> strLocation: Path to the folder that contains the files to load.

    OUTPUTS:
        -> The result is an array of helpers of length = order with the loaded data.

    TODO: Make a reload function that is capable of loading different set of files.
    */ 
    // ************************************************************************************************

    // uint16_t nbases_per_ord[]   = {65535, // ------------------   1 -> Probably not necessary
    //                                 1000, // ------------------   2
    //                                  100, // ------------------   3
    //                                   10, // ------------------   4
    //                                   10, // ------------------   5
    //                                   10, // ------------------   6
    //                                   10, // ------------------   7 
    //                                   10, // ------------------   8
    //                                   10, // ------------------   9
    //                                   10  // ------------------  10
    // };          

    uint8_t nhelpers = 10;               // Number of elements in the ndirs array

    uint16_t nbases_per_ord[]   = {  10, // ------------------   1 
                                     10, // ------------------   3
                                     10, // ------------------   2
                                     10, // ------------------   4
                                     10, // ------------------   5
                                     10, // ------------------   6
                                     10, // ------------------   7 
                                     10, // ------------------   8
                                     10, // ------------------   9
                                     10  // ------------------  10
    };

    uint8_t  nhelps =  3;

    p_dH[0] = (directionHelper2* )malloc(nhelpers*sizeof(directionHelper2));

    if (p_dH == NULL){
      printf("Error. Not enough memory for helper array. Exiting\n");
      exit(-1);
    }
    
    for( int i = 1; i<=nhelpers; i++){
      
      c_loadDirHelper2(strLocation,i,nbases_per_ord[i-1], nhelps, &(*p_dH)[i-1]);

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_freeDirHelper2(  directionHelper2* p_dH){          
    /*
    freeDirHelper( p_dH)

    Frees all arrays in dHelp struct.

    INPUTS:
        
        -> p_dH:  Allocated direction helper.
    */ 
    // ************************************************************************************************
    
    uint64_t i;
    // printf("1\n");
    // Initialize known values
    if (p_dH->p_fulldir != NULL){
        free(p_dH->p_fulldir);
    }
    // printf("2\n");
    if (p_dH->p_ndirs != NULL){
        free(p_dH->p_ndirs);
    }
    // printf("3\n");
    if (p_dH->p_multtabls != NULL){

        for (i=0;i<p_dH->Nmult;i++){

            free(p_dH->p_multtabls[i]);

        }

        free(p_dH->p_multtabls);
    }    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_helper_free2(directionHelper2** p_dH, uint8_t nhelpers ){          
    /*
    void c_helper_free2(directionHelper* p_dH , uint8_t maxorder )

    Free all helpers that where loaded.

    INPUTS:
        -> p_dH:        Array of helpers
            Example: 3

    OUTPUTS:
        -> The result is an array of helpers of length = order with the loaded data.
    */ 
    // ************************************************************************************************

    
    
    for( int i = 1; i<=nhelpers; i++){
      // printf("freeing %d\n",i );
      c_freeDirHelper2(&(*p_dH)[i-1]);
    }

    free(*p_dH);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void load_npy(char* filename, void** data, uint8_t* ndim, uint64_t* shape){
    /*
    load_npy( order,  ndir)

    Loads a '.npy' array to C format.

    INPUTS:
        
        -> filename:    Filename of the file to load. Must contain the path.
            
        ->     data:    Address of the pointer that will hold the data. Will be allocated in this function.

        ->     ndim:    Number of dimensions of the array.

        ->    shape:    Address to the pointer that will hold the array.

    OUTPUTS:
        -> The result is the direction array pointer with the loaded data.
    */ 
    // ************************************************************************************************
    
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

    char holder[1024], *header,one_char='0';
    char magic_read[7];
    char kwds[3][64]={"'descr':","'fortran_order':","'shape':"};
    char descr[1024],fortran_order[1024],shape_str[1024];
    char descr_tmp[1024],fortran_order_tmp[1024],shape_str_tmp[1024];
    char magic[7] = {0x93,'N','U','M','P','Y','\0'};
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size, data_start;
    uint8_t MINOR, MAJOR,flag,dtype;
    char * pt, *pt2, *pt3;
    uint64_t shape_tmp,total_nels;
    uint64_t i;
    
    if(filename != NULL ){
        
        cfPtr = fopen( filename, "rb" );

        if (cfPtr != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread(magic_read, sizeof(char), 6, cfPtr);
            magic_read[6] = '\0';

            if ( strcmp(magic_read,magic) ){ // Checks that the file starts correctly
                
                printf("Error: File is not in NUMPY '.npy' format.\n");
                exit(-1);

            } else {

                // Get the version of the file.
                fread(&MAJOR, sizeof(char), 1, cfPtr);
                fread(&MINOR, sizeof(char), 1, cfPtr);
                
                // Read header size
                fread(&header_size, sizeof(uint16_t), 1, cfPtr);
                
                // Allocate header
                header = (char *)malloc((header_size+1)*sizeof(char));

                if (header == NULL){
                    printf("\nERROR: Not enough memory.\n Exiting\n");
                    exit(-1);
                }
                // Read header
                fread(header, sizeof(char), header_size, cfPtr);
                header[header_size] = '\0';

                // printf("%s",header);

                // Data:
                if ((header_size+12)%16!=0){
                    
                    data_start = (1+(header_size+12)/16)*16;

                } else {

                    data_start = header_size+12;

                }
                
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

                pt = strtok(NULL, ":"); // Becomes null.

                pt = strtok(descr_tmp,",");
                // printf( " %s\n", pt );
                strcpy(descr,pt);
                pt = strtok(NULL, ":");
                pt = strtok(NULL, ":");

                pt = strtok(fortran_order_tmp,",");
                strcpy(fortran_order,pt);
                // printf( " %s\n", pt );
                pt = strtok(NULL, ":");
                pt = strtok(NULL, ":");

                pt = strtok(shape_str_tmp,")");
                strcpy(shape_str_tmp,pt);
                while(pt!=NULL){
                    pt = strtok(NULL, ")");
                }
                pt = strtok(shape_str_tmp,"(");
                pt = strtok(NULL, "(");
                strcpy(shape_str_tmp,pt);
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

                    fread(data[0], known_types_size[dtype] , total_nels, cfPtr);

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
// -------------------------------     END HELPER 2 FUNCTIONS   ---------------------------------------
// ----------------------------------------------------------------------------------------------------