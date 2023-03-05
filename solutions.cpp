//
// Created by wildcardo on 2023/2/28.
//

#include "solutions.h"

void DeleteValueXLinkList(LinkList &L, ElemType x)
{
    if (L == NULL) return;
    if (L->data == x)
    {
        LNode *pDelete = L;
        L = L->next;
        free(pDelete);
        DeleteValueXLinkList(L, x);
    } else
    {
        DeleteValueXLinkList(L->next, x);
    }
}

void DeleteXLinkList(LinkList &L, ElemType x)
{
    LNode *p = L;
    LNode *pDelete;
    while (p->next != NULL)
    {
        if (p->next->data == x)
        {
            pDelete = p->next;
            p->next = pDelete->next;
            free(pDelete);
        } else
        {
            p = p->next;
        }
    }
}

bool DeleteMinLinkList(LinkList &L)
{
    if (L->next == NULL) return false;
    LNode *p = L;
    LNode *min = p;
    ElemType data = p->next->data;
    while (p->next != NULL)
    {
        if (p->next->data < data)
        {
            data = p->next->data;
            min = p;
        }
        p = p->next;
    }
    LNode *pDelete = min->next;
    min->next = pDelete->next;
    free(pDelete);
    return true;
}

bool ReverseLinkList(LinkList &L)
{
    if (L->next == NULL) return false;
    LNode *pCur = L->next;
    LNode *pAdd = pCur;
    LNode *head = L;
    head->next = NULL;
    while (pCur != NULL)
    {
        pCur = pCur->next;
        pAdd->next = head->next;
        head->next = pAdd;
        pAdd = pCur;
    }
    return true;
}

bool IncrementalLinkList(LinkList &L)
{
    if (L->next == NULL) return false;
    if (L->next->next == NULL) return true;
    LNode *p = L->next->next;
    LNode *q = p;
    L->next->next = NULL;
    while (p != NULL)
    {
        p = p->next;
        LNode *l = L;
        while (l->next != NULL && q->data > l->next->data)
        {
            l = l->next;
        }
        q->next = l->next;
        l->next = q;
        q = p;
    }
    return true;
}

bool DeleteSTLinkList(LinkList &L, ElemType s, ElemType t)
{
    if (L->next == NULL) return false;
    LNode *p = L, *q;
    while (p->next != NULL)
    {
        if (p->next->data >= s && p->next->data <= t)
        {
            q = p->next;
            p->next = p->next->next;
            free(q);
        } else
        {
            p = p->next;
        }
    }
    return true;
}

LNode *FindPublicNodeLinkList(LinkList L1, LinkList L2)
{
    if (L1->next == NULL || L2->next == NULL) return NULL;
    int length1 = LengthLinkList(L1);
    int length2 = LengthLinkList(L2);
    int dist = 0;
    LinkList longList, shortList;
    if (length1 >= length2)
    {
        longList = L1->next;
        shortList = L2->next;
        dist = length1 - length2;
    } else
    {
        longList = L2->next;
        shortList = L1->next;
        dist = length2 - length1;
    }
    while (dist--)
    {
        longList = longList->next;
    }
    while (longList != NULL)
    {
        if (longList == shortList) return longList;
        longList = longList->next;
        shortList = shortList;
    }
    return NULL;
}

bool OutPutIncrementalAndDeleteLinkList(LinkList &L)
{
    if (L->next == NULL) return false;
    LNode *l = L;
    while (l->next != NULL)
    {
        LNode *preMinPos = l;
        LNode *pre = l;
        while (pre->next != NULL)
        {
            if (pre->next->data <= preMinPos->next->data)
            {
                preMinPos = pre;
            }
            pre = pre->next;
        }
        printf("%d\n", preMinPos->next->data);
        LNode *deleteNode = preMinPos->next;
        preMinPos->next = deleteNode->next;
        free(deleteNode);
    }
    printf("delete complete!\n");
    return true;
}

bool DecomposeTwoLinkList(LinkList &A, LinkList &B)
{
    if (A->next == NULL || B->next != NULL) return false; // A must be non-empty, B must be empty
    LNode *headA = A;
    LNode *tailB = B; // point to B's current tail node, start as B's head node
    int index = 1;
    while (headA->next != NULL)
    {
        if (index % 2 == 0)
        {
            tailB->next = headA->next;
            headA->next = headA->next->next;
            tailB = tailB->next;
            tailB->next = NULL;
        } else
        {
            headA = headA->next;
        }
        index++;
    }
    printf("decompose complete!\n");
    return true;
}

bool RemoveDuplicateLinkList(LinkList &L)
{
    if (L->next == NULL) return false; // if list is empty return false
    LNode *p = L->next;
    while (p != NULL)
    {
        if (p->next != NULL && p->next->data == p->data)
        {
            LNode *q = p->next;
            p->next = p->next->next;
            free(q);
        } else
        {
            p = p->next;
        }
    }
    printf("remove success!\n");
    return true;
}
