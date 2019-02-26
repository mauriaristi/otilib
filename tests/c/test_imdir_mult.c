#include<oti/core.h>


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
	
	imdir_t idx1[] = {0, 4, 5     };
	imdir_t idx2[] = {2, 4, 7, 8, 9};

	ord_t ordmin = MIN(ord1,ord2);
	imdir2d_t tmp_multtabl = dhl.p_dh[ord1+ord2-1].p_multtabls[ordmin-1];

	// for (ndir_t i = 0; i<3; i++){

	// 	for (ndir_t j =0; j<5; j++){
			
			
	// 		dhelp_multDir( idx1[3-i],ord1, idx2[4-j],ord2 ,&idx_res, &ord_res , dhl);
	// 		printf("Multiply: ");
	// 		dhelp_printImdir(idx1[3-i],ord1,dhl);		
	// 		printf(" x ");
	// 		dhelp_printImdir(idx2[4-j],ord2,dhl);		
	// 		printf(" results in ");
	// 		dhelp_printImdir(idx_res, ord_res, dhl);		
	// 		printf("\n");

	// 		printf("Multiply: (%lu,%hhu) x (%lu,%hhu) = (%lu,%hhu)\n\n",idx1[i],ord1,idx2[j],ord2,idx_res, ord_res);
			

	// 	}
	// }
	
	ndir_t curr_i1 = 2, curr_i2=4;
	ndir_t max_i1 = 2, max_i2=4;
	
	while ( 1 ){	
		
		if ( idx1[curr_i1] > idx2[curr_i2] ){
			// Here Index 1 has a larger number, but what if they have different orders?

			while(1){
				dhelp_multDir( idx1[curr_i1],ord1, idx2[curr_i2],ord2 ,&idx_res, &ord_res , dhl);
				printf("Multiply: ");
				dhelp_printImdir(idx1[curr_i1],ord1,dhl);		
				printf(" x ");
				dhelp_printImdir(idx2[curr_i2],ord2,dhl);		
				printf(" results in ");
				dhelp_printImdir(idx_res, ord_res, dhl);		
				printf("\n");

				printf("Multiply: (%lu,%hhu) x (%lu,%hhu) = (%lu,%hhu)\n\n",idx1[curr_i1],ord1,idx2[curr_i2],ord2,idx_res, ord_res);

				if (curr_i2 == 0){
					
					break;

				} else {
				
					curr_i2--;

				}

			}
			if (max_i1 == 0){
				
				break;

			}else{

				max_i1--;

			}

		} else if (idx1[curr_i1]<idx2[curr_i2]){

			while(1){
				dhelp_multDir( idx1[curr_i1],ord1, idx2[curr_i2],ord2 ,&idx_res, &ord_res , dhl);
				printf("Multiply: ");
				dhelp_printImdir(idx1[curr_i1],ord1,dhl);		
				printf(" x ");
				dhelp_printImdir(idx2[curr_i2],ord2,dhl);		
				printf(" results in ");
				dhelp_printImdir(idx_res, ord_res, dhl);		
				printf("\n");

				printf("Multiply: (%lu,%hhu) x (%lu,%hhu) = (%lu,%hhu)\n\n",idx1[curr_i1],ord1,idx2[curr_i2],ord2,idx_res, ord_res);

				if (curr_i1 == 0){
					
					break;

				} else {
				
					curr_i1--;

				}

			}
			if (max_i2 == 0){
				
				break;

			}else{

				max_i2--;

			}


		} else {
			printf("found equal case\n");

			dhelp_multDir( idx1[curr_i1],ord1, idx2[curr_i2],ord2 ,&idx_res, &ord_res , dhl);
			printf("Multiply: ");
			dhelp_printImdir(idx1[curr_i1],ord1,dhl);		
			printf(" x ");
			dhelp_printImdir(idx2[curr_i2],ord2,dhl);		
			printf(" results in ");
			dhelp_printImdir(idx_res, ord_res, dhl);		
			printf("\n");

			printf("Multiply: (%lu,%hhu) x (%lu,%hhu) = (%lu,%hhu)\n\n",idx1[curr_i1],ord1,idx2[curr_i2],ord2,idx_res, ord_res);
			
			// while(1){	

			// 	dhelp_multDir( idx1[curr_i1],ord1, idx2[curr_i2],ord2 ,&idx_res, &ord_res , dhl);
			// 	printf("Multiply: ");
			// 	dhelp_printImdir(idx1[curr_i1],ord1,dhl);		
			// 	printf(" x ");
			// 	dhelp_printImdir(idx2[curr_i2],ord2,dhl);		
			// 	printf(" results in ");
			// 	dhelp_printImdir(idx_res, ord_res, dhl);		
			// 	printf("\n");

			// 	printf("Multiply: (%lu,%hhu) x (%lu,%hhu) = (%lu,%hhu)\n\n",idx1[curr_i1],ord1,idx2[curr_i2],ord2,idx_res, ord_res);

			// 	if (curr_i1 == 0){
					
			// 		break;

			// 	} else {
				
			// 		curr_i1--;

			// 	}

			// }

			break;
		}

		curr_i1 = max_i1;
		curr_i2 = max_i2;
		// if idx2[curr_i2]




	}

	printf("Unloading directions helpers\n");
	dhelp_free( &dhl );

	printf("Successfuly freed memory from direction helper\n");
	printf("Exiting now...\n");

	return 0;
}