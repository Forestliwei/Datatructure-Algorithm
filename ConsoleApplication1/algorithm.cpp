#include "algorithm.h"


int mg[10][10] = {                         //迷宫
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
//判断字符串是否是对称串
bool symmetry(ElemeType_LStk str[])
{
	LkStack s;//创建一个栈
	int i;
	ElemeType_LStk e;
	InitStack_Lk(s);//初始化一个栈
	for (i = 0; str[i]!='\0'; i++)
	{
		Push_Lk(s, str[i]);//入栈
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		Pop_Lk(s, e);
		if (str[i] != e)
		{
			DestroyStack_Lk(s);//栈用完了得销毁
			return false;
		}
	}
	DestroyStack_Lk(s);//栈用完了得销毁   无论是true还是false，使用完的栈都要销毁
	return true;
}


bool magpath_Stack(int xi,int yi,int xe,int ye)//起点xi,yi  终点xe，ye
{
	int i, j, di, find;
	int k;
	StType st;
	st.top = -1; //栈顶
	
	st.top++;
	st.data[st.top].i = xi;
	st.data[st.top].j = yi;
	st.data[st.top].di = -1;//先将起始位置标记入栈

	mg[xi][yi] = -1;//当前点都进行标记

	while (st.top>-1)//如果不通就会原路返回，如果所有的路都不通就会返回到起点。也就是说只要是栈里有数据，就说明还没回到原点。
	{
		i = st.data[st.top].i;
		j = st.data[st.top].j;
		di = st.data[st.top].di;
		if (i == xe && j == xe) //找到出口了
		{
			for (k = 0; k <= st.top; k++)
			{
				printf("(%d,%d)\n",st.data[k].i, st.data[k].j);//输出路径
			}
			return true;
		}
		find = 0;//还没找到出口
		while (di<4 && find == 0)  //扫描附近可走的点，找到就退出循环，或者没找到也退出循环。
		{
			di++; //加一
			switch (di) //根据di映射坐标
			{
			case(0):i = st.data[st.top].i -1; j = st.data[st.top].j; break;
			case(1):i = st.data[st.top].i; j = st.data[st.top].j +1; break;
			case(2):i = st.data[st.top].i + 1; j = st.data[st.top].j; break;
			case(3):i = st.data[st.top].i; j = st.data[st.top].j - 1; break;
			}
			if (mg[i][j] == 0)find = 1;//找到可以走的点。
		}//找出口
		if (find)//找到出口了
		{
			st.data[st.top].di = di;//保存原栈顶元素的di值，di值以内的都是不能走已经或者走过的点，如果下次退到该点，就不会走老路了。
			
			//入栈
			st.top++;
			st.data[st.top].i = i; st.data[st.top].j = j;//记录出口坐标
			st.data[st.top].di = -1;//来到新的点，di为-1
			
			mg[i][j] = -1;//标记路径
		}
		else   //找遍了都没找到出口，就得退栈
		{
			mg[st.data[st.top].i][st.data[st.top].j] = 0;//抹掉痕迹，允许其他路径通过。
			st.top--;
		}
	}
	return false;//都没找到
}



bool magpath_Qu(int xi, int yi, int xe, int ye)
{
	int i, j, di, find = 0;
	int t;
	Box_qu q;//用来回追路径
	Qu_Type qu;
	qu.front = qu.rear = -1;
	qu.rear++;
	qu.data[qu.rear].i = xi;
	qu.data[qu.rear].j = yi;
	qu.data[qu.rear].pre = -1;
	mg[xi][yi] = -1;
	/*###############################################################*/
	while (qu.front != qu.rear && !find)
	{
		qu.front++;
		i = qu.data[qu.front].i; j = qu.data[qu.front].j;
		if (i == xe && j == ye)
		{
			printf("路径：\n");
			q = qu.data[qu.front];//记录元素的坐标
			while (q.pre != -1)
			{
				printf("(%d,%d)\n",qu.data[q.pre].i, qu.data[q.pre].j);
				q = qu.data[q.pre];//向前追踪
			}
			find = 1;
			return true;
		}
		/************************************************************/
		for (di = 0; di < 4; di++)
		{
			switch (di)
			{
			case(0):i = qu.data[qu.front].i - 1; j = qu.data[qu.front].j; break;
			case(1):i = qu.data[qu.front].i; j = qu.data[qu.front].j+1; break;
			case(2):i = qu.data[qu.front].i+1; j = qu.data[qu.front].j; break;
			case(3):i = qu.data[qu.front].i; j = qu.data[qu.front].j-1; break;
			}
			if (mg[i][j]==0)//如果可走的话
			{
				qu.rear++;
				qu.data[qu.rear].i = i; qu.data[qu.rear].j = j;
				qu.data[qu.rear].pre = qu.front;   //记录前一个下标
				mg[i][j] = -1;
			}
		}
		/************************************************************/
	}
	/*###############################################################*/
	return false;
}







