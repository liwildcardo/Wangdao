//
// Created by wildcardo on 2023/2/26.
//

#ifndef WANGDAO_DATASTRUCTURES_H
#define WANGDAO_DATASTRUCTURES_H

#include <cstdio>
#include <cstdlib>

#define MaxSize 10
#define ElemType int

/**
 * 数据结构：静态顺序表
 */
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;



#endif //WANGDAO_DATASTRUCTURES_H
