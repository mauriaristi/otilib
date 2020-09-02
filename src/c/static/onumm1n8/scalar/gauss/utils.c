

// ****************************************************************************************************
inline void feonumm1n8_dimCheck(feonumm1n8_t* num1,feonumm1n8_t* num){

     if( num1->nip  != num->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feonumm1n8 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm1n8_get_active_bases(feonumm1n8_t* num, imdir_t* list_vals){
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<num->nip; i++ ){
        
        onumm1n8_get_active_bases( &num->p_data[i], list_vals);
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

