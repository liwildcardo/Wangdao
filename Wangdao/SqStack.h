#pragma once

#include "BasicType.h"

constexpr auto SqStackMaxSize = 100;

typedef struct
{
	SqStackElemType data[SqStackMaxSize];
	int top;
} SqStack;

// 判断栈是否为空
bool Empty(SqStack S)
{
	return S.top == 0;
}

// 判断栈是否为满
bool Full(SqStack S)
{
	return S.top == SqStackMaxSize - 1;
}

// 入栈
bool Push(SqStack &S, SqStackElemType e)
{
	if (!Full(S))
	{
		S.data[S.top++] = e;
		return true;
	}
	return false;
}

// 出栈
bool Pop(SqStack &S, SqStackElemType &e)
{
	if (!Empty(S))
	{
		e = S.data[--S.top];
		return true;
	}
	return false;
}

// 获取栈顶元素
bool GetTop(SqStack S, SqStackElemType &e)
{
	if (!Empty(S))
	{
		e = S.data[S.top - 1];
		return true;
	}
	return false;
}
