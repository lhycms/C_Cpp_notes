#include <iostream>


class Circle {
public:
    Circle() = default;
    Circle(int r) {
        R = r;
        Length = 4 * 3.14 * R;
        Area = 3.14 * R * R;
    }
    
    // 友元函数的声明
    friend void PrintResult(Circle &circle);

private:
    double R;
    double Length;
    double Area;
};


// 友元函数的定义
void PrintResult(Circle &circle) {
    std::cout << circle.R << std::endl;
    std::cout << circle.Length << std::endl;
    std::cout << circle.Area << std::endl;
}


int main() {
    Circle *ptr_circle = new Circle(2);
    
    // 调用友元函数
    PrintResult();

    delete ptr_circle;
    return 0;
}