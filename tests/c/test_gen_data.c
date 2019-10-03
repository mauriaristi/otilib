#include<oti/core.h>

int main(int argc, char *argv[]){

    // Declarations
    bases_t nbases[] = {
            10, // 1
            10, // 2
            10, // 3
            10, // 4
            10, // 5
            10, // 6
            10, // 7
            10, // 8
            10, // 9
            10, // 10
             5, // 11
             5, // 12
             5, // 13
             5, // 14
             5, // 15
             5, // 16
             5, // 17
             5, // 18
             5, // 19
             5  // 20
    };// Up to order 20
    
    ord_t maxorder = 20;

    dhelp_precompute("", nbases, maxorder);
    
    printf("__________________________________________________\n");
    printf("Finished precomputation of data.\n");
    printf("Exiting now...\n");

    return 0;
}