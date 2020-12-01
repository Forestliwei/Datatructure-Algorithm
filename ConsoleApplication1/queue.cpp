#include "queue.h"

/**************ѭ������*********************/
void InitQueue_cir(Queue &qu)
{
	qu = (Queue)malloc(sizeof(QuType));
	if (!qu)exit(0);

	qu->front = 0;//��Ӧ����-1��Ϊʲô����Ϊ0����λ���ζ��д�1��ʼҲ�ǿ��Եģ�
	qu->count = 0;
}
void DestoryQueue_cir(Queue& qu)
{
	free(qu);
}

status EnQueue_cir(Queue& qu, ElemeType_SQu e)
{
	if (qu->count == MaxSize_SQu)return ERROR;
	qu->rear = (qu->front + qu->count +1) % MaxSize_SQu;//���βָ��һ���µ�λ��
	qu->data[qu->rear] = e;//װֵ
	qu->count += 1;//������һ
	return OK;
}

status DeQueue_cir(Queue& qu, ElemeType_SQu &e)
{
	if (qu->count == 0)return ERROR;
	qu->front = (qu->front + 1) % MaxSize_SQu;//�µĶ��ף���������ָ���һ��Ԫ�ص�ǰһ��λ�ã������ﻹ������
	e = qu->data[qu->front];//ȥ�����׵�Ԫ��
	qu->count--;
	return OK;
}
bool QueueEmpty_cir(Queue& qu)
{
	return (qu->count == 0);
}
int QueueCount_cir(Queue& qu)
{
	return qu->count;
}




/**************��ѭ������*********************/
void InitQueue_ln(Queue& qu)
{
	qu = (Queue)malloc(sizeof(QuType));
	if (!qu)exit(0);

	qu->front = -1;
	qu->rear = -1;
}

void DestoryQueue_ln(Queue& qu)
{
	free(qu);
}

status EnQueue_ln(Queue& qu, ElemeType_SQu e)
{
	if (qu->rear == MaxSize_SQu - 1)return ERROR;//�����ǰ��βָ���Ѿ�ָ�������һ��Ԫ��λ�ã������

	qu->rear += 1;
	qu->data[qu->rear] = e;
	return OK;
}
status DeQueue_ln(Queue& qu, ElemeType_SQu& e)
{
	if (qu->front == qu->rear)return ERROR;//�ӿ�
	qu->front += 1;//ֻ��ҪŲ�����׾�����
	e = qu->data[qu->front];
	return OK;
}
bool QueueEmpty_ln(Queue& qu)
{
	return (qu->front == qu->rear);
}
int QueueCount_ln(Queue& qu)
{
	return (qu->rear - qu->front);
}



/**************��ʽ����*********************/
void InitQueue_lk(liqueue& qu)
{
	qu = (liqueue)malloc(sizeof(LiQueue));//����һ�����׺Ͷ�βָ��Ľڵ�
	if (!qu)exit(0);
	qu->front = NULL;
	qu->rear = NULL;
}

status DestoryQueue_lk(liqueue& qu)
{
	LQueue p,q;
	p = qu->front;//����һ��Ԫ�ؽ���P
	while (p != NULL)//ȫ���ͷŵ�
	{
		q = p->next;//
		free(p);
		p = q;
	}
	free(qu);
	return OK;
}


status EnQueue_lk(liqueue& qu, ElemeType_LQu e)
{
	LQueue q;//����������Ľڵ�
	q = (LQueue)malloc(sizeof(QuNode));//�����½ڵ�
	if (!q)exit(0);

	q->data = e;
	q->next = NULL;
	if (qu->front == NULL)//����ǿն�
	{
		qu->rear = q;
		qu->front = q;
	}
	else
	{
		qu->rear->next = q;//��β�ڵ�ָ���µĽڵ㣨���½ڵ���ӽ�ȥ��
		qu->rear = q;//ָ���µĶ�β�ڵ�
	}
	return OK;
}

status DeQueue_lk(liqueue& qu, ElemeType_LQu& e)
{
	LQueue p;//������ʱ����Ҫɾ���Ľڵ�
	if (qu->front == NULL)return ERROR;
	
	p = qu->front;//ָ������ĵ�һ���ڵ㣨�����׽ڵ㣩��ע��front��һ��ָ���һ���ڵ��ָ�룡
	if (qu->front == qu->rear)//ָ��ǿնӵ�ͬһ���ڵ��˵����ֻ��һ���ڵ�
	{
		qu->front = NULL;
		qu->rear = NULL;
	}
	else
	{
		qu->front = qu->front->next;
	}
	e = p->data;
	free(p);
	return OK;
}

bool QueueEmpty_lk(liqueue& qu)
{
	return (qu->front == NULL);
	//return (qu->rear == NULL);//����дҲ��
}
int QueueCount_lk(liqueue& qu)
{
	LQueue p;
	int num = 0;
	p = qu->front;
	while (p != NULL)
	{
		num++; 
		p = p->next;
	}
	return num;
}


