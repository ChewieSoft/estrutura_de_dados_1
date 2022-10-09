#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adt_sample.h"


StackPtr_t Stack = NULL;
//Stack = (StackStruct_t*) malloc(2 * sizeof(StackPtr_t));

Stack_Init(Stack);
Stack_Push(Stack, 0x15);

int main(int argc, char *argv[])
{
	
	printf("Gabiru Mundano!");	
	return EXIT_SUCCESS;
}
