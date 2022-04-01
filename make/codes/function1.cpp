/*
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2022-03-30 17:07:42
 * @LastEditors: sch
 * @LastEditTime: 2022-03-30 17:14:34
 */
#include "functions.h"


int factorial(int n) {
    if (n != 1) {
        return n * factorial(n-1);
    }
    else
        return 1;
}