//
// Created by wildcardo on 2023/2/28.
//

#ifndef WANGDAO_SOLUTIONS_H
#define WANGDAO_SOLUTIONS_H

#include "datastructures.h"

// 01 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点
void DeleteValueXLinkList(LinkList &L, ElemType x);

// 02 在带头结点的单链表中删除所有值为x的结点（假设不唯一）
void DeleteXLinkList(LinkList &L, ElemType x);

// 04 试编写带头结点的单链表L中删除一个最小值的结点的高效算法（假设最小值唯一）
bool DeleteMinLinkList(LinkList &L);

// 05 试编写带头结点的单链表就地逆置，辅助空间复杂度为O(1)
bool ReverseLinkList(LinkList &L);

// 06 Design an algorithm to make link list in incremental order
bool IncrementalLinkList(LinkList &L);

// 07 Design an algorithm to delete nodes whose data between s and t
bool DeleteSTLinkList(LinkList &L, ElemType s, ElemType t);

// 08 Design an algorithm to find the public node of two link lists
LNode *FindPublicNodeLinkList(LinkList L1, LinkList L2);

// 09 Output the node data in incremental order, and release the space of the nodes
bool OutPutIncrementalAndDeleteLinkList(LinkList &L);

// 10 Decompose a single linked list into two single linked lists, one containing an odd number of nodes, one containing an even number of nodes, with the same relative position
bool DecomposeTwoLinkList(LinkList &A, LinkList &B);

// 12 remove duplicate nodes in an increasing link list
bool RemoveDuplicateLinkList(LinkList &L);

#endif //WANGDAO_SOLUTIONS_H
