

// // ****************************************************************************************************
// void feoarr_gaussIntegrateOverElement(feoarr_t* arr, elemProps_t* elem, oarr_t* res, dhelpl_t dhl){
//     /*
//     Gauss integration over all elements of a femarray.

//     INPUTS:

//         ->   p_arr1:    Array

//         ->   elem:      Element with the information of the solution.
        
//         -> res:    Result of operation.

//         ->     dhl:    Direction helper

//     */ 
//     // ************************************************************************************************

//     uint64_t i,j,k;
//     oarr_t tmp1, tmp2, tmp3, tmp4;
//     otinum_t tmp_oti = oti_get_tmp(10 , arr->nbases, arr->order, dhl);

//     tmp1 = oarr_zeros(,dhl);
//     tmp2 = oarr_zeros(,dhl);
//     // tmp3 = oarr_zeros(,dhl);
//     // tmp4 = oarr_zeros(,dhl);

//     // printf("\nIntegrating over element.\n");

//     for (k = 0; k<elem->nip; k++){

//         tmp_arr = arr->p_data[k];

//         feoarr_get_item_ijk_to(&elem->p_detWeights, 0, 0, k, &tmp_oti);

//         // multiply array times oti value
//         oarr_mul_oO_to( &tmp_oti, &arr->p_data[k], &tmp2, dhl);

//         // Add it to the result

//         // tmp3 += tmp2



//     }

//     // offset copy information to the specified array.
//     for (i = 0; i<arr->nrows; i++){
    
//         for (j = 0; j<arr->ncols; j++){

            

//         }

//     }

//     oarr_free( &tmp1 );




//     for (i = 0; i<arr->nrows; i++){
    
//         for (j = 0; j<arr->ncols; j++){

//             // printf("  Integrating position (%llu,%llu)\n",i,j);
            
//             ssoti_createEmpty(&tmp1,0,arr->order);

           
//             for (k = 0; k<elem->nip; k++){
//                 // printf("    Summing integration point %llu\n",k);
//                 // printf("    Getting element of integration function\n");
//                 feoarr_get_item_ijk(arr, i, j, k, &tmp2);

//                 // printf("    Getting element of weights function\n");
//                 feoarr_get_item_ijk(&elem->p_detWeights, 0, 0, k, &tmp4);


//                 // printf("    Multiplying two otis\n");
//                 ssoti_mul(&tmp2, &tmp4, &tmp3, dhl);


//                 tmp2 = tmp1;

//                 // printf("    Adding two otis\n");
//                 ssoti_sum(&tmp2,&tmp3,&tmp1,dhl);

//                 // printf("    Freeing memory of temporal arrays.\n");
//                 // Free temporals that were created in here.
//                 ssoti_free(&tmp2);    
//                 ssoti_free(&tmp3);

//             }
//             // printf("  Adding position i: %llu,   j: %llu,    with offsets ->   i': %llu,   j': %llu\n", 
//                                 // i, j, p_arr1->offsetx+i,   p_arr1->offsety+j  );

//             // printf("  Getting element from result array\n");
//             sotiarray_getItem( res, p_arr1->offsetx + i, p_arr1->offsety + j, &tmp2);

//             // realVal = ssoti_getReal(&tmp2);

//             // printf("  tmp2: \n");
//             // ssoti_printf(&tmp2);
//             // realVal = ssoti_getReal(&tmp1);
//             // printf("\n  tmp1: \n");
//             // ssoti_printf(&tmp1);

//             // realVal = ssoti_getReal(&tmp3);
            
//             // printf("\n  tmp3: \n");
//             // ssoti_printf(&tmp3);

//             // printf("  Adding the two arrays\n");
            

//             oti_sum(&tmp2,&tmp1,&tmp3,dhl);



//             // printf("  Freeing memory temporal 1.\n");
//             oti_free(&tmp1);

            

//             sotiarray_setItemOTI(&tmp3,
//                 p_arr1->offsetx + i , p_arr1->offsety + j, res);
    
//         }

    
//     }


// }
// // ----------------------------------------------------------------------------------------------------








