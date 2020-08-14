#include"test_writer.h"
#include <time.h>

clock_t start, end;
double cpu_time_used;


/*
// ****************************************************************************************************
void der_r_pow(coeff_t x, coeff_t e, ord_t order, coeff_t* derivs){
    
    coeff_t power_i = e;
    coeff_t x0 = x;
    uint8_t flag = 0;
    coeff_t factor = 1.;
    uint8_t i;
    
    for (i=0; i<(order+1); i++){
        if( power_i != 0.0){            
            derivs[i] = factor * pow(x0,power_i);
            factor = factor*power_i;
            power_i -= 1.;
        }else{
            if (i==0){
                derivs[i] = x0; // not sure if 1.0 or if coefs[0]
                flag = 1;
            } else if (flag == 0 ){
                derivs[i]=factor;
                flag = 1;
            }else{ 
                derivs[i] = 0.;
            }        
        }
    }  
}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
onumm2n5_t onumm2n5_pow(onumm2n5_t* x, double e){

    coeff_t derivs[6];

    der_r_pow(x->r, e, 5, derivs);

    return onumm2n5_feval(derivs, x);

}
// ----------------------------------------------------------------------------------------------------
*/


int main(){

	onumm2n5_t x,y,z;
	ord_t order = 1;
	imdir_t idx = 0;
	int niter = 1e7;
	double niterd = (double)niter;
	coeff_t cf;
	coeff_t derivs[6];

    

	x = onumm2n5_create_r(3.5);
	y = onumm2n5_create_r(-2.5);
	x.e1 = 1;
	y.e2 = 1;

	printf("x:\n");
	onumm2n5_print(&x);
	
	printf("y:\n");
	onumm2n5_print(&y);

	printf("\n\n");
	
	x = onumm2n5_mul_oo(&x,&x);
	y = onumm2n5_mul_oo(&y,&y);
	
	onumm2n5_mul_oo_to(&x,&y,&z);

	printf("x^2:\n");
	onumm2n5_print(&x);	

	printf("y^2:\n");
	onumm2n5_print(&y);	
	
	printf("\n\n");

	printf("z = x^2 * y^2:\n");
	onumm2n5_print(&z);	

	cf = onumm2n5_get_item(idx,order,&z);
	printf("im[%llu,%hhu](z)=%f\n",idx,order,cf);
	onumm2n5_print(&z);	

	


	x = onumm2n5_create_r(3.5);
	x.e1 = 1;
	y = onumm2n5_mul_oo(&x,&x); //2
	y = onumm2n5_mul_oo(&x,&y); //3
	y = onumm2n5_mul_oo(&x,&y); //4
	y = onumm2n5_mul_oo(&x,&y); //5
	printf("y = x * x * x * x * x (x^5):\n");
	onumm2n5_print(&y);	

	x = onumm2n5_create_r(3.5);
	x.e1 = 1;
	z = onumm2n5_pow(&x,5.0);
	printf("z = x^5.0:\n");
	onumm2n5_print(&z);		

	y = onumm2n5_create_r(0.5);
	y.e2 = 1;
	z = onumm2n5_pow(&x,-1);
	z = onumm2n5_mul_oo(&z,&y);
	z = onumm2n5_pow(&z,0.5);
	printf("z = f(x,y):\n");
	onumm2n5_print(&z);		






	// Measure time:


	
	start = clock();
	
	for (int i=0; i<niter; i++){
		x = onumm2n5_create_r(3.5);
		x.e1 = 1;
		y = onumm2n5_mul_oo(&x,&x); //2
		y = onumm2n5_mul_oo(&x,&y); //3
		y = onumm2n5_mul_oo(&x,&y); //4
		y = onumm2n5_mul_oo(&x,&y); //5
		// x = onumm2n5_mul_oo(&x,&x);
	}

	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cpu_time_used = cpu_time_used/niterd*1000000000.;

	printf("\n\nCPU time per multiplication is: %g ns \n", cpu_time_used);

	x = onumm2n5_create_r(3.5);
	x.e1 = 1;

	start = clock();
	for (int i=0; i<niter; i++){
		z = onumm2n5_pow(&x,0.5);
		// der_r_pow(x.r, 5.0, 5, derivs);
	}

	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cpu_time_used = cpu_time_used/niterd*1000000000.;

	printf("\n\nCPU time per multiplication (2) is: %g ns \n", cpu_time_used);
	return 0;
}