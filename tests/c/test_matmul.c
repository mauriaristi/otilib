
// Example taken from http://blog.speedgocomputing.com/2010/08/parallelizing-matrix-multiplication.html

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

const int size = 10000;

float a[size][size];
float b[size][size];
float c[size][size];

int main()
{   
    int i,j,k;
    // Initialize buffers.
    for ( i = 0; i < size; ++i) {
        for ( j = 0; j < size; ++j) {
            a[i][j] = (float)i + j;
            b[i][j] = (float)i - j;
            c[i][j] = 0.0f;
        }
    }

    // Compute matrix multiplication.
    // C <- C + A x B
    for ( i = 0; i < size; ++i) {
        for ( j = 0; j < size; ++j) {
            for ( k = 0; k < size; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return 0;
}