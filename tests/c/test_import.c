#include<oti/core.h>
#include<time.h>


int main(int argc, char *argv[]){
	// Declarations
	char data_folder[] = "/home/maristi7/coding/otilib/src/datagen/data"; // Useful for linux and macos distributions.
	dhelpl_t dhelpl; // Direction helper.


	// 
	printf("Testing data loading from precomputed arrays:"_ENDL);

	dhelp_load(data_folder, &dhelpl);
	
	printf("Successfuly loaded "_PNDHT" direction helpers."_ENDL, dhelpl.ndh);
	
	// Print direction helpers.
	dhelp_printList(dhelpl);




	printf("Testing multiplication of directions."_ENDL);

	imdir_t idx_res = 0;
	ord_t   ord_res = 0;
	dhelp_multDir( 15,4, 50,2 ,&idx_res, &ord_res , dhelpl);
	printf("Multiplying directions (15,4) x (50,2) = ("_PUINT64T","_PORDT")"_ENDL,idx_res,ord_res);

	printf("\n\n Printing of imaginary directions:\n");

	printf("Printing (0,1)\n"); 
	dhelp_printImdir(0,1,dhelpl);
	printf(_ENDL);
	printf("Printing (0,2)\n"); 
	
	dhelp_printImdir(0,2,dhelpl);
	printf(_ENDL);

	printf("Printing (15,4)\n"); 
	dhelp_printImdir(15,4,dhelpl);
	printf(_ENDL);

	printf("Printing (50,2)\n"); 
	dhelp_printImdir(50,2,dhelpl);
	printf(_ENDL);

	printf("Printing result of (15,4) x (50,2)\n"); 
	dhelp_printImdir(idx_res,ord_res,dhelpl);
	printf(_ENDL);

	// Check CPU time of the multiplication:
	int ordi = 4;
	int ordj = 6;
	ndir_t Ni = dhelpl.p_dh[ordi-1].Ndir;
	ndir_t Nj = dhelpl.p_dh[ordj-1].Ndir;
	clock_t start, end;
    double cpu_time_used;
    
    start = clock(); 
	for(imdir_t i = 0; i<Ni; i++){
		for(imdir_t j = 0; j<Nj; j++){
			// printf("Multiplying ");
			// dhelp_printImdir(i,ordi,dhelpl);		
			// printf(" X ");
			// dhelp_printImdir(j,ordj,dhelpl);		
			// printf(" = ");
			dhelp_multDir( i,ordi, j, ordj, &idx_res, &ord_res, dhelpl);
			// dhelp_printImdir( idx_res, ord_res, dhelpl);		
			// printf("\n");
			// printf("Multiplying directions ("_PUINT64T",%hhd) x ("_PUINT64T",%hhd) = ("_PUINT64T",%hhd)\n",
			// 	i,ordi,j,ordj,idx_res,ord_res);

		}

	}
	end = clock();
    cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC*1000000)/(Ni*Nj);

	printf("CPU time per multiplication: %g us\n",cpu_time_used);   

	

	// Test Combinatorics:
	printf("\n\nComputing combinatorics...\n");    
	printf("comb("_PINT", "_PINT") = "_PUINT64T _ENDL,15,5,dhelp_comb(15,5));    
	printf("Total number of directions for nbases "_PINT", order "_PINT" = "_PUINT64T" \n",15,5,dhelp_ndirTotal(15,5));  
	printf("Total number of directions for nbases "_PINT", order "_PINT" = "_PUINT64T" \n",10,5,dhelp_ndirTotal(10,5));  
	printf("Extracted total num of dir for nbases "_PINT", order "_PINT" = "_PUINT64T" \n",10,5,dhelp_extract_ndirTotal(10,5, dhelpl));  
	printf("Number of directions with order "_PINT" for nbases "_PINT" = "_PUINT64T" \n",5,15,dhelp_ndirOrder(15,5));    
	printf("Number of directions with order "_PINT" for nbases "_PINT" = "_PUINT64T" \n",5,4,dhelp_ndirOrder(5,4));    
	printf("Extracted Num of dir with order "_PINT" for nbases "_PINT" = "_PUINT64T" \n",5,4,dhelp_extract_ndirOrder(5,4,dhelpl));    


	printf("Unloading directions helpers\n");
	dhelp_free( &dhelpl );

	printf("Successfuly unloaded memory from direction helper\n");
	printf("Exiting now...\n");

	return 0;
}