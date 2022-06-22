#include <iostream>



class Coordination {
private:
    int x, y, z;

public:
    Coordination() = default;
    
    Coordination(int x_value, int y_value, int z_value) :
                    x(x_value), 
                    y(y_value),
                    z(z_value) 
    {
        std::cout << "Calling constructor...\n";
    }

    Coordination(Coordination &c) : 
                    x(c.x),
                    y(c.y),
                    z(c.z)
    {
        std::cout << "Calling copy constructor...\n" ;
    }
};


int main() {
    std::cout << "c_1:\t";
    Coordination c_1(1, 2, 3);  // 直接初始化

    std::cout << "c_2:\t";
    Coordination c_2(c_1);  // 拷贝初始化

    std::cout << "c_3:\t";
    Coordination c_3 = c_1; // 拷贝初始化

    std::cout << "c_4:\t";
    Coordination c_4 = {1, 2, 3};   // 直接初始化

    std::cout << "c_5:\t";  
    Coordination c_5 = Coordination(4, 5, 6);   // 直接初始化

    return 0;
}