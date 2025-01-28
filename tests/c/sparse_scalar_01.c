#include<oti/oti.h>


int main(){

	sotinum_t x;
    dhelpl_t dhl;

	bases_t bases[] = {20,30};

	// Create a variable x with real value 3.5

	printf(" > Loading pre-computed data\n");
    dhelp_load("../data/", &dhl);

	printf(" > Loaded pre-computed data\n");
	
	x = soti_init();

	soti_pprint(&x, dhl);

	pritnf('Test - oti_createEmpty_bases \n');
	x = soti_createEmpty_bases(bases, 2, 2, dhl);
	soti_pprint(&x, dhl);
	soti_free(&x);


	pritnf('Test - soti_createReal_bases \n');
	x = soti_createReal_bases(0.5, bases, 2, 2, dhl);
	soti_pprint(&x, dhl);
	soti_free(&x);

	pritnf('Test - soti_createReal \n');
	x = soti_createReal(0.25, 0, dhl);
	soti_pprint(&x, dhl);
	soti_free(&x);



	dhelp_free( &dhl);

	return 0;

}