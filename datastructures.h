//
// Created by wildcardo on 2023/2/26.
//

#ifndef WANGDAO_DATASTRUCTURES_H
#define WANGDAO_DATASTRUCTURES_H

#include <cstdio>
#include <cstdlib>

#define MaxSize 10
#define ElemType int


// 数据结构：静态顺序表
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

// 初始化静态顺序表
void InitSqList(SqList &L);

// 判断静态顺序表是否为空
bool EmptySqList(SqList L);

// 判断静态顺序表是否为满
bool FullSqList(SqList L);

// 在静态顺序表的表尾添加新元素
bool AddElemSqList(SqList &L, ElemType x);

// 在静态顺序表的pos位序插入新元素
bool InsertElemSqList(SqList &L, int pos, ElemType x);

// 删除静态顺序表的位序为pos的元素，返回被删除的元素x
bool DeleteElemSqList(SqList &L, int pos, ElemType &x);

// 查找静态顺序表第一个元素值为e的元素，并返回其位序
int LocateElemSqList(SqList L, ElemType e);

// 数据结构：动态顺序表。表的最大长度可以动态分配
typedef struct
{
    ElemType *data;
    int length, maxSize;
} SeqList;

// 初始化一个动态顺序表
bool InitSeqList(SeqList &L, int maxSize);

// 判断动态顺序表是否为空
bool EmptySeqList(SeqList L);

// 判断动态顺序表是否为满
bool FullSeqList(SeqList L);

// 动态顺序表的上限增加length长度
bool AddLengthSeqList(SeqList &L, int length);

// 在动态顺序表的表尾添加新元素
bool AddElemSeqList(SeqList &L, ElemType x);

// 在动态顺序表的pos位序插入新元素
bool InsertElemSeqList(SeqList &L, int pos, ElemType x);

// 删除动态顺序表的位序为pos的元素，返回被删除的元素x
bool DeleteElemSeqList(SeqList &L, int pos, ElemType &x);

// 查找动态顺序表第一个元素值为e的元素，并返回其位序
int LocateElemSeqList(SeqList &L, ElemType e);

// 数据结构：单链表
typedef struct LNode
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;

// 初始化一个带头结点的单链表
bool InitLinkList(LinkList &L);

// 初始化一个不带头结点的单链表
bool InitLinkListNoHead(LinkList &L);

// 判断单链表是否为空
bool EmptyLinkList(LinkList L);

// 在a结点后插入b结点
bool InsertNodeLinkList(LNode *a, LNode *b);

// 删除a结点后的结点
bool DeleteNodeLinkList(LNode *a);

// 使用头插法建立单链表
bool HeadInsertLinkList(LinkList &L);

// 使用尾插法建立单链表
bool TailInsertLinkList(LinkList &L);

// 单链表按序号查找位序为pos的结点
LNode *GetElem(LinkList L, int pos);

// 单链表按值查找第一个值为e的结点
LNode *LocateElem(LinkList L, ElemType e);

// 在单链表的pos位序插入值为e的结点
bool InsertNodePosLinkList(LinkList &L, int pos, ElemType e);

// 求单链表表长
int LengthLinkList(LinkList L);

// 打印单链表
void PrintLinkList(LinkList L);

// 打印不带头结点的单链表
void PrintLinkListNoHead(LinkList L);

#endif //WANGDAO_DATASTRUCTURES_H
