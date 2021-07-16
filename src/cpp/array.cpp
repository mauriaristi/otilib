
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>

#include"error_codes.hpp"
using namespace std;
// ----------------------------------------------------------------------------------------------------
// --------------------------------------       TYPEDEFS         --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef double     coeff_t; ///< Coefficient type.
typedef uint64_t   imdir_t; ///< Imaginary direction type.
typedef uint64_t    ndir_t; ///< Number of Imaginary directions type.
typedef uint16_t   bases_t; ///< Imaginary bases type. 
typedef uint8_t      ord_t; ///< Order type.
typedef uint8_t      ndh_t; ///< Number of direction helpers type.
typedef uint8_t     flag_t; ///< Flag type.

#define OWN_MEM 1

// ----------------------------------------------------------------------------------------------------
// --------------------------------------     END TYPEDEFS       --------------------------------------
// ----------------------------------------------------------------------------------------------------



template<class class_t>
inline void allocate(class_t*& ptr, uint64_t numEls){

    class_t* p_tmp = NULL;

    p_tmp = (class_t*)malloc(numEls*sizeof(class_t));

    if (p_tmp == NULL){
        // could not allocate data.
        cerr << "Error: Not enough memory." << printError(OTI_OutOfMemory);
        exit(OTI_OutOfMemory);
    } else {
        // Successfully allocated data.
        ptr = p_tmp;
    }
}






// ----------------------------------------------------------------------------------------------------
// --------------------------------------     CLASSES       -------------------------------------------
// ----------------------------------------------------------------------------------------------------
template<class scalar_t>
class array2d{
private:
    
    scalar_t* data; ///< Pointer to the data.
    uint64_t nrows; ///< Number of rows in the array.
    uint64_t ncols; ///< Number of columns in the array.
    flag_t   flags; ///< Flags (8 bit):
                    //   bit 1: memory owned -> (high) memory not owned -> (low) 
                    //   bit 2: 


public:
    
    /**************************************************************************************************
    @brief Constructor of the Array2D class.
    **************************************************************************************************/ 
    array2d();
    // ------------------------------------------------------------------------------------------------

    /**************************************************************************************************
    @brief Constructor of the Array2D class given the size dimensions of the array.

    @param[in] numRows: Number of rows.
    @param[in] numCols: Number of columns.
    **************************************************************************************************/ 
    array2d(uint64_t numRows, uint64_t numCols);
    // ------------------------------------------------------------------------------------------------

    /**************************************************************************************************
    @brief Destructor of the Array2D class 
    **************************************************************************************************/ 
    ~array2d();
    // ------------------------------------------------------------------------------------------------

    /**************************************************************************************************
    @brief Function that computes the size of the array. Returns the total number of element in the 
    array.
    **************************************************************************************************/
    uint64_t size();
    // ------------------------------------------------------------------------------------------------

    void print(){
        cout << "Pointer: " << this->data << endl;
        cout << "nrows: "   << this->nrows << endl;
        cout << "ncols: "   << this->ncols << endl;
    }


    /**************************************************************************************************
    @brief Overload to the assignment ("=") operator. Set all elements in the matrix all to the same 
    value.

    @tparam value: Value to set all parameters.
    **************************************************************************************************/
    array2d<scalar_t>& operator=(scalar_t value);
    array2d<scalar_t>& operator=(array2d<scalar_t>& value);
    // ------------------------------------------------------------------------------------------------


    /**************************************************************************************************
    @brief Overload to the self addition ("+=") operator. Add to a scalar value

    @param value: Value to set all parameters.
    **************************************************************************************************/
    array2d<scalar_t>& operator+=(scalar_t value);
    // ------------------------------------------------------------------------------------------------


    /**************************************************************************************************
    @brief Overload to the parenthesis ("()") operator. Get an item of the array.

    @param i: Row index.
    @param j: Column index.
    **************************************************************************************************/
    scalar_t& operator()(uint64_t i,uint64_t j );
    // ------------------------------------------------------------------------------------------------

    void pointer(){
        cout << this->data << endl;
    }









    //%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%
    //                                       FRIEND FUNCTIONS                                           
    //%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%

    /**************************************************************************************************
    @brief Overload to the output stream ("<<") operator. Prints the elements in the matrix.

    @param os: Output stream.
    @tparam val: 2D Array.
    **************************************************************************************************/
    template<class U>
    friend ostream& operator<<( ostream& os, const array2d<U>& val );
    // ------------------------------------------------------------------------------------------------

