void oti_blas_coeff_axpy(int64_t n, coeff_t a, coeff_t *x, int64_t incx, coeff_t *y, int64_t incy){
	int64_t i;

	for (i = 0; i<n; i++){
		y[i*incy] = a*x[i*incx]+y[i*incx]
	}

}