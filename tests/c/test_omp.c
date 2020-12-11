
// Example taken from http://blog.speedgocomputing.com/2010/08/parallelizing-matrix-multiplication.html

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{   
    
    
    #pragma omp parallel 
    {
        int id = omp_get_thread_num();
        printf("Hello(%d)!\n",id);    
    }

    return 0;
}