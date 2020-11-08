#include "sqlist.h"
#include "linklist.h"

#define N 10

//int main()
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

void Lklist_Test();

int main()
{

	Lklist_Test();
	return 0;
}


void Lklist_Test()
{
	LinkList L;
	int e;
	int i;
	int ii = 0;

	InitList_Lk(L);//��ʼ��һ��������ֻ��ͷ��㣩
	printf("ListEmpty_Lk(L):%d\n",ListEmpty_Lk(L));
	//����ͷ�巨��β�巨����
	//CreateList_LkHead(L, N);//ͷ�巨����һ��L������ΪN
	CreateList_LkEnd(L, N);//β�巨����һ��L������ΪN
	printf("L has been created, DisplList_Lk(L):");
	DisplList_Lk(L);
	printf("\nListEmpty_Lk(L):%d\n", ListEmpty_Lk(L));
	printf("ListLength_Lk(L):%d\n", ListLength_Lk(L));
	//����nGetElem_Lk����
	for (i = 1; i <= N; i++)
	{
		GetElem_Lk(L, i, e);
		printf("\nGetElem_Lk(L, %d, e):%d", i, e);
	}
	
	//����ListInsert_Lk����
	printf("\ninsert:");
	for (i = 1; i <= 5; i++)//���5��������λ�ò�����������
	{
		e = rand() % 100;
		ii = rand() % N+ 1;
		ListInsert_Lk(L, ii, e);
		printf("\n'%d' in %d\n", e, ii);
		DisplList_Lk(L);
	}
	printf("\n\nListLength_Lk(L):%d\n", ListLength_Lk(L));

	printf("LocateElem_Lk(L, 12):%d\n", LocateElem_Lk(L, 69));
	//����ListDelet_Lk����
	printf("\nDelet:");
	for (i = 1; i <= 5; i++)//���5��������λ��ɾ����������
	{
		ii = rand() % N + 1;
		ListDelet_Lk(L, ii,e);
		printf("\n'%d' in %d\n", e, ii);
		DisplList_Lk(L);
	}

	DestoryList_Lk(L);
	printf("\n%d",DisplList_Lk(L));
}
