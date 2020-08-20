

// ****************************************************************************************************
inline void {fenum_func}_dimCheck({fenum_type}* num1,{fenum_type}* num){{

     if( num1->nip  != num->nip ){{
        printf("ERROR: Wrong dimensions in elementwise operation between two {fenum_func} arrays.\n");
        exit(OTI_BadDim);
     }}

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void {fenum_func}_get_active_bases({fenum_type}* num, imdir_t* list_vals){{
    
    uint64_t i;
    
    // Finds the active imaginary directions in the array.
    for( i=0; i<num->nip; i++ ){{
        
        {num_func}_get_active_bases( &num->p_data[i], list_vals);
    
    }}
    
}}
// ----------------------------------------------------------------------------------------------------

