#ifndef _INC_QUEUE
#define _INC_QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1
typedef int status;


#define ElemeType_SQu int //˳��ջ��������
#define MaxSize_SQu 100 //˳��ջ�������
typedef struct {
	ElemeType_SQu data[MaxSize_SQu];
	int front;//����
	int rear;//��β
	int count;//Ԫ�ظ���
}QuType, * Queue;


#define ElemeType_LQu int //��ʽջ��������
typedef struct qNode {
	ElemeType_LQu data;
	struct qNode* next;
}QuNode, * LQueue;
typedef struct
{
	LQueue front;//���׽ڵ�ָ��
	LQueue rear;//��β�ڵ�ָ��
}LiQueue,*liqueue;


/**************����ѭ������*********************/
void InitQueue_cir(Queue& qu);
void DestoryQueue_cir(Queue& qu);
status EnQueue_cir(Queue& qu, ElemeType_SQu e);
status DeQueue_cir(Queue& qu, ElemeType_SQu& e);
bool QueueEmpty_cir(Queue& qu);
int QueueCount_cir(Queue& qu);

/**************�������Զ���*********************/
void InitQueue_ln(Queue& qu);
void DestoryQueue_ln(Queue& qu);
status EnQueue_ln(Queue& qu, ElemeType_SQu e);
status DeQueue_ln(Queue& qu, ElemeType_SQu& e);
bool QueueEmpty_ln(Queue& qu);
int QueueCount_ln(Queue& qu);


/*******************���Դ���******************/
void QueueTest();//�������Զ��в��Դ���
void QueueTest_lk();//�������Զ��в��Դ���
void QueueTest_lk_cir();//����ѭ�����в��Դ���

#endif