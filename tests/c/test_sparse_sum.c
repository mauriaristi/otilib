#include<oti/core.h>








int main(int argc, char *argv[]){
	// Declarations
	char data_folder[] = "../../data"; // Useful for linux and macos distributions.
	dhelpl_t dhl; // Direction helper.

	dhelp_load(data_folder, &dhl);

	coeff_t p_im1[5] = {0.1,5.1,7.1,13.9,20.5};
	imdir_t p_idx1[5]= {  0,  5,  7,  13,  20};
	ndir_t  ndir1 = 5;

	coeff_t p_im2[5] = {0.2,6.5,7.5,16.9,20.1};
	imdir_t p_idx2[5]= {  0,  6,  7,  16,  20};
	ndir_t  ndir2 = 5;

	coeff_t p_imres[100] ;
	imdir_t p_idxres[100];
	ndir_t  ndirres = 0;


	printArrayDBL( p_im1, ndir1);printf("\n");
	printArrayUI64(p_idx1,ndir1);printf("\n\n");

	printArrayDBL( p_im2, ndir2);printf("\n");
	printArrayUI64(p_idx2,ndir2);printf("\n\n");

	dhelp_sparse_add_dirs( p_im1,   p_idx1,    ndir1,
                           p_im2,   p_idx2,    ndir2, 
                           p_imres, p_idxres, &ndirres,           
                           dhl);

	printArrayDBL( p_imres, ndirres);printf("\n");
	printArrayUI64(p_idxres,ndirres);printf("\n");

	printf("\n\n");

	printf("Unloading directions helpers\n");
	dhelp_free( &dhl );

	printf("Successfuly freed memory from direction helper\n");
	printf("Exiting now...\n");

	return 0;
}