#include<oti/core.h>


void add_coeff(coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,
			   coeff_t im,imdir_t idx);

void search_prev_dir_old(  coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1, // Input 1
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2, // Input 2 
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       imdir_t prev_idx, imdir_t next_idx, ndir_t curr_i1, ndir_t curr_i2,
                       dhelpl_t dhl);
void search_prev_dir(  coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1, // Input 1
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2, // Input 2 
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       imdir_t prev_idx, imdir_t next_idx, ndir_t curr_i1, ndir_t curr_i2,
                       imdir2d_t tmp_multtabl);
void dhelp_mult_sparse(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1, // Input 1
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2, // Input 2
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       dhelpl_t dhl);





void add_coeff(coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,
			   coeff_t im,imdir_t idx){

	// This function assumes that the 
	

	if (p_idxres == idx){
		
		p_imres[(*ndirres)-1] += im;

	} else {
	
		p_imres[(*ndirres)] = im;
		p_idxres[(*ndirres)] = idx;
		(*ndirres) += 1;	

	}
}

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

					// printf("-adding %lu, from ( %lu x %lu )\n",idx_res, p_idx1[next_i1], p_idx2[next_i2]);
					printf("-adding %lu\n",idx_res);
					*ndirres += 1;

					search_prev_dir_old(p_im1, p_idx1, ndir1, ord1, // Input 1
			                        p_im2, p_idx2, ndir2, ord2, // Input 2 
                                    p_imres, p_idxres, ndirres, // Result
                                    idx_res, next_idx, next_i1, curr_i2,
                       				dhl);
					// Add direction.
					// add_direction(p_imres, p_idxres, ndirres,
					// 			  );
					
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


void search_prev_dir(  coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1, // Input 1
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2, // Input 2 
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       imdir_t prev_idx, imdir_t next_idx, ndir_t curr_i1, ndir_t curr_i2,
                       imdir2d_t tmp_multtabl){                                        // Helper
	
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

			// dhelp_multDir( p_idx1[next_i1],ord1, p_idx2[next_i2],ord2 ,&idx_res, &ord_res , dhl);
			idx_res = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],p_idx1[next_i1],p_idx2[next_i2]); 


			if (idx_res > prev_idx ){
				

				if (idx_res <= next_idx ){
					// Perform recursive call
					search_prev_dir(p_im1, p_idx1, ndir1, ord1, // Input 1
			                        p_im2, p_idx2, ndir2, ord2, // Input 2 
                                    p_imres, p_idxres, ndirres, // Result
                                    prev_idx, idx_res, next_i1, next_i2,
                       				tmp_multtabl);

					// printf("-adding %lu, from ( %lu x %lu )\n",idx_res, p_idx1[next_i1], p_idx2[next_i2]);
					printf("-adding %lu\n",idx_res);
					*ndirres += 1;

					search_prev_dir(p_im1, p_idx1, ndir1, ord1, // Input 1
			                        p_im2, p_idx2, ndir2, ord2, // Input 2 
                                    p_imres, p_idxres, ndirres, // Result
                                    idx_res, next_idx, next_i1, curr_i2,
                       				tmp_multtabl);
					// Add direction.
					// add_direction(p_imres, p_idxres, ndirres,
					// 			  );
					
				} else {
					search_prev_dir(p_im1, p_idx1, ndir1, ord1, // Input 1
			                        p_im2, p_idx2, ndir2, ord2, // Input 2 
                                    p_imres, p_idxres, ndirres, // Result
                                    prev_idx, next_idx, next_i1, curr_i2,
                       				tmp_multtabl);
					break;
				}

			}
		
		}
		if (idx_res<= prev_idx){
			search_prev_dir(p_im1, p_idx1, ndir1, ord1, // Input 1
                        p_im2, p_idx2, ndir2, ord2, // Input 2 
                        p_imres, p_idxres, ndirres, // Result
                        prev_idx, next_idx, next_i1, curr_i2,
           				tmp_multtabl);	
		}
		

		return;

	}
	


}




