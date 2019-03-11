#include<oti/core.h>



void search_prev_dir_old(  coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1, // Input 1
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2, // Input 2 
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       imdir_t prev_idx, imdir_t next_idx, ndir_t curr_i1, ndir_t curr_i2,
                       dhelpl_t dhl);





// ****************************************************************************************************
void search_prev_dir_old(  coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1, // Input 1
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2, // Input 2 
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       imdir_t prev_idx, imdir_t next_idx, ndir_t curr_i1, ndir_t curr_i2,
                       dhelpl_t dhl){                                                  // Helper
	
	// i1 - > Index along im1
	// i2 - > Index along im2
	
	// Looking forward directions in the multtabl of im1 x im2 that are:
	// 
	// idx > prev_idx && idx <= next_idx
	 
	ndir_t  next_i1;
	ndir_t  next_i2;
	ord_t   ord_res;
	imdir_t idx_res;

	if (curr_i1 == ndir1-1){

		// No need to find more values.
		return;

	} else {
		next_i1 = curr_i1+1;

		for (next_i2 = 0; next_i2<curr_i2; next_i2++){

			dhelp_multDir( p_idx1[next_i1],ord1, p_idx2[next_i2],ord2 ,&idx_res, &ord_res , dhl);

			if (idx_res > prev_idx ){
				

				if (idx_res <= next_idx ){
					// Perform recursive call
					search_prev_dir_old(p_im1, p_idx1, ndir1, ord1, // Input 1
			                        p_im2, p_idx2, ndir2, ord2, // Input 2 
                                    p_imres, p_idxres, ndirres, // Result
                                    prev_idx, idx_res, next_i1, next_i2,
                       				dhl);

					// Add Direction
					printf("-adding %lu\n",idx_res);
					*ndirres += 1;


					search_prev_dir_old(p_im1, p_idx1, ndir1, ord1, // Input 1
			                        p_im2, p_idx2, ndir2, ord2, // Input 2 
                                    p_imres, p_idxres, ndirres, // Result
                                    idx_res, next_idx, next_i1, curr_i2,
                       				dhl);
					
					
				} else {
					search_prev_dir_old(p_im1, p_idx1, ndir1, ord1, // Input 1
			                        p_im2, p_idx2, ndir2, ord2, // Input 2 
                                    p_imres, p_idxres, ndirres, // Result
                                    prev_idx, next_idx, next_i1, curr_i2,
                       				dhl);
					break;
				}

			}
		
		}
		if (idx_res<= prev_idx){
			search_prev_dir_old(p_im1, p_idx1, ndir1, ord1, // Input 1
                        p_im2, p_idx2, ndir2, ord2, // Input 2 
                        p_imres, p_idxres, ndirres, // Result
                        prev_idx, next_idx, next_i1, curr_i2,
           				dhl);	
		}
		

		return;

	}

}
// ----------------------------------------------------------------------------------------------------











































int main(int argc, char *argv[]){
	// Declarations
	char data_folder[] = "../../data"; // Useful for linux and macos distributions.
	dhelpl_t dhl; // Direction helper.

	dhelp_load(data_folder, &dhl);

	printf("Testing multiplication of directions."_ENDL);

	imdir_t idx_res = 0;
	ord_t   ord_res = 0;

	imdir_t idx_res1 = 0;
	ord_t   ord_res1 = 0;

	imdir_t idx_res2 = 0;
	ord_t   ord_res2 = 0;

	ord_t  ord1=1, ord2=1;
	
	// imdir_t idx1[] = {0, 3, 4, 7     };
	coeff_t im1[] = {1,1,1,1,1,1,1};
	imdir_t idx1[] = {0, 1, 2, 3, 4, 5, 6};
	// imdir_t idx1[] = {0, 1, 2      };
	ndir_t ndir1 = 7;

	// imdir_t idx2[] = {2, 4, 7, 8, 9};
	coeff_t im2[] = {1,1,1,1,1,1,1};
	imdir_t idx2[] = {0,1,2,3,4,5,6};
	// imdir_t idx2[] = {0, 1, 2, 3, 4};
	ndir_t ndir2 = 7;


	ord_t ordmin = MIN(ord1,ord2);
	imdir2d_t tmp_multtabl = dhl.p_dh[ord1+ord2-1].p_multtabls[ordmin-1];

	ndir_t i,j;
	
	for ( i = 0; i<ndir1; i++){

		for ( j =0; j<ndir2; j++){
			
			
			dhelp_multDir( idx1[i],ord1, idx2[j],ord2 ,&idx_res, &ord_res , dhl);
			// printf("Multiply: ");
			// dhelp_printImdir(idx1[i],ord1,dhl);		
			// printf(" x ");
			// dhelp_printImdir(idx2[j],ord2,dhl);		
			// printf(" results in ");
			// dhelp_printImdir(idx_res, ord_res, dhl);		
			// printf("\n");

			// if (idx_res<idx_res2){
			// 	printf("%lu\n",idx_res);
			// } else {
			// 	idx_res2 = idx_res;
			// }

			// printf("Multiply: (%lu,%hhu) x (%lu,%hhu) = (%lu,%hhu)\n\n",idx1[i],ord1,idx2[j],ord2,idx_res, ord_res);
			printf("%6lu, ",idx_res);
			

		}
		printf("\n");
	}
	
	printf("\n\n");
	
	imdir_t idx_curr_res = 0;
	imdir_t idx_next_res = 0;
	ndir_t ndirres = 0;


	// Do first multiplication:
	// idx1[0] * idx2[0];
	dhelp_multDir( idx1[0],ord1, idx2[0],ord2 ,&idx_next_res, &ord_res , dhl);
	printf("Adding %lu\n",idx_next_res);
    ndirres++;
    idx_curr_res = idx_next_res;	
	// Check previous elements from next direction.:
	for ( i = 0; i<ndir1; i++){

		for ( j =0; j<ndir2; j++){

			dhelp_multDir( idx1[i],ord1, idx2[j],ord2 ,&idx_next_res, &ord_res , dhl);

			if (idx_next_res > idx_curr_res){
				// printf("next: %lu, prev: %lu,\n",idx_next_res,idx_curr_res);
				search_prev_dir_old(  NULL,  idx1, ndir1, ord1, // Input 1
		                          NULL,  idx2, ndir2, ord2, // Input 2 
		                          NULL,  NULL, &ndirres,           // Result
		                       idx_curr_res, idx_next_res, i, j,
		                       dhl);
		        // printf("Adding %lu, from ( %lu x %lu )\n",idx_next_res,idx1[i], idx2[j]);
		        printf("Adding %lu\n",idx_next_res);
		        ndirres++;
				idx_curr_res = idx_next_res;	
			}
		}
	}
	printf("Total predicted multiplications: %lu vs total performed: %lu\n",ndir1*ndir2,ndirres);


	imdir_t p_idx_res[100];
	coeff_t p_im_res[100];

	dhelp_sparse_mult( 
                       im2,idx2,ndir2,ord2,
		               im1,idx1,ndir1,ord1, 
                       p_im_res, p_idx_res, &ndirres,          
                       dhl);
	for ( i = 0; i<ndirres; i++){
		printf("%4lu, %f\n",p_idx_res[i],p_im_res[i]);
	} 
	printf("Total second pass multiplications: %lu vs total performed: %lu\n",ndir1*ndir2,ndirres);

	

	printf("\n\n");

	printf("Unloading directions helpers\n");
	dhelp_free( &dhl );

	printf("Successfuly freed memory from direction helper\n");
	printf("Exiting now...\n");

	return 0;
}