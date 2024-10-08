
// Division.
// ****************************************************************************************************
void onumm10n1_div_ro_to(coeff_t num, onumm10n1_t* den, onumm10n1_t* res){

    onumm10n1_t inv;
    onumm10n1_pow_to( den, -1, &inv);
    onumm10n1_mul_ro_to(num,&inv,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm10n1_div_oo_to(onumm10n1_t* num, onumm10n1_t* den, onumm10n1_t* res){

    onumm10n1_t inv = onumm10n1_init();
    onumm10n1_pow_to( den, -1, &inv);
    onumm10n1_mul_oo_to( num, &inv, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm10n1_div_or_to(onumm10n1_t* num, coeff_t val, onumm10n1_t* res){

    onumm10n1_mul_ro_to(1.0/val, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm10n1_abs_to(onumm10n1_t* num, onumm10n1_t* res){

	if (num->r < 0){
		onumm10n1_neg_to(num,res);
	} else {
		onumm10n1_copy_to(num,res);
	}

}
// ----------------------------------------------------------------------------------------------------