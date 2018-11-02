#include "oti/core.h"

// ----------------------------------------------------------------------------------------------------
// ---------------------------------     HELPER FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------








// ****************************************************************************************************
void c_helper_insertIndx(uint64_t* p_indxArray,uint64_t indx,uint64_t *size,
    double * p_coefArray, double coef){
    /*
    void c_helper_insertIndx(uint64_t* p_indxArray,uint64_t indx,uint64_t *size)

    Function to insert a direction index to a stack of directions.

    INPUTS:      
              - uint64_t* p_indxArray: Array of the directions.

              - uint64_t         indx: Index to be added. 

              - uint64_t*        size: Number of elements in p_indxArray

    EXAMPLE:

        >>> c_helper_insertIndx([], 5, 0);
           // Modifies the following.
        -> p_indxArray = [5]
        -> size        = 1


        >>> c_helper_insertIndx([1, 3, 17, 25], 17, 4);
        -> p_indxArray = [1, 3, 17, 25]
        -> size        = 4


        >>> c_helper_insertIndx([1, 3, 17, 25], 2, 4);
        -> p_indxArray = [1, 2, 3, 17, 25]
        -> size        = 5


    */   
    // ************************************************************************************************

    uint64_t pos;
    // printf("before: \n");
    // c_printArrayUI64(p_indxArray,size[0]);
    if (size[0] == 0){
        
        // No need to check what coefficients are
        
        p_indxArray[0] = indx;
        p_coefArray[0] = coef;
        size[0] = 1;

    } else {
    
        pos = c_binarySearchUI64( p_indxArray, indx, size[0]); //
        

        // printf("\nPosition found: %llu\n",pos);

        if (p_indxArray[pos] != indx){

            // printf("Array of %llu els. to be moved:\n");
            // c_printArrayUI64(&p_indxArray[pos],size[0]-pos);

            // move all items to make space for new index
            memmove(  &p_indxArray[pos+1],               // Destination
                      &p_indxArray[pos],                 // Source
                      (size[0]-pos)*sizeof(uint64_t));   // Number of bytes
            memmove(  &p_coefArray[pos+1],               // Destination
                      &p_coefArray[pos],                 // Source
                      (size[0]-pos)*sizeof(double)  );   // Number of bytes
            size[0] += 1 ;
            p_indxArray[pos] = indx;
            p_coefArray[pos] = coef;

        } else {

            p_coefArray[pos] += coef;

        }
        

    }
    // printf("after: \n");
    // c_printArrayUI64(p_indxArray,size[0]);
    // printf("\n\n");


}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_helper_ordDirExpA(uint16_t* p_dirA, uint8_t* multiple, uint8_t order, 
                        uint16_t* p_ndirA, uint8_t* p_nexpA){
    /*
    void c_helper_ordDirExpA(uint16_t* p_dirA, uint8_t* multiple, uint16_t* p_ndirA)

    Function to organize a direction array according to one obtained multiple.

    INPUTS:      
              - uint16_t* p_dirA:     Array of the directions.

              - uint8_t* multiple:    1D array with the multiple information of the exponents. 

              - uint8_t order:        Maximum order of the direction

              - uint16_t* p_ndirA:    Holder for the organized direction exponents

              - uint8_t*  p_nexpA:    Holder for the organized direction exponents

    EXAMPLE:

        >>> c_helper_ordDirExpA([1,3,5,0,0], [0,1,4,0,0], 5, p_ndirA, p_nexpA);

        >>> print(p_ndirA)
        [3,5,0,0,0]

        >>> print(p_nexpA)
        [1,4,0,0,0]

    */   
    // ************************************************************************************************

    uint8_t i = 0;
    uint8_t j = 0;

    for (;i<order;i++){

        if (multiple[i] != 0){ // If this exponent exists in the solution

            p_ndirA[j] = p_dirA[i];
            p_nexpA[j] = multiple[i];
            j++;

        }

    }

    // Fill up the rest with zeros.
    for (;j<order;j++){
        p_ndirA[j] = 0;
        p_nexpA[j] = 0;
    }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_helper_getMultpl(uint8_t* p_expA, uint8_t order, directionHelper* p_dH, uint64_t* Nmultpl){
    /*
    void c_helper_getMultpl(uint8_t* p_expA expArray, directionHelper* p_dH, uint64_t* Nmultpl)

    function to get the multiples of a direction. (it only depends of the exponent vector.)

    INPUTS:      
              - uint8_t* p_expA:       Array of the exponents 

              - uint8_t order:         Maximum order of the direction

              - directionHelper* p_dH: Address of the list of helpers

              - uint64_t* Nmultpl:     Number of multiples computed.

    RESULT: 
            p_dH[order-1].p_multpl will contain the multiples of the direction.

    EXAMPLE:

        >>> c_helper_getMultpl([1,2,0], 3, p_dH, &Nmultpl);
        >>> print(p_dH[3-1].p_multpl)
        [0,0,0]
        [1,0,0]
        [0,1,0]
        [1,1,0]
        [0,2,0]
        [1,2,0]
        [-,-,-] # not relevant
        [-,-,-] # not relevant
        >>> print(Nmultpl)
        6


    */   
    // ************************************************************************************************
    uint64_t i=0, k=0;
    uint8_t passed;
    uint8_t* multiple = p_dH[order-1].p_mexpA;
    uint8_t* multiples = p_dH[order-1].p_multpl;
    
    *Nmultpl = 1;
    for(; i<order; i++ ){
        // Multiply by the number of possible values of each basis exponent.
        *Nmultpl *= p_expA[i]+1;

        // Initialize the multiple holder's values.
        multiple[i] = 0;  // First multiple is real (all exps zero).
        multiples[i] = 0; // Initialize first row in zeros
    }

    for ( i = 1; i < (*Nmultpl); i++){

        passed = 0; // termination flag off.
        k=0;        // Set the counter to the initial position

        while(passed == 0){

            // Check if the current exponent can be summed 1 and still meet the 
            // exponent array limits.
            if( (multiple[k]+1) > p_expA[k]){ 
                
                // This means that if the current k'th exponent + 1 will not meet 
                // the conditions.
                multiple[k] = 0; // reset the current exponent
                k++;             // go to next position.

            } else {

                // the exponent can be summed 1.
                multiple[k] += 1;
                passed = 1;        // rise the flag.

            }
        }

        for(k=0;k<order;k++){

            multiples[i*order+k] = multiple[k];

        }

    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
uint16_t c_maxUI16(uint64_t a,uint64_t b){
    /* 
    uint16_t c_maxUI16(uint64_t a,uint64_t b)

    PURPOSE:     Computation of maximum of two integers

    INPUTS:      
              - uint64_t a: Integer to be compared.

              - uint64_t b: Integer to be compared

    RESULT: 
            Maximum of the two nmbers
              
    */
    // ************************************************************************************************

    if (a>b){
        
        return a;

    } else {
        
        return b;

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_minUI64(uint64_t a,uint64_t b,uint64_t* minnum,uint64_t* maxnum ){
    /* 
    uint64_t c_minUI64(uint64_t a,uint64_t b,uint64_t minnum,uint64_t maxnum )

    PURPOSE:     Computation of maximum and minimum of two integers

    INPUTS:      
              - uint64_t a: Integer to be compared.

              - uint64_t b: Integer to be compared

              - uint64_t* minnun: Address of minimum output.

              - uint64_t* maxnum: Address of maximum output.
              
    */
    // ************************************************************************************************

    if (a<b){
        *minnum = a;
        *maxnum = b;
    } else {
        *minnum = b;
        *maxnum = a;
    }

}
// ----------------------------------------------------------------------------------------------------









// ****************************************************************************************************
uint64_t c_helper_multMultiIndxFast(uint64_t* indx, uint8_t nindx, uint8_t order, 
                                directionHelper* p_dH, uint8_t* error){
    /* 
    uint64_t c_helper_multMultiIndxFast(uint64_t* indx, uint8_t nindx, uint8_t order, 
                                directionHelper* p_dH, uint8_t* error)

    PURPOSE:     Fast function that multiply multiple oti directions given by its indices. The idea is to send
                 the indices to a pure c-function in order to get the results.

    INPUTS:      
              - uint64_t* indx: List of Indices that represent the directions to be multiplied.

              - uint8_t nindx: Number of elements in indx

    OUTPUTS:
              - uint64_t indx: Resulting index that has the multiplication of the two numbers.
              
              - uint8_t* error: Error flag indicating viable multiplication or not.

                            error = 0:   -> Operation results in a viable direction.

                            error = 1:   -> Operation results in a not viable direction, and 
                                            indx should not be used. 
                                            e.g. the two directions result in a direction with 
                                            order greater than the maximum allowed order.
              
    */
    // ************************************************************************************************

    uint64_t minI, maxI;
    uint64_t indx1, indx2;
    uint8_t i, ord;

    
    {
        
        // -> Assuming values are not zero.
        // -> The number of indices is t
        
        ord = 0; // Find the order of the terms.
        for (i=0; i<nindx; i++){

            ord += c_sumUI8(&p_dH[order-1].p_expA[(indx[i]-1)*order],order);

            if (ord>order){

                *error = 1;
                return 0;

            }

        }
        
        // We know that the result is valid. It must exist.
        indx1 = indx[0]; 

        for(i=1 ; i<nindx; i++ ){
            
            indx2 = indx[i];
            
            c_minUI64(indx1,indx2,&minI,&maxI);
            // printf("IN MULTINDX: min %llu\n",minI);
            // printf("IN MULTINDX: max %llu\n",maxI);

            minI = (maxI-1)*((maxI-1)+1)/2 + (minI-1);
            //(i-1)*((i-1)+1)//2+(j-1)

            // Binary Search the Multiplication index to obtain the multiplication result.
            maxI =  c_binarySearchUI64(  p_dH[order-1].p_multInd, minI, p_dH[order-1].Nmult);
            // printf("IN MULTINDX: Index %llu\n",minI);
            // printf("IN MULTINDX: position %llu\n",maxI);
            // printf("IN MULTINDX: Found item %llu\n",p_dH[order-1].p_multInd[maxI]);
            // printf("IN MULTINDX: Found multResult %llu\n",p_dH[order-1].p_multRes[maxI]);

            if (p_dH[order-1].p_multInd[maxI] == minI){

                
                indx1 = p_dH[order-1].p_multRes[maxI];

            } else {

                *error = 1;
                return 0;

            }
        }

        *error = 0;
        return indx1;

    }
     

    

}
// ----------------------------------------------------------------------------------------------------




























// ****************************************************************************************************
uint64_t c_helper_multIndxFast(uint64_t indx1, uint64_t indx2, uint8_t order, directionHelper* p_dH, 
                               uint8_t* error){
    /* 
    uint64_t c_helper_multIndx(uint64_t indx1, uint64_t indx2, uint8_t order, directionHelper* p_dH, 
                           uint8_t error)

    PURPOSE:     Fast function that multiply two dual directions given by its indices. The idea is to send
                 the indices to a pure c-function in order to get the results.

    INPUTS:      
              - uint64_t indx1, indx2: Indices that represent the directions to be multiplied.

    OUTPUTS:
              - uint64_t indx: Resulting index that has the multiplication of the two numbers.
              
              - uint8_t* error: Error flag indicating viable multiplication or not.

                            error = 0:   -> Operation results in a viable direction.

                            error = 1:   -> Operation results in a not viable direction, and 
                                            indx should not be used. 
                                            e.g. the two directions result in a direction with 
                                            order greater than the maximum allowed order.
              
    */
    // ************************************************************************************************

    uint64_t minI, maxI;
    uint8_t ord1, ord2;

    

    if (order == 1){

        if (indx1 == 0 || indx2 == 0){
            
            c_minUI64(indx1,indx2,&minI,&maxI);
            *error = 0;
            return  maxI;

        } else {

            *error = 1;
            return 0;
        }


    }else{

        // First check if values are zero
        c_minUI64(indx1,indx2,&minI,&maxI);

        if (minI == 0){

            *error = 0;
            return maxI;

        }

        //First check orders... then do binary search
        ord1 = c_sumUI8(&p_dH[order-1].p_expA[(indx1-1)*order],order);
        ord2 = c_sumUI8(&p_dH[order-1].p_expA[(indx2-1)*order],order);

        if ((ord1+ord2)<=order){
            // printf("IN MULTINDX: i1 %llu\n",indx1);
            // printf("IN MULTINDX: i2 %llu\n",indx2);
            

            // printf("IN MULTINDX: min %llu\n",minI);
            // printf("IN MULTINDX: max %llu\n",maxI);

            minI = (maxI-1)*((maxI-1)+1)/2 + (minI-1);
            //(i-1)*((i-1)+1)//2+(j-1)

            // Binary Search the Multiplication index to obtain the multiplication result.
            maxI =  c_binarySearchUI64(  p_dH[order-1].p_multInd, minI, p_dH[order-1].Nmult);
            // printf("IN MULTINDX: Index %llu\n",minI);
            // printf("IN MULTINDX: position %llu\n",maxI);
            // printf("IN MULTINDX: Found item %llu\n",p_dH[order-1].p_multInd[maxI]);
            // printf("IN MULTINDX: Found multResult %llu\n",p_dH[order-1].p_multRes[maxI]);

            if (p_dH[order-1].p_multInd[maxI] == minI){

                *error = 0;
                return p_dH[order-1].p_multRes[maxI];

            } else {

                *error = 1;
                return 0;

            }
        }else{

            *error = 1;
            return 0;

        }

    }
     

    

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_helper_findIndex(uint16_t* p_dirA,  uint8_t* p_expA, uint8_t order, directionHelper* p_dH){
    /*
    uint64_t c_helper_findIndex(uint16_t* dirA,  uint8_t* expA, uint8_t order, directionHelper* p_dH)

    PURPOSE:      Implements a binary search so that it can find the given pair (dirA,expA) in
                  (p_dH.p_dirA,p_dH.p_expA)
     
    DESCRIPTION:  The condition that this satisfies is that it will return i such that

                  >>> (self.dirA[i,:],self.expA[i,:]) == (dirA,expA)
                  True

    INPUTS:      
              - uint16_t* dirA: Direction array with the basis of the direction to search.

              - uint8_t*  expA: Exponent array with the exponents of the basis that 
                                are present in the direction to search.

              - directionHelper* p_dH: List of all direction helpers

    OUTPUTS: 
              - uint64_t indx : position of the pair 

                        (dirA[:],expA[:]) in (p_dH.dirA[:,:],p_dH.expA[:,:])
              
    */
    //*************************************************************************************************

    uint64_t indx = 0;

    if (p_dirA[0] == 0){     // Case where dirA and expA are all zeros
    
        return indx;
    }
    

    if (order == 1){
          
        indx = p_dirA[0];
    
    }else{
          
        indx = c_binarySearch_dH( p_dirA, p_expA, &p_dH[order-1]) + 1;
    
    }

    return indx;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_helper_multIndx(uint64_t indx1, uint64_t indx2, uint8_t order, directionHelper* p_dH, 
                           uint8_t* error){
    /*
    uint64_t c_helper_multIndx(uint64_t indx1, uint64_t indx2, uint8_t order, directionHelper* p_dH, 
                           uint8_t error)

    PURPOSE:     Function that multiply two dual directions given by its indices. The idea is to send
                 the indices to a pure c-function in order to get the results.

    INPUTS:      
              - uint64_t indx1, indx2: Indices that represent the directions to be multiplied.

    OUTPUTS:
              - uint64_t indx: Resulting index that has the multiplication of the two numbers.
              
              - uint8_t* error: Error flag indicating viable multiplication or not.

                            error = 0:   -> Operation results in a viable direction.

                            error = 1:   -> Operation results in a not viable direction, and 
                                            indx should not be used. 
                                            e.g. the two directions result in a direction with 
                                            order greater than the maximum allowed order.
              
    */
    // ************************************************************************************************

    uint64_t indx = 0;  

    if (order == 1){
        
        // Order 1 multiplication is very easy and fast.
        if (indx1 == 0 ){
        
            error[0] = 0;
            return indx2;

        }else if(indx2 == 0){

            error[0] = 0;
            return indx1;

        }else{

            error[0] = 1;
            indx  = 0;
            return indx;

        }

    } else {
      
        // Check first if the given indices are zero.
  
        if (indx1 == 0 ){
          
            error[0] = 0;
            return indx2;
  
        }else if(indx2 == 0){
  
            error[0] = 0;
            return indx1;
  
        }
        
        // If necessary, multiply using the direction helper.
        indx = c_multDirections_dH( indx1-1, indx2-1, &p_dH[order-1], error);

    } 

    return indx + 1;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint8_t*  c_helper_getExpA(uint64_t indx, uint8_t order, directionHelper* p_dH){
    /*
    uint8_t* c_helper_getExpA(uint64_t indx, uint8_t order)

    PURPOSE:    Return the corresponding exponent array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] expA: Array containing the exponents of direction indx.

    TODO: Make output constant.
              
    */
    //*************************************************************************************************

    uint8_t i;
      
    if (indx != 0){

        return &p_dH[order-1].p_expA[(indx-1)*order];

    }else{

        for (i=0; i<order; i++){

            p_dH[order-1].p_mexpA[i] = 0; // Use only the first user array.

        }

        return p_dH[order-1].p_mexpA;
    }


}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint16_t*  c_helper_getDirA(uint64_t indx, uint8_t order, directionHelper* p_dH){
    /*
    uint8_t* c_helper_getDirA(uint64_t indx, uint8_t order)

    PURPOSE:    Return the corresponding direction array of indx.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint8_t[:] dirA: Array containing the basis of direction indx.

    TODO: Make output constant.
              
    */
    //*************************************************************************************************

    uint8_t i;
      
    if (indx != 0){

        return &p_dH[order-1].p_dirA[(indx-1)*order];

    }else{

        for (i=0; i<order; i++){

            p_dH[order-1].p_mdirA[i] = 0; // Use only the first user array.

        }

        return p_dH[order-1].p_mdirA;
    }


}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline uint8_t*   c_helper_getUExpA( uint8_t order, uint8_t n, directionHelper* p_dH){
    /*
    uint8_t* c_helper_getUExpA( uint8_t order, uint8_t n, directionHelper* p_dH)

    PURPOSE:  Return the n'th user exponent array.  
     
    INPUTS:      
              - uint8_t order: Order that indicates which helper to use.

              - uint8_t n:     Number of helper to use. Be careful to use a number less than
                               p_dH[order-1].nn

    OUTPUTS:
              - uint8_t[:] uexpA: n'th user array.
              
    */
    //*************************************************************************************************
      
    return &p_dH[order-1].p_uexpA[n*order];

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline uint16_t* c_helper_getUDirA( uint8_t order, uint8_t n, directionHelper* p_dH){
    /*
    uint16_t* c_helper_getUDirA( uint8_t order, uint8_t n, directionHelper* p_dH)

    PURPOSE:  Return the n'th user exponent array.  
     
    INPUTS:      
              - uint8_t order: Order that indicates which helper to use.

              - uint8_t n:     Number of helper to use. Be careful to use a number less than
                               p_dH[order-1].nn

    OUTPUTS:
              - uint8_t[:] udirA: n'th user array.
              
    */
    //*************************************************************************************************

    return &p_dH[order-1].p_udirA[n*order];
  
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_helper_findMaxDir(uint64_t index, uint8_t order, directionHelper* p_dH){
    /*
    uint64_t c_helper_findMaxDir(uint64_t index, uint8_t order, directionHelper* p_dH)

    PURPOSE:    Return the maximum direction of count.  
     
    INPUTS:      
              - uint64_t indx: index of the direction.

    OUTPUTS:
              - uint64_t The maximum basis of said direction.
              
    */
    // ************************************************************************************************

    uint64_t res = 0 ;       // Variable that has the maximum direction

    if (order == 1){
      
        res = index;

    } else {
      
        res = c_binarySearchUI64( p_dH[order-1].p_countOTI, index + 1 , p_dH[order-1].Nbasis );

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_helper_getNels( uint64_t m, uint8_t order, directionHelper* p_dH){
    /*
    uint64_t c_helper_getNels( uint64_t m, uint8_t order, directionHelper* p_dH)

    PURPOSE:    Return the number of total elements for m basis and maxorder.  
     
    INPUTS:      
              - uint64_t m: Number of directions.

    OUTPUTS:
              - uint64_t Number of elements.
              
    */
    // ************************************************************************************************

    uint64_t res = 0;  // Variable that has the maximum direction

    if (order == 1){
      
      res = m + 1;

    }else{
      
      res = p_dH[order-1].p_countOTI[m]; // TODO: Check when m > countOTI.size

    } 

    return res;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline uint64_t c_helper_getNParts( uint8_t order, directionHelper* p_dH){
    /*
    uint64_t c_helper_getNParts( uint8_t order, directionHelper* p_dH)

    PURPOSE:    Return the number of partition sets for the given size of set.
     
    INPUTS:      
              - uint8_t n: number of elements of the set.

    OUTPUTS:
              - uint64_t: number of partitions for a set of n elements.
              
    */
    // ************************************************************************************************
    
    return p_dH[order-1].Npart;

}
// ---------------------------------------------------------------------------------------------------- 



// ****************************************************************************************************
inline uint16_t c_helper_getSet( uint8_t order,uint64_t i,uint64_t j, directionHelper* p_dH){
    /*
    uint16_t c_helper_getSet( uint8_t order,uint64_t i,uint64_t j, directionHelper* p_dH)

    PURPOSE:    Return the set, in binary format, for the given partition i and subset j.
     
    INPUTS:      
              - uint8_t  maxorder: number of elements of the set.

              - uint64_t i: Number of partition to look for.

              - uint64_t j: subset of the partition to look for.

    OUTPUTS:
              - uint16_t: number in which the high bits correspond to the position of the elements
                          that belong to the asked partition.
              
    */
    // ************************************************************************************************

    return p_dH[order-1].p_part[ i*order + j ];

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_helper_load(  uint8_t maxorder, char* strLocation, directionHelper** p_dH){          
    /*
    directionHelper* c_loadHelpers(  uint8_t maxorder )

    Load a set of helpers from order 1 until maxorder with specified number of  basis for each order.

    INPUTS:
        
        -> maxorder:    Maximum order of helper to be loaded.
            Example: 3

    OUTPUTS:
        -> The result is an array of helpers of length = order with the loaded data.
    */ 
    // ************************************************************************************************

    
    // uint16_t ndir[]   = {65535, // ------------------   1 -> Probably not necessary
    //                       1000, // ------------------   2
    //                        100, // ------------------   3
    //                         10, // ------------------   4
    //                         10, // ------------------   5
    //                         10, // ------------------   6
    //                         10, // ------------------   7 
    //                         10, // ------------------   8
    //                         10, // ------------------   9
    //                         10  // ------------------  10
    // };

    uint16_t ndir[]   = {65535, // ------------------   1 -> Probably not necessary
                          1000, // ------------------   2
                           100, // ------------------   3
                            10, // ------------------   4
                            10, // ------------------   5
                            10, // ------------------   6
                            10, // ------------------   7 
                            10, // ------------------   8
                            10, // ------------------   9
                            10  // ------------------  10
    };

    uint8_t  nhelps =  3;

    p_dH[0] = (directionHelper* )malloc(maxorder*sizeof(directionHelper));

    if (p_dH == NULL){
      printf("Error. Not enough memory for helper array. Exiting\n");
      exit(-1);
    }
    
    for( int i = 1; i<=maxorder; i++){
        
      c_loadDirHelper(strLocation,i,ndir[i-1], nhelps, &(*p_dH)[i-1]);

    }

#ifdef VERB // Indicator of verbosity from compiler.
    printf("Successfully loaded  %d helpers.\n",maxorder);
#endif

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_helper_free(directionHelper* p_dH , uint8_t maxorder ){          
    /*
    void c_freeHelpers(directionHelper* p_dH , uint8_t maxorder )

    Free all helpers that where loaded.

    INPUTS:
        -> p_dH:        Array of helpers
        -> maxorder:    Maximum order of helper to be loaded.
            Example: 3

    OUTPUTS:
        -> The result is an array of helpers of length = order with the loaded data.
    */ 
    // ************************************************************************************************

    
    
    for( int i = 1; i<=maxorder; i++){
        
      c_freeDirHelper(&p_dH[i-1]);
    }

    free(p_dH);

#ifdef VERB // Indicator of verbosity from compiler.
    printf("Successfully freed  %d helpers.\n",maxorder);
#endif
}
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// -------------------------------     END HELPER FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------







// ----------------------------------------------------------------------------------------------------
// -------------------------------------     FUNCTIONS     --------------------------------------------
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_load2Dnpy_ui64(const char* filepath, uint64_t** p_array, 
                                            uint64_t* p_shapex, uint64_t* p_shapey){
    /*
    c_load2Dnpy_ui16( filepath, p_array, p_shapex, p_shapey)

    Loads a 2d array from a .npy file.

    INPUTS:

        -> filepath: Path where the *.npy file is located.
        -> p_array:  Address of the pointer that will hold the data.
        -> p_shapex: Address of the element that will contain the shape x.
        -> p_shapey: Address of the element that will contain the shape x.
        
    USAGE:

        uint16_t* array_with_data;
        uint64_t shapex, shapey;

        c_load2Dnpy_ui16("../data/", &array_with_data, &shapex, &shapey);
        

    OUTPUTS:
        -> The result is the direction array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0, shapey=0, size=0;
    


    // Malloc memory for strings:
    holder        = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc( 16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD ARRAY:
    
        #ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Filename: %s\n", filepath);
        #endif

        if ((cfPtr = fopen( filepath, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filepath
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';

            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);
            
            p_shapey[0] = shapey;
            p_shapex[0] = shapex;
            size = shapex*shapey;

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("shape: %llu, %llu \n",shapex,shapey);
            #endif
            
            // Allocate memory            
            p_array[0] = ( uint64_t* )malloc( size * sizeof(uint64_t) );

            if (p_array[0] != NULL){

                fread(p_array[0], sizeof(uint64_t), size, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for loading array in %s.\n Exiting\n", filepath);
                exit(-1);

            }

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filepath);
            #endif

        }else{

            printf("Error. No file \" %s \"found.\n",filepath);
            exit(-1);    // Exit program

        }

        fclose(cfPtr);

    }
}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_load2Dnpy_ui16(const char* filepath, uint16_t** p_array, 
                                            uint64_t* p_shapex, uint64_t* p_shapey){
    /*
    c_load2Dnpy_ui16( filepath, p_array, p_shapex, p_shapey)

    Loads a 2d array from a .npy file.

    INPUTS:

        -> filepath: Path where the *.npy file is located.
        -> p_array:  Address of the pointer that will hold the data.
        -> p_shapex: Address of the element that will contain the shape x.
        -> p_shapey: Address of the element that will contain the shape x.
        
    USAGE:

        uint16_t* array_with_data;
        uint64_t shapex, shapey;

        c_load2Dnpy_ui16("../data/", &array_with_data, &shapex, &shapey);


    OUTPUTS:
        -> The result is the direction array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0, shapey=0, size=0;
    


    // Malloc memory for strings:
    holder        = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc( 16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD ARRAY:
    
        #ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Filename: %s\n", filepath);
        #endif

        if ((cfPtr = fopen( filepath, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filepath
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';

            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);
            
            p_shapey[0] = shapey;
            p_shapex[0] = shapex;
            size = shapex*shapey;

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("shape: %llu, %llu \n",shapex,shapey);
            #endif
            
            // Allocate memory            
            p_array[0] = ( uint16_t* )malloc( size * sizeof(uint16_t) );

            if (p_array[0] != NULL){

                fread(p_array[0], sizeof(uint16_t), size, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for loading array in %s.\n Exiting\n", filepath);
                exit(-1);

            }

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filepath);
            #endif

        }else{

            printf("Error. No file \" %s \"found.\n",filepath);
            exit(-1);    // Exit program

        }

        fclose(cfPtr);

    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_load2Dnpy_ui8(const char* filepath, uint8_t** p_array, 
                                            uint64_t* p_shapex, uint64_t* p_shapey){
    /*
    c_load2Dnpy_ui8( filepath, p_array, p_shapex, p_shapey)

    Loads a 2d array from a .npy file.

    INPUTS:

        -> filepath: Path where the *.npy file is located.
        -> p_array:  Address of the pointer that will hold the data.
        -> p_shapex: Address of the element that will contain the shape x.
        -> p_shapey: Address of the element that will contain the shape x.
        
    USAGE:

        uint16_t* array_with_data;
        uint64_t shapex, shapey;

        c_load2Dnpy_ui16("../data/", &array_with_data, &shapex, &shapey);


    OUTPUTS:
        -> The result is the direction array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0, shapey=0, size=0;
    


    // Malloc memory for strings:
    holder        = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc( 16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD ARRAY:
    
        #ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Filename: %s\n", filepath);
        #endif

        if ((cfPtr = fopen( filepath, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filepath
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';

            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);
            
            p_shapey[0] = shapey;
            p_shapex[0] = shapex;
            size = shapex*shapey;

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("shape: %llu, %llu \n",shapex,shapey);
            #endif
            
            // Allocate memory            
            p_array[0] = ( uint8_t* )malloc( size * sizeof(uint8_t) );

            if (p_array[0] != NULL){

                fread(p_array[0], sizeof(uint8_t), size, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for loading array in %s.\n Exiting\n", filepath);
                exit(-1);

            }

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filepath);
            #endif

        }else{

            printf("Error. No file \" %s \"found.\n",filepath);
            exit(-1);    // Exit program

        }

        fclose(cfPtr);

    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_load2Dnpy_ui64(const char* filepath, uint64_t** p_array, 
                                            uint64_t* p_shapex, uint64_t* p_shapey){
    /*
    c_load2Dnpy_ui16( filepath, p_array, p_shapex, p_shapey)

    Loads a 2d array from a .npy file.

    INPUTS:

        -> filepath: Path where the *.npy file is located.
        -> p_array:  Address of the pointer that will hold the data.
        -> p_shapex: Address of the element that will contain the shape x.
        -> p_shapey: Address of the element that will contain the shape x.
        
    USAGE:

        uint16_t* array_with_data;
        uint64_t shapex, shapey;

        c_load2Dnpy_ui16("../data/", &array_with_data, &shapex, &shapey);
        

    OUTPUTS:
        -> The result is the direction array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0, shapey=0, size=0;
    


    // Malloc memory for strings:
    holder        = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc( 16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD ARRAY:
    
        #ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Filename: %s\n", filepath);
        #endif

        if ((cfPtr = fopen( filepath, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filepath
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';

            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);
            
            p_shapey[0] = shapey;
            p_shapex[0] = shapex;
            size = shapex*shapey;

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("shape: %llu, %llu \n",shapex,shapey);
            #endif
            
            // Allocate memory            
            p_array[0] = ( uint64_t* )malloc( size * sizeof(uint64_t) );

            if (p_array[0] != NULL){

                fread(p_array[0], sizeof(uint64_t), size, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for loading array in %s.\n Exiting\n", filepath);
                exit(-1);

            }

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filepath);
            #endif

        }else{

            printf("Error. No file \" %s \"found.\n",filepath);
            exit(-1);    // Exit program

        }

        fclose(cfPtr);

    }
}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void c_load2Dnpy_ui16(const char* filepath, uint16_t** p_array, 
                                            uint64_t* p_shapex, uint64_t* p_shapey){
    /*
    c_load2Dnpy_ui16( filepath, p_array, p_shapex, p_shapey)

    Loads a 2d array from a .npy file.

    INPUTS:

        -> filepath: Path where the *.npy file is located.
        -> p_array:  Address of the pointer that will hold the data.
        -> p_shapex: Address of the element that will contain the shape x.
        -> p_shapey: Address of the element that will contain the shape x.
        
    USAGE:

        uint16_t* array_with_data;
        uint64_t shapex, shapey;

        c_load2Dnpy_ui16("../data/", &array_with_data, &shapex, &shapey);


    OUTPUTS:
        -> The result is the direction array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0, shapey=0, size=0;
    


    // Malloc memory for strings:
    holder        = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc( 16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD ARRAY:
    
        #ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Filename: %s\n", filepath);
        #endif

        if ((cfPtr = fopen( filepath, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filepath
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';

            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);
            
            p_shapey[0] = shapey;
            p_shapex[0] = shapex;
            size = shapex*shapey;

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("shape: %llu, %llu \n",shapex,shapey);
            #endif
            
            // Allocate memory            
            p_array[0] = ( uint16_t* )malloc( size * sizeof(uint16_t) );

            if (p_array[0] != NULL){

                fread(p_array[0], sizeof(uint16_t), size, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for loading array in %s.\n Exiting\n", filepath);
                exit(-1);

            }

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filepath);
            #endif

        }else{

            printf("Error. No file \" %s \"found.\n",filepath);
            exit(-1);    // Exit program

        }

        fclose(cfPtr);

    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_load2Dnpy_ui8(const char* filepath, uint8_t** p_array, 
                                            uint64_t* p_shapex, uint64_t* p_shapey){
    /*
    c_load2Dnpy_ui8( filepath, p_array, p_shapex, p_shapey)

    Loads a 2d array from a .npy file.

    INPUTS:

        -> filepath: Path where the *.npy file is located.
        -> p_array:  Address of the pointer that will hold the data.
        -> p_shapex: Address of the element that will contain the shape x.
        -> p_shapey: Address of the element that will contain the shape x.
        
    USAGE:

        uint16_t* array_with_data;
        uint64_t shapex, shapey;

        c_load2Dnpy_ui16("../data/", &array_with_data, &shapex, &shapey);


    OUTPUTS:
        -> The result is the direction array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0, shapey=0, size=0;
    


    // Malloc memory for strings:
    holder        = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc( 16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD ARRAY:
    
        #ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Filename: %s\n", filepath);
        #endif

        if ((cfPtr = fopen( filepath, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filepath
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';

            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);
            
            p_shapey[0] = shapey;
            p_shapex[0] = shapex;
            size = shapex*shapey;

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("shape: %llu, %llu \n",shapex,shapey);
            #endif
            
            // Allocate memory            
            p_array[0] = ( uint8_t* )malloc( size * sizeof(uint8_t) );

            if (p_array[0] != NULL){

                fread(p_array[0], sizeof(uint8_t), size, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for loading array in %s.\n Exiting\n", filepath);
                exit(-1);

            }

            #ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filepath);
            #endif

        }else{

            printf("Error. No file \" %s \"found.\n",filepath);
            exit(-1);    // Exit program

        }

        fclose(cfPtr);

    }
}
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
void c_loadDirA(char* strLocation, uint8_t order,   uint16_t ndir, uint16_t** dirA, uint64_t* Ndir){
    /*
    loadDirA( order,  ndir)

    Loads a direction array from a file

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  ndir:    Number of directions to load.
            Example: 100

    OUTPUTS:
        -> The result is the direction array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0,shapey=0;
    


    // Malloc memory for strings:
    filename = (char *)malloc(256*sizeof(char));
    holder   = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc(16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD DIRECTION ARRAY:


        strcpy(filename,strLocation);
        strcat(filename,basename);
        strcat(filename,"dir_n");
        sprintf(holder, "%hhu", order);

        strcat(filename,holder);
        strcat(filename,"_m");

        sprintf(holder, "%hu", ndir);
        strcat(filename,holder);

        strcat(filename,".npy");
    
#ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Filename: %s\n", filename);
#endif

        if ((cfPtr = fopen( filename, "rb" )) != NULL){



            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';



            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);



            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';



            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);

#ifdef VERB // Indicator of verbosity from compiler.
            printf("shape: %llu, %llu \n",shapex,shapey);
#endif
            Ndir[0] = shapex;
            shapex *= shapey;
            
            // Allocate memory
            
            dirA[0] = (uint16_t* )malloc(shapex*sizeof(uint16_t));

            if (dirA[0] != NULL){

                fread(dirA[0], sizeof(uint16_t), shapex, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for direction array.\n Exiting\n");
                exit(-1);

            }

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filename);
#endif

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }



        fclose(cfPtr);


        // free memory
        free(filename);
        free(holder); 
        free(holderSmall); 
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_loadExpA(char* strLocation,uint8_t order,   uint16_t ndir, uint8_t** expA, uint64_t* Ndir){
    /*
    loadExpA( order,  ndir)

    Loads a direction array from a file

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  ndir:    Number of directions to load.
            Example: 100

    OUTPUTS:
        -> The result is the exponent array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0,shapey=0;

    // Malloc memory for strings:
    filename =      (char *)malloc(256*sizeof(char));
    holder   =      (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc( 16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD DIRECTION ARRAY:
        strcpy(filename,strLocation);
        strcat(filename,basename);
        strcat(filename,"exp_n");
        sprintf(holder, "%hhu", order);

        strcat(filename,holder);
        strcat(filename,"_m");

        sprintf(holder, "%hu", ndir);
        strcat(filename,holder);

        strcat(filename,".npy");
    
#ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Filename: %s\n", filename);
#endif

        if ((cfPtr = fopen( filename, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';



            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);



            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';



            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);

#ifdef VERB // Indicator of verbosity from compiler.
            printf("shape: %llu, %llu \n",shapex,shapey);
#endif

            Ndir[0] = shapex;
            shapex *= shapey;
            
            // Allocate memory
            expA[0] = (uint8_t* )malloc(shapex*sizeof(uint8_t));

            if (expA[0] != NULL){

                fread(expA[0], sizeof(uint8_t), shapex, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for direction array.\n Exiting\n");
                exit(-1);

            }

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filename);
#endif

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }
        fclose(cfPtr);


        // free memory
        free(filename);
        free(holder); 
        free(holderSmall); 
    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_loadCount(char* strLocation,uint8_t order,   uint16_t ndir, uint64_t** count){
    /*
    loadDirA( order,  ndir)

    Loads a direction array from a file

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  ndir:    Number of directions to load.
            Example: 100

    OUTPUTS:
        -> The result is the exponent array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0;

    // Malloc memory for strings:
    filename = (char *)malloc(256*sizeof(char));
    holder   = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc(16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD DIRECTION ARRAY:
        strcpy(filename,strLocation);
        strcat(filename,basename);
        strcat(filename,"count_n");
        sprintf(holder, "%hhu", order);

        strcat(filename,holder);
        strcat(filename,"_m");

        sprintf(holder, "%hu", ndir);
        strcat(filename,holder);

        strcat(filename,".npy");
    
#ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading File: %s\n", filename);
#endif

        if ((cfPtr = fopen( filename, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';


            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,), }",
                holderSmall, holderSmall, &shapex);

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Array shape: %llu\n",shapex);
#endif
            
            // Allocate memory
            count[0] = (uint64_t* )malloc(shapex*sizeof(uint64_t));

            if (count[0] != NULL){

                fread(count[0], sizeof(uint64_t), shapex, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for direction array.\n Exiting\n");
                exit(-1);

            }

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filename);
#endif

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }

        fclose(cfPtr);


        // free memory
        free(filename);
        free(holder); 
        free(holderSmall); 
    }
}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_loadMult(char* strLocation,uint8_t order, uint16_t ndir, uint64_t** multRes, uint64_t** multInd, uint64_t* Nmult){
    /*
    loadDirA( order,  ndir)

    Loads a direction array from a file

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  ndir:    Number of directions to load.
            Example: 100

    OUTPUTS:
        -> The result is the exponent array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char *filename2 ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr  = NULL; //  file pointer
    FILE *cfPtr2 = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0;
    uint64_t shapey=0;



    // Malloc memory for strings:
    filename = (char *)malloc(256*sizeof(char));
    filename2 = (char *)malloc(256*sizeof(char));
    holder   = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc(16*sizeof(char));
    
    if(filename != NULL && holder != NULL && filename2 != NULL){
        // LOAD DIRECTION ARRAY:
        strcpy(filename,strLocation);
        strcat(filename,basename);
        strcat(filename,"multres_n");
        strcpy(filename2,strLocation);
        strcat(filename2,basename);
        strcat(filename2,"multind_n");
        sprintf(holder, "%hhu", order);

        strcat(filename,holder);
        strcat(filename2,holder);

        strcat(filename,"_m");
        strcat(filename2,"_m");

        sprintf(holder, "%hu", ndir);
        strcat(filename,holder);
        strcat(filename2,holder);

        strcat(filename,".npy");
        strcat(filename2,".npy");
        
#ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading Files: %s, %s\n", filename, filename2);
#endif

        if ((cfPtr = fopen( filename, "rb" )) != NULL  && (cfPtr2 = fopen( filename2, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';


            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,), }",
                holderSmall, holderSmall, &shapex);
            
               
            Nmult[0] = shapex;

            if (shapex==0){

                multRes[0] = NULL;

            } else {

                // Allocate memory
                multRes[0] = (uint64_t* )malloc(shapex*sizeof(uint64_t));

                if (multRes[0] != NULL ){

                    fread(multRes[0], sizeof(uint64_t), shapex, cfPtr);

                }else{

                    printf("\nERROR1: Not enough memory for direction array.\n Exiting\n");
                    exit(-1);

                }

            }


            fread(holder, sizeof(char), 8, cfPtr2);
            holder[6] = '\0';

            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr2);

            // Read header
            fread(holder, sizeof(char), header_size, cfPtr2);
            holder[header_size] = '\0';


            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,), }",
                holderSmall, holderSmall, &shapey);

            if (shapex != shapey){
                printf("found different shapes: %llu     ---   %llu\n", shapex, shapey);
            }

            if (shapey==0){

                multInd[0] = NULL;

            } else {

                // Allocate memory
                multInd[0] = (uint64_t* )malloc(shapey*sizeof(uint64_t));

                if ( multInd[0] != NULL){

                    fread(multInd[0], sizeof(uint64_t), shapex, cfPtr2);

                }else{

                    printf("\nERROR2: Not enough memory for direction array.\n Exiting\n");
                    exit(-1);

                }

            }



                

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filename);
#endif

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }

        fclose(cfPtr);
        fclose(cfPtr2);


        // free memory
        free(filename);
        free(filename2);
        free(holder); 
        free(holderSmall); 
    }
    
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_loadParts(char* strLocation,uint8_t order,   uint16_t ndir, uint16_t** p_parts, uint64_t* Nparts){
    /*
    loadParts( order,  ndir, count)

    Loads a direction array from a file

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  ndir:    Number of directions to load.
            Example: 100

    OUTPUTS:
        -> The result is the partition array pointer with the loaded data.
    */ 
    // ************************************************************************************************

    char *filename ;
    char basename[] = "data/";
    char *holder;
    char *holderSmall;
    FILE *cfPtr = NULL; //  file pointer
    uint16_t header_size;
    uint64_t shapex=0,shapey=0;

    // Malloc memory for strings:
    filename = (char *)malloc(256*sizeof(char));
    holder   = (char *)malloc(256*sizeof(char));
    holderSmall   = (char *)malloc(16*sizeof(char));
    
    if(filename != NULL && holder != NULL){
        // LOAD DIRECTION ARRAY:
        strcpy(filename,strLocation);
        strcat(filename,basename);
        strcat(filename,"part_n");
        sprintf(holder, "%hhu", order);
        strcat(filename,holder);
        strcat(filename,".npy");
    
#ifdef VERB // Indicator of verbosity from compiler.
        printf("Loading File: %s\n", filename);
#endif

        if ((cfPtr = fopen( filename, "rb" )) != NULL){

            // Read the first 8 bytes of the file:
            // expected: ?NUMPYab     a,b is the version of the filename
            fread(holder, sizeof(char), 8, cfPtr);
            holder[6] = '\0';



            // Read header size
            fread(&header_size, sizeof(uint16_t), 1, cfPtr);



            // Read header
            fread(holder, sizeof(char), header_size, cfPtr);
            holder[header_size] = '\0';


            sscanf(holder,"{'descr': %s 'fortran_order': %s 'shape': (%llu,%llu), }",
                holderSmall, holderSmall, &shapex, &shapey);

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Array shape: %llu, %llu \n",shapex,shapey);
#endif

            Nparts[0] = shapex; 
            shapex   *= shapey;
            
            // Allocate memory
            
            p_parts[0] = (uint16_t* )malloc(shapex*sizeof(uint16_t));

            if (p_parts[0] != NULL){

                fread(p_parts[0], sizeof(uint16_t), shapex, cfPtr);

            }else{

                printf("\nERROR: Not enough memory for partition array.\n Exiting\n");
                exit(-1);

            }

#ifdef VERB // Indicator of verbosity from compiler.
            printf("Successfully loaded \" %s \" file.\n",filename);
#endif

        }else{

            printf("Error. No file \" %s \"found.\n",filename);
            exit(-1);    // Exit program

        }



        fclose(cfPtr);


        // free memory
        free(filename);
        free(holder); 
        free(holderSmall); 
    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_loadDirHelper( char* strLocation, uint8_t order,   uint16_t nbasis, uint8_t nhelps, directionHelper* dHelp){          
    /*
    loadDirHelper( order,  ndir,  dHelp)

    Loads a direction helper from a file.Applies the binary search to find what is the position at which the 
    pair dirs,exps exist on an array of size N that contains it.

    INPUTS:
        
        -> order:    Order to be loaded in memory.
            Example: 3

        ->  nbasis:    Number of basis directions to load.
            Example: 100

        ->nhelps:   Number of help arrays to be allocated in the array.

        ->dHelp:    Adress of the helper to be loaded.

    OUTPUTS:
        -> The result is the direction helper with the loaded data.
    */ 
    // ************************************************************************************************

    // Initialize known values

    c_loadDirA( strLocation, order, nbasis, &dHelp->p_dirA, &dHelp->Ndir  );
    c_loadExpA( strLocation, order, nbasis, &dHelp->p_expA, &dHelp->Ndir  );
    c_loadParts(strLocation, order, nbasis, &dHelp->p_part, &dHelp->Npart );
    c_loadCount(strLocation, order, nbasis, &dHelp->p_countOTI);
    c_loadMult( strLocation, order, nbasis, &dHelp->p_multRes, &dHelp->p_multInd, &dHelp->Nmult);

    dHelp->Nbasis = nbasis;
    dHelp->order  =  order;
    dHelp->nn     = nhelps;
    
    dHelp->p_udirA  = (uint16_t*)malloc(  nhelps*order*sizeof(uint16_t)    ); 
    dHelp->p_uexpA  = (uint8_t* )malloc(  nhelps*order*sizeof(uint8_t )    ); 
    dHelp->p_rdirA  = (uint16_t*)malloc(  nhelps*order*sizeof(uint16_t)    ); 
    dHelp->p_rexpA  = (uint8_t* )malloc(  nhelps*order*sizeof(uint8_t )    ); 
    dHelp->p_mdirA  = (uint16_t*)malloc(  nhelps*order*sizeof(uint16_t)    ); 
    dHelp->p_mexpA  = (uint8_t* )malloc(  nhelps*order*sizeof(uint8_t )    ); 
    dHelp->p_mapder = (uint16_t*)malloc(2*nhelps*order*sizeof(uint16_t)    ); 
    dHelp->p_multpl = (uint8_t* )malloc( c_fastpow(2,order)*order*sizeof(uint8_t )); 
    dHelp->p_fder   = (double*  )malloc( (order+1    )*sizeof(double  )    );
    dHelp->p_coefs  = (double*  )malloc( (dHelp->Ndir)*sizeof(double  )    );
    dHelp->p_indx   = (uint64_t*)malloc( (dHelp->Ndir)*sizeof(uint64_t)    );

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_freeDirHelper(  directionHelper* dHelp){          
    /*
    freeDirHelper( dHelp)

    Frees all arrays in dHelp struct.

    INPUTS:
        
        -> dHelp:   Allocated direction helper.
    */ 
    // ************************************************************************************************

    // Initialize known values
    if (dHelp->p_dirA != NULL){
        free(dHelp->p_dirA    );
    }

    if (dHelp->p_expA != NULL){
        free(dHelp->p_expA    );
    }

    if (dHelp->p_part != NULL){
        free(dHelp->p_part    );
    }

    if (dHelp->p_countOTI != NULL){
        free(dHelp->p_countOTI);
    }

    if (dHelp->p_udirA != NULL){
        free(dHelp->p_udirA   );
    }
    
    if (dHelp->p_uexpA != NULL){
        free(dHelp->p_uexpA   );
    }
    
    if (dHelp->p_rdirA != NULL){
        free(dHelp->p_rdirA   );
    }

    if (dHelp->p_rexpA != NULL){
        free(dHelp->p_rexpA   );
    }
    
    if (dHelp->p_mdirA != NULL){
        free(dHelp->p_mdirA   );
    }
    
    if (dHelp->p_mexpA    != NULL){
        free(dHelp->p_mexpA   );
    }
    
    if (dHelp->p_mapder   != NULL){
        free(dHelp->p_mapder  );
    }

    if (dHelp->p_multRes   != NULL){
        free(dHelp->p_multRes  );
    }

    if (dHelp->p_multInd   != NULL){
        free(dHelp->p_multInd  );
    }

    if (dHelp->p_multpl   != NULL){
        free(dHelp->p_multpl  );
    }

    if (dHelp->p_fder    != NULL){
        free(dHelp->p_fder   );
    }

    if (dHelp->p_coefs   != NULL){
        free(dHelp->p_coefs  );
    }

    if (dHelp->p_indx    != NULL){
        free(dHelp->p_indx   );
    }
    

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
uint64_t c_fastpow(uint64_t b,uint16_t exp){
    /*
    fastpow( b,exp ):

    Function that returns the power of a positive integer "base" to a positive integer "exp", both 
    bounded in value from 0 to 10. It is meant to be much faster than math.h pow(), which is defined
    for double inputs.

    INPUTS:
        
        -> b   : Base of exponentiation.         0 < b    < 10

        -> exp : exponent of the exponentiation. 0 < exp  < 10

    OUTPUTS:

        -> The result is b^exp :

            Example: fastpow(3,2) --> 9

    */
    // ************************************************************************************************

    static uint64_t ndir = 11;

    static uint64_t pows[] = {
        1,  0,   0,    0,     0,      0,       0,        0,         0,          0,           0, 
        1,  1,   1,    1,     1,      1,       1,        1,         1,          1,           1, 
        1,  2,   4,    8,    16,     32,      64,      128,       256,        512,        1024, 
        1,  3,   9,   27,    81,    243,     729,     2187,      6561,      19683,       59049, 
        1,  4,  16,   64,   256,   1024,    4096,    16384,     65536,     262144,     1048576, 
        1,  5,  25,  125,   625,   3125,   15625,    78125,    390625,    1953125,     9765625, 
        1,  6,  36,  216,  1296,   7776,   46656,   279936,   1679616,   10077696,    60466176, 
        1,  7,  49,  343,  2401,  16807,  117649,   823543,   5764801,   40353607,   282475249, 
        1,  8,  64,  512,  4096,  32768,  262144,  2097152,  16777216,  134217728,  1073741824, 
        1,  9,  81,  729,  6561,  59049,  531441,  4782969,  43046721,  387420489,  3486784401, 
        1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000,
        1, 11, 121, 1331, 14641, 161051, 1771561, 19487171, 214358881, 2357947691, 25937424601};
    
    return pows[b*ndir+exp];

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_fastfact(uint8_t exp){
    /*
    fastfact( exp ):

    Function that returns the factorial of a positive integer value from 0 until 10.

    INPUTS:
        -> exp : value to compute the factorial. 0 < exp < 10

    OUTPUTS:
        -> The result is exp! :

            Example: fastfact(3) --> 6

    */
    // ************************************************************************************************
    static double facts[] = {1., 1., 2., 6., 24., 120., 720., 5040., 40320., 362880., 3628800.};
    
    return facts[exp];

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_ndir(uint64_t nvar,uint8_t order){
    /*
    c_ndir(m, n):

    Function that returns the binomial coefficient :   /  nvar + order  \
                                                      (                  )
                                                       \      nvar      /
    INPUTS:
        -> nvar  : Number of variables to compute derivatives
        -> order : Order of derivatives

    OUTPUTS:
        -> The result is exp! :

            Example: c_ndir(3,5) --> 6

    */
    // ************************************************************************************************
    uint8_t n = order;
    uint64_t num = 1;
    uint64_t den = 1;

    for (int i=0; i<order; i++){
        num*=(nvar+n);
        den*=(n);
        n = n-1;
    }
    
    return num/den;

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void c_orderDirExpArray(uint16_t* dirA,    uint8_t*    multExpA , uint8_t pos,
             uint16_t* newDirA, uint8_t* newExpA, uint8_t order){
    /*
    c_orderDirExpArray( dirA, multExpA, newDirA, pos, newExpA,  maxorder)

    */
    // ************************************************************************************************
    
    uint8_t i;
    uint8_t j = 0 ;
    

    

    for (i=0; i<order; i++){
    
        if (multExpA[ i+ pos*order] != 0){          // the exponent exist in the solution.
                  
            newDirA[j] = dirA[i];
            newExpA[j] = multExpA[i + pos*order];
            j += 1;
        
        }
    
    }
    if (j != order){
        for(i = j; i<order; i++){
            newDirA[j] = 0;
            newExpA[j] = 0;
        }
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_mapPartition(uint16_t part,  uint16_t*  ptr_dir,  uint8_t  order, 
                    uint16_t*  ptr_map){
    /*
    c_mapPartition(  part,  ptr_dir,  order,  ptr_map)

    */
    // ************************************************************************************************
    
    uint8_t i = 0 ;                     // Counter of the element that belongs to 
    uint8_t pos = 0;                    // Holds position to write in ptr_map (set with the partition)
    uint16_t seti = part;               // This number contains in its bits the elements of the full 
                                        // that belong to the current partition.
    while(seti != 0){

        if(seti & 1){

            ptr_map[pos] = ptr_dir[i];  // Bit of position i is high, therefore the element i exist in 
            pos += 1;                   // the set.

        }

        i += 1;                         // update the counter for i.
        seti = seti >> 1;               // Move number one element to the right to ask if next 
                                        // element exist in the set.
    }

    for (i = pos; i<order; i++){

        ptr_map[i] = 0;                 // Fill the remaining elements with zeros.

    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mapDirArrayNoMapderFast( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,
                    uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2) {
    /*
    mapDirArrayNoMapderFast( ptr_dirA1 , ptr_dirA2,       order,
                   ptr_mdirA2, ptr_mdirA2):

    Function that maps two direction arrays to a consecutive ordered 
    direction arrays starting from 1.

    INPUTS:
        -> ptr_dirA1 (order): Array of values that represent the directions of a number
            Example: [ 3, 8, 0, 0]

        -> ptr_dirA2 (order): Array of values that represent the exponents of those directions
            Example: [ 7,10, 0, 0]

        -> order:    Order of the OTI number that is being used.
            Example: 4 


    OUTPUTS:
        -> The result are 3 arrays:

            -> ptr_mdirA1 (order): Array of values with the corresponding mapped directions of array 
            dirA1.
            Example: [1, 3, 0, 0]

            -> ptr_mdirA2 (order): Array of values that represent the exponents of those directions
            Example: [2, 4, 0, 0]


    
    Note: All arrays must come already allocated.

    */
    // ************************************************************************************************
    
    uint8_t  k=1;
    uint8_t  i=0,  j=0;

    uint16_t dir1, dir2 ;    

    while (i < order && j < order){
        
        dir1 = ptr_dirA1[i];        
        dir2 = ptr_dirA2[j];
        
        if (dir1 == 0 || dir2 == 0){
            
            if (dir1 == 0){
                ptr_mdirA1[i] = 0;
                i++;
            } else {
                ptr_mdirA1[i] = k;
                i++;
                k++;
            }
            
            if (dir2 == 0){
                ptr_mdirA2[j] = 0;
                j++;
            } else {
                ptr_mdirA2[j] = k;
                j++;
                k++;
            }

        }else {

            if (dir1 == dir2){
                ptr_mdirA1[i] = k;
                ptr_mdirA2[j] = k;
                i++;
                j++;
                k++;
            }else if (dir1 < dir2){
                ptr_mdirA1[i] = k;
                i++;
                k++;
            }else{
                ptr_mdirA2[j] = k;
                j++;
                k++;
            }

        }

    }
    for (;i < order; i++) {
        dir1 = ptr_dirA1[i];
        if (dir1 == 0){
            ptr_mdirA1[i] = 0;
            i++;
        } else {
            ptr_mdirA1[i] = k;
            i++;
            k++;
        }
    }
    for (;j < order; j++) {
        dir2 = ptr_dirA2[j];
        if (dir2 == 0){
            ptr_mdirA2[j] = 0;
            j++;
        } else {
            ptr_mdirA2[j] = k;
            j++;
            k++;
        }
    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_mapDirArrayNoMapder( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,
                    uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2) {
    /*
    c_mapDirArray( ptr_dirA1 , ptr_dirA2,       order,
                   ptr_mdirA2, ptr_mdirA2):

    Function that maps two direction arrays to a consecutive ordered 
    direction arrays starting from 1.

    INPUTS:
        -> ptr_dirA1 (order): Array of values that represent the directions of a number
            Example: [ 3, 8, 0, 0]

        -> ptr_dirA2 (order): Array of values that represent the exponents of those directions
            Example: [ 7,10, 0, 0]

        -> order:    Order of the OTI number that is being used.
            Example: 4 


    OUTPUTS:
        -> The result are 3 arrays:

            -> ptr_mdirA1 (order): Array of values with the corresponding mapped directions of array 
            dirA1.
            Example: [1, 3, 0, 0]

            -> ptr_mdirA2 (order): Array of values that represent the exponents of those directions
            Example: [2, 4, 0, 0]


    
    Note: All arrays must come already allocated.

    */
    // ************************************************************************************************
    
    uint8_t k = 0;
    uint8_t i;
    uint8_t j;
    uint8_t l;
    uint8_t n = 0;
    uint16_t m;

    for (i = 0; i<order ; i++){
        
        if(ptr_dirA1[i]!=0){

            m = i+1;
            ptr_mdirA1[i] = m;


        } else{
          
            ptr_mdirA1[i] = 0;

        }

    }

    // Check if the second array has some values that can improve the 
    // performance

    for(i = 0; i<order ; i++){

        if(ptr_dirA2[i]!=0){

            // Loop in the elements of dirA1
            for(l=n; l<order; l++){
                
                if (ptr_dirA1[l]!=0){

                    if(ptr_dirA2[i] < ptr_dirA1[l]){


                        k = ptr_mdirA1[l];

                        // Sum 1 to all elements in ptr_mdirA1 except the zeros
                        for(j = l; j<order ; j++){
                            
                            if(ptr_dirA1[j]!=0){
                      
                                ptr_mdirA1[j] += 1;
                            
                            } else{
                                
                                break;

                            }

                        }

                        n = l;
                        ptr_mdirA2[i] = k;
                        m += 1;
                        break;

                    }else if(ptr_dirA2[i] == ptr_dirA1[l]){
                      
                        k = ptr_mdirA1[l];
                        ptr_mdirA2[i] = k;
                        break;

                    }

                }else{
            
                    ptr_mdirA2[i] = m+1;
                    m+=1;
                    break;
                    
                }

                if (l==order-1){
                    ptr_mdirA2[i] = m+1;
                    m+=1;
                }

            }

        }else{

            ptr_mdirA2[i] = 0;

        }



    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_multDirections(uint16_t* ptr_dirArray, uint8_t* ptr_expArray,
                        uint16_t* ptr_dirA1,  uint8_t* ptr_expA1,
                        uint16_t* ptr_dirA2,  uint8_t* ptr_expA2, 
                        uint16_t* ptr_mdirA1, uint8_t* ptr_mexpA1,
                        uint16_t* ptr_mdirA2, uint16_t* ptr_mdirA3, 
                        uint16_t* ptr_mapder, 
                        uint8_t order, uint64_t N, uint8_t* error ){
    /*
    c_multDirections(ptr_dirA1, ptr_expA2, ptr_dirA1, ptr_expA2, order):

    Function that multiplies two directions i,j.

    INPUTS:

        -> ptr_dirArray[N,order]:   Array of all possible combinations of directions 
                                    for m number of base directions.
            Example: [1,0,   
                      1,0,
                      2,0,
                      1,2,
                      2,0,
                      3,0,   // for m=3
                      1,3,
                      2,3,
                      3,0]

        -> ptr_expArray[N,order]:   Array of all possible combinations of exponents, 
                                    associated to those directions.
            Example: [1,0,
                      2,0,   
                      1,0,
                      1,1,   // the sum of each row should always be \leq order.
                      2,0,
                      1,0,
                      1,1,
                      1,1,
                      2,0]


        ->  ptr_dirA<1,2>: Array of values that represent the directions of a number
            Example: ptr_dirA1 [3,0] , ptr_dirA2 [2,0] 

        ->  ptr_expA<1,2>: Array of values that represent the exponents of those directions
            Example: ptr_expA1 [1,0] , ptr_expA2 [1,0]

        ->  order:    Order of the OTI number that is being used.
            Example: 2

        -> ptr_mdirA<1,2,3>: Allocated arrays to handle the algorithm.

        -> ptr_mexpA1: Allocated array to handle the exponent of the algorithm.

        -> N:         Number of rows of the dirArray and expArray.
            Example: 9 
        -> error: Indicator to show if the result is valid or not.


    OUTPUTS:
        ->  The result is an uint64_t which corresponds to the index of the 
            multiplied indices.

            Example: 7 = c_multDirections(...)


    */
    // ************************************************************************************************

    // check thee order of the numbers
    uint64_t index = 0;

    uint8_t newOrder = c_sumUI8(ptr_expA1,order) + c_sumUI8(ptr_expA2,order);
    uint64_t index_1;
    uint64_t index_2;

    if( newOrder <= order ){

        // no notification required.
        (*error) = 0;

        // Map the direction arrays.

        c_mapDirArray( ptr_dirA1, ptr_dirA2, order, ptr_mdirA1, ptr_mdirA2, ptr_mapder);

        // Find index values

        index_1 =  c_convToIndex(ptr_mdirA1,ptr_expA1, order);
        index_2 =  c_convToIndex(ptr_mdirA2,ptr_expA2, order);

        // Find the resulting direction after multiplication

        index_1 +=  index_2; 

        // Retrieve the directions of the multiplied index.
        c_convToDirExp(index_1, order, ptr_mdirA1, ptr_mexpA1); 
        
        // remap the array to the original directions.
        c_reMapDirArray( ptr_mdirA1, ptr_mapder,  order,  ptr_mdirA1);

        // find the corresponding index of the result:
        index = c_binarySearch(  ptr_dirArray,  ptr_expArray,
                                   ptr_mdirA1,    ptr_mexpA1,  order,
                               N,  ptr_mdirA2,    ptr_mdirA3);

    }else{

        // Send back a signal to know the multiplication is not possible between this 
        // two directions.

        (*error) = 1;
    }

    return index;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_mapDirArray( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,
                    uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2, uint16_t* ptr_mapder) {
    /*
    c_mapDirArray( ptr_dirA1 , ptr_dirA2,       order,
                   ptr_mdirA2, ptr_mdirA2, ptr_mapder):

    Function that maps two direction arrays to a consecutive ordered 
    direction arrays starting from 1.

    INPUTS:
        -> ptr_dirA1 (order): Array of values that represent the directions of a number
            Example: [ 3, 8, 0, 0]

        -> ptr_dirA2 (order): Array of values that represent the exponents of those directions
            Example: [ 7,10, 0, 0]

        -> order:    Order of the OTI number that is being used.
            Example: 4 


    OUTPUTS:
        -> The result are 3 arrays:

            -> ptr_mdirA1 (order): Array of values with the corresponding mapped directions of array 
            dirA1.
            Example: [1, 3, 0, 0]

            -> ptr_mdirA2 (order): Array of values that represent the exponents of those directions
            Example: [2, 4, 0, 0]

            -> ptr_mapder (2 * order): Array of the corresponding (real) directions that correlates the mapped
            directions
            Example: [3,7,8,10,0,0,0,0]
    
    Note: All arrays must come already allocated.

    */
    // ************************************************************************************************

    uint8_t k = 0;
    uint8_t i;
    uint8_t j;
    uint8_t l;
    uint8_t n = 0;
    uint16_t m;

    // printArray16(ptr_dirA1,order);
    // Initialize the first mapped dirA

    for (i = 0; i<order ; i++){
        
        if(ptr_dirA1[i]!=0){

            m = i+1;
            ptr_mdirA1[i] = m;


        } else{
          
            ptr_mdirA1[i] = 0;

        }

    }

    // Check if the second array has some values that can improve the 
    // performance

    for(i = 0; i<order ; i++){

        if(ptr_dirA2[i]!=0){

            // Loop in the elements of dirA1
            for(l=n; l<order; l++){
                
                if (ptr_dirA1[l]!=0){

                    if(ptr_dirA2[i] < ptr_dirA1[l]){


                        k = ptr_mdirA1[l];

                        // Sum 1 to all elements in ptr_mdirA1 except the zeros
                        for(j = l; j<order ; j++){
                            
                            if(ptr_dirA1[j]!=0){
                      
                                ptr_mdirA1[j] += 1;
                            
                            } else{
                                
                                break;

                            }

                        }

                        n = l;
                        ptr_mdirA2[i] = k;
                        m += 1;
                        break;

                    }else if(ptr_dirA2[i] == ptr_dirA1[l]){
                      
                        k = ptr_mdirA1[l];
                        ptr_mdirA2[i] = k;
                        break;

                    }

                }else{
            
                    ptr_mdirA2[i] = m+1;
                    m+=1;
                    break;
                    
                }

                if (l==order-1){
                    ptr_mdirA2[i] = m+1;
                    m+=1;
                }

            }

        }else{

            ptr_mdirA2[i] = 0;

        }

    }


    // Find the equivalent mapder array:

    for(i = 0; i<order ; i++){
        
        if(ptr_dirA1[i]!=0){

            ptr_mapder[ptr_mdirA1[i]-1] = ptr_dirA1[i];

        }else{

            break;

        }

    }

    for(i = 0; i<order ; i++){
        
        if(ptr_dirA2[i]!=0){

            ptr_mapder[ptr_mdirA2[i]-1] = ptr_dirA2[i];

        }else{

            break;
            
        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint8_t c_sumUI8(uint8_t* ptr_,uint8_t n){
    /*

    c_sumUI8( ptr_, size):

    Function that sums all elements of array of unsigned integers of 8 bits of size n.

    */
    // ************************************************************************************************

    uint8_t sum_ = 0;
    uint8_t val;

    for (int i = 0; i<n ; i++){
        
        val = ptr_[i];

        if (val == 0){
            break;
        } else {
            sum_ += val;    
        }
        
    }

    return sum_;

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_printArrayDBL(double* ptr_,uint64_t n){
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
void c_printArrayUI64(uint64_t* ptr_,uint64_t n){
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
void c_printArrayUI16(uint16_t* ptr_,uint8_t n){
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
void c_printArrayUI8(uint8_t* ptr_,uint8_t n){
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
void c_reMapDirArray( uint16_t*  ptr_mdirA1, uint16_t* ptr_mapder, uint8_t order,
                      uint16_t* ptr_dirA1) {

    /*
    c_reMapDirArray( ptr_mdirA1 , ptr_mdirA2, ptr_mapder,
                   ptr_dir1, ptr_dirA2 ):

    Function that maps two direction arrays to a consecutive ordered 
    direction arrays starting from 1.

    INPUTS:
        -> ptr_mdirA1 (order): Array of values with the corresponding mapped directions of array 
            dirA1.
            Example: [1, 3, 0, 0]

            -> ptr_mdirA2 (order): Array of values with the corresponding mapped directions of array 
            dirA2.
            Example: [2, 4, 0, 0]

        -> ptr_mapder (2 * order): Array of the corresponding (real) directions that correlates the mapped
            directions
            Example: [3,7,8,10,0,0,0,0]

        -> order:    Order of the OTI number that is being used.
            Example: 4 



    OUTPUTS:
        -> The result are 3 arrays:

            -> ptr_dirA1 (order): Array of values that represent the directions of a number
            Example: [ 3, 8, 0, 0]

            -> ptr_dirA2 (order): Array of values that represent the directions of a number
            Example: [ 7,10, 0, 0]

            
    
    Note: All arrays must come already allocated.

    */
    // ************************************************************************************************

    int i;

    for(i =0; i<order; i++){
        
        if( ptr_mdirA1[i]!= 0 ) {

            ptr_dirA1[i] = ptr_mapder[ptr_mdirA1[i]-1];

        }else{

            ptr_dirA1[i] = 0;

        }

    }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_convToIndex(uint16_t* ptr_dirA,uint8_t* ptr_expA, uint8_t order) {
    /*
    c_convToIndex( ptr_dirA, ptr_expA, order):

    Function that converts a set of exponents and directions to a corresponding 
    integer value.

    INPUTS:
        -> ptr_dirA: Array of values that represent the directions of a number
            Example: [3,4]

        -> ptr_expA: Array of values that represent the exponents of those directions
            Example: [1,2]

        -> order:    Order of the OTI number that is being used.
            Example: 3 


    OUTPUTS:
        -> The result is an uint64_t with the following formula

                \sum{expA[i]*(order+1)^(dirA[i]-1)}

            Example: 144 = c_convToIndex([3,4],[1,2], 3)


    */
    // ************************************************************************************************

    uint64_t index = 0;
    uint64_t base = order+1;
    uint64_t multiple;

    for (uint8_t i = 0; i<order ; i++){

        multiple = ptr_expA[i];

        if (multiple != 0){

            index += multiple*c_fastpow(base,ptr_dirA[i]-1);

        }else{

            break;

        }

    }

    return index;
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void c_convToDirExp(uint64_t index, uint8_t order, uint16_t* ptr_dirA, uint8_t* ptr_expA) {
    /*
    c_convToDirExp( ptr_dirA, ptr_expA, order):

    Function that converts a set of exponents and directions to a corresponding 
    integer value.

    INPUTS:
        -> index:    Integer form of the sets of directions and exponents.
            Example: 24

        -> order:    Order of the OTI number that is being used.
            Example: 3 

        -> ptr_expA: Array of values that represent the exponents of those directions
            Example: [1,2]

        


    OUTPUTS:
        -> The result is an uint64_t with the following formula

                \sum{expA[i]*(order+1)^(dirA[i]-1)}

            Example: 144 = c_convToIndex([3,4],[1,2], 3)


    */
    // ************************************************************************************************

    uint64_t indx = index;

    uint8_t  i = 0;
    uint8_t  dir = 1;
    uint8_t  exp;
    

    while (indx != 0){

        exp  = indx%(order+1);
        indx = indx/(order+1);

        if(exp!=0){

            ptr_dirA[i] = dir;
            ptr_expA[i] = exp;
            i++; 

        }

        dir++;  

    }
    if (i<order){
        ptr_dirA[i] = 0;
        ptr_expA[i] = 0;
    }
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_binarySearchUI64(  uint64_t* ptr_indxArray, uint64_t indx,uint64_t  N){          
    /*
    c_binarySearchUI64( ptr_indxArray, indx, N):

    Function that applies binary search to find what is the position at which the 
    indx belongs in indxArray. However, if indx does not belong to indxArray, it will tell 
    at which position it must be inserted.

    INPUTS:
        
        -> ptr_indxArray[N]:   Array with indices, in ascending order. 
            Example: [1,  
                      4,
                      5,
                      6,
                      9,
                      20,
                      25,
                      45,
                      50]

        -> indx:    Value to seek in indxArray 
            Example: 5

        -> N:       Number of elements in indxArray
            Example: 9

    OUTPUTS:
        -> The result is the index that indicates where the indx value exist in indxArray,
        or where should it be inserted
            Example: 2 = c_binarySearchUI64( ptr_indxArray, indx, N)

    */ 
    // ************************************************************************************************

    
    uint64_t min_i = 0;
    uint64_t max_i = N;
    uint64_t pos = min_i+(max_i-min_i)/2; // Automatically truncates the result.

    // Case length 0.
    if(min_i==max_i){

        return 0;

    }
    
    // !!!!! Not robust enough to handle order 1!!!!
    if (indx <= ptr_indxArray[min_i]){
        
        return min_i;

    }else if (indx > ptr_indxArray[max_i-1]){

        return max_i;
    }
    
    while(  (max_i-min_i)>2  ){

        
        if (indx>ptr_indxArray[pos]){

            min_i = pos;

        }else{

            max_i = pos+1;

        }
        // Convert both arrays to 

        pos = min_i+(max_i-min_i)/2 ;

    }

    return pos;


}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
uint64_t c_multDirections_dH(uint64_t indx1m1, uint64_t indx2m1, directionHelper* p_dH, 
                             uint8_t* error ){
    /*
    c_multDirections(ptr_dirA1, ptr_expA2, ptr_dirA1, ptr_expA2, order):

    Function that multiplies two directions i,j.

    INPUTS:

        -> indx1m1:   Index of direction that will be multiplied

        -> indx2m1:   Index of direction that will be multiplied

        ->  p_dH:     Address of the direction helper for indx1m1 and indx2xm1.
            Example: 2

        -> error: Address of error flag to get the multiplication validity. 0:   valid multiplication.
                                                                            1: invalid multiplication.


    OUTPUTS:
        ->  The result is an uint64_t which corresponds to the index of the 
            multiplied indices.


    */
    // ************************************************************************************************

    // check thee order of the numbers
    uint64_t index = 0;
    
    // Get once the pointers
    uint8_t  order = p_dH->order;
    uint16_t* ptr_dirA1 = &p_dH->p_dirA[indx1m1*order];
    uint8_t*  ptr_expA1 = &p_dH->p_expA[indx1m1*order];
    uint16_t* ptr_dirA2 = &p_dH->p_dirA[indx2m1*order];
    uint8_t*  ptr_expA2 = &p_dH->p_expA[indx2m1*order];
    uint16_t* ptr_mdirA1= p_dH->p_mdirA;
    uint8_t*  ptr_mexpA1= p_dH->p_mexpA;
    uint16_t* ptr_mdirA2= &p_dH->p_mdirA[order];
    uint16_t* ptr_mdirA3= &p_dH->p_mdirA[2*order];
    uint16_t* ptr_mapder= p_dH->p_mapder;


    uint8_t newOrder = c_sumUI8(ptr_expA1,order) + c_sumUI8(ptr_expA2,order);
    uint64_t index_1;
    uint64_t index_2;

    if( newOrder <= order ){

        // no notification required.
        (*error) = 0;

        // Map the direction arrays.

        c_mapDirArray( ptr_dirA1, ptr_dirA2, order, ptr_mdirA1, ptr_mdirA2, ptr_mapder);

        // Find index values

        index_1 =  c_convToIndex(ptr_mdirA1,ptr_expA1, order);
        index_2 =  c_convToIndex(ptr_mdirA2,ptr_expA2, order);

        // Find the resulting direction after multiplication

        index_1 +=  index_2;

        // Retrieve the directions of the multiplied index.
        c_convToDirExp(index_1, order, ptr_mdirA1, ptr_mexpA1); 

        // remap the array to the original directions.
        c_reMapDirArray( ptr_mdirA1, ptr_mapder,  order,  ptr_mdirA1);

        // find the corresponding index of the result:
        index = c_binarySearch(  p_dH->p_dirA,  p_dH->p_expA,
                                   ptr_mdirA1,    ptr_mexpA1,  order,
                      p_dH->Ndir,  ptr_mdirA2,    ptr_mdirA3);

    }else{

        // Send back a signal to know the multiplication is not possible between this 
        // two directions.

        (*error) = 1;
    }

    return index;

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
uint64_t c_binarySearch_dH(  uint16_t* p_dirA,   uint8_t* p_expA,  directionHelper* p_dH){          
    /*
    dirBinarySearch( c_binarySearch( ptr_dirA, ptr_expA, dHelp):

    Applies the binary search to find what is the position at which the 
    pair dirs,exps exist on an array of size N that contains it.

    INPUTS:
        
        -> ptr_dirA:    Array of values that represent the directions of a number
            Example: [3,0]

        -> ptr_expA:    Array of values that represent the exponents of those directions
            Example: [1,0]

        -> dHelp:     Address of direction helper.


    OUTPUTS:
        -> The result is the index that indicates the sequential order at which the dirA, expA occurs
        

            Example: For the values shown as examples in inputs (order 2),

                >> 5 = dirBinarySearch(...)

    NOTE: All arrays must come allocated.
    */ 
    // ************************************************************************************************

    
    uint64_t min_i = 0 ;
    uint64_t max_i = p_dH->Ndir;
    uint64_t pos = min_i+(max_i-min_i)/2 ; // Automatically truncates the result.

    uint64_t index_look;
    uint64_t index_array;

    uint8_t order = p_dH->order;
    uint16_t* p_mdirA1 = &p_dH->p_mdirA[    0];
    // uint16_t*  p_dirAh;   // view of helper's direction array
    // uint8_t*   p_expAh;   // view of helper's exponent array
    uint16_t* p_mdirA2 = &p_dH->p_mdirA[order];


    // Map the direction arrays.
    mapDirArrayNoMapderFast( p_dH->p_dirA, p_dirA, order, 
                        p_mdirA1, p_mdirA2);

    // ptr_mdirA2 -> The arrays to be looked into dirArray
    index_look  = c_convToIndex(p_mdirA2, p_expA, order);
    
    // !!!!! Not robust enough to handle order 1!!!!
    if (index_look == 1){
        
        return 0;

    }
    
    while(  (max_i-min_i)>2  ){

        // Map the direction arrays.
        mapDirArrayNoMapderFast( &p_dH->p_dirA[pos*order], p_dirA, order, 
                                p_mdirA1, p_mdirA2); 

        // ptr_mdirA1 -> Global array
        index_array = c_convToIndex(p_mdirA1, &p_dH->p_expA[pos*order], order);

        // ptr_mdirA2 -> The arrays to be looked into dirArray
        index_look  = c_convToIndex(p_mdirA2, p_expA, order);

        if (index_look > index_array){

            min_i = pos;

        }else{

            max_i = pos+1;

        }
        
        pos = min_i+ (max_i-min_i) /2 ;
    }

    return pos;


}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
uint64_t c_binarySearch(  uint16_t* ptr_dirArray, uint8_t* ptr_expArray,
                          uint16_t* ptr_dirA,     uint8_t* ptr_expA,     uint8_t order,
                          uint64_t  N, uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2){          
    /*
    c_binarySearch( c_binarySearch(  ptr_dirArray, ptr_expArray,
                                     ptr_dirA,     ptr_expA,      order,
                                     N,            ptr_mdirA1,    ptr_mdirA2):

    Function applies the binary search to find what is the position at which the 
    pair dirs,exps exist on an array of size N that contains it.

    INPUTS:
        
        -> ptr_dirArray[N,order]:   Array of all possible combinations of directions 
                                    for m number of base directions.
            Example: [1,0,   
                      1,0,
                      2,0,
                      1,2,
                      2,0,
                      3,0,   // for m=3
                      1,3,
                      2,3,
                      3,0]

        -> ptr_expArray[N,order]:   Array of all possible combinations of exponents, 
                                    associated to those directions.
            Example: [1,0,
                      2,0,   
                      1,0,
                      1,1,   // the sum of each row should always be \leq order.
                      2,0,
                      1,0,
                      1,1,
                      1,1,
                      2,0]


        -> ptr_dirA:    Array of values that represent the directions of a number
            Example: [3,0]

        -> ptr_expA:    Array of values that represent the exponents of those directions
            Example: [1,0]

        -> order:       Order of the OTI number that is being used.
            Example: 2 (as in the example) 

        -> N:           number of columns of the dirArray and expArray.
            Example: 9 

        -> ptr_mdirA1,ptr_mdirA2: Allocated arrays to handle the algorithm.


    OUTPUTS:
        -> The result is the index that indicates where the combination dirA,expA occurs:

            Example: For the values shown as examples in inputs,

                >> 5 = c_binarySearch(...)

    NOTE: All arrays must come allocated.
    */ 
    // ************************************************************************************************

    
    uint64_t min_i = 0 ;
    uint64_t max_i = N;
    uint64_t pos = min_i+(max_i-min_i)/2 ; // Automatically truncates the result.

    uint64_t index_look;
    uint64_t index_array;

    // Map the direction arrays.
    c_mapDirArrayNoMapder( &ptr_dirArray[0], ptr_dirA, order, ptr_mdirA1, ptr_mdirA2);

    // ptr_mdirA2 -> The arrays to be looked into dirArray
    index_look  = c_convToIndex(ptr_mdirA2, ptr_expA, order);

    
    // !!!!! Not robust enough to handle order 1!!!!
    if (index_look == 1){
        
        return 0;

    }
    
    while(  (max_i-min_i)>2  ){

        // Map the direction arrays.
        c_mapDirArrayNoMapder( &ptr_dirArray[pos*order], ptr_dirA, order, ptr_mdirA1, ptr_mdirA2);

        // ptr_mdirA1 -> Global array
        index_array = c_convToIndex(ptr_mdirA1, &ptr_expArray[pos*order], order);

        // ptr_mdirA2 -> The arrays to be looked into dirArray
        index_look  = c_convToIndex(ptr_mdirA2, ptr_expA, order);

        if (index_look>index_array){

            min_i = pos;

        }else{

            max_i = pos+1;

        }
        // Convert both arrays to 

        pos = min_i+(max_i-min_i)/2 ;

    }

    return pos;


}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void* c_malloc_ptr(uint64_t numberOfElements, uint64_t sizeOfElement){
  /*
    c_malloc_ptr( nelems,  sizeOfElement):

    Function that allocates memory in the system according to the given data.

    INPUTS:
        
        -> numberOfElements Number of elements to be allocated.

        -> sizeOfElement:  Size in bytes of each element to be allocated.

    OUTPUTS:
        -> pointer with the memory allocated

    NOTE: If the memory is not allocated, then the program exits and prints an error message in console.
    */ 
    // ************************************************************************************************
    
    void* res;

    res = malloc( numberOfElements * sizeOfElement);
    
    if (res == NULL){
        printf("-MemoryError-: Can not allocate %llu elements of size %llu for a total of %llu bytes.\n",
            numberOfElements, sizeOfElement, numberOfElements*sizeOfElement );
        exit(1);
    }

    return res;

}  
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void c_free_ptr(void** ptrAddress){
  /*
    cc_free_ptr( ptr ):

    Frees memory and sets the value of the pointer to NULL.

    INPUTS:
        
        -> ptrAddress: Address of the pointer.

    
    */ 
    // ************************************************************************************************
    
    if(*ptrAddress != NULL){

        free( *ptrAddress );
        *ptrAddress = NULL; 

    }    

}  
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// -----------------------------------     END FUNCTIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
