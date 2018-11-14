// This is a file to read numpy arrays.
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


typedef struct {
    uint16_t*     p_fulldir;  // 2D Array with explicit                     Shape: (    Ndir,   order)
    uint64_t**  p_multtabls;  // 1D Array of 2D multiplication tables       Shape: (       1,   Nmult)
    uint64_t*       p_ndirs;  // 1D Array with the Ndir given a m <= Nbases Shape: (       1,  Nbasis)
    uint16_t*       p_mdirA;  // Temporal direction array. Shape: (      nn,   order) -> nn: number of 
    uint8_t*        p_mexpA;  // Temporal exponent array.  Shape: (      nn,   order)        temp els
    uint16_t*      p_mapder;  // Temporal mapping array.   Shape: (      nn, 2*order)   
    uint8_t*       p_multpl;  // Array to hold multiples.  Shape: ( 2^order,   order)
    double*          p_fder;  // Preallocated array for general function evaluation. size: order+1
    double*         p_coefs;  // Preallocated array for general multiplication coefs. Shape: (Ndir,1)
    uint64_t*        p_indx;  // Preallocated array for general multiplication indx.  Shape: (Ndir,1)
    uint64_t           Ndir;  // Number of directions in the helper..
    uint64_t          Nmult;  // Number of multiplication tables.
    uint16_t         Nbasis;  // Maximum number of basis in the helper.
    uint8_t           order;  // Order of all directions in this set. 

} directionHelper2;




typedef struct {
    void*        p_data;  // Pointer with the data.
    uint64_t*   p_shape;  // Shape of the array
    uint64_t       size;  // Number of elements in p_data
    uint8_t        ndim;  // Number of dimensions.
    uint8_t       order;  // Fortran or C order.
    uint8_t       dtype;  // Integer rlated with the data type 
} nparray_t;

const uint8_t n_known_types=5;
char known_types_char[5][76]={
	" '|u1'", // uint8_t // '<u2': Little endian, unsigned int, 2 bytes
	" '<u1'", // uint8_t
	" '<u2'", // uint16_t 
	" '<u4'", // uint32_t
	" '<u8'", // uint64_t
};

uint8_t known_types_size[5]={
	sizeof(uint8_t), // uint8_t
	sizeof(uint8_t), // uint8_t
	sizeof(uint16_t), // uint16_t
	sizeof(uint32_t), // uint32_t
	sizeof(uint64_t), // uint64_t
};


void load_npy(char* filename, void** data, uint8_t* ndim, uint64_t* shape);
void c_loadDirHelper2( char* strLocation, uint8_t order,   uint16_t nbasis, uint8_t nhelps, 
    directionHelper2* dHelp);
// void load_npy(char* filename, void** data, uint8_t* ndim, uint64_t** shape);
// void load_npy_struct(char* filename, nparray_t array);



