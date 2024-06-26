
// Division.
// ****************************************************************************************************
void onumm2n3_div_ro_to(coeff_t num, onumm2n3_t* den, onumm2n3_t* res){

    onumm2n3_t inv;
    onumm2n3_pow_to( den, -1, &inv);
    onumm2n3_mul_ro_to(num,&inv,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n3_div_oo_to(onumm2n3_t* num, onumm2n3_t* den, onumm2n3_t* res){

    onumm2n3_t inv = onumm2n3_init();
    onumm2n3_pow_to( den, -1, &inv);
    onumm2n3_mul_oo_to( num, &inv, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n3_div_or_to(onumm2n3_t* num, coeff_t val, onumm2n3_t* res){

    onumm2n3_mul_ro_to(1.0/val, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n3_abs_to(onumm2n3_t* num, onumm2n3_t* res){

	if (num->r < 0){
		onumm2n3_neg_to(num,res);
	} else {
		onumm2n3_copy_to(num,res);
	}

}
// ----------------------------------------------------------------------------------------------------