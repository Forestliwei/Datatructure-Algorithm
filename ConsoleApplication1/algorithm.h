#ifndef _INC_ALGORITHM
#define _INC_ALGORITHM
/*
用于验证底层
用于设计算法
*/
#include "stack.h"

#define Maxsize 100


typedef struct {  //表示当前位置和可走的方位
	int i;
	int j;
	int di;
}Box;
typedef struct {   //顺序栈
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


bool symmetry(ElemeType_LStk str[]);//判断字符串是否是对称串



bool magpath_Stack(int xi, int yi, int xe, int ye);
bool magpath_Qu(int xi, int yi, int xe, int ye);

#endif
