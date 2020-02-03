


// typedef struct {
//     coeff_t          re; ///< Real coefficient.
//     coeff_t**      p_im; ///< Array with all imaginary coefficients per order.
//     imdir_t**     p_idx; ///< Directions associated to each coefficient per order.
//     ndir_t*       p_nnz; ///< Number of non zero coefficients per order.
//     ndir_t*      p_size; ///< Allocated size per order.
//     ord_t         order; ///< Truncation order of the number.
//     flag_t         flag; ///< Memory flag.
// } sotinum_t;             ///< Sparse OTI number type

// typedef struct {
//     coeff_t          re; ///< Real coefficient.
//     coeff_t**      p_im; ///< Array with all imaginary coefficients per order.
//     imdir_t**     p_idx; ///< Directions associated to each coefficient per order.
//     ndir_t*       p_nnz; ///< Number of non zero coefficients per order.
// } somin_t;               ///< Minimal sparse OTI number type. 



// ****************************************************************************************************
inline sotinum_t dhelp_get_sotinum_from_somin(somin_t in, ord_t order, flag_t flag, ndir_t* p_size){

	sotinum_t res;

	res.re     = in.re;
	res.p_im   = in.p_im;
	res.p_idx  = in.p_idx;
	res.p_nnz  = in.p_nnz;
	res.p_size = p_size;
	res.order  = order;
	res.flag   = 0;

	return res;
}
// ----------------------------------------------------------------------------------------------------
