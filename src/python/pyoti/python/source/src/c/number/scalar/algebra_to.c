
// Division.
// ****************************************************************************************************
void soti_div_ro_to(coeff_t num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl){

    sotinum_t inv = soti_get_rtmp(6, den->order, dhl);
    soti_pow_to( den, -1, &inv, dhl);
    soti_mul_ro_to(num,&inv,res,dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_div_oo_to(sotinum_t* num, sotinum_t* den, sotinum_t* res, dhelpl_t dhl){

    sotinum_t inv = soti_init();
    soti_pow_to( den, -1, &inv, dhl);
    soti_mul_oo_to( num, &inv, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_div_or_to(sotinum_t* num, coeff_t val, sotinum_t* res, dhelpl_t dhl){

    soti_mul_ro_to(1.0/val, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------
