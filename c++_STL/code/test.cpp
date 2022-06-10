/*
 * @Author: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @Date: 2022-06-04 17:46:29
 * @LastEditors: Uper 41718895+Hyliu-BUAA@users.noreply.github.com
 * @LastEditTime: 2022-06-10 10:39:14
 * @FilePath: /C_C++/c++_STL/code/test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <algorithm>


class Interval
{
private:
    int x, y;

public:
    // Constructor function
    Interval() = default;
    Interval(int x_value, int y_value) : 
                        x(x_value),
                        y(y_value)  {
        std::cout << "Calling constructor...\n";
    }
    

    // Copy Function
    Interval(const Interval &i) {
        //std::cout << "Calling copy function...\n";
        x = i.x;
        y = i.y;
    }


    // Assignment Operator
    Interval& operator=(const Interval &i) {
        //std::cout << "Calling assignment operator...\n";
        x = i.x;
        y = i.y;

        return *this;
    }
    

    // Friend function : The `cout` overloaded for Interval class
    friend std::ostream& operator<<(std::ostream &COUT, Interval &i);

    // Friend function : Compare function
    friend bool compareInterval(Interval&, Interval&);
};


// Friend function : The `cout` overloaded for Interval class
std::ostream& operator<<(std::ostream &COUT, Interval &i) {
    COUT << "\t" << "[" << i.x <<  ", " << i.y << "]";
    COUT << std::endl;

    return COUT;
}


// show intervals_lst
void show_intervals(Interval intervals_lst[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << intervals_lst[i];
    }
}


// Compare function: 作为 `std::sort(<startaddress>, <endaddress>, <function_name>)` 的第三个函数
// 升序排列
bool compareInterval(Interval &i1, Interval &i2) {
    return ( i1.x < i2.x );
}


int main() {
    Interval intervals_lst[] = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
    int size = sizeof(intervals_lst) / sizeof(intervals_lst[0]);

    // output intervals_lst
    std::cout << "Intervals_lst before sorting:\n";
    show_intervals(intervals_lst, size);

    // sort
    std::sort(intervals_lst, intervals_lst + size, compareInterval);

    // output intervals_lst
    std::cout << "Intervals_lst after sorting:\n";
    show_intervals(intervals_lst, size);

    return 0;
}