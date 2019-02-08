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
	otinum_t num;
	coeff_t a = 0.5;
	bases_t nbases = 2;
	ord_t order  = 2;

	// Allocate memory first.
	oti_createEmpty( nbases, order, &num, dhl);

	// Set From a real number:
	oti_setFromReal( a, &num, dhl);

	// Set element 
	imdir_t idx_to_set = 2;
	ord_t   ord_to_set  = 2;
	oti_setIm_IdxOrd( a, 3, 2, &num, dhl);


	oti_print(&num, dhl);

	oti_free( &num );

	

	printf("Unloading directions helpers\n");
	dhelp_free( &dhl );

	printf("Successfuly unloaded memory from direction helper\n");
	printf("Exiting now...\n");

	return 0;
}