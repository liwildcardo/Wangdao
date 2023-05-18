#pragma once

#include "BasicType.h"

// ˳��ѭ��������󳤶�
constexpr auto SqQueueMaxSize = 100;

// ���ݽṹ��˳��ѭ������
typedef struct
{
	SqQueueElemType data[SqQueueMaxSize];
	int front;
	int rear;
} SqQueue;

// ��ʼ������
bool Init(SqQueue &Q)
{
	Q.front = 0;
	Q.rear = 0;
}

// �ж϶����Ƿ�Ϊ��
bool Empty(SqQueue Q)
{
	return Q.front == Q.rear;
}

// �ж϶����Ƿ�Ϊ��
bool Full(SqQueue Q)
{
	return Q.rear == (Q.front + 1) % SqQueueMaxSize;
}

// ���
bool EnQueue(SqQueue &Q, SqQueueElemType e)
{
	if (!Full(Q))
	{
		Q.data[Q.rear++] = e;
		return true;
	}
	return false;
}

// ����
bool DeQueue(SqQueue &Q, SqQueueElemType &e)
{
	if (!Empty(Q))
	{
		e = Q.data[Q.front++];
		return true;
	}
	return false;
}
