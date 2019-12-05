#ifndef _SLIST_H_
#define _SLIST_H_

typedef int SLDatatype;

typedef struct SlistNode{
	SLDatatype data;
	struct SlistNode* next;

}SlistNode;

void SlistInit(SlistNode** phead);
void SlistDestory(SlistNode** phead);

SlistNode* BuySlistNode(SLDatatype x);

void SlistPushFront(SlistNode** phead,SLDatatype x);
void SlistPopFront(SlistNode** phead, SLDatatype x);

void SlistInsertAfter(SlistNode* pos, SLDatatype x);
void SlistEraseAfter(SlistNode* pos);

SlistNode* SlistFind(SlistNode* phead, SLDatatype x);
void SlistRemove(SlistNode** phead, SLDatatype x);

void SlistPrint(SlistNode* phead);

void SlistReverse1(SlistNode** phead);
void SlistReverse2(SlistNode** phead);

void SListRemoveAll(SlistNode** pphead, SLDatatype x);


#endif/*_SLIST_H_*/