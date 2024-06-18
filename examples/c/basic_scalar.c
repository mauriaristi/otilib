#include<oti/oti.h>


int main(){

	onumm1n3_t x,f;

	// Create a variable x with real value 3.5
	onumm1n3_set_r(  3.5, &x);
	// Set its imaginary direction equal to 1.
	x.e1=1.0;

	// Evaluate the f = sin(x)
	onumm1n3_sin_to(&x,&f);

	// Print f.
	onumm1n3_print(&f);

	return 0;

}