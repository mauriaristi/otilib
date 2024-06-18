#include<oti/oti.h>


int main(){

	oarrm1n3_t x,f;

	// Create a variable x with real value 3.5
	x = oarrm1n3_ones( 3, 3 );
	f = oarrm1n3_createEmpty( 3, 3 );
	// Set its imaginary direction equal to 1.
	x.p_data[0].e1=1.0;

	// Evaluate the f = sqrt(x) (element-wise)
	oarrm1n3_sqrt_to(&x,&f);

	// Print f.
	onumm1n3_print(&f.p_data[0]);

	return 0;

}