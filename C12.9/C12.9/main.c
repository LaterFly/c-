#include "Queue.h"
int main(){
	Queue qu;

	QueueInit(&qu);

	QueuePush(&qu, 3);

	QueuePush(&qu, 5);

	QueuePush(&qu, 8);

	QueuePush(&qu, 7);

	printf("%d ", QueueFront(&qu));

	QueuePop(&qu);

	printf("%d ", QueueFront(&qu));

	QueuePop(&qu);

	QueuePush(&qu, 9);

	QueuePush(&qu, 10);

	printf("%d ", QueueFront(&qu));

	QueuePop(&qu);

	printf("%d ", QueueFront(&qu));

	QueuePop(&qu);


	return 0;
}