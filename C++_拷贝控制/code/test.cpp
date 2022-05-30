#include <iostream>


class B {
public:
    // default constructor
    B(const char *str = NULL) {
        std::cout << "Constructor called.\n";
    }

    B(const B &b) {
        std::cout << "Copy constructor called.\n";
    }
};


int main() {
    B ob = "copy me";
    return 0;
}