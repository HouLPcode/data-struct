#ifndef _STACK_H_
#define _STACK_H_

#include "tree.h"

#define STACK_INIT_SIZE	100//存储空间初始分配量
#define STACKINCREMENT	10//栈满时的存储空间分配增量
//typedef BitNode* StackElemType;
#define StackElemType BitNode*

typedef struct{
	StackElemType* base;	//栈底
	StackElemType* top;	//栈顶
	//int stacksize;//可用存储空间
}SqStack;

int InitStack(SqStack &s);
StackElemType push(SqStack &s,StackElemType x);
StackElemType pop(SqStack &s,StackElemType &x);
StackElemType get_top(SqStack s);
bool isEmpty_stack(SqStack s);

#endif