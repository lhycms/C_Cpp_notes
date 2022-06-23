/*
 * @Author: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @Date: 2022-06-04 17:46:29
 * @LastEditors: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @LastEditTime: 2022-06-23 17:00:25
 * @FilePath: /C_C++/c++_STL/code/test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// Cpp program to illustrate `std::find_if()` and `std::find_if_not()`
#include <bits/stdc++.h>


// Returns true if argument is odd
bool IsOdd(int i) {
    return i % 2;
}


// Driver code
int main() {
    std::vector<int> vec{ 10, 25, 40, 55 };

    // Iterator to store the position of element found
    std::vector<int>::iterator it;

    // std::find_if()
    it = find_if(vec.begin(), vec.end(), IsOdd);
    std::cout << "The first odd value: " << *it << std::endl;

    // Iterator to store the position of element found
    std::vector<int>::iterator ite;

    // std:find_if_not()
    ite = std::find_if_not(vec.begin(), vec.end(), IsOdd);
    std::cout << "The first non-odd value is: " << *it << std::endl;

    return 0;
}