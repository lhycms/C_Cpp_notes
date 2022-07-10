#include <iostream>


class Coordination {
private:
    int x, y;

public:
    // Constructor
    Coordination(int x_value, int y_value) {
        std::cout << "Constructor is running...\n";
        x = x_value;
        y = y_value;
    }

    // Copy Constructor
    Coordination(const Coordination& old_coordiantion) {
        std::cout << "Copy Constructor is running...\n";
        x = old_coordiantion.x;
        y = old_coordiantion.y;
    }

    // Intiallizer_list constructor
    Coordination(std::initializer_list<int> lst) {
        std::cout << "Initialzier_list constructor is running...\n";
        x = *(lst.begin());
        y = *(lst.begin() + 1);
    }
};


int main() {
    Coordination c{1, 2};
    return 0;
}