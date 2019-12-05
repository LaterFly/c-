#include "Slist.h"
#include<stdio.h>

void SlistInit(SlistNode** phead){
	*phead = NULL;

}
void SlistDestory(SlistNode** phead){
	if (*phead==NULL){
		return;
	}


}

SlistNode* BuySlistNode(SLDatatype x){
	SlistNode* ret = (SlistNode*)malloc(sizeof(SlistNode));
	ret->data = x;
	ret->next = NULL;
	return ret;
}

void SlistPushFront(SlistNode** phead, SLDatatype x){
	SlistNode* temp = BuySlistNode(x);
	temp->next= *phead;
	*phead = temp;
}

void SlistPopFront(SlistNode** phead){
	if (*phead == NULL){
		return;
	}
	SlistNode* temp = (*phead)->next;
	free(*phead);
	*phead = temp;
}

void SlistInsertAfter(SlistNode* pos, SLDatatype x){
	SlistNode* temp = BuySlistNode(x);
	temp->next = pos->next;
	pos->next = temp;
}

void SlistEraseAfter(SlistNode* pos){
	SlistNode* temp = pos->next;
	if (temp == NULL)

	{

		return;

	}
	pos->next = temp->next;
	free(temp);
}

SlistNode* SlistFind(SlistNode* phead, SLDatatype x){
	SlistNode* temp;
	for (temp=phead; temp;temp=temp->next){
		if (temp->data == x){
			return temp;
		}
	}
	return NULL;

}
void SlistRemove(SlistNode** phead, SLDatatype x){
	SlistNode* temp;
	if (temp == NULL)

	{
		return;
	}
	if ((*phead)->data == x){
		SlistPopFront(phead);
		return;
    }
	for (temp = *phead; temp->next;temp=temp->next){
		if (temp->next->data == x){
			SlistEraseAfter(temp);
			return;
		}
	}
}

void SlistPrint(SlistNode* phead){

}

void SlistReverse1(SlistNode** phead);
void SlistReverse2(SlistNode** phead);

void SListRemoveAll(SlistNode** pphead, SLDatatype x){


}