    /**************************************************************************************************
    @brief Overload to the addition ("+") operator. Adds two matrices of the same type.

    @tparam lhs: Left hand side 2D array.
    @tparam rhs: Right hand side 2D array.
    **************************************************************************************************/
    template<class U>
    friend array2d<U> operator+( const array2d<U>& lhs, const array2d<U>& rhs );
    template<class U>
    friend array2d<U> operator+( const array2d<U>& lhs, const U& rhs );
    template<class U>
    friend array2d<U> operator+( const U& lhs, const array2d<U>& rhs );
    // ------------------------------------------------------------------------------------------------

    /**************************************************************************************************
    @brief Overload to the subtraction ("-") operator. Subtracts two matrices of the same type.

    @tparam lhs: Left hand side 2D array.
    @tparam rhs: Right hand side 2D array.
    **************************************************************************************************/
    template<class U>
    friend array2d<U> operator-( const array2d<U>& lhs, const array2d<U>& rhs );
    template<class U>
    friend array2d<U> operator-( const array2d<U>& lhs, const U& rhs );
    template<class U>
    friend array2d<U> operator-( const U& lhs, const array2d<U>& rhs );
    // ------------------------------------------------------------------------------------------------

    /**************************************************************************************************
    @brief Overload to the multiplication ("*") operator. Elementwise multiplication between
    two arrays of the same type.

    @tparam lhs: Left hand side 2D array.
    @tparam rhs: Right hand side 2D array.
    **************************************************************************************************/
    template<class U>
    friend array2d<U> operator*( const array2d<U>& lhs, const array2d<U>& rhs );
    template<class U>
    friend array2d<U> operator*( const array2d<U>& lhs, const U& rhs );
    template<class U>
    friend array2d<U> operator*( const U& lhs, const array2d<U>& rhs );
    // ------------------------------------------------------------------------------------------------

    /**************************************************************************************************
    @brief Overload to the division ("/") operator. Elementwise division between two arrays of the 
    same type.

    @tparam lhs: Left hand side 2D array.
    @tparam rhs: Right hand side 2D array.
    **************************************************************************************************/
    template<class U>
    friend array2d<U> operator/( const array2d<U>& lhs, const array2d<U>& rhs );
    template<class U>
    friend array2d<U> operator/( const array2d<U>& lhs, const U& rhs );
    template<class U>
    friend array2d<U> operator/( const U& lhs, const array2d<U>& rhs );
    // ------------------------------------------------------------------------------------------------
    
    /**************************************************************************************************
    @brief Function to transpose a 2D array.

    @tparam array: 2D array.
    **************************************************************************************************/
    template<class U>
    friend array2d<U> transpose(array2d<U>& array);
    // ------------------------------------------------------------------------------------------------

    /**************************************************************************************************
    @brief Inner product between two 2D arrays.

    @tparam lhs: Left hand side 2D array.
    @tparam rhs: Right hand side 2D array.
    **************************************************************************************************/
    template<class U>
    friend array2d<U> dot(const array2d<U>& lhs, const array2d<U>& rhs);
    // ------------------------------------------------------------------------------------------------

    /**************************************************************************************************
    @brief Creates a matrix full of zeroes.

    @param nrows: Number of rows.
    @param ncols: Number of columns.
    **************************************************************************************************/
    static array2d<scalar_t> zeros(uint64_t nrows, uint64_t ncols);
    // ------------------------------------------------------------------------------------------------
    
    /**************************************************************************************************
    @brief Creates a matrix full of ones.

    @param nrows: Number of rows.
    @param ncols: Number of columns.
    **************************************************************************************************/
    static array2d<scalar_t>& ones(uint64_t nrows, uint64_t ncols);
    // ------------------------------------------------------------------------------------------------
    
    /**************************************************************************************************
    @brief Creates an identity matrix.

    @param nrows: Number of rows.
    **************************************************************************************************/
    static array2d<scalar_t> eye(uint64_t nrows);
    // ------------------------------------------------------------------------------------------------

    //%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%
    //                                     END FRIEND FUNCTIONS                                         
    //%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%--%


    // ------------------------------
    // Matrix operations:
    // ------------------------------
    // Inverse.

