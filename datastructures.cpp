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
