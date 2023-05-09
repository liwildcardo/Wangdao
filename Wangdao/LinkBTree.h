#pragma once

#include <cstdlib>
#include <cstdio>
#include "BasicType.h"

// ���ݽṹ����ʽ������
typedef struct LinkBTreeNode
{
	// ��ʽ���������������
	LinkBTreeElemType data;
	// ��ʽ�������������
	LinkBTreeNode *lchild;
	// ��ʽ����������Һ���
	LinkBTreeNode *rchild;
} *LinkBTree;

// ��ʼ��������
bool Init(LinkBTree &T)
{
	T = (LinkBTree)malloc(sizeof(sizeof(LinkBTreeNode)));
	if (T)
	{
		T->lchild = NULL;
		T->rchild = NULL;
		return true;
	}
	return false;
}

// ���ʶ������������
void Visit(LinkBTreeNode *node)
{
	if (node)
	{
		printf("%d", node->data);
	}
}

// �������
void PreOrder(LinkBTree T)
{
	if (T)
	{
		Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

// �������
void InOrder(LinkBTree T)
{
	if (T)
	{
		InOrder(T->lchild);
		Visit(T);
		InOrder(T->rchild);
	}
}

// �������
void PostOrder(LinkBTree T)
{
	if (T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		Visit(T);
	}
}
