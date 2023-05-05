#pragma once

#include <cstdlib>
#include "BasicType.h"

// 数据结构：链栈
typedef struct LinkStackNode
{
	// 链栈结点数据域
	LinkStackElemType data;
	// 链栈结点指针域
	struct LinkStackNode *next;
} LinkStackNode, *LinkStack;

// 初始化链栈
bool Init(LinkStack &S)
{
	S = (LinkStack)malloc(sizeof(LinkStackNode));
	if (S)
	{
		S->next = NULL;
		return true;
	}
	return false;
}

// 判断链栈是否为空
bool Empty(LinkStack S)
{
	if (S)
		return S->next == NULL;
	return false;
}

// 入栈
bool Push(LinkStack &S, LinkStackElemType e)
{
	if (S)
	{
		auto *p = (LinkStackNode *)malloc(sizeof(LinkStackNode));
		if (p)
		{
			p->data = e;
			p->next = S->next;
			S->next = p;
			return true;
		}
	}
	return false;
}

// 出栈
bool Pop(LinkStack &S, LinkStackElemType &e)
{
	if (!Empty(S))
	{
		auto *p = S->next;
		e = p->data;
		S->next = p->next;
		free(p);
		return true;
	}
	return false;
}

// 获取栈顶元素
bool GetTop(LinkStack S, LinkStackElemType &e)
{
	if (!Empty(S))
	{
		e = S->next->data;
		return true;
	}
	return false;
}
