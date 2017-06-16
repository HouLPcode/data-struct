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

void main()
{
	BitNode *pTree = NULL;
	int i;
	int j[] = {8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};//树的层次遍历值

    for( i = 0; i < 15; i++)
	{
		printf("%d ",j[i]);
        pTree = Insert( j[i], pTree );
	}
	printf("\n\n");

	printf("tree hight is %d\n", get_hight(pTree));

	//printf("levelOrder: ");
	//levelOrder(pTree);
	//printf("\n\n");

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