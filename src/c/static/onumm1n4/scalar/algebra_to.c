
// Division.
// ****************************************************************************************************
void onumm1n4_div_ro_to(coeff_t num, onumm1n4_t* den, onumm1n4_t* res){

    onumm1n4_t inv;
    onumm1n4_pow_to( den, -1, &inv);
    onumm1n4_mul_ro_to(num,&inv,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n4_div_oo_to(onumm1n4_t* num, onumm1n4_t* den, onumm1n4_t* res){

    onumm1n4_t inv = onumm1n4_init();
    onumm1n4_pow_to( den, -1, &inv);
    onumm1n4_mul_oo_to( num, &inv, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n4_div_or_to(onumm1n4_t* num, coeff_t val, onumm1n4_t* res){

    onumm1n4_mul_ro_to(1.0/val, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n4_abs_to(onumm1n4_t* num, onumm1n4_t* res){

	if (num->r < 0){
		onumm1n4_neg_to(num,res);
	} else {
		onumm1n4_copy_to(num,res);
	}

}
// ----------------------------------------------------------------------------------------------------