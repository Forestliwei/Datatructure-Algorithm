#include <iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node* lchild, * rchild;
}BTNode;

void CreatBTNode(BTNode*& tree,char* str);//括号表示法传递二叉树
void DestroyBT(BTNode*& tree);
BTNode* FindNode(BTNode* tree, ElemType x);
BTNode* LchildNode(BTNode* p);
BTNode* RchildNode(BTNode* p);
int BTNodeDepth(BTNode* tree);
void DispBTNode(BTNode* tree);

void PreOrder(BTNode* tree);//先序访问
void InOrder(BTNode* tree);//中序访问
void PostOrder(BTNode* tree);//后序遍历
void LevelOrder(BTNode* tree);

int Nodes(BTNode* tree);//求树的节点个数
int LeafNodes(BTNode* tree);
void Copy(BTNode* b, BTNode* &t);//把a复制到b

void AllPath(BTNode* b);//从根节点到每个叶子节点的逆路径

int main()
{
    char str[] = {12 , '(' , 22 , '(' , 81 , ',' , 3 , ')' , ',' , 32 , ')' , '\0' };
    BTNode* Tree; BTNode* Tree2;
    BTNode *p;
    CreatBTNode(Tree,str);
    cout <<"树深度"<< BTNodeDepth(Tree)<<endl;
    DispBTNode(Tree);
    p = FindNode(Tree,22);
    cout << "\n节点" << p->data << "的左孩子为" << LchildNode(p)->data << endl;
    cout << "节点" << p->data << "的右孩子为" << RchildNode(p)->data << endl;
    
    cout << "前序遍历："<<endl;
    PreOrder(Tree);
    cout << "中序遍历：" << endl;
    InOrder(Tree);
    cout << "后序遍历：" << endl;
    PostOrder(Tree);
    cout << "层次遍历：" << endl;
    LevelOrder(Tree);

    cout << "节点个数" << Nodes(Tree) << endl;
    cout << "叶子个数" << LeafNodes(Tree) << endl;

    cout << "复制节点"<<endl;
    Copy(Tree, Tree2);
    DispBTNode(Tree2);

    cout << "\nALLPath(Tree2)" << endl;
    AllPath(Tree2);

    cout << "\n销毁树:" << endl;
    DestroyBT(Tree);
    cout << BTNodeDepth(Tree) << endl;
    return 0;
}

void CreatBTNode(BTNode* &tree,char* str)//括号表示法传递二叉树
{
    BTNode* St[MaxSize], * p=NULL;//这里p指针要初始化一下
    int top = -1, k, j = 0;
    char ch;
    tree = NULL;
    ch = str[j];
    while (ch != '\0')
    {
        switch (ch)
        {
        case('('):top++; St[top] = p; k = 1; break;//进栈
        case(')'):top--; break;//出栈
        case(','):k = 2; break;
        default://遇到节点
            p = (BTNode*)malloc(sizeof(BTNode));
            if (!p)exit(0);

            p->data = ch; p->lchild = p->rchild = NULL;//赋值
            if (tree == NULL)tree = p;//树根
            else
            {
                switch (k)
                {
                case(1):St[top]->lchild = p; break;
                case(2):St[top]->rchild = p; break;
                }
            }
        }
        j++; ch = str[j];
    }
}

void DestroyBT(BTNode* &tree)
{
    if (tree == NULL)return;
    else
    {
        DestroyBT(tree->lchild);
        DestroyBT(tree->rchild);
        free(tree);//为什么要放这里?
    }
    tree = NULL;
}

BTNode* FindNode(BTNode *tree, ElemType x)
{
    BTNode* p;
    if (tree == NULL)return NULL;//递归结束条件1
    else if (tree->data == x)//递归结束条件2
    {
        return tree;
    }else
    {
        p = FindNode(tree->lchild, x);//之所以用一个p,是因为还要返回第二个孩子。
        if (p != NULL)return p;
        else return FindNode(tree->rchild, x);
    }
}

BTNode* LchildNode(BTNode* p)
{
    return p->lchild;
}
BTNode* RchildNode(BTNode* p)
{
    return p->rchild;
}

int BTNodeDepth(BTNode* tree)
{
    int lchilddep, rchiledep;
    if (tree == NULL)return 0;
    else
    {
        lchilddep = BTNodeDepth(tree->lchild);
        rchiledep = BTNodeDepth(tree->rchild);
        return (lchilddep > rchiledep) ? (lchilddep + 1 ): (rchiledep+1);
    }
}

