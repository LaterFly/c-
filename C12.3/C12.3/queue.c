#include "queue.h"

void QueueInit(Queue *ptr){
	ptr->front = ptr->rear = ptr->data;
	ptr->size = 0;
}
void QueueDestory(Queue *ptr){
	ptr->front = ptr->rear = ptr->data;
	ptr->size = 0; 
}

void QueuePush(Queue *ptr, DataType x){

	if (ptr->size+1==queMax){
		return;
	}
	*ptr->rear = x;
	ptr->rear++;
	ptr->size++;
	if (ptr->rear - ptr->data == queMax)//?

	{

		ptr->rear = ptr->data;

	}


}
void QueuePop(Queue *ptr){
	if (ptr->size==0){
		return 0;
	}
	ptr->front++;
	ptr->size--;
	if (ptr->rear - ptr->data == queMax)//?

	{

		ptr->rear = ptr->data;

	}

}

DataType QueueFront(Queue *ptr){
	if (ptr->size == 0){
		return (DataType)-1;
	}
	return *ptr->front;

}
DataType QueueBack(Queue *ptr){
	if (ptr->size == 0){
		return (DataType)0;
	}
	if (ptr->rear==ptr->data){
		return ptr->data[queMax- 1];
	}
	return *(ptr->rear-1);
}