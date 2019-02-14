#include<oti/otinum_dense.h>
#include<time.h>


int main(int argc, char *argv[]){
	// Declarations
	char data_folder[] = "/home/maristi7/coding/otilib/src/datagen/data"; // Useful for linux and macos distributions.
	dhelpl_t dhl; // Direction helper.


	// 
	// printf("Testing data loading from precomputed arrays:\n");

	dhelp_load(data_folder, &dhl);
	
	// printf("Successfuly loaded %d direction helpers.\n", dhelpl.ndh);




	printf("Testing creation of oti number.\n");
	otinum_t num, num1, num2;
	coeff_t a = 0.5, b=3.78, c = 4.66;
	bases_t nbases = 2;
	ord_t order  = 3;

	// Allocate memory first.
	num = oti_createEmpty( nbases, order, dhl);
	printf("Result after creating from empty.\n");
	oti_print(&num, dhl);		
	printf("after print\n");

	// Set From a real number:
	oti_setFromReal( a, &num, dhl);
	printf("Result after assigning from real %f.\n",a);
	oti_print(&num, dhl);	


	// Set element 
	imdir_t idx_to_set = 0;
	ord_t   ord_to_set = 3;
	printf("Result after assigning by index and order.\n");
	oti_setIm_IdxOrd( b, idx_to_set, ord_to_set, &num, dhl);
	idx_to_set = 1;
	ord_to_set = 2;
	oti_setIm_IdxOrd( 5*b-1, idx_to_set, ord_to_set, &num, dhl);
	idx_to_set = 0;
	ord_to_set = 1;
	oti_setIm_IdxOrd( (3*a+2*b+4*c)/5., idx_to_set, ord_to_set, &num, dhl);
	oti_print(&num, dhl);

	// Test addition with real
	printf("Result after adding real number %f.\n",c);
	printf("Expected result: %f.\n",a+c);
	num2 = oti_sum_real(c,&num,dhl);	
	oti_print(&num2, dhl);


	// Test addition with another oti number.
	printf("Result after adding two oti numbers:\n");
	num1 = oti_sum(&num, &num2, dhl);
	oti_print( &num1, dhl);
	oti_free( &num2 );

	// Test multiplication with real.
	printf("Result after multiplying by a real number:\n");
	num2 = oti_mul_real(3.5, &num1, dhl);
	oti_print(&num2,dhl);
	oti_free( &num2 );

	// Test multiplication between OTI numbers.
	printf("Result after multiplying by a oti number:\n");
	num2 = oti_mul(&num, &num1, dhl);
	oti_print(&num2,dhl);

    // Free all numbers.
	oti_free( &num  );
	oti_free( &num1 );
	oti_free( &num2 );

	otinum_t x = oti_createZero(nbases,order,dhl);
	otinum_t y = oti_createZero(nbases,order,dhl);

	oti_setFromReal(0.75, &x, dhl);
	oti_setFromReal(3.5 , &y, dhl);

	// Add peturbations
	oti_setIm_IdxOrd( 1.0, 0, 1, &x, dhl);
	oti_setIm_IdxOrd( 1.0, 1, 1, &y, dhl);
	
	// f(x,y) = ( x * y )^2
	otinum_t xy = oti_mul(&x, &y, dhl);

	otinum_t xy2 = oti_mul(&xy, &xy, dhl);
	otinum_t xy4 = oti_mul(&xy2, &xy2, dhl);
	printf("\n\n Result of evaluating f(x,y) = (x*y)^2\n");
	oti_print(&xy2,dhl);

	printf("\n Result of evaluating f(x,y) = (x*y)^4\n");
	oti_print(&xy4,dhl);

	printf("\n Result of negating (x*y)^4\n");
	otinum_t mxy4 = oti_neg(&xy4,dhl);
	oti_print(&mxy4,dhl);

	printf("\n Result of subtracting by itself:\n");
	otinum_t mxy2 = oti_sub(&xy2,&xy2,dhl);
	oti_print(&mxy2,dhl);


	oti_free( &x ); oti_free( &y ); oti_free( &xy );oti_free( &xy2 );oti_free( &xy4 );
	oti_free( &mxy2 );oti_free( &mxy4 );


	x = oti_createZero(nbases,order,dhl);
	oti_setFromReal(0.75, &x, dhl);
	oti_setIm_IdxOrd( 1.0, 0, 1, &x, dhl);

	printf("\n Result of evaluating sin(x):\n");
	otinum_t sinx = oti_sin(&x,dhl);
	oti_print( &sinx, dhl );
	oti_free( &x );oti_free( &sinx );


	x = oti_createZero(nbases,10,dhl);
	y = oti_createZero(nbases,10,dhl);

	oti_setFromReal(0.75 , &x, dhl);
	oti_setFromReal(3.5  , &y, dhl);

	// Add peturbations
	oti_setIm_IdxOrd( 1.0, 0, 1, &x, dhl);
	oti_setIm_IdxOrd( 1.0, 1, 1, &y, dhl);


	xy = oti_div(&y, &x, dhl);
	printf("\n Result of y/x:\n");
	oti_print(&xy, dhl);

	oti_free( &x );oti_free( &y );	oti_free( &xy );

	printf("Unloading directions helpers\n");
	dhelp_free( &dhl );

	printf("Successfuly unloaded memory from direction helper\n");
	printf("Exiting now...\n");

	return 0;
}