
# include <iostream>
# include <vector>

using namespace std;

int main (){
	vector<double> a;

	a.resize(10,5.35);

	for(int i =0; i<a.size(); i++){

		cout << a[i] << endl;	
		
	}
	

}

