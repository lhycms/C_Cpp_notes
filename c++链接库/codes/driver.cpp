/*
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2022-03-30 16:06:57
 * @LastEditors: sch
 * @LastEditTime: 2022-03-30 16:15:55
 */
#include <iostream>
#include <stdlib.h>
#include "function.h"

int main(int argc, char **argv) {
    float value1 = std::atof(argv[1]);
    float value2 = std::atof(argv[2]);
    float result = multiply(value1, value2);
    std::cout << result << std::endl;
    return 0;
}