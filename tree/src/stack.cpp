#include "stack.h"
#include <stdlib.h>


int InitStack(SqStack &s)
{
	s.top = s.base = (StackElemType*)malloc(STACK_INIT_SIZE * sizeof(StackElemType));
	if(s.base == NULL)
		return -1;
	//s.stacksize = STACK_INIT_SIZE;
}

StackElemType push(SqStack &s,StackElemType x)
{
	if(s.top - s.base < STACK_INIT_SIZE)
		*s.top++ = x;
	return x;
}

StackElemType pop(SqStack &s,StackElemType &x)
{
	x = *--s.top;
	return x;	
}
StackElemType get_top(SqStack s)
{
	if(s.base == s.top)
		return NULL;//¿ÕÕ»
	return *(s.top-1);
}

bool isEmpty_stack(SqStack s)
{
	return s.top - s.base > 0 ? false : true;
}