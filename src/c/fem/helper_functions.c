








// ****************************************************************************************************
int64_t fem_defFunctFrom_otiFunc(oarr_t* p_arr1, uint64_t derIndx, elemProps_t* elem, 
    feoarr_t* res, dhelpl_t dhl) {

    uint64_t i,k;
    otinum_t tmpcnt, tmp1, tmp2, tmp3;    

    for (k=0; k<elem->nIntPts; k++){
        
        // Initialize counter as 0.
        oti_createEmpty(&tmpcnt,0,elem->otiorder);

        for ( i=0; i<elem->nbasis ; i++){
     
            // tmp3 = p_arr1->p_data[i] * &elem->p_basis[0,i,k];
            feoarr_get_item_ijk(&elem->p_basis[derIndx],0,i,k,&tmp1);
            oti_mul( &p_arr1->p_data[i], &tmp1, &tmp3, dhl);

            // tmpcnt += tmp3;
            tmp2 = tmpcnt;
            oti_sum( &tmp2, &tmp3, &tmpcnt, dhl);
            
            oti_free(&tmp2);

            oti_free(&tmp3);
        }

        feoarr_setItem_ijk(&tmpcnt,0,0,k,res);

        // oti_free(&tmpcnt);

    }
    
    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
int64_t fem_defFunctFrom_oti(otinum_t* num, uint64_t derIndx, elemProps_t* elem, feoarr_t* res,
    dhelpl_t dhl) {

    uint64_t i,k;
    otinum_t tmpcnt,tmp1,tmp2;

    // printf("Inside Function definition.\n");
    for (k=0; k<elem->nIntPts; k++){
        // printf("   Creating counter.\n");
        // Initialize counter as 0.
        oti_createEmpty(&tmpcnt,0,elem->otiorder);
     
        for ( i=0; i<elem->nbasis ; i++){
            // printf("       Geting  basis number %llu and for integration point %llu.\n",i,k);
            feoarr_get_item_ijk(&elem->p_basis[derIndx],0,i,k,&tmp1);

            tmp2 = tmpcnt;
            // printf("       Sum  the elements.\n");
            oti_sum( &tmp2, &tmp1, &tmpcnt, dhl);
            
            // printf("       Free tmp2.\n");
            oti_free(&tmp2);
        }
        

        // printf("   Multiply the given number times the sum.\n");

        oti_mul(&tmpcnt,num,&tmp2,dhl);

        // printf("   Set position 0, 0, %llu.\n",k);

        feoarr_setItem_ijk(&tmp2,0,0,k,res);


        // printf("   Free tmpcnt.\n");
        oti_free(&tmpcnt);

    }
    // printf("Exit.\n");
    
    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
int64_t fem_defFunctFrom_R(double num, uint64_t derIndx, elemProps_t* elem, feoarr_t* res,
    dhelpl_t dhl) {
    /*
    

    */ 
    // ************************************************************************************************

    uint64_t i,k;
    otinum_t tmpcnt,tmp1,tmp2;    

    for (k=0; k<elem->nIntPts; k++){

        // Initialize counter as 0.
        oti_createEmpty(&tmpcnt,0,elem->otiorder);
     
        for ( i=0; i<elem->nbasis ; i++){
     
            feoarr_get_item_ijk(&elem->p_basis[derIndx],0,i,k,&tmp1);

            tmp2 = tmpcnt;

            oti_sum( &tmp2, &tmp1, &tmpcnt, dhl);
            
            oti_free(&tmp2);
        }
        
        oti_mulf(&tmpcnt,num,&tmp2);

        feoarr_setItem_ijk(&tmp2,0,0,k,res);

        oti_free(&tmpcnt);

    }

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
int64_t fem_integrateOTIfunct(oarr_t* f_eval, darr_t* weights, otinum_t* res, dhelpl_t dhl){
    /*
    fem_integrateotifunct( f_eval, weights)

    Perform the numerical integration of the function.

    INPUTS:

        -> f_eval:    (nIntPoints x 1) Array of oti numbers with the evaluated sampling points 
                                       of the function.

        -> weights:   (nIntPoints x 1) Array of weights to evaluate the integral.

    OUTPUTS: 
        
        -> res:  otinum that represents the result of the operation.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    double rtmp;
    uint64_t i, j = 0, nSamples = weights->nrows;

    otinum_t otitmp1, otitmp2, otitmp3;

    oti_createEmpty(&otitmp3, 0, f_eval->order);

    // Note: This can be done in parallel.
    for ( i = 0; i < nSamples ; i++ ){

        // Get function evaluated at point i.
        oarr_get_item(f_eval,  i, j, &otitmp1);
        
        // Get weight i.
        darr_get_item(weights,    i, j, &rtmp    );
        
        // Multiply weight times the function
        oti_mulf( &otitmp1, rtmp, &otitmp2 );

        // Sum to the temporal sum.
        otitmp1 = otitmp3;
        oti_sum( &otitmp1, &otitmp2, &otitmp3, dhl) ;

        oti_free( &otitmp1 );
        oti_free( &otitmp2 );

    }
    
    // Copy result.
    res[0] = otitmp3;

    return OTI_success;

} 
// ----------------------------------------------------------------------------------------------------









// ****************************************************************************************************
int64_t fem_defineSpatial( elemProps_t* elem, uint16_t derFlags, dhelpl_t dhl) {
    /*
    fem_computeJacobian( elem, xcoords, ycoords, zcoords, nDimAnalysis, res, dhl) 

    Initialize the element Basis functions for the specified order of integration.

    INPUTS:

        -> elem:   Address of the structure that holds the element information.

        -> xcoords: Coordinates.
        
        -> ycoords: Coordinates.
        
        -> zcoords: Coordinates.

        -> nDimAnalysis: Number of dimension of the analysis. May differ from the number of 
                         dimensions of the element, however cannot be less than that.

        -> res: list of result holders. Must come allocated.

        -> dhl: Direction helper       


    OUTPUTS: 
        
        -> Assigns to elem the corresponding arrays with the correct data input.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    int64_t derId;
    uint64_t i,j;
    uint64_t k;
    otinum_t tmp1,tmp2, tmpcntx, tmpcnty;
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

                    darr_get_item(&elem->p_evalBasis[i],j,k, &der);

                    oti_createFromReal(der,&tmp1,elem->otiorder);

                    feoarr_setItem_ijk(&tmp1,0,j,k,&elem->p_basis[i]);
                
                }

            }

        }else if( (derId == basisNx ) && (derFlags & 1<<1) ){

            for (j=0; j< elem->nbasis; j++){
                
                for(k=0; k< elem->nIntPts; k++){
                    //                    basisNa (dN/dxi)
                    darr_get_item(&elem->p_evalBasis[derNa-derN],j,k, &der); //ok

                    //                                From basisNx    from dim 1  
                    feoarr_get_item_ijk(&elem->Jinv,       0    ,     0       , k, &tmp2);

                    oti_mulf(&tmp2,der,&tmpcntx);


                    if (elem->ndim >= 2){
                        //                      basisNb (dN/deta)
                        darr_get_item(&elem->p_evalBasis[derNb-derN],j,k, &der);

                                                    //    From basisNx    from dim 2  
                        feoarr_get_item_ijk(&elem->Jinv,       0    ,     1       , k, &tmp2);

                        oti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        oti_sum( &tmp2, &tmpcnty, &tmpcntx, dhl);

                        oti_free(&tmp2);
                        oti_free(&tmpcnty);                        


                    }

                    if (elem->ndim >= 3){

                        //                      basisNb (dN/dchi)
                        darr_get_item(&elem->p_evalBasis[derNc-derN],j,k, &der);

                                                    //    From basisNx    from dim 3  
                        feoarr_get_item_ijk(&elem->Jinv,       0    ,     2       , k, &tmp2);

                        oti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        oti_sum( &tmp2, &tmpcnty, &tmpcntx, dhl);

                        oti_free(&tmp2);
                        oti_free(&tmpcnty);                    

                    }

                    feoarr_setItem_ijk(&tmpcntx,0,j,k,&elem->p_basis[i]);
                
                }

            }

        }else if( (derId == basisNxx) && (derFlags & 1<<2) ){
            // Not sure what to do yet

        }else if( (derId == basisNy ) && (derFlags & 1<<3) ){

            // Check that this is in dimension analysis.

            for (j=0; j< elem-> nbasis; j++){
                
                for(k=0; k< elem->nIntPts; k++){
                    //                    basisNa (dN/dxi)
                    darr_get_item(&elem->p_evalBasis[derNa-derN],j,k, &der);

                    //                                From basisNy    from dim 1  
                    feoarr_get_item_ijk(&elem->Jinv,       1    ,     0       , k, &tmp2);

                    oti_mulf(&tmp2,der,&tmpcntx);


                    if (elem->ndim >= 2){
                        //                      basisNb (dN/deta)
                        darr_get_item(&elem->p_evalBasis[derNb-derN],j,k, &der);

                                                    //    From basisNy    from dim 2  
                        feoarr_get_item_ijk(&elem->Jinv,       1    ,     1       , k, &tmp2);

                        oti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        oti_sum( &tmp2, &tmpcnty, &tmpcntx, dhl);

                        oti_free(&tmp2);
                        oti_free(&tmpcnty);                        


                    }

                    if (elem->ndim >= 3){

                        //                      basisNb (dN/dchi)
                        darr_get_item(&elem->p_evalBasis[derNc-derN],j,k, &der);

                                                    //    From basisNy    from dim 3  
                        feoarr_get_item_ijk(&elem->Jinv,       1    ,     2       , k, &tmp2);

                        oti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        oti_sum( &tmp2, &tmpcnty, &tmpcntx, dhl);

                        oti_free(&tmp2);
                        oti_free(&tmpcnty);                    

                    }

                    feoarr_setItem_ijk(&tmpcntx,0,j,k,&elem->p_basis[i]);
                
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
                    darr_get_item(&elem->p_evalBasis[derNa-derN],j,k, &der);

                    //                                From basisNz    from dim 1  
                    feoarr_get_item_ijk(&elem->Jinv,       2    ,     0       , k, &tmp2);

                    oti_mulf(&tmp2,der,&tmpcntx);


                    if (elem->ndim >= 2){
                        //                      basisNb (dN/deta)
                        darr_get_item(&elem->p_evalBasis[derNb-derN],j,k, &der);

                        //                                From basisNz    from dim 2  
                        feoarr_get_item_ijk(&elem->Jinv,       2    ,     1       , k, &tmp2);

                        oti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        oti_sum( &tmp2, &tmpcnty, &tmpcntx, dhl);

                        oti_free(&tmp2);
                        oti_free(&tmpcnty);                        


                    }

                    if (elem->ndim >= 3){

                        //                      basisNb (dN/dchi)
                        darr_get_item(&elem->p_evalBasis[derNc-derN],j,k, &der);

                        //                                From basisNz    from dim 3  
                        feoarr_get_item_ijk(&elem->Jinv,       2    ,     2       , k, &tmp2);

                        oti_mulf(&tmp2,der,&tmpcnty);

                        tmp2 = tmpcntx;

                        oti_sum( &tmp2, &tmpcnty, &tmpcntx, dhl);

                        oti_free(&tmp2);
                        oti_free(&tmpcnty);                    

                    }

                    feoarr_setItem_ijk(&tmpcntx,0,j,k,&elem->p_basis[i]);
                
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
int64_t fem_computeJacobian( elemProps_t* elem, oarr_t* xcoords, oarr_t* ycoords,
                               oarr_t* zcoords, dhelpl_t dhl) {
    /*
    fem_computeJacobian( elem, xcoords, ycoords, zcoords, dhl) 

    Initialize the element Basis functions for the specified order of integration.

    INPUTS:

        -> elem:   Address of the structure that holds the element information.

        -> xcoords: (ncoords x 1) Coordinates.
        
        -> ycoords: (ncoords x 1) Coordinates.
        
        -> zcoords: (ncoords x 1) Coordinates.

        -> nDimAnalysis: Number of dimension of the analysis. May differ from the number of 
                         dimensions of the element, however cannot be less than that.

        -> p_arrRes: Result holder. Must come allocated. shape: (nDimAnalysis x nDimElement)

        -> dhl: Direction helper       


    OUTPUTS: 
        
        -> Assigns to elem the corresponding arrays with the correct data input.

        -> uint64_t error_code: Code of error, if any.

    */ 
    // ************************************************************************************************

    int64_t derId, posNa = derNa-derN, posNb = derNb-derN, posNc = derNc-derN;
    uint8_t intPt,elDim; // i, j
    uint64_t basis; // i, k
    otinum_t tmp1,tmp2,tmp3, tmpcntx, tmpcnty, tmpcntz;
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
            oti_createEmpty(&tmpcntx,0,elem->otiorder); 

            if (elem->nDimAnalysis >= 2){
                // create tmpcnty = 0.
                oti_createEmpty(&tmpcnty,0,elem->otiorder); 
            }
            
            if (elem->nDimAnalysis >= 3){
                // create tmpcntz = 0.
                oti_createEmpty(&tmpcntz,0,elem->otiorder); 
            }



            for( basis = 0; basis<elem->nbasis; basis++){

                // compute for analysis dimension 1
                // Extract the coordinate for the corresponding basis.
                oarr_get_item_ij(xcoords, basis, 0, &tmp1); 

                // get the derivative of basis i with respect to elDim
                darr_get_item_ij( &elem->p_evalBasis[derId], basis, intPt, &dN_dxi);

                // multiply coordinate times derivative dN/da
                oti_mulf(&tmp1,dN_dxi,&tmp2);

                // Sum the result to the accumulator tmpcntx
                tmp3 = tmpcntx;
                oti_sum(&tmp3,&tmp2,&tmpcntx,dhl);

                // Free temps.
                oti_free(&tmp3);
                oti_free(&tmp2);

                if (elem->nDimAnalysis >= 2){

                    // compute for analysis dimension 2
                    oarr_get_item(ycoords, basis, 0, &tmp1); 

                    // multiply coordinate times derivative dN/db
                    oti_mulf(&tmp1,dN_dxi,&tmp2);

                    // Sum the result to the accumulator tmpcnty
                    tmp3 = tmpcnty;
                    oti_sum(&tmp3,&tmp2,&tmpcnty,dhl);

                    // Free temps.
                    oti_free(&tmp3);
                    oti_free(&tmp2);

                }

                if (elem->nDimAnalysis >= 3){
                    // compute for analysis dimension 3
                    oarr_get_item(zcoords, basis, 0, &tmp1); 

                    // multiply coordinate times derivative dN/dc
                    oti_mulf(&tmp1,dN_dxi,&tmp2);

                    // Sum the result to the accumulator tmpcntz
                    tmp3 = tmpcntz;
                    oti_sum(&tmp3,&tmp2,&tmpcntz,dhl);

                    // Free temps.
                    oti_free(&tmp3);
                    oti_free(&tmp2);
                }

            }

            // set element of the result array:
            feoarr_setItem_ijk(    &tmpcntx, elDim, 0, intPt, &elem->J);

            if (elem->nDimAnalysis >= 2){
                // create an oti zero to get otinum = 0 .
                feoarr_setItem_ijk(&tmpcnty, elDim, 1, intPt, &elem->J);
            }
            
            if (elem->nDimAnalysis >= 3){
                // create an oti zero to get otinum = 0 .
                feoarr_setItem_ijk(&tmpcntz, elDim, 2, intPt, &elem->J);
            }

    
        }
    
    }

    // Here, Jacobian is already computed. Now, the inverse and determinant can be computed.

    if (elem->ndim == elem->nDimAnalysis){
        
        feoarr_invert(&elem->J, &elem->Jinv, dhl);
        feoarr_det(   &elem->J, &elem->Jdet, dhl);

        for ( intPt=0; intPt< elem->nIntPts; intPt++){
            
            feoarr_get_item_ijk(&elem->Jdet,0,0,intPt,&tmp1);
            
            oti_mulf(&tmp1,elem->p_intWeights.p_data[intPt],&tmp2);

            // for (i=0; i<tmp2.size; i++){
            //     if( tmp2.p_indx[i] != 0 ){
            //         tmp2.p_coefs[i] = 0.0;
            //     }
            // }

            feoarr_setItem_ijk(&tmp2,0,0,intPt,&elem->p_detWeights);

            
        }

    } else {

        if (elem->ndim == 0){

            oti_createFromReal( 1.0, &tmp1, elem->otiorder);
            feoarr_setItem_ijk(&tmp1,0,0,0,&elem->p_detWeights);

        } else if (elem->ndim == 1){

            // sqrt( (dx/dxi)^2 + (dy/dxi)^2 + (dz/dxi)^2 )

            // Loop for every integration point
            for ( intPt=0; intPt< elem->nIntPts; intPt++){

                // initialize counter
               oti_createEmpty(&tmpcntx, 0, elem->otiorder); 


                // get dx/dxi
                feoarr_get_item_ijk(&elem->J , 0, 0, intPt,&tmp1);

                // do (dx/dxi)^2
                oti_ipowfast(&tmp1,2,&tmp2,dhl);

                // sum to counter
                tmp3 = tmpcntx;
                oti_sum( &tmp2, &tmp3, &tmpcntx, dhl);

                oti_free(&tmp2);
                oti_free(&tmp3);

                if (elem->nDimAnalysis >= 2){
                    // get dy/dxi
                    feoarr_get_item_ijk(&elem->J , 0, 1, intPt, &tmp1);

                    // do (dy/dxi)^2
                    oti_ipowfast(&tmp1,2,&tmp2,dhl);

                    // sum to counter
                    tmp3 = tmpcntx;
                    oti_sum(&tmp2,&tmp3,&tmpcntx,dhl);

                    oti_free(&tmp2);
                    oti_free(&tmp3);

                }

                if (elem->nDimAnalysis >= 3){

                    // get dz/dxi
                    feoarr_get_item_ijk(&elem->J , 0, 2, intPt, &tmp1);

                    // do (dz/dxi)^2
                    oti_ipowfast(&tmp1,2,&tmp2,dhl);

                    // sum to counter
                    tmp3 = tmpcntx;
                    oti_sum(&tmp2,&tmp3,&tmpcntx,dhl);

                    oti_free(&tmp2);
                    oti_free(&tmp3);

                }

                // counter = sqrt(counter)
                oti_sqrt( &tmpcntx, dhl, &tmp2);
                oti_free( &tmpcntx);

                // Multiply weight times the result.
                oti_mulf(&tmp2,elem->p_intWeights.p_data[intPt],&tmp1);
                oti_free(&tmp2);
                
                // for (i=0; i<tmp2.size; i++){
                //     if( tmp2.p_indx[i] != 0 ){
                //         tmp2.p_coefs[i] = 0.0;
                //     }
                // }
                // set the element with the result 
                feoarr_setItem_ijk(&tmp1,0,0,intPt,&elem->p_detWeights);

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
























