/*
 * adt_sample.h
 *
 * Created on: Oct 9, 2022
 *		Author: Brenno, Jorge e Hamilton
 *
 */
 
 #ifndef ADT_SAMPLE_
 #define ADT_SAMPLE_ 
 
  /*
  *  Put here your default needed C definitions
  */
 #include <stdbool.h>
 
  /*
  *  Defines the maximum size of the stack
  */
 
 #define STACK_SIZE 50
 
   /*
  *  Defines the pointer to the ADT
  */ 

typedef struct StackStruct_t * StackPtr_t;

bool Stack_Init(StackPtr_t Stack);
bool Stack_Push(StackPtr_t Stack, int Item);
bool Stack_Pop(StackPtr_t Stack, int * Item);

#endif /* ADT_SAMPLE_ */
