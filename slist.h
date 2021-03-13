#ifndef  __SLIST_H__
#define  __SLIST_H__

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#pragma warning(disable:4996)

// slist.h
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;



void SListInit(SListNode* plist);


// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);

// �������ӡ
void SListPrint(SListNode* plist);
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
// �����������

//void SListDestory(SList* plist);

void SListInit(SListNode**plist) {
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	p->data = NULL;
	(*plist) = p;
	(*plist)->next = NULL;
}
SListNode* BuySListNode(SLTDateType x) {
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	assert(p);
	p->data = x;
	p->next = NULL;
	return p;
}

void SListPrint(SListNode*plist)
{
	SListNode* p = plist;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->next;
	}
}
//������β��
void SListPushBack(SListNode** pplist, SLTDateType x) {
	SListNode* p = BuySListNode(x);
	SListNode* q = *pplist;
	if ((*pplist)->data == NULL) {
		(*pplist) = p;
	}	
	else{
	while (q->next != NULL)
		q = q->next;
	}
	q->next = p;

}


void SListPushFront(SListNode** pplist, SLTDateType x) {
	SListNode* p = BuySListNode(x);
	if ((*pplist)->data != NULL) {	
		p->next = *pplist;	
	}
	*pplist = p;
}


// �������βɾ
void SListPopBack(SListNode** pplist) {
	if ((*pplist) == NULL) {
		return;
	}
	if ((*pplist)->next == NULL) {
		(*pplist)= NULL;
	}
	else {
		SListNode* q = *pplist;
		SListNode* pre = q;
		while (q->next != NULL) {
			pre = q;
			q = q->next;
		}
		pre->next = NULL;
		free(q);
	}
}
// ������ͷɾ
void SListPopFront(SListNode** pplist) {
	if ((*pplist) == NULL) {
		return;
	}
	if ((*pplist)->next == NULL) {
		(*pplist) = NULL;
	}
	else {
		SListNode* p = *pplist;
		SListNode* q = (*pplist)->next;
		(*pplist) = q;
		free(p);	
	}
}


// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x) {
	assert(plist);
	SListNode* p = plist;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}



// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x) {
	assert(pos);
	SListNode* p = BuySListNode(x);
	SListNode* q = pos->next;
	pos->next = p;
	p->next = q;
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos) {
	assert(pos);
	SListNode* p = pos->next;
	pos->next = p->next;
	free(p);
}
// �����������

void SListDestory(SListNode** plist) {
	assert(plist);
	SListNode* q;
	while (*plist != NULL) {
		q = *plist;
		(*plist) = (*plist)->next;
		free(q);
	}
}



#endif