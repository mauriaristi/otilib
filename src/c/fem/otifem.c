#include "oti/otifem.h"

// ----------------------------------------------------------------------------------------------------
// ---------------------------------     OTIFEM FUNCTIONS     -----------------------------------------
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_defFunctFrom_otiFunc(sotiarray_t* p_arr1, uint64_t derIndx, elemProps_t* elem, 
    femarray_t* p_arrRes, directionHelper* p_dH) {
    /*
    c_fem_defFunctFrom_otiFunc( p_arr1, derIndx, elem, p_arrRes, p_dH)

    Define a constant function from a real number.

    INPUTS:

        -> p_arr1:     (1 x nbasis) otinum values of the function.

        -> derIndx:    Basis Id that defines this function.

        -> elem:       Element that interpolates the data.

        -> p_arrRes:   (1 x 1) Address of the array that holds the result.

        -> p_dH:       Direction helper


    OUTPUTS: 
        
        -> Assigns the result .

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    uint64_t i,k;
    sotinum_t tmpcnt, tmp1, tmp2, tmp3;    

    for (k=0; k<elem->nIntPts; k++){
        
        // Initialize counter as 0.
        c_soti_createEmpty(&tmpcnt,0,elem->otiorder);

        for ( i=0; i<elem->nbasis ; i++){
     
            // tmp3 = p_arr1->p_data[i] * &elem->p_basis[0,i,k];
            c_femarray_getItem_ijk(&elem->p_basis[derIndx],0,i,k,&tmp1);
            c_soti_mul( &p_arr1->p_data[i], &tmp1, &tmp3, p_dH);

            // tmpcnt += tmp3;
            tmp2 = tmpcnt;
            c_soti_sum( &tmp2, &tmp3, &tmpcnt, p_dH);
            
            c_soti_free(&tmp2);

            c_soti_free(&tmp3);
        }

        c_femarray_setItem_ijk(&tmpcnt,0,0,k,p_arrRes);

        // c_soti_free(&tmpcnt);

    }
    
    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_defFunctFrom_oti(sotinum_t* num, uint64_t derIndx, elemProps_t* elem, femarray_t* p_arrRes,
    directionHelper* p_dH) {
    /*
    c_fem_defFunctFrom_R( num, derIndx, elem, p_arrRes, p_dH)

    Define a constant function from a real number.

    INPUTS:

        -> num:        otinum value of the constant function.

        -> derIndx:    Basis Id that defines this function.

        -> elem:       Element that interpolates the data.

        -> p_arrRes:   (1 x 1) Address of the array that holds the result.

        -> p_dH:       Direction helper


    OUTPUTS: 
        
        -> Assigns the result .

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    uint64_t i,k;
    sotinum_t tmpcnt,tmp1,tmp2;


    // 
    // printf("Inside Function definition.\n");
    for (k=0; k<elem->nIntPts; k++){
        // printf("   Creating counter.\n");
        // Initialize counter as 0.
        c_soti_createEmpty(&tmpcnt,0,elem->otiorder);
     
        for ( i=0; i<elem->nbasis ; i++){
            // printf("       Geting  basis number %llu and for integration point %llu.\n",i,k);
            c_femarray_getItem_ijk(&elem->p_basis[derIndx],0,i,k,&tmp1);

            tmp2 = tmpcnt;
            // printf("       Sum  the elements.\n");
            c_soti_sum( &tmp2, &tmp1, &tmpcnt, p_dH);
            
            // printf("       Free tmp2.\n");
            c_soti_free(&tmp2);
        }
        

        // printf("   Multiply the given number times the sum.\n");

        c_soti_mul(&tmpcnt,num,&tmp2,p_dH);

        // printf("   Set position 0, 0, %llu.\n",k);

        c_femarray_setItem_ijk(&tmp2,0,0,k,p_arrRes);


        // printf("   Free tmpcnt.\n");
        c_soti_free(&tmpcnt);

    }
    // printf("Exit.\n");
    
    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_defFunctFrom_R(double num, uint64_t derIndx, elemProps_t* elem, femarray_t* p_arrRes,
    directionHelper* p_dH) {
    /*
    c_fem_defFunctFrom_R( num, derIndx, elem, p_arrRes, p_dH)

    Define a constant function from a real number.

    INPUTS:

        -> num:        Real value of the constant function.

        -> derIndx:    Basis Id that defines this function.

        -> elem:       Element that interpolates the data.

        -> p_arrRes:   (1 x 1) Address of the array that holds the result.

        -> p_dH:       Direction helper


    OUTPUTS: 
        
        -> Assigns the result .

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    uint64_t i,k;
    sotinum_t tmpcnt,tmp1,tmp2;


    

    for (k=0; k<elem->nIntPts; k++){

        // Initialize counter as 0.
        c_soti_createEmpty(&tmpcnt,0,elem->otiorder);
     
        for ( i=0; i<elem->nbasis ; i++){
     
            c_femarray_getItem_ijk(&elem->p_basis[derIndx],0,i,k,&tmp1);

            tmp2 = tmpcnt;

            c_soti_sum( &tmp2, &tmp1, &tmpcnt, p_dH);
            
            c_soti_free(&tmp2);
        }
        
        c_soti_mulf(&tmpcnt,num,&tmp2);

        c_femarray_setItem_ijk(&tmp2,0,0,k,p_arrRes);

        c_soti_free(&tmpcnt);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
int64_t c_fem_defineSpatial( elemProps_t* elem, uint16_t derFlags, directionHelper* p_dH) {
    /*
    c_fem_computeJacobian( elem, xcoords, ycoords, zcoords, nDimAnalysis, p_arrRes, p_dH) 

    Initialize the element Basis functions for the specified order of integration.

    INPUTS:

        -> elem:   Address of the structure that holds the element information.

        -> xcoords: Coordinates.
        
        -> ycoords: Coordinates.
        
        -> zcoords: Coordinates.

        -> nDimAnalysis: Number of dimension of the analysis. May differ from the number of 
                         dimensions of the element, however cannot be less than that.

        -> p_arrRes: list of result holders. Must come allocated.

        -> p_dH: Direction helper       


    OUTPUTS: 
        
        -> Assigns to elem the corresponding arrays with the correct data input.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    int64_t derId;
    uint64_t i,j;
    uint64_t k;
    sotinum_t tmp1,tmp2, tmpcntx, tmpcnty;
    double der;


    for( i = 0; i<elem->nder; i++){  // Do for each possible derivative.

        // 0. basisN  
        // 1. basisNx 
        // 2. basisNxx
        // 3. basisNy 
        // 4. basisNxy
        // 5. basisNyy
        // 6. basisNz 
        // 7. basisNxz
        // 8. basisNyz
        // 9. basisNzz
        derId = i+basisN;


        if(       (derId == basisN  ) && (derFlags & 1   ) ){
            
            for (j=0; j< elem-> nbasis; j++){
                
                for(k=0; k< elem->nIntPts; k++){

                    c_darray_getItem(&elem->p_evalBasis[i],j,k, &der);

                    c_soti_createFromReal(der,&tmp1,elem->otiorder);

                    c_femarray_setItem_ijk(&tmp1,0,j,k,&elem->p_basis[i]);
                
                }

            }

        }else if( (derId == basisNx ) && (derFlags & 1<<1) ){

            for (j=0; j< elem-> nbasis; j++){
                
                for(k=0; k< elem->nIntPts; k++){
                    //                    basisNa (dN/dxi)
                    c_darray_getItem(&elem->p_evalBasis[derNa-derN],j,k, &der); //ok

                    //                                From basisNx    from dim 1  
                    c_femarray_getItem_ijk(&elem->Jinv,       0    ,     0       , k, &tmp2);

                    c_soti_mulf(&tmp2,der,&tmpcntx);


                    if (elem->ndim >= 2){
                        //                      basisNb (dN/deta)
                        c_darray_getItem(&elem->p_evalBasis[derNb-derN],j,k, &der);

                                                    //    From basisNx    from dim 2  
                        c_femarray_getItem_ijk(&elem->Jinv,       0    ,     1       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                        


                    }

                    if (elem->ndim >= 3){

                        //                      basisNb (dN/dchi)
                        c_darray_getItem(&elem->p_evalBasis[derNc-derN],j,k, &der);

                                                    //    From basisNx    from dim 3  
                        c_femarray_getItem_ijk(&elem->Jinv,       0    ,     2       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                    

                    }

                    c_femarray_setItem_ijk(&tmpcntx,0,j,k,&elem->p_basis[i]);
                
                }

            }

        }else if( (derId == basisNxx) && (derFlags & 1<<2) ){
            // Not sure what to do yet

        }else if( (derId == basisNy ) && (derFlags & 1<<3) ){

            // Check that this is in dimension analysis.

            for (j=0; j< elem-> nbasis; j++){
                
                for(k=0; k< elem->nIntPts; k++){
                    //                    basisNa (dN/dxi)
                    c_darray_getItem(&elem->p_evalBasis[derNa-derN],j,k, &der);

                    //                                From basisNy    from dim 1  
                    c_femarray_getItem_ijk(&elem->Jinv,       1    ,     0       , k, &tmp2);

                    c_soti_mulf(&tmp2,der,&tmpcntx);


                    if (elem->ndim >= 2){
                        //                      basisNb (dN/deta)
                        c_darray_getItem(&elem->p_evalBasis[derNb-derN],j,k, &der);

                                                    //    From basisNy    from dim 2  
                        c_femarray_getItem_ijk(&elem->Jinv,       1    ,     1       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                        


                    }

                    if (elem->ndim >= 3){

                        //                      basisNb (dN/dchi)
                        c_darray_getItem(&elem->p_evalBasis[derNc-derN],j,k, &der);

                                                    //    From basisNy    from dim 3  
                        c_femarray_getItem_ijk(&elem->Jinv,       1    ,     2       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                    

                    }

                    c_femarray_setItem_ijk(&tmpcntx,0,j,k,&elem->p_basis[i]);
                
                }

            }

        }else if( (derId == basisNxy) && (derFlags & 1<<4) ){
            // Not sure what to do yet

        }else if( (derId == basisNyy) && (derFlags & 1<<5) ){
            // Not sure what to do yet

        }else if( (derId == basisNz ) && (derFlags & 1<<6) ){

            // Check that this is in dimension analysis.

            for (j=0; j< elem-> nbasis; j++){
                
                for(k=0; k< elem->nIntPts; k++){
                    //                    basisNa (dN/dxi)
                    c_darray_getItem(&elem->p_evalBasis[derNa-derN],j,k, &der);

                    //                                From basisNz    from dim 1  
                    c_femarray_getItem_ijk(&elem->Jinv,       2    ,     0       , k, &tmp2);

                    c_soti_mulf(&tmp2,der,&tmpcntx);


                    if (elem->ndim >= 2){
                        //                      basisNb (dN/deta)
                        c_darray_getItem(&elem->p_evalBasis[derNb-derN],j,k, &der);

                        //                                From basisNz    from dim 2  
                        c_femarray_getItem_ijk(&elem->Jinv,       2    ,     1       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                        


                    }

                    if (elem->ndim >= 3){

                        //                      basisNb (dN/dchi)
                        c_darray_getItem(&elem->p_evalBasis[derNc-derN],j,k, &der);

                        //                                From basisNz    from dim 3  
                        c_femarray_getItem_ijk(&elem->Jinv,       2    ,     2       , k, &tmp2);

                        c_soti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        c_soti_sum( &tmp2, &tmpcnty, &tmpcntx, p_dH);

                        c_soti_free(&tmp2);
                        c_soti_free(&tmpcnty);                    

                    }

                    c_femarray_setItem_ijk(&tmpcntx,0,j,k,&elem->p_basis[i]);
                
                }

            }

        }else if( (derId == basisNxz) && (derFlags & 1<<7) ){
            // Not sure what to do yet

        }else if( (derId == basisNyz) && (derFlags & 1<<8) ){
            // Not sure what to do yet

        }else if( (derId == basisNzz) && (derFlags & 1<<9) ){
            // Not sure what to do yet

        }
        
    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_computeJacobian( elemProps_t* elem, sotiarray_t* xcoords, sotiarray_t* ycoords,
                               sotiarray_t* zcoords, directionHelper* p_dH) {
    /*
    c_fem_computeJacobian( elem, xcoords, ycoords, zcoords, p_dH) 

    Initialize the element Basis functions for the specified order of integration.

    INPUTS:

        -> elem:   Address of the structure that holds the element information.

        -> xcoords: (ncoords x 1) Coordinates.
        
        -> ycoords: (ncoords x 1) Coordinates.
        
        -> zcoords: (ncoords x 1) Coordinates.

        -> nDimAnalysis: Number of dimension of the analysis. May differ from the number of 
                         dimensions of the element, however cannot be less than that.

        -> p_arrRes: Result holder. Must come allocated. shape: (nDimAnalysis x nDimElement)

        -> p_dH: Direction helper       


    OUTPUTS: 
        
        -> Assigns to elem the corresponding arrays with the correct data input.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    int64_t derId, posNa = derNa-derN, posNb = derNb-derN, posNc = derNc-derN;
    uint8_t intPt,elDim; // i, j
    uint64_t basis; // i, k
    sotinum_t tmp1,tmp2,tmp3, tmpcntx, tmpcnty, tmpcntz;
    double dN_dxi;

    
    for( intPt = 0; intPt<elem->nIntPts; intPt++){  // Do for each integration point intPt.

        for( elDim = 0; elDim<elem->ndim; elDim++){ // take the derivative with respect to each
                                                    // of the canonical coordinates of the element.

            if        (elDim == 0){

                derId = posNa;

            } else if (elDim == 1){

                derId = posNb;

            }else{ // (elDim == 2)

                derId = posNc;

            }

            // create tmpcntx = 0.
            c_soti_createEmpty(&tmpcntx,0,elem->otiorder); 

            if (elem->nDimAnalysis >= 2){
                // create tmpcnty = 0.
                c_soti_createEmpty(&tmpcnty,0,elem->otiorder); 
            }
            
            if (elem->nDimAnalysis >= 3){
                // create tmpcntz = 0.
                c_soti_createEmpty(&tmpcntz,0,elem->otiorder); 
            }



            for( basis = 0; basis<elem->nbasis; basis++){

                // compute for analysis dimension 1
                // Extract the coordinate for the corresponding basis.
                c_sotiarray_getItem(xcoords, basis, 0, &tmp1); 

                // get the derivative of basis i with respect to elDim
                c_darray_getItem( &elem->p_evalBasis[derId], basis, intPt, &dN_dxi);

                // multiply coordinate times derivative dN/da
                c_soti_mulf(&tmp1,dN_dxi,&tmp2);

                // Sum the result to the accumulator tmpcntx
                tmp3 = tmpcntx;
                c_soti_sum(&tmp3,&tmp2,&tmpcntx,p_dH);

                // Free temps.
                c_soti_free(&tmp3);
                c_soti_free(&tmp2);

                if (elem->nDimAnalysis >= 2){

                    // compute for analysis dimension 2
                    c_sotiarray_getItem(ycoords, basis, 0, &tmp1); 

                    // multiply coordinate times derivative dN/db
                    c_soti_mulf(&tmp1,dN_dxi,&tmp2);

                    // Sum the result to the accumulator tmpcnty
                    tmp3 = tmpcnty;
                    c_soti_sum(&tmp3,&tmp2,&tmpcnty,p_dH);

                    // Free temps.
                    c_soti_free(&tmp3);
                    c_soti_free(&tmp2);

                }

                if (elem->nDimAnalysis >= 3){
                    // compute for analysis dimension 3
                    c_sotiarray_getItem(zcoords, basis, 0, &tmp1); 

                    // multiply coordinate times derivative dN/dc
                    c_soti_mulf(&tmp1,dN_dxi,&tmp2);

                    // Sum the result to the accumulator tmpcntz
                    tmp3 = tmpcntz;
                    c_soti_sum(&tmp3,&tmp2,&tmpcntz,p_dH);

                    // Free temps.
                    c_soti_free(&tmp3);
                    c_soti_free(&tmp2);
                }

            }

            // set element of the result array:
            c_femarray_setItem_ijk(    &tmpcntx, elDim, 0, intPt, &elem->J);

            if (elem->nDimAnalysis >= 2){
                // create an oti zero to get otinum = 0 .
                c_femarray_setItem_ijk(&tmpcnty, elDim, 1, intPt, &elem->J);
            }
            
            if (elem->nDimAnalysis >= 3){
                // create an oti zero to get otinum = 0 .
                c_femarray_setItem_ijk(&tmpcntz, elDim, 2, intPt, &elem->J);
            }

    
        }
    
    }

    // Here, Jacobian is already computed. Now, the inverse and determinant can be computed.

    if (elem->ndim == elem->nDimAnalysis){
        
        c_femarray_invert(&elem->J, &elem->Jinv, p_dH);
        c_femarray_det(   &elem->J, &elem->Jdet, p_dH);

        for ( intPt=0; intPt< elem->nIntPts; intPt++){
            
            c_femarray_getItem_ijk(&elem->Jdet,0,0,intPt,&tmp1);
            
            c_soti_mulf(&tmp1,elem->p_intWeights.p_data[intPt],&tmp2);

            // for (i=0; i<tmp2.size; i++){
            //     if( tmp2.p_indx[i] != 0 ){
            //         tmp2.p_coefs[i] = 0.0;
            //     }
            // }

            c_femarray_setItem_ijk(&tmp2,0,0,intPt,&elem->p_detWeights);

            
        }

    } else {

        if (elem->ndim == 0){

            c_soti_createFromReal( 1.0, &tmp1, elem->otiorder);
            c_femarray_setItem_ijk(&tmp1,0,0,0,&elem->p_detWeights);

        } else if (elem->ndim == 1){

            // sqrt( (dx/dxi)^2 + (dy/dxi)^2 + (dz/dxi)^2 )

            // Loop for every integration point
            for ( intPt=0; intPt< elem->nIntPts; intPt++){

                // initialize counter
               c_soti_createEmpty(&tmpcntx, 0, elem->otiorder); 


                // get dx/dxi
                c_femarray_getItem_ijk(&elem->J , 0, 0, intPt,&tmp1);

                // do (dx/dxi)^2
                c_soti_ipowfast(&tmp1,2,&tmp2,p_dH);

                // sum to counter
                tmp3 = tmpcntx;
                c_soti_sum( &tmp2, &tmp3, &tmpcntx, p_dH);

                c_soti_free(&tmp2);
                c_soti_free(&tmp3);

                if (elem->nDimAnalysis >= 2){
                    // get dy/dxi
                    c_femarray_getItem_ijk(&elem->J , 0, 1, intPt, &tmp1);

                    // do (dy/dxi)^2
                    c_soti_ipowfast(&tmp1,2,&tmp2,p_dH);

                    // sum to counter
                    tmp3 = tmpcntx;
                    c_soti_sum(&tmp2,&tmp3,&tmpcntx,p_dH);

                    c_soti_free(&tmp2);
                    c_soti_free(&tmp3);

                }

                if (elem->nDimAnalysis >= 3){

                    // get dz/dxi
                    c_femarray_getItem_ijk(&elem->J , 0, 2, intPt, &tmp1);

                    // do (dz/dxi)^2
                    c_soti_ipowfast(&tmp1,2,&tmp2,p_dH);

                    // sum to counter
                    tmp3 = tmpcntx;
                    c_soti_sum(&tmp2,&tmp3,&tmpcntx,p_dH);

                    c_soti_free(&tmp2);
                    c_soti_free(&tmp3);

                }

                // counter = sqrt(counter)
                c_soti_sqrt( &tmpcntx, p_dH, &tmp2);
                c_soti_free( &tmpcntx);

                // Multiply weight times the result.
                c_soti_mulf(&tmp2,elem->p_intWeights.p_data[intPt],&tmp1);
                c_soti_free(&tmp2);
                
                // for (i=0; i<tmp2.size; i++){
                //     if( tmp2.p_indx[i] != 0 ){
                //         tmp2.p_coefs[i] = 0.0;
                //     }
                // }
                // set the element with the result 
                c_femarray_setItem_ijk(&tmp1,0,0,intPt,&elem->p_detWeights);

                // Inverse is not determined,  yet.

            }

        // } else if (elem->ndim == 2){   // When 3D is supported
        //     //
        //     // Cross product between these two vectors.
        //     //                                                   
        //     //       ||                              ||          
        //     //       ||  | dx/dxi |      | dx/deta | ||          
        //     //       ||  |        |      |         | ||          
        //     //       ||  | dy/dxi |   x  | dy/deta | ||          
        //     //       ||  |        |      |         | ||          
        //     //       ||  | dz/dxi |      | dz/deta | ||          
        //     //       ||  |        |      |         | ||          
        //     //       ||                              ||          
        //     //











        }


    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_unInitElement(elemProps_t* elem) {
    /*
    c_fem_initElement(uint64_t order, elemProps_t* elem) 

    Initialize the element Basis functions for the specified order of integration.

    INPUTS:

        -> order:    Order of polynomial.

        -> elem:   Address of the structure that holds the element information.


    OUTPUTS: 
        
        -> Assigns to elem the corresponding arrays with the correct data input.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    int64_t derId;

    if (elem->isInit != 0){
        // Get the integration points and integration weights.
    
        c_darray_free(&elem->p_intPoints);
        c_darray_free(&elem->p_intWeights);
        
        elem->nIntPts = 0;

        // Loop through all derivatives
        for(derId = 0; derId<elem->nder; derId++){
            
            // Allocate new array
            c_darray_free(&elem->p_evalBasis[derId]);
            c_femarray_free(&elem->p_basis[ derId ]);

        }

        c_femarray_free(&elem->J   );

        
        c_femarray_free(&elem->Jinv);
        c_femarray_free(&elem->p_detWeights);
        c_femarray_free(&elem->Jdet);
        

        
        
        c_free_ptr((void**)&elem->p_evalBasis);
        c_free_ptr((void**)&elem->p_basis);
        elem->isInit       = 0; // Lower flag of initialization.
        elem->nDimAnalysis = 0;
        elem->otiorder     = 0;

        elem->p_evalBasis = NULL;
        elem->p_basis     = NULL;
    }
    
    

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_initElement(uint64_t order, uint8_t otiorder, uint8_t nDimAnalysis, elemProps_t* elem) {
    /*
    c_fem_initElement(uint64_t order, elemProps_t* elem) 

    Initialize the element Basis functions for the specified order of integration.

    INPUTS:

        -> order:    Order of polynomial.

        -> elem:   Address of the structure that holds the element information.


    OUTPUTS: 
        
        -> Assigns to elem the corresponding arrays with the correct data input.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    int64_t derId;
    uint64_t basisId;

    // Check first if the element is already initialized.
    if( elem->isInit == 0 ){
   
    
        // Get the integration points and integration weights.
        c_fem_integrationPoints(order, elem->geomBase, &elem->p_intPoints, &elem->p_intWeights);
        
        elem->nIntPts = elem->p_intPoints.nrows;


        elem->otiorder = otiorder;
        elem->nDimAnalysis = nDimAnalysis;


        elem->p_evalBasis = (darray_t*  )c_malloc_ptr(elem->nder,sizeof(darray_t  ));     
        elem->p_basis     = (femarray_t*)c_malloc_ptr(elem->nder,sizeof(femarray_t));

        if( elem->p_evalBasis == NULL || elem->p_basis == NULL ){
            printf("--- MemoryError ---\n");
            exit(1);
        }
        

        // Evaluate all basis functions at integration points.
        // Loop through all derivatives
        for(derId = 0; derId<elem->nder; derId++){

            // Allocate new array
            c_darray_createEmpty(&elem->p_evalBasis[derId], elem->nbasis, elem->nIntPts);

            // Loop through all basis functions.
            for(basisId = 0; basisId<elem->nbasis; basisId++){
                
                elem->f_basis(basisId, derId + derN, &elem->p_intPoints, NULL, &elem->p_evalBasis[derId]);
                

            }

            c_femarray_zeros(&elem->p_basis[ derId ],
                    1,elem->nbasis,0,0,elem->nIntPts,elem->otiorder);


        }


        // Allocate space for Jacobian, its inverse and determinant.
        c_femarray_zeros(&elem->J, MAX(elem->ndim,1),    elem->nDimAnalysis, 0, 0, elem->nIntPts, elem->otiorder);

        c_femarray_zeros(&elem->Jinv,elem->nDimAnalysis, MAX(elem->ndim,1),  0, 0, elem->nIntPts, elem->otiorder);

        c_femarray_zeros(&elem->Jdet,         1, 1, 0, 0, elem->nIntPts, elem->otiorder);
        
        c_femarray_zeros(&elem->p_detWeights, 1, 1, 0, 0, elem->nIntPts, elem->otiorder);

        
        elem->isInit = 1; // Raise flag of initialization.

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_integrateSOTIfunct(sotiarray_t* f_eval, darray_t* weights, sotinum_t* res,
                                 directionHelper* p_dH){
    /*
    c_fem_integrateSOTIfunct( f_eval, weights)

    Perform the numerical integration of the function.

    INPUTS:

        -> f_eval:    (nIntPoints x 1) Array of soti numbers with the evaluated sampling points 
                                       of the function.

        -> weights:   (nIntPoints x 1) Array of weights to evaluate the integral.

    OUTPUTS: 
        
        -> res:  sotinum that represents the result of the operation.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    double rtmp;
    uint64_t i, j = 0, nSamples = weights->nrows;

    sotinum_t sotitmp1, sotitmp2, sotitmp3;

    c_soti_createEmpty(&sotitmp3, 0, f_eval->order);

    // Note: This can be done in parallel.
    for ( i = 0; i < nSamples ; i++ ){

        // Get function evaluated at point i.
        c_sotiarray_getItem(f_eval,  i, j, &sotitmp1);
        
        // Get weight i.
        c_darray_getItem(weights,    i, j, &rtmp    );
        
        // Multiply weight times the function
        c_soti_mulf( &sotitmp1, rtmp, &sotitmp2 );

        // Sum to the temporal sum.
        sotitmp1 = sotitmp3;
        c_soti_sum( &sotitmp1, &sotitmp2, &sotitmp3, p_dH) ;

        c_soti_free( &sotitmp1 );
        c_soti_free( &sotitmp2 );

    }
    
    // Copy result.
    res[0] = sotitmp3;

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
int64_t c_fem_integrationPoints(uint64_t order, int64_t elementType, 
                                darray_t* coords, darray_t* weights){
    /*
    c_fem_integrationPoints(uint64_t order, int64_t elementType, double* coords) 

    Define the coordinates and weights for integration according to the type of element and 
    order of evaluation sought.

    INPUTS:

        -> order:    Order of integration.


        -> elementType:  Geometric Type of element. 
                         It can be: elLine, elTriangle, elQuadrangle,
                         elTetrahedra or elHexahedra.
    OUTPUTS: 
        
        -> coords:  Coordinates to evaluate the integral.

        -> weights: Weights to evaluate the integral.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    uint64_t i,j;
    uint64_t npoints, ndim;
    double a=0.0, b=0.0, c=0.0, w=0.0; 

    // Safely initialize the array.
    coords->ncols = 0;
    coords->nrows = 0;
    coords->size = 0;
    coords->p_data = NULL;

    weights->ncols = 0;
    weights->nrows = 0;
    weights->size = 0;
    weights->p_data = NULL;

    // Check if the elementType given is ok.
    if ( elementType < elNode || elementType > elHexahedra ){
        coords = NULL;
        return OTI_FEM_InvalidElementType;
    }

    // Depending on the element type, compute the data.
    if (elementType == elNode){
        npoints = 1;
        ndim = 1;

        c_darray_createEmpty(coords,npoints,ndim);
        c_darray_createEmpty(weights,npoints,1);

        c_darray_setItem(0.0,0,0,coords);
        c_darray_setItem(1.0,0,0,weights);

    } else if (elementType == elLine){
        
        uint64_t nIntPts = (order + 1)/2;
        // Line element.
        ndim = 1;
        if (nIntPts <= 1){ // Accepts 0 or 1.
            
            npoints = 1;
            c_darray_createEmpty(coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,1);

            // Point 0
            i = 0;
            a = 0.000000000000000;
            w = 2.000000000000000;
            i =  c_fem_addLineIntegrationPoints(1, i, a, w, coords, weights);


        } else if (nIntPts == 2) {

            npoints = 2;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0;
            a = 0.577350269189626;
            w = 1.000000000000000;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);
            

        } else if (nIntPts == 3) {

            npoints = 3;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.888888888888889;
            i =  c_fem_addLineIntegrationPoints(1, i, a, w, coords, weights); 

            a = 0.774596669241483; w = 0.555555555555556;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);


        } else if (nIntPts == 4) {

            npoints = 4;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0; 

            a = 0.861136311594053; w = 0.347854845137454;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.339981043584856; w = 0.652145154862546;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            

        } else if (nIntPts == 5) {

            npoints = 5;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.568888888888889;
            i =  c_fem_addLineIntegrationPoints(1, i, a, w, coords, weights);

            a = 0.906179845938664; w = 0.236926885056189;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.538469310105683; w = 0.478628670499366;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        } else if (nIntPts == 6) {

            npoints = 6;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0;

            a = 0.932469514203152; w = 0.171324492379170;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.661209386466265; w = 0.360761573048139;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.238619186083197; w = 0.467913934572691;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        } else if (nIntPts == 7) {

            npoints = 7;

            c_darray_createEmpty( coords,npoints,ndim);
            c_darray_createEmpty(weights,npoints,   1);

            // Point 0
            i = 0;
            a = 0.000000000000000; w = 0.417959183673469;
            i =  c_fem_addLineIntegrationPoints(1, i, a, w, coords, weights);

            a = 0.949107912342759; w = 0.129484966168870;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.741531185599394; w = 0.279705391489277;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.405845151377397; w = 0.381830050505119;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        } else if (nIntPts == 8) {

            npoints = 8;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 

            a = 0.960289856497536; w = 0.101228536290376;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.796666477413627; w = 0.222381034453374;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.525532409916329; w = 0.313706645877887;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.183434642495650; w = 0.362683783378362;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        } else if (nIntPts == 9) {

            npoints = 9;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 

            a = 0.000000000000000; w = 0.362683783378362;
            i =  c_fem_addLineIntegrationPoints(1, i, a, w, coords, weights);

            a = 0.968160239507626; w = 0.101228536290376;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.836031107326636; w = 0.222381034453374;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.613371432700590; w = 0.313706645877887;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.324253423403809; w = 0.362683783378362;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        } else {    // Order >= 10  

            npoints = 10;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 

            a = 0.973906528517172; w = 0.066671344308688;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.865063366688985; w = 0.149451349150581;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.679409568299024; w = 0.219086362515982;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.433395394129247; w = 0.269266719309996;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

            a = 0.148874338981631; w = 0.295524224714753;
            i =  c_fem_addLineIntegrationPoints(2, i, a, w, coords, weights);

        }

    } else if (elementType == elTriangle){
        
        // Triangular element .
        ndim = 2;

        if (order <= 1){ // Accepts 0 or 1.

            npoints = 1;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 1.000000000000000; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);

        } else if (order == 2){

            npoints = 3;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Points 0, 1, 2
            i = 0; 
            a = 0.666666666666667; b = 0.166666666666667; c = b;
            w = 0.333333333333333; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

        } else if (order == 3){

            npoints = 1+3;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w =-0.562500000000000; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);

            a = 0.600000000000000; b = 0.200000000000000; c = b;
            w = 0.520833333333333; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

        } else if (order == 4){

            npoints = 3+3;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0;
            a = 0.108103018168070; b = 0.445948490915965; c = b;
            w = 0.223381589678011; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.816847572980459; b = 0.091576213509771; c = b;
            w = 0.109951743655322; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);
            
        } else if (order == 5){

            npoints = 1+3+3;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.225000000000000; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);
            
            a = 0.059715871789770; b = 0.470142064105115; c = b;
            w = 0.132394152788506; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.797426985353087; b = 0.101286507323456; c = b;
            w = 0.125939180544827; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            
        } else if (order == 6){

            npoints = 3+3+6;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 

            a = 0.501426509658179; b = 0.249286745170910; c = b;
            w = 0.116786275726379; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.873821971016996; b = 0.063089014491502; c = b;
            w = 0.050844906370207; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.053145049844817; b = 0.310352451033784; c = 0.636502499121399;
            w = 0.082851075618374; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);
            
        } else if (order == 7){

            npoints = 1+3+3+6;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w =-0.149570044467682; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);
            
            a = 0.479308067841920; b = 0.260345966079040; c = b;
            w = 0.175615257433208; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.869739794195568; b = 0.065130102902216; c = b;
            w = 0.053347235608838; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.048690315425316; b = 0.312865496004874; c = 0.638444188569810;
            w = 0.077113760890257; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);
            
        } else if (order == 8){

            npoints = 1+3+3+3+6;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.144315607677787; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);
            
            a = 0.081414823414554; b = 0.459292588292723; c = b;
            w = 0.095091634267285; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.658861384496480; b = 0.170569307751760; c = b;
            w = 0.103217370534718; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.898905543365938; b = 0.050547228317031; c = b;
            w = 0.032458497623198; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.008394777409958; b = 0.263112829634638; c = 0.728492392955404;
            w = 0.027230314174435; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights); 



        } else if (order == 9){

            npoints = 1+3+3+3+3+6;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.097135796282799; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);
            
            a = 0.020634961602525; b = 0.489682519198738; c = b;
            w = 0.031334700227139; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.125820817014127; b = 0.437089591492937; c = b;
            w = 0.077827541004774; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.623592928761935; b = 0.188203535619033; c = b;
            w = 0.079647738927210; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.910540973211095; b = 0.044729513394453; c = b;
            w = 0.025577675658698; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.036838412054736; b = 0.221962989160766; c = 0.741198598784498;
            w = 0.043283539377289; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);

        
        } else {

            npoints = 1+3+3+6+6+6;

            c_darray_createEmpty( coords, npoints, ndim);
            c_darray_createEmpty(weights, npoints,    1);

            // Point 0
            i = 0; 
            a = 0.333333333333333; b = a; c = a;
            w = 0.090817990382754; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(1, i, a, b, c, w, coords, weights);
            
            a = 0.028844733232685; b = 0.485577633383657; c = b;
            w = 0.036725957756467; w *= 0.5;            
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.781036849029926; b = 0.109481575485037; c = b;
            w = 0.045321059435528; w *= 0.5;            
            i = c_fem_addTriangleIntegrationPoints(3, i, a, b, c, w, coords, weights);

            a = 0.141707219414880; b = 0.307939838764121; c = 0.550352941820999;
            w = 0.072757916845420; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);

            a = 0.025003534762686; b = 0.246672560639903; c = 0.728323904597411;
            w = 0.028327242531057; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);

            a = 0.009540815400299; b = 0.066803251012200; c = 0.923655933587500;
            w = 0.009421666963733; w *= 0.5;
            i = c_fem_addTriangleIntegrationPoints(6, i, a, b, c, w, coords, weights);

        }




    } else if (elementType == elQuadrangle){

        darray_t coord_tmp;
        darray_t weights_tmp;

        double w_tmp1 = 0.0;
        double w_tmp2 = 0.0;

        ndim = 2;

        // Call the solution for the corresponding 1D line element.
        c_fem_integrationPoints(order, elLine, &coord_tmp, &weights_tmp);

        npoints = coord_tmp.nrows*coord_tmp.nrows;

        c_darray_createEmpty( coords, npoints, ndim);
        c_darray_createEmpty(weights, npoints,    1);

        for ( i = 0; i < coord_tmp.nrows; i++ ){

            // Get the first weight.
            c_darray_getItem(   &coord_tmp, i, 0, &a      ) ;
            c_darray_getItem( &weights_tmp, i, 0, &w_tmp1 ) ;

            for ( j = 0; j < coord_tmp.nrows; j++ ){

                // Get the second weight.
                c_darray_getItem(   &coord_tmp, j, 0, &b      ) ;
                c_darray_getItem( &weights_tmp, j, 0, &w_tmp2 ) ;

                w = w_tmp1 * w_tmp2;
                
                c_darray_setItem( a, coord_tmp.nrows*i + j, 0, coords );
                c_darray_setItem( b, coord_tmp.nrows*i + j, 1, coords );
                c_darray_setItem( w, coord_tmp.nrows*i + j, 0, weights);

            }

        }

        c_darray_free(&coord_tmp);
        c_darray_free(&weights_tmp);

        
    // } else if (elementType == elTetrahedra){
        
    } else if (elementType == elHexahedra){

        darray_t coord_tmp;
        darray_t weights_tmp;

        uint64_t k = 0, currentIndex = 0 ;

        double w_tmp1 = 0.0;
        double w_tmp2 = 0.0;
        double w_tmp3 = 0.0;

        ndim = 3;
        
        // Call the solution for the corresponding 1D line element.
        c_fem_integrationPoints(order, elLine, &coord_tmp, &weights_tmp);

        // Go for all possible combinations for 

        npoints = coord_tmp.nrows * coord_tmp.nrows * coord_tmp.nrows;

        c_darray_createEmpty( coords, npoints, ndim);
        c_darray_createEmpty(weights, npoints,    1);

        for ( i = 0; i < coord_tmp.nrows; i++ ){

            // Get the first weight.
            c_darray_getItem(   &coord_tmp, i, 0, &a      ) ;
            c_darray_getItem( &weights_tmp, i, 0, &w_tmp1 ) ;

            for ( j = 0; j < coord_tmp.nrows; j++ ){

                // Get the second weight.
                c_darray_getItem(   &coord_tmp, j, 0, &b      ) ;
                c_darray_getItem( &weights_tmp, j, 0, &w_tmp2 ) ;

                for ( k = 0; k < coord_tmp.nrows; k++ ){

                    // Get the second weight.
                    c_darray_getItem(   &coord_tmp, k, 0, &c      ) ;
                    c_darray_getItem( &weights_tmp, k, 0, &w_tmp3 ) ;

                    w = w_tmp1 * w_tmp2 * w_tmp3;
                    
                    c_darray_setItem( a, currentIndex, 0, coords );
                    c_darray_setItem( b, currentIndex, 1, coords );
                    c_darray_setItem( c, currentIndex, 2, coords );
                    c_darray_setItem( w, currentIndex, 0, weights);

                    currentIndex+= 1;

                }

            }

        }

        c_darray_free(&coord_tmp);
        c_darray_free(&weights_tmp);
    
    } else {

        return OTI_FEM_NotImplemented;

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
uint64_t c_fem_addLineIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                           double a,  double w,
                                           darray_t* coords, darray_t* weights){
    /*
    c_fem_addTriangleIntegrationPoints( numberOfPermutations,  startPoint, 
                                        a, b,  c,  w,
                                        coords, weights)

    Permutations of the .


    INPUTS:

        -> numberOfPermutations: Number of permutations for the selected point. (1, 3 or 6)

        -> startPoint: Index of the starting point in the 

        -> a: Coordinate 

        -> w: Weight for this point

        -> coords:  ( ncoords x 1 ) Array to write the coordinates. Must come allocated.

        -> weights: ( ncoords x 1 ) Array to write the weights. Must come allocated.
    
    OUTPUTS: 

        -> Position after last element added. (startPoint + numberOfPermutations). Current positionAdded position

    */ 
    // ************************************************************************************************
    uint64_t i = 0 ,j = 0;

    if (numberOfPermutations == 1){
        // Point 1
        i = startPoint; 
        c_darray_setItem( a, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

    } else if (numberOfPermutations == 2){

        // Point 1
        i = startPoint; 
        c_darray_setItem(-a, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 2
        i+= 1; 
        c_darray_setItem( a, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

    }

    return i+1;
}   
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
uint64_t c_fem_addTriangleIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                           double a, double b, double c, double w,
                                           darray_t* coords, darray_t* weights){
    /*
    c_fem_addTriangleIntegrationPoints( numberOfPermutations,  startPoint, 
                                        a, b,  c,  w,
                                        coords, weights)

    Permutations of the .


    INPUTS:

        -> numberOfPermutations: Number of permutations for the selected point. (1, 3 or 6)

        -> startPoint: Index of the starting point in the 

        -> a: Area coordinate 1

        -> b: Area coordinate 2

        -> c: Area coordinate 3

        -> w: Weight for this configuration                      

        -> coords:  ( ncoords x 2 ) Array to write the coordinates. Must come allocated.

        -> weights: ( ncoords x 1 ) Array to write the weights. Must come allocated.
    
    OUTPUTS: 

        -> Position after last element added. (startPoint + numberOfPermutations). Current positionAdded position

    */ 
    // ************************************************************************************************
    uint64_t i=0,j=0;

    if (numberOfPermutations == 1){
        // Point 1
        i = startPoint; 
        j = 0; c_darray_setItem( b, i, j, coords);
        j = 1; c_darray_setItem( c, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

    } else if (numberOfPermutations == 3){

        // Point 1
        i = startPoint; 
        j = 0; c_darray_setItem(b, i, j, coords);
        j = 1; c_darray_setItem(b, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 2
        i+= 1; 
        j = 0; c_darray_setItem(a, i, j, coords);
        j = 1; c_darray_setItem(b, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 3
        i+= 1; 
        j = 0; c_darray_setItem(b, i, j, coords);
        j = 1; c_darray_setItem(a, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

    } else if (numberOfPermutations == 6){
        
        // Point 1
        i = startPoint; 
        j = 0; c_darray_setItem( b, i, j, coords);
        j = 1; c_darray_setItem( c, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 2
        i+= 1; 
        j = 0; c_darray_setItem( c, i, j, coords);
        j = 1; c_darray_setItem( b, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 3
        i+= 1; 
        j = 0; c_darray_setItem( a, i, j, coords);
        j = 1; c_darray_setItem( c, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 4
        i+= 1; 
        j = 0; c_darray_setItem( c, i, j, coords);
        j = 1; c_darray_setItem( a, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 5
        i+= 1; 
        j = 0; c_darray_setItem( a, i, j, coords);
        j = 1; c_darray_setItem( b, i, j, coords);
        c_darray_setItem( w, i, 0, weights);

        // Point 6
        i+= 1;
        j = 0; c_darray_setItem( b, i, j, coords);
        j = 1; c_darray_setItem( a, i, j, coords);
        c_darray_setItem( w, i, 0, weights); 
    }

    return i+1;
}   
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_QuadSerendP2_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_QuadSerendP2_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the serendipity 2D element.


    NODE NUMBERING:

                           (3)* *(6)* *(2) 
                            *           *
                            *           *
                           (7)         (5)
                            *           *
                            *           *
                           (0)* *(4)* *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, ..., 8. (N1, ..., N8)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN    , derNa  , derNaa
                        derNb   , derNab , derNbb
                        derNc   , derNac , 
                        derNbc  , derNcc ,  
                        

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     (ncoords x ndim) array with the  data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    SOURCE:
        
        -> http://www.pckingsford.com/cykchee/phd/chD.pdf

    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double xi, eta, evalBasis_i;

    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 7 ){
        printf("--- InvalidBaseId ---");
        exit(1);
        // return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        c_darray_getItem(coords,i,0,&xi);
        c_darray_getItem(coords,i,1,&eta);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0-xi)*(1.0-eta)*(1.+xi+eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(-1.+eta)*(2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(-1.+xi)*(xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.-eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.-xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(1-2.*xi-2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0+xi)*(1.0-eta)*(1.-xi+eta);  

            }else if (basisDer == derNa){

                evalBasis_i = 0.25*(-1.+eta)*(-2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.25*(1.+xi)*(-xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.-eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(-1-2.*xi+2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0+xi)*(1.0+eta)*(1.-xi-eta);  

            }else if (basisDer == derNa){

                evalBasis_i = 0.25*(1.+eta)*(2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.25*(1.+xi)*(xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(1+2.*xi+2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 3){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.25*(1.0-xi)*(1.0+eta)*(1.+xi-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.+eta)*(-2.*xi+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(-1.+xi)*(-xi+2.*eta); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.5*(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.5*(1.-xi); 

            }else if (basisDer == derNab){

                evalBasis_i = 0.25*(-1+2.*xi-2.*eta); 

            } else{

                evalBasis_i = 0.0;  
                
            }
            // =============================================================================
        }  else if (basisId == 4){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = xi*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = 0.5*(1.+xi)*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = (eta - 1.); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNab){

                evalBasis_i = xi; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 5){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0+xi)*(1.0+eta)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =-0.5*(1.+eta)*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -eta*(1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNbb){

                evalBasis_i = -(1.+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = -eta; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 6){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i =-xi*(1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.5*(1.+xi)*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = -(1.+eta); 

            }else if (basisDer == derNbb){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNab){

                evalBasis_i =-xi; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 7){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 0.5*(1.0-xi)*(1.0+eta)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.5*(1.+eta)*(-1.+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  eta*(-1.+xi); 

            }else if (basisDer == derNaa){

                evalBasis_i = 0.0; 

            }else if (basisDer == derNbb){

                evalBasis_i = (xi-1.); 

            }else if (basisDer == derNab){

                evalBasis_i = eta; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_QuadP1_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_QuadP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:

                           (3)* * * * *(2) 
                            *           *
                            *           *
                            *           *
                            *           *
                            *           *
                           (0)* * * * *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double xi, eta, evalBasis_i;
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 3 ){
        return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        c_darray_getItem(coords,i,0,&xi);
        c_darray_getItem(coords,i,1,&eta);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0-xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.0-eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(1.0-xi); 

            }else if (basisDer == derNab){

                evalBasis_i =  0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0+xi)*(1.0-eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.25*(1.0-eta); 

            }else if (basisDer == derNb){

                evalBasis_i = -0.25*(1.0+xi); 

            }else if (basisDer == derNab){

                evalBasis_i = -0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0+xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.25*(1.0+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  0.25*(1.0+xi); 

            }else if (basisDer == derNab){

                evalBasis_i =  0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 3){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.25*(1.0-xi)*(1.0+eta); 

            }else if (basisDer == derNa){

                evalBasis_i = -0.25*(1.0+eta); 

            }else if (basisDer == derNb){

                evalBasis_i =  0.25*(1.0-xi); 

            }else if (basisDer == derNab){ 

                evalBasis_i = -0.25; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_TriangP2_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_TriangP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the P1 2D element.

    
    NODE NUMBERING:

    (2)
     * *
     *   * 
    (5)   (4) 
     *       *
     *         *
    (0)* *(3)* *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. 
                       For this case, id = 0,1,2,3,4 or 5. (N1, N2, N3, N4, N5, N6)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.



    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double xi, eta, evalBasis_i;
    
    if ( basisId > 5 ){
        return OTI_FEM_InvalidBaseId;
    }

    

    for(i=0; i<ncoords; i++){
        
        c_darray_getItem(coords,i,0,&xi);
        c_darray_getItem(coords,i,1,&eta);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){
            // N1
            // Detect which derivative is being computed
            if (basisDer == derN){
                
                evalBasis_i = 2.*pow(eta,2.)+4.*eta*xi - 3.*eta + 2.*pow(xi,2.)-3.*xi+ 1.; 

            } else if (basisDer == derNa){

                evalBasis_i = 4.*eta + 4.*xi - 3.; 

            } else if (basisDer == derNb){

                evalBasis_i = 4.*eta + 4.*xi - 3.; 

            } else if (basisDer == derNaa){

                evalBasis_i = 4.; 

            }  else if (basisDer == derNab){

                evalBasis_i = 4.; 

            }  else if (basisDer == derNbb){

                evalBasis_i = 4.; 

            } else {

                evalBasis_i = 0.0;  // dN1/d everything else.
                
            }

        } else if (basisId == 1){
            // N2
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 2.*pow(xi,2.0)-xi; // N2 = xi

            }else if (basisDer == derNa){

                evalBasis_i = 4.*xi-1.; 

            } else if (basisDer == derNaa){

                evalBasis_i = 4.; 

            } else{

                evalBasis_i = 0.0;

            }

        } else if (basisId == 2){
            // N3
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 2.*pow(eta,2.0)-eta; 

            }else if (basisDer == derNb){

                evalBasis_i = 4.*eta-1.; 

            } else if (basisDer == derNbb){

                evalBasis_i = 4.; 

            } else{

                evalBasis_i = 0.0; // dN1/deta = 0.0 and everything else (if asked).

            }

        } else if (basisId == 3){
            // N4
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = - 4.*eta*xi - 4.*pow(xi,2.0) + 4.*xi; 

            }else if (basisDer == derNa){

                evalBasis_i =  - 4.*eta - 8.*xi + 4.; 

            } else if (basisDer == derNaa){

                evalBasis_i = -8.; 

            }else if (basisDer == derNb){

                evalBasis_i = - 4.*xi; 

            } else if (basisDer == derNab){

                evalBasis_i = -4.; 

            } else{

                evalBasis_i = 0.0; 

            }

        } else if (basisId == 4){
            // N5
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 4.*eta*xi ; 

            }else if (basisDer == derNa){

                evalBasis_i =  4.*eta ; 

            }else if (basisDer == derNb){

                evalBasis_i = 4.*xi; 

            } else if (basisDer == derNab){

                evalBasis_i = 4.; 

            } else{

                evalBasis_i = 0.0; 

            }

        }else if (basisId == 5){
            // N6
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = - 4.*eta*xi - 4.*pow(eta,2.0) + 4.*eta; 

            }else if (basisDer == derNb){

                evalBasis_i =  - 4.*xi - 8.*eta + 4.; 

            } else if (basisDer == derNbb){

                evalBasis_i = -8.; 

            }else if (basisDer == derNa){

                evalBasis_i = - 4.*eta; 

            } else if (basisDer == derNab){

                evalBasis_i = -4.; 

            } else{

                evalBasis_i = 0.0; 

            }

        }  

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------






// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_TriangP1_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_TriangP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the P1 2D element.


    NODE NUMBERING:

                           (2)
                            * *
                            *   * 
                            *     *  
                            *       *
                            *         *
                           (0)* * * * *(1)


    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1 or 2. (N1, N2, N3)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double xi, eta, evalBasis_i;
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 2 ){
        return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        c_darray_getItem(coords,i,0,&xi);
        c_darray_getItem(coords,i,1,&eta);
        
        // Detect which basis function is being computed: N1, N2, or N3.
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 1.0-xi-eta; // N1 = 1-xi-eta

            }else if (basisDer == derNa){

                evalBasis_i = -1.0; // dN1/dxi  = 1.0

            }else if (basisDer == derNb){

                evalBasis_i = -1.0; // dN1/deta  = 1.0

            } else{

                evalBasis_i = 0.0;  // dN1/d everything else.
                
            }

        } else if (basisId == 1){
            
            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = xi; // N2 = xi

            }else if (basisDer == derNa){

                evalBasis_i = 1.0; // dN2/dxi  = 1.0

            } else{

                evalBasis_i = 0.0; // dN2/deta = 0.0 and everything else (if asked).

            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = eta; // N3 = eta

            }else if (basisDer == derNb){

                evalBasis_i = 1.0; // dN3/deta  = 1.0

            } else{

                evalBasis_i = 0.0; // dN3/dxi = 0.0 and everything else.
                
            }

        } 

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_TriangP0_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_TriangP1_2Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the P1 2D element.

    NODE NUMBERING:
                            
                     *                    |           *
                     * *                  |           * *
                     *   *                            *   * 
                     *     *         <-- o r -->      *     *  
                     *  (0)  *                        *       *
                     *         *          |           *         *
                     * * * * * * *        |          (0)* * * * * *

    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0. (N1)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab     

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [ xi_1,      eta_1      ],
                         [ xi_2,      eta_2      ],
                                   ...             
                         [ xi_ncoord, eta_ncoord ] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords=coords->nrows;
    double  evalBasis_i;
    
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 1 ){
        return OTI_FEM_InvalidBaseId;
    }

    
    for(i=0; i<ncoords; i++){
                    
        // Detect which derivative is being computed
        if (basisDer == derN){

            evalBasis_i = 1.0; // N1 = xi

        } else{

            evalBasis_i = 0.0; // everything else (if asked).

        }

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_LineP2_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_LineP2_1Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:


                           (0)* *(2)* *(1)



    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [    xi_1   ],
                         [    xi_2   ],
                             ... 
                         [ xi_ncoord,] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords = coords->nrows;
    double xi, evalBasis_i;
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 2 ){
        return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        c_darray_getItem(coords,i,0,&xi);
        
        // Detect which basis function is being computed: N1, N2
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = -0.5*xi*(1.0-xi);

            }else if (basisDer == derNa){

                evalBasis_i = -0.5+xi;

            }else if (basisDer == derNaa){

                evalBasis_i = 1.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.5*xi*(1.0+xi); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.5+xi; 

            }else if (basisDer == derNaa){

                evalBasis_i = 1.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 2){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = (1.0-xi*xi); 

            }else if (basisDer == derNa){

                evalBasis_i = -2.0*xi; 

            }else if (basisDer == derNaa){

                evalBasis_i = -2.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------





// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_LineP1_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_LineP1_1Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:


                           (0)* * * * *(1)



    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [    xi_1   ],
                         [    xi_2   ],
                             ... 
                         [ xi_ncoord,] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords = coords->nrows;
    double xi, evalBasis_i;
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 1 ){
        return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){

        c_darray_getItem(coords,i,0,&xi);
        
        // Detect which basis function is being computed: N1, N2
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.5*(1.0-xi);

            }else if (basisDer == derNa){

                evalBasis_i = -0.5;

            } else{

                evalBasis_i = 0.0;  
                
            }

        } else if (basisId == 1){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i =  0.5*(1.0+xi); 

            }else if (basisDer == derNa){

                evalBasis_i =  0.5; 

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t c_fem_basisFunctions_N_PntP0_0Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis){
    /*
    c_fem_basisFunctions_N_PntP0_0Diso(  basisId,  basisDer,  ncoords, 
                                            ndim,     coords,    other_data,
                                            evalBasis) 

    Definition of basis functions for the quad P1 2D element.


    NODE NUMBERING:


                           (0)



    INPUTS:

        -> basisId:    Id of the basis to be evaluated. For this case, id = 0, 1, 2 or 3. (N1, N2, N3, N4)


        -> basisDer:  Id of the basis derivative to be computed. Possible values are:
                        derN   , derNaa , derNaz
                        derNa  , derNbb , derNbz
                        derNb  , derNcc , 
                        derNz  , derNab ,    

        -> ncoords:    Number of coordinates to be evaluated.

        -> ndim:       Number of dimensions of the evaluation. (might work for more general functions)
        
        -> coords:     Pointer with the data in the transformed space:
                       [ [    xi_1   ],
                         [    xi_2   ],
                             ... 
                         [ xi_ncoord,] ]

        -> other_data: Data that might be available for other computations.
    
    OUTPUTS: 

        -> evalBasis: Pointer with the result.

        -> uint64_t error_code: Code of error if any.

    */ 
    // ************************************************************************************************

    uint64_t i, ncoords = coords->nrows;
    double evalBasis_i;
    
    // Check if the baseId given exceeds the corresponding for this element.
    if ( basisId > 0 ){
        return OTI_FEM_InvalidBaseId;
    }

    for(i=0; i<ncoords; i++){
        
        // Detect which basis function is being computed: N1, N2
        if (basisId == 0){

            // Detect which derivative is being computed
            if (basisDer == derN){

                evalBasis_i = 1.0;

            } else{

                evalBasis_i = 0.0;  
                
            }

        }  

        c_darray_setItem( evalBasis_i, basisId, i, evalBasis);

    }

    return OTI_success;

}   
// ----------------------------------------------------------------------------------------------------




// ----------------------------------------------------------------------------------------------------
// -------------------------------     END OTIFEM FUNCTIONS     ---------------------------------------
// ----------------------------------------------------------------------------------------------------


