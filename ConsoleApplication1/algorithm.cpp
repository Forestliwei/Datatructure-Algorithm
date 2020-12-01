#include "algorithm.h"


int mg[10][10] = {                         //�Թ�
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
//�ж��ַ����Ƿ��ǶԳƴ�
bool symmetry(ElemeType_LStk str[])
{
	LkStack s;//����һ��ջ
	int i;
	ElemeType_LStk e;
	InitStack_Lk(s);//��ʼ��һ��ջ
	for (i = 0; str[i]!='\0'; i++)
	{
		Push_Lk(s, str[i]);//��ջ
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		Pop_Lk(s, e);
		if (str[i] != e)
		{
			DestroyStack_Lk(s);//ջ�����˵�����
			return false;
		}
	}
	DestroyStack_Lk(s);//ջ�����˵�����   ������true����false��ʹ�����ջ��Ҫ����
	return true;
}


bool magpath_Stack(int xi,int yi,int xe,int ye)//���xi,yi  �յ�xe��ye
{
	int i, j, di, find;
	int k;
	StType st;
	st.top = -1; //ջ��
	
	st.top++;
	st.data[st.top].i = xi;
	st.data[st.top].j = yi;
	st.data[st.top].di = -1;//�Ƚ���ʼλ�ñ����ջ

	mg[xi][yi] = -1;//��ǰ�㶼���б��

	while (st.top>-1)//�����ͨ�ͻ�ԭ·���أ�������е�·����ͨ�ͻ᷵�ص���㡣Ҳ����˵ֻҪ��ջ�������ݣ���˵����û�ص�ԭ�㡣
	{
		i = st.data[st.top].i;
		j = st.data[st.top].j;
		di = st.data[st.top].di;
		if (i == xe && j == xe) //�ҵ�������
		{
			for (k = 0; k <= st.top; k++)
			{
				printf("(%d,%d)\n",st.data[k].i, st.data[k].j);//���·��
			}
			return true;
		}
		find = 0;//��û�ҵ�����
		while (di<4 && find == 0)  //ɨ�踽�����ߵĵ㣬�ҵ����˳�ѭ��������û�ҵ�Ҳ�˳�ѭ����
		{
			di++; //��һ
			switch (di) //����diӳ������
			{
			case(0):i = st.data[st.top].i -1; j = st.data[st.top].j; break;
			case(1):i = st.data[st.top].i; j = st.data[st.top].j +1; break;
			case(2):i = st.data[st.top].i + 1; j = st.data[st.top].j; break;
			case(3):i = st.data[st.top].i; j = st.data[st.top].j - 1; break;
			}
			if (mg[i][j] == 0)find = 1;//�ҵ������ߵĵ㡣
		}//�ҳ���
		if (find)//�ҵ�������
		{
			st.data[st.top].di = di;//����ԭջ��Ԫ�ص�diֵ��diֵ���ڵĶ��ǲ������Ѿ������߹��ĵ㣬����´��˵��õ㣬�Ͳ�������·�ˡ�
			
			//��ջ
			st.top++;
			st.data[st.top].i = i; st.data[st.top].j = j;//��¼��������
			st.data[st.top].di = -1;//�����µĵ㣬diΪ-1
			
			mg[i][j] = -1;//���·��
		}
		else   //�ұ��˶�û�ҵ����ڣ��͵���ջ
		{
			mg[st.data[st.top].i][st.data[st.top].j] = 0;//Ĩ���ۼ�����������·��ͨ����
			st.top--;
		}
	}
	return false;//��û�ҵ�
}



bool magpath_Qu(int xi, int yi, int xe, int ye)
{
	int i, j, di, find = 0;
	int t;
	Box_qu q;//������׷·��
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
			printf("·����\n");
			q = qu.data[qu.front];//��¼Ԫ�ص�����
			while (q.pre != -1)
			{
				printf("(%d,%d)\n",qu.data[q.pre].i, qu.data[q.pre].j);
				q = qu.data[q.pre];//��ǰ׷��
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
			if (mg[i][j]==0)//������ߵĻ�
			{
				qu.rear++;
				qu.data[qu.rear].i = i; qu.data[qu.rear].j = j;
				qu.data[qu.rear].pre = qu.front;   //��¼ǰһ���±�
				mg[i][j] = -1;
			}
		}
		/************************************************************/
	}
	/*###############################################################*/
	return false;
}