void dhelp_mult_sparse(coeff_t* p_im1,   imdir_t* p_idx1,   ndir_t  ndir1, ord_t ord1, // Input 1
                       coeff_t* p_im2,   imdir_t* p_idx2,   ndir_t  ndir2, ord_t ord2, // Input 2
                       coeff_t* p_imres, imdir_t* p_idxres, ndir_t* ndirres,           // Result
                       dhelpl_t dhl){                            // Helper


	ord_t     tmp_ord      = ord1 + ord2;
    imdir2d_t tmp_multtabl ;

	imdir_t idx_curr_res = 0;
	imdir_t idx_next_res = 0;
	(*ndirres) = 0;
	
	coeff_t* p_immin;
	imdir_t* p_idxmin;
	ndir_t   ndirmin;
	ord_t    ordmin;

	coeff_t* p_immax;
	imdir_t* p_idxmax;
	ndir_t  ndirmax;
	ord_t ordmax;

	if (ndir1 >0 && ndir2 >0){

		// Sort input directions by order.
		
		if(ord1 < ord2){

			p_immin  = p_im1;
			p_idxmin = p_idx1;
			ndirmin  = ndir1;
			ordmin   = ord1;

			p_immax  = p_im2;
			p_idxmax = p_idx2;
			ndirmax  = ndir2;
			ordmax   = ord2;

		} else {
			
			p_immin  = p_im2;
			p_idxmin = p_idx2;
			ndirmin  = ndir2;
			ordmin   = ord2;

			p_immax  = p_im1;
			p_idxmax = p_idx1;
			ndirmax  = ndir1;
			ordmax   = ord1;

		}

		// Get the relevant multiplication table.
		tmp_multtabl = dhl.p_dh[tmp_ord-1].p_multtabls[ordmin-1];
		
		// Do first multiplication:
		// idx1[0] * idx2[0];
		
	    idx_next_res = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],p_idxmin[0],p_idxmax[0]); 

		printf("Adding %lu\n",idx_next_res);
	    (*ndirres)+=1;

	    idx_curr_res = idx_next_res;	
		// Check previous elements from next direction.:
		for (ndir_t i = 0; i<ndirmin; i++){

			for (ndir_t j = 0; j<ndirmax; j++){

				idx_next_res = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],p_idxmin[i],p_idxmax[j]); 

				if (idx_next_res > idx_curr_res){
					// printf("next: %lu, prev: %lu,\n",idx_next_res,idx_curr_res);
					search_prev_dir(  p_immin,  p_idxmin, ndirmin, ordmin, 
			                          p_immax,  p_idxmax, ndirmax, ordmax, 
			                          p_imres,  p_idxres, ndirres,         
			                       	  idx_curr_res, idx_next_res, i, j,tmp_multtabl);
			        // printf("Adding %lu, from ( %lu x %lu )\n",idx_next_res,idx1[i], idx2[j]);
			        printf("Adding %lu\n",idx_next_res);
			        *(ndirres)+=1;
					idx_curr_res = idx_next_res;	
				}
			}
		}
	}

}










































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
	imdir_t idx1[] = {0, 1, 2, 3, 4, 5, 6};
	// imdir_t idx1[] = {0, 1, 2      };
	ndir_t ndir1 = 7;

	// imdir_t idx2[] = {2, 4, 7, 8, 9};
	imdir_t idx2[] = {0,1,2,3,4,5,6};
	// imdir_t idx2[] = {0, 1, 2, 3, 4};
	ndir_t ndir2 = 7;

	ord_t ordmin = MIN(ord1,ord2);
	imdir2d_t tmp_multtabl = dhl.p_dh[ord1+ord2-1].p_multtabls[ordmin-1];

	for (ndir_t i = 0; i<ndir1; i++){

		for (ndir_t j =0; j<ndir2; j++){
			
			
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
	for (ndir_t i = 0; i<ndir1; i++){

		for (ndir_t j =0; j<ndir2; j++){

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


	dhelp_mult_sparse( 
                       NULL,idx2,ndir2,ord2,
		               NULL,idx1,ndir1,ord1, 
                       NULL, NULL, &ndirres,          
                       dhl);

	printf("Total second pass multiplications: %lu vs total performed: %lu\n",ndir1*ndir2,ndirres);

	// while ( 1 ){	
		
	// 	curr_i1 = max_i1;
	// 	curr_i2 = max_i2;
	// 	// Multiply current dir 1 with mul 1.
	// 	dhelp_multDir( idx1[curr_i1],ord1, idx2[mul_i1],ord2 ,&idx_res1, &ord_res1 , dhl);

	// 	// printf("\nMultiplied: ");
	// 	// dhelp_printImdir(idx1[curr_i1],ord1,dhl);		
	// 	// printf(" x ");
	// 	// dhelp_printImdir(idx2[mul_i1],ord2 ,dhl);		
	// 	// printf(" results in ");
	// 	// dhelp_printImdir(idx_res1, ord_res1, dhl);


	// 	// Multiply current dir 2 with mul 2.
	// 	dhelp_multDir( idx2[curr_i2],ord2, idx1[mul_i2],ord1 ,&idx_res2, &ord_res2 , dhl);

	// }

	printf("\n\n");

	printf("Unloading directions helpers\n");
	dhelp_free( &dhl );

	printf("Successfuly freed memory from direction helper\n");
	printf("Exiting now...\n");

	return 0;
}