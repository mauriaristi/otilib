



// ****************************************************************************************************
void elem_iso_compJacobian( elem_t* elem, oarr_t* xcoo, oarr_t* ycoo, oarr_t* zcoo, dhelpl_t* dhl) {
    /*
    
    @brief Compute the jacobian of an element with an isoparametric formulation.

    @param elem Element, must come initialized.
    @param xcoo Array with x coordinates. (ncoords x 1)
    @param ycoo Array with y coordinates. (ncoords x 1)
    @param zcoo Array with z coordinates. (ncoords x 1)    
    @param dhl: Direction helper 

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
                // Perform:
                // tmpcntx += xcoo[ basis ]*dN_dxi[basis]

                // Extract the coordinate for the corresponding basis.
                // xcoo[ basis ]
                c_sotiarray_getItem(xcoo, basis, 0, &tmp1); 

                // get the derivative of basis i with respect to elDim
                // dN_dxi[basis]
                c_darray_getItem( &elem->p_evalBasis[derId], basis, intPt, &dN_dxi);

                // multiply coordinate times derivative dN/da

                c_soti_mulf(&tmp1,dN_dxi,&tmp2);

                // Sum the result to the accumulator tmpcntx
                // tmpcntx += dN_dxi[basis]
                tmp3 = tmpcntx;
                c_soti_sum(&tmp3,&tmp2,&tmpcntx,p_dH);

                // Free temps.
                c_soti_free(&tmp3);
                c_soti_free(&tmp2);

                if (elem->nDimAnalysis >= 2){

                    // Perform:
                    // tmpcnty += ycoo[ basis ]*dN_dxi[basis]
                    // 
                    
                    // compute for analysis dimension 2
                    c_sotiarray_getItem(ycoo, basis, 0, &tmp1); 

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
                    
                    // Perform: dz_dxi
                    // tmpcntz += zcoo[ basis ] * dN_dxi[basis]
                    // 

                    // compute for analysis dimension 3
                    c_sotiarray_getItem(zcoo, basis, 0, &tmp1); 

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

            
            // The jacobian is formed as follows
            //  
            //       < -------- Natural coords ------ > 
            //                                                        
            //      |                                  |        A
            //      |                                  |        |
            //      |  dx_dxi     dx_deta   dx_dgamma  |        |
            //      |                                  |        |
            //      |                                  |        |
            //  J = |  dy_dxi     dy_deta   dy_dgamma  | Spatial coords. 
            //      |                                  |        |
            //      |                                  |        |
            //      |  dz_dxi     dz_deta   dz_dgamma  |        |
            //      |                                  |        |
            //      |                                  |        v
            // 
            //



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
            

            // Compute the dV for the integration procedure.

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

            c_soti_createFromReal(     1.0, &tmp1, elem->otiorder);
            c_femarray_setItem_ijk(  &tmp1,0,0,0,&elem->p_detWeights);

        } else if (elem->ndim == 1){
            // This case corresponds for a line integral in multiple dimensions.
            // The way to proceed is to compute $d \Omega$ as follows:
            //
            // $$
            // d \Omega =  
            //     sqrt{(\frac{dx}{dxi})^2 + (\frac{dy}{dxi})^2 + (\frac{dz}{dxi})^2 } 
            // $$
            //
            //


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


