/*
 * @Author: your name
 * @Date: 2022-05-01 09:35:09
 * @LastEditTime: 2022-05-01 09:39:15
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /C_C++/make/codes/test/main.cpp
 */
#include <iostream>
#include <stdlib.h>
#include "functions.h"


int main(int argc, char **argv) {
    float value_1 = std::atof(argv[1]);
    float value_2 = std::atof(argv[2]);

    std::cout << "Result: " << multiply(value_1, value_2) << std::endl;

    return 0;
}