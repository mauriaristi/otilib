



// ****************************************************************************************************
inline void fesoti_dimCheck(fesoti_t* num1,fesoti_t* num){

     if( num1->nip  != num->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fesoti arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void fesoti_get_active_bases(fesoti_t* num, imdir_t* list_vals, dhelpl_t dhl){
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<num->nip; i++ ){
        
        soti_get_active_bases( &num->p_data[i], list_vals, dhl);
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

