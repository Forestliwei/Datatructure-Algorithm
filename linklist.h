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
}LNode,*LinkList;//结构体、结构体指针类型



status GetElem_Lk(LinkList L, int i, ElemType_Lk& e);
status ListInsert_Lk(LinkList& L, int i, ElemType_Lk& e);
status ListDelet_Lk(LinkList& L, int i, ElemType_Lk& e);//在L中删除第i个元素，并将删掉的元素记在e中。
status CreateList_LkHead(LinkList& L, int n);//头插法
status CreateList_LkEnd(LinkList& L, int n);//尾巴插法
status DisplList_Lk(LinkList& L);
status DestoryList_Lk(LinkList& L);
status InitList_Lk(LinkList& L);//初始化链表(申请一个头结点)
bool ListEmpty_Lk(LinkList& L);
int ListLength_Lk(LinkList& L);
int LocateElem_Lk(LinkList& L, ElemType_Lk e);//查找元素，没找到就返回0


#endif
