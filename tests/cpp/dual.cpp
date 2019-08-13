// Basic implementation of dual numbers


#include<fstream>
#include<cmath>


template<class T>
class CayleyDickson{

private:
	T r, i;

public:

	CayleyDickson();
	CayleyDickson(T real, T imag);


	// Get elements
	T real();
	T imag();
};



CayleyDickson::CayleyDickson(){

}



