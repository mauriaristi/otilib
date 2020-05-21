// ****************************************************************************************************
inline uint8_t array2d_getel_ui8_t(uint8_t* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline uint16_t array2d_getel_ui16_t(uint16_t* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline uint32_t array2d_getel_ui32_t(uint32_t* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline uint64_t array2d_getel_ui64_t(uint64_t* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline double array2d_getel_f64_t(double* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline float array2d_getel_f32_t(float* arr,uint64_t ncols, uint64_t i, uint64_t j){
   return arr[i*ncols + j];
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline int64_t dhelp_comb(int64_t a, int64_t b){
    
    int64_t niter = a - MAX(a-b,b);
    int64_t num = 1, den=1;
    int64_t i;

    for(i = 0; i<niter; i++){

        den = den * (i+1) ;
        num = num * (a-i) ;

    }

    return num/den;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void printArrayDBL(double* ptr_,uint64_t n){
    /*

    c_printArrayUI16( ptr_, size):

    Function that prints an array of unsigned integers of 64 bits of size n.

    */
    // ************************************************************************************************

    printf("[");

    for (uint64_t i = 0; i<n ; i++){

        printf(" %g,",ptr_[i]);
    }

    printf("]");

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void printArrayUI64(uint64_t* ptr_,uint64_t n){
    /*

    c_printArrayUI16( ptr_, size):

    Function that prints an array of unsigned integers of 64 bits of size n.

    */
    // ************************************************************************************************

    printf("[");

    for (uint64_t i = 0; i<n ; i++){

        printf(" %llu,",ptr_[i]);
    }

    printf("]");

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void printArrayUI16(uint16_t* ptr_,uint8_t n){
    /*

    c_printArrayUI16( ptr_, size):

    Function that prints an array of unsigned integers of 16 bits of size n.

    */
    // ************************************************************************************************

    int i=0;

    printf("[");

    for (i = 0; i<n ; i++){

        printf("%hu,",ptr_[i]);
    }
    if (i>0){
        
        printf("\b]");    

    } else {

        printf("]");    

    }
    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void printArrayUI8(uint8_t* ptr_,uint8_t n){
    /*

    c_printArrayUI16( ptr_, size):

    Function that prints an array of unsigned integers of 16 bits of size n.

    */

    printf("[");

    for (int i = 0; i<n ; i++){

        printf("%hhu,",ptr_[i]);
    }

    printf("]");

}
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















// ----------------------------------------------------------------------------------------------------

// typedef struct{
//     uint64_t*     p_data;
//     uint64_t*     p_cols;
//     uint64_t*     p_rows;
//     uint64_t       sizex;
//     uint64_t       sizey;
//     uint64_t     nonzero;
// } coomat_ui64_t;


// ****************************************************************************************************
matrix_form_t dhelp_matrix_form_indices( bases_t nbases, uint8_t order, dhelpl_t dhl){
    /*

    Obtain the dense matrix representation of the oti number num.

    INPUTS:

        -> nbases: Number of independent variables (number of imaginary bases.

        -> order:  Order of derivatives.

        -> p_dH:   List of helpers.

    OUTPUTS:

        The operation gives a uint64_t* such that it contains the matrix form of the oti number.

        Each non zero element in the matrix is the index of the OTI number coefficient that should
        be placed in that position.

        The shape of the matrix is (size x size)

    */ 
    // ************************************************************************************************
    uint64_t i,j,k,ii,jj,Ndir, ndir_i, ndir_j;
    imdir_t idx_i, idx_j, idx_res;
    ord_t ordi, ordj, ord_res;
    matrix_form_t mat;     // matrix pointer, Coo format
    uint64_t nnonzero = dhelp_ndirTotal( 2*nbases, order); // Get the number of non-zero elements.

    
    // Allocate memory to hold the results:
    mat.p_im   = ( imdir_t*)malloc(nnonzero*sizeof( imdir_t));
    mat.p_ord  = (   ord_t*)malloc(nnonzero*sizeof(   ord_t));
    mat.p_cols = (uint64_t*)malloc(nnonzero*sizeof(uint64_t));
    mat.p_rows = (uint64_t*)malloc(nnonzero*sizeof(uint64_t));


    if (mat.p_im   == NULL || mat.p_ord  == NULL || 
        mat.p_cols == NULL || mat.p_rows == NULL    ){

        printf("--- MemoryError ---\n");
        exit(1);

    }

    
    // Initialize in zero.
    memset(mat.p_im,   0, nnonzero*sizeof( imdir_t));
    memset(mat.p_ord,  0, nnonzero*sizeof(   ord_t));
    memset(mat.p_cols, 0, nnonzero*sizeof(uint64_t));
    memset(mat.p_rows, 0, nnonzero*sizeof(uint64_t));

    // Get the total size of the matrix.
    Ndir = dhelp_ndirTotal( nbases, order);
        
    mat.sizex   = Ndir;
    mat.sizey   = Ndir;
    mat.nonzero = nnonzero;



    // Put all real coefficient on the diagonal:
    k = 0;
    for(i = 0; i<Ndir; i++){

        mat.p_im[k]   = 0;
        mat.p_ord[k]  = 0;
        mat.p_rows[k] = i;
        mat.p_cols[k] = i;

        k++;

    }

    // Put all imaginary coefficient in the first column:
    j=0;
    // This is putting dir_i times real.
    for(ordi = 1; ordi<=order; ordi++){

        ndir_i = dhelp_ndirOrder(nbases, ordi   );
        ii     = dhelp_ndirTotal(nbases, ordi-1 );
        
        for (idx_i=0; idx_i<ndir_i; idx_i++){

            mat.p_im[k]   = idx_i;
            mat.p_ord[k]  = ordi;
            mat.p_rows[k] = ii + idx_i;
            mat.p_cols[k] = j;

            k++;
        
        }
        

    }

    // Put all other elements under the diagonal.
    for( ordi = 1; ordi < order ; ordi++){
        
        ndir_i = dhelp_ndirOrder(nbases, ordi);        

        for( ordj = 1; ordj <= (order-ordi) ; ordj++){
            
            ndir_j = dhelp_ndirOrder(nbases, ordj);
            
            jj = dhelp_ndirTotal(nbases, ordj-1     );
            ii = dhelp_ndirTotal(nbases, ordi+ordj-1);

            for (idx_i=0; idx_i<ndir_i; idx_i++){
                
                for (idx_j=0; idx_j<ndir_j; idx_j++){
                    
                    dhelp_multDir( idx_i, ordi, idx_j, ordj, &idx_res,&ord_res,dhl);
                    
                    // Add the element:
                    mat.p_im[k]   = idx_i;
                    mat.p_ord[k]  = ordi;

                    mat.p_rows[k] = ii + idx_res;
                    mat.p_cols[k] = jj + idx_j  ;

                    k++;


                }

            }            

        }

    }
    
    return mat;

}    
// ----------------------------------------------------------------------------------------------------


int global_test = 0;


void (*__PY_ERROR_OTI_EXIT)(int64_t)=NULL;
uint64_t is_python_error_def=0;

// void (**__PY_ERROR_OTI_EXIT_ptr)(int64_t)=&__PY_ERROR_OTI_EXIT;
// uint64_t* is_python_error_def_ptr = &is_python_error_def;

// ****************************************************************************************************
void set_global_test(int x){


    global_test = x;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void print_global_test(void){


    printf("This is global_test: %d \n",global_test);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void start_python_error_function(void){


    // printf("In start_python_error_function()\nDefining error function from python: \n");
    __PY_ERROR_OTI_EXIT = NULL;
    // error_function(OTI_OutOfMemory);
    is_python_error_def = 0;
    // printf("is_python_error_def: %llu\n",is_python_error_def);
    // (*__PY_ERROR_OTI_EXIT_ptr)(OTI_OutOfMemory);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void set_python_error_function(void (*error_function)(int64_t)){

    usage_python_error_function(error_function, 0, 0);
    // printf("In set_python_error_function()\nDefining error function from python: \n");
    __PY_ERROR_OTI_EXIT = error_function;
    // error_function(OTI_OutOfMemory);
    is_python_error_def = 1;
    // printf("is_python_error_def: %llu\n",is_python_error_def);
    // (*__PY_ERROR_OTI_EXIT_ptr)(OTI_OutOfMemory);

}
// ----------------------------------------------------------------------------------------------------

void print_python_error_def(void ){

    printf("This is is_python_error_def: %d \n",is_python_error_def);
}

// ****************************************************************************************************
void usage_python_error_function(void (*error_function)(int64_t), int64_t error_id, int64_t status){
    
    static void (*__PY_ERROR)(int64_t)=NULL;
    static uint64_t is_python = 0;

    if (status == 0){
        // Redefine __PY_ERROR_OTI_EXIT
        __PY_ERROR = error_function;
        is_python = 1;
        // printf("in usage_python_error_function\nModifying values\n");
        
    } else if (status == 1){
        
        // Use __PY_ERROR_OTI_EXIT
        
        // printf("in usage_python_error_function\nis_python_error_def %llu\n",is_python);

        // if (__PY_ERROR != NULL && is_python != 0){
        //     (*__PY_ERROR)(error_id);
        // }

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void python_error_function(void (*error_function)(int64_t)){


    // printf("In set_python_error_function()\nDefining error function from python: \n");
    __PY_ERROR_OTI_EXIT = error_function;
    // error_function(OTI_OutOfMemory);
    is_python_error_def = is_python_error_def + 1;
    // printf("is_python_error_def: %llu\n",is_python_error_def);
    // (*__PY_ERROR_OTI_EXIT_ptr)(OTI_OutOfMemory);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void error_exit(int64_t error_id){

    // printf("In error_exit()\nis_python_error_def: %llu\n",is_python_error_def);
    // usage_python_error_function(NULL,error_id,1);
    if (is_python_error_def != 0 ){
        printf("Exit from Python error function\n");
        (*__PY_ERROR_OTI_EXIT)(error_id);

    } else {
        printf("Exit from C exit function\n");
        exit(error_id);

    }

}
// ----------------------------------------------------------------------------------------------------
