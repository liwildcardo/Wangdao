#pragma once

#include <cstdlib>
#include "BasicType.h"

// ��ʽ���н�㶨��
typedef struct LinkQueueNode
{
	// ��ʽ���н��������
	LinkQueueElemType data;
	// ��ʽ���н��ָ����
	LinkQueueNode *next;
} LinkQueueNode;

// ���ݽṹ����ʽ����
typedef struct
{
	// ��ʽ����ͷָ��
	LinkQueueNode *front;
	// ��ʽ����βָ��
	LinkQueueNode *rear;
} *LinkQueue;

// ��ʼ����ʽ����
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

// �ж϶����Ƿ�Ϊ��
bool Empty(LinkQueue Q)
{
	if (Q)
	{
		return Q->front == Q->rear;
	}
	return false;
}

// ���
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

// ����
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