// ****************************************************************************************************
inline void fearrsso_dimCheck_FF_samesize(fearrsso_t* arr1,fearrsso_t* arr2,fessoti_t* res){

     if( arr1->size != arr2->size || arr1->nip != arr2->nip || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fearrsso arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrsso_dimCheck_OF_samesize(arrsso_t* arr1,fearrsso_t* arr2, fessoti_t* res){

     if( arr1->size != arr2->size || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between fearrsso and real arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrsso_dimCheck_RF_samesize(darr_t* arr1, fearrsso_t* arr2, fessoti_t* res){

    if( arr1->size != arr2->size || arr2->nip != res->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between fearrsso and real arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------
















// ****************************************************************************************************
inline void fearrsso_dimCheck_FF_elementwise(fearrsso_t* arr1,fearrsso_t* arr2,fearrsso_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fearrsso arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrsso_dimCheck_fF_elementwise(fessoti_t* arr1,fearrsso_t* arr2,fearrsso_t* res){

     if( arr2->size !=  res->size || arr2->ncols !=  res->ncols || arr2->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fearrsso arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrsso_dimCheck_Ff_elementwise(fearrsso_t* arr1,fessoti_t* arr2,fearrsso_t* res){

     if( arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr1->nip != res->nip || arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fearrsso arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrsso_dimCheck_OF_elementwise(arrsso_t* arr1,fearrsso_t* arr2, fearrsso_t* res){

     if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
         arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
         arr2->nip !=  res->nip   ){
        printf("ERROR: Wrong dimensions in elementwise operation between fearrsso and real arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrsso_dimCheck_RF_elementwise(darr_t* arr1, fearrsso_t* arr2, fearrsso_t* res){

    if( arr1->size != arr2->size || arr1->ncols != arr2->ncols || arr1->nrows != arr2->nrows ||
        arr1->size !=  res->size || arr1->ncols !=  res->ncols || arr1->nrows !=  res->nrows ||
        arr2->nip != res->nip                         ){
        printf("ERROR: Wrong dimensions in elementwise operation between fearrsso and real arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
inline void fearrsso_dimCheck_FfO_integrate(fearrsso_t* arr,fessoti_t* num,arrsso_t* res){

     if( arr->size !=  res->size || arr->ncols != res->ncols || arr->nrows != res->nrows ||
         arr->nip != num->nip   ){
        printf("ERROR: Wrong dimensions in integration operation between two fearrsso arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------











// ****************************************************************************************************
inline void fearrsso_dimCheck_FF_matmul( fearrsso_t* arr1, fearrsso_t* arr2, fearrsso_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip || 
        arr2->nip !=  res->nip      ){
       printf("ERROR: Wrong dimensions in matmul-like operation between two fearrsso arrays.\n");
       exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrsso_dimCheck_OF_matmul( arrsso_t* arr1, fearrsso_t* arr2, fearrsso_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and fearrsso arrays.\n");
        exit(OTI_BadDim);
    }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrsso_dimCheck_RF_matmul( darr_t* arr1, fearrsso_t* arr2, fearrsso_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr2->nip !=  res->nip      ){
        printf("ERROR: Wrong dimensions in matmul-like operation between darr and fearrsso arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline void fearrsso_dimCheck_FO_matmul( fearrsso_t* arr1, arrsso_t* arr2, fearrsso_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip    ){
        printf("ERROR: Wrong dimensions in matmul-like operation between fearrsso and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void fearrsso_dimCheck_FR_matmul( fearrsso_t* arr1, darr_t* arr2, fearrsso_t* res){

    if( arr1->ncols != arr2->nrows ||
        arr1->nrows !=  res->nrows || 
        arr2->ncols !=  res->ncols ||
        arr1->nip !=  res->nip     ){
        printf("ERROR: Wrong dimensions in matmul-like operation between fearrsso and darr arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------












// ****************************************************************************************************
inline void fearrsso_dimCheck_F_squareness( fearrsso_t* arr1, fearrsso_t* res){

    if( arr1->ncols != arr1->nrows ||
        arr1->nrows !=  res->nrows || 
        arr1->ncols !=  res->ncols ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: fearrsso array not square.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
inline void fearrsso_dimCheck_F_transpose( fearrsso_t* arr1, fearrsso_t* res){

    if( arr1->nrows !=  res->ncols || 
        arr1->ncols !=  res->nrows ||
        arr1->nip !=  res->nip   ){
        printf("ERROR: fearrsso array not compliant with transpose operation.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************
void fearrsso_get_active_bases(fearrsso_t* arr, imdir_t* list_vals, dhelpl_t dhl){
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<arr->nip; i++ ){
        
        arrsso_get_active_bases( &arr->p_data[i], list_vals, dhl);
    
    }
    
}
// ----------------------------------------------------------------------------------------------------











