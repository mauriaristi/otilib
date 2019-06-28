#include<string>
#include<iostream>
#include<fstream>

using namespace std;


int main(){
	string filename = "ndirs_n1_m10.npy";
	// string filename = "ndirs_n1_m1.npy";

	ifstream file;



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