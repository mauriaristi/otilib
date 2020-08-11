




darr_t darr_atanh(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = atanh(arr->p_data[i]);

	}

	return res;
    
}

void darr_atanh_to(darr_t* arr, darr_t* res){
    
    uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = atanh(arr->p_data[i]);

	}

}





darr_t darr_asinh(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = asinh(arr->p_data[i]);

	}

	return res;
    
}

void darr_asinh_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = asinh(arr->p_data[i]);

	}

}







darr_t darr_acosh(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = acosh(arr->p_data[i]);

	}

	return res;
    
}

void darr_acosh_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = acosh(arr->p_data[i]);

	}

}












darr_t darr_tanh(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = tanh(arr->p_data[i]);

	}

	return res;
    
}

void darr_tanh_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = tanh(arr->p_data[i]);

	}

}









darr_t darr_sqrt(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = sqrt(arr->p_data[i]);

	}

	return res;
    
}

void darr_sqrt_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = sqrt(arr->p_data[i]);

	}

}






darr_t darr_cbrt(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = cbrt(arr->p_data[i]);

	}

	return res;
    
}

void darr_cbrt_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = cbrt(arr->p_data[i]);

	}

}




darr_t darr_cosh(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = cosh(arr->p_data[i]);

	}

	return res;
    
}

void darr_cosh_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = cosh(arr->p_data[i]);

	}

}













darr_t darr_sinh(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = sinh(arr->p_data[i]);

	}

	return res;
    
}

void darr_sinh_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = sinh(arr->p_data[i]);

	}

}















darr_t darr_asin(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = asin(arr->p_data[i]);

	}

	return res;
    
}

void darr_asin_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = asin(arr->p_data[i]);

	}

}



















darr_t darr_acos(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = acos(arr->p_data[i]);

	}

	return res;
    
}

void darr_acos_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = acos(arr->p_data[i]);

	}

}










darr_t darr_atan(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = atan(arr->p_data[i]);

	}

	return res;
    
}

void darr_atan_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = atan(arr->p_data[i]);

	}

}










darr_t darr_tan(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = tan(arr->p_data[i]);

	}

	return res;
    
}

void darr_tan_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = tan(arr->p_data[i]);

	}

}










darr_t darr_cos(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = cos(arr->p_data[i]);

	}

	return res;
    
}

void darr_cos_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = cos(arr->p_data[i]);

	}

}










darr_t darr_sin(darr_t* arr ){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = sin(arr->p_data[i]);

	}

	return res;
    
}

void darr_sin_to(darr_t* arr, darr_t* res){
    
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = sin(arr->p_data[i]);

	}

}










darr_t darr_logb(darr_t* arr, double base){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;
	coeff_t lbase = log(base);

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = log(arr->p_data[i])/lbase;

	}

	return res;
    
}

void darr_logb_to(darr_t* arr, double base, darr_t* res){
    
	uint64_t i;
	coeff_t lbase = log(base);

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = log(arr->p_data[i])/lbase;

	}

}










darr_t darr_log10(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;
	coeff_t lbase = log(10.0);

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = log(arr->p_data[i])/lbase;

	}

	return res;
    
}

void darr_log10_to(darr_t* arr, darr_t* res){
    
	uint64_t i;
	coeff_t lbase = log(10.0);

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = log(arr->p_data[i])/lbase;

	}

}







darr_t darr_log(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = log(arr->p_data[i]);

	}

	return res;
    
}

void darr_log_to(darr_t* arr, darr_t* res){

	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = log(arr->p_data[i]);

	}

}







darr_t darr_exp(darr_t* arr){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = exp(arr->p_data[i]);

	}

	return res;
    
}

void darr_exp_to(darr_t* arr, darr_t* res){

	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = exp(arr->p_data[i]);

	}

}







darr_t darr_pow(darr_t* arr, double e){

	darr_t res = darr_createEmpty(arr->nrows,arr->ncols);
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res.p_data[i] = pow(arr->p_data[i],e);

	}

	return res;
    
}

void darr_pow_to(darr_t* arr, double e, darr_t* res){
	
	uint64_t i;

	for (i=0; i<arr->size; i++ ){

		res->p_data[i] = pow(arr->p_data[i],e);

	}

}







// ----------------------------------------------------------------------------------------------------