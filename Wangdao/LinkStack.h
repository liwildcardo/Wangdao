#pragma once

#include <cstdlib>
#include "BasicType.h"

// ���ݽṹ����ջ
typedef struct LinkStackNode
{
	// ��ջ���������
	LinkStackElemType data;
	// ��ջ���ָ����
	struct LinkStackNode *next;
} LinkStackNode, *LinkStack;

// ��ʼ����ջ
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

// �ж���ջ�Ƿ�Ϊ��
bool Empty(LinkStack S)
{
	if (S)
		return S->next == NULL;
	return false;
}

// ��ջ
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

// ��ջ
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

// ��ȡջ��Ԫ��
bool GetTop(LinkStack S, LinkStackElemType &e)
{
	if (!Empty(S))
	{
		e = S->next->data;
		return true;
	}
	return false;
}
