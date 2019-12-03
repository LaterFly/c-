#include "queue.h"

int main(){
	Queue qe;
	QueueInit(&qe);

	QueuePush(&qe, 3);

	QueuePush(&qe, 5);

	QueuePush(&qe, 8);

	QueuePush(&qe, 7);

	printf("%d ",QueueFront(&qe));

	QueuePop(&qe);

	printf("%d ", QueueFront(&qe));

	QueuePop(&qe);

	QueuePush(&qe, 12);

	QueuePush(&qe, 13);

	printf("%d ", QueueFront(&qe));

return 0;
}