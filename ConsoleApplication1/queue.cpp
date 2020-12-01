#include "queue.h"

/**************循环队列*********************/
void InitQueue_cir(Queue &qu)
{
	qu = (Queue)malloc(sizeof(QuType));
	if (!qu)exit(0);

	qu->front = 0;//不应该是-1吗？为什么书上为0？因位环形队列从1开始也是可以的！
	qu->count = 0;
}
void DestoryQueue_cir(Queue& qu)
{
	free(qu);
}

status EnQueue_cir(Queue& qu, ElemeType_SQu e)
{
	if (qu->count == MaxSize_SQu)return ERROR;
	qu->rear = (qu->front + qu->count +1) % MaxSize_SQu;//求队尾指向一个新的位置
	qu->data[qu->rear] = e;//装值
	qu->count += 1;//数量加一
	return OK;
}

status DeQueue_cir(Queue& qu, ElemeType_SQu &e)
{
	if (qu->count == 0)return ERROR;
	qu->front = (qu->front + 1) % MaxSize_SQu;//新的队首（队首总是指向第一个元素的前一个位置），这里还有数据
	e = qu->data[qu->front];//去除队首的元素
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




/**************非循环队列*********************/
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
	if (qu->rear == MaxSize_SQu - 1)return ERROR;//如果当前队尾指针已经指向了最后一个元素位置，则队满

	qu->rear += 1;
	qu->data[qu->rear] = e;
	return OK;
}
status DeQueue_ln(Queue& qu, ElemeType_SQu& e)
{
	if (qu->front == qu->rear)return ERROR;//队空
	qu->front += 1;//只需要挪动队首就行了
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



/**************链式队列*********************/
void InitQueue_lk(liqueue& qu)
{
	qu = (liqueue)malloc(sizeof(LiQueue));//创建一个队首和队尾指针的节点
	if (!qu)exit(0);
	qu->front = NULL;
	qu->rear = NULL;
}

status DestoryQueue_lk(liqueue& qu)
{
	LQueue p,q;
	p = qu->front;//将第一个元素交给P
	while (p != NULL)//全部释放掉
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
	LQueue q;//创建待插入的节点
	q = (LQueue)malloc(sizeof(QuNode));//创建新节点
	if (!q)exit(0);

	q->data = e;
	q->next = NULL;
	if (qu->front == NULL)//如果是空队
	{
		qu->rear = q;
		qu->front = q;
	}
	else
	{
		qu->rear->next = q;//队尾节点指向新的节点（把新节点添加进去）
		qu->rear = q;//指向新的队尾节点
	}
	return OK;
}

status DeQueue_lk(liqueue& qu, ElemeType_LQu& e)
{
	LQueue p;//用来临时保存要删除的节点
	if (qu->front == NULL)return ERROR;
	
	p = qu->front;//指向链表的第一个节点（即队首节点），注意front是一个指向第一个节点的指针！
	if (qu->front == qu->rear)//指向非空队的同一个节点就说明是只有一个节点
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
	//return (qu->rear == NULL);//这样写也行
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


/*******************链式循环队列（只用尾节点指针）******************/
void InitQueue_lk_cir(liqueue& qu) //其实不用传递qu，只需要传递一个rear指针就行了，我这里懒得重新定义了，就用了之前的定义。
{
	qu = (liqueue)malloc(sizeof(LiQueue));//一般只需要传递个指针就行了，不用这一步。
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
		p->next = p;//只有一个节点的循环链表就指向自己
		qu->rear = p;
	}
	else
	{
		p->next = qu->rear->next;//先你的下一个节点交给新节点，才能松手！顺序别反了。
		qu->rear->next = p;
		qu->rear = p;//指向新插入的节点（新节点称为尾节点），也就是遵循队列“尾进”的原则。
	}
	return OK;
}
status DeQueue_lk_cir(liqueue& qu, ElemeType_LQu& e)//注意出队是从头出
{
	LQueue p;
	if (qu->rear == NULL)return ERROR;
	if (qu->rear== qu->rear->next)//尾节点和首节点相同（只有一个节点）
	{
		p = qu->rear;//指向首节点（因为只有一个节点，所以rear就是首节点）
		qu->rear = NULL;//别忘了指针置为空
	}
	else
	{
		p = qu->rear->next;//指向首节点(循环队列的尾节点的下一个节点就是首节点)
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
	while ((p != NULL) && (p->next!=qu->rear))//如果下一个节点是未节点停止计数
	{
		p = p->next;
		num++;
	}
	num++;
	return num;
}

/*******************链表循环队列测试代码******************/
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


/*******************链表线性队列测试代码******************/
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



/*******************数组线性队列测试代码******************/
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