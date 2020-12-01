#include "stack.h"

/*********************栈的顺序存储结构******************************/
void InitStack_Sq(SqStack& s)//初始化一个空栈
{
	s = (SqStack)malloc(sizeof(SStkNode));
	s->top = -1;  //栈顶指向-1表示空栈,栈顶始终指向栈顶元素
}

void DestroyStack_Sq(SqStack& s)
{
	free(s);//释放栈
}

bool StackEmpty_Sq(SqStack& s)
{
	return (s->top == -1);//栈顶指向-1表示空栈
}

status Push_Sq(SqStack& s, ElemeType_SStk e)//入栈操作，只需要把数据传递进去就行了，不需要引用
{
	if (s->top == (MaxSize_SStk - 1))return ERROR;
	s->top ++;
	s->data[s->top] = e;
	return OK;
}

status Pop_Sq(SqStack& s, ElemeType_SStk& e)//数据引用，以便把数据传递出去
{
	if (s->top == -1)return ERROR;
	e = s->data[s->top];
	s->top--;
	return OK;
}

bool GetTpo_Sq(SqStack& s, ElemeType_SStk& e)//取栈顶元素，
{
	if (s->top == -1)return false;//栈下溢出
	e = s->data[s->top];   //只取出栈顶元素，但并不退栈
	return true;
}

/*********************栈的链式存储结构******************************/

void InitStack_Lk(LkStack& s)//初始化一个空栈
{
	s = (LkStack)malloc(sizeof(LStkNode));//创建一个头指针
	s->next = NULL;//空指针，空栈。
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

//课件写法
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
//	free(p);//释放未节点
//}

bool StackEmpty_Lk(LkStack& s)
{
	return (s->next == NULL);
}

status Push_Lk(LkStack& s, ElemeType_LStk e)
{
	LkStack p;
	p = (LkStack)malloc(sizeof(LStkNode)); //申请一个内存
	p->data = e;
	p->next = s->next;
	s->next = p;
	return OK;
}
status Pop_Lk(LkStack& s, ElemeType_LStk& e)//出栈，要注意出栈千万不要物删了头结点
{
	LkStack p;
	if (s->next == NULL)return ERROR;//空栈
	p = s->next;
	s->next = p->next;//退栈
	e = p->data;//出数据
	free(p);//释放出栈的内存
	return OK;
}

bool GetTpo_Lk(LkStack& s, ElemeType_LStk& e)//取栈顶元素（不退栈）
{
	if (s->next == NULL)return false;
	e = s->next->data;//读取数据
	return true;
}





