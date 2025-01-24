#include<oti/oti.h>


int main(){

	sotinum_t x;
    dhelpl_t dhl;

	bases_t bases[] = {2,3};

	// Create a variable x with real value 3.5

	printf(" > Loading pre-computed data\n");
    dhelp_load("../data/", &dhl);

	printf(" > Loaded pre-computed data\n");
	
	x = soti_init();

	soti_pprint(&x, dhl);

	x = soti_createEmpty_bases(bases, 2, 2, dhl);

	soti_pprint(&x, dhl);

	soti_free(&x);


	dhelp_free( &dhl);

	return 0;

}