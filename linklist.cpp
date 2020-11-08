#include "linklist.h"


status GetElem_Lk(LinkList L,int i,ElemType_Lk &e)
{
	LinkList p; //�ṹ��ָ��
	int j = 0;//iΪ������
	p = L; //pָ��ͷ���
	while (p && j<i)
	{
		j++;
		p = p->next;
	}
	if (!p || j < i)return ERROR;

	e = p->data;
	return OK;
}

status ListInsert_Lk(LinkList &L, int i, ElemType_Lk &e)//��ͷ���������ǰ��
{
	LinkList p; //�ṹ��ָ�룬������������
	LinkList q; //�½�һ���ṹ��ָ�룬������������
	int j = 0;//iΪ��������ͷ�ڵ�Ϊ0
	p = L; //pָ��ͷ���,
	while (p && j < i-1)//��ΪҪ��ǰ��壬����Ҫ��1
	{
		j++;
		p = p->next;
	}
	if (!p || j < i-1)return ERROR;

	//q->data = e;//���õ�д����Ҫ��̬�����ڴ�
	q = (LinkList)malloc(sizeof(LNode));   //�����ڴ�
	if (!q)exit(ERROR);

	q->data = e;

	q->next = p->next;
	p->next = q;

	//p->next = q;
	//q->next = p->next; //����д������Ϊ��һ���Ѿ��ı���p->next
}

status ListDelet_Lk(LinkList& L, int i,ElemType_Lk &e)//��ͷ���������ɾ����ɾ����Ԫ�ط�e��
{
	LinkList p; //�ڵ�ָ�룬������������
	LinkList q; //��ʱ���ɾ���Ľڵ�ȥ
	int j = 0;//iΪ������
	p = L; //pָ���һ���ڵ�
	while (p && j < i-1)//ɾ����i���ڵ㣬��Ҫ����i-1���ڵ��ָ��ָ���i+1���ڵ�
	{
		j++;
		p = p->next;
	}
	if (!p || j < i-1)return ERROR;

	//p->next = p->next->next;//��������д��������һ��������Ǹ��ڴ�û���ͷţ��Ժ��������ջ���

	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);//�ͷ�ɾ����Ԫ�ص��ڴ�
	return OK;
}

status CreateList_LkHead(LinkList& L,int n)//ͷ�巨
{
	LinkList q; //���ɽڵ㣬�����Ų���ڵ�
	int i;

	L = (LinkList)malloc(sizeof(LNode)); //����һ��ͷ���
	if (!L)exit(ERROR);
	L->next = NULL;//�Ƚ���һ��ͷ��㲢ָ��NULL

	//printf("please in put %d inttype data\n", n);
	for (i = n; i > 0; i--)//ͷ�巨�������
	{
		q = (LinkList)malloc(sizeof(LNode));//ÿ�ζ���������
		if (!q)exit(ERROR);

		//scanf_s("%d", &q->data);
		q->data = rand()%100;//�������
		q->next = L->next;
		L->next = q;
	}
	return OK;
}

status CreateList_LkEnd(LinkList& L, int n)//β�巨
{

	LinkList q; //���ɽڵ㣬�����Ų���ڵ�
	LinkList p; //���ɽڵ㣬������������ָ��ǰ�ڵ�
	int i;
	
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)exit(ERROR);
	L->next = NULL;

	p = L;//pָ��ǰ�ڵ�
	//printf("please in put %d ElemType_Lk data\n", n);
	for (i = 0; i < n; i++)
	{
		q = (LinkList)malloc(sizeof(LNode));//ÿ�ζ����������ڴ�
		if (!q)exit(ERROR);
		//scanf_s("%d", &q->data);
		q->data = rand() % 100;//�������
		p->next=q;
		p = p->next;//��дΪp = q;
	}
	p->next = NULL; //������������Ľ�β��NULL
	return OK;
}

status DisplList_Lk(LinkList& L)//������ͷ�ڵ������
{
	LinkList p;
	if (!L)return ERROR;
	p = L;
	p = p->next;//��һ���ƹ�ͷָ��
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	return OK;
}


status DestoryList_Lk(LinkList& L)  //����һ��������
{
	LinkList p;
	LinkList q; //�����ڵ㣬һ�����ɽڵ�ָ��ǰ�ڵ㣬һ�����ɽڵ㱻����

	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;//ɾ��֮�������ͷ���ָ��NULL
	return OK;
}


status InitList_Lk(LinkList& L)//��ʼ������(����һ��ͷ���)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)exit(ERROR);
	L->next = NULL;
	return OK;
}


