










/**************************************************************************************************//**
@brief Negate an array. 

@param[in]      p_arr1: Address of the array.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
void darr_neg_to(darr_t* arr1, darr_t* aRes);

darr_t darr_neg(darr_t* arr1);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Elementwise division of arrays. Must have same dimensions. 

@param[in] p_arr1: Address of the array 1.
@param[in] p_arr2: Address of the array 2.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
darr_t darr_div_RR(darr_t* arr1, darr_t* arr2);
darr_t darr_div_Rr(darr_t* arr1, coeff_t num);
darr_t darr_div_rR(coeff_t num, darr_t* arr1);

void darr_div_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
void darr_div_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes);
void darr_div_rR_to(coeff_t num, darr_t* arr2, darr_t* aRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise multiplication of arrays. Must have same dimensions. 

@param[in] p_arr1: Address of the array 1.
@param[in] p_arr2: Address of the array 2.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
darr_t darr_mul_RR(darr_t* arr1, darr_t* arr2);
darr_t darr_mul_rR(coeff_t num, darr_t* arr1);

void darr_mul_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
void darr_mul_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes);

void darr_mul_and_selfsum_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
void darr_mul_and_selfsum_rR_to(coeff_t num, darr_t* arr2, darr_t* aRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise subtraction of arrays. Must have same dimensions. 

@param[in] p_arr1: Address of the array 1.
@param[in] p_arr2: Address of the array 2.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
darr_t darr_sub_RR(darr_t* arr1, darr_t* arr2);
darr_t darr_sub_Rr(darr_t* arr1, coeff_t num);
darr_t darr_sub_rR(coeff_t num, darr_t* arr1);

void darr_sub_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
void darr_sub_Rr_to(darr_t* arr1, coeff_t num, darr_t* aRes);
void darr_sub_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise addition of arrays. Must have same dimensions. 

@param[in] arr1: Address of the array 1.
@param[in] arr2: Address of the array 2.
@param[inout] aRes: Resulting array.
******************************************************************************************************/
darr_t darr_sum_RR(darr_t* arr1, darr_t* arr2);
darr_t darr_sum_rR(coeff_t num, darr_t* arr1);

void darr_sum_RR_to(darr_t* arr1, darr_t* arr2, darr_t* aRes);
void darr_sum_rR_to(coeff_t num, darr_t* arr1, darr_t* aRes);
// ----------------------------------------------------------------------------------------------------






void darr_matmul_and_selfsum_RR_to(darr_t* arr1, darr_t* arr2, darr_t* res );


darr_t darr_matmul(darr_t* arr1, darr_t* arr2 );
void darr_matmul_to(darr_t* arr1, darr_t* arr2, darr_t* aRes );

darr_t darr_transpose(darr_t* arr1);
void darr_transpose_to(darr_t* arr1, darr_t* aRes);

darr_t darr_invert(darr_t* arr1);
void darr_invert_to(darr_t* arr1, darr_t* aRes);

coeff_t darr_det( darr_t* arr1 );



void darr_self_neg( darr_t* res);
void darr_self_sum_R(darr_t* arr1, darr_t* res);
void darr_self_sum_r(coeff_t num, darr_t* res);
void darr_self_sub_R(darr_t* arr1, darr_t* res);
void darr_self_sub_r(coeff_t num, darr_t* res);
void darr_self_mul_R(darr_t* arr1, darr_t* res);
void darr_self_mul_r(coeff_t num, darr_t* aRes);