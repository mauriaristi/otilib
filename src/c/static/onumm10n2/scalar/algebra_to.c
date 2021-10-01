
// Division.
// ****************************************************************************************************
void onumm10n2_div_ro_to(coeff_t num, onumm10n2_t* den, onumm10n2_t* res){

    onumm10n2_t inv;
    onumm10n2_pow_to( den, -1, &inv);
    onumm10n2_mul_ro_to(num,&inv,res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm10n2_div_oo_to(onumm10n2_t* num, onumm10n2_t* den, onumm10n2_t* res){

    onumm10n2_t inv = onumm10n2_init();
    onumm10n2_pow_to( den, -1, &inv);
    onumm10n2_mul_oo_to( num, &inv, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm10n2_div_or_to(onumm10n2_t* num, coeff_t val, onumm10n2_t* res){

    onumm10n2_mul_ro_to(1.0/val, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm10n2_abs_to(onumm10n2_t* num, onumm10n2_t* res){

	if (num->r < 0){
		onumm10n2_neg_to(num,res);
	} else {
		onumm10n2_copy_to(num,res);
	}

}
// ----------------------------------------------------------------------------------------------------