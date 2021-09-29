



// ****************************************************************************************************
inline void fessoti_dimCheck(fessoti_t* num1,fessoti_t* num){

     if( num1->nip  != num->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two fesoti arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------




// ****************************************************************************************************
void fessoti_get_active_bases(fessoti_t* num, imdir_t* list_vals, dhelpl_t dhl){
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<num->nip; i++ ){
        
        ssoti_get_active_bases( &num->p_data[i], list_vals, dhl);
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

