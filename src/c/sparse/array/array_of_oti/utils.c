// typedef struct {
//     sotinum_t*    p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     flag_t          flag; ///< Memory flag.
// } arrso_t;                ///< Array of OTIs type.


// ****************************************************************************************************
inline void arrso_dimCheck_OO_elementwise(arrso_t* arr1,arrso_t* arr2){

	 if( arr1->size  != arr2->size  || 
	     arr1->ncols != arr2->ncols ||
	     arr1->nrows != arr2->nrows   ){
	 	printf("ERROR: Wrong dimensions in elementwise operation between two arrso arrays.\n");
	 	exit(OTI_BadDim);
	 }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_dimCheck_RO_elementwise(darr_t* arr1,arrso_t* arr2){

	 if( arr1->size  != arr2->size  || 
	     arr1->ncols != arr2->ncols ||
	     arr1->nrows != arr2->nrows   ){
	 	printf("ERROR: Wrong dimensions in elementwise operation between arrso and real arrays.\n");
	 	exit(OTI_BadDim);
	 }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
inline void arrso_dimCheck_OO_matmul(arrso_t* arr1,arrso_t* arr2){

	 if( arr1->nrows != arr2->ncols ){
	 	printf("ERROR: Wrong dimensions in matmul-like operation between two arrso arrays.\n");
	 	exit(OTI_BadDim);
	 }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_dimCheck_RO_matmul(darr_t* arr1,arrso_t* arr2){

	 if( arr1->nrows != arr2->ncols ){
	 	printf("ERROR: Wrong dimensions in matmul-like operation between darr and arrso arrays.\n");
	 	exit(OTI_BadDim);
	 }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_dimCheck_OR_matmul(arrso_t* arr1, darr_t* arr2){

	 if( arr1->nrows != arr2->ncols ){
	 	printf("ERROR: Wrong dimensions in matmul-like operation between arrso and darr arrays.\n");
	 	exit(OTI_BadDim);
	 }

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
inline void arrso_dimCheck_OR_squareness(arrso_t* arr1){

	 if( arr1->nrows != arr1->ncols ){
	 	printf("ERROR: Arrso array not square.\n");
	 	exit(OTI_BadDim);
	 }

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
ord_t arrso_get_order(arrso_t* arr){
	ord_t order = 0;

	if( arr->size !=0 ){
		// Extract the order information from the first sotinum element.
		order = arr->p_data[0].order;
	}

	return order;
}
// ----------------------------------------------------------------------------------------------------



// ****************************************************************************************************




