#include<oti/oti.h>


int main(){

	sotinum_t x;
    dhelpl_t dhl;

	bases_t bases[] = {20,30};

	// Create a variable x with real value 3.5

	// ---------------------------------------------------------------------------------------------------
	// TEST soti_init
	// ---------------------------------------------------------------------------------------------------

	printf(" > Loading pre-computed data\n");

    dhelp_load("../data/", &dhl);

	printf(" > Loaded pre-computed data\n");
	// ---------------------------------------------------------------------------------------------------
	

	// Initialize the OTI structure. This essentially nullyfies the number.
	printf("Test - soti_init \n");
	x = soti_init();
	// Cant be printed. - This should output nothing.
	soti_pprint(&x, dhl);


	// ---------------------------------------------------------------------------------------------------
	// TEST soti_createEmpty_bases
	// ---------------------------------------------------------------------------------------------------
	printf("Test - soti_createEmpty_bases \n");
	x = soti_createEmpty_bases(bases, 2, 2, dhl);
	soti_pprint(&x, dhl);
	soti_free(&x);

	// ---------------------------------------------------------------------------------------------------



	// ---------------------------------------------------------------------------------------------------
	// TEST soti_createReal_bases
	// ---------------------------------------------------------------------------------------------------
	bases[0] = 1;
	bases[1] = 4;
	printf("Test - soti_createReal_bases \n");
	x = soti_createReal_bases(0.5, bases, 2, 2, dhl);
	soti_pprint(&x, dhl);
	soti_free(&x);
	// ---------------------------------------------------------------------------------------------------

	// ---------------------------------------------------------------------------------------------------
	// TEST soti_createReal
	// ---------------------------------------------------------------------------------------------------
	printf("Test - soti_createReal \n");
	x = soti_createReal(0.25, dhl);
	soti_print_struct(&x, dhl); 
	soti_pprint(&x, dhl); 
	soti_free(&x);
	// ---------------------------------------------------------------------------------------------------



	dhelp_free( &dhl);

	return 0;

}