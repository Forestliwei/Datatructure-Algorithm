#ifndef _INC_STACK
#define _INC_STACK

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1

#define ElemeType_SStk int //˳��ջ��������
#define ElemeType_LStk int //��ʽջ��������


#define MaxSize_SStk 100 //˳��ջ�������

typedef int status;

typedef struct  //����ջ�ṹ
{
	ElemeType_SStk data[MaxSize_SStk];
	int top;   //ջ��ָ��
}SStkNode,*SqStack;


typedef struct LStkNode //����ջ�ṹ
{
	ElemeType_LStk data;
	struct LStkNode *next;   //ָ����һ���ڵ��ָ��,���ﲻ����LkStackֱ�Ӷ��壡
}LStkNode, *LkStack;

/*********************ջ��˳��洢�ṹ******************************/
void InitStack_Sq(SqStack& s);//��ʼ��һ����ջ
void DestroyStack_Sq(SqStack& s);
bool StackEmpty_Sq(SqStack& s);
status Push_Sq(SqStack& s, ElemeType_SStk e);//��ջ������ֻ��Ҫ�����ݴ��ݽ�ȥ�����ˣ�����Ҫ����
status Pop_Sq(SqStack& s, ElemeType_SStk& e);//�������ã��Ա�����ݴ��ݳ�ȥ
bool GetTpo_Sq(SqStack& s, ElemeType_SStk& e);//ȡջ��Ԫ�أ�

/*********************ջ����ʽ�洢�ṹ******************************/

void InitStack_Lk(LkStack& s);//��ʼ��һ����ջ
void DestroyStack_Lk(LkStack& s);
bool StackEmpty_Lk(LkStack& s);
status Push_Lk(LkStack& s, ElemeType_LStk e);
status Pop_Lk(LkStack& s, ElemeType_LStk& e);//��ջ
bool GetTpo_Lk(LkStack& s, ElemeType_LStk& e);//ȡջ��Ԫ�أ�����ջ��


#endif




