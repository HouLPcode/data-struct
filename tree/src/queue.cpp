#include "queue.h"

void init_queue(linkQueue &q)
{
	q.front = q.rear = (QNode*)malloc(sizeof(QNode));
	if(q.front == NULL)
		return;
	q.front->next = NULL;
}

//β��ͷ�� �ڵ�ָ��ͷ --> β
QUEUE_ELEM_TYPE EnQueue(linkQueue &q,QUEUE_ELEM_TYPE x)
{
	QNode *tmp = (QNode*)malloc(sizeof(QNode));
	if(tmp == NULL)
		return 0;
	tmp->data = x;
	tmp->next = NULL;
	q.rear->next = tmp;
	q.rear = tmp;
	return x;
}

QUEUE_ELEM_TYPE DeQueue(linkQueue &q,QUEUE_ELEM_TYPE &x)
{
	if(q.front == q.rear)//�ն���
		return 0;
	QNode *p = q.front->next;
	x = p->data;
	q.front->next = p->next;
	if (p == q.rear)//���ӵ��Ƕ�βԪ��
		q.rear = q.front;
	free(p);
	return x;
}

QUEUE_ELEM_TYPE get_head(linkQueue q)
{
	if(q.front == q.rear)
		return 0;
	return q.front->next->data;
}

bool isEmpty_queue(linkQueue q)
{
	return q.front == q.rear ? true : false;
}