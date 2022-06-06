#include <iostream>


class Distance {
private:
    int feet;
    int inches;

public:
    // 构造函数
    // Distance() = default;
    
    Distance() {
        feet = 0;
        inches = 0;
    }

    Distance(int f, int i) {
        feet = f;
        inches = i;
    }

    // Overloading function-call operator
    /*
    Note
    ----
        1. 此处不可以返回 Distance&, 因为 D 是一个局部变量
           局部变量会在结束时销毁，因此引用可能出错。
    */
    Distance operator()(int a, int b, int c) {
        Distance D;
        // 进行随机计算
        D.feet = a + c + 10;
        D.inches = b + c + 100;
        return D;
    }

    // Overloading cout operator
    friend std::ostream& operator<<(std::ostream&, Distance&);
};


// Overloading cout operator
std::ostream& operator<<(std::ostream& COUT, Distance &d) {
    COUT << "feet = " << d.feet << ", inches = "
            << d.inches << std::endl;
    return COUT;
}


int main() {
    Distance D1(11, 10), D2;

    std::cout << "First Distance : \n";
    std::cout << D1;

    D2 = D1(10, 10, 10); // invoke operator()
    std::cout << "Second Distance : \n";
    std::cout << D2;

    return 0;
}