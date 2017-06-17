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
//����ɾ���ڵ�����ĸ��ڵ�
BitNode* BST_delete(BitNode *T, elemType x)
{
	BitNode *tmp; 
	if (T == NULL)	//not find
	{
		printf("not found the element");
		return NULL;
	}
	if (x < T->elem)
		 T->left = BST_delete(T->left, x); //�˴�һ��Ҫ�� T->left ָ�򷵻�ֵ����֤����������
	else if (x > T->elem)
		 T->right = BST_delete(T->right, x);
	else 	//��ǰ�ڵ����Ҫɾ���Ľڵ�
	{
		if (!T->left)//û������������Ҷ�ӽڵ�
		{
			tmp = T;
			T = T->right;
			free(tmp);
		}
		else if (!T->right)//û���������Ľڵ�
		{
			tmp = T;
			T = T->left;
			free(tmp);
		}
		else if (T->left && T->right)//����������
		{
			tmp = BST_findMin(T->right);
			T->elem = tmp->elem;
			T->right = BST_delete(T->right, tmp->elem);
		}
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
