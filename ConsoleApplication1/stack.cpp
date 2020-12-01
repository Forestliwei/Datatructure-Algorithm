#include "stack.h"

/*********************ջ��˳��洢�ṹ******************************/
void InitStack_Sq(SqStack& s)//��ʼ��һ����ջ
{
	s = (SqStack)malloc(sizeof(SStkNode));
	s->top = -1;  //ջ��ָ��-1��ʾ��ջ,ջ��ʼ��ָ��ջ��Ԫ��
}

void DestroyStack_Sq(SqStack& s)
{
	free(s);//�ͷ�ջ
}

bool StackEmpty_Sq(SqStack& s)
{
	return (s->top == -1);//ջ��ָ��-1��ʾ��ջ
}

status Push_Sq(SqStack& s, ElemeType_SStk e)//��ջ������ֻ��Ҫ�����ݴ��ݽ�ȥ�����ˣ�����Ҫ����
{
	if (s->top == (MaxSize_SStk - 1))return ERROR;
	s->top ++;
	s->data[s->top] = e;
	return OK;
}

status Pop_Sq(SqStack& s, ElemeType_SStk& e)//�������ã��Ա�����ݴ��ݳ�ȥ
{
	if (s->top == -1)return ERROR;
	e = s->data[s->top];
	s->top--;
	return OK;
}

bool GetTpo_Sq(SqStack& s, ElemeType_SStk& e)//ȡջ��Ԫ�أ�
{
	if (s->top == -1)return false;//ջ�����
	e = s->data[s->top];   //ֻȡ��ջ��Ԫ�أ���������ջ
	return true;
}

/*********************ջ����ʽ�洢�ṹ******************************/

void InitStack_Lk(LkStack& s)//��ʼ��һ����ջ
{
	s = (LkStack)malloc(sizeof(LStkNode));//����һ��ͷָ��
	s->next = NULL;//��ָ�룬��ջ��
}
void DestroyStack_Lk(LkStack& s)
{
	LkStack p,q;
	p = s;
	while (p!=NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
}

//�μ�д��
//void DestroyStack_Lk(LkStack& s)
//{
//	LkStack p, q;
//	p = s;
//	q = s->next;
//	while (q!=NULL)
//	{
//		free(p);
//		p = q;
//		q = p->next;
//	}
//	free(p);//�ͷ�δ�ڵ�
//}

bool StackEmpty_Lk(LkStack& s)
{
	return (s->next == NULL);
}

status Push_Lk(LkStack& s, ElemeType_LStk e)
{
	LkStack p;
	p = (LkStack)malloc(sizeof(LStkNode)); //����һ���ڴ�
	p->data = e;
	p->next = s->next;
	s->next = p;
	return OK;
}
status Pop_Lk(LkStack& s, ElemeType_LStk& e)//��ջ��Ҫע���ջǧ��Ҫ��ɾ��ͷ���
{
	LkStack p;
	if (s->next == NULL)return ERROR;//��ջ
	p = s->next;
	s->next = p->next;//��ջ
	e = p->data;//������
	free(p);//�ͷų�ջ���ڴ�
	return OK;
}

bool GetTpo_Lk(LkStack& s, ElemeType_LStk& e)//ȡջ��Ԫ�أ�����ջ��
{
	if (s->next == NULL)return false;
	e = s->next->data;//��ȡ����
	return true;
}





