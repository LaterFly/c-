#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#define queMax 6

typedef int DataType;

typedef struct Queue{
	DataType data[queMax];
	DataType *front;
	DataType *rear;
	size_t size;

}Queue;

void QueueInit(Queue *p);
void QueueDestory(Queue *p);

void QueuePush(Queue *p,DataType x);
void QueuePop(Queue *p);

DataType QueueFront(Queue *p);
DataType QueueBack(Queue *p);

#endif/* _QUEUE_H_*/