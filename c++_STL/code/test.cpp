/*
 * @Author: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @Date: 2022-06-04 17:46:29
 * @LastEditors: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @LastEditTime: 2022-06-04 18:15:13
 * @FilePath: /C_C++/c++_STL/code/test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <iostream>


int main() {
    #ifndef __sgi
    std::cout << "__sgi" << std::endl;
    #endif
    
    #ifdef __GNUC__
    std::cout << "__GNUC__" << std::endl;
    #endif

    return 0;
}