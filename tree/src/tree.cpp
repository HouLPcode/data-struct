#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"
#include "queue.h"

void preOrder(BitNode *T)
{
	if(T != NULL)
	{
		printf("%d ",T->elem);
		preOrder(T->left);
		preOrder(T->right);
	}
}

void preOrder2(BitNode *T)
{
	SqStack s;
	InitStack(s);
	BitNode* tmp;

	if (T == NULL)
		return;
	push(s, T);
	while (!isEmpty_stack(s))
	{
		pop(s, tmp);
		printf("%d ", tmp->elem);
		if (tmp->right != NULL)
			push(s, tmp->right);
		if (tmp->left != NULL)
			push(s, tmp->left);
	}
}

void inOrder(BitNode *T)
{
	if(T != NULL)
	{
		inOrder(T->left);
		printf("%d ",T->elem);
		inOrder(T->right);
	}
}

void inOrder2(BitNode *T)
{
	SqStack s;
	InitStack(s);
	BitNode* tmp = T;
	
	while(tmp || !isEmpty_stack(s))
	{
		if(tmp)//树继续遍历
		{
			push(s,tmp);
			tmp = tmp->left;
		}
		else
		{
			pop(s,tmp);
			printf("%d ",tmp->elem);
			tmp = tmp->right;
		}
	}
}

void postOrder(BitNode *T)
{
	if(T != NULL)
	{
		postOrder(T->left);
		postOrder(T->right);
		printf("%d ",T->elem);
	}
}

void postOrder2(BitNode *T)
{
	
}

void levelOrder(BitNode *T)
{
	linkQueue q;
	init_queue(q);
	BitNode *tmp = T;
	EnQueue(q, tmp);
	while (!isEmpty_queue(q))
	{
		DeQueue(q, tmp);
		printf("%d ", tmp->elem);
		if(tmp->left != NULL)		//注意左右节点不存在时不入队
			EnQueue(q, tmp->left);
		if(tmp->right != NULL)
			EnQueue(q, tmp->right);
	}
}

//构建二叉排序树
BitNode* Insert(int x,BitNode *T)
{
	if(T == NULL)
	{
		T = (BitNode*)malloc(sizeof(struct BitNode));
		if(T == NULL)
			return NULL;
		T->elem = x;
		T->left = T->right = NULL;
	}
	else if(x < T->elem)
	{
		T->left = Insert(x,T->left);
	}
	else if(x > T->elem)
	{
		T->right = Insert(x,T->right);
	}
	return T;
}

#define MAX(A,B) ((A) > (B) ? (A) : (B))
int get_hight(BitNode *T)
{
	if (T == NULL)
		return 0;
	return 1 + MAX(get_hight(T->left), get_hight(T->right));
}

////先序方式创建树，'#'表示结束
//BitNode* CreateTree(BitNode *&T) {  // 算法6.4
//  // 按先序次序输入二叉树中结点的值（一个字符），空格字符表示空树，
//  // 构造二叉链表表示的二叉树T。
//  char ch;
//  scanf("%c",&ch);
//  if (ch=='#') T = NULL;
//  else {
//    if (!(T = (BitNode *)malloc(sizeof(BitNode)))) return ERROR;
//    T->elem = ch;              // 生成根结点
//	CreateTree(T->left);   // 构造左子树
//	CreateTree(T->right);   // 构造右子树
//  }
//  return T;
//} 
