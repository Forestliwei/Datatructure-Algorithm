#include "linklist.h"


status GetElem_Lk(LinkList L,int i,ElemType_Lk &e)
{
	LinkList p; //结构体指针
	int j = 0;//i为计数器
	
	if (!L)return ERROR;
	
	p = L; //p指向头结点
	while (p && j<i)
	{
		j++;
		p = p->next;
	}
	if (!p || j < i)return ERROR;

	e = p->data;
	return OK;
}

status ListInsert_Lk(LinkList &L, int i, ElemType_Lk &e)//带头结点的链表的前插
{
	LinkList p; //结构体指针，用来遍历链表
	LinkList q; //新建一个结构体指针，用来插入链表
	int j = 0;//i为计数器，头节点为0
	
	if (!L)return ERROR;

	p = L; //p指向头结点,
	while (p && j < i-1)//因为要在前面插，所以要减1
	{
		j++;
		p = p->next;
	}
	if (!p || j < i-1)return ERROR;

	//q->data = e;//不好的写法，要动态申请内存
	q = (LinkList)malloc(sizeof(LNode));   //申请内存
	if (!q)exit(ERROR);

	q->data = e;

	q->next = p->next;
	p->next = q;

	//p->next = q;
	//q->next = p->next; //错误写法，因为上一句已经改变了p->next
}

status ListDelet_Lk(LinkList& L, int i,ElemType_Lk &e)//带头结点的链表的删除，删除的元素放e中
{
	LinkList p; //节点指针，用来遍历链表
	LinkList q; //临时存放删除的节点去
	int j = 0;//i为计数器

	if (!L)return ERROR;

	p = L; //p指向第一个节点
	while (p && j < i-1)//删除第i个节点，需要将第i-1个节点的指针指向第i+1个节点
	{
		j++;
		p = p->next;
	}
	if (!p || j < i-1)return ERROR;

	//p->next = p->next->next;//可以这样写，但是有一个问题就是该内存没有释放，以后容易造成栈溢出

	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);//释放删掉的元素的内存
	return OK;
}

status CreateList_LkHead(LinkList& L,int n)//头插法
{
	LinkList q; //自由节点，用来放插入节点
	int i;

	if (!L)//如果链表没有初始化就先初始化
	{
		L = (LinkList)malloc(sizeof(LNode)); //创建一个头结点
		if (!L)exit(ERROR);
			L->next = NULL;//先建立一个头结点并指向NULL
	}
	//printf("please in put %d inttype data\n", n);
	for (i = n; i > 0; i--)//头插法是逆序的
	{
		q = (LinkList)malloc(sizeof(LNode));//每次都重新申请
		if (!q)exit(ERROR);

		//scanf_s("%d", &q->data);
		q->data = rand()%100;//填充数据
		q->next = L->next;
		L->next = q;
	}
	return OK;
}

status CreateList_LkEnd(LinkList& L, int n)//尾插法
{

	LinkList q; //自由节点，用来放插入节点
	LinkList p; //自由节点，用来遍历链表，指向当前节点
	int i;

	if (!L)//如果链表没有初始化就先初始化
	{
		L = (LinkList)malloc(sizeof(LNode));
		if (!L)exit(ERROR);
			L->next = NULL;
	}

	p = L;//p指向当前节点
	//printf("please in put %d ElemType_Lk data\n", n);
	for (i = 0; i < n; i++)
	{
		q = (LinkList)malloc(sizeof(LNode));//每次都重新申请内存
		if (!q)exit(ERROR);
		//scanf_s("%d", &q->data);
		q->data = rand() % 100;//填充数据
		p->next=q;
		p = p->next;//或写为p = q;
	}
	p->next = NULL; //容易忘在链表的结尾加NULL
	return OK;
}

status DisplList_Lk(LinkList& L)//遍历带头节点的链表
{
	LinkList p;
	
	if (!L) return ERROR;//如果是未初始化的链表就返回一个错误
	
	p = L;
	p = p->next;//第一次绕过头指针
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	return OK;
}


status DestoryList_Lk(LinkList& L)  //销毁一个单链表
{
	LinkList p;
	LinkList q; //两个节点，一个自由节点指向当前节点，一个自由节点被销毁

	if (!L)return ERROR;

	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;//删除之后别忘了头结点指向NULL
	return OK;
}


status InitList_Lk(LinkList& L)//初始化链表(申请一个头结点)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)exit(ERROR);
		L->next = NULL;
	return OK;
}


bool ListEmpty_Lk(LinkList& L)
{
	if (!L)return ERROR;
	
	return (L->next == NULL);
}

int ListLength_Lk(LinkList& L)
{
	int n = 0;
	LinkList p;

	if (!L)return ERROR;

	p = L->next;
	while (p)
	{
		n++;
		p = p->next;
	}
	return n;
}

int LocateElem_Lk(LinkList& L, ElemType_Lk e)//查找元素，没找到就返回0
{
	LinkList p;
	int i = 0;
	
	if (!L)return ERROR;

	p = L->next;//指向第一个节点

	while (p)
	{
		i++;
		if(p->data == e)return i;
		p = p->next;
	}
	return 0;//没找到就返回0
}






