#include "c_otilib.h"
#include <time.h>

#define NITER 1000000 // 10^6...


#define MAXORD 10

int main(){

	uint8_t order    =  3;
	

	clock_t start, end;
    double cpu_time_used;
	directionHelper* p_dH = NULL;
	uint64_t indx = 1, indx2 = 4;
	uint64_t foundIndx,foundIndx2 ;
	uint8_t err = 1;
	char directory[] = "./";

	uint64_t ii,jj;


	// Load the direction helper.
	c_helper_load(MAXORD,directory, &p_dH);

    // printf("This is the direction array of index %llu\n",)

    for(indx = 0; indx<30; indx++){
	    
	    printf("i: %llu\t",indx);

	    c_printArrayUI16(c_helper_getDirA(indx,order,p_dH),order);

	    c_printArrayUI8(c_helper_getExpA(indx,order,p_dH),order);

	    printf("\n");
	}


	// TEST SEARCH FUNCTION

	indx = 100;
	uint16_t* p_dirA = c_helper_getDirA(indx,order,p_dH);
	uint8_t*  p_expA = c_helper_getExpA(indx,order,p_dH);

	
	foundIndx =  c_helper_findIndex(p_dirA,p_expA,order,p_dH);
	


	for (ii=0;ii<10;ii++){
		
		for (jj=0;jj<10;jj++){
			foundIndx =  c_helper_multIndx(ii, jj,order,p_dH, &err); 
			if (err == 1){
				foundIndx = 0;
			}
			foundIndx2 =  c_helper_multIndxFast(ii, jj, order, p_dH, &err);
			if (err == 1){
				foundIndx2 = 0;
			}
			if (foundIndx == foundIndx2){
				err = 0;
			} else {
				err = 1;
			}
			printf("mul %llu * %llu ->  %llu, %llu  |  %hhu      \n",ii,jj,foundIndx,foundIndx2,err);


		}

	}

	indx = 1;
	
	foundIndx =  c_helper_multIndx(indx, indx2,order,p_dH, &err); 
	printf("Found index 1 : %llu\n",foundIndx);


	foundIndx2 =  c_helper_multIndxFast(indx, indx2,order,p_dH, &err); 
	printf("Found index 2 : %llu\n",foundIndx2);
    start = clock();


    for(int i=0;i<NITER;i++){

    	// foundIndx =  c_helper_findIndex(p_dirA,p_expA,order,p_dH);  // 290 ns for o2, 390 ns o3, 460 ns o4
    	// foundIndx =  c_helper_multIndx(indx, indx2, order, p_dH, &err);  // 290 ns for o2, 390 ns o3, 460 ns o4
    	foundIndx2 =  c_helper_multIndxFast(indx, indx2, order, p_dH, &err);  // 42.4 ns for o2,  ns o3,  43.6 ns o4

    }


    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n: time of run:  %f us\n\n", cpu_time_used );
	
	printf("Found index after several repetitions: %llu\n",foundIndx2);



	printf("\n\n\n Computing multiples of : ");
	uint64_t Nmultpl;
	order = 3;
	indx = 3;
	c_printArrayUI16(c_helper_getDirA(indx,order,p_dH),order); 
	c_printArrayUI8(c_helper_getExpA(indx,order,p_dH),order); printf("\n\n");

	c_helper_getMultpl(c_helper_getExpA(indx,order,p_dH), order, p_dH, &Nmultpl);

	for(int i=0;i<Nmultpl;i++){
		c_printArrayUI8(&p_dH[order-1].p_multpl[i*order],order);
		printf("\n");
	}



	printf("\n\n\n Expanding arrays\n");




	for(indx = 0; indx<30; indx++){
	    
	    printf("i: %llu\t",indx);

	    c_printArrayUI16(c_helper_getDirA(indx,order,p_dH),order);

	    c_printArrayUI8(c_helper_getExpA(indx,order,p_dH),order);

	    printf(" -> ");

	    c_oti_expandDirA(c_helper_getDirA(indx,order,p_dH),c_helper_getExpA(indx,order,p_dH),
	    	order, p_dH[order-1].p_udirA);

	    c_printArrayUI16(p_dH[order-1].p_udirA,order);

	    c_oti_collapseDirA(p_dH[order-1].p_udirA, order, &p_dH[order-1].p_udirA[order],&p_dH[order-1].p_uexpA[order]);

	    printf(" -> ");

	    c_printArrayUI16(&p_dH[order-1].p_udirA[order],order);

	    c_printArrayUI8(&p_dH[order-1].p_uexpA[order],order);


	    //c_oti_expandDirA(uint16_t* p_dirA,uint8_t* p_expA, uint8_t order, uint16_t* p_expandArr)

	    printf("\n");
	}





	c_helper_free(p_dH, MAXORD);
	
	return 0;
}