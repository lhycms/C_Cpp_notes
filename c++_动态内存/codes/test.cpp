#include <iostream>


class Test {
public:
    Test() { std::cout << "Constructor\n"; }  
    ~Test() { std::cout << "Destructor\n"; }
};


int main() {
    try {
        Test t1;
        throw 10;
    } catch (int i) {
        std::cout << "Caught " << i << std::endl; 
    }
    return 0;
}