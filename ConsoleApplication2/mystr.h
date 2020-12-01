#pragma once

#ifndef _INC_MYSTR // include guard for 3rd party interop
#define _INC_MYSTR
#include <stdio.h>

#define MaxSize 100

typedef struct {
	char data[MaxSize];
	int Length;
}SqString;

int Strcmp(SqString s, SqString t);
int StrAssign(SqString& s, char cstr[]);
int BF(SqString s, SqString t);

void GereNext(SqString t, int* next);
int KMP(SqString s, SqString t);
#endif
