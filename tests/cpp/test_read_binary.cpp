#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<complex>
using namespace std;


int main(){
	string filename = "ndirs_n1_m10.npy";
	// string filename = "ndirs_n1_m1.npy";

	ifstream file;

	complex<double> a;
	complex<double>* p_a;



	// Test of complex class type initialization and pointer to class using malloc.
	a = 3.8;

	p_a = (complex<double>*) malloc(10*sizeof(complex<double>*));
	
	p_a[0] =    a;
	p_a[2] = 2.*a;
	p_a[4] = 3.*a;

	cout << a << p_a[0] << p_a[2] << p_a[4]<< p_a << endl;
	free(p_a);




	cout << "Opening file \"" << filename << "\"" << endl;
	
	file.open(filename);

	if (file.is_open()){
		 
		cout << " :) Opened file correctly." << endl;
		

	} else {
		
		cout << " :( File not opened." << endl;

	}

	file.close();

	cout << "... Quitting ..."<< endl;



	return 0;
}