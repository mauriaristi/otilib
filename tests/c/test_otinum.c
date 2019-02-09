#include<oti/otinum_dense.h>
#include<time.h>


int main(int argc, char *argv[]){
	// Declarations
	char data_folder[] = "/home/maristi7/coding/otilib/src/datagen/data"; // Useful for linux and macos distributions.
	dhelpl_t dhl; // Direction helper.


	// 
	// printf("Testing data loading from precomputed arrays:\n");

	dhelp_load(data_folder, &dhl);
	
	// printf("Successfuly loaded %d direction helpers.\n", dhelpl.ndh);




	printf("Testing creation of oti number.\n");
	otinum_t num, num1, num2;
	coeff_t a = 0.5;
	bases_t nbases = 2;
	ord_t order  = 3;

	// Allocate memory first.
	oti_createEmpty( nbases, order, &num, dhl);

	// Set From a real number:
	oti_setFromReal( a, &num, dhl);

	// Set element 
	imdir_t idx_to_set = 0;
	ord_t   ord_to_set = 3;
	oti_setIm_IdxOrd( a, idx_to_set, ord_to_set, &num, dhl);

	oti_print(&num, dhl);

	// Test addition:
	num2 = oti_sum_real(a,&num,dhl);
	oti_print(&num2, dhl);	

	num1 = oti_sum(&num, &num2, dhl);
	oti_print(&num1,dhl);


	oti_free( &num2 );

	num2 = oti_mul_real(3.5, &num1, dhl);
	oti_print(&num2,dhl);

	oti_free( &num2 );

	num2 = oti_mul(&num, &num1, dhl);
	oti_print(&num2,dhl);

	oti_free( &num );
	oti_free( &num1 );
	oti_free( &num2 );

	

	printf("Unloading directions helpers\n");
	dhelp_free( &dhl );

	printf("Successfuly unloaded memory from direction helper\n");
	printf("Exiting now...\n");

	return 0;
}