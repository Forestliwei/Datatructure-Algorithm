#ifndef _INC_QUEUE
#define _INC_QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1
typedef int status;


#define ElemeType_SQu int //顺序栈数据类型
#define MaxSize_SQu 100 //顺序栈最大容量
typedef struct {
	ElemeType_SQu data[MaxSize_SQu];
	int front;//队首
	int rear;//队尾
	int count;//元素个数
}QuType, * Queue;


#define ElemeType_LQu int //链式栈数据类型
typedef struct qNode {
	ElemeType_LQu data;
	struct qNode* next;
}QuNode, * LQueue;
typedef struct
{
	LQueue front;//队首节点指针
	LQueue rear;//队尾节点指针
}LiQueue,*liqueue;


/**************数组循环队列*********************/
void InitQueue_cir(Queue& qu);
void DestoryQueue_cir(Queue& qu);
status EnQueue_cir(Queue& qu, ElemeType_SQu e);
status DeQueue_cir(Queue& qu, ElemeType_SQu& e);
bool QueueEmpty_cir(Queue& qu);
int QueueCount_cir(Queue& qu);

/**************数组线性队列*********************/
void InitQueue_ln(Queue& qu);
void DestoryQueue_ln(Queue& qu);
status EnQueue_ln(Queue& qu, ElemeType_SQu e);
status DeQueue_ln(Queue& qu, ElemeType_SQu& e);
bool QueueEmpty_ln(Queue& qu);
int QueueCount_ln(Queue& qu);


/*******************测试代码******************/
void QueueTest();//数组线性队列测试代码
void QueueTest_lk();//链表线性队列测试代码
void QueueTest_lk_cir();//链表循环队列测试代码

#endif