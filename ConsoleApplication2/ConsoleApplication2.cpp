#include "mystr.h"
#include <stdlib.h>
int main()
{
	SqString s, t;
	char s1[] = "aaabaaababababab";
	char s2[] = "aaab";
	printf("%d\n", StrAssign(s, s1));//返回长度
	printf("%d\n",StrAssign(t, s2));//返回长度

	//printf("%d\n", BF(s,t));//返回匹配的s的下标
	printf("%d\n", KMP(s,t));//返回匹配的s的下标
	return 0;
}