int main(){

	char* filename = "test.npy";
	char* strLocation="/home/maristi7/coding/otilib/build/data/v1.0";
	uint8_t   ndim,i,j ;
	uint64_t shape[2]={0,0};  // Join in a structure.
	uint16_t* data;
	directionHelper2 dHelp;



	load_npy(filename,(void**)&data, &ndim, shape);
	// load_npy_struct(filename,(void**)&data, &ndim, &shape);
	printf("ndim: %hhu; shape: (%lu,%lu)\n",ndim,shape[0],shape[1]);
	printf("data: \n");
	for(i=0;i<shape[0];i++){
		for(j=0;j<shape[1];j++){
			printf("%5hu,",data[i*shape[1]+j]);
		}
		printf("\n");
	}
	printf("\n");

	free(data);

	c_loadDirHelper2( strLocation, 3,   10, 3, &dHelp);

	// free(shape);
	
}/**/

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
    uint64_t i,j;


    strcpy(filename,strLocation);
    strcat(filename,"/fulldir_n");
    sprintf(holder, "%hhu", order);
    strcat(filename,holder);
    strcat(filename,"_m");
    sprintf(holder, "%hu", nbasis);
    strcat(filename,holder);
    strcat(filename,".npy");
    // Load Fulldir.

    printf("%s\n",filename);
    load_npy(filename, (void**) &p_dH->p_fulldir, &ndim, shape);
    p_dH->Ndir = shape[0];
    p_dH->order= order;

    printf("ndim: %hhu; shape: (%lu,%lu)\n",ndim, shape[0], shape[1]);
	printf("p_fulldir: \n");
	for(i=0;i<shape[0];i++){
		for(j=0;j<shape[1];j++){
			printf("%5hu,",p_dH->p_fulldir[i*shape[1]+j]);
		}
		printf("\n");
	}
	printf("\n");


}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_loadMulttabls( char* strLocation, uint8_t order, uint16_t nbasis, directionHelper2* p_dH){
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
    uint64_t i,j,k;

    p_dH->Nmult = order/2;
    printf("Number of multtabls: %hhu\n",p_dH->Nmult);

    p_dH->p_multtabls = (uint64_t**)malloc(p_dH->Nmult*sizeof(uint64_t*));
    if (p_dH->p_multtabls!=NULL){

	    for (k=0;k<p_dH->Nmult;k++){

			strcpy(filename,strLocation);
		    strcat(filename,"/fulldir_n");
		    sprintf(holder, "%hhu", order);
		    strcat(filename,holder);
		    strcat(filename,"_m");
		    sprintf(holder, "%hu", nbasis);
		    strcat(filename,holder);
		    strcat(filename,".npy");
		    

		    printf("%s\n",filename);
		    load_npy(filename, (void**) &p_dH->p_multtabls[k], &ndim, shape);
		    // p_dH->Ndir = shape[0];
		    // p_dH->order= order;

		    printf("ndim: %hhu; shape: (%lu,%lu)\n",ndim, shape[0], shape[1]);
			printf("p_fulldir: \n");
			for(i=0;i<shape[0];i++){
				for(j=0;j<shape[1];j++){
					printf("%5lu,",p_dH->p_multtabls[k][i*shape[1]+j]);
				}
				printf("\n");
			}
			printf("\n");

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
    uint64_t i,j;


    strcpy(filename,strLocation);
    strcat(filename,"/ndirs_n");
    sprintf(holder, "%hhu", order);
    strcat(filename,holder);
    strcat(filename,"_m");
    sprintf(holder, "%hu", nbasis);
    strcat(filename,holder);
    strcat(filename,".npy");
    

    // printf("%s\n",filename);
    load_npy(filename, (void**) &p_dH->p_ndirs, &ndim, shape);
    // p_dH->Ndir = shape[0];
    // p_dH->order= order;

    printf("ndim: %hhu; shape: (%lu,%lu)\n",ndim, shape[0], shape[1]);
	printf("p_ndirs: \n");
	for(i=0;i<shape[0];i++){
		for(j=0;j<shape[1];j++){
			printf("%5lu,",p_dH->p_ndirs[i*shape[1]+j]);
		}
		printf("\n");
	}
	printf("\n");

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_loadDirHelper2( char* strLocation, uint8_t order,   uint16_t nbasis, uint8_t nhelps, 
    directionHelper2* p_dH){          
    /*
    loadDirHelper( order,  ndir,  p_dH)

    Loads a direction helper from a file.Applies the binary search to find what is the position at which the 
    pair dirs,exps exist on an array of size N that contains it.

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
        
        uint64_t**  p_multtabls;  // 1D Array of 2D multiplication tables       Shape: (       1,   Nmult)
        uint16_t*       p_ndirs;  // 1D Array with the Ndir given a m <= Nbases Shape: (       1,  Nbasis)
        uint16_t*       p_mdirA;  // Temporal direction array. Shape: (      nn,   order) -> nn: number of 
        uint8_t*        p_mexpA;  // Temporal exponent array.  Shape: (      nn,   order)        temp els
        uint16_t*      p_mapder;  // Temporal mapping array.   Shape: (      nn, 2*order)   
        uint8_t*       p_multpl;  // Array to hold multiples.  Shape: ( 2^order,   order)
        double*          p_fder;  // Preallocated array for general function evaluation. size: order+1
        double*         p_coefs;  // Preallocated array for general multiplication coefs. Shape: (Ndir,1)
        uint64_t*        p_indx;  // Preallocated array for general multiplication indx.  Shape: (Ndir,1)
        uint64_t           Ndir;  // Number of directions in the helper..
        uint64_t          Nmult;  // Number of multiplication tables.
        
        
    } directionHelper2;
    */

    char filename[1000], holder[100];
    uint64_t shape[2];
    uint8_t   ndim;
    uint64_t i,j;

    

	c_loadFulldir( strLocation, order, nbasis, p_dH);
	c_loadNdirs( strLocation, order, nbasis, p_dH);
    free(p_dH->p_fulldir);
    free(p_dH->p_ndirs);

    // Load ndirs.
    
    // // Load multtabls.
    

    // c_loadDirA( strLocation, order, nbasis, &dHelp->p_dirA, &dHelp->Ndir  );
    // c_loadExpA( strLocation, order, nbasis, &dHelp->p_expA, &dHelp->Ndir  );
    // c_loadParts(strLocation, order, nbasis, &dHelp->p_part, &dHelp->Npart );
    // c_loadCount(strLocation, order, nbasis, &dHelp->p_countOTI);
    // c_loadMult( strLocation, order, nbasis, &dHelp->p_multRes, &dHelp->p_multInd, &dHelp->Nmult);

    // dHelp->Nbasis = nbasis;
    // dHelp->order  =  order;
    // dHelp->nn     = nhelps;
    
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
    

    


    // Malloc memory for strings:
    // holder        = (char *)malloc(256*sizeof(char));
    // holderSmall   = (char *)malloc(16*sizeof(char));
    
    if(filename != NULL ){
        
// #ifdef VERB // Indicator of verbosity from compiler.
        // printf("Loading Filename: %s\n", filename);
// #endif	
        cfPtr = fopen( filename, "rb" );

        if (cfPtr != NULL){

        	// printf("Successfully loaded: \"%s\"\n", filename);

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
	            // printf("Version of the file is %hhu.%hhu \n",MAJOR,MINOR);

	            // Read header size
	            fread(&header_size, sizeof(uint16_t), 1, cfPtr);
	            // printf("The header size is %hu bytes.\n",header_size);


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
	            
				// printf("Data starts at %hu\n",data_start);

				
				// Read the header:
				

				pt = strtok(header,":");
				// Read descr:
				pt = strtok(NULL, ":");
				// printf( " %s\n", pt );
				strcpy(descr_tmp,pt);
				// while( pt != NULL ) { // Reset pt.
				
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
			    //*shape = (uint64_t*)malloc((*ndim)*sizeof(uint64_t));
			    i=0;
			    while(pt !=NULL){
			    	
			    	// sscanf(pt,"%lu", &((*shape)[i]));
			    	sscanf(pt,"%lu", &(shape[i]));
				    pt = strtok(NULL,",");
				    i+=1;
			    }				

				// printf("Descr:%s\n",descr);
				// printf("Number of dimensions: %hhu\n",*ndim);
				// printf("Number of elements: %lu\n",total_nels);
				// printf("shape: (");
				// for (i=0;i<*ndim;i++){
				// 	printf(" %lu,",(*shape)[i]);
				// }
				// printf(")\n");
				// printf("fortran_order: %s\n",fortran_order);



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
				// determine data

				// printf("dtype: %hhu\n",dtype);
				// printf("nbytes of dtype: %hhu\n",known_types_size[dtype]);
				// printf("nbytes of dtype: %lu\n",total_nels*known_types_size[dtype]);

				
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


            






            // sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
//                 holderSmall, holderSmall, &shapex, &shapey);

// #ifdef VERB // Indicator of verbosity from compiler.
//             printf("shape: %llu, %llu \n",shapex,shapey);
// #endif
//             Ndir[0] = shapex;
//             shapex *= shapey;
            
//             // Allocate memory
            
//             dirA[0] = (uint16_t* )malloc(shapex*sizeof(uint16_t));

//             if (dirA[0] != NULL){

//                 fread(dirA[0], sizeof(uint16_t), shapex, cfPtr);

//             }else{

//                 printf("\nERROR: Not enough memory for direction array.\n Exiting\n");
//                 exit(-1);

//             }

// #ifdef VERB // Indicator of verbosity from compiler.
//             printf("Successfully loaded \" %s \" file.\n",filename);
// #endif
			fclose(cfPtr);
        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }



        


        // free memory
        // free(holder); 
        // free(holderSmall); 
    }
}
// ----------------------------------------------------------------------------------------------------



// // ****************************************************************************************************
// void load_npy_struct(char* filename, nparray_t* array){
//     /*
//     load_npy_struct( order,  ndir)

//     Loads a '.npy' array to C format.

//     INPUTS:
        
//         -> filename:    Filename of the file to load. Must contain the path.
            
//         ->     data:    Address of the array to be written (and allocated).

//     OUTPUTS:
//         -> The result is the direction array pointer with the loaded data.
//     */ 
//     // ************************************************************************************************

    
    
//     char holder[1024], *header,one_char='0';
//     char magic_read[7];
//     char kwds[3][64]={"'descr':","'fortran_order':","'shape':"};
//     char descr[1024],fortran_order[1024],shape_str[1024];
//     char descr_tmp[1024],fortran_order_tmp[1024],shape_str_tmp[1024];
//     char magic[7] = {0x93,'N','U','M','P','Y','\0'};
//     char *holderSmall;
//     FILE *cfPtr = NULL; //  file pointer
//     uint16_t header_size, data_start;
//     uint8_t MINOR, MAJOR,flag,dtype;
//     char * pt, *pt2, *pt3;
//     uint64_t shape_tmp,total_nels;
//     uint64_t i;
    

//     if(filename != NULL ){
        

//         // printf("Loading Filename: %s\n", filename);

//         cfPtr = fopen( filename, "rb" );

//         if (cfPtr != NULL){

//         	// printf("Successfully loaded: \"%s\"\n", filename);

//             // Read the first 8 bytes of the file:
//             // expected: ?NUMPYab     a,b is the version of the filename
//             fread(magic_read, sizeof(char), 6, cfPtr);
//             magic_read[6] = '\0';

//             if ( strcmp(magic_read,magic) ){ // Checks that the file starts correctly
            	
//             	printf("Error: File is not in NUMPY '.npy' format.\n");
//             	exit(-1);

//             } else {

//             	// Get the version of the file.
//             	fread(&MAJOR, sizeof(char), 1, cfPtr);
//             	fread(&MINOR, sizeof(char), 1, cfPtr);
// 	            // printf("Version of the file is %hhu.%hhu \n",MAJOR,MINOR);

// 	            // Read header size
// 	            fread(&header_size, sizeof(uint16_t), 1, cfPtr);
// 	            // printf("The header size is %hu bytes.\n",header_size);


// 	            // Allocate header
// 	            header = (char *)malloc((header_size+1)*sizeof(char));

// 	            if (header == NULL){
// 	            	printf("\nERROR: Not enough memory.\n Exiting\n");
// 	                exit(-1);
// 	            }
// 	            // Read header
// 	            fread(header, sizeof(char), header_size, cfPtr);
// 	            header[header_size] = '\0';

// 	            // printf("%s",header);

// 	            // Data:
// 	            if ((header_size+12)%16!=0){
// 	            	data_start = (1+(header_size+12)/16)*16;
// 	            } else {
// 	            	data_start = header_size+12;

// 	            }
	            
// 				// printf("Data starts at %hu\n",data_start);

				
// 				// Read the header:
				

// 				pt = strtok(header,":");
// 				// Read descr:
// 				pt = strtok(NULL, ":");
// 				// printf( " %s\n", pt );
// 				strcpy(descr_tmp,pt);
// 				// while( pt != NULL ) { // Reset pt.
				
// 			    pt = strtok(NULL, ":");
// 			    // printf( " %s\n", pt );
// 			    strcpy(fortran_order_tmp,pt);

			    
// 			    pt = strtok(NULL, ":");
// 			    // printf( " %s\n", pt );
// 			    strcpy(shape_str_tmp,pt);

// 			    pt = strtok(NULL, ":"); // Becomes null.










// 			    pt = strtok(descr_tmp,",");
// 				// printf( " %s\n", pt );
// 				strcpy(descr,pt);
// 			    pt = strtok(NULL, ":");
// 			    pt = strtok(NULL, ":");


// 			    pt = strtok(fortran_order_tmp,",");
// 			    strcpy(fortran_order,pt);
// 			    // printf( " %s\n", pt );
// 			    pt = strtok(NULL, ":");
// 			    pt = strtok(NULL, ":");

// 			    pt = strtok(shape_str_tmp,")");
// 			    strcpy(shape_str_tmp,pt);
// 			    while(pt!=NULL){
// 			    	pt = strtok(NULL, ")");
// 			    }
// 			    pt = strtok(shape_str_tmp,"(");
// 			    pt = strtok(NULL, "(");
// 			    strcpy(shape_str_tmp,pt);
// 			    strcpy(shape_str,shape_str_tmp);
// 			    // printf( " %s\n", shape_str );
// 			    pt = strtok(NULL, "(");

// 			    pt = strtok(shape_str_tmp,",");

// 			    total_nels=1;
// 			    *ndim=0;
// 			    while(pt !=NULL){
// 			    	*ndim=*ndim+1;
			    	
// 			    	sscanf(pt,"%lu", &shape_tmp);
// 			    	total_nels*=shape_tmp;
// 				    // printf("The read shape is: %lu\n", shape_tmp);	
// 				    pt = strtok(NULL,",");
// 			    }

			    
// 			    strcpy(shape_str_tmp,shape_str);

// 			    pt = strtok(shape_str_tmp,",");
// 			    *shape = (uint64_t*)malloc((*ndim)*sizeof(uint64_t));
// 			    i=0;
// 			    while(pt !=NULL){
			    	
// 			    	sscanf(pt,"%lu", &((*shape)[i]));
// 				    pt = strtok(NULL,",");
// 				    i+=1;
// 			    }				

// 				// printf("Descr:%s\n",descr);
// 				// printf("Number of dimensions: %hhu\n",*ndim);
// 				// printf("Number of elements: %lu\n",total_nels);
// 				// printf("shape: (");
// 				// for (i=0;i<*ndim;i++){
// 				// 	printf(" %lu,",(*shape)[i]);
// 				// }
// 				// printf(")\n");
// 				// printf("fortran_order: %s\n",fortran_order);



// 				flag = 0; // Flag for known data
				
// 				for(i=0;i<n_known_types;i++){
// 					if (!strcmp(descr,known_types_char[i])){
// 						flag=1;
// 						dtype = i;
// 						break;
// 					}
// 				}

// 				if (flag==0){
// 					printf("ERROR: Data type %s not supported\n Exiting",descr);
// 					exit(-1);
// 				}
// 				// determine data

// 				// printf("dtype: %hhu\n",dtype);
// 				// printf("nbytes of dtype: %hhu\n",known_types_size[dtype]);
// 				// printf("nbytes of dtype: %lu\n",total_nels*known_types_size[dtype]);

				
// 				// Allocate pointer of data
// 				data[0]=malloc(total_nels*known_types_size[dtype]);
// 				if (data[0]!=NULL){
// 					fread(data[0], known_types_size[dtype] , total_nels, cfPtr);
// 				} else {
// 					printf("\nERROR: Not enough memory.\n Exiting\n");
// 					exit(-1);
// 				}			

// 				// Free memory.
// 				free(header);
				

//             }

// 			fclose(cfPtr);

//         }else{

//             printf("Error. No file \" %s \"found.\n",filename);
//             exit(-1);    // Exit program

//         }



        


        
//     }
// }
// // ----------------------------------------------------------------------------------------------------



