#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include "adt_sample.h"

//typedef struct StackStruct_t * StackPtr_t;


StackPtr_t Stack;
Stack = (StackPtr_t) malloc(50 * sizeof(StackStruct_t));



int main(int argc, char *argv[])
{
	printf("Gabiru Mundano!");	
	//Stack_Init(Stack);
	//Stack_Push(Stack, 0x15);
	return EXIT_SUCCESS;
}
