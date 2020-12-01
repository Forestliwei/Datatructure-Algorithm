#include <stdio.h>

#define NUM 8


int A[NUM] = { 102,102,32,44,202,32,61,56 };

int fun1(int n);//首递归
int fun2(int n, int pdt);//尾递归
int Fibonacci1(int n);
int Fibonacci2(int n, int va1, int va2);
int F(int A[], int i);
int main()
{
    printf("fun1: 10!=%d\n",fun1(10));
    printf("fun2: 10!=%d\n", fun2(10,1));
    printf("Fibonacci: %d\n", Fibonacci1(6));
    printf("Fibonacci: %d\n", Fibonacci2(6,0,1));
    printf("F: %d\n", F(A, NUM - 1));
    return 0;
}
int fun1(int n)//首递归
{
    if (n == 1)
        return n;
    else
        return n*fun1(n-1);
}
int fun2(int n, int pdt)//尾递归
{
    if (n == 1)return pdt;
    else
        return fun2(n - 1, n*pdt);
}

int Fibonacci1(int n)
{
    if (n == 1 || n == 2)return 1;
    else
        return (Fibonacci1(n - 1) + Fibonacci1(n - 2));
}
int Fibonacci2(int n,int va1,int va2)//n来控制出口，va1和va2来进行计算
{
    if (n == 0)return (va1);
    else
        return (Fibonacci2(n-1,va2,va1+va2));
}

int min(int a,int b)
{
    if (a < b)return a;
    else return b;
}

int F(int A[], int i)//使用递归求数组A[]中A[0]~A[i]的最小值
{
    if (i == 0)return A[0];
    else
    {
        return min(F(A, i - 1), A[i]);
    }
}


