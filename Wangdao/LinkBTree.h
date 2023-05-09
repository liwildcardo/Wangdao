#pragma once

#include <cstdlib>
#include <cstdio>
#include "BasicType.h"

// 数据结构：链式二叉树
typedef struct LinkBTreeNode
{
	// 链式二叉树结点数据域
	LinkBTreeElemType data;
	// 链式二叉树结点左孩子
	LinkBTreeNode *lchild;
	// 链式二叉树结点右孩子
	LinkBTreeNode *rchild;
} *LinkBTree;

// 初始化二叉树
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

// 访问二叉树结点数据
void Visit(LinkBTreeNode *node)
{
	if (node)
	{
		printf("%d", node->data);
	}
}

// 先序遍历
void PreOrder(LinkBTree T)
{
	if (T)
	{
		Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

// 中序遍历
void InOrder(LinkBTree T)
{
	if (T)
	{
		InOrder(T->lchild);
		Visit(T);
		InOrder(T->rchild);
	}
}

// 后序遍历
void PostOrder(LinkBTree T)
{
	if (T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		Visit(T);
	}
}
