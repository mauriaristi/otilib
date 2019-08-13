
#include<string>


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