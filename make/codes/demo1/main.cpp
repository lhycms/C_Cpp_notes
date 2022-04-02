/*
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2022-04-02 10:23:01
 * @LastEditors: sch
 * @LastEditTime: 2022-04-02 10:37:50
 */
#include <iostream>
#include <stdlib.h>
#include "function.h"


int main(int argc, char **argv) {
    float value1 = std::atof(argv[1]);
    float value2 = std::atof(argv[2]);
    std::cout << add(value1, value2) << std::endl;
    std::cout << substract(value1, value2) << std::endl;
    return 0;
}