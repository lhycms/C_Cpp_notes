#include <iostream>
#include <cmath>
#include <algorithm>
#include <initializer_list>



class Coordination {
private:
    double x, y, z;

public:
    // Constructor
    Coordination(double x_value, double y_value, double z_value) {
        std::cout << "Constructor is running...\n";
        x = x_value;
        y = y_value;
        z = z_value;
    }

    // Initializer list constructor
    Coordination(std::initializer_list<double> lst) {
        std::cout << "Initializer list constructor is running...\n";
        x = *(lst.begin());
        y = *(lst.begin() + 1);
        z = *(lst.begin() + 2);
    }


    // member function -- overload the `function-call operator()` (调用运算符)
    double operator()(int idx_direction) const {
        if (idx_direction == 0)
            return x;
        else if (idx_direction == 1)
            return y;
        else
            return z;
    }


    // friend function -- overloading the `operator<<`
    friend std::ostream& operator<<(std::ostream &COUT, Coordination &c1);

    // friend function -- used in `std::sort()` function
    friend bool compare_coordinations(Coordination &c1, Coordination &c2);
};


// friend function 1
std::ostream& operator<<(std::ostream &COUT, Coordination &c1) {
    double distance = sqrt(pow(c1.x, 2) + pow(c1.y, 2) + pow(c1.z, 2));
    COUT << "[" << c1.x << ", " << c1.y << ", " << c1.z << "]\t";
    COUT << "Distance = " << distance << std::endl;

    return COUT;
}


// friend function 2
bool compare_coordinations(Coordination &c1, Coordination &c2) {
    double distance_1 = pow(c1.x, 2) + pow(c1.y, 2) + pow(c1.z, 2);
    double distance_2 = pow(c2.x, 2) + pow(c2.y, 2) + pow(c2.z, 2);
    
    return distance_1 >= distance_2;
}


int main() {
    Coordination c_lst[] = { {1, 2, 3}, 
                             {9, 5, 4},
                             {4, 5, 6}
                            };
    int size = sizeof(c_lst) / sizeof(c_lst[0]);

    std::sort(c_lst, c_lst + size, compare_coordinations);

    for (auto c_value: c_lst)
        std::cout << c_value;
    
    return 0;
}