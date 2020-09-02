

// ****************************************************************************************************
inline void feonumm2n9_dimCheck(feonumm2n9_t* num1,feonumm2n9_t* num){

     if( num1->nip  != num->nip ){
        printf("ERROR: Wrong dimensions in elementwise operation between two feonumm2n9 arrays.\n");
        exit(OTI_BadDim);
     }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void feonumm2n9_get_active_bases(feonumm2n9_t* num, imdir_t* list_vals){
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<num->nip; i++ ){
        
        onumm2n9_get_active_bases( &num->p_data[i], list_vals);
    
    }
    
}
// ----------------------------------------------------------------------------------------------------

