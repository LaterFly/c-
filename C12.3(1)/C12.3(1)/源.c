#include"БъЭЗ.h"

void  SeqListInit(SeqList* sp, size_t capacity){
	sp->arry = (SDataType*)calloc(capacity,sizeof(SDataType));
	sp->capacity = capacity;
	sp->size = 0;
}
void  SeqListDestory(SeqList* sp){
	if (sp->arry){
		free(sp->arry);
		sp->arry = NULL;
		sp->capacity = 0;
		sp->size = 0;
	}

}

void CheckCapacity(SeqList* sp){
	if (sp->size>=sp->capacity){
		sp->capacity *= 2;
		sp->arry = (SDataType*)realloc(sp->capacity,sp->capacity*sizeof(SDataType));
	}

}

void  SeqListPushBack(SeqList* sp, SDataType x){
	CheckCapacity(sp);
	sp->arry[sp->size] = x;
	sp->size++;
}
void  SeqListPopBack(SeqList* sp){
	sp->size--;
}

void  SeqListPushFront(SeqList* sp, SDataType x){
	int i;
	CheckCapacity(sp);
	for (i = sp->size - 1; i >= 0;i--){
		sp->arry[i + 1] = sp->arry[i];
	}
	sp->arry[0] = x;
	sp->size++;
}

void  SeqListPopFront(SeqList* sp, SDataType x){

	int i;
	
	for (i=0; i <=sp->size-1; i++){
		sp->arry[i] = sp->arry[i+1];
	}
	sp->size--;
}

int  SeqListFind(SeqList* sp, SDataType x){
	int i;

	for (i = 0; i <= sp->size - 1; i++){
		if (sp->arry[i]==x){
			return i;
		}
	}
	return -1;
}

void  SeqListInsert(SeqList* sp, size_t pos, SDataType x){
	int i;
	CheckCapacity(sp);
	for (i = sp->size - 1; i >= pos; i--){
		sp->arry[i + 1] = sp->arry[i];
	}
	sp->arry[pos] = x;
	sp->size++;
}

void  SeqListErase(SeqList* sp, size_t pos){
	int i;
	for (i = pos; i <= sp->size - 1; i++){
		sp->arry[i] = sp->arry[i + 1];
	}
	sp->size--;

}

void SeqListModify(SeqList* psl, size_t pos, SDataType x);

void  SeqListRemove(SeqList* sp, SDataType x);

void  SeqListPrint(SeqList* sp){
	int i = 0;
	for (i = 0; i <= sp->size - 1; i++){
		printf("%d",sp->arry[i]);
	}
	putchar('\n');
}

void  SeqListRemoveAll(SeqList* sp, SDataType x);
void SeqListBubbleSort(SeqList* sp){
	int i, j;
	SDataType temp;
	for (i = 0; i <= sp->size - 1;i++){
		for (j = 0; j <= sp->size -1- i;j++){
			if (sp->arry[j] > sp->arry[j+1]){
				temp = sp->arry[j];
				sp->arry[j] = sp->arry[j + 1];
				sp->arry[j + 1] = temp;
			}
		}
	}
}

int SeqListBinaryFind(SeqList* psl, SDataType x);
