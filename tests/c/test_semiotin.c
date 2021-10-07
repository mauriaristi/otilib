#include<oti/semisparse.h>
#include<time.h>


int main(int argc, char *argv[]){
	// Declarations
	char data_folder[] = "../../data"; // Useful for linux and macos distributions.
	dhelpl_t dhl; // Direction helper.
	uint64_t i;


	// 
	printf("Loading pre-computed data...\n");

	dhelp_load(data_folder, &dhl);
	
	printf("Successfuly loaded %d direction helpers.\n\n --- \n\n", dhl.ndh);




	printf("Testing creation of semi-sparse oti number.\n");
	semiotin_t num1, num2, num3;
	bases_t nbases = 3;
	coeff_t a = 0.5, b=3.78, c = 4.66;
	ord_t order  = 4;

	// Allocate memory first.
	num1 = ssoti_createReal(4.8,nbases, order, dhl);
	
	printf("Result after creating from empty.\n");
	ssoti_print(&num1, dhl);

	// Set all coefficients to 1.5 (including real coefficient).
	ssoti_help_set_all_coeffs( 1.5, &num1,dhl);
	ssoti_print_full(&num1, dhl);	
	
	for(i=0;i<64;i++) printf("=");printf("\n");
	
	// Test the reset order function.
	// num1.act_order = 3;
	num1.act_nbases = 2;
	ssoti_reset_orders(3, 5, &num1,  dhl);
	ssoti_print_full(&num1, dhl);

	ssoti_help_set_all_coeffs( 4.5, &num1,dhl);
	for(i=0;i<64;i++) printf("=");printf("\n");
	num1.act_order = 3;
	// ssoti_reset_nbases(1, 3, &num1,  dhl);
	ssoti_print_full(&num1, dhl);

	ssoti_set_im_r(1.11, 29, 6, &num1, dhl);
	ssoti_print_full(&num1, dhl);

	// soti_set_item(a,0,0,&num1,dhl); // Set real coefficient
	// soti_set_item(b,0,1,&num1,dhl); // Set Imaginary coefficient e(1)
	// soti_set_item(c,1,2,&num1,dhl); // Set imaginary coefficient e([1,2])
	// printf("\nResult after setting real and imaginary coefficients.\n");
	// soti_print(&num1, dhl);	

	// printf("\nResult of getting real coefficient "_PCOEFFT _ENDL,
	// 	soti_get_item(0,0,&num1,dhl) );
	// printf("Result of getting imaginary coefficient (0,1) "_PCOEFFT _ENDL,
	// 	soti_get_item(0,1,&num1,dhl) );
	// printf("Result of getting imaginary coefficient (1,2) "_PCOEFFT _ENDL,
	// 	soti_get_item(1,2,&num1,dhl) );
	// printf("Result of getting imaginary coefficient (2,2) "_PCOEFFT _ENDL,
	// 	soti_get_item(2,2,&num1,dhl) );



	// printf("\nResult after copying.\n");
	// num2 = soti_copy(&num1,dhl);
	// soti_print(&num2,dhl);

	
	// printf("\nResult after adding real coefficient.\n");
	// num3 = soti_sum_ro(c , &num2, dhl);
	// soti_print(&num3,dhl);	

	// soti_free(&num3);
	// printf("\nResult after multiplying by real coefficient.\n");
	// num3 = soti_mul_ro(c , &num2, dhl);
	// soti_print(&num3,dhl);
	// soti_free(&num2);

	// printf("\nResult after negating sotinum.\n");
	// num2 = soti_neg(&num3, dhl);
	// soti_print(&num2,dhl);

	// soti_free(&num2);
	// printf("\nResult after subtracting sotinum - real.\n");
	// num2 = soti_sub_or(&num3, a, dhl);
	// soti_print(&num2,dhl);

	// soti_free(&num2);
	// printf("\nResult after subtracting real - sotinum.\n");
	// num2 = soti_sub_ro( c, &num3, dhl);
	// soti_print(&num2,dhl);

	// soti_free(&num2);
	// printf("\nResult after dividing sotinum by real number.\n");
	// num2 = soti_div_or(&num3, b, dhl);
	// soti_print(&num2,dhl);

	// soti_set_item(c*3.3,3,3,&num3,dhl); 
	// soti_print(&num3,dhl);

	// soti_set_item(a*3.3,3,1,&num2,dhl); 
	// soti_set_item(b*3.3,0,3,&num2,dhl); 
	// soti_print(&num2,dhl);


	// soti_free(&num1);
	// printf("\nResult after adding two sotinums.\n");
	// num1 = soti_sum_oo(&num3,&num2,dhl);
	// soti_print(&num1,dhl);













	// // ---------------------------------- binary search ----------------------------
	// uint64_t arr[] ={4,5,8,9,10,17,21,34};
	// // uint64_t arr[] ={4};
	// uint64_t item = 105;
	// flag_t flag;

	// uint64_t pos = binSearchUI64(item, arr, 1, &flag );
	// printf("\nTesting binary search:\n");
	// if (flag == 0){
	// 	printf("Item %lu is not in array and should be inserted at %lu:\n",item, pos);
	// } else {
	// 	printf("Item %lu is in array and is at position: %lu -->Element extracted: %lu\n",
	// 		item, pos,arr[pos]);
	// }
	// // ---------------------------------- binary search ----------------------------



	printf("\nFreeing OTI numbers\n");
	ssoti_free(&num1); //soti_free(&num2); soti_free(&num3);

	printf("\nUnloading directions helpers\n");
	dhelp_free( &dhl );

	printf("Successfuly unloaded memory from direction helper\n");
	printf("Exiting now...\n");

	return 0;
}