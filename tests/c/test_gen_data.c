#include<oti/core.h>

int main(int argc, char *argv[]){

	// Declarations
	bases_t nbases[] = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};// Up to order 20
	ord_t maxorder = 10;
	dhelpl_t dhl;
	dhelp_precompute("", nbases, maxorder);
	
	printf("__________________________________________________\n");
	printf("Finished precomputation of data.\n");
	printf("Exiting now...\n");

	return 0;
}