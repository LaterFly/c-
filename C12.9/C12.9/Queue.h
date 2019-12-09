
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>

typedef int QueDatatype;
#define QueueMAX 5
typedef struct queue{
	QueDatatype  data[QueueMAX];
	QueDatatype *front;
	QueDatatype *tail;
	size_t size;
}Queue;

void QueueInit(Queue* qu);
void QueueDestory(Queue* qu);

void QueuePush(Queue* qu,QueDatatype x);
void QueuePop(Queue* qu);

QueDatatype QueueFront(Queue* qu);
QueDatatype QueueBack(Queue* qu);

#endif /*_QUEUE_H_*/