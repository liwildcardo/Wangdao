//
// Created by wildcardo on 2023/2/28.
//

#ifndef WANGDAO_SOLUTIONS_H
#define WANGDAO_SOLUTIONS_H

#include "datastructures.h"

// p38-01 Design an algorithm to delete all nodes value 'x' in a single link list L without head node
void DeleteValueXLinkList(LinkList &L, ElemType x);

// p38-02 Delete all nodes value 'x' in a single link list L with head node
void DeleteXLinkList(LinkList &L, ElemType x);

// p38-04 Design an algorithm to delete the minimum node in single link list with head node(assume only one minimum node)
bool DeleteMinLinkList(LinkList &L);

// p38-05 Design an algorithm to reverse the single link list, whose space complexity should be O(1)
bool ReverseLinkList(LinkList &L);

// p38-06 Design an algorithm to make link list in incremental order
bool IncrementalLinkList(LinkList &L);

// p38-07 Design an algorithm to delete nodes whose data between s and t
bool DeleteSTLinkList(LinkList &L, ElemType s, ElemType t);

// p38-08 Design an algorithm to find the public node of two link lists
LNode *FindPublicNodeLinkList(LinkList L1, LinkList L2);

// p38-09 Output the node data in incremental order, and release the space of the nodes
bool OutPutIncrementalAndDeleteLinkList(LinkList &L);

// p38-10 Decompose a single linked list into two single linked lists, one containing an odd number of nodes,
// one containing an even number of nodes, with the same relative position
bool DecomposeTwoLinkList(LinkList &A, LinkList &B);

// p38-12 Remove duplicate nodes in an increasing link list
bool RemoveDuplicateLinkList(LinkList &L);

// p67-04 Design an algorithm to determine whether the data of the elems are central symmetric
bool IsCentralSymmetricLinkList(LinkList &L);

#endif //WANGDAO_SOLUTIONS_H
