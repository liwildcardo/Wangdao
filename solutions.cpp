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

}