void DispBTNode(BTNode* tree)
{
    if (tree == NULL)return;
    else
    {
        cout << tree->data;
        if (tree->lchild != NULL || tree->rchild != NULL)
        {
            cout << '(';
            DispBTNode(tree->lchild);
            if(tree->rchild != NULL)cout << ',';
            DispBTNode(tree->rchild);
            cout << ')';
        }
    }
}

void PreOrder(BTNode* tree)//先序访问
{
    if (tree != NULL)
    {
        cout << tree->data << endl;
        PreOrder(tree->lchild);
        PreOrder(tree->rchild);
    }
}

void InOrder(BTNode* tree)//中序访问
{
    if (tree != NULL)
    {
        InOrder(tree->lchild);
        cout << tree->data << endl;
        InOrder(tree->rchild);
    }
}

void PostOrder(BTNode* tree)//后序遍历
{
    if (tree != NULL)
    {
        InOrder(tree->lchild);
        InOrder(tree->rchild);
        cout << tree->data<<endl;
    }
}

void LevelOrder(BTNode* tree)
{
    BTNode* p;
    BTNode* qu[MaxSize];
    int front, rear;
    front = rear = 0;
    rear++;
    qu[rear] = tree;//入队
    while (front != rear)
    {
        front = (front + 1) % MaxSize;//环形队列
        p = qu[front];
        cout << p->data << endl;
        if (p->lchild != NULL)
        {
            rear = (rear + 1) % MaxSize;
            qu[rear] = p->lchild;//入队
        }
        if (p->rchild != NULL)
        {
            rear = (rear + 1) % MaxSize;
            qu[rear] = p->rchild;//入队
        }
    }
}

int Nodes(BTNode* tree)//求树的节点个数
{
    if (tree == NULL)return 0;
    else
    {
        return (Nodes(tree->lchild)+ Nodes(tree->rchild)+1);
    }
}

int LeafNodes(BTNode* tree)
{
    if (tree == NULL)return 0;//递归结束条件1
    else if (tree->lchild == NULL && tree->rchild == NULL)return 1;//递归结束条件2
    else
    {
        return (LeafNodes(tree->lchild) + LeafNodes(tree->rchild));
    }
}

void Copy(BTNode* b, BTNode* &t)//把a复制到b
{
    if (b == NULL)t = NULL;
    else
    {
        t = (BTNode*)malloc(sizeof(BTNode));
        t->data = b->data;
        Copy(b->lchild, t->lchild);
        Copy(b->rchild, t->rchild);
    }
}

void Swap(BTNode* b, BTNode* &t)//交换b的左右子树，复制到t
{
    if (b == NULL)t = NULL;
    else
    {
        t = (BTNode*)malloc(sizeof(BTNode));
        t->data = b->data;
        Swap(b->lchild, t->rchild);
        Swap(b->rchild, t->lchild);
    }
}

int l;//那是L的小写
int Level(BTNode* b, ElemType x, int h)//h初始传入的值应该为1
{
    if (b == NULL)return 0;
    else if (b->data == x)return h;
    else
    {
        l = Level(b->lchild, x, h + 1);
        if (l == 0)
            return Level(b->rchild, x, h + 1);
        else return l;
    }
}


void AllPath(BTNode* b)//类似队列求解迷宫问题
{
    struct snode {
        BTNode* node;
        int parent;
    }qu[MaxSize];
    BTNode* q;
    int front,rear,p;
    front = rear = -1;
    rear++;
    qu[rear].node = b;//入队
    qu[rear].parent = -1;
    while (front != rear)
    {
        front++;
        q = qu[front].node;//出队一个元素
        if (q->lchild == NULL && q->rchild == NULL)
        {
            p = front;
            while (qu[p].parent != -1)
            {
                cout << qu[p].node->data << endl;
                p = qu[p].parent;
            }
            cout << qu[p].node->data << endl;
        }
        if (q->lchild != NULL)
        {
            rear++;
            qu[rear].node = q->lchild;
            qu[rear].parent = front;
        }
        if (q->rchild != NULL)
        {
            rear++;
            qu[rear].node = q->rchild;
            qu[rear].parent = front;
        }
    }
}


