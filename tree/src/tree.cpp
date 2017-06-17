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
		if(tmp)//����������
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
		if(tmp->left != NULL)		//ע�����ҽڵ㲻����ʱ�����
			EnQueue(q, tmp->left);
		if(tmp->right != NULL)
			EnQueue(q, tmp->right);
	}
}

#define MAX(A,B) ((A) > (B) ? (A) : (B))
int get_hight(BitNode *T)
{
	if (T == NULL)
		return 0;
	return 1 + MAX(get_hight(T->left), get_hight(T->right));
}

//��������������,���ظ��ڵ�
BitNode* BST_insert(BitNode *T, elemType x)
{
	if (T == NULL)
	{
		T = (BitNode*)malloc(sizeof(struct BitNode));
		if (T == NULL)
			return NULL;
		T->elem = x;
		T->left = T->right = NULL;
	}
	else if (x < T->elem)
	{
		T->left = BST_insert(T->left, x);
	}
	else if (x > T->elem)
	{
		T->right = BST_insert(T->right, x);
	}
	return T;
}

BitNode* BST_delete(BitNode *T, elemType x)
{
	BitNode *p = T, *tmp = NULL, *fp = T; 
	while (p != NULL)
	{
		if (x == p->elem)
			break;
		fp = p;
		p = x > p->elem ? p->right : p->left;
	}
	if (p == NULL)	//not find
	{
		printf("not found");
		return NULL;
	}
	else if (!p->left && !p->right)//Ҷ�ӽڵ�
	{
		if (fp->left == p)
			fp->left = NULL;
		if (fp->right == p)
			fp->right = NULL;
		free(p);
	}
	else if (!p->left && p->right)//û���������Ľڵ�
	{
		p = p->right;
		free(p);
	}
	else if (p->left && !p->right)//û���������Ľڵ�
	{
		p = p->left;
	}
	else if (p->left && !p->right)//����������
	{
		tmp = BST_findMin(p->right);
		p->elem = tmp->elem;
		BST_delete(p->right, tmp->elem);
	}
	return T;
}

BitNode* BST_find(BitNode *T, elemType x)
{
	if (T == NULL)
		return NULL;
	if (T->elem == x)
		return T;
	if (x < T->elem)
		return BST_find(T->left, x);
	if (x > T->elem)
		return BST_find(T->right, x);
}

BitNode* BST_find2(BitNode *T, elemType x)
{
	while (T != NULL)
	{
		if (x == T->elem)
			break;
		T = x > T->elem ? T->right : T->left;
	}
	return T;
}

//������Сֵ�Ľڵ�ָ��
BitNode* BST_findMin(BitNode *T)
{
	if (T == NULL)
		return NULL;
	while (T->left != NULL)
		T = T->left;
	return T;
}

////����ʽ��������'#'��ʾ����
//BitNode* CreateTree(BitNode *&T) {  // �㷨6.4
//  // �������������������н���ֵ��һ���ַ������ո��ַ���ʾ������
//  // ������������ʾ�Ķ�����T��
//  char ch;
//  scanf("%c",&ch);
//  if (ch=='#') T = NULL;
//  else {
//    if (!(T = (BitNode *)malloc(sizeof(BitNode)))) return ERROR;
//    T->elem = ch;              // ���ɸ����
//	CreateTree(T->left);   // ����������
//	CreateTree(T->right);   // ����������
//  }
//  return T;
//} 
