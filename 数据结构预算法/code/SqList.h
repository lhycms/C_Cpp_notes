/*
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2022-03-13 14:20:57
 * @LastEditors: sch
 * @LastEditTime: 2022-03-13 20:26:28
 */
#ifndef PREDEFINE_H
#define PREDEFINE_H

#include <iostream>

// 函数结果的状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100

// Status 是函数的类型，其值是函数结果的状态代码
typedef int Status;
typedef char ElemType;

#endif


typedef struct {
    int *elem;
    int length;
}SqList;


// 1) 创建一个空表
int InitList(SqList &L) {
    L.elem = new int[MAXSIZE];
    if ( !L.elem )
        return OVERFLOW;
    L.length = 0;
    return OK;
}


// 2) 销毁线性表
void DestroyList(SqList &L) {
    if ( L.elem )
        delete L.elem;
}


// 3) 清空线性表
void ClearList(SqList &L) {
    L.length = 0;
}


// 4) 判断线性表是否为空
bool ListEmpty(SqList &L) {
    if (L.length == 0)
        return true;
    return false;
}


// 5) 计算线性表的长度
int ListLength(SqList &L) {
    return L.length;
}


// 6) 取出第 i 个元素
int GetElem(SqList &L, int i, int &e) {
    if ( (i>0) && (i<L.length) ) {
        e = L.elem[i];
        return OK;
    }
    return ERROR;
}


// 7) 
int LocateElem(SqList &L, int e, int &index) {
    for (int i=0; i<L.length; i++) {
        if ( L.elem[i] == e ) {
            index = i;
            return OK;
        }
    }
    return ERROR;
}


// 8) 在 i 处插入元素 e
int ListInsert(SqList &L, int i, int e) {
    if (i<0 && i>L.length)
        return ERROR;
    if (L.length==MAXSIZE)
        return ERROR;
    for (int j=L.length-1; j>=i; j--) {
        L.elem[j+1] = L.elem[j];
    }
    L.elem[i] = e;
    L.length += 1;
    return OK;
}


// 9) 删除下表为 index 的元素
int ListDelete(SqList &L, int i, int &e) {
    if (i<0 && i>=L.length)
        return ERROR;
    if (L.length == 0)
        return ERROR;
    e = L.elem[i];
    for (int j=i; j<L.length-1; j++) {
        L.elem[j] = L.elem[j+1];
    }
    L.length -= 1;
    return OK;
}