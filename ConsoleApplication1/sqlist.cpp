#include "sqlist.h"

status InitList_Sq(SqList& L) //创建一个空表
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));//申请内存
	if (!L.elem) exit(ERROR);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

status ListInsert_Sq(SqList& L,int i, ElemType e) //插入 一个 元素
{
	int *q,*p;
	if (i<1 || i>(L.length+1))return ERROR;//可插入的位置是length+1个
	if (L.length >= L.listsize)//内存不够用了就增加LISTINCREMENT个内存
	{
		L.elem = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT )*sizeof(ElemType));
		if (!L.elem)exit(ERROR);
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i-1]);
	for (p = &(L.elem[L.length]); p >= q; p--)
	{
		*(p + 1) = *p;
	}
	*q = e;
	L.length += 1;
	return OK;
}
status ListDelet_Sq(SqList &L,int i)
{
	int *q,*p,e;
	if (i<1 || i>L.length)return ERROR;//错误
	e = L.elem[i-1];  //保存要删除的元素
	q = L.elem + L.length - 1 - 1;//删除后的尾部   L.elem + L.length - 1是删除前最后一个元素的下标，在减一是删除后的最后一个元素下标
	for (p = &L.elem[i-1]; p <= q; p++)
	{
		*p = *(p + 1);
	}
	L.length -= 1;
	return OK;
}

int LocateElement_Sq(SqList L, ElemType e)//定位查找元素
{
	int i = 1;
	while (i <= L.length)
	{
		if (L.elem[i - 1] == e)return i;
		i++;
	}
	return 0;
}

int ListLength_Sq(SqList L)//获取表长度
{
	return L.length;
}
status DisplList_Sq(SqList L)//显示表
{
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		printf("%d  ", L.elem[i]);
	}
	return OK;
}
bool ListEmpty_Sq(SqList L)//是否为空
{
	if (L.length == 0)
		return true;
	else
		return false;
}

status GetElem_Sq(SqList L,int i, ElemType &e)//指定位置元素
{
	e = L.elem[i - 1];
	return OK;
}
//int LocateElement(SqList& L, ElemType e)
//{
//	int i = 1;
//	int *p = L.elem;
//	while (i <= L.length && !(*p++ == e))++i;
//	if (i <= L.length)return i;
//	else return 0;
//}



//void SqList_Test()
//{
//	int e;
//	SqList L;
//	InitList_Sq(L);
//	printf("ListEmpty(L): %d\n", ListEmpty(L));
//	ListInsert(L, 1, 22);
//	printf("ListInsert(L, 1, 22)\n");
//	ListInsert(L, 2, 23);
//	printf("ListInsert(L, 2, 23)\n");
//	ListInsert(L, 3, 26);
//	printf("ListInsert(L, 3, 26)\n");
//	ListInsert(L, 4, 287);
//	printf("ListInsert(L, 4, 287)\n");
//	printf("ListEmpty(L): %d\n", ListEmpty(L));
//	DislpList(L);
//	printf("\nListLength(L): %d\n", ListLength(L));
//	printf("LocateElement(L, 23): %d\n", LocateElement(L, 23));
//	ListDelet(L, 4);
//	ListDelet(L, 1);
//	DislpList(L);
//	printf("\nLocateElement(L, 23): %d\n", LocateElement(L, 23));
//	GetElem(L, 1, e);
//	printf("GetElem(L, 1, e): %d\n", e);
//	return 0;
//}