/*******************��ʽѭ�����У�ֻ��β�ڵ�ָ�룩******************/
void InitQueue_lk_cir(liqueue& qu) //��ʵ���ô���qu��ֻ��Ҫ����һ��rearָ������ˣ��������������¶����ˣ�������֮ǰ�Ķ��塣
{
	qu = (liqueue)malloc(sizeof(LiQueue));//һ��ֻ��Ҫ���ݸ�ָ������ˣ�������һ����
	qu->rear = NULL;
}
bool QueueEmpty_lk_cir(liqueue& qu)
{
	return (qu->rear == NULL);
}
status EnQueue_lk_cir(liqueue& qu, ElemeType_LQu e)
{
	LQueue p;
	p = (LQueue)malloc(sizeof(QuNode));
	if (!p)exit(0);
	p->data = e;
	if (qu->rear == NULL)
	{
		p->next = p;//ֻ��һ���ڵ��ѭ�������ָ���Լ�
		qu->rear = p;
	}
	else
	{
		p->next = qu->rear->next;//�������һ���ڵ㽻���½ڵ㣬�������֣�˳����ˡ�
		qu->rear->next = p;
		qu->rear = p;//ָ���²���Ľڵ㣨�½ڵ��Ϊβ�ڵ㣩��Ҳ������ѭ���С�β������ԭ��
	}
	return OK;
}
status DeQueue_lk_cir(liqueue& qu, ElemeType_LQu& e)//ע������Ǵ�ͷ��
{
	LQueue p;
	if (qu->rear == NULL)return ERROR;
	if (qu->rear== qu->rear->next)//β�ڵ���׽ڵ���ͬ��ֻ��һ���ڵ㣩
	{
		p = qu->rear;//ָ���׽ڵ㣨��Ϊֻ��һ���ڵ㣬����rear�����׽ڵ㣩
		qu->rear = NULL;//������ָ����Ϊ��
	}
	else
	{
		p = qu->rear->next;//ָ���׽ڵ�(ѭ�����е�β�ڵ����һ���ڵ�����׽ڵ�)
		qu->rear->next = p->next;
	}
	e = p->data;
	free(p);
	return OK;
}

int QueueCount_lk_cir(liqueue& qu)
{
	LQueue p;
	int num = 0;
	p = qu->rear;
	if (p == NULL)return num;
	while ((p != NULL) && (p->next!=qu->rear))//�����һ���ڵ���δ�ڵ�ֹͣ����
	{
		p = p->next;
		num++;
	}
	num++;
	return num;
}

/*******************����ѭ�����в��Դ���******************/
void QueueTest_lk_cir()
{
	ElemeType_LQu e;
	liqueue qu;
	InitQueue_lk_cir(qu);
	if (QueueEmpty_lk_cir(qu)) printf("Empty\n"); else printf("not empty\n");
	EnQueue_lk_cir(qu, 12);
	printf("%d\n", QueueCount_lk_cir(qu));
	EnQueue_lk_cir(qu, 23);
	EnQueue_lk_cir(qu, 78);
	EnQueue_lk_cir(qu, 102);
	EnQueue_lk_cir(qu, 456);
	printf("%d\n", QueueCount_lk_cir(qu));
	if (QueueEmpty_lk_cir(qu)) printf("Empty\n"); else printf("not empty\n");

	printf("%d\n", DeQueue_lk_cir(qu, e));
	printf("%d\n", e);
	DeQueue_lk_cir(qu, e);
	printf("%d\n", e);
	DeQueue_lk_cir(qu, e);
	printf("%d\n", e);
	DeQueue_lk_cir(qu, e);
	printf("%d\n", e);
	DeQueue_lk_cir(qu, e);
	printf("%d\n", e);
	if (QueueEmpty_lk_cir(qu)) printf("Empty\n"); else printf("not empty\n");
}


/*******************�������Զ��в��Դ���******************/
void QueueTest_lk()
{
	ElemeType_LQu e;
	liqueue qu;
	InitQueue_lk(qu);
	if (QueueEmpty_lk(qu)) printf("Empty\n"); else printf("not empty\n");
	EnQueue_lk(qu, 12);
	printf("%d\n", QueueCount_lk(qu));
	EnQueue_lk(qu, 23);
	EnQueue_lk(qu, 78);
	EnQueue_lk(qu, 102);
	EnQueue_lk(qu, 456);
	printf("%d\n", QueueCount_lk(qu));
	if (QueueEmpty_lk(qu)) printf("Empty\n"); else printf("not empty\n");

	printf("%d\n", DeQueue_lk(qu, e));
	printf("%d\n", e);
	DeQueue_lk(qu, e);
	printf("%d\n", e);
	DeQueue_lk(qu, e);
	printf("%d\n", e);
	DeQueue_lk(qu, e);
	printf("%d\n", e);
	DeQueue_lk(qu, e);
	printf("%d\n", e);
	if (QueueEmpty_lk(qu)) printf("Empty\n"); else printf("not empty\n");
}



/*******************�������Զ��в��Դ���******************/
void QueueTest()
{
	ElemeType_SQu e;
	Queue qu;
	InitQueue_ln(qu);
	if (QueueEmpty_ln(qu)) printf("Empty\n"); else printf("not empty\n");
	EnQueue_ln(qu, 12);
	printf("%d\n", QueueCount_ln(qu));
	EnQueue_ln(qu, 23);
	EnQueue_ln(qu, 78);
	EnQueue_ln(qu, 102);
	EnQueue_ln(qu, 456);
	printf("%d\n", QueueCount_ln(qu));
	if (QueueEmpty_ln(qu)) printf("Empty\n"); else printf("not empty\n");
	DeQueue_ln(qu, e);
	printf("%d\n", e);
	DeQueue_ln(qu, e);
	printf("%d\n", e);
	DeQueue_ln(qu, e);
	printf("%d\n", e);
	DeQueue_ln(qu, e);
	printf("%d\n", e);
	DeQueue_ln(qu, e);
	printf("%d\n", e);
	if (QueueEmpty_ln(qu)) printf("Empty\n"); else printf("not empty\n");
}