#include "Queue.h"

void QueueInit(Queue* qu){
	qu->front = qu->tail = qu->data;//?
	qu->size = 0;
}
void QueueDestory(Queue* qu){
	qu->front = qu->tail = qu->data;
	qu->size = 0;
}

void QueuePush(Queue* qu, QueDatatype x){
	if (qu->size + 1 == QueueMAX){
		return;
	}

	else{
		*qu->tail = x;
		qu->tail++;
		qu->size++;
	}
	if (qu->front - qu->data == QueueMAX){
		qu->front = qu->data;
	}
}
void QueuePop(Queue* qu){
	if (qu->size == 0){
	
		return;
	}
	qu->front++;
	qu->size--;
	if (qu->front - qu->data == QueueMAX){
		qu->front = qu->data;//?
	}
}

QueDatatype QueueFront(Queue* qu){
	if (qu->size == 0){
		return (QueDatatype)-1;
	}
	return *qu->front;
}
QueDatatype QueueBack(Queue* qu){
	if (qu->size == 0)

	{

		return (QueDatatype)0;

	}

	if (qu->tail == qu->data)//?

	{

		return qu->data[QueueMAX - 1];

	}

	return *(qu->tail - 1);
}