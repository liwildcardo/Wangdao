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
    printf("print list success!\n");
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

void InitSqStack(SqStack &S)
{
    S.top = -1;
}

bool EmptySqStack(SqStack S)
{
    return S.top == -1;
}

bool PushSqStack(SqStack &S, ElemType e)
{
    if (S.top == MaxSize - 1) return false;
    S.data[++S.top] = e;
    return true;
}

bool PopSqStack(SqStack &S, ElemType &e)
{
    if (EmptySqStack(S)) return false;
    e = S.data[S.top--];
    return true;
}

bool GetTopSqStack(SqStack S, ElemType &e)
{
    if (EmptySqStack(S)) return false;
    e = S.data[S.top];
    return true;
}

bool BracketCheck(char *str, int length)
{
    SqStack S;
    InitSqStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            PushSqStack(S, str[i]);
        } else
        {
            int e; // cast char to int
            PopSqStack(S, e);
            if (str[i] == ')' && e != '(') return false;
            if (str[i] == ']' && e != '[') return false;
            if (str[i] == '}' && e != '{') return false;
        }
    }
    return EmptySqStack(S);
}

bool InitLinkStack(LinkStack &S)
{
    S = (LinkStack) malloc(sizeof(StackNode));
    if (S == NULL) return false;
    S->next = NULL;
    return true;
}

bool EmptyLinkStack(LinkStack S)
{
    return S->next == NULL;
}

bool PushLinkStack(LinkStack &S, ElemType e)
{
    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
    if (node == NULL) return false;
    node->data = e;
    node->next = S->next;
    S->next = node;
    return true;
}

bool PopLinkStack(LinkStack &S, ElemType &e)
{
    if (EmptyLinkStack(S)) return false;
    e = S->next->data;
    StackNode *node = S->next;
    S->next = node->next;
    free(node);
    return true;
}

bool GetTopLinkStack(LinkStack S, ElemType &e)
{
    if (EmptyLinkStack(S)) return false;
    e = S->next->data;
    return true;
}

void PrintLinkStack(LinkStack S)
{
    StackNode *p = S->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("print stack success\n");
}

void InitSqQueue(SqQueue &Q)
{
    Q.front = 0;
    Q.rear = 0;
}

bool EmptySqQueue(SqQueue Q)
{
    return Q.rear == Q.front;
}

bool EnSqQueue(SqQueue &Q, ElemType e)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeSqQueue(SqQueue &Q, ElemType &e)
{
    if (EmptySqQueue(Q)) return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool GetHeadSqQueue(SqQueue Q, ElemType &e)
{
    if (EmptySqQueue(Q)) return false;
    e = Q.data[Q.front];
    return true;
}

bool InitLinkQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (QueueNode *) malloc(sizeof(QueueNode));
    if (Q.front == NULL) return false;
    Q.front->next = NULL;
    Q.length = 0;
    return true;
}

bool EmptyLinkQueue(LinkQueue Q)
{
    return Q.front->next == NULL;
    // return Q.front == Q.rear;
    // return Q.length == 0;
}

bool EnLinkQueue(LinkQueue &Q, ElemType e)
{
    QueueNode *node = (QueueNode *) malloc(sizeof(QueueNode));
    if (node == NULL) return false;
    node->data = e;
    node->next = Q.rear->next;
    Q.rear->next = node;
    Q.rear = node;
    Q.length++;
    return true;
}

bool DeLinkQueue(LinkQueue &Q, ElemType &e)
{
    if (EmptyLinkQueue(Q)) return false;
    QueueNode *node = Q.front->next;
    e = node->data;
    Q.front->next = node->next;
    if (node->next == NULL) Q.rear = Q.front;
    free(node);
    Q.length--;
    return true;
}
