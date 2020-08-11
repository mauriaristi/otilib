#include"test_writer.h"

int main(){

	onumm2n5_t x,y;

	x = onumm2n5_set_r(3.5);

	x.e1 = 1;


	onumm2n5_print(x);

	printf("\n\n");
	
	y = onumm2n5_mul_oo(x,x);
	y = onumm2n5_mul_oo(y,y);
	
	onumm2n5_print(y);	

	return 0;
}