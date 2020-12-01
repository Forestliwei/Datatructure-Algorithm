#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MaxSize 100

int mg[10][10] = {                         //迷宫
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
char mg_graph[10][10];

typedef struct {
	int i;
	int j;
}Box;

typedef struct {
	Box data[MaxSize];
	int length;
}PathType;  //路径信息

void mgpath(int xi, int yi, int xe, int ye, PathType& path);
void Show();

PathType path;
int main()
{
	path.length = 0;
	mgpath(1,1,8,8,path);
}

void mgpath(int xi,int yi,int xe,int ye, PathType &path)
{
	int di, k, i, j;
	int va=0;
	if (xi == xe && yi == ye)//找到出口
	{
		path.data[path.length].i = xi;
		path.data[path.length].j = yi;
		path.length++;
		printf("迷宫路径如下：\n");
		for (k = 0; k < path.length; k++)//输出路径
		{
			printf("\t(%d,%d)", path.data[k].i, path.data[k].j);
			if ((k + 1) % 10 == 0)
			{
				printf("\n");
			}
		}
		printf("\n输入任意值继续\n");
		scanf_s("%d", &va);
	}
	else
	{
		if (mg[xi][yi] == 0)
		{
			di = 0;
			while (di < 4)
			{
				switch (di)
				{
				case 0:i = xi - 1; j = yi; break;
				case 1:i = xi; j = yi + 1; break;
				case 2:i = xi + 1; j = yi; break;
				case 3:i = xi; j = yi - 1; break;
				}
				path.data[path.length].i = xi;
				path.data[path.length].j = yi;
				printf("(%d,%d)\n",xi,yi);
				path.length++;
				mg[xi][yi] = -1;
				Sleep(500);
				system("cls");
				Show();//
				mgpath(i, j, xe, ye, path);//进去搜索位置并刺探 xi == xe && yi == ye 条件
				path.length--;//为什么要减？
				mg[xi][yi] = 0;
				printf("di=%d\n", di);
				Sleep(500);
				system("cls");
				Show();//
				di++;
			}
		}
	}//递归体
}

void Show()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (mg[i][j] == 0)
			{
				printf("Ｏ");
			}
			else if(mg[i][j] == 1)
			{
				printf("●");
			}
			else if (mg[i][j] == -1)
			{
				printf("☆");
			}
		}
		printf("\n");
	}
	printf("\n");
}



void f()
{
	//由外到内
	f();//递归体
	//由内到外
}
