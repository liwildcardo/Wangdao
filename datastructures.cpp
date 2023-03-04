//
// Created by wildcardo on 2023/2/26.
//

#include "datastructures.h"

void InitSqList(SqList &L)
{
    for (ElemType i: L.data)
        i = 0;
    L.length = 0;
}

bool EmptySqList(SqList L)
{
    return L.length == 0;
}

bool FullSqList(SqList L)
{
    return L.length == MaxSize;
}

bool AddElemSqList(SqList &L, ElemType x)
{
    if (FullSqList(L)) return false;
    L.data[L.length++] = x;
    return true;
}

bool InsertElemSqList(SqList &L, int pos, ElemType x)
{
    if (FullSqList(L) || pos > L.length + 1 || pos < 1) return false;
    for (int i = L.length; i > pos - 1; i--)
    {
        L.data[i] = L.data[i - 1];
    }
    L.data[pos - 1] = x;
    L.length++;
    return true;
}

bool DeleteElemSqList(SqList &L, int pos, ElemType &x)
{
    if (EmptySqList(L)) return false;
    x = L.data[pos - 1];
    for (int i = pos - 1; i < L.length - 1; i++)
    {
        L.data[i] = L.data[i + 1];
    }
    L.length--;
    return true;
}

int LocateElemSqList(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e) return i + 1;
    }
    return 0;
}

bool InitSeqList(SeqList &L, int maxSize)
{
    if (maxSize <= 0) return false;
    L.data = (ElemType *) malloc(sizeof(ElemType) * maxSize);
    if (L.data == NULL) return false;
    L.length = 0;
    L.maxSize = maxSize;
    return true;
}

bool EmptySeqList(SeqList L)
{
    return L.length == 0;
}

bool FullSeqList(SeqList L)
{
    return L.length == L.maxSize;
}

bool AddLengthSeqList(SeqList &L, int length)
{
    if (length <= 0) return false;
    ElemType *oldData = L.data;
    ElemType *newData = (ElemType *) malloc(sizeof(ElemType) * (L.maxSize + length));
    if (newData == NULL) return false;
    for (int i = 0; i < L.length; i++) newData[i] = oldData[i];
    L.data = newData;
    L.maxSize += length;
    free(oldData);
    return true;
}

bool AddElemSeqList(SeqList &L, ElemType x)
{
    if (FullSeqList(L)) AddLengthSeqList(L, 1);
    L.data[L.length++] = x;
    return true;
}

bool InsertElemSeqList(SeqList &L, int pos, ElemType x)
{
    if (pos < 1 || pos > L.length + 1) return false;
    if (FullSeqList(L)) AddLengthSeqList(L, 1);
    for (int i = L.length - 1; i >= pos - 1; i--)
    {
        L.data[i + 1] = L.data[i];
    }
    L.data[pos - 1] = x;
    L.length++;
    return true;
}

bool DeleteElemSeqList(SeqList &L, int pos, ElemType &x)
{
    if (EmptySeqList(L) || pos < 1 || pos > L.length) return false;
    for (int i = pos; i < L.length; i++)
    {
        L.data[i - 1] = L.data[i];
    }
    L.length--;
    return true;
}

int LocateElemSeqList(SeqList &L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e) return i + 1;
    }
    return 0;
}

bool InitLinkList(LinkList &L)
{
    L = (LinkList) malloc(sizeof(LNode));
    if (L == NULL) return false;
    L->next = NULL;
    return true;
}

bool InitLinkListNoHead(LinkList &L)
{
    L = NULL;
    return true;
}

bool EmptyLinkList(LinkList L)
{
    return L->next == NULL;
}

bool InsertNodeLinkList(LNode *a, LNode *b)
{
    if (a == NULL || b == NULL) return false;
    b->next = a->next;
    a->next = b;
    return true;
}

bool DeleteNodeLinkList(LNode *a)
{
    if (a->next == NULL) return false;
    LNode *p = a->next;
    a->next = p->next;
    free(p);
    return true;
}

bool HeadInsertLinkList(LinkList &L)
{
    InitLinkList(L);
    ElemType data;
    LNode *node;
    scanf("%d", &data);
    while (data != 9999)
    {
        node = (LNode *) malloc(sizeof(LNode));
        if (node == NULL) return false;
        node->data = data;
        InsertNodeLinkList(L, node);
        scanf("%d", &data);
    }
    return true;
}

bool TailInsertLinkList(LinkList &L)
{
    InitLinkList(L);
    ElemType data;
    LNode *tail = L;
    LNode *node;
    scanf("%d", &data);
    while (data != 9999)
    {
        node = (LNode *) malloc(sizeof(LNode));
        if (node == NULL) return false;
        node->data = data;
        InsertNodeLinkList(tail, node);
        tail = node;
        scanf("%d", &data);
    }
    tail->next = NULL;
    return true;
}

LNode *GetElem(LinkList L, int pos)
{
    if (pos < 1) return NULL;
    LNode *p = L;
    int i = 0;
    while (p->next != NULL && i < pos)
    {
        p = p->next;
        i++;
    }
    return p;
}

LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

bool InsertNodePosLinkList(LinkList &L, int pos, ElemType e)
{
    LNode *posNode = GetElem(L, pos - 1);
    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    if (posNode == NULL || newNode == NULL) return false;
    InsertNodeLinkList(posNode, newNode);
    return true;
}

int LengthLinkList(LinkList L)
{
    int length = 0;
    LNode *p = L->next;
    while (p != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}

void PrintLinkList(LinkList L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void PrintLinkListNoHead(LinkList L)
{
    LNode *p = L;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
