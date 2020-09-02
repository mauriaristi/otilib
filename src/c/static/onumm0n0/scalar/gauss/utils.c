

// ****************************************************************************************************
inline void feonumm0n0_dimCheck(feonumm0n0_t* num1,feonumm0n0_t* num){

     if( num1->nip  != num->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feonumm0n0 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm0n0_get_active_bases(feonumm0n0_t* num, imdir_t* list_vals){
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<num->nip; i++ ){
        
        onumm0n0_get_active_bases( &num->p_data[i], list_vals);
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

