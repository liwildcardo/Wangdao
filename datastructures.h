//
// Created by wildcardo on 2023/2/26.
//

#ifndef WANGDAO_DATASTRUCTURES_H
#define WANGDAO_DATASTRUCTURES_H

#include <cstdio>
#include <cstdlib>

#define MaxSize 10
#define ElemType int


// Data structure：static sequence list
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

// Init sequence list
void InitSqList(SqList &L);

// Is sequence list empty
bool EmptySqList(SqList L);

// Is sequence list full
bool FullSqList(SqList L);

// Add a new elem on the tail of the list
bool AddElemSqList(SqList &L, ElemType x);

// Insert a new elem on the 'pos' position
bool InsertElemSqList(SqList &L, int pos, ElemType x);

// Delete the 'pos' position elem, return it
bool DeleteElemSqList(SqList &L, int pos, ElemType &x);

// Find the first elem which values 'e'
int LocateElemSqList(SqList L, ElemType e);



// Data structure: Dynamic sequence list
typedef struct
{
    ElemType *data;
    int length, maxSize;
} SeqList;

// Init a dynamic sequence list
bool InitSeqList(SeqList &L, int maxSize);

// Is dynamic sequence list empty
bool EmptySeqList(SeqList L);

// Is dynamic sequence list full
bool FullSeqList(SeqList L);

// Add 'length' length to the dynamic sequence list
bool AddLengthSeqList(SeqList &L, int length);

// Add a new elem to the end of the list
bool AddElemSeqList(SeqList &L, ElemType x);

// Insert a new elem at the 'pos' position
bool InsertElemSeqList(SeqList &L, int pos, ElemType x);

// Delete the 'pos' position elem of the list, return its value
bool DeleteElemSeqList(SeqList &L, int pos, ElemType &x);

// Find the first elem values 'e', return its position
int LocateElemSeqList(SeqList &L, ElemType e);



// Data structure: single link list
typedef struct LNode
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;

// Init a single link list with head node
bool InitLinkList(LinkList &L);

// Init a single link list without head node
bool InitLinkListNoHead(LinkList &L);

// Is single link list empty
bool EmptyLinkList(LinkList L);

// Insert a 'b' node behind 'a' node
bool InsertNodeLinkList(LNode *a, LNode *b);

// Delete the node behind 'a' node
bool DeleteNodeLinkList(LNode *a);

// Build a single link list by head insertion method
bool HeadInsertLinkList(LinkList &L);

// Build a single link list by tail insertion method
bool TailInsertLinkList(LinkList &L);

// Get the 'pos' position node of the single link list
LNode *GetElem(LinkList L, int pos);

// Find the first node values 'e' of the single link list
LNode *LocateElem(LinkList L, ElemType e);

// Insert a new node values 'e' at the 'pos' position fo the single link list
bool InsertNodePosLinkList(LinkList &L, int pos, ElemType e);

// Get the single link list's length
int LengthLinkList(LinkList L);

// Print the single link list
void PrintLinkList(LinkList L);

// Print the single link list doesn't have head node
void PrintLinkListNoHead(LinkList L);



// Data structure: Sequential Stack
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;

// Initialize stack
void InitSqStack(SqStack &S);

// Is stack empty
bool EmptySqStack(SqStack S);

// Push
bool PushSqStack(SqStack &S, ElemType e);

// Pop
bool PopSqStack(SqStack &S, ElemType &e);

// Get the top element
bool GetTopSqStack(SqStack S, ElemType &e);



// Data structure: Link Stack
typedef struct StackNode
{
    ElemType data;
    StackNode *next;
} StackNode, *LinkStack;

// Initialize link stack
bool InitLinkStack(LinkStack &S);

// Is link stack empty
bool EmptyLinkStack(LinkStack S);

// Push
bool PushLinkStack(LinkStack &S, ElemType e);

// Pop
bool PopLinkStack(LinkStack &S, ElemType &e);

// Get the top element
bool GetTopLinkStack(LinkStack S, ElemType &e);

#endif //WANGDAO_DATASTRUCTURES_H
