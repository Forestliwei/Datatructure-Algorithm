#ifndef _INC_ALGORITHM
#define _INC_ALGORITHM
/*
������֤�ײ�
��������㷨
*/
#include "stack.h"

#define Maxsize 100


typedef struct {  //��ʾ��ǰλ�úͿ��ߵķ�λ
	int i;
	int j;
	int di;
}Box;
typedef struct {   //˳��ջ
	Box data[Maxsize];
	int top;
}StType;


typedef struct {
	int i;
	int j;
	int pre;
}Box_qu;

typedef struct {

	Box_qu data[Maxsize];
	int front;
	int rear;
}Qu_Type;


bool symmetry(ElemeType_LStk str[]);//�ж��ַ����Ƿ��ǶԳƴ�



bool magpath_Stack(int xi, int yi, int xe, int ye);
bool magpath_Qu(int xi, int yi, int xe, int ye);

#endif
