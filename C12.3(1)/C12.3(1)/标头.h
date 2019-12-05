#ifndef _SEQLIST_H_
#define _SEQLIST_H_

// Ë³Ðò±íµÄ¶¯Ì¬´æ´¢


#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef int SDataType;

typedef struct SeqList{
	SDataType* arry;
	size_t size;
	size_t capacity;
}SeqList;

void  SeqListInit(SeqList* sp,size_t capacity);
void  SeqListDestory(SeqList* sp);

void CheckCapacity(SeqList* sp);

void  SeqListPushBack(SeqList* sp, SDataType x);
void  SeqListPopBack(SeqList* sp);

void  SeqListPushFront(SeqList* sp, SDataType x);
void  SeqListPopFront(SeqList* sp, SDataType x);

int  SeqListFind(SeqList* sp, SDataType x);

void  SeqListInsert(SeqList* sp,size_t pos ,SDataType x);
void  SeqListErase(SeqList* sp, size_t pos);

void SeqListModify(SeqList* psl, size_t pos, SDataType x);

void  SeqListRemove(SeqList* sp, SDataType x);
void  SeqListPrint(SeqList* sp);

void  SeqListRemoveAll(SeqList* sp, SDataType x);
void SeqListBubbleSort(SeqList* psl);

int SeqListBinaryFind(SeqList* psl, SDataType x);

#endif/*_SEQLIST_H_*/