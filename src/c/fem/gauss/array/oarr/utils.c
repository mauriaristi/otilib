

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

//     for (k = 0; k<elem->nIntPts; k++){

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
            
//             soti_createEmpty(&tmp1,0,arr->order);

           
//             for (k = 0; k<elem->nIntPts; k++){
//                 // printf("    Summing integration point %llu\n",k);
//                 // printf("    Getting element of integration function\n");
//                 feoarr_get_item_ijk(arr, i, j, k, &tmp2);

//                 // printf("    Getting element of weights function\n");
//                 feoarr_get_item_ijk(&elem->p_detWeights, 0, 0, k, &tmp4);


//                 // printf("    Multiplying two otis\n");
//                 soti_mul(&tmp2, &tmp4, &tmp3, dhl);


//                 tmp2 = tmp1;

//                 // printf("    Adding two otis\n");
//                 soti_sum(&tmp2,&tmp3,&tmp1,dhl);

//                 // printf("    Freeing memory of temporal arrays.\n");
//                 // Free temporals that were created in here.
//                 soti_free(&tmp2);    
//                 soti_free(&tmp3);

//             }
//             // printf("  Adding position i: %llu,   j: %llu,    with offsets ->   i': %llu,   j': %llu\n", 
//                                 // i, j, p_arr1->offsetx+i,   p_arr1->offsety+j  );

//             // printf("  Getting element from result array\n");
//             sotiarray_getItem( res, p_arr1->offsetx + i, p_arr1->offsety + j, &tmp2);

//             // realVal = soti_getReal(&tmp2);

//             // printf("  tmp2: \n");
//             // soti_printf(&tmp2);
//             // realVal = soti_getReal(&tmp1);
//             // printf("\n  tmp1: \n");
//             // soti_printf(&tmp1);

//             // realVal = soti_getReal(&tmp3);
            
//             // printf("\n  tmp3: \n");
//             // soti_printf(&tmp3);

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





