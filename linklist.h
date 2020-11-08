#ifndef _INC_LINKLIST
#define _INC_LINKLIST

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1

typedef int ElemType_Lk;
typedef int status;

typedef struct LNode{
	ElemType_Lk data;
	struct LNode* next;
}LNode,*LinkList;//�ṹ�塢�ṹ��ָ������



status GetElem_Lk(LinkList L, int i, ElemType_Lk& e);
status ListInsert_Lk(LinkList& L, int i, ElemType_Lk& e);
status ListDelet_Lk(LinkList& L, int i, ElemType_Lk& e);//��L��ɾ����i��Ԫ�أ�����ɾ����Ԫ�ؼ���e�С�
status CreateList_LkHead(LinkList& L, int n);//ͷ�巨
status CreateList_LkEnd(LinkList& L, int n);//β�Ͳ巨
status DisplList_Lk(LinkList& L);
status DestoryList_Lk(LinkList& L);
status InitList_Lk(LinkList& L);//��ʼ������(����һ��ͷ���)
bool ListEmpty_Lk(LinkList& L);
int ListLength_Lk(LinkList& L);
int LocateElem_Lk(LinkList& L, ElemType_Lk e);//����Ԫ�أ�û�ҵ��ͷ���0


#endif
