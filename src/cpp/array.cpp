




template<class T>
class array2d{
private:
    T* data;
    uint64_t ncols, nrows;
public:
    
    // Constructor:
    array2d();
    array2d();
    // Destructor:
    ~array2d();


    // ------------------------------
    // Elementwise Operations:
    // ------------------------------
    // Addition.
    // Subtraction.
    // Multiplication.
    // Division.

    // ------------------------------
    // Matrix operations:
    // ------------------------------
    // Inner product (dot).
    // Transpose.
    // Inverse.

    // ------------------------------
    // Friend functions.
    // ------------------------------

    friend transpose();
    friend invese();
    friend dot();

    operator=();
    operator+=();
    operator-=();
    operator*=();
    operator/=();

    friend operator+();
    friend operator-();
    friend operator*();
    friend operator/();   

    friend operator<<();





}


template<class T>
class array1d{
private:
    vector<T> data;
    uint64_t ncols, nrows;
public:
    
    // Initializer:
    array1d();

    // Deallocator
    ~array1d();



    // Operations:

    // Addition.

    // Subtraction.

    // Inner product (dot).

    // Elementwise multiplication.

    


}