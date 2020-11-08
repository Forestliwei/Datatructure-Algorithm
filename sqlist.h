#ifndef _INC_SQLIST
#define _INC_SQLIST

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LIST_INIT_SIZE 100  //初始化的时候分配的量
#define LISTINCREMENT 10  //初始化分配的量不够的时候的增量
#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int status;

typedef struct {
	ElemType* elem;//存储空间基地址
	int length;  //当前长度（即元素个数）
	int listsize;//当前分配的存储容量
}SqList;

status InitList_Sq(SqList& L);
status ListInsert_Sq(SqList& L, int i, ElemType e);
status ListDelet_Sq(SqList& L, int i);
int LocateElement_Sq(SqList L, ElemType e);
int ListLength_Sq(SqList L);//获取表长度
status DisplList_Sq(SqList L);//显示表
bool ListEmpty_Sq(SqList L);//是否为空
status GetElem_Sq(SqList L, int i, ElemType& e);//指定位置元素

#endif