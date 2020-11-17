




carr_t carr_atanh(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = atanh(arr->p_data[i]);

	}

	return res;
    
}

void carr_atanh_to(carr_t* arr, carr_t* res){
    
    uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = atanh(arr->p_data[i]);

	}

}





carr_t carr_asinh(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = asinh(arr->p_data[i]);

	}

	return res;
    
}

void carr_asinh_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = asinh(arr->p_data[i]);

	}

}







carr_t carr_acosh(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = acosh(arr->p_data[i]);

	}

	return res;
    
}

void carr_acosh_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = acosh(arr->p_data[i]);

	}

}












carr_t carr_tanh(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = tanh(arr->p_data[i]);

	}

	return res;
    
}

void carr_tanh_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = tanh(arr->p_data[i]);

	}

}









carr_t carr_sqrt(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = sqrt(arr->p_data[i]);

	}

	return res;
    
}

void carr_sqrt_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = sqrt(arr->p_data[i]);

	}

}






carr_t carr_cbrt(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = cbrt(arr->p_data[i]);

	}

	return res;
    
}

void carr_cbrt_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = cbrt(arr->p_data[i]);

	}

}




carr_t carr_cosh(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = cosh(arr->p_data[i]);

	}

	return res;
    
}

void carr_cosh_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = cosh(arr->p_data[i]);

	}

}













carr_t carr_sinh(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = sinh(arr->p_data[i]);

	}

	return res;
    
}

void carr_sinh_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = sinh(arr->p_data[i]);

	}

}















carr_t carr_asin(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = asin(arr->p_data[i]);

	}

	return res;
    
}

void carr_asin_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = asin(arr->p_data[i]);

	}

}



















carr_t carr_acos(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = acos(arr->p_data[i]);

	}

	return res;
    
}

void carr_acos_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = acos(arr->p_data[i]);

	}

}










carr_t carr_atan(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = atan(arr->p_data[i]);

	}

	return res;
    
}

void carr_atan_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = atan(arr->p_data[i]);

	}

}










carr_t carr_tan(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = tan(arr->p_data[i]);

	}

	return res;
    
}

void carr_tan_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = tan(arr->p_data[i]);

	}

}










carr_t carr_cos(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = cos(arr->p_data[i]);

	}

	return res;
    
}

void carr_cos_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = cos(arr->p_data[i]);

	}

}










carr_t carr_sin(carr_t* arr ){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = sin(arr->p_data[i]);

	}

	return res;
    
}

void carr_sin_to(carr_t* arr, carr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = sin(arr->p_data[i]);

	}

}










carr_t carr_logb(carr_t* arr, double base){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;
	coeff_t lbase = log(base);

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = log(arr->p_data[i])/lbase;

	}

	return res;
    
}

void carr_logb_to(carr_t* arr, double base, carr_t* res){
    
	uint64_t i;
	coeff_t lbase = log(base);

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = log(arr->p_data[i])/lbase;

	}

}










carr_t carr_log10(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;
	coeff_t lbase = log(10.0);

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = log(arr->p_data[i])/lbase;

	}

	return res;
    
}

void carr_log10_to(carr_t* arr, carr_t* res){
    
	uint64_t i;
	coeff_t lbase = log(10.0);

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = log(arr->p_data[i])/lbase;

	}

}







carr_t carr_log(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = log(arr->p_data[i]);

	}

	return res;
    
}

void carr_log_to(carr_t* arr, carr_t* res){

	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = log(arr->p_data[i]);

	}

}







carr_t carr_exp(carr_t* arr){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = exp(arr->p_data[i]);

	}

	return res;
    
}

void carr_exp_to(carr_t* arr, carr_t* res){

	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = exp(arr->p_data[i]);

	}

}







carr_t carr_pow(carr_t* arr, double e){

	carr_t res = carr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = pow(arr->p_data[i],e);

	}

	return res;
    
}

void carr_pow_to(carr_t* arr, double e, carr_t* res){
	
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = pow(arr->p_data[i],e);

	}

}







// ----------------------------------------------------------------------------------------------------