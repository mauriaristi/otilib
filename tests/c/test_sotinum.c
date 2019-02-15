#include<oti/otinum_spr.h>
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
	sotinum_t num1, num2, num3;
	coeff_t a = 0.5, b=3.78, c = 4.66;
	ord_t order  = 3;

	// Allocate memory first.
	num1 = soti_createEmpty( order, dhl);
	printf("Result after creating from empty.\n");
	soti_print(&num1, dhl);	

	soti_set_item(a,0,0,&num1,dhl); // Set real coefficient
	soti_set_item(b,0,1,&num1,dhl); // Set Imaginary coefficient e(1)
	soti_set_item(c,1,2,&num1,dhl); // Set imaginary coefficient e([1,2])
	printf("\nResult after setting real an imaginary coefficients.\n");
	soti_print(&num1, dhl);	

	printf("\nResult of getting real coefficient "_PCOEFFT _ENDL,
		soti_get_item(0,0,&num1,dhl) );
	printf("Result of getting imaginary coefficient (0,1) "_PCOEFFT _ENDL,
		soti_get_item(0,1,&num1,dhl) );
	printf("Result of getting imaginary coefficient (1,2) "_PCOEFFT _ENDL,
		soti_get_item(1,2,&num1,dhl) );
	printf("Result of getting imaginary coefficient (2,2) "_PCOEFFT _ENDL,
		soti_get_item(2,2,&num1,dhl) );


	uint64_t arr[] ={4,5,8,9,10,17,21,34};
	// uint64_t arr[] ={4};
	uint64_t item = 105;
	flag_t flag;

	uint64_t pos = binSearchUI64(item, arr, 1, &flag );
	printf("\nTesting binary search:\n");
	if (flag == 0){
		printf("Item %lu is not in array and should be inserted at %lu:\n",item, pos);
	} else {
		printf("Item %lu is in array and is at position: %lu -->Element extracted: %lu\n",
			item, pos,arr[pos]);
	}
	




	soti_free(&num1);

	printf("\nUnloading directions helpers\n");
	dhelp_free( &dhl );

	printf("Successfuly unloaded memory from direction helper\n");
	printf("Exiting now...\n");

	return 0;
}