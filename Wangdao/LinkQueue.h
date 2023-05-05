#pragma once

#include <cstdlib>
#include "BasicType.h"

// 链式队列结点定义
typedef struct LinkQueueNode
{
	// 链式队列结点数据域
	LinkQueueElemType data;
	// 链式队列结点指针域
	LinkQueueNode *next;
} LinkQueueNode;

// 数据结构：链式队列
typedef struct
{
	// 链式队列头指针
	LinkQueueNode *front;
	// 链式队列尾指针
	LinkQueueNode *rear;
} *LinkQueue;

// 初始化链式队列
bool Init(LinkQueue &Q)
{
	Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (Q->front)
	{
		Q->front->next = NULL;
		Q->rear = Q->front;
		return true;
	}
	return false;
}

// 判断队列是否为空
bool Empty(LinkQueue Q)
{
	if (Q)
	{
		return Q->front == Q->rear;
	}
	return false;
}

// 入队
bool EnQueue(LinkQueue &Q, LinkQueueElemType e)
{
	if (Q)
	{
		auto *p = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
		if (p)
		{
			p->data = e;
			p->next = NULL;
			Q->rear->next = p;
			return true;
		}
	}
	return false;
}

// 出队
bool DeQueue(LinkQueue &Q, LinkQueueElemType &e)
{
	if (!Empty(Q))
	{
		auto *p = Q->front->next;
		e = p->data;
		Q->front = p->next;
		if (Q->rear == p) Q->rear = Q->front;
		free(p);
		return true;
	}
	return false;
}
