#ifndef _STACK_H_
#define _STACK_H_

#include "tree.h"

#define STACK_INIT_SIZE	100//�洢�ռ��ʼ������
#define STACKINCREMENT	10//ջ��ʱ�Ĵ洢�ռ��������
//typedef BitNode* StackElemType;
#define StackElemType BitNode*

typedef struct{
	StackElemType* base;	//ջ��
	StackElemType* top;	//ջ��
	//int stacksize;//���ô洢�ռ�
}SqStack;

int InitStack(SqStack &s);
StackElemType push(SqStack &s,StackElemType x);
StackElemType pop(SqStack &s,StackElemType &x);
StackElemType get_top(SqStack s);
bool isEmpty_stack(SqStack s);

#endif