#include "mystr.h"

int Strcmp(SqString s, SqString t)
{
	int i, comlen;
	if (s.Length < t.Length)comlen = s.Length;
	else comlen = t.Length;

	for (i = 0; i < comlen; i++)//先比较相同长度的部分
	{
		if (s.data[i] > t.data[i])return 1;
		else if (s.data[i] < t.data[i]) return -1;
	}
	if (s.Length == t.Length)return 0;
	else if (s.Length > t.Length)return 1;
	else return -1;
}

int StrAssign(SqString &s,char cstr[])//将字串分配到SqString中
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
			i = i - j + 1;//妙极了
			j = 0;
		}
	}
	if (j >= t.Length)
	{
		return (i - t.Length);//易错
	}
	else
		return -1;
}

void GereNext(SqString t,int *next)
{
	int j,k;
	j = 0; k = -1; next[0] = -1;//k用来扫描对比前面几个元素是否与j扫描的元素相同
	while (j < t.Length - 1)
	{
		if (k == -1 || t.data[j]==t.data[k])//当k=-1的时候说明到头了，j该往前走了。
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];//这里为什么不是k=-1呢？因为k=-1和k=next[k]是一样的。
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
		if (j == -1 || s.data[i] == t.data[j])//-1用来让i前进
		{
			i++;
			j++;
		}
		else
			j = next[j];
		times++;
	}
	printf("times：%d\n", times);//打印匹配次数（时间复杂度）
	if (j >= t.Length)
		return (i - t.Length);//匹配成功就返回s的下标
	else
		return -1;//匹配失败返回-1
}