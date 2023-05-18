#pragma once

#include "BasicType.h"

// 顺序循环队列最大长度
constexpr auto SqQueueMaxSize = 100;

// 数据结构：顺序循环队列
typedef struct
{
	SqQueueElemType data[SqQueueMaxSize];
	int front;
	int rear;
} SqQueue;

// 初始化队列
bool Init(SqQueue &Q)
{
	Q.front = 0;
	Q.rear = 0;
}

// 判断队列是否为空
bool Empty(SqQueue Q)
{
	return Q.front == Q.rear;
}

// 判断队列是否为满
bool Full(SqQueue Q)
{
	return Q.rear == (Q.front + 1) % SqQueueMaxSize;
}

// 入队
bool EnQueue(SqQueue &Q, SqQueueElemType e)
{
	if (!Full(Q))
	{
		Q.data[Q.rear++] = e;
		return true;
	}
	return false;
}

// 出队
bool DeQueue(SqQueue &Q, SqQueueElemType &e)
{
	if (!Empty(Q))
	{
		e = Q.data[Q.front++];
		return true;
	}
	return false;
}
