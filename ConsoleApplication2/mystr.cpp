#include "mystr.h"

int Strcmp(SqString s, SqString t)
{
	int i, comlen;
	if (s.Length < t.Length)comlen = s.Length;
	else comlen = t.Length;

	for (i = 0; i < comlen; i++)//�ȱȽ���ͬ���ȵĲ���
	{
		if (s.data[i] > t.data[i])return 1;
		else if (s.data[i] < t.data[i]) return -1;
	}
	if (s.Length == t.Length)return 0;
	else if (s.Length > t.Length)return 1;
	else return -1;
}

int StrAssign(SqString &s,char cstr[])//���ִ����䵽SqString��
{
	s.Length = 0;
	while ((s.Length < MaxSize) && (cstr[s.Length] != '\0'))
	{
		s.data[s.Length] = cstr[s.Length];
		s.Length++;
	}
	return s.Length;
}

int BF(SqString s, SqString t)
{
	int i = 0, j = 0;
	while (i < s.Length && j < t.Length)
	{
		if (s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;//���
			j = 0;
		}
	}
	if (j >= t.Length)
	{
		return (i - t.Length);//�״�
	}
	else
		return -1;
}

void GereNext(SqString t,int *next)
{
	int j,k;
	j = 0; k = -1; next[0] = -1;//k����ɨ��Ա�ǰ�漸��Ԫ���Ƿ���jɨ���Ԫ����ͬ
	while (j < t.Length - 1)
	{
		if (k == -1 || t.data[j]==t.data[k])//��k=-1��ʱ��˵����ͷ�ˣ�j����ǰ���ˡ�
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];//����Ϊʲô����k=-1�أ���Ϊk=-1��k=next[k]��һ���ġ�
	}
} 

int KMP(SqString s, SqString t)
{
	int i=0, j=0;
	int times = 0;
	int next[MaxSize];
	GereNext(t,next);
	while (i < s.Length && j<t.Length)
	{
		if (j == -1 || s.data[i] == t.data[j])//-1������iǰ��
		{
			i++;
			j++;
		}
		else
			j = next[j];
		times++;
	}
	printf("times��%d\n", times);//��ӡƥ�������ʱ�临�Ӷȣ�
	if (j >= t.Length)
		return (i - t.Length);//ƥ��ɹ��ͷ���s���±�
	else
		return -1;//ƥ��ʧ�ܷ���-1
}