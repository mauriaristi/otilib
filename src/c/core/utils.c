










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

    printf("[");

    for (int i = 0; i<n ; i++){

        printf(" %hu,",ptr_[i]);
    }

    printf("]");

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

        printf(" %hhu,",ptr_[i]);
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

