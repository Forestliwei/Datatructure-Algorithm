#ifndef _INC_STACK
#define _INC_STACK

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1

#define ElemeType_SStk int //顺序栈数据类型
#define ElemeType_LStk int //链式栈数据类型


#define MaxSize_SStk 100 //顺序栈最大容量

typedef int status;

typedef struct  //定义栈结构
{
	ElemeType_SStk data[MaxSize_SStk];
	int top;   //栈顶指针
}SStkNode,*SqStack;


typedef struct LStkNode //定义栈结构
{
	ElemeType_LStk data;
	struct LStkNode *next;   //指向下一个节点的指针,这里不能用LkStack直接定义！
}LStkNode, *LkStack;

/*********************栈的顺序存储结构******************************/
void InitStack_Sq(SqStack& s);//初始化一个空栈
void DestroyStack_Sq(SqStack& s);
bool StackEmpty_Sq(SqStack& s);
status Push_Sq(SqStack& s, ElemeType_SStk e);//入栈操作，只需要把数据传递进去就行了，不需要引用
status Pop_Sq(SqStack& s, ElemeType_SStk& e);//数据引用，以便把数据传递出去
bool GetTpo_Sq(SqStack& s, ElemeType_SStk& e);//取栈顶元素，

/*********************栈的链式存储结构******************************/

void InitStack_Lk(LkStack& s);//初始化一个空栈
void DestroyStack_Lk(LkStack& s);
bool StackEmpty_Lk(LkStack& s);
status Push_Lk(LkStack& s, ElemeType_LStk e);
status Pop_Lk(LkStack& s, ElemeType_LStk& e);//出栈
bool GetTpo_Lk(LkStack& s, ElemeType_LStk& e);//取栈顶元素（不退栈）


#endif




