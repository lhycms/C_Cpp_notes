/*
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2022-02-25 10:21:34
 * @LastEditors: sch
 * @LastEditTime: 2022-03-13 20:24:28
 */
#include "SqList.h"
#include <iostream>


int main() {
    SqList sqlst;
    // 创建线性表
    InitList(sqlst);

    for (int i=0; i<10; i++) {
        ListInsert(sqlst, i, i);
    }
    
    int e, index;
    LocateElem(sqlst, 5, index);
    std::cout << "index: " << index << std::endl;


    //for (int i=0; i<sqlst.length; i++)
        //std::cout << sqlst.elem[i] << std::endl;

    // 销毁线性表
    DestroyList(sqlst);
    return 0;
}