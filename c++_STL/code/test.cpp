#include <iostream>
#include <initializer_list>


class Coordination {
private:
    double x, y, z;

public:
    // Constructor 1
    Coordination() = default;

    // Constructor 2
    Coordination(double x_value, double y_value, double z_value) {
        std::cout << "Calling constructor...\n";
        x = x_value;
        y = y_value;
        z = z_value;
    }

    // Initializer list constructor
    Coordination(std::initializer_list<double> lst) {
        std::cout << "Calling initializer list constructor...\n";
        x = *(lst.begin());     // x = 11
        y = *(lst.begin()+1);   // y = 22
        z = *(lst.begin()+2);   // z = 33
    }
};


int main() {
    Coordination c_1 = {11,22,33};
    Coordination c_2(4,5,6);

    return 0;
}