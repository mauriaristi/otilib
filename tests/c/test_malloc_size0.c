#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>


int main (){

	int *ptr = NULL;

	// before initialization
	printf("size of int: %zu\n",sizeof(int));

	printf("Pointer before initialization %p\n", ptr);

	ptr = (int*) malloc(28*sizeof(int));

	printf("Pointer after initialization %p\n", ptr);
	printf("Pointer usable size: %zu\n", malloc_usable_size(ptr));

	free(ptr);

	printf("Pointer after free %p\n", ptr);

	return 0;
}