    // operator+=();
    // operator-=();
    // operator*=();
    // operator/=();

};
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// --------------------------------------     END CLASSES       ---------------------------------------
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
template<class T> array2d<T>::array2d(): data(NULL), nrows(0), ncols(0), flags(0) {
    cout << "Calling empty constructor\n";
}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T> array2d<T>::array2d(uint64_t numRows, uint64_t numCols){
    
    cout << "Calling sized constructor\n";
    this->nrows = numRows;
    this->ncols = numCols;

    // Allocate memory.
    this->data= new T[this->ncols*this->nrows];
    this->flags = OWN_MEM;

}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T> array2d<T>::~array2d(){
    
    cout << "Freeing item" << this->data << endl;

    if ( this->flags  == OWN_MEM ){
        
        delete[] this->data;
        this->data = NULL;
        this->flags = 0;
    }
    
    this->nrows = 0;
    this->ncols = 0;

}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T> inline uint64_t array2d<T>::size(){
    return this->ncols*this->nrows;
}
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
template<class T> T& array2d<T>::operator()(uint64_t i, uint64_t j){
    
    if (i >= this->nrows || j >= this->ncols){

        cerr << "Error: Index out of bounds. " << 
                printError(OTI_BadIndx)<< endl;
        exit(OTI_BadIndx);

    } 

    return this->data[i*this->ncols+j];
}
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
template<class T> array2d<T>& array2d<T>::operator=(T value){
    
    uint64_t i,j,k;

    cout << "Assigning "<< value << "to another array\n";

    if (this->size()>0){

        for (i=0; i<this->nrows; i++){
            
            for (j=0; j<this->ncols; j++){
                
                k = i*this->ncols + j;
                this->data[k] = value;
                
            } 

        }

    } else {
        cerr << "Error trying to set elements to an uninitialized array."<< 
                printError(OTI_NotInitialized) << endl;
        exit(OTI_NotInitialized);
    }

    return *this;
}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T> array2d<T>& array2d<T>::operator=(array2d<T>& value){
    
    uint64_t i,j,k;

    if ( this->flags & OWN_MEM ){

        // If first allocated, remove previous data.
        delete[] this->data;

    } 

    this->data  = value.data;
    this->nrows = value.nrows;
    this->ncols = value.ncols;
    this->flags = this->flags || OWN_MEM; // Apply own memory to new element. 
    
    value.flags = 0;

    // copy_n( value.data, this->size(), this->data);

    return (*this);
}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T> ostream& operator<<( ostream& os, const array2d<T>& val ){
    
    uint64_t i,j,k;
    
    os << "array2d\n";

    for (i=0; i<val.nrows; i++){
            
        for (j=0; j<val.ncols; j++){
            
            k = i*val.ncols + j;
            os << k << " " ;
            os << val.data[k] << ",";
            
        } 
        os << "\b\b" << endl;

    }

    return os;

}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T>
array2d<T> transpose(array2d<T>& array){
    
    array2d<T> res(array.ncols,array.nrows);
    uint64_t i,j,k1,k2;

    for (i=0; i<array.nrows; i++){
            
        for (j=0; j<array.ncols; j++){
            
            k1 = i*array.ncols + j;
            k2 = j*array.nrows + i;
            res.data[k2]=array.data[k1];
               
        }

    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T> array2d<T> operator+(const array2d<T>& lhs, const array2d<T>& rhs){

    array2d<T> res(lhs.nrows,rhs.ncols);

    // Elementwise operation
    if ( lhs.nrows == rhs.nrows && lhs.ncols == rhs.ncols){

        for(uint64_t i = 0; i< lhs.nrows*rhs.ncols; i++){
            res.data[i] = lhs.data[i] + rhs.data[i];
        }

    } else {
        cerr << "Error: Array addition dimension mismatch."<<
                printError(OTI_BadDimensions) << endl;
        exit(OTI_BadDimensions);
    }

    return res;
}
template<class T> array2d<T> operator+(const array2d<T>& lhs, const T& rhs){

    array2d<T> res(lhs.nrows,lhs.ncols);

    for(uint64_t i = 0; i< lhs.nrows*lhs.ncols; i++){
        res.data[i] = lhs.data[i] + rhs;
    }

    return res;
}
template<class T> array2d<T> operator+(const T& lhs, const array2d<T>& rhs){

    array2d<T> res(rhs.nrows,rhs.ncols);

    for(uint64_t i = 0; i< rhs.nrows*rhs.ncols; i++){
        res.data[i] = lhs + rhs.data[i];
    }

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T> 
array2d<T> operator*(const array2d<T>& lhs, const array2d<T>& rhs){

    array2d<T> res(lhs.nrows,rhs.ncols);

    // Elementwise operation
    if ( lhs.nrows == rhs.nrows && lhs.ncols == rhs.ncols){

        for(uint64_t i = 0; i< lhs.nrows*rhs.ncols; i++){
            res.data[i] = lhs.data[i] * rhs.data[i];
        }

    } else {
        cerr << "Error: Array elementwise multiplication dimension mismatch."<<
                printError(OTI_BadDimensions) << endl;
        exit(OTI_BadDimensions);
    }

    return res;
}
template<class T> 
array2d<T> operator*(const array2d<T>& lhs, const T& rhs){

    array2d<T> res(lhs.nrows,lhs.ncols);

    for(uint64_t i = 0; i< lhs.nrows*lhs.ncols; i++){
        res.data[i] = lhs.data[i] * rhs;
    }

    return res;
}
template<class T> 
array2d<T> operator*(const T& lhs, const array2d<T>& rhs){

    array2d<T> res(rhs.nrows,rhs.ncols);

    for(uint64_t i = 0; i< rhs.nrows*rhs.ncols; i++){

        res.data[i] = lhs * rhs.data[i];

    }

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T> 
array2d<T> operator-(const array2d<T>& lhs, const array2d<T>& rhs){

    array2d<T> res(lhs.nrows,rhs.ncols);

    // Elementwise operation
    if ( lhs.nrows == rhs.nrows && lhs.ncols == rhs.ncols){

        for(uint64_t i = 0; i< lhs.nrows*rhs.ncols; i++){
            res.data[i] = lhs.data[i] - rhs.data[i];
        }

    } else {
        cerr << "Error: Array elementwise multiplication dimension mismatch."<<
                printError(OTI_BadDimensions) << endl;
        exit(OTI_BadDimensions);
    }

    return res;
}
template<class T> 
array2d<T> operator-(const T& lhs, const array2d<T>& rhs){

    array2d<T> res(rhs.nrows,rhs.ncols);

    for(uint64_t i = 0; i< rhs.nrows*rhs.ncols; i++){
        res.data[i] = lhs - rhs.data[i];
    }

    return res;
}
template<class T> 
array2d<T> operator-(const array2d<T>& lhs, const T& rhs){

    array2d<T> res(lhs.nrows,lhs.ncols);

    for(uint64_t i = 0; i< lhs.nrows*lhs.ncols; i++){
        res.data[i] = lhs.data[i] - rhs;
    }

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T> 
array2d<T> operator/(const array2d<T>& lhs, const array2d<T>& rhs){

    array2d<T> res(lhs.nrows,rhs.ncols);

    // Elementwise operation
    if ( lhs.nrows == rhs.nrows && lhs.ncols == rhs.ncols){

        for(uint64_t i = 0; i< lhs.nrows*rhs.ncols; i++){
            res.data[i] = lhs.data[i] / rhs.data[i];
        }

    } else {
        cerr << "Error: Array elementwise multiplication dimension mismatch."<<
                printError(OTI_BadDimensions) << endl;
        exit(OTI_BadDimensions);
    }

    return res;
}
template<class T> array2d<T> operator/(const T& lhs, const array2d<T>& rhs){

    array2d<T> res(rhs.nrows,rhs.ncols);

    for(uint64_t i = 0; i< rhs.nrows*rhs.ncols; i++){
        res.data[i] = lhs / rhs.data[i];
    }

    return res;
}
template<class T> array2d<T> operator/(const array2d<T>& lhs, const T& rhs){

    array2d<T> res(lhs.nrows,lhs.ncols);

    for(uint64_t i = 0; i< lhs.nrows*lhs.ncols; i++){
        res.data[i] = lhs.data[i] / rhs;
    }

    return res;
}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T> array2d<T> dot(const array2d<T>& lhs, const array2d<T>& rhs){

    array2d<T> res(lhs.nrows,rhs.ncols);

    uint64_t i,j,k,l1,l2,l3;

    if (lhs.ncols == rhs.nrows){

        for (i=0; i<lhs.nrows; i++){
            
            for (j=0; j<rhs.ncols; j++){
                
                l1 = i*res.ncols + j;
                
                res.data[l1] = 0.0;

                for (k=0; k<lhs.ncols; k++ ){

                    l2 = i*lhs.ncols + k;
                    l3 = k*rhs.ncols + j;
                    res.data[l1] += lhs.data[l2] * rhs.data[l3];

                }

            }

        }

    } else {
        cerr << "Error: Array inner product wrong dimensions "<<
                printError(OTI_BadDimensions) << endl;
        exit(OTI_BadDimensions);
    }

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
template<class T> 
array2d<T>& array2d<T>::ones(uint64_t nrows, uint64_t ncols){

    array2d<T> res(nrows,ncols);

    uint64_t i;

    for (i=0; i<nrows*ncols; i++){
        cout << i;
        res.data[i] = 1.;
        //cout << " " << res.data[i] << endl;
    }   

    res.pointer();
    
    return &res;

}
// ----------------------------------------------------------------------------------------------------


// Create ZEROS, ONES, and EYE.

//



int main(){

    // array2d<complex<double>> a(3,3);
    // array2d<complex<double>> b(3,5);

    array2d<double> a(3,3);
    array2d<double> b(3,3);

    array2d<double> c;

    a = 0.5;
    a(1,1) = 16.5;
    b = 3.5;

    c.print();
    c = array2d<double>::ones(3,3);
    // c.print();
    // // c.pointer();

    // cout << c << endl;
    cout << a << endl;
    cout << b << endl;
    

    // cout << transpose(b) << endl;

    // cout << dot(a,b) << endl;

    // cout << 10. / a - b/15. << endl;

    // Set a value of the array.

    return 0;
}