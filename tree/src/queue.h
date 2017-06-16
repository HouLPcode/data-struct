#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "tree.h"
#include <stdlib.h>

#define QUEUE_INIT_SIZE 100
#define QUEUE_ELEM_TYPE BitNode*

//µ•¡¥–Œ Ω
typedef struct QNode{
	QUEUE_ELEM_TYPE data;
	struct QNode * next;
}QNode;

typedef struct linkQueue{
	QNode *front;
	QNode *rear;
}linkQueue;

void init_queue(linkQueue &q);
QUEUE_ELEM_TYPE EnQueue(linkQueue &q,QUEUE_ELEM_TYPE x);
QUEUE_ELEM_TYPE DeQueue(linkQueue &q,QUEUE_ELEM_TYPE &x);
QUEUE_ELEM_TYPE get_head(linkQueue q);
bool isEmpty_queue(linkQueue q);

#endif