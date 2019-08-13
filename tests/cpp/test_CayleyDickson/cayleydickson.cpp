// Basic implementation of dual numbers


#include<fstream>
#include<iostream>
#include<cmath>
#include<complex>

using namespace std;

template<class T>
class CayleyDickson{

public:

	T r, i;
	CayleyDickson();
	CayleyDickson(T real, T imag);


	// Get elements
	T& real();
	T& imag();

	CayleyDickson<T>& operator=(const T& num);
	CayleyDickson<T>& operator=(const double& num);
	T& operator[](const int index);

	template<class U>
	friend ostream& operator<<(ostream& os, const CayleyDickson<U>& num);
	template<class U>
	friend CayleyDickson<U> operator*(const CayleyDickson<U>& lhs,const  CayleyDickson<U>& rhs);
	template<class U>
	friend CayleyDickson<U> operator+(const CayleyDickson<U>& lhs,const  CayleyDickson<U>& rhs);
	template<class U>
	friend CayleyDickson<U> operator-(const CayleyDickson<U>& lhs,const  CayleyDickson<U>& rhs);
};


template<class T>
CayleyDickson<T>::CayleyDickson(){
	r = 0;
	i = 0;
}

template<class T>
CayleyDickson<T>::CayleyDickson(T real, T imag){
	r = real;
	i = imag;
}


template<class T>
CayleyDickson<T>& CayleyDickson<T>::operator=(const T& num){
	r = num;
	i = 0;
	return *this;
}

template<class T>
CayleyDickson<T>& CayleyDickson<T>::operator=(const double& num){
	r = num;
	i = 0;
	return *this;
}


// Extract real part.
template<class T>
T& CayleyDickson<T>::real(){
	return r;
}

// Extract imaginary part.
template<class T>
T& CayleyDickson<T>::imag(){
	return i;
}

// Extract real part.
template<class T>
ostream& operator<<(ostream& os, const CayleyDickson<T>& num){

	os << "(" << num.r;
	os << "," << num.i <<")";
	return os;
}

// Conjugate operation of Cayley Dickson numbers.
template<class T>
CayleyDickson<T> conj(CayleyDickson<T>& num){
	return CayleyDickson<T>::CayleyDickson( conj(num.r), -num.i );
}


template<class T>
CayleyDickson<T> operator-(const CayleyDickson<T>& lhs,const  CayleyDickson<T>& rhs){
	
	CayleyDickson<T> res;
	res.r = lhs.r-rhs.r;
	res.i = lhs.i-rhs.i;
	return res;
}

template<class T>
CayleyDickson<T> operator+(const CayleyDickson<T>& lhs,const  CayleyDickson<T>& rhs){
	
	CayleyDickson<T> res;

	res.r = lhs.r+rhs.r;
	res.i = lhs.i+rhs.i;
	return res;
}

template<class T>
CayleyDickson<T> operator*(const CayleyDickson<T>& lhs,const  CayleyDickson<T>& rhs){
	
	CayleyDickson<T> res;

	res.r = lhs.r*rhs.r - conj(rhs.i)*lhs.i;
	res.i = rhs.i*lhs.r + lhs.i*conj(rhs.r);
	return res;
}



typedef CayleyDickson< complex<double> > quaternion;
typedef CayleyDickson< quaternion      > octonion; 
typedef CayleyDickson< octonion        > sedenion; 


// test
int main(){
	
	quaternion q;
	octonion   o;
	sedenion   s;
	
	s = 3.5;
	q = 3.8;

	o.imag() = q;

	cout<<"Quaternion: " << q <<  endl;
	cout<<"Octonion: "   << o <<  endl;
	// cout<<"Sedenion: "   << s <<  endl;

	return 0;
}



