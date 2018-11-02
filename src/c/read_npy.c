// This is a file to read numpy arrays.
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


void load_npy(char* filename, void** data, uint8_t* ndim, uint64_t** shape);
void load_npy_struct(char* filename, nparray_t array);


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

int main(){

	char* filename = "test.npy";
	uint8_t   ndim,i,j ;
	uint64_t* shape;  // Join in a structure.
	uint16_t* data;
	nparray_t array;
	load_npy(filename,(void**)&data, &ndim, &shape);
	load_npy_struct(filename,(void**)&data, &ndim, &shape);

	printf("data: \n");
	for(i=0;i<shape[0];i++){
		for(j=0;j<shape[1];j++){
			printf("%5hu,",data[i*shape[1]+j]);
		}
		printf("\n");
	}
	printf("\n");

	free(shape);
	free(data);
}/**/








// ****************************************************************************************************
void load_npy(char* filename, void** data, uint8_t* ndim, uint64_t** shape){
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
			    *shape = (uint64_t*)malloc((*ndim)*sizeof(uint64_t));
			    i=0;
			    while(pt !=NULL){
			    	
			    	sscanf(pt,"%lu", &((*shape)[i]));
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



// ****************************************************************************************************
void load_npy_struct(char* filename, nparray_t* array){
    /*
    load_npy_struct( order,  ndir)

    Loads a '.npy' array to C format.

    INPUTS:
        
        -> filename:    Filename of the file to load. Must contain the path.
            
        ->     data:    Address of the array to be written (and allocated).

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
    

    if(filename != NULL ){
        

        // printf("Loading Filename: %s\n", filename);

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
			    *shape = (uint64_t*)malloc((*ndim)*sizeof(uint64_t));
			    i=0;
			    while(pt !=NULL){
			    	
			    	sscanf(pt,"%lu", &((*shape)[i]));
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

			fclose(cfPtr);

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }



        


        
    }
}
// ----------------------------------------------------------------------------------------------------



