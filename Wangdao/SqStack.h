#pragma once

#include "BasicType.h"

constexpr auto SqStackMaxSize = 100;

typedef struct
{
	SqStackElemType data[SqStackMaxSize];
	int top;
} SqStack;

// �ж�ջ�Ƿ�Ϊ��
bool Empty(SqStack S)
{
	return S.top == 0;
}

// �ж�ջ�Ƿ�Ϊ��
bool Full(SqStack S)
{
	return S.top == SqStackMaxSize - 1;
}

// ��ջ
bool Push(SqStack &S, SqStackElemType e)
{
	if (!Full(S))
	{
		S.data[S.top++] = e;
		return true;
	}
	return false;
}

// ��ջ
bool Pop(SqStack &S, SqStackElemType &e)
{
	if (!Empty(S))
	{
		e = S.data[--S.top];
		return true;
	}
	return false;
}

// ��ȡջ��Ԫ��
bool GetTop(SqStack S, SqStackElemType &e)
{
	if (!Empty(S))
	{
		e = S.data[S.top - 1];
		return true;
	}
	return false;
}
