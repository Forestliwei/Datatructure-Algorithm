#include <stdio.h>

#define M 6
#define N 7

#define MaxSize 100
typedef int ElemType;

typedef struct {
	int r;
	int c;
	ElemType elem;
}TupNode;

typedef struct {
	int rows;//多少行
	int cols;//多少列
	int nums;//多少个非零元素
	TupNode data[MaxSize];//稀疏矩阵表示
}TSMatrix;

int A[M][N] = {
	{0,0,5,0,0,0,0},
	{0,2,0,0,0,0,0},
	{3,0,0,0,0,0,0},
	{0,0,0,5,0,0,0},
	{0,0,0,0,6,0,0},
	{0,9,0,0,0,7,4},
};

void CreatMat(TSMatrix& t, ElemType* A, int m, int n);
void PrintMat(TSMatrix t);
bool Value(TSMatrix& t, ElemType e, int i, int j);
bool Assign(TSMatrix& t, ElemType& e, int i, int j);
int main()
{
	TSMatrix t;
	ElemType e;

	CreatMat(t,&A[0][0],M,N);
	PrintMat(t);
	Value(t, 12, 2, 3);
	printf("\n");
	PrintMat(t);
	Assign(t, e, 3, 4);
	printf("\n%d\n",e);

	return 0;
}

void CreatMat(TSMatrix &t, ElemType *A,int m,int n)//
{
	int i, j; 
	t.rows = m; t.cols = n; t.nums = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (*(A + i * n + j) != 0)//A[i][j]
			{
				t.data[t.nums].r = i;//记录行
				t.data[t.nums].c = j;//记录列
				t.data[t.nums].elem = *(A + i * n + j);//复制
				t.nums++;//数量加一
			}
		}
	}
}
void PrintMat(TSMatrix t)
{
	int k = 0;
	if (t.nums <= 0)return;
	while (k < t.nums)
	{
		printf("(%d,%d):%d\n", t.data[k].r, t.data[k].c, t.data[k].elem);//调试信息
		k++;//数量加一
	}
}

bool Value(TSMatrix& t, ElemType e, int i, int j)//在矩阵的(i,j)位置元素改为e,注意如果e为0就不要乱插了
{
	int k=0,k1;
	//bool flag = false;
	if (i > t.rows || j > t.cols)//有效性检查
		return false;//要操作的元素不在范围内就返回false

	//for (k = 0; k < t.nums; k++)
	//{
	//	if (t.data[k].c == i && t.data[k].r == j)//查到该位置不为0的值
	//	{
	//		t.data[k].elem = e;//直接修改
	//		flag = true;
	//		break;
	//	}
	//}
	//if (!flag)//没有查到
	//{
	//	for (k1 = t.nums - 1; k1 >= k; k1--)//往后移一位
	//	{
	//		t.data[k1 + 1].r = t.data[k1].r;
	//		t.data[k1 + 1].c = t.data[k1].c;
	//		t.data[k1 + 1].elem = t.data[k1].elem;
	//	}
	//	t.data[k].r = i;
	//	t.data[k].c = j;
	//	t.data[k].elem = e;
	//	t.nums++;
	//}

	while (k < t.nums && t.data[k].r < i)k++;//先找到那一行（CreatMat函数是行优先，因此这里查找也应该是行优先）
	while (k < t.nums && t.data[k].r == i && t.data[k].c<j)k++;//
	if (t.data[k].r == i && t.data[k].c == j)//存在这个元素
	{
		t.data[k].elem = e;
	}
	else//不存在的话就插入进去
	{
		for (k1 = t.nums-1; k1 >= k; k1--)//往后移一位
		{
			t.data[k1+1].c = t.data[k1].c;
			t.data[k1+1].r = t.data[k1].r;
			t.data[k1+1].elem = t.data[k1].elem;
		}
		t.data[k].r = i;
		t.data[k].c = j;
		t.data[k].elem = e;
		t.nums++;
	}
	return true;
}


bool Assign(TSMatrix& t, ElemType& e, int i, int j)//将制定位置的元素值赋给变量e
{
	int k = 0;
	if (i >= t.rows || j >= t.cols)return false;

	while (k < t.nums && t.data[k].r < i)k++;//先找到那一行（CreatMat函数是行优先，因此这里查找也应该是行优先）
	while (k < t.nums && t.data[k].r == i && t.data[k].c < j)k++;//
	if (t.data[k].r == i && t.data[k].c == j)
		e = t.data[k].elem;
	else
		e = 0;
	return true;
}
