#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node, * LkList;

void CreatLkList(LkList& L, int n);
void Tranvers_Twd(LkList L);//递归正向遍历
void Tranvers_Bk(LkList L);//递归反向遍历
void DestoryList(LkList& L);

int main()
{
    LkList L;
    CreatLkList(L, 5);
    printf("正向遍历：\n");
    Tranvers_Twd(L);
    printf("反向遍历：\n");
    Tranvers_Bk(L);
    printf("销毁链表：\n");
    DestoryList(L);
	return 0;
}


void CreatLkList(LkList& L,int n)//递归创建不带头结点的单链表
{
    if (n == 0)//终止条件
    {
        L = NULL;
    }
    else
    {
        L = (LkList)malloc(sizeof(Node));
        if (!L)exit(0);

        scanf_s("%d",&(L->data));
        CreatLkList(L->next, n - 1);
    }
}

void Tranvers_Twd(LkList L)//递归正向遍历
{
    if (L == NULL)return;
    printf("%d\n",L->data);
    Tranvers_Twd(L->next);
}
void Tranvers_Bk(LkList L)//递归反向遍历
{
    if (L == NULL)return;
    Tranvers_Bk(L->next);
    printf("%d\n", L->data);
}

void DestoryList(LkList& L)
{
    if (L)
    {
        DestoryList(L->next);
        printf("free：%d\n", L->data);//显示释放过程
        free(L);
        L = NULL;
    }
}


void Tranvers_Bk(LkList L)//递归反向遍历
{
    if (L == NULL)return;
        if (L->next == NULL)return;
            if (L->next->next == NULL)return;
            Tranvers_Bk(L->next->next->next);
            printf("%d\n", L->next->next->data);
        printf("%d\n", L->next->data);
    printf("%d\n", L->data);
}
