#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"
#include "queue.h"

//void test_sqstack()
//{
//	SqStack s;
//	int x=0;
//
//	InitStack(s);
//	for(int i=0; i<10; i++)
//	{
//		push(s,i);
//		printf("%d ",get_top(s));
//	}
//		
//	for(int i=0; i<10; i++)
//	{
//		pop(s,x);
//		printf("%d ",x);
//	}
//}

//void test_queue()
//{
//	linkQueue q;
//	init_queue(q);
//	int tmp;
//
//	for(int i=0; i<10; i++)
//	{
//		EnQueue(q,i);
//		printf("%d ",i);
//	}
//	printf("\n");
//	while(!isEmpty_queue(q))
//	{
//		DeQueue(q,tmp);
//		printf("%d ",tmp);
//	}
//}

void test_BST()
{
	BitNode *pTree = NULL;
	int i;
	int j[] = { 8,4,12,2,6,10,14,1,3,5,7,9,11,13,15 };//树的层次遍历值

	for (i = 0; i < 15; i++)
	{
		printf("%d ", j[i]);
		pTree = BST_insert(pTree,j[i]);
	}
	printf("\n\n");
	printf("min is %d\n", BST_findMin(pTree)->elem);

	printf("levelOrder: \n");
	levelOrder(pTree);
	printf("\n");

	//删除叶子节点
	printf("delete node 3\n");
	BST_delete(pTree, 3);
	levelOrder(pTree);
	printf("\n");
	//删除不存在节点
	printf("delete node 3\n");
	BST_delete(pTree, 3);
	levelOrder(pTree);
	printf("\n");
	//删除无右子树节点
	printf("delete node 2\n");
	BST_delete(pTree, 2);
	levelOrder(pTree);
	printf("\n");
	//删除左右均有节点
	printf("delete node 12\n");
	BST_delete(pTree, 12);
	levelOrder(pTree);
	printf("\n");
	//删除无左子树节点
	printf("delete node 14\n");
	BST_delete(pTree, 14);
	levelOrder(pTree);
	printf("\n");

	printf("add node 7\n");
	BST_insert(pTree, 7);
	levelOrder(pTree);
	printf("\n");
	printf("add node 12\n");
	BST_insert(pTree, 12);
	levelOrder(pTree);
	printf("\n");

	printf("BST_find x *%p = %d \n",BST_find(pTree,10), BST_find(pTree, 10)->elem);
	printf("BST_find2 x *%p = %d \n", BST_find2(pTree, 10), BST_find2(pTree, 10)->elem);
}

void main()
{
	test_BST();
	//BitNode *pTree = NULL;
	//int i;
	//int j[] = { 8,4,12,2,6,10,14,1,3,5,7,9,11,13,15 };//树的层次遍历值

	//for (i = 0; i < 15; i++)
	//{
	//	printf("%d ", j[i]);
	//	pTree = BST_insert(pTree, j[i]);
	//}
	//printf("\n\n");

	//printf("tree hight is %d\n", get_hight(pTree));

	//printf("levelOrder: ");
	//levelOrder(pTree);
	//printf("\n\n");

	//printf("min is %d\n", BST_findMin(pTree)->elem);

	//printf("preOrder: ");
	//preOrder(pTree);
	//printf("\n\n");

	//printf("preOrder: ");
	//preOrder2(pTree);
	//printf("\n\n");

	//printf("inOrder: ");
	//inOrder(pTree);
	//printf("\n\n");

	//printf("inOrder2: ");
	//inOrder2(pTree);
	//printf("\n\n");
}