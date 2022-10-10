/*
 * adt_sample.c
 *
 * Created on: Oct 9, 2022
 *		Author: Brenno, Jorge e Hamilton
 *
 */
 
 #include "adt_sample.h"
 
 struct StackStruct_t
 {
 	int Position_Current;
 	int Array[STACK_SIZE];
 };
 
 bool Stack_Init(StackPtr_t Stack)
 {
 	Stack->Position_Current=0;
 }
 
 bool Stack_Push(StackPtr_t Stack, int Item)
 {
 	bool ErrorState = false;
 	
 	if( Stack->Position_Current == STACK_SIZE )
 	{
 		ErrorState = true;
	}
	else
	{
		Stack-> Array[Stack->Position_Current] = Item;
		Stack->Position_Current++; 
	}
	return ErrorState;
 }
 
 bool Stack_Pop(StackPtr_t Stack, int * Item)
 {
 	bool ErrorState = false;
 	
 	if( Stack->Position_Current == 0 )
 	{
 		ErrorState = true;
	}
	else
	{		
		Stack->Position_Current--;
		*Item = Stack->Array[Stack->Position_Current];
	}
	return ErrorState;
 }
 
 